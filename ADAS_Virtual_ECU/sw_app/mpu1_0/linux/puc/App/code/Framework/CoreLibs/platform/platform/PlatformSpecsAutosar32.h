/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file PlatformSpecsWin32.h
/// @brief Platform Specifications for Windows 64 bit
/// Defines macros that must be implemented for Windows 64 bit
///       
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Alexander Stadler
///
//  --------------------------------------------------------------------------

#ifndef ME_PLATFORM_SPECS_AUTOSAR32_H
#define ME_PLATFORM_SPECS_AUTOSAR32_H

// Macros that need to be implemented by the compiler specific headers

#ifndef NDEBUG
  #define ME_DEBUG
#endif

#include <stdint.h>

// PRQA S 1026 EOF // Macro may be used as a constant expression. shared between c and cpp
// PRQA S 1025 EOF // Macro may be used as a literal. shared between c and cpp
// PRQA S 1021 EOF // Macro may be used as a literal. shared between c and cpp
// PRQA S 1020 EOF // Macro may be used here
// PRQA S 2400 EOF // global scope: yes for sure, this is the header declaration

#define ME_PLATFORM_NAME          "AUTOSAR"
#define ME_COMPILER_NAME          "Gnu Compiler Collection 5.4.0 64 Bit"
#define ME_LITTLE_ENDIAN          1
#define ME_BIG_ENDIAN             0
#define ME_INLINE                 static
#define ME_FORCE_INLINE           inline __attribute__((always_inline))
#define ME_OVERRIDE               // NA
#define ME_FINAL                  // NA
#define ME_ALIGN(align_)          __attribute__((aligned(align_))) // PRQA S 3453 // we want Macros here
#define ME_ALIGN_OF(x)            __alignof__(x) // PRQA S 3453 // we want Macros here
#define ME_PACKED_STRUCT(x)       { x } __attribute__((__packed__))  /* PRQA S 3412 *//* we want Macros here */
#define ME_THREAD_STORAGE         __thread
#define ME_NOOP_FUNCTION          (void)
#define ME_CDECL                  // NA
#define ME_STDCALL                // NA
#define ME_PRETTY_FUNCTION        __FUNCTION__
#define ME_PATH_SEPARATOR         '/'
#define ME_INVALID_PATH_SEPARATOR '\\'
#define ME_BUILDDATE              __DATE__
#define ME_BUILDTIME              __TIME__
#define ME_MAX_PATH_LENGTH        256
#define ME_INVALID_FILE_HANDLE    (-1)
#define ME_INVALID_PROCESS_ID     (-1)
#define ME_WORKING_DIR            "/PrjDir"

// DataTypes that must be implemented by the compiler specific headers:


typedef signed char               sint8_t;
//typedef unsigned char             uint8_t; // already defined
typedef signed short int          sint16_t;
//typedef unsigned short int        uint16_t; // already defined
typedef signed long int           sint32_t;
//typedef unsigned long int         uint32_t; // already in #include <stdint.h>
typedef signed long long          sint64_t;
//typedef unsigned long long        uint64_t; // already defined
typedef float                     float32_t;
typedef double                    float64_t;
typedef char                      char_t;

//typedef unsigned char             BOOL; // already defined



#endif // ME_PLATFORM_SPECS_AUTOSAR32_H
