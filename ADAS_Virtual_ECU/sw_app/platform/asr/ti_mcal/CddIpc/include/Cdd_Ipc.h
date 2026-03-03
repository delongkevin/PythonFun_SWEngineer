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
 *  \file     Cdd_Ipc.h
 *
 *  \brief    This file contains interface for InterProcessorCommunication (Ipc)
 *               as a complex device driver.
 *
 */

/**
 *  \defgroup MCAL_IPC_API CDD Ipc Driver
 *
 *  IPC module is provided as an CDD and implements IPC based on shared memory
 *  and Mailbox IP of the SoC
 *
 *  The IPC Driver implements interfaces specified in MCAL_CDD_IPC_Design
 *  document.<br>
 *
 *  Provides methods to transport N bytes of data across core's in TDAxx class
 *  of processors. Some of the abilities of this driver are
 *
 *  - Send N bytes of data to other processor (s)
 *  - Received N bytes of data from other processor (s)
 *  - Announce Services offered by core hosting AUTOSAR to all processor (s)
 *      - Via transmission N bytes of data
 *
 *
 *  \version 01.00.00
 *
 *
 *  \sa MCAL_IPC_CFG
 *  \sa MCAL_IPC_IRQ
 *  @{
 */

/*
 * Below are the global requirements which are met by this IPC CDD
 * driver
 */

/*
 * Design : DES_CDD_IPC_002, DES_CDD_IPC_003, DES_CDD_IPC_004, DES_CDD_IPC_018,
 *
 */
/*
 * Requirements : MCAL-964, MCAL-3699, MCAL-3697, MCAL-981
 */

#ifndef CDD_IPC_H_
#define CDD_IPC_H_


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "Std_Types.h"
#include "Cdd_IpcCfg.h"



