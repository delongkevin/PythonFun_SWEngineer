//--------------------------------------------------------------------------
/// @file RecSSM_SystemState.cpp
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

#include "RecSSM_SystemState.h"

namespace sigm
{

RecSSM_SystemState::RecSSM_SystemState()
 : BaseReceiver(e_IpcMsgId_Data_SSM_SystemState, 50)
{
}

RecSSM_SystemState::~RecSSM_SystemState()
{
}

bool_t RecSSM_SystemState::handleSpecificReceiver_b()
{
  if (true == handle_RecSSM_SystemStateReceiver_b())
  {
    // receive is done

  }
  // always respond
  return true;
}

bool_t RecSSM_SystemState::handle_RecSSM_SystemStateReceiver_b()
{
    bool_t v_RequestOk_b = false;
    uint32_t size_u32 =0;
    uint32_t rc;

    size_u32 = BaseReceiver::getStructSize_u32<SSM_SystemState>();
    if(size_u32 != m_MsgReceived.msgSize_u32)
    {
    	logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, " SSM_SystemState message  invalid  size actual %d and received %d \n",size_u32, m_MsgReceived.msgSize_u32);
    }
    else
    {
    	SSM_SystemState v_NewRequest_t;
        if (m_MsgReceived.msgSize_u32 > 0)
        {
            v_RequestOk_b = true;
            memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
            dataProvider_po->setSSM_SystemState_v(v_NewRequest_t);
//            logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf,"Received- %s\n", __PRETTY_FUNCTION__);
            printf("Received- %s\tSState: %d\tDState: %d\n", __PRETTY_FUNCTION__,v_NewRequest_t.SystemState,v_NewRequest_t.DegradedState);
#if 0
            if ((SSM_STATE_SHUTTINGDOWN_REMOTECORES_i == v_NewRequest_t.SystemState) ||
          	  (SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE_i == v_NewRequest_t.SystemState))
            {
            	rc = system( "shutdown -b -f -v" );
            	if( rc == -1 ) {
            		ME_Debugger_F_Printf_v("App_IPCM :: Shutdown could not be run\n");
            	} else {
            		ME_Debugger_F_Printf_v("App_IPCM :: Shutdown is %d\n",
            				WEXITSTATUS( rc ));
            	}
            }
#endif
        }
    }
  return v_RequestOk_b;
}


} /* namespace sigm */
