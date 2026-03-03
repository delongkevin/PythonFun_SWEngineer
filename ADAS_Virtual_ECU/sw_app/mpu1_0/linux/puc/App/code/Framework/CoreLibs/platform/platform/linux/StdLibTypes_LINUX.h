//--------------------------------------------------------------------------
/// @file StdLibTypes_LINUX.h
/// @brief Header for Linux Specific Standard Library Types
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

#ifndef ME_STD_LIB_TYPES_LINUX_H
#define ME_STD_LIB_TYPES_LINUX_H

#include "platform/PlatformSpecs.h"

// compile this file for Linux only
#ifdef ME_PLATFORM_LINUX

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

// includes needed for qnx types
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>  // PRQA S 5124 // standard library needed here, this is the abstraction

// TODO: maybe these lines should be moved to another header file
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <asm-generic/errno.h>

#include <sys/stat.h>
#include <sys/types.h>


#define EOK 0 // does not exist under Linux

typedef struct SemaphoreLinux_s
{
  sem_t* qnxSem_po;
} Semaphore_s;

typedef struct MutexLinux_s
{
  pthread_mutex_t qnxMutex_o;
} Mutex_s;

typedef struct CondvarLinux_s
{
  pthread_cond_t qnxCondvar_po;
  pthread_condattr_t qnxCondvarAttributes;
  Mutex_s MEMutex_po;
} Condvar_s;

typedef struct SharedMemoryLinux_s
{
  sint32_t dummy;
} SharedMemory_s;


typedef pthread_t ThreadID_t;
typedef struct ThreadHandleLinux_s
{
  pthread_t ThreadId;                           // holds the thread id
  pthread_attr_t qnxThreadAttributes_o;         // thread attributes
  struct sched_param qnxSchedulingParameters;   // scheduling parameters
} ThreadHandle_s;

typedef struct FileHandleLinux_s
{
  FILE* qnxFileHandle_po;
} FileHandle_s;

// Process
typedef pid_t ProcessID_t;
typedef struct ProcessHandleLinux_s
{
  FILE*   file_po;
  bool_t  created_b;
} ProcessHandle_s;

// Socket
#define ME_INVALID_SOCKET (-1)
typedef struct SocketHandleLinux_s
{
  sint32_t socketHandle_s32;
  bool_t   isBlocking_b;
} SocketHandle_t;

// TODO: agraf: remove this type (real impl needed!!!)
typedef struct LogHandleLinux_s
{
  SocketHandle_t logHandle_t;
} LogHandle_s;

// TODO: agraf: remove this line (real impl needed!!!)
typedef void * screen_context_t;

typedef screen_context_t ScreenContext_t;

typedef void*            Stream_t;

typedef sint32_t         Event_t;

typedef sint32_t         Display_t;

typedef sint32_t         Pixmap_t;

typedef sint32_t         Buffer_t;

typedef enum WindowTypeLinux_e
{
  e_ApplicationWindow,
  e_ChildWindow
} WindowType_t;

typedef struct WindowLinux_s
{
  sint32_t  contextHandle_t;
  sint32_t  windowHandle_t;
} Window_t;

// I2c

#define I2C_BUFFER_SIZE 64

typedef struct I2cHandleLinux_s
{
  sint32_t    i2cHandle_s32;
} I2cHandle_t;

typedef struct SendMessageLinux_s
{
  uint8_t    sendBuffer_au8[I2C_BUFFER_SIZE];
} SendMessage_t;

typedef struct RecvMessageLinux_s
{
  uint8_t    recvBuffer_au8[I2C_BUFFER_SIZE];
} RecvMessage_t;

// --------------------------------------------------------------------
// Uart
// --------------------------------------------------------------------

#define UART_BUFFER_SIZE 256

typedef struct UartHandleLinux_s
{
  sint32_t    uartHandle_s32;
  i2c_addr_t  uartSlaveAddress_t;
} UartHandle_t;

typedef int camera_handle_t;
// add other Linux dependent types here

// --------------------------------------------------------------------
// ICCOM
// --------------------------------------------------------------------

typedef struct IccomHandleLinux_s
{
  sint32_t handle_s32;
  uint8_t channelId_s8;
} IccomHandle_t;

// --------------------------------------------------------------------
// Interrupts
// --------------------------------------------------------------------

typedef struct InterruptHandleLinux_s
{
  sint32_t   irqId_s32;
  sint32_t   interruptId_s32;
} InterruptHandle_t;

#endif // ME_PLATFORM_LINUX

#endif // ME_STD_LIB_TYPES_LINUX_H
