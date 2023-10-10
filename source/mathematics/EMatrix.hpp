#ifndef EMATRIX_HPP
#define EMATRIX_HPP

#include <EContainer>
#include <EException>

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
			 * @description: Operator that applies addition with the given 'other' matrix.
			 * @return: A copy of a Matrix<MatrixType, MatrixRows, MatrixColumns>.
			 */
			Matrix<MatrixType, MatrixRows, MatrixColumns> operator+(const Matrix<MatrixType, MatrixRows, MatrixColumns>& other) const;

			/*
			 * @description: Operator that applies subtraction with the given 'other' matrix.
			 * @return: A copy of a Matrix<MatrixType, MatrixRows, MatrixColumns>.
			 */
			Matrix<MatrixType, MatrixRows, MatrixColumns> operator-(const Matrix<MatrixType, MatrixRows, MatrixColumns>& other) const;

			/*
			 * @description: Operator that applies dot product with the given 'scalar' value.
			 * @return: A copy of a Matrix<MatrixType, MatrixRows, MatrixColumns>.
			 */
			Matrix<MatrixType, MatrixRows, MatrixColumns> operator*(const MatrixType& scalar) const;

			/*
			 * @description: Operator that applies dot product with the given 'other' matrix.
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
			 * @description: Function to get the determinant of the matrix.
			 * @return: Determinant value.
			 * @note: This matrix must be squared.
			 */
			MatrixType getDeterminant() const;

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
			static Matrix<MatrixType, MatrixRows, MatrixColumns> Identity() const;
	};
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::Matrix(bool zeroed) :
	StaticArray<MatrixType>(MatrixRows * MatrixColumns){
	if(zeroed == true){
		fill(0);
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
		return data[row * MatrixColumns + column];
	}
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns> EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::operator+(const Matrix<MatrixType, MatrixRows, MatrixColumns>& other) const{
	Matrix<MatrixType, MatrixRows, MatrixColumns> result(false);
	for(unsigned int i = 0; i < MatrixRows; ++i){
		for(unsigned int j = 0; j < MatrixColumns; ++j){
			result(i, j) = data[i * MatrixColumns + j] + other(i, j);
		}
	}
	return result;
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns> EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::operator-(const Matrix<MatrixType, MatrixRows, MatrixColumns>& other) const{
	Matrix<MatrixType, MatrixRows, MatrixColumns> result(false);
	for(unsigned int i = 0; i < MatrixRows; ++i){
		for(unsigned int j = 0; j < MatrixColumns; ++j){
			result(i, j) = data[i * MatrixColumns + j] - other(i, j);
		}
	}
	return result;
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns> EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::operator*(const MatrixType& scalar) const{
	Matrix<MatrixType, MatrixRows, MatrixColumns> result(false);
	for(unsigned int i = 0; i < size; i++){
		result.data[i] = data[i] * scalar;
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
            result(i, j) = 0;
            for(unsigned int k = 0; k < MatrixColumns; ++k){
                result(i, j) += data[i * MatrixColumns + k] * other(k, j);
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

template <class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
MatrixType EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::getDeterminant() const{
	if(MatrixRows == 1){
		return data[0];
	}

	MatrixType determinant = 0;

	// For larger matrices, calculate using cofactor expansion
	for(unsigned int col = 0; col < MatrixColumns; ++col){

		// Calculate the cofactor
		Matrix<MatrixType, MatrixRows - 1, MatrixColumns - 1> subMatrix(false);
		for(unsigned int i = 1; i < MatrixRows; ++i){
			for(unsigned int j = 0, k = 0; j < MatrixColumns; ++j){
				if(j != col){
					subMatrix(i - 1, k++) = data[i * MatrixColumns + j];
				}
			}
		}

		// Add the contribution of this column to the determinant
		if(col % 2 == 0){
			determinant += data[col] * subMatrix.determinant();
		}else{
			determinant -= data[col] * subMatrix.determinant();
		}
	}

	return determinant;
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns> EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::getTranspose() const{
	Matrix<MatrixType, MatrixColumns, MatrixRows> result(false);
	for(unsigned int i = 0; i < MatrixRows; ++i){
		for(unsigned int j = 0; j < MatrixColumns; ++j){
			result(j, i) = data[i * MatrixColumns + j];
		}
	}
	return result;
}

template<class MatrixType, unsigned int MatrixRows, unsigned int MatrixColumns>
EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns> EToolkit::Matrix<MatrixType, MatrixRows, MatrixColumns>::Identity() const{
	Matrix<MatrixType, MatrixRows, MatrixColumns> result;
	for(unsigned int row = 0; row < MatrixRows; row++){
		for(unsigned int column = 0; column < MatrixColumns; column++){
			if(row == column){
				result.data[row][column] = 1;
			}
		}
	}
	return result;
}

#endif /* EMATRIX_HPP */
