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
 *            Module: BswM
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: BswM_Lcfg.c
 *   Generation Time: 2025-06-25 19:44:14
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define BSWM_LCFG_SOURCE

/* -----------------------------------------------------------------------------
    &&&~ MISRA JUSTIFICATION
 ----------------------------------------------------------------------------- */
/* PRQA S 0785, 0786 EOF */ /* MD_CSL_DistinctIdentifiers */

/* -----------------------------------------------------------------------------
    &&&~ INCLUDE
 ----------------------------------------------------------------------------- */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#include "BswM.h"
#include "BswM_Private_Cfg.h"
#include "SchM_BswM.h"

#if !defined (BSWM_LOCAL)
# define BSWM_LOCAL static
#endif

#if !defined (BSWM_LOCAL_INLINE) /* COV_BSWM_LOCAL_INLINE */
# define BSWM_LOCAL_INLINE LOCAL_INLINE
#endif



#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ LOCAL FUNCTION DECLARATIONS
 ----------------------------------------------------------------------------- */
/**********************************************************************************************************************
 *  BswM_Action_RuleHandler()
 **********************************************************************************************************************/
/*!
 * \brief       Executes a rule.
 * \details     Arbitrates a rule and executes corresponding action list.
 * \param[in]   handleId       Id of the rule to execute.
 * \param[in]   partitionIdx   Current partition context.
 * \return      E_OK      No action list was executed or corresponding action list was completely executed.
 * \return      E_NOT_OK  Action list was aborted because an action failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_RuleHandler(BswM_HandleType handleId,
                                                                   BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);

/**********************************************************************************************************************
 *  BswM_UpdateRuleStates()
 **********************************************************************************************************************/
/*!
 * \brief       Updates the state of a rule.
 * \details     Set rule state of passed ruleId to passed state.
 * \param[in]   ruleId         Id of the rule to update.
 * \param[in]   state          New state of the rule.
 * \param[in]   partitionIdx   Current partition context.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateRuleStates(BswM_SizeOfRuleStatesType ruleId,
                                                              BswM_RuleStatesType state,
                                                              BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);

/**********************************************************************************************************************
 *  BswM_UpdateTimer()
 **********************************************************************************************************************/
/*!
 * \brief       Updates a timer.
 * \details     Set timer value of passed timerId to passed value and calculates the new state.
 * \param[in]   timerId        Id of the timer to update.
 * \param[in]   value          New value of the timer.
 * \param[in]   partitionIdx   Current partition context.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx,
                                                         BswM_SizeOfTimerValueType timerId,
                                                         BswM_TimerValueType value);

/*! \addtogroup    BswMGeneratedFunctions BswM Generated Functions
 * \{
 */
/* PRQA S 0779 FUNCTIONDECLARATIONS */ /* MD_MSR_Rule5.2_0779 */

/**********************************************************************************************************************
 *  Init
 *********************************************************************************************************************/
/*! \defgroup    Init
 * \{
 */
/**********************************************************************************************************************
 *  BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * \brief       Initializes BswM.
 * \details     Part of the BswM_Init. Initializes all generated variables and executes action lists for initialization.
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        May only be called by BswM_Init.
 */
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of group Init */

/**********************************************************************************************************************
 *  Common
 *********************************************************************************************************************/
/*! \defgroup    Common
 * \{
 */
/**********************************************************************************************************************
 *  BswM_ModeNotificationFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * \brief       Switch Modes of RTE and writes RTE values.
 * \details     Forwards a BswM Switch Action to the RTE and writes value of RteRequestPorts to RTE.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        May only be called by BswM_MainFunction.
 */
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_ModeNotificationFct_BSWM_SINGLEPARTITION(void);
/*! \} */ /* End of group Common */

/**********************************************************************************************************************
 *  SwcModeRequestUpdate
 *********************************************************************************************************************/
/*! \defgroup    SwcModeRequestUpdate
 * \{
 */
/**********************************************************************************************************************
 *  BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * \brief       Reads port values from RTE.
 * \details     Gets the current value of SwcModeRequest Ports and SwcNotification Ports from RTE.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        May only be called by BswM_MainFunction.
 */
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION(void);
/*! \} */ /* End of group SwcModeRequestUpdate */

/**********************************************************************************************************************
 *  BswMActionListFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMActionListFunctions
 * \{
 */

/*!
 * \{
 * \brief       Execute actions of action list.
 * \details     Generated function which depends on the configuration. Executes the actions of the action list in the
 *              configured order.
 * \return      E_OK      Action list was completely executed.
 * \return      E_NOT_OK  Action list was aborted because an action failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_INIT_AL_Initialize(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ExitRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_RunToPostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WaitForNvMToShutdown(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WakeupToPrep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WaitForNvMWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WakeupToRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_DemInit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_InitToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_PostRunToPrepShutdown(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_PostRunToRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ExitPostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_PrepShutdownToWaitForNvM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_Disable_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_Enable_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_TX_Disable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_TX_EnableNoinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_RX_Disable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_RX_EnableNoinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_Disable_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_Enable_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_RX_Disable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_TX_Disable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableNoinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_NmEnable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_NmDisable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_BUSOFF_SILENT(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_NO_COM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_RX_EnableReinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableReinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CheckNMPendingRequest(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NMIndicationNormal(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NMIndicationPrepareSleep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NMIndicationReadySleep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NMIndicationRepeat(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NMIndicationUninit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_HardReset(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_JumpToBOOT(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_SSM_BSW_Shutdown_execute(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_ADAS_EcuM_stateSwitch(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_ADAS_ECUReset(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_SafetyGuard_SysResetReq(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_SCCalStatus(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of sharing description for BswMActionListFunctions */
/*! \} */ /* End of group BswMActionListFunctions */

/**********************************************************************************************************************
 *  BswMRuleFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMRuleFunctions
 * \{
 */

/*!
 * \{
 * \brief       Arbitrates the configured rule.
 * \details     Generated function which depends on the configuration. Arbitrates the rule and returns the action list
 *              which shall be executed.
 * \return      ID of action list to execute (BSWM_NO_ACTIONLIST if no ActionList shall be executed)
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_RunToPostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_RunToPostRunNested(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WaitToShutdown(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WakeupToPrep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WaitToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WakeupToRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_DemInit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_InitToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRunToPrepNested(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRunNested(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PrepToWait(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN14_a902658e_RX_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN14_a902658e_TX(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN14_a902658e_RX(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_RX_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_RX(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_NM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_BUSOFF_SILENT(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_TX_DISABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_NO_COM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_TX_ENABLE_BUSOFF(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_TX_ENABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_JumpToBoot(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_NMNormalNtfy(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_NMReadySleepNtfy(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_NmOtherNtfy(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_NmPrepareSleepNtfy(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_NmRepeatNtfy(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_PerfromHardReset(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWN_NmEnable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BswMRule_NMCheckRequest(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_SSM_Shutdown_Execute(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BswMRule_ADAS_Shutdown_Request_CAN(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BswM_ADAS_ECUReset(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BswMRule_SafetyGuard_SysResetReq(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BswMRule_SCCalStatus(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of sharing description for BswMRuleFunctions */
/*! \} */ /* End of group BswMRuleFunctions */
/* PRQA L:FUNCTIONDECLARATIONS */
/*! \} */ /* End of group BswMGeneratedFunctions */

#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ LOCAL VARIABLE DECLARATIONS
 ----------------------------------------------------------------------------- */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/


