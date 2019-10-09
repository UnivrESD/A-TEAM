
// Generated from ../assertionminer/antlr4_grammar/proposition.gr by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "propositionListener.h"


/**
 * This class provides an empty implementation of propositionListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  propositionBaseListener : public propositionListener {
public:

  virtual void enterFile(propositionParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(propositionParser::FileContext * /*ctx*/) override { }

  virtual void enterProposition(propositionParser::PropositionContext * /*ctx*/) override { }
  virtual void exitProposition(propositionParser::PropositionContext * /*ctx*/) override { }

  virtual void enterAtomicProp(propositionParser::AtomicPropContext * /*ctx*/) override { }
  virtual void exitAtomicProp(propositionParser::AtomicPropContext * /*ctx*/) override { }

  virtual void enterNumericExpression(propositionParser::NumericExpressionContext * /*ctx*/) override { }
  virtual void exitNumericExpression(propositionParser::NumericExpressionContext * /*ctx*/) override { }

  virtual void enterBooleanExpression(propositionParser::BooleanExpressionContext * /*ctx*/) override { }
  virtual void exitBooleanExpression(propositionParser::BooleanExpressionContext * /*ctx*/) override { }

  virtual void enterHandleNot(propositionParser::HandleNotContext * /*ctx*/) override { }
  virtual void exitHandleNot(propositionParser::HandleNotContext * /*ctx*/) override { }

  virtual void enterHandleNeg(propositionParser::HandleNegContext * /*ctx*/) override { }
  virtual void exitHandleNeg(propositionParser::HandleNegContext * /*ctx*/) override { }

  virtual void enterLogicExpression(propositionParser::LogicExpressionContext * /*ctx*/) override { }
  virtual void exitLogicExpression(propositionParser::LogicExpressionContext * /*ctx*/) override { }

  virtual void enterAtom(propositionParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(propositionParser::AtomContext * /*ctx*/) override { }

  virtual void enterConstant(propositionParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(propositionParser::ConstantContext * /*ctx*/) override { }

  virtual void enterVariable(propositionParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(propositionParser::VariableContext * /*ctx*/) override { }

  virtual void enterArtop(propositionParser::ArtopContext * /*ctx*/) override { }
  virtual void exitArtop(propositionParser::ArtopContext * /*ctx*/) override { }

  virtual void enterLrelop(propositionParser::LrelopContext * /*ctx*/) override { }
  virtual void exitLrelop(propositionParser::LrelopContext * /*ctx*/) override { }

  virtual void enterRelop(propositionParser::RelopContext * /*ctx*/) override { }
  virtual void exitRelop(propositionParser::RelopContext * /*ctx*/) override { }

  virtual void enterLogop(propositionParser::LogopContext * /*ctx*/) override { }
  virtual void exitLogop(propositionParser::LogopContext * /*ctx*/) override { }

  virtual void enterBoolop(propositionParser::BoolopContext * /*ctx*/) override { }
  virtual void exitBoolop(propositionParser::BoolopContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

