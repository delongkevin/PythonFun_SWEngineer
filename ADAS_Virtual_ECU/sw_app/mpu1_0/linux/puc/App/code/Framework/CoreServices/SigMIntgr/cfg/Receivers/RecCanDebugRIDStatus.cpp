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
#include "RecCanDebugRIDStatus.h"
namespace sigm
{

CanDebugRIDStatus::CanDebugRIDStatus()
   : BaseReceiver(e_IpcMsgId_Data_ME_CanDebugRIDStatus_t,50){}

CanDebugRIDStatus::~CanDebugRIDStatus(){}

bool_t CanDebugRIDStatus::handleSpecificReceiver_b()
{
    if (true == handle_CanDebugRIDStatusReceiver_b())
    {
    }
    return true;
}

bool_t CanDebugRIDStatus::handle_CanDebugRIDStatusReceiver_b()
{
    bool_t v_RequestOk_b = false;
    uint32_t size_u32 =0;

    size_u32 = BaseReceiver::getStructSize_u32<ME_CanDebugRIDStatus_t>();
    if(size_u32 != m_MsgReceived.msgSize_u32)
    {
    }
    else
    {
        ME_CanDebugRIDStatus_t v_NewRequest_t;
        if (m_MsgReceived.msgSize_u32 > 0)
        {
            v_RequestOk_b = true;
            memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
            dataProvider_po->setCanDebugRIDStatus_v(v_NewRequest_t);
        }
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
