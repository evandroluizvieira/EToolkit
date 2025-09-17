/**
 * @file Position3.hpp
 * @brief Contains Position3 template class.
 */

#ifndef EPOSITION3_HPP
#define EPOSITION3_HPP

#include "EPosition2.hpp"

/*
 * @namespace EToolkit
 * @brief: Evandro's Toolkit.
 */
namespace EToolkit{

	/**
	 * @class Position3
	 * @brief Represents a 3-dimensional position.
	 * @tparam Position3Type Numeric type used for the coordinates.
	 *
	 * Inherits from Position2 (x, y coordinates) and extends it with 'z'.
	 */
	template<class Position3Type>
	class Position3 : virtual public Position2<Position3Type>{
		public:
			/**
			 * @brief Constructor that initializes the object with the given `x`, `y`, and `z` values.
			 * @param x The initial value for the x coordinate (default = 0).
			 * @param y The initial value for the y coordinate (default = 0).
			 * @param z The initial value for the z coordinate (default = 0).
			 */
			Position3(Position3Type x = 0, Position3Type y = 0, Position3Type z = 0);

			/**
			 * @brief Virtual destructor.
			 */
			virtual ~Position3() = default;

			/**
			 * @brief Get the z coordinate.
			 * @return Reference to the current value of z.
			 */
			inline Position3Type& getZ();

			/**
			 * @brief Get the z coordinate (read-only for const objects).
			 * @return Constant reference to z.
			 */
			inline const Position3Type& getZ() const;

			/**
			 * @brief Set the z coordinate.
			 * @param z The value to assign to z.
			 */
			inline void setZ(const Position3Type& z);
	};

	typedef Position3<int> Position3i; ///< Typedef for integer 3D positions.
}

template<class Position3Type>
EToolkit::Position3<Position3Type>::Position3(Position3Type x, Position3Type y, Position3Type z) :
	StaticArray<Position3Type>(3), Position2<Position3Type>(x, y){
	(*this)[0] = x;
	(*this)[1] = y;
	(*this)[2] = z;
}

template<class Position3Type>
inline Position3Type& EToolkit::Position3<Position3Type>::getZ(){
	return (*this)[2];
}

template<class Position3Type>
inline const Position3Type& EToolkit::Position3<Position3Type>::getZ() const{
    return (*this)[2];
}

template<class Position3Type>
inline void EToolkit::Position3<Position3Type>::setZ(const Position3Type& z){
	(*this)[2] = z;
}

#endif /* EPOSITION3_HPP */
