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
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTp_Lcfg.c
 *   Generation Time: 2024-11-25 15:00:22
 *           Project: DemoFbl - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
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
CONST(CanTp_RxPduMapType, CANTP_CONST) CanTp_RxPduMap[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxSduCfgIndEndIdx  RxSduCfgIndStartIdx  TxSduCfgIndEndIdx                     TxSduCfgIndStartIdx                    */
  { /*     0 */                1u,                  0u,                                   1u,                                     0u },
  { /*     1 */                2u,                  1u,                                   2u,                                     1u },
  { /*     2 */                3u,                  2u, CANTP_NO_TXSDUCFGINDENDIDXOFRXPDUMAP, CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP },
  { /*     3 */                4u,                  3u, CANTP_NO_TXSDUCFGINDENDIDXOFRXPDUMAP, CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP }
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
  NCr                     
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  RxPaddingActivation     
  BlockSize               
  CanType                 
  NAr                     
  RxMaxPayloadLength      
  RxTaType                
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfg[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    NCr   LoLayerTxFcPduId                                                                    PduRRxSduId                              RxPduId                                     TxFcPduConfirmationPduId                        RxPaddingActivation  BlockSize  CanType                        NAr   RxMaxPayloadLength  RxTaType                             TxSduCfgIdx                           Comment                            Referable Keys */
  { /*     0 */  11u, CANTP_INVALID_HDL                                                                 , PduRConf_PduRSrcPdu_PduRSrcPdu_c6d69dfd, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_d1898b63, CANTP_INVALID_HDL                             ,               FALSE,        8u, CANTP_CANFD_CANTYPEOFRXSDUCFG,  11u,                63u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_7ae70fe5] */  /* [CanTpRxNSdu_7ae70fe5, 3] */
  { /*     1 */ 501u, CanIfConf_CanIfTxPduCfg_Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_af53cbd5, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a624ba96, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_a624ba96,                TRUE,        0u, CANTP_CAN20_CANTYPEOFRXSDUCFG, 101u,                 7u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,                             0u },  /* [CanTpRxNSdu_b2964663] */  /* [CanTpRxNSdu_b2964663, 0] */
  { /*     2 */ 501u, CanIfConf_CanIfTxPduCfg_Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx   , PduRConf_PduRSrcPdu_PduRSrcPdu_6253e517, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_0b7d7ddf, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_0b7d7ddf,               FALSE,        0u, CANTP_CANFD_CANTYPEOFRXSDUCFG, 101u,                63u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,                             1u },  /* [CanTpRxNSdu_1ca716a4] */  /* [CanTpRxNSdu_1ca716a4, 1] */
  { /*     3 */  11u, CANTP_INVALID_HDL                                                                 , PduRConf_PduRSrcPdu_PduRSrcPdu_7d577bc2, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_b0bf513f, CANTP_INVALID_HDL                             ,                TRUE,        8u, CANTP_CAN20_CANTYPEOFRXSDUCFG,  11u,                 7u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG }   /* [CanTpRxNSdu_e190cd69] */  /* [CanTpRxNSdu_e190cd69, 2] */
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
CONST(CanTp_RxSduCfgIndType, CANTP_CONST) CanTp_RxSduCfgInd[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxSduCfgInd      Referable Keys */
  /*     0 */           1u,  /* [0] */
  /*     1 */           2u,  /* [1] */
  /*     2 */           3u,  /* [2] */
  /*     3 */           0u   /* [3] */
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
CONST(CanTp_RxSduSnv2HdlType, CANTP_CONST) CanTp_RxSduSnv2Hdl[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxSduCfgIdx        Comment */
  { /*     0 */          0u },  /* [CanTpRxNSdu_7ae70fe5] */
  { /*     1 */          1u },  /* [CanTpRxNSdu_b2964663] */
  { /*     2 */          2u },  /* [CanTpRxNSdu_1ca716a4] */
  { /*     3 */          3u }   /* [CanTpRxNSdu_e190cd69] */
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
CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfg[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LoLayerTxPduId                                                                      PduRTxSduId                                                                RxFcPduId                                       TxPduConfirmationPduId                      CanType                        RxSduCfgIdx  TxMaxPayloadLength        Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_Demo_0_CAN_20_Response_Tp_oDemoFBL_Vector_SLP3_598c37f0_Tx, PduRConf_PduRDestPdu_Demo_0_CAN_Response_oDemoFBL_Vector_SLP3_366a5b38_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_84de6e64, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_84de6e64, CANTP_CAN20_CANTYPEOFTXSDUCFG,          1u,                 7u },  /* [CanTpTxNSdu_b2964663] */  /* [CanTpTxNSdu_b2964663, 0] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_7e3956da_Tx   , PduRConf_PduRDestPdu_Demo_0_CAN_FD_Response_oDemoFBL_Fca_SLP5_55a79f5b_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_2987a92d, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_2987a92d, CANTP_CANFD_CANTYPEOFTXSDUCFG,          2u,                63u }   /* [CanTpTxNSdu_1ca716a4] */  /* [CanTpTxNSdu_1ca716a4, 1] */
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
CONST(CanTp_TxSduCfgIndType, CANTP_CONST) CanTp_TxSduCfgInd[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxSduCfgInd      Referable Keys */
  /*     0 */           0u,  /* [0] */
  /*     1 */           1u   /* [1] */
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
CONST(CanTp_TxSduSnv2HdlType, CANTP_CONST) CanTp_TxSduSnv2Hdl[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxSduCfgIdx        Comment */
  { /*     0 */          0u },  /* [CanTpTxNSdu_b2964663] */
  { /*     1 */          1u }   /* [CanTpTxNSdu_1ca716a4] */
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
VAR(CanTp_CalcBSType, CANTP_VAR_NOINIT) CanTp_CalcBS[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(CanTp_RxStateType, CANTP_VAR_NOINIT) CanTp_RxState[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(CanTp_TxSemaphoreType, CANTP_VAR_NOINIT) CanTp_TxSemaphores[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(CanTp_TxStateType, CANTP_VAR_NOINIT) CanTp_TxState[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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




