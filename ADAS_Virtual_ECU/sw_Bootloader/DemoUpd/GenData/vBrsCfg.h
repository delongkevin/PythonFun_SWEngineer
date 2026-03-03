/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: vBRS
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D09
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: .\vBrsCfg.h
 *   Generation Time: 2023-10-09 10:56:17
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D09
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Please note:
 *    The demo and example programs only show special aspects of the software. With regard to the fact
 *    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
 *    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *********************************************************************************************************************/

#ifndef _VBRSCFG_H_
#define _VBRSCFG_H_

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#if !defined (BRS_INCLUDED_BY_ASM_FILE)
# include "Std_Types.h"
#endif

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#define BASIC_RUNTIME_SYSTEM_TYPE_MSR4

#define BRS_GENERATED_HW_CONFIG_VERSION 392U

/*******************************************************************************
 Standard BRS configuration
*******************************************************************************/
/*******************************************************************************
 Generic TestSuite Support
 *******************************************************************************/
/* Enable support of the Generic TestSuite connection.
   Via the define BRS_ENABLE_TESTSUITE_SUPPORT, the Generic TestSuite concept 
   headerfile BrsTestsuite.h will be included and the Generic Testsuite init 
   function BrsTestsuiteInit() will be called within BrsMain.c. */
/* Testsuite support is disabled (#define BRS_ENABLE_TESTSUITE_SUPPORT) */

/* TCC support is disabled (#define BRS_ENABLE_TCC_COMIF_SUPPORT) */

/* LED support is disabled (#define BRS_ENABLE_SUPPORT_LEDS) */

/* Toggle custom pin support is disabled (#define BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN) */

/* Toggle watchdog pin support is disabled (#define BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN) */


/* Not the first execution instance of BRS within the system. 
   (#define BRS_FIRST_EXECUTION_INSTANCE) */

/*******************************************************************************
 Additional BRS support features
*******************************************************************************/
/* Enable support of SafeContext OS (used for OS partitioning UseCase). */
/* SafeContext support is disabled (#define BRS_ENABLE_SAFECTXSUPPORT) */

/* Enable support of MultiCore OS. */
/* MultiCore OS support is disabled (#define BRS_ENABLE_OS_MULTICORESUPPORT) */

/* Switches to enable support of FlashBootLoader and to define the FBL Type. */
#define BRS_ENABLE_FBL_SUPPORT
/* Definition of the FBL Execution Instance. */
#define BRS_FBL_INSTANCE_UPDATER
/* Configure, if the FBL stack should be started inside main() via a call 
   of EcuM_Init() or a call of FblMain().
   This parameter only has an effect, if Execution Instance is "FBL", 
   "FBL_Updater", "BM" or "BM_FBL".
   FBL without EcuM_Init() is the oldstyle FBL integration, started with 
   a direct call of FblMain().
   FBL with EcuM_Init() means, module initialization is done in EcuM_Init() 
   (real EcuM or EcuM Stub), but the cyclic handling is done in FBL. */
#define BRS_FBL_WITH_ECUMINIT
/* Configure, if the additional ExceptionTable in RAM should be initialized.
   This will cause a call of BrsHw_ExceptionTable_Init() in main(), which 
   will program the vector table base address to Brs_ExcVectRam. The 
   depending SectionGroup needs to be configured with Init Policy COPY_TO_RAM 
   in vLinkGen as well.
   This allows proper exception handling during erase/re-program of flash. */
/* ExceptionTable in RAM support is disabled 
   (#define BRS_FBL_EXCEPTIONTABLE_IN_RAM) */

/* Switch to enable support of Hardware Security Module (HSM). */
/* HSM support is disabled (#define BRS_ENABLE_HSM_SUPPORT) */

/* Switch to enable support of Hardware Security Module (HSM) Updater. */
/* HSM Updater support is disabled (#define BRS_ENABLE_HSM_UPDATER_SUPPORT) */

/* Switch to enable support of OS UseCase "Interrupt Only". */
/* OS UseCase "Interrupt Only" is disabled (#define BRS_ENABLE_OS_INTERRUPT_ONLY) */

