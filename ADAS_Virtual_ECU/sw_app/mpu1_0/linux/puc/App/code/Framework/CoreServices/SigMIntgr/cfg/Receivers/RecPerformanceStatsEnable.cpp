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
#include "RecPerformanceStatsEnable.h"
namespace sigm
{

PerformanceStatsEnable::PerformanceStatsEnable()
   : BaseReceiver(e_IpcMsgId_Data_PerformanceStatsEnable_t,50){}

PerformanceStatsEnable::~PerformanceStatsEnable(){}

bool_t PerformanceStatsEnable::handleSpecificReceiver_b()
{
    if (true == handle_PerformanceStatsEnableReceiver_b())
    {
    }
    return true;
}

bool_t PerformanceStatsEnable::handle_PerformanceStatsEnableReceiver_b()
{
    bool_t v_RequestOk_b = false;
    uint32_t size_u32 =0;

    size_u32 = BaseReceiver::getStructSize_u32<PerformanceStatsEnable_t>();
    if(size_u32 != m_MsgReceived.msgSize_u32)
    {
    }
    else
    {
        PerformanceStatsEnable_t v_NewRequest_t;
        if (m_MsgReceived.msgSize_u32 > 0)
        {
            v_RequestOk_b = true;
            memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
            dataProvider_po->setPerformanceStatsEnable_v(v_NewRequest_t);
        }
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
