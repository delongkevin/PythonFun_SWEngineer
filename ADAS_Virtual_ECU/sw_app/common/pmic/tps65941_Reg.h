/**
 * @file tps65941_Reg.h
 * @brief Header file for all PMIC register offset
 *
 * @details This file contains all PMIC register offset
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
 
#ifndef __PMIC_TPS65941_REG_H
#define __PMIC_TPS65941_REG_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/* PMIC Register offset */
#define D_PMIC_TPS65941_DEV_REV               (0x1U)
#define D_PMIC_TPS65941_NVM_CODE_1            (0x2U)
#define D_PMIC_TPS65941_NVM_CODE_2            (0x3U)
#define D_PMIC_TPS65941_BUCK1_CTRL            (0x4U)
#define D_PMIC_TPS65941_BUCK1_CONF            (0x5U)
#define D_PMIC_TPS65941_BUCK2_CTRL            (0x6U)
#define D_PMIC_TPS65941_BUCK2_CONF            (0x7U)
#define D_PMIC_TPS65941_BUCK3_CTRL            (0x8U)
#define D_PMIC_TPS65941_BUCK3_CONF            (0x9U)
#define D_PMIC_TPS65941_BUCK4_CTRL            (0xAU)
#define D_PMIC_TPS65941_BUCK4_CONF            (0xBU)
#define D_PMIC_TPS65941_BUCK5_CTRL            (0xCU)
#define D_PMIC_TPS65941_BUCK5_CONF            (0xDU)
#define D_PMIC_TPS65941_BUCK1_VOUT_1          (0xEU)
#define D_PMIC_TPS65941_BUCK1_VOUT_2          (0xFU)
#define D_PMIC_TPS65941_BUCK2_VOUT_1          (0x10U)
#define D_PMIC_TPS65941_BUCK2_VOUT_2          (0x11U)
#define D_PMIC_TPS65941_BUCK3_VOUT_1          (0x12U)
#define D_PMIC_TPS65941_BUCK3_VOUT_2          (0x13U)
#define D_PMIC_TPS65941_BUCK4_VOUT_1          (0x14U)
#define D_PMIC_TPS65941_BUCK4_VOUT_2          (0x15U)
#define D_PMIC_TPS65941_BUCK5_VOUT_1          (0x16U)
#define D_PMIC_TPS65941_BUCK5_VOUT_2          (0x17U)
#define D_PMIC_TPS65941_BUCK1_PG_WINDOW       (0x18U)
#define D_PMIC_TPS65941_BUCK2_PG_WINDOW       (0x19U)
#define D_PMIC_TPS65941_BUCK3_PG_WINDOW       (0x1AU)
#define D_PMIC_TPS65941_BUCK4_PG_WINDOW       (0x1BU)
#define D_PMIC_TPS65941_BUCK5_PG_WINDOW       (0x1CU)
#define D_PMIC_TPS65941_LDO1_CTRL             (0x1DU)
#define D_PMIC_TPS65941_LDO2_CTRL             (0x1EU)
#define D_PMIC_TPS65941_LDO3_CTRL             (0x1FU)
#define D_PMIC_TPS65941_LDO4_CTRL             (0x20U)
#define D_PMIC_TPS65941_LDORTC_CTRL           (0x22U)
#define D_PMIC_TPS65941_LDO1_VOUT             (0x23U)
#define D_PMIC_TPS65941_LDO2_VOUT             (0x24U)
#define D_PMIC_TPS65941_LDO3_VOUT             (0x25U)
#define D_PMIC_TPS65941_LDO4_VOUT             (0x26U)
#define D_PMIC_TPS65941_LDO1_PG_WINDOW        (0x27U)
#define D_PMIC_TPS65941_LDO2_PG_WINDOW        (0x28U)
#define D_PMIC_TPS65941_LDO3_PG_WINDOW        (0x29U)
#define D_PMIC_TPS65941_LDO4_PG_WINDOW        (0x2AU)
#define D_PMIC_TPS65941_VCCA_VMON_CTRL        (0x2BU)
#define D_PMIC_TPS65941_VCCA_PG_WINDOW        (0x2CU)
#define D_PMIC_TPS65941_VMON2_PG_WINDOW       (0x2FU)   /* Only for HERA */
#define D_PMIC_TPS65941_VMON2_PG_LEVEL        (0x30U)   /* Only for HERA */
#define D_PMIC_TPS65941_GPIO1_CONF            (0x31U)
#define D_PMIC_TPS65941_GPIO2_CONF            (0x32U)
#define D_PMIC_TPS65941_GPIO3_CONF            (0x33U)
#define D_PMIC_TPS65941_GPIO4_CONF            (0x34U)
#define D_PMIC_TPS65941_GPIO5_CONF            (0x35U)
#define D_PMIC_TPS65941_GPIO6_CONF            (0x36U)
#define D_PMIC_TPS65941_GPIO7_CONF            (0x37U)
#define D_PMIC_TPS65941_GPIO8_CONF            (0x38U)
#define D_PMIC_TPS65941_GPIO9_CONF            (0x39U)
#define D_PMIC_TPS65941_GPIO10_CONF           (0x3AU)
#define D_PMIC_TPS65941_GPIO11_CONF           (0x3BU)
#define D_PMIC_TPS65941_NPWRON_CONF           (0x3CU)
#define D_PMIC_TPS65941_GPIO_OUT_1            (0x3DU)
#define D_PMIC_TPS65941_GPIO_OUT_2            (0x3EU)
#define D_PMIC_TPS65941_GPIO_IN_1             (0x3FU)
#define D_PMIC_TPS65941_GPIO_IN_2             (0x40U)
#define D_PMIC_TPS65941_RAIL_SEL_1            (0x41U)
#define D_PMIC_TPS65941_RAIL_SEL_2            (0x42U)
#define D_PMIC_TPS65941_RAIL_SEL_3            (0x43U)
#define D_PMIC_TPS65941_FSM_TRIG_SEL_1        (0x44U)
#define D_PMIC_TPS65941_FSM_TRIG_SEL_2        (0x45U)
#define D_PMIC_TPS65941_FSM_TRIG_MASK_1       (0x46U)
#define D_PMIC_TPS65941_FSM_TRIG_MASK_2       (0x47U)
#define D_PMIC_TPS65941_FSM_TRIG_MASK_3       (0x48U)
#define D_PMIC_TPS65941_MASK_BUCK1_2          (0x49U)
#define D_PMIC_TPS65941_MASK_BUCK3_4          (0x4AU)
#define D_PMIC_TPS65941_MASK_BUCK5            (0x4BU)
#define D_PMIC_TPS65941_MASK_LDO1_2           (0x4CU)
#define D_PMIC_TPS65941_MASK_LDO3_4           (0x4DU)
#define D_PMIC_TPS65941_MASK_VMON             (0x4EU)
#define D_PMIC_TPS65941_MASK_GPIO1_8_FALL     (0x4FU)
#define D_PMIC_TPS65941_MASK_GPIO1_8_RISE     (0x50U)
#define D_PMIC_TPS65941_MASK_GPIO9_11         (0x51U)
#define D_PMIC_TPS65941_MASK_STARTUP          (0x52U)
#define D_PMIC_TPS65941_MASK_MISC             (0x53U)
#define D_PMIC_TPS65941_MASK_MODERATE_ERR     (0x54U)
#define D_PMIC_TPS65941_MASK_FSM_ERR          (0x56U)
#define D_PMIC_TPS65941_MASK_COMM_ERR         (0x57U)
#define D_PMIC_TPS65941_MASK_READBACK_ERR     (0x58U)
#define D_PMIC_TPS65941_MASK_ESM              (0x59U)
#define D_PMIC_TPS65941_INT_TOP               (0x5AU)
#define D_PMIC_TPS65941_INT_BUCK              (0x5BU)
#define D_PMIC_TPS65941_INT_BUCK1_2           (0x5CU)
#define D_PMIC_TPS65941_INT_BUCK3_4           (0x5DU)
#define D_PMIC_TPS65941_INT_BUCK5             (0x5EU)
#define D_PMIC_TPS65941_INT_LDO_VMON          (0x5FU)
#define D_PMIC_TPS65941_INT_LDO1_2            (0x60U)
#define D_PMIC_TPS65941_INT_LDO3_4            (0x61U)
#define D_PMIC_TPS65941_INT_VMON              (0x62U)
#define D_PMIC_TPS65941_INT_GPIO              (0x63U)
#define D_PMIC_TPS65941_INT_GPIO1_8           (0x64U)
#define D_PMIC_TPS65941_INT_STARTUP           (0x65U)
#define D_PMIC_TPS65941_INT_MISC              (0x66U)
#define D_PMIC_TPS65941_INT_MODERATE_ERR      (0x67U)
#define D_PMIC_TPS65941_INT_SEVERE_ERR        (0x68U)
#define D_PMIC_TPS65941_INT_FSM_ERR           (0x69U)
#define D_PMIC_TPS65941_INT_COMM_ERR          (0x6AU)
#define D_PMIC_TPS65941_INT_READBACK_ERR      (0x6BU)
#define D_PMIC_TPS65941_INT_ESM               (0x6CU)
#define D_PMIC_TPS65941_STAT_BUCK1_2          (0x6DU)
#define D_PMIC_TPS65941_STAT_BUCK3_4          (0x6EU)
#define D_PMIC_TPS65941_STAT_BUCK5            (0x6FU)
#define D_PMIC_TPS65941_STAT_LDO1_2           (0x70U)
#define D_PMIC_TPS65941_STAT_LDO3_4           (0x71U)
#define D_PMIC_TPS65941_STAT_VMON             (0x72U)
#define D_PMIC_TPS65941_STAT_STARTUP          (0x73U)
#define D_PMIC_TPS65941_STAT_MISC             (0x74U)
#define D_PMIC_TPS65941_STAT_MODERATE_ERR     (0x75U)
#define D_PMIC_TPS65941_STAT_SEVERE_ERR       (0x76U)
#define D_PMIC_TPS65941_STAT_READBACK_ERR     (0x77U)
#define D_PMIC_TPS65941_PGOOD_SEL_1           (0x78U)
#define D_PMIC_TPS65941_PGOOD_SEL_2           (0x79U)
#define D_PMIC_TPS65941_PGOOD_SEL_3           (0x7AU)
#define D_PMIC_TPS65941_PGOOD_SEL_4           (0x7BU)
#define D_PMIC_TPS65941_PLL_CTRL              (0x7CU)
#define D_PMIC_TPS65941_CONFIG_1              (0x7DU)
#define D_PMIC_TPS65941_CONFIG_2              (0x7EU)
#define D_PMIC_TPS65941_ENABLE_DRV_REG        (0x80U)
#define D_PMIC_TPS65941_MISC_CTRL             (0x81U)
#define D_PMIC_TPS65941_ENABLE_DRV_STAT       (0x82U)
#define D_PMIC_TPS65941_RECOV_CNT_REG_1       (0x83U)
#define D_PMIC_TPS65941_RECOV_CNT_REG_2       (0x84U)
#define D_PMIC_TPS65941_FSM_I2C_TRIGGERS      (0x85U)
#define D_PMIC_TPS65941_FSM_NSLEEP_TRIGGERS   (0x86U)
#define D_PMIC_TPS65941_BUCK_RESET_REG        (0x87U)
#define D_PMIC_TPS65941_SPREAD_SPECTRUM_1     (0x88U)
#define D_PMIC_TPS65941_FREQ_SEL              (0x8AU)
#define D_PMIC_TPS65941_FSM_STEP_SIZE         (0x8BU)
#define D_PMIC_TPS65941_LDO_RV_TIMEOUT_REG_1  (0x8CU)
#define D_PMIC_TPS65941_LDO_RV_TIMEOUT_REG_2  (0x8DU)
#define D_PMIC_TPS65941_USER_SPARE_REGS       (0x8EU)
#define D_PMIC_TPS65941_ESM_MCU_START_REG     (0x8FU)
#define D_PMIC_TPS65941_ESM_MCU_DELAY1_REG    (0x90U)
#define D_PMIC_TPS65941_ESM_MCU_DELAY2_REG    (0x91U)
#define D_PMIC_TPS65941_ESM_MCU_MODE_CFG      (0x92U)
#define D_PMIC_TPS65941_ESM_MCU_HMAX_REG      (0x93U)
#define D_PMIC_TPS65941_ESM_MCU_HMIN_REG      (0x94U)
#define D_PMIC_TPS65941_ESM_MCU_LMAX_REG      (0x95U)
#define D_PMIC_TPS65941_ESM_MCU_LMIN_REG      (0x96U)
#define D_PMIC_TPS65941_ESM_MCU_ERR_CNT_REG   (0x97U)
#define D_PMIC_TPS65941_ESM_SOC_START_REG     (0x98U)
#define D_PMIC_TPS65941_ESM_SOC_DELAY1_REG    (0x99U)
#define D_PMIC_TPS65941_ESM_SOC_DELAY2_REG    (0x9AU)
#define D_PMIC_TPS65941_ESM_SOC_MODE_CFG      (0x9BU)
#define D_PMIC_TPS65941_ESM_SOC_HMAX_REG      (0x9CU)
#define D_PMIC_TPS65941_ESM_SOC_HMIN_REG      (0x9DU)
#define D_PMIC_TPS65941_ESM_SOC_LMAX_REG      (0x9EU)
#define D_PMIC_TPS65941_ESM_SOC_LMIN_REG      (0x9FU)
#define D_PMIC_TPS65941_ESM_SOC_ERR_CNT_REG   (0xA0U)
#define D_PMIC_TPS65941_REGISTER_LOCK         (0xA1U)
#define D_PMIC_TPS65941_MANUFACTURING_VER     (0xA6U)
#define D_PMIC_TPS65941_CUSTOMER_NVM_ID_REG   (0xA7U)
#define D_PMIC_TPS65941_SOFT_REBOOT_REG       (0xABU)
#define D_PMIC_TPS65941_RTC_SECONDS           (0xB5U)
#define D_PMIC_TPS65941_RTC_MINUTES           (0xB6U)
#define D_PMIC_TPS65941_RTC_HOURS             (0xB7U)
#define D_PMIC_TPS65941_RTC_DAYS              (0xB8U)
#define D_PMIC_TPS65941_RTC_MONTHS            (0xB9U)
#define D_PMIC_TPS65941_RTC_YEARS             (0xBAU)
#define D_PMIC_TPS65941_RTC_WEEKS             (0xBBU)
#define D_PMIC_TPS65941_ALARM_SECONDS         (0xBCU)
#define D_PMIC_TPS65941_ALARM_MINUTES         (0xBDU)
#define D_PMIC_TPS65941_ALARM_HOURS           (0xBEU)
#define D_PMIC_TPS65941_ALARM_DAYS            (0xBFU)
#define D_PMIC_TPS65941_ALARM_MONTHS          (0xC0U)
#define D_PMIC_TPS65941_ALARM_YEARS           (0xC1U)
#define D_PMIC_TPS65941_RTC_CTRL_1            (0xC2U)
#define D_PMIC_TPS65941_RTC_CTRL_2            (0xC3U)
#define D_PMIC_TPS65941_RTC_STATUS            (0xC4U)
#define D_PMIC_TPS65941_RTC_INTERRUPTS        (0xC5U)
#define D_PMIC_TPS65941_RTC_COMP_LSB          (0xC6U)
#define D_PMIC_TPS65941_RTC_COMP_MSB          (0xC7U)
#define D_PMIC_TPS65941_RTC_RESET_STATUS      (0xC8U)
#define D_PMIC_TPS65941_SCRATCH_PAD_REG_1     (0xC9U)
#define D_PMIC_TPS65941_SCRATCH_PAD_REG_2     (0xCAU)
#define D_PMIC_TPS65941_SCRATCH_PAD_REG_3     (0xCBU)
#define D_PMIC_TPS65941_SCRATCH_PAD_REG_4     (0xCCU)
#define D_PMIC_TPS65941_PFSM_DELAY_REG_1      (0xCDU)
#define D_PMIC_TPS65941_PFSM_DELAY_REG_2      (0xCEU)
#define D_PMIC_TPS65941_PFSM_DELAY_REG_3      (0xCFU)
#define D_PMIC_TPS65941_PFSM_DELAY_REG_4      (0xD0U)
#define D_PMIC_TPS65941_WD_ANSWER_REG         (0x401U)
#define D_PMIC_TPS65941_WD_QUESTION_ANSW_CNT  (0x402U)
#define D_PMIC_TPS65941_WD_WIN1_CFG           (0x403U)
#define D_PMIC_TPS65941_WD_WIN2_CFG           (0x404U)
#define D_PMIC_TPS65941_WD_LONGWIN_CFG        (0x405U)
#define D_PMIC_TPS65941_WD_MODE_REG           (0x406U)
#define D_PMIC_TPS65941_WD_QA_CFG             (0x407U)
#define D_PMIC_TPS65941_WD_ERR_STATUS         (0x408U)
#define D_PMIC_TPS65941_WD_THR_CFG            (0x409U)
#define D_PMIC_TPS65941_WD_FAIL_CNT_REG       (0x40AU)


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                         External variables                                 */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


/* === End Of Header File ================================================= */
#endif  /* __PMIC_TPS65941_REG_H */
