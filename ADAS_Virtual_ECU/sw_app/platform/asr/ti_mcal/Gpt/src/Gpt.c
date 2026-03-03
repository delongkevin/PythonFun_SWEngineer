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
 *  \file     Gpt.c
 *
 *  \brief    This file contains GPT MCAL driver
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* Design : DES_GPT_001 */
/* Requirements : MCAL-955, MCAL-920, MCAL-921, MCAL-922, MCAL-923, MCAL-925,
                    MCAL-929, MCAL-930, MCAL-932, MCAL-933, MCAL-937, MCAL-938,
                    MCAL-939, MCAL-942, MCAL-947, MCAL-980, MCAL-945, MCAL-1056
                    */
/* Requirements listed above are the common requirements for MCAL modules and
    these requirements are implemented in "Gpt" driver, but cannot be mapped to
    particular line of implementation. */

/* Design : DES_GPT_011 */
/* Requirements : MCAL-1970, MCAL-1986 */
#include "Gpt.h"
#include "SchM_Gpt.h"
#include "stdint.h"

/* Design : DES_GPT_017, DES_GPT_011 */
/* Requirements : MCAL-1972, MCAL-1984 */
#if (STD_ON == GPT_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/* There are static inline functions in hw_types.h file. Map them as well */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
#include <ti/csl/hw_types.h>
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

/* IP Specific include */
#include <ti/csl/cslr_timer.h>

#include "Gpt_Priv.h"
#include "Gpt_Irq.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* AUTOSAR version information check has to match definition in header file */
#if ((GPT_AR_RELEASE_MAJOR_VERSION != (4U)) || \
    (GPT_AR_RELEASE_MINOR_VERSION != (3U)) ||  \
    (GPT_AR_RELEASE_REVISION_VERSION != (1U)))
    #error "Gpt: AUTOSAR Version Numbers of Gpt are different!!"
#endif

/* AUTOSAR version information check has to match definition in header file */
#if ((GPT_SW_MAJOR_VERSION != (1U)) || \
    (GPT_SW_MINOR_VERSION != (3U)) ||  \
    (GPT_SW_PATCH_VERSION != (5U)))
    #error "Gpt: Software Version Numbers are inconsistent!!"
#endif

/** \brief Declaration for GPT Channel HW Obj pointer type */
typedef Gpt_ChannelHwObjType * Gpt_ChannelHwObjPtrType;

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief GPT PC Configuration struct declaration */
extern const struct Gpt_ChannelConfigType_PC_s Gpt_ChannelConfig_PC[GPT_MAX_CHANNELS];
/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
#if (STD_ON == GPT_DEV_ERROR_DETECT)
static Std_ReturnType Gpt_checkChCount(const Gpt_ConfigType *pCfgPtr);
#endif /* STD_ON == GPT_DEV_ERROR_DETECT */
static void Gpt_resetDrvObj(Gpt_DriverObjType *pGptDrvObj);
static void Gpt_copyConfig(Gpt_DriverObjType    *pGptDrvObj,
                           const Gpt_ConfigType *pCfgPtr);
static Std_ReturnType  Gpt_hwUnitInit(uint32                gptChannel,
                                      Gpt_ChannelHwObjType *pHwUnitObj);
static inline Gpt_ChannelHwObjPtrType Gpt_getCurrChannelObj(uint32 chIdx);

#if (STD_ON == GPT_DEINIT_API)
static void Gpt_hwUnitDeInit(const Gpt_ChannelHwObjType *pHwUnitObj);
#endif

static Std_ReturnType Gpt_getTimerType(Gpt_ChannelType channelId,
                                       Gpt_TimerType  *pTimerType);

#if (STD_ON == GPT_REPORT_WAKEUP_SOURCE) && (STD_ON == \
                                                 GPT_WAKEUP_FUNCTIONALITY_API)
static void Gpt_setSleepMode(void);
static void Gpt_setNormalMode(void);
#endif

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#define GPT_START_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"
/** \brief GPT driver init status */
GPT_VAR_DATA_INIT_32_SECTION volatile VAR(uint32, GPT_VAR_CLEARED)
    Gpt_DrvStatus = GPT_DRV_UNINTIALIZED;
#define GPT_STOP_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/* Design : DES_GPT_036 */
/** \brief GPT driver object. */
GPT_VAR_DATA_NO_INIT_UNSPECIFIED_SECTION
    VAR(Gpt_DriverObjType, GPT_VAR_CLEARED) Gpt_DrvObj;
/* Gpt_DrvObj is not static storage class, as this requires to be accessed by
    debug interface provided.  */

#if ((STD_ON == GPT_WAKEUP_FUNCTIONALITY_API) && (STD_ON == \
                                                      GPT_REPORT_WAKEUP_SOURCE))
/* WakeupSource Ref value of configured channels*/
GPT_VAR_DATA_NO_INIT_UNSPECIFIED_SECTION static VAR(EcuM_WakeupSourceType,
           GPT_INTERNAL_VAR_NO_INIT) Gpt_WakeupSourceType[GPT_MAX_CHANNELS];
#endif

#define GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_32
#include "Gpt_MemMap.h"

/*The Array of pointers to the call notification Functions */
GPT_VAR_CONST_32_SECTION CONST(Gpt_IsrRefType, GPT_CONST) Gpt_IsrFxn[2U] =
{
    &Gpt_notifyIsr,
    &Gpt_wakeupIsr
};

#define GPT_STOP_SEC_CONST_32
#include "Gpt_MemMap.h"

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define GPT_START_SEC_CODE

#include "Gpt_MemMap.h"

/* Design : DES_GPT_017, DES_GPT_033 */
/* Requirements : MCAL-1968, MCAL-2092, MCAL-1993 */
#if (STD_ON == GPT_VERSION_INFO_API)
GPT_FUNC_TEXT_SECTION FUNC(void, GPT_CODE) Gpt_GetVersionInfo
    (P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) VersionInfoPtr)
{
#if (STD_ON == GPT_DEV_ERROR_DETECT)
    if (NULL_PTR == VersionInfoPtr)
    {
    /* Design : DES_GPT_037 */
    /* Requirements : MCAL-2519 */
        Gpt_reportDetError(GPT_SID_GET_VERSION_INFO, GPT_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfoPtr->vendorID         = GPT_VENDOR_ID;
        VersionInfoPtr->moduleID         = GPT_MODULE_ID;
        VersionInfoPtr->sw_major_version = (uint8) GPT_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8) GPT_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8) GPT_SW_PATCH_VERSION;
    }

    return;
}
#endif /*(STD_ON == GPT_VERSION_INFO_API)*/

/* Design : DES_GPT_021 */
/*
 * Requirements : MCAL-1994, MCAL-1998, MCAL-1999, MCAL-2000, MCAL-2001,
 *                MCAL-2002
 */
/* Note that some 2002 and 1999, specify dependency on other modules. These
 * requirements are mapped here to specify that this module is not configuring
 * general registers */
