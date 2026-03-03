//--------------------------------------------------------------------------
/// @file ME_IO_WIN.c
/// @brief Windows dummy implementation for physical memory map to virtual memory map
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Gangadhar Reddy Yadiki (GangadharReddy.Yadiki@magna.com)
///
//  --------------------------------------------------------------------------


#include "platform/stdlib/ME_IO.h"

// compile this file for WIN only
#ifdef ME_PLATFORM_WIN

bool_t ME_IO_MapDeviceAdress_b(uint32_t i_PhyAddress_u32, uint32_t i_Size_u32, void** o_DeviceAddress_ppv)
{
  bool_t v_Result_b = true;
  return v_Result_b;
}

bool_t ME_IO_Out32_b(void* i_Address_pv, uint32_t i_Offset_u32, uint32_t i_Value_u32)
{
  return true;
}

bool_t ME_IO_In32_b(void* i_Address_pv, uint32_t i_Offset_u32, uint32_t* o_Value_u32)
{
  return true;
}



#endif // ME_PLATFORM_WIN // PRQA S 862 // this define decides which platform is defined
