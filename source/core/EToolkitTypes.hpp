/**
 * @file EToolkitTypes.hpp
 * @brief Contains platform-independent type definitions with compile-time size guarantees
 *
 * This header defines fixed-size integer types that guarantee exact byte sizes across
 * different platforms and architectures. All types are verified at compile-time using
 * static assertions to ensure portability and consistency.
 *
 * The types follow a consistent naming convention:
 * - intX:  X-bit signed integers (two's complement, explicitly signed)
 * - uintX: X-bit unsigned integers
 * - float32, float64: Floating-point types
 *
 * @note: These types are designed to be used throughout EToolkit for memory-safe and
 *        platform-independent numeric operations. All integer types have guaranteed
 *        two's complement representation and exact bit sizes.
 */

#ifndef ETOOLKITTYPES_HPP
#define ETOOLKITTYPES_HPP

#include <stdint.h>

typedef int8_t   int8;   ///<  8-bit signed integer (-128 to 127)
typedef int16_t  int16;  ///< 16-bit signed integer (-32,768 to 32,767)
typedef int32_t  int32;  ///< 32-bit signed integer (-2,147,483,648 to 2,147,483,647)
typedef int64_t  int64;  ///< 64-bit signed integer (-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807)

typedef uint8_t  uint8;  ///<  8-bit unsigned integer (0 to 255)
typedef uint16_t uint16; ///< 16-bit unsigned integer (0 to 65,535)
typedef uint32_t uint32; ///< 32-bit unsigned integer (0 to 4,294,967,295)
typedef uint64_t uint64; ///< 64-bit unsigned integer (0 to 18,446,744,073,709,551,615)

typedef float  float32;  ///< 32-bit single-precision floating-point (IEEE-754)
typedef double float64;  ///< 64-bit double-precision floating-point (IEEE-754)

/**
 * @brief Integer size validation
 * @description Ensures each integer type has exactly the expected byte size. These assertions guarantee portability across different compilers and platforms.
 */
static_assert(sizeof(int8)  == 1, "int8 must be exactly 1 byte (8 bits)");
static_assert(sizeof(int16) == 2, "int16 must be exactly 2 bytes (16 bits)");
static_assert(sizeof(int32) == 4, "int32 must be exactly 4 bytes (32 bits)");
static_assert(sizeof(int64) == 8, "int64 must be exactly 8 bytes (64 bits)");

static_assert(sizeof(uint8)  == 1, "uint8 must be exactly 1 byte (8 bits)");
static_assert(sizeof(uint16) == 2, "uint16 must be exactly 2 bytes (16 bits)");
static_assert(sizeof(uint32) == 4, "uint32 must be exactly 4 bytes (32 bits)");
static_assert(sizeof(uint64) == 8, "uint64 must be exactly 8 bytes (64 bits)");

static_assert(sizeof(float32) == 4, "float32 must be exactly 4 bytes");
static_assert(sizeof(float64) == 8, "float64 must be exactly 8 bytes");

#endif /* ETOOLKITTYPES_HPP */
