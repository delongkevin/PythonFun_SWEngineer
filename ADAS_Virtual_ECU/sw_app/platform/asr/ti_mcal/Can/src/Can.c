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
 *  \file     Can.c
 *
 *  \brief    This file contains CAN MCAL driver implementation.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "string.h"
#include "SchM_Can.h"

#include "Can.h"
#include "Can_Priv.h"

/* Requirements :MCAL-2226 */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
#include <ti/csl/cslr.h>
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* AUTOSAR version information check has to match definition in header file */
#if ((CAN_AR_RELEASE_MAJOR_VERSION != (4U))   \
    || (CAN_AR_RELEASE_MINOR_VERSION != (3U)) \
    || (CAN_AR_RELEASE_REVISION_VERSION != (1U)))
#error "CAN: AUTOSAR Version Numbers of CAN are different"
#endif

#if ((CAN_SW_MAJOR_VERSION != (1U)) || (CAN_SW_MINOR_VERSION != (3U)))
#error "Vendor specific version numbers of Can.c and Can.h are inconsistent"
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
static boolean Can_CheckInitDet(const Can_ConfigType *ConfigPtr);
static boolean Can_CheckControllerConfig(const Can_ConfigType *ConfigPtr);
static boolean Can_CheckMbConfig(const Can_ConfigType *ConfigPtr);
static boolean Can_CheckWriteDet(const uint32 Hth,
                                 const Can_PduType *PduInfo,
                                 const Can_DriverObjType *canDrvObj);
static boolean Can_CheckEnableDet(uint8 Controller,
                                  const Can_DriverObjType * canDrvObj);
static boolean Can_CheckDisableDet(uint8 Controller,
                                   const Can_DriverObjType * canDrvObj);
static boolean Can_CheckSetControllerModeDet(uint8 Controller,
                                   const Can_DriverObjType * canDrvObj);
static boolean Can_SetBaudrateDet(uint8 Controller,
                                  const Can_DriverObjType * canDrvObj);
#endif

static void Can_resetDrvObj(Can_DriverObjType *drvObj);
static void Can_initDrvObj(Can_DriverObjType *drvObj,
                           const Can_ConfigType *ConfigPtr);
LOCAL_INLINE Std_ReturnType Can_SetControllerModeProcess(
                                        Can_ControllerObjType * controllerObj,
                                        Can_ControllerStateType Transition);

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define CAN_INVALID_BASE_ADDR                   (0x00000000U)
#define CAN_ID_CAN_CONTROLLER_TYPE_MASK         (0x40000000U)
#define CAN_MAX_BAUD_RATE_PRESCALER_VALUE       (0x200U)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
#define CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Can_MemMap.h"

CAN_VAR_DATA_NO_INIT_UNSPECIFIED_SECTION static Can_DriverObjType Can_DriverObj;

#define CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_INIT_8
#include "Can_MemMap.h"

CAN_VAR_DATA_INIT_8_SECTION
    VAR(uint8, CAN_VAR_INIT) Can_DrvState = CAN_UNINIT;

#define CAN_STOP_SEC_VAR_INIT_8
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

/*Requirements : MCAL-2294, MCAL-2295, MCAL-2296,
 * MCAL-2377, MCAL-2254 */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/*******************************************************************************
 * Can_Init
 ******************************************************************************/
/*! \brief     This function initialises the CAN controller
 *
 *              All the required initilisation for the CAN driver and hardware
 *              is performed in this function.
 *
 *  \param[in]  CfgPtr - Pointer to post-build configuration data.
 *
 *  \context    App
 ******************************************************************************/
/*Requirements: MCAL-2287, MCAL-2286, MCAL-2280, MCAL-2281,
 * MCAL-2249, MCAL-2342, MCAL-2245,
 * MCAL-2282, MCAL-2283, MCAL-2219, MCAL-2303
 * MCAL-2220, MCAL-2223, MCAL-2236,
 * MCAL-2341, MCAL-2342, MCAL-2343, MCAL-2243,
 */
/* Design : DES_CAN_014 */
CAN_FUNC_TEXT_SECTION FUNC(void, CAN_CODE) Can_Init(
    P2CONST(Can_ConfigType, AUTOMATIC, CAN_PBCFG) CfgPtr)
{
    uint8 controller_cntr;
    const Can_ConfigType *ConfigPtr = CfgPtr;
#if (STD_ON == CAN_VARIANT_PRE_COMPILE)
    if (NULL_PTR == ConfigPtr)
    {
        ConfigPtr = &CAN_INIT_CONFIG_PC;
    }
#endif  /* (STD_ON == CAN_VARIANT_PRE_COMPILE) */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == ConfigPtr)
    {
        /* Can config pointer is NOT valid */
        (void) Det_ReportError((uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_INIT_ID,
                               (uint8) CAN_E_PARAM_POINTER);
    }
    else if (Can_CheckInitDet(ConfigPtr) == (boolean) FALSE)
    {
        /* Reporting Det Error */
        (void) Det_ReportError((uint16) CAN_MODULE_ID,
                               (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_INIT_ID,
                               (uint8) CAN_E_PARAM_POINTER);
    }
    else
#endif  /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    {
        Can_resetDrvObj(&Can_DriverObj);
        Can_initDrvObj(&Can_DriverObj, ConfigPtr);
        for (controller_cntr = 0U;
             controller_cntr < Can_DriverObj.canMaxControllerCount;
             controller_cntr++)
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            if (Can_DriverObj.canController[controller_cntr].canState
                                                            != CAN_CS_UNINIT)
            {
                /* Can controller is in not in UNINT state */
                (void) Det_ReportError((uint16) CAN_MODULE_ID,
                                       (uint8) CAN_INSTANCE_ID,
                                       (uint8) CAN_INIT_ID,
                                       (uint8) CAN_E_TRANSITION);
            }
            else
#endif
            {
                /* If Controller is active then only do initialization */
                if (Can_DriverObj.canController[controller_cntr].
                            canControllerConfig_PC.CntrActive ==
                                                            (boolean) TRUE)
                {
                    /* Init individual controller (may be moved to
                     * SetControllerMode(start state)) */
                    Can_hwUnitConfig(&Can_DriverObj,
                        &Can_DriverObj.canController[controller_cntr],
                        &Can_DriverObj.canMailbox[0U],
                        Can_DriverObj.maxMbCnt);

                    /* initialize the interrupt counter to zero */
                    Can_DriverObj.canController[controller_cntr].
                    canInterruptCounter = 0U;
                    /* change the state to stopped from the UNINIT state */
                    Can_DriverObj.canController[controller_cntr].canState =
                                                                    CAN_CS_STOPPED;
                    /* Update BusOff Recovery status */
                    Can_DriverObj.canController[controller_cntr].
                                canBusOffRecoveryStatus = (boolean) FALSE;
                }
            }
        }

        /*Requirements: MCAL-2244 */
        Can_DrvState = CAN_READY;
    }
}

#if (CAN_VERSION_INFO_API == STD_ON)
/*******************************************************************************
 * Can_GetVersionInfo
 ******************************************************************************/
/*! \brief      This function will return the version for this module
 *
 *  \param[in]  None
 *
 *  \param[out]    Std_VersionInfoType VersionInfo - the structure that will
 *                  contain version info after fxn call.
 *
 *  \context    App
 ******************************************************************************/
