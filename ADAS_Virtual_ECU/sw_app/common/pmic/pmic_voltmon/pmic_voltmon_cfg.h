/**
 * @file pmic_voltmon_cfg.h
 * @brief Config header file for pmic voltage monitoring
 *
 * @details This file contains pmic voltage monitoring register configuration
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
 
#ifndef __PMIC_VOLTMON_CFG_H
#define __PMIC_VOLTMON_CFG_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "pmic_cfg.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/* Macro to enable/disable test code */
#define D_PMIC_DBG_PRINT_VOLTMON_CFG_DATA   (0)

/* Number of BUCK and LDO in PMIC master, Slave and Hera (each) */
#define D_BUCK_CNT            (5)
#define D_LDO_CNT             (4)

/* BUCK and LDO index for Array indexing */
#define D_BUCK_1_IDX          (0)
#define D_BUCK_2_IDX          (1)
#define D_BUCK_3_IDX          (2)
#define D_BUCK_4_IDX          (3)
#define D_BUCK_5_IDX          (4)
#define D_LDO_1_IDX           (0)
#define D_LDO_2_IDX           (1)
#define D_LDO_3_IDX           (2)
#define D_LDO_4_IDX           (3)

/* BUCK and LDO bit mask (Corresponding to Array indexing) */
#define D_BUCK_1_BIT_MASK     (0x01)
#define D_BUCK_2_BIT_MASK     (0x02)
#define D_BUCK_3_BIT_MASK     (0x04)
#define D_BUCK_4_BIT_MASK     (0x08)
#define D_BUCK_5_BIT_MASK     (0x10)
#define D_BUCK_ALL_BIT_MASK   (0x1F)

#define D_LDO_1_BIT_MASK      (0x01)
#define D_LDO_2_BIT_MASK      (0x02)
#define D_LDO_3_BIT_MASK      (0x04)
#define D_LDO_4_BIT_MASK      (0x08)
#define D_LDO_ALL_BIT_MASK    (0x0F)


#define D_PMIC_VOLTMON_CFG_SEQ_STEP1_CNT  (12)    /* Number of sequence in step 1 configuration */
#define D_PMIC_VOLTMON_CFG_SEQ_STEP2_CNT  (4)    /* Number of sequence in step 2 configuration */
#define D_PMIC_VOLTMON_CFG_SEQ_INV        (0xFF) /* Invalid configuration sequence count */

/* ILIM current error limit */
#define D_PMIC_ILIM_ERR_CNT_LIMIT         (3)

/* *************************************** */
/*        Interrupt Mask registers         */
/* *************************************** */
/*
 * ---------------------------------------------------------------------------------------------------------------------------
 * |                                         MASK_BUCK1_2 Register   (Default = 0x00)                                        |
 * --------------------------------------------------------------------------------------------------------------------------|
 * |        7        |     6    |       5       |       4       |        3        |     2    |       1       |        0      |
 * |-----------------|----------|---------------|---------------|-----------------|----------|---------------|---------------|
 * | BUCK2_ILIM_MASK | RESERVED | BUCK2_UV_MASK | BUCK2_OV_MASK | BUCK1_ILIM_MASK | RESERVED | BUCK1_UV_MASK | BUCK1_OV_MASK |
 * ---------------------------------------------------------------------------------------------------------------------------
 *          |                           |               |                 |                           |               |
 *          |                           |               |                 |                           |               +------ Masking of BUCK1 over-voltage detection
 *          |                           |               |                 |                           +---------------------- Masking of BUCK1 under-voltage detection interrupt
 *          |                           |               |                 +-------------------------------------------------- Masking for BUCK1 current monitoring interrupt BUCK1_ILIM_INT
 *          |                           |               +-------------------------------------------------------------------- Masking of BUCK2 over-voltage detection interrupt BUCK2_OV_INT
 *          |                           +------------------------------------------------------------------------------------ Masking of BUCK2 under-voltage detection interrupt
 *          +---------------------------------------------------------------------------------------------------------------- Masking for BUCK2 current monitoring interrupt
 *
 * Note 1: 0b = Interrupt generated, 1b = Interrupt not generated.
 * Note 2: Register MASK_BUCK3_4, MASK_BUCK5, MASK_LDO1_2 and MASK_LDO3_4 is similar to MASK_BUCK1_2.
 */