GPT_FUNC_TEXT_SECTION FUNC(void, GPT_CODE)
    Gpt_Init( P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_CONST) CfgPtr)
{
    Std_ReturnType         retVal = (Std_ReturnType) E_OK;
    uint32                 chIdx;
    Gpt_ChannelType        gptChannel;
    Gpt_ChannelHwObjType  *pGptChHwObj;
    Gpt_ChannelConfigType_PC *pGptChCfg_PC;
    const Gpt_ConfigType  *ConfigPtr = CfgPtr;

#if (STD_ON == GPT_PRE_COMPILE_VARIANT)
    /* Design : DES_GPT_020 */
    if (NULL_PTR == ConfigPtr)
    {
        ConfigPtr = &GPT_INIT_CONFIG_PC;
    }
#endif /* (STD_ON == GPT_PRE_COMPILE_VARIANT) */
#if (STD_ON == GPT_DEV_ERROR_DETECT)
    /* Design : DES_GPT_017, DES_GPT_021, DES_GPT_037 */
    /* Requirements : MCAL-2003, MCAL-2006, MCAL-2515, MCAL-2516 */
    if (Gpt_DrvStatus == GPT_DRV_INTIALIZED)
    {
        /*
         * Gpt module must not be initialized.
         * Otherwise call the Det with GPT_E_ALREADY_INITIALIZED
         */
        Gpt_reportDetError(GPT_SID_INIT, GPT_E_ALREADY_INITIALIZED);
    }
    else if (NULL_PTR == ConfigPtr)
    {
        /* Design : DES_GPT_037 */
        /* Requirements : MCAL-2519 */
        /*
         * ConfigPtr must not be NULL. In case it is NULL report an error and
         * return immediately.
         */
        Gpt_reportDetError(GPT_SID_INIT, GPT_E_PARAM_POINTER);
    }
    else if ((Std_ReturnType) E_OK != Gpt_checkChCount(ConfigPtr))
    {
        Gpt_reportDetError(GPT_SID_INIT, GPT_E_INIT_FAILED);
    }
    else
#endif /* (STD_ON == GPT_DEV_ERROR_DETECT) */
    {
        /* Reset driver object */
        Gpt_resetDrvObj(&Gpt_DrvObj);
        /* Copy the configuration */
        Gpt_copyConfig(&Gpt_DrvObj, ConfigPtr);

        /* Design : DES_GPT_021 */
        /* Requirements : MCAL-1997, MCAL-1995 */
        /* Only initialize configured resources, that means, only
         * timers listed in the channel configuration structure.
         */
        for (chIdx = 0U; ((chIdx < Gpt_DrvObj.channelCount) &&
                          ((Std_ReturnType) E_OK == retVal));
             chIdx++)
        {
            pGptChHwObj = &(Gpt_DrvObj.channelObj[chIdx]);
            pGptChCfg_PC = &(pGptChHwObj->channelCfg_PC);
            gptChannel = pGptChCfg_PC->channelId;

            /*
             * Resets timer HW module and initialize GPT/Timer hardware object
             * Note: This will keep channel disabled.
             */
            retVal = Gpt_hwUnitInit(gptChannel, pGptChHwObj);
            if (retVal == (Std_ReturnType) E_NOT_OK)
            {
#if (STD_ON == GPT_DEV_ERROR_DETECT)
                Gpt_reportDetError(GPT_SID_INIT, GPT_E_INIT_FAILED);
#endif
            }
            else
            {
                /* Set the channel State to "Initialized"*/
                Gpt_DrvObj.channelState[chIdx] = GPT_INITIALIZED;

                /* Design : DES_GPT_021 */
                /* Requirements : MCAL-2004 */
                /* Reset wakeup Channels */
#if (STD_ON == GPT_WAKEUP_FUNCTIONALITY_API)
                Gpt_DrvObj.channelWakeupEnFlag[chIdx] = (uint32) FALSE;
#endif

                /* Design : DES_GPT_021 */
                /* Requirements : MCAL-1996 */
                /*
                 * The function Gpt_Init shall disable all interrupt
                 * notifications controlled by the GPT driver.
                 */
#if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API)
                Gpt_DrvObj.channelNotifyActiveFlag[chIdx] = (uint32) FALSE;
#endif
            }
        }

        if (retVal == (Std_ReturnType) E_OK)
        {
            /* Initialize driver status, the SetMode function expects driver state
                to be initialized */
            Gpt_DrvStatus = GPT_DRV_INTIALIZED;

            /* Design : DES_GPT_021 */
            /* Requirements : MCAL-2005 */
#if (STD_ON == GPT_REPORT_WAKEUP_SOURCE) && (STD_ON == \
                                                 GPT_WAKEUP_FUNCTIONALITY_API)
            Gpt_SetMode(GPT_MODE_NORMAL);
#endif
        }
    }

    return;
} /* Gpt_Init */

/* Design : DES_GPT_022, DES_GPT_037 */
/* Requirements : MCAL-2008, MCAL-2011, MCAL-2013, MCAL-2512 */

