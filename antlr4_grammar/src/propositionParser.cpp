
// Generated from ../assertionminer/antlr4_grammar/proposition.gr by ANTLR 4.7.1


#include "propositionListener.h"

#include "propositionParser.h"


using namespace antlrcpp;
using namespace antlr4;

propositionParser::propositionParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

propositionParser::~propositionParser() {
  delete _interpreter;
}

std::string propositionParser::getGrammarFileName() const {
  return "proposition.gr";
}

const std::vector<std::string>& propositionParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& propositionParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

propositionParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

propositionParser::ExpressionContext* propositionParser::FileContext::expression() {
  return getRuleContext<propositionParser::ExpressionContext>(0);
}

tree::TerminalNode* propositionParser::FileContext::EOF() {
  return getToken(propositionParser::EOF, 0);
}


size_t propositionParser::FileContext::getRuleIndex() const {
  return propositionParser::RuleFile;
}

void propositionParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void propositionParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

propositionParser::FileContext* propositionParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, propositionParser::RuleFile);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
    expression(0);
    setState(21);
    match(propositionParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

propositionParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::ExpressionContext::LPAREN() {
  return getToken(propositionParser::LPAREN, 0);
}

std::vector<propositionParser::ExpressionContext *> propositionParser::ExpressionContext::expression() {
  return getRuleContexts<propositionParser::ExpressionContext>();
}

propositionParser::ExpressionContext* propositionParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<propositionParser::ExpressionContext>(i);
}

tree::TerminalNode* propositionParser::ExpressionContext::RPAREN() {
  return getToken(propositionParser::RPAREN, 0);
}

tree::TerminalNode* propositionParser::ExpressionContext::LGPAREN() {
  return getToken(propositionParser::LGPAREN, 0);
}

propositionParser::LogicContext* propositionParser::ExpressionContext::logic() {
  return getRuleContext<propositionParser::LogicContext>(0);
}

tree::TerminalNode* propositionParser::ExpressionContext::RGPAREN() {
  return getToken(propositionParser::RGPAREN, 0);
}

tree::TerminalNode* propositionParser::ExpressionContext::LCPAREN() {
  return getToken(propositionParser::LCPAREN, 0);
}

tree::TerminalNode* propositionParser::ExpressionContext::CONSTANT() {
  return getToken(propositionParser::CONSTANT, 0);
}

tree::TerminalNode* propositionParser::ExpressionContext::RCPAREN() {
  return getToken(propositionParser::RCPAREN, 0);
}

tree::TerminalNode* propositionParser::ExpressionContext::NextOp() {
  return getToken(propositionParser::NextOp, 0);
}

tree::TerminalNode* propositionParser::ExpressionContext::PastOp() {
  return getToken(propositionParser::PastOp, 0);
}

tree::TerminalNode* propositionParser::ExpressionContext::NOT() {
  return getToken(propositionParser::NOT, 0);
}

std::vector<propositionParser::Numeric_logicContext *> propositionParser::ExpressionContext::numeric_logic() {
  return getRuleContexts<propositionParser::Numeric_logicContext>();
}

propositionParser::Numeric_logicContext* propositionParser::ExpressionContext::numeric_logic(size_t i) {
  return getRuleContext<propositionParser::Numeric_logicContext>(i);
}

propositionParser::RelopContext* propositionParser::ExpressionContext::relop() {
  return getRuleContext<propositionParser::RelopContext>(0);
}

propositionParser::AtomContext* propositionParser::ExpressionContext::atom() {
  return getRuleContext<propositionParser::AtomContext>(0);
}

tree::TerminalNode* propositionParser::ExpressionContext::EQ() {
  return getToken(propositionParser::EQ, 0);
}

tree::TerminalNode* propositionParser::ExpressionContext::NEQ() {
  return getToken(propositionParser::NEQ, 0);
}

tree::TerminalNode* propositionParser::ExpressionContext::AND() {
  return getToken(propositionParser::AND, 0);
}

