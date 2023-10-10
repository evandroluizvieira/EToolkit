#ifndef ETRANSFORMATION_HPP
#define ETRANSFORMATION_HPP

#include <EMath>
#include <EMatrix>

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{

	/*
	 * @description: 3D transformation class used to get translation, scale and rotation 3D matrix.
	 * @note: Can't use objects, only functions.
	 */
	class Transformation{
		private:
			/*
			 * @description: Private default constructor that prevents object instantiation.
			 */
			Transformation();

		public:
			/*
			 * @description: Function to get the translate matrix in x, y and z axis with given 'x', 'y' and 'z' value.
			 * @return: A copy of translate matrix.
			 * @note: 'MatrixType' must be floating pointer.
			 */
			template<class MatrixType>
			static Matrix<MatrixType, 4, 4> translate(MatrixType x, MatrixType y, MatrixType z);

			/*
			 * @description: Function to get the translate matrix in x axis with given 'x' value.
			 * @return: A copy of translate matrix.
			 * @note: 'MatrixType' must be floating pointer.
			 */
			template<class MatrixType>
			static Matrix<MatrixType, 4, 4> translateX(MatrixType x);

			/*
			 * @description: Function to get the translate matrix in y axis with given 'y' value.
			 * @return: A copy of translate matrix.
			 * @note: 'MatrixType' must be floating pointer.
			 */
			template<class MatrixType>
			static Matrix<MatrixType, 4, 4> translateY(MatrixType y);

			/*
			 * @description: function to get the translate matrix in z axis with given 'z' value.
			 * @return: A copy of translate matrix.
			 * @note: 'MatrixType' must be floating pointer.
			 */
			template<class MatrixType>
			static Matrix<MatrixType, 4, 4> translateZ(MatrixType z);

			/*
			 * @description: function to get the scale matrix in x, y and z axis with given 'x', 'y' and 'z' value.
			 * @return: A copy of scale matrix.
			 * @note: 'MatrixType' must be floating pointer.
			 */
			template<class MatrixType>
			static Matrix<MatrixType, 4, 4> scale(MatrixType x, MatrixType y, MatrixType z);

			/*
			 * @description: Function to get the scale matrix in x axis with given 'x' value.
			 * @return: A copy of scale matrix.
			 * @note: 'MatrixType' must be floating pointer.
			 */
			template<class MatrixType>
			static Matrix<MatrixType, 4, 4> scaleX(MatrixType x);

			/*
			 * @description: Function to get the scale matrix in y axis with given 'y' value.
			 * @return: A copy of scale matrix.
			 * @note: 'MatrixType' must be floating pointer.
			 */
			template<class MatrixType>
			static Matrix<MatrixType, 4, 4> scaleY(MatrixType y);

			/*
			 * @description: Function to get the scale matrix in z axis with given 'z' value.
			 * @return: A copy of scale matrix.
			 * @note: 'MatrixType' must be floating pointer.
			 */
			template<class MatrixType>
			static Matrix<MatrixType, 4, 4> scaleZ(MatrixType z);

			/*
			 * @description: Function to get the rotate matrix on given 'angle' in degrees.
			 * @return: A copy of rotated matrix.
			 * @note: 'MatrixType' must be floating pointer.
			 */
			template<class MatrixType>
			static Matrix<MatrixType, 4, 4> rotate(MatrixType angle, MatrixType x, MatrixType y, MatrixType z);

			/*
			 * @description: Function to get the rotate matrix in x axis on given 'angle' in degrees.
			 * @return: A copy of rotated matrix.
			 * @note: 'MatrixType' must be floating pointer.
			 */
			template<class MatrixType>
			static Matrix<MatrixType, 4, 4> rotateX(MatrixType angle);

			/*
			 * @description: Function to get the rotate matrix in y axis on given 'angle' in degrees.
			 * @return: A copy of rotated matrix.
			 * @note: 'MatrixType' must be floating pointer.
			 */
			template<class MatrixType>
			static Matrix<MatrixType, 4, 4> rotateY(MatrixType angle);

			/*
			 * @description: Function to get the rotate matrix in z axis on given 'angle' in degrees.
			 * @return: A copy of rotated matrix.
			 * @note: 'MatrixType' must be floating pointer.
			 */
			template<class MatrixType>
			static Matrix<MatrixType, 4, 4> rotateZ(MatrixType angle);
	};
}

template<class MatrixType>
EToolkit::Matrix<MatrixType, 4, 4> EToolkit::Transformation::translate(MatrixType x, MatrixType y, MatrixType z){
	Matrix<MatrixType, 4, 4> result;
	result(0, 0) = 1;
	result(1, 1) = 1;
	result(2, 2) = 1;
	result(3, 3) = 1;
	result(0, 3) = x;
	result(1, 3) = y;
	result(2, 3) = z;
	return result;
}