#if (STD_ON == GPT_DEINIT_API)
GPT_FUNC_TEXT_SECTION FUNC(void, GPT_CODE) Gpt_DeInit(void)
{
    uint32                chIdx;
    Std_ReturnType        retVal = (Std_ReturnType) E_OK;
    Gpt_ChannelHwObjType *pGptChHwObj;

#if (STD_ON == GPT_DEV_ERROR_DETECT)
    if (Gpt_DrvStatus != GPT_DRV_INTIALIZED)
    {
        /* Design : DES_GPT_017, DES_GPT_022 */
        /* Requirements : MCAL-2016 */
        /*
         * If the driver is not initialized, the function shall raise the error
         * GPT_E_UNINIT
         */
        Gpt_reportDetError(GPT_SID_DEINIT, GPT_E_UNINIT);
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
#endif
    {
        /* Design : DES_GPT_017, DES_GPT_022 */
        /* Requirements : MCAL-2015 */
        /*
         * If any timer channel is in state "running", the
         * function shall raise the error GPT_E_BUSY.
         */
        for (chIdx = 0U; chIdx < Gpt_DrvObj.channelCount;
             chIdx++)
        {
            if (GPT_RUNNING == Gpt_DrvObj.channelState[chIdx])
            {
                Gpt_reportRuntimeError(GPT_SID_DEINIT, GPT_E_BUSY);
                retVal = (Std_ReturnType) E_NOT_OK;
                break;
            }
        }
    }
    if (retVal != (Std_ReturnType) E_NOT_OK)
    {
        /* Design : DES_GPT_021, DES_GPT_022 */
        /* Requirements : MCAL-2006, MCAL-2012, MCAL-2014 */
        /* Set driver status  to uninitialized */
        Gpt_DrvStatus = GPT_DRV_UNINTIALIZED;
        for (chIdx = 0U; chIdx < Gpt_DrvObj.channelCount;
             chIdx++)
        {
            pGptChHwObj = Gpt_getCurrChannelObj(chIdx);

            /*
             * Deinitialize the hardware used by the GPT driver to the power on
             * reset state.
             */
            Gpt_hwUnitDeInit(pGptChHwObj);

            /* Set the channel State to "Initialized"*/
            Gpt_DrvObj.channelState[chIdx] = GPT_UNINITIALIZED;

#if (STD_ON == GPT_WAKEUP_FUNCTIONALITY_API)
            /* Reset wakeup Channels */
            Gpt_DrvObj.channelWakeupEnFlag[chIdx] = (uint32) FALSE;
#endif
#if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API)
            Gpt_DrvObj.channelNotifyActiveFlag[chIdx] = (uint32) FALSE;
#endif
        }
    }
}
#endif


/* Design : DES_GPT_007, DES_GPT_009, DES_GPT_017,
            DES_GPT_023, DES_GPT_037 */
/* Requirements : MCAL-2018, MCAL-2025, MCAL-2026, MCAL-2512 */
#if (STD_ON == GPT_TIME_ELAPSED_API)
GPT_FUNC_TEXT_SECTION FUNC(Gpt_ValueType, GPT_CODE)
    Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    uint32 retVal = 0U;
    Gpt_ChannelHwObjType *pGptChHwObj;
    uint32 startVal = 0U;
    uint32 countVal = 0U;
    /* Initialized to 0 to suppress warning: chIdx may be used uninitialized */
    uint32 chIdx = 0U;

    pGptChHwObj = Gpt_getHwUnitObj(Channel, &chIdx);
#if (STD_ON == GPT_DEV_ERROR_DETECT)
    if (Gpt_DrvStatus != GPT_DRV_INTIALIZED)
    {
        /*
         * If the driver is not initialized, the function shall raise the error
         * GPT_E_UNINIT
         */
        Gpt_reportDetError(GPT_SID_GET_TIME_ELAPSED, GPT_E_UNINIT);
        retVal = 0U;
    }
    else if (NULL_PTR == pGptChHwObj)
    {
        /* Design : DES_GPT_017, DES_GPT_023, DES_GPT_037 */
        /* Requirements : MCAL-2027, MCAL-2517 */
        /* Channel not valid configured channel */
        Gpt_reportDetError(GPT_SID_GET_TIME_ELAPSED, GPT_E_PARAM_CHANNEL);
        retVal = 0U;
    }
    else
#endif
    {
        if (GPT_INITIALIZED == Gpt_DrvObj.channelState[chIdx])
        {
            /* Design : DES_GPT_023 */
            /* Requirements : MCAL-2021 */
            /* Check if timer is in "initialized" state, if TRUE
             * return value = 0 */
            retVal = 0U;
        }
        else
        {
            /* Design : DES_GPT_023 */
            /* Requirements : MCAL-2024 */
            /* Critical section, block the interrupts */
            SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();

            /*
             * Read the Counter, update counter and free running counter values
             * of the channel
             */
            countVal = Gpt_gptimerCounterGet(pGptChHwObj->baseAddr);
            startVal = Gpt_gptimerReloadGet(pGptChHwObj->baseAddr);

            /* Check if the channel is in Continuous mode*/
            if (GPT_CH_MODE_CONTINUOUS ==
                Gpt_DrvObj.channelObj[chIdx].channelCfg.channelMode)
            {
                /* Design : DES_GPT_023 */
                /* Requirements : MCAL-2020, MCAL-2022 */

                /* Find the relative difference b/w Compare and Free running
                 * counter*/
                retVal = (countVal - startVal);
            }
            else /* One shot mode*/
            {
                /* Design : DES_GPT_023 */
                /* Requirements : MCAL-2019, MCAL-2022, MCAL-2023 */
                /* Return the target time if the channel is
                 * expired, else return the relative difference */
                if (GPT_EXPIRED == Gpt_DrvObj.channelState[chIdx])
                {
                    retVal = (GPTIMER_MAX_RESOLUTION - startVal);
                }
                else
                {
                    retVal = (countVal - startVal);
                }
            }

            /* Critical section, restore the interrupts */
            SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
        }
    }
    return retVal;
}
#endif /*(STD_ON == GPT_TIME_ELAPSED_API)*/

/* Design : DES_GPT_007, DES_GPT_010, DES_GPT_037 */
/* Requirements : MCAL-1967, MCAL-2028, MCAL-2034, MCAL-2512 */
#if (STD_ON == GPT_TIME_REMAINING_API)
GPT_FUNC_TEXT_SECTION FUNC(Gpt_ValueType, GPT_CODE)
    Gpt_GetTimeRemaining(Gpt_ChannelType Channel)

{
    uint32 retVal = 0U;
    Gpt_ChannelHwObjType *pGptChHwObj;
    uint32 countVal = 0U;
    /* Initialized to 0 to suppress warning: chIdx may be used uninitialized */
    uint32 chIdx = 0U;

    pGptChHwObj = Gpt_getHwUnitObj(Channel, &chIdx);
#if (STD_ON == GPT_DEV_ERROR_DETECT)
    if (Gpt_DrvStatus != GPT_DRV_INTIALIZED)
    {
        /* Design : DES_GPT_017, DES_GPT_024 */
        /* Requirements : MCAL-2035 */
        /*
         * If the driver is not initialized, the function shall raise the error
         * GPT_E_UNINIT.
         */
        Gpt_reportDetError(GPT_SID_GET_TIME_REMAINING, GPT_E_UNINIT);
        retVal = 0U;
    }
    else if (NULL_PTR == pGptChHwObj)
    {
        /* Design : DES_GPT_017, DES_GPT_024, DES_GPT_037 */
        /* Requirements : MCAL-2036, MCAL-2517 */
        Gpt_reportDetError(GPT_SID_GET_TIME_REMAINING, GPT_E_PARAM_CHANNEL);
        retVal = 0U;
    }
    else
#endif
    {
        if (GPT_INITIALIZED == Gpt_DrvObj.channelState[chIdx])
        {
            /* Design : DES_GPT_024 */
            /* Requirements : MCAL-2030 */
            /* Check if timer is in "initialized" state, if TRUE
             * return value = 0. */
            retVal = 0U;
        }
        else
        {
            /* Design : DES_GPT_024 */
            /* Requirements : MCAL-2033 */
            /* Critical section, block the interrupts */
            SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();

            /* Get current value of timer count */
            countVal = Gpt_gptimerCounterGet(pGptChHwObj->baseAddr);

            /* Design : DES_GPT_024 */
            /* Requirements : MCAL-2029, MCAL-2031 */
            /* Check if the channel is in Continuous mode, find the remaining
             * time value
             * No Special handling required for stopped timer, as the counter
             * would have stopped counting (countVal).
             */
            if (GPT_CH_MODE_CONTINUOUS ==
                Gpt_DrvObj.channelObj[chIdx].channelCfg.channelMode)
            {
                /* This will also take care of case where channel is stopped */
                retVal = (GPTIMER_MAX_RESOLUTION - countVal);
            }
            else
            {
                /* One shot mode */
                /* If the channel is expired in one-shot mode, return value
                 * zero. */
                if (GPT_EXPIRED == Gpt_DrvObj.channelState[chIdx])
                {
                    /* Design : DES_GPT_024 */
                    /* Requirements : MCAL-2032 */
                    retVal = 0U;
                }
                else
                {
                    /*This'll also take care of case where channel is stopped.*/
                    retVal = (GPTIMER_MAX_RESOLUTION - countVal);
                }
            }
            /* Critical section, restore the interrupts. */
            SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
        }
    }
    return retVal;
}
#endif /*(STD_ON == GPT_TIME_REMAINING_API)*/

/* Design : DES_GPT_025, DES_GPT_037 */
/* Requirements : MCAL-2037, MCAL-2512 */
GPT_FUNC_TEXT_SECTION FUNC(void, GPT_CODE)
                Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    Gpt_ChannelHwObjType *pGptChHwObj;
    /* Initialized to 0 to suppress warning: chIdx may be used uninitialized */
    uint32 chIdx = 0U;

    pGptChHwObj = Gpt_getHwUnitObj(Channel, &chIdx);
