#ifndef ETOOLKITTYPES_HPP
#define ETOOLKITTYPES_HPP

#include "EMacrosArchitecture.hpp"

#if EBITARCHITECTURE == 64
    typedef char int8;
    typedef short int int16;
    typedef int int32;
    typedef long long int int64;

    typedef unsigned char uint8;
    typedef unsigned short int uint16;
    typedef unsigned int uint32;
    typedef unsigned long long int uint64;
#else
    typedef char int8;
    typedef short int int16;
    typedef long int int32;
    typedef long long int int64;

    typedef unsigned char uint8;
    typedef unsigned short int uint16;
    typedef unsigned long int uint32;
    typedef unsigned long long int uint64;
#endif

#endif /* ETOOLKITTYPES_HPP */
