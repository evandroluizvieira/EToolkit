#ifndef ECOLOR4_HPP
#define ECOLOR4_HPP

#include <EColor>

/*
 * @description: Evandro's C++ Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent color with 4 channels.
	 * @note: 'Color4Type' must be numeric integer.
	 */
	template<class Color4Type>
	class Color4 : public Color3<Color4Type>{
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'red', 'green', 'blue' and 'alpha' values.
			 */
			Color4(Color4Type red = 0, Color4Type green = 0, Color4Type blue = 0, Color4Type alpha = 0);

			/*
			 * @description: Default destructor.
			 */
			~Color4();

		public:
			Color4Type alpha;
	};
}

template<class Color4Type>
EToolkit::Color4<Color4Type>::Color4(Color4Type red, Color4Type green, Color4Type blue, Color4Type alpha) :
	Color3<Color4Type>(red, green, blue), alpha(alpha){

}

template<class Color4Type>
EToolkit::Color4<Color4Type>::~Color4(){

}

#endif /* ECOLOR4_HPP */
