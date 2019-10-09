set(SPOTLTL_ROOT "" CACHE PATH "Root of SPOTLTL distribution.")

find_library(SPOTLTL_LIBRARY NAMES spot PATHS ${SPOTLTL_ROOT}/lib)

if (NOT SPOTLTL_LIBRARY)
    message(STATUS "Could not find SPOTLTL libraries")
endif ()

# Try to find c++ headers
find_path(SPOTLTL_CPP_INCLUDE_DIR
        NAMES parse.hh print.hh formula.hh
        PATH_SUFFIXES spot/tl
        DOC "SPOTLTL C++ header"
        )

if (SPOTLTL_CPP_INCLUDE_DIR)
    message(STATUS "Found SPOTLTL include directory: " ${SPOTLTL_CPP_INCLUDE_DIR})
else ()
    message(STATUS "Could not find SPOTLTL C++ include path")
endif ()

find_package_handle_standard_args(SPOTLTL REQUIRED_VARS SPOTLTL_LIBRARY SPOTLTL_CPP_INCLUDE_DIR)

