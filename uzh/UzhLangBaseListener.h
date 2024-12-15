
// Generated from UzhLang.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "UzhLangListener.h"


/**
 * This class provides an empty implementation of UzhLangListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  UzhLangBaseListener : public UzhLangListener {
public:

  virtual void enterProgram(UzhLangParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(UzhLangParser::ProgramContext * /*ctx*/) override { }

  virtual void enterLine(UzhLangParser::LineContext * /*ctx*/) override { }
  virtual void exitLine(UzhLangParser::LineContext * /*ctx*/) override { }

  virtual void enterEmpty_line(UzhLangParser::Empty_lineContext * /*ctx*/) override { }
  virtual void exitEmpty_line(UzhLangParser::Empty_lineContext * /*ctx*/) override { }

  virtual void enterFunction_line(UzhLangParser::Function_lineContext * /*ctx*/) override { }
  virtual void exitFunction_line(UzhLangParser::Function_lineContext * /*ctx*/) override { }

  virtual void enterWhile_line(UzhLangParser::While_lineContext * /*ctx*/) override { }
  virtual void exitWhile_line(UzhLangParser::While_lineContext * /*ctx*/) override { }

  virtual void enterIf_line(UzhLangParser::If_lineContext * /*ctx*/) override { }
  virtual void exitIf_line(UzhLangParser::If_lineContext * /*ctx*/) override { }

  virtual void enterElse_line(UzhLangParser::Else_lineContext * /*ctx*/) override { }
  virtual void exitElse_line(UzhLangParser::Else_lineContext * /*ctx*/) override { }

  virtual void enterAssign_line(UzhLangParser::Assign_lineContext * /*ctx*/) override { }
  virtual void exitAssign_line(UzhLangParser::Assign_lineContext * /*ctx*/) override { }

  virtual void enterReturn_line(UzhLangParser::Return_lineContext * /*ctx*/) override { }
  virtual void exitReturn_line(UzhLangParser::Return_lineContext * /*ctx*/) override { }

  virtual void enterExpr(UzhLangParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(UzhLangParser::ExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

