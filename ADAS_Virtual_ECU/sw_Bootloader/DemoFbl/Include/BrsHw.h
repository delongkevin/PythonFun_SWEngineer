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
/** \file  File:  BrsHw.h
 *      Project:  Vector Basic Runtime System
 *       Module:  BrsHw for platform Texas Instruments Jacinto7
 *
 *  \brief Description:  This is the hardware specific header file for Vector Basic Runtime System (BRS).
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
 *  00.01.00  2020-04-01  visbwa  Initial creation from template
 *  01.00.00  2020-06-24  visbwa  Transferred CustomerDE from TI into VectorDE code basis,
 *                                updated to Brs_Template 1.0.0 for vBaseEnv 2.0,
 *                                implemented enable/disable/trigger interrupt functions
 *            2020-06-30  visbwa  Adaptions after Workshop3 with TI - Uart4, I2C, TogglePin, Board_init()
 *                                Added LED pin for board J721EVM
 *  01.00.01  2020-09-03  visdri  Add customer DE documentation for Jacinto-Cortex-R and TI image files
 *  01.01.00  2020-10-15  visdri  Update to support vBaseEnv FBL-Legacy w/o OS
 *  01.01.01  2020-10-23  visdri  Update debugger scripts
 *  01.01.02  2020-10-23  visdri  Moved gCslR5MpuCfg from TI provided startup code into this file (allow usage of
 *                                generic Brs_ArmCommon startup code)
 *            2020-11-13  visbwa  Review according to Brs_Template 1.01.01, removed AUTHOR IDENTITY
 *  01.02.00  2020-11-16  visbwa  Updates according to TI SDK 7.0 update delivery (several checks removed)
 *  01.03.00  2021-02-02  vismaa  Moved BrsHw_GetCore(void) to Brs_ArmCommon
 *            2021-03-17  visdri  Adapted to Brs_Template 1.02.00, moved revision history into BrsHw.h
 *  01.03.01  2021-05-05  vismaa  Added OCMS RAM / MSRAM in gCslR5MpuCfg for vHSM
 *  01.04.00  2021-07-29  visbwa  Updated TI environment (SDK header and libraries) to official TI SDK 7.1 Release
 *            2021-08-05  visbwa  Added support for Ethernet (CPSW2G initialization, provided by TI),
 *                                added usage of BRS_ENABLE_I2C_SUPPORT, update to Brs_Template 1.02.01
 *            2021-08-27  visdri  Updated TI boot images (binaries) suited to official TI SDK 7.1 Release
 *  01.05.00  2021-10-18  vishci  Added LLVMTEXASINSTRUMENTS compiler support
 *            2021-12-06  visbwa  Added parentheses in BRSHW_INTC_VIM macros, to solve issues with calculations as 'n'
 *  01.06.00  2022-01-12  vishci  Update to TI SDK 8.1 for llvmti compiler
 *  01.06.02  2022-03-18  visdri  Fix of the Update to TI SDK 8.1 for llvmti compiler
 *  01.07.00  2022-04-07  virmid  Added TDA4VE derivative and J721S2 evalboard support
 *********************************************************************************************************************/

#ifndef _BRSHW_H_
#define _BRSHW_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/*
 * Description: Inclusion of generic ARM parts
 */
#include "ARMBrsHw_CortexR.h"

#if defined (BRS_ENABLE_PORT)
  #include "BrsHw_Ports.h"
#endif

/**********************************************************************************************************************
 *  MODULE VERSION
 *********************************************************************************************************************/
/*
 * Description: This is the BrsHw main and bug fix version. The version numbers are BCD coded.
 *              E.g. a main version of 1.23 is coded with 0x0123, a bug fix version of 9 is coded 0x09.
 */

/* This is the BrsHw template main and bug fix version, the platform BrsHw is reviewed to */
#define BRSHW_SOURCECODE_TEMPLATE_VERSION        0x0102u
#define BRSHW_SOURCECODE_TEMPLATE_BUGFIX_VERSION 0x01u

/* This is the BrsHw main and bug fix version */
#define BRSHW_VERSION        0x0107u
#define BRSHW_BUGFIX_VERSION 0x00u

/**********************************************************************************************************************
 *  CONFIGURATION CHECK
 *********************************************************************************************************************/
