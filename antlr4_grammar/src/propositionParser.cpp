
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

propositionParser::PropositionContext* propositionParser::FileContext::proposition() {
  return getRuleContext<propositionParser::PropositionContext>(0);
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
    setState(32);
    proposition();
    setState(33);
    match(propositionParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropositionContext ------------------------------------------------------------------

propositionParser::PropositionContext::PropositionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

propositionParser::AtomicPropContext* propositionParser::PropositionContext::atomicProp() {
  return getRuleContext<propositionParser::AtomicPropContext>(0);
}


size_t propositionParser::PropositionContext::getRuleIndex() const {
  return propositionParser::RuleProposition;
}

void propositionParser::PropositionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProposition(this);
}

void propositionParser::PropositionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProposition(this);
}

propositionParser::PropositionContext* propositionParser::proposition() {
  PropositionContext *_localctx = _tracker.createInstance<PropositionContext>(_ctx, getState());
  enterRule(_localctx, 2, propositionParser::RuleProposition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    atomicProp();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomicPropContext ------------------------------------------------------------------

propositionParser::AtomicPropContext::AtomicPropContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

propositionParser::NumericExpressionContext* propositionParser::AtomicPropContext::numericExpression() {
  return getRuleContext<propositionParser::NumericExpressionContext>(0);
}

propositionParser::BooleanExpressionContext* propositionParser::AtomicPropContext::booleanExpression() {
  return getRuleContext<propositionParser::BooleanExpressionContext>(0);
}

propositionParser::LogicExpressionContext* propositionParser::AtomicPropContext::logicExpression() {
  return getRuleContext<propositionParser::LogicExpressionContext>(0);
}

tree::TerminalNode* propositionParser::AtomicPropContext::LPAREN() {
  return getToken(propositionParser::LPAREN, 0);
}

propositionParser::AtomicPropContext* propositionParser::AtomicPropContext::atomicProp() {
  return getRuleContext<propositionParser::AtomicPropContext>(0);
}

tree::TerminalNode* propositionParser::AtomicPropContext::RPAREN() {
  return getToken(propositionParser::RPAREN, 0);
}


size_t propositionParser::AtomicPropContext::getRuleIndex() const {
  return propositionParser::RuleAtomicProp;
}

void propositionParser::AtomicPropContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtomicProp(this);
}

void propositionParser::AtomicPropContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtomicProp(this);
}

propositionParser::AtomicPropContext* propositionParser::atomicProp() {
  AtomicPropContext *_localctx = _tracker.createInstance<AtomicPropContext>(_ctx, getState());
  enterRule(_localctx, 4, propositionParser::RuleAtomicProp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(44);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(37);
      numericExpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(38);
      booleanExpression(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(39);
      logicExpression(0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(40);
      match(propositionParser::LPAREN);
      setState(41);
      atomicProp();
      setState(42);
      match(propositionParser::RPAREN);
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

//----------------- NumericExpressionContext ------------------------------------------------------------------

propositionParser::NumericExpressionContext::NumericExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::NumericExpressionContext::LPAREN() {
  return getToken(propositionParser::LPAREN, 0);
}

std::vector<propositionParser::NumericExpressionContext *> propositionParser::NumericExpressionContext::numericExpression() {
  return getRuleContexts<propositionParser::NumericExpressionContext>();
}

propositionParser::NumericExpressionContext* propositionParser::NumericExpressionContext::numericExpression(size_t i) {
  return getRuleContext<propositionParser::NumericExpressionContext>(i);
}

tree::TerminalNode* propositionParser::NumericExpressionContext::RPAREN() {
  return getToken(propositionParser::RPAREN, 0);
}

propositionParser::AtomContext* propositionParser::NumericExpressionContext::atom() {
  return getRuleContext<propositionParser::AtomContext>(0);
}

propositionParser::ArtopContext* propositionParser::NumericExpressionContext::artop() {
  return getRuleContext<propositionParser::ArtopContext>(0);
}

propositionParser::RelopContext* propositionParser::NumericExpressionContext::relop() {
  return getRuleContext<propositionParser::RelopContext>(0);
}

propositionParser::BoolopContext* propositionParser::NumericExpressionContext::boolop() {
  return getRuleContext<propositionParser::BoolopContext>(0);
}

propositionParser::BooleanExpressionContext* propositionParser::NumericExpressionContext::booleanExpression() {
  return getRuleContext<propositionParser::BooleanExpressionContext>(0);
}


size_t propositionParser::NumericExpressionContext::getRuleIndex() const {
  return propositionParser::RuleNumericExpression;
}

void propositionParser::NumericExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericExpression(this);
}

void propositionParser::NumericExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericExpression(this);
}


propositionParser::NumericExpressionContext* propositionParser::numericExpression() {
   return numericExpression(0);
}

propositionParser::NumericExpressionContext* propositionParser::numericExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  propositionParser::NumericExpressionContext *_localctx = _tracker.createInstance<NumericExpressionContext>(_ctx, parentState);
  propositionParser::NumericExpressionContext *previousContext = _localctx;
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, propositionParser::RuleNumericExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(52);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case propositionParser::LPAREN: {
        setState(47);
        match(propositionParser::LPAREN);
        setState(48);
        numericExpression(0);
        setState(49);
        match(propositionParser::RPAREN);
        break;
      }

      case propositionParser::NextOp:
      case propositionParser::VARIABLE:
      case propositionParser::CONSTANT: {
        setState(51);
        atom();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(68);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(66);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<NumericExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumericExpression);
          setState(54);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(55);
          artop();
          setState(56);
          numericExpression(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<NumericExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumericExpression);
          setState(58);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(59);
          relop();
          setState(60);
          numericExpression(5);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<NumericExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumericExpression);
          setState(62);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(63);
          boolop();
          setState(64);
          booleanExpression(0);
          break;
        }

        } 
      }
      setState(70);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BooleanExpressionContext ------------------------------------------------------------------

