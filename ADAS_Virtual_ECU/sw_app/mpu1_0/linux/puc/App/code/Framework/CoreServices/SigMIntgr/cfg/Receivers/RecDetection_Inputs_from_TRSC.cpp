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
#include "RecDetection_Inputs_from_TRSC.h"
namespace sigm
{

Detection_Inputs_from_TRSC::Detection_Inputs_from_TRSC()
   : BaseReceiver(e_IpcMsgId_PpDetInpTrsc_Detection_Inputs_from_TRSC_t,50){}

Detection_Inputs_from_TRSC::~Detection_Inputs_from_TRSC(){}

bool_t Detection_Inputs_from_TRSC::handleSpecificReceiver_b()
{
    if (true == handle_Detection_Inputs_from_TRSCReceiver_b())
    {
    }
    return true;
}

bool_t Detection_Inputs_from_TRSC::handle_Detection_Inputs_from_TRSCReceiver_b()
{
    bool_t v_RequestOk_b = false;
    uint32_t size_u32 =0;

    size_u32 = BaseReceiver::getStructSize_u32<Detection_Inputs_from_TRSC_t>();
    if(size_u32 != m_MsgReceived.msgSize_u32)
    {
    	logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "Detection_Inputs_from_TRSC_t message  invalid  size actual %d and received %d \n",size_u32, m_MsgReceived.msgSize_u32);
    }
    else
    {
        Detection_Inputs_from_TRSC_t v_NewRequest_t;
        if (m_MsgReceived.msgSize_u32 > 0)
        {
            v_RequestOk_b = true;
            memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
            dataProvider_po->setDetection_Inputs_from_TRSC_v(v_NewRequest_t);
            logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf,"Received- %s\n", __PRETTY_FUNCTION__);
        }
    }
    return v_RequestOk_b;
}


} /* namespace sigm */
