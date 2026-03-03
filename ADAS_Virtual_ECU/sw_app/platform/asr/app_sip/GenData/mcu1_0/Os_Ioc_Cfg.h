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
 *            Module: Os
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Ioc_Cfg.h
 *   Generation Time: 2024-02-13 13:07:50
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_IOC_CFG_H
# define OS_IOC_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether IOC is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_IOC                              (STD_ON)

/*! Defines whether IOC callbacks are configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_IOC_HAS_CALLBACKS                (STD_OFF)

/* IOC communication defines: Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM */
# define OS_CFG_SIZE_IOC_RTE_ERRORMGRAGG_1_0_QM_R_SATERROR_DATA_ERRORMGR_ERRORCOMMPACK_1_0_QM_BUFFER       (0u)
# define OS_CFG_NUM_IOC_RTE_ERRORMGRAGG_1_0_QM_R_SATERROR_DATA_ERRORMGR_ERRORCOMMPACK_1_0_QM_CALLBACKS     (0u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_IOC_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Ioc_Cfg.h
 *********************************************************************************************************************/
