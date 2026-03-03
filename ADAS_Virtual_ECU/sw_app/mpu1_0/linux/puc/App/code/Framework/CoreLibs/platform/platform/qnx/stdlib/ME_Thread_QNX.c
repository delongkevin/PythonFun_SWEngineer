//--------------------------------------------------------------------------
/// @file ME_Thread_QNX.c
/// @brief Qnx implementation for standard-library Thread
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

// compile this file for QNX only
#ifdef ME_PLATFORM_QNX

// stdlib header include
#include "platform/stdlib/ME_Thread.h"
#include "platform/stdlib/ME_Mutex.h"
#include "platform/stdlib/ME_Condvar.h"

#include <sys/neutrino.h> // needed


const size_t ME_Thread_C_DefaultStackSize_t = 0;

// enum for priority values (else we can't use switch-case)
enum ThreadPriorityValues_e
{
  e_PriorityIdleValue = 1,
  e_PriorityLowValue = 5,
  e_PriorityNormalValue = 11,
  e_PriorityBelowHighValue = 12,
  e_PriorityHighValue = 13,
  e_PriorityAboveHighValue = 14,
  e_PriorityBelowRealtimeValue = 15,
  e_PriorityRealtimeValue = 16
} ;

static PlatformError_t      ME_Thread_f_Attribute_Init_t(ThreadHandle_s* b_Thread_ps);
static sint32_t             ME_Thread_f_GetPrioFromPlatformPrio_s32(ME_Thread_Priority_t i_Priority_e);
static ME_Thread_Priority_t ME_Thread_f_GetPlatformPrio_t(sint32_t i_Priority_s32);