#if (STD_ON == GPT_DEV_ERROR_DETECT)
    if (Gpt_DrvStatus != GPT_DRV_INTIALIZED)
    {
        /* Design : DES_GPT_017, DES_GPT_025 */
        /* Requirements : MCAL-2044 */
        /*
         * If the driver is not initialized, the function shall raise the error
         * GPT_E_UNINIT.
         */
        Gpt_reportDetError(GPT_SID_START_TIMER, GPT_E_UNINIT);
    }
    /* Check if parameter channel is in valid range. */
    else if (NULL_PTR == pGptChHwObj)
    {
        /* Design : DES_GPT_017, DES_GPT_025, DES_GPT_037 */
        /* Requirements : MCAL-2042, MCAL-2517 */
        Gpt_reportDetError(GPT_SID_START_TIMER, GPT_E_PARAM_CHANNEL);
    }
    else if ((Value == 0U) || (Value == GPTIMER_MAX_RESOLUTION))
    {
        /* Design : DES_GPT_017, DES_GPT_025, DES_GPT_037 */
        /* Requirements : MCAL-2043, MCAL-2518 */
        /*
         * Parameter value not in valid range. If "0" is specified
         * as value, report an error and set flag.
         */
        /* GP timer hw limitation: It is not recommended to put the
         * overflow value (0xFFFFFFFF) in TLDR because it can lead
         * to undesired results
         */
        Gpt_reportDetError(GPT_SID_START_TIMER, GPT_E_PARAM_VALUE);
    }
    else
#endif
    {
        if (GPT_RUNNING == Gpt_DrvObj.channelState[chIdx])
        {
            /* Design : DES_GPT_017, DES_GPT_025, DES_GPT_037 */
            /* Requirements : MCAL-2045, MCAL-2513 */
            /* Channel is already running, report error GPT_E_BUSY. */
            Gpt_reportRuntimeError(GPT_SID_START_TIMER, GPT_E_BUSY);
        }
        else
        {
            /* Design : DES_GPT_025 */
            /* Requirements : MCAL-2040, MCAL-2041 */

            /* Critical section, block the interrupts */
            SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();

    #if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API)
            Gpt_gptimerStart(pGptChHwObj, Value,
                                Gpt_DrvObj.channelNotifyActiveFlag[chIdx]);
    #else
            Gpt_gptimerStart(pGptChHwObj, Value, (uint32) FALSE);
    #endif /* (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API) */

            Gpt_DrvObj.channelState[chIdx] = GPT_RUNNING;
            /* Critical section, restore the interrupts */
            SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
        }
    }
    return;
}

/* Design : DES_GPT_017, DES_GPT_026, DES_GPT_037 */
/* Requirements : MCAL-2046, MCAL-2049, MCAL-2512 */

GPT_FUNC_TEXT_SECTION FUNC(void, GPT_CODE) Gpt_StopTimer(Gpt_ChannelType Channel)
{
    Gpt_ChannelHwObjType *pGptChHwObj;
    /* Initialized to 0 to suppress warning: chIdx may be used uninitialized */
    uint32 chIdx = 0U;

    pGptChHwObj = Gpt_getHwUnitObj(Channel, &chIdx);
#if (STD_ON == GPT_DEV_ERROR_DETECT)
    if (Gpt_DrvStatus != GPT_DRV_INTIALIZED)
    {
        /* Design : DES_GPT_017, DES_GPT_026 */
        /* Requirements : MCAL-2053 */
        /*
         * If the driver is not initialized, the function shall raise the error
         * GPT_E_UNINIT.
         */
        Gpt_reportDetError(GPT_SID_STOP_TIMER, GPT_E_UNINIT);
    }
    /* Check if parameter channel is in valid range */
    else if (NULL_PTR == pGptChHwObj)
    {
        /* Design : DES_GPT_017, DES_GPT_026, DES_GPT_037 */
        /* Requirements : MCAL-2052, MCAL-2517 */
        Gpt_reportDetError(GPT_SID_STOP_TIMER, GPT_E_PARAM_CHANNEL);
    }
    else
#endif
    {
        /* Design : DES_GPT_026 */
        /* Requirements : MCAL-2047, MCAL-2050, MCAL-2051 */

        if (GPT_RUNNING == Gpt_DrvObj.channelState[chIdx])
        {
            /* Critical section, block the interrupts */
            SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();

            /* Design : DES_GPT_026 */
            /* Requirements : MCAL-2047 */

            /* Stop counting */
            Gpt_gptimerStop(pGptChHwObj);

            /* Design : DES_GPT_026 */
            /* Requirements : MCAL-2048 */
            Gpt_DrvObj.channelState[chIdx] = GPT_STOPPED;

            /* Critical section, restore the interrupts */
            SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
        }
    }
    return;
}

/* Design : DES_GPT_027, DES_GPT_037 */
/* Requirements : MCAL-2054, MCAL-2057, MCAL-2512 */

#if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API)
GPT_FUNC_TEXT_SECTION FUNC(void, GPT_CODE)
    Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    Gpt_ChannelHwObjType *pGptChHwObj;
    /* Initialized to 0 to suppress warning: chIdx may be used uninitialized */
    uint32 chIdx = 0U;

    pGptChHwObj = Gpt_getHwUnitObj(Channel, &chIdx);
#if (STD_ON == GPT_DEV_ERROR_DETECT)
    if (Gpt_DrvStatus != GPT_DRV_INTIALIZED)
    {
        /* Design : DES_GPT_017, DES_GPT_027 */
        /* Requirements : MCAL-2058 */
        /*
         * If the driver is not initialized, the function shall raise the error
         * GPT_E_UNINIT.
         */
        Gpt_reportDetError(GPT_SID_ENABLE_NOTIFY, GPT_E_UNINIT);
    }
    /* Check if parameter channel is in valid range */
    else if (NULL_PTR == pGptChHwObj)
    {
        /* Design : DES_GPT_017, DES_GPT_027, DES_GPT_037 */
        /* Requirements : MCAL-2059, MCAL-2517 */
        Gpt_reportDetError(GPT_SID_ENABLE_NOTIFY, GPT_E_PARAM_CHANNEL);
    }
    else if (NULL ==
             pGptChHwObj->channelCfg.fnPtrNotifyFunction)
    {
        /* Design : DES_GPT_017, DES_GPT_027, DES_GPT_037 */
        /* Requirements : MCAL-2060, MCAL-2517*/
        Gpt_reportDetError(GPT_SID_ENABLE_NOTIFY, GPT_E_PARAM_CHANNEL);
    }
    else
#endif
    {
        /* Notification could be enabled, when the channel state is either in
            GPT_INITIALIZED, GPT_RUNNING, GPT_STOPPED & GPT_STOPPED */
        if (GPT_UNINITIALIZED != Gpt_DrvObj.channelState[chIdx])
        {
            /* Design : DES_GPT_027 */
            /* Requirements : MCAL-2056 */

            /* Critical section, block the interrupts */
            SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();
            /* Set the channel mode for notification index */
            Gpt_DrvObj.channelObj[chIdx].channelIsrFnIdx = GPT_CH_MODE_NOTIFY;

            /* Design : DES_GPT_027 */
            /* Requirements : MCAL-2055 */

            /* Require to explicitly enable the interrupt, as disabled channels
             * should not generate the interrupt also.
             */
            Gpt_gptimerEnableNotify(pGptChHwObj);

            /* Set the notification active flag to TRUE */
            Gpt_DrvObj.channelNotifyActiveFlag[chIdx] = (uint32) TRUE;

            /* Critical section, restore the interrupts */
            SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
        }
    }
    return;
}
#endif /*(STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API)*/

