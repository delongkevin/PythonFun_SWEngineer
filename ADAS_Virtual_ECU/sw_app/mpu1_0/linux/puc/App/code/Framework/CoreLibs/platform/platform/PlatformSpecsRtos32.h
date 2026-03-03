//--------------------------------------------------------------------------
/// @file PlatformSpecsWin64.h
/// @brief Platform Specifications for Windows 64 bit
/// Defines macros that must be implemented for Windows 64 bit
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

#ifndef ME_PLATFORM_SPECS_RTOS_32_H
#define ME_PLATFORM_SPECS_RTOS_32_H

// Macros that need to be implemented by the compiler specific headers

#ifdef _DEBUG
#define ME_DEBUG
#endif

#define ME_PLATFORM_NAME          "Free Rtos"
#define ME_COMPILER_NAME          "Mingw GCC"
#define ME_LITTLE_ENDIAN          1
#define ME_BIG_ENDIAN             0
#define ME_INLINE                 __inline
#define ME_FORCE_INLINE           __forceinline
#define ME_OVERRIDE               override
#define ME_FINAL                  final
#define ME_ALIGN(align_)          __declspec(align(align_)) /* PRQA S 3453 *//* we want macros here */
#define ME_ALIGN_OF(x)            __alignof(x) /* PRQA S 3453 *//* we want Macros here */
#define ME_PACKED_STRUCT(x)       { __pragma( pack(push, 1) ); x __pragma( pack(pop) ); } /* PRQA S 3412 *//* we want Macros here */
#define ME_THREAD_STORAGE         __declspec(thread)
#define ME_NOOP_FUNCTION          __noop
#define ME_CDECL                  __cdecl
#define ME_STDCALL                __stdcall
#define ME_PRETTY_FUNCTION        __FUNCTION__
#define ME_PATH_SEPARATOR         '/'
#define ME_INVALID_PATH_SEPARATOR '\\'
#define ME_BUILDDATE              __DATE__
#define ME_BUILDTIME              __TIME__
#define ME_MAX_PATH_LENGTH        256
#define ME_INVALID_FILE_HANDLE    NULL
#define ME_INVALID_PROCESS_ID     0xFFFFFFFF
#define ME_WORKING_DIR            "C:/PrjDir"

// DataTypes that must be implemented by the compiler specific headers:

typedef signed    char            sint8_t;
typedef unsigned  char            uint8_t;
typedef signed    short           sint16_t;
typedef unsigned  short           uint16_t;
typedef signed    int             sint32_t;
typedef unsigned  int             uint32_t;
typedef signed    long long       sint64_t;
typedef unsigned  long long       uint64_t;
typedef float                     float32_t;
typedef double                    float64_t;
typedef char                      char_t;

#endif // ME_PLATFORM_SPECS_RTOS_32_H
