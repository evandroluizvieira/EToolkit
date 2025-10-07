/**
 * @file IIterable.hpp
 * @brief Iterable interface for container iteration
 */

#ifndef IITERABLE_HPP
#define IITERABLE_HPP

/**
 * @namespace EToolkit
 * @brief Evandro's Toolkit
 */
namespace EToolkit{

    /**
     * @brief Interface for iterable containers
     *
     * Defines the iterable interface that enables range-based for loops
     * and STL algorithm compatibility for EToolkit containers. Follows
     * the Iterator design pattern to provide uniform iteration across
     * different container types.
     *
     * @note Implementing this interface allows containers to work with
     *       C++11 range-based for loops and all STL algorithms that
     *       require iterators.
     *
     * @tparam DataType Type of the elements stored in the container
     */
    template<class DataType>
    class IIterable{
        public:
            /**
             * @brief Virtual destructor for proper inheritance
             */
            virtual ~IIterable() = default;

            /**
             * @brief Default constructor
             */
            IIterable() = default;

            /**
             * @brief Copy constructor
             */
            IIterable(const IIterable& other) = default;

            /**
             * @brief Copy assignment operator
             */
            IIterable& operator=(const IIterable& other) = default;

            /**
             * @brief Move constructor
             */
            IIterable(IIterable&& other) = default;

            /**
             * @brief Move assignment operator
             */
            IIterable& operator=(IIterable&& other) = default;

            /**
             * @brief Gets iterator to the beginning of the container
             * @return Pointer to the first element
             */
            virtual DataType* begin() = 0;

            /**
             * @brief Gets iterator to the beginning of the container (const version)
             * @return Const pointer to the first element
             */
            virtual const DataType* begin() const = 0;

            /**
             * @brief Gets iterator to the end of the container
             * @return Pointer to the element after the last
             */
            virtual DataType* end() = 0;

            /**
             * @brief Gets iterator to the end of the container (const version)
             * @return Const pointer to the element after the last
             */
            virtual const DataType* end() const = 0;

            /**
             * @brief Gets constant iterator to the beginning of the container
             * @return Const pointer to the first element
             */
            virtual const DataType* cbegin() const = 0;

            /**
             * @brief Gets constant iterator to the end of the container
             * @return Const pointer to the element after the last
             */
            virtual const DataType* cend() const = 0;
    };
}

#endif /* IITERABLE_HPP */
