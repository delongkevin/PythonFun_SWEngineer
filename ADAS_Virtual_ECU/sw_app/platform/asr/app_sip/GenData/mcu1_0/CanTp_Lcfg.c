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
 *            Module: CanTp
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTp_Lcfg.c
 *   Generation Time: 2024-02-13 13:07:47
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define CANTP_LCFG_SOURCE

/* -----------------------------------------------------------------------------
    &&&~ Include files
 ----------------------------------------------------------------------------- */

#include "CanTp_Lcfg.h"
#if (CANTP_LOLAYER_CANIF == STD_ON)
# include "CanIf.h"
#endif
#include "PduR_CanTp.h"

/* -----------------------------------------------------------------------------
    &&&~ Data definitions
 ----------------------------------------------------------------------------- */



/**********************************************************************************************************************
 *  LOCAL DATA
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
 *  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanTp_RxPduMap
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPduMap
  \details
  Element                Description
  RxSduCfgIndEndIdx      the end index of the 0:n relation pointing to CanTp_RxSduCfgInd
  RxSduCfgIndStartIdx    the start index of the 0:n relation pointing to CanTp_RxSduCfgInd
  TxSduCfgIndEndIdx      the end index of the 0:n relation pointing to CanTp_TxSduCfgInd
  TxSduCfgIndStartIdx    the start index of the 0:n relation pointing to CanTp_TxSduCfgInd
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPduMapType, CANTP_CONST) CanTp_RxPduMap[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxSduCfgIndEndIdx  RxSduCfgIndStartIdx  TxSduCfgIndEndIdx                     TxSduCfgIndStartIdx                    */
  { /*     0 */                1u,                  0u,                                   1u,                                     0u },
  { /*     1 */                2u,                  1u,                                   2u,                                     1u },
  { /*     2 */                3u,                  2u,                                   3u,                                     2u },
  { /*     3 */                4u,                  3u, CANTP_NO_TXSDUCFGINDENDIDXOFRXPDUMAP, CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP },
  { /*     4 */                5u,                  4u, CANTP_NO_TXSDUCFGINDENDIDXOFRXPDUMAP, CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP },
  { /*     5 */                6u,                  5u, CANTP_NO_TXSDUCFGINDENDIDXOFRXPDUMAP, CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfg
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfg
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NCr                     
  RxMaxPayloadLength      
  RxTaType                
  STmin                   
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfg[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxFcPduId                                                              PduRRxSduId                              RxPduId                                     TxFcPduConfirmationPduId                        CanType                        NAr  NCr  RxMaxPayloadLength  RxTaType                             STmin  TxSduCfgIdx                           Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_DIAGNOSTIC_RESPONSE_FD_PAM_Tp_oFDCAN2_3daa27dc_Tx   , PduRConf_PduRSrcPdu_PduRSrcPdu_e393916e, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_d47df513, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_d47df513, CANTP_CANFD_CANTYPEOFRXSDUCFG, 21u, 31u,                63u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             0u },  /* [CanTpRxNSdu_1222086e] */  /* [CanTpRxNSdu_1222086e, 0] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_DIAGNOSTIC_RESPONSE_PAM_Tp_oFDCAN2_dc079c65_Tx      , PduRConf_PduRSrcPdu_PduRSrcPdu_274afd95, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_70d407dc, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_70d407dc, CANTP_CAN20_CANTYPEOFRXSDUCFG, 21u, 31u,                 7u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             1u },  /* [CanTpRxNSdu_2a48747d] */  /* [CanTpRxNSdu_2a48747d, 2] */
  { /*     2 */ CANTP_INVALID_HDL                                                           , PduRConf_PduRSrcPdu_PduRSrcPdu_d1f51245, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_e5111065, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG, 11u, 11u,                 7u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_fc98325d] */  /* [CanTpRxNSdu_fc98325d, 4] */
  { /*     3 */ CANTP_INVALID_HDL                                                           , PduRConf_PduRSrcPdu_PduRSrcPdu_ec401e20, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_5d8c5c04, CANTP_INVALID_HDL                             , CANTP_CAN20_CANTYPEOFRXSDUCFG, 11u, 11u,                 7u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_7ba98dbc] */  /* [CanTpRxNSdu_7ba98dbc, 5] */
  { /*     4 */ CANTP_INVALID_HDL                                                           , PduRConf_PduRSrcPdu_PduRSrcPdu_74e62a6c, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_c5f86a1c, CANTP_INVALID_HDL                             , CANTP_CANFD_CANTYPEOFRXSDUCFG, 11u, 11u,                63u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,    0u, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_02dfa36c] */  /* [CanTpRxNSdu_02dfa36c, 3] */
  { /*     5 */ CanIfConf_CanIfTxPduCfg_DIAGNOSTIC_RESPONSE_FD_PAM_Tp_oFDCAN2_20_a02181d6_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_ff4aa4e5, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_84ab9e51, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_84ab9e51, CANTP_CAN20_CANTYPEOFRXSDUCFG, 21u, 31u,                 7u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,   20u,                             2u }   /* [CanTpRxNSdu_652be4ae] */  /* [CanTpRxNSdu_652be4ae, 1] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgInd
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgInd
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduCfgIndType, CANTP_CONST) CanTp_RxSduCfgInd[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxSduCfgInd      Referable Keys */
  /*     0 */           0u,  /* [0] */
  /*     1 */           5u,  /* [1] */
  /*     2 */           1u,  /* [2] */
  /*     3 */           4u,  /* [3] */
  /*     4 */           2u,  /* [4] */
  /*     5 */           3u   /* [5] */
};
#define CANTP_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduSnv2Hdl
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduSnv2Hdl
  \details
  Element        Description
  RxSduCfgIdx    the index of the 0:1 relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduSnv2HdlType, CANTP_CONST) CanTp_RxSduSnv2Hdl[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxSduCfgIdx        Comment */
  { /*     0 */          0u },  /* [CanTpRxNSdu_1222086e] */
  { /*     1 */          1u },  /* [CanTpRxNSdu_2a48747d] */
  { /*     2 */          2u },  /* [CanTpRxNSdu_fc98325d] */
  { /*     3 */          3u },  /* [CanTpRxNSdu_7ba98dbc] */
  { /*     4 */          4u },  /* [CanTpRxNSdu_02dfa36c] */
  { /*     5 */          5u }   /* [CanTpRxNSdu_652be4ae] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfg
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfg
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfg[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxPduId                                                                PduRTxSduId                                                             RxFcPduId                                       TxPduConfirmationPduId                      CanType                        RxSduCfgIdx  TxMaxPayloadLength        Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_DIAGNOSTIC_RESPONSE_FD_PAM_Tp_oFDCAN2_3daa27dc_Tx   , PduRConf_PduRDestPdu_DIAGNOSTIC_RESPONSE_FD_PAM_oFDCAN2_411d850e_Tx   , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_f68721e1, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_f68721e1, CANTP_CANFD_CANTYPEOFTXSDUCFG,          0u,                63u },  /* [CanTpTxNSdu_1222086e] */  /* [CanTpTxNSdu_1222086e, 0] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_DIAGNOSTIC_RESPONSE_PAM_Tp_oFDCAN2_dc079c65_Tx      , PduRConf_PduRDestPdu_DIAGNOSTIC_RESPONSE_PAM_oFDCAN2_7c9fd6f9_Tx      , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_522ed32e, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_522ed32e, CANTP_CAN20_CANTYPEOFTXSDUCFG,          1u,                 7u },  /* [CanTpTxNSdu_2a48747d] */  /* [CanTpTxNSdu_2a48747d, 2] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_DIAGNOSTIC_RESPONSE_FD_PAM_Tp_oFDCAN2_20_a02181d6_Tx, PduRConf_PduRDestPdu_DIAGNOSTIC_RESPONSE_FD_PAM_oFDCAN2_20_25761d2e_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_a6514aa3, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_a6514aa3, CANTP_CAN20_CANTYPEOFTXSDUCFG,          5u,                 7u }   /* [CanTpTxNSdu_652be4ae] */  /* [CanTpTxNSdu_652be4ae, 1] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgInd
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgInd
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduCfgIndType, CANTP_CONST) CanTp_TxSduCfgInd[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxSduCfgInd      Referable Keys */
  /*     0 */           0u,  /* [0] */
  /*     1 */           2u,  /* [1] */
  /*     2 */           1u   /* [2] */
};
#define CANTP_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduSnv2Hdl
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduSnv2Hdl
  \details
  Element        Description
  TxSduCfgIdx    the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduSnv2HdlType, CANTP_CONST) CanTp_TxSduSnv2Hdl[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxSduCfgIdx        Comment */
  { /*     0 */          0u },  /* [CanTpTxNSdu_1222086e] */
  { /*     1 */          1u },  /* [CanTpTxNSdu_2a48747d] */
  { /*     2 */          2u }   /* [CanTpTxNSdu_652be4ae] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_CalcBS
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTp_CalcBSType, CANTP_VAR_NOINIT) CanTp_CalcBS[6];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANTP_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxState
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTp_RxStateType, CANTP_VAR_NOINIT) CanTp_RxState[6];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSemaphores
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTp_TxSemaphoreType, CANTP_VAR_NOINIT) CanTp_TxSemaphores[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxState
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTp_TxStateType, CANTP_VAR_NOINIT) CanTp_TxState[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 * FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/




