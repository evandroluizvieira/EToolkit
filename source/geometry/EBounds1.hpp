#ifndef EBOUNDS1_HPP
#define EBOUNDS1_HPP

#include "EPosition1.hpp"
#include "ESize1.hpp"

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent a object with 1 dimensional position and size.
	 * @note: 'Bounds1Type' must be numeric.
	 */
	template<class Bounds1Type>
	class Bounds1 : public Position1<Bounds1Type>, public Size1<Bounds1Type>{
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'x' and 'width' values.
			 * @return: None.
			 */
			Bounds1(Bounds1Type x = 0, Bounds1Type width = 0);

			/*
			 * @description: Default destructor.
			 * @return: None.
			 */
			~Bounds1();
	};

	typedef Bounds1<int> Bounds1i;
}

template<class Bounds1Type>
EToolkit::Bounds1<Bounds1Type>::Bounds1(Bounds1Type x, Bounds1Type width) :
	Position1<Bounds1Type>(x), Size1<Bounds1Type>(width){

}

template<class Bounds1Type>
EToolkit::Bounds1<Bounds1Type>::~Bounds1(){

}

#endif /* EBOUNDS1_HPP */
