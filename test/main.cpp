/**
 * @file main.cpp
 * @brief Defines the entry point for the EToolkit unit test suite.
 */

#include "DynamicArrayTest.hpp"
#include "GeometryTest.hpp"
#include "StaticArrayTest.hpp"
#include "TestAssertions.hpp"
#include <iostream>

/**
 * @brief Runs the EToolkit unit test suite.
 * @return Zero when every test succeeds; otherwise, one.
 */
int main(){
    std::cout << "[==========] Running EToolkit test suites." << std::endl;
    const bool staticArrayPassed = StaticArrayTest::run();
    const bool dynamicArrayPassed = DynamicArrayTest::run();
    const bool geometryPassed = GeometryTest::run();
    const bool allPassed = staticArrayPassed && dynamicArrayPassed && geometryPassed;

    const EToolkitTest::TestSummary summary = EToolkitTest::getSummary();
    std::cout << "[==========] " << summary.total << " tests from " << summary.suites
              << " test suites ran." << std::endl;
    std::cout << "[  PASSED  ] " << summary.passed << " tests." << std::endl;
    if(summary.total != summary.passed){
        std::cout << "[  FAILED  ] " << summary.total - summary.passed << " tests." << std::endl;
    }
    std::cout << "[==========] " << summary.passedChecks << " of " << summary.checks
              << " checks passed (" << summary.elapsedMilliseconds << " ms)." << std::endl;

    return allPassed ? 0 : 1;
}
