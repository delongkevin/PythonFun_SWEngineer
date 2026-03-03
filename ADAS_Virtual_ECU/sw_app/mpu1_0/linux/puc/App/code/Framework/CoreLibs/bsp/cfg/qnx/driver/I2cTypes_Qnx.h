//--------------------------------------------------------------------------
/// @file I2cTypes_QNX.h
/// @brief Header for Qnx Specific Standard Library Types
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

#ifndef I2C_TYPES_QNX_H_
#define I2C_TYPES_QNX_H_

#include <platform/PlatformAPI.h>

#ifdef ME_PLATFORM_QNX

// --------------------------------------------------------------------
// I2c
// --------------------------------------------------------------------

#include <hw/i2c.h>

enum I2cFormat_e
{
  e_I2cFormat7Bit = I2C_ADDRFMT_7BIT,
  e_I2cFormat10Bit = I2C_ADDRFMT_10BIT
};

typedef struct SendMessageQnx_s
{
  i2c_send_t header_t;
  uint8_t    sendBuffer_au8[I2C_SEND_BUFFER_SIZE];
} SendMessage_t;

typedef struct RecvMessageQnx_s
{
  i2c_recv_t header_t;
  uint8_t    recvBuffer_au8[I2C_BUFFER_SIZE];
} RecvMessage_t;


class I2cSendHandle : public DeviceDataHandle
{

public:

  I2cSendHandle()
  : DeviceDataHandle()
  , sendMessage_t()
  {

  }

  virtual ~I2cSendHandle()
  {

  }

  virtual bool_t init_b()
  {
    return true;
  }

  virtual bool_t deInit_b()
  {
    return true;
  }

  virtual void* getData_pv()
  {
    return &sendMessage_t;
  }

  virtual uint32_t getSize_u32()
  {
    return (sizeof(sendMessage_t.header_t) + sendMessage_t.header_t.len);
  }

  void config_v(I2cSendConfig_t& i_I2cHandle_ro)
  {
    sendMessage_t.header_t.slave.fmt = i_I2cHandle_ro.format_u32;
    sendMessage_t.header_t.slave.addr = i_I2cHandle_ro.deviceAddress_u32;
    sendMessage_t.header_t.stop = i_I2cHandle_ro.stop_b;
    sendMessage_t.header_t.len = i_I2cHandle_ro.length_u32;

    if(i_I2cHandle_ro.is16BitRegister_b == true)
    {
      sendMessage_t.sendBuffer_au8[1] = (uint8_t)((i_I2cHandle_ro.registerAddress_u16 & 0x00FF) >> 0);
      sendMessage_t.sendBuffer_au8[0] = (uint8_t)((i_I2cHandle_ro.registerAddress_u16 & 0xFF00) >> 8);
      memcpy(&sendMessage_t.sendBuffer_au8[2], &i_I2cHandle_ro.sendBuffer_au8[0], sendMessage_t.header_t.len);
    }
    else
    {
      sendMessage_t.sendBuffer_au8[0] = (uint8_t)((i_I2cHandle_ro.registerAddress_u16 & 0x00FF));
      memcpy(&sendMessage_t.sendBuffer_au8[1], &i_I2cHandle_ro.sendBuffer_au8[0], sendMessage_t.header_t.len);
    }
  }

private:

  SendMessage_t sendMessage_t;

};

class I2cRecvHandle : public DeviceDataHandle
{

public:

  I2cRecvHandle()
  : DeviceDataHandle()
  , recvMessage_t()
  {

  }

  virtual ~I2cRecvHandle()
  {

  }

  virtual bool_t init_b()
  {
    return true;
  }

  virtual bool_t deInit_b()
  {
    return true;
  }

  virtual void* getData_pv()
  {
    return &recvMessage_t;
  }

  virtual void getConfig_ro(I2cRecvConfig_s& o_Config_ro)
  {
    memcpy(&o_Config_ro.recvBuffer_au8[0], &recvMessage_t.recvBuffer_au8[0], recvMessage_t.header_t.len);
  }

  virtual uint32_t getSize_u32()
  {
    return (sizeof(recvMessage_t.header_t) + recvMessage_t.header_t.len);
  }

  void config_v(I2cRecvConfig_t& i_I2cHandle_ro)
  {
    recvMessage_t.header_t.slave.fmt = i_I2cHandle_ro.format_u32;
    recvMessage_t.header_t.slave.addr = i_I2cHandle_ro.deviceAddress_u32;
    recvMessage_t.header_t.stop = i_I2cHandle_ro.stop_b;
    recvMessage_t.header_t.len = i_I2cHandle_ro.length_u32;
  }

private:

  RecvMessage_t recvMessage_t;

};

#endif // ME_PLATFORM_QNX

#endif // I2C_TYPES_QNX_H_
