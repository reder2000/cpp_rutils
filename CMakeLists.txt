cmake_minimum_required (VERSION 3.20)

project("cpp_rutils" VERSION 1.0.1
             DESCRIPTION "some basic cpp framework"
             HOMEPAGE_URL "https://github.com/reder2000/cpp_rutils")

message("Configuring cpp_rutils ...")

include(GNUInstallDirs)

include(FetchContent)
FetchContent_Declare(
  rr_cmake
  GIT_REPOSITORY "https://github.com/reder2000/rr_cmake.git"
  GIT_TAG origin/master
  GIT_SHALLOW TRUE
  GIT_REMOTE_UPDATE_STRATEGY REBASE_CHECKOUT
)
FetchContent_MakeAvailable(rr_cmake)
include(${rr_cmake_SOURCE_DIR}/rr_cmake/common.cmake)

find_vcpkg_install_missing(fmt)
if ("${fmt_VERSION}" VERSION_LESS "9.0.0")
    message(FATAL_ERROR  "fmt version ${fmt_VERSION} must be >= 9.0.0.\n Please upgrade vcpkg")
endif()
boost_header_only_package(preprocessor preprocessor.hpp)
if (${MINGW})
# libbacktrace does not work properlmy on msys2
#find_package(backtrace REQUIRED)
#set(additional_libraries backtrace)
add_compile_definitions(BOOST_STACKTRACE_USE_NOOP)
endif()
if (${UNIX})
boost_header_only_package(stacktrace stacktrace.hpp)
add_compile_definitions(BOOST_STACKTRACE_USE_BACKTRACE)
#sorry but stacktrace misses a config so we run into that line at each configure
vcpkg_install(libbacktrace)
#find_vcpkg_install_missing(backtrace libbacktrace)
set(additional_libraries backtrace)
endif()
find_vcpkg_install_missing(tl-expected)

include(CheckSymbolExists)
check_symbol_exists(strerror_s "string.h" HAVE_STRERROR_S)
check_symbol_exists(getenv_s "stdlib.h" HAVE_GETENV_S)
check_symbol_exists(localtime_s "time.h" HAVE_LOCALTIME_S)
include(CheckCXXSourceCompiles)
check_cxx_source_compiles(
        "#include <chrono>
         using test = std::chrono::duration;
         int main(){ return 0; }"
         HAVE_CXX20_CHRONO_DURATION)
check_cxx_source_compiles(
        "#include <chrono>
         using test = std::chrono::time_zone;
         int main(){ return 0; }"
         HAVE_CXX20_CHRONO_TIME_ZONE)
configure_file(cpp_rutils/config.h.in cpp_rutils_config.h)
include_directories(${CMAKE_BINARY_DIR})
message("include_directories CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}")

if (MSVC)
message("using https://github.com/HowardHinnant/date.git")
FetchContent_Declare(
	  date_src
	  GIT_REPOSITORY  "https://github.com/HowardHinnant/date.git"
	  GIT_TAG origin/master
	  GIT_REMOTE_UPDATE_STRATEGY REBASE_CHECKOUT
	  GIT_PROGRESS TRUE
	  GIT_SHALLOW TRUE
	  LOG_UPDATE TRUE
	  SOURCE_SUBDIR  date_src
	  BUILD_TZ_LIB
	)
FetchContent_Populate(date_src)
set(CMAKE_CXX_STANDARD 20 CACHE STRING "The C++ standard whose features are requested." )
set(BUILD_TZ_LIB ON CACHE INTERNAL "BUILD_TZ_LIB")
add_subdirectory(${date_src_SOURCE_DIR} ${date_src_BINARY_DIR})
message("add_subdirectory(${date_src_SOURCE_DIR} ${date_src_BINARY_DIR}")
else ()
    message("using vcpkg date")
  find_vcpkg_install_missing(date date[remote-api])
endif()

add_source_group(cpp_rutils)
set(all_sources ${all_sources} cpp_rutils/config.h.in)
add_source_group(cpp_rutils/throwing)
add_source_group(cpp_rutils/detail)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# define a header-only library
add_library(cpp_rutils INTERFACE ${all_sources} README.md)
add_library(cpp_rutils::cpp_rutils ALIAS cpp_rutils)

target_link_libraries(cpp_rutils INTERFACE fmt::fmt fmt::fmt-header-only date::date date::date-tz ${additional_libraries})
#target_link_libraries(cpp_rutils INTERFACE "$<BUILD_INTERFACE:date>")

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_NAME}ConfigVersion.cmake"
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMajorVersion
                                 ARCH_INDEPENDENT)

set(INCLUDE_INSTALL_DIR include/ ... CACHE PATH "include cpputils")
configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/dummy-config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION
  ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
  PATH_VARS INCLUDE_INSTALL_DIR )

install(EXPORT ${PROJECT_NAME}_Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)


install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
              "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)


install(DIRECTORY cpp_rutils/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cpp_rutils)

if (NOT "${cpp_rutils_BUILD_TESTS}" STREQUAL "OFF")
    add_subdirectory(tests)
    enable_testing()
endif()

message("... done cpp_rutils Configuring")
