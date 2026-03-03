/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: CanNm
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanNm_Cfg.c
 *   Generation Time: 2024-02-13 13:07:46
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define CANNM_CFG_SOURCE

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2_0779 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "CanNm_Cfg.h"

#include "PduR_Cfg.h"

#include "CanIf_Cfg.h"

#include "Nm.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanNm_ChannelConfig
**********************************************************************************************************************/
/** 
  \var    CanNm_ChannelConfig
  \details
  Element                     Description
  RepeatMessageTime           Timeout for Repeat Message State [ms].
  TimeoutTime                 Timeout for the NM messages [ms].
  ActiveWakeUpBitEnabled      Determines if Active WUP Bit Handling is active or not
  BusLoadReductionActive      Determines if bus load reduction for the respective NM channel is active or not.
  ComControlEnabled           Determines if Com Control is active or not
  NodeIdEnabled               Determines if Node Ids are enabled or not
  ChannelId                   Channel ID configured for the respective instance of the NM.
  ImmediateNmCycleTime        Fast NM PDU Transmission Time during WUP
  ImmediateNmTransmissions    Number of fast NM PDU Transmissions during WUP
  MsgCycleTime                Period of a NM message [ms]. It determines the periodic rate in the periodic transmission mode.
  MsgTimeoutTime              Transmission Timeout [ms] of NM message. If there is no transmission confirmation by the CAN Interface within this timeout, the CAN NM module shall give an error notification.
  PduCbvPosition              Control Bit Vector Position in the PDU
  PduNidPosition              Node ID Position in the PDU
  RemoteSleepIndTime          Timeout for Remote Sleep Indication [ms].
  WaitBusSleepTime            Timeout for bus calm down phase [ms].
*/ 
#define CANNM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanNm_ChannelConfigType, CANNM_CONST) CanNm_ChannelConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RepeatMessageTime  TimeoutTime  ActiveWakeUpBitEnabled  BusLoadReductionActive  ComControlEnabled  NodeIdEnabled  ChannelId                                   ImmediateNmCycleTime  ImmediateNmTransmissions  MsgCycleTime  MsgTimeoutTime  PduCbvPosition    PduNidPosition    RemoteSleepIndTime  WaitBusSleepTime        Referable Keys */
  { /*     0 */              500u,        800u,                   TRUE,                   TRUE,              TRUE,          TRUE, NmConf_NmChannelConfig_CN_FDCAN14_a902658e,                   1u,                       2u,         100u,            50u, CANNM_PDU_BYTE_1, CANNM_PDU_BYTE_0,                 0u,             101u },  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN14_a902658e] */
  { /*     1 */              500u,        800u,                   TRUE,                   TRUE,              TRUE,          TRUE,  NmConf_NmChannelConfig_CN_FDCAN2_28a8fc44,                   1u,                       2u,         100u,            50u, CANNM_PDU_BYTE_1, CANNM_PDU_BYTE_0,                 0u,             101u }   /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN2_28a8fc44] */
};
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_PbChannelConfig
**********************************************************************************************************************/
/** 
  \var    CanNm_PbChannelConfig
  \details
  Element                  Description
  MsgCycleOffset       
  MsgReducedTime       
  NodeId               
  RxMessageDataEndIdx      the end index of the 0:n relation pointing to CanNm_RxMessageData
  RxMessageDataLength      the number of relations pointing to CanNm_RxMessageData
  RxMessageDataStartIdx    the start index of the 0:n relation pointing to CanNm_RxMessageData
  RxMessageData_CBVIdx     the index of the 0:1 relation pointing to CanNm_RxMessageData
  RxMessageData_NIDIdx     the index of the 0:1 relation pointing to CanNm_RxMessageData
  TxMessageDataEndIdx      the end index of the 0:n relation pointing to CanNm_TxMessageData
  TxMessageDataLength      the number of relations pointing to CanNm_TxMessageData
  TxMessageDataStartIdx    the start index of the 0:n relation pointing to CanNm_TxMessageData
  TxMessageData_CBVIdx     the index of the 0:1 relation pointing to CanNm_TxMessageData
  TxMessageData_NIDIdx     the index of the 0:1 relation pointing to CanNm_TxMessageData
  TxPduId              
*/ 
#define CANNM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanNm_PbChannelConfigType, CANNM_CONST) CanNm_PbChannelConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MsgCycleOffset  MsgReducedTime  NodeId  RxMessageDataEndIdx  RxMessageDataLength  RxMessageDataStartIdx  RxMessageData_CBVIdx  RxMessageData_NIDIdx  TxMessageDataEndIdx  TxMessageDataLength  TxMessageDataStartIdx  TxMessageData_CBVIdx  TxMessageData_NIDIdx  TxPduId                                                    Referable Keys */
  { /*     0 */             0u,            60u,    24u,                  2u,                  2u,                    0u,                   1u,                   0u,                  2u,                  2u,                    0u,                   1u,                   0u, CanIfConf_CanIfTxPduCfg_NM_PAM_oFDCAN14_636c02e4_Tx },  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN14_CAN_df03166d] */
  { /*     1 */             0u,            60u,    24u,                  4u,                  2u,                    2u,                   3u,                   2u,                  4u,                  2u,                    2u,                   3u,                   2u,  CanIfConf_CanIfTxPduCfg_NM_PAM_oFDCAN2_28cff7c5_Tx }   /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN2_CAN_70a1f111] */
};
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_SysToNmChInd
**********************************************************************************************************************/
/** 
  \var    CanNm_SysToNmChInd
  \brief  Channel indirection: System Channel handle to NM channel handle
*/ 
#define CANNM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanNm_SysToNmChIndType, CANNM_CONST) CanNm_SysToNmChInd[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     SysToNmChInd  */
  /*     0 */            0u,
  /*     1 */            1u
};
#define CANNM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_CommState
**********************************************************************************************************************/
/** 
  \var    CanNm_CommState
  \brief  Internal state for the application's need for communication.
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_CommStateUType, CANNM_VAR_NOINIT) CanNm_CommState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN14_a902658e] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN2_28a8fc44] */

