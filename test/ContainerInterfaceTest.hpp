/**
 * @file ContainerInterfaceTest.hpp
 * @brief Declares tests for `EToolkit::IContainer` behavior through concrete test doubles.
 */

#ifndef ETOOLKIT_CONTAINER_INTERFACE_TEST_HPP
#define ETOOLKIT_CONTAINER_INTERFACE_TEST_HPP

/**
 * @brief Contains unit tests for `EToolkit::IContainer` contract behavior.
 */
class ContainerInterfaceTest{
    public:
        /**
         * @brief Executes all container interface tests.
         * @return true when every test passes
         */
        static bool run();

    private:
        /**
         * @brief Verifies empty and non-empty state through the base interface.
         * @return true on success
         */
        static bool testEmptyState();

        /**
         * @brief Verifies equality and inequality operators through the base interface.
         * @return true on success
         */
        static bool testEqualityAndInequality();

        /**
         * @brief Verifies comparisons with different sizes and self-comparison rules.
         * @return true on success
         */
        static bool testSizeAndSelfComparison();

        /**
         * @brief Verifies `clear()` and `swap()` behavior through the base interface.
         * @return true on success
         */
        static bool testClearAndSwap();

        /**
         * @brief Verifies null-data safety for non-empty containers.
         * @return true on success
         */
        static bool testNullDataSafety();

        /**
         * @brief Verifies swap behavior against an incompatible implementation.
         * @return true on success
         */
        static bool testSwapWithIncompatibleImplementation();
};

#endif /* ETOOLKIT_CONTAINER_INTERFACE_TEST_HPP */
