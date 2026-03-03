/**
 * file pmic_readback.c
 * brief PMIC readback on logic output pin
 *
 * details This file contain the implementation PMIC functional safety
 *          SM 12 readback on logic output pin
 *
 * --------------------------------------------------------------------------
 * copyright MAGNA Electronics - C O N F I D E N T I A L <br>
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
 * author Pramod Kumar (Pramod.kumar1@magna.com)
 */

/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include "pmic_cfg.h"
#include "tps65941_Reg.h"
#include "pmic_error.h"
#include <ti/drv/pmic/src/pmic_io_priv.h>
#include "app_log_Boot.h"
#include "ErrorManagerSatellite.h"
#include "pmic_readback.h"
extern void f_Send_Dbg_SDLFault_CanTx(uint16 SDLFault);
/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
/* PMIC register field bit mask (For configuration Register) */
#define D_PMIC_REG_BITMASK_NRSTOUT_RDBK_MSK             (0x80U)
#define D_PMIC_REG_BITMASK_NINT_RDBK_MSK                     (0x40U)
#define D_PMIC_REG_BITMASK_NRSTOUT_SOC_RDBK_MSK  (0x08U)
#define D_PMIC_REG_BITMASK_EN_DRV_RDBK_MSK               (0x01U)

/* PMIC register field bit mask (For error monitoring Register) */
#define D_PMIC_REG_BITMASK_NRSTOUT_RDBK_INT             (0x80U) /*  PRQA S 0791*//* Specific name used to get exact details of registers used*/
#define D_PMIC_REG_BITMASK_NINT_RDBK_INT                     (0x40U)
#define D_PMIC_REG_BITMASK_RDBK_ERR_INT                        (0x20U)
#define D_PMIC_REG_BITMASK_NRSTOUT_SOC_RDBK_INT  (0x08U) /*  PRQA S 0791*//*Specific name used to get exact details of registers used*/
#define D_PMIC_REG_BITMASK_EN_DRV_RDBK_INT                (0x01U) /*  PRQA S 0791*//* Specific name used to get exact details of registers used*/

/************ Error Capturing to report to error manager **************/
#define D_PMIC_RDBK_ERR_DEV_IDX                               (0x00U)  /* PMIC Device index (0: Master, 1: Slave, 2: Hera) */
#define D_PMIC_RDBK_ERR_REG_ADDR_LO_IDX          (0x02U)  /* Register address Low byte */
#define D_PMIC_RDBK_ERR_REG_VAL_IDX                     (0x03U)  /* Register value */
#define D_PMIC_RDBK_ERR_DATA_LEN                             (0x04U)  /* Error buffer length to report to error manager */

/* ===========================================================================
*
* Typedefs
*
* ========================================================================= */
/* User configurtion structure */
typedef struct pmic_is_readBack_enable
{
    uint8_t is_reportErr_u8;          /* Do we need to report error on failure? (1/0)) */
    ldef_ErrorMgr_enErrorNo errNo_e;  /* Error enum to report to error manager */
}pmic_is_readBack_enable_t;

