cmake_minimum_required(VERSION 3.0.0)
project(cpp_rutils_tests VERSION 0.1.0)

message("Configuring cpp_rutils/tests ...")


find_vcpkg_install_missing(Catch2 catch2)
#find_vcpkg_install_missing(tl-expected)

file (GLOB srcs CONFIGURE_DEPENDS *.cpp stdafx.h)

include_directories(../cpp_rutils)
include_directories(..)

add_executable(cpp_rutils_tests ${srcs})

target_link_libraries(cpp_rutils_tests Catch2::Catch2WithMain  fmt::fmt  date::date date::date-tz ${additional_libraries})

if (NOT GCC)
#set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP  0)
target_precompile_headers(cpp_rutils_tests  PUBLIC    stdafx.h)
add_compile_definitions(USING_PCH)
endif ()

message("... done cpp_rutils/tests Configuring")