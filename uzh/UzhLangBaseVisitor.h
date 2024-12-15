
// Generated from UzhLang.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "UzhLangVisitor.h"


/**
 * This class provides an empty implementation of UzhLangVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  UzhLangBaseVisitor : public UzhLangVisitor {
public:

  virtual antlrcpp::Any visitProgram(UzhLangParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLine(UzhLangParser::LineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionLine(UzhLangParser::FunctionLineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileLine(UzhLangParser::WhileLineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfLine(UzhLangParser::IfLineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElseLine(UzhLangParser::ElseLineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignLine(UzhLangParser::AssignLineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnLine(UzhLangParser::ReturnLineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprLine(UzhLangParser::ExprLineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncCall(UzhLangParser::FuncCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(UzhLangParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

