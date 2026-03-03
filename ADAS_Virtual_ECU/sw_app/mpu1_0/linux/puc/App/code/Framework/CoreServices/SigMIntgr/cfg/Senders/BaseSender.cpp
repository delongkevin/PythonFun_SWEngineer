//--------------------------------------------------------------------------
/// @file BaseSender.cpp
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
/// @author Ananda Kavrady (Ananda.Kavrady@magna.com)
///
//  --------------------------------------------------------------------------

#include "BaseSender.h"
#include "sigm/JobSigM.h"


namespace sigm
{

BaseSender::BaseSender(IpcMsgId_t i_SenderID_t,
                         uint32_t i_FrameCountTimeout_u32)
: dataProvider_po(NULL)
, jobSigM_po(NULL)
, channel_u32(0U)
, msgToRespond_s(0,0)
, senderID_t(i_SenderID_t)
, sendControl_s()
, frameCountTimeout_u32(i_FrameCountTimeout_u32)
{

}

BaseSender::~BaseSender()
{
}

void BaseSender::init_v(sigm::IDataProviderSigM& b_DataProvider_ro, JobSigM& b_JobSigM_ro)
{
  // PRQA S 2516 3 // parameter objects are not deleted -> objects are ensured to exist after init_v call
  dataProvider_po = &b_DataProvider_ro;

  jobSigM_po = &b_JobSigM_ro;
}

bool_t BaseSender::handlSender_b()
{
  bool_t v_SendResponse_b = false;
  v_SendResponse_b = handleSpecificSender_b(); // handle specific request in derived class
  // fill Send data

  return v_SendResponse_b;
}

bool_t BaseSender::sendResponse_b()
{
  //ME_Debugger_F_Printf_v("DMS Sending  from Sigm()...\n");
  jobSigM_po->send_b(&msgToRespond_s.data_t[0], msgToRespond_s.msgSize_u32, channel_u32);

  return true;
}

IpcMsgId_t BaseSender::getSendID_t() const
{
  return senderID_t;
}

bool_t BaseSender::isActive_b()
{
  return (sendControl_s.sendAt_u32 > sendControl_s.processedAt_u32);
}

void BaseSender::setProcessed_v()
{
  sendControl_s.processedAt_u32 = sendControl_s.sendAt_u32 +1;

}

void BaseSender::setReceived_v()
{
  sendControl_s.sendAt_u32 = sendControl_s.processedAt_u32 + 1;
}

bool_t BaseSender::setProcess_b()
{
  logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskDlt, "BaseSender::setProcess_b(): \n");

  setProcessed_v();

  return true;
}

uint32_t BaseSender::addSendIdHeader_u32(uint8_t* b_Data_pu8) const
{
  //return addHeaderToMessage_u32(b_Data_pu8, sendID_t);
	return 0;
}

void BaseSender::setDelayed_v()
{
 //
}

bool_t BaseSender::checkForTimeout_b() const
{


  return true;
}

} // namespace sigm
