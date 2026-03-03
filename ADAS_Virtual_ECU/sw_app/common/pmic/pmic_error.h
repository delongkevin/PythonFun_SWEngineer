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
 
#ifndef __PMIC_ERROR_H
#define __PMIC_ERROR_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "pmic_cfg.h"
#include "pmic_voltmon_cfg.h"
#include <ti/drv/pmic/include/pmic_core.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/************ Error Capturing for local debugging **************/
/* Error type */
#define D_PMIC_ERR_TYPE_VMON_INIT_CMN          (0x01)   /* Init common error */
#define D_PMIC_ERR_TYPE_VMON_INIT              (0x02)   /* Init error */
#define D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV      (0x03)   /* Run time PMIC specific error */
#define D_PMIC_ERR_TYPE_VMON_RUN_TIME_BUCK     (0x04)   /* Run time BUCK specific error */
#define D_PMIC_ERR_TYPE_VMON_RUN_TIME_LDO      (0x05)   /* Run time LDO specific error */
#define D_PMIC_ERR_TYPE_BIST_STS_CHECK         (0x06)   /* Run time Bist status check error */
#define D_PMIC_ERR_TYPE_RDBK_CFG               (0x07)   /* Readback logic error during configuration check */
#define D_PMIC_ERR_TYPE_RDBK_MON               (0x08)   /* Readback logic error during runtime */
#define D_PMIC_ERR_LBIST                       (0x09)   /* LBIST error occured */
#define D_PMIC_ERR_TWARN                       (0x0A)   /* Thermal warning */
#define D_PMIC_ERR_TYPE_MCU_ESM                (0x0B)   /* ESM_MCU Enable Bit Error*/
#define D_PMIC_ERR_TYPE_CLOCKMON_EN            (0x0C)   /* CLOCKMON_EN Error*/
#define D_PMIC_ERR_TYPE_REG_LOCK               (0x0D)   /* Register lock Error*/

/*Init common Error */
#define D_PMIC_ERR_VMON_INIT_CFG_STEP          (0x01) /* Invalid config step number passed to function Pmic_F_VoltmonConfigStep_v() */

/*Init Error */
#define D_PMIC_ERR_VMON_INIT_REG_RD            (0x01)   /* PMIC register read failed during init */
#define D_PMIC_ERR_VMON_INIT_REG_WR            (0x02)   /* PMIC register write failed during init */

/* Device specific runtime error */
#define D_PMIC_ERR_VMON_ERR_RECVRY_MON_TYPE    (0x0001) /* Invalid monitor type passed to function Pmic_f_monitorErrRecovery_v() */
#define D_PMIC_ERR_VMON_CMN_ERR_RECVRY_DEV_ID  (0x0002) /* Invalid PMIC dev id passed to function Pmic_f_monitorErrRecovery_v() */
#define D_PMIC_ERR_VMON_INT_TOP_RD             (0x0004) /* PMIC register INT_TOP read failed */
#define D_PMIC_ERR_VMON_INT_BUCK_RD            (0x0008) /* PMIC register INT_BUCK read failed */
#define D_PMIC_ERR_VMON_INT_BUCK1_2_RD         (0x0010) /* PMIC register INT_BUCK1_2 read failed */
#define D_PMIC_ERR_VMON_INT_BUCK3_4_RD         (0x0020) /* PMIC register INT_BUCK3_4 read failed */
#define D_PMIC_ERR_VMON_INT_BUCK5_RD           (0x0040) /* PMIC register INT_BUCK5 read failed */
#define D_PMIC_ERR_VMON_INT_LDO_VMON_RD        (0x0080) /* PMIC register INT_LDO_VMON read failed */
#define D_PMIC_ERR_VMON_INT_LDO1_2_RD          (0x0100) /* PMIC register INT_LDO1_2 read failed */
#define D_PMIC_ERR_VMON_INT_LDO3_4_RD          (0x0200) /* PMIC register INT_LDO3_4 read failed */
#define D_PMIC_ERR_VMON_RD                     (0x0400) /* PMIC register INT_VMON read failed */
#define D_PMIC_ERR_VMON_INT_VMON_RD            (0x0800) /* PMIC register INT_VMON read failed */
#define D_PMIC_ERR_VMON_CHK_ERR_RGLTR_TYPE     (0x1000) /* Invalid regulator type passed to function Pmic_f_checkErrStsBit_v() */
#define D_PMIC_ERR_VCCA_ERR_OCCURED            (0x2000) /* VCCA voltage out of range error occured */


