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
 *            Module: Can
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Can_30_Mcan_Lcfg.c
 *   Generation Time: 2024-01-09 11:05:11
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define CAN_30_MCAN_LCFG_SOURCE

/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */

/* -----------------------------------------------------------------------------
    Includes
 ----------------------------------------------------------------------------- */

#include "Can_30_Mcan_Cfg.h"

/* -----------------------------------------------------------------------------
    Hw specific
 ----------------------------------------------------------------------------- */

/* HW specific CT global C file */

/* !HW specific CT global C file */

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
  CONFIGURATION CLASS: LINK
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
  CONFIGURATION CLASS: LINK
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
  Can_30_Mcan_BTP
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_BTP
  \brief  Bit Timing and Prescaler
*/ 
#define CAN_30_MCAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_BTPType, CAN_30_MCAN_CONST) Can_30_Mcan_BTP[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     BTP              Comment */
  /*     0 */  0x000F0601u,  /* [CT_FDCAN2_c5d3d1a7 - CanControllerBaudrateConfig] */
  /*     1 */  0x000F0601u   /* [CT_FDCAN14_90ecad61 - CanControllerBaudrateConfig] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_BufferConfig
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_BufferConfig
  \brief  CAN Buffer Configuration
  \details
  Element    Description
  RXF0C  
  TXBC   
  RXBC   
  RXF1C  
  TXEFC  
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_BufferConfigType, CAN_30_MCAN_CONST) Can_30_Mcan_BufferConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RXF0C        TXBC         RXBC   RXF1C  TXEFC        Comment */
  { /*     0 */ 0x0040000Cu, 0x0001120Cu, 0x00u, 0x00u, 0x00u },  /* [CT_FDCAN2_c5d3d1a7] */
  { /*     1 */ 0x0040000Cu, 0x0001120Cu, 0x00u, 0x00u, 0x00u }   /* [CT_FDCAN14_90ecad61] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_CanEccAggrBaseAddr
**********************************************************************************************************************/
#define CAN_30_MCAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_CanEccAggrBaseAddrType, CAN_30_MCAN_CONST) Can_30_Mcan_CanEccAggrBaseAddr[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CanEccAggrBaseAddr      Comment */
  /*     0 */         0x40700000u,  /* [Base address of M_CAN0_ECC_AGGR] */
  /*     1 */         0x40701000u   /* [Base address of M_CAN1_ECC_AGGR] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_CanIfChannelId
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_CanIfChannelId
  \brief  indirection table Can to CanIf controller ID
*/ 
#define CAN_30_MCAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_CanIfChannelIdType, CAN_30_MCAN_CONST) Can_30_Mcan_CanIfChannelId[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CanIfChannelId      Comment */
  /*     0 */              0u,  /* [CT_FDCAN2_c5d3d1a7] */
  /*     1 */              1u   /* [CT_FDCAN14_90ecad61] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_CanMcanSsBaseAddr
**********************************************************************************************************************/
#define CAN_30_MCAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_CanMcanSsBaseAddrType, CAN_30_MCAN_CONST) Can_30_Mcan_CanMcanSsBaseAddr[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CanMcanSsBaseAddr      Comment */
  /*     0 */        0x40520000u,  /* [Base address of M_CAN0_SS] */
  /*     1 */        0x40560000u   /* [Base address of M_CAN1_SS] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_ControllerConfig
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_ControllerConfig
  \brief  Global configuration for all controllers
  \details
  Element                            Description
  BasisAdr                           CAN channel base address
  CanControllerDefaultBaudrate   
  IsTTCan                            TTCAN channel support
  CanControllerDefaultBaudrateIdx
  MailboxRxBasicEndIdx               the end index of the 0:n relation pointing to Can_30_Mcan_Mailbox
  MailboxRxBasicLength               the number of relations pointing to Can_30_Mcan_Mailbox
  MailboxRxBasicStartIdx             the start index of the 0:n relation pointing to Can_30_Mcan_Mailbox
  MailboxTxBasicEndIdx               the end index of the 0:n relation pointing to Can_30_Mcan_Mailbox
  MailboxTxBasicLength               the number of relations pointing to Can_30_Mcan_Mailbox
  MailboxTxBasicStartIdx             the start index of the 0:n relation pointing to Can_30_Mcan_Mailbox
  RxBasicHwStart                 
  RxBasicHwStop                  
  RxFullHwStart                  
  RxFullHwStop                   
  TxBasicHwStart                 
  TxBasicHwStop                  
  TxFullHwStart                  
  TxFullHwStop                   
  UnusedHwStart                  
  UnusedHwStop                   
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_ControllerConfigType, CAN_30_MCAN_CONST) Can_30_Mcan_ControllerConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BasisAdr     CanControllerDefaultBaudrate  IsTTCan  CanControllerDefaultBaudrateIdx  MailboxRxBasicEndIdx                                                                                                                                             MailboxRxBasicLength                                                                                                                                             MailboxRxBasicStartIdx                                                                                                                                             MailboxTxBasicEndIdx                                                                                                                                             MailboxTxBasicLength                                                                                                                                             MailboxTxBasicStartIdx                                                                                                                                             RxBasicHwStart  RxBasicHwStop  RxFullHwStart  RxFullHwStop  TxBasicHwStart  TxBasicHwStop  TxFullHwStart  TxFullHwStop  UnusedHwStart  UnusedHwStop        Comment                           Referable Keys */
  { /*     0 */ 0x40528000u,                         500u,   FALSE,                              0u,                   2u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */ ,                   1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */ ,                     1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */ ,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */ ,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */ ,                     0u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */ ,             0u,            1u,            0u,           0u,             0u,            1u,            1u,           1u,            0u,           0u },  /* [CT_FDCAN2_c5d3d1a7]  */  /* [/ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7] */
  { /*     1 */ 0x40568000u,                         500u,   FALSE,                              0u,                   4u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                     3u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   3u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                     2u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,             0u,            1u,            0u,           0u,             0u,            1u,            1u,           1u,            0u,           0u }   /* [CT_FDCAN14_90ecad61] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_FBTP
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_FBTP
  \brief  Fast Bit Timing and Prescaler
*/ 
#define CAN_30_MCAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_FBTPType, CAN_30_MCAN_CONST) Can_30_Mcan_FBTP[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     FBTP             Comment */
  /*     0 */  0x00030611u,  /* [CT_FDCAN2_c5d3d1a7 - CanControllerBaudrateConfig] */
  /*     1 */  0x00070200u   /* [CT_FDCAN14_90ecad61 - CanControllerBaudrateConfig] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_GFC
**********************************************************************************************************************/
#define CAN_30_MCAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_GFCType, CAN_30_MCAN_CONST) Can_30_Mcan_GFC[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     GFC        Comment */
  /*     0 */  0x3Fu,  /* [CT_FDCAN2_c5d3d1a7] */
  /*     1 */  0x3Fu   /* [CT_FDCAN14_90ecad61] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_InitObjectBaudrate
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_InitObjectBaudrate
  \brief  baudrates ('InitStruct' as index)
*/ 
#define CAN_30_MCAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_InitObjectBaudrateType, CAN_30_MCAN_CONST) Can_30_Mcan_InitObjectBaudrate[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectBaudrate      Comment */
  /*     0 */                500u,  /* [CT_FDCAN2_c5d3d1a7 - CanControllerBaudrateConfig] */
  /*     1 */                500u   /* [CT_FDCAN14_90ecad61 - CanControllerBaudrateConfig] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_InitObjectFdBrsConfig
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_InitObjectFdBrsConfig
  \brief  FD config ('BaudrateObject' as index)
*/ 
#define CAN_30_MCAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_InitObjectFdBrsConfigType, CAN_30_MCAN_CONST) Can_30_Mcan_InitObjectFdBrsConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectFdBrsConfig                      */
  /*     0 */  CAN_30_MCAN_FD_RXTX_INITOBJECTFDBRSCONFIG,
  /*     1 */  CAN_30_MCAN_FD_RXTX_INITOBJECTFDBRSCONFIG
};
#define CAN_30_MCAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_InitObjectStartIndex
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_InitObjectStartIndex
  \brief  Start index of 'InitStruct' / baudratesets (controllers as index)
