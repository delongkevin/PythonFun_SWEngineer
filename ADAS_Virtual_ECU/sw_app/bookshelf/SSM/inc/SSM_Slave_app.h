#ifndef SSM_SLAVE_APP_H_INCGUARD
#define SSM_SLAVE_APP_H_INCGUARD

#include "SSM_Cfg.h"
#include "SSM_Defs.h"

#ifdef  SSM_APPLICATION_SLAVE

uint32_t SSM_Slave_App_getLocalTime(void);
void SSM_Slave_App_SendCoreStatus(const SSM_LocalCoreStatus *CoreStatus);
bool_t SSM_Slave_App_GetStartupDataAvailability(void);
#if defined(BUILD_MCU1_0) 
void SSM_Slave_App_HandleStateChange(SSM_CoreSlaveCoreStateDef Curr, SSM_CoreSlaveCoreStateDef Next);
#else
void SSM_Slave_App_HandleStateChange(SSM_CoreSlaveCoreStateDef_i Curr, SSM_CoreSlaveCoreStateDef_i Next);
#endif
void SSM_Slave_App_MainTask(void);


#endif



#endif