tree::TerminalNode* propositionParser::ExpressionContext::OR() {
  return getToken(propositionParser::OR, 0);
}


size_t propositionParser::ExpressionContext::getRuleIndex() const {
  return propositionParser::RuleExpression;
}

void propositionParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void propositionParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


propositionParser::ExpressionContext* propositionParser::expression() {
   return expression(0);
}

propositionParser::ExpressionContext* propositionParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  propositionParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  propositionParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, propositionParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(55);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(24);
      match(propositionParser::LPAREN);
      setState(25);
      expression(0);
      setState(26);
      match(propositionParser::RPAREN);
      break;
    }

    case 2: {
      setState(28);
      match(propositionParser::LGPAREN);
      setState(29);
      logic(0);
      setState(30);
      match(propositionParser::RGPAREN);
      setState(31);
      match(propositionParser::LCPAREN);
      setState(32);
      match(propositionParser::CONSTANT);
      setState(33);
      match(propositionParser::RCPAREN);
      break;
    }

    case 3: {
      setState(35);
      match(propositionParser::NextOp);
      setState(36);
      match(propositionParser::LCPAREN);
      setState(37);
      match(propositionParser::CONSTANT);
      setState(38);
      match(propositionParser::RCPAREN);
      setState(39);
      expression(10);
      break;
    }

    case 4: {
      setState(40);
      match(propositionParser::PastOp);
      setState(41);
      match(propositionParser::LPAREN);
      setState(42);
      expression(0);
      setState(43);
      match(propositionParser::T__0);
      setState(44);
      match(propositionParser::CONSTANT);
      setState(45);
      match(propositionParser::RPAREN);
      break;
    }

    case 5: {
      setState(47);
      match(propositionParser::NOT);
      setState(48);
      expression(8);
      break;
    }

    case 6: {
      setState(49);
      numeric_logic(0);
      setState(50);
      relop();
      setState(51);
      numeric_logic(0);
      break;
    }

    case 7: {
      setState(53);
      numeric_logic(0);
      break;
    }

    case 8: {
      setState(54);
      atom();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(71);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(69);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(57);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(58);
          match(propositionParser::EQ);
          setState(59);
          expression(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(60);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(61);
          match(propositionParser::NEQ);
          setState(62);
          expression(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(63);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(64);
          dynamic_cast<ExpressionContext *>(_localctx)->boolop = match(propositionParser::AND);
          setState(65);
          expression(5);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(66);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(67);
          dynamic_cast<ExpressionContext *>(_localctx)->boolop = match(propositionParser::OR);
          setState(68);
          expression(4);
          break;
        }

        } 
      }
      setState(73);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Numeric_logicContext ------------------------------------------------------------------

propositionParser::Numeric_logicContext::Numeric_logicContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::Numeric_logicContext::LPAREN() {
  return getToken(propositionParser::LPAREN, 0);
}

std::vector<propositionParser::Numeric_logicContext *> propositionParser::Numeric_logicContext::numeric_logic() {
  return getRuleContexts<propositionParser::Numeric_logicContext>();
}

propositionParser::Numeric_logicContext* propositionParser::Numeric_logicContext::numeric_logic(size_t i) {
  return getRuleContext<propositionParser::Numeric_logicContext>(i);
}

tree::TerminalNode* propositionParser::Numeric_logicContext::RPAREN() {
  return getToken(propositionParser::RPAREN, 0);
}

tree::TerminalNode* propositionParser::Numeric_logicContext::NextOp() {
  return getToken(propositionParser::NextOp, 0);
}

tree::TerminalNode* propositionParser::Numeric_logicContext::LCPAREN() {
  return getToken(propositionParser::LCPAREN, 0);
}

tree::TerminalNode* propositionParser::Numeric_logicContext::CONSTANT() {
  return getToken(propositionParser::CONSTANT, 0);
}

tree::TerminalNode* propositionParser::Numeric_logicContext::RCPAREN() {
  return getToken(propositionParser::RCPAREN, 0);
}

