#pragma once

#include "oden/List.hh"
#include "oden/classes/DataType.hh"
#include "oden/classes/atom/Variable.hh"
#include "oden/types.hh"

#include <map>
#include <string>

namespace oden {

// Forwards declaration
class PeTraceChanger;

/// @brief Trace declaration.
/// This class represents a simulation trace.
class Trace {

  public:
    /// @brief Constructor.
    /// @param variables The variables to be set in the trace.
    /// @param length The length of the trace (number of simulation instants).
    Trace(List<DataType> &variables, size_t length);

    /// @brief Copy constructor
    Trace(const Trace &other) = delete;

    /// @brief Destructor.
    ~Trace();

    /// @brief Returns the length of the trace.
    size_t getLength() const;

    /// @brief Returns the BooleanVariable given its name.
    /// @param name The name of the boolean variable
    /// @return An instance of BooleanVariable
    BooleanVariable *getBooleanVariable(const std::string &name) const;

    /// @brief Returns the logic variable given its name.
    /// @param name The name of the logic variable
    /// @return An instance of ExpressionVariable<Logic>
    LogicVariable *getLogicVariable(const std::string &name) const;

    /// @brief Returns the numeric variable given its name.
    /// @param name The name of the numeric variable
    /// @return An instance of ExpressionVariable<Numeric>
    NumericVariable *getNumericVariable(const std::string &name) const;

    /// @brief Assignment operator
    /// @param other The other trace to be copied.
    Trace &operator=(const Trace &other) = delete;

    // declaring PeTraceChanger as a friend class
    // in otder to let it access to private variables
    friend class PeTraceChanger;

  private:
    /// @brief The numeric sub-trace containing the values of each Numeric
    /// variable
    Numeric *_numeriTrace;

    /// @brief The boolean sub-trace containing the values of each Boolean
    /// variable
    unsigned int *_booleanTrace;

    /// @brief The logic sub-trace containing the values of each Logic variable
    uint64_t *_logicTrace;

    /// @brief The length of the trace
    size_t _length;

    /// @brief The mapping between the logic variable and its size
    std::map<std::string, uint8_t> _logicName2size;

    /// @brief The mapping between variable's name and values
    std::map<std::string, uintptr_t> _varName2varValues;

    // Logics are stored in a uint64_t array
    const size_t _bits4Logic = sizeof(uint64_t);

    void _allocateTrace(List<DataType> &variables);
    void _allocatePointers(List<DataType> &variables);
};

} // namespace oden
