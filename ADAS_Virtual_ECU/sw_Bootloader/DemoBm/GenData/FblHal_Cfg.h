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
 *            Module: FblHal
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FblHal_Cfg.h
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/


#if !defined(__FBL_HAL_H__)
#define __FBL_HAL_H__

/* FblHal__base ******************************************************************************************************/
#define FBL_FLASH_DISABLE_ECC_SAFE_READ 
#define FLASH_SIZE                      4 
#define FBL_TIMER_RELOAD_VALUE          19199 
#define FBL_TIMER_PRESCALER_VALUE       1 

/* Derivative Specific Defines */
#define V_COMP_LLVMTI
#define V_CPU_JACINTO7
#define V_COMP_LLVMTI_JACINTO7
#define C_CPUTYPE_32BIT
#define VGEN_ENABLE_CANFBL
#define V_SUPPRESS_EXTENDED_VERSION_CHECK
#define C_CPUTYPE_LITTLEENDIAN
#define V_DEF_SUPPORTED_PLATFORM
#define FBL_TIMER_MCU_BASE             0x40400000uL
#define FBL_TIMER_MAIN_BASE            0x02400000uL
#define FBL_GPIO_BASE                  0x00600000uL
#define FBL_SFR_BASE_ADRESSES_PRECONFIGURED

/* FblHal_Generic ****************************************************************************************************/

#endif /* __FBL_HAL_H__ */

