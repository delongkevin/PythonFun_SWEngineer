/*
*
* Copyright (c) 2019 Texas Instruments Incorporated
*
* All rights reserved not granted herein.
*
* Limited License.
*
* Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
* license under copyrights and patents it now or hereafter owns or controls to make,
* have made, use, import, offer to sell and sell ("Utilize") this software subject to the
* terms herein.  With respect to the foregoing patent license, such license is granted
* solely to the extent that any such patent is necessary to Utilize the software alone.
* The patent license shall not apply to any combinations which include this software,
* other than combinations with devices manufactured by or for TI ("TI Devices").
* No hardware patent is licensed hereunder.
*
* Redistributions must preserve existing copyright notices and reproduce this license
* (including the above copyright notice and the disclaimer and (if applicable) source
* code license limitations below) in the documentation and/or other materials provided
* with the distribution
*
* Redistribution and use in binary form, without modification, are permitted provided
* that the following conditions are met:
*
* *       No reverse engineering, decompilation, or disassembly of this software is
* permitted with respect to any software provided in binary form.
*
* *       any redistribution and use are licensed by TI for use only with TI Devices.
*
* *       Nothing shall obligate TI to provide you with source code for the software
* licensed and provided to you in object code.
*
* If software source code is provided to you, modification and redistribution of the
* source code are permitted provided that the following conditions are met:
*
* *       any redistribution and use of the source code, including any resulting derivative
* works, are licensed by TI for use only with TI Devices.
*
* *       any redistribution and use of any object code compiled from the source code
* and any resulting derivative works, are licensed by TI for use only with TI Devices.
*
* Neither the name of Texas Instruments Incorporated nor the names of its suppliers
*
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* DISCLAIMER.
*
* THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/**
 *  \file     AdcApp_Startup.c
 *
 *  \brief    This file contains the pinmux, interrupt and clock configuration.
 */
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "string.h"
#include "Adc.h"
#include "Adc_Priv.h"
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/soc.h>
#include <ti/csl/cslr.h>
/* SCI Client */
#include <ti/drv/sciclient/sciclient.h>
#include "Os.h"
#include "Os_Types_Lcfg.h"
#include <ti/csl/arch/r5/csl_arm_r5.h>


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static void AdcApp_PowerAndClkSrc(void);
static uint32 Adc_GetAdcVoltage(uint32 adcValue);
static uint32 AdcApp_procImplicitStop(const Adc_ConfigType *Adc_ConfigPtr);
static uint32 AdcApp_procExplicitStop(const Adc_ConfigType *Adc_ConfigPtr);
//static void AdcApp_procIsr(uint32 grpIdx);
static void AdcApp_PrintResult();
uintptr_t AdcSchM_IntKey;
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
uint32                            Adc_TestPassed = E_OK;
/**< App Result Status Flag */
uint32                            Adc_AppLoopCount = 5U;
/**< Number of times App runs */
Adc_ValueGroupType                Adc_AppBuffer[ADC_MAX_GROUP][
    ADC_APP_BUF_SIZE_WORD];
/**< SetUp Result Buffer passed to driver */
Adc_ValueGroupType                Adc_AppReadBuffer[ADC_MAX_GROUP][
    ADC_APP_READ_BUF_SIZE_WORD];
/**< Output Result Buffer */
volatile uint32                   Adc_AppRdBufCount[ADC_MAX_GROUP];
/**< No of Samples Counter */
volatile uint32                   Adc_AppGroupDone[ADC_MAX_GROUP];
/**< Group Conversion Completion flag */
const Adc_ConfigType *Adc_ConfigPtr;

uint32 ADC_LastRecordedvoltage = 0;
/**< Pointer to configuration  */
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void AdcApp_Init(void)
{
    AdcApp_PowerAndClkSrc();
    Adc_ConfigPtr = &ADC_INIT_CONFIG_PC;
    Adc_Init((const Adc_ConfigType *) NULL_PTR);
}

static void AdcApp_PowerAndClkSrc(void)
{
    uint32 regVal;
    /* Unlock lock key registers for Partition 0: IO PAD
       configuration registers in MCU_CTRL_MMR */
    /* write Partition 0 Lock Key 0 Register */
    CSL_REG32_WR(CSL_MCU_CTRL_MMR0_CFG0_BASE +
        CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0, 0x68EF3490U);
    /* write Partition 1 Lock Key 1 Register */
    CSL_REG32_WR(CSL_MCU_CTRL_MMR0_CFG0_BASE +
        CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK1, 0xD172BC5AU);
    /* Check for unlock */
    regVal = CSL_REG32_RD(CSL_MCU_CTRL_MMR0_CFG0_BASE +
        CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0);
    while ((regVal & 0x1U) != 0x1U)
    {
		/* Check for unlock */
		regVal = CSL_REG32_RD(CSL_MCU_CTRL_MMR0_CFG0_BASE +
			CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0);
    }

    /* Select clock frequency 25 MHZ */
    CSL_REG32_FINS(CSL_MCU_CTRL_MMR0_CFG0_BASE +
                  CSL_MCU_CTRL_MMR_CFG0_MCU_ADC0_CLKSEL,
                  MCU_CTRL_MMR_CFG0_MCU_ADC0_CLKSEL_PROXY_MCU_ADC0_CLKSEL_CLK_SEL_PROXY,
                  0U);
    return;
}

