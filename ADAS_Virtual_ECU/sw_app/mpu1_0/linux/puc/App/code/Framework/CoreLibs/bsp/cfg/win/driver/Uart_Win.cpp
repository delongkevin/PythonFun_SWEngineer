//--------------------------------------------------------------------------
/// @file Uart_Win.cpp
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

#ifdef ME_PLATFORM_WIN

Uart::Uart()
  : uartHandle_t()
{
}

Uart::~Uart()
{
}

bool_t Uart::init_b()
{
  bool_t v_Result_b = true;
  return v_Result_b;
}

void Uart::deInit_v() const
{
}

bool_t Uart::send_b(const uint8_t* i_Buffer_pu8, size_t i_BufferLength_t) const
{
  bool_t v_Result_b = true;
  return v_Result_b;
}


bool_t Uart::recv_b(uint8_t* o_RecvData_pu8, size_t i_BufferLength_t) const
{
  bool_t v_Result_b = true;
  return v_Result_b;
}

#endif // ME_PLATFORM_WIN

} // namespace bsp
