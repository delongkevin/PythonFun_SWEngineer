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
#include "RecUS_S_USSErrorDiagData.h"
namespace sigm
{

US_S_USSErrorDiagData::US_S_USSErrorDiagData()
   : BaseReceiver(e_IpcMsgId_PpUSSErrorDiagData_US_S_USSErrorDiagData_t,50){}

US_S_USSErrorDiagData::~US_S_USSErrorDiagData(){}

bool_t US_S_USSErrorDiagData::handleSpecificReceiver_b()
{
    if (true == handle_US_S_USSErrorDiagDataReceiver_b())
    {
    }
    return true;
}

bool_t US_S_USSErrorDiagData::handle_US_S_USSErrorDiagDataReceiver_b()
{
    bool_t v_RequestOk_b = false;
    uint32_t size_u32 =0;

    size_u32 = BaseReceiver::getStructSize_u32<US_S_USSErrorDiagData_t>();
    if(size_u32 != m_MsgReceived.msgSize_u32)
    {
    	logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, " US_S_USSErrorDiagData_t message  invalid  size actual %d and received %d \n",size_u32, m_MsgReceived.msgSize_u32);
    }
    else
    {
        US_S_USSErrorDiagData_t v_NewRequest_t;
        if (m_MsgReceived.msgSize_u32 > 0)
        {
            v_RequestOk_b = true;
            memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
            dataProvider_po->setUS_S_USSErrorDiagData_v(v_NewRequest_t);
            logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf,"Received- %s\n", __PRETTY_FUNCTION__);
        }
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