/* PRQA S 0310 GLOBALDATADECLARATIONS */ /* MD_BSWM_0310 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  BswM_ActionLists
**********************************************************************************************************************/
/** 
  \var    BswM_ActionLists
  \details
  Element    Description
  FctPtr     Pointer to the array list function.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionListsType, BSWM_CONST) BswM_ActionLists[44] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FctPtr                                                           Comment                   Referable Keys */
  { /*     0 */ BswM_ActionList_INIT_AL_Initialize                        },  /* [Priority: 0] */  /* [AL_INIT_AL_Initialize] */
  { /*     1 */ BswM_ActionList_ESH_AL_ExitRun                            },  /* [Priority: 0] */  /* [AL_ESH_AL_ExitRun] */
  { /*     2 */ BswM_ActionList_ESH_AL_RunToPostRun                       },  /* [Priority: 0] */  /* [AL_ESH_AL_RunToPostRun] */
  { /*     3 */ BswM_ActionList_ESH_AL_WaitForNvMToShutdown               },  /* [Priority: 0] */  /* [AL_ESH_AL_WaitForNvMToShutdown] */
  { /*     4 */ BswM_ActionList_ESH_AL_WakeupToPrep                       },  /* [Priority: 0] */  /* [AL_ESH_AL_WakeupToPrep] */
  { /*     5 */ BswM_ActionList_ESH_AL_WaitForNvMWakeup                   },  /* [Priority: 0] */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  { /*     6 */ BswM_ActionList_ESH_AL_WakeupToRun                        },  /* [Priority: 0] */  /* [AL_ESH_AL_WakeupToRun] */
  { /*     7 */ BswM_ActionList_ESH_AL_DemInit                            },  /* [Priority: 0] */  /* [AL_ESH_AL_DemInit] */
  { /*     8 */ BswM_ActionList_ESH_AL_InitToWakeup                       },  /* [Priority: 0] */  /* [AL_ESH_AL_InitToWakeup] */
  { /*     9 */ BswM_ActionList_ESH_AL_PostRunToPrepShutdown              },  /* [Priority: 0] */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    10 */ BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck             },  /* [Priority: 0] */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  { /*    11 */ BswM_ActionList_ESH_AL_PostRunToRun                       },  /* [Priority: 0] */  /* [AL_ESH_AL_PostRunToRun] */
  { /*    12 */ BswM_ActionList_ESH_AL_ExitPostRun                        },  /* [Priority: 0] */  /* [AL_ESH_AL_ExitPostRun] */
  { /*    13 */ BswM_ActionList_ESH_AL_PrepShutdownToWaitForNvM           },  /* [Priority: 0] */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  { /*    14 */ BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_Disable_DM      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN14_a902658e_Disable_DM] */
  { /*    15 */ BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_Enable_DM       },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN14_a902658e_Enable_DM] */
  { /*    16 */ BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_TX_Disable      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN14_a902658e_TX_Disable] */
  { /*    17 */ BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_TX_EnableNoinit },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN14_a902658e_TX_EnableNoinit] */
  { /*    18 */ BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_RX_Disable      },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN14_a902658e_RX_Disable] */
  { /*    19 */ BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_RX_EnableNoinit },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN14_a902658e_RX_EnableNoinit] */
  { /*    20 */ BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_Disable_DM       },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_Disable_DM] */
  { /*    21 */ BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_Enable_DM        },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_Enable_DM] */
  { /*    22 */ BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_RX_Disable       },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_RX_Disable] */
  { /*    23 */ BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_TX_Disable       },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_TX_Disable] */
  { /*    24 */ BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableNoinit  },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableNoinit] */
  { /*    25 */ BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_NmEnable         },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_NmEnable] */
  { /*    26 */ BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_NmDisable        },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_NmDisable] */
  { /*    27 */ BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_BUSOFF_SILENT    },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_BUSOFF_SILENT] */
  { /*    28 */ BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_NO_COM           },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_NO_COM] */
  { /*    29 */ BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_RX_EnableReinit  },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_RX_EnableReinit] */
  { /*    30 */ BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableReinit  },  /* [Priority: 0] */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableReinit] */
  { /*    31 */ BswM_ActionList_AL_CheckNMPendingRequest                  },  /* [Priority: 0] */  /* [AL_AL_CheckNMPendingRequest] */
  { /*    32 */ BswM_ActionList_AL_NMIndicationNormal                     },  /* [Priority: 0] */  /* [AL_AL_NMIndicationNormal] */
  { /*    33 */ BswM_ActionList_AL_NMIndicationPrepareSleep               },  /* [Priority: 0] */  /* [AL_AL_NMIndicationPrepareSleep] */
  { /*    34 */ BswM_ActionList_AL_NMIndicationReadySleep                 },  /* [Priority: 0] */  /* [AL_AL_NMIndicationReadySleep] */
  { /*    35 */ BswM_ActionList_AL_NMIndicationRepeat                     },  /* [Priority: 0] */  /* [AL_AL_NMIndicationRepeat] */
  { /*    36 */ BswM_ActionList_AL_NMIndicationUninit                     },  /* [Priority: 0] */  /* [AL_AL_NMIndicationUninit] */
  { /*    37 */ BswM_ActionList_AL_Run_HardReset                          },  /* [Priority: 0] */  /* [AL_AL_Run_HardReset] */
  { /*    38 */ BswM_ActionList_AL_Run_JumpToBOOT                         },  /* [Priority: 0] */  /* [AL_AL_Run_JumpToBOOT] */
  { /*    39 */ BswM_ActionList_AL_SSM_BSW_Shutdown_execute               },  /* [Priority: 0] */  /* [AL_AL_SSM_BSW_Shutdown_execute] */
  { /*    40 */ BswM_ActionList_AL_ADAS_EcuM_stateSwitch                  },  /* [Priority: 0] */  /* [AL_AL_ADAS_EcuM_stateSwitch] */
  { /*    41 */ BswM_ActionList_AL_ADAS_ECUReset                          },  /* [Priority: 0] */  /* [AL_AL_ADAS_ECUReset] */
  { /*    42 */ BswM_ActionList_AL_SafetyGuard_SysResetReq                },  /* [Priority: 0] */  /* [AL_AL_SafetyGuard_SysResetReq] */
  { /*    43 */ BswM_ActionList_AL_SCCalStatus                            }   /* [Priority: 0] */  /* [AL_AL_SCCalStatus] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelMapping
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelMapping
  \brief  Maps the external id of BswMCanSMIndication to an internal id and references immediate request ports.
  \details
  Element                  Description
  ExternalId               External id of BswMCanSMIndication.
  ImmediateUserEndIdx      the end index of the 0:n relation pointing to BswM_ImmediateUser
  ImmediateUserStartIdx    the start index of the 0:n relation pointing to BswM_ImmediateUser
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_CanSMChannelMappingType, BSWM_CONST) BswM_CanSMChannelMapping[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExternalId                                ImmediateUserEndIdx  ImmediateUserStartIdx        Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_CN_FDCAN2_28a8fc44 ,                  1u,                    0u },  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44] */
  { /*     1 */ ComMConf_ComMChannel_CN_FDCAN14_a902658e,                  2u,                    1u }   /* [CANSM_CHANNEL_1, MRP_CC_CanSMIndication_CN_FDCAN14_a902658e] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMChannelMapping
**********************************************************************************************************************/
/** 
  \var    BswM_ComMChannelMapping
  \brief  Maps the external id of BswMComMIndication to an internal id and references immediate request ports.
  \details
  Element       Description
  ExternalId    External id of BswMComMIndication.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComMChannelMappingType, BSWM_CONST) BswM_ComMChannelMapping[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExternalId                                      Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_CN_FDCAN2_28a8fc44  },  /* [COMM_CHANNEL_0, MRP_ESH_ComMIndication_CN_FDCAN2_28a8fc44] */
  { /*     1 */ ComMConf_ComMChannel_CN_FDCAN14_a902658e }   /* [COMM_CHANNEL_1, MRP_ESH_ComMIndication_CN_FDCAN14_a902658e] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_DeferredRules
**********************************************************************************************************************/
/** 
  \var    BswM_DeferredRules
  \details
  Element     Description
  RulesIdx    the index of the 1:1 relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_DeferredRulesType, BSWM_CONST) BswM_DeferredRules[14] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RulesIdx        Referable Keys */
  { /*     0 */       0u },  /* [R_ESH_RunToPostRun] */
  { /*     1 */       2u },  /* [R_ESH_WaitToShutdown] */
  { /*     2 */       3u },  /* [R_ESH_WakeupToPrep] */
  { /*     3 */       4u },  /* [R_ESH_WaitToWakeup] */
  { /*     4 */       5u },  /* [R_ESH_WakeupToRun] */
  { /*     5 */      10u },  /* [R_ESH_PostRun] */
  { /*     6 */      11u },  /* [R_ESH_PrepToWait] */
  { /*     7 */      23u },  /* [R_BSWM_JumpToBoot] */
  { /*     8 */      29u },  /* [R_BSWM_PerfromHardReset] */
  { /*     9 */      31u },  /* [R_BswMRule_NMCheckRequest] */
  { /*    10 */      32u },  /* [R_BSWM_SSM_Shutdown_Execute] */
  { /*    11 */      34u },  /* [R_BswM_ADAS_ECUReset] */
  { /*    12 */      35u },  /* [R_BswMRule_SafetyGuard_SysResetReq] */
  { /*    13 */      36u }   /* [R_BswMRule_SCCalStatus] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericMapping
**********************************************************************************************************************/
/** 
  \var    BswM_GenericMapping
  \brief  Maps the external id of BswMGenericRequest to an internal id and references immediate request ports.
  \details
  Element                  Description
  ExternalId               External id of BswMGenericRequest.
  ImmediateUserEndIdx      the end index of the 0:n relation pointing to BswM_ImmediateUser
  ImmediateUserStartIdx    the start index of the 0:n relation pointing to BswM_ImmediateUser
  InitValue                Initialization value of port.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_GenericMappingType, BSWM_CONST) BswM_GenericMapping[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExternalId                                         ImmediateUserEndIdx                          ImmediateUserStartIdx                          InitValue                                                            Referable Keys */
  { /*     0 */ BSWM_GENERIC_CC_Generic_BusOff_CN_FDCAN2_28a8fc44,                                          4u,                                            3u, BSWM_GENERICVALUE_CC_Generic_BusOff_CN_FDCAN2_28a8fc44_NO_COM },  /* [GENERIC_0, MRP_CC_Generic_BusOff_CN_FDCAN2_28a8fc44] */
  { /*     1 */ BSWM_GENERIC_ESH_ComMPendingRequests             , BSWM_NO_IMMEDIATEUSERENDIDXOFGENERICMAPPING, BSWM_NO_IMMEDIATEUSERSTARTIDXOFGENERICMAPPING, BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST },  /* [GENERIC_1, MRP_ESH_ComMPendingRequests] */
  { /*     2 */ BSWM_GENERIC_ESH_DemInitStatus                   ,                                          5u,                                            4u, BSWM_GENERICVALUE_ESH_DemInitStatus_DEM_INITIALIZED           },  /* [GENERIC_2, MRP_ESH_DemInitStatus] */
  { /*     3 */ BSWM_GENERIC_ESH_DemPostRunRequested             , BSWM_NO_IMMEDIATEUSERENDIDXOFGENERICMAPPING, BSWM_NO_IMMEDIATEUSERSTARTIDXOFGENERICMAPPING, BSWM_GENERICVALUE_ESH_DemPostRunRequested_TRUE                },  /* [GENERIC_3, MRP_ESH_DemPostRunRequested] */
  { /*     4 */ BSWM_GENERIC_ESH_State                           ,                                          6u,                                            5u, BSWM_GENERICVALUE_ESH_State_ESH_INIT                          }   /* [GENERIC_4, MRP_ESH_State] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ImmediateUser
**********************************************************************************************************************/
/** 
  \var    BswM_ImmediateUser
  \brief  Contains all immediate request ports.
  \details
  Element             Description
  OnInit              Arbitrate depending rules on initialization.
  RulesIndEndIdx      the end index of the 0:n relation pointing to BswM_RulesInd
  RulesIndStartIdx    the start index of the 0:n relation pointing to BswM_RulesInd
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ImmediateUserType, BSWM_CONST) BswM_ImmediateUser[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    OnInit  RulesIndEndIdx                         RulesIndStartIdx                               Comment                                                    Referable Keys */
  { /*     0 */  FALSE,                                    7u,                                      0u },  /* [Name: CC_CanSMIndication_CN_FDCAN2_28a8fc44]  */  /* [MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44, CANSM_CHANNEL_0] */
  { /*     1 */  FALSE,                                   10u,                                      7u },  /* [Name: CC_CanSMIndication_CN_FDCAN14_a902658e] */  /* [MRP_CC_CanSMIndication_CN_FDCAN14_a902658e, CANSM_CHANNEL_1] */
  { /*     2 */  FALSE,                                   17u,                                     10u },  /* [Name: CC_DcmComIndication_CN_FDCAN2_28a8fc44] */  /* [MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44, DCM_COM_0] */
  { /*     3 */  FALSE,                                   19u,                                     17u },  /* [Name: CC_Generic_BusOff_CN_FDCAN2_28a8fc44]   */  /* [MRP_CC_Generic_BusOff_CN_FDCAN2_28a8fc44, GENERIC_0] */
  { /*     4 */  FALSE, BSWM_NO_RULESINDENDIDXOFIMMEDIATEUSER, BSWM_NO_RULESINDSTARTIDXOFIMMEDIATEUSER },  /* [Name: ESH_DemInitStatus]                      */  /* [MRP_ESH_DemInitStatus, GENERIC_2] */
  { /*     5 */   TRUE,                                   27u,                                     19u },  /* [Name: ESH_State]                              */  /* [MRP_ESH_State, GENERIC_4] */
  { /*     6 */  FALSE,                                   37u,                                     27u }   /* [Name: CC_NmIndication_CN_FDCAN2_28a8fc44]     */  /* [COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44], NM_0] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_InitGenVarAndInitAL
**********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_InitGenVarAndInitALType, BSWM_CONST) BswM_InitGenVarAndInitAL[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitGenVarAndInitAL                            */
  /*     0 */ BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION 
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeNotificationFct
**********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PartitionFunctionType, BSWM_CONST) BswM_ModeNotificationFct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ModeNotificationFct                            */
  /*     0 */ BswM_ModeNotificationFct_BSWM_SINGLEPARTITION 
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    BswM_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to BswM_PCPartitionConfig
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PartitionIdentifiersType, BSWM_CONST) BswM_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV          PCPartitionConfigIdx */
  { /*     0 */ BSWM_SINGLEPARTITION,                   0u }
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Rules
**********************************************************************************************************************/
/** 
  \var    BswM_Rules
  \details
  Element          Description
  Id               External id of rule.
  Init             Initialization value of rule state (TRUE, FALSE, UNDEFINED or DEACTIVATED).
  RuleStatesIdx    the index of the 1:1 relation pointing to BswM_RuleStates
  FctPtr           Pointer to the rule function which does the arbitration.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_RulesType, BSWM_CONST) BswM_Rules[37] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id   Init        RuleStatesIdx  FctPtr                                                  Referable Keys */
  { /*     0 */ 31u, BSWM_FALSE,            0u, BswM_Rule_ESH_RunToPostRun                       },  /* [R_ESH_RunToPostRun, MRP_ESH_State, MRP_ESH_ModeNotification, MRP_ESH_ComMIndication_CN_FDCAN2_28a8fc44, MRP_ESH_ComMIndication_CN_FDCAN14_a902658e, MRP_ESH_RunRequest_0, MRP_ESH_RunRequest_1, MRP_ESH_SelfRunRequestTimer] */
  { /*     1 */ 32u, BSWM_FALSE,            1u, BswM_Rule_ESH_RunToPostRunNested                 },  /* [R_ESH_RunToPostRunNested] */
  { /*     2 */ 33u, BSWM_FALSE,            2u, BswM_Rule_ESH_WaitToShutdown                     },  /* [R_ESH_WaitToShutdown, MRP_ESH_State, MRP_ESH_NvMIndication, MRP_ESH_NvM_WriteAllTimer, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_RunRequest_0, MRP_ESH_RunRequest_1] */
  { /*     3 */ 35u, BSWM_FALSE,            3u, BswM_Rule_ESH_WakeupToPrep                       },  /* [R_ESH_WakeupToPrep, MRP_ESH_State, MRP_ESH_NvMIndication, MRP_ESH_NvM_CancelWriteAllTimer, MRP_ESH_EcuM_GetPendingWakeupEvents, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_RunRequest_0, MRP_ESH_RunRequest_1, MRP_ESH_ModeNotification, MRP_ESH_ComMPendingRequests] */
  { /*     4 */ 34u, BSWM_FALSE,            4u, BswM_Rule_ESH_WaitToWakeup                       },  /* [R_ESH_WaitToWakeup, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_RunRequest_1, MRP_ESH_RunRequest_0, MRP_ESH_ComMPendingRequests] */
  { /*     5 */ 36u, BSWM_FALSE,            5u, BswM_Rule_ESH_WakeupToRun                        },  /* [R_ESH_WakeupToRun, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_RunRequest_1, MRP_ESH_RunRequest_0, MRP_ESH_NvMIndication, MRP_ESH_NvM_CancelWriteAllTimer, MRP_ESH_ModeNotification, MRP_ESH_ComMPendingRequests] */
  { /*     6 */ 25u, BSWM_FALSE,            6u, BswM_Rule_ESH_DemInit                            },  /* [R_ESH_DemInit] */
  { /*     7 */ 26u, BSWM_FALSE,            7u, BswM_Rule_ESH_InitToWakeup                       },  /* [R_ESH_InitToWakeup, MRP_ESH_State] */
  { /*     8 */ 29u, BSWM_FALSE,            8u, BswM_Rule_ESH_PostRunToPrepNested                },  /* [R_ESH_PostRunToPrepNested] */
  { /*     9 */ 28u, BSWM_FALSE,            9u, BswM_Rule_ESH_PostRunNested                      },  /* [R_ESH_PostRunNested] */
  { /*    10 */ 27u, BSWM_FALSE,           10u, BswM_Rule_ESH_PostRun                            },  /* [R_ESH_PostRun, MRP_ESH_State, MRP_ESH_ModeNotification] */
  { /*    11 */ 30u, BSWM_FALSE,           11u, BswM_Rule_ESH_PrepToWait                         },  /* [R_ESH_PrepToWait, MRP_ESH_State, MRP_ESH_ModeNotification] */
  { /*    12 */ 23u, BSWM_FALSE,           12u, BswM_Rule_CC_CN_FDCAN14_a902658e_RX_DM           },  /* [R_CC_CN_FDCAN14_a902658e_RX_DM, MRP_CC_CanSMIndication_CN_FDCAN14_a902658e] */
  { /*    13 */ 24u, BSWM_FALSE,           13u, BswM_Rule_CC_CN_FDCAN14_a902658e_TX              },  /* [R_CC_CN_FDCAN14_a902658e_TX, MRP_CC_CanSMIndication_CN_FDCAN14_a902658e] */
  { /*    14 */ 22u, BSWM_FALSE,           14u, BswM_Rule_CC_CN_FDCAN14_a902658e_RX              },  /* [R_CC_CN_FDCAN14_a902658e_RX, MRP_CC_CanSMIndication_CN_FDCAN14_a902658e] */
  { /*    15 */ 18u, BSWM_FALSE,           15u, BswM_Rule_CC_CN_FDCAN2_28a8fc44_RX_DM            },  /* [R_CC_CN_FDCAN2_28a8fc44_RX_DM, MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44, MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44] */
  { /*    16 */ 17u, BSWM_FALSE,           16u, BswM_Rule_CC_CN_FDCAN2_28a8fc44_RX               },  /* [R_CC_CN_FDCAN2_28a8fc44_RX, MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44, MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44] */
  { /*    17 */ 15u, BSWM_FALSE,           17u, BswM_Rule_CC_CN_FDCAN2_28a8fc44_NM               },  /* [R_CC_CN_FDCAN2_28a8fc44_NM, MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44] */
  { /*    18 */ 14u, BSWM_FALSE,           18u, BswM_Rule_CC_CN_FDCAN2_28a8fc44_BUSOFF_SILENT    },  /* [R_CC_CN_FDCAN2_28a8fc44_BUSOFF_SILENT, MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44] */
  { /*    19 */ 19u, BSWM_FALSE,           19u, BswM_Rule_CC_CN_FDCAN2_28a8fc44_TX_DISABLE       },  /* [R_CC_CN_FDCAN2_28a8fc44_TX_DISABLE, MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44, COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44], MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44] */
  { /*    20 */ 16u, BSWM_TRUE ,           20u, BswM_Rule_CC_CN_FDCAN2_28a8fc44_NO_COM           },  /* [R_CC_CN_FDCAN2_28a8fc44_NO_COM, MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44] */
  { /*    21 */ 21u, BSWM_FALSE,           21u, BswM_Rule_CC_CN_FDCAN2_28a8fc44_TX_ENABLE_BUSOFF },  /* [R_CC_CN_FDCAN2_28a8fc44_TX_ENABLE_BUSOFF, MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44, MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44, COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44], MRP_CC_Generic_BusOff_CN_FDCAN2_28a8fc44] */
  { /*    22 */ 20u, BSWM_FALSE,           22u, BswM_Rule_CC_CN_FDCAN2_28a8fc44_TX_ENABLE        },  /* [R_CC_CN_FDCAN2_28a8fc44_TX_ENABLE, MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44, MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44, COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44], MRP_CC_Generic_BusOff_CN_FDCAN2_28a8fc44] */
  { /*    23 */  0u, BSWM_FALSE,           23u, BswM_Rule_BSWM_JumpToBoot                        },  /* [R_BSWM_JumpToBoot, MRP_SwcModeNotification_SYSModeRequestType] */
  { /*    24 */  1u, BSWM_FALSE,           24u, BswM_Rule_BSWM_NMNormalNtfy                      },  /* [R_BSWM_NMNormalNtfy, COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
  { /*    25 */  2u, BSWM_FALSE,           25u, BswM_Rule_BSWM_NMReadySleepNtfy                  },  /* [R_BSWM_NMReadySleepNtfy, COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
  { /*    26 */  3u, BSWM_FALSE,           26u, BswM_Rule_BSWM_NmOtherNtfy                       },  /* [R_BSWM_NmOtherNtfy, COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
  { /*    27 */  4u, BSWM_FALSE,           27u, BswM_Rule_BSWM_NmPrepareSleepNtfy                },  /* [R_BSWM_NmPrepareSleepNtfy, COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
  { /*    28 */  5u, BSWM_FALSE,           28u, BswM_Rule_BSWM_NmRepeatNtfy                      },  /* [R_BSWM_NmRepeatNtfy, COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
  { /*    29 */  6u, BSWM_FALSE,           29u, BswM_Rule_BSWM_PerfromHardReset                  },  /* [R_BSWM_PerfromHardReset, MRP_SwcModeNotification_SYSModeRequestType] */
  { /*    30 */  9u, BSWM_FALSE,           30u, BswM_Rule_BSWN_NmEnable                          },  /* [R_BSWN_NmEnable, MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44] */
  { /*    31 */  8u, BSWM_FALSE,           31u, BswM_Rule_BswMRule_NMCheckRequest                },  /* [R_BswMRule_NMCheckRequest, COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44], MRP_SwcModeNotification_Current_CmdIgnition] */
  { /*    32 */  7u, BSWM_FALSE,           32u, BswM_Rule_BSWM_SSM_Shutdown_Execute              },  /* [R_BSWM_SSM_Shutdown_Execute, MRP_SwcModeNotification_SSM_ModeNotification_State] */
  { /*    33 */ 11u, BSWM_FALSE,           33u, BswM_Rule_BswMRule_ADAS_Shutdown_Request_CAN     },  /* [R_BswMRule_ADAS_Shutdown_Request_CAN, COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
  { /*    34 */ 13u, BSWM_FALSE,           34u, BswM_Rule_BswM_ADAS_ECUReset                     },  /* [R_BswM_ADAS_ECUReset, MRP_SwcModeNotification_ADAS_ECU_Reset] */
  { /*    35 */ 12u, BSWM_FALSE,           35u, BswM_Rule_BswMRule_SafetyGuard_SysResetReq       },  /* [R_BswMRule_SafetyGuard_SysResetReq, MRP_SwcModeNotification_SafetyGuard_SysResetReq] */
  { /*    36 */ 10u, BSWM_FALSE,           36u, BswM_Rule_BswMRule_SCCalStatus                   }   /* [R_BswMRule_SCCalStatus, MRP_BswM_ScCalStatus] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RulesInd
**********************************************************************************************************************/
/** 
  \var    BswM_RulesInd
  \brief  the indexes of the 1:1 sorted relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_RulesIndType, BSWM_CONST) BswM_RulesInd[37] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RulesInd      Referable Keys */
  /*     0 */       15u,  /* [MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44] */
  /*     1 */       16u,  /* [MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44] */
  /*     2 */       18u,  /* [MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44] */
  /*     3 */       19u,  /* [MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44] */
  /*     4 */       20u,  /* [MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44] */
  /*     5 */       21u,  /* [MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44] */
  /*     6 */       22u,  /* [MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44] */
  /*     7 */       12u,  /* [MRP_CC_CanSMIndication_CN_FDCAN14_a902658e] */
  /*     8 */       13u,  /* [MRP_CC_CanSMIndication_CN_FDCAN14_a902658e] */
  /*     9 */       14u,  /* [MRP_CC_CanSMIndication_CN_FDCAN14_a902658e] */
  /*    10 */       15u,  /* [MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44] */
  /*    11 */       16u,  /* [MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44] */
  /*    12 */       17u,  /* [MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44] */
  /*    13 */       19u,  /* [MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44] */
  /*    14 */       21u,  /* [MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44] */
  /*    15 */       22u,  /* [MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44] */
  /*    16 */       30u,  /* [MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44] */
  /*    17 */       21u,  /* [MRP_CC_Generic_BusOff_CN_FDCAN2_28a8fc44] */
  /*    18 */       22u,  /* [MRP_CC_Generic_BusOff_CN_FDCAN2_28a8fc44] */
  /*    19 */        0u,  /* [MRP_ESH_State] */
  /*    20 */        2u,  /* [MRP_ESH_State] */
  /*    21 */        3u,  /* [MRP_ESH_State] */
  /*    22 */        4u,  /* [MRP_ESH_State] */
  /*    23 */        5u,  /* [MRP_ESH_State] */
  /*    24 */        7u,  /* [MRP_ESH_State] */
  /*    25 */       10u,  /* [MRP_ESH_State] */
  /*    26 */       11u,  /* [MRP_ESH_State] */
  /*    27 */       19u,  /* [COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
  /*    28 */       21u,  /* [COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
  /*    29 */       22u,  /* [COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
  /*    30 */       24u,  /* [COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
  /*    31 */       25u,  /* [COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
  /*    32 */       26u,  /* [COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
  /*    33 */       27u,  /* [COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
  /*    34 */       28u,  /* [COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
  /*    35 */       31u,  /* [COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
  /*    36 */       33u   /* [COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */
};
#define BSWM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SwcModeRequestUpdateFct
**********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PartitionFunctionType, BSWM_CONST) BswM_SwcModeRequestUpdateFct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     SwcModeRequestUpdateFct                            */
  /*     0 */ BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION 
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionListQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ActionListQueue
  \brief  Variable to store action lists which shall be executed.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ActionListQueueUType, BSWM_VAR_NO_INIT) BswM_ActionListQueue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [AL_INIT_AL_Initialize] */
  /*     1 */  /* [AL_ESH_AL_ExitRun] */
  /*     2 */  /* [AL_ESH_AL_RunToPostRun] */
  /*     3 */  /* [AL_ESH_AL_WaitForNvMToShutdown] */
  /*     4 */  /* [AL_ESH_AL_WakeupToPrep] */
  /*     5 */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  /*     6 */  /* [AL_ESH_AL_WakeupToRun] */
  /*     7 */  /* [AL_ESH_AL_DemInit] */
  /*     8 */  /* [AL_ESH_AL_InitToWakeup] */
  /*     9 */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  /*    10 */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  /*    11 */  /* [AL_ESH_AL_PostRunToRun] */
  /*    12 */  /* [AL_ESH_AL_ExitPostRun] */
  /*    13 */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  /*    14 */  /* [AL_CC_AL_CN_FDCAN14_a902658e_Disable_DM] */
  /*    15 */  /* [AL_CC_AL_CN_FDCAN14_a902658e_Enable_DM] */
  /*    16 */  /* [AL_CC_AL_CN_FDCAN14_a902658e_TX_Disable] */
  /*    17 */  /* [AL_CC_AL_CN_FDCAN14_a902658e_TX_EnableNoinit] */
  /*    18 */  /* [AL_CC_AL_CN_FDCAN14_a902658e_RX_Disable] */
  /*    19 */  /* [AL_CC_AL_CN_FDCAN14_a902658e_RX_EnableNoinit] */
  /*    20 */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_Disable_DM] */
  /*    21 */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_Enable_DM] */
  /*    22 */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_RX_Disable] */
  /*    23 */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_TX_Disable] */
  /*    24 */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableNoinit] */
  /*    25 */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_NmEnable] */
  /*    26 */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_NmDisable] */
  /*    27 */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_BUSOFF_SILENT] */
  /*    28 */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_NO_COM] */
  /*    29 */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_RX_EnableReinit] */
  /*    30 */  /* [AL_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableReinit] */
  /*    31 */  /* [AL_AL_CheckNMPendingRequest] */
  /*    32 */  /* [AL_AL_NMIndicationNormal] */
  /*    33 */  /* [AL_AL_NMIndicationPrepareSleep] */
  /*    34 */  /* [AL_AL_NMIndicationReadySleep] */
  /*    35 */  /* [AL_AL_NMIndicationRepeat] */
  /*    36 */  /* [AL_AL_NMIndicationUninit] */
  /*    37 */  /* [AL_AL_Run_HardReset] */
  /*    38 */  /* [AL_AL_Run_JumpToBOOT] */
  /*    39 */  /* [AL_AL_SSM_BSW_Shutdown_execute] */
  /*    40 */  /* [AL_AL_ADAS_EcuM_stateSwitch] */
  /*    41 */  /* [AL_AL_ADAS_ECUReset] */
  /*    42 */  /* [AL_AL_SafetyGuard_SysResetReq] */
  /*    43 */  /* [AL_AL_SCCalStatus] */

