//--------------------------------------------------------------------------
/// @file RecIKinematicData.cpp
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

#include "RecIKinematicData.h"

namespace sigm
{

RecIKinematicData::RecIKinematicData()
 : BaseReceiver(e_IpcMsgId_Data_IKinematicData_t, 50)
{
}

RecIKinematicData::~RecIKinematicData()
{
}

bool_t RecIKinematicData::handleSpecificReceiver_b()
{
  if (true == handleIKinematicDataReceiver_b())
  {
    // receive is done
  }
  // always respond
  return true;
}

bool_t RecIKinematicData::handleIKinematicDataReceiver_b()
{
	bool_t v_RequestOk_b = false;
	IKinematicData_t  v_NewRequest_t;
	uint32_t IKinematicData_size_u32 =0;

	IKinematicData_size_u32 = BaseReceiver::getStructSize_u32<IKinematicData_t>();

	if(IKinematicData_size_u32 != m_MsgReceived.msgSize_u32)
	{
		logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "IKinematicData_t message  invalid  size actual %d and received %d \n",IKinematicData_size_u32, m_MsgReceived.msgSize_u32);
	}
	else
	{
		IKinematicData_t v_NewRequest_t;
		if (m_MsgReceived.msgSize_u32 > 0)
		{
			v_RequestOk_b = true;
	          memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
			logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf, " IKinematicData signal received \n");

			dataProvider_po->setIKinematicData_v(v_NewRequest_t);
		}
	}
	return v_RequestOk_b;
}




} /* namespace sigm */
