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

option(ETOOLKIT_BUILD_TESTS "Build EToolkit tests" ON)
option(ETOOLKIT_BUILD_APPLICATIONS "Build EToolkit API applications" ON)

if(ETOOLKIT_BUILD_TESTS)
    enable_testing()
endif()

set(ETOOLKIT_LIBRARY_SOURCES
    source/core/EToolkit.cpp
)

if(ETOOLKIT_BUILD_SHARED_LIBRARY)
    add_library(EToolkit_shared SHARED ${ETOOLKIT_LIBRARY_SOURCES})
    target_include_directories(EToolkit_shared
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/source
    )
    set_target_properties(EToolkit_shared PROPERTIES
        OUTPUT_NAME EToolkit_shared
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif()

if(ETOOLKIT_BUILD_STATIC_LIBRARY)
    add_library(EToolkit_static STATIC ${ETOOLKIT_LIBRARY_SOURCES})
    target_include_directories(EToolkit_static
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/source
    )
    set_target_properties(EToolkit_static PROPERTIES
        OUTPUT_NAME EToolkit_static
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif()

if(ETOOLKIT_BUILD_SHARED_LIBRARY)
    add_library(EToolkit ALIAS EToolkit_shared)
elseif(ETOOLKIT_BUILD_STATIC_LIBRARY)
    add_library(EToolkit ALIAS EToolkit_static)
endif()

if(ETOOLKIT_BUILD_TESTS)
    add_subdirectory(test)
endif()

if(ETOOLKIT_BUILD_APPLICATIONS)
    add_subdirectory(applications)
endif()