#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelState
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelState
  \brief  Variable to store current mode of BswMCanSMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanSM_BswMCurrentStateType, BSWM_VAR_NO_INIT) BswM_CanSMChannelState[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44] */
  /*     1 */  /* [CANSM_CHANNEL_1, MRP_CC_CanSMIndication_CN_FDCAN14_a902658e] */

#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMChannelState
**********************************************************************************************************************/
/** 
  \var    BswM_ComMChannelState
  \brief  Variable to store current mode of BswMComMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_ModeType, BSWM_VAR_NO_INIT) BswM_ComMChannelState[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [COMM_CHANNEL_0, MRP_ESH_ComMIndication_CN_FDCAN2_28a8fc44] */
  /*     1 */  /* [COMM_CHANNEL_1, MRP_ESH_ComMIndication_CN_FDCAN14_a902658e] */

#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_DcmComState
**********************************************************************************************************************/
/** 
  \var    BswM_DcmComState
  \brief  Variable to store current mode of BswMDcmComModeRequest mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dcm_CommunicationModeType, BSWM_VAR_NO_INIT) BswM_DcmComState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [DCM_COM_0, MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44] */

#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ForcedActionListPriority
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ForcedActionListPriorityType, BSWM_VAR_NO_INIT) BswM_ForcedActionListPriority;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericState
**********************************************************************************************************************/
/** 
  \var    BswM_GenericState
  \brief  Variable to store current mode of BswMGenericRequest mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ModeType, BSWM_VAR_NO_INIT) BswM_GenericState[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [GENERIC_0, MRP_CC_Generic_BusOff_CN_FDCAN2_28a8fc44] */
  /*     1 */  /* [GENERIC_1, MRP_ESH_ComMPendingRequests] */
  /*     2 */  /* [GENERIC_2, MRP_ESH_DemInitStatus] */
  /*     3 */  /* [GENERIC_3, MRP_ESH_DemPostRunRequested] */
  /*     4 */  /* [GENERIC_4, MRP_ESH_State] */

