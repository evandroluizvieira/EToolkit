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
	 * @tparam Size3Type Numeric type used to store the width, height, and depth dimensions.
	 * @tparam SizeType Type used to index the StaticArray and represent its length.
	 * @tparam Length Number of elements in the shared StaticArray storage. The default value 3 is
	 *       the standalone storage size for width, height, and depth. A larger value can be
	 *       propagated through Size2 and Size1 when Size3 uses a larger shared size array.
	 *
	 * Inherits from Size2 with size 2 and extends it with the depth dimension.
	 * Virtually inherits from Size2 and preserves one StaticArray when this type participates in
	 * the multidimensional Size hierarchy.
	 *
	 * @note The shared contiguous array maps [0] to width, [1] to height, and [2] to depth.
	 *
	 * Size3 repeats SizeType and Length so its Size2, Size1, and StaticArray bases remain the same
	 * specialization. This is required for one shared virtual array throughout the Size hierarchy.
	 */
	template<class Size3Type, class SizeType, SizeType Length = 3>
	class Size3 : virtual public Size2<Size3Type, SizeType, Length>{
		public:
			using Size2<Size3Type, SizeType, Length>::getWidth; ///< Exposes the inherited width accessor from Size2.
			using Size2<Size3Type, SizeType, Length>::setWidth; ///< Exposes the inherited width mutator from Size2.
			using Size2<Size3Type, SizeType, Length>::getHeight; ///< Exposes the inherited height accessor from Size2.
			using Size2<Size3Type, SizeType, Length>::setHeight; ///< Exposes the inherited height mutator from Size2.

			/**
			 * @brief Constructs a size with the given width, height, and depth.
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

	typedef Size3<int, unsigned int> Size3i; ///< Typedef for integer 3D size.
}

template<class Size3Type, class SizeType, SizeType Length>
EToolkit::Size3<Size3Type, SizeType, Length>::Size3(Size3Type width, Size3Type height, Size3Type depth) :
	StaticArray<Size3Type, SizeType, Length>({width, height, depth}), Size2<Size3Type, SizeType, Length>(width, height){
	(*this)[0] = width;
	(*this)[1] = height;
	(*this)[2] = depth;
}

template<class Size3Type, class SizeType, SizeType Length>
inline Size3Type& EToolkit::Size3<Size3Type, SizeType, Length>::getDepth(){
	return (*this)[2];
}

template<class Size3Type, class SizeType, SizeType Length>
inline const Size3Type& EToolkit::Size3<Size3Type, SizeType, Length>::getDepth() const{
	return (*this)[2];
}

template<class Size3Type, class SizeType, SizeType Length>
inline void EToolkit::Size3<Size3Type, SizeType, Length>::setDepth(const Size3Type& depth){
	(*this)[2] = depth;
}

#endif /* ESIZE3_HPP */
