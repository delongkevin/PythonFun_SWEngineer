/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Csm
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Csm_Cfg.c
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#define CSM_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Csm_Cfg.h"
#include "CryIf.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CSM_LOCAL)
# define CSM_LOCAL static
#endif

#if !defined (CSM_LOCAL_INLINE)
# define CSM_LOCAL_INLINE LOCAL_INLINE
#endif




/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Csm_JobInfo
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     JobInfo       Referable Keys */
  /*     0 */ {0u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_ReadDCLEntries] */
  /*     1 */ {1u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CalculateHash] */
  /*     2 */ {2u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Fca_HeaderVerify] */
  /*     3 */ {3u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate] */
  /*     4 */ {4u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_MacGenerate] */
  /*     5 */ {5u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_MacVerify] */
  /*     6 */ {6u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA] */
  /*     7 */ {7u, 0u}    /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TRNGGen] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobPrimitiveInfo
**********************************************************************************************************************/
/** 
  \var    Csm_JobPrimitiveInfo
  \brief  const uint32 callbackId; const Crypto_PrimitiveInfoType* primitiveInfo; const uint32 secureCounterId; const uint32 cryIfKeyId; const Crypto_ProcessingType processingType; const bool callbackUpdateNotification
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     JobPrimitiveInfo                                                                                                                                         Referable Keys */
  /*     0 */ {0u, &Csm_PrimitiveInfo[7], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Random, CRYPTO_PROCESSING_SYNC, FALSE}                                         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_ReadDCLEntries] */
  /*     1 */ {0u, &Csm_PrimitiveInfo[1], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_CryIfKey_Sha256Result, CRYPTO_PROCESSING_SYNC, FALSE}                          ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CalculateHash] */
  /*     2 */ {0u, &Csm_PrimitiveInfo[6], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_CryIfKey_RsaSignatureVerifyKey_CodeSign_App_L4, CRYPTO_PROCESSING_SYNC, FALSE} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Fca_HeaderVerify] */
  /*     3 */ {0u, &Csm_PrimitiveInfo[5], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_CryIfKey_KeyMCertificate_ADA_L4, CRYPTO_PROCESSING_SYNC, FALSE}                ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate] */
  /*     4 */ {0u, &Csm_PrimitiveInfo[3], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_SecureLog, CRYPTO_PROCESSING_SYNC, FALSE}                                      ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_MacGenerate] */
  /*     5 */ {0u, &Csm_PrimitiveInfo[4], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_SecureLog, CRYPTO_PROCESSING_SYNC, FALSE}                                      ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_MacVerify] */
  /*     6 */ {0u, &Csm_PrimitiveInfo[0], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_CryIfKey_RsaSignatureVerifyKey_ADA_L4, CRYPTO_PROCESSING_SYNC, FALSE}          ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA] */
  /*     7 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Random, CRYPTO_PROCESSING_SYNC, FALSE}                                            /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TRNGGen] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobTable
**********************************************************************************************************************/
/** 
  \var    Csm_JobTable
  \brief  Contains parameters of /MICROSAR/Csm/CsmJobs/CsmJob.
  \details
  Element        Description
  CsmKeyIdIdx    the index of the 1:1 relation pointing to one of Csm_Key
  Priority       Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPriority.
  QueueRefIdx    the index of the 1:1 relation pointing to one of Csm_QueueInfo
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_JobTableType, CSM_CONST) Csm_JobTable[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CsmKeyIdIdx  Priority  QueueRefIdx        Referable Keys */
  { /*     0 */          2u,       0u,          3u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_ReadDCLEntries, /ActiveEcuC/Csm/CsmJobs] */
  { /*     1 */          6u,       0u,          1u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CalculateHash, /ActiveEcuC/Csm/CsmJobs] */
  { /*     2 */          5u,       0u,          0u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Fca_HeaderVerify, /ActiveEcuC/Csm/CsmJobs] */
  { /*     3 */          1u,       0u,          4u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate, /ActiveEcuC/Csm/CsmJobs] */
  { /*     4 */          0u,       0u,          2u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_MacGenerate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/NvM/NvMBlockDescriptor_SecureLogGroup1:NvMCsmMacGenerationJobReference, /ActiveEcuC/NvM/NvMBlockDescriptor_SecureLogGroup2:NvMCsmMacGenerationJobReference] */
  { /*     5 */          0u,       0u,          2u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_MacVerify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/NvM/NvMBlockDescriptor_SecureLogGroup1:NvMCsmMacVerificationJobReference, /ActiveEcuC/NvM/NvMBlockDescriptor_SecureLogGroup2:NvMCsmMacVerificationJobReference] */
  { /*     6 */          4u,       0u,          2u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA, /ActiveEcuC/Csm/CsmJobs] */
  { /*     7 */          2u,       0u,          1u }   /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TRNGGen, /ActiveEcuC/Csm/CsmJobs] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Key
