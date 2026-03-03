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
 *            Module: Dcm
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dcm_Lcfg.c
 *   Generation Time: 2025-09-23 16:16:41
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/



#define DCM_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
                                                                                                                                                     /* PRQA S 1533 EOF */ /* MD_Dcm_ObjectOnlyAccessedOnce */
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "Det.h"
#include "Dcm_Int.h"
#include "PduR_Dcm.h"
#include "ComM_Dcm.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if (DCM_DIDMGR_NVM_READ_ENABLED == STD_ON) || \
    (DCM_DIDMGR_NVM_WRITE_ENABLED == STD_ON)
# if defined(NVM_VENDOR_ID)
#  if (NVM_VENDOR_ID == 30u)
/* Only Vector NvM supports this feature up to now */
#   define Dcm_GetDcmNvMBlockId(blockId)                             (uint16)(NvM_GetDcmBlockId(blockId))                                            /* PRQA S 3453 */ /* QAC 7.0:  A function could probably be used instead of this function-like macro */ /* Macro is more efficient! */
#  endif
# endif

/* Default NvM handle offset */
# if !defined(Dcm_GetDcmNvMBlockId)
#  define Dcm_GetDcmNvMBlockId(blockId)                              (uint16)(blockId)                                                               /* PRQA S 3453 */ /* QAC 7.0:  A function could probably be used instead of this function-like macro */ /* Macro is more efficient! */
# endif
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  Dcm_ModeRuleDefaultModeRule()
***********************************************************************************************************************/
/*! \brief         Evaluates a specific mode rule
 *  \details       Evaluates a specific mode rule consisting of one or multiple mode conditions and/or other mode rules.
 *  \param[in]     nrc    Negative response code
 *  \return        TRUE   The condition is fulfilled
 *  \return        FALSE  The condition is not fulfilled
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(boolean, DCM_CODE) Dcm_ModeRuleDefaultModeRule(Dcm_Ptr2LocalU8Type nrc);
/***********************************************************************************************************************
 *  Dcm_ModeRuleVehicleSpeedCheckRule()
***********************************************************************************************************************/
/*! \brief         Evaluates a specific mode rule
 *  \details       Evaluates a specific mode rule consisting of one or multiple mode conditions and/or other mode rules.
 *  \param[in]     nrc    Negative response code
 *  \return        TRUE   The condition is fulfilled
 *  \return        FALSE  The condition is not fulfilled
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(boolean, DCM_CODE) Dcm_ModeRuleVehicleSpeedCheckRule(Dcm_Ptr2LocalU8Type nrc);
/***********************************************************************************************************************
 *  Dcm_ModeRuleProgrammingPreconditionCheckRule()
***********************************************************************************************************************/
/*! \brief         Evaluates a specific mode rule
 *  \details       Evaluates a specific mode rule consisting of one or multiple mode conditions and/or other mode rules.
 *  \param[in]     nrc    Negative response code
 *  \return        TRUE   The condition is fulfilled
 *  \return        FALSE  The condition is not fulfilled
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(boolean, DCM_CODE) Dcm_ModeRuleProgrammingPreconditionCheckRule(Dcm_Ptr2LocalU8Type nrc);
/***********************************************************************************************************************
 *  Dcm_ModeCondGet_Dcm_Read_Mode_VehicleSpeedCheck()
***********************************************************************************************************************/
/*! \brief         Reads the currently active mode of a specific mode declaration group.
 *  \details       -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Rte_ModeType_VehicleSpeedCheck, DCM_CODE) Dcm_ModeCondGet_Dcm_Read_Mode_VehicleSpeedCheck(void);
/***********************************************************************************************************************
 *  Dcm_ModeCondGet_Dcm_Read_ModeProgPreconditionCheck_ProgPreconditionState()
***********************************************************************************************************************/
/*! \brief         Reads the currently active mode of a specific mode declaration group.
 *  \details       -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Rte_ModeType_ProgPreconditionState, DCM_CODE) Dcm_ModeCondGet_Dcm_Read_ModeProgPreconditionCheck_ProgPreconditionState(void);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define DCM_START_SEC_CALLOUT_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  Dcm_ServiceNoPostProcessor()
 ***********************************************************************************************************************/
/*! \brief         Dummy post-processor
 *  \details       This post-processor is called for diagnostic services which do not require any post processing.
 *  \param[in]     pContext  Pointer to the context
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoPostProcessor(
  Dcm_ContextPtrType pContext,
  Dcm_ConfirmationStatusType status
  );
/***********************************************************************************************************************
 *  Dcm_ServiceNoUpdater()
 ***********************************************************************************************************************/
/*! \brief         Realizes a dummy paged buffer updater.
 *  \details       This function is never called.
 *  \param[in]     pContext      Pointer to the context
 *  \param[in]     opStatus      The operation status
 *  \param[in,out] pDataContext  Pointer to the data context
 *  \param[out]    ErrorCode     Negative response code
 *  \return        E_NOT_OK      Operation failed. Take the NRC from ErrorCode. Do not call again
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ServiceNoUpdater(
  Dcm_ContextPtrType pContext,
  Dcm_OpStatusType opStatus,
  Dcm_DiagDataContextPtrType pDataContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_ServiceNoCancel()
 ***********************************************************************************************************************/
/*! \brief         Dummy service cancellation.
 *  \details       -
 *  \param[in]     pContext      Pointer to the context
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoCancel(
  Dcm_ContextPtrType pContext
  );
#define DCM_STOP_SEC_CALLOUT_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA DECLARATIONS
 *********************************************************************************************************************/
