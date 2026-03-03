/**
 * @file pmic_cfg.h
 * @brief configurations for pmic module
 *
 * @details This file configures pmic for Wdg
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

#ifndef PMIC_CFG_H_
#define PMIC_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/drv/pmic/pmic.h>
#include <ti/board/src/devices/pmic/tps65941.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#ifndef bool_t
    typedef uint8_t bool_t;
#endif
#define D_FEATURE_HERA_ENABLE           (1u)
#define ENABLE_PMIC_EXTWDG              (1u)
//#define PMIC_PRINT_ENABLE
/*************** I2C Communication congiguration ***************/
#define I2C_PMIC_INSTANCE               (0u)
#define I2C_PMIC_WD_INSTANCE            (1u)

/*************** PMIC Device Configuration ***************/
/* Slave address of PMIC-A device */
#define LEO_PMICA_SLAVE_ADDR            (0x48U)
#define LEO_PMICA_PAGE1_SLAVE_ADDR      (0x49U)
#define LEO_PMICA_WDG_SLAVE_ADDR        (0x12U)

/* Slave address of PMIC-B device */
#define LEO_PMICB_SLAVE_ADDR            (0x4CU)
#define LEO_PMICB_PAGE1_SLAVE_ADDR      (0x4DU)
#define LEO_PMICB_WDG_SLAVE_ADDR        (0x13U)

/* Slave address of HERA PMIC */
#define HERA_PMIC_SLAVE_ADDR            (0x50U)
#define HERA_PMIC_PAGE1_SLAVE_ADDR      (0x51U)


#define PMIC_WDG_CFG_SETPARAMS_TRIGGER_FORALL \
        (PMIC_CFG_WDG_LONGWINDURATION_VALID_SHIFT | \
         PMIC_CFG_WDG_WIN1DURATION_VALID_SHIFT    | \
         PMIC_CFG_WDG_WIN2DURATION_VALID_SHIFT    | \
         PMIC_CFG_WDG_FAILTHRESHOLD_VALID_SHIFT   | \
         PMIC_CFG_WDG_RSTTHRESHOLD_VALID_SHIFT    | \
         PMIC_CFG_WDG_RSTENABLE_VALID_SHIFT       | \
         PMIC_CFG_WDG_WDGMODE_VALID_SHIFT         | \
         PMIC_CFG_WDG_RETLONGWIN_VALID_SHIFT      | \
         PMIC_CFG_WDG_ENABLE_VALID_SHIFT)

/*************** PMIC WDG Configuration ***************/
/* GPIO Pin to generate pulse for Wdg trigger */
#define D_PMIC_WDG_TRIG_PIN1         (0x57U) /* WKUP_GPIO0_87 (J25): GPIO-2 Pin of PMIC to Trigger/Feed Watchdog pulse */ 

/* GPIO pin value definitions */
#define D_PMIC_GPIO_PIN_LEVEL_LOW    (0U)
#define D_PMIC_GPIO_PIN_LEVEL_HIGH   (1U)

/* PMIC configuration */
#define D_PMIC_LONG_WINDOW_DURATION  (0x40) /* Long Window Duration: 
                                             * Ranges->  0x00: 80 ms
                                             *           0x01 - 0x40: 125 ms to 8 sec, in 125 ms steps
                                             *           0x41 - 0xFF: 12 sec to 772 sec, in 4 sec steps
                                             * Observed 1 -> 0xFF: 772 Sec, 0x28: 5 Sec, 0x46: 20 Sec
                                             * Observed 2 -> 0x4F: 68 Sec, 0x40: 8 Sec, 0x30: 6 Sec */

#define D_PMIC_WINDOW_1_DURATION     (0x7F)  /* WINDOW_1 Duration: 
                                              * Range -> Min: (Value + 1) × 0.55 × 0.95 ms, 
                                              *          Max: (Value + 1) × 0.55 × 1.05 ms */

#define D_PMIC_WINDOW_2_DURATION     (0x7F)  /* WINDOW_2 Duration: 
                                              * Range -> Min: (Value + 1) × 0.55 × 0.95 ms, 
                                              *          Max: (Value + 1) × 0.55 × 1.05 ms */

#define D_PMIC_FAIL_THRESHOLD        (0x5)   /* Fail Threshold count */
#define D_PMIC_RESET_THRESHOLD       (0x1)   /* Reset Threshold count */
#define D_PMIC_RESET_ENABLE          (0x1)   /* Reset Enable, 1: Enable, 0: Disable */

#define PMIC_WDG_ENABLE_VAL                          (0x1)
#define PMIC_WDG_DISABLE_VAL                         (0x0)

#define D_PMIC_WDG_DISABLE_TIMEOUT                   (30u)   /* 150 ms */

#define D_PMIC_WDG_DISABLE_SUCCESS                   (0x00)
#define D_PMIC_WDG_WRONG_SEQUENCE_MASK               (0x01 << 0)
#define D_PMIC_WDG_LONGWINDOW_I2C_FAIL_MASK          (0x01 << 1)
#define D_PMIC_WDG_DISABLE_TIMEOUT_MASK              (0x01 << 2)
#define D_PMIC_WDG_DISABLE_I2C_FAIL_MASK             (0x01 << 3)

