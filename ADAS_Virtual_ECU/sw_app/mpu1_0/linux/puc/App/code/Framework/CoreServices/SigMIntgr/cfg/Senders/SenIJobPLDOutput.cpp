//--------------------------------------------------------------------------
/// @file SenIJobPLDOutput.cpp
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

#include "SenIJobPLDOutput.h"

namespace sigm
{

SenIJobPLDOutput::SenIJobPLDOutput()
 : BaseSender(e_IpcMsgId_PpJobPLDData_IJobPLDOutput_t, 50)
{
}

SenIJobPLDOutput::~SenIJobPLDOutput()
{
}

bool_t SenIJobPLDOutput::handleSpecificSender_b()
{
  if (true == handle_IJobPLDOutput_b())
  {
    // receive is done

  }
  // always respond
  return true;
}

bool_t SenIJobPLDOutput::handle_IJobPLDOutput_b()
{
	bool_t v_RequestOk_b;
  IJobPLDOutput_t v_NewMsgSend_t = dataProvider_po->getIJobPLDOutput_t();

  msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<IJobPLDOutput_t>();
  uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0],e_IpcMsgId_PpJobPLDData_IJobPLDOutput_t );
  memcpy(&msgToRespond_s.data_t[v_Index_u32], &v_NewMsgSend_t, msgToRespond_s.msgSize_u32);
  logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " IJobPLDOutput Signals sent \n");

  return v_RequestOk_b;
}


} /* namespace sigm */
