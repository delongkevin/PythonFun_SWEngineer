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
#include "SenQNX_State_QNX.h"

namespace sigm
{
QNX_State_QNX::QNX_State_QNX()
   : BaseSender(e_IpcMsgId_PpSR_State_QNX_State_QNX, 50)
{
}

QNX_State_QNX::~QNX_State_QNX()
{
}

bool_t QNX_State_QNX::handleSpecificSender_b()
{
    if (true == handle_SSM_QNX_CoreStatub())
    {
    }
    return true;
}

bool_t QNX_State_QNX::handle_SSM_QNX_CoreStatub()
{
    bool_t v_RequestOk_b = false;
    SSM_QNX_CoreStatus v_NewMsgSend_t = dataProvider_po->getSSM_QNX_CoreStatus ();
    msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<SSM_QNX_CoreStatus>();
    if(msgToRespond_s.msgSize_u32 > 0)
    {
        uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_PpSR_State_QNX_State_QNX);
        memcpy(&msgToRespond_s.data_t[v_Index_u32], &v_NewMsgSend_t, msgToRespond_s.msgSize_u32);
        logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " QNX_State_QNX Signals sent \n");
        v_RequestOk_b = true;
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
