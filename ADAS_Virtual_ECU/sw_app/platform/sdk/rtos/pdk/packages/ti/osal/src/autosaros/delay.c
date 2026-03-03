/*
 * Copyright (c) 2017-2018, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== delay.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ti/csl/soc.h>
#include <ti/osal/soc/osal_soc.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/osal/src/autosaros/autosaros_config.h>
#include <ti/csl/arch/r5/csl_arm_r5.h>
#include <ti/csl/arch/r5/csl_arm_r5_pmu.h>
#include "Os.h"
#include "Os_Types_Lcfg.h"
#include "boot_cfg.h"

#define RF5_DEFAULT_CLOCK_IN_MHZ    (1000U * (1000U * 1000U))
#define R5F_COUNTER_TICK_DIVIDER    (0U)

uint32_t osalAutosar_IsCtrEnabled;
static bool gTimestampInit = (bool)true;


static void osal_core_delay(uint32_t nTicks);


static void osal_core_delay(uint32_t nTicks)
{
    uint32_t             tsFreq;
    uint32_t            msTick = 0;
    uint32_t   startCount = 0U, tempCount, elaspsedCount = 0U;

    {
        /* Get the frequency of the timeStatmp provider */
        tsFreq  = osalAutosar_TimerGetClkFreq() / 1000u;

        /* Make sure init is done, if not done already */
        osalAutosar_TimerInit();

        startCount = osalAutosar_TimerGetCurrTick();

        do {
            tempCount = osalAutosar_TimerGetCurrTick();

            elaspsedCount  = tempCount - startCount;

            if ((uint32_t)elaspsedCount >= tsFreq)
            {
                msTick++;
                startCount = tempCount;
            }
            else
            {
               /* No action */
            }
        } while (msTick < nTicks);
    }

    return;
}

/** \brief Initializes the core internal timer (PMU in case of R5F)
 *
 */
void osalAutosar_TimerInit(void)
{
    uint32 val;
    /*  cycleCntDiv : Divide ticks by 64, i.e.count every 64th clock is:
                                                        R5F_COUNTER_TICK_DIVIDER
        exportEvents : Export events to monitoring block of R5F : Disabled
                                                        0U
        userEnable  : Enabled user mode access : Enabled
                                                        1U
    */
    if (gTimestampInit == (bool)true)
    {
        CSL_armR5PmuCfg(R5F_COUNTER_TICK_DIVIDER, 0U, 1);

        /* Clear the overflow */
        val = CSL_armR5PmuReadCntrOverflowStatus();
        val &= 0x80000000;
        CSL_armR5PmuClearCntrOverflowStatus(val);

        CSL_armR5PmuCfgCntr(
            CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM, /* Counter ID for counting cycles */
            CSL_ARM_R5_PMU_EVENT_TYPE_CYCLE_CNT); /* Cfg for counting cycles */

        /* Clear the counter CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM */
        CSL_armR5PmuEnableAllCntrs(1);

        osalAutosar_IsCtrEnabled = 0U;
        gTimestampInit = (bool)false;
    }
}

uint32_t osalAutosar_TimerGetClkFreq (void)
{
    uint32_t rtnVal = RF5_DEFAULT_CLOCK_IN_MHZ;

    if (1U == R5F_COUNTER_TICK_DIVIDER)
    {
        /* 64 is specific to R5F core and divider is not configurable */
        rtnVal = rtnVal / 64U;
    }

    return (rtnVal);
}

uint32_t  osalAutosar_TimerGetCurrTick (void)
{
    uint32_t rtnVal;

    if (0U == osalAutosar_IsCtrEnabled)
    {
        CSL_armR5PmuEnableCntr(CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM, 1);
        osalAutosar_IsCtrEnabled = 1U;
    }

    rtnVal = CSL_armR5PmuReadCntr(CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM);
    return (rtnVal);
}

/* Osal delay implementation for bare metal,
 * where nTicks is number of ticks in 1ms
 */
int32_t Osal_delay(uint32_t nTicks)
{
  /* Delay by number of ticks */
   osal_core_delay(nTicks);
   return (osal_OK);
}

/* nothing past this point */
