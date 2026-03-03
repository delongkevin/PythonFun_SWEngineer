#include "PlatformDataTypes.h"
#include "RunTimeStats.h"
#include "AddRuntimeStats.h"
#include "SignalDef.h"
#include "string.h"
#define D_HUNDRED_MS 10u
#define D_THOUSAND_MS 100u
#define OS_STACK_FILL_PATTERN  0x00000000uL

#ifdef ADDRUNTIMESTATS
#if defined (BUILD_MCU2_1) || defined (BUILD_MCU2_0)
volatile StackUsage_Task TaskStackData[s_TASK_MAX] =
 {
	#if defined (BUILD_MCU2_1)
	{s_Task_APP_B_10msec,    		0x00000000,	0x00000000,0U},
	{s_TasK_APP_QM_10msec,     		0x00000000,	0x00000000,0U},
	{s_Task_SAFETY_APP_50msec, 		0x00000000,	0x00000000,0U},
	{s_TasK_SAFETY_BSW_10msec, 		0x00000000,	0x00000000,0U},
	{s_Task_BSW_B_Idle,	        	0x00000000,	0x00000000,0U},
	{s_Task_BSW_B_1msec,     		0x00000000,	0x00000000,0U},
	{s_Task_BSW_B_10msec,      		0x00000000,	0x00000000,0U},
	{s_TasK_BSW_QM_10msec,   		0x00000000,	0x00000000,0U},
	{s_TasK_BSW_QM1_10msec,  		0x00000000,	0x00000000,0U},
	{s_Task_en_TasK_BSW_QM_HighPriority_OnEvent, 			0x00000000,	0x00000000,0U},
	#endif
	#if defined (BUILD_MCU2_0)
	{s_Task_APP_B_10msec,   		0x00000000,	0x00000000,0U},
	{s_TasK_APP_QM_10msec,    		0x00000000,	0x00000000,0U},
	{s_Task_APP_B_30msec,   		0x00000000,	0x00000000,0U},
	{s_Task_BSW_B_10msec, 			0x00000000,	0x00000000,0U},
	{s_TasK_BSW_QM_10msec,			0x00000000,	0x00000000,0U},
	{s_TasK_BSW_QM1_10msec,     	0x00000000,	0x00000000,0U},
	{s_Task_en_TasK_BSW_QM_HighPriority_OnEvent, 0x00000000,	0x00000000,0U},
	{s_TasK_BSW_QM_TI_100msec,   	0x00000000,	0x00000000,0U},
	#endif
 };

