
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
    setState(16);
    expression(0);
    setState(17);
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

tree::TerminalNode* propositionParser::ExpressionContext::NextOp() {
  return getToken(propositionParser::NextOp, 0);
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
    setState(44);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(20);
      match(propositionParser::LPAREN);
      setState(21);
      expression(0);
      setState(22);
      match(propositionParser::RPAREN);
      break;
    }

    case 2: {
      setState(24);
      match(propositionParser::NextOp);
      setState(25);
      match(propositionParser::LCPAREN);
      setState(26);
      match(propositionParser::CONSTANT);
      setState(27);
      match(propositionParser::RCPAREN);
      setState(28);
      expression(10);
      break;
    }

    case 3: {
      setState(29);
      match(propositionParser::PastOp);
      setState(30);
      match(propositionParser::LPAREN);
      setState(31);
      expression(0);
      setState(32);
      match(propositionParser::T__0);
      setState(33);
      match(propositionParser::CONSTANT);
      setState(34);
      match(propositionParser::RPAREN);
      break;
    }

    case 4: {
      setState(36);
      match(propositionParser::NOT);
      setState(37);
      expression(8);
      break;
    }

    case 5: {
      setState(38);
      numeric_logic(0);
      setState(39);
      relop();
      setState(40);
      numeric_logic(0);
      break;
    }

    case 6: {
      setState(42);
      numeric_logic(0);
      break;
    }

    case 7: {
      setState(43);
      atom();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(60);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(58);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(46);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(47);
          match(propositionParser::EQ);
          setState(48);
          expression(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(49);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(50);
          match(propositionParser::NEQ);
          setState(51);
          expression(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(52);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(53);
          dynamic_cast<ExpressionContext *>(_localctx)->boolop = match(propositionParser::AND);
          setState(54);
          expression(5);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(55);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(56);
          dynamic_cast<ExpressionContext *>(_localctx)->boolop = match(propositionParser::OR);
          setState(57);
          expression(4);
          break;
        }

        } 
      }
      setState(62);
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
    setState(82);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(64);
      match(propositionParser::LPAREN);
      setState(65);
      numeric_logic(0);
      setState(66);
      match(propositionParser::RPAREN);
      break;
    }

    case 2: {
      setState(68);
      match(propositionParser::NextOp);
      setState(69);
      match(propositionParser::LCPAREN);
      setState(70);
      match(propositionParser::CONSTANT);
      setState(71);
      match(propositionParser::RCPAREN);
      setState(72);
      numeric_logic(6);
      break;
    }

    case 3: {
      setState(73);
      match(propositionParser::PastOp);
      setState(74);
      match(propositionParser::LPAREN);
      setState(75);
      numeric_logic(0);
      setState(76);
      match(propositionParser::T__0);
      setState(77);
      match(propositionParser::CONSTANT);
      setState(78);
      match(propositionParser::RPAREN);
      break;
    }

    case 4: {
      setState(80);
      atom();
      break;
    }

    case 5: {
      setState(81);
      logic(0);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(92);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(90);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Numeric_logicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric_logic);
          setState(84);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(85);
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
          setState(86);
          numeric_logic(3);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Numeric_logicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric_logic);
          setState(87);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(88);
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
          setState(89);
          numeric_logic(2);
          break;
        }

        } 
      }
      setState(94);
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
    setState(103);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case propositionParser::LPAREN: {
        setState(96);
        match(propositionParser::LPAREN);
        setState(97);
        logic(0);
        setState(98);
        match(propositionParser::RPAREN);
        break;
      }

      case propositionParser::VARIABLE:
      case propositionParser::CONSTANT: {
        setState(100);
        atom();
        break;
      }

      case propositionParser::NEG: {
        setState(101);
        match(propositionParser::NEG);
        setState(102);
        logic(3);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(113);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(111);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(105);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(106);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(propositionParser::BAND);
          setState(107);
          logic(3);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(108);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(109);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(propositionParser::BOR);
          setState(110);
          logic(2);
          break;
        }

        } 
      }
      setState(115);
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
    setState(118);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case propositionParser::CONSTANT: {
        enterOuterAlt(_localctx, 1);
        setState(116);
        constant();
        break;
      }

      case propositionParser::VARIABLE: {
        enterOuterAlt(_localctx, 2);
        setState(117);
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
    setState(120);
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
    setState(122);
    match(propositionParser::VARIABLE);
   
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
  enterRule(_localctx, 14, propositionParser::RuleRelop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
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
  "relop"
};

std::vector<std::string> propositionParser::_literalNames = {
  "", "','", "'X'", "'$past'", "'['", "']'", "'('", "')'", "", "", "'+'", 
  "'-'", "'*'", "'/'", "'>'", "'>='", "'<'", "'<='", "'=='", "'!='", "'&'", 
  "'|'", "'^'", "'~'", "'&&'", "'||'", "'!'"
};

std::vector<std::string> propositionParser::_symbolicNames = {
  "", "", "NextOp", "PastOp", "LCPAREN", "RCPAREN", "LPAREN", "RPAREN", 
  "VARIABLE", "CONSTANT", "PLUS", "MINUS", "TIMES", "DIV", "GT", "GE", "LT", 
  "LE", "EQ", "NEQ", "BAND", "BOR", "BXOR", "NEG", "AND", "OR", "NOT", "WS"
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
    0x3, 0x1d, 0x81, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2f, 0xa, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x3d, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x40, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x55, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x5d, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 
    0x60, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x6a, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x72, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0x75, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x79, 0xa, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x2, 0x5, 0x4, 0x6, 0x8, 0xa, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x2, 0x5, 0x3, 0x2, 0xe, 0xf, 0x3, 0x2, 0xc, 0xd, 0x3, 0x2, 0x10, 
    0x13, 0x2, 0x8d, 0x2, 0x12, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x54, 0x3, 0x2, 0x2, 0x2, 0x8, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x78, 0x3, 0x2, 0x2, 0x2, 0xc, 0x7a, 0x3, 0x2, 0x2, 0x2, 0xe, 0x7c, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x12, 0x13, 0x5, 
    0x4, 0x3, 0x2, 0x13, 0x14, 0x7, 0x2, 0x2, 0x3, 0x14, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x15, 0x16, 0x8, 0x3, 0x1, 0x2, 0x16, 0x17, 0x7, 0x8, 0x2, 
    0x2, 0x17, 0x18, 0x5, 0x4, 0x3, 0x2, 0x18, 0x19, 0x7, 0x9, 0x2, 0x2, 
    0x19, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x7, 0x4, 0x2, 0x2, 0x1b, 
    0x1c, 0x7, 0x6, 0x2, 0x2, 0x1c, 0x1d, 0x7, 0xb, 0x2, 0x2, 0x1d, 0x1e, 
    0x7, 0x7, 0x2, 0x2, 0x1e, 0x2f, 0x5, 0x4, 0x3, 0xc, 0x1f, 0x20, 0x7, 
    0x5, 0x2, 0x2, 0x20, 0x21, 0x7, 0x8, 0x2, 0x2, 0x21, 0x22, 0x5, 0x4, 
    0x3, 0x2, 0x22, 0x23, 0x7, 0x3, 0x2, 0x2, 0x23, 0x24, 0x7, 0xb, 0x2, 
    0x2, 0x24, 0x25, 0x7, 0x9, 0x2, 0x2, 0x25, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x27, 0x7, 0x1c, 0x2, 0x2, 0x27, 0x2f, 0x5, 0x4, 0x3, 0xa, 0x28, 
    0x29, 0x5, 0x6, 0x4, 0x2, 0x29, 0x2a, 0x5, 0x10, 0x9, 0x2, 0x2a, 0x2b, 
    0x5, 0x6, 0x4, 0x2, 0x2b, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2f, 0x5, 
    0x6, 0x4, 0x2, 0x2d, 0x2f, 0x5, 0xa, 0x6, 0x2, 0x2e, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x2e, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0x26, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x28, 0x3, 0x2, 0x2, 0x2, 
    0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 
    0x3e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0xc, 0x8, 0x2, 0x2, 0x31, 0x32, 
    0x7, 0x14, 0x2, 0x2, 0x32, 0x3d, 0x5, 0x4, 0x3, 0x9, 0x33, 0x34, 0xc, 
    0x7, 0x2, 0x2, 0x34, 0x35, 0x7, 0x15, 0x2, 0x2, 0x35, 0x3d, 0x5, 0x4, 
    0x3, 0x8, 0x36, 0x37, 0xc, 0x6, 0x2, 0x2, 0x37, 0x38, 0x7, 0x1a, 0x2, 
    0x2, 0x38, 0x3d, 0x5, 0x4, 0x3, 0x7, 0x39, 0x3a, 0xc, 0x5, 0x2, 0x2, 
    0x3a, 0x3b, 0x7, 0x1b, 0x2, 0x2, 0x3b, 0x3d, 0x5, 0x4, 0x3, 0x6, 0x3c, 
    0x30, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x33, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x40, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x3f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 
    0x2, 0x41, 0x42, 0x8, 0x4, 0x1, 0x2, 0x42, 0x43, 0x7, 0x8, 0x2, 0x2, 
    0x43, 0x44, 0x5, 0x6, 0x4, 0x2, 0x44, 0x45, 0x7, 0x9, 0x2, 0x2, 0x45, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x7, 0x4, 0x2, 0x2, 0x47, 0x48, 
    0x7, 0x6, 0x2, 0x2, 0x48, 0x49, 0x7, 0xb, 0x2, 0x2, 0x49, 0x4a, 0x7, 
    0x7, 0x2, 0x2, 0x4a, 0x55, 0x5, 0x6, 0x4, 0x8, 0x4b, 0x4c, 0x7, 0x5, 
    0x2, 0x2, 0x4c, 0x4d, 0x7, 0x8, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0x6, 0x4, 
    0x2, 0x4e, 0x4f, 0x7, 0x3, 0x2, 0x2, 0x4f, 0x50, 0x7, 0xb, 0x2, 0x2, 
    0x50, 0x51, 0x7, 0x9, 0x2, 0x2, 0x51, 0x55, 0x3, 0x2, 0x2, 0x2, 0x52, 
    0x55, 0x5, 0xa, 0x6, 0x2, 0x53, 0x55, 0x5, 0x8, 0x5, 0x2, 0x54, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0x54, 0x46, 0x3, 0x2, 0x2, 0x2, 0x54, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 0x54, 0x53, 0x3, 0x2, 
    0x2, 0x2, 0x55, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0xc, 0x4, 0x2, 
    0x2, 0x57, 0x58, 0x9, 0x2, 0x2, 0x2, 0x58, 0x5d, 0x5, 0x6, 0x4, 0x5, 
    0x59, 0x5a, 0xc, 0x3, 0x2, 0x2, 0x5a, 0x5b, 0x9, 0x3, 0x2, 0x2, 0x5b, 
    0x5d, 0x5, 0x6, 0x4, 0x4, 0x5c, 0x56, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x59, 
    0x3, 0x2, 0x2, 0x2, 0x5d, 0x60, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5c, 0x3, 
    0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x8, 0x5, 0x1, 
    0x2, 0x62, 0x63, 0x7, 0x8, 0x2, 0x2, 0x63, 0x64, 0x5, 0x8, 0x5, 0x2, 
    0x64, 0x65, 0x7, 0x9, 0x2, 0x2, 0x65, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x66, 
    0x6a, 0x5, 0xa, 0x6, 0x2, 0x67, 0x68, 0x7, 0x19, 0x2, 0x2, 0x68, 0x6a, 
    0x5, 0x8, 0x5, 0x5, 0x69, 0x61, 0x3, 0x2, 0x2, 0x2, 0x69, 0x66, 0x3, 
    0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x73, 0x3, 0x2, 
    0x2, 0x2, 0x6b, 0x6c, 0xc, 0x4, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x16, 0x2, 
    0x2, 0x6d, 0x72, 0x5, 0x8, 0x5, 0x5, 0x6e, 0x6f, 0xc, 0x3, 0x2, 0x2, 
    0x6f, 0x70, 0x7, 0x17, 0x2, 0x2, 0x70, 0x72, 0x5, 0x8, 0x5, 0x4, 0x71, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x72, 0x75, 
    0x3, 0x2, 0x2, 0x2, 0x73, 0x71, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 
    0x2, 0x2, 0x2, 0x74, 0x9, 0x3, 0x2, 0x2, 0x2, 0x75, 0x73, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x79, 0x5, 0xc, 0x7, 0x2, 0x77, 0x79, 0x5, 0xe, 0x8, 
    0x2, 0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x77, 0x3, 0x2, 0x2, 0x2, 
    0x79, 0xb, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0xb, 0x2, 0x2, 0x7b, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0xa, 0x2, 0x2, 0x7d, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x9, 0x4, 0x2, 0x2, 0x7f, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0xc, 0x2e, 0x3c, 0x3e, 0x54, 0x5c, 0x5e, 0x69, 0x71, 
    0x73, 0x78, 
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
