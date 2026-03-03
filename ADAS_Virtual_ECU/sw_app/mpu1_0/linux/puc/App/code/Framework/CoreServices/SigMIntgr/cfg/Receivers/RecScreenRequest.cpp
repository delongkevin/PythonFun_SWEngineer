//--------------------------------------------------------------------------
/// @file RecScreenRequest.cpp
/// @brief Contains
///
///
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author sagar.saste@magna.com

//  --------------------------------------------------------------------------

#include "RecScreenRequest.h"

namespace sigm
{

RecScreenRequest::RecScreenRequest()
 : BaseReceiver(e_IpcMsgId_PpScreenRequest_ScreenRequest_t, 50)
{
}

RecScreenRequest::~RecScreenRequest()
{
}

bool_t RecScreenRequest::handleSpecificReceiver_b()
{
  if (true == handle_ScreenRequestReceiver_b())
  {
    // receive is done

  }
  // always respond
  return true;
}

bool_t RecScreenRequest::handle_ScreenRequestReceiver_b()
{
  bool_t v_RequestOk_b = false;
  uint32_t ScreenRequest_size_u32 =0;

  ScreenRequest_size_u32 = BaseReceiver::getStructSize_u32<ScreenRequest_t>();
  if(ScreenRequest_size_u32 != m_MsgReceived.msgSize_u32)
  {
    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, " ScreenRequest message  invalid  size actual %d and received %d \n",ScreenRequest_size_u32, m_MsgReceived.msgSize_u32);
  }
  else
  {
    ScreenRequest_t v_NewRequest_t;

    bool_t v_RequestOk_b = readScreenRequest_b(&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32, &v_NewRequest_t);
    if (true == v_RequestOk_b)
    {
        logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "PuC: ViewEngReqCode: %d, ZoomPressed: %d, ZoomFactor: %d, x: %d, Y: %d",\
      		  v_NewRequest_t.MeSVS_e_ViewEngReqCode,v_NewRequest_t.MeSVS_b_ZoomPressedReq, v_NewRequest_t.ZoomFactor_u8,v_NewRequest_t.MeSVS_px_CplrPosX,v_NewRequest_t.MeSVS_px_CplrPosY);
      dataProvider_po->setScreenRequest_v(v_NewRequest_t);
//      ScreenResponse_t scr;
//      dataProvider_po->setScreenResponse_v(scr);
    }
  }

  return v_RequestOk_b;
}


} /* namespace sigm */
