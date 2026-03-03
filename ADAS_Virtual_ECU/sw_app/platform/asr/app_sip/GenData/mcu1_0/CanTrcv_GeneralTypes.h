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
 *            Module: CanTrcv
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTrcv_GeneralTypes.h
 *   Generation Time: 2024-02-13 13:07:49
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef __CANTRCV_GENERALTYPES_H
#define __CANTRCV_GENERALTYPES_H

typedef enum CanTrcv_TrcvModeTypeTag 
{
  CANTRCV_TRCVMODE_NORMAL = 0u,
  CANTRCV_TRCVMODE_SLEEP,
  CANTRCV_TRCVMODE_STANDBY
} CanTrcv_TrcvModeType;


typedef enum CanTrcv_TrcvWakeupModeTypeTag
{
  CANTRCV_WUMODE_ENABLE = 0u,
  CANTRCV_WUMODE_CLEAR,
  CANTRCV_WUMODE_DISABLE
} CanTrcv_TrcvWakeupModeType;

typedef enum CanTrcv_TrcvWakeupReasonTypeTag
{
  CANTRCV_WU_ERROR = 0u,
  CANTRCV_WU_BY_BUS,
  CANTRCV_WU_BY_PIN,
  CANTRCV_WU_INTERNALLY,
  CANTRCV_WU_NOT_SUPPORTED,
  CANTRCV_WU_POWER_ON,
  CANTRCV_WU_RESET,
  CANTRCV_WU_BY_SYSERR
} CanTrcv_TrcvWakeupReasonType;

#endif


