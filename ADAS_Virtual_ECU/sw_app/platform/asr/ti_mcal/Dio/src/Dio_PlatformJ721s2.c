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
 *  \file     Dio_PlatformJ721s2.c
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
/* Requirements : MCAL-1091 */
#include "Std_Types.h"
#include "Dio.h"
#include "Dio_Priv.h"
#include <ti/csl/soc.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define DIO_WKUP0_RESERVED_PIN_START0    (32U)
#define DIO_WKUP0_RESERVED_PIN_END0      (42U)
#define DIO_WKUP0_RESERVED_PIN_START1    (82U)
#define DIO_WKUP0_RESERVED_PIN_END1      (83U)
#define DIO_WKUP0_RESERVED_PIN_START2    (85U)
#define DIO_WKUP0_RESERVED_PIN_END2      (143U)

#define DIO_WKUP1_RESERVED_PIN_START0    (144U + 32U)
#define DIO_WKUP1_RESERVED_PIN_END0      (144U + 42U)
#define DIO_WKUP1_RESERVED_PIN_START1    (144U + 82U)
#define DIO_WKUP1_RESERVED_PIN_END1      (144U + 83U)
#define DIO_WKUP1_RESERVED_PIN_START2    (144U + 85U)
#define DIO_WKUP1_RESERVED_PIN_END2      (144U + 143U)

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */
#if defined _MCAL8_5_UPDATE_
typedef struct {
    uint8 regNum;
    uint8 numPins;
    uint32 reservedPinStart;
} DioReservedPinListType;
#endif /* _MCAL8_5_UPDATE_ */
/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
#if defined _MCAL8_5_UPDATE_  /* Redefination in Dio_cfg */
#define DIO_START_SEC_CONST_32

#include "Dio_MemMap.h"

DIO_VAR_CONST_32_SECTION static CONST(uint32, DIO_CONST)
    Dio_GPIOBaseAddr[DIO_HW_UNIT_CNT] =
{
    (uint32)CSL_WKUP_GPIO0_BASE,
    (uint32)CSL_WKUP_GPIO1_BASE,
    (uint32)CSL_GPIO0_BASE,
    (uint32)CSL_GPIO2_BASE,
    (uint32)CSL_GPIO4_BASE,
    (uint32)CSL_GPIO6_BASE,
};

#define DIO_STOP_SEC_CONST_32

#include "Dio_MemMap.h"

#define DIO_START_SEC_CONST_UNSPECIFIED

#include "Dio_MemMap.h"


/*The reserved pins are taken from Platform Specific TRM*/
DIO_VAR_CONST_UNSPECIFIED_SECTION
    static CONST(DioReservedPinListType, DIO_CONST) Dio_ReservedPinList[DIO_HW_UNIT_CNT] =
{
    [0] =
    {
        .regNum           = 0U,
        .numPins          = 72U,
        .reservedPinStart = 32U
    },
    [1] =
    {
        .regNum           = 1U,
        .numPins          = 72U,
        .reservedPinStart = 176U
    },
    [2] =
    {
        .regNum           = 2U,
        .numPins          = 75U,
        .reservedPinStart = 358U
    },
    [3] =
    {
        .regNum           = 3U,
        .numPins          = 75U,
        .reservedPinStart = 502U
    },
    [4] =
    {
        .regNum           = 4U,
        .numPins          = 75U,
        .reservedPinStart = 646U
    },
    [5] =
    {
        .regNum           = 5U,
        .numPins          = 75U,
        .reservedPinStart = 790U
    },
};

#define DIO_STOP_SEC_CONST_UNSPECIFIED
#include "Dio_MemMap.h"

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define DIO_START_SEC_CODE

#include "Dio_MemMap.h"


