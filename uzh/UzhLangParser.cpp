
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

std::vector<UzhLangParser::Empty_lineContext *> UzhLangParser::ProgramContext::empty_line() {
  return getRuleContexts<UzhLangParser::Empty_lineContext>();
}

UzhLangParser::Empty_lineContext* UzhLangParser::ProgramContext::empty_line(size_t i) {
  return getRuleContext<UzhLangParser::Empty_lineContext>(i);
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
    setState(22); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(22);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(20);
        line();
        break;
      }

      case 2: {
        setState(21);
        empty_line();
        break;
      }

      }
      setState(24); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << UzhLangParser::T__0)
      | (1ULL << UzhLangParser::INT)
      | (1ULL << UzhLangParser::BOL)
      | (1ULL << UzhLangParser::DEF)
      | (1ULL << UzhLangParser::WHILE)
      | (1ULL << UzhLangParser::IF)
      | (1ULL << UzhLangParser::ELSE)
      | (1ULL << UzhLangParser::RETURN)
      | (1ULL << UzhLangParser::NOT)
      | (1ULL << UzhLangParser::ID))) != 0));
   
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

UzhLangParser::Function_lineContext* UzhLangParser::LineContext::function_line() {
  return getRuleContext<UzhLangParser::Function_lineContext>(0);
}

UzhLangParser::While_lineContext* UzhLangParser::LineContext::while_line() {
  return getRuleContext<UzhLangParser::While_lineContext>(0);
}

UzhLangParser::If_lineContext* UzhLangParser::LineContext::if_line() {
  return getRuleContext<UzhLangParser::If_lineContext>(0);
}

UzhLangParser::Else_lineContext* UzhLangParser::LineContext::else_line() {
  return getRuleContext<UzhLangParser::Else_lineContext>(0);
}

UzhLangParser::Assign_lineContext* UzhLangParser::LineContext::assign_line() {
  return getRuleContext<UzhLangParser::Assign_lineContext>(0);
}

UzhLangParser::ExprContext* UzhLangParser::LineContext::expr() {
  return getRuleContext<UzhLangParser::ExprContext>(0);
}

UzhLangParser::Return_lineContext* UzhLangParser::LineContext::return_line() {
  return getRuleContext<UzhLangParser::Return_lineContext>(0);
}

tree::TerminalNode* UzhLangParser::LineContext::BOL() {
  return getToken(UzhLangParser::BOL, 0);
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
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == UzhLangParser::BOL) {
      setState(26);
      match(UzhLangParser::BOL);
    }
    setState(36);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(29);
      function_line();
      break;
    }

    case 2: {
      setState(30);
      while_line();
      break;
    }

    case 3: {
      setState(31);
      if_line();
      break;
    }

    case 4: {
      setState(32);
      else_line();
      break;
    }

    case 5: {
      setState(33);
      assign_line();
      break;
    }

    case 6: {
      setState(34);
      expr(0);
      break;
    }

    case 7: {
      setState(35);
      return_line();
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

//----------------- Empty_lineContext ------------------------------------------------------------------

UzhLangParser::Empty_lineContext::Empty_lineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::Empty_lineContext::BOL() {
  return getToken(UzhLangParser::BOL, 0);
}


size_t UzhLangParser::Empty_lineContext::getRuleIndex() const {
  return UzhLangParser::RuleEmpty_line;
}

void UzhLangParser::Empty_lineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmpty_line(this);
}

void UzhLangParser::Empty_lineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmpty_line(this);
}


