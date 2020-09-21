#ifndef ECOLOR3_HPP
#define ECOLOR3_HPP

/*
 * @description: Evandro's C++ Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent color with 3 channels.
	 * @note: 'Color3Type' must be numeric integer.
	 */
	template<class Color3Type>
	class Color3{
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'red', 'green' and 'blue' values.
			 */
			Color3(Color3Type red = 0, Color3Type green = 0, Color3Type blue = 0);

			/*
			 * @description: Default destructor.
			 */
			~Color3();

		public:
			Color3Type red;
			Color3Type green;
			Color3Type blue;
	};
}

template<class Color3Type>
EToolkit::Color3<Color3Type>::Color3(Color3Type red, Color3Type green, Color3Type blue) :
	red(red), green(green), blue(blue){

}

template<class Color3Type>
EToolkit::Color3<Color3Type>::~Color3(){

}

#endif /* ECOLOR3_HPP */
