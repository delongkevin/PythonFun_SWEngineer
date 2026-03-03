//--------------------------------------------------------------------------
/// @file RecDiagMgrOutputToSVSCamCalibSM.cpp
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
///
//  --------------------------------------------------------------------------

#include "RecDiagMgrOutputToSVSCamCalibSM.h"

namespace sigm
{

RecDiagMgrOutputToSVSCamCalibSM::RecDiagMgrOutputToSVSCamCalibSM()
 : BaseReceiver(e_IpcMsgId_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t, 50)
{
}

RecDiagMgrOutputToSVSCamCalibSM::~RecDiagMgrOutputToSVSCamCalibSM()
{
}

bool_t RecDiagMgrOutputToSVSCamCalibSM::handleSpecificReceiver_b()
{
  if (true == handle_DiagMgrOutputToSVSCamCalibSMReceiver_b())
  {
    // receive is done

  }
  // always respond
  return true;
}

bool_t RecDiagMgrOutputToSVSCamCalibSM::handle_DiagMgrOutputToSVSCamCalibSMReceiver_b()
{
  bool_t v_RequestOk_b = true;
  uint32_t size_u32 =0;

  size_u32 = BaseReceiver::getStructSize_u32<TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t>();
  if(size_u32 != m_MsgReceived.msgSize_u32)
  {
  	logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t message  invalid  size actual %d and received %d \n",size_u32, m_MsgReceived.msgSize_u32);
  	v_RequestOk_b = false;
  }
  else
  {
    TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t v_NewRequest_t;

    bool_t v_RequestOk_b = readTbSVS_e_DiagMgrOutputToSVSCamCalibSM_b(&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32, &v_NewRequest_t);
    if (true == v_RequestOk_b)
    {
      logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " TbSVS_e_DiagMgrOutputToSVSCamCalibSM Signals received \n");

      dataProvider_po->setTbSVS_e_DiagMgrOutputToSVSCamCalibSM_v(v_NewRequest_t);
    }
  }

  return v_RequestOk_b;
}


} /* namespace sigm */
