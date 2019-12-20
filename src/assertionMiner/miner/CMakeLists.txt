#############################################
# Configuration.
#############################################

SET(NAME a-team)
project(${NAME})

include_directories(include/
        ${oden_SOURCE_DIR}/include
        ${manualDefinition_SOURCE_DIR}/include
        ${pslPrinter_SOURCE_DIR}/include
        ${ateam_SOURCE_DIR}/include
        ${booleanVariables_SOURCE_DIR}/include
        ${tbPropositionMiner_SOURCE_DIR}/include
        ${faultBasedQualifier_SOURCE_DIR}/include
        SYSTEM ${MINER_EXTERNAL_HEADERS})

#############################################
# Sources.
#############################################

set(MINER_SRC
        src/main.cc
        src/ModuleManager.cc
        src/Miner.cc
        src/CommandLineReader.cc)

#############################################
# Targets.
#############################################
add_executable(${NAME} ${MINER_SRC})
target_link_libraries(${NAME}
        manualDefinition
        pslPrinter
        ateam
        booleanVariables
        tbPropositionMiner
        faultBasedQualifier
        oden
        -pthread
        ${MINER_EXTERNAL_LIBRARIES}
        )

#############################################
# Install.
#############################################
install(TARGETS ${NAME} DESTINATION bin)
