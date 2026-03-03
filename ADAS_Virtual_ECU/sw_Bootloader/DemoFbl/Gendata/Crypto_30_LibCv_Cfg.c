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
 *            Module: Crypto_30_LibCv
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D06
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_LibCv_Cfg.c
 *   Generation Time: 2023-03-30 16:30:29
 *           Project: DemoFbl - Version 1.0
 *          Delivery: CBD2101146_D06
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#define CRYPTO_30_LIBCV_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_LibCv_Cfg.h"
#include "Crypto_30_LibCv.h"
#include "Crypto_30_LibCv_Services.h"
/* PRQA S 0759 EOF */ /* MD_CSL_18.4 */
/*lint -e91 */
#include "Crypto_30_LibCv_Hash.h"
#include "Crypto_30_LibCv_MacGenerate.h"
#include "Crypto_30_LibCv_MacVerify.h"
#include "Crypto_30_LibCv_RandomGenerate.h"
#include "Crypto_30_LibCv_SignatureVerify.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CRYPTO_30_LIBCV_LOCAL)
# define CRYPTO_30_LIBCV_LOCAL static
#endif

#if !defined (CRYPTO_30_LIBCV_LOCAL_INLINE)
# define CRYPTO_30_LIBCV_LOCAL_INLINE LOCAL_INLINE
#endif




