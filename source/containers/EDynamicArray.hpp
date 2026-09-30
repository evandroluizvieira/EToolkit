#ifndef EDYNAMICARRAY_HPP
#define EDYNAMICARRAY_HPP

#include <EException>

#include "interfaces/IDynamicContainer.hpp"
#include "interfaces/IIterable.hpp"

#include <new>

/**
 * @brief Evandro's Toolkit.
 */
namespace EToolkit{

	/**
	 * @brief One-dimensional dynamically sized array.
	 * @tparam DataType Type of the elements stored in the array.
	 * @implements IDynamicContainer<DataType, unsigned int>
	 * @implements IIterable<DataType>
	 * @note Capacity grows as elements are appended.
	 */
	template<class DataType>
	class DynamicArray : public IDynamicContainer<DataType, unsigned int>, public IIterable<DataType>{
		public:
			/**
			 * @brief Constructs an empty dynamic array.
			 */
			DynamicArray();

			/**
			 * @brief Constructs an array containing one value.
			 * @param data Initial value.
			 */
			DynamicArray(const DataType& data);

			/**
			 * @brief Constructs a copy of another dynamic array.
			 * @param other Array to copy.
			 */
			DynamicArray(const DynamicArray<DataType>& other);

			/**
			 * @brief Constructs an array by taking ownership of another array's storage.
			 * @param other Array whose storage is transferred.
			 */
			DynamicArray(DynamicArray<DataType>&& other);

			/**
			 * @brief Destroys the dynamic array.
			 */
			virtual ~DynamicArray();

			/**
			 * @brief Replaces the array contents with one value.
			 * @param data Value assigned to the array.
			 * @return Reference to this array.
			 */
			DynamicArray<DataType>& operator=(const DataType& data);

			/**
			 * @brief Assigns the contents of another dynamic array.
			 * @param other Array to copy.
			 * @return Reference to this array.
			 */
			DynamicArray<DataType>& operator=(const DynamicArray<DataType>& other);

			/**
			 * @brief Assigns an array by taking ownership of another array's storage.
			 * @param other Array whose storage is transferred.
			 * @return Reference to this array.
			 */
			DynamicArray<DataType>& operator=(DynamicArray<DataType>&& other);

			/**
			 * @brief Returns a copy of this array with one value appended.
			 * @param data Value to append.
			 * @return Copy of the appended array.
			 */
			DynamicArray<DataType> operator+(const DataType& data) const;

			/**
			 * @brief Returns a copy of this array with another array appended.
			 * @param other Array to append.
			 * @return Copy of the appended array.
			 */
			DynamicArray<DataType> operator+(const DynamicArray<DataType>& other) const;

			/**
			 * @brief Appends one value to this array.
			 * @param data Value to append.
			 * @return Reference to this array.
			 */
			DynamicArray<DataType>& operator+=(DataType data);

			/**
			 * @brief Appends another array to this array.
			 * @param other Array to append.
			 * @return Reference to this array.
			 */
			DynamicArray<DataType>& operator+=(const DynamicArray<DataType>& other);

			/**
			 * @brief Compares this array with another array.
			 * @param other Array to compare with.
			 * @return `true` when corresponding stored values are equal.
			 * @note Can be called on const arrays.
			 */
			bool operator==(const DynamicArray<DataType>& other) const;

			/**
			 * @brief Compares this array with another array for inequality.
			 * @param other Array to compare with.
			 * @return `true` when at least one stored value differs.
			 * @note Can be called on const arrays.
			 */
			bool operator!=(const DynamicArray<DataType>& other) const;

			/**
			 * @brief Clears the array and restores its initial capacity.
			 * @throws MemoryAllocationException If replacement storage cannot be allocated.
			 * @note Existing storage remains owned by the array until replacement storage
			 *       has been allocated successfully.
			 */
			virtual void operator!();

			/**
			 * @brief Accesses an element at the specified index.
			 * @param index Position in the array.
			 * @return Reference to the element at the specified position.
			 * @throws OutOfBoundsException If index is outside the array.
			 */
			DataType& operator[](unsigned int index);

			/**
			 * @brief Accesses an element at the specified index on a const array.
			 * @param index Position in the array.
			 * @return Const reference to the element at the specified position.
			 * @throws OutOfBoundsException If index is outside the array.
			 */
			const DataType& operator[](unsigned int index) const;

			/**
			 * @brief Gets the number of stored elements.
			 * @return Number of elements currently stored.
			 */
			unsigned int getSize() const override;

			/**
			 * @brief Gets a const pointer to the underlying storage.
			 * @return Const pointer to the first element.
			 */
			const DataType* getData() const override;

