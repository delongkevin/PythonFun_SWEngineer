//--------------------------------------------------------------------------
/// @file I2c.h
/// @brief Implementation of an interface for a UART configurable device
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

#ifndef UART_H_
#define UART_H_

#include "cfg/BspTypes.h"

namespace bsp
{
  class Uart
  {
  public:

    Uart();

    ~Uart();

    bool_t   init_b();

    void     deInit_v() const;

    bool_t   send_b(const uint8_t* i_Buffer_pu8, size_t i_BufferLength_t) const;

    bool_t   recv_b(uint8_t* o_RecvData_pu8, size_t i_BufferLength_t) const;

  private:

    UartHandle_t   uartHandle_t;
  };

} // namespace bsp

#endif // I2C_H_
