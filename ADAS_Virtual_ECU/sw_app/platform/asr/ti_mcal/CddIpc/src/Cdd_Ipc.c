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
 *  \file     Cdd_Ipc.c
 *
 *  \brief    This file implements CDD IPC service API's and reception interrupt
 *              handler
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "string.h"
#include "Cdd_Ipc.h"

#include "Cdd_IpcCfg.h"
#include "Cdd_IpcPriv.h"

#define CDD_IPC_START_SEC_CODE
#include "Cdd_Ipc_MemMap.h"
#define CDD_IPC_STOP_SEC_CODE
#include "Cdd_Ipc_MemMap.h"


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* AUTOSAR version information check has to match definition in header file */
#if ((CDD_IPC_AR_RELEASE_MAJOR_VERSION != (4U)) || \
    (CDD_IPC_AR_RELEASE_MINOR_VERSION != (3U)) ||  \
    (CDD_IPC_AR_RELEASE_REVISION_VERSION != (1U)))
    #error "Cdd Ipc: AUTOSAR Version Numbers of Cdd Ipc are different!!"
#endif

/* AUTOSAR version information check has to match definition in header file */
#if ((CDD_IPC_SW_MAJOR_VERSION != (1U)) || \
    (CDD_IPC_SW_MINOR_VERSION != (3U)) ||  \
    (CDD_IPC_SW_PATCH_VERSION != (5U)))
    #error "Cdd Ipc: Software Version Numbers are inconsistent!!"
#endif

#define CDD_IPC_MAX_CTRL_MSG_PER_CORE   (2U)
/**< Maximum of N messages that can queued, aps will have to drain this buffer
        Post that, the message would be lost */
/**
 * \brief Space to stored received CTRL messages.
 *      256 Messages
 *      Each message of size 496 bytes
 *      Size of RPMessage_MsgElem:32U
 *      RPMSG Object size, for managing message objects
 */
 #define CDD_IPC_RPMSG_CTRL_DATA_SIZE \
          ((256 *\
            (CDD_IPC_MAX_MSG_LEN + 32U)) \
          + CDD_IPC_RPMSG_OBJ_SIZE)

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
/*
 * Design : DES_CDD_IPC_010
 */
/*
 * Requirements : MCAL-3715
 *
 */
#define CDD_IPC_START_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"
/** \brief CDD IPC Driver status. Can be initialized (TRUE) & uninitialized
            (FALSE) */
CDD_IPC_VAR_DATA_INIT_32_SECTION static volatile
            VAR(uint32, CDD_IPC_VAR_CLEARED) Cdd_IpcDrvStatus = (uint32)FALSE;

#define CDD_IPC_STOP_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"

#define CDD_IPC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Ipc_MemMap.h"
/** \brief CDD IPC driver object */
CDD_IPC_VAR_DATA_NO_INIT_UNSPECIFIED_SECTION static
            VAR(Cdd_IpcObjType, CDD_IPC_VAR_NO_INIT) Cdd_IpcDrvObj;

#define CDD_IPC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Ipc_MemMap.h"

#define CDD_IPC_START_SEC_VAR_NO_INIT_8_ALIGN_8B
#include "Cdd_Ipc_MemMap.h"
CDD_IPC_VAR_DATA_NO_INIT_8_SECTION_ALIGN_8B static VAR(uint8, CDD_IPC_VAR_NO_INIT)
                        Cdd_IpcRpMsgCtrlBuffer[CDD_IPC_RPMSG_CTRL_DATA_SIZE];
#define CDD_IPC_STOP_SEC_VAR_NO_INIT_8_ALIGN_8B
#include "Cdd_Ipc_MemMap.h"
/**
 * \brief A array of buffer pointers that describe memory allocated to local
 *          communication channels
 */
extern const struct Cdd_IpcChannelBufType_s
                            Cdd_IpcCommChanBufferPtr [CDD_IPC_MAX_CHANNEL_CFG];
/* ========================================================================== */
/*                          Local Function Prototypes                         */
/* ========================================================================== */
#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
static Std_ReturnType Cdd_IpcCheckInitConfig(const Cdd_IpcConfigType *pCfg);
/**< Check PC configurations */
static Std_ReturnType Cdd_IpcCheckChConfig(const Cdd_IpcChannelType *pChCfgChk,
                                            uint32 channelCount);
/**< Check PC Channel Configurations */
#endif /* CDD_IPC_DEV_ERROR_DETECT */

