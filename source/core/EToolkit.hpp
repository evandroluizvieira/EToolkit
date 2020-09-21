#ifndef ETOOLKIT_HPP
#define ETOOLKIT_HPP

#ifdef ETOOLKIT_EXPORT
	#define ETOOLKIT_API __declspec(dllexport)
#else
	#define ETOOLKIT_API __declspec(dllimport)
#endif

#endif /* ETOOLKIT_HPP */