#define DCM_START_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! DCM protocol descriptor */
DCM_LOCAL VAR(Dcm_MsgItemType, DCM_VAR_NOINIT) Dcm_CfgNetBuffer_000[5003];
#define DCM_STOP_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! TxPduId to DCM connection map */
CONST(Dcm_NetConnRefMemType, DCM_CONST) Dcm_CfgNetTxPduInfo[3]=
{
    1u
  , 2u
  , 0u
};
/*! Map of DCM relevant network handles */
CONST(Dcm_CfgNetNetIdRefMemType, DCM_CONST) Dcm_CfgNetConnComMChannelMap[1]=
{
    0u
};
/*! Service 0x28 list of channels for the all-comm-channel parameter */
CONST(Dcm_CfgNetNetIdRefMemType, DCM_CONST) Dcm_CfgNetComCtrlChannelListAll[2]=
{
   1u
  , 0u
};
/*! Look up table of all supported transfer ALFIDs */
CONST(uint8, DCM_CONST) Dcm_CfgFblMgrTransferAlfidLookUpTable[17]=
{
   16u
  ,0x11u
  ,0x12u
  ,0x13u
  ,0x14u
  ,0x21u
  ,0x22u
  ,0x23u
  ,0x24u
  ,0x31u
  ,0x32u
  ,0x33u
  ,0x34u
  ,0x41u
  ,0x42u
  ,0x43u
  ,0x44u
};
/*! Look up table of all supported transfer MIDs */
CONST(uint8, DCM_CONST) Dcm_CfgFblMgrTransferMidLookUpTable[1]=
{
   0u
};
/*! Look up table of DCM service identifiers */
CONST(uint8, DCM_CONST) Dcm_CfgDiagSvcIdLookUpTable[16]=
{
   15u
  ,0x10u
  ,0x11u
  ,0x14u
  ,0x19u
  ,0x22u
  ,0x27u
  ,0x28u
  ,0x2Eu
  ,0x2Fu
  ,0x31u
  ,0x34u
  ,0x36u
  ,0x37u
  ,0x3Eu
  ,0x85u
};
/*! Service 0x10 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc10SubFuncLookUpTable[4]=
{
   3u
  ,0x01u
  ,0x02u
  ,0x03u
};
/*! Service 0x11 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc11SubFuncLookUpTable[2]=
{
   1u
  ,0x01u
};
/*! Service 0x19 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc19SubFuncLookUpTable[11]=
{
   10u
  ,0x01u
  ,0x02u
  ,0x04u
  ,0x06u
  ,0x07u
  ,0x08u
  ,0x09u
  ,0x0Au
  ,0x0Cu
  ,0x0Eu
};
/*! Service 0x27 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc27SubFuncLookUpTable[3]=
{
   2u
  ,0x11u
  ,0x12u
};
/*! Service 0x28 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28SubFuncLookUpTable[3]=
{
   2u
  ,0x00u
  ,0x01u
};
/*! Service 0x28 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28MessageTypeLookUpTable[4]=
{
   3u
  ,0x01u
  ,0x02u
  ,0x03u
};
/*! Service 0x28 network ID lookup */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28SubNetIdLookUp[3]=
{
   2u
  ,0x00u
  ,0x0Fu
};
/*! Service 0x3E look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc3ESubFuncLookUpTable[2]=
{
   1u
  ,0x00u
};
/*! Look up table of service 0x85 */
CONST(uint8, DCM_CONST) Dcm_CfgSvc85SubFuncLookUpTable[3]=
{
   2u
  ,0x01u
  ,0x02u
};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define DCM_START_SEC_CONST_16
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! DID look up table  */
CONST(uint16, DCM_CONST) Dcm_CfgDidMgrDidLookUpTable[165]=
{
   164u
  ,0x0103u
  ,0x0107u
  ,0x0108u
  ,0x1002u
  ,0x1004u
  ,0x1008u
  ,0x1009u
  ,0x100Bu
  ,0x100Cu
  ,0x102Au
  ,0x191Du
  ,0x1921u
  ,0x2001u
  ,0x2002u
  ,0x2003u
  ,0x2008u
  ,0x200Au
  ,0x200Bu
  ,0x200Cu
  ,0x200Du
  ,0x2010u
  ,0x2013u
  ,0x201Au
  ,0x201Bu
  ,0x201Fu
  ,0x2023u
  ,0x2024u
  ,0x2026u
  ,0x2030u
  ,0x2031u
  ,0x2032u
  ,0x292Eu
  ,0x2939u
  ,0x2945u
  ,0x2951u
  ,0x2954u
  ,0x2957u
  ,0x2958u
  ,0x2959u
  ,0x295Au
  ,0x295Bu
  ,0x295Cu
  ,0x295Eu
  ,0x295Fu
  ,0x4421u
  ,0x4422u
  ,0x4423u
  ,0x4424u
  ,0x4425u
  ,0x4426u
  ,0x4427u
  ,0x4428u
  ,0x4429u
  ,0x442Au
  ,0x442Bu
  ,0x442Cu
  ,0x4451u
  ,0x5001u
  ,0x5100u
  ,0x5102u
  ,0x5103u
  ,0x5104u
  ,0x5105u
  ,0x5107u
  ,0x5109u
  ,0x5201u
  ,0x5300u
  ,0x5301u
  ,0x5302u
  ,0x5303u
  ,0x5304u
  ,0x5305u
  ,0x5500u
  ,0x5501u
  ,0xF10Bu
  ,0xF10Du
  ,0xF110u
  ,0xF111u
  ,0xF112u
  ,0xF122u
  ,0xF132u
  ,0xF133u
  ,0xF134u
  ,0xF154u
  ,0xF155u
  ,0xF180u
  ,0xF181u
  ,0xF182u
  ,0xF184u
  ,0xF185u
  ,0xF186u
  ,0xF187u
  ,0xF188u
  ,0xF18Au
  ,0xF18Bu
  ,0xF18Cu
  ,0xF190u
  ,0xF191u
  ,0xF192u
  ,0xF193u
  ,0xF194u
  ,0xF195u
  ,0xF1A0u
  ,0xF1A1u
  ,0xF1A2u
  ,0xF1A6u
  ,0xF1B0u
  ,0xF1B3u
  ,0xF1B4u
  ,0xF1B5u
  ,0xFD00u
  ,0xFD01u
  ,0xFD04u
  ,0xFD07u
  ,0xFD08u
  ,0xFD0Au
  ,0xFD0Cu
  ,0xFD0Du
  ,0xFD0Eu
  ,0xFD0Fu
  ,0xFD13u
  ,0xFD14u
  ,0xFD15u
  ,0xFD16u
  ,0xFD17u
  ,0xFD1Cu
  ,0xFD1Du
  ,0xFD1Eu
  ,0xFD20u
  ,0xFD28u
  ,0xFD29u
  ,0xFD2Au
  ,0xFD2Bu
  ,0xFD2Cu
  ,0xFD2Du
  ,0xFD2Eu
  ,0xFD31u
  ,0xFD33u
  ,0xFD38u
  ,0xFD42u
  ,0xFD43u
  ,0xFD44u
  ,0xFD46u
  ,0xFD47u
  ,0xFD48u
  ,0xFD49u
  ,0xFD4Au
  ,0xFD4Eu
  ,0xFD60u
  ,0xFD61u
  ,0xFD62u
  ,0xFD64u
  ,0xFD65u
  ,0xFD66u
  ,0xFD67u
  ,0xFD74u
  ,0xFD86u
  ,0xFDF0u
  ,0xFDF1u
  ,0xFDF2u
  ,0xFDF5u
  ,0xFDF6u
  ,0xFDF7u
  ,0xFDF8u
};
/*! RID look up table  */
CONST(uint16, DCM_CONST) Dcm_CfgRidMgrRidLookUpTable[21]=
{
   20u
  ,0x1000u
  ,0x2000u
  ,0x2001u
  ,0x3000u
  ,0x5000u
  ,0x5101u
  ,0x5200u
  ,0x5400u
  ,0x5401u
  ,0x5502u
  ,0xD001u
  ,0xD002u
  ,0xD003u
  ,0xF000u
  ,0xFE01u
  ,0xFE02u
  ,0xFE0Eu
  ,0xFF00u
  ,0xFF01u
  ,0xFF03u
};
#define DCM_STOP_SEC_CONST_16
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! DCM buffer descriptor */
CONST(Dcm_CfgNetBufferInfoType, DCM_CONST) Dcm_CfgNetBufferInfo[1]=
{
   { Dcm_CfgNetBuffer_000,5003u}
};
/*! DCM protocol switch notifications */
CONST(Dcm_CfgNetProtocolNotificationInfoType, DCM_CONST) Dcm_CfgNetProtocolNotificationInfo[1]=
{
   { NULL_PTR}
};
/*! RxPduId map */
CONST(Dcm_CfgNetRxPduInfoType, DCM_CONST) Dcm_CfgNetRxPduInfo[6]=
{
   { TRUE, 1u}
  ,{ FALSE, 1u}
  ,{ TRUE, 2u}
  ,{ FALSE, 2u}
  ,{ TRUE, 0u}
  ,{ FALSE, 0u}
};
/*! DCM connection descriptor */
CONST(Dcm_CfgNetConnectionInfoType, DCM_CONST) Dcm_CfgNetConnectionInfo[3]=
{
   { 0x00F2u,PduRConf_PduRSrcPdu_PduRSrcPdu_042e3f8c, 0u,0u,0x00u,0x00u, 0u}
  ,{ 0x00F1u,PduRConf_PduRSrcPdu_PduRSrcPdu_8b616172, 0u,0u,0x00u,0x00u, 0u}
  ,{ 0x00F2u,PduRConf_PduRSrcPdu_PduRSrcPdu_a27f7930, 0u,0u,0x00u,0x00u, 0u}
};
/*! DCM protocol descriptor */
CONST(Dcm_CfgNetProtocolInfoType, DCM_CONST) Dcm_CfgNetProtocolInfo[1]=
{
   { {        0u,       0u},4095u, 3u, 0u,TRUE,0u,DemConf_DemClient_DemClient, 0u}
};
/*! Map of all relevant for DCM network handles */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetAllComMChannelMap[1]=
{
   ComMConf_ComMChannel_CN_FDCAN2_28a8fc44
};
/*! Look up table of DCM relevant network handles */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetNetworkHandleLookUpTable[2]=
{
   1u
  ,ComMConf_ComMChannel_CN_FDCAN2_28a8fc44
};
/*! Precondition mode rules */
CONST(Dcm_ModeRuleFuncType, DCM_CONST) Dcm_CfgModeMgrRules[3]=
{
   Dcm_ModeRuleDefaultModeRule
  ,Dcm_ModeRuleVehicleSpeedCheckRule
  ,Dcm_ModeRuleProgrammingPreconditionCheckRule
};
/*! Diagnostic service execution conditions */
CONST(Dcm_CfgStatePreconditionInfoType, DCM_CONST) Dcm_CfgStatePreconditions[11]=
{
   {    0u,{ 0x07u,0x03u}}
  ,{    2u,{ 0x07u,0x03u}}
  ,{    0u,{ 0x05u,0x03u}}
  ,{    0u,{ 0x06u,0x03u}}
  ,{    0u,{ 0x04u,0x03u}}
  ,{    0u,{ 0x04u,0x02u}}
  ,{    0u,{ 0x02u,0x02u}}
  ,{    0u,{ 0x02u,0x03u}}
  ,{    0u,{ 0x06u,0x02u}}
  ,{    1u,{ 0x04u,0x03u}}
  ,{    1u,{ 0x04u,0x02u}}
};
/*! Session state properties */
CONST(Dcm_CfgStateSessionInfoType, DCM_CONST) Dcm_CfgStateSessionInfo[3]=
{
   { {        5u,     500u},RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION,0x01u}
  ,{ {        5u,     500u},RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION,0x02u}
  ,{ {        5u,     500u},RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION,0x03u}
};
/*! Security Access state properties */
CONST(Dcm_CfgStateSecurityInfoType, DCM_CONST) Dcm_CfgStateSecurityInfo[1]=
{
   { 1000u,   0u,FALSE, 0u,0x09u} /* SecLvl: Authenticated_Diagnostic_Access */
};
/*! Session state change notification(s) */
CONST(Dcm_CfgStateNotificationInfoType, DCM_CONST) Dcm_CfgStateSessionNotificationInfo[2]=
{
   { Os_Call_DcmCalloutStub_SessionCallback}
  ,{ NULL_PTR}
};
/*! Security state change notification(s) */
CONST(Dcm_CfgStateNotificationInfoType, DCM_CONST) Dcm_CfgStateSecurityNotificationInfo[1]=
{
   { NULL_PTR}
};
/*! DID ranges look up */
CONST(Dcm_CfgDidMgrDidRangeType, DCM_CONST) Dcm_CfgDidMgrDidRanges[1]=
{
   {    0u,   0u}
};
/*! DID ranges to DID info map */
CONST(Dcm_CfgDidMgrDidInfoRefType, DCM_CONST) Dcm_CfgDidMgrRangeDidInfoRefs[1]=
{
   0u /* dummy initializer */
};
/*! DID properties */
CONST(Dcm_CfgDidMgrDidInfoType, DCM_CONST) Dcm_CfgDidMgrDidInfo[164]=
{
   {    2u,   2u,   2u,   0u,   0u,0x01u} /* DID: 0x0103 */
  ,{    1u,   1u,   1u,   1u,   0u,0x03u} /* DID: 0x0107 */
  ,{    4u,   4u,   4u,   3u,   0u,0x01u} /* DID: 0x0108 */
  ,{    2u,   2u,   2u,   4u,   0u,0x01u} /* DID: 0x1002 */
  ,{    1u,   1u,   1u,   5u,   0u,0x01u} /* DID: 0x1004 */
  ,{    3u,   3u,   3u,   6u,   0u,0x01u} /* DID: 0x1008 */
  ,{    2u,   2u,   2u,   7u,   0u,0x01u} /* DID: 0x1009 */
  ,{    1u,   1u,   1u,   8u,   0u,0x01u} /* DID: 0x100B */
  ,{    5u,   5u,   5u,   9u,   0u,0x01u} /* DID: 0x100C */
  ,{    9u,   9u,   9u,  10u,   0u,0x01u} /* DID: 0x102A */
  ,{    1u,   1u,   1u,  11u,   0u,0x01u} /* DID: 0x191D */
  ,{    9u,   9u,   9u,  12u,   0u,0x01u} /* DID: 0x1921 */
  ,{    2u,   2u,   2u,  13u,   0u,0x01u} /* DID: 0x2001 */
  ,{    2u,   2u,   2u,  14u,   0u,0x01u} /* DID: 0x2002 */
  ,{    4u,   4u,   4u,  15u,   0u,0x01u} /* DID: 0x2003 */
  ,{    3u,   3u,   3u,  16u,   0u,0x01u} /* DID: 0x2008 */
  ,{    2u,   2u,   2u,  17u,   0u,0x01u} /* DID: 0x200A */
  ,{    3u,   3u,   3u,  18u,   0u,0x01u} /* DID: 0x200B */
  ,{    2u,   2u,   2u,  19u,   0u,0x01u} /* DID: 0x200C */
  ,{    2u,   2u,   2u,  20u,   0u,0x01u} /* DID: 0x200D */
  ,{    2u,   2u,   2u,  21u,   0u,0x01u} /* DID: 0x2010 */
  ,{    1u,   1u,   1u,  22u,   0u,0x01u} /* DID: 0x2013 */
  ,{   20u,  20u,  20u,  23u,   0u,0x01u} /* DID: 0x201A */
  ,{   12u,  12u,  12u,  24u,   0u,0x01u} /* DID: 0x201B */
  ,{    2u,   2u,   2u,  25u,   0u,0x01u} /* DID: 0x201F */
  ,{    0u, 255u, 255u,  26u,   0u,0x02u} /* DID: 0x2023 */
  ,{    0u, 255u, 255u,  27u,   0u,0x01u} /* DID: 0x2024 */
  ,{    8u,   8u,   8u,  28u,   0u,0x01u} /* DID: 0x2026 */
  ,{  960u, 960u, 960u,  29u,   0u,0x01u} /* DID: 0x2030 */
  ,{ 3072u,3072u,3072u,  30u,   0u,0x01u} /* DID: 0x2031 */
  ,{ 1296u,1296u,1296u,  31u,   0u,0x01u} /* DID: 0x2032 */
  ,{    1u,   1u,   1u,  32u,   0u,0x01u} /* DID: 0x292E */
  ,{   24u,  24u,  24u,  33u,   0u,0x01u} /* DID: 0x2939 */
  ,{  200u, 200u, 200u,  34u,   0u,0x03u} /* DID: 0x2945 */
  ,{   16u,  16u,  16u,  36u,   0u,0x01u} /* DID: 0x2951 */
  ,{    1u,   1u,   1u,  37u,   0u,0x01u} /* DID: 0x2954 */
  ,{ 1056u,1056u,1056u,  38u,   0u,0x01u} /* DID: 0x2957 */
  ,{   96u,  96u,  96u,  39u,   0u,0x01u} /* DID: 0x2958 */
  ,{  352u, 352u, 352u,  40u,   0u,0x01u} /* DID: 0x2959 */
  ,{   32u,  32u,  32u,  41u,   0u,0x01u} /* DID: 0x295A */
  ,{  176u, 176u, 176u,  42u,   0u,0x01u} /* DID: 0x295B */
  ,{   16u,  16u,  16u,  43u,   0u,0x01u} /* DID: 0x295C */
  ,{   16u,  16u,  16u,  44u,   0u,0x01u} /* DID: 0x295E */
  ,{  176u, 176u, 176u,  45u,   0u,0x01u} /* DID: 0x295F */
  ,{   13u,  13u,  13u,  46u,   0u,0x01u} /* DID: 0x4421 */
  ,{   13u,  13u,  13u,  47u,   0u,0x01u} /* DID: 0x4422 */
  ,{   13u,  13u,  13u,  48u,   0u,0x01u} /* DID: 0x4423 */
  ,{   13u,  13u,  13u,  49u,   0u,0x01u} /* DID: 0x4424 */
  ,{   13u,  13u,  13u,  50u,   0u,0x01u} /* DID: 0x4425 */
  ,{   13u,  13u,  13u,  51u,   0u,0x01u} /* DID: 0x4426 */
  ,{   13u,  13u,  13u,  52u,   0u,0x01u} /* DID: 0x4427 */
  ,{   13u,  13u,  13u,  53u,   0u,0x01u} /* DID: 0x4428 */
  ,{   13u,  13u,  13u,  54u,   0u,0x01u} /* DID: 0x4429 */
  ,{   13u,  13u,  13u,  55u,   0u,0x01u} /* DID: 0x442A */
  ,{   13u,  13u,  13u,  56u,   0u,0x01u} /* DID: 0x442B */
  ,{   13u,  13u,  13u,  57u,   0u,0x01u} /* DID: 0x442C */
  ,{   44u,  44u,  44u,  58u,   0u,0x01u} /* DID: 0x4451 */
  ,{    1u,   1u,   1u,  59u,   0u,0x05u} /* DID: 0x5001 */
  ,{    4u,   4u,   4u,  61u,   0u,0x01u} /* DID: 0x5100 */
  ,{   34u,  34u,  34u,  62u,   0u,0x01u} /* DID: 0x5102 */
  ,{   41u,  41u,  41u,  63u,   0u,0x01u} /* DID: 0x5103 */
  ,{    5u,   5u,   5u,  64u,   0u,0x01u} /* DID: 0x5104 */
  ,{   19u,  19u,  19u,  65u,   0u,0x01u} /* DID: 0x5105 */
  ,{   15u,  15u,  15u,  66u,   0u,0x01u} /* DID: 0x5107 */
  ,{   15u,  15u,  15u,  67u,   0u,0x01u} /* DID: 0x5109 */
  ,{    1u,   1u,   1u,  68u,   0u,0x01u} /* DID: 0x5201 */
  ,{   14u,  14u,  14u,  69u,   0u,0x01u} /* DID: 0x5300 */
  ,{   14u,  14u,  14u,  70u,   0u,0x01u} /* DID: 0x5301 */
  ,{   14u,  14u,  14u,  71u,   0u,0x01u} /* DID: 0x5302 */
  ,{   12u,  12u,  12u,  72u,   0u,0x01u} /* DID: 0x5303 */
  ,{   12u,  12u,  12u,  73u,   0u,0x01u} /* DID: 0x5304 */
  ,{   12u,  12u,  12u,  74u,   0u,0x01u} /* DID: 0x5305 */
  ,{   42u,  42u,  42u,  75u,   0u,0x01u} /* DID: 0x5500 */
  ,{   48u,  48u,  48u,  76u,   0u,0x01u} /* DID: 0x5501 */
  ,{    2u,   2u,   2u,  77u,   0u,0x01u} /* DID: 0xF10B */
  ,{    4u,   4u,   4u,  78u,   0u,0x01u} /* DID: 0xF10D */
  ,{   10u,  10u,  10u,  79u,   0u,0x01u} /* DID: 0xF110 */
  ,{    1u,   1u,   1u,  80u,   0u,0x01u} /* DID: 0xF111 */
  ,{   10u,  10u,  10u,  81u,   0u,0x01u} /* DID: 0xF112 */
  ,{   90u,  90u,  90u,  82u,   0u,0x01u} /* DID: 0xF122 */
  ,{   10u,  10u,  10u,  83u,   0u,0x01u} /* DID: 0xF132 */
  ,{   10u,  10u,  10u,  84u,   0u,0x01u} /* DID: 0xF133 */
  ,{   11u,  11u,  11u,  85u,   0u,0x01u} /* DID: 0xF134 */
  ,{    2u,   2u,   2u,  86u,   0u,0x01u} /* DID: 0xF154 */
  ,{    2u,   2u,   2u,  87u,   0u,0x01u} /* DID: 0xF155 */
  ,{   14u,  14u,  14u,  88u,   0u,0x01u} /* DID: 0xF180 */
  ,{   66u,  66u,  66u,  89u,   0u,0x01u} /* DID: 0xF181 */
  ,{   40u,  40u,  40u,  90u,   0u,0x01u} /* DID: 0xF182 */
  ,{   14u,  14u,  14u,  91u,   0u,0x02u} /* DID: 0xF184 */
  ,{   14u,  14u,  14u,  92u,   0u,0x02u} /* DID: 0xF185 */
  ,{    3u,   3u,   3u,  93u,   0u,0x01u} /* DID: 0xF186 */
  ,{   11u,  11u,  11u,  94u,   0u,0x01u} /* DID: 0xF187 */
  ,{   11u,  11u,  11u,  95u,   0u,0x01u} /* DID: 0xF188 */
  ,{   10u,  10u,  10u,  96u,   0u,0x01u} /* DID: 0xF18A */
  ,{   10u,  10u,  10u,  97u,   0u,0x01u} /* DID: 0xF18B */
  ,{   15u,  15u,  15u,  98u,   0u,0x01u} /* DID: 0xF18C */
  ,{   17u,  17u,  17u,  99u,   0u,0x01u} /* DID: 0xF190 */
  ,{   11u,  11u,  11u, 100u,   0u,0x01u} /* DID: 0xF191 */
  ,{   11u,  11u,  11u, 101u,   0u,0x01u} /* DID: 0xF192 */
  ,{    1u,   1u,   1u, 102u,   0u,0x01u} /* DID: 0xF193 */
  ,{   11u,  11u,  11u, 103u,   0u,0x01u} /* DID: 0xF194 */
  ,{    2u,   2u,   2u, 104u,   0u,0x01u} /* DID: 0xF195 */
  ,{   90u,  90u,  90u, 105u,   0u,0x01u} /* DID: 0xF1A0 */
  ,{   11u,  11u,  11u, 106u,   0u,0x01u} /* DID: 0xF1A1 */
  ,{   10u,  10u,  10u, 107u,   0u,0x01u} /* DID: 0xF1A2 */
  ,{    3u,   3u,   3u, 108u,   0u,0x01u} /* DID: 0xF1A6 */
  ,{   17u,  17u,  17u, 109u,   0u,0x01u} /* DID: 0xF1B0 */
  ,{   15u,  15u,  15u, 110u,   0u,0x01u} /* DID: 0xF1B3 */
  ,{   71u,  71u,  71u, 111u,   0u,0x01u} /* DID: 0xF1B4 */
  ,{   43u,  43u,  43u, 112u,   0u,0x01u} /* DID: 0xF1B5 */
  ,{   54u,  54u,  54u, 113u,   0u,0x03u} /* DID: 0xFD00 */
  ,{   50u,  50u,  50u, 115u,   0u,0x01u} /* DID: 0xFD01 */
  ,{    0u,3072u,3072u, 116u,   0u,0x03u} /* DID: 0xFD04 */
  ,{    8u,   8u,   8u, 118u,   0u,0x01u} /* DID: 0xFD07 */
  ,{   28u,  28u,  28u, 119u,   0u,0x03u} /* DID: 0xFD08 */
  ,{   28u,  28u,  28u, 121u,   0u,0x03u} /* DID: 0xFD0A */
  ,{  256u, 256u, 256u, 123u,   0u,0x01u} /* DID: 0xFD0C */
  ,{  256u, 256u, 256u, 124u,   0u,0x01u} /* DID: 0xFD0D */
  ,{  256u, 256u, 256u, 125u,   0u,0x01u} /* DID: 0xFD0E */
  ,{  256u, 256u, 256u, 126u,   0u,0x01u} /* DID: 0xFD0F */
  ,{   32u,  32u,  32u, 127u,   0u,0x01u} /* DID: 0xFD13 */
  ,{    5u,   5u,   5u, 128u,   0u,0x01u} /* DID: 0xFD14 */
  ,{   13u,  13u,  13u, 129u,   0u,0x01u} /* DID: 0xFD15 */
  ,{   64u,  64u,  64u, 130u,   0u,0x01u} /* DID: 0xFD16 */
  ,{    3u,   3u,   3u, 131u,   0u,0x01u} /* DID: 0xFD17 */
  ,{   52u,  52u,  52u, 132u,   0u,0x01u} /* DID: 0xFD1C */
  ,{   14u,  14u,  14u, 133u,   0u,0x01u} /* DID: 0xFD1D */
  ,{   21u,  21u,  21u, 134u,   0u,0x01u} /* DID: 0xFD1E */
  ,{    2u,   2u,   2u, 135u,   0u,0x01u} /* DID: 0xFD20 */
  ,{   24u,  24u,  24u, 136u,   0u,0x01u} /* DID: 0xFD28 */
  ,{   24u,  24u,  24u, 137u,   0u,0x01u} /* DID: 0xFD29 */
  ,{   24u,  24u,  24u, 138u,   0u,0x01u} /* DID: 0xFD2A */
  ,{   24u,  24u,  24u, 139u,   0u,0x01u} /* DID: 0xFD2B */
  ,{   24u,  24u,  24u, 140u,   0u,0x01u} /* DID: 0xFD2C */
  ,{   48u,  48u,  48u, 141u,   0u,0x01u} /* DID: 0xFD2D */
  ,{   48u,  48u,  48u, 142u,   0u,0x01u} /* DID: 0xFD2E */
  ,{    4u,   4u,   4u, 143u,   0u,0x03u} /* DID: 0xFD31 */
  ,{   10u,  10u,  10u, 145u,   0u,0x03u} /* DID: 0xFD33 */
  ,{   16u,  16u,  16u, 147u,   0u,0x01u} /* DID: 0xFD38 */
  ,{    1u,   1u,   1u, 148u,   0u,0x03u} /* DID: 0xFD42 */
  ,{   14u,  14u,  14u, 150u,   0u,0x01u} /* DID: 0xFD43 */
  ,{    4u,   4u,   4u, 151u,   0u,0x01u} /* DID: 0xFD44 */
  ,{    8u,   8u,   8u, 152u,   0u,0x01u} /* DID: 0xFD46 */
  ,{   10u,  10u,  10u, 153u,   0u,0x01u} /* DID: 0xFD47 */
  ,{    4u,   4u,   4u, 154u,   0u,0x01u} /* DID: 0xFD48 */
  ,{   16u,  16u,  16u, 155u,   0u,0x01u} /* DID: 0xFD49 */
  ,{    9u,   9u,   9u, 156u,   0u,0x01u} /* DID: 0xFD4A */
  ,{    1u,   1u,   1u, 157u,   0u,0x02u} /* DID: 0xFD4E */
  ,{   14u,  14u,  14u, 158u,   0u,0x01u} /* DID: 0xFD60 */
  ,{   12u,  12u,  12u, 159u,   0u,0x01u} /* DID: 0xFD61 */
  ,{    2u,   2u,   2u, 160u,   0u,0x01u} /* DID: 0xFD62 */
  ,{  138u, 138u, 138u, 161u,   0u,0x01u} /* DID: 0xFD64 */
  ,{   28u,  28u,  28u, 162u,   0u,0x01u} /* DID: 0xFD65 */
  ,{    9u,   9u,   9u, 163u,   0u,0x01u} /* DID: 0xFD66 */
  ,{    4u,   4u,   4u, 164u,   0u,0x01u} /* DID: 0xFD67 */
  ,{    4u,   4u,   4u, 165u,   0u,0x01u} /* DID: 0xFD74 */
  ,{    6u,   6u,   6u, 166u,   0u,0x03u} /* DID: 0xFD86 */
  ,{    1u,   1u,   1u, 168u,   0u,0x03u} /* DID: 0xFDF0 */
  ,{    5u,   5u,   5u, 170u,   0u,0x01u} /* DID: 0xFDF1 */
  ,{    2u,   2u,   2u, 171u,   0u,0x01u} /* DID: 0xFDF2 */
  ,{    2u,   2u,   2u, 172u,   0u,0x03u} /* DID: 0xFDF5 */
  ,{  306u, 306u, 306u, 174u,   0u,0x01u} /* DID: 0xFDF6 */
  ,{   44u,  44u,  44u, 175u,   0u,0x01u} /* DID: 0xFDF7 */
  ,{   37u,  37u,  37u, 176u,   0u,0x01u} /* DID: 0xFDF8 */
};
/*! DID operation properties */
CONST(Dcm_CfgDidMgrDidOpInfoType, DCM_CONST) Dcm_CfgDidMgrDidOpInfo[177]=
{
   {    2u,   0u,0x01u} /* DID: 0x0103 */
  ,{    2u,   1u,0x01u} /* DID: 0x0107 */
  ,{    5u,   2u,0x01u} /* DID: 0x0107 */
  ,{    0u,   3u,0x01u} /* DID: 0x0108 */
  ,{    2u,   4u,0x01u} /* DID: 0x1002 */
  ,{    2u,   5u,0x01u} /* DID: 0x1004 */
  ,{    2u,   6u,0x01u} /* DID: 0x1008 */
  ,{    2u,   7u,0x01u} /* DID: 0x1009 */
  ,{    0u,   8u,0x01u} /* DID: 0x100B */
  ,{    0u,   9u,0x01u} /* DID: 0x100C */
  ,{    2u,  10u,0x01u} /* DID: 0x102A */
  ,{    2u,  11u,0x01u} /* DID: 0x191D */
  ,{    2u,  12u,0x01u} /* DID: 0x1921 */
  ,{    2u,  13u,0x01u} /* DID: 0x2001 */
  ,{    0u,  14u,0x01u} /* DID: 0x2002 */
  ,{    0u,  15u,0x01u} /* DID: 0x2003 */
  ,{    2u,  16u,0x01u} /* DID: 0x2008 */
  ,{    2u,  17u,0x01u} /* DID: 0x200A */
  ,{    2u,  18u,0x01u} /* DID: 0x200B */
  ,{    2u,  19u,0x01u} /* DID: 0x200C */
  ,{    2u,  20u,0x01u} /* DID: 0x200D */
  ,{    0u,  21u,0x01u} /* DID: 0x2010 */
  ,{    2u,  22u,0x01u} /* DID: 0x2013 */
  ,{    0u,  23u,0x01u} /* DID: 0x201A */
  ,{    0u,  24u,0x01u} /* DID: 0x201B */
  ,{    0u,  25u,0x01u} /* DID: 0x201F */
  ,{    2u,  26u,0x01u} /* DID: 0x2023 */
  ,{    2u,  27u,0x03u} /* DID: 0x2024 */
  ,{    2u,  29u,0x01u} /* DID: 0x2026 */
  ,{    8u,  30u,0x01u} /* DID: 0x2030 */
  ,{    8u,  31u,0x01u} /* DID: 0x2031 */
  ,{    8u,  32u,0x01u} /* DID: 0x2032 */
  ,{    2u,  33u,0x01u} /* DID: 0x292E */
  ,{    2u,  34u,0x01u} /* DID: 0x2939 */
  ,{    2u,  35u,0x01u} /* DID: 0x2945 */
  ,{    2u,  36u,0x01u} /* DID: 0x2945 */
  ,{    0u,  37u,0x01u} /* DID: 0x2951 */
  ,{    0u,  38u,0x01u} /* DID: 0x2954 */
  ,{    8u,  39u,0x01u} /* DID: 0x2957 */
  ,{    8u,  40u,0x01u} /* DID: 0x2958 */
  ,{    8u,  41u,0x01u} /* DID: 0x2959 */
  ,{    8u,  42u,0x01u} /* DID: 0x295A */
  ,{    8u,  43u,0x01u} /* DID: 0x295B */
  ,{    8u,  44u,0x01u} /* DID: 0x295C */
  ,{    8u,  45u,0x01u} /* DID: 0x295E */
  ,{    8u,  46u,0x01u} /* DID: 0x295F */
  ,{    2u,  47u,0x01u} /* DID: 0x4421 */
  ,{    2u,  48u,0x01u} /* DID: 0x4422 */
  ,{    2u,  49u,0x01u} /* DID: 0x4423 */
  ,{    2u,  50u,0x01u} /* DID: 0x4424 */
  ,{    2u,  51u,0x01u} /* DID: 0x4425 */
  ,{    2u,  52u,0x01u} /* DID: 0x4426 */
  ,{    2u,  53u,0x01u} /* DID: 0x4427 */
  ,{    2u,  54u,0x01u} /* DID: 0x4428 */
  ,{    2u,  55u,0x01u} /* DID: 0x4429 */
  ,{    2u,  56u,0x01u} /* DID: 0x442A */
  ,{    2u,  57u,0x01u} /* DID: 0x442B */
  ,{    2u,  58u,0x01u} /* DID: 0x442C */
  ,{    2u,  59u,0x01u} /* DID: 0x4451 */
  ,{    4u,  60u,0x01u} /* DID: 0x5001 */
  ,{    5u,  61u,0x09u} /* DID: 0x5001 */
  ,{    2u,  63u,0x01u} /* DID: 0x5100 */
  ,{    5u,  64u,0x01u} /* DID: 0x5102 */
  ,{    5u,  65u,0x01u} /* DID: 0x5103 */
  ,{    5u,  66u,0x01u} /* DID: 0x5104 */
  ,{    5u,  67u,0x01u} /* DID: 0x5105 */
  ,{    5u,  68u,0x01u} /* DID: 0x5107 */
  ,{    5u,  69u,0x01u} /* DID: 0x5109 */
  ,{    2u,  70u,0x01u} /* DID: 0x5201 */
  ,{    2u,  71u,0x01u} /* DID: 0x5300 */
  ,{    2u,  72u,0x01u} /* DID: 0x5301 */
  ,{    2u,  73u,0x01u} /* DID: 0x5302 */
  ,{    2u,  74u,0x01u} /* DID: 0x5303 */
  ,{    2u,  75u,0x01u} /* DID: 0x5304 */
  ,{    2u,  76u,0x01u} /* DID: 0x5305 */
  ,{    5u,  77u,0x01u} /* DID: 0x5500 */
  ,{    5u,  78u,0x01u} /* DID: 0x5501 */
  ,{    2u,  79u,0x01u} /* DID: 0xF10B */
  ,{    0u,  80u,0x01u} /* DID: 0xF10D */
  ,{    0u,  81u,0x01u} /* DID: 0xF110 */
  ,{    8u,  82u,0x01u} /* DID: 0xF111 */
  ,{    0u,  83u,0x01u} /* DID: 0xF112 */
  ,{    0u,  84u,0x01u} /* DID: 0xF122 */
  ,{    0u,  85u,0x01u} /* DID: 0xF132 */
  ,{    0u,  86u,0x01u} /* DID: 0xF133 */
  ,{    0u,  87u,0x01u} /* DID: 0xF134 */
  ,{    0u,  88u,0x01u} /* DID: 0xF154 */
  ,{    0u,  89u,0x01u} /* DID: 0xF155 */
  ,{    0u,  90u,0x01u} /* DID: 0xF180 */
  ,{    2u,  91u,0x01u} /* DID: 0xF181 */
  ,{    2u,  92u,0x01u} /* DID: 0xF182 */
  ,{    6u,  93u,0x01u} /* DID: 0xF184 */
  ,{    6u,  94u,0x01u} /* DID: 0xF185 */
  ,{    0u,  95u,0x01u} /* DID: 0xF186 */
  ,{    0u,  96u,0x01u} /* DID: 0xF187 */
  ,{    0u,  97u,0x01u} /* DID: 0xF188 */
  ,{    0u,  98u,0x01u} /* DID: 0xF18A */
  ,{    0u,  99u,0x01u} /* DID: 0xF18B */
  ,{    0u, 100u,0x01u} /* DID: 0xF18C */
  ,{    2u, 101u,0x01u} /* DID: 0xF190 */
  ,{    0u, 102u,0x01u} /* DID: 0xF191 */
  ,{    0u, 103u,0x01u} /* DID: 0xF192 */
  ,{    0u, 104u,0x01u} /* DID: 0xF193 */
  ,{    0u, 105u,0x01u} /* DID: 0xF194 */
  ,{    0u, 106u,0x01u} /* DID: 0xF195 */
  ,{    0u, 107u,0x01u} /* DID: 0xF1A0 */
  ,{    2u, 108u,0x01u} /* DID: 0xF1A1 */
  ,{    0u, 109u,0x01u} /* DID: 0xF1A2 */
  ,{    2u, 110u,0x01u} /* DID: 0xF1A6 */
  ,{    2u, 111u,0x01u} /* DID: 0xF1B0 */
  ,{    0u, 112u,0x01u} /* DID: 0xF1B3 */
  ,{    0u, 113u,0x01u} /* DID: 0xF1B4 */
  ,{    0u, 114u,0x01u} /* DID: 0xF1B5 */
  ,{    2u, 115u,0x01u} /* DID: 0xFD00 */
  ,{    4u, 116u,0x01u} /* DID: 0xFD00 */
  ,{    2u, 117u,0x01u} /* DID: 0xFD01 */
  ,{    5u, 118u,0x03u} /* DID: 0xFD04 */
  ,{    5u, 120u,0x01u} /* DID: 0xFD04 */
  ,{    2u, 121u,0x01u} /* DID: 0xFD07 */
  ,{    2u, 122u,0x01u} /* DID: 0xFD08 */
  ,{    4u, 123u,0x01u} /* DID: 0xFD08 */
  ,{    2u, 124u,0x01u} /* DID: 0xFD0A */
  ,{    4u, 125u,0x01u} /* DID: 0xFD0A */
  ,{    2u, 126u,0x01u} /* DID: 0xFD0C */
  ,{    2u, 127u,0x01u} /* DID: 0xFD0D */
  ,{    2u, 128u,0x01u} /* DID: 0xFD0E */
  ,{    2u, 129u,0x01u} /* DID: 0xFD0F */
  ,{    2u, 130u,0x01u} /* DID: 0xFD13 */
  ,{    2u, 131u,0x01u} /* DID: 0xFD14 */
  ,{    2u, 132u,0x01u} /* DID: 0xFD15 */
  ,{    2u, 133u,0x01u} /* DID: 0xFD16 */
  ,{    2u, 134u,0x01u} /* DID: 0xFD17 */
  ,{    2u, 135u,0x01u} /* DID: 0xFD1C */
  ,{    2u, 136u,0x01u} /* DID: 0xFD1D */
  ,{    2u, 137u,0x01u} /* DID: 0xFD1E */
  ,{    2u, 138u,0x01u} /* DID: 0xFD20 */
  ,{    2u, 139u,0x01u} /* DID: 0xFD28 */
  ,{    2u, 140u,0x01u} /* DID: 0xFD29 */
  ,{    2u, 141u,0x01u} /* DID: 0xFD2A */
  ,{    2u, 142u,0x01u} /* DID: 0xFD2B */
  ,{    2u, 143u,0x01u} /* DID: 0xFD2C */
  ,{    2u, 144u,0x01u} /* DID: 0xFD2D */
  ,{    2u, 145u,0x01u} /* DID: 0xFD2E */
  ,{    2u, 146u,0x01u} /* DID: 0xFD31 */
  ,{    4u, 147u,0x01u} /* DID: 0xFD31 */
  ,{    2u, 148u,0x01u} /* DID: 0xFD33 */
  ,{    4u, 149u,0x01u} /* DID: 0xFD33 */
  ,{    0u, 150u,0x01u} /* DID: 0xFD38 */
  ,{    2u, 151u,0x01u} /* DID: 0xFD42 */
  ,{    4u, 152u,0x01u} /* DID: 0xFD42 */
  ,{    2u, 153u,0x01u} /* DID: 0xFD43 */
  ,{    2u, 154u,0x01u} /* DID: 0xFD44 */
  ,{    2u, 155u,0x01u} /* DID: 0xFD46 */
  ,{    2u, 156u,0x01u} /* DID: 0xFD47 */
  ,{    2u, 157u,0x01u} /* DID: 0xFD48 */
  ,{    2u, 158u,0x01u} /* DID: 0xFD49 */
  ,{    2u, 159u,0x01u} /* DID: 0xFD4A */
  ,{    4u, 160u,0x01u} /* DID: 0xFD4E */
  ,{    2u, 161u,0x01u} /* DID: 0xFD60 */
  ,{    2u, 162u,0x01u} /* DID: 0xFD61 */
  ,{    2u, 163u,0x01u} /* DID: 0xFD62 */
  ,{    2u, 164u,0x01u} /* DID: 0xFD64 */
  ,{    2u, 165u,0x01u} /* DID: 0xFD65 */
  ,{    2u, 166u,0x01u} /* DID: 0xFD66 */
  ,{    2u, 167u,0x01u} /* DID: 0xFD67 */
  ,{    2u, 168u,0x01u} /* DID: 0xFD74 */
  ,{    2u, 169u,0x01u} /* DID: 0xFD86 */
  ,{    4u, 170u,0x01u} /* DID: 0xFD86 */
  ,{    2u, 171u,0x01u} /* DID: 0xFDF0 */
  ,{    2u, 172u,0x01u} /* DID: 0xFDF0 */
  ,{    2u, 173u,0x01u} /* DID: 0xFDF1 */
  ,{    2u, 174u,0x01u} /* DID: 0xFDF2 */
  ,{    2u, 175u,0x01u} /* DID: 0xFDF5 */
  ,{    2u, 176u,0x01u} /* DID: 0xFDF5 */
  ,{    2u, 177u,0x01u} /* DID: 0xFDF6 */
  ,{    2u, 178u,0x01u} /* DID: 0xFDF7 */
  ,{    2u, 179u,0x01u} /* DID: 0xFDF8 */
};
/*! DID operation classes */
CONST(Dcm_CfgDidMgrDidOpClassInfoType, DCM_CONST) Dcm_CfgDidMgrDidOpClassInfo[181]=
{
   {  0u}
  ,{  1u}
  ,{  2u}
  ,{  3u}
  ,{  4u}
  ,{  5u}
  ,{  6u}
  ,{  7u}
  ,{  8u}
  ,{  9u}
  ,{ 10u}
  ,{ 11u}
  ,{ 12u}
  ,{ 13u}
  ,{ 14u}
  ,{ 15u}
  ,{ 16u}
  ,{ 17u}
  ,{ 18u}
  ,{ 19u}
  ,{ 20u}
  ,{ 21u}
  ,{ 22u}
  ,{ 23u}
  ,{ 24u}
  ,{ 25u}
  ,{ 26u}
  ,{ 27u}
  ,{ 28u}
  ,{ 29u}
  ,{ 30u}
  ,{ 31u}
  ,{ 32u}
  ,{ 33u}
  ,{ 34u}
  ,{ 35u}
  ,{ 36u}
  ,{ 37u}
  ,{ 38u}
  ,{ 39u}
  ,{ 40u}
  ,{ 41u}
  ,{ 42u}
  ,{ 43u}
  ,{ 44u}
  ,{ 45u}
  ,{ 46u}
  ,{ 47u}
  ,{ 48u}
  ,{ 49u}
  ,{ 50u}
  ,{ 51u}
  ,{ 52u}
  ,{ 53u}
  ,{ 54u}
  ,{ 55u}
  ,{ 56u}
  ,{ 57u}
  ,{ 58u}
  ,{ 59u}
  ,{ 60u}
  ,{ 61u}
  ,{ 62u}
  ,{ 63u}
  ,{ 64u}
  ,{ 65u}
  ,{ 66u}
  ,{ 67u}
  ,{ 68u}
  ,{ 69u}
  ,{ 70u}
  ,{ 71u}
  ,{ 72u}
  ,{ 73u}
  ,{ 74u}
  ,{ 75u}
  ,{ 76u}
  ,{ 77u}
  ,{ 78u}
  ,{ 79u}
  ,{ 80u}
  ,{ 81u}
  ,{ 82u}
  ,{ 83u}
  ,{ 84u}
  ,{ 85u}
  ,{ 86u}
  ,{ 87u}
  ,{ 88u}
  ,{ 89u}
  ,{ 90u}
  ,{ 91u}
  ,{ 92u}
  ,{ 93u}
  ,{ 94u}
  ,{ 95u}
  ,{ 96u}
  ,{ 97u}
  ,{ 98u}
  ,{ 99u}
  ,{ 100u}
  ,{ 101u}
  ,{ 102u}
  ,{ 103u}
  ,{ 104u}
  ,{ 105u}
  ,{ 106u}
  ,{ 107u}
  ,{ 108u}
  ,{ 109u}
  ,{ 110u}
  ,{ 111u}
  ,{ 112u}
  ,{ 113u}
  ,{ 114u}
  ,{ 115u}
  ,{ 116u}
  ,{ 117u}
  ,{ 118u}
  ,{ 119u}
  ,{ 120u}
  ,{ 121u}
  ,{ 122u}
  ,{ 123u}
  ,{ 124u}
  ,{ 125u}
  ,{ 126u}
  ,{ 127u}
  ,{ 128u}
  ,{ 129u}
  ,{ 130u}
  ,{ 131u}
  ,{ 132u}
  ,{ 133u}
  ,{ 134u}
  ,{ 135u}
  ,{ 136u}
  ,{ 137u}
  ,{ 138u}
  ,{ 139u}
  ,{ 140u}
  ,{ 141u}
  ,{ 142u}
  ,{ 143u}
  ,{ 144u}
  ,{ 145u}
  ,{ 146u}
  ,{ 147u}
  ,{ 148u}
  ,{ 149u}
  ,{ 150u}
  ,{ 151u}
  ,{ 152u}
  ,{ 153u}
  ,{ 154u}
  ,{ 155u}
  ,{ 156u}
  ,{ 157u}
  ,{ 158u}
  ,{ 159u}
  ,{ 160u}
  ,{ 161u}
  ,{ 162u}
  ,{ 163u}
  ,{ 164u}
  ,{ 165u}
  ,{ 166u}
  ,{ 167u}
  ,{ 168u}
  ,{ 169u}
  ,{ 170u}
  ,{ 171u}
  ,{ 172u}
  ,{ 173u}
  ,{ 174u}
  ,{ 175u}
  ,{ 176u}
  ,{ 177u}
  ,{ 178u}
  ,{ 179u}
  ,{ 180u}
};
/*! DID signal operation classes */
CONST(Dcm_CfgDidMgrSignalOpClassInfoType, DCM_CONST) Dcm_CfgDidMgrSignalOpClassInfo[180]=
{
   { ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_220103_VIN_Lock_Status_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0103 */                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_220107_RoE_Activation_State_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0107 */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_220107_RoE_Activation_State_WriteData)),   1u,   1u,0x1002u} /* DID: 0x0107 */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_ReadData)),   4u,   4u,0x0002u} /* DID: 0x0108 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_221002_Vehicle_Speed_ReadData)),   2u,   2u,0x0002u} /* DID: 0x1002 */                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_221004_Battery_Voltage_ReadData)),   1u,   1u,0x0002u} /* DID: 0x1004 */                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_221008_ECU_Life_Time_ReadData)),   3u,   3u,0x0002u} /* DID: 0x1008 */                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_221009_ECU_Time_Since_Ignition_ON_ReadData)),   2u,   2u,0x0002u} /* DID: 0x1009 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22100B_Diagnostic_Tool_and_Session_Status_ReadData)),   1u,   1u,0x0002u} /* DID: 0x100B */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22100C_Security_Status_Read_ReadData)),   5u,   5u,0x0002u} /* DID: 0x100C */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22102A_Check_EOL_Configuration_Data_ReadData)),   9u,   9u,0x0002u} /* DID: 0x102A */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22191D_Time_of_Power_Latch_ReadData)),   1u,   1u,0x0002u} /* DID: 0x191D */                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_221921_Operational_Mode_Status_ReadData)),   9u,   9u,0x0002u} /* DID: 0x1921 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222001_Odometer_ReadData)),   2u,   2u,0x0002u} /* DID: 0x2001 */                            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222002_Odometer_at_last_Flash_programming_ReadData)),   2u,   2u,0x0002u} /* DID: 0x2002 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_ReadData)),   4u,   4u,0x0002u} /* DID: 0x2003 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222008_ECU_Life_Time_Not_Volatile_Memory_ReadData)),   3u,   3u,0x0002u} /* DID: 0x2008 */   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22200A_Ignition_ON_Counter_ReadData)),   2u,   2u,0x0002u} /* DID: 0x200A */                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22200B_Time_First_DTC_Detection_ReadData)),   3u,   3u,0x0002u} /* DID: 0x200B */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22200C_Time_Since_Ignition_ON_of_first_DTC_Detection_ReadData)),   2u,   2u,0x0002u} /* DID: 0x200C */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22200D_Odometer_Last_Clear_Data_Trouble_Code_DTC_ReadData)),   2u,   2u,0x0002u} /* DID: 0x200D */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222010_Programming_Status_ReadData)),   2u,   2u,0x0002u} /* DID: 0x2010 */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222013_VIN_Lock_State_Read_ReadData)),   1u,   1u,0x0002u} /* DID: 0x2013 */                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_ReadData)),  20u,  20u,0x0002u} /* DID: 0x201A */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_ReadData)),  12u,  12u,0x0002u} /* DID: 0x201B */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22201F_Boot_Failure_Reason_Read_ReadData)),   2u,   2u,0x0002u} /* DID: 0x201F */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_2E2023_PROXI_Data_WriteData)),   0u, 255u,0x1004u} /* DID: 0x2023 */                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222024_Read_ECU_PROXI_Data_ReadData)),   0u, 255u,0x0002u} /* DID: 0x2024 */                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222024_Read_ECU_PROXI_Data_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x2024 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222026_CAN_Overrun_Counters_ReadData)),   8u,   8u,0x0002u} /* DID: 0x2026 */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_ReadData)), 960u, 960u,0x0002u} /* DID: 0x2030 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222031_Disallowed_Certificate_List_Read_ReadData)),3072u,3072u,0x0002u} /* DID: 0x2031 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222032_Secure_Log_Read_ReadData)),1296u,1296u,0x0002u} /* DID: 0x2032 */                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22292E_PROXI_Write_Counter_ReadData)),   1u,   1u,0x0002u} /* DID: 0x292E */                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222939_FDCAN2_BUS_Network_WakeUp_Reason_ReadData)),  24u,  24u,0x0002u} /* DID: 0x2939 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222945_Flow_Control_Test_ReadData)), 200u, 200u,0x0002u} /* DID: 0x2945 */                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222945_Flow_Control_Test_WriteData)), 200u, 200u,0x1002u} /* DID: 0x2945 */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222951_Certificate_Store_UUID_Read_ReadData)),  16u,  16u,0x0002u} /* DID: 0x2951 */         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222954_Policy_Type_Read_ReadData)),   1u,   1u,0x0002u} /* DID: 0x2954 */                    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_ReadData)),1056u,1056u,0x0002u} /* DID: 0x2957 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_ReadData)),  96u,  96u,0x0002u} /* DID: 0x2958 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_ReadData)), 352u, 352u,0x0002u} /* DID: 0x2959 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_ReadData)),  32u,  32u,0x0002u} /* DID: 0x295A */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22295B_HTA_Header_Info_Read_ReadData)), 176u, 176u,0x0002u} /* DID: 0x295B */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22295C_HTA_Header_UUID_Read_ReadData)),  16u,  16u,0x0002u} /* DID: 0x295C */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22295E_DCL_Header_UUID_Read_ReadData)),  16u,  16u,0x0002u} /* DID: 0x295E */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_ReadData)), 176u, 176u,0x0002u} /* DID: 0x295F */   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_224421_USS_Sensor_1_Part_Number_Read_ReadData)),  13u,  13u,0x0002u} /* DID: 0x4421 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_224422_USS_Sensor2_Part_Number_Read_ReadData)),  13u,  13u,0x0002u} /* DID: 0x4422 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_224423_USS_Sensor_3_Part_Number_Read_ReadData)),  13u,  13u,0x0002u} /* DID: 0x4423 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_224424_USS_Sensor_4_Part_Number_Read_ReadData)),  13u,  13u,0x0002u} /* DID: 0x4424 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_224425_USS_Sensor_5_Part_Number_Read_ReadData)),  13u,  13u,0x0002u} /* DID: 0x4425 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_224426_USS_Sensor_6_Part_Number_Read_ReadData)),  13u,  13u,0x0002u} /* DID: 0x4426 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_224427_USS_Sensor_7_Part_Number_Read_ReadData)),  13u,  13u,0x0002u} /* DID: 0x4427 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_224428_USS_Sensor_8_Part_Number_Read_ReadData)),  13u,  13u,0x0002u} /* DID: 0x4428 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_224429_USS_Sensor_9_Part_Number_Read_ReadData)),  13u,  13u,0x0002u} /* DID: 0x4429 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22442A_USS_Sensor_10_Part_Number_Read_ReadData)),  13u,  13u,0x0002u} /* DID: 0x442A */      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22442B_USS_Sensor_11_Part_Number_Read_ReadData)),  13u,  13u,0x0002u} /* DID: 0x442B */      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22442C_USS_Sensor_12_Part_Number_Read_ReadData)),  13u,  13u,0x0002u} /* DID: 0x442C */      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_224451_EOL_Calibration_State_Read_ReadData)),  44u,  44u,0x0002u} /* DID: 0x4451 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_2F5001_Gear_Position_Read_ReadData)),   1u,   1u,0x0002u} /* DID: 0x5001 */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_2F5001_Gear_Position_Read_ReturnControlToECU)),   1u,   1u,0x2003u} /* DID: 0x5001 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_2F5001_Gear_Position_Read_ShortTermAdjustment)),   1u,   1u,0x2004u} /* DID: 0x5001 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225100_SPM_status_Read_ReadData)),   4u,   4u,0x0002u} /* DID: 0x5100 */                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225102_FD_CAN14_Rx_Signals_Read_ReadData)),  34u,  34u,0x0002u} /* DID: 0x5102 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225103_FD_CAN2_Rx_Signals_Read_ReadData)),  41u,  41u,0x0002u} /* DID: 0x5103 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225104_FD_CAN14_Tx_Signals_Read_ReadData)),   5u,   5u,0x0002u} /* DID: 0x5104 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225105_FD_CAN2_Tx_Signals_Read_ReadData)),  19u,  19u,0x0002u} /* DID: 0x5105 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225107_Front_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData)),  15u,  15u,0x0002u} /* DID: 0x5107 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225109_Rear_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData)),  15u,  15u,0x0002u} /* DID: 0x5109 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225201_Plant_Mode_Status_Read_ReadData)),   1u,   1u,0x0002u} /* DID: 0x5201 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225300_Rear_Braking_Event_1_Read_ReadData)),  14u,  14u,0x0002u} /* DID: 0x5300 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225301_Rear_Braking_Event_2_Read_ReadData)),  14u,  14u,0x0002u} /* DID: 0x5301 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225302_Rear_Braking_Event_3_Read_ReadData)),  14u,  14u,0x0002u} /* DID: 0x5302 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225303_SPM_Event_Abort_1_Read_ReadData)),  12u,  12u,0x0002u} /* DID: 0x5303 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225304_SPM_Event_Abort_2_Read_ReadData)),  12u,  12u,0x0002u} /* DID: 0x5304 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225305_SPM_Event_Abort_3_Read_ReadData)),  12u,  12u,0x0002u} /* DID: 0x5305 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225500_Trailer_Sense_and_Drive_Function_Data_Read_ReadData)),  42u,  42u,0x0002u} /* DID: 0x5500 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_225501_Trailer_coupler_sense_detection_Function_Data_Read_ReadData)),  48u,  48u,0x0002u} /* DID: 0x5501 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F10B_ECU_Qualification_ReadData)),   2u,   2u,0x0002u} /* DID: 0xF10B */                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F10D_Diagnostic_Specification_Information_ReadData)),   4u,   4u,0x0002u} /* DID: 0xF10D */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F110_ECU_Diagnostic_Identification_ReadData)),  10u,  10u,0x0002u} /* DID: 0xF110 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF111 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F112_PTESLM_Hardware_Number_ReadData)),  10u,  10u,0x0002u} /* DID: 0xF112 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F122_Software_EBOM_Part_Number_ReadData)),  90u,  90u,0x0002u} /* DID: 0xF122 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F132_EBOM_ECU_Part_Number_ReadData)),  10u,  10u,0x0002u} /* DID: 0xF132 */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F133_EBOM_Assembly_Part_Number_ReadData)),  10u,  10u,0x0002u} /* DID: 0xF133 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F134_CODEP_assembly_part_number_ReadData)),  11u,  11u,0x0002u} /* DID: 0xF134 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F154_Hardware_Supplier_Identification_ReadData)),   2u,   2u,0x0002u} /* DID: 0xF154 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F155_Software_Supplier_Identification_ReadData)),   2u,   2u,0x0002u} /* DID: 0xF155 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F180_Boot_Software_Version_Information_ReadData)),  14u,  14u,0x0002u} /* DID: 0xF180 */   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F181_Application_Software_Identification_ReadData)),  66u,  66u,0x0002u} /* DID: 0xF181 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F182_Application_Data_Identification_ReadData)),  40u,  40u,0x0002u} /* DID: 0xF182 */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_2EF184_Application_Software_Fingerprint_writing_information_WriteData)),  14u,  14u,0x1002u} /* DID: 0xF184 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_2EF185_Application_Data_Software_Fingerprint_Writing_Information_WriteData)),  14u,  14u,0x1002u} /* DID: 0xF185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F186_Active_Diagnostic_Session_ReadData)),   3u,   3u,0x0002u} /* DID: 0xF186 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F187_CODEP_ECU_Part_Number_ReadData)),  11u,  11u,0x0002u} /* DID: 0xF187 */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_ReadData)),  11u,  11u,0x0002u} /* DID: 0xF188 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_ReadData)),  10u,  10u,0x0002u} /* DID: 0xF18A */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_ReadData)),  10u,  10u,0x0002u} /* DID: 0xF18B */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F18C_ECU_Serial_Number_ReadData)),  15u,  15u,0x0002u} /* DID: 0xF18C */                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F190_VIN_Original_ReadData)),  17u,  17u,0x0002u} /* DID: 0xF190 */                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_ReadData)),  11u,  11u,0x0002u} /* DID: 0xF191 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_ReadData)),  11u,  11u,0x0002u} /* DID: 0xF192 */   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF193 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_ReadData)),  11u,  11u,0x0002u} /* DID: 0xF194 */   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_ReadData)),   2u,   2u,0x0002u} /* DID: 0xF195 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F1A0_System_Identification_Data_ReadData)),  90u,  90u,0x0002u} /* DID: 0xF1A0 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F1A1_Configuration_Code_ReadData)),  11u,  11u,0x0002u} /* DID: 0xF1A1 */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F1A2_Vector_Delivery_ID_ReadData)),  10u,  10u,0x0002u} /* DID: 0xF1A2 */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F1A6_Message_Matrix_ReadData)),   3u,   3u,0x0002u} /* DID: 0xF1A6 */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F1B0_VIN_Current_ReadData)),  17u,  17u,0x0002u} /* DID: 0xF1B0 */                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_ReadData)),  15u,  15u,0x0002u} /* DID: 0xF1B3 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_ReadData)),  71u,  71u,0x0002u} /* DID: 0xF1B4 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_ReadData)),  43u,  43u,0x0002u} /* DID: 0xF1B5 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD00_Plant_Camera_Calibration_Data_ReadData)),  54u,  54u,0x0002u} /* DID: 0xFD00 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD00_Plant_Camera_Calibration_Data_WriteData)),  54u,  54u,0x1002u} /* DID: 0xFD00 */      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD01_Previous_Camera_Calibration_Data_ReadData)),  50u,  50u,0x0002u} /* DID: 0xFD01 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadData)),   0u,3072u,0x0002u} /* DID: 0xFD04 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_WriteData)),   0u,3072u,0x1004u} /* DID: 0xFD04 */      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD07_OC_Result_Read_ReadData)),   8u,   8u,0x0002u} /* DID: 0xFD07 */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD08_OC_Data_Read_ReadData)),  28u,  28u,0x0002u} /* DID: 0xFD08 */                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD08_OC_Data_Read_WriteData)),  28u,  28u,0x1002u} /* DID: 0xFD08 */                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD0A_SC_Data_Read_ReadData)),  28u,  28u,0x0002u} /* DID: 0xFD0A */                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD0A_SC_Data_Read_WriteData)),  28u,  28u,0x1002u} /* DID: 0xFD0A */                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD0C_Front_Camera_Data_EEPROM_Read_ReadData)), 256u, 256u,0x0002u} /* DID: 0xFD0C */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD0D_Left_Camera_Data_EEPROM_Read_ReadData)), 256u, 256u,0x0002u} /* DID: 0xFD0D */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD0E_Rear_Camera_Data_EEPROM_Read_ReadData)), 256u, 256u,0x0002u} /* DID: 0xFD0E */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD0F_Right_Camera_Data_EEPROM_Read_ReadData)), 256u, 256u,0x0002u} /* DID: 0xFD0F */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD13_Magna_Software_Version_ReadData)),  32u,  32u,0x0002u} /* DID: 0xFD13 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_ReadData)),   5u,   5u,0x0002u} /* DID: 0xFD14 */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD15_Magna_Production_HW_Number_Read_ReadData)),  13u,  13u,0x0002u} /* DID: 0xFD15 */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_ReadData)),  64u,  64u,0x0002u} /* DID: 0xFD16 */      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_ReadData)),   3u,   3u,0x0002u} /* DID: 0xFD17 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD1C_Current_Camera_Calibration_Data_Read_ReadData)),  52u,  52u,0x0002u} /* DID: 0xFD1C */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD1D_PCB_Serial_Number_ReadData)),  14u,  14u,0x0002u} /* DID: 0xFD1D */                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD1E_Calibration_Status_Read_ReadData)),  21u,  21u,0x0002u} /* DID: 0xFD1E */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD20_ECU_PinStates_Read_ReadData)),   2u,   2u,0x0002u} /* DID: 0xFD20 */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD28_USS_Ringing_Frequency_Read_ReadData)),  24u,  24u,0x0002u} /* DID: 0xFD28 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD29_USS_Driving_Frequency_Read_ReadData)),  24u,  24u,0x0002u} /* DID: 0xFD29 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD2A_USS_Ringing_Time_Read_ReadData)),  24u,  24u,0x0002u} /* DID: 0xFD2A */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD2B_USS_Direct_Distance_0xFD2B_Read_ReadData)),  24u,  24u,0x0002u} /* DID: 0xFD2B */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD2C_USS_Temperature_Read_ReadData)),  24u,  24u,0x0002u} /* DID: 0xFD2C */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD2D_USS_Sensor_ID_IME_SN_Read_ReadData)),  48u,  48u,0x0002u} /* DID: 0xFD2D */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD2E_USS_Sensor_ID_Murata_SN_Read_ReadData)),  48u,  48u,0x0002u} /* DID: 0xFD2E */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_ReadData)),   4u,   4u,0x0002u} /* DID: 0xFD31 */         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_WriteData)),   4u,   4u,0x1002u} /* DID: 0xFD31 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD33_Magna_Testing_2_Read_ReadData)),  10u,  10u,0x0002u} /* DID: 0xFD33 */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD33_Magna_Testing_2_Read_WriteData)),  10u,  10u,0x1002u} /* DID: 0xFD33 */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD38_Programmed_Assembly_ReadData)),  16u,  16u,0x0002u} /* DID: 0xFD38 */                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD42_Failsafe_Behaviour_Read_ReadData)),   1u,   1u,0x0002u} /* DID: 0xFD42 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD42_Failsafe_Behaviour_Read_WriteData)),   1u,   1u,0x1002u} /* DID: 0xFD42 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD43_Active_Safe_State_Read_ReadData)),  14u,  14u,0x0002u} /* DID: 0xFD43 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD44_Error_Flags_Read_ReadData)),   4u,   4u,0x0002u} /* DID: 0xFD44 */                    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD46_Camera_Power_Supply_Read_ReadData)),   8u,   8u,0x0002u} /* DID: 0xFD46 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD47_SoC_Temperature_0xFD47_Read_ReadData)),  10u,  10u,0x0002u} /* DID: 0xFD47 */         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD48_PCBA_Temperature_Read_ReadData)),   4u,   4u,0x0002u} /* DID: 0xFD48 */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD49_SoC_Die_Temperature_ID_0xFD49_Read_ReadData)),  16u,  16u,0x0002u} /* DID: 0xFD49 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD4A_Ultrasonic_Sensors_Power_supply_and_Current_Level_Read_ReadData)),   9u,   9u,0x0002u} /* DID: 0xFD4A */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_2EFD4E_Reset_NVM_Write_WriteData)),   1u,   1u,0x1002u} /* DID: 0xFD4E */                    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD60_ECU_Software_Status_Read_ReadData)),  14u,  14u,0x0002u} /* DID: 0xFD60 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD61_Vehicle_Variant_Coding_Data_Read_ReadData)),  12u,  12u,0x0002u} /* DID: 0xFD61 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD62_ASIL_QM_Fault_Status_Read_ReadData)),   2u,   2u,0x0002u} /* DID: 0xFD62 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD64_ASIL_B_Fault_Status_Read_ReadData)), 138u, 138u,0x0002u} /* DID: 0xFD64 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD65_FuSa_Module_Status_Read_ReadData)),  28u,  28u,0x0002u} /* DID: 0xFD65 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD66_Camera_occlusion_and_low_light_status_Read_ReadData)),   9u,   9u,0x0002u} /* DID: 0xFD66 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD67_Camera_DLD_Status_Read_ReadData)),   4u,   4u,0x0002u} /* DID: 0xFD67 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD74_PHY_Tunning_Error_And_Buffer_Mark_Error_Read_ReadData)),   4u,   4u,0x0002u} /* DID: 0xFD74 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD86_Functional_Settings_Read_ReadData)),   6u,   6u,0x0002u} /* DID: 0xFD86 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FD86_Functional_Settings_Read_WriteData)),   6u,   6u,0x1002u} /* DID: 0xFD86 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FDF0_ECU_shutdown_process_Read_ReadData)),   1u,   1u,0x0002u} /* DID: 0xFDF0 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FDF0_ECU_shutdown_process_Read_WriteData)),   1u,   1u,0x1002u} /* DID: 0xFDF0 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FDF1_CPU_Load_Read_ReadData)),   5u,   5u,0x0002u} /* DID: 0xFDF1 */                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FDF2_Reset_Reason_Read_ReadData)),   2u,   2u,0x0002u} /* DID: 0xFDF2 */                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FDF5_PerformanceStatEnable_Read_ReadData)),   2u,   2u,0x0002u} /* DID: 0xFDF5 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FDF5_PerformanceStatEnable_Read_WriteData)),   2u,   2u,0x1002u} /* DID: 0xFDF5 */         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FDF6_RunTimeStatsData_Read_ReadData)), 306u, 306u,0x0002u} /* DID: 0xFDF6 */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FDF7_Intrinsic_Camera_NvM_Data_Read_ReadData)),  44u,  44u,0x0002u} /* DID: 0xFDF7 */      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_22FDF8_StackUsage_Read_ReadData)),  37u,  37u,0x0002u} /* DID: 0xFDF8 */                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! IO control DID operation properties */