propositionParser::BooleanExpressionContext::BooleanExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> propositionParser::BooleanExpressionContext::NOT() {
  return getTokens(propositionParser::NOT);
}

tree::TerminalNode* propositionParser::BooleanExpressionContext::NOT(size_t i) {
  return getToken(propositionParser::NOT, i);
}

std::vector<propositionParser::HandleNotContext *> propositionParser::BooleanExpressionContext::handleNot() {
  return getRuleContexts<propositionParser::HandleNotContext>();
}

propositionParser::HandleNotContext* propositionParser::BooleanExpressionContext::handleNot(size_t i) {
  return getRuleContext<propositionParser::HandleNotContext>(i);
}

propositionParser::BoolopContext* propositionParser::BooleanExpressionContext::boolop() {
  return getRuleContext<propositionParser::BoolopContext>(0);
}

std::vector<propositionParser::BooleanExpressionContext *> propositionParser::BooleanExpressionContext::booleanExpression() {
  return getRuleContexts<propositionParser::BooleanExpressionContext>();
}

propositionParser::BooleanExpressionContext* propositionParser::BooleanExpressionContext::booleanExpression(size_t i) {
  return getRuleContext<propositionParser::BooleanExpressionContext>(i);
}

std::vector<propositionParser::NumericExpressionContext *> propositionParser::BooleanExpressionContext::numericExpression() {
  return getRuleContexts<propositionParser::NumericExpressionContext>();
}

propositionParser::NumericExpressionContext* propositionParser::BooleanExpressionContext::numericExpression(size_t i) {
  return getRuleContext<propositionParser::NumericExpressionContext>(i);
}

propositionParser::RelopContext* propositionParser::BooleanExpressionContext::relop() {
  return getRuleContext<propositionParser::RelopContext>(0);
}

std::vector<propositionParser::LogicExpressionContext *> propositionParser::BooleanExpressionContext::logicExpression() {
  return getRuleContexts<propositionParser::LogicExpressionContext>();
}

propositionParser::LogicExpressionContext* propositionParser::BooleanExpressionContext::logicExpression(size_t i) {
  return getRuleContext<propositionParser::LogicExpressionContext>(i);
}

propositionParser::LrelopContext* propositionParser::BooleanExpressionContext::lrelop() {
  return getRuleContext<propositionParser::LrelopContext>(0);
}

tree::TerminalNode* propositionParser::BooleanExpressionContext::LPAREN() {
  return getToken(propositionParser::LPAREN, 0);
}

tree::TerminalNode* propositionParser::BooleanExpressionContext::RPAREN() {
  return getToken(propositionParser::RPAREN, 0);
}

propositionParser::AtomContext* propositionParser::BooleanExpressionContext::atom() {
  return getRuleContext<propositionParser::AtomContext>(0);
}


size_t propositionParser::BooleanExpressionContext::getRuleIndex() const {
  return propositionParser::RuleBooleanExpression;
}

void propositionParser::BooleanExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanExpression(this);
}

void propositionParser::BooleanExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanExpression(this);
}


propositionParser::BooleanExpressionContext* propositionParser::booleanExpression() {
   return booleanExpression(0);
}

