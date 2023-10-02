#ifndef EARCHITECTURE_HPP
#define EARCHITECTURE_HPP

#ifdef _MSC_VER
	#ifndef EMS
		#define EMS 1
	#endif

	//MSC (Microsoft C) compiler
	#ifndef __cplusplus
		#ifndef EMSC
			#define EMSC 1
		#endif
	#endif

	//MSVC (Microsoft Visual C/C++) compiler
	#ifndef EMSVC
		#define EMSVC 1
	#endif
#endif

#ifdef __GNUC__
	#ifndef EGNU
		#define EGNU 1
	#endif

	//GCC (GNU Compiler Collection) for C
	#ifndef EGNUC
		#define EGNUC 1
	#endif

	//GCC (GNU Compiler Collection) for C++
	#ifdef __cplusplus
		#ifndef EGNUCPP
			#define EGNUCPP 1
		#endif
	#endif
#endif

//CMake C compiler
#ifdef CMAKE_COMPILER_IS_GNUC
	#ifndef ECMAKEGNUC
		#define ECMAKEGNUC 1
	#endif
#endif

//CMake C++ compiler
#ifdef CMAKE_COMPILER_IS_GNUCXX
	#ifndef ECMAKEGNUCPP
		#define ECMAKEGNUCPP 1
	#endif
#endif

//Oracle Solaris Studio (formerly Sun Studio) for C
#ifdef __SUNPRO_C
	#ifndef ESUNC
		#define ESUNC 1
	#endif
#endif

//Oracle Solaris Studio (formerly Sun Studio) for C++
#ifdef __SUNPRO_CC
	#ifndef ESUNCPP
		#define ESUNCPP 1
	#endif
#endif

//HP-UX C Compiler (HP C/aC++)
#if __HP_cc || __HP_aCC
	#ifndef EHPUX
		#define EHPUX 1
	#endif

	#ifdef __HP_cc
		#ifndef EHPUXC
			#define EHPUXC 1
		#endif
	#endif

	//HP-UX C++ Compiler (HP aCC)
	#ifdef __HP_aCC
		#ifndef EHPUXCPP
			#define EHPUXCPP 1
		#endif
	#endif
#endif

//MinGW for C and C++
#if __MINGW64__ || __MINGW32__
	#ifndef EMINGW
		#define EMINGW 1
	#endif
#endif

//Clang (LLVM-based compiler) for C and C++
#ifdef __clang__
	#ifndef ECLANG
		#define ECLANG 1
	#endif
#endif

//Pelles C Compiler for C and C++
#ifdef __POCC__
	#ifndef EPELLES
		#define EPELLES 1
	#endif
#endif

//Cygwin for C and C++
#ifdef __CYGWIN_
	#ifndef ECYGWIN
		#define ECYGWIN 1
	#endif
#endif

//Intel C and C++ Compiler
#ifdef __INTEL_COMPILER
	#ifndef EINTEL
		#define EINTEL 1
	#endif
#endif

//IBM XL C/C++ Compiler
#ifdef __ibmxl__
	#ifndef EIBMXL
		#define EIBMXL 1
	#endif
#endif


/*
 * @description: Macro that defines bit architecture.
 * @note: Can be 32-bit or 64-bit.
 */
#ifndef EBITARCHITECTURE
#define EBITARCHITECTURE 0
#endif

#if EMINGW && __MINGW64__
	#define EBITARCHITECTURE 64
#elif EMINGW && __MINGW32__
	#define EBITARCHITECTURE 32
#elif EMS
	#ifdef _WIN64
		#define EBITARCHITECTURE 64
	#else
		#define EBITARCHITECTURE 32
	#endif
#elif EHPUX
	#ifdef __LP64__
		#define EBITARCHITECTURE 64
	#else
		#define EBITARCHITECTURE 32
	#endif
#elif EIBMXL
	#ifdef __64BIT__
		#define EBITARCHITECTURE 64
	#else
		#define EBITARCHITECTURE 32
	#endif
#else
	//is a preprocessor macro that is typically defined by compilers when targeting 64-bit x86 (Intel/AMD) architectures.
	#ifdef __x86_64__
		#define EBITARCHITECTURE 64
	#endif

	//is a preprocessor macro that is typically defined by compilers when targeting 32-bit x86 (Intel) architecture.
	#ifdef __i386__
		#define EBITARCHITECTURE 32
	#endif
#endif

#endif /* EARCHITECTURE_HPP */