static uintptr_t Cdd_IpcCriticalSectionIntEnter(void);
/**< Exclusive Area Enter */
static void Cdd_IpcCriticalSectionIntExit(uintptr_t keyNotUsed);
/**< Exclusive Area Exit */
static Std_ReturnType Cdd_IpcInitDepends(Cdd_IpcObjType *pDrvObj,
                                            const Cdd_IpcConfigType *pCfg);
/**< Initialize dependencies */
static Std_ReturnType Cdd_IpcInitVirtIoCtrlEp(Cdd_IpcObjType *pDrvObj,
                                            const Cdd_IpcConfigType *pCfg);
/**< Initialize, Cores, HISR and Exclusive access */
static Std_ReturnType Cdd_IpcInitRpMsgCtrl(Cdd_IpcObjType *pDrvObj);
/**< Initialize RP Messages and for control end point */

static Std_ReturnType Cdd_IpcInitEps(Cdd_IpcObjType *pDrvObj,
                                        const Cdd_IpcConfigType *pCfg);

static void Cdd_IpcNewMsgCb(uint32_t srcEndPt, uint32_t procId);
/**< New Message notification from EP and Source Processor ID */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define CDD_IPC_START_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

#if (STD_ON == CDD_IPC_VERSION_INFO_API)
/*
 * Design : DES_CDD_IPC_032
 */
/*
 * Requirements : MCAL-3739, MCAL-3740, MCAL-3741
 */
/** \brief Return the version information of this implementation */
CDD_IPC_FUNC_TEXT_SECTION FUNC(void, CDD_IPC_CODE) Cdd_IpcGetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_APP_DATA) VersionInfoPtr)
{
#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if (NULL_PTR == VersionInfoPtr)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                        CDD_IPC_SID_GETVERSIONINFO, CDD_IPC_E_PARAM_POINTER);
    }
    else
#endif  /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */
    {
        VersionInfoPtr->vendorID            = CDD_IPC_VENDOR_ID;
        VersionInfoPtr->moduleID            = CDD_IPC_MODULE_ID;
        VersionInfoPtr->sw_major_version    = (uint8) CDD_IPC_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version    = (uint8) CDD_IPC_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version    = (uint8) CDD_IPC_SW_PATCH_VERSION;
    }

    return;
}
#endif  /* #if (STD_ON == CDD_IPC_VERSION_INFO_API) */


/*
 * Design : DES_CDD_IPC_003, DES_CDD_IPC_010, DES_CDD_IPC_027
 */
/*
 * Requirements : MCAL-3708, MCAL-3709, MCAL-3710, MCAL-3706, MCAL-3715,
 *                MCAL-3756, MCAL-3716, MCAL-3707
 */

CDD_IPC_FUNC_TEXT_SECTION FUNC(void, CDD_IPC_CODE) Cdd_IpcInit(void)
{
    Std_ReturnType rtnVal = E_NOT_OK;

    /* Only Pre Compile variant supported */
    const Cdd_IpcConfigType *pCfg = &CddIpcConfiguraions_PC;
    /**
     * \warning : Don't reset Mailbox IP. An entity out-side will reset and
     *              this driver is initialized.
     */

    pCfg = &CddIpcConfiguraions_PC;

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) != Cdd_IpcDrvStatus)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_INIT, CDD_IPC_E_ALREADY_INITIALIZED);
    }
    else
    {
        if ((Std_ReturnType)E_OK == Cdd_IpcCheckInitConfig(pCfg))
        {
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */

            /* Steps
                1. Build the required tables, proc names, etc...
                2. Initialize VirtIO, with provided VRING Address
                3. Create RP Messages for all end points
            */
            rtnVal = Cdd_IpcInitDepends(&Cdd_IpcDrvObj, pCfg);

            if ((Std_ReturnType)E_OK == rtnVal)
            {
                rtnVal = Cdd_IpcInitVirtIoCtrlEp(&Cdd_IpcDrvObj, pCfg);
            }

            if ((Std_ReturnType)E_OK == rtnVal)
            {
                rtnVal = Cdd_IpcInitEps(&Cdd_IpcDrvObj, pCfg);
            }

            if ((Std_ReturnType)E_OK == rtnVal)
            {
                /* Everything went well, we are initialized now!!! */
                Cdd_IpcDrvStatus = (uint32) TRUE;
            }

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
            else
            {
                (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_INIT, CDD_IPC_E_INIT_FAILED);
            }

        }
        else
        {
            (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_INIT, CDD_IPC_E_INVALID_CONFIG);
        }
    }
#endif /* CDD_IPC_DEV_ERROR_DETECT */
    return;
}

/*
 * Design : DES_CDD_IPC_010, DES_CDD_IPC_029
 */
