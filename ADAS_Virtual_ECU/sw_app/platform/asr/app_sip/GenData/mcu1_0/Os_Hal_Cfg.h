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
 *              File: Os_Hal_Cfg.h
 *   Generation Time: 2024-02-13 12:17:20
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_CFG_H
# define OS_HAL_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! HAL configuration major version identification. */
# define OS_CFG_HAL_MAJOR_VERSION                (2u)

/*! HAL configuration minor version identification. */
# define OS_CFG_HAL_MINOR_VERSION                (70u)

/* ISR core and level definitions */
# define OS_ISR_ADC0_CORE      (0)
# define OS_ISR_ADC0_LEVEL     (13)
# define OS_ISR_ADC1_CORE      (0)
# define OS_ISR_ADC1_LEVEL     (14)
# define OS_ISR_CAN_30_MCANISR_0_CORE      (0)
# define OS_ISR_CAN_30_MCANISR_0_LEVEL     (10)
# define OS_ISR_CAN_30_MCANISR_1_CORE      (0)
# define OS_ISR_CAN_30_MCANISR_1_LEVEL     (12)
# define OS_ISR_COUNTERISR_SYSTEMTIMER_CORE      (0)
# define OS_ISR_COUNTERISR_SYSTEMTIMER_LEVEL     (1)
# define OS_ISR_I2C_IRQUNIT0_CORE      (0)
# define OS_ISR_I2C_IRQUNIT0_LEVEL     (15)
# define OS_ISR_I2C_IRQUNIT1_CORE      (0)
# define OS_ISR_I2C_IRQUNIT1_LEVEL     (15)
# define OS_ISR_IPC_MAILBOX1_CORE      (0)
# define OS_ISR_IPC_MAILBOX1_LEVEL     (14)
# define OS_ISR_IPC_MAILBOX2_CORE      (0)
# define OS_ISR_IPC_MAILBOX2_LEVEL     (14)
# define OS_ISR_MAIN_ESM0_ESM_INT_CFG_LVL_0_CORE      (0)
# define OS_ISR_MAIN_ESM0_ESM_INT_CFG_LVL_0_LEVEL     (15)
# define OS_ISR_MAIN_ESM0_ESM_INT_HI_LVL_0_CORE      (0)
# define OS_ISR_MAIN_ESM0_ESM_INT_HI_LVL_0_LEVEL     (15)
# define OS_ISR_MAIN_ESM0_ESM_INT_LOW_LVL_0_CORE      (0)
# define OS_ISR_MAIN_ESM0_ESM_INT_LOW_LVL_0_LEVEL     (15)
# define OS_ISR_MCU_ESM0_ESM_INT_CFG_LVL_0_CORE      (0)
# define OS_ISR_MCU_ESM0_ESM_INT_CFG_LVL_0_LEVEL     (15)
# define OS_ISR_MCU_ESM0_ESM_INT_HI_LVL_0_CORE      (0)
# define OS_ISR_MCU_ESM0_ESM_INT_HI_LVL_0_LEVEL     (15)
# define OS_ISR_MCU_ESM0_ESM_INT_LOW_LVL_0_CORE      (0)
# define OS_ISR_MCU_ESM0_ESM_INT_LOW_LVL_0_LEVEL     (15)
# define OS_ISR_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_CORE      (0)
# define OS_ISR_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_LEVEL     (4)
# define OS_ISR_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_CORE      (0)
# define OS_ISR_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_LEVEL     (4)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_LEVEL     (15)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_CORE      (0)
# define OS_ISR_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_LEVEL     (15)
# define OS_ISR_SCISERVER_OSISR_USERMSGHWIFXN1_CORE      (0)
# define OS_ISR_SCISERVER_OSISR_USERMSGHWIFXN1_LEVEL     (5)
# define OS_ISR_SCISERVER_OSISR_USERMSGHWIFXN2_CORE      (0)
# define OS_ISR_SCISERVER_OSISR_USERMSGHWIFXN2_LEVEL     (5)
# define OS_ISR_SCISERVER_OSISR_USERMSGHWIFXN3_CORE      (0)
# define OS_ISR_SCISERVER_OSISR_USERMSGHWIFXN3_LEVEL     (6)
# define OS_ISR_SCISERVER_OSISR_USERMSGHWIFXN4_CORE      (0)
# define OS_ISR_SCISERVER_OSISR_USERMSGHWIFXN4_LEVEL     (6)
# define OS_ISR_WKUP_ESM0_ESM_INT_CFG_LVL_0_CORE      (0)
# define OS_ISR_WKUP_ESM0_ESM_INT_CFG_LVL_0_LEVEL     (15)
# define OS_ISR_WKUP_ESM0_ESM_INT_HI_LVL_0_CORE      (0)
# define OS_ISR_WKUP_ESM0_ESM_INT_HI_LVL_0_LEVEL     (15)
# define OS_ISR_WKUP_ESM0_ESM_INT_LOW_LVL_0_CORE      (0)
# define OS_ISR_WKUP_ESM0_ESM_INT_LOW_LVL_0_LEVEL     (15)
# define OS_ISR_VHSMRESPONSEISR_CORE      (0)
# define OS_ISR_VHSMRESPONSEISR_LEVEL     (7)

/* Hardware counter timing macros */

/* Counter timing macros and constants: SystemTimer */
# define OSMAXALLOWEDVALUE_SystemTimer     (2147483647u) /* 0x7FFFFFFFu */
# define OSMINCYCLE_SystemTimer            (1u)
# define OSTICKSPERBASE_SystemTimer        (19200u)
# define OSTICKDURATION_SystemTimer        (1000000u)

/* OSEK compatibility for the system timer. */
# define OSMAXALLOWEDVALUE     (OSMAXALLOWEDVALUE_SystemTimer)
# define OSMINCYCLE            (OSMINCYCLE_SystemTimer)
# define OSTICKSPERBASE        (OSTICKSPERBASE_SystemTimer)
# define OSTICKDURATION        (OSTICKDURATION_SystemTimer)

/*! Macro OS_NS2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 500000) / 1000000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2NS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_US2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 500) / 1000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2US_SystemTimer was approximated with a deviation of 1.1102230246251565E-10ppm. */
# define OS_TICKS2US_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_MS2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2MS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_SEC2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2SEC_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 500) / 1000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */




/*! Master core phyiscal core Id. */
# define OS_HAL_MASTERCORE_PHYISCALCOREID    (0uL)



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_HAL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Cfg.h
 *********************************************************************************************************************/
