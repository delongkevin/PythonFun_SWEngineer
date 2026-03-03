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
 *  \file     Spi.c
 *
 *  \brief    This file contains SPI MCAL driver
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "string.h"
#include "Spi_Cfg.h"
#include "Spi.h"
#include "Spi_Dbg.h"
#include "Spi_Priv.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* AUTOSAR version information check has to match definition in header file */
#if ((SPI_AR_RELEASE_MAJOR_VERSION != (4U)) || \
    (SPI_AR_RELEASE_MINOR_VERSION != (3U)) ||  \
    (SPI_AR_RELEASE_REVISION_VERSION != (1U)))
    #error "Spi: AUTOSAR Version Numbers of Spi are different!!"
#endif

/* AUTOSAR version information check has to match definition in header file */
#if ((SPI_SW_MAJOR_VERSION != (1U)) || \
    (SPI_SW_MINOR_VERSION != (3U)) ||  \
    (SPI_SW_PATCH_VERSION != (5U)))
    #error "Spi: Software Version Numbers are inconsistent!!"
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
#if ((SPI_CHANNELBUFFERS == SPI_IB) || (SPI_CHANNELBUFFERS == SPI_IB_EB))
#if (STD_ON == SPI_DEV_ERROR_DETECT)
static FUNC(Std_ReturnType, SPI_CODE) Spi_WriteIBDetErrCheck(
    Spi_ChannelType Channel,
    P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr);
#endif /* (STD_ON == SPI_DEV_ERROR_DETECT) */
#endif /* (SPI_CHANNELBUFFERS == SPI_IB) || (SPI_CHANNELBUFFERS == SPI_IB_EB) */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

/** \brief SPI driver status */
/* Requirements : MCAL-1345 */
SPI_VAR_DATA_INIT_UNSPECIFIED_SECTION
volatile VAR(Spi_StatusType, SPI_VAR_CLEARED) Spi_DrvStatus = SPI_UNINIT;
#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
/** \brief SPI driver object */
SPI_VAR_DATA_NO_INIT_UNSPECIFIED_SECTION
VAR(Spi_DriverObjType, SPI_VAR_CLEARED) Spi_DrvObj;
#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/* Design :  SPI_DesignId_009 */
/* Requirements : MCAL-1308, MCAL-1309, MCAL-1310, MCAL-1312,
 *                MCAL-1316, MCAL-1330, MCAL-1386, MCAL-1387,
 *                MCAL-1388, MCAL-1389, MCAL-1390, MCAL-1391
 */
