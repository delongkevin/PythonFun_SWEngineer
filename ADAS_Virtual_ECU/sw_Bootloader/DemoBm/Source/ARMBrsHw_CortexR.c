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
/** \file  File:  ARMBrsHw_CortexR.c
 *      Project:  Vector Basic Runtime System
 *       Module:  BrsHw for all platforms with ARM core Cortex-R
 *     Template:  This file is reviewed according to Brs_Template@Implementation[1.02.00]
 *
 *  \brief Description:  This is a global, platform-independent file for the ARM-BRS.
 *                       This file includes all non-platform dependent functions.
 *                       All the (platform depending) rest needs to be defined in BrsHw.c
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

#if !defined (BRS_ENABLE_FBL_SUPPORT)
  #include "Os.h"
#endif

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

/**********************************************************************************************************************
 *  DEFINITION + MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONST VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL VARIABLES AND LOCAL HW REGISTERS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CONTROLLER CONFIGURATION REGISTERS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONST VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PROTOTYPES OF GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PROTOTYPES OF LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/*****************************************************************************/
/* @brief      Disable the global system interrupt.
 * @pre        Must be the first function call in main@BrsMain
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from main@BrsMain at power on initialization
 *****************************************************************************/
void BrsHwDisableInterruptAtPowerOn(void)
{
  /* Disable IRQ, FIQ */
  __asm(" MRS R0, CPSR ");       /* Read CPSR Register */
  __asm(" ORR R0, R0, #0x040 "); /* Set Asynchronous FIQ Mask bit */
  __asm(" ORR R0, R0, #0x080 "); /* Set Asynchronous IRQ Mask bit */
  __asm(" MSR CPSR_c, R0 ");     /* Write CPSR Register (only bits [7:0]) */

#if defined (BRS_DERIVATIVE_TDA4VM88) || defined (BRS_DERIVATIVE_TDA4VE88) || defined (BRS_DERIVATIVE_TPR12)
  /* Disable Data Abort Handler */
  __asm(" MRS R0, CPSR ");       /* Read CPSR Register */
  __asm(" ORR R0, R0, #0x100 "); /* Set Asynchronous Abort Mask bit */
  __asm(" MSR CPSR_x, R0 ");     /* Write CPSR Register (only bits [15:8]) */

  /* Disable VIC */
  __asm(" MRS R0, CPSR ");
  __asm(" ORR R0, R0, #0x1f ");
  __asm(" MSR CPSR_cxsf, R0 ");

  __asm(" MRC p15, #0, r1, c1, c0, #0 ");
  __asm(" BIC  r1, r1, #(1<<24) ");
  __asm(" MCR  p15, #0, r1, c1, c0, #0 ");
#endif /*BRS_DERIVATIVE_x*/
}

/*****************************************************************************/
/* @brief      This API is used to read the core ID of the actual running core
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     Core ID of the actual running core
 * @context    Function is e.g. called from main@BrsMain, to only call HW-init
 *             code once, on the boot core.
 *             In MultiCore setups, additional BRSHW_INIT_CORE_ID must be
 *             declared inside BrsHw.h, to configure the proper core ID value
 *             of that boot core.
 *****************************************************************************/
uint32 BrsHw_GetCore(void)
{
#if (BRS_CPU_CORE_AMOUNT>1)
  uint32 id=0;
  /* Read out the physical processor number.
   * 0 for Core0, Cluster0
   * 1 for Core1, Cluster0
   * 2 for Core0, Cluster1
   * 3 for Core1, Cluster1
   * 4 for Core0, Cluster2
   * 5 for Core1, Cluster2
   */
  brsHwGetMpidr(id);

  return ((id & 0x01ul) + (((id & 0xFF00ul) >> 7u) & 0x0Eul));

#else
  /* Stub for SingleCore environments, always returns 0 */
  return 0u;
#endif /*BRS_CPU_CORE_AMOUNT*/
}

/*****************************************************************************/
/* @brief      This API is used for the BRS time measurement support to get a
 *             default time value for all measurements with this platform to
 *             be able to compare time measurements on different dates based
 *             on this time result.
 * @pre        Should be called with interrupts global disabled
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from e.g. component testsuits for calibration
 *****************************************************************************/
void BrsHwTime100NOP(void)
{
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
}
