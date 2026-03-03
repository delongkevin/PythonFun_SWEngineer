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
#include "SenCVPAMFDData2_LMD_Outputs_CVPAMFDData.h"

namespace sigm
{
CVPAMFDData2_LMD_Outputs_CVPAMFDData::CVPAMFDData2_LMD_Outputs_CVPAMFDData()
   : BaseSender(e_IpcMsgId_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t, 50)
{
}

CVPAMFDData2_LMD_Outputs_CVPAMFDData::~CVPAMFDData2_LMD_Outputs_CVPAMFDData()
{
}

bool_t CVPAMFDData2_LMD_Outputs_CVPAMFDData::handleSpecificSender_b()
{
    if (true == handle_LMD_Outputs_CVPAMFDData2_b())
    {
    }
    return true;
}

bool_t CVPAMFDData2_LMD_Outputs_CVPAMFDData::handle_LMD_Outputs_CVPAMFDData2_b()
{
    bool_t v_RequestOk_b = false;
    LMD_Outputs_CVPAMFDData2_t v_NewMsgSend_t = dataProvider_po->getCVPAMFDData2_LMD_Outputs_CVPAMFDData ();
    msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<LMD_Outputs_CVPAMFDData2_t>();
    if(msgToRespond_s.msgSize_u32 > 0)
    {
        uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t);
        memcpy(&msgToRespond_s.data_t[v_Index_u32], &v_NewMsgSend_t, msgToRespond_s.msgSize_u32);
        logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " CVPAMFDData2_LMD_Outputs_CVPAMFDData Signals sent \n");
        v_RequestOk_b = true;
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
