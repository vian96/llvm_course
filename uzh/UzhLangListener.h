
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

  virtual void enterLine(UzhLangParser::LineContext *ctx) = 0;
  virtual void exitLine(UzhLangParser::LineContext *ctx) = 0;

  virtual void enterEmpty_line(UzhLangParser::Empty_lineContext *ctx) = 0;
  virtual void exitEmpty_line(UzhLangParser::Empty_lineContext *ctx) = 0;

  virtual void enterFunction_line(UzhLangParser::Function_lineContext *ctx) = 0;
  virtual void exitFunction_line(UzhLangParser::Function_lineContext *ctx) = 0;

  virtual void enterWhile_line(UzhLangParser::While_lineContext *ctx) = 0;
  virtual void exitWhile_line(UzhLangParser::While_lineContext *ctx) = 0;

  virtual void enterIf_line(UzhLangParser::If_lineContext *ctx) = 0;
  virtual void exitIf_line(UzhLangParser::If_lineContext *ctx) = 0;

  virtual void enterElse_line(UzhLangParser::Else_lineContext *ctx) = 0;
  virtual void exitElse_line(UzhLangParser::Else_lineContext *ctx) = 0;

  virtual void enterAssign_line(UzhLangParser::Assign_lineContext *ctx) = 0;
  virtual void exitAssign_line(UzhLangParser::Assign_lineContext *ctx) = 0;

  virtual void enterReturn_line(UzhLangParser::Return_lineContext *ctx) = 0;
  virtual void exitReturn_line(UzhLangParser::Return_lineContext *ctx) = 0;

  virtual void enterExpr(UzhLangParser::ExprContext *ctx) = 0;
  virtual void exitExpr(UzhLangParser::ExprContext *ctx) = 0;


};

