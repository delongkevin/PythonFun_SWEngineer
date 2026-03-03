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
 *  \file     Adc.c
 *
 *  \brief    This file contains ADC MCAL driver
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "stdint.h"
#include "string.h"
#include "Adc.h"
#include "Adc_Priv.h"
#include <ti/csl/csl_adc.h>
/* There are static inline functions in hw_types.h file. Map them as well */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
#include <ti/csl/hw_types.h>
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* AUTOSAR version information check has to match definition in header file */
#if ((ADC_AR_RELEASE_MAJOR_VERSION != (4U)) || \
    (ADC_AR_RELEASE_MINOR_VERSION != (3U)) ||  \
    (ADC_AR_RELEASE_REVISION_VERSION != (1U)))
    #error "Adc: AUTOSAR Version Numbers of Adc are different!!"
#endif

/* AUTOSAR version information check has to match definition in header file */
#if ((ADC_SW_MAJOR_VERSION != (2U)) || \
    (ADC_SW_MINOR_VERSION != (0U)) ||  \
    (ADC_SW_PATCH_VERSION != (0U)))
    #error "Adc: Software Version Numbers are inconsistent!!"
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static Std_ReturnType Adc_getStreamPtrCheckDetError(
    Adc_GroupType        Group,
    Adc_ValueGroupType **PtrToSamplePtr);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/* Design : DES_ADC_032 */
/* Requirements : MCAL-1056 */
#define ADC_START_SEC_VAR_INIT_32
#include "Adc_MemMap.h"
/** \brief ADC driver init status */
static volatile VAR(uint32, ADC_VAR_CLEARED) Adc_DrvIsInit = (uint32) FALSE;
#define ADC_STOP_SEC_VAR_INIT_32
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Adc_MemMap.h"
/** \brief ADC driver object */
VAR(Adc_DriverObjType, ADC_VAR_CLEARED) Adc_DrvObj;
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Adc_MemMap.h"

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/* Design : DES_ADC_020 */
/* Requirements : MCAL-3256, MCAL-3257, MCAL-3259, MCAL-3261,
 *                MCAL-3262, MCAL-3267, MCAL-3269, MCAL-3427
 */
FUNC(void, ADC_CODE) Adc_Init(
    P2CONST(Adc_ConfigType, AUTOMATIC, ADC_PBCFG) CfgPtr)
{
    uint32 hwUnitIdx;
    const Adc_ConfigType *ConfigPtr = CfgPtr;

#if (STD_ON == ADC_VARIANT_PRE_COMPILE)
    ConfigPtr = &ADC_INIT_CONFIG_PC;
#endif  /* (STD_ON == ADC_PRE_COMPILE_VARIANT) */

#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) != Adc_DrvIsInit)
    {
        Adc_reportDetError(ADC_SID_INIT, ADC_E_ALREADY_INITIALIZED);
    }
    else if (NULL_PTR == ConfigPtr)
    {
        Adc_reportDetError(ADC_SID_INIT, ADC_E_PARAM_CONFIG);
    }
    else if ((ConfigPtr->maxGroup > ADC_MAX_GROUP) ||
             (ConfigPtr->maxHwUnit > ADC_MAX_HW_UNIT))
    {
        Adc_reportDetError(ADC_SID_INIT, ADC_E_PARAM_CONFIG);
    }
    else if (((uint32) TRUE) != Adc_checkHwUnitObj(ConfigPtr))
    {
        Adc_reportDetError(ADC_SID_INIT, ADC_E_PARAM_CONFIG);
    }
    else
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */
    {
        Adc_resetDrvObj(&Adc_DrvObj);

        /* Copy the configuration */
        Adc_copyConfig(&Adc_DrvObj, ConfigPtr);

        /* Init HW once all config is copied */
        for (hwUnitIdx = 0U; hwUnitIdx < ConfigPtr->maxHwUnit; hwUnitIdx++)
        {
            Adc_HwUnitObjType *hwObj = &(Adc_DrvObj.hwUnitObj[hwUnitIdx]);
            Adc_hwUnitInit(hwObj);
        }

        /* Initialize driver status and object */
        Adc_DrvIsInit = (uint32) TRUE;
    }

    return;
}

