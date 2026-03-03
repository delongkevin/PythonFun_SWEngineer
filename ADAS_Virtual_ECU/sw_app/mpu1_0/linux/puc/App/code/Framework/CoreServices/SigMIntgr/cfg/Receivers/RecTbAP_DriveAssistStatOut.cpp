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
#include "RecTbAP_DriveAssistStatOut.h"
namespace sigm
{

TbAP_DriveAssistStatOut::TbAP_DriveAssistStatOut()
   : BaseReceiver(e_IpcMsgId_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t,50){}

TbAP_DriveAssistStatOut::~TbAP_DriveAssistStatOut(){}

bool_t TbAP_DriveAssistStatOut::handleSpecificReceiver_b()
{
    if (true == handle_TbAP_DriveAssistStatOutReceiver_b())
    {
    }
    return true;
}

bool_t TbAP_DriveAssistStatOut::handle_TbAP_DriveAssistStatOutReceiver_b()
{
    bool_t v_RequestOk_b = false;
    uint32_t size_u32 =0;

    size_u32 = BaseReceiver::getStructSize_u32<TbAP_DriveAssistStatOut_t>();
    if(size_u32 != m_MsgReceived.msgSize_u32)
    {
    }
    else
    {
        TbAP_DriveAssistStatOut_t v_NewRequest_t;
        if (m_MsgReceived.msgSize_u32 > 0)
        {
            v_RequestOk_b = true;
            memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
            dataProvider_po->setTbAP_DriveAssistStatOut_v(v_NewRequest_t);
        }
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