/*Requirements: MCAL-2344, MCAL-2345 */
/* Design : DES_CAN_023 */
CAN_FUNC_TEXT_SECTION FUNC(void, CAN_CODE) Can_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_APPL_DATA) VersionInfo)
{
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (VersionInfo == NULL_PTR)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_VERSION_ID,
                               (uint8) CAN_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfo->vendorID         = (uint16) CAN_VENDOR_ID;
        VersionInfo->moduleID         = (uint16) CAN_MODULE_ID;
        VersionInfo->sw_major_version = (uint8) CAN_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8) CAN_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8) CAN_SW_PATCH_VERSION;
    }
}
#endif


/*******************************************************************************
 * Can_SetControllerMode
 ******************************************************************************/
/*! \brief      This function will transition the controller to different
 * states, Its AUTOSAR defined states.
 *
 *  \param[in]  uint8 Controller -  The controller for which the state change
 *              needs to be performed/
 *              Can_ControllerStateType Transition - the state to which
 *              controller needs to move in.
 *
 *
 *  \context
 ******************************************************************************/
/*Requirements: MCAL-2257, MCAL-2258, MCAL-2264,
 * MCAL-2269, MCAL-2364
 * MCAL-2365, MCAL-2366, MCAL-2368, MCAL-2369, MCAL-2370,
 * MCAL-2371, MCAL-2372,
 * MCAL-2373, MCAL-2374, MCAL-2262, MCAL-2266, MCAL-2267 */
/* Design : DES_CAN_015 */
CAN_FUNC_TEXT_SECTION FUNC(Std_ReturnType, CAN_CODE) Can_SetControllerMode(
    uint8 Controller, Can_ControllerStateType Transition)
{
    Std_ReturnType status = E_NOT_OK;

    /*check for the validity of the controller parameter if det is enabled*/
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (Can_CheckSetControllerModeDet(Controller,
                                      &Can_DriverObj) == (boolean) FALSE)
    {
        /* Det Error is already reported */
    }
    else
#endif
    {
        status = Can_SetControllerModeProcess(
                                &Can_DriverObj.canController[Controller],
                                Transition);
    }

    return status;
}

/*******************************************************************************
 * Can_Write
 ******************************************************************************/
/*! \brief      This function will write the data into Can mail boxes.
 *
 *  \param[in]  Can_HwHandleType Hth - This is the Msg box number its a unique
 *              number.
 *              const Can_PduType *PduInfo - the CAN message to be transmitted.
 *
 *
 *  \context    App
 ******************************************************************************/
/*Requirements: MCAL-2290, MCAL-2391, MCAL-2288, MCAL-2291,
 * MCAL-2392, MCAL-2393, MCAL-2297,
 * MCAL-2394, MCAL-2395, MCAL-2396, MCAL-2397, MCAL-2398,
 * MCAL-2399, MCAL-2402, MCAL-2404, MCAL-2405
 * */
/* Design : DES_CAN_016 */
CAN_FUNC_TEXT_SECTION FUNC(Std_ReturnType, CAN_CODE) Can_Write(
    Can_HwHandleType Hth, const Can_PduType *PduInfo)
{
    Std_ReturnType status = E_OK;
    uint32         messageBox, controller;
    uint8          MsgCntrlr;
    uint32         msgObjIndx;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (Can_CheckWriteDet((uint32) Hth, PduInfo, &Can_DriverObj) ==
        (boolean) FALSE)
    {
        status = E_NOT_OK;
    }
    else
#endif
    {
        MsgCntrlr = Can_DriverObj.canMailbox[Hth].
                                mailBoxConfig.Controller->ControllerId;
        /* only for the Tx Mailbox */
        if (Can_DriverObj.canMailbox[Hth].mailBoxConfig.MBDir ==
                                                CAN_MAILBOX_DIRECTION_TX)
        {
            /* CanSM has triggered a new write after L1 timeout. Stop the BusOff
             * recovery.
             * CanSM will trigger a new bus off recovery sequence. */
            Can_DriverObj.canController[MsgCntrlr].canBusOffRecoveryStatus =
                                                               (boolean) FALSE;
            SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();

            for(controller = 0U ; controller < CAN_NUM_CONTROLLER; controller++)
            {
                if(MsgCntrlr == Can_DriverObj.canController[controller].
                                            canControllerConfig_PC.ControllerId)
                {
                    break;
                }
            }

            if(controller < CAN_NUM_CONTROLLER)
            {
                messageBox = (uint32)Can_DriverObj.canMailbox[Hth].
                                                            mailBoxConfig.HwHandle;
                status = Can_writeGetFreeMsgObj(
                                &Can_DriverObj.canMailbox[Hth].mailBoxConfig,
                                &Can_DriverObj.canController[MsgCntrlr],
                                &messageBox,
                                Hth);

                if (status == E_OK)
                {
                    Can_writeTxMailbox(
                                &Can_DriverObj.canMailbox[Hth].mailBoxConfig,
                                &Can_DriverObj.canController[MsgCntrlr],
                                Hth,
                                messageBox,
                                PduInfo);
                    msgObjIndx = messageBox;
                    /* Store the transmitted Pdu SWPdu Handle for Tx
                     * confirmation */
                    Can_DriverObj.canMailbox[Hth].canTxRxPduId[msgObjIndx] =
                                                            PduInfo->swPduHandle;
                    /* set that this object is transmitted. */
                    Can_DriverObj.canController[MsgCntrlr].canTxStatus[msgObjIndx]
                                                                            = 1U;
                }
            }
            else
            {
                status = E_NOT_OK;
            }

            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
        }
        else
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError((uint16) CAN_MODULE_ID,
                                   (uint8) CAN_INSTANCE_ID,
                                   (uint8) CAN_WRITE_ID,
                                   (uint8) CAN_E_PARAM_HANDLE);
#endif
            status = E_NOT_OK;
        }
    }
    return status;
}

/*******************************************************************************
 * Can_DisableControllerInterrupts
 ******************************************************************************/
/*! \brief      This function will Disable the interrupts for the Controller
 * desired.
 *              Basically it will Disable the CAN interrupts(reset bit 1 in CTL
 * reg(IE0=0)).
 *
 *
 *  \param[in]  uint8 Controller - CAN Controller Id
 *
 *  \context
 ******************************************************************************/
/*Requirements: MCAL-2375, MCAL-2376, MCAL-2379, MCAL-2380,
 *MCAL-2378*/
/* Design : DES_CAN_017 */
CAN_FUNC_TEXT_SECTION FUNC(void, CAN_CODE) Can_DisableControllerInterrupts(
    uint8 Controller)
{

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (Can_CheckDisableDet(Controller, &Can_DriverObj) == (boolean) FALSE)
    {
        /* Det Error is already reported */
    }
    else
#endif
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        if ((Can_DriverObj.canController[Controller].canControllerConfig_PC.
                TxProcessingType == CAN_TX_RX_PROCESSING_POLLING)
            && (Can_DriverObj.canController[Controller].canControllerConfig_PC.
                RxProcessingType == CAN_TX_RX_PROCESSING_POLLING))
        {
            (void) Det_ReportError((uint16) CAN_MODULE_ID,
                                   (uint8) CAN_INSTANCE_ID,
                                   (uint8) CAN_DIINT_ID,
                                   (uint8) CAN_E_PARAM_CONTROLLER);
        }
        else
#endif
        {
            Can_hwUnitDisableInterrupts(
                                &Can_DriverObj.canController[Controller]);
        }

        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}

/*******************************************************************************
 * Can_EnableControllerInterrupts
 ******************************************************************************/
/*! \brief      This function will Enable the interrupts for the Controller
 *              desired. It will restore the interrupts
 *              that were defined in the configuration. Basically it will enable
 *              the CAN interrupts.
 *
 *  \param[in]  uint8 Controller - CAN Controller Id
 *
 *  \context
 ******************************************************************************/
/*Requirements: MCAL-2381, MCAL-2382, MCAL-2383, MCAL-2384,
 *MCAL-2385 */
/* Design : DES_CAN_018 */
CAN_FUNC_TEXT_SECTION FUNC(void, CAN_CODE) Can_EnableControllerInterrupts(
    uint8 Controller)
{
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (Can_CheckEnableDet(Controller, &Can_DriverObj) == (boolean) FALSE)
    {
        /* Det Error is already reported */
    }
    else
#endif
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        Can_hwUnitEnableInterrupts(&Can_DriverObj.canController[Controller]);
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }
}

/*******************************************************************************
 * Can_SetBaudrate
 ******************************************************************************/
/*! \brief      This service shall set the baudrate of the CAN controller.
 *
 *  \param[in]  uint8 Controller -  The controller for which the Baud is to be
 *              changed
 *              BaudRateConfigID -  references a baud rate configuration by ID
 *
 *  \return     Std_ReturnType -  E_OK  - Service request accepted, setting
 *                                           of (new) baud rate started
 *
 *                                E_NOT_OK  - Service request not accepted
 *
 *  \context
 ******************************************************************************/
/* Design : DES_CAN_032 */
/*Requirements: MCAL-2359, MCAL-2363, MCAL-2285,
 *MCAL-2284, MCAL-2251 , MCAL-2252, MCAL-2250 */
CAN_FUNC_TEXT_SECTION FUNC(Std_ReturnType, CAN_CODE) Can_SetBaudrate(
    uint8 Controller, uint16 BaudRateConfigID)
{
    uint32                baseAddr;

    Std_ReturnType        status = E_NOT_OK;
    Can_BaudConfigType   *setBaud;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (Can_SetBaudrateDet(Controller, &Can_DriverObj) == (boolean) FALSE)
    {
        /* Det Error is already reported */
    }
    else
#endif
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
        baseAddr = Can_DriverObj.canController[Controller].
                                                canControllerConfig_PC.CntrAddr;
        setBaud = Can_DriverObj.canController[Controller].
                    canControllerConfig.BaudRateConfigList[BaudRateConfigID];

        if ((uint32)BaudRateConfigID >
            (Can_DriverObj.canController[Controller].maxBaudConfigID))
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError((uint16) CAN_MODULE_ID,
                                   (uint8) CAN_INSTANCE_ID,
                                   (uint8) CAN_SETBAUDRATE_ID,
                                   (uint8) CAN_E_PARAM_BAUDRATE);
#endif
        }
        else
        {
            Can_hwUnitSetBaudrate(baseAddr, setBaud);

            status = (Std_ReturnType) E_OK;
        }

        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
    }

    return status;
}

/* Design : DES_CAN_039 */
/*Requirements: MCAL-4372, MCAL-4373, MCAL-4374,
 *              MCAL-4375, MCAL-4376 */
CAN_FUNC_TEXT_SECTION FUNC(Std_ReturnType, CAN_CODE)
    Can_GetControllerMode(uint8 Controller,
        Can_ControllerStateType* ControllerModePtr)
{
    Std_ReturnType    retVal = (Std_ReturnType) E_NOT_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (Can_DrvState == CAN_UNINIT)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID,
                               (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_GETCTRMODE_ID,
                               (uint8) CAN_E_UNINIT);
    }
    else if (Controller >= (Can_DriverObj.canMaxControllerCount))
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID,
                               (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_GETCTRMODE_ID,
                               (uint8) CAN_E_PARAM_CONTROLLER);
    }
    else if (ControllerModePtr == NULL_PTR)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID,
                               (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_GETCTRMODE_ID,
                               (uint8) CAN_E_PARAM_POINTER);
    }
    else
#endif
    {
        retVal = (Std_ReturnType) E_OK;
        *ControllerModePtr = Can_DriverObj.canController[Controller].canState;
    }

    return retVal;
}

/* Design : DES_CAN_040 */
/*Requirements: MCAL-4367, MCAL-4368, MCAL-4369,
 *              MCAL-4370, MCAL-4371 */
CAN_FUNC_TEXT_SECTION FUNC(Std_ReturnType, CAN_CODE) Can_GetControllerErrorState(uint8 ControllerId,
    Can_ErrorStateType* ErrorStatePtr)
{
    Std_ReturnType    	  retVal = (Std_ReturnType) E_NOT_OK;
    Can_ErrorStateType    errorState;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (Can_DrvState == CAN_UNINIT)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID,
                               (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_GETCTRERRST_ID,
                               (uint8) CAN_E_UNINIT);
    }
    else if (ControllerId >= (Can_DriverObj.canMaxControllerCount))
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID,
                               (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_GETCTRERRST_ID,
                               (uint8) CAN_E_PARAM_CONTROLLER);
    }
    else if (ErrorStatePtr == NULL_PTR)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID,
                               (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_GETCTRERRST_ID,
                               (uint8) CAN_E_PARAM_POINTER);
    }
    else
#endif
    {
        retVal = (Std_ReturnType) E_OK;
		errorState = Can_mcanGetProtocolStatus
						(&Can_DriverObj.canController[ControllerId]);
        *ErrorStatePtr = errorState;
    }

    return retVal;
}

/*******************************************************************************
 * Can_MainFunction_Write
 ******************************************************************************/
/*! \brief      This function performs the polling of TX confirmation and TX
 * cancellation confirmation
 *              when CAN_TX_PROCESSING is set to POLLING.
 *
 *  \param[in]  void
 *
 *  \context
 ******************************************************************************/
/*Requirements: MCAL-2226, MCAL-2292, MCAL-2412, MCAL-2413,
 *MCAL-2414,MCAL-2416 */
/* Design : DES_CAN_019 */
CAN_FUNC_TEXT_SECTION FUNC(void, CAN_CODE) Can_MainFunction_Write(void)
{
#if  (CAN_TX_POLLING == STD_ON)
    uint8  ctlrIndx;
    Can_TxRxProcessingType txProcessingType;

	for (ctlrIndx = 0U ;
		 ctlrIndx < (uint8) CAN_NUM_CONTROLLER;
		 ctlrIndx++)
	{
        txProcessingType = Can_DriverObj.canController[ctlrIndx].
                        canControllerConfig_PC.TxProcessingType;
		/* only for the Tx Mailbox */
        if (txProcessingType != CAN_TX_RX_PROCESSING_INTERRUPT)
        {
            if (Can_DriverObj.canController[ctlrIndx].
                            canControllerConfig_PC.CntrActive == (boolean) TRUE)
            {
                Can_mcanTxDonePolling(
                    &Can_DriverObj.canController[ctlrIndx],
                    &Can_DriverObj.canMailbox[0U]);
            }
        }
	}
#endif
}

/*******************************************************************************
 * Can_MainFunction_Wakeup
 ******************************************************************************/
/*! \brief      This function performs the polling of wake-up events that are
 * configured statically as 'to be polled'.
 *
 *  \param[in]  void
 *
 *  \context
 ******************************************************************************/
/*Requirements: MCAL-2426, MCAL-2428 */
/* Design : DES_CAN_022 */
CAN_FUNC_TEXT_SECTION FUNC(void, CAN_CODE) Can_MainFunction_Wakeup(void)
{
#if  (CAN_WAKEUP_POLLING == STD_ON)
     /* Empty Meeting Requirement Id MCAL-2428 */
#endif /* #if (CAN_WAKEUP_POLLING == STD_ON) */
}
/*******************************************************************************
 * Can_MainFunction_BusOff
 ******************************************************************************/
/*! \brief      This function performs the polling of bus-off events that are
 * configured statically as 'to be polled'.
 *
 *  \param[in]  void
 *
 *  \context
 ******************************************************************************/
/*Requirements: MCAL-2422, MCAL-2423, MCAL-2424 */
/* Design : DES_CAN_020 */
CAN_FUNC_TEXT_SECTION FUNC(void, CAN_CODE) Can_MainFunction_BusOff(void)
{
#if (CAN_BUSOFF_POLLING == STD_ON)
    uint8  controller_cntr;

    for (controller_cntr = 0U;
         controller_cntr < Can_DriverObj.canMaxControllerCount;
         controller_cntr++)
    {
        /* If the controller is not activated just skip its checking */
        if (Can_DriverObj.canController[controller_cntr].
                    canControllerConfig_PC.CntrActive == (boolean) TRUE)
        {
            Can_MainFunction_BusOffProcess(&Can_DriverObj.
                                           canController[controller_cntr]);
        }
    }
#endif /* #if (CAN_BUSOFF_POLLING == STD_ON) */
}

/*******************************************************************************
 * Can_MainFunction_Mode
 ******************************************************************************/
/*! \brief      This function performs the polling of CAN controller mode
 * transitions
 *              This will indicate only the CanController SW state and cannot
 *              indicate any HW state as there is not
 *              HW state exposed from the Can Controller.
 *
 *  \param[in]  void
 *
 *  \context
 ******************************************************************************/
/*Requirements:MCAL-2253, MCAL-2256, MCAL-2430, MCAL-2431,
 * MCAL-2255, MCAL-2278*/
/* Design : DES_CAN_024 */
CAN_FUNC_TEXT_SECTION FUNC(void, CAN_CODE) Can_MainFunction_Mode(void)
{
    uint8  controller_cntr;

    for (controller_cntr = 0U;
         controller_cntr < Can_DriverObj.canMaxControllerCount;
         controller_cntr++)
    {
        Can_MainFunction_ModeProcess(
            &Can_DriverObj.canController[controller_cntr]);
    }
}

/*******************************************************************************
 * Can_MainFunction_Read
 ******************************************************************************/
/*! \brief      This function performs the polling of CAN controller mode
 * transitions
 *
 *  \param[in]  void
 *
 *  \context
 ******************************************************************************/
/*Requirements: MCAL-2300, MCAL-2417,
 * MCAL-2418, MCAL-2419, MCAL-2421 */
/* Design : DES_CAN_021 */
CAN_FUNC_TEXT_SECTION FUNC(void, CAN_CODE) Can_MainFunction_Read(void)
{
#if (CAN_RX_POLLING == STD_ON)
    Can_MainFunction_ReadProcess(&Can_DriverObj);
#endif /* #if (CAN_RX_POLLING == STD_ON) */
}

#if (CAN_LOOPBACK_ENABLE == STD_ON)
/*******************************************************************************
 * Can_TestLoopBackModeEnable
 ******************************************************************************/
/*! \brief      This function enables the Loopback
 *
 *  \param[in]  uint8 Controller for which loopback needs to be enabled
 *              uint8 Mode 0 - Enable Digital mode. 1 - Enable Analog mode.
 *
 *  \context
 ******************************************************************************/
/* Design : DES_CAN_027 */
CAN_FUNC_TEXT_SECTION FUNC(Std_ReturnType, CAN_CODE)
    Can_TestLoopBackModeEnable(uint8 Controller, uint8 Mode)
{
    uint32 baseAddr;
    VAR(Std_ReturnType, AUTOMATIC) retVal;

    retVal = (Std_ReturnType) E_NOT_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (Can_DrvState == CAN_READY)
#endif
    {
        if ((Controller < (Can_DriverObj.canMaxControllerCount)) &&
            (Mode < 2U))
        {
            baseAddr = Can_DriverObj.canController[Controller].
                                                canControllerConfig_PC.CntrAddr;
            retVal = Can_hwUnitTestLoopBackModeEnable(baseAddr,
                                    Mode);
        }
    }
    return (retVal);
}

/*******************************************************************************
 * Can_TestLoopBackModeDisable
 ******************************************************************************/
/*! \brief      This function Disable the Loopback
 *
 *  \param[in]  uint8 Controller for which loopback needs to be Disabled
 *              uint8 Mode 0 - Disable Digital mode. 1 - Disable Analog mode.
 *
 *  \context
 ******************************************************************************/
/* Design : DES_CAN_028 */
CAN_FUNC_TEXT_SECTION FUNC(Std_ReturnType, CAN_CODE)
    Can_TestLoopBackModeDisable(uint8 Controller, uint8 Mode)
{
    uint32 baseAddr;
    VAR(Std_ReturnType, AUTOMATIC) retVal;

    retVal = (Std_ReturnType) E_NOT_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (Can_DrvState == CAN_READY)
#endif
    {
        if ((Controller < (Can_DriverObj.canMaxControllerCount)) &&
            (Mode < 2U))
        {
            baseAddr = Can_DriverObj.canController[Controller].
                                            canControllerConfig_PC.CntrAddr;
            retVal = Can_hwUnitTestLoopBackModeDisable(baseAddr,
                                    Mode);
        }
    }
    return (retVal);
}
#endif

/*******************************************************************************
 * Can_RegisterReadback
 ******************************************************************************/
/*! \brief      This is the function for checking the configuration registers.
 *              This APi canbe called by higher layers to check if configuration
 *              is correct.
 *
 *  \param[in]  uint8 controller - 2 controllers are there
 *
 *  \context
 ******************************************************************************/
/* Design : DES_CAN_029 */
#if (STD_ON == CAN_REGISTER_READBACK_API)
CAN_FUNC_TEXT_SECTION Std_ReturnType Can_RegisterReadback(
    VAR(uint8, AUTOMATIC)Controller,
    P2VAR(Can_RegisterReadbackType, AUTOMATIC, CAN_APPL_DATA) RegRbPtr)
{
    uint32 baseAddr;
    VAR(Std_ReturnType, AUTOMATIC) retVal;
    retVal = (Std_ReturnType) E_NOT_OK;
#if (STD_ON == CAN_DEV_ERROR_DETECT)
    if ((Can_DrvState == CAN_UNINIT) || (NULL_PTR == RegRbPtr))
    {
        retVal = E_NOT_OK;
    }
    else
#endif  /* #if (STD_ON == CAN_DEV_ERROR_DETECT) */
    {
        if (Controller < (Can_DriverObj.canMaxControllerCount))
        {
            baseAddr = Can_DriverObj.canController[Controller].
                                            canControllerConfig_PC.CntrAddr;

            /* Read configuration registers value */
            RegRbPtr->CanReadBackRegPID   =
                CSL_REG32_RD(baseAddr + (uint32)MCAN_MCANSS_PID);
            RegRbPtr->CanReadBackRegSTAT  =
                CSL_REG32_RD(baseAddr + (uint32)MCAN_MCANSS_STAT);
            RegRbPtr->CanReadBackRegCREL  =
                CSL_REG32_RD(baseAddr + (uint32)MCAN_CREL);
            RegRbPtr->CanReadBackRegENDN  =
                CSL_REG32_RD(baseAddr + (uint32)MCAN_ENDN);
            retVal = (Std_ReturnType) E_OK;
        }
    }
    return (retVal);
}

#endif

/* Design : DES_CAN_033 */
/*Requirements: MCAL-4363, MCAL-4364, MCAL-4365, MCAL-4377, MCAL-4378 */
/**
 * \brief This function de-initializes the module
 */
CAN_FUNC_TEXT_SECTION FUNC(void, CAN_CODE) Can_DeInit(void)
{
    uint8 controllerIdx;
    uint8 tmpStatus = (uint8) E_OK;

#if (STD_ON == CAN_DEV_ERROR_DETECT)
    if (CAN_UNINIT == Can_DrvState)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_DEINIT_ID, (uint8) CAN_E_TRANSITION);
    }
    else
#endif  /* #if (STD_ON == CAN_DEV_ERROR_DETECT) */
    {
        /* Check if any of the CAN controllers is in state STARTED */
        for (controllerIdx = 0U;
             controllerIdx < Can_DriverObj.canMaxControllerCount;
             controllerIdx++)
        {
            if (Can_DriverObj.canController[controllerIdx].canState ==
                    CAN_CS_STARTED)
                {
                    tmpStatus = (uint8) E_NOT_OK;
                    break;
                }
        }

        if (tmpStatus == (uint8) E_OK)
        {
            Can_DrvState = CAN_UNINIT;
            for (controllerIdx = 0U;
                 controllerIdx < Can_DriverObj.canMaxControllerCount;
                 controllerIdx++)
            {
                Can_DriverObj.canController[controllerIdx].canState =
                    CAN_CS_UNINIT;
                Can_hwDeInit(&Can_DriverObj.canController[controllerIdx]);
            }
            Can_resetDrvObj(&Can_DriverObj);
        }
        else
        {
#if (STD_ON == CAN_DEV_ERROR_DETECT)
            (void) Det_ReportError(
                (uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                    (uint8) CAN_DEINIT_ID, (uint8) CAN_E_TRANSITION);
#endif  /* #if (STD_ON == CAN_DEV_ERROR_DETECT) */
        }

    }
}

/*******************************************************************************
 * Can_resetDrvObj
 ******************************************************************************/
/*! \brief      This function will reset default  Config structure.
 *
 *  \param[in]  Can_DriverObjType drvObj Pointer to Driver Config structure.
 *
 *  \context
 ******************************************************************************/
CAN_FUNC_TEXT_SECTION static void Can_resetDrvObj(Can_DriverObjType *drvObj)
{
    uint32 controllerIndx, mbIndx, loopIndx;

    for (controllerIndx = 0U; controllerIndx < (uint32)CAN_NUM_CONTROLLER;
         controllerIndx++)
    {
        if(Can_DrvState == CAN_UNINIT)
        {
            drvObj->canController[controllerIndx].canState = CAN_CS_UNINIT;
        }
        drvObj->canController[controllerIndx].canBaud = 0U;
        drvObj->canController[controllerIndx].txMixedModeIntrEnable = (boolean) FALSE;
        drvObj->canController[controllerIndx].rxMixedModeIntrEnable = (boolean) FALSE;
        drvObj->canController[controllerIndx].canBusOffRecoveryStatus =
                                                            (boolean) FALSE;
        drvObj->canController[controllerIndx].canInterruptCounter = (uint8)0U;
        for (mbIndx = 0U; mbIndx < (uint32)MCAN_TX_BUFFER_MAX_NUM; mbIndx++)
        {
            drvObj->canController[controllerIndx].canTxStatus[mbIndx] =
                                                                  (uint8)0U;
        }
        for (mbIndx = 0U; mbIndx < (uint32)CAN_FD_PAYLOAD_MAX_BYTES; mbIndx++)
        {
            drvObj->canController[controllerIndx].canSduPtr[mbIndx] = (uint8)0U;
        }
        for (mbIndx = 0U; mbIndx < (uint32)CAN_NUM_MAILBOXES; mbIndx++)
        {
            for (loopIndx = 0U ;
                 loopIndx < (uint32)MCAN_TX_BUFFER_MAX_NUM ;
                 loopIndx++)
            {
                drvObj->canMailbox[mbIndx].canTxRxPduId[loopIndx] =
                                                                (PduIdType)0U;
            }
        }

		drvObj->canController[controllerIndx].canControllerTxType.totalBufCntPollMode = 0U;
		drvObj->canController[controllerIndx].canControllerTxType.totalBufCntIntrMode = 0U;
		drvObj->canController[controllerIndx].canControllerTxType.totalFifoCntPollMode = 0U;
		drvObj->canController[controllerIndx].canControllerTxType.totalFifoCntIntrMode = 0U;
		drvObj->canController[controllerIndx].canControllerTxType.txPollModeMask = 0U;
		drvObj->canController[controllerIndx].canControllerTxType.txIntrModeMask = 0U;
		drvObj->canController[controllerIndx].canControllerRxType.totalBufCntPollMode = 0U;
		drvObj->canController[controllerIndx].canControllerRxType.totalBufCntIntrMode = 0U;
		drvObj->canController[controllerIndx].canControllerRxType.totalFifoCntPollMode = 0U;
		drvObj->canController[controllerIndx].canControllerRxType.totalFifoCntIntrMode = 0U;
		drvObj->canController[controllerIndx].canControllerRxType.bufIntrModeMaskLow = 0U;
		drvObj->canController[controllerIndx].canControllerRxType.bufIntrModeMaskHigh = 0U;
		drvObj->canController[controllerIndx].canControllerRxType.bufPollModeMaskLow = 0U;
		drvObj->canController[controllerIndx].canControllerRxType.bufPollModeMaskHigh = 0U;

		for (loopIndx = 0U ;
			 loopIndx < (uint32)MCAN_TX_BUFFER_MAX_NUM ;
			 loopIndx++)
		{
			drvObj->canController[controllerIndx].canControllerTxType.
				canControllerObjTxPollingType[loopIndx].hth = 0U;
			drvObj->canController[controllerIndx].canControllerTxType.
				canControllerObjTxPollingType[loopIndx].bitPos = 0U;
			drvObj->canController[controllerIndx].canControllerTxType.
				canControllerObjTxPollingType[loopIndx].hwHandle = 0U;
			drvObj->canController[controllerIndx].canControllerTxType.
				canControllerObjTxInterruptType[loopIndx].hth = 0U;
			drvObj->canController[controllerIndx].canControllerTxType.
				canControllerObjTxInterruptType[loopIndx].bitPos = 0U;
			drvObj->canController[controllerIndx].canControllerTxType.
				canControllerObjTxInterruptType[loopIndx].hwHandle = 0U;
		}
		for (loopIndx = 0U ;
			 loopIndx < (uint32)MCAN_RX_BUFFER_MAX_NUM ;
			 loopIndx++)
		{
			drvObj->canController[controllerIndx].canControllerRxType.
				canControllerObjRxPollingType[loopIndx].hrh = 0U;
			drvObj->canController[controllerIndx].canControllerRxType.
				canControllerObjRxPollingType[loopIndx].bitPosLow = 0U;
			drvObj->canController[controllerIndx].canControllerRxType.
				canControllerObjRxPollingType[loopIndx].bitPosHigh = 0U;
			drvObj->canController[controllerIndx].canControllerRxType.
				canControllerObjRxPollingType[loopIndx].hwHandle = 0U;
			drvObj->canController[controllerIndx].canControllerRxType.
				canControllerObjRxInterruptType[loopIndx].hrh = 0U;
			drvObj->canController[controllerIndx].canControllerRxType.
				canControllerObjRxInterruptType[loopIndx].bitPosLow = 0U;
			drvObj->canController[controllerIndx].canControllerRxType.
				canControllerObjRxInterruptType[loopIndx].bitPosHigh = 0U;
			drvObj->canController[controllerIndx].canControllerRxType.
				canControllerObjRxInterruptType[loopIndx].hwHandle = 0U;
			drvObj->canController[controllerIndx].canControllerRxType.
				canControllerObjRxInterruptTypeFifo[loopIndx].hrh = 0U;
			drvObj->canController[controllerIndx].canControllerRxType.
				canControllerObjRxPollingTypeFifo[loopIndx].hrh = 0U;
		}
		drvObj->canController[controllerIndx].txMixedModeIntrEnable = (boolean) FALSE;
        drvObj->canController[controllerIndx].rxMixedModeIntrEnable = (boolean) FALSE;
    }
    return;
}

