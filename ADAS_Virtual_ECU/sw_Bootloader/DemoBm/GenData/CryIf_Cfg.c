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
 *            Module: CryIf
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CryIf_Cfg.c
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#define CRYIF_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "CryIf_Cfg.h"
#include "CryIf.h"
#include "Crypto_30_vHsm.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CRYIF_LOCAL)
# define CRYIF_LOCAL static
#endif

#if !defined (CRYIF_LOCAL_INLINE)
# define CRYIF_LOCAL_INLINE LOCAL_INLINE
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
  CryIf_Channel
**********************************************************************************************************************/
/** 
  \var    CryIf_Channel
  \brief  Contains parameters of /MICROSAR/CryIf/CryIfChannel.
  \details
  Element               Description
  DriverObjectRef       Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfChannel/CryIfDriverObjectRef.
  CryptoFunctionsIdx    the index of the 1:1 relation pointing to CryIf_CryptoFunctions
  Id                    Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfChannel/CryIfChannelId.
*/ 
#define CRYIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CryIf_ChannelType, CRYIF_CONST) CryIf_Channel[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DriverObjectRef                                          CryptoFunctionsIdx  Id        Referable Keys */
  { /*     0 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_Custom    ,                 0u, 0u },  /* [/ActiveEcuC/CryIf/CryIfChannel_vHsm_Custom, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_Custom:CsmChannelRef] */
  { /*     1 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_Hal       ,                 0u, 1u },  /* [/ActiveEcuC/CryIf/CryIfChannel_Hal, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Crypto30_vHsm_Hal:CsmChannelRef] */
  { /*     2 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_Core      ,                 0u, 2u },  /* [/ActiveEcuC/CryIf/CryIfChannel_vHsm_Core, /ActiveEcuC/CryIf] */
  { /*     3 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_GVCS      ,                 0u, 3u },  /* [/ActiveEcuC/CryIf/CryIfChannel_vHsm_GVCS, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Crypto30_vHsm_GVCS:CsmChannelRef] */
  { /*     4 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_KeyMRemote,                 0u, 4u },  /* [/ActiveEcuC/CryIf/CryIfChannel_vHsm_KeyMRemote, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_KeyMRemote:CsmChannelRef] */
  { /*     5 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_LibCv     ,                 0u, 5u }   /* [/ActiveEcuC/CryIf/CryIfChannel_vHsm_LibCv, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Crypto30_vHsm_LibCv:CsmChannelRef] */
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CryIf_CryptoFunctions
**********************************************************************************************************************/
/** 
  \var    CryIf_CryptoFunctions
  \details
  Element                          Description
  SupportsKeyElementCopyPartial
  CancelJob                    
  CertificateParse             
  CertificateVerify            
  KeyCopy                      
  KeyDerive                    
  KeyElementCopy               
  KeyElementCopyPartial        
  KeyElementGet                
  KeyElementIdsGet             
  KeyElementSet                
  KeyExchangeCalcPubVal        
  KeyExchangeCalcSecret        
  KeyGenerate                  
  KeyValidSet                  
  ProcessJob                   
  RandomSeed                   
*/ 
#define CRYIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CryIf_CryptoFunctionsType, CRYIF_CONST) CryIf_CryptoFunctions[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SupportsKeyElementCopyPartial  CancelJob                 CertificateParse                 CertificateVerify                 KeyCopy                 KeyDerive                 KeyElementCopy                 KeyElementCopyPartial                 KeyElementGet                 KeyElementIdsGet                 KeyElementSet                 KeyExchangeCalcPubVal                 KeyExchangeCalcSecret                 KeyGenerate                 KeyValidSet                 ProcessJob                 RandomSeed                       Referable Keys */
  { /*     0 */                          TRUE, Crypto_30_vHsm_CancelJob, Crypto_30_vHsm_CertificateParse, Crypto_30_vHsm_CertificateVerify, Crypto_30_vHsm_KeyCopy, Crypto_30_vHsm_KeyDerive, Crypto_30_vHsm_KeyElementCopy, Crypto_30_vHsm_KeyElementCopyPartial, Crypto_30_vHsm_KeyElementGet, Crypto_30_vHsm_KeyElementIdsGet, Crypto_30_vHsm_KeyElementSet, Crypto_30_vHsm_KeyExchangeCalcPubVal, Crypto_30_vHsm_KeyExchangeCalcSecret, Crypto_30_vHsm_KeyGenerate, Crypto_30_vHsm_KeyValidSet, Crypto_30_vHsm_ProcessJob, Crypto_30_vHsm_RandomSeed }   /* [/ActiveEcuC/Crypto_30_vHsm] */
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CryIf_Key
**********************************************************************************************************************/
/** 
  \var    CryIf_Key
  \brief  Contains parameters of /MICROSAR/CryIf/CryIfKey.
  \details
  Element               Description
  Ref                   Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfKey/CryIfKeyRef.
  CryptoFunctionsIdx    the index of the 1:1 relation pointing to CryIf_CryptoFunctions
*/ 
#define CRYIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CryIf_KeyType, CRYIF_CONST) CryIf_Key[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Ref                                                                  CryptoFunctionsIdx        Referable Keys */
  { /*     0 */ CryptoConf_CryptoKey_CryIfKey_UserSecureLog_Key                    ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_SecureLog, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SecureLog:CsmKeyRef] */
  { /*     1 */ CryptoConf_CryptoKey_CryIfKey_KeyMCertificate_ADA_L4               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_KeyMCertificate_ADA_L4, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyMCertificate_ADA_L4:CsmKeyRef] */
  { /*     2 */ CryptoConf_CryptoKey_CryIfKey_RoleFlag                             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_RoleFlag, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_RoleFlag:CsmKeyRef] */
  { /*     3 */ CryptoConf_CryptoKey_CryIfKey_RsaSignatureVerifyKey_ADA_L4         ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_RsaSignatureVerifyKey_ADA_L4, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_RsaSignatureVerifyKey_ADA_L4:CsmKeyRef] */
  { /*     4 */ CryptoConf_CryptoKey_CryIfKey_RsaSignatureVerifyKey_CodeSign_App_L4,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_RsaSignatureVerifyKey_CodeSign_App_L4, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_RsaSignatureVerifyKey_CodeSign_App_L4:CsmKeyRef] */
  { /*     5 */ CryptoConf_CryptoKey_CryIfKey_Sha256Result                         ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Sha256Result, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Sha256Result:CsmKeyRef] */
  { /*     6 */ CryptoConf_CryptoKey_StartApplication_CryptoKey_vHsm_MAC           ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Mac_Crypto_30_vHsm, /ActiveEcuC/CryIf] */
  { /*     7 */ CryptoConf_CryptoKey_Random                                        ,                 0u }   /* [/ActiveEcuC/CryIf/CryIfKey_Random, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Random:CsmKeyRef] */
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/





