#if defined(BUILD_MCU1_0)
	#include "Rte_SSM_Master.h"
#include "app_log.h"
#include "app_log_Boot.h"

#endif
#include "SSM_Master.h"
#include "SSM_Master_app.h"
#include "string.h"
#include "ipc_lookup_table.h"




#ifdef  SSM_APPLICATION_MASTER
extern SSM_MasterStateInfo SSM_mStateInfo;

 uint32 SSM_Master_App_GetIndex(uint32 Appidx,SSM_CORE_Defs Core)
{
  /* DD-ID: {81C2491B-549D-487b-9096-EDC944C4775C}*/
	uint32_t Idx=0u;
	if(Core<SSM_CORE_MAX)
	{
		if(Core != SSM_CORE_1_0)
		{
			Idx+=(uint32_t)SSM_MCU_1_0_Application_MAX;
			if(Core != SSM_CORE_2_0)
			{
				Idx+=(uint32_t)SSM_MCU_2_0_Application_MAX;
				if(Core != SSM_CORE_2_1)
				{
					Idx+=(uint32_t)SSM_MCU_2_1_Application_MAX;
				}
			}
		}

		Idx+=Appidx;
	}

	return Idx;
}


 
void SSM_Master_App_Read_MasterLocalCoreStatus(SSM_LocalCoreStatus *LocalState)
{
   /* DD-ID: {26F9ADCB-8E4E-4911-9CC2-13C48CC28536}*/
	// Read slave status of MCU1_0
	(void)Rte_Read_R_SSM_1_0_State_State_1_0(LocalState);

}
void SSM_Master_App_Read_AllCoreState(SSM_AllCoreStateDef *AllCoresState)
{
  /* DD-ID: {FD249B38-36A2-4f73-BF87-6721689B1FF1}*/
	
	uint32_t i;

	//Read from  RTE/Signal Manager/ Underlying COMM Layer
	SSM_1_0_CoreStatus S_1_0_Status;
	SSM_2_0_CoreStatus S_2_0_Status;
	SSM_2_1_CoreStatus S_2_1_Status;
	SSM_QNX_CoreStatus S_QNX_Status;
	
		//Now copy over the data into the indexes
	uint32_t idx=0u;

	//Read the present status of individual cores
	SSM_READ_CORESTATE_1_0(&S_1_0_Status);
	SSM_READ_CORESTATE_2_0(&S_2_0_Status);
	SSM_READ_CORESTATE_2_1(&S_2_1_Status);
	SSM_READ_CORESTATE_QNX(&S_QNX_Status);



	//Now copy over the data into the indexes
	idx=0u;

	//1_0 status;
	AllCoresState->CoreStateDef[SSM_CORE_1_0] = (SSM_CoreSlaveCoreStateDef)S_1_0_Status.CoreStatus;
	for(i=0u; (idx < (uint32_t)SSM_MAX_MONITORED_APPLICATIONS) && (i < (uint32_t)SSM_MCU_1_0_Application_MAX); i++)
	{
		AllCoresState->AppStatus[idx]=(SSM_ApplicationStatus)S_1_0_Status.LocalAppStatus[i];
		idx++;

	}

	//2_0 status;
	AllCoresState->CoreStateDef[SSM_CORE_2_0] = (SSM_CoreSlaveCoreStateDef)S_2_0_Status.CoreStatus;
	for(i=0u; (idx < (uint8_t)SSM_MAX_MONITORED_APPLICATIONS) && (i < (uint8_t)SSM_MCU_2_0_Application_MAX); i++)
	{
		AllCoresState->AppStatus[idx]=(SSM_ApplicationStatus)S_2_0_Status.LocalAppStatus[i];
		idx++;
	}

	//2_1 status;
	AllCoresState->CoreStateDef[SSM_CORE_2_1] = (SSM_CoreSlaveCoreStateDef)S_2_1_Status.CoreStatus;
	for(i=0u; (idx < (uint8_t)SSM_MAX_MONITORED_APPLICATIONS) && (i < (uint8_t)SSM_MCU_2_1_Application_MAX); i++)
	{
		AllCoresState->AppStatus[idx] = (SSM_ApplicationStatus)S_2_1_Status.LocalAppStatus[i];
		idx++;
	}

/* QNX Core Not using */
#if SSM_QNX_MONITOR
	/* QNX status */
	AllCoresState->CoreStateDef[SSM_CORE_QNX] = (SSM_CoreSlaveCoreStateDef)S_QNX_Status.CoreStatus;
	for(i=0u; (idx < (uint8_t)SSM_MAX_MONITORED_APPLICATIONS) && (i < (uint8_t)SSM_MCU_QNX_Application_MAX); i++)
	{
		AllCoresState->AppStatus[idx] = (SSM_ApplicationStatus)S_QNX_Status.LocalAppStatus[i];
		idx++;
	}
#endif
}


void SSM_Master_App_SendSystemState(SSM_SystemState g_CurrentSystemState)
{
  /* DD-ID: {41A15225-758E-4b3d-AF33-A771957425F3}*/
	SSM_SystemState SystemState;
	/* static_assert(sizeof(SSM_SystemState) == sizeof(SSM_SystemState),"Incompatible size") */
	(void)memcpy(&SystemState,&g_CurrentSystemState,sizeof(SystemState));


	(void)Rte_Write_P_SystemState_SystemState((const SSM_SystemState *)&SystemState);
	SSM_WRITE_SYSTEMSTATE(&SystemState);

}


/*
********************************************************************************
INTERFACE:  uint8_t GetFailSafeDebugFlag(void)

DESC:       This function reads debug flag from DID manager. It is used to enable
 	 	 	debug functionality and production functionality.

INPUTS:     None

Return:     Debug Flag value
********************************************************************************
*/
uint8 GetFailSafeDebugFlag(void)
{
   /* DD-ID:{666EC473-8D5F-4f97-8523-FBBAA8520123}*/
	uint8 DebugFlag;

	(void)Rte_Read_RpFailsafeDebug_Debugflag(&DebugFlag);

	return DebugFlag;
}



#endif


