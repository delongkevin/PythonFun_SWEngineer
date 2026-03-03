/**
 * @file pmic_error.c
 * @brief Safe state implementation for PMIC driver
 *
 * @details Safe state implementation for PMIC driver
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
 * @author 
 */
 
/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include "pmic_cfg.h"
#include <ti/drv/pmic/pmic.h>
#include <ti/drv/pmic/src/pmic_io_priv.h>

#include <ti/board/src/j721s2_hyd/include/board_power.h>
#include "app_log_Boot.h"
#include "tps65941_Reg.h"
#include <ti/drv/pmic/include/pmic_irq.h>

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */


/* ===========================================================================
*
* Typedefs
*
* ========================================================================= */


/* ===========================================================================
*
* Private functions
*
* ========================================================================= */


/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */
pmic_device_t pmic_device[PMIC_DEV_NUM] = {
    [PMIC_DEV_0] = {
        .name = "PMIC LEO-A",
        .deviceNum = (uint8_t)PMIC_DEV_0,
        .pmicCoreHandle = {0},
        .pmicConfigData = {
            .pmicDeviceType      = PMIC_DEV_LEO_TPS6594X,
            .commMode            = PMIC_INTF_SINGLE_I2C, //PMIC_INTF_DUAL_I2C,
            .slaveAddr           = LEO_PMICA_SLAVE_ADDR,
            .nvmSlaveAddr        = LEO_PMICA_PAGE1_SLAVE_ADDR,
            .qaSlaveAddr         = LEO_PMICA_WDG_SLAVE_ADDR,
            .i2c1Speed           = PMIC_I2C_STANDARD_MODE,
            .crcEnable           = (bool)true,
            .pFnPmicCommIoRead   = pmic_regRead,
            .pFnPmicCommIoWrite  = pmic_regWrite,
            .pFnPmicCritSecStart  = pmic_criticalSectionStartFn,
            .pFnPmicCritSecStop   = pmic_criticalSectionStopFn,
            .validParams         =
               (uint32_t)(PMIC_CFG_DEVICE_TYPE_VALID_SHIFT |
                PMIC_CFG_COMM_MODE_VALID_SHIFT |
                PMIC_CFG_SLAVEADDR_VALID_SHIFT |
                PMIC_CFG_QASLAVEADDR_VALID_SHIFT |
                PMIC_CFG_NVMSLAVEADDR_VALID_SHIFT |
                PMIC_CFG_COMM_IO_RD_VALID_SHIFT |
                PMIC_CFG_COMM_IO_WR_VALID_SHIFT |
                PMIC_CFG_CRITSEC_START_VALID_SHIFT |
                PMIC_CFG_CRITSEC_STOP_VALID_SHIFT |
                PMIC_CFG_COMM_HANDLE_VALID_SHIFT),
        },
        .rdIntr = (bool)true,
        .rdDeviceInfo = (bool)false,
        .clrIrqSts = (bool)true,
        .checkWdgConfig = (bool)true,
        .clrRecovCounter = (bool)false,
    },
    [PMIC_DEV_1] = {
        .name = "PMIC LEO-B",
        .deviceNum = (uint8_t)PMIC_DEV_1,
        .pmicCoreHandle = {0},
        .pmicConfigData = {
            .pmicDeviceType      = PMIC_DEV_LEO_TPS6594X,
            .commMode            = PMIC_INTF_SINGLE_I2C,
            .slaveAddr           = LEO_PMICB_SLAVE_ADDR,
            .nvmSlaveAddr        = LEO_PMICB_PAGE1_SLAVE_ADDR,
            .qaSlaveAddr         = LEO_PMICB_WDG_SLAVE_ADDR,
            .i2c1Speed           = PMIC_I2C_STANDARD_MODE,
            .crcEnable           = (bool)true,
            .pFnPmicCommIoRead   = pmic_regRead,
            .pFnPmicCommIoWrite  = pmic_regWrite,
            .pFnPmicCritSecStart  = pmic_criticalSectionStartFn,
            .pFnPmicCritSecStop   = pmic_criticalSectionStopFn,
            .validParams         =
               (uint32_t)(PMIC_CFG_DEVICE_TYPE_VALID_SHIFT |
                PMIC_CFG_COMM_MODE_VALID_SHIFT |
                PMIC_CFG_SLAVEADDR_VALID_SHIFT |
                PMIC_CFG_NVMSLAVEADDR_VALID_SHIFT |
                PMIC_CFG_COMM_IO_RD_VALID_SHIFT |
                PMIC_CFG_COMM_IO_WR_VALID_SHIFT |
                PMIC_CFG_CRITSEC_START_VALID_SHIFT |
                PMIC_CFG_CRITSEC_STOP_VALID_SHIFT |
                PMIC_CFG_COMM_HANDLE_VALID_SHIFT),
        },
        .rdIntr = (bool)true,
        .rdDeviceInfo = (bool)false,
        .clrIrqSts = (bool)true,
        .clrRecovCounter = (bool)false,
    },
#if (D_FEATURE_HERA_ENABLE == 1)
    [PMIC_DEV_2] = {
        .name = "PMIC HERA",
        .deviceNum = (uint8_t)PMIC_DEV_2,
        .pmicCoreHandle = {0},
        .pmicConfigData = {
            .pmicDeviceType      = PMIC_DEV_HERA_LP8764X,
            .commMode            = PMIC_INTF_SINGLE_I2C,
            .slaveAddr           = HERA_PMIC_SLAVE_ADDR,
            .nvmSlaveAddr        = HERA_PMIC_PAGE1_SLAVE_ADDR,
            .i2c1Speed           = PMIC_I2C_STANDARD_MODE,
            .crcEnable           = (bool)true,
            .pFnPmicCommIoRead   = pmic_regRead,
            .pFnPmicCommIoWrite  = pmic_regWrite,
            .pFnPmicCritSecStart  = pmic_criticalSectionStartFn,
            .pFnPmicCritSecStop   = pmic_criticalSectionStopFn,
            .validParams         =
               (uint32_t)(PMIC_CFG_DEVICE_TYPE_VALID_SHIFT |
                PMIC_CFG_COMM_MODE_VALID_SHIFT |
                PMIC_CFG_SLAVEADDR_VALID_SHIFT |
                PMIC_CFG_NVMSLAVEADDR_VALID_SHIFT |
                PMIC_CFG_COMM_IO_RD_VALID_SHIFT |
                PMIC_CFG_COMM_IO_WR_VALID_SHIFT |
                PMIC_CFG_CRITSEC_START_VALID_SHIFT |
                PMIC_CFG_CRITSEC_STOP_VALID_SHIFT |
                PMIC_CFG_COMM_HANDLE_VALID_SHIFT),
        },
        .rdIntr = (bool)true,
        .rdDeviceInfo = (bool)false,
        .clrIrqSts = (bool)true,
        .clrRecovCounter = (bool)false,
    },
#endif
};

/* PMIC configuration */
const Pmic_WdgCfg_t wdgCfg    =
    {
        (uint32_t)PMIC_WDG_CFG_SETPARAMS_TRIGGER_FORALL,
        16000U,
        11000U,
        70400U,
        PMIC_WDG_FAIL_THRESHOLD_COUNT_1,
        PMIC_WDG_RESET_THRESHOLD_COUNT_1,
        PMIC_WDG_TRIGGER_MODE,
        PMIC_WDG_PWRHOLD_ENABLE,
        PMIC_WDG_RESET_ENABLE,
        PMIC_WDG_RETLONGWIN_DISABLE,
        0U,
        0U,
        0U,
    #ifdef ENABLE_PMIC_EXTWDG
        PMIC_WDG_ENABLE_VAL,
    #else
        PMIC_WDG_DISABLE_VAL,
    #endif
    };

uint8_t pmic_lastReset = 0u;
/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */
/* PMIC error variable */


/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */

