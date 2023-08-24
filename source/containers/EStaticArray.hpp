#ifndef ESTATICARRAY_HPP
#define ESTATICARRAY_HPP

#include <EException>

#include <new>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent a 1 dimensional static size array.
	 */
	template<class DataType>
	class StaticArray{
		public:
			/*
			 * @description: Default constructor that initialize object with the given array 'size'.
			 * @return: None.
			 */
			StaticArray(unsigned int size);

			/*
			 * @description: Default constructor that initialize object with the given 'array' and fill with it's values.
			 * @return: None.
			 * @note: The values are copied before or until the sizes match.
			 */
			StaticArray(const StaticArray<DataType>& other);

			/*
			 * @description: Default inheritable destructor that clear the object.
			 * @return: None.
			 */
			virtual ~StaticArray();

			/*
			 * @description: Operator that set the content of the object with the given 'other' array.
			 * @return: Reference to itself.
			 */
			StaticArray<DataType>& operator=(const StaticArray<DataType>& other);

			/*
			 * @description: Operator to get the 'DataType' of the given 'index'.
			 * @return: Reference of the data in the 'index' position if 'index' is valid.
			 */
			DataType& operator[](unsigned int index);

			/*
			 * @description: Operator that check if the 'size' and all elements values are equals to elements of the given 'other' vector.
			 * @return: True if yes or false otherwise.
			 * @note: Same as 'isEqual(other)'.
			 */
			bool operator==(const StaticArray<DataType>& other);

			/*
			 * @description: Operator that check if the 'size' and any of the elements values are not equals to elements of the given 'other' vector in the same position.
			 * @return: True if yes or false otherwise.
			 * @note: Same as '!isEqual(other)'.
			 */
			bool operator!=(const StaticArray<DataType>& other);

			/*
			 * @description: Operator that clear all data.
			 * @return: None.
			 * @note: Same as 'clear()'.
			 */
			void operator!();

			/*
			 * @description: Function that fill object with zero value in each position of the array.
			 * @return: None.
			 * @note: Same as 'fill(0)'.
			 */
			void clear();

			/*
			 * @description: Function that fill object with the given 'data' value in each position of the array.
			 * @return: None.
			 */
			void fill(const DataType& data);

			/*
			 * @description: Function that change with each other the object data in 'index1' and 'index2' position of the array.
			 * @return: None.
			 */
			void swap(unsigned int index1, unsigned int index2);

			/*
			 * @description: Function that check if the 'size' and all elements values are equals to elements of the given 'other' vector.
			 * @return: True if yes or false otherwise.
			 */
			bool isEqual(const StaticArray<DataType>& other);

			/*
			 * @description: Function to get the size of the data array.
			 * @return: Copy of the size.
			 */
			unsigned int getSize() const;

		private:
			DataType* data;
			unsigned int size;
	};
}

template<class DataType>
EToolkit::StaticArray<DataType>::StaticArray(unsigned int size) :
	data(0), size(size){
	if(size == 0){
		throw MemoryAllocationException();
	}else{
		data = new (std::nothrow) DataType[size];
		if(data == 0){
			this->size = 0;
			throw MemoryAllocationException();
		}
	}
}

template<class DataType>
EToolkit::StaticArray<DataType>::StaticArray(const StaticArray<DataType>& other) :
	data(0), size(other.size){
	if(size == 0){
		throw MemoryAllocationException();
	}else{
		data = new (std::nothrow) DataType[size];
		if(data == 0){
			this->size = 0;
			throw MemoryAllocationException();
		}else{
			for(unsigned int i = 0; i < size; i++){
				data[i] = other.data[i];
			}
		}
	}
}

template<class DataType>
EToolkit::StaticArray<DataType>::~StaticArray(){
	if(data != 0){
		delete[] data;
		data = 0;
	}
	size = 0;
}

template<class DataType>
EToolkit::StaticArray<DataType>& EToolkit::StaticArray<DataType>::operator=(const StaticArray<DataType>& other){
	if(this != &other){
		for(unsigned int i = 0; i < size; i++){
			if(i < other.size){
				data[i] = other.data[i];
			}
		}
	}
	return *this;
}

template<class DataType>
DataType& EToolkit::StaticArray<DataType>::operator[](unsigned int index){
	if(index >= size){
		throw OutOfBoundsException();
	}else{
		return data[index];
	}
}

template<class DataType>
bool EToolkit::StaticArray<DataType>::operator==(const StaticArray<DataType>& other){
	return isEqual(other);
}

template<class DataType>
bool EToolkit::StaticArray<DataType>::operator!=(const StaticArray<DataType>& other){
	return !isEqual(other);
}

template<class DataType>
void EToolkit::StaticArray<DataType>::operator!(){
	clear();
}

template<class DataType>
void EToolkit::StaticArray<DataType>::clear(){
	fill(0);
}

template<class DataType>
void EToolkit::StaticArray<DataType>::fill(const DataType& data){
	for(unsigned int i = 0; i < size; i++){
		this->data[i] = data;
	}
}

template<class DataType>
void EToolkit::StaticArray<DataType>::swap(unsigned int index1, unsigned int index2){
	if(index1 >= size || index2 >= size){
		throw OutOfBoundsException();
	}else{
		DataType temporaryData = data[index1];
		data[index1] = data[index2];
		data[index2] = temporaryData;
	}
}

template<class DataType>
bool EToolkit::StaticArray<DataType>::isEqual(const StaticArray<DataType>& other){
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
unsigned int EToolkit::StaticArray<DataType>::getSize() const{
	return size;
}

#endif /* ESTATICARRAY_HPP */
