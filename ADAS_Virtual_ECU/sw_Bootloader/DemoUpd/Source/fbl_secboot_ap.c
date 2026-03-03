/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         SecureBoot implementation callback file
 *
 *  \note          Please note, that this file contains a collection of callback functions to be used with the
 *                 Flash Bootloader. These functions may influence the behavior of the bootloader in principle.
 *                 Therefore, great care must be taken to verify the correctness of the implementation.
 *                 The contents of the originally delivered files are only examples resp. implementation proposals.
 *                 With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                 Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                 admissible by law or statute.
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2020-01-07  visrie  FBL-524          Initial release
 *  01.00.01   2020-04-27  visrie  FBL-1773         No changes
 *  02.00.00   2020-05-19  vistbe  FBL-1016         No changes
 *  02.01.00   2021-01-19  visrie  FBL-2648         No changes
 *                                 FBL-2641         No changes
 *  02.02.00   2021-09-03  visjdn  FBL-3352         Support different default locations of the signature
 **********************************************************************************************************************/

#define FBL_SECBOOT_AP_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
#include "bm_main.h"
#include "Csm.h"
#include "fbl_secboot_ap.h"

 /***********************************************************************************************************************
  *  DEFINES
  **********************************************************************************************************************/

#define FBLSB_INITIAL_STARTUP_SET_VALUE      0xA5u

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ApplFblSbStartup
 **********************************************************************************************************************/
/*! \brief       Secure boot initialization callback
 *  \details     This function is called during Bootloader initialization to set up secure boot
 **********************************************************************************************************************/
void ApplFblSbStartup( void )
{
#if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
# if defined( FBLBM_INSTANCE_BOOTLOADER )
   if (FblBmChkInitCmacMagicFlag())
   {
      /* Clear the flag */
      FblBmClrMagicFlag();

      /* Update the SecureBootSegments by using SecureBoot-ForceSequential */
      assertFbl(FblSb_UpdateInitialSegments() == kFblOk, 0u);

      /* Clear the initial startup flag */
      ApplFblSbClrInitialStartup();

      /* Perform reset to enable secure boot on next startup */
      ApplFblReset();
   }
# endif /* FBLBM_INSTANCE_BOOTLOADER */
#endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC */
}

#if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
# if defined( FBLBM_INSTANCE_BOOTMANAGER )
/***********************************************************************************************************************
 *  ApplFblSbIsInitialStartup
 **********************************************************************************************************************/
/*! \brief       Checks if this is an initial (first) startup of the ECU
 *  \return      kFblOk if this is the first startup, otherwise kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblSbIsInitialStartup(void)
{
   tFblResult result = kFblFailed;
   uint8 writeOnceKeyValue = 0u;
   uint32 writeOnceKeyLength = 1u;

   /* Reads a write once key from the vHsm */
   if (Csm_KeyElementGet(FblSb_GetCsmKeyOfInitialStartup(), 1u, &writeOnceKeyValue, &writeOnceKeyLength) == E_OK)
   {
      /* Check if the key was already written */
      if (writeOnceKeyValue != FBLSB_INITIAL_STARTUP_SET_VALUE)
      {
         result = kFblOk;
      }
   }

   return result;
}
#endif /* FBLBM_INSTANCE_BOOTMANAGER */

/***********************************************************************************************************************
 *  ApplFblSbClrInitialStartup
 **********************************************************************************************************************/
/*! \brief       Clears the initial startup condition flag
 **********************************************************************************************************************/
void ApplFblSbClrInitialStartup(void)
{
   tFblResult result = kFblFailed;
   uint8 writeOnceKeyValue = FBLSB_INITIAL_STARTUP_SET_VALUE;
   uint32 writeOnceKeyLength = 1u;

   /* Reads a write once key from the vHsm */
   if (Csm_KeyElementSet(FblSb_GetCsmKeyOfInitialStartup(), 1u, &writeOnceKeyValue, writeOnceKeyLength) == E_OK)
   {
      if (Csm_KeySetValid(FblSb_GetCsmKeyOfInitialStartup()) == E_OK)
      {
         result = kFblOk;
      }
   }

   /* Writing of the key was not successful, which should not happen */
   assertFblUser((result == kFblOk), 1u);
}
#endif

/***********************************************************************************************************************
 *  ApplFblSbGetSignatureInfo
 **********************************************************************************************************************/
/*! \brief      Gets the information of the signature
 *  \param[in]  blockDescriptor  Pointer to the block descriptor
 *  \param[in]  bmHdrHeader      Pointer to the FblBmHdrHeader structure
 *  \param[out] signatureAddress Address of the signature
 *  \param[out] signatureLength  Length of the signature
 **********************************************************************************************************************/
void ApplFblSbGetSignatureInfo(const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
   const V_MEMRAM1 tFblBmHdrHeader V_MEMRAM2 V_MEMRAM3 * bmHdrHeader,
   V_MEMRAM1 uint32 V_MEMRAM2 V_MEMRAM3 * signatureAddress,
   V_MEMRAM1 uint32 V_MEMRAM2 V_MEMRAM3 * signatureLength)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 2 */ /* MD_MSR_DummyStmt */
   (void)blockDescriptor;
   (void)bmHdrHeader;
#endif

   *signatureLength = FBLSB_SIGNATURE_LENGTH;
   
#if ( FBLSB_SIGNATURE_POSITION == FBLSB_SIGPOSITION_FRONT_SEGTABLE )
   *signatureAddress = bmHdrHeader->bmAuthenticationHeaderAddress - FBLSB_SIGNATURE_LENGTH;
#elif ( FBLSB_SIGNATURE_POSITION == FBLSB_SIGPOSITION_START_LOGICAL_BLOCK )
   *signatureAddress = blockDescriptor->blockStartAddress;
#elif ( FBLSB_SIGNATURE_POSITION == FBLSB_SIGPOSITION_END_LOGICAL_BLOCK )
   *signatureAddress = blockDescriptor->blockStartAddress + blockDescriptor->blockLength - FBLSB_SIGNATURE_LENGTH;
#else /* FBLSB_SIGNATURE_POSITION == FBLSB_SIGPOSITION_USER */
# error "A user implementation of the signature address retrieval must be provided here."
#endif
}

/***********************************************************************************************************************
 *  MISRA
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_SECBOOT_AP.C
 **********************************************************************************************************************/
