cmake_minimum_required(VERSION 3.19)
project("cpp_rutils" VERSION 1.0.1
             DESCRIPTION "some basic cpp framework"
             HOMEPAGE_URL "https://github.com/reder2000/cpp_rutils")

add_subdirectory(tests)
enable_testing()

include(GNUInstallDirs)

find_package(fmt CONFIG REQUIRED)

# installation directories
# set(cpp_rutils_INSTALL_INCLUDE_DIR "include" CACHE STRING "The installation include directory")
# set(cpp_rutils_INSTALL_CMAKE_DIR "share" CACHE STRING "The installation cmake directory")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
add_compile_options(/Zc:preprocessor)
endif ()

FILE(GLOB_RECURSE headers CONFIGURE_DEPENDS include/*.hpp include/*.h)
FILE(GLOB_RECURSE roost CONFIGURE_DEPENDS roost/*.hpp roost/*.h)
source_group("Header Files/roost" FILES ${roost})


# define a header-only library
add_library(cpp_rutils INTERFACE  ${headers} ${roost})
add_library(cpp_rutils::cpp_rutils ALIAS cpp_rutils)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)


target_link_libraries(cpp_rutils INTERFACE fmt::fmt fmt::fmt-header-only)

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/include/>
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

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/dummy-config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION
  ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(EXPORT ${PROJECT_NAME}_Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)


install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
              "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)


install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cpp_rutils)
install(DIRECTORY roost/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/roost)
