
// Generated from A-TEAM/antlr4_grammar/proposition.gr by ANTLR 4.7.2


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

propositionParser::BooleanContext* propositionParser::FileContext::boolean() {
  return getRuleContext<propositionParser::BooleanContext>(0);
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
    setState(36);
    boolean(0);
    setState(37);
    match(propositionParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanContext ------------------------------------------------------------------

propositionParser::BooleanContext::BooleanContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::BooleanContext::LPAREN() {
  return getToken(propositionParser::LPAREN, 0);
}

std::vector<propositionParser::BooleanContext *> propositionParser::BooleanContext::boolean() {
  return getRuleContexts<propositionParser::BooleanContext>();
}

propositionParser::BooleanContext* propositionParser::BooleanContext::boolean(size_t i) {
  return getRuleContext<propositionParser::BooleanContext>(i);
}

tree::TerminalNode* propositionParser::BooleanContext::RPAREN() {
  return getToken(propositionParser::RPAREN, 0);
}

tree::TerminalNode* propositionParser::BooleanContext::NextOp() {
  return getToken(propositionParser::NextOp, 0);
}

tree::TerminalNode* propositionParser::BooleanContext::LCPAREN() {
  return getToken(propositionParser::LCPAREN, 0);
}

propositionParser::ConstantContext* propositionParser::BooleanContext::constant() {
  return getRuleContext<propositionParser::ConstantContext>(0);
}

tree::TerminalNode* propositionParser::BooleanContext::RCPAREN() {
  return getToken(propositionParser::RCPAREN, 0);
}

tree::TerminalNode* propositionParser::BooleanContext::PastOp() {
  return getToken(propositionParser::PastOp, 0);
}

tree::TerminalNode* propositionParser::BooleanContext::NOT() {
  return getToken(propositionParser::NOT, 0);
}

std::vector<propositionParser::LogicContext *> propositionParser::BooleanContext::logic() {
  return getRuleContexts<propositionParser::LogicContext>();
}

propositionParser::LogicContext* propositionParser::BooleanContext::logic(size_t i) {
  return getRuleContext<propositionParser::LogicContext>(i);
}

propositionParser::RelopContext* propositionParser::BooleanContext::relop() {
  return getRuleContext<propositionParser::RelopContext>(0);
}

std::vector<propositionParser::NumericContext *> propositionParser::BooleanContext::numeric() {
  return getRuleContexts<propositionParser::NumericContext>();
}

propositionParser::NumericContext* propositionParser::BooleanContext::numeric(size_t i) {
  return getRuleContext<propositionParser::NumericContext>(i);
}

tree::TerminalNode* propositionParser::BooleanContext::EQ() {
  return getToken(propositionParser::EQ, 0);
}

tree::TerminalNode* propositionParser::BooleanContext::NEQ() {
  return getToken(propositionParser::NEQ, 0);
}

propositionParser::BooleanAtomContext* propositionParser::BooleanContext::booleanAtom() {
  return getRuleContext<propositionParser::BooleanAtomContext>(0);
}

tree::TerminalNode* propositionParser::BooleanContext::AND() {
  return getToken(propositionParser::AND, 0);
}

tree::TerminalNode* propositionParser::BooleanContext::OR() {
  return getToken(propositionParser::OR, 0);
}


size_t propositionParser::BooleanContext::getRuleIndex() const {
  return propositionParser::RuleBoolean;
}

void propositionParser::BooleanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean(this);
}

void propositionParser::BooleanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean(this);
}


propositionParser::BooleanContext* propositionParser::boolean() {
   return boolean(0);
}

propositionParser::BooleanContext* propositionParser::boolean(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  propositionParser::BooleanContext *_localctx = _tracker.createInstance<BooleanContext>(_ctx, parentState);
  propositionParser::BooleanContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, propositionParser::RuleBoolean, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(85);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(40);
      match(propositionParser::LPAREN);
      setState(41);
      boolean(0);
      setState(42);
      match(propositionParser::RPAREN);
      break;
    }

    case 2: {
      setState(44);
      match(propositionParser::NextOp);
      setState(45);
      match(propositionParser::LCPAREN);
      setState(46);
      constant();
      setState(47);
      match(propositionParser::RCPAREN);
      setState(48);
      boolean(15);
      break;
    }

    case 3: {
      setState(50);
      match(propositionParser::PastOp);
      setState(51);
      match(propositionParser::LPAREN);
      setState(52);
      boolean(0);
      setState(53);
      match(propositionParser::T__0);
      setState(54);
      constant();
      setState(55);
      match(propositionParser::RPAREN);
      break;
    }

    case 4: {
      setState(57);
      match(propositionParser::NOT);
      setState(58);
      boolean(13);
      break;
    }

    case 5: {
      setState(59);
      logic(0);
      setState(60);
      relop();
      setState(61);
      logic(0);
      break;
    }

    case 6: {
      setState(63);
      numeric(0);
      setState(64);
      relop();
      setState(65);
      numeric(0);
      break;
    }

    case 7: {
      setState(67);
      logic(0);
      setState(68);
      match(propositionParser::EQ);
      setState(69);
      logic(0);
      break;
    }

    case 8: {
      setState(71);
      numeric(0);
      setState(72);
      match(propositionParser::EQ);
      setState(73);
      numeric(0);
      break;
    }

    case 9: {
      setState(75);
      logic(0);
      setState(76);
      match(propositionParser::NEQ);
      setState(77);
      logic(0);
      break;
    }

    case 10: {
      setState(79);
      numeric(0);
      setState(80);
      match(propositionParser::NEQ);
      setState(81);
      numeric(0);
      break;
    }

    case 11: {
      setState(83);
      booleanAtom();
      break;
    }

    case 12: {
      setState(84);
      logic(0);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(101);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(99);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(87);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(88);
          match(propositionParser::EQ);
          setState(89);
          boolean(11);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(90);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(91);
          match(propositionParser::NEQ);
          setState(92);
          boolean(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(93);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(94);
          dynamic_cast<BooleanContext *>(_localctx)->booleanop = match(propositionParser::AND);
          setState(95);
          boolean(5);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(96);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(97);
          dynamic_cast<BooleanContext *>(_localctx)->booleanop = match(propositionParser::OR);
          setState(98);
          boolean(4);
          break;
        }

        } 
      }
      setState(103);
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

