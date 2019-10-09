#############################################
# Configuration.
#############################################

SET(NAME propositionParser)

project(${NAME})

include_directories(include/
                    SYSTEM /usr/local/include/antlr4-runtime)

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
target_link_libraries(${NAME} antlr4-runtime)
