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
 *  \file     Gpt_Irq.c
 *
 *  \brief    This file contains the ISR implementation of GPT MCAL driver
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* Design : DES_GPT_011 */
/* Requirements : MCAL-1971 */
#include "Gpt.h"
#include "Gpt_Priv.h"
#include "Gpt_Irq.h"
#include "Os.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define GPT_START_SEC_ISR_CODE
#include "Gpt_MemMap.h"

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch1Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch1Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER1);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER1);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER1, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch2Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch2Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER2);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER2);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER2, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch3Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch3Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER3);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER3);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER3, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch4Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch4Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER4);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER4);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER4, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch5Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch5Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER5);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER5);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER5, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch6Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch6Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER6);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER6);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER6, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch7Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch7Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER7);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER7);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER7, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch8Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch8Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER8);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER8);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER8, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}


#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch9Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch9Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER9);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER9);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER9, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch10Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch10Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER10);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER10);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER10, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch11Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch11Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER11);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER11);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER11, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch12Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch12Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER12);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER12);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER12, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch13Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch13Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER13);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER13);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER13, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch14Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch14Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER14);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER14);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER14, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch15Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch15Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER15);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER15);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER15, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch16Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch16Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER16);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER16);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER16, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

/* ========================================================================== */
/*                         J721E Specific Instances only                      */
/* ========================================================================== */

#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch17Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch17Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER17);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER17);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER17, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch18Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch18Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER18);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER18);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER18, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch19Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch19Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER19);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER19);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER19, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch20Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch20Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER20);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER20);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER20, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch21Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch21Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER21);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER21);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER21, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch22Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch22Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER22);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER22);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER22, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch23Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch23Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER23);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER23);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER23, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch24Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch24Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER24);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER24);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER24, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch25Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch25Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER25);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER25);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER25, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch26Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch26Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER26);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER26);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER26, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch27Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch27Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER27);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER27);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER27, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch28Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch28Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER28);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER28);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER28, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch29Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch29Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER29);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER29);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER29, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}

#if ((GPT_ISR_TYPE == GPT_ISR_CAT1) || (GPT_ISR_TYPE == GPT_ISR_VOID))
GPT_ISR_TEXT_SECTION FUNC(void, GPT_CODE_FAST) Gpt_Ch30Isr(void)
#elif (GPT_ISR_TYPE == GPT_ISR_CAT2)
GPT_ISR_TEXT_SECTION ISR(Gpt_Ch30Isr)
#endif
{
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    if (GPT_DRV_INTIALIZED != Gpt_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Gpt_gptimerIntDisableAll(GPT_CH_GPTIMER30);
        Gpt_gptimerIntrClear(GPT_CH_GPTIMER30);
    }
    else
    {
        pGptChHwObj = Gpt_getHwUnitObj(GPT_CH_GPTIMER30, &chIdx);
        if (NULL_PTR != pGptChHwObj)
        {
            Gpt_IsrFxn[pGptChHwObj->channelIsrFnIdx](chIdx);
        }
    }
}
#endif /* SOC_J721E */

#define GPT_STOP_SEC_ISR_CODE
#include "Gpt_MemMap.h"
