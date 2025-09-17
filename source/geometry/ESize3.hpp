/**
 * @file Size3.hpp
 * @brief Contains Size3 template class.
 */

#ifndef ESIZE3_HPP
#define ESIZE3_HPP

#include "ESize2.hpp"

/*
 * @namespace EToolkit
 * @brief: Evandro's Toolkit.
 */
namespace EToolkit{

	/**
	 * @class Size3
	 * @brief Represents a 3-dimensional size (width, height, depth).
	 * @tparam Size3Type Numeric type used for the dimensions.
	 *
	 * Inherits from Size2 (width, height) and extends it with 'depth'.
	 */
	template<class Size3Type>
	class Size3 : virtual public Size2<Size3Type>{
		public:
			/**
			 * @brief Constructor that initializes the object with width, height, and depth.
			 * @param width Initial width (default = 0).
			 * @param height Initial height (default = 0).
			 * @param depth Initial depth (default = 0).
			 */
			Size3(Size3Type width = 0, Size3Type height = 0, Size3Type depth = 0);

			/**
			 * @brief Virtual destructor.
			 */
			virtual ~Size3() = default;

			/**
			 * @brief Get the depth.
			 * @return Reference to the depth value.
			 */
			inline Size3Type& getDepth();

		    /**
		     * @brief Get the depth (read-only for const objects).
		     * @return Constant reference to depth.
		     */
		    inline const Size3Type& getDepth() const;

			/**
			 * @brief Set the depth.
			 * @param depth The value to assign as depth.
			 */
			inline void setDepth(const Size3Type& depth);
	};

	typedef Size3<int> Size3i; ///< Typedef for integer 3D size.
}

template<class Size3Type>
EToolkit::Size3<Size3Type>::Size3(Size3Type width, Size3Type height, Size3Type depth) :
	StaticArray<Size3Type>(3), Size2<Size3Type>(width, height){
	(*this)[0] = width;
	(*this)[1] = height;
	(*this)[2] = depth;
}

template<class Size3Type>
inline Size3Type& EToolkit::Size3<Size3Type>::getDepth(){
	return (*this)[2];
}

template<class Size3Type>
inline const Size3Type& EToolkit::Size3<Size3Type>::getDepth() const{
    return (*this)[2];
}

template<class Size3Type>
inline void EToolkit::Size3<Size3Type>::setDepth(const Size3Type& depth){
	(*this)[2] = depth;
}

#endif /* ESIZE3_HPP */
