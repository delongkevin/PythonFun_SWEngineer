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
 *  \file     DioApp.c
 *
 *  \brief    This file contains the DIO test example
 */

/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
/* Include Files */
#include "stdio.h"

#include "Dio.h"
#include "SchM_Dio.h"

#include <ti/csl/soc.h>
#include <ti/csl/csl_gpio.h>
#include <ti/csl/arch/csl_arch.h>
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/**< SoC & C++ Build compatible */
#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)
#define PRAGMA(x) _Pragma(#x)
#ifdef __cplusplus
#define DATAPRAGMA(f,s) PRAGMA(DATA_SECTION(s))
#else
#define DATAPRAGMA(f,s) PRAGMA(DATA_SECTION(f, s))
#endif
#endif /* #if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2) */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static void DioApp_McuDomainPinMux(uint32 offset, uint32 muxmode);
static void DioApp_unlockMmrRegisters(uint32 lockKey0, uint32 lockKey1);
static void Can14EnableCondtion(void);
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
uint32                          DIO_TestPassed = E_OK;
/*Global to inidicate status of APP */
#if (STD_ON == DIO_VERSION_INFO_API)
Std_VersionInfoType       DIO_VersionInfo;
#endif

/* GPIO Version Information */
#define DIO_START_SEC_CONST_32
#include "Dio_MemMap.h"
DIO_VAR_CONST_32_SECTION static CONST(uint32, DIO_CONST)
    DIO_GPIOBaseAddr[DIO_HW_UNIT_CNT] =
{
#if defined (SOC_J721E)
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
#elif defined (SOC_J7200)
    (uint32)CSL_WKUP_GPIO0_BASE,
    (uint32)CSL_WKUP_GPIO1_BASE,
    (uint32)CSL_GPIO0_BASE,
    (uint32)CSL_GPIO2_BASE,
    (uint32)CSL_GPIO4_BASE,
    (uint32)CSL_GPIO6_BASE,
#elif defined (SOC_J721S2)
    (uint32)CSL_WKUP_GPIO0_BASE,
    (uint32)CSL_WKUP_GPIO1_BASE,
    (uint32)CSL_GPIO0_BASE,
    (uint32)CSL_GPIO2_BASE,
    (uint32)CSL_GPIO4_BASE,
    (uint32)CSL_GPIO6_BASE,
#endif
};
/* GPIO Instance Base Addresses */

#define DIO_STOP_SEC_CONST_32
#include "Dio_MemMap.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/*  */

/**
 *\brief   This function is to perform Initialization and pinmuxingfor DIO
 *
 */
void Dio_Init(void)
{
    uint32 regVal = 0U, outputEnableMask = 0U, inputEnableMask = 0U;
    uint32       setMask;
    uint32       clrMask;
    CSL_GpioHandle hGpio;
    uint32                          DIO_PortId;
    uint32                          DIO_InstanceId;
    uint32                          DIO_PortId56;
    uint32                          DIO_InstanceId56;
    uint32                          DIO_InputEnableMask;
    uint32                          DIO_OutputEnableMask;
    uint32                          DIO_OutputEnableMask56;
    uint32                          DIO_OutputPinInitialLevel;
    uint32                          DIO_OutputPinInitialLevel56;
    uint32                          DIO_InstanceAddr;
    /* Unlock lock key registers for Partition 7: IO PAD
       configuration registers in MAIN_CTRL_MMR */
    /* write Partition 7 Lock Key 0 Register */
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x5008, 0x68EF3490);
    /* write Partition 7 Lock Key 1 Register */
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x500C, 0xD172BC5A);
    /* Check for unlock */
    regVal = CSL_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x5008);
    while ((regVal & 0x1) != 0x1U)
    {
        regVal = CSL_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x5008);
    }
    regVal = CSL_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x8070);
    regVal &= 0U;
    regVal |= 0x00001U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x8070, regVal);

    /*Unlock Control mmr regions Wakeup domain */
    DioApp_unlockMmrRegisters(CSL_WKUP_CTRL_MMR_CFG0_LOCK0_KICK0,
                                CSL_WKUP_CTRL_MMR_CFG0_LOCK0_KICK1);
    DioApp_unlockMmrRegisters(CSL_WKUP_CTRL_MMR_CFG0_LOCK1_KICK0,
                                CSL_WKUP_CTRL_MMR_CFG0_LOCK1_KICK1);
    DioApp_unlockMmrRegisters(CSL_WKUP_CTRL_MMR_CFG0_LOCK2_KICK0,
                                CSL_WKUP_CTRL_MMR_CFG0_LOCK2_KICK1);
    DioApp_unlockMmrRegisters(CSL_WKUP_CTRL_MMR_CFG0_LOCK3_KICK0,
                                CSL_WKUP_CTRL_MMR_CFG0_LOCK3_KICK1);
    DioApp_unlockMmrRegisters(CSL_WKUP_CTRL_MMR_CFG0_LOCK4_KICK0,
                                CSL_WKUP_CTRL_MMR_CFG0_LOCK4_KICK1);
