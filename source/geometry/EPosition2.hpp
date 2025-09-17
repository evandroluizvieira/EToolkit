/**
 * @file Position2.hpp
 * @brief Contains Position2 template class.
 */

#ifndef EPOSITION2_HPP
#define EPOSITION2_HPP

#include "EPosition1.hpp"

/*
 * @namespace EToolkit
 * @brief: Evandro's Toolkit.
 */
namespace EToolkit{

	/**
	 * @class Position2
	 * @brief Represents a 2-dimensional position.
	 * @tparam Position2Type Numeric type used for the coordinates.
	 *
	 * Inherits from Position1 (x coordinate) and extends it with 'y'.
	 */
	template<class Position2Type>
	class Position2 : virtual public Position1<Position2Type>{
		public:
			/**
			 * @brief Constructor that initializes the object with the given `x` and `y` values.
			 * @param x The initial value for the x coordinate (default = 0).
			 * @param y The initial value for the y coordinate (default = 0).
			 */
			Position2(Position2Type x = 0, Position2Type y = 0);

			/**
			 * @brief Virtual destructor.
			 */
			virtual ~Position2() = default;

			/**
			 * @brief Get the y coordinate.
			 * @return Reference to the current value of y.
			 */
			inline Position2Type& getY();

			/**
			 * @brief Get the y coordinate (read-only for const objects).
			 * @return Constant reference to y.
			 */
			inline const Position2Type& getY() const;

			/**
			 * @brief Set the y coordinate.
			 * @param y The value to assign to y.
			 */
			inline void setY(const Position2Type& y);
	};

	typedef Position2<int> Position2i; ///< Typedef for integer 2D positions.
}

template<class Position2Type>
EToolkit::Position2<Position2Type>::Position2(Position2Type x, Position2Type y) :
	StaticArray<Position2Type>(2), Position1<Position2Type>(x){
	(*this)[0] = x;
	(*this)[1] = y;
}

template<class Position2Type>
inline Position2Type& EToolkit::Position2<Position2Type>::getY(){
	return (*this)[1];
}

template<class Position2Type>
inline const Position2Type& EToolkit::Position2<Position2Type>::getY() const{
    return (*this)[1];
}

template<class Position2Type>
inline void EToolkit::Position2<Position2Type>::setY(const Position2Type& y){
	(*this)[1] = y;
}

#endif /* EPOSITION2_HPP */
