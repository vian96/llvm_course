
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

  virtual void enterCode(UzhLangParser::CodeContext * /*ctx*/) override { }
  virtual void exitCode(UzhLangParser::CodeContext * /*ctx*/) override { }

  virtual void enterLine(UzhLangParser::LineContext * /*ctx*/) override { }
  virtual void exitLine(UzhLangParser::LineContext * /*ctx*/) override { }

  virtual void enterFunctionLine(UzhLangParser::FunctionLineContext * /*ctx*/) override { }
  virtual void exitFunctionLine(UzhLangParser::FunctionLineContext * /*ctx*/) override { }

  virtual void enterWhileLine(UzhLangParser::WhileLineContext * /*ctx*/) override { }
  virtual void exitWhileLine(UzhLangParser::WhileLineContext * /*ctx*/) override { }

  virtual void enterIfLine(UzhLangParser::IfLineContext * /*ctx*/) override { }
  virtual void exitIfLine(UzhLangParser::IfLineContext * /*ctx*/) override { }

  virtual void enterElseLine(UzhLangParser::ElseLineContext * /*ctx*/) override { }
  virtual void exitElseLine(UzhLangParser::ElseLineContext * /*ctx*/) override { }

  virtual void enterAssignLine(UzhLangParser::AssignLineContext * /*ctx*/) override { }
  virtual void exitAssignLine(UzhLangParser::AssignLineContext * /*ctx*/) override { }

  virtual void enterReturnLine(UzhLangParser::ReturnLineContext * /*ctx*/) override { }
  virtual void exitReturnLine(UzhLangParser::ReturnLineContext * /*ctx*/) override { }

  virtual void enterExprLine(UzhLangParser::ExprLineContext * /*ctx*/) override { }
  virtual void exitExprLine(UzhLangParser::ExprLineContext * /*ctx*/) override { }

  virtual void enterFuncCall(UzhLangParser::FuncCallContext * /*ctx*/) override { }
  virtual void exitFuncCall(UzhLangParser::FuncCallContext * /*ctx*/) override { }

  virtual void enterExpr(UzhLangParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(UzhLangParser::ExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

