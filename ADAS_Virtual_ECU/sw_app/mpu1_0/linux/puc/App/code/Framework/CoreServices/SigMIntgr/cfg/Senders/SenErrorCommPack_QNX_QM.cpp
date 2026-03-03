/**
 * -------------------------------------------------------------------------
 *  @file ***.cpp/***.h
 *  @brief Contains
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 *
 *  @author sagar.saste@magna.com
 *  --------------------------------------------------------------------------*/
#include "SenErrorCommPack_QNX_QM.h"

namespace sigm
{
ErrorCommPack_QNX_QM::ErrorCommPack_QNX_QM()
   : BaseSender(e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM, 50)
{
}

ErrorCommPack_QNX_QM::~ErrorCommPack_QNX_QM()
{
}

bool_t ErrorCommPack_QNX_QM::handleSpecificSender_b()
{
    if (true == handle_ErrorMgr_ErrorCommPack_QNX_Qb())
    {
    }
    return true;
}

bool_t ErrorCommPack_QNX_QM::handle_ErrorMgr_ErrorCommPack_QNX_Qb()
{
    bool_t v_RequestOk_b = false;
    ErrorMgr_ErrorCommPack_QNX_QM v_NewMsgSend_t = dataProvider_po->getErrorMgr_ErrorCommPack_QNX_QM ();
    msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<ErrorMgr_ErrorCommPack_QNX_QM>();
    if(msgToRespond_s.msgSize_u32 > 0)
    {
        uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM);
        memcpy(&msgToRespond_s.data_t[v_Index_u32], &v_NewMsgSend_t, msgToRespond_s.msgSize_u32);
        logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " ErrorCommPack_QNX_QM Signals sent \n");
        v_RequestOk_b = true;
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