#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Initialized
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_InitializedType, BSWM_VAR_NO_INIT) BswM_Initialized;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeRequestQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ModeRequestQueue
  \brief  Variable to store an immediate mode request which must be queued because of a current active arbitration.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ModeRequestQueueType, BSWM_VAR_NO_INIT) BswM_ModeRequestQueue[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [MRP_CC_CanSMIndication_CN_FDCAN2_28a8fc44, CANSM_CHANNEL_0] */
  /*     1 */  /* [MRP_CC_CanSMIndication_CN_FDCAN14_a902658e, CANSM_CHANNEL_1] */
  /*     2 */  /* [MRP_CC_DcmComIndication_CN_FDCAN2_28a8fc44, DCM_COM_0] */
  /*     3 */  /* [MRP_CC_Generic_BusOff_CN_FDCAN2_28a8fc44, GENERIC_0] */
  /*     4 */  /* [MRP_ESH_DemInitStatus, GENERIC_2] */
  /*     5 */  /* [MRP_ESH_State, GENERIC_4] */
  /*     6 */  /* [COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44], NM_0] */

#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_NmState
**********************************************************************************************************************/
/** 
  \var    BswM_NmState
  \brief  Variable to store current mode of BswMNmIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Nm_StateType, BSWM_VAR_NO_INIT) BswM_NmState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [NM_0, COMBINATION[MRP_CC_NmIndication_CN_FDCAN2_28a8fc44, MRP_NmIndication_CN_FDCAN2_28a8fc44]] */

#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_NvMJobState
**********************************************************************************************************************/
/** 
  \var    BswM_NvMJobState
  \brief  Variable to store current mode of BswMNvMJobModeIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(NvM_RequestResultType, BSWM_VAR_NO_INIT) BswM_NvMJobState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [NVM_JOB_0, MRP_ESH_NvMIndication] */

#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_QueueSemaphore
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_QueueSemaphoreType, BSWM_VAR_NO_INIT) BswM_QueueSemaphore;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_QueueWritten
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_QueueWrittenType, BSWM_VAR_NO_INIT) BswM_QueueWritten;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RuleStates
**********************************************************************************************************************/
/** 
  \var    BswM_RuleStates
  \brief  Stores the last execution state of the rule.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_RuleStatesUType, BSWM_VAR_NO_INIT) BswM_RuleStates;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [R_ESH_RunToPostRun] */
  /*     1 */  /* [R_ESH_RunToPostRunNested] */
  /*     2 */  /* [R_ESH_WaitToShutdown] */
  /*     3 */  /* [R_ESH_WakeupToPrep] */
  /*     4 */  /* [R_ESH_WaitToWakeup] */
  /*     5 */  /* [R_ESH_WakeupToRun] */
  /*     6 */  /* [R_ESH_DemInit] */
  /*     7 */  /* [R_ESH_InitToWakeup] */
  /*     8 */  /* [R_ESH_PostRunToPrepNested] */
  /*     9 */  /* [R_ESH_PostRunNested] */
  /*    10 */  /* [R_ESH_PostRun] */
  /*    11 */  /* [R_ESH_PrepToWait] */
  /*    12 */  /* [R_CC_CN_FDCAN14_a902658e_RX_DM] */
  /*    13 */  /* [R_CC_CN_FDCAN14_a902658e_TX] */
  /*    14 */  /* [R_CC_CN_FDCAN14_a902658e_RX] */
  /*    15 */  /* [R_CC_CN_FDCAN2_28a8fc44_RX_DM] */
  /*    16 */  /* [R_CC_CN_FDCAN2_28a8fc44_RX] */
  /*    17 */  /* [R_CC_CN_FDCAN2_28a8fc44_NM] */
  /*    18 */  /* [R_CC_CN_FDCAN2_28a8fc44_BUSOFF_SILENT] */
  /*    19 */  /* [R_CC_CN_FDCAN2_28a8fc44_TX_DISABLE] */
  /*    20 */  /* [R_CC_CN_FDCAN2_28a8fc44_NO_COM] */
  /*    21 */  /* [R_CC_CN_FDCAN2_28a8fc44_TX_ENABLE_BUSOFF] */
  /*    22 */  /* [R_CC_CN_FDCAN2_28a8fc44_TX_ENABLE] */
  /*    23 */  /* [R_BSWM_JumpToBoot] */
  /*    24 */  /* [R_BSWM_NMNormalNtfy] */
  /*    25 */  /* [R_BSWM_NMReadySleepNtfy] */
  /*    26 */  /* [R_BSWM_NmOtherNtfy] */
  /*    27 */  /* [R_BSWM_NmPrepareSleepNtfy] */
  /*    28 */  /* [R_BSWM_NmRepeatNtfy] */
  /*    29 */  /* [R_BSWM_PerfromHardReset] */
  /*    30 */  /* [R_BSWN_NmEnable] */
  /*    31 */  /* [R_BswMRule_NMCheckRequest] */
  /*    32 */  /* [R_BSWM_SSM_Shutdown_Execute] */
  /*    33 */  /* [R_BswMRule_ADAS_Shutdown_Request_CAN] */
  /*    34 */  /* [R_BswM_ADAS_ECUReset] */
  /*    35 */  /* [R_BswMRule_SafetyGuard_SysResetReq] */
  /*    36 */  /* [R_BswMRule_SCCalStatus] */

