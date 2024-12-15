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
#include <llvm-16/llvm/IR/Value.h>
#include <string>
using namespace llvm;

struct StackEntry {
  int n;
  enum Type {NO, FUNC, IF} t;
  llvm::BasicBlock *to;
};

struct TreeLLVMWalker : public UzhLangVisitor {
  std::vector<std::map<std::string, Value *>> vars;
  Function *currFunc;
  LLVMContext *ctxLLVM;
  Module *module;
  IRBuilder<> *builder;
  Type *int32Type;

  std::vector<StackEntry> space_stack;

  void undo_stack(int n, bool is_else = false) {
    if (n > space_stack.back().n) {
      std::cerr << "indentation made deeper in inproper place!\n";
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
    undo_stack(ctx->BOL()->getText().size());
    return visitExpr(ctx->expr());
  }

  antlrcpp::Any visitFunctionLine(UzhLangParser::FunctionLineContext *ctx) override {
    if (ctx->BOL() and ctx->BOL()->children.size() != 1) {
      std::cerr << "function decl can not be nested!\n";
      exit(1);
    }
    space_stack.push_back({4, StackEntry::FUNC, nullptr});

    std::string name = ctx->ID()[0]->getText();
    outs() << "visitFuncDecl: " << name << "\n";
    vars.push_back({});

    std::vector<Type *> funcParamTypes;
    for (int arg = 5; arg < ctx->ID().size(); arg++)
      funcParamTypes.push_back(int32Type);
    FunctionType *funcType =
        FunctionType::get(int32Type, funcParamTypes, false);
    Function *func = Function::Create(funcType, Function::ExternalLinkage,
                                      ctx->ID()[0]->getText(), module);
    BasicBlock *entryBB = BasicBlock::Create(*ctxLLVM, "entry", func);
    builder->SetInsertPoint(entryBB);
    currFunc = func;

    for (int arg = 1; arg < ctx->ID().size(); arg++)
      registerVar(ctx->ID()[arg]->getText(), func->getArg(arg - 1));

    return nullptr;
  }

  antlrcpp::Any visitWhileLine(UzhLangParser::WhileLineContext *ctx) override {
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
    undo_stack(ctx->BOL()->getText().size(), true);
    return nullptr;
  }

  antlrcpp::Any visitAssignLine(UzhLangParser::AssignLineContext *ctx) override {
    undo_stack(ctx->BOL()->getText().size());
    std::string name = ctx->ID()->getText();
    outs() << "visitVarDecl: " << name << "\n";
    return registerVar(name, visitExpr(ctx->expr()).as<Value *>());
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
      outs() << "[Error] Wrong arguments number for " << name << "\n";
      exit(1);
    }
    std::vector<Value *> args;
    for (int i = 0; i < argSize; i++)
      args.push_back(visitExpr(ctx->expr()[i]));
    return (Value *)builder->CreateCall(func, args);
  }

  antlrcpp::Any visitReturnLine(UzhLangParser::ReturnLineContext *ctx) override {
    undo_stack(ctx->BOL()->getText().size());
    builder->CreateRet((Value*) visitExpr(ctx->expr()));
    return nullptr;
  }

  antlrcpp::Any visitExpr(UzhLangParser::ExprContext *ctx) override {
    outs() << "visitExpr: ";
    if (ctx->funcCall())
      return visitFuncCall(ctx->funcCall());
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
    // NOT expr
    if (ctx->children.size() == 2) {
      std::cerr << "NOT is not implemented\n";
      exit(1);
    }
    // '(' expr ')'
    if (ctx->children[0]->getText().at(0) == '(') {
      outs() << "()\n";
      return visit(ctx->children[1]);
    }
    // BIN OPERATION
    outs() << ctx->children[0]->getText() << "\n";
    Value *lhs = visit(ctx->children[1]).as<Value *>();
    Value *rhs = visit(ctx->children[2]).as<Value *>();
    if (ctx->AND())
      return builder->CreateAnd(lhs, rhs);
    if (ctx->OR())
      return builder->CreateOr(lhs, rhs);
    if (ctx->COMP()) {
      std::string op = ctx->children[0]->getText();
      if (op == "<")
        return builder->CreateICmpSLT(lhs, rhs);
      if (op == ">")
        return builder->CreateICmpSGT(lhs, rhs);
      if (op == "<=")
        return builder->CreateICmpSLE(lhs, rhs);
      if (op == ">=")
        return builder->CreateICmpSGE(lhs, rhs);
      if (op == "==")
        return builder->CreateICmpEQ(lhs, rhs);
      if (op == "!=")
        return builder->CreateICmpNE(lhs, rhs);
    }
    switch (ctx->children[1]->getText().at(0)) {
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

  TreeLLVMWalker walker;
  walker.visitExpr(parser.expr());
//  int res = walker.visitExpr(parser.expr()).as<int>();
//  outs() << "Visitor output: " << res << "\n";
  return 0;


   return 0;
}
