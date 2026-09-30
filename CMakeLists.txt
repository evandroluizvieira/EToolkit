cmake_minimum_required(VERSION 3.16)

project(EToolkit LANGUAGES CXX)

option(ETOOLKIT_BUILD_TESTS "Build EToolkit tests" ON)

if(ETOOLKIT_BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
