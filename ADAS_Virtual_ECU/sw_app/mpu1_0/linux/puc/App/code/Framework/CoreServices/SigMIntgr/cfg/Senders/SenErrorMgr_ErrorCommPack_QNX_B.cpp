//--------------------------------------------------------------------------
/// @file SenErrorMgr_ErrorCommPack_QNX_B.cpp
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

#include "SenErrorMgr_ErrorCommPack_QNX_B.h"

namespace sigm
{

SenErrorMgr_ErrorCommPack_QNX_B::SenErrorMgr_ErrorCommPack_QNX_B()
 : BaseSender(e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B, 50)
{
}

SenErrorMgr_ErrorCommPack_QNX_B::~SenErrorMgr_ErrorCommPack_QNX_B()
{
}

bool_t SenErrorMgr_ErrorCommPack_QNX_B::handleSpecificSender_b()
{
  if (true == handle_ErrorMgr_ErrorCommPack_QNX_BSender_b())
  {
    // receive is done

  }
  // always respond
  return true;
}

bool_t SenErrorMgr_ErrorCommPack_QNX_B::handle_ErrorMgr_ErrorCommPack_QNX_BSender_b()
{
    bool_t v_RequestOk_b = false;
    ErrorMgr_ErrorCommPack_QNX_B v_NewMsgSend_t = dataProvider_po->getErrorMgr_ErrorCommPack_QNX_B ();
    msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<ErrorMgr_ErrorCommPack_QNX_B>();
    if(msgToRespond_s.msgSize_u32 > 0)
    {
        uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B);
        memcpy(&msgToRespond_s.data_t[v_Index_u32], &v_NewMsgSend_t, msgToRespond_s.msgSize_u32);
        logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B Signals sent \n");
        v_RequestOk_b = true;
    }
    return v_RequestOk_b;
}



} /* namespace sigm */
