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
#include <cstdlib>
#include <iostream>
#include <llvm-16/llvm/IR/Instructions.h>
#include <llvm-16/llvm/IR/Type.h>
#include <llvm-16/llvm/IR/Value.h>
#include <string>
using namespace llvm;

struct StackEntry {
  int n;
  enum Type {NO, FUNC, IF} t;
  llvm::BasicBlock *to;
};

void print(int n) {
  std::cout << "out: " << n << '\n';
}

struct TreeLLVMWalker : public UzhLangVisitor {
  std::vector<std::map<std::string, AllocaInst *>> vars;
  Function *currFunc;
  LLVMContext *ctxLLVM;
  Module *module;
  IRBuilder<> *builder;
  Type *int32Type;

  std::vector<StackEntry> space_stack;

  Value *get_var_val(const std::string &name) {
    if (vars.back().count(name))
      return builder->CreateLoad(Type::getInt32Ty(*ctxLLVM), vars.back()[name]);
    std::cerr << name << " is unknown varariable!\n";
    exit(1);
  }

  void set_var_val(const std::string &name, Value *val) {
    if (vars.back().count(name)) {
      builder->CreateStore(val, vars.back()[name]);
      return;
    }
    vars.back()[name] = builder->CreateAlloca(Type::getInt32Ty(*ctxLLVM), 0, name);
    builder->CreateStore(val, vars.back()[name]);
  }

  void undo_stack(int n, bool is_else = false) {
    if (n > space_stack.back().n) {
      std::cerr << "indentation made deeper in inproper place! exp: " << space_stack.back().n << "got: " << n << '\n';
      exit(1);
    }
    if ((space_stack.back().n - n) % 4) {
      std::cerr << "depth is not divisivle by 4!\n";
      exit(1);
    }
    while (space_stack.size() and n != space_stack.back().n) {
      llvm::BasicBlock *to = space_stack.back().to;
      space_stack.pop_back();
      if (!to) // TODO it means we exited function? what to do?
        break;
      if (is_else and n == space_stack.back().n) {
        BasicBlock *if_else_exit = BasicBlock::Create(*ctxLLVM, "", currFunc);
        builder->CreateBr(if_else_exit);
        builder->SetInsertPoint(to);
        space_stack.push_back({n+4, StackEntry::NO, if_else_exit});
        break;
      }
      builder->CreateBr(to);
      builder->SetInsertPoint(to);
    }
  }

  TreeLLVMWalker(LLVMContext *ctxLLVM, IRBuilder<> *builder, Module *module)
      : ctxLLVM(ctxLLVM), builder(builder), module(module) {
    int32Type = Type::getInt32Ty(*ctxLLVM);
  }

  antlrcpp::Any visitProgram(UzhLangParser::ProgramContext *ctx) override {
    visitCode(ctx->code());
    return nullptr;
  }

//  antlrcpp::Any visitWhyDoesThisRuleHelp(UzhLangParser::WhyDoesThisRuleHelpContext *ctx) override {
//    visitCode(ctx->code());
//    return nullptr;
//  }

  antlrcpp::Any visitCode(UzhLangParser::CodeContext *ctx) override {
    outs() << "visitProgram\n";
    // declare i32 @PUT_PIXEL(i32, i32, i32)
    ArrayRef<Type *> simPutPixelParamTypes = {int32Type, int32Type, int32Type};
    FunctionType *simPutPixelType =
        FunctionType::get(int32Type, simPutPixelParamTypes, false);
    module->getOrInsertFunction("PUT_PIXEL", simPutPixelType);

    FunctionType *printFuncType =
        FunctionType::get(Type::getVoidTy(*ctxLLVM), {int32Type}, false);
    module->getOrInsertFunction("print", printFuncType);

    // declare i32 @FLUSH()
    FunctionType *simFlushType = FunctionType::get(int32Type, false);
    module->getOrInsertFunction("FLUSH", simFlushType);

    // program: nodeDecl+;
    for (auto it : ctx->line()) {
      visitLine(it);
    }
    return nullptr;
  }

  antlrcpp::Any visitLine(UzhLangParser::LineContext *ctx) override {
    outs() << "Line\n";
    if (ctx->functionLine())
      visitFunctionLine(ctx->functionLine());
    if (ctx->whileLine())
      visitWhileLine(ctx->whileLine());
    if (ctx->ifLine())
      visitIfLine(ctx->ifLine());
    if (ctx->elseLine())
      visitElseLine(ctx->elseLine());
    if (ctx->assignLine())
      visitAssignLine(ctx->assignLine());
    if (ctx->exprLine())
      visitExprLine(ctx->exprLine());
    if (ctx->returnLine())
      visitReturnLine(ctx->returnLine());
    return nullptr;
  }

