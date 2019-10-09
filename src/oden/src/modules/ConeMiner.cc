#include "oden/modules/ConeMiner.hh"
#include "oden/odenUtils/applicationUtils.hh"

namespace oden {
namespace modules {

ConeMiner::ConeMiner(XmlNode *data) : configuration(nullptr) {
    if (data == nullptr)
        messageError("Invalid XML::Node object for ConeMiner class");

    configuration = data;
}

} // namespace modules
} // namespace oden
