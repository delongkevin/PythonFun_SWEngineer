#include "PlatformDataTypes.h"
#include "ErrorManagerTypes.h"
#include "ErrorManagerDef.h"
#include "DegManager.h"
#include "DegManagerDef.h"
#include "DegManager_app.h"
#include "string.h"
#include "DegManagerApp_HelperFuncs.h"


#include "DegManager_QM_Memmap_adapt.h"

/* 3493, 3494, 0310, 3305, 1840, 1843 */ /* MD_MSR_Rule14.3, MD_MSR_Rule11.3, MD_MSR_Rule10.4 */
/*************************************** Justification *********************************************/
/*
 * 3493, 3494: No functional impact. Conditional check added to avoid any unintentional mistakes while updating the enums.
 * 0310, 3305: No functional impact. Pointers cast to a different type but passed on to further function calls via void pointer.
 * 1840, 1843: No functional impact. Assignment done as per code implementation.
 */

static DegManager_Output_QM_t DegManager_Output_QM DEGMANAGER_ATTR_QM_HIGHPERF_BSS;



#ifndef FID_ENUM_QM_HAS_NO_ELEMENTS
static uint32_t DegManager_FID_QM_QM_InputMask[QM_FID_MAX][DEGMANAGER_GETPACKEDSIZE(ldef_QM_ErrorMgr_ErrorNum_Max)] DEGMANAGER_ATTR_QM_HIGHPERF_BSS;
static uint32_t DegManager_FID_QM_B_InputMask[QM_FID_MAX][DEGMANAGER_GETPACKEDSIZE(ldef_B_ErrorMgr_ErrorNum_Max)]  DEGMANAGER_ATTR_QM_HIGHPERF_BSS;
#endif
#ifndef RES_ENUM_QM_HAS_NO_ELEMENTS
static uint32_t DegManager_RES_QM_QM_InputMask[QM_RES_MAX][DEGMANAGER_GETPACKEDSIZE(ldef_QM_ErrorMgr_ErrorNum_Max)] DEGMANAGER_ATTR_QM_HIGHPERF_BSS;
static uint32_t DegManager_RES_QM_B_InputMask[QM_RES_MAX][DEGMANAGER_GETPACKEDSIZE(ldef_B_ErrorMgr_ErrorNum_Max)] DEGMANAGER_ATTR_QM_HIGHPERF_BSS;
#endif

#ifdef DEGMANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION
	#if defined(DEGMANAGER_FID_BYTE_STRUCT)
	static FID_BYTE_STRUCT_QM Debug_FIM_DegManager_Output_QM  DEGMANAGER_ATTR_QM_BSS;
	static RES_BYTE_STRUCT_FEATURES_QM Debug_RES_DegManager_Output_QM DEGMANAGER_ATTR_QM_BSS;
	#else
	static FID_BIT_STRUCT_QM Debug_FIM_DegManager_Output_QM  DEGMANAGER_ATTR_QM_BSS;
	static RES_BIT_STRUCT_FEATURES_QM Debug_RES_DegManager_Output_QM DEGMANAGER_ATTR_QM_BSS;
	#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif


static void DegManager_QM_Init_Mask(void)
{
	/* DD-ID: {86F47658-86CE-4b49-9615-F49BD8D89E0F}*/
		uint16_t i,  k;
		#ifndef FID_ENUM_QM_HAS_NO_ELEMENTS
		const DegMgr_ErrorDef* Fid_QM_Def = DegManaagerDef_Get_FID_ErrorDef_QM();
		#endif
		#ifndef RES_ENUM_QM_HAS_NO_ELEMENTS
		const DegMgr_ErrorDef* Res_QM_Def = DegManagerDef_Get_RES_ErrorDef_QM();
		#endif
		uint32_t *u32Ptr;

		#ifndef FID_ENUM_QM_HAS_NO_ELEMENTS
		for (i = 0u; i < (uint16_t)QM_FID_MAX; i++)
		{
			for (k = 0u; k < Fid_QM_Def[i].errDep.Dep_Error_Count_QM; k++)
			{
				u32Ptr=&DegManager_FID_QM_QM_InputMask[i][0];
				DEGSetError_BitPacked(u32Ptr, Fid_QM_Def[i].errDep.Error_List_QM[k]);
			}
			for (k = 0u; k < Fid_QM_Def[i].errDep.Dep_Error_Count_B; k++)
			{
				u32Ptr=&DegManager_FID_QM_B_InputMask[i][0];
				DEGSetError_BitPacked(u32Ptr, Fid_QM_Def[i].errDep.Error_List_B[k]);
			}
		}
		#endif

		#ifndef RES_ENUM_QM_HAS_NO_ELEMENTS
		for (i = 0u; i < (uint16_t)QM_RES_MAX; i++)
		{
			for (k = 0u; k < Res_QM_Def[i].errDep.Dep_Error_Count_QM; k++)
			{
				u32Ptr=&DegManager_RES_QM_QM_InputMask[i][0];
				DEGSetError_BitPacked(u32Ptr, Res_QM_Def[i].errDep.Error_List_QM[k]);
			}
			for (k = 0u; k < Res_QM_Def[i].errDep.Dep_Error_Count_B; k++)
			{
				u32Ptr=&DegManager_RES_QM_B_InputMask[i][0];
				DEGSetError_BitPacked(u32Ptr, Res_QM_Def[i].errDep.Error_List_B[k]);
			}
		}
		#endif
}

