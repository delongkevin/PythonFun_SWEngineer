//--------------------------------------------------------------------------
/// @file ME_Thread_WIN.c
/// @brief Win implementation for standard-library Thread
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


// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for WIN only
#ifdef ME_PLATFORM_WIN

// stdlib header include
#include "platform/stdlib/ME_Thread.h"
#include "platform/stdlib/ME_Debugger.h"
#include "platform/stdlib/ME_Condvar.h"
#include "platform/stdlib/ME_Mutex.h"

#include <errno.h>

const size_t ME_Thread_C_DefaultStackSize_t = 0;

static PlatformError_t ME_Thread_Attribute_Init_t(ThreadHandle_s* b_Thread_ps);
static sint32_t ME_Thread_WIN_GetPrioFromPlatformPrio(ME_Thread_Priority_t i_Priority_e);
static ME_Thread_Priority_t ME_Thread_WIN_GetPlatformPrio(sint32_t i_Priority_s32);

// Internal Helper functions for attribute initialization
static PlatformError_t ME_Thread_Attribute_Init_t(ThreadHandle_s* b_Thread_ps)
{
  PlatformError_t v_Error_t = e_PeOk;

  if(NULL != b_Thread_ps)
  {
    b_Thread_ps->lpThreadAttributes = NULL;
    v_Error_t = e_PeOk;
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }
  return v_Error_t;
}

static sint32_t ME_Thread_WIN_GetPrioFromPlatformPrio(ME_Thread_Priority_t i_Priority_e)
{
  sint32_t v_Priority_s32;

  switch (i_Priority_e)
  {
    case e_PriorityIdle:
      v_Priority_s32 = THREAD_PRIORITY_IDLE;
      break;
    case e_PriorityLow:
      v_Priority_s32 = THREAD_PRIORITY_LOWEST;
      break;
    case e_PriorityNormal:
      v_Priority_s32 = THREAD_PRIORITY_NORMAL;
      break;
    case e_PriorityBelowHigh:
      v_Priority_s32 = THREAD_PRIORITY_ABOVE_NORMAL;
      break;
    case e_PriorityHigh:
      v_Priority_s32 = THREAD_PRIORITY_HIGHEST;
      break;
    case e_PriorityAboveHigh:
      v_Priority_s32 = THREAD_PRIORITY_HIGHEST;
      break;
    case e_PriorityBelowRealtime:
      v_Priority_s32 = THREAD_PRIORITY_TIME_CRITICAL;
      break;
    case e_PriorityRealtime:
      v_Priority_s32 = THREAD_PRIORITY_TIME_CRITICAL;
      break;
    default:
      v_Priority_s32 = THREAD_PRIORITY_NORMAL;
      break;
  }

  return v_Priority_s32;
}

static ME_Thread_Priority_t ME_Thread_WIN_GetPlatformPrio(sint32_t i_Priority_s32)
{
  ME_Thread_Priority_t v_Priority_e;

  switch (i_Priority_s32)
  {
    case THREAD_PRIORITY_IDLE:
      v_Priority_e = e_PriorityIdle;
      break;
    case THREAD_PRIORITY_LOWEST:
      v_Priority_e = e_PriorityLow;
      break;
    case THREAD_PRIORITY_NORMAL:
      v_Priority_e = e_PriorityNormal;
      break;
    case THREAD_PRIORITY_ABOVE_NORMAL:
      v_Priority_e = e_PriorityBelowHigh;
      break;
    case THREAD_PRIORITY_HIGHEST:
      v_Priority_e = e_PriorityHigh;
      v_Priority_e = e_PriorityAboveHigh;   // double mapping
      break;
    case THREAD_PRIORITY_TIME_CRITICAL:
      v_Priority_e = e_PriorityRealtime;
      v_Priority_e = e_PriorityBelowRealtime; // double mapping
      break;
    default:
      v_Priority_e = e_PriorityNormal;
      break;
  }

  return v_Priority_e;
}

PlatformError_t ME_Thread_Attribute_SetInheritedScheduling_t(ThreadHandle_s* b_Thread_ps, bool_t i_Inherited_b)
{
  PlatformError_t v_Error_t = e_PeOk;

  if(NULL != b_Thread_ps)
  {
    b_Thread_ps->lpThreadAttributes->bInheritHandle = i_Inherited_b;
    v_Error_t = e_PeOk;
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }
  return v_Error_t;
}

