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
 *  \file     Spi_Irq.c
 *
 *  \brief    This file contains the ISR implementation of SPI MCAL driver
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "Spi_Cfg.h"
#include "Spi.h"
#include "Spi_Priv.h"

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

extern volatile Spi_StatusType Spi_DrvStatus;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define SPI_START_SEC_ISR_CODE
#include "Spi_MemMap.h"

#if (STD_ON == SPI_UNIT_MCU_MCSPI0_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi0TxRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcuMcspi0TxRx)
  #endif
{
    Spi_HwUnitObjType *hwUnitObj;
    uint32 baseAddr;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCU_MCSPI0);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        hwUnitObj = Spi_getHwUnitObj(SPI_UNIT_MCU_MCSPI0);
        Spi_processEvents(hwUnitObj);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCU_MCSPI0_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCU_MCSPI1_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi1TxRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcuMcspi1TxRx)
  #endif
{
    Spi_HwUnitObjType *hwUnitObj;
    uint32 baseAddr;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCU_MCSPI1);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        hwUnitObj = Spi_getHwUnitObj(SPI_UNIT_MCU_MCSPI1);
        Spi_processEvents(hwUnitObj);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCU_MCSPI1_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCU_MCSPI2_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi2TxRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcuMcspi2TxRx)
  #endif
{
    Spi_HwUnitObjType *hwUnitObj;
    uint32 baseAddr;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCU_MCSPI2);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        hwUnitObj = Spi_getHwUnitObj(SPI_UNIT_MCU_MCSPI2);
        Spi_processEvents(hwUnitObj);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCU_MCSPI2_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCSPI0_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi0TxRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi0TxRx)
  #endif
{
    Spi_HwUnitObjType *hwUnitObj;
    uint32 baseAddr;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI0);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        hwUnitObj = Spi_getHwUnitObj(SPI_UNIT_MCSPI0);
        Spi_processEvents(hwUnitObj);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI0_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCSPI1_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi1TxRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi1TxRx)
  #endif
{
    Spi_HwUnitObjType *hwUnitObj;
    uint32 baseAddr;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI1);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        hwUnitObj = Spi_getHwUnitObj(SPI_UNIT_MCSPI1);
        Spi_processEvents(hwUnitObj);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI1_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCSPI2_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi2TxRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi2TxRx)
  #endif
{
    Spi_HwUnitObjType *hwUnitObj;
    uint32 baseAddr;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI2);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        hwUnitObj = Spi_getHwUnitObj(SPI_UNIT_MCSPI2);
        Spi_processEvents(hwUnitObj);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI2_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCSPI3_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi3TxRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi3TxRx)
  #endif
{
    Spi_HwUnitObjType *hwUnitObj;
    uint32 baseAddr;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI3);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        hwUnitObj = Spi_getHwUnitObj(SPI_UNIT_MCSPI3);
        Spi_processEvents(hwUnitObj);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI3_ACTIVE) */

#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)

#if (STD_ON == SPI_UNIT_MCSPI4_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi4TxRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi4TxRx)
  #endif
{
    Spi_HwUnitObjType *hwUnitObj;
    uint32 baseAddr;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI4);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        hwUnitObj = Spi_getHwUnitObj(SPI_UNIT_MCSPI4);
        Spi_processEvents(hwUnitObj);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI4_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCSPI5_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi5TxRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi5TxRx)
  #endif
{
    Spi_HwUnitObjType *hwUnitObj;
    uint32 baseAddr;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI5);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        hwUnitObj = Spi_getHwUnitObj(SPI_UNIT_MCSPI5);
        Spi_processEvents(hwUnitObj);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI5_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCSPI6_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi6TxRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi6TxRx)
  #endif
{
    Spi_HwUnitObjType *hwUnitObj;
    uint32 baseAddr;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI6);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        hwUnitObj = Spi_getHwUnitObj(SPI_UNIT_MCSPI6);
        Spi_processEvents(hwUnitObj);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI6_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCSPI7_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi7TxRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi7TxRx)
  #endif
{
    Spi_HwUnitObjType *hwUnitObj;
    uint32 baseAddr;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI7);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        hwUnitObj = Spi_getHwUnitObj(SPI_UNIT_MCSPI7);
        Spi_processEvents(hwUnitObj);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI7_ACTIVE) */

#endif /* #if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2) */


/* DMA Enabled ISR routines */
#if (STD_ON == SPI_DMA_ENABLE)

#if (STD_ON == SPI_UNIT_MCU_MCSPI0_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi0DmaTx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcuMcspi0DmaTx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCU_MCSPI0);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCU_MCSPI0)
            {
                 break;
            }
        }
        Spi_DmaTxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}

  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi0DmaRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcuMcspi0DmaRx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCU_MCSPI0);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCU_MCSPI0)
            {
                 break;
            }
        }
        Spi_DmaRxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCU_MCSPI0_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCU_MCSPI1_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi1DmaTx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcuMcspi1DmaTx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCU_MCSPI1);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCU_MCSPI1)
            {
                 break;
            }
        }
        Spi_DmaTxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}

  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi1DmaRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcuMcspi1DmaRx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCU_MCSPI1);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCU_MCSPI1)
            {
                 break;
            }
        }
        Spi_DmaRxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCU_MCSPI1_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCU_MCSPI2_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi2DmaTx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcuMcspi2DmaTx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCU_MCSPI2);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCU_MCSPI2)
            {
                 break;
            }
        }
        Spi_DmaTxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}

  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi2DmaRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcuMcspi2DmaRx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCU_MCSPI2);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCU_MCSPI2)
            {
                 break;
            }
        }
        Spi_DmaRxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCU_MCSPI2_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCSPI0_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi0DmaTx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi0DmaTx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI0);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI0)
            {
                 break;
            }
        }
        Spi_DmaTxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}

  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi0DmaRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi0DmaRx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI0);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI0)
            {
                 break;
            }
        }
        Spi_DmaRxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI0_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCSPI1_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi1DmaTx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi1DmaTx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI1);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI1)
            {
                 break;
            }
        }
        Spi_DmaTxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}

  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi1DmaRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi1DmaRx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI1);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI1)
            {
                 break;
            }
        }
        Spi_DmaRxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI1_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCSPI2_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi2DmaTx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi2DmaTx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI2);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI2)
            {
                 break;
            }
        }
        Spi_DmaTxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}

  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi2DmaRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi2DmaRx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI2);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI2)
            {
                 break;
            }
        }
        Spi_DmaRxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI2_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCSPI3_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi3DmaTx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi3DmaTx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI3);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI3)
            {
                 break;
            }
        }
        Spi_DmaTxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}

  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi3DmaRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi3DmaRx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI3);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI3)
            {
                 break;
            }
        }
        Spi_DmaRxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI3_ACTIVE) */

#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)

#if (STD_ON == SPI_UNIT_MCSPI4_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi4DmaTx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi4DmaTx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI4);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI4)
            {
                 break;
            }
        }
        Spi_DmaTxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}

  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi4DmaRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi4DmaRx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI4);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI4)
            {
                 break;
            }
        }
        Spi_DmaRxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI4_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCSPI5_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi5DmaTx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi5DmaTx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI5);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI5)
            {
                 break;
            }
        }
        Spi_DmaTxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}

  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi5DmaRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi5DmaRx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI5);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI5)
            {
                 break;
            }
        }
        Spi_DmaRxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI5_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCSPI6_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi6DmaTx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi6DmaTx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI6);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI6)
            {
                 break;
            }
        }
        Spi_DmaTxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}

  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi6DmaRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi6DmaRx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI6);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI6)
            {
                 break;
            }
        }
        Spi_DmaRxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI6_ACTIVE) */

#if (STD_ON == SPI_UNIT_MCSPI7_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi7DmaTx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi7DmaTx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI7);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI7)
            {
                 break;
            }
        }
        Spi_DmaTxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}

  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
SPI_ISR_TEXT_SECTION FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi7DmaRx(void)
  #else
SPI_ISR_TEXT_SECTION ISR(Spi_IrqUnitMcspi7DmaRx)
  #endif
{
    uint32 baseAddr, index;
    Spi_DmaObjType   *dmaObj;
    uint32 dmaEnabledHwCnt = (uint32)SPI_MAX_HW_DMA_UNIT;

    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Should not come here. Only possible case is MCU registers ISR and
         * stray/old interrupts are pending for channel */
        baseAddr = Spi_getHwUnitBaseAddr(SPI_UNIT_MCSPI7);
        Spi_mcspiDisableAllIntr(baseAddr);
        Spi_mcspiClearAllIrqStatus(baseAddr);
    }
    else
    {
        /* Get Hw Unit id */
        for (index = 0U; index < dmaEnabledHwCnt; index++)
        {
            dmaObj =  &Spi_DrvObj.dmaObj[index];
            if (dmaObj->hwUnitId == SPI_UNIT_MCSPI7)
            {
                 break;
            }
        }
        Spi_DmaRxIsrHandler(&Spi_DrvObj.dmaObj[index]);
    }
}
#endif  /* #if (STD_ON == SPI_UNIT_MCSPI7_ACTIVE) */

#endif /* #if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2) */

#endif /* #if (STD_ON == SPI_DMA_ENABLE) */

#define SPI_STOP_SEC_ISR_CODE
#include "Spi_MemMap.h"
