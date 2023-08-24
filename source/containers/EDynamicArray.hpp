#ifndef EDYNAMICARRAY_HPP
#define EDYNAMICARRAY_HPP

#include <EException>

#include <new>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent a 1 dimensional dynamic size array.
	 * @note: This array holds a 'capacity' value that doubles when the 'size' reach the 'capacity' value.
	 */
	template<class DataType>
	class DynamicArray{
		public:
			/*
			 * @description: Default constructor.
			 * @return: None.
			 */
			DynamicArray();

			/*
			 * @description: Constructor that initializes the object with a copy of the the given 'data'.
			 * @return: None.
			 */
			DynamicArray(const DataType& data);

			/*
			 * @description: Constructor that initializes the object with a copy of the the given 'other' array.
			 * @return: None.
			 */
			DynamicArray(const DynamicArray<DataType>& other);

			/*
			 * @description: Default inheritable destructor that clear the object.
			 * @return: None.
			 */
			virtual ~DynamicArray();

			/*
			 * @description: Operator that set the content of the array with the given 'data'.
			 * @return: Reference to itself.
			 */
			DynamicArray<DataType>& operator=(const DataType& data);

			/*
			 * @description: Operator that set the content of the array with the given 'other' array.
			 * @return: Reference to itself.
			 */
			DynamicArray<DataType>& operator=(const DynamicArray<DataType>& other);

			/*
			 * @description: Operator that append this array and 'data' into a new array.
			 * @return: Copy of appended array.
			 * @note: Same as 'insertBack(other)'.
			 */
			DynamicArray<DataType> operator+(const DataType& data) const;

			/*
			 * @description: Operator that append this array and 'other' array into a new array.
			 * @return: Copy of appended array.
			 * @note: Same as 'insertBack' for each element in 'other' array.
			 */
			DynamicArray<DataType> operator+(const DynamicArray<DataType>& other) const;

			/*
			 * @description: Operator that append the 'data' into the current array.
			 * @return: Reference to itself.
			 */
			DynamicArray<DataType>& operator+=(DataType data);

			/*
			 * @description: Operator that append the 'other' array into the current array.
			 * @return: Reference to itself.
			 */
			DynamicArray<DataType>& operator+=(const DynamicArray<DataType>& other);

			/*
			 * @description: Operator that check if the 'size', 'capacity' and any of the elements values (in the same index) are equals to elements of the given 'other' array.
			 * @return: True if yes or false otherwise.
			 * @note: Same as 'isEqual(other)'.
			 */
			bool operator==(const DynamicArray<DataType>& other);

			/*
			 * @description: Operator that check if the 'size', 'capacity' and any of the elements values (in the same index) are not equals to elements of the given 'other' array.
			 * @return: True if yes or false otherwise.
			 * @note: Same as '!isEqual(other)'.
			 */
			bool operator!=(const DynamicArray<DataType>& other);

			/*
			 * @description: Operator that reset the array with no data, with the initial 'size' and 'capacity'.
			 * @return: None.
			 * @note: Same as 'clear()'.
			 */
			virtual void operator!();

			/*
			 * @description: Operator to get the 'DataType' of the given 'index'.
			 * @return: Reference of the data in the 'index' position if 'index' is valid.
			 * @note: Same as 'get(index)'.
			 */
			DataType& operator[](unsigned int index);

			/*
			 * @description: Function that add 'data' at 'index' position in the array.
			 * @return: None.
			 */
			void insert(const DataType& data, unsigned int index);

			/*
			 * @description: Function that add 'data' at the end of the array.
			 * @return: None.
			 */
			void insertBack(const DataType& data);

			/*
			 * @description: Function that add 'data' at the end of the array.
			 * @return: None.
			 */
			void insertFront(const DataType& data);

			/*
			 * @description: Function that remove 'data' from the 'index' position of the array.
			 * @return: None.
			 */
			void remove(unsigned int index);

			/*
			 * @description: Function that remove the last data of the array.
			 * @return: None.
			 */
			void removeBack();

			/*
			 * @description: Function that remove the first data of the array.
			 * @return: None.
			 */
			void removeFront();

			/*
			 * @description: Function to get the 'DataType' of the given 'index'.
			 * @return: Reference of the data in the 'index' position if 'index' is valid.
			 */
			DataType& get(unsigned int index);

			/*
			 * @description: Operator to get the last 'DataType''.
			 * @return: Reference of the last data, if there is.
			 */
			DataType& getBack();

			/*
			 * @description: Operator to get the first 'DataType''.
			 * @return: Reference of the first data, if there is.
			 */
			DataType& getFront();

			/*
			 * @description: Function that reset the array and leave it with no data, with the initial 'size' and 'capacity'.
			 * @return: None.
			 */
			void clear();

			/*
			 * @description: Function that change with each other the object data in 'index1' and 'index2' position of the array.
			 * @return: None.
			 */
			void swap(unsigned int index1, unsigned int index2);

			/*
			 * @description: Function that check if the 'size', 'capacity' and any of the elements values (in the same index) are equals to elements of the given 'other' array.
			 * @return: True if yes or false otherwise.
			 */
			bool isEqual(const DynamicArray<DataType>& other);

			/*
			 * @description: Function to get the number of instances of 'DataType' in 'data'.
			 * @return: Copy of the size.
			 */
			unsigned int getSize() const;

			/*
			 * @description: Function to get the maximum number of instances of 'DataType' that 'data' can have.
			 * @return: Copy of the capacity.
			 */
			unsigned int getCapacity() const;

		private:
			void resize(unsigned int newCapacity);

		private:
			DataType* data;
			unsigned int size;
			unsigned int capacity;
	};
}