/* Buck / LDO specific runtime error */
#define D_PMIC_ERR_VMON_CHK_ERR_CLEAR_ILIM_ERR (0x01)   /* Write to PMIC register to clear ILIM error failed */
#define D_PMIC_ERR_VMON_CHK_ERR_MON_TYPE       (0x02)   /* Invalid monitor type passed to function Pmic_f_checkErrStsBit_v() */
#define D_PMIC_ERR_VOLT_ERR_OCCURED            (0x04)   /* Voltage out of range error occured */
#define D_PMIC_ERR_ILIM_ERR_OCCURED            (0x08)   /* ILIM error occured */
#define D_PMIC_ERR_RV_ERR_OCCURED              (0x10)   /* Resudual voltage out of range error occured */

/* Bist status check error */
#define D_PMIC_ERR_BIST_STS_INT_MISC_RD        (0x01)   /* PMIC register INT_MISC read fail */
#define D_PMIC_ERR_BIST_STS_INT_MODERATE_RD    (0x02)   /* PMIC register INT_MODERATE read fail */

/* Readback logic error */
  /* Config error */
#define D_PMIC_ERR_RDBK_CFG_MASK_MODRTE_RD     (0x01)   /* PMIC register MASK_MODERATE_ERR read fail */
#define D_PMIC_ERR_RDBK_CFG_MASK_MODRTE_WR     (0x02)   /* PMIC register MASK_MODERATE_ERR write fail */
#define D_PMIC_ERR_RDBK_CFG_MASK_RDBK_RD       (0x04)   /* PMIC register MASK_READBACK_ERR read fail */
#define D_PMIC_ERR_RDBK_CFG_MASK_RDBK_WR       (0x08)   /* PMIC register MASK_READBACK_ERR write fail */

  /* Runtime error (Error monitoring) */
#define D_PMIC_ERR_RDBK_INT_MODRTE_ERR_RD      (0x01)   /* PMIC register INT_MODERATE_ERR read fail */
#define D_PMIC_ERR_RDBK_INT_FSM_ERR_RD         (0x02)   /* PMIC register INT_FSM_ERR read fail */
#define D_PMIC_ERR_RDBK_INT_READBACK_ERR_RD    (0x04)   /* PMIC register INT_READBACK_ERR read fail */

/* Lbist error */
#define D_PMIC_ERR_LBIST_RTC_CTRL_2_RD         (0x01)   /* PMIC register RTC_CTRL_2 read fail */

/* Thermal warning */
#define D_PMIC_ERR_TWARN_INT_MISC_RD           (0x01)   /* PMIC register INT_MISC read fail */

/*Error Signal Monitoring MCU Error*/
#define D_PMIC_ERR_ESM_MCU_EN_ERR_RD           (0x01)   /*MIC ESM MCU Error Read Fail*/

/* CLOCKMON_EN error */
#define D_PMIC_ERR_CLKMON_MISC_CTR_RD          (0x01)   /* PMIC register MISC_CTRL read fail */
#define D_PMIC_ERR_CLKMON_MISC_CTR_WR          (0x02)   /* PMIC register MISC_CTRL write fail */

/* Register lock error */
#define D_PMIC_ERR_REG_LOCK_WR                 (0x01)   /* PMIC register REGISTER_LOCK write fail */

/*ESM_MCU DELAY Registers Write Error*/
#define D_PMIC_ERR_DELAY1_WRITE_ERR_WR         (0x01)   /*PMIC ESM MCU DELAY1 Register Write Fail*/
#define D_PMIC_ERR_DELAY2_WRITE_ERR_WR         (0x02)   /*PMIC ESM MCU DELAY2 Register Write Fail*/

/*Error Signal Monitoring ESM_MCU_START Write Error*/
#define D_PMIC_ERR_START_WRITE_ERR_WR          (0x01)   /*PMIC ESM MCU DELAY1 Register Write Fail*/

/*Error Signal Monitoring ESM_MCU_MODE_CFG Write Error*/
#define D_PMIC_ERR_MCU_ESM_ESM_MCU_START_REG_RD         (0x01)   /*PMIC ESM_MCU_MODE_CFG Register Write Fail*/
#define D_PMIC_ERR_MCU_ESM_ESM_MCU_START_REG_WR         (0x02)   /*PMIC ESM_MCU_MODE_CFG Register Write Fail*/
#define D_PMIC_ERR_MCU_ESM_ESM_MCU_DELAY1_REG_WR        (0x04)   /*PMIC ESM_MCU_MODE_CFG Register Write Fail*/
#define D_PMIC_ERR_MCU_ESM_ESM_MCU_DELAY2_REG_WR        (0x08)   /*PMIC ESM_MCU_MODE_CFG Register Write Fail*/
#define D_PMIC_ERR_MCU_ESM_ESM_MCU_MODE_CFG_WR          (0x10)   /*PMIC ESM_MCU_MODE_CFG Register Write Fail*/


/* Voltmon init error */
typedef struct pmic_voltmon_init_err
{
    uint8_t  v_isErr_u8;                     /* Is any init error? */
    uint16_t v_initCmnErr_u16;               /* Init common error */
    uint16_t v_initErr_au16[PMIC_DEV_NUM];   /* Device specific init error */
}pmic_voltmon_init_err_t;