typedef struct pmic_readBack_errMon
{
    pmic_is_readBack_enable_t nRstout_rdbk_s;      /* NRSTOUT_READBACK */
    pmic_is_readBack_enable_t nInt_rdbk_s;         /* NINT_READBACK */
    pmic_is_readBack_enable_t nRstoutSoc_rdbk_u8;  /* NRSTOUT_SOC_READBACK */
    pmic_is_readBack_enable_t enDrv_rdbk_u8;       /* EN_DRV_READBACK */
}pmic_readBack_errMon_t;

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
/* User configuration as per requirement */
static const pmic_readBack_errMon_t V_PMIC_readback_errmon_as[PMIC_DEV_NUM] =
{
    /* PMIC Master */
    {
        /* is_reportErr_u8,  errNo_e */
        {        0u,          ldef_ErrorMgr_ErrorNum_Max},  /* nRstout_rdbk_s */
        {        0u,          ldef_ErrorMgr_ErrorNum_Max},  /* nInt_rdbk_s */
        {        1u,          ldef_ErrorMgr_Error_SysIntFlt_MCU_SM12_Redundant_Readback_Error_GPIO_Pin_nRSTOUT_SoC_Pin},  /* nRstoutSoc_rdbk_u8 */
        {        0u,          ldef_ErrorMgr_ErrorNum_Max},  /* enDrv_rdbk_u8 */
    },

    /* PMIC Slave */
    {
        /* is_reportErr_u8,  errNo_e */
        {        0u,          ldef_ErrorMgr_ErrorNum_Max},  /* nRstout_rdbk_s */
        {        0u,          ldef_ErrorMgr_ErrorNum_Max},  /* nInt_rdbk_s */
        {        0u,          ldef_ErrorMgr_ErrorNum_Max},  /* nRstoutSoc_rdbk_u8 */
        {        0u,          ldef_ErrorMgr_ErrorNum_Max},  /* enDrv_rdbk_u8 */
    },

    /* PMIC Hera */
#if (D_FEATURE_HERA_ENABLE == 1)
        {
        /* is_reportErr_u8,  errNo_e */
        {        0u,          ldef_ErrorMgr_ErrorNum_Max},  /* nRstout_rdbk_s */
        {        0u,          ldef_ErrorMgr_ErrorNum_Max},  /* nInt_rdbk_s */
        {        0u,          ldef_ErrorMgr_ErrorNum_Max},  /* nRstoutSoc_rdbk_u8 */
        {        0u,          ldef_ErrorMgr_ErrorNum_Max},  /* enDrv_rdbk_u8 */
    }
#endif
};

/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */


/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*
 * Purpose: Check NVM configuration of all readback output pin.
 * Description: Check NVM configuration of all readback output pin
 *              to make sure, monitoring is not disabled.
 * Return Type: void
 */
