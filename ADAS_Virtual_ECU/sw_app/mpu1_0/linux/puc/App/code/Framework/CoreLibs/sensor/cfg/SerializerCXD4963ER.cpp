//--------------------------------------------------------------------------
/// @file SerializerMAX9249.cpp
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


#include "SerializerCXD4963ER.h"

namespace sensor
{

const uint8_t c_SerInitSequence_au8[]  = {0xCC, 0x01,
                                          0xCF, 0x64,
                                          0xD0, 0xFB,
                                          0xD1, 0x63,
                                          0xD9, 0x0D,
                                          0xDA, 0x00,
                                          0x53, 0x00,
                                          0x20, 0x11,
                                          0x69, 0x02,
                                          0x6A, 0x00,
                                          0x6B, 0x00,
                                          0xA1, 0x03,
                                          0xA3, 0x06,
                                          0xA0, 0x01,
                                          0x53, 0x01,
                                          0x1F, 0x01,
                                          0x1F, 0x00};

SerializerCXD4963ER::SerializerCXD4963ER()
  : SerializerBase()
{
}

SerializerCXD4963ER::~SerializerCXD4963ER()
{

}

bool_t SerializerCXD4963ER::init_b(bsp::I2c& i_I2C_ro, uint32_t i_DeviceAddress_u8)
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

void SerializerCXD4963ER::deInit_v()
{
}

// send data
bool_t SerializerCXD4963ER::write_b(uint32_t i_RegisterAddress_u8, const uint32_t* b_Buffer_pu8, uint32_t i_BufferLength_u32)
{
  return i2c_po->send_b(deviceAddress_u8, static_cast<uint8_t>(i_RegisterAddress_u8), reinterpret_cast<const uint8_t*>(b_Buffer_pu8), i_BufferLength_u32, false);
}

bool_t SerializerCXD4963ER::read_b(uint32_t i_RegisterAddress_u8, uint32_t* b_Buffer_pu8, uint32_t i_BufferLength_u32)
{
  return i2c_po->sendRecv_b(deviceAddress_u8, static_cast<uint8_t>(i_RegisterAddress_u8), reinterpret_cast<uint8_t*>(b_Buffer_pu8), i_BufferLength_u32);
}


bool_t SerializerCXD4963ER::runCommand_b(sint8_t i_Command_s8)
{
  bool_t v_Result_b = false;

  i2c_po->lock_b();

  switch(i_Command_s8)
  {
  case e_SerCmdInit:
  {
    v_Result_b = runInitCmd_b();
    ME_Debugger_F_Printf_v("SerializerCXD4963ER::runCommand finish config - Address 0x%x - Result %d\n", deviceAddress_u8, v_Result_b);
    break;
  }
  case e_SerCmdCheckStatus:
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

bool_t SerializerCXD4963ER::runCheckStatus_b()
{
  uint32_t v_ReadValue_u32 = 0x00U;

  bool_t v_Result_b = read_b(GENERAL_STATUS_REG_1, &v_ReadValue_u32, sizeof(uint8_t));
  v_Result_b &= ((v_ReadValue_u32 & GVIF2TX_ACTIVATED) == GVIF2TX_ACTIVATED);

  v_Result_b &= read_b(GENERAL_STATUS_REG_2, &v_ReadValue_u32, sizeof(uint8_t));
  v_Result_b &= ((v_ReadValue_u32 & READY) == READY);

  //v_Result_b &= read_b(ERROR_STATUS_REG_1, &v_ReadValue_u32, sizeof(uint8_t));
  //  v_Result_b &= ((v_ReadValue_u32 & READY) == READY);

  //v_Result_b &= read_b(ERROR_STATUS_REG_7, &v_ReadValue_u32, sizeof(uint8_t));
  //  v_Result_b &= ((v_ReadValue_u32 & READY) == READY);

  return v_Result_b;
}

bool_t SerializerCXD4963ER::runInitCmd_b()
{
  bool_t v_Result_b = true;

  uint32_t v_ReadValue_u32 = 0x0;

  for(uint32_t v_I_u32 = 0; v_I_u32 < (sizeof(c_SerInitSequence_au8)); v_I_u32 += 2U)
  {
    v_Result_b = write_b(c_SerInitSequence_au8[v_I_u32], reinterpret_cast<const uint32_t*>(&c_SerInitSequence_au8[v_I_u32 + 1]), sizeof(uint8_t)) && v_Result_b;

    if(v_Result_b == true)
    {
      v_Result_b = read_b(c_SerInitSequence_au8[v_I_u32], &v_ReadValue_u32, sizeof(uint8_t)) && v_Result_b;
    }

    if(v_Result_b == true)
    {
      v_Result_b = (v_ReadValue_u32 == c_SerInitSequence_au8[v_I_u32 + 1]);
    }

    if(v_Result_b == false)
    {
      break;
    }
  }

  return v_Result_b;
}

bool_t EcuSerializerCXD4963ER::runCommand_b(sint8_t i_Command_s8)
{
  bool_t v_Result_b = true;

  const uint8_t c_EcuSerInitSequence_au8[]  = {0x20, 0x12,
                                               0x53, 0x00,
                                               0x69, 0x04,
                                               0x42, 0x01,
                                               0x53, 0x01,
                                               0x1F, 0x01,
                                               0x1F, 0x00};
  uint8_t v_SerializerRegOffset_u8 = 0U;
  uint32_t v_ReadValue_u32 = 0x0U;

  i2c_po->lock_b();

  /*10. ECU Serializer initialization*/
  switch(i_Command_s8)
  {
  case e_SerCmdOff:
  {
    v_SerializerRegOffset_u8 = 13;
    v_Result_b = write_b(c_EcuSerInitSequence_au8[v_SerializerRegOffset_u8],
                         reinterpret_cast<const uint32_t*>(&c_EcuSerInitSequence_au8[v_SerializerRegOffset_u8 + 1]), sizeof(uint8_t)) && v_Result_b;
    v_Result_b = read_b(c_EcuSerInitSequence_au8[v_SerializerRegOffset_u8], &v_ReadValue_u32, sizeof(uint8_t)) && v_Result_b;
    break;
  }
  case e_SerCmdOn:
  {
    v_SerializerRegOffset_u8 = 12;
    v_Result_b = write_b(c_EcuSerInitSequence_au8[v_SerializerRegOffset_u8],
                         reinterpret_cast<const uint32_t*>(&c_EcuSerInitSequence_au8[v_SerializerRegOffset_u8 + 1]), sizeof(uint8_t)) && v_Result_b;
    v_Result_b = read_b(c_EcuSerInitSequence_au8[v_SerializerRegOffset_u8], &v_ReadValue_u32, sizeof(uint8_t)) && v_Result_b;
    break;
  }
  case e_SerCmdInit:
  {
    for(uint32_t v_I_u32 = 0; v_I_u32 < sizeof(c_EcuSerInitSequence_au8); v_I_u32 += 2)
    {
      v_Result_b = write_b(c_EcuSerInitSequence_au8[v_I_u32],
                            reinterpret_cast<const uint32_t*>(&c_EcuSerInitSequence_au8[v_I_u32 + 1]), sizeof(uint8_t)) && v_Result_b;

      if(v_Result_b == true)
      {
        v_Result_b = read_b(c_EcuSerInitSequence_au8[v_I_u32], &v_ReadValue_u32, sizeof(uint8_t)) && v_Result_b;
      }

      if(v_Result_b == true)
      {
        v_Result_b = (v_ReadValue_u32 == c_EcuSerInitSequence_au8[v_I_u32 + 1]) && v_Result_b;
      }

      if(v_Result_b == false)
      {
        break;
      }
    }

    break;
  }
  case e_SerCmdCheckStatus:
  {
    v_Result_b = runCheckStatus_b();
    break;
  }
  default:
  {
    break;
  }
  }

  i2c_po->unlock_b();

  return v_Result_b;
}

} // namespace sensor