void AdcApp_Runnable(void)
{
    uint32              grpIdx = 1;
    uint32              testPassed = E_OK;
    Adc_StatusType      status;
    Std_ReturnType      retVal;

        /* Check group status - it should be idle */
        status = Adc_GetGroupStatus(grpIdx);
        if (status != ADC_IDLE)
        {
            testPassed = E_NOT_OK;
        }
        else
        {
                /* Reset read counter and buffer content */
                Adc_AppRdBufCount[grpIdx] = 0U;
                memset(
                    &Adc_AppReadBuffer[grpIdx][0],
                    0U,
                    (sizeof (Adc_ValueGroupType) * ADC_APP_READ_BUF_SIZE_WORD));

             /* Memset result buffer and give to driver */
            memset(
                &Adc_AppBuffer[grpIdx][0],
                0U,
                (sizeof (Adc_ValueGroupType) * ADC_APP_BUF_SIZE_WORD));
            retVal = Adc_SetupResultBuffer(grpIdx, &Adc_AppBuffer[grpIdx][0]);
            if (retVal != E_OK)
            {
                testPassed = E_NOT_OK;
            }
            else
            {
                /* One Shot Mode Conversion */
                if ((ADC_CONV_MODE_ONESHOT == Adc_ConfigPtr->groupCfg[ADC_GROUP_ID_1].convMode) ||
                    (ADC_STREAM_BUFFER_LINEAR ==
                     Adc_ConfigPtr->groupCfg[ADC_GROUP_ID_1].streamBufMode))
                {
                    testPassed = AdcApp_procImplicitStop(Adc_ConfigPtr);
                }
            }
        }

    if (E_OK == Adc_TestPassed)
    {
        Adc_TestPassed = testPassed;
    }

    return;
}

static uint32 AdcApp_procImplicitStop(const Adc_ConfigType *Adc_ConfigPtr)
{
    uint32         testPassed = E_OK, isPending;
    Adc_StatusType status;

        /* Reset flags */
        Adc_AppGroupDone[ADC_GROUP_ID_1] = FALSE;

        /* Memset result buffer and give to driver */
        memset(
            &Adc_AppBuffer[ADC_GROUP_ID_1][0],
            0U,
            (sizeof (Adc_ValueGroupType) * ADC_APP_BUF_SIZE_WORD));

#if (ADC_GRP_NOTIF_CAPABILITY_API == STD_ON)
        /* Enable notification */
        Adc_EnableGroupNotification(ADC_GROUP_ID_1);
#endif      /* #if (ADC_GRP_NOTIF_CAPABILITY_API == STD_ON) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
        /* Start conversion */
        Adc_StartGroupConversion(ADC_GROUP_ID_1);
#endif      /* #if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

        /* Note: Stop not required as read group API we are calling from
         * ISR callback will move state to idle automatically */
#if (ADC_GRP_NOTIF_CAPABILITY_API == STD_ON)
        //Adc_DisableGroupNotification(ADC_GROUP_ID_1);
#endif      /* #if (ADC_GRP_NOTIF_CAPABILITY_API == STD_ON) */


    return (testPassed);
}

void AdcApp_HwUnit0_Group0EndNotification(void)
{
    AdcApp_procIsr(ADC_GROUP_ID_0);
}

#if defined (SOC_J721E) || defined (SOC_J721S2)
void AdcApp_HwUnit1_Group0EndNotification(void)
{
    AdcApp_procIsr(ADC_GROUP_ID_1);
    Adc_DisableGroupNotification(ADC_GROUP_ID_1);
}
#endif  /* #if defined (SOC_J721E) || defined (SOC_J721S2)*/