/*******************************************************************************
 BRS hardware configuration constants
*******************************************************************************/
/* Frequency of the board specific external oscillator. */
/* Main Oscillator Clock (Hz) */
#define BRS_OSC_CLK 19200000

/* Frequency, used for PLL calculation (normally used as CPU core clock). */
/* Timebase Clock (MHz) */
#define BRS_TIMEBASE_CLOCK 1000

/* Frequency of the controller peripherals, at least for the default timer, used by the OS.
   This frequency value is used to calculate the proper value of the TicksPerBase value inside 
   the OS configuration.
   If the frequencies for communication peripherals differ from this peripheral clock, 
   they could be configured within the depending communictaion channel configuration 
   (e.g. vBRSHwConfig/vBRSDriverHandlingCAN/vBRSDriverHandlingCAN_Clock). */
/* Peripheral Clock (Hz) */
#define BRS_PERIPH_CLOCK 19200000

/*******************************************************************************
 BRS software modules
*******************************************************************************/
/* Enable the handling of Ports configuration inside BrsHw. */
#define BRS_ENABLE_PORT
/* Enable the handling of Watchdog configuration inside BrsHw. */
#define BRS_ENABLE_WATCHDOG
/* Enable the handling of PLL and Clocks configuration inside BrsHw. */
#define BRS_ENABLE_PLLCLOCKS

/*******************************************************************************
 Tested Derivative: TI TDA4VE88
*******************************************************************************/
#define BRS_DERIVATIVE_TDA4VE88

/*******************************************************************************
 CPU Core
 possible values are:
 BRS_CPU_CORE_OTHER: Generic value for cores with no specific value
 BRS_CPU_CORE_ARC_EM6: DesignWare ARC EM6
 BRS_CPU_CORE_CORTEX_M0: Arm Cortex M0
 BRS_CPU_CORE_CORTEX_M0PLUS: Arm Cortex M0+
 BRS_CPU_CORE_CORTEX_M3: Arm Cortex M3
 BRS_CPU_CORE_CORTEX_M4: Arm Cortex M4
 BRS_CPU_CORE_CORTEX_M4F: Arm Cortex M4F
 BRS_CPU_CORE_CORTEX_M7: Arm Cortex M7
 BRS_CPU_CORE_CORTEX_M33: Arm Cortex M33
 BRS_CPU_CORE_CORTEX_R4: Arm Cortex R4
 BRS_CPU_CORE_CORTEX_R4F: Arm Cortex R4F
 BRS_CPU_CORE_CORTEX_R5: ARM Cortex R5
 BRS_CPU_CORE_CORTEX_R5F: Arm Cortex R5F
 BRS_CPU_CORE_CORTEX_R7: ARM Cortex R7
 BRS_CPU_CORE_CORTEX_R52: Arm Cortex R52
 BRS_CPU_CORE_E200Z0: NXP/ST PowerPC RISC Core e200z0
 BRS_CPU_CORE_E200Z210: NXP/ST PowerPC RISC Core e200z210
 BRS_CPU_CORE_E200Z215: NXP/ST PowerPC RISC Core e200z215
 BRS_CPU_CORE_E200Z225: NXP/ST PowerPC RISC Core e200z225
 BRS_CPU_CORE_E200Z410: NXP/ST PowerPC RISC Core e200z410
 BRS_CPU_CORE_E200Z420: NXP/ST PowerPC RISC Core e200z420
 BRS_CPU_CORE_E200Z425: NXP/ST PowerPC RISC Core e200z425
 BRS_CPU_CORE_E200Z710: NXP/ST PowerPC RISC Core e200z710
 BRS_CPU_CORE_E200Z720: NXP/ST PowerPC RISC Core e200z720
 BRS_CPU_CORE_E200Z726: NXP/ST PowerPC RISC Core e200z726
 BRS_CPU_CORE_E200Z759: NXP/ST PowerPC RISC Core e200z759
 BRS_CPU_CORE_G3K: Renesas G3K
 BRS_CPU_CORE_G3KH: Renesas G3KH
 BRS_CPU_CORE_G3M: Renesas G3M
 BRS_CPU_CORE_G4MH: Renesas G4MH
 BRS_CPU_CORE_TC161: Infineon TriCore Aurix Core
 BRS_CPU_CORE_TC162: Infineon TriCore AurixPlus Core
 BRS_CPU_CORE_TC18: Infineon TriCore Aurix 3G (TC4xx)
*******************************************************************************/
#define BRS_CPU_CORE_CORTEX_R5F

