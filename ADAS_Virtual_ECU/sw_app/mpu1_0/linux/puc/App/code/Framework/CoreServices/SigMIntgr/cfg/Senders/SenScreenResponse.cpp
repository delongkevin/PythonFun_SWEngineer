//--------------------------------------------------------------------------
/// @file SenScreenResponse.cpp
/// @brief Contains
///
///
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Ananda Kavrady (Ananda.kavrady@magna.com)
///
//  --------------------------------------------------------------------------

#include "SenScreenResponse.h"

namespace sigm
{

SenScreenResponse::SenScreenResponse()
 : BaseSender(e_IpcMsgId_PpScreenResponse_ScreenResponse_t, 50)
{
}

SenScreenResponse::~SenScreenResponse()
{
}

bool_t SenScreenResponse::handleSpecificSender_b()
{
  if (true == handle_ScreenResponseSender_b())
  {
    // receive is done

  }
  // always respond
  return true;
}

bool_t SenScreenResponse::handle_ScreenResponseSender_b()
{

  ScreenResponse_t v_NewMsgSend_t = dataProvider_po->getScreenResponse_t();

  msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<ScreenResponse_t>();
  uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_PpScreenResponse_ScreenResponse_t);
  bool_t v_RequestOk_b = writeScreenResponse_b(&msgToRespond_s.data_t[v_Index_u32], msgToRespond_s.msgSize_u32, &v_NewMsgSend_t);
  logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, " SenScreenResponse Signals sent \n");

  return v_RequestOk_b;
}


} /* namespace sigm */
