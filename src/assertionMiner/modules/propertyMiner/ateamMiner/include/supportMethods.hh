#pragma once

#include "oden/types.hh"
#include <cstddef>
using namespace oden;

namespace ateam {

namespace support {

#define DIV(a, b) (static_cast<double>((a)) / static_cast<double>((b)))

/// @brief Given a template, this method returns the antecedent of the formula
Template getAntecedent(Template templ);

/// @brief Given a template, this method returns the consequent of the formula
Template getConsequent(Template templ);

/// @brief Given a formula, which represents the antecedent of a template,
/// this method returns the offsets among the atomic propositions.
void getOffsetsFromChain(Template templ, std::vector<size_t> &offsets);

double getEntropy(size_t occurrences, size_t traceLength);

} // namespace support
} // namespace ateam