propositionParser::BooleanExpressionContext* propositionParser::booleanExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  propositionParser::BooleanExpressionContext *_localctx = _tracker.createInstance<BooleanExpressionContext>(_ctx, parentState);
  propositionParser::BooleanExpressionContext *previousContext = _localctx;
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, propositionParser::RuleBooleanExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(98);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      break;
    }

    case 2: {
      setState(72);
      match(propositionParser::NOT);
      setState(73);
      handleNot();
      setState(74);
      boolop();
      setState(75);
      match(propositionParser::NOT);
      setState(76);
      handleNot();
      break;
    }

    case 3: {
      setState(78);
      match(propositionParser::NOT);
      setState(79);
      handleNot();
      setState(80);
      boolop();
      setState(81);
      booleanExpression(9);
      break;
    }

    case 4: {
      setState(83);
      match(propositionParser::NOT);
      setState(84);
      handleNot();
      break;
    }

    case 5: {
      setState(85);
      numericExpression(0);
      setState(86);
      relop();
      setState(87);
      numericExpression(0);
      break;
    }

    case 6: {
      setState(89);
      logicExpression(0);
      setState(90);
      lrelop();
      setState(91);
      logicExpression(0);
      break;
    }

    case 7: {
      setState(93);
      match(propositionParser::LPAREN);
      setState(94);
      booleanExpression(0);
      setState(95);
      match(propositionParser::RPAREN);
      break;
    }

    case 8: {
      setState(97);
      atom();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(119);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(117);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<BooleanExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBooleanExpression);
          setState(100);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(101);
          boolop();
          setState(102);
          booleanExpression(8);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<BooleanExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBooleanExpression);
          setState(104);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(105);
          boolop();
          setState(106);
          match(propositionParser::NOT);
          setState(107);
          handleNot();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<BooleanExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBooleanExpression);
          setState(109);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(110);
          relop();
          setState(111);
          numericExpression(0);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<BooleanExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBooleanExpression);
          setState(113);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(114);
          relop();
          setState(115);
          logicExpression(0);
          break;
        }

        } 
      }
      setState(121);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- HandleNotContext ------------------------------------------------------------------

propositionParser::HandleNotContext::HandleNotContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

propositionParser::BooleanExpressionContext* propositionParser::HandleNotContext::booleanExpression() {
  return getRuleContext<propositionParser::BooleanExpressionContext>(0);
}


size_t propositionParser::HandleNotContext::getRuleIndex() const {
  return propositionParser::RuleHandleNot;
}

void propositionParser::HandleNotContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHandleNot(this);
}

void propositionParser::HandleNotContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHandleNot(this);
}

propositionParser::HandleNotContext* propositionParser::handleNot() {
  HandleNotContext *_localctx = _tracker.createInstance<HandleNotContext>(_ctx, getState());
  enterRule(_localctx, 10, propositionParser::RuleHandleNot);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    booleanExpression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HandleNegContext ------------------------------------------------------------------

propositionParser::HandleNegContext::HandleNegContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

propositionParser::LogicExpressionContext* propositionParser::HandleNegContext::logicExpression() {
  return getRuleContext<propositionParser::LogicExpressionContext>(0);
}


size_t propositionParser::HandleNegContext::getRuleIndex() const {
  return propositionParser::RuleHandleNeg;
}

void propositionParser::HandleNegContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHandleNeg(this);
}

void propositionParser::HandleNegContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHandleNeg(this);
}

propositionParser::HandleNegContext* propositionParser::handleNeg() {
  HandleNegContext *_localctx = _tracker.createInstance<HandleNegContext>(_ctx, getState());
  enterRule(_localctx, 12, propositionParser::RuleHandleNeg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    logicExpression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicExpressionContext ------------------------------------------------------------------

propositionParser::LogicExpressionContext::LogicExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> propositionParser::LogicExpressionContext::NEG() {
  return getTokens(propositionParser::NEG);
}

tree::TerminalNode* propositionParser::LogicExpressionContext::NEG(size_t i) {
  return getToken(propositionParser::NEG, i);
}

std::vector<propositionParser::HandleNegContext *> propositionParser::LogicExpressionContext::handleNeg() {
  return getRuleContexts<propositionParser::HandleNegContext>();
}

propositionParser::HandleNegContext* propositionParser::LogicExpressionContext::handleNeg(size_t i) {
  return getRuleContext<propositionParser::HandleNegContext>(i);
}

propositionParser::LogopContext* propositionParser::LogicExpressionContext::logop() {
  return getRuleContext<propositionParser::LogopContext>(0);
}

std::vector<propositionParser::LogicExpressionContext *> propositionParser::LogicExpressionContext::logicExpression() {
  return getRuleContexts<propositionParser::LogicExpressionContext>();
}

propositionParser::LogicExpressionContext* propositionParser::LogicExpressionContext::logicExpression(size_t i) {
  return getRuleContext<propositionParser::LogicExpressionContext>(i);
}

tree::TerminalNode* propositionParser::LogicExpressionContext::LPAREN() {
  return getToken(propositionParser::LPAREN, 0);
}

tree::TerminalNode* propositionParser::LogicExpressionContext::RPAREN() {
  return getToken(propositionParser::RPAREN, 0);
}

propositionParser::AtomContext* propositionParser::LogicExpressionContext::atom() {
  return getRuleContext<propositionParser::AtomContext>(0);
}

propositionParser::LrelopContext* propositionParser::LogicExpressionContext::lrelop() {
  return getRuleContext<propositionParser::LrelopContext>(0);
}

propositionParser::BoolopContext* propositionParser::LogicExpressionContext::boolop() {
  return getRuleContext<propositionParser::BoolopContext>(0);
}

propositionParser::BooleanExpressionContext* propositionParser::LogicExpressionContext::booleanExpression() {
  return getRuleContext<propositionParser::BooleanExpressionContext>(0);
}


size_t propositionParser::LogicExpressionContext::getRuleIndex() const {
  return propositionParser::RuleLogicExpression;
}

void propositionParser::LogicExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicExpression(this);
}

void propositionParser::LogicExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicExpression(this);
}


