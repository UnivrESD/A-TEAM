
#include "CommandLineReader.hh"
#include "Miner.hh"
#include "ModuleManager.hh"

using namespace assertionMiner;

ModuleManager manager;
Miner::Config_t config;

int main(int arg, char *argv[]) {
    CommandLineReader cmdReader(arg, argv);

    config.coneMiner = manager.getConeMiner(cmdReader.getConeMinerNode());

    config.traceReader = manager.getTraceReader(cmdReader.getTraceReaderNode(),cmdReader.getVCDfile());

    config.propositionMiner =
        manager.getAtomicPropositionsMiner(cmdReader.getPropositionMinerNode());

    config.propertyMiner =
        manager.getPropertyMiner(cmdReader.getPropertyMinerNode());

    config.propertyQualifier =
        manager.getPropertyQualifier(cmdReader.getPropertyQualifierNode());

    config.propertyPrinter =
        manager.getPropertyPrinter(cmdReader.getPropertyPrinterNode());

    Miner miner(config);
    miner.run();

    return 0;
}
