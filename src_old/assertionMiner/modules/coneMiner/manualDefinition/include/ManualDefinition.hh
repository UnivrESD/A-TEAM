#pragma once

#include "oden/modules/ConeMiner.hh"
#include "oden/types.hh"

#include <map>
#include <string>

using namespace oden;

namespace manualDefinition {

class ManualDefinition : public modules::ConeMiner {

  public:
    explicit ManualDefinition(XmlNode *xmlNode);
    ~ManualDefinition() override = default;

    void mineCones(TraceRepository &traceRepo,
                   List<ConeOfInfluence> &cones) override;

  private:
    XmlNodeList _conesList;

    std::map<std::string, VariableDirection> _name2Dir;

    void _fillName2Dir(XmlNodeList &directionList);
    void _fillConeWithVariables(TraceRepository &traceRepo,
                                XmlNodeList &variablesList,
                                ConeOfInfluence &cone);

    void fillConeWithAtomicPropositions(TraceRepository &traceRepo,
                                        XmlNodeList &atomicPropsList,
                                        ConeOfInfluence &cone);
};

} // namespace manualDefinition
