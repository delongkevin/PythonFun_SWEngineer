//--------------------------------------------------------------------------
/// @file ME_IO_QNX.c
/// @brief Qnx implementation for physical memory map to virtual memory map
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

// compile this file for QNX only
#ifdef ME_PLATFORM_QNX

// stdlib header include
#include "platform/stdlib/ME_IO.h"
#include "platform/stdlib/ME_Debugger.h"

#include <sys/neutrino.h> // needed

#include <hw/inout.h>
#include <sys/mman.h>
#include <stdint.h>



bool_t ME_IO_MapDeviceAdress_b(uint32_t i_PhyAddress_u32, uint32_t i_Size_u32, void** o_DeviceAddress_ppv)
{
  bool_t v_Result_b = true;
  *o_DeviceAddress_ppv = (void*)mmap_device_io(i_Size_u32, i_PhyAddress_u32);

  if (*o_DeviceAddress_ppv == (uintptr_t*)MAP_DEVICE_FAILED)
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

bool_t ME_IO_Out32_b(const void* i_Address_pv, uint32_t i_Offset_u32, uint32_t i_Value_u32)
{
  bool_t v_Result_b = false;

  if(i_Address_pv != NULL)
  {
    ((uint32_t*)(i_Address_pv))[i_Offset_u32 / sizeof(uint32_t)] = i_Value_u32;
    v_Result_b = true;
  }

  return v_Result_b;
}

bool_t ME_IO_In32_b(const void* i_Address_pv, uint32_t i_Offset_u32, uint32_t* o_Value_u32)
{
  bool_t v_Result_b = false;

  if((i_Address_pv != NULL) && (o_Value_u32 != NULL))
  {
    *o_Value_u32 = ((uint32_t*)(i_Address_pv))[i_Offset_u32 / sizeof(uint32_t)];
    v_Result_b = true;
  }

  return v_Result_b;
}


bool_t ME_IO_Write8_b(const void* i_PhyAddr_pv, uint32_t i_Offset_u32, uint8_t i_Value_u8)
{
  bool_t v_Result_b = false;

  volatile uint64_t v_LocalAddress_u32 = (volatile uint64_t)i_PhyAddr_pv;

  if(i_PhyAddr_pv != NULL)
  {
    *((uint8_t*)(v_LocalAddress_u32 + i_Offset_u32)) = i_Value_u8;
  }

  return v_Result_b;
}

bool_t ME_IO_Write32_b(const void* i_PhyAddr_pv, uint32_t i_Offset_u32, uint32_t i_Value_u32)
{
  bool_t v_Result_b = false;

  if (i_PhyAddr_pv != NULL)
  {
    volatile uint32_t* v_LocalAddress_pu32 = (volatile uint32_t*)((uintptr_t)i_PhyAddr_pv + i_Offset_u32);
    *v_LocalAddress_pu32 = i_Value_u32;
    v_Result_b = true;
  }

  return v_Result_b;
}


#else
/* do not do anything */
#endif
