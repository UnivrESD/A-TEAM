#############################################
# Configuration.
#############################################

SET(NAME ateam)

project(${NAME})

include_directories(include/
        ${oden_SOURCE_DIR}/include
        SYSTEM ${MINER_EXTERNAL_HEADERS})

#############################################
# Sources.
#############################################
SET(ATEAMPROPERTYMINER_SRC
        src/AteamMiner.cc
        src/ContingencyTable.cc
        src/supportTypes.cc
        src/supportMethods.cc
        src/AntecedentGenerator.cc
        src/FaultChecker.cc
        src/SetsGenerator.cc)

#############################################
# Targets.
#############################################
add_library(${NAME} ${ATEAMPROPERTYMINER_SRC})


