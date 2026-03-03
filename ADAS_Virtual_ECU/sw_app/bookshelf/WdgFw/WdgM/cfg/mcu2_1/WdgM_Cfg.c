/**
 * @file WdgM_Cfg.c
 * @brief Watchdog manager config header file
 *
 * @details This is generated config file for watchdog manager
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2022. Magna Electronics owns all
 *   rights to this work and intends to maintain it in confidence
 *   to preserve its trade secret status. Magna Electronics
 *   reserves the right, under the copyright laws of the United
 *   States or those of any other country that may have jurisdiction,
 *   to protect this work as an unpublished work, in the event of
 *   an inadvertent or deliberate unauthorized publication.
 *   Magna Electronics also reserves its rights under all copyright
 *   laws to protect this work as a published work, when appropriate.
 *   Those having access to this work may not copy it, use it,
 *   modify it, or disclose the information contained in it without
 *   the written authorization of Magna Electronics.
 *
 * --------------------------------------------------------------------------
 * @author Pramod Kumar (Pramod.kumar1@magna.com)
 */

/* ===========================================================================
 *
 *   WdgFw_Config_Generator.xlsx
 *
 * ======================================================================== */
/*
 * Excel file Version:  1.0
 * Excel file Mod Date: 2022-10-31 00:00:00
 * Generated on:        2023-03-16 17:42:51
*/


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "WdgM.h"

/**********************************************************************************************************************
 *  VERSION INFORMATION AND CHECK
 *********************************************************************************************************************/
#define WDGM_CFG_C_MAJOR_VERSION (6u)
#define WDGM_CFG_C_MINOR_VERSION (0u)
#define WDGM_CFG_C_PATCH_VERSION (1u)


/* Check the version of WdgM_Cfg header file */
#if ( (WDGM_CFG_MAJOR_VERSION != WDGM_CFG_C_MAJOR_VERSION) \
   || (WDGM_CFG_MINOR_VERSION != WDGM_CFG_C_MINOR_VERSION) \
   || (WDGM_CFG_PATCH_VERSION != WDGM_CFG_C_PATCH_VERSION) )
# error "Version numbers of WdgM_Cfg.c and WdgM_Cfg.h are inconsistent!"
#endif

#if !defined (WDGM_LOCAL) /* COV_WDGM_COMPATIBILITY */
# define WDGM_LOCAL static
#endif

WDGM_LOCAL VAR(WdgM_DataGSType, WDGM_VAR_NOINIT) StatusGS_core0;
WDGM_LOCAL VAR(WdgM_EntityGSType, WDGM_VAR_NOINIT) EntityGS [WDGM_NR_OF_ENTITIES];

/* Local Status for Supervised Entities */
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_0;

/* Local Alive Counters for checkpoints */
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_0;

/* Global Status for Supervised Entities */
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_0;

/* Global Alive Counters for checkpoint */
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_0;

/* RAM section for Global Status */
WDGM_LOCAL VAR(WdgM_DataGType, WDGM_VAR_NOINIT) StatusG_core0;

/* Global variables */
WDGM_LOCAL VAR(WdgM_GlobalVariablesType, WDGM_VAR_NOINIT) GlobalVariables_core0;

WDGM_LOCAL CONST(WdgM_CheckPointType, WDGM_CONST) WdgMCheckPoint[WDGM_NR_OF_CHECKPOINTS] =
{
  {
    WdgMConf_WdgMCheckpoint_TaskBswB10msec_Alive_CP/*  WdgMCheckpointId  */ ,
    FALSE /*  WdgMIsEndCheckpoint  */ ,
    FALSE /*  WdgMIsEndCheckpointGlobal  */ ,
    2u /*  WdgMExpectedAliveIndications  */ ,
    1u /*  WdgMMinMargin  */ ,
    1u /*  WdgMMaxMargin  */ ,
    2u /*  WdgMSupervisionReferenceCycle  */ ,
    &Alive_CounterL_0/*  WdgMAliveLRef  */ ,
    &Alive_CounterG_0/*  WdgMAliveGRef  */ ,
    FALSE /*  WdgMDeadlineMonitoring  */ ,
    0u /*  WdgMOutgoingDeadlineMax  */ ,
    0u /*  NrOfLocalTransitions  */ ,
    NULL_PTR /*  WdgMLocalTransitionRef  */ ,
    0u /*  NrOfGlobalTransitions  */ ,
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ ,
    FALSE /*  WdgMStartsAGlobalTransition  */ ,
    0u /*  NrOfStartedGlobalTransitions  */ ,
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */
  } /*  [0]  */
};


WDGM_LOCAL CONST(WdgM_SupervisedEntityType, WDGM_CONST) WdgMSupervisedEntity[WDGM_NR_OF_ENTITIES] =
{
  {
    WdgMConf_WdgMSupervisedEntity_TaskBswB10msec_SE /*  WdgMSupervisedEntity  */ ,
    FALSE /*  WdgMEnableEntityDeactivation  */ ,
    WdgMConf_WdgMCheckpoint_TaskBswB10msec_Alive_CP /*  WdgMCheckpointLocInitialId  */ , 
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
  } /*  [0]  */
};


WDGM_LOCAL CONST(WdgM_TriggerModeType, WDGM_CONST) WdgMTriggerMode_core0[WDGM_NR_OF_WATCHDOGS_CORE0 * WDGM_NR_OF_TRIGGER_MODES_CORE0] =
{
  {
    10u /*   (condition value)  WdgMTriggerTimeout  */ ,
    10u /*  WdgMTicksPerSecond[Hz]=1000 , WdgMTriggerTimeoutTicks  */ ,
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
  12u /*  WdgMConfigChecksum  */
};

/**********************************************************************************************************************
 *  END OF FILE: WdgM_Cfg.c
 *********************************************************************************************************************/

