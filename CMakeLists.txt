cmake_minimum_required(VERSION 3.10.2)

execute_process(
    COMMAND git describe --abbrev=8 --dirty --always --tags
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE VERSION_STR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

message(STATUS "Version: ${VERSION_STR}")
STRING(REGEX REPLACE v\([0-9]+\).[0-9]+.[0-9]+.*$ \\1 MAVSDK_VERSION_MAJOR "${VERSION_STR}")
STRING(REGEX REPLACE v[0-9]+.\([0-9]+\).[0-9]+.*$ \\1 MAVSDK_VERSION_MINOR "${VERSION_STR}")
STRING(REGEX REPLACE v[0-9]+.[0-9]+.\([0-9]+\).*$ \\1 MAVSDK_VERSION_PATCH "${VERSION_STR}")

message(STATUS "Version major: ${MAVSDK_VERSION_MAJOR}")
message(STATUS "Version minor: ${MAVSDK_VERSION_MINOR}")
message(STATUS "Version patch: ${MAVSDK_VERSION_PATCH}")

set(MAVSDK_SOVERSION_STRING ${MAVSDK_VERSION_MAJOR})
set(MAVSDK_VERSION_STRING ${MAVSDK_VERSION_MAJOR}.${MAVSDK_VERSION_MINOR}.${MAVSDK_VERSION_PATCH})

project(mavsdk_superbuild)

if (BUILD_BACKEND)
    message(FATAL_ERROR "The argument BUILD_BACKEND has been replaced by BUILD_MAVSDK_SERVER. To build mavsdk_server, use -DBUILD_MAVSDK_SERVER=ON.")
endif()

option(SUPERBUILD "Build dependencies" ON)
option(BUILD_MAVSDK_SERVER "Build mavsdk_server" OFF)
option(BUILD_SHARED_LIBS "Build core as shared libraries instead of static ones" ON)

set(DEPS_BUILD_PATH "${PROJECT_BINARY_DIR}/third_party" CACHE PATH "Install path for the dependencies. Ignored if SUPERBUILD=OFF.")
set(DEPS_INSTALL_PATH "${DEPS_BUILD_PATH}/install" CACHE PATH "Install path for the dependencies. Ignored if SUPERBUILD=OFF.")
if(ANDROID)
## https://github.com/android-ndk/ndk/issues/890
##
## ONLY doesn't do anything when CMAKE_FIND_ROOT_PATH is empty. Without this,
## CMake will wrongly search host sysroots for headers/libraries. The actual path
## used here is fairly meaningless since CMake doesn't handle the NDK sysroot
## layout (per-arch and per-verion subdirectories for libraries), so find_library
## is handled separately by CMAKE_SYSTEM_LIBRARY_PATH.
## https://github.com/android-ndk/ndk/issues/517
#
#list(APPEND CMAKE_FIND_ROOT_PATH "${ANDROID_NDK}")

## Allow users to override these values in case they want more strict behaviors.
## For example, they may want to prevent the NDK's libz from being picked up so
## they can use their own.
## https://github.com/android-ndk/ndk/issues/517
#
#if(NOT CMAKE_FIND_ROOT_PATH_MODE_PROGRAM)
#  set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#endif()
#
#if(NOT CMAKE_FIND_ROOT_PATH_MODE_LIBRARY)
#  set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#endif()
#
#if(NOT CMAKE_FIND_ROOT_PATH_MODE_INCLUDE)
#  set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
#endif()
#
#if(NOT CMAKE_FIND_ROOT_PATH_MODE_PACKAGE)
#  set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
#endif()
  list(APPEND CMAKE_FIND_ROOT_PATH "${DEPS_INSTALL_PATH}")
endif()

include(GNUInstallDirs)

if(SUPERBUILD)
    add_subdirectory(third_party)
endif()

add_subdirectory(src)

install(EXPORT mavsdk-targets
    FILE MAVSDKTargets.cmake
    NAMESPACE MAVSDK::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MAVSDK
    )

# For the build tree
configure_file(MAVSDKConfig.cmake.in
    "${PROJECT_BINARY_DIR}/MAVSDKConfig.cmake" @ONLY)
# For the install tree
configure_file(MAVSDKConfig.cmake.in
    "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/MAVSDKConfig.cmake" @ONLY)

include(CMakePackageConfigHelpers)
# Supply version to config
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/MAVSDKConfigVersion.cmake
    VERSION ${MAVSDK_VERSION_MAJOR}.${MAVSDK_VERSION_MINOR}.${MAVSDK_VERSION_PATCH}
    COMPATIBILITY SameMajorVersion )

install(FILES
    "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/MAVSDKConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/MAVSDKConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MAVSDK)
