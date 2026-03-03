//--------------------------------------------------------------------------
/// @file ME_Atomic_QNX.c
/// @brief Qnx implementation for standard-library Atomic
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sivakumar Asoka Kumaran (Sivakumar.Asokakumaran1@magna.com)
///
//  --------------------------------------------------------------------------

// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for QNX only
#ifdef ME_PLATFORM_QNX

// stdlib header include
#include <atomic.h>
#include "platform/stdlib/ME_Atomic.h"


PlatformError_t ME_Atomic_Add_t(atomic_address_t *i_Location_pu32,uint32_t i_Increment_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  atomic_add(i_Location_pu32,i_Increment_u32);
  return v_Error_t;

}
PlatformError_t ME_Atomic_Add_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Increment_u32,uint32_t *o_Previousvalue_pu32)
{
  PlatformError_t v_Error_t = e_PeOk;
  *o_Previousvalue_pu32= atomic_add_value(i_Location_pu32,i_Increment_u32);
  return v_Error_t;
}
PlatformError_t ME_Atomic_Clr(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  atomic_clr(i_Location_pu32,i_Bits_u32);
  return v_Error_t;
}
PlatformError_t ME_Atomic_Clr_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32,uint32_t *o_Previousvalue_pu32)
{
  PlatformError_t v_Error_t = e_PeOk;
  *o_Previousvalue_pu32= atomic_clr_value(i_Location_pu32,i_Bits_u32);
  return v_Error_t;

}
PlatformError_t ME_Atomic_Set(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  atomic_set(i_Location_pu32,i_Bits_u32);
  return v_Error_t;
}

PlatformError_t ME_Atomic_Set_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32,uint32_t *o_Previousvalue_pu32)
{
  PlatformError_t v_Error_t = e_PeOk;
  *o_Previousvalue_pu32=atomic_set_value(i_Location_pu32,i_Bits_u32);
  return v_Error_t;
}
PlatformError_t ME_Atomic_Sub_t(atomic_address_t *i_Location_pu32,uint32_t i_Decrement_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  atomic_sub(i_Location_pu32,i_Decrement_u32);
  return v_Error_t;

}
PlatformError_t ME_Atomic_Sub_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Decrement_u32,uint32_t *o_Previousvalue_pu32)
{
  PlatformError_t v_Error_t = e_PeOk;
  *o_Previousvalue_pu32=atomic_set_value(i_Location_pu32,i_Decrement_u32);
  return v_Error_t;
}
PlatformError_t ME_Atomic_Toggle_t(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  atomic_toggle(i_Location_pu32,i_Bits_u32);
  return v_Error_t;
}
PlatformError_t ME_Atomic_Toggle_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32,uint32_t *o_Previousvalue_pu32)
{
  PlatformError_t v_Error_t = e_PeOk;
  *o_Previousvalue_pu32=atomic_toggle_value(i_Location_pu32,i_Bits_u32);
  return v_Error_t;
}

#endif // ME_PLATFORM_QNX
