/**
 * @file pmic.h
 * @brief Header file for pmic module
 *
 * @details This file contains pmic module interface for other SWC
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2023.  Magna Electronics owns all
 *   rights to this work and intends to maintain it in confidence
 *   to preserve its trade secret status.  Magna Electronics
 *   reserves the right, under the copyright laws of the United
 *   States or those of any other country that may have jurisdiction,
 *   to protect this work as an unpublished work, in the event of
 *   an inadvertent or deliberate unauthorized publication.
 *   Magna Electronics also reserves its rights under all copyright
 *   laws to protect this work as a published work, when appropriate.
 *   Those having access to this work may not copy it, use it,
 *   modify it, or disclose the information contained in it without
 *   the written authorization of Magna Electronics.
 *
 * --------------------------------------------------------------------------
 * @author Pramod Kumar  (pramod.kumar1@magna.com)
 */
 
#ifndef __PMIC_H
#define __PMIC_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/drv/pmic/pmic.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define RESET_REGISTER_BIT_POSITION_MAX                       (25u) 
#define PMIC_MASK_HIGHER_BYTE                                 (0xFF00u)
#define PMIC_MASK_LOWER_BYTE                                  (0x00FFu)


/******   DID 0xFDF2 Byte_2 Value List      ******/
#define SAFESTATE_REASON_NO_ERROR                             (0U)
#define SAFESTATE_REASON_SDL_PBIST_MCU_TPOS                   (1U)
#define SAFESTATE_REASON_SDL_ECC_WKUP                         (2U)
#define SAFESTATE_REASON_SDL_TOG                              (3U)
#define SAFESTATE_REASON_PMIC_INIT_FAIL                       (4U)
#define SAFESTATE_REASON_VTM_TEMP                             (5U)
#define SAFESTATE_REASON_SDL_ESM_WKUP_REG                     (6U)
#define SAFESTATE_REASON_ERROR_MGR                            (7U)
#define SAFESTATE_REASON_PMIC_WDG_RESET_MCU1_0                (8U) /* the reset caused by code stuck in MCU1_0 which will stop feeding trigger pulses to PMIC */
#define SAFESTATE_REASON_SDL_PBIST_MCU_TNEG                   (9U)
#define SAFESTATE_REASON_SDL_PBIST_MAINR5_TPOS                (10U)
#define SAFESTATE_REASON_SDL_PBIST_MAINR5_TNEG                (11U)
#define SAFESTATE_REASON_SDL_LBIST_SMS            			  (12U)
#define SAFESTATE_REASON_SDL_LBIST_MCU         				  (13U)
#define SAFESTATE_REASON_SDL_LBIST_MAINR5         			  (14U)
#define SAFESTATE_REASON_SDL_ESM_MCU_REG                      (15U)
#define SAFESTATE_REASON_SDL_ECC_Main_CBASS_Parity            (16U)
#define SAFESTATE_REASON_SDL_POK                              (17U)
#define SAFESTATE_REASON_SDL_CCM            				  (18U)
#define SAFESTATE_REASON_SDL_VTM_REG						  (19U)
#define SAFESTATE_REASON_PMIC_INIT_I2C_FAIL                   (20U)
#define SAFESTATE_REASON_PMIC_BIST_FAIL                       (21U)
#define SAFESTATE_REASON_PMIC_WDG_CFG_FAIL                    (22U)
#define SAFESTATE_REASON_OS_ERROR_HOOK                        (23U)
#define SAFESTATE_REASON_OS_PROTECTION_HOOK                   (24U)
#define SAFESTATE_REASON_OS_PANIC_HOOK                        (25U)
/* All the Wdg reset reason */
#define	SAFESTATE_REASON_MCU1_0_CHKPT_0_Task_WDG_Main		  (26U)
#define	SAFESTATE_REASON_MCU1_0_CHKPT_4_Safety_Task_00_10ms	  (27U)
#define	SAFESTATE_REASON_MCU1_0_CHKPT_5_Safety_Task_01_10ms   (28U)
#define	SAFESTATE_REASON_MCU1_0_CHKPT_6_Safety_Com_Task_10ms  (29U)
#define	SAFESTATE_REASON_MCU2_0_CHKPT_0						  (30U)
#define	SAFESTATE_REASON_MCU2_1_CHKPT_0_Task_BSW_Safety_10ms  (31U)
#define	SAFESTATE_REASON_MCU2_1_CHKPT_1_Task_BSW_QM_1ms		  (32U)
#define	SAFESTATE_REASON_MCU2_1_CHKPT_2_Task_BSW_QM_10ms	  (33U)
#define	SAFESTATE_REASON_MCU2_1_CHKPT_3						  (34U)
#define	SAFESTATE_REASON_MPU1_0_CHKPT_0						  (35U)

