#ifndef EMACROSTOOLKIT_HPP
#define EMACROSTOOLKIT_HPP

//For further use.
//#define EPUBLIC public:
//#define EPROTECTED protected:
//#define EPRIVATE private:

/*
 * @description: Macro that includes a function to get the string name of the class.
 * @note: Used inside a public scope of the class header.
 */
#define ETOOLKIT_OBJECT_NAME(ClassName)			\
	static const char* const getClassName(){	\
		return EMakeString(ClassName);			\
	}

/*
 * @description: Macro that includes a function to get the bits size the class.
 * @note: Used inside a public scope of the class header.
 */
#define ETOOLKIT_OBJECT_SIZE(ClassName)			\
	static const unsigned int getClassSize(){	\
		return sizeof(ClassName);				\
	}

/*
 * @description: Macro that includes a function to get the string name and the bits size of the class.
 * @note: Used inside a public scope of the class header.
 */
#define ETOOLKIT_OBJECT(ClassName)	\
	ETOOLKIT_OBJECT_NAME(ClassName)	\
	ETOOLKIT_OBJECT_SIZE(ClassName)

/*
 * @description: Numeric limit of maximum unsigned 8 bit value.
 */
#define ELIMIT_UNSIGNED_MAXIMUM_8_BITS 255

/*
 * @description: Numeric limit of maximum unsigned 16 bit value.
 */
#define ELIMIT_UNSIGNED_MAXIMUM_16_BITS 65535

/*
 * @description: Numeric limit of maximum unsigned 32 bit value.
 */
#define ELIMIT_UNSIGNED_MAXIMUM_32_BITS 4294967295

/*
 * @description: Numeric limit of maximum unsigned 64 bit value.
 */
#define ELIMIT_UNSIGNED_MAXIMUM_64_BITS 18446744073709551615

/*
 * @description: Numeric limit of maximum signed 8 bits value.
 */
#define ELIMIT_SIGNED_MAXIMUM_8_BITS 127

/*
 * @description: Numeric limit of maximum signed 16 bits value.
 */
#define ELIMIT_SIGNED_MAXIMUM_16_BITS 32767

/*
 * @description: Numeric limit of maximum signed 32 bits value.
 */
#define ELIMIT_SIGNED_MAXIMUM_32_BITS 2147483647

/*
 * @description: Numeric limit of maximum signed 64 bits value.
 */
#define ELIMIT_SIGNED_MAXIMUM_64_BITS 9223372036854775807

/*
 * @description: Numeric limit of minimum signed 8 bits value.
 */
#define ELIMIT_SIGNED_MINIMUM_8_BITS (-LIMIT_SIGNED_MAXIMUM_8_BITS - 1)

/*
 * @description: Numeric limit of minimum signed 16 bits value.
 */
#define ELIMIT_SIGNED_MINIMUM_16_BITS (-LIMIT_SIGNED_MAXIMUM_16_BITS - 1)

/*
 * @description: Numeric limit of minimum signed 32 bits value.
 */
#define ELIMIT_SIGNED_MINIMUM_32_BITS (-LIMIT_SIGNED_MAXIMUM_32_BITS - 1)

/*
 * @description: Numeric limit of minimum signed 64 bits value.
 */
#define ELIMIT_SIGNED_MINIMUM_64_BITS (-LIMIT_SIGNED_MAXIMUM_64_BITS - 1)

/*
 * @description: Value of pi.
 * @note With 100 decimal places.
 */
#define EMATH_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

#endif /* EMACROSTOOLKIT_HPP */
