cmake_minimum_required(VERSION 3.16)

project(EToolkit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ETOOLKIT_BUILD_SHARED_LIBRARY "Build the shared EToolkit library" ON)
option(ETOOLKIT_BUILD_STATIC_LIBRARY "Build the static EToolkit library" ON)

file(GLOB_RECURSE ETOOLKIT_LIBRARY_SOURCES CONFIGURE_DEPENDS
    source/*.cpp
)

if(NOT ETOOLKIT_BUILD_SHARED_LIBRARY AND NOT ETOOLKIT_BUILD_STATIC_LIBRARY)
    message(FATAL_ERROR "At least one EToolkit library variant must be enabled")
endif()

function(configure_etoolkit_library target_name library_type)
    add_library(${target_name} ${library_type} ${ETOOLKIT_LIBRARY_SOURCES})
    target_compile_features(${target_name} PUBLIC cxx_std_11)
    target_include_directories(${target_name}
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/source
    )
endfunction()

if(ETOOLKIT_BUILD_SHARED_LIBRARY)
    configure_etoolkit_library(EToolkit_shared SHARED)
    target_compile_definitions(EToolkit_shared
        PRIVATE ETOOLKIT_SHARED_LIBRARY
    )
    if(WIN32)
        target_link_libraries(EToolkit_shared PUBLIC gdi32 opengl32 user32)
    endif()
endif()

if(ETOOLKIT_BUILD_STATIC_LIBRARY)
    configure_etoolkit_library(EToolkit_static STATIC)
    target_compile_definitions(EToolkit_static PUBLIC ETOOLKIT_STATIC_LIBRARY)
    if(WIN32)
        target_link_libraries(EToolkit_static PUBLIC gdi32 opengl32 user32)
    endif()
endif()

if(ETOOLKIT_BUILD_SHARED_LIBRARY)
    add_library(EToolkit ALIAS EToolkit_shared)
elseif(ETOOLKIT_BUILD_STATIC_LIBRARY)
    add_library(EToolkit ALIAS EToolkit_static)
endif()

option(ETOOLKIT_BUILD_TESTS "Build EToolkit tests" ON)
option(ETOOLKIT_BUILD_APPLICATIONS "Build EToolkit API applications" ON)

if(ETOOLKIT_BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

if(ETOOLKIT_BUILD_APPLICATIONS)
    add_subdirectory(applications)
endif()