antlrcpp::Any UzhLangParser::Empty_lineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitEmpty_line(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::Empty_lineContext* UzhLangParser::empty_line() {
  Empty_lineContext *_localctx = _tracker.createInstance<Empty_lineContext>(_ctx, getState());
  enterRule(_localctx, 4, UzhLangParser::RuleEmpty_line);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    match(UzhLangParser::BOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_lineContext ------------------------------------------------------------------

UzhLangParser::Function_lineContext::Function_lineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::Function_lineContext::DEF() {
  return getToken(UzhLangParser::DEF, 0);
}

std::vector<tree::TerminalNode *> UzhLangParser::Function_lineContext::ID() {
  return getTokens(UzhLangParser::ID);
}

tree::TerminalNode* UzhLangParser::Function_lineContext::ID(size_t i) {
  return getToken(UzhLangParser::ID, i);
}


size_t UzhLangParser::Function_lineContext::getRuleIndex() const {
  return UzhLangParser::RuleFunction_line;
}

void UzhLangParser::Function_lineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_line(this);
}

void UzhLangParser::Function_lineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_line(this);
}


antlrcpp::Any UzhLangParser::Function_lineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitFunction_line(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::Function_lineContext* UzhLangParser::function_line() {
  Function_lineContext *_localctx = _tracker.createInstance<Function_lineContext>(_ctx, getState());
  enterRule(_localctx, 6, UzhLangParser::RuleFunction_line);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
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

//----------------- While_lineContext ------------------------------------------------------------------

UzhLangParser::While_lineContext::While_lineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::While_lineContext::WHILE() {
  return getToken(UzhLangParser::WHILE, 0);
}

UzhLangParser::ExprContext* UzhLangParser::While_lineContext::expr() {
  return getRuleContext<UzhLangParser::ExprContext>(0);
}


size_t UzhLangParser::While_lineContext::getRuleIndex() const {
  return UzhLangParser::RuleWhile_line;
}

void UzhLangParser::While_lineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_line(this);
}

void UzhLangParser::While_lineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_line(this);
}


antlrcpp::Any UzhLangParser::While_lineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitWhile_line(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::While_lineContext* UzhLangParser::while_line() {
  While_lineContext *_localctx = _tracker.createInstance<While_lineContext>(_ctx, getState());
  enterRule(_localctx, 8, UzhLangParser::RuleWhile_line);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(UzhLangParser::WHILE);
    setState(57);
    expr(0);
    setState(58);
    match(UzhLangParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_lineContext ------------------------------------------------------------------

UzhLangParser::If_lineContext::If_lineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::If_lineContext::IF() {
  return getToken(UzhLangParser::IF, 0);
}

UzhLangParser::ExprContext* UzhLangParser::If_lineContext::expr() {
  return getRuleContext<UzhLangParser::ExprContext>(0);
}


size_t UzhLangParser::If_lineContext::getRuleIndex() const {
  return UzhLangParser::RuleIf_line;
}

void UzhLangParser::If_lineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_line(this);
}

void UzhLangParser::If_lineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_line(this);
}


antlrcpp::Any UzhLangParser::If_lineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitIf_line(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::If_lineContext* UzhLangParser::if_line() {
  If_lineContext *_localctx = _tracker.createInstance<If_lineContext>(_ctx, getState());
  enterRule(_localctx, 10, UzhLangParser::RuleIf_line);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    match(UzhLangParser::IF);
    setState(61);
    expr(0);
    setState(62);
    match(UzhLangParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_lineContext ------------------------------------------------------------------

UzhLangParser::Else_lineContext::Else_lineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::Else_lineContext::ELSE() {
  return getToken(UzhLangParser::ELSE, 0);
}


size_t UzhLangParser::Else_lineContext::getRuleIndex() const {
  return UzhLangParser::RuleElse_line;
}

void UzhLangParser::Else_lineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElse_line(this);
}

void UzhLangParser::Else_lineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElse_line(this);
}


antlrcpp::Any UzhLangParser::Else_lineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitElse_line(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::Else_lineContext* UzhLangParser::else_line() {
  Else_lineContext *_localctx = _tracker.createInstance<Else_lineContext>(_ctx, getState());
  enterRule(_localctx, 12, UzhLangParser::RuleElse_line);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    match(UzhLangParser::ELSE);
    setState(65);
    match(UzhLangParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assign_lineContext ------------------------------------------------------------------

UzhLangParser::Assign_lineContext::Assign_lineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::Assign_lineContext::ID() {
  return getToken(UzhLangParser::ID, 0);
}

UzhLangParser::ExprContext* UzhLangParser::Assign_lineContext::expr() {
  return getRuleContext<UzhLangParser::ExprContext>(0);
}


size_t UzhLangParser::Assign_lineContext::getRuleIndex() const {
  return UzhLangParser::RuleAssign_line;
}

void UzhLangParser::Assign_lineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign_line(this);
}

void UzhLangParser::Assign_lineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign_line(this);
}


antlrcpp::Any UzhLangParser::Assign_lineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitAssign_line(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::Assign_lineContext* UzhLangParser::assign_line() {
  Assign_lineContext *_localctx = _tracker.createInstance<Assign_lineContext>(_ctx, getState());
  enterRule(_localctx, 14, UzhLangParser::RuleAssign_line);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    match(UzhLangParser::ID);
    setState(68);
    match(UzhLangParser::T__4);
    setState(69);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_lineContext ------------------------------------------------------------------

UzhLangParser::Return_lineContext::Return_lineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UzhLangParser::Return_lineContext::RETURN() {
  return getToken(UzhLangParser::RETURN, 0);
}

UzhLangParser::ExprContext* UzhLangParser::Return_lineContext::expr() {
  return getRuleContext<UzhLangParser::ExprContext>(0);
}


size_t UzhLangParser::Return_lineContext::getRuleIndex() const {
  return UzhLangParser::RuleReturn_line;
}

void UzhLangParser::Return_lineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_line(this);
}

void UzhLangParser::Return_lineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UzhLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_line(this);
}


antlrcpp::Any UzhLangParser::Return_lineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UzhLangVisitor*>(visitor))
    return parserVisitor->visitReturn_line(this);
  else
    return visitor->visitChildren(this);
}

UzhLangParser::Return_lineContext* UzhLangParser::return_line() {
  Return_lineContext *_localctx = _tracker.createInstance<Return_lineContext>(_ctx, getState());
  enterRule(_localctx, 16, UzhLangParser::RuleReturn_line);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    match(UzhLangParser::RETURN);
    setState(72);
    expr(0);
   
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

tree::TerminalNode* UzhLangParser::ExprContext::ID() {
  return getToken(UzhLangParser::ID, 0);
}

tree::TerminalNode* UzhLangParser::ExprContext::INT() {
  return getToken(UzhLangParser::INT, 0);
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
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, UzhLangParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(96);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(75);
      match(UzhLangParser::NOT);
      setState(76);
      expr(10);
      break;
    }

    case 2: {
      setState(77);
      match(UzhLangParser::T__0);
      setState(78);
      expr(0);
      setState(79);
      match(UzhLangParser::T__2);
      break;
    }

    case 3: {
      setState(81);
      match(UzhLangParser::ID);
      setState(82);
      match(UzhLangParser::T__0);
      setState(91);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << UzhLangParser::T__0)
        | (1ULL << UzhLangParser::INT)
        | (1ULL << UzhLangParser::NOT)
        | (1ULL << UzhLangParser::ID))) != 0)) {
        setState(83);
        expr(0);
        setState(88);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == UzhLangParser::T__1) {
          setState(84);
          match(UzhLangParser::T__1);
          setState(85);
          expr(0);
          setState(90);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(93);
      match(UzhLangParser::T__2);
      break;
    }

    case 4: {
      setState(94);
      match(UzhLangParser::INT);
      break;
    }

    case 5: {
      setState(95);
      match(UzhLangParser::ID);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(115);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(113);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(98);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(99);
          _la = _input->LA(1);
          if (!(_la == UzhLangParser::T__5

          || _la == UzhLangParser::T__6)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(100);
          expr(10);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(101);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(102);
          _la = _input->LA(1);
          if (!(_la == UzhLangParser::T__7

          || _la == UzhLangParser::T__8)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(103);
          expr(9);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(104);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(105);
          match(UzhLangParser::COMP);
          setState(106);
          expr(8);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(107);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(108);
          match(UzhLangParser::AND);
          setState(109);
          expr(7);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(110);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(111);
          match(UzhLangParser::OR);
          setState(112);
          expr(6);
          break;
        }

        } 
      }
      setState(117);
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
    case 9: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

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
  "program", "line", "empty_line", "function_line", "while_line", "if_line", 
  "else_line", "assign_line", "return_line", "expr"
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
    0x3, 0x19, 0x79, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x19, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 
    0x1a, 0x3, 0x3, 0x5, 0x3, 0x1e, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x27, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x7, 0x5, 0x31, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x34, 0xb, 0x5, 0x5, 
    0x5, 0x36, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x7, 0xb, 0x59, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x5c, 0xb, 0xb, 0x5, 0xb, 
    0x5e, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x63, 0xa, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x7, 0xb, 0x74, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x77, 0xb, 0xb, 
    0x3, 0xb, 0x2, 0x3, 0x14, 0xc, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x2, 0x4, 0x3, 0x2, 0x8, 0x9, 0x3, 0x2, 0xa, 0xb, 0x2, 0x84, 
    0x2, 0x18, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x6, 0x28, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x2a, 0x3, 0x2, 0x2, 0x2, 0xa, 0x3a, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x3e, 0x3, 0x2, 0x2, 0x2, 0xe, 0x42, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x45, 0x3, 0x2, 0x2, 0x2, 0x12, 0x49, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0x16, 0x19, 0x5, 0x4, 0x3, 0x2, 0x17, 0x19, 
    0x5, 0x6, 0x4, 0x2, 0x18, 0x16, 0x3, 0x2, 0x2, 0x2, 0x18, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x19, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x18, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x1e, 0x7, 0xe, 0x2, 0x2, 0x1d, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x1d, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x26, 0x3, 0x2, 0x2, 0x2, 0x1f, 
    0x27, 0x5, 0x8, 0x5, 0x2, 0x20, 0x27, 0x5, 0xa, 0x6, 0x2, 0x21, 0x27, 
    0x5, 0xc, 0x7, 0x2, 0x22, 0x27, 0x5, 0xe, 0x8, 0x2, 0x23, 0x27, 0x5, 
    0x10, 0x9, 0x2, 0x24, 0x27, 0x5, 0x14, 0xb, 0x2, 0x25, 0x27, 0x5, 0x12, 
    0xa, 0x2, 0x26, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x26, 0x20, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x21, 0x3, 0x2, 0x2, 0x2, 0x26, 0x22, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x23, 0x3, 0x2, 0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 0x5, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 
    0x7, 0xe, 0x2, 0x2, 0x29, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x7, 
    0x10, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0x19, 0x2, 0x2, 0x2c, 0x35, 0x7, 0x3, 
    0x2, 0x2, 0x2d, 0x32, 0x7, 0x19, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x4, 0x2, 
    0x2, 0x2f, 0x31, 0x7, 0x19, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 
    0x31, 0x34, 0x3, 0x2, 0x2, 0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x33, 0x36, 0x3, 0x2, 0x2, 0x2, 0x34, 0x32, 
    0x3, 0x2, 0x2, 0x2, 0x35, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x7, 0x5, 
    0x2, 0x2, 0x38, 0x39, 0x7, 0x6, 0x2, 0x2, 0x39, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x3a, 0x3b, 0x7, 0x11, 0x2, 0x2, 0x3b, 0x3c, 0x5, 0x14, 0xb, 0x2, 
    0x3c, 0x3d, 0x7, 0x6, 0x2, 0x2, 0x3d, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x3f, 0x7, 0x12, 0x2, 0x2, 0x3f, 0x40, 0x5, 0x14, 0xb, 0x2, 0x40, 0x41, 
    0x7, 0x6, 0x2, 0x2, 0x41, 0xd, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x7, 
    0x13, 0x2, 0x2, 0x43, 0x44, 0x7, 0x6, 0x2, 0x2, 0x44, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x45, 0x46, 0x7, 0x19, 0x2, 0x2, 0x46, 0x47, 0x7, 0x7, 0x2, 
    0x2, 0x47, 0x48, 0x5, 0x14, 0xb, 0x2, 0x48, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x49, 0x4a, 0x7, 0x14, 0x2, 0x2, 0x4a, 0x4b, 0x5, 0x14, 0xb, 0x2, 0x4b, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x8, 0xb, 0x1, 0x2, 0x4d, 0x4e, 
    0x7, 0x18, 0x2, 0x2, 0x4e, 0x63, 0x5, 0x14, 0xb, 0xc, 0x4f, 0x50, 0x7, 
    0x3, 0x2, 0x2, 0x50, 0x51, 0x5, 0x14, 0xb, 0x2, 0x51, 0x52, 0x7, 0x5, 
    0x2, 0x2, 0x52, 0x63, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0x19, 0x2, 
    0x2, 0x54, 0x5d, 0x7, 0x3, 0x2, 0x2, 0x55, 0x5a, 0x5, 0x14, 0xb, 0x2, 
    0x56, 0x57, 0x7, 0x4, 0x2, 0x2, 0x57, 0x59, 0x5, 0x14, 0xb, 0x2, 0x58, 
    0x56, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 
    0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5e, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x55, 0x3, 0x2, 
    0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 
    0x2, 0x5f, 0x63, 0x7, 0x5, 0x2, 0x2, 0x60, 0x63, 0x7, 0xc, 0x2, 0x2, 
    0x61, 0x63, 0x7, 0x19, 0x2, 0x2, 0x62, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x62, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x62, 0x53, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 
    0x3, 0x2, 0x2, 0x2, 0x62, 0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 0x75, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x65, 0xc, 0xb, 0x2, 0x2, 0x65, 0x66, 0x9, 0x2, 
    0x2, 0x2, 0x66, 0x74, 0x5, 0x14, 0xb, 0xc, 0x67, 0x68, 0xc, 0xa, 0x2, 
    0x2, 0x68, 0x69, 0x9, 0x3, 0x2, 0x2, 0x69, 0x74, 0x5, 0x14, 0xb, 0xb, 
    0x6a, 0x6b, 0xc, 0x9, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x15, 0x2, 0x2, 0x6c, 
    0x74, 0x5, 0x14, 0xb, 0xa, 0x6d, 0x6e, 0xc, 0x8, 0x2, 0x2, 0x6e, 0x6f, 
    0x7, 0x16, 0x2, 0x2, 0x6f, 0x74, 0x5, 0x14, 0xb, 0x9, 0x70, 0x71, 0xc, 
    0x7, 0x2, 0x2, 0x71, 0x72, 0x7, 0x17, 0x2, 0x2, 0x72, 0x74, 0x5, 0x14, 
    0xb, 0x8, 0x73, 0x64, 0x3, 0x2, 0x2, 0x2, 0x73, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x73, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x73, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x73, 0x70, 0x3, 0x2, 0x2, 0x2, 0x74, 0x77, 0x3, 0x2, 0x2, 0x2, 0x75, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0xd, 0x18, 0x1a, 
    0x1d, 0x26, 0x32, 0x35, 0x5a, 0x5d, 0x62, 0x73, 0x75, 
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