SPI_FUNC_TEXT_SECTION FUNC(void, SPI_CODE) Spi_Init(
    P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CONFIG_DATA) CfgPtr)
{
    uint32         index;
    const Spi_ConfigType *ConfigPtr = CfgPtr;
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    Std_ReturnType retVal;
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */

#if (STD_ON == SPI_PRE_COMPILE_VARIANT)
    if (NULL_PTR == ConfigPtr)
    {
        ConfigPtr = &SPI_INIT_CONFIG_PC;
    }
#endif  /* (STD_ON == SPI_PRE_COMPILE_VARIANT) */
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT != Spi_DrvStatus)
    {
        Spi_reportDetError(SPI_SID_INIT, SPI_E_ALREADY_INITIALIZED);
    }
    else if (NULL_PTR == ConfigPtr)
    {
        Spi_reportDetError(SPI_SID_INIT, SPI_E_PARAM_POINTER);
    }
    else if (ConfigPtr->maxChannels > SPI_MAX_CHANNELS)
    {
        Spi_reportDetError(SPI_SID_INIT, SPI_E_PARAM_CHANNEL);
    }
    else if (ConfigPtr->maxJobs > SPI_MAX_JOBS)
    {
        Spi_reportDetError(SPI_SID_INIT, SPI_E_PARAM_JOB);
    }
    else if (ConfigPtr->maxSeq > SPI_MAX_SEQ)
    {
        Spi_reportDetError(SPI_SID_INIT, SPI_E_PARAM_SEQ);
    }
    else if (ConfigPtr->maxHwUnit > SPI_MAX_HW_UNIT)
    {
        Spi_reportDetError(SPI_SID_INIT, SPI_E_PARAM_UNIT);
    }
    else if (ConfigPtr->maxExtDevCfg > SPI_MAX_EXT_DEV)
    {
        Spi_reportDetError(SPI_SID_INIT, SPI_E_PARAM_JOB);
    }
    else
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
#if (STD_ON == SPI_DEV_ERROR_DETECT)
        /* Check the configuration */
        retVal = Spi_checkConfig(ConfigPtr);
        if (((Std_ReturnType) E_OK) == retVal)
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
        {
            Spi_resetDrvObj(&Spi_DrvObj);
            Spi_copyConfig(&Spi_DrvObj, ConfigPtr);

            /* Init HW once all config is copied */
            for (index = 0U; index < ConfigPtr->maxHwUnit; index++)
            {
                Spi_hwUnitInit(&Spi_DrvObj.hwUnitObj[index]);
            }

#if (STD_ON == SPI_DMA_ENABLE)
            retVal = Spi_DmaConfig(&Spi_DrvObj, ConfigPtr);
            if (retVal == E_NOT_OK)
            {
                Spi_reportDetError(SPI_SID_INIT, SPI_E_PARAM_JOB);
            }

            if (retVal == E_OK)
#endif
            {
                /* Initialize driver status and object */
                Spi_DrvStatus = SPI_IDLE;
            }
        }
    }

    return;
}

/* Design :  SPI_DesignId_010 */
/*
 * Requirements : MCAL-1313, MCAL-1328, MCAL-1393, MCAL-1394,
 *                MCAL-1395, MCAL-1396, MCAL-1397, MCAL-1398,
 *                MCAL-1400, MCAL-1401
 */
SPI_FUNC_TEXT_SECTION FUNC(Std_ReturnType, SPI_CODE) Spi_DeInit(void)
{
    uint32         index;
    Std_ReturnType retVal = (Std_ReturnType) E_NOT_OK;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        Spi_reportDetError(SPI_SID_DEINIT, SPI_E_UNINIT);
    }
    else
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        if (SPI_BUSY == Spi_DrvStatus)
        {
            /* Do nothing */
        }
        else
        {
            Spi_DrvStatus = SPI_UNINIT;
            /* Deinit the hardware modules */
            for (index = 0U; index < Spi_DrvObj.maxHwUnit; index++)
            {
                Spi_hwUnitDeInit(&Spi_DrvObj.hwUnitObj[index]);
            }
            Spi_resetDrvObj(&Spi_DrvObj);
#if (STD_ON == SPI_DMA_ENABLE)
            /* Deinit the hardware modules */
            for (index = 0U; index < Spi_DrvObj.maxHwUnit; index++)
            {
                Spi_DmaFreeChannel(&Spi_DrvObj.dmaObj[index]);
            }
            (void)Udma_deinit(Spi_DrvObj.drvHandle);
#endif
            retVal        = ((Std_ReturnType) E_OK);
        }
    }

    return (retVal);
}

/* Design :  SPI_DesignId_011 */
/*
 * Requirements : MCAL-1342, MCAL-1346, MCAL-1347, MCAL-1448,
 *                MCAL-1449, MCAL-1450, MCAL-1451
 */
SPI_FUNC_TEXT_SECTION FUNC(Spi_StatusType, SPI_CODE) Spi_GetStatus(void)
{
    return (Spi_DrvStatus);
}

/* Design :  SPI_DesignId_012 */
/*
 * Requirements : MCAL-1313, MCAL-1322, MCAL-1328, MCAL-1352,
 *                MCAL-1354, MCAL-1452, MCAL-1453, MCAL-1454,
 *                MCAL-1455
 */
