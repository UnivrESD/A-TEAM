#############################################
# Configuration.
#############################################

SET(NAME tbPropositionMiner)
project(${NAME})

include_directories(include/
        ${oden_SOURCE_DIR}/include
        SYSTEM ${MINER_EXTERNAL_HEADERS})

#############################################
# Sources.
#############################################

SET(BTBPROPOSITIONMINER_SRC
        src/TBPropositionMiner.cc)

#############################################
# Targets.
#############################################
add_library(${NAME} ${BTBPROPOSITIONMINER_SRC})

