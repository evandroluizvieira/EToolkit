/**
 * @file IDynamicContainer.hpp
 * @brief Interface for dynamically sized containers
 */

#ifndef IDYNAMICCONTAINER_HPP
#define IDYNAMICCONTAINER_HPP

#include "IContainer.hpp"

/**
 * @namespace EToolkit
 * @brief Evandro's Toolkit
 */
namespace EToolkit{

    /**
     * @brief Interface for containers whose size can change at runtime.
     *
     * Defines the operations shared by dynamically sized containers.
     * Concrete containers remain responsible for allocation, capacity
     * management, bounds checking, and element lifetime.
     *
     * @tparam DataType Type of the elements stored in the container
     * @tparam SizeType Type used for size, capacity, and indices
     * @extends IContainer<DataType, SizeType>
     */
    template<class DataType, class SizeType>
    class IDynamicContainer : public IContainer<DataType, SizeType>{
        public:
            /**
             * @brief Virtual destructor for proper inheritance
             */
            virtual ~IDynamicContainer() = default;

            /**
             * @brief Gets the allocated capacity
             * @return Number of elements that can be stored without reallocating
             */
            virtual SizeType getCapacity() const = 0;

            /**
             * @brief Changes the logical size of the container
             * @param newSize Requested logical size
             */
            virtual void resize(SizeType newSize) = 0;

            /**
             * @brief Ensures that the container can hold at least the requested number of elements
             * @param newCapacity Requested capacity
             */
            virtual void reserve(SizeType newCapacity) = 0;

            /**
             * @brief Inserts an element at an index
             * @param data Element to insert
             * @param index Destination index
             */
            virtual void insert(const DataType& data, SizeType index) = 0;

            /**
             * @brief Inserts an element at the end
             * @param data Element to insert
             */
            virtual void insertBack(const DataType& data) = 0;

            /**
             * @brief Inserts an element at the beginning
             * @param data Element to insert
             */
            virtual void insertFront(const DataType& data) = 0;

            /**
             * @brief Removes the element at an index
             * @param index Index of the element to remove
             */
            virtual void remove(SizeType index) = 0;

            /**
             * @brief Removes the last element
             */
            virtual void removeBack() = 0;

            /**
             * @brief Removes the first element
             */
            virtual void removeFront() = 0;

        protected:
            /**
             * @brief Default constructor
             */
            IDynamicContainer() = default;

            /**
             * @brief Copy constructor
             * @param other Dynamic container interface to copy
             */
            IDynamicContainer(const IDynamicContainer&) = default;

            /**
             * @brief Move constructor
             * @param other Dynamic container interface to move
             */
            IDynamicContainer(IDynamicContainer&&) = default;

            /**
             * @brief Copy assignment operator
             * @param other Dynamic container interface to copy
             * @return Reference to this interface
             */
            IDynamicContainer& operator=(const IDynamicContainer&) = default;

            /**
             * @brief Move assignment operator
             * @param other Dynamic container interface to move
             * @return Reference to this interface
             */
            IDynamicContainer& operator=(IDynamicContainer&&) = default;
    };
}

#endif /* IDYNAMICCONTAINER_HPP */
