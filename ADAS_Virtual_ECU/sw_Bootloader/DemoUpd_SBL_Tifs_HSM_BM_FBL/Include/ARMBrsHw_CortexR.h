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
/** \file  File:  ARMBrsHw_CortexR.h
 *      Project:  Vector Basic Runtime System
 *       Module:  BrsHw for all platforms with ARM core Cortex-R
 *
 *  \brief Description:  This is a global, platform-independent header file for the ARM-BRS.
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
 *  Version   Date        Author  Description
 *  --------  ----------  ------  -------------------------------------------------------------------------------------
 *  01.00.00  2020-15-19  visbwa  New branch for vBaseEnv 2.0, based on zBrs_ArmCommon ARMBrsHw_CortexA.c 4.07.01 and
 *                                ARMStartup_CortexA.c 1.11.01; updated vLinkGen define and struct names to new
 *                                vLinkGen 2.0 naming schema in ARMStartup_CortexA.c
 *  01.00.01  2020-06-08  visbwa  Fixed support for Tasking compiler and usage of struct vLinkGen_MemArea
 *                                (vLinkGen_ZeroInit_Early_Blocks, vLinkGen_ZeroInit_Early_Groups) -> size is 16Byte
 *                                per entry in ARMStartup_CortexA.c
 *  01.00.02  2020-06-09  visbwa  Fixed IAR code to load stack symbols in ARMStartup_CortexA.c
 *  01.00.03  2020-07-03  visbwa  Added disabling of abort handler and VIC for TDA4VM88@TI,
 *                                added support for up to 6 cores in ARMStartup_CortexA.c
 *  01.01.00  2020-09-18  visbwa  Review according to Brs_Template 1.01.00
 *  01.01.01  2020-10-21  vishci  Fixed BRS_ISR_KEYWORD of Arm5, Gnu and Iar compiler abstraction in ARMBrsHw_CortexA.h,
 *                                update to Brs_Template 1.01.01, removed AUTHOR IDENTITY,
 *                                added new file ARMBrsHwIntTb_CortexR.c for FBL projects w/o OS
 *  01.01.02  2020-10-23  visbwa  Renamed exception vector table according to Brs_Template in ARMBrsHwIntTb_CortexR.c
 *  01.01.03  2020-10-28  visbwa  No changes in sourcecode, only within ALM package
 *  01.01.04  2020-11-09  visbwa  No changes in sourcecode, only within ALM package
 *  01.01.05  2020-11-12  visdri  Support Jacinto7 Cortex-R cores by merging the Jacinto7 startup code provided by TI
 *                                (disable TCM and call mpu_init for Jacinto7 derivative) and fixed activation of FPU
 *                                + initialization order (switch to system mode after FPU init) in ARMStartup_CortexA.c
 *  01.01.06  2020-12-07  visjhr  Added support for TPR12 derivative and disabling of abort handler and VIC for it
 *  01.01.07  2021-01-14  visbwa  Fixed BRANCH to startup_block_zero_init_loop_start for ARM compilers in
 *                                ARMStartup_CortexA.c
 *  01.01.08  2021-03-05  visdri  Removed Tasking and HighTec from list of supported compilers,
 *                                removed BRS_EXTERN_BRANCH (separation to BRS_BRANCH not needed on Cortex-A/R) and
 *                                fixed branches to stack pointer init routines for MultiCore in ARMStartup_CortexA.c
 *  01.01.09  2021-03-08  visbwa  Fixed IAR encapsulation of Brs_IarLoadCore0Id (only for MultiCore) and branch extern
 *                                in ARMStartup_CortexA.c
 *  01.02.00  2021-02-02  vismaa  Added BrsHw_GetCore() and macros BRS_READ_COREID + brsHwGetMpidr
 *            2021-03-09  visbwa  Renamed all files from ARMBrsHw_CortexA into ARMBrsHw_CortexR,
 *                                update to Brs_Template 1.02.00, moved revision history of all .c and .h files into
 *                                ARMBrsHw_CortexR.h, added SingleCore stubs for Read_COREID (always return 0)
 *  01.02.01  2021-03-18  vismaa  Fixed memory initialization process in ARMStartup_CortexR.c to work properly in
 *                                MultiCore environments
 *  01.03.00  2021-04-20  vishci  Added LlvmDiab compiler support, fixed IAR compiler support in FBL CoreExceptionTable
 *            2021-05-04  visbwa  Review, generalized BrsHwDisableInterruptAtPowerOn(),
 *                                removed duplicates in TI compiler abstraction
 *  01.03.01  2021-05-11  visbwa  Fixed brsExcVect section for Arm6 and LlvmDiab in ARMBrsHwIntTb_CortexR.c
 *  01.03.02  2021-07-28  visjhr  Fixed bug in brsHwGetMpidr(c) for GCC compilers
 *  01.03.03  2021-08-03  visjhr  Adapted bugfix of brsHwGetMpidr(c) for LLVMDIAB compiler
 *  01.03.04  2021-09-21  visbpz  Adaptation for IAR
 *  01.04.00  2021-10-18  vishci  added LLVMTEXASINSTRUMENTS compiler support
 *  01.04.01  2021-10-20  visbpz  Fix for 8 byte aligned ECC initialization
 *            2021-10-25  visbwa  Added usage of alignment parameter to distinguish between 4-Byte and 8-Byte init
 *  01.04.02  2022-03-01  visbwa  ESCAN00111389, ESCAN00111390: Fixed zero_init loops in ARMStartup_CortexR.c, renamed
 *                                area_zero_init to group_zero_init, introduced BRS_BRANCH_GREATER_THAN_OR_EQUAL
 *  01.04.03  2022-03-14  visbwa  ESCAN00111478: StartupCode is not mapped into specific section "brsStartup" for Arm6
 *                                compiler (ARMStartup_CortexR.c),
 *                                ESCAN00111480: StartupCode is using ARM_LIB_STACK instead of STACK_C0 to initialize
 *                                stackpointer during startup (ARMStartup_CortexR.c),
 *                                removed useless abstraction for asm in ARMBrsHw_CortexR.c, 
 *                                removed unused BRS_SECTION_DATA fragments from some compiler abstractions,
 *                                replaced BRS_DUMMY_FUNC by Startup_Handler_ASM() (adjustment with Cortex-M code)
 *  01.04.04  2022-04-06  virmid  Support for TDA4VE derivative
 *  01.04.05  2022-08-22  visrgm  Added BRSHW_PRE_ASM_STARTUP_HOOK_AVAILABLE define to ARMStartup_CortexM.c
 *  01.04.06  2022-08-11  visto   correct the bugfix version number
 *********************************************************************************************************************/

