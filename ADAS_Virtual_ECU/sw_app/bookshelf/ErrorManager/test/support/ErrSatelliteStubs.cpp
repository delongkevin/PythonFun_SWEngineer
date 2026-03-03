#if defined(BUILD_MCU2_0)|| defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0) || defined (BUILD_MPU1_0)
#include "PlatformDataTypes.h"
#include "ipc_manager.h"
// Need to mock the IPC calls out of SignalMgr
uint32_t IPC_F_WrapperSend_e(IPCMessage_Params_t* i_IPCMsg_ps)
{

	return (uint32_t)0;
}

#else
#endif