#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_CoordReadyToSleepState
**********************************************************************************************************************/
/** 
  \var    CanNm_CoordReadyToSleepState
  \brief  State for Rx of Coordinator Sleep Ready Bit:
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_CoordReadyToSleepStateUType, CANNM_VAR_NOINIT) CanNm_CoordReadyToSleepState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN14_a902658e] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN2_28a8fc44] */

#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_ImmediateNmMsgCount
**********************************************************************************************************************/
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_ImmediateNmMsgCountUType, CANNM_VAR_NOINIT) CanNm_ImmediateNmMsgCount;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN14_a902658e] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN2_28a8fc44] */

#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_ModuleInitialized
**********************************************************************************************************************/
#define CANNM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_ModuleInitializedType, CANNM_VAR_ZERO_INIT) CanNm_ModuleInitialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANNM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_MsgConfirmationFlag
**********************************************************************************************************************/
/** 
  \var    CanNm_MsgConfirmationFlag
  \brief  Message Confirmation Flag
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_MsgConfirmationFlagUType, CANNM_VAR_NOINIT) CanNm_MsgConfirmationFlag;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN14_a902658e] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN2_28a8fc44] */

#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_MsgIndicationFlag
**********************************************************************************************************************/
/** 
  \var    CanNm_MsgIndicationFlag
  \brief  Message Indication Flag
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_MsgIndicationFlagUType, CANNM_VAR_NOINIT) CanNm_MsgIndicationFlag;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN14_a902658e] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN2_28a8fc44] */

#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_MsgTimer
**********************************************************************************************************************/
/** 
  \var    CanNm_MsgTimer
  \brief  Timer for NM message transmission.
*/ 
#define CANNM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_MsgTimerUType, CANNM_VAR_NOINIT) CanNm_MsgTimer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN14_a902658e] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN2_28a8fc44] */

#define CANNM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_NetworkRestartFlag
**********************************************************************************************************************/
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_NetworkRestartFlagUType, CANNM_VAR_NOINIT) CanNm_NetworkRestartFlag;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN14_a902658e] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN2_28a8fc44] */

#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_NmState
**********************************************************************************************************************/
/** 
  \var    CanNm_NmState
  \brief  Current state of the state machine
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_NmStateUType, CANNM_VAR_NOINIT) CanNm_NmState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN14_a902658e] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN2_28a8fc44] */

#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_RepeatMsgTimer
**********************************************************************************************************************/
#define CANNM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_RepeatMsgTimerUType, CANNM_VAR_NOINIT) CanNm_RepeatMsgTimer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN14_a902658e] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN2_28a8fc44] */

#define CANNM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_RxMessageData
**********************************************************************************************************************/
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_RxMessageDataType, CANNM_VAR_NOINIT) CanNm_RxMessageData[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN14_CAN_df03166d, /ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN14_CAN_df03166d_NID] */
  /*     1 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN14_CAN_df03166d, /ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN14_CAN_df03166d_CBV] */
  /*     2 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN2_CAN_70a1f111, /ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN2_CAN_70a1f111_NID] */
  /*     3 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN2_CAN_70a1f111, /ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN2_CAN_70a1f111_CBV] */

#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_TimeoutTimer
**********************************************************************************************************************/
/** 
  \var    CanNm_TimeoutTimer
  \brief  Timer for NM Algorithm.
*/ 
#define CANNM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_TimeoutTimerUType, CANNM_VAR_NOINIT) CanNm_TimeoutTimer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN14_a902658e] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN2_28a8fc44] */

#define CANNM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_TxControlState
**********************************************************************************************************************/
/** 
  \var    CanNm_TxControlState
  \brief  Message transmission control state.
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_TxControlStateUType, CANNM_VAR_NOINIT) CanNm_TxControlState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN14_a902658e] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN2_28a8fc44] */

#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_TxControlStateRequest
**********************************************************************************************************************/
/** 
  \var    CanNm_TxControlStateRequest
  \brief  Message transmission control state request.
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_TxControlStateRequestUType, CANNM_VAR_NOINIT) CanNm_TxControlStateRequest;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN14_a902658e] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN2_28a8fc44] */

#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_TxMessageData
**********************************************************************************************************************/
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_TxMessageDataType, CANNM_VAR_NOINIT) CanNm_TxMessageData[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN14_CAN_df03166d, /ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN14_CAN_df03166d_NID] */
  /*     1 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN14_CAN_df03166d, /ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN14_CAN_df03166d_CBV] */
  /*     2 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN2_CAN_70a1f111, /ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN2_CAN_70a1f111_NID] */
  /*     3 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN2_CAN_70a1f111, /ActiveEcuC/CanNm/CanNmGlobalConfig/FDCAN2_CAN_70a1f111_CBV] */

#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_WaitBusSleepTimer
**********************************************************************************************************************/
#define CANNM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanNm_WaitBusSleepTimerUType, CANNM_VAR_NOINIT) CanNm_WaitBusSleepTimer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN14_a902658e] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN2_28a8fc44] */

#define CANNM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  END OF FILE: CanNm_Cfg.c
**********************************************************************************************************************/

