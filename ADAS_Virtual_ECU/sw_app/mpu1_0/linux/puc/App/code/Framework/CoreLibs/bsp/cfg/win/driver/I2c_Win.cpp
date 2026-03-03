//--------------------------------------------------------------------------
/// @file I2c_Win.cpp
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

#include "bsp/driver/I2c.h"

#include <platform/stdlib/ME_Thread.h>

namespace bsp
{

#ifdef ME_PLATFORM_WIN

I2c::I2c()
{
}

I2c::~I2c()
{
}

bool_t I2c::init_b(const char_t* i_Port_pc)
{
  bool_t v_Result_b = false;

  return v_Result_b;
}

bool_t I2c::init_b(const char_t* i_Port_pc, uint8_t i_DeviceAddress_u8)
{
  bool_t v_Result_b = false;

  return v_Result_b;
}

void I2c::deInit_v()
{
}


bool_t I2c::lock_b()
{
  return true;
}

bool_t I2c::unlock_b()
{
  return true;
}

template<>
bool_t I2c::send_b<uint8_t>(uint8_t i_RegisterAddress_u8, const uint8_t* i_Buffer_pu8, size_t i_BufferLength_t, bool_t i_SendRecv_b)
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

template<>
bool_t I2c::send_b<uint8_t>(uint8_t i_DeviceAddress_u8, uint8_t i_RegisterAddress_u8, const uint8_t* i_Buffer_pu8, size_t i_BufferLength_t, bool_t i_SendRecv_b)
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

template<>
bool_t I2c::send_b<uint16_t>(uint16_t i_RegisterAddress_u16, const uint16_t* i_Buffer_pu16, size_t i_BufferLength_t, bool_t i_SendRecv_b)
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

template<>
bool_t I2c::send_b<uint16_t>(uint16_t i_DeviceAddress_u16, uint16_t i_RegisterAddress_u16, const uint16_t* i_Buffer_pu16, size_t i_BufferLength_t, bool_t i_SendRecv_b)
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

template<>
bool_t I2c::recv_b<uint8_t>(uint8_t i_RegisterAddress_u8, uint8_t* o_RecvData_pu8, size_t i_BufferLength_t)
{
  bool_t v_Result_b = true;
  return v_Result_b;
}

template<>
bool_t I2c::recv_b<uint8_t>(uint8_t i_DeviceAddress_u8, uint8_t i_RegisterAddress_u8, uint8_t* o_RecvData_pu8, size_t i_BufferLength_t)
{
  bool_t v_Result_b = true;
  return v_Result_b;
}

template<>
bool_t I2c::recv_b<uint16_t>(uint16_t i_RegisterAddress_u16, uint16_t* o_RecvData_pu16, size_t i_BufferLength_t)
{
  bool_t v_Result_b = true;
  return v_Result_b;
}

template<>
bool_t I2c::recv_b<uint16_t>(uint16_t i_DeviceAddress_u16, uint16_t i_RegisterAddress_u16, uint16_t* o_RecvData_pu16, size_t i_BufferLength_t)
{
  bool_t v_Result_b = true;
  return v_Result_b;
}

template<>
bool_t I2c::sendRecv_b<uint8_t>(uint8_t i_RegisterAddress_u8, uint8_t* b_Buffer_pu8, size_t i_BufferLength_t)
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

template<>
bool_t I2c::sendRecv_b<uint8_t>(uint8_t i_DeviceAddress_u8, uint8_t i_RegisterAddress_u8, uint8_t* b_Buffer_pu8, size_t i_BufferLength_t)
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

template<>
bool_t I2c::sendRecv_b<uint16_t>(uint16_t i_RegisterAddress_u16, uint16_t* b_Buffer_pu8, size_t i_BufferLength_t)
{
  bool_t v_Result_b = true;
  return v_Result_b;
}

template<>
bool_t I2c::sendRecv_b<uint16_t>(uint16_t i_DeviceAddress_u16, uint16_t i_RegisterAddress_u16, uint16_t* b_Buffer_pu8, size_t i_BufferLength_t)
{
  bool_t v_Result_b = true;
  return v_Result_b;
}

#endif // ME_PLATFORM_WIN

} // namespace bsp
