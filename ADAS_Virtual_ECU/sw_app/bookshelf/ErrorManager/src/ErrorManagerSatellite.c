#include "ErrorManagerTypes.h"
#include "ErrorManagerDef.h"
#include "ErrorManagerSatelliteDef.h"
#include "ErrorManagerSatelliteApp.h"
#include "ErrorManagerSatellite.h"
#include "string.h"

#include "ErrorManager_Common_Memmap.h"

static void ErrorMgrSatellite_PeriodicFunction(ErrorMgr_AsilList AsilLevel);



static const uint32_t* ErrorMgr_Satellite_RunningCount[ErrorMgr_Asil_MAX] = {
	#if ERRMANAGER_QM_LEVEL_ACTIVE == 1u
	&ErrorMgr_Satellite_QM_RunningCount,
	#endif
	#if ERRMANAGER_A_LEVEL_ACTIVE == 1u
	&ErrorMgr_Satellite_A_RunningCount,
	#endif
	#if ERRMANAGER_B_LEVEL_ACTIVE == 1u
	&ErrorMgr_Satellite_B_RunningCount,
	#endif
	#if ERRMANAGER_C_LEVEL_ACTIVE == 1u
	&ErrorMgr_Satellite_C_RunningCount,
	#endif
	#if ERRMANAGER_D_LEVEL_ACTIVE == 1u
	&ErrorMgr_Satellite_D_RunningCount,
	#endif
};





#if ERRMANAGER_QM_LEVEL_ACTIVE == 1u
void ErrorMgrSatellite_Init_QM(void)
{
  /* DD-ID: {19562DFA-F515-468d-9BC2-20E03C7BB0C8}*/
	*(uint32_t*)ErrorMgr_Satellite_RunningCount[ErrorMgr_Asil_QM] = (uint32_t)0;
	ErrorManagerSatelliteDef_Init_QM();
	ErrorMgrSatelliteApp_Init(ErrorMgr_Asil_QM);
}
#endif

#if ERRMANAGER_A_LEVEL_ACTIVE == 1u
void ErrorMgrSatellite_Init_A(void)
{
  /* DD-ID: {AC98BD69-FE16-49f3-B05F-F151259070F6}*/
	*(uint32_t*)ErrorMgr_Satellite_RunningCount[ErrorMgr_Asil_A] = (uint32_t)0;
	ErrorManagerSatelliteDef_Init_A();
	ErrorMgrSatelliteApp_Init(ErrorMgr_Asil_A);
}
#endif


#if ERRMANAGER_B_LEVEL_ACTIVE == 1u
void ErrorMgrSatellite_Init_B(void)
{
  /* DD-ID: {29AC4F13-7644-41aa-ABD1-2DA93AE30783}*/
	*(uint32_t*)ErrorMgr_Satellite_RunningCount[ErrorMgr_Asil_B] = (uint32_t)0;
	ErrorManagerSatelliteDef_Init_B();
	ErrorMgrSatelliteApp_Init(ErrorMgr_Asil_B);
}
#endif

#if ERRMANAGER_C_LEVEL_ACTIVE == 1u
void ErrorMgrSatellite_Init_C(void)
{
  /* DD-ID: {4CB7E07E-3BB5-46c7-8A50-0CC005EE3AC3}*/
	*(uint32_t*)ErrorMgr_Satellite_RunningCount[ErrorMgr_Asil_C] = (uint32_t)0;
	ErrorManagerSatelliteDef_Init_C();
	ErrorMgrSatelliteApp_Init(ErrorMgr_Asil_C);
}
#endif

#if ERRMANAGER_D_LEVEL_ACTIVE == 1u
void ErrorMgrSatellite_Init_D(void)
{
  /* DD-ID: {CED8F84C-595B-458a-A830-2420BAD777DE}*/
	*(uint32_t*)ErrorMgr_Satellite_RunningCount[ErrorMgr_Asil_D] = (uint32_t)0;
	ErrorManagerSatelliteDef_Init_D();
	ErrorMgrSatelliteApp_Init(ErrorMgr_Asil_D);
}
#endif


