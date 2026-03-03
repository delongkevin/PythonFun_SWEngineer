/**
 * @file pmic_voltmon_cfg.c
 * @brief Config file for pmic voltage monitoring
 *
 * @details This file contains pmic voltage monitoring configuration
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
 * @author Pramod Kumar (Pramod.kumar1@magna.com)
 */
 
/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include "pmic_voltmon_cfg.h"
#include "tps65941_Reg.h"

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


/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */
/* BUCK and LDO voltage / Current monitoring enable / disable lookup table */
const pmic_monitor_enable_t  V_pmic_monitor_enable_as[PMIC_DEV_NUM] = 
{
    /* PMIC Master (5 BUCK, 4 LDO) */
    {
        (uint8_t)1,    /* is_buck_mon_enb_u8 -> Volt, curr and RV monitoring for any of buck not required in SW */ 
        /* is_buck_Supp_u8, is_volt_mon_enable_u8, is_curr_mon_enable_u8, is_rv_mon_enable_u8 */
        {    {(uint8_t)1,       (uint8_t)1,            (uint8_t)0,            (uint8_t)0}, /* BUCK 1 */
             {(uint8_t)1,       (uint8_t)1,            (uint8_t)0,            (uint8_t)0}, /* BUCK 2 */ 
             {(uint8_t)1,       (uint8_t)1,            (uint8_t)0,            (uint8_t)0}, /* BUCK 3 */
             {(uint8_t)1,       (uint8_t)1,            (uint8_t)0,            (uint8_t)0}, /* BUCK 4 */
             {(uint8_t)1,       (uint8_t)1,            (uint8_t)0,            (uint8_t)0}  /* BUCK 5 */
        },
        (uint8_t)1,    /* is_ldo_mon_enb_u8 -> Volt, curr and RV monitoring for any of ldo and VCCA monitoring not required in SW */ 
        /* is_ldo_Supp_u8,  is_volt_mon_enable_u8, is_curr_mon_enable_u8, is_rv_mon_enable_u8 */
        {    {(uint8_t)1,       (uint8_t)1,            (uint8_t)0,            (uint8_t)0}, /* LDO 1 */
             {(uint8_t)1,       (uint8_t)1,            (uint8_t)0,            (uint8_t)0}, /* LDO 2 */ 
             {(uint8_t)1,       (uint8_t)1,            (uint8_t)0,            (uint8_t)0}, /* LDO 3 */
             {(uint8_t)1,       (uint8_t)1,            (uint8_t)0,            (uint8_t)0}  /* LDO 4 */
        },
        (uint8_t)0  /* VCCA monitoring flag */
    },

    /* PMIC Slave (5 BUCK, 4 LDO) */
    {
        (uint8_t)1,    /* is_buck_mon_enb_u8 -> curr monitoring buck required in SW */ 
        /* is_buck_Supp_u8, is_volt_mon_enable_u8, is_curr_mon_enable_u8, is_rv_mon_enable_u8 */
        {    {(uint8_t)1,       (uint8_t)0,            (uint8_t)1,            (uint8_t)0}, /* BUCK 1 */
             {(uint8_t)1,       (uint8_t)0,            (uint8_t)1,            (uint8_t)0}, /* BUCK 2 */ 
             {(uint8_t)1,       (uint8_t)0,            (uint8_t)1,            (uint8_t)0}, /* BUCK 3 */
             {(uint8_t)1,       (uint8_t)0,            (uint8_t)1,            (uint8_t)0}, /* BUCK 4 */
             {(uint8_t)1,       (uint8_t)0,            (uint8_t)1,            (uint8_t)0}  /* BUCK 5 */
        },
        (uint8_t)1,    /* is_ldo_mon_enb_u8 -> Volt, curr and RV monitoring for any of ldo and VCCA monitoring not required in SW */
        /* is_ldo_Supp_u8,  is_volt_mon_enable_u8, is_curr_mon_enable_u8, is_rv_mon_enable_u8 */
        {    {(uint8_t)1,       (uint8_t)0,            (uint8_t)0,            (uint8_t)0}, /* LDO 1 (Not safety relavent) */
             {(uint8_t)1,       (uint8_t)0,            (uint8_t)0,            (uint8_t)0}, /* LDO 2 (Not safety relavent) */ 
             {(uint8_t)1,       (uint8_t)0,            (uint8_t)0,            (uint8_t)0}, /* LDO 3 (Unused) */
             {(uint8_t)1,       (uint8_t)0,            (uint8_t)1,            (uint8_t)0}  /* LDO 4 */
        },
        (uint8_t)0  /* VCCA monitoring flag */
    },
#if (D_FEATURE_HERA_ENABLE == 1)
    /* PMIC Hera (4 BUCK, 0 LDO) */
    {
        (uint8_t)1,    /* is_buck_mon_enb_u8 -> Volt, curr and RV monitoring for any of buck not required in SW */ 
        /* is_buck_Supp_u8, is_volt_mon_enable_u8, is_curr_mon_enable_u8, is_rv_mon_enable_u8 */
        {    {(uint8_t)1,       (uint8_t)1,            (uint8_t)0,            (uint8_t)0}, /* BUCK 1 (Not mentioned in HSIS) */
             {(uint8_t)1,       (uint8_t)1,            (uint8_t)0,            (uint8_t)0}, /* BUCK 2 (Not safety relavent) */ 
             {(uint8_t)1,       (uint8_t)1,            (uint8_t)0,            (uint8_t)0}, /* BUCK 3 */
             {(uint8_t)1,       (uint8_t)1,            (uint8_t)0,            (uint8_t)0}, /* BUCK 4 */
             {(uint8_t)0,       (uint8_t)0,            (uint8_t)0,            (uint8_t)0}  /* BUCK 5 (Not suppoted in HW) */
        },
        (uint8_t)0,    /* is_ldo_mon_enb_u8 -> Volt, curr and RV monitoring for any of ldo not required in SW */
        /* is_ldo_Supp_u8,  is_volt_mon_enable_u8, is_curr_mon_enable_u8, is_rv_mon_enable_u8 */
        {    {(uint8_t)0,       (uint8_t)0,            (uint8_t)0,            (uint8_t)0}, /* LDO 1 (Not suppoted in HW) */
             {(uint8_t)0,       (uint8_t)0,            (uint8_t)0,            (uint8_t)0}, /* LDO 2 (Not suppoted in HW) */ 
             {(uint8_t)0,       (uint8_t)0,            (uint8_t)0,            (uint8_t)0}, /* LDO 3 (Not suppoted in HW) */
             {(uint8_t)0,       (uint8_t)0,            (uint8_t)0,            (uint8_t)0}  /* LDO 4 (Not suppoted in HW) */
        },
        (uint8_t)0  /* VCCA monitoring flag -> Not required in SW */
    },
#endif
};

