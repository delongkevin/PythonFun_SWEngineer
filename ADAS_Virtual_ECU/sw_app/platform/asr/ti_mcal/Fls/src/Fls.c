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
  *  \file      Fls.c
  *
  *  \brief    This file contains Fls MCAL driver
  *
  */

 /* ========================================================================== */
 /*                             Include Files                                  */
 /* ========================================================================== */
#include "string.h"
#include "Fls_Cfg.h"
#include "Fls_Brd_Nor.h"
#if defined (SOC_J721E)
#include "Fls_NOR_m35xu512.h"
#elif defined (SOC_J7200)  || defined (SOC_J721S2)
#include "Fls_NOR_s28hs512t.h"
#endif
#include "Fls_Soc.h"
#include "Det.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* AUTOSAR version information check has to match definition in header file */
#if ((FLS_AR_RELEASE_MAJOR_VERSION != (4U)) || \
    (FLS_AR_RELEASE_MINOR_VERSION != (3U)) ||  \
    (FLS_AR_RELEASE_REVISION_VERSION != (1U)))
    #error "Fls: AUTOSAR Version Numbers of Fls are different!!"
#endif

/* AUTOSAR version information check has to match definition in header file */
#if ((FLS_SW_MAJOR_VERSION != (1U)) || \
    (FLS_SW_MINOR_VERSION != (3U)) ||  \
    (FLS_SW_PATCH_VERSION != (5U)))
    #error "Fls: Software Version Numbers are inconsistent!!"
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

#if (STD_ON == FLS_DEV_ERROR_DETECT)
/**
 * Check Flash bank ranges for a valid address
 *
 */
static Std_ReturnType checkValidAddress( Fls_AddressType SourceAddress )
{
    Std_ReturnType retVal = E_NOT_OK;
    uint32 startAddr = Fls_NorOspiInfo.baseAddr;
    if( (SourceAddress >= startAddr) &&
    	(SourceAddress < (startAddr + NOR_SIZE)) )
    {
        retVal = E_OK;
    }
    return retVal;
}
#endif /*#if (STD_ON == FLS_DEV_ERROR_DETECT)*/

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

Fls_NOR_InfoType Fls_NorOspiInfo =
{
    .manufacturerId = NOR_MANF_ID,
    .deviceId = NOR_DEVICE_ID,
    .busWidth = 0U,
    .blockCnt = NOR_NUM_BLOCKS,
    .pageCnt = NOR_NUM_PAGES_PER_BLOCK,
    .pageSize = NOR_PAGE_SIZE,
    .baseAddr = 0U,
    .sectorSize = NOR_SECTOR_SIZE,
    .sectorCnt = NOR_NUM_SECTORS
};

Fls_NOR_InfoType Fls_NorXspiInfo =//TODO probably don't need to seperate this as includes take care of it
{
    .manufacturerId = NOR_MANF_ID,
    .deviceId = NOR_DEVICE_ID,
    .busWidth = 0U,
    .blockCnt = NOR_NUM_BLOCKS,
    .pageCnt = NOR_NUM_PAGES_PER_BLOCK,
    .pageSize = NOR_PAGE_SIZE,
    .baseAddr = 0U,
    .sectorSize = NOR_SECTOR_SIZE,
    .sectorCnt = NOR_NUM_SECTORS
};

#define FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"
/** \brief FLS driver object */
FLS_VAR_DATA_INIT_UNSPECIFIED_SECTION
Fls_DriverObjType Fls_DrvObj =
{
    .status = MEMIF_UNINIT
};
#define FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/* Design :  DES_FLS_010  */
/* Requirements : MCAL-4217, MCAL-4224, MCAL-4222, MCAL-4219,
 *                MCAL-4223, MCAL-4220, MCAL-4221, MCAL-4218,
 *                MCAL-4191, MCAL-4190, MCAL-4192
 */
