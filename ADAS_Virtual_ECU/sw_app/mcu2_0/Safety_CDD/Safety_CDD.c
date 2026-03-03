/**
 * @file Safety_CDD.c
 * @brief Safety function handling
 *
 * @details This file is for handling safety function
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
 * @Last Modified by:   Manatheykad, Shalhoob
 * @Last Modified time: 2023-09-12 13:18:26
 */

/* ===========================================================================
 *
 *   Include Files
 *
 * ========================================================================= */
#include <stdio.h>
#include <string.h>
#include "PlatformDataTypes.h"
#include "ErrorManagerDef.h"
#include "ErrorManagerSatellite.h"
#include "Safety_CDD.h"
#include "vim_mainR5.h"
#include <app_log.h>
#include <ti/csl/soc/j721s2/src/cslr_intr_r5fss0_core0.h>
#include <ti/csl/arch/r5/src/interrupt_priv.h>
#include "timer_fusa_utils.h"
/* ===========================================================================
 *
 *   Defines
 *
 * ========================================================================= */
#define VIM_INTR_TIMER_OS 0u
#define VIM_INTR_TIMER_TASK 1u

/* To be deleted */
#define ASILB_DATA_SECTION
#define ASILB_CODE_SECTION
#define ASILB_CONST_SECTION
/* ===========================================================================
 *
 * Typedefs
 *
 * ========================================================================= */
#define SAFETY_MAIN_FUNCTION_TASK_RATE 10
#define SAFETY_VIM_TIMER_OS_RUN_OFFSET 10
#define SAFETY_VIM_TIMER_TASK_RUN_OFFSET 20
#define SAFETY_VIM_READBACK_RUN_OFFSET 30
#define SAFETY_TASKTIMER_RUN_OFFSET 40
#define SAFETY_OSTIMER_RUN_OFFSET 50
#define SAFETY_MAIN_FUNCTION_RUN_EXPIRED 100
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
ASILB_DATA_SECTION static uint32_t u32SafetyTaskrunCount = 0;

/* =====================================================R5FSS0======================
 *
 *   Global variables
 *
 * ========================================================================= */

ASILB_CONST_SECTION const Safety_arm_vim_cfg j721s2_vim_data_2_0[] = {

    {
        .intrNum = CSLR_R5FSS0_CORE0_INTR_TIMER2_INTR_PEND_0,
        .pri = VIM_PRIV_VAL_0x0F,
        .intrMap = VIM_INTR_MAP_VAL_0,
        .intrType = VIM_INTR_TYPE_VAL_0,
        .intrEnClr = VIM_INTR_EN_VAL_1,
        .intrEnSet = VIM_INTR_EN_VAL_1,
    },
    {
        .intrNum = CSLR_R5FSS0_CORE0_INTR_TIMER4_INTR_PEND_0,
        .pri = VIM_PRIV_VAL_0x0F,
        .intrMap = VIM_INTR_MAP_VAL_0,
        .intrType = VIM_INTR_TYPE_VAL_0,
        .intrEnClr = VIM_INTR_EN_VAL_1,
        .intrEnSet = VIM_INTR_EN_VAL_1,
    },
};

ASILB_CONST_SECTION const Safety_vimStaticRegs j721s2_vim_static_data_2_0 = {
    .PID = 0x60900001,
    .INFO = 0x0200,
    #if !defined(VCAST)
    .DEDVEC = (volatile uint32_t) & VIM_VIMDEDInterruptHandler,
    #endif
};

/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */

/**
 * function name - Safety_MainFunction
 * @return - void
 * @description - Safety Mainfunction
 */
ASILB_CODE_SECTION void Safety_MainFunction(void)
{
  /* DD-ID: {07B85752-5285-4abb-ABDB-9ACBD0C8B306}*/
    int32_t retVal = SDL_PASS;
    u32SafetyTaskrunCount += SAFETY_MAIN_FUNCTION_TASK_RATE;
    uint8_t v_errData_u8[4] = {0};
    thresholdCounterVal localThreshold5msec, localThreshold1msec;

    switch (u32SafetyTaskrunCount)
    {
    case SAFETY_VIM_TIMER_OS_RUN_OFFSET:
    {
        retVal = Safety_VIM_verifyCfgIntr(&j721s2_vim_data_2_0[VIM_INTR_TIMER_OS]);
        if (retVal != 0x0)
        {
            /* Report Error Status */
            v_errData_u8[0] = u32SafetyTaskrunCount;
            ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_VIM_Register_Mismatch_in_MainDomain_2_0, ldef_ErrorMgr_ErrorActive, (const ldef_ErrorMgr_stAddData *)v_errData_u8);
        }
        break;
    }

    case SAFETY_VIM_TIMER_TASK_RUN_OFFSET:
    {

        retVal = Safety_VIM_verifyCfgIntr(&j721s2_vim_data_2_0[VIM_INTR_TIMER_TASK]);
        if (retVal != 0x0)
        {
            /* Report Error Status */
            v_errData_u8[0] = u32SafetyTaskrunCount;
            ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_VIM_Register_Mismatch_in_MainDomain_2_0, ldef_ErrorMgr_ErrorActive, (const ldef_ErrorMgr_stAddData *)v_errData_u8);
        }
        break;
    }
    case SAFETY_VIM_READBACK_RUN_OFFSET:
    {
        retVal = Safety_VIM_VerifyStaticRegs(&j721s2_vim_static_data_2_0);
        if (retVal != 0x0)
        {
            /* Report Error Status */
            v_errData_u8[0] = u32SafetyTaskrunCount;
            ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_VIM_Register_Mismatch_in_MainDomain_2_0, ldef_ErrorMgr_ErrorActive, (const ldef_ErrorMgr_stAddData *)v_errData_u8);
        }
        break;
    }

    case SAFETY_TASKTIMER_RUN_OFFSET:
    {
        localThreshold5msec = getCurrentTaskThresholdVal_5msec();
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        if ((localThreshold5msec.max_thresholdCounter > MAX_COUNTER_LIMIT) || (localThreshold5msec.min_thresholdCounter > MIN_COUNTER_LIMIT))
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        {
            v_errData_u8[0] = u32SafetyTaskrunCount;
            ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain_2_0, ldef_ErrorMgr_ErrorActive, (const ldef_ErrorMgr_stAddData *)v_errData_u8);
        }
        break;
    }
    case SAFETY_OSTIMER_RUN_OFFSET:
    {
        localThreshold1msec = getCurrentTaskThresholdVal_1msec();
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        if ((localThreshold1msec.max_thresholdCounter > MAX_COUNTER_LIMIT) || (localThreshold1msec.min_thresholdCounter > MIN_COUNTER_LIMIT))
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        {
            v_errData_u8[0] = u32SafetyTaskrunCount;
            ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain_2_0, ldef_ErrorMgr_ErrorActive, (const ldef_ErrorMgr_stAddData *)v_errData_u8);
        }
        break;
    }

    default:
    {
        if (SAFETY_MAIN_FUNCTION_RUN_EXPIRED <= u32SafetyTaskrunCount)
        {
            u32SafetyTaskrunCount = 0;
        }
    }
    break;
    }
}