#define D_PMIC_WDG_ENABLE_SUCCESS                    (0x00)
#define D_PMIC_WDG_INT_CLEAR_MASK                    (0x01 << 0u)
#define D_PMIC_WDG_RECOV_CNT_MASK                    (0x01 << 1u)
#define D_PMIC_WDG_ENABLE_FAIL_MASK                  (0x01 << 2u)
#define D_PMIC_WDG_PWRHOLD_FAIL_MASK                 (0x01 << 3u)
#define D_PMIC_WDG_RET_LONGWIN_MASK                  (0x01 << 4u)
#define D_PMIC_WDG_CFG_FAIL_MASK                     (0x01 << 5u)
#define D_PMIC_WDG_CFG_CHECK_FAIL_MASK               (0x01 << 6u)

#define D_PMIC_WDG_WIN1_SHIFT                        (0)
#define D_PMIC_WDG_WIN2_SHIFT                        (1)
#define D_PMIC_WDG_LONGWIN_SHIFT                     (2)
#define D_PMIC_WDG_RST_ENABLE_SHIFT                  (3)
#define D_PMIC_WDG_FAIL_THR_SHIFT                    (4)
#define D_PMIC_WDG_RST_THR_SHIFT                     (5)
#define D_PMIC_WDG_WDT_MODE_SHIFT                    (6)
#define D_PMIC_WDG_RETLONWIN_SHIFT                   (7)
#define D_PMIC_WDG_PWRHOLD_SHIFT                     (8)
#define D_PMIC_WDG_ENABLE_SHIFT                      (9)

#define D_PMIC_WDG_CFG_SUCCESS                       (0x00)
#define D_PMIC_WDG_WIN1_MASK                         (0x01 << D_PMIC_WDG_WIN1_SHIFT)
#define D_PMIC_WDG_WIN2_MASK                         (0x01 << D_PMIC_WDG_WIN2_SHIFT)
#define D_PMIC_WDG_LONGWIN_MASK                      (0x01 << D_PMIC_WDG_LONGWIN_SHIFT)
#define D_PMIC_WDG_RST_ENABLE_MASK                   (0x01 << D_PMIC_WDG_RST_ENABLE_SHIFT)
#define D_PMIC_WDG_FAIL_THR_MASK                     (0x01 << D_PMIC_WDG_FAIL_THR_SHIFT)
#define D_PMIC_WDG_RST_THR_MASK                      (0x01 << D_PMIC_WDG_RST_THR_SHIFT)
#define D_PMIC_WDG_WDT_MODE_MASK                     (0x01 << D_PMIC_WDG_WDT_MODE_SHIFT)

/* Pulse generate after window 1 duration */
#define D_PMIC_WINDOW_1_TIME         (2u)  /* 2 * 10 = 20ms */


/*************** PMIC Safe state Configuration ***************/
#define D_PMIC_T_WD_PULSE             (40u) /* tWD_pulse: min -> 24us, typ -> 30us, max -> 36us */

/* PMIC error monitoring */
#define D_PMIC_LOG_ERROR(x)              (V_PmicErrSts_u32 | (uint32_t)x)
#define D_PMIC_RECOV_CNT_THR                         (0x0Fu-0x01u)

#define D_PMIC_INTR_SET                              (0x01u)
#define D_PMIC_INTR_CLR                              (0x00u)

#define D_PMIC_SOFT_REBOOT_REASON                    (0b0001)
#define D_PMIC_SOFT_REBOOR_TRIG                      (0x1u)

#define D_PMIC_CRC_ENABLED                           (0x1u)
#define D_PMIC_CRC_DISABLED                          (0x0u)

#define D_PMIC_GPIO2_CFG                             (0x2AU)  

/* PMIC Ext WDG state machine states */
typedef enum PmicExtWdgSt_e
{
    e_PmicExtWdgSt_UNINIT = 1 ,  /* 01 */
    e_PmicExtWdgSt_INIT       ,  /* 02 */
    e_PmicExtWdgSt_HI         ,  /* 03 */
    e_PmicExtWdgSt_LO            /* 04 */
} PmicExtWdgSt_t;

typedef enum PmicDevId_e {
    PMIC_DEV_0,
    PMIC_DEV_1,
#if (D_FEATURE_HERA_ENABLE == 1)
    PMIC_DEV_2,
#endif
    PMIC_DEV_NUM
}PmicDevId_t;

typedef struct pmic_device
{
    /* Device name */
    const char         *name;

    /* driver handle */
    Pmic_CoreHandle_t  pmicCoreHandle;

    /* Config */
    Pmic_CoreCfg_t      pmicConfigData;

    /* Data */
    Pmic_DeviceInfo_t st_deviceinfo;
    Pmic_IrqStatus_t  errStat;

    /* Debug */
    bool rdIntr;
    bool rdDeviceInfo;
    bool clrIrqSts;
    bool checkWdgConfig;
    bool clrRecovCounter;
    bool earlyConfigDone;
    bool regLocked;
    bool pmicInitCompleted;
    uint8_t deviceNum;
    uint8_t CurRecoveryCounter;
    uint8_t lastReset;

}pmic_device_t;

extern pmic_device_t pmic_device[];

extern const Pmic_WdgCfg_t wdgCfg;

extern uint8_t pmic_lastReset;

/* === End Of Header File ================================================= */
#endif /* #ifndef PMIC_CFG_H_ */

/* @} */
