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
 *            Module: Smh
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SecMPar.c
 *   Generation Time: 2024-11-25 15:00:22
 *           Project: DemoFbl - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/


#define SECMPAR_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "Sec.h"
#include "Csm.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define SECM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static SecM_StatusType SecM_VerifyDummy(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam);

#define SECM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
/* PRQA  S 3218 EOF */ /* MD_SecMPar_3218 */
#define SECM_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


V_MEMROM0 static V_MEMROM1 SecM_VerifyOperationType V_MEMROM2 verifyConfigSmhSecurityClassDDDConfig[1] =
{
  { /*  SmhSecurityClassDDDConfig  */ 
    SecM_VerifySHA256, 
    SEC_SIZE_HASH_SHA256, 
    0x00000002u, 
    SEC_UPDATE_OPERATION_VERIFICATION
  }
};
V_MEMROM0 static V_MEMROM1 SecM_VerifyOperationType V_MEMROM2 verifyConfigSmhSecurityClassVendorConfig[1] =
{
  { /*  SmhSecurityClassVendorConfig  */ 
    SecM_VerifyClassVendorStream, 
    1, 
    0x00000000u, 
    SEC_UPDATE_OPERATION_VERIFICATION
  }
};

#define SECM_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SECM_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

V_MEMRAM0 static V_MEMRAM1 SecM_ByteType V_MEMRAM2 SecM_DigestBuffer_SmhSecurityClassDDDConfig[SEC_SIZE_HASH_SHA256];


#define SECM_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define SECM_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define SECM_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SECM_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */





V_MEMROM0 V_MEMROM1 SecM_HashPrimitiveType V_MEMROM2 SecM_HashPrimitives[1] =
{
  { /*  SmhSecurityClassDDDConfig  */ 
    SmhConf_SmhJob_SmhJob_CalculateHash, 
    SecM_DigestBuffer_SmhSecurityClassDDDConfig, 
    SEC_SIZE_HASH_SHA256, 
    FALSE, 
    FALSE
  }
};



V_MEMROM0 V_MEMROM1 SecM_RamDataType V_MEMROM2 SecM_SignaturePrimitivesContextBuffs[1] =
{ /*  SmhSecurityClassCCCConfig  */ 
  V_NULL
};

V_MEMROM0 V_MEMROM1 SecM_SigPrimitiveType V_MEMROM2 SecM_SignaturePrimitives[1] =
{
  { /*  SmhSecurityClassCCCConfig  */ 
    SmhConf_SmhJob_SmhJob_SignatureVerify, 
    SEC_INVALID_SMH_JOB_ID, 
    NULL_PTR, 
    0, 
    0u, 
    V_NULL, 
    FALSE
  }
};



/* PRQA S 0315 JOBINFO_TAG */ /* MD_SecMPar_0315 */
V_MEMROM0 V_MEMROM1 SecM_JobInfoType V_MEMROM2 SecM_JobInfo[4] =
{
  { /*  SmhJob_TRNG  */ 
    SECM_RANDOMGENERATE, 
    CsmConf_CsmJob_CsmJob_TRNGGen, 
    CsmConf_CsmKey_CsmKey_Random, 
    SEC_INVALID_SMH_KEY_ID, 
    SEC_KEY_TYPE_NONE, 
    V_NULL
  }, 
  { /*  SmhJob_SignatureVerify  */ 
    SECM_SIGNATUREVERIFY, 
    CsmConf_CsmJob_CsmJob_SignatureVerify_ADA, 
    CsmConf_CsmKey_CsmKey_RsaSignatureVerifyKey_ADA_L4, 
    SEC_INVALID_SMH_KEY_ID, 
    SEC_KEY_TYPE_ASYMMETRIC, 
    V_NULL
  }, 
  { /*  Smh_GetCertificateElement  */ 
    SECM_AEADENCRYPT, 
    CsmConf_CsmJob_CsmJob_GetRoleFromTesterCertificate, 
    SEC_INVALID_CSM_KEY_ID, 
    SEC_INVALID_SMH_KEY_ID, 
    SEC_KEY_TYPE_NONE, 
    V_NULL
  }, 
  { /*  SmhJob_CalculateHash  */ 
    SECM_HASH, 
    CsmConf_CsmJob_CsmJob_CalculateHash, 
    CsmConf_CsmKey_CsmKey_Sha256Result, 
    SEC_INVALID_SMH_KEY_ID, 
    SEC_KEY_TYPE_NONE, 
    V_NULL
  }
};
/* PRQA L:JOBINFO_TAG */

#define SECM_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
/* PRQA S 3219, 3673 1 */ /* MD_SecMPar_3219, MD_MSR_Rule8.13 */
static SecM_StatusType SecM_VerifyDummy(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam)
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 1 */ /* MD_MSR_DummyStmt */
   (void)pVerifyParam;
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */
   return SECM_OK;
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


SecM_StatusType SecM_VerifySHA256( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam )
{
   return SecM_VerifyHash(pVerifyParam, SmhConf_SmhStreamVerificationHash_SmhSecurityClassDDDConfig);
}

SecM_StatusType SecM_AuthDiag_Certificate_VerifySign( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam )
{
   return SecM_VerifySig(pVerifyParam, SmhConf_SmhStreamVerificationSignature_SmhSecurityClassCCCConfig);
}


SecM_StatusType SecM_VerificationClassDDD_SHA256( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam )
{
   SecM_SignatureParamType    verifyContext[1];
   SecM_VerifyConfigListType  config;

   config.pPrimitives.pOperation = verifyConfigSmhSecurityClassDDDConfig;
   config.pPrimitives.pContext   = verifyContext;
   config.count                  = 1;

   return SecM_VerificationBase(pVerifyParam, &config);
}

SecM_StatusType SecM_VerifyClassVendorBlock( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam )
{
   SecM_SignatureParamType    verifyContext[1];
   SecM_VerifyConfigListType  config;

   config.pPrimitives.pOperation = verifyConfigSmhSecurityClassVendorConfig;
   config.pPrimitives.pContext   = verifyContext;
   config.count                  = 1;

   return SecM_VerificationBase(pVerifyParam, &config);
}



#define SECM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_SecMPar_0313:
      Reason:     Signature/checksum verification functions are stored as void pointers as actual type is not known at
                  configuration time.
      Risk:       Function signature not compatible with expected type.
      Prevention: Integrator has to take care the configured functions match with the expected signature.

   MD_SecMPar_0315:
      Reason:     The implicit conversion from a pointer to object type to a pointer to void is used to allows pointers 
                  to different object types as parameter.
      Risk:       No risk, because the underlying pointer type is known and the cast is safe.
      Prevention: No prevention necessary.

   MD_SecMPar_3218:
      Reason:     The local variables of this module are kept at a central location for a better overview and maintenance.
      Risk:       Scope is larger than required (whole file instead of one function). Some other function could access
                  the variable.
      Prevention: Restrict the functionality in this module to the intended purpose. Don't add functions which shall not
                  be able to access the local data buffers.

   MD_SecMPar_3219:
      Reason:     The function is used only on some configurations.
      Risk:       No risk.
      Prevention: No prevention.

*/
