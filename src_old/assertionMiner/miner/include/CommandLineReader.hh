#pragma once

#include "oden/odenUtils/rapidxml/rapidxml_utils.hh"
#include "oden/types.hh"

using namespace oden;

namespace assertionMiner {

class CommandLineReader {

  public:
    CommandLineReader(int argc, char *argv[]);

    /// @brief Unsupported constructor.
    CommandLineReader(const CommandLineReader &other) = delete;

    ~CommandLineReader();

    XmlNode *getConeMinerNode();
    XmlNode *getTraceReaderNode();
    XmlNode *getPropositionMinerNode();
    XmlNode *getPropertyMinerNode();
    XmlNode *getPropertyQualifierNode();
    XmlNode *getPropertyPrinterNode();
    const std::string getVCDfile();

    CommandLineReader &operator=(const CommandLineReader &other) = delete;

  private:
    rapidxml::file<> *_xmlFile;
    rapidxml::xml_document<> *_doc;
    std::string _vcdFile;

    void _printUsage();
    void _validateFile(const char *xmlFile);
};

} // namespace assertionMiner
