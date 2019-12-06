
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

  virtual void enterExpression(propositionParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(propositionParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterNumeric_logic(propositionParser::Numeric_logicContext * /*ctx*/) override { }
  virtual void exitNumeric_logic(propositionParser::Numeric_logicContext * /*ctx*/) override { }

  virtual void enterLogic(propositionParser::LogicContext * /*ctx*/) override { }
  virtual void exitLogic(propositionParser::LogicContext * /*ctx*/) override { }

  virtual void enterAtom(propositionParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(propositionParser::AtomContext * /*ctx*/) override { }

  virtual void enterConstant(propositionParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(propositionParser::ConstantContext * /*ctx*/) override { }

  virtual void enterVariable(propositionParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(propositionParser::VariableContext * /*ctx*/) override { }

  virtual void enterRelop(propositionParser::RelopContext * /*ctx*/) override { }
  virtual void exitRelop(propositionParser::RelopContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