/* ******************************************************* */
/*        Volatge threshold configuration registers        */
/* ******************************************************* */
/*
 * -------------------------------------------------------------------------------------------------------------
 * |                          BUCKn_CTRL (n = 1, 2, 3, 4 and 5)  (Default = 0x22)                              |
 * -------------------------------------------------------------------------------------------------------------
 * |       7      |     6    |      5     |       4       |      3     |       2       |      1     |     0    |
 * |--------------|----------|------------|---------------|------------|---------------|------------|----------|
 * | BUCKn_RV_SEL | RESERVED | BUCKn_PLDN | BUCKn_VMON_EN | BUCKn_VSEL | BUCKn_FPWM_MP | BUCKn_FPWM | BUCKn_EN |
 * -------------------------------------------------------------------------------------------------------------
 *        |                         |             |              |              |              |          |
 *        |                         |             |              |              |              |          +----- Enable BUCKn regulator
 *        |                         |             |              |              |              +---------------- Forces regulator to operate in PWM mode
 *        |                         |             |              |              +------------------------------- Forces regulator to operate always in multi-phase and forced PWM operation mode
 *        |                         |             |              +---------------------------------------------- output voltage register (0b = BUCK1_VOUT_1, 1b = BUCK1_VOUT_2)
 *        |                         |             +------------------------------------------------------------- OV, UV, SC and ILIM comparators
 *        |                         +--------------------------------------------------------------------------- Output pull-down resistor
 *        +----------------------------------------------------------------------------------------------------- Residual voltage checking
 */

/*
 * -------------------------------------------------------
 * | BUCKn_CONF (n = 1, 2, 3, 4 and 5)  (Default = 0x22) |
 * -------------------------------------------------------
 * |    7 - 6     |      5 - 3     |        2 - 0        |
 * |--------------|----------------|---------------------|
 * |   RESERVED   |   BUCKn_ILIM   |   BUCKn_SLEW_RATE   |
 * -------------------------------------------------------
 *                        |                  |
 *                        |                  +----- Sets the switch peak current limit
 *                        |                          (   0b = Reserved,   1b = Reserved
 *                        |                             10b = 2.5 A,     11b = 3.5 A
 *                        |                            100b = 4.5 A,    101b = 5.5 A
 *                        |                            110b = Reserved, 111b = Reserved)
 *                        |
 *                        +------------------------ Sets the output voltage slew rate
 *                                                   (   0b = 33 mV/μs,     1b = 20 mV/μs
 *                                                      10b = 10 mV/μs,    11b = 5.0 mV/μs
 *                                                     100b = 2.5 mV/μs,  101b = 1.3 mV/μs
 *                                                     110b = 0.63 mV/μs, 111b = 0.31 mV/μs)
 */

/*
 * -------------------------------------------------------
 * | BUCKn_VOUT_1(n = 1, 2, 3, 4 and 5) (Default = 0x00) |
 * -------------------------------------------------------
 * |                      7 - 0                          |
 * |-----------------------------------------------------|
 * |                  BUCKn_VSET1                        |
 * -------------------------------------------------------
 *                        |
 *                        +------------------------ Voltage selection
 */


/*
 * -------------------------------------------------------
 * | BUCKn_VOUT_2(n = 1, 2, 3, 4 and 5) (Default = 0x00) |
 * -------------------------------------------------------
 * |                      7 - 0                          |
 * |-----------------------------------------------------|
 * |                  BUCKn_VSET2                        |
 * -------------------------------------------------------
 *                        |
 *                        +------------------------ Voltage selection
 */