#define SAFESTATE_REASON_PMIC_GPIO2_CFG_FAIL                  (36U)
#define	SAFESTATE_REASON_MCU2_0_CHKPT_1						  (37U)
#define	SAFESTATE_REASON_MCU2_0_CHKPT_2						  (38U)
#define	SAFESTATE_REASON_MCU1_0_CHKPT_UNKNOWN				  (39U)
#define	SAFESTATE_REASON_MCU2_0_CHKPT_UNKNOWN				  (40U)
#define	SAFESTATE_REASON_MCU2_1_CHKPT_UNKNOWN				  (41U)
#define	SAFESTATE_REASON_MPU1_0_CHKPT_UNKNOWN				  (42U)
#define	SAFESTATE_REASON_MCU1_0_CHKPT_7_Safety_Task_200ms	  (43U)
#define SAFESTATE_REASON_NVM_WRITE_ALL_FAIL 				  (45U)

/* SSM Reset Reasons */
#define SSM_BOOT_ISSUE_RESET_REASON_BASE                      (60U)
#define SSM_BOOT_ISSUE_CORE_MCU_1_0                           (SSM_BOOT_ISSUE_RESET_REASON_BASE + 0U)
#define SSM_BOOT_ISSUE_CORE_MCU_2_0                           (SSM_BOOT_ISSUE_RESET_REASON_BASE + 1U)
#define SSM_BOOT_ISSUE_CORE_MCU_2_1                           (SSM_BOOT_ISSUE_RESET_REASON_BASE + 2U)
#define SSM_BOOT_ISSUE_CORE_QNX                               (SSM_BOOT_ISSUE_RESET_REASON_BASE + 3U)
#define SSM_BOOT_ISSUE_MAX                                    (SSM_BOOT_ISSUE_CORE_QNX)

#define SSM_IPC_READY_FAILURE_RESET_REASON_BASE               (SSM_BOOT_ISSUE_MAX + 1U)
#define SSM_IPC_READY_FAILURE_MCU_1_0_APP_CALDATAPROVIDER     (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + 0U)
#define SSM_IPC_READY_FAILURE_MCU_1_0_APP_PROXIMANAGER        (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + 1U)
#define SSM_IPC_READY_FAILURE_MCU_1_0_APP_PARTNUMMANAGER      (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + 2U)
#define SSM_IPC_READY_FAILURE_MCU_1_0_APP_SAFEVCANRX          (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + 3U)
#define SSM_IPC_READY_FAILURE_MCU_2_0_APP_ERRORMGR            (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + 4U)
#define SSM_IPC_READY_FAILURE_MCU_2_0_APP_HMIMGR              (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + 5U)
#define SSM_IPC_READY_FAILURE_MCU_2_0_APP_USS_PWR             (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + 6U)
#define SSM_IPC_READY_FAILURE_MCU_2_1_APP_ERRORMGR            (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + 7U)
#define SSM_IPC_READY_FAILURE_MCU_2_1_APP_TRSC                (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + 8U)
#define SSM_IPC_READY_FAILURE_MCU_2_1_APP_THASM               (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + 9U)
#define SSM_IPC_READY_FAILURE_MCU_2_1_APP_APFUSION            (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + 10U)
#define SSM_IPC_READY_FAILURE_MCU_2_1_APP_AUTOPARK            (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + 11U)
#define SSM_IPC_READY_FAILURE_MCU_2_1_APP_USS                 (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + 12U)
#define SSM_IPC_READY_FAILURE_MCU_2_1_APP_FOD                 (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + 13U)
#define SSM_IPC_READY_FAILURE_MCU_2_1_APP_ARBITER             (SSM_IPC_READY_FAILURE_RESET_REASON_BASE + 14U)
#define SSM_IPC_READY_FAILURE_MAX                             (SSM_IPC_READY_FAILURE_MCU_2_1_APP_ARBITER)

