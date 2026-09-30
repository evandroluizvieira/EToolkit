/**
 * @file main.cpp
 * @brief Defines the entry point for the EToolkit unit test suite.
 */

#include "DynamicArrayTest.hpp"
#include "StaticArrayTest.hpp"
#include "TestAssertions.hpp"

#include <iostream>

/**
 * @brief Runs the EToolkit unit test suite.
 * @return Zero when every test succeeds; otherwise, one.
 */
int main(){
    try{
        StaticArrayTest::run();
        DynamicArrayTest::run();
    }catch(const EToolkitTest::AssertionFailure& failure){
        std::cerr << failure.what() << std::endl;
        return 1;
    }

    return 0;
}
