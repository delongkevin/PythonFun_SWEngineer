//--------------------------------------------------------------------------
/// @file BinarySemaphore.h
/// @brief BinarySemaphore implementation
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

// PRQA S 4631 EOF // part of RAII design

#include "BinarySemaphore.h"

namespace osal
{

BinarySemaphore::BinarySemaphore(bool_t i_IsLocked_b, bool_t i_IsProcessShared_b)
  : condVar_s()
  , counter_u32(1)
{
  PlatformError_t v_Success_b;

  v_Success_b = ME_Condvar_Init_t(&condVar_s);
  Assert(v_Success_b == e_PeOk);

  v_Success_b = ME_Mutex_Init_t(&condVar_s.MEMutex_po, i_IsProcessShared_b);
  Assert(v_Success_b == e_PeOk);

  // destruction of attributes not needed

  // reset the counter if needed
  if(false == i_IsLocked_b)
  {
    counter_u32 = 0;
  }
}

BinarySemaphore::~BinarySemaphore()
{
  PlatformError_t v_Success_b;

  v_Success_b = ME_Mutex_Destroy_t(&condVar_s.MEMutex_po);
  Assert(v_Success_b == e_PeOk);

  v_Success_b = ME_Condvar_Destroy_t(&condVar_s);
  Assert(v_Success_b == e_PeOk);
}

// lock the semaphore.
bool_t BinarySemaphore::take_b(bool_t i_WaitForEver_b)
{
  PlatformError_t v_Success_b;
  bool_t v_Ret_b = true;

  v_Success_b = ME_Mutex_Lock_t(&condVar_s.MEMutex_po);
  Assert(v_Success_b == e_PeOk);

  if(1 == counter_u32) // if semaphore is free
  {
    counter_u32 = 0; // semaphore is locked now
  }
  else if (false == i_WaitForEver_b)
  {
    // return false, as semaphore is locked, but we are not allowed to wait
    v_Ret_b = false;
  }
  else
  {
    while (0 == counter_u32) // stay here if any other waiting thread gained lock before me
    //while not needed on QNX, but needed for Windows :-)
    {
      v_Success_b = ME_Condvar_Wait_t(&condVar_s);
      Assert(v_Success_b == e_PeOk);
    }

    Assert(1 == counter_u32);

    counter_u32 = 0; // semaphore is locked now
  }

  v_Success_b = ME_Mutex_UnLock_t(&condVar_s.MEMutex_po);
  Assert(v_Success_b == e_PeOk);

  return v_Ret_b;
}

// unlock the semaphore.
void BinarySemaphore::give_v(void)
{
  PlatformError_t v_Success_b;

  v_Success_b = ME_Mutex_Lock_t(&condVar_s.MEMutex_po);
  Assert(v_Success_b == e_PeOk);

  counter_u32 = 1; // semaphore is free now

  v_Success_b = ME_Mutex_UnLock_t(&condVar_s.MEMutex_po);
  Assert(v_Success_b == e_PeOk);

  // signal waiting thread after unlocking the mutex
  v_Success_b = ME_Condvar_Signal_t(&condVar_s);
  Assert(v_Success_b == e_PeOk);

  return;
}

} // namespace osal
