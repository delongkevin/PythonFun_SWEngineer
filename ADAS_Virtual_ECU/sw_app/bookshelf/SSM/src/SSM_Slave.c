#include "PlatformDataTypes.h"
#include "SSM_Slave.h"
#include "SSM_Slave_app.h"


#ifdef  SSM_APPLICATION_SLAVE


static SSM_LocalCoreStatus g_LocalCoreStatus;
static uint32_t g_LastStateTime_ms;
static void SSM_Slave_Determine_State(void);



void SSM_Slave_Init(void)
{
  /* DD-ID: {BCA1D8AF-A794-45fe-BFCE-813533CA35FE}*/
	uint16_t i = 0;

	g_LastStateTime_ms = 0;
	#if defined(BUILD_MCU1_0)
	g_LocalCoreStatus.CoreStatus = SSM_SlaveCore_State_BSP_Booting;
	#else
	g_LocalCoreStatus.CoreStatus = SSM_SlaveCore_State_BSP_Booting_i;
	#endif

	for (i = 0; i < (uint16_t)SSM_LOCALAPPLICATION_MAX; i++)
	{
		#if defined(BUILD_MCU1_0)
		g_LocalCoreStatus.LocalAppStatus[i] = SSM_APPSTATE_UNINIT;
		#else
		g_LocalCoreStatus.LocalAppStatus[i] = SSM_APPSTATE_UNINIT_i;
		#endif
	}
}

#if defined(BUILD_MCU1_0)
bool_t SSM_Slave_SetApplicationStatus(SSM_LocalCoreApplications AppId, SSM_ApplicationStatus Status_var)
#else
bool_t SSM_Slave_SetApplicationStatus(SSM_LocalCoreApplications AppId, SSM_ApplicationStatus_i Status_var)
#endif
{
	/* DD-ID: {A6C2BC65-5953-417f-80FB-8F1D27688EC8}*/
	/* DD-ID:{672F0CBC-A17A-4120-BF40-1339667DDFFF}*/
	bool_t bRet = TRUE;

	#if defined(BUILD_MCU1_0)
	if ((AppId < SSM_LOCALAPPLICATION_MAX) && (Status_var< SSM_APPSTATE_MAX))
	#else
	if ((AppId < SSM_LOCALAPPLICATION_MAX) && (Status_var< SSM_APPSTATE_MAX_i))
	#endif
	{
		g_LocalCoreStatus.LocalAppStatus[AppId] = Status_var;
	}
	else
	{
		bRet = FALSE;
	}
	return bRet;
}


/* Function Not used in this project,This is for future use hence not removed */
/*
#if defined(BUILD_MCU1_0)
SSM_CoreSlaveCoreStateDef SSM_Slave_GetState(void)
#else
SSM_CoreSlaveCoreStateDef_i SSM_Slave_GetState(void)
#endif
{
	 DD-ID: {2258310B-348E-4cea-BA64-93AE5DD35861}
	 DD-ID:{7E202D09-CAFB-4d33-A1D8-8D4370AFE1C7}
	return g_LocalCoreStatus.CoreStatus;
}
*/

#if defined(BUILD_MCU1_0)
bool_t SSM_Slave_RequestState(SSM_CoreSlaveCoreStateDef NextState)
#else
bool_t SSM_Slave_RequestState(SSM_CoreSlaveCoreStateDef_i NextState)
#endif
{
	/* DD-ID: {DB8C0416-685A-4dd9-84AC-1F190120012C}*/
	/* DD-ID:{078A5016-BE23-4045-81BA-A5EAC980906A}*/
	uint32_t CurrTime;
	CurrTime = SSM_Slave_App_getLocalTime();
	bool_t StateChangeAccepted = FALSE;

#if defined(BUILD_MCU1_0)
static volatile uint32_t g_StateTransitionTime[SSM_SlaveCore_State_MAX];
#else
static volatile uint32_t g_StateTransitionTime[SSM_SlaveCore_State_MAX_i];
#endif

	#if defined(BUILD_MCU1_0)
	SSM_CoreSlaveCoreStateDef CurrSt;
	#else
	SSM_CoreSlaveCoreStateDef_i CurrSt;
	#endif

	uint16_t ExpectedState = (uint16_t)g_LocalCoreStatus.CoreStatus + 1u;
	if ((uint16_t)NextState == ExpectedState)
	{
		StateChangeAccepted = TRUE;
	}	

	if (StateChangeAccepted == (bool_t)TRUE)
	{
		g_StateTransitionTime[g_LocalCoreStatus.CoreStatus] = CurrTime - g_LastStateTime_ms;
		g_LastStateTime_ms = CurrTime;

		CurrSt = g_LocalCoreStatus.CoreStatus;
		g_LocalCoreStatus.CoreStatus = NextState;

		//Notify other cores about the change before any custom changes
		SSM_Slave_App_SendCoreStatus(&g_LocalCoreStatus);

		//Custom handling 
		SSM_Slave_App_HandleStateChange(CurrSt, NextState);
	}


	return StateChangeAccepted;
}

