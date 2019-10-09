#pragma once

#include "oden/List.hh"
#include "oden/classes/DataType.hh"
#include "oden/classes/Trace.hh"

#include <map>
#include <string>

namespace oden {

using Name2Variable = std::map<std::string, const DataType *>;

/// @brief TraceRepository declaration.
/// This class represents a poll of simulation traces.
class TraceRepository {
  public:
    /// @brief Constructor.
    /// @param variables The variables to be set in each trace.
    explicit TraceRepository(List<DataType> &variables);

    /// @brief Copy constructor
    TraceRepository(const TraceRepository &repo) = delete;

    /// @brief Destructor.
    ~TraceRepository() = default;

    /// @brief Returns a const reference of the variable given its name.
    /// @param name The name of the variable.
    /// @return A Variable.
    const DataType &getVariable(const std::string &name);

    /// @brief Returns a const reference of the map name2Variable.
    /// @return A map name2Variable.
    const Name2Variable &getVariables();

    /// @brief Creates a new execution trace.
    /// @param size The length of the execution trace.
    /// @return A empty trace with length fixed at size.
    Trace &makeTrace(size_t length);

    /// @brief Returns the i-th execution trace.
    /// @return The i-th trace.
    Trace &operator[](size_t position);

    /// @brief Returns the number of traces in the repository.
    /// @return The number of traces.
    size_t size() const;

  private:
    // The vriables in each simulation trace.
    List<DataType> _variables;

    // Mapping between variable's name and its declaration.
    Name2Variable _varName2varDeclaration;

    // List of simulation traces.
    List<Trace> _repository;
};

} // namespace oden
