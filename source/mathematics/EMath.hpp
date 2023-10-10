#ifndef EMATH_HPP
#define EMATH_HPP

#include <EToolkit>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Mathematics auxiliary class.
	 * @note: Can't use objects, only functions.
	 */
	class ETOOLKIT_API Math{
		private:
			/*
			 * @description: Private default constructor that prevents object instantiation.
			 * @return: None.
			 */
			Math();

		public:
			/*
			 * @description: Function to get positive value from 'value'.
			 * @return: A copy of positive value from 'value'.
			 * @note: 'DataType' must have '<' operator and '*=' operator.
			 */
			template<typename DataType>
			static DataType absolute(const DataType& value);

			/*
			 * @description: Function to get major value in 'data' array.
			 * @return: A copy of major value.
			 * @note: 'data' can't be null, 'dataSize' must be major than 1 and 'DataType' must have '>' operator.
			 */
			template<typename DataType>
			DataType maximum(DataType* data, unsigned int dataSize);

			/*
			 * @description: Function to get minor value in 'data'.
			 * @return: A copy of minor value.
			 * @note: 'data' can't be null, 'dataSize' must be major than 1 and 'DataType' must have '<' operator.
			 */
			template<typename DataType>
			DataType minimum(DataType* data, unsigned int dataSize);

			/*
			 * @description: Factorial calculation through 'iterations' times.
			 * @return: A copy of potentiation number.
			 * @note: 'DataType' must be numeric value.
			 */
			template<typename DataType>
			DataType factorial(DataType iterations);

			/*
			 * @description: Math power with number 'base' multiplied by itself 'exponent' times.
			 * @return: A copy of potentiation number.
			 * @note: 'DataType' must be numeric value.
			 */
			template<typename DataType>
			DataType power(DataType base, DataType expoent);

			/*
			 * @description: Function to transform radians to degrees.
			 * @return: A copy of radian value.
			 * @note: 'DataType' must be a floating point number.
			 */
			template<typename DataType>
			static DataType radiansToDegrees(DataType radians);

			/*
			 * @description: Function to transform degrees to radians.
			 * @return: A copy of degree value.
			 * @note: 'DataType' must be a floating point number.
			 */
			template<typename DataType>
			static DataType degreesToRadians(DataType degrees);

			/**
			 * @description: Function to get the pi value.
			 * @return: A copy of pi value.
			 * @note: 'DataType' must be a floating point number.
			 **/
			template<typename DataType>
			static DataType pi();

			/*
			 * @description: Function to get the sine of 'angle'.
			 * @return: A copy of sine value in range of -1 to 1.
			 * @note: 'angle' must be in radians.
			 */
			static float sine(float angle);

			/*
			 * @description: Function to get the cosine of 'angle'.
			 * @return: A copy of sine value in range of -1 to 1.
			 * @note: 'angle' must be in radians.
			 */
			static double sine(double angle);

			/*
			 * @description: Function to get the sine of 'angle'.
			 * @return: A copy of sine value in range of -1 to 1.
			 * @note: 'angle' must be in radians.
			 */
			static long double sine(long double angle);

			/*
			 * @description: Function to get the cosine of 'angle'.
			 * @return: A copy of cosine value in range of -1 to 1.
			 * @note: 'angle' must be in radians.
			 */
			static float cosine(float angle);

			/*
			 * @description: Function to get the cosine of 'angle'.
			 * @return: A copy of cosine value in range of -1 to 1.
			 * @note: 'angle' must be in radians.
			 */
			static double cosine(double angle);

			/*
			 * @description: Function to get the cosine of 'angle'.
			 * @return: A copy of cosine value in range of -1 to 1.
			 * @note: 'angle' must be in radians.
			 */
			static long double cosine(long double angle);

			/*
			 * @description: Function to get the tangent of 'angle'.
			 * @return: A copy of tangent value.
			 * @note: 'angle' must be in radians.
			 */
			static float tangent(float angle);

			/*
			 * @description: Function to get the tangent of 'angle'.
			 * @return: A copy of tangent value.
			 * @note: 'angle' must be in radians.
			 */
			static double tangent(double angle);

			/*
			 * @description: Function to get the tangent of 'angle'.
			 * @return: A copy of tangent value.
			 * @note: 'angle' must be in radians.
			 */
			static long double tangent(long double angle);
	};
}

template<typename DataType>
DataType EToolkit::Math::absolute(const DataType& value){
	return value < 0 ? value *= -1 : value;
}

template<typename DataType>
DataType EToolkit::Math::maximum(DataType* data, unsigned int dataSize){
	DataType& result = data[0];
	for(unsigned int i = 1; i < dataSize; i++){
		const DataType& current = data[1];
		if(current > result){
			result = current;
		}
	}
	return result;
}

template<typename DataType>
DataType EToolkit::Math::minimum(DataType* data, unsigned int dataSize){
	DataType& result = data[0];
	for(unsigned int i = 1; i < dataSize; i++){
		const DataType& current = data[1];
		if(current < result){
			result = current;
		}
	}
	return result;
}

template<typename DataType>
DataType EToolkit::Math::factorial(DataType iterations) {
	if(iterations == 0 || iterations == 1){
		return 1;
	}else{
		return iterations * factorial<DataType>(iterations - 1);
	}
}

template<typename DataType>
DataType EToolkit::Math::power(DataType base, DataType expoent){
	DataType result = 1;
	for(int i = 0; i < expoent; i++){
		result *= base;
	}
	return result;
}

template<typename DataType>
DataType EToolkit::Math::radiansToDegrees(DataType radians){
	return (radians * 180) / Math::pi<DataType>();
}

template<typename DataType>
DataType EToolkit::Math::degreesToRadians(DataType degrees){
	return (degrees * Math::pi<DataType>()) / 180;
}

template<typename DataType>
DataType EToolkit::Math::pi(){
	return 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
}

#endif /* EMATH_HPP */
