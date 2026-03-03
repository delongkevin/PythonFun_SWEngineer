//--------------------------------------------------------------------------
/// @file SenIParkingSlotInformation.cpp
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
///  *  @author sagar.saste@magna.com
///
//  --------------------------------------------------------------------------

#include "SenIParkingSlotInformation.h"

namespace sigm
{

SenIParkingSlotInformation::SenIParkingSlotInformation()
 : BaseSender(e_IpcMsgId_Data_IParkingSlotInformation_t, 50)
{
}

SenIParkingSlotInformation::~SenIParkingSlotInformation()
{
}

bool_t SenIParkingSlotInformation::handleSpecificSender_b()
{
  if (true == handle_IParkingSlotInformation_b())
  {
    // receive is done

  }
  // always respond
  return true;
}

bool_t SenIParkingSlotInformation::handle_IParkingSlotInformation_b()
{
	bool_t v_RequestOk_b;
  IParkingSlotInformation_t v_NewMsgSend_t = dataProvider_po->getIParkingSlotInformation_t();

  msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<IParkingSlotInformation_t>();
  uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_Data_IParkingSlotInformation_t);
  memcpy(&msgToRespond_s.data_t[v_Index_u32], &v_NewMsgSend_t, msgToRespond_s.msgSize_u32);
//  v_RequestOk_b = writeIParkingSlotInformation_b(&msgToRespond_s.data_t[v_Index_u32], msgToRespond_s.msgSize_u32, &v_NewMsgSend_t);
  logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " IParkingSlotInformation Signals sent \n");

  return v_RequestOk_b;
}


} /* namespace sigm */