/*
 * Requirements : MCAL-3756, MCAL-3717, MCAL-3718, MCAL-3719, MCAL-3720,
 *                  MCAL-3721, MCAL-3722, MCAL-3723
 *
 */
FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_IpcSendMsg(
                                    VAR(uint32, AUTOMATIC) chId,
                                    P2CONST(void, AUTOMATIC, CDD_APP_DATA) pBuf,
                                    VAR(uint32, AUTOMATIC) bufLen)
{
    Std_ReturnType rtnVal = (Std_ReturnType)E_NOT_OK;
    uint32 remoteEndPt, remoteProcId, ownEp;
    const Cdd_IpcChannelType *pChanCfg = CddIpcConfiguraions_PC.pChCfg;

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Cdd_IpcDrvStatus)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_SEND, CDD_IPC_E_UNINIT);
    }
    else if ((CddIpcConfiguraions_PC.channelCount <= chId) ||
             (NULL_PTR == pBuf))
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_SEND, CDD_IPC_E_PARAM_POINTER);
    }
    else if ((0U == bufLen) || (CDD_IPC_MAX_MSG_LEN <= bufLen))
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_SEND, CDD_IPC_E_NOT_SUPPORTED);
    }
    else
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */

    {

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
        /* Ensure the commId do match */
        if (chId != pChanCfg[chId].id)
        {
            (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_SEND, CDD_IPC_E_INVALID_CONFIG);
        }
        else
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */
        {
            remoteProcId = pChanCfg[chId].remoteProcId;
            remoteEndPt = Cdd_IpcDrvObj.mapToCommId[remoteProcId][chId].remoteEp;
            ownEp = pChanCfg[chId].localEp;

            if (IPC_SOK == RPMessage_send(Cdd_IpcDrvObj.rpmsgHndl[chId],
                                            remoteProcId, remoteEndPt, ownEp,
                                            (Ptr)pBuf, bufLen))
            {
                rtnVal = (Std_ReturnType)E_OK;
            }
#if (CDD_IPC_E_HARDWARE_ERROR != CDD_IPC_DEM_NO_EVENT)
            else
            {
                (void)Dem_SetEventStatus(CDD_IPC_E_HARDWARE_ERROR,
                    DEM_EVENT_STATUS_FAILED);
            }
#endif /* CDD_IPC_E_HARDWARE_ERROR != CDD_IPC_DEM_NO_EVENT */

        }
    }
    return (rtnVal);
}

/*
 * Design : DES_CDD_IPC_010, DES_CDD_IPC_030
 */
/*
 * Requirements : MCAL-3756, MCAL-3724, MCAL-3725, MCAL-3726, MCAL-3727,
 *                  MCAL-3728, MCAL-3729
 *
 */
CDD_IPC_FUNC_TEXT_SECTION FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_IpcReceiveMsg (
                            VAR(uint32, AUTOMATIC) chId,
                            P2VAR(void, AUTOMATIC, CDD_APP_DATA) pBuf,
                            P2VAR(uint32, AUTOMATIC, CDD_APP_DATA) bufLen)
{
    Std_ReturnType rtnVal = (Std_ReturnType)E_NOT_OK;
    unsigned int remoteEndPt, remoteProcId;
    const Cdd_IpcChannelType *pChanCfg = CddIpcConfiguraions_PC.pChCfg;
    uint32 allocBufLen;

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Cdd_IpcDrvStatus)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_RECEIVE, CDD_IPC_E_UNINIT);
    }
    else if ((CddIpcConfiguraions_PC.channelCount <= chId) ||
             (NULL_PTR == pBuf))
                /* FixMe 512 should come out from the configurator */
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_RECEIVE, CDD_IPC_E_PARAM_POINTER);
    }
    else if (NULL_PTR == bufLen)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_RECEIVE, CDD_IPC_E_NOT_SUPPORTED);
    }
    else
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */
    {

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
        /* Ensure the commId do match */
        if (chId != pChanCfg[chId].id)
        {
            (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_RECEIVE, CDD_IPC_E_INVALID_CONFIG);
        }
        else
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */
        {
            /*
                1. Get the associated RemoteEp & RemoteProc
                2. Initiate the transfer
            */
            remoteProcId = pChanCfg[chId].remoteProcId;
            remoteEndPt = Cdd_IpcDrvObj.mapToCommId[remoteProcId][chId].remoteEp;
            allocBufLen  = *bufLen;
            if (IPC_SOK == RPMessage_recvNb(Cdd_IpcDrvObj.rpmsgHndl[chId],
                                            (Ptr)pBuf, (uint16_t *)bufLen,
                                            &remoteEndPt, &remoteProcId))
            {
                if (allocBufLen < *bufLen)
                {
#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
                    (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                                    CDD_IPC_SID_RECEIVE, CDD_IPC_E_INVALID_CONFIG);
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */
                    rtnVal = (Std_ReturnType)E_NOT_OK;
                }
                else
                {
		    Cdd_IpcDrvObj.mapToCommId[remoteProcId][chId].remoteEp = remoteEndPt;
                    rtnVal = (Std_ReturnType)E_OK;
                }
            }
            else
            {
                /* No DET required here, as apps could call this function
                    anytime after initialization */
                rtnVal = (Std_ReturnType)E_NOT_OK;
            }
        }
    }

    return (Std_ReturnType)rtnVal;
}