/*
 * ------------------------------------------------------------
 * | BUCKn_PG_WINDOW (n = 1, 2, 3, 4 and 5)  (Default = 0x00) |
 * ------------------------------------------------------------
 * |      7 - 6     |        5 - 3       |        2 - 0       |
 * |----------------|--------------------|--------------------|
 * |    RESERVED    |    BUCKn_UV_THR    |    BUCKn_OV_THR    |
 * ------------------------------------------------------------
 *                             |                   |
 *                             |                   +----- Powergood low threshold level for BUCKn
 *                             |                          (   0b = -3% / -30 mV,  1b = -3.5% / -35 mV
 *                             |                             10b = -4% / -40 mV,  11b = -5% / -50 mV
 *                             |                            100b = -6% / -60 mV, 101b = -7% / -70 mV
 *                             |                            110b = -8% / -80 mV, 111b = -10% / -100 mV)
 *                             |
 *                             +------------------------- Powergood high threshold level for BUCKn
 *                                                        (   0b = +3% / +30 mV,   1b = +3.5% / +35 mV
 *                                                           10b = +4% / +40 mV,  11b = +5% / +50 mV
 *                                                          100b = +6% / +60 mV, 101b = +7% / +70 mV
 *                                                          110b = +8% / +80 mV, 111b = +10% / +100 mV)
 */


/*
 * --------------------------------------------------------------------------------
 * |                    LDOm_CTRL (m = 1, 2, 3 and 4)  (Default = 0x60)           |
 * --------------------------------------------------------------------------------
 * |       7     |   6 - 5   |       4      |   3 - 2  |        1       |    0    |
 * |-------------|-----------|--------------|----------|----------------|---------|
 * | LDOm_RV_SEL | LDOm_PLDN | LDOm_VMON_EN | RESERVED | LDOm_SLOW_RAMP | LDOm_EN |
 * --------------------------------------------------------------------------------
 *        |            |            |                           |            |
 *        |            |            |                           |            +----- Enable LDOm regulator
 *        |            |            |                           +------------------ LDOm startup slew rate selection
 *        |            |            +---------------------------------------------- Enable LDO1 OV and UV comparators
 *        |            +----------------------------------------------------------- Enable output pull-down resistor when LDOm is disabled (0=50 kOhm, 1=125 Ohm, 2=250 Ohm, 3=500 Ohm)
 *        +------------------------------------------------------------------------ Select residual voltage checking for LDOm output pin
 */

/*
 * ----------------------------------------------------
 * | LDOm_VOUT (m = 1, 2, 3 and 4)  (Default = 0x00)  |
 * ----------------------------------------------------
 * |         7         |       6 - 1     |     0      |
 * |-------------------|-----------------|------------|
 * |    LDOm_BYPASS    |    LDOm_VSET    |  RESERVED  |
 * ----------------------------------------------------
 *        |            |
 *        |            +----------------------- Voltage selection for LDO regulator
 *        +------------------------------------ Set LDOm to bypass mode
 */

/*
 * -----------------------------------------------------------
 * | LDOm_PG_WINDOW (n = 1, 2, 3, 4 and 5)  (Default = 0x00) |
 * -----------------------------------------------------------
 * |      7 - 6     |        5 - 3       |        2 - 0      |
 * |----------------|--------------------|-------------------|
 * |    RESERVED    |    LDOm_UV_THR     |    LDOm_OV_THR    |
 * -----------------------------------------------------------
 *                             |                    |
 *                             |                    +----- Powergood low threshold level for LDOn
 *                             |                           (   0b = -3% / -30 mV,  1b = -3.5% / -35 mV
 *                             |                              10b = -4% / -40 mV,  11b = -5% / -50 mV
 *                             |                             100b = -6% / -60 mV, 101b = -7% / -70 mV
 *                             |                             110b = -8% / -80 mV, 111b = -10% / -100 mV)
 *                             |
 *                             +-------------------------- Powergood high threshold level for LDOn
 *                                                         (   0b = +3% / +30 mV,   1b = +3.5% / +35 mV
 *                                                            10b = +4% / +40 mV,  11b = +5% / +50 mV
 *                                                           100b = +6% / +60 mV, 101b = +7% / +70 mV
 *                                                           110b = +8% / +80 mV, 111b = +10% / +100 mV)
 */