/*******************************************************************************
 * Can_initDrvObj
 ******************************************************************************/
/*! \brief      This function will initialize Driver Config structure.
 *
 *  \param[in]  Can_DriverObjType drvObj Pointer to Driver Config structure.
 *  \param[in]  Can_ConfigType ConfigPtr Pointer to Can controllers
 *              Config structure.
 *
 *  \context
 ******************************************************************************/
CAN_FUNC_TEXT_SECTION static void Can_initDrvObj(Can_DriverObjType *drvObj,
                           const Can_ConfigType *ConfigPtr)
{
    uint32 controllerIndx, mbIndx;

    for (controllerIndx = 0U ; controllerIndx < (uint32)CAN_NUM_CONTROLLER ;
         controllerIndx++)
    {
        (void) memcpy(
            &drvObj->canController[controllerIndx].canControllerConfig,
            ConfigPtr->CanControllerList[controllerIndx],
            sizeof(Can_ControllerType));
        (void) memcpy(
            &drvObj->canController[controllerIndx].canControllerConfig_PC,
            CanConfigSet_CanController_List_PC[controllerIndx],
            sizeof(Can_ControllerType_PC));
        drvObj->canController[controllerIndx].maxBaudConfigID =
                                ConfigPtr->MaxBaudConfigID[controllerIndx];
        drvObj->controllerIDMap[
        CanConfigSet_CanController_List_PC[controllerIndx]->CanControllerInst] =
            controllerIndx;
    }
    for (mbIndx = 0U ; mbIndx < (uint32)CAN_NUM_MAILBOXES ; mbIndx++)
    {
        (void) memcpy(
            &drvObj->canMailbox[mbIndx].mailBoxConfig,
            ConfigPtr->MailBoxList[mbIndx],
            sizeof(Can_MailboxType));
        (void) memcpy(
            &drvObj->canMailbox[mbIndx].mailBoxConfig_PC,
            CanConfigSet_CanHardwareObject_List_PC[mbIndx],
            sizeof(Can_MailboxType_PC));
    }
    drvObj->canMaxControllerCount = ConfigPtr->CanMaxControllerCount;
    drvObj->maxMbCnt              = ConfigPtr->MaxMbCnt;
}

CAN_FUNC_TEXT_SECTION LOCAL_INLINE
    Std_ReturnType Can_SetControllerModeProcess(
                                        Can_ControllerObjType * controllerObj,
                                        Can_ControllerStateType Transition)
{
    Std_ReturnType status;
    boolean retVal = (boolean) FALSE;

    switch (Transition)
    {
        case CAN_CS_STARTED:
        {
            retVal = Can_hwUnitStart(controllerObj);
            break;
        }

        case CAN_CS_STOPPED:
        {
            retVal = Can_hwUnitStop(controllerObj);
            break;
        }

        case CAN_CS_SLEEP:
        {
            retVal = Can_hwUnitSleep(controllerObj);
            break;
        }
        default:
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            retVal = (boolean) FALSE;
            (void) Det_ReportError((uint16) CAN_MODULE_ID,
                                   (uint8) CAN_INSTANCE_ID,
                                   (uint8) CAN_SETCTR_ID,
                                   (uint8) CAN_E_TRANSITION);
            break;
#endif
        }
    }

    if (retVal == (boolean) TRUE)
    {
        status = E_OK;
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

/*******************************************************************************
 * Can_CheckInitDet
 ******************************************************************************/
/*! \brief      This function will check for NULL pointers for Config structure.
 *
 *  \param[in]  Can_ConfigType ConfigPtr Pointer to Driver Config structure.
 *
 *  \context
 ******************************************************************************/
/* Design :CAN_DesignId_006*/
#if (CAN_DEV_ERROR_DETECT == STD_ON)
CAN_FUNC_TEXT_SECTION static boolean Can_CheckInitDet(
    const Can_ConfigType *ConfigPtr)
{
    boolean returnstatus = (boolean) TRUE;

    returnstatus = Can_CheckControllerConfig(ConfigPtr);
    if((boolean) TRUE == returnstatus)
    {
        returnstatus = Can_CheckMbConfig(ConfigPtr);
    }

    return returnstatus;
}

CAN_FUNC_TEXT_SECTION static boolean Can_CheckControllerConfig(
    const Can_ConfigType *ConfigPtr)
{
    boolean returnstatus = (boolean) TRUE;
    uint32 loopCnt, cnt;

    for(loopCnt = 0U ; loopCnt < CAN_NUM_CONTROLLER ; loopCnt++)
    {
        if(NULL_PTR == ConfigPtr->CanControllerList[loopCnt])
        {
            returnstatus = (boolean) FALSE;
        }
        else if(NULL_PTR == ConfigPtr->CanControllerList[loopCnt]->DefaultBaud)
        {
            returnstatus = (boolean) FALSE;
        }
        else if(CAN_INVALID_BASE_ADDR ==
                    CanConfigSet_CanController_List_PC[loopCnt]->CntrAddr)
        {
            returnstatus = (boolean) FALSE;
        }
        else
        {
            for(cnt = 0U ; cnt <= ConfigPtr->MaxBaudConfigID[loopCnt]; cnt++)
            {
                if(NULL_PTR ==
                ConfigPtr->CanControllerList[loopCnt]->BaudRateConfigList[cnt])
                {
                    returnstatus = (boolean) FALSE;
                }
            }
        }

        if (returnstatus == (boolean)FALSE)
        {
            break;
        }
    }

    return returnstatus;
}

CAN_FUNC_TEXT_SECTION static boolean Can_CheckMbConfig(
    const Can_ConfigType *ConfigPtr)
{
    boolean returnstatus = (boolean) TRUE;
    uint32 loopCnt;

    for(loopCnt = 0U ; loopCnt < CAN_NUM_MAILBOXES ; loopCnt++)
    {
        if(NULL_PTR == ConfigPtr->MailBoxList[loopCnt])
        {
            returnstatus = (boolean) FALSE;
        }
        else if(NULL_PTR == ConfigPtr->MailBoxList[loopCnt]->Controller)
        {
            returnstatus = (boolean) FALSE;
        }
        else
        {
            /*Do Nothing*/
        }

        if(returnstatus == (boolean)FALSE)
        {
            break;
        }
    }
    return returnstatus;
}
#endif

/*******************************************************************************
 * Can_CheckSetControllerModeDet
 ******************************************************************************/
/*! \brief      This function will check DET for SetControllerMode API.
 *
 *  \param[in]  uint8 Controller Controller Id
 *
 *  \context
 ******************************************************************************/
#if (CAN_DEV_ERROR_DETECT == STD_ON)
/* Design :CAN_DesignId_006*/
CAN_FUNC_TEXT_SECTION static boolean Can_CheckSetControllerModeDet(
    uint8 Controller, const Can_DriverObjType * canDrvObj)
{
    boolean returnstatus;
    if (Can_DrvState == CAN_UNINIT)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_SETCTR_ID, (uint8) CAN_E_UNINIT);
        returnstatus = (boolean) FALSE;
    }
    else if(Controller >= (canDrvObj->canMaxControllerCount))
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_SETCTR_ID,
                               (uint8) CAN_E_PARAM_CONTROLLER);
        returnstatus = (boolean) FALSE;
    }
    else if(canDrvObj->canController[Controller].
                        canControllerConfig_PC.CntrActive == (boolean) FALSE)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_SETCTR_ID, (uint8) CAN_E_UNINIT);
        returnstatus = (boolean) FALSE;
    }
    else
    {
        /* MISRA C Compliance */
        returnstatus = (boolean) TRUE;
    }
    return returnstatus;
}