//----------------- BooleanAtomContext ------------------------------------------------------------------

propositionParser::BooleanAtomContext::BooleanAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

propositionParser::BooleanConstantContext* propositionParser::BooleanAtomContext::booleanConstant() {
  return getRuleContext<propositionParser::BooleanConstantContext>(0);
}

propositionParser::BooleanVariableContext* propositionParser::BooleanAtomContext::booleanVariable() {
  return getRuleContext<propositionParser::BooleanVariableContext>(0);
}


size_t propositionParser::BooleanAtomContext::getRuleIndex() const {
  return propositionParser::RuleBooleanAtom;
}

void propositionParser::BooleanAtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanAtom(this);
}

void propositionParser::BooleanAtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanAtom(this);
}

propositionParser::BooleanAtomContext* propositionParser::booleanAtom() {
  BooleanAtomContext *_localctx = _tracker.createInstance<BooleanAtomContext>(_ctx, getState());
  enterRule(_localctx, 4, propositionParser::RuleBooleanAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(106);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case propositionParser::BOOLEAN: {
        enterOuterAlt(_localctx, 1);
        setState(104);
        booleanConstant();
        break;
      }

      case propositionParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(105);
        booleanVariable();
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

//----------------- BooleanConstantContext ------------------------------------------------------------------

propositionParser::BooleanConstantContext::BooleanConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::BooleanConstantContext::BOOLEAN() {
  return getToken(propositionParser::BOOLEAN, 0);
}


size_t propositionParser::BooleanConstantContext::getRuleIndex() const {
  return propositionParser::RuleBooleanConstant;
}

void propositionParser::BooleanConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanConstant(this);
}

void propositionParser::BooleanConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanConstant(this);
}