#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerState
**********************************************************************************************************************/
/** 
  \var    BswM_TimerState
  \brief  Variable to store current state of BswMTimer (STARTED, STOPPER OR EXPIRED).
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_TimerStateUType, BSWM_VAR_NO_INIT) BswM_TimerState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */

#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerValue
**********************************************************************************************************************/
/** 
  \var    BswM_TimerValue
  \brief  Variable to store current timer values.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_32
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_TimerValueUType, BSWM_VAR_NO_INIT) BswM_TimerValue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [MRP_ESH_NvM_CancelWriteAllTimer] */
  /*     1 */  /* [MRP_ESH_NvM_WriteAllTimer] */
  /*     2 */  /* [MRP_ESH_SelfRunRequestTimer] */

#define BSWM_STOP_SEC_VAR_NO_INIT_32
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/* PRQA L:GLOBALDATADECLARATIONS */

#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

VAR(Rte_ModeType_ESH_Mode, BSWM_VAR_NO_INIT) BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
VAR(Rte_ModeType_NM_State, BSWM_VAR_NO_INIT) BswM_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode;

VAR(BswM_ESH_RunRequest, BSWM_VAR_NO_INIT) Request_ESH_RunRequest_0_requestedMode;
VAR(BswM_ESH_RunRequest, BSWM_VAR_NO_INIT) Request_ESH_RunRequest_1_requestedMode;
VAR(BswM_ESH_RunRequest, BSWM_VAR_NO_INIT) Request_ESH_PostRunRequest_0_requestedMode;
VAR(BswM_ESH_RunRequest, BSWM_VAR_NO_INIT) Request_ESH_PostRunRequest_1_requestedMode;
VAR(BswM_CalDataProSCCalStatus, BSWM_VAR_NO_INIT) Request_BswM_ScCalStatus_requestedMode;
VAR(Rte_ModeType_ESH_Mode, BSWM_VAR_NO_INIT) BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode;
VAR(Rte_ModeType_MDG_CmdIgnitionState, BSWM_VAR_NO_INIT) BswM_Mode_Notification_SwcModeNotification_Current_CmdIgnition_Current_CmdIgnition;
VAR(Rte_ModeType_SYSModeRequestType, BSWM_VAR_NO_INIT) BswM_Mode_Notification_SwcModeNotification_SYSModeRequestType_SYSModeRequestType;
VAR(Rte_ModeType_SSM_SystemState_Mode, BSWM_VAR_NO_INIT) BswM_Mode_Notification_SwcModeNotification_SSM_ModeNotification_State_Mode;
VAR(Rte_ModeType_DcmEcuReset, BSWM_VAR_NO_INIT) BswM_Mode_Notification_SwcModeNotification_ADAS_ECU_Reset_DcmEcuReset;
VAR(Rte_ModeType_SafetyGuard_BSWM_SafeMode, BSWM_VAR_NO_INIT) BswM_Mode_Notification_SwcModeNotification_SafetyGuard_SysResetReq_Mode;


VAR(boolean, BSWM_VAR_NO_INIT) BswM_PreInitialized;
#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"


#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ FUNCTIONS
 ----------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  BswM_Action_RuleHandler()
 **********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_RuleHandler(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType actionListIndex;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if ( BSWM_DEV_ERROR_DETECT == STD_ON )
  if (handleId < BswM_GetSizeOfRules(partitionIdx))
#endif
  {
    SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    actionListIndex = BswM_GetFctPtrOfRules(handleId, partitionIdx)(partitionIdx); /* SBSW_BSWM_RULEFCTPTR */
    SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if(actionListIndex < BswM_GetSizeOfActionLists(partitionIdx))
    {
      retVal = BswM_GetFctPtrOfActionLists(actionListIndex, partitionIdx)(partitionIdx); /* SBSW_BSWM_ACTIONLISTFCTPTR */
    }
    else
    {
      retVal = E_OK;
    }
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
}

/**********************************************************************************************************************
 *  BswM_UpdateRuleStates()
 **********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateRuleStates(BswM_SizeOfRuleStatesType ruleId,
                                                                   BswM_RuleStatesType state,
                                                                   BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  if (ruleId < BswM_GetSizeOfRuleStates(partitionIdx))
  {
    BswM_SetRuleStates(ruleId, state, partitionIdx); /* SBSW_BSWM_SETRULESTATE */
  }

  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  BswM_UpdateTimer()
 **********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx,
                                                              BswM_SizeOfTimerValueType timerId,
                                                              BswM_TimerValueType value)
{
  if (timerId < BswM_GetSizeOfTimerValue(partitionIdx))
  {
      SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      BswM_SetTimerValue(timerId, value, partitionIdx); /* SBSW_BSWM_SETTIMER */
      BswM_SetTimerState(timerId, (BswM_TimerStateType)((value != 0u) ? BSWM_TIMER_STARTED : BSWM_TIMER_STOPPED), partitionIdx); /* SBSW_BSWM_SETTIMER */
      SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = 0xFFu;
  BswM_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode = 0xFFu;
  Request_ESH_RunRequest_0_requestedMode = RELEASED;
  Request_ESH_RunRequest_1_requestedMode = RELEASED;
  Request_ESH_PostRunRequest_0_requestedMode = RELEASED;
  Request_ESH_PostRunRequest_1_requestedMode = RELEASED;
  Request_BswM_ScCalStatus_requestedMode = SC_CAL_NOT_STARTED;
  BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_STARTUP;
  BswM_Mode_Notification_SwcModeNotification_Current_CmdIgnition_Current_CmdIgnition = RTE_MODE_MDG_CmdIgnitionState_CmdIgnitionState_INVALID;
  BswM_Mode_Notification_SwcModeNotification_SYSModeRequestType_SYSModeRequestType = RTE_MODE_SYSModeRequestType_SYS_REQ_INIT;
  BswM_Mode_Notification_SwcModeNotification_SSM_ModeNotification_State_Mode = RTE_MODE_SSM_SystemState_Mode_SSM_STATE_BOOTING;
  BswM_Mode_Notification_SwcModeNotification_ADAS_ECU_Reset_DcmEcuReset = RTE_MODE_DcmEcuReset_NONE;
  BswM_Mode_Notification_SwcModeNotification_SafetyGuard_SysResetReq_Mode = RTE_MODE_SafetyGuard_BSWM_SafeMode_SAFETTYGUARD_SAFASTATE_NORMAL;
  (void)BswM_ActionList_INIT_AL_Initialize(partitionIdx);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  BswM_ModeNotificationFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_ModeNotificationFct_BSWM_SINGLEPARTITION(void)
{
  if(BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode != 0xFFu)
  {
    if(Rte_Switch_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode) == RTE_E_OK)
    {
      BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = 0xFFu;
    }
  }
  if(BswM_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode != 0xFFu)
  {
    if(Rte_Switch_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode(BswM_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode) == RTE_E_OK)
    {
      BswM_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode = 0xFFu;
    }
  }
}

/**********************************************************************************************************************
 *  BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION(void)
{
  uint32 mode;
  mode = Rte_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode();
  if (mode != RTE_TRANSITION_ESH_Mode)
  {
    BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode = (Rte_ModeType_ESH_Mode)mode;
  }
  mode = Rte_Mode_Notification_SwcModeNotification_Current_CmdIgnition_Current_CmdIgnition();
  if (mode != RTE_TRANSITION_MDG_CmdIgnitionState)
  {
    BswM_Mode_Notification_SwcModeNotification_Current_CmdIgnition_Current_CmdIgnition = (Rte_ModeType_MDG_CmdIgnitionState)mode;
  }
  mode = Rte_Mode_Notification_SwcModeNotification_SYSModeRequestType_SYSModeRequestType();
  if (mode != RTE_TRANSITION_SYSModeRequestType)
  {
    BswM_Mode_Notification_SwcModeNotification_SYSModeRequestType_SYSModeRequestType = (Rte_ModeType_SYSModeRequestType)mode;
  }
  mode = Rte_Mode_Notification_SwcModeNotification_SSM_ModeNotification_State_Mode();
  if (mode != RTE_TRANSITION_SSM_SystemState_Mode)
  {
    BswM_Mode_Notification_SwcModeNotification_SSM_ModeNotification_State_Mode = (Rte_ModeType_SSM_SystemState_Mode)mode;
  }
  mode = Rte_Mode_Notification_SwcModeNotification_ADAS_ECU_Reset_DcmEcuReset();
  if (mode != RTE_TRANSITION_DcmEcuReset)
  {
    BswM_Mode_Notification_SwcModeNotification_ADAS_ECU_Reset_DcmEcuReset = (Rte_ModeType_DcmEcuReset)mode;
  }
  mode = Rte_Mode_Notification_SwcModeNotification_SafetyGuard_SysResetReq_Mode();
  if (mode != RTE_TRANSITION_SafetyGuard_BSWM_SafeMode)
  {
    BswM_Mode_Notification_SwcModeNotification_SafetyGuard_SysResetReq_Mode = (Rte_ModeType_SafetyGuard_BSWM_SafeMode)mode;
  }
  (void)Rte_Read_Request_ESH_RunRequest_0_requestedMode(&Request_ESH_RunRequest_0_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_RunRequest_1_requestedMode(&Request_ESH_RunRequest_1_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_PostRunRequest_0_requestedMode(&Request_ESH_PostRunRequest_0_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_PostRunRequest_1_requestedMode(&Request_ESH_PostRunRequest_1_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_BswM_ScCalStatus_requestedMode(&Request_BswM_ScCalStatus_requestedMode); /* SBSW_BSWM_RTE_READ */
}

