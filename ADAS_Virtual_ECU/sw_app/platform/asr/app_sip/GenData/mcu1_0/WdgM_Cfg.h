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
 *              File: WdgM_Cfg.h
 *   Generation Time: 2025-01-23 15:17:23
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined (WDGM_CFG_H)
# define WDGM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "WdgM_Types.h"


/**********************************************************************************************************************
 *  VERSION INFORMATION
 *********************************************************************************************************************/
#define WDGM_CFG_MAJOR_VERSION (6u) 
#define WDGM_CFG_MINOR_VERSION (0u) 
#define WDGM_CFG_PATCH_VERSION (2u) 


/* Module specific general defines */ 
#ifndef WDGM_USE_DUMMY_STATEMENT
#define WDGM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef WDGM_DUMMY_STATEMENT
#define WDGM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef WDGM_DUMMY_STATEMENT_CONST
#define WDGM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef WDGM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define WDGM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef WDGM_ATOMIC_VARIABLE_ACCESS
#define WDGM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef WDGM_PROCESSOR_TDA4VE88
#define WDGM_PROCESSOR_TDA4VE88
#endif
#ifndef WDGM_COMP_LLVMTEXASINSTRUMENTS
#define WDGM_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef WDGM_GEN_GENERATOR_MSR
#define WDGM_GEN_GENERATOR_MSR
#endif
#ifndef WDGM_CPUTYPE_BITORDER_LSB2MSB
#define WDGM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef WDGM_CONFIGURATION_VARIANT_PRECOMPILE
#define WDGM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef WDGM_CONFIGURATION_VARIANT_LINKTIME
#define WDGM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef WDGM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define WDGM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef WDGM_CONFIGURATION_VARIANT
#define WDGM_CONFIGURATION_VARIANT WDGM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef WDGM_POSTBUILD_VARIANT_SUPPORT
#define WDGM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif
 

 
/* Module config related defines */ 
# define WDGM_NR_OF_CHECKPOINTS           (8u) 
# define WDGM_NR_OF_ENTITIES              (8u) 
# define WDGM_NR_OF_ALLOWED_CALLERS       (1u) 
# define WDGM_NR_OF_GLOBAL_TRANSITIONS    (0u) 
# define WDGM_NR_OF_LOCAL_TRANSITIONS     (0u) 
# define WDGM_NR_OF_WATCHDOGS_CORE0       (1u) 
# define WDGM_NR_OF_TRIGGER_MODES_CORE0   (1u) 

/* Checkpoints for supervised entity 'WdgM_SE_MCU1_0' */ 
# define WdgMConf_WdgMCheckpoint_WdgMAliveCP_MCU1_0 (0u) 
/* Checkpoints for supervised entity 'WdgM_SE_MCU2_0' */ 
# define WdgMConf_WdgMCheckpoint_WdgMAliveCP_MCU2_0 (0u) 
/* Checkpoints for supervised entity 'WdgM_SE_MCU2_1' */ 
# define WdgMConf_WdgMCheckpoint_WdgMAliveCP_MCU2_1 (0u) 
/* Checkpoints for supervised entity 'WdgM_SE_MPU1_0' */ 
# define WdgMConf_WdgMCheckpoint_WdgMAliveCP_MPU1_0 (0u) 
/* Checkpoints for supervised entity 'WdgM_SE_Safety_Task_00_10ms' */ 
# define WdgMConf_WdgMCheckpoint_WdgMAliveCP_Safety_Task_00_10ms (0u) 
/* Checkpoints for supervised entity 'WdgM_SE_Safety_Task_01_10ms' */ 
# define WdgMConf_WdgMCheckpoint_WdgMAliveCP_Safety_Task_01_10ms (0u) 
/* Checkpoints for supervised entity 'WdgM_SE_Safety_Com_Task_10ms' */ 
# define WdgMConf_WdgMCheckpoint_WdgMAliveCP_Safety_Com_Task_10ms (0u) 
/* Checkpoints for supervised entity 'WdgM_SE_Safety_Task_200ms' */ 
# define WdgMConf_WdgMCheckpoint_WdgMAliveCP_Safety_Task_200ms (0u) 
 

# define WdgMConf_WdgMSupervisedEntity_WdgM_SE_MCU1_0 (0u) 
# define WdgMConf_WdgMSupervisedEntity_WdgM_SE_MCU2_0 (1u) 
# define WdgMConf_WdgMSupervisedEntity_WdgM_SE_MCU2_1 (2u) 
# define WdgMConf_WdgMSupervisedEntity_WdgM_SE_MPU1_0 (3u) 
# define WdgMConf_WdgMSupervisedEntity_WdgM_SE_Safety_Task_00_10ms (4u) 
# define WdgMConf_WdgMSupervisedEntity_WdgM_SE_Safety_Task_01_10ms (5u) 
# define WdgMConf_WdgMSupervisedEntity_WdgM_SE_Safety_Com_Task_10ms (6u) 
# define WdgMConf_WdgMSupervisedEntity_WdgM_SE_Safety_Task_200ms (7u) 


#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(WdgM_ConfigType, WDGM_CONST) WdgMConfig_Mode0_core0; 

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */




#endif /* WDGM_CFG_H*/

/**********************************************************************************************************************
 *  END OF FILE: WdgM_Cfg.h
 *********************************************************************************************************************/

