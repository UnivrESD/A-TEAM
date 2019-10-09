#include "oden/modules/PropertyMiner.hh"
#include "oden/odenUtils/applicationUtils.hh"

namespace oden {
namespace modules {

PropertyMiner::PropertyMiner(XmlNode *data) : configuration(nullptr) {
    if (data == nullptr)
        messageError("Invalid XML::Node object for PropertyMiner class");

    configuration = data;
}

} // namespace modules
} // namespace oden
