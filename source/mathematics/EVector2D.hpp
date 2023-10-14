#ifndef EVECTOR2D_HPP
#define EVECTOR2D_HPP

#include "EVector.hpp"

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Two-dimensional generic class.
	 * @note: 'Vector2DType' must be numeric and 'Vector2DLength' have to be 2.
	 */
	template<class Vector2DType, unsigned int Vector2DLength = 2>
	class Vector2D : public Vector<Vector2DType, Vector2DLength>{
		public:
			/*
			 * @description: Default constructor, if 'zeroed' is true initializes everything with cleared data.
			 * @return: None.
			 */
			Vector2D(bool zeroed = true);

			/*
			 * @description: Constructor that initializes the elements with the 'x' and 'y' values in sequence.
			 * @return: None.
			 */
			Vector2D(const Vector2DType& x, const Vector2DType& y);

			/*
			 * @description: Default destructor.
			 * @return: None.
			 */
			virtual ~Vector2D();

			/*
			 * @description: Function to get the 'Vector2DType' of the axis x.
			 * @return: Reference of the axis x data.
			 */
			inline Vector2DType& x();

			/*
			 * @description: Function that set the value of axis x with the given 'x' value.
			 * @return: None.
			 */
			inline void setX(const Vector2DType& x);

			/*
			 * @description: Function that returns the axis x value.
			 * @return: Copy of axis x value.
			 */
			inline Vector2DType getX() const;

			/*
			 * @description: Function to get the 'Vector2DType' of the axis y.
			 * @return: Reference of the axis y data.
			 */
			inline Vector2DType& y();

			/*
			 * @description: Function that set the value of axis y with the given 'y' value.
			 * @return: None.
			 */
			inline void setY(const Vector2DType& y);

			/*
			 * @description: Function that returns the axis y value.
			 * @return: Copy of axis y value.
			 */
			inline Vector2DType getY() const;
	};
}

template<class Vector2DType, unsigned int Vector2DLength>
EToolkit::Vector2D<Vector2DType, Vector2DLength>::Vector2D(bool zeroed) :
	Vector<Vector2DType, Vector2DLength>(zeroed){

}

template<class Vector2DType, unsigned int Vector2DLength>
EToolkit::Vector2D<Vector2DType, Vector2DLength>::Vector2D(const Vector2DType& x, const Vector2DType& y) :
	Vector<Vector2DType, Vector2DLength>(){
	setX(x);
	setY(y);
}


template<class Vector2DType, unsigned int Vector2DLength>
EToolkit::Vector2D<Vector2DType, Vector2DLength>::~Vector2D(){

}

template<class Vector2DType, unsigned int Vector2DLength>
Vector2DType& EToolkit::Vector2D<Vector2DType, Vector2DLength>::x(){
	return this->data[0];
}

template<class Vector2DType, unsigned int Vector2DLength>
void EToolkit::Vector2D<Vector2DType, Vector2DLength>::setX(const Vector2DType& x){
	this->data[0] = x;
}

template<class Vector2DType, unsigned int Vector2DLength>
Vector2DType EToolkit::Vector2D<Vector2DType, Vector2DLength>::getX() const{
	return this->data[0];
}

template<class Vector2DType, unsigned int Vector2DLength>
Vector2DType& EToolkit::Vector2D<Vector2DType, Vector2DLength>::y(){
	return this->data[1];
}

template<class Vector2DType, unsigned int Vector2DLength>
void EToolkit::Vector2D<Vector2DType, Vector2DLength>::setY(const Vector2DType& y){
	this->data[1] = y;
}

template<class Vector2DType, unsigned int Vector2DLength>
Vector2DType EToolkit::Vector2D<Vector2DType, Vector2DLength>::getY() const{
	return this->data[1];
}

#endif /* EVECTOR2D_HPP */
