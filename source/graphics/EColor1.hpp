#ifndef ECOLOR1_HPP
#define ECOLOR1_HPP

/*
 * @description: Evandro's C++ Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent color with 1 channel.
	 * @note: 'Color1Type' must be numeric integer.
	 */
	template<class Color1Type>
	class Color1{
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'gray' value.
			 */
			Color1(Color1Type gray = 0);

			/*
			 * @description: Default destructor.
			 */
			~Color1();

		public:
			Color1Type gray;
	};
}

template<class Color1Type>
EToolkit::Color1<Color1Type>::Color1(Color1Type gray) :
	gray(gray){
}

template<class Color1Type>
EToolkit::Color1<Color1Type>::~Color1(){

}

#endif /* ECOLOR1_HPP */
