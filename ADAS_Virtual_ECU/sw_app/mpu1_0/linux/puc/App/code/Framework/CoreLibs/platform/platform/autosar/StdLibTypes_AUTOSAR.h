/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------

/// @file StdLibTypes_AUTOSAR.h
/// @brief Header for Autosar Specific Standard Library Types
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

#ifndef ME_STD_LIB_TYPES_AUTOSAR_H
#define ME_STD_LIB_TYPES_AUTOSAR_H

#include "platform/PlatformSpecs.h"

// PRQA S 2400 EOF // global scope, this is a shared c and cpp header file

// compile this file for AUTOSAR only
#ifdef ME_PLATFORM_AUTOSAR

typedef struct SemaphoreAutosar_s
{
  uint32_t dummy;
} Semaphore_s;

typedef struct MutexAutosar_s
{
  uint32_t dummy;
} Mutex_s;

typedef struct CondvarAutosar_s
{
  Mutex_s MEMutex_po;
} Condvar_s;

typedef struct SharedMemoryAutosar_s
{
  sint32_t dummy;
} SharedMemory_s;


typedef uint32_t ThreadID_t;
typedef struct ThreadHandleAutosar_s
{
  uint32_t dummy;
} ThreadHandle_s;

typedef struct FileHandleAutosar_s
{
  uint32_t FileHandle_po;
} FileHandle_s;

typedef struct LogHandleAutosar_s
{
  uint32_t dummy;
} LogHandle_s;

// Process
typedef uint32_t ProcessID_t;
typedef struct ProcessHandleAutosar_s
{
  uint32_t dummy;
} ProcessHandle_s;

// Socket
#define ME_INVALID_SOCKET (-1) // PRQA S 1026 // used by C and C++
typedef sint32_t SocketHandle_t;

// --------------------------------------------------------------------
// Interrupts
// --------------------------------------------------------------------

typedef struct InterruptHandleAutosar_s
{
  sint32_t   irqId_s32;
  sint32_t   interruptId_s32;
} InterruptHandle_t;

// add other AUTOSAR dependent types here

#endif // ME_PLATFORM_AUTOSAR // PRQA S 862 // this define decides which platform is defined

#endif // ME_STD_LIB_TYPES_AUTOSAR_H