			/**
			 * @brief Gets a pointer to the underlying storage.
			 * @return Pointer to the first element.
			 */
			DataType* getData() override;

			/**
			 * @brief Removes all elements and resets the array.
			 * @throws MemoryAllocationException If replacement storage cannot be allocated.
			 * @note Existing storage remains valid until replacement storage has been
			 *       allocated successfully.
			 */
			void clear() override;

			/**
			 * @brief Exchanges contents with another container.
			 * @param other Container whose contents are exchanged with this array.
			 */
			void swap(IContainer<DataType, unsigned int>& other) override;

			/**
			 * @brief Gets the allocated capacity.
			 * @return Number of elements that can be stored without reallocating.
			 */
			unsigned int getCapacity() const override;

			/**
			 * @brief Changes the logical size of the array.
			 * @param newSize Requested number of elements.
			 */
			void resize(unsigned int newSize) override;

			/**
			 * @brief Ensures that the array can hold the requested capacity.
			 * @param newCapacity Requested capacity.
			 */
			void reserve(unsigned int newCapacity) override;

			/**
			 * @brief Gets an iterator to the first element.
			 * @return Pointer to the first element.
			 */
			DataType* begin() override;

			/**
			 * @brief Gets a const iterator to the first element.
			 * @return Const pointer to the first element.
			 */
			const DataType* begin() const override;

			/**
			 * @brief Gets an iterator past the last element.
			 * @return Pointer past the last element.
			 */
			DataType* end() override;

			/**
			 * @brief Gets a const iterator past the last element.
			 * @return Const pointer past the last element.
			 */
			const DataType* end() const override;

			/**
			 * @brief Gets a const iterator to the first element.
			 * @return Const pointer to the first element.
			 */
			const DataType* cbegin() const override;

			/**
			 * @brief Gets a const iterator past the last element.
			 * @return Const pointer past the last element.
			 */
			const DataType* cend() const override;

			/**
			 * @brief Inserts a value at the specified index.
			 * @param data Value to insert.
			 * @param index Destination index.
			 * @throws OutOfBoundsException If index is greater than the size.
			 */
			void insert(const DataType& data, unsigned int index);

			/**
			 * @brief Inserts a value at the end of the array.
			 * @param data Value to insert.
			 */
			void insertBack(const DataType& data);

			/**
			 * @brief Inserts a value at the beginning of the array.
			 * @param data Value to insert.
			 */
			void insertFront(const DataType& data);

			/**
			 * @brief Removes the value at the specified index.
			 * @param index Index of the value to remove.
			 * @throws OutOfBoundsException If index is outside the array.
			 */
			void remove(unsigned int index);

			/**
			 * @brief Removes the last value when the array is not empty.
			 */
			void removeBack();

			/**
			 * @brief Removes the first value when the array is not empty.
			 */
			void removeFront();

			/**
			 * @brief Accesses the value at the specified index.
			 * @param index Position in the array.
			 * @return Reference to the element at the specified position.
			 * @throws OutOfBoundsException If index is outside the array.
			 */
			DataType& get(unsigned int index);

			/**
			 * @brief Gets the last value.
			 * @return Reference to the last value.
			 * @throws OutOfBoundsException If the array is empty.
			 */
			DataType& getBack();

			/**
			 * @brief Gets the first value.
			 * @return Reference to the first value.
			 * @throws OutOfBoundsException If the array is empty.
			 */
			DataType& getFront();

			/**
			 * @brief Exchanges two values by index.
			 * @param index1 Index of the first value.
			 * @param index2 Index of the second value.
			 * @throws OutOfBoundsException If either index is outside the array.
			 */
			void swap(unsigned int index1, unsigned int index2);

			/**
			 * @brief Checks whether two dynamic arrays contain equal values.
			 * @param other Array to compare with.
			 * @return `true` when all corresponding stored values are equal.
			 * @note Can be called on const arrays.
			 */
			bool isEqual(const DynamicArray<DataType>& other) const;

		protected:
			/**
			 * @brief Changes the allocated capacity.
			 * @param newCapacity New capacity of the array.
			 */
			void resizeCapacity(unsigned int newCapacity);

		private:
			DataType*    data;     ///< Pointer to the allocated element storage
			unsigned int size;     ///< Number of elements currently stored
			unsigned int capacity; ///< Number of elements that can be stored
	};
}

template<class DataType>
EToolkit::DynamicArray<DataType>::DynamicArray() :
	IDynamicContainer<DataType, unsigned int>(), IIterable<DataType>(),
	data(0), size(0), capacity(0){
	clear();
}

template<class DataType>
EToolkit::DynamicArray<DataType>::DynamicArray(const DataType& value) :
	IDynamicContainer<DataType, unsigned int>(), IIterable<DataType>(),
	data(0), size(0), capacity(0){
	clear();
	data[0] = value;
	size++;
}

