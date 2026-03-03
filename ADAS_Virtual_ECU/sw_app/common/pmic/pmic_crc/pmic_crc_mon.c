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
 */

/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include "pmic_cfg.h"
#include "tps65941_Reg.h"
#include <ti/drv/pmic/src/pmic_irq_priv.h>
#include "pmic_error.h"
#include "ErrorManagerSatellite.h"
#include "app_log_Boot.h"
#include "pmic_crc_mon.h"
extern void f_Send_Dbg_SDLFault_CanTx(uint16 SDLFault);
/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
/* PMIC register field bit mask */
#define D_PMIC_ERR_DATA_LEN           (0x04)  /* Error buffer length to report to error manager */
/************ Error Capturing to report to error manager **************/

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
void Pmic_F_CRC_Mon_v(void)
{
    /* DD-ID:{D8E20437-AE85-433d-A31E-66C5001EB1A0}*/
    /* Error enum to report to error manager */
    static ldef_ErrorMgr_enErrorNo v_errNum_ae[PMIC_DEV_NUM] =
    {
        ldef_ErrorMgr_Error_SysIntFlt_MCU_SM17_CRC_Error_I2C1_Channel,
        ldef_ErrorMgr_Error_SysIntFlt_MCU_SM17_CRC_Error_I2C1_Channel_Slave,
    #if (D_FEATURE_HERA_ENABLE == 1)
        ldef_ErrorMgr_Error_SysIntFlt_MCU_SM17_CRC_Error_I2C1_Channel_HERA
    #endif
    };

    uint8_t  v_devIdx_u8 = 0;
    uint8_t  v_errData_u8[D_PMIC_ERR_DATA_LEN] = {0u};  /* Buffer to collect and report error to error manager */

    static int32_t v_crcRead_err_as32[PMIC_DEV_NUM] = {0};
    static int32_t v_crcWrite_err_as32[PMIC_DEV_NUM] = {0};

    /* Iterate through all 3 pmic device */
    for(v_devIdx_u8 = 0u; v_devIdx_u8 < (uint8_t)PMIC_DEV_NUM; v_devIdx_u8++)
    {
        V_pmic_err_s.crc_error_s.v_crcRead_err_as32[v_devIdx_u8] = Pmic_Read_CRCError(&pmic_device[v_devIdx_u8].pmicCoreHandle);
        V_pmic_err_s.crc_error_s.v_crcWrite_err_as32[v_devIdx_u8] = Pmic_Write_CRCError(&pmic_device[v_devIdx_u8].pmicCoreHandle);

        if(((V_pmic_err_s.crc_error_s.v_crcRead_err_as32[v_devIdx_u8] > 0 ) &&
            (v_crcRead_err_as32[v_devIdx_u8] != V_pmic_err_s.crc_error_s.v_crcRead_err_as32[v_devIdx_u8])) ||
           ((V_pmic_err_s.crc_error_s.v_crcWrite_err_as32[v_devIdx_u8] > 0) &&
            (v_crcWrite_err_as32[v_devIdx_u8] != V_pmic_err_s.crc_error_s.v_crcWrite_err_as32[v_devIdx_u8])))
        {
            v_errData_u8[0] = (uint8_t)V_pmic_err_s.crc_error_s.v_crcRead_err_as32[v_devIdx_u8];
            v_errData_u8[1] = (uint8_t)V_pmic_err_s.crc_error_s.v_crcWrite_err_as32[v_devIdx_u8];

            (void)ErrorMgrSatellite_ReportErrorStatus(v_errNum_ae[v_devIdx_u8], ldef_ErrorMgr_ErrorActive, (const ldef_ErrorMgr_stAddData *)v_errData_u8);

             /* Report error to CAN msg */
            f_Send_Dbg_SDLFault_CanTx((uint16)v_errNum_ae[v_devIdx_u8]);

            /* Go to SafeState2 */
            #ifdef PMIC_PRINT_ENABLE
            APP_log(APP_LOG_ERR,"[%s] CRC Error read: %d Write: %d \n", pmic_device[v_devIdx_u8].name, V_pmic_err_s.crc_error_s.v_crcRead_err_as32[v_devIdx_u8],
                V_pmic_err_s.crc_error_s.v_crcWrite_err_as32[v_devIdx_u8]);
            #endif
        } else {/* Do Nothing */}
        v_crcRead_err_as32[v_devIdx_u8] = V_pmic_err_s.crc_error_s.v_crcRead_err_as32[v_devIdx_u8];
        v_crcWrite_err_as32[v_devIdx_u8] = V_pmic_err_s.crc_error_s.v_crcWrite_err_as32[v_devIdx_u8];
    }

}
