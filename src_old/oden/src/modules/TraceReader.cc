#include "oden/modules/TraceReader.hh"
#include "oden/odenUtils/applicationUtils.hh"
#include "oden/odenUtils/xmlUtils.hh"

namespace oden {
namespace modules {

TraceReader::TraceReader(XmlNode *data) : configuration(nullptr) {
    if (data == nullptr)
        messageError("Invalid XML::Node object for TraceReader class");

    configuration = data;
}

void TraceReader::fillName2Dir(
    XmlNodeList &directionList,
    std::map<std::string, VariableDirection> &name2Dir) {

    for (auto *directionXml : directionList) {
        std::string variableName = getAttributeValue(directionXml, "name");
        if (variableName.empty())
            messageError("Name of the variable not found");

        std::string directionStr = getAttributeValue(directionXml, "dir");
        if (directionStr.empty())
            messageError("direction not found");

        VariableDirection direction =
            oden::variableDirectionFromString(directionStr);
        name2Dir[variableName] = direction;
    }
}

} // namespace modules
} // namespace oden
