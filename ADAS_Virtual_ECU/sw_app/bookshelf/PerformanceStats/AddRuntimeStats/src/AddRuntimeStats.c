#include "AddRuntimeStats.h"
#include "string.h"
#include <ti/osal/TimerP.h>

#ifdef ADDRUNTIMESTATS

/*Need to Move this function to soc_utils.c once it is implemented on MCU1_0*/
#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_1)
static uint64_t GetGlobalTimeInUsec_mcu1_0(void)
{
	/*DD-ID:{342B31F3-BBBA-4210-BDCE-E119F63C50ED}*/
    return TimerP_getTimeInUsecs();
}
#endif

#if defined (BUILD_MCU2_1)
#include <ti/osal/TimerP.h>
#define  AddRuntimeStats_GETLOCALTIMESTAMP_PROVIDER   TimerP_getTimeInUsecs()
#elif defined (BUILD_MCU2_0)
#include <app_log.h>
#define  AddRuntimeStats_GETLOCALTIMESTAMP_PROVIDER   appLogGetGlobalTimeInUsec()
#elif defined (BUILD_MCU1_0)
#define AddRuntimeStats_GETLOCALTIMESTAMP_PROVIDER    GetGlobalTimeInUsec_mcu1_0()
#else
#define AddRuntimeStats_GETLOCALTIMESTAMP_PROVIDER   (0)
#endif

static AdditionalRuntimeStats_Log AddRuntimeStats_LogData;
static uint8_t AddRuntimeStats_bInitialized=FALSE;
static void AdditionalRuntimeStats_Initalize(void);

static void AdditionalRuntimeStats_Initalize(void)
{
	/*DD-ID:{99A4F2B6-A4B3-47f1-8E87-C15AE57163A6}*/
	(void)memset((void *)&AddRuntimeStats_LogData,0,sizeof(AdditionalRuntimeStats_Log));
	AddRuntimeStats_bInitialized=TRUE;
}


static void AdditionalRuntimeStats_Start_Generic(AdditionalRuntimeStats_LogType_Entity LogType, uint32_t RunEntityId)
{
	/*DD-ID:{BCFC0E48-B3A0-434f-86CC-73EA583D2D17}*/
	uint64_t PreviousRuntime;
	uint32_t MaxValue=0;
	static uint32_t AdditionalRuntimeStats_ResetCounter=0;
	volatile AddRuntimeStats_LogStructDef *DataPtr=NULL;

	if (AdditionalRuntimeStats_ResetCounter  < UINT32_MAX) {
			AdditionalRuntimeStats_ResetCounter = AdditionalRuntimeStats_ResetCounter +1u;
	} else {
		/* Do Nothing */
	}
	//Reset after the f
	if((AddRuntimeStats_bInitialized !=(uint8_t) TRUE) ||  (AdditionalRuntimeStats_ResetCounter ==(uint32_t)5000))
	{
		AdditionalRuntimeStats_Initalize();
	}

	switch(LogType)
	{
#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)
	case AdditionalRuntimeStats_LogType_Function:
	{
		MaxValue=AddRuntimeStats_Loggable_Entries_Max;
		DataPtr=&AddRuntimeStats_LogData.AddRuntimeStats_Stats_LogStruct_Entities[0];
	}
	break;
#endif
#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)
	case AdditionalRuntimeStats_LogType_AppTask:
	{
		MaxValue=en_Task_APP_MAX;
		DataPtr=&AddRuntimeStats_LogData.AddRuntimeStats_AppTask_Time[0];
	}
	break;
	case AdditionalRuntimeStats_LogType_BswTask:
	{
		MaxValue=en_Task_BSW_MAX;
		DataPtr=&AddRuntimeStats_LogData.AddRuntimeStats_BSWTask_Time[0];
	}
	break;
	#if defined(BUILD_MCU2_1)
	case AdditionalRuntimeStats_LogType_AppSafeTask:
	case AdditionalRuntimeStats_LogType_BswSafeTask:
	{
		MaxValue=en_Task_SAFETY_MAX;
		DataPtr=&AddRuntimeStats_LogData.AddRuntimeStats_SafeTask_Time[0];		

	}
	break;
	#endif
#endif
#if defined(BUILD_MCU1_0)
	case AdditionalRuntimeStats_LogType_Task:
	{
		MaxValue=(uint32_t)OS_TASKID_COUNT;
		DataPtr=&AddRuntimeStats_LogData.AddRuntimeStats_OsTask_Time[0];
	}
	break;
#endif
	default:
		if (AddRuntimeStats_LogData.InternalError.InvalidType < UINT32_MAX) {
			AddRuntimeStats_LogData.InternalError.InvalidType = AddRuntimeStats_LogData.InternalError.InvalidType +1u;
		} else {
			/* Do Nothing */
		}
		break;
	}

	if(RunEntityId<MaxValue)
	{
		if(DataPtr[RunEntityId].bMeasuementStarted ==(uint8_t)TRUE)
		{
			DataPtr[RunEntityId].ErrorInfo.MultipleInvocationErrorCount=DataPtr[RunEntityId].ErrorInfo.MultipleInvocationErrorCount + 1u; 
		}

		PreviousRuntime=DataPtr[RunEntityId].CurrentRuntTime;
		DataPtr[RunEntityId].CurrentRuntTime=AddRuntimeStats_GETLOCALTIMESTAMP_PROVIDER;

		//no coming ou of init
		if(PreviousRuntime != (uint64_t)0)
		{
			DataPtr[RunEntityId].bCurrentPeriodicity_ms=(uint32_t)((DataPtr[RunEntityId].CurrentRuntTime-PreviousRuntime)/1000u);
			if(DataPtr[RunEntityId].bCurrentPeriodicity_ms <(uint32_t)100)
			{
				DataPtr[RunEntityId].PeriodicityBucket_ms[DataPtr[RunEntityId].bCurrentPeriodicity_ms]= DataPtr[RunEntityId].PeriodicityBucket_ms[DataPtr[RunEntityId].bCurrentPeriodicity_ms] + 1u;
			}
			else
			{
				DataPtr[RunEntityId].PeriodicityBucket_ms[99]=DataPtr[RunEntityId].PeriodicityBucket_ms[99] + 1u;
			}
		}
		DataPtr[RunEntityId].bMeasuementStarted=TRUE;
	}
}

