/**
 * @file Position1.hpp
 * @brief Contains Position1 template class.
 */

#ifndef EPOSITION1_HPP
#define EPOSITION1_HPP

#include <EContainer>

/*
 * @namespace EToolkit
 * @brief: Evandro's Toolkit.
 */
namespace EToolkit{

	/**
	 * @class Position1
	 * @brief Represents a 1-dimensional position.
	 * @tparam Position1Type Numeric type used to store the x coordinate.
	 * @tparam PositionSizeType Type used to index the StaticArray and represent its length.
	 * @tparam Length Number of elements in the shared StaticArray storage. The default value 1 is
	 *       the standalone storage size for a one-dimensional position. A larger value can be used
	 *       when Position1 is a virtual base of Position2 or Position3.
	 *
	 * Inherits from StaticArray with size 1. Provides access methods to the single coordinate 'x'.
	 * Virtually inherits from StaticArray so that derived multidimensional positions can share one
	 * contiguous array.
	 *
	 * @note The shared contiguous array maps [0] to x.
	 *
	 * Position1 has a separate PositionSizeType parameter because the type used to store a
	 * coordinate is not required to be the type used for array indices. Length is a non-type
	 * parameter so the array size is known at compile time.
	 */
	template<class Position1Type, class PositionSizeType, PositionSizeType Length = 1>
	class Position1 : virtual public StaticArray<Position1Type, PositionSizeType, Length>{
		public:
			/**
			 * @brief Constructs a position with the given x value.
			 * @param x The initial value for the x coordinate (default = 0).
			 */
			Position1(Position1Type x = 0);

			/**
			 * @brief Virtual destructor.
			 */
			virtual ~Position1() = default;

			/**
			 * @brief Get the x coordinate.
			 * @return The current value of x.
			 */
			inline Position1Type& getX();

		    /**
		     * @brief Get the x coordinate (read-only for const objects).
		     * @return Constant reference to x.
		     */
		    inline const Position1Type& getX() const;

			/**
			 * @brief Set the x coordinate.
			 * @param x The value to assign to x.
			 */
			inline void setX(const Position1Type& x);
	};

	typedef Position1<int, unsigned int> Position1i; ///< Typedef for integer 1D positions.
}

template<class Position1Type, class PositionSizeType, PositionSizeType Length>
EToolkit::Position1<Position1Type, PositionSizeType, Length>::Position1(Position1Type x) :
	StaticArray<Position1Type, PositionSizeType, Length>({x}){
	(*this)[0] = x;
}

template<class Position1Type, class PositionSizeType, PositionSizeType Length>
inline Position1Type& EToolkit::Position1<Position1Type, PositionSizeType, Length>::getX(){
	return (*this)[0];
}

template<class Position1Type, class PositionSizeType, PositionSizeType Length>
inline const Position1Type& EToolkit::Position1<Position1Type, PositionSizeType, Length>::getX() const{
	return (*this)[0];
}

template<class Position1Type, class PositionSizeType, PositionSizeType Length>
inline void EToolkit::Position1<Position1Type, PositionSizeType, Length>::setX(const Position1Type& x){
	(*this)[0] = x;
}

#endif /* EPOSITION1_HPP */