SPI_FUNC_TEXT_SECTION FUNC(Spi_JobResultType, SPI_CODE)
    Spi_GetJobResult(Spi_JobType Job)
{
    Spi_JobResultType jobResult = SPI_JOB_FAILED;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        Spi_reportDetError(SPI_SID_GET_JOB_RESULT, SPI_E_UNINIT);
    }
    else if (Job >= Spi_DrvObj.maxJobs)
    {
        Spi_reportDetError(SPI_SID_GET_JOB_RESULT, SPI_E_PARAM_JOB);
    }
    else
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        jobResult = Spi_DrvObj.jobObj[Job].jobResult;
    }

    return  (jobResult);
}

/* Design :  SPI_DesignId_013 */
/*
 * Requirements : MCAL-1310, MCAL-1313, MCAL-1328, MCAL-1356,
 *                MCAL-1358, MCAL-1360, MCAL-1361, MCAL-1362,
 *                MCAL-1457, MCAL-1458, MCAL-1459
 */
SPI_FUNC_TEXT_SECTION FUNC(Spi_SeqResultType, SPI_CODE) Spi_GetSequenceResult(
    Spi_SequenceType Sequence)
{
    Spi_SeqResultType seqResult = SPI_SEQ_FAILED;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        Spi_reportDetError(SPI_SID_GET_SEQ_RESULT, SPI_E_UNINIT);
    }
    else if (Sequence >= Spi_DrvObj.maxSeq)
    {
        Spi_reportDetError(SPI_SID_GET_SEQ_RESULT, SPI_E_PARAM_SEQ);
    }
    else
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        seqResult = Spi_DrvObj.seqObj[Sequence].seqResult;
    }

    return (seqResult);
}

#if (STD_ON == SPI_VERSION_INFO_API)
/* Design :  SPI_DesignId_021 */
/*
 * Requirements : MCAL-1462, MCAL-1464
 */
SPI_FUNC_TEXT_SECTION FUNC(void, SPI_CODE) Spi_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, SPI_APPL_DATA) versioninfo)
{
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (NULL_PTR == versioninfo)
    {
        Spi_reportDetError(SPI_SID_GET_VERSION_INFO, SPI_E_PARAM_POINTER);
    }
    else
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        versioninfo->vendorID         = SPI_VENDOR_ID;
        versioninfo->moduleID         = SPI_MODULE_ID;
        versioninfo->sw_major_version = (uint8) SPI_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8) SPI_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8) SPI_SW_PATCH_VERSION;
    }

    return;
}
#endif  /* #if (STD_ON == SPI_VERSION_INFO_API) */

/*
 * Requirements : MCAL-1480
 */
#if (STD_ON == SPI_HW_STATUS_API)
/* Design :  SPI_DesignId_014 */
/*
 * Requirements : MCAL-1312, MCAL-1313, MCAL-1326, MCAL-1327,
 *                MCAL-1328, MCAL-1343, MCAL-1348, MCAL-1349,
 *                MCAL-1475, MCAL-1476, MCAL-1477, MCAL-1478,
 */
SPI_FUNC_TEXT_SECTION FUNC(Spi_StatusType, SPI_CODE) Spi_GetHWUnitStatus(
    Spi_HWUnitType HWUnit)
{
    Spi_HwUnitObjType *hwUnitObj;
    Spi_StatusType     hwUnitStatus = SPI_UNINIT;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        Spi_reportDetError(SPI_SID_GET_HW_UNIT_STATUS, SPI_E_UNINIT);
    }
    else if (HWUnit >= SPI_HW_UNIT_CNT)
    {
        Spi_reportDetError(SPI_SID_GET_HW_UNIT_STATUS, SPI_E_PARAM_UNIT);
    }
    else
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_0();

        /* HW unit ID may not be the index, so search for matching HW unit */
        hwUnitObj = Spi_getHwUnitObj(HWUnit);
        if (NULL_PTR != hwUnitObj)
        {
            if (SPI_HW_UNIT_OK == hwUnitObj->hwUnitResult)
            {
                hwUnitStatus = SPI_IDLE;
            }
            else
            {
                hwUnitStatus = SPI_BUSY;
            }
        }

        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_0();
    }

    return (hwUnitStatus);
}
#endif  /* #if (STD_ON == SPI_HW_STATUS_API) */

