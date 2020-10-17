#############################################
# Configuration.
#############################################

SET(NAME pslPrinter)

project(${NAME})

include_directories(include/
        ${oden_SOURCE_DIR}/include
        SYSTEM ${MINER_EXTERNAL_HEADERS})

#############################################
# Sources.
#############################################

SET(PSLPRINTER_SRC
        src/PSLPrinter.cc
        src/PSLPropositionPrinter.cc)

#############################################
# Targets.
#############################################
add_library(${NAME} ${PSLPRINTER_SRC})