tree::TerminalNode* propositionParser::Numeric_logicContext::PastOp() {
  return getToken(propositionParser::PastOp, 0);
}

propositionParser::AtomContext* propositionParser::Numeric_logicContext::atom() {
  return getRuleContext<propositionParser::AtomContext>(0);
}

propositionParser::LogicContext* propositionParser::Numeric_logicContext::logic() {
  return getRuleContext<propositionParser::LogicContext>(0);
}

tree::TerminalNode* propositionParser::Numeric_logicContext::TIMES() {
  return getToken(propositionParser::TIMES, 0);
}

tree::TerminalNode* propositionParser::Numeric_logicContext::DIV() {
  return getToken(propositionParser::DIV, 0);
}

tree::TerminalNode* propositionParser::Numeric_logicContext::PLUS() {
  return getToken(propositionParser::PLUS, 0);
}

tree::TerminalNode* propositionParser::Numeric_logicContext::MINUS() {
  return getToken(propositionParser::MINUS, 0);
}


size_t propositionParser::Numeric_logicContext::getRuleIndex() const {
  return propositionParser::RuleNumeric_logic;
}

void propositionParser::Numeric_logicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumeric_logic(this);
}

void propositionParser::Numeric_logicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumeric_logic(this);
}


propositionParser::Numeric_logicContext* propositionParser::numeric_logic() {
   return numeric_logic(0);
}

propositionParser::Numeric_logicContext* propositionParser::numeric_logic(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  propositionParser::Numeric_logicContext *_localctx = _tracker.createInstance<Numeric_logicContext>(_ctx, parentState);
  propositionParser::Numeric_logicContext *previousContext = _localctx;
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, propositionParser::RuleNumeric_logic, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(93);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(75);
      match(propositionParser::LPAREN);
      setState(76);
      numeric_logic(0);
      setState(77);
      match(propositionParser::RPAREN);
      break;
    }

    case 2: {
      setState(79);
      match(propositionParser::NextOp);
      setState(80);
      match(propositionParser::LCPAREN);
      setState(81);
      match(propositionParser::CONSTANT);
      setState(82);
      match(propositionParser::RCPAREN);
      setState(83);
      numeric_logic(6);
      break;
    }

    case 3: {
      setState(84);
      match(propositionParser::PastOp);
      setState(85);
      match(propositionParser::LPAREN);
      setState(86);
      numeric_logic(0);
      setState(87);
      match(propositionParser::T__0);
      setState(88);
      match(propositionParser::CONSTANT);
      setState(89);
      match(propositionParser::RPAREN);
      break;
    }

    case 4: {
      setState(91);
      atom();
      break;
    }

    case 5: {
      setState(92);
      logic(0);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(103);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(101);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Numeric_logicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric_logic);
          setState(95);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(96);
          dynamic_cast<Numeric_logicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == propositionParser::TIMES

          || _la == propositionParser::DIV)) {
            dynamic_cast<Numeric_logicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(97);
          numeric_logic(3);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Numeric_logicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric_logic);
          setState(98);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(99);
          dynamic_cast<Numeric_logicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == propositionParser::PLUS

          || _la == propositionParser::MINUS)) {
            dynamic_cast<Numeric_logicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(100);
          numeric_logic(2);
          break;
        }

        } 
      }
      setState(105);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicContext ------------------------------------------------------------------

propositionParser::LogicContext::LogicContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::LogicContext::LPAREN() {
  return getToken(propositionParser::LPAREN, 0);
}

std::vector<propositionParser::LogicContext *> propositionParser::LogicContext::logic() {
  return getRuleContexts<propositionParser::LogicContext>();
}

propositionParser::LogicContext* propositionParser::LogicContext::logic(size_t i) {
  return getRuleContext<propositionParser::LogicContext>(i);
}

tree::TerminalNode* propositionParser::LogicContext::RPAREN() {
  return getToken(propositionParser::RPAREN, 0);
}

