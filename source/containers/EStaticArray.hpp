#ifndef ESTATICARRAY_HPP
#define ESTATICARRAY_HPP

#include <EException>

#include <initializer_list>

#include "interfaces/IIterable.hpp"
#include "interfaces/IStaticContainer.hpp"

/**
 * @brief Evandro's Toolkit.
 */
namespace EToolkit{

	/**
	 * @brief One-dimensional compile-time-sized array.
	 * @tparam DataType Type of the elements stored in the array.
	 * @tparam SizeType Type used for indices and the size value.
	 * @tparam SizeValue Number of elements in the array.
	 * @note SizeValue must be greater than zero. A zero-sized StaticArray
	 *       is rejected at compile time.
	 * @implements IStaticContainer<DataType, SizeType, SizeValue>
	 * @implements IIterable<DataType>
	 */
	template<class DataType, class SizeType = unsigned int, SizeType SizeValue = 1>
	class StaticArray : public IStaticContainer<DataType, SizeType, SizeValue>, public IIterable<DataType>{
		template<class VectorType, unsigned int VectorLength>
		friend class Vector;
		template<class Vector2DType, unsigned int Vector2DLength>
		friend class Vector2D;
		template<class Vector3DType, unsigned int Vector3DLength>
		friend class Vector3D;
		template<class Vector4DType>
		friend class Vector4D;
		template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
		friend class Matrix;

		public:
			/**
			 * @brief Constructs an empty static array.
			 */
			StaticArray() = default;

			/**
			 * @brief Constructs an array from an initializer list.
			 * @param list Values copied into the array until it is full.
			 */
			StaticArray(const std::initializer_list<DataType>& list);

			/**
			 * @brief Constructs an array by moving another static array.
			 * @param other Array whose elements are moved.
			 */
			StaticArray(StaticArray&& other) = default;

			/**
			 * @brief Destroys the static array.
			 */
			virtual ~StaticArray() = default;

			/**
			 * @brief Assigns the contents of another static array.
			 * @param other Array whose contents are copied.
			 * @return Reference to this array.
			 */
			StaticArray& operator=(const StaticArray& other) = default;

			/**
			 * @brief Assigns the contents of another static array by move.
			 * @param other Array whose contents are moved.
			 * @return Reference to this array.
			 */
			StaticArray& operator=(StaticArray&& other) = default;

			/**
			 * @brief Accesses an element at the specified index.
			 * @param index Position in the array.
			 * @return Reference to the element at the specified position.
			 * @throws OutOfBoundsException If index is outside the array.
			 */
			DataType& operator[](SizeType index) override;

			/**
			 * @brief Access element at given index (read-only for const objects).
			 * @param index Position in the array.
			 * @return Const reference to the data at the index.
			 */
			const DataType& operator[](SizeType index) const override;

			/**
			 * @brief Gets the compile-time number of elements.
			 * @return Number of elements in the array.
			 */
			SizeType getSize() const override;

			/**
			 * @brief Accesses an element with bounds checking.
			 * @param index Position in the array.
			 * @return Reference to the element at the specified position.
			 * @throws OutOfBoundsException If index is outside the array.
			 */
			DataType& at(SizeType index) override;

			/**
			 * @brief Accesses an element with bounds checking on a const array.
			 * @param index Position in the array.
			 * @return Const reference to the element at the specified position.
			 * @throws OutOfBoundsException If index is outside the array.
			 */
			const DataType& at(SizeType index) const override;

			/**
			 * @brief Gets the first element.
			 * @return Reference to the first element.
			 */
			DataType& getFront() override;

			/**
			 * @brief Gets the first element from a const array.
			 * @return Const reference to the first element.
			 */
			const DataType& getFront() const override;

			/**
			 * @brief Gets the last element.
			 * @return Reference to the last element.
			 */
			DataType& getBack() override;

			/**
			 * @brief Gets the last element from a const array.
			 * @return Const reference to the last element.
			 */
			const DataType& getBack() const override;

			/**
			 * @brief Fills every element with a value.
			 * @param data Value assigned to every element.
			 */
			void fill(const DataType& data) override;

