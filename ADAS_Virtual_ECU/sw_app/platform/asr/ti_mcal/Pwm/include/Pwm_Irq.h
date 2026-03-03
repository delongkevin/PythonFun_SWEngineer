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
 *  \file     Pwm_Irq.h
 *
 *  \brief    This file contains ISR function declaration for PWM MCAL driver
 *
 */

/**
 *  \ingroup MCAL_PWM_API
 *  \defgroup MCAL_PWM_IRQ Pwm Driver Interrupt Handlers
 *
 *  This file defines the interrupt handlers for all instance of timer/channels
 *  @{
 */

#ifndef PWM_IRQ_H_
#define PWM_IRQ_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
/* Design : DES_PWM_006 */
/* Requirements : MCAL-3508 */
#include "Pwm.h"
#ifdef __cplusplus
extern "C"
{
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/**
 *  \name PWM Driver ISR category level
 *
 *  Defines for PWM Driver ISR ISR category level
 *  @{
 */
/** \brief void ISR type */
#define PWM_ISR_VOID                    (0x00U)
/** \brief Category 1 ISR type */
#define PWM_ISR_CAT1                    (0x01U)
/** \brief Category 2 ISR type */
#define PWM_ISR_CAT2                    (0x02U)
/* @} */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         GLOBAL VARIABLES                                   */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
#if (STD_ON == PWM_NOTIFICATION_SUPPORTED)
#if ((PWM_ISR_TYPE == PWM_ISR_CAT1) || (PWM_ISR_TYPE == PWM_ISR_VOID))
#ifdef PWM_USE_GPT
/** \brief PWM Channel 1 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch1Isr(void);
/** \brief PWM Channel 2 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch2Isr(void);
/** \brief PWM Channel 3 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch3Isr(void);
/** \brief PWM Channel 4 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch4Isr(void);
/** \brief PWM Channel 5 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch5Isr(void);
/** \brief PWM Channel 6 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch6Isr(void);
/** \brief PWM Channel 7 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch7Isr(void);
/** \brief PWM Channel 8 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch8Isr(void);
/** \brief PWM Channel 9 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch9Isr(void);
/** \brief PWM Channel 10 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch10Isr(void);
/** \brief PWM Channel 11 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch11Isr(void);
/** \brief PWM Channel 12 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch12Isr(void);
/** \brief PWM Channel 13 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch13Isr(void);
/** \brief PWM Channel 14 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch14Isr(void);
/** \brief PWM Channel 15 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch15Isr(void);
/** \brief PWM Channel 16 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch16Isr(void);
#endif /*PWM_USE_GPT*/

#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)

#ifdef PWM_USE_GPT
/** \brief PWM Channel 17 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch17Isr(void);
/** \brief PWM Channel 18 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch18Isr(void);
/** \brief PWM Channel 19 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch19Isr(void);
/** \brief PWM Channel 20 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch20Isr(void);
/** \brief PWM Channel 21 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch21Isr(void);
/** \brief PWM Channel 22 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch22Isr(void);
/** \brief PWM Channel 23 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch23Isr(void);
/** \brief PWM Channel 24 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch24Isr(void);
/** \brief PWM Channel 25 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch25Isr(void);
/** \brief PWM Channel 26 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch26Isr(void);
/** \brief PWM Channel 27 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch27Isr(void);
/** \brief PWM Channel 28 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch28Isr(void);
/** \brief PWM Channel 29 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch29Isr(void);
/** \brief PWM Channel 30 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch30Isr(void);
#endif /*PWM_USE_GPT*/

#ifdef PWM_USE_EPWM
/** \brief EPWM Channel 1 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch1Notify(void);
/** \brief EPWM Channel 2 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch2Notify(void);
/** \brief EPWM Channel 3 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch3Notify(void);
/** \brief EPWM Channel 4 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch4Notify(void);
/** \brief EPWM Channel 5 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch5Notify(void);
/** \brief EPWM Channel 6 ISR */
FUNC(void, PWM_CODE_FAST) Pwm_Ch6Notify(void);
#endif /*PWM_USE_EPWM*/

#endif /*SOC*/


#elif (PWM_ISR_TYPE == PWM_ISR_CAT2)
/* Function prototype is declared by OS */
#endif
#endif
#ifdef __cplusplus
}
#endif

#endif  /* #ifndef PWM_IRQ_H_ */

/* @} */