#if defined (SOC_J721E)
    DioApp_unlockMmrRegisters(CSL_WKUP_CTRL_MMR_CFG0_LOCK6_KICK0,
                                CSL_WKUP_CTRL_MMR_CFG0_LOCK6_KICK1);
#endif
    DioApp_unlockMmrRegisters(CSL_WKUP_CTRL_MMR_CFG0_LOCK7_KICK0,
                                CSL_WKUP_CTRL_MMR_CFG0_LOCK7_KICK1);
    /*Pin Mux for WKUP_GPIO0_15,1,6*/
    /*Updated Muxmode value as per discussion wrt MCAL-2139*/
    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG49, 0x08050007);
    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG63, 0x08050007);
    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG54, 0x08050007);

    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG72, 0x08050007);    /*WKUP_GPIO0_56 - CANEN2*/
    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG48, 0x08050007);    /*WKUP_GPIO0_0 - CANEN2*/
    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG52, 0x00010000);    /*WKUP_GPIO0_4 -- MCAN1 */
    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG53, 0x00050000);     /*WKUP_GPIO0_5----MCAN1*/

    
    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG64, 0x28050000); /* WKUP_I2C0 -> WKUP_I2C0_SCL -> H24 */ 
    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG65, 0x28050000); /* WKUP_I2C0 -> WKUP_I2C0_SDA -> H27 */

    /*Initializing DIO module: Instance of DIO, Pin Direction, Initial Value*/
    /* Dio Instance is 0: Wake Up domain */
    DIO_InstanceId = 0U;
    DIO_PortId = 0U;
    DIO_OutputEnableMask = ((1U << 15U) | (1U << 1U) | (1 << 31U));
    DIO_OutputPinInitialLevel = ((1U << 15U) | (1U << 1U) | (1 << 31U));
    DIO_InputEnableMask = (1U << 6U);
    DIO_InstanceAddr = DIO_GPIOBaseAddr[DIO_InstanceId];
    hGpio = (CSL_GpioHandle)DIO_InstanceAddr;
    /* Set output pin levels for GPIO */
    if (DIO_OutputEnableMask != 0U)
    {
        /* Enable output pin */
        regVal = hGpio->BANK_REGISTERS[DIO_PortId].DIR;
        outputEnableMask = (regVal & (~DIO_OutputEnableMask));
        hGpio->BANK_REGISTERS[DIO_PortId].DIR = outputEnableMask;
        setMask = DIO_OutputEnableMask & DIO_OutputPinInitialLevel;
        clrMask = DIO_OutputEnableMask & (~DIO_OutputPinInitialLevel);
        hGpio->BANK_REGISTERS[DIO_PortId].SET_DATA = setMask;
        hGpio->BANK_REGISTERS[DIO_PortId].CLR_DATA = clrMask;
    }

    /** For WKUP_GPIO0_56 **/
    DIO_InstanceId56 = 0U; /* WKUP_GPIO0 select */
    DIO_PortId56 = 0U; /* Bank 0 */
    DIO_OutputEnableMask56 = ((1 << 0U));
    DIO_OutputPinInitialLevel56 = ((1 << 0U));
    DIO_InstanceAddr = DIO_GPIOBaseAddr[DIO_InstanceId56];
    hGpio = (CSL_GpioHandle)DIO_InstanceAddr;
    /* Set output pin levels for GPIO */
    if (DIO_OutputEnableMask56 != 0U)
    {
        /* Enable output pin */
        regVal = hGpio->BANK_REGISTERS[DIO_PortId56].DIR;
        outputEnableMask = (regVal & (~DIO_OutputEnableMask56));
        hGpio->BANK_REGISTERS[DIO_PortId56].DIR = outputEnableMask;
        setMask = DIO_OutputEnableMask56 & DIO_OutputPinInitialLevel56;
        clrMask = DIO_OutputEnableMask56 & (~DIO_OutputPinInitialLevel56);
        hGpio->BANK_REGISTERS[DIO_PortId56].SET_DATA = setMask;
        hGpio->BANK_REGISTERS[DIO_PortId56].CLR_DATA = clrMask;
    }
    Dio_WriteChannel(0U, STD_LOW);
    /* Set input pin levels for GPIO */
    if (DIO_InputEnableMask != 0U)
    {
        /* Enable input pin */
        regVal = hGpio->BANK_REGISTERS[DIO_PortId].DIR;
        inputEnableMask = (regVal | DIO_InputEnableMask);
        hGpio->BANK_REGISTERS[DIO_PortId].DIR = inputEnableMask;
    }
    /*Disable Write proteciton */
    GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 49U, GPIO_DIRECTION_OUTPUT);
    GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE,49U,0);

    return;
}
/**
 *\brief   This function is set a unloack MMR register required for Pin Mux
 *
 */