  antlrcpp::Any visitExprLine(UzhLangParser::ExprLineContext *ctx) override {
    outs() << "exprLine\n";
    undo_stack(ctx->BOL()->getText().size());
    return (Value*)visitExpr(ctx->expr());
  }

  antlrcpp::Any visitFunctionLine(UzhLangParser::FunctionLineContext *ctx) override {
    outs() << "funcDec\n";
    if (ctx->BOL() and ctx->BOL()->getText().size() != 1) {
      std::cerr << "function decl can not be nested!\n";
      exit(1);
    }
    space_stack.push_back({5, StackEntry::FUNC, nullptr});

    std::string name = ctx->ID()[0]->getText();
    outs() << "visitFuncDecl: " << name << "\n";
    vars.push_back({});

    std::vector<Type *> funcParamTypes;
    for (int arg = 1; arg < ctx->ID().size(); arg++)
      funcParamTypes.push_back(int32Type);
    FunctionType *funcType =
        FunctionType::get(int32Type, funcParamTypes, false);
    Function *func = Function::Create(funcType, Function::ExternalLinkage,
                                      ctx->ID()[0]->getText(), module);
    BasicBlock *entryBB = BasicBlock::Create(*ctxLLVM, "entry", func);
    builder->SetInsertPoint(entryBB);
    currFunc = func;

    for (int arg = 1; arg < ctx->ID().size(); arg++)
      set_var_val(ctx->ID()[arg]->getText(), func->getArg(arg - 1));

    return nullptr;
  }

  antlrcpp::Any visitWhileLine(UzhLangParser::WhileLineContext *ctx) override {
    outs() << "whileLine\n";
    undo_stack(ctx->BOL()->getText().size());

    BasicBlock *cmpBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    BasicBlock *iterationBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    BasicBlock *exitBB = BasicBlock::Create(*ctxLLVM, "", currFunc);

    space_stack.push_back({space_stack.back().n+4, StackEntry::NO, cmpBB});

    // br label cmpBB
    builder->CreateBr(cmpBB);
    builder->SetInsertPoint(cmpBB);
    Value *cond = visitExpr(ctx->expr());
    builder->CreateCondBr(
        builder->CreateTrunc(cond, builder->getInt1Ty()),
        iterationBB, exitBB
    );
    builder->SetInsertPoint(iterationBB);

    return nullptr;
  }

  antlrcpp::Any visitIfLine(UzhLangParser::IfLineContext *ctx) override {
    outs() << "fiLine\n";
    undo_stack(ctx->BOL()->getText().size());

    BasicBlock *trueBB = BasicBlock::Create(*ctxLLVM, "", currFunc);
    BasicBlock *falseBB = BasicBlock::Create(*ctxLLVM, "", currFunc);

    space_stack.push_back({space_stack.back().n+4, StackEntry::IF, falseBB});

    // br label cmpBB
    Value *cond = visitExpr(ctx->expr());
    builder->CreateCondBr(
        builder->CreateTrunc(cond, builder->getInt1Ty()),
        trueBB, falseBB
    );
    builder->SetInsertPoint(trueBB);

    return nullptr;
  }

  antlrcpp::Any visitElseLine(UzhLangParser::ElseLineContext *ctx) override {
    outs() << "elseLine\n";
    undo_stack(ctx->BOL()->getText().size(), true);
    return nullptr;
  }

  antlrcpp::Any visitAssignLine(UzhLangParser::AssignLineContext *ctx) override {
    outs() << "assLine\n";
    undo_stack(ctx->BOL()->getText().size());
    std::string name = ctx->ID()->getText();
    outs() << "visitVarDecl: " << name << "\n";
    set_var_val(name, visitExpr(ctx->expr()).as<Value *>());
    return nullptr;
  }

  antlrcpp::Any visitFuncCall(UzhLangParser::FuncCallContext *ctx) override {
    std::string name = ctx->ID()->getText();
    outs() << "visitFuncCall: " << name << "\n";
    Function *func = module->getFunction(name);
    if (!func) {
      outs() << "[Error] Unknown Function name: " << name << "\n";
      exit(1);
    }
    int argSize = ctx->expr().size();
    if (argSize != func->arg_size()) {
      outs() << "[Error] Wrong arguments number for " << name << " need " << func->arg_size() << " got " << argSize << "\n";
      exit(1);
    }
    std::vector<Value *> args;
    for (int i = 0; i < argSize; i++)
      args.push_back(visitExpr(ctx->expr()[i]));
    return (Value *)builder->CreateCall(func, args);
  }

  antlrcpp::Any visitReturnLine(UzhLangParser::ReturnLineContext *ctx) override {
    outs() << "retLine\n";
    undo_stack(ctx->BOL()->getText().size());
    builder->CreateRet((Value*) visitExpr(ctx->expr()));
    return nullptr;
  }