/* DD-ID: {F787665F-E282-47aa-A18D-239B64383609}*/
/*void ErrorMgrSatellite_DeInit(void)
{
   Kept in case of future use.
	ErrorMgrSatelliteApp_DeInit();
}*/

static void ErrorMgrSatellite_NotifyAggregator(ErrorMgr_AsilList asil)
{
  /* DD-ID: {9BF16096-AC51-4321-B06C-0E71CAE5A6BB}*/
	uint16_t j, count;
	const ErrorMgr_ErrorDescExt* ErrDescExt;
	const ErrorMgr_ErrorDesc* ErrDesc;
	const ldef_ErrorMgr_ErrorCommPack* ComPack = ErrorMgr_getErrorCommPack(asil);

	ErrDescExt = ErrorMgr_getGetErrorLocalDesc();
	ErrDesc = ErrDescExt[asil].ErrorDesc;
	count = ErrDescExt[asil].Count;

	for (j = (uint16_t)0; j < count; j++)
	{
		if (ErrDesc[j].RamDef->bErrorActive == (bool_t)TRUE)
		{
			ComPack->Error[j] = (bool_t)TRUE;
		}
		else
		{
			ComPack->Error[j] = (bool_t)FALSE;
		}
		
		(void)memcpy((void *)&ComPack->Data[j], (const void *)&ErrDesc[j].RamDef->stAddData, (size_t)sizeof(ldef_ErrorMgr_stAddData));
	}

	*(uint32_t*)ErrorMgr_Satellite_RunningCount[asil] += (uint32_t)1;
	*ComPack->RunningCounter = *(uint32_t*)ErrorMgr_Satellite_RunningCount[asil];

#if ERRORMGR_E2EPROTECTIONTYPE == ERRORMGR_E2EPROTECTIONTYPE_LOCAL 		

		/*calculate the checksum also*/
#endif

	
	ErrorMggrSatelliteApp_Send(ComPack, asil);
	#ifdef ERROR_MANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION
		if(asil == ErrorMgr_Asil_B)
		{
			/*static_assert(sizeof(Debug_Sat_B_Output)== sizeof(ldef_ErrorMgr_ErrorCommPack->Error));
			memcpy((void *)&Debug_Sat_B_Output, (void *)&ComPack->Error[0],sizeof(Debug_Sat_B_Output));*/
		}
		else if(asil == ErrorMgr_Asil_QM)
		{
			/*static_assert(sizeof(Debug_Sat_QM_Output)== sizeof(ldef_ErrorMgr_ErrorCommPack->Error));*/
			#ifdef ErrorMgr_LocalDef_ST_Core_Specific_QM
			(void)memcpy((void *)&Debug_Sat_QM_Output,(const void *)&ComPack->Error[0],(size_t)sizeof(Debug_Sat_QM_Output));
			#endif
		}
		else
		{
			/* Do Nothing */
		}
	#endif 
		
}

#if ERRMANAGER_QM_LEVEL_ACTIVE == 1u
void ErrorMgrSatellite_PeriodicFunction_QM(void)
{
  /* DD-ID :{FA124F91-B803-4e21-97CD-C0CD1A49F151}*/
	ErrorMgrSatellite_PeriodicFunction(ErrorMgr_Asil_QM);
}
#endif

#if ERRMANAGER_B_LEVEL_ACTIVE == 1u
void ErrorMgrSatellite_PeriodicFunction_B(void)
{
  /* DD-ID :{A2EDAB67-2F8B-479d-B741-025589AE1AF0}*/
	ErrorMgrSatellite_PeriodicFunction(ErrorMgr_Asil_B);

}
#endif


#if ERRMANAGER_D_LEVEL_ACTIVE == 1u
void ErrorMgrSatellite_PeriodicFunction_D()
{
  /* DD-ID :{D2664AC5-4933-4a66-A374-8D168D77273C}*/
	ErrorMgrSatellite_PeriodicFunction(ErrorMgr_Asil_D);
}
#endif


