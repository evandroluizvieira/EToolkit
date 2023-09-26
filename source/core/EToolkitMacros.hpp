#ifndef ETOOLKITMACROS_HPP
#define ETOOLKITMACROS_HPP

#include <EMacros>

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


#endif /* ETOOLKITMACROS_HPP */
