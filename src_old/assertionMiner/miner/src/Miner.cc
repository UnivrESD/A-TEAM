#include "Miner.hh"
#include "oden/Checker.hh"
#include "oden/classes/TraceRepository.hh"
#include "oden/odenUtils/applicationUtils.hh"
#include <iostream>

#include "oden/classes/classes.hh"

namespace assertionMiner {

Miner::Config_t::Config_t()
    : welcomeMessage(false), traceReader(nullptr), coneMiner(nullptr),
      propositionMiner(nullptr), propertyMiner(nullptr),
      propertyQualifier(nullptr), propertyPrinter(nullptr) {
    // ntd
}

Miner::Config_t::~Config_t() {
    delete traceReader;
    delete coneMiner;
    delete propositionMiner;
    delete propertyMiner;
    delete propertyQualifier;
    delete propertyPrinter;
}

Miner::Miner(Config_t &configuration) : _config(configuration) {
    // ntd
}

void Miner::run() {
    messageInfo("Miner started...");
    if (_config.welcomeMessage)
        _printWelcomeMessage();

    List<ConeOfInfluence> cones;

    //==== step 1) Read simulation traces ======================================
    messageErrorIf(_config.traceReader == nullptr,
                   "Trace reader module has not been set!");
    TraceRepository *traceRepo = _config.traceReader->readTraces();
    //--------------------------------------------------------------------------

    //==== step 2) Define cone of influences ===================================
    messageErrorIf(_config.coneMiner == nullptr,
                   "ConeMiner module has not been set!");
    _config.coneMiner->mineCones(*traceRepo, cones);
    //--------------------------------------------------------------------------

    // for each cone of influence
    for (ConeOfInfluence *cone : cones) {
        messageInfo("Getting assertions for the cone: " + cone->name);

        //==== step 3) Mine logic propositions =================================
        if (_config.propositionMiner == nullptr)
            messageWarning("No propositionMiner module has been set");
        else
            _config.propositionMiner->minePropositions(*cone, *traceRepo);
        //----------------------------------------------------------------------

        //==== step 4) Mine temporal assertions
        if (_config.propertyMiner == nullptr)
            messageWarning("No propertyMiner module has been set");
        else
            _config.propertyMiner->mineProperties(*cone, *traceRepo);
        //----------------------------------------------------------------------

        //==== step 5) Qualify the mined temporal assertions
        if (_config.propertyQualifier == nullptr)
            messageWarning("No propertyQualifier module has been set");
        else
            _config.propertyQualifier->qualify(*cone);
        //----------------------------------------------------------------------

        //==== step 6) Print the mined temporal assertions
        if (_config.propertyPrinter == nullptr)
            messageWarning("No propertyPrinter module has been set");
        else
            _config.propertyPrinter->print(*cone);
        //----------------------------------------------------------------------

        /*
        Checker checker;
        for (Assertion *a : cone->assertions)
            messageErrorIf(!checker.evaluate(*a, *traceRepo),
                           "Checking mined assertion failed!");
                           */
    }
    delete traceRepo;
}

void Miner::_printWelcomeMessage() {
    std::cout << "   ____  _____  ______ _   _        ___" << std::endl;
    std::cout << "  / __ \\|  __ \\|  ____| \\ | |      |__ \\" << std::endl;
    std::cout << " | |  | | |  | | |__  |  \\| | __   __ ) |" << std::endl;
    std::cout << " | |  | | |  | |  __| | . ` | \\ \\ / // /" << std::endl;
    std::cout << " | |__| | |__| | |____| |\\  |  \\ V // /_" << std::endl;
    std::cout << "  \\____/|_____/|______|_| \\_|   \\_/|____|" << std::endl
              << std::endl;
}

} // namespace assertionMiner