#if ((SPI_CHANNELBUFFERS == SPI_IB) || (SPI_CHANNELBUFFERS == SPI_IB_EB))
/* Design :  SPI_DesignId_026 */
/*
 * Requirements : MCAL-1402, MCAL-1403, MCAL-1404, MCAL-1405,
 *                MCAL-1406, MCAL-1407, MCAL-1408, MCAL-1409,
 *                MCAL-1410
 */
SPI_FUNC_TEXT_SECTION FUNC(Std_ReturnType, SPI_CODE) Spi_WriteIB(
    Spi_ChannelType Channel,
    P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr)
{
    Std_ReturnType      retVal = (Std_ReturnType) E_OK;
    Spi_ChannelObjType *chObj;
    const uint8        *tempBuf8;
    uint8              *tempIbPtr8;
    const uint16       *tempBuf16;
    uint16             *tempIbPtr16;
    const uint32       *tempBuf32;
    uint32             *tempIbPtr32;
    uint32              index;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if ((Std_ReturnType) E_NOT_OK == Spi_WriteIBDetErrCheck(Channel,
        DataBufferPtr))
    {
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_0();

        chObj = &Spi_DrvObj.channelObj[Channel];
        if (1U == chObj->bufWidth)
        {
            tempIbPtr8 = ((uint8 *) &chObj->txIb[0U]);
            for (index = 0U; index < chObj->chCfg.maxBufLength; index++)
            {
                if (NULL_PTR != DataBufferPtr)
                {
                    tempBuf8 = (const uint8 *) DataBufferPtr;
                    tempBuf8 += index;
                }
                else
                {
                    tempBuf8 = ((const uint8 *) &chObj->chCfg.defaultTxData);
                }
                tempIbPtr8[index] = *tempBuf8;
            }
        }
        else if (2U == chObj->bufWidth)
        {
            tempIbPtr16 = ((uint16 *) &chObj->txIb[0U]);
            for (index = 0U; index < chObj->chCfg.maxBufLength; index++)
            {
                if (NULL_PTR != DataBufferPtr)
                {
                    tempBuf16 = (const uint16 *) DataBufferPtr;
                    tempBuf16 += index;
                }
                else
                {
                    tempBuf16 = ((const uint16 *) &chObj->chCfg.defaultTxData);
                }
                tempIbPtr16[index] = *tempBuf16;
            }
        }
        else
        {
            tempIbPtr32 = ((uint32 *) &chObj->txIb[0U]);
            for (index = 0U; index < chObj->chCfg.maxBufLength; index++)
            {
                if (NULL_PTR != DataBufferPtr)
                {
                    tempBuf32 = (const uint32 *) DataBufferPtr;
                    tempBuf32 += index;
                }
                else
                {
                    tempBuf32 = ((const uint32 *) &chObj->chCfg.defaultTxData);
                }
                tempIbPtr32[index] = *tempBuf32;
            }
        }

        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_0();
    }

    return  (retVal);
}

/* Design : SPI_DesignId_027 */
/*
 * Requirements : MCAL-1430, MCAL-1431, MCAL-1432, MCAL-1433,
 *                MCAL-1434, MCAL-1435, MCAL-1436, MCAL-1437
 */
