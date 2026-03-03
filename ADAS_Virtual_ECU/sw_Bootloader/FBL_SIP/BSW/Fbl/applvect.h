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
 *  01.00.01   2020-09-18  RCn     ESCAN00106567    No changes
 **********************************************************************************************************************/

#ifndef __APPL_VECT_H__
#define __APPL_VECT_H__

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#define FBLVTABAPPL_IVBR_VERSION             0x0100u
#define FBLVTABAPPL_IVBR_RELEASE_VERSION     0x01u

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#define APPLVECT_FROM_BOOT       0x42544C44ul   /* 'BTLD', Reserved for Bootloader internal value
                                                 * This magic value mustn't be set
                                                 * for the application vector table, just
                                                 * for the table linked with the Bootloader.
                                                 */

#define APPLVECT_FROM_APPL       0x4150504Cul   /* 'APPL', Set this label only for the
                                                 * application vector table linked with the Application!
                                                 */

/***********************************************************************************************************************
 *  EXTERNAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/* Reset vector pointer definition for the FBL - compiler/hardware specific.
 * When using this file for the actual application, FBL_RESET_ENTRY_LABEL may not be defined.
 * Please insert the label manually and adapt the defines or include fbl_cfg.h.
 */
#if !defined( FBL_RESET_ENTRY_LABEL )
# error "Please define FBL_RESET_ENTRY_LABEL to entry label of the startup code."
#else
extern void FBL_RESET_ENTRY_LABEL( void );
# define RESET_ENTRY_ADDRESS (vuint32)&FBL_RESET_ENTRY_LABEL
#endif /* FBL_ENTRY_LABEL */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBL_APPLVECT_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
V_MEMROM0 extern V_MEMROM1 vuint32 V_MEMROM2 ApplIntJmpTable[2];
#define FBL_APPLVECT_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* __APPL_VECT_H__ */

/***********************************************************************************************************************
 *  END OF FILE: APPLVECT.H
 **********************************************************************************************************************/
