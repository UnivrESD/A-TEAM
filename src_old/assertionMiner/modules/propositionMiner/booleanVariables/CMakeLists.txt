#############################################
# Configuration.
#############################################

SET(NAME booleanVariables)
project(${NAME})

include_directories(include/
        ${oden_SOURCE_DIR}/include
        SYSTEM ${MINER_EXTERNAL_HEADERS})

#############################################
# Sources.
#############################################

SET(BOOLEANVARIABLES_SRC
        src/BooleanVariables.cc)

#############################################
# Targets.
#############################################
add_library(${NAME} ${BOOLEANVARIABLES_SRC})

