#pragma once

#include "oden/List.hh"
#include "oden/classes/DataType.hh"
#include "oden/modules/TraceReader.hh"
#include "oden/types.hh"

#include <fstream>
#include <list>
#include <map>
#include <string>

using namespace std;

namespace oden {
namespace modules {

/// @brief MangroveTraceReader declaration.
/// This class reads a simulation trace in "mangrove" format.

class MangroveTraceReader : public TraceReader {

  public:
    /// @brief Constructor.
    /// @param xmlNode The xml node containing the reader's parameters
    explicit MangroveTraceReader(XmlNode *xmlNode);

    /// @brief Destructor.
    ~MangroveTraceReader() override = default;

    /// @brief readTraces. Method in charge of generating a Trace object
    /// for each file .mangrove
    /// @param traces A empty List of Trace objects
    TraceRepository *readTraces() override;

  private:
    // path to the file .variables
    string _variablesFile;

    // list of files .mangrove
    list<string> _tracesFile;

    // list of variables
    std::list<std::string> _sortedNames;

    // mapping between var's name and its direction
    std::map<std::string, VariableDirection> _name2Dir;

    void _readVariablesFile(List<DataType> &vars);
    void _readTraceFile(TraceRepository &repo, const string &traceFile);
    void _readBooleans(BooleanVariable *var, ifstream &infile, size_t length);
    void _readLogics(LogicVariable *var, ifstream &infile, size_t length);
    void _readNumeric(NumericVariable *var, ifstream &infile, size_t length);
};

} // namespace modules
} // namespace oden
