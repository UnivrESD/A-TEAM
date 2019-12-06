#include "ModuleManager.hh"
#include "oden/modules/default/MangroveTraceReader.hh"
#include "oden/odenUtils/odenUtils.hh"

#include <cstdlib>

//==== Modules =================================================================
#include "AteamMiner.hh"
#include "BooleanVariables.hh"
#include "FaultBasedQualifier.hh"
#include "ManualDefinition.hh"
#include "PSLPrinter.hh"
#include "TBPropositionMiner.hh"
//------------------------------------------------------------------------------

using namespace oden::modules;

namespace assertionMiner {

ConeMiner *ModuleManager::getConeMiner(XmlNode *data) {
    if (data == nullptr)
        return nullptr;

    std::string name = getAttributeValue(data, "name");
    if (name == "manualDefinition") {
        manualDefinition::ManualDefinition *mDefinition;
        mDefinition = new manualDefinition::ManualDefinition(data);
        return static_cast<ConeMiner *>(mDefinition);
    }

    messageError("Unknown staticAnalyzer module.");
    return nullptr;
}

TraceReader *ModuleManager::getTraceReader(XmlNode *data) {
    if (data == nullptr)
        return nullptr;


    std::string name = getAttributeValue(data, "name");
    if (name == "mangroveTraceReader") {
        MangroveTraceReader *mTReader;
        mTReader = new MangroveTraceReader(data);
        return static_cast<TraceReader *>(mTReader);
    }

    messageError("Unknown traceReader module.");
    return nullptr;
}

PropositionMiner *ModuleManager::getAtomicPropositionsMiner(XmlNode *data) {
    if (data == nullptr)
        return nullptr;

    std::string name = getAttributeValue(data, "name");
    if (name == "booleanVariables") {
        booleanVariables::BooleanVariables *vars;
        vars = new booleanVariables::BooleanVariables(data);
        return static_cast<PropositionMiner *>(vars);
    } else if (name == "TBMiner") {
        tbPropositionMiner::TBPropositionMiner *tbminer;
        tbminer = new tbPropositionMiner::TBPropositionMiner(data);
        return static_cast<PropositionMiner *>(tbminer);
    }

    messageError("Unknown proposition miner module.");
    return nullptr;
}

PropertyMiner *ModuleManager::getPropertyMiner(XmlNode *data) {
    if (data == nullptr)
        return nullptr;

    std::string name = getAttributeValue(data, "name");
    if (name == "A-teamMiner") {
        ateam::AteamMiner *ateam;
        ateam = new ateam::AteamMiner(data);
        return static_cast<PropertyMiner *>(ateam);
    }

    messageError("Unknown PropertyMiner module.");
    return nullptr;
}

PropertyQualifier *ModuleManager::getPropertyQualifier(XmlNode *data) {
    if (data == nullptr)
        return nullptr;

    std::string name = getAttributeValue(data, "name");
    if (name == "FBQualifier") {
        faultBasedQualifier::FaultBasedQualifier *qualifier;
        qualifier = new faultBasedQualifier::FaultBasedQualifier(data);
        return static_cast<PropertyQualifier *>(qualifier);
    }

    messageError("Unknown PropertyQualifier module.");
    return nullptr;
}

PropertyPrinter *ModuleManager::getPropertyPrinter(XmlNode *data) {
    if (data == nullptr)
        return nullptr;

    std::string name = getAttributeValue(data, "name");
    if (name == "psl") {
        pslPrinter::PSLPrinter *printer;
        printer = new pslPrinter::PSLPrinter(data);
        return static_cast<PropertyPrinter *>(printer);
    }

    messageError("Unknown PropertyPrinter module.");
    return nullptr;
}

} // namespace assertionMiner
