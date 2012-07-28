cmake_minimum_required (VERSION 2.6)
project (IBUSBOGOENGINE)

find_package (PkgConfig)

#Find build dependencies
pkg_check_modules (GLIBMM glibmm-2.4)
pkg_check_modules (IBUS ibus-1.0)

#Include - headers
include_directories (${GLIBMM_INCLUDE_DIRS})
include_directories (${IBUS_INCLUDE_DIRS})
include_directories (src)
include_directories (BoGoEngine/src)

#Linker - directories
link_directories (${GLIMM_LIBRARY_DIRS})
link_directories (${IBUS_LIBRARY_DIRS})

add_subdirectory (src)
add_subdirectory (BoGoEngine/src)
