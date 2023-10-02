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
			static const Color3uc White();

			/*
			 * @description: Function to get an black color object.
			 * @return: A copy of black object.
			 */
			static const Color3uc Black();

			/*
			 * @description: Function to get an light gray color object.
			 * @return: A copy of light gray object.
			 */
			static const Color3uc LightGray();

			/*
			 * @description: Function to get an gray color object.
			 * @return: A copy of gray object.
			 */
			static const Color3uc Gray();

			/*
			 * @description: Function to get an dark gray color object.
			 * @return: A copy of dark gray object.
			 */
			static const Color3uc DarkGray();

			/*
			 * @description: Function to get an red color object.
			 * @return: A copy of red object.
			 */
			static const Color3uc Red();

			/*
			 * @description: Function to get an light maroon object.
			 * @return: A copy of maroon object.
			 */
			static const Color3uc Maroon();

			/*
			 * @description: Function to get an blue color object.
			 * @return: A copy of blue object.
			 */
			static const Color3uc Blue();

			/*
			 * @description: Function to get an navy color object.
			 * @return: A copy of navy object.
			 */
			static const Color3uc Navy();

			/*
			 * @description: Function to get an yellow color object.
			 * @return: A copy of yellow object.
			 */
			static const Color3uc Yellow();

			/*
			 * @description: Function to get an olive color object.
			 * @return: A copy of olive object.
			 */
			static const Color3uc Olive();

			/*
			 * @description: Function to get an lime color object.
			 * @return: A copy of lime object.
			 */
			static const Color3uc Lime();

			/*
			 * @description: Function to get an green color object.
			 * @return: A copy of green object.
			 */
			static const Color3uc Green();

			/*
			 * @description: Function to get an cyan color object.
			 * @return: A copy of cyan object.
			 */
			static const Color3uc Cyan();

			/*
			 * @description: Function to get an teal color object.
			 * @return: A copy of teal object.
			 */
			static const Color3uc Teal();

			/*
			 * @description: Function to get an fuchsia color object.
			 * @return: A copy of fuchsia object.
			 */
			static const Color3uc Fuchsia();

			/*
			 * @description: Function to get an purple color object.
			 * @return: A copy of purple object.
			 */
			static const Color3uc Purple();
	};

	/*
	 * @description: Color class, used to store red, green and blue channel information in a 'float', that has values in range of 0 to 1 in each channel.
	 */
	class Color3f : public Color3<float>{
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
			static const Color3f White();

			/*
			 * @description: Function to get an black color object.
			 * @return: A copy of black object.
			 */
			static const Color3f Black();

			/*
			 * @description: Function to get an light gray color object.
			 * @return: A copy of light gray object.
			 */
			static const Color3f LightGray();

			/*
			 * @description: Function to get an gray color object.
			 * @return: A copy of gray object.
			 */
			static const Color3f Gray();

			/*
			 * @description: Function to get an dark gray color object.
			 * @return: A copy of dark gray object.
			 */
			static const Color3f DarkGray();

			/*
			 * @description: Function to get an red color object.
			 * @return: A copy of red object.
			 */
			static const Color3f Red();

			/*
			 * @description: Function to get an light maroon object.
			 * @return: A copy of maroon object.
			 */
			static const Color3f Maroon();

			/*
			 * @description: Function to get an blue color object.
			 * @return: A copy of blue object.
			 */
			static const Color3f Blue();

			/*
			 * @description: Function to get an navy color object.
			 * @return: A copy of navy object.
			 */
			static const Color3f Navy();

			/*
			 * @description: Function to get an yellow color object.
			 * @return: A copy of yellow object.
			 */
			static const Color3f Yellow();

			/*
			 * @description: Function to get an olive color object.
			 * @return: A copy of olive object.
			 */
			static const Color3f Olive();

			/*
			 * @description: Function to get an lime color object.
			 * @return: A copy of lime object.
			 */
			static const Color3f Lime();

			/*
			 * @description: Function to get an green color object.
			 * @return: A copy of green object.
			 */
			static const Color3f Green();

			/*
			 * @description: Function to get an cyan color object.
			 * @return: A copy of cyan object.
			 */
			static const Color3f Cyan();

			/*
			 * @description: Function to get an teal color object.
			 * @return: A copy of teal object.
			 */
			static const Color3f Teal();

			/*
			 * @description: Function to get an fuchsia color object.
			 * @return: A copy of fuchsia object.
			 */
			static const Color3f Fuchsia();

			/*
			 * @description: Function to get an purple color object.
			 * @return: A copy of purple object.
			 */
			static const Color3f Purple();
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

const EToolkit::Color3uc EToolkit::Color3uc::White(){
	return Color3uc(255, 255, 255);
}

const EToolkit::Color3uc EToolkit::Color3uc::Black(){
	return Color3uc(0, 0, 0);
}

const EToolkit::Color3uc EToolkit::Color3uc::LightGray(){
	return Color3uc(191, 191, 191);
}

const EToolkit::Color3uc EToolkit::Color3uc::Gray(){
	return Color3uc(127, 127, 127);
}

const EToolkit::Color3uc EToolkit::Color3uc::DarkGray(){
	return Color3uc(63, 63, 63);
}

const EToolkit::Color3uc EToolkit::Color3uc::Red(){
		return Color3uc(255, 0, 0);
}

const EToolkit::Color3uc EToolkit::Color3uc::Maroon(){
	return Color3uc(127, 0, 0);
}

const EToolkit::Color3uc EToolkit::Color3uc::Blue(){
	return Color3uc(0, 0, 255);
}

const EToolkit::Color3uc EToolkit::Color3uc::Navy(){
	return Color3uc(0, 0, 127);
}

const EToolkit::Color3uc EToolkit::Color3uc::Yellow(){
	return Color3uc(255, 255, 0);
}

const EToolkit::Color3uc EToolkit::Color3uc::Olive(){
	return Color3uc(127, 127, 0);
}

const EToolkit::Color3uc EToolkit::Color3uc::Lime(){
	return Color3uc(0, 255, 0);
}

const EToolkit::Color3uc EToolkit::Color3uc::Green(){
	return Color3uc(0, 127, 0);
}

const EToolkit::Color3uc EToolkit::Color3uc::Cyan(){
	return Color3uc(0, 255, 255);
}

const EToolkit::Color3uc EToolkit::Color3uc::Teal(){
	return Color3uc(0, 127, 127);
}

const EToolkit::Color3uc EToolkit::Color3uc::Fuchsia(){
	return Color3uc(255, 0, 255);
}

const EToolkit::Color3uc EToolkit::Color3uc::Purple(){
	return Color3uc(127, 0, 127);
}


EToolkit::Color3f::Color3f(float red, float green, float blue) :
	EToolkit::Color3<float>(red, green, blue){

}

EToolkit::Color3f::~Color3f(){

}

const EToolkit::Color3f EToolkit::Color3f::White(){
	return Color3f(1.0f, 1.0f, 1.0f);
}

const EToolkit::Color3f EToolkit::Color3f::Black(){
	return Color3f(0.0f, 0.0f, 0.0f);
}

const EToolkit::Color3f EToolkit::Color3f::LightGray(){
	return Color3f(0.75f, 0.75f, 0.75f);
}

const EToolkit::Color3f EToolkit::Color3f::Gray(){
	return Color3f(0.5f, 0.5f, 0.5f);
}

const EToolkit::Color3f EToolkit::Color3f::DarkGray(){
	return Color3f(0.25f, 0.25f, 0.25f);
}

const EToolkit::Color3f EToolkit::Color3f::Red(){
	return Color3f(1.0f, 0.0f, 0.0f);
}

const EToolkit::Color3f EToolkit::Color3f::Maroon(){
	return Color3f(0.5f, 0.0f, 0.0f);
}

const EToolkit::Color3f EToolkit::Color3f::Blue(){
	return Color3f(0.0f, 0.0f, 1.0f);
}

const EToolkit::Color3f EToolkit::Color3f::Navy(){
	return Color3f(0.0f, 0.0f, 0.5f);
}

const EToolkit::Color3f EToolkit::Color3f::Yellow(){
	return Color3f(1.0f, 1.0f, 0.0f);
}

const EToolkit::Color3f EToolkit::Color3f::Olive(){
	return Color3f(0.5f, 0.5f, 0.0f);
}

const EToolkit::Color3f EToolkit::Color3f::Lime(){
	return Color3f(0.0f, 1.0f, 0.0f);
}

const EToolkit::Color3f EToolkit::Color3f::Green(){
	return Color3f(0.0f, 0.5f, 0.0f);
}

const EToolkit::Color3f EToolkit::Color3f::Cyan(){
	return Color3f(0.0f, 1.0f, 1.0f);
}

const EToolkit::Color3f EToolkit::Color3f::Teal(){
	return Color3f(0.0f, 0.5f, 0.5f);
}

const EToolkit::Color3f EToolkit::Color3f::Fuchsia(){
	return Color3f(1.0f, 0.0f, 1.0f);
}

const EToolkit::Color3f EToolkit::Color3f::Purple(){
	return Color3f(0.5f, 0.0f, 0.5f);
}

#endif /* ECOLOR3_HPP */
