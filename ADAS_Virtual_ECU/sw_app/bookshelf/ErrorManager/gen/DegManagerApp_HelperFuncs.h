#ifndef DEGMANAGER_HELPERFUNC_DEF_H_INCGUARD
#define DEGMANAGER_HELPERFUNC_DEF_H_INCGUARD



#include "string.h"
#include "DegManagerDef.h"
#include "DegManagerTypes.h"
#include "assert.h"

/* 1840, 1495 */ /* MD_MSR_Rule10.4, MD_MSR_Rule21.15 */
/*************************************** Justification *********************************************/
/*
 * 1840: No functional impact. Assignment done as per code implementation.
 * 1495: No functional impact. Size passed along with pointer to copy desired data.
 */
#define DegManager_BiggerOf2Size(x,y) ((uint32_t)(x) > (uint32_t)(y) ? (uint32_t)(x) : (uint32_t)(y))

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


#define DegManager_MaxInputsize  	(DegManager_BiggerOf2Size( 											\
	DegManager_BiggerOf2Size( 																			\
	DegManager_BiggerOf2Size(D_ldef_QM_ErrorMgr_ErrorNum_Max,D_ldef_A_ErrorMgr_ErrorNum_Max), 				\
	DegManager_BiggerOf2Size(D_ldef_B_ErrorMgr_ErrorNum_Max,D_ldef_C_ErrorMgr_ErrorNum_Max) 		), 		\
	DegManager_BiggerOf2Size(D_ldef_D_ErrorMgr_ErrorNum_Max,1) 	))


#define DegManager_MaxInputsize_BitPacked (((DegManager_MaxInputsize)/32)+1)



/* Function to translate array into Structure representation  :QM Controls */
/* Attn : Strongly advised to use the bitArray functions at the below portion of this file after you change internal matlab structures/c code to BitArray inputs */
static inline void DegManagerApp_ConvStruct_Type2_QM(FID_STRUCT_QM *pOutputFidStruct,RES_STRUCT_FEATURES_QM *pOutputResStruct,uint32 *pInpFid,uint32 *pInpRes) {
	uint16_t i;
	uint8 *pFidu8Ptr=(uint8 *)&pOutputFidStruct[0];
	uint8 *pResu8Ptr=(uint8 *)&pOutputResStruct[0];
	for(i=0u;i<(uint16_t)QM_FID_MAX;i++)
	{
		pFidu8Ptr[i]=DEGGetError_BitPacked_Rshd_1stbitPos(pInpFid,i);
	}
	for(i=0;i<(uint16_t)QM_RES_MAX;i++)
	{
		pResu8Ptr[i]=DEGGetError_BitPacked_Rshd_1stbitPos(pInpRes,i);
	}
}



/* Function to translate array into Structure representation  :B Controls */
/* Attn : Strongly advised to use the bitArray functions at the below portion of this file after you change internal matlab structures/c code to BitArray inputs */
static inline void DegManagerApp_ConvStruct_Type2_B(FID_STRUCT_B *pOutputFidStruct,RES_STRUCT_FEATURES_B *pOutputResStruct,uint32 *pInpFid,uint32 *pInpRes) {
	uint16_t i;
	uint8 *pFidu8Ptr=(uint8 *)&pOutputFidStruct[0];
	uint8 *pResu8Ptr=(uint8 *)&pOutputResStruct[0];
	for(i=0u;i<(uint16_t)B_FID_MAX;i++)
	{
		pFidu8Ptr[i]=DEGGetError_BitPacked_Rshd_1stbitPos(pInpFid,i);
	}
	for(i=0u;i<(uint16_t)B_RES_MAX;i++)
	{
		pResu8Ptr[i]=DEGGetError_BitPacked_Rshd_1stbitPos(pInpRes,i);
	}
}



/* Function to translate array into Structure representation  :QM Controls */
/* Attn : Strongly advised to use the bitArray functions at the below portion of this file after you change internal matlab structures/c code to BitArray inputs */
static inline void DegManagerApp_ConvStruct_QM(FID_STRUCT_QM *pOutputFidStruct,RES_STRUCT_FEATURES_QM *pOutputResStruct,DegManager_Output_QM_t *pInputDegMgrArray) { 
	uint32 *FidPtr=&pInputDegMgrArray->FID_Output[0];
	uint32 *ResPtr=&pInputDegMgrArray->RES_Output[0];
	DegManagerApp_ConvStruct_Type2_QM(pOutputFidStruct,pOutputResStruct,FidPtr,ResPtr);
}



/* Function to translate array into Structure representation  :B Controls */
/* Attn : Strongly advised to use the bitArray functions at the below portion of this file after you change internal matlab structures/c code to BitArray inputs */
static inline void DegManagerApp_ConvStruct_B(FID_STRUCT_B *pOutputFidStruct,RES_STRUCT_FEATURES_B *pOutputResStruct,DegManager_Output_B_t *pInputDegMgrArray) { 
	uint32 *FidPtr=&pInputDegMgrArray->FID_Output[0];
	uint32 *ResPtr=&pInputDegMgrArray->RES_Output[0];
	DegManagerApp_ConvStruct_Type2_B(pOutputFidStruct,pOutputResStruct,FidPtr,ResPtr);
}




/* Function to translate array into Structure representation  :QM Controls */
static inline void DegManagerApp_ConvStruct_BITARRAY_QM_Type2(FID_BIT_STRUCT_QM *pOutputFidStruct,RES_BIT_STRUCT_FEATURES_QM *pOutputResStruct,uint32 *pInpFid,uint32 *pInpRes) {
	(void)memcpy(pOutputFidStruct,pInpFid,sizeof(FID_BIT_STRUCT_QM));
	(void)memcpy(pOutputResStruct,pInpRes,sizeof(RES_BIT_STRUCT_FEATURES_QM));
}



/* Function to translate array into Structure representation  :B Controls */
static inline void DegManagerApp_ConvStruct_BITARRAY_B_Type2(FID_BIT_STRUCT_B *pOutputFidStruct,RES_BIT_STRUCT_FEATURES_B *pOutputResStruct,uint32 *pInpFid,uint32 *pInpRes) {
	(void)memcpy(pOutputFidStruct,pInpFid,sizeof(FID_BIT_STRUCT_B));
	(void)memcpy(pOutputResStruct,pInpRes,sizeof(RES_BIT_STRUCT_FEATURES_B));
}



/* Function to translate array into Structure representation  :QM Controls */
static inline void DegManagerApp_ConvStruct_BITARRAY_QM(FID_BIT_STRUCT_QM *pOutputFidStruct,RES_BIT_STRUCT_FEATURES_QM *pOutputResStruct,DegManager_Output_QM_t *pInputDegMgrArray) { 
	DegManagerApp_ConvStruct_BITARRAY_QM_Type2(pOutputFidStruct,pOutputResStruct,&pInputDegMgrArray->FID_Output[0],&pInputDegMgrArray->RES_Output[0]);
}



/* Function to translate array into Structure representation  :B Controls */
static inline void DegManagerApp_ConvStruct_BITARRAY_B(FID_BIT_STRUCT_B *pOutputFidStruct,RES_BIT_STRUCT_FEATURES_B *pOutputResStruct,DegManager_Output_B_t *pInputDegMgrArray) { 
	DegManagerApp_ConvStruct_BITARRAY_B_Type2(pOutputFidStruct,pOutputResStruct,&pInputDegMgrArray->FID_Output[0],&pInputDegMgrArray->RES_Output[0]);
}

#endif /* End Include Guard */
