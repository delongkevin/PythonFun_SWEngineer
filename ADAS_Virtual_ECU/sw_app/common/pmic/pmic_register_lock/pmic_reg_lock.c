/**
 * @file pmic_reg_lock.c
 * @brief PMIC Register Lock Monitoring
 *
 * @details This file provides interface to monitor the register lock status
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
#include "pmic_reg_lock.h"
#include <ti/drv/pmic/src/pmic_io_priv.h>
#include "pmic_error.h"

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

/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */
/*
 * Purpose: Read data from PMIC registers for Register lock monitoring
 * Description: Read data from PMIC registers for Register lock monitoring.
 * Return Type: void
 */
void Pmic_F_RegLockMon_v(void)
{
    /* DD-ID:{E7915C8C-8AF2-47a6-9EE9-9EA42F5E3799}*/
    /* Note: By default in NVM setting for Bit REGISTER_LOCK_STATUS is 0 (Registers are unlocked) for Master, Slave and Hera */

    uint8_t  v_devIdx_u8;
    int32_t  v_pmicStatus_s32;

    /* Iterate through all 3 pmic device */
    for(v_devIdx_u8 = 0; v_devIdx_u8 < (uint8_t)PMIC_DEV_NUM; v_devIdx_u8++)
    {
        /* Write REGISTER_LOCK register to lock all Configuration and control registers */
        v_pmicStatus_s32 = Pmic_commIntf_sendByte(&pmic_device[v_devIdx_u8].pmicCoreHandle, (uint16_t)D_PMIC_TPS65941_REGISTER_LOCK, (uint8_t)D_PMIC_REG_LOCK_KEY);

        if(v_pmicStatus_s32 != (int32_t)PMIC_ST_SUCCESS)
        {
            /* Log error */
            Pmic_F_CollectErr_v((uint16_t)D_PMIC_ERR_TYPE_REG_LOCK, (uint16_t)D_PMIC_ERR_REG_LOCK_WR, v_devIdx_u8, 0);
        }
        else
        {
            pmic_device[v_devIdx_u8].regLocked = (bool)true;
        }
    }
}


int32_t Pmic_F_RegUnLockMon_v(uint8_t device)
{
    /* DD-ID:{AB3113E0-8604-498d-95BD-54FA36047545}*/
    /* Note: By default in NVM setting for Bit REGISTER_LOCK_STATUS is 0 (Registers are unlocked) for Master, Slave and Hera */
    int32_t  v_pmicStatus_s32;

    /* Write REGISTER_LOCK register to lock all Configuration and control registers */
    v_pmicStatus_s32 = Pmic_commIntf_sendByte(&pmic_device[device].pmicCoreHandle, (uint16_t)D_PMIC_TPS65941_REGISTER_LOCK, (uint8_t)D_PMIC_REG_UNLOCK_KEY);

    return v_pmicStatus_s32;
}

