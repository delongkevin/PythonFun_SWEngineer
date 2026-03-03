//--------------------------------------------------------------------------
/// @file I2c.h
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

#ifndef I2C_H_
#define I2C_H_

#include <osal/threading/Mutex.h>

#include "cfg/BspTypes.h"

namespace bsp
{

  class I2c
  {

  public:

    I2c();

    ~I2c();

    bool_t   init_b(const char_t* i_Port_pc);

    bool_t   init_b(const char_t* i_Port_pc, uint8_t i_DeviceAddress_u8);

    void     deInit_v();

    bool_t   lock_b();

    bool_t   unlock_b();

    template<typename T>
    bool_t   send_b(T i_RegisterAddress_x, const T* i_Buffer_px, size_t i_BufferLength_t, bool_t i_SendRecv_b);

    template<typename T>
    bool_t   send_b(T i_DeviceAddress_x, T i_RegisterAddress_x, const T* i_Buffer_px, size_t i_BufferLength_t, bool_t i_SendRecv_b);

    template<typename T>
    bool_t   recv_b(T i_RegisterAddress_x, T* o_RecvData_px, size_t i_BufferLength_t);

    template<typename T>
    bool_t   recv_b(T i_DeviceAddress_x, T i_RegisterAddress_x, T* o_RecvData_px, size_t i_BufferLength_t);

    template<typename T>
    bool_t   sendRecv_b(T i_RegisterAddress_x, T* b_Buffer_px, size_t i_BufferLength_t);

    template<typename T>
    bool_t   sendRecv_b(T i_DeviceAddress_x, T i_RegisterAddress_x, T* b_Buffer_px, size_t i_BufferLength_t);

  protected:

    osal::Mutex   mutex_o;

    I2cHandle_t   i2cHandle_t;
  };

} // namespace bsp

#endif // I2C_H_