/* The following parameters are necessary for this platform, to be generated by BRS-Cfg5-Generator into BrsCfg.h */
#if !defined (BRS_OSC_CLK)
  #error "BRS CHECK: The parameter BRS_OSC_CLK is missing! Please check your BRS Cfg5 configuration."
#endif

#if !defined (BRS_TIMEBASE_CLOCK)
  #error "BRS CHECK: The parameter BRS_TIMEBASE_CLOCK is missing! Please check your BRS Cfg5 configuration."
#endif

#if !defined (BRS_PERIPH_CLOCK)
  #error "BRS CHECK: The parameter BRS_PERIPH_CLOCK is missing! Please check your BRS Cfg5 configuration."
#endif

#if !defined (BRS_CPU_MAX_FREQUENCY)
  #error "BRS CHECK: The parameter BRS_CPU_MAX_FREQUENCY is missing! Please check your BRS Cfg5 configuration."
#endif

#if !defined (BRS_CPU_CORE_CORTEX_R5F)
  #error "BRS CHECK: The parameter BRS_CPU_CORE_x is missing or not supported! Please check your BRS Cfg5 configuration."
#endif

#if !defined (BRS_CPU_CORE_AMOUNT)
  #error "BRS CHECK: The parameter BRS_CPU_CORE_AMOUNT is missing! Please check your BRS Cfg5 configuration."
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define BRSHW_DERIVATIVE_CORE0_ID 0
#define BRSHW_DERIVATIVE_CORE1_ID 1
#define BRSHW_DERIVATIVE_CORE2_ID 2
#define BRSHW_DERIVATIVE_CORE3_ID 3
#define BRSHW_DERIVATIVE_CORE4_ID 4
#define BRSHW_DERIVATIVE_CORE5_ID 5

#define BRSHW_INIT_CORE_ID BRSHW_DERIVATIVE_CORE0_ID

/**********************************************************************************************************************
 * Compiler abstraction
 *********************************************************************************************************************/
/* part of ArmCommon */

/**********************************************************************************************************************
 *  BrsHW configuration
 *********************************************************************************************************************/
/* part of ArmCommon */

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/
/*
 * Description: These constants are used to propagate the Versions over module boundaries.
 *              The version numbers are BCD coded. E.g. a sub version of 23 is coded with 0x23, 
 *              a bug fix version of 9 is coded 0x09.
 */
extern uint8 const kBrsHwMainVersion;
extern uint8 const kBrsHwSubVersion;
extern uint8 const kBrsHwBugfixVersion;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/*****************************************************************************/
/* @brief      This function can be used to initialize controller specific
 *             stuff that is not related to one of the other InitPowerOn
 *             functions (e.g. code that is always mandatory, also if MCAL
 *             and/or OS is used). This function is called from BrsMain
 *             immediately after BrsHwDisableInterruptAtPowerOn() during
 *             initialization (if BRSHW_PREINIT_AVAILABLE is set in BrsHw.h).
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 *****************************************************************************/
#define BRSHW_PREINIT_AVAILABLE
void BrsHwPreInitPowerOn(void);

#if defined (BRS_ENABLE_WATCHDOG)
/*****************************************************************************/
/* @brief      This function must be used to initialize the Watchdog.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 *****************************************************************************/
void BrsHwWatchdogInitPowerOn(void);
#endif /*BRS_ENABLE_WATCHDOG*/

#if defined (BRS_ENABLE_PLLCLOCKS)
/*****************************************************************************/
/* @brief      This function must be used to initialize the PLL.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 *****************************************************************************/
void BrsHwPllInitPowerOn(void);
#endif /*BRS_ENABLE_PLLCLOCKS*/

#if defined (BRS_ENABLE_PORT)

/* BrsHwInitPortInput(), BrsHwInitPortOutput(), BrsHwInitPortInputOutput() are replaced by 
 * proprietary functions provided by TI. */

# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_START_SEC_RAM_CODE
  #include "Brs_MemMap.h"
