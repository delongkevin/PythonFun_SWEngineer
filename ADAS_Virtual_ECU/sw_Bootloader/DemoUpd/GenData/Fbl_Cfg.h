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
 *            Module: Fbl
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D09
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fbl_Cfg.h
 *   Generation Time: 2023-10-09 10:56:17
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D09
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/


#if !defined(__FBL_CFG_H__)
#define __FBL_CFG_H__

/* Global Constant Macros ********************************************************************************************/
#ifndef FBL_USE_DUMMY_STATEMENT
#define FBL_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FBL_DUMMY_STATEMENT
#define FBL_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FBL_DUMMY_STATEMENT_CONST
#define FBL_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FBL_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FBL_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef FBL_ATOMIC_VARIABLE_ACCESS
#define FBL_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef FBL_PROCESSOR_TDA4VE88
#define FBL_PROCESSOR_TDA4VE88
#endif
#ifndef FBL_COMP_LLVMTEXASINSTRUMENTS
#define FBL_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef FBL_GEN_GENERATOR_MSR
#define FBL_GEN_GENERATOR_MSR
#endif
#ifndef FBL_CPUTYPE_BITORDER_LSB2MSB
#define FBL_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef FBL_CONFIGURATION_VARIANT_PRECOMPILE
#define FBL_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef FBL_CONFIGURATION_VARIANT_LINKTIME
#define FBL_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef FBL_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define FBL_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef FBL_CONFIGURATION_VARIANT
#define FBL_CONFIGURATION_VARIANT FBL_CONFIGURATION_VARIANT_LINKTIME
#endif
#ifndef FBL_POSTBUILD_VARIANT_SUPPORT
#define FBL_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

/* FblOem__base ******************************************************************************************************/
#define FBL_DISABLE_STAY_IN_BOOT 
#define FBL_USE_OWN_MEMCPY 
#define FBL_WATCHDOG_OFF 
#define FBL_WATCHDOG_TIME                        (1u / FBL_REPEAT_CALL_CYCLE) 
#define FBL_HEADER_ADDRESS                       0x00280000u 
#define FBL_ENABLE_APPL_TIMER_TASK 
#define FBL_ENABLE_APPL_TASK 
#define FBL_ENABLE_APPL_STATE_TASK 
#define SWM_DATA_MAX_NOAR                        8u 
#define FBL_DIAG_BUFFER_LENGTH                   4095u 
#define FBL_DIAG_TIME_P2MAX                      (10u / FBL_REPEAT_CALL_CYCLE) 
#define FBL_DIAG_TIME_P3MAX                      (5000u / FBL_REPEAT_CALL_CYCLE) 
#define FBL_DISABLE_SLEEPMODE 
#define FBL_SLEEP_TIME                           300000u 
#define FBL_DISABLE_GAP_FILL 
#define kFillChar                                0xFFu 
#define FBL_DISABLE_GATEWAY_SUPPORT 
#define FBL_ENABLE_PRESENCE_PATTERN 
#define FBL_ENABLE_FBL_START 
#define FBL_ENABLE_COMMON_DATA 
#define FBL_DISABLE_RESPONSE_AFTER_RESET 
#define FBL_DISABLE_USERSUBFUNCTION 
#define FBL_DISABLE_USERSERVICE 
#define FBL_DISABLE_USERROUTINE 
#define FBL_DIAG_TIME_S3EXT                      (0u / FBL_REPEAT_CALL_CYCLE) 
#define FBL_DIAG_TIME_S3PRG                      (0u / FBL_REPEAT_CALL_CYCLE) 
#define FBL_DISABLE_HARDWARE_SWAP 
#define FBL_DISABLE_XCP 
#define FBL_DIAG_DISABLE_FLASHDRV_DOWNLOAD 
#define FBL_DIAG_ENABLE_FLASHDRV_ROM 
#define FBL_DISABLE_DATA_PROCESSING 
#define FBL_DISABLE_ENCRYPTION_MODE 
#define FBL_DISABLE_COMPRESSION_MODE 
#define FBL_INTEGRATION                          2u 
#define FBL_PRODUCTION                           1u 
#define FBL_PROJECT_STATE                        FBL_INTEGRATION 
#define FBL_ENABLE_SYSTEM_CHECK 
#define FBL_ENABLE_DEBUG_STATUS 
#define FBL_ENABLE_ASSERTION 
#define FBL_MEM_PROC_BUFFER_SIZE                 256u 
#define FBL_MEM_DISABLE_VERIFY_INPUT 
#define FBL_MEM_DISABLE_VERIFY_PROCESSED 
#define FBL_MEM_DISABLE_VERIFY_PIPELINED 
#define FBL_MEM_DISABLE_VERIFY_OUTPUT 
#define FBL_MEM_VERIFY_SEGMENTATION              256u 
#define FBL_DISABLE_ADAPTIVE_DATA_TRANSFER_RCRRP 
#define FBL_DISABLE_PIPELINED_PROGRAMMING 
#define FBL_DISABLE_SUSPEND_PROGRAMMING 
#define FBL_MEM_WRITE_SEGMENTATION               4096u 
#define FBL_ENABLE_UNALIGNED_DATA_TRANSFER 
#define FBL_BLOCK_START_ADDRESS                  0x00280000u 
#define FBL_BLOCK_LENGTH                         524288u 
#define FBL_DISABLE_OTA 
#define FBL_DISABLE_ONE_STEP_UPDATER 

