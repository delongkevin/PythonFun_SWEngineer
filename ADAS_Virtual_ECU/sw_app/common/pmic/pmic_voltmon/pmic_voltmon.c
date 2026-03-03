/**
 * @file pmic_voltmon.c
 * @brief PMIC voltage monitoring
 *
 * @details This file provides interface to monitor PMIC voltage
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
#include "pmic_voltmon.h"
#include "tps65941_Reg.h"
#include "pmic.h"
#include "pmic_error.h"
#include <ti/drv/pmic/src/pmic_io_priv.h>
#include "app_log_Boot.h"
#include "ErrorManagerSatellite.h"
#include "pmic_bist_sts.h"
#include "pmic_readback.h"
#include "pmic_lbist.h"
#include "pmic_clock_mon.h"
#include "pmic_reg_lock.h"
#include "pmic_utils.h"
extern void f_Send_Dbg_SDLFault_CanTx(uint16 SDLFault);
/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
/************ Error Capturing to report to error manager **************/
#define D_PMIC_VOLTMON_ERR_DEV_IDX            (0x00)  /* PMIC Decice index (0: Master, 1: Slave, 2: Hera) */
#define D_PMIC_VOLTMON_ERR_REG_ADDR_HI_IDX    (0x01)  /* Register address High byte */
#define D_PMIC_VOLTMON_ERR_REG_ADDR_LO_IDX    (0x02)  /* Register address Low byte */
#define D_PMIC_VOLTMON_ERR_REG_VAL_IDX        (0x03)  /* Register value */
#define D_PMIC_VOLTMON_ERR_DATA_LEN           (0x04)  /* Error buffer length to report to error manager */
#define D_PMIC_VOLTMON_BITPOS_WR_VAL          (0xFFu)  

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
static void Pmic_f_monitorErrRecovery_v (uint8_t i_devIdx_u8, uint8_t i_monType_u8, uint16_t i_regAddr_u16, uint8_t i_regVal_u8);
static void Pmic_f_checkErrStsBit_v     (uint8_t i_devIdx_u8, uint8_t i_regulatorType_u8, uint8_t i_regulatorIdx_u8,
                                         uint8_t i_monType_u8, uint8_t i_regData_u8, uint8_t i_checkBitMask_u8,
                                         uint16_t i_regAddr_u16);
static void Pmic_f_checkVccaErr_v(uint8_t i_devIdx_u8, uint8_t i_regData_u8, uint16_t i_regAddr_u16);
static void Pmic_f_initCurrErrCntr_v(void);
static void Pmic_f_ClearCurrErrCntr_v(void);

/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */
/* Flags to clear ILIM error counter */
static pmic_ILIM_err_cntr_clr_t  V_ilim_err_cntr_clr_as[PMIC_DEV_NUM] = {0};

/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */


/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */
/*
 * Purpose: Initialize flags for ILIM error counter.
 * Description: Initialize flags for ILIM error counter.
 * Return Type: void
 */
static void Pmic_f_initCurrErrCntr_v(void)
{
    /* DD-ID:{14A9DFCB-CA9F-42c4-8D62-09FB82C09A45}*/
    uint8_t v_devIdx_u8;

    /* Iterate through all 3 pmic device */
    for(v_devIdx_u8 = 0; v_devIdx_u8 < (uint8_t)PMIC_DEV_NUM; v_devIdx_u8++)
    {
        /* Reset flags to 0 */
        V_ilim_err_cntr_clr_as[v_devIdx_u8].buck_ilim_err_cntr_clr_u8 = 0;  /* Flag for ILIM error counter for Buck */
        V_ilim_err_cntr_clr_as[v_devIdx_u8].ldo_ilim_err_cntr_clr_u8 = 0;   /* Flag for ILIM error counter for Ldo */
    }
}


/*
 * Purpose: Clear ILIM error counter.
 * Description: Clear ILIM error counter for respective Buck and LDO if flag is set.
 * Return Type: void
 */
static void Pmic_f_ClearCurrErrCntr_v(void)
{
    /* DD-ID:{A9219C1D-94FB-40c2-988D-B63327AD6DDB}*/
    uint8_t v_devIdx_u8;
    uint8_t v_buckIdx_u8;
    uint8_t v_ldoIdx_u8;

    /* Iterate through all 3 pmic device */
    for(v_devIdx_u8 = 0; v_devIdx_u8 < (uint8_t)PMIC_DEV_NUM; v_devIdx_u8++)
    {
        /* Iterate through all Buck */
        for(v_buckIdx_u8 = 0; v_buckIdx_u8 < (uint8_t)D_BUCK_CNT; v_buckIdx_u8++)
        {
            /* If bit mask not set in flag for respective buck */
            if (((V_ilim_err_cntr_clr_as[v_devIdx_u8].buck_ilim_err_cntr_clr_u8) & (uint8_t)(1U << v_buckIdx_u8)) == 0U)
            {
                /* Clear ILIM error counter */
                V_pmic_ILIM_err_cntr_as[v_devIdx_u8].buck_ilim_err_cntr_au8[v_buckIdx_u8] = 0U;
            }
            else
            {
                /* Nothing to do */
            }
        }

        /* Iterate through all Ldo */
        for(v_ldoIdx_u8 = 0; v_ldoIdx_u8 < (uint8_t)D_LDO_CNT; v_ldoIdx_u8++)
        {
            /* If bit mask set in flag for respective LDO */
            if (((V_ilim_err_cntr_clr_as[v_devIdx_u8].ldo_ilim_err_cntr_clr_u8) & (uint8_t)(1U << v_ldoIdx_u8)) == 0U)
            {
                /* Clear ILIM error counter */
                V_pmic_ILIM_err_cntr_as[v_devIdx_u8].ldo_ilim_err_cntr_au8[v_ldoIdx_u8] = 0U;
            }
            else
            {
                /* Nothing to do */
            }
        }
    }

    /* Reset flag for ILIM error counter */
    Pmic_f_initCurrErrCntr_v();
}


/*
 * Purpose: Recovery from error.
 * Description: Recovery from error.
 * Return Type: void
 */