/* Design : DES_GPT_028, DES_GPT_037 */
/* Requirements : MCAL-2061, MCAL-2064, MCAL-2512 */

#if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API)
GPT_FUNC_TEXT_SECTION FUNC(void, GPT_CODE)
    Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    Gpt_ChannelHwObjType *pGptChHwObj;
    /* Initialized to 0 to suppress warning: chIdx may be used uninitialized */
    uint32 chIdx = 0U;

    pGptChHwObj = Gpt_getHwUnitObj(Channel, &chIdx);
#if (STD_ON == GPT_DEV_ERROR_DETECT)
    if (Gpt_DrvStatus != GPT_DRV_INTIALIZED)
    {
        /* Design : DES_GPT_017, DES_GPT_028 */
        /* Requirements : MCAL-2065 */
        /*
         * If the driver is not initialized, the function shall raise the error
         * GPT_E_UNINIT
         */
        Gpt_reportDetError(GPT_SID_DISABLE_NOTIFY, GPT_E_UNINIT);
    }
    /* Design : DES_GPT_017, DES_GPT_028, DES_GPT_037 */
    /* Requirements : MCAL-2066, MCAL-2067, MCAL-2517 */
    /* Check if parameter channel is in valid range */
    else if (NULL_PTR == pGptChHwObj)
    {
        Gpt_reportDetError(GPT_SID_DISABLE_NOTIFY, GPT_E_PARAM_CHANNEL);
    }
    else if (NULL ==
             pGptChHwObj->channelCfg.fnPtrNotifyFunction)
    {
        Gpt_reportDetError(GPT_SID_DISABLE_NOTIFY, GPT_E_PARAM_CHANNEL);
    }
    else
#endif
    {
        /* Design : DES_GPT_028 */
        /* Requirements : MCAL-2063 */
        /* Critical section, block the interrupts */
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();

        /* Design : DES_GPT_028 */
        /* Requirements : MCAL-2062 */
        Gpt_gptimerDisableNotify(pGptChHwObj);

        /* Set the notification active flag to FALSE */
        Gpt_DrvObj.channelNotifyActiveFlag[chIdx] = (uint32) FALSE;

        /* Critical section, restore the interrupts */
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
    }
    return;
}
#endif /*(STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API)*/


/* Design : DES_GPT_029, DES_GPT_037 */
/* Requirements : MCAL-2068, MCAL-2069, MCAL-2071, MCAL-2078, MCAL-2512 */
#if (STD_ON == GPT_REPORT_WAKEUP_SOURCE) && (STD_ON == \
                                                 GPT_WAKEUP_FUNCTIONALITY_API)
GPT_FUNC_TEXT_SECTION FUNC(void, GPT_CODE) Gpt_SetMode(Gpt_ModeType Mode)
{
#if (STD_ON == GPT_DEV_ERROR_DETECT)
    if (Gpt_DrvStatus != GPT_DRV_INTIALIZED)
    {
        /* Design : DES_GPT_017, DES_GPT_029 */
        /* Requirements : MCAL-2076 */
        /*
         * If the driver is not initialized, the function shall raise the error
         * GPT_E_UNINIT
         */
        Gpt_reportDetError(GPT_SID_SET_MODE, GPT_E_UNINIT);
    }
    else if ((Mode != GPT_MODE_SLEEP) && (Mode != GPT_MODE_NORMAL))
    {
        /* Design : DES_GPT_017, DES_GPT_029, DES_GPT_037 */
        /* Requirements : MCAL-2077, MCAL-2520 */
        /* Mode parameter is valid. */
        Gpt_reportDetError(GPT_SID_SET_MODE, GPT_E_PARAM_MODE);
    }
    else
#endif
    {
        if (Mode == GPT_MODE_SLEEP)
        {
            /* Setting to sleep mode if not done before? */
            if (GPT_MODE_SLEEP != Gpt_DrvObj.sleepMode)
            {
                /* Set sleep mode as Gpt operation mode*/
                Gpt_setSleepMode();
            }
        }
        else
        {
            /* Set to normal mode if not done before. */
            if (GPT_MODE_NORMAL != Gpt_DrvObj.sleepMode)
            {
                /* Set normal mode as Gpt operation mode*/
                Gpt_setNormalMode();
            }
        }
    }

    return;
}
#endif /*(STD_ON == GPT_WAKEUP_FUNCTIONALITY_API)*/

/* Design : DES_GPT_030, DES_GPT_037 */
/* Requirements : MCAL-2081, MCAL-2083, MCAL-2085, MCAL-2512 */
#if (STD_ON == GPT_REPORT_WAKEUP_SOURCE) && (STD_ON == \
                                                 GPT_WAKEUP_FUNCTIONALITY_API)
GPT_FUNC_TEXT_SECTION FUNC(void, GPT_CODE)
    Gpt_DisableWakeup(Gpt_ChannelType Channel)
{
    Gpt_ChannelHwObjType *pGptChHwObj;
    /* Initialized to 0 to suppress warning: chIdx may be used uninitialized */
    uint32 chIdx = 0U;

    pGptChHwObj = Gpt_getHwUnitObj(Channel, &chIdx);

#if (STD_ON == GPT_DEV_ERROR_DETECT)
    if (Gpt_DrvStatus != GPT_DRV_INTIALIZED)
    {
        /* Design : DES_GPT_017, DES_GPT_030 */
        /* Requirements : MCAL-2087 */
        /*
         * If the driver is not initialized, the function shall raise the error
         * GPT_E_UNINIT
         */
        Gpt_reportDetError(GPT_SID_DISABLE_WAKEUP, GPT_E_UNINIT);
    }
    /* Check if parameter channel is in valid range */
    else if (NULL_PTR == pGptChHwObj)
    {
        /* Design : DES_GPT_017, DES_GPT_030, DES_GPT_037 */
        /* Requirements : MCAL-2086, MCAL-2517 */
        Gpt_reportDetError(GPT_SID_DISABLE_WAKEUP, GPT_E_PARAM_CHANNEL);
    }
    else if (pGptChHwObj->channelCfg.enableWakeupFlag == (uint8) FALSE)
    {
        /* Design : DES_GPT_030 */
        /* Requirements : MCAL-2086 */
        /* If channel wakeup is not enabled by configuration (GptEnableWakeup),
         * the function Gpt_DisableWakeup shall raise the error
         * GPT_E_PARAM_CHANNEL */
        Gpt_reportDetError(GPT_SID_DISABLE_WAKEUP, GPT_E_PARAM_CHANNEL);
    }
    else
#endif
    {
        /* Design : DES_GPT_030 */
        /* Requirements : MCAL-2084 */

        /* Critical section, block the interrupts */
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();

        /* Set the wakeup active flag to FALSE */
        Gpt_DrvObj.channelWakeupEnFlag[chIdx] = (uint32) FALSE;
        /* Disable wakeup interrupt */
        Gpt_gptimerDisableWakeup(pGptChHwObj);
        /* Critical section, restore the interrupts */
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
    }
    return;
}
#endif /*(STD_ON == GPT_WAKEUP_FUNCTIONALITY_API)*/


/* Design : DES_GPT_031, DES_GPT_037 */
/* Requirements : MCAL-2088, MCAL-2090, MCAL-2092, MCAL-2512 */
#if (STD_ON == GPT_REPORT_WAKEUP_SOURCE) && (STD_ON == \
                                                 GPT_WAKEUP_FUNCTIONALITY_API)