static void DioApp_unlockMmrRegisters(uint32 lockKey0, uint32 lockKey1)
{
    uint32 regVal = 0U;
    /* write Partition Lock Key 0 Register */
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + lockKey0, 0x68EF3490);
    /* write Partition Lock Key 1 Register */
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + lockKey1, 0xD172BC5A);
    /* Check for unlock */
    regVal = CSL_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + lockKey0);
    while ((regVal & 0x1) != 0x1U)
    {
        regVal = CSL_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + lockKey0);
    }

#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)
    /* write Partition Lock Key 0 Register */
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + lockKey0, 0x68EF3490);
    /* write Partition Lock Key 1 Register */
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + lockKey1, 0xD172BC5A);
    /* Check for unlock */
    regVal = CSL_REG32_RD(CSL_CTRL_MMR0_CFG0_BASE + lockKey0);
    while ((regVal & 0x1) != 0x1U)
    {
        regVal = CSL_REG32_RD(CSL_CTRL_MMR0_CFG0_BASE + lockKey0);
    }
#endif

    return;
}

/**
 *\brief   This function is enable Pin Muxing: Wakeup domain
 *
 */
static void DioApp_McuDomainPinMux(uint32 offset, uint32 muxmode)
{
    uint32 regVal = 0U;

    regVal = CSL_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + offset);
    regVal &= 0U;
    regVal |= muxmode;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + offset, regVal);

    return;
}

static void Can14EnableCondtion(void)
{
       uint32 regVal = 0U, outputEnableMask = 0U, inputEnableMask = 0U;
    uint32       setMask;
    uint32       clrMask;
    CSL_GpioHandle hGpio;
    uint32                          DIO_PortId56;
    uint32                          DIO_InstanceId56;
    uint32                          DIO_OutputEnableMask56;
    uint32                          DIO_OutputPinInitialLevel56;
    uint32                          DIO_InstanceAddr;

    /* Unlock lock key registers for Partition 7: IO PAD
   configuration registers in MAIN_CTRL_MMR */
    /* write Partition 7 Lock Key 0 Register */
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x5008, 0x68EF3490);
    /* write Partition 7 Lock Key 1 Register */
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x500C, 0xD172BC5A);
    /* Check for unlock */
    regVal = CSL_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x5008);
    while ((regVal & 0x1) != 0x1U)
    {
        regVal = CSL_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x5008);
    }
    regVal = CSL_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x8070);
    regVal &= 0U;
    regVal |= 0x00001U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x8070, regVal);

    /*Unlock Control mmr regions Wakeup domain */
    DioApp_unlockMmrRegisters(CSL_WKUP_CTRL_MMR_CFG0_LOCK0_KICK0,
                              CSL_WKUP_CTRL_MMR_CFG0_LOCK0_KICK1);
    DioApp_unlockMmrRegisters(CSL_WKUP_CTRL_MMR_CFG0_LOCK1_KICK0,
                              CSL_WKUP_CTRL_MMR_CFG0_LOCK1_KICK1);
    DioApp_unlockMmrRegisters(CSL_WKUP_CTRL_MMR_CFG0_LOCK2_KICK0,
                              CSL_WKUP_CTRL_MMR_CFG0_LOCK2_KICK1);
    DioApp_unlockMmrRegisters(CSL_WKUP_CTRL_MMR_CFG0_LOCK3_KICK0,
                              CSL_WKUP_CTRL_MMR_CFG0_LOCK3_KICK1);
    DioApp_unlockMmrRegisters(CSL_WKUP_CTRL_MMR_CFG0_LOCK4_KICK0,
                              CSL_WKUP_CTRL_MMR_CFG0_LOCK4_KICK1);
        /*Updated Muxmode value as per discussion wrt MCAL-2139*/
    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG49, 0x08050007);
    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG63, 0x08050007);
    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG54, 0x08050007);

    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG72, 0x08050007);    /*WKUP_GPIO0_56 - CANEN2*/
    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG48, 0x08050007);    /*WKUP_GPIO0_0 - CANEN2*/
    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG52, 0x00010000);    /*WKUP_GPIO0_4 -- MCAN1 */
    DioApp_McuDomainPinMux(CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG53, 0x00050000);     /*WKUP_GPIO0_5----MCAN1*/
        /** For WKUP_GPIO0_56 **/
    DIO_InstanceId56 = 0U;
    DIO_PortId56 = 01;
    DIO_OutputEnableMask56 = ((1 << 24U));
    DIO_OutputPinInitialLevel56 = ((1 << 24U));
    DIO_InstanceAddr = DIO_GPIOBaseAddr[DIO_InstanceId56];
    hGpio = (CSL_GpioHandle)DIO_InstanceAddr;
    /* Set output pin levels for GPIO */
    if (DIO_OutputEnableMask56 != 0U)
    {
        /* Enable output pin */
        regVal = hGpio->BANK_REGISTERS[DIO_PortId56].DIR;
        outputEnableMask = (regVal & (~DIO_OutputEnableMask56));
        hGpio->BANK_REGISTERS[DIO_PortId56].DIR = outputEnableMask;
        setMask = DIO_OutputEnableMask56 & DIO_OutputPinInitialLevel56;
        clrMask = DIO_OutputEnableMask56 & (~DIO_OutputPinInitialLevel56);
        hGpio->BANK_REGISTERS[DIO_PortId56].SET_DATA = setMask;
        hGpio->BANK_REGISTERS[DIO_PortId56].CLR_DATA = clrMask;
    }
    Dio_WriteChannel(DioConf_DioChannel_pinFDCAN14_Enable, STD_LOW);
    
    /** For WKUP_GPIO0_0 **/
    DIO_InstanceId56 = 0U; /* WKUP_GPIO0 select */
    DIO_PortId56 = 0U; /* Bank 0 */
    DIO_OutputEnableMask56 = ((1 << 0U));
    DIO_OutputPinInitialLevel56 = ((1 << 0U));
    DIO_InstanceAddr = DIO_GPIOBaseAddr[DIO_InstanceId56];
    hGpio = (CSL_GpioHandle)DIO_InstanceAddr;
    /* Set output pin levels for GPIO */
    if (DIO_OutputEnableMask56 != 0U)
    {
        /* Enable output pin */
        regVal = hGpio->BANK_REGISTERS[DIO_PortId56].DIR;
        outputEnableMask = (regVal & (~DIO_OutputEnableMask56));
        hGpio->BANK_REGISTERS[DIO_PortId56].DIR = outputEnableMask;
        setMask = DIO_OutputEnableMask56 & DIO_OutputPinInitialLevel56;
        clrMask = DIO_OutputEnableMask56 & (~DIO_OutputPinInitialLevel56);
        hGpio->BANK_REGISTERS[DIO_PortId56].SET_DATA = setMask;
        hGpio->BANK_REGISTERS[DIO_PortId56].CLR_DATA = clrMask;
    }
    Dio_WriteChannel(0U, STD_LOW);
}
