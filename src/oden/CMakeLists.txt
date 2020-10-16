#############################################
# Configuration.
#############################################

project(oden)


include_directories(./include
        ${propositionParser_SOURCE_DIR}/include
        ${PYTHON_INCLUDE_DIRS}
        SYSTEM ${MINER_EXTERNAL_HEADERS})

#############################################
# Sources.
#############################################

SET(BASE_SRCS
        src/odenEnums.cc
        src/types.cc
        src/Checker.cc
        src/parser/PropositionParser.cc
        )

SET(VISITORS_SRC
        src/OdenVisitor.cc
        src/visitors/PrinterVisitor.cc
        src/visitors/DepthVisitor.cc
        src/visitors/CopyVisitor.cc
        src/visitors/PeTraceChanger.cc
        )

SET(UTILS_SRCS
        src/odenUtils/applicationUtils.cc
        src/odenUtils/xmlUtils.cc
        src/odenUtils/propositionUtils.cc
        src/odenUtils/templateUtils.cc
        )

SET(CLASSES_SRCS
        src/classes/atom/Constant.cc
        src/classes/atom/BooleanVariable.cc
        src/classes/atom/NumericVariable.cc
        src/classes/atom/LogicVariable.cc
        src/classes/expression/Expression.cc
        src/classes/expression/BitSelector.cc
        src/classes/expression/TypeCast.cc
        src/classes/temporal/NextOperator.cc
        src/classes/temporal/PastOperator.cc
        src/classes/temporal/UntilOperator.cc
        src/classes/temporal/ReleaseOperator.cc
        #others
        src/classes/Logic_t.cc
        src/classes/ConeOfInfluence.cc
        src/classes/DataType.cc
        src/classes/TraceRepository.cc
        src/classes/Trace.cc
        )

SET(MODULES_SRCS
        src/modules/TraceReader.cc
        src/modules/ConeMiner.cc
        src/modules/PropositionMiner.cc
        src/modules/PropertyMiner.cc
        src/modules/PropertyPrinter.cc
        src/modules/PropertyQualifier.cc
        src/modules/default/MangroveTraceReader.cc
        )

#### All the previous ####
SET(ALL_ODEN_SRCS
        ${BASE_SRCS}
        ${CLASSES_SRCS}
        ${UTILS_SRCS}
        ${MODULES_SRCS}
        ${VISITORS_SRC}
        )

#############################################
# Targets.
#############################################
add_library(oden ${ALL_ODEN_SRCS})
target_link_libraries(oden propositionParser)

#############################################
# Install.
#############################################
install(TARGETS oden
        RUNTIME DESTINATION oden/lib
        LIBRARY DESTINATION oden/lib
        ARCHIVE DESTINATION oden/lib)

install(DIRECTORY include
        DESTINATION oden)
