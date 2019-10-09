#############################################
# Configuration.
#############################################

SET(NAME manualDefinition)
project(${NAME})

include_directories(include/
        ${oden_SOURCE_DIR}/include
        SYSTEM ${MINER_EXTERNAL_HEADERS}
        SYSTEM ${propositionParser_SOURCE_DIR}/include)

#############################################
# Sources.
#############################################
SET(MANUALDEFINITION_SRC
        src/ManualDefinition.cc)

#############################################
# Targets.
#############################################
add_library(${NAME} ${MANUALDEFINITION_SRC})