propositionParser::BooleanConstantContext* propositionParser::booleanConstant() {
  BooleanConstantContext *_localctx = _tracker.createInstance<BooleanConstantContext>(_ctx, getState());
  enterRule(_localctx, 6, propositionParser::RuleBooleanConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(propositionParser::BOOLEAN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanVariableContext ------------------------------------------------------------------

propositionParser::BooleanVariableContext::BooleanVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::BooleanVariableContext::LT() {
  return getToken(propositionParser::LT, 0);
}

propositionParser::VariableContext* propositionParser::BooleanVariableContext::variable() {
  return getRuleContext<propositionParser::VariableContext>(0);
}


size_t propositionParser::BooleanVariableContext::getRuleIndex() const {
  return propositionParser::RuleBooleanVariable;
}

void propositionParser::BooleanVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanVariable(this);
}

void propositionParser::BooleanVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanVariable(this);
}

propositionParser::BooleanVariableContext* propositionParser::booleanVariable() {
  BooleanVariableContext *_localctx = _tracker.createInstance<BooleanVariableContext>(_ctx, getState());
  enterRule(_localctx, 8, propositionParser::RuleBooleanVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    match(propositionParser::LT);
    setState(111);
    variable();
    setState(112);
    match(propositionParser::T__1);
   
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

propositionParser::ConstantContext* propositionParser::LogicContext::constant() {
  return getRuleContext<propositionParser::ConstantContext>(0);
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

tree::TerminalNode* propositionParser::LogicContext::NextOp() {
  return getToken(propositionParser::NextOp, 0);
}

tree::TerminalNode* propositionParser::LogicContext::PastOp() {
  return getToken(propositionParser::PastOp, 0);
}

tree::TerminalNode* propositionParser::LogicContext::NEG() {
  return getToken(propositionParser::NEG, 0);
}

propositionParser::LogicAtomContext* propositionParser::LogicContext::logicAtom() {
  return getRuleContext<propositionParser::LogicAtomContext>(0);
}

propositionParser::NumericContext* propositionParser::LogicContext::numeric() {
  return getRuleContext<propositionParser::NumericContext>(0);
}

tree::TerminalNode* propositionParser::LogicContext::TIMES() {
  return getToken(propositionParser::TIMES, 0);
}

tree::TerminalNode* propositionParser::LogicContext::DIV() {
  return getToken(propositionParser::DIV, 0);
}

tree::TerminalNode* propositionParser::LogicContext::PLUS() {
  return getToken(propositionParser::PLUS, 0);
}

tree::TerminalNode* propositionParser::LogicContext::MINUS() {
  return getToken(propositionParser::MINUS, 0);
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
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, propositionParser::RuleLogic, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(152);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(115);
      match(propositionParser::LPAREN);
      setState(116);
      logic(0);
      setState(117);
      match(propositionParser::RPAREN);
      break;
    }

    case 2: {
      setState(119);
      match(propositionParser::LGPAREN);
      setState(120);
      logic(0);
      setState(121);
      match(propositionParser::RGPAREN);
      setState(122);
      match(propositionParser::LCPAREN);
      setState(123);
      constant();
      setState(124);
      match(propositionParser::RCPAREN);
      break;
    }

    case 3: {
      setState(126);
      match(propositionParser::LGPAREN);
      setState(127);
      logic(0);
      setState(128);
      match(propositionParser::RGPAREN);
      setState(129);
      match(propositionParser::LCPAREN);
      setState(130);
      upper_bound();
      setState(131);
      match(propositionParser::T__2);
      setState(132);
      lower_bound();
      setState(133);
      match(propositionParser::RCPAREN);
      break;
    }

    case 4: {
      setState(135);
      match(propositionParser::NextOp);
      setState(136);
      match(propositionParser::LCPAREN);
      setState(137);
      constant();
      setState(138);
      match(propositionParser::RCPAREN);
      setState(139);
      logic(9);
      break;
    }

    case 5: {
      setState(141);
      match(propositionParser::PastOp);
      setState(142);
      match(propositionParser::LPAREN);
      setState(143);
      logic(0);
      setState(144);
      match(propositionParser::T__0);
      setState(145);
      constant();
      setState(146);
      match(propositionParser::RPAREN);
      break;
    }

    case 6: {
      setState(148);
      match(propositionParser::NEG);
      setState(149);
      logic(7);
      break;
    }

    case 7: {
      setState(150);
      logicAtom();
      break;
    }

    case 8: {
      setState(151);
      numeric(0);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(168);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(166);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(154);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(155);
          dynamic_cast<LogicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == propositionParser::TIMES

          || _la == propositionParser::DIV)) {
            dynamic_cast<LogicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(156);
          logic(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(157);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(158);
          dynamic_cast<LogicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == propositionParser::PLUS

          || _la == propositionParser::MINUS)) {
            dynamic_cast<LogicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(159);
          logic(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(160);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(161);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(propositionParser::BAND);
          setState(162);
          logic(5);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(163);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(164);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(propositionParser::BOR);
          setState(165);
          logic(4);
          break;
        }

        } 
      }
      setState(170);
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

//----------------- LogicAtomContext ------------------------------------------------------------------

propositionParser::LogicAtomContext::LogicAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

propositionParser::LogicConstantContext* propositionParser::LogicAtomContext::logicConstant() {
  return getRuleContext<propositionParser::LogicConstantContext>(0);
}

propositionParser::LogicVariableContext* propositionParser::LogicAtomContext::logicVariable() {
  return getRuleContext<propositionParser::LogicVariableContext>(0);
}


size_t propositionParser::LogicAtomContext::getRuleIndex() const {
  return propositionParser::RuleLogicAtom;
}

void propositionParser::LogicAtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicAtom(this);
}

void propositionParser::LogicAtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicAtom(this);
}

propositionParser::LogicAtomContext* propositionParser::logicAtom() {
  LogicAtomContext *_localctx = _tracker.createInstance<LogicAtomContext>(_ctx, getState());
  enterRule(_localctx, 12, propositionParser::RuleLogicAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(173);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case propositionParser::BINARY: {
        enterOuterAlt(_localctx, 1);
        setState(171);
        logicConstant();
        break;
      }

      case propositionParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(172);
        logicVariable();
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

//----------------- LogicConstantContext ------------------------------------------------------------------

propositionParser::LogicConstantContext::LogicConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::LogicConstantContext::BINARY() {
  return getToken(propositionParser::BINARY, 0);
}


size_t propositionParser::LogicConstantContext::getRuleIndex() const {
  return propositionParser::RuleLogicConstant;
}

void propositionParser::LogicConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicConstant(this);
}

void propositionParser::LogicConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicConstant(this);
}

