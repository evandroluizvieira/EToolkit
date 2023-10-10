#ifndef EVECTOR3D_HPP
#define EVECTOR3D_HPP

#include "EVector2D.hpp"

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Three-dimensional generic class.
	 * @note: 'Vector3DType' must be numeric and 'Vector3DLength' have to be 3.
	 */
	template<class Vector3DType, unsigned int Vector3DLength = 3>
	class Vector3D : public Vector2D<Vector3DType, Vector3DLength>{
		public:
			/*
			 * @description: Default constructor, if 'zeroed' is true initializes everything with cleared data.
			 * @return: None.
			 */
			Vector3D(bool zeroed = true);

			/*
			 * @description: Constructor that initializes the elements with the 'x', 'y' and 'z' values in sequence.
			 * @return: None.
			 */
			Vector3D(const Vector3DType& x, const Vector3DType& y, const Vector3DType& z);

			/*
			 * @description: Default destructor.
			 * @return: None.
			 */
			virtual ~Vector3D();

			/*
			 * @description: Procedure that set the value of axis z with the given 'z' value.
			 * @return: None.
			 */
			inline void setZ(const Vector3DType& z);

			/*
			 * @description: Function that returns the axis z value.
			 * @return: Copy of axis z value.
			 */
			inline Vector3DType getZ() const;
	};
}

template<class Vector3DType, unsigned int Vector3DLength>
EToolkit::Vector3D<Vector3DType, Vector3DLength>::Vector3D(bool zeroed) :
	Vector2D<Vector3DType, Vector3DLength>(zeroed){

}

template<class Vector3DType, unsigned int Vector3DLength>
EToolkit::Vector3D<Vector3DType, Vector3DLength>::Vector3D(const Vector3DType& x, const Vector3DType& y, const Vector3DType& z) :
	Vector2D<Vector3DType, Vector3DLength>(){
	setX(x);
	setY(y);
	setZ(z);
}


template<class Vector3DType, unsigned int Vector3DLength>
EToolkit::Vector3D<Vector3DType, Vector3DLength>::~Vector3D(){

}

template<class Vector3DType, unsigned int Vector3DLength>
void EToolkit::Vector3D<Vector3DType, Vector3DLength>::setZ(const Vector3DType& z){
	data[2] = z;
}

template<class Vector3DType, unsigned int Vector3DLength>
Vector3DType EToolkit::Vector3D<Vector3DType, Vector3DLength>::getZ() const{
	return data[2];
}

#endif /* EVECTOR3D_HPP */
