/*
*
* Copyright (c) 2020 Texas Instruments Incorporated
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
 *  \file     Pwm_Irq.c
 *
 *  \brief    This file contains the ISR implementation of PWM MCAL driver
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "Pwm_Priv.h"
#include "Pwm_Irq.h"

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
//Pwm_ChObjType Pwm_ChObj[PWM_MAX_NUM_CHANNELS];
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define PWM_START_SEC_ISR_CODE
#include "Pwm_MemMap.h"

#if (STD_ON == PWM_NOTIFICATION_SUPPORTED)

#ifdef PWM_USE_GPT

#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch1Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch1Isr)
#endif
{

    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL1);
        Pwm_IntDisableAll(PWM_CHANNEL1);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL1];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL1);
        }
    }
}

#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch2Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch2Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL2);
        Pwm_IntDisableAll(PWM_CHANNEL2);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL2];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL2);
        }
    }
}

#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch3Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch3Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL3);
        Pwm_IntDisableAll(PWM_CHANNEL3);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL3];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL3);
        }
    }
}
#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch4Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch4Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL4);
        Pwm_IntDisableAll(PWM_CHANNEL4);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL4];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL4);
        }
    }
}
#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch5Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch5Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL5);
        Pwm_IntDisableAll(PWM_CHANNEL5);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL5];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL5);
        }
    }
}
#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch6Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch6Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL6);
        Pwm_IntDisableAll(PWM_CHANNEL6);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL6];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL6);
        }
    }
}
#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch7Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch7Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL7);
        Pwm_IntDisableAll(PWM_CHANNEL7);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL7];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL7);
        }
    }
}
#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch8Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch8Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL8);
        Pwm_IntDisableAll(PWM_CHANNEL8);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL8];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL8);
        }
    }
}
#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch9Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch9Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL9);
        Pwm_IntDisableAll(PWM_CHANNEL9);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL9];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL9);
        }
    }
}
#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch10Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch10Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL10);
        Pwm_IntDisableAll(PWM_CHANNEL10);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL10];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL10);
        }
    }
}
#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch11Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch11Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL11);
        Pwm_IntDisableAll(PWM_CHANNEL11);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL11];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL11);
        }
    }
}
#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch12Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch12Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL12);
        Pwm_IntDisableAll(PWM_CHANNEL12);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL12];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL12);
        }
    }
}
#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch13Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch13Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL13);
        Pwm_IntDisableAll(PWM_CHANNEL13);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL13];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL13);
        }
    }
}
#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch14Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch14Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL14);
        Pwm_IntDisableAll(PWM_CHANNEL14);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL14];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL14);
        }
    }
}
#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch15Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch15Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL15);
        Pwm_IntDisableAll(PWM_CHANNEL15);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL15];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL15);
        }
    }
}
#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch16Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch16Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL16);
        Pwm_IntDisableAll(PWM_CHANNEL16);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL16];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL16);
        }
    }
}

#endif /*PWM_USE_GPT*/

#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)

#ifdef PWM_USE_GPT
#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch17Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch17Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL17);
        Pwm_IntDisableAll(PWM_CHANNEL17);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL17];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL17);
        }
    }
}


#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch18Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch18Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL18);
        Pwm_IntDisableAll(PWM_CHANNEL18);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL18];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL18);
        }
    }
}


#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch19Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch19Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL19);
        Pwm_IntDisableAll(PWM_CHANNEL19);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL19];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL19);
        }
    }
}


#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch20Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch20Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL20);
        Pwm_IntDisableAll(PWM_CHANNEL20);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL20];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL20);
        }
    }
}


#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch21Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch21Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL21);
        Pwm_IntDisableAll(PWM_CHANNEL21);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL21];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL21);
        }
    }
}


#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch22Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch22Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL22);
        Pwm_IntDisableAll(PWM_CHANNEL22);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL22];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL22);
        }
    }
}


#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch23Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch23Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL23);
        Pwm_IntDisableAll(PWM_CHANNEL23);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL23];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL23);
        }
    }
}


#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch24Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch24Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL24);
        Pwm_IntDisableAll(PWM_CHANNEL24);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL24];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL24);
        }
    }
}


#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch25Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch25Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL25);
        Pwm_IntDisableAll(PWM_CHANNEL25);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL25];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL25);
        }
    }
}


#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch26Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch26Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL26);
        Pwm_IntDisableAll(PWM_CHANNEL26);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL26];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL26);
        }
    }
}


#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch27Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch27Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL27);
        Pwm_IntDisableAll(PWM_CHANNEL27);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL27];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL27);
        }
    }
}


#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch28Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch28Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL28);
        Pwm_IntDisableAll(PWM_CHANNEL28);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL28];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL28);
        }
    }
}


#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch29Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch29Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL29);
        Pwm_IntDisableAll(PWM_CHANNEL29);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL29];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL29);
        }
    }
}