propositionParser::LogicConstantContext* propositionParser::logicConstant() {
  LogicConstantContext *_localctx = _tracker.createInstance<LogicConstantContext>(_ctx, getState());
  enterRule(_localctx, 14, propositionParser::RuleLogicConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(propositionParser::BINARY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicVariableContext ------------------------------------------------------------------

propositionParser::LogicVariableContext::LogicVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::LogicVariableContext::LT() {
  return getToken(propositionParser::LT, 0);
}

propositionParser::VariableContext* propositionParser::LogicVariableContext::variable() {
  return getRuleContext<propositionParser::VariableContext>(0);
}


size_t propositionParser::LogicVariableContext::getRuleIndex() const {
  return propositionParser::RuleLogicVariable;
}

void propositionParser::LogicVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicVariable(this);
}

void propositionParser::LogicVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicVariable(this);
}

propositionParser::LogicVariableContext* propositionParser::logicVariable() {
  LogicVariableContext *_localctx = _tracker.createInstance<LogicVariableContext>(_ctx, getState());
  enterRule(_localctx, 16, propositionParser::RuleLogicVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(propositionParser::LT);
    setState(178);
    variable();
    setState(179);
    match(propositionParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericContext ------------------------------------------------------------------

propositionParser::NumericContext::NumericContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::NumericContext::LPAREN() {
  return getToken(propositionParser::LPAREN, 0);
}

std::vector<propositionParser::NumericContext *> propositionParser::NumericContext::numeric() {
  return getRuleContexts<propositionParser::NumericContext>();
}

propositionParser::NumericContext* propositionParser::NumericContext::numeric(size_t i) {
  return getRuleContext<propositionParser::NumericContext>(i);
}

tree::TerminalNode* propositionParser::NumericContext::RPAREN() {
  return getToken(propositionParser::RPAREN, 0);
}

tree::TerminalNode* propositionParser::NumericContext::NextOp() {
  return getToken(propositionParser::NextOp, 0);
}

tree::TerminalNode* propositionParser::NumericContext::LCPAREN() {
  return getToken(propositionParser::LCPAREN, 0);
}

propositionParser::ConstantContext* propositionParser::NumericContext::constant() {
  return getRuleContext<propositionParser::ConstantContext>(0);
}

tree::TerminalNode* propositionParser::NumericContext::RCPAREN() {
  return getToken(propositionParser::RCPAREN, 0);
}

tree::TerminalNode* propositionParser::NumericContext::PastOp() {
  return getToken(propositionParser::PastOp, 0);
}

propositionParser::NumericAtomContext* propositionParser::NumericContext::numericAtom() {
  return getRuleContext<propositionParser::NumericAtomContext>(0);
}

tree::TerminalNode* propositionParser::NumericContext::TIMES() {
  return getToken(propositionParser::TIMES, 0);
}

tree::TerminalNode* propositionParser::NumericContext::DIV() {
  return getToken(propositionParser::DIV, 0);
}

tree::TerminalNode* propositionParser::NumericContext::PLUS() {
  return getToken(propositionParser::PLUS, 0);
}

tree::TerminalNode* propositionParser::NumericContext::MINUS() {
  return getToken(propositionParser::MINUS, 0);
}


size_t propositionParser::NumericContext::getRuleIndex() const {
  return propositionParser::RuleNumeric;
}

void propositionParser::NumericContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumeric(this);
}

void propositionParser::NumericContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumeric(this);
}


propositionParser::NumericContext* propositionParser::numeric() {
   return numeric(0);
}

propositionParser::NumericContext* propositionParser::numeric(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  propositionParser::NumericContext *_localctx = _tracker.createInstance<NumericContext>(_ctx, parentState);
  propositionParser::NumericContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, propositionParser::RuleNumeric, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(200);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case propositionParser::LPAREN: {
        setState(182);
        match(propositionParser::LPAREN);
        setState(183);
        numeric(0);
        setState(184);
        match(propositionParser::RPAREN);
        break;
      }

      case propositionParser::NextOp: {
        setState(186);
        match(propositionParser::NextOp);
        setState(187);
        match(propositionParser::LCPAREN);
        setState(188);
        constant();
        setState(189);
        match(propositionParser::RCPAREN);
        setState(190);
        numeric(5);
        break;
      }

      case propositionParser::PastOp: {
        setState(192);
        match(propositionParser::PastOp);
        setState(193);
        match(propositionParser::LPAREN);
        setState(194);
        numeric(0);
        setState(195);
        match(propositionParser::T__0);
        setState(196);
        constant();
        setState(197);
        match(propositionParser::RPAREN);
        break;
      }

      case propositionParser::NUMERIC:
      case propositionParser::LT: {
        setState(199);
        numericAtom();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(210);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(208);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<NumericContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric);
          setState(202);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(203);
          dynamic_cast<NumericContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == propositionParser::TIMES

          || _la == propositionParser::DIV)) {
            dynamic_cast<NumericContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(204);
          numeric(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<NumericContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric);
          setState(205);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(206);
          dynamic_cast<NumericContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == propositionParser::PLUS

          || _la == propositionParser::MINUS)) {
            dynamic_cast<NumericContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(207);
          numeric(3);
          break;
        }

        } 
      }
      setState(212);
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

