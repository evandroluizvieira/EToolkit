/**
 * @file StaticArrayTest.hpp
 * @brief Declares tests for the EToolkit static array.
 */

#ifndef ETOOLKIT_STATIC_ARRAY_TEST_HPP
#define ETOOLKIT_STATIC_ARRAY_TEST_HPP

/**
 * @brief Contains unit tests for the EToolkit static array.
 */
class StaticArrayTest{
    public:
        /**
         * @brief Executes all static array tests.
         */
        static void run();

    private:
        /**
         * @brief Tests construction, element access, size, and containment.
         */
        static void testConstructionAndAccess();

        /**
         * @brief Tests mutation, filling, clearing, and indexed swapping.
         */
        static void testMutationAndClear();

        /**
         * @brief Tests iteration and access through a constant reference.
         */
        static void testIterationAndConstCorrectness();

        /**
         * @brief Tests exception reporting for an invalid index.
         */
        static void testBoundsChecking();
};

#endif /* ETOOLKIT_STATIC_ARRAY_TEST_HPP */
