/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file PlatformSpecs.h
/// @brief Includes the platform specs for the selected platform
/// Defines macros that must be implemented by the compiler-specific header
///       
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef ME_PLATFORM_SPECS_H
#define ME_PLATFORM_SPECS_H


// include the defines 
#include "PlatformDefines.h"

// PRQA S 1014 1 // use std C header here because <cstddef> is not always available
#include <stddef.h>

// depending on Platform Defines, include the corresponding Platform Specification
#if defined(ME_PLATFORM_WIN) && defined(ME_PLATFORM_32_BIT)
  #include "PlatformSpecsWin32.h"
#elif defined(ME_PLATFORM_WIN) && defined(ME_PLATFORM_64_BIT)
  #include "PlatformSpecsWin64.h"
#elif defined(ME_PLATFORM_POS_35) && defined(ME_PLATFORM_32_BIT)
  #include "PlatformSpecsPos35.h"
#elif defined(ME_PLATFORM_POS_4X) && defined(ME_PLATFORM_64_BIT)
  #include "PlatformSpecsPos4x.h"
#elif defined(ME_PLATFORM_QNX) && defined(ME_PLATFORM_32_BIT)
  #include "PlatformSpecsQnx32.h"
#elif defined(ME_PLATFORM_QNX) && defined(ME_PLATFORM_64_BIT)
  #include "PlatformSpecsQnx64.h"
#elif defined(ME_PLATFORM_LINUX) && defined(ME_PLATFORM_32_BIT)
  #include "PlatformSpecsLinux32.h"
#elif defined(ME_PLATFORM_LINUX) && defined(ME_PLATFORM_64_BIT)
  #include "PlatformSpecsLinux64.h"
#elif defined(ME_PLATFORM_AUTOSAR) && defined(ME_PLATFORM_64_BIT)
  #include "PlatformSpecsAutosar64.h"
#elif defined(ME_PLATFORM_AUTOSAR) && defined(ME_PLATFORM_32_BIT)
  #include "PlatformSpecsAutosar32.h"
#elif defined(ME_PLATFORM_RTOS) && defined(ME_PLATFORM_64_BIT)
  #include "PlatformSpecsRtos64.h"
#elif defined(ME_PLATFORM_RTOS) && defined(ME_PLATFORM_32_BIT)
  #include "PlatformSpecsRtos32.h"
#else
  #error Platform Specification not supported!
#endif

// PRQA S 1051 EOF // Code example is not commented out code
// Macros that need to be implemented by the compiler specific headers:

// #define ME_DEBUG                     // The Flag used to distinguish between debug / Release version  
// #define ME_PLATFORM_NAME             // defines the name of the platform
// #define ME_COMPILER_NAME             // The compiler's name.
// #define ME_LITTLE_ENDIAN             // Little endian define (0 or 1).
// #define ME_BIG_ENDIAN                // Big endian define (0 or 1).
// #define ME_INLINE                    // Macro for inlining functions.
// #define ME_FORCE_INLINE              // Macro for forcing function inlining
// #define ME_OVERRIDE                  // Macro for the C++11 override keyword
// #define ME_FINAL                     // Macro for the C++11 final keyword
// #define ME_ALIGN(align_)             // Macro for specifying a type's alignment.
// #define ME_ALIGN_OF(x)               // Macro for receiving the alignment of a type.
// #define ME_PACKED                    // Macro for packaging of structures
// #define ME_THREAD_STORAGE            // Defines thread-local storage (TLS) for a variable.
// #define ME_NOOP_FUNCTION             // Replacement for an actual function name, but performs a no-op.
// #define ME_CDECL                     // Specifies __cdecl calling convention for a function (caller cleans up the stack). 
// #define ME_STDCALL                   // Specifies __stdcall calling convention for a function (callee cleans up the stack)
// #define ME_PRETTY_FUNCTION           // contains the "pretty" name of the function including the signature of the function
// #define ME_PATH_SEPARATOR            // wchar_t path separator e.g. L'/'
// #define ME_INVALID_PATH_SEPARATOR    // An invalid wchar_t path separator that might be replaced with ME_PATH_SEPARATOR when fixing a path string. e.g. L'\\'
// #define ME_BUILDDATE                 // __DATE__
// #define ME_BUILDTIME                 // __TIME__
// #define ME_MAX_PATH_LENGTH           // 256
// #define ME_INVALID_PROCESS_ID        // -1

// define Debug / release version


// DataTypes that must be implemented by the compiler specific headers:

//typedef <DataType> sint8_t;
//typedef <DataType> uint8_t;
//typedef <DataType> sint16_t;
//typedef <DataType> uint16_t;
//typedef <DataType> sint32_t;
//typedef <DataType> uint32_t;
//typedef <DataType> sint64_t;
//typedef <DataType> uint64_t;
//typedef <DataType> float32_t;
//typedef <DataType> float64_t;
//typedef <DataType> char_t;

// PRQA S 0631 1 // char_t may not be defined in c context
typedef char      char_t;

#ifdef __cplusplus
  typedef bool    bool_t; // PRQA S 2400 // The type name 'bool_t' is in the global scope.
#else
  typedef char_t  bool_t;
  // PRQA S 5172 2 // keyword definition
  #define true    (1) // PRQA S 4600 // stdbool header may not be available in c++ context
  #define false   (0) // PRQA S 4600 // stdbool header may not be available in c++ context
#endif




#endif // ME_PLATFORM_SPECS_H
