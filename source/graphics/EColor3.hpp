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
			 * @return: None.
			 */
			Color3(Color3Type red = 0, Color3Type green = 0, Color3Type blue = 0);

			/*
			 * @description: Default destructor.
			 * @return: None.
			 */
			~Color3();

		public:
			Color3Type red;
			Color3Type green;
			Color3Type blue;
	};

	/*
	 * @description: Color class, used to store red, green and blue channel information in a 'unsigned char', that has 256 possibles values for each channel.
	 */
	class Color3uc : public Color3<unsigned char>{
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'red', 'green' and 'blue' values.
			 * @return: None.
			 */
			Color3uc(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0);

			/*
			 * @description: Default destructor.
			 * @return: None.
			 */
			~Color3uc();

		public:
			/*
			 * @description: Function to get an white color object.
			 * @return: A copy of white object.
			 */
			static const Color3uc white();

			/*
			 * @description: Function to get an black color object.
			 * @return: A copy of black object.
			 */
			static const Color3uc black();

			/*
			 * @description: Function to get an light gray color object.
			 * @return: A copy of light gray object.
			 */
			static const Color3uc lightGray();

			/*
			 * @description: Function to get an gray color object.
			 * @return: A copy of gray object.
			 */
			static const Color3uc gray();

			/*
			 * @description: Function to get an dark gray color object.
			 * @return: A copy of dark gray object.
			 */
			static const Color3uc darkGray();

			/*
			 * @description: Function to get an red color object.
			 * @return: A copy of red object.
			 */
			static const Color3uc red();

			/*
			 * @description: Function to get an light maroon object.
			 * @return: A copy of maroon object.
			 */
			static const Color3uc maroon();

			/*
			 * @description: Function to get an blue color object.
			 * @return: A copy of blue object.
			 */
			static const Color3uc blue();

			/*
			 * @description: Function to get an navy color object.
			 * @return: A copy of navy object.
			 */
			static const Color3uc navy();

			/*
			 * @description: Function to get an yellow color object.
			 * @return: A copy of yellow object.
			 */
			static const Color3uc yellow();

			/*
			 * @description: Function to get an olive color object.
			 * @return: A copy of olive object.
			 */
			static const Color3uc olive();

			/*
			 * @description: Function to get an lime color object.
			 * @return: A copy of lime object.
			 */
			static const Color3uc lime();

			/*
			 * @description: Function to get an green color object.
			 * @return: A copy of green object.
			 */
			static const Color3uc green();

			/*
			 * @description: Function to get an cyan color object.
			 * @return: A copy of cyan object.
			 */
			static const Color3uc cyan();

			/*
			 * @description: Function to get an teal color object.
			 * @return: A copy of teal object.
			 */
			static const Color3uc teal();

			/*
			 * @description: Function to get an fuchsia color object.
			 * @return: A copy of fuchsia object.
			 */
			static const Color3uc fuchsia();

			/*
			 * @description: Function to get an purple color object.
			 * @return: A copy of purple object.
			 */
			static const Color3uc purple();
	};

	/*
	 * @description: Color class, used to store red, green and blue channel information in a 'float', that has values in range of 0 to 1 in each channel.
	 */
	class Color3f : public Color3<float> {
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'red', 'green' and 'blue' values.
			 * @return: None.
			 */
			Color3f(float red = 0.0f, float green = 0.0f, float blue = 0.0f);

			/*
			 * @description: Default destructor.
			 * @return: None.
			 */
			~Color3f();

		public:
			/*
			 * @description: Function to get an white color object.
			 * @return: A copy of white object.
			 */
			static const Color3f white();

			/*
			 * @description: Function to get an black color object.
			 * @return: A copy of black object.
			 */
			static const Color3f black();

			/*
			 * @description: Function to get an light gray color object.
			 * @return: A copy of light gray object.
			 */
			static const Color3f lightGray();

			/*
			 * @description: Function to get an gray color object.
			 * @return: A copy of gray object.
			 */
			static const Color3f gray();

			/*
			 * @description: Function to get an dark gray color object.
			 * @return: A copy of dark gray object.
			 */
			static const Color3f darkGray();

			/*
			 * @description: Function to get an red color object.
			 * @return: A copy of red object.
			 */
			static const Color3f red();

			/*
			 * @description: Function to get an light maroon object.
			 * @return: A copy of maroon object.
			 */
			static const Color3f maroon();

			/*
			 * @description: Function to get an blue color object.
			 * @return: A copy of blue object.
			 */
			static const Color3f blue();

			/*
			 * @description: Function to get an navy color object.
			 * @return: A copy of navy object.
			 */
			static const Color3f navy();

			/*
			 * @description: Function to get an yellow color object.
			 * @return: A copy of yellow object.
			 */
			static const Color3f yellow();

			/*
			 * @description: Function to get an olive color object.
			 * @return: A copy of olive object.
			 */
			static const Color3f olive();

			/*
			 * @description: Function to get an lime color object.
			 * @return: A copy of lime object.
			 */
			static const Color3f lime();

			/*
			 * @description: Function to get an green color object.
			 * @return: A copy of green object.
			 */
			static const Color3f green();

			/*
			 * @description: Function to get an cyan color object.
			 * @return: A copy of cyan object.
			 */
			static const Color3f cyan();

			/*
			 * @description: Function to get an teal color object.
			 * @return: A copy of teal object.
			 */
			static const Color3f teal();

			/*
			 * @description: Function to get an fuchsia color object.
			 * @return: A copy of fuchsia object.
			 */
			static const Color3f fuchsia();

			/*
			 * @description: Function to get an purple color object.
			 * @return: A copy of purple object.
			 */
			static const Color3f purple();
	};
}

