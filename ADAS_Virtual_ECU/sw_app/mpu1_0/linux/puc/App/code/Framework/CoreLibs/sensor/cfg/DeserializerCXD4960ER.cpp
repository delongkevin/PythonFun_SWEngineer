//--------------------------------------------------------------------------
/// @file DeserializerCXD4960ER.cpp
/// @brief Implementation of Shared Memory camera grabber
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
///
//  --------------------------------------------------------------------------

#include "DeserializerCXD4960ER.h"

#include <platform/PlatformAPI.h>
#include <logging/Logger.h>

namespace sensor
{

DeserializerCXD4960ER::DeserializerCXD4960ER()
  : DeserializerBase()
  , deserGeneralStatus1_u32(0x00U)
  , deserGeneralStatus2_u32(0x00U)
{
}

DeserializerCXD4960ER::~DeserializerCXD4960ER()
{

}


bool_t DeserializerCXD4960ER::init_b(bsp::I2c& i_I2C_ro, uint32_t i_DeviceAddress_u8)
{
  bool_t v_Result_b = false;

  i2c_po = & i_I2C_ro;

  if(i2c_po != NULL)
  {
    deviceAddress_u8 = i_DeviceAddress_u8;
    v_Result_b = true;
  }


  return v_Result_b;
}

void DeserializerCXD4960ER::deInit_v()
{
}

// send data
bool_t DeserializerCXD4960ER::write_b(uint32_t i_RegisterAddress_u8, const uint32_t* b_Buffer_pu8, uint32_t i_BufferLength_u32)
{
  bool_t v_Result_b = false;

  v_Result_b = i2c_po->send_b(deviceAddress_u8,
                              static_cast<uint8_t>(i_RegisterAddress_u8),
                              reinterpret_cast<const uint8_t*>(b_Buffer_pu8),
                              i_BufferLength_u32, false);

  return v_Result_b;
}

bool_t DeserializerCXD4960ER::read_b(uint32_t i_RegisterAddress_u8, uint32_t* b_Buffer_pu8, uint32_t i_BufferLength_u32)
{
  bool_t v_Result_b = false;
  v_Result_b = i2c_po->sendRecv_b(deviceAddress_u8,
                                  static_cast<uint8_t>(i_RegisterAddress_u8),
                                  reinterpret_cast<uint8_t*>(b_Buffer_pu8),
                                  i_BufferLength_u32);

  return v_Result_b;
}

bool_t DeserializerCXD4960ER::runCommand_b(sint8_t i_Command_s8)
{
  bool_t v_Result_b = false;

  i2c_po->lock_b();

  switch(i_Command_s8)
  {
  case e_DeserCmdInit:
  {
    v_Result_b = runInitCmd_b();
    ME_Debugger_F_Printf_v("DeserializerCXD4960ER::runCommand finish config - Address 0x%x - Result %d\n", deviceAddress_u8, v_Result_b);
    break;
  }
  case e_DeserCmdCheckStatus:
  {
    v_Result_b = runCheckStatus_b();
    break;
  }
  default:
    break;
  }

  i2c_po->unlock_b();

  return v_Result_b;
}

bool_t DeserializerCXD4960ER::runInitCmd_b()
{
  const uint8_t c_DeserInitSequence_au8[] = {0x28, 0x10,
                                             0x71, 0x4A,
                                             0xB0, 0x4A,
                                             0xB1, 0xC5,
                                             0xB2, deviceFlipAddress_u8,
                                             0xB4, 0x01,
                                             0xB4, 0x00,
                                             0x29, 0x00,
                                             0x20, 0x01,
                                             0xC0, 0x41,
                                             0xB1, 0xC0,
                                             0xB2, 0x41,
                                             0xB4, 0x01,
                                             0xB4, 0x00,
                                             0x76, 0x00,
                                             0x90, 0x20,
                                             0xA1, 0x03,
                                             0xA0, 0x01,
                                             0x76, 0x01,
                                             0x1F, 0x01,
                                             0x1F, 0x00
  };

  bool_t v_Result_b = true;
  uint32_t v_ReadValue_u32 = 0x0;

  for(uint32_t v_I_u32 = 0; v_I_u32 < sizeof(c_DeserInitSequence_au8); v_I_u32 += 2)
  {
    v_Result_b = write_b(c_DeserInitSequence_au8[v_I_u32], reinterpret_cast<const uint32_t*>(&c_DeserInitSequence_au8[v_I_u32+1]), sizeof(uint8_t)) && v_Result_b;
    if(v_Result_b == true)
    {
      v_Result_b = read_b(c_DeserInitSequence_au8[v_I_u32], &v_ReadValue_u32, sizeof(uint8_t)) && v_Result_b;
    }

    if(v_Result_b == true)
    {
      v_Result_b = (v_ReadValue_u32 == c_DeserInitSequence_au8[v_I_u32+1]) && v_Result_b;
    }

    if(v_Result_b == false)
    {
      break;
    }
  }

  return v_Result_b;
}

bool_t DeserializerCXD4960ER::runCheckStatus_b()
{
  uint32_t v_ReadValue_u32 = 0x00U;

  bool_t v_Result_b = read_b(GENERAL_STATUS_REG_1, &v_ReadValue_u32, sizeof(uint8_t));
  // ME_Debugger_F_Printf_v("GENERAL_STATUS_REG_1: 0x%x\n", v_ReadValue_u32);
  v_Result_b &= ((v_ReadValue_u32 & GVIF2RX_ACTIVATED) == GVIF2RX_ACTIVATED);

  v_Result_b &= read_b(GENERAL_STATUS_REG_2, &v_ReadValue_u32, sizeof(uint8_t));
  v_Result_b &= ((v_ReadValue_u32 & GVIF2RX_LOS) == 0x00U);
  // ME_Debugger_F_Printf_v("GENERAL_STATUS_REG_2: 0x%x\n", v_ReadValue_u32);

  v_Result_b &= read_b(ERROR_STATUS_REG_1, &v_ReadValue_u32, sizeof(uint8_t));
  //v_Result_b &= ((v_ReadValue_u32 & (GVIF2RX_FAIL | GVIF2TX_FAIL | VIDEOTX_FAIL | DAISY_FAIL)) == 0x00U);
  // ME_Debugger_F_Printf_v("ERROR_STATUS_REG_1: 0x%x\n", v_ReadValue_u32);

  return v_Result_b;
}


} // namespace sensor
