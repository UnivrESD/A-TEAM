
include(FindPackageHandleStandardArgs)

find_library(Z3_LIBRARY NAMES z3 PATHS ./libs/lib/z3/lib)

if (NOT Z3_LIBRARY)
    find_library(Z3_LIBRARY NAMES z3 PATHS ./libs/z3/build)
endif ()

if (Z3_LIBRARY)
    message(STATUS "Found Z3 libraries: " ${Z3_LIBRARY})
else ()
    message(STATUS "Could not find Z3 libraries")
endif ()

# Try to find c headers
find_path(Z3_C_INCLUDE_DIR
    NAMES z3.h
    PATHS ./libs/lib/z3/include/api/ 
    DOC "Z3 C header"
    )

if (NOT Z3_C_INCLUDE_DIR)
    find_path(Z3_C_INCLUDE_DIR
        NAMES z3.h
        PATHS ./libs/z3/src/api/ 
        DOC "Z3 C header"
        )
endif ()

# Try to find c++ headers
find_path(Z3_CPP_INCLUDE_DIR
    NAMES z3++.h
    PATHS ./libs/lib/z3/include/api/c++
    DOC "Z3 C++ header"
    )

if (NOT Z3_CPP_INCLUDE_DIR)
    # Try to find c++ headers
    find_path(Z3_CPP_INCLUDE_DIR
        NAMES z3++.h
        PATHS ./libs/z3/src/api/c++
        DOC "Z3 C++ header"
        )
endif ()



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

