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
 *    License Scope : The usage is restricted to CBD2101146_D09
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ..\Include\SchM_Eep_30_XXi2c01.h
 *   Generation Time: 2023-10-09 10:56:17
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D09
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

#ifndef SCHM_EEP_30_XXI2C01_H
# define SCHM_EEP_30_XXI2C01_H

# include "Os.h"

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "Std_Types.h"

# define EEP_30_XXI2C01_START_SEC_CODE
# include "MemMap.h"

FUNC(void, EEP_30_XXI2C01_CODE) Eep_30_XXi2c01_MainFunction(void);

# define EEP_30_XXI2C01_STOP_SEC_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

# define SchM_Enter_Eep_30_XXi2c01_EEP_30_XXI2C01_EXCLUSIVE_AREA_0() SuspendAllInterrupts()
# define SchM_Exit_Eep_30_XXi2c01_EEP_30_XXI2C01_EXCLUSIVE_AREA_0() ResumeAllInterrupts()

#endif /* SCHM_EEP_30_XXI2C01_H */
