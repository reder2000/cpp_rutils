cmake_minimum_required(VERSION 3.30)
project(cpp_rutils_tests VERSION 0.1.0)
include(CTest)

message("Configuring cpp_rutils/tests ...")

enable_testing()

if (WIN32) # or MSVC to be specific
	string(REGEX REPLACE "/EHsc" "/EHa" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif (WIN32)


find_vcpkg_install_missing(GTest gtest)
include(GoogleTest)

file (GLOB srcs CONFIGURE_DEPENDS *.cpp stdafx.h)

include_directories(../cpp_rutils)
include_directories(..)
include_directories(${CMAKE_BINARY_DIR})
message("include_directories CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}")

add_executable(cpp_rutils_tests ${srcs})
#add_executable(cpp_rutils_tests fpu_seh.cpp)

MESSAGE("additional_libraries  ${additional_libraries} ")

target_link_libraries(cpp_rutils_tests PRIVATE date::date date::date-tz
		GTest::gtest GTest::gtest_main ${additional_libraries} ) # GTest::gmock GTest::gmock_main Catch2::Catch2WithMain  )

#add_test(cpp_rutils cpp_rutils_tests)
#gtest_add_tests(TARGET cpp_rutils_tests TEST_LIST cpp_rutils)
#gtest_discover_tests(cpp_rutils_tests)
gtest_add_tests(TARGET cpp_rutils_tests)

#if (MSVC)
message("using Precompiled Headers")
#set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP  0)
target_precompile_headers(cpp_rutils_tests  PUBLIC    stdafx.h)
add_compile_definitions(USING_PCH)
#endif ()

message("... done cpp_rutils/tests Configuring")