SPI_FUNC_TEXT_SECTION FUNC(Std_ReturnType, SPI_CODE) Spi_ReadIB(
    Spi_ChannelType Channel,
    P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPointer)
{
    Std_ReturnType      retVal = (Std_ReturnType) E_OK;
    Spi_ChannelObjType *chObj;
    uint8              *tempBuf8;
    uint8              *tempIbPtr8;
    uint16             *tempBuf16;
    uint16             *tempIbPtr16;
    uint32             *tempBuf32;
    uint32             *tempIbPtr32;
    uint32              index;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        Spi_reportDetError(SPI_SID_READ_IB, SPI_E_UNINIT);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if ((Channel >= Spi_DrvObj.maxChannels) ||
             (Spi_DrvObj.channelObj[Channel].chCfg.channelBufType != SPI_IB))
    {
        Spi_reportDetError(SPI_SID_READ_IB, SPI_E_PARAM_CHANNEL);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if ((NULL_PTR == DataBufferPointer) ||
            (((uint32) DataBufferPointer & 0x03U) != 0U))
    {
        Spi_reportDetError(SPI_SID_READ_IB, SPI_E_PARAM_POINTER);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_0();

        chObj = &Spi_DrvObj.channelObj[Channel];
        if (1U == chObj->bufWidth)
        {
            tempBuf8 = (uint8 *) DataBufferPointer;
            tempIbPtr8 = ((uint8 *) &chObj->rxIb[0U]);
            for (index = 0U; index < chObj->chCfg.maxBufLength; index++)
            {
                tempBuf8[index] = tempIbPtr8[index];
            }
        }
        else if (2U == chObj->bufWidth)
        {
            tempBuf16 = (uint16 *) DataBufferPointer;
            tempIbPtr16 = ((uint16 *) &chObj->rxIb[0U]);
            for (index = 0U; index < chObj->chCfg.maxBufLength; index++)
            {
                tempBuf16[index] = tempIbPtr16[index];
            }
        }
        else
        {
            tempBuf32 = (uint32 *) DataBufferPointer;
            tempIbPtr32 = ((uint32 *) &chObj->rxIb[0U]);
            for (index = 0U; index < chObj->chCfg.maxBufLength; index++)
            {
                tempBuf32[index] = tempIbPtr32[index];
            }
        }

        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_0();
    }

    return  (retVal);
}
#endif  /* #if SPI_IB || SPI_IB_EB */

#if ((SPI_CHANNELBUFFERS == SPI_EB) || (SPI_CHANNELBUFFERS == SPI_IB_EB))
/* Design :  SPI_DesignId_015 */
/*
 * Requirements : MCAL-1447
 */
/*
 * Requirements : MCAL-1311, MCAL-1313, MCAL-1321, MCAL-1324,
 *                MCAL-1325, MCAL-1328, MCAL-1364, MCAL-1438,
 *                MCAL-1439, MCAL-1440, MCAL-1441, MCAL-1442,
 *                MCAL-1443, MCAL-1512, MCAL-1513
 */
SPI_FUNC_TEXT_SECTION FUNC(Std_ReturnType, SPI_CODE) Spi_SetupEB(
    Spi_ChannelType Channel,
    P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) SrcDataBufferPtr,
    P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
    Spi_NumberOfDataType Length)
{
    Std_ReturnType      retVal = (Std_ReturnType) E_OK;
    Spi_ChannelObjType *chObj;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        Spi_reportDetError(SPI_SID_SETUP_EB, SPI_E_UNINIT);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if ((Channel >= Spi_DrvObj.maxChannels) ||
             (Spi_DrvObj.channelObj[Channel].chCfg.channelBufType != SPI_EB))
    {
        Spi_reportDetError(SPI_SID_SETUP_EB, SPI_E_PARAM_CHANNEL);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_0();

        chObj = &Spi_DrvObj.channelObj[Channel];

#if (STD_ON == SPI_DEV_ERROR_DETECT)
        /* Buffers must always be 32-bit aligned - MCAL-1364 */
        if ((((uint32) SrcDataBufferPtr & 0x03U) != 0U) ||
            (((uint32) DesDataBufferPtr & 0x03U) != 0U))
        {
            Spi_reportDetError(SPI_SID_SETUP_EB, SPI_E_PARAM_POINTER);
            retVal = (Std_ReturnType) E_NOT_OK;
        }

        if (((Std_ReturnType) E_OK) == retVal)
        {
            /* now check length */
            if ((Length == 0U) || (Length > chObj->chCfg.maxBufLength))
            {
                Spi_reportDetError(SPI_SID_SETUP_EB, SPI_E_PARAM_LENGTH);
                retVal = (Std_ReturnType) E_NOT_OK;
            }
        }
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */

#if (STD_ON == SPI_DMA_ENABLE)
        /* In case of DMA, if number of words are more than FIFO Depth(32)
         * and is not a multiple of FIFO Depth, is not supported */
        if ((Length & (chObj->effTxFifoDepth - 1U)) != 0U)
        {
            retVal = (Std_ReturnType) E_NOT_OK;
        }
#endif

        if (((Std_ReturnType) E_OK) == retVal)
        {
            chObj->txBufPtr     = SrcDataBufferPtr;
            chObj->rxBufPtr     = DesDataBufferPtr;
            chObj->numWordsTxRx = Length;
            retVal = ((Std_ReturnType) E_OK);
        }

        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_0();
    }

    return  (retVal);
}
#endif  /* #if ((SPI_CHANNELBUFFERS == SPI_EB) || (SPI_CHANNELBUFFERS ==
         *SPI_IB_EB)) */

