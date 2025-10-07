/**
 * @file IContainer.hpp
 * @brief Contains base container interface
 */

#ifndef ICONTAINER_HPP
#define ICONTAINER_HPP

/**
 * @namespace EToolkit
 * @brief Evandro's Toolkit
 */
namespace EToolkit{

    /**
     * @brief Base interface for all containers in EToolkit.
     * @tparam DataType Type of the elements stored in the container
     * @tparam SizeType Type used for size operations and indices
     */
    template<class DataType, class SizeType>
    class IContainer{
        public:
            /**
             * @brief Virtual destructor for proper inheritance and resource cleanup
             */
            virtual ~IContainer() = default;

            /**
             * @brief Default constructor
             */
            IContainer() = default;

            /**
             * @brief Copy constructor
             */
            IContainer(const IContainer& other) = default;

            /**
             * @brief Copy assignment operator
             */
            IContainer& operator=(const IContainer& other) = default;

            /**
             * @brief Move constructor
             */
            IContainer(IContainer&& other) = default;

            /**
             * @brief Move assignment operator
             */
            IContainer& operator=(IContainer&& other) = default;

            /**
             * @brief Gets the number of elements in the container
             * @return Number of elements in the container
             */
            virtual SizeType getSize() const = 0;

            /**
             * @brief Checks if the container is empty
             * @return True if container has no elements, false otherwise
             */
            bool isEmpty() const;

            /**
             * @brief Gets pointer to the underlying data array
             * @return Const pointer to the data array
             */
            virtual const DataType* getData() const = 0;

            /**
             * @brief Gets pointer to the underlying data array
             * @return Pointer to the data array
             */
            virtual DataType* getData() = 0;

            /**
             * @brief Removes all elements from the container
             */
            virtual void clear() = 0;

            /**
             * @brief Swaps contents with another container
             * @param other Another container to swap with
             */
            virtual void swap(IContainer& other) = 0;

            /**
             * @brief Equality comparison operator
             * @param other Another container to compare with
             * @return True if containers have same size and elements, false otherwise
             */
            bool operator==(const IContainer& other) const;

            /**
             * @brief Inequality comparison operator
             * @param other Another container to compare with
             * @return True if containers are different, false otherwise
             */
            bool operator!=(const IContainer& other) const;

        protected:
            /**
             * @brief Helper method for equality comparison
             * @description Compares sizes and element-by-element contents
             */
            bool isEqual(const IContainer& other) const;
    };
}

template<class DataType, class SizeType>
bool EToolkit::IContainer<DataType, SizeType>::isEmpty() const{
	return getSize() == 0;
}

template<class DataType, class SizeType>
bool EToolkit::IContainer<DataType, SizeType>::operator==(const IContainer& other) const{
	return isEqual(other);
}

template<class DataType, class SizeType>
bool EToolkit::IContainer<DataType, SizeType>::operator!=(const IContainer& other) const{
	return !isEqual(other);
}

template<class DataType, class SizeType>
bool EToolkit::IContainer<DataType, SizeType>::isEqual(const IContainer& other) const{
	if(getSize() != other.getSize()){
		return false;
	}

	const DataType* thisData = getData();
	const DataType* otherData = other.getData();
	for(SizeType i = 0; i < getSize(); ++i){
		if(thisData[i] != otherData[i]){
			return false;
		}
	}

	return true;
}

#endif /* ICONTAINER_HPP */