template<class Color3Type>
EToolkit::Color3<Color3Type>::Color3(Color3Type red, Color3Type green, Color3Type blue) :
	red(red), green(green), blue(blue){

}

template<class Color3Type>
EToolkit::Color3<Color3Type>::~Color3(){

}

EToolkit::Color3uc::Color3uc(unsigned char red, unsigned char green, unsigned char blue) :
	EToolkit::Color3<unsigned char>(red, green, blue){

}

EToolkit::Color3uc::~Color3uc(){

}

const EToolkit::Color3uc EToolkit::Color3uc::white(){
	return Color3uc(255, 255, 255);
}

const EToolkit::Color3uc EToolkit::Color3uc::black(){
	return Color3uc(0, 0, 0);
}

const EToolkit::Color3uc EToolkit::Color3uc::lightGray(){
	return Color3uc(191, 191, 191);
}

const EToolkit::Color3uc EToolkit::Color3uc::gray(){
	return Color3uc(127, 127, 127);
}

const EToolkit::Color3uc EToolkit::Color3uc::darkGray(){
	return Color3uc(63, 63, 63);
}

const EToolkit::Color3uc EToolkit::Color3uc::red(){
		return Color3uc(255, 0, 0);
}

const EToolkit::Color3uc EToolkit::Color3uc::maroon(){
	return Color3uc(127, 0, 0);
}

const EToolkit::Color3uc EToolkit::Color3uc::blue(){
	return Color3uc(0, 0, 255);
}

const EToolkit::Color3uc EToolkit::Color3uc::navy(){
	return Color3uc(0, 0, 127);
}

const EToolkit::Color3uc EToolkit::Color3uc::yellow(){
	return Color3uc(255, 255, 0);
}

const EToolkit::Color3uc EToolkit::Color3uc::olive(){
	return Color3uc(127, 127, 0);
}

const EToolkit::Color3uc EToolkit::Color3uc::lime(){
	return Color3uc(0, 255, 0);
}

const EToolkit::Color3uc EToolkit::Color3uc::green(){
	return Color3uc(0, 127, 0);
}

const EToolkit::Color3uc EToolkit::Color3uc::cyan(){
	return Color3uc(0, 255, 255);
}

const EToolkit::Color3uc EToolkit::Color3uc::teal(){
	return Color3uc(0, 127, 127);
}

const EToolkit::Color3uc EToolkit::Color3uc::fuchsia(){
	return Color3uc(255, 0, 255);
}

const EToolkit::Color3uc EToolkit::Color3uc::purple(){
	return Color3uc(127, 0, 127);
}


EToolkit::Color3f::Color3f(float red, float green, float blue) :
	EToolkit::Color3<float>(red, green, blue){

}

EToolkit::Color3f::~Color3f(){

}

const EToolkit::Color3f EToolkit::Color3f::white(){
	return Color3f(1.0f, 1.0f, 1.0f);
}

const EToolkit::Color3f EToolkit::Color3f::black(){
	return Color3f(0.0f, 0.0f, 0.0f);
}

const EToolkit::Color3f EToolkit::Color3f::lightGray(){
	return Color3f(0.75f, 0.75f, 0.75f);
}

const EToolkit::Color3f EToolkit::Color3f::gray(){
	return Color3f(0.5f, 0.5f, 0.5f);
}

const EToolkit::Color3f EToolkit::Color3f::darkGray(){
	return Color3f(0.25f, 0.25f, 0.25f);
}

const EToolkit::Color3f EToolkit::Color3f::red(){
	return Color3f(1.0f, 0.0f, 0.0f);
}

const EToolkit::Color3f EToolkit::Color3f::maroon(){
	return Color3f(0.5f, 0.0f, 0.0f);
}

const EToolkit::Color3f EToolkit::Color3f::blue(){
	return Color3f(0.0f, 0.0f, 1.0f);
}

const EToolkit::Color3f EToolkit::Color3f::navy(){
	return Color3f(0.0f, 0.0f, 0.5f);
}

const EToolkit::Color3f EToolkit::Color3f::yellow(){
	return Color3f(1.0f, 1.0f, 0.0f);
}

const EToolkit::Color3f EToolkit::Color3f::olive(){
	return Color3f(0.5f, 0.5f, 0.0f);
}

const EToolkit::Color3f EToolkit::Color3f::lime(){
	return Color3f(0.0f, 1.0f, 0.0f);
}

const EToolkit::Color3f EToolkit::Color3f::green(){
	return Color3f(0.0f, 0.5f, 0.0f);
}

const EToolkit::Color3f EToolkit::Color3f::cyan(){
	return Color3f(0.0f, 1.0f, 1.0f);
}

const EToolkit::Color3f EToolkit::Color3f::teal(){
	return Color3f(0.0f, 0.5f, 0.5f);
}

const EToolkit::Color3f EToolkit::Color3f::fuchsia(){
	return Color3f(1.0f, 0.0f, 1.0f);
}

const EToolkit::Color3f EToolkit::Color3f::purple(){
	return Color3f(0.5f, 0.0f, 0.5f);
}

#endif /* ECOLOR3_HPP */
