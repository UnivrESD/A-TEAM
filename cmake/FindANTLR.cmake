include(FindPackageHandleStandardArgs)

# Try to find c++ headers
find_path(ANTLR4CPP_INCLUDE_DIRS
        NAMES antlr4-runtime.h
        PATH_SUFFIXES antlr4-runtime
        DOC "ANTLR4 C++ headers"
        )

if (NOT ANTLR4CPP_INCLUDE_DIRS)
    message(STATUS "Could not find C++ ANTLR include path")
endif ()

find_package_handle_standard_args(ANTLR4 REQUIRED_VARS ANTLR4CPP_INCLUDE_DIRS)