**********************************************************************************************************************/
/** 
  \var    Csm_Key
  \brief  Contains parameters of /AUTOSAR/EcucDefs/Csm/CsmKeys/CsmKey.
  \details
  Element       Description
  CryIfKeyId    Contains values of DefinitionRef: /MICROSAR/Csm/CsmKeys/CsmKey/CsmKeyRef.
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_KeyType, CSM_CONST) Csm_Key[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CryIfKeyId                                                                        Referable Keys */
  { /*     0 */ CryIfConf_CryIfKey_CryIfKey_SecureLog                                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SecureLog, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_MacGenerate:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_MacVerify:CsmJobKeyRef] */
  { /*     1 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_KeyMCertificate_ADA_L4                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyMCertificate_ADA_L4, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmAEADEncryptConfig/CsmAEADEncrypt/CsmAEADEncryptConfig:CsmAEADEncryptKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate:CsmJobKeyRef] */
  { /*     2 */ CryIfConf_CryIfKey_CryIfKey_Random                                         },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Random, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_ReadDCLEntries:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_TRNGGen:CsmJobKeyRef] */
  { /*     3 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_RoleFlag                              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_RoleFlag, /ActiveEcuC/Csm/CsmKeys] */
  { /*     4 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_RsaSignatureVerifyKey_ADA_L4          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_RsaSignatureVerifyKey_ADA_L4, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA:CsmJobKeyRef] */
  { /*     5 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_RsaSignatureVerifyKey_CodeSign_App_L4 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_RsaSignatureVerifyKey_CodeSign_App_L4, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Fca_HeaderVerify:CsmJobKeyRef] */
  { /*     6 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Sha256Result                          }   /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Sha256Result, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_CalculateHash:CsmJobKeyRef] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_PrimitiveInfo
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PrimitiveInfo                                                                                                                                                      Referable Keys */
  /*     0 */ {0u, CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_RSA, 256u, CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5, CRYPTO_ALGOFAM_SHA2_256}}                                          ,  /* [/ActiveEcuC/Csm/CsmPrimitives_CsmSignatureVerify/CsmSignatureVerify/CsmPrimitives_CsmSignatureVerify] */
  /*     1 */ {32u, CRYPTO_HASH, {CRYPTO_ALGOFAM_SHA2_256, 0u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}                                                            ,  /* [/ActiveEcuC/Csm/CsmPrimitives_CsmHash/CsmHash/CsmPrimitives_CsmHash] */
  /*     2 */ {32u, CRYPTO_RANDOMGENERATE, {CRYPTO_ALGOFAM_RNG, 0u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}                                                       ,  /* [/ActiveEcuC/Csm/CsmPrimitives_CsmTrng/CsmRandomGenerate/CsmPrimitives_CsmTrng] */
  /*     3 */ {16u, CRYPTO_MACGENERATE, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CMAC, CRYPTO_ALGOFAM_NOT_SET}}                                                            ,  /* [/ActiveEcuC/Csm/CsmPrimitives_CsmMacGenerate/CsmMacGenerate/CsmPrimitives_CsmMacGenerate] */
  /*     4 */ {0u, CRYPTO_MACVERIFY, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CMAC, CRYPTO_ALGOFAM_NOT_SET}}                                                               ,  /* [/ActiveEcuC/Csm/CsmPrimitives_CsmMacVerify/CsmMacVerify/CsmPrimitives_CsmMacVerify] */
  /*     5 */ {0u, CRYPTO_AEADENCRYPT, {170u, 16u, 141u, CRYPTO_ALGOFAM_NOT_SET} /*  Family = Crypto_30_vHsm_KeyM_vHsm_KeyM Mode = Crypto_30_vHsm_KeyM_CertElementGet  */ } ,  /* [/ActiveEcuC/Csm/CsmAEADEncryptConfig/CsmAEADEncrypt/CsmAEADEncryptConfig] */
  /*     6 */ {0u, CRYPTO_SIGNATUREVERIFY, {190, 256u, 178, 170}}                                                                                                           ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Fca_HeaderVerify/CsmSignatureVerify/CsmPrimitives_Fca_HeaderVerify] */
  /*     7 */ {1536u, CRYPTO_RANDOMGENERATE, {CRYPTO_ALGOFAM_CUSTOM, 0u, CRYPTO_ALGOMODE_CUSTOM, CRYPTO_ALGOFAM_NOT_SET}}                                                      /* [/ActiveEcuC/Csm/CsmPrimitives_ReadDCLEntries/CsmRandomGenerate/CsmPrimitives_ReadDCLEntries] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_QueueInfo
**********************************************************************************************************************/
/** 
  \var    Csm_QueueInfo
  \brief  Contains parameters of /AUTOSAR/EcucDefs/Csm/CsmQueues/CsmQueue.
  \details
  Element            Description
  ChannelId          Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmChannelRef.
  JobPoolStartIdx    the start index of the 0:n relation pointing to Csm_Job
  MaskedBits         contains bitcoded the boolean data of Csm_JobObjSynchronousUsedOfQueueInfo, Csm_JobPoolUsedOfQueueInfo, Csm_JobSharingOfQueueInfo
  QueueEndIdx        the end index of the 1:n relation pointing to Csm_Queue
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_QueueInfoType, CSM_CONST) Csm_QueueInfo[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ChannelId                                            JobPoolStartIdx  MaskedBits  QueueEndIdx        Referable Keys */
  { /*     0 */ CryIfConf_CryIfChannel_CryIfChannel_vHsm_GVCS      ,              3u,      0x07u,          4u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Crypto30_vHsm_GVCS, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Fca_HeaderVerify:CsmJobQueueRef] */
  { /*     1 */ CryIfConf_CryIfChannel_CryIfChannel_Hal            ,              1u,      0x07u,          2u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Crypto30_vHsm_Hal, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_CalculateHash:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_TRNGGen:CsmJobQueueRef] */
  { /*     2 */ CryIfConf_CryIfChannel_CryIfChannel_vHsm_LibCv     ,              0u,      0x07u,          1u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Crypto30_vHsm_LibCv, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_MacGenerate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_MacVerify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA:CsmJobQueueRef] */
  { /*     3 */ CryIfConf_CryIfChannel_CryIfChannel_vHsm_Custom    ,              4u,      0x07u,          5u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_Custom, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_ReadDCLEntries:CsmJobQueueRef] */
  { /*     4 */ CryIfConf_CryIfChannel_CryIfChannel_vHsm_KeyMRemote,              2u,      0x07u,          3u }   /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_KeyMRemote, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate:CsmJobQueueRef] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Job
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_JobType, CSM_VAR_NOINIT) Csm_Job[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [CsmQueue_Crypto30_vHsm_LibCv_AsyncPool, CsmQueue_Crypto30_vHsm_LibCv_SyncObj] */
  /*     1 */  /* [CsmQueue_Crypto30_vHsm_Hal_AsyncPool, CsmQueue_Crypto30_vHsm_Hal_SyncObj] */
  /*     2 */  /* [CsmQueue_vHsm_KeyMRemote_AsyncPool, CsmQueue_vHsm_KeyMRemote_SyncObj] */
  /*     3 */  /* [CsmQueue_Crypto30_vHsm_GVCS_AsyncPool, CsmQueue_Crypto30_vHsm_GVCS_SyncObj] */
  /*     4 */  /* [CsmQueue_vHsm_Custom_AsyncPool, CsmQueue_vHsm_Custom_SyncObj] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobState
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_JobStateType, CSM_VAR_NOINIT) Csm_JobState[8];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_ReadDCLEntries, /ActiveEcuC/Csm/CsmJobs] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CalculateHash, /ActiveEcuC/Csm/CsmJobs] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Fca_HeaderVerify, /ActiveEcuC/Csm/CsmJobs] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate, /ActiveEcuC/Csm/CsmJobs] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_MacGenerate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/NvM/NvMBlockDescriptor_SecureLogGroup1:NvMCsmMacGenerationJobReference, /ActiveEcuC/NvM/NvMBlockDescriptor_SecureLogGroup2:NvMCsmMacGenerationJobReference] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_MacVerify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/NvM/NvMBlockDescriptor_SecureLogGroup1:NvMCsmMacVerificationJobReference, /ActiveEcuC/NvM/NvMBlockDescriptor_SecureLogGroup2:NvMCsmMacVerificationJobReference] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA, /ActiveEcuC/Csm/CsmJobs] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TRNGGen, /ActiveEcuC/Csm/CsmJobs] */

#define CSM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobToObjMap
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_SizeOfJobType, CSM_VAR_NOINIT) Csm_JobToObjMap[8];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_ReadDCLEntries, /ActiveEcuC/Csm/CsmJobs] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CalculateHash, /ActiveEcuC/Csm/CsmJobs] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Fca_HeaderVerify, /ActiveEcuC/Csm/CsmJobs] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate, /ActiveEcuC/Csm/CsmJobs] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_MacGenerate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/NvM/NvMBlockDescriptor_SecureLogGroup1:NvMCsmMacGenerationJobReference, /ActiveEcuC/NvM/NvMBlockDescriptor_SecureLogGroup2:NvMCsmMacGenerationJobReference] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_MacVerify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/NvM/NvMBlockDescriptor_SecureLogGroup1:NvMCsmMacVerificationJobReference, /ActiveEcuC/NvM/NvMBlockDescriptor_SecureLogGroup2:NvMCsmMacVerificationJobReference] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA, /ActiveEcuC/Csm/CsmJobs] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_TRNGGen, /ActiveEcuC/Csm/CsmJobs] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Queue
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_QueueUType, CSM_VAR_NOINIT) Csm_Queue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Crypto30_vHsm_LibCv] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Crypto30_vHsm_Hal] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_KeyMRemote] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Crypto30_vHsm_GVCS] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_Custom] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_QueueState
**********************************************************************************************************************/
/** 
  \var    Csm_QueueState
  \brief  Stores state of the asynchronous job queue.
  \details
  Element     Description
  Lock    
  QueueIdx    the index of the 1:1 relation pointing to Csm_Queue
*/ 
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_QueueStateType, CSM_VAR_NOINIT) Csm_QueueState[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Crypto30_vHsm_GVCS, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Fca_HeaderVerify:CsmJobQueueRef] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Crypto30_vHsm_Hal, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_CalculateHash:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_TRNGGen:CsmJobQueueRef] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Crypto30_vHsm_LibCv, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_MacGenerate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_MacVerify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA:CsmJobQueueRef] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_Custom, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_ReadDCLEntries:CsmJobQueueRef] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_KeyMRemote, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate:CsmJobQueueRef] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/