/* ************************************************************* */
/*        Volatge monitoring interrupt registers (Status)        */
/* ************************************************************* */
/*
 * -----------------------------------------------------------------------------------------------------------------
 * |                                                  INT_TOP (Default = 0x00)                                     |
 * -----------------------------------------------------------------------------------------------------------------
 * |      7      |        6       |         5        |     4    |      3      |     2    |       1      |     0    |
 * |-------------|----------------|------------------|----------|-------------|----------|--------------|----------|
 * | FSM_ERR_INT | SEVERE_ERR_INT | MODERATE_ERR_INT | MISC_INT | STARTUP_INT | GPIO_INT | LDO_VMON_INT | BUCK_INT |
 * -----------------------------------------------------------------------------------------------------------------
 *        |               |                  |             |            |           |           |             |
 *        |               |                  |             |            |           |           |             +----- INT_BUCK register has pending interrupt
 *        |               |                  |             |            |           |           +------------------- INT_LDO_VMON register has pending interrup
 *        |               |                  |             |            |           +------------------------------- INT_GPIO register has pending interrup
 *        |               |                  |             |            +------------------------------------------- INT_STARTUP register has pending interrupt
 *        |               |                  |             +-------------------------------------------------------- INT_MISC register has pending interrupt
 *        |               |                  +---------------------------------------------------------------------- INT_MODERATE_ERR register has pending interrupt
 *        |               +----------------------------------------------------------------------------------------- INT_SEVERE_ERR register has pending interrupt
 *        +--------------------------------------------------------------------------------------------------------- INT_FSM_ERR register has pending interrupt
 */
 
#define D_BUCK_INT_BIT_MASK      (0x01)
#define D_LDO_VMON_INT_BIT_MASK  (0x02)
#define D_VMON_INT_BIT_MASK      (0x02)    /* For hera */

/*
 * ----------------------------------------------------
 * |             INT_BUCK (Default = 0x00)            |
 * ----------------------------------------------------
 * |   7 - 3  |     2     |       1     |      0      |
 * |----------|-----------|-------------|-------------|
 * | RESERVED | BUCK5_INT | BUCK3_4_INT | BUCK1_2_INT |
 * ----------------------------------------------------
 *                  |           |             |
 *                  |           |             +-------- INT_BUCK1_2 register has pending interrupt
 *                  |           +---------------------- INT_BUCK3_4 register has pending interrupt
 *                  +---------------------------------- INT_BUCK5 register has pending interrupt
 */
#define D_BUCK1_2_INT_BIT_MASK  (0x01)
#define D_BUCK3_4_INT_BIT_MASK  (0x02)
#define D_BUCK5_INT_BIT_MASK    (0x04)

