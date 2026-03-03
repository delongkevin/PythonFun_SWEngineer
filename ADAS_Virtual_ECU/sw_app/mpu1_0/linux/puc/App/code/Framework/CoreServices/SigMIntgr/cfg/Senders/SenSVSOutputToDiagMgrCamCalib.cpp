//--------------------------------------------------------------------------
/// @file SenSVSOutputToDiagMgrCamCalib.cpp
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
/// @author Ananda Kavrady (Ananda.kavrady@magna.com)
///
//  --------------------------------------------------------------------------

#include "SenSVSOutputToDiagMgrCamCalib.h"

namespace sigm
{

SenSVSOutputToDiagMgrCamCalib::SenSVSOutputToDiagMgrCamCalib()
 : BaseSender(e_IpcMsgId_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t, 50)
{
}

SenSVSOutputToDiagMgrCamCalib::~SenSVSOutputToDiagMgrCamCalib()
{
}

bool_t SenSVSOutputToDiagMgrCamCalib::handleSpecificSender_b()
{
	  if (true == handle_TbADAS_SVSOutputToDiagMgrCamCalibSender_b())
	  {
	    // receive is done

	  }
  // always respond
  return true;
}

bool_t SenSVSOutputToDiagMgrCamCalib::handle_TbADAS_SVSOutputToDiagMgrCamCalibSender_b()
{

  TbSVS_e_SVSOutputToDiagMgrCamCalib_t v_NewMsgSend_t = dataProvider_po->getTbSVS_e_SVSOutputToDiagMgrCamCalib_t();

  msgToRespond_s.msgSize_u32 = BaseSender::getMessageSize_u32<TbSVS_e_SVSOutputToDiagMgrCamCalib_t>();
  uint32_t v_Index_u32 = addHeaderToMessage_u32(&msgToRespond_s.data_t[0], e_IpcMsgId_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t);
  bool_t v_RequestOk_b = writeTbSVS_e_SVSOutputToDiagMgrCamCalib_b(&msgToRespond_s.data_t[v_Index_u32], msgToRespond_s.msgSize_u32, &v_NewMsgSend_t);

  logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, "SVSOutputToDiagMgrCamCalib Signals sent size: %d\n",msgToRespond_s.msgSize_u32);

  return v_RequestOk_b;

}




} /* namespace sigm */
