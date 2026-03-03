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
 *  02.02.00   2021-09-03  visjdn  FBL-3352         No changes
 **********************************************************************************************************************/

#ifndef FBL_SECBOOT_AP_H
#define FBL_SECBOOT_AP_H

/***********************************************************************************************************************
*  INCLUDES
**********************************************************************************************************************/

#include "bm_types.h"
#include "fbl_secboot.h"

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/

void ApplFblSbStartup(void);
#if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
# if defined( FBLBM_INSTANCE_BOOTMANAGER )
tFblResult ApplFblSbIsInitialStartup(void);
# endif
void ApplFblSbClrInitialStartup(void);
#endif
void ApplFblSbGetSignatureInfo(const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
   const V_MEMRAM1 tFblBmHdrHeader V_MEMRAM2 V_MEMRAM3 * bmHdrHeader,
   V_MEMRAM1 uint32 V_MEMRAM2 V_MEMRAM3 * signatureAddress,
   V_MEMRAM1 uint32 V_MEMRAM2 V_MEMRAM3 * signatureLength);

#endif /* FBL_SECBOOT_AP_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_SECBOOT_AP.H
 **********************************************************************************************************************/