static void AdditionalRuntimeStats_Stop_Generic(AdditionalRuntimeStats_LogType_Entity LogType, uint32_t RunEntityId)
{
	/*DD-ID:{F56C72EE-76A1-4825-823F-149ADC7549A2}*/
	uint64_t CurrentTime=AddRuntimeStats_GETLOCALTIMESTAMP_PROVIDER;
	uint32_t MaxValue=0;
	volatile AddRuntimeStats_LogStructDef *DataPtr=NULL;

#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)
	/*Task Stat statBuf used*/
	volatile uint32 *StackUsedPtr=NULL;
	volatile float32 *StackUsedPercent=NULL;
#endif

	if(AddRuntimeStats_bInitialized != (uint8_t)TRUE)
	{
		AdditionalRuntimeStats_Initalize();
	}

	switch(LogType)
	{
#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)   
	case AdditionalRuntimeStats_LogType_Function:
	{
		MaxValue=AddRuntimeStats_Loggable_Entries_Max;
		DataPtr=&AddRuntimeStats_LogData.AddRuntimeStats_Stats_LogStruct_Entities[0];
	}
	break;
#endif
#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)            

	case AdditionalRuntimeStats_LogType_AppTask:
	{
		MaxValue=en_Task_APP_MAX;
		DataPtr=&AddRuntimeStats_LogData.AddRuntimeStats_AppTask_Time[0];
		StackUsedPtr=&AddRuntimeStats_LogData.AddRuntimeStats_AppTask_StackUsage[0];
		StackUsedPercent=&AddRuntimeStats_LogData.AddRuntimeStats_AppTask_StackUsage_PerCent[0];
	}
	break;
	case AdditionalRuntimeStats_LogType_BswTask:
	{
		MaxValue=en_Task_BSW_MAX;
		DataPtr=&AddRuntimeStats_LogData.AddRuntimeStats_BSWTask_Time[0];
		StackUsedPtr=&AddRuntimeStats_LogData.AddRuntimeStats_BSWTask_StackUsage[0];
		StackUsedPercent=&AddRuntimeStats_LogData.AddRuntimeStats_BSWTask_StackUsage_PerCent[0];
	}
	break;
	#if defined(BUILD_MCU2_1)
	case AdditionalRuntimeStats_LogType_AppSafeTask:
	case AdditionalRuntimeStats_LogType_BswSafeTask:
	{
		MaxValue=en_Task_SAFETY_MAX;
		DataPtr=&AddRuntimeStats_LogData.AddRuntimeStats_SafeTask_Time[0];
		StackUsedPtr=&AddRuntimeStats_LogData.AddRuntimeStats_SafeTask_StackUsage[0];
		StackUsedPercent=&AddRuntimeStats_LogData.AddRuntimeStats_SafeTask_StackUsage_PerCent[0];
	}
	break;
	#endif
#endif
#if defined(BUILD_MCU1_0) 
 	case AdditionalRuntimeStats_LogType_Task:
	{
		MaxValue=(uint32_t)OS_TASKID_COUNT;
		DataPtr=&AddRuntimeStats_LogData.AddRuntimeStats_OsTask_Time[0];
	}
	break;
#endif
	default:
		if ((AddRuntimeStats_LogData.InternalError.InvalidType) < UINT32_MAX) {
			AddRuntimeStats_LogData.InternalError.InvalidType = AddRuntimeStats_LogData.InternalError.InvalidType + 1u;
		} else {
			/* Do Nothing */
		}	
		break;
	}

	if(RunEntityId < MaxValue)
	{

#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1) 
		if((LogType == AdditionalRuntimeStats_LogType_AppTask) || (LogType == AdditionalRuntimeStats_LogType_BswTask))
		{ 
			/*DO nothing*/
		}
#endif

		if(DataPtr[RunEntityId].bMeasuementStarted != (uint8_t)TRUE)
		{
			DataPtr[RunEntityId].ErrorInfo.StopInvoationWithoutStart= DataPtr[RunEntityId].ErrorInfo.StopInvoationWithoutStart + 1u; 
		}
		else
		{
			DataPtr[RunEntityId].bAveragePeriodicity_ms=((DataPtr[RunEntityId].bAveragePeriodicity_ms*DataPtr[RunEntityId].InvocationCount)+DataPtr[RunEntityId].bCurrentPeriodicity_ms)/(DataPtr[RunEntityId].InvocationCount+1u);
			DataPtr[RunEntityId].InvocationCount= DataPtr[RunEntityId].InvocationCount + 1u;
			DataPtr[RunEntityId].LastInvocationTime_us =CurrentTime-DataPtr[RunEntityId].CurrentRuntTime;
			DataPtr[RunEntityId].TotalTimeSpend_ms += (DataPtr[RunEntityId].LastInvocationTime_us /1000.0f);
			if(DataPtr[RunEntityId].LastInvocationTime_us >= DataPtr[RunEntityId].MaximumTime_us)
			{
				DataPtr[RunEntityId].MaximumTime_us=DataPtr[RunEntityId].LastInvocationTime_us;
			}
			DataPtr[RunEntityId].AverageTime_ms= DataPtr[RunEntityId].TotalTimeSpend_ms/DataPtr[RunEntityId].InvocationCount;

		}
		DataPtr[RunEntityId].bMeasuementStarted=FALSE;
	}
}
#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)
void AdditionalRuntimeStats_Start_Function(AddRuntimeStats_LoggableEntries_Local RunEntityId)
{
	/*DD-ID:{7BE2CA41-A6EC-4399-8142-BE7F9EBF7356}*/
	AdditionalRuntimeStats_Start_Generic(AdditionalRuntimeStats_LogType_Function,(uint32_t)RunEntityId);
}

