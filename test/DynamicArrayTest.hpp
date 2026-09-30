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
        static void run();

    private:
        /**
         * @brief Tests construction and insertion operations.
         */
        static void testConstructionAndInsertion();

        /**
         * @brief Tests capacity management, resizing, removal, and clearing.
         */
        static void testResizeAndRemoval();

        /**
         * @brief Tests copying, comparison, iteration, and constant access.
         */
        static void testCopyComparisonAndIteration();

        /**
         * @brief Tests exception reporting for an invalid index.
         */
        static void testBoundsChecking();
};

#endif /* ETOOLKIT_DYNAMIC_ARRAY_TEST_HPP */