CONST(Dcm_CfgDidMgrOpInfoIoControlType, DCM_CONST) Dcm_CfgDidMgrOpInfoIoControl[1]=
{
   {   61u,   5u, 0u, 0u} /* DID: 0x5001 */
};
/*! Bridge for combined DID operation properties */
CONST(Dcm_CfgDidMgrOpInfoCombinedType, DCM_CONST) Dcm_CfgDidMgrOpInfoCombined[1]=
{
   {    0u,   0u} /* DID: 0x5001 */
};
/*! RID properties */
CONST(Dcm_CfgRidMgrRidInfoType, DCM_CONST) Dcm_CfgRidMgrRidInfo[20]=
{
   {    0u,   9u,0x01u, 0u} /* RID: 0x1000 */
  ,{    1u,   5u,0x01u, 0u} /* RID: 0x2000 */
  ,{    2u,   5u,0x01u, 0u} /* RID: 0x2001 */
  ,{    3u,   9u,0x01u, 0u} /* RID: 0x3000 */
  ,{    4u,  10u,0x01u, 0u} /* RID: 0x5000 */
  ,{    5u,   9u,0x01u, 0u} /* RID: 0x5101 */
  ,{    6u,   9u,0x05u, 0u} /* RID: 0x5200 */
  ,{    8u,   4u,0x05u, 0u} /* RID: 0x5400 */
  ,{   10u,   4u,0x05u, 0u} /* RID: 0x5401 */
  ,{   12u,   4u,0x05u, 0u} /* RID: 0x5502 */
  ,{   14u,  10u,0x03u, 0u} /* RID: 0xD001 */
  ,{   16u,   0u,0x01u, 0u} /* RID: 0xD002 */
  ,{   17u,   6u,0x01u, 0u} /* RID: 0xD003 */
  ,{   18u,   6u,0x01u, 0u} /* RID: 0xF000 */
  ,{   19u,  10u,0x01u, 0u} /* RID: 0xFE01 */
  ,{   20u,   4u,0x01u, 0u} /* RID: 0xFE02 */
  ,{   21u,  10u,0x03u, 0u} /* RID: 0xFE0E */
  ,{   23u,   6u,0x01u, 0u} /* RID: 0xFF00 */
  ,{   24u,   6u,0x01u, 0u} /* RID: 0xFF01 */
  ,{   25u,   4u,0x01u, 0u} /* RID: 0xFF03 */
};
/*! RID operation properties */
CONST(Dcm_CfgRidMgrOpInfoType, DCM_CONST) Dcm_CfgRidMgrOpInfo[26]=
{
   { ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Start)),   1u,   1u,   1u,   1u, 2u, 0u} /* RID: 0x1000 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_31012000_Original_VIN_Lock_Start)),   0u,   0u,   0u,   0u, 0u, 0u} /* RID: 0x2000 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_31012001_Original_VIN_Unlock_Start)),   0u,   0u,   0u,   0u, 0u, 0u} /* RID: 0x2001 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_Start)),   1u,   1u,   1u,   1u, 2u, 0u} /* RID: 0x3000 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_Start)),   1u,   1u,   0u,   0u, 1u, 0u} /* RID: 0x5000 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_Start)),   0u,   0u,   0u,   0u, 0u, 0u} /* RID: 0x5101 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_Start)),   1u,   1u,   0u,   0u, 1u, 0u} /* RID: 0x5200 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_RequestResults)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0x5200 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_Start)),   1u,   1u,   1u,   1u, 2u, 0u} /* RID: 0x5400 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_RequestResults)),   0u,   0u,   8u,   8u, 3u, 0u} /* RID: 0x5400 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_Start)),   1u,   1u,   1u,   1u, 2u, 0u} /* RID: 0x5401 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_RequestResults)),   0u,   0u,   9u,   9u, 3u, 0u} /* RID: 0x5401 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Start)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0x5502 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_RequestResults)),   0u,   0u,   2u,   2u, 3u, 0u} /* RID: 0x5502 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Start)),   0u,   0u,   0u,   0u, 0u, 0u} /* RID: 0xD001 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Stop)),   0u,   0u,   0u,   0u, 0u, 0u} /* RID: 0xD001 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_Start)),   0u,   0u,   0u, 256u, 6u, 0u} /* RID: 0xD002 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_3101D003_Application_Logical_Block_Hash_Start)),   1u,   1u,  32u,  32u, 2u, 0u} /* RID: 0xD003 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_3101F000_Check_Program_Start_Start)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0xF000 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_Start)),   2u,   2u,   2u,   2u, 2u, 0u} /* RID: 0xFE01 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_Start)),   5u,   5u,   0u,   0u, 1u, 0u} /* RID: 0xFE02 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Start)),   2u,   2u,   2u,   2u, 2u, 0u} /* RID: 0xFE0E */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Stop)),   0u,   0u,   0u,   0u, 0u, 0u} /* RID: 0xFE0E */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_3101FF00_FlashErase_Start_Start)),   0u,   0u,   9u,   9u, 3u, 0u} /* RID: 0xFF00 */   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_3101FF01_checkProgrammingDependencies_FlashChecksum_Start_Start)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0xFF01 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_Start)),   3u,   3u,   2u,   2u, 2u, 0u} /* RID: 0xFF03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! DCM service initializers */
