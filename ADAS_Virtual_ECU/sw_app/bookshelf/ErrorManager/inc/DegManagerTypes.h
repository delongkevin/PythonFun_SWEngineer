#ifndef DegManager_OutputTypes_IncludeGuard
#define DegManager_OutputTypes_IncludeGuard

#include "DegManagercfg.h"
#include "DegManagerGenEnTypes.h"

/* 3493, 3494, 1840, 1843 */ /* MD_MSR_Rule14.3, MD_MSR_Rule10.4 */
/*************************************** Justification *********************************************/
/*
 * 3493, 3494: No functional impact. Conditional check added to avoid any unintentional mistakes while updating the enums.
 * 1840, 1843: No functional impact. Assignment done as per code implementation.
 */

#define DEGMgr_GetBytePos(enVal) ((uint32_t)(enVal)/32)
#define DEGMgr_GetBitPos(enVal)  ((uint32_t)(enVal)%32)

#define DEGSetError_BitPacked(arr,enVal)                    ((uint32_t *)(arr))[(uint16_t)DEGMgr_GetBytePos((enVal))] |= (uint32_t)((uint32_t)0x00000001 << (uint32_t)DEGMgr_GetBitPos((enVal)))
#define DEGGetError_BitPacked(arr,enVal)                    (((uint32_t *)(arr))[(uint16_t)DEGMgr_GetBytePos((enVal))] & ((uint32_t)0x00000001 << (uint32_t)DEGMgr_GetBitPos((enVal))))
#define DEGGetError_BitPacked_Rshd_1stbitPos(arr,enVal)     (uint8_t)((DEGGetError_BitPacked(arr,enVal))>>(DEGMgr_GetBitPos(enVal)))

//divide by 32 and add 1 if remained is 1
#define DEGMANAGER_GETPACKEDSIZE(x)  (uint32_t)(((uint32_t)(x)>>5u) + (((uint32_t)(x)&(uint32_t)0x1F)!=0?(uint32_t)1:(uint32_t)0))


#define DegManager_Function_NonInhibited 0x00u
#define DegManager_Function_Inhibitted 0x01u

#define DegManager_Reason_InActive 0x00u
#define DegManager_Reason_Active  0x01u


#if DEGMANAGER_QM_LEVEL_ACTIVE == 1u
typedef struct 
{
    uint32_t FID_Output[DEGMANAGER_GETPACKEDSIZE((uint16_t)QM_FID_MAX == (uint16_t)0 ? (uint16_t)1: (uint16_t)QM_FID_MAX)];
    uint32_t RES_Output[DEGMANAGER_GETPACKEDSIZE((uint16_t)QM_RES_MAX == (uint16_t)0 ? (uint16_t)1: (uint16_t)QM_RES_MAX)];
}DegManager_Output_QM_t;
#endif

#if DEGMANAGER_A_LEVEL_ACTIVE == 1u
typedef struct 
{
    uint32_t FID_Output[DEGMANAGER_GETPACKEDSIZE(A_FID_MAX == 0 ?1: A_FID_MAX)];
    uint32_t RES_Output[DEGMANAGER_GETPACKEDSIZE(A_RES_MAX == 0 ?1: A_RES_MAX)];
}DegManager_Output_A_t;
#endif

#if DEGMANAGER_B_LEVEL_ACTIVE == 1u
typedef struct 
{
    uint32_t FID_Output[DEGMANAGER_GETPACKEDSIZE((uint16_t)B_FID_MAX == (uint16_t)0 ? (uint16_t)1: (uint16_t)B_FID_MAX)];
    uint32_t RES_Output[DEGMANAGER_GETPACKEDSIZE((uint16_t)B_RES_MAX == (uint16_t)0 ? (uint16_t)1: (uint16_t)B_RES_MAX)];
}DegManager_Output_B_t;
#endif

#if DEGMANAGER_C_LEVEL_ACTIVE == 1u
typedef struct 
{
    uint32_t FID_Output[DEGMANAGER_GETPACKEDSIZE(C_FID_MAX == 0 ?1: C_FID_MAX)];
    uint32_t RES_Output[DEGMANAGER_GETPACKEDSIZE(C_RES_MAX == 0 ?1: C_RES_MAX)];
}DegManager_Output_C_t;
#endif

#if DEGMANAGER_D_LEVEL_ACTIVE == 1u
typedef struct 
{
    uint32_t FID_Output[DEGMANAGER_GETPACKEDSIZE(D_FID_MAX == 0 ?1: D_FID_MAX)];
    uint32_t RES_Output[DEGMANAGER_GETPACKEDSIZE(D_RES_MAX == 0 ?1: D_RES_MAX)];
}DegManager_Output_D_t;
#endif


typedef struct 
{
    uint32_t Errors_InvalidIndexInto_ErrorInput;
}DegManager_DiagnosticDebugErrorCount;





#endif
