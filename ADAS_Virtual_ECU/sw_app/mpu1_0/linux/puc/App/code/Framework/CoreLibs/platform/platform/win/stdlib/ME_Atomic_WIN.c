/*
 * ME_Atomic_WIN.c
 *
 *  Creation Date: 28.09.2021
 *         Author: Sivakumar Asoka Kumaran
 *        Company: Magna Electronics
 */

#include "platform/PlatformSpecs.h"

#ifdef ME_PLATFORM_WIN

// stdlib header include
#include "platform/stdlib/ME_Atomic.h"


PlatformError_t ME_Atomic_Add_t(atomic_address_t *i_Location_pu32,uint32_t i_Increment_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;

}
PlatformError_t ME_Atomic_Add_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Increment_u32,uint32_t *i_Previousvalue_pu32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;
}
PlatformError_t ME_Atomic_Clr(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;
}
PlatformError_t ME_Atomic_Clr_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32,uint32_t *i_Previousvalue_pu32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;

}
PlatformError_t ME_Atomic_Set(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;
}

PlatformError_t ME_Atomic_Set_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32,uint32_t *i_Previousvalue_pu32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;
}
PlatformError_t ME_Atomic_Sub_t(atomic_address_t *i_Location_pu32,uint32_t i_Decrement_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;

}
PlatformError_t ME_Atomic_Sub_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Decrement_u32,uint32_t *i_Previousvalue_pu32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;
}
PlatformError_t ME_Atomic_Toggle_t(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;
}
PlatformError_t ME_Atomic_Toggle_Value_t(atomic_address_t *i_Location_pu32,uint32_t i_Bits_u32,uint32_t *i_Previousvalue_pu32)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;
}

#endif
