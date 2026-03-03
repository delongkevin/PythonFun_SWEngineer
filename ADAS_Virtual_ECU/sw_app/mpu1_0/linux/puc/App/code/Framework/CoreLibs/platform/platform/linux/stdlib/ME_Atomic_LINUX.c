/*
 * ME_Atomic_LINUX.c
 *
 *  Creation Date: 28.09.2021
 *         Author: Sivakumar Asoka Kumaran
 *        Company: Magna Electronics
 */

#include "platform/PlatformSpecs.h"

// compile this file for Linux only
#ifdef ME_PLATFORM_LINUX

// stdlib header include
#include "platform/stdlib/ME_Atomic.h"


PlatformError_t ME_Atomic_Add_t(atomic_address_t *i_Location_pu32,uint32_t i_Increment_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  atomic_add(i_Increment_u32, i_Location_pu32);
  return v_Error_t;

}
PlatformError_t ME_Atomic_Add_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Increment_u32,uint32_t *o_Previousvalue_pu32)
{
  PlatformError_t v_Error_t = e_PeOk;
  *o_Previousvalue_pu32=atomic_read(i_Location_pu32);
  atomic_add(i_Increment_u32, i_Location_pu32);
  return v_Error_t;
}
PlatformError_t ME_Atomic_Clr(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;
}
PlatformError_t ME_Atomic_Clr_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32,uint32_t *o_Previousvalue_pu32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;

}
PlatformError_t ME_Atomic_Set(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;
}

PlatformError_t ME_Atomic_Set_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32,uint32_t *o_Previousvalue_pu32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;
}
PlatformError_t ME_Atomic_Sub_t(atomic_address_t *i_Location_pu32,uint32_t i_Decrement_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  atomic_sub(i_Decrement_u32, i_Location_pu32);
  return v_Error_t;

}
PlatformError_t ME_Atomic_Sub_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Decrement_u32,uint32_t *o_Previousvalue_pu32)
{
  PlatformError_t v_Error_t = e_PeOk;
  *o_Previousvalue_pu32=atomic_read(i_Location_pu32);
  atomic_sub(i_Increment_u32, i_Location_pu32);
  return v_Error_t;
}
PlatformError_t ME_Atomic_Toggle_t(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;
}
PlatformError_t ME_Atomic_Toggle_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32,uint32_t *o_Previousvalue_pu32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;
}

#endif
