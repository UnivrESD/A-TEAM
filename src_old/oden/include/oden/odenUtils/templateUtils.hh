#pragma once

#include "oden/classes/Trace.hh"
#include "oden/types.hh"

#include <string>

namespace oden {

/// @brief This method turns a template into a string
/// @param templ The template
/// @return a string
std::string template2String(Template templ);

/// @brief This method turns a string into a template
/// @param str A string describing a LTL formula
Template string2Template(const std::string &str);

/// @brief This methos returns true if the Template is an atomic proposition.
/// false, otherwise.
bool isAtomicProposition(Template templ);

/// @brief Given a template, this method removes the next operators from the
/// template (e.g. X[2](p) is turned into p)
Template removeNext(Template templ);

/// @brief Given a template, this method returns the number of next operators
/// before reaching the formula
size_t countNext(Template templ);

} // namespace oden
