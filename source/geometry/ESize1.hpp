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
	 * @tparam Size1Type Numeric type used to store the width dimension.
	 * @tparam SizeType Type used to index the StaticArray and represent its length.
	 * @tparam Length Number of elements in the shared StaticArray storage. The default value 1 is
	 *       the standalone storage size for width. A larger value can be used when Size1 is a
	 *       virtual base of Size2 or Size3.
	 *
	 * Inherits from StaticArray with size 1. Provides access methods to the single dimension 'width'.
	 * Virtually inherits from StaticArray so that derived multidimensional sizes can share one
	 * contiguous array.
	 *
	 * @note The shared contiguous array maps [0] to width.
	 *
	 * Size1 has a separate SizeType parameter because the type used for dimensions is not required
	 * to be the type used for array indices. Length is compile-time storage information and is
	 * repeated by derived size classes to preserve one compatible virtual StaticArray.
	 */
	template<class Size1Type, class SizeType, SizeType Length = 1>
	class Size1 : virtual public StaticArray<Size1Type, SizeType, Length>{
		public:
			/**
			 * @brief Constructs a size with the given width.
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

	typedef Size1<int, unsigned int> Size1i; ///< Typedef for integer 1D size.
}

template<class Size1Type, class SizeType, SizeType Length>
EToolkit::Size1<Size1Type, SizeType, Length>::Size1(Size1Type width) :
	StaticArray<Size1Type, SizeType, Length>({width}){
	(*this)[0] = width;
}

template<class Size1Type, class SizeType, SizeType Length>
inline Size1Type& EToolkit::Size1<Size1Type, SizeType, Length>::getWidth(){
	return (*this)[0];
}

template<class Size1Type, class SizeType, SizeType Length>
inline const Size1Type& EToolkit::Size1<Size1Type, SizeType, Length>::getWidth() const{
	return (*this)[0];
}

template<class Size1Type, class SizeType, SizeType Length>
inline void EToolkit::Size1<Size1Type, SizeType, Length>::setWidth(const Size1Type& width){
	(*this)[0] = width;
}

#endif /* ESIZE1_HPP */
