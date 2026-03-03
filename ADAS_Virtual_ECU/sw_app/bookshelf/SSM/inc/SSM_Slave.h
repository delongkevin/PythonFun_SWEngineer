#ifndef SSM_SLAVE_H_INCGUARD
#define SSM_SLAVE_H_INCGUARD

#include "PlatformDataTypes.h"
#include "SSM_Cfg.h"
#include "SSM_Defs.h"

#ifdef  SSM_APPLICATION_SLAVE

void SSM_Slave_Init(void);
void SSM_Slave_MainTask(void);
#if defined(BUILD_MCU1_0)
bool_t SSM_Slave_RequestState(SSM_CoreSlaveCoreStateDef NextState);
bool_t SSM_Slave_SetApplicationStatus(SSM_LocalCoreApplications AppId, SSM_ApplicationStatus Status_var);
#else
bool_t SSM_Slave_RequestState(SSM_CoreSlaveCoreStateDef_i NextState);
bool_t SSM_Slave_SetApplicationStatus(SSM_LocalCoreApplications AppId, SSM_ApplicationStatus_i Status_var);
#endif

#endif

#endif