#define SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE                  (SSM_IPC_READY_FAILURE_MAX + 1U)
#define SSM_SHUTDOWN_ISSUE_MCU_1_0_APP_CALDATAPROVIDER        (SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE + 0U)
#define SSM_SHUTDOWN_ISSUE_MCU_1_0_APP_PROXIMANAGER           (SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE + 1U)
#define SSM_SHUTDOWN_ISSUE_MCU_1_0_APP_PARTNUMMANAGER         (SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE + 2U)
#define SSM_SHUTDOWN_ISSUE_MCU_1_0_APP_SAFEVCANRX             (SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE + 3U)
#define SSM_SHUTDOWN_ISSUE_MCU_2_0_APP_ERRORMGR               (SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE + 4U)
#define SSM_SHUTDOWN_ISSUE_MCU_2_0_APP_HMIMGR                 (SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE + 5U)
#define SSM_SHUTDOWN_ISSUE_MCU_2_0_APP_USS_PWR                (SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE + 6U)
#define SSM_SHUTDOWN_ISSUE_MCU_2_1_APP_ERRORMGR               (SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE + 7U)
#define SSM_SHUTDOWN_ISSUE_MCU_2_1_APP_TRSC                   (SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE + 8U)
#define SSM_SHUTDOWN_ISSUE_MCU_2_1_APP_THASM                  (SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE + 9U)
#define SSM_SHUTDOWN_ISSUE_MCU_2_1_APP_APFUSION               (SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE + 10U)
#define SSM_SHUTDOWN_ISSUE_MCU_2_1_APP_AUTOPARK               (SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE + 11U)
#define SSM_SHUTDOWN_ISSUE_MCU_2_1_APP_USS                    (SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE + 12U)
#define SSM_SHUTDOWN_ISSUE_MCU_2_1_APP_FOD                    (SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE + 13U)
#define SSM_SHUTDOWN_ISSUE_MCU_2_1_APP_ARBITER                (SSM_SHUTDOWN_ISSUE_RESET_REASON_BASE + 14U)
#define SSM_SHUTDOWN_ISSUE_MAX                                (SSM_SHUTDOWN_ISSUE_MCU_2_1_APP_ARBITER)


/****** End of DID 0xFDF2 Byte_2 Value List ******/

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                         External variables                                 */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
extern int32_t Pmic_F_Init_s32(void);
extern int32_t Pmic_F_EarlyInit_s32(void);
extern void    Pmic_F_RefreshWdg_v(void);
void    Pmic_F_SafeState2_v(uint8_t SafeStateReason);
/* Declaration added in Trusted_Func_Api.h -> extern int32_t Pmic_AppEnterInLongWindow(void); */
extern void    Pmic_F_StopPettingWdg_v(void);
extern void    Pmic_F_MainTask_v(void);
extern void    Pmic_F_Config_step1_v(void);
void pmic_criticalSectionStartFn(void);
void pmic_criticalSectionStopFn(void);

int32_t pmic_regRead(Pmic_CoreHandle_t  *pmicCorehandle,
                     uint8_t             instType,
                     uint16_t            regAddr,
                     uint8_t            *pBuf,
                     uint8_t             bufLen);

int32_t pmic_regWrite(Pmic_CoreHandle_t  *pmicCorehandle,
                      uint8_t             instType,
                      uint16_t            regAddr,
                      uint8_t            *pBuf,
                      uint8_t             bufLen);

/* === End Of Header File ================================================= */
#endif  /* __PMIC_H */