/*
 * Design : DES_CDD_IPC_039
 */
/*
 * Requirements : MCAL-4068, MCAL-4069, MCAL-4070, MCAL-4071, MCAL-4072
 *
 */
#if (STD_ON == CDD_IPC_ANNOUNCE_API)
CDD_IPC_FUNC_TEXT_SECTION FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_IpcReceiveCtrlMsg (
                        P2VAR (unsigned int, AUTOMATIC, CDD_APP_DATA) pRemoteProcId,
                        P2VAR (unsigned int, AUTOMATIC, CDD_APP_DATA) pRemoteEndPt,
                        P2VAR (void, AUTOMATIC, CDD_APP_DATA) pBuf,
                        P2VAR (uint32, AUTOMATIC, CDD_APP_DATA) bufLen)
{
    Std_ReturnType rtnVal = (Std_ReturnType)E_NOT_OK;
    Cdd_IpcAnnouncement ctrlMsg;

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Cdd_IpcDrvStatus)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_CTRL_RECEIVE, CDD_IPC_E_UNINIT);
    }
    else if ((NULL_PTR == pBuf) || (0U == bufLen))
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_CTRL_RECEIVE, CDD_IPC_E_PARAM_POINTER);
    }
    else if ((NULL_PTR == pRemoteProcId) || (0U == pRemoteEndPt))
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_CTRL_RECEIVE, CDD_IPC_E_PARAM_POINTER);
    }
    else
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */

    {
        if (IPC_SOK == RPMessage_recvNb(Cdd_IpcDrvObj.ctrlRpmsgHndl,
                                        (Ptr)&ctrlMsg, (uint16_t *)bufLen,
                                        pRemoteEndPt, pRemoteProcId))
        {
            rtnVal = (Std_ReturnType)E_OK;
            (void) memcpy(pBuf, &ctrlMsg.name[0U], CDD_IPC_MAX_CTRL_MSG_LEN);
            *pRemoteEndPt = ctrlMsg.endPt;
            *bufLen = CDD_IPC_MAX_CTRL_MSG_LEN;
        }
        else
        {
            /* No DET required here, as apps could call this function
                anytime after initialization */
            rtnVal = (Std_ReturnType)E_NOT_OK;
        }
    }

    return (Std_ReturnType)rtnVal;
}

#endif /* (STD_ON == CDD_IPC_ANNOUNCE_API) */

/*
 * Design : DES_CDD_IPC_010, DES_CDD_IPC_031
 */
/*
 * Requirements : MCAL-3756, MCAL-3730, MCAL-3731, MCAL-3732, MCAL-3733,
 *                  MCAL-3734, MCAL-3735
 *
 */
#if (STD_ON == CDD_IPC_ANNOUNCE_API)
FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_IpcAnnounce(
                                    P2CONST(char, AUTOMATIC, CDD_APP_DATA) pBuf,
                                    VAR(uint32, AUTOMATIC) chId)
{
    Std_ReturnType rtnVal = (Std_ReturnType)E_NOT_OK;
    uint32 ownEp, procId;
    const Cdd_IpcChannelType *pChanCfg = CddIpcConfiguraions_PC.pChCfg;

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if (((uint32) FALSE) == Cdd_IpcDrvStatus)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_ANNOUNCE, CDD_IPC_E_UNINIT);
    }
    else if ((NULL_PTR == pBuf))
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_ANNOUNCE, CDD_IPC_E_PARAM_POINTER);
    }
    else if (chId >= CddIpcConfiguraions_PC.channelCount)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                            CDD_IPC_SID_ANNOUNCE, CDD_IPC_E_INVALID_CONFIG);
    }
    else
