cmake_minimum_required(VERSION 3.20)
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
  GIT_REMOTE_UPDATE_STRATEGY REBASE_CHECKOUT
  GIT_PROGRESS TRUE
  GIT_SHALLOW TRUE
  LOG_UPDATE TRUE
)
FetchContent_MakeAvailable(rr_cmake)

list(APPEND CMAKE_MODULE_PATH "${rr_cmake_SOURCE_DIR}") 

include(rr_cmake/FindVcpkInstall)
include(rr_cmake/cxx20)

find_vcpkg_install_missing(fmt)

# installation directories
# set(cpp_rutils_INSTALL_INCLUDE_DIR "include" CACHE STRING "The installation include directory")
# set(cpp_rutils_INSTALL_CMAKE_DIR "share" CACHE STRING "The installation cmake directory")

FILE(GLOB_RECURSE headers CONFIGURE_DEPENDS cpp_rutils/*.hpp cpp_rutils/*.h)
FILE(GLOB_RECURSE roost CONFIGURE_DEPENDS roost/*.hpp roost/*.h)
source_group("Header Files/roost" FILES ${roost})

# define a header-only library
add_library(cpp_rutils INTERFACE  ${headers} ${roost} README.md)
add_library(cpp_rutils::cpp_rutils ALIAS cpp_rutils)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

target_link_libraries(cpp_rutils INTERFACE fmt::fmt fmt::fmt-header-only)

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# require C++20
target_compile_features(cpp_rutils INTERFACE cxx_std_20)

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
install(DIRECTORY roost/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/roost)


if (NOT "${cpp_rutils_BUILD_TESTS}" STREQUAL "OFF")
    add_subdirectory(tests)
    enable_testing()
endif()

message("... done cpp_rutils Configuring")