/* ILIM error counter */
pmic_ILIM_err_cntr_t V_pmic_ILIM_err_cntr_as[PMIC_DEV_NUM] = 
{
    /* PMIC Master (5 BUCK, 4 LDO) */
    {
        { (uint8_t)0, (uint8_t)0, (uint8_t)0, (uint8_t)0, (uint8_t)0 }, /* BUCK 1 - BUCK 5 */
        { (uint8_t)0, (uint8_t)0, (uint8_t)0, (uint8_t)0 }     /* LDO 1 - LDO 5 */
    },

    /* PMIC Slave (5 BUCK, 4 LDO) */
    {
        { (uint8_t)0, (uint8_t)0, (uint8_t)0, (uint8_t)0, (uint8_t)0 }, /* BUCK 1 - BUCK 5 */
        { (uint8_t)0, (uint8_t)0, (uint8_t)0, (uint8_t)0 }     /* LDO 1 - LDO 5 */
    },
#if (D_FEATURE_HERA_ENABLE == 1)
    /* PMIC Hera (4 BUCK, 0 LDO) */
    {
        { (uint8_t)0, (uint8_t)0, (uint8_t)0, (uint8_t)0, (uint8_t)0 }, /* BUCK 1 - BUCK 5 (BUCK 5 not supported for HERA) */
        { (uint8_t)0, (uint8_t)0, (uint8_t)0, (uint8_t)0 }     /* LDO 1 - LDO 5 (LDO not supported for HERA) */
    },
#endif
};


/****************** Link Hera rails with Leo(s) state machine *********************/
/* Req Id: 19338137 */
#define D_PMIC_HERA_RAIL_LINK_SEQ_STEP1_CNT    (5)
static const pmic_voltmon_config_seq_t V_hera_rail_link_seq_step1_as[D_PMIC_HERA_RAIL_LINK_SEQ_STEP1_CNT] =
{
    /* devId_e,          pmic_cfg_reg_addr_u16,               bitpos_u8,     reg_value_u8 */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_BUCK3_VOUT_1,    (uint8_t)0xFF,  (uint8_t)0x73 }, /* 1. Slave -> BUCK3_VOUT_1 -> BUCK3_VSET1 -> 0x73 (Read Value = 0x00) */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_RAIL_SEL_1,      (uint8_t)0xFF,  (uint8_t)0x59 }, /* 2. Slave -> RAIL_SEL_1 -> BUCK3_GRP_SEL -> 1 (Read Value = 0x0A) */
                                                                                             /* From "Rail group assignment" -> RAIL_SEL_1 -> BUCK1_GRP_SEL -> 1 */
                                                                                             /* From "VDD_IO_3V3" -> RAIL_SEL_1 -> BUCK4_GRP_SEL -> 1 */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_BUCK3_PG_WINDOW, (uint8_t)0xFF,  (uint8_t)0x3F }, /* 3. Slave -> BUCK3_PG_WINDOW -> BUCK3_UV_THR -> 7 (Read Value = 0x00) */
                                                                                             /* 3. Slave -> BUCK3_PG_WINDOW -> BUCK3_OV_THR -> 7 */
                                                                                             /* bit 6-7 is Reserved */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_MASK_BUCK3_4,    (uint8_t)0xFF,  (uint8_t)0x33 }, /* 4. Slave -> MASK_BUCK3_4 -> BUCK3_UV_MASK -> 1 (Read Value = 0x00) */
                                                                                             /* 4. Slave -> MASK_BUCK3_4 -> BUCK3_OV_MASK -> 1 */
                                                                                             /* From "VDD_IO_3V3" -> MASK_BUCK3_4 -> BUCK4_UV_MASK -> 1 */
                                                                                                                  /* MASK_BUCK3_4 -> BUCK4_OV_MASK -> 1 */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_BUCK3_CTRL,      (uint8_t)0xFF,  (uint8_t)0xB0 }  /* 5. Slave -> BUCK3_CTRL -> BUCK3_VMON_EN -> 1 (Read Value = 0x20) */
                                                                                                /* From "V_residual_volt_mon_enb_as"
                                                                                                    BUCK3_CTRL -> BUCK3_RV_SEL -> 1 */
};