/*
 * -----------------------------------------------------------------------------------------------------------------------------
 * |                                                    INT_BUCK1_2 (Default = 0x00)                                           |
 * -----------------------------------------------------------------------------------------------------------------------------
 * |        7       |       6      |       5      |       4      |        3       |       2      |       1      |       0      |
 * |----------------|--------------|--------------|--------------|----------------|--------------|--------------|--------------|
 * | BUCK2_ILIM_INT | BUCK2_SC_INT | BUCK2_UV_INT | BUCK2_OV_INT | BUCK1_ILIM_INT | BUCK1_SC_INT | BUCK1_UV_INT | BUCK1_OV_INT |
 * -----------------------------------------------------------------------------------------------------------------------------
 *         |               |               |             |                |               |              |             |
 *         |               |               |             |                |               |              |             +------- BUCK1 output over-voltage has been detected
 *         |               |               |             |                |               |              +--------------------- BUCK1 output under-voltage has been detected.
 *         |               |               |             |                |               +------------------------------------ BUCK1 (or other regulators) output voltage has
 *         |               |               |             |                |                                                     fallen below the 150 mV level during operation,
 *         |               |               |             |                |                                                     or BUCK1 (or other regulators) output is higher
 *         |               |               |             |                |                                                     than the 150 mV level immediately after enable
 *         |               |               |             |                +---------------------------------------------------- BUCK1 output current limit has been triggered
 *         |               |               |             +--------------------------------------------------------------------- BUCK2 output over-voltage has been detected
 *         |               |               +----------------------------------------------------------------------------------- BUCK2 output under-voltage has been detected.
 *         |               +--------------------------------------------------------------------------------------------------- BUCK2 (or other regulators) output voltage has
 *         |                                                                                                                    fallen below the 150 mV level during operation,
 *         |                                                                                                                    or BUCK2 (or other regulators) output is higher
 *         |                                                                                                                    than the 150 mV level immediately after enable
 *         +------------------------------------------------------------------------------------------------------------------- BUCK2 output current limit has been triggered
 *
 * Note: Register INT_BUCK3_4 and INT_BUCK5 has similar bitfied as INT_BUCK1_2
 */
 
#define D_BUCK1_OV_INT_BIT_MASK    (0x01)
#define D_BUCK1_UV_INT_BIT_MASK    (0x02)
#define D_BUCK1_SC_INT_BIT_MASK    (0x04)
#define D_BUCK1_ILIM_INT_BIT_MASK  (0x08)

#define D_BUCK2_OV_INT_BIT_MASK    (0x10)
#define D_BUCK2_UV_INT_BIT_MASK    (0x20)
#define D_BUCK2_SC_INT_BIT_MASK    (0x40)
#define D_BUCK2_ILIM_INT_BIT_MASK  (0x80)

#define D_BUCK3_OV_INT_BIT_MASK    (0x01)
#define D_BUCK3_UV_INT_BIT_MASK    (0x02)
#define D_BUCK3_SC_INT_BIT_MASK    (0x04)
#define D_BUCK3_ILIM_INT_BIT_MASK  (0x08)

#define D_BUCK4_OV_INT_BIT_MASK    (0x10)
#define D_BUCK4_UV_INT_BIT_MASK    (0x20)
#define D_BUCK4_SC_INT_BIT_MASK    (0x40)
#define D_BUCK4_ILIM_INT_BIT_MASK  (0x80)

#define D_BUCK5_OV_INT_BIT_MASK    (0x01)
#define D_BUCK5_UV_INT_BIT_MASK    (0x02)
#define D_BUCK5_SC_INT_BIT_MASK    (0x04)
#define D_BUCK5_ILIM_INT_BIT_MASK  (0x08)

/*
 * ------------------------------------------------------------
 * |                INT_LDO_VMON (Default = 0x00)             |
 * ------------------------------------------------------------
 * |   7 - 5  |     4    |   3 - 2  |      1     |      0     |
 * |----------|----------|----------|------------|------------|
 * | RESERVED | VCCA_INT | RESERVED | LDO3_4_INT | LDO1_2_INT |
 * ------------------------------------------------------------
 *                  |                     |             |
 *                  |                     |             +-------- INT_LDO1_2 register has pending interrupt
 *                  |                     +---------------------- INT_LDO3_4 register has pending interrupt
 *                  +-------------------------------------------- INT_VMON register has pending interrupt
 */
#define D_LDO1_2_INT_BIT_MASK  (0x01)
#define D_LDO3_4_INT_BIT_MASK  (0x02)
#define D_VCCA_INT_BIT_MASK    (0x10)


