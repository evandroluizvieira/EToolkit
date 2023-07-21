#ifndef ESIZE3_HPP
#define ESIZE3_HPP

#include "ESize2.hpp"

/*
 * @description: Evandro's C++ Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent 2 dimensional size.
	 * @note: 'Size3Type' must be numeric.
	 */
	template<class Size3Type>
	class Size3 : public Size2<Size3Type>{
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'width', 'height' and 'depth' values.
			 */
			Size3(Size3Type width = 0, Size3Type height = 0, Size3Type depth = 0);

			/*
			 * @description: Default destructor.
			 */
			~Size3();

		public:
			Size3Type depth;
	};
}

template<class Size3Type>
EToolkit::Size3<Size3Type>::Size3(Size3Type width, Size3Type height, Size3Type depth) :
	Size2<Size3Type>(width, height), depth(depth){

}

template<class Size3Type>
EToolkit::Size3<Size3Type>::~Size3(){

}

#endif /* ESIZE3_HPP */
