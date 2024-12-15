
// Generated from UzhLang.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "UzhLangParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by UzhLangParser.
 */
class  UzhLangVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by UzhLangParser.
   */
    virtual antlrcpp::Any visitProgram(UzhLangParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitCode(UzhLangParser::CodeContext *context) = 0;

    virtual antlrcpp::Any visitLine(UzhLangParser::LineContext *context) = 0;

    virtual antlrcpp::Any visitFunctionLine(UzhLangParser::FunctionLineContext *context) = 0;

    virtual antlrcpp::Any visitWhileLine(UzhLangParser::WhileLineContext *context) = 0;

    virtual antlrcpp::Any visitIfLine(UzhLangParser::IfLineContext *context) = 0;

    virtual antlrcpp::Any visitElseLine(UzhLangParser::ElseLineContext *context) = 0;

    virtual antlrcpp::Any visitAssignLine(UzhLangParser::AssignLineContext *context) = 0;

    virtual antlrcpp::Any visitReturnLine(UzhLangParser::ReturnLineContext *context) = 0;

    virtual antlrcpp::Any visitExprLine(UzhLangParser::ExprLineContext *context) = 0;

    virtual antlrcpp::Any visitFuncCall(UzhLangParser::FuncCallContext *context) = 0;

    virtual antlrcpp::Any visitExpr(UzhLangParser::ExprContext *context) = 0;


};

