//--------------------------------------------------------------------------
/// @file I2cTypes_Win.h
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

#ifndef I2C_TYPES_WIN_H_
#define I2C_TYPES_WIN_H_

#include <platform/PlatformAPI.h>

#ifdef ME_PLATFORM_WIN

// --------------------------------------------------------------------
// I2c
// --------------------------------------------------------------------

enum I2cFormat_e
{
  e_I2cFormat7Bit = 0,
  e_I2cFormat10Bit
};

typedef struct SendMessageQnx_s
{
  uint8_t    sendBuffer_au8[I2C_SEND_BUFFER_SIZE];
} SendMessage_t;

typedef struct RecvMessageQnx_s
{
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
    return 0;
  }

  void config_v(I2cSendConfig_t& i_I2cHandle_ro)
  {
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
  }

  virtual uint32_t getSize_u32()
  {
    return 0;
  }

  void config_v(I2cRecvConfig_t& i_I2cHandle_ro)
  {
  }

private:

  RecvMessage_t recvMessage_t;

};

#endif // ME_PLATFORM_QNX

#endif // I2C_TYPES_WIN_H_
