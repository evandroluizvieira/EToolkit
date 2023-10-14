#ifndef EVECTOR4D_HPP
#define EVECTOR4D_HPP

#include "EVector3D.hpp"

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Four-dimensional generic class.
	 * @note: 'Vector4DType' must be numeric.
	 */
	template<class Vector4DType>
	class Vector4D : public Vector3D<Vector4DType, 4>{
		public:
			/*
			 * @description: Default constructor, if 'zeroed' is true initializes everything with cleared data.
			 * @return: None.
			 */
			Vector4D(bool zeroed = true);

			/*
			 * @description: Constructor that initializes the elements with the 'x', 'y', 'z' and 'w' values in sequence.
			 * @return: None.
			 */
			Vector4D(const Vector4DType& x, const Vector4DType& y, const Vector4DType& z, const Vector4DType& w);

			/*
			 * @description: Default destructor.
			 * @return: None.
			 */
			virtual ~Vector4D();

			/*
			 * @description: Function to get the 'Vector4DType' of the axis w.
			 * @return: Reference of the axis w data.
			 */
			inline Vector4DType& w();

			/*
			 * @description: Function that set the value of axis w with the given 'w' value.
			 * @return: None.
			 */
			inline void setW(const Vector4DType& w);

			/*
			 * @description: Function that returns the axis w value.
			 * @return: Copy of axis w value.
			 */
			inline Vector4DType getW() const;
	};
}

template<class Vector4DType>
EToolkit::Vector4D<Vector4DType>::Vector4D(bool zeroed) :
	Vector3D<Vector4DType, 4>(zeroed){

}

template<class Vector4DType>
EToolkit::Vector4D<Vector4DType>::Vector4D(const Vector4DType& x, const Vector4DType& y, const Vector4DType& z, const Vector4DType& w) :
	Vector3D<Vector4DType, 4>(){
	setX(x);
	setY(y);
	setZ(z);
	setW(w);
}


template<class Vector4DType>
EToolkit::Vector4D<Vector4DType>::~Vector4D(){

}

template<class Vector4DType>
Vector4DType& EToolkit::Vector4D<Vector4DType>::w(){
	return this->data[3];
}

template<class Vector4DType>
void EToolkit::Vector4D<Vector4DType>::setW(const Vector4DType& w){
	this->data[3] = w;
}

template<class Vector4DType>
Vector4DType EToolkit::Vector4D<Vector4DType>::getW() const{
	return this->data[3];
}

#endif /* EVECTOR4D_HPP */