/*
 * ---------------------------------------------------------------------------------------------------------------------
 * |                                                INT_LDO1_2 (Default = 0x00)                                        |
 * ---------------------------------------------------------------------------------------------------------------------
 * |       7       |      6      |      5      |      4      |       3       |      2      |      1      |      0      |
 * |---------------|-------------|-------------|-------------|---------------|-------------|-------------|-------------|
 * | LDO2_ILIM_INT | LDO2_SC_INT | LDO2_UV_INT | LDO2_OV_INT | LDO1_ILIM_INT | LDO1_SC_INT | LDO1_UV_INT | LDO1_OV_INT |
 * ---------------------------------------------------------------------------------------------------------------------
 *         |              |              |            |              |              |             |             |
 *         |              |              |            |              |              |             |             +------- LDO1 output over-voltage has been detected
 *         |              |              |            |              |              |             +--------------------- LDO1 output under-voltage has been detected.
 *         |              |              |            |              |              +----------------------------------- LDO1 (or other regulators) output voltage has
 *         |              |              |            |              |                                                   fallen below the 150 mV level during operation,
 *         |              |              |            |              |                                                   or LDO1 (or other regulators) output is higher
 *         |              |              |            |              |                                                   than the 150 mV level immediately after enable
 *         |              |              |            |              +-------------------------------------------------- LDO1 output current limit has been triggered
 *         |              |              |            +----------------------------------------------------------------- LDO2 output over-voltage has been detected
 *         |              |              +------------------------------------------------------------------------------ LDO2 output under-voltage has been detected.
 *         |              +--------------------------------------------------------------------------------------------- LDO2 (or other regulators) output voltage has
 *         |                                                                                                             fallen below the 150 mV level during operation,
 *         |                                                                                                             or LDO2 (or other regulators) output is higher
 *         |                                                                                                             than the 150 mV level immediately after enable
 *         +------------------------------------------------------------------------------------------------------------ LDO2 output current limit has been triggered
 *
 * Note: Register INT_LDO3_4 has similar bitfied as INT_LDO1_2
 */
#define D_LDO1_OV_INT_BIT_MASK     (0x01)
#define D_LDO1_UV_INT_BIT_MASK     (0x02)
#define D_LDO1_SC_INT_BIT_MASK     (0x04)
#define D_LDO1_ILIM_INT_BIT_MASK   (0x08)

#define D_LDO2_OV_INT_BIT_MASK     (0x10)
#define D_LDO2_UV_INT_BIT_MASK     (0x20)
#define D_LDO2_SC_INT_BIT_MASK     (0x40)
#define D_LDO2_ILIM_INT_BIT_MASK   (0x80)

#define D_LDO3_OV_INT_BIT_MASK     (0x01)
#define D_LDO3_UV_INT_BIT_MASK     (0x02)
#define D_LDO3_SC_INT_BIT_MASK     (0x04)
#define D_LDO3_ILIM_INT_BIT_MASK   (0x08)

#define D_LDO4_OV_INT_BIT_MASK     (0x10)
#define D_LDO4_UV_INT_BIT_MASK     (0x20)
#define D_LDO4_SC_INT_BIT_MASK     (0x40)
#define D_LDO4_ILIM_INT_BIT_MASK   (0x80)


/*
 * ----------------------------------------
 * |      INT_VMON (Default = 0x00)       |
 * ----------------------------------------
 * |   7 - 2  |      1      |      0      |
 * |------------------------|-------------|
 * | RESERVED | VCCA_UV_INT | VCCA_OV_INT |
 * ----------------------------------------
 *                  |              |
 *                  |              +------- VCCA over-voltage has been detected
 *                  +---------------------- VCCA under-voltage has been detected.
 */
#define D_VCCA_OV_INT_BIT_MASK     (0x01u)
#define D_VCCA_UV_INT_BIT_MASK     (0x02u)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/* BUCK and LDO voltage monitoring enable / disable cfg structure */
typedef struct pmic_buck_monitor_enable
{
    uint8_t  is_buck_Supp_u8;        /* Is buck supported in PMIC HW? (1 - Supported, 0 - Not supported) */
    uint8_t  is_volt_mon_enable_u8;  /* Is voltage monitoring enabled? (1 - enable, 0 - disable) */
    uint8_t  is_curr_mon_enable_u8;  /* Is current monitoring enabled ? (1 - enable, 0 - disable) */
    uint8_t  is_rv_mon_enable_u8;    /* Is Residual voltage monitoring enabled ? (1 - enable, 0 - disable) */
}pmic_buck_monitor_t;