//----------------- NumericAtomContext ------------------------------------------------------------------

propositionParser::NumericAtomContext::NumericAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

propositionParser::NumericConstantContext* propositionParser::NumericAtomContext::numericConstant() {
  return getRuleContext<propositionParser::NumericConstantContext>(0);
}

propositionParser::NumericVariableContext* propositionParser::NumericAtomContext::numericVariable() {
  return getRuleContext<propositionParser::NumericVariableContext>(0);
}


size_t propositionParser::NumericAtomContext::getRuleIndex() const {
  return propositionParser::RuleNumericAtom;
}

void propositionParser::NumericAtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericAtom(this);
}

void propositionParser::NumericAtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericAtom(this);
}

propositionParser::NumericAtomContext* propositionParser::numericAtom() {
  NumericAtomContext *_localctx = _tracker.createInstance<NumericAtomContext>(_ctx, getState());
  enterRule(_localctx, 20, propositionParser::RuleNumericAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(215);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case propositionParser::NUMERIC: {
        enterOuterAlt(_localctx, 1);
        setState(213);
        numericConstant();
        break;
      }

      case propositionParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(214);
        numericVariable();
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

//----------------- NumericConstantContext ------------------------------------------------------------------

propositionParser::NumericConstantContext::NumericConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::NumericConstantContext::NUMERIC() {
  return getToken(propositionParser::NUMERIC, 0);
}


size_t propositionParser::NumericConstantContext::getRuleIndex() const {
  return propositionParser::RuleNumericConstant;
}

void propositionParser::NumericConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericConstant(this);
}

void propositionParser::NumericConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericConstant(this);
}