void DegManager_Init_QM(void)
{
	/* DD-ID: {4F89A749-DA0A-4886-8A18-B5622D864BFF}*/
	(void)memset((void *)&DegManager_Output_QM, 0u, sizeof(DegManager_Output_QM));
	DegManager_QM_Init_Mask();
}

void DegManager_Periodic_QM(void)
{

	/* DD-ID: {0771DBD4-7267-4a9c-B2BA-3C7E25EC230F}*/
#ifndef FID_ENUM_QM_HAS_NO_ELEMENTS
	const uint32_t* DegManager_FID_QM_InputMaskPtrs[ErrorMgr_Asil_MAX] = { &DegManager_FID_QM_QM_InputMask[0][0], &DegManager_FID_QM_B_InputMask[0][0] } ;
#endif
#ifndef RES_ENUM_QM_HAS_NO_ELEMENTS
	const uint32_t* DegManager_RES_QM_InputMaskPtrs[ErrorMgr_Asil_MAX] = { &DegManager_RES_QM_QM_InputMask[0][0], &DegManager_RES_QM_B_InputMask[0][0] } ;
#endif
	static uint32_t DegManager_QM_InputData[DegManager_MaxInputsize_BitPacked] DEGMANAGER_ATTR_QM_HIGHPERF_BSS;
	static uint32_t DegMgr_ExeuteCount=0;
	static DegManager_DiagnosticDebugErrorCount DegManager_Errors_QM DEGMANAGER_ATTR_QM_BSS = {(uint32_t)0};

	DegMgr_ExeuteCount++;
	if(DegMgr_ExeuteCount >= (uint32_t)DEGRADATIONMANAGER_QM_EXECUTION_DIVISOR_COUNT)
	{
		DegMgr_ExeuteCount = (uint32_t)0;

		#ifndef FID_ENUM_QM_HAS_NO_ELEMENTS
		DegManager_FimCalcualtion((uint32 *)&DegManager_QM_InputData[0],ErrorMgr_Asil_QM,(uint32_t)QM_FID_MAX,(uint32 *)&DegManager_Output_QM.FID_Output[0],&DegManager_Errors_QM, DegManager_FID_QM_InputMaskPtrs);
		#endif
		#ifndef RES_ENUM_QM_HAS_NO_ELEMENTS
		DegManager_FimCalcualtion((uint32 *)&DegManager_QM_InputData[0],ErrorMgr_Asil_QM,(uint32_t)QM_RES_MAX,(uint32 *)&DegManager_Output_QM.RES_Output[0],&DegManager_Errors_QM, DegManager_RES_QM_InputMaskPtrs);
		#endif

    #if defined(DEGMANAGER_FID_BYTE_STRUCT)
			#ifdef DEGMANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION
		  DegManagerApp_ConvStruct_QM((FID_BYTE_STRUCT_QM *)&Debug_FIM_DegManager_Output_QM,(RES_BYTE_STRUCT_FEATURES_QM *)&Debug_RES_DegManager_Output_QM,&DegManager_Output_QM);
		  #endif
	    (void)DegManagerApp_Send((uint32_t *)&Debug_FIM_DegManager_Output_QM, (uint16_t)QM_FID_MAX,(uint32 *)&Debug_RES_DegManager_Output_QM,(uint16_t) QM_RES_MAX, ErrorMgr_Asil_QM);
		#else
	    DegManagerApp_Send((uint32 *)&DegManager_Output_QM.FID_Output[0], QM_FID_MAX,(uint32 *)&DegManager_Output_QM.RES_Output[0], QM_RES_MAX, ErrorMgr_Asil_QM);
			#ifdef DEGMANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION
				DegManagerApp_ConvStruct_BITARRAY_QM((FID_BIT_STRUCT_QM *)&Debug_FIM_DegManager_Output_QM,(RES_BIT_STRUCT_FEATURES_QM *)&Debug_RES_DegManager_Output_QM,&DegManager_Output_QM);
			#endif
		#endif


	}

}



#ifdef __cplusplus
}
#endif
