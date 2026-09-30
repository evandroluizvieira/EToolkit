/**
 * @file TestAssertions.hpp
 * @brief Provides dependency-free assertions for the EToolkit test suite.
 */

#ifndef ETOOLKIT_TEST_ASSERTIONS_HPP
#define ETOOLKIT_TEST_ASSERTIONS_HPP

#include <sstream>
#include <stdexcept>
#include <string>

/**
 * @namespace EToolkitTest
 * @brief Provides support utilities for the EToolkit test suite.
 */
namespace EToolkitTest{

/**
 * @brief Reports a failed test assertion.
 */
class AssertionFailure : public std::runtime_error{
    public:
        /**
         * @brief Constructs an assertion failure with a diagnostic message.
         * @param message Diagnostic message describing the failed assertion.
         */
        explicit AssertionFailure(const std::string& message) :
            std::runtime_error(message){
        }
};

/**
 * @brief Verifies a test condition and reports a failure when it is false.
 * @param condition Condition that must evaluate to true.
 * @param expression Source expression used to produce the diagnostic message.
 * @param file Source file containing the assertion.
 * @param line Source line containing the assertion.
 * @throws AssertionFailure When condition evaluates to false.
 */
inline void assertTrue(bool condition, const char* expression, const char* file, int line){
    if(!condition){
        std::ostringstream message;
        message << file << ":" << line << ": assertion failed: " << expression;
        throw AssertionFailure(message.str());
    }
}

}

/**
 * @brief Evaluates a test condition and reports its source location on failure.
 * @param expression Condition that must evaluate to true.
 */
#define ETOOLKIT_TEST_ASSERT(expression) \
    EToolkitTest::assertTrue((expression), #expression, __FILE__, __LINE__)

#endif /* ETOOLKIT_TEST_ASSERTIONS_HPP */
