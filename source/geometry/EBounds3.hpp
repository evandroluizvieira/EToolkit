/**
 * @file EBounds3.hpp
 * @brief Contains Bounds3 template class.
 */

#ifndef EBOUNDS3_HPP
#define EBOUNDS3_HPP

#include "EBounds2.hpp"
#include "EPosition3.hpp"
#include "ESize3.hpp"

/*
 * @namespace EToolkit
 * @brief: Evandro's Toolkit.
 */
namespace EToolkit{

	/**
	 * @class Bounds3
	 * @brief Represents a 3-dimensional bounds (position + size).
	 * @tparam Bounds3Type Numeric type used to store x, y, z, width, height, and depth.
	 * @tparam BoundsSizeType Type used to index the shared StaticArray and represent its length.
	 * @tparam Length Number of elements in the shared StaticArray storage. The default value 6 is
	 *       required for the x, y, z, width, height, and depth fields of standalone Bounds3.
	 *
	 * Inherits from Bounds2 and extends it with the z coordinate and depth dimension. Bounds1 and
	 * Bounds2 provide the shared StaticArray storage through their virtual Position and Size bases.
	 * @extends Bounds2<Bounds3Type, BoundsSizeType, Length>
	 *
	 * Bounds3 uses the inherited StaticArray for all six values. It implements the accessors whose
	 * offsets differ from standalone Position3 and Size3, while exposing inherited coordinate
	 * accessors with using declarations.
	 *
	 * @note The shared contiguous array maps [0] to x, [1] to y, [2] to z, [3] to width,
	 *       [4] to height, and [5] to depth.
	 *
	 * Bounds3 provides conversion operators to standalone Position3 and Size3 values. It also
	 * inherits the conversion operators for the lower dimensions from Bounds1 and Bounds2. Every
	 * conversion creates a standalone value rather than returning a reference to part of the bounds
	 * array.
	 */
	template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length = 6>
	class Bounds3 : public Bounds2<Bounds3Type, BoundsSizeType, Length> {
	public:
		using Bounds2<Bounds3Type, BoundsSizeType, Length>::getX; ///< Exposes the inherited x-coordinate accessor.
		using Bounds2<Bounds3Type, BoundsSizeType, Length>::setX; ///< Exposes the inherited x-coordinate mutator.
		using Bounds2<Bounds3Type, BoundsSizeType, Length>::getY; ///< Exposes the inherited y-coordinate accessor.
		using Bounds2<Bounds3Type, BoundsSizeType, Length>::setY; ///< Exposes the inherited y-coordinate mutator.

		/**
		 * @brief Constructs a Bounds3 object with given position and size.
		 * @param x Initial x coordinate (default = 0).
		 * @param y Initial y coordinate (default = 0).
		 * @param z Initial z coordinate (default = 0).
		 * @param width Initial width (default = 0).
		 * @param height Initial height (default = 0).
		 * @param depth Initial depth (default = 0).
		 */
		Bounds3(Bounds3Type x = 0, Bounds3Type y = 0, Bounds3Type z = 0, Bounds3Type width = 0, Bounds3Type height = 0, Bounds3Type depth = 0);

		/**
		 * @brief Constructs a Bounds3 object from a Position3 object and width, height and depth values equal to 0.
		 * @param position Position3 object to copy x, y, z coordinates from.
		 */
		Bounds3(const Position3<Bounds3Type, BoundsSizeType, Length>& position);

		/**
		 * @brief Constructs a Bounds3 object from a Size3 object and x, y and z values equal to 0.
		 * @param size Size3 object to copy width, height and depth from.
		 */
		Bounds3(const Size3<Bounds3Type, BoundsSizeType, Length>& size);

		/**
		 * @brief Virtual destructor.
		 */
		virtual ~Bounds3() = default;

		/**
		 * @brief Converts the bounds to a standalone three-dimensional position.
		 * @return A position containing the x, y, and z coordinates.
		 */
		operator Position3<Bounds3Type, BoundsSizeType>() const;

		/**
		 * @brief Converts the bounds to a standalone three-dimensional size.
		 * @return A size containing the width, height, and depth.
		 */
		operator Size3<Bounds3Type, BoundsSizeType>() const;

		/**
		 * @brief Gets the z coordinate from the bounds array.
		 * @return Reference to the z value stored at index [2].
		 */
		inline Bounds3Type& getZ();

		/**
		 * @brief Gets the z coordinate from the bounds array for a const object.
		 * @return Constant reference to the z value stored at index [2].
		 */
		inline const Bounds3Type& getZ() const;

