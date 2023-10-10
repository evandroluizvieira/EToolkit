#ifndef EVECTOR_HPP
#define EVECTOR_HPP

#include <EContainer>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Spatial dimension generic base class.
	 * @note: 'VectorType' must be numeric and 'VectorLength' must be greater than 0.
	 */
	template<class VectorType, unsigned int VectorLength>
	class Vector : public StaticArray<VectorType>{
		public:
			/*
			 * @description: Default constructor, if 'zeroed' is true initializes everything with cleared data.
			 * @return: None.
			 */
			Vector(bool zeroed = true);

			/*
			 * @description: Default destructor.
			 * @return: None.
			 */
			virtual ~Vector();

			/*
			 * @description: Operator that returns a vector with all elements multiplied by -1.
			 * @return: Negative copy of this vector.
			 */
			Vector<VectorType, VectorLength> operator-() const;

			/*
			 * @description: Operator that returns a vector with all elements summed by the 'scalar' value.
			 * @return: Summed copy of this vector.
			 */
			Vector<VectorType, VectorLength> operator+(const VectorType& scalar) const;

			/*
			 * @description: Operator that returns a vector with each element summed by the respective element of the given 'other' vector.
			 * @return: Summed copy of this vector by the 'other' vector.
			 */
			Vector<VectorType, VectorLength> operator+(const Vector<VectorType, VectorLength>& other) const;

			/*
			 * @description: Operator that returns itself with all elements summed by the 'scalar' value.
			 * @return: Summed elements with reference of this vector.
			 */
			Vector<VectorType, VectorLength>& operator+=(const VectorType& scalar);

			/*
			 * @description: Operator that returns itself with each element summed by the respective element of the given 'other' vector.
			 * @return: Summed elements with reference of this vector.
			 */
			Vector<VectorType, VectorLength>& operator+=(const Vector<VectorType, VectorLength>& other);

			/*
			 * @description: Operator that returns a vector with all elements subtracted by the 'scalar' value.
			 * @return: Subtracted copy of this vector.
			 */
			Vector<VectorType, VectorLength> operator-(const VectorType& scalar) const;

			/*
			 * @description: Operator that returns a vector with each element subtracted by the respective element of the given 'other' vector.
			 * @return: Subtracted copy of this vector by the 'other' vector.
			 */
			Vector<VectorType, VectorLength> operator-(const Vector<VectorType, VectorLength>& other) const;

			/*
			 * @description: Operator that returns itself with all elements subtracted by the 'scalar' value.
			 * @return: Subtracted elements with reference of this vector.
			 */
			Vector<VectorType, VectorLength>& operator-=(const VectorType& scalar);

			/*
			 * @description: Operator that returns itself with each element subtracted by the respective element of the given 'other' vector.
			 * @return: Subtracted elements with reference of this vector.
			 */
			Vector<VectorType, VectorLength>& operator-=(const Vector<VectorType, VectorLength>& other);

			/*
			 * @description: Operator that returns a vector with all elements multiplied by the 'scalar' value.
			 * @return: Multiplied copy of this vector.
			 */
			Vector<VectorType, VectorLength> operator*(const VectorType& scalar) const;

			/*
			 * @description: Operator that returns a vector with each element multiplied by the respective element of the given 'other' vector.
			 * @return: Multiplied copy of this vector by the 'other' vector.
			 */
			Vector<VectorType, VectorLength> operator*(const Vector<VectorType, VectorLength>& other) const;

			/*
			 * @description: Operator that returns itself with all elements multiplied by the 'scalar' value.
			 * @return: Multiplied elements with reference of this vector.
			 */
			Vector<VectorType, VectorLength>& operator*=(const VectorType& scalar);

			/*
			 * @description: Operator that returns itself with each element multiplied by the respective element of the given 'other' vector.
			 * @return: Multiplied elements with reference of this vector.
			 */
			Vector<VectorType, VectorLength>& operator*=(const Vector<VectorType, VectorLength>& other);

			/*
			 * @description: Operator that returns a vector with all elements divided by the 'scalar' value.
			 * @return: Divided copy of this vector.
			 */
			Vector<VectorType, VectorLength> operator/(const VectorType& scalar) const;

			/*
			 * @description: Operator that returns a vector with each element divided by the respective element of the given 'other' vector.
			 * @return: Divided copy of this vector by the 'other' vector.
			 */
			Vector<VectorType, VectorLength> operator/(const Vector<VectorType, VectorLength>& other) const;

			/*
			 * @description: Operator that returns itself with all elements divided by the 'scalar' value.
			 * @return: Divided elements with reference of this vector.
			 */
			Vector<VectorType, VectorLength>& operator/=(const VectorType& scalar);

			/*
			 * @description: Operator that returns itself with each element divided by the respective element of the given 'other' vector.
			 * @return: Divided elements with reference of this vector.
			 */
			Vector<VectorType, VectorLength>& operator/=(const Vector<VectorType, VectorLength>& other);
	};
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength>::Vector(bool zeroed) :
	StaticArray<VectorType>(VectorLength){
	if(zeroed == true){
		fill(0);
	}
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength>::~Vector(){

}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength> EToolkit::Vector<VectorType, VectorLength>::operator-() const{
	Vector<VectorType, VectorLength> result;
	for(unsigned int i = 0; i < VectorLength; i++){
		result.data[i] = -data[i];
	}
	return result;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength> EToolkit::Vector<VectorType, VectorLength>::operator+(const VectorType& scalar) const{
	Vector<VectorType, VectorLength> result;
	for(unsigned int i = 0; i < VectorLength; i++){
		result.data[i] = data[i] + scalar;
	}
	return result;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength> EToolkit::Vector<VectorType, VectorLength>::operator+(const Vector<VectorType, VectorLength>& other) const{
	Vector<VectorType, VectorLength> result;
	for(unsigned int i = 0; i < VectorLength; i++){
		result.data[i] = data[i] + other.data[i];
	}
	return result;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength>& EToolkit::Vector<VectorType, VectorLength>::operator+=(const VectorType& scalar){
	for(unsigned int i = 0; i < VectorLength; i++){
		data[i] = data[i] + scalar;
	}
	return *this;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength>& EToolkit::Vector<VectorType, VectorLength>::operator+=(const Vector<VectorType, VectorLength>& other){
	for(unsigned int i = 0; i < VectorLength; i++){
		data[i] = data[i] + other.data[i];
	}
	return *this;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength> EToolkit::Vector<VectorType, VectorLength>::operator-(const VectorType& scalar) const{
	Vector<VectorType, VectorLength> result;
	for(unsigned int i = 0; i < VectorLength; i++){
		result.data[i] = data[i] - scalar;
	}
	return result;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength> EToolkit::Vector<VectorType, VectorLength>::operator-(const Vector<VectorType, VectorLength>& other) const{
	Vector<VectorType, VectorLength> result;
	for(unsigned int i = 0; i < VectorLength; i++){
		result.data[i] = data[i] - other.data[i];
	}
	return result;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength>& EToolkit::Vector<VectorType, VectorLength>::operator-=(const VectorType& scalar){
	for(unsigned int i = 0; i < VectorLength; i++){
		data[i] = data[i] - scalar;
	}
	return *this;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength>& EToolkit::Vector<VectorType, VectorLength>::operator-=(const Vector<VectorType, VectorLength>& other){
	for(unsigned int i = 0; i < VectorLength; i++){
		data[i] = data[i] - other.data[i];
	}
	return *this;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength> EToolkit::Vector<VectorType, VectorLength>::operator*(const VectorType& scalar) const{
	Vector<VectorType, VectorLength> result;
	for(unsigned int i = 0; i < VectorLength; i++){
		result.data[i] = data[i] * scalar;
	}
	return result;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength> EToolkit::Vector<VectorType, VectorLength>::operator*(const Vector<VectorType, VectorLength>& other) const{
	Vector<VectorType, VectorLength> result;
	for(unsigned int i = 0; i < VectorLength; i++){
		result.data[i] = data[i] * other.data[i];
	}
	return result;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength>& EToolkit::Vector<VectorType, VectorLength>::operator*=(const VectorType& scalar){
	for(unsigned int i = 0; i < VectorLength; i++){
		data[i] = data[i] * scalar;
	}
	return *this;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength>& EToolkit::Vector<VectorType, VectorLength>::operator*=(const Vector<VectorType, VectorLength>& other){
	for(unsigned int i = 0; i < VectorLength; i++){
		data[i] = data[i] * other.data[i];
	}
	return *this;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength> EToolkit::Vector<VectorType, VectorLength>::operator/(const VectorType& scalar) const{
	Vector<VectorType, VectorLength> result;
	for(unsigned int i = 0; i < VectorLength; i++){
		result.data[i] = data[i] / scalar;
	}
	return result;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength> EToolkit::Vector<VectorType, VectorLength>::operator/(const Vector<VectorType, VectorLength>& other) const{
	Vector<VectorType, VectorLength> result;
	for(unsigned int i = 0; i < VectorLength; i++){
		result.data[i] = data[i] / other.data[i];
	}
	return result;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength>& EToolkit::Vector<VectorType, VectorLength>::operator/=(const VectorType& scalar){
	for(unsigned int i = 0; i < VectorLength; i++){
		data[i] = data[i] / scalar;
	}
	return *this;
}

template<class VectorType, unsigned int VectorLength>
EToolkit::Vector<VectorType, VectorLength>& EToolkit::Vector<VectorType, VectorLength>::operator/=(const Vector<VectorType, VectorLength>& other){
	for(unsigned int i = 0; i < VectorLength; i++){
		data[i] = data[i] / other.data[i];
	}
	return *this;
}

#endif /* EVECTOR_HPP */
