//--------------------------------------------------------------------------
/// @file ME_Mutex_QNX.c
/// @brief Qnx implementation for standard-library Mutex
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
#include "platform/stdlib/ME_Mutex.h"
#include "platform/stdlib/ME_Assert.h"

PlatformError_t ME_Mutex_Init_t(Mutex_s* b_Mutex_po, bool_t i_Shared_b)
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if(NULL != b_Mutex_po)
  {
    sint32_t v_Result_s32;
    pthread_mutexattr_t v_qnxMutexAttributes_t;

    // First initialize mutex attributes.
    v_Result_s32 = pthread_mutexattr_init(&v_qnxMutexAttributes_t);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);

    if(e_PeOk == v_Error_t)
    {
      // Now set attribute arguments accordingly
      // Don't expect these calls to fail. So no error checking.

      // to avoid self-blocking we use a recursive mutex.
      // Remember : unlock as often as you locked!
      pthread_mutexattr_settype(&v_qnxMutexAttributes_t, PTHREAD_MUTEX_RECURSIVE);

      if(true == i_Shared_b)
      {
        // any thread that has access to the memory where the mutex is allocated can operate on it,
        // even if the mutex is allocated in memory that's shared by multiple processes.
        pthread_mutexattr_setpshared(&v_qnxMutexAttributes_t, PTHREAD_PROCESS_SHARED);
      }

      // Last step is to initialize the mutex itself.
      v_Result_s32 = pthread_mutex_init(&b_Mutex_po->qnxMutex_t, &v_qnxMutexAttributes_t);
      v_Error_t = ME_GetPlatformError_t(v_Result_s32);
    }
  }

  return v_Error_t;
}

PlatformError_t ME_Mutex_Lock_t(Mutex_s* i_Mutex_po)
{
  PlatformError_t v_Error_t;

  if(NULL != i_Mutex_po)
  {
    sint32_t v_Result_s32 = pthread_mutex_lock(&i_Mutex_po->qnxMutex_t);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);

    Assert(v_Error_t == e_PeOk);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Mutex_TryLock_t(Mutex_s* i_Mutex_po)
{
  PlatformError_t v_Error_t;

  if(NULL != i_Mutex_po)
  {
    sint32_t v_Result_s32 = pthread_mutex_trylock(&i_Mutex_po->qnxMutex_t);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Mutex_UnLock_t(Mutex_s* i_Mutex_po)
{
  PlatformError_t v_Error_t;

  if(NULL != i_Mutex_po)
  {
    sint32_t v_Result_s32 = pthread_mutex_unlock(&i_Mutex_po->qnxMutex_t);

    v_Error_t = ME_GetPlatformError_t(v_Result_s32);

    Assert(v_Error_t == e_PeOk);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Mutex_Destroy_t(Mutex_s* b_Mutex_po)
{
  PlatformError_t v_Error_t;

  if(NULL != b_Mutex_po)
  {
    sint32_t v_Result_s32 = pthread_mutex_destroy(&b_Mutex_po->qnxMutex_t);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

#endif // ME_PLATFORM_QNX