/* Design : DES_ADC_022 */
/* Requirements : MCAL-3282 */
#if (STD_ON == ADC_DEINIT_API)
/* Requirements : MCAL-3278, MCAL-3283, MCAL-3284 */
FUNC(void, ADC_CODE) Adc_DeInit(void)
{
    uint32 hwUnitIdx;
    uint32 isError = (uint32) FALSE;
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    uint32 grpIdx;
    Adc_GroupObjType *groupObj;
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */

#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Adc_DrvIsInit)
    {
        Adc_reportDetError(ADC_SID_DEINIT, ADC_E_UNINIT);
    }
    else
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */
    {
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_0();
        for (grpIdx = 0U; grpIdx < Adc_DrvObj.maxGroup; grpIdx++)
        {
            groupObj = &Adc_DrvObj.groupObj[grpIdx];
            if ((ADC_BUSY == groupObj->groupStatus) ||
                (ADC_COMPLETED == groupObj->groupStatus))
            {
                /* These states indicate, that the group is still converting */
                isError = (uint32) TRUE;
            }
            else if (ADC_STREAM_COMPLETED == groupObj->groupStatus)
            {
                /* Check if this group has to be stopped explicitly */
                if (((uint32) TRUE) == groupObj->isExplicitStopMode)
                {
                    /* Group has to be stopped explicitly. State
                     * ADC_STREAM_COMPLETED means, that group is still
                     * converting */
                    isError = (uint32) TRUE;
                }
            }
            else
            {
                /* This group is not converting: continue */
            }

            if (((uint32) TRUE) == isError)
            {
                Adc_reportDetRuntimeError(ADC_SID_DEINIT, ADC_E_BUSY);
            }
        }

        if (((uint32) FALSE) == isError)
        {
            Adc_DrvIsInit = (uint32) FALSE;
            /* Deinit the hardware modules */
            for (hwUnitIdx = 0U; hwUnitIdx < Adc_DrvObj.maxHwUnit; hwUnitIdx++)
            {
                Adc_hwUnitDeInit(&Adc_DrvObj.hwUnitObj[hwUnitIdx]);
            }
            Adc_resetDrvObj(&Adc_DrvObj);
        }
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_0();
    }

    return;
}
#endif  /* #if (STD_ON == ADC_DEINIT_API) */

/* Design : DES_ADC_021 */
/* Requirements : MCAL-3270, MCAL-3271, MCAL-3274, MCAL-3275,
 *                MCAL-3276, MCAL-3277 */
