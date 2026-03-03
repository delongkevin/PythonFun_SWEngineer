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
 *            Module: EcuM
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EcuM_Generated_Types.h
 *   Generation Time: 2024-02-13 13:07:49
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined(ECUM_GENERATEDTYPES_H)
#define ECUM_GENERATEDTYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "Rte_EcuM_Type.h"
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! This type is a 32bit bitmask where each bit represents a wakeup source. */
 typedef uint32 EcuM_WakeupSourceType;
 
 

/* ------------------------------------- Symblic Name Defines for EcuM_WakeupSourceType ---------------------------- */
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_POWER          (0u) 
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_RESET          (1u) 
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_INTERNAL_RESET (2u) 
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_INTERNAL_WDG   (3u) 
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_EXTERNAL_WDG   (4u) 
#define EcuMConf_EcuMWakeupSource_CN_FDCAN14_a902658e          (5u) 
#define EcuMConf_EcuMWakeupSource_CN_FDCAN2_28a8fc44           (6u) 

 
/* ------------------------------------- Range of EcuM_WakeupSourceType -------------------------------------------- */
#define ECUM_WKSOURCE_NONE                (EcuM_WakeupSourceType)(0x00000000u) 
#define ECUM_WKSOURCE_ALL_SOURCES         (EcuM_WakeupSourceType)(~((EcuM_WakeupSourceType)0x00UL)) 
#define ECUM_WKSOURCE_POWER               (EcuM_WakeupSourceType)(1u) 
#define ECUM_WKSOURCE_RESET               (EcuM_WakeupSourceType)(2u) 
#define ECUM_WKSOURCE_INTERNAL_RESET      (EcuM_WakeupSourceType)(4u) 
#define ECUM_WKSOURCE_INTERNAL_WDG        (EcuM_WakeupSourceType)(8u) 
#define ECUM_WKSOURCE_EXTERNAL_WDG        (EcuM_WakeupSourceType)(16u) 
#define ECUM_WKSOURCE_CN_FDCAN14_a902658e (EcuM_WakeupSourceType)(32u) 
#define ECUM_WKSOURCE_CN_FDCAN2_28a8fc44  (EcuM_WakeupSourceType)(64u) 



  /* ------------------------------------- Range of EcuM_StateType ------------------------------------------------- */
#define ECUM_SUBSTATE_MASK                                  (0x0Fu)
#define ECUM_STATE_STARTUP                                  (0x10u)
#define ECUM_STATE_STARTUP_ONE                              (0x11u)
#define ECUM_STATE_STARTUP_TWO                              (0x12u)
#define ECUM_STATE_WAKEUP                                   (0x20u)
#define ECUM_STATE_WAKEUP_ONE                               (0x21u)
#define ECUM_STATE_WAKEUP_VALIDATION                        (0x22u)
#define ECUM_STATE_WAKEUP_REACTION                          (0x23u)
#define ECUM_STATE_WAKEUP_TWO                               (0x24u)
#define ECUM_STATE_WAKEUP_WAKESLEEP                         (0x25u)
#define ECUM_STATE_WAKEUP_TTII                              (0x26u)
#define ECUM_STATE_RUN                                      (0x30u)
#define ECUM_STATE_APP_RUN                                  (0x32u)
#define ECUM_STATE_APP_POST_RUN                             (0x33u)
#define ECUM_STATE_SHUTDOWN                                 (0x40u)
#define ECUM_STATE_PREP_SHUTDOWN                            (0x44u)
#define ECUM_STATE_GO_SLEEP                                 (0x49u)
#define ECUM_STATE_GO_OFF_ONE                               (0x4Du)
#define ECUM_STATE_GO_OFF_TWO                               (0x4Eu)
/* State OFF, RESET AND SLEEP are defined by the RTE */
#define ECUM_STATE_ERROR                                    (0xFFu)


typedef uint8 EcuM_WakeupStateType;
/* ------------------------------------- Range of EcuM_WakeupStatusType -------------------------------------------- */
#define ECUM_WKSTATUS_NONE                                  (0u)
#define ECUM_WKSTATUS_PENDING                               (1u)
#define ECUM_WKSTATUS_VALIDATED                             (2u)
#define ECUM_WKSTATUS_EXPIRED                               (3u)

/* The following state was introduced by Vector to support asynchronous transceiver handling */
#define ECUM_WKSTATUS_CHECKWAKEUP                           (5u)
#define ECUM_WKSTATUS_ENABLED                               (6u)

/* ------------------------------------- Range of Alarm Clocks ----------------------------------------------------- */

/* ------------------------------------- Range of EcuM RunStatus Types --------------------------------------------- */
#define ECUM_RUNSTATUS_UNKNOWN                              (0u)
#define ECUM_RUNSTATUS_REQUESTED                            (1u)
#define ECUM_RUNSTATUS_RELEASED                             (2u)


typedef uint8 EcuM_RunStatusType;

typedef EcuM_ModeType EcuM_ResetType;

#endif /* ECUM_GENERATEDTYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: ECUM_GENERATEDTYPES.H
 *********************************************************************************************************************/


