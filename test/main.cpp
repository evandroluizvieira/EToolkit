/**
 * @file main.cpp
 * @brief Defines the entry point for the EToolkit unit test suite.
 */

#include "TestAssertions.hpp"
#include <iostream>

/**
 * @brief Runs the EToolkit unit test suite.
 * @return Zero when every test succeeds; otherwise, one.
 */
int main(){
    std::cout << "[==========] Running EToolkit test suites." << std::endl;
    const bool allPassed = EToolkitTest::runRegisteredSuites();

    const EToolkitTest::TestSummary summary = EToolkitTest::getSummary();
    std::cout << "[==========] " << summary.total << " tests from " << summary.suites
              << " test suites ran." << std::endl;
    std::cout << "[  PASSED  ] " << summary.passed << " tests." << std::endl;
    if(summary.total != summary.passed){
        std::cout << "[  FAILED  ] " << summary.total - summary.passed << " tests." << std::endl;
    }
    std::cout << "[==========] " << summary.passedChecks << " of " << summary.checks
              << " assertion checks passed (" << summary.elapsedMilliseconds << " ms)." << std::endl;

    return allPassed ? 0 : 1;
}
