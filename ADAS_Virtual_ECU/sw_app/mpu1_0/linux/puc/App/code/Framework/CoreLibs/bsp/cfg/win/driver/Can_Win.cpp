//--------------------------------------------------------------------------
/// @file Can_Win.cpp
/// @brief Class implementation of Can server
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------


// ==========================================================================
// Includes
// ==========================================================================
#include "bsp/driver/Can.h"
#include "osal/networking/INetworkMsgHandler.h"


namespace bsp
{

#ifdef ME_PLATFORM_WIN

Can::Can()
  : INetwork()
  , canChannelType_e(e_CanRxChannel)
  , canChannelStatus_e(e_ChannelStatusSendFailed)
  , canHandleRx_t()
  , canHandleTx_t()
  , msgHandler_po(NULL)
{
}

Can::~Can()
{
}

void Can::init_v(const uint8_t& i_ChannelId_ru8)
{
  AssertMsg(i_ChannelId_ru8 <= e_CanChannelCnt, "Unexpected CAN channel type %d \r\n", i_ChannelId_ru8);
  canChannelType_e = static_cast<CanChannelType_t>(i_ChannelId_ru8);
}

bool_t Can::open_b()
{
  bool_t v_Result_b = true;
  return v_Result_b;
}

bool_t Can::registerHandler_b(osal::INetworkMsgHandler* b_Handler_po)
{
  bool_t v_Result_b = true;

  Assert(NULL == msgHandler_po);
  Assert(NULL != b_Handler_po);
  msgHandler_po = b_Handler_po;

  return v_Result_b;
}

bool_t Can::process_b()
{
  bool_t v_Result_b = false;
  return v_Result_b;
}

void Can::shutdown_v()
{
  canChannelStatus_e = e_ChannelStatusClosed;
}

bool_t Can::send_b(const uint8_t* i_Buffer_pu8, size_t i_BufferLength_t)
{
  bool_t v_Result_b = true;
  return v_Result_b;
}

#endif // ME_PLATFORM_WIN

} // namespace bsp
