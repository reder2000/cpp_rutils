cmake_minimum_required(VERSION 3.0.0)
project(cpp_rutils_tests VERSION 0.1.0)

#message("include ${CMAKE_CURRENT_SOURCE_DIR}/../cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")
include(FindVcpkInstall)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
add_compile_options(/Zc:preprocessor)
endif ()

find_vcpkg_install_missing(Catch2 catch2)
find_vcpkg_install_missing(fmt)

#file(GLOB headers ../include/*.h )
file (GLOB srcs CONFIGURE_DEPENDS *.cpp)

include_directories(../include)
include_directories(..)

#include(CTest)
#enable_testing()

add_executable(cpp_rutils_tests ${srcs}) # ${headers})

target_link_libraries(cpp_rutils_tests Catch2::Catch2 fmt::fmt)

target_precompile_headers(cpp_rutils_tests  PUBLIC    stdafx.h)
add_definitions(-DUSING_PCH)

enable_testing()
add_test(NAME main COMMAND cpp_rutils_tests)