//TODO: scheduling supported?
PlatformError_t ME_Thread_Attribute_SetSchedulingPolicy_t(ThreadHandle_s* b_Thread_ps, SchedulingPolicy_t i_SchedulingPolicy_e)
{
  sint32_t        v_Result_s32      = 0;
  sint32_t        v_SchedPolicy_s32 = 0;
  PlatformError_t v_Error_t         = e_PeOk;

  switch (i_SchedulingPolicy_e)
  {
    case e_SpFifo:        v_SchedPolicy_s32 = 0 /* TODO SCHED_FIFO*/; break; // TODO
    case e_SpRoundRobin:  v_SchedPolicy_s32 = 0 /* SCHED_RR*/;   break; // TODO
    default :             v_Result_s32      = -1;         break;  // set invalid result if mapping doesn't exist
  }

  if (-1 != v_Result_s32)
  {
    v_Result_s32 = 0; // TODO pthread_attr_setschedpolicy(&b_Thread_ps->qnxThreadAttributes_o, v_SchedPolicy_s32);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_Attribute_SetPriority_e(ThreadHandle_s* b_Thread_ps, ME_Thread_Priority_t i_Priority_e)
{
  sint32_t i_Priority_s32 = 0;
  //TODO
  return ME_Thread_SetPriority_t(b_Thread_ps, i_Priority_s32);
}

PlatformError_t ME_Thread_Create_t(ThreadHandle_s* b_Thread_ps, ThreadFunc_t i_ThreadFunc_pv, void* i_ThreadArgs_pv, size_t i_StackSize_t)
{
  PlatformError_t v_Error_t     = e_PeOk;
  sint32_t        v_Result_s32  = -1;

  if (NULL == b_Thread_ps)
  {
    ME_Debugger_F_Printf_v("ME_Thread_Create_t - Invalid Thread Handle\n");
    v_Error_t = e_PeInvalid;
  }
  else
  {
    // init default thread attributes, we have no default initialization attribute values right now
    v_Error_t = ME_Thread_Attribute_Init_t(b_Thread_ps);

    if (e_PeOk == v_Error_t)
    {
      b_Thread_ps->hThread = CreateThread(
                              b_Thread_ps->lpThreadAttributes,
                              i_StackSize_t,
                              (LPTHREAD_START_ROUTINE)i_ThreadFunc_pv,              // thread function name
                              i_ThreadArgs_pv,                // argument to thread function
                              0,                              // use default creation flags
                              &b_Thread_ps->ThreadId);        // returns the thread identifier
      
      (void)memset(b_Thread_ps->winThreadName_ac, 0x00, sizeof(b_Thread_ps->winThreadName_ac));
      
      if(NULL == b_Thread_ps->hThread)
      {
        v_Error_t = ME_GetPlatformError_t(-1);
      }
      else
      {
        ME_Condvar_Init_t(&b_Thread_ps->winSuspendCondvar_t);
        ME_Mutex_Init_t(&b_Thread_ps->winSuspendCondvar_t.MEMutex_po, true);
      }
    }
    else
    {
      ME_Debugger_F_Printf_v("ME_Thread_Create_t - Error Setting Thread Attributes\n");
    }
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_Suspend_t(ThreadHandle_s* b_Thread_ps)
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if(b_Thread_ps != NULL)
  {
    ME_Mutex_Lock_t(&b_Thread_ps->winSuspendCondvar_t.MEMutex_po);
    b_Thread_ps->winSuspendFlag_b = true;
    ME_Mutex_UnLock_t(&b_Thread_ps->winSuspendCondvar_t.MEMutex_po);

    v_Error_t = e_PeOk;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_Resume_t(ThreadHandle_s* b_Thread_ps)
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if(b_Thread_ps != NULL)
  {
    ME_Mutex_Lock_t(&b_Thread_ps->winSuspendCondvar_t.MEMutex_po);
    b_Thread_ps->winSuspendFlag_b = false;
    ME_Condvar_Broadcast_t(&b_Thread_ps->winSuspendCondvar_t);
    ME_Mutex_UnLock_t(&b_Thread_ps->winSuspendCondvar_t.MEMutex_po);

    v_Error_t = e_PeOk;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_CheckSuspend_t(ThreadHandle_s* b_Thread_ps)
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if(b_Thread_ps != NULL)
  {
    ME_Mutex_Lock_t(&b_Thread_ps->winSuspendCondvar_t.MEMutex_po);
    while(b_Thread_ps->winSuspendFlag_b != false)
    {
      ME_Condvar_Wait_t(&b_Thread_ps->winSuspendCondvar_t);
    }
    ME_Mutex_UnLock_t(&b_Thread_ps->winSuspendCondvar_t.MEMutex_po);
  }

  return v_Error_t;
}

// https://msdn.microsoft.com/en-us/library/windows/desktop/ms686277(v=vs.85).aspx
PlatformError_t ME_Thread_SetPriority_t(const ThreadHandle_s* b_Thread_ps, ME_Thread_Priority_t i_Priority_e)
{
  PlatformError_t v_Error_t = e_PeOk;

  if (NULL != b_Thread_ps)
  {
    sint32_t v_Result_s32;
    bool_t v_Result_b;
    sint32_t v_Priority_s32;

    v_Priority_s32 = ME_Thread_WIN_GetPrioFromPlatformPrio(i_Priority_e);

    v_Result_b = SetThreadPriority(b_Thread_ps->hThread, v_Priority_s32);
    if (true == v_Result_b)
    {
      v_Result_s32 = 0;
    }
    else
    {
      v_Result_s32 = -1;
    }
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_GetPriority_t(const ThreadHandle_s* b_Thread_ps, ME_Thread_Priority_t* i_Priority_e)
{
  PlatformError_t v_Error_t = e_PeOk;

  if((NULL != b_Thread_ps) && (NULL != i_Priority_e))
  {
    sint32_t v_Priority_s32;
    v_Priority_s32 = GetThreadPriority(b_Thread_ps->hThread);

    *i_Priority_e = ME_Thread_WIN_GetPlatformPrio(v_Priority_s32);

    v_Error_t = e_PeOk;
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_SetCpuAffinity_t(const ThreadHandle_s* b_Thread_ps, CpuId_t i_CpuId_t)
{
  PlatformError_t v_Error_t = e_PeOk;

  if (0 == SetThreadAffinityMask(b_Thread_ps->hThread, (DWORD) i_CpuId_t))
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

ThreadID_t ME_Thread_GetCurrentID_t(void)
{
  return GetCurrentThreadId();
}

PlatformError_t ME_Thread_SetName_t(const ThreadHandle_s* i_Thread_ps, const char_t* i_Name_pc)
{
  PlatformError_t v_Error_t = e_PeOk;

  if( (NULL != i_Thread_ps) && (NULL != i_Name_pc))
  {
    if (sizeof(i_Thread_ps->winThreadName_ac) < strlen(i_Name_pc))
    {
      v_Error_t = e_PeNoMemory;
    }
    else
    {
      (void)memset((void*)i_Thread_ps->winThreadName_ac, 0x00, sizeof(i_Thread_ps->winThreadName_ac));
      (void)strncpy_s((void*)i_Thread_ps->winThreadName_ac, sizeof(i_Thread_ps->winThreadName_ac), (void*)i_Name_pc, strlen(i_Name_pc));

      v_Error_t = e_PeOk;
    }

    v_Error_t = e_PeOk;
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_GetName_t(const ThreadHandle_s* i_Thread_ps, char_t* o_Name_pc, sint32_t i_BufferSize_s32)
{
  PlatformError_t v_Error_t = e_PeOk;

  if( (NULL != i_Thread_ps) && (NULL != o_Name_pc))
  {
    if (i_BufferSize_s32 < sizeof(i_Thread_ps->winThreadName_ac))
    {
      v_Error_t = e_PeNoMemory;
    }
    else
    {
      (void)memset(o_Name_pc, 0x00, i_BufferSize_s32);
      (void)strncpy_s(o_Name_pc, i_BufferSize_s32, i_Thread_ps->winThreadName_ac, strlen(i_Thread_ps->winThreadName_ac));
      v_Error_t = e_PeOk;
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_Cancel_t(const ThreadHandle_s* i_Thread_ps)
{
  bool_t v_Result_b;
  sint32_t v_Result_s32;
  DWORD v_ExitCode_dw;

  v_ExitCode_dw = 0;

  //TerminateThread is a dangerous function that should only be used in the most extreme cases.
  //https://msdn.microsoft.com/de-de/library/windows/desktop/ms686717(v=vs.85).aspx
  v_Result_b = TerminateThread(i_Thread_ps->hThread, v_ExitCode_dw);
  if (true == v_Result_b)
  {
    v_Result_s32 = 0;
  }
  else
  {
    v_Result_s32 = -1;
  }
  CloseHandle(i_Thread_ps->hThread);
  return ME_GetPlatformError_t(v_Result_s32);
}

// join thread
PlatformError_t ME_Thread_Join_t(const ThreadHandle_s* i_Thread_ps)
{
  DWORD v_Result_dw;
  sint32_t v_Result_s32 = 0;
  DWORD v_WaitTimeMsec_dw;

  v_WaitTimeMsec_dw = 1000;

  v_Result_dw = WaitForSingleObject(i_Thread_ps->hThread, INFINITE); 
  //v_Result_dw = WaitForSingleObject(i_Thread_ps->hThread, v_WaitTimeMsec_dw); // TODO: decide, which one should be used!
  if (WAIT_FAILED == v_Result_dw)
  {
    v_Result_s32 = -1;
  }
  else
  {
    v_Result_s32 = 0;
  }

  return ME_GetPlatformError_t(v_Result_s32);
}

PlatformError_t ME_Thread_Sleep_t(uint32_t i_MilliSeconds_u32)
{
  Sleep(i_MilliSeconds_u32);

  return e_PeOk;
}

#endif // ME_PLATFORM_WIN // PRQA S 862 // this define decides which platform is defined