CONST(Dcm_DiagSvcInitFuncType, DCM_CONST) Dcm_CfgDiagSvcInitializers[3]=
{
   Dcm_Service27Init
  ,Dcm_Service2FInit
  ,NULL_PTR /* end marker */
};
/*! DCM service properties */
CONST(Dcm_CfgDiagServiceInfoType, DCM_CONST) Dcm_CfgDiagServiceInfo[16]=
{
   { Dcm_Service10Processor,0x01u, 1u,   1u,   2u, 0u, 0u} /* SID: 0x10 */
  ,{ Dcm_Service11Processor,0x01u, 1u,   3u,   4u, 0u, 0u} /* SID: 0x11 */
  ,{ Dcm_Service14Processor,0x00u, 3u,   0u,   0u, 0u, 1u} /* SID: 0x14 */
  ,{ Dcm_Service19Processor,0x01u, 1u,   5u,   0u, 2u, 2u} /* SID: 0x19 */
  ,{ Dcm_Service22Processor,0x00u, 2u,   0u,   0u, 0u, 3u} /* SID: 0x22 */
  ,{ Dcm_Service27Processor,0x03u, 1u,   6u,   0u, 0u, 0u} /* SID: 0x27 */
  ,{ Dcm_Service28Processor,0x01u, 1u,   7u,   0u, 0u, 0u} /* SID: 0x28 */
  ,{ Dcm_Service2EProcessor,0x00u, 3u,   0u,   0u, 0u, 4u} /* SID: 0x2E */
  ,{ Dcm_Service2FProcessor,0x00u, 3u,   8u,   0u, 0u, 5u} /* SID: 0x2F */
  ,{ Dcm_Service31Processor,0x01u, 3u,   0u,   0u, 0u, 0u} /* SID: 0x31 */
  ,{ Dcm_Service34Processor,0x00u, 4u,   0u,   0u, 0u, 0u} /* SID: 0x34 */
  ,{ Dcm_Service36Processor,0x00u, 1u,   0u,   0u, 0u, 0u} /* SID: 0x36 */
  ,{ Dcm_Service37Processor,0x00u, 0u,   0u,   0u, 0u, 0u} /* SID: 0x37 */
  ,{ Dcm_Service3EProcessor,0x01u, 1u,   0u,   0u, 0u, 0u} /* SID: 0x3E */
  ,{ Dcm_Service85Processor,0x01u, 1u,   9u,   0u, 0u, 6u} /* SID: 0x85 */
  ,{ Dcm_RepeaterDeadEnd,0x00u, 0u,   0u,   0u, 0u, 0u} /* Dcm_RepeaterDeadEnd */
};
/*! Indirection from diag service info to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgDiagSvcIdExecPrecondTable[15]=
{
      0u /* SID: 0x10 */
  ,   0u /* SID: 0x11 */
  ,   2u /* SID: 0x14 */
  ,   0u /* SID: 0x19 */
  ,   0u /* SID: 0x22 */
  ,   3u /* SID: 0x27 */
  ,   4u /* SID: 0x28 */
  ,   0u /* SID: 0x2E */
  ,   5u /* SID: 0x2F */
  ,   0u /* SID: 0x31 */
  ,   6u /* SID: 0x34 */
  ,   7u /* SID: 0x36 */
  ,   7u /* SID: 0x37 */
  ,   0u /* SID: 0x3E */
  ,   4u /* SID: 0x85 */
};
/*! DCM service post processors */
CONST(Dcm_DiagSvcConfirmationFuncType, DCM_CONST) Dcm_CfgDiagSvcPostProcessors[10]=
{
   Dcm_ServiceNoPostProcessor
  ,Dcm_Service10PostProcessor
  ,Dcm_Service10FastPostProcessor
  ,Dcm_Service11PostProcessor
  ,Dcm_Service11FastPostProcessor
  ,Dcm_Service19PostProcessor
  ,Dcm_Service27PostProcessor
  ,Dcm_Service28PostProcessor
  ,Dcm_Service2FPostProcessor
  ,Dcm_Service85PostProcessor
};
/*! DCM service paged buffer updater */
CONST(Dcm_DiagSvcUpdateFuncType, DCM_CONST) Dcm_CfgDiagSvcUpdaters[3]=
{
   Dcm_ServiceNoUpdater
  ,Dcm_PagedBufferDataPadding
  ,Dcm_Service19Updater
};
/*! DCM service paged buffer canceller */
CONST(Dcm_DiagSvcCancelFuncType, DCM_CONST) Dcm_CfgDiagSvcCancellers[7]=
{
   Dcm_ServiceNoCancel
  ,Dcm_Service14Cancel
  ,Dcm_Service19Cancel
  ,Dcm_Service22Cancel
  ,Dcm_Service2ECancel
  ,Dcm_Service2FCancel
  ,Dcm_Service85Cancel
};
/*! OEM notification functions */
CONST(Dcm_CfgDiagNotificationInfoType, DCM_CONST) Dcm_CfgDiagOemNotificationInfo[2]=
{
   { DcmDslServiceRequestManufacturer_Indication,DcmDslServiceRequestManufacturer_Confirmtion}
  ,{ NULL_PTR,NULL_PTR}
};
/*! System supplier notification functions */
CONST(Dcm_CfgDiagNotificationInfoType, DCM_CONST) Dcm_CfgDiagSysNotificationInfo[1]=
{
   { NULL_PTR,NULL_PTR}
};
/*! DCM service to protocol map */
CONST(Dcm_CfgDiagSvc2ProtMapMemType, DCM_CONST) Dcm_CfgDiagSvcId2ProtMap[15]=
{
   0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
};
/*! Service 0x10 sub-service properties table  */
CONST(Dcm_CfgSvc10SubFuncInfoType, DCM_CONST) Dcm_CfgSvc10SubFuncInfo[3]=
{
   { { 50u, 500u}, 0u} /* Session ID: 0x01 */
  ,{ { 50u, 500u}, 1u} /* Session ID: 0x02 */
  ,{ { 50u, 500u}, 0u} /* Session ID: 0x03 */
};
/*! Indirection from service 0x10 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc10SubFuncExecPrecondTable[3]=
{
      0u /* Session ID: 0x01 */
  ,   1u /* Session ID: 0x02 */
  ,   0u /* Session ID: 0x03 */
};
/*! Service 0x11 sub-service properties table  */
CONST(Dcm_CfgSvc11SubFuncInfoType, DCM_CONST) Dcm_CfgSvc11SubFuncInfo[1]=
{
   { Dcm_Service11_01Processor} /* SF: 0x01 */
};
/*! Indirection from service 0x11 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc11SubFuncExecPrecondTable[1]=
{
      0u /* SF: 0x01 */
};
/*! Service 0x19 sub-service properties table  */
CONST(Dcm_CfgSvc19SubFuncInfoType, DCM_CONST) Dcm_CfgSvc19SubFuncInfo[10]=
{
   { Dcm_Service19_01Processor, 2u} /* SF: 0x01 */
  ,{ Dcm_Service19_02Processor, 2u} /* SF: 0x02 */
  ,{ Dcm_Service19_04Processor, 5u} /* SF: 0x04 */
  ,{ Dcm_Service19_06Processor, 5u} /* SF: 0x06 */
  ,{ Dcm_Service19_07Processor, 3u} /* SF: 0x07 */
  ,{ Dcm_Service19_08Processor, 3u} /* SF: 0x08 */
  ,{ Dcm_Service19_09Processor, 4u} /* SF: 0x09 */
  ,{ Dcm_Service19_0AProcessor, 1u} /* SF: 0x0A */
  ,{ Dcm_Service19_0CProcessor, 1u} /* SF: 0x0C */
  ,{ Dcm_Service19_0EProcessor, 1u} /* SF: 0x0E */
};
/*! Indirection from service 0x19 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc19SubFuncExecPrecondTable[10]=
{
      2u /* SF: 0x01 */
  ,   0u /* SF: 0x02 */
  ,   2u /* SF: 0x04 */
  ,   2u /* SF: 0x06 */
  ,   2u /* SF: 0x07 */
  ,   2u /* SF: 0x08 */
  ,   2u /* SF: 0x09 */
  ,   2u /* SF: 0x0A */
  ,   2u /* SF: 0x0C */
  ,   2u /* SF: 0x0E */
};
/*! Service 0x27 sub-service properties table  */
CONST(Dcm_CfgSvc27SubFuncInfoType, DCM_CONST) Dcm_CfgSvc27SubFuncInfo[2]=
{
   { 1537u} /* SF: 0x11 */                                                                                                                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{  289u} /* SF: 0x12 */                                                                                                                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! Service 0x27 security level properties table  */
CONST(Dcm_CfgSvc27SecLevelInfoType, DCM_CONST) Dcm_CfgSvc27SecLevelInfo[1]=
{
   { ((Dcm_Svc27GetSeedFuncType)(Os_Call_DcmCalloutStub_GetSeed)),Os_Call_DcmCalloutStub_CompareKey,  32u, 1u} /* SecLvl: Authenticated_Diagnostic_Access */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! Indirection from service 0x27 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc27SubFuncExecPrecondTable[2]=
{
      3u /* SF: 0x11 */
  ,   3u /* SF: 0x12 */
};
/*! Service 0x28 sub-service properties table  */
CONST(Dcm_CfgSvc28SubFuncInfoType, DCM_CONST) Dcm_CfgSvc28SubFuncInfo[2]=
{
   { Dcm_Service28_XXProcessor, 2u} /* SF: 0x00 */
  ,{ Dcm_Service28_XXProcessor, 2u} /* SF: 0x01 */
};
/*! Indirection from service 0x28 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc28SubFuncExecPrecondTable[2]=
{
      4u /* SF: 0x00 */
  ,   4u /* SF: 0x01 */
};
/*! Service 0x28 network ID to ComM channel map */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgSvc28SubNetIdMap[2]=
{
   DCM_SVC_28_NETWORK_ALL
  ,DCM_SVC_28_NETWORK_CURRENT
};
/*! Indirection from service 0x3E sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc3ESubFuncExecPrecondTable[1]=
{
      0u /* SF: 0x00 */
};
/*! Indirection from service 0x85 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc85SubFuncExecPrecondTable[2]=
{
      4u /* SF: 0x01 */
  ,   4u /* SF: 0x02 */
};
/*! DCM service 0x85 properties */
CONST(Dcm_CfgSvc85SubFuncInfoType, DCM_CONST) Dcm_CfgSvc85SubFuncInfo[2]=
{
   { Dem_EnableDTCSetting,RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING} /* SF: 0x01 */
  ,{ Dem_DisableDTCSetting,RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING} /* SF: 0x02 */
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  Dcm_ModeRuleDefaultModeRule()
***********************************************************************************************************************/
/* Implements CDD Dcm_ModeRule<XXX>() */
DCM_LOCAL FUNC(boolean, DCM_CODE) Dcm_ModeRuleDefaultModeRule(Dcm_Ptr2LocalU8Type nrc)                                                               /* PRQA S 3673, 2889 */ /* MD_Dcm_APIStd_3673, MD_Dcm_Optimize_2889 */
{
  DCM_IGNORE_UNREF_PARAM(nrc);                                                                                                                       /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  return TRUE;
}
/***********************************************************************************************************************
 *  Dcm_ModeRuleVehicleSpeedCheckRule()
***********************************************************************************************************************/
/* Implements CDD Dcm_ModeRule<XXX>() */
DCM_LOCAL FUNC(boolean, DCM_CODE) Dcm_ModeRuleVehicleSpeedCheckRule(Dcm_Ptr2LocalU8Type nrc)                                                         /* PRQA S 2889 */ /* MD_Dcm_Optimize_2889 */
{
  if (Dcm_ModeCondGet_Dcm_Read_Mode_VehicleSpeedCheck() != RTE_MODE_VehicleSpeedCheck_VehicleSpeedZero)
  {
    *nrc = ((uint8)(0x22u));                                                                                                                         /* SBSW_DCM_GEN_PARAM_PTR_WRITE */
    return FALSE;
  }
  return TRUE;
}
/***********************************************************************************************************************
 *  Dcm_ModeRuleProgrammingPreconditionCheckRule()
***********************************************************************************************************************/
/* Implements CDD Dcm_ModeRule<XXX>() */
DCM_LOCAL FUNC(boolean, DCM_CODE) Dcm_ModeRuleProgrammingPreconditionCheckRule(Dcm_Ptr2LocalU8Type nrc)                                              /* PRQA S 2889 */ /* MD_Dcm_Optimize_2889 */
{
  if (Dcm_ModeCondGet_Dcm_Read_ModeProgPreconditionCheck_ProgPreconditionState() != RTE_MODE_ProgPreconditionState_StateOK)
  {
    *nrc = ((uint8)(0x22u));                                                                                                                         /* SBSW_DCM_GEN_PARAM_PTR_WRITE */
    return FALSE;
  }
  return TRUE;
}
/***********************************************************************************************************************
 *  Dcm_ModeCondGet_Dcm_Read_Mode_VehicleSpeedCheck()
***********************************************************************************************************************/
/* Implements CDD Dcm_ModeCondGet_<XXX>() */
DCM_LOCAL FUNC(Rte_ModeType_VehicleSpeedCheck, DCM_CODE) Dcm_ModeCondGet_Dcm_Read_Mode_VehicleSpeedCheck(void)
{
  Rte_ModeType_VehicleSpeedCheck result;
  Rte_ModeType_VehicleSpeedCheck prev;
  Rte_ModeType_VehicleSpeedCheck next;
  result = Rte_Mode_Dcm_Read_Mode_Dcm_Read_Mode(&prev, &next);                                                                                       /* SBSW_DCM_GEN_POINTER_FORWARD_STACK */
  return ((Rte_ModeType_VehicleSpeedCheck)((RTE_TRANSITION_VehicleSpeedCheck == result)?next:result));
}
/***********************************************************************************************************************
 *  Dcm_ModeCondGet_Dcm_Read_ModeProgPreconditionCheck_ProgPreconditionState()
***********************************************************************************************************************/
/* Implements CDD Dcm_ModeCondGet_<XXX>() */
DCM_LOCAL FUNC(Rte_ModeType_ProgPreconditionState, DCM_CODE) Dcm_ModeCondGet_Dcm_Read_ModeProgPreconditionCheck_ProgPreconditionState(void)
{
  Rte_ModeType_ProgPreconditionState result;
  Rte_ModeType_ProgPreconditionState prev;
  Rte_ModeType_ProgPreconditionState next;
  result = Rte_Mode_Dcm_Read_ModeProgPreconditionCheck_Dcm_Read_ModeProgPreconditionCheck(&prev, &next);                                             /* SBSW_DCM_GEN_POINTER_FORWARD_STACK */
  return ((Rte_ModeType_ProgPreconditionState)((RTE_TRANSITION_ProgPreconditionState == result)?next:result));
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define DCM_START_SEC_CALLOUT_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  Dcm_ServiceNoPostProcessor()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoPostProcessor() */
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoPostProcessor(
  Dcm_ContextPtrType pContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_ConfirmationStatusType status
  )
{
  DCM_IGNORE_UNREF_PARAM(pContext);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(status);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoUpdater()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoUpdater() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ServiceNoUpdater(
  Dcm_ContextPtrType pContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_OpStatusType opStatus,
  Dcm_DiagDataContextPtrType pDataContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  DCM_IGNORE_UNREF_PARAM(pContext);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(opStatus);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(pDataContext);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(ErrorCode);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoCancel()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoCancel() */
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoCancel(
  Dcm_ContextPtrType pContext  /* PRQA S 3673 */ /* MD_Dcm_Design_3673 */
  )
{
  DCM_IGNORE_UNREF_PARAM(pContext);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  /* nothing to do */
}
#define DCM_STOP_SEC_CALLOUT_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Dcm_Lcfg.c
 *********************************************************************************************************************/