void Pmic_F_ReadBackConfigCheck_v(void)
{
    /* DD-ID:{51D9BA7C-3B29-4445-ACB5-DB98772CF591}*/
    /* Note 1: Readback is enabled by default
     * Note 2: NVM default value of Interrupt mask (0 -> Intr generated / 1 -> Intr not generated )
     *                      PMIC Master
     *                    ===============
     *      Register    bit_pos   Feature             Master   Slave   Hera
     *     ----------  --------- ---------           -------- ------- ------
     * MASK_MODERATE_ERR  7  NRSTOUT_READBACK_MASK      0        1      1
     * MASK_MODERATE_ERR  6  NINT_READBACK_MASK         0        1      0
     * MASK_READBACK_ERR  3  NRSTOUT_SOC_READBACK_MASK  0        1      1
     * MASK_READBACK_ERR  0  EN_DRV_READBACK_MASK       0        1      1
     *
     */

    uint8_t  v_devIdx_u8;
    uint8_t  v_regDataRd_u8;
    uint8_t  v_regDataWr_u8;
    int32_t  v_pmicStatus_s32;

    /* Iterate through all 3 pmic device */
    for(v_devIdx_u8 = 0; v_devIdx_u8 < (uint8_t)PMIC_DEV_NUM; v_devIdx_u8++)
    {
        /* Is error reporting enabled for NRSTOUT or NINT? */
        if((V_PMIC_readback_errmon_as[v_devIdx_u8].nRstout_rdbk_s.is_reportErr_u8 == 1U) ||
           (V_PMIC_readback_errmon_as[v_devIdx_u8].nInt_rdbk_s.is_reportErr_u8 == 1U))
        {
            /* Read pmic register MASK_MODERATE_ERR */
            v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                      (uint16_t)D_PMIC_TPS65941_MASK_MODERATE_ERR, &v_regDataRd_u8);
            if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
            {
                /* Copy current register value */
                v_regDataWr_u8 = v_regDataRd_u8;

                /* Is error reporting enabled for NRSTOUT? */
                if(V_PMIC_readback_errmon_as[v_devIdx_u8].nRstout_rdbk_s.is_reportErr_u8 == 1U)
                {
                    /* Is NRSTOUT readback monitoring masked in PMIC? */
                    if ((v_regDataRd_u8 & (uint8_t)D_PMIC_REG_BITMASK_NRSTOUT_RDBK_MSK) == (uint8_t)D_PMIC_REG_BITMASK_NRSTOUT_RDBK_MSK)
                    {
                        /* Unmask bit NRSTOUT */
                        v_regDataWr_u8 &= (~(uint8_t)D_PMIC_REG_BITMASK_NRSTOUT_RDBK_MSK);
                    }
                    else
                    {
                        /* Nothing to do */
                    }
                }
                else
                {
                    /* Nothing to do */
                }

                /* Is error reporting enabled for NINT? */
                if(V_PMIC_readback_errmon_as[v_devIdx_u8].nInt_rdbk_s.is_reportErr_u8 == 1U)
                {
                    /* Is NINT readback monitoring masked in PMIC? */
                    if ((v_regDataRd_u8 & (uint8_t)D_PMIC_REG_BITMASK_NINT_RDBK_MSK) == (uint8_t)D_PMIC_REG_BITMASK_NINT_RDBK_MSK)
                    {
                        /* Unmask bit NINT */
                        v_regDataWr_u8 &= (~(uint8_t)D_PMIC_REG_BITMASK_NINT_RDBK_MSK);
                    }
                    else
                    {
                        /* Nothing to do */
                    }
                }
                else
                {
                    /* Nothing to do */
                }

                /* If some of interrupt was masked? -> Then unmask it */
                if(v_regDataWr_u8 != v_regDataRd_u8)
                {
                    /* Write pmic register */
                    v_pmicStatus_s32 = Pmic_commIntf_sendByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                                (uint16_t)D_PMIC_TPS65941_MASK_MODERATE_ERR,
                                                                v_regDataWr_u8);

                    if(v_pmicStatus_s32 != (int32_t)PMIC_ST_SUCCESS)
                    {
                        /* Log error */
                        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_RDBK_CFG, (uint16_t)D_PMIC_ERR_RDBK_CFG_MASK_MODRTE_WR, v_devIdx_u8, 0);
                    } else {/* Do Nothing */}
                } else {/* Do Nothing */}
            }
            else
            {
                /* Log error */
                Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_RDBK_CFG, (uint16_t)D_PMIC_ERR_RDBK_CFG_MASK_MODRTE_RD, v_devIdx_u8, 0);
            }
        }
        else
        {
            /* Nothing to do */
        }

        /* Is error reporting enabled for NRSTOUT_SOC or EN_DRV? */
        if((V_PMIC_readback_errmon_as[v_devIdx_u8].nRstoutSoc_rdbk_u8.is_reportErr_u8 == (uint8_t)TRUE) ||
           (V_PMIC_readback_errmon_as[v_devIdx_u8].enDrv_rdbk_u8.is_reportErr_u8 == (uint8_t)TRUE))
        {
            /* Read pmic register MASK_READBACK_ERR */
            v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                      (uint16_t)D_PMIC_TPS65941_MASK_READBACK_ERR, &v_regDataRd_u8);
            if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
            {
                /* Copy current register value */
                v_regDataWr_u8 = v_regDataRd_u8;

                /* Is error reporting enabled for NRSTOUT_SOC? */
                if(V_PMIC_readback_errmon_as[v_devIdx_u8].nRstoutSoc_rdbk_u8.is_reportErr_u8 == (uint8_t)TRUE)
                {
                    /* Is NRSTOUT_SOC readback monitoring masked in PMIC? */
                    if ((v_regDataRd_u8 & (uint8_t)D_PMIC_REG_BITMASK_NRSTOUT_SOC_RDBK_MSK) == (uint8_t)D_PMIC_REG_BITMASK_NRSTOUT_SOC_RDBK_MSK)
                    {
                        /* Unmask bit NRSTOUT_SOC */
                        v_regDataWr_u8 &= (~(uint8_t)D_PMIC_REG_BITMASK_NRSTOUT_SOC_RDBK_MSK);
                    }
                    else
                    {
                        /* Nothing to do */
                    }
                }
                else
                {
                    /* Nothing to do */
                }
                /* Is error reporting enabled for EN_DRV? */
                if(V_PMIC_readback_errmon_as[v_devIdx_u8].enDrv_rdbk_u8.is_reportErr_u8 == (uint8_t)TRUE)
                {
                    /* Is EN_DRV readback monitoring masked in PMIC? */
                    if ((v_regDataRd_u8 & (uint8_t)D_PMIC_REG_BITMASK_EN_DRV_RDBK_MSK) == (uint8_t)D_PMIC_REG_BITMASK_EN_DRV_RDBK_MSK)
                    {
                        /* Unmask bit EN_DRV */
                        v_regDataWr_u8 &= (~(uint8_t)D_PMIC_REG_BITMASK_EN_DRV_RDBK_MSK);
                    }
                    else
                    {
                        /* Nothing to do */
                    }
                }
                else
                {
                    /* Nothing to do */
                }

                if(v_regDataWr_u8 != v_regDataRd_u8)
                {
                    /* Write pmic register */
                    v_pmicStatus_s32 = Pmic_commIntf_sendByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                                (uint16_t)D_PMIC_TPS65941_MASK_MODERATE_ERR,
                                                                v_regDataWr_u8);

                    if(v_pmicStatus_s32 != (int32_t)PMIC_ST_SUCCESS)
                    {
                        /* Log error */
                        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_RDBK_CFG, (uint16_t)D_PMIC_ERR_RDBK_CFG_MASK_RDBK_WR, v_devIdx_u8, (uint8_t)FALSE);
                    } else {/* Do Nothing */}
                } else {/* Do Nothing */}
            }
            else
            {
                /* Log error */
                Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_RDBK_CFG, (uint16_t)D_PMIC_ERR_RDBK_CFG_MASK_RDBK_RD, v_devIdx_u8, (uint8_t)FALSE);
            }
        }
        else
        {
            /* Nothing to do */
        }
    }
}