void AdditionalRuntimeStats_Stop_Function(AddRuntimeStats_LoggableEntries_Local RunEntityId)
{
	/*DD-ID:{E7593ABF-C813-426d-8C95-7814A2F60951}*/
	AdditionalRuntimeStats_Stop_Generic(AdditionalRuntimeStats_LogType_Function,(uint32_t)RunEntityId);
}
#endif

#if defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)

void AdditionalRuntimeStats_Start_AppTask(en_APP_Tasks_Def RunEntityId)
{
	/*DD-ID:{CB640AE2-4CBD-4bd3-8CD1-5A3F3E79BC3C}*/
	AdditionalRuntimeStats_Start_Generic(AdditionalRuntimeStats_LogType_AppTask,(uint32_t)RunEntityId);
}

void AdditionalRuntimeStats_Stop_AppTask(en_APP_Tasks_Def RunEntityId)
{
	/*DD-ID:{B2366C41-227B-4945-81D1-3FDA451A1224}*/
	AdditionalRuntimeStats_Stop_Generic(AdditionalRuntimeStats_LogType_AppTask,(uint32_t)RunEntityId);
}

void AdditionalRuntimeStats_Start_BswTask(en_BSW_Tasks_Def RunEntityId)
{
	/*DD-ID:{625FFA8B-F95D-47f8-A42C-F290E7201461}*/
	AdditionalRuntimeStats_Start_Generic(AdditionalRuntimeStats_LogType_BswTask,(uint32_t)RunEntityId);
}

