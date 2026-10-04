/**
 * @file EBounds2.hpp
 * @brief Contains Bounds2 template class.
 */

#ifndef EBOUNDS2_HPP
#define EBOUNDS2_HPP

#include "EBounds1.hpp"
#include "EPosition2.hpp"
#include "ESize2.hpp"

/*
 * @namespace EToolkit
 * @brief: Evandro's Toolkit.
 */
namespace EToolkit{

	/**
	 * @class Bounds2
	 * @brief Represents a 2-dimensional bounds (position + size).
	 * @tparam Bounds2Type Numeric type used to store x, y, width, and height.
	 * @tparam BoundsSizeType Type used to index the shared StaticArray and represent its length.
	 * @tparam Length Number of elements in the shared StaticArray storage. The default value 4 is
	 *       required for the x, y, width, and height fields of Bounds2.
	 *
	 * Inherits from Bounds1 and extends it with the y coordinate and height dimension. Bounds1
	 * provides the shared StaticArray storage through its virtual Position1 and Size1 bases.
	 * @extends Bounds1<Bounds2Type, BoundsSizeType, Length>
	 *
	 * Bounds2 uses the inherited StaticArray for all four values. It implements its own coordinate
	 * and dimension accessors because the offsets differ from standalone Position2 and Size2. The
	 * inherited x accessors are exposed with using declarations.
	 *
	 * @note The shared contiguous array maps [0] to x, [1] to y, [2] to width, and [3] to height.
	 *
	 * Bounds2 provides conversion operators to standalone Position2 and Size2 values. It also
	 * inherits the Position1 and Size1 conversion operators from Bounds1. Every conversion creates
	 * a standalone value rather than returning a reference to part of the bounds array.
	 */
	template<class Bounds2Type, class BoundsSizeType, BoundsSizeType Length = 4>
	class Bounds2 : public Bounds1<Bounds2Type, BoundsSizeType, Length> {
	public:
		using Bounds1<Bounds2Type, BoundsSizeType, Length>::getX; ///< Exposes the inherited x-coordinate accessor.
		using Bounds1<Bounds2Type, BoundsSizeType, Length>::setX; ///< Exposes the inherited x-coordinate mutator.

		/**
		 * @brief Constructs a Bounds2 object with given position and size.
		 * @param x Initial x coordinate (default = 0).
		 * @param y Initial y coordinate (default = 0).
		 * @param width Initial width (default = 0).
		 * @param height Initial height (default = 0).
		 */
		Bounds2(Bounds2Type x = 0, Bounds2Type y = 0, Bounds2Type width = 0, Bounds2Type height = 0);

		/**
		 * @brief Constructs a Bounds2 object from a Position2 object and width and height values equal to 0.
		 * @param position Position2 object to copy x and y coordinates from.
		 */
		Bounds2(const Position2<Bounds2Type, BoundsSizeType, Length>& position);

		/**
		 * @brief Constructs a Bounds2 object from a Size2 object and x and y values equal to 0.
		 * @param size Size2 object to copy width and height from.
		 */
		Bounds2(const Size2<Bounds2Type, BoundsSizeType, Length>& size);

		/**
		 * @brief Virtual destructor.
		 */
		virtual ~Bounds2() = default;

		/**
		 * @brief Converts the bounds to a standalone two-dimensional position.
		 * @return A position containing the x and y coordinates.
		 */
		operator Position2<Bounds2Type, BoundsSizeType>() const;

		/**
		 * @brief Converts the bounds to a standalone two-dimensional size.
		 * @return A size containing the width and height.
		 */
		operator Size2<Bounds2Type, BoundsSizeType>() const;

		/**
		 * @brief Gets the y coordinate from the bounds array.
		 * @return Reference to the y value stored at index [1].
		 */
		inline Bounds2Type& getY();

		/**
		 * @brief Gets the y coordinate from the bounds array for a const object.
		 * @return Constant reference to the y value stored at index [1].
		 */
		inline const Bounds2Type& getY() const;

		/**
		 * @brief Sets the y coordinate in the bounds array.
		 * @param y The value to assign at index [1].
		 */
		inline void setY(const Bounds2Type& y);

		/**
		 * @brief Gets the width from the bounds array.
		 * @return Reference to the width value stored at index [2].
		 */
		inline Bounds2Type& getWidth();

		/**
		 * @brief Gets the width from the bounds array for a const object.
		 * @return Constant reference to the width value stored at index [2].
		 */
		inline const Bounds2Type& getWidth() const;

		/**
		 * @brief Sets the width in the bounds array.
		 * @param width The value to assign at index [2].
		 */
		inline void setWidth(const Bounds2Type& width);

		/**
		 * @brief Gets the height from the bounds array.
		 * @return Reference to the height value stored at index [3].
		 */
		inline Bounds2Type& getHeight();

