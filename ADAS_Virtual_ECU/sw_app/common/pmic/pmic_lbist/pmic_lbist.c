/**
 * @file pmic_lbist.c
 * @brief PMIC LBIST
 *
 * @details This file provides interface to monitor PMIC FAST_BIST Boot
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
 * @author Shekhar Chettri (shekhar.chettri@magna.com)
 */
 
/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include "pmic_cfg.h"
#include "tps65941_Reg.h"
#include "pmic_lbist.h"
#include <ti/drv/pmic/src/pmic_io_priv.h>
#include "pmic_error.h"
#include "app_log_Boot.h"

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
#define D_PMIC_REG_BITMASK_FAST_BIST   (0x10)

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
 * Purpose: Check FAST_BIST bit to make sure lbist is enabled.
 * Description: Check FAST_BIST bit to make sure lbist is enabled and not modified during startup.
 * Return Type: void
 */
 void Pmic_F_Lbist_check(void)
{
    /* DD-ID:{4D9647FE-319F-446a-B638-C36D02A969F5}*/
    uint8_t  v_devIdx_u8;
    uint8_t  v_regData_u8;
    int32_t  v_pmicStatus_s32;


    /* Iterate through all 3 pmic devices */
    for(v_devIdx_u8 = 0; v_devIdx_u8 < (uint8_t)PMIC_DEV_NUM; v_devIdx_u8++)
    {
        /* Read RTC_CTRL_2 Register  */
        v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[v_devIdx_u8].pmicCoreHandle,
                                            D_PMIC_TPS65941_RTC_CTRL_2, &v_regData_u8);

        if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
        {
            if ((v_regData_u8 & (uint8_t)D_PMIC_REG_BITMASK_FAST_BIST) == (uint8_t)D_PMIC_REG_BITMASK_FAST_BIST)
            {
                /* Print error msg to UART */
                #ifdef PMIC_PRINT_ENABLE
                APP_log(APP_LOG_ERR,"PMIC %d: LBIST err, bit FAST_BIST = %d\n", v_devIdx_u8, D_PMIC_REG_BITMASK_FAST_BIST);
                #endif
            }
            else
            {
                /*Do Nothing*/
            }
        }
        else
        {
            /* Log error */
            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_LBIST, (uint16_t)D_PMIC_ERR_LBIST_RTC_CTRL_2_RD, v_devIdx_u8, 0);
        }
     }
}


