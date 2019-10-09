#pragma once

#include "oden/modules/modules.hh"

using namespace oden;

namespace assertionMiner {
/// @brief Miner declaration.
/// This class represents an assertion miner.
/// It consists of:
/// 1) a trace reader reading simulation traces
/// 2) a static analyser generating cone of influence,
/// 3) a proposition miner mining logic propositions among the variables
///    of a cone of influence
/// 4) a temporal assertion miner prosedure mining temporal assertion by combing
///    propositions with temporal operators.
/// 5) a temporal assertion printer printing out the mined assertion in some
///    standard format.

class Miner {

  public:
    /// @brief Config_t declaration.
    /// This class collects a trace reader, a static analyser, a proposition
    /// miner, an assertion miner and an assetions printer
    struct Config_t {
        /// @brief Constructor.
        Config_t();

        /// @brief Destructor.
        ~Config_t();

        /// when set, assertion miner should print a welcome message
        bool welcomeMessage;
        /// a pointer to a trace reader
        modules::TraceReader *traceReader;
        /// a pointer to a cone miner
        modules::ConeMiner *coneMiner;
        /// a pointer to a proposition miner
        modules::PropositionMiner *propositionMiner;
        /// a pointer to an assertion miner
        modules::PropertyMiner *propertyMiner;
        /// a point to a property qualifier
        modules::PropertyQualifier *propertyQualifier;
        /// a pointer to a assertion printer
        modules::PropertyPrinter *propertyPrinter;

        /// @brief Unsupported constructor.
        Config_t(const Config_t &) = delete;

        /// @brief Unsupported operator
        Config_t &operator=(const Config_t &) = delete;
    };

    explicit Miner(Config_t &configuration);
    ~Miner() = default;

    void run();

  private:
    Config_t &_config;

    void _printWelcomeMessage();
};

} // namespace assertionMiner
