//--------------------------------------------------------------------------
/// @file SenMOT_Output.cpp
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

#include "SenMOT_Output.h"

namespace sigm
{

SenMOT_Output::SenMOT_Output()
 : BaseSender(e_IpcMsgId_Data_MOT_Output, 50)
{
}

SenMOT_Output::~SenMOT_Output()
{
}

bool_t SenMOT_Output::handleSpecificSender_b()
{
  if (true == handle_MOT_OutputSender_b())
  {
    // receive is done

  }
  // always respond
  return true;
}

bool_t SenMOT_Output::handle_MOT_OutputSender_b()
{
	bool_t v_RequestOk_b = false;
   MOT_Output v_NewMsgSend_t = dataProvider_po->getMOT_Output_t();

   msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<MOT_Output>();
   uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_Data_MOT_Output);
   if(msgToRespond_s.msgSize_u32 > 0)
   {
	   v_RequestOk_b = true;
	   memcpy(&msgToRespond_s.data_t[v_Index_u32], &v_NewMsgSend_t, msgToRespond_s.msgSize_u32);
	   logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " MOT_Output_t Signals sent \n");
   }
  return v_RequestOk_b;
}


} /* namespace sigm */