*/ 
#define CAN_30_MCAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_InitObjectStartIndexType, CAN_30_MCAN_CONST) Can_30_Mcan_InitObjectStartIndex[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectStartIndex      Comment */
  /*     0 */                    0u,  /* [CT_FDCAN2_c5d3d1a7] */
  /*     1 */                    1u,  /* [CT_FDCAN14_90ecad61] */
  /*     2 */                    2u   /* [stop index] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_Mailbox
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_Mailbox
  \brief  mailbox configuration (over all controllers)
  \details
  Element                Description
  ActiveSendObject   
  ControllerConfigIdx    the index of the 1:1 relation pointing to Can_30_Mcan_ControllerConfig
  FdPadding          
  HwHandle           
  IDValue            
  MailboxSize        
  MailboxType        
  MaxDataLen         
  MemorySectionsIndex
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_MailboxType, CAN_30_MCAN_CONST) Can_30_Mcan_Mailbox[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ActiveSendObject  ControllerConfigIdx                                                          FdPadding  HwHandle  IDValue  MailboxSize  MailboxType                                        MaxDataLen  MemorySectionsIndex        Comment                              Referable Keys */
  { /*     0 */               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7 */ ,        0u,       0u,   0x00u,          1u, CAN_30_MCAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 64u },  /* [CN_FDCAN2_28a8fc44_Tx]  */  /* [/ActiveEcuC/Can/CanConfigSet/CN_FDCAN2_28a8fc44_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7, TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     1 */               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7 */ ,        0u,       0u,   0x00u,         64u, CAN_30_MCAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 32u },  /* [CN_FDCAN2_4c0547f7_Rx]  */  /* [/ActiveEcuC/Can/CanConfigSet/CN_FDCAN2_4c0547f7_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     2 */               1u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61 */,        0u,       0u,   0x00u,          1u, CAN_30_MCAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 64u },  /* [CN_FDCAN14_a902658e_Tx] */  /* [/ActiveEcuC/Can/CanConfigSet/CN_FDCAN14_a902658e_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61, TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     3 */               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61 */,        0u,       0u,   0x00u,         64u, CAN_30_MCAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 64u }   /* [CN_FDCAN14_525e7c5e_Rx] */  /* [/ActiveEcuC/Can/CanConfigSet/CN_FDCAN14_525e7c5e_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_MemorySectionInfo
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_MemorySectionInfo
  \brief  Memory section description
  \details
  Element               Description
  MemorySectionStart
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_MemorySectionInfoType, CAN_30_MCAN_CONST) Can_30_Mcan_MemorySectionInfo[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MemorySectionStart        Comment */
  { /*     0 */                 0u },  /* [MemorySection: TxBuffer_CT_FDCAN2_c5d3d1a7] */
  { /*     1 */                32u }   /* [MemorySection: TxBuffer_CT_FDCAN14_90ecad61] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_MemorySectionObjects
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_MemorySectionObjects
  \brief  Memory section objects description
  \details
  Element           Description
  HwHandle      
  MailboxElement
  MailboxHandle 
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_MemorySectionObjectsType, CAN_30_MCAN_CONST) Can_30_Mcan_MemorySectionObjects[64] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    HwHandle  MailboxElement  MailboxHandle        Comment */
  { /*     0 */       0u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - CN_FDCAN2_28a8fc44_Tx] */
  { /*     1 */       1u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*     2 */       2u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*     3 */       3u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*     4 */       4u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*     5 */       5u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*     6 */       6u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*     7 */       7u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*     8 */       8u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*     9 */       9u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    10 */      10u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    11 */      11u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    12 */      12u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    13 */      13u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    14 */      14u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    15 */      15u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    16 */      16u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    17 */      17u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    18 */      18u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    19 */      19u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    20 */      20u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    21 */      21u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    22 */      22u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    23 */      23u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    24 */      24u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    25 */      25u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    26 */      26u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    27 */      27u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    28 */      28u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    29 */      29u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    30 */      30u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    31 */      31u,             0u,            0u },  /* [TxBuffer_CT_FDCAN2_c5d3d1a7 - Reserved] */
  { /*    32 */       0u,             0u,            2u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - CN_FDCAN14_a902658e_Tx] */
  { /*    33 */       1u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    34 */       2u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    35 */       3u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    36 */       4u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    37 */       5u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    38 */       6u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    39 */       7u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    40 */       8u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    41 */       9u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    42 */      10u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    43 */      11u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    44 */      12u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    45 */      13u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    46 */      14u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    47 */      15u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    48 */      16u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    49 */      17u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
    /* Index    HwHandle  MailboxElement  MailboxHandle        Comment */
  { /*    50 */      18u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    51 */      19u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    52 */      20u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    53 */      21u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    54 */      22u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    55 */      23u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    56 */      24u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    57 */      25u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    58 */      26u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    59 */      27u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    60 */      28u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    61 */      29u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    62 */      30u,             0u,            0u },  /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
  { /*    63 */      31u,             0u,            0u }   /* [TxBuffer_CT_FDCAN14_90ecad61 - Reserved] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_SIDFC
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_SIDFC
  \brief  Standard ID filter configuration
  \details
  Element          Description
  FLSSA            Filter List Standard Start Address
  LSS              List size standard
  SIDFEEndIdx      the end index of the 0:n relation pointing to Can_30_Mcan_SIDFE
  SIDFEStartIdx    the start index of the 0:n relation pointing to Can_30_Mcan_SIDFE
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_SIDFCType, CAN_30_MCAN_CONST) Can_30_Mcan_SIDFC[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FLSSA  LSS    SIDFEEndIdx                                                          SIDFEStartIdx                                                                Comment */
  { /*     0 */ 0x00u, 0x01u,          1u  /* /ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7 */ ,            0u  /* /ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7 */  },  /* [CT_FDCAN2_c5d3d1a7] */
  { /*     1 */ 0x00u, 0x01u,          2u  /* /ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61 */,            1u  /* /ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61 */ }   /* [CT_FDCAN14_90ecad61] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_SIDFE
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_SIDFE
  \brief  Standard ID filters
*/ 
#define CAN_30_MCAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_SIDFEType, CAN_30_MCAN_CONST) Can_30_Mcan_SIDFE[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     SIDFE                                   Comment                      Referable Keys */
  /*     0 */  0x88000000u  /*  I: 0 S0 FIFO_0 */,  /* [CT_FDCAN2_c5d3d1a7]  */  /* [/ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7] */
  /*     1 */  0x88000000u  /*  I: 0 S0 FIFO_0 */   /* [CT_FDCAN14_90ecad61] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_ShmAdr
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_ShmAdr
  \brief  CAN Shared Message RAM configuration
  \details
  Element     Description
  RXBA        RX Buffer Address
  RXF0A       RX FIFO0 Address
  RXF1A       RX FIFO1 Address
  SIDFA       Standard Filters Address
  StartAdr    Start address of the shared memory area
  StopAdr     Stop address of the shared memory area
  TXBA        TX Buffer address
  TXEFA       TX Event FIFO address
  XIDFA       Extended Filters Address
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_ShmAdrType, CAN_30_MCAN_CONST) Can_30_Mcan_ShmAdr[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RXBA                           RXF0A                             RXF1A                          SIDFA                          StartAdr     StopAdr      TXBA                            TXEFA                          XIDFA                                Comment */
  { /*     0 */ 0x40500000u  /* Size[B]: 0 */, 0x4050000Cu  /* Size[B]: 4608 */, 0x40500000u  /* Size[B]: 0 */, 0x40500000u  /* Size[B]: 4 */, 0x40500000u, 0x40501255u, 0x4050120Cu  /* Size[B]: 72 */, 0x40500000u  /* Size[B]: 0 */, 0x40500004u  /* Size[B]: 8 */ },  /* [CT_FDCAN2_c5d3d1a7] */
  { /*     1 */ 0x40540000u  /* Size[B]: 0 */, 0x4054000Cu  /* Size[B]: 4608 */, 0x40540000u  /* Size[B]: 0 */, 0x40540000u  /* Size[B]: 4 */, 0x40540000u, 0x40541255u, 0x4054120Cu  /* Size[B]: 72 */, 0x40540000u  /* Size[B]: 0 */, 0x40540004u  /* Size[B]: 8 */ }   /* [CT_FDCAN14_90ecad61] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_ShmElementSize
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_ShmElementSize
  \brief  data buffer size in case of CAN_FD Full
  \details
  Element    Description
  F0DS   
  F1DS   
  RBDS   
  TBDS   
  TEFBDS 
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_ShmElementSizeType, CAN_30_MCAN_CONST) Can_30_Mcan_ShmElementSize[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    F0DS                  F1DS                  RBDS                 TBDS                  TEFBDS                        Comment */
  { /*     0 */ 0x07u  /* F0DS 64 */, 0x07u  /* F1DS 64 */, 0x00u  /* RBDS 8 */, 0x07u  /* TBDS 64 */,  0x00u  /* EFTBDS 8 */ },  /* [CT_FDCAN2_c5d3d1a7] */
  { /*     1 */ 0x07u  /* F0DS 64 */, 0x07u  /* F1DS 64 */, 0x00u  /* RBDS 8 */, 0x07u  /* TBDS 64 */,  0x00u  /* EFTBDS 8 */ }   /* [CT_FDCAN14_90ecad61] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_TDCR
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_TDCR
  \brief  Transmitter Delay Compensation
*/ 
#define CAN_30_MCAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_TDCRType, CAN_30_MCAN_CONST) Can_30_Mcan_TDCR[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TDCR       Comment */
  /*     0 */  0x20u,  /* [CT_FDCAN2_c5d3d1a7 - CanControllerBaudrateConfig] */
  /*     1 */  0x00u   /* [CT_FDCAN14_90ecad61 - CanControllerBaudrateConfig] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_XIDAM
**********************************************************************************************************************/
#define CAN_30_MCAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_XIDAMType, CAN_30_MCAN_CONST) Can_30_Mcan_XIDAM[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     XIDAM            Comment */
  /*     0 */  0x1FFFFFFFu,  /* [CT_FDCAN2_c5d3d1a7] */
  /*     1 */  0x1FFFFFFFu   /* [CT_FDCAN14_90ecad61] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_XIDFC
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_XIDFC
  \brief  Extended ID filter configuration
  \details
  Element          Description
  FLESA            Filter List Extended Start Address
  LSE              List size extended
  XIDFEEndIdx      the end index of the 0:n relation pointing to Can_30_Mcan_XIDFE
  XIDFEStartIdx    the start index of the 0:n relation pointing to Can_30_Mcan_XIDFE
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_XIDFCType, CAN_30_MCAN_CONST) Can_30_Mcan_XIDFC[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FLESA  LSE    XIDFEEndIdx                                                          XIDFEStartIdx                                                                Comment */
  { /*     0 */ 0x04u, 0x01u,          1u  /* /ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7 */ ,            0u  /* /ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7 */  },  /* [CT_FDCAN2_c5d3d1a7] */
  { /*     1 */ 0x04u, 0x01u,          2u  /* /ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61 */,            1u  /* /ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61 */ }   /* [CT_FDCAN14_90ecad61] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_XIDFE
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_XIDFE
  \brief  Extended ID filters
  \details
  Element    Description
  EIDFE_0
  EIDFE_1
*/ 
#define CAN_30_MCAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_30_Mcan_XIDFEType, CAN_30_MCAN_CONST) Can_30_Mcan_XIDFE[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EIDFE_0                            EIDFE_1                                  Comment                           Referable Keys */
  { /*     0 */ 0x20000000u  /*  I:0 F0 FIFO_0 */, 0x80000000u  /*  I:0 F1 FIFO_0 */ },  /* [CT_FDCAN2_c5d3d1a7]  */  /* [/ActiveEcuC/Can/CanConfigSet/CT_FDCAN2_c5d3d1a7] */
  { /*     1 */ 0x20000000u  /*  I:0 F0 FIFO_0 */, 0x80000000u  /*  I:0 F1 FIFO_0 */ }   /* [CT_FDCAN14_90ecad61] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_FDCAN14_90ecad61] */
};
#define CAN_30_MCAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_ActiveSendObject
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_ActiveSendObject
  \brief  temporary data for TX object
  \details
  Element    Description
  Pdu        buffered PduId for confirmation or cancellation
  State      send state like cancelled or send activ
