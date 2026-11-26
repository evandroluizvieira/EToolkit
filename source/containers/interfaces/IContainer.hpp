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
     * @tparam DataType Type of the elements stored in the container.
     * @tparam SizeType Type used for size operations and indices.
     */
    template<class DataType, class SizeType>
    class IContainer{
        public:
            /**
             * @brief Constructs an empty interface object.
             */
            IContainer() = default;

            /**
             * @brief Constructs an interface object from another interface object.
             * @param other Interface object to copy.
             */
            IContainer(const IContainer& other) = default;

            /**
             * @brief Constructs an interface object by moving another interface object.
             * @param other Interface object to move from.
             */
            IContainer(IContainer&& other) = default;

            /**
             * @brief Destroys the interface object through its base pointer.
             */
            virtual ~IContainer() = default;

            /**
             * @brief Copies the state of another interface object.
             * @param other Interface object to copy.
             * @return Reference to this interface object.
             */
            IContainer& operator=(const IContainer& other) = default;

            /**
             * @brief Moves the state of another interface object.
             * @param other Interface object to move from.
             * @return Reference to this interface object.
             */
            IContainer& operator=(IContainer&& other) = default;

            /**
             * @brief Checks whether two containers have equal sizes and elements.
             * @param other Container to compare with this one.
             * @return True when both containers have equal contents; otherwise false.
             */
            bool operator==(const IContainer& other) const;

            /**
             * @brief Checks whether two containers have different sizes or elements.
             * @param other Container to compare with this one.
             * @return True when the containers differ; otherwise false.
             */
            bool operator!=(const IContainer& other) const;

            /**
             * @brief Gets the number of elements in the container.
             * @return Number of elements currently stored.
             */
            virtual SizeType getSize() const = 0;

            /**
             * @brief Checks whether the container contains no elements.
             * @return True when the container is empty; otherwise false.
             */
            bool isEmpty() const;

            /**
             * @brief Gets a const pointer to the underlying element data.
             * @return Pointer to the first element, or nullptr when no data is available.
             */
            virtual const DataType* getData() const = 0;

            /**
             * @brief Gets a mutable pointer to the underlying element data.
             * @return Pointer to the first element, or nullptr when no data is available.
             */
            virtual DataType* getData() = 0;

            /**
             * @brief Removes all elements from the container.
             */
            virtual void clear() = 0;

            /**
             * @brief Swaps contents with another container.
             * @param other Container whose contents are exchanged with this container.
             */
            virtual void swap(IContainer& other) = 0;

        protected:
            /**
             * @brief Compares sizes and element-by-element contents.
             * @param other Container to compare with this one.
             * @return True when sizes and elements are equal; otherwise false.
             */
            bool isEqual(const IContainer& other) const;
    };
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
bool EToolkit::IContainer<DataType, SizeType>::isEmpty() const{
    return getSize() == 0;
}

template<class DataType, class SizeType>
bool EToolkit::IContainer<DataType, SizeType>::isEqual(const IContainer& other) const{
	if(getSize() != other.getSize()){
		return false;
	}

	if(getSize() == 0){
		return true;
	}

	const DataType* thisData = getData();
	const DataType* otherData = other.getData();
	if(thisData == nullptr || otherData == nullptr){
		return false;
	}

	for(SizeType i = 0; i < getSize(); ++i){
		if(thisData[i] != otherData[i]){
			return false;
		}
	}

	return true;
}

#endif /* ICONTAINER_HPP */
