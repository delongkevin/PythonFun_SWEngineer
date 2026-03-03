/**
 * @file pmic_mcu_esm.c
 * @brief PMIC ESM
 *
 * @details This file provides Error Signal monitoring and handling of MCU
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
#include "pmic_mcu_esm.h"
#include <ti/drv/pmic/src/pmic_io_priv.h>
#include "pmic_error.h"
/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
#define D_PMIC_REG_BITMASK_START_BIT  (0x01U)
#define D_PMIC_REG_BITMASK_ENABLE_ESM (0x60U)  /*ESM_MCU_EN = 1, ESM_MCU_EN_DRV = 1 */

#define D_PMIC_ESM_DELAY_1            (0x16U)  /*Configuration of Delay_1 register = 22 x 2.048 x 1.05 = 47.308 ms*/
#define D_PMIC_ESM_DELAY_2            (0x16U)  /*Configuration of Delay_2 register = 22 x 2.048 x 1.05 = 47.308 ms*/

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
 * Purpose: PMIC MCU ESM configuration Task.
 * Description:  PMIC MCU ESM  configure  and enable ESM for PMIC Master at Startup
 * Return Type: void
 */
void Pmic_M_ESM_config(void)
{
    /* DD-ID:{D7A55098-5760-4098-9B11-4AA80A63203F}*/
    int32_t  v_pmicStatus_s32 = (int32_t)PMIC_ST_SUCCESS;
    uint8_t  v_regData_u8 = 0;

    /*Read ESM_MCU_START  Register */
    v_pmicStatus_s32 = Pmic_commIntf_recvByte(&pmic_device[PMIC_DEV_0].pmicCoreHandle,
                                                (uint16_t)D_PMIC_TPS65941_ESM_MCU_START_REG, &v_regData_u8);

    if(v_pmicStatus_s32 == (int32_t)PMIC_ST_SUCCESS)
    {
        if ((v_regData_u8 & (uint8_t)D_PMIC_REG_BITMASK_START_BIT) == (uint8_t)D_PMIC_REG_BITMASK_START_BIT)
        {
            v_regData_u8 &= (~D_PMIC_REG_BITMASK_START_BIT);
            /*Clear ESM_MCU_START Bit */
            v_pmicStatus_s32 = Pmic_commIntf_sendByte(&pmic_device[PMIC_DEV_0].pmicCoreHandle, (uint16_t)D_PMIC_TPS65941_ESM_MCU_START_REG, v_regData_u8);

            if(v_pmicStatus_s32 != (int32_t)PMIC_ST_SUCCESS)
            {
                /* Log error */
                Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_MCU_ESM, (uint16_t)D_PMIC_ERR_MCU_ESM_ESM_MCU_START_REG_WR, (uint8_t)PMIC_DEV_0, 0U);
            } else {/* Do Nothing */}
        } else {/* Do Nothing */}
          
        /*Configure the ESM_MCU_DELAY1_REG at Start up*/
        v_pmicStatus_s32 =  Pmic_commIntf_sendByte(&pmic_device[PMIC_DEV_0].pmicCoreHandle, (uint16_t)D_PMIC_TPS65941_ESM_MCU_DELAY1_REG, (uint8_t)D_PMIC_ESM_DELAY_1 );

        /* Check if PMIC DELAY1 Write is success else return Error*/
        if(v_pmicStatus_s32 != (int32_t)PMIC_ST_SUCCESS)
        {
            /* Log error */
            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_MCU_ESM, (uint16_t)D_PMIC_ERR_MCU_ESM_ESM_MCU_DELAY1_REG_WR, (uint8_t)PMIC_DEV_0, 0U);
        } else {/* Do Nothing */}

        /*Configure the ESM_MCU_DELAY2_REG at Start up*/
        v_pmicStatus_s32 =  Pmic_commIntf_sendByte(&pmic_device[PMIC_DEV_0].pmicCoreHandle, (uint16_t)D_PMIC_TPS65941_ESM_MCU_DELAY2_REG, (uint8_t)D_PMIC_ESM_DELAY_2);

        /* Check if PMIC DELAY2 Write is success else return Error*/
        if(v_pmicStatus_s32 != (int32_t)PMIC_ST_SUCCESS)
        {
            /* Log error */
            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_MCU_ESM, (uint16_t)D_PMIC_ERR_MCU_ESM_ESM_MCU_DELAY2_REG_WR, (uint8_t)PMIC_DEV_0, 0U);
        } else {/* Do Nothing */}

        /*Enable  ESM_MCU_MODE_CFG Register for Error Signal Monitoring*/
        v_pmicStatus_s32 = Pmic_commIntf_sendByte(&pmic_device[PMIC_DEV_0].pmicCoreHandle, (uint16_t)D_PMIC_TPS65941_ESM_MCU_MODE_CFG, (uint8_t)D_PMIC_REG_BITMASK_ENABLE_ESM);
        /* Check if PMIC ESM_MCU_START Write is success else return Error*/
        if(v_pmicStatus_s32 != (int32_t)PMIC_ST_SUCCESS)
        {
            /* Log error */
            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_MCU_ESM, (uint16_t)D_PMIC_ERR_MCU_ESM_ESM_MCU_MODE_CFG_WR, (uint8_t)PMIC_DEV_0, 0U);
        } else {/* Do Nothing */}

        /* Set  ESM_MCU_START bit  of ESM_MCU_START_REG Register to  start monitoring*/
        v_pmicStatus_s32 =  Pmic_commIntf_sendByte(&pmic_device[PMIC_DEV_0].pmicCoreHandle, (uint16_t)D_PMIC_TPS65941_ESM_MCU_START_REG, (uint8_t)D_PMIC_REG_BITMASK_START_BIT);
        /* Check if PMIC ESM_MCU_START Write is success else return Error*/
        if(v_pmicStatus_s32 != (int32_t)PMIC_ST_SUCCESS)
        {
            /* Log error */
            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_MCU_ESM, (uint16_t)D_PMIC_ERR_MCU_ESM_ESM_MCU_START_REG_WR, (uint8_t)PMIC_DEV_0, 0U);
        } else {/* Do Nothing */}
    }
    else
    {
        /* Log error */
        Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_MCU_ESM, (uint16_t)D_PMIC_ERR_MCU_ESM_ESM_MCU_START_REG_RD, (uint8_t)PMIC_DEV_0, 0U);
    }
}




