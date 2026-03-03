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
#include "SenMeDLD_e_RrCamSts.h"

namespace sigm
{
MeDLD_e_RrCamSts::MeDLD_e_RrCamSts()
   : BaseSender(e_IpcMsgId_data_MeDLD_e_RrCamSts_t, 50)
{
}

MeDLD_e_RrCamSts::~MeDLD_e_RrCamSts()
{
}

bool_t MeDLD_e_RrCamSts::handleSpecificSender_b()
{
    if (true == handle_MeDLD_e_RrCamSts_b())
    {
    }
    return true;
}

bool_t MeDLD_e_RrCamSts::handle_MeDLD_e_RrCamSts_b()
{
    bool_t v_RequestOk_b = false;
    MeDLD_e_RrCamSts_t v_NewMsgSend_t = dataProvider_po->getMeDLD_e_RrCamSts_t ();
    msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<MeDLD_e_RrCamSts_t>();
    if(msgToRespond_s.msgSize_u32 > 0)
    {
        uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_data_MeDLD_e_RrCamSts_t);
        memcpy(&msgToRespond_s.data_t[v_Index_u32], &v_NewMsgSend_t, msgToRespond_s.msgSize_u32);
        logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " MeDLD_e_RrCamSts Signals sent \n");
        v_RequestOk_b = true;
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