			/**
			 * @brief Gets a pointer to the underlying storage.
			 * @return Pointer to the first element.
			 */
			DataType* getData() override;

			/**
			 * @brief Gets a const pointer to the underlying storage.
			 * @return Const pointer to the first element.
			 */
			const DataType* getData() const override;

			/**
			 * @brief Clears all elements using value initialization.
			 */
			void clear() override;

			/**
			 * @brief Swaps contents with another container of the same static type.
			 * @param other Container whose contents are exchanged with this array.
			 */
			void swap(IContainer<DataType, SizeType>& other) override;

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
			 * @brief Compares this array with another static array.
			 * @param other Array to compare with.
			 * @return `true` when both arrays contain equal values.
			 */
			bool operator==(const StaticArray& other) const;

			/**
			 * @brief Compares this array with another static array for inequality.
			 * @param other Array to compare with.
			 * @return `true` when at least one value differs.
			 */
			bool operator!=(const StaticArray& other) const;

			/**
			 * @brief Clears all elements in the array.
			 */
			void operator!();

			/**
			 * @brief Swaps two elements by index.
			 * @param index1 Index of the first element.
			 * @param index2 Index of the second element.
			 * @throws OutOfBoundsException If either index is outside the array.
			 */
			void swap(unsigned int index1, unsigned int index2);

			/**
			 * @brief Checks whether two static arrays contain equal values.
			 * @param other Array to compare with.
			 * @return `true` when all corresponding values are equal.
			 */
			bool isEqual(const StaticArray& other) const;

			/**
			 * @brief Checks whether the array contains a value.
			 * @param data Value to find.
			 * @return `true` when the value is present.
			 */
			bool contains(const DataType& data) const;

		private:
			DataType data[SizeValue];
	};
}

template<class DataType, class SizeType, SizeType SizeValue>
EToolkit::StaticArray<DataType, SizeType, SizeValue>::StaticArray(const std::initializer_list<DataType>& list) :
	IStaticContainer<DataType, SizeType, SizeValue>(), IIterable<DataType>(){
	SizeType index = 0;
	for(const DataType& value : list){
		if(index == SizeValue){
			break;
		}
		data[index++] = value;
	}
}

template<class DataType, class SizeType, SizeType SizeValue>
DataType& EToolkit::StaticArray<DataType, SizeType, SizeValue>::operator[](SizeType index){
	return at(index);
}

template<class DataType, class SizeType, SizeType SizeValue>
const DataType& EToolkit::StaticArray<DataType, SizeType, SizeValue>::operator[](SizeType index) const{
	return at(index);
}

template<class DataType, class SizeType, SizeType SizeValue>
SizeType EToolkit::StaticArray<DataType, SizeType, SizeValue>::getSize() const{
	return SizeValue;
}

template<class DataType, class SizeType, SizeType SizeValue>
DataType& EToolkit::StaticArray<DataType, SizeType, SizeValue>::at(SizeType index){
	if(index >= SizeValue){
		throw OutOfBoundsException();
	}
	return data[index];
}

template<class DataType, class SizeType, SizeType SizeValue>
const DataType& EToolkit::StaticArray<DataType, SizeType, SizeValue>::at(SizeType index) const{
	if(index >= SizeValue){
		throw OutOfBoundsException();
	}
	return data[index];
}

template<class DataType, class SizeType, SizeType SizeValue>
DataType& EToolkit::StaticArray<DataType, SizeType, SizeValue>::getFront(){
	return data[0];
}

template<class DataType, class SizeType, SizeType SizeValue>
const DataType& EToolkit::StaticArray<DataType, SizeType, SizeValue>::getFront() const{
	return data[0];
}

template<class DataType, class SizeType, SizeType SizeValue>
DataType& EToolkit::StaticArray<DataType, SizeType, SizeValue>::getBack(){
	return data[SizeValue - 1];
}

template<class DataType, class SizeType, SizeType SizeValue>
const DataType& EToolkit::StaticArray<DataType, SizeType, SizeValue>::getBack() const{
	return data[SizeValue - 1];
}