typedef struct pmic_ldo_monitor_enable
{
    uint8_t  is_ldo_Supp_u8;         /* Is LDO supported in PMIC HW? (1 - Supported, 0 - Not supported) */
    uint8_t  is_volt_mon_enable_u8;  /* Is voltage monitoring enabled? (1 - enable, 0 - disable) */
    uint8_t  is_curr_mon_enable_u8;  /* Is current monitoring enabled? (1 - enable, 0 - disable) */
    uint8_t  is_rv_mon_enable_u8;    /* Is Residual voltage monitoring enabled ? (1 - enable, 0 - disable) */
}pmic_ldo_monitor_t;


typedef struct pmic_voltmon_enable
{
    uint8_t              is_buck_mon_enb_u8;       /* This should be 1 if any of buck feature need to monitor in sw, or else 0 */
    pmic_buck_monitor_t  buck_mon_as[D_BUCK_CNT];  /* Monitor Enable structure for Buck regulator */
    uint8_t              is_ldo_mon_enb_u8;        /* This should be 1 if any of ldo feature need to monitor in sw 
                                                        (Including VCCA for master and slave), or else 0 */
    pmic_ldo_monitor_t   ldo_mon_as[D_LDO_CNT];    /* Monitor Enable structure for LDO regulator */
    uint8_t              is_vcca_mon_enb_u8;       /* Voltmon Enable flag for VCCA */
}pmic_monitor_enable_t;


/* BUCK and LDO ILIM error counter structure */
typedef struct pmic_ILIM_err_cntr
{
    uint8_t  buck_ilim_err_cntr_au8[D_BUCK_CNT];  /* ILIM error counter for BUCK */
    uint8_t  ldo_ilim_err_cntr_au8[D_LDO_CNT];    /* ILIM error counter for LDO */
}pmic_ILIM_err_cntr_t;

/* Clear BUCK and LDO ILIM error counter structure */
typedef struct pmic_ILIM_err_cntr_clr
{
    uint8_t  buck_ilim_err_cntr_clr_u8;  /* Flag to clear ILIM error counter for BUCK */
    uint8_t  ldo_ilim_err_cntr_clr_u8;   /* Flag to clear ILIM error counter for LDO */
}pmic_ILIM_err_cntr_clr_t;

/* BUCK and LDO configuration structure */
typedef struct pmic_voltmon_config_seq
{
    PmicDevId_t  devId_e;               /* Device Id */
    uint16_t     pmic_cfg_reg_addr_u16; /* PMIC config register address */
    uint8_t      bitpos_u8;             /* Bit position, where value needs to be wtitten */
    uint8_t      reg_value_u8;          /* Register value (Need to OR with Existing value) */
}pmic_voltmon_config_seq_t;

typedef struct pmic_voltmon_config_seq_step
{
    uint8_t                          seq_cnt_u8;
    const pmic_voltmon_config_seq_t  *step1_s;    /* PMIC slave address */
}pmic_voltmon_config_seq_step_t;

/* ========================================================================== */
/*                         External variables                                 */
/* ========================================================================== */
extern const pmic_monitor_enable_t                  V_pmic_monitor_enable_as[];
extern const pmic_voltmon_config_seq_step_t         V_voltmon_cfg_seq_step1_as[];
extern const pmic_voltmon_config_seq_step_t         V_voltmon_cfg_seq_step2_as[];

extern pmic_ILIM_err_cntr_t V_pmic_ILIM_err_cntr_as[PMIC_DEV_NUM];

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


/* === End Of Header File ================================================= */
#endif  /* __PMIC_VOLTMON_CFG_H */
