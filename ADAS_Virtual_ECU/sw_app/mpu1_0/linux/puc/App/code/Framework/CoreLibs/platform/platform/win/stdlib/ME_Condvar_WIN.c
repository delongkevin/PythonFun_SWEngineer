// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for WIN only
#ifdef ME_PLATFORM_WIN

// stdlib header include
#include "platform/stdlib/ME_Condvar.h"
#include "platform/stdlib/ME_Mutex.h"
#include "platform/stdlib/ME_Assert.h"

PlatformError_t ME_Condvar_Init_t(Condvar_s* b_Condvar_po)
{
  PlatformError_t v_Error_t         = e_PeOk;

  if(NULL != b_Condvar_po)
  {
    InitializeConditionVariable(&b_Condvar_po->ConditionVar); // Return value: This function does not return a value.
    InitializeCriticalSection(&b_Condvar_po->MEMutex_po.CritSection); // Return value: This function does not return a value.

    v_Error_t = e_PeOk;
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

// Destroy a Condvar
PlatformError_t ME_Condvar_Destroy_t(Condvar_s* b_Condvar_po)
{
  sint32_t        v_Result_s32      = 0;
  PlatformError_t v_Error_t         = e_PeOk;

  if(NULL != b_Condvar_po)
  {
    v_Result_s32 = 0; // TODO  pthread_cond_destroy(&b_Condvar_po->qnxCondvar_po);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

// signal to Condvar
PlatformError_t ME_Condvar_Signal_t(Condvar_s* b_Condvar_po)
{
  PlatformError_t v_Error_t         = e_PeOk;

  if(NULL != b_Condvar_po)
  {
    WakeConditionVariable(&b_Condvar_po->ConditionVar); // Return value: This function does not return a value.
    v_Error_t = e_PeOk;
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// signal a broadcast to all waiting threads
PlatformError_t ME_Condvar_Broadcast_t(Condvar_s* b_Condvar_po)
{
  PlatformError_t v_Error_t         = e_PeOk;

  if(NULL != b_Condvar_po)
  {
    WakeAllConditionVariable(&b_Condvar_po->ConditionVar); // Return value: This function does not return a value.
    v_Error_t = e_PeOk;
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// Wait on a Condvar
PlatformError_t ME_Condvar_Wait_t(Condvar_s* b_Condvar_po)
{
  sint32_t        v_Result_s32      = 0;
  PlatformError_t v_Error_t         = e_PeOk;

  if(NULL != b_Condvar_po)
  {
    v_Result_s32 = SleepConditionVariableCS(&b_Condvar_po->ConditionVar, &b_Condvar_po->MEMutex_po.CritSection, INFINITE);
    if(0 != v_Result_s32)
    {
      v_Error_t = e_PeOk;
    }
    else
    {
      v_Error_t = e_PeFault;
      // TODO: call GetLastError.
    }
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

#endif // ME_PLATFORM_WIN // PRQA S 862 // this define decides which platform is defined