/****************** Rail group assignment *********************/
/* Req Id: 19338823 */
#define D_PMIC_RAIL_GRP_CFG_CNT    (5)
static const pmic_voltmon_config_seq_t V_rail_grp_cfg_as[D_PMIC_RAIL_GRP_CFG_CNT] =
{
    /* devId_e,          pmic_cfg_reg_addr_u16,           bitpos_u8,     reg_value_u8 */
    {PMIC_DEV_0, (uint16_t)D_PMIC_TPS65941_RAIL_SEL_1,  (uint8_t)0xFF,  (uint8_t)0x59 }, /* 1. Master -> RAIL_SEL_1 -> BUCK1_GRP_SEL -> 1 (Read Value = 0x5A) */
    {PMIC_DEV_0, (uint16_t)D_PMIC_TPS65941_RAIL_SEL_2,  (uint8_t)0xFF,  (uint8_t)0x55 }, /* 2. Master -> RAIL_SEL_2 -> BUCK5_GRP_SEL -> 1 (Read Value = 0x96) */
                                                                                         /* 3. Master -> RAIL_SEL_2 -> LDO3_GRP_SEL -> 1 */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_RAIL_SEL_2,  (uint8_t)0xFF,  (uint8_t)0x01 }, /* 5. Slave ->  RAIL_SEL_2 -> BUCK5_GRP_SEL -> 1 (Read Value = 0xA2) */
                                                                                         /* From "V_no_rail_grp_cfg_as" 
                                                                                             RAIL_SEL_2 -> LDO2_GRP_SEL -> 0
                                                                                             RAIL_SEL_2 -> LDO3_GRP_SEL -> 0 */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_RAIL_SEL_3,  (uint8_t)0xFF,  (uint8_t)0x05 }, /* 6. Slave ->  RAIL_SEL_3 -> LDO4_GRP_SEL -> 1 (Read Value = 0x06) */
    {PMIC_DEV_2, (uint16_t)D_PMIC_TPS65941_RAIL_SEL_1,  (uint8_t)0xFF,  (uint8_t)0x52 }, /* 7. Hera ->   RAIL_SEL_1 -> BUCK3_GRP_SEL -> 1 (Read Value = 0xAA)*/
                                                                                         /* 8. Hera ->   RAIL_SEL_1 -> BUCK4_GRP_SEL -> 1 */
                                                                                         /* From "V_no_rail_grp_cfg_as" 
                                                                                             RAIL_SEL_1 -> BUCK2_GRP_SEL -> 0*/
                                                                                         /* 9. Master ->  RAIL_SEL_1 -> BUCK4_GRP_SEL -> Default */
                                                                                         /* 10. Master ->  RAIL_SEL_2 -> LDO1_GRP_SEL -> Default */
                                                                                         /* 11. Master ->  RAIL_SEL_2 -> LDO2_GRP_SEL -> Default */
                                                                                         /* 12. Master ->  RAIL_SEL_3 -> LDO4_GRP_SEL -> Default */
};

/****************** VDD_MCUIO_3V3 *********************/
/* Req Id: 19339156 */
#define D_PMIC_VDD_MCUIO_3V3_SEQ_STEP1_CNT    (1)
static const pmic_voltmon_config_seq_t V_vdd_mcuio_3v3_seq_step1_as[D_PMIC_VDD_MCUIO_3V3_SEQ_STEP1_CNT] =
{
    /* devId_e,           pmic_cfg_reg_addr_u16,            bitpos_u8,     reg_value_u8 */
                                                                                           /* 1. Master -> BUCK3_VOUT_1 -> BUCK3_VSET1 -> Default */
                                                                                           /* 2. Master -> RAIL_SEL_1 -> BUCK3_GRP_SEL -> Default */
                                                                                           /* 3. Master -> BUCK3_PG_WINDOW -> BUCK3_UV_THR -> Default */
                                                                                           /* 3. Master -> BUCK3_PG_WINDOW -> BUCK3_OV_THR -> Default */
    {PMIC_DEV_0, (uint16_t)D_PMIC_TPS65941_MASK_BUCK3_4,  (uint8_t)0xFF,  (uint8_t)0x03 }, /* 4. Master -> MASK_BUCK3_4 -> BUCK3_UV_MASK -> 1 (Read Value = 0x00) */
                                                                                           /* 4. Master -> MASK_BUCK3_4 -> BUCK3_OV_MASK -> 1 */
};

