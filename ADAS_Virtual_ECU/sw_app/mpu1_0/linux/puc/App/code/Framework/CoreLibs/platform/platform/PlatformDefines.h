/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------

/// @file PlatformDefines.h
/// @brief Defines the following platforms:
///
/// ME_PLATFORM_WIN      - Windows with MS Visual C++ compiler for 32 bit / 64 bit
/// ME_PLATFORM_POS_35   - PikeOS with GCC compiler 32 bit
/// ME_PLATFORM_POS_4X   - PikeOS with GCC compiler 64 bit
/// ME_PLATFORM_QNX      - QNX with GCC compiler 32 bit / 64 bit
/// ME_PLATFORM_LINUX    - Linux with GCC compiler 32 bit / 64 bit (experimental, same api as QNX (posix) )
/// ME_PLATFORM_MAC      - Mac with GCC compiler (TODO)
/// ME_PLATFORM_AUTOSAR  - Autosar (TODO)
/// ME_PLATFORM_RPU      - (TODO)
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

// PRQA S 0844 EOF // macro redefinition is ok here
// PRQA S 3614 EOF // why undef if redef is fine
// PRQA S 1036 EOF // conditional preprocessor directive is wanted here!

#ifndef ME_PLATFORM_DEFINES_H
#define ME_PLATFORM_DEFINES_H

//#undef __QNX__
//#define __RTOS__

// 1) check for 32 bit or 64 bit
#if defined (__alpha__)  || defined (__ia64__)  || \
    defined (__x86_64__) || defined (_WIN64)    || \
    defined (__LP64__)   || defined (__LLP64__) || \
    defined (PLATFORM)   && (PLATFORM == aarch64le) /* && needed for QAC */
  #define ME_PLATFORM_64_BIT
#else
  #define ME_PLATFORM_32_BIT
#endif


// 2) check the platform
#if defined(__RTOS__)
#define ME_PLATFORM_RTOS
#elif defined(_MSC_VER)
#define ME_PLATFORM_WIN
#elif defined(PIKEOSCPPENV) && (PIKEOS_VERSION < 40)
#define ME_PLATFORM_POS
#define ME_PLATFORM_POS_35
#elif defined(PIKEOSCPPENV) && (PIKEOS_VERSION >= 40)
#define ME_PLATFORM_POS
#define ME_PLATFORM_POS_4X
#elif defined(__QNX__)
#define ME_PLATFORM_QNX
#elif defined(__linux__)
#define ME_PLATFORM_LINUX
#elif defined(__APPLE__)
#define ME_PLATFORM_MAC
#elif defined(___AUTOSAR___)
#define ME_PLATFORM_AUTOSAR
#elif defined(__MCU__)
#define ME_PLATFORM_RPU
#else
#error Platform Define not supported!
#endif

// 3) Check for c++ 11 support
 // PRQA S 3332 1 // macro is not defined for c, but we are also in c++ context here
#if __cplusplus >= 199711L
  #define ME_PLATFORM_CPP_11
#endif


#endif // ME_PLATFORM_DEFINES_H
