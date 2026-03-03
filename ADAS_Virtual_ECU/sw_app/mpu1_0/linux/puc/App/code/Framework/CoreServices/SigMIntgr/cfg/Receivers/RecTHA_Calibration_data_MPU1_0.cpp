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
#include "RecTHA_Calibration_data_MPU1_0.h"
namespace sigm
{

THA_Calibration_data_MPU1_0::THA_Calibration_data_MPU1_0()
   : BaseReceiver(e_IpcMsgId_Data_THA_Calibration_data_MPU1_0_t,50){}

THA_Calibration_data_MPU1_0::~THA_Calibration_data_MPU1_0(){}

bool_t THA_Calibration_data_MPU1_0::handleSpecificReceiver_b()
{
    if (true == handle_THA_Calibration_data_MPU1_0Receiver_b())
    {
    }
    return true;
}

bool_t THA_Calibration_data_MPU1_0::handle_THA_Calibration_data_MPU1_0Receiver_b()
{
    bool_t v_RequestOk_b = false;
    uint32_t size_u32 =0;

    size_u32 = BaseReceiver::getStructSize_u32<THA_Calibration_data_MPU1_0_t>();
    if(size_u32 != m_MsgReceived.msgSize_u32)
    {
    }
    else
    {
        THA_Calibration_data_MPU1_0_t v_NewRequest_t;
        if (m_MsgReceived.msgSize_u32 > 0)
        {
            v_RequestOk_b = true;
            memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
            dataProvider_po->setTHA_Calibration_data_MPU1_0_v(v_NewRequest_t);
        }
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
