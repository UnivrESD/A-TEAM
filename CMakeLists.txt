# Checking cmake version:
PROJECT(A-Team)
cmake_minimum_required(VERSION 2.8.11)

set(ODEN_VERSION_MAJOR 1)
set(ODEN_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#############################################################################
# Basic configuration.
#############################################################################
#if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#    include("cmake/ConfigureCompilerClang.cmake")
#elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
#    include("cmake/ConfigureCompilerGcc.cmake")
#else ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
#    message(FATAL_ERROR "Only the compiler gcc and clang are supported")
#endif()

include(FindPackageHandleStandardArgs)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

################################################################################
# Installation
################################################################################
SET(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install CACHE PATH "Reset install
dir" FORCE)

################################################################################
# External libraries
################################################################################

find_package(Z3 QUIET)
if (${Z3_FOUND})
    add_definitions(-DZ3_FOUND)
    list(APPEND MINER_EXTERNAL_HEADERS ${Z3_INCLUDE_DIRS})
    list(APPEND MINER_EXTERNAL_LIBRARIES ${Z3_LIBRARY})
endif ()

find_package(ANTLR REQUIRED)
list(APPEND MINER_EXTERNAL_HEADERS ${ANTLR4CPP_INCLUDE_DIRS})
list(APPEND MINER_EXTERNAL_LIBRARIES ${ANTLR4_RUNTIME})

find_package(SPOTLTL REQUIRED)
list(APPEND MINER_EXTERNAL_HEADERS ${SPOTLTL_CPP_INCLUDE_DIR})
list(APPEND MINER_EXTERNAL_LIBRARIES ${SPOTLTL_LIBRARY})

################################################################################
# Targets.
################################################################################
#ODEN Library
add_subdirectory(antlr4_grammar)
add_subdirectory(src/oden)
add_subdirectory(src/assertionMiner)

################################################################################
# Test.
################################################################################
enable_testing()
add_subdirectory(tests)


