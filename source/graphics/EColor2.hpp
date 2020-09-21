#ifndef ECOLOR2_HPP
#define ECOLOR2_HPP

#include <EColor>

/*
 * @description: Evandro's C++ Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent color with 2 channels.
	 * @note: 'Color2Type' must be numeric integer.
	 */
	template<class Color2Type>
	class Color2 : public Color1<Color2Type>{
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'gray' and 'alpha' values.
			 */
			Color2(Color2Type gray = 0, Color2Type alpha = 0);

			/*
			 * @description: Default destructor.
			 */
			~Color2();

		public:
			Color2Type alpha;
	};
}

template<class Color2Type>
EToolkit::Color2<Color2Type>::Color2(Color2Type gray, Color2Type alpha) :
	Color1<Color2Type>(gray), alpha(alpha){

}

template<class Color2Type>
EToolkit::Color2<Color2Type>::~Color2(){

}

#endif /* ECOLOR2_HPP */
