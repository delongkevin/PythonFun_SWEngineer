//--------------------------------------------------------------------------
/// @file DeserializerCXD4960ER.h
/// @brief Implementation of the communication interface to CXD4960ER Quad Deserializer
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

#ifndef DESERIALIZER_CXD4960ER_H_
#define DESERIALIZER_CXD4960ER_H_

#include <sensor/devices/DeserializerBase.h>

#include <bsp/driver/I2c.h>

/// General status Monitor 1
#define GENERAL_STATUS_REG_1 0x00U
#define GVIF2TX_ACTIVATED    0x01U
#define GVIF2RX_ACTIVATED    0x02U

/// General status Monitor 2
#define GENERAL_STATUS_REG_2 0x01U
#define GVIF2RX_LOS          0x01U
#define READY                0x10U

/// Error status monitor 1
#define ERROR_STATUS_REG_1   0x10U
#define GVIF2RX_FAIL         0x80U
#define GVIF2TX_FAIL         0x40U
#define VIDEOTX_FAIL         0x10U
#define DAISY_FAIL           0x01U


namespace sensor
{

class DeserializerCXD4960ER : public DeserializerBase<uint32_t>
{

public:

  DeserializerCXD4960ER();

  virtual ~DeserializerCXD4960ER();

  virtual bool_t   init_b(bsp::I2c& i_I2C_ro, uint32_t i_DeviceAddress_u8) ME_OVERRIDE;

  virtual void     deInit_v() ME_OVERRIDE;

  virtual bool_t   write_b(uint32_t i_RegisterAddress_u8, const uint32_t* b_Buffer_pu8, uint32_t i_BufferLength_u32) ME_OVERRIDE;

  virtual bool_t   read_b(uint32_t i_RegisterAddress_u8, uint32_t* b_Buffer_pu8, uint32_t i_BufferLength_u32) ME_OVERRIDE;

  virtual bool_t   runCommand_b(sint8_t i_Command_s8) ME_OVERRIDE;

private:

  bool_t           runInitCmd_b();

  bool_t           runCheckStatus_b();

private:

  uint32_t         deserGeneralStatus1_u32;

  uint32_t         deserGeneralStatus2_u32;

};

}

#endif // DESERIALIZER_CXD4960ER_H_
