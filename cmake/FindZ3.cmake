set(Z3_ROOT "" CACHE PATH "Root of Z3 distribution.")

find_library(Z3_LIBRARY NAMES z3 PATHS ${Z3_ROOT}/lib)

if (Z3_LIBRARY)
    message(STATUS "Found Z3 libraries: " ${Z3_LIBRARY})
else ()
    message(STATUS "Could not find Z3 libraries")
endif ()

# Try to find c headers
find_path(Z3_C_INCLUDE_DIR
        NAMES z3.h
        # For distributions that keep the header files in a `z3` folder,
        # for example Fedora's `z3-devel` package at `/usr/include/z3/z3.h`
        PATH_SUFFIXES z3
        DOC "Z3 C header"
        )
# Try to find c++ headers
find_path(Z3_CPP_INCLUDE_DIR
        NAMES z3++.h
        PATH_SUFFIXES z3/c++
        DOC "Z3 C++ header"
        )

if (Z3_C_INCLUDE_DIR AND Z3_CPP_INCLUDE_DIR)
    list(APPEND Z3_INCLUDE_DIRS ${Z3_C_INCLUDE_DIR} " " ${Z3_CPP_INCLUDE_DIR})
    message(STATUS "Found Z3 include directories: " ${Z3_INCLUDE_DIRS})
else ()
    if (Z3_C_INCLUDE_DIR)
        message(STATUS "Could not find C Z3 include path")
    endif ()
    if (Z3_CPP_INCLUDE_DIR)
        message(STATUS "Could not find Z3 C++ include path")
    endif ()
endif ()

find_package_handle_standard_args(Z3 REQUIRED_VARS Z3_LIBRARY Z3_INCLUDE_DIRS)