/*
 * Purpose: Check error status of readback error monitoring for output pins.
 * Description: Check error status of readback error monitoring for output pins.
 * Return Type: void
 */
void Pmic_F_ReadBackErrMonitor_v(void)
{
    /* DD-ID:{0FF8EEB5-2DF0-4f34-8244-0C1B902768D0}*/
    uint8_t  v_devIdx_u8;
    uint8_t  v_regData_u8;
    int32_t  v_pmicStatus_s32;
    uint8_t  v_errData_u8[D_PMIC_RDBK_ERR_DATA_LEN];  /* Buffer to collect and report error to err mgr */

    /* Iterate through all 3 pmic device */
    for(v_devIdx_u8 = 0; v_devIdx_u8 < (uint8_t)PMIC_DEV_NUM; v_devIdx_u8++)
    {
        /* Is error reporting enabled for NRSTOUT or NINT? */
        if((V_PMIC_readback_errmon_as[v_devIdx_u8].nRstout_rdbk_s.is_reportErr_u8 == (uint8_t)TRUE) ||
           (V_PMIC_readback_errmon_as[v_devIdx_u8].nInt_rdbk_s.is_reportErr_u8 == (uint8_t)TRUE))
        {
            /* Read pmic register INT_MODERATE_ERR */
            v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                      (uint16_t)D_PMIC_TPS65941_INT_MODERATE_ERR, &v_regData_u8);

            if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
            {
                /* Is error reporting enabled for NRSTOUT? */
                if(V_PMIC_readback_errmon_as[v_devIdx_u8].nRstout_rdbk_s.is_reportErr_u8 == (uint8_t)TRUE)
                {
                    /* Is readback error occured for NRSTOUT */
                    if ((v_regData_u8 & (uint8_t)D_PMIC_REG_BITMASK_NRSTOUT_RDBK_INT) == (uint8_t)D_PMIC_REG_BITMASK_NRSTOUT_RDBK_INT)
                    {
                        /* Prepare error info to report to error manager */
                        v_errData_u8[D_PMIC_RDBK_ERR_DEV_IDX] = v_devIdx_u8;                                      /* PMIC Device index */
                        v_errData_u8[D_PMIC_RDBK_ERR_REG_ADDR_LO_IDX] = (uint8_t)(D_PMIC_TPS65941_INT_MODERATE_ERR & PMIC_MASK_LOWER_BYTE);        /* Reg addr Lower byte */
                        v_errData_u8[D_PMIC_RDBK_ERR_REG_VAL_IDX] = v_regData_u8;

                        /* Report error to error manager to Perform Safe state 2 */
                        (void)ErrorMgrSatellite_ReportErrorStatus(V_PMIC_readback_errmon_as[v_devIdx_u8].nRstout_rdbk_s.errNo_e, ldef_ErrorMgr_ErrorActive, (const ldef_ErrorMgr_stAddData *)&v_errData_u8);

                         /* Report error to CAN msg */
                         f_Send_Dbg_SDLFault_CanTx((uint16)V_PMIC_readback_errmon_as[v_devIdx_u8].nRstout_rdbk_s.errNo_e);
                    }
                    else
                    {
                        /* Nothing to do */
                    }
                }
                else
                {
                    /* Nothing to do */
                }

                /* Is error reporting enabled for NINT? */
                if(V_PMIC_readback_errmon_as[v_devIdx_u8].nInt_rdbk_s.is_reportErr_u8 == (uint8_t)TRUE)
                {
                    /* Is readback error occured for NINT */
                    if ((v_regData_u8 & (uint8_t)D_PMIC_REG_BITMASK_NINT_RDBK_INT) == (uint8_t)D_PMIC_REG_BITMASK_NINT_RDBK_INT)
                    {
                        /* Prepare error info to report to error manager */
                        v_errData_u8[D_PMIC_RDBK_ERR_DEV_IDX] = v_devIdx_u8;                                      /* PMIC Device index */
                        v_errData_u8[D_PMIC_RDBK_ERR_REG_ADDR_LO_IDX] = (uint8_t)(D_PMIC_TPS65941_INT_MODERATE_ERR & PMIC_MASK_LOWER_BYTE);        /* Reg addr Lower byte */
                        v_errData_u8[D_PMIC_RDBK_ERR_REG_VAL_IDX] = v_regData_u8;

                        /* Report error to error manager to Perform Safe state 2 */
                        (void)ErrorMgrSatellite_ReportErrorStatus(V_PMIC_readback_errmon_as[v_devIdx_u8].nInt_rdbk_s.errNo_e, ldef_ErrorMgr_ErrorActive, (const ldef_ErrorMgr_stAddData *)&v_errData_u8);
                    }
                    else
                    {
                        /* Nothing to do */
                    }
                }
                else
                {
                    /* Nothing to do */
                }
            }
            else
            {
                /* Log error */
                Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_RDBK_MON, (uint16_t)D_PMIC_ERR_RDBK_INT_MODRTE_ERR_RD, v_devIdx_u8, (uint8_t)FALSE);
            }
        }
        else
        {
            /* Nothing to do */
        }

        /* Is error reporting enabled for NRSTOUT_SOC or EN_DRV? */
        if((V_PMIC_readback_errmon_as[v_devIdx_u8].nRstoutSoc_rdbk_u8.is_reportErr_u8 == (uint8_t)TRUE) ||
           (V_PMIC_readback_errmon_as[v_devIdx_u8].enDrv_rdbk_u8.is_reportErr_u8 == (uint8_t)TRUE))
        {
            /* Read pmic register INT_FSM_ERR */
            v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                      (uint16_t)D_PMIC_TPS65941_INT_FSM_ERR, &v_regData_u8);
            if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
            {
                /* Is readback error latched in INT_READBACK_ERR? */
                if ((v_regData_u8 & (uint8_t)D_PMIC_REG_BITMASK_RDBK_ERR_INT) == (uint8_t)D_PMIC_REG_BITMASK_RDBK_ERR_INT)
                {
                    /* Read pmic register INT_READBACK_ERR */
                    v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                      (uint16_t)D_PMIC_TPS65941_INT_READBACK_ERR, &v_regData_u8);

                    if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
                    {
                        /* Is error reporting enabled for NRSTOUT_SOC? */
                        if(V_PMIC_readback_errmon_as[v_devIdx_u8].nRstoutSoc_rdbk_u8.is_reportErr_u8 == (uint8_t)TRUE)
                        {
                            /* Is readback error occured for NRSTOUT_SOC? */
                            if ((v_regData_u8 & (uint8_t)D_PMIC_REG_BITMASK_NRSTOUT_SOC_RDBK_INT) == (uint8_t)D_PMIC_REG_BITMASK_NRSTOUT_SOC_RDBK_INT)
                            {
                                /* Prepare error info to report to error manager */
                                v_errData_u8[D_PMIC_RDBK_ERR_DEV_IDX] = v_devIdx_u8;                                      /* PMIC Device index */
                                v_errData_u8[D_PMIC_RDBK_ERR_REG_ADDR_LO_IDX] = (uint8_t)(D_PMIC_TPS65941_INT_READBACK_ERR & PMIC_MASK_LOWER_BYTE);        /* Reg addr Lower byte */
                                v_errData_u8[D_PMIC_RDBK_ERR_REG_VAL_IDX] = v_regData_u8;

                                /* Report error to error manager to Perform Safe state 2 */
                               (void)ErrorMgrSatellite_ReportErrorStatus(V_PMIC_readback_errmon_as[v_devIdx_u8].nRstoutSoc_rdbk_u8.errNo_e, ldef_ErrorMgr_ErrorActive, (const ldef_ErrorMgr_stAddData *)&v_errData_u8);
                            }
                            else
                            {
                                /* Nothing to do */
                            }
                        }
                        else
                        {
                            /* Nothing to do */
                        }

                        /* Is error reporting enabled for EN_DRV? */
                        if(V_PMIC_readback_errmon_as[v_devIdx_u8].enDrv_rdbk_u8.is_reportErr_u8 == (uint8_t)TRUE)
                        {
                            /* Is readback error occured for EN_DRV? */
                            if ((v_regData_u8 & (uint8_t)D_PMIC_REG_BITMASK_EN_DRV_RDBK_INT) == (uint8_t)D_PMIC_REG_BITMASK_EN_DRV_RDBK_INT)
                            {
                                /* Prepare error info to report to error manager */
                                v_errData_u8[D_PMIC_RDBK_ERR_DEV_IDX] = v_devIdx_u8;                                      /* PMIC Device index */
                                v_errData_u8[D_PMIC_RDBK_ERR_REG_ADDR_LO_IDX] = (uint8_t)(D_PMIC_TPS65941_INT_READBACK_ERR & PMIC_MASK_LOWER_BYTE);        /* Reg addr Lower byte */
                                v_errData_u8[D_PMIC_RDBK_ERR_REG_VAL_IDX] = v_regData_u8;

                                /* Report error to error manager to Perform Safe state 2 */
                                (void)ErrorMgrSatellite_ReportErrorStatus(V_PMIC_readback_errmon_as[v_devIdx_u8].enDrv_rdbk_u8.errNo_e, ldef_ErrorMgr_ErrorActive, (const ldef_ErrorMgr_stAddData *)&v_errData_u8);
                            }
                            else
                            {
                                /* Nothing to do */
                            }
                        }
                        else
                        {
                            /* Nothing to do */
                        }
                    }
                    else
                    {
                        /* Log error */
                        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_RDBK_MON, (uint16_t)D_PMIC_ERR_RDBK_INT_READBACK_ERR_RD, v_devIdx_u8, (uint8_t)FALSE);
                    }
                }
                else
                {
                    /* Nothing to do */
                }
            }
            else
            {
                /* Log error */
                Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_RDBK_MON, (uint16_t)D_PMIC_ERR_RDBK_INT_FSM_ERR_RD, v_devIdx_u8, (uint8_t)FALSE);
            }
        }
        else
        {
            /* Nothing to do */
        }
    }
}
