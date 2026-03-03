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
/// @author sagar.saste@magna.com

 *  --------------------------------------------------------------------------*/
#include "RecMCU2_State_2_0.h"
namespace sigm
{

MCU2_State_2_0::MCU2_State_2_0()
   : BaseReceiver(e_IpcMsgId_PpSR_State_MCU2_State_2_0,50){}

MCU2_State_2_0::~MCU2_State_2_0(){}

bool_t MCU2_State_2_0::handleSpecificReceiver_b()
{
    if (true == handle_MCU2_State_2_0Receiver_b())
    {
    }
    return true;
}

bool_t MCU2_State_2_0::handle_MCU2_State_2_0Receiver_b()
{
    bool_t v_RequestOk_b = false;
    uint32_t size_u32 =0;

    size_u32 = BaseReceiver::getStructSize_u32<SSM_2_0_CoreStatus>();
    if(size_u32 != m_MsgReceived.msgSize_u32)
    {
        logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "SSM_2_0_CoreStatus message  invalid  size actual %d and received %d \n",size_u32, m_MsgReceived.msgSize_u32);
    }
    else
    {
        SSM_2_0_CoreStatus v_NewRequest_t;
        if (m_MsgReceived.msgSize_u32 > 0)
        {
            v_RequestOk_b = true;
            memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
            dataProvider_po->setSSM_2_0_CoreStatus_v(v_NewRequest_t);
            logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf,"Received- %s\n", __PRETTY_FUNCTION__);
        }
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
