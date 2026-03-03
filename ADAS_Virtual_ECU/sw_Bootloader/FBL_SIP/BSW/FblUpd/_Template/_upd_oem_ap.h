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

#ifndef __UPD_OEM_AP_H__
#define __UPD_OEM_AP_H__

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblUpd_Ap_Fca CQComponent : Implementation */
#define FBLUPD_AP_FCA_VERSION             0x0100u
#define FBLUPD_AP_FCA_RELEASE_VERSION     0x00u

/* Interface version */
/** Major interface version identifies incompatible changes */
#define FBL_UPD_AP_OEM_API_VERSION_MAJOR     0x01u
/** Minor interface version identifies backward compatible changes */
#define FBL_UPD_AP_OEM_API_VERSION_MINOR     0x00u
/** Release interface version identifies cosmetic changes */
#define FBL_UPD_AP_OEM_API_VERSION_RELEASE   0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "upd_types.h"
#include "upd_cfg.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#define FblRealTimeSupport                   FblLookForWatchdog

/** Verification function is not needed in the updater */
#define SecM_Verification                    0
#define SecM_VerifySignature                 0
#define FBL_DIAG_DEFAULT_VERIFICATION        0

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/

void ApplFblUpdOemInit(void);
tFblResult ApplFblUpdOemInvalidateUpdater( void );
#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
tFblResult ApplFblUpdOemCheckResponsePending( void );
void ApplFblUpdOemPrepareResponsePending(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pResponse);
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */

/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/

#error "TODO: Remove call to ApplFblNvWriteFingerprint() from function ApplFblInvalidateBlock()!"

#endif /* __UDP_OEM_AP_H__ */

/***********************************************************************************************************************
 *  END OF FILE: UDP_OEM_AP.H
 **********************************************************************************************************************/