#endif

/*******************************************************************************
 * Can_CheckDisableDet
 ******************************************************************************/
/*! \brief      This function will check DET for Enable API.
 *
 *  \param[in]  uint8 Controller Controller Number in the can hardware its 0-3
 *
 *  \context
 ******************************************************************************/
#if (CAN_DEV_ERROR_DETECT == STD_ON)
/* Design :CAN_DesignId_006*/
CAN_FUNC_TEXT_SECTION static boolean Can_CheckDisableDet(uint8 Controller,
                                   const Can_DriverObjType * canDrvObj)
{
    boolean returnstatus;
    if (Can_DrvState == CAN_UNINIT)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_DIINT_ID, (uint8) CAN_E_UNINIT);
        returnstatus = (boolean) FALSE;
    }
    else if (Controller >= (canDrvObj->canMaxControllerCount))
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_DIINT_ID,
                               (uint8) CAN_E_PARAM_CONTROLLER);
        returnstatus = (boolean) FALSE;
    }
    else if (canDrvObj->canController[Controller].
                        canControllerConfig_PC.CntrActive == (boolean) FALSE)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_DIINT_ID, (uint8) CAN_E_UNINIT);
        returnstatus = (boolean) FALSE;
    }
    else
    {
        returnstatus = (boolean) TRUE;
        /* MISRA C Compliance */
    }
    return returnstatus;
}

#endif

/*******************************************************************************
 * Can_CheckEnableDet
 ******************************************************************************/
/*! \brief      This function will check DET for Disable API.
 *
 *  \param[in]  uint8 Controller Controller Number in the can hardware its 0-3
 *
 *  \context
 ******************************************************************************/
#if (CAN_DEV_ERROR_DETECT == STD_ON)
/* Design :CAN_DesignId_006*/
CAN_FUNC_TEXT_SECTION static boolean Can_CheckEnableDet(uint8 Controller,
                                  const Can_DriverObjType * canDrvObj)
{
    boolean returnstatus;
    if (Can_DrvState == CAN_UNINIT)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_ENINT_ID, (uint8) CAN_E_UNINIT);
        returnstatus = (boolean) FALSE;
    }
    else if (Controller >= (canDrvObj->canMaxControllerCount))
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_ENINT_ID,
                               (uint8) CAN_E_PARAM_CONTROLLER);
        returnstatus = (boolean) FALSE;
    }
    else if (canDrvObj->canController[Controller].
                        canControllerConfig_PC.CntrActive == (boolean) FALSE)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_ENINT_ID, (uint8) CAN_E_UNINIT);
        returnstatus = (boolean) FALSE;
    }
    else
    {
        returnstatus = (boolean) TRUE;
        /* MISRA C Compliance */
    }
    return returnstatus;
}

#endif

/*******************************************************************************
 * Can_CheckWriteDet
 ******************************************************************************/
/*! \brief      This function will check DET for WriteAPI.
 *
 *  \param[in]  uint8 Hth - Hardware Handle
 *              const Can_PduType *PduInfo - pointer to pdu.
 *
 *  \context
 ******************************************************************************/
#if (CAN_DEV_ERROR_DETECT == STD_ON)
/* Design :CAN_DesignId_006*/
CAN_FUNC_TEXT_SECTION static boolean Can_CheckWriteDet(const uint32 Hth,
                                 const Can_PduType *PduInfo,
                                 const Can_DriverObjType *canDrvObj)
{
    boolean returnstatus = (boolean) FALSE;
    uint8          MsgCntrlr;

    if (Can_DrvState == CAN_UNINIT)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_WRITE_ID,
                               (uint8) CAN_E_UNINIT);
        returnstatus = (boolean) FALSE;
    }
    else if (canDrvObj->maxMbCnt <= Hth)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_WRITE_ID,
                               (uint8) CAN_E_PARAM_HANDLE);
        returnstatus = (boolean) FALSE;
    }
    else if ((PduInfo == NULL_PTR) || (PduInfo->sdu == NULL_PTR))
    {
        /* Can config pointer is not valid */
        (void) Det_ReportError((uint16) CAN_MODULE_ID, (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_WRITE_ID,
                               (uint8) CAN_E_PARAM_POINTER);
        returnstatus = (boolean) FALSE;
    }
    else
    {
        MsgCntrlr = canDrvObj->canMailbox[Hth].
                                    mailBoxConfig.Controller->ControllerId;
        returnstatus = (boolean) TRUE;
    }
    if(returnstatus == (boolean) TRUE)
    {
        if (PduInfo->length > 64U)
        {
          (void) Det_ReportError((uint16) CAN_MODULE_ID,
                                 (uint8) CAN_INSTANCE_ID,
                                 (uint8) CAN_WRITE_ID,
                                 (uint8) CAN_E_PARAM_DLC);
          returnstatus = (boolean) FALSE;
        }
        else if((PduInfo->length > 8U) &&
                (canDrvObj->canMailbox[Hth].
                                    mailBoxConfig.Controller->CanFDModeEnabled
                                    != (boolean)TRUE))
        {
            (void) Det_ReportError((uint16) CAN_MODULE_ID,
                                   (uint8) CAN_INSTANCE_ID,
                                   (uint8) CAN_WRITE_ID,
                                   (uint8) CAN_E_PARAM_DLC);
            returnstatus = (boolean) FALSE;
        }
        else if((PduInfo->length > 8U) && (canDrvObj->canMailbox[Hth].
                                    mailBoxConfig.Controller->CanFDModeEnabled
                                    == (boolean)TRUE) &&
                (CAN_ID_CAN_CONTROLLER_TYPE_MASK !=
                        (CAN_ID_CAN_CONTROLLER_TYPE_MASK & PduInfo->id)))
        {
            (void) Det_ReportError((uint16) CAN_MODULE_ID,
                                   (uint8) CAN_INSTANCE_ID,
                                   (uint8) CAN_WRITE_ID,
                                   (uint8) CAN_E_PARAM_DLC);
            returnstatus = (boolean) FALSE;
        }
        else if (canDrvObj->canController[MsgCntrlr].
                    canControllerConfig_PC.CntrActive == (boolean) FALSE)
        {
            /* Can controller is not valid */
            (void) Det_ReportError((uint16) CAN_MODULE_ID,
                                   (uint8) CAN_INSTANCE_ID,
                                   (uint8) CAN_WRITE_ID,
                                   (uint8) CAN_E_UNINIT);
            returnstatus = (boolean) FALSE;
        }
        else
        {
            /* MISRA C Compliance */
            returnstatus = (boolean) TRUE;
        }
    }

    return returnstatus;
}

