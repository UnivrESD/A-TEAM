#pragma once

#include "oden/classes/Trace.hh"
#include "oden/types.hh"
#include <string>

namespace oden {

/// @brief This method turns a proposition into a string.
/// @param prop The proposition
std::string prop2String(Proposition &prop);

/// @brief return the len of antecedent 
int prop2len(Proposition &prop);

/// @brief return the len of cosequent next 
int prop2next(Proposition &prop);

int prop2depth(Proposition &prop);

std::string logicExp2String(LogicExpression &le);

/// @brief Copy a given Proposition.
/// @param prop The proposition that has to be copied.
/// @return a copy of prop.
Proposition *copy(Proposition &prop);

/// @brief This method updates the proposition's pointer to make every
/// its variable read the values from the provided trace.
/// @param prop A proposition
/// @param trace A trace
void changeTrace(Proposition &prop, Trace &trace);

/// @brief This method turns a string into a Numeric
/// @param val A string representing a Numeric value
/// @return a Numeric
Numeric string2Numeric(const std::string &val);

/// @brief This method turns a string into a Logic
/// @param val A string representing a Logic value
/// @return a Logic
Logic string2Logic(const std::string &val);

/// @brief Checks if the given proposition is always constant.
/// @param prop The proposition that has to be evaluated.
/// @return the boolean value true if the proposition is a constant. Otherwise
/// it returns the boolean value false.
bool isConstant(Proposition &prop);

/// @brief Given a proposition prop, it makes the assertion G(prop).
/// @param prop A proposition
/// @return an assertion
Assertion *makeInvariant(Proposition &prop);

template <typename T1> void addItems(T1 &base);

template <typename T1, typename T2, typename... T3>
void addItems(T1 &base, T2 arg1, T3... args);

/// @brief This method generates a new expression of type T1. All provided
/// sub-expressions are added in the generated expression by using its addItem
/// method.
/// @param args A list of sub-expressions.
/// @return A new expression combining the given sub-expressions by an operator.
template <typename T1, typename... T2> T1 *makeExpression(T2... args);

} // namespace oden

#include "propositionUtils.i.hh"
