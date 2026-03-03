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
 *            Module: vBRS
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ..\Include\EcuM_Generated_Types.h
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Please note:
 *    The demo and example programs only show special aspects of the software. With regard to the fact
 *    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
 *    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *********************************************************************************************************************/
/***************************************************************************************************
 * Note:
 * The use of this file or any part of this file is limited to vBRS.
 * The file may be incomplete with respect to ASR Module requirements, defined by the
 * AUTOSAR Standard.
 ***************************************************************************************************/

#if !defined(ECUM_GENERATED_TYPES_H)
#define ECUM_GENERATED_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! This type is a 32bit bitmask where each bit represents a wakeup source. */
typedef uint32 EcuM_WakeupSourceType;

/* ------------------------------------- Symbolic Name Defines for EcuM_WakeupSourceType ---------------------------- */
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_POWER          (0UL) 
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_RESET          (1UL)
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_INTERNAL_RESET (2UL) 
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_INTERNAL_WDG   (3UL)
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_EXTERNAL_WDG   (4UL)
 
/* ------------------------------------- Range of EcuM_WakeupSourceType -------------------------------------------- */
#define ECUM_WKSOURCE_NONE (EcuM_WakeupSourceType)(0x00000000UL)
#define ECUM_WKSOURCE_ALL_SOURCES (~((EcuM_WakeupSourceType)0UL))
#define ECUM_WKSOURCE_EcuMWakeupSource_LIN (EcuM_WakeupSourceType)(31UL)
#define ECUM_WKSOURCE_ECUM_WKSOURCE_INTERNAL_WDG (EcuM_WakeupSourceType)(3UL)
#define ECUM_WKSOURCE_ECUM_WKSOURCE_POWER (EcuM_WakeupSourceType)(0UL)
#define ECUM_WKSOURCE_ECUM_WKSOURCE_RESET (EcuM_WakeupSourceType)(1UL)
#define ECUM_WKSOURCE_ECUM_WKSOURCE_INTERNAL_RESET (EcuM_WakeupSourceType)(2UL)
#define ECUM_WKSOURCE_ECUM_WKSOURCE_EXTERNAL_WDG (EcuM_WakeupSourceType)(4UL)

#endif /* ECUM_GENERATED_TYPES_H */

