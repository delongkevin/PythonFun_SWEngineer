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
/// @author Martin Rachor (martin.rachor@Magna.com)
///
//  --------------------------------------------------------------------------

#include "bsp/driver/Uart.h"

namespace bsp
{

#ifdef ME_PLATFORM_QNX

Uart::Uart()
  : uartHandle_t(0)
{
}

Uart::~Uart()
{
}

bool_t Uart::init_b()
{
  bool_t v_Result_b = false;

  uartHandle_t = open("/dev/ser2", O_RDWR); // PRQA S 3600 // O_RDWR is a QNX define

  if(uartHandle_t > 0)
  {
    v_Result_b = true;
  }

  return v_Result_b;
}

void Uart::deInit_v() const
{
  close(uartHandle_t);
}

bool_t Uart::send_b(const uint8_t* i_Buffer_pu8, size_t i_BufferLength_t) const
{
  bool_t v_Result_b = true;

  if(0 > write(uartHandle_t, i_Buffer_pu8, i_BufferLength_t))
  {
    v_Result_b = false;
  }

  return v_Result_b;
}


bool_t Uart::recv_b(uint8_t* o_RecvData_pu8, size_t i_BufferLength_t) const
{
  bool_t v_Result_b = true;

  if(0 > read(uartHandle_t, o_RecvData_pu8, i_BufferLength_t))
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

#endif // ME_PLATFORM_QNX

} // namespace bsp
