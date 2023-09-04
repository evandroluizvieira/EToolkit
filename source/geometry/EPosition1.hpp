#ifndef EPOSITION1_HPP
#define EPOSITION1_HPP

/*
 * @description: Evandro's C++ Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent 1 dimensional position.
	 * @note: 'Position1Type' must be numeric.
	 */
	template<class Position1Type>
	class Position1{
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'x' value.
			 * @return: None.
			 */
			Position1(Position1Type x = 0);

			/*
			 * @description: Default destructor.
			 * @return: None.
			 */
			~Position1();

		public:
			Position1Type x;
	};

	typedef Position1<int> Position1i;
}

template<class Position1Type>
EToolkit::Position1<Position1Type>::Position1(Position1Type x) :
	x(x){

}

template<class Position1Type>
EToolkit::Position1<Position1Type>::~Position1(){

}

#endif /* EPOSITION1_HPP */