FUNC(Std_ReturnType, ADC_CODE) Adc_SetupResultBuffer(
    Adc_GroupType Group,
    const Adc_ValueGroupType * DataBufferPtr)
{
    Std_ReturnType    retVal = (Std_ReturnType) E_OK;
    Adc_GroupObjType *groupObj;

#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Adc_DrvIsInit)
    {
        Adc_reportDetError(ADC_SID_SETUP_RESULT_BUFFER, ADC_E_UNINIT);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if (Group >= Adc_DrvObj.maxGroup)
    {
        Adc_reportDetError(ADC_SID_SETUP_RESULT_BUFFER, ADC_E_PARAM_GROUP);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if (NULL_PTR == DataBufferPtr)
    {
        Adc_reportDetError(ADC_SID_SETUP_RESULT_BUFFER, ADC_E_PARAM_POINTER);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */
    {
        groupObj = &Adc_DrvObj.groupObj[Group];

        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_0();

        /* Check group status */
        if (ADC_IDLE != groupObj->groupStatus)
        {
            Adc_reportDetRuntimeError(ADC_SID_SETUP_RESULT_BUFFER, ADC_E_BUSY);
            retVal = (Std_ReturnType) E_NOT_OK;
        }
        else
        {
            groupObj->resultBufPtr = DataBufferPtr;
        }

        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_0();
    }

    return (retVal);
}

/* Design : DES_ADC_028 */
/* Requirements : MCAL-3365, MCAL-3366,  */
FUNC(Adc_StatusType, ADC_CODE) Adc_GetGroupStatus(Adc_GroupType Group)
{
    Adc_StatusType    groupStatus = ADC_IDLE;
    Adc_GroupObjType *groupObj;

#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Adc_DrvIsInit)
    {
        Adc_reportDetError(ADC_SID_GET_GROUP_STATUS, ADC_E_UNINIT);
    }
    else if (Group >= Adc_DrvObj.maxGroup)
    {
        Adc_reportDetError(ADC_SID_GET_GROUP_STATUS, ADC_E_PARAM_GROUP);
    }
    else
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */
    {
        groupObj = &Adc_DrvObj.groupObj[Group];

        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_0();

        groupStatus = groupObj->groupStatus;

        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_0();
    }

    return (groupStatus);
}

/* Design : DES_ADC_029 */
/* Requirements : MCAL-3183, MCAL-3367, MCAL-3368, MCAL-3376,
 *                MCAL-3377, MCAL-3379, MCAL-3380, MCAL-3382,
 *                MCAL-3383, MCAL-3384, MCAL-3385, MCAL-3386,
 *                MCAL-3387 */
FUNC(Adc_StreamNumSampleType, ADC_CODE) Adc_GetStreamLastPointer(
    Adc_GroupType Group,
    Adc_ValueGroupType * *PtrToSamplePtr)
{
    Adc_GroupObjType       *groupObj;
    Adc_StreamNumSampleType numSamples = 0U;
    Adc_ChannelObjType     *chObjLast;
    uint32 offset;
    Std_ReturnType          retVal = (Std_ReturnType) E_OK;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_0();

    retVal = Adc_getStreamPtrCheckDetError(Group, PtrToSamplePtr);
    if (((Std_ReturnType) E_OK) == retVal)
    {
        groupObj = &Adc_DrvObj.groupObj[Group];
        if (ADC_BUSY == groupObj->groupStatus)
        {
            *PtrToSamplePtr = NULL;
        }
        else
        {
            numSamples =
                (Adc_StreamNumSampleType) groupObj->validSampleCount;
            /* Reset ValidSampleCount after read process */
            groupObj->validSampleCount = 0U;

            /* Use the last channel pointers to calculate last result
             * pointer as this represents a completion of a set of all
             * channels. If we use any other channel, we could be half way
             * through and might return pointer one location extra */
            chObjLast =
                &groupObj->chObj[groupObj->groupCfg.numChannels - 1U];
            if ((chObjLast->curResultBufPtr) <= (chObjLast->chResultBufPtr))
            {
                /* Pointer is at first element, so offset is last sample */
                offset = (uint32) groupObj->groupCfg.streamNumSamples - 1U;
            }
            else
            {
                offset =
                    chObjLast->curResultBufPtr - chObjLast->chResultBufPtr;
                /* The next result will be written at position [n],
                 * so the latest result in buffer is at [n-1] */
                offset--;
            }
            /* Let PtrToSamplePtr refer to the latest element in
             * application result buffer. */
            *PtrToSamplePtr = (Adc_ValueGroupType *)
								&groupObj->resultBufPtr[offset];

            /* State transition after getting StreamLastPointer */
            if (ADC_COMPLETED == groupObj->groupStatus)
            {
                /* Conversion has not been finished, when the group
                 * was read. State transition to ADC_BUSY */
                groupObj->groupStatus = ADC_BUSY;
            }
            else
            {
                /*
                 * ADC_STREAM_COMPLETED State
                 */

                /* Conversion has been finished before the group was read.
                 * State transition to ADC_IDLE if the group stops
                 * implicitly or to ADC_BUSY if the group has to be
                 * stopped explicitly.
                 */
                if (((uint32) TRUE) == groupObj->isExplicitStopMode)
                {
                    /* Group has to be stopped explicitly, so conversion is
                     * going on after this read. */
                    groupObj->groupStatus = ADC_BUSY;
                }
                else
                {
                    /* Group stops implicitly when ADC_STREAM_COMPLETED is
                     * reached and the group is read. */
                    groupObj->groupStatus = ADC_IDLE;
                }
            }
        }
    }

    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_0();

    return (numSamples);
}

/* Design : DES_ADC_023 */
/* Requirements : MCAL-3290, MCAL-3309 */
#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
/* Requirements : MCAL-3204, MCAL-3285, MCAL-3286, MCAL-3288
 *                MCAL-3291, MCAL-3292, MCAL-3299, MCAL-3300 */
FUNC(void, ADC_CODE) Adc_StartGroupConversion(Adc_GroupType Group)
{
    Std_ReturnType    retVal;
    Adc_GroupObjType *groupObj;

#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Adc_DrvIsInit)
    {
        Adc_reportDetError(ADC_SID_START_GROUP_CONVERSION, ADC_E_UNINIT);
    }
    else if (Group >= Adc_DrvObj.maxGroup)
    {
        Adc_reportDetError(ADC_SID_START_GROUP_CONVERSION, ADC_E_PARAM_GROUP);
    }
    else
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */
    {
        groupObj = &Adc_DrvObj.groupObj[Group];

        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_0();

#if (STD_ON == ADC_DEV_ERROR_DETECT)
        if (NULL_PTR == groupObj->resultBufPtr)
        {
            Adc_reportDetError(
                ADC_SID_START_GROUP_CONVERSION, ADC_E_BUFFER_UNINIT);
        }
        else if (ADC_TRIGG_SRC_HW == groupObj->groupCfg.triggSrc)
        {
            Adc_reportDetError(
                ADC_SID_START_GROUP_CONVERSION, ADC_E_WRONG_TRIGG_SRC);
        }
        else
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */
        {
            /* Call the start group API */
            retVal = Adc_startGroup(groupObj);
            if (((Std_ReturnType) E_NOT_OK) == retVal)
            {
                Adc_reportDetRuntimeError(ADC_SID_START_GROUP_CONVERSION, ADC_E_BUSY);
            }
        }

        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_0();
    }

    return;
}

/* Design : DES_ADC_024 */
/* Requirements : MCAL-3301, MCAL-3308, MCAL-3310, MCAL-3311,
 *                MCAL-3312, MCAL-3313 */
FUNC(void, ADC_CODE) Adc_StopGroupConversion(Adc_GroupType Group)
{
    Adc_GroupObjType *groupObj;
    Std_ReturnType retVal = (Std_ReturnType) E_OK;

#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Adc_DrvIsInit)
    {
        Adc_reportDetError(ADC_SID_STOP_GROUP_CONVERSION, ADC_E_UNINIT);
    }
    else if (Group >= Adc_DrvObj.maxGroup)
    {
        Adc_reportDetError(ADC_SID_STOP_GROUP_CONVERSION, ADC_E_PARAM_GROUP);
    }
    else
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */
    {
        groupObj = &Adc_DrvObj.groupObj[Group];

        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_0();

#if (STD_ON == ADC_DEV_ERROR_DETECT)
        if (ADC_TRIGG_SRC_HW == groupObj->groupCfg.triggSrc)
        {
            Adc_reportDetError(
                ADC_SID_STOP_GROUP_CONVERSION, ADC_E_WRONG_TRIGG_SRC);
			retVal = (Std_ReturnType) E_NOT_OK;
        }
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */
		if (retVal == (Std_ReturnType) E_OK)
		{
			if (ADC_IDLE == groupObj->groupStatus)
			{
				Adc_reportDetRuntimeError(
					ADC_SID_STOP_GROUP_CONVERSION, ADC_E_IDLE);
			}
			else
			{
				/* Call the stop group API */
				Adc_stopGroup(groupObj);
			}
		}

        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_0();
    }

    return;
}
#endif  /* #if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API) */

/* Design : DES_ADC_025 */
/* Requirements : MCAL-3321 */
#if (STD_ON == ADC_READ_GROUP_API)
/* Requirements : MCAL-3184, MCAL-3314, MCAL-3315, MCAL-3316,
 *                MCAL-3317, MCAL-3318, MCAL-3319, MCAL-3320,
 *                MCAL-3322, MCAL-3323, MCAL-3324, MCAL-3367,
 *                MCAL-3368, MCAL-3371, MCAL-3373, MCAL-3374 */
FUNC(Std_ReturnType, ADC_CODE) Adc_ReadGroup(
    Adc_GroupType Group,
    Adc_ValueGroupType * DataBufferPtr)
{
    Std_ReturnType retVal = (Std_ReturnType) E_OK;
    Adc_GroupObjType           *groupObj;
    Adc_ChannelObjType         *chObj, *chObjLast;
    uint32         offset, chIdx;

#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Adc_DrvIsInit)
    {
        Adc_reportDetError(ADC_SID_READ_GROUP, ADC_E_UNINIT);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if (Group >= Adc_DrvObj.maxGroup)
    {
        Adc_reportDetError(ADC_SID_READ_GROUP, ADC_E_PARAM_GROUP);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else if (NULL_PTR == DataBufferPtr)
    {
        /* Note: This error return is not mentioned in spec */
        Adc_reportDetError(ADC_SID_READ_GROUP, ADC_E_PARAM_GROUP);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */
    {
        groupObj = &Adc_DrvObj.groupObj[Group];

        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_0();

        if (ADC_IDLE == groupObj->groupStatus)
        {
            Adc_reportDetRuntimeError(ADC_SID_READ_GROUP, ADC_E_IDLE);
            retVal = (Std_ReturnType) E_NOT_OK;
        }
        else
        {
            if (ADC_BUSY == groupObj->groupStatus)
            {
                retVal = (Std_ReturnType) E_NOT_OK;
            }
            else
            {
                /*
                 * State equals ADC_COMPLETED or ADC_STREAM_COMPLETED, so
                 * results are available: start reading group
                 */

                /* Use the last channel pointers to calculate last result
                 * pointer as this represents a completion of a set of all
                 * channels. If we use any other channel, we could be half way
                 * through and might return pointer one location extra */
                chObjLast =
                    &groupObj->chObj[groupObj->groupCfg.numChannels - 1U];

                if ((chObjLast->curResultBufPtr) <= (chObjLast->chResultBufPtr))
                {
                    /* Pointer is at first element, so offset is last sample */
                    offset = (uint32) groupObj->groupCfg.streamNumSamples - 1U;
                }
                else
                {
                    offset =
                        chObjLast->curResultBufPtr - chObjLast->chResultBufPtr;
                    /* The next result will be written at position [n],
                     * so the latest result in buffer is at [n-1] */
                    offset--;
                }

                for (chIdx = 0U;
                     chIdx < groupObj->groupCfg.numChannels;
                     chIdx++)
                {
                    chObj = &groupObj->chObj[chIdx];
                    DataBufferPtr[chIdx] = chObj->chResultBufPtr[offset];
                }

                /* Reset ValidSampleCount after read process */
                groupObj->validSampleCount = 0U;

                /* State transition after reading to buffer */
                if (ADC_COMPLETED == groupObj->groupStatus)
                {
                    /* Conversion has not been finished, when the group
                     * was read. State transition to ADC_BUSY */
                    groupObj->groupStatus = ADC_BUSY;
                }
                else
                {
                    /*
                     * ADC_STREAM_COMPLETED State
                     */

                    /* Conversion has been finished before the group was read.
                     * State transition to ADC_IDLE if the group stops
                     * implicitly or to ADC_BUSY if the group has to be
                     * stopped explicitly.
                     */
                    if (((uint32) TRUE) == groupObj->isExplicitStopMode)
                    {
                        /* Group has to be stopped explicitly, so conversion is
                         * going on after this read. */
                        groupObj->groupStatus = ADC_BUSY;
                    }
                    else
                    {
                        /* Group stops implicitly when ADC_STREAM_COMPLETED is
                         * reached and the group is read. */
                        groupObj->groupStatus = ADC_IDLE;
                    }
                }
            }
        }

        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_0();
    }

    return (retVal);
}
#endif  /* #if (STD_ON == ADC_READ_GROUP_API) */

/* Design : DES_ADC_026 */
/* Requirements : MCAL-3355, MCAL-3361 */
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY_API)
/* Requirements : MCAL-3353, MCAL-3354, MCAL-3356, MCAL-3357,
 *                MCAL-3358, MCAL-3422 */
FUNC(void, ADC_CODE) Adc_EnableGroupNotification(Adc_GroupType Group)
{
    Adc_GroupObjType *groupObj;

#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Adc_DrvIsInit)
    {
        Adc_reportDetError(ADC_SID_ENABLE_GROUP_NOTIFICATION, ADC_E_UNINIT);
    }
    else if (Group >= Adc_DrvObj.maxGroup)
    {
        Adc_reportDetError(
            ADC_SID_ENABLE_GROUP_NOTIFICATION, ADC_E_PARAM_GROUP);
    }
    else
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */
    {
        groupObj = &Adc_DrvObj.groupObj[Group];

#if (STD_ON == ADC_DEV_ERROR_DETECT)
        /* Check group status */
        if ((Adc_GroupEndNotifyType)NULL_PTR ==
                groupObj->groupCfg.Adc_GroupEndNotification)
        {
            Adc_reportDetError(
                ADC_SID_ENABLE_GROUP_NOTIFICATION, ADC_E_NOTIF_CAPABILITY);
        }
        else
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */
        {
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_0();

            groupObj->isNotifyOn = (uint32) TRUE;

            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_0();
        }
    }

    return;
}

/* Design : DES_ADC_027 */
/* Requirements : MCAL-3359, MCAL-3360, MCAL-3362, MCAL-3363,
 *                MCAL-3364, MCAL-3421 */
FUNC(void, ADC_CODE) Adc_DisableGroupNotification(Adc_GroupType Group)
{
    Adc_GroupObjType *groupObj;

#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Adc_DrvIsInit)
    {
        Adc_reportDetError(ADC_SID_DISABLE_GROUP_NOTIFICATION, ADC_E_UNINIT);
    }
    else if (Group >= Adc_DrvObj.maxGroup)
    {
        Adc_reportDetError(
            ADC_SID_DISABLE_GROUP_NOTIFICATION, ADC_E_PARAM_GROUP);
    }
    else
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */
    {
        groupObj = &Adc_DrvObj.groupObj[Group];

#if (STD_ON == ADC_DEV_ERROR_DETECT)
        /* Check group status */
        if ((Adc_GroupEndNotifyType)NULL_PTR ==
                groupObj->groupCfg.Adc_GroupEndNotification)
        {
            Adc_reportDetError(
                ADC_SID_DISABLE_GROUP_NOTIFICATION, ADC_E_NOTIF_CAPABILITY);
        }
        else
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */
        {
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_0();

            groupObj->isNotifyOn = (uint32) FALSE;

            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_0();
        }
    }

    return;
}
#endif  /* #if (STD_ON == ADC_GRP_NOTIF_CAPABILITY_API) */

#if (STD_ON == ADC_VERSION_INFO_API)
/* Design : DES_ADC_030 */
/* Requirements : MCAL-3388, MCAL-3389 */
FUNC(void, ADC_CODE) Adc_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ADC_APPL_DATA) versioninfo)
{
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if (NULL_PTR == versioninfo)
    {
        Adc_reportDetError(ADC_SID_GET_VERSION_INFO, ADC_E_PARAM_POINTER);
    }
    else
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */
    {
        versioninfo->vendorID         = ADC_VENDOR_ID;
        versioninfo->moduleID         = ADC_MODULE_ID;
        versioninfo->sw_major_version = (uint8) ADC_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8) ADC_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8) ADC_SW_PATCH_VERSION;
    }

    return;
}
#endif  /* #if (STD_ON == ADC_VERSION_INFO_API) */

static Std_ReturnType Adc_getStreamPtrCheckDetError(
    Adc_GroupType        Group,
    Adc_ValueGroupType **PtrToSamplePtr)
{
    Std_ReturnType    retVal = (Std_ReturnType) E_OK;
    Adc_GroupObjType *groupObj;

#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if ((((uint32) FALSE)) == Adc_DrvIsInit)
    {
        if (NULL_PTR != PtrToSamplePtr)
        {
            *PtrToSamplePtr = NULL;
        }
        retVal = (Std_ReturnType) E_NOT_OK;
        Adc_reportDetError(ADC_SID_GET_STREAM_LAST_POINTER, ADC_E_UNINIT);
    }
    else if (Group >= Adc_DrvObj.maxGroup)
    {
        if (NULL_PTR != PtrToSamplePtr)
        {
            *PtrToSamplePtr = NULL;
        }
        retVal = (Std_ReturnType) E_NOT_OK;
        Adc_reportDetError(ADC_SID_GET_STREAM_LAST_POINTER, ADC_E_PARAM_GROUP);
    }
    else if (NULL_PTR == PtrToSamplePtr)
    {
        /* Note: This error return is not mentioned in spec */
        retVal = (Std_ReturnType) E_NOT_OK;
        Adc_reportDetError(
            ADC_SID_GET_STREAM_LAST_POINTER, ADC_E_PARAM_GROUP);
    }
    else
#endif  /* #if (STD_ON == ADC_DEV_ERROR_DETECT) */
    {
        groupObj = &Adc_DrvObj.groupObj[Group];
        if (ADC_IDLE == groupObj->groupStatus)
        {
            *PtrToSamplePtr = NULL;
            retVal          = (Std_ReturnType) E_NOT_OK;
            Adc_reportDetRuntimeError(
                ADC_SID_GET_STREAM_LAST_POINTER, ADC_E_IDLE);
        }
    }


    return retVal;
}

/* Design : DES_ADC_031 */
/* Requirements : MCAL-3658 */
#if (STD_ON == ADC_REGISTER_READBACK_API)
FUNC(Std_ReturnType, ADC_CODE) Adc_RegisterReadback(
    Adc_HWUnitType HWUnit,
    P2VAR(Adc_RegisterReadbackType, AUTOMATIC, ADC_APPL_DATA) RegRbPtr)
{
    Adc_HwUnitObjType *hwUnitObj;
    uint32 baseAddr;
    Std_ReturnType     retVal = ((Std_ReturnType) E_OK);

    if (((uint32) FALSE == Adc_DrvIsInit) || (NULL_PTR == RegRbPtr))
    {
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
    {
        (void) memset(RegRbPtr, 0, sizeof (Adc_RegisterReadbackType));

        /* HW unit ID may not be the index, so search for matching HW unit */
        hwUnitObj = &Adc_DrvObj.hwUnitObj[HWUnit];

        baseAddr = hwUnitObj->baseAddr;
        RegRbPtr->adcRev    = HW_RD_REG32(baseAddr + ADC_REVISION);
        RegRbPtr->adcCtrl   = HW_RD_REG32(baseAddr + ADC_CTRL);
        RegRbPtr->adcMisc   = HW_RD_REG32(baseAddr + ADC_MISC);
    }

    return (retVal);
}
#endif  /* #if (STD_ON == ADC_REGISTER_READBACK_API) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
