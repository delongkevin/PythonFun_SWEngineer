/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file ME_IO.h
/// @brief Abstract Interface for physical memory map to virtual memory map
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

#ifndef ME_IO_H
#define ME_IO_H

#include "platform/PlatformSpecs.h"

#include "platform/stdlib/StdLibTypes.h"

#if defined(__cplusplus)
extern "C"
{
#endif


bool_t ME_IO_MapDeviceAdress_b(uint32_t i_PhyAddress_u32, uint32_t i_Size_u32, void** o_DeviceAddress_ppv);

bool_t ME_IO_Out32_b(const void* i_Address_pv, uint32_t i_Offset_u32, uint32_t i_Value_u32);

bool_t ME_IO_In32_b(const void* i_Address_pv, uint32_t i_Offset_u32, uint32_t* o_Value_u32);


#if defined(__cplusplus)
}; // extern C
#endif

#endif // ME_IO_H
