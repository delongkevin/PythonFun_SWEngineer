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
 *  @author (Author pavan.raut@magna.com)
 *  --------------------------------------------------------------------------*/
#include "SenRunTimeStats_MPU1_0.h"

namespace sigm
{
RunTimeStats_MPU1_0::RunTimeStats_MPU1_0()
   : BaseSender(e_IpcMsgId_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t, 50)
{
}

RunTimeStats_MPU1_0::~RunTimeStats_MPU1_0()
{
}

bool_t RunTimeStats_MPU1_0::handleSpecificSender_b()
{
    if (true == handle_RunTimeStats_MPU1_0_b())
    {
    }
    return true;
}

bool_t RunTimeStats_MPU1_0::handle_RunTimeStats_MPU1_0_b()
{
    bool_t v_RequestOk_b = false;
    RunTimeStats_MPU1_0_t v_NewMsgSend_t = dataProvider_po->getRunTimeStats_MPU1_0_t ();
    msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<RunTimeStats_MPU1_0_t>();
    if(msgToRespond_s.msgSize_u32 > 0)
    {
        uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t);
        memcpy(&msgToRespond_s.data_t[v_Index_u32], &v_NewMsgSend_t, msgToRespond_s.msgSize_u32);
        logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " RunTimeStats_MPU1_0 Signals sent \n");
        v_RequestOk_b = true;
    }
    return v_RequestOk_b;
}
} /* namespace sigm */