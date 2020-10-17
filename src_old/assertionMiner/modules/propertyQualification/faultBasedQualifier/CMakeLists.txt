#############################################
# Configuration.
#############################################

SET(NAME faultBasedQualifier)
project(${NAME})

include_directories(include/
        ${oden_SOURCE_DIR}/include
        SYSTEM ${MINER_EXTERNAL_HEADERS})

#############################################
# Sources.
#############################################

SET(FAULTBASEDQUALIFIER_SRC
        src/FaultBasedQualifier.cc)

#############################################
# Targets.
#############################################
add_library(${NAME} ${FAULTBASEDQUALIFIER_SRC})
