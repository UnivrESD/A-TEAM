//
// Created by danes on 30/05/2019.
//

#include "oden/parser/PropositionParser.hh"
//#include "oden/classes/expressions/expressions.hh"
//#include "oden/classes/propositions/propositions.hh"
#include "oden/odenUtils/odenUtils.hh"

#include "oden/classes/atom/Constant.hh"
#include "oden/classes/atom/Variable.hh"
#include "oden/classes/expression/Expression.hh"
#include "oden/classes/temporal/NextOperator.hh"
#include "oden/classes/temporal/PastOperator.hh"
#include <cassert>

#define CHECK_ABORT                                                            \
    if (_abort)                                                                \
        return;

namespace oden {

PropositionParser::PropositionParser(const Name2Variable &varName2varDec,
                                     Trace &trace)
    : _varName2varDec(varName2varDec), _trace(trace), _abort(false), _type(),
      _proposition(), _logicExpressions(), _numericExpressions() {}

/*
void PropositionParser::enterFile(propositionParser::FileContext * ctx) {
    // //std::cout << "enterFile\n";
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

Proposition *PropositionParser::getProposition() {
    if (_proposition.size() != 1)
        return nullptr;

    Proposition *ret = _proposition.top();
    _proposition.pop();

    return ret;
}

void PropositionParser::exitProposition(
    propositionParser::PropositionContext *ctx) {
    CHECK_ABORT
}

void PropositionParser::enterConstant(propositionParser::ConstantContext *ctx) {
    CHECK_ABORT

    antlr4::tree::TerminalNode *con = ctx->CONSTANT();
    std::string conStr              = std::string(con->getText());

    if (conStr.substr(0,2) == "'b") {
        Logic value = oden::string2Logic(conStr.substr(2,conStr.size()-2));
        auto *c     = new LogicConstant(value,INT_MAX );
        _logicExpressions.push(c);
        return;
    } else {
        Numeric value = oden::string2Numeric(conStr);
        auto *c       = new NumericConstant(value, INT_MAX);
        _numericExpressions.push(c);
        return;
    }
    messageError("Unknown-type constants!");
}

void PropositionParser::enterVariable(propositionParser::VariableContext *ctx) {
    CHECK_ABORT

    // //std::cout << "enterVariable\n";
    tree::TerminalNode *tNode = ctx->VARIABLE();
    std::string varName       = std::string(tNode->getText());

    auto found = _varName2varDec.find(varName);
    messageErrorIf(found == _varName2varDec.end(),
                   "Unknown variable name: " + varName);

    // record the last variable's type met
    _type = *(found->second);

    switch (_type.getType()) {
    case VariableType::boolean: {
        Proposition *n = _trace.getBooleanVariable(varName);
        if (ctx->NextOp() != nullptr && ctx->LCPAREN() != nullptr &&
            ctx->RCPAREN() != nullptr) {
            tNode         = ctx->CONSTANT();
            size_t offset = static_cast<size_t>(std::stoi(tNode->getText()));
            n             = new PropositionNext(n, offset);
        }

        _proposition.push(n);
        break;
    }
    case VariableType::numeric: {
        NumericExpression *n = _trace.getNumericVariable(varName);
        if (ctx->NextOp() != nullptr && ctx->LCPAREN() != nullptr &&
            ctx->RCPAREN() != nullptr) {
            tNode         = ctx->CONSTANT();
            size_t offset = static_cast<size_t>(std::stoi(tNode->getText()));
            n             = new NumericNext(n, offset);
        }

        _numericExpressions.push(n);
        break;
    }
    case VariableType::logic: {
        LogicExpression *l = _trace.getLogicVariable(varName);
        if (ctx->NextOp() != nullptr && ctx->LCPAREN() != nullptr &&
            ctx->RCPAREN() != nullptr) {
            tNode         = ctx->CONSTANT();
            size_t offset = static_cast<size_t>(std::stoi(tNode->getText()));
            l             = new LogicNext(l, offset);
        }

        _logicExpressions.push(l);
        break;
    }
    case VariableType::unknown:
        break;
    default:
        messageError("Unknown-type variable!");
    }
}
void PropositionParser::handleBooleanExpression(
    propositionParser::BoolopContext *boolop) {

    Proposition *p2 = _proposition.top();
    _proposition.pop();

    Proposition *p1 = _proposition.top();
    _proposition.pop();

    if (boolop->AND() != nullptr) {
        _proposition.push(makeExpression<PropositionAnd>(p1, p2));
        return;
    }
    if (boolop->OR() != nullptr) {
        _proposition.push(makeExpression<PropositionOr>(p1, p2));
        return;
    }
    if (boolop->bEQ() != nullptr) {
        _proposition.push(makeExpression<PropositionEq>(p1, p2));
        return;
    }

    messageError("Unknown boolean operator!");
}
void PropositionParser::handleLogicExpression(
    propositionParser::LogopContext *logop) {

    LogicExpression *le2 = _logicExpressions.top();
    _logicExpressions.pop();

    LogicExpression *le1 = _logicExpressions.top();
    _logicExpressions.pop();

    if (logop->BAND() != nullptr) {
        _logicExpressions.push(makeExpression<LogicBAnd>(le1, le2));
        return;
    }
    if (logop->BOR() != nullptr) {
        _logicExpressions.push(makeExpression<LogicBOr>(le1, le2));
        return;
    }
    if (logop->BXOR() != nullptr) {
        _logicExpressions.push(makeExpression<LogicBXor>(le1, le2));
        return;
    }

    if (logop->TIMES_() != nullptr) {
        _logicExpressions.push(makeExpression<LogicMul>(le1, le2));
        return;
    }
    if (logop->DIV_() != nullptr) {
        _logicExpressions.push(makeExpression<LogicDiv>(le1, le2));
        return;
    }
    if (logop->MINUS_() != nullptr) {
        _logicExpressions.push(makeExpression<LogicSub>(le1, le2));
        return;
    }
    if (logop->PLUS_() != nullptr) {
        _logicExpressions.push(makeExpression<LogicSum>(le1, le2));
        return;
    }
    messageError("Unknown arithmetic operator in logic expression.");
}
void PropositionParser::handleNumericExpression(
    propositionParser::ArtopContext *artop) {

    NumericExpression *ne2 = _numericExpressions.top();
    _numericExpressions.pop();

    NumericExpression *ne1 = _numericExpressions.top();
    _numericExpressions.pop();

    if (artop->TIMES() != nullptr) {
        _numericExpressions.push(makeExpression<NumericMul>(ne1, ne2));
        return;
    }
    if (artop->DIV() != nullptr) {
        _numericExpressions.push(makeExpression<NumericDiv>(ne1, ne2));
        return;
    }
    if (artop->MINUS() != nullptr) {
        _numericExpressions.push(makeExpression<NumericSub>(ne1, ne2));
        return;
    }
    if (artop->PLUS() != nullptr) {
        _numericExpressions.push(makeExpression<NumericSum>(ne1, ne2));
        return;
    }
    messageError("Unknown arithmetic operator in numeric expression.");
}
void PropositionParser::handleNumericExpression(
    propositionParser::LrelopContext *lrelop) {

    LogicExpression *ne2 = _logicExpressions.top();
    _logicExpressions.pop();

    LogicExpression *ne1 = _logicExpressions.top();
    _logicExpressions.pop();

    if (lrelop->EQ_() != nullptr) {
        _proposition.push(makeExpression<LogicEq>(ne1, ne2));
        return;
    }
    if (lrelop->NEQ_() != nullptr) {
        _proposition.push(makeExpression<LogicNeq>(ne1, ne2));
        return;
    }
    if (lrelop->LT_() != nullptr) {
        _proposition.push(makeExpression<LogicLess>(ne1, ne2));
        return;
    }
    if (lrelop->LE_() != nullptr) {
        _proposition.push(makeExpression<LogicLessEq>(ne1, ne2));
        return;
    }
    if (lrelop->GT_() != nullptr) {
        _proposition.push(makeExpression<LogicGreater>(ne1, ne2));
        return;
    }
    if (lrelop->GE_() != nullptr) {
        _proposition.push(makeExpression<LogicGreaterEq>(ne1, ne2));
        return;
    }
    messageError("Unknown relational operator in logic expression!");
}
void PropositionParser::handleNumericExpression(
    propositionParser::RelopContext *relop) {

    NumericExpression *ne2 = _numericExpressions.top();
    _numericExpressions.pop();

    NumericExpression *ne1 = _numericExpressions.top();
    _numericExpressions.pop();

    if (relop->EQ() != nullptr) {
        _proposition.push(makeExpression<NumericEq>(ne1, ne2));
        return;
    }
    if (relop->NEQ() != nullptr) {
        _proposition.push(makeExpression<NumericNeq>(ne1, ne2));
        return;
    }
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
    messageError("Unknown relational operator in logic expression!");
}
void PropositionParser::exitHandleNot(
    propositionParser::HandleNotContext *ctx) {
    CHECK_ABORT
    Proposition *p = _proposition.top();
    _proposition.pop();
    _proposition.push(makeExpression<PropositionNot>(p));
    return;
}
void PropositionParser::exitHandleNeg(
    propositionParser::HandleNegContext *ctx) {
    CHECK_ABORT
    LogicExpression *l = _logicExpressions.top();
    _logicExpressions.pop();
    _logicExpressions.push(makeExpression<LogicNot>(l));
    return;
}
void PropositionParser::exitBooleanExpression(
    propositionParser::BooleanExpressionContext *ctx) {
    CHECK_ABORT
    // //std::cout << "exitBooleanExpression\n";

    propositionParser::RelopContext *relop   = ctx->relop();
    propositionParser::LrelopContext *lrelop = ctx->lrelop();

    // handling the expression: booleanExpression boolop numericExpression
    if (relop != nullptr) {
        handleNumericExpression(relop);
        return;
    }

    // handling the expression: booleanExpression boolop logicExpression
    if (lrelop != nullptr) {
        handleNumericExpression(lrelop);
        return;
    }

    propositionParser::BoolopContext *boolop = ctx->boolop();
    if (boolop == nullptr) {
        return;
    }

    // handling the expression: booleanExpression boolop booleanExpression
    handleBooleanExpression(boolop);
}
void PropositionParser::exitLogicExpression(
    propositionParser::LogicExpressionContext *ctx) {
    CHECK_ABORT
    // //std::cout << "exitLogicExpression\n";

    propositionParser::LrelopContext *lrelop = ctx->lrelop();
    propositionParser::LogopContext *logop   = ctx->logop();
    propositionParser::BoolopContext *boolop = ctx->boolop();

    // handling the expression: numericExpression boolop booleanExpression
    if (boolop != nullptr) {
        handleBooleanExpression(boolop);
        return;
    }

    if (logop == nullptr && lrelop == nullptr) {
        return;
    }

    if (_logicExpressions.size() < 2) {
        _abort = true;
        return;
    }

    // handling the expression: logicExpression logop logicExpression
    if (logop != nullptr) {
        handleLogicExpression(logop);
        return;
    }

    // handling the expression: logicExpression lrelop logicExpression
    if (lrelop != nullptr) {
        handleNumericExpression(lrelop);
        return;
    }
}

void PropositionParser::exitNumericExpression(
    propositionParser::NumericExpressionContext *ctx) {
    CHECK_ABORT
    // //std::cout << "exitNumericExpression\n";

    propositionParser::ArtopContext *numoper = ctx->artop();
    propositionParser::RelopContext *relop   = ctx->relop();
    propositionParser::BoolopContext *boolop = ctx->boolop();

    // handling the expression: numericExpression boolop booleanExpression
    if (boolop != nullptr) {
        handleBooleanExpression(boolop);
        return;
    }

    if (numoper == nullptr && relop == nullptr) {
        return;
    }

    if (_numericExpressions.size() < 2) {
        _abort = true;
        return;
    }

    // handling the expression: numericExpression artop numericExpression
    if (numoper != nullptr) {
        handleNumericExpression(numoper);
        return;
    }

    // handling the expression: numericExpression relop numericExpression
    if (relop != nullptr) {
        handleNumericExpression(relop);
        return;
    }
}

void PropositionParser::exitAtomicProp(
    propositionParser::AtomicPropContext *ctx) {
    CHECK_ABORT

    // //std::cout << "exitAtomicProp\n";

}

void PropositionParser::visitErrorNode(tree::ErrorNode * node) {
    _abort = true;
}
*/
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

void PropositionParser::exitLogic(propositionParser::LogicContext *ctx) {

    if (ctx->LPAREN() && ctx->RPAREN()) {
        // std::cout << __func__ << ": ) " << std::endl;
        return;
    }

    antlr4::Token *logop = ctx->logop;

    if (ctx->NEG() != nullptr) {
        // TODO negate logic on stack
        // std::cout << __func__ << ": ~ " << std::endl;
        LogicExpression *l = _logicExpressions.top();
        _logicExpressions.pop();
        _logicExpressions.push(makeExpression<LogicNot>(l));
        //     if(ctx->logop()==nullptr  && ctx->artop()==nullptr){ return; }
    }

    if (logop != nullptr) {
        // TODO create logic from logic stack
        // std::cout << __func__ << " logop " << std::endl;
        makeLogicFromLogic(logop);
        return;
    }
}
void PropositionParser::exitNumeric_logic(
    propositionParser::Numeric_logicContext *ctx) {

    if (ctx->LPAREN() && ctx->RPAREN()) {
        // std::cout << __func__ << ": ) " << std::endl;
        return;
    }

    //next operator
    if (ctx->NextOp() != nullptr && ctx->LCPAREN() != nullptr &&
        ctx->RCPAREN() != nullptr) {

        messageErrorIf(
            (_logicExpressions.empty() && _numericExpressions.empty()) ||
                (!_logicExpressions.empty() && !_numericExpressions.empty()),
            "Type missmatch: Numeric vs Logic");

        if (_logicExpressions.empty()) {
            NumericExpression *ne = _numericExpressions.top();
            _numericExpressions.pop();
            size_t offset =
                static_cast<size_t>(std::stoi(ctx->CONSTANT()->getText()));
            _numericExpressions.push(new NumericNext(ne, offset));
        } else {
            LogicExpression *le = _logicExpressions.top();
            _logicExpressions.pop();
            size_t offset =
                static_cast<size_t>(std::stoi(ctx->CONSTANT()->getText()));
            _logicExpressions.push(new LogicNext(le, offset));
        }
    }

    //past operator
    if (ctx->PastOp() != nullptr && ctx->LPAREN() != nullptr &&
        ctx->RPAREN() != nullptr) {

        messageErrorIf(
            (_logicExpressions.empty() && _numericExpressions.empty()) ||
                (!_logicExpressions.empty() && !_numericExpressions.empty()),
            "Type missmatch: Numeric vs Logic");

        if (_logicExpressions.empty()) {
            NumericExpression *ne = _numericExpressions.top();
            _numericExpressions.pop();
            size_t offset =
                static_cast<size_t>(std::stoi(ctx->CONSTANT()->getText()));
            _numericExpressions.push(new NumericPast(ne, offset));
        } else {
            LogicExpression *le = _logicExpressions.top();
            _logicExpressions.pop();
            size_t offset =
                static_cast<size_t>(std::stoi(ctx->CONSTANT()->getText()));
            _logicExpressions.push(new LogicPast(le, offset));
        }
    }

    antlr4::Token *artop = ctx->artop;

    if (artop != nullptr) {
        // TODO create logic or numeric from numeric or logic stack
        // std::cout << __func__ << " artop " << std::endl;
        makeNumericLogicFromNumericLogic(artop);
        return;
    }
}
void PropositionParser::exitExpression(
    propositionParser::ExpressionContext *ctx) {

    if (ctx->LPAREN() && ctx->RPAREN() && ctx->PastOp() == nullptr) {
        // std::cout << __func__ << ": ) " << std::endl;
        return;
    }

    // next operator
    if (ctx->NextOp() != nullptr && ctx->LCPAREN() != nullptr &&
        ctx->RCPAREN() != nullptr) {
        messageErrorIf(
            ((_logicExpressions.empty() && _numericExpressions.empty()) &&
             _proposition.empty()) ||
                (!_logicExpressions.empty() && !_numericExpressions.empty()),
            "Type missmatch: Numeric vs Logic vs Boolean in Next operator");

        if (!_logicExpressions.empty() || !_numericExpressions.empty()) {
            if (_logicExpressions.empty()) {
                NumericExpression *ne = _numericExpressions.top();
                _numericExpressions.pop();
                size_t offset =
                    static_cast<size_t>(std::stoi(ctx->CONSTANT()->getText()));
                _numericExpressions.push(new NumericNext(ne, offset));
                return;
            } else {
                LogicExpression *le = _logicExpressions.top();
                _logicExpressions.pop();
                size_t offset =
                    static_cast<size_t>(std::stoi(ctx->CONSTANT()->getText()));
                _logicExpressions.push(new LogicNext(le, offset));
                return;
            }
        }

        Proposition *p = _proposition.top();
        _proposition.pop();
        size_t offset =
            static_cast<size_t>(std::stoi(ctx->CONSTANT()->getText()));
        _proposition.push(new PropositionNext(p, offset));
        return;
    }

    // past operator
    if (ctx->PastOp() != nullptr && ctx->LPAREN() != nullptr &&
        ctx->RPAREN() != nullptr) {
        messageErrorIf(
            ((_logicExpressions.empty() && _numericExpressions.empty()) &&
             _proposition.empty()) ||
                (!_logicExpressions.empty() && !_numericExpressions.empty()),
            "Type missmatch: Numeric vs Logic vs Boolean in Next operator");

        if (!_logicExpressions.empty() || !_numericExpressions.empty()) {
            if (_logicExpressions.empty()) {
                NumericExpression *ne = _numericExpressions.top();
                _numericExpressions.pop();
                size_t offset =
                    static_cast<size_t>(std::stoi(ctx->CONSTANT()->getText()));
                _numericExpressions.push(new NumericPast(ne, offset));
                return;
            } else {
                LogicExpression *le = _logicExpressions.top();
                _logicExpressions.pop();
                size_t offset =
                    static_cast<size_t>(std::stoi(ctx->CONSTANT()->getText()));
                _logicExpressions.push(new LogicPast(le, offset));
                return;
            }
        }
        Proposition *p = _proposition.top();
        _proposition.pop();
        size_t offset =
            static_cast<size_t>(std::stoi(ctx->CONSTANT()->getText()));
        _proposition.push(new PropositionPast(p, offset));
        return;
    }

    propositionParser::RelopContext *relop = ctx->relop();

    if (ctx->NOT()) {
        // TODO negate boolean on stack
        // handle "!"
        Proposition *p = _proposition.top();
        _proposition.pop();
        _proposition.push(makeExpression<PropositionNot>(p));
        // std::cout << __func__ << ": ! " << std::endl;
    }

    if (ctx->EQ() != nullptr) {
        // TODO create boolean from numeric or logic or bool stack
        if (!_numericExpressions.empty() && _logicExpressions.empty()) {
            NumericExpression *ne2 = _numericExpressions.top();
            _numericExpressions.pop();
            NumericExpression *ne1 = _numericExpressions.top();
            _numericExpressions.pop();
            _proposition.push(makeExpression<NumericEq>(ne1, ne2));
        } else if (_numericExpressions.empty() && !_logicExpressions.empty()) {
            LogicExpression *le2 = _logicExpressions.top();
            _logicExpressions.pop();
            LogicExpression *le1 = _logicExpressions.top();
            _logicExpressions.pop();
            _proposition.push(makeExpression<LogicEq>(le1, le2));
        } else if (!_proposition.empty() && _numericExpressions.empty() &&
                   _logicExpressions.empty()) {
            Proposition *p2 = _proposition.top();
            _proposition.pop();
            Proposition *p1 = _proposition.top();
            _proposition.pop();
            _proposition.push(makeExpression<PropositionEq>(p1, p2));
        } else {
            messageError("Type missmatch!");
        }
        return;
    }

    if (ctx->NEQ() != nullptr) {
        // TODO create boolean from numeric or logic or bool stack
        if (!_numericExpressions.empty() && _logicExpressions.empty()) {
            NumericExpression *ne2 = _numericExpressions.top();
            _numericExpressions.pop();
            NumericExpression *ne1 = _numericExpressions.top();
            _numericExpressions.pop();
            _proposition.push(makeExpression<NumericNeq>(ne1, ne2));
        } else if (_numericExpressions.empty() && !_logicExpressions.empty()) {
            LogicExpression *le2 = _logicExpressions.top();
            _logicExpressions.pop();
            LogicExpression *le1 = _logicExpressions.top();
            _logicExpressions.pop();
            _proposition.push(makeExpression<LogicNeq>(le1, le2));
        } else if (!_proposition.empty() && _numericExpressions.empty() &&
                   _logicExpressions.empty()) {
            Proposition *p2 = _proposition.top();
            _proposition.pop();
            Proposition *p1 = _proposition.top();
            _proposition.pop();
            _proposition.push(makeExpression<PropositionNeq>(p1, p2));
        } else {
            messageError("Type missmatch!");
        }
        return;
    }

    if (ctx->boolop != nullptr) {
        // TODO create boolean from numeric or logic or bool stack
        // std::cout << __func__ << " boolop " << std::endl;
        handleBooleanExpression(ctx->boolop);
        return;
    } else if (relop != nullptr) {
        // TODO create bool from numeric or logic stack
        // std::cout << __func__ << " relop " << std::endl;
        makeBoolFromNumericLogic(relop);
        return;
    }
}

void PropositionParser::enterVariable(propositionParser::VariableContext *ctx) {
    CHECK_ABORT

    tree::TerminalNode *tNode = ctx->VARIABLE();
    std::string varName       = std::string(tNode->getText());
    // std::cout << __func__ << ": " << varName << std::endl;

    auto found = _varName2varDec.find(varName);
    messageErrorIf(found == _varName2varDec.end(),
                   "Unknown variable name: " + varName);

    // record the last variable's type met
    _type = *(found->second);

    switch (_type.getType()) {
    case VariableType::boolean: {
        Proposition *n = _trace.getBooleanVariable(varName);
        /*
        if (ctx->NextOp() != nullptr && ctx->LCPAREN() != nullptr &&
            ctx->RCPAREN() != nullptr) {
            tNode         = ctx->CONSTANT();
            size_t offset = static_cast<size_t>(std::stoi(tNode->getText()));
            n             = new PropositionNext(n, offset);
        }
        */

        _proposition.push(n);
        break;
    }
    case VariableType::numeric: {
        NumericExpression *n = _trace.getNumericVariable(varName);
        /*
        if (ctx->NextOp() != nullptr && ctx->LCPAREN() != nullptr &&
            ctx->RCPAREN() != nullptr) {
            tNode         = ctx->CONSTANT();
            size_t offset = static_cast<size_t>(std::stoi(tNode->getText()));
            n             = new NumericNext(n, offset);
        }
        */

        _numericExpressions.push(n);
        break;
    }
    case VariableType::logic: {
        LogicExpression *l = _trace.getLogicVariable(varName);
        /*
        if (ctx->NextOp() != nullptr && ctx->LCPAREN() != nullptr &&
            ctx->RCPAREN() != nullptr) {
            tNode         = ctx->CONSTANT();
            size_t offset = static_cast<size_t>(std::stoi(tNode->getText()));
            l             = new LogicNext(l, offset);
        }
        */

        _logicExpressions.push(l);
        break;
    }
    case VariableType::unknown:
        break;
    default:
        messageError("Unknown-type variable!");
    }
}
void PropositionParser::enterConstant(propositionParser::ConstantContext *ctx) {
    CHECK_ABORT

    antlr4::tree::TerminalNode *con = ctx->CONSTANT();
    std::string conStr              = std::string(con->getText());

    if (conStr.substr(0, 2) == "'b") {
        Logic value = oden::string2Logic(conStr.substr(2, conStr.size() - 2));
        auto *c     = new LogicConstant(value, INT_MAX);
        _logicExpressions.push(c);
        return;
    } else {
        Numeric value = oden::string2Numeric(conStr);
        auto *c       = new NumericConstant(value, INT_MAX);
        _numericExpressions.push(c);
        return;
    }
    messageError("Unknown-type constants!");
}

void PropositionParser::exitFile(propositionParser::FileContext *ctx) {
    // std::cout << "IT WORKS!" << std::endl;
}
void PropositionParser::makeLogicFromLogic(antlr4::Token *art_log_op) {

    messageErrorIf((_logicExpressions.empty() || !_numericExpressions.empty()),
                   "Type missmatch: Numeric vs Logic");

    LogicExpression *le2 = _logicExpressions.top();
    _logicExpressions.pop();

    LogicExpression *le1 = _logicExpressions.top();
    _logicExpressions.pop();

    if (art_log_op->getText() == "&") {
        _logicExpressions.push(makeExpression<LogicBAnd>(le1, le2));
        return;
    }
    if (art_log_op->getText() == "|") {
        _logicExpressions.push(makeExpression<LogicBOr>(le1, le2));
        return;
    }

    messageError("Unknown logic operator in logic expression!");
}
void PropositionParser::makeNumericLogicFromNumericLogic(
    antlr4::Token *art_log_op) {

    messageErrorIf(
        (_logicExpressions.empty() && _numericExpressions.empty()) ||
            (!_logicExpressions.empty() && !_numericExpressions.empty()),
        "Type missmatch: Numeric vs Logic");

    if (_logicExpressions.empty()) {
        NumericExpression *ne2 = _numericExpressions.top();
        _numericExpressions.pop();

        NumericExpression *ne1 = _numericExpressions.top();
        _numericExpressions.pop();

        if (art_log_op->getText() == "*") {
            _numericExpressions.push(makeExpression<NumericMul>(ne1, ne2));
            return;
        }
        if (art_log_op->getText() == "/") {
            _numericExpressions.push(makeExpression<NumericDiv>(ne1, ne2));
            return;
        }
        if (art_log_op->getText() == "-") {
            _numericExpressions.push(makeExpression<NumericSub>(ne1, ne2));
            return;
        }
        if (art_log_op->getText() == "+") {
            _numericExpressions.push(makeExpression<NumericSum>(ne1, ne2));
            return;
        }

        messageError(
            "Unknown arithmetic operator in numeric_logic expression!");
    } else {
        LogicExpression *le2 = _logicExpressions.top();
        _logicExpressions.pop();

        LogicExpression *le1 = _logicExpressions.top();
        _logicExpressions.pop();

        if (art_log_op->getText() == "*") {
            _logicExpressions.push(makeExpression<LogicMul>(le1, le2));
            return;
        }
        if (art_log_op->getText() == "/") {
            _logicExpressions.push(makeExpression<LogicDiv>(le1, le2));
            return;
        }
        if (art_log_op->getText() == "-") {
            _logicExpressions.push(makeExpression<LogicSub>(le1, le2));
            return;
        }
        if (art_log_op->getText() == "+") {
            _logicExpressions.push(makeExpression<LogicSum>(le1, le2));
            return;
        }
        messageError(
            "Unknown arithmetic operator in numeric_logic expression!");
    }
}
void PropositionParser::makeBoolFromNumericLogic(
    propositionParser::RelopContext *relop) {

    messageErrorIf(
        (_logicExpressions.empty() && _numericExpressions.empty()) ||
            (!_logicExpressions.empty() && !_numericExpressions.empty()),
        "Type missmatch: Numeric vs Logic");

    if (_logicExpressions.empty()) {
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
        messageError("Unknown relational operator in numeric expression!");
    } else {

        LogicExpression *ne2 = _logicExpressions.top();
        _logicExpressions.pop();

        LogicExpression *ne1 = _logicExpressions.top();
        _logicExpressions.pop();

        if (relop->LT() != nullptr) {
            _proposition.push(makeExpression<LogicLess>(ne1, ne2));
            return;
        }
        if (relop->LE() != nullptr) {
            _proposition.push(makeExpression<LogicLessEq>(ne1, ne2));
            return;
        }
        if (relop->GT() != nullptr) {
            _proposition.push(makeExpression<LogicGreater>(ne1, ne2));
            return;
        }
        if (relop->GE() != nullptr) {
            _proposition.push(makeExpression<LogicGreaterEq>(ne1, ne2));
            return;
        }
        messageError("Unknown relational operator in logic expression!");
    }
}
void PropositionParser::handleBooleanExpression(antlr4::Token *boolop) {
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
Proposition *PropositionParser::getProposition() {

    if (_proposition.size() != 1)
        return nullptr;

    Proposition *ret = _proposition.top();
    _proposition.pop();

    return ret;
}
}
