#include "BooleanVariables.hh"

using namespace oden;

namespace booleanVariables {

BooleanVariables::BooleanVariables(XmlNode *data)
    : modules::PropositionMiner(data) {
    // ntd
}

void BooleanVariables::minePropositions(ConeOfInfluence &cone,
                                        TraceRepository &traceRepository) {
    /*
    Trace &trace = traceRepository[0];

    for (DataType *dt : cone.variables) {
        if (dt->getType() != VariableType::boolean)
            continue;

        Proposition *p = trace.getBooleanVariable(dt->getName());

        switch (dt->getDirection()) {
        case VariableDirection::dir_in: {
            cone.inPropositions.push_back(p);
            break;
        }

        case VariableDirection::dir_out: {
            cone.outPropositions.push_back(p);
            break;
        }

        case VariableDirection::dir_inout:
        default: {
            // ntd
        }
        }
    }
    */
}

} // namespace booleanVariables
