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
#include "RecTHARelated_ScreenReq.h"
namespace sigm
{

THARelated_ScreenReq::THARelated_ScreenReq()
   : BaseReceiver(e_IpcMsgId_Data_THARelated_ScreenReq_t,50){}

THARelated_ScreenReq::~THARelated_ScreenReq(){}

bool_t THARelated_ScreenReq::handleSpecificReceiver_b()
{
    if (true == handle_THARelated_ScreenReqReceiver_b())
    {
    }
    return true;
}

bool_t THARelated_ScreenReq::handle_THARelated_ScreenReqReceiver_b()
{
    bool_t v_RequestOk_b = false;
    uint32_t size_u32 =0;

    size_u32 = BaseReceiver::getStructSize_u32<THARelated_ScreenReq_t>();
    if(size_u32 != m_MsgReceived.msgSize_u32)
    {
    	logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, " THARelated_ScreenReq_t message  invalid  size actual %d and received %d \n",size_u32, m_MsgReceived.msgSize_u32);
    }
    else
    {
        THARelated_ScreenReq_t v_NewRequest_t;
        if (m_MsgReceived.msgSize_u32 > 0)
        {
            v_RequestOk_b = true;
            memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
            dataProvider_po->setTHARelated_ScreenReq_v(v_NewRequest_t);
            logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf,"Received- %s\n", __PRETTY_FUNCTION__);
        }
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
