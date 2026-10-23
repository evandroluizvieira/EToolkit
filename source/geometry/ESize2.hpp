#ifndef ESIZE2_HPP
#define ESIZE2_HPP

#include "ESize1.hpp"

/*
 * @description: Evandro's C++ Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent 2 dimensional size.
	 * @note: 'Size2Type' must be numeric.
	 */
	template<class Size2Type>
	class Size2 : public Size1<Size2Type>{
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'width' and 'height' values.
			 */
			Size2(Size2Type width = 0, Size2Type height = 0);

			/*
			 * @description: Default destructor.
			 */
			~Size2();

		public:
			Size2Type height;
	};

	typedef Size2<int> Size2i;
}

template<class Size2Type>
EToolkit::Size2<Size2Type>::Size2(Size2Type width, Size2Type height) :
	Size1<Size2Type>(width), height(height){

}

template<class Size2Type>
EToolkit::Size2<Size2Type>::~Size2(){

}

#endif /* ESIZE2_HPP */