		/**
		 * @brief Sets the z coordinate in the bounds array.
		 * @param z The value to assign at index [2].
		 */
		inline void setZ(const Bounds3Type& z);

		/**
		 * @brief Gets the width from the bounds array.
		 * @return Reference to the width value stored at index [3].
		 */
		inline Bounds3Type& getWidth();

		/**
		 * @brief Gets the width from the bounds array for a const object.
		 * @return Constant reference to the width value stored at index [3].
		 */
		inline const Bounds3Type& getWidth() const;

		/**
		 * @brief Sets the width in the bounds array.
		 * @param width The value to assign at index [3].
		 */
		inline void setWidth(const Bounds3Type& width);

		/**
		 * @brief Gets the height from the bounds array.
		 * @return Reference to the height value stored at index [4].
		 */
		inline Bounds3Type& getHeight();

		/**
		 * @brief Gets the height from the bounds array for a const object.
		 * @return Constant reference to the height value stored at index [4].
		 */
		inline const Bounds3Type& getHeight() const;

		/**
		 * @brief Sets the height in the bounds array.
		 * @param height The value to assign at index [4].
		 */
		inline void setHeight(const Bounds3Type& height);

		/**
		 * @brief Gets the depth from the bounds array.
		 * @return Reference to the depth value stored at index [5].
		 */
		inline Bounds3Type& getDepth();

		/**
		 * @brief Gets the depth from the bounds array for a const object.
		 * @return Constant reference to the depth value stored at index [5].
		 */
		inline const Bounds3Type& getDepth() const;

		/**
		 * @brief Sets the depth in the bounds array.
		 * @param depth The value to assign at index [5].
		 */
		inline void setDepth(const Bounds3Type& depth);

	};

	typedef Bounds3<int, unsigned int> Bounds3i; ///< Typedef for integer bounds3.
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::Bounds3(Bounds3Type x, Bounds3Type y, Bounds3Type z, Bounds3Type width, Bounds3Type height, Bounds3Type depth) :
	Bounds2<Bounds3Type, BoundsSizeType, Length>()
{
	(*this)[0] = x;
	(*this)[1] = y;
	(*this)[2] = z;
	(*this)[3] = width;
	(*this)[4] = height;
	(*this)[5] = depth;
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::Bounds3(const Position3<Bounds3Type, BoundsSizeType, Length>& position) :
	Bounds2<Bounds3Type, BoundsSizeType, Length>()
{
	(*this)[0] = position.getX();
	(*this)[1] = position.getY();
	(*this)[2] = position.getZ();
	(*this)[3] = 0;
	(*this)[4] = 0;
	(*this)[5] = 0;
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::Bounds3(const Size3<Bounds3Type, BoundsSizeType, Length>& size) :
	Bounds2<Bounds3Type, BoundsSizeType, Length>()
{
	(*this)[0] = 0;
	(*this)[1] = 0;
	(*this)[2] = 0;
	(*this)[3] = size.getWidth();
	(*this)[4] = size.getHeight();
	(*this)[5] = size.getDepth();
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::operator Position3<Bounds3Type, BoundsSizeType>() const{
	return Position3<Bounds3Type, BoundsSizeType>(getX(), getY(), getZ());
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::operator Size3<Bounds3Type, BoundsSizeType>() const{
	return Size3<Bounds3Type, BoundsSizeType>(getWidth(), getHeight(), getDepth());
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
inline Bounds3Type& EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::getZ(){
	return (*this)[2];
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
inline const Bounds3Type& EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::getZ() const{
	return (*this)[2];
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
inline void EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::setZ(const Bounds3Type& z){
	(*this)[2] = z;
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
inline Bounds3Type& EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::getWidth(){
	return (*this)[3];
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
inline const Bounds3Type& EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::getWidth() const{
	return (*this)[3];
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
inline void EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::setWidth(const Bounds3Type& width){
	(*this)[3] = width;
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
inline Bounds3Type& EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::getHeight(){
	return (*this)[4];
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
inline const Bounds3Type& EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::getHeight() const{
	return (*this)[4];
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
inline void EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::setHeight(const Bounds3Type& height){
	(*this)[4] = height;
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
inline Bounds3Type& EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::getDepth(){
	return (*this)[5];
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
inline const Bounds3Type& EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::getDepth() const{
	return (*this)[5];
}

template<class Bounds3Type, class BoundsSizeType, BoundsSizeType Length>
inline void EToolkit::Bounds3<Bounds3Type, BoundsSizeType, Length>::setDepth(const Bounds3Type& depth){
	(*this)[5] = depth;
}

#endif /* EBOUNDS3_HPP */