/* FblHal ************************************************************************************************************/
#include "FblHal_Cfg.h"
/* FblOem_Fca *****************************************************************************************************/
#define FBL_ENABLE_SEC_ACCESS_DELAY 
#define FBL_SEC_ACCESS_DELAY_TIME                       50 
#define FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS 
#define FBL_DIAG_DISABLE_REQUEST_UPLOAD 
#define FBL_APPL_DISABLE_STARTUP_DEPENDENCY_CHECK 
#define FBL_DIAG_ENABLE_SECACCESS_STANDARD 
#define FBL_DIAG_DISABLE_SECACCESS_AUTHENTICATED 

/* User Config File **************************************************************************************************/
/* User Config File Start */
/* Wait time in FBL after abnormal shutdown */
#define FBL_DIAG_BOOT_TIMOUT_COUNTER   25

/* Flash erased detection, skip erase process if logical block is already erased */
#define FBL_ENABLE_FLASH_ERASED_DETECTION

/* Number of invalid security access attempts */
/* Default is one single false attempt, see CS.00099, RQMT9.3.3-3 */
#define kSecMaxInvalidKeys 1u

/* Number of bytes in dummy EEPROM / NVM */
#define EEP_BUFFER_SIZE 0x1000u


/* FlexNVM: Flash sector number for certificate backup */
#define BACKUP_SECTOR_NO               18u

/* Settings for boot manager */

/* Configuration has BootManager */
#define FBL_BM_ENABLE_BOOTMANAGER

#if defined( FBL_BM_ENABLE_BOOTMANAGER )
/* Prototype of startup code */
extern void _START(void);
# define FBL_STARTUP_ADDR _START

/* Bootmanager performs (part-)verification of FBL */
# define FBL_BM_DISABLE_VERIFICATION

# define FBL_BM_FblBmInfoHdrAddr        0xA00041C8u
# define FBL_BM_FblPresPatternAddress   0x1FE00u
# define FBL_BM_FblMagicFlag            0x12345678u

/* Appl settings */
# define FBL_BM_ApplBmInfoHdrAddr       0xA0040380u
# define FBL_BM_ApplMagicFlag           0x87654321u
# define FBL_BM_UpdMagicFlag            0xABDCEF12u
# define APPL_STARTUP_ADDR              _START

#endif /* FBL_BM_ENABLE_BOOTMANAGER */ 

#define FBL_ENABLE_VECTOR_HW
#define FBL_RESET_ENTRY_LABEL brsStartupEntry

#define FBL_MIO_DISABLE_SEGMENT_CACHING

#define FBL_BM_HEADER_ADDRESS 0x280020
/* User Config File End */


/* User Section ******************************************************************************************************/

#endif /* __FBL_CFG_H__ */