static void Pmic_f_monitorErrRecovery_v (uint8_t i_devIdx_u8, uint8_t i_monType_u8, uint16_t i_regAddr_u16, uint8_t i_regVal_u8)
{
    /* DD-ID:{93A2B06C-BE7C-41a5-9B4B-6EF1CC77502E}*/
    ldef_ErrorMgr_enErrorNo v_errNum_e;
    uint8_t                 v_errData_u8[D_PMIC_VOLTMON_ERR_DATA_LEN] = {0};  /* Buffer to collect and report error to error manager */
    uint8_t                 v_isValidErr_u8 = 0;


    /* If valid PMIC device id */
    if(i_devIdx_u8 < (uint8_t)PMIC_DEV_NUM)
    {
        /* If voltage monitoring for reguloators */
        if(i_monType_u8 == (uint8_t)D_PMIC_MON_TYPE_VOLT)
        {
            /* PMIC master */
            if(i_devIdx_u8 == (uint8_t)PMIC_DEV_0)
            {
                /* Assign respective error number */
                v_errNum_e = ldef_ErrorMgr_Error_SysIntFlt_MCU_SM4_UV_OV_threshold_reached_in_Master_MCU_Rail_group;
            }
            /* PMIC slave */
            else if(i_devIdx_u8 == (uint8_t)PMIC_DEV_1)
            {
                /* Assign respective error number */
                v_errNum_e = ldef_ErrorMgr_Error_SysIntFlt_MCU_SM4_UV_OV_threshold_reached_in_slave_MCU_Rail_group;
            }
#if (D_FEATURE_HERA_ENABLE == 1)
            /* PMIC hera */
            else
            {
                /* Assign respective error number */
                v_errNum_e = ldef_ErrorMgr_Error_SysIntFlt_MCU_SM4_UV_OV_threshold_reached_in_HERA_MCU_Rail_group;
            }
#endif            
            /* This is valid error */
            v_isValidErr_u8 = 1;
        }

        /* If current monitoring for reguloators */
        else if(i_monType_u8 == (uint8_t)D_PMIC_MON_TYPE_CURR)
        {
            /* PMIC master */
            if(i_devIdx_u8 == (uint8_t)PMIC_DEV_0)
            {
                /* Assign respective error number */
                v_errNum_e = ldef_ErrorMgr_Error_SysIntFlt_MCU_SM7_ILIM_Reached_Threshold;
            }
            /* PMIC slave */
            else if(i_devIdx_u8 == (uint8_t)PMIC_DEV_1)
            {
                /* Assign respective error number */
                v_errNum_e = ldef_ErrorMgr_Error_SysIntFlt_MCU_SM7_ILIM_Reached_Threshold_Slave;
            }
#if (D_FEATURE_HERA_ENABLE == 1)
            /* PMIC hera */
            else
            {
                /* Assign respective error number */
                v_errNum_e = ldef_ErrorMgr_Error_SysIntFlt_MCU_SM7_ILIM_Reached_Threshold_HERA;
            }
#endif
            /* This is valid error */
            v_isValidErr_u8 = 1;
        }
#if 0
        /* If residual voltage monitoring for reguloators */
        else if(i_monType_u8 == (uint8_t)D_PMIC_MON_TYPE_RV)
        {
            /* TODO */
            /* This is valid error */
            //v_isValidErr_u8 = 1;
            //v_errNum_e = Assign error enum
        }

        /* If VCCA voltage monitoring for reguloators */
        else if(i_monType_u8 == (uint8_t)D_PMIC_MON_TYPE_VCCA)
        {
            /* TODO */
            /* This is valid error */
            //v_isValidErr_u8 = 1;
            //v_errNum_e = Assign error enum
        }
#endif
        else
        {
            /* Log Error */
            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV, (uint16_t)D_PMIC_ERR_VMON_ERR_RECVRY_MON_TYPE, i_devIdx_u8, 0U);
        }

        if(v_isValidErr_u8 == 1U)
        {
            /* Prepare error info to report to error manager */
            v_errData_u8[D_PMIC_VOLTMON_ERR_DEV_IDX] = i_devIdx_u8;                                      /* PMIC Device index */
            v_errData_u8[D_PMIC_VOLTMON_ERR_REG_ADDR_HI_IDX] = (uint8_t)((i_regAddr_u16 & PMIC_MASK_HIGHER_BYTE) >> 8U); /* Register address higher byte */
            v_errData_u8[D_PMIC_VOLTMON_ERR_REG_ADDR_LO_IDX] = (uint8_t)(i_regAddr_u16 & PMIC_MASK_LOWER_BYTE);        /* Register address Lower byte */
            v_errData_u8[D_PMIC_VOLTMON_ERR_REG_VAL_IDX] = i_regVal_u8;                                  /* Register value */

            /* 2. Report error to error manager to Perform Safe state 2 */
           (void)ErrorMgrSatellite_ReportErrorStatus(v_errNum_e, ldef_ErrorMgr_ErrorActive, (const ldef_ErrorMgr_stAddData *)v_errData_u8);

             /* Report error to CAN msg */
            f_Send_Dbg_SDLFault_CanTx((uint16)v_errNum_e);
        }
        else
        {
            /* Nothing to do - Error already captured */
        }
    }
    else
    {
        /* Log Error */
        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV, (uint16_t)D_PMIC_ERR_VMON_CMN_ERR_RECVRY_DEV_ID, i_devIdx_u8, 0);
    }
}

/*
 * Purpose: Check error bit in value read from PMIC registers.
 * Description: Check error bit in value read from PMIC registers and perform recovery.
 * Return Type: void
 */
static void Pmic_f_checkErrStsBit_v(uint8_t i_devIdx_u8, uint8_t i_regulatorType_u8, uint8_t i_regulatorIdx_u8,
                                    uint8_t i_monType_u8, uint8_t i_regData_u8, uint8_t i_checkBitMask_u8,
                                    uint16_t i_regAddr_u16)
{
    /* DD-ID:{95016397-1B39-4f7e-AFC4-F2835B16379D}*/
    int32_t v_pmicStatus_s32 = (int32_t)PMIC_ST_SUCCESS;

    /* If error captured for Buck */
    if(i_regulatorType_u8 == (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK)
    {
        /* Is Buck supported in PMIC ?*/
        if(V_pmic_monitor_enable_as[i_devIdx_u8].buck_mon_as[i_regulatorIdx_u8].is_buck_Supp_u8 == (uint8_t)1)
        {
            /* Is error captured from voltage monitoring? */
            if(i_monType_u8 == (uint8_t)D_PMIC_MON_TYPE_VOLT)
            {
                /* Is voltage monitoring enabled (user configuration) for respective buck? */
                if(V_pmic_monitor_enable_as[i_devIdx_u8].buck_mon_as[i_regulatorIdx_u8].is_volt_mon_enable_u8 == (uint8_t)1)
                {
                    /* Check respective error bits in register read value to see if any UV/OV interrupt triggered for buck */
                    if ((i_regData_u8 & i_checkBitMask_u8) == i_checkBitMask_u8)
                    {
                        /* Error Occured -> Take action */
                        Pmic_f_monitorErrRecovery_v(i_devIdx_u8, i_monType_u8, i_regAddr_u16, i_regData_u8);

                        /* Log Error */
                        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_BUCK, (uint16_t)D_PMIC_ERR_VOLT_ERR_OCCURED, i_devIdx_u8, i_regulatorIdx_u8);
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

            /* Is error captured from current monitoring? */
            else if(i_monType_u8 == (uint8_t)D_PMIC_MON_TYPE_CURR)
            {
                /* Is current monitoring enabled (user configuration) for respective buck? */
                if(V_pmic_monitor_enable_as[i_devIdx_u8].buck_mon_as[i_regulatorIdx_u8].is_curr_mon_enable_u8 == (uint8_t)1)
                {
                    /* Check respective bits in register read value to see if current out of threshold range interrupt triggered for Buck */
                    if ((i_regData_u8 & (uint8_t)i_checkBitMask_u8) == i_checkBitMask_u8)
                    {
                        /* Error Occured -> Take action
                           1. Increment regulator specific error counter
                           2. If error counter reached 3 -> Report error to error manger to perform safe state */

                        /* Increment error counter */
                        V_pmic_ILIM_err_cntr_as[i_devIdx_u8].buck_ilim_err_cntr_au8[i_regulatorIdx_u8]++;

                        /* Is error counter reached to 3 */
                        if(V_pmic_ILIM_err_cntr_as[i_devIdx_u8].buck_ilim_err_cntr_au8[i_regulatorIdx_u8] >= (uint8_t)D_PMIC_ILIM_ERR_CNT_LIMIT)
                        {
                            /* Take action (Report error to error manager) */
                            Pmic_f_monitorErrRecovery_v(i_devIdx_u8, i_monType_u8, i_regAddr_u16, i_regData_u8);

                            /* Log Error */
                            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_BUCK, (uint16_t)D_PMIC_ERR_ILIM_ERR_OCCURED, i_devIdx_u8, i_regulatorIdx_u8);
                        }
                        else
                        {
                            /* Clear respective error in register (W1C) */
                            v_pmicStatus_s32 = Pmic_commIntf_sendByte(&pmic_device[i_devIdx_u8].pmicCoreHandle,
                                                        i_regAddr_u16, i_checkBitMask_u8);
                            if(v_pmicStatus_s32 != (int32_t)PMIC_ST_SUCCESS)
                            {
                                /* Log Error */
                                Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_BUCK, (uint16_t)D_PMIC_ERR_VMON_CHK_ERR_CLEAR_ILIM_ERR, i_devIdx_u8, i_regulatorIdx_u8);
                            } else {/* Do Nothing */}
                        }

                        /* Set respective bit in flag to not clear the error counter to detect 3 consecutive ILIM error for same Buck */
                        V_ilim_err_cntr_clr_as[i_devIdx_u8].buck_ilim_err_cntr_clr_u8 |= (uint8_t)(1U << i_regulatorIdx_u8);
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

            /* Is error captured from Residual voltage monitoring? */
            else if(i_monType_u8 == (uint8_t)D_PMIC_MON_TYPE_RV)
            {
                /* If Residual voltage monitor enabled (user configuration) for respective buck? */
                if(V_pmic_monitor_enable_as[i_devIdx_u8].buck_mon_as[i_regulatorIdx_u8].is_rv_mon_enable_u8 == (uint8_t)1)
                {
                    /* Check respective bits in register read value to see if residual voltage out of threshold range interrupt triggered for Buck */
                    if ((i_regData_u8 & (uint8_t)i_checkBitMask_u8) == i_checkBitMask_u8)
                    {
                        /* Error Occured -> Take action */
                        Pmic_f_monitorErrRecovery_v(i_devIdx_u8, i_monType_u8, i_regAddr_u16, i_regData_u8);
                        /* Log Error */
                        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_BUCK, (uint16_t)D_PMIC_ERR_RV_ERR_OCCURED, i_devIdx_u8, i_regulatorIdx_u8);
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
                Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_BUCK, (uint16_t)D_PMIC_ERR_VMON_CHK_ERR_MON_TYPE, i_devIdx_u8, i_regulatorIdx_u8);
            }
        }
        else
        {
            /* Nothing to do */
        }
    }

    /* If error captured for Ldo */
    else if(i_regulatorType_u8 == (uint8_t)D_PMIC_REGULATOR_TYPE_LDO)
    {
        /* Is Ldo supported in PMIC ?*/
        if(V_pmic_monitor_enable_as[i_devIdx_u8].ldo_mon_as[i_regulatorIdx_u8].is_ldo_Supp_u8 == (uint8_t)1)
        {
            /* Is error captured from voltage monitoring? */
            if(i_monType_u8 == (uint8_t)D_PMIC_MON_TYPE_VOLT)
            {
                /* Is voltage monitoring enabled (user configuration) for respective Ldo? */
                if(V_pmic_monitor_enable_as[i_devIdx_u8].ldo_mon_as[i_regulatorIdx_u8].is_volt_mon_enable_u8 == (uint8_t)1)
                {
                    /* Check respective error bits in register read value to see if any UV/OV interrupt triggered for Ldo */
                    if ((i_regData_u8 & i_checkBitMask_u8) == i_checkBitMask_u8)
                    {
                        /* Error Occured -> Take action */
                        Pmic_f_monitorErrRecovery_v(i_devIdx_u8, i_monType_u8, i_regAddr_u16, i_regData_u8);

                        /* Log Error */
                        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_LDO, (uint16_t)D_PMIC_ERR_VOLT_ERR_OCCURED, i_devIdx_u8, i_regulatorIdx_u8);

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

            /* Is error captured from current monitoring? */
            else if(i_monType_u8 == (uint8_t)D_PMIC_MON_TYPE_CURR)
            {
                /* Is current monitoring enabled (user configuration) for respective Ldo? */
                if(V_pmic_monitor_enable_as[i_devIdx_u8].ldo_mon_as[i_regulatorIdx_u8].is_curr_mon_enable_u8 == (uint8_t)1)
                {
                    /* Check respective bits in register read value to see if current out of threshold range interrupt triggered for Ldo */
                    if ((i_regData_u8 & (uint8_t)i_checkBitMask_u8) == i_checkBitMask_u8)
                    {
                        /* Error Occured -> Take action
                           1. Increment regulator specific error counter
                           2. If error counter reached 3 -> Report error to error manger to perform safe state */

                        /* Increment error counter */
                        V_pmic_ILIM_err_cntr_as[i_devIdx_u8].ldo_ilim_err_cntr_au8[i_regulatorIdx_u8]++;

                        /* Is error counter reached to 3 */
                        if(V_pmic_ILIM_err_cntr_as[i_devIdx_u8].ldo_ilim_err_cntr_au8[i_regulatorIdx_u8] >= (uint8_t)D_PMIC_ILIM_ERR_CNT_LIMIT)
                        {
                            /* Take action (Report error to error manager) */
                            Pmic_f_monitorErrRecovery_v(i_devIdx_u8, i_monType_u8, i_regAddr_u16, i_regData_u8);
                            /* Log Error */
                            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_LDO, (uint16_t)D_PMIC_ERR_ILIM_ERR_OCCURED, i_devIdx_u8, i_regulatorIdx_u8);
                        }
                        else
                        {
                            /* Clear respective error in register (W1C) */
                            v_pmicStatus_s32 = Pmic_commIntf_sendByte(&pmic_device[i_devIdx_u8].pmicCoreHandle,
                                                        i_regAddr_u16, i_checkBitMask_u8);
                            if(v_pmicStatus_s32 != (int32_t)PMIC_ST_SUCCESS)
                            {
                                /* Log Error */
                                Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_LDO, (uint16_t)D_PMIC_ERR_VMON_CHK_ERR_CLEAR_ILIM_ERR, i_devIdx_u8, i_regulatorIdx_u8);
                            } else {/* Do Nothing */}
                        }
                        /* Set respective bit in flag to not clear the error counter to detect 3 consecutive ILIM error for same Ldo */
                        V_ilim_err_cntr_clr_as[i_devIdx_u8].ldo_ilim_err_cntr_clr_u8 |= (uint8_t)(1U << i_regulatorIdx_u8);
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

            /* Is error captured from Residual voltage monitoring? */
            else if(i_monType_u8 == (uint8_t)D_PMIC_MON_TYPE_RV)
            {
                /* If Residual voltage monitor enabled (user configuration) for respective Ldo? */
                if(V_pmic_monitor_enable_as[i_devIdx_u8].ldo_mon_as[i_regulatorIdx_u8].is_rv_mon_enable_u8 == (uint8_t)1)
                {
                    /* Check respective bits in register read value to see if residual voltage out of threshold range interrupt triggered for Ldo */
                    if ((i_regData_u8 & i_checkBitMask_u8) == i_checkBitMask_u8)
                    {
                        /* Error Occured -> Take action */
                        Pmic_f_monitorErrRecovery_v(i_devIdx_u8, i_monType_u8, i_regAddr_u16, i_regData_u8);
                        /* Log Error */
                        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_LDO, (uint16_t)D_PMIC_ERR_RV_ERR_OCCURED, i_devIdx_u8, i_regulatorIdx_u8);
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
                Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_LDO, (uint16_t)D_PMIC_ERR_VMON_CHK_ERR_MON_TYPE, i_devIdx_u8, i_regulatorIdx_u8);
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
        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV, (uint16_t)D_PMIC_ERR_VMON_CHK_ERR_RGLTR_TYPE, i_devIdx_u8, 0);
    }
}

/*
 * Purpose: Check VCCA OV/UV error.
 * Description: Check VCCA OV/UV error.
 * Return Type: void
 */
static void Pmic_f_checkVccaErr_v(uint8_t i_devIdx_u8, uint8_t i_regData_u8, uint16_t i_regAddr_u16)
{
    /* DD-ID:{BBB8ED56-F08A-4026-A2D1-45062835756D}*/
    /* Check respective bits in INT_VMON register to see if UV/OV interrupt triggered for VCCA */
    if (((i_regData_u8 & D_VCCA_OV_INT_BIT_MASK) == D_VCCA_OV_INT_BIT_MASK) ||
        ((i_regData_u8 & D_VCCA_UV_INT_BIT_MASK) == D_VCCA_UV_INT_BIT_MASK))
    {
        /* Error Occured -> Take action */
        Pmic_f_monitorErrRecovery_v(i_devIdx_u8, (uint8_t)D_PMIC_MON_TYPE_VCCA, i_regAddr_u16, i_regData_u8);

        /* Log Error */
        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV, (uint16_t)D_PMIC_ERR_VCCA_ERR_OCCURED, i_devIdx_u8, 0);
    }
    else
    {
        /* Nothing to do */
    }
}

/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*
 * Purpose: Configure PMIC Bucks and LDO assosiated register as per HSIS.
 * Description: Configure PMIC Bucks and LDO assosiated register as per HSIS.
 * Return Type: void
 */
void Pmic_F_VoltmonConfigStep_v(uint8_t i_step_u8)
{
    /* DD-ID:{1BDB9594-7153-421a-A3FB-4C50E6653986}*/
    int32_t v_pmicStatus_s32 = (int32_t)PMIC_ST_SUCCESS;
    uint8_t v_regData_u8 = 0;
    uint8_t  v_stepIdx_u8;
    uint8_t  v_seqIdx_u8;
    uint8_t  v_stepCnt_u8 = (uint8_t)D_PMIC_VOLTMON_CFG_SEQ_INV;
    const pmic_voltmon_config_seq_t *v_cfg_seq_ps;
    const pmic_voltmon_config_seq_step_t *V_voltmon_cfg_seq_ps;

    /* configure voltmon step 1 sequence */
    if(i_step_u8 == (uint8_t)D_PMIC_VOLTMON_CFG_STEP_1)
    {
        v_stepCnt_u8 = (uint8_t)D_PMIC_VOLTMON_CFG_SEQ_STEP1_CNT;
        V_voltmon_cfg_seq_ps = &V_voltmon_cfg_seq_step1_as[0];

        Pmic_f_initCurrErrCntr_v();
    }
    /* configure voltmon step 2 sequence */
    else if(i_step_u8 == (uint8_t)D_PMIC_VOLTMON_CFG_STEP_2)
    {
        v_stepCnt_u8 = (uint8_t)D_PMIC_VOLTMON_CFG_SEQ_STEP2_CNT;
        V_voltmon_cfg_seq_ps = &V_voltmon_cfg_seq_step2_as[0];
    }
    else
    {
        /* Log Error */
        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_INIT_CMN, (uint16_t)D_PMIC_ERR_VMON_INIT_CFG_STEP, 0, 0);
    }

    /* If no error */
    if( v_stepCnt_u8 != (uint8_t)D_PMIC_VOLTMON_CFG_SEQ_INV)
    {
        /* Test Code */
#if (D_PMIC_DBG_PRINT_VOLTMON_CFG_DATA == 1)
        #ifdef Enable_Printf
        APP_log(APP_LOG_ERR,"PMIC: Before writing cfg register\n");
        #endif
        for(v_stepIdx_u8 = 0; v_stepIdx_u8 < (uint8_t)v_stepCnt_u8; v_stepIdx_u8++)
        {
            #ifdef Enable_Printf
            APP_log(APP_LOG_ERR,"V_voltmon_cfg_seq_ps[v_stepIdx_u8].seq_cnt_u8 = %d\n", V_voltmon_cfg_seq_ps[v_stepIdx_u8].seq_cnt_u8);
            #endif
            for(v_seqIdx_u8 = 0; v_seqIdx_u8 < V_voltmon_cfg_seq_ps[v_stepIdx_u8].seq_cnt_u8; v_seqIdx_u8++)
            {
                v_cfg_seq_ps = &V_voltmon_cfg_seq_ps[v_stepIdx_u8].step1_s[v_seqIdx_u8];


                v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_cfg_seq_ps->devId_e].pmicCoreHandle,
                                                        v_cfg_seq_ps->pmic_cfg_reg_addr_u16,
                                                        &v_regData_u8);
                if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
                {
                    #ifdef Enable_Printf
                    APP_log(APP_LOG_ERR,"PMIC_IC = %d, Reg = %d, Data = %d\n", v_stepIdx_u8, v_seqIdx_u8, v_regData_u8);
                    #endif
                }
                else
                {
                    #ifdef Enable_Printf
                    APP_log(APP_LOG_ERR,"PMIC Reg read error, PMIC_IC = %d, Reg = %d\n", v_stepIdx_u8, v_seqIdx_u8);
                    #endif
                }
            }
        }
#endif

        /* Itereate through all steps of configuration */
        for(v_stepIdx_u8 = 0; v_stepIdx_u8 < (uint8_t)v_stepCnt_u8; v_stepIdx_u8++)
        {
            /* Itereate through all sequence of configuration */
            for(v_seqIdx_u8 = 0; v_seqIdx_u8 < V_voltmon_cfg_seq_ps[v_stepIdx_u8].seq_cnt_u8; v_seqIdx_u8++)
            {
                /* Copy sequence */
                v_cfg_seq_ps = &V_voltmon_cfg_seq_ps[v_stepIdx_u8].step1_s[v_seqIdx_u8];

                /* if few bits of register to write -> Read, modify, write */
                if (v_cfg_seq_ps->bitpos_u8 != (uint8_t)D_PMIC_VOLTMON_BITPOS_WR_VAL)
                {
                    /* Read pmic register */
                    v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_cfg_seq_ps->devId_e].pmicCoreHandle,
                                                        v_cfg_seq_ps->pmic_cfg_reg_addr_u16,
                                                        &v_regData_u8);
                    if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
                    {
                        /* Modify register value */
                        v_regData_u8 = ((v_regData_u8 & (~v_cfg_seq_ps->bitpos_u8)) | (v_cfg_seq_ps-> reg_value_u8));
                    }
                    else
                    {
                        /* Log Error */
                        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_INIT, (uint16_t)D_PMIC_ERR_VMON_INIT_REG_RD, (uint8_t)v_cfg_seq_ps->devId_e, 0);
                        #ifdef PMIC_PRINT_ENABLE
                        APP_log(APP_LOG_ERR,"PMIC Voltmon cfg err:Read, PMIC IC: %d, Reg addr = %d\n", (uint8_t)v_cfg_seq_ps->devId_e, v_cfg_seq_ps->pmic_cfg_reg_addr_u16);
                        #endif
                    }
                }
                /*if all bits of register to write -> Directly write data */
                else
                {
                    /* Copy data to write */
                    v_regData_u8 = v_cfg_seq_ps-> reg_value_u8;
                }

                if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
                {
                    /* Write pmic register */
                    v_pmicStatus_s32 = Pmic_commIntf_sendByte(&pmic_device[v_cfg_seq_ps->devId_e].pmicCoreHandle,
                                                        v_cfg_seq_ps->pmic_cfg_reg_addr_u16,
                                                        v_regData_u8);
                    if(v_pmicStatus_s32 != (int32_t)PMIC_ST_SUCCESS)
                    {
                        /* Log Error */
                        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_INIT, (uint16_t)D_PMIC_ERR_VMON_INIT_REG_WR, (uint8_t)v_cfg_seq_ps->devId_e, 0);
                        #ifdef PMIC_PRINT_ENABLE
                        APP_log(APP_LOG_ERR,"PMIC Voltmon cfg err:Write, PMIC IC: %d, Reg addr = %d\n", (uint8_t)v_cfg_seq_ps->devId_e, v_cfg_seq_ps->pmic_cfg_reg_addr_u16);
                        #endif
                    } else {/* Do Nothing */}
                }
                else
                {
                    /* Nothing to do, error already logged */
                }

            }
        }

/* Test Code */
#if (D_PMIC_DBG_PRINT_VOLTMON_CFG_DATA == 1)
        #ifdef PMIC_PRINT_ENABLE
        APP_log(APP_LOG_ERR,"PMIC: After writing cfg register\n");
        #endif
        for(v_stepIdx_u8 = 0; v_stepIdx_u8 < (uint8_t)v_stepCnt_u8; v_stepIdx_u8++)
        {
            #ifdef PMIC_PRINT_ENABLE
            APP_log(APP_LOG_ERR,"V_voltmon_cfg_seq_ps[v_stepIdx_u8].seq_cnt_u8 = %d\n", V_voltmon_cfg_seq_ps[v_stepIdx_u8].seq_cnt_u8);
            #endif
            for(v_seqIdx_u8 = 0; v_seqIdx_u8 < V_voltmon_cfg_seq_ps[v_stepIdx_u8].seq_cnt_u8; v_seqIdx_u8++)
            {
                v_cfg_seq_ps = &V_voltmon_cfg_seq_ps[v_stepIdx_u8].step1_s[v_seqIdx_u8];


                v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_cfg_seq_ps->devId_e].pmicCoreHandle,
                                                        v_cfg_seq_ps->pmic_cfg_reg_addr_u16,
                                                        &v_regData_u8);
                if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
                {
                    #ifdef PMIC_PRINT_ENABLE
                    APP_log(APP_LOG_ERR,"PMIC_IC = %d, Reg = %d, Data = %d\n", v_stepIdx_u8, v_seqIdx_u8, v_regData_u8);
                    #endif
                }
                else
                {
                    #ifdef PMIC_PRINT_ENABLE
                    APP_log(APP_LOG_ERR,"PMIC Reg read error, PMIC_IC = %d, Reg = %d\n", v_stepIdx_u8, v_seqIdx_u8);
                    #endif
                }
            }
        }
#endif
    } else {/* Do Nothing */}
}


/*
 * Purpose: PMIC voltage monitoring 10ms Task.
 * Description: PMIC voltage monitoring 10ms Task.
 * Return Type: void
 */
void Pmic_F_Voltmon_v(void)
{
    /*
     *                                   For Master / Slave
     *                                ==========================
     *
     *                                          INT_TOP
     *                                             |
     *                      +------------------------------------------+
     *                      |                                          |
     *                  INT_BUCK                                 INT_LDO_VMON
     *                      |                                          |
     *       +--------------+--------------+              +------------+----------+
     *       |              |              |              |            |          |
     *       |              |              |              |            |          |
     *  INT_BUCK1_2    INT_BUCK3_4    INT_BUCK5       INT_LDO1_2   INT_LDO3_4  INT_VMON
     *
     *
     *                                         For Hera
     *                                ==========================
     *
     *                                          INT_TOP
     *                                             |
     *                      +------------------------------------------+
     *                      |                                          |
     *                  INT_BUCK                                    INT_VMON
     *                      |
     *       +--------------+
     *       |              |
     *       |              |
     *  INT_BUCK1_2    INT_BUCK3_4
     */

  /* DD-ID:{289A36D1-AD79-4484-B5BB-F837104926A8}*/
    uint8_t     v_devIdx_u8;
    int32_t     v_pmicStatus_s32;
    uint8_t     v_intTopRegData_u8 = 0;
    uint8_t     v_intBuckRegData_u8 = 0;
    uint8_t     v_intLdoVmonRegData_u8 = 0;
    uint8_t     v_regData_u8 = 0;
    static bool v_first_call_b = true;

    /* If this is first call, configure voltmon step 2 configuration */
    if(v_first_call_b == true)
    {
        /* Configur PMIC voltmon 2nd step */
        Pmic_F_VoltmonConfigStep_v((uint8_t)D_PMIC_VOLTMON_CFG_STEP_2);

        /* (SM12 - Redundant Read-Back on Logic Output pins) */
        /* Bist status Check */
        Pmic_F_ReadBackConfigCheck_v();

        /* (SM14 - LBIST) */
        /* Check for LBIST_BOOT BIT */
        Pmic_F_Lbist_check();

        /* (SM22 - Notify Host on Previously Detected Errors) */
        /* Bist status Check */
        Pmic_F_BistStsCheck_v();

        /* (SM20 - Clock Monitoring on Internal Clock Signals (Need to call only once per driving cycle) */
        Pmic_F_ClockMon_v();   /* PMIC Internal clock monitoring call*/

        /* SM21 - Configuration Register Lock */
        /* Enable the Register lock at startup */
        /* IMP NOTE: This function should be called as last pmic configuration */
        Pmic_F_RegLockMon_v();

        /* Write flag to avoid above steps next time */
        v_first_call_b = false;
    }
    else
    {
        /* Nothing to do */
    }

    /* Iterate through all 3 pmic device */
    for(v_devIdx_u8 = 0; v_devIdx_u8 < (uint8_t)PMIC_DEV_NUM; v_devIdx_u8++)
    {
        /* If any feature monitoring reqired in sw for buck or ldo */
        if( (V_pmic_monitor_enable_as[v_devIdx_u8].is_buck_mon_enb_u8 != 0U) ||
            (V_pmic_monitor_enable_as[v_devIdx_u8].is_ldo_mon_enb_u8 != 0U) ||
            (V_pmic_monitor_enable_as[v_devIdx_u8].is_vcca_mon_enb_u8 != 0U))   /* For Hera */
        {
            /* Read INT_TOP register */
            v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                        (uint16_t)D_PMIC_TPS65941_INT_TOP, &v_intTopRegData_u8);

            /* If register read successful */
            if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
            {
                /* If any feature monitoring reqired in sw for buck */
                if(V_pmic_monitor_enable_as[v_devIdx_u8].is_buck_mon_enb_u8 != 0U)
                {
                    /* Check bit BUCK_INT to see if any UV/OV interrupt triggered for any of Buck */
                    if ((v_intTopRegData_u8 & (uint8_t)D_BUCK_INT_BIT_MASK) == (uint8_t)D_BUCK_INT_BIT_MASK)
                    {
                        /* Read INT_BUCK register */
                        v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK, &v_intBuckRegData_u8);

                        /* If register read successful */
                        if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
                        {
                            /* If volt, curr or RV monitor required in sw for buck 1 or 2 */
                            if((V_pmic_monitor_enable_as[v_devIdx_u8].buck_mon_as[D_BUCK_1_IDX].is_volt_mon_enable_u8 == (uint8_t)1) ||
                               (V_pmic_monitor_enable_as[v_devIdx_u8].buck_mon_as[D_BUCK_2_IDX].is_volt_mon_enable_u8 == (uint8_t)1) ||
                               (V_pmic_monitor_enable_as[v_devIdx_u8].buck_mon_as[D_BUCK_1_IDX].is_curr_mon_enable_u8 == (uint8_t)1) ||
                               (V_pmic_monitor_enable_as[v_devIdx_u8].buck_mon_as[D_BUCK_2_IDX].is_curr_mon_enable_u8 == (uint8_t)1) ||
                               (V_pmic_monitor_enable_as[v_devIdx_u8].buck_mon_as[D_BUCK_1_IDX].is_rv_mon_enable_u8 == (uint8_t)1) ||
                               (V_pmic_monitor_enable_as[v_devIdx_u8].buck_mon_as[D_BUCK_2_IDX].is_rv_mon_enable_u8 == (uint8_t)1))
                            {
                                /* Check bit BUCK1_2_INT to see if any UV/OV interrupt triggered for Buck 1 or 2 */
                                if ((v_intBuckRegData_u8 & (uint8_t)D_BUCK1_2_INT_BIT_MASK) == (uint8_t)D_BUCK1_2_INT_BIT_MASK)
                                {
                                    /* Read INT_BUCK1_2 register */
                                    v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                                            (uint16_t)D_PMIC_TPS65941_INT_BUCK1_2, &v_regData_u8);

                                    /* If register read successful */
                                    if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
                                    {
                                        /* Check respective bits in INT_BUCK1_2 to see if any error interrupt triggered */

                                        /* BUCK1 -> OV error in INT_BUCK1_2 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_1_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_BUCK1_OV_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK1_2);

                                        /* BUCK1 -> UV error in INT_BUCK1_2 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_1_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_BUCK1_UV_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK1_2);

                                        /* BUCK2 -> OV error in INT_BUCK1_2 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_2_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_BUCK2_OV_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK1_2);

                                        /* BUCK2 -> UV error in INT_BUCK1_2 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_2_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_BUCK2_UV_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK1_2);

                                        /* BUCK1 -> ILIM error in INT_BUCK1_2 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_1_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_CURR, v_regData_u8, (uint8_t)D_BUCK1_ILIM_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK1_2);

                                        /* BUCK2 -> ILIM error in INT_BUCK1_2 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_2_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_CURR, v_regData_u8, (uint8_t)D_BUCK2_ILIM_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK1_2);

                                        /* BUCK1 -> RV error in INT_BUCK1_2 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_1_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_RV, v_regData_u8, (uint8_t)D_BUCK1_SC_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK1_2);

                                        /* BUCK2 -> RV error in INT_BUCK1_2 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_2_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_RV, v_regData_u8, (uint8_t)D_BUCK2_SC_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK1_2);
                                    }
                                    else
                                    {
                                        /* Log Error */
                                        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV, (uint16_t)D_PMIC_ERR_VMON_INT_BUCK1_2_RD, v_devIdx_u8, 0);
                                    }
                                }
                                else
                                {
                                    /* Nothing to do */
                                }
                            } else {/* Do Nothing */}

                            /* If volt, curr or RV monitor required in sw for buck 3 or 4 */
                            if((V_pmic_monitor_enable_as[v_devIdx_u8].buck_mon_as[D_BUCK_3_IDX].is_volt_mon_enable_u8 == (uint8_t)1) ||
                               (V_pmic_monitor_enable_as[v_devIdx_u8].buck_mon_as[D_BUCK_4_IDX].is_volt_mon_enable_u8 == (uint8_t)1) ||
                               (V_pmic_monitor_enable_as[v_devIdx_u8].buck_mon_as[D_BUCK_3_IDX].is_curr_mon_enable_u8 == (uint8_t)1) ||
                               (V_pmic_monitor_enable_as[v_devIdx_u8].buck_mon_as[D_BUCK_4_IDX].is_curr_mon_enable_u8 == (uint8_t)1) ||
                               (V_pmic_monitor_enable_as[v_devIdx_u8].buck_mon_as[D_BUCK_3_IDX].is_rv_mon_enable_u8 == (uint8_t)1) ||
                               (V_pmic_monitor_enable_as[v_devIdx_u8].buck_mon_as[D_BUCK_4_IDX].is_rv_mon_enable_u8 == (uint8_t)1))
                            {
                                /* Check bit BUCK3_4_INT to see if any UV/OV interrupt triggered for Buck 3 or 4 */
                                if ((v_intBuckRegData_u8 & (uint8_t)D_BUCK3_4_INT_BIT_MASK) == (uint8_t)D_BUCK3_4_INT_BIT_MASK)
                                {
                                    /* Read INT_BUCK3_4 register */
                                    v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                                            (uint16_t)D_PMIC_TPS65941_INT_BUCK3_4, &v_regData_u8);

                                    /* If register read successful */
                                    if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
                                    {
                                        /* Check respective bits in INT_BUCK3_4 to see if any error interrupt triggered */

                                        /* BUCK3 -> OV error in INT_BUCK3_4 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_3_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_BUCK3_OV_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK3_4);

                                        /* BUCK3 -> UV error in INT_BUCK3_4 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_3_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_BUCK3_UV_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK3_4);

                                        /* BUCK4 -> OV error in INT_BUCK3_4 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_4_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_BUCK4_OV_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK3_4);

                                        /* BUCK4 -> UV error in INT_BUCK3_4 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_4_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_BUCK4_UV_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK3_4);

                                        /* BUCK3 -> ILIM error in INT_BUCK3_4 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_3_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_CURR, v_regData_u8, (uint8_t)D_BUCK3_ILIM_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK3_4);

                                        /* BUCK4 -> ILIM error in INT_BUCK3_4 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_4_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_CURR, v_regData_u8, (uint8_t)D_BUCK4_ILIM_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK3_4);

                                        /* BUCK3 -> RV error in INT_BUCK3_4 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_3_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_RV, v_regData_u8, (uint8_t)D_BUCK3_SC_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK3_4);

                                        /* BUCK4 -> RV error in INT_BUCK3_4 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_4_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_RV, v_regData_u8, (uint8_t)D_BUCK4_SC_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK3_4);
                                    }
                                    else
                                    {
                                        /* Log Error */
                                        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV, (uint16_t)D_PMIC_ERR_VMON_INT_BUCK3_4_RD, v_devIdx_u8, 0);
                                    }
                                }
                                else
                                {
                                    /* Nothing to do */
                                }
                            } else {/* Do Nothing */}

                            /* If not Hear device and volt, curr or RV monitor required in sw for buck 5 */
                            if ((v_devIdx_u8 != (uint8_t)PMIC_DEV_2) &&
                                ((V_pmic_monitor_enable_as[v_devIdx_u8].buck_mon_as[D_BUCK_5_IDX].is_volt_mon_enable_u8 == (uint8_t)1) ||
                                 (V_pmic_monitor_enable_as[v_devIdx_u8].buck_mon_as[D_BUCK_5_IDX].is_curr_mon_enable_u8 == (uint8_t)1) ||
                                 (V_pmic_monitor_enable_as[v_devIdx_u8].buck_mon_as[D_BUCK_5_IDX].is_rv_mon_enable_u8 == (uint8_t)1) ) )
                            {
                                /* Check bit BUCK5_INT to see if any UV/OV interrupt triggered for Buck 5 */
                                if ((v_intBuckRegData_u8 & (uint8_t)D_BUCK5_INT_BIT_MASK) == (uint8_t)D_BUCK5_INT_BIT_MASK)
                                {
                                    /* Read INT_BUCK5 register */
                                    v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                                            (uint16_t)D_PMIC_TPS65941_INT_BUCK5, &v_regData_u8);

                                    /* If register read successful */
                                    if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
                                    {
                                        /* Check respective bits in INT_BUCK5 to see if any error interrupt triggered */

                                        /* BUCK5 -> OV error in INT_BUCK5 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_5_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_BUCK5_OV_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK5);

                                        /* BUCK5 -> UV error in INT_BUCK5 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_5_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_BUCK5_UV_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK5);

                                        /* BUCK5 -> ILIM error in INT_BUCK5 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_5_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_CURR, v_regData_u8, (uint8_t)D_BUCK5_ILIM_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK5);

                                        /* BUCK5 -> RV error in INT_BUCK5 */
                                        Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_BUCK, (uint8_t)D_BUCK_5_IDX,
                                                                (uint8_t)D_PMIC_MON_TYPE_RV, v_regData_u8, (uint8_t)D_BUCK5_SC_INT_BIT_MASK,
                                                                (uint16_t)D_PMIC_TPS65941_INT_BUCK5);

                                    }
                                    else
                                    {
                                        /* Log Error */
                                        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV, (uint16_t)D_PMIC_ERR_VMON_INT_BUCK5_RD, v_devIdx_u8, 0);
                                    }
                                }
                                else
                                {
                                    /* Nothing to do */
                                }
                            } else {/* Do Nothing */}
                        }
                        else
                        {
                            /* Log Error */
                            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV, (uint16_t)D_PMIC_ERR_VMON_INT_BUCK_RD, v_devIdx_u8, 0);
                        }
                    }
                    else
                    {
                        /* Nothing to do */
                    }
                } else {/* Do Nothing */}

                /* If not Hera device */
                if (v_devIdx_u8 != (uint8_t)PMIC_DEV_2)
                {
                    /* If any feature monitoring reqired in sw for ldo */
                    if(V_pmic_monitor_enable_as[v_devIdx_u8].is_ldo_mon_enb_u8 != 0U)
                    {
                        /* Check bit LDO_VMON_INT to see if any UV/OV interrupt triggered for any of LDO */
                        if ((v_intTopRegData_u8 & (uint8_t)D_LDO_VMON_INT_BIT_MASK) == (uint8_t)D_LDO_VMON_INT_BIT_MASK)
                        {
                            /* Read INT_LDO_VMON register */
                            v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO_VMON, &v_intLdoVmonRegData_u8);

                            /* If register read successful */
                            if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
                            {
                                /* If volt, curr or RV monitor required in sw for LDO 1 or 2 */
                                if((V_pmic_monitor_enable_as[v_devIdx_u8].ldo_mon_as[D_LDO_1_IDX].is_volt_mon_enable_u8 == (uint8_t)1) ||
                                   (V_pmic_monitor_enable_as[v_devIdx_u8].ldo_mon_as[D_LDO_2_IDX].is_volt_mon_enable_u8 == (uint8_t)1) ||
                                   (V_pmic_monitor_enable_as[v_devIdx_u8].ldo_mon_as[D_LDO_1_IDX].is_curr_mon_enable_u8 == (uint8_t)1) ||
                                   (V_pmic_monitor_enable_as[v_devIdx_u8].ldo_mon_as[D_LDO_2_IDX].is_curr_mon_enable_u8 == (uint8_t)1) ||
                                   (V_pmic_monitor_enable_as[v_devIdx_u8].ldo_mon_as[D_LDO_1_IDX].is_rv_mon_enable_u8 == (uint8_t)1) ||
                                   (V_pmic_monitor_enable_as[v_devIdx_u8].ldo_mon_as[D_LDO_2_IDX].is_rv_mon_enable_u8 == (uint8_t)1))
                                {
                                    /* Check bit LDO1_2_INT to see if any UV/OV interrupt triggered for LDO 1 or 2 */
                                    if ((v_intLdoVmonRegData_u8 & (uint8_t)D_LDO1_2_INT_BIT_MASK) == (uint8_t)D_LDO1_2_INT_BIT_MASK)
                                    {
                                        /* Read INT_LDO1_2 register */
                                        v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                                                (uint16_t)D_PMIC_TPS65941_INT_LDO1_2, &v_regData_u8);

                                        /* If register read successful */
                                        if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
                                        {
                                            /* Check respective bits in INT_LDO1_2 to see if any error interrupt triggered */

                                            /* LDO1 -> OV error in INT_LDO1_2 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_1_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_LDO1_OV_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO1_2);

                                            /* LDO1 -> UV error in INT_LDO1_2 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_1_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_LDO1_UV_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO1_2);

                                            /* LDO2 -> OV error in INT_LDO1_2 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_2_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_LDO2_OV_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO1_2);

                                            /* LDO2 -> UV error in INT_LDO1_2 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_2_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_LDO2_UV_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO1_2);

                                            /* LDO1 -> ILIM error in INT_LDO1_2 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_1_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_CURR, v_regData_u8, (uint8_t)D_LDO1_ILIM_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO1_2);

                                            /* LDO2 -> ILIM error in INT_LDO1_2 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_2_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_CURR, v_regData_u8, (uint8_t)D_LDO2_ILIM_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO1_2);

                                            /* LDO1 -> RV error in INT_LDO1_2 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_1_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_RV, v_regData_u8, (uint8_t)D_LDO1_SC_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO1_2);

                                            /* LDO2 -> RV error in INT_LDO1_2 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_2_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_RV, v_regData_u8, (uint8_t)D_LDO2_SC_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO1_2);
                                        }
                                        else
                                        {
                                            /* Log Error */
                                            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV, (uint16_t)D_PMIC_ERR_VMON_INT_LDO1_2_RD, v_devIdx_u8, 0);
                                        }
                                    }
                                    else
                                    {
                                        /* Nothing to do */
                                    }
                                } else {/* Do Nothing */}

                                /* If volt, curr or RV monitor required in sw for LDO 3 or 4 */
                                if((V_pmic_monitor_enable_as[v_devIdx_u8].ldo_mon_as[D_LDO_3_IDX].is_volt_mon_enable_u8 == (uint8_t)1) ||
                                   (V_pmic_monitor_enable_as[v_devIdx_u8].ldo_mon_as[D_LDO_4_IDX].is_volt_mon_enable_u8 == (uint8_t)1) ||
                                   (V_pmic_monitor_enable_as[v_devIdx_u8].ldo_mon_as[D_LDO_3_IDX].is_curr_mon_enable_u8 == (uint8_t)1) ||
                                   (V_pmic_monitor_enable_as[v_devIdx_u8].ldo_mon_as[D_LDO_4_IDX].is_curr_mon_enable_u8 == (uint8_t)1) ||
                                   (V_pmic_monitor_enable_as[v_devIdx_u8].ldo_mon_as[D_LDO_3_IDX].is_rv_mon_enable_u8 == (uint8_t)1) ||
                                   (V_pmic_monitor_enable_as[v_devIdx_u8].ldo_mon_as[D_LDO_4_IDX].is_rv_mon_enable_u8 == (uint8_t)1))
                                {
                                    /* Check bit LDO3_4_INT to see if any UV/OV interrupt triggered for LDO 3 or 4 */
                                    if ((v_intLdoVmonRegData_u8 & (uint8_t)D_LDO3_4_INT_BIT_MASK) == (uint8_t)D_LDO3_4_INT_BIT_MASK)
                                    {
                                        /* Read INT_LDO3_4 register */
                                        v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                                                (uint16_t)D_PMIC_TPS65941_INT_LDO3_4, &v_regData_u8);

                                        if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
                                        {
                                             /* Check respective bits in INT_LDO3_4 to see if any error interrupt triggered */

                                            /* LDO3 -> OV error in INT_LDO3_4 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_3_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_LDO3_OV_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO3_4);

                                            /* LDO3 -> UV error in INT_LDO3_4 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_3_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_LDO3_UV_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO3_4);

                                            /* LDO4 -> OV error in INT_LDO3_4 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_4_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_LDO4_OV_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO3_4);

                                            /* LDO4 -> UV error in INT_LDO3_4 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_4_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_VOLT, v_regData_u8, (uint8_t)D_LDO4_UV_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO3_4);

                                            /* LDO3 -> ILIM error in INT_LDO3_4 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_3_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_CURR, v_regData_u8, (uint8_t)D_LDO3_ILIM_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO3_4);

                                            /* LDO4 -> ILIM error in INT_LDO3_4 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_4_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_CURR, v_regData_u8, (uint8_t)D_LDO4_ILIM_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO3_4);

                                            /* LDO3 -> RV error in INT_LDO3_4 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_3_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_RV, v_regData_u8, (uint8_t)D_LDO3_SC_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO3_4);

                                            /* LDO4 -> RV error in INT_LDO3_4 */
                                            Pmic_f_checkErrStsBit_v(v_devIdx_u8, (uint8_t)D_PMIC_REGULATOR_TYPE_LDO, (uint8_t)D_LDO_4_IDX,
                                                                    (uint8_t)D_PMIC_MON_TYPE_RV, v_regData_u8, (uint8_t)D_LDO4_SC_INT_BIT_MASK,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_LDO3_4);
                                        }
                                        else
                                        {
                                            /* Log Error */
                                            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV, (uint16_t)D_PMIC_ERR_VMON_INT_LDO3_4_RD, v_devIdx_u8, 0);
                                        }
                                    }
                                    else
                                    {
                                        /* Nothing to do */
                                    }
                                } else {/* Do Nothing */}

                                /* If VCCA monitor required in sw */
                                if(V_pmic_monitor_enable_as[v_devIdx_u8].is_vcca_mon_enb_u8 == (uint8_t)1)
                                {
                                    /* Check bit D_PMIC_TPS65941_INT_VMON to see if any UV/OV interrupt triggered for VCCA */
                                    if ((v_intLdoVmonRegData_u8 & (uint8_t)D_VCCA_INT_BIT_MASK) == (uint8_t)D_VCCA_INT_BIT_MASK)
                                    {
                                        /* Read D_PMIC_TPS65941_INT_VMON register */
                                        v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                                                (uint16_t)D_PMIC_TPS65941_INT_VMON, &v_regData_u8);

                                        /* If register read successful */
                                        if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
                                        {
                                            /* Check respective bits in D_PMIC_TPS65941_INT_VMON to see if any error interrupt triggered */

                                            /* VCCA -> OV/UV error in INT_VMON */
                                            Pmic_f_checkVccaErr_v(v_devIdx_u8, v_regData_u8, (uint16_t)D_PMIC_TPS65941_INT_VMON);
                                        }
                                        else
                                        {
                                            /* Log Error */
                                            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV, (uint16_t)D_PMIC_ERR_VMON_INT_VMON_RD, v_devIdx_u8, 0);
                                        }
                                    } else {/* Do Nothing */}
                                } else {/* Do Nothing */}
                            }
                            else
                            {
                                /* Log Error */
                                Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV, (uint16_t)D_PMIC_ERR_VMON_INT_LDO_VMON_RD, v_devIdx_u8, 0);
                            }
                        }
                        else
                        {
                            /* Nothing to do */
                        }
                    } else {/* Do Nothing */}
                }
                else
                {
                    /* For Hera */
                    /* If VCCA monitor required in sw */
                    if(V_pmic_monitor_enable_as[v_devIdx_u8].is_vcca_mon_enb_u8 == (uint8_t)1)
                    {
                        /* Check bit VMON_INT to see if UV/OV interrupt triggered for VCCA */
                        if ((v_intTopRegData_u8 & (uint8_t)D_VMON_INT_BIT_MASK) == (uint8_t)D_VMON_INT_BIT_MASK)
                        {
                            /* Read INT_LDO_VMON register */
                            v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                                    (uint16_t)D_PMIC_TPS65941_INT_VMON, &v_regData_u8);
                            /* If register read successful */
                            if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
                            {
                                /* Check respective bits in D_PMIC_TPS65941_INT_VMON to see if any error interrupt triggered */

                                /* VCCA -> OV/UV error in INT_VMON */
                                Pmic_f_checkVccaErr_v(v_devIdx_u8, v_regData_u8, (uint16_t)D_PMIC_TPS65941_INT_VMON);
                            }
                            else
                            {
                                /* Log Error */
                                Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV, (uint16_t)D_PMIC_ERR_VMON_INT_VMON_RD, v_devIdx_u8, 0);
                            }
                        } else {/* Do Nothing */}
                    } else {/* Do Nothing */}

                }
            }
            else
            {
                /* Log Error */
                Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV, (uint16_t)D_PMIC_ERR_VMON_INT_TOP_RD, v_devIdx_u8, 0);
            }
        } else {/* Do Nothing */}
    }

    /* Clear ILIM counter based on current ILIM error status */
    Pmic_f_ClearCurrErrCntr_v();
}
