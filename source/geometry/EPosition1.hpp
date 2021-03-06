#ifndef EPOSITION1_HPP
#define EPOSITION1_HPP

/*
 * @description: Evandro's C++ Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent 1 dimensional position.
	 * @note: 'Color2Type' must be numeric.
	 */
	template<class Position1Type>
	class Position1{
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'x' value.
			 */
			Position1(Position1Type x = 0);

			/*
			 * @description: Default destructor.
			 */
			~Position1();

		public:
			Position1Type x;
	};
}

template<class Position1Type>
EToolkit::Position1<Position1Type>::Position1(Position1Type x) :
	x(x){

}

template<class Position1Type>
EToolkit::Position1<Position1Type>::~Position1(){

}

#endif /* EPOSITION1_HPP */
