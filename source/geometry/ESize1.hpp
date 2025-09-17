/**
 * @file Size1.hpp
 * @brief Contains Size1 template class.
 */

#ifndef ESIZE1_HPP
#define ESIZE1_HPP

#include <EContainer>

/*
 * @namespace EToolkit
 * @brief: Evandro's Toolkit.
 */
namespace EToolkit{

	/**
	 * @class Size1
	 * @brief Represents a 1-dimensional size (width).
	 * @tparam Size1Type Numeric type used for the dimension.
	 *
	 * Inherits from StaticArray with size 1. Provides access to the single dimension 'width'.
	 */
	template<class Size1Type>
	class Size1 : virtual public StaticArray<Size1Type>{
		public:
			/**
			 * @brief Constructor that initializes the object with the given width.
			 * @param width Initial width value (default = 0).
			 */
			Size1(Size1Type width = 0);

			/**
			 * @brief Virtual destructor.
			 */
			virtual ~Size1() = default;

			/**
			 * @brief Get the width.
			 * @return Reference to the width value.
			 */
			inline Size1Type& getWidth();

		    /**
		     * @brief Get the width (read-only for const objects).
		     * @return Constant reference to width.
		     */
		    inline const Size1Type& getWidth() const;

			/**
			 * @brief Set the width.
			 * @param width The value to assign as width.
			 */
			inline void setWidth(const Size1Type& width);
	};

	typedef Size1<int> Size1i; ///< Typedef for integer 1D size.
}

template<class Size1Type>
EToolkit::Size1<Size1Type>::Size1(Size1Type width) :
	StaticArray<Size1Type>(1){
	(*this)[0] = width;
}

template<class Size1Type>
inline Size1Type& EToolkit::Size1<Size1Type>::getWidth(){
	return (*this)[0];
}

template<class Size1Type>
inline const Size1Type& EToolkit::Size1<Size1Type>::getWidth() const{
    return (*this)[0];
}

template<class Size1Type>
inline void EToolkit::Size1<Size1Type>::setWidth(const Size1Type& width){
	(*this)[0] = width;
}

#endif /* ESIZE1_HPP */
