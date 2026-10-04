/**
 * @file EBounds1.hpp
 * @brief Contains Bounds1 template class.
 */

#ifndef EBOUNDS1_HPP
#define EBOUNDS1_HPP

#include "EPosition1.hpp"
#include "ESize1.hpp"

/*
 * @namespace EToolkit
 * @brief: Evandro's Toolkit.
 */
namespace EToolkit{

	/**
     * @class Bounds1
     * @brief Represents a 1-dimensional bounds (position + size).
     * @tparam Bounds1Type Numeric type used to store the x coordinate and width.
     * @tparam BoundsSizeType Type used to index the StaticArray and represent its length.
     * @tparam Length Number of elements in the shared StaticArray storage. The default value 2 is
     *       required for the x and width fields of Bounds1.
	 *
     * Inherits from Position1 and Size1, which share one virtual StaticArray with two elements.
     * @extends Position1<Bounds1Type, BoundsSizeType, Length>
     * @extends Size1<Bounds1Type, BoundsSizeType, Length>
	 *
     * Bounds1 is the root of the Bounds inheritance chain. Its Position1 and Size1 bases are
     * virtual and receive the same Length, so they share one two-element StaticArray. Bounds2 and
     * Bounds3 extend this chain by reusing the inherited storage and access contract.
	 *
	 * @note The shared contiguous array maps [0] to x and [1] to width.
     * @note The inherited StaticArray operators provide direct access to the shared storage.
     *
     * Bounds1 exposes conversion operators to standalone Position1 and Size1 values. Derived Bounds
     * classes inherit these operators and add conversions for their own dimensions. The conversions
     * create standalone values; they do not return references to subobjects.
	 */
    template<class Bounds1Type, class BoundsSizeType, BoundsSizeType Length = 2>
    class Bounds1 :
        virtual public Position1<Bounds1Type, BoundsSizeType, Length>,
        virtual public Size1<Bounds1Type, BoundsSizeType, Length> {
    public:
        using Position1<Bounds1Type, BoundsSizeType, Length>::getX; ///< Exposes the inherited x-coordinate accessor.
        using Position1<Bounds1Type, BoundsSizeType, Length>::setX; ///< Exposes the inherited x-coordinate mutator.

        /**
         * @brief Constructs a Bounds1 object with given position and size.
         * @param x Initial x coordinate (default = 0).
         * @param width Initial width value (default = 0).
         */
        Bounds1(Bounds1Type x = 0, Bounds1Type width = 0);

        /**
         * @brief Constructs a Bounds1 object from a Position1 object and width value equals to 0.
         * @param position Position1 object to copy x coordinate from.
         */
        Bounds1(const Position1<Bounds1Type, BoundsSizeType, Length>& position);

        /**
         * @brief Constructs a Bounds1 object from a Size1 object and x value equals to 0.
         * @param size Size1 object to copy width from.
         */
        Bounds1(const Size1<Bounds1Type, BoundsSizeType, Length>& size);

        /**
         * @brief Virtual destructor.
         */
        virtual ~Bounds1() = default;

        /**
         * @brief Converts the bounds to a standalone one-dimensional position.
         * @return A position containing the x coordinate.
         */
        operator Position1<Bounds1Type, BoundsSizeType>() const;

        /**
         * @brief Converts the bounds to a standalone one-dimensional size.
         * @return A size containing the width.
         */
        operator Size1<Bounds1Type, BoundsSizeType>() const;

        /**
         * @brief Gets the width from the bounds array.
         * @return Reference to the width value stored at index [1].
         */
        inline Bounds1Type& getWidth();

        /**
         * @brief Gets the width from the bounds array for a const object.
         * @return Constant reference to the width value stored at index [1].
         */
        inline const Bounds1Type& getWidth() const;

        /**
         * @brief Sets the width in the bounds array.
         * @param width The value to assign at index [1].
         */
        inline void setWidth(const Bounds1Type& width);

    };

	typedef Bounds1<int, unsigned int> Bounds1i; ///< Typedef for integer bounds1.
}

template<class Bounds1Type, class BoundsSizeType, BoundsSizeType Length>
EToolkit::Bounds1<Bounds1Type, BoundsSizeType, Length>::Bounds1(Bounds1Type x, Bounds1Type width) :
    StaticArray<Bounds1Type, BoundsSizeType, Length>(),
    Position1<Bounds1Type, BoundsSizeType, Length>(),
    Size1<Bounds1Type, BoundsSizeType, Length>()
{
	(*this)[0] = x;
	(*this)[1] = width;
}

template<class Bounds1Type, class BoundsSizeType, BoundsSizeType Length>
EToolkit::Bounds1<Bounds1Type, BoundsSizeType, Length>::Bounds1(const Position1<Bounds1Type, BoundsSizeType, Length>& position) :
    StaticArray<Bounds1Type, BoundsSizeType, Length>(),
    Position1<Bounds1Type, BoundsSizeType, Length>(),
    Size1<Bounds1Type, BoundsSizeType, Length>()
{
	(*this)[0] = position.getX();
	(*this)[1] = 0;
}

template<class Bounds1Type, class BoundsSizeType, BoundsSizeType Length>
EToolkit::Bounds1<Bounds1Type, BoundsSizeType, Length>::Bounds1(const Size1<Bounds1Type, BoundsSizeType, Length>& size) :
    StaticArray<Bounds1Type, BoundsSizeType, Length>(),
    Position1<Bounds1Type, BoundsSizeType, Length>(),
    Size1<Bounds1Type, BoundsSizeType, Length>()
{
	(*this)[0] = 0;
	(*this)[1] = size.getWidth();
}

template<class Bounds1Type, class BoundsSizeType, BoundsSizeType Length>
EToolkit::Bounds1<Bounds1Type, BoundsSizeType, Length>::operator Position1<Bounds1Type, BoundsSizeType>() const{
    return Position1<Bounds1Type, BoundsSizeType>(getX());
}

template<class Bounds1Type, class BoundsSizeType, BoundsSizeType Length>
EToolkit::Bounds1<Bounds1Type, BoundsSizeType, Length>::operator Size1<Bounds1Type, BoundsSizeType>() const{
    return Size1<Bounds1Type, BoundsSizeType>(getWidth());
}

template<class Bounds1Type, class BoundsSizeType, BoundsSizeType Length>
inline Bounds1Type& EToolkit::Bounds1<Bounds1Type, BoundsSizeType, Length>::getWidth(){
    return (*this)[1];
}

template<class Bounds1Type, class BoundsSizeType, BoundsSizeType Length>
inline const Bounds1Type& EToolkit::Bounds1<Bounds1Type, BoundsSizeType, Length>::getWidth() const{
    return (*this)[1];
}

template<class Bounds1Type, class BoundsSizeType, BoundsSizeType Length>
inline void EToolkit::Bounds1<Bounds1Type, BoundsSizeType, Length>::setWidth(const Bounds1Type& width){
    (*this)[1] = width;
}

#endif /* EBOUNDS1_HPP */