#ifndef _ARMBRSHW_CORTEXR_H_
#define _ARMBRSHW_CORTEXR_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/*
 * Description: The BrsCfg header is used to configure different types of
 *              tests and system setups. Therefore it must be included first
 *              in each BRS and test module.
 *              This file is part of the BRS.
 */
#include "vBrsCfg.h"

/**********************************************************************************************************************
 *  MODULE VERSION
 *********************************************************************************************************************/
/*
 * Description: This is the BrsHw main and bug fix version. The version numbers are BCD coded.
 *              E.g. a main version of 1.23 is coded with 0x0123, a bug fix version of 9 is coded 0x09.
 */
#define ARMBRSHW_CORTEXR_VERSION        0x0104u
#define ARMBRSHW_CORTEXR_BUGFIX_VERSION 0x06u

/**********************************************************************************************************************
 *  CONFIGURATION CHECK
 *********************************************************************************************************************/
/* Configuration checks performed within platform specific code (BrsHw) */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
 * Description: Macro for access to IO addresses
 */
#define BRSHW_IOS(type, address) (*((volatile type *)(address)))

#define BRSHWNOP10() do { \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  } while(0)

/**********************************************************************************************************************
 * Compiler abstraction
 *********************************************************************************************************************/
#if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
  #define ___asm(c)                __asm_(c)
  #define __asm_(c)                __asm(#c);
  #define __as1(c, d)              __as1_(c, d)
  #define __as1_(c, d)             __asm( #c " , " #d);
  #define __as2(c, d, e)           __as2_(c, d, e)
  #define __as2_(c, d, e)          __asm( #c " , " #d " , " #e);
  #define __as3(c, d, e, f)        __as3_(c, d, e, f)
  #define __as3_(c, d, e, f)       __asm( #c " , " #d " , " #e " , " #f);
  #define __as4(c, d, e, f, g)     __as4_(c, d, e, f, g)
  #define __as4_(c, d, e, f, g)    __asm( #c " , " #d " , " #e " , " #f  " , " #g);
  #define __as5(c, d, e, f, g, h)  __as5_(c, d, e, f, g, h)
  #define __as5_(c, d, e, f, g, h) __asm( #c " , " #d " , " #e " , " #f  " , " #g " , " #h);

  #define BRS_MULTILINE_ASM_BEGIN()
  #define BRS_MULTILINE_ASM_END()

  #define BRS_ASM_EQU(Label, Value) __as1(.equ Label, Value)

  #define BRS_ISR_KEYWORD __attribute__ ((interrupt("IRQ")))

  #define BRS_SECTION_CODE(c)     __as1(.section .c , "ax" )

  #define BRS_GLOBAL(c)           ___asm(.globl c)
  #define BRS_LABEL(c)            ___asm(c:)
  #define BRS_GLOBAL_END()

  /* Unconditional branch to c */
  #define BRS_BRANCH(c)           ___asm(B c)
  #define BRS_EXTERN_BRANCH(c)    ___asm(B c)

  /* Branch to e if c and d are equal */
  #define BRS_BRANCH_EQUAL(c,d,e)  __as1(CMP c, d) \
                                   ___asm(BEQ e)

  /* Branch to e if c and d are NOT equal */
  #define BRS_BRANCH_NOT_EQUAL(c,d,e)  __as1(CMP c, d) \
                                       ___asm(BNE e)

  /* Branch to e if c is greater than d*/
  #define BRS_BRANCH_GREATER_THAN(c,d,e)  __as1(CMP c, d) \
                                         ___asm(BGT e)

  /* Branch to e if c is greater or equal than d */
  #define BRS_BRANCH_GREATER_THAN_OR_EQUAL(c,d,e)  __as1(CMP c, d) \
                                                   ___asm(BGE e)