template<class MatrixType>
EToolkit::Matrix<MatrixType, 4, 4> EToolkit::Transformation::translateX(MatrixType x){
	return translate(x, 0, 0);
}

template<class MatrixType>
EToolkit::Matrix<MatrixType, 4, 4> EToolkit::Transformation::translateY(MatrixType y){
	return translate(0, y, 0);
}

template<class MatrixType>
EToolkit::Matrix<MatrixType, 4, 4> EToolkit::Transformation::translateZ(MatrixType z){
	return translate(0, 0, z);
}

template<class MatrixType>
EToolkit::Matrix<MatrixType, 4, 4> EToolkit::Transformation::scale(MatrixType x, MatrixType y, MatrixType z){
	Matrix<MatrixType, 4, 4> result;
	result(0, 0) = x;
	result(1, 1) = y;
	result(2, 2) = z;
	result(3, 3) = 1;
	return result;
}

template<class MatrixType>
EToolkit::Matrix<MatrixType, 4, 4> EToolkit::Transformation::scaleX(MatrixType x){
	return scale(x, 1, 1);
}

template<class MatrixType>
EToolkit::Matrix<MatrixType, 4, 4> EToolkit::Transformation::scaleY(MatrixType y){
	return scale(1, y, 1);
}

template<class MatrixType>
EToolkit::Matrix<MatrixType, 4, 4> EToolkit::Transformation::scaleZ(MatrixType z){
	return scale(1, 1, z);
}

template<class MatrixType>
EToolkit::Matrix<MatrixType, 4, 4> EToolkit::Transformation::rotate(MatrixType angle, MatrixType x, MatrixType y, MatrixType z){
	MatrixType sine = Math::sine(angle);
	MatrixType cosine = Math::cosine(angle);
	MatrixType xSine = x * sine;
	MatrixType ySine = y * sine;
	MatrixType zSine = z * sine;
	MatrixType unitMinusCosine = 1 - cosine;
	MatrixType xxUnitMinusCosine = x * x * unitMinusCosine;
	MatrixType xyUnitMinusCosine = x * y * unitMinusCosine;
	MatrixType xzUnitMinusCosine = x * z * unitMinusCosine;
	MatrixType yyUnitMinusCosine = y * y * unitMinusCosine;
	MatrixType yzUnitMinusCosine = y * z * unitMinusCosine;
	MatrixType zzUnitMinusCosine = z * z * unitMinusCosine;
	Matrix<MatrixType, 4, 4> result;
	result(0, 0) = xxUnitMinusCosine + cosine;
	result(0, 1) = xyUnitMinusCosine - zSine;
	result(0, 2) = xzUnitMinusCosine + ySine;
	result(1, 0) = xyUnitMinusCosine + zSine;
	result(1, 1) = yyUnitMinusCosine + cosine;
	result(1, 2) = yzUnitMinusCosine - xSine;
	result(2, 0) = xzUnitMinusCosine - ySine;
	result(2, 1) = yzUnitMinusCosine + xSine;
	result(2, 2) = zzUnitMinusCosine + cosine;
	result(3, 3) = 1;
	return result;
}

template<class MatrixType>
EToolkit::Matrix<MatrixType, 4, 4> EToolkit::Transformation::rotateX(MatrixType angle){
	MatrixType sine = Math::sine(angle);
	MatrixType cosine = Math::cosine(angle);
	Matrix<MatrixType, 4, 4> result;
	result(0, 0) = 1;
	result(1, 1) = cosine;
	result(1, 2) = -sine;
	result(2, 1) = sine;
	result(2, 2) = cosine;
	result(3, 3) = 1;
	return result;
}

template<class MatrixType>
EToolkit::Matrix<MatrixType, 4, 4> EToolkit::Transformation::rotateY(MatrixType angle){
	MatrixType sine = Math::sine(angle);
	MatrixType cosine = Math::cosine(angle);
	Matrix<MatrixType, 4, 4> result;
	result(0, 0) = cosine;
	result(0, 2) = sine;
	result(1, 1) = 1;
	result(2, 0) = -sine;
	result(2, 2) = cosine;
	result(3, 3) = 1;
	return result;
}

template<class MatrixType>
EToolkit::Matrix<MatrixType, 4, 4> EToolkit::Transformation::rotateZ(MatrixType angle){
	MatrixType sine = Math::sine(angle);
	MatrixType cosine = Math::cosine(angle);
	Matrix<MatrixType, 4, 4> result;
	result(0, 0) = cosine;
	result(0, 1) = -sine;
	result(1, 0) = sine;
	result(1, 1) = cosine;
	result(2, 2) = 1;
	result(3, 3) = 1;
	return result;
}

#endif /* ETRANSFORMATION_HPP */