void AdditionalRuntimeStats_Stop_BswTask(en_BSW_Tasks_Def RunEntityId)
{
	/*DD-ID:{1A0446A3-54CF-406c-8D48-3E5F68B13A05}*/
	AdditionalRuntimeStats_Stop_Generic(AdditionalRuntimeStats_LogType_BswTask,(uint32_t)RunEntityId);
}

#if defined (BUILD_MCU2_1)
void AdditionalRuntimeStats_Start_AppSafeTask(en_SAFETY_Tasks_Def RunEntityId)
{
	/*DD-ID:{4952EFFE-BA87-4a9f-97BE-E30506069B15}*/
	AdditionalRuntimeStats_Start_Generic(AdditionalRuntimeStats_LogType_AppSafeTask,(uint32_t)RunEntityId);
}

void AdditionalRuntimeStats_Stop_AppSafeTask(en_SAFETY_Tasks_Def RunEntityId)
{
	/*DD-ID:{EEDADE51-4709-4ca8-83CC-9FCEFB7EF882}*/
	AdditionalRuntimeStats_Stop_Generic(AdditionalRuntimeStats_LogType_AppSafeTask,(uint32_t)RunEntityId);
}

void AdditionalRuntimeStats_Start_BswSafeTask(en_SAFETY_Tasks_Def RunEntityId)
{
	/*DD-ID:{2D16336A-FDF3-47f8-93EB-6137F87AADA7}*/
	AdditionalRuntimeStats_Start_Generic(AdditionalRuntimeStats_LogType_BswSafeTask,(uint32_t)RunEntityId);
}

void AdditionalRuntimeStats_Stop_BswSafeTask(en_SAFETY_Tasks_Def RunEntityId)
{
	/*DD-ID:{DF9B89AA-E4C7-42d8-8030-AB2138CD7F89}*/
	AdditionalRuntimeStats_Stop_Generic(AdditionalRuntimeStats_LogType_BswSafeTask,(uint32_t)RunEntityId);
}
#endif

#endif

#if defined(BUILD_MCU1_0)
void AdditionalRuntimeStats_Start_Task(TaskType RunEntityId)
{
	/*DD-ID:{F0120196-9BC5-48e6-8CA8-BEC74F1D703F}*/
	AdditionalRuntimeStats_Start_Generic(AdditionalRuntimeStats_LogType_Task, (uint32_t)RunEntityId);
}

void AdditionalRuntimeStats_Stop_Task(TaskType RunEntityId)
{
	/*DD-ID:{4A80A0C7-ABAE-47f6-9A52-50A6453A4D1B}*/
	AdditionalRuntimeStats_Stop_Generic(AdditionalRuntimeStats_LogType_Task, (uint32_t)RunEntityId);
}
#endif

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU2_0) || defined (BUILD_MCU2_1)
AdditionalRuntimeStats_Log* AdditionalRuntimeStats_GetData(void)
{
	/*DD-ID:{F608ADA9-FCC3-4dbd-875B-356A3873CF84}*/
	return (AdditionalRuntimeStats_Log *)&AddRuntimeStats_LogData;
}
#endif

#endif
