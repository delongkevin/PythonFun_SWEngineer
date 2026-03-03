//--------------------------------------------------------------------------
/// @file Deserializer.cpp
/// @brief Implementation of Shared Memory camera grabber
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Gangadhar Reddy Yadiki (Gangadhar Reddy.Yadiki@Magna.com)
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#include "bsp/driver/I2c.h"

#include <platform/stdlib/ME_Thread.h>


// PRQA S 2427 EOF // Due to QNX definitions
// PRQA S 3080 EOF // Due to QNX definitions
// PRQA S 3604 EOF // Due to QNX definitions

namespace bsp
{

#ifdef ME_PLATFORM_QNX

I2c::I2c()
  : mutex_o()
  , i2cHandle_t()
{
}

I2c::~I2c()
{
}

bool_t I2c::init_b(const char_t* i_Port_pc)
{
  bool_t v_Result_b = false;
  sint32_t v_Error_s32 = EINVAL;


  MEP_BEGIN("init", "I2C");

  i2cHandle_t.i2cHandle_s32 = open(i_Port_pc, O_RDWR); // PRQA S 3600 // O_RDWR is a QNX define

  if(i2cHandle_t.i2cHandle_s32 > 0)
  {
    i2cHandle_t.i2cSlaveAddress_t.fmt  = I2C_ADDRFMT_7BIT;
  }

  if(v_Error_s32 == EOK)
  {
   v_Result_b = true;
  }

  MEP_END("init", "I2C");

  return v_Result_b;
}

bool_t I2c::init_b(const char_t* i_Port_pc, uint8_t i_DeviceAddress_u8)
{
  bool_t v_Result_b = false;
  sint32_t v_Error_s32 = EINVAL;


  MEP_BEGIN("init", "I2C");

  i2cHandle_t.i2cHandle_s32 = open(i_Port_pc, O_RDWR); // PRQA S 3600 // O_RDWR is a QNX define

  if(i2cHandle_t.i2cHandle_s32 > 0)
  {
    i2cHandle_t.i2cSlaveAddress_t.addr = i_DeviceAddress_u8;
    i2cHandle_t.i2cSlaveAddress_t.fmt  = I2C_ADDRFMT_7BIT;

    v_Error_s32 = devctl(i2cHandle_t.i2cHandle_s32, DCMD_I2C_SET_SLAVE_ADDR, &i2cHandle_t.i2cSlaveAddress_t, sizeof(i2c_addr_t), NULL);
  }

  if(v_Error_s32 == EOK)
  {
   v_Result_b = true;
  }

  MEP_END("init", "I2C");

  return v_Result_b;
}

bool_t I2c::lock_b()
{
  return mutex_o.take_b(true);
}

bool_t I2c::unlock_b()
{
  mutex_o.give_v();

  return true;
}

void I2c::deInit_v()
{
  close(i2cHandle_t.i2cHandle_s32);

  i2cHandle_t.i2cHandle_s32 = ME_INVALID_FILE_HANDLE; // PRQA S 1021 // invalid file handle is defined in shared c and cpp file

  open("/dev/tiipc0", O_RDWR);
  (void)memset(&i2cHandle_t.i2cSlaveAddress_t, 0, sizeof(i2c_addr_t));
}

template<>
bool_t I2c::send_b<uint8_t>(uint8_t i_RegisterAddress_u8, const uint8_t* i_Buffer_pu8, size_t i_BufferLength_t, bool_t i_SendRecv_b)
{
  bool_t v_Result_b = true;
  sint32_t v_Error_s32 = EINVAL;

  SendMessage_t v_Message_t;

  mutex_o.take_b();

  v_Message_t.header_t.slave = i2cHandle_t.i2cSlaveAddress_t;
  v_Message_t.header_t.len = i_BufferLength_t + 1;
  v_Message_t.header_t.stop = static_cast<uint32_t>(i_SendRecv_b);
  v_Message_t.sendBuffer_au8[0] = i_RegisterAddress_u8;

  if(i_SendRecv_b == false)
  {
    if((i_Buffer_pu8 != NULL) && (v_Message_t.header_t.len <= I2C_SEND_BUFFER_SIZE))
    {
      (void)memcpy(&v_Message_t.sendBuffer_au8[1], i_Buffer_pu8, i_BufferLength_t);
      v_Error_s32 = EOK;
    }
    else
    {
      v_Error_s32 = EINVAL;
    }
  }
  else
  {
    v_Error_s32 = EOK;
  }

  if(v_Error_s32 == EOK)
  {
    uint32_t v_Size_u32 = (sizeof(v_Message_t.header_t)) + v_Message_t.header_t.len;
    v_Error_s32 = devctl(i2cHandle_t.i2cHandle_s32, DCMD_I2C_SEND, &v_Message_t, v_Size_u32, NULL);
  }

  if(v_Error_s32 != EOK)
  {
    v_Result_b = false;
    ME_Debugger_F_Printf_v("I2C 0x%x error %d\n", i2cHandle_t.i2cSlaveAddress_t, v_Error_s32);
  }

  mutex_o.give_v();

  return v_Result_b;
}

template<>
bool_t I2c::send_b<uint8_t>(uint8_t i_DeviceAddress_u8, uint8_t i_RegisterAddress_u8, const uint8_t* i_Buffer_pu8, size_t i_BufferLength_t, bool_t i_SendRecv_b)
{
  bool_t v_Result_b = true;
  sint32_t v_Error_s32 = EINVAL;

  SendMessage_t v_Message_t;

  mutex_o.take_b();

  v_Message_t.header_t.slave.addr = i_DeviceAddress_u8;
  v_Message_t.header_t.slave.fmt = I2C_ADDRFMT_7BIT;
  v_Message_t.header_t.len = i_BufferLength_t + 1;
  v_Message_t.header_t.stop = static_cast<uint32_t>(i_SendRecv_b);
  v_Message_t.sendBuffer_au8[0] = i_RegisterAddress_u8;

  if(i_SendRecv_b == false)
  {
    if((i_Buffer_pu8 != NULL) && (v_Message_t.header_t.len <= I2C_SEND_BUFFER_SIZE))
    {
      (void)memcpy(&v_Message_t.sendBuffer_au8[1], i_Buffer_pu8, i_BufferLength_t);
      v_Error_s32 = EOK;
    }
    else
    {
      v_Error_s32 = EINVAL;
    }
  }
  else
  {
    v_Error_s32 = EOK;
  }

  if(v_Error_s32 == EOK)
  {
    uint32_t v_Size_u32 = (sizeof(v_Message_t.header_t)) + v_Message_t.header_t.len;

    v_Error_s32 = devctl(i2cHandle_t.i2cHandle_s32, DCMD_I2C_SEND, &v_Message_t, v_Size_u32, NULL);
  }

  if(v_Error_s32 != EOK)
  {
    v_Result_b = false;
    ME_Debugger_F_Printf_v("I2C 0x%x error %d\n", i_DeviceAddress_u8, v_Error_s32);
  }

  mutex_o.give_v();

  return v_Result_b;
}

template<>
bool_t I2c::send_b<uint16_t>(uint16_t i_RegisterAddress_u16, const uint16_t* i_Buffer_pu16, size_t i_BufferLength_t, bool_t i_SendRecv_b)
{
  bool_t v_Result_b = true;
  sint32_t v_Error_s32 = EINVAL;

  SendMessage_t v_Message_t;

  mutex_o.take_b();

  v_Message_t.header_t.slave = i2cHandle_t.i2cSlaveAddress_t;
  v_Message_t.header_t.len = i_BufferLength_t + sizeof(uint16_t); // increment with size of i_RegisterAddress_u16
  v_Message_t.header_t.stop = (uint32_t)(true && i_SendRecv_b);
  v_Message_t.sendBuffer_au8[1] = (uint8_t)((i_RegisterAddress_u16 & 0x00FF) >> 0);
  v_Message_t.sendBuffer_au8[0] = (uint8_t)((i_RegisterAddress_u16 & 0xFF00) >> 8);


  if(i_SendRecv_b == false)
  {
    if((i_Buffer_pu16 != NULL) && (v_Message_t.header_t.len <= I2C_SEND_BUFFER_SIZE))
    {        
      (void)memcpy(&v_Message_t.sendBuffer_au8[sizeof(uint16_t)], i_Buffer_pu16, i_BufferLength_t);
      v_Error_s32 = EOK;
    }
    else
    {
       v_Error_s32 = EINVAL;
    }
  }
  else
  {
    v_Error_s32 = EOK;
  }

  if(v_Error_s32 == EOK)
  {
    uint32_t v_Size_u32 = (sizeof(v_Message_t.header_t)) + v_Message_t.header_t.len;
    v_Error_s32 = devctl(i2cHandle_t.i2cHandle_s32, DCMD_I2C_SEND, &v_Message_t, v_Size_u32, NULL);
  }

  if(v_Error_s32 != EOK)
  {
    v_Result_b = false;
    ME_Debugger_F_Printf_v("I2C 0x%x error %d\n", i2cHandle_t.i2cSlaveAddress_t, v_Error_s32);
  }

  mutex_o.give_v();

  return v_Result_b;
}

template<>
bool_t I2c::send_b<uint16_t>(uint16_t i_DeviceAddress_u16, uint16_t i_RegisterAddress_u16, const uint16_t* i_Buffer_pu16, size_t i_BufferLength_t, bool_t i_SendRecv_b)
{
  bool_t v_Result_b = true;
  sint32_t v_Error_s32 = EINVAL;

  SendMessage_t v_Message_t;

  mutex_o.take_b();

  v_Message_t.header_t.slave.addr = i_DeviceAddress_u16;
  v_Message_t.header_t.slave.fmt = I2C_ADDRFMT_7BIT;
  v_Message_t.header_t.len = i_BufferLength_t + sizeof(uint16_t); // increment with size of i_RegisterAddress_u16
  v_Message_t.header_t.stop = (uint32_t)(true && i_SendRecv_b);
  v_Message_t.sendBuffer_au8[1] = (uint8_t)((i_RegisterAddress_u16 & 0x00FF) >> 0);
  v_Message_t.sendBuffer_au8[0] = (uint8_t)((i_RegisterAddress_u16 & 0xFF00) >> 8);


  if(i_SendRecv_b == false)
  {
    if((i_Buffer_pu16 != NULL) && (v_Message_t.header_t.len <= I2C_SEND_BUFFER_SIZE))
    {
      (void)memcpy(&v_Message_t.sendBuffer_au8[sizeof(uint16_t)], i_Buffer_pu16, i_BufferLength_t);
      v_Error_s32 = EOK;
    }
    else
    {
       v_Error_s32 = EINVAL;
    }
  }
  else
  {
    v_Error_s32 = EOK;
  }

  if(v_Error_s32 == EOK)
  {
    uint32_t v_Size_u32 = (sizeof(v_Message_t.header_t)) + v_Message_t.header_t.len;
    v_Error_s32 = devctl(i2cHandle_t.i2cHandle_s32, DCMD_I2C_SEND, &v_Message_t, v_Size_u32, NULL);
  }

  if(v_Error_s32 != EOK)
  {
    v_Result_b = false;
    ME_Debugger_F_Printf_v("I2C 0x%x error %d\n", i_DeviceAddress_u16, v_Error_s32);
  }

  mutex_o.give_v();

  return v_Result_b;
}

template<>
// PRQA S 4327 1 // Parameter 'i_RegisterAddress_u16' not necessary for this project specific implementation
bool_t I2c::recv_b<uint8_t>(uint8_t i_RegisterAddress_u8, uint8_t* o_RecvData_pu8, size_t i_BufferLength_t)
{
  bool_t v_Result_b = true;
  sint32_t v_Error_s32;

  RecvMessage_t v_Message_t;

  if(o_RecvData_pu8 != NULL)
  {
    mutex_o.take_b();
    v_Message_t.header_t.slave = i2cHandle_t.i2cSlaveAddress_t;
    v_Message_t.header_t.len = i_BufferLength_t;
    v_Message_t.header_t.stop = 1;

    uint32_t v_Size_u32 = (sizeof(v_Message_t.header_t)) + v_Message_t.header_t.len;
    v_Error_s32 = devctl(i2cHandle_t.i2cHandle_s32, DCMD_I2C_RECV, &v_Message_t, v_Size_u32, NULL);

    if(v_Error_s32 == EOK)
    {
      if (i_BufferLength_t <= I2C_BUFFER_SIZE)
      {
        (void)memcpy(o_RecvData_pu8, &v_Message_t.recvBuffer_au8[0], i_BufferLength_t);
        memset(&v_Message_t.recvBuffer_au8[0], 0, i_BufferLength_t);
      }
      else
      {
        v_Error_s32 = ENOMEM;
      }
    }
    mutex_o.give_v();
  }
  else
  {
    v_Error_s32 = EINVAL;
  }

  if(v_Error_s32 != EOK)
  {
    v_Result_b = false;
    ME_Debugger_F_Printf_v("I2C 0x%x error %d\n", i2cHandle_t.i2cSlaveAddress_t, v_Error_s32);
  }

  return v_Result_b;
}

template<>
// PRQA S 4327 1 // Parameter 'i_RegisterAddress_u16' not necessary for this project specific implementation
bool_t I2c::recv_b<uint8_t>(uint8_t i_DeviceAddress_u8, uint8_t i_RegisterAddress_u8, uint8_t* o_RecvData_pu8, size_t i_BufferLength_t)
{
  bool_t v_Result_b = true;

  sint32_t v_Error_s32;
  RecvMessage_t v_Message_t;

  if(o_RecvData_pu8 != NULL)
  {
    mutex_o.take_b();
    v_Message_t.header_t.slave.addr = i_DeviceAddress_u8;
    v_Message_t.header_t.slave.fmt = I2C_ADDRFMT_7BIT;
    v_Message_t.header_t.len = i_BufferLength_t;
    v_Message_t.header_t.stop = 1;

    uint32_t v_Size_u32 = (sizeof(v_Message_t.header_t)) + v_Message_t.header_t.len;
    v_Error_s32 = devctl(i2cHandle_t.i2cHandle_s32, DCMD_I2C_RECV, &v_Message_t, v_Size_u32, NULL);

    if(v_Error_s32 == EOK)
    {
      if (i_BufferLength_t <= I2C_BUFFER_SIZE)
      {
        (void)memcpy(o_RecvData_pu8, &v_Message_t.recvBuffer_au8[0], i_BufferLength_t);
        memset(&v_Message_t.recvBuffer_au8[0], 0, i_BufferLength_t);
      }
      else
      {
        v_Error_s32 = ENOMEM;
      }
    }
    mutex_o.give_v();
  }
  else
  {
    v_Error_s32 = EINVAL;
  }

  if(v_Error_s32 != EOK)
  {
    v_Result_b = false;
    ME_Debugger_F_Printf_v("I2C 0x%x error %d\n", i_DeviceAddress_u8, v_Error_s32);
  }

  return v_Result_b;
}

template<>
// PRQA S 4327 1 // Parameter 'i_RegisterAddress_u16' not necessary for this project specific implementation
bool_t I2c::recv_b<uint16_t>(uint16_t i_RegisterAddress_u16, uint16_t* o_RecvData_pu16, size_t i_BufferLength_t)
{
  bool_t v_Result_b = true;

  sint32_t v_Error_s32;
  RecvMessage_t v_Message_t;

  if(o_RecvData_pu16 != NULL)
  {
    mutex_o.take_b();

    v_Message_t.header_t.slave = i2cHandle_t.i2cSlaveAddress_t;
    v_Message_t.header_t.len = i_BufferLength_t;
    v_Message_t.header_t.stop = 1;

    uint32_t v_Size_u32 = (sizeof(v_Message_t.header_t)) + v_Message_t.header_t.len;
    v_Error_s32 = devctl(i2cHandle_t.i2cHandle_s32, DCMD_I2C_RECV, &v_Message_t, v_Size_u32, NULL);

    if(v_Error_s32 == EOK)
    {
      if (i_BufferLength_t <= I2C_BUFFER_SIZE)
      {
        (void)memcpy(o_RecvData_pu16, &v_Message_t.recvBuffer_au8[0], i_BufferLength_t);
        memset(&v_Message_t.recvBuffer_au8[0], 0, i_BufferLength_t);
      }
      else
      {
        v_Error_s32 = ENOMEM;
      }
    }
    mutex_o.give_v();
  }
  else
  {
    v_Error_s32 = EINVAL;
  }

  if(v_Error_s32 != EOK)
  {
    v_Result_b = false;
    ME_Debugger_F_Printf_v("I2C 0x%x error %d\n", i2cHandle_t.i2cSlaveAddress_t, v_Error_s32);
  }

  return v_Result_b;
}

template<>
// PRQA S 4327 1 // Parameter 'i_RegisterAddress_u16' not necessary for this project specific implementation
bool_t I2c::recv_b<uint16_t>(uint16_t i_DeviceAddress_u8, uint16_t i_RegisterAddress_u16, uint16_t* o_RecvData_pu16, size_t i_BufferLength_t)
{
  bool_t v_Result_b = true;

  sint32_t v_Error_s32;
  RecvMessage_t v_Message_t;

  if(o_RecvData_pu16 != NULL)
  {
    mutex_o.take_b();

    v_Message_t.header_t.slave.addr = i_DeviceAddress_u8;
    v_Message_t.header_t.slave.fmt = I2C_ADDRFMT_7BIT;
    v_Message_t.header_t.len = i_BufferLength_t;
    v_Message_t.header_t.stop = 1;

    uint32_t v_Size_u32 = (sizeof(v_Message_t.header_t)) + v_Message_t.header_t.len;

    memset(&v_Message_t.recvBuffer_au8[0], 0, i_BufferLength_t);

    v_Error_s32 = devctl(i2cHandle_t.i2cHandle_s32, DCMD_I2C_RECV, &v_Message_t, v_Size_u32, NULL);

    if(v_Error_s32 == EOK)
    {
      if (i_BufferLength_t <= I2C_BUFFER_SIZE)
      {
        (void)memcpy(o_RecvData_pu16, &v_Message_t.recvBuffer_au8[0], i_BufferLength_t);
      }
      else
      {
        v_Error_s32 = ENOMEM;
      }
    }
    mutex_o.give_v();
  }
  else
  {
    v_Error_s32 = EINVAL;
  }

  if(v_Error_s32 != EOK)
  {
    v_Result_b = false;
    ME_Debugger_F_Printf_v("I2C 0x%x error %d\n", i_DeviceAddress_u8, v_Error_s32);
  }

  return v_Result_b;
}

template<>
bool_t I2c::sendRecv_b<uint8_t>(uint8_t i_RegisterAddress_u8, uint8_t* b_Buffer_pu8, size_t i_BufferLength_t)
{
  uint8_t* v_NullRead_pu8 = 0;

  mutex_o.take_b();
  bool_t v_Result_b = send_b(i_RegisterAddress_u8, v_NullRead_pu8, 0, true);

  if(v_Result_b == true)
  {
    v_Result_b = recv_b(i_RegisterAddress_u8, b_Buffer_pu8, i_BufferLength_t);
  }
  mutex_o.give_v();

  return v_Result_b;
}

template<>
bool_t I2c::sendRecv_b<uint8_t>(uint8_t i_DeviceAddress_u8, uint8_t i_RegisterAddress_u8, uint8_t* b_Buffer_pu8, size_t i_BufferLength_t)
{
  uint8_t* v_NullRead_pu8 = 0;

  mutex_o.take_b();
  bool_t v_Result_b = send_b(i_DeviceAddress_u8, i_RegisterAddress_u8, v_NullRead_pu8, 0, true);

  if(v_Result_b == true)
  {
    v_Result_b = recv_b(i_DeviceAddress_u8, i_RegisterAddress_u8, b_Buffer_pu8, i_BufferLength_t);
  }
  mutex_o.give_v();

  return v_Result_b;
}

template<>
bool_t I2c::sendRecv_b<uint16_t>(uint16_t i_RegisterAddress_u16, uint16_t* b_Buffer_pu8, size_t i_BufferLength_t)
{
  uint16_t* v_NullRead_pu16 = 0;

  mutex_o.take_b();
  bool_t v_Result_b = send_b(i_RegisterAddress_u16, v_NullRead_pu16, 0, true);

  if(v_Result_b == true)
  {
    v_Result_b = recv_b(i_RegisterAddress_u16, b_Buffer_pu8, i_BufferLength_t);
  }
  mutex_o.give_v();

  return v_Result_b;
}

template<>
bool_t I2c::sendRecv_b<uint16_t>(uint16_t i_DeviceAddress_u8, uint16_t i_RegisterAddress_u16, uint16_t* b_Buffer_pu8, size_t i_BufferLength_t)
{
  uint16_t* v_NullRead_pu16 = 0;

  mutex_o.take_b();
  bool_t v_Result_b = send_b(i_DeviceAddress_u8, i_RegisterAddress_u16, v_NullRead_pu16, 0, true);

  if(v_Result_b == true)
  {
    v_Result_b = recv_b(i_DeviceAddress_u8, i_RegisterAddress_u16, b_Buffer_pu8, i_BufferLength_t);
  }
  mutex_o.give_v();

  return v_Result_b;
}

#endif // ME_PLATFORM_QNX

} // namespace bsp