propositionParser::NumericConstantContext* propositionParser::numericConstant() {
  NumericConstantContext *_localctx = _tracker.createInstance<NumericConstantContext>(_ctx, getState());
  enterRule(_localctx, 22, propositionParser::RuleNumericConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    match(propositionParser::NUMERIC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericVariableContext ------------------------------------------------------------------

propositionParser::NumericVariableContext::NumericVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::NumericVariableContext::LT() {
  return getToken(propositionParser::LT, 0);
}

propositionParser::VariableContext* propositionParser::NumericVariableContext::variable() {
  return getRuleContext<propositionParser::VariableContext>(0);
}


size_t propositionParser::NumericVariableContext::getRuleIndex() const {
  return propositionParser::RuleNumericVariable;
}

void propositionParser::NumericVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericVariable(this);
}

void propositionParser::NumericVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericVariable(this);
}

propositionParser::NumericVariableContext* propositionParser::numericVariable() {
  NumericVariableContext *_localctx = _tracker.createInstance<NumericVariableContext>(_ctx, getState());
  enterRule(_localctx, 24, propositionParser::RuleNumericVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(219);
    match(propositionParser::LT);
    setState(220);
    variable();
    setState(221);
    match(propositionParser::T__4);
   
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

tree::TerminalNode* propositionParser::ConstantContext::BINARY() {
  return getToken(propositionParser::BINARY, 0);
}

tree::TerminalNode* propositionParser::ConstantContext::NUMERIC() {
  return getToken(propositionParser::NUMERIC, 0);
}

tree::TerminalNode* propositionParser::ConstantContext::BOOLEAN() {
  return getToken(propositionParser::BOOLEAN, 0);
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
  enterRule(_localctx, 26, propositionParser::RuleConstant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << propositionParser::NUMERIC)
      | (1ULL << propositionParser::BINARY)
      | (1ULL << propositionParser::BOOLEAN))) != 0))) {
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
  enterRule(_localctx, 28, propositionParser::RuleVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
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

propositionParser::ConstantContext* propositionParser::Upper_boundContext::constant() {
  return getRuleContext<propositionParser::ConstantContext>(0);
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
  enterRule(_localctx, 30, propositionParser::RuleUpper_bound);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    constant();
   
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

propositionParser::ConstantContext* propositionParser::Lower_boundContext::constant() {
  return getRuleContext<propositionParser::ConstantContext>(0);
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
  enterRule(_localctx, 32, propositionParser::RuleLower_bound);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    constant();
   
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
  enterRule(_localctx, 34, propositionParser::RuleRelop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(231);
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
    case 1: return booleanSempred(dynamic_cast<BooleanContext *>(context), predicateIndex);
    case 5: return logicSempred(dynamic_cast<LogicContext *>(context), predicateIndex);
    case 9: return numericSempred(dynamic_cast<NumericContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool propositionParser::booleanSempred(BooleanContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool propositionParser::logicSempred(LogicContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 6);
    case 5: return precpred(_ctx, 5);
    case 6: return precpred(_ctx, 4);
    case 7: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool propositionParser::numericSempred(NumericContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 3);
    case 9: return precpred(_ctx, 2);

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
  "file", "boolean", "booleanAtom", "booleanConstant", "booleanVariable", 
  "logic", "logicAtom", "logicConstant", "logicVariable", "numeric", "numericAtom", 
  "numericConstant", "numericVariable", "constant", "variable", "upper_bound", 
  "lower_bound", "relop"
};

std::vector<std::string> propositionParser::_literalNames = {
  "", "','", "',bool>'", "':'", "',logic>'", "',numeric>'", "'X'", "'$past'", 
  "'{'", "'}'", "'['", "']'", "'('", "')'", "", "", "", "", "'+'", "'-'", 
  "'*'", "'/'", "'>'", "'>='", "'<'", "'<='", "'=='", "'!='", "'&'", "'|'", 
  "'^'", "'~'", "'&&'", "'||'", "'!'"
};

std::vector<std::string> propositionParser::_symbolicNames = {
  "", "", "", "", "", "", "NextOp", "PastOp", "LGPAREN", "RGPAREN", "LCPAREN", 
  "RCPAREN", "LPAREN", "RPAREN", "VARIABLE", "NUMERIC", "BINARY", "BOOLEAN", 
  "PLUS", "MINUS", "TIMES", "DIV", "GT", "GE", "LT", "LE", "EQ", "NEQ", 
  "BAND", "BOR", "BXOR", "NEG", "AND", "OR", "NOT", "WS"
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
    0x3, 0x25, 0xec, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x58, 0xa, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x66, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x69, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x6d, 0xa, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x9b, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0xa9, 0xa, 0x7, 0xc, 0x7, 0xe, 
    0x7, 0xac, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xb0, 0xa, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xcb, 0xa, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xd3, 0xa, 
    0xb, 0xc, 0xb, 0xe, 0xb, 0xd6, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 
    0xda, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x2, 0x5, 0x4, 
    0xc, 0x14, 0x14, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x2, 0x6, 0x3, 0x2, 
    0x16, 0x17, 0x3, 0x2, 0x14, 0x15, 0x3, 0x2, 0x11, 0x13, 0x3, 0x2, 0x18, 
    0x1b, 0x2, 0xfb, 0x2, 0x26, 0x3, 0x2, 0x2, 0x2, 0x4, 0x57, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x8, 0x6e, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x70, 0x3, 0x2, 0x2, 0x2, 0xc, 0x9a, 0x3, 0x2, 0x2, 0x2, 0xe, 0xaf, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x12, 0xb3, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xca, 0x3, 0x2, 0x2, 0x2, 0x16, 0xd9, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xdd, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xe1, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xe3, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x22, 0xe7, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0xe9, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x5, 0x4, 0x3, 0x2, 0x27, 0x28, 
    0x7, 0x2, 0x2, 0x3, 0x28, 0x3, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x8, 
    0x3, 0x1, 0x2, 0x2a, 0x2b, 0x7, 0xe, 0x2, 0x2, 0x2b, 0x2c, 0x5, 0x4, 
    0x3, 0x2, 0x2c, 0x2d, 0x7, 0xf, 0x2, 0x2, 0x2d, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0x2f, 0x7, 0x8, 0x2, 0x2, 0x2f, 0x30, 0x7, 0xc, 0x2, 0x2, 
    0x30, 0x31, 0x5, 0x1c, 0xf, 0x2, 0x31, 0x32, 0x7, 0xd, 0x2, 0x2, 0x32, 
    0x33, 0x5, 0x4, 0x3, 0x11, 0x33, 0x58, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 
    0x7, 0x9, 0x2, 0x2, 0x35, 0x36, 0x7, 0xe, 0x2, 0x2, 0x36, 0x37, 0x5, 
    0x4, 0x3, 0x2, 0x37, 0x38, 0x7, 0x3, 0x2, 0x2, 0x38, 0x39, 0x5, 0x1c, 
    0xf, 0x2, 0x39, 0x3a, 0x7, 0xf, 0x2, 0x2, 0x3a, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x3b, 0x3c, 0x7, 0x24, 0x2, 0x2, 0x3c, 0x58, 0x5, 0x4, 0x3, 0xf, 
    0x3d, 0x3e, 0x5, 0xc, 0x7, 0x2, 0x3e, 0x3f, 0x5, 0x24, 0x13, 0x2, 0x3f, 
    0x40, 0x5, 0xc, 0x7, 0x2, 0x40, 0x58, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 
    0x5, 0x14, 0xb, 0x2, 0x42, 0x43, 0x5, 0x24, 0x13, 0x2, 0x43, 0x44, 0x5, 
    0x14, 0xb, 0x2, 0x44, 0x58, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x5, 0xc, 
    0x7, 0x2, 0x46, 0x47, 0x7, 0x1c, 0x2, 0x2, 0x47, 0x48, 0x5, 0xc, 0x7, 
    0x2, 0x48, 0x58, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x5, 0x14, 0xb, 0x2, 
    0x4a, 0x4b, 0x7, 0x1c, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0x14, 0xb, 0x2, 0x4c, 
    0x58, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0xc, 0x7, 0x2, 0x4e, 0x4f, 
    0x7, 0x1d, 0x2, 0x2, 0x4f, 0x50, 0x5, 0xc, 0x7, 0x2, 0x50, 0x58, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x52, 0x5, 0x14, 0xb, 0x2, 0x52, 0x53, 0x7, 0x1d, 
    0x2, 0x2, 0x53, 0x54, 0x5, 0x14, 0xb, 0x2, 0x54, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x55, 0x58, 0x5, 0x6, 0x4, 0x2, 0x56, 0x58, 0x5, 0xc, 0x7, 0x2, 
    0x57, 0x29, 0x3, 0x2, 0x2, 0x2, 0x57, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x57, 
    0x34, 0x3, 0x2, 0x2, 0x2, 0x57, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x57, 0x3d, 
    0x3, 0x2, 0x2, 0x2, 0x57, 0x41, 0x3, 0x2, 0x2, 0x2, 0x57, 0x45, 0x3, 
    0x2, 0x2, 0x2, 0x57, 0x49, 0x3, 0x2, 0x2, 0x2, 0x57, 0x4d, 0x3, 0x2, 
    0x2, 0x2, 0x57, 0x51, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x67, 0x3, 0x2, 0x2, 0x2, 
    0x59, 0x5a, 0xc, 0xc, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x1c, 0x2, 0x2, 0x5b, 
    0x66, 0x5, 0x4, 0x3, 0xd, 0x5c, 0x5d, 0xc, 0x9, 0x2, 0x2, 0x5d, 0x5e, 
    0x7, 0x1d, 0x2, 0x2, 0x5e, 0x66, 0x5, 0x4, 0x3, 0xa, 0x5f, 0x60, 0xc, 
    0x6, 0x2, 0x2, 0x60, 0x61, 0x7, 0x22, 0x2, 0x2, 0x61, 0x66, 0x5, 0x4, 
    0x3, 0x7, 0x62, 0x63, 0xc, 0x5, 0x2, 0x2, 0x63, 0x64, 0x7, 0x23, 0x2, 
    0x2, 0x64, 0x66, 0x5, 0x4, 0x3, 0x6, 0x65, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x65, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x65, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x65, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0x66, 0x69, 0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6d, 0x5, 0x8, 
    0x5, 0x2, 0x6b, 0x6d, 0x5, 0xa, 0x6, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x6f, 0x7, 0x13, 0x2, 0x2, 0x6f, 0x9, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x71, 0x7, 0x1a, 0x2, 0x2, 0x71, 0x72, 0x5, 0x1e, 0x10, 0x2, 0x72, 0x73, 
    0x7, 0x4, 0x2, 0x2, 0x73, 0xb, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x8, 
    0x7, 0x1, 0x2, 0x75, 0x76, 0x7, 0xe, 0x2, 0x2, 0x76, 0x77, 0x5, 0xc, 
    0x7, 0x2, 0x77, 0x78, 0x7, 0xf, 0x2, 0x2, 0x78, 0x9b, 0x3, 0x2, 0x2, 
    0x2, 0x79, 0x7a, 0x7, 0xa, 0x2, 0x2, 0x7a, 0x7b, 0x5, 0xc, 0x7, 0x2, 
    0x7b, 0x7c, 0x7, 0xb, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0xc, 0x2, 0x2, 0x7d, 
    0x7e, 0x5, 0x1c, 0xf, 0x2, 0x7e, 0x7f, 0x7, 0xd, 0x2, 0x2, 0x7f, 0x9b, 
    0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x7, 0xa, 0x2, 0x2, 0x81, 0x82, 0x5, 
    0xc, 0x7, 0x2, 0x82, 0x83, 0x7, 0xb, 0x2, 0x2, 0x83, 0x84, 0x7, 0xc, 
    0x2, 0x2, 0x84, 0x85, 0x5, 0x20, 0x11, 0x2, 0x85, 0x86, 0x7, 0x5, 0x2, 
    0x2, 0x86, 0x87, 0x5, 0x22, 0x12, 0x2, 0x87, 0x88, 0x7, 0xd, 0x2, 0x2, 
    0x88, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x8, 0x2, 0x2, 0x8a, 
    0x8b, 0x7, 0xc, 0x2, 0x2, 0x8b, 0x8c, 0x5, 0x1c, 0xf, 0x2, 0x8c, 0x8d, 
    0x7, 0xd, 0x2, 0x2, 0x8d, 0x8e, 0x5, 0xc, 0x7, 0xb, 0x8e, 0x9b, 0x3, 
    0x2, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x9, 0x2, 0x2, 0x90, 0x91, 0x7, 0xe, 
    0x2, 0x2, 0x91, 0x92, 0x5, 0xc, 0x7, 0x2, 0x92, 0x93, 0x7, 0x3, 0x2, 
    0x2, 0x93, 0x94, 0x5, 0x1c, 0xf, 0x2, 0x94, 0x95, 0x7, 0xf, 0x2, 0x2, 
    0x95, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x7, 0x21, 0x2, 0x2, 0x97, 
    0x9b, 0x5, 0xc, 0x7, 0x9, 0x98, 0x9b, 0x5, 0xe, 0x8, 0x2, 0x99, 0x9b, 
    0x5, 0x14, 0xb, 0x2, 0x9a, 0x74, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x79, 0x3, 
    0x2, 0x2, 0x2, 0x9a, 0x80, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x89, 0x3, 0x2, 
    0x2, 0x2, 0x9a, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x96, 0x3, 0x2, 0x2, 
    0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x99, 0x3, 0x2, 0x2, 0x2, 
    0x9b, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0xc, 0x8, 0x2, 0x2, 0x9d, 
    0x9e, 0x9, 0x2, 0x2, 0x2, 0x9e, 0xa9, 0x5, 0xc, 0x7, 0x9, 0x9f, 0xa0, 
    0xc, 0x7, 0x2, 0x2, 0xa0, 0xa1, 0x9, 0x3, 0x2, 0x2, 0xa1, 0xa9, 0x5, 
    0xc, 0x7, 0x8, 0xa2, 0xa3, 0xc, 0x6, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x1e, 
    0x2, 0x2, 0xa4, 0xa9, 0x5, 0xc, 0x7, 0x7, 0xa5, 0xa6, 0xc, 0x5, 0x2, 
    0x2, 0xa6, 0xa7, 0x7, 0x1f, 0x2, 0x2, 0xa7, 0xa9, 0x5, 0xc, 0x7, 0x6, 
    0xa8, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa8, 
    0xa2, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 
    0x2, 0x2, 0x2, 0xab, 0xd, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaa, 0x3, 0x2, 
    0x2, 0x2, 0xad, 0xb0, 0x5, 0x10, 0x9, 0x2, 0xae, 0xb0, 0x5, 0x12, 0xa, 
    0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0xb0, 0xf, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0x12, 0x2, 0x2, 0xb2, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x1a, 0x2, 0x2, 0xb4, 0xb5, 
    0x5, 0x1e, 0x10, 0x2, 0xb5, 0xb6, 0x7, 0x6, 0x2, 0x2, 0xb6, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0xb7, 0xb8, 0x8, 0xb, 0x1, 0x2, 0xb8, 0xb9, 0x7, 0xe, 
    0x2, 0x2, 0xb9, 0xba, 0x5, 0x14, 0xb, 0x2, 0xba, 0xbb, 0x7, 0xf, 0x2, 
    0x2, 0xbb, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x8, 0x2, 0x2, 
    0xbd, 0xbe, 0x7, 0xc, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x1c, 0xf, 0x2, 0xbf, 
    0xc0, 0x7, 0xd, 0x2, 0x2, 0xc0, 0xc1, 0x5, 0x14, 0xb, 0x7, 0xc1, 0xcb, 
    0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x7, 0x9, 0x2, 0x2, 0xc3, 0xc4, 0x7, 
    0xe, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0x14, 0xb, 0x2, 0xc5, 0xc6, 0x7, 0x3, 
    0x2, 0x2, 0xc6, 0xc7, 0x5, 0x1c, 0xf, 0x2, 0xc7, 0xc8, 0x7, 0xf, 0x2, 
    0x2, 0xc8, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcb, 0x5, 0x16, 0xc, 0x2, 
    0xca, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xca, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xca, 
    0xc2, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0xc, 0x5, 0x2, 0x2, 0xcd, 0xce, 0x9, 
    0x2, 0x2, 0x2, 0xce, 0xd3, 0x5, 0x14, 0xb, 0x6, 0xcf, 0xd0, 0xc, 0x4, 
    0x2, 0x2, 0xd0, 0xd1, 0x9, 0x3, 0x2, 0x2, 0xd1, 0xd3, 0x5, 0x14, 0xb, 
    0x5, 0xd2, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xcf, 0x3, 0x2, 0x2, 0x2, 
    0xd3, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd4, 
    0xd5, 0x3, 0x2, 0x2, 0x2, 0xd5, 0x15, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0xda, 0x5, 0x18, 0xd, 0x2, 0xd8, 0xda, 0x5, 
    0x1a, 0xe, 0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd8, 0x3, 0x2, 
    0x2, 0x2, 0xda, 0x17, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x7, 0x11, 0x2, 
    0x2, 0xdc, 0x19, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x1a, 0x2, 0x2, 
    0xde, 0xdf, 0x5, 0x1e, 0x10, 0x2, 0xdf, 0xe0, 0x7, 0x7, 0x2, 0x2, 0xe0, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x9, 0x4, 0x2, 0x2, 0xe2, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x7, 0x10, 0x2, 0x2, 0xe4, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0xe5, 0xe6, 0x5, 0x1c, 0xf, 0x2, 0xe6, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0xe7, 0xe8, 0x5, 0x1c, 0xf, 0x2, 0xe8, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0xe9, 0xea, 0x9, 0x5, 0x2, 0x2, 0xea, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x57, 0x65, 0x67, 0x6c, 0x9a, 0xa8, 0xaa, 0xaf, 0xca, 0xd2, 0xd4, 
    0xd9, 
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