/**********************************************************************************************************************
 *  BswMActionListFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_ActionList_INIT_AL_Initialize
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_INIT_AL_Initialize(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_ESH_OnEnterWakeup();
  BswM_AL_SetProgrammableInterrupts();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Adc_Init(&ADC_INIT_CONFIG_PC);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Ea_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Eep_30_XXi2c01_Init(&Eep_30_XXi2c01_Runtime);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  NvM_Init();
  /*lint -restore */
  BswM_INIT_NvMReadAll();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Wdg_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanTrcv_30_Tja1043_Init(CanTrcv_30_Tja1043_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Can_30_Mcan_Init(Can_30_Mcan_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Crypto_30_vHsm_WaitForHsmRam();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Crypto_30_vHsm_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanIf_Init(CanIf_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CryIf_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  WdgM_Init(&WdgMConfig_Mode0_core0);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Com_Init(Com_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  PduR_Init(PduR_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanSM_Init(CanSM_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanNm_Init(CanNm_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Nm_Init(Nm_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanTp_Init(CanTp_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanXcp_Init(NULL_PTR);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Xcp_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Csm_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  vDam_Init(vDam_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  vDiagSecAcc_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  ComM_Init(ComM_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dcm_Init(NULL_PTR);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dem_Init(Dem_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  IoHwAb_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  vRoE_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  ComM_PostInit();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Nm_PostInit();
  /*lint -restore */
  Com_EnableReceptionDM(ComConf_ComIPduGroup_CVADAS_oFDCAN14_Rx_885c637a);
  (void)ComM_RequestComMode(ComMConf_ComMUser_CN_FDCAN2_3de30c40, COMM_FULL_COMMUNICATION);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_FDCAN2_28a8fc44, TRUE);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_FDCAN14_a902658e, TRUE);
  Com_EnableReceptionDM(ComConf_ComIPduGroup_CVADAS_oFDCAN2_Rx_6371d032);
  Com_IpduGroupStart(ComConf_ComIPduGroup_CVADAS_oFDCAN14_Rx_885c637a, FALSE);
  Com_IpduGroupStart(ComConf_ComIPduGroup_CVADAS_oFDCAN14_Tx_de06c4fc, FALSE);
  Com_IpduGroupStart(ComConf_ComIPduGroup_CVADAS_oFDCAN2_Rx_6371d032, TRUE);
  Com_IpduGroupStart(ComConf_ComIPduGroup_CVADAS_oFDCAN2_Tx_352b77b4, TRUE);
  Com_IpduGroupStart(ComConf_ComIPduGroup_CVADAS_oFDCAN2_Tx_352b77b4, FALSE);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Rte_Start();
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_ExitRun
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ExitRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  ESH_ComM_CheckPendingRequests();
  (void)BswM_Action_RuleHandler(BSWM_ID_RULE_ESH_RunToPostRunNested, partitionIdx);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_RunToPostRun
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_RunToPostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_FDCAN2_28a8fc44, FALSE);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_FDCAN14_a902658e, FALSE);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  EcuM_ClearValidatedWakeupEvent(ECUM_WKSOURCE_ALL_SOURCES);
  /*lint -restore */
  BswM_ESH_OnEnterPostRun();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_POSTRUN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_POST_RUN);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_WaitForNvMToShutdown
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WaitForNvMToShutdown(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_NvM_WriteAllTimer, 0u);
  BswM_ESH_OnEnterShutdown();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  (void)EcuM_GoToSelectedShutdownTarget();
  /*lint -restore */
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_SHUTDOWN;
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_WakeupToPrep
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WakeupToPrep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_ESH_OnEnterPrepShutdown();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_SHUTDOWN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_WaitForNvMWakeup
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WaitForNvMWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_NvM_WriteAllTimer, 0u);
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_NvM_CancelWriteAllTimer, 50u);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  NvM_CancelWriteAll();
  /*lint -restore */
  BswM_ESH_OnEnterWakeup();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_WAKEUP;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_WakeupToRun
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WakeupToRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_NvM_CancelWriteAllTimer, 0u);
  (void)BswM_Action_RuleHandler(BSWM_ID_RULE_ESH_DemInit, partitionIdx);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_FDCAN2_28a8fc44, TRUE);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_FDCAN14_a902658e, TRUE);
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_SelfRunRequestTimer, 10u);
  BswM_ESH_OnEnterRun();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_RUN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_RUN);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_DemInit
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_DemInit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dem_Init(Dem_Config_Ptr);
  /*lint -restore */
  BswM_RequestMode(BSWM_GENERIC_ESH_DemInitStatus, BSWM_GENERICVALUE_ESH_DemInitStatus_DEM_INITIALIZED);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_InitToWakeup
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_InitToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_ESH_OnEnterWakeup();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_WAKEUP;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_PostRunToPrepShutdown
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_PostRunToPrepShutdown(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dem_Shutdown();
  /*lint -restore */
  BswM_RequestMode(BSWM_GENERIC_ESH_DemInitStatus, BSWM_GENERICVALUE_ESH_DemInitStatus_DEM_NOT_INITIALIZED);
  BswM_ESH_OnEnterPrepShutdown();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_SHUTDOWN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  (void)BswM_Action_RuleHandler(BSWM_ID_RULE_ESH_PostRunToPrepNested, partitionIdx);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_PostRunToRun
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_PostRunToRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_FDCAN2_28a8fc44, TRUE);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_FDCAN14_a902658e, TRUE);
  BswM_UpdateTimer(partitionIdx, BSWM_TMR_ESH_SelfRunRequestTimer, 10u);
  BswM_ESH_OnEnterRun();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_RUN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_RUN);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_ExitPostRun
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ExitPostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  ESH_ComM_CheckPendingRequests();
  ESH_Dem_PostRunRequested();
  (void)BswM_Action_RuleHandler(BSWM_ID_RULE_ESH_PostRunNested, partitionIdx);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_PrepShutdownToWaitForNvM
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_PrepShutdownToWaitForNvM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_Disable_DM
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_Disable_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_DisableReceptionDM(ComConf_ComIPduGroup_CVADAS_oFDCAN14_Rx_885c637a);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_Enable_DM
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_Enable_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_EnableReceptionDM(ComConf_ComIPduGroup_CVADAS_oFDCAN14_Rx_885c637a);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_TX_Disable
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_TX_Disable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_CVADAS_oFDCAN14_Tx_de06c4fc);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_TX_EnableNoinit
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_TX_EnableNoinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStart(ComConf_ComIPduGroup_CVADAS_oFDCAN14_Tx_de06c4fc, FALSE);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_RX_Disable
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_RX_Disable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_CVADAS_oFDCAN14_Rx_885c637a);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_RX_EnableNoinit
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_RX_EnableNoinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStart(ComConf_ComIPduGroup_CVADAS_oFDCAN14_Rx_885c637a, FALSE);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_Disable_DM
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_Disable_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_DisableReceptionDM(ComConf_ComIPduGroup_CVADAS_oFDCAN2_Rx_6371d032);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_Enable_DM
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_Enable_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_EnableReceptionDM(ComConf_ComIPduGroup_CVADAS_oFDCAN2_Rx_6371d032);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_RX_Disable
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_RX_Disable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_CVADAS_oFDCAN2_Rx_6371d032);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_TX_Disable
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_TX_Disable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_CVADAS_oFDCAN2_Tx_352b77b4);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableNoinit
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableNoinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStart(ComConf_ComIPduGroup_CVADAS_oFDCAN2_Tx_352b77b4, FALSE);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_NmEnable
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_NmEnable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  (void)Nm_EnableCommunication(ComMConf_ComMChannel_CN_FDCAN2_28a8fc44);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_NmDisable
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_NmDisable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  (void)Nm_DisableCommunication(ComMConf_ComMChannel_CN_FDCAN2_28a8fc44);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_BUSOFF_SILENT
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_BUSOFF_SILENT(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_RequestMode(BSWM_GENERIC_CC_Generic_BusOff_CN_FDCAN2_28a8fc44, BSWM_GENERICVALUE_CC_Generic_BusOff_CN_FDCAN2_28a8fc44_BUSOFF_SILENT);
  (void)Nm_DisableCommunication(ComMConf_ComMChannel_CN_FDCAN2_28a8fc44);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_NO_COM
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_NO_COM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_RequestMode(BSWM_GENERIC_CC_Generic_BusOff_CN_FDCAN2_28a8fc44, BSWM_GENERICVALUE_CC_Generic_BusOff_CN_FDCAN2_28a8fc44_NO_COM);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_RX_EnableReinit
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_RX_EnableReinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStart(ComConf_ComIPduGroup_CVADAS_oFDCAN2_Rx_6371d032, TRUE);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableReinit
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableReinit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  Com_IpduGroupStart(ComConf_ComIPduGroup_CVADAS_oFDCAN2_Tx_352b77b4, TRUE);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_CheckNMPendingRequest
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CheckNMPendingRequest(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  ESH_ComM_CheckPendingRequests();
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_NMIndicationNormal
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NMIndicationNormal(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode = RTE_MODE_NM_State_NM_STATE_NORMAL;
  BswM_SetNewDemOperationCycleState();
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_NMIndicationPrepareSleep
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NMIndicationPrepareSleep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode = RTE_MODE_NM_State_NM_STATE_PREPARE_SLEEP;
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_NMIndicationReadySleep
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NMIndicationReadySleep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode = RTE_MODE_NM_State_NM_STATE_READY_SLEEP;
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_NMIndicationRepeat
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NMIndicationRepeat(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode = RTE_MODE_NM_State_NM_STATE_REPEAT;
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_NMIndicationUninit
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NMIndicationUninit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode = RTE_MODE_NM_State_NM_UINIT;
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Run_HardReset
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_HardReset(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  (void)EcuM_SelectShutdownTarget(ECUM_STATE_RESET, EcuMConf_EcuMResetMode_ECUM_RESET_MCU);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  EcuM_SelectShutdownCause(EcuMConf_EcuMShutdownCause_ECUM_CAUSE_DCM);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  (void)EcuM_GoToSelectedShutdownTarget();
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Run_JumpToBOOT
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_JumpToBOOT(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_AL_ResetProgrammableInterrupts();
  (void)EcuM_SelectShutdownTarget(ECUM_STATE_RESET, EcuMConf_EcuMResetMode_ECUM_RESET_BOOT);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  EcuM_SelectShutdownCause(EcuMConf_EcuMShutdownCause_ECUM_CAUSE_DCM);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  (void)EcuM_GoToSelectedShutdownTarget();
  /*lint -restore */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_SSM_BSW_Shutdown_execute
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_SSM_BSW_Shutdown_execute(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  (void)EcuM_SelectShutdownTarget(ECUM_STATE_OFF, 0);
  BSW_Shutdown();
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_ADAS_EcuM_stateSwitch
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_ADAS_EcuM_stateSwitch(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSW_SSM_Master_SetShutDownRequest();
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_ADAS_ECUReset
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_ADAS_ECUReset(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  (void)EcuM_SelectShutdownTarget(ECUM_STATE_RESET, EcuMConf_EcuMResetMode_ECUM_RESET_MCU);
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_SafetyGuard_SysResetReq
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_SafetyGuard_SysResetReq(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSW_AppDiag_InternalError_SysResetReq();
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_SCCalStatus
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_SCCalStatus(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  BSW_Set_SC_CAL_ResetType();
  /*lint -restore */
  BSW_SSM_Master_SetShutDownRequest();
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswMRuleFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_Rule_ESH_RunToPostRun
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_RunToPostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_RunToPostRunTransition. */ /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  if(((BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_RUN) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_RUN)) && (((BswM_GetComMChannelState(0, 0u) == COMM_NO_COMMUNICATION) || (BswM_GetComMChannelState(1, 0u) == COMM_NO_COMMUNICATION)) && ((Request_ESH_RunRequest_0_requestedMode == RELEASED) && (Request_ESH_RunRequest_1_requestedMode == RELEASED)) && (BswM_GetTimerState(2, 0u) == BSWM_TIMER_EXPIRED)))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_ExitRun. */
    retVal = BSWM_ID_AL_ESH_AL_ExitRun;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_RunToPostRunNested
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_RunToPostRunNested(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_ComMNoPendingRequests. */
  if(BswM_GetGenericState(1, 0u) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST)
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_RunToPostRun. */
    retVal = BSWM_ID_AL_ESH_AL_RunToPostRun;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_WaitToShutdown
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WaitToShutdown(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_WaitForNvMToShutdown. */ /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  if((BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && ((BswM_GetNvMJobState(0, 0u) != NVM_REQ_PENDING) || (BswM_GetTimerState(1, 0u) != BSWM_TIMER_STARTED)) && ((EcuM_GetValidatedWakeupEvents() == 0u) || (Request_ESH_RunRequest_0_requestedMode == RELEASED) || (Request_ESH_RunRequest_1_requestedMode == RELEASED)))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_WaitForNvMToShutdown. */
    retVal = BSWM_ID_AL_ESH_AL_WaitForNvMToShutdown;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_WakeupToPrep
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WakeupToPrep(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_WakeupToPrepShutdown. */ /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  if((BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && ((BswM_GetNvMJobState(0, 0u) != NVM_REQ_PENDING) || (BswM_GetTimerState(0, 0u) != BSWM_TIMER_STARTED)) && (EcuM_GetPendingWakeupEvents() == 0u) && ((EcuM_GetValidatedWakeupEvents() == 0u) || (Request_ESH_RunRequest_0_requestedMode == RELEASED) || (Request_ESH_RunRequest_1_requestedMode == RELEASED)) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_WAKEUP) && (BswM_GetGenericState(1, 0u) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_WakeupToPrep. */
    retVal = BSWM_ID_AL_ESH_AL_WakeupToPrep;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_WaitToWakeup
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WaitToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_WaitForNvMToWakeup. */ /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  if((BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && ((EcuM_GetValidatedWakeupEvents() != 0u) || (Request_ESH_RunRequest_1_requestedMode == REQUESTED) || (Request_ESH_RunRequest_0_requestedMode == REQUESTED)) && (BswM_GetGenericState(1, 0u) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_WaitForNvMWakeup. */
    retVal = BSWM_ID_AL_ESH_AL_WaitForNvMWakeup;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_WakeupToRun
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WakeupToRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_WakeupToRun. */ /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  if((BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && ((EcuM_GetValidatedWakeupEvents() != 0u) || (Request_ESH_RunRequest_1_requestedMode == REQUESTED) || (Request_ESH_RunRequest_0_requestedMode == REQUESTED)) && ((BswM_GetNvMJobState(0, 0u) != NVM_REQ_PENDING) || (BswM_GetTimerState(0, 0u) != BSWM_TIMER_STARTED)) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_WAKEUP) && (BswM_GetGenericState(1, 0u) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_WakeupToRun. */
    retVal = BSWM_ID_AL_ESH_AL_WakeupToRun;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_DemInit
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_DemInit(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_DemNotInitialized. */
  if(BswM_GetGenericState(2, 0u) == BSWM_GENERICVALUE_ESH_DemInitStatus_DEM_NOT_INITIALIZED)
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_DemInit. */
    retVal = BSWM_ID_AL_ESH_AL_DemInit;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_InitToWakeup
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_InitToWakeup(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_InitToWakeup. */
  if(BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_INIT)
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_InitToWakeup. */
    retVal = BSWM_ID_AL_ESH_AL_InitToWakeup;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_PostRunToPrepNested
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRunToPrepNested(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_Dem_PostRunRequested. */
  if(((Request_ESH_PostRunRequest_0_requestedMode == RELEASED) && (Request_ESH_PostRunRequest_1_requestedMode == RELEASED)) && (BswM_GetGenericState(3, 0u) == BSWM_GENERICVALUE_ESH_DemPostRunRequested_FALSE))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_PostRunToPrepShutdown. */
    retVal = BSWM_ID_AL_ESH_AL_PostRunToPrepShutdown;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_PostRunNested
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRunNested(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal;
  /* Evaluate logical expression ESH_LE_PostRunToRun. */
  if(((Request_ESH_RunRequest_0_requestedMode == REQUESTED) || (Request_ESH_RunRequest_1_requestedMode == REQUESTED)) || ((EcuM_GetValidatedWakeupEvents() != 0u) || (Request_ESH_RunRequest_1_requestedMode == REQUESTED) || (Request_ESH_RunRequest_0_requestedMode == REQUESTED)))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_PostRunToRun. */
    retVal = BSWM_ID_AL_ESH_AL_PostRunToRun;
  }
  else
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck. */
    retVal = BSWM_ID_AL_ESH_AL_ESH_PostRunToPrepCheck;
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_PostRun
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRun(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_PostRun. */
  if((BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_POST_RUN) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_POSTRUN))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_ExitPostRun. */
    retVal = BSWM_ID_AL_ESH_AL_ExitPostRun;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_PrepToWait
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PrepToWait(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression ESH_LE_PrepShutdownToWaitForNvM. */
  if((BswM_GetGenericState(4, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_SHUTDOWN))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_PrepShutdownToWaitForNvM. */
    retVal = BSWM_ID_AL_ESH_AL_PrepShutdownToWaitForNvM;
  }
  /* No false action list configured. */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_FDCAN14_a902658e_RX_DM
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN14_a902658e_RX_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_FDCAN14_a902658e_RX_DM. */
  if(BswM_GetCanSMChannelState(1, 0u) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN14_a902658e_RX_DM, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN14_a902658e_RX_DM, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_Enable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN14_a902658e_Enable_DM;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN14_a902658e_RX_DM, partitionIdx) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN14_a902658e_RX_DM, BSWM_FALSE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_Disable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN14_a902658e_Disable_DM;
    }
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_FDCAN14_a902658e_TX
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN14_a902658e_TX(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_FDCAN14_a902658e_TX. */
  if(BswM_GetCanSMChannelState(1, 0u) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN14_a902658e_TX, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN14_a902658e_TX, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_TX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN14_a902658e_TX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN14_a902658e_TX, partitionIdx) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN14_a902658e_TX, BSWM_FALSE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_TX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN14_a902658e_TX_Disable;
    }
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_FDCAN14_a902658e_RX
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN14_a902658e_RX(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_FDCAN14_a902658e_RX. */
  if(BswM_GetCanSMChannelState(1, 0u) != CANSM_BSWM_NO_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN14_a902658e_RX, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN14_a902658e_RX, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_RX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN14_a902658e_RX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN14_a902658e_RX, partitionIdx) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN14_a902658e_RX, BSWM_FALSE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN14_a902658e_RX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN14_a902658e_RX_Disable;
    }
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_FDCAN2_28a8fc44_RX_DM
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_RX_DM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_FDCAN2_28a8fc44_RX_DM. */
  if((BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_ENABLE_TX_NORM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NORMAL) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_ENABLE_TX_NM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_ENABLE_TX_NORM_NM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NORM_NM))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_RX_DM, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_RX_DM, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_Enable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN2_28a8fc44_Enable_DM;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_RX_DM, partitionIdx) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_RX_DM, BSWM_FALSE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_Disable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN2_28a8fc44_Disable_DM;
    }
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_FDCAN2_28a8fc44_RX
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_RX(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_FDCAN2_28a8fc44_RX. */
  if((BswM_GetCanSMChannelState(0, 0u) != CANSM_BSWM_NO_COMMUNICATION) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_ENABLE_TX_NORM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NORMAL) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_ENABLE_TX_NM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_ENABLE_TX_NORM_NM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NORM_NM))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_RX, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_RX, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_RX_EnableReinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN2_28a8fc44_RX_EnableReinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_RX, partitionIdx) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_RX, BSWM_FALSE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_RX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN2_28a8fc44_RX_Disable;
    }
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_FDCAN2_28a8fc44_NM
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_NM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_FDCAN2_28a8fc44_NM. */
  if((BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_DISABLE_TX_NM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_TX_NM) || (BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_DISABLE_TX_NORM_NM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_TX_NORM_NM))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_NM, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_NM, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_NmDisable. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN2_28a8fc44_NmDisable;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_NM, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_FDCAN2_28a8fc44_BUSOFF_SILENT
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_BUSOFF_SILENT(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CanSMIndication_CN_FDCAN2_28a8fc44_BUSOFF_SILENT. */
  if((BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_BUS_OFF) || (BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_SILENT_COMMUNICATION))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_BUSOFF_SILENT, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_BUSOFF_SILENT, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_BUSOFF_SILENT. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN2_28a8fc44_BUSOFF_SILENT;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_BUSOFF_SILENT, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_FDCAN2_28a8fc44_TX_DISABLE
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_TX_DISABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_FDCAN2_28a8fc44_TX_DISABLE. */
  if((BswM_GetCanSMChannelState(0, 0u) != CANSM_BSWM_FULL_COMMUNICATION) || (BswM_GetNmState(0, 0u) == NM_STATE_BUS_SLEEP) || (BswM_GetNmState(0, 0u) == NM_STATE_PREPARE_BUS_SLEEP) || (BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_DISABLE_TX_NORM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_TX_NORMAL) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_TX_NM) || (BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_DISABLE_TX_NORM_NM) || (BswM_GetDcmComState(0, 0u) == DCM_DISABLE_RX_TX_NORM_NM))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_TX_DISABLE, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_TX_DISABLE, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_TX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN2_28a8fc44_TX_Disable;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_TX_DISABLE, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_FDCAN2_28a8fc44_NO_COM
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_NO_COM(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CanSMIndication_CN_FDCAN2_28a8fc44_EQ_CANSM_BSWM_NO_COMMUNICATION. */
  if(BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_NO_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_NO_COM, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_NO_COM, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_NO_COM. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN2_28a8fc44_NO_COM;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_NO_COM, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_FDCAN2_28a8fc44_TX_ENABLE_BUSOFF
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_TX_ENABLE_BUSOFF(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_FDCAN2_28a8fc44_TX_ENABLE. */
  if((BswM_GetDcmComState(0, 0u) != DCM_ENABLE_RX_TX_NM) && (BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION) && (BswM_GetNmState(0, 0u) != NM_STATE_BUS_SLEEP) && (BswM_GetNmState(0, 0u) != NM_STATE_PREPARE_BUS_SLEEP) && (BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_CC_Generic_BusOff_CN_FDCAN2_28a8fc44_BUSOFF_SILENT) && (BswM_GetDcmComState(0, 0u) != DCM_ENABLE_RX_DISABLE_TX_NORM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NORMAL) && (BswM_GetDcmComState(0, 0u) != DCM_ENABLE_RX_DISABLE_TX_NM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NM) && (BswM_GetDcmComState(0, 0u) != DCM_ENABLE_RX_DISABLE_TX_NORM_NM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NORM_NM))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_TX_ENABLE_BUSOFF, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_TX_ENABLE_BUSOFF, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableNoinit;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_TX_ENABLE_BUSOFF, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CN_FDCAN2_28a8fc44_TX_ENABLE
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CN_FDCAN2_28a8fc44_TX_ENABLE(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression CC_LE_CN_FDCAN2_28a8fc44_TX_ENABLE_REINIT. */
  if((BswM_GetDcmComState(0, 0u) != DCM_ENABLE_RX_TX_NM) && (BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION) && (BswM_GetNmState(0, 0u) != NM_STATE_BUS_SLEEP) && (BswM_GetNmState(0, 0u) != NM_STATE_PREPARE_BUS_SLEEP) && (BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_CC_Generic_BusOff_CN_FDCAN2_28a8fc44_NO_COM) && (BswM_GetDcmComState(0, 0u) != DCM_ENABLE_RX_DISABLE_TX_NORM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NORMAL) && (BswM_GetDcmComState(0, 0u) != DCM_ENABLE_RX_DISABLE_TX_NM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NM) && (BswM_GetDcmComState(0, 0u) != DCM_ENABLE_RX_DISABLE_TX_NORM_NM) && (BswM_GetDcmComState(0, 0u) != DCM_DISABLE_RX_TX_NORM_NM))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_TX_ENABLE, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_TX_ENABLE, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableReinit. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN2_28a8fc44_TX_EnableReinit;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CN_FDCAN2_28a8fc44_TX_ENABLE, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_BSWM_JumpToBoot
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_JumpToBoot(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_JumpToBootloader. */
  if(BswM_Mode_Notification_SwcModeNotification_SYSModeRequestType_SYSModeRequestType == RTE_MODE_SYSModeRequestType_SYS_REQ_JUMPTOBOOT)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_BSWM_JumpToBoot, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_JumpToBoot, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_Run_JumpToBOOT. */
      retVal = BSWM_ID_AL_AL_Run_JumpToBOOT;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_JumpToBoot, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_BSWM_NMNormalNtfy
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_NMNormalNtfy(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_NM_INDICATION_NORMAL_NTY. */
  if(BswM_GetNmState(0, 0u) == NM_STATE_NORMAL_OPERATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_BSWM_NMNormalNtfy, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_NMNormalNtfy, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_NMIndicationNormal. */
      retVal = BSWM_ID_AL_AL_NMIndicationNormal;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_NMNormalNtfy, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_BSWM_NMReadySleepNtfy
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_NMReadySleepNtfy(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_NM_INDICATION_READY_SLEEP_NTY. */
  if(BswM_GetNmState(0, 0u) == NM_STATE_READY_SLEEP)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_BSWM_NMReadySleepNtfy, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_NMReadySleepNtfy, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_NMIndicationReadySleep. */
      retVal = BSWM_ID_AL_AL_NMIndicationReadySleep;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_NMReadySleepNtfy, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_BSWM_NmOtherNtfy
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_NmOtherNtfy(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_NM_INDICATION_OTHER_NTY. */
  if((BswM_GetNmState(0, 0u) != NM_STATE_NORMAL_OPERATION) && (BswM_GetNmState(0, 0u) != NM_STATE_READY_SLEEP) && (BswM_GetNmState(0, 0u) != NM_STATE_PREPARE_BUS_SLEEP) && (BswM_GetNmState(0, 0u) != NM_STATE_REPEAT_MESSAGE))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_BSWM_NmOtherNtfy, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_NmOtherNtfy, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_NMIndicationUninit. */
      retVal = BSWM_ID_AL_AL_NMIndicationUninit;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_NmOtherNtfy, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_BSWM_NmPrepareSleepNtfy
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_NmPrepareSleepNtfy(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_NM_INDICATION_PREPARE_SLEEP_NTY. */
  if(BswM_GetNmState(0, 0u) == NM_STATE_PREPARE_BUS_SLEEP)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_BSWM_NmPrepareSleepNtfy, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_NmPrepareSleepNtfy, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_NMIndicationPrepareSleep. */
      retVal = BSWM_ID_AL_AL_NMIndicationPrepareSleep;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_NmPrepareSleepNtfy, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_BSWM_NmRepeatNtfy
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_NmRepeatNtfy(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_NM_INDICATION_REPEAT_NTY. */
  if(BswM_GetNmState(0, 0u) == NM_STATE_REPEAT_MESSAGE)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_BSWM_NmRepeatNtfy, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_NmRepeatNtfy, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_NMIndicationRepeat. */
      retVal = BSWM_ID_AL_AL_NMIndicationRepeat;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_NmRepeatNtfy, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_BSWM_PerfromHardReset
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_PerfromHardReset(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_HardReset. */
  if(BswM_Mode_Notification_SwcModeNotification_SYSModeRequestType_SYSModeRequestType == RTE_MODE_SYSModeRequestType_SYS_REQ_HARDRESET)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_BSWM_PerfromHardReset, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_PerfromHardReset, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_Run_HardReset. */
      retVal = BSWM_ID_AL_AL_Run_HardReset;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_PerfromHardReset, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_BSWN_NmEnable
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWN_NmEnable(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_NMEnable. */
  if((BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_TX_NM) || (BswM_GetDcmComState(0, 0u) == DCM_ENABLE_RX_TX_NORM_NM))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_BSWN_NmEnable, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_BSWN_NmEnable, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_CC_AL_CN_FDCAN2_28a8fc44_NmEnable. */
      retVal = BSWM_ID_AL_CC_AL_CN_FDCAN2_28a8fc44_NmEnable;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_BSWN_NmEnable, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_BswMRule_NMCheckRequest
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BswMRule_NMCheckRequest(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_CheckNMRequest. */
  if((BswM_GetNmState(0, 0u) != NM_STATE_BUS_SLEEP) || (BswM_Mode_Notification_SwcModeNotification_Current_CmdIgnition_Current_CmdIgnition == RTE_MODE_MDG_CmdIgnitionState_CmdIgnitionState_ON))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_BswMRule_NMCheckRequest, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_BswMRule_NMCheckRequest, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_CheckNMPendingRequest. */
      retVal = BSWM_ID_AL_AL_CheckNMPendingRequest;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_BswMRule_NMCheckRequest, partitionIdx) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_BswMRule_NMCheckRequest, BSWM_FALSE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_CheckNMPendingRequest. */
      retVal = BSWM_ID_AL_AL_CheckNMPendingRequest;
    }
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_BSWM_SSM_Shutdown_Execute
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BSWM_SSM_Shutdown_Execute(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_BSW_SSM_Systemstate_Expression. */
  if(BswM_Mode_Notification_SwcModeNotification_SSM_ModeNotification_State_Mode == RTE_MODE_SSM_SystemState_Mode_SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_BSWM_SSM_Shutdown_Execute, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_SSM_Shutdown_Execute, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_SSM_BSW_Shutdown_execute. */
      retVal = BSWM_ID_AL_AL_SSM_BSW_Shutdown_execute;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_BSWM_SSM_Shutdown_Execute, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_BswMRule_ADAS_Shutdown_Request_CAN
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BswMRule_ADAS_Shutdown_Request_CAN(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_ADAS_Shutdown_Request. */
  if(BswM_GetNmState(0, 0u) == NM_STATE_BUS_SLEEP)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_BswMRule_ADAS_Shutdown_Request_CAN, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_BswMRule_ADAS_Shutdown_Request_CAN, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_ADAS_EcuM_stateSwitch. */
      retVal = BSWM_ID_AL_AL_ADAS_EcuM_stateSwitch;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_BswMRule_ADAS_Shutdown_Request_CAN, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_BswM_ADAS_ECUReset
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BswM_ADAS_ECUReset(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_ADAS_ECUResetRequest. */
  if(BswM_Mode_Notification_SwcModeNotification_ADAS_ECU_Reset_DcmEcuReset == RTE_MODE_DcmEcuReset_EXECUTE)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_BswM_ADAS_ECUReset, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_BswM_ADAS_ECUReset, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_ADAS_ECUReset. */
      retVal = BSWM_ID_AL_AL_ADAS_ECUReset;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_BswM_ADAS_ECUReset, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_BswMRule_SafetyGuard_SysResetReq
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BswMRule_SafetyGuard_SysResetReq(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_BswMRule_SafetyGuard_SysResetReq. */
  if(BswM_Mode_Notification_SwcModeNotification_SafetyGuard_SysResetReq_Mode == RTE_MODE_SafetyGuard_BSWM_SafeMode_SAFETYGUARD_SAFESTATE_2_RESET)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_BswMRule_SafetyGuard_SysResetReq, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_BswMRule_SafetyGuard_SysResetReq, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_SafetyGuard_SysResetReq. */
      retVal = BSWM_ID_AL_AL_SafetyGuard_SysResetReq;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_BswMRule_SafetyGuard_SysResetReq, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_BswMRule_SCCalStatus
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_BswMRule_SCCalStatus(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST(partitionIdx);
  /* Evaluate logical expression LE_SCCalStatus. */
  if(Request_BswM_ScCalStatus_requestedMode == SC_CAL_FINISHED)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_BswMRule_SCCalStatus, partitionIdx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_BswMRule_SCCalStatus, BSWM_TRUE, partitionIdx);
      /* Return triggered action list BswM_ActionList_AL_SCCalStatus. */
      retVal = BSWM_ID_AL_AL_SCCalStatus;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_BswMRule_SCCalStatus, BSWM_FALSE, partitionIdx);
    /* No false action list configured. */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}


#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

