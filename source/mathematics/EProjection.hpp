#ifndef EPROJECTION_HPP
#define EPROJECTION_HPP

#include <EMatrix>

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{

	/*
	 * @description: 3D projection class used to get 3D view matrix.
	 * @note: Can't use objects, only functions.
	 */
	class Projection{
		private:
			/*
			 * @description: Private default constructor that prevents object instantiation.
			 */
			Projection();

		public:
			/*
			 * @description: Function to get a perspective matrix, 'left' and 'right' are used to vertical clipping planes, 'bottom' and 'top' are used to horizontal clipping planes and 'near' and 'far' are used to depth clipping planes.
			 * @return: A copy of perspective matrix.
			 * @note: 'MatrixType' must be floating pointer.
			 */
			template<class MatrixType>
			static Matrix<MatrixType, 4, 4> perspectiveFrustrum(MatrixType left, MatrixType right, MatrixType bottom, MatrixType top, MatrixType near, MatrixType far);

			/*
			 * @description: Function to get a orthographic matrix, 'left' and 'right' are used to vertical clipping planes, 'bottom' and 'top' are used to horizontal clipping planes and 'near' and 'far' are used to depth clipping planes.
			 * @return: A copy of perspective matrix.
			 * @note: 'MatrixType' must be floating pointer.
			 */
			template<class MatrixType>
			static Matrix<MatrixType, 4, 4> orthographicFrustrum(MatrixType left, MatrixType right, MatrixType bottom, MatrixType top, MatrixType near, MatrixType far);

	};
}

template<class MatrixType>
EToolkit::Matrix<MatrixType, 4, 4> EToolkit::Projection::perspectiveFrustrum(MatrixType left, MatrixType right, MatrixType bottom, MatrixType top, MatrixType near, MatrixType far){
	Matrix<MatrixType, 4, 4> result;
	result(0, 0) = (2 * near) / (right - left);
	result(0, 2) = (right + left) / (right - left);
	result(1, 1) = (2 * near) / (top - bottom);
	result(1, 2) = (top + bottom) / (top - bottom);
	result(2, 2) = -(far + near) / (far - near);
	result(2, 3) = (-2 * far * near) / (far - near);
	result(3, 2) = -1;
	return result;
}

template<class MatrixType>
EToolkit::Matrix<MatrixType, 4, 4> EToolkit::Projection::orthographicFrustrum(MatrixType left, MatrixType right, MatrixType bottom, MatrixType top, MatrixType near, MatrixType far){
	Matrix<MatrixType, 4, 4> result;
	result(0, 0) = 2 / (right - left);
	result(0, 3) = -((right + left) / (right - left));
	result(1, 1) = 2 / (top - bottom);
	result(1, 3) = -((top + bottom) / (top - bottom));
	result(2, 2) = -2 / (far - near);
	result(2, 3) = -((far + near) / (far - near));
	result(3, 3) = 1;
	return result;
}

#endif /* EPROJECTION_HPP */
