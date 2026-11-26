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
#include <vector>

/**
 * @def ETOOLKIT_TEST_ASSERT(title, expression)
 * @brief Evaluates a titled test condition.
 * @param title Human-readable description of the check.
 * @param expression Condition that must evaluate to true.
 */
#define ETOOLKIT_TEST_ASSERT(title, expression) \
    if(!EToolkitTest::check((title), (expression), #expression, __FILE__, __LINE__)) return false

/**
 * @def ETOOLKIT_REGISTER_TEST_SUITE(suite)
 * @brief Registers a suite class with the automatic test runner.
 * @param suite Suite class exposing a static `run()` function
 */
#define ETOOLKIT_REGISTER_TEST_SUITE(suite) \
    namespace{ \
        const bool suite##_registered = EToolkitTest::registerSuite(&suite::run); \
    }

/**
 * @namespace EToolkitTest
 * @brief Provides support utilities for the EToolkit test suite.
 */
namespace EToolkitTest{

/**
 * @brief Stores the result of one executed test case.
 */
struct TestResult{
    std::string name;	///< Human-readable name of the test case.
    bool passed;	///< True when the test case completed successfully.
};

/**
 * @brief Aggregated results produced by the test runner.
 */
struct TestSummary{
    unsigned int total;				///< Total number of executed test cases.
    unsigned int passed;			///< Number of test cases that passed.
    unsigned int checks;			///< Total number of evaluated assertions.
    unsigned int passedChecks;		///< Number of assertions that passed.
    unsigned int suites;			///< Number of executed test suites.
    long long elapsedMilliseconds;  ///< Accumulated test execution time in milliseconds.
};

/**
 * @brief A named test case and its execution function.
 */
struct TestCase{
    const char* name;	///< Human-readable name reported for the test case.
    bool (*function)();	///< Test function returning true when successful.
};

/**
 * @brief Function signature used by a registered test suite.
 * @details A suite function returns true when all of its test cases pass.
 */
typedef bool (*TestSuiteFunction)();

/**
 * @brief Gets the process-wide test result summary.
 * @return Mutable reference to the current summary
 */
inline TestSummary& summary(){
    static TestSummary value = {0, 0, 0, 0, 0, 0};
    return value;
}

/**
 * @brief Announces the start of a test suite.
 * @param name Human-readable suite name
 * @param testCount Number of cases in the suite
 */
inline void beginSuite(const char* name, unsigned int testCount){
    ++summary().suites;
    std::cout << "[----------] " << testCount << " tests from " << name << std::endl;
}

/**
 * @brief Announces the completion of a test suite.
 * @param name Human-readable suite name
 * @param testCount Number of cases in the suite
 */
inline void endSuite(const char* name, unsigned int testCount){
    std::cout << "[----------] " << testCount << " tests from " << name << " (suite complete)"
              << std::endl;
}

/**
 * @brief Gets a copy of the current test result summary.
 * @return Current summary values
 */
inline TestSummary getSummary(){
    return summary();
}

/**
 * @brief Gets the collection of test suites registered with the runner.
 * @return Mutable reference to the registered suite functions
 */
inline std::vector<TestSuiteFunction>& registeredSuites(){
    static std::vector<TestSuiteFunction> suites;
    return suites;
}

/**
 * @brief Registers a test suite function for execution by the runner.
 * @param suite Suite function to register
 * @return true after the suite has been added
 */
inline bool registerSuite(TestSuiteFunction suite){
    registeredSuites().push_back(suite);
    return true;
}

/**
 * @brief Executes every suite registered with the runner.
 * @return true when every registered suite passes
 */
inline bool runRegisteredSuites(){
    bool passed = true;
    const std::vector<TestSuiteFunction>& suites = registeredSuites();
    for(std::size_t index = 0; index < suites.size(); ++index){
        passed = suites[index]() && passed;
    }
    return passed;
}

/**
 * @brief Evaluates one assertion and records its result.
 * @param title Human-readable assertion description printed on failure.
 * @param condition Boolean result of the assertion expression.
 * @param expression Source expression used to produce the diagnostic message.
 * @param file Source file containing the assertion.
 * @param line Source line containing the assertion.
 * @return True when the assertion passes; otherwise false.
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

/**
 * @brief Runs one test case and reports its result.
 * @tparam TestFunction Callable type returning true when the test passes.
 * @param name Human-readable name of the test case.
 * @param test Test function to execute.
 * @return The test case name and pass/fail result.
 */
template<class TestFunction>
TestResult runTest(const char* name, TestFunction test);

/**
 * @brief Runs every test case in a suite and reports the results.
 * @tparam TestCount Number of entries in the test case array.
 * @param name Human-readable name of the test suite.
 * @param tests Array containing the named test cases to execute.
 * @return True when every test case in the suite passes; otherwise false.
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

#endif /* ETOOLKIT_TEST_ASSERTIONS_HPP */
