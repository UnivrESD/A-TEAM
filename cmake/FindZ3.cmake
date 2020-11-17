include(FindPackageHandleStandardArgs)

if(DEFINED Z3_INCLUDE_PATH AND DEFINED Z3_LIB_PATH)
    set(Z3_INCLUDE_DIRS ${Z3_INCLUDE_PATH})
    set(Z3_LIBRARY ${Z3_LIB_PATH})
else()
    find_library(Z3_LIBRARY NAMES libz3.so
        HINTS /usr/local/lib/z3 /usr/lib/z3 /usr/local/lib /usr/lib)

    find_path(Z3_INCLUDE_DIRS
        NAMES z3++.h z3.h
        HINTS /usr/local/include/z3 /usr/include/z3 /usr/local/include /usr/include
        DOC "Z3 C++ header")
endif()

find_package_handle_standard_args(Z3 REQUIRED_VARS Z3_LIBRARY Z3_INCLUDE_DIRS)
