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
 *  \file     Dio_PlatformJ721e.c
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

/* None */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */
typedef struct {
    uint8 regNum;
    uint8 numPins;
    uint32 reservedPinStart;
} DioReservedPinListType;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
#define DIO_START_SEC_CONST_32

#include "Dio_MemMap.h"


DIO_VAR_CONST_32_SECTION static CONST(uint32, DIO_CONST)
    Dio_GPIOBaseAddr[DIO_HW_UNIT_CNT] =
{
    (uint32)CSL_WKUP_GPIO0_BASE,
    (uint32)CSL_WKUP_GPIO1_BASE,
    (uint32)CSL_GPIO0_BASE,
    (uint32)CSL_GPIO1_BASE,
    (uint32)CSL_GPIO2_BASE,
    (uint32)CSL_GPIO3_BASE,
    (uint32)CSL_GPIO4_BASE,
    (uint32)CSL_GPIO5_BASE,
    (uint32)CSL_GPIO6_BASE,
    (uint32)CSL_GPIO7_BASE,
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
        .numPins          = 60U,
        .reservedPinStart = 84U
    },
    [1] =
    {
        .regNum           = 1U,
        .numPins          = 60U,
        .reservedPinStart = 204U
    },
    [2] =
    {
        .regNum           = 2U,
        .numPins          = 16U,
        .reservedPinStart = 416U
    },
    [3] =
    {
        .regNum           = 3U,
        .numPins          = 108U,
        .reservedPinStart = 468U
    },
    [4] =
    {
        .regNum           = 4U,
        .numPins          = 16U,
        .reservedPinStart = 704U
    },
    [5] =
    {
        .regNum           = 5U,
        .numPins          = 108U,
        .reservedPinStart = 756U
    },
    [6] =
    {
        .regNum           = 6U,
        .numPins          = 16U,
        .reservedPinStart = 992U
    },
    [7] =
    {
        .regNum           = 7U,
        .numPins          = 108U,
        .reservedPinStart = 1044U
    },
    [8] =
    {
        .regNum           = 8U,
        .numPins          = 16U,
        .reservedPinStart = 1280U
    },
    [9] =
    {
        .regNum           = 9U,
        .numPins          = 108U,
        .reservedPinStart = 1332U
    },
};

#define DIO_STOP_SEC_CONST_UNSPECIFIED
#include "Dio_MemMap.h"

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define DIO_START_SEC_CODE

#include "Dio_MemMap.h"

DIO_FUNC_TEXT_SECTION uint32 Dio_getGPIOBaseAddr(uint8 regNum)
{
    return (Dio_GPIOBaseAddr[regNum]);
}

DIO_FUNC_TEXT_SECTION boolean Dio_isReservedPin(uint8 regNum, uint32 pinNum)
{
    boolean isReservedPin = (boolean) FALSE;
    uint8   i;
    for (i = 0U; i < (uint8) DIO_UTILS_ARRAYSIZE(Dio_ReservedPinList); i++)
    {
        if (Dio_ReservedPinList[i].regNum == regNum)
        {
            if (Dio_ReservedPinList[i].reservedPinStart <= pinNum)
                {
                    isReservedPin = (boolean) TRUE;
                    break;
                }
            else
            {
                /*Do Nothing*/
            }
        }
        else
        {
            /*Do Nothing*/
        }
    }
    if (i == (uint8) DIO_UTILS_ARRAYSIZE(Dio_ReservedPinList))
    {
        isReservedPin = (boolean) FALSE;
    }
    else
    {
        /*Do Nothing*/
    }
    return isReservedPin;
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
    else if((PortId >= DIO_MAX_PORT_ID_INSTANCE_5) &&
            (PortId < DIO_MAX_PORT_ID_INSTANCE_6))
    {
        DioPortInfo->Dio_InstanceId   = DIO_INSTANCE_6;
        DioPortInfo->Dio_PortId  = PortId - DIO_MAX_PORT_ID_INSTANCE_5;
    }
    else if((PortId >= DIO_MAX_PORT_ID_INSTANCE_6) &&
            (PortId < DIO_MAX_PORT_ID_INSTANCE_7))
    {
        DioPortInfo->Dio_InstanceId   = DIO_INSTANCE_7;
        DioPortInfo->Dio_PortId  = PortId - DIO_MAX_PORT_ID_INSTANCE_6;
    }
    else if((PortId >= DIO_MAX_PORT_ID_INSTANCE_7) &&
            (PortId < DIO_MAX_PORT_ID_INSTANCE_8))
    {
        DioPortInfo->Dio_InstanceId   = DIO_INSTANCE_8;
        DioPortInfo->Dio_PortId  = PortId - DIO_MAX_PORT_ID_INSTANCE_7;
    }
    else if((PortId >= DIO_MAX_PORT_ID_INSTANCE_8) &&
            (PortId < DIO_MAX_PORT_ID_INSTANCE_9))
    {
        DioPortInfo->Dio_InstanceId   = DIO_INSTANCE_9;
        DioPortInfo->Dio_PortId  = PortId - DIO_MAX_PORT_ID_INSTANCE_8;
    }
    else
    {
        /*Do Nothing*/
    }

}

#define DIO_STOP_SEC_CODE

#include "Dio_MemMap.h"