#endif /* #if (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */

    {
        ownEp = pChanCfg[chId].localEp;
        procId = pChanCfg[chId].remoteProcId;
        if (IPC_SOK == RPMessage_announce(procId, ownEp,
                                             (const char *)pBuf))
        {
            rtnVal = (Std_ReturnType)E_OK;
        }
#if (CDD_IPC_E_HARDWARE_ERROR != CDD_IPC_DEM_NO_EVENT)
        else
        {
            (void)Dem_SetEventStatus(CDD_IPC_E_HARDWARE_ERROR,
                DEM_EVENT_STATUS_FAILED);
        }
#endif /* CDD_IPC_E_HARDWARE_ERROR != CDD_IPC_DEM_NO_EVENT */

    }
    return (rtnVal);
}
#endif /* CDD_IPC_ANNOUNCE_API */

/*
 * Design : DES_CDD_IPC_040
 */
/*
 * Requirements : MCAL-4452
 *
 */
#if (STD_ON == CDD_IPC_REGISTER_READBACK_API)
CDD_IPC_FUNC_TEXT_SECTION FUNC(Std_ReturnType, CDD_IPC_CODE)
                    Cdd_IpcRegisterReadBack(
                    P2VAR(Cdd_IpcRegRbValues, AUTOMATIC, CDD_APP_DATA) pRegArgs)
{

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                    CDD_IPC_SID_REG_READBACK, CDD_IPC_E_NOT_SUPPORTED);
#endif

    return((Std_ReturnType)E_NOT_OK);

}
#endif /* CDD_IPC_REGISTER_READBACK_API */

/*
 * Design : DES_CDD_IPC_041
 */
/*
 * Requirements : MCAL-4453
 *
 */
#if (STD_ON == CDD_IPC_IS_INIT_DONE_API)
CDD_IPC_FUNC_TEXT_SECTION FUNC(boolean, CDD_IPC_CODE) Cdd_IpcIsInitDone(void)
{
    boolean ipcInitDone;

    if (TRUE == Cdd_IpcDrvStatus)
    {
        ipcInitDone = TRUE;
    }
    else
    {
        ipcInitDone = FALSE;
    }

    return ipcInitDone;
}

#endif

#if (STD_ON == CDD_IPC_GET_MAX_MSG_SIZE_API)
FUNC(uint32, CDD_IPC_CODE) Cdd_IpcGetMaxMsgSize(VAR(uint32, AUTOMATIC) chId)
{
    uint32 maxMsgSize;
    Std_ReturnType rtnVal = (Std_ReturnType)E_OK;

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if (CddIpcConfiguraions_PC.channelCount <= chId)
    {
        (void) Det_ReportError(CDD_IPC_MODULE_ID, CDD_IPC_INSTANCE_ID,
                        CDD_IPC_SID_GET_MAX_MSG_SIZE, CDD_IPC_E_PARAM_POINTER);
        rtnVal = E_NOT_OK;
    }
#endif
    if (E_OK == rtnVal)
    {
        maxMsgSize = CddIpcConfiguraions_PC.pChCfg[chId].maxMsgSize;

    }
    else
    {
        maxMsgSize = 0;
    }
    return maxMsgSize;
}
#endif

/* ========================================================================== */
/*                 Internal Function Implementation                           */
/* ========================================================================== */

#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
static Std_ReturnType Cdd_IpcCheckChConfig(const Cdd_IpcChannelType *pChCfgChk,
                                        uint32 channelCount)
{
    uint32 idx;
    Std_ReturnType rtnVal = (Std_ReturnType)E_NOT_OK;
    if (NULL_PTR != pChCfgChk)
    {
        rtnVal = (Std_ReturnType)E_OK;
        for (idx = 0U; ((idx < channelCount) &&
                        ((Std_ReturnType)E_OK == rtnVal)); idx++)
        {
            if ((CDD_IPC_RESERVED_END_POINT == pChCfgChk[idx].localEp) ||
                (CDD_IPC_RESERVED_END_POINT == pChCfgChk[idx].remoteEp))
            {
                rtnVal = (Std_ReturnType)E_NOT_OK;
            }
        }
    }

    return (rtnVal);
}

