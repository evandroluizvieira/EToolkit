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
	 * @tparam Position3Type Numeric type used to store the x, y, and z coordinates.
	 * @tparam PositionSizeType Type used to index the StaticArray and represent its length.
	 * @tparam Length Number of elements in the shared StaticArray storage. The default value 3 is
	 *       the standalone storage size for x, y, and z. A larger value can be propagated through
	 *       Position2 and Position1 when Position3 uses a larger shared position array.
	 *
	 * Inherits from Position2 with size 2 and extends it with the z coordinate.
	 * Virtually inherits from Position2 and preserves one StaticArray when this type participates
	 * in the multidimensional Position hierarchy.
	 *
	 * @note The shared contiguous array maps [0] to x, [1] to y, and [2] to z.
	 *
	 * Position3 repeats the type and Length parameters so its Position2 and Position1 bases use
	 * the same StaticArray specialization. This is required to preserve one shared virtual array
	 * throughout the Position hierarchy.
	 */
	template<class Position3Type, class PositionSizeType, PositionSizeType Length = 3>
	class Position3 : virtual public Position2<Position3Type, PositionSizeType, Length>{
		public:
			using Position2<Position3Type, PositionSizeType, Length>::getX; ///< Exposes the inherited x-coordinate accessor from Position2.
			using Position2<Position3Type, PositionSizeType, Length>::setX; ///< Exposes the inherited x-coordinate mutator from Position2.
			using Position2<Position3Type, PositionSizeType, Length>::getY; ///< Exposes the inherited y-coordinate accessor from Position2.
			using Position2<Position3Type, PositionSizeType, Length>::setY; ///< Exposes the inherited y-coordinate mutator from Position2.

			/**
			 * @brief Constructs a position with the given x, y, and z values.
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

	typedef Position3<int, unsigned int> Position3i; ///< Typedef for integer 3D positions.
}

template<class Position3Type, class PositionSizeType, PositionSizeType Length>
EToolkit::Position3<Position3Type, PositionSizeType, Length>::Position3(Position3Type x, Position3Type y, Position3Type z) :
	StaticArray<Position3Type, PositionSizeType, Length>({x, y, z}), Position2<Position3Type, PositionSizeType, Length>(x, y){
	(*this)[0] = x;
	(*this)[1] = y;
	(*this)[2] = z;
}

template<class Position3Type, class PositionSizeType, PositionSizeType Length>
inline Position3Type& EToolkit::Position3<Position3Type, PositionSizeType, Length>::getZ(){
	return (*this)[2];
}

template<class Position3Type, class PositionSizeType, PositionSizeType Length>
inline const Position3Type& EToolkit::Position3<Position3Type, PositionSizeType, Length>::getZ() const{
    return (*this)[2];
}

template<class Position3Type, class PositionSizeType, PositionSizeType Length>
inline void EToolkit::Position3<Position3Type, PositionSizeType, Length>::setZ(const Position3Type& z){
	(*this)[2] = z;
}

#endif /* EPOSITION3_HPP */