propositionParser::LogicExpressionContext* propositionParser::logicExpression() {
   return logicExpression(0);
}

propositionParser::LogicExpressionContext* propositionParser::logicExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  propositionParser::LogicExpressionContext *_localctx = _tracker.createInstance<LogicExpressionContext>(_ctx, parentState);
  propositionParser::LogicExpressionContext *previousContext = _localctx;
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, propositionParser::RuleLogicExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(145);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(127);
      match(propositionParser::NEG);
      setState(128);
      handleNeg();
      setState(129);
      logop();
      setState(130);
      match(propositionParser::NEG);
      setState(131);
      handleNeg();
      break;
    }

    case 2: {
      setState(133);
      match(propositionParser::NEG);
      setState(134);
      handleNeg();
      setState(135);
      logop();
      setState(136);
      logicExpression(7);
      break;
    }

    case 3: {
      setState(138);
      match(propositionParser::NEG);
      setState(139);
      handleNeg();
      break;
    }

    case 4: {
      setState(140);
      match(propositionParser::LPAREN);
      setState(141);
      logicExpression(0);
      setState(142);
      match(propositionParser::RPAREN);
      break;
    }

    case 5: {
      setState(144);
      atom();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(166);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(164);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogicExpression);
          setState(147);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(148);
          logop();
          setState(149);
          logicExpression(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogicExpression);
          setState(151);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(152);
          lrelop();
          setState(153);
          logicExpression(5);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<LogicExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogicExpression);
          setState(155);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(156);
          logop();
          setState(157);
          match(propositionParser::NEG);
          setState(158);
          handleNeg();
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<LogicExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogicExpression);
          setState(160);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(161);
          boolop();
          setState(162);
          booleanExpression(0);
          break;
        }

        } 
      }
      setState(168);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
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
  enterRule(_localctx, 16, propositionParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(171);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case propositionParser::CONSTANT: {
        enterOuterAlt(_localctx, 1);
        setState(169);
        constant();
        break;
      }

      case propositionParser::NextOp:
      case propositionParser::VARIABLE: {
        enterOuterAlt(_localctx, 2);
        setState(170);
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
  enterRule(_localctx, 18, propositionParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
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

tree::TerminalNode* propositionParser::VariableContext::NextOp() {
  return getToken(propositionParser::NextOp, 0);
}

tree::TerminalNode* propositionParser::VariableContext::LCPAREN() {
  return getToken(propositionParser::LCPAREN, 0);
}

tree::TerminalNode* propositionParser::VariableContext::CONSTANT() {
  return getToken(propositionParser::CONSTANT, 0);
}

tree::TerminalNode* propositionParser::VariableContext::RCPAREN() {
  return getToken(propositionParser::RCPAREN, 0);
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
  enterRule(_localctx, 20, propositionParser::RuleVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(181);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case propositionParser::VARIABLE: {
        enterOuterAlt(_localctx, 1);
        setState(175);
        match(propositionParser::VARIABLE);
        break;
      }

      case propositionParser::NextOp: {
        enterOuterAlt(_localctx, 2);
        setState(176);
        match(propositionParser::NextOp);
        setState(177);
        match(propositionParser::LCPAREN);
        setState(178);
        match(propositionParser::CONSTANT);
        setState(179);
        match(propositionParser::RCPAREN);
        setState(180);
        match(propositionParser::VARIABLE);
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

//----------------- ArtopContext ------------------------------------------------------------------

propositionParser::ArtopContext::ArtopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::ArtopContext::TIMES() {
  return getToken(propositionParser::TIMES, 0);
}

tree::TerminalNode* propositionParser::ArtopContext::DIV() {
  return getToken(propositionParser::DIV, 0);
}

tree::TerminalNode* propositionParser::ArtopContext::PLUS() {
  return getToken(propositionParser::PLUS, 0);
}

tree::TerminalNode* propositionParser::ArtopContext::MINUS() {
  return getToken(propositionParser::MINUS, 0);
}


size_t propositionParser::ArtopContext::getRuleIndex() const {
  return propositionParser::RuleArtop;
}

void propositionParser::ArtopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArtop(this);
}

void propositionParser::ArtopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArtop(this);
}

propositionParser::ArtopContext* propositionParser::artop() {
  ArtopContext *_localctx = _tracker.createInstance<ArtopContext>(_ctx, getState());
  enterRule(_localctx, 22, propositionParser::RuleArtop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << propositionParser::PLUS)
      | (1ULL << propositionParser::MINUS)
      | (1ULL << propositionParser::TIMES)
      | (1ULL << propositionParser::DIV))) != 0))) {
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

//----------------- LrelopContext ------------------------------------------------------------------

propositionParser::LrelopContext::LrelopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::LrelopContext::EQ_() {
  return getToken(propositionParser::EQ_, 0);
}

tree::TerminalNode* propositionParser::LrelopContext::NEQ_() {
  return getToken(propositionParser::NEQ_, 0);
}

tree::TerminalNode* propositionParser::LrelopContext::GT_() {
  return getToken(propositionParser::GT_, 0);
}

tree::TerminalNode* propositionParser::LrelopContext::GE_() {
  return getToken(propositionParser::GE_, 0);
}

tree::TerminalNode* propositionParser::LrelopContext::LT_() {
  return getToken(propositionParser::LT_, 0);
}

tree::TerminalNode* propositionParser::LrelopContext::LE_() {
  return getToken(propositionParser::LE_, 0);
}


size_t propositionParser::LrelopContext::getRuleIndex() const {
  return propositionParser::RuleLrelop;
}

void propositionParser::LrelopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLrelop(this);
}

