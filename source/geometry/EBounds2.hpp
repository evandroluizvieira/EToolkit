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
     * @tparam Bounds2Type Numeric type used for coordinates and dimensions.
     *
     * Inherits from Bounds1, Position2 and Size2. Can be used as a StaticArray through Position2 or Size2 bases.
     *
     * @note Internally, allocates a single contiguous array of 4 elements:
     *       index 0 stores x coordinate,
     *       index 1 stores y coordinate,
     *       index 2 stores width,
     *       index 3 stores height.
     */
    template<class Bounds2Type>
    class Bounds2 : public Bounds1<Bounds2Type>, virtual public Position2<Bounds2Type>, virtual public Size2<Bounds2Type> {
    public:
    	using Position2<Bounds2Type>::getX; ///< Resolves multiple inheritance ambiguity, specifies getX comes from Position3
    	using Position2<Bounds2Type>::setX; ///< Resolves multiple inheritance ambiguity, specifies setX comes from Position3
    	using Position2<Bounds2Type>::getY; ///< Resolves multiple inheritance ambiguity, specifies getY comes from Position3
    	using Position2<Bounds2Type>::setY; ///< Resolves multiple inheritance ambiguity, specifies setY comes from Position3
    	using Size2<Bounds2Type>::getWidth; ///< Resolves multiple inheritance ambiguity, specifies getWidth comes from Size3
    	using Size2<Bounds2Type>::setWidth; ///< Resolves multiple inheritance ambiguity, specifies setWidth comes from Size3
    	using Size2<Bounds2Type>::getHeight; ///< Resolves multiple inheritance ambiguity, specifies getHeight comes from Size3
    	using Size2<Bounds2Type>::setHeight; ///< Resolves multiple inheritance ambiguity, specifies setHeight comes from Size3

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
    	Bounds2(const Position2<Bounds2Type>& position);

    	/**
    	 * @brief Constructs a Bounds2 object from a Size2 object and x and y values equal to 0.
    	 * @param size Size2 object to copy width and height from.
    	 */
    	Bounds2(const Size2<Bounds2Type>& size);

        /**
         * @brief Virtual destructor.
         */
        virtual ~Bounds2() = default;
    };

    typedef Bounds2<int> Bounds2i; ///< Typedef for integer bounds2.
}

template<class Bounds2Type>
EToolkit::Bounds2<Bounds2Type>::Bounds2(Bounds2Type x, Bounds2Type y, Bounds2Type width, Bounds2Type height) :
	StaticArray<Bounds2Type>({x, y, width, height})
{

}

template<class Bounds2Type>
EToolkit::Bounds2<Bounds2Type>::Bounds2(const Position2<Bounds2Type>& position) :
	StaticArray<Bounds2Type>({position.getX(), position.getY(), 0, 0})
{

}

template<class Bounds2Type>
EToolkit::Bounds2<Bounds2Type>::Bounds2(const Size2<Bounds2Type>& size) :
	StaticArray<Bounds2Type>({0, 0, size.getWidth(), size.getHeight()})
{

}

#endif /* EBOUNDS2_HPP */
