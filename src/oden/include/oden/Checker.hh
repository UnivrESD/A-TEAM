#pragma once

#include "oden/classes/Trace.hh"
#include "oden/classes/TraceRepository.hh"
#include "oden/types.hh"

namespace oden {

/// @brief Checker class
/// This class represents an assertion checker.
class Checker {
  public:
    /// @brief Constructor.
    Checker();

    /// @brief Destructor.
    ~Checker() = default;

    /// @brief evaluate method.
    /// @param assertion The assertion that has to be evaluated in each
    /// trace of the TraceRepository
    /// @param traces The tracerepository storing simulation traces
    bool evaluate(Assertion &assertion, TraceRepository &traces);

    /// @brief evaluate method.
    /// @param assertion The assertion that has to be evaluated in the
    /// simulation trace
    /// @param traces The trace
    bool evaluate(Assertion &assertion, Trace &trace);

  private:
    //
    void _updatePointers2Trace(Assertion &assertion, Trace *trace);
    //
    bool _evaluate(Assertion &assertion, const Template &templ, size_t instant);

    size_t _traceLength;
};

} // namespace oden
