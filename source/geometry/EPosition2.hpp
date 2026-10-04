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
	 * @tparam Position2Type Numeric type used to store the x and y coordinates.
	 * @tparam PositionSizeType Type used to index the StaticArray and represent its length.
	 * @tparam Length Number of elements in the shared StaticArray storage. The default value 2 is
	 *       the standalone storage size for x and y. A larger value can be used when Position2 is a
	 *       virtual base of Position3.
	 *
	 * Inherits from Position1 with size 1 and extends it with the y coordinate.
	 * Virtually inherits from Position1 and preserves one StaticArray in the multidimensional
	 * Position hierarchy.
	 *
	 * @note The shared contiguous array maps [0] to x and [1] to y.
	 *
	 * Position2 repeats the type and Length parameters so its Position1 base is instantiated with
	 * exactly the same array type. This preserves one virtual StaticArray in the Position hierarchy
	 * instead of creating incompatible or duplicated storage.
	 */
	template<class Position2Type, class PositionSizeType, PositionSizeType Length = 2>
	class Position2 : virtual public Position1<Position2Type, PositionSizeType, Length>{
		public:
			using Position1<Position2Type, PositionSizeType, Length>::getX; ///< Exposes the inherited x-coordinate accessor from Position1.
			using Position1<Position2Type, PositionSizeType, Length>::setX; ///< Exposes the inherited x-coordinate mutator from Position1.

			/**
			 * @brief Constructs a position with the given x and y values.
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

	typedef Position2<int, unsigned int> Position2i; ///< Typedef for integer 2D positions.
}

template<class Position2Type, class PositionSizeType, PositionSizeType Length>
EToolkit::Position2<Position2Type, PositionSizeType, Length>::Position2(Position2Type x, Position2Type y) :
	StaticArray<Position2Type, PositionSizeType, Length>({x, y}), Position1<Position2Type, PositionSizeType, Length>(x){
	(*this)[0] = x;
	(*this)[1] = y;
}

template<class Position2Type, class PositionSizeType, PositionSizeType Length>
inline Position2Type& EToolkit::Position2<Position2Type, PositionSizeType, Length>::getY(){
	return (*this)[1];
}

template<class Position2Type, class PositionSizeType, PositionSizeType Length>
inline const Position2Type& EToolkit::Position2<Position2Type, PositionSizeType, Length>::getY() const{
	return (*this)[1];
}

template<class Position2Type, class PositionSizeType, PositionSizeType Length>
inline void EToolkit::Position2<Position2Type, PositionSizeType, Length>::setY(const Position2Type& y){
	(*this)[1] = y;
}

#endif /* EPOSITION2_HPP */