static void SSM_Slave_Determine_State(void)
{
  /* DD-ID: {940159F6-200E-440c-8150-26950740FDFD}*/
  /* DD-ID:{1399234E-4ACD-40b3-BA8C-C1F1BF7877D8}*/

	uint16_t i = 0;
	bool_t bRet;

	bool_t bTemp;
	

	switch (g_LocalCoreStatus.CoreStatus)
	{
		#if defined(BUILD_MCU1_0)
		case SSM_SlaveCore_State_BSP_Init_Done:
		#else
		case SSM_SlaveCore_State_BSP_Init_Done_i:
		#endif
		{
			bTemp = SSM_Slave_App_GetStartupDataAvailability();
			if (bTemp == (bool_t)TRUE)
			{
				#if defined(BUILD_MCU1_0)
				(void)SSM_Slave_RequestState(SSM_SlaveCore_State_Calibrated);
				#else
				(void)SSM_Slave_RequestState(SSM_SlaveCore_State_Calibrated_i);
				#endif
			}
		}
		break;

		#if defined(BUILD_MCU1_0)
		case SSM_SlaveCore_State_Calibrated:
		#else
		case SSM_SlaveCore_State_Calibrated_i:
		#endif
		{
			bRet = TRUE;
			for (i = 0; i < (uint16_t)SSM_LOCALAPPLICATION_MAX; i++)
			{
				#if defined(BUILD_MCU1_0)
				if (!((g_LocalCoreStatus.LocalAppStatus[i] == SSM_APPSTATE_INIT) || (g_LocalCoreStatus.LocalAppStatus[i] == SSM_APPSTATE_RUNNING)))
				#else
				if (!((g_LocalCoreStatus.LocalAppStatus[i] == SSM_APPSTATE_INIT_i) || (g_LocalCoreStatus.LocalAppStatus[i] == SSM_APPSTATE_RUNNING_i)))
				#endif
				{
					bRet = FALSE;
				}
			}

			if (bRet == (bool_t)TRUE)
			{
				#if defined(BUILD_MCU1_0)
				(void)SSM_Slave_RequestState(SSM_SlaveCore_State_AppInitialized);
				#else
				(void)SSM_Slave_RequestState(SSM_SlaveCore_State_AppInitialized_i);
				#endif
			}
		}
		break;

		#if defined(BUILD_MCU1_0)
		case SSM_SlaveCore_State_AppInitialized:
		#else
		case SSM_SlaveCore_State_AppInitialized_i:
		#endif
		{
			bRet = TRUE;
			for (i = 0; i < (uint16_t)SSM_LOCALAPPLICATION_MAX; i++)
			{
				#if defined(BUILD_MCU1_0)
				if (g_LocalCoreStatus.LocalAppStatus[i] != SSM_APPSTATE_RUNNING)
				#else
				if (g_LocalCoreStatus.LocalAppStatus[i] != SSM_APPSTATE_RUNNING_i)
				#endif
				{
					bRet = FALSE;
				}
			}

			if (bRet == (bool_t)TRUE)
			{
				#if defined(BUILD_MCU1_0)
				(void)SSM_Slave_RequestState(SSM_SlaveCore_State_Running);
				#else
				(void)SSM_Slave_RequestState(SSM_SlaveCore_State_Running_i);
				#endif
			}
		}
		break;
		default:
			/* Do Nothing */
		break;
	}
}


void SSM_Slave_MainTask(void)
{
  /* DD-ID: {6FF70C99-7EB3-4469-81FC-42ED35894ABB}*/
	//Determine the new state
	SSM_Slave_Determine_State();

	SSM_Slave_App_MainTask();

	//Notify other cores about the change
	SSM_Slave_App_SendCoreStatus(&g_LocalCoreStatus);
}


#endif


