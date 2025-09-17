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
     * @tparam Bounds3Type Numeric type used for coordinates and dimensions.
     *
     * Inherits from Bounds2, Position3 and Size3. Can be used as a StaticArray through Position3 or Size3 bases.
     *
     * @note Internally, allocates a single contiguous array of 6 elements:
     *       index 0 stores x coordinate,
     *       index 1 stores y coordinate,
     *       index 2 stores z coordinate,
     *       index 3 stores width,
     *       index 4 stores height,
     *       index 5 stores depth.
     */
    template<class Bounds3Type>
    class Bounds3 : public Bounds2<Bounds3Type>, virtual public Position3<Bounds3Type>, virtual public Size3<Bounds3Type> {
    public:
    	using Position3<Bounds3Type>::getX;  ///< Resolves multiple inheritance ambiguity, specifies getX comes from Position3
    	using Position3<Bounds3Type>::setX;  ///< Resolves multiple inheritance ambiguity, specifies setX comes from Position3
    	using Position3<Bounds3Type>::getY;  ///< Resolves multiple inheritance ambiguity, specifies getY comes from Position3
    	using Position3<Bounds3Type>::setY;  ///< Resolves multiple inheritance ambiguity, specifies setY comes from Position3
    	using Position3<Bounds3Type>::getZ;  ///< Resolves multiple inheritance ambiguity, specifies getZ comes from Position3
    	using Position3<Bounds3Type>::setZ;  ///< Resolves multiple inheritance ambiguity, specifies setZ comes from Position3
    	using Size3<Bounds3Type>::getWidth;  ///< Resolves multiple inheritance ambiguity, specifies getWidth  comes from Size3
    	using Size3<Bounds3Type>::setWidth;  ///< Resolves multiple inheritance ambiguity, specifies setWidth  comes from Size3
    	using Size3<Bounds3Type>::getHeight; ///< Resolves multiple inheritance ambiguity, specifies getHeight comes from Size3
    	using Size3<Bounds3Type>::setHeight; ///< Resolves multiple inheritance ambiguity, specifies setHeight comes from Size3
    	using Size3<Bounds3Type>::getDepth;  ///< Resolves multiple inheritance ambiguity, specifies getDepth  comes from Size3
    	using Size3<Bounds3Type>::setDepth;  ///< Resolves multiple inheritance ambiguity, specifies setDepth  comes from Size3

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
    	Bounds3(const Position3<Bounds3Type>& position);

    	/**
    	 * @brief Constructs a Bounds3 object from a Size3 object and x, y and z values equal to 0.
    	 * @param size Size3 object to copy width, height and depth from.
    	 */
    	Bounds3(const Size3<Bounds3Type>& size);

        /**
         * @brief Virtual destructor.
         */
        virtual ~Bounds3() = default;
    };

    typedef Bounds3<int> Bounds3i; ///< Typedef for integer bounds3.
}

template<class Bounds3Type>
EToolkit::Bounds3<Bounds3Type>::Bounds3(Bounds3Type x, Bounds3Type y, Bounds3Type z, Bounds3Type width, Bounds3Type height, Bounds3Type depth) :
	StaticArray<Bounds3Type>({x, y, z, width, height, depth})
{

}

template<class Bounds3Type>
EToolkit::Bounds3<Bounds3Type>::Bounds3(const Position3<Bounds3Type>& position) :
	StaticArray<Bounds3Type>({position.getX(), position.getY(), position.getZ(), 0, 0, 0})
{

}

template<class Bounds3Type>
EToolkit::Bounds3<Bounds3Type>::Bounds3(const Size3<Bounds3Type>& size) :
	StaticArray<Bounds3Type>({0, 0, 0, size.getWidth(), size.getHeight(), size.getDepth()})
{

}

#endif /* EBOUNDS3_HPP */
