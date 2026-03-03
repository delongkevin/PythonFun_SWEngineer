/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file StdLibTypes.h
/// @brief Generic Header for Platform Specific Standard Library Types.
///        Contains an Enum for Error Handling function
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------


#ifndef ME_STD_LIB_TYPES_H
#define ME_STD_LIB_TYPES_H

#include "platform/PlatformSpecs.h"

// Error Enum. If you add Enums here, implement OS Specific error code mapping in StdLibTypes_QNX.c
typedef enum PlatformError_e // PRQA S 2400 // global scope, this is a shared c and cpp header file
{
  e_PeUnmapped = 0, // Internal Mapping Error! Map the Os specific error to this enum
  e_PeOk,           // Success.
  e_PeNoPermission,
  e_PeAgain,        // Insufficient system resources available
  e_PeNoEntry,      // No such file or directory
  e_PeDeadLock,     // The calling thread already owns mutex, and the mutex doesn't allow recursive behavior.
  e_PeFault,        // A fault occurred when the kernel tried to access the buffers you provided.
  e_PeBusy,         // Resource is busy
  e_PeTimedOut,     // A kernel timeout unblocked the call.
  e_PeNoMemory,     // Insufficient memory to initialize object.
  e_PeNoSuchProcess, // Invalid given ID for a process or thread
  e_PeNoSuchDevice,  // Invalid Device, either the device does not exist or exist anymore
  e_PeBadFileDescriptor, // Invalid given file descriptor, most cases -1
  e_PeInvalid,      // Invalid mutex.
  e_PeNotSupported,
  e_PeResultTooLarge,
  e_PeAddrNotAvailable,
  e_PeConnAborted   // (Socket) Connection Aborted.
} PlatformError_t; // PRQA S 2400 // global scope, this is a shared c and cpp header file

#if defined(__cplusplus)
extern "C"
{
#endif
// function to map Platform error enum to os specific error codes
PlatformError_t ME_GetPlatformError_t(sint32_t i_ErrorState_s32);

#if defined(__cplusplus)
}; // extern C
#endif

// depending on Platform Defines, include the corresponding Platform types Specification
#if defined(ME_PLATFORM_WIN)
  #include "platform/win/StdLibTypes_WIN.h"
#elif defined(ME_PLATFORM_POS_35) || defined(ME_PLATFORM_POS_4X)
  #error POS Platform Types not supported!
#elif defined(ME_PLATFORM_QNX)
  #include "platform/qnx/StdLibTypes_QNX.h"
#elif defined(ME_PLATFORM_LINUX)
  #include "platform/linux/StdLibTypes_LINUX.h"
#elif defined(ME_PLATFORM_AUTOSAR)
  #include "platform/autosar/StdLibTypes_AUTOSAR.h"
#elif defined(ME_PLATFORM_RTOS)
  #include "platform/freertos/StdLibTypes_RTOS.h"
#else
  #error Platform Types not supported!
#endif


#endif // ME_STD_LIB_TYPES_H
