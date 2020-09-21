#ifndef ETOOLKITMACROS_HPP
#define ETOOLKITMACROS_HPP

#include <EMacros>

//ADD COMMENT
#define ETOOLKIT_OBJECT_NAME(ClassName)			\
	static const char* const getClassName(){	\
		return EMakeString(ClassName);			\
	}

//ADD COMMENT
#define ETOOLKIT_OBJECT_SIZE(ClassName)			\
	static const unsigned int getClassSize(){	\
		return sizeof(ClassName);				\
	}

//ADD COMMENT
#define ETOOLKIT_OBJECT(ClassName)	\
	ETOOLKIT_OBJECT_NAME(ClassName)	\
	ETOOLKIT_OBJECT_SIZE(ClassName)


#endif /* ETOOLKITMACROS_HPP */
