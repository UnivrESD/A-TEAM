#include "oden/modules/PropertyQualifier.hh"
#include "oden/odenUtils/applicationUtils.hh"

namespace oden {
namespace modules {

PropertyQualifier::PropertyQualifier(XmlNode *data) : configuration(nullptr) {
    if (data == nullptr)
        messageError("Invalid XML::Node object for PropertyPrinter class");

    configuration = data;
}

} // namespace modules
} // namespace oden
