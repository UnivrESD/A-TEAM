#############################################
# Configuration.
#############################################

SET(NAME propositionParser)

project(${NAME})

include_directories(include/
    ${ANTLR4CPP_INCLUDE_DIRS})

#############################################
# Sources.
#############################################
SET (PARSER_SRCS
        src/propositionLexer.cpp
        src/propositionParser.cpp
        src/propositionListener.cpp
        src/propositionBaseListener.cpp)

#############################################
# Targets.
#############################################
add_library(${NAME} ${PARSER_SRCS})
target_link_libraries(${NAME} ${ANTLR4_RUNTIME})
