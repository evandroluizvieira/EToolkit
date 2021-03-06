#ifndef EPOSITION3_HPP
#define EPOSITION3_HPP

#include <EPosition>

/*
 * @description: Evandro's C++ Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent 3 dimensional position.
	 * @note: 'Color2Type' must be numeric.
	 */
	template<class Position3Type>
	class Position3 : public Position2<Position3Type>{
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'x', 'y' and 'z' values.
			 */
			Position3(Position3Type x = 0, Position3Type y = 0, Position3Type z = 0);

			/*
			 * @description: Default destructor.
			 */
			~Position3();

		public:
			Position3Type z;
	};
}

template<class Position3Type>
EToolkit::Position3<Position3Type>::Position3(Position3Type x, Position3Type y, Position3Type z) :
	Position2<Position3Type>(x, y), z(z){

}

template<class Position3Type>
EToolkit::Position3<Position3Type>::~Position3(){

}

#endif /* EPOSITION3_HPP */