template<class DataType>
EToolkit::DynamicArray<DataType>::DynamicArray(const DynamicArray<DataType>& other) :
	IDynamicContainer<DataType, unsigned int>(other), IIterable<DataType>(other),
	data(0), size(0), capacity(other.capacity){
	if(capacity == 0){
		throw MemoryAllocationException();
	}else{
		data = new (std::nothrow) DataType[capacity];
		if(data == 0){
			capacity = 0;
			throw MemoryAllocationException();
		}else{
			size = other.size;
			//fill data[i] = 0? when 'i' is between size and capacity?
			for(unsigned int i = 0; i < size; i++){
				data[i] = other.data[i];
			}
		}
	}
}

template<class DataType>
EToolkit::DynamicArray<DataType>::DynamicArray(DynamicArray<DataType>&& other) :
	IDynamicContainer<DataType, unsigned int>(), IIterable<DataType>(),
	data(other.data), size(other.size), capacity(other.capacity){
	other.data = 0;
	other.size = 0;
	other.capacity = 0;
}

template<class DataType>
EToolkit::DynamicArray<DataType>::~DynamicArray(){
	if(data != 0){
		delete[] data;
		data = 0;
	}
	size = 0;
	capacity = 0;
}

template<class DataType>
EToolkit::DynamicArray<DataType>& EToolkit::DynamicArray<DataType>::operator=(const DataType& data){
	clear();
	insertBack(data);
	return *this;
}

template<class DataType>
EToolkit::DynamicArray<DataType>& EToolkit::DynamicArray<DataType>::operator=(const DynamicArray<DataType>& other){
	if(this != &other){
		clear();
		unsigned int otherSize = other.size;
		for(unsigned int i = 0; i < otherSize; i++){
			insertBack(other.data[i]);
		}
	}

	return *this;
}

template<class DataType>
EToolkit::DynamicArray<DataType>& EToolkit::DynamicArray<DataType>::operator=(DynamicArray<DataType>&& other){
	if(this != &other){
		delete[] data;
		data = other.data;
		size = other.size;
		capacity = other.capacity;
		other.data = 0;
		other.size = 0;
		other.capacity = 0;
	}
	return *this;
}

template<class DataType>
EToolkit::DynamicArray<DataType> EToolkit::DynamicArray<DataType>::operator+(const DataType& data) const{
	DynamicArray<DataType> result(*this);
	result.insertBack(data);
	return result;
}

template<class DataType>
EToolkit::DynamicArray<DataType> EToolkit::DynamicArray<DataType>::operator+(const DynamicArray<DataType>& other) const{
	DynamicArray<DataType> result(*this);
	unsigned int otherSize = other.size;
	for(unsigned int i = 0; i < otherSize; i++){
		result.insertBack(other.data[i]);
	}
	return result;
}

template<class DataType>
EToolkit::DynamicArray<DataType>& EToolkit::DynamicArray<DataType>::operator+=(DataType data){
	insertBack(data);
	return *this;
}

template<class DataType>
EToolkit::DynamicArray<DataType>& EToolkit::DynamicArray<DataType>::operator+=(const DynamicArray<DataType>& other){
	unsigned int otherSize = other.size;
	for(unsigned int i = 0; i < otherSize; i++){
		insertBack(other.data[i]);
	}
	return *this;
}

template<class DataType>
bool EToolkit::DynamicArray<DataType>::operator==(const DynamicArray<DataType>& other) const{
	return isEqual(other);
}