FLS_FUNC_TEXT_SECTION FUNC(void, FLS_CODE) Fls_Init(
        P2CONST(Fls_ConfigType, AUTOMATIC, FLS_CONFIG_DATA) ConfigPtr)
{
    const Fls_ConfigType *CfgPtr = ConfigPtr;

#if (STD_ON == FLS_PRE_COMPILE_VARIANT)
    if (NULL_PTR == ConfigPtr)
    {
      CfgPtr = &FLS_INIT_CONFIG_PC;
    }
#endif  /* (STD_ON == SPI_PRE_COMPILE_VARIANT) */

#if (STD_ON == FLS_DEV_ERROR_DETECT)
    if (MEMIF_BUSY == Fls_DrvObj.status)
    {
        Fls_reportDetError(FLS_SID_INIT, FLS_E_BUSY);
    }
    else if(NULL_PTR == CfgPtr)
    {
        Fls_reportDetError(FLS_SID_INIT, FLS_E_PARAM_CONFIG);
    }
    else if ((CfgPtr->maxReadNormalMode == 0U) || ((CfgPtr->maxReadNormalMode % Fls_NorOspiInfo.pageSize) != 0U))
    {
        Fls_reportDetError(FLS_SID_INIT, FLS_E_PARAM_CONFIG);
    }
    else if ((CfgPtr->maxWriteNormalMode == 0U) || ((CfgPtr->maxWriteNormalMode % Fls_NorOspiInfo.pageSize) != 0U))
    {
        Fls_reportDetError(FLS_SID_INIT, FLS_E_PARAM_CONFIG);
    }
    else
#endif /* #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        /* Instantiate a Driver Obj to be used by module */
        Fls_resetDrvObj(&Fls_DrvObj);
        /*Copy the input config parameters to Driver Object */
        Fls_copyConfig(&Fls_DrvObj, CfgPtr);
        Fls_DrvObj.jobResultType = MEMIF_JOB_PENDING;

        /*Init the HW */
        if(Fls_hwUnitInit() == E_OK)
        {
            Fls_DrvObj.jobResultType = MEMIF_JOB_OK;
            Fls_DrvObj.status = MEMIF_IDLE;
        }
    }
    return;
}

/* Design :  DES_FLS_011  */
/* Requirements : MCAL-4231, MCAL-4236, MCAL-4226, MCAL-4227,
 *                MCAL-4237, MCAL-4232, MCAL-4228, MCAL-4230,
 *                MCAL-4229, MCAL-4235. MCAL-4234, MCAL-4190,
 *                MCAL-4191, MCAL-4192
 */
