#pragma once

#include "oden/modules/modules.hh"
#include "oden/types.hh"

using namespace oden;

namespace assertionMiner {

class ModuleManager {

  public:
    ModuleManager()  = default;
    ~ModuleManager() = default;

    modules::ConeMiner *getConeMiner(XmlNode *data);
    modules::TraceReader *getTraceReader(XmlNode *data,const std::string &vcdFile);
    modules::PropositionMiner *getAtomicPropositionsMiner(XmlNode *data);
    modules::PropertyMiner *getPropertyMiner(XmlNode *data);
    modules::PropertyQualifier *getPropertyQualifier(XmlNode *data);
    modules::PropertyPrinter *getPropertyPrinter(XmlNode *data);
};

} // namespace assertionMiner