/* Voltmon runtime error */
typedef struct pmic_voltmon_runTime_err
{
    uint8_t  v_isErr_u8;                     /* Is any run time error? */
    uint16_t v_devSpecificErr_u16;           /* Device specific run time error */
    uint16_t v_buckErr_au16[D_BUCK_CNT];     /* Error for buck */
    uint16_t v_ldoErr_au16[D_LDO_CNT];       /* Error for ldo */
}pmic_voltmon_runTime_err_t;

/* PMIC voltmon error */
typedef struct pmic_voltmon_error
{
    pmic_voltmon_init_err_t     v_initErr_s;                    /* Init error */
    pmic_voltmon_runTime_err_t  v_runTimeErr_as[PMIC_DEV_NUM];  /* Run time error? */
}pmic_voltmon_error_t;

/* PMIC bist status check error */
typedef struct pmic_bist_sts_check_error
{
    uint8_t  v_isErr_u8;                     /* Is any error? */
    uint16_t v_runTimeErr_u16[PMIC_DEV_NUM];  /* Run time error? */
}pmic_bist_sts_check_error_t;

/* PMIC Readback logic monitor error */
typedef struct rdbk_err
{
    uint8_t  v_isErr_u8;                      /* Is any error? */
    uint16_t v_configErr_u16;                 /* Run time error? */
    uint16_t v_runTimeErr_u16;                /* Run time error? */
}rdbk_err_t;

typedef struct pmic_readback_error
{
    rdbk_err_t  v_rdbk_err_as[PMIC_DEV_NUM];  /* Readback error array for all pmic device */
}pmic_readback_error_t;

/* PMIC lbist error */
typedef struct pmic_lbist_error
{
    uint8_t  v_isErr_u8;                      /* Is any error? */
    uint16_t v_errCode_au16[PMIC_DEV_NUM];      /* Error code */
}pmic_lbist_error_t;

/* PMIC thermal warning */
typedef struct pmic_twarn
{
    uint8_t  v_isErr_u8;                      /* Is any error? */
    uint16_t v_errCode_au16[PMIC_DEV_NUM];    /* Error code */
}pmic_twarn_t;


/* PMIC CLOCKMON_EN error  */
typedef struct pmic_clkmon_en_error
{
    uint8_t  v_isErr_u8;                      /* Is any error? */
    uint16_t v_errCode_au16[PMIC_DEV_NUM];
}pmic_clkmon_en_error_t;

/* PMIC Register lock error  */
typedef struct pmic_reg_lock_error
{
    uint8_t  v_isErr_u8;                      /* Is any error? */
    uint16_t v_errCode_au16[PMIC_DEV_NUM];
}pmic_reg_lock_error_t;

/* PMIC MCU ESM Error */
typedef struct pmic_mcu_esm_en_error
{
    uint8_t  v_isErr_u8;                      /* Is any error? */
    uint16_t v_errCode_au16[PMIC_DEV_NUM];
}pmic_mcu_esm_en_error_t;

/* PMIC CRCError */
typedef struct pmic_crc_error
{
    uint8_t  v_isErr_u8;                      /* Is any error? */
    int32_t v_crcRead_err_as32[PMIC_DEV_NUM];
    int32_t v_crcWrite_err_as32[PMIC_DEV_NUM];
}pmic_crc_error_t;

/* Error collecting structure */
typedef struct pmic_error_status
{
    pmic_voltmon_error_t         voltmon_err_s;      /* Voltmon error */
    pmic_bist_sts_check_error_t  bistStsCheck_err_s; /* Bist Stats check error */
    pmic_readback_error_t        readback_err_s;     /* Readback error */
    pmic_lbist_error_t           lbist_err_s;        /* lbist error */
    pmic_twarn_t                 twarn_s;            /* Thermal warning */
    pmic_clkmon_en_error_t       clkmon_en_err_s;    /* CLOCKMON_EN Error */
    pmic_reg_lock_error_t        reg_lock_err_s;     /* Register lock Error */
    pmic_mcu_esm_en_error_t      esm_mcu_en_err_s;   /*ESM_MCU_MODE_CFG Write Error*/
    pmic_crc_error_t             crc_error_s;        /* CRC Error Read/ Write */
}pmic_error_status_t;

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                         External variables                                 */
/* ========================================================================== */
extern pmic_error_status_t  V_pmic_err_s;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
void Pmic_F_CollectErr_v(uint16_t i_errType_u16, uint16_t i_errNum_u16, uint8_t i_devIdx_u8, uint8_t i_regulatorIdx_u8);

/* === End Of Header File ================================================= */
#endif  /* __PMIC_ERROR_H */
