/**
 * @file pmic_bist_sts.c
 * @brief PMIC bist status check after powerup
 *
 * @details This file contain the implementation of PMIC bist status check after powerup
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
#include "pmic_cfg.h"
#include "tps65941_Reg.h"
#include "pmic_error.h"
#include <ti/drv/pmic/src/pmic_io_priv.h>
#include "app_log_Boot.h"
#include "ErrorManagerSatellite.h"
#include "pmic_bist_sts.h"
extern void f_Send_Dbg_SDLFault_CanTx(uint16 SDLFault);
/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
/* PMIC register field bit mask */
#define D_PMIC_REG_BIST_PASS_INT_BITMASK   (0x01) /* BIST_PASS_INT bit position in INT_MISC register */
#define D_PMIC_REG_BIST_FAIL_INT_BITMASK   (0x02) /* BIST_FAIL_INT bit position in INT_MODERATE_ERR register */

/************ Error Capturing to report to error manager **************/
#define D_PMIC_BIST_ERR_DEV_IDX            (0x00)  /* PMIC Decice index (0: Master, 1: Slave, 2: Hera) */
#define D_PMIC_BIST_ERR_REG_ADDR_LO_IDX    (0x02)  /* Register address Low byte */
#define D_PMIC_BIST_ERR_REG_VAL_IDX        (0x03)  /* Register value */
#define D_PMIC_BIST_ERR_DATA_LEN           (0x04)  /* Error buffer length to report to error manager */

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


/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */


/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*
 * Purpose: Check the status of BIST after powerup.
 * Description: Check the status of BIST after powerup.
 * Return Type: void
 */
void Pmic_F_BistStsCheck_v(void)
{
    /* DD-ID:{2B458D28-1395-4f74-927E-A8FF30FD1576}*/
    /* Note: NVM default value of Interrupt mask
     * For PMIC Master, Slave and Hera
     * MASK_MISC -> Bit 0 -> BIST_PASS_MASK -> 0 (Interrupt generated)
     * MASK_MODERATE_ERR -> Bit 1 -> BIST_FAIL_MASK -> 0 (Interrupt generated)
     */
    /* Error enum to report to error manager */
    static ldef_ErrorMgr_enErrorNo v_errNum_ae[PMIC_DEV_NUM] =
    {
        ldef_ErrorMgr_Error_SysIntFlt_MCU_SM22_Notify_Host_Previously_Detected_Errors,
        ldef_ErrorMgr_Error_SysIntFlt_MCU_SM22_Notify_Host_Previously_Detected_Errors_Slave,
    #if (D_FEATURE_HERA_ENABLE == 1)
        ldef_ErrorMgr_Error_SysIntFlt_MCU_SM22_Notify_Host_Previously_Detected_Errors_HERA
    #endif
    };

    int32_t  v_pmicStatus_s32;
    uint8_t  v_regData_u8;
    uint8_t  v_devIdx_u8;
    uint8_t  v_errData_u8[D_PMIC_BIST_ERR_DATA_LEN] = {0};  /* Buffer to collect and report error to error manager */

    /* Iterate through all 3 pmic device */
    for(v_devIdx_u8 = 0; v_devIdx_u8 < (uint8_t)PMIC_DEV_NUM; v_devIdx_u8++)
    {
        /* Read pmic register INT_MISC */
        v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                    D_PMIC_TPS65941_INT_MISC, &v_regData_u8);
        if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
        {
            /* If bit BIST_PASS_INT set -> BIST completed */
            if ((v_regData_u8 & (uint8_t)D_PMIC_REG_BIST_PASS_INT_BITMASK) == (uint8_t)D_PMIC_REG_BIST_PASS_INT_BITMASK)
            {
                /* Read pmic register INT_MODERATE_ERR */
                v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                                            D_PMIC_TPS65941_INT_MODERATE_ERR, &v_regData_u8);
                if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
                {
                    /* If bit BIST_FAIL_INT set -> Error occured during BIST */
                    if ((v_regData_u8 & (uint8_t)D_PMIC_REG_BIST_FAIL_INT_BITMASK) == (uint8_t)D_PMIC_REG_BIST_FAIL_INT_BITMASK)
                    {
                        /* Prepare error info to report to error manager */
                        v_errData_u8[D_PMIC_BIST_ERR_DEV_IDX] = v_devIdx_u8;                                      /* PMIC Device index */
                        v_errData_u8[D_PMIC_BIST_ERR_REG_ADDR_LO_IDX] = (uint8_t)(D_PMIC_TPS65941_INT_MODERATE_ERR & PMIC_MASK_LOWER_BYTE);        /* Reg addr Lower byte */
                        v_errData_u8[D_PMIC_BIST_ERR_REG_VAL_IDX] = v_regData_u8;                                  /* Register value */

                        /* Report error to error manager to Perform Safe state 5 */
                        (void)ErrorMgrSatellite_ReportErrorStatus(v_errNum_ae[v_devIdx_u8], ldef_ErrorMgr_ErrorActive, (const ldef_ErrorMgr_stAddData *)v_errData_u8);

                           /* Report error to CAN msg */
                            f_Send_Dbg_SDLFault_CanTx((uint16)v_errNum_ae[v_devIdx_u8]);
                        Pmic_F_SafeState2_v(SAFESTATE_REASON_PMIC_BIST_FAIL); /* To insure MCU not run and restart once Fault detected */
                    }
                    else
                    {
                        /* Nothing to do */
                    }
                }
                else
                {
                    /* Log error */
                    Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_BIST_STS_CHECK, (uint16_t)D_PMIC_ERR_BIST_STS_INT_MODERATE_RD, v_devIdx_u8, 0);
                }
            }
            else
            {
                /* Print error msg to UART */
                #ifdef PMIC_PRINT_ENABLE
                APP_log(APP_LOG_ERR,"PMIC %d: BIST is not completed\n", v_devIdx_u8);
                #endif
            }
        }
        else
        {
            /* Log error */
            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_BIST_STS_CHECK, (uint16_t)D_PMIC_ERR_BIST_STS_INT_MISC_RD, v_devIdx_u8, 0);
        }
    }
}
