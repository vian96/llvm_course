#include "../graph/sim.h"
#include "UzhLangLexer.h"
#include "UzhLangParser.h"
#include "UzhLangVisitor.h"
#include "antlr4-runtime.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include <any>
#include <iostream>
using namespace llvm;

struct TreeLLVMWalker : public UzhLangVisitor {
  std::vector<std::map<std::string, Value *>> vars;
  Function *currFunc;
  LLVMContext *ctxLLVM;
  Module *module;
  IRBuilder<> *builder;
  Type *int32Type;
  TreeLLVMWalker(LLVMContext *ctxLLVM, IRBuilder<> *builder, Module *module)
      : ctxLLVM(ctxLLVM), builder(builder), module(module) {
    int32Type = Type::getInt32Ty(*ctxLLVM);
  }

  antlrcpp::Any visitProgram(UzhLangParser::ProgramContext *ctx) override {
    outs() << "visitProgram\n";
    // declare i32 @PUT_PIXEL(i32, i32, i32)
    ArrayRef<Type *> simPutPixelParamTypes = {int32Type, int32Type, int32Type};
    FunctionType *simPutPixelType =
        FunctionType::get(int32Type, simPutPixelParamTypes, false);
    module->getOrInsertFunction("PUT_PIXEL", simPutPixelType);

    // declare i32 @FLUSH()
    FunctionType *simFlushType = FunctionType::get(int32Type, false);
    module->getOrInsertFunction("FLUSH", simFlushType);

    vars.push_back(
        std::map<std::string, Value *>{{"Y_SIZE", builder->getInt32(256)},
                                       {"X_SIZE", builder->getInt32(512)}});
    // program: nodeDecl+;
    for (auto it : ctx->nodeDecl()) {
      visitNodeDecl(it);
    }
    return nullptr;
  }

  antlrcpp::Any visitNodeDecl(UzhLangParser::NodeDeclContext *ctx) override {
    outs() << "visitNodeDecl\n";
    // nodeDecl: '(' 'NODE' (varDecl | funcDecl) ')';
    if (ctx->varDecl()) {
      return visitVarDecl(ctx->varDecl());
    }
    if (ctx->funcDecl()) {
      return visitFuncDecl(ctx->funcDecl());
    }
    return nullptr;
  }

  antlrcpp::Any visitFuncDecl(UzhLangParser::FuncDeclContext *ctx) override {
    // funcDecl: ID '(' ID* ')' node+;
    std::string name = ctx->ID()[0]->getText();
    outs() << "visitFuncDecl: " << name << "\n";
    vars.push_back({});

    // (i32 %0, i32 %1, i32 %2)
    std::vector<Type *> funcParamTypes;
    for (int arg = 1; arg < ctx->ID().size(); arg++) {
      funcParamTypes.push_back(int32Type);
    }
    // define i32 @color(i32 %0, i32 %1, i32 %2)
    FunctionType *funcType =
        FunctionType::get(int32Type, funcParamTypes, false);
    Function *func = Function::Create(funcType, Function::ExternalLinkage,
                                      ctx->ID()[0]->getText(), module);
    // entry:
    BasicBlock *entryBB = BasicBlock::Create(*ctxLLVM, "entry", func);
    builder->SetInsertPoint(entryBB);
    currFunc = func;

    // (x y step) -> (i32 %0, i32 %1, i32 %2)
    for (int arg = 1; arg < ctx->ID().size(); arg++) {
      registerVar(ctx->ID()[arg]->getText(), func->getArg(arg - 1));
    }

    // Add instructions
    Value *res = nullptr;
    for (auto it : ctx->node()) {
      res = visitNode(it).as<Value *>();
    }
    vars.pop_back();
    builder->CreateRet(res);
    return nullptr;
  }

  antlrcpp::Any visitNode(UzhLangParser::NodeContext *ctx) override {
    outs() << "visitNode\n";
    // node: nodeDecl | ... ;
    if (ctx->nodeDecl()) {
      return visitNodeDecl(ctx->nodeDecl());
    }
    if (ctx->expr()) {
      // node: ... | expr ;
      return visitExpr(ctx->expr());
    }
    // node: ... | '{' ID node* '}';
    if (ctx->ID()) {
      std::string name = ctx->ID()->getText();
      if (name == "LOOP") {
        // node: ... | '{' LOOP it begin end node* '}';
        return visitLoop(ctx);
      }
      // node: ... | '{' FuncID node* '}'
      return visitFuncCall(name, ctx);
    }
    return nullptr;
  }

