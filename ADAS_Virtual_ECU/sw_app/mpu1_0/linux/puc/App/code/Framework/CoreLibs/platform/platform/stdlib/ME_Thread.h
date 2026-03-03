/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file ME_Thread.h
/// @brief Interface to abstract standard-library Thread
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

#ifndef ME_THREAD_H
#define ME_THREAD_H

#include "platform/PlatformSpecs.h"

#include "platform/stdlib/StdLibTypes.h"


#if defined(__cplusplus)
extern "C"
{
#endif

// Scheduling Policy
typedef enum SchedulingPolicy_e // PRQA S 2400 // global scope, this is a shared c and cpp header file
{
  e_SpFifo,         // First in First out scheduling
  e_SpRoundRobin    // Round Robin Scheduling
} SchedulingPolicy_t; // PRQA S 2400 // global scope, this is a shared c and cpp header file

// Thread function
typedef void* (*ThreadFunc_t)(void* args); // PRQA S 2400 // global scope, this is a shared c and cpp header file

// PRQA S 2300 1 // intended // forward declaration, needs to be implemented in c-file
extern const size_t ME_Thread_C_DefaultStackSize_t; // use OS specific stack size // PRQA S 1025 //  Macro may be used as a literal. Is OK here

typedef enum ME_Thread_Priority_e // PRQA S 2400 // global scope, this is a shared c and cpp header file
{
  e_PriorityIdle,
  e_PriorityLow,
  e_PriorityNormal,
  e_PriorityBelowHigh,
  e_PriorityHigh,
  e_PriorityAboveHigh,
  e_PriorityBelowRealtime,
  e_PriorityRealtime
} ME_Thread_Priority_t; // PRQA S 2400 // global scope, this is a shared c and cpp header file


typedef enum CpuId_e // PRQA S 2400 // global scope, this is a shared c and cpp header file
{
  e_Cpu1 = 1 << 0,
  e_Cpu2 = 1 << 1,
  e_Cpu3 = 1 << 2,
  e_Cpu4 = 1 << 3,
  e_CpuAny = e_Cpu1 | e_Cpu2 | e_Cpu3 | e_Cpu4
} CpuId_t; // PRQA S 2400 // global scope, this is a shared c and cpp header file

PlatformError_t ME_Thread_Attribute_SetInheritedScheduling_t(ThreadHandle_s* b_Thread_ps, bool_t i_Inherited_b);

PlatformError_t ME_Thread_Attribute_SetSchedulingPolicy_t(ThreadHandle_s* b_Thread_ps, SchedulingPolicy_t i_SchedulingPolicy_t);

PlatformError_t ME_Thread_Attribute_SetPriority_e(ThreadHandle_s* b_Thread_ps, ME_Thread_Priority_t i_Priority_e);

// Create Thread. By default, all the threads created using pthread_create() inherit the program name.
PlatformError_t ME_Thread_Create_t(ThreadHandle_s* b_Thread_ps, ThreadFunc_t i_ThreadFunc_pv, void* i_ThreadArgs_pv, size_t i_StackSize_t);

PlatformError_t ME_Thread_Suspend_t(ThreadHandle_s* b_Thread_ps);

PlatformError_t ME_Thread_Resume_t(ThreadHandle_s* b_Thread_ps);

PlatformError_t ME_Thread_CheckSuspend_t(ThreadHandle_s* b_Thread_ps);

// set Priority after thread creation
PlatformError_t ME_Thread_SetPriority_t(const ThreadHandle_s* b_Thread_ps, ME_Thread_Priority_t i_Priority_e);

// get the thread priority after thread creation
PlatformError_t ME_Thread_GetPriority_t(const ThreadHandle_s* b_Thread_ps, ME_Thread_Priority_t* b_Priority_e);

// sets the CPU affinity
PlatformError_t ME_Thread_SetCpuAffinity_t(const ThreadHandle_s* b_Thread_ps, CpuId_t i_CpuId_t);

// Returns the thread ID of the calling thread
ThreadID_t      ME_Thread_GetCurrentID_t(void);

// set new thread name
PlatformError_t ME_Thread_SetName_t(const ThreadHandle_s* i_Thread_ps, const char_t* i_Name_pc);

// get thread name
PlatformError_t ME_Thread_GetName_t(const ThreadHandle_s* i_Thread_ps, char_t* o_Name_pc, sint32_t i_BufferSize_s32);

// cancel thread
PlatformError_t ME_Thread_Cancel_t(const ThreadHandle_s* i_Thread_ps);

// join thread
PlatformError_t ME_Thread_Join_t(const ThreadHandle_s* i_Thread_ps);

// threads also need a nap sometimes
PlatformError_t ME_Thread_Sleep_t(uint32_t i_MilliSeconds_u32);

#if defined(__cplusplus)
}; // extern C
#endif

#endif // ME_THREAD_H