void RunTimeStatsData_SendData(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PpRunTimeStatCSData_GetData
 *********************************************************************************************************************/
/*DD-ID:{D0C6F21D-ECC6-409c-B7DD-3E0722C7D71F}*/
	const AdditionalRuntimeStats_Log* runTimeStatDataPtr = AdditionalRuntimeStats_GetData();
	#if defined (BUILD_MCU2_1)
    RunTimeStats_MCU2_1_t RunTimeStats_MCU2_1_local;
	#endif
	#if defined(BUILD_MCU2_0)
	RunTimeStats_MCU2_0_t RunTimeStats_MCU2_0_local;
	#endif
    static uint8 counter_100ms = 0u;
	PerformanceStatsEnable_t PerformanceEnableFlag;

	if(counter_100ms >= D_HUNDRED_MS) /* function call at every 100ms*/
	{
		SigMgr_Data_PerformanceStatsEnable_t_Get(&PerformanceEnableFlag);
		counter_100ms = 0u;
		if((uint32)TRUE == PerformanceEnableFlag.RunTimeStatsEnable)
		{
			#if defined (BUILD_MCU2_1)
			RunTimeStats_MCU2_1_local.en_Task_BSWTaskTime[0] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[0].bAveragePeriodicity_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_BSWTaskTime[1] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[0].AverageTime_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_BSWTaskTime[2] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[1].bAveragePeriodicity_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_BSWTaskTime[3] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[1].AverageTime_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_BSWTaskTime[4] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[2].bAveragePeriodicity_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_BSWTaskTime[5] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[2].AverageTime_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_BSWTaskTime[6] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[3].bAveragePeriodicity_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_BSWTaskTime[7] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[3].AverageTime_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_BSWTaskTime[8] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[4].bAveragePeriodicity_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_BSWTaskTime[9] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[4].AverageTime_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_BSWTaskTime[10] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[5].bAveragePeriodicity_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_BSWTaskTime[11] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[5].AverageTime_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_BSWTaskTime[12] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[6].bAveragePeriodicity_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_BSWTaskTime[13] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[6].AverageTime_ms * 1000.0f);

			RunTimeStats_MCU2_1_local.en_Task_APPTaskTime[0] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_AppTask_Time[0].bAveragePeriodicity_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_APPTaskTime[1] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_AppTask_Time[0].AverageTime_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_APPTaskTime[2] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_AppTask_Time[1].bAveragePeriodicity_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_APPTaskTime[3] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_AppTask_Time[1].AverageTime_ms * 1000.0f);

			RunTimeStats_MCU2_1_local.en_Task_SAFETYTaskTime[0] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_SafeTask_Time[0].bAveragePeriodicity_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_SAFETYTaskTime[1] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_SafeTask_Time[0].AverageTime_ms * 1000.0f);			
			RunTimeStats_MCU2_1_local.en_Task_SAFETYTaskTime[2] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_SafeTask_Time[1].bAveragePeriodicity_ms * 1000.0f);
			RunTimeStats_MCU2_1_local.en_Task_SAFETYTaskTime[3] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_SafeTask_Time[1].AverageTime_ms * 1000.0f);	
			#endif

			#if defined(BUILD_MCU2_0)
			RunTimeStats_MCU2_0_local.en_Task_BSWTaskTime[0] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[0].bAveragePeriodicity_ms * 100.0f);
			RunTimeStats_MCU2_0_local.en_Task_BSWTaskTime[1] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[0].AverageTime_ms * 100.0f);
			RunTimeStats_MCU2_0_local.en_Task_BSWTaskTime[2] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[1].bAveragePeriodicity_ms * 100.0f);
			RunTimeStats_MCU2_0_local.en_Task_BSWTaskTime[3] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[1].AverageTime_ms * 100.0f);
			RunTimeStats_MCU2_0_local.en_Task_BSWTaskTime[4] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[2].bAveragePeriodicity_ms * 100.0f);
			RunTimeStats_MCU2_0_local.en_Task_BSWTaskTime[5] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[2].AverageTime_ms * 100.0f);
			RunTimeStats_MCU2_0_local.en_Task_BSWTaskTime[6] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[3].bAveragePeriodicity_ms * 100.0f);
			RunTimeStats_MCU2_0_local.en_Task_BSWTaskTime[7] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[3].AverageTime_ms * 100.0f);
			RunTimeStats_MCU2_0_local.en_Task_BSWTaskTime[8] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[4].bAveragePeriodicity_ms * 100.0f);
			RunTimeStats_MCU2_0_local.en_Task_BSWTaskTime[9] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_BSWTask_Time[4].AverageTime_ms * 100.0f);
			
			RunTimeStats_MCU2_0_local.en_Task_APPTaskTime[0] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_AppTask_Time[0].bAveragePeriodicity_ms * 100.0f);
			RunTimeStats_MCU2_0_local.en_Task_APPTaskTime[1] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_AppTask_Time[0].AverageTime_ms * 100.0f);
			RunTimeStats_MCU2_0_local.en_Task_APPTaskTime[2] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_AppTask_Time[1].bAveragePeriodicity_ms * 100.0f);
			RunTimeStats_MCU2_0_local.en_Task_APPTaskTime[3] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_AppTask_Time[1].AverageTime_ms * 100.0f);
			RunTimeStats_MCU2_0_local.en_Task_APPTaskTime[4] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_AppTask_Time[2].bAveragePeriodicity_ms * 100.0f);
			RunTimeStats_MCU2_0_local.en_Task_APPTaskTime[5] = (uint32)(runTimeStatDataPtr->AddRuntimeStats_AppTask_Time[2].AverageTime_ms * 100.0f);
			#endif
		}
		else
		{
			#if defined(BUILD_MCU2_1)
			(void)memset(&RunTimeStats_MCU2_1_local, 0, (sizeof(RunTimeStats_MCU2_1_local)));
			#endif

			#if defined(BUILD_MCU2_0)
			(void)memset(&RunTimeStats_MCU2_0_local, 0, (sizeof(RunTimeStats_MCU2_0_local)));
			#endif
		}
		#if defined(BUILD_MCU2_1)
		(void)SigMgr_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t_Put(&RunTimeStats_MCU2_1_local);
		#endif

		#if defined(BUILD_MCU2_0)
		(void)SigMgr_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t_Put(&RunTimeStats_MCU2_0_local);
		#endif

	}
	else
	{
		counter_100ms = counter_100ms + 1u;
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

void AddRuntimeStats_StackUsage(void)
{
 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PpRunTimeStatCSData_GetData
 *********************************************************************************************************************/
  /*DD-ID:{1226FDAF-7364-4bbd-8B97-F76EE757D104}*/
  static uint8 cntr_100ms = 0u;
  static uint8 Idx;
  #if defined (BUILD_MCU2_1)
  StackUsage_MCU2_1_t StackUsage_MCU2_1_local;
  #endif
  #if defined (BUILD_MCU2_0)
  StackUsage_MCU2_0_t StackUsage_MCU2_0_local;
  #endif
  float32 StackUsage[s_TASK_MAX];
  uint32 const* EndAddress;
  uint32 const* StartAddress;
  float32 StackUsageInPerc[s_TASK_MAX];
  uint32 StackSize;
  PerformanceStatsEnable_t PerformanceEnableFlag; 

	if(cntr_100ms >= D_THOUSAND_MS) /* function call at every 1s*/
	{
		cntr_100ms = 0u;
		SigMgr_Data_PerformanceStatsEnable_t_Get(&PerformanceEnableFlag);
		if((uint32)TRUE == PerformanceEnableFlag.StackUsageStatsEnable)
		{
			/*Calculate the stack usage of all task base on the iterator. */
			for(Idx=(uint8)0u;Idx<(uint8)s_TASK_MAX;Idx++)
			{
				EndAddress = (uint32*)TaskStackData[Idx].Task_HighAdd;
				StartAddress = (uint32*)TaskStackData[Idx].Task_LowAdd;  
				StackSize = TaskStackData[Idx].Task_Size;
				while(EndAddress != StartAddress)                                                                                        /* FETA_OS_ITERATEOVERSTACK */
				{
					if(*StartAddress == OS_STACK_FILL_PATTERN)
					{
						/* #30 Move the iterator one stack entry down. */
						StartAddress = StartAddress + 0x00000001u;
					}
					else
					{
						break;
					} 
				}
				/*Return (Bottom-Top)*SizeOf(Element). */
				StackUsage[Idx] = (((uint32)EndAddress - (uint32)StartAddress) * 100.0f);
				StackUsageInPerc[Idx] = (StackUsage[Idx] / StackSize) ;
			}
		
			#if defined (BUILD_MCU2_1)
			StackUsage_MCU2_1_local.en_Task_APPTaskTime[0] = (uint8)StackUsageInPerc[s_Task_APP_B_10msec];
			StackUsage_MCU2_1_local.en_Task_APPTaskTime[1] = (uint8)StackUsageInPerc[s_TasK_APP_QM_10msec];
			StackUsage_MCU2_1_local.en_Task_SAFETYTaskTime[0] = (uint8)StackUsageInPerc[s_Task_SAFETY_APP_50msec];
			StackUsage_MCU2_1_local.en_Task_SAFETYTaskTime[1] = (uint8)StackUsageInPerc[s_TasK_SAFETY_BSW_10msec];
			StackUsage_MCU2_1_local.en_Task_BSWTaskTime[0] = (uint8)StackUsageInPerc[s_Task_BSW_B_Idle];
			StackUsage_MCU2_1_local.en_Task_BSWTaskTime[1] = (uint8)StackUsageInPerc[s_Task_BSW_B_1msec];
			StackUsage_MCU2_1_local.en_Task_BSWTaskTime[2] = (uint8)StackUsageInPerc[s_Task_BSW_B_10msec];
			StackUsage_MCU2_1_local.en_Task_BSWTaskTime[3] = (uint8)StackUsageInPerc[s_TasK_BSW_QM_10msec];
			StackUsage_MCU2_1_local.en_Task_BSWTaskTime[4] = (uint8)StackUsageInPerc[s_TasK_BSW_QM1_10msec];
			StackUsage_MCU2_1_local.en_Task_BSWTaskTime[5] = (uint8)StackUsageInPerc[s_Task_en_TasK_BSW_QM_HighPriority_OnEvent];
			#endif
			#if defined (BUILD_MCU2_0)
			StackUsage_MCU2_0_local.en_Task_APPTaskTime[0] = (uint8)StackUsageInPerc[s_Task_APP_B_10msec];
			StackUsage_MCU2_0_local.en_Task_APPTaskTime[1] = (uint8)StackUsageInPerc[s_TasK_APP_QM_10msec];
			StackUsage_MCU2_0_local.en_Task_APPTaskTime[2] = (uint8)StackUsageInPerc[s_Task_APP_B_30msec];
			StackUsage_MCU2_0_local.en_Task_BSWTaskTime[0] = (uint8)StackUsageInPerc[s_Task_BSW_B_10msec];
			StackUsage_MCU2_0_local.en_Task_BSWTaskTime[1] = (uint8)StackUsageInPerc[s_TasK_BSW_QM_10msec];
			StackUsage_MCU2_0_local.en_Task_BSWTaskTime[2] = (uint8)StackUsageInPerc[s_TasK_BSW_QM1_10msec];
			StackUsage_MCU2_0_local.en_Task_BSWTaskTime[3] = (uint8)StackUsageInPerc[s_Task_en_TasK_BSW_QM_HighPriority_OnEvent];
			StackUsage_MCU2_0_local.en_Task_BSWTaskTime[4] = (uint8)StackUsageInPerc[s_TasK_BSW_QM_TI_100msec];
			#endif
		}
		else
		{
			#if defined(BUILD_MCU2_1)
			(void)memset(&StackUsage_MCU2_1_local, 0, (sizeof(StackUsage_MCU2_1_local)));
			#endif

			#if defined(BUILD_MCU2_0)
			(void)memset(&StackUsage_MCU2_0_local, 0, (sizeof(StackUsage_MCU2_0_local)));
			#endif
		}
			#if defined(BUILD_MCU2_1)
			(void)SigMgr_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t_Put(&StackUsage_MCU2_1_local);
			#endif

			#if defined(BUILD_MCU2_0)
			(void)SigMgr_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t_Put(&StackUsage_MCU2_0_local);
			#endif
	}
	else
	{
		cntr_100ms = cntr_100ms + 1u;
	}
	/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

void RunTimeStats_BSW_Start_Task(en_BSW_Tasks_Def taskId)
{
	/*DD-ID:{0FBB23E9-B762-434f-827D-C7239E4741DE}*/
	PerformanceStatsEnable_t PerformanceEnableFlag;;
	SigMgr_Data_PerformanceStatsEnable_t_Get(&PerformanceEnableFlag);
	if((uint32)TRUE == PerformanceEnableFlag.RunTimeStatsEnable)
	{
		AdditionalRuntimeStats_Start_BswTask(taskId);
	}
}

void RunTimeStats_BSW_Stop_Task(en_BSW_Tasks_Def taskId)
{
	/*DD-ID:{BF1A0455-DF24-4e76-8C5F-60897DCA6D57}*/
	PerformanceStatsEnable_t PerformanceEnableFlag;;
	SigMgr_Data_PerformanceStatsEnable_t_Get(&PerformanceEnableFlag);
	if((uint32)TRUE == PerformanceEnableFlag.RunTimeStatsEnable)
	{
		AdditionalRuntimeStats_Stop_BswTask(taskId);
	}
}
void RunTimeStats_APP_Start_Task(en_APP_Tasks_Def taskId)
{
	/*DD-ID:{F384088C-22A9-42c6-8D91-541244C26DF3}*/
	PerformanceStatsEnable_t PerformanceEnableFlag;;
	SigMgr_Data_PerformanceStatsEnable_t_Get(&PerformanceEnableFlag);
	if((uint32)TRUE == PerformanceEnableFlag.RunTimeStatsEnable)
	{
		AdditionalRuntimeStats_Start_AppTask(taskId);
	}
}

void RunTimeStats_APP_Stop_Task(en_APP_Tasks_Def taskId)
{
	/*DD-ID:{C6F8D3D8-DDD2-472a-BEDF-17D1CE6E470D}*/
	PerformanceStatsEnable_t PerformanceEnableFlag;;
	SigMgr_Data_PerformanceStatsEnable_t_Get(&PerformanceEnableFlag);
	if((uint32)TRUE == PerformanceEnableFlag.RunTimeStatsEnable)
	{
		AdditionalRuntimeStats_Stop_AppTask(taskId);
	}
}
#endif
#if defined (BUILD_MCU2_1) 
void RunTimeStats_AppSafety_Start_Task(en_SAFETY_Tasks_Def taskId)
{
	/*DD-ID:{ACF9C048-8454-4700-A456-181F5A11EEDC}*/
	PerformanceStatsEnable_t PerformanceEnableFlag;;
	SigMgr_Data_PerformanceStatsEnable_t_Get(&PerformanceEnableFlag);
	if((uint32)TRUE == PerformanceEnableFlag.RunTimeStatsEnable)
	{
		AdditionalRuntimeStats_Start_AppSafeTask(taskId);
	}
}

void RunTimeStats_AppSafety_Stop_Task(en_SAFETY_Tasks_Def taskId)
{
	/*DD-ID:{FE01B523-3B4C-40fe-8635-4A083702A163}*/
	PerformanceStatsEnable_t PerformanceEnableFlag;;
	SigMgr_Data_PerformanceStatsEnable_t_Get(&PerformanceEnableFlag);
	if((uint32)TRUE == PerformanceEnableFlag.RunTimeStatsEnable)
	{
		AdditionalRuntimeStats_Stop_AppSafeTask(taskId);
	}
}
void RunTimeStats_BswSafety_Start_Task(en_SAFETY_Tasks_Def taskId)
{
	/*DD-ID:{73766059-E8B8-4849-BCBA-D4F0A566FC9A}*/
	PerformanceStatsEnable_t PerformanceEnableFlag;;
	SigMgr_Data_PerformanceStatsEnable_t_Get(&PerformanceEnableFlag);
	if((uint32)TRUE == PerformanceEnableFlag.RunTimeStatsEnable)
	{
		AdditionalRuntimeStats_Start_BswSafeTask(taskId);
	}
}

void RunTimeStats_BswSafety_Stop_Task(en_SAFETY_Tasks_Def taskId)
{
	/*DD-ID:{A60F6041-646A-44fb-ADEA-079A7E051D93}*/
	PerformanceStatsEnable_t PerformanceEnableFlag;;
	SigMgr_Data_PerformanceStatsEnable_t_Get(&PerformanceEnableFlag);
	if((uint32)TRUE == PerformanceEnableFlag.RunTimeStatsEnable)
	{ 
		AdditionalRuntimeStats_Stop_BswSafeTask(taskId);
	}
}
#endif
#endif

