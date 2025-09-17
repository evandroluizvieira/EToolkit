/**
 * @file Size2.hpp
 * @brief Contains Size2 template class.
 */

#ifndef ESIZE2_HPP
#define ESIZE2_HPP

#include "ESize1.hpp"

/*
 * @namespace EToolkit
 * @brief: Evandro's Toolkit.
 */
namespace EToolkit{

	/**
	 * @class Size2
	 * @brief Represents a 2-dimensional size (width, height).
	 * @tparam Size2Type Numeric type used for the dimensions.
	 *
	 * Inherits from Size1 (width) and extends it with 'height'.
	 */
	template<class Size2Type>
	class Size2 : virtual public Size1<Size2Type>{
		public:
			/**
			 * @brief Constructor that initializes the object with width and height.
			 * @param width Initial width (default = 0).
			 * @param height Initial height (default = 0).
			 */
			Size2(Size2Type width = 0, Size2Type height = 0);

			/**
			 * @brief Virtual destructor.
			 */
			virtual ~Size2() = default;

			/**
			 * @brief Get the height.
			 * @return Reference to the height value.
			 */
			inline Size2Type& getHeight();

		    /**
		     * @brief Get the height (read-only for const objects).
		     * @return Constant reference to height.
		     */
		    inline const Size2Type& getHeight() const;

			/**
			 * @brief Set the height.
			 * @param height The value to assign as height.
			 */
			inline void setHeight(const Size2Type& height);
	};

	typedef Size2<int> Size2i; ///< Typedef for integer 2D size.
}

template<class Size2Type>
EToolkit::Size2<Size2Type>::Size2(Size2Type width, Size2Type height) :
	StaticArray<Size2Type>(2), Size1<Size2Type>(width){
	(*this)[0] = width;
	(*this)[1] = height;
}

template<class Size2Type>
inline Size2Type& EToolkit::Size2<Size2Type>::getHeight(){
	return (*this)[1];
}

template<class Size2Type>
inline const Size2Type& EToolkit::Size2<Size2Type>::getHeight() const{
    return (*this)[1];
}

template<class Size2Type>
inline void EToolkit::Size2<Size2Type>::setHeight(const Size2Type& height){
	(*this)[1] = height;
}

#endif /* ESIZE2_HPP */
