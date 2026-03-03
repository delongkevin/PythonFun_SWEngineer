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
 *  \file     Can_Irq.c
 *
 *  \brief    This file contains the ISR implementation of CAN MCAL driver
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "Can.h"
#include "Can_Priv.h"
#include "SchM_Can.h"
#include <ti/csl/soc.h>

#if (CAN_ISR_TYPE == CAN_ISR_CAT2)
#include "Os.h"
#endif

/* ========================================================================== */
/*                          ISR Definitions                                   */
/* ========================================================================== */
/* Design : DES_CAN_005 */
/* Requirements :MCAL-2235 */
#define CAN_START_SEC_ISR_CODE
#include "Can_MemMap.h"

#if defined (CAN_CONTROLLER_MCU_MCAN0)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
/* Design :CAN_DesignId_00x*/
CAN_ISR_TEXT_SECTION void Can_0_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_0_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCU_MCAN0_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_0_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCU_MCAN0) */

#if defined (CAN_CONTROLLER_MCU_MCAN1)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_1_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_1_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCU_MCAN1_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_1_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCU_MCAN1) */

#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)

#if defined (CAN_CONTROLLER_MCAN0)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_2_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_2_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN0_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_2_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN0) */

#if defined (CAN_CONTROLLER_MCAN1)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_3_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_3_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN1_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_3_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN1) */

#if defined (CAN_CONTROLLER_MCAN2)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_4_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_4_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN2_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_4_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN2) */

#if defined (CAN_CONTROLLER_MCAN3)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_5_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_5_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN3_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_5_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN3) */

#if defined (CAN_CONTROLLER_MCAN4)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_6_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_6_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN4_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_6_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN4) */

#if defined (CAN_CONTROLLER_MCAN5)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_7_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_7_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN5_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_7_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN5) */

#if defined (CAN_CONTROLLER_MCAN6)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_8_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_8_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN6_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_8_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN6) */

#if defined (CAN_CONTROLLER_MCAN7)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_9_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_9_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN7_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_9_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN7) */

#if defined (CAN_CONTROLLER_MCAN8)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_10_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_10_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN8_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_10_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN8) */

#if defined (CAN_CONTROLLER_MCAN9)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_11_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_11_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN9_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_11_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN9) */

#if defined (CAN_CONTROLLER_MCAN10)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_12_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_12_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN10_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_12_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN10) */

#if defined (CAN_CONTROLLER_MCAN11)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_13_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_13_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN11_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_13_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN11) */

#if defined (CAN_CONTROLLER_MCAN12)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_14_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_14_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN12_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_14_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN12) */

#if defined (CAN_CONTROLLER_MCAN13)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_15_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_15_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN13_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_15_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN13) */

#if defined (SOC_J7200) || defined (SOC_J721S2)
#if defined (CAN_CONTROLLER_MCAN14)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_16_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_16_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN14_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_16_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN14) */

#if defined (CAN_CONTROLLER_MCAN15)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_17_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_17_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN15_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_17_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN15) */

#if defined (CAN_CONTROLLER_MCAN16)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_18_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_18_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN16_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_18_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN16) */

#if defined (CAN_CONTROLLER_MCAN17)
#if (CAN_ISR_TYPE == CAN_ISR_CAT1 || \
     CAN_ISR_TYPE == CAN_ISR_VOID)
CAN_ISR_TEXT_SECTION void Can_19_Int0ISR(void)
#else
CAN_ISR_TEXT_SECTION ISR(Can_19_Int0ISR)
#endif /* ((CAN_ISR_TYPE == CAN_ISR_CAT1).... */
{
    uint32 baseAddr = (uint32)CSL_MCAN17_MSGMEM_RAM_BASE;
    if (CAN_READY != Can_DrvState)
    {
        /* Disable Interrupt Sources as well as Interrupt Line */
        MCAN_enableIntr(baseAddr, MCAN_INTR_MASK_ALL, (uint32)FALSE);
        /* Clear Interrupt status */
        MCAN_clearIntrStatus(baseAddr, (uint32)MCAN_INTR_MASK_ALL);
    }
    else
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_19_Int0ISR_Fun();
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}
#endif /* #if defined (CAN_CONTROLLER_MCAN17) */

#endif /* #if defined (SOC_J7200) */
#endif /* #if defined (SOC_J721E) || defined (SOC_J7200) */

#define CAN_STOP_SEC_ISR_CODE
#include "Can_MemMap.h"

/*******************************************************************************
 *  End of File: Can_Irq.c
 ******************************************************************************/
