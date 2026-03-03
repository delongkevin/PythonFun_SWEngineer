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
 *  \file     Adc_Irq.c
 *
 *  \brief    This file contains the ISR implementation of ADC MCAL driver
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "Adc_Cfg.h"
#include "Adc.h"
#include "Adc_Priv.h"
# include "Os.h"
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

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define ADC_START_SEC_ISR_CODE
#include "Adc_MemMap.h"

#if defined _MCAL8_5_UPDATE_
/* Design : DES_ADC_010, DES_ADC_033 */
/* Requirements : MCAL-3205, MCAL-3418 */
//#if defined (ADC_INSTANCE_0)
  #if ((ADC_ISR_TYPE == ADC_ISR_CAT1) || (ADC_ISR_TYPE == ADC_ISR_VOID))

FUNC(void, ADC_CODE_FAST) Adc_IrqUnit0(void)
  #else
ISR(Adc_IrqUnit0)
  #endif
{
    Adc_HwUnitObjType *hwUnitObj;

    hwUnitObj = &Adc_DrvObj.hwUnitObj[ADC_UNIT_0];
    Adc_IrqTxRx(hwUnitObj);
}
//#endif  /* #if defined (ADC_INSTANCE_0) */

#if defined (SOC_J721E) || defined (SOC_J721S2)
#if defined (ADC_INSTANCE_1)
  #if ((ADC_ISR_TYPE == ADC_ISR_CAT1) || (ADC_ISR_TYPE == ADC_ISR_VOID))

FUNC(void, ADC_CODE_FAST) Adc_IrqUnit1(void)
  #else
ISR(Adc_IrqUnit1)
  #endif
{
    Adc_HwUnitObjType *hwUnitObj;

    hwUnitObj = &Adc_DrvObj.hwUnitObj[ADC_UNIT_1];
    Adc_IrqTxRx(hwUnitObj);
}
#endif  /* #if defined (ADC_INSTANCE_1) */
#endif  /* #if defined (SOC_J721E)*/
#endif /*# _MCAL8_5_UPDATE_ */

FUNC(void, ADC_CODE_FAST) Adc_IntISR_Fun(Adc_ChannelType AdcChannel)

{
    Adc_HwUnitObjType *hwUnitObj;

    hwUnitObj = &Adc_DrvObj.hwUnitObj[AdcChannel];
    Adc_IrqTxRx(hwUnitObj);
}

#define ADC_STOP_SEC_ISR_CODE
#include "Adc_MemMap.h"
