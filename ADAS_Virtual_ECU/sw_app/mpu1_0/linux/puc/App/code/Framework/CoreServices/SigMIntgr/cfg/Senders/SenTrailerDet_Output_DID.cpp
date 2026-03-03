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
 *  @author (Author sagar.saste@magna.com)
 *  --------------------------------------------------------------------------*/
#include "SenTrailerDet_Output_DID.h"

namespace sigm
{
TrailerDet_Output_DID::TrailerDet_Output_DID()
   : BaseSender(e_IpcMsgId_PpTrailerDetectOP_TrailerDetection_Output_DID_t, 50)
{
}

TrailerDet_Output_DID::~TrailerDet_Output_DID()
{
}

bool_t TrailerDet_Output_DID::handleSpecificSender_b()
{
    if (true == handle_TrailerDetection_Output_DID_b())
    {
    }
    return true;
}

bool_t TrailerDet_Output_DID::handle_TrailerDetection_Output_DID_b()
{
    bool_t v_RequestOk_b = false;
    TrailerDetection_Output_DID_t v_NewMsgSend_t = dataProvider_po->getTrailerDet_Output_DID ();
    msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<TrailerDetection_Output_DID_t>();
    if(msgToRespond_s.msgSize_u32 > 0)
    {
        uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_PpTrailerDetectOP_TrailerDetection_Output_DID_t);
        memcpy(&msgToRespond_s.data_t[v_Index_u32], &v_NewMsgSend_t, msgToRespond_s.msgSize_u32);
        logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " TrailerDet_Output_DID Signals sent \n");
        v_RequestOk_b = true;
    }
    return v_RequestOk_b;
}
} /* namespace sigm */