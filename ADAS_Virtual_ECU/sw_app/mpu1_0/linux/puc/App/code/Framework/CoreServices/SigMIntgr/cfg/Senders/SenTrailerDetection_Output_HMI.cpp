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
#include "SenTrailerDetection_Output_HMI.h"

namespace sigm
{
TrailerDetection_Output_HMI::TrailerDetection_Output_HMI()
   : BaseSender(e_IpcMsgId_Data_TrailerDetection_Output_HMI_t, 50)
{
}

TrailerDetection_Output_HMI::~TrailerDetection_Output_HMI()
{
}

bool_t TrailerDetection_Output_HMI::handleSpecificSender_b()
{
    if (true == handle_TrailerDetection_Output_HMI_b())
    {
    }
    return true;
}

bool_t TrailerDetection_Output_HMI::handle_TrailerDetection_Output_HMI_b()
{
    bool_t v_RequestOk_b = false;
    TrailerDetection_Output_HMI_t v_NewMsgSend_t = dataProvider_po->getTrailerDetection_Output_HMI ();
    msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<TrailerDetection_Output_HMI_t>();
    if(msgToRespond_s.msgSize_u32 > 0)
    {
        uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_Data_TrailerDetection_Output_HMI_t);
        memcpy(&msgToRespond_s.data_t[v_Index_u32], &v_NewMsgSend_t, msgToRespond_s.msgSize_u32);
        logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " TrailerDetection_Output_HMI Signals sent \n");
        v_RequestOk_b = true;
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
