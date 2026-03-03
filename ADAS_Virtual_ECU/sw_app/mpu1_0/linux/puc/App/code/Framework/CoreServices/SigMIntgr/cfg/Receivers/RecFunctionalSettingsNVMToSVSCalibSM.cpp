//--------------------------------------------------------------------------
/// @file RecFunctionalSettingsNVMToSVSCalibSM.cpp
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

#include "RecFunctionalSettingsNVMToSVSCalibSM.h"

namespace sigm
{

RecFunctionalSettingsNVMToSVSCalibSM::RecFunctionalSettingsNVMToSVSCalibSM()
 : BaseReceiver(e_IpcMsgId_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t, 50)
{
}

RecFunctionalSettingsNVMToSVSCalibSM::~RecFunctionalSettingsNVMToSVSCalibSM()
{
}

bool_t RecFunctionalSettingsNVMToSVSCalibSM::handleSpecificReceiver_b()
{
  if (true == handleFunctionalSettingsNVMToSVSCalibSMReceiver_b())
  {
    // receive is done
  }
  // always respond
  return true;
}

bool_t RecFunctionalSettingsNVMToSVSCalibSM::handleFunctionalSettingsNVMToSVSCalibSMReceiver_b()
{
	bool_t v_RequestOk_b = false;
	TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t  v_NewRequest_t;
	uint32_t size_u32 =0;

	size_u32 = BaseReceiver::getStructSize_u32<TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t>();

	if(size_u32 != m_MsgReceived.msgSize_u32)
	{
		logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "FunctionalSettingsNVMToSVSCalibSM_t message  invalid  size actual %d and received %d \n",size_u32, m_MsgReceived.msgSize_u32);
	}
	else
	{
		TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t v_NewRequest_t;
		if (m_MsgReceived.msgSize_u32 > 0)
		{
			v_RequestOk_b = true;
			memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
			printf("Received- %s\n", __PRETTY_FUNCTION__);

			dataProvider_po->setTbSVS_e_FunctionalSettingsNVMToSVSCalibSM_v(v_NewRequest_t);
		}
	}
	return v_RequestOk_b;
}




} /* namespace sigm */
