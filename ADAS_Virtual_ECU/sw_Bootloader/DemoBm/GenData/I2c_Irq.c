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
 *            Module: I2c
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: I2c_Irq.c
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#define I2C_IRQ_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "I2c_Irq.h"
#include "I2c_PerMgr.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define I2C_START_SEC_CODE_ISR
#include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  I2c_IrqUnit0()
 *********************************************************************************************************************/
/*!
 * \internal
 * - Forward call to interrupt handler for specific hardware unit id.
 * \endinternal
 */
FUNC(void, I2C_CODE) I2c_IrqUnit0(void)
{
  I2c_PerMgr_IrqHandler(0);
}


#define I2C_STOP_SEC_CODE_ISR
#include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_19.1 */

