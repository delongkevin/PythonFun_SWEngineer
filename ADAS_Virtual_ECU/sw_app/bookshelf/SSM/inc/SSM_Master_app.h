#ifndef SSM_MASTER_APP_H_INCGUARD
#define SSM_MASTER_APP_H_INCGUARD

#include "SSM_Cfg.h"
#include "SSM_Defs.h"
#if defined(BUILD_MCU1_0)
#include "Os_Lcfg.h"
#endif


#ifdef  SSM_APPLICATION_MASTER

#define SSM_READ_CORESTATE_1_0(x) (void)Rte_Read_R_SSM_1_0_State_State_1_0(x)
#define SSM_READ_CORESTATE_2_0(x) (void)Rte_Read_R_SSM_2_State_State_2_0(x)
#define SSM_READ_CORESTATE_2_1(x) (void)Rte_Read_R_SSM_2_State_State_2_1(x)
#define SSM_READ_CORESTATE_QNX(x) (void)Rte_Read_R_SSM_QNXState_State_QNX(x)

#define SSM_WRITE_SYSTEMSTATE(x)  (void)Os_Call_RE_IpcTxData(x,(uint16_t)e_IpcMsgId_Data_SSM_SystemState,(uint16_t)sizeof(SystemState))


typedef struct
{
	SSM_CoreSlaveCoreStateDef CoreStateDef[SSM_CORE_MAX];
	SSM_ApplicationStatus AppStatus[SSM_MAX_MONITORED_APPLICATIONS];
}SSM_AllCoreStateDef;


void SSM_Master_App_Read_AllCoreState(SSM_AllCoreStateDef *AllCoresState);
//void SSM_Master_App_Read_StartupDataState(SSM_ALLCORE_STARTUPDATA_Status* AllCoresStartupDataState);
void SSM_Master_App_SendSystemState(SSM_SystemState g_CurrentSystemState);
void SSM_Master_App_Read_MasterLocalCoreStatus(SSM_LocalCoreStatus *LocalState);
uint32 SSM_Master_App_GetIndex(uint32 Appidx,SSM_CORE_Defs Core);
uint8 GetFailSafeDebugFlag(void);
#endif


#endif