void propositionParser::LrelopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLrelop(this);
}

propositionParser::LrelopContext* propositionParser::lrelop() {
  LrelopContext *_localctx = _tracker.createInstance<LrelopContext>(_ctx, getState());
  enterRule(_localctx, 24, propositionParser::RuleLrelop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(185);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << propositionParser::GT_)
      | (1ULL << propositionParser::GE_)
      | (1ULL << propositionParser::LT_)
      | (1ULL << propositionParser::LE_)
      | (1ULL << propositionParser::EQ_)
      | (1ULL << propositionParser::NEQ_))) != 0))) {
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

//----------------- RelopContext ------------------------------------------------------------------

propositionParser::RelopContext::RelopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::RelopContext::EQ() {
  return getToken(propositionParser::EQ, 0);
}

tree::TerminalNode* propositionParser::RelopContext::NEQ() {
  return getToken(propositionParser::NEQ, 0);
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
  enterRule(_localctx, 26, propositionParser::RuleRelop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(187);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << propositionParser::GT)
      | (1ULL << propositionParser::GE)
      | (1ULL << propositionParser::LT)
      | (1ULL << propositionParser::LE)
      | (1ULL << propositionParser::EQ)
      | (1ULL << propositionParser::NEQ))) != 0))) {
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

//----------------- LogopContext ------------------------------------------------------------------

propositionParser::LogopContext::LogopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::LogopContext::BAND() {
  return getToken(propositionParser::BAND, 0);
}

tree::TerminalNode* propositionParser::LogopContext::BOR() {
  return getToken(propositionParser::BOR, 0);
}

tree::TerminalNode* propositionParser::LogopContext::BXOR() {
  return getToken(propositionParser::BXOR, 0);
}

tree::TerminalNode* propositionParser::LogopContext::TIMES_() {
  return getToken(propositionParser::TIMES_, 0);
}

tree::TerminalNode* propositionParser::LogopContext::DIV_() {
  return getToken(propositionParser::DIV_, 0);
}

tree::TerminalNode* propositionParser::LogopContext::PLUS_() {
  return getToken(propositionParser::PLUS_, 0);
}

tree::TerminalNode* propositionParser::LogopContext::MINUS_() {
  return getToken(propositionParser::MINUS_, 0);
}


size_t propositionParser::LogopContext::getRuleIndex() const {
  return propositionParser::RuleLogop;
}

void propositionParser::LogopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogop(this);
}

void propositionParser::LogopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogop(this);
}