#if ((SPI_SCALEABILITY == SPI_LEVEL_1) || (SPI_SCALEABILITY == \
                                                   SPI_LEVEL_2))
/* Design :  SPI_DesignId_016 */
/* Requirements : MCAL-1239, MCAL-1240, MCAL-1428 */
/*
 * Requirements : MCAL-1310, MCAL-1313, MCAL-1314, MCAL-1328,
 *                MCAL-1411, MCAL-1412, MCAL-1413, MCAL-1414,
 *                MCAL-1415, MCAL-1419, MCAL-1422
 */
SPI_FUNC_TEXT_SECTION FUNC(Std_ReturnType, SPI_CODE) Spi_AsyncTransmit(
    Spi_SequenceType Sequence)
{
    Std_ReturnType retVal = (Std_ReturnType) E_OK;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        Spi_reportDetError(SPI_SID_ASYNC_TRANSMIT, SPI_E_UNINIT);
		retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if (Sequence >= Spi_DrvObj.maxSeq)
    {
        Spi_reportDetError(SPI_SID_ASYNC_TRANSMIT, SPI_E_PARAM_SEQ);
		retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
		if (retVal == (Std_ReturnType) E_OK)
		{
			if (Spi_GetSequenceResult(Sequence) == SPI_SEQ_PENDING)
			{
				Spi_reportDetRuntimeError(SPI_SID_ASYNC_TRANSMIT, SPI_E_SEQ_PENDING);
				retVal = (Std_ReturnType) E_NOT_OK;
			}
			else
			{
				/* Call the start sequence API */
				retVal = Spi_startSeqAsync(&(Spi_DrvObj.seqObj[Sequence]));
				if (((Std_ReturnType) E_NOT_OK) == retVal)
				{
					Spi_reportDetRuntimeError(SPI_SID_ASYNC_TRANSMIT, SPI_E_SEQ_PENDING);
				}
			}
		}
    }

    return (retVal);
}
#endif  /* #if ((SPI_SCALEABILITY == SPI_LEVEL_1) ||
         *(SPI_SCALEABILITY == SPI_LEVEL_2)) */

/*
 * Requirements : MCAL-1486
 */
#if (STD_ON == SPI_CANCEL_API)
/* Design :  SPI_DesignId_017 */
/*
 * Requirements : MCAL-1310, MCAL-1313, MCAL-1328, MCAL-1481,
 *                MCAL-1482, MCAL-1483
 */
