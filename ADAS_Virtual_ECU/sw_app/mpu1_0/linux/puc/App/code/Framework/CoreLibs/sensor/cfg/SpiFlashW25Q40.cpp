//--------------------------------------------------------------------------
/// @file SpiFlashW25Q40.cpp
/// @brief Implementation of Shared Memory camera grabber
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------


#include "SpiFlashW25Q40.h"

// PRQA S 3706 EOF // Usage of subscript operator necessary for read and write

namespace sensor
{

const uint8_t  c_CMD_BUF_LENGTH_u8     = 5; //buffer size includes number of commands and length of data to read
const uint16_t c_MaxPageSize_u8        = 256U;
const uint32_t c_MAX_RD_SIZE_FLASH_u32 = 250U;

SpiFlashW25Q40::SpiFlashW25Q40()
    : imagerAS0149AT_po(NULL)
    , i2c_po(NULL)
    , deviceAddress_u8(0x00U)
{
}

SpiFlashW25Q40::~SpiFlashW25Q40()
{

}

bool_t SpiFlashW25Q40::init_b(bsp::I2c& i_I2C_ro, uint32_t i_DeviceAddress_u8)
{
  bool_t v_Result_b = false;
  i2c_po = &i_I2C_ro;

  if(i2c_po != NULL)
  {
    deviceAddress_u8 = i_DeviceAddress_u8;
    v_Result_b = true;
  }

  return v_Result_b;
}

void SpiFlashW25Q40::deInit_v()
{
  i2c_po->deInit_v();
}

// send data
bool_t SpiFlashW25Q40::write_b(uint32_t i_RegisterAddress_u8, const uint32_t* b_Buffer_pu8, uint32_t i_BufferLength_u32)
{
  bool_t v_Result_b = true;
  return v_Result_b;
}

bool_t SpiFlashW25Q40::read_b(uint32_t i_RegisterAddress_u32, uint32_t* b_Buffer_pu8, uint32_t i_BufferLength_u32)
{
  bool_t v_Result_b = false;
  bool_t v_ReadSuccess_b = true;

  uint32_t v_Length_u32      = 0;
  uint32_t v_TotalLength_u32 = 0;
  uint32_t v_BufferIndex_u32    = 0;
  uint32_t v_Address_u32     = 0;

  i2c_po->lock_b();

  v_Result_b = requestFlashLock_b();

  v_Address_u32        = i_RegisterAddress_u32;
  v_TotalLength_u32    = i_BufferLength_u32;

  //record counter calculation.
  if(v_Result_b == true)
  {
    while((v_TotalLength_u32 > 0))
    {
      v_Length_u32 = mecl::math::min_x(v_TotalLength_u32, c_MAX_RD_SIZE_FLASH_u32);

      v_Result_b = readFlashRecord_b(v_Address_u32, v_Length_u32, &reinterpret_cast<uint8_t*>(b_Buffer_pu8)[v_BufferIndex_u32]) && v_Result_b;
      if(false == v_Result_b)
      {
        break;
      }

      v_Address_u32     += v_Length_u32;
      v_TotalLength_u32 -= v_Length_u32;
      v_BufferIndex_u32 +=v_Length_u32;

    }

    v_Result_b = imagerAS0149AT_po->issueHostCommand_b(c_FLASHMGR_GET_UNLOCK_u32, true) && v_Result_b;
  }

  i2c_po->unlock_b();

  return v_Result_b;
}

bool_t SpiFlashW25Q40::runCommand_b(sint8_t i_Command_s8)
{
  return true;
}


bool_t SpiFlashW25Q40::requestFlashLock_b()
{
  bool_t v_Result_b = true;
  uint32_t v_ReadValue_u32 = 0;


  if(true == imagerAS0149AT_po->issueHostCommand_b(c_FLASHMGR_SET_LOCK_u32, true))
  {
    //ME_Thread_Sleep_t(10);
    if(true == imagerAS0149AT_po->issueHostCommand_b(c_FLASHMGR_GET_LOCK_STATUS_u32, true))
    {
      v_Result_b = true;
    }
    else
    {
      ME_Debugger_F_Printf_v("Get lock failed\n");
      v_Result_b = false;
    }
  }
  else
  {
    ME_Debugger_F_Printf_v("Lock failed\n");
    v_Result_b = false;
  }

  return v_Result_b;
}

 //maximum data length = 250 bytes (limited to PARAMS_POOL_SIZE - 5)
bool_t SpiFlashW25Q40::readFlashRecord_b(uint32_t i_BlockAddress_u32, uint32_t i_BufferLength_u32, uint8_t* b_Buffer_pu8)
{
  bool_t v_Result_b = true;
  uint8_t v_Cmdbuffer_pu8[c_CMD_BUF_LENGTH_u8+1];

  if((0 == i_BufferLength_u32) || (i_BufferLength_u32 > 250) || (NULL == b_Buffer_pu8 ))
  {
    v_Result_b = true;
  }
  else
  {
    v_Cmdbuffer_pu8[0] = static_cast<uint8_t>((i_BlockAddress_u32 >> 24) & 0xffU);
    v_Cmdbuffer_pu8[1] = static_cast<uint8_t>((i_BlockAddress_u32 >> 16) & 0xffU);
    v_Cmdbuffer_pu8[2] = static_cast<uint8_t>((i_BlockAddress_u32 >>  8) & 0xffU);
    v_Cmdbuffer_pu8[3] = static_cast<uint8_t> (i_BlockAddress_u32        & 0xffU);
    v_Cmdbuffer_pu8[4] = i_BufferLength_u32;

    uint8_t v_Retries_u8 = 10;

    uint8_t tmp[5] = {0};
    do
    {
      imagerAS0149AT_po->write_b(c_IMAGER_CMD_HANDLER_PARAMS_POOL_0_u32, reinterpret_cast<uint32_t*>(v_Cmdbuffer_pu8), 5);

      v_Result_b = imagerAS0149AT_po->issueHostCommand_b(c_FLASHMGR_READ_u32, true);
      ME_Thread_Sleep_t(1);
    }
    while(false == imagerAS0149AT_po->issueHostCommand_b(c_FLASHMGR_STATUS_u32, true) && (v_Result_b == false) && (--v_Retries_u8 == 0));

    if(v_Result_b == true)
    {
      ME_Thread_Sleep_t(1);
      v_Result_b = imagerAS0149AT_po->read_b(c_IMAGER_CMD_HANDLER_PARAMS_POOL_0_u32, reinterpret_cast<uint32_t*>(b_Buffer_pu8), i_BufferLength_u32);
    }

    if(v_Result_b == true)
    {
      v_Result_b = imagerAS0149AT_po->issueHostCommand_b(c_FLASHMGR_STATUS_u32, true);
    }
  }

  return v_Result_b;
}



} // namespace sensor
