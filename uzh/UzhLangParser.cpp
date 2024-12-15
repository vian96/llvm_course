
// Generated from UzhLang.g4 by ANTLR 4.7.2


#include "UzhLangListener.h"
#include "UzhLangVisitor.h"

#include "UzhLangParser.h"


using namespace antlrcpp;
using namespace antlr4;

UzhLangParser::UzhLangParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

UzhLangParser::~UzhLangParser() {
  delete _interpreter;
}

std::string UzhLangParser::getGrammarFileName() const {
  return "UzhLang.g4";
}

const std::vector<std::string>& UzhLangParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& UzhLangParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

UzhLangParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<UzhLangParser::LineContext *> UzhLangParser::ProgramContext::line() {
  return getRuleContexts<UzhLangParser::LineContext>();
}

UzhLangParser::LineContext* UzhLangParser::ProgramContext::line(size_t i) {
  return getRuleContext<UzhLangParser::LineContext>(i);
}

std::vector<tree::TerminalNode *> UzhLangParser::ProgramContext::BOL() {
  return getTokens(UzhLangParser::BOL);
}

tree::TerminalNode* UzhLangParser::ProgramContext::BOL(size_t i) {
  return getToken(UzhLangParser::BOL, i);
}


size_t UzhLangParser::ProgramContext::getRuleIndex() const {
  return UzhLangParser::RuleProgram;
}

void UzhLangParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void UzhLangParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any UzhLangParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::ProgramContext* UzhLangParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, UzhLangParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(24); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(24);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(22);
        line();
        break;
      }

      case 2: {
        setState(23);
        match(UzhLangParser::BOL);
        break;
      }

      }
      setState(26); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == UzhLangParser::BOL

    || _la == UzhLangParser::DEF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

UzhLangParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

UzhLangParser::FunctionLineContext* UzhLangParser::LineContext::functionLine() {
  return getRuleContext<UzhLangParser::FunctionLineContext>(0);
}

UzhLangParser::WhileLineContext* UzhLangParser::LineContext::whileLine() {
  return getRuleContext<UzhLangParser::WhileLineContext>(0);
}

UzhLangParser::IfLineContext* UzhLangParser::LineContext::ifLine() {
  return getRuleContext<UzhLangParser::IfLineContext>(0);
}

UzhLangParser::ElseLineContext* UzhLangParser::LineContext::elseLine() {
  return getRuleContext<UzhLangParser::ElseLineContext>(0);
}

UzhLangParser::AssignLineContext* UzhLangParser::LineContext::assignLine() {
  return getRuleContext<UzhLangParser::AssignLineContext>(0);
}

UzhLangParser::ExprLineContext* UzhLangParser::LineContext::exprLine() {
  return getRuleContext<UzhLangParser::ExprLineContext>(0);
}

UzhLangParser::ReturnLineContext* UzhLangParser::LineContext::returnLine() {
  return getRuleContext<UzhLangParser::ReturnLineContext>(0);
}


size_t UzhLangParser::LineContext::getRuleIndex() const {
  return UzhLangParser::RuleLine;
}

void UzhLangParser::LineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine(this);
}

void UzhLangParser::LineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine(this);
}


antlrcpp::Any UzhLangParser::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::LineContext* UzhLangParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 2, UzhLangParser::RuleLine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(28);
      functionLine();
      break;
    }

    case 2: {
      setState(29);
      whileLine();
      break;
    }

    case 3: {
      setState(30);
      ifLine();
      break;
    }

    case 4: {
      setState(31);
      elseLine();
      break;
    }

    case 5: {
      setState(32);
      assignLine();
      break;
    }

    case 6: {
      setState(33);
      exprLine();
      break;
    }

    case 7: {
      setState(34);
      returnLine();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionLineContext ------------------------------------------------------------------

UzhLangParser::FunctionLineContext::FunctionLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::FunctionLineContext::DEF() {
  return getToken(UzhLangParser::DEF, 0);
}

std::vector<tree::TerminalNode *> UzhLangParser::FunctionLineContext::ID() {
  return getTokens(UzhLangParser::ID);
}

tree::TerminalNode* UzhLangParser::FunctionLineContext::ID(size_t i) {
  return getToken(UzhLangParser::ID, i);
}

tree::TerminalNode* UzhLangParser::FunctionLineContext::BOL() {
  return getToken(UzhLangParser::BOL, 0);
}


size_t UzhLangParser::FunctionLineContext::getRuleIndex() const {
  return UzhLangParser::RuleFunctionLine;
}

void UzhLangParser::FunctionLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionLine(this);
}