/*******************************************************************************
 CPU Max Frequency (MHz)
*******************************************************************************/
/* Configure the maximum frequency of this derivative.
   This value is used to validate the vBRS PLL configuration. */
#define BRS_CPU_MAX_FREQUENCY 1000

/*******************************************************************************
 CPU Core Amount (number of cores)
*******************************************************************************/
/* Configure the amount of cores, available on this derivative. */
#define BRS_CPU_CORE_AMOUNT 6

/*******************************************************************************
 CPU Init Core
*******************************************************************************/
/* Configure the core ID of the core, which should be used for general 
   initialization. For normal, this is the boot core. */
#define BRS_CPU_INIT_CORE 0

/*******************************************************************************
 Instruction Set
 possible values are:
 BRS_INSTRUCTION_SET_THUMB: Thumb Mode for Arm core controllers
 BRS_INSTRUCTION_SET_ARM: Arm Mode for Arm core controllers
 BRS_INSTRUCTION_SET_VLE: Vle Mode for PPC core controllers
 BRS_INSTRUCTION_SET_BOOKE: Book-E Mode for PPC core controllers
*******************************************************************************/
/* Select the platform dependent Instruction Set for compile/link of the project.
   Note: not all platforms are supporting different instruction sets. */
#define BRS_INSTRUCTION_SET_ARM

/*******************************************************************************
 Floating Point Unit (FPU)
*******************************************************************************/
/* Enable FPU usage on the controller. This has effect on the compiler/linker 
   options. 
   Note: not all platforms are supporting enabling/disabling of FPU usage. */
#define BRS_FPU_USED

/*******************************************************************************
 Evaluation Board: No Led Support
*******************************************************************************/
/* Define, used in SourceCode, for this specific Evaluation Board.
   Most times, this is used for board specific pin settings. */ 
#define BRS_EVA_BOARD_J721S2

/*******************************************************************************
 Init Patterns
*******************************************************************************/
/* Configure the init pattern for the Brs_MemoryZeroInit() call within 
   Brs_ApplicationEntry().
   This value is for the blocks, configured with "Init Policy" = ZERO_INIT and 
   a "Init Stage" from ZERO up to THREE within the vLinkGen configuration.
   The pattern must be 32-bit aligned. Default value is 0x0. */
#define BRS_INIT_PATTERN_BLOCKS (0x0UL)

/* Configure the init pattern for the Brs_MemoryZeroInit() call within 
   Brs_ApplicationEntry().
   This value is for the blocks, configured with "Init Policy" = ZERO_INIT and 
   the "Init Stage" HARD_RESET_ONLY within the vLinkGen configuration.
   The pattern must be 32-bit aligned. Default value is 0x0. */
#define BRS_INIT_PATTERN_HARDRESET_BLOCKS (0x0UL)

/* Configure the init pattern for the Brs_MemoryZeroInit() call within 
   Brs_ApplicationEntry().
   This value is for the groups, configured with "Init Policy" = ZERO_INIT and 
   a "Init Stage" from ZERO up to THREE within the vLinkGen configuration.
   The pattern must be 32-bit aligned. Default value is 0x0. */
#define BRS_INIT_PATTERN_AREAS (0x0UL)

/* Configure the init pattern for the Brs_MemoryZeroInit() call within
   Brs_ApplicationEntry().
   This value is for the groups, configured with "Init Policy" = ZERO_INIT and 
   the "Init Stage" HARD_RESET_ONLY within the vLinkGen configuration.
   The pattern must be 32-bit aligned. Default value is 0x0. */
#define BRS_INIT_PATTERN_HARDRESET_AREAS (0x0UL)

#endif /*_VBRSCFG_H_*/

