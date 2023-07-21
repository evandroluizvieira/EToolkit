#ifndef EBOUNDS2_HPP
#define EBOUNDS2_HPP

#include <EToolkit>

#include <EPosition>
#include <ESize>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent a object with 2 dimensional position and size.
	 * @note: 'Bounds2Type' must be numeric.
	 */
	template<class Bounds2Type>
	class Bounds2 : public Position2<Bounds2Type>, public Size2<Bounds2Type>{
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'x', 'y', 'width' and 'height' values.
			 * @return: None.
			 */
			Bounds2(Bounds2Type x = 0, Bounds2Type y = 0, Bounds2Type width = 0, Bounds2Type height = 0);

			/*
			 * @description: Default destructor.
			 * @return: None.
			 */
			~Bounds2();
	};

	typedef Bounds2<int> Bounds2i;
}

template<class Bounds2Type>
EToolkit::Bounds2<Bounds2Type>::Bounds2(Bounds2Type x, Bounds2Type y, Bounds2Type width, Bounds2Type height) :
	Position2<Bounds2Type>(x, y), Size2<Bounds2Type>(width, height){

}

template<class Bounds2Type>
EToolkit::Bounds2<Bounds2Type>::~Bounds2(){

}

#endif /* EBOUNDS2_HPP */
