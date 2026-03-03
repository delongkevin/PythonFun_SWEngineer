/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         FBL updater callout routines - OEM specific
 *
 *  \note          Please note, that this file contains a collection of callback functions to be used with the
 *                 FBL Updater. These functions may influence the behavior of the updater in principle.
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
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Christian Baeuerle            CB            Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2018-07-18  CB      -                Initial release
 **********************************************************************************************************************/

#define UPD_OEM_AP

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "upd_oem_ap.h"
#if defined( V_GEN_GENERATOR_MSR )
# include "Fbl_Lbt.h"
#else /* VGEN_GENY */
# include "fbl_mtab.h"
#endif /* VGEN_GENY */
#include "WrapNv_inc.h"
#include "fbl_apnv.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLUPD_AP_FCA_VERSION != 0x0100u ) || \
    ( FBLUPD_AP_FCA_RELEASE_VERSION != 0x00u )
# error "Error in upd_oem_ap.c: Source and Header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

/** Reset response flag */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 resetRespFlag;

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ApplFblUpdOemInit
 **********************************************************************************************************************/
/*! \brief       Callback function to initialize OEM specifics
 **********************************************************************************************************************/
void ApplFblUpdOemInit(void)
{
   /* Initialize EEPROM-Driver */
   (void)EepromDriver_InitSync(V_NULL);
}

/***********************************************************************************************************************
 *  ApplFblUpdOemInvalidateUpdater
 **********************************************************************************************************************/
/*! \brief    Callback function to invalidate the updater/application
 *  \details  Update validity information of e.g. Eep-data
 *  \return   invalidation state
 **********************************************************************************************************************/
tFblResult ApplFblUpdOemInvalidateUpdater( void )
{
   tBlockDescriptor blockDescriptor;

   blockDescriptor = FblLogicalBlockTable.logicalBlock[FBL_UPD_LBT_NR_OF_UPDATER];

   return ApplFblInvalidateBlock(blockDescriptor);
}

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
/***********************************************************************************************************************
 *  ApplFblUpdOemCheckResponsePending
 **********************************************************************************************************************/
/*! \brief    Callback function to check if response pending message is needed
 *  \return   invalidation state
 **********************************************************************************************************************/
tFblResult ApplFblUpdOemCheckResponsePending( void )
{
   tFblResult result;

   result = kFblFailed;

   /* Check if reset-flag is set */
   if (kFblOk == ApplFblReadResetResponseFlag(&resetRespFlag))
   {
      if (   (resetRespFlag == RESET_RESPONSE_SDS_REQUIRED)
          || (resetRespFlag == RESET_RESPONSE_ECURESET_REQUIRED))
      {
         result = kFblOk;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblUpdOemPrepareResponsePending
 ***********************************************************************************************************************/
/*! \brief        Callout to prepare buffer with response pending (RCR-RP) message
 ***********************************************************************************************************************/
void ApplFblUpdOemPrepareResponsePending(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pResponse)
{
   if (resetRespFlag == RESET_RESPONSE_SDS_REQUIRED)
   {
      /* Prepare RCR-RP for service DiagnosticSession */
      pResponse[0u] = 0x7Fu;
      pResponse[1u] = 0x10u;
      pResponse[2u] = 0x78u;
   }
   else if (resetRespFlag == RESET_RESPONSE_ECURESET_REQUIRED)
   {
      /* Prepare RCR-RP for service EcuReset */
      pResponse[0u] = 0x7Fu;
      pResponse[1u] = 0x11u;
      pResponse[2u] = 0x78u;
   }
   else
   {
      /* Satisfy MISRA */
   }
}
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */

/***********************************************************************************************************************
 *  END OF FILE: UPD_OEM_AP.C
 **********************************************************************************************************************/
