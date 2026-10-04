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
	 * @tparam Size2Type Numeric type used to store the width and height dimensions.
	 * @tparam SizeType Type used to index the StaticArray and represent its length.
	 * @tparam Length Number of elements in the shared StaticArray storage. The default value 2 is
	 *       the standalone storage size for width and height. A larger value can be used when Size2
	 *       is a virtual base of Size3.
	 *
	 * Inherits from Size1 with size 1 and extends it with the height dimension.
	 * Virtually inherits from Size1 and preserves one StaticArray when this type participates in
	 * the multidimensional Size hierarchy.
	 *
	 * @note The shared contiguous array maps [0] to width and [1] to height.
	 *
	 * Size2 repeats SizeType and Length so its Size1 base refers to the same StaticArray
	 * specialization. This keeps the inherited width view compatible with the height view and
	 * avoids a second array in the Size hierarchy.
	 */
	template<class Size2Type, class SizeType, SizeType Length = 2>
	class Size2 : virtual public Size1<Size2Type, SizeType, Length>{
		public:
			using Size1<Size2Type, SizeType, Length>::getWidth; ///< Exposes the inherited width accessor from Size1.
			using Size1<Size2Type, SizeType, Length>::setWidth; ///< Exposes the inherited width mutator from Size1.

			/**
			 * @brief Constructs a size with the given width and height.
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

	typedef Size2<int, unsigned int> Size2i; ///< Typedef for integer 2D size.
}

template<class Size2Type, class SizeType, SizeType Length>
EToolkit::Size2<Size2Type, SizeType, Length>::Size2(Size2Type width, Size2Type height) :
	StaticArray<Size2Type, SizeType, Length>({width, height}), Size1<Size2Type, SizeType, Length>(width){
	(*this)[0] = width;
	(*this)[1] = height;
}

template<class Size2Type, class SizeType, SizeType Length>
inline Size2Type& EToolkit::Size2<Size2Type, SizeType, Length>::getHeight(){
	return (*this)[1];
}

template<class Size2Type, class SizeType, SizeType Length>
inline const Size2Type& EToolkit::Size2<Size2Type, SizeType, Length>::getHeight() const{
	return (*this)[1];
}

template<class Size2Type, class SizeType, SizeType Length>
inline void EToolkit::Size2<Size2Type, SizeType, Length>::setHeight(const Size2Type& height){
	(*this)[1] = height;
}

#endif /* ESIZE2_HPP */
