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
 *            Module: FblCw
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FblCw_Lcfg.c
 *   Generation Time: 2024-11-25 15:00:22
 *           Project: DemoFbl - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/


#define FBLCW_LCFG_SOURCE
/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0779 EOF */ /* MD_CSL_0779 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "fbl_inc.h"
#include "FblCw_Lcfg.h"
#include "PduR_Dcm.h"

#include "CanIf.h"
#include "CanTp.h"




/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  FblCw_CanIfCtrlInfo
**********************************************************************************************************************/
/** 
  \var    FblCw_CanIfCtrlInfo
  \brief  DefinitionRef: /[ANY]/CanIf/CanIfCtrlDrvCfg/CanIfCtrlCfg
*/ 
#define FBLCW_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_CanIfCtrlInfoType, FBLCW_CONST) FblCw_CanIfCtrlInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CanIfCtrlInfo                                               Referable Keys */
  /*     0 */  CanIfConf_CanIfCtrlCfg_CT_DemoFBL_Vector_SLP3_d34c962b   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DemoFBL_Vector_SLP3_d34c962b] */
};
#define FBLCW_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslConnectionGroupInfo
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslConnectionGroupInfo
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnectionGroup
  \details
  Element    Description
  Snv    
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_DcmDslConnectionGroupInfoType, FBLCW_CONST) FblCw_DcmDslConnectionGroupInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Snv        Referable Keys */
  { /*     0 */  0u }   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DcmDslConnectionGroup, /ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DcmDslConnection_ee2e78f1, /ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DcmDslConnection_8ee2a6b1] */
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslConnectionGroupInfoInd
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslConnectionGroupInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to FblCw_DcmDslConnectionGroupInfo
*/ 
#define FBLCW_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_DcmDslConnectionGroupInfoIndType, FBLCW_CONST) FblCw_DcmDslConnectionGroupInfoInd[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     DcmDslConnectionGroupInfoInd      Referable Keys */
  /*     0 */                            0u,  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DcmDslConnection_8ee2a6b1] */
  /*     1 */                            0u   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DcmDslConnection_ee2e78f1] */
};
#define FBLCW_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslConnectionInfo
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslConnectionInfo
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection
  \details
  Element                                 Description
  PayloadLimit                            DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslPayloadLimit
  Controller                              controller handle
  DcmDslConnectionGroupInfoIndStartIdx    the start index of the 0:n relation pointing to FblCw_DcmDslConnectionGroupInfoInd
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_DcmDslConnectionInfoType, FBLCW_CONST) FblCw_DcmDslConnectionInfo[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PayloadLimit  Controller                                              DcmDslConnectionGroupInfoIndStartIdx        Referable Keys */
  { /*     0 */      0x0FFFu, CanIfConf_CanIfCtrlCfg_CT_DemoFBL_Vector_SLP3_d34c962b,                                   0u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DcmDslConnection_8ee2a6b1] */
  { /*     1 */      0x0FFFu, CanIfConf_CanIfCtrlCfg_CT_DemoFBL_Vector_SLP3_d34c962b,                                   1u }   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DcmDslConnection_ee2e78f1] */
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslProtocolRxInfo
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslProtocolRxInfo
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx
  \details
  Element                    Description
  AddrType                   DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx/DcmDslProtocolRxAddrType
  DcmDslConnectionInfoIdx    the index of the 1:1 relation pointing to FblCw_DcmDslConnectionInfo
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_DcmDslProtocolRxInfoType, FBLCW_CONST) FblCw_DcmDslProtocolRxInfo[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AddrType                                         DcmDslConnectionInfoIdx        Referable Keys */
  { /*     0 */   FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      0u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DcmDslConnection_8ee2a6b1/DcmDslMainConnection_7a6ac838/Demo_0_CAN_Request_oDemoFBL_Vector_SLP3_51500fe6_Rx_a43927b4] */
  { /*     1 */ FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      0u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DcmDslConnection_8ee2a6b1/DcmDslMainConnection_7a6ac838/Functional_CAN_oDemoFBL_Vector_SLP3_3a497ac1_Rx_39a6aa48] */
  { /*     2 */ FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      1u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DcmDslConnection_ee2e78f1/DcmDslMainConnection/Functional_CAN_FD_oDemoFBL_Fca_SLP5_b4f709e0_Rx_5eff7b81] */
  { /*     3 */   FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      1u }   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DcmDslConnection_ee2e78f1/DcmDslMainConnection/Demo_0_CAN_FD_Request_oDemoFBL_Fca_SLP5_888d0879_Rx_ba94451d] */
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslProtocolTxInfo
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslProtocolTxInfo
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolTx
  \details
  Element                    Description
  DcmDslConnectionInfoIdx    the index of the 1:1 relation pointing to FblCw_DcmDslConnectionInfo
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_DcmDslProtocolTxInfoType, FBLCW_CONST) FblCw_DcmDslProtocolTxInfo[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DcmDslConnectionInfoIdx        Referable Keys */
  { /*     0 */                      1u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DcmDslConnection_ee2e78f1/DcmDslMainConnection/Demo_0_CAN_FD_Response_oDemoFBL_Fca_SLP5_3c1da0e3_Tx_d2d667ae] */
  { /*     1 */                      0u }   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DcmDslConnection_8ee2a6b1/DcmDslMainConnection_7a6ac838/Demo_0_CAN_Response_oDemoFBL_Vector_SLP3_aa44c06b_Tx_b84cb01a] */
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_Initialized
**********************************************************************************************************************/
/** 
  \var    FblCw_Initialized
  \brief  Initialization state of the Dcm. TRUE, if Dcm_Init() has been called, else FALSE.
*/ 
#define FBLCW_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(FblCw_InitializedType, FBLCW_VAR_ZERO_INIT) FblCw_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/

#define FBLCW_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define FBLCW_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
  END OF FILE: FblCw_Lcfg.c
**********************************************************************************************************************/