DIO_FUNC_TEXT_SECTION boolean Dio_isReservedPin(uint8 regNum, uint32 pinNum)
{
    boolean isReservedPin = (boolean) FALSE;
    uint8   i, flag = 0U;

    /*  In case of J7200 Reseved Pin List are not contiguous for WKUP Doamin.
        WKUP_GPIOu_[32:42], WKUP_GPIOu_[82:83], WKUP_GPIOu_[85:143] (u = 0, 1), and
        GPIOn_[69:143] (n = 0, 2, 4, 6) are reserved */
    if ((uint8)0U == regNum)
    {
        if (((pinNum >= DIO_WKUP0_RESERVED_PIN_START0) && (pinNum <= DIO_WKUP0_RESERVED_PIN_END0)) ||
             ((pinNum >= DIO_WKUP0_RESERVED_PIN_START1) && (pinNum <= DIO_WKUP0_RESERVED_PIN_END1)) ||
             ((pinNum >= DIO_WKUP0_RESERVED_PIN_START2) && (pinNum <= DIO_WKUP0_RESERVED_PIN_END2)))
            {
                isReservedPin = (boolean) TRUE;
                flag = 1U;
            }
    }
    else if ((uint8)1U == regNum)
    {
        if (((pinNum >= DIO_WKUP1_RESERVED_PIN_START0) && (pinNum <= DIO_WKUP1_RESERVED_PIN_END0)) ||
             ((pinNum >= DIO_WKUP1_RESERVED_PIN_START1) && (pinNum <= DIO_WKUP1_RESERVED_PIN_END1)) ||
             ((pinNum >= DIO_WKUP1_RESERVED_PIN_START2) && (pinNum <= DIO_WKUP1_RESERVED_PIN_END2)))
            {
                isReservedPin = (boolean) TRUE;
                flag = 1U;
            }
    }
    else
    {
        /* Do Nothing MISRA C Fix */
    }

    if (flag == 0U)
    {
        for (i = 2U; i < (uint8) DIO_UTILS_ARRAYSIZE(Dio_ReservedPinList); i++)
        {
            if (Dio_ReservedPinList[i].regNum == regNum)
            {
                if (Dio_ReservedPinList[i].reservedPinStart <= pinNum)
                    {
                        isReservedPin = (boolean) TRUE;
                        break;
                    }
            }
        }
        if (i == (uint8) DIO_UTILS_ARRAYSIZE(Dio_ReservedPinList))
        {
            isReservedPin = (boolean) FALSE;
        }
    }

    return isReservedPin;
}

#endif /* _MCAL8_5_UPDATE_ */

#define DIO_START_SEC_CODE

#include "Dio_MemMap.h"

DIO_FUNC_TEXT_SECTION uint32 Dio_getGPIOBaseAddr(uint8 regNum)
{
    return (Dio_GPIOBaseAddr[regNum]);
}

DIO_FUNC_TEXT_SECTION void Dio_UpdatePortInfoInternal(Dio_PortType PortId,
                                                     Dio_PortInfo * DioPortInfo)
{

    if((PortId >= DIO_MAX_PORT_ID_INSTANCE_2) &&
            (PortId < DIO_MAX_PORT_ID_INSTANCE_3))
    {
        DioPortInfo->Dio_InstanceId   = DIO_INSTANCE_3;
        DioPortInfo->Dio_PortId  = PortId - DIO_MAX_PORT_ID_INSTANCE_2;
    }
    else if((PortId >= DIO_MAX_PORT_ID_INSTANCE_3) &&
            (PortId < DIO_MAX_PORT_ID_INSTANCE_4))
    {
        DioPortInfo->Dio_InstanceId   = DIO_INSTANCE_4;
        DioPortInfo->Dio_PortId  = PortId - DIO_MAX_PORT_ID_INSTANCE_3;
    }
    else if((PortId >= DIO_MAX_PORT_ID_INSTANCE_4) &&
            (PortId < DIO_MAX_PORT_ID_INSTANCE_5))
    {
        DioPortInfo->Dio_InstanceId   = DIO_INSTANCE_5;
        DioPortInfo->Dio_PortId  = PortId - DIO_MAX_PORT_ID_INSTANCE_4;
    }
    else
    {
        /*Do Nothing*/
    }

}

#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"