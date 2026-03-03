/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file  File:  ARMBrsHwIntTb_CortexR.c
 *      Project:  Vector Basic Runtime System
 *       Module:  BrsHw for all platforms with ARM core Cortex-R
 *     Template:  This file is reviewed according to Brs_Template@Implementation[1.02.00]
 *
 *  \brief Description:  This file consists of the core exception table for FBL projects, without usage of an OS.
 *
 *  \attention Please note:
 *    The demo and example programs only show special aspects of the software. With regard to the fact
 *    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
 *    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to ARMBrsHw_CortexR.h.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "BrsHw.h"

#include "BrsMain.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if (ARMBRSHW_CORTEXR_VERSION != 0x0104u)
  #error "Header and source file are inconsistent!"
#endif
#if (ARMBRSHW_CORTEXR_BUGFIX_VERSION != 0x04u)
  #error "Different versions of bugfix in Header and Source used!"
#endif

/**********************************************************************************************************************
 *  CONFIGURATION CHECK
 *********************************************************************************************************************/
#if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)

#else
  #error "Unknown compiler specified!"
#endif

#define BRS_START_SEC_RAM_CODE
#include "Brs_MemMap.h"
BRS_ISR_KEYWORD void BrsHw_core_exception_handler(void)
{
  BrsMainExceptionHandler(kBrsInterruptHandlerNotInstalled, BRSERROR_MODULE_BRSHW, (uint16)0);
}
#define BRS_STOP_SEC_RAM_CODE
#include "Brs_MemMap.h"

/********************************************************************************************
 *                                                                                          *
 *                           Core Exceptions Table                                          *
 *                                                                                          *
 ********************************************************************************************/


#if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
# pragma clang section text = ".brsExcVect"
__attribute__((naked)) void intvect_CoreExceptions(void)
{
  __asm("  b brsStartupEntry");
  __asm("  b BrsHw_core_exception_handler");
  __asm("  b BrsHw_core_exception_handler");
  __asm("  b BrsHw_core_exception_handler");
  __asm("  b BrsHw_core_exception_handler");
  __asm("  b BrsHw_core_exception_handler");
  __asm("  b BrsHw_core_exception_handler");
  __asm("  b BrsHw_core_exception_handler");
}
# pragma clang section text = ""
#endif /*BRS_COMP_ARM6||BRS_COMP_LLVMDIAB||BRS_COMP_LLVMTEXASINSTRUMENTS*/