#define D_PMIC_VDD_MCUIO_3V3_SEQ_STEP2_CNT    (1)
static const pmic_voltmon_config_seq_t V_vdd_mcuio_3v3_seq_step2_as[D_PMIC_VDD_MCUIO_3V3_SEQ_STEP2_CNT] = /* PRQA S 1504 */ /* Used in PMIC Voltmon config Sequence steps */
{
    /* devId_e,          pmic_cfg_reg_addr_u16,              bitpos_u8,    reg_value_u8 */
    {PMIC_DEV_0, (uint16_t)D_PMIC_TPS65941_MASK_BUCK3_4,  (uint8_t)0xFF,  (uint8_t)0x00 } /* 7. Master -> MASK_BUCK3_4 -> BUCK3_UV_MASK -> 0 (This is 2nd write) */
                                                                                          /* 7. Master -> MASK_BUCK3_4 -> BUCK3_OV_MASK -> 0 */
};

/******************** VDD_IO_3V3 **********************/
/* Req Id: 19339473 */
#define D_PMIC_VDD_IO_3V3_SEQ_STEP1_CNT    (3)
static const pmic_voltmon_config_seq_t V_vdd_io_3v3_seq_step1_as[D_PMIC_VDD_IO_3V3_SEQ_STEP1_CNT] =
{
    /* devId_e,          pmic_cfg_reg_addr_u16,               bitpos_u8,     reg_value_u8 */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_BUCK4_VOUT_1,    (uint8_t)0xFF,  (uint8_t)0xFD }, /* 1. Slave -> BUCK4_VOUT_1 -> BUCK4_VSET1 -> 0xFD (Read Value = 0x00) */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_BUCK4_PG_WINDOW, (uint8_t)0xFF,  (uint8_t)0x1B }, /* 3. Slave -> BUCK4_PG_WINDOW -> BUCK4_UV_THR -> 3 (Read Value = 0x00) */
                                                                                             /* 3. Slave -> BUCK4_PG_WINDOW -> BUCK4_OV_THR -> 3 */
                                                                                             /* bit 6-7 is Reserved */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_BUCK4_CTRL,      (uint8_t)0xFF,  (uint8_t)0xB0 }  /* 5. Slave -> BUCK4_CTRL -> BUCK4_VMON_EN -> 1 (Read Value = 0x20) */
                                                                                             /* From "V_residual_volt_mon_enb_as"
                                                                                                   BUCK4_CTRL -> BUCK4_RV_SEL -> 1 */
};

#define D_PMIC_VDD_IO_3V3_SEQ_STEP2_CNT    (1)
static const pmic_voltmon_config_seq_t V_vdd_io_3v3_seq_step2_as[D_PMIC_VDD_IO_3V3_SEQ_STEP2_CNT] =
{
    /* devId_e,          pmic_cfg_reg_addr_u16,              bitpos_u8,    reg_value_u8 */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_MASK_BUCK3_4,  (uint8_t)0xFF,  (uint8_t)0x00 } /* 7. Slave -> MASK_BUCK3_4 -> BUCK4_UV_MASK -> 0 (This is 2nd write) */
                                                                                          /* 7. Slave -> MASK_BUCK3_4 -> BUCK4_OV_MASK -> 0 */
                                                                                          /* From "V_hera_rail_link_seq_step2_as" 
                                                                                                   MASK_BUCK3_4 -> BUCK3_UV_MASK -> 0
                                                                                                   MASK_BUCK3_4 -> BUCK3_OV_MASK -> 0 */
};