# endif
/*****************************************************************************/
/* @brief      This function sets the output level of a port pin.
 * @pre        Port pin configurations available within BrsHw_Ports.h,
 *             no DrvPort used for port pin initialization and
 *             transferred port pin has to be initialized as output pin with
 *             GPIO functionality.
 * @param[in]  p     - brsHw_Port_PortType, to be set,
 *             Level - level, port pin has to be set to
 *                     (BRSHW_PORT_LOGIC_LOW or BRSHW_PORT_LOGIC_HIGH).
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsHwPortInitPowerOn() and
 *             provided to external modules (e.g. BrsMainTogglePin()).
 *****************************************************************************/
void BrsHwPort_SetLevel(brsHw_Port_PortType, uint8);

/*****************************************************************************/
/* @brief      This function reads the input level of a port pin.
 * @pre        Port pin configurations available within BrsHw_Ports.h,
 *             no DrvPort used for port pin initialization and
 *             transferred port pin has to be initialized as input pin with
 *             GPIO functionality.
 * @param[in]  p - brsHw_Port_PortType, to be read.
 * @param[out] -
 * @return     Level, read from port pin
 *             (BRSHW_PORT_LOGIC_LOW or BRSHW_PORT_LOGIC_HIGH).
 * @context    Function is provided to external modules.
 *****************************************************************************/
uint8 BrsHwPort_GetLevel(brsHw_Port_PortType);
# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_STOP_SEC_RAM_CODE
  #include "Brs_MemMap.h"
# endif

/*****************************************************************************/
/* @brief      This function must be used to initialize the used ports.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 *****************************************************************************/
void BrsHwPortInitPowerOn(void);
#endif /*BRS_ENABLE_PORT*/

/* BrsHwDisableInterruptAtPowerOn() is part of ArmCommon */

/*****************************************************************************/
/* @brief      Restart ECU (issue a software reset or jump to startup code)
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from e.g. ECU state handling
 *****************************************************************************/
void BrsHwSoftwareResetECU(void);

typedef enum
{
  BRSHW_RESET_SW,
  BRSHW_RESET_OTHER
}brsHw_ResetReasonType;

/*****************************************************************************/
/* @brief      Get reset reason
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     Reset reason
 * @context    Function is called from BrsMainStartup to determine if reset
 *             was triggered through software call (BrsHwSoftwareResetECU()).
 *****************************************************************************/
brsHw_ResetReasonType BrsHwGetResetReason(void);

/* BrsHwTime100NOP() is part of ArmCommon */

#if defined (BRS_ENABLE_SAFECTXSUPPORT)
/*****************************************************************************/
/* @brief      This API is used to enable hardware access in untrusted mode
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function must be called after all depending peripheral modules
 *             are supplied by proper clocks AND before the OS is started.
 *****************************************************************************/
void BrsHw_EnableHwAccess(void);
#endif /*BRS_ENABLE_SAFECTXSUPPORT*/

/* BrsHw_GetCore() is part of ArmCommon */

/*****************************************************************************/
/* @brief      This API is used to enable an interrupt source in the core
 *             interrupt controller.
 * @pre        -
 * @param[in]  Source to be enabled.
 * @param[in]  Priority level to be set.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 *****************************************************************************/
void BrsHw_EnableInterrupt(uint32, uint8);

/*****************************************************************************/
/* @brief      This API is used to disable an interrupt source in the core
 *             interrupt controller.
 * @pre        -
 * @param[in]  Source to be disabled.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 *****************************************************************************/
void BrsHw_DisableInterrupt(uint32);

/*****************************************************************************/
/* @brief      This API is used to trigger the given software interrupt source.
 * @pre        -
 * @param[in]  Source to be triggered.
 *             Some derivatives only support few software triggerable sources,
 *             check for their validity.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 *****************************************************************************/
void BrsHw_TriggerSoftwareInterrupt(uint32);

#if defined (BRS_ENABLE_OS_MULTICORESUPPORT)
/*****************************************************************************/
/* @brief      This API is used as sync barrier. It is used to unlock cores
 *             that are locked in the Startup code. The implementation is only
 *             needed on platforms, where all cores are started automatically
 *             after a power-on reset. All additional cores are looped, until
 *             the boot core reaches this function.
 * @pre        -
 * @param[in]  uint32 coreId
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainStartup on the boot core.
 *****************************************************************************/
void BrsHw_UnlockCores(uint32);
#endif /*BRS_ENABLE_OS_MULTICORESUPPORT*/

#endif /*_BRSHW_H_*/
