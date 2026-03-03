/**
 * @file pmic_clock_mon.c
 * @brief PMIC Clock Monitoring on Internal Clock Signals
 *
 * @details This file provides interface to monitor PMIC Internal clock signal monitoring
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
#include "pmic_clock_mon.h"
#include <ti/drv/pmic/src/pmic_io_priv.h>
#include "pmic_error.h"
#include "app_log_Boot.h"

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
/* PMIC register field bit mask */
#define D_PMIC_REG_BITMASK_CLKMON_EN   (0x08)

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
 * Purpose: Read data from PMIC registers for Clock monitoring .
 * Description: Read data from PMIC registers for clock signal monitoring.
 * Return Type: int32_t (Read success or failure)
 */
void Pmic_F_ClockMon_v(void)
{
    /* DD-ID:{47F00600-E041-41b5-95EB-B46B490AB509}*/
    /* Note: By default in NVM setting for Bit CLKMON_EN is 1 for Master, Slave and Hera */

    /*Variables to read the data*/
    uint8_t  v_devIdx_u8;
    int32_t  v_pmicStatus_s32;
    uint8_t  v_regData_u8;

    /* Iterate through all 3 pmic device */
    for(v_devIdx_u8 = 0; v_devIdx_u8 < (uint8_t)PMIC_DEV_NUM; v_devIdx_u8++)
    {
        /* Read MISC_CTRL register */
        v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle, (uint16_t)D_PMIC_TPS65941_MISC_CTRL, &v_regData_u8);

        if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
        {
            /* If CLKMON_EN != 0 -> clear it */
            if ((v_regData_u8 & (uint8_t)D_PMIC_REG_BITMASK_CLKMON_EN) == (uint8_t)D_PMIC_REG_BITMASK_CLKMON_EN)
            {
                #ifdef PMIC_PRINT_ENABLE
                APP_log(APP_LOG_ERR,"PMIC = %d, CLKMON_EN = 0 (Enabled)\n", v_devIdx_u8);
                #endif
                if(v_devIdx_u8 != (uint8_t)PMIC_DEV_2)
                {
                    /* Set bit CLKMON_EN in variable */
                    v_regData_u8 &= ~(uint8_t)D_PMIC_REG_BITMASK_CLKMON_EN;
                }
                else
                {
                    /* Set bit CLKMON_EN in variable */
                    v_regData_u8 |= (uint8_t)D_PMIC_REG_BITMASK_CLKMON_EN;
                }

                /* Write MISC_CTRL register */
                v_pmicStatus_s32 = Pmic_commIntf_sendByte(&pmic_device[v_devIdx_u8].pmicCoreHandle, (uint16_t)D_PMIC_TPS65941_MISC_CTRL, v_regData_u8);
                #ifdef PMIC_PRINT_ENABLE
                APP_log(APP_LOG_ERR,"PMIC = %d, CLKMON_EN changed to %d \n", v_devIdx_u8, v_regData_u8);
                #endif
                
                if(v_pmicStatus_s32 != (int32_t)PMIC_ST_SUCCESS)
                {
                    /* Log error */
                    Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_CLOCKMON_EN, (uint16_t)D_PMIC_ERR_CLKMON_MISC_CTR_WR, v_devIdx_u8, (uint8_t)FALSE);
                } else {/* Do Nothing */}
            } else {/* Do Nothing */}
        }
        else
        {
            /* Log error */
            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_CLOCKMON_EN, (uint16_t)D_PMIC_ERR_CLKMON_MISC_CTR_RD, v_devIdx_u8, (uint8_t)FALSE);
        }
    }
}