tree::TerminalNode* propositionParser::LogicContext::LGPAREN() {
  return getToken(propositionParser::LGPAREN, 0);
}

tree::TerminalNode* propositionParser::LogicContext::RGPAREN() {
  return getToken(propositionParser::RGPAREN, 0);
}

tree::TerminalNode* propositionParser::LogicContext::LCPAREN() {
  return getToken(propositionParser::LCPAREN, 0);
}

tree::TerminalNode* propositionParser::LogicContext::CONSTANT() {
  return getToken(propositionParser::CONSTANT, 0);
}

tree::TerminalNode* propositionParser::LogicContext::RCPAREN() {
  return getToken(propositionParser::RCPAREN, 0);
}

propositionParser::Upper_boundContext* propositionParser::LogicContext::upper_bound() {
  return getRuleContext<propositionParser::Upper_boundContext>(0);
}

propositionParser::Lower_boundContext* propositionParser::LogicContext::lower_bound() {
  return getRuleContext<propositionParser::Lower_boundContext>(0);
}

propositionParser::AtomContext* propositionParser::LogicContext::atom() {
  return getRuleContext<propositionParser::AtomContext>(0);
}

tree::TerminalNode* propositionParser::LogicContext::NEG() {
  return getToken(propositionParser::NEG, 0);
}

tree::TerminalNode* propositionParser::LogicContext::BAND() {
  return getToken(propositionParser::BAND, 0);
}

tree::TerminalNode* propositionParser::LogicContext::BOR() {
  return getToken(propositionParser::BOR, 0);
}


size_t propositionParser::LogicContext::getRuleIndex() const {
  return propositionParser::RuleLogic;
}

void propositionParser::LogicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic(this);
}

void propositionParser::LogicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic(this);
}


propositionParser::LogicContext* propositionParser::logic() {
   return logic(0);
}

propositionParser::LogicContext* propositionParser::logic(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  propositionParser::LogicContext *_localctx = _tracker.createInstance<LogicContext>(_ctx, parentState);
  propositionParser::LogicContext *previousContext = _localctx;
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, propositionParser::RuleLogic, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(130);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(107);
      match(propositionParser::LPAREN);
      setState(108);
      logic(0);
      setState(109);
      match(propositionParser::RPAREN);
      break;
    }

    case 2: {
      setState(111);
      match(propositionParser::LGPAREN);
      setState(112);
      logic(0);
      setState(113);
      match(propositionParser::RGPAREN);
      setState(114);
      match(propositionParser::LCPAREN);
      setState(115);
      match(propositionParser::CONSTANT);
      setState(116);
      match(propositionParser::RCPAREN);
      break;
    }

    case 3: {
      setState(118);
      match(propositionParser::LGPAREN);
      setState(119);
      logic(0);
      setState(120);
      match(propositionParser::RGPAREN);
      setState(121);
      match(propositionParser::LCPAREN);
      setState(122);
      upper_bound();
      setState(123);
      match(propositionParser::T__1);
      setState(124);
      lower_bound();
      setState(125);
      match(propositionParser::RCPAREN);
      break;
    }

    case 4: {
      setState(127);
      atom();
      break;
    }

    case 5: {
      setState(128);
      match(propositionParser::NEG);
      setState(129);
      logic(3);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(140);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(138);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(132);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(133);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(propositionParser::BAND);
          setState(134);
          logic(3);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(135);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(136);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(propositionParser::BOR);
          setState(137);
          logic(2);
          break;
        }

        } 
      }
      setState(142);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

propositionParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

propositionParser::ConstantContext* propositionParser::AtomContext::constant() {
  return getRuleContext<propositionParser::ConstantContext>(0);
}

propositionParser::VariableContext* propositionParser::AtomContext::variable() {
  return getRuleContext<propositionParser::VariableContext>(0);
}


size_t propositionParser::AtomContext::getRuleIndex() const {
  return propositionParser::RuleAtom;
}

void propositionParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void propositionParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

propositionParser::AtomContext* propositionParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 8, propositionParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(145);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case propositionParser::CONSTANT: {
        enterOuterAlt(_localctx, 1);
        setState(143);
        constant();
        break;
      }

      case propositionParser::VARIABLE: {
        enterOuterAlt(_localctx, 2);
        setState(144);
        variable();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

propositionParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::ConstantContext::CONSTANT() {
  return getToken(propositionParser::CONSTANT, 0);
}


size_t propositionParser::ConstantContext::getRuleIndex() const {
  return propositionParser::RuleConstant;
}

void propositionParser::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}

void propositionParser::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}

propositionParser::ConstantContext* propositionParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 10, propositionParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    match(propositionParser::CONSTANT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

propositionParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::VariableContext::VARIABLE() {
  return getToken(propositionParser::VARIABLE, 0);
}


size_t propositionParser::VariableContext::getRuleIndex() const {
  return propositionParser::RuleVariable;
}

void propositionParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void propositionParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

propositionParser::VariableContext* propositionParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 12, propositionParser::RuleVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    match(propositionParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Upper_boundContext ------------------------------------------------------------------

propositionParser::Upper_boundContext::Upper_boundContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::Upper_boundContext::CONSTANT() {
  return getToken(propositionParser::CONSTANT, 0);
}


size_t propositionParser::Upper_boundContext::getRuleIndex() const {
  return propositionParser::RuleUpper_bound;
}

void propositionParser::Upper_boundContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpper_bound(this);
}

void propositionParser::Upper_boundContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpper_bound(this);
}

propositionParser::Upper_boundContext* propositionParser::upper_bound() {
  Upper_boundContext *_localctx = _tracker.createInstance<Upper_boundContext>(_ctx, getState());
  enterRule(_localctx, 14, propositionParser::RuleUpper_bound);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    match(propositionParser::CONSTANT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Lower_boundContext ------------------------------------------------------------------

propositionParser::Lower_boundContext::Lower_boundContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::Lower_boundContext::CONSTANT() {
  return getToken(propositionParser::CONSTANT, 0);
}


size_t propositionParser::Lower_boundContext::getRuleIndex() const {
  return propositionParser::RuleLower_bound;
}

void propositionParser::Lower_boundContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLower_bound(this);
}

void propositionParser::Lower_boundContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLower_bound(this);
}

propositionParser::Lower_boundContext* propositionParser::lower_bound() {
  Lower_boundContext *_localctx = _tracker.createInstance<Lower_boundContext>(_ctx, getState());
  enterRule(_localctx, 16, propositionParser::RuleLower_bound);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    match(propositionParser::CONSTANT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelopContext ------------------------------------------------------------------

propositionParser::RelopContext::RelopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::RelopContext::GT() {
  return getToken(propositionParser::GT, 0);
}

tree::TerminalNode* propositionParser::RelopContext::GE() {
  return getToken(propositionParser::GE, 0);
}

tree::TerminalNode* propositionParser::RelopContext::LT() {
  return getToken(propositionParser::LT, 0);
}

tree::TerminalNode* propositionParser::RelopContext::LE() {
  return getToken(propositionParser::LE, 0);
}


size_t propositionParser::RelopContext::getRuleIndex() const {
  return propositionParser::RuleRelop;
}

void propositionParser::RelopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelop(this);
}

void propositionParser::RelopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelop(this);
}

