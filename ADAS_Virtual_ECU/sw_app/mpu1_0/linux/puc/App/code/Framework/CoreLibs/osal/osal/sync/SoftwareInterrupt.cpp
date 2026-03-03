//--------------------------------------------------------------------------
/// @file SoftwareInterrupt.cpp
/// @brief Implementation of Software interrupt to synchronize different threads
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#include "SoftwareInterrupt.h"

namespace osal
{

SoftwareInterrupt::SoftwareInterrupt()
: mutex_o()
, isInitialized_b(false)
{
  init_v();
}

SoftwareInterrupt::~SoftwareInterrupt()
{
}

void SoftwareInterrupt::init_v()
{
  ME_Mutex_Init_t(&mutex_o, true);

  for(uint32_t v_I_u32 = 0; v_I_u32 < c_MAX_ATTACHMENTS_u8; v_I_u32++)
  {
    isUsed_ab[v_I_u32] = false;
    Assert(e_PeOk == ME_Condvar_Init_t(&condvars_as[v_I_u32]));
  }

  isInitialized_b = true;
}

void SoftwareInterrupt::broadcast_v()
{
//  while(isInitialized_b == false)
//  {
//    ME_Thread_Sleep_t(1);
//  }

  for(uint32_t v_I_u32 = 0; v_I_u32 < c_MAX_ATTACHMENTS_u8; v_I_u32++)
  {
    if(isUsed_b(v_I_u32) == true)
    {
      ME_Condvar_Broadcast_t(&condvars_as[v_I_u32]);
    }
  }
}

void SoftwareInterrupt::receive_v(uint8_t i_AttachmentID_u8)
{
  if(i_AttachmentID_u8 >= c_MAX_ATTACHMENTS_u8)
  {
    while((i_AttachmentID_u8 = attach_u8()) >= c_MAX_ATTACHMENTS_u8)
    {
      ME_Thread_Sleep_t(1U);
    }

    if(isUsed_b(i_AttachmentID_u8) == true)
    {
      ME_Mutex_Lock_t(&condvars_as[i_AttachmentID_u8].MEMutex_po);
      if(e_PeOk == ME_Condvar_Wait_t(&condvars_as[i_AttachmentID_u8]))
      {
      }
      ME_Mutex_UnLock_t(&condvars_as[i_AttachmentID_u8].MEMutex_po);
    }

    detach_v(i_AttachmentID_u8);
  }
  else
  {
    if(isUsed_b(i_AttachmentID_u8) == true)
    {
       ME_Mutex_Lock_t(&condvars_as[i_AttachmentID_u8].MEMutex_po);
      if(e_PeOk == ME_Condvar_Wait_t(&condvars_as[i_AttachmentID_u8]))
      {
      }
      ME_Mutex_UnLock_t(&condvars_as[i_AttachmentID_u8].MEMutex_po);
    }
  }
}

uint8_t SoftwareInterrupt::attach_u8()
{
  uint8_t v_Result_u8 = c_MAX_ATTACHMENTS_u8;

//  while(isInitialized_b == false)
//  {
//    ME_Thread_Sleep_t(1);
//  }

  ME_Mutex_Lock_t(&mutex_o);
  for(uint32_t v_I_u32 = 0; v_I_u32 < c_MAX_ATTACHMENTS_u8; v_I_u32++)
  {
    if(isUsed_ab[v_I_u32] == false)
    {
      isUsed_ab[v_I_u32] = true;
      v_Result_u8 = v_I_u32;
      break;
    }
  }
  ME_Mutex_UnLock_t(&mutex_o);

  return v_Result_u8;
}

void SoftwareInterrupt::detach_v(uint8_t i_AttachmentID_u8)
{
  if(i_AttachmentID_u8 < c_MAX_ATTACHMENTS_u8)
  {
    ME_Mutex_Lock_t(&mutex_o);
    isUsed_ab[i_AttachmentID_u8] = false;
    ME_Mutex_UnLock_t(&mutex_o);
  }
}

bool_t SoftwareInterrupt::isUsed_b(uint8_t i_AttachmentID_u8)
{
  bool_t v_Result_b = false;

  ME_Mutex_Lock_t(&mutex_o);
  v_Result_b = isUsed_ab[i_AttachmentID_u8];
  ME_Mutex_UnLock_t(&mutex_o);

  return v_Result_b;
}

} // namespace osal
