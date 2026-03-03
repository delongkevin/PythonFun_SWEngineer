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
#include "SenTRSC_Inputs_from_TrailerDetection.h"

namespace sigm
{
TRSC_Inputs_from_TrailerDetection::TRSC_Inputs_from_TrailerDetection()
   : BaseSender(e_IpcMsgId_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t, 50)
{
}

TRSC_Inputs_from_TrailerDetection::~TRSC_Inputs_from_TrailerDetection()
{
}

bool_t TRSC_Inputs_from_TrailerDetection::handleSpecificSender_b()
{
    if (true == handle_TRSC_Inputs_from_TrailerDetection_b())
    {
    }
    return true;
}

bool_t TRSC_Inputs_from_TrailerDetection::handle_TRSC_Inputs_from_TrailerDetection_b()
{
    bool_t v_RequestOk_b = false;
    TRSC_Inputs_from_TrailerDetection_t v_NewMsgSend_t = dataProvider_po->getTRSC_Inputs_from_TrailerDetection_t ();
    msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<TRSC_Inputs_from_TrailerDetection_t>();
    if(msgToRespond_s.msgSize_u32 > 0)
    {
        uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t);
        memcpy(&msgToRespond_s.data_t[v_Index_u32], &v_NewMsgSend_t, msgToRespond_s.msgSize_u32);
        logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " TRSC_Inputs_from_TrailerDetection Signals sent \n");
        v_RequestOk_b = true;
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
