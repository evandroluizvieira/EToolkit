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
     * @tparam Bounds1Type Numeric type used for coordinates and dimensions.
     *
     * Inherits from Position1 and Size1. Can be used as a StaticArray through Position1 or Size1 base.
     *
     * @note Internally, allocates a single contiguous array of 2 elements:
     *       index 0 stores the x coordinate (position),
     *       index 1 stores the width (size).
     */
    template<class Bounds1Type>
    class Bounds1 : virtual public Position1<Bounds1Type>, virtual public Size1<Bounds1Type> {
    public:
    	using Position1<Bounds1Type>::getX; ///< Resolves multiple inheritance ambiguity, specifies getX comes from Position3
    	using Position1<Bounds1Type>::setX; ///< Resolves multiple inheritance ambiguity, specifies setX comes from Position3
    	using Size1<Bounds1Type>::getWidth; ///< Resolves multiple inheritance ambiguity, specifies getWidth comes from Size3
    	using Size1<Bounds1Type>::setWidth; ///< Resolves multiple inheritance ambiguity, specifies setWidth comes from Size3

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
        Bounds1(const Position1<Bounds1Type>& position);

        /**
         * @brief Constructs a Bounds1 object from a Size1 object and x value equals to 0.
         * @param size Size1 object to copy width from.
         */
        Bounds1(const Size1<Bounds1Type>& size);

        /**
         * @brief Virtual destructor.
         */
        virtual ~Bounds1() = default;
    };

    typedef Bounds1<int> Bounds1i; ///< Typedef for integer bounds1.
}

template<class Bounds1Type>
EToolkit::Bounds1<Bounds1Type>::Bounds1(Bounds1Type x, Bounds1Type width) :
	StaticArray<Bounds1Type>({x, width})
{

}

template<class Bounds1Type>
EToolkit::Bounds1<Bounds1Type>::Bounds1(const Position1<Bounds1Type>& position) :
	StaticArray<Bounds1Type>({position.getX(), 0})
{

}

template<class Bounds1Type>
EToolkit::Bounds1<Bounds1Type>::Bounds1(const Size1<Bounds1Type>& size) :
	StaticArray<Bounds1Type>({0, size.getWidth()})
{

}

#endif /* EBOUNDS1_HPP */