template<class DataType, class SizeType, SizeType SizeValue>
void EToolkit::StaticArray<DataType, SizeType, SizeValue>::fill(const DataType& value){
	for(SizeType index = 0; index < SizeValue; ++index){
		data[index] = value;
	}
}

template<class DataType, class SizeType, SizeType SizeValue>
DataType* EToolkit::StaticArray<DataType, SizeType, SizeValue>::getData(){
	return data;
}

template<class DataType, class SizeType, SizeType SizeValue>
const DataType* EToolkit::StaticArray<DataType, SizeType, SizeValue>::getData() const{
	return data;
}

template<class DataType, class SizeType, SizeType SizeValue>
void EToolkit::StaticArray<DataType, SizeType, SizeValue>::clear(){
	fill(DataType());
}

template<class DataType, class SizeType, SizeType SizeValue>
void EToolkit::StaticArray<DataType, SizeType, SizeValue>::swap(IContainer<DataType, SizeType>& other){
	StaticArray& staticOther = dynamic_cast<StaticArray&>(other);
	for(SizeType index = 0; index < SizeValue; ++index){
		DataType temporary = data[index];
		data[index] = staticOther.data[index];
		staticOther.data[index] = temporary;
	}
}

template<class DataType, class SizeType, SizeType SizeValue>
DataType* EToolkit::StaticArray<DataType, SizeType, SizeValue>::begin(){
	return data;
}

template<class DataType, class SizeType, SizeType SizeValue>
const DataType* EToolkit::StaticArray<DataType, SizeType, SizeValue>::begin() const{
	return data;
}

template<class DataType, class SizeType, SizeType SizeValue>
DataType* EToolkit::StaticArray<DataType, SizeType, SizeValue>::end(){
	return data + SizeValue;
}

template<class DataType, class SizeType, SizeType SizeValue>
const DataType* EToolkit::StaticArray<DataType, SizeType, SizeValue>::end() const{
	return data + SizeValue;
}

template<class DataType, class SizeType, SizeType SizeValue>
const DataType* EToolkit::StaticArray<DataType, SizeType, SizeValue>::cbegin() const{
	return data;
}

template<class DataType, class SizeType, SizeType SizeValue>
const DataType* EToolkit::StaticArray<DataType, SizeType, SizeValue>::cend() const{
	return data + SizeValue;
}

template<class DataType, class SizeType, SizeType SizeValue>
bool EToolkit::StaticArray<DataType, SizeType, SizeValue>::operator==(const StaticArray& other) const{
	return isEqual(other);
}

template<class DataType, class SizeType, SizeType SizeValue>
bool EToolkit::StaticArray<DataType, SizeType, SizeValue>::operator!=(const StaticArray& other) const{
	return !isEqual(other);
}

template<class DataType, class SizeType, SizeType SizeValue>
void EToolkit::StaticArray<DataType, SizeType, SizeValue>::operator!(){
	clear();
}

template<class DataType, class SizeType, SizeType SizeValue>
void EToolkit::StaticArray<DataType, SizeType, SizeValue>::swap(unsigned int index1, unsigned int index2){
	if(index1 >= SizeValue || index2 >= SizeValue){
		throw OutOfBoundsException();
	}
	DataType temporary = data[index1];
	data[index1] = data[index2];
	data[index2] = temporary;
}

template<class DataType, class SizeType, SizeType SizeValue>
bool EToolkit::StaticArray<DataType, SizeType, SizeValue>::isEqual(const StaticArray& other) const{
	for(SizeType index = 0; index < SizeValue; ++index){
		if(data[index] != other.data[index]){
			return false;
		}
	}
	return true;
}

template<class DataType, class SizeType, SizeType SizeValue>
bool EToolkit::StaticArray<DataType, SizeType, SizeValue>::contains(const DataType& value) const{
	for(SizeType index = 0; index < SizeValue; ++index){
		if(data[index] == value){
			return true;
		}
	}
	return false;
}

#endif /* ESTATICARRAY_HPP */
