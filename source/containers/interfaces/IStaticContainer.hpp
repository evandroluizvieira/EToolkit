/**
 * @file IStaticContainer.hpp
 * @brief Static container interface for fixed-size containers
 */

#ifndef ISTATICCONTAINER_HPP
#define ISTATICCONTAINER_HPP

#include "IContainer.hpp"

/**
 * @namespace EToolkit
 * @brief Evandro's Toolkit
 */
namespace EToolkit{

    /**
     * @brief Interface for static-size containers
     *
     * Defines the interface for fixed-size containers.
     * Provides bounds-checked access operations and
     * efficient memory layout for static data structures.
     *
     * @note Containers implementing this interface must have a fixed
     *       size greater than zero, validated at compile-time.
     *       A zero-sized static container is never permitted.
     *
     * @tparam DataType Type of the elements stored in the container
     * @tparam SizeType Type used for size operations and indices
     * @extends IContainer<DataType, SizeType>
     */
    template<class DataType, class SizeType, SizeType SizeValue>
    class IStaticContainer : public IContainer<DataType, SizeType>{
        public:
            /**
             * @brief Virtual destructor for proper inheritance
             */
            virtual ~IStaticContainer() = default;

            /**
             * @brief Copy assignment operator
             * @param other Static container interface to copy
             * @return Reference to this interface
             */
            IStaticContainer& operator=(const IStaticContainer& other) = default;

            /**
             * @brief Move assignment operator
             * @param other Static container interface to move
             * @return Reference to this interface
             */
            IStaticContainer& operator=(IStaticContainer&& other) = default;

            /**
             * @brief Gets the compile-time number of elements in the container
             * @return Fixed number of elements in the container
             */
            SizeType getSize() const override{
                return SizeValue;
            }

            /**
             * @brief Access element with bounds checking
             * @param index Position of the element
             * @return Reference to the element at the given index
             * @throws OutOfBoundsException If index is out of range
             */
            virtual DataType& at(SizeType index) = 0;

            /**
             * @brief Access element with bounds checking (const version)
             * @param index Position of the element
             * @return Const reference to the element at the given index
             * @throws OutOfBoundsException If index is out of range
             */
            virtual const DataType& at(SizeType index) const = 0;

            /**
             * @brief Access operator for non-const objects
             * @param index Position of the element
             * @return Reference to the element at the given index
             */
            virtual DataType& operator[](SizeType index) = 0;

            /**
             * @brief Access operator for const objects
             * @param index Position of the element
             * @return Const reference to the element at the given index
             */
            virtual const DataType& operator[](SizeType index) const = 0;

            /**
             * @brief Gets the first element in the container
             * @return Reference to the first element
             * @throws OutOfBoundsException If container is empty
             */
            virtual DataType& getFront() = 0;

            /**
             * @brief Gets the first element in the container (const version)
             * @return Const reference to the first element
             * @throws OutOfBoundsException If container is empty
             */
            virtual const DataType& getFront() const = 0;

            /**
             * @brief Gets the last element in the container
             * @return Reference to the last element
             * @throws OutOfBoundsException If container is empty
             */
            virtual DataType& getBack() = 0;

            /**
             * @brief Gets the last element in the container (const version)
             * @return Const reference to the last element
             * @throws OutOfBoundsException If container is empty
             */
            virtual const DataType& getBack() const = 0;

            /**
             * @brief Fills all elements with the given value
             * @param value Value to fill each element
             */
            virtual void fill(const DataType& value) = 0;

        protected:
            /**
             * @brief Default constructor with size validation.
             * @note A zero-sized static container is rejected by the
             *       compile-time assertion in this constructor.
             */
            IStaticContainer() : IContainer<DataType, SizeType>(){
                static_assert(SizeValue > 0, "Static container size must be greater than zero");
            }

            /**
             * @brief Copy constructor
             * @param other Static container interface to copy
             */
            IStaticContainer(const IStaticContainer& other) = default;

            /**
             * @brief Move constructor
             * @param other Static container interface to move
             */
            IStaticContainer(IStaticContainer&& other) = default;
    };
}

#endif /* ISTATICCONTAINER_HPP */
