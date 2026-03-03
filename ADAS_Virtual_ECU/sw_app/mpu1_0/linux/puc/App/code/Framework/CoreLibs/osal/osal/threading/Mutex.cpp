//--------------------------------------------------------------------------
/// @file Thread.cpp
/// @brief Generic Thread class implementation based on platforms stdlib
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#include "Mutex.h"


namespace osal
{

Mutex::Mutex(bool_t i_IsFree_b, bool_t i_IsProcessShared_b)
  : mutex_s()
  , ownerID_t(ME_INVALID_PROCESS_ID)
  , lockCount_u8(0U)
{
  init_b(i_IsFree_b, i_IsProcessShared_b);
}

Mutex::~Mutex()
{
}

bool_t Mutex::init_b(bool_t i_IsFree_b, bool_t i_IsProcessShared_b)
{
  PlatformError_t v_Error_t = ME_Mutex_Init_t(&mutex_s, i_IsProcessShared_b);
  Assert(e_PeOk == v_Error_t);

  if (false == i_IsFree_b)
  {
    v_Error_t = ME_Mutex_Lock_t(&mutex_s);
    Assert(e_PeOk == v_Error_t);
  }

  return true;
}

bool_t Mutex::deInit_b()
{
  ME_Mutex_Destroy_t(&mutex_s);

  return true;
}

bool_t Mutex::take_b(bool_t i_WaitForEver_b)
{
  PlatformError_t v_Error_t = e_PeInvalid;
  bool_t v_HasLock_b = false;

  if(ownerID_t != ME_Thread_GetCurrentID_t())
  {
    if(true == i_WaitForEver_b)
    {
      v_Error_t = ME_Mutex_Lock_t(&mutex_s);
    }
    else
    {
      v_Error_t = ME_Mutex_TryLock_t(&mutex_s);
    }

    if((v_Error_t == e_PeOk) && (ownerID_t == ME_INVALID_PROCESS_ID))
    {
      v_HasLock_b = true;
      ownerID_t = ME_Thread_GetCurrentID_t();
      lockCount_u8 = 0;
    }
  }
  else
  {
    v_HasLock_b = true;
    lockCount_u8++;
  }

  return v_HasLock_b;
}

/// @brief free the Mutex
void Mutex::give_v()
{
  PlatformError_t v_Error_t = e_PeOk;
  if((ownerID_t == ME_Thread_GetCurrentID_t()) && (lockCount_u8 == 0))
  {
    v_Error_t = e_PeInvalid;
    ownerID_t = ME_INVALID_PROCESS_ID;
    v_Error_t = ME_Mutex_UnLock_t(&mutex_s);
  }
  else
  {
    lockCount_u8--;
  }

  Assert(e_PeOk == v_Error_t);
}

} // namespace osal

