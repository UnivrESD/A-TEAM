#include "oden/modules/default/MangroveTraceReader.hh"
#include "oden/odenUtils/applicationUtils.hh"
#include "oden/odenUtils/xmlUtils.hh"
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <unistd.h>


std::string get_selfpath() {
    char buff[500];
    ssize_t len = ::readlink("/proc/self/exe", buff, sizeof(buff)-1);
    if (len != -1) {
      buff[len] = '\0';
      return std::string(buff);
    }

    return "";
    /* handle error condition */
}

namespace oden {
namespace modules {

MangroveTraceReader::MangroveTraceReader(XmlNode *xmlNode,const std::string &vcdFile)
    : TraceReader(xmlNode), _vcdFile(vcdFile), _variablesFile(), _tracesFile(), _name2Dir(),
      _sortedNames() {

          XmlNode *vcdParserConfigXml = configuration->first_node("vcdParserConfig");
          if (vcdParserConfigXml == nullptr)
              messageError("The xml node 'vcdParserConfig' has not been found");

          XmlNode *clockSignalXml = vcdParserConfigXml->first_node("clockSignal");
          if (clockSignalXml == nullptr)
              messageError("The xml node 'clockSignal' has not been found");

          XmlNode *splitSignalsXml = vcdParserConfigXml->first_node("splitSignals");
          if (splitSignalsXml == nullptr)
              messageError("The xml node 'splitSignals' has not been found");

          XmlNode *addModulePathToVariablesXml = vcdParserConfigXml->first_node("addModulePathToVariables");
          if (addModulePathToVariablesXml == nullptr)
              messageError("The xml node 'addModulePathToVariables' has not been found");

          XmlNode *convertSingleBitLogicToBoolXml = vcdParserConfigXml->first_node("convertSingleBitLogicToBool");
          if (convertSingleBitLogicToBoolXml == nullptr)
              messageError("The xml node 'convertSingleBitLogicToBool' has not been found");



          _clk=getAttributeValue(clockSignalXml,"name");
          std::string splitSignal=getAttributeValue(splitSignalsXml,"value");
          std::string addModulePathToVariables=getAttributeValue(addModulePathToVariablesXml,"value");
          std::string convertSingleBitLogicToBool=getAttributeValue(convertSingleBitLogicToBoolXml,"value");


          size_t itIndex = _vcdFile.find_last_of("/", _vcdFile.size() - 1);
          std::string pathToOut(_vcdFile.begin(), _vcdFile.begin() + (itIndex + 1));

    std::string binPath=get_selfpath();
    itIndex = binPath.find_last_of("/", binPath.size() - 1);
    std::string selfPath(binPath.begin(), binPath.begin() + (itIndex + 1));

    ifstream f1((pathToOut + "trace.variables").c_str());
    ifstream f2((pathToOut + "trace.mangrove").c_str());
    if (!f1.good() || !f2.good()) {
        messageInfo("Parsing VCD file...");
        std::system(("python2.7 " + selfPath + "../../../../vcd2mangrove/vcd2mangrove.py " + _vcdFile + " " + _clk + " " + splitSignal + " "  + addModulePathToVariables + " " + convertSingleBitLogicToBool + " " + pathToOut).c_str());
    } else {
        messageInfo("Trace files found! Not parsing the VCD file");
    }
    f1.close();
    f2.close();
    _variablesFile = pathToOut + "trace.variables";
    _tracesFile.push_back(pathToOut + "trace.mangrove");
    /*

_variablesFile = getAttributeValue(variablesXml, "path");
if (_variablesFile.empty())
  messageError("The attribute 'path' in the xml node 'variables' has not "
               "been found");

XmlNode *tracesXML = configuration->first_node("traces");
if (tracesXML == nullptr)
  messageError("The xml node 'traces' has not been found");

XmlNodeList tracesList;
getNodesFromName(tracesXML, "trace", tracesList);

for (auto *traceFile : tracesList) {
  std::string tracePath = getAttributeValue(traceFile, "path");
  if (tracePath.empty())
      messageError("The attribute 'path' in the xml node 'trace' has not "
                   "been found");

  _tracesFile.push_back(tracePath);
}
*/

    XmlNode *directionsXml = configuration->first_node("directions");
    if (directionsXml != nullptr) {
        messageWarning("Directions definition outside a cone of influence is "
                       "no longer supported and will be ignored!\n");
    }
    /*
    if (directionsXml == nullptr) {
        messageError("directions not found!");
    }
    XmlNodeList directionList;
    getNodesFromName(directionsXml, "direction", directionList);
    //set directions for all variables
    fillName2Dir(directionList, _name2Dir);
    */
}

TraceRepository *MangroveTraceReader::readTraces() {
    TraceRepository *ret = nullptr;

    List<DataType> vars;
    messageInfo("Reading variables...");
    _readVariablesFile(vars);
    messageInfo("Variables: " + to_string(vars.size()));

    ret = new TraceRepository(vars);

    messageInfo("Reading traces...");
    for (const string &traceFile : _tracesFile)
        _readTraceFile(*ret, traceFile);

    messageInfo("Traces: " + to_string(ret->size()));
    return ret;
}

void MangroveTraceReader::_readVariablesFile(List<DataType> &vars) {
    ifstream infile(_variablesFile);
    if (!infile.is_open())
        messageError("File not found: " + _variablesFile);

    std::string line;
    while (std::getline(infile, line)) {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        string tokens[4];
        int pos = 0;

        // Reading a line
        while (ss >> tokens[pos++])
            if (pos == 4)
                messageError("Unknown variable format");

        // Min size is 2 tokens
        if (pos < 1)
            messageError("Unknown variable format");

        VariableType type = variableTypeFromString(tokens[1]);
        if (type == VariableType::unknown)
            messageError("Unknown type of variable: " + tokens[0]);

        uint8_t size = 1;
        if (type == VariableType::logic) {
            try {
                size = static_cast<uint8_t>(stoi(tokens[2]));
            } catch (invalid_argument &e) {
                messageError("Unknown size for the logic variable: " +
                             tokens[0]);
            }
        }

        auto *newVar = new DataType();
        newVar->setName(tokens[0]);
        newVar->setType(type, size);

        /*
        auto dir = _name2Dir.find(tokens[0]);
        if (dir != _name2Dir.end()) {
            newVar->setDirection(dir->second);
        }else{
            messageWarning("Variable \""+tokens[0] + "\" has no direction!");
        }
        */

        vars.push_back(newVar);
        if (std::find(begin(_sortedNames), end(_sortedNames), tokens[0]) !=
            _sortedNames.end()) {
            messageWarning("Duplicated variable in mangrove: " + tokens[0]);
            duplicatedVariablesCount++;
        }
        _sortedNames.push_back(tokens[0]);
    }

    infile.close();
}

void MangroveTraceReader::_readTraceFile(TraceRepository &repo,
                                         const string &traceFile) {
    ifstream infile(traceFile);
    if (!infile.is_open())
        messageError("File not found: " + traceFile);

    size_t vars = 0, length = 0;
    if (!(infile >> vars >> length))
        messageError("Unknown vars and length");

    if (vars != ((repo.getVariables()).size() + duplicatedVariablesCount)) {
        messageError("The number of variables does not match with their "
                     "declaration:\n Unique vars: " +
                     std::to_string((repo.getVariables()).size()) +
                     "\n Duplicated: " +
                     std::to_string(duplicatedVariablesCount) + "\n Defined: " +
                     std::to_string(vars));
    }

    Trace &trace = repo.makeTrace(length);
    trace._clk=_clk;

    messageInfo("File: " + traceFile + " Length: " + to_string(length));
    for (string &varName : _sortedNames) {
        const DataType &dataT = repo.getVariable(varName);

        switch (dataT.getType()) {
        case VariableType::boolean: {
            BooleanVariable *var = trace.getBooleanVariable(varName);
            _readBooleans(var, infile, length);
            delete var;

            break;
        }
        case VariableType::logic: {
            LogicVariable *var = trace.getLogicVariable(varName);
            _readLogics(var, infile, length);
            delete var;

            break;
        }
        case VariableType::numeric: {
            NumericVariable *var = trace.getNumericVariable(varName);
            _readNumeric(var, infile, length);
            delete var;

            break;
        }
        case VariableType::unknown:
            messageError("Unknown variable type");
        }
    }

    infile.close();
}

void MangroveTraceReader::_readBooleans(BooleanVariable *var, ifstream &infile,
                                        size_t length) {
    int token = 0;
    for (size_t i = 0; i < length; ++i) {
        infile >> token;
        var->assign(i, (token == 1));
    }
}

void MangroveTraceReader::_readLogics(LogicVariable *var, ifstream &infile,
                                      size_t length) {
    string token;
    for (size_t i = 0; i < length; ++i) {
        infile >> token;
        if (var->getSize() != token.size()) {
            std::cout << var->getSize() << "!=" << token.size() << "\n";
            messageError(
                "Logical trace value size is not equal to declaration!");
        }
        Logic l(token);
        var->assign(i, l);
    }
}

void MangroveTraceReader::_readNumeric(NumericVariable *var, ifstream &infile,
                                       size_t length) {
    Numeric token = 0;
    for (size_t i = 0; i < length; ++i) {
        infile >> token;
        var->assign(i, token);
    }
}

} // namespace modules
// namespace modules
} // namespace oden
