#ifndef EPOSITION2_HPP
#define EPOSITION2_HPP

#include "EPosition1.hpp"

/*
 * @description: Evandro's C++ Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent 2 dimensional position.
	 * @note: 'Position2Type' must be numeric.
	 */
	template<class Position2Type>
	class Position2 : public Position1<Position2Type>{
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'x' and 'y' values.
			 * @return: None.
			 */
			Position2(Position2Type x = 0, Position2Type y = 0);

			/*
			 * @description: Default destructor.
			 * @return: None.
			 */
			~Position2();

		public:
			Position2Type y;
	};

	typedef Position2<int> Position2i;
}

template<class Position2Type>
EToolkit::Position2<Position2Type>::Position2(Position2Type x, Position2Type y) :
	Position1<Position2Type>(x), y(y){

}

template<class Position2Type>
EToolkit::Position2<Position2Type>::~Position2(){

}

#endif /* EPOSITION2_HPP */
