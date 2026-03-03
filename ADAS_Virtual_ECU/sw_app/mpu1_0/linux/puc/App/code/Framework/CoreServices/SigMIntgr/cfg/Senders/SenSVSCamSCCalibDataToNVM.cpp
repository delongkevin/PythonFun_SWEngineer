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
#include "SenSVSCamSCCalibDataToNVM.h"

namespace sigm
{
SVSCamSCCalibDataToNVM::SVSCamSCCalibDataToNVM()
   : BaseSender(e_IpcMsgId_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t, 50)
{
}

SVSCamSCCalibDataToNVM::~SVSCamSCCalibDataToNVM()
{
}

bool_t SVSCamSCCalibDataToNVM::handleSpecificSender_b()
{
    if (true == handle_TbSVS_S_SVSCamSCCalibDataToNVM_b())
    {
    }
    return true;
}

bool_t SVSCamSCCalibDataToNVM::handle_TbSVS_S_SVSCamSCCalibDataToNVM_b()
{
    bool_t v_RequestOk_b = false;
    TbSVS_S_SVSCamSCCalibDataToNVM_t v_NewMsgSend_t = dataProvider_po->getTbSVS_S_SVSCamSCCalibDataToNVM_t ();
    msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<TbSVS_S_SVSCamSCCalibDataToNVM_t>();
    if(msgToRespond_s.msgSize_u32 > 0)
    {
        uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t);
        memcpy(&msgToRespond_s.data_t[v_Index_u32], &v_NewMsgSend_t, msgToRespond_s.msgSize_u32);
        logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " SVSCamSCCalibDataToNVM Signals sent \n");
        v_RequestOk_b = true;
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