# if (BRS_CPU_CORE_AMOUNT>1)
  #define BRS_READ_COREID(c) __asm( "mrc p15" "," "0" "," "r12" "," "c0" "," "c0" "," "5" ); \
                             __asm( "movw " #c "," "#0x1fe" );  \
                             __asm( "and r12" "," #c "," "r12" "," "lsr #7" ); \
                             __asm( "mrc p15" "," "#0" "," #c "," "c0" ","  "c0" "," "#5" );  \
                             __asm( "and " #c "," #c "," "#3" );  \
                             __asm( "orr " #c "," #c "," "r12" );

  /* Multiprocessor affinity (MPIDR) */
  #define brsHwGetMpidr(c) asm("MRC p15, 0, %0, c0, c0, 5" : "=r" (c) :)

# else
  /* Stub for SingleCore environments, always returns 0 */
  #define BRS_READ_COREID(c) __as1(MOV c, 0)
# endif /*BRS_CPU_CORE_AMOUNT*/

#else
  #error "Compiler not yet supported"
#endif /*BRS_COMP_x*/

/**********************************************************************************************************************
 *  BrsHW configuration
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/*****************************************************************************/
/* @brief      Disable the global system interrupt.
 * @pre        Must be the first function call in main@BrsMain
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from main@BrsMain at power on initialization
 *****************************************************************************/
void BrsHwDisableInterruptAtPowerOn(void);

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
uint32 BrsHw_GetCore(void);

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
void BrsHwTime100NOP(void);

#endif /*_ARMBRSHW_CORTEXR_H_*/