propositionParser::LogopContext* propositionParser::logop() {
  LogopContext *_localctx = _tracker.createInstance<LogopContext>(_ctx, getState());
  enterRule(_localctx, 28, propositionParser::RuleLogop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << propositionParser::BAND)
      | (1ULL << propositionParser::BOR)
      | (1ULL << propositionParser::BXOR)
      | (1ULL << propositionParser::PLUS_)
      | (1ULL << propositionParser::MINUS_)
      | (1ULL << propositionParser::TIMES_)
      | (1ULL << propositionParser::DIV_))) != 0))) {
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

//----------------- BoolopContext ------------------------------------------------------------------

propositionParser::BoolopContext::BoolopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::BoolopContext::AND() {
  return getToken(propositionParser::AND, 0);
}

tree::TerminalNode* propositionParser::BoolopContext::OR() {
  return getToken(propositionParser::OR, 0);
}


size_t propositionParser::BoolopContext::getRuleIndex() const {
  return propositionParser::RuleBoolop;
}

void propositionParser::BoolopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolop(this);
}

void propositionParser::BoolopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolop(this);
}

propositionParser::BoolopContext* propositionParser::boolop() {
  BoolopContext *_localctx = _tracker.createInstance<BoolopContext>(_ctx, getState());
  enterRule(_localctx, 30, propositionParser::RuleBoolop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    _la = _input->LA(1);
    if (!(_la == propositionParser::AND

    || _la == propositionParser::OR)) {
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
    case 3: return numericExpressionSempred(dynamic_cast<NumericExpressionContext *>(context), predicateIndex);
    case 4: return booleanExpressionSempred(dynamic_cast<BooleanExpressionContext *>(context), predicateIndex);
    case 7: return logicExpressionSempred(dynamic_cast<LogicExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool propositionParser::numericExpressionSempred(NumericExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool propositionParser::booleanExpressionSempred(BooleanExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 7);
    case 4: return precpred(_ctx, 10);
    case 5: return precpred(_ctx, 6);
    case 6: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool propositionParser::logicExpressionSempred(LogicExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 5);
    case 8: return precpred(_ctx, 4);
    case 9: return precpred(_ctx, 8);
    case 10: return precpred(_ctx, 3);

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
  "file", "proposition", "atomicProp", "numericExpression", "booleanExpression", 
  "handleNot", "handleNeg", "logicExpression", "atom", "constant", "variable", 
  "artop", "lrelop", "relop", "logop", "boolop"
};

std::vector<std::string> propositionParser::_literalNames = {
  "", "'X'", "'['", "']'", "'('", "')'", "", "", "'+'", "'-'", "'*'", "'/'", 
  "'>_'", "'>=_'", "'<_'", "'<=_'", "'=_'", "'!=_'", "'>'", "'>='", "'<'", 
  "'<='", "'='", "'!='", "'&'", "'|'", "'^'", "'~'", "'+_'", "'-_'", "'*_'", 
  "'/_'", "'&&'", "'||'", "'!'"
};

std::vector<std::string> propositionParser::_symbolicNames = {
  "", "NextOp", "LCPAREN", "RCPAREN", "LPAREN", "RPAREN", "VARIABLE", "CONSTANT", 
  "PLUS", "MINUS", "TIMES", "DIV", "GT_", "GE_", "LT_", "LE_", "EQ_", "NEQ_", 
  "GT", "GE", "LT", "LE", "EQ", "NEQ", "BAND", "BOR", "BXOR", "NEG", "PLUS_", 
  "MINUS_", "TIMES_", "DIV_", "AND", "OR", "NOT", "WS"
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
    0x3, 0x25, 0xc4, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x2f, 0xa, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x37, 
    0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 
    0x45, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x48, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x65, 0xa, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x78, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 
    0x7b, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x94, 0xa, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xa7, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xaa, 
    0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xae, 0xa, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 
    0xc, 0xb8, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x2, 
    0x5, 0x8, 0xa, 0x10, 0x12, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x2, 0x7, 0x3, 0x2, 
    0xa, 0xd, 0x3, 0x2, 0xe, 0x13, 0x3, 0x2, 0x14, 0x19, 0x4, 0x2, 0x1a, 
    0x1c, 0x1e, 0x21, 0x3, 0x2, 0x22, 0x23, 0x2, 0xcf, 0x2, 0x22, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x25, 0x3, 0x2, 0x2, 0x2, 0x6, 0x2e, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x36, 0x3, 0x2, 0x2, 0x2, 0xa, 0x64, 0x3, 0x2, 0x2, 0x2, 0xc, 0x7c, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x10, 0x93, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0xad, 0x3, 0x2, 0x2, 0x2, 0x14, 0xaf, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x18, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xbd, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x20, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x23, 0x5, 0x4, 0x3, 0x2, 0x23, 0x24, 0x7, 0x2, 0x2, 0x3, 0x24, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x5, 0x6, 0x4, 0x2, 0x26, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x27, 0x2f, 0x5, 0x8, 0x5, 0x2, 0x28, 0x2f, 0x5, 0xa, 
    0x6, 0x2, 0x29, 0x2f, 0x5, 0x10, 0x9, 0x2, 0x2a, 0x2b, 0x7, 0x6, 0x2, 
    0x2, 0x2b, 0x2c, 0x5, 0x6, 0x4, 0x2, 0x2c, 0x2d, 0x7, 0x7, 0x2, 0x2, 
    0x2d, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x28, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2a, 
    0x3, 0x2, 0x2, 0x2, 0x2f, 0x7, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x8, 
    0x5, 0x1, 0x2, 0x31, 0x32, 0x7, 0x6, 0x2, 0x2, 0x32, 0x33, 0x5, 0x8, 
    0x5, 0x2, 0x33, 0x34, 0x7, 0x7, 0x2, 0x2, 0x34, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x35, 0x37, 0x5, 0x12, 0xa, 0x2, 0x36, 0x30, 0x3, 0x2, 0x2, 0x2, 
    0x36, 0x35, 0x3, 0x2, 0x2, 0x2, 0x37, 0x46, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x39, 0xc, 0x7, 0x2, 0x2, 0x39, 0x3a, 0x5, 0x18, 0xd, 0x2, 0x3a, 0x3b, 
    0x5, 0x8, 0x5, 0x8, 0x3b, 0x45, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0xc, 
    0x6, 0x2, 0x2, 0x3d, 0x3e, 0x5, 0x1c, 0xf, 0x2, 0x3e, 0x3f, 0x5, 0x8, 
    0x5, 0x7, 0x3f, 0x45, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0xc, 0x5, 0x2, 
    0x2, 0x41, 0x42, 0x5, 0x20, 0x11, 0x2, 0x42, 0x43, 0x5, 0xa, 0x6, 0x2, 
    0x43, 0x45, 0x3, 0x2, 0x2, 0x2, 0x44, 0x38, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x3c, 0x3, 0x2, 0x2, 0x2, 0x44, 0x40, 0x3, 0x2, 0x2, 0x2, 0x45, 0x48, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x47, 0x9, 0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 
    0x2, 0x2, 0x49, 0x65, 0x8, 0x6, 0x1, 0x2, 0x4a, 0x4b, 0x7, 0x24, 0x2, 
    0x2, 0x4b, 0x4c, 0x5, 0xc, 0x7, 0x2, 0x4c, 0x4d, 0x5, 0x20, 0x11, 0x2, 
    0x4d, 0x4e, 0x7, 0x24, 0x2, 0x2, 0x4e, 0x4f, 0x5, 0xc, 0x7, 0x2, 0x4f, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x7, 0x24, 0x2, 0x2, 0x51, 0x52, 
    0x5, 0xc, 0x7, 0x2, 0x52, 0x53, 0x5, 0x20, 0x11, 0x2, 0x53, 0x54, 0x5, 
    0xa, 0x6, 0xb, 0x54, 0x65, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x7, 0x24, 
    0x2, 0x2, 0x56, 0x65, 0x5, 0xc, 0x7, 0x2, 0x57, 0x58, 0x5, 0x8, 0x5, 
    0x2, 0x58, 0x59, 0x5, 0x1c, 0xf, 0x2, 0x59, 0x5a, 0x5, 0x8, 0x5, 0x2, 
    0x5a, 0x65, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x5, 0x10, 0x9, 0x2, 0x5c, 
    0x5d, 0x5, 0x1a, 0xe, 0x2, 0x5d, 0x5e, 0x5, 0x10, 0x9, 0x2, 0x5e, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x7, 0x6, 0x2, 0x2, 0x60, 0x61, 0x5, 
    0xa, 0x6, 0x2, 0x61, 0x62, 0x7, 0x7, 0x2, 0x2, 0x62, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0x63, 0x65, 0x5, 0x12, 0xa, 0x2, 0x64, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x64, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x64, 0x50, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x55, 0x3, 0x2, 0x2, 0x2, 0x64, 0x57, 0x3, 0x2, 0x2, 0x2, 0x64, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x64, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x64, 0x63, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0x79, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0xc, 
    0x9, 0x2, 0x2, 0x67, 0x68, 0x5, 0x20, 0x11, 0x2, 0x68, 0x69, 0x5, 0xa, 
    0x6, 0xa, 0x69, 0x78, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0xc, 0xc, 0x2, 
    0x2, 0x6b, 0x6c, 0x5, 0x20, 0x11, 0x2, 0x6c, 0x6d, 0x7, 0x24, 0x2, 0x2, 
    0x6d, 0x6e, 0x5, 0xc, 0x7, 0x2, 0x6e, 0x78, 0x3, 0x2, 0x2, 0x2, 0x6f, 
    0x70, 0xc, 0x8, 0x2, 0x2, 0x70, 0x71, 0x5, 0x1c, 0xf, 0x2, 0x71, 0x72, 
    0x5, 0x8, 0x5, 0x2, 0x72, 0x78, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0xc, 
    0x5, 0x2, 0x2, 0x74, 0x75, 0x5, 0x1c, 0xf, 0x2, 0x75, 0x76, 0x5, 0x10, 
    0x9, 0x2, 0x76, 0x78, 0x3, 0x2, 0x2, 0x2, 0x77, 0x66, 0x3, 0x2, 0x2, 
    0x2, 0x77, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x77, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x77, 0x73, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x79, 
    0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x5, 
    0xa, 0x6, 0x2, 0x7d, 0xd, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x5, 0x10, 
    0x9, 0x2, 0x7f, 0xf, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x8, 0x9, 0x1, 
    0x2, 0x81, 0x82, 0x7, 0x1d, 0x2, 0x2, 0x82, 0x83, 0x5, 0xe, 0x8, 0x2, 
    0x83, 0x84, 0x5, 0x1e, 0x10, 0x2, 0x84, 0x85, 0x7, 0x1d, 0x2, 0x2, 0x85, 
    0x86, 0x5, 0xe, 0x8, 0x2, 0x86, 0x94, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 
    0x7, 0x1d, 0x2, 0x2, 0x88, 0x89, 0x5, 0xe, 0x8, 0x2, 0x89, 0x8a, 0x5, 
    0x1e, 0x10, 0x2, 0x8a, 0x8b, 0x5, 0x10, 0x9, 0x9, 0x8b, 0x94, 0x3, 0x2, 
    0x2, 0x2, 0x8c, 0x8d, 0x7, 0x1d, 0x2, 0x2, 0x8d, 0x94, 0x5, 0xe, 0x8, 
    0x2, 0x8e, 0x8f, 0x7, 0x6, 0x2, 0x2, 0x8f, 0x90, 0x5, 0x10, 0x9, 0x2, 
    0x90, 0x91, 0x7, 0x7, 0x2, 0x2, 0x91, 0x94, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x94, 0x5, 0x12, 0xa, 0x2, 0x93, 0x80, 0x3, 0x2, 0x2, 0x2, 0x93, 0x87, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x93, 0x8e, 0x3, 
    0x2, 0x2, 0x2, 0x93, 0x92, 0x3, 0x2, 0x2, 0x2, 0x94, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0x95, 0x96, 0xc, 0x7, 0x2, 0x2, 0x96, 0x97, 0x5, 0x1e, 0x10, 
    0x2, 0x97, 0x98, 0x5, 0x10, 0x9, 0x8, 0x98, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0x99, 0x9a, 0xc, 0x6, 0x2, 0x2, 0x9a, 0x9b, 0x5, 0x1a, 0xe, 0x2, 0x9b, 
    0x9c, 0x5, 0x10, 0x9, 0x7, 0x9c, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 
    0xc, 0xa, 0x2, 0x2, 0x9e, 0x9f, 0x5, 0x1e, 0x10, 0x2, 0x9f, 0xa0, 0x7, 
    0x1d, 0x2, 0x2, 0xa0, 0xa1, 0x5, 0xe, 0x8, 0x2, 0xa1, 0xa7, 0x3, 0x2, 
    0x2, 0x2, 0xa2, 0xa3, 0xc, 0x5, 0x2, 0x2, 0xa3, 0xa4, 0x5, 0x20, 0x11, 
    0x2, 0xa4, 0xa5, 0x5, 0xa, 0x6, 0x2, 0xa5, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0xa6, 0x95, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x99, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xaa, 
    0x3, 0x2, 0x2, 0x2, 0xa8, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0xa9, 0x11, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0xab, 0xae, 0x5, 0x14, 0xb, 0x2, 0xac, 0xae, 0x5, 0x16, 0xc, 
    0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 0xac, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0x13, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x9, 0x2, 0x2, 0xb0, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb8, 0x7, 0x8, 0x2, 0x2, 0xb2, 0xb3, 
    0x7, 0x3, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x4, 0x2, 0x2, 0xb4, 0xb5, 0x7, 
    0x9, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x5, 0x2, 0x2, 0xb6, 0xb8, 0x7, 0x8, 
    0x2, 0x2, 0xb7, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb2, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x9, 0x2, 0x2, 0x2, 
    0xba, 0x19, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x9, 0x3, 0x2, 0x2, 0xbc, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x9, 0x4, 0x2, 0x2, 0xbe, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x9, 0x5, 0x2, 0x2, 0xc0, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0xc1, 0xc2, 0x9, 0x6, 0x2, 0x2, 0xc2, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x2e, 0x36, 0x44, 0x46, 0x64, 0x77, 0x79, 0x93, 0xa6, 
    0xa8, 0xad, 0xb7, 
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