static Std_ReturnType Cdd_IpcCheckInitConfig(const Cdd_IpcConfigType *pCfg)
{
    /* Checks
        MP : coreIds
            1. numProcs < CDD_IPC_CORE_ID_MAX
            2. ownProcID should be < CDD_IPC_CORE_ID_MAX
        VirtIO  : vertIoCfg
            1. vertIoRingAddr is not NULL
        Comm Channels : channelCount, pChCfg
            2. localEp and remoteEp should not be 53
    */
    Std_ReturnType rtnVal = (Std_ReturnType)E_NOT_OK;
    if (NULL_PTR != pCfg)
    {
        rtnVal = (Std_ReturnType)E_OK;
        if ((CDD_IPC_CORE_ID_MAX <= pCfg->coreIds.numProcs) ||
            (CDD_IPC_CORE_ID_MAX <= pCfg->coreIds.ownProcID))
        {
            rtnVal = (Std_ReturnType)E_NOT_OK;
        }
        else if (NULL_PTR == pCfg->vertIoCfg.vertIoRingAddr)
        {
            rtnVal = (Std_ReturnType)E_NOT_OK;
        }
        else if (NULL_PTR == pCfg->pChCfg)
        {
            rtnVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            rtnVal = Cdd_IpcCheckChConfig(pCfg->pChCfg, pCfg->channelCount);
        }
    }
    return ((Std_ReturnType)rtnVal);
}
#endif /* CDD_IPC_DEV_ERROR_DETECT */

uintptr_t Cdd_IpcCriticalSectionIntEnter(void)
{
    SchM_Enter_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0();
    return (uintptr_t)1U;
}

void Cdd_IpcCriticalSectionIntExit(uintptr_t keyNotUsed)
{
    SchM_Exit_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0();
}

static int Cdd_IpcHIsrCreate(Ipc_OsalHIsrHandle *handle,
                                    Ipc_OsalHIsrFxn fxn, void *arg)
{
    sint32 rtnVal = IPC_EBADARGS;

    /* No HISR, HISR would be invoked in ISR context it self */
    if ((NULL != handle) && ((NULL != fxn) && (NULL != arg)))
    {
        handle->arg0    = (uintptr_t) arg;
        handle->arg1    = (uintptr_t) NULL;
        handle->hIsrFxn = fxn;
        handle->hLosHisrHandle = NULL;
        rtnVal = IPC_SOK;
    }

    return (rtnVal);
}

static void Cdd_IpcHIsrDelete(Ipc_OsalHIsrHandle *handle)
{
    if (NULL != handle)
    {
        handle->arg0    = NULL;
        handle->arg1    = NULL;
        handle->hIsrFxn = NULL;
        handle->hLosHisrHandle = NULL;
    }

    return;
}

static int Cdd_IpcHIsrPost(Ipc_OsalHIsrHandle *handle)
{
    sint32 rtnVal = IPC_EBADARGS;

    if (NULL != handle)
    {
        handle->hIsrFxn(handle->arg0, NULL);
        rtnVal = IPC_SOK;
    }
    return (rtnVal);
}

static void *Cdd_IpcHIsrGateCreate(void)
{
    /* Really!!, nothing required as rely on interrupt locking for exclusive
        access. */
    return (void *) 1U;
}

static void Cdd_IpcHIsrGateDelete(Ipc_OsalHIsrGateHandle *handle)
{
    /* Really!!, nothing required as rely on interrupt locking for exclusive
        access. */
    return;
}

static int Cdd_IpcHIsrGateEnter(Ipc_OsalHIsrGateHandle handle)
{
    /* Really!!, nothing required as rely on interrupt locking for exclusive
        access. */
    return ((sint32)Cdd_IpcCriticalSectionIntEnter());
}

static void Cdd_IpcHIsrGateExit(Ipc_OsalHIsrGateHandle handle, int key)
{
    /* Really!!, nothing required as rely on interrupt locking for exclusive
        access. */
    Cdd_IpcCriticalSectionIntExit(key);
    return;
}

