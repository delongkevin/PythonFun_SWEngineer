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
#include "RecFeatureOutputsTHA_TbTHASmVc_FeatureOutputs.h"
namespace sigm
{

FeatureOutputsTHA_TbTHASmVc_FeatureOutputs::FeatureOutputsTHA_TbTHASmVc_FeatureOutputs()
   : BaseReceiver(e_IpcMsgId_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t,50){}

FeatureOutputsTHA_TbTHASmVc_FeatureOutputs::~FeatureOutputsTHA_TbTHASmVc_FeatureOutputs(){}

bool_t FeatureOutputsTHA_TbTHASmVc_FeatureOutputs::handleSpecificReceiver_b()
{
    if (true == handle_FeatureOutputsTHA_TbTHASmVc_FeatureOutputsReceiver_b())
    {
    }
    return true;
}

bool_t FeatureOutputsTHA_TbTHASmVc_FeatureOutputs::handle_FeatureOutputsTHA_TbTHASmVc_FeatureOutputsReceiver_b()
{
    bool_t v_RequestOk_b = false;
    uint32_t size_u32 =0;

    size_u32 = BaseReceiver::getStructSize_u32<TbTHASmVc_FeatureOutputs_t>();
    if(size_u32 != m_MsgReceived.msgSize_u32)
    {
    	logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "TbTHASmVc_FeatureOutputs_t message  invalid  size actual %d and received %d \n",size_u32, m_MsgReceived.msgSize_u32);
    }
    else
    {
        TbTHASmVc_FeatureOutputs_t v_NewRequest_t;
        if (m_MsgReceived.msgSize_u32 > 0)
        {
            v_RequestOk_b = true;
            memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
            dataProvider_po->setTbTHASmVc_FeatureOutputs_v(v_NewRequest_t);
            logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf,"Received- %s\n", __PRETTY_FUNCTION__);
        }
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