		/**
		 * @brief Gets the height from the bounds array for a const object.
		 * @return Constant reference to the height value stored at index [3].
		 */
		inline const Bounds2Type& getHeight() const;

		/**
		 * @brief Sets the height in the bounds array.
		 * @param height The value to assign at index [3].
		 */
		inline void setHeight(const Bounds2Type& height);

	};

	typedef Bounds2<int, unsigned int> Bounds2i; ///< Typedef for integer bounds2.
}

template<class Bounds2Type, class BoundsSizeType, BoundsSizeType Length>
EToolkit::Bounds2<Bounds2Type, BoundsSizeType, Length>::Bounds2(Bounds2Type x, Bounds2Type y, Bounds2Type width, Bounds2Type height) :
	Bounds1<Bounds2Type, BoundsSizeType, Length>()
{
	(*this)[0] = x;
	(*this)[1] = y;
	(*this)[2] = width;
	(*this)[3] = height;
}

template<class Bounds2Type, class BoundsSizeType, BoundsSizeType Length>
EToolkit::Bounds2<Bounds2Type, BoundsSizeType, Length>::Bounds2(const Position2<Bounds2Type, BoundsSizeType, Length>& position) :
	Bounds1<Bounds2Type, BoundsSizeType, Length>()
{
	(*this)[0] = position.getX();
	(*this)[1] = position.getY();
	(*this)[2] = 0;
	(*this)[3] = 0;
}

template<class Bounds2Type, class BoundsSizeType, BoundsSizeType Length>
EToolkit::Bounds2<Bounds2Type, BoundsSizeType, Length>::Bounds2(const Size2<Bounds2Type, BoundsSizeType, Length>& size) :
	Bounds1<Bounds2Type, BoundsSizeType, Length>()
{
	(*this)[0] = 0;
	(*this)[1] = 0;
	(*this)[2] = size.getWidth();
	(*this)[3] = size.getHeight();
}

template<class Bounds2Type, class BoundsSizeType, BoundsSizeType Length>
EToolkit::Bounds2<Bounds2Type, BoundsSizeType, Length>::operator Position2<Bounds2Type, BoundsSizeType>() const{
	return Position2<Bounds2Type, BoundsSizeType>(getX(), getY());
}

template<class Bounds2Type, class BoundsSizeType, BoundsSizeType Length>
EToolkit::Bounds2<Bounds2Type, BoundsSizeType, Length>::operator Size2<Bounds2Type, BoundsSizeType>() const{
	return Size2<Bounds2Type, BoundsSizeType>(getWidth(), getHeight());
}

template<class Bounds2Type, class BoundsSizeType, BoundsSizeType Length>
inline Bounds2Type& EToolkit::Bounds2<Bounds2Type, BoundsSizeType, Length>::getY(){
	return (*this)[1];
}

template<class Bounds2Type, class BoundsSizeType, BoundsSizeType Length>
inline const Bounds2Type& EToolkit::Bounds2<Bounds2Type, BoundsSizeType, Length>::getY() const{
	return (*this)[1];
}

template<class Bounds2Type, class BoundsSizeType, BoundsSizeType Length>
inline void EToolkit::Bounds2<Bounds2Type, BoundsSizeType, Length>::setY(const Bounds2Type& y){
	(*this)[1] = y;
}

template<class Bounds2Type, class BoundsSizeType, BoundsSizeType Length>
inline Bounds2Type& EToolkit::Bounds2<Bounds2Type, BoundsSizeType, Length>::getWidth(){
	return (*this)[2];
}

template<class Bounds2Type, class BoundsSizeType, BoundsSizeType Length>
inline const Bounds2Type& EToolkit::Bounds2<Bounds2Type, BoundsSizeType, Length>::getWidth() const{
	return (*this)[2];
}

template<class Bounds2Type, class BoundsSizeType, BoundsSizeType Length>
inline void EToolkit::Bounds2<Bounds2Type, BoundsSizeType, Length>::setWidth(const Bounds2Type& width){
	(*this)[2] = width;
}

template<class Bounds2Type, class BoundsSizeType, BoundsSizeType Length>
inline Bounds2Type& EToolkit::Bounds2<Bounds2Type, BoundsSizeType, Length>::getHeight(){
	return (*this)[3];
}

template<class Bounds2Type, class BoundsSizeType, BoundsSizeType Length>
inline const Bounds2Type& EToolkit::Bounds2<Bounds2Type, BoundsSizeType, Length>::getHeight() const{
	return (*this)[3];
}

template<class Bounds2Type, class BoundsSizeType, BoundsSizeType Length>
inline void EToolkit::Bounds2<Bounds2Type, BoundsSizeType, Length>::setHeight(const Bounds2Type& height){
	(*this)[3] = height;
}

#endif /* EBOUNDS2_HPP */