/******************** VDD_5V0 **********************/
/* Req Id: 19339485 */
#define D_PMIC_VDD_5V0_SEQ_STEP1_CNT    (5)
static const pmic_voltmon_config_seq_t V_vdd_5v0_seq_step1_as[D_PMIC_VDD_5V0_SEQ_STEP1_CNT] =
{
    /* devId_e,          pmic_cfg_reg_addr_u16,               bitpos_u8,     reg_value_u8 */
    {PMIC_DEV_2, (uint16_t)D_PMIC_TPS65941_GPIO8_CONF,      (uint8_t)0xFF,  (uint8_t)0x70 }, /* 1. Hera -> GPIO8_CONF -> GPIO8_SEL -> 0x11 (Read Value = 0x18) */
                                                                                             /* 1. Hera -> GPIO8_CONF -> GPIO8_PU_PD_EN -> 0 */
    {PMIC_DEV_2, (uint16_t)D_PMIC_TPS65941_VMON2_PG_LEVEL,  (uint8_t)0xFF,  (uint8_t)0x82 }, /* 2. Hera -> VMON2_PG_LEVEL -> VMON2_PG_SET -> 0x82 (Read Value = 0x00) */
    {PMIC_DEV_2, (uint16_t)D_PMIC_TPS65941_RAIL_SEL_3,      (uint8_t)0xFF,  (uint8_t)0x48 }, /* 3. Hera -> RAIL_SEL_3 -> VMON2_GRP_SEL -> 1 (Read Value = 0x08) */
    {PMIC_DEV_2, (uint16_t)D_PMIC_TPS65941_VMON2_PG_WINDOW, (uint8_t)0xFF,  (uint8_t)0x36 }, /* 4. Hera -> VMON2_PG_WINDOW -> VMON2_RANGE -> 0 (Read Value = 0x00) */
                                                                                             /* 4. Hera -> VMON2_PG_WINDOW -> VMON2_UV_THR -> 6 */
                                                                                             /* 4. Hera -> VMON2_PG_WINDOW -> VMON2_OV_THR -> 6 */
                                                                                             /* bit 7 is Reserved */
    {PMIC_DEV_2, (uint16_t)D_PMIC_TPS65941_VCCA_VMON_CTRL,  (uint8_t)0xFF,  (uint8_t)0x29 }  /* 6. Hera -> VCCA_VMON_CTRL -> VMON2_EN -> 1 (Read Value = 0x21) */
                                                                                             /* From "V_vcca_volt_mon_enb_as" 
                                                                                                    VCCA_VMON_CTRL -> VCCA_VMON_EN -> 1 (By default it is 1)*/
};

#define D_PMIC_VDD_5V0_SEQ_STEP2_CNT    (1)
static const pmic_voltmon_config_seq_t V_vdd_5v0_seq_step2_as[D_PMIC_VDD_5V0_SEQ_STEP2_CNT] =
{
    /* devId_e,          pmic_cfg_reg_addr_u16,               bitpos_u8,     reg_value_u8 */
    {PMIC_DEV_2, (uint16_t)D_PMIC_TPS65941_MASK_VMON,       (uint8_t)0xFF,  (uint8_t)0x0C }  /* 8. Hera -> MASK_VMON -> VMON2_UV_MASK -> 0 (Read Value = 0x6C) */
                                                                                             /* 8. Hera -> MASK_VMON -> VMON2_OV_MASK -> 0 */
};


/******************** BUCK regulator switching mode **********************/
/* Req Id: 19339521, 19339526 */
#define D_PMIC_BUCK_SWITING_MODE_CNT    (5)
static const pmic_voltmon_config_seq_t V_buck_switching_mode_as[D_PMIC_BUCK_SWITING_MODE_CNT] =
{
    /* devId_e,          pmic_cfg_reg_addr_u16,           bitpos_u8,     reg_value_u8 */
    {PMIC_DEV_0, (uint16_t)D_PMIC_TPS65941_BUCK1_CTRL,  (uint8_t)0xFF,  (uint8_t)0xB3 }, /* Master -> BUCK1_CTRL -> BUCK1_FPWM -> 1 (Read Value = 0x31) */
                                                                                         /* From "V_residual_volt_mon_enb_as"
                                                                                                   BUCK1_CTRL -> BUCK1_RV_SEL -> 1 */
    {PMIC_DEV_0, (uint16_t)D_PMIC_TPS65941_BUCK4_CTRL,  (uint8_t)0xFF,  (uint8_t)0xB3 }, /* Master -> BUCK4_CTRL -> BUCK4_FPWM -> 1 (Read Value = 0x31) */
                                                                                         /* From "V_residual_volt_mon_enb_as"
                                                                                                   BUCK4_CTRL -> BUCK4_RV_SEL -> 1 */
    {PMIC_DEV_0, (uint16_t)D_PMIC_TPS65941_BUCK5_CTRL,  (uint8_t)0xFF,  (uint8_t)0xB3 }, /* Master -> BUCK5_CTRL -> BUCK5_FPWM -> 1 (Read Value = 0x31) */
                                                                                         /* From "V_residual_volt_mon_enb_as"
                                                                                                   BUCK5_CTRL -> BUCK5_RV_SEL -> 1 */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_BUCK1_CTRL,  (uint8_t)0xFF,  (uint8_t)0xB3 }, /* Slave ->  BUCK1_CTRL -> BUCK1_FPWM -> 1 (Read Value = 0x31) */
                                                                                            /* From "V_residual_volt_mon_enb_as"
                                                                                                   BUCK1_CTRL -> BUCK1_RV_SEL -> 1 */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_BUCK5_CTRL,  (uint8_t)0xFF,  (uint8_t)0xB3 }  /* Slave ->  BUCK5_CTRL -> BUCK5_FPWM -> 1 (Read Value = 0x31) */
                                                                                            /* From "V_residual_volt_mon_enb_as"
                                                                                                   BUCK5_CTRL -> BUCK5_RV_SEL -> 1 */
};


