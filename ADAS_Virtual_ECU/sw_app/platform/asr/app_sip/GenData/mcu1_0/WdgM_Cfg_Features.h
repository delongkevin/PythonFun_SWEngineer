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
 *              File: WdgM_Cfg_Features.h
 *   Generation Time: 2024-02-13 13:07:46
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined (WDGM_CFG_FEATURES_H)
# define WDGM_CFG_FEATURES_H

/**********************************************************************************************************************
 *  AUTOSAR feature defines
 *********************************************************************************************************************/
# define WDGM_VERSION_INFO_API                STD_OFF 
# define WDGM_DEV_ERROR_DETECT                STD_OFF 
# define WDGM_DEFENSIVE_BEHAVIOR              STD_OFF 
# define WDGM_IMMEDIATE_RESET                 STD_OFF 
# define WDGM_OFF_MODE_ENABLED                STD_OFF 


/**********************************************************************************************************************
 *  WDGM-specific feature defines (user-defined)
 *********************************************************************************************************************/
# define WDGM_USE_OS_SUSPEND_INTERRUPT        STD_ON 
# define WDGM_TIMEBASE_SOURCE         WDGM_INTERNAL_SOFTWARE_TICK 
# define WDGM_SECOND_RESET_PATH               STD_OFF 
# define WDGM_TICK_OVERRUN_CORRECTION         STD_OFF 
# define WDGM_ENTITY_DEACTIVATION_ENABLED     STD_OFF 
# define WDGM_STATUS_REPORTING_MECHANISM WDGM_USE_NO_STATUS_REPORTING 
# define WDGM_USE_RTE                         STD_ON 
# define WDGM_DEM_SUPERVISION_REPORT          STD_OFF 
# define WDGM_FIRSTCYCLE_ALIVECOUNTER_RESET   STD_OFF 
# define WDGM_AUTOSAR_DEBUGGING               STD_OFF 
# define WDGM_DEM_REPORT                      STD_OFF 


/**********************************************************************************************************************
 *  WDGM-specific feature defines (automatically computed)
 *********************************************************************************************************************/
# define WDGM_GLOBAL_TRANSITIONS              STD_OFF 
# define WDGM_MULTIPLE_TRIGGER_MODES          STD_OFF 


/**********************************************************************************************************************
 *  WDGM-specific feature defines for multi-core systems
 *  (all automatically computed except for OS core identification usage)
 *********************************************************************************************************************/
# define WDGM_MULTICORE_USAGE                 STD_OFF 


/**********************************************************************************************************************
 *  INCLUDES for Dem
 *********************************************************************************************************************/
/* Intentionally left empty. Preprocessor switch WDGM_DEM_REPORT is STD_OFF */ 



#endif /* WDGM_CFG_FEATURES_H */

/**********************************************************************************************************************
 *  END OF FILE: WdgM_Cfg_Features.h
 *********************************************************************************************************************/

