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
 *            Module: WdgM
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WdgM_Cfg.c
 *   Generation Time: 2025-01-23 15:17:23
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define WDGM_CFG_C


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "WdgM.h"

/**********************************************************************************************************************
 *  VERSION INFORMATION AND CHECK
 *********************************************************************************************************************/
#define WDGM_CFG_C_MAJOR_VERSION (6u) 
#define WDGM_CFG_C_MINOR_VERSION (0u) 
#define WDGM_CFG_C_PATCH_VERSION (2u) 


/* Check the version of WdgM_Cfg header file */
#if ( (WDGM_CFG_MAJOR_VERSION != WDGM_CFG_C_MAJOR_VERSION) \
   || (WDGM_CFG_MINOR_VERSION != WDGM_CFG_C_MINOR_VERSION) \
   || (WDGM_CFG_PATCH_VERSION != WDGM_CFG_C_PATCH_VERSION) )
# error "Version numbers of WdgM_Cfg.c and WdgM_Cfg.h are inconsistent!"
#endif

#if !defined (WDGM_LOCAL) /* COV_WDGM_COMPATIBILITY */
# define WDGM_LOCAL static
#endif

#define WDGM_GLOBAL_SHARED_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for global shared data */ 
WDGM_LOCAL VAR(WdgM_DataGSType, WDGM_VAR_NOINIT) StatusGS_core0; 
WDGM_LOCAL VAR(WdgM_EntityGSType, WDGM_VAR_NOINIT) EntityGS [WDGM_NR_OF_ENTITIES]; 
#define WDGM_GLOBAL_SHARED_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 


#define WDGM_SE0_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'WdgM_SE_MCU1_0' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_0; 
#define WDGM_SE0_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE0_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'WdgMAliveCP_MCU1_0' in 'WdgM_SE_MCU1_0' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_0; 
#define WDGM_SE0_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE1_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'WdgM_SE_MCU2_0' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_1; 
#define WDGM_SE1_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE1_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'WdgMAliveCP_MCU2_0' in 'WdgM_SE_MCU2_0' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_1; 
#define WDGM_SE1_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE2_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'WdgM_SE_MCU2_1' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_2; 
#define WDGM_SE2_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE2_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'WdgMAliveCP_MCU2_1' in 'WdgM_SE_MCU2_1' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_2; 
#define WDGM_SE2_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE3_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'WdgM_SE_MPU1_0' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_3; 
#define WDGM_SE3_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE3_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'WdgMAliveCP_MPU1_0' in 'WdgM_SE_MPU1_0' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_3; 
#define WDGM_SE3_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE4_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'WdgM_SE_Safety_Task_00_10ms' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_4; 
#define WDGM_SE4_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE4_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'WdgMAliveCP_Safety_Task_00_10ms' in 'WdgM_SE_Safety_Task_00_10ms' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_4; 
#define WDGM_SE4_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE5_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'WdgM_SE_Safety_Task_01_10ms' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_5; 
#define WDGM_SE5_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE5_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'WdgMAliveCP_Safety_Task_01_10ms' in 'WdgM_SE_Safety_Task_01_10ms' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_5; 
#define WDGM_SE5_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE6_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'WdgM_SE_Safety_Com_Task_10ms' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_6; 
#define WDGM_SE6_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE6_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'WdgMAliveCP_Safety_Com_Task_10ms' in 'WdgM_SE_Safety_Com_Task_10ms' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_6; 
#define WDGM_SE6_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE7_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'WdgM_SE_Safety_Task_200ms' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_7; 
#define WDGM_SE7_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE7_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'WdgMAliveCP_Safety_Task_200ms' in 'WdgM_SE_Safety_Task_200ms' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_7; 
#define WDGM_SE7_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
 
#define WDGM_GLOBAL_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
/* Global Status for Supervised Entities */ 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_0; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_1; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_2; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_3; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_4; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_5; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_6; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_7; 
 
