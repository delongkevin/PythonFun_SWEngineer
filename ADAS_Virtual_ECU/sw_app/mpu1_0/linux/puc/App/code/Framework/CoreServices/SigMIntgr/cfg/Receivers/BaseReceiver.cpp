//--------------------------------------------------------------------------
/// @file BaseReceiver.cpp
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

#include "BaseReceiver.h"
#include "sigm/JobSigM.h"


namespace sigm
{

BaseReceiver::BaseReceiver(IpcMsgId_t i_ReceiveID_t,
                         uint32_t i_FrameCountTimeout_u32)
: dataProvider_po(NULL)
, jobSigM_po(NULL)
, channel_u32(0U)
, m_MsgReceived(0,0)
, receiveID_t(i_ReceiveID_t)
, receiveControl_s()
, frameCountTimeout_u32(i_FrameCountTimeout_u32)
, mutex_o()
{

}

BaseReceiver::~BaseReceiver()
{
}

void BaseReceiver::init_v(sigm::IDataProviderSigM& b_DataProvider_ro, JobSigM& b_JobSigM_ro)
{
  // PRQA S 2516 3 // parameter objects are not deleted -> objects are ensured to exist after init_v call
  dataProvider_po = &b_DataProvider_ro;

  jobSigM_po = &b_JobSigM_ro;
}

void BaseReceiver::setReceivedMsg_v(const ME_MsgRx_s& i_MsgReceived_ro)
{
  m_MsgReceived = i_MsgReceived_ro;
}

bool_t BaseReceiver::handleReceive_b()
{
  bool_t v_SendResponse_b = false;
  v_SendResponse_b = handleSpecificReceiver_b(); // handle specific request in derived class
  return v_SendResponse_b;
}

IpcMsgId_t BaseReceiver::getReceiveID_t() const
{
  return receiveID_t;
}

bool_t BaseReceiver::readFromBuffer(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32,  uint8_t * dest){
	return true;
}

bool_t BaseReceiver::isActive_b()
{
  mutex_o.take_b();
  return (receiveControl_s.receivedAt_u32 > receiveControl_s.processedAt_u32);
  mutex_o.give_v();
}

void BaseReceiver::setProcessed_v()
{
  mutex_o.take_b();
  receiveControl_s.processedAt_u32 = receiveControl_s.receivedAt_u32 +1;
  mutex_o.give_v();
}

void BaseReceiver::setReceived_v()
{
  mutex_o.take_b();
  receiveControl_s.receivedAt_u32 = receiveControl_s.processedAt_u32 + 1;
  mutex_o.give_v();
  //logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskDlt, "Received %d & Procesed %d \n",receiveControl_s.receivedAt_u32, receiveControl_s.processedAt_u32 );
}

bool_t BaseReceiver::setProcess_b()
{
 // logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskDlt, "BaseReceiver::setProcess_b(): \n");

  setProcessed_v();

  return true;
}

uint32_t BaseReceiver::addSendIdHeader_u32(uint8_t* b_Data_pu8) const
{
//  return addHeaderToMessage_u32(b_Data_pu8, sendID_t);
  return 0;
}

void BaseReceiver::setDelayed_v()
{
 //
}

bool_t BaseReceiver::checkForTimeout_b() const
{

  return true;
}

} // namespace sigm