  antlrcpp::Any visitExpr(UzhLangParser::ExprContext *ctx) override {
    outs() << "visitExpr: ";
    if (ctx->funcCall())
      return (Value *)visitFuncCall(ctx->funcCall());
    // ID
    if (ctx->ID()) {
      std::cout << "id\n";
      outs() << ctx->ID()->getText() << "\n";
      return (Value *)get_var_val(ctx->ID()->getText());
    }
    // INT
    if (ctx->INT()) {
      std::cout << "int\n";
      outs() << ctx->INT()->getText() << "\n";
      return (Value *)builder->getInt32(std::stoi(ctx->INT()->getText()));
    }
    // NOT expr
    if (ctx->children.size() == 2) {
      std::cerr << "NOT is not implemented\n";
      exit(1);
    }
    // '(' expr ')'
    if (ctx->children[0]->getText().at(0) == '(') {
      outs() << "()\n";
      return (Value *)visit(ctx->children[1]);
    }
    // BIN OPERATION
    std::cout << "bin\n";
    outs() << ctx->children[0]->getText() << "\n";
    std::cout << "getT\n";
    Value *lhs = visit(ctx->children[0]).as<Value *>();
    Value *rhs = visit(ctx->children[2]).as<Value *>();
    lhs->getType()->print(outs());
    outs() << '\n';
    rhs->getType()->print(outs());
    outs() << '\n';
    std::cout << lhs->getType() << ' ' << rhs->getType() << '\n';
    std::cout << "visitChildr\n";
    if (ctx->AND())
      return (Value *)builder->CreateAnd(lhs, rhs);
    if (ctx->OR())
      return (Value *)builder->CreateOr(lhs, rhs);
    if (ctx->COMP()) {
      std::cout << "comp\n";
      std::string op = ctx->children[1]->getText();
      if (op == "<")
        return (Value *)builder->CreateICmpSLT(lhs, rhs);
      if (op == ">")
        return (Value *)builder->CreateICmpSGT(lhs, rhs);
      if (op == "<=")
        return (Value *)builder->CreateICmpSLE(lhs, rhs);
      if (op == ">=")
        return (Value *)builder->CreateICmpSGE(lhs, rhs);
      if (op == "==")
        return (Value *)builder->CreateICmpEQ(lhs, rhs);
      if (op == "!=")
        return (Value *)builder->CreateICmpNE(lhs, rhs);
      std::cout << op << " is unknown comp op\n";
    }
    std::cout << "nocomp\n";
    switch (ctx->children[1]->getText().at(0)) {
      case '*':
        return (Value *)builder->CreateMul(lhs, rhs);
      case '/':
        return (Value *)builder->CreateSDiv(lhs, rhs);
      case '+':
        return (Value *)builder->CreateAdd(lhs, rhs);
      case '-':
        return (Value *)builder->CreateSub(lhs, rhs);
      default:
        break;
    }
    return nullptr;
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

  std::cout << "past input\n";
  // Create a lexer from the input
  UzhLangLexer lexer(&input);

  std::cout << "past lexer\n";

  // Create a token stream from the lexer
  antlr4::CommonTokenStream tokens(&lexer);

  std::cout << "past token\n";
  // Create a parser from the token stream
  UzhLangParser parser(&tokens);

  std::cout << "past parse\n";
//  std::cout << parser.program()->line().size() << '\n';
  // Display the parse tree
//  outs() << parser.program()->toStringTree() << "\n";

  LLVMContext context;
  Module *module = new Module("top", context);
  IRBuilder<> builder(context);

  TreeLLVMWalker walker(&context, &builder, module);
  walker.visitProgram(parser.program());

  outs() << "[LLVM IR]\n";
  module->print(outs(), nullptr);
  outs() << "\n";
  bool verif = verifyModule(*module, &outs());
  outs() << "[VERIFICATION] " << (!verif ? "OK\n\n" : "FAIL\n\n");

  Function *appFunc = module->getFunction("app");
  if (appFunc == nullptr) {
    outs() << "Can't find app function\n";
    return -1;
  }

  // LLVM IR Interpreter
  outs() << "[EE] Run\n";
  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();

  ExecutionEngine *ee =
      EngineBuilder(std::unique_ptr<Module>(module)).create();
  ee->InstallLazyFunctionCreator([=](const std::string &fnName) -> void * {
    if (fnName == "PUT_PIXEL") {
      return reinterpret_cast<void *>(simPutPixel);
    }
    if (fnName == "FLUSH") {
      return reinterpret_cast<void *>(simFlush);
    }
    if (fnName == "print") {
      return reinterpret_cast<void *>(print);
    }
    return nullptr;
  });
  ee->finalizeObject();

  simInit();

  ArrayRef<GenericValue> noargs;
  GenericValue v = ee->runFunction(appFunc, noargs);
  outs() << "[EE] Result: " << v.IntVal << "\n";

  simExit();

  return 0;
}
