#ifndef ETOOLKIT_HPP
#define ETOOLKIT_HPP

#ifdef ETOOLKIT_STATIC_LIBRARY
	#define ETOOLKIT_API
#else
	#ifdef ETOOLKIT_SHARED_LIBRARY
	#define ETOOLKIT_API __declspec(dllexport)
	#else
	#define ETOOLKIT_API __declspec(dllimport)
	#endif
#endif

#endif /* ETOOLKIT_HPP */
