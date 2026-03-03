//--------------------------------------------------------------------------
/// @file PlatformSpecsLinux64.h
/// @brief Platform Specifications for Linux 64 Bit
/// Defines macros that must be implemented for Linux 64 bit
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

#ifndef ME_PLATFORM_SPECS_LINUX64_H
#define ME_PLATFORM_SPECS_LINUX64_H

// Macros that need to be implemented by the compiler specific headers
#include <sys/types.h>
#include <machine/atomic.h>

#ifndef NDEBUG
  #define ME_DEBUG
#endif

#define ME_PLATFORM_NAME          "Linux"
#define ME_COMPILER_NAME          "Gnu Compiler Collection"
#define ME_LITTLE_ENDIAN          1
#define ME_BIG_ENDIAN             0
#define ME_INLINE                 inline
#define ME_FORCE_INLINE           inline __attribute__((always_inline))
#define ME_OVERRIDE               override
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

typedef __INT8_TYPE__             sint8_t;
typedef __UINT8_TYPE__            uint8_t;
typedef __INT16_TYPE__            sint16_t;
typedef __UINT16_TYPE__           uint16_t;
typedef __INT32_TYPE__            sint32_t;
typedef __UINT32_TYPE__           uint32_t;
typedef __INT64_TYPE__            sint64_t;
typedef __UINT64_TYPE__           uint64_t;
typedef float                     float32_t;
typedef double                    float64_t;
typedef char                      char_t;
typedef atomic_t                  atomic_address_t;
#endif // ME_PLATFORM_SPECS_LINUX64_H
