// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for Linux only
#ifdef ME_PLATFORM_LINUX

// stdlib header include
#include "platform/stdlib/ME_Thread.h"
#include "platform/stdlib/ME_Debugger.h"
#include "platform/stdlib/ME_Assert.h"
#include <errno.h>

#include <sched.h>
#include <syscall.h>
#include <sys/types.h>
#include <unistd.h>


const size_t ME_Thread_C_MinStackSize_t = 16384;
const size_t ME_Thread_C_DefaultStackSize_t = 16384;


// enum for priority values (else we can't use switch-case)
enum ThreadPriorityValues_e
{
  e_PriorityIdleValue = 19,
  e_PriorityLowValue = 18,
  e_PriorityNormalValue = 17,
  e_PriorityBelowHighValue = 16,
  e_PriorityHighValue = 15,
  e_PriorityAboveHighValue = 14,
  e_PriorityBelowRealtimeValue = 13,
  e_PriorityRealtimeValue = 12
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
  sint32_t v_Result_s32 = 0;

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
    // init default thread attributes, we have no default initialization attribute values right now
    v_Error_t = ME_Thread_f_Attribute_Init_t(b_Thread_ps);

    if(ME_Thread_C_DefaultStackSize_t != i_StackSize_t)
    {
      if((i_StackSize_t < ME_Thread_C_MinStackSize_t))
      {
        i_StackSize_t = ME_Thread_C_DefaultStackSize_t;
      }
      else if((i_StackSize_t % getpagesize() != 0))
      {
        i_StackSize_t = ((i_StackSize_t % getpagesize()) + 1) * getpagesize();
      }
      else
      {
        // do nothing
      }

      v_Result_s32 = pthread_attr_setstacksize(&b_Thread_ps->qnxThreadAttributes_o, i_StackSize_t);
      v_Error_t    = ME_GetPlatformError_t(v_Result_s32);
    }

    if (e_PeOk == v_Error_t)
    {
      sint32_t v_Result_s32;

      v_Result_s32 = pthread_attr_setschedpolicy(&b_Thread_ps->qnxThreadAttributes_o, SCHED_RR);

      if(v_Result_s32 == 0)
      {
        v_Result_s32 = pthread_create(&b_Thread_ps->ThreadId, &b_Thread_ps->qnxThreadAttributes_o, i_ThreadFunc_pv, i_ThreadArgs_pv);
      }
    }
    else
    {
      // TODO: remove here?
      ME_Debugger_F_Printf_v("ME_Thread_Create_t - Error Setting Thread Attributes\n");
    }
  }

  v_Error_t = ME_GetPlatformError_t(v_Result_s32);

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
    v_Error_t = e_PeOk;
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_CheckSuspend_t(ThreadHandle_s* b_Thread_ps)
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if(b_Thread_ps != NULL)
  {
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
    sint32_t v_Policy_s32 = -1;
    struct sched_param v_SchedParam_s;

    i_Priority_s32 = ME_Thread_f_GetPrioFromPlatformPrio_s32(i_Priority_e);

    pthread_attr_getschedpolicy(&b_Thread_ps->qnxThreadAttributes_o, &v_Policy_s32);

    v_SchedParam_s.sched_priority = i_Priority_s32;

    v_Result_s32 = pthread_setschedparam(b_Thread_ps->ThreadId, v_Policy_s32, &v_SchedParam_s);

    //v_Result_s32 = pthread_setschedprio(b_Thread_ps->ThreadId, i_Priority_s32);
    v_Error_t    = ME_GetPlatformError_t(v_Result_s32);

    if (v_Error_t != e_PeOk)
    {
      ME_Debugger_F_Printf_v("ME_Thread_SetPriority_t failed, prio : %d, thread id: %d\n", i_Priority_s32, b_Thread_ps->ThreadId);
    }
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
  sint32_t v_Error_s32 = 0;
  if(NULL != b_Thread_ps)
  {
    uint32_t v_Runmask_u32 = i_CpuId_t; // using unsigned integer is important here :O
    cpu_set_t cpuSet;

    CPU_ZERO(&cpuSet);

//    for(int i = 0; i < 32; i++)
//    {
//      if(((1 << i) & v_Runmask_u32) == 1)
//      {
//        CPU_SET(i + 1, &cpuSet);
//      }
//    }

    CPU_SET(1, &cpuSet);

    v_Error_s32 = pthread_setaffinity_np(b_Thread_ps->ThreadId, sizeof(cpu_set_t), &cpuSet);

    if(v_Error_s32 != 0)
    {
      ME_Debugger_F_Printf_v("ME_Thread_SetAffinity_t failed, thread id: %d\n", b_Thread_ps->ThreadId);
    }
  }

  v_Error_t = ME_GetPlatformError_t(v_Error_s32);

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

  if(NULL != i_Thread_ps)
  {
    v_Result_s32 = pthread_setname_np(i_Thread_ps->ThreadId, i_Name_pc);
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

  if(NULL != i_Thread_ps)
  {
    v_Result_s32 = pthread_join(i_Thread_ps->ThreadId, NULL);
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

#endif // ME_PLATFORM_LINUX // PRQA S 862 // this define decides which platform is defined
