//--------------------------------------------------------------------------
/// @file StdLibTypes_QNX.h
/// @brief Header for Qnx Specific Standard Library Types
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

#ifndef ME_STD_LIB_TYPES_QNX_H
#define ME_STD_LIB_TYPES_QNX_H

#include "platform/PlatformSpecs.h"

// PRQA S 2400 EOF // global scope, this is a shared c and cpp header file

// compile this file for QNX only
#ifdef ME_PLATFORM_QNX

// includes needed for qnx types
#include <semaphore.h>
#include <pthread.h>

#include <stdlib.h>
#include <string.h>

#include <stdarg.h> // needed in ME_Debugger

#include <stdio.h>  // PRQA S 5124 // PRQA S 5188 // standard library needed here, this is the abstraction
#include <errno.h>

#include <fcntl.h>
#include <sys/slog.h>
#include <sys/types.h>
#include <sys/slogcodes.h>
#include <unistd.h>
#include <sys/iofunc.h>
#include <sys/dispatch.h>
#include <sys/neutrino.h>
#include <sys/iofunc.h>
#include <errno.h>
#include <devctl.h>
#include <fcntl.h>
#include <sys/procmgr.h>

// --------------------------------------------------------------------
// Semaphore
// --------------------------------------------------------------------

typedef struct SemaphoreQnx_s
{
  sem_t* qnxSem_po;
} Semaphore_s;

// --------------------------------------------------------------------
// Mutext
// --------------------------------------------------------------------

typedef struct MutexQnx_s
{
  pthread_mutex_t qnxMutex_t;
} Mutex_s;

// --------------------------------------------------------------------
// Condititon Variable
// --------------------------------------------------------------------

typedef struct CondvarQnx_s
{
  pthread_cond_t qnxCondvar_t;
  pthread_condattr_t qnxCondvarAttributes_t;
  Mutex_s MEMutex_po;
} Condvar_s;

// --------------------------------------------------------------------
// Shared Memory
// --------------------------------------------------------------------

typedef struct SharedMemoryQnx_s
{
  sint32_t dummy;
} SharedMemory_s;


// --------------------------------------------------------------------
// Thread
// --------------------------------------------------------------------

typedef pthread_t ThreadID_t;
typedef struct ThreadHandleQnx_s
{
  pthread_t ThreadId;                           // holds the thread id
  pthread_attr_t qnxThreadAttributes_o;         // thread attributes
  Condvar_s qnxSuspendCondvar_t;
  bool_t qnxSuspendFlag_b;
  struct sched_param qnxSchedulingParameters;   // scheduling parameters
} ThreadHandle_s;


// --------------------------------------------------------------------
// File
// --------------------------------------------------------------------

typedef struct FileHandleQnx_s
{
  FILE* qnxFileHandle_po;
} FileHandle_s;

typedef struct ICCOMHandleQnx_s
{
  uint32_t channelNumber_u32;
  sint32_t fileHandle_s32;
} ICCOMHandle_s;

// Process
typedef pid_t ProcessID_t;
typedef struct ProcessHandleQnx_s
{
  FILE*   file_po;
  bool_t  created_b;
} ProcessHandle_s;

// --------------------------------------------------------------------
// Socket
// --------------------------------------------------------------------

#define ME_INVALID_SOCKET (-1) // PRQA S 1026 // used by C and C++
typedef struct SocketHandle_s
{
  sint32_t socketHandle_s32;
  bool_t isBlocking_b;
} SocketHandle_t;

// --------------------------------------------------------------------
// Logging
// --------------------------------------------------------------------

typedef struct LogHandleQnx_s
{
  SocketHandle_t logHandle_t;
} LogHandle_s;



// --------------------------------------------------------------------
// Interrupts
// --------------------------------------------------------------------

typedef struct InterruptHandleQnx_s
{
  sint32_t   irqId_s32;
  sint32_t   interruptId_s32;
} InterruptHandle_t;



#endif // ME_PLATFORM_QNX

#endif // ME_STD_LIB_TYPES_QNX_H
