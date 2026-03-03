#include "PlatformDataTypes.h"
#include "ErrorManagerTypes.h"
#include "ErrorManagerDef.h"
#include "DegManager.h"
#include "DegManagerDef.h"
#include "DegManager_app.h"
#include "string.h"
#include "DegManagerApp_HelperFuncs.h"


#include "DegManager_B_Memmap_adapt.h"

/* 3493, 3494, 0310, 3305, 1840, 1843 */ /* MD_MSR_Rule14.3, MD_MSR_Rule11.3, MD_MSR_Rule10.4 */
/*************************************** Justification *********************************************/
/*
 * 3493, 3494: No functional impact. Conditional check added to avoid any unintentional mistakes while updating the enums.
 * 0310, 3305: No functional impact. Pointers cast to a different type but passed on to further function calls via void pointer.
 * 1840, 1843: No functional impact. Assignment done as per code implementation.
 */

static DegManager_Output_B_t DegManager_Output_B DEGMANAGER_ATTR_B_HIGHPERF_BSS;

#ifndef FID_ENUM_B_HAS_NO_ELEMENTS
static uint32_t DegManager_FID_B_QM_InputMask[B_FID_MAX][DEGMANAGER_GETPACKEDSIZE(ldef_QM_ErrorMgr_ErrorNum_Max)] DEGMANAGER_ATTR_B_HIGHPERF_BSS;
static uint32_t DegManager_FID_B_B_InputMask[B_FID_MAX][DEGMANAGER_GETPACKEDSIZE(ldef_B_ErrorMgr_ErrorNum_Max)] DEGMANAGER_ATTR_B_HIGHPERF_BSS;
#endif

#ifndef RES_ENUM_B_HAS_NO_ELEMENTS
static uint32_t DegManager_RES_B_QM_InputMask[B_RES_MAX][DEGMANAGER_GETPACKEDSIZE(ldef_QM_ErrorMgr_ErrorNum_Max)] DEGMANAGER_ATTR_B_HIGHPERF_BSS;
static uint32_t DegManager_RES_B_B_InputMask[B_RES_MAX][DEGMANAGER_GETPACKEDSIZE(ldef_B_ErrorMgr_ErrorNum_Max)] DEGMANAGER_ATTR_B_HIGHPERF_BSS;
#endif

#ifdef DEGMANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION

 #if defined(DEGMANAGER_FID_BYTE_STRUCT)
	static FID_BYTE_STRUCT_B Debug_FIM_DegManager_Output_B DEGMANAGER_ATTR_B_BSS;
	static RES_BYTE_STRUCT_FEATURES_B Debug_RES_DegManager_Output_B DEGMANAGER_ATTR_B_BSS;
 #else
	volatile static FID_BIT_STRUCT_B Debug_FIM_DegManager_Output_B DEGMANAGER_ATTR_B_BSS;
	volatile static RES_BIT_STRUCT_FEATURES_B Debug_RES_DegManager_Output_B DEGMANAGER_ATTR_B_BSS;
 #endif
#endif

