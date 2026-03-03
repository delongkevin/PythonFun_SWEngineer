//--------------------------------------------------------------------------
/// @file ImagerAR0143AT.cpp
/// @brief Implementation of Shared Memory camera grabber
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@web.de)
///
//  --------------------------------------------------------------------------


#include "ImagerAS0149AT.h"

namespace sensor
{

static const uint32_t c_MAX_RETRIES_u32 =   10U;

static const uint8_t  c_IMAGER_MODE_NORMAL_u8      = 0x00U;
static const uint8_t  c_IMAGER_MODE_TESTPATTERN_u8 = 0x02U;
static const uint8_t  c_IMAGER_MODE_SYNC_u8        = 0x03U;

static const uint8_t  c_IMAGER_SYNC_TRIGGER_u8     = 0x00U;
static const uint8_t  c_IMAGER_SYNC_SLAVE_u8       = 0x02U;

enum Color_e
{
  e_ColorWhite = 0,
  e_ColorBlack,
  e_ColorRed,
  e_ColorGreen,
  e_ColorBlue,
  e_ColorCount,
  e_ColorInvalid
};

enum PatternMode_e
{
  e_PatternModeNone           = 0,
  e_PatternModeStaticColor    = 1,
  e_PatternModeColorBars      = 2,
  e_PatternModeFadeToGreyBars = 8,
  e_PatternModeCount          = 9,
  e_PatternModeInvalid        = 10
};

static void getImagerConfig_v(PatternMode_e i_PatternMode_u8, Color_e i_Color_e, uint32_t* o_Config_pv, uint32_t& o_Size_ru32)
{
  const uint32_t c_EmptyConfig_au32[] = {
      c_IMAGER_REG_MODE_SELECT_u32,    0x00U,   sizeof(uint8_t),  // mode
      c_IMAGER_REG_PATTERN_u32,        0x00U,   sizeof(uint8_t),  // pattern
      c_IMAGER_REG_RED1_u32,           0x0000U, sizeof(uint16_t), // Red 1
      c_IMAGER_REG_RED2_u32,           0x0000U, sizeof(uint16_t), // Red 2
      c_IMAGER_REG_GREEN1_u32,         0x0000U, sizeof(uint16_t), // Green 1
      c_IMAGER_REG_GREEN2_u32,         0x0000U, sizeof(uint16_t), // Green 2
      c_IMAGER_REG_BLUE1_u32,          0x0000U, sizeof(uint16_t), // Blue 1
      c_IMAGER_REG_BLUE2_u32,          0x0000U, sizeof(uint16_t), // Blue 2
  };

  if(o_Config_pv != NULL)
  {
    if((i_PatternMode_u8 > e_PatternModeNone) && (i_PatternMode_u8 < e_PatternModeCount))
    {
      memcpy(o_Config_pv, c_EmptyConfig_au32, sizeof(c_EmptyConfig_au32));
      o_Size_ru32 = sizeof(c_EmptyConfig_au32) / sizeof(uint32_t);

      o_Config_pv[1] = c_IMAGER_MODE_TESTPATTERN_u8;
      o_Config_pv[4] = i_PatternMode_u8;

      if(i_PatternMode_u8 == e_PatternModeStaticColor)
      {
        if((i_Color_e == e_ColorRed) || (i_Color_e == e_ColorWhite))
        {
          o_Config_pv[7] = 0x0f00U;
          o_Config_pv[10] = 0xffffU;
        }
        if((i_Color_e == e_ColorGreen) || (i_Color_e == e_ColorWhite))
        {
          o_Config_pv[13]  = 0x0f00U;
          o_Config_pv[16]  = 0xffffU;
        }
        if((i_Color_e == e_ColorBlue) || (i_Color_e == e_ColorWhite))
        {
          o_Config_pv[19] = 0x0f00U;
          o_Config_pv[22] = 0xffffU;
        }
      }
      else
      {
        o_Size_ru32 = 6;
      }
    }
    else
    {
      // init config (trigger mode)
      uint32_t c_ImagerInit_au32[] = {c_IMAGER_REG_MODE_SELECT_u32,  c_IMAGER_MODE_SYNC_u8,   sizeof(uint8_t),
                                      c_IMAGER_REG_SYNC_TYPE_u32,    c_IMAGER_SYNC_SLAVE_u8,  sizeof(uint8_t),
                                      0x30CEU,                       0x1000U,                 sizeof(uint16_t)};

      memcpy(o_Config_pv, c_ImagerInit_au32, sizeof(c_ImagerInit_au32));
      o_Size_ru32 = o_Size_ru32 = sizeof(c_ImagerInit_au32) / sizeof(uint32_t);
    }
  }
}

//osal::Mutex ImagerAS0149AT:://mutex_o;

ImagerAS0149AT::ImagerAS0149AT()
  : ImagerBase()
  , i2c_po()
  , deviceAddress_u8(0x00U)
{
}

ImagerAS0149AT::~ImagerAS0149AT()
{

}


bool_t ImagerAS0149AT::init_b(bsp::I2c& i_I2C_ro, uint32_t i_DeviceAddress_u8)
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

void ImagerAS0149AT::deInit_v()
{
  i2c_po = NULL;
  deviceAddress_u8 = 0U;
}

bool_t ImagerAS0149AT::write_b(uint32_t i_RegisterAddress_u16, uint32_t i_WriteValue_u32, uint32_t i_Size_u32)
{
  return write_b(i_RegisterAddress_u16, &i_WriteValue_u32, i_Size_u32);
}

// send data
bool_t ImagerAS0149AT::write_b(uint32_t i_RegisterAddress_u16, const uint32_t* b_Buffer_pu16, uint32_t i_BufferLength_u32)
{
  return i2c_po->send_b(static_cast<uint16_t>(deviceAddress_u8),
                        static_cast<uint16_t>(i_RegisterAddress_u16),
                        reinterpret_cast<const uint16_t*>(b_Buffer_pu16),
                        i_BufferLength_u32,
                        false);
}

bool_t ImagerAS0149AT::read_b(uint32_t i_RegisterAddress_u16, uint32_t* b_Buffer_pu16, uint32_t i_BufferLength_u32)
{

  return i2c_po->sendRecv_b(static_cast<uint16_t>(deviceAddress_u8),
                            static_cast<uint16_t>(i_RegisterAddress_u16),
                            reinterpret_cast<uint16_t*>(b_Buffer_pu16),
                            i_BufferLength_u32);
}

bool_t ImagerAS0149AT::runCommand_b(sint8_t i_Command_s8)
{
  bool_t v_Result_b = false;

  i2c_po->lock_b();

  switch(i_Command_s8)
  {
    case 1:
    {
      v_Result_b = configTriggerMode_b();
      ME_Debugger_F_Printf_v("ImagerAS0149AT::runCommand finish config - Address 0x%x - Result %d\n", deviceAddress_u8, v_Result_b);
      break;
    }
    case 0:
    default:
    {
      v_Result_b = configTestPattern_b(static_cast<variants::CamTestPattern_t>(i_Command_s8));
      break;
    }
  }

  i2c_po->unlock_b();

  return v_Result_b && isStreaming_b();
}

bool_t ImagerAS0149AT::configStreamingMode_b()
{
  bool_t v_Result_b = true;

  if(isStreaming_b() == true)
  {
    v_Result_b = disableStreaming_b();
  }
  else
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

bool_t ImagerAS0149AT::configTriggerMode_b()
{
  bool_t v_Result_b = true;
  uint32_t v_RetryCount_u32 = 0U;

  while(((v_RetryCount_u32++) <= 3) && (isStreaming_b() != true))
  {
    ME_Thread_Sleep_t(10);
  }

  if(isStreaming_b() == true)
  {
    uint32_t v_ReadValue_u32 = 0x00U;
    uint32_t v_ImagerInit_au32[32];
    uint32_t v_ConfigSize_u32;

    getImagerConfig_v(e_PatternModeNone, e_ColorInvalid, v_ImagerInit_au32, v_ConfigSize_u32);

    for(uint32_t v_It_u32 = 0; v_It_u32 < v_ConfigSize_u32; v_It_u32 += 3)
    {
      v_Result_b = write_b(v_ImagerInit_au32[v_It_u32], v_ImagerInit_au32[v_It_u32 + 1], v_ImagerInit_au32[v_It_u32 + 2]);

      if(v_Result_b == true)
      {
        read_b(v_ImagerInit_au32[v_It_u32], &v_ReadValue_u32, v_ImagerInit_au32[v_It_u32 + 2]);
      }

      if(v_Result_b == true)
      {
        v_Result_b = (v_ReadValue_u32 == v_ImagerInit_au32[v_It_u32 + 1]);
      }

      if(v_Result_b == false)
      {
        break;
      }
    }

    if(v_Result_b == true)
    {
      v_Result_b = changeConfig_b();
    }
  }
  else
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

bool_t ImagerAS0149AT::configTestPattern_b(variants::CamTestPattern_t i_CameraTestPattern_t)
{
  bool_t v_Result_b = true;

  uint32_t v_ConfigSize_u32 = 0;
  uint32_t v_Config_au32[32] = {0};

  switch (i_CameraTestPattern_t)
  {
  case variants::e_CamTestPatternNone:
  {
    getImagerConfig_v(e_PatternModeNone, e_ColorInvalid, v_Config_au32, v_ConfigSize_u32);
    break;
  }
  case variants::e_CamTestPatternFullVertColorBars: //Full Vertical Color Bars test
  {
    getImagerConfig_v(e_PatternModeColorBars, e_ColorInvalid, v_Config_au32, v_ConfigSize_u32);
    break;
  }
  case variants::e_CamTestPatternFadeToGrey: //Fade to vertical color bar pattern
  {
    getImagerConfig_v(e_PatternModeFadeToGreyBars, e_ColorInvalid, v_Config_au32, v_ConfigSize_u32);
    break;
  }
  case variants::e_CamTestPatternSolidBlack: //Solid black
  {
    getImagerConfig_v(e_PatternModeStaticColor, e_ColorBlack, v_Config_au32, v_ConfigSize_u32);
    break;
  }
  case variants::e_CamTestPatternSolidWhite://Solid White
  {
    getImagerConfig_v(e_PatternModeStaticColor, e_ColorWhite, v_Config_au32, v_ConfigSize_u32);
    break;
  }
  case variants::e_CamTestPatternSolidRed://Red
  {
    getImagerConfig_v(e_PatternModeStaticColor, e_ColorRed, v_Config_au32, v_ConfigSize_u32);
    break;
  }
  case variants::e_CamTestPatternSolidGreen: //Green
  {
    getImagerConfig_v(e_PatternModeStaticColor, e_ColorGreen, v_Config_au32, v_ConfigSize_u32);
    break;
  }
  case variants::e_CamTestPatternSolidBlue: //Blue
  {
    getImagerConfig_v(e_PatternModeStaticColor, e_ColorBlue, v_Config_au32, v_ConfigSize_u32);
    break;
  }
  default:
  {
    getImagerConfig_v(e_PatternModeNone, e_ColorInvalid, v_Config_au32, v_ConfigSize_u32);
    break;
  }
  }

  uint32_t v_It_u32 = 0;
  uint32_t v_ReadValue_u32 = 0x00U;

  if(true == disableStreaming_b())
  {
    for(uint32_t v_I_u32 = 0; v_I_u32 < v_ConfigSize_u32; v_I_u32 += 3)
    {
      v_Result_b = write_b(v_Config_au32[v_I_u32], v_Config_au32[v_I_u32 + 1], v_Config_au32[v_I_u32 + 2]);

      if(v_Result_b == true)
      {
        read_b(v_Config_au32[v_I_u32], &v_ReadValue_u32, v_Config_au32[v_I_u32 + 2]);
      }

      if(v_Result_b == true)
      {
        v_Result_b = (v_ReadValue_u32 == v_Config_au32[v_I_u32 + 1]);
      }

      if(v_Result_b == false)
      {
        break;
      }
    }

    if(v_Result_b == true)
    {
      v_Result_b = changeConfig_b();
    }

    if((v_Result_b == true) && (i_CameraTestPattern_t != variants::e_CamTestPatternNone))
    {
      v_Result_b = write_b(0x6000U, 0x2300U, sizeof(uint16_t)) && v_Result_b;
    }
  }
  else
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

bool_t ImagerAS0149AT::changeConfig_b()
{
  bool_t v_Result_b = false;
  uint8_t v_State_u8 = 0x00U;
  uint32_t v_Timeout_u32 = c_MAX_RETRIES_u32;

  while(0 != (--v_Timeout_u32))
  {
    if(true == setState_b(c_IMAGER_STATE_CONFIG_MODE_u32))
    {
      ME_Thread_Sleep_t(10U);
      if(true == getState_b(v_State_u8))
      {
        v_Result_b = (v_State_u8 == c_IMAGER_STATE_STREAMING_u32);
        break;
      }
    }
  }

  return (v_Result_b && isStreaming_b());
}

bool_t ImagerAS0149AT::issueHostCommand_b(uint32_t i_Command_u32, bool_t i_CheckDoorbell_b)
{
  bool_t v_Result_b = true;
  uint32_t v_Timeout_u32 = c_MAX_RETRIES_u32;
  uint32_t v_CmdReg_u32 = 0x00U;

  if(i_CheckDoorbell_b == true)
  {
    do
    {
      v_Result_b = getHostCommandRegister_b(v_CmdReg_u32);
    }
    while((v_Result_b == false) && (v_CmdReg_u32 & c_COMMAND_REG_DOORBELL_BIT_u32) == c_COMMAND_REG_DOORBELL_BIT_u32);
  }

  while(0 != (--v_Timeout_u32))
  {
    v_Result_b = write_b(c_IMAGER_CMD_REGISTER_u32, i_Command_u32, sizeof(uint16_t));
    ME_Thread_Sleep_t(1);

    if(true == v_Result_b)
    {
      v_Result_b = getHostCommandRegister_b(v_CmdReg_u32);
    }

    if(true == v_Result_b)
    {
      v_Result_b = ((v_CmdReg_u32 & c_COMMAND_REG_DOORBELL_BIT_u32) == 0x00U);
    }

    if(true == v_Result_b)
    {
      v_Result_b = (ME_Platform_F_EndianSwap_u32(v_CmdReg_u32) & 0xffU) == c_RESP_ENOERR_u32;
      break;
    }
  }

  return v_Result_b;
}

bool_t ImagerAS0149AT::isStreaming_b()
{
  bool_t v_Result_b = false;
  uint8_t v_State_u8 = 0x00U;
  uint32_t v_ReadVal_u32 = 0x00U;

  if(getState_b(v_State_u8) == true)
  {
    v_Result_b = (v_State_u8 == c_IMAGER_STATE_STREAMING_u32);
  }

  if(v_Result_b == true)
  {
    v_Result_b = read_b(0xDC07U, &v_ReadVal_u32, sizeof(uint8_t));
    if(true == v_Result_b)
    {
      v_Result_b = (v_ReadVal_u32 == 0x03U);
    }
  }

  if(v_Result_b == true)
  {
    v_Result_b = read_b(0xDC00U, &v_ReadVal_u32, sizeof(uint16_t));
    if(true == v_Result_b)
    {
      v_Result_b = ((v_ReadVal_u32 & 0x1108) == 0x1000);
    }
  }

  if(v_Result_b == true)
  {
    v_Result_b = read_b(0x8016U, &v_ReadVal_u32, sizeof(uint16_t));
    if(true == v_Result_b)
    {
      v_Result_b = (v_ReadVal_u32 == 0x0000);
    }
  }

  return v_Result_b;
}


bool_t ImagerAS0149AT::isErrorFlagActive_b()
{
  uint32_t v_ReadValue_u32 = 0xFFU;

  if(true == read_b(c_IMAGER_CMD_REGISTER_u32, &v_ReadValue_u32, sizeof(uint16_t)))
  {
    v_ReadValue_u32 = ME_Platform_F_EndianSwap_u16(v_ReadValue_u32);
  }

  return (v_ReadValue_u32 != 0x00U);
}

bool_t ImagerAS0149AT::disableStreaming_b()
{
  bool_t v_Result_b = true;
  uint32_t v_Retries_u32 = 0;

  v_Result_b = write_b(c_IMAGER_REG_MODE_SELECT_u32, static_cast<uint32_t>(c_IMAGER_MODE_NORMAL_u8),  sizeof(uint8_t)) && v_Result_b;
  v_Result_b = write_b(c_IMAGER_REG_SYNC_TYPE_u32,   static_cast<uint32_t>(c_IMAGER_SYNC_TRIGGER_u8), sizeof(uint8_t)) && v_Result_b;
  v_Result_b = write_b(0x30CEU,                      0x0000U,                  sizeof(uint16_t)) && v_Result_b;

  v_Result_b = changeConfig_b() && v_Result_b;

  return v_Result_b;
}

bool_t ImagerAS0149AT::getHostCommandRegister_b(uint32_t& o_RegValue_ru32)
{
  return read_b(c_IMAGER_CMD_REGISTER_u32, &o_RegValue_ru32, sizeof(uint16_t));
}

bool_t ImagerAS0149AT::getState_b(uint8_t& o_State_ru8)
{
  bool_t v_Result_b = false;

  if(true == issueHostCommand_b(c_IMAGER_GET_STATE_u32, true))
  {
    uint32_t v_ReadValue_u32 = 0x00U;
    v_Result_b = read_b(c_IMAGER_CMD_HANDLER_PARAMS_POOL_0_u32, &v_ReadValue_u32, sizeof(uint16_t));
    o_State_ru8 = (v_ReadValue_u32 & 0xFFU);
  }

  return v_Result_b;
}

bool_t ImagerAS0149AT::setState_b(uint8_t i_State_u8)
{
  bool_t v_Result_b = false;
  if(true == write_b(c_IMAGER_CMD_HANDLER_PARAMS_POOL_0_u32, i_State_u8, sizeof(uint16_t)))
  {
    v_Result_b = issueHostCommand_b(c_IMAGER_SET_STATE_u32, true);
  }

  return v_Result_b;
}


} // namespace sensor
