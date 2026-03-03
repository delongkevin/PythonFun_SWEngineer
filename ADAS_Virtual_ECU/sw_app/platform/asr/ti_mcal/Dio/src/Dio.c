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
 *  \file     Dio.c
 *
 *  \brief    This file contains DIO MCAL driver
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
/* Requirements : MCAL-1090 */
#include "Dio.h"
#include "Dio_Priv.h"
#include "SchM_Dio.h"

/* Requirements : MCAL-1090, MCAL-1092 */
#if (DIO_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/* Include to use the CSL library read/writes*/
#include <ti/csl/csl_gpio.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* AUTOSAR version information check has to match definition in header file */
#if ((DIO_AR_RELEASE_MAJOR_VERSION != (0x04U)) || \
    (DIO_AR_RELEASE_MINOR_VERSION != (0x03U)) ||  \
    (DIO_AR_RELEASE_REVISION_VERSION != (0x01U)))
    #error "AUTOSAR Version Numbers of Dio are different"
#endif

/* AUTOSAR version information check has to match definition in header file */
#if ((DIO_SW_MAJOR_VERSION != (2U)) || (DIO_SW_MINOR_VERSION != (0U)))
  #error "Version numbers of Dio.c and Dio.h are inconsistent!"
#endif

#define DIO_READ_PORT_MASK              (0xFFFFFFFFU)

/* To Return 0 when Improper ID is passed to Read functions */
#define DIO_RETURN_ZERO                        (0U)

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
static void Dio_UpdateChannelInfo( Dio_ChannelType ChannelId,
                                   Dio_ChannelInfo * DioChannelInfo);
static void Dio_UpdatePortInfo(Dio_PortType PortId, Dio_PortInfo * DioPortInfo);
static Dio_LevelType Dio_pinRead(const Dio_ChannelInfo * DioChannelInfo);
static void Dio_pinWrite(const Dio_ChannelInfo * DioChannelInfo,
                         Dio_LevelType level);
static void Dio_multiplePinsWrite(const Dio_PortInfo * DioPortInfo,
                                  uint32 setMask,
                                  uint32 clrMask);
static void Dio_gioReadPort(Dio_PortType portId, uint32 *portVal);
static void Dio_gioWritePort(Dio_PortType portId, uint32 Level);
#if (DIO_WRITE_CHANNEL_EVENT_ID != DIO_DEM_NO_EVENT)
static Std_ReturnType Dio_checkIO(Dio_ChannelType ChannelId,
                                  Dio_LevelType   level);
#endif
#if (STD_ON == DIO_DEV_ERROR_DETECT)
static Std_ReturnType Dio_checkChannelValidity(const Dio_ChannelInfo * DioChannelInfo,
                                                Dio_ChannelType ChannelId);
static inline void Dio_reportDetError(uint8 apiId, uint8 errorId);
#endif  /* #if (STD_ON == DIO_DEV_ERROR_DETECT) */
#if (DIO_WRITE_CHANNEL_EVENT_ID != DIO_DEM_NO_EVENT)
static void Dio_writechannel_check(Dio_DirectionType Dio_Dir, Dio_ChannelType ChannelId,
                       Dio_LevelType Level);
#endif
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
#if defined _MCAL8_5_UPDATE_ /* Redefination in Dio_cfg */
#if (STD_ON == DIO_DEV_ERROR_DETECT)

#define DIO_START_SEC_CONST_32
#include "Dio_MemMap.h"

DIO_VAR_CONST_32_SECTION
static const uint32 Dio_PortIdInstance[DIO_HW_UNIT_CNT] =
{
    (uint32)0U,
    (uint32)DIO_MAX_PORT_ID_INSTANCE_0,
    (uint32)DIO_MAX_PORT_ID_INSTANCE_1,
#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)
	(uint32)DIO_MAX_PORT_ID_INSTANCE_2,
	(uint32)DIO_MAX_PORT_ID_INSTANCE_3,
	(uint32)DIO_MAX_PORT_ID_INSTANCE_4,
#if defined (SOC_J721E)
	(uint32)DIO_MAX_PORT_ID_INSTANCE_5,
	(uint32)DIO_MAX_PORT_ID_INSTANCE_6,
	(uint32)DIO_MAX_PORT_ID_INSTANCE_7,
	(uint32)DIO_MAX_PORT_ID_INSTANCE_8,
#endif /* #if defined (SOC_J721E) */
#endif /* #if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)*/
};

