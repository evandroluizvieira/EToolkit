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
	 * @tparam Position1Type Numeric type used for the coordinate.
	 *
	 * Inherits from StaticArray with size 1. Provides access methods to the single coordinate 'x'.
	 */
	template<class Position1Type>
	class Position1 : virtual public StaticArray<Position1Type>{
		public:
			/**
			 * @brief Default constructor that initializes the object with the given `x` value.
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

	typedef Position1<int> Position1i; ///< Typedef for integer 1D positions.
}

template<class Position1Type>
EToolkit::Position1<Position1Type>::Position1(Position1Type x) :
	StaticArray<Position1Type>(1){
	(*this)[0] = x;
}

template<class Position1Type>
inline Position1Type& EToolkit::Position1<Position1Type>::getX(){
	return (*this)[0];
}

template<class Position1Type>
inline const Position1Type& EToolkit::Position1<Position1Type>::getX() const{
    return (*this)[0];
}

template<class Position1Type>
inline void EToolkit::Position1<Position1Type>::setX(const Position1Type& x){
	(*this)[0] = x;
}

#endif /* EPOSITION1_HPP */
