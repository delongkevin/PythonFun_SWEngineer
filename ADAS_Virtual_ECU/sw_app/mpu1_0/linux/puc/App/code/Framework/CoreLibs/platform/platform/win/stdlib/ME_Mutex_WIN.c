//--------------------------------------------------------------------------
/// @file ME_Mutex_WIN.c
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

// compile this file for WIN only
#ifdef ME_PLATFORM_WIN

// stdlib header include
#include "platform/stdlib/ME_Mutex.h"


PlatformError_t ME_Mutex_Init_t(Mutex_s* b_Mutex_po, bool_t i_Shared_b)
{
  InitializeCriticalSection(&b_Mutex_po->CritSection); // Return value: This function does not return a value.
  
  return e_PeOk;
}

PlatformError_t ME_Mutex_Lock_t(Mutex_s* i_Mutex_po)
{
  EnterCriticalSection(&i_Mutex_po->CritSection); // Return value: This function does not return a value.
  return e_PeOk;
}

PlatformError_t ME_Mutex_TryLock_t(Mutex_s* i_Mutex_po)
{
  PlatformError_t v_Error_t = e_PeOk;
  bool_t          v_Ret_b;

  v_Ret_b = TryEnterCriticalSection(&i_Mutex_po->CritSection); // Return value: This function does not return a value.

  if (true == v_Ret_b)
  {
    // If another thread already owns the critical section, the return value is zero.
    v_Error_t = e_PeOk;
  }
  else
  {
    // If the critical section is successfully entered or the current thread already owns the critical section, the return value is nonzero.
    v_Error_t = e_PeBusy;
  }

  return v_Error_t;
}

PlatformError_t ME_Mutex_UnLock_t(Mutex_s* i_Mutex_po)
{
  LeaveCriticalSection(&i_Mutex_po->CritSection); // Return value: This function does not return a value.
  return e_PeOk;
}

PlatformError_t ME_Mutex_Destroy_t(Mutex_s* b_Mutex_po)
{
  DeleteCriticalSection(&b_Mutex_po->CritSection); // Return value: This function does not return a value.
  return e_PeOk;
}

#endif // ME_PLATFORM_WIN // PRQA S 862 // this define decides which platform is defined