static void ErrorMgrSatellite_PeriodicFunction(ErrorMgr_AsilList AsilLevel)
{
  /* DD-ID :{E5B9930E-C03A-4dd0-8583-82E24BE09637}*/
	const ErrorMgr_ErrorDescExt* DescExt;
	const ErrorMgr_ErrorDesc* ErrDesc;
	ErrorMgr_RuntimeStateDef* CurrState;
	uint16_t i;
	uint16_t count;
	static uint32_t Sat_ExeuteCount[ErrorMgr_Asil_MAX]= {0};
	static const uint8_t ErrorMgrSat_RunDivisor[] ={
		#if ERRMANAGER_QM_LEVEL_ACTIVE == 1u
			ERRORMGRSATELLITE_PERIODICFUNC_TIME_MS/ERRORMGRSATELLITE_OSPERIODIC_CALLBACK_TIME_MS,
		#endif
		#if ERRMANAGER_A_LEVEL_ACTIVE == 1u
			ERRORMGRSATELLITE_PERIODICFUNC_TIME_MS/ERRORMGRSATELLITE_OSPERIODIC_CALLBACK_TIME_MS,
		#endif
		#if ERRMANAGER_B_LEVEL_ACTIVE == 1u
			ERRORMGRSATELLITE_PERIODICFUNC_TIME_MS/ERRORMGRSATELLITE_OSPERIODIC_CALLBACK_TIME_MS,
		#endif
		#if ERRMANAGER_C_LEVEL_ACTIVE == 1u
			ERRORMGRSATELLITE_PERIODICFUNC_TIME_MS/ERRORMGRSATELLITE_OSPERIODIC_CALLBACK_TIME_MS,
		#endif
		#if ERRMANAGER_D_LEVEL_ACTIVE == 1u
			ERRORMGRSATELLITE_PERIODICFUNC_TIME_MS/ERRORMGRSATELLITE_OSPERIODIC_CALLBACK_TIME_MS,
		#endif

	};
	Sat_ExeuteCount[AsilLevel] += (uint32_t)1;/* PRQA 3383 *//* No functional impact. Used to execute code separately for QM and B. Reset to 0 after entering in following 'if' condition. */

	if(Sat_ExeuteCount[AsilLevel] >= ErrorMgrSat_RunDivisor[AsilLevel])
	{
	    Sat_ExeuteCount[AsilLevel] = (uint32_t)0;

		if (AsilLevel < ErrorMgr_Asil_MAX)
		{
			/*Process the ASIL Level*/
			DescExt = ErrorMgr_getGetErrorLocalDesc();
			if (DescExt != NULL)
			{			
				count = DescExt[AsilLevel].Count;
				for (i = (uint16_t)0; i < count; i++)
				{
					ErrDesc = &DescExt[AsilLevel].ErrorDesc[i];
					CurrState = ErrDesc->RamDef;
					if (CurrState != NULL)
					{
						/*if currently the error is active*/
						if (CurrState->bErrorActive == (bool_t)TRUE)
						{
							if (CurrState->bCurrentCycleInvocation == ldef_ErrorMgr_ErrorActive)
							{
								/*everything is the same : */
								CurrState->DematureTime = (uint16_t)0;
							}
							else if ((CurrState->bCurrentCycleInvocation == ldef_ErrorMgr_ErrorInactive) || ((CurrState->bCurrentCycleInvocation == ldef_ErrorMgr_Invalid) && (CurrState->bPrevCycleInvocation == ldef_ErrorMgr_ErrorInactive)))
							{
								if (CurrState->DematureTime >= ErrDesc->DematurationTime_ms)
								{
									CurrState->bErrorActive = (bool_t)FALSE;
									CurrState->MatureTime = (uint16_t)0;
								}
								else
								{
									/*Update De-maturation time*/
									CurrState->DematureTime += ERRORMGRSATELLITE_PERIODICFUNC_TIME_MS; /* PRQA 3383 *//* No functional impact. Does not wrap around. */
								}
								
							}
							else
							{
								/* Do nothing */
							}
						}
						else
						{
							if (CurrState->bCurrentCycleInvocation == ldef_ErrorMgr_ErrorInactive)
							{
								/*everything is the same : */
								CurrState->MatureTime = 0;
							}
							else if( (CurrState->bCurrentCycleInvocation == ldef_ErrorMgr_ErrorActive) || ((CurrState->bCurrentCycleInvocation == ldef_ErrorMgr_Invalid) && (CurrState->bPrevCycleInvocation == ldef_ErrorMgr_ErrorActive)))
							{
								if (CurrState->MatureTime >= ErrDesc->MaturationTime_ms)
								{
									CurrState->bErrorActive = TRUE;
									CurrState->DematureTime = 0;
								}
								else
								{
									/*Update Dematuration time*/
									CurrState->MatureTime += ERRORMGRSATELLITE_PERIODICFUNC_TIME_MS; /* PRQA 3383 *//* No functional impact. Does not wrap around. */
								}

							}
							else
							{
								/*Assertion of failure : Some corruption resulted in local memory*/
							}

						}

						if (CurrState->bCurrentCycleInvocation != ldef_ErrorMgr_Invalid)
						{
							CurrState->bPrevCycleInvocation = CurrState->bCurrentCycleInvocation;
						}
						CurrState->bCurrentCycleInvocation = ldef_ErrorMgr_Invalid;
					}
					else
					{
						
					}
					
				}
			}
			else
			{
				/*Send a Diag message that we are running a periodic task for errors that does not have any errors to process*/
			}
		}
		else
		{
			/*Assertion of failure*/
		}

		ErrorMgrSatellite_NotifyAggregator(AsilLevel);
	}
}

