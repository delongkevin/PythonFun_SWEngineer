//--------------------------------------------------------------------------
/// @file PlatformSpecsPos35.h
/// @brief Platform Specifications for Pike OS 64 bit
/// Defines macros that must be implemented for Pike OS 64 bit
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

#ifndef ME_PLATFORM_SPECS_POS35_H
#define ME_PLATFORM_SPECS_POS35_H

// Macros that need to be implemented by the compiler specific headers

#ifdef PIKEOSDEBUG
  #define ME_DEBUG
#endif

#define ME_PLATFORM_NAME          "Pike OS"
#define ME_COMPILER_NAME          "Gnu Compiler Collection 4.8.2 32 Bit" 
#define ME_LITTLE_ENDIAN          1
#define ME_BIG_ENDIAN             0
#define ME_INLINE                 inline
#define ME_FORCE_INLINE           inline __attribute__((always_inline))
#define ME_OVERRIDE               // NA
#define ME_FINAL                  // NA
#define ME_ALIGN(align_)          __attribute__((aligned(align_)))
#define ME_ALIGN_OF(x)            __alignof__(x)
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

typedef signed   char      sint8_t;  
typedef unsigned char      uint8_t;
typedef signed   short     sint16_t;
typedef unsigned short     uint16_t;
typedef signed   int       sint32_t;
typedef unsigned long      uint32_t; // different from POS40 
typedef signed long long   sint64_t;
typedef unsigned long long uint64_t;
typedef float              float32_t;
typedef double             float64_t;
typedef char               char_t;

#endif // ME_PLATFORM_SPECS_POS64_H
