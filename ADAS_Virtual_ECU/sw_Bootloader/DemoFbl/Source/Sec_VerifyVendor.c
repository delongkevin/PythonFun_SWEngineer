/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include "fbl_inc.h"

 

#if (SEC_SECURITY_CLASS == SEC_CLASS_VENDOR)

 

/**********************************************************************************************************************
*  DEFINES
*********************************************************************************************************************/

 

/**********************************************************************************************************************
*  LOCAL DATA
*********************************************************************************************************************/

 

/**********************************************************************************************************************
*  GLOBAL FUNCTIONS
*********************************************************************************************************************/

 

/**********************************************************************************************************************
*  SecM_VerifyClassVendor
*********************************************************************************************************************/
/*! \brief         Calculate and verify checksum or hash using primitive configured for security class Vendor
*  \details       This function verifies the signature of a downloaded logical block by calling the corresponding
*                 library functionsd
*  \param[in]     pVerifyParam Pointer to parameter structure for signature verification
*                   Member currentHash must (SEC_DISABLE_DEFAULT_WORKSPACE) or may (SEC_ENABLE_WORKSPACE_INTERNAL)
*                   contain reference to buffer used as workspace
*  \return        SECM_VER_OK if verification operation successful
*                 SECM_VER_ERROR if error occured during verification
*                 SECM_VER_CRC if CRC verification failed
*                 SECM_VER_SIG if MAC/Signature verification failed
*********************************************************************************************************************/
SecM_StatusType SecM_VerifyClassVendorStream( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam )
{
   return SECM_VER_ERROR;
}

 

#endif /* SEC_SECURITY_CLASS == SEC_CLASS_VENDOR */

 

/***********************************************************************************************************************
*  SEC_VERIFYVENDOR.C
**********************************************************************************************************************/


