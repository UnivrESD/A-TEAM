#include "ManualDefinition.hh"

#include "antlr4-runtime.h"
#include "propositionLexer.h"
#include "propositionParser.h"

#include "oden/odenUtils/applicationUtils.hh"
#include "oden/odenUtils/xmlUtils.hh"
#include "oden/parser/PropositionParser.hh"

#include "oden/classes/classes.hh"
#include "oden/odenUtils/propositionUtils.hh"

#include <algorithm>
#include <set>

using namespace oden;

namespace manualDefinition {

ManualDefinition::ManualDefinition(XmlNode *xmlNode)
    : ConeMiner(xmlNode), _conesList(), _name2Dir() {

    XmlNode *directionsXml = configuration->first_node("directions");
    //    messageErrorIf(directionsXml == nullptr, "XML tag 'directions' must be
    //    defined!");

    if (directionsXml != nullptr) {
        XmlNodeList directionList;
        getNodesFromName(directionsXml, "direction", directionList);
    }
    /*
    messageErrorIf(directionList.empty(), "Direction list is empty!");

    _fillName2Dir(directionList);

    */
    getNodesFromName(configuration, "coneOfInfluence", _conesList);
}

void ManualDefinition::mineCones(TraceRepository &traceRepo,
                                 List<ConeOfInfluence> &cones) {
    Trace &trace = traceRepo[0];

    // if no cone is specified, create a Cone with all the input/output
    // variables as propositions
    if (_conesList.empty()) {

        /*
        messageWarning("No cone defined! A cone with all available boolean "
                       "varibles will be generated!\n");
        ConeOfInfluence *cone = new ConeOfInfluence("noCone");

        const Name2Variable &vars = traceRepo.getVariables();
        // fill noCone directions with all variable directions
        for (auto &var : vars) {
            _name2Dir[var.first] = var.second->getDirection();
        }

        for (auto &kv : vars) {

            if (kv.second->getType() == VariableType::boolean) {
                auto *newVar = new DataType(*(kv.second));

                auto currentVar = _name2Dir.find(kv.first);

                Proposition *p = trace.getBooleanVariable(currentVar->first);

                if (currentVar != _name2Dir.end()) {
                    std::string propName = oden::prop2String(*p);
                    switch (currentVar->second) {
                    case VariableDirection::dir_in:
                        cone->inPropositions.push_back(oden::copy(*p));
                        break;
                    case VariableDirection::dir_inout:
                        cone->inoutPropositions.push_back(oden::copy(*p));
                        break;
                    case VariableDirection::dir_out:
                        cone->propositions.push_back(oden::copy(*p));
                        break;
                    default:
                        delete p;
                        break;
                    }
                }
            }
        } // end for kv
        cones.push_back(cone);
        return;
        */

        // Not defining a cone of influence is no longer supported!
        messageError("Not defining a cone of influce is no longer supported!");

    } // end if coneList

    for (auto *coneXml : _conesList) {
        std::string coneName = getAttributeValue(coneXml, "name");
        messageErrorIf(coneName.empty(),
                       "Cone of influence does not have a name!");

        auto *newCone = new ConeOfInfluence(coneName);

        //(1) get single variable propositions
        XmlNode *directionsXml = coneXml->first_node("directions");
        XmlNodeList directionList;
        getNodesFromName(directionsXml, "direction", directionList);
        for (auto *directionXml : directionList) {
            std::string variableName = getAttributeValue(directionXml, "name");
            if (variableName.empty())
                messageError("Name of the variable not found");

            std::string directionStr = getAttributeValue(directionXml, "dir");
            if (directionStr.empty())
                messageError("direction not found");

            VariableDirection direction =
                oden::variableDirectionFromString(directionStr);
            Proposition *p = trace.getBooleanVariable(variableName);
            switch (direction) {
            case VariableDirection::dir_in:
                newCone->inPropositions.push_back(oden::copy(*p));
                break;
            case VariableDirection::dir_inout:
//                newCone->inoutPropositions.push_back(oden::copy(*p));
                newCone->inPropositions.push_back(oden::copy(*p));
                newCone->propositions.push_back(oden::copy(*p));
                break;
            case VariableDirection::dir_out:
                newCone->propositions.push_back(oden::copy(*p));
                break;
            }
            delete p;
        }

        //(2) get complex manually defined propositions
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
        std::cout << tree->toStringTree(&parser) << std::endl;


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
//            cone.inoutPropositions.push_back(oden::copy(*p));
            cone.inPropositions.push_back(oden::copy(*p));
            cone.propositions.push_back(oden::copy(*p));
            break;
        }
        case VariableDirection::dir_out: {
            // cone.outPropositions.push_back(oden::copy(*p));
            cone.propositions.push_back(oden::copy(*p));
            break;
        }
            delete p;
        }
    }
}

} // namespace manualDefinition
