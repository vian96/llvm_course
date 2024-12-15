
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

  virtual antlrcpp::Any visitEmpty_line(UzhLangParser::Empty_lineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_line(UzhLangParser::Function_lineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile_line(UzhLangParser::While_lineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_line(UzhLangParser::If_lineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElse_line(UzhLangParser::Else_lineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign_line(UzhLangParser::Assign_lineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturn_line(UzhLangParser::Return_lineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(UzhLangParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