#define DIO_STOP_SEC_CONST_32
#include "Dio_MemMap.h"

#endif /* (STD_ON == DIO_DEV_ERROR_DETECT) */
#endif /* _MCAL8_5_UPDATE_ */
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

#if (STD_ON == DIO_VERSION_INFO_API)
/**
 *\brief   This function is used to get the version information of DIO module
 *
 */
/* Design : DES_DIO_012 */
/* Requirements : MCAL-1166, MCAL-1124 */
DIO_FUNC_TEXT_SECTION FUNC(void, DIO_CODE)  Dio_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DIO_APPL_DATA) versioninfo)
{
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    if (NULL_PTR == versioninfo)
    {
        /* Requirements : MCAL-1167 */
        Dio_reportDetError(DIO_SID_GET_VERSION_INFO, DIO_E_PARAM_POINTER);
    }
    else
#endif
    {
        versioninfo->vendorID         = (uint16) DIO_VENDOR_ID;
        versioninfo->moduleID         = (uint16) DIO_MODULE_ID;
        versioninfo->sw_major_version = (uint8)  DIO_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)  DIO_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)  DIO_SW_PATCH_VERSION;
    }
    return;
}
#endif  /*(STD_ON == DIO_VERSION_INFO_API)*/

/**
 *\brief   This function is used to read from a channel
 *
 */
