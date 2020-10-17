#include "CommandLineReader.hh"
#include <iostream>

using namespace std;

namespace assertionMiner {

void CommandLineReader::_printUsage() {
    cout << "Usage: a-team configuration_file.xml Trace.vcd" << endl;
    exit(EXIT_FAILURE);
}

CommandLineReader::CommandLineReader(int argc, char *argv[])
    : _xmlFile(nullptr), _doc(nullptr) {
    if (argc != 3)
        _printUsage();

    _validateFile(argv[1]);
    _vcdFile=std::string(argv[2]);
}

CommandLineReader::~CommandLineReader() {
    delete _xmlFile;
    delete _doc;
}

void CommandLineReader::_validateFile(const char *xmlFile) {
    try {
        _xmlFile = new rapidxml::file<>(xmlFile);
        _doc     = new rapidxml::xml_document<>();
        _doc->parse<0>(_xmlFile->data());
    } catch (exception &e) {
        std::cout << "Parsing error with xml file: " << xmlFile << ". "
                  << "Reason: " << e.what() << endl;
        exit(1);
    }
}

const std::string CommandLineReader::getVCDfile(){
    return _vcdFile;
}

XmlNode *CommandLineReader::getConeMinerNode() {
    XmlNode *root_node = _doc->first_node("root");
    if (root_node == nullptr)
        return nullptr;

    root_node = root_node->first_node("coneminer");
    return root_node;
}

XmlNode *CommandLineReader::getTraceReaderNode() {
    XmlNode *root_node = _doc->first_node("root");
    if (root_node == nullptr)
        return nullptr;

    root_node = root_node->first_node("tracereader");
    return root_node;
}

XmlNode *CommandLineReader::getPropositionMinerNode() {
    XmlNode *root_node = _doc->first_node("root");
    if (root_node == nullptr)
        return nullptr;

    root_node = root_node->first_node("propositionminer");
    return root_node;
}

XmlNode *CommandLineReader::getPropertyMinerNode() {
    XmlNode *root_node = _doc->first_node("root");
    if (root_node == nullptr)
        return nullptr;

    root_node = root_node->first_node("propertyminer");
    return root_node;
}

XmlNode *CommandLineReader::getPropertyQualifierNode() {
    XmlNode *root_node = _doc->first_node("root");
    if (root_node == nullptr)
        return nullptr;

    root_node = root_node->first_node("propertyQualifier");
    return root_node;
}

XmlNode *CommandLineReader::getPropertyPrinterNode() {
    XmlNode *root_node = _doc->first_node("root");
    if (root_node == nullptr)
        return nullptr;

    root_node = root_node->first_node("propertyprinter");
    return root_node;
}

} // namespace assertionMiner
