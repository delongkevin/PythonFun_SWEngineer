


#include "PlatformDataTypes.h"
#include "SSM_Master.h"
#include "SSM_Master_app.h"
#include "string.h"
#include "pmic.h"
#ifdef SSM_APPLICATION_MASTER
#include "Rte_BswM_Type.h"
#include "Rte_BswM.h"
#include "Os.h"
#endif

#include <ti/csl/hw_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/cslr_spinlock.h>
#include <ti/csl/csl_spinlock.h>
#include "app_log.h"
#include "app_log_Boot.h"
#include "SSM_BSW_Interface.h"


#ifdef SSM_APPLICATION_MASTER
extern void SW_ResetMainDomainCores(void);

/* Forward Declaration */
SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_BOOTING_OnEntry(SSM_SystemStateDef OldState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_BOOTING_OnExit(SSM_SystemStateDef NewState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_BOOTING_Periodic(void);

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_IPCREADY_OnEntry(SSM_SystemStateDef OldState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_IPCREADY_OnExit(SSM_SystemStateDef NewState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_IPCREADY_Periodic(void);

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_RUNNING_OnEntry(SSM_SystemStateDef OldState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_RUNNING_OnExit(SSM_SystemStateDef NewState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_RUNNING_Periodic(void);

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_DEGRADED_OnEntry(SSM_SystemStateDef OldState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_DEGRADED_OnExit(SSM_SystemStateDef NewState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_DEGRADED_Periodic(void);

SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_StrtShtdwnClnUp_OnEntry(SSM_SystemStateDef OldState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_StrtShtdwnClnUp_OnExit(SSM_SystemStateDef NewState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_StrtShtdwnClnUp_Periodic(void);

SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_Shtdwn_RemCores_OnEntry(SSM_SystemStateDef OldState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_Shtdwn_RemCores_OnExit(SSM_SystemStateDef NewState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_Shtdwn_RemCores_Periodic(void);

SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_Master_Shutdown_OnEntry(SSM_SystemStateDef OldState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_Master_Shutdown_OnExit(SSM_SystemStateDef NewState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_Master_Shutdown_Periodic(void);

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_OFF_OnEntry(SSM_SystemStateDef OldState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_OFF_OnExit(SSM_SystemStateDef NewState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_OFF_Periodic(void);

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_BOOT_ERROR_OnEntry(SSM_SystemStateDef OldState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_BOOT_ERROR_OnExit(SSM_SystemStateDef NewState);
SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_BOOT_ERROR_Periodic(void);

SSM_STATIC_EXTERNAL_LINKAGE void SSM_Master_RequestStateChange(SSM_SystemStateDef NewState);

/* Const Variables */

#define SSM_DEBUG_BYTES		18u
#define SSM_VALUE_ONE		(uint8_t)1



/* State Transition information */
SSM_STATIC_EXTERNAL_LINKAGE SSM_CONST_EXTERNAL_LINKAGE SSM_StateMachineStateInfo SSM_StateTransitionInfo[SSM_STATE_MAX] =
	{
		{SSM_STATE_BOOTING, SSM_STATE_BOOTING_OnEntry, SSM_STATE_BOOTING_OnExit, SSM_STATE_BOOTING_Periodic, D_SSM_STATE_BOOTING_Timeout, SSM_STATE_BOOT_ERROR,
		 /* to ipc ready , degraded or boot error */
		 {FALSE, TRUE, FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, TRUE}},

		{SSM_STATE_IPCREADY, SSM_STATE_IPCREADY_OnEntry, SSM_STATE_IPCREADY_OnExit, SSM_STATE_IPCREADY_Periodic, D_SSM_STATE_IPCREADY_Timeout, SSM_STATE_BOOT_ERROR,
		 /* to running , degraded or boot error */
		 {FALSE, FALSE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, TRUE}},

		{SSM_STATE_RUNNING, SSM_STATE_RUNNING_OnEntry, SSM_STATE_RUNNING_OnExit, SSM_STATE_RUNNING_Periodic, D_SSM_STATE_RUNNING_Timeout, SSM_STATE_RUNNING,
		 /* To only degraded or powering down */
		 {FALSE, FALSE, FALSE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE}},

		{SSM_STATE_DEGRADED, SSM_STATE_DEGRADED_OnEntry, SSM_STATE_DEGRADED_OnExit, SSM_STATE_DEGRADED_Periodic, D_SSM_STATE_DEGRADED_Timeout, SSM_STATE_DEGRADED,
		 /* Back to Running or Shuting Down */
		 {FALSE, FALSE, TRUE, FALSE, TRUE, FALSE, FALSE, FALSE, FALSE}},

		{SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP, SSM_St_StrtShtdwnClnUp_OnEntry, SSM_St_StrtShtdwnClnUp_OnExit, SSM_St_StrtShtdwnClnUp_Periodic, D_SSM_STATE_POWERINGDOWN_Timeout, SSM_STATE_SHUTTINGDOWN_REMOTECORES,
		 /* Only to SSM_STATE_SHUTTINGDOWN_REMOTECORES */
		 {FALSE, FALSE, FALSE, FALSE, FALSE, TRUE, FALSE, FALSE, FALSE}},

		{SSM_STATE_SHUTTINGDOWN_REMOTECORES, SSM_St_Shtdwn_RemCores_OnEntry, SSM_St_Shtdwn_RemCores_OnExit, SSM_St_Shtdwn_RemCores_Periodic, D_SSM_STATE_SHUTTINGDOWN_REMOTECORES_Timeout, SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE,
		 /* Only toi SSM_STATE_SHUTTINGDOWN_REMOTECORES*/
		 {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, TRUE, FALSE, FALSE}},

		{SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE, SSM_St_Master_Shutdown_OnEntry, SSM_St_Master_Shutdown_OnExit, SSM_St_Master_Shutdown_Periodic, D_SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE_Timeout, SSM_STATE_OFF,
		 /* to running if ThermalShutDown was requested else to OFF*/
		 {FALSE, FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, TRUE, FALSE}},

		{SSM_STATE_OFF, SSM_STATE_OFF_OnEntry, SSM_STATE_OFF_OnExit, SSM_STATE_OFF_Periodic, D_SSM_STATE_OFF_Timeout, SSM_STATE_OFF,
		 /* Nothing wait for power off*/ /* Change if we want to allow rebooting */
		 {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE}},

		{SSM_STATE_BOOT_ERROR, SSM_STATE_BOOT_ERROR_OnEntry, SSM_STATE_BOOT_ERROR_OnExit, SSM_STATE_BOOT_ERROR_Periodic, D_SSM_STATE_BOOT_ERROR_Timeout, SSM_STATE_SHUTTINGDOWN_REMOTECORES,
		 /* Move to powering Down */
		 {FALSE, FALSE, FALSE, FALSE, TRUE, TRUE, FALSE, FALSE, FALSE}}};


/* RAM Variables */
SSM_STATIC_EXTERNAL_LINKAGE SSM_MasterStateInfo SSM_mStateInfo;

/* State Functions */

/* volatile int test_var=0u */
SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_BOOTING_OnEntry(SSM_SystemStateDef OldState)
{
  /* DD-ID: {33D9FC5E-2AA3-40b2-8238-38C0635CFCAF}*/
	
	/* initialize the Spinlock used by all cores */
	/* SPINLOCKModuleReset(CSL_NAVSS0_SPINLOCK_BASE) */

	/*  Ideally i should be waiting till all spinlocks should be cleared */
	/*  Only possible if loading of other cores are linked after this */
	(void)OldState;
	
}
SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_BOOTING_OnExit(SSM_SystemStateDef NewState)
{
  /* DD-ID: {052F5A99-9724-41c2-88BC-3F865A643136}*/
	(void)NewState;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_BOOTING_Periodic(void)
{
  /* DD-ID: {D63D7D84-13B5-481a-B651-092A06EE1E4D}*/
	bool_t bTemp = TRUE;
	uint32_t i;
	SSM_AllCoreStateDef AllCoresState;

	SSM_Master_App_Read_AllCoreState(&AllCoresState);

	// Consider the QNX core after SSM code changes are added in QNX.
#if SSM_QNX_MONITOR
	for (i = 0u; i < (uint32_t)SSM_CORE_MAX; i++)
#else
	for (i = 0u; i <(uint32_t) SSM_CORE_QNX; i++)
#endif
	{
		if (AllCoresState.CoreStateDef[i] <= SSM_SlaveCore_State_BSP_Booting)
		{
			bTemp = FALSE;
		}
	}

	

	if (bTemp == (bool_t)TRUE)
	{
		// All cores IPC is up:
		SSM_Master_RequestStateChange(SSM_STATE_IPCREADY);
	}
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_IPCREADY_OnEntry(SSM_SystemStateDef OldState)
{
  /* DD-ID: {7E438F2B-AC94-4e07-9E73-1FBC65177893}*/
	(void)OldState;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_IPCREADY_OnExit(SSM_SystemStateDef NewState)
{
  /* DD-ID: {5C00AA9A-C103-4e41-A343-79AD118C8BAB}*/
	(void)NewState;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_IPCREADY_Periodic(void)
{
  /* DD-ID: {69931801-5E5E-4b9b-BBCF-046CDBD78BC9}*/
	bool_t bTemp = TRUE;
	SSM_AllCoreStateDef AllCoresState;
	uint32_t i;

	SSM_Master_App_Read_AllCoreState(&AllCoresState);
	// Check with StartupData Manager if calibration has been comminucated to all cores
	// Consider the QNX core after SSM code changes are added in QNX.
#if SSM_QNX_MONITOR
	for (i = 0u; i < (uint32_t)SSM_CORE_MAX; i++)
#else
	for (i = 0u; i < (uint32_t)SSM_CORE_QNX; i++)
#endif
	{
		if (AllCoresState.CoreStateDef[i] != SSM_SlaveCore_State_Running)
		{
			bTemp = FALSE;
		}
	}

	if (bTemp == (bool_t)TRUE)
	{
		// All cores IPC is up:
		SSM_Master_RequestStateChange(SSM_STATE_RUNNING);
	}
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_RUNNING_OnEntry(SSM_SystemStateDef OldState)
{
  /* DD-ID: {0E6F1473-3198-4f68-BD8B-546047E75C84}*/
	(void)OldState;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_RUNNING_OnExit(SSM_SystemStateDef NewState)
{
  /* DD-ID: {E2D13E9E-F31F-48ef-B93A-07CBD7BC1AEF}*/
	(void)NewState;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_RUNNING_Periodic(void)
{
	/* DD-ID:{3FCB441E-22DE-4c20-971E-EAE6773DEBD5}*/
	if((SSM_mStateInfo.bShutDownRequested == D_SHUTDOWN_REQUESTED_FLAG_UNIQUE) || 
		(SSM_mStateInfo.bRestartRequested == D_SHUTDOWN_REQUESTED_FLAG_UNIQUE) ||
		(SSM_mStateInfo.bThermalShutDownRequested == D_SHUTDOWN_REQUESTED_FLAG_UNIQUE))
	{
   	SSM_Master_RequestStateChange(SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP);
	}
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_DEGRADED_OnEntry(SSM_SystemStateDef OldState)
{
  /* DD-ID: {872DE496-05CD-49f0-A31A-17553B218BAA}*/
	(void)OldState;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_DEGRADED_OnExit(SSM_SystemStateDef NewState)
{
  /* DD-ID: {657DB1B9-3C9D-4fad-A487-2961CC33CA7A}*/
	(void)NewState;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_DEGRADED_Periodic(void)
{
  /* DD-ID: {D0D6FA14-F554-47e9-BCB5-F18CAC966499}*/
}

SSM_STATIC_EXTERNAL_LINKAGE bool_t SSM_STATE_STARTSHUTDOWNCLEANUP_IsExemptedApp(SSM_LocalCoreApplications Idx)
{
  /* DD-ID: {2D12B599-9824-495a-8AB2-DD9D86DBCE3E}*/
	uint32_t i;
	uint32_t v_index;

	bool_t bRet=FALSE;

	SSM_STATIC_EXTERNAL_LINKAGE SSM_CONST_EXTERNAL_LINKAGE SSM_LocalCoreApplications SSM_Apps_excludedDuringShtDwn[] = {SSM_MCU_1_0_Application_CalDataProvider};

	SSM_STATIC_EXTERNAL_LINKAGE SSM_CONST_EXTERNAL_LINKAGE uint32_t Apps_excludedDuringShtDwn_Cnt = sizeof(SSM_Apps_excludedDuringShtDwn)/sizeof(SSM_LocalCoreApplications);

/* Loop will executed one time here but this loop is created in geneal purpose */
/* Need to comment-PRQA  2877 */	
	for(i=0u;i<Apps_excludedDuringShtDwn_Cnt;i++)
	{
		v_index = SSM_Master_App_GetIndex((uint32)SSM_Apps_excludedDuringShtDwn[i], SSM_SLAVE_CURRENTCORE);
		if(v_index == (uint32)Idx)
		{
			bRet=TRUE;
		}
	}

	return bRet;
}

SSM_STATIC_EXTERNAL_LINKAGE bool_t SSM_STATE_STARTSHUTDOWNCLEANUP_IsThermalShutdownExemptedApp(SSM_LocalCoreApplications Idx)
{
    /* DD-ID:{268CE66B-BDFE-4ae2-AC71-510FFB454BFA}*/
	uint32_t i;
	uint32_t v_index;
	bool_t bRet=FALSE;
	SSM_STATIC_EXTERNAL_LINKAGE SSM_CONST_EXTERNAL_LINKAGE SSM_LocalCoreApplications SSM_Apps_ThermalShtDwnExempt[] = {SSM_MCU_1_0_Application_CalDataProvider,
																																				  SSM_MCU_1_0_Application_ProxiManager,
																																			  SSM_MCU_1_0_Application_PartNumManager};
	SSM_STATIC_EXTERNAL_LINKAGE SSM_CONST_EXTERNAL_LINKAGE uint32_t Apps_ThermalShtDwnExempt_Cnt = sizeof(SSM_Apps_ThermalShtDwnExempt)/sizeof(SSM_LocalCoreApplications);

	for(i=0;i<Apps_ThermalShtDwnExempt_Cnt;i++)
	{
		v_index = SSM_Master_App_GetIndex((uint32)SSM_Apps_ThermalShtDwnExempt[i], SSM_SLAVE_CURRENTCORE);
		if( v_index == (uint32)Idx)
		{
			bRet=TRUE;
		}
	}

	return bRet;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_StrtShtdwnClnUp_OnEntry(SSM_SystemStateDef OldState)
{
  /* DD-ID: {032ABFA0-4CF9-4cb3-96D0-A5C4AB762FEF}*/
	(void)OldState;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_StrtShtdwnClnUp_OnExit(SSM_SystemStateDef NewState)
{
  /* DD-ID: {E4622341-F040-4921-B08A-0456F60D806E}*/
	(void)NewState;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_StrtShtdwnClnUp_Periodic(void)
{
  /* DD-ID: {D1C1B2D7-F863-4a19-80F2-95B17E09658D}*/
	bool_t v_shutDown =  TRUE;
	bool_t bTemp = TRUE;
	SSM_AllCoreStateDef AllCoresState;
	uint32_t i;
	static uint8_t cntr = 0u;
	static bool_t StartDelayFlag = FALSE;

	SSM_Master_App_Read_AllCoreState(&AllCoresState);

	if(SSM_mStateInfo.bThermalShutDownRequested == D_SHUTDOWN_REQUESTED_FLAG_UNIQUE)
	{
		for (i = 0u; i < (uint32_t)SSM_LOCALAPPLICATION_MAX; i++)
		{
			if(AllCoresState.AppStatus[i] != SSM_APPSTATE_STOPPED)
			{
				//State is not Stopped
				v_shutDown = SSM_STATE_STARTSHUTDOWNCLEANUP_IsThermalShutdownExemptedApp((SSM_LocalCoreApplications)i); 
				if(v_shutDown == (bool_t)FALSE)
				{
					//Its not an exmpted app like CalDataProvider
					bTemp = FALSE;
				}
			}
		}
	}
	else
	{

		for (i = 0u; i < (uint32_t)SSM_LOCALAPPLICATION_MAX; i++)
		{
			if(AllCoresState.AppStatus[i] != SSM_APPSTATE_STOPPED)
			{
				//State is not Stopped
				v_shutDown = (bool_t)SSM_STATE_STARTSHUTDOWNCLEANUP_IsExemptedApp((SSM_LocalCoreApplications)i);
				if( v_shutDown == (bool_t)FALSE)
				{
					//Its not an exmpted app like CalDataProvider
					bTemp = FALSE;
				}
			}
		}
	}
	
	// Enable below code after QNX and up and running
#if SSM_QNX_MONITOR
	//Check remaining slave core:
	for (; i < SSM_MAX_MONITORED_APPLICATIONS; i++)
	{
		if(AllCoresState.AppStatus[i] != SSM_APPSTATE_STOPPED)
		{
			bTemp = FALSE;
		}
	}
#else

	//Check for MCU2_0 and MCU2_1 slave cores
	for (; i < ((uint32_t)((uint32_t)SSM_MCU_1_0_Application_MAX + (uint32_t)SSM_MCU_2_0_Application_MAX +(uint32_t) SSM_MCU_2_1_Application_MAX)); i++)
	{
		if(AllCoresState.AppStatus[i] != SSM_APPSTATE_STOPPED)
		{
			bTemp = FALSE;
		}
	}
	
#endif

	if (bTemp == (bool_t)TRUE)
	{
		StartDelayFlag = TRUE;
	}

	/*
	As SSM is not monitoring any QNX applications, a safe delay of 300ms is added to receive
	all the IPC messages from QNX. After the delay, shutdown remote cores will be processed.
	*/
	if((bool_t)TRUE == (bool_t)StartDelayFlag)
	{
		//delay for 300ms
		if(cntr >= 30u)
		{
			// All monitored applications have shutdown
			SSM_Master_RequestStateChange(SSM_STATE_SHUTTINGDOWN_REMOTECORES);
			StartDelayFlag = FALSE;
		}
		else
		{
			cntr++;
		}
	}
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_Shtdwn_RemCores_OnEntry(SSM_SystemStateDef OldState)
{
  /* DD-ID: {E4ED3917-976D-48a4-A3CC-2D3446660D49}*/
	//Send the command to shut down the slave cores
	(void)OldState;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_Shtdwn_RemCores_OnExit(SSM_SystemStateDef NewState)
{
  /* DD-ID: {79FC3D01-2CC1-40ea-84EF-F7468F1A5741}*/
	(void)NewState;
}
SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_Shtdwn_RemCores_Periodic(void)
{
  /* DD-ID: {DBC82C49-83BD-4c26-928C-D1C38D74BA77}*/
	//Check the status of core shutdown
	//Temporarily transition over to 
	SSM_Master_RequestStateChange(SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE);
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_Master_Shutdown_OnEntry(SSM_SystemStateDef OldState)
{
  /* DD-ID: {E49A3C36-D38C-4186-BAF6-560A60258CAD}*/
	(void)OldState;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_Master_Shutdown_OnExit(SSM_SystemStateDef NewState)
{
  /* DD-ID: {7B8DFA33-4193-42e2-9D04-8D2F5A51EC56}*/
	if(SSM_STATE_RUNNING == NewState)
	{
		SSM_mStateInfo.bThermalShutDownRequested = FALSE;
		/* Reset remote cores through SciClient */
		SW_ResetMainDomainCores();
	}
	else
	{
		/* Call BSW to perform shutdown*/
		(void)Rte_Switch_BswM_Switch_SSM_BSW_SystemState_Mode((uint8)RTE_MODE_SSM_SystemState_Mode_SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE);
	}
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_St_Master_Shutdown_Periodic(void)
{
  /* DD-ID: {62EE0DA8-2513-4fb6-B4A6-E3263B6A72CF}*/
	bool_t bRet=TRUE;
	SSM_LocalCoreStatus LocalState;
	SSM_Master_App_Read_MasterLocalCoreStatus(&LocalState);

	//Wait for all the master core shutdown status to shutdown
	if(LocalState.LocalAppStatus[SSM_MCU_1_0_Application_CalDataProvider] == SSM_APPSTATE_STOPPED)
	{
		bRet=FALSE;
	}

	if(bRet == (bool_t)TRUE)
	{
		if(SSM_mStateInfo.bThermalShutDownRequested == D_SHUTDOWN_REQUESTED_FLAG_UNIQUE)
		{
			SSM_Master_RequestStateChange(SSM_STATE_RUNNING);
		}
		else
		{
			SSM_Master_RequestStateChange(SSM_STATE_OFF);
		}
		
	}
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_OFF_OnEntry(SSM_SystemStateDef OldState)
{
  /* DD-ID: {BD392ECD-B9E1-44ac-9100-6A0A516D22CB}*/
	(void)OldState;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_OFF_OnExit(SSM_SystemStateDef NewState)
{
  /* DD-ID: {393D0698-B500-4b4d-B766-7898D9C5EB90}*/
	(void)NewState;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_OFF_Periodic(void)
{
  /* DD-ID: {9A64E53D-DC07-41c1-9204-DC8ED1AD19AD}*/
}


SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_BOOT_ERROR_OnEntry(SSM_SystemStateDef OldState)
{
  /* DD-ID: {48426AA2-3D37-4cfd-8705-75F488DAFE3A}*/
	(void)OldState;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_BOOT_ERROR_OnExit(SSM_SystemStateDef NewState)
{
  /* DD-ID: {310D3F86-1F34-4125-A087-EF2D7574B02B}*/
	(void)NewState;
}

SSM_STATIC_EXTERNAL_LINKAGE void SSM_STATE_BOOT_ERROR_Periodic(void)
{
  /* DD-ID: {7F12F9D2-867D-48f5-868E-221CF5AA31CB}*/
	/* TBD Remove this once watchdog check all core running status and perform shutdown if not running*/
	if((SSM_mStateInfo.bShutDownRequested == D_SHUTDOWN_REQUESTED_FLAG_UNIQUE) || 
		(SSM_mStateInfo.bRestartRequested == D_SHUTDOWN_REQUESTED_FLAG_UNIQUE))
	{
   	(void)Rte_Switch_BswM_Switch_SSM_BSW_SystemState_Mode((uint8)RTE_MODE_SSM_SystemState_Mode_SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE);
	}
}


SSM_STATIC_EXTERNAL_LINKAGE void SSM_Master_HandleInvalid_SSMState(SSM_SystemStateDef OldState, SSM_SystemStateDef NewStateDef)
{
  /* DD-ID: {A393DE95-0050-40dd-8840-D182EB81E514}*/
  /* DD-ID:{3D20C8C6-645F-4e33-B478-AF71F8200F85}*/

	// Report DET
	// Log Error
	(void)OldState;
	(void)NewStateDef;
}


void SSM_Master_Init(void)
{
  /* DD-ID:{4C612C12-C09C-4262-B958-2CF8F590E74E}*/
	SSM_STATIC_EXTERNAL_LINKAGE SSM_CONST_EXTERNAL_LINKAGE SSM_MasterStateInfo SSM_mStateInfo_Default = {0u, 0u, {SSM_STATE_BOOTING, SSM_DEGRADEDSTATE_MAX}, FALSE, FALSE, FALSE};
	SSM_mStateInfo = SSM_mStateInfo_Default;
	SSM_STATE_BOOTING_OnEntry(SSM_STATE_BOOTING);
}


SSM_STATIC_EXTERNAL_LINKAGE void SSM_Master_RequestStateChange(SSM_SystemStateDef NewState)
{
  /* DD-ID: {A393DE95-0050-40dd-8840-D182EB81E514}*/
  /* DD-ID:{44868A53-FFD1-47b6-B777-050AD06C93CE}*/
	SSM_SystemStateDef OldState;
	// Range Check
	if ((SSM_mStateInfo.g_CurrentSystemState.SystemState < SSM_STATE_MAX) && (NewState < SSM_STATE_MAX))
	{

		// Check if the transition is allowed
		if (SSM_StateTransitionInfo[SSM_mStateInfo.g_CurrentSystemState.SystemState].bAllowedTransitionTo[NewState] == (bool_t)TRUE)
		{
			if (SSM_StateTransitionInfo[SSM_mStateInfo.g_CurrentSystemState.SystemState].onExit != NULL)
			{
				SSM_StateTransitionInfo[SSM_mStateInfo.g_CurrentSystemState.SystemState].onExit(NewState);
			}
			OldState = SSM_mStateInfo.g_CurrentSystemState.SystemState;
			SSM_mStateInfo.g_CurrentSystemState.SystemState = NewState;
			if (SSM_StateTransitionInfo[SSM_mStateInfo.g_CurrentSystemState.SystemState].onEntry != NULL)
			{
				SSM_StateTransitionInfo[SSM_mStateInfo.g_CurrentSystemState.SystemState].onEntry(OldState);
			}

			// Reset the count for the current state
			SSM_mStateInfo.u32CurrentStateCount = 0u;
			SSM_Master_App_SendSystemState(SSM_mStateInfo.g_CurrentSystemState);
		}
		else
		{
			SSM_Master_HandleInvalid_SSMState(SSM_mStateInfo.g_CurrentSystemState.SystemState, NewState);
		}
	}
	else
	{
		SSM_Master_HandleInvalid_SSMState(SSM_mStateInfo.g_CurrentSystemState.SystemState, NewState);
	}
}


SSM_STATIC_EXTERNAL_LINKAGE void SSM_CalculateAndManage_TimeOut(void)
{
  /* DD-ID: {E1C37D79-0952-47bd-ADBF-AF86E7F6164C}*/

	/*SSM debug data*/
	SSM_STATIC_EXTERNAL_LINKAGE uint8_t	SSM_FaultInfo[SSM_DEBUG_BYTES];
	uint8_t idx = 0u;
	uint8_t index = 0u;
	uint8_t reason_SSMReset = 0u;
	bool_t v_shutDown =  TRUE;
	SSM_AllCoreStateDef AllCoresState;

	// Sanity check
	if (SSM_mStateInfo.g_CurrentSystemState.SystemState < SSM_STATE_MAX)
	{
		// Value of 0 indicates no timeout
		if (SSM_StateTransitionInfo[SSM_mStateInfo.g_CurrentSystemState.SystemState].u32MaxDuration > 0u)
		{
			if (SSM_mStateInfo.u32CurrentStateCount >= SSM_StateTransitionInfo[SSM_mStateInfo.g_CurrentSystemState.SystemState].u32MaxDuration)
			{

				/* Read individual core applications status */ 
				SSM_Master_App_Read_AllCoreState(&AllCoresState);

				// Timeout has happened : bummer

				/*
				3 possible reset reasons via SSM
				1. All cores were not finished booting with in Boot Timeout (Reason: SSM_BOOT_ISSUE)
				2. All core applications were not running with in IPC_READY Timeout (Reason: SSM_APP_RUN_ISSUE)
				3. All cores were not completed cleanup activities within time during shutdown request (Reason: SSM_SHUTDOWN_CLEANUP_ISSUE)
				*/
				switch (SSM_mStateInfo.g_CurrentSystemState.SystemState)
				{
					case SSM_STATE_BOOTING:
						SSM_FaultInfo[index] = SSM_BOOT_ISSUE;
						
						/* check for Cores, which are not in RUNNING state */
						/* Consider the QNX core after SSM code changes are added in QNX. */
						#if 0
						for (idx = 0u; idx < (uint8_t)SSM_CORE_MAX; idx++)
						#else
						for (idx = 0u; idx < (uint8_t)SSM_CORE_QNX; idx++)
						#endif
						{
							if (AllCoresState.CoreStateDef[idx] < SSM_SlaveCore_State_BSP_Init_Done)
							{
								reason_SSMReset = (SSM_BOOT_ISSUE_RESET_REASON_BASE + idx);
								break;
							}
						}
						break;
					case SSM_STATE_IPCREADY:
						SSM_FaultInfo[index] = SSM_APP_RUN_ISSUE;
						for (idx = 0u; idx < (uint8_t)SSM_MAX_MONITORED_APPLICATIONS; idx++)
						{
							/* check for applications, which are not in RUNNING state */
							if(SSM_APPSTATE_RUNNING != (uint8_t) AllCoresState.AppStatus[idx])
							{
								reason_SSMReset = (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + idx);
								break;
							}
						}						
						break;
					case SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP:
						SSM_FaultInfo[index] = SSM_SHUTDOWN_CLEANUP_ISSUE;
						for (idx = 0u; idx < (uint8_t)SSM_MAX_MONITORED_APPLICATIONS; idx++)
						{
							/* check for Application, which is not Stopped and which is not exempted from Shudown checks*/
							/* Need to Suppress-PRQA  03415  */
							/* This && and || is used intentionally */
							
							v_shutDown =  (bool_t)SSM_STATE_STARTSHUTDOWNCLEANUP_IsExemptedApp((SSM_LocalCoreApplications)idx);
							if((SSM_APPSTATE_STOPPED != (uint8_t) AllCoresState.AppStatus[idx]) 
							   && ( v_shutDown == (bool_t)FALSE ))
							{
								reason_SSMReset = ((uint8_t)SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE +(uint8_t)idx);
								break;
							}
						}						
						break;
					default:
						//ignore
						break;
				}

				index = index + SSM_VALUE_ONE;

				for (idx = 0u; idx < (uint8_t)SSM_MAX_MONITORED_APPLICATIONS; idx++)
				{

						SSM_FaultInfo[index] = (uint8_t) AllCoresState.AppStatus[idx];
						index = index + SSM_VALUE_ONE;

				}

				// Send the debug data over CAN
				Os_Call_f_Send_Dbg_SSMFault_CanTx(&SSM_FaultInfo[0]);

				/* Store valid Reset Reason in NVM */
				if(0u != reason_SSMReset)
				{
					Os_Call_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus(0u, reason_SSMReset, TRUE);
				}
				
				// Request a transition out to the timeout error state
				SSM_Master_RequestStateChange(SSM_StateTransitionInfo[SSM_mStateInfo.g_CurrentSystemState.SystemState].TimedOutErrorState);
			}
		}
	}
	else
	{
		SSM_Master_HandleInvalid_SSMState(SSM_mStateInfo.g_CurrentSystemState.SystemState, SSM_mStateInfo.g_CurrentSystemState.SystemState);
	}

}


void SSM_Master_PeriodicRunnable(void)
{
  /* DD-ID: {A393DE95-0050-40dd-8840-D182EB81E514}*/
  /* DD-ID:{2AC95AD8-FDD1-4494-B454-85676371D945}*/


	// Update the Counters
	SSM_mStateInfo.PeriodicRunnableCount = SSM_mStateInfo.PeriodicRunnableCount + 1u;
	SSM_mStateInfo.u32CurrentStateCount = SSM_mStateInfo.u32CurrentStateCount + 1u;
	uint8 FailSafeDegugFlag = 0u;

	/*
	Read the debug flag value and if the debug flag is set, then avoid
	considering SSM state timeouts.
	*/
	FailSafeDegugFlag = GetFailSafeDebugFlag();

	if((bool_t)FALSE == (bool_t)FailSafeDegugFlag)
	{   
		// Check if any state timeouts have happened
		SSM_CalculateAndManage_TimeOut();
	}
	else
	{
		// Not considering SSM state timeouts during the Debug mode.
	}


	if (SSM_mStateInfo.g_CurrentSystemState.SystemState < SSM_STATE_MAX)
	{
		// Execute the main fucntion in that state
		SSM_StateTransitionInfo[SSM_mStateInfo.g_CurrentSystemState.SystemState].Periodic();
	}
	else
	{
	}
}

void SSM_Master_SetShutDownRequest(void)
{
  /* DD-ID:{A32499F3-670B-48ca-98F2-8F0D088A3F7B}*/
	SSM_mStateInfo.bShutDownRequested = D_SHUTDOWN_REQUESTED_FLAG_UNIQUE;
}


void SSM_Master_SetRestartRequest(void)
{
    /* DD-ID:{383294AA-2738-4254-88D3-94B1A5EA3429}*/
  SSM_mStateInfo.bRestartRequested = D_SHUTDOWN_REQUESTED_FLAG_UNIQUE;
}

void SSM_Master_SetThermalShutDownRequest(void)
{
  /* DD-ID: {CD42A3C9-07A6-485e-ABA4-64DA937EDBEE}*/
	SSM_mStateInfo.bThermalShutDownRequested = D_SHUTDOWN_REQUESTED_FLAG_UNIQUE;
}

#endif
