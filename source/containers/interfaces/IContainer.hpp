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
             * @brief Default constructor
             */
            IContainer() = default;

            /**
             * @brief Copy constructor
             */
            IContainer(const IContainer& other) = default;

            /**
             * @brief Move constructor
             */
            IContainer(IContainer&& other) = default;

            /**
             * @brief Virtual destructor for proper inheritance and resource cleanup
             */
            virtual ~IContainer() = default;

            /**
             * @brief Copy assignment operator
             */
            IContainer& operator=(const IContainer& other) = default;

            /**
             * @brief Move assignment operator
             */
            IContainer& operator=(IContainer&& other) = default;

            /**
             * @brief Equality comparison operator
             */
            bool operator==(const IContainer& other) const;

            /**
             * @brief Inequality comparison operator
             */
            bool operator!=(const IContainer& other) const;

            /**
             * @brief Gets the number of elements in the container
             */
            virtual SizeType getSize() const = 0;

            /**
             * @brief Checks if the container is empty
             */
            bool isEmpty() const;

            /**
             * @brief Gets a const pointer to the underlying data
             */
            virtual const DataType* getData() const = 0;

            /**
             * @brief Gets a pointer to the underlying data
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

        protected:
            /**
             * @brief Compares sizes and element-by-element contents
             * @param other Another container to compare with
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
