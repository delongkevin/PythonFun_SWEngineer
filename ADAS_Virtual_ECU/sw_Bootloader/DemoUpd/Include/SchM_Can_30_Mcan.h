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
 *    License Scope : The usage is restricted to CBD2101146_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ..\Include\SchM_Can_30_Mcan.h
 *   Generation Time: 2022-06-21 14:40:10
 *           Project: DemoFbl - Version 1.0
 *          Delivery: CBD2101146_D01
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Please note:
 *    The demo and example programs only show special aspects of the software. With regard to the fact
 *    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
 *    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *********************************************************************************************************************/

#ifndef SCHM_CAN_30_MCAN_H
# define SCHM_CAN_30_MCAN_H

# include "Os.h"

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "Std_Types.h"

# define CAN_30_MCAN_START_SEC_CODE
# include "MemMap.h"

FUNC(void, CAN_30_MCAN_CODE) Can_30_Mcan_MainFunction_Write(void);
FUNC(void, CAN_30_MCAN_CODE) Can_30_Mcan_MainFunction_Read(void);
FUNC(void, CAN_30_MCAN_CODE) Can_30_Mcan_MainFunction_BusOff(void);
FUNC(void, CAN_30_MCAN_CODE) Can_30_Mcan_MainFunction_Wakeup(void);
FUNC(void, CAN_30_MCAN_CODE) Can_30_Mcan_MainFunction_Mode(void);

# define CAN_30_MCAN_STOP_SEC_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

# define SchM_Enter_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_0() SuspendAllInterrupts()
# define SchM_Exit_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_0() ResumeAllInterrupts()

# define SchM_Enter_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_1() SuspendAllInterrupts()
# define SchM_Exit_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_1() ResumeAllInterrupts()

# define SchM_Enter_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_2() SuspendAllInterrupts()
# define SchM_Exit_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_2() ResumeAllInterrupts()

# define SchM_Enter_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_3() SuspendAllInterrupts()
# define SchM_Exit_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_3() ResumeAllInterrupts()

# define SchM_Enter_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_4() SuspendAllInterrupts()
# define SchM_Exit_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_4() ResumeAllInterrupts()

# define SchM_Enter_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_5() SuspendAllInterrupts()
# define SchM_Exit_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_5() ResumeAllInterrupts()

# define SchM_Enter_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_6() SuspendAllInterrupts()
# define SchM_Exit_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_6() ResumeAllInterrupts()

# define SchM_Enter_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_7() SuspendAllInterrupts()
# define SchM_Exit_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_7() ResumeAllInterrupts()

#endif /* SCHM_CAN_30_MCAN_H */