static void ErrorMgrSatellite_ProcessError(ldef_ErrorMgr_enErrorNo err, ldef_ErrorMgr_enErrorStatus enErrorStatus, const ErrorMgr_ErrorMapping *const map, const ldef_ErrorMgr_stAddData *AddData)
{
  /* DD-ID: {E8A2ECB3-4C93-4bab-8F23-B86E81F72C8C}*/
	const ErrorMgr_ErrorDescExt* DescExt;
	uint16_t Count,i;
	const ErrorMgr_ErrorDesc* Desc;
	/*Current Core is responsible for handling the error*/
	DescExt = ErrorMgr_getGetErrorLocalDesc();
	/*update the error status in the RAM Variable*/
	Count = DescExt[map->enAsil].Count;
	Desc = DescExt[map->enAsil].ErrorDesc;

	for (i = 0; i < Count; i++)
	{
		if (Desc[i].enError == err)
		{
			Desc[i].RamDef->bCurrentCycleInvocation = enErrorStatus;
			if (AddData != NULL)
			{
				(void)memcpy((void *)&Desc[i].RamDef->stAddData, (const void *)AddData, (size_t)sizeof(ldef_ErrorMgr_stAddData));
			}
			else
			{
				/* Do Nothing */
			}
			break;
		}
		else
		{
			/* Do Nothing */
		}
	}
}


#ifdef __cplusplus
extern "C" {
#endif

bool_t ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_enErrorNo err, ldef_ErrorMgr_enErrorStatus enErrorStatus,const ldef_ErrorMgr_stAddData *AddData)
{
  /* DD-ID: {EBDDF5A4-3D9C-4c51-8D24-F9CEA812A0B2}*/
	bool_t bRet = FALSE;
	ErrorMgr_ErrorMapping  const * map;
	
	map = ErrorMgr_getErrorMapping(err);
	if ((uint16)map->enCore == ERRORMGR_CURRENTCORE)
	{		
		ErrorMgrSatellite_ProcessError(err,enErrorStatus,map,AddData);
	}

	return bRet;
}
#ifdef __cplusplus
}
#endif





