cmake_minimum_required(VERSION 3.0.0)
project(cpp_rutils_tests VERSION 0.1.0)

message("Configuring cpp_rutils/tests ...")

if (WIN32) # or MSVC to be specific
	string(REGEX REPLACE "/EHsc" "/EHa" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif (WIN32)


find_vcpkg_install_missing(Catch2 catch2)
#find_vcpkg_install_missing(tl-expected)

file (GLOB srcs CONFIGURE_DEPENDS *.cpp stdafx.h)

include_directories(../cpp_rutils)
include_directories(..)
include_directories(${CMAKE_BINARY_DIR})
message("include_directories CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}")

add_executable(cpp_rutils_tests ${srcs})
#add_executable(cpp_rutils_tests fpu_seh.cpp)

target_link_libraries(cpp_rutils_tests Catch2::Catch2WithMain  date::date date::date-tz ${additional_libraries})
#target_link_libraries(cpp_rutils_tests fmt::fmt  date::date date::date-tz ${additional_libraries})

if (MSVC)
message("using Precompiled Headers")
#set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP  0)
target_precompile_headers(cpp_rutils_tests  PUBLIC    stdafx.h)
add_compile_definitions(USING_PCH)
endif ()

message("... done cpp_rutils/tests Configuring")