FLS_FUNC_TEXT_SECTION FUNC(Std_ReturnType, FLS_CODE) Fls_Erase(
        Fls_AddressType TargetAddress, Fls_LengthType Length)
{
    Std_ReturnType      retVal = (Std_ReturnType) E_OK;

#if (STD_ON == FLS_DEV_ERROR_DETECT)
    if (MEMIF_UNINIT == Fls_DrvObj.status)
    {
        Fls_reportDetError(FLS_SID_ERASE, FLS_E_UNINIT);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if(MEMIF_BUSY == Fls_DrvObj.status)
    {
        Fls_reportDetError(FLS_SID_ERASE, FLS_E_BUSY);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if (E_NOT_OK == checkValidAddress(TargetAddress))
    {
        Fls_reportDetError(FLS_SID_ERASE, FLS_E_PARAM_ADDRESS);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if ((Length == 0U) || (E_NOT_OK == checkValidAddress(TargetAddress + Length - 1U)))
    {
        Fls_reportDetError(FLS_SID_ERASE, FLS_E_PARAM_LENGTH);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
#endif /* #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        Fls_DrvObj.status = MEMIF_BUSY;
        Fls_DrvObj.jobResultType = MEMIF_JOB_PENDING;
        Fls_DrvObj.jobType = FLS_JOB_ERASE;

        Fls_DrvObj.flashAddr = TargetAddress;
        Fls_DrvObj.ramAddr = NULL;
        Fls_DrvObj.length = Length + (TargetAddress % Fls_NorOspiInfo.sectorSize);
        Fls_DrvObj.transferred = 0;

        Fls_DrvObj.jobChunkSize = Fls_NorOspiInfo.sectorSize;
    }

    return retVal;
};

/* Design :  DES_FLS_014  */
/* Requirements : MCAL-4275, MCAL-4280, MCAL-4270, MCAL-4271,
 *                MCAL-4281, MCAL-4272, MCAL-4274, MCAL-4273,
 *                MCAL-4283, MCAL-4279, MCAL-4278, MCAL-4282,
 *                MCAL-4190, MCAL-4191, MCAL-4192
 */
FLS_FUNC_TEXT_SECTION FUNC(Std_ReturnType, FLS_CODE) Fls_Read(
        Fls_AddressType SourceAddress,
        P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) TargetAddressPtr,
        Fls_LengthType Length)
{
    Std_ReturnType      retVal = (Std_ReturnType) E_OK;

#if (STD_ON == FLS_DEV_ERROR_DETECT)
    if (MEMIF_UNINIT == Fls_DrvObj.status)
    {
        Fls_reportDetError(FLS_SID_READ, FLS_E_UNINIT);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if(MEMIF_BUSY == Fls_DrvObj.status)
    {
        Fls_reportDetError(FLS_SID_READ, FLS_E_BUSY);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if(NULL_PTR == TargetAddressPtr)
    {
        Fls_reportDetError(FLS_SID_READ, FLS_E_PARAM_DATA);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if (E_NOT_OK == checkValidAddress(SourceAddress))
    {
        Fls_reportDetError(FLS_SID_READ, FLS_E_PARAM_ADDRESS);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if ((Length == 0U) || (E_NOT_OK == checkValidAddress(SourceAddress + Length - 1U)))
    {
        Fls_reportDetError(FLS_SID_READ, FLS_E_PARAM_LENGTH);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
#endif /* #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        Fls_DrvObj.status = MEMIF_BUSY;
        Fls_DrvObj.jobResultType = MEMIF_JOB_PENDING;
        Fls_DrvObj.jobType = FLS_JOB_READ;

        Fls_DrvObj.flashAddr = SourceAddress;
        Fls_DrvObj.ramAddr = (uint8*) TargetAddressPtr;
        Fls_DrvObj.length = Length;
        Fls_DrvObj.transferred = 0;

        Fls_DrvObj.jobChunkSize = Fls_DrvObj.maxReadNormalMode;
#if (STD_ON == FLS_USE_INTERRUPTS)
        processJobs(Fls_DrvObj.jobType);
#endif
    }

    return retVal;
}

/* Design :  DES_FLS_012  */
/* Requirements : MCAL-4244, MCAL-4239, MCAL-4249, MCAL-4250,
 *                MCAL-4243, MCAL-4242, MCAL-4245, MCAL-4251,
 *                MCAL-4248, MCAL-4247, MCAL-4190, MCAL-4191,
 *                MCAL-4192, MCAL-4241, MCAL_4252
 */
FLS_FUNC_TEXT_SECTION FUNC(Std_ReturnType, FLS_CODE) Fls_Write(
        Fls_AddressType TargetAddress,
        P2VAR(const uint8, AUTOMATIC, FLS_APPL_DATA) SourceAddressPtr,
        Fls_LengthType Length)
{
    Std_ReturnType      retVal = (Std_ReturnType) E_OK;

#if (STD_ON == FLS_DEV_ERROR_DETECT)
    if (MEMIF_UNINIT == Fls_DrvObj.status)
    {
        Fls_reportDetError(FLS_SID_WRITE, FLS_E_UNINIT);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if(MEMIF_BUSY == Fls_DrvObj.status)
    {
        Fls_reportDetError(FLS_SID_WRITE, FLS_E_BUSY);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if(NULL_PTR == SourceAddressPtr)
    {
        Fls_reportDetError(FLS_SID_WRITE, FLS_E_PARAM_DATA);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if (((TargetAddress % Fls_NorOspiInfo.pageSize) != 0U) || (E_NOT_OK == checkValidAddress(TargetAddress)))
    {
        Fls_reportDetError(FLS_SID_WRITE, FLS_E_PARAM_ADDRESS);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if (((Length == 0U) || ((((TargetAddress + Length) % Fls_NorOspiInfo.pageSize) != 0U)
    || (E_NOT_OK == checkValidAddress(TargetAddress + Length -1U )))))
    {
        Fls_reportDetError(FLS_SID_WRITE, FLS_E_PARAM_LENGTH);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
#endif /* #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        Fls_DrvObj.jobResultType = MEMIF_JOB_PENDING;
        Fls_DrvObj.status = MEMIF_BUSY;
        Fls_DrvObj.jobType = FLS_JOB_WRITE;

        Fls_DrvObj.flashAddr = TargetAddress;
        Fls_DrvObj.ramAddr = (uint8*)SourceAddressPtr;
        Fls_DrvObj.length = Length;
        Fls_DrvObj.transferred = 0;

        Fls_DrvObj.jobChunkSize = Fls_DrvObj.maxWriteNormalMode;
#if (STD_ON == FLS_USE_INTERRUPTS)
        processJobs(Fls_DrvObj.jobType);
#endif
    }
    return retVal;

};

/* Design :  DES_FLS_015  */
/* Requirements : MCAL-4289, MCAL-4286, MCAL-4284, MCAL-4287,
 *                MCAL-4285, MCAL-4294, MCAL-4295, MCAL-4290,
 *                MCAL-4288, MCAL-4297, MCAL-4293, MCAL-4292,
 *                MCAL-4296, MCAL-4190, MCAL-4191, MCAL-4192
 */
#if ( FLS_COMPARE_API == STD_ON )
FLS_FUNC_TEXT_SECTION FUNC(Std_ReturnType, FLS_CODE) Fls_Compare(
        Fls_AddressType SourceAddress,
        P2VAR(const uint8, AUTOMATIC, FLS_APPL_DATA) TargetAddressPtr,
        Fls_LengthType Length)
{
    Std_ReturnType      retVal = (Std_ReturnType) E_OK;

#if (STD_ON == FLS_DEV_ERROR_DETECT)
    if (MEMIF_UNINIT == Fls_DrvObj.status)
    {
        Fls_reportDetError(FLS_SID_COMPARE, FLS_E_UNINIT);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if(MEMIF_BUSY == Fls_DrvObj.status)
    {
        Fls_reportDetError(FLS_SID_COMPARE, FLS_E_BUSY);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if(NULL_PTR == TargetAddressPtr)
    {
        Fls_reportDetError(FLS_SID_COMPARE, FLS_E_PARAM_DATA);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if (E_NOT_OK == checkValidAddress(SourceAddress))
    {
        Fls_reportDetError(FLS_SID_COMPARE, FLS_E_PARAM_ADDRESS);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if ((Length == 0U) || (E_NOT_OK == checkValidAddress(SourceAddress + Length - 1U)))
    {
        Fls_reportDetError(FLS_SID_COMPARE, FLS_E_PARAM_LENGTH);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
#endif /* #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        Fls_DrvObj.status = MEMIF_BUSY;
        Fls_DrvObj.jobResultType = MEMIF_JOB_PENDING;
        Fls_DrvObj.jobType = FLS_JOB_COMPARE;

        Fls_DrvObj.flashAddr = SourceAddress;
        Fls_DrvObj.ramAddr = (uint8*)TargetAddressPtr;
        Fls_DrvObj.length = Length;
        Fls_DrvObj.transferred = 0;

        Fls_DrvObj.jobChunkSize = Fls_DrvObj.maxReadNormalMode;
    }
    return retVal;
}
#endif

/* Design :  DES_FLS_018  */
/* Requirements : MCAL-4309, MCAL-4306, MCAL-4384, MCAL-4304,
 *                MCAL-4314, MCAL-4315, MCAL-4308, MCAL-4310,
 *                MCAL-4307, MCAL-4312, MCAL-4190, MCAL-4191
 *                MCAL-4192
 */
#if ( FLS_BLANK_CHECK_API == STD_ON )
FLS_FUNC_TEXT_SECTION FUNC(Std_ReturnType, FLS_CODE) Fls_BlankCheck(
        Fls_AddressType TargetAddress, Fls_LengthType Length)
{
    Std_ReturnType      retVal = (Std_ReturnType) E_OK;

#if (STD_ON == FLS_DEV_ERROR_DETECT)
    if (MEMIF_UNINIT == Fls_DrvObj.status)
    {
        Fls_reportDetError(FLS_SID_BLANK_CHECK, FLS_E_UNINIT);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if(MEMIF_BUSY == Fls_DrvObj.status)
    {
        Fls_reportDetError(FLS_SID_BLANK_CHECK, FLS_E_BUSY);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if (E_NOT_OK == checkValidAddress(TargetAddress))
    {
        Fls_reportDetError(FLS_SID_BLANK_CHECK, FLS_E_PARAM_ADDRESS);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if ((Length == 0U) || (E_NOT_OK == checkValidAddress(TargetAddress + Length - 1U)))
    {
        Fls_reportDetError(FLS_SID_BLANK_CHECK, FLS_E_PARAM_LENGTH);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
#endif /* #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        Fls_DrvObj.status = MEMIF_BUSY;
        Fls_DrvObj.jobResultType = MEMIF_JOB_PENDING;
        Fls_DrvObj.jobType = FLS_JOB_BLANKCHECK;

        Fls_DrvObj.flashAddr = TargetAddress;
        Fls_DrvObj.ramAddr = NULL;
        Fls_DrvObj.length = Length;
        Fls_DrvObj.transferred = 0;

        Fls_DrvObj.jobChunkSize = Fls_DrvObj.maxReadNormalMode;
    }
    return retVal;
}
#endif


/* Design :  DES_FLS_016  */
/* Requirements : MCAL-4262, MCAL-4391, MCAL-4263, MCAL-4264
 */
#if ( STD_ON == FLS_GET_STATUS_API)
FLS_FUNC_TEXT_SECTION FUNC(MemIf_StatusType, FLS_CODE)
        Fls_GetStatus( void )
{
    return Fls_DrvObj.status;
}
#endif


/* Design :  DES_FLS_013  */
/* Requirements : MCAL-4269, MCAL-4390, MCAL-4265, MCAL-4268,
 *                MCAL-4266, MCAL-4267, MCAL-4191
 */
#if ( FLS_GET_JOB_RESULT_API == STD_ON )
FLS_FUNC_TEXT_SECTION FUNC(MemIf_JobResultType, FLS_CODE)
        Fls_GetJobResult( void )
{
    MemIf_JobResultType jobResult = MEMIF_JOB_FAILED;
#if (STD_ON == FLS_DEV_ERROR_DETECT)
    if (MEMIF_UNINIT == Fls_DrvObj.status)
    {
        Fls_reportDetError(FLS_SID_GET_JOB_RESULT, FLS_E_UNINIT);
    }
    else
#endif /* #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        jobResult = Fls_DrvObj.jobResultType;
    }
    return jobResult;
}
#endif

/* Design :  DES_FLS_017  */
/* Requirements : MCAL-4302, MCAL-4303, MCAL-4190
 */
#if (STD_ON == FLS_VERSION_INFO_API)
FLS_FUNC_TEXT_SECTION FUNC(Std_ReturnType, FLS_CODE) Fls_GetVersionInfo(
        P2VAR(Std_VersionInfoType, AUTOMATIC, FLS_APPL_DATA) versioninfo)
{
    Std_ReturnType      retVal = (Std_ReturnType) E_OK;

#if (STD_ON == FLS_DEV_ERROR_DETECT)
    if (NULL_PTR == versioninfo)
    {
        Fls_reportDetError(FLS_SID_GET_VERSION_INFO, FLS_E_PARAM_POINTER);
        retVal = E_NOT_OK;
    }
    else
#endif  /* #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        versioninfo->vendorID         = FLS_VENDOR_ID;
        versioninfo->moduleID         = FLS_MODULE_ID;
        versioninfo->sw_major_version = (uint8) FLS_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8) FLS_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8) FLS_SW_PATCH_VERSION;
    }
    return retVal;
}
#endif  /* #if (STD_ON == FLS_VERSION_INFO_API) */

/* Design :  DES_FLS_019  */
/* Requirements : MCAL-4318, MCAL-4342, MCAL-4322, MCAL-4337
 *                MCAL-4321, MCAL-4343, MCAL-4328, MCAL-4191
 */
FLS_FUNC_TEXT_SECTION FUNC(void, FLS_CODE) Fls_MainFunction(void)
{

#if (STD_ON == FLS_DEV_ERROR_DETECT)
    if (MEMIF_UNINIT == Fls_DrvObj.status)
    {
        Fls_reportDetError(FLS_SID_MAIN_FUNCTION, FLS_E_UNINIT);
    }
    else
#endif  /* #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        if ( Fls_DrvObj.jobResultType == MEMIF_JOB_PENDING)
        {
            switch (Fls_DrvObj.jobType)
            {
                case FLS_JOB_COMPARE:
                    processJobs(FLS_JOB_COMPARE);
                    break;
                case FLS_JOB_ERASE:
                    processJobs(FLS_JOB_ERASE);
                    break;
                case FLS_JOB_READ:
                    processJobs(FLS_JOB_READ);
                    break;
                case FLS_JOB_WRITE:
                    processJobs(FLS_JOB_WRITE);
                    break;
                case FLS_JOB_BLANKCHECK:
                    processJobs(FLS_JOB_BLANKCHECK);
                    break;
                case FLS_JOB_NONE:
                    break;
                default:
                    break;
            } /* switch */
        }   /* if */
        else
        {
            /* If not pending job, then return end notification */
            Fls_DrvObj.Fls_JobEndNotification();
        }
    }
}

FLS_FUNC_TEXT_SECTION FUNC(void, FLS_CODE) Fls_SwitchMode(boolean dacEnable, boolean xipEnable)
{
    Fls_NorOspiClose(); /*Close the device before reopening with new modes */
    Fls_DrvObj.dacEnable = dacEnable;
    Fls_DrvObj.xipEnable = xipEnable;
    Fls_norOpen();
}


#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