#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION FUNC(void, PWM_CODE_FAST) Pwm_Ch30Isr(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch30Isr)
#endif
{
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        Pwm_IntrClear(PWM_CHANNEL30);
        Pwm_IntDisableAll(PWM_CHANNEL30);
    }
    else
    {
        Pwm_ChObjType *chObj = &Pwm_ChObj[PWM_CHANNEL30];
        if (PWM_STATUS_INIT == chObj->channelState)
        {
            Pwm_ChannelNotificationISR(PWM_CHANNEL30);
        }
    }
}


#endif /*PWM_USE_GPT*/
#endif /* SOC_J721E */

#ifdef PWM_USE_EPWM
#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)

#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION void Pwm_Ch1Notify(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch1Notify)
#endif
{
#if (STD_ON == PWM_DEV_ERROR_DETECT)
    /*TI_INSPECTED 91 D : MISRAC_2012_R.17.7
     * "Reason - Tool Issue, baseAddr is used in this function only " */
    uint32 baseAddr = Pwm_GetBaseAddr(PWM_CHANNEL1);
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Disable and Clear Interrupt */
        Pwm_EtIntrDisable_epwm(baseAddr);
        Pwm_EtIntrClear_epwm(baseAddr);
    }
    else
#endif
    {
        Pwm_ChannelNotificationISR_epwm(PWM_CHANNEL1);
    }
}

#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION void Pwm_Ch2Notify(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch2Notify)
#endif
{
#if (STD_ON == PWM_DEV_ERROR_DETECT)
    /*TI_INSPECTED 91 D : MISRAC_2012_R.17.7
     * "Reason - Tool Issue, baseAddr is used in this function only " */
    uint32 baseAddr = Pwm_GetBaseAddr(PWM_CHANNEL2);
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Disable and Clear Interrupt */
        Pwm_EtIntrDisable_epwm(baseAddr);
        Pwm_EtIntrClear_epwm(baseAddr);
    }
    else
#endif
    {
        Pwm_ChannelNotificationISR_epwm(PWM_CHANNEL2);
    }
}

#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION void Pwm_Ch3Notify(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch3Notify)
#endif
{
#if (STD_ON == PWM_DEV_ERROR_DETECT)
    /*TI_INSPECTED 91 D : MISRAC_2012_R.17.7
     * "Reason - Tool Issue, baseAddr is used in this function only " */
    uint32 baseAddr = Pwm_GetBaseAddr(PWM_CHANNEL3);
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Disable and Clear Interrupt */
        Pwm_EtIntrDisable_epwm(baseAddr);
        Pwm_EtIntrClear_epwm(baseAddr);
    }
    else
#endif
    {
        Pwm_ChannelNotificationISR_epwm(PWM_CHANNEL3);
    }
}

#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION void Pwm_Ch4Notify(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch4Notify)
#endif
{
#if (STD_ON == PWM_DEV_ERROR_DETECT)
    /*TI_INSPECTED 91 D : MISRAC_2012_R.17.7
     * "Reason - Tool Issue, baseAddr is used in this function only " */
    uint32 baseAddr = Pwm_GetBaseAddr(PWM_CHANNEL4);
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Disable and Clear Interrupt */
        Pwm_EtIntrDisable_epwm(baseAddr);
        Pwm_EtIntrClear_epwm(baseAddr);
    }
    else
#endif
    {
        Pwm_ChannelNotificationISR_epwm(PWM_CHANNEL4);
    }
}

#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION void Pwm_Ch5Notify(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch5Notify)
#endif
{
#if (STD_ON == PWM_DEV_ERROR_DETECT)
    /*TI_INSPECTED 91 D : MISRAC_2012_R.17.7
     * "Reason - Tool Issue, baseAddr is used in this function only " */
    uint32 baseAddr = Pwm_GetBaseAddr(PWM_CHANNEL5);
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Disable and Clear Interrupt */
        Pwm_EtIntrDisable_epwm(baseAddr);
        Pwm_EtIntrClear_epwm(baseAddr);
    }
    else
#endif
    {
        Pwm_ChannelNotificationISR_epwm(PWM_CHANNEL5);
    }
}

#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
PWM_ISR_TEXT_SECTION void Pwm_Ch6Notify(void)
#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
PWM_ISR_TEXT_SECTION ISR(Pwm_Ch6Notify)
#endif
{
#if (STD_ON == PWM_DEV_ERROR_DETECT)
    /*TI_INSPECTED 91 D : MISRAC_2012_R.17.7
     * "Reason - Tool Issue, baseAddr is used in this function only " */
    uint32 baseAddr = Pwm_GetBaseAddr(PWM_CHANNEL6);
    if (PWM_STATUS_INIT != Pwm_DrvStatus)
    {
        /* Disable and Clear Interrupt */
        Pwm_EtIntrDisable_epwm(baseAddr);
        Pwm_EtIntrClear_epwm(baseAddr);
    }
    else
#endif
    {
        Pwm_ChannelNotificationISR_epwm(PWM_CHANNEL6);
    }
}

#endif /*SOC*/
#endif /*PWM_USE_EPWM*/


#endif /* PWM_NOTIFICATION_SUPPORTED */

#define PWM_STOP_SEC_ISR_CODE
#include "Pwm_MemMap.h"