#ifdef __cplusplus
extern "C" {
#endif


static void DegManager_B_Init_Mask(void)
{
	/* DD-ID: {98A58672-E4A2-41b6-BEB1-5546F9065D31}*/
		uint32_t i,  k;
		#ifndef FID_ENUM_B_HAS_NO_ELEMENTS
		const DegMgr_ErrorDef* Fid_B_Def = DegManaagerDef_Get_FID_ErrorDef_B();
		#endif
		#ifndef RES_ENUM_B_HAS_NO_ELEMENTS
		const DegMgr_ErrorDef* Res_B_Def = DegManagerDef_Get_RES_ErrorDef_B();
		#endif
		uint32_t *u32Ptr;

		#ifndef FID_ENUM_B_HAS_NO_ELEMENTS
		for (i = 0u; i < (uint32_t)B_FID_MAX; i++)
		{
			for (k = 0u; k < Fid_B_Def[i].errDep.Dep_Error_Count_QM; k++)
			{
				u32Ptr=&DegManager_FID_B_QM_InputMask[i][0];
				DEGSetError_BitPacked(u32Ptr, Fid_B_Def[i].errDep.Error_List_QM[k]);
			}
			for (k = 0u; k < Fid_B_Def[i].errDep.Dep_Error_Count_B; k++)
			{
				u32Ptr=&DegManager_FID_B_B_InputMask[i][0];
				DEGSetError_BitPacked(u32Ptr, Fid_B_Def[i].errDep.Error_List_B[k]);
			}
		}
		#endif
		#ifndef RES_ENUM_B_HAS_NO_ELEMENTS
		for (i = 0u; i < (uint32_t)B_RES_MAX; i++)
			{

			for (k = 0u; k < Res_B_Def[i].errDep.Dep_Error_Count_QM; k++)
			{
				u32Ptr=&DegManager_RES_B_QM_InputMask[i][0];
				DEGSetError_BitPacked(u32Ptr, Res_B_Def[i].errDep.Error_List_QM[k]);
			}
			for (k = 0u; k < Res_B_Def[i].errDep.Dep_Error_Count_B; k++)
			{
				u32Ptr=&DegManager_RES_B_B_InputMask[i][0];
				DEGSetError_BitPacked(u32Ptr, Res_B_Def[i].errDep.Error_List_B[k]);
			}
		}
		#endif
}

void DegManager_Init_B(void)
{
  /* DD-ID: {5F7FD184-2D2F-4f77-B78E-70CE265D8C3F}*/
	(void)memset((void *)&DegManager_Output_B, 0, sizeof(DegManager_Output_B));
	DegManager_B_Init_Mask();
}

void DegManager_Periodic_B(void)
{
  /* DD-ID: {8A1D5676-98CD-40c6-81E3-B886FF653298}*/
#ifndef FID_ENUM_B_HAS_NO_ELEMENTS
	static DegManager_DiagnosticDebugErrorCount DegManager_Errors_B DEGMANAGER_ATTR_B_BSS = {(uint32_t)0};
#endif

#ifndef FID_ENUM_B_HAS_NO_ELEMENTS
	const uint32* DegManager_FID_B_InputMaskPtrs[ErrorMgr_Asil_MAX] = { &DegManager_FID_B_QM_InputMask[0][0], &DegManager_FID_B_B_InputMask[0][0] };
#endif
#ifndef RES_ENUM_B_HAS_NO_ELEMENTS
	const uint32* DegManager_RES_B_InputMaskPtrs[ErrorMgr_Asil_MAX] = { &DegManager_RES_B_QM_InputMask[0][0], &DegManager_RES_B_B_InputMask[0][0] };
#endif

	static uint32_t DegMgr_ExeuteCount=0;
	static uint32_t DegManager_B_InputData[DegManager_MaxInputsize_BitPacked] DEGMANAGER_ATTR_B_HIGHPERF_BSS;

	DegMgr_ExeuteCount++;
	if(DegMgr_ExeuteCount >= (uint32_t)DEGRADATIONMANAGER_B_EXECUTION_DIVISOR_COUNT)
	{
		DegMgr_ExeuteCount = (uint32_t)0;

		#ifndef FID_ENUM_B_HAS_NO_ELEMENTS
		DegManager_FimCalcualtion((uint32_t *)&DegManager_B_InputData[0],ErrorMgr_Asil_B,(uint32_t)B_FID_MAX,(uint32_t *)&DegManager_Output_B.FID_Output[0], &DegManager_Errors_B , DegManager_FID_B_InputMaskPtrs);
		#endif
		#ifndef RES_ENUM_B_HAS_NO_ELEMENTS
		DegManager_FimCalcualtion((uint32_t *)&DegManager_B_InputData[0],ErrorMgr_Asil_B,(uint32_t)B_RES_MAX,(uint32_t *)&DegManager_Output_B.RES_Output[0], &DegManager_Errors_B , DegManager_RES_B_InputMaskPtrs);
		#endif

   #if defined(DEGMANAGER_FID_BYTE_STRUCT)
    #ifdef DEGMANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION
		  DegManagerApp_ConvStruct_B((FID_BYTE_STRUCT_B *)&Debug_FIM_DegManager_Output_B,(RES_BYTE_STRUCT_FEATURES_B *)&Debug_RES_DegManager_Output_B,&DegManager_Output_B);
		#endif
		  (void)DegManagerApp_Send((uint32_t *)&Debug_FIM_DegManager_Output_B, (uint16_t)B_FID_MAX,(uint32_t *)&Debug_RES_DegManager_Output_B, (uint16_t)B_RES_MAX, ErrorMgr_Asil_B);/* 3305 */ /* MD_MSR_Rule11.3 *//* Res_Output not used in function DegManagerApp_Send() */
	 #else
		 DegManagerApp_Send((uint32 *)&DegManager_Output_B.FID_Output[0], B_FID_MAX,(uint32 *)&DegManager_Output_B.RES_Output[0], B_RES_MAX, ErrorMgr_Asil_B);

		 #ifdef DEGMANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION
			DegManagerApp_ConvStruct_BITARRAY_B((FID_BIT_STRUCT_B *)&Debug_FIM_DegManager_Output_B,(RES_BIT_STRUCT_FEATURES_B *)&Debug_RES_DegManager_Output_B,&DegManager_Output_B);
		 #endif
		#endif
	}
	else
	{
		/* Do Nothing */
	}


}


#ifdef __cplusplus
}
#endif

