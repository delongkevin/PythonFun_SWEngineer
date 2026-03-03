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
 *              File: ..\Include\SchM_CanIf.h
 *   Generation Time: 2024-11-25 15:00:22
 *           Project: DemoFbl - Version 1.0
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

#ifndef SCHM_CANIF_H
# define SCHM_CANIF_H

# include "Os.h"

/* already implemented in BrsMain.c (see also CanDriver ApplicationNote AN-ISC-8-1149)
# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_0() SuspendAllInterrupts()
*/
void SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_0(void);

/* already implemented in BrsMain.c (see also CanDriver ApplicationNote AN-ISC-8-1149)
# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_0() ResumeAllInterrupts()
*/
void SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_0(void);


# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_1() SuspendAllInterrupts()
# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_1() ResumeAllInterrupts()

# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_2() SuspendAllInterrupts()
# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_2() ResumeAllInterrupts()

# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_3() SuspendAllInterrupts()
# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_3() ResumeAllInterrupts()

# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_4() SuspendAllInterrupts()
# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_4() ResumeAllInterrupts()

# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_5() SuspendAllInterrupts()
# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_5() ResumeAllInterrupts()

# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_6() SuspendAllInterrupts()
# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_6() ResumeAllInterrupts()

# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_7() SuspendAllInterrupts()
# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_7() ResumeAllInterrupts()

#endif /* SCHM_CANIF_H */
