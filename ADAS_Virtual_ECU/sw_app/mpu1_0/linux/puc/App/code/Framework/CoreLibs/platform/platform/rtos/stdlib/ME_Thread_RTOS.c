/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file ME_Thread_AUTOSAR.c
/// @brief AUTOSAR implementation for Thread
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

// compile this file for RTOS only
#ifdef ME_PLATFORM_RTOS

// stdlib header include
#include "platform/stdlib/ME_Thread.h"

//#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <timers.h>

const size_t ME_Thread_C_DefaultStackSize_t = 256U;

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

static PlatformError_t      ME_Thread_Attribute_Init_t(ThreadHandle_s* b_Thread_ps);
static sint32_t             ME_Thread_RTOS_GetPrioFromPlatformPrio(ME_Thread_Priority_t i_Priority_e);
static ME_Thread_Priority_t ME_Thread_RTOS_GetPlatformPrio(sint32_t i_Priority_s32);

// Internal Helper functions for attribute initialization
static PlatformError_t ME_Thread_Attribute_Init_t(ThreadHandle_s* b_Thread_ps)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

static sint32_t ME_Thread_RTOS_GetPrioFromPlatformPrio(ME_Thread_Priority_t i_Priority_e)
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


static ME_Thread_Priority_t ME_Thread_RTOS_GetPlatformPrio(sint32_t i_Priority_s32)
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
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Thread_Attribute_SetSchedulingPolicy_t(ThreadHandle_s* b_Thread_ps, SchedulingPolicy_t i_SchedulingPolicy_e)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Thread_Suspend_t(ThreadHandle_s* b_Thread_ps)
{
  PlatformError_t v_Error_t = e_PeOk;

  vTaskSuspend(b_Thread_ps->handle_t);

  return v_Error_t;
}

PlatformError_t ME_Thread_Resume_t(ThreadHandle_s* b_Thread_ps)
{
  PlatformError_t v_Error_t = e_PeOk;

  vTaskResume(b_Thread_ps->handle_t);

  return v_Error_t;
}

PlatformError_t ME_Thread_CheckSuspend_t(ThreadHandle_s* b_Thread_ps)
{
  PlatformError_t v_Error_t = e_PeFault;

  if(b_Thread_ps->handle_t != NULL)
  {
    if(eSuspended == eTaskGetState(b_Thread_ps->handle_t))
    {
      v_Error_t = e_PeOk;
    }
  }

  return v_Error_t;
}

PlatformError_t ME_Thread_Attribute_SetPriority_e(ThreadHandle_s* b_Thread_ps, ME_Thread_Priority_t i_Priority_e)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Thread_Create_t(ThreadHandle_s* b_Thread_ps, ThreadFunc_t i_ThreadFunc_pv, void* i_ThreadArgs_pv, size_t i_StackSize_t)
{
  PlatformError_t v_Error_t = e_PeOk;

  if(pdPASS != xTaskCreate((TaskFunction_t)i_ThreadFunc_pv, NULL, (i_StackSize_t / sizeof(configSTACK_DEPTH_TYPE)), i_ThreadArgs_pv, 0, &b_Thread_ps->handle_t))
  {
    v_Error_t = e_PeFault;
  }

  if(b_Thread_ps->handle_t == NULL)
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// QNX: Threads can have a scheduling priority ranging from 1 to 255 (the highest priority),
PlatformError_t ME_Thread_SetPriority_t(const ThreadHandle_s* b_Thread_ps, ME_Thread_Priority_t i_Priority_e)
{
#if 0
  PlatformError_t v_Error_t = e_PeInvalid;

  if(b_Thread_ps != NULL)
  {
    if((eReady == eTaskGetState(b_Thread_ps->handle_t)) || (eRunning == eTaskGetState(b_Thread_ps->handle_t)))
    {
      if(i_Priority_e < configMAX_PRIORITIES)
      {
        vTaskPrioritySet(b_Thread_ps->handle_t, i_Priority_e);
      }
      else
      {
        vTaskPrioritySet(b_Thread_ps->handle_t, configMAX_PRIORITIES - 1);
      }

      v_Error_t = e_PeOk;
    }
  }

  return v_Error_t;
#else
  return e_PeOk;
#endif

}

PlatformError_t ME_Thread_GetPriority_t(const ThreadHandle_s* b_Thread_ps, ME_Thread_Priority_t* b_Priority_e)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Thread_SetCpuAffinity_t(const ThreadHandle_s* b_Thread_ps, CpuId_t i_CpuId_t)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

ThreadID_t ME_Thread_GetCurrentID_t(void)
{
  return 0;
}

PlatformError_t ME_Thread_SetName_t(const ThreadHandle_s* i_Thread_ps, const char_t* i_Name_pc)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Thread_GetName_t(const ThreadHandle_s* i_Thread_ps, char_t* o_Name_pc, sint32_t i_BufferSize_s32)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// cancel thread
PlatformError_t ME_Thread_Cancel_t(const ThreadHandle_s* i_Thread_ps)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// join thread
PlatformError_t ME_Thread_Join_t(const ThreadHandle_s* i_Thread_ps)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Thread_Sleep_t(uint32_t i_MilliSeconds_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  
  vTaskDelay((i_MilliSeconds_u32 * 250) / configTICK_RATE_HZ);

  return v_Error_t;
}

#endif // ME_PLATFORM_RTOS // PRQA S 862 // this define decides which platform is defined