/* Design : DES_DIO_005 */
/* Requirements : MCAL-1143 */
DIO_FUNC_TEXT_SECTION FUNC(Dio_LevelType, DIO_CODE) Dio_ReadChannel(
    Dio_ChannelType ChannelId)
{
    Dio_ChannelInfo Dio_ReadChannelInfo;
    Dio_UpdateChannelInfo(ChannelId, &Dio_ReadChannelInfo);
    /* Requirements : MCAL-1114 */
    Dio_LevelType chLevelVal = (Dio_LevelType) DIO_RETURN_ZERO;
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /* Requirements : MCAL-1121 */
    if ((((Std_ReturnType) E_OK) != Dio_checkChannelValidity(&Dio_ReadChannelInfo,
                                    ChannelId)))
    {
        Dio_reportDetError(
            DIO_SID_READ_CHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
#endif
    {
        SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_0();
        /* Requirements : MCAL-1096, MCAL-1113, MCAL-1115,
         * MCAL-1118, MCAL-1144 */
        chLevelVal = Dio_pinRead(&Dio_ReadChannelInfo);
        SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_0();
    }
    return (chLevelVal);
}

/**
 *\brief   This function is used to write a value to a channel
 *
 */
/* Design : DES_DIO_006 */
/* Requirements : MCAL-1145 ,MCAL-1107 */
DIO_FUNC_TEXT_SECTION FUNC(void, DIO_CODE) Dio_WriteChannel(
    Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    Dio_ChannelInfo Dio_WriteChannelInfo;
    Dio_UpdateChannelInfo(ChannelId, &Dio_WriteChannelInfo);

#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /* Requirements : MCAL-1121 */
    if ((((Std_ReturnType) E_OK) != Dio_checkChannelValidity(&Dio_WriteChannelInfo,
                                                            ChannelId)))
    {
        /* ChannelId is NOT valid */
        Dio_reportDetError(DIO_SID_WRITE_CHANNEL,
                           DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    /* Requirements : MCAL-1108 */
    else
#endif
    {
        /* Requirements : MCAL-1094, MCAL-1100 */
        SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_0();
        /* Requirements : MCAL-1096, MCAL-1105, MCAL-1106 , MCAL-1146*/
        if (DIO_DIR_OUTPUT == (Dio_WriteChannelInfo.Dio_Direction))
        {
            /* Write to Channel if direction is OUTPUT. */
            Dio_pinWrite(&Dio_WriteChannelInfo, Level);
        }
        /* Requirements : MCAL-1147, MCAL-1148 */
        else
        {
              /* else case for input channel : Do Nothing */
        }
        /* Requirements : MCAL-1094 */
        SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_0();
#if (DIO_WRITE_CHANNEL_EVENT_ID != DIO_DEM_NO_EVENT)
        Dio_writechannel_check(Dio_WriteChannelInfo.Dio_Direction,ChannelId,Level);
#endif
    }
    return;
}

/**
 *\brief   This function is used to read the value from a port
 *
 */
/* Design : DES_DIO_007 */
/* Requirements : MCAL-1149, MCAL-1151 */
DIO_FUNC_TEXT_SECTION FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadPort(
    Dio_PortType PortId)
{
    /* Requirements : MCAL-1114, MCAL-1150 */
    Dio_PortLevelType portVal = (Dio_PortLevelType) DIO_RETURN_ZERO;
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /* Requirements : MCAL-1122 */
    if (0U == (DIO_ENABLED_PORT_MASK & ((uint32)1U << PortId)))
    {
        /* PortId is NOT valid */
        Dio_reportDetError(
            DIO_SID_READ_PORT, DIO_E_PARAM_INVALID_PORT_ID);
    }
    else
#endif
    {
        SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_0();
      /* Requirements : MCAL-1150 */
        Dio_gioReadPort(PortId, &portVal);
        SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_0();
    }
    return (portVal);
}

/**
 *\brief   This function is used to write a value to a port
 *
 */
 /* Design : DES_DIO_008 */
/* Requirements : MCAL-1152 */
DIO_FUNC_TEXT_SECTION FUNC(void, DIO_CODE) Dio_WritePort(
    Dio_PortType PortId, Dio_PortLevelType Level)
{
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /* Requirements : MCAL-1122 */
    if (0U == (DIO_ENABLED_PORT_MASK & ((uint32)1U << PortId)))
    {
        /* PortId is NOT valid  */
        Dio_reportDetError( DIO_SID_WRITE_PORT,
                            DIO_E_PARAM_INVALID_PORT_ID);
    }
    /* Requirements : MCAL-1108 */
    else
#endif
    {
        /* Requirements : MCAL-1094, MCAL-1100 */
        SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_0();
        /* Requirements : MCAL-1153 */
        Dio_gioWritePort(PortId, Level);
        /* Requirements : MCAL-1094, MCAL-1100 */
        SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_0();
    }
    return;
}

/**
 *\brief   This function is used to read a value to a channel group
 *
 */
/* Design : DES_DIO_009 */
/* Requirements : MCAL-1157 */
DIO_FUNC_TEXT_SECTION FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadChannelGroup
    (const Dio_ChannelGroupType *ChannelGroupIdPtr)
{
    /* Requirements : MCAL-1114 */
    Dio_PortLevelType portLevelVal = (Dio_PortLevelType) DIO_RETURN_ZERO;
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /* Requirements : MCAL-1123 */
    if (NULL_PTR == ChannelGroupIdPtr)
    {
        /* null pointer is referenced by the parameter */
        Dio_reportDetError( DIO_SID_READ_CHL_GROUP,
                            DIO_E_PARAM_INVALID_GROUP);
    }
    else
#endif
    {
        SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_0();
        /* Requirements : MCAL-1117 ,MCAL-1150 */
        Dio_gioReadPort(ChannelGroupIdPtr->port, &portLevelVal);
        SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_0();
        /* Requirements : MCAL-1158, MCAL-1159 */
        portLevelVal &= ChannelGroupIdPtr->mask;
        /* Requirements : MCAL-1160 */
        portLevelVal >>= ChannelGroupIdPtr->offset;
    }
    return (portLevelVal);
}

/**
 *\brief   This function is used to write a value to a channel group
 *
 */
/* Design : DES_DIO_010 */
/* Requirements : MCAL-1161 */
DIO_FUNC_TEXT_SECTION FUNC(void, DIO_CODE) Dio_WriteChannelGroup(
    const Dio_ChannelGroupType *ChannelGroupIdPtr, Dio_PortLevelType Level)
{
    uint32 portLevelVal;
    uint32 newValue;
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /* Requirements : MCAL-1123 */
    if (NULL_PTR == ChannelGroupIdPtr)
    {
        /* null pointer is referenced by the parameter */
        Dio_reportDetError( DIO_SID_WRITE_CHL_GROUP,
                            DIO_E_PARAM_INVALID_GROUP);
    }
    /* Requirements : MCAL-1108 */
    else
#endif
    {
        uint8 groupoffset;
        /* Requirements : MCAL-1094, MCAL-1100 */
        SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_0();
        groupoffset = ChannelGroupIdPtr->offset;
        /* Requirements : MCAL-1162, MCAL-1165 */
        newValue = ((Level << groupoffset) & ChannelGroupIdPtr->mask);
        Dio_gioReadPort(ChannelGroupIdPtr->port, &portLevelVal);
        /* Requirements : MCAL-1112, MCAL-1164 */
        /* clear old value of this channel group and apply new levels */
        portLevelVal &= (~ChannelGroupIdPtr->mask);
        portLevelVal |= newValue;
        Dio_gioWritePort(ChannelGroupIdPtr->port, portLevelVal);
        /* Requirements : MCAL-1094, MCAL-1100 */
        SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_0();
    }
    return;
}

#if (STD_ON == DIO_FLIP_CHANNEL_API)
/**
 *\brief   This function is used to flip the value of a pin
 *
 */
/* Design : DES_DIO_011 */
/* Requirements : MCAL-1168, MCAL-1170, MCAL-1171 */
DIO_FUNC_TEXT_SECTION FUNC(Dio_LevelType, DIO_CODE) Dio_FlipChannel(
    Dio_ChannelType ChannelId)
{
    Dio_ChannelInfo Dio_FlipChannelInfo;
    Dio_UpdateChannelInfo(ChannelId, &Dio_FlipChannelInfo);
    Dio_LevelType channelVal = (Dio_LevelType) DIO_RETURN_ZERO;
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    if ((((Std_ReturnType) E_OK) != Dio_checkChannelValidity(&Dio_FlipChannelInfo,
                                                             ChannelId)))
    {
        /* ChannelId is NOT valid */
        Dio_reportDetError(
            DIO_SID_FLIP_CHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    /* Requirements : MCAL-1108 */
    else
#endif
    {
        Dio_LevelType     flipValue;
        /* Requirements : MCAL-1169, MCAL-1096, MCAL-1113,
         * MCAL-1115, MCAL-1118, MCAL-1144 */
        /*Read the channel value*/
        flipValue = Dio_pinRead(&Dio_FlipChannelInfo);
        /* Requirements : MCAL-1170 */
        if (DIO_DIR_OUTPUT == Dio_FlipChannelInfo.Dio_Direction)
        {
            /*Check if the level is logic HIGH, store the inverted level*/
            if (((Dio_LevelType) STD_HIGH) == flipValue)
            {
                flipValue = (Dio_LevelType) STD_LOW;
            }
            else
            {
                flipValue = (Dio_LevelType) STD_HIGH;
            }
            /*Write back the inverted level value*/
            Dio_pinWrite(&Dio_FlipChannelInfo, flipValue);
            /*Update the return value*/
            channelVal = Dio_pinRead(&Dio_FlipChannelInfo);
        }
        else
        {
            /* Input channel can't change value */
            /* Requirements : MCAL-1171 */
            channelVal = flipValue;
        }
    }
    return (channelVal);
}
#endif /*(STD_ON == DIO_FLIP_CHANNEL_API)*/

#if (STD_ON == DIO_REGISTER_READBACK_API)
/**
 *\brief   This function is used to readback some critical DIO registers
 *
 */
DIO_FUNC_TEXT_SECTION FUNC(uint32, DIO_CODE) Dio_RegisterReadback(
            Dio_ChannelType ChannelId)
{
    uint32 Dio_pid;
    Dio_ChannelInfo Dio_ReadBackChannelInfo;
    Dio_UpdateChannelInfo(ChannelId, &Dio_ReadBackChannelInfo);
    /*checking the status of GPIO_PID register: offset=0 refer trm*/
    Dio_pid = CSL_REG32_RD((uint32)((Dio_ReadBackChannelInfo.baseaddr)+CSL_GPIO_PID));
    return (Dio_pid);
}
#endif  /* #if (STD_ON == DIO_REGISTER_READBACK_API) */

/**************************************************************************/
/********************    Internal Functions *******************************/
/**************************************************************************/

/**
 *\brief   This function is used to update the channel structure
 *
 */
static void Dio_UpdateChannelInfo(Dio_ChannelType ChannelId,
                                   Dio_ChannelInfo * DioChannelInfo)
{
    CSL_GpioHandle hGpio;
    uint8 dioInstanceId = 0U;
    uint8 dioPinNum = 0U;
    Dio_PortType dioportId = 0U;
    uint32 pin_dir = 0U;
    /* Calculate the instance id, pin num and port num inside the instance */
    /* Below is calculated assuming number of pins in each instance is same.
     * Need to revisit this logic if number of pins is different */
    dioInstanceId = (uint8) (ChannelId / DIO_MAX_PIN_ID_INSTANCE_0);
    dioPinNum     = (uint8) ((ChannelId % DIO_MAX_PIN_ID_INSTANCE_0) %
                                DIO_PORT_WIDTH);
    dioportId     = (uint8) ((ChannelId % DIO_MAX_PIN_ID_INSTANCE_0) /
                                DIO_PORT_WIDTH);

    /*calculate the base address based on the instance*/
    DioChannelInfo->baseaddr   = Dio_getGPIOBaseAddr(dioInstanceId);
    /*update the information based on the instance*/
    DioChannelInfo->Dio_PinNum = dioPinNum;
    DioChannelInfo->Dio_PortId = dioportId;
    DioChannelInfo->Dio_InstanceId = dioInstanceId;
    /*Update the Direction*/
    hGpio = (CSL_GpioHandle)DioChannelInfo->baseaddr;
    pin_dir = (uint32)(CSL_FEXTR(hGpio->BANK_REGISTERS[dioportId].DIR,
                        (uint32)dioPinNum, (uint32)dioPinNum));
    if ((uint32)DIO_DIR_OUTPUT == pin_dir)
    {
        DioChannelInfo->Dio_Direction = DIO_DIR_OUTPUT;
    }
    else
    {
        DioChannelInfo->Dio_Direction = DIO_DIR_INPUT;
    }
}

/**
 *\brief   This function is used to update the port structure
 *
 */
DIO_FUNC_TEXT_SECTION static void Dio_UpdatePortInfo (Dio_PortType PortId,
                                                     Dio_PortInfo * DioPortInfo)
{
    CSL_GpioHandle hGpio;
    /*Update Instance ID and portId inside the instance*/
    if (PortId < DIO_MAX_PORT_ID_INSTANCE_0)
    {
        DioPortInfo->Dio_InstanceId = DIO_INSTANCE_0;
        DioPortInfo->Dio_PortId  = PortId;
    }
    else if((PortId >= DIO_MAX_PORT_ID_INSTANCE_0) &&
            (PortId < DIO_MAX_PORT_ID_INSTANCE_1))
    {
        DioPortInfo->Dio_InstanceId   = DIO_INSTANCE_1;
        DioPortInfo->Dio_PortId  = PortId - DIO_MAX_PORT_ID_INSTANCE_0;
    }
    else if((PortId >= DIO_MAX_PORT_ID_INSTANCE_1) &&
            (PortId < DIO_MAX_PORT_ID_INSTANCE_2))
    {
        DioPortInfo->Dio_InstanceId   = DIO_INSTANCE_2;
        DioPortInfo->Dio_PortId  = PortId - DIO_MAX_PORT_ID_INSTANCE_1;
    }
    else
    {
        /*Do Nothing*/
    }
#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)
    Dio_UpdatePortInfoInternal(PortId, DioPortInfo);
#endif

    /*Update the Base Address*/
    DioPortInfo->baseaddr   = Dio_getGPIOBaseAddr(DioPortInfo->Dio_InstanceId);
     /*Update the Direction*/
    hGpio = (CSL_GpioHandle)(DioPortInfo->baseaddr);
    DioPortInfo->Dio_PortDirection = (hGpio->BANK_REGISTERS[
                                      DioPortInfo->Dio_PortId].DIR);
}

DIO_FUNC_TEXT_SECTION static void Dio_gioReadPort(Dio_PortType portId, uint32 *portVal)
{
    Dio_PortInfo  Dio_ReadPortInfo;
    CSL_GpioHandle hGpio;
    Dio_UpdatePortInfo(portId, &Dio_ReadPortInfo);
    hGpio = (CSL_GpioHandle)(Dio_ReadPortInfo.baseaddr);
    *portVal = 0U;
    /* Requirements : MCAL-1116 */
    /*to be removed once readback issue is resolved*/
#if (DIO_MCAL_2139_FIXED == 0U)
    uint32 Dio_port_in;
    uint32 Dio_port_out;
    uint32 Dio_portdir;
    Dio_port_out = ((hGpio->BANK_REGISTERS[Dio_ReadPortInfo.Dio_PortId].OUT_DATA));
    Dio_port_in = ((hGpio->BANK_REGISTERS[Dio_ReadPortInfo.Dio_PortId].IN_DATA)) ;
    Dio_portdir = Dio_ReadPortInfo.Dio_PortDirection;
    *portVal = ((Dio_portdir & Dio_port_in) | (~Dio_portdir & Dio_port_out))&
                DIO_READ_PORT_MASK;
#else
    *portVal = ((hGpio->BANK_REGISTERS[Dio_ReadPortInfo.Dio_PortId].IN_DATA)) &
                DIO_READ_PORT_MASK;
#endif
}

/**
 *\brief   This function is used to write to a port
 *
 */
/* Requirements : MCAL-1155 */
DIO_FUNC_TEXT_SECTION static void Dio_gioWritePort(Dio_PortType portId,
                                                    uint32 Level)
{
    uint32 outputPinMask;
    uint32 setBits, clearBits;
    CSL_GpioHandle hGpio;
    Dio_PortInfo  Dio_WritePortInfo;
    Dio_UpdatePortInfo(portId, &Dio_WritePortInfo);
    hGpio = (CSL_GpioHandle)Dio_WritePortInfo.baseaddr;

    /* Getting the Direction of pins */
    outputPinMask = (hGpio->BANK_REGISTERS[Dio_WritePortInfo.Dio_PortId].DIR);
    /* Output pins are 0 in DIR register */
    outputPinMask = ~outputPinMask;
    /* Requirements : MCAL-1111, MCAL-1154, MCAL-1156 , MCAL-1163 */
    /* clear channels which are not output to 0 */
    setBits   = Level & outputPinMask;
    clearBits = ~Level & outputPinMask;
    /* Requirements : MCAL-1140, MCAL-1156 */
    Dio_multiplePinsWrite(&Dio_WritePortInfo, setBits, clearBits);
#if (DIO_WRITE_PORT_EVENT_ID != DIO_DEM_NO_EVENT)
    uint32 dioDirection;
    Dio_PortLevelType portVal;
    uint32 chId;
    dioDirection = Dio_WritePortInfo.Dio_PortDirection;
    Dio_gioReadPort(portId, &portVal);
    for (chId = 0U; chId < DIO_PORT_WIDTH; chId++)
    {
        if (DIO_DIR_OUTPUT == (dioDirection & (((uint32)1U) << chId)))
        {
        /*If a channel is not configured as input only, do IO check*/
            if ((Level & (((uint32)1U) << chId)) !=
                (portVal & (((uint32)1U) << chId)))
            {
                /* Requirements : MCAL-1124, MCAL-1172 */
                (void)Dem_SetEventStatus((Dem_EventIdType) DIO_WRITE_PORT_EVENT_ID,
                                  (uint8) DEM_EVENT_STATUS_FAILED);
                break;
            }
        }
    }
#endif
}

/**
 *\brief   This function is used to after pin write to confirm if correct
 * value is written
 *
 */
#if (DIO_WRITE_CHANNEL_EVENT_ID != DIO_DEM_NO_EVENT)
DIO_FUNC_TEXT_SECTION static Std_ReturnType Dio_checkIO(
    Dio_ChannelType ChannelId, Dio_LevelType   level)
{
    Dio_LevelType  newLevel;
    Std_ReturnType Status = (Std_ReturnType) E_OK;
    newLevel = Dio_ReadChannel(ChannelId);
    if (level != newLevel)
    {
        Status = (Std_ReturnType) E_NOT_OK;
    }
    return (Status);
}
#endif

/**
 *\brief   This function is used to check if specified GPIO pin is not reserved
 *         and valid
 *
 */
#if (STD_ON == DIO_DEV_ERROR_DETECT)
DIO_FUNC_TEXT_SECTION static Std_ReturnType Dio_checkChannelValidity(
    const Dio_ChannelInfo * DioChannelInfo, Dio_ChannelType ChannelId)
{
    uint32          maxNumPorts,dioabsPortd;
    boolean        isReservedPin;
    Std_ReturnType retVal = (Std_ReturnType) E_OK;

    /* Updating the absolute Port ID */
    if (DioChannelInfo->Dio_InstanceId <= DIO_MAX_INSTANCE_ID)
    {
        dioabsPortd = Dio_PortIdInstance[DioChannelInfo->Dio_InstanceId] +
                        DioChannelInfo->Dio_PortId;
    }
    else
    {
        retVal = (Std_ReturnType) E_NOT_OK;
    }

    if (retVal == (Std_ReturnType) E_OK)
    {
        maxNumPorts = (uint8)(sizeof(Dio_ConfigValidChannelMask) / sizeof(uint32));
        /*checking for reserved pin, specific to device, refer TRM*/
        isReservedPin = Dio_isReservedPin(DioChannelInfo->Dio_InstanceId,
                                          ChannelId);
        /*if pin is not reserved, check if the pin has been configured(valid)*/
        if ((isReservedPin != (boolean)TRUE))
        {
            if (dioabsPortd < maxNumPorts)
            {
                if (0U != ((uint32)(Dio_ConfigValidChannelMask[dioabsPortd]) &
                           ((uint32)((uint32)1U << DioChannelInfo->Dio_PinNum))))
                {
                    retVal = (Std_ReturnType) E_OK;
                }
            }
        }
        else
        {
            retVal = (Std_ReturnType) E_NOT_OK;
        }
    }
    return (retVal);
}
#endif

/**
 *\brief This function determines the logic level(value) on a specified
 *       GPIO pin.
  */
DIO_FUNC_TEXT_SECTION static Dio_LevelType Dio_pinRead(const Dio_ChannelInfo * DioChannelInfo)
{
    uint32        regVal;
    Dio_LevelType retVal;
    uint8       bitPos;
    CSL_GpioHandle hGpio;
    hGpio = (CSL_GpioHandle)(DioChannelInfo->baseaddr);
    bitPos = (uint8)((DioChannelInfo->Dio_PinNum) % DIO_PORT_WIDTH);

    /*to be removed after the read back is confirmed*/
     /* MCAL-1119*/
#if (DIO_MCAL_2139_FIXED == 0U)
    if (DIO_DIR_OUTPUT == DioChannelInfo->Dio_Direction)
    {
        regVal = (Uint8)CSL_FEXTR (
                     hGpio->BANK_REGISTERS[DioChannelInfo->Dio_PortId].OUT_DATA,
                                    (uint32)bitPos, (uint32)bitPos);
    }
    else
#endif
    {
        /* Requirements : MCAL-1093, MCAL-1095 */
        regVal = (Uint8)CSL_FEXTR (
                     hGpio->BANK_REGISTERS[DioChannelInfo->Dio_PortId].IN_DATA,
                                    (uint32)bitPos, (uint32)bitPos);
    }
    /* Requirements : MCAL-1138 */
    if (regVal != 0U)
    {
        retVal = (Dio_LevelType) STD_HIGH;
    }
    else
    {
        retVal = (Dio_LevelType) STD_LOW;
    }
    return (retVal);
}

/**
 *\brief   This function is used to set and clear the
 *         specified output pins of a GPIO pin.
 *
 */
/* Requirements : MCAL-1093 */
DIO_FUNC_TEXT_SECTION static void Dio_pinWrite(const Dio_ChannelInfo * DioChannelInfo,
                                               Dio_LevelType level)
{
    uint8       bitPos;
    bitPos = (uint8)((DioChannelInfo->Dio_PinNum) % DIO_PORT_WIDTH);
    CSL_GpioHandle hGpio;
    hGpio = (CSL_GpioHandle)DioChannelInfo->baseaddr;
    /* Requirements : MCAL-1095, MCAL-1109 */
    if (((Dio_LevelType) STD_HIGH) == level)
    {
        hGpio->BANK_REGISTERS[DioChannelInfo->Dio_PortId].SET_DATA =
                                               (uint32)((uint32)(1U) << bitPos);
    }
    else
    {
        hGpio->BANK_REGISTERS[DioChannelInfo->Dio_PortId].CLR_DATA =
                                                (uint32)((uint32)(1U) << bitPos);
    }
    return;
}

/**
 *\brief   This function is used to collectively set and collectively clear the
 *         specified output pins of a GPIO instance.
 *
 */
DIO_FUNC_TEXT_SECTION static void Dio_multiplePinsWrite(const Dio_PortInfo * DioPortInfo,
                                  uint32 setMask,
                                  uint32 clrMask)
{
    CSL_GpioHandle hGpio;
    hGpio = (CSL_GpioHandle)(DioPortInfo->baseaddr);
    /* Requirements : MCAL-1110, MCAL-1156 */
    /* Setting the specified output pins in GPIO_DATAOUT register. */
    hGpio->BANK_REGISTERS[DioPortInfo->Dio_PortId].SET_DATA = setMask;
    /* Clearing the specified output pins in GPIO_DATAOUT register. */
    hGpio->BANK_REGISTERS[DioPortInfo->Dio_PortId].CLR_DATA = clrMask;
    return;
}

#if (STD_ON == DIO_DEV_ERROR_DETECT)
DIO_FUNC_TEXT_SECTION static inline void Dio_reportDetError(
    uint8 apiId, uint8 errorId)
{
    /* Requirements : MCAL-1172 */
    (void) Det_ReportError(DIO_MODULE_ID, 0U, apiId, errorId);
    return;
}
#endif  /* #if (STD_ON == DIO_DEV_ERROR_DETECT) */
/**
 *\brief   This function is checks the channel is not configured as input and performs
*  IO check */

#if (DIO_WRITE_CHANNEL_EVENT_ID != DIO_DEM_NO_EVENT)
static void Dio_writechannel_check(Dio_DirectionType Dio_Dir,
                                    Dio_ChannelType ChannelId,
                                    Dio_LevelType Level)
{
        if (DIO_DIR_OUTPUT == Dio_Dir)
        {
            if (((Std_ReturnType) E_NOT_OK) == Dio_checkIO(ChannelId, Level))
            {
                /* Requirements : MCAL-1124, MCAL-1172 */
                (void)Dem_SetEventStatus(
                    (Dem_EventIdType) DIO_WRITE_CHANNEL_EVENT_ID,
                    (uint8) DEM_EVENT_STATUS_FAILED);
            }
            else
            {
              /* else case : Do Nothing */
            }
        }
        else
        {
              /* else case for input channel : Do Nothing */
        }
}
#endif
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