void UzhLangParser::FunctionLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionLine(this);
}


antlrcpp::Any UzhLangParser::FunctionLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitFunctionLine(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::FunctionLineContext* UzhLangParser::functionLine() {
  FunctionLineContext *_localctx = _tracker.createInstance<FunctionLineContext>(_ctx, getState());
  enterRule(_localctx, 4, UzhLangParser::RuleFunctionLine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == UzhLangParser::BOL) {
      setState(37);
      match(UzhLangParser::BOL);
    }
    setState(40);
    match(UzhLangParser::DEF);
    setState(41);
    match(UzhLangParser::ID);
    setState(42);
    match(UzhLangParser::T__0);
    setState(51);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == UzhLangParser::ID) {
      setState(43);
      match(UzhLangParser::ID);
      setState(48);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == UzhLangParser::T__1) {
        setState(44);
        match(UzhLangParser::T__1);
        setState(45);
        match(UzhLangParser::ID);
        setState(50);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(53);
    match(UzhLangParser::T__2);
    setState(54);
    match(UzhLangParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileLineContext ------------------------------------------------------------------

UzhLangParser::WhileLineContext::WhileLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::WhileLineContext::BOL() {
  return getToken(UzhLangParser::BOL, 0);
}

tree::TerminalNode* UzhLangParser::WhileLineContext::WHILE() {
  return getToken(UzhLangParser::WHILE, 0);
}

UzhLangParser::ExprContext* UzhLangParser::WhileLineContext::expr() {
  return getRuleContext<UzhLangParser::ExprContext>(0);
}


size_t UzhLangParser::WhileLineContext::getRuleIndex() const {
  return UzhLangParser::RuleWhileLine;
}

void UzhLangParser::WhileLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileLine(this);
}

void UzhLangParser::WhileLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileLine(this);
}


antlrcpp::Any UzhLangParser::WhileLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitWhileLine(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::WhileLineContext* UzhLangParser::whileLine() {
  WhileLineContext *_localctx = _tracker.createInstance<WhileLineContext>(_ctx, getState());
  enterRule(_localctx, 6, UzhLangParser::RuleWhileLine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(UzhLangParser::BOL);
    setState(57);
    match(UzhLangParser::WHILE);
    setState(58);
    expr(0);
    setState(59);
    match(UzhLangParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfLineContext ------------------------------------------------------------------

UzhLangParser::IfLineContext::IfLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::IfLineContext::BOL() {
  return getToken(UzhLangParser::BOL, 0);
}

tree::TerminalNode* UzhLangParser::IfLineContext::IF() {
  return getToken(UzhLangParser::IF, 0);
}

UzhLangParser::ExprContext* UzhLangParser::IfLineContext::expr() {
  return getRuleContext<UzhLangParser::ExprContext>(0);
}


size_t UzhLangParser::IfLineContext::getRuleIndex() const {
  return UzhLangParser::RuleIfLine;
}

void UzhLangParser::IfLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfLine(this);
}

void UzhLangParser::IfLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfLine(this);
}


antlrcpp::Any UzhLangParser::IfLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitIfLine(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::IfLineContext* UzhLangParser::ifLine() {
  IfLineContext *_localctx = _tracker.createInstance<IfLineContext>(_ctx, getState());
  enterRule(_localctx, 8, UzhLangParser::RuleIfLine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    match(UzhLangParser::BOL);
    setState(62);
    match(UzhLangParser::IF);
    setState(63);
    expr(0);
    setState(64);
    match(UzhLangParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseLineContext ------------------------------------------------------------------

UzhLangParser::ElseLineContext::ElseLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::ElseLineContext::BOL() {
  return getToken(UzhLangParser::BOL, 0);
}

tree::TerminalNode* UzhLangParser::ElseLineContext::ELSE() {
  return getToken(UzhLangParser::ELSE, 0);
}


size_t UzhLangParser::ElseLineContext::getRuleIndex() const {
  return UzhLangParser::RuleElseLine;
}

void UzhLangParser::ElseLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseLine(this);
}

void UzhLangParser::ElseLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseLine(this);
}


antlrcpp::Any UzhLangParser::ElseLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitElseLine(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::ElseLineContext* UzhLangParser::elseLine() {
  ElseLineContext *_localctx = _tracker.createInstance<ElseLineContext>(_ctx, getState());
  enterRule(_localctx, 10, UzhLangParser::RuleElseLine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(UzhLangParser::BOL);
    setState(67);
    match(UzhLangParser::ELSE);
    setState(68);
    match(UzhLangParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignLineContext ------------------------------------------------------------------

UzhLangParser::AssignLineContext::AssignLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::AssignLineContext::BOL() {
  return getToken(UzhLangParser::BOL, 0);
}

tree::TerminalNode* UzhLangParser::AssignLineContext::ID() {
  return getToken(UzhLangParser::ID, 0);
}

UzhLangParser::ExprContext* UzhLangParser::AssignLineContext::expr() {
  return getRuleContext<UzhLangParser::ExprContext>(0);
}


size_t UzhLangParser::AssignLineContext::getRuleIndex() const {
  return UzhLangParser::RuleAssignLine;
}

void UzhLangParser::AssignLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignLine(this);
}

void UzhLangParser::AssignLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignLine(this);
}


antlrcpp::Any UzhLangParser::AssignLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitAssignLine(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::AssignLineContext* UzhLangParser::assignLine() {
  AssignLineContext *_localctx = _tracker.createInstance<AssignLineContext>(_ctx, getState());
  enterRule(_localctx, 12, UzhLangParser::RuleAssignLine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    match(UzhLangParser::BOL);
    setState(71);
    match(UzhLangParser::ID);
    setState(72);
    match(UzhLangParser::T__4);
    setState(73);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnLineContext ------------------------------------------------------------------

UzhLangParser::ReturnLineContext::ReturnLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::ReturnLineContext::BOL() {
  return getToken(UzhLangParser::BOL, 0);
}

tree::TerminalNode* UzhLangParser::ReturnLineContext::RETURN() {
  return getToken(UzhLangParser::RETURN, 0);
}

UzhLangParser::ExprContext* UzhLangParser::ReturnLineContext::expr() {
  return getRuleContext<UzhLangParser::ExprContext>(0);
}


size_t UzhLangParser::ReturnLineContext::getRuleIndex() const {
  return UzhLangParser::RuleReturnLine;
}

void UzhLangParser::ReturnLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnLine(this);
}

void UzhLangParser::ReturnLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnLine(this);
}


antlrcpp::Any UzhLangParser::ReturnLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitReturnLine(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::ReturnLineContext* UzhLangParser::returnLine() {
  ReturnLineContext *_localctx = _tracker.createInstance<ReturnLineContext>(_ctx, getState());
  enterRule(_localctx, 14, UzhLangParser::RuleReturnLine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    match(UzhLangParser::BOL);
    setState(76);
    match(UzhLangParser::RETURN);
    setState(77);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprLineContext ------------------------------------------------------------------

UzhLangParser::ExprLineContext::ExprLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::ExprLineContext::BOL() {
  return getToken(UzhLangParser::BOL, 0);
}

UzhLangParser::ExprContext* UzhLangParser::ExprLineContext::expr() {
  return getRuleContext<UzhLangParser::ExprContext>(0);
}


size_t UzhLangParser::ExprLineContext::getRuleIndex() const {
  return UzhLangParser::RuleExprLine;
}

void UzhLangParser::ExprLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprLine(this);
}

void UzhLangParser::ExprLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprLine(this);
}


antlrcpp::Any UzhLangParser::ExprLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitExprLine(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::ExprLineContext* UzhLangParser::exprLine() {
  ExprLineContext *_localctx = _tracker.createInstance<ExprLineContext>(_ctx, getState());
  enterRule(_localctx, 16, UzhLangParser::RuleExprLine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(UzhLangParser::BOL);
    setState(80);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncCallContext ------------------------------------------------------------------

UzhLangParser::FuncCallContext::FuncCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::FuncCallContext::ID() {
  return getToken(UzhLangParser::ID, 0);
}

std::vector<UzhLangParser::ExprContext *> UzhLangParser::FuncCallContext::expr() {
  return getRuleContexts<UzhLangParser::ExprContext>();
}

UzhLangParser::ExprContext* UzhLangParser::FuncCallContext::expr(size_t i) {
  return getRuleContext<UzhLangParser::ExprContext>(i);
}


size_t UzhLangParser::FuncCallContext::getRuleIndex() const {
  return UzhLangParser::RuleFuncCall;
}

void UzhLangParser::FuncCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncCall(this);
}

void UzhLangParser::FuncCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncCall(this);
}


antlrcpp::Any UzhLangParser::FuncCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitFuncCall(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::FuncCallContext* UzhLangParser::funcCall() {
  FuncCallContext *_localctx = _tracker.createInstance<FuncCallContext>(_ctx, getState());
  enterRule(_localctx, 18, UzhLangParser::RuleFuncCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(UzhLangParser::ID);
    setState(83);
    match(UzhLangParser::T__0);
    setState(92);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << UzhLangParser::T__0)
      | (1ULL << UzhLangParser::INT)
      | (1ULL << UzhLangParser::NOT)
      | (1ULL << UzhLangParser::ID))) != 0)) {
      setState(84);
      expr(0);
      setState(89);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == UzhLangParser::T__1) {
        setState(85);
        match(UzhLangParser::T__1);
        setState(86);
        expr(0);
        setState(91);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(94);
    match(UzhLangParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

UzhLangParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::ExprContext::NOT() {
  return getToken(UzhLangParser::NOT, 0);
}

std::vector<UzhLangParser::ExprContext *> UzhLangParser::ExprContext::expr() {
  return getRuleContexts<UzhLangParser::ExprContext>();
}

UzhLangParser::ExprContext* UzhLangParser::ExprContext::expr(size_t i) {
  return getRuleContext<UzhLangParser::ExprContext>(i);
}

UzhLangParser::FuncCallContext* UzhLangParser::ExprContext::funcCall() {
  return getRuleContext<UzhLangParser::FuncCallContext>(0);
}

tree::TerminalNode* UzhLangParser::ExprContext::INT() {
  return getToken(UzhLangParser::INT, 0);
}

tree::TerminalNode* UzhLangParser::ExprContext::ID() {
  return getToken(UzhLangParser::ID, 0);
}

tree::TerminalNode* UzhLangParser::ExprContext::COMP() {
  return getToken(UzhLangParser::COMP, 0);
}

tree::TerminalNode* UzhLangParser::ExprContext::AND() {
  return getToken(UzhLangParser::AND, 0);
}

tree::TerminalNode* UzhLangParser::ExprContext::OR() {
  return getToken(UzhLangParser::OR, 0);
}


size_t UzhLangParser::ExprContext::getRuleIndex() const {
  return UzhLangParser::RuleExpr;
}

void UzhLangParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void UzhLangParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any UzhLangParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


UzhLangParser::ExprContext* UzhLangParser::expr() {
   return expr(0);
}

UzhLangParser::ExprContext* UzhLangParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  UzhLangParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  UzhLangParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, UzhLangParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(106);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(97);
      match(UzhLangParser::NOT);
      setState(98);
      expr(10);
      break;
    }

    case 2: {
      setState(99);
      match(UzhLangParser::T__0);
      setState(100);
      expr(0);
      setState(101);
      match(UzhLangParser::T__2);
      break;
    }

    case 3: {
      setState(103);
      funcCall();
      break;
    }

    case 4: {
      setState(104);
      match(UzhLangParser::INT);
      break;
    }

    case 5: {
      setState(105);
      match(UzhLangParser::ID);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(125);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(123);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(108);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(109);
          _la = _input->LA(1);
          if (!(_la == UzhLangParser::T__5

          || _la == UzhLangParser::T__6)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(110);
          expr(10);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(111);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(112);
          _la = _input->LA(1);
          if (!(_la == UzhLangParser::T__7

          || _la == UzhLangParser::T__8)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(113);
          expr(9);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(114);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(115);
          match(UzhLangParser::COMP);
          setState(116);
          expr(8);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(117);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(118);
          match(UzhLangParser::AND);
          setState(119);
          expr(7);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(120);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(121);
          match(UzhLangParser::OR);
          setState(122);
          expr(6);
          break;
        }

        } 
      }
      setState(127);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool UzhLangParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 10: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool UzhLangParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 9);
    case 1: return precpred(_ctx, 8);
    case 2: return precpred(_ctx, 7);
    case 3: return precpred(_ctx, 6);
    case 4: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> UzhLangParser::_decisionToDFA;
atn::PredictionContextCache UzhLangParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN UzhLangParser::_atn;
std::vector<uint16_t> UzhLangParser::_serializedATN;

std::vector<std::string> UzhLangParser::_ruleNames = {
  "program", "line", "functionLine", "whileLine", "ifLine", "elseLine", 
  "assignLine", "returnLine", "exprLine", "funcCall", "expr"
};

std::vector<std::string> UzhLangParser::_literalNames = {
  "", "'('", "','", "')'", "':'", "'='", "'*'", "'/'", "'+'", "'-'", "", 
  "", "", "", "'def'", "'while'", "'if'", "'else'", "'return'"
};

std::vector<std::string> UzhLangParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "INT", "LC", "BOL", "HWS", "DEF", 
  "WHILE", "IF", "ELSE", "RETURN", "COMP", "AND", "OR", "NOT", "ID"
};

dfa::Vocabulary UzhLangParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> UzhLangParser::_tokenNames;

UzhLangParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x19, 0x83, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x1b, 0xa, 0x2, 
    0xd, 0x2, 0xe, 0x2, 0x1c, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x26, 0xa, 0x3, 0x3, 0x4, 0x5, 0x4, 
    0x29, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x7, 0x4, 0x31, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x34, 0xb, 0x4, 0x5, 
    0x4, 0x36, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x7, 0xb, 0x5a, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x5d, 0xb, 0xb, 
    0x5, 0xb, 0x5f, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x5, 0xc, 0x6d, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x7e, 0xa, 0xc, 0xc, 
    0xc, 0xe, 0xc, 0x81, 0xb, 0xc, 0x3, 0xc, 0x2, 0x3, 0x16, 0xd, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x2, 0x4, 0x3, 0x2, 
    0x8, 0x9, 0x3, 0x2, 0xa, 0xb, 0x2, 0x8d, 0x2, 0x1a, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x25, 0x3, 0x2, 0x2, 0x2, 0x6, 0x28, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3a, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x3f, 0x3, 0x2, 0x2, 0x2, 0xc, 0x44, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x48, 0x3, 0x2, 0x2, 0x2, 0x10, 0x4d, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x51, 0x3, 0x2, 0x2, 0x2, 0x14, 0x54, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1b, 0x5, 0x4, 0x3, 0x2, 0x19, 
    0x1b, 0x7, 0xe, 0x2, 0x2, 0x1a, 0x18, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1a, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x26, 0x5, 0x6, 0x4, 0x2, 0x1f, 0x26, 0x5, 0x8, 0x5, 
    0x2, 0x20, 0x26, 0x5, 0xa, 0x6, 0x2, 0x21, 0x26, 0x5, 0xc, 0x7, 0x2, 
    0x22, 0x26, 0x5, 0xe, 0x8, 0x2, 0x23, 0x26, 0x5, 0x12, 0xa, 0x2, 0x24, 
    0x26, 0x5, 0x10, 0x9, 0x2, 0x25, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x25, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0x25, 0x20, 0x3, 0x2, 0x2, 0x2, 0x25, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x25, 0x22, 0x3, 0x2, 0x2, 0x2, 0x25, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x25, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x27, 0x29, 0x7, 0xe, 0x2, 0x2, 0x28, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x2b, 0x7, 0x10, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0x19, 0x2, 0x2, 0x2c, 0x35, 
    0x7, 0x3, 0x2, 0x2, 0x2d, 0x32, 0x7, 0x19, 0x2, 0x2, 0x2e, 0x2f, 0x7, 
    0x4, 0x2, 0x2, 0x2f, 0x31, 0x7, 0x19, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x34, 0x3, 0x2, 0x2, 0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 
    0x2, 0x32, 0x33, 0x3, 0x2, 0x2, 0x2, 0x33, 0x36, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 0x35, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x35, 
    0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 
    0x7, 0x5, 0x2, 0x2, 0x38, 0x39, 0x7, 0x6, 0x2, 0x2, 0x39, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0xe, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x11, 
    0x2, 0x2, 0x3c, 0x3d, 0x5, 0x16, 0xc, 0x2, 0x3d, 0x3e, 0x7, 0x6, 0x2, 
    0x2, 0x3e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x7, 0xe, 0x2, 0x2, 
    0x40, 0x41, 0x7, 0x12, 0x2, 0x2, 0x41, 0x42, 0x5, 0x16, 0xc, 0x2, 0x42, 
    0x43, 0x7, 0x6, 0x2, 0x2, 0x43, 0xb, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 
    0x7, 0xe, 0x2, 0x2, 0x45, 0x46, 0x7, 0x13, 0x2, 0x2, 0x46, 0x47, 0x7, 
    0x6, 0x2, 0x2, 0x47, 0xd, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x7, 0xe, 
    0x2, 0x2, 0x49, 0x4a, 0x7, 0x19, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x7, 0x2, 
    0x2, 0x4b, 0x4c, 0x5, 0x16, 0xc, 0x2, 0x4c, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x4e, 0x7, 0xe, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x14, 0x2, 0x2, 0x4f, 
    0x50, 0x5, 0x16, 0xc, 0x2, 0x50, 0x11, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 
    0x7, 0xe, 0x2, 0x2, 0x52, 0x53, 0x5, 0x16, 0xc, 0x2, 0x53, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0x54, 0x55, 0x7, 0x19, 0x2, 0x2, 0x55, 0x5e, 0x7, 0x3, 
    0x2, 0x2, 0x56, 0x5b, 0x5, 0x16, 0xc, 0x2, 0x57, 0x58, 0x7, 0x4, 0x2, 
    0x2, 0x58, 0x5a, 0x5, 0x16, 0xc, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x5a, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 
    0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x56, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 
    0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0x5, 
    0x2, 0x2, 0x61, 0x15, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x8, 0xc, 0x1, 
    0x2, 0x63, 0x64, 0x7, 0x18, 0x2, 0x2, 0x64, 0x6d, 0x5, 0x16, 0xc, 0xc, 
    0x65, 0x66, 0x7, 0x3, 0x2, 0x2, 0x66, 0x67, 0x5, 0x16, 0xc, 0x2, 0x67, 
    0x68, 0x7, 0x5, 0x2, 0x2, 0x68, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6d, 
    0x5, 0x14, 0xb, 0x2, 0x6a, 0x6d, 0x7, 0xc, 0x2, 0x2, 0x6b, 0x6d, 0x7, 
    0x19, 0x2, 0x2, 0x6c, 0x62, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x6f, 0xc, 0xb, 0x2, 0x2, 0x6f, 0x70, 0x9, 0x2, 0x2, 0x2, 0x70, 
    0x7e, 0x5, 0x16, 0xc, 0xc, 0x71, 0x72, 0xc, 0xa, 0x2, 0x2, 0x72, 0x73, 
    0x9, 0x3, 0x2, 0x2, 0x73, 0x7e, 0x5, 0x16, 0xc, 0xb, 0x74, 0x75, 0xc, 
    0x9, 0x2, 0x2, 0x75, 0x76, 0x7, 0x15, 0x2, 0x2, 0x76, 0x7e, 0x5, 0x16, 
    0xc, 0xa, 0x77, 0x78, 0xc, 0x8, 0x2, 0x2, 0x78, 0x79, 0x7, 0x16, 0x2, 
    0x2, 0x79, 0x7e, 0x5, 0x16, 0xc, 0x9, 0x7a, 0x7b, 0xc, 0x7, 0x2, 0x2, 
    0x7b, 0x7c, 0x7, 0x17, 0x2, 0x2, 0x7c, 0x7e, 0x5, 0x16, 0xc, 0x8, 0x7d, 
    0x6e, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x71, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x74, 
    0x3, 0x2, 0x2, 0x2, 0x7d, 0x77, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7a, 0x3, 
    0x2, 0x2, 0x2, 0x7e, 0x81, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 0x3, 0x2, 
    0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0xd, 0x1a, 0x1c, 0x25, 0x28, 0x32, 
    0x35, 0x5b, 0x5e, 0x6c, 0x7d, 0x7f, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

UzhLangParser::Initializer UzhLangParser::_init;
