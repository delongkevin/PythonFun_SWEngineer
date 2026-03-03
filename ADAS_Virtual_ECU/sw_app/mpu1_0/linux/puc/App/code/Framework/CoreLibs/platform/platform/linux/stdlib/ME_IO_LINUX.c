//--------------------------------------------------------------------------
/// @file ME_IO_LINUX.c
/// @brief Linux dummy implementation for physical memory map to virtual memory map
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



// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for Linux only
#ifdef ME_PLATFORM_LINUX

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


bool_t ME_IO_Write8_b(void* i_PhyAddr_pv, uint32_t i_Offset_u32, uint8_t i_Value_u8)
{
  bool_t v_Result_b = true;
  return v_Result_b;
}

bool_t ME_IO_Write32_b(void* i_PhyAddr_pv, uint32_t i_Offset_u32, uint32_t i_Value_u32)
{
  bool_t v_Result_b = true;
  return v_Result_b;
}


bool_t ME_IO_Write_b(volatile const uint32_t *i_PhyBaseAddr_pu32, uint32_t i_MapSize_u32, IoMemoryMapRegister_t *i_RegConfig_ps, uint32_t i_WriteSize_u32)
{
  bool_t v_Result_b = true;
  return v_Result_b;
}


bool_t ME_IO_Read32_b(void* i_PhyAddr_pv, uint32_t i_Offset_u32, uint32_t* o_Value_pu32)
{
  bool_t v_Result_b = true;
  return v_Result_b;
}


bool_t ME_IO_Read(volatile const uint32_t *i_PhyBaseAddr_pu32, uint32_t i_MapSize_u32,  IoMemoryMapRegister_t *i_RegConfig_ps, uint32_t *i_PacketValue_pu32, uint32_t i_ReadSize_u32)
{
  bool_t v_Result_b = true;
  return v_Result_b;
}

#endif // ME_PLATFORM_LINUX // PRQA S 862 // this define decides which platform is defined