// Internal Helper functions for attribute initialization
static PlatformError_t ME_Thread_f_Attribute_Init_t(ThreadHandle_s* b_Thread_ps)
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;

  if(NULL != b_Thread_ps)
  {
    v_Result_s32 = pthread_attr_init(&b_Thread_ps->qnxThreadAttributes_o);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

static sint32_t ME_Thread_f_GetPrioFromPlatformPrio_s32(ME_Thread_Priority_t i_Priority_e)
{
  sint32_t v_Priority_s32;

  switch(i_Priority_e)
  {
    case e_PriorityIdle:
      v_Priority_s32 = e_PriorityIdleValue;
      break;
    case e_PriorityLow:
      v_Priority_s32 = e_PriorityLowValue;
      break;
    case e_PriorityNormal:
      v_Priority_s32 = e_PriorityNormalValue;
      break;
    case e_PriorityBelowHigh:
      v_Priority_s32 = e_PriorityBelowHighValue;
      break;
    case e_PriorityHigh:
      v_Priority_s32 = e_PriorityHighValue;
      break;
    case e_PriorityAboveHigh:
      v_Priority_s32 = e_PriorityAboveHighValue;
      break;
    case e_PriorityBelowRealtime:
      v_Priority_s32 = e_PriorityBelowRealtimeValue;
      break;
    case e_PriorityRealtime:
      v_Priority_s32 = e_PriorityRealtimeValue;
      break;
    default:
      v_Priority_s32 = e_PriorityNormalValue;
      break;
  }

  return v_Priority_s32;
}


static ME_Thread_Priority_t ME_Thread_f_GetPlatformPrio_t(sint32_t i_Priority_s32)
{
  ME_Thread_Priority_t v_Priority_e;

  switch(i_Priority_s32)
  {
    case e_PriorityIdleValue:
      v_Priority_e = e_PriorityIdle;
      break;
    case e_PriorityLowValue:
      v_Priority_e = e_PriorityLow;
      break;
    case e_PriorityNormalValue:
      v_Priority_e = e_PriorityNormal;
      break;
    case e_PriorityBelowHighValue:
      v_Priority_e = e_PriorityBelowHigh;
      break;
    case e_PriorityHighValue:
      v_Priority_e = e_PriorityHigh;
      break;
    case e_PriorityAboveHighValue:
      v_Priority_e = e_PriorityAboveHigh;
      break;
    case e_PriorityBelowRealtimeValue:
      v_Priority_e = e_PriorityBelowRealtime;
      break;
    case e_PriorityRealtimeValue:
      v_Priority_e = e_PriorityRealtime;
      break;
    default:
      v_Priority_e = e_PriorityNormal;
      break;
  }

  return v_Priority_e;
}

PlatformError_t ME_Thread_Attribute_SetInheritedScheduling_t(ThreadHandle_s* b_Thread_ps, bool_t i_Inherited_b)
{
  PlatformError_t v_Error_t;

  if(NULL != b_Thread_ps)
  {
    sint32_t v_Result_s32;
    if (true == i_Inherited_b)
    {
      v_Result_s32 = pthread_attr_setinheritsched(&b_Thread_ps->qnxThreadAttributes_o, PTHREAD_INHERIT_SCHED);
    }
    else
    {
      v_Result_s32 = pthread_attr_setinheritsched(&b_Thread_ps->qnxThreadAttributes_o, PTHREAD_EXPLICIT_SCHED);
    }
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_Attribute_SetSchedulingPolicy_t(ThreadHandle_s* b_Thread_ps, SchedulingPolicy_t i_SchedulingPolicy_t)
{
  PlatformError_t v_Error_t;
  sint32_t        v_Result_s32 = 0;
  sint32_t        v_SchedPolicy_s32;

  if(NULL != b_Thread_ps)
  {
    switch (i_SchedulingPolicy_t)
    {
      case e_SpFifo:        v_SchedPolicy_s32 = SCHED_FIFO; break;
      case e_SpRoundRobin:  v_SchedPolicy_s32 = SCHED_RR;   break;
      default :             v_Result_s32      = -1;         break;  // set invalid result if mapping doesn't exist
    }

    if (-1 != v_Result_s32)
    {
      v_Result_s32 = pthread_attr_setschedpolicy(&b_Thread_ps->qnxThreadAttributes_o, v_SchedPolicy_s32);
      v_Error_t = ME_GetPlatformError_t(v_Result_s32);
    }
    else
    {
      v_Error_t = e_PeInvalid;
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_Attribute_SetPriority_e(ThreadHandle_s* b_Thread_ps, ME_Thread_Priority_t i_Priority_e)
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;

  if(NULL != b_Thread_ps)
  {
    sint32_t i_Priority_s32;
    i_Priority_s32 = ME_Thread_f_GetPrioFromPlatformPrio_s32(i_Priority_e);
    b_Thread_ps->qnxSchedulingParameters.sched_priority = i_Priority_s32;

    v_Result_s32 = pthread_attr_setschedparam(&b_Thread_ps->qnxThreadAttributes_o, &b_Thread_ps->qnxSchedulingParameters);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_Create_t(ThreadHandle_s* b_Thread_ps, ThreadFunc_t i_ThreadFunc_pv, void* i_ThreadArgs_pv, size_t i_StackSize_t)
{
  PlatformError_t v_Error_t;

  if (NULL == b_Thread_ps)
  {
#ifdef VERBOSE
    // TODO: remove here?
    ME_Debugger_F_Printf_v("ME_Thread_Create_t - Invalid Thread Handle\n");
#endif
    v_Error_t = e_PeInvalid;
  }
  else
  {
    ME_Condvar_Init_t(&b_Thread_ps->qnxSuspendCondvar_t);

    // init default thread attributes, we have no default initialization attribute values right now
    v_Error_t = ME_Thread_f_Attribute_Init_t(b_Thread_ps);

    if(ME_Thread_C_DefaultStackSize_t != i_StackSize_t)
    {
      sint32_t v_Result_s32;
      v_Result_s32 = pthread_attr_setstacksize(&b_Thread_ps->qnxThreadAttributes_o, i_StackSize_t);
      v_Error_t    = ME_GetPlatformError_t(v_Result_s32);
    }

    if (e_PeOk == v_Error_t)
    {
      sint32_t v_Result_s32;
      v_Result_s32 = pthread_create(&b_Thread_ps->ThreadId, &b_Thread_ps->qnxThreadAttributes_o, i_ThreadFunc_pv, i_ThreadArgs_pv);
      v_Error_t    = ME_GetPlatformError_t(v_Result_s32);
    }
    else
    {
#ifdef VERBOSE
      // TODO: remove here?
      ME_Debugger_F_Printf_v("ME_Thread_Create_t - Error Setting Thread Attributes\n");
#endif
    }
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_Suspend_t(ThreadHandle_s* b_Thread_ps)
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if(b_Thread_ps != NULL)
  {
    ME_Mutex_Lock_t(&b_Thread_ps->qnxSuspendCondvar_t.MEMutex_po);
    b_Thread_ps->qnxSuspendFlag_b = true;
    ME_Mutex_UnLock_t(&b_Thread_ps->qnxSuspendCondvar_t.MEMutex_po);

    v_Error_t = e_PeOk;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_Resume_t(ThreadHandle_s* b_Thread_ps)
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if(b_Thread_ps != NULL)
  {
    ME_Mutex_Lock_t(&b_Thread_ps->qnxSuspendCondvar_t.MEMutex_po);
    b_Thread_ps->qnxSuspendFlag_b = false;
    ME_Mutex_UnLock_t(&b_Thread_ps->qnxSuspendCondvar_t.MEMutex_po);

    ME_Condvar_Broadcast_t(&b_Thread_ps->qnxSuspendCondvar_t);

    v_Error_t = e_PeOk;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_CheckSuspend_t(ThreadHandle_s* b_Thread_ps)
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if(b_Thread_ps != NULL)
  {
    ME_Mutex_Lock_t(&b_Thread_ps->qnxSuspendCondvar_t.MEMutex_po);
    while(b_Thread_ps->qnxSuspendFlag_b != false)
    {
      ME_Condvar_Wait_t(&b_Thread_ps->qnxSuspendCondvar_t);
    }
    ME_Mutex_UnLock_t(&b_Thread_ps->qnxSuspendCondvar_t.MEMutex_po);

    v_Error_t = e_PeOk;
  }

  return v_Error_t;
}

// QNX: Threads can have a scheduling priority ranging from 1 to 255 (the highest priority),
PlatformError_t ME_Thread_SetPriority_t(const ThreadHandle_s* b_Thread_ps, ME_Thread_Priority_t i_Priority_e)
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;

  if(NULL != b_Thread_ps)
  {
    sint32_t i_Priority_s32;

    i_Priority_s32 = ME_Thread_f_GetPrioFromPlatformPrio_s32(i_Priority_e);

    v_Result_s32 = pthread_setschedprio(b_Thread_ps->ThreadId, i_Priority_s32);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_GetPriority_t(const ThreadHandle_s* b_Thread_ps, ME_Thread_Priority_t* b_Priority_e)
{
  struct sched_param v_Param_s;
  sint32_t v_Policy_s32;
  sint32_t v_Result_s32;

  PlatformError_t v_Error_t;

  if((NULL != b_Priority_e) && (NULL != b_Thread_ps))
  {
    v_Result_s32 = pthread_getschedparam(b_Thread_ps->ThreadId, &v_Policy_s32, &v_Param_s);

    *b_Priority_e = ME_Thread_f_GetPlatformPrio_t(v_Param_s.sched_priority);

    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_SetCpuAffinity_t(const ThreadHandle_s* b_Thread_ps, CpuId_t i_CpuId_t)
{
  PlatformError_t v_Error_t;

  if(NULL != b_Thread_ps)
  {
    uint32_t v_Runmask_u32    = i_CpuId_t; // using unsigned integer is important here :O

#ifdef VERBOSE
    // TODO: remove here?
    ME_Debugger_F_Printf_v("ME_Thread_SetCpuAffinity_t Setting runmask: %d\n", v_Runmask_u32);
#endif

    // ThreadCtl(_NTO_TCTL_RUNMASK, data)
    // Set the processor affinity for the calling thread in a multiprocessor system.
    // The data is the runmask, cast to be a pointer (i.e., (void *) runmask).
    // Each set bit in runmask represents a processor that the thread can run on.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
    if (-1 == ThreadCtl(_NTO_TCTL_RUNMASK, (void *)v_Runmask_u32)) // PRQA S 306 // this is defined by QNX API ;-(
    {
#ifdef VERBOSE
      // TODO: remove here?
      ME_Debugger_F_Printf_v("ME_Thread_SetCpuAffinity_t failed. CpuID: %d \n", (uint32_t)i_CpuId_t);
#endif
      v_Error_t = ME_GetPlatformError_t((sint32_t)(-1));
    }
    else
    {
      v_Error_t = e_PeOk;
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }
#pragma GCC diagnostic pop

  return v_Error_t;
}

ThreadID_t ME_Thread_GetCurrentID_t(void)
{
  return pthread_self();
}

PlatformError_t ME_Thread_SetName_t(const ThreadHandle_s* i_Thread_ps, const char_t* i_Name_pc)
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;

  if(NULL != i_Name_pc)
  {
    if(i_Thread_ps != NULL)
    {
      v_Result_s32 = pthread_setname_np(i_Thread_ps->ThreadId, i_Name_pc);
    }
    else
    {
      v_Result_s32 = pthread_setname_np(0, i_Name_pc);
    }

    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_GetName_t(const ThreadHandle_s* i_Thread_ps, char_t* o_Name_pc, sint32_t i_BufferSize_s32)
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;

  if(NULL != i_Thread_ps)
  {
    v_Result_s32 = pthread_getname_np(i_Thread_ps->ThreadId, o_Name_pc, i_BufferSize_s32);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

// cancel thread
PlatformError_t ME_Thread_Cancel_t(const ThreadHandle_s* i_Thread_ps)
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;

  if(NULL != i_Thread_ps)
  {
    v_Result_s32 = pthread_cancel(i_Thread_ps->ThreadId);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);

    if(v_Error_t == e_PeNoSuchProcess)
    {
      // Error "no such process" is valid in this case
      v_Error_t = e_PeOk;
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

// join thread
PlatformError_t ME_Thread_Join_t(const ThreadHandle_s* i_Thread_ps)
{
  PlatformError_t v_Error_t;
  sint32_t v_Result_s32;
  void* v_RetVal_pv;

  if(NULL != i_Thread_ps)
  {
    v_Result_s32 = pthread_join(i_Thread_ps->ThreadId, &v_RetVal_pv);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_Sleep_t(uint32_t i_MilliSeconds_u32)
{
  struct timespec v_TimeSpec_s;
  sint32_t v_Result_s32;

  v_TimeSpec_s.tv_sec  = (sint32_t)(i_MilliSeconds_u32 / 1000);
  v_TimeSpec_s.tv_nsec = (sint32_t)(i_MilliSeconds_u32 % 1000) * 1000 * 1000;

  v_Result_s32 = nanosleep(&v_TimeSpec_s, NULL);

  return ME_GetPlatformError_t(v_Result_s32);
}

#endif // ME_PLATFORM_QNX
