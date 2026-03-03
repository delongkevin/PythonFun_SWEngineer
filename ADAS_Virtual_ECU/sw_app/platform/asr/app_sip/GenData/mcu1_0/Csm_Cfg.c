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
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Csm_Cfg.c
 *   Generation Time: 2024-03-11 14:16:13
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
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
  Csm_BswCallbacks
**********************************************************************************************************************/
/** 
  \var    Csm_BswCallbacks
  \details
  Element           Description
  CallbackFunc44
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_BswCallbacksType, CSM_CONST) Csm_BswCallbacks[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CallbackFunc44                     Referable Keys */
  { /*     0 */ CsmCallbackFunc_CsmCallback }   /* [/ActiveEcuC/Csm/CsmCallbacks/CsmCallback] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Callout
**********************************************************************************************************************/
/** 
  \var    Csm_Callout
  \brief  Contains parameters of /MICROSAR/Csm/CsmCallouts/CsmCallout.
  \details
  Element               Description
  PostJobCalloutFunc    Contains values of DefinitionRef: /MICROSAR/Csm/CsmCallouts/CsmCallout/CsmPostJobCalloutFunc.
  PreJobCalloutFunc     Contains values of DefinitionRef: /MICROSAR/Csm/CsmCallouts/CsmCallout/CsmPreJobCalloutFunc.
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_CalloutType, CSM_CONST) Csm_Callout[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PostJobCalloutFunc                             PreJobCalloutFunc                                   Referable Keys */
  { /*     0 */ CsmPostJobCalloutFunc_CsmCallout_ADASigVerify, CsmPreJobCalloutFunc_CsmCallout_ADASigVerify }   /* [/ActiveEcuC/Csm/CsmCallout/CsmCallout, /ActiveEcuC/Csm/CsmCallout, /ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA:CsmJobCalloutRef] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

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
  /*     1 */ {1u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CsmHash] */
  /*     2 */ {2u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate] */
  /*     3 */ {3u, 1u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Random] */
  /*     4 */ {4u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacGen] */
  /*     5 */ {5u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacVerify] */
  /*     6 */ {6u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify] */
  /*     7 */ {7u, 0u}    /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA] */
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
  /* Index     JobPrimitiveInfo                                                                                                                                Referable Keys */
  /*     0 */ {0u, &Csm_PrimitiveInfo[6], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_CryIfKey_KeyMCertificate_ADA_L4, CRYPTO_PROCESSING_SYNC, FALSE}       ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_ReadDCLEntries] */
  /*     1 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_RSAKey, CRYPTO_PROCESSING_SYNC, FALSE}                                         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CsmHash] */
  /*     2 */ {0u, &Csm_PrimitiveInfo[0], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_CryIfKey_KeyMCertificate_ADA_L4, CRYPTO_PROCESSING_SYNC, FALSE}       ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate] */
  /*     3 */ {0u, &Csm_PrimitiveInfo[3], 0x000000FFu, CryIfConf_CryIfKey_Random, CRYPTO_PROCESSING_SYNC, FALSE}                                         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Random] */
  /*     4 */ {0u, &Csm_PrimitiveInfo[4], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_SecureLog, CRYPTO_PROCESSING_SYNC, FALSE}                             ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacGen] */
  /*     5 */ {0u, &Csm_PrimitiveInfo[5], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_SecureLog, CRYPTO_PROCESSING_SYNC, FALSE}                             ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacVerify] */
  /*     6 */ {0u, &Csm_PrimitiveInfo[1], 0x000000FFu, CryIfConf_CryIfKey_RSAKey, CRYPTO_PROCESSING_ASYNC, FALSE}                                        ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify] */
  /*     7 */ {0u, &Csm_PrimitiveInfo[1], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_CryIfKey_RsaSignatureVerifyKey_ADA_L4, CRYPTO_PROCESSING_SYNC, FALSE}    /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA] */
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
  Element            Description
  BswCallbacksIdx    the index of the 0:1 relation pointing to Csm_BswCallbacks
  CalloutInfoIdx     the index of the 0:1 relation pointing to Csm_CalloutInfo
  CsmKeyIdIdx        the index of the 1:1 relation pointing to one of Csm_Key
  MaskedBits         contains bitcoded the boolean data of Csm_AsynchronousOfJobTable, Csm_BswCallbacksUsedOfJobTable, Csm_CalloutInfoUsedOfJobTable, Csm_PrimitiveCallbackUpdateNotificationOfJobTable
  Priority           Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPriority.
  QueueRefIdx        the index of the 1:1 relation pointing to one of Csm_QueueInfo
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_JobTableType, CSM_CONST) Csm_JobTable[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BswCallbacksIdx                   CalloutInfoIdx                   CsmKeyIdIdx  MaskedBits  Priority  QueueRefIdx        Referable Keys */
  { /*     0 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE, CSM_NO_CALLOUTINFOIDXOFJOBTABLE,          1u,      0x00u,       0u,          0u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_ReadDCLEntries, /ActiveEcuC/Csm/CsmJobs] */
  { /*     1 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE, CSM_NO_CALLOUTINFOIDXOFJOBTABLE,          2u,      0x00u,       0u,          4u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CsmHash, /ActiveEcuC/Csm/CsmJobs] */
  { /*     2 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE, CSM_NO_CALLOUTINFOIDXOFJOBTABLE,          1u,      0x00u,       0u,          3u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate, /ActiveEcuC/Csm/CsmJobs] */
  { /*     3 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE, CSM_NO_CALLOUTINFOIDXOFJOBTABLE,          3u,      0x00u,       1u,          2u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Random, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vDiagSecAcc/vDiagSecAccGeneral:vDiagSecAccRandomGenerateJobRef] */
  { /*     4 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE, CSM_NO_CALLOUTINFOIDXOFJOBTABLE,          7u,      0x00u,       0u,          2u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacGen, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/NvM/CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup1:NvMCsmMacGenerationJobReference, /ActiveEcuC/NvM/CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup2:NvMCsmMacGenerationJobReference] */
  { /*     5 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE, CSM_NO_CALLOUTINFOIDXOFJOBTABLE,          7u,      0x00u,       0u,          2u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacVerify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/NvM/CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup1:NvMCsmMacVerificationJobReference, /ActiveEcuC/NvM/CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup2:NvMCsmMacVerificationJobReference] */
  { /*     6 */                               0u, CSM_NO_CALLOUTINFOIDXOFJOBTABLE,          2u,      0x0Cu,       0u,          4u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify, /ActiveEcuC/Csm/CsmJobs] */
  { /*     7 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,                              0u,          5u,      0x02u,       0u,          4u }   /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vDiagSecAcc/vDiagSecAccSecurityLevels/vDiagSecAccSecurityLevel:vDiagSecAccCompareKeyCsmJobRef] */
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
CONST(Csm_KeyType, CSM_CONST) Csm_Key[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CryIfKeyId                                                               Referable Keys */
  { /*     0 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_CurrentTimeStamp             },  /* [/ActiveEcuC/Csm/CsmKey/CsmKey_CurrentTimeStamp, /ActiveEcuC/Csm/CsmKey] */
  { /*     1 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_KeyMCertificate_ADA_L4       },  /* [/ActiveEcuC/Csm/CsmKey/CsmKey_KeyMCertificate_ADA_L4, /ActiveEcuC/Csm/CsmKey, /ActiveEcuC/Csm/CsmAEADEncryptConfig/CsmAEADEncrypt/CsmAEADEncryptConfig:CsmAEADEncryptKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_ReadDCLEntries:CsmJobKeyRef] */
  { /*     2 */ CryIfConf_CryIfKey_RSAKey                                         },  /* [/ActiveEcuC/Csm/CsmKey/CsmKey_RSAKey, /ActiveEcuC/Csm/CsmKey, /ActiveEcuC/Csm/CsmJobs/CsmJob_CsmHash:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify:CsmJobKeyRef] */
  { /*     3 */ CryIfConf_CryIfKey_Random                                         },  /* [/ActiveEcuC/Csm/CsmKey/CsmKey_Random, /ActiveEcuC/Csm/CsmKey, /ActiveEcuC/Csm/CsmJobs/CsmJob_Random:CsmJobKeyRef] */
  { /*     4 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_RoleFlag                     },  /* [/ActiveEcuC/Csm/CsmKey/CsmKey_RoleFlag, /ActiveEcuC/Csm/CsmKey] */
  { /*     5 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_RsaSignatureVerifyKey_ADA_L4 },  /* [/ActiveEcuC/Csm/CsmKey/CsmKey_RsaSignatureVerifyKey_ADA_L4, /ActiveEcuC/Csm/CsmKey, /ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA:CsmJobKeyRef] */
  { /*     6 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_SecondCounter                },  /* [/ActiveEcuC/Csm/CsmKey/CsmKey_SecondCounter, /ActiveEcuC/Csm/CsmKey] */
  { /*     7 */ CryIfConf_CryIfKey_CryIfKey_SecureLog                             }   /* [/ActiveEcuC/Csm/CsmKey/CsmKey_SecureLog, /ActiveEcuC/Csm/CsmKey, /ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacGen:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacVerify:CsmJobKeyRef] */
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
CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PrimitiveInfo                                                                                                                                                      Referable Keys */
  /*     0 */ {0u, CRYPTO_AEADENCRYPT, {170u, 16u, 141u, CRYPTO_ALGOFAM_NOT_SET} /*  Family = Crypto_30_vHsm_KeyM_vHsm_KeyM Mode = Crypto_30_vHsm_KeyM_CertElementGet  */ } ,  /* [/ActiveEcuC/Csm/CsmAEADEncryptConfig/CsmAEADEncrypt/CsmAEADEncryptConfig] */
  /*     1 */ {0u, CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_RSA, 256u, CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5, CRYPTO_ALGOFAM_SHA2_256}}                                          ,  /* [/ActiveEcuC/Csm/CsmPrimitives_CsmSignatureVerify_ADA/CsmPrimitives_CsmSignatureVerify/CsmPrimitives_CsmSignatureVerify_ADA, /ActiveEcuC/Csm/CsmPrimitives_CsmSignatureVerify/CsmPrimitives_CsmSignatureVerify/CsmPrimitives_CsmSignatureVerify] */
  /*     2 */ {32u, CRYPTO_HASH, {CRYPTO_ALGOFAM_SHA2_256, 0u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}                                                            ,  /* [/ActiveEcuC/Csm/CsmPrimitives_CsmHash/CsmPrimitives_CsmHash/CsmPrimitives_CsmHash] */
  /*     3 */ {32u, CRYPTO_RANDOMGENERATE, {CRYPTO_ALGOFAM_RNG, 0u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}                                                       ,  /* [/ActiveEcuC/Csm/CsmPrimitives_RandomTrng/CsmRandomGenerate/CsmPrimitives_RandomTrng] */
  /*     4 */ {16u, CRYPTO_MACGENERATE, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CMAC, CRYPTO_ALGOFAM_NOT_SET}}                                                            ,  /* [/ActiveEcuC/Csm/CsmPrimitives_SecureLog_CMAC/CsmMacGenerate/CsmPrimitives_SecureLog_CMAC] */
  /*     5 */ {0u, CRYPTO_MACVERIFY, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CMAC, CRYPTO_ALGOFAM_NOT_SET}}                                                               ,  /* [/ActiveEcuC/Csm/CsmPrimitives_CMACVerify/CsmMacVerify/CsmPrimitives_CMACVerify] */
  /*     6 */ {1536u, CRYPTO_RANDOMGENERATE, {CRYPTO_ALGOFAM_CUSTOM, 0u, CRYPTO_ALGOMODE_CUSTOM, CRYPTO_ALGOFAM_NOT_SET}}                                                      /* [/ActiveEcuC/Csm/CsmPrimitives_ReadDCLEntries/CsmRandomGenerate/CsmPrimitives_ReadDCLEntries] */
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
  Element                 Description
  ChannelId               Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmChannelRef.
  JobObjSynchronousIdx    the index of the 0:1 relation pointing to Csm_Job
  JobPoolEndIdx           the end index of the 0:n relation pointing to Csm_Job
  JobPoolStartIdx         the start index of the 0:n relation pointing to Csm_Job
  MaskedBits              contains bitcoded the boolean data of Csm_JobObjSynchronousUsedOfQueueInfo, Csm_JobPoolUsedOfQueueInfo, Csm_JobSharingOfQueueInfo
  QueueEndIdx             the end index of the 1:n relation pointing to Csm_Queue
  QueueStartIdx           the start index of the 1:n relation pointing to Csm_Queue
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_QueueInfoType, CSM_CONST) Csm_QueueInfo[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ChannelId                                            JobObjSynchronousIdx  JobPoolEndIdx  JobPoolStartIdx  MaskedBits  QueueEndIdx  QueueStartIdx        Referable Keys */
  { /*     0 */ CryIfConf_CryIfChannel_CryIfChannel_VHsm_Custom    ,                   6u,            7u,              6u,      0x07u,          6u,            5u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Custom, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_ReadDCLEntries:CsmJobQueueRef] */
  { /*     1 */ CryIfConf_CryIfChannel_CryIfChannel_vHsm_Core      ,                   1u,            2u,              1u,      0x07u,          2u,            1u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_Core, /ActiveEcuC/Csm/CsmQueues] */
  { /*     2 */ CryIfConf_CryIfChannel_CryIfChannel_vHsm_Hal       ,                   0u,            1u,              0u,      0x07u,          1u,            0u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_Hal, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Random:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacGen:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacVerify:CsmJobQueueRef] */
  { /*     3 */ CryIfConf_CryIfChannel_CryIfChannel_vHsm_KeyMRemote,                   2u,            3u,              2u,      0x07u,          3u,            2u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_KeyMRemote, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate:CsmJobQueueRef] */
  { /*     4 */ CryIfConf_CryIfChannel_CryIfChannel_vHsm_LibCv     ,                   3u,            6u,              4u,      0x07u,          5u,            3u }   /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_LibCv, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_CsmHash:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA:CsmJobQueueRef] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_CalloutState
**********************************************************************************************************************/
/** 
  \var    Csm_CalloutState
  \brief  Holds current state of the pre and post job callout processing.
  \details
  Element         Description
  CalloutState
*/ 
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_CalloutStateUType, CSM_VAR_NOINIT) Csm_CalloutState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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
VAR(Crypto_JobType, CSM_VAR_NOINIT) Csm_Job[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [CsmQueue_vHsm_Hal_AsyncPool, CsmQueue_vHsm_Hal_SyncObj] */
  /*     1 */  /* [CsmQueue_vHsm_Core_AsyncPool, CsmQueue_vHsm_Core_SyncObj] */
  /*     2 */  /* [CsmQueue_vHsm_KeyMRemote_AsyncPool, CsmQueue_vHsm_KeyMRemote_SyncObj] */
  /*     3 */  /* [CsmQueue_vHsm_LibCv_SyncObj] */
  /*     4 */  /* [CsmQueue_vHsm_LibCv_AsyncPool] */
  /*     5 */  /* [CsmQueue_vHsm_LibCv_AsyncPool] */
  /*     6 */  /* [CsmQueue_Custom_AsyncPool, CsmQueue_Custom_SyncObj] */

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
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CsmHash, /ActiveEcuC/Csm/CsmJobs] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate, /ActiveEcuC/Csm/CsmJobs] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Random, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vDiagSecAcc/vDiagSecAccGeneral:vDiagSecAccRandomGenerateJobRef] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacGen, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/NvM/CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup1:NvMCsmMacGenerationJobReference, /ActiveEcuC/NvM/CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup2:NvMCsmMacGenerationJobReference] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacVerify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/NvM/CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup1:NvMCsmMacVerificationJobReference, /ActiveEcuC/NvM/CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup2:NvMCsmMacVerificationJobReference] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify, /ActiveEcuC/Csm/CsmJobs] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vDiagSecAcc/vDiagSecAccSecurityLevels/vDiagSecAccSecurityLevel:vDiagSecAccCompareKeyCsmJobRef] */

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
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CsmHash, /ActiveEcuC/Csm/CsmJobs] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate, /ActiveEcuC/Csm/CsmJobs] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Random, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vDiagSecAcc/vDiagSecAccGeneral:vDiagSecAccRandomGenerateJobRef] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacGen, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/NvM/CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup1:NvMCsmMacGenerationJobReference, /ActiveEcuC/NvM/CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup2:NvMCsmMacGenerationJobReference] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacVerify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/NvM/CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup1:NvMCsmMacVerificationJobReference, /ActiveEcuC/NvM/CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup2:NvMCsmMacVerificationJobReference] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify, /ActiveEcuC/Csm/CsmJobs] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vDiagSecAcc/vDiagSecAccSecurityLevels/vDiagSecAccSecurityLevel:vDiagSecAccCompareKeyCsmJobRef] */

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
  /*     0 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_Hal] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_Core] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_KeyMRemote] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_LibCv] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_LibCv] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Custom] */

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
  /*     0 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Custom, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_ReadDCLEntries:CsmJobQueueRef] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_Core, /ActiveEcuC/Csm/CsmQueues] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_Hal, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Random:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacGen:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SecureLog_MacVerify:CsmJobQueueRef] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_KeyMRemote, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_GetRoleFromTesterCertificate:CsmJobQueueRef] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_LibCv, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_CsmHash:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SignatureVerify_ADA:CsmJobQueueRef] */

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





