
// Generated from UzhLang.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "UzhLangParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by UzhLangParser.
 */
class  UzhLangListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(UzhLangParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(UzhLangParser::ProgramContext *ctx) = 0;

  virtual void enterCode(UzhLangParser::CodeContext *ctx) = 0;
  virtual void exitCode(UzhLangParser::CodeContext *ctx) = 0;

  virtual void enterLine(UzhLangParser::LineContext *ctx) = 0;
  virtual void exitLine(UzhLangParser::LineContext *ctx) = 0;

  virtual void enterFunctionLine(UzhLangParser::FunctionLineContext *ctx) = 0;
  virtual void exitFunctionLine(UzhLangParser::FunctionLineContext *ctx) = 0;

  virtual void enterWhileLine(UzhLangParser::WhileLineContext *ctx) = 0;
  virtual void exitWhileLine(UzhLangParser::WhileLineContext *ctx) = 0;

  virtual void enterIfLine(UzhLangParser::IfLineContext *ctx) = 0;
  virtual void exitIfLine(UzhLangParser::IfLineContext *ctx) = 0;

  virtual void enterElseLine(UzhLangParser::ElseLineContext *ctx) = 0;
  virtual void exitElseLine(UzhLangParser::ElseLineContext *ctx) = 0;

  virtual void enterAssignLine(UzhLangParser::AssignLineContext *ctx) = 0;
  virtual void exitAssignLine(UzhLangParser::AssignLineContext *ctx) = 0;

  virtual void enterReturnLine(UzhLangParser::ReturnLineContext *ctx) = 0;
  virtual void exitReturnLine(UzhLangParser::ReturnLineContext *ctx) = 0;

  virtual void enterExprLine(UzhLangParser::ExprLineContext *ctx) = 0;
  virtual void exitExprLine(UzhLangParser::ExprLineContext *ctx) = 0;

  virtual void enterFuncCall(UzhLangParser::FuncCallContext *ctx) = 0;
  virtual void exitFuncCall(UzhLangParser::FuncCallContext *ctx) = 0;

  virtual void enterExpr(UzhLangParser::ExprContext *ctx) = 0;
  virtual void exitExpr(UzhLangParser::ExprContext *ctx) = 0;


};

