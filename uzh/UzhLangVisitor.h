
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

    virtual antlrcpp::Any visitLine(UzhLangParser::LineContext *context) = 0;

    virtual antlrcpp::Any visitEmpty_line(UzhLangParser::Empty_lineContext *context) = 0;

    virtual antlrcpp::Any visitFunction_line(UzhLangParser::Function_lineContext *context) = 0;

    virtual antlrcpp::Any visitWhile_line(UzhLangParser::While_lineContext *context) = 0;

    virtual antlrcpp::Any visitIf_line(UzhLangParser::If_lineContext *context) = 0;

    virtual antlrcpp::Any visitElse_line(UzhLangParser::Else_lineContext *context) = 0;

    virtual antlrcpp::Any visitAssign_line(UzhLangParser::Assign_lineContext *context) = 0;

    virtual antlrcpp::Any visitReturn_line(UzhLangParser::Return_lineContext *context) = 0;

    virtual antlrcpp::Any visitExpr(UzhLangParser::ExprContext *context) = 0;


};

