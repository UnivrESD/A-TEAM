#include "ManualDefinition.hh"

#include "antlr4-runtime.h"
#include "propositionLexer.h"
#include "propositionParser.h"

#include "oden/odenUtils/applicationUtils.hh"
#include "oden/odenUtils/xmlUtils.hh"
#include "oden/parser/PropositionParser.hh"

#include "oden/classes/classes.hh"
#include "oden/odenUtils/propositionUtils.hh"

#include <set>

using namespace oden;

namespace manualDefinition {

ManualDefinition::ManualDefinition(XmlNode *xmlNode)
    : ConeMiner(xmlNode), _conesList(), _name2Dir() {

    XmlNode *directionsXml = configuration->first_node("directions");
    messageErrorIf(directionsXml == nullptr,
                   "XML tag 'directions' must be defined!");

    XmlNodeList directionList;
    getNodesFromName(directionsXml, "direction", directionList);
    messageErrorIf(directionList.empty(), "Direction list is empty!");

    _fillName2Dir(directionList);

    getNodesFromName(configuration, "coneOfInfluence", _conesList);
}

void ManualDefinition::mineCones(TraceRepository &traceRepo,
                                 List<ConeOfInfluence> &cones) {
    Trace &trace = traceRepo[0];

    // if no cone is specified, create a Cone with all the input/output
    // variables as propositions
    if (_conesList.empty()) {
        messageWarning("No cone defined! A cone with only boolean varibles will be generated\n");
        ConeOfInfluence *cone = new ConeOfInfluence("noCone");

        const Name2Variable &vars = traceRepo.getVariables();
        for (auto &kv : vars) {

            if (kv.second->getType() == VariableType::boolean) {
                if (_name2Dir.find(kv.first) == _name2Dir.end()) {

                    messageWarning("Direction not defined for variable '" +
                            kv.first + "', the variable will be "
                            "discarded!\nHint: add the variable "
                            "direction in the xml file\n");
                    continue;
                }
                auto *newVar = new DataType(*(kv.second));

                auto currentVar = _name2Dir.find(kv.first);

                Proposition *p = trace.getBooleanVariable(currentVar->first);
                cone->propositions.push_back(p);

                if (currentVar != _name2Dir.end()) {
                    switch (currentVar->second) {
                    case VariableDirection::dir_in: {
                        cone->inPropositions.push_back(oden::copy(*p));
                        break;
                    }
                    case VariableDirection::dir_inout: {
                        cone->inoutPropositions.push_back(oden::copy(*p));
                        break;
                    }
                    case VariableDirection::dir_out: {
                        cone->outPropositions.push_back(oden::copy(*p));
                        break;
                    }
                    }
                }
            }
        }
        cones.push_back(cone);
        return;
    }

    for (auto *coneXml : _conesList) {
        std::string coneName = getAttributeValue(coneXml, "name");
        messageErrorIf(coneName.empty(),
                       "Cone of influence does not have a name!");

        auto *newCone = new ConeOfInfluence(coneName);

        XmlNode *atPropsXml = coneXml->first_node("atomicPropositions");
        if (atPropsXml != nullptr) {
            XmlNodeList atPropsList;
            getNodesFromName(atPropsXml, "atomicProposition", atPropsList);
            fillConeWithAtomicPropositions(traceRepo, atPropsList, *newCone);
        }

        messageInfo("The cone: " + coneName + " has been created");
        cones.push_back(newCone);
    }
}

void ManualDefinition::_fillName2Dir(XmlNodeList &directionList) {

    for (auto *directionXml : directionList) {
        std::string variableName = getAttributeValue(directionXml, "name");
        messageErrorIf(variableName.empty(), "Name of the variable not found!");

        std::string directionStr = getAttributeValue(directionXml, "dir");
        messageErrorIf(directionStr.empty(), "direction not found!");

        VariableDirection direction = variableDirectionFromString(directionStr);
        _name2Dir[variableName]     = direction;
    }
}

void ManualDefinition::fillConeWithAtomicPropositions(
    TraceRepository &traceRepo, XmlNodeList &atomicPropsList,
    ConeOfInfluence &cone) {

    for (auto *atomicProp : atomicPropsList) {
        std::string atProp       = getAttributeValue(atomicProp, "formula");
        std::string directionStr = getAttributeValue(atomicProp, "dir");

        messageErrorIf(atProp.empty(), "formula not found!");
        messageErrorIf(directionStr.empty(), "Formula's direction not found!");

        antlr4::ANTLRInputStream input(atProp);

        propositionLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        propositionParser parser(&tokens);
        tree::ParseTree *tree = parser.file();
        oden::PropositionParser listener(traceRepo.getVariables(),
                                         traceRepo[0]);
        tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
        std::cout << tree->toStringTree(&parser) << "\n";

        Proposition *p = listener.getProposition();
        messageErrorIf(p == nullptr, "Not valid atomic proposition: " +
                                         tree->toStringTree(&parser));

        messageInfo("PROPOSITION: " + oden::prop2String(*p));

        VariableDirection direction = variableDirectionFromString(directionStr);

        switch (direction) {
        case VariableDirection::dir_in: {
            cone.inPropositions.push_back(oden::copy(*p));
            break;
        }
        case VariableDirection::dir_inout: {
            cone.inoutPropositions.push_back(oden::copy(*p));
            break;
        }
        case VariableDirection::dir_out: {
            // cone.outPropositions.push_back(oden::copy(*p));
            cone.propositions.push_back(p);
            break;
        }
        }
    }
}

} // namespace manualDefinition