/******************** VDD_spread_SpectrumSS voltage **********************/
/* Req Id: 15093394 */ //HSISREQ
#define D_PMIC_SPREAD_SPECTRUM_SS_CNT    (2)
static const pmic_voltmon_config_seq_t V_spread_spectrum_as[D_PMIC_SPREAD_SPECTRUM_SS_CNT] =
{
    /* devId_e,          pmic_cfg_reg_addr_u16,             bitpos_u8,     reg_value_u8 */
      {PMIC_DEV_0, (uint16_t)D_PMIC_TPS65941_SPREAD_SPECTRUM_1,    (uint8_t)0xFF,  (uint8_t)0x06 }, /* Master -> SPREAD_SPECTRUM_1 -> SPREAD_SPECTRUM_1 -> 0x03 (Read Value = 0x00)*/
      {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_SPREAD_SPECTRUM_1,    (uint8_t)0xFF,  (uint8_t)0x06 }, /* Slave -> SPREAD_SPECTRUM_1 -> SPREAD_SPECTRUM_1 -> 0x03 (Read Value = 0x00)*/
};

/******************** VDD_MCU_0V85 voltage **********************/
/* Req Id: 19490878 */
#define D_PMIC_VDD_MCU_0V85_CNT    (1)
static const pmic_voltmon_config_seq_t V_vdd_avs_as[D_PMIC_VDD_MCU_0V85_CNT] =
{
    /* devId_e,          pmic_cfg_reg_addr_u16,             bitpos_u8,     reg_value_u8 */
      {PMIC_DEV_0, (uint16_t)D_PMIC_TPS65941_BUCK4_VOUT_1,    (uint8_t)0xFF,  (uint8_t)0x44 }, /* Master -> BUCK4_VOUT_1 -> BUCK4_VSET1 -> 0x44 (Read Value = 0x41)*/
};

/******************** VDD_UNUSED_LEOB_LDO3 voltage **********************/
/* Req Id: 19339709 */
#define D_PMIC_VDD_UNUSED_LEOB_LDO3_CNT    (1)  
static const pmic_voltmon_config_seq_t V_vdd_unused_as[D_PMIC_VDD_UNUSED_LEOB_LDO3_CNT] =
{
    /* devId_e,          pmic_cfg_reg_addr_u16,             bitpos_u8,     reg_value_u8 */
      {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_MASK_LDO3_4,    (uint8_t)0xFF,  (uint8_t)0x03 }, /* Slave -> MASK_LDO3_4 -> MASK_LDO3_4 -> 0x3 (Read Value = 0x00)*/
};


/******************** VDD_RAM_0V85 voltage **********************/
/* Req Id: 19339613 */
#define D_PMIC_VDD_RAM_0V85_CNT    (1)
static const pmic_voltmon_config_seq_t V_vdd_ram_0v85_as[D_PMIC_VDD_RAM_0V85_CNT] =
{
    /* devId_e,          pmic_cfg_reg_addr_u16,             bitpos_u8,     reg_value_u8 */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_BUCK5_VOUT_1,  (uint8_t)0xFF,  (uint8_t)0x46 }, /* Slave -> BUCK5_VOUT_1 -> BUCK5_VSET1 -> 0x46 (Read Value = 0x41)*/
};


