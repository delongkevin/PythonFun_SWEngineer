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
 
#ifndef __PMIC_UTILS_H
#define __PMIC_UTILS_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/csl/csl_types.h>
#include <ti/drv/pmic/include/pmic_types.h>
#include <ti/board/src/devices/pmic/tps65941.h>
#include <ti/drv/pmic/include/pmic_wdg.h>
#include <ti/drv/pmic/include/pmic_irq.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define LEOA_BUCK3_CTRL_SOFT_REBOOT  0x30
#define LEOA_BUCK5_CTRL_SOFT_REBOOT  0x31
#define LEOB_BUCK3_CTRL_SOFT_REBOOT  0x20
#define LEOB_BUCK4_CTRL_SOFT_REBOOT  0x20
#define LEOB_BUCK5_CTRL_SOFT_REBOOT  0x31
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                         External variables                                 */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/*
 * Purpose: Util function for Pmic write.
 * Description: Util function for Pmic write
 * Return Type: int32_t
 */
int32_t Pmic_utils_Write(Pmic_CoreHandle_t *pPmicCoreHandle, uint16_t regaddr, uint8_t regData);

/*
 * Purpose: Util function for Pmic write.
 * Description: Util function for Pmic write
 * Return Type: int32_t
 */
int32_t Pmic_utils_read(Pmic_CoreHandle_t *pPmicCoreHandle, uint16_t regaddr, uint8_t *regData);

/**
 * \brief   Clear the TPS65941 Recovery Counter
 *
 * This function is used to set/clear the watchdog powerhold function in the
 * TPS65941.
 *
 * \param   handle          [IN]    Low level driver
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtDisable      [IN]    Enable/Disable the watchdog
 *                                  Valid values:
 *                                  0
 *                                  1
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
int32_t Pmic_utils_tps65941RecovCounterClear(Pmic_CoreHandle_t *pPmicCoreHandle);

#if 0 /* Unused function */
/**
 * \brief   Enable/Disable the TPS65941 Watchdog function.
 *
 * This function is used to enable/disable the watchdog function in the
 * TPS65941.
 *
 * \param   handle          [IN]    Low level driver
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtDisable      [IN]    Enable/Disable the watchdog
 *                                  Valid values:
 *                                  BOARD_TPS65941_WDT_DISABLE
 *                                  BOARD_TPS65941_WDT_ENABLE
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
int32_t Pmic_utils_tps65941WdtDisable(Pmic_CoreHandle_t *pPmicCoreHandle,
                                      uint8_t wdtDisable);

/**
 * \brief   Set/Clear the TPS65941 WDG PWR HOLD register.
 *
 * This function is used to set/clear the watchdog powerhold function in the
 * TPS65941.
 *
 * \param   handle          [IN]    Low level driver
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtDisable      [IN]    Enable/Disable the watchdog
 *                                  Valid values:
 *                                  0
 *                                  1
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
int32_t Pmic_utils_tps65941WdPwrhold(Pmic_CoreHandle_t *pPmicCoreHandle,
                                      uint8_t value);

/**
 * \brief  TPS65941 Enter or exit to Long Window
 *
 * This function is used to return to Long Window or exit window
 * In  TPS65941 in either Long Window or exit Window.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   val             [IN]    Valid values:
 *                                  1 - Enter to Long Window
 *                                  0 - Exit from Long Window


 * \return  BOARD_SOK in case of success or appropriate error code.
 */
int32_t Pmic_utils_tps65941RetToLongWinDisable(void);
#endif

/**
 * \brief   TPS65941 watchdog configuration function.
 *
 * This function is used to configure the watchdog function parameters
 * in the TPS65941 in either trigger mode or Q&A (question and answer) mode.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtCfgMode      [IN]    Watchdog configuration mode
 *                                  Valid values:
 *                                  BOARD_TPS65941_WDT_QA_MODE
 *                                  BOARD_TPS65941_WDT_TRIGGER_MODE
 * \param   wdtCfg          [IN]    TPS65941 watchdog configuration
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
int32_t Pmic_utils_tps65941WdtConfig(Pmic_CoreHandle_t *pPmicCoreHandle,
                                     uint8_t wdtCfgMode,
                                     Board_Tps65941WdtCfg *wdtCfg);


/**
 * \brief   TPS65941 watchdog Long Windows status function.
 *
 * This function is used to get the error status from the TPS65941 watchdog.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtErrStat      [OUT]   TPS65941 Watchdog Long window status
 *                                  Valid Values:
 *                                  BOARD_TPS65941_WDT_ERR_LATCHED
 *                                  BOARD_TPS65941_WDT_NO_ERR
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
int32_t Pmic_utils_tps65941GetWdtFirstOkStat(Pmic_CoreHandle_t *pPmicCoreHandle,
                                      uint8_t *wdtFirstOK);

/**
 * \brief   TPS65941 watchdog configuration function.
 *
 * This function is used to configure the watchdog function parameters
 * in the TPS65941 in either trigger mode or Q&A (question and answer) mode.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtCfgMode      [IN]    Watchdog configuration mode
 *                                  Valid values:
 *                                  BOARD_TPS65941_WDT_QA_MODE
 *                                  BOARD_TPS65941_WDT_TRIGGER_MODE
 * \param   wdtCfg          [IN]    TPS65941 watchdog configuration
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
int32_t Pmic_utils_tps65941CheckWdtConfig(Pmic_CoreHandle_t *pPmicCoreHandle,
                                     const Pmic_WdgCfg_t  wdg_Cfg);

int32_t Pmic_utils_ReadInterrupts(Pmic_CoreHandle_t *pPmicCoreHandle, bool irqClear, Pmic_IrqStatus_t *errStat);

int32_t Pmic_utils_ClearInterrupts(Pmic_CoreHandle_t *pPmicCoreHandle, bool irqClear);
int32_t Pmic_utils_WdgSetConfig(Pmic_WdgCfg_t  wdg_Cfg);
int32_t Pmic_utils_CheckRecoveryCounter(void);
void Pmic_utils_SoftReboot(uint8_t SafeStateReason);
uint8_t pmic_utils_getLastReset(void);
uint8_t Pmic_utils_getCRCStatus(void);
void Pmic_utils_NvMRead_PMICLastResetReason(void);
bool Get_ResetPMICFlag(void);
void Pmic_utils_CheckforSoftResetReq(void);
#if 0 /* Unused function */
uint32_t Pmic_utils_GetIrqStatus(uint8_t device, uint8_t pos);
uint8_t Pmic_utils_GetRecoveryCounter(uint8_t device);
#endif
/* === End Of Header File ================================================= */
#endif  /* __PMIC_ERROR_H */
