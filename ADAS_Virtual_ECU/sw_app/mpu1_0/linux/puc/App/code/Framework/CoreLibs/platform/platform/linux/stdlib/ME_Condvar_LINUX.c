// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for Linux only
#ifdef ME_PLATFORM_LINUX

// stdlib header include
#include "platform/stdlib/ME_Condvar.h"
#include "platform/stdlib/ME_Mutex.h"

#include <pthread.h>

PlatformError_t ME_Condvar_Init_t(Condvar_s* b_Condvar_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  if(NULL != b_Condvar_po)
  {
    v_Result_s32 = pthread_cond_init(&b_Condvar_po->qnxCondvar_po, &b_Condvar_po->qnxCondvarAttributes);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
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
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  if(NULL != b_Condvar_po)
  {
    v_Result_s32 = pthread_cond_destroy(&b_Condvar_po->qnxCondvar_po);
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
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  if(NULL != b_Condvar_po)
  {
    v_Result_s32 = pthread_cond_signal(&b_Condvar_po->qnxCondvar_po);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
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
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  if(NULL != b_Condvar_po)
  {
    v_Result_s32 = pthread_cond_broadcast(&b_Condvar_po->qnxCondvar_po);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
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
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  if(NULL != b_Condvar_po)
  {
    /* The pthread_cond_wait() function blocks the calling thread on the condition variable cond, and unlocks the associated mutex mutex. */
    v_Result_s32 = pthread_cond_wait(&b_Condvar_po->qnxCondvar_po, &b_Condvar_po->MEMutex_po.qnxMutex_o);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

#endif // ME_PLATFORM_LINUX // PRQA S 862 // this define decides which platform is defined
