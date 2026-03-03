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
#include "Recfid_struct.h"
namespace sigm
{

fid_struct::fid_struct()
   : BaseReceiver(e_IpcMsgId_Data_FID_STRUCT_B,50){}

fid_struct::~fid_struct(){}

bool_t fid_struct::handleSpecificReceiver_b()
{
    if (true == handle_fid_structReceiver_b())
    {
    }
    return true;
}

bool_t fid_struct::handle_fid_structReceiver_b()
{
    bool_t v_RequestOk_b = false;
    uint32_t size_u32 =0;

    size_u32 = BaseReceiver::getStructSize_u32<FID_STRUCT_B>();
    if(size_u32 != m_MsgReceived.msgSize_u32)
    {
    }
    else
    {
        FID_STRUCT_B v_NewRequest_t;
        if (m_MsgReceived.msgSize_u32 > 0)
        {
            v_RequestOk_b = true;
            memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
            dataProvider_po->setfid_struct_v(v_NewRequest_t);
        }
    }
    return v_RequestOk_b;
}
} /* namespace sigm */