SPI_FUNC_TEXT_SECTION FUNC(void, SPI_CODE) Spi_Cancel(Spi_SequenceType Sequence)
{
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        Spi_reportDetError(SPI_SID_CANCEL, SPI_E_UNINIT);
    }
    else if (Sequence >= Spi_DrvObj.maxSeq)
    {
        Spi_reportDetError(SPI_SID_CANCEL, SPI_E_PARAM_SEQ);
    }
    else
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        Spi_cancelSequence(&Spi_DrvObj.seqObj[Sequence]);
    }

    return;
}
#endif  /* #if (STD_ON == SPI_CANCEL_API) */

#if ((SPI_SCALEABILITY == SPI_LEVEL_0) || (SPI_SCALEABILITY == \
                                                   SPI_LEVEL_2))
/* Design :  SPI_DesignId_018 */
/*
 * Requirements : MCAL-1465, MCAL-1466, MCAL-1467, MCAL-1468,
 *                MCAL-1469, MCAL-1473, MCAL-1315
 *
 */
SPI_FUNC_TEXT_SECTION FUNC(Std_ReturnType, SPI_CODE) Spi_SyncTransmit(
    Spi_SequenceType Sequence)
{
    Std_ReturnType   retVal = (Std_ReturnType) E_OK;
#if (STD_OFF == SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT)
    Spi_SequenceType i;
#endif

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        Spi_reportDetError(SPI_SID_SYNC_TRANSMIT, SPI_E_UNINIT);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if (Sequence >= Spi_DrvObj.maxSeq)
    {
        Spi_reportDetError(SPI_SID_SYNC_TRANSMIT, SPI_E_PARAM_SEQ);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
		if (retVal == (Std_ReturnType) E_OK)
		{
			if (Spi_GetSequenceResult(Sequence) == SPI_SEQ_PENDING)
			{
				Spi_reportDetRuntimeError(SPI_SID_SYNC_TRANSMIT, SPI_E_SEQ_PENDING);
				retVal = (Std_ReturnType) E_NOT_OK;
			}
			else
			{
#if (STD_OFF == SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT)
				/* Requirements : MCAL-1473 */
				for (i = (Spi_SequenceType) 0;
					 i < (Spi_SequenceType) Spi_DrvObj.maxSeq;
					 i++)
				{
					if (Spi_GetSequenceResult(i) == SPI_SEQ_PENDING)
					{
						Spi_reportDetRuntimeError(SPI_SID_SYNC_TRANSMIT, SPI_E_SEQ_IN_PROCESS);
						retVal = (Std_ReturnType) E_NOT_OK;
						break;
					}
				}
#endif
			}
		}
        if (((Std_ReturnType) E_OK) == retVal)
        {
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_0();

            /* Call the start sequence API */
            Spi_SeqObjType *seqObjTmp = &(Spi_DrvObj.seqObj[Sequence]);
            retVal = Spi_startSeqSync(seqObjTmp);

            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_0();
        }
    }

    return (retVal);
}
#endif

#if (SPI_SCALEABILITY == SPI_LEVEL_2)
/* Design :  SPI_DesignId_019 */
/*
 * Requirements : MCAL-1487, MCAL-1488, MCAL-1489, MCAL-1490,
 *                MCAL-1491, MCAL-1492, MCAL-1493, MCAL-1494,
 *                MCAL-1495, MCAL-1301
 */
SPI_FUNC_TEXT_SECTION FUNC(Std_ReturnType, SPI_CODE) Spi_SetAsyncMode(
    Spi_AsyncModeType Mode)
{
    Std_ReturnType retVal = (Std_ReturnType) E_OK;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Note: This error return is not mentioned in spec */
        Spi_reportDetError(SPI_SID_SET_ASYNC_MODE, SPI_E_UNINIT);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        if ((uint32) FALSE == Spi_DrvObj.isAsynInProgress)
        {
            Spi_DrvObj.asyncMode = Mode;
        }
        else
        {
            /* Return error incase any ASYNC transmit is in progress */
            retVal = (Std_ReturnType) E_NOT_OK;
        }
    }

    return (retVal);
}
#endif  /* #if (SPI_SCALEABILITY == SPI_LEVEL_2) */