template<class DataType>
bool EToolkit::DynamicArray<DataType>::operator!=(const DynamicArray<DataType>& other) const{
	return !isEqual(other);
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::operator!(){
	clear();
}

template<class DataType>
DataType& EToolkit::DynamicArray<DataType>::operator[](unsigned int index){
	return get(index);
}

template<class DataType>
const DataType& EToolkit::DynamicArray<DataType>::operator[](unsigned int index) const{
	if(index >= size){
		throw OutOfBoundsException();
	}
	return data[index];
}


template<class DataType>
unsigned int EToolkit::DynamicArray<DataType>::getSize() const{
	return size;
}

template<class DataType>
const DataType* EToolkit::DynamicArray<DataType>::getData() const{
	return data;
}

template<class DataType>
DataType* EToolkit::DynamicArray<DataType>::getData(){
	return data;
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::clear(){
	DataType* newData = new (std::nothrow) DataType[2]();
	if(newData == 0){
		throw MemoryAllocationException();
	}
	delete[] data;
	data = newData;
	size = 0;
	capacity = 2;
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::swap(IContainer<DataType, unsigned int>& other){
	DynamicArray<DataType>& dynamicOther = dynamic_cast<DynamicArray<DataType>&>(other);
	DataType* temporaryData = data;
	data = dynamicOther.data;
	dynamicOther.data = temporaryData;
	unsigned int temporarySize = size;
	size = dynamicOther.size;
	dynamicOther.size = temporarySize;
	unsigned int temporaryCapacity = capacity;
	capacity = dynamicOther.capacity;
	dynamicOther.capacity = temporaryCapacity;
}

template<class DataType>
unsigned int EToolkit::DynamicArray<DataType>::getCapacity() const{
	return capacity;
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::resize(unsigned int newSize){
	if(newSize > capacity){
		resizeCapacity(newSize);
	}
	if(newSize > size){
		for(unsigned int i = size; i < newSize; ++i){
			data[i] = DataType();
		}
	}
	size = newSize;
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::reserve(unsigned int newCapacity){
	if(newCapacity > capacity){
		resizeCapacity(newCapacity);
	}
}

template<class DataType>
DataType* EToolkit::DynamicArray<DataType>::begin(){
	return data;
}

template<class DataType>
const DataType* EToolkit::DynamicArray<DataType>::begin() const{
	return data;
}

template<class DataType>
DataType* EToolkit::DynamicArray<DataType>::end(){
	return data + size;
}

template<class DataType>
const DataType* EToolkit::DynamicArray<DataType>::end() const{
	return data + size;
}

template<class DataType>
const DataType* EToolkit::DynamicArray<DataType>::cbegin() const{
	return data;
}

template<class DataType>
const DataType* EToolkit::DynamicArray<DataType>::cend() const{
	return data + size;
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::insert(const DataType& value, unsigned int index){
	if(index > size){
		throw OutOfBoundsException();
	}
	if(size >= capacity){
		resizeCapacity(capacity * 2);
	}
	for(unsigned int i = size; i > index; i--){
		data[i] = data[i - 1];
	}
	data[index] = value;
	size++;
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::insertBack(const DataType& value){
	if(size >= capacity){
		resizeCapacity(capacity * 2);
	}
	data[size] = value;
	size++;
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::insertFront(const DataType& value){
	if(size >= capacity){
		resizeCapacity(capacity * 2);
	}
	for(unsigned int i = size; i > 0; i--){
		data[i] = data[i - 1];
	}
	data[0] = value;
	size++;
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::remove(unsigned int index){
	if(index >= size){
		throw OutOfBoundsException();
	}
	for(unsigned int i = index; i < size - 1; i++){
		data[i] = data[i + 1];
	}
	size--;
	unsigned int newCapacity = capacity / 2;
	if(size <= newCapacity){
		resizeCapacity(newCapacity);
	}
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::removeBack(){
	if(size > 0){
		size--;
		unsigned int newCapacity = capacity / 2;
		if(size <= newCapacity){
			resizeCapacity(newCapacity);
		}
	}
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::removeFront(){
	if(size > 0){
		for(unsigned int i = 0; i < size - 1; i++){
			data[i] = data[i + 1];
		}
		size--;
		unsigned int newCapacity = capacity / 2;
		if(size <= newCapacity){
			resizeCapacity(newCapacity);
		}
	}
}

template<class DataType>
DataType& EToolkit::DynamicArray<DataType>::get(unsigned int index){
	if(index >= size){
		throw OutOfBoundsException();
	}
	return data[index];
}

template<class DataType>
DataType& EToolkit::DynamicArray<DataType>::getBack(){
	if(size == 0){
		throw OutOfBoundsException();
	}
	return data[size - 1];
}

template<class DataType>
DataType& EToolkit::DynamicArray<DataType>::getFront(){
	if(size == 0){
		throw OutOfBoundsException();
	}
	return data[0];
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::swap(unsigned int index1, unsigned int index2){
	if(index1 >= size || index2 >= size){
		throw OutOfBoundsException();
	}
	DataType temporaryData = data[index1];
	data[index1] = data[index2];
	data[index2] = temporaryData;
}

template<class DataType>
bool EToolkit::DynamicArray<DataType>::isEqual(const DynamicArray<DataType>& other) const{
	if(size != other.size){
		return false;
	}
	for(unsigned int i = 0; i < size; i++){
		if(data[i] != other.data[i]){
			return false;
		}
	}
	return true;
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::resizeCapacity(unsigned int newCapacity){
	if(newCapacity < 2){
		newCapacity = 2;
	}
	DataType* newData = new DataType[newCapacity];
	//fill newData[i] = 0? when 'i' is between size and newCapacity?
	for(unsigned int i = 0; i < size; i++){
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	capacity = newCapacity;
}

#endif /* EDYNAMICARRAY_HPP */
