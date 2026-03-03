//--------------------------------------------------------------------------
/// @file ImagerAR0143AT.h
/// @brief Implementation of Serializer interface
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

#ifndef IMAGER_AS0149_H_
#define IMAGER_AS0149_H_

#include <sensor/devices/ImagerBase.h>

#include <bsp/driver/I2c.h>

#include <variants/Enums.h>

namespace sensor
{

/// Registers
const uint32_t c_IMAGER_REG_MODE_SELECT_u32                      = 0xC874U;  // mode
const uint32_t c_IMAGER_REG_SYNC_TYPE_u32                        = 0xC875U;  // sync type
const uint32_t c_IMAGER_REG_PATTERN_u32                          = 0xC877U;  // pattern
const uint32_t c_IMAGER_REG_RED1_u32                             = 0xC878U;  // Red 1
const uint32_t c_IMAGER_REG_RED2_u32                             = 0xC87AU;  // Red 2
const uint32_t c_IMAGER_REG_GREEN1_u32                           = 0xC87CU;  // Green 1
const uint32_t c_IMAGER_REG_GREEN2_u32                           = 0xC87EU;  // Green 2
const uint32_t c_IMAGER_REG_BLUE1_u32                            = 0xC880U;  // Blue 1
const uint32_t c_IMAGER_REG_BLUE2_u32                            = 0xC882U;  // blue2

const uint32_t c_IMAGER_CMD_HANDLER_PARAMS_POOL_0_u32            = 0xFC00U;   //s_Imager_cmd_buf_pool_u16

const uint32_t c_GET_IMAGER_DEV_ID_u32                           = 0x5200U;
const uint32_t c_IMAGER_CMD_REGISTER_u32                         = 0x5240U;   //s_Imager_cmd_reg_u16


const uint32_t c_IMAGER_SET_STATE_u32                            = ME_Platform_F_EndianSwap_u16(0x8100U);
const uint32_t c_IMAGER_GET_STATE_u32                            = ME_Platform_F_EndianSwap_u16(0x8101U);


/// Register values (constants)
const uint32_t c_COMMAND_REG_DOORBELL_BIT_u32                    = ME_Platform_F_EndianSwap_u16(0x8000U);     //s_Cmd_door_bit

const uint32_t c_RESP_ENOERR_u32                                 = 0x00U;
const uint32_t c_RESP_EBUSY_u32                                  = 0x09U;
const uint32_t c_RESP_EALREADY_u32                               = 0x10U;

const uint32_t c_IMAGER_STATE_STREAMING_u32                      = 0x31U;
const uint32_t c_IMAGER_STATE_CONFIG_MODE_u32                    = 0x28U;


/// Flash manager registers
const uint32_t c_FLASHMGR_SET_LOCK_u32                           = ME_Platform_F_EndianSwap_u16(0x8500U);
const uint32_t c_FLASHMGR_GET_LOCK_STATUS_u32                    = ME_Platform_F_EndianSwap_u16(0x8501U);
const uint32_t c_FLASHMGR_GET_UNLOCK_u32                         = ME_Platform_F_EndianSwap_u16(0x8502U);

const uint32_t c_FLASHMGR_READ_u32                               = ME_Platform_F_EndianSwap_u16(0x8504U);
const uint32_t c_FLASHMGR_WRITE_u32                              = ME_Platform_F_EndianSwap_u16(0x8505U);
const uint32_t c_FLASHMGR_ERASE_BLOCK_u32                        = ME_Platform_F_EndianSwap_u16(0x8506U);
const uint32_t c_FLASHMGR_QUERY_DEVICE_u32                       = ME_Platform_F_EndianSwap_u16(0x8508U);
const uint32_t c_FLASHMGR_STATUS_u32                             = ME_Platform_F_EndianSwap_u16(0x8509U);
const uint32_t c_FLASHMGR_CONFIG_DEVICE_u32                      = ME_Platform_F_EndianSwap_u16(0x850AU);
const uint32_t c_FLASHMGR_ISSUE_DEVICE_CMD_u32                   = ME_Platform_F_EndianSwap_u16(0x850FU);
const uint32_t c_FLASHMGR_GET_DEVICE_CMD_RESP_u32                = ME_Platform_F_EndianSwap_u16(0x8510U);




class ImagerAS0149AT : public ImagerBase<uint32_t>
{
public:

  ImagerAS0149AT();

  virtual ~ImagerAS0149AT();

  virtual bool_t   init_b(bsp::I2c& i_I2C_ro, uint32_t i_DeviceAddress_u8) ME_OVERRIDE;

  virtual void     deInit_v() ME_OVERRIDE;

  virtual bool_t   write_b(uint32_t i_RegisterAddress_u16, uint32_t i_WriteValue_u32, uint32_t i_Size_u32);

  virtual bool_t   write_b(uint32_t i_RegisterAddress_u16, const uint32_t* b_Buffer_pu16, uint32_t i_BufferLength_u32) ME_OVERRIDE;

  virtual bool_t   read_b(uint32_t i_RegisterAddress_u16, uint32_t* b_Buffer_pu16, uint32_t i_BufferLength_u32) ME_OVERRIDE;

  virtual bool_t   runCommand_b(sint8_t i_Command_s8) ME_OVERRIDE;

public:

  bool_t           issueHostCommand_b(uint32_t i_Command_u32, bool_t i_CheckDoorbell_b);

  bool_t           disableStreaming_b();

public:

  bool_t           isStreaming_b();

  bool_t           isErrorFlagActive_b();

private:

  bool_t           configStreamingMode_b();

  bool_t           configTriggerMode_b();

  bool_t           configTestPattern_b(variants::CamTestPattern_t i_CameraTestPattern_t);

  bool_t           changeConfig_b();

  /// -----------------------------------------------------------------------------------
  /// Setter

  bool_t           getHostCommandRegister_b(uint32_t& o_RegValue_ru32);

  bool_t           getState_b(uint8_t& o_State_ru8);

  /// -----------------------------------------------------------------------------------
  /// Setter

  bool_t           setState_b(uint8_t i_State_u8);

private:

  bsp::I2c*   i2c_po;

  uint8_t     deviceAddress_u8;

};

}

#endif // IMAGER_AS0149_H_