#ifdef __cplusplus
extern "C"
{
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *  \name CDD IPC Driver Module SW Version Info
 *
 *  Defines for CDD IPC Driver AUTOSAR version used for compatibility checks.
 *  Expected to change with each each change in IPC implementation
 *  @{
 */
/** \brief Driver Implementation Major Version */
#define CDD_IPC_SW_MAJOR_VERSION            (1U)
/** \brief Driver Implementation Minor Version */
#define CDD_IPC_SW_MINOR_VERSION            (3U)
/** \brief Driver Implementation patch Version */
#define CDD_IPC_SW_PATCH_VERSION            (5U)
/* @} */

/**
 *  \name CDD IPC Driver Module AUTOSAR Version Info
 *
 *  Defines for CDD Driver AUTOSAR version used for compatibility checks
 *  @{
 */
/** \brief AUTOSAR Major version specification implemented by CDD Driver */
#define CDD_IPC_AR_RELEASE_MAJOR_VERSION        (4U)
/** \brief AUTOSAR Minor  version specification implemented by CDD Driver */
#define CDD_IPC_AR_RELEASE_MINOR_VERSION        (3U)
/** \brief AUTOSAR Patch version specification implemented by CDD Driver */
#define CDD_IPC_AR_RELEASE_REVISION_VERSION     (1U)
/* @} */

/**
 *  \name CDD IPC Driver Module, AUTOSAR Version Info
 *
 *  Defines for CDD IPC Driver AUTOSAR version used for compatibility checks
 *  @{
 */
/*
 * Design : DES_CDD_IPC_019
 */
/*
 * Requirements : MCAL-3720, MCAL-3721, MCAL-3722, MCAL-3723, MCAL-3727,
 *                MCAL-3729, MCAL-3734, MCAL-3740, MCAL-3756
 */
/** \brief CDD Module ID */
#define CDD_IPC_MODULE_ID                       ((uint16) 255U)
/** \brief Texas Instruments Vendor ID */
#define CDD_IPC_VENDOR_ID                       ((uint16) 44U)
/** \brief IPC Instance ID */
#define CDD_IPC_INSTANCE_ID                     ((uint8) 0U)

/* @} */


/**
 *  \name CDD API Service ID
 *  @{
 */

/*
 * Design : DES_CDD_IPC_027, DES_CDD_IPC_028, DES_CDD_IPC_029, DES_CDD_IPC_030,
 *          DES_CDD_IPC_031, DES_CDD_IPC_032, DES_CDD_IPC_033, DES_CDD_IPC_039
 */
/*
 * Requirements : MCAL-3708, MCAL-3688, MCAL-3717 MCAL-3724, MCAL-3730,
 *                  MCAL-3739, MCAL-3736, MCAL-4068
 */

/** \brief API Service ID for get version info */
#define CDD_IPC_SID_GETVERSIONINFO      (0x01U)
/** \brief API Service ID for initialization */
#define CDD_IPC_SID_INIT                (0x02U)
/** \brief API Service ID to send message to remote core */
#define CDD_IPC_SID_SEND                (0x03U)
/** \brief API Service ID to receive message from remote core */
#define CDD_IPC_SID_RECEIVE             (0x04U)
/** \brief API Service ID to announce message all remote core */
#define CDD_IPC_SID_ANNOUNCE            (0x05U)
/** \brief API Service ID for ISR */
#define CDD_IPC_SID_INTERNAL_ISR_ID     (0x06U)
/** \brief API Service ID for register read back */
#define CDD_IPC_SID_REG_READBACK        (0x07U)
/** \brief API Service ID for De initialization */
#define CDD_IPC_SID_DEINIT              (0x08U)
/** \brief API Service ID to receive control message from remote core */
#define CDD_IPC_SID_CTRL_RECEIVE        (0x09U)
/** \brief API Service ID to determine if module is initialized */
#define CDD_IPC_SID_IS_INIT_DONE        (0x0AU)
/** \brief API Service ID to determine the maximum message size configured */
#define CDD_IPC_SID_GET_MAX_MSG_SIZE    (0x0BU)

/* @} */

/**
 *  \name CDD IPC Error Codes
 *  @{
 */
/*
 * Design : DES_CDD_IPC_019
 */
/*
 * Requirements : MCAL-3720, MCAL-3721, MCAL-3722, MCAL-3723, MCAL-3727,
 *                  MCAL-3729, MCAL-3734, MCAL-3740, MCAL-3756
 */
/** \brief No errors */
#define CDD_IPC_E_OK                            (0x00U)
/** \brief Error code indicating initialization failure */
#define CDD_IPC_E_INIT_FAILED                   (0x01U)
/** \brief Error code indicating the IPC is uninitialized */
#define CDD_IPC_E_UNINIT                        (0x02U)
/** \brief Error code indicating driver is un-initialized */
#define CDD_IPC_E_PARAM_POINTER                 (0x03U)
/** \brief Error code indicating IPC has already been initialized */
#define CDD_IPC_E_ALREADY_INITIALIZED           (0x04U)
/** \brief Error code indicating wrong configuration */
#define CDD_IPC_E_INVALID_CONFIG                (0x05U)
/** \brief Error code indicating sending of an message failed */
#define CDD_IPC_E_SEND                          (0x06U)
/** \brief Error code indicating reception of invalid message */
#define CDD_IPC_E_RECEIVE_RETRY                 (0x07U)
/** \brief Error code indicating feature is not supported */
#define CDD_IPC_E_NOT_SUPPORTED                 (0x08U)

/* @} */

/** \brief IPC maximum possible core ID
 */
#define CDD_IPC_CORE_ID_MAX         (11U)

/** \brief Maximum message length that can be transported
 */
#define CDD_IPC_MAX_MSG_LEN         (496U)

/** \brief Maximum length of control message
 */
#define CDD_IPC_MAX_CTRL_MSG_LEN    (32U)

/** \brief Maximum number of times notify via mailbox is attempted
 *
 *      In cases where the remote core is not processing mailbox notification,
 *      the driver would attempt to notify multiple times.
 */
#define CDD_IPC_MAX_RETRY_NOTIFY    (2U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/**
 *  \addtogroup MCAL_CDD_IPC_CFG CDD_IPC Configuration
 *  @{
 */

/**
 *  \brief Defines processor identifiers
 *          Core on which MCAL/AUTOSAR is hosted and other cores with which IPC
 *          is desired.
 *  @{
 */
/*
 * Design : DES_CDD_IPC_006, DES_CDD_IPC_022
 */
/*
 * Requirements : MCAL-3668, MCAL-3669, MCAL-3670, MCAL-3671
 */
typedef struct Cdd_IpcMpType_s
{
    uint32  ownProcID;
    /**< Defines processor ID on which MCAL/AUTOSAR is being hosted */
    uint32  numProcs;
    /**< Number of remote processor which with IPC is desired */
    uint32  remoteProcID[CDD_IPC_CORE_ID_MAX];
    /**< Remote processor identifiers */
    uint32  reserved;
    /**< Future use if any */

} Cdd_IpcMpType;
/* @} */

/**
 *  \brief Defines Shared Memories for VRING and VRING OBJECT
 *          VRING is the shared memory between cores and VRING OBJECT is used
 *          implement queue. Please refer design/user guide for details.
 *  @{
 */
/*
 * Design : DES_CDD_IPC_006, DES_CDD_IPC_008, DES_CDD_IPC_023
 */
/*
 * Requirements : MCAL-3672, MCAL-3673, MCAL-3674, MCAL-3675, MCAL-3676
 */
typedef struct Cdd_IpcVertIoType_s
{
    void    *vertIoRingAddr;
    /**< Defines address that shall be shared between cores */
    uint32  vertIoRingSize;
    /**< Size of the shared memory */
    uint32  vertIoObjSize;
    /**< Size of the vertio Object, used for vertIoRing */
    uint32  reserved;
    /**< Future use if any */

} Cdd_IpcVertIoType;
/* @} */

/**
 *  \brief Defines logical communication channel between cores
 *  @{
 */
/*
 * Design : DES_CDD_IPC_006, DES_CDD_IPC_024
 */
/*
 * Requirements : MCAL-3677, MCAL-3678, MCAL-3679, MCAL-3680, MCAL-3681,
 *                MCAL-3682, MCAL-3755
 */
typedef struct Cdd_IpcChannelType_s
{
    uint32  id;
    /**< Unique identifiers for a channel */
    uint32  localEp;
    /**< Local End Point identifier, on which MCAL/AUTOSAR is hosted */
    uint32  remoteEp;
    /**< Remote End Point identifier, on remote cores */
    uint32  remoteProcId;
    /**< Remote Processor Identifier */
    uint32  numMsgQueued;
    /**< Maximum depth of the queue, that holds received messages */
    uint32  maxMsgSize;
    /**< Maximum size of the message that could be received */
    uint32  reserved;
    /**< Future use if any */

} Cdd_IpcChannelType;
/* @} */

/**
 *  \brief CDD IPC Configuration type
 *  @{
 */
/*
 * Design : DES_CDD_IPC_025,
 */
/*
 * Requirements : MCAL-3702, MCAL-3705
 */
typedef struct Cdd_IpcConfigType_s
{
    Cdd_IpcMpType       coreIds;
    /**< Core identifier configurations */
    Cdd_IpcVertIoType   vertIoCfg;
    /**< VertIO configurations */
    uint32              channelCount;
    /**<  Number of channels configured  */
    P2CONST(Cdd_IpcChannelType, AUTOMATIC, CDD_IPC_CONST) pChCfg;
    /**< Pointer to array of channel conditions */

    uint32              reserved;
    /**< Reserved field */
} Cdd_IpcConfigType;

/* @} */

/**
 *  \brief
 *  @{
 */
/*
 * Design :
 */
/*
 * Requirements :
 */
typedef struct
{
    uint32  numRegisters;
    /**< Will specify number of registers values provided */
    uint32  regValues[CDD_IPC_CORE_ID_MAX];
    /**< Values of critical registers that's read and provided */
    uint32  reserved;
    /**< Reserved field */
} Cdd_IpcRegRbValues;

/* @} */

/**
 * \brief Channel RP Msg buffer type
 *          Used to hold the received buffer, before apps can pick it up
 */
typedef struct Cdd_IpcChannelBufType_s
{
    uint8 *pBuf;
    /**< Pointer to buffer */
    uint32  bufSize;
    /**< Buffer size, expressed in bytes */
}Cdd_IpcChannelBufType;

/* @} */
/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief Service for getting CDD version.
 *
 *  \verbatim
 *  Service name        : Cdd_IpcGetVersionInfo
 *  Syntax              : void Cdd_IpcGetVersionInfo(Std_VersionInfoType
 *                                                              VersionInfoPtr)
 *  Mode                : User Mode (Non-Privileged Mode)
 *  Service ID[hex]     : CDD_IPC_SID_GETVERSIONINFO
 *  Sync/Async          : Synchronous
 *  Reentrancy          : Non Reentrant
 *  Parameters (in)     : VersionInfoPtr - Pointer to version info element
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : None
 *  Description         : Service for getting CDD version.
 *  \endverbatim
 */
#if (STD_ON == CDD_IPC_VERSION_INFO_API)
FUNC(void, CDD_IPC_CODE) Cdd_IpcGetVersionInfo(
                                        P2VAR(Std_VersionInfoType, AUTOMATIC,
                                        CDD_APP_DATA) VersionInfoPtr);
#endif

/**
 *  \brief Service for CDD Initialization
 *
 *  \verbatim
 *  Service name        : Cdd_IpcInit
 *  Syntax              : Std_ReturnType Cdd_IpcInit(void)
 *  Mode                : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]     : CDD_IPC_SID_INIT
 *  Sync/Async          : Synchronous
 *  Reentrancy          : Non Reentrant
 *  Parameters (in)     : None
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : None
 *  Description         : Service for  CDD Initialization.
 *  \endverbatim
 */
FUNC(void, CDD_IPC_CODE) Cdd_IpcInit(void);

/**
 *  \brief Service for deinitializing CDD
 *
 *  \verbatim
 *  Service name        : Cdd_IpcDeinit
 *  Syntax              : Std_ReturnType Cdd_IpcDeinit(void* ConfigPtr)
 *  Mode                : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]     : CDD_IPC_SID_DEINIT
 *  Sync/Async          : Synchronous
 *  Reentrancy          : Non-Reentrant
 *  Parameters (in)     : ConfigPtr - Not used for now, reserved for future
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : Std_ReturnType
 *  Description         : Service for deinitializing the CDD and change the
 *                          driver state to uninitialized
 *  \endverbatim
 */
#if (STD_ON == CDD_IPC_DEINIT_API)
FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_IpcDeinit(void);
#endif

/**
 *  \brief Service for sending an message to remote cores
 *
 *  \verbatim
 *  Service name        : Cdd_IpcSendMsg
 *  Syntax              : Std_ReturnType Cdd_IpcSendMsg(
 *                                              uint32  chId,
 *                                              void    *pBuf,
 *                                              uint32  bufLen)
 *  Mode                : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]     : CDD_IPC_SID_SEND
 *  Sync/Async          : Synchronous
 *  Reentrancy          : NonReentrant
 *  Parameters (in)     : chId - Communication channel identifier
 *                      : pBuf - non NULL_PTR, that describes the message to be
 *                                  sent
 *                      : bufLen - Length in bytes and cannot exceed
 *                                  CDD_IPC_MAX_MSG_LEN
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : Std_ReturnType
 *  Description         : This API is used to transport N bytes of data across
 *                          cores.
 *  \endverbatim
 *
 */
FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_IpcSendMsg(
                                    VAR(uint32, AUTOMATIC) chId,
                                    P2CONST(void, AUTOMATIC, CDD_APP_DATA) pBuf,
                                    VAR(uint32, AUTOMATIC) bufLen);
/**
 *  \brief Service for reception of N bytes of data from remote cores
 *
 *  \verbatim
 *  Service name        : Cdd_IpcReceiveMsg
 *  Syntax              : Std_ReturnType Cdd_IpcReceiveMsg(
 *                                              uint32  chId,
 *                                              void    *pBuf,
 *                                              uint32  bufLen)
 *  Mode                : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]     : CDD_IPC_SID_RECEIVE
 *  Sync/Async          : Synchronous
 *  Reentrancy          : NonReentrant
 *  Parameters (in)     : chId - Communication channel identifier
 *                      : pBuf - non NULL_PTR, that describes the memory space
 *                                  that can hold received message. The length
 *                                  shall be CDD_IPC_MAX_MSG_LEN
 *                      : bufLen - Received message length in bytes and will not
 *                                  exceed CDD_IPC_MAX_MSG_LEN.
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : Std_ReturnType
 *  Description         : This API is used to receive message from remote core
 *                          If there are no messages E_NOT_OK shall be
 *                          returned.
 *
 *  \endverbatim
 *
 */
FUNC(Std_ReturnType, CDD_IPC_CODE)Cdd_IpcReceiveMsg(
                            VAR(uint32, AUTOMATIC) chId,
                            P2VAR(void, AUTOMATIC, CDD_APP_DATA) pBuf,
                            P2VAR(uint32, AUTOMATIC, CDD_APP_DATA) bufLen);

/**
 *  \brief Service for broadcasting capabilities of this core to all other cores
 *
 *  \verbatim
 *  Service name        : Cdd_IpcAnnounce
 *  Syntax              : Std_ReturnType Cdd_IpcAnnounce(
 *                                              void    *pBuf,
 *                                              uint32  bufLen)
 *  Mode                : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]     : CDD_IPC_SID_ANNOUNCE
 *  Sync/Async          : Synchronous
 *  Reentrancy          : NonReentrant
 *  Parameters (in)     : pBuf - non NULL_PTR, that describes the message to be
 *                                  sent.
 *                      : bufLen - Length in bytes and cannot exceed
 *                                  CDD_IPC_MAX_MSG_LEN
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : Std_ReturnType
 *  Description         : This API is used to announce the capability of this
 *                          core to all other cores.
 *  \endverbatim
 *
 */
#if (STD_ON == CDD_IPC_ANNOUNCE_API)
FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_IpcAnnounce(
                                    P2CONST(char, AUTOMATIC, CDD_APP_DATA) pBuf,
                                    VAR(uint32, AUTOMATIC) chId);
#endif /* CDD_IPC_ANNOUNCE_API */

/**
 *  \brief Service for reception of N bytes of control message from remote cores
 *
 *  \verbatim
 *  Service name        : Cdd_IpcReceiveCtrlMsg
 *  Syntax              : Std_ReturnType Cdd_IpcReceiveCtrlMsg(
 *                                              uint32  pRemoteProcId,
 *                                              uint32  pRemoteEndPt,
 *                                              void    *pBuf,
 *                                              uint32  *bufLen)
 *  Mode                : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]     : CDD_IPC_SID_CTRL_RECEIVE
 *  Sync/Async          : Synchronous
 *  Reentrancy          : NonReentrant
 *  Parameters (inout)  : pRemoteProcId - Holds the remote processor identifier
 *                                          that iniciated this control message
 *                      : pRemoteEndPt - Holds remote end point number that
 *                                      iniciated this control message
 *                      : pBuf - non NULL_PTR, that describes the memory space
 *                                  that can hold received message. The length
 *                                  shall be CDD_IPC_MAX_MSG_LEN
 *                      : bufLen - Received message length in bytes and will not
 *                                  exceed CDD_IPC_MAX_MSG_LEN.
 *  Parameters (in)     : None
 *  Parameters (out)    : None
 *  Return value        : Std_ReturnType
 *  Description         : This API is used to receive control message from
 *                          remote core. If there are no messages E_NOT_OK
 *                           shall be returned.
 *
 *  \endverbatim
 *
 */
#if (STD_ON == CDD_IPC_ANNOUNCE_API)
FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_IpcReceiveCtrlMsg (
                        P2VAR (unsigned int, AUTOMATIC, CDD_APP_DATA) pRemoteProcId,
                        P2VAR (unsigned int, AUTOMATIC, CDD_APP_DATA) pRemoteEndPt,
                        P2VAR (void, AUTOMATIC, CDD_APP_DATA) pBuf,
                        P2VAR (uint32, AUTOMATIC, CDD_APP_DATA) bufLen);
#endif /* CDD_IPC_ANNOUNCE_API */

/**
 *  \brief Service for reading the configuration registers of the MCAL modules.
 *
 *  \verbatim
 *  Service name        : Cdd_RegisterReadBack
 *  Syntax              : Std_ReturnType Cdd_RegisterReadBack(uint8* mod_name)
 *  Mode                : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]     : None
 *  Sync/Async          : Synchronous
 *  Reentrancy          : Reentrant
 *  Parameters (in)     : None
 *  Parameters (inout)  : pRegArgs - Pointer to structure that would hold values
 *                          of registers read back by this API
 *  Parameters (out)    : None
 *  Return value        : Std_ReturnType
 *  Description         : Service for reading the critical configuration
 *                          registers of the Mailbox/IPC
 *  \endverbatim
 *
 */
#if (STD_ON == CDD_IPC_REGISTER_READBACK_API)
FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_IpcRegisterReadBack(
                P2VAR(Cdd_IpcRegRbValues, AUTOMATIC, CDD_APP_DATA) pRegArgs);
#endif

/**
 *  \brief Service for checking if IPC module is initialized.
 *
 *  \verbatim
 *  Service name        : Cdd_IpcIsInitDone
 *  Syntax              : boolean Cdd_IpcIsInitDone(void)
 *  Mode                : User Mode (Non-Privileged Mode)
 *  Service ID[hex]     : CDD_IPC_SID_IS_INIT_DONE
 *  Sync/Async          : Synchronous
 *  Reentrancy          : Reentrant
 *  Parameters (in)     : None
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : boolean
 *  Description         : Returns TRUE if Cdd_ipcInit is completed else FALSE
 *  \endverbatim
 *
 */
#if (STD_ON == CDD_IPC_IS_INIT_DONE_API)
FUNC(boolean, CDD_IPC_CODE) Cdd_IpcIsInitDone(void);
#endif

/**
 *  \brief Service for checking if IPC module is initialized.
 *
 *  \verbatim
 *  Service name        : Cdd_IpcGetMaxMsgSize
 *  Syntax              : uint32 Cdd_IpcGetMaxMsgSize(uint32 chId)
 *  Mode                : User Mode (Non-Privileged Mode)
 *  Service ID[hex]     : CDD_IPC_SID_GET_MAX_MSG_SIZE
 *  Sync/Async          : Synchronous
 *  Reentrancy          : Reentrant
 *  Parameters (in)     : chId - Communication channel identifier
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : uint32
 *  Description         : Returns max msg size for the specified channel
 *  \endverbatim
 *
 */
#if (STD_ON == CDD_IPC_GET_MAX_MSG_SIZE_API)
FUNC(uint32, CDD_IPC_CODE) Cdd_IpcGetMaxMsgSize(VAR(uint32, AUTOMATIC) chId);
#endif

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef CDD_IPC_H_ */

/* @} */