GPT_FUNC_TEXT_SECTION FUNC(void, GPT_CODE)
    Gpt_EnableWakeup(Gpt_ChannelType Channel)
{
    Gpt_ChannelHwObjType *pGptChHwObj;
    uint32 chIdx;

    pGptChHwObj = Gpt_getHwUnitObj(Channel, &chIdx);
#if (STD_ON == GPT_DEV_ERROR_DETECT)
    if (Gpt_DrvStatus != GPT_DRV_INTIALIZED)
    {
        /* Design : DES_GPT_017, DES_GPT_031 */
        /* Requirements : MCAL-2093 */

        /*
         * If the driver is not initialized, the function shall raise the error
         * GPT_E_UNINIT
         */
        Gpt_reportDetError(GPT_SID_ENABLE_WAKEUP, GPT_E_UNINIT);
    }
    /* Check if parameter channel is in valid range */
    else if (NULL_PTR == pGptChHwObj)
    {
        /* Design : DES_GPT_017, DES_GPT_031, DES_GPT_037 */
        /* Requirements : MCAL-2094, MCAL-2517 */
        Gpt_reportDetError(GPT_SID_ENABLE_WAKEUP, GPT_E_PARAM_CHANNEL);
    }
    /* Check if channel is wakeup capable (reference ID != 0). If not report an
     * error and return immediately. */
    else if (pGptChHwObj->channelCfg.enableWakeupFlag == (uint8) FALSE)
    {
        /* Design : DES_GPT_031, DES_GPT_037 */
        /* Requirements : MCAL-2094, MCAL-2517 */
        Gpt_reportDetError(GPT_SID_ENABLE_WAKEUP, GPT_E_PARAM_CHANNEL);
    }
    else
#endif
    {
        /* Design : DES_GPT_031 */
        /* Requirements : MCAL-2089, MCAL-2091 */

        /* Critical section, block the interrupts */
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();

        /* Set the channel mode for notification index */
        pGptChHwObj->channelIsrFnIdx = GPT_CH_MODE_WAKEUP;

        /* WakeupSource for the referenced Channel is stored in
         * Gpt_WakeupSourceType */
        Gpt_WakeupSourceType[chIdx] =
            pGptChHwObj->channelCfg.wakeupSourceRef;

        /* Set the wakeup active flag to TRUE */
        Gpt_DrvObj.channelWakeupEnFlag[chIdx] = (uint32) TRUE;
        Gpt_gptimerEnableWakeup(pGptChHwObj);

        /* Critical section, restore the interrupts */
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
    }
    return;
}
#endif /*(STD_ON == GPT_WAKEUP_FUNCTIONALITY_API)*/


/* Design : DES_GPT_032, DES_GPT_037 */
/* Requirements : MCAL-2095, MCAL-2097, MCAL-2098, MCAL-2099, MCAL-2512 */
#if (STD_ON == GPT_REPORT_WAKEUP_SOURCE) && (STD_ON == \
                                                 GPT_WAKEUP_FUNCTIONALITY_API)
GPT_FUNC_TEXT_SECTION FUNC(void, GPT_CODE)
    Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    uint32                chIdx;
    Gpt_ChannelType       gptChannel   = 0U;
    EcuM_WakeupSourceType chlWakeupRef = 0U;
    uint8 wakeupChFound = (uint8) FALSE;

#if (STD_ON == GPT_DEV_ERROR_DETECT)
    if (Gpt_DrvStatus != GPT_DRV_INTIALIZED)
    {
        /* Design : DES_GPT_017, DES_GPT_032 */
        /* Requirements : MCAL-2100 */
        /*
         * If the driver is not initialized, the function shall raise the error
         * GPT_E_UNINIT
         */
        Gpt_reportDetError(GPT_SID_CHECK_WAKEUP, GPT_E_UNINIT);
    }
    else
#endif
    {
        /* Design : DES_GPT_032 */
        /* Requirements : MCAL-2096 */
        /*
         * Check if delivered wakeupSource comes from configured wakeup capable
         * timer channel.
         */
        for (chIdx = 0U; chIdx < Gpt_DrvObj.channelCount;
             chIdx++)
        {
            chlWakeupRef =
                (EcuM_WakeupSourceType) (Gpt_DrvObj.channelObj[chIdx].
                                         channelCfg.wakeupSourceRef);

            if (WakeupSource == chlWakeupRef)
            {
                /* configured wakeup capable timer found; leave loop */
                wakeupChFound = (uint8) TRUE;
                gptChannel    =
                    Gpt_DrvObj.channelObj[chIdx].channelCfg_PC.channelId;
                break;
            }
        } /* End of for */

        /* Check if configured wakeup capable timer was found */
        if (wakeupChFound == (uint8) TRUE)
        {
            /*
             * Check if delivered wakeupSource comes from wakeup enabled timer
             * channel
             */
            if ((uint32) TRUE == Gpt_DrvObj.channelWakeupEnFlag[gptChannel])
            {
                /* Wakeup Channel is active, Call Wake up function */
                EcuM_SetWakeupEvent(chlWakeupRef);
            }
        }
    }
    return;
}
#endif

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
#if (STD_ON == GPT_DEV_ERROR_DETECT)
GPT_FUNC_TEXT_SECTION static Std_ReturnType
                                Gpt_checkChCount(const Gpt_ConfigType *pCfgPtr)
{
    Std_ReturnType retVal = E_OK;
    if (pCfgPtr->channelCount > GPT_MAX_CHANNELS)
    {
        retVal = E_NOT_OK;
    }
    return retVal;
}
#endif
/**
 * \brief   This API will reset GPT s/w driver object.
 *
 * \param   pGptDrvObj       Pointer to driver object.
 *
 * \return  None.
 *
 **/
GPT_FUNC_TEXT_SECTION static void Gpt_resetDrvObj(Gpt_DriverObjType *pGptDrvObj)
{
    uint32 chIdx;

    pGptDrvObj->channelCount = 0U;
    for (chIdx = 0U; chIdx < GPT_MAX_CHANNELS; chIdx++)
    {
        (void) memset(&(pGptDrvObj->channelObj[chIdx]), 0,
                      sizeof (pGptDrvObj->channelObj[chIdx]));
        /**< Set channel state to uninitialized */
        (void) memset(&(pGptDrvObj->channelState[chIdx]), 0,
                      sizeof (pGptDrvObj->channelState[chIdx]));
#if (STD_ON == GPT_WAKEUP_FUNCTIONALITY_API)
        /**< Set channel wakeup enable state to disabled */
        (void) memset(&(pGptDrvObj->channelWakeupEnFlag[chIdx]), 0,
                      sizeof (pGptDrvObj->channelState[chIdx]));
#endif
#if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API)
        /**< Set channel notification state to  disabled */
        (void) memset(&(pGptDrvObj->channelNotifyActiveFlag[chIdx]), 0,
                      sizeof (pGptDrvObj->channelState[chIdx]));
#endif
        pGptDrvObj->channelIdMap[chIdx] = 0U;
        /* Initialize to first timer */
    }

    return;
}

/**
 * \brief   This API will copy all channel configuration into local Gpt Object
 *
 * \param   pGptDrvObj      Pointer to driver object.
 * \param   pCfgPtr         Pointer to configuration object sent by application.
 *
 * \return  None.
 *
 **/
