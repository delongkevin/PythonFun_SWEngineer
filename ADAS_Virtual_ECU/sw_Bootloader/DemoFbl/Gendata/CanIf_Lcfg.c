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
 *            Module: CanIf
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Lcfg.c
 *   Generation Time: 2024-11-25 15:00:22
 *           Project: DemoFbl - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#define CANIF_LCFG_SOURCE

/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/ 

#include "CanIf_Cfg.h"

 /*  CanTp Header Files  */ 
#include "CanTp_Cfg.h"
#include "CanTp_Cbk.h"
 /*  CDD Header Files  */ 
#include "CanIf_Cdd.h"


#define CANIF_START_SEC_APPL_CODE

#include "CanIf_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  \var  Prototypes of callback functions
**********************************************************************************************************************/

/** 
  \brief  Tx confirmation functions.
*/



/** 
  \brief  Rx indication functions.
*/





#define CANIF_STOP_SEC_APPL_CODE

#include "CanIf_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  ComStackLib
**********************************************************************************************************************/
/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
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
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr = FblCw_ControllerBusOff;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CanIfCtrlId2MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CanIfCtrlId2MappedTxBuffersConfig
  \brief  CAN controller configuration - mapped Tx-buffer(s).
  \details
  Element                          Description
  MappedTxBuffersConfigEndIdx      the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
  MappedTxBuffersConfigStartIdx    the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MappedTxBuffersConfigEndIdx                                                                                    MappedTxBuffersConfigStartIdx                                                                                          Referable Keys */
  { /*     0 */                          1u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DemoFBL_Vector_SLP3_d34c962b */,                            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DemoFBL_Vector_SLP3_d34c962b */ }   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DemoFBL_Vector_SLP3_d34c962b] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr = FblCw_ControllerModeIndication;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfig
  \brief  Mailbox table.
  \details
  Element                 Description
  CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst              "First" PDU mapped to mailbox.
  PduIdLast               "Last" PDU mapped to mailbox.
  TxBufferCfg         
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig
  TxBufferHandlingType
  MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CtrlStatesIdx                                                                                    PduIdFirst                           PduIdLast                           TxBufferCfg                                                          TxBufferCfgIdx                                                                              TxBufferHandlingType                     MailBoxType                    Referable Keys */
  { /*     0 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DemoFBL_Vector_SLP3_d34c962b */,         0u  /* Unused, TxPduId 0 */,        0u  /* Unused, TxPduId 1 */, CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIG_TXBUFFERCFGOFMAILBOXCONFIG,                                     0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3b54cc70 */, CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID, CANIF_TxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_DemoFBL_Vector_SLP3_599e8ccc_Tx] */
  { /*     1 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DemoFBL_Vector_SLP3_d34c962b */,         0u  /* RxPduId */          ,        3u  /* RxPduId  */         ,                                 CANIF_NO_TXBUFFERCFGOFMAILBOXCONFIG, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex1 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxBasicCANMailbox }   /* [/ActiveEcuC/Can/CanConfigSet/CN_DemoFBL_Vector_SLP3_36153a3c_Rx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MappedTxBuffersConfig
  \brief  Mapped Tx-buffer(s)
  \details
  Element             Description
  MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_MappedTxBuffersConfigType, CANIF_CONST) CanIf_MappedTxBuffersConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MailBoxConfigIdx                                                                               Referable Keys */
  { /*     0 */               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_DemoFBL_Vector_SLP3_599e8ccc_Tx */ }   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DemoFBL_Vector_SLP3_d34c962b] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxIndicationFct                                           RxIndicationLayout                                                                 Referable Keys */
  { /*     0 */  { (CanIf_SimpleRxIndicationFctType)NULL_PTR }          , CanIf_SimpleRxIndicationLayout    /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [NULL_PTR] */
  { /*     1 */  { (CanIf_SimpleRxIndicationFctType)CanTp_RxIndication }, CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ }   /* [CanTp_RxIndication] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfig
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
  MsgType                   Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxPduCanId                                                                                  RxPduMask                                                                     UpperPduId                                      RxIndicationFctListIdx                            RxPduDlc  MsgType                         Comment                                                                                         Referable Keys */
  { /*     0 */ 0x98DBFEF2u  /* Functional_CAN_FD_Tp_oDemoFBL_Fca_SLP5_1bf053ab_Rx, only FD-PDU */        , 0xDFFFFFFFu  /* Functional_CAN_FD_Tp_oDemoFBL_Fca_SLP5_1bf053ab_Rx */       , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_d1898b63    ,                     1u  /* CanTp_RxIndication */,      64u, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: Functional_CAN_FD_Tp_oDemoFBL_Fca_SLP5_1bf053ab_Rx, CanId: 0x18dbfef2]        */  /* [CanIfConf_CanIfRxPduCfg_Functional_CAN_FD_Tp_oDemoFBL_Fca_SLP5_1bf053ab_Rx] */
  { /*     1 */ 0x98DBFEF1u  /* Functional_CAN_20_Tp_oDemoFBL_Vector_SLP3_1fcf9f08_Rx, only 2.0-PDU */    , 0x9FFFFFFFu  /* Functional_CAN_20_Tp_oDemoFBL_Vector_SLP3_1fcf9f08_Rx */    , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_b0bf513f    ,                     1u  /* CanTp_RxIndication */,       8u, CANIF_MSG_TYPE_NO_FD_CAN },  /* [PDU: Functional_CAN_20_Tp_oDemoFBL_Vector_SLP3_1fcf9f08_Rx, CanId: 0x18dbfef1]     */  /* [CanIfConf_CanIfRxPduCfg_Functional_CAN_20_Tp_oDemoFBL_Vector_SLP3_1fcf9f08_Rx] */
  { /*     2 */ 0x98DAA0F2u  /* Demo_0_CAN_FD_Request_Tp_oDemoFBL_Fca_SLP5_68bd9369_Rx, only FD-PDU */    , 0x9FFFFFFFu  /* Demo_0_CAN_FD_Request_Tp_oDemoFBL_Fca_SLP5_68bd9369_Rx */   , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_2987a92d,                     1u  /* CanTp_RxIndication */,      64u, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: Demo_0_CAN_FD_Request_Tp_oDemoFBL_Fca_SLP5_68bd9369_Rx, CanId: 0x18daa0f2]    */  /* [CanIfConf_CanIfRxPduCfg_Demo_0_CAN_FD_Request_Tp_oDemoFBL_Fca_SLP5_68bd9369_Rx] */
  { /*     3 */ 0x98DAA0F1u  /* Demo_0_CAN_20_Request_Tp_oDemoFBL_Vector_SLP3_cac44394_Rx, only 2.0-PDU */, 0x9FFFFFFFu  /* Demo_0_CAN_20_Request_Tp_oDemoFBL_Vector_SLP3_cac44394_Rx */, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a624ba96    ,                     1u  /* CanTp_RxIndication */,       8u, CANIF_MSG_TYPE_NO_FD_CAN }   /* [PDU: Demo_0_CAN_20_Request_Tp_oDemoFBL_Vector_SLP3_cac44394_Rx, CanId: 0x18daa0f1] */  /* [CanIfConf_CanIfRxPduCfg_Demo_0_CAN_20_Request_Tp_oDemoFBL_Vector_SLP3_cac44394_Rx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueConfig
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE
  \details
  Element                                             Description
  TxBufferPrioByCanIdBaseIdx                          the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase
  TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx      the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusLength      the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx    the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxBufferPrioByCanIdBaseIdx                                                      TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx                                                      TxBufferPrioByCanIdByteQueueMappedTxPdusLength                                                      TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx                                                            Referable Keys */
  { /*     0 */                         0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3b54cc70 */,                                             2u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3b54cc70 */,                                             2u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3b54cc70 */,                                               0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3b54cc70 */ }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3b54cc70] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE: Mapped Tx-PDUs
  \details
  Element           Description
  TxPduConfigIdx    the index of the 1:1 relation pointing to CanIf_TxPduConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxPduConfigIdx                                                                                                         Referable Keys */
  { /*     0 */             0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx */    },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3b54cc70] */
  { /*     1 */             1u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx */ }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3b54cc70] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxConfirmationFctList                      Referable Keys */
  /*     0 */ (CanIf_TxConfirmationFctType)NULL_PTR ,  /* [NULL_PTR] */
  /*     1 */ CanTp_TxConfirmation                     /* [CanTp_TxConfirmation] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfig
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle-Id (8bit / 16bit).
  IsTxPduTruncation           TRUE: Truncation of Tx-PDU is enabled, FALSE: Truncation of Tx-PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx-PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CanId        UpperLayerTxPduId                               IsTxPduTruncation  CtrlStatesIdx                                                                                    MailBoxConfigIdx                                                                         TxConfirmationFctListIdx                              TxPduLength        Comment                                                                       Referable Keys */
  { /*     0 */ 0xD8DAF2A0u, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_2987a92d    , TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DemoFBL_Vector_SLP3_d34c962b */,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_DemoFBL_Vector_SLP3_599e8ccc_Tx */,                       1u  /* CanTp_TxConfirmation */,         64u },  /* [PDU: Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx]    */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx] */
  { /*     1 */ 0x98DAF1A0u, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_a624ba96, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DemoFBL_Vector_SLP3_d34c962b */,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_DemoFBL_Vector_SLP3_599e8ccc_Tx */,                       1u  /* CanTp_TxConfirmation */,          8u }   /* [PDU: Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduQueueIndex
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduQueueIndex
  \brief  Indirection table: Tx-PDU handle-Id to corresponding Tx buffer handle-Id. NOTE: Only BasicCAN Tx-PDUs have a valid indirection into the Tx buffer.
  \details
  Element                          Description
  TxQueue                      
  TxQueueIdx                       the index of the 0:1 relation pointing to CanIf_TxQueue
  TxQueueIndex2DataStartStopIdx    the index of the 0:1 relation pointing to CanIf_TxQueueIndex2DataStartStop
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxQueue                                 TxQueueIdx                                                                                                   TxQueueIndex2DataStartStopIdx                                                                                                         Comment                                                                                                 Referable Keys */
  { /*     0 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,         0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx */   ,                            0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx */    },  /* [Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx, BasicCAN TxPdu with Tx-buffer]    */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DemoFBL_Vector_SLP3_d34c962b] */
  { /*     1 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,         1u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx */,                            1u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx */ }   /* [Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx, BasicCAN TxPdu with Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DemoFBL_Vector_SLP3_d34c962b] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueueIndex2DataStartStop
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueueIndex2DataStartStop
  \details
  Element                Description
  TxQueueDataEndIdx      the end index of the 0:n relation pointing to CanIf_TxQueueData
  TxQueueDataLength      the number of relations pointing to CanIf_TxQueueData
  TxQueueDataStartIdx    the start index of the 0:n relation pointing to CanIf_TxQueueData
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxQueueIndex2DataStartStopType, CANIF_CONST) CanIf_TxQueueIndex2DataStartStop[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxQueueDataEndIdx                                                                                                   TxQueueDataLength                                                                                                   TxQueueDataStartIdx                                                                                                         Comment                                                                          Referable Keys */
  { /*     0 */               64u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx */   ,               64u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx */   ,                  0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx */    },  /* [Tx-PDU: Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx]    */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx] */
  { /*     1 */               72u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx */,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx */,                 64u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx */ }   /* [Tx-PDU: Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element     Description
  CtrlMode    Controller mode.
  PduMode     PDU mode state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DemoFBL_Vector_SLP3_d34c962b] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBase
  \brief  Variable declaration - Tx-buffer: PRIO_BY_CANID as byte/bit-queue. Stores at least the QueueCounter.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_TxBufferPrioByCanIdBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBase;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3b54cc70] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueue
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueue
  \brief  Variable declaration - Tx byte queue.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx] */
  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueueData
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueueData
  \brief  Variable declaration - Tx queue data.
*/ 
#define CANIF_START_SEC_VAR_FAST_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_TxQueueDataUType, CANIF_VAR_NOINIT_FAST) CanIf_TxQueueData;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx] */
  /*    63 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx] */
  /*    64 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx] */
  /*    71 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx] */

#define CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */




