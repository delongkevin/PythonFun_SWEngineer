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
 *  \file     Spi_Irq.h
 *
 *  \brief    This file contains ISR function declaration for SPI MCAL driver
 *
 */

/**
 *  \ingroup MCAL_SPIHANDLER_API
 *
 *  \defgroup MCAL_SPI_IRQ_API Defines Interrupt Handler for all SPI instances
 *  @{
 */

/* Design: SPI_DesignId_004 */

#ifndef SPI_IRQ_H_
#define SPI_IRQ_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
extern "C"
{
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *  \name SPI Driver ISR category level
 *
 *  Defines for SPI Driver ISR ISR category level
 *  @{
 */
/** \brief void ISR type */
#define SPI_ISR_VOID                    (0x00U)
/** \brief Category 1 ISR type */
#define SPI_ISR_CAT1                    (0x01U)
/** \brief Category 2 ISR type */
#define SPI_ISR_CAT2                    (0x02U)
/* @} */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

#if (STD_ON == SPI_UNIT_MCU_MCSPI0_ACTIVE)
  #if (SPI_ISR_TYPE == SPI_ISR_CAT1 || SPI_ISR_TYPE == SPI_ISR_VOID)
    /** \brief Mcu McSPI0 ISR */
    FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi0TxRx(void);
  #elif (SPI_ISR_TYPE == SPI_ISR_CAT2)
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCU_MCSPI1_ACTIVE)
  #if (SPI_ISR_TYPE == SPI_ISR_CAT1 || SPI_ISR_TYPE == SPI_ISR_VOID)
    /** \brief Mcu McSPI1 ISR */
    FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi1TxRx(void);
  #elif (SPI_ISR_TYPE == SPI_ISR_CAT2)
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCU_MCSPI2_ACTIVE)
  #if (SPI_ISR_TYPE == SPI_ISR_CAT1 || SPI_ISR_TYPE == SPI_ISR_VOID)
    /** \brief Mcu McSPI2 ISR */
    FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi2TxRx(void);
  #elif (SPI_ISR_TYPE == SPI_ISR_CAT2)
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCSPI0_ACTIVE)
  #if (SPI_ISR_TYPE == SPI_ISR_CAT1 || SPI_ISR_TYPE == SPI_ISR_VOID)
    /** \brief McSPI0 ISR */
    FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi0TxRx(void);
  #elif (SPI_ISR_TYPE == SPI_ISR_CAT2)
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCSPI1_ACTIVE)
  #if (SPI_ISR_TYPE == SPI_ISR_CAT1 || SPI_ISR_TYPE == SPI_ISR_VOID)
    /** \brief McSPI1 ISR */
    FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi1TxRx(void);
  #elif (SPI_ISR_TYPE == SPI_ISR_CAT2)
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCSPI2_ACTIVE)
  #if (SPI_ISR_TYPE == SPI_ISR_CAT1 || SPI_ISR_TYPE == SPI_ISR_VOID)
    /** \brief McSPI2 ISR */
    FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi2TxRx(void);
  #elif (SPI_ISR_TYPE == SPI_ISR_CAT2)
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCSPI3_ACTIVE)
  #if (SPI_ISR_TYPE == SPI_ISR_CAT1 || SPI_ISR_TYPE == SPI_ISR_VOID)
    /** \brief McSPI3 ISR */
    FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi3TxRx(void);
  #elif (SPI_ISR_TYPE == SPI_ISR_CAT2)
    /* Function prototype is declared by OS */
  #endif
#endif

#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)

#if (STD_ON == SPI_UNIT_MCSPI4_ACTIVE)
  #if (SPI_ISR_TYPE == SPI_ISR_CAT1 || SPI_ISR_TYPE == SPI_ISR_VOID)
    /** \brief McSPI4 ISR */
    FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi4TxRx(void);
  #elif (SPI_ISR_TYPE == SPI_ISR_CAT2)
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCSPI5_ACTIVE)
  #if (SPI_ISR_TYPE == SPI_ISR_CAT1 || SPI_ISR_TYPE == SPI_ISR_VOID)
    /** \brief McSPI5 ISR */
    FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi5TxRx(void);
  #elif (SPI_ISR_TYPE == SPI_ISR_CAT2)
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCSPI6_ACTIVE)
  #if (SPI_ISR_TYPE == SPI_ISR_CAT1 || SPI_ISR_TYPE == SPI_ISR_VOID)
    /** \brief McSPI6 ISR */
    FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi6TxRx(void);
  #elif (SPI_ISR_TYPE == SPI_ISR_CAT2)
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCSPI7_ACTIVE)
  #if (SPI_ISR_TYPE == SPI_ISR_CAT1 || SPI_ISR_TYPE == SPI_ISR_VOID)
    /** \brief McSPI7 ISR */
    FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi7TxRx(void);
  #elif (SPI_ISR_TYPE == SPI_ISR_CAT2)
    /* Function prototype is declared by OS */
  #endif
#endif

#endif


#if (STD_ON == SPI_DMA_ENABLE)

#if (STD_ON == SPI_UNIT_MCU_MCSPI0_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi0DmaTx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi0DmaRx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCU_MCSPI1_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi1DmaTx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi1DmaRx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCU_MCSPI2_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi2DmaTx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcuMcspi2DmaRx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCSPI0_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi0DmaTx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi0DmaRx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCSPI1_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi1DmaTx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi1DmaRx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCSPI2_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi2DmaTx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi2DmaRx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCSPI3_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi3DmaTx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi3DmaRx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
#endif

#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)

#if (STD_ON == SPI_UNIT_MCSPI4_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi4DmaTx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi4DmaRx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCSPI5_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi5DmaTx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi5DmaRx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCSPI6_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi6DmaTx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi6DmaRx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
#endif

#if (STD_ON == SPI_UNIT_MCSPI7_ACTIVE)
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi7DmaTx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
  #if ((SPI_ISR_TYPE == SPI_ISR_CAT1) || (SPI_ISR_TYPE == SPI_ISR_VOID))
  FUNC(void, SPI_CODE_FAST) Spi_IrqUnitMcspi7DmaRx(void);
  #else
    /* Function prototype is declared by OS */
  #endif
#endif

#endif /* #if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2) */


#endif

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef SPI_IRQ_H_ */

/* @} */