GPT_FUNC_TEXT_SECTION static void Gpt_copyConfig(Gpt_DriverObjType *pGptDrvObj,
                                                 const Gpt_ConfigType *pCfgPtr)
{
    uint32 chIdx;

    pGptDrvObj->channelCount = pCfgPtr->channelCount;

    /* Can't do memcpy as no. of configured channel can be
     * less than no. of maximum channels available */
    for (chIdx = 0U; chIdx < pCfgPtr->channelCount; chIdx++)
    {
        /* Copy channel cfg of configured channels */
        (void) memcpy(&(pGptDrvObj->channelObj[chIdx].channelCfg),
                      &(pCfgPtr->ChannelCfgPtr[chIdx]),
                      sizeof (pGptDrvObj->channelObj[chIdx].channelCfg));
        /* Copy channel Id of configured channels */
        (void) memcpy(&(pGptDrvObj->channelObj[chIdx].channelCfg_PC),
                      &(Gpt_ChannelConfig_PC[chIdx]),
                      sizeof (Gpt_ChannelConfigType_PC));
        pGptDrvObj->channelIdMap
                [pGptDrvObj->channelObj[chIdx].channelCfg_PC.channelId] = chIdx;
    }

    return;
}

/**
 * \brief   This API will initialize GPT HW object associated with logical
 *          channel.
 *
 * \param   pGptDrvObj      Pointer to HW object.
 *
 * \return  None.
 *
 **/
GPT_FUNC_TEXT_SECTION static Std_ReturnType Gpt_hwUnitInit(uint32 gptChannel,
                                       Gpt_ChannelHwObjType *pHwUnitObj)
{
    Std_ReturnType retVal;
    Gpt_TimerType  timerType;

    retVal = Gpt_getTimerType(gptChannel, &timerType);
    if (retVal == (Std_ReturnType) E_OK)
    {
        /*
         * Save timer type for this channel into hw unit object for future use
         */
        pHwUnitObj->timerType = timerType;

        Gpt_gptimerInit(gptChannel, pHwUnitObj);
    }
    else
    {
        pHwUnitObj->timerType = timerType;
        retVal = (Std_ReturnType) E_NOT_OK;
    }

    return retVal;
}

/**
 * \brief   This API will de initialize GPT HW object associated with logical
 *          channel.
 *
 * \param   pGptDrvObj      Pointer to HW object.
 *
 * \return  None.
 *
 **/
#if (STD_ON == GPT_DEINIT_API)
GPT_FUNC_TEXT_SECTION static void Gpt_hwUnitDeInit(
    const Gpt_ChannelHwObjType *pHwUnitObj)
{
    /* Only GPT_TIMERTYPE_GPTIMER == pHwUnitObj->timerType supported now */
    Gpt_gptimerDeInit(pHwUnitObj);
    return;
}

#endif

/**
 * \brief   This API will return timer type.
 *
 * \param   channelId: channel id.
 *
 * \return  timerType: channel type.
 *
 **/
GPT_FUNC_TEXT_SECTION static Std_ReturnType  Gpt_getTimerType(
    Gpt_ChannelType channelId, Gpt_TimerType  *pTimerType)
{
    Std_ReturnType retVal;

    switch (channelId)
    {
        case GPT_CH_GPTIMER1:
        case GPT_CH_GPTIMER2:
        case GPT_CH_GPTIMER3:
        case GPT_CH_GPTIMER4:
        case GPT_CH_GPTIMER5:
        case GPT_CH_GPTIMER6:
        case GPT_CH_GPTIMER7:
        case GPT_CH_GPTIMER8:
        case GPT_CH_GPTIMER9:
        case GPT_CH_GPTIMER10:
        case GPT_CH_GPTIMER11:
        case GPT_CH_GPTIMER12:
        case GPT_CH_GPTIMER13:
        case GPT_CH_GPTIMER14:
        case GPT_CH_GPTIMER15:
        case GPT_CH_GPTIMER16:
#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)
        case GPT_CH_GPTIMER17:
        case GPT_CH_GPTIMER18:
        case GPT_CH_GPTIMER19:
        case GPT_CH_GPTIMER20:
        case GPT_CH_GPTIMER21:
        case GPT_CH_GPTIMER22:
        case GPT_CH_GPTIMER23:
        case GPT_CH_GPTIMER24:
        case GPT_CH_GPTIMER25:
        case GPT_CH_GPTIMER26:
        case GPT_CH_GPTIMER27:
        case GPT_CH_GPTIMER28:
        case GPT_CH_GPTIMER29:
        case GPT_CH_GPTIMER30:
#endif /* SOC_J721E */
            *pTimerType = GPT_TIMERTYPE_GPTIMER;
            retVal      = (Std_ReturnType) E_OK;
            break;
        default:
            *pTimerType = GPT_TIMERTYPE_INVALID;
            retVal      = (Std_ReturnType) E_NOT_OK;
            break;
    }

    return retVal;
}

#if (STD_ON == GPT_REPORT_WAKEUP_SOURCE) && (STD_ON == \
                                                 GPT_WAKEUP_FUNCTIONALITY_API)
/**
 * \brief   This API will set the operation mode of the Gpt driver to sleep
 *          mode.
 *
 * \param   None.
 *
 * \return  None.
 *
 **/
/* Design : DES_GPT_029 */
/* Requirements : MCAL-2072, MCAL-2073, MCAL-2075 */
GPT_FUNC_TEXT_SECTION static void Gpt_setSleepMode(void)
{
    /* Perform the sleep sequence */
    uint32 chIdx;
    Gpt_ChannelHwObjType *pGptChHwObj;

    for (chIdx = 0U; chIdx < Gpt_DrvObj.channelCount; chIdx++)
    {
        pGptChHwObj = &(Gpt_DrvObj.channelObj[chIdx]);

        if ((uint32) TRUE == Gpt_DrvObj.channelWakeupEnFlag[chIdx])
        {
            /* Critical section, block the interrupts */
            SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();

            /* Enable Interrupt notification */
            /* Set enableWakeupFlag and enable wakeup interrupt */
            Gpt_gptimerEnableWakeup(pGptChHwObj);

            /* Critical section, restore the interrupts */
            SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
        }
        else
        {
            /*
             * Stopping channel
             * In Wake-up mode only those notifications, which cause wake-up
             * capable notifications, are available. All other notifications are
             * disabled and must not lead to an exit of the reduced power mode
             * state (e.g. idle, halt) of the MCU if the event occurs.
             */
            Gpt_StopTimer(pGptChHwObj->channelCfg_PC.channelId);

            /*Disable channel notification*/
            /* Enable Interrupt notification */
            /*
             * Disabling other interrupts[SRS_Gpt_13603]
             * In Wake-up mode only those notifications, which cause
             * wake-up capable notifications, are available. All other
             * notifications are disabled and must not lead to an exit
             * of the reduced power mode state (e.g. idle, halt) of the
             * MCU if the event occurs.
             */
            Gpt_gptimerDisableWakeup(pGptChHwObj);
        }
    }

    /* Set marker for sleep mode */
    Gpt_DrvObj.sleepMode = GPT_MODE_SLEEP;
}

#endif

#if (STD_ON == GPT_REPORT_WAKEUP_SOURCE) && (STD_ON == \
                                                 GPT_WAKEUP_FUNCTIONALITY_API)
/**
 * \brief   This API will set the operation mode of the Gpt driver to normal
 *          mode
 *
 * \param   None.
 *
 * \return  None.
 *
 **/
