//--------------------------------------------------------------------------
/// @file StdLibTypes_WIN.h
/// @brief Header for Win Specific Standard Library Types
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

#ifndef ME_STD_LIB_TYPES_WIN_H
#define ME_STD_LIB_TYPES_WIN_H

#include "platform/PlatformSpecs.h"

// Compile this file for WIN only!
#ifdef ME_PLATFORM_WIN

// includes needed for win types
#include "WinInclude.h"

//include needed for screen implementation
#include <winuser.h>

//includes needed for pipe implementation in ME_Iccom
#include <fcntl.h>
#include <stdio.h>
#include <io.h>

// include and link winsock, Used for 32 and 64 bit
#include <winsock2.h>
#pragma comment (lib, "Ws2_32.lib")

#define D_MAX_NAME_LENGTH    32

typedef struct SemaphoreWin_s
{
  HANDLE winSem_po;
} Semaphore_s;

typedef struct MutexWin_s
{
  uint8_t winMutex_o; // TODO
  CRITICAL_SECTION CritSection;
} Mutex_s;

typedef struct CondvarWin_s
{
  CONDITION_VARIABLE ConditionVar;
  Mutex_s MEMutex_po;
} Condvar_s;

typedef struct SharedMemoryWin_s
{
  HANDLE shmFileHandle_t;
} SharedMemory_s; 


typedef int ThreadID_t;
typedef struct ThreadHandleWin_s
{
  HANDLE hThread;
  DWORD ThreadId; // holds the thread id
  LPSECURITY_ATTRIBUTES lpThreadAttributes;
  Condvar_s winSuspendCondvar_t;
  bool_t winSuspendFlag_b;
  char_t winThreadName_ac[D_MAX_NAME_LENGTH];
} ThreadHandle_s;

typedef struct FileHandleWin_s
{
  HANDLE winFileHandle_po;
} FileHandle_s;

// Process
typedef uint32_t ProcessID_t;
typedef struct ProcessHandleWin_s
{
  HANDLE processHandle_po;
  bool_t created_b;
} ProcessHandle_s;

// Socket
#define ME_INVALID_SOCKET INVALID_SOCKET // PRQA S 1026 // used by C and C++
typedef struct SocketHandleWin_s
{
  SOCKET socket_t;
  uint32_t isNonBlocking_u32;
} SocketHandle_t;

// Logging
typedef struct LogHandleWin_s
{
  SocketHandle_t writeHandle_s;
} LogHandle_s;


// --------------------------------------------------------------------
// Interrupts
// --------------------------------------------------------------------

typedef struct InterruptHandleWin_s
{
  sint32_t   irqId_s32;
  sint32_t   interruptId_s32;
} InterruptHandle_t;


// add other Windows dependent types here

#endif // ME_PLATFORM_WIN

#endif // ME_STD_LIB_TYPES_WIN_H
