/**
 * @file TestAssertions.hpp
 * @brief Provides dependency-free test reporting for the EToolkit test suite.
 */

#ifndef ETOOLKIT_TEST_ASSERTIONS_HPP
#define ETOOLKIT_TEST_ASSERTIONS_HPP

#include <chrono>
#include <cstddef>
#include <exception>
#include <iostream>
#include <string>

/**
 * @namespace EToolkitTest
 * @brief Provides support utilities for the EToolkit test suite.
 */
namespace EToolkitTest{

/**
 * @brief Reports a failed test assertion.
 */
struct TestResult{
    std::string name;
    bool passed;
};

struct TestSummary{
    unsigned int total;
    unsigned int passed;
    unsigned int checks;
    unsigned int passedChecks;
    unsigned int suites;
    long long elapsedMilliseconds;
};

struct TestCase{
    const char* name;
    bool (*function)();
};

inline TestSummary& summary(){
    static TestSummary value = {0, 0, 0, 0, 0, 0};
    return value;
}

inline void beginSuite(const char* name, unsigned int testCount){
    ++summary().suites;
    std::cout << "[----------] " << testCount << " tests from " << name << std::endl;
}

inline void endSuite(const char* name, unsigned int testCount){
    std::cout << "[----------] " << testCount << " tests from " << name << " (suite complete)"
              << std::endl;
}

inline TestSummary getSummary(){
    return summary();
}

/**
 * @brief Verifies one titled test condition.
 * @param title Human-readable description of the check.
 * @param condition Condition that must evaluate to true.
 * @param expression Source expression used to produce the diagnostic message.
 * @param file Source file containing the assertion.
 * @param line Source line containing the assertion.
 * @return true when the condition passes; otherwise false.
 */
inline bool check(const char* title, bool condition, const char* expression, const char* file, int line){
    ++summary().checks;
    if(condition){
        ++summary().passedChecks;
        return true;
    }

    std::cerr << "    [FAIL] " << title << " (" << expression << ") at " << file << ":" << line
              << std::endl;
    return false;
}

template<class TestFunction>
TestResult runTest(const char* name, TestFunction test);

/**
 * @brief Runs every case in a suite and reports its dynamically determined count.
 * @param name Human-readable suite name.
 * @param tests Array of named test cases.
 * @return true when every case in the suite succeeds.
 */
template<std::size_t TestCount>
bool runSuite(const char* name, const TestCase (&tests)[TestCount]){
    beginSuite(name, static_cast<unsigned int>(TestCount));
    bool passed = true;
    for(std::size_t index = 0; index < TestCount; ++index){
        passed = runTest(tests[index].name, tests[index].function).passed && passed;
    }
    endSuite(name, static_cast<unsigned int>(TestCount));
    return passed;
}

/**
 * @brief Runs one test case and prints its result.
 * @param name Human-readable test-case name.
 * @param test Test-case function returning true on success.
 * @return Test-case result.
 */
template<class TestFunction>
TestResult runTest(const char* name, TestFunction test){
    const std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    TestResult result = {name, false};
    ++summary().total;
    std::cout << "[ RUN      ] " << result.name << std::endl;
    try{
        result.passed = test();
    }catch(const std::exception& exception){
        std::cerr << "    [FAIL] unexpected exception: " << exception.what() << std::endl;
    }catch(...){
        std::cerr << "    [FAIL] unexpected unknown exception" << std::endl;
    }

    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    const long long elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    summary().elapsedMilliseconds += elapsed;
    if(result.passed){
        ++summary().passed;
    }

    std::cout << (result.passed ? "[       OK ] " : "[  FAILED  ] ") << result.name << " ("
              << elapsed << " ms)" << std::endl;
    return result;
}

}

/**
 * @brief Evaluates a titled test condition.
 * @param title Human-readable description of the check.
 * @param expression Condition that must evaluate to true.
 */
#define ETOOLKIT_TEST_ASSERT(title, expression) \
    if(!EToolkitTest::check((title), (expression), #expression, __FILE__, __LINE__)) return false

#endif /* ETOOLKIT_TEST_ASSERTIONS_HPP */