/* Global Alive Counters for checkpoint 'WdgMAliveCP_MCU1_0' in supervised entity 'WdgM_SE_MCU1_0' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_0; 
 
/* Global Alive Counters for checkpoint 'WdgMAliveCP_MCU2_0' in supervised entity 'WdgM_SE_MCU2_0' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_1; 
 
/* Global Alive Counters for checkpoint 'WdgMAliveCP_MCU2_1' in supervised entity 'WdgM_SE_MCU2_1' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_2; 
 
/* Global Alive Counters for checkpoint 'WdgMAliveCP_MPU1_0' in supervised entity 'WdgM_SE_MPU1_0' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_3; 
 
/* Global Alive Counters for checkpoint 'WdgMAliveCP_Safety_Task_00_10ms' in supervised entity 'WdgM_SE_Safety_Task_00_10ms' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_4; 
 
/* Global Alive Counters for checkpoint 'WdgMAliveCP_Safety_Task_01_10ms' in supervised entity 'WdgM_SE_Safety_Task_01_10ms' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_5; 
 
/* Global Alive Counters for checkpoint 'WdgMAliveCP_Safety_Com_Task_10ms' in supervised entity 'WdgM_SE_Safety_Com_Task_10ms' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_6; 
 
/* Global Alive Counters for checkpoint 'WdgMAliveCP_Safety_Task_200ms' in supervised entity 'WdgM_SE_Safety_Task_200ms' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_7; 
 
/* RAM section for Global Status */ 
WDGM_LOCAL VAR(WdgM_DataGType, WDGM_VAR_NOINIT) StatusG_core0; 
 
/* Global variables */ 
WDGM_LOCAL VAR(WdgM_GlobalVariablesType, WDGM_VAR_NOINIT) GlobalVariables_core0; 
 
#define WDGM_GLOBAL_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 


#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