/* Design : DES_GPT_029 */
/* Requirements : MCAL-2071, MCAL-2074 */
GPT_FUNC_TEXT_SECTION static void Gpt_setNormalMode(void)
{
#if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API)
    uint32 chIdx;

    /* Check if Notification enabled for each channel. */
    for (chIdx = 0U; chIdx < Gpt_DrvObj.channelCount; chIdx++)
    {
        if ((uint32) TRUE == Gpt_DrvObj.channelNotifyActiveFlag[chIdx])
        {
            Gpt_EnableNotification
                (Gpt_DrvObj.channelObj[chIdx].channelCfg_PC.channelId);
        }
    }
#endif
    /* Set the Gpt mode to Normal */
    Gpt_DrvObj.sleepMode = GPT_MODE_NORMAL;
}

#endif

Gpt_ChannelHwObjType *Gpt_getHwUnitObj(Gpt_ChannelType gptChannel,
                                       uint32         *chIdx)
{
    uint32 i;
    Gpt_ChannelHwObjType *pHwUnitObj = NULL;

    for (i = 0U; i < GPT_MAX_CHANNELS; i++)
    {
        if (gptChannel == Gpt_DrvObj.channelObj[i].channelCfg_PC.channelId)
        {
            /* Return channel hw object and channel index in driver object */
            pHwUnitObj = Gpt_getCurrChannelObj(i);
            *chIdx     = i;
            break;
        }
    }
    if ((Gpt_ChannelHwObjType *) NULL == pHwUnitObj)
    {
#if (STD_ON == GPT_DEV_ERROR_DETECT)
        /* Design : DES_GPT_037 */
        /* Requirements : MCAL-2517 */
        Gpt_reportDetError(GPT_SID_GET_GETHWUNITOBJ, GPT_E_PARAM_CHANNEL);
#endif
    }
    return (Gpt_ChannelHwObjType *) pHwUnitObj;
}

#if (STD_ON == GPT_REGISTER_READBACK_API)
GPT_FUNC_TEXT_SECTION FUNC(Std_ReturnType, GPT_CODE) Gpt_RegisterReadback(
    Gpt_ChannelType GptChannel,
    P2VAR(Gpt_RegisterReadbackType, AUTOMATIC, GPT_APPL_DATA) RegRbPtr)
{
    Gpt_ChannelHwObjType *pHwUnitObj = NULL;
    Std_ReturnType        retVal     = ((Std_ReturnType) E_OK);
    uint32 chIdx;

    if ((GPT_DRV_UNINTIALIZED == Gpt_DrvStatus) || (NULL_PTR == RegRbPtr))
    {
        retVal = (Std_ReturnType) E_NOT_OK;
    }
    else
    {
        (void) memset(RegRbPtr, 0, sizeof (Gpt_RegisterReadbackType));

        /* HW unit ID may not be the index, so search for matching HW unit */
        pHwUnitObj = Gpt_getHwUnitObj(GptChannel, &chIdx);
        if (NULL_PTR != pHwUnitObj)
        {
            uint32 baseAddr;

            baseAddr = pHwUnitObj->baseAddr;
            RegRbPtr->gptRev          = HW_RD_REG32(baseAddr + TIMER_TIDR);
            RegRbPtr->gptTtgr         = HW_RD_REG32(baseAddr + TIMER_TTGR);
            RegRbPtr->gptTimerSynCtrl = HW_RD_REG32(baseAddr + TIMER_TSICR);
        }
        else
        {
            retVal = (Std_ReturnType) E_NOT_OK;
        }
    }

    return (retVal);
}
#endif  /* #if (STD_ON == GPT_REGISTER_READBACK_API) */

/* This API is to get address of current GPR channel object */
GPT_FUNC_TEXT_SECTION static inline Gpt_ChannelHwObjPtrType
    Gpt_getCurrChannelObj(uint32 chIdx)
{
    return (&Gpt_DrvObj.channelObj[chIdx]);
}

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#define GPT_START_SEC_ISR_CODE
#include "Gpt_MemMap.h"

/**
 * \brief   This Interrupt notification call function is called when timer
 *          channel is enabled for notification interrupt. Gpt_StartTimer is
 *          called with the referenced channel. Once the timer channel is
 *          expired or reaches count value, interrupt is triggered which calls
 *          the Gpt_notifyIsr call back function inside the timer Isr.
 *
 * \param   Channel Index in configuration array: chIdx
 *
 * \return  None.
 **/
GPT_ISR_TEXT_SECTION void Gpt_notifyIsr(uint32 chIdx)
{
    Gpt_ChannelHwObjType *pGptChHwObj;
    Gpt_ChannelType       channelId;

    /* Critical section, block the interrupts */
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();

    pGptChHwObj = &(Gpt_DrvObj.channelObj[chIdx]);
    channelId   = pGptChHwObj->channelCfg_PC.channelId;

    /* Design : DES_GPT_034 */
    /* Requirements : MCAL-2118 */
    Gpt_gptimerIntrClear(channelId);

    /* Design : DES_GPT_034 */
    /* Requirements : MCAL-2116, MCAL-2117 */
    if (NULL != (pGptChHwObj->channelCfg.fnPtrNotifyFunction))
    {
        /* Call notification callback */
        pGptChHwObj->channelCfg.fnPtrNotifyFunction();
    }
    /* Mark the channel as inactive */
    if (GPT_CH_MODE_ONESHOT ==
        Gpt_DrvObj.channelObj[chIdx].channelCfg.channelMode)
    {
        /* Design : DES_GPT_008 */
        /* Requirements : MCAL-1974 */
        Gpt_DrvObj.channelState[chIdx] = GPT_EXPIRED;
    }
    /* Critical section, restore the interrupts */
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
} /* Gpt_NotifContIsr */

/* Design : DES_GPT_035 */
/* Requirements : MCAL-2111, MCAL-1986 */
/**
 * \brief   This wake-up event notification call function is called when timer
 *          channel is enabled for wake-up and GPT is in sleep mode.
 *          Gpt_StartTimer is called with the referenced channel. Once the timer
 *          channel is expired or reaches count value, interrupt is triggered
 *          which calls the Gpt_wakeupIsr call back function inside the
 *          timerIsr.
 *
 * \param   Channel Index in configuration array: chIdx
 *
 * \return  None.
 **/
GPT_ISR_TEXT_SECTION void Gpt_wakeupIsr(uint32 chIdx)
{
    Gpt_ChannelHwObjType *pGptChHwObj;
    Gpt_ChannelType       channelId;

    /* Critical section, block the interrupts */
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_0();

    pGptChHwObj = &(Gpt_DrvObj.channelObj[chIdx]);
    channelId   = pGptChHwObj->channelCfg_PC.channelId;

    /* Design : DES_GPT_035 */
    /* Requirements : MCAL-2112 */
    Gpt_gptimerIntrClear(channelId);

#if (STD_ON == GPT_REPORT_WAKEUP_SOURCE) && (STD_ON == \
                                                 GPT_WAKEUP_FUNCTIONALITY_API)
    if ((uint32) FALSE != Gpt_DrvObj.channelWakeupEnFlag[chIdx])
    {
        /* Design : DES_GPT_035 */
        /* Requirements : MCAL-2111 */
        /* Inform EcuM about wakeup source */
        EcuM_CheckWakeup(Gpt_WakeupSourceType[chIdx]);
    }
#endif
    /* Critical section, restore the interrupts */
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_0();
}


#define GPT_STOP_SEC_ISR_CODE
#include "Gpt_MemMap.h"