void AdcApp_procIsr(uint32 grpIdx)
{
    Adc_StatusType status;
    const Adc_GroupConfigType *grpCfg;
    const Adc_ValueGroupType    *tempResultPtr;
#if (ADC_READ_GROUP_API == STD_ON)
    uint32         offset;
    Std_ReturnType retVal;
#endif  /* #if (ADC_READ_GROUP_API == STD_ON) */

    grpCfg = &Adc_ConfigPtr->groupCfg[grpIdx];
    /* Check group status - it should be COMPLETED state */
    status = Adc_GetGroupStatus(grpIdx);
    if ((status == ADC_COMPLETED) || (status == ADC_STREAM_COMPLETED))
    {
#if (ADC_READ_GROUP_API == STD_ON)
        /* Read and store the result */
        offset = Adc_AppRdBufCount[grpIdx] * grpCfg->numChannels;
        retVal = Adc_ReadGroup(grpIdx, &Adc_AppReadBuffer[grpIdx][offset]);
        if (retVal != E_OK)
        {
            Adc_TestPassed = E_NOT_OK;

        }

        /* Move to next set of samples */
        Adc_AppRdBufCount[grpIdx]++;
        if (Adc_AppRdBufCount[grpIdx] > ADC_APP_MAX_READ_SAMPLES)
        {
            /* Keep reading to the last buffer set incase of buffer overflow */
            Adc_AppRdBufCount[grpIdx] = ADC_APP_MAX_READ_SAMPLES - 1U;
        }
#endif  /* #if (ADC_READ_GROUP_API == STD_ON) */
    }
    else
    {
        Adc_TestPassed = E_NOT_OK;
    }

    if ((ADC_CONV_MODE_ONESHOT == grpCfg->convMode) ||
        (ADC_STREAM_BUFFER_LINEAR == grpCfg->streamBufMode))
    {
        /* post after all streams are completed */
        if ((Adc_AppRdBufCount[grpIdx] % grpCfg->streamNumSamples) == 0U)
        {
            Adc_AppGroupDone[grpIdx] = TRUE;
        }
    }
    else
    {
        /* post after loopcount of all streams */
        if (Adc_AppRdBufCount[grpIdx] >=
            (grpCfg->streamNumSamples * Adc_AppLoopCount))
        {
            Adc_AppGroupDone[grpIdx] = TRUE;
        }
    }

    tempResultPtr = &Adc_AppReadBuffer[grpIdx][0];
    ADC_LastRecordedvoltage       = Adc_GetAdcVoltage(*tempResultPtr);
    return;
}

static void AdcApp_PrintResult()
{
    uint32 grpIdx, chIdx;
    uint32 strmIdx, strmOffset;
    uint32 setIdx, setOffset;
    const Adc_GroupConfigType   *grpCfg;
    const Adc_ChannelConfigType *chCfg;
    const Adc_ValueGroupType    *tempResultPtr;
    uint32 voltage;
    uint32 readErr;
    Adc_ValueGroupType lowerLimit, upperLimit;


    for (grpIdx = 0U; grpIdx < Adc_ConfigPtr->maxGroup; grpIdx++)
    {
        grpCfg = &Adc_ConfigPtr->groupCfg[grpIdx];

        for (chIdx = 0U; chIdx < grpCfg->numChannels; chIdx++)
        {
            chCfg = &grpCfg->channelConfig[chIdx];
            for (strmIdx = 0U; strmIdx < grpCfg->streamNumSamples;
                 strmIdx++)
            {
                strmOffset =
                    (grpCfg->streamNumSamples * chIdx) + strmIdx;
                tempResultPtr = &Adc_AppBuffer[grpIdx][strmOffset];
                voltage       = Adc_GetAdcVoltage(*tempResultPtr);

            }
        }
    }

    for (grpIdx = 0U; grpIdx < Adc_ConfigPtr->maxGroup; grpIdx++)
    {
        readErr = FALSE;
        grpCfg  = &Adc_ConfigPtr->groupCfg[grpIdx];

        for (chIdx = 0U; chIdx < grpCfg->numChannels; chIdx++)
        {
            chCfg = &grpCfg->channelConfig[chIdx];
            for (setIdx = 0U; setIdx < Adc_AppRdBufCount[grpIdx]; setIdx++)
            {
                setOffset     = (grpCfg->numChannels * setIdx) + chIdx;
                tempResultPtr = &Adc_AppReadBuffer[grpIdx][setOffset];
                voltage       = Adc_GetAdcVoltage(*tempResultPtr);


                /* Check for value within range - use first sample value
                 * as the reference and keeping 5% variance i.e appx 200mv */
                if (0U == setIdx)
                {
                    lowerLimit = 0U;
                    if (*tempResultPtr > 200U)
                    {
                        lowerLimit = *tempResultPtr - 200U;
                    }
                    upperLimit = *tempResultPtr + 200U;
                }
                else
                {
                    if ((*tempResultPtr < lowerLimit) ||
                        (*tempResultPtr > upperLimit))
                    {
                        readErr = TRUE;
                    }
                }
            }
        }

    }

    return;
}

static uint32 Adc_GetAdcVoltage(uint32 adcValue)
{
    uint32 refVoltage    = 1800U;
    uint32 maxResolution = 4095U;

    return ((adcValue * refVoltage) / maxResolution);
}


void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_0(void)
{
    AdcSchM_IntKey = CSL_armR5GetCpsrRegVal();
    /* Disable IRQ and FIQ */
    CSL_armR5DisableIrqFiq();
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_0(void)
{
    CSL_armR5EnableIrqFiq(AdcSchM_IntKey);
}

uint16 Adc_BatteryVoltage(void)
{
    return ADC_LastRecordedvoltage;
}