/* Design :  SPI_DesignId_020 */
/*
 * Requirements : MCAL-1496 */
SPI_FUNC_TEXT_SECTION FUNC(void, SPI_CODE) Spi_MainFunction_Handling(void)
{
    uint32 hwUnitIdx;
    Spi_HwUnitObjType *hwUnitObj;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        /* Note: This error return is not mentioned in spec */
        Spi_reportDetError(SPI_SID_MAINFUNCTION_HANDLING, SPI_E_UNINIT);
    }
    else
#endif  /* #if (STD_ON == SPI_DEV_ERROR_DETECT) */
    {
        /* Check all hardware units for any pending sequence */
        for (hwUnitIdx = 0U; hwUnitIdx < Spi_DrvObj.maxHwUnit; hwUnitIdx++)
        {
            hwUnitObj = &Spi_DrvObj.hwUnitObj[hwUnitIdx];
            if ((SPI_POLLING_MODE == Spi_DrvObj.asyncMode) &&
                (NULL_PTR != hwUnitObj->curJobObj))
            {
                Spi_processEvents(hwUnitObj);
            }
        }
    }

    return;
}

#if (STD_ON == SPI_REGISTER_READBACK_API)
SPI_FUNC_TEXT_SECTION FUNC(Std_ReturnType, SPI_CODE) Spi_RegisterReadback(
    Spi_HWUnitType HWUnit,
    P2VAR(Spi_RegisterReadbackType, AUTOMATIC, SPI_APPL_DATA) RegRbPtr)
{
    Spi_HwUnitObjType *hwUnitObj;
    Std_ReturnType     retVal = ((Std_ReturnType) E_OK);

    if ((SPI_UNINIT == Spi_DrvStatus) || (NULL_PTR == RegRbPtr))
    {
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
    {
        (void) memset(RegRbPtr, 0, sizeof (Spi_RegisterReadbackType));

        /* HW unit ID may not be the index, so search for matching HW unit */
        hwUnitObj = Spi_getHwUnitObj(HWUnit);
        if (NULL_PTR != hwUnitObj)
        {
			Spi_mcspiRegReadback(hwUnitObj, RegRbPtr);
        }
        else
        {
            retVal = (Std_ReturnType) E_NOT_OK;
        }
    }

    return (retVal);
}
#endif  /* #if (STD_ON == SPI_REGISTER_READBACK_API) */

#if ((SPI_CHANNELBUFFERS == SPI_IB) || (SPI_CHANNELBUFFERS == SPI_IB_EB))
#if (STD_ON == SPI_DEV_ERROR_DETECT)
SPI_FUNC_TEXT_SECTION static
    FUNC(Std_ReturnType, SPI_CODE) Spi_WriteIBDetErrCheck(
    Spi_ChannelType Channel,
    P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr)
{
    Std_ReturnType retVal = (Std_ReturnType) E_OK;
    if (SPI_UNINIT == Spi_DrvStatus)
    {
        Spi_reportDetError(SPI_SID_WRITE_IB, SPI_E_UNINIT);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if ((Channel >= Spi_DrvObj.maxChannels) ||
             (Spi_DrvObj.channelObj[Channel].chCfg.channelBufType != SPI_IB))
    {
        Spi_reportDetError(SPI_SID_WRITE_IB, SPI_E_PARAM_CHANNEL);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if (((uint32) DataBufferPtr & 0x03U) != 0U)
    {
        Spi_reportDetError(SPI_SID_WRITE_IB, SPI_E_PARAM_POINTER);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
    {
        /* Nothing to be done here - MISRA C Fix */
    }

    return retVal;
}
#endif /* (STD_ON == SPI_DEV_ERROR_DETECT) */
#endif /* (SPI_CHANNELBUFFERS == SPI_IB) || (SPI_CHANNELBUFFERS == SPI_IB_EB) */

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
