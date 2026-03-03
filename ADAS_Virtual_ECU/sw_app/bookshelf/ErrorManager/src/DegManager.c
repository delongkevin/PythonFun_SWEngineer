#include "PlatformDataTypes.h"
#include "ErrorManagerTypes.h"
#include "ErrorManagerDef.h"
#include "DegManager.h"
#include "DegManagerDef.h"
#include "DegManager_app.h"
#include "string.h"
#include "DegManagerApp_HelperFuncs.h"

#include "DegManager_Common_Memmap_adapt.h"

/* 3493, 3494, 0310, 3305, 1840, 1843 */ /* MD_MSR_Rule14.3, MD_MSR_Rule11.3, MD_MSR_Rule10.4 */
/*************************************** Justification *********************************************/
/*
 * 3493, 3494: No functional impact. Conditional check added to avoid any unintentional mistakes while updating the enums.
 * 0310, 3305: No functional impact. Pointers cast to a different type but passed on to further function calls via void pointer.
 * 1840, 1843: No functional impact. Assignment done as per code implementation.
 */

#if DEGMANAGER_QM_LEVEL_ACTIVE == 1u
	#define D_ldef_QM_ErrorMgr_ErrorNum_Max ldef_QM_ErrorMgr_ErrorNum_Max
#else
	#define D_ldef_QM_ErrorMgr_ErrorNum_Max 1u
#endif
#if DEGMANAGER_A_LEVEL_ACTIVE == 1u
	#define D_ldef_A_ErrorMgr_ErrorNum_Max ldef_A_ErrorMgr_ErrorNum_Max
#else
	#define D_ldef_A_ErrorMgr_ErrorNum_Max 1u
#endif
#if DEGMANAGER_B_LEVEL_ACTIVE == 1u
	#define D_ldef_B_ErrorMgr_ErrorNum_Max ldef_B_ErrorMgr_ErrorNum_Max
#else
	#define D_ldef_B_ErrorMgr_ErrorNum_Max 1u
#endif
#if DEGMANAGER_C_LEVEL_ACTIVE == 1u
	#define D_ldef_C_ErrorMgr_ErrorNum_Max ldef_C_ErrorMgr_ErrorNum_Max
#else
	#define D_ldef_C_ErrorMgr_ErrorNum_Max 1u
#endif
#if DEGMANAGER_D_LEVEL_ACTIVE == 1u
	#define D_ldef_D_ErrorMgr_ErrorNum_Max ldef_D_ErrorMgr_ErrorNum_Max
#else
	#define D_ldef_D_ErrorMgr_ErrorNum_Max 1u
#endif

#ifdef __cplusplus
extern "C" {
#endif

void DegManager_FimCalcualtion(uint32_t *InputDataBuff,ErrorMgr_AsilList minAsilLevel,uint32_t FidMax,uint32_t *DegManager_Output,DegManager_DiagnosticDebugErrorCount *ErrorLog, const uint32* DegManager_InputMaskPtrs[ErrorMgr_Asil_MAX])
{
  /* DD-ID: {028802C6-9E97-4a6f-BB71-B535C2D11FF1}*/
	(void)*ErrorLog;
	uint32_t f;
	uint32_t i;
	uint8_t asil_err;
	bool_t bTemp;
	uint32_t CurrentMask;

	uint32_t PackedFidSize = DEGMANAGER_GETPACKEDSIZE(FidMax);
	const static uint32_t DegManager_PackedSize_Errors[ErrorMgr_Asil_MAX] = {
		#if DEGMANAGER_QM_LEVEL_ACTIVE == 1
		DEGMANAGER_GETPACKEDSIZE((uint32_t)ldef_QM_ErrorMgr_ErrorNum_Max > (uint32_t)0 ? (uint32_t)ldef_QM_ErrorMgr_ErrorNum_Max : (uint32_t)1),
		#endif
		#if DEGMANAGER_A_LEVEL_ACTIVE == 1
		DEGMANAGER_GETPACKEDSIZE(ldef_A_ErrorMgr_ErrorNum_Max > 0 ? ldef_A_ErrorMgr_ErrorNum_Max : 1),
		#endif
		#if DEGMANAGER_B_LEVEL_ACTIVE == 1
		DEGMANAGER_GETPACKEDSIZE((uint32_t)ldef_B_ErrorMgr_ErrorNum_Max > (uint32_t)0 ? (uint32_t)ldef_B_ErrorMgr_ErrorNum_Max : (uint32_t)1),
		#endif
		#if DEGMANAGER_C_LEVEL_ACTIVE == 1
		DEGMANAGER_GETPACKEDSIZE(ldef_C_ErrorMgr_ErrorNum_Max > 0 ? ldef_C_ErrorMgr_ErrorNum_Max : 1),
		#endif
		#if DEGMANAGER_D_LEVEL_ACTIVE == 1
		DEGMANAGER_GETPACKEDSIZE(ldef_D_ErrorMgr_ErrorNum_Max > 0 ? ldef_D_ErrorMgr_ErrorNum_Max : 1)
		#endif
	};

	(void)memset(DegManager_Output, 0, PackedFidSize*sizeof(uint32));

	//for(tempList=(uint8_t)minAsilLevel;tempList <(uint8_t)ErrorMgr_Asil_MAX ; tempList+=1)
	//Till Naveen fixes the dependencies
	for(asil_err =(uint8_t)0; asil_err <(uint8_t)ErrorMgr_Asil_MAX ; asil_err++)
	{
		const uint32_t* MaskPtr_Asil = DegManager_InputMaskPtrs[asil_err];
		bTemp=DegManagerApp_Read(&InputDataBuff[0],(ErrorMgr_AsilList)asil_err,minAsilLevel);
		if(bTemp == (bool_t)TRUE)
		{		
			
			for (f = (uint32_t)0; f < FidMax; f++)
			{
				CurrentMask = (uint32_t)0;
				
				for (i = (uint32_t)0; i < DegManager_PackedSize_Errors[asil_err]; i++)
				{
					CurrentMask |= MaskPtr_Asil[(f * DegManager_PackedSize_Errors[asil_err])+i] & InputDataBuff[i];
				}
				if (CurrentMask != (uint32_t)0)
				{
					DEGSetError_BitPacked(DegManager_Output, f);
				}
				else
				{
					/* Do Nothing */
				}
			}		
		}
		else
		{
			/* Do Nothing */
		}
	}
}


#ifdef __cplusplus
}
#endif






