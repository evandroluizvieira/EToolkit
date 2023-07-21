#ifndef EBOUNDS3_HPP
#define EBOUNDS3_HPP

#include "EPosition3.hpp"
#include "ESize3.hpp"

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent a object with 3 dimensional position and size.
	 * @note: 'Bounds3Type' must be numeric.
	 */
	template<class Bounds3Type>
	class Bounds3 : public Position3<Bounds3Type>, public Size3<Bounds3Type>{
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'x', 'y', 'z', 'width', 'height' and 'depth' values.
			 * @return: None.
			 */
			Bounds3(Bounds3Type x = 0, Bounds3Type y = 0, Bounds3Type z = 0, Bounds3Type width = 0, Bounds3Type height = 0, Bounds3Type depth = 0);

			/*
			 * @description: Default destructor.
			 * @return: None.
			 */
			~Bounds3();
	};

	typedef Bounds3<int> Bounds3i;
}

template<class Bounds3Type>
EToolkit::Bounds3<Bounds3Type>::Bounds3(Bounds3Type x, Bounds3Type y, Bounds3Type z, Bounds3Type width, Bounds3Type height, Bounds3Type depth) :
	Position3<Bounds3Type>(x, y, z), Size3<Bounds3Type>(width, height, depth){

}

template<class Bounds3Type>
EToolkit::Bounds3<Bounds3Type>::~Bounds3(){

}

#endif /* EBOUNDS3_HPP */
