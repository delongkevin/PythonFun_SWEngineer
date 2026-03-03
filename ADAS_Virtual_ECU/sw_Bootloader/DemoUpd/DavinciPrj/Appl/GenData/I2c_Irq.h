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
 *    License Scope : The usage is restricted to CBD2101146_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: I2c_Irq.h
 *   Generation Time: 2022-11-08 19:25:58
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D04
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined I2C_IRQ_H
#define I2C_IRQ_H    /* PRQA S 0857 */ /* MD_MSR_1.1_857 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "I2c_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define I2C_START_SEC_CODE_ISR
#include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  I2c_IrqUnit0()
 *********************************************************************************************************************/
/*! \brief       Interrupt service routine for I2c peripheral 0.
 *  \details     This function serves as a service routine for interrupts of a specific I2c hardware unit. In the 
 *               context of this function, data transfers are handled (fill/read buffers, error and result handling)
 *               for this hardware unit. 
 *  \pre         -
 *  \context     ISR
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \note        This ISR is related to the hardware unit with base address 0x40B10000u
 *********************************************************************************************************************/
void I2c_IrqUnit0 ( void );
	

#define I2C_STOP_SEC_CODE_ISR
#include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif

