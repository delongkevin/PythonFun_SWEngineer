/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------

/// @file StdLibTypes_RTOS.h
/// @brief Header for RTOS Specific Standard Library Types
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef ME_STD_LIB_TYPES_RTOS_H
#define ME_STD_LIB_TYPES_RTOS_H

// PRQA S 2400 EOF // global scope, this is a shared c and cpp header file

#include "platform/PlatformSpecs.h"

// compile this file for AUTOSAR only
#ifdef ME_PLATFORM_RTOS

#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <timers.h>
#include <semphr.h>

#include "platform/stdlib/utils/ME_FileSystem.h"

typedef struct SemaphoreRtos_s
{
  SemaphoreHandle_t handle_t;
} Semaphore_s;

typedef struct MutexRtos_s
{
  SemaphoreHandle_t handle_t;
} Mutex_s;


#define c_MaxCondvarTaskHandles_u32  32U
typedef struct CondvarRtos_s
{
  Mutex_s      MEMutex_po;
  uint8_t      tasksToNotify_u8;
  TaskHandle_t taskHandles_at[c_MaxCondvarTaskHandles_u32];
} Condvar_s;

typedef struct SharedMemoryRtos_s
{
  sint32_t dummy;
} SharedMemory_s;


typedef uint32_t ThreadID_t;
typedef struct ThreadHandleRtos_s
{
  TaskHandle_t handle_t;
} ThreadHandle_s;

typedef struct FileHandleRtos_s
{
  ME_FileInfo_t* FileHandle_pt;
} FileHandle_s;

typedef struct LogHandleRtos_s
{
  uint32_t dummy;
} LogHandle_s;

// Process
typedef uint32_t ProcessID_t;
typedef struct ProcessHandleRtos_s
{
  uint32_t dummy;
} ProcessHandle_s;

// Socket
#define ME_INVALID_SOCKET (-1) // PRQA S 1026 // used by C and C++
typedef sint32_t SocketHandle_t;

// --------------------------------------------------------------------
// Interrupts
// --------------------------------------------------------------------

typedef struct InterruptHandleRtos_s
{
  sint32_t   irqId_s32;
  sint32_t   interruptId_s32;
} InterruptHandle_t;

// add other RTOS dependent types here

#endif // ME_PLATFORM_RTOS // PRQA S 862 // this define decides which platform is defined

#endif // ME_STD_LIB_TYPES_RTOS_H
