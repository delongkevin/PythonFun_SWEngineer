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
#include "SenLMD_Lane_Outputs.h"

namespace sigm
{
LMD_Lane_Outputs::LMD_Lane_Outputs()
   : BaseSender(e_IpcMsgId_PpLMDLaneOp_LMD_Lane_Outputs_s, 50)
{
}

LMD_Lane_Outputs::~LMD_Lane_Outputs()
{
}

bool_t LMD_Lane_Outputs::handleSpecificSender_b()
{
    if (true == handle_LMD_Lane_Outputs_s_b())
    {
    }
    return true;
}

bool_t LMD_Lane_Outputs::handle_LMD_Lane_Outputs_s_b()
{
    bool_t v_RequestOk_b = false;
    LMD_Lane_Outputs_s v_NewMsgSend_t = dataProvider_po->getLMD_Lane_Outputs();
    msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<LMD_Lane_Outputs_s>();
    if(msgToRespond_s.msgSize_u32 > 0)
    {
        uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_PpLMDLaneOp_LMD_Lane_Outputs_s);
        memcpy(&msgToRespond_s.data_t[v_Index_u32], &v_NewMsgSend_t, msgToRespond_s.msgSize_u32);
        logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " LMD_Lane_Outputs_s Signals sent \n");
        v_RequestOk_b = true;
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
