/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Generic application vector table for platforms with Interrupt Vector Base Register.
 *                 This file is usually compiled and linked with the bootloader and is located OUTSIDE the
 *                 protected area of the FBL. It must be compiled, linked and downloaded with the
 *                 application after changing the magic value to 'APPL'
 *                 and setting the start label to the entry point of the application.
 *                 If the application is set to valid, the bootloader checks the magic flag in the first
 *                 entry of the ApplIntJmpTable and then calls the function specified in the second entry.
 *
 *                 This file must be compiled and linked in the bootloader
 *                 and the application to the SAME MEMORY LOCATION!
 *
 *  \note          Please note, that this file contains example source code used by the Flash Bootloader. These
 *                 functions may influence the behavior of the bootloader in principle. Therefore, great care must
 *                 be taken to verify the correctness of the implementation. The contents of the originally delivered
 *                 files are only examples resp. implementation proposals. With regard to the fact that these
 *                 functions are meant for demonstration purposes only, Vector Informatik's liability shall be
 *                 expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.
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
 *  Johannes Krimmel              KJs           Vector Informatik GmbH
 *  Christian Ralcewicz           RCn           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2017-10-27  KJs                      Initial version
 *  01.00.01   2020-09-18  RCn     ESCAN00106567    Compiler issue: "fbl_cfg.h" cannot be opened
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_def.h"
#include "applvect.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLVTABAPPL_IVBR_VERSION != 0x0100u ) || \
    ( FBLVTABAPPL_IVBR_RELEASE_VERSION != 0x01u )
# error "Error in fbl_applvect.c: Source and header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBL_APPLVECT_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/* PRQA S 305,428 1 */ /* MD_ApplVect_0305, MD_ApplVect_0428*/
V_MEMROM0 V_MEMROM1 vuint32 V_MEMROM2 ApplIntJmpTable[2] = {APPLVECT_FROM_APPL, RESET_ENTRY_ADDRESS};
#define FBL_APPLVECT_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_ApplVect_0305:
      Reason: Cast between a pointer to function and an integral type.
      Risk: Target data types are not big enough - data loss occurs.
      Prevention: The length of the pointer is known for the used platform and has to be kept in mind by the programmer.

   MD_ApplVect_0428:
     Reason: Function identifier is not followed by () but a function call may be intended.
             No function call intended. The address of the function shall be used.
     Risk: No risk.
     Prevention: No prevention required.

*/

/***********************************************************************************************************************
 *  END OF FILE: APPLVECT.C
 **********************************************************************************************************************/