  antlrcpp::Any visitLoop(UzhLangParser::NodeContext *ctx) {
    outs() << "visitLoop\n";
    // node: ... | '{' LOOP it begin end node* '}';
    vars.push_back({});
    if (ctx->node().size() < 3) {
      outs() << "[Error] Too few arguments for LOOP\n";
      return nullptr;
    }
    Value *beg = visitNode(ctx->node()[1]).as<Value *>();
    Value *end = visitNode(ctx->node()[2]).as<Value *>();

    // br label cmpBB
    BasicBlock *prevBB = builder->GetInsertBlock();
    // it = phi i32 [ 0, prevBB ], [ inc, iterationBB ]
    // cond = icmp eq i32 %1, end
    // br i1 cond, exitBB, iterationBB
    BasicBlock *cmpBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    // inc = add i32 it, 1
    // br label cmpBB
    BasicBlock *iterationBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    // function continuation
    BasicBlock *exitBB = BasicBlock::Create(*ctxLLVM, "", currFunc);

    // br label cmpBB
    builder->CreateBr(cmpBB);
    builder->SetInsertPoint(cmpBB);
    // it = phi i32 [ 0, prevBB ], [ inc, iterationBB ]
    PHINode *it = builder->CreatePHI(builder->getInt32Ty(), 2);
    it->addIncoming(beg, prevBB);
    registerVar(ctx->node()[0]->getText(), it);
    // cond = icmp eq i32 %1, end
    auto cond = builder->CreateICmpEQ(it, end);
    // br i1 cond, exitBB, iterationBB
    builder->CreateCondBr(cond, exitBB, iterationBB);
    builder->SetInsertPoint(iterationBB);

    // Iteration code generation
    for (int i = 3; i < ctx->node().size(); i++) {
      visitNode(ctx->node()[i]);
    }

    // inc = add i32 it, 1
    Value *inc = builder->CreateAdd(it, builder->getInt32(1));
    // br label cmpBB
    builder->CreateBr(cmpBB);
    // it = phi i32 [ 0, prevBB ], [ inc, iterationBB ]
    it->addIncoming(inc, builder->GetInsertBlock());
    builder->SetInsertPoint(exitBB);

    vars.pop_back();
    return (Value *)it;
  }

  antlrcpp::Any visitFuncCall(std::string &name,
                              UzhLangParser::NodeContext *ctx) {
    // node: ... | '{' FuncID node* '}'
    outs() << "visitFuncCall: " << name << "\n";
    // i32 @color(i32 %0, i32 %1, i32 %2)
    Function *func = module->getFunction(name);
    if (!func) {
      outs() << "[Error] Unknown Function name: " << name << "\n";
      return nullptr;
    }
    int argSize = ctx->node().size();
    if (argSize != func->arg_size()) {
      outs() << "[Error] Wrong arguments number for " << name << "\n";
      return nullptr;
    }
    // (i32 %13, i32 %6, i32 %1)
    std::vector<Value *> args;
    for (int i = 0; i < argSize; i++) {
      args.push_back(visitNode(ctx->node()[i]));
    }
    // %16 = call i32 @color(i32 %13, i32 %6, i32 %1)
    return (Value *)builder->CreateCall(func, args);
  }

  antlrcpp::Any visitVarDecl(UzhLangParser::VarDeclContext *ctx) override {
    // varDecl: ID expr;
    std::string name = ctx->ID()->getText();
    outs() << "visitVarDecl: " << name << "\n";
    return registerVar(name, visitExpr(ctx->expr()).as<Value *>());
  }

  antlrcpp::Any visitExpr(UzhLangParser::ExprContext *ctx) override {
    outs() << "visitExpr: ";
    // ID
    if (ctx->ID()) {
      outs() << ctx->ID()->getText() << "\n";
      return searchVar(ctx->ID()->getText());
    }
    // INT
    if (ctx->INT()) {
      outs() << ctx->INT()->getText() << "\n";
      return (Value *)builder->getInt32(std::stoi(ctx->INT()->getText()));
    }
    // '-' expr
    if (ctx->children.size() == 2) {
      outs() << "neg\n";
      return builder->CreateNeg(visit(ctx->children[1]).as<Value *>());
    }
    // '(' expr ')'
    if (ctx->children[0]->getText().at(0) == '(') {
      outs() << "()\n";
      return visit(ctx->children[1]);
    }
    // ( '*' | '/') expr expr
    // ( '+' | '-') expr expr
    outs() << ctx->children[0]->getText() << "\n";
    Value *lhs = visit(ctx->children[1]).as<Value *>();
    Value *rhs = visit(ctx->children[2]).as<Value *>();
    switch (ctx->children[0]->getText().at(0)) {
    case '*':
      return builder->CreateMul(lhs, rhs);
    case '/':
      return builder->CreateSDiv(lhs, rhs);
    case '+':
      return builder->CreateAdd(lhs, rhs);
    case '-':
      return builder->CreateSub(lhs, rhs);
    default:
      break;
    }
    return nullptr;
  }

  Value *registerVar(const std::string &name, Value *val) {
    outs() << "registerVar: " << name << "\n";
    vars.back()[name] = val;
    return val;
  }

  Value *searchVar(const std::string &name) {
    outs() << "searchVar: " << name << "\n";
    for (auto it = vars.rbegin(); it != vars.rend(); ++it) {
      if (auto find = it->find(name); find != it->end()) {
        return find->second;
      }
    }
    // Conflict resolving: node: (expr) <-> (ID)
    Function *func = module->getFunction(name);
    if (!func || func->arg_size() > 0) {
      outs() << "[Error] Can't find variable: " << name << "\n";
      return nullptr;
    }
    outs() << "Change to FuncCall: " << name << "\n";
    return (Value *)builder->CreateCall(func);
  }
};

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    outs() << "[ERROR] Need 1 argument: file with UzhLang\n";
    return 1;
  }
  // Open file
  std::ifstream stream;
  stream.open(argv[1]);

  // Provide the input text in a stream
  antlr4::ANTLRInputStream input(stream);

  // Create a lexer from the input
  UzhLangLexer lexer(&input);

  // Create a token stream from the lexer
  antlr4::CommonTokenStream tokens(&lexer);

  // Create a parser from the token stream
  UzhLangParser parser(&tokens);

  // Display the parse tree
   outs() << parser.program()->toStringTree() << "\n";

  TreeDumpWalker walker;
  walker.visitExpr(parser.expr());
//  int res = walker.visitExpr(parser.expr()).as<int>();
//  outs() << "Visitor output: " << res << "\n";
  return 0;


   return 0;
}
