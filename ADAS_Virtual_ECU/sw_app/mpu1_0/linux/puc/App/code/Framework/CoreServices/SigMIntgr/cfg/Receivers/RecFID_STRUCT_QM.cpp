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
#include "RecFID_STRUCT_QM.h"
namespace sigm
{

FID_STRUCT_QM_C::FID_STRUCT_QM_C()
   : BaseReceiver(e_IpcMsgId_Data_FID_STRUCT_QM,50){}

FID_STRUCT_QM_C::~FID_STRUCT_QM_C(){}

bool_t FID_STRUCT_QM_C::handleSpecificReceiver_b()
{
    if (true == handle_FID_STRUCT_QM_Receiver_b())
    {
    }
    return true;
}

bool_t FID_STRUCT_QM_C::handle_FID_STRUCT_QM_Receiver_b()
{
    bool_t v_RequestOk_b = false;
    uint32_t size_u32 =0;

    size_u32 = BaseReceiver::getStructSize_u32<FID_STRUCT_QM>();
    if(size_u32 != m_MsgReceived.msgSize_u32)
    {
    }
    else
    {
        FID_STRUCT_QM v_NewRequest_t;
        if (m_MsgReceived.msgSize_u32 > 0)
        {
            v_RequestOk_b = true;
            memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
            dataProvider_po->setFID_STRUCT_QM_v(v_NewRequest_t);
			//printf("Received- %s\n", __PRETTY_FUNCTION__);
        }
    }
    return v_RequestOk_b;
}
} /* namespace sigm */
