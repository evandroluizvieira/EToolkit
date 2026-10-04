/**
 * @file DynamicArrayTest.hpp
 * @brief Declares tests for the EToolkit dynamic array.
 */

#ifndef ETOOLKIT_DYNAMIC_ARRAY_TEST_HPP
#define ETOOLKIT_DYNAMIC_ARRAY_TEST_HPP

/**
 * @brief Contains unit tests for the EToolkit dynamic array.
 */
class DynamicArrayTest{
    public:
        /**
         * @brief Executes all dynamic array tests.
         */
        static bool run();

    private:
        /**
         * @brief Tests construction and insertion operations.
         */
        static bool testConstructionAndInsertion();

        /**
         * @brief Tests capacity management, resizing, removal, and clearing.
         */
        static bool testResizeAndRemoval();

        /**
         * @brief Tests copying, comparison, iteration, and constant access.
         */
        static bool testCopyComparisonAndIteration();

        /**
         * @brief Tests exception reporting for an invalid index.
         */
        static bool testBoundsChecking();
};

#endif /* ETOOLKIT_DYNAMIC_ARRAY_TEST_HPP */
