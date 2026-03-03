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
 *  @author (Author pavan.raut@magna.com)
 *  --------------------------------------------------------------------------*/

#include "RecTRSC_CalibrationClear.h"
namespace sigm
{

TRSC_CalibrationClear::TRSC_CalibrationClear()
   : BaseReceiver(e_IpcMsgId_Data_TRSC_CalibrationClear_t,50){}

TRSC_CalibrationClear::~TRSC_CalibrationClear(){}

bool_t TRSC_CalibrationClear::handleSpecificReceiver_b()
{
    if (true == handle_TRSC_CalibrationClearReceiver_b())
    {
    }
    return true;
}

bool_t TRSC_CalibrationClear::handle_TRSC_CalibrationClearReceiver_b()
{
    bool_t v_RequestOk_b = false;
    uint32_t size_u32 =0;

    size_u32 = BaseReceiver::getStructSize_u32<TRSC_CalibrationClear_t>();
    if(size_u32 != m_MsgReceived.msgSize_u32)
    {
    }
    else
    {
        TRSC_CalibrationClear_t v_NewRequest_t;
        if (m_MsgReceived.msgSize_u32 > 0)
        {
            v_RequestOk_b = true;
            memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
            dataProvider_po->setTRSC_CalibrationClear_v(v_NewRequest_t);
        }
    }
    return v_RequestOk_b;
}
} /* namespace sigm */