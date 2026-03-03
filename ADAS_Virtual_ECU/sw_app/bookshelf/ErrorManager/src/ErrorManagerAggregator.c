#include "ErrorManagerTypes.h"
#include "ErrorManagerAggregator.h"
#include "ErrorManagerAggregatorDef.h"
#include "ErrorManagerAggregatorApp.h"
#include <string.h>
#include <assert.h>

 
#include "ErrorManager_Common_Memmap.h"


#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE 


#ifdef __cplusplus
extern "C" {
#endif

static void ErrorMgrAggregator_PeriodicFunction(ErrorMgr_AsilList AsilLevel);
static void ErrorMgrAggregator_Init(ErrorMgr_AsilList AsilLevel);


static const ErrorManagerAggregator_RuntimeDefs* ErrorMgrAgg_RamDefs[ErrorMgr_Asil_MAX] = {
#if ERRMANAGER_QM_LEVEL_ACTIVE == 1u
	&ErrorMgrAgg_RamDef_QM,
#endif
#if ERRMANAGER_A_LEVEL_ACTIVE == 1u
	&ErrorMgrAgg_RamDef_A,
#endif
#if ERRMANAGER_B_LEVEL_ACTIVE == 1u
	&ErrorMgrAgg_RamDef_B,
#endif
#if ERRMANAGER_C_LEVEL_ACTIVE == 1u
	&ErrorMgrAgg_RamDef_C,
#endif
#if ERRMANAGER_D_LEVEL_ACTIVE == 1u
	&ErrorMgrAgg_RamDef_D,
#endif
};


static void ErrorMgrAggregator_Init(ErrorMgr_AsilList AsilLevel)
{
  /* DD-ID: {E733D963-6132-4ca5-A5E2-5304B337B38D}*/
	ErrorMgrAggregatorApp_Init(AsilLevel);

}


#if ERRMANAGER_QM_LEVEL_ACTIVE == 1u
void ErrorMgrAggregator_Init_QM(void)
{
   /* DD-ID :{7EA977DA-58B4-4481-A77B-E5C5364A7CB6}*/
	ErrorMgrAggregator_Init(ErrorMgr_Asil_QM);
	ErrorMgrAggregator_Callback_Clear_QM();

}
#endif


#if ERRMANAGER_A_LEVEL_ACTIVE == 1u
void ErrorMgrAggregator_Init_A(void)
{
  /* DD-ID :{7B8575C4-2868-431b-9396-EF69A41E22FD}*/
	ErrorMgrAggregator_Init(ErrorMgr_Asil_A);
	ErrorMgrAggregator_Callback_Clear_A();

}
#endif


#if ERRMANAGER_B_LEVEL_ACTIVE == 1u
void ErrorMgrAggregator_Init_B(void)
{
  /* DD-ID: {E733D963-6132-4ca5-A5E2-5304B337B38D}*/
  /* DD-ID :{DDB18725-671B-40e5-BE45-32484945EFAA}*/
	ErrorMgrAggregator_Init(ErrorMgr_Asil_B);
	ErrorMgrAggregator_Callback_Clear_B();

}
#endif


#if ERRMANAGER_C_LEVEL_ACTIVE == 1u
void ErrorMgrAggregator_Init_C(void)
{
  /* DD-ID: {E733D963-6132-4ca5-A5E2-5304B337B38D}*/
	ErrorMgrAggregator_Init(ErrorMgr_Asil_C);
	ErrorMgrAggregator_Callback_Clear_C();

}
#endif


#if ERRMANAGER_D_LEVEL_ACTIVE == 1u
void ErrorMgrAggregator_Init_D(void)
{
  /* DD-ID: {E733D963-6132-4ca5-A5E2-5304B337B38D}*/
	ErrorMgrAggregator_Init(ErrorMgr_Asil_D);
	ErrorMgrAggregator_Callback_Clear_D();

}
#endif



/* DD-ID: {AF8722C2-5977-434c-9B69-7F1873F9E573}*/
/* 
ErrorMgrAggregator_DeInit()
Commented out. Kept for future use.
{
	ErrorMgrAggregatorApp_DeInit()
}
*/

#if ERRMANAGER_QM_LEVEL_ACTIVE == 1u
void ErrorMgrAggregator_QM_PeriodicFunction(void)
{
  /* DD-ID: {4CFE69BC-E88E-454a-A3C8-6E9E358BB90E}*/
  /* DD-ID :{DE1CB180-E257-4d8c-AB31-5485D1D09546}*/
	ErrorMgrAggregator_PeriodicFunction(ErrorMgr_Asil_QM);
}
#endif


#if ERRMANAGER_B_LEVEL_ACTIVE == 1u
void ErrorMgrAggregator_B_PeriodicFunction(void)
{
  /* DD-ID: {4CFE69BC-E88E-454a-A3C8-6E9E358BB90E}*/
  /* DD-ID :{7D360FB4-2A05-4aef-93EB-F0D0C4B3458E}*/
	ErrorMgrAggregator_PeriodicFunction(ErrorMgr_Asil_B);

}
#endif

#if ERRMANAGER_D_LEVEL_ACTIVE == 1u
void ErrorMgrAggregator_PeriodicFunction_D(void)
{
  /* DD-ID: {4CFE69BC-E88E-454a-A3C8-6E9E358BB90E}*/
	ErrorMgrAggregator_PeriodicFunction(ErrorMgr_Asil_D);
}
#endif


#if ERRMANAGER_QM_LEVEL_ACTIVE == 1u
	#define D_ldef_QM_ErrorMgr_ErrorNum_Max ldef_QM_ErrorMgr_ErrorNum_Max
#else
	#define D_ldef_QM_ErrorMgr_ErrorNum_Max 0u
#endif

#if ERRMANAGER_A_LEVEL_ACTIVE == 1u
	#define D_ldef_A_ErrorMgr_ErrorNum_Max ldef_A_ErrorMgr_ErrorNum_Max
#else
	#define D_ldef_A_ErrorMgr_ErrorNum_Max 0u
#endif


#if ERRMANAGER_B_LEVEL_ACTIVE == 1u
	#define D_ldef_B_ErrorMgr_ErrorNum_Max ldef_B_ErrorMgr_ErrorNum_Max
#else
	#define D_ldef_B_ErrorMgr_ErrorNum_Max 0u
#endif


#if ERRMANAGER_C_LEVEL_ACTIVE == 1u
	#define D_ldef_C_ErrorMgr_ErrorNum_Max ldef_C_ErrorMgr_ErrorNum_Max
#else
	#define D_ldef_C_ErrorMgr_ErrorNum_Max 0u
#endif

#if ERRMANAGER_D_LEVEL_ACTIVE == 1u
	#define D_ldef_D_ErrorMgr_ErrorNum_Max ldef_D_ErrorMgr_ErrorNum_Max
#else
	#define D_ldef_D_ErrorMgr_ErrorNum_Max 0u
#endif



#define ErrorMgrAgg_asil_ConsolidatedOutput_Size (uint16_t)(ErrorMgr_MaxOf2Vals((uint16_t)D_ldef_QM_ErrorMgr_ErrorNum_Max,(uint16_t)D_ldef_B_ErrorMgr_ErrorNum_Max))
#define ErrorMgrAgg_asil_PackedAsBits_ConsolidatedOutput_Size (uint16_t)((ErrorMgrAgg_asil_ConsolidatedOutput_Size/32)+1)
		

#if ERRMANAGER_QM_LEVEL_ACTIVE == 1u
static_assert((ErrorMgrAgg_asil_ConsolidatedOutput_Size >= (uint16_t)ldef_QM_ErrorMgr_ErrorNum_Max),"Possible MisCalculation of ErrorMgrAgg_asil_ConsolidatedOutput_Size");
#endif
#if ERRMANAGER_A_LEVEL_ACTIVE == 1u
static_assert((ErrorMgrAgg_asil_ConsolidatedOutput_Size >= (uint16_t)ldef_A_ErrorMgr_ErrorNum_Max), "Possible MisCalculation of ErrorMgrAgg_asil_ConsolidatedOutput_Size");
#endif
#if ERRMANAGER_B_LEVEL_ACTIVE == 1u
static_assert((ErrorMgrAgg_asil_ConsolidatedOutput_Size >= (uint16_t)ldef_B_ErrorMgr_ErrorNum_Max), "Possible MisCalculation of ErrorMgrAgg_asil_ConsolidatedOutput_Size");
#endif
#if ERRMANAGER_C_LEVEL_ACTIVE == 1u
static_assert((ErrorMgrAgg_asil_ConsolidatedOutput_Size >= (uint16_t)ldef_C_ErrorMgr_ErrorNum_Max), "Possible MisCalculation of ErrorMgrAgg_asil_ConsolidatedOutput_Size");
#endif
#if ERRMANAGER_D_LEVEL_ACTIVE == 1u
static_assert((ErrorMgrAgg_asil_ConsolidatedOutput_Size >= (uint16_t)ldef_D_ErrorMgr_ErrorNum_Max), "Possible MisCalculation of ErrorMgrAgg_asil_ConsolidatedOutput_Size");
#endif



static const ErrorMgrAggregator_SatelliteMonitorConf* ErrorMgrAggregator_getConf(ErrorMgr_AsilList AsilLevel)
{
  /* DD-ID: {0BD616A4-171A-409b-9C2E-185783D727A4}*/
	const ErrorMgrAggregator_SatelliteMonitorConf* Conf = NULL;

	switch (AsilLevel)
	{
		#if ERRMANAGER_QM_LEVEL_ACTIVE == 1u
		case ErrorMgr_Asil_QM:
			Conf = ErrorMgrAggregator_GetMonitorConf_QM();
		break;
		#endif

		#if ERRMANAGER_A_LEVEL_ACTIVE == 1u
		case ErrorMgr_Asil_A:
			Conf = ErrorMgrAggregator_GetMonitorConf_A();
		break;
		#endif

		#if ERRMANAGER_B_LEVEL_ACTIVE == 1u
		case ErrorMgr_Asil_B:
			Conf = ErrorMgrAggregator_GetMonitorConf_B();
		break;
		#endif

		#if ERRMANAGER_C_LEVEL_ACTIVE == 1u
		case ErrorMgr_Asil_C:
			Conf = ErrorMgrAggregator_GetMonitorConf_C();
		break;
		#endif

		#if ERRMANAGER_D_LEVEL_ACTIVE == 1u
		case ErrorMgr_Asil_D:
			Conf = ErrorMgrAggregator_GetMonitorConf_D();
		break;
		#endif

		default:
			Conf=NULL;
			break;

		}


	return Conf;
} 





static void ErrorMgrAggregator_PeriodicFunction(ErrorMgr_AsilList AsilLevel)
{
	/* DD-ID: {4CFE69BC-E88E-454a-A3C8-6E9E358BB90E}*/
    #if ERRORMGR_CURRENTCORE == ERRORMGRCORE_MCU1_0
    static uint16_t SafeState2_RstRsn_flag = 0U;
    #endif
	const ErrorMgrAggregator_SatelliteMonitorConf* Conf = NULL;
	uint16_t Core ,i;
	uint32_t diff;
	bool_t bError = FALSE;
	const ErrorMgr_ErrorDescExt* ErrDescExt;
	const ErrorMgr_ErrorDesc *ErrDesc;
	uint16_t count, j;
	uint32_t sCount;
	ErrorMgrAggregator_Callback_HandleError Callback = NULL;
	uint32_t ErrorMgrAgg_asil_ConsolidatedOutput[ErrorMgrAgg_asil_PackedAsBits_ConsolidatedOutput_Size];

	static const uint32_t ErrorMgrAgg_asil_MaxErrorValues[ErrorMgr_Asil_MAX] =
	{
	  /* DD-ID: {35564AAF-D67A-4c15-9AFA-CE56BD3F4929}*/
		#if ERRMANAGER_QM_LEVEL_ACTIVE == 1u
			(uint32_t)D_ldef_QM_ErrorMgr_ErrorNum_Max,
		#endif
		#if ERRMANAGER_A_LEVEL_ACTIVE == 1u
			(uint32_t)D_ldef_A_ErrorMgr_ErrorNum_Max,
		#endif
		#if ERRMANAGER_B_LEVEL_ACTIVE == 1u
			(uint32_t)D_ldef_B_ErrorMgr_ErrorNum_Max,
		#endif
		#if ERRMANAGER_C_LEVEL_ACTIVE == 1u
			(uint32_t)D_ldef_C_ErrorMgr_ErrorNum_Max,
		#endif
		#if ERRMANAGER_D_LEVEL_ACTIVE == 1u
			(uint32_t)D_ldef_D_ErrorMgr_ErrorNum_Max
		#endif
	};

	uint32_t PackedOuputSize=(uint32_t)ERRMANAGER_GETPACKEDSIZE(ErrorMgrAgg_asil_MaxErrorValues[AsilLevel]);/* PRQA 3384 *//* No Functional impact. Fixed enum values incremented by 1. */

	const uint8_t ErrorMgrAgg_RunDivisor[ErrorMgr_Asil_MAX] ={
		#if ERRMANAGER_QM_LEVEL_ACTIVE == 1u
			ERRORMGR_AGGREGATORMONITOR_TASKPERIOD_ASIL_QM_MS/AUTOSAR_AGGREGATOR_TASKPERIOD_ASIL_QM_MS,
		#endif
		#if ERRMANAGER_A_LEVEL_ACTIVE == 1u
			ERRORMGR_AGGREGATORMONITOR_TASKPERIOD_ASIL_A_MS/AUTOSAR_AGGREGATOR_TASKPERIOD_ASIL_A_MS,
		#endif
		#if ERRMANAGER_B_LEVEL_ACTIVE == 1u
			ERRORMGR_AGGREGATORMONITOR_TASKPERIOD_ASIL_B_MS/AUTOSAR_AGGREGATOR_TASKPERIOD_ASIL_B_MS,
		#endif
		#if ERRMANAGER_C_LEVEL_ACTIVE == 1u
			ERRORMGR_AGGREGATORMONITOR_TASKPERIOD_ASIL_C_MS/AUTOSAR_AGGREGATOR_TASKPERIOD_ASIL_C_MS,
		#endif
		#if ERRMANAGER_D_LEVEL_ACTIVE == 1u
			ERRORMGR_AGGREGATORMONITOR_TASKPERIOD_ASIL_D_MS/AUTOSAR_AGGREGATOR_TASKPERIOD_ASIL_D_MS,
		#endif

	};

	ErrorMgr_ErrorMapping const *errMap;
	ErrorManagerAggregator_RuntimeDefs *RuntimeDefs;
	bool_t SafeStateDef[ldef_ErrorMgr_SafeState_Max];
	static uint32_t Agg_ExeuteCount[ErrorMgr_Asil_MAX]= {0};

	#ifdef ERROR_MANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION
		uint32_t *u32DebugCountPtr=NULL;
	#endif

	#ifdef ERROR_MANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION
		if(AsilLevel == ErrorMgr_Asil_B)
		{
			u32DebugCountPtr=(uint32_t *)ErrorMgrAgg_GetDebug_ErrCount_B();
		}
		else if(AsilLevel == ErrorMgr_Asil_QM)
		{
			u32DebugCountPtr=(uint32_t *)ErrorMgrAgg_GetDebug_ErrCount_QM();
		}
		else
		{
			/* Do Nothing */
		}
	#endif

	/*since the ErrorMgrAgg_asil_ConsolidatedOutput is the biggest of all err counts.just clear the entries that doesn't get assigned in the end*/

	Agg_ExeuteCount[AsilLevel]+=(uint32_t)1; /* PRQA 3383 *//* No functional impact. Used to execute code separately for QM and B. Reset to 0 after entering in following 'if' condition. */

	if(Agg_ExeuteCount[AsilLevel] >= ErrorMgrAgg_RunDivisor[AsilLevel])
	{
		Agg_ExeuteCount[AsilLevel]=(uint32_t)0;


		(void)memset(SafeStateDef,FALSE,sizeof(SafeStateDef));
		(void)memset((void *)&ErrorMgrAgg_asil_ConsolidatedOutput[0],0,sizeof(ErrorMgrAgg_asil_ConsolidatedOutput));

		ErrorMgrAggregatorApp_ReadInputs(AsilLevel);

		RuntimeDefs=(ErrorManagerAggregator_RuntimeDefs *)ErrorMgrAgg_RamDefs[AsilLevel];
		
		Conf=ErrorMgrAggregator_getConf(AsilLevel);


		if (Conf != NULL)
		{
			switch (AsilLevel)
			{
				#if ERRMANAGER_QM_LEVEL_ACTIVE == 1u
				case ErrorMgr_Asil_QM:
				{
					ErrorMgrAggregator_Callback_Clear_QM();
				}
				break;
				#endif
				#if ERRMANAGER_A_LEVEL_ACTIVE == 1u
				case ErrorMgr_Asil_A:
				{
					ErrorMgrAggregator_Callback_Clear_A();
				}
				break;
				#endif
				#if ERRMANAGER_B_LEVEL_ACTIVE == 1u
				case ErrorMgr_Asil_B:
				{
					ErrorMgrAggregator_Callback_Clear_B();
				}
				break;
				#endif
				#if ERRMANAGER_C_LEVEL_ACTIVE == 1u
				case ErrorMgr_Asil_C:
				{
					ErrorMgrAggregator_Callback_Clear_C();
				}
				break;
				#endif
				#if ERRMANAGER_D_LEVEL_ACTIVE == 1u
				case ErrorMgr_Asil_D:
				{
					ErrorMgrAggregator_Callback_Clear_D();
				}
				break;
				#endif

				default:
					/* Do Nothing */
					break;
			}

			for (Core = (uint16_t)0; Core < (uint16_t)ErrorMgr_Core_CORE_MAX; Core++)
			{
				bError = FALSE;

				if(Conf->RamDef->CurrentCount[Core] < 0xFFFFFFFFU)
				{
					Conf->RamDef->CurrentCount[Core] += 1U;
				}
				else
				{
					Conf->RamDef->CurrentCount[Core] = 0U;
					Conf->RamDef->LastRecvdCount[Core] = 0U;
				}

				if (Conf->RamDef->LastRecvdCount[Core] > Conf->RamDef->CurrentCount[Core])
				{
					/*Sanity check: Should not happen*/
					bError = TRUE;
				}
				else
				{
					/*Check if there is a data has not been received yet*/
					diff = (Conf->RamDef->CurrentCount[Core] - Conf->RamDef->LastRecvdCount[Core]);
					if (diff >= Conf->Timeout_MonitorTaskCounts[Core])
					{
						bError = TRUE;
					}
				}

				if (bError == (bool_t)TRUE)
				{
					if (Conf->RamDef->bLossOfCommDetected[Core] == (bool_t)FALSE)
					{
						/*Report Error as Active*/
						Conf->LossOfCommCallBack((ErrorMgr_CoreList)Core, ldef_ErrorMgr_ErrorActive);
					}
					Conf->RamDef->bLossOfCommDetected[Core] = (bool_t)TRUE;
				}
				else
				{
					if (Conf->RamDef->bLossOfCommDetected[Core] == (bool_t)TRUE)
					{
						/*Report Error as InActive anymore*/
						Conf->LossOfCommCallBack((ErrorMgr_CoreList)Core, ldef_ErrorMgr_ErrorInactive);

					}
					Conf->RamDef->bLossOfCommDetected[Core] = (bool_t)FALSE;

				}
			}




			/*Now : Lets call the callback for handling Every Error : Highest Priority is always loss of communication with the satellite itself
			Iterate through the  Errors and Call the Notifiers*/

			for (i = (uint16_t)0; i < (uint16_t)ErrorMgr_Core_CORE_MAX; i++)
			{
				ErrDescExt = ErrorMgr_getGetErrorDesc((ErrorMgr_CoreList)i);
				ErrDesc = ErrDescExt[AsilLevel].ErrorDesc;
				count = ErrDescExt[AsilLevel].Count;			
				for (j = (uint16_t)0; j < count; j++)
				{

					errMap=ErrorMgr_getErrorMapping(ErrDesc[j].enError);				
					if(errMap->enAsilEnumVal >= ErrorMgrAgg_asil_MaxErrorValues[AsilLevel])
					{
						RuntimeDefs->RuntimeErr.ErrMapErrNo_NotWithinRange+=1u;/* PRQA 3383 *//* No Functional impact. Not used in code. Kept for future use. */
					}
					else
					{
						/*ErrorMgrAgg_asil_ConsolidatedOutput[errMap.enAsilEnumVal]=FALSE;*/
					}

					/*Callback = ErrorMgrAggregator_GetErrorHandler(ErrDesc[j].enError);*/
					/*if (Callback != NULL)*/
					{
						if (ErrDesc[j].RamDef->bErrorActive == (bool_t)TRUE)
						{						
							if(errMap->enAsilEnumVal <= ErrorMgrAgg_asil_MaxErrorValues[AsilLevel])
							{
								ErrorMgrSetError_BitPacked((ErrorMgrAgg_asil_ConsolidatedOutput), (errMap->enAsilEnumVal));
								/*ErrorMgrAgg_asil_ConsolidatedOutput[errMap.enAsilEnumVal]=TRUE;*/
								#ifdef ERROR_MANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION
									u32DebugCountPtr[errMap->enAsilEnumVal]+=1u;/* PRQA 3383 *//* No Functional impact. Not used in code. Kept for future use. */
								#endif
							}
							for(sCount=0;sCount<errMap->SafeStateCount;sCount++)
							{
								if(errMap->enSafeStates[sCount] < ldef_ErrorMgr_SafeState_Max)
								{
									SafeStateDef[errMap->enSafeStates[sCount]]=TRUE;
									#if ERRORMGR_CURRENTCORE == ERRORMGRCORE_MCU1_0
									if((errMap->enSafeStates[sCount] == ldef_ErrorMgr_SafeState_safestate2)&&(SafeState2_RstRsn_flag==0u)&&(AsilLevel == ErrorMgr_Asil_B))
									{
										SafeState2_RstRsn_flag = (uint16_t)errMap->enAsilEnumVal;
										ErrorMgrAggregatorApp_Write_SafeState2ReasonProcess(SafeState2_RstRsn_flag);
									}
									#endif
								}
								else
								{
									RuntimeDefs->RuntimeErr.Err_SafeStateValueOutofMaxVal+=1u;/* PRQA 3383 *//* No Functional impact. Not used in code. Kept for future use. */
								}
							}
							if(errMap->pDtcFlag != NULL)
							{
								if (*errMap->pDtcFlag != 0x01u)
								{
									*errMap->pDtcFlag = 0x01u;
									(void)memcpy((void*)errMap->pDtcAddData, (const void*)&ErrDesc[j].RamDef->stAddData.AdditionalData, (size_t)sizeof(ldef_ErrorMgr_stAddData));
								}
							}
							/*Callback(ldef_ErrorMgr_ErrorActive, &ErrDesc[j].RamDef->stAddData.AdditionalData[0], &RuntimeDefs->RuntimeErr);*/
						}
	#ifdef ERRORMGR_AGGREGATOR_ASSERTINDIVIDUALERRORS_DURINGLOSSOFCOMM
						else if (Conf->RamDef->bLossOfCommDetected[i] == TRUE)
						{
							/*Callback(ErrorMgr_ErrorActive,&ErrDesc[j].RamDef->stAddData.AdditionalData[0],&RuntimeDefs->RuntimeErr);*/
							if(errMap->enAsilEnumVal <= ErrorMgrAgg_asil_MaxErrorValues[AsilLevel])
							{
								ErrorMgrSetError_BitPacked(ErrorMgrAgg_asil_ConsolidatedOutput,errMap->enAsilEnumVal)
								/*ErrorMgrAgg_asil_ConsolidatedOutput[errMap.enAsilEnumVal]=TRUE;*/
							}
							for(sCount=0;sCount<errMap->SafeStateCount;sCount++)
							{
								if(errMap->enSafeStates[sCount] < ldef_ErrorMgr_SafeState_Max)
								{
									SafeStateDef[errMap->enSafeStates[sCount]]=TRUE;
								}
								else
								{
									RuntimeDefs->RuntimeErr.Err_SafeStateValueOutofMaxVal+=1u;
								}
							}
						}
	#endif
						else
						{
							/*Callback(ldef_ErrorMgr_ErrorInactive, &ErrDesc[j].RamDef->stAddData.AdditionalData[0],&RuntimeDefs->RuntimeErr); */
						}
					}
					/*else
					{
						DET equivalent
					}*/

				}

			}

		

			

			/*Write the big structure for the degradation manager and any other modules that might be collecting statistics*/
			ErrorMgrAggregatorApp_Write_AsilGrouped_ErrorStatus(AsilLevel,&ErrorMgrAgg_asil_ConsolidatedOutput[0],PackedOuputSize,&RuntimeDefs->RuntimeErr);

			#ifdef ERROR_MANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION
				if(AsilLevel == ErrorMgr_Asil_B)
				{
					(void)memcpy((void *)ErrorMgrAgg_GetDebug_ErrMgrSt_B(),(const void*)&ErrorMgrAgg_asil_ConsolidatedOutput[0],(size_t)ErrorMgrAgg_GetDebug_ErrMgrStSize_B());
				}
				if(AsilLevel == ErrorMgr_Asil_QM)
				{
					(void)memcpy((void *)ErrorMgrAgg_GetDebug_ErrMgrSt_QM(),(const void*)&ErrorMgrAgg_asil_ConsolidatedOutput[0],(size_t)ErrorMgrAgg_GetDebug_ErrMgrStSize_QM());
				}
			#endif
			
			/*Write if any of the safe states status are turned on*/
			ErrorMgrAggregatorApp_Write_SafeState(AsilLevel,SafeStateDef,(uint32_t)ldef_ErrorMgr_SafeState_Max,&RuntimeDefs->RuntimeErr);

			/*Write the DTC structures*/
			switch (AsilLevel)
			{
				#if ERRMANAGER_QM_LEVEL_ACTIVE == 1u
				case ErrorMgr_Asil_QM:
				{
					ErrorMgrAggregator_Callback_WriteDtcData_QM();
				}
				break;
				#endif
				#if ERRMANAGER_A_LEVEL_ACTIVE == 1u
				case ErrorMgr_Asil_A:
				{
					ErrorMgrAggregator_Callback_WriteDtcData_A();
				}
				break;
				#endif
				#if ERRMANAGER_B_LEVEL_ACTIVE == 1u
				case ErrorMgr_Asil_B:
				{
					ErrorMgrAggregator_Callback_WriteDtcData_B();
				}
				break;
				#endif
				#if ERRMANAGER_C_LEVEL_ACTIVE == 1u
				case ErrorMgr_Asil_C:
				{
					ErrorMgrAggregator_Callback_WriteDtcData_C();
				}
				break;
				#endif
				#if ERRMANAGER_D_LEVEL_ACTIVE == 1u
				case ErrorMgr_Asil_D:
				{
					ErrorMgrAggregator_Callback_WriteDtcData_D();
				}
				break;
				#endif

				default:
					/* Do Nothing */
					break;
			}

			
			

		}
	}
	
}


#if ERRORMGR_E2EPROTECTIONTYPE == ERRORMGR_E2EPROTECTIONTYPE_LOCAL

bool_t ErrorMgrAggregator_VerifyCRC(ldef_ErrorMgr_ErrorField* Start, uint16_t Count, uint32_t Checksum)
{
	/* DD-ID: {F5D5B8DD-9624-4eca-866E-E18E77BC7F5A}*/
	(void)Start;
	(void)Count;
	(void)Checksum;
	bool_t bRet = TRUE;


	return bRet;
}

#endif

bool_t ErrorMgrAggregator_HandleandVerifyRunningCount(ErrorMgr_CoreList Core, uint32_t RunningCount, ErrorMgr_AsilList AsilLevel)
{
  /* DD-ID: {D2A6B6E4-3BEE-4c4a-9650-21E35917B84B}*/
	bool_t bRet = TRUE;
	const ErrorMgrAggregator_SatelliteMonitorConf* Conf = NULL;
	uint32_t* PrevCount = (uint32_t * )&ErrorMgrAgg_RamDefs[AsilLevel]->SatRunCount[0];


	if (RunningCount >= (PrevCount[Core] + 1u)) /* PRQA 3383 *//* No Functional impact. */
	{
		/*Next one in the logical sequence : Accept it*/
		PrevCount[Core] = RunningCount;
		Conf=ErrorMgrAggregator_getConf(AsilLevel);
		/*Update the last received current as recent*/
		Conf->RamDef->LastRecvdCount[Core] = Conf->RamDef->CurrentCount[Core];

		bRet = TRUE;

	}
	else
	{
		/*This represents an old message id: Drop it*/
	}

	

	return bRet;
}

#ifdef __cplusplus
}
#endif



#endif