WDGM_LOCAL CONST(WdgM_CheckPointType, WDGM_CONST) WdgMCheckPoint[WDGM_NR_OF_CHECKPOINTS] =
{
  {
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_MCU1_0 /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    100u /*  WdgMExpectedAliveIndications  */ , 
    40u /*  WdgMMinMargin  */ , 
    40u /*  WdgMMaxMargin  */ , 
    100u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_0 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_0 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [0]  */ , 
  {
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_MCU2_0 /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    100u /*  WdgMExpectedAliveIndications  */ , 
    40u /*  WdgMMinMargin  */ , 
    40u /*  WdgMMaxMargin  */ , 
    100u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_1 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_1 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [1]  */ , 
  {
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_MCU2_1 /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    100u /*  WdgMExpectedAliveIndications  */ , 
    40u /*  WdgMMinMargin  */ , 
    40u /*  WdgMMaxMargin  */ , 
    100u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_2 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_2 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [2]  */ , 
  {
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_MPU1_0 /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    100u /*  WdgMExpectedAliveIndications  */ , 
    40u /*  WdgMMinMargin  */ , 
    40u /*  WdgMMaxMargin  */ , 
    100u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_3 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_3 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [3]  */ , 
  {
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_Safety_Task_00_10ms /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    100u /*  WdgMExpectedAliveIndications  */ , 
    80u /*  WdgMMinMargin  */ , 
    80u /*  WdgMMaxMargin  */ , 
    100u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_4 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_4 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [4]  */ , 
  {
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_Safety_Task_01_10ms /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    100u /*  WdgMExpectedAliveIndications  */ , 
    80u /*  WdgMMinMargin  */ , 
    80u /*  WdgMMaxMargin  */ , 
    100u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_5 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_5 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [5]  */ , 
  {
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_Safety_Com_Task_10ms /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    100u /*  WdgMExpectedAliveIndications  */ , 
    80u /*  WdgMMinMargin  */ , 
    80u /*  WdgMMaxMargin  */ , 
    100u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_6 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_6 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [6]  */ , 
  {
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_Safety_Task_200ms /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    25u /*  WdgMExpectedAliveIndications  */ , 
    20u /*  WdgMMinMargin  */ , 
    20u /*  WdgMMaxMargin  */ , 
    500u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_7 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_7 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [7]  */ 
};


WDGM_LOCAL CONST(WdgM_SupervisedEntityType, WDGM_CONST) WdgMSupervisedEntity[WDGM_NR_OF_ENTITIES] =
{
  {
    WdgMConf_WdgMSupervisedEntity_WdgM_SE_MCU1_0 /*  WdgMSupervisedEntity  */ , 
    FALSE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_MCU1_0 /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[0] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_0 /*  EntityStatusLRef  */ , 
    &EntityStatusG_0 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [0]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_WdgM_SE_MCU2_0 /*  WdgMSupervisedEntity  */ , 
    FALSE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_MCU2_0 /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[1] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_1 /*  EntityStatusLRef  */ , 
    &EntityStatusG_1 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [1]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_WdgM_SE_MCU2_1 /*  WdgMSupervisedEntity  */ , 
    FALSE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_MCU2_1 /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[2] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_2 /*  EntityStatusLRef  */ , 
    &EntityStatusG_2 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [2]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_WdgM_SE_MPU1_0 /*  WdgMSupervisedEntity  */ , 
    FALSE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_MPU1_0 /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[3] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_3 /*  EntityStatusLRef  */ , 
    &EntityStatusG_3 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [3]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_WdgM_SE_Safety_Task_00_10ms /*  WdgMSupervisedEntity  */ , 
    FALSE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_Safety_Task_00_10ms /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[4] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_4 /*  EntityStatusLRef  */ , 
    &EntityStatusG_4 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [4]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_WdgM_SE_Safety_Task_01_10ms /*  WdgMSupervisedEntity  */ , 
    FALSE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_Safety_Task_01_10ms /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[5] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_5 /*  EntityStatusLRef  */ , 
    &EntityStatusG_5 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [5]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_WdgM_SE_Safety_Com_Task_10ms /*  WdgMSupervisedEntity  */ , 
    FALSE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_Safety_Com_Task_10ms /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[6] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_6 /*  EntityStatusLRef  */ , 
    &EntityStatusG_6 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [6]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_WdgM_SE_Safety_Task_200ms /*  WdgMSupervisedEntity  */ , 
    FALSE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_WdgMAliveCP_Safety_Task_200ms /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[7] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_7 /*  EntityStatusLRef  */ , 
    &EntityStatusG_7 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [7]  */ 
};


WDGM_LOCAL CONST(WdgM_TriggerModeType, WDGM_CONST) WdgMTriggerMode_core0[WDGM_NR_OF_WATCHDOGS_CORE0 * WDGM_NR_OF_TRIGGER_MODES_CORE0] = 
{
  {
    10u /*   (condition value)  WdgMTriggerTimeout  */ , 
    1u /*  WdgMTicksPerSecond[Hz]=100 , WdgMTriggerTimeoutTicks  */ , 
    WDGIF_FAST_MODE /*  WdgMWatchdogMode  */ , 
    0u /*  WdgMDeviceIndex  */ 
  } /*  WdgMTriggerModeId 0  */ 
}; 
 
WDGM_LOCAL CONST(WdgM_WatchdogDeviceType, WDGM_CONST) WdgMWatchdogDevice0[WDGM_NR_OF_WATCHDOGS_CORE0] = 
{
  {
    &WdgMTriggerMode_core0[0] /*  WdgMTriggerModeRef  */ 
  } /*  [0]  */ 
}; 


WDGM_LOCAL CONST(WdgM_CallersType, WDGM_CONST) WdgMAllowedCallers[WDGM_NR_OF_ALLOWED_CALLERS] =
{
  {
    0u /*  WdgMAllowedCaller  */ 
  } /*  [0]  */ 
};


CONST(WdgM_ConfigType, WDGM_CONST) WdgMConfig_Mode0_core0 = 
{
  6u /*  WdgMConfigMajorVersion  */ , 
  0u /*  WdgMConfigMinorVersion  */ , 
  0u /*  WdgMConfigId  */ , 
  0u /*  WdgMInitialTriggerModeId  */ , 
  0u /*  WdgMExpiredSupervisionCycleTol  */ , 
  WDGM_INVALID_SE_ID /*  WdgMGlobInitialEntityId  */ , 
  WDGM_INVALID_CP_ID /*  WdgMGlobInitialCheckpointId  */ , 
  WDGM_NR_OF_GLOBAL_TRANSITIONS /*  NrOfGlobalTransitions  */ , 
  NULL_PTR /*  WdgMGlobalTransitions  */ , 
  WDGM_NR_OF_WATCHDOGS_CORE0 /*  NrOfWatchdogDevices  */ , 
  WDGM_NR_OF_TRIGGER_MODES_CORE0 /*  NrOfTriggerModes  */ , 
  WdgMWatchdogDevice0 /*  WdgMWatchdogDeviceRef  */ , 
  WDGM_NR_OF_ALLOWED_CALLERS /*  NrOfAllowedCallers  */ , 
  WdgMAllowedCallers /*  WdgMCallersRef  */ , 
  WDGM_NR_OF_ENTITIES /*  NrOfSupervisedEntities  */ , 
  WdgMSupervisedEntity /*  WdgMSupervisedEntityRef  */ , 
  &StatusG_core0 /*  DataGRef  */ , 
  &StatusGS_core0 /*  DataGSRef  */ , 
  EntityGS /*  EntityGSRef  */ , 
  NULL_PTR /*  GlobalTransitionFlagsGSRef  */ , 
  NULL_PTR /*  WdgM_GlobalStatusChangeNotification  */ , 
  &GlobalVariables_core0 /*  WdgMGlobalVariables  */ , 
  0u /*  WdgMModeCoreAssignment  */ , 
  52u /*  WdgMConfigChecksum  */ 
}; 
 

#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  END OF FILE: WdgM_Cfg.c
 *********************************************************************************************************************/

