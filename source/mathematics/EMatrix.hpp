#ifndef EMATRIX_HPP
#define EMATRIX_HPP

#include <EContainer>
#include <EException>

#include <initializer_list>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Spatial two-dimension generic base class.
	 * @note: 'MatrixType' must be numeric. 'MatrixRows' and 'MatrixColumns' must be greater than 0.
	 */
	template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
	class Matrix : public StaticArray<MatrixType>{
		public:
			/*
			 * @description: Default constructor, if 'zeroed' is true initializes everything with cleared data.
			 * @return: None.
			 */
			Matrix(bool zeroed = true);

			/*
			 * @description: Default constructor that initialize object with the 'list' if is valid otherwise initializes everything with cleared data.
			 * @return: None.
			 * @note: Elements in 'list' will be added only if 'MatrixRows*MatrixColumns' are equal to 'list.size()'.
			 */
			Matrix(const std::initializer_list<MatrixType>& list);

			/*
			 * @description: Default constructor that initialize object with the 'list' if is valid otherwise initializes everything with cleared data.
			 * @return: None.
			 * @note: Elements in 'list' will be added only if 'MatrixRows*MatrixColumns' are equal to the sum of the number of elements in the 'list' and all sublist.
			 */
			Matrix(const std::initializer_list<std::initializer_list<MatrixType>>& list);

			/*
			 * @description: Default destructor.
			 * @return: None.
			 */
			virtual ~Matrix();

			/*
			 * @description: Operator to get the 'MatrixType' at the given 'row' and column.
			 * @return: Reference of the data at that position.
			 */
			MatrixType& operator()(unsigned int row, unsigned int column);

			/*
			 * @description: Operator that applies addition with the given 'scalar' value to each element of this matrix.
			 * @return: A copy of a Matrix<MatrixType, MatrixRows, MatrixColumns>.
			 */
			Matrix<MatrixType, MatrixRows, MatrixColumns> operator+(const MatrixType& scalar) const;

			/*
			 * @description: Operator that applies addition with the given 'other' matrix.
			 * @return: A copy of a Matrix<MatrixType, MatrixRows, MatrixColumns>.
			 */
			Matrix<MatrixType, MatrixRows, MatrixColumns> operator+(const Matrix<MatrixType, MatrixRows, MatrixColumns>& other) const;

			/*
			 * @description: Operator that applies subtraction with the given 'scalar' value to each element of this matrix.
			 * @return: A copy of a Matrix<MatrixType, MatrixRows, MatrixColumns>.
			 */
			Matrix<MatrixType, MatrixRows, MatrixColumns> operator-(const MatrixType& scalar) const;

			/*
			 * @description: Operator that applies subtraction with the given 'other' matrix.
			 * @return: A copy of a Matrix<MatrixType, MatrixRows, MatrixColumns>.
			 */
			Matrix<MatrixType, MatrixRows, MatrixColumns> operator-(const Matrix<MatrixType, MatrixRows, MatrixColumns>& other) const;

			/*
			 * @description: Operator that applies multiplication with the given 'scalar' value to each element of this matrix.
			 * @return: A copy of a Matrix<MatrixType, MatrixRows, MatrixColumns>.
			 */
			Matrix<MatrixType, MatrixRows, MatrixColumns> operator*(const MatrixType& scalar) const;

			/*
			 * @description: Operator that applies matrix multiplication with the given 'other' matrix.
			 * @return: A copy of a Matrix<MatrixType, MatrixRows, MatrixResultColumns>.
			 */
			template <unsigned int MatrixResultColumns>
			Matrix<MatrixType, MatrixRows, MatrixResultColumns> operator*(const Matrix<MatrixType, MatrixColumns, MatrixResultColumns>& other) const;

			/*
			 * @description: Function to check if the 'MatrixRows' and 'MatrixColumns' are equals.
			 * @return: True if squared and false otherwise.
			 */
			bool isSquare() const;

			/*
			 * @description: Function to get the number of rows of matrix.
			 * @return: Value of 'MatrixRows'.
			 */
			unsigned int getRows() const;

			/*
			 * @description: Function to get the number of columns of matrix.
			 * @return: Value of 'MatrixColumns'.
			 */
			unsigned int getColumns() const;

			/*
			 * @description: Function to get the transpose matrix.
			 * @return: A copy of transpose matrix.
			 */
			Matrix<MatrixType, MatrixRows, MatrixColumns> getTranspose() const;

		public:
			/*
			 * @description: Function to get the identity matrix.
			 * @return: A copy of identity matrix.
			 * @note: This matrix must be squared.
			 */
			static Matrix<MatrixType, MatrixRows, MatrixColumns> Identity();
	};
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::Matrix(bool zeroed) :
	StaticArray<MatrixType>(MatrixRows * MatrixColumns){
	if(zeroed == true){
		this->fill(0);
	}
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::Matrix(const std::initializer_list<MatrixType>& list) :
	StaticArray<MatrixType>(MatrixRows * MatrixColumns){
	if(this->size == list.size()){
		unsigned int i = 0;
		for(const MatrixType& item : list){
			this->data[i++] = item;
		}
	}else{
		this->fill(0);
	}
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::Matrix(const std::initializer_list<std::initializer_list<MatrixType>>& list) :
	StaticArray<MatrixType>(MatrixRows * MatrixColumns){
	bool validFormat = true;
	if(list.size() == MatrixRows){
		for(const auto& rowList : list){
			if(rowList.size() != MatrixColumns){
				validFormat = false;
				break;
			}
		}
	}else{
		validFormat = false;
	}

	if(validFormat == true){
		int col = 0;
		int row = 0;
		for(const auto& rowList : list){
			col = 0;
			for(const auto& item : rowList){
				this->data[row * MatrixColumns + col] = item;
				col++;
			}
			row++;
		}
	}else{
		this->fill(0);
	}
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::~Matrix(){

}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
MatrixType& EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::operator()(unsigned int row, unsigned int column){
	if(row >= MatrixRows || column >= MatrixColumns){
		throw OutOfBoundsException();
	}else{
		return this->data[row * MatrixColumns + column];
	}
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns> EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::operator+(const MatrixType& scalar) const{
	Matrix<MatrixType, MatrixRows, MatrixColumns> result(false);
	for(unsigned int i = 0; i < this->size; ++i){
		result.data[i] = this->data[i] + scalar;
	}
	return result;
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns> EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::operator+(const Matrix<MatrixType, MatrixRows, MatrixColumns>& other) const{
	Matrix<MatrixType, MatrixRows, MatrixColumns> result(false);
	for(unsigned int i = 0; i < this->size; ++i){
		result.data[i] = this->data[i] + other.data[i];
	}
	return result;
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns> EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::operator-(const MatrixType& scalar) const{
	Matrix<MatrixType, MatrixRows, MatrixColumns> result(false);
	for(unsigned int i = 0; i < this->size; ++i){
		result.data[i] = this->data[i] - scalar;
	}
	return result;
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns> EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::operator-(const Matrix<MatrixType, MatrixRows, MatrixColumns>& other) const{
	Matrix<MatrixType, MatrixRows, MatrixColumns> result(false);
	for(unsigned int i = 0; i < this->size; ++i){
		result.data[i] = this->data[i] - other.data[i];
	}
	return result;
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns> EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::operator*(const MatrixType& scalar) const{
	Matrix<MatrixType, MatrixRows, MatrixColumns> result(false);
	for(unsigned int i = 0; i < this->size; ++i){
		result.data[i] = this->data[i] * scalar;
	}
	return result;
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
template <unsigned int MatrixResultColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixResultColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::operator*(const Matrix<MatrixType, MatrixColumns, MatrixResultColumns>& other) const{
	Matrix<MatrixType, MatrixRows, MatrixResultColumns> result(false);
	for(unsigned int i = 0; i < MatrixRows; ++i){
		for(unsigned int j = 0; j < MatrixResultColumns; ++j){
			unsigned int dataIt = i * MatrixResultColumns + j;
			result.data[dataIt] = 0;
			for(unsigned int k = 0; k < MatrixColumns; ++k){
				result.data[dataIt] += this->data[i * MatrixColumns + k] * other.data[k * MatrixResultColumns + j];
			}
		}
	}
	return result;
}

template <class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
bool EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::isSquare() const{
	return (MatrixRows == MatrixColumns);
}

template <class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
unsigned int EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::getRows() const{
	return MatrixRows;
}

template <class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
unsigned int EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::getColumns() const{
	return MatrixColumns;
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns> EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::getTranspose() const{
	Matrix<MatrixType, MatrixColumns, MatrixRows> result(false);
	for(unsigned int i = 0; i < MatrixRows; ++i){
		for(unsigned int j = 0; j < MatrixColumns; ++j){
			result.data[j * MatrixRows + i] = this->data[i * MatrixColumns + j];
		}
	}
	return result;
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns> EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::Identity(){
	Matrix<MatrixType, MatrixRows, MatrixColumns> result(false);
	for(unsigned int row = 0; row < MatrixRows; ++row){
		for (unsigned int column = 0; column < MatrixColumns; ++column){
			if(row == column){
				result.data[row * MatrixColumns + column] = 1;
			}else{
				result.data[row * MatrixColumns + column] = 0;
			}
		}
	}
	return result;
}

#endif /* EMATRIX_HPP */