*/ 
#define CAN_30_MCAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Can_30_Mcan_ActiveSendObjectType, CAN_30_MCAN_VAR_NOINIT) Can_30_Mcan_ActiveSendObject[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CAN_30_MCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_ControllerData
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_ControllerData
  \brief  struct for all controller related variable data
  \details
  Element                      Description
  IntEnable                    CAN Interrupt Enable state for each controller
  NonFdObjectsPendingFlag      CAN Tx Objects pending with CAN-FD format
  TXBCR                        CAN Tx Buffer Cancellation Request for each controller
  TXBRP                        CAN Tx Buffer request Pending for each controller
  BusOffNotification           CAN state for each controller: busoff occur
  BusOffTransitionRequest      CAN state request for each controller: ContinueBusOffRecovery=0x00, FinishBusOffRecovery=0x01
  CanInterruptCounter          CAN interrupt disable counter for each controller
  IsBusOff                     CAN state for each controller: busoff occur
  LastInitObject               last set baudrate for reinit
  LastState                    CAN mode transition request status for each controller
  LogStatus                    CAN state for each controller: UNINIT=0x00, START=0x01, STOP=0x02, INIT=0x04, INCONSISTENT=0x08, WARNING =0x10, PASSIVE=0x20, BUSOFF=0x40, SLEEP=0x80
  ModeTransitionRequest        CAN state request for each controller: INIT=0x00, SLEEP=0x01, WAKEUP=0x02, STOP+INIT=0x03, START=0x04, START+INIT=0x05, NONE=0x06
  PrevMode                     CAN mode transition request for each controller
  RamCheckTransitionRequest    CAN state request for each controller: kCanSuppressRamCheck=0x01, kCanExecuteRamCheck=0x00
  CanInterruptOldStatus        last CAN interrupt status for restore interrupt for each controller
  LoopTimeout                  hw loop timeout for each controller
*/ 
#define CAN_30_MCAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Can_30_Mcan_ControllerDataType, CAN_30_MCAN_VAR_NOINIT) Can_30_Mcan_ControllerData[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CAN_30_MCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_30_Mcan_MailboxState
**********************************************************************************************************************/
/** 
  \var    Can_30_Mcan_MailboxState
  \brief  state of mailbox (e.g. deactivated)
*/ 
#define CAN_30_MCAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Can_30_Mcan_MailboxStateType, CAN_30_MCAN_VAR_NOINIT) Can_30_Mcan_MailboxState[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CAN_30_MCAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/