/******************** Set UV/OV threshold **********************/
/* Req Id: 19339624, 19339631 */
#define D_PMIC_SET_UV_OV_THR_CNT    (2)
static const pmic_voltmon_config_seq_t V_set_uv_ov_thr_as[D_PMIC_SET_UV_OV_THR_CNT] =
{
    /* devId_e,              pmic_cfg_reg_addr_u16,           bitpos_u8,  reg_value_u8 */
                                                                                             /* Master -> BUCK1_PG_WINDOW -> BUCK1_UV_THR -> Default */
                                                                                             /* Master -> BUCK1_PG_WINDOW -> BUCK1_OV_THR -> Default */
                                                                                             /* Master -> BUCK4_PG_WINDOW -> BUCK4_UV_THR -> Default */
                                                                                             /* Master -> BUCK4_PG_WINDOW -> BUCK4_OV_THR -> Default */
                                                                                             /* Master -> BUCK5_PG_WINDOW -> BUCK5_UV_THR -> Default */
                                                                                             /* Master -> BUCK5_PG_WINDOW -> BUCK5_OV_THR -> Default */
                                                                                             /* Master -> LDO1_PG_WINDOW -> LDO1_UV_THR -> Default */
                                                                                             /* Master -> LDO1_PG_WINDOW -> LDO1_OV_THR -> Default */
                                                                                             /* Master -> LDO2_PG_WINDOW -> LDO2_UV_THR -> Default */
                                                                                             /* Master -> LDO2_PG_WINDOW -> LDO2_OV_THR -> Default */
                                                                                             /* Master -> LDO3_PG_WINDOW -> LDO3_UV_THR -> Default */
                                                                                             /* Master -> LDO3_PG_WINDOW -> LDO3_OV_THR -> Default */
                                                                                             /* Master -> LDO4_PG_WINDOW -> LDO4_UV_THR -> Default */
                                                                                             /* Master -> LDO4_PG_WINDOW -> LDO4_OV_THR -> Default */
                                                                                             /* Slave ->  BUCK1_PG_WINDOW -> BUCK1_UV_THR -> Default */
                                                                                             /* Slave ->  BUCK1_PG_WINDOW -> BUCK1_OV_THR -> Default */
                                                                                             /* Slave ->  BUCK5_PG_WINDOW -> BUCK5_UV_THR -> Default */
                                                                                             /* Slave ->  BUCK5_PG_WINDOW -> BUCK5_OV_THR -> Default */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_LDO1_PG_WINDOW,  (uint8_t)0xFF,  (uint8_t)0x3F }, /* Slave ->  LDO1_PG_WINDOW -> LDO1_UV_THR -> 7 (Read Value = 0x1B) */
                                                                                             /* Slave ->  LDO1_PG_WINDOW -> LDO1_OV_THR -> 7 */
                                                                                             /* bit 6-7 is Reserved */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_LDO2_PG_WINDOW,  (uint8_t)0xFF,  (uint8_t)0x3F }, /* Slave ->  LDO2_PG_WINDOW -> LDO2_UV_THR -> 7 (Read Value = 0x1B) */
                                                                                             /* Slave ->  LDO2_PG_WINDOW -> LDO2_OV_THR -> 7 */
                                                                                             /* bit 6-7 is Reserved */
                                                                                             /* Slave ->  LDO4_PG_WINDOW -> LDO4_UV_THR -> Default */
                                                                                             /* Slave ->  LDO4_PG_WINDOW -> LDO4_OV_THR -> Default */
                                                                                             /* Hera ->   BUCK2_PG_WINDOW -> BUCK2_UV_THR -> Default */
                                                                                             /* Hera ->   BUCK2_PG_WINDOW -> BUCK2_OV_THR -> Default */
                                                                                             /* Hera ->   BUCK3_PG_WINDOW -> BUCK3_UV_THR -> Default */
                                                                                             /* Hera ->   BUCK3_PG_WINDOW -> BUCK3_OV_THR -> Default */
                                                                                             /* Hera ->   BUCK4_PG_WINDOW -> BUCK4_UV_THR -> Default */
                                                                                             /* Hera ->   BUCK4_PG_WINDOW -> BUCK4_OV_THR -> Default */
};

/******************** Unused power rail **********************/
/* Req Id: 19339624, 19339631 */
#define D_UNUSED_PWR_RAIL_CNT    (1)
static const pmic_voltmon_config_seq_t V_unused_pwr_rail_as[D_UNUSED_PWR_RAIL_CNT] =
{
    /* devId_e,          pmic_cfg_reg_addr_u16,            bitpos_u8,     reg_value_u8 */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_MASK_LDO3_4,  (uint8_t)0xFF,  (uint8_t)0x03 }, /* 1. Slave -> MASK_LDO3_4 -> LDO3_UV_MASK -> 1 (Read Value = 0x00) */
                                                                                          /* 1. Slave -> MASK_LDO3_4 -> LDO3_OV_MASK -> 1 */
                                                                                          /* 1. Slave -> MASK_LDO3_4 -> LDO3_ILIM_MASK -> 0 */
};


/******************** Residual voltage enable **********************/
/* Below Residual voltage monitoring should be enabled by default from NVM setting, but it is not */
/* This is PMIC FUSA requirement not from HSIS */
#define D_RESIDUAL_VOLT_MON_CNT    (10)
static const pmic_voltmon_config_seq_t V_residual_volt_mon_enb_as[D_RESIDUAL_VOLT_MON_CNT] =
{
    /* devId_e,          pmic_cfg_reg_addr_u16,            bitpos_u8,     reg_value_u8 */
    {PMIC_DEV_0, (uint16_t)D_PMIC_TPS65941_BUCK2_CTRL,  (uint8_t)0xFF,  (uint8_t)0xA0 }, /* Master -> BUCK2_CTRL -> BUCK2_RV_SEL -> 1 (Read Value = 0x20) */
    {PMIC_DEV_0, (uint16_t)D_PMIC_TPS65941_BUCK3_CTRL,  (uint8_t)0xFF,  (uint8_t)0xB0 }, /* Master -> BUCK3_CTRL -> BUCK3_RV_SEL -> 1 (Read Value = 0x30) */
    {PMIC_DEV_0, (uint16_t)D_PMIC_TPS65941_LDO1_CTRL,   (uint8_t)0xFF,  (uint8_t)0xB1 }, /* Master -> LDO1_CTRL -> LDO1_RV_SEL -> 1 (Read Value = 0x31) */
    {PMIC_DEV_0, (uint16_t)D_PMIC_TPS65941_LDO2_CTRL,   (uint8_t)0xFF,  (uint8_t)0xB1 }, /* Master -> LDO2_CTRL -> LDO2_RV_SEL -> 1 (Read Value = 0x31) */
    {PMIC_DEV_0, (uint16_t)D_PMIC_TPS65941_LDO3_CTRL,   (uint8_t)0xFF,  (uint8_t)0xB1 }, /* Master -> LDO3_CTRL -> LDO3_RV_SEL -> 1 (Read Value = 0x31) */
    {PMIC_DEV_0, (uint16_t)D_PMIC_TPS65941_LDO4_CTRL,   (uint8_t)0xFF,  (uint8_t)0xB1 }, /* Master -> LDO4_CTRL -> LDO4_RV_SEL -> 1 (Read Value = 0x31) */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_BUCK2_CTRL,  (uint8_t)0xFF,  (uint8_t)0xA0 }, /* Slave -> BUCK2_CTRL -> BUCK2_RV_SEL -> 1 (Read Value = 0x20) */
    {PMIC_DEV_1, (uint16_t)D_PMIC_TPS65941_LDO4_CTRL,   (uint8_t)0xFF,  (uint8_t)0xB1 }, /* Slave -> LDO4_CTRL -> LDO4_RV_SEL -> 1 (Read Value = 0x31) */
    {PMIC_DEV_2, (uint16_t)D_PMIC_TPS65941_BUCK3_CTRL,  (uint8_t)0xFF,  (uint8_t)0xB3 }, /* Hera -> BUCK3_CTRL -> BUCK3_RV_SEL -> 1 (Read Value = 0x33) */
    {PMIC_DEV_2, (uint16_t)D_PMIC_TPS65941_BUCK4_CTRL,  (uint8_t)0xFF,  (uint8_t)0xB3 }, /* Hera -> BUCK4_CTRL -> BUCK4_RV_SEL -> 1 (Read Value = 0x33) */
};

/******************** PMIC Voltmon config Sequence Step 1 **********************/
const pmic_voltmon_config_seq_step_t V_voltmon_cfg_seq_step1_as[D_PMIC_VOLTMON_CFG_SEQ_STEP1_CNT] =
{
    {(uint8_t)D_PMIC_HERA_RAIL_LINK_SEQ_STEP1_CNT, &V_hera_rail_link_seq_step1_as[0]},
    {(uint8_t)D_PMIC_RAIL_GRP_CFG_CNT,             &V_rail_grp_cfg_as[0]},
    {(uint8_t)D_PMIC_VDD_MCUIO_3V3_SEQ_STEP1_CNT,  &V_vdd_mcuio_3v3_seq_step1_as[0]},
    {(uint8_t)D_PMIC_VDD_IO_3V3_SEQ_STEP1_CNT,     &V_vdd_io_3v3_seq_step1_as[0]},
    {(uint8_t)D_PMIC_VDD_5V0_SEQ_STEP1_CNT,        &V_vdd_5v0_seq_step1_as[0]},    
    {(uint8_t)D_PMIC_BUCK_SWITING_MODE_CNT,        &V_buck_switching_mode_as[0]},
    {(uint8_t)D_PMIC_VDD_RAM_0V85_CNT,             &V_vdd_ram_0v85_as[0]},
    {(uint8_t)D_PMIC_SET_UV_OV_THR_CNT,            &V_set_uv_ov_thr_as[0]},
    {(uint8_t)D_UNUSED_PWR_RAIL_CNT,               &V_unused_pwr_rail_as[0]},
    {(uint8_t)D_PMIC_SPREAD_SPECTRUM_SS_CNT,       &V_spread_spectrum_as[0]},
    {(uint8_t)D_PMIC_VDD_MCU_0V85_CNT,             &V_vdd_avs_as[0]},
    {(uint8_t)D_PMIC_VDD_UNUSED_LEOB_LDO3_CNT,     &V_vdd_unused_as[0]}
};

/******************** PMIC Voltmon config Sequence Step 2 **********************/
const pmic_voltmon_config_seq_step_t V_voltmon_cfg_seq_step2_as[D_PMIC_VOLTMON_CFG_SEQ_STEP2_CNT] =
{
    {(uint8_t)D_PMIC_VDD_MCUIO_3V3_SEQ_STEP2_CNT,  &V_vdd_mcuio_3v3_seq_step2_as[0]},
    {(uint8_t)D_PMIC_VDD_IO_3V3_SEQ_STEP2_CNT,     &V_vdd_io_3v3_seq_step2_as[0]},
    {(uint8_t)D_PMIC_VDD_5V0_SEQ_STEP2_CNT,        &V_vdd_5v0_seq_step2_as[0]},
    {(uint8_t)D_RESIDUAL_VOLT_MON_CNT,             &V_residual_volt_mon_enb_as[0]}
};

/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */


/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */

