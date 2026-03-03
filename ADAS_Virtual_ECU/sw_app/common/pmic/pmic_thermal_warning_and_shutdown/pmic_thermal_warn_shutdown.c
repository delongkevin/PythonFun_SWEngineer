/**
 * @file pmic_thermal_warn_shutdown.c
 * @brief PMIC Thermal and Warning Shutdown monitoring
 *
 * @details This file provides interface to monitor PMIC thermal warning and shutdown threshold temperature
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
 * @author Varun Kwatra (Varun.Kwatra@magna.com)
 */

/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include "pmic_cfg.h"
#include "tps65941_Reg.h"
#include "pmic_thermal_warn_shutdown.h"
#include <ti/drv/pmic/src/pmic_io_priv.h>
#include "pmic_error.h"
#include "ErrorManagerSatellite.h"
extern void f_Send_Dbg_SDLFault_CanTx(uint16 SDLFault);
/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
/* PMIC register field bit mask */
#define D_PMIC_REG_BITMASK_TWARN_INT   (0x08)

/************ Error Capturing to report to error manager **************/
#define D_PMIC_TWARN_ERR_DEV_IDX            (0x00)  /* PMIC Decice index (0: Master, 1: Slave, 2: Hera) */
#define D_PMIC_TWARN_ERR_REG_ADDR_HI_IDX    (0x01)  /* Register address High byte */
#define D_PMIC_TWARN_ERR_REG_ADDR_LO_IDX    (0x02)  /* Register address Low byte */
#define D_PMIC_TWARN_ERR_REG_VAL_IDX        (0x03)  /* Register value */
#define D_PMIC_TWARN_ERR_DATA_LEN           (0x04)  /* Error buffer length to report to error manager */

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
/*
 * Purpose: Read PMIC registers for thermal warning/shutdown monitoring
 * Description: Read PMIC registers for thermal warning/shutdown monitoring and
 *              report error to error manager in case of thermal warning interrupt triggered.
 * Return Type: void
 */
void Pmic_F_TwarnMon_v(void)
{
    /* DD-ID:{8217BFBA-B940-4b8e-B4A1-02C0861EB54B}*/
    /* Error enum to report to error manager */
    static ldef_ErrorMgr_enErrorNo v_errNum_ae[PMIC_DEV_NUM] =
    {
        ldef_ErrorMgr_Error_SysIntFlt_MCU_SM8_Thermal_prewarning_Interrupt,
        ldef_ErrorMgr_Error_SysIntFlt_MCU_SM8_Thermal_prewarning_Interrupt_Slave,
    #if (D_FEATURE_HERA_ENABLE == 1)
        ldef_ErrorMgr_Error_SysIntFlt_MCU_SM8_Thermal_prewarning_Interrupt_HERA
    #endif
    };

    uint8_t  v_devIdx_u8 = 0;
    uint8_t  v_regData_u8 = 0;
    int32_t  v_pmicStatus_s32 = (int32_t)PMIC_ST_SUCCESS;
    uint8_t  v_errData_u8[D_PMIC_TWARN_ERR_DATA_LEN] = {0};  /* Buffer to collect and report error to error manager */

    /* Iterate through all 3 pmic device */
    for(v_devIdx_u8 = 0; v_devIdx_u8 < (uint8_t)PMIC_DEV_NUM; v_devIdx_u8++)
    {
         /* Read INT_MISC register */
        v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                            D_PMIC_TPS65941_INT_MISC, &v_regData_u8);

        if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
        {
            /* If Thermal warning interrupt set -> Report error to error manager to perform Safe state 1 and reset*/
            if ((v_regData_u8 & (uint8_t)D_PMIC_REG_BITMASK_TWARN_INT) == (uint8_t)D_PMIC_REG_BITMASK_TWARN_INT)
            {
                /* Prepare error info to report to error manager */
                v_errData_u8[D_PMIC_TWARN_ERR_DEV_IDX] = v_devIdx_u8;                                      /* PMIC Device index */
                v_errData_u8[D_PMIC_TWARN_ERR_REG_ADDR_LO_IDX] = (uint8_t)(D_PMIC_TPS65941_INT_MISC & PMIC_MASK_LOWER_BYTE);        /* Reg addr Lower byte */
                v_errData_u8[D_PMIC_TWARN_ERR_REG_VAL_IDX] = v_regData_u8;                                  /* Reg value */

                /* 2. Report error to error manager to Perform Safe state 2 */
                (void)ErrorMgrSatellite_ReportErrorStatus(v_errNum_ae[v_devIdx_u8], ldef_ErrorMgr_ErrorActive, (const ldef_ErrorMgr_stAddData *)v_errData_u8);

                 /* Report error to CAN msg */
                f_Send_Dbg_SDLFault_CanTx((uint16)v_errNum_ae[v_devIdx_u8]);
            }
            else
            {
                /*Do Nothing*/
            }
        }
        else
        {
            /* Log error */
            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TWARN, (uint16_t)D_PMIC_ERR_TWARN_INT_MISC_RD, v_devIdx_u8, (uint8_t)FALSE);
        }
    }
}
