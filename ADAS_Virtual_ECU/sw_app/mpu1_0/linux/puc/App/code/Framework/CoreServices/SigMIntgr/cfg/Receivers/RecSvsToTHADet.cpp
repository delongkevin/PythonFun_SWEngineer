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
#include "RecSvsToTHADet.h"
namespace sigm
{

SvsToTHADet::SvsToTHADet()
   : BaseReceiver(e_IpcMsgId_data_SvsToTHADet_t,50){}

SvsToTHADet::~SvsToTHADet(){}

bool_t SvsToTHADet::handleSpecificReceiver_b()
{
    if (true == handle_SvsToTHADetReceiver_b())
    {
    }
    return true;
}

bool_t SvsToTHADet::handle_SvsToTHADetReceiver_b()
{
    bool_t v_RequestOk_b = false;
    uint32_t size_u32 =0;

    size_u32 = BaseReceiver::getStructSize_u32<SvsToTHADet_t>();
    if(size_u32 != m_MsgReceived.msgSize_u32)
    {
    	logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, " SvsToTHADet_t message  invalid  size actual %d and received %d \n",size_u32, m_MsgReceived.msgSize_u32);
    }
    else
    {
        SvsToTHADet_t v_NewRequest_t;
        if (m_MsgReceived.msgSize_u32 > 0)
        {
            v_RequestOk_b = true;
            memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
            dataProvider_po->setSvsToTHADet_v(v_NewRequest_t);
            logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf,"Received- %s\n", __PRETTY_FUNCTION__);
        }
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