#endif

/*******************************************************************************
 * Can_SetBaudrateDet
 ******************************************************************************/
/*! \brief      This function will check DET for Can_SetBaudrateDet API.
 *
 *  \param[in]  uint8 Controller Controller Id
 *
 *  \context
 ******************************************************************************/
/*Requirements: SWS_CAN_00492, MCAL-2361, MCAL-2362 */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
CAN_FUNC_TEXT_SECTION static boolean Can_SetBaudrateDet(uint8 Controller,
                                   const Can_DriverObjType * canDrvObj)
{
    boolean returnstatus = (boolean) TRUE;
    if (Can_DrvState == CAN_UNINIT)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID,
                               (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_SETBAUDRATE_ID,
                               (uint8) CAN_E_UNINIT);
        returnstatus = (boolean) FALSE;
    }
    else if (Controller >= (canDrvObj->canMaxControllerCount))
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID,
                               (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_SETBAUDRATE_ID,
                               (uint8) CAN_E_PARAM_CONTROLLER);
        returnstatus = (boolean) FALSE;
    }
    else if (canDrvObj->canController[Controller].canState !=
                                                CAN_CS_STOPPED)
    {
        (void) Det_ReportError((uint16) CAN_MODULE_ID,
                               (uint8) CAN_INSTANCE_ID,
                               (uint8) CAN_SETBAUDRATE_ID,
                               (uint8) CAN_E_TRANSITION);
        returnstatus = (boolean) FALSE;
    }
    else
    {
        /* MISRA C Compliance */
    }
    return returnstatus;
}

#endif

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

/*******************************************************************************
 * INTERRUPT SERVICE ROUTINES
 ******************************************************************************/
/* Design : DES_CAN_031 */
#define CAN_START_SEC_ISR_CODE
#include "Can_MemMap.h"

#if defined (CAN_CONTROLLER_MCU_MCAN0)
/*******************************************************************************
 * Can_0_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the CAN controller 0. All the
 *              Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_0_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCU_MCAN0];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCU_MCAN0) */

#if defined (CAN_CONTROLLER_MCU_MCAN1)
/*******************************************************************************
 * Can_1_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the CAN controller 1. All the
 *              Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_1_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCU_MCAN1];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCU_MCAN1) */

#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)

#if defined (CAN_CONTROLLER_MCAN0)
/*******************************************************************************
 * Can_2_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 0.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_2_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN0];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN0) */

#if defined (CAN_CONTROLLER_MCAN1)
/*******************************************************************************
 * Can_3_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 1.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_3_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN1];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN1) */

#if defined (CAN_CONTROLLER_MCAN2)
/*******************************************************************************
 * Can_4_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 2.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_4_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN2];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN2) */

#if defined (CAN_CONTROLLER_MCAN3)
/*******************************************************************************
 * Can_5_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 3.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_5_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN3];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN3) */

#if defined (CAN_CONTROLLER_MCAN4)
/*******************************************************************************
 * Can_6_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 4.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_6_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN4];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN4) */

#if defined (CAN_CONTROLLER_MCAN5)
/*******************************************************************************
 * Can_7_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 5.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_7_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN5];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN5) */

#if defined (CAN_CONTROLLER_MCAN6)
/*******************************************************************************
 * Can_8_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 6.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_8_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN6];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN6) */

#if defined (CAN_CONTROLLER_MCAN7)
/*******************************************************************************
 * Can_9_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 7.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_9_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN7];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN7) */

#if defined (CAN_CONTROLLER_MCAN8)
/*******************************************************************************
 * Can_10_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 8.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_10_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN8];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN8) */

#if defined (CAN_CONTROLLER_MCAN9)
/*******************************************************************************
 * Can_11_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 9.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_11_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN9];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN9) */

#if defined (CAN_CONTROLLER_MCAN10)
/*******************************************************************************
 * Can_12_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 10.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_12_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN10];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN10) */

#if defined (CAN_CONTROLLER_MCAN11)
/*******************************************************************************
 * Can_13_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 11.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_13_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN11];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN11) */

#if defined (CAN_CONTROLLER_MCAN12)
/*******************************************************************************
 * Can_14_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 12.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_14_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN12];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN12) */

#if defined (CAN_CONTROLLER_MCAN13)
/*******************************************************************************
 * Can_15_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 13.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_15_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN13];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN13) */

#if defined (SOC_J7200) || defined (SOC_J721S2)
#if defined (CAN_CONTROLLER_MCAN14)
/*******************************************************************************
 * Can_16_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 14.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_16_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN14];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN14) */

#if defined (CAN_CONTROLLER_MCAN15)
/*******************************************************************************
 * Can_17_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 15.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_17_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN15];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN15) */

#if defined (CAN_CONTROLLER_MCAN16)
/*******************************************************************************
 * Can_18_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 16.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_18_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN16];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN16) */

#if defined (CAN_CONTROLLER_MCAN17)
/*******************************************************************************
 * Can_19_Int0ISR_Fun
 ******************************************************************************/
/*! \brief      This is the ISR function for the MAIN Domain CAN controller 17.
 *              All the Interrupts are hooked to MCAN INT0.
 *              This ISR sends the TX confirmation for the successful tx msg.
 *              This ISR will call the RX processing function for the received
 *              message.
 *
 *  \param[in]  void
 *
 *  \context    ISR
 ******************************************************************************/
CAN_ISR_TEXT_SECTION FUNC(void, CAN_CODE) Can_19_Int0ISR_Fun(void)
{
    uint32 ctrlId;

    ctrlId = Can_DriverObj.controllerIDMap[CAN_CONTROLLER_INSTANCE_MCAN17];
    Can_mcanProcessISR(&Can_DriverObj.canController[ctrlId],
                       &Can_DriverObj.canMailbox[0]);
}
#endif /* #if defined (CAN_CONTROLLER_MCAN17) */

#endif /* #if defined (SOC_J7200)  || defined (SOC_J721S2)*/
#endif /* #if defined (SOC_J721E) || defined (SOC_J7200)  || defined (SOC_J721S2)*/

#define CAN_STOP_SEC_ISR_CODE
#include "Can_MemMap.h"

/*******************************************************************************
 *  End of File: Can.c
 ******************************************************************************/
