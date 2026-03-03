//--------------------------------------------------------------------------
/// @file SpiFlashW25Q40.h
/// @brief Implementation of Imager interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Gangadhar Reddy Yadiki (GangadharReddy.Yadiki@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef SPIFLASH_W25Q40_H_
#define SPIFLASH_W25Q40_H_


#include <osal/threading/Mutex.h>
#include <sensor/devices/EepromBase.h>

#include "ImagerAS0149AT.h"

namespace sensor
{











class SpiFlashW25Q40 : public EepromBase<uint32_t>
{
public:

  explicit SpiFlashW25Q40();

  ~SpiFlashW25Q40();

  bool_t   init_b(bsp::I2c& i_I2C_ro, uint32_t i_DeviceAddress_u8) ME_OVERRIDE;
  
  void     deInit_v() ME_OVERRIDE;

  bool_t   write_b(uint32_t i_RegisterAddress_u8, const uint32_t* b_Buffer_pu8, uint32_t i_BufferLength_u32) ME_OVERRIDE;

  bool_t   read_b(uint32_t i_RegisterAddress_u32, uint32_t* b_Buffer_pu8, uint32_t i_BufferLength_u32) ME_OVERRIDE;
  
  bool_t   runCommand_b(sint8_t i_Command_s8) ME_OVERRIDE;

public:

  void     setImager_v(ImagerAS0149AT* i_Imager_po) { imagerAS0149AT_po = i_Imager_po; }

private:

  bool_t   readFlashRecord_b(uint32_t i_BlockAddress_u32, uint32_t i_BufferLength_u32, uint8_t* b_Buffer_pu8);
  
  bool_t   requestFlashLock_b();
  
  
  sensor::ImagerAS0149AT* imagerAS0149AT_po;

  bsp::I2c*               i2c_po;

  uint8_t                 deviceAddress_u8;

};

}

#endif // SPIFLASH_W25Q40_H_
