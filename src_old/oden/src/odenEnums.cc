#include "oden/odenEnums.hh"
#include "oden/odenUtils/applicationUtils.hh"

namespace oden {

std::string variableTypeToString(const VariableType t) {
    switch (t) {
    case VariableType::logic:
        return "logic";
    case VariableType::numeric:
        return "numeric";
    case VariableType::boolean:
        return "boolean";
    case VariableType::unknown:
        return "unknown";
    default:
        messageError("Unknown variable type");
    }
    return "";
}

VariableType variableTypeFromString(const std::string &s) {
    if (s == "logic")
        return VariableType::logic;
    if (s == "numeric")
        return VariableType::numeric;
    if (s == "bool" || s == "boolean")
        return VariableType::boolean;

    return VariableType::unknown;
}

std::string variableDirectionToString(const VariableDirection t) {
    switch (t) {
    case VariableDirection::dir_in:
        return "in";
    case VariableDirection::dir_out:
        return "out";
    case VariableDirection::dir_inout:
        return "inout";
    default:
        messageError("Unknown variable direction.");
    }
    return "";
}

VariableDirection variableDirectionFromString(const std::string &s) {
    if (s == "in" || s == "IN")
        return VariableDirection::dir_in;
    if (s == "out" || s == "OUT")
        return VariableDirection::dir_out;
    if (s == "inout" || s == "INOUT")
        return VariableDirection::dir_inout;
    return VariableDirection::dir_inout;
}

} // namespace oden
