/**
 * @file pmic_error.c
 * @brief Safe state implementation for PMIC driver
 *
 * @details Safe state implementation for PMIC driver
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
/* PMIC error variable */
pmic_error_status_t  V_pmic_err_s = {0};

/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */

/*
 * Purpose: Collect PMIC error related PMIC fusa SM modules.
 * Description: Collect PMIC error related PMIC fusa SM modules.
 * Return Type: void
 */
void Pmic_F_CollectErr_v(uint16_t i_errType_u16, uint16_t i_errNum_u16, uint8_t i_devIdx_u8, uint8_t i_regulatorIdx_u8)
{
    /* DD-ID:{7C6F9750-940E-49b1-BEF9-FCD7B93CACE1}*/
    switch(i_errType_u16)
    {
        /* Init error */
        case (uint16_t)D_PMIC_ERR_TYPE_VMON_INIT_CMN:
        {
            /* Set error flag */
            V_pmic_err_s.voltmon_err_s.v_initErr_s.v_isErr_u8 = (uint8_t)TRUE;

            V_pmic_err_s.voltmon_err_s.v_initErr_s.v_initCmnErr_u16 |= i_errNum_u16;
            break;
        }

        /* Init common error */
        case (uint16_t)D_PMIC_ERR_TYPE_VMON_INIT:
        {
            /* Set error flag */
            V_pmic_err_s.voltmon_err_s.v_initErr_s.v_isErr_u8 = (uint8_t)TRUE;

            V_pmic_err_s.voltmon_err_s.v_initErr_s.v_initErr_au16[i_devIdx_u8] |= i_errNum_u16;
            break;
        }

        /* Run time error (PMIC Specific) */
        case (uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_DEV:
        {
            /* Set error flag */
            V_pmic_err_s.voltmon_err_s.v_runTimeErr_as[i_devIdx_u8].v_isErr_u8 = (uint8_t)TRUE;
            
            V_pmic_err_s.voltmon_err_s.v_runTimeErr_as[i_devIdx_u8].v_devSpecificErr_u16 |= i_errNum_u16;
            break;
        }

        /* Run time error (BUCK Specific) */
        case (uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_BUCK:
        {
            /* Set error flag */
            V_pmic_err_s.voltmon_err_s.v_runTimeErr_as[i_devIdx_u8].v_isErr_u8 = (uint8_t)TRUE;
            
            V_pmic_err_s.voltmon_err_s.v_runTimeErr_as[i_devIdx_u8].v_buckErr_au16[i_regulatorIdx_u8] |= i_errNum_u16;
            break;
        }

        /* Run time error (LDO Specific) */
        case (uint16_t)D_PMIC_ERR_TYPE_VMON_RUN_TIME_LDO:
        {
            /* Set error flag */
            V_pmic_err_s.voltmon_err_s.v_runTimeErr_as[i_devIdx_u8].v_isErr_u8 = (uint8_t)TRUE;
            
            V_pmic_err_s.voltmon_err_s.v_runTimeErr_as[i_devIdx_u8].v_ldoErr_au16[i_regulatorIdx_u8] |= i_errNum_u16;
            break;
        }

        /* Run time error for Bist Status check */
        case (uint16_t)D_PMIC_ERR_TYPE_BIST_STS_CHECK:
        {
            /* Set error flag */
            V_pmic_err_s.bistStsCheck_err_s.v_isErr_u8 = (uint8_t)TRUE;
            
            V_pmic_err_s.bistStsCheck_err_s.v_runTimeErr_u16[i_devIdx_u8] |= i_errNum_u16;
            break;
        }

        /* Config error for readback logic */
        case (uint16_t)D_PMIC_ERR_TYPE_RDBK_CFG:
        {
            /* Set error flag */
            V_pmic_err_s.readback_err_s.v_rdbk_err_as[i_devIdx_u8].v_isErr_u8 = (uint8_t)TRUE;
            
            V_pmic_err_s.readback_err_s.v_rdbk_err_as[i_devIdx_u8].v_configErr_u16 |= i_errNum_u16;
            break;
        }

        /* Runtime error for readback logic */
        case (uint16_t)D_PMIC_ERR_TYPE_RDBK_MON:
        {
            /* Set error flag */
            V_pmic_err_s.readback_err_s.v_rdbk_err_as[i_devIdx_u8].v_isErr_u8 = (uint8_t)TRUE;
            
            V_pmic_err_s.readback_err_s.v_rdbk_err_as[i_devIdx_u8].v_runTimeErr_u16 |= i_errNum_u16;
            break;
        }
        
        /* lbist error */
        case (uint16_t)D_PMIC_ERR_LBIST:
        {
            /* Set error flag */
            V_pmic_err_s.lbist_err_s.v_isErr_u8 = (uint8_t)TRUE;
            
            V_pmic_err_s.lbist_err_s.v_errCode_au16[i_devIdx_u8] |= i_errNum_u16;
            break;
        }
        
        /* Thermal warning */
        case (uint16_t)D_PMIC_ERR_TWARN:
        {
            /* Set error flag */
            V_pmic_err_s.twarn_s.v_isErr_u8 = (uint8_t)TRUE;
            
            V_pmic_err_s.twarn_s.v_errCode_au16[i_devIdx_u8] |= i_errNum_u16;
            break;
        }
        /* MCU_ESM Error */
        case (uint16_t)D_PMIC_ERR_TYPE_MCU_ESM:
        {
            /* Set error flag */
            V_pmic_err_s.esm_mcu_en_err_s.v_isErr_u8 = (uint8_t)TRUE;

            V_pmic_err_s.esm_mcu_en_err_s.v_errCode_au16[i_devIdx_u8] |= i_errNum_u16;
            break;
        }
        
        /* CLOCKMON_EN Error */
        case (uint16_t)D_PMIC_ERR_TYPE_CLOCKMON_EN:
        {
            /* Set error flag */
            V_pmic_err_s.clkmon_en_err_s.v_isErr_u8 = (uint8_t)TRUE;

            V_pmic_err_s.clkmon_en_err_s.v_errCode_au16[i_devIdx_u8] |= i_errNum_u16;
            break;
        }
        
        /* REGISTER_LOCK Error */
        case (uint16_t)D_PMIC_ERR_TYPE_REG_LOCK:
        {
            /* Set error flag */
            V_pmic_err_s.reg_lock_err_s.v_isErr_u8 = (uint8_t)TRUE;

            V_pmic_err_s.reg_lock_err_s.v_errCode_au16[i_devIdx_u8] |= i_errNum_u16;
            break;
        }

        default:
        {
            /* Do nothing */
            break;
        }
    }
}