propositionParser::RelopContext* propositionParser::relop() {
  RelopContext *_localctx = _tracker.createInstance<RelopContext>(_ctx, getState());
  enterRule(_localctx, 18, propositionParser::RuleRelop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << propositionParser::GT)
      | (1ULL << propositionParser::GE)
      | (1ULL << propositionParser::LT)
      | (1ULL << propositionParser::LE))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool propositionParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 2: return numeric_logicSempred(dynamic_cast<Numeric_logicContext *>(context), predicateIndex);
    case 3: return logicSempred(dynamic_cast<LogicContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool propositionParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool propositionParser::numeric_logicSempred(Numeric_logicContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 2);
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool propositionParser::logicSempred(LogicContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 2);
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> propositionParser::_decisionToDFA;
atn::PredictionContextCache propositionParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN propositionParser::_atn;
std::vector<uint16_t> propositionParser::_serializedATN;

std::vector<std::string> propositionParser::_ruleNames = {
  "file", "expression", "numeric_logic", "logic", "atom", "constant", "variable", 
  "upper_bound", "lower_bound", "relop"
};

std::vector<std::string> propositionParser::_literalNames = {
  "", "','", "':'", "'X'", "'$past'", "'{'", "'}'", "'['", "']'", "'('", 
  "')'", "", "", "'+'", "'-'", "'*'", "'/'", "'>'", "'>='", "'<'", "'<='", 
  "'=='", "'!='", "'&'", "'|'", "'^'", "'~'", "'&&'", "'||'", "'!'"
};

std::vector<std::string> propositionParser::_symbolicNames = {
  "", "", "", "NextOp", "PastOp", "LGPAREN", "RGPAREN", "LCPAREN", "RCPAREN", 
  "LPAREN", "RPAREN", "VARIABLE", "CONSTANT", "PLUS", "MINUS", "TIMES", 
  "DIV", "GT", "GE", "LT", "LE", "EQ", "NEQ", "BAND", "BOR", "BXOR", "NEG", 
  "AND", "OR", "NOT", "WS"
};

dfa::Vocabulary propositionParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> propositionParser::_tokenNames;

propositionParser::Initializer::Initializer() {
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
    0x3, 0x20, 0xa0, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x3a, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x7, 0x3, 0x48, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x4b, 0xb, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x60, 0xa, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0x68, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x6b, 0xb, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x85, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x8d, 0xa, 0x5, 0xc, 0x5, 0xe, 
    0x5, 0x90, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x94, 0xa, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x2, 0x5, 0x4, 0x6, 0x8, 0xc, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x2, 0x5, 0x3, 0x2, 
    0x11, 0x12, 0x3, 0x2, 0xf, 0x10, 0x3, 0x2, 0x13, 0x16, 0x2, 0xad, 0x2, 
    0x16, 0x3, 0x2, 0x2, 0x2, 0x4, 0x39, 0x3, 0x2, 0x2, 0x2, 0x6, 0x5f, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x84, 0x3, 0x2, 0x2, 0x2, 0xa, 0x93, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x95, 0x3, 0x2, 0x2, 0x2, 0xe, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x99, 0x3, 0x2, 0x2, 0x2, 0x12, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x5, 0x4, 0x3, 0x2, 0x17, 0x18, 
    0x7, 0x2, 0x2, 0x3, 0x18, 0x3, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x8, 
    0x3, 0x1, 0x2, 0x1a, 0x1b, 0x7, 0xb, 0x2, 0x2, 0x1b, 0x1c, 0x5, 0x4, 
    0x3, 0x2, 0x1c, 0x1d, 0x7, 0xc, 0x2, 0x2, 0x1d, 0x3a, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x1f, 0x7, 0x7, 0x2, 0x2, 0x1f, 0x20, 0x5, 0x8, 0x5, 0x2, 
    0x20, 0x21, 0x7, 0x8, 0x2, 0x2, 0x21, 0x22, 0x7, 0x9, 0x2, 0x2, 0x22, 
    0x23, 0x7, 0xe, 0x2, 0x2, 0x23, 0x24, 0x7, 0xa, 0x2, 0x2, 0x24, 0x3a, 
    0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x7, 0x5, 0x2, 0x2, 0x26, 0x27, 0x7, 
    0x9, 0x2, 0x2, 0x27, 0x28, 0x7, 0xe, 0x2, 0x2, 0x28, 0x29, 0x7, 0xa, 
    0x2, 0x2, 0x29, 0x3a, 0x5, 0x4, 0x3, 0xc, 0x2a, 0x2b, 0x7, 0x6, 0x2, 
    0x2, 0x2b, 0x2c, 0x7, 0xb, 0x2, 0x2, 0x2c, 0x2d, 0x5, 0x4, 0x3, 0x2, 
    0x2d, 0x2e, 0x7, 0x3, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0xe, 0x2, 0x2, 0x2f, 
    0x30, 0x7, 0xc, 0x2, 0x2, 0x30, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 
    0x7, 0x1f, 0x2, 0x2, 0x32, 0x3a, 0x5, 0x4, 0x3, 0xa, 0x33, 0x34, 0x5, 
    0x6, 0x4, 0x2, 0x34, 0x35, 0x5, 0x14, 0xb, 0x2, 0x35, 0x36, 0x5, 0x6, 
    0x4, 0x2, 0x36, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x37, 0x3a, 0x5, 0x6, 0x4, 
    0x2, 0x38, 0x3a, 0x5, 0xa, 0x6, 0x2, 0x39, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0x39, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x39, 0x25, 0x3, 0x2, 0x2, 0x2, 0x39, 
    0x2a, 0x3, 0x2, 0x2, 0x2, 0x39, 0x31, 0x3, 0x2, 0x2, 0x2, 0x39, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x38, 0x3, 
    0x2, 0x2, 0x2, 0x3a, 0x49, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0xc, 0x8, 
    0x2, 0x2, 0x3c, 0x3d, 0x7, 0x17, 0x2, 0x2, 0x3d, 0x48, 0x5, 0x4, 0x3, 
    0x9, 0x3e, 0x3f, 0xc, 0x7, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x18, 0x2, 0x2, 
    0x40, 0x48, 0x5, 0x4, 0x3, 0x8, 0x41, 0x42, 0xc, 0x6, 0x2, 0x2, 0x42, 
    0x43, 0x7, 0x1d, 0x2, 0x2, 0x43, 0x48, 0x5, 0x4, 0x3, 0x7, 0x44, 0x45, 
    0xc, 0x5, 0x2, 0x2, 0x45, 0x46, 0x7, 0x1e, 0x2, 0x2, 0x46, 0x48, 0x5, 
    0x4, 0x3, 0x6, 0x47, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x47, 0x3e, 0x3, 0x2, 
    0x2, 0x2, 0x47, 0x41, 0x3, 0x2, 0x2, 0x2, 0x47, 0x44, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x5, 0x3, 0x2, 0x2, 0x2, 0x4b, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x8, 0x4, 0x1, 0x2, 0x4d, 0x4e, 
    0x7, 0xb, 0x2, 0x2, 0x4e, 0x4f, 0x5, 0x6, 0x4, 0x2, 0x4f, 0x50, 0x7, 
    0xc, 0x2, 0x2, 0x50, 0x60, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x5, 
    0x2, 0x2, 0x52, 0x53, 0x7, 0x9, 0x2, 0x2, 0x53, 0x54, 0x7, 0xe, 0x2, 
    0x2, 0x54, 0x55, 0x7, 0xa, 0x2, 0x2, 0x55, 0x60, 0x5, 0x6, 0x4, 0x8, 
    0x56, 0x57, 0x7, 0x6, 0x2, 0x2, 0x57, 0x58, 0x7, 0xb, 0x2, 0x2, 0x58, 
    0x59, 0x5, 0x6, 0x4, 0x2, 0x59, 0x5a, 0x7, 0x3, 0x2, 0x2, 0x5a, 0x5b, 
    0x7, 0xe, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0xc, 0x2, 0x2, 0x5c, 0x60, 0x3, 
    0x2, 0x2, 0x2, 0x5d, 0x60, 0x5, 0xa, 0x6, 0x2, 0x5e, 0x60, 0x5, 0x8, 
    0x5, 0x2, 0x5f, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x5f, 0x56, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 
    0x5f, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 0x69, 0x3, 0x2, 0x2, 0x2, 0x61, 
    0x62, 0xc, 0x4, 0x2, 0x2, 0x62, 0x63, 0x9, 0x2, 0x2, 0x2, 0x63, 0x68, 
    0x5, 0x6, 0x4, 0x5, 0x64, 0x65, 0xc, 0x3, 0x2, 0x2, 0x65, 0x66, 0x9, 
    0x3, 0x2, 0x2, 0x66, 0x68, 0x5, 0x6, 0x4, 0x4, 0x67, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x67, 0x64, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0x7, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x6d, 0x8, 0x5, 0x1, 0x2, 0x6d, 0x6e, 0x7, 0xb, 0x2, 0x2, 0x6e, 0x6f, 
    0x5, 0x8, 0x5, 0x2, 0x6f, 0x70, 0x7, 0xc, 0x2, 0x2, 0x70, 0x85, 0x3, 
    0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0x7, 0x2, 0x2, 0x72, 0x73, 0x5, 0x8, 
    0x5, 0x2, 0x73, 0x74, 0x7, 0x8, 0x2, 0x2, 0x74, 0x75, 0x7, 0x9, 0x2, 
    0x2, 0x75, 0x76, 0x7, 0xe, 0x2, 0x2, 0x76, 0x77, 0x7, 0xa, 0x2, 0x2, 
    0x77, 0x85, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x7, 0x7, 0x2, 0x2, 0x79, 
    0x7a, 0x5, 0x8, 0x5, 0x2, 0x7a, 0x7b, 0x7, 0x8, 0x2, 0x2, 0x7b, 0x7c, 
    0x7, 0x9, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0x10, 0x9, 0x2, 0x7d, 0x7e, 0x7, 
    0x4, 0x2, 0x2, 0x7e, 0x7f, 0x5, 0x12, 0xa, 0x2, 0x7f, 0x80, 0x7, 0xa, 
    0x2, 0x2, 0x80, 0x85, 0x3, 0x2, 0x2, 0x2, 0x81, 0x85, 0x5, 0xa, 0x6, 
    0x2, 0x82, 0x83, 0x7, 0x1c, 0x2, 0x2, 0x83, 0x85, 0x5, 0x8, 0x5, 0x5, 
    0x84, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x84, 0x71, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x78, 0x3, 0x2, 0x2, 0x2, 0x84, 0x81, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 
    0x3, 0x2, 0x2, 0x2, 0x85, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0xc, 
    0x4, 0x2, 0x2, 0x87, 0x88, 0x7, 0x19, 0x2, 0x2, 0x88, 0x8d, 0x5, 0x8, 
    0x5, 0x5, 0x89, 0x8a, 0xc, 0x3, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x1a, 0x2, 
    0x2, 0x8b, 0x8d, 0x5, 0x8, 0x5, 0x4, 0x8c, 0x86, 0x3, 0x2, 0x2, 0x2, 
    0x8c, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x91, 0x94, 0x5, 
    0xc, 0x7, 0x2, 0x92, 0x94, 0x5, 0xe, 0x8, 0x2, 0x93, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x93, 0x92, 0x3, 0x2, 0x2, 0x2, 0x94, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x95, 0x96, 0x7, 0xe, 0x2, 0x2, 0x96, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x98, 0x7, 0xd, 0x2, 0x2, 0x98, 0xf, 0x3, 0x2, 0x2, 0x2, 0x99, 
    0x9a, 0x7, 0xe, 0x2, 0x2, 0x9a, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 
    0x7, 0xe, 0x2, 0x2, 0x9c, 0x13, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x9, 
    0x4, 0x2, 0x2, 0x9e, 0x15, 0x3, 0x2, 0x2, 0x2, 0xc, 0x39, 0x47, 0x49, 
    0x5f, 0x67, 0x69, 0x84, 0x8c, 0x8e, 0x93, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

propositionParser::Initializer propositionParser::_init;
