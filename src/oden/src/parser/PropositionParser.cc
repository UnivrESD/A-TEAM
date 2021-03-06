
#include "oden/parser/PropositionParser.hh"
#include "oden/odenUtils/odenUtils.hh"

#include "oden/classes/atom/Constant.hh"
#include "oden/classes/atom/Variable.hh"
#include "oden/classes/expression/BitSelector.hh"
#include "oden/classes/expression/Expression.hh"
#include "oden/classes/expression/TypeCast.hh"
#include "oden/classes/temporal/NextOperator.hh"
#include "oden/classes/temporal/PastOperator.hh"
#include <cassert>

#define CHECK_ABORT                                                            \
  if (_abort)                                                                  \
    return;

namespace oden {

PropositionParser::PropositionParser(const Name2Variable &varName2varDec,
                                     Trace &trace)
  : _varName2varDec(varName2varDec), _trace(trace), _abort(false), _type(),
    _proposition(), _logicExpressions(), _numericExpressions() {}

void PropositionParser::enterFile(propositionParser::FileContext *ctx) {
  _abort = false;
  _type.setType(VariableType::unknown);

  while (!_proposition.empty()) {
    delete _proposition.top();
    _proposition.pop();
  }

  while (!_numericExpressions.empty()) {
    delete _numericExpressions.top();
    _numericExpressions.pop();
  }

  while (!_logicExpressions.empty()) {
    delete _logicExpressions.top();
    _logicExpressions.pop();
  }
}

void PropositionParser::exitFile(propositionParser::FileContext *ctx) {
  // //std::cout << "IT WORKS!" << std::endl;
}

void PropositionParser::enterBooleanConstant(
  propositionParser::BooleanConstantContext *ctx) {

  antlr4::tree::TerminalNode *con = ctx->BOOLEAN();
  std::string conStr = std::string(con->getText());

  if (conStr == "<false,bool>") {
    auto *c = new BooleanConstant(false, INT_MAX);
    _proposition.push(c);
    return;
  } else if (conStr == "<true,bool>") {
    auto *c = new BooleanConstant(true, INT_MAX);
    _proposition.push(c);
    return;
  }
}
void PropositionParser::enterLogicConstant(
  propositionParser::LogicConstantContext *ctx) {

  std::string conStr = std::string(ctx->getText());

  if (ctx->BINARY() != nullptr) {
    Logic value = oden::string2Logic(conStr.substr(2, conStr.size() - 2));
    auto *c = new LogicConstant(value, INT_MAX);
    _logicExpressions.push(c);
    return;
  }
  messageError("Unknown logic constant!");
}
void PropositionParser::enterNumericConstant(propositionParser::NumericConstantContext *ctx) {
  if (ctx->NUMERIC() != nullptr) {
    Numeric value = std::stof(ctx->getText());
    auto *c = new NumericConstant(value, INT_MAX);
    _numericExpressions.push(c);
    return;
  }
}

void PropositionParser::enterBooleanVariable(
  propositionParser::BooleanVariableContext *ctx) {

  propositionParser::VariableContext *tNode = ctx->variable();
  std::string varName = std::string(tNode->getText());
  // //std::cout << __func__ << ": " << varName << std::endl;

  auto found = _varName2varDec.find(varName);
  messageErrorIf(found == _varName2varDec.end(),
                 "Unknown variable name: " + varName);

  Proposition *n = _trace.getBooleanVariable(varName);

  _proposition.push(n);
}
void PropositionParser::enterLogicVariable(
  propositionParser::LogicVariableContext *ctx) {
  propositionParser::VariableContext *tNode = ctx->variable();
  std::string varName = std::string(tNode->getText());
  // //std::cout << __func__ << ": " << varName << std::endl;

  auto found = _varName2varDec.find(varName);
  messageErrorIf(found == _varName2varDec.end(),
                 "Unknown variable name: " + varName);

  LogicExpression *n = _trace.getLogicVariable(varName);

  _logicExpressions.push(n);
}
void PropositionParser::enterNumericVariable(
  propositionParser::NumericVariableContext *ctx) {

  propositionParser::VariableContext *tNode = ctx->variable();
  std::string varName = std::string(tNode->getText());
  // //std::cout << __func__ << ": " << varName << std::endl;

  auto found = _varName2varDec.find(varName);
  messageErrorIf(found == _varName2varDec.end(),
                 "Unknown variable name: " + varName);

  NumericExpression *n = _trace.getNumericVariable(varName);
  _numericExpressions.push(n);
}
void PropositionParser::exitBoolean(propositionParser::BooleanContext *ctx) {

  if (ctx->LPAREN() && ctx->RPAREN() && ctx->PastOp() == nullptr &&  ctx->NextOp() == nullptr) {
    return;
  }

  if (ctx->boolean().size() == 1) {
    if (ctx->NOT()) {
      // std::cout<<__func__<<"!"<<std::endl;
      Proposition *p = _proposition.top();
      _proposition.pop();
      _proposition.push(makeExpression<PropositionNot>(p));
      return;
    }

    // next operator
    if (ctx->NextOp() != nullptr && ctx->LPAREN() != nullptr &&
        ctx->RPAREN() != nullptr) {
      // std::cout<<__func__<<"X"<<std::endl;
      Proposition *p = _proposition.top();
      _proposition.pop();
      size_t offset =
        static_cast<size_t>(std::stoi(ctx->constant()->getText()));
      _proposition.push(new PropositionNext(p, offset));
      return;
    }

    // past operator
    if (ctx->PastOp() != nullptr && ctx->LPAREN() != nullptr &&
        ctx->RPAREN() != nullptr) {
      // std::cout<<__func__<<"$past"<<std::endl;
      Proposition *p = _proposition.top();
      _proposition.pop();
      size_t offset =
        static_cast<size_t>(std::stoi(ctx->constant()->getText()));
      _proposition.push(new PropositionPast(p, offset));
      return;
    }

    messageError("Unknown unary boolean operator!");
  } else if (ctx->boolean().size() == 2) {
    antlr4::Token *boolop = ctx->booleanop;
    if (boolop != nullptr) {
      // std::cout<<__func__<<"boolop"<<std::endl;
      Proposition *p2 = _proposition.top();
      _proposition.pop();
      Proposition *p1 = _proposition.top();
      _proposition.pop();
      if (boolop->getText() == "&&") {
        _proposition.push(makeExpression<PropositionAnd>(p1, p2));
        return;
      } else if (boolop->getText() == "||") {
        _proposition.push(makeExpression<PropositionOr>(p1, p2));
        return;
      }
      messageError("Unknown boolean operator in expression!");
    }
    if (ctx->EQ() != nullptr) {
      // std::cout<<__func__<<"="<<std::endl;
      Proposition *p2 = _proposition.top();
      _proposition.pop();
      Proposition *p1 = _proposition.top();
      _proposition.pop();
      _proposition.push(makeExpression<PropositionEq>(p1, p2));
      return;
    }
    if (ctx->NEQ() != nullptr) {
      // std::cout<<__func__<<"!="<<std::endl;
      Proposition *p2 = _proposition.top();
      _proposition.pop();
      Proposition *p1 = _proposition.top();
      _proposition.pop();
      _proposition.push(makeExpression<PropositionNeq>(p1, p2));
      return;
    }
    messageError("Unknown binary boolean operator!");
  }

  if (ctx->logic().size() == 1) {
    // Try cast to Boolean
    // std::cout<<__func__<<"cast"<<std::endl;
    messageWarning("Implicit typecast to Bool!");
    LogicExpression *le2 = _logicExpressions.top();
    _logicExpressions.pop();
    _proposition.push(new LogicToBool(le2));
    return;
    messageError("Unknown unary logic operator in boolean expression!");
  } else if (ctx->logic().size() == 2) {
    propositionParser::RelopContext *relop = ctx->relop();
    if (relop != nullptr) {
      // std::cout<<__func__<<"relop"<<std::endl;
      LogicExpression *le2 = _logicExpressions.top();
      _logicExpressions.pop();

      LogicExpression *le1 = _logicExpressions.top();
      _logicExpressions.pop();

      if (relop->LT() != nullptr) {
        _proposition.push(makeExpression<LogicLess>(le1, le2));
        return;
      }
      if (relop->LE() != nullptr) {
        _proposition.push(makeExpression<LogicLessEq>(le1, le2));
        return;
      }
      if (relop->GT() != nullptr) {
        _proposition.push(makeExpression<LogicGreater>(le1, le2));
        return;
      }
      if (relop->GE() != nullptr) {
        _proposition.push(makeExpression<LogicGreaterEq>(le1, le2));
        return;
      }
      messageError("Unknown relational operator!");
    }
    if (ctx->EQ() != nullptr) {
      // std::cout<<__func__<<"="<<std::endl;
      LogicExpression *le2 = _logicExpressions.top();
      _logicExpressions.pop();
      LogicExpression *le1 = _logicExpressions.top();
      _logicExpressions.pop();
      _proposition.push(makeExpression<LogicEq>(le1, le2));
      return;
    }
    if (ctx->NEQ() != nullptr) {
      // std::cout<<__func__<<"!="<<std::endl;
      LogicExpression *le2 = _logicExpressions.top();
      _logicExpressions.pop();
      LogicExpression *le1 = _logicExpressions.top();
      _logicExpressions.pop();
      _proposition.push(makeExpression<LogicNeq>(le1, le2));
      return;
    }
    messageError("Unknown binary logic operator!");
  }

  if (ctx->numeric().size() == 2) {
    propositionParser::RelopContext *relop = ctx->relop();
    if (relop != nullptr) {
      // std::cout<<__func__<<"relop"<<std::endl;
      NumericExpression *ne2 = _numericExpressions.top();
      _numericExpressions.pop();

      NumericExpression *ne1 = _numericExpressions.top();
      _numericExpressions.pop();

      if (relop->LT() != nullptr) {
        _proposition.push(makeExpression<NumericLess>(ne1, ne2));
        return;
      }
      if (relop->LE() != nullptr) {
        _proposition.push(makeExpression<NumericLessEq>(ne1, ne2));
        return;
      }
      if (relop->GT() != nullptr) {
        _proposition.push(makeExpression<NumericGreater>(ne1, ne2));
        return;
      }
      if (relop->GE() != nullptr) {
        _proposition.push(makeExpression<NumericGreaterEq>(ne1, ne2));
        return;
      }
      messageError("Unknown relational operator!");
    }
    if (ctx->EQ() != nullptr) {
      // std::cout<<__func__<<"="<<std::endl;
      NumericExpression *le2 = _numericExpressions.top();
      _numericExpressions.pop();
      NumericExpression *le1 = _numericExpressions.top();
      _numericExpressions.pop();
      _proposition.push(makeExpression<NumericEq>(le1, le2));
      return;
    }
    if (ctx->NEQ() != nullptr) {
      // std::cout<<__func__<<"!="<<std::endl;
      NumericExpression *le2 = _numericExpressions.top();
      _numericExpressions.pop();
      NumericExpression *le1 = _numericExpressions.top();
      _numericExpressions.pop();
      _proposition.push(makeExpression<NumericNeq>(le1, le2));
      return;
    }
    messageError("Unknown binary numeric operator!");
  }
}
void PropositionParser::exitLogic(propositionParser::LogicContext *ctx) {
  // std::cout<<__func__<<std::endl;

  if (ctx->LPAREN() && ctx->RPAREN() && ctx->PastOp() == nullptr && ctx->NextOp() == nullptr) {
    return;
  }

  if (ctx->logic().size() == 1) {
    // single bit selection to logic
    if (ctx->LGPAREN() != nullptr && ctx->RGPAREN() != nullptr &&
        ctx->RCPAREN() != nullptr && ctx->LCPAREN() != nullptr &&
        ctx->constant() != nullptr) {
      propositionParser::ConstantContext *con = ctx->constant();
      std::string conStr = std::string(con->getText());
      size_t index = 999;

      if (conStr.substr(0, 2) == "'b") {
        Logic value = oden::string2Logic(conStr.substr(2, conStr.size() - 2));
        index = value.getValue();
      } else {
        Numeric value = oden::string2Numeric(conStr);
        index = value;
      }
      LogicExpression *le = _logicExpressions.top();
      _logicExpressions.pop();
      _logicExpressions.push(new LogicBitSelector(le, index, index));
      return;
    }

    // multiple bit selection to logic
    if (ctx->LGPAREN() != nullptr && ctx->RGPAREN() != nullptr &&
        ctx->RCPAREN() != nullptr && ctx->LCPAREN() != nullptr &&
        ctx->upper_bound() != nullptr && ctx->lower_bound() != nullptr) {
      propositionParser::ConstantContext *con1 = ctx->upper_bound()->constant();
      propositionParser::ConstantContext *con2 = ctx->lower_bound()->constant();
      std::string conStr1 = std::string(con1->getText());
      std::string conStr2 = std::string(con2->getText());
      size_t upper_index = 999;
      size_t lower_index = 999;

      if (conStr1.size() > 2 && conStr1.substr(0, 2) == "'b") {
        Logic value = oden::string2Logic(conStr1.substr(2, conStr1.size() - 2));
        upper_index = value.getValue();
      } else {
        Numeric value = oden::string2Numeric(conStr1);
        upper_index = value;
      }

      if (conStr2.size() > 2 && conStr2.substr(0, 2) == "'b") {
        Logic value = oden::string2Logic(conStr2.substr(2, conStr2.size() - 2));
        lower_index = value.getValue();
      } else {
        Numeric value = oden::string2Numeric(conStr2);
        lower_index = value;
      }

      LogicExpression *le = _logicExpressions.top();
      _logicExpressions.pop();
      _logicExpressions.push(
        new LogicBitSelector(le, upper_index, lower_index));
      return;
    }

    if (ctx->NEG() != nullptr) {
      LogicExpression *l = _logicExpressions.top();
      _logicExpressions.pop();
      _logicExpressions.push(makeExpression<LogicNot>(l));
      return;
    }

    // next operator
    if (ctx->NextOp() != nullptr && ctx->LPAREN() != nullptr &&
        ctx->RPAREN() != nullptr) {
      LogicExpression *le = _logicExpressions.top();
      _logicExpressions.pop();
      size_t offset =
        static_cast<size_t>(std::stoi(ctx->constant()->getText()));
      _logicExpressions.push(new LogicNext(le, offset));
      return;
    }

    // past operator
    if (ctx->PastOp() != nullptr && ctx->LPAREN() != nullptr &&
        ctx->RPAREN() != nullptr) {
      LogicExpression *le = _logicExpressions.top();
      _logicExpressions.pop();
      size_t offset =
        static_cast<size_t>(std::stoi(ctx->constant()->getText()));
      _logicExpressions.push(new LogicPast(le, offset));
      return;
    }

    messageError("Unknown unary logic operator in logic expression!");

  } else if (ctx->logic().size() == 2) {

    antlr4::Token *logop = ctx->logop;

    if (logop != nullptr) {
      LogicExpression *le2 = _logicExpressions.top();
      _logicExpressions.pop();

      LogicExpression *le1 = _logicExpressions.top();
      _logicExpressions.pop();

      if (logop->getText() == "&") {
        _logicExpressions.push(makeExpression<LogicBAnd>(le1, le2));
        return;
      }
      if (logop->getText() == "|") {
        _logicExpressions.push(makeExpression<LogicBOr>(le1, le2));
        return;
      }

      messageError("Unknown binary logic operator in logic expression!");
    }

    antlr4::Token *artop = ctx->artop;

    if (artop != nullptr) {
      LogicExpression *le2 = _logicExpressions.top();
      _logicExpressions.pop();

      LogicExpression *le1 = _logicExpressions.top();
      _logicExpressions.pop();

      if (artop->getText() == "*") {
        _logicExpressions.push(makeExpression<LogicMul>(le1, le2));
        return;
      }
      if (artop->getText() == "/") {
        _logicExpressions.push(makeExpression<LogicDiv>(le1, le2));
        return;
      }
      if (artop->getText() == "-") {
        _logicExpressions.push(makeExpression<LogicSub>(le1, le2));
        return;
      }
      if (artop->getText() == "+") {
        _logicExpressions.push(makeExpression<LogicSum>(le1, le2));
        return;
      }
      messageError("Unknown binary arithmetic operator in logic expression!");
    }
  }

  if (ctx->numeric() != nullptr) {
    // Try cast to Logic
    messageWarning("Implicit typecast to Logic!");
    NumericExpression *ne2 = _numericExpressions.top();
    _numericExpressions.pop();
    _logicExpressions.push(new NumericToLogic(ne2));
    return;
  }
}
void PropositionParser::exitNumeric(propositionParser::NumericContext *ctx) {
  // std::cout<<__func__<<std::endl;

  if (ctx->LPAREN() && ctx->RPAREN() && ctx->PastOp() == nullptr && ctx->NextOp() == nullptr) {
    return;
  }

  if (ctx->numeric().size() == 1) {
    // next operator
    if (ctx->NextOp() != nullptr && ctx->LPAREN() != nullptr &&
        ctx->RPAREN() != nullptr) {
      NumericExpression *ne = _numericExpressions.top();
      _numericExpressions.pop();
      size_t offset =
        static_cast<size_t>(std::stoi(ctx->constant()->getText()));
      _numericExpressions.push(new NumericNext(ne, offset));
      return;
    }

    // past operator
    if (ctx->PastOp() != nullptr && ctx->LPAREN() != nullptr &&
        ctx->RPAREN() != nullptr) {
      NumericExpression *ne = _numericExpressions.top();
      _numericExpressions.pop();
      size_t offset =
        static_cast<size_t>(std::stoi(ctx->constant()->getText()));
      _numericExpressions.push(new NumericPast(ne, offset));
      return;
    }
    messageError("Unknown unary numeric operator in logic expression!");

  } else if (ctx->numeric().size() == 2) {

    antlr4::Token *artop = ctx->artop;

    if (artop != nullptr) {
      NumericExpression *ne2 = _numericExpressions.top();
      _numericExpressions.pop();

      NumericExpression *ne1 = _numericExpressions.top();
      _numericExpressions.pop();

      if (artop->getText() == "*") {
        _numericExpressions.push(makeExpression<NumericMul>(ne1, ne2));
        return;
      }
      if (artop->getText() == "/") {
        _numericExpressions.push(makeExpression<NumericDiv>(ne1, ne2));
        return;
      }
      if (artop->getText() == "-") {
        _numericExpressions.push(makeExpression<NumericSub>(ne1, ne2));
        return;
      }
      if (artop->getText() == "+") {
        _numericExpressions.push(makeExpression<NumericSum>(ne1, ne2));
        return;
      }
      messageError("Unknown binary arithmetic operator in numeric expression!");
    }
  }
}

Proposition *PropositionParser::getProposition() {

  if (_proposition.size() != 1)
    return nullptr;

  Proposition *ret = _proposition.top();
  _proposition.pop();

  return ret;
}
}
