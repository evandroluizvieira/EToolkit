cmake_minimum_required(VERSION 3.16)

file(READ "${CMAKE_CURRENT_SOURCE_DIR}/VERSION" ETOOLKIT_VERSION)
string(STRIP "${ETOOLKIT_VERSION}" ETOOLKIT_VERSION)
if(NOT ETOOLKIT_VERSION MATCHES "^[0-9]+\\.[0-9]+\\.[0-9]+$")
    message(FATAL_ERROR "VERSION must contain MAJOR.MINOR.PATCH")
endif()

project(EToolkit VERSION ${ETOOLKIT_VERSION} LANGUAGES CXX)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in"
    "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
    @ONLY
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ETOOLKIT_BUILD_SHARED_LIBRARY "Build the shared EToolkit library" ON)
option(ETOOLKIT_BUILD_STATIC_LIBRARY "Build the static EToolkit library" ON)

message(STATUS "EToolkit main baseline setup: implementation targets are added in follow-up development branches.")

option(ETOOLKIT_BUILD_TESTS "Build EToolkit tests" ON)
option(ETOOLKIT_BUILD_APPLICATIONS "Build EToolkit API applications" ON)

if(ETOOLKIT_BUILD_TESTS)
    enable_testing()
endif()