static Std_ReturnType Cdd_IpcInitDepends(Cdd_IpcObjType *pDrvObj,
                                            const Cdd_IpcConfigType *pCfg)
{
    Std_ReturnType rtnVal = E_NOT_OK;
    Ipc_InitPrms initPrms;
    uint32 procIdx, commIdx;
#if (STD_ON == CDD_IPC_DEV_ERROR_DETECT)
    if ((NULL_PTR != pDrvObj) && (NULL_PTR != pCfg))
#endif /* (STD_ON == CDD_IPC_DEV_ERROR_DETECT) */

    {
        /*  1. Init Core Names
            2. Init HISR and It's dependencies
            3. Linkup local cb for new msg notification
            4. Initialize mapToCommId to un-mapped state
        */
        if (IPC_SOK == Ipc_mpSetConfig(pCfg->coreIds.ownProcID,
                                    pCfg->coreIds.numProcs,
                                    (unsigned int*)&pCfg->coreIds.remoteProcID[0U]))
        {
            rtnVal = (Std_ReturnType)E_OK;

            IpcInitPrms_init(0U, &initPrms);

            initPrms.instId = 0U;
            initPrms.osalPrms.disableAllIntr = &Cdd_IpcCriticalSectionIntEnter;
            initPrms.osalPrms.restoreAllIntr = &Cdd_IpcCriticalSectionIntExit;

            initPrms.osalPrms.createHIsr    = &Cdd_IpcHIsrCreate;
            initPrms.osalPrms.deleteHIsr    = &Cdd_IpcHIsrDelete;
            initPrms.osalPrms.postHIsr      = &Cdd_IpcHIsrPost;
            initPrms.osalPrms.createHIsrGate = &Cdd_IpcHIsrGateCreate;
            initPrms.osalPrms.deleteHIsrGate = &Cdd_IpcHIsrGateDelete;
            initPrms.osalPrms.lockHIsrGate   = &Cdd_IpcHIsrGateEnter;
            initPrms.osalPrms.unLockHIsrGate = &Cdd_IpcHIsrGateExit;

            initPrms.osalPrms.createMutex   = (Ipc_OsalMutexCreateFxn) NULL_PTR;
            initPrms.osalPrms.deleteMutex   = (Ipc_OsalMutexDeleteFxn) NULL_PTR;
            initPrms.osalPrms.lockMutex     = (Ipc_OsalMutexLockFxn) NULL_PTR;
            initPrms.osalPrms.unlockMutex   = (Ipc_OsalMutexUnlockFxn) NULL_PTR;
            initPrms.osalPrms.registerIntr  = (Ipc_OsalRegisterIntrFxn)NULL_PTR;

            initPrms.newMsgFxn = &Cdd_IpcNewMsgCb;

            if (IPC_SOK != Ipc_init(&initPrms))
            {
                rtnVal = E_NOT_OK;
            }
        }
        if ((Std_ReturnType)E_OK == rtnVal)
        {
            for (procIdx = 0U; procIdx < CDD_IPC_CORE_ID_MAX; procIdx++)
            {
                for (commIdx = 0U; commIdx < CDD_IPC_MAX_CHANNEL_CFG; commIdx++)
                {
                    pDrvObj->mapToCommId[procIdx][commIdx].isValid  = 0U;
                    pDrvObj->mapToCommId[procIdx][commIdx].remoteEp =
                                                    0xFFFFFFFFU;
                    pDrvObj->mapToCommId[procIdx][commIdx].commChId   =
                                                    0xFFFFFFFFU;
                }
            }
        }
    }

    return (rtnVal);
}

static Std_ReturnType Cdd_IpcInitVirtIoCtrlEp(Cdd_IpcObjType *pDrvObj,
                                            const Cdd_IpcConfigType *pCfg)
{
    Std_ReturnType rtnVal = (Std_ReturnType)E_OK;

    Ipc_VirtIoParams  vqParam;

    vqParam.vqObjBaseAddr = (void*) &Cdd_IpcDrvVertIoObj[0U];
    vqParam.vqBufSize     = CDD_IPC_VERTIO_OBJECT_SIZE;

    vqParam.vringBaseAddr = pCfg->vertIoCfg.vertIoRingAddr;
    vqParam.vringBufSize  = pCfg->vertIoCfg.vertIoRingSize;
    vqParam.timeoutCnt    = CDD_IPC_MAX_RETRY_NOTIFY;
                            /* When the MBX FIFO is full, number of iterations
                               to wait before giving up */
    if (IPC_SOK != Ipc_initVirtIO(&vqParam))
    {
        rtnVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        rtnVal = Cdd_IpcInitRpMsgCtrl(&Cdd_IpcDrvObj);
    }

    return (rtnVal);
}


static Std_ReturnType Cdd_IpcInitRpMsgCtrl(Cdd_IpcObjType *pDrvObj)
{
    Std_ReturnType rtnVal = (Std_ReturnType)E_NOT_OK;

    if (NULL_PTR != pDrvObj)
    {
        RPMessage_Params ctrlParam;
        (void)RPMessageParams_init(&ctrlParam);

        /* Override the default */
        ctrlParam.numBufs     = CDD_IPC_MAX_CTRL_MSG_PER_CORE;

        ctrlParam.buf         = &Cdd_IpcRpMsgCtrlBuffer[0U];
        ctrlParam.bufSize     = CDD_IPC_RPMSG_CTRL_DATA_SIZE;
        ctrlParam.stackBuffer = NULL;
        ctrlParam.stackSize   = 0U;
        (void)RPMessage_init(&ctrlParam);

#if (STD_ON == CDD_IPC_ANNOUNCE_API)
        ctrlParam.requestedEndpt = IPC_CTRL_ENDPOINT_ID;

        pDrvObj->ctrlRpmsgHndl = RPMessage_create(&ctrlParam, &pDrvObj->ctrlEp);
        if (NULL_PTR != pDrvObj->ctrlRpmsgHndl)
        {
            rtnVal = (Std_ReturnType)E_OK;
        }
#else
        /* Dont require the control end point */
        rtnVal = (Std_ReturnType)E_OK;
#endif /* #if (STD_ON == CDD_IPC_ANNOUNCE_API) */

    }

    return (rtnVal);
}