template<class DataType>
EToolkit::DynamicArray<DataType>::DynamicArray() :
	data(0), size(0), capacity(0){
	clear();
}

template<class DataType>
EToolkit::DynamicArray<DataType>::DynamicArray(const DataType& value) :
	data(0), size(0), capacity(0){
	clear();
	data[0] = value;
	size++;
}

template<class DataType>
EToolkit::DynamicArray<DataType>::DynamicArray(const DynamicArray<DataType>& other) :
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
bool EToolkit::DynamicArray<DataType>::operator==(const DynamicArray<DataType>& other){
	return isEqual(other);
}

template<class DataType>
bool EToolkit::DynamicArray<DataType>::operator!=(const DynamicArray<DataType>& other){
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
void EToolkit::DynamicArray<DataType>::insert(const DataType& value, unsigned int index){
	if(index >= size){
		throw OutOfBoundsException();
	}
    if(size >= capacity){
        resize(capacity * 2);
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
		resize(capacity * 2);
	}
	data[size] = value;
	size++;
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::insertFront(const DataType& value){
	if(size >= capacity){
		resize(capacity * 2);
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
		resize(newCapacity);
	}
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::removeBack(){
	if(size > 0){
		size--;
		unsigned int newCapacity = capacity / 2;
		if(size <= newCapacity){
			resize(newCapacity);
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
			resize(newCapacity);
		}
	}
}

template<class DataType>
DataType& EToolkit::DynamicArray<DataType>::get(unsigned int index){
	if(index >= size){
		throw OutOfBoundsException();
	}else{
		return data[index];
	}
}

template<class DataType>
DataType& EToolkit::DynamicArray<DataType>::getBack(){
	if(size == 0){
		throw OutOfBoundsException();
	}else{
		return data[size - 1];
	}
}

template<class DataType>
DataType& EToolkit::DynamicArray<DataType>::getFront(){
	if(size == 0){
		throw OutOfBoundsException();
	}else{
		return data[0];
	}
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::clear(){
	if(data != 0){
		delete[] data;
	}

	data = new (std::nothrow) DataType[2];
	if(data == 0){
		throw MemoryAllocationException();
	}else{
		data[0] = 0;
		data[1] = 0;
		size = 0;
		capacity = 2;
	}
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::swap(unsigned int index1, unsigned int index2){
	if(index1 >= size || index2 >= size){
		throw OutOfBoundsException();
	}else{
		DataType temporaryData = data[index1];
		data[index1] = data[index2];
		data[index2] = temporaryData;
	}
}

template<class DataType>
bool EToolkit::DynamicArray<DataType>::isEqual(const DynamicArray<DataType>& other){
	if(size == other.size){
		for(unsigned int i = 0; i < size; i++){
			if(data[i] != other.data[i]){
				return false;
			}
		}
		return true;
	}
	return false;
}

template<class DataType>
unsigned int EToolkit::DynamicArray<DataType>::getSize() const{
	return size;
}

template<class DataType>
unsigned int EToolkit::DynamicArray<DataType>::getCapacity() const{
	return capacity;
}

template<class DataType>
void EToolkit::DynamicArray<DataType>::resize(unsigned int newCapacity){
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
