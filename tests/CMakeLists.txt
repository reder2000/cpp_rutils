cmake_minimum_required(VERSION 3.0.0)
project(cpp_rutils_tests VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Catch2 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

file(GLOB headers ../include/*.h )
file (GLOB srcs CONFIGURE_DEPENDS *.cpp)

include_directories(../include)

#include(CTest)
#enable_testing()

add_executable(cpp_rutils_tests ${srcs} ${headers})

target_link_libraries(cpp_rutils_tests Catch2::Catch2 fmt::fmt)

target_precompile_headers(cpp_rutils_tests  PUBLIC    stdafx.h)
add_definitions(-DUSING_PCH)

enable_testing()
add_test(NAME main COMMAND cpp_rutils_tests)