/*
 * Design : DES_CDD_IPC_027
 */
/*
 * Requirements : MCAL-3714
 */

static Std_ReturnType Cdd_IpcInitEps(Cdd_IpcObjType *pDrvObj,
                                        const Cdd_IpcConfigType *pCfg)
{
    uint32 idx;
    RPMessage_Params    params;
    unsigned int              myEndPt, rProcId, chId;
    const Cdd_IpcChannelType    *pChCfg = pCfg->pChCfg;
    Std_ReturnType  rtnVal = (Std_ReturnType)E_OK;

    for (idx = 0U; ((idx < pCfg->channelCount) &&
                    ((Std_ReturnType)E_OK == rtnVal)); idx++)
    {
        (void)RPMessageParams_init(&params);
        params.requestedEndpt   = pChCfg[idx].localEp;
        params.numBufs          = pChCfg[idx].numMsgQueued;
        params.buf              = Cdd_IpcCommChanBufferPtr[idx].pBuf;
        params.bufSize          = Cdd_IpcCommChanBufferPtr[idx].bufSize;

        pDrvObj->rpmsgHndl[idx] = RPMessage_create(&params, &myEndPt);
        if (NULL_PTR == pDrvObj->rpmsgHndl[idx])
        {
            rtnVal = (Std_ReturnType)E_NOT_OK;
        }
    }

    /* Map commId to Ep */
    for (idx = 0U; ((idx < pCfg->channelCount) &&
                    ((Std_ReturnType)E_OK == rtnVal)); idx++)
    {
        rProcId     = pChCfg[idx].remoteProcId;
        chId        = pChCfg[idx].id;
        pDrvObj->mapToCommId[rProcId][chId].commChId = chId;
        pDrvObj->mapToCommId[rProcId][chId].remoteEp = pChCfg[idx].remoteEp;
        /* Some positive integer value, 0 is for invalid */
        pDrvObj->mapToCommId[rProcId][chId].isValid  = 1U;
    }

    /* Enable interrupts now */
    for (idx = 0U; idx < pCfg->coreIds.numProcs; idx++)
    {
        Ipc_mailboxEnableNewMsgInt(pCfg->coreIds.ownProcID,
                                        pCfg->coreIds.remoteProcID[idx]);
    }

    return rtnVal;
}

#define CDD_IPC_STOP_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

#define CDD_IPC_START_SEC_ISR_CODE
#include "Cdd_Ipc_MemMap.h"

CDD_IPC_ISR_TEXT_SECTION
static void Cdd_IpcNewMsgCb(uint32_t srcEndPt, uint32_t procId)
{
    uint32 idx, commId;
    Cdd_IpcMapProcId2ComId *pComMap;

    commId = IPC_CTRL_ENDPOINT_ID;

    if (IPC_CTRL_ENDPOINT_ID == srcEndPt)
    {

#if (STD_ON == CDD_IPC_ANNOUNCE_API)
        /* Let apps know on arrival of new control message */
        CDD_IPC_NEW_CTRL_MSG_NTFY_FXN(procId);
#endif /* CDD_IPC_ANNOUNCE_API */

    }
    else
    {
        if (CDD_IPC_CORE_ID_MAX > procId)
        {
            pComMap = &Cdd_IpcDrvObj.mapToCommId[procId][0U];
            for (idx = 0U; idx < CDD_IPC_MAX_CHANNEL_CFG; idx++)
            {
                if (0U != pComMap[idx].isValid)
                {
                    commId = pComMap[idx].commChId;
                    /* Application notification function,
                        provided by the config */
                    CDD_IPC_NEW_MSG_NTFY_FXN(commId);
                    break;
                }
            }
        }
    }
    return;
}
#define CDD_IPC_STOP_SEC_ISR_CODE
#include "Cdd_Ipc_MemMap.h"

/********************************* End of file ******************************/
