include(FindPackageHandleStandardArgs)

find_library(ANTLR4_RUNTIME NAMES antlr4-runtime PATHS ./libs/lib/antlr4/lib)

if (NOT ANTLR4_RUNTIME)
    find_library(ANTLR4_RUNTIME NAMES antlr4-runtime PATHS ./libs/antlr4/.libs)
endif ()

find_path(ANTLR4CPP_INCLUDE_DIRS
    PATHS ./libs/lib/antlr4/include/runtime/Cpp/runtime/src
    NAMES antlr4-runtime.h
    DOC "ANTLR4 C++ headers"
    )
if (NOT ANTLR4CPP_INCLUDE_DIRS)
    find_path(ANTLR4CPP_INCLUDE_DIRS
        PATHS ./libs/antlr4/runtime/Cpp/runtime/src
        NAMES antlr4-runtime.h
        DOC "ANTLR4 C++ headers"
        )
endif ()

if (NOT ANTLR4_RUNTIME)
    message(STATUS "Could not find ANTLR-RUNTIME library")
else()
    message(STATUS "Found ANTLR4_RUNTIME:" ${ANTLR4_RUNTIME})
endif ()

if (NOT ANTLR4CPP_INCLUDE_DIRS)
    message(STATUS "Could not find C++ ANTLR include path")
endif ()

find_package_handle_standard_args(ANTLR4 REQUIRED_VARS ANTLR4CPP_INCLUDE_DIRS ANTLR4_RUNTIME)