/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Crypto_30_LibCv_CmacAesGenerate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_CmacAesGenerate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_CmacAesGenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_CmacAesGenerate[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                              Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_Crypto_30_LibCv.primWS.CmacAesGenerate }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_CmacAesVerify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_CmacAesVerify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_CmacAesVerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_CmacAesVerify[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                            Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_Crypto_30_LibCv.primWS.CmacAesVerify }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Fips186
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Fips186
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_Fips186Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Fips186[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                      Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_Crypto_30_LibCv.primWS.Fips186 }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_InitValue
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_InitValueType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_InitValue[41] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitValue      Referable Keys */
  /*     0 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*     1 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*     2 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*     3 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*     4 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*     5 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*     6 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*     7 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*     8 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*     9 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*    10 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*    11 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*    12 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*    13 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*    14 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*    15 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*    16 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*    17 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*    18 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*    19 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  /*    20 */         4u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES256] */
  /*    21 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Reseed_Counter] */
  /*    22 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Reseed_Counter] */
  /*    23 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Reseed_Counter] */
  /*    24 */         1u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Reseed_Counter] */
  /*    25 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  /*    26 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  /*    27 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  /*    28 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  /*    29 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  /*    30 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  /*    31 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  /*    32 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  /*    33 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  /*    34 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  /*    35 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  /*    36 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  /*    37 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  /*    38 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  /*    39 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  /*    40 */         0u   /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Key
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Key
  \details
  Element                Description
  KeyElementsEndIdx      the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyElements
  KeyElementsStartIdx    the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyElements
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Key[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    KeyElementsEndIdx  KeyElementsStartIdx        Referable Keys */
  { /*     0 */                2u,                  0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_MCU1VerificationKey] */
  { /*     1 */                3u,                  2u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_SHA256Key] */
  { /*     2 */                8u,                  3u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Random] */
  { /*     3 */                9u,                  8u }   /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Mac] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyElementInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyElementInfo
  \details
  Element              Description
  Id               
  Length           
  InitValueEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_InitValue
  InitValueStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_InitValue
  MaskedBits           contains bitcoded the boolean data of Crypto_30_LibCv_OnceOfKeyElementInfo, Crypto_30_LibCv_PartialOfKeyElementInfo, Crypto_30_LibCv_PersistOfKeyElementInfo
  Read             
  Write            
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyElementInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElementInfo[9] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id     Length  InitValueEndIdx                                     InitValueStartIdx                                     MaskedBits  Read                        Write                             Referable Keys */
  { /*     0 */  160u,    16u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Rsa_Modulus] */
  { /*     1 */  161u,   256u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Rsa_Pub_Exponent] */
  { /*     2 */    1u,    20u,                                                20u,                                                   0u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  { /*     3 */    3u,    48u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,      0x00u, CRYPTO_30_LIBCV_RA_DENIED , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES256] */
  { /*     4 */    4u,     1u,                                                21u,                                                  20u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES256] */
  { /*     5 */ 3015u,    16u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_PrivateString] */
  { /*     6 */ 3016u,    32u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_AdditionalInput] */
  { /*     7 */ 3018u,     4u,                                                25u,                                                  21u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_DENIED  },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Reseed_Counter] */
  { /*     8 */    1u,    16u,                                                41u,                                                  25u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED }   /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyElements
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyElements
  \details
  Element                            Description
  Id                             
  KeyStorageEndIdx                   the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageExtensionIdx             the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageStartIdx                 the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageValidIdx                 the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageWrittenLengthEndIdx      the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageWrittenLengthStartIdx    the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyElementInfoIdx                  the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyElementInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyElementsType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElements[9] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id     KeyStorageEndIdx  KeyStorageExtensionIdx  KeyStorageStartIdx  KeyStorageValidIdx  KeyStorageWrittenLengthEndIdx  KeyStorageWrittenLengthStartIdx  KeyElementInfoIdx        Referable Keys */
  { /*     0 */  160u,              20u,                     3u,                 4u,                 2u,                            2u,                              0u,                0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_MCU1VerificationKey, CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Modulus] */
  { /*     1 */  161u,             280u,                    23u,                24u,                22u,                           22u,                             20u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_MCU1VerificationKey, CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Pub_Exponent] */
  { /*     2 */    1u,             304u,                   283u,               284u,               282u,                          282u,                            280u,                2u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_SHA256Key, CryptoKey_SHA256Key__Crypto_30_LibCv_Hash_Result] */
  { /*     3 */    3u,             356u,                   307u,               308u,               306u,                          306u,                            304u,                3u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Random, CryptoKey_Random__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES256] */
  { /*     4 */    4u,             361u,                   359u,               360u,               358u,                          358u,                            356u,                4u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Random, CryptoKey_Random__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES256] */
  { /*     5 */ 3015u,             381u,                   364u,               365u,               363u,                          363u,                            361u,                5u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Random, CryptoKey_Random__Crypto_30_LibCv_Random_PrivateString] */
  { /*     6 */ 3016u,             417u,                   384u,               385u,               383u,                          383u,                            381u,                6u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Random, CryptoKey_Random__Crypto_30_LibCv_Random_AdditionalInput] */
  { /*     7 */ 3018u,             425u,                   420u,               421u,               419u,                          419u,                            417u,                7u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Random, CryptoKey_Random__Crypto_30_LibCv_Random_Reseed_Counter] */
  { /*     8 */    1u,             445u,                   428u,               429u,               427u,                          427u,                            425u,                8u }   /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Mac, CryptoKey_Mac__Crypto_30_LibCv_Mac_Key] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_ObjectInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_ObjectInfo
  \details
  Element                     Description
  WorkspaceLength             Holds the length of the workspace.
  CmacAesGenerateIdx          the index of the 0:1 relation pointing to Crypto_30_LibCv_CmacAesGenerate
  CmacAesVerifyIdx            the index of the 0:1 relation pointing to Crypto_30_LibCv_CmacAesVerify
  Fips186Idx                  the index of the 0:1 relation pointing to Crypto_30_LibCv_Fips186
  QueueIdx                    the index of the 1:1 relation pointing to Crypto_30_LibCv_Queue
  RandomSeedBufferEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_RandomSeedBuffer
  RandomSeedBufferStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_RandomSeedBuffer
  RsaPkcs1VerifyIdx           the index of the 0:1 relation pointing to Crypto_30_LibCv_RsaPkcs1Verify
  SHA256Idx                   the index of the 0:1 relation pointing to Crypto_30_LibCv_SHA256
  WorkspaceAddr               Holds the address of the workspace.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_ObjectInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    WorkspaceLength                                  CmacAesGenerateIdx  CmacAesVerifyIdx  Fips186Idx  QueueIdx  RandomSeedBufferEndIdx  RandomSeedBufferStartIdx  RsaPkcs1VerifyIdx  SHA256Idx  WorkspaceAddr                                                                                        Referable Keys */
  { /*     0 */ sizeof(Crypto_30_LibCv_WS_Crypto_30_LibCv_Type),                 0u,               0u,         0u,       0u,                    21u,                       0u,                0u,        0u, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_UnionWS_Crypto_30_LibCv }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, SHA256, CmacAesGenerate, CmacAesVerify, Fips186, RsaPkcs1Verify] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_ObjectInfoInd
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_ObjectInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Crypto_30_LibCv_ObjectInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_ObjectInfoIndType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfoInd[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ObjectInfoInd      Referable Keys */
  /*     0 */             0u,  /* [SHA256] */
  /*     1 */             0u,  /* [CmacAesGenerate] */
  /*     2 */             0u,  /* [CmacAesVerify] */
  /*     3 */             0u,  /* [Fips186] */
  /*     4 */             0u   /* [RsaPkcs1Verify] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PrimitiveFct
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PrimitiveFct
  \details
  Element                  Description
  ObjectInfoIndEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_ObjectInfoInd
  ObjectInfoIndStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_ObjectInfoInd
  Dispatch             
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_PrimitiveFctType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveFct[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ObjectInfoIndEndIdx  ObjectInfoIndStartIdx  Dispatch                                        Referable Keys */
  { /*     0 */                  1u,                    0u, Crypto_30_LibCv_Dispatch_SHA256          },  /* [SHA256] */
  { /*     1 */                  2u,                    1u, Crypto_30_LibCv_Dispatch_CmacAesGenerate },  /* [CmacAesGenerate] */
  { /*     2 */                  3u,                    2u, Crypto_30_LibCv_Dispatch_CmacAesVerify   },  /* [CmacAesVerify] */
  { /*     3 */                  4u,                    3u, Crypto_30_LibCv_Dispatch_Fips186         },  /* [Fips186] */
  { /*     4 */                  5u,                    4u, Crypto_30_LibCv_Dispatch_RsaPkcs1Verify  }   /* [RsaPkcs1Verify] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PrimitiveInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PrimitiveInfo
  \details
  Element            Description
  Combined       
  MaskedBits         contains bitcoded the boolean data of Crypto_30_LibCv_ContextOfPrimitiveInfo, Crypto_30_LibCv_DefaultRandomSourceOfPrimitiveInfo
  PrimitiveFctIdx    the index of the 1:1 relation pointing to Crypto_30_LibCv_PrimitiveFct
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_PrimitiveInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveInfo[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Combined                                                                                                                                                                    MaskedBits  PrimitiveFctIdx        Referable Keys */
  { /*     0 */ ((((uint32)CRYPTO_HASH) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA2_256) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                 ,      0x00u,              0u },  /* [CRYPTO_HASH] */
  { /*     1 */ ((((uint32)CRYPTO_MACGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                  ,      0x00u,              1u },  /* [CRYPTO_MACGENERATE] */
  { /*     2 */ ((((uint32)CRYPTO_MACVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                    ,      0x00u,              2u },  /* [CRYPTO_MACVERIFY] */
  { /*     3 */ ((((uint32)CRYPTO_RANDOMGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_RNG) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))            ,      0x00u,              3u },  /* [CRYPTO_RANDOMGENERATE] */
  { /*     4 */ ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_RSA) << 16) | (((uint32)CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_256)),      0x00u,              4u }   /* [CRYPTO_SIGNATUREVERIFY] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PrimitiveServiceInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PrimitiveServiceInfo
  \details
  Element                  Description
  PrimitiveInfoEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_PrimitiveInfo
  PrimitiveInfoStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_PrimitiveInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_PrimitiveServiceInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveServiceInfo[20] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PrimitiveInfoEndIdx                                           PrimitiveInfoStartIdx                                                 Referable Keys */
  { /*     0 */                                                           1u,                                                             0u },  /* [CRYPTO_HASH] */
  { /*     1 */                                                           2u,                                                             1u },  /* [CRYPTO_MACGENERATE] */
  { /*     2 */                                                           3u,                                                             2u },  /* [CRYPTO_MACVERIFY] */
  { /*     3 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_ENCRYPT] */
  { /*     4 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_DECRYPT] */
  { /*     5 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_AEADENCRYPT] */
  { /*     6 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_AEADDECRYPT] */
  { /*     7 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_SIGNATUREGENERATE] */
  { /*     8 */                                                           5u,                                                             4u },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*     9 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_SECCOUNTERINCREMENT] */
  { /*    10 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_SECCOUNTERREAD] */
  { /*    11 */                                                           4u,                                                             3u },  /* [CRYPTO_RANDOMGENERATE] */
  { /*    12 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_RANDOMSEED] */
  { /*    13 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_KEYGENERATE] */
  { /*    14 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_KEYDERIVE] */
  { /*    15 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_KEYEXCHANGECALCPUBVAL] */
  { /*    16 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_KEYEXCHANGECALCSECRET] */
  { /*    17 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_CERTIFICATEPARSE] */
  { /*    18 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_CERTIFICATEVERIFY] */
  { /*    19 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO }   /* [CRYPTO_KEYSETVALID] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_RsaPkcs1Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_RsaPkcs1Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_RsaPkcs1VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_RsaPkcs1Verify[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                             Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_Crypto_30_LibCv.primWS.RsaPkcs1Verify }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_SHA256
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_SHA256
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_SHA256Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_SHA256[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                     Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_Crypto_30_LibCv.primWS.SHA256 }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_BufferLength
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_BufferLength
  \brief  Buffer which holds the current seed of the Fips186 algorithm to restore the needed workspace.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_BufferLengthType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_BufferLength[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, SHA256, CmacAesGenerate, CmacAesVerify, Fips186, RsaPkcs1Verify] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_DriverObjectState
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_DriverObjectState
  \brief  State of the current workspace usage.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_DriverObjectStateType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DriverObjectState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, SHA256, CmacAesGenerate, CmacAesVerify, Fips186, RsaPkcs1Verify] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyLock
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyLock
  \brief  Stores locking counter of each key
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_KeyLockUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyLock;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_MCU1VerificationKey] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_SHA256Key] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Random] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Mac] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyStorage
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_KeyStorageType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyStorage[445];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Modulus__WrittenLength__, RAM_KEY] */
  /*     1 */  /* [CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Modulus__WrittenLength__, RAM_KEY] */
  /*     2 */  /* [CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Modulus__Valid__, RAM_KEY] */
  /*     3 */  /* [CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Modulus__Extension__, RAM_KEY] */
  /*     4 */  /* [CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Modulus__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Modulus__Data__, RAM_KEY] */
  /*    19 */  /* [CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Modulus__Data__, RAM_KEY] */
  /*    20 */  /* [CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Pub_Exponent__WrittenLength__, RAM_KEY] */
  /*    21 */  /* [CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Pub_Exponent__WrittenLength__, RAM_KEY] */
  /*    22 */  /* [CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Pub_Exponent__Valid__, RAM_KEY] */
  /*    23 */  /* [CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Pub_Exponent__Extension__, RAM_KEY] */
  /*    24 */  /* [CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Pub_Exponent__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Pub_Exponent__Data__, RAM_KEY] */
  /*   279 */  /* [CryptoKey_MCU1VerificationKey__Crypto_30_LibCv_Rsa_Pub_Exponent__Data__, RAM_KEY] */
  /*   280 */  /* [CryptoKey_SHA256Key__Crypto_30_LibCv_Hash_Result__WrittenLength__, RAM_KEY] */
  /*   281 */  /* [CryptoKey_SHA256Key__Crypto_30_LibCv_Hash_Result__WrittenLength__, RAM_KEY] */
  /*   282 */  /* [CryptoKey_SHA256Key__Crypto_30_LibCv_Hash_Result__Valid__, RAM_KEY] */
  /*   283 */  /* [CryptoKey_SHA256Key__Crypto_30_LibCv_Hash_Result__Extension__, RAM_KEY] */
  /*   284 */  /* [CryptoKey_SHA256Key__Crypto_30_LibCv_Hash_Result__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_SHA256Key__Crypto_30_LibCv_Hash_Result__Data__, RAM_KEY] */
  /*   303 */  /* [CryptoKey_SHA256Key__Crypto_30_LibCv_Hash_Result__Data__, RAM_KEY] */
  /*   304 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES256__WrittenLength__, RAM_KEY] */
  /*   305 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES256__WrittenLength__, RAM_KEY] */
  /*   306 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES256__Valid__, RAM_KEY] */
  /*   307 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES256__Extension__, RAM_KEY] */
  /*   308 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES256__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES256__Data__, RAM_KEY] */
  /*   355 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES256__Data__, RAM_KEY] */
  /*   356 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES256__WrittenLength__, RAM_KEY] */
  /*   357 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES256__WrittenLength__, RAM_KEY] */
  /*   358 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES256__Valid__, RAM_KEY] */
  /*   359 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES256__Extension__, RAM_KEY] */
  /*   360 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES256__Data__, RAM_KEY] */
  /*   361 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_PrivateString__WrittenLength__, RAM_KEY] */
  /*   362 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_PrivateString__WrittenLength__, RAM_KEY] */
  /*   363 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_PrivateString__Valid__, RAM_KEY] */
  /*   364 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_PrivateString__Extension__, RAM_KEY] */
  /*   365 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_PrivateString__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_PrivateString__Data__, RAM_KEY] */
  /*   380 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_PrivateString__Data__, RAM_KEY] */
  /*   381 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_AdditionalInput__WrittenLength__, RAM_KEY] */
  /*   382 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_AdditionalInput__WrittenLength__, RAM_KEY] */
  /*   383 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_AdditionalInput__Valid__, RAM_KEY] */
  /*   384 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_AdditionalInput__Extension__, RAM_KEY] */
  /*   385 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_AdditionalInput__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_AdditionalInput__Data__, RAM_KEY] */
  /*   416 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_AdditionalInput__Data__, RAM_KEY] */
  /*   417 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Reseed_Counter__WrittenLength__, RAM_KEY] */
  /*   418 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Reseed_Counter__WrittenLength__, RAM_KEY] */
  /*   419 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Reseed_Counter__Valid__, RAM_KEY] */
  /* Index        Referable Keys */
  /*   420 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Reseed_Counter__Extension__, RAM_KEY] */
  /*   421 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Reseed_Counter__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Reseed_Counter__Data__, RAM_KEY] */
  /*   424 */  /* [CryptoKey_Random__Crypto_30_LibCv_Random_Reseed_Counter__Data__, RAM_KEY] */
  /*   425 */  /* [CryptoKey_Mac__Crypto_30_LibCv_Mac_Key__WrittenLength__, RAM_KEY] */
  /*   426 */  /* [CryptoKey_Mac__Crypto_30_LibCv_Mac_Key__WrittenLength__, RAM_KEY] */
  /*   427 */  /* [CryptoKey_Mac__Crypto_30_LibCv_Mac_Key__Valid__, RAM_KEY] */
  /*   428 */  /* [CryptoKey_Mac__Crypto_30_LibCv_Mac_Key__Extension__, RAM_KEY] */
  /*   429 */  /* [CryptoKey_Mac__Crypto_30_LibCv_Mac_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Mac__Crypto_30_LibCv_Mac_Key__Data__, RAM_KEY] */
  /*   444 */  /* [CryptoKey_Mac__Crypto_30_LibCv_Mac_Key__Data__, RAM_KEY] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Lock
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Lock
  \brief  Id of job that currently occupies the workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_LockType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Lock[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, SHA256, CmacAesGenerate, CmacAesVerify, Fips186, RsaPkcs1Verify] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Queue
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Queue
  \brief  Acts as job queue for all driver objects.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_QueueUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Queue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_RandomSeedBuffer
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_RandomSeedBufferUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_RandomSeedBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  /*   ... */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  /*    20 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_UnionWS_Crypto_30_LibCv
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_UnionWS_Crypto_30_LibCv
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_WS_Crypto_30_LibCv_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_Crypto_30_LibCv;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_WrittenLength
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_WrittenLength
  \brief  Holds the length which needs to be written in a next step for some algorithms.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_WrittenLengthType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_WrittenLength[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, SHA256, CmacAesGenerate, CmacAesVerify, Fips186, RsaPkcs1Verify] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_LibCv_Cfg.c
 *********************************************************************************************************************/
