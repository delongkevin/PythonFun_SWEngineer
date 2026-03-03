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
 *              File: Os_Hal_Interrupt_Lcfg.h
 *   Generation Time: 2024-02-13 13:07:50
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_INTERRUPT_LCFG_H
# define OS_HAL_INTERRUPT_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Interrupt_Cfg.h"
# include "Os_Hal_Interrupt_Types.h"

/* Os kernel module dependencies */
# include "Os_Interrupt_Types.h"

/* Os hal dependencies */
# include "Os_Hal_Core_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: ADC0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC0;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_ADC0;

/*! HAL ISR configuration data: ADC1 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC1;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_ADC1;

/*! HAL ISR configuration data: Can_30_McanIsr_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Can_30_McanIsr_0;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Can_30_McanIsr_0;

/*! HAL ISR configuration data: Can_30_McanIsr_1 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Can_30_McanIsr_1;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Can_30_McanIsr_1;

/*! HAL ISR configuration data: CounterIsr_SystemTimer */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CounterIsr_SystemTimer;

/*! HAL ISR configuration data: I2c_IrqUnit0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_I2c_IrqUnit0;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_I2c_IrqUnit0;

/*! HAL ISR configuration data: I2c_IrqUnit1 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_I2c_IrqUnit1;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_I2c_IrqUnit1;

/*! HAL ISR configuration data: IPC_mailbox1 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_IPC_mailbox1;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_IPC_mailbox1;

/*! HAL ISR configuration data: IPC_mailbox2 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_IPC_mailbox2;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_IPC_mailbox2;

/*! HAL ISR configuration data: MAIN_ESM0_ESM_INT_CFG_LVL_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MAIN_ESM0_ESM_INT_CFG_LVL_0;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MAIN_ESM0_ESM_INT_CFG_LVL_0;

/*! HAL ISR configuration data: MAIN_ESM0_ESM_INT_HI_LVL_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MAIN_ESM0_ESM_INT_HI_LVL_0;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MAIN_ESM0_ESM_INT_HI_LVL_0;

/*! HAL ISR configuration data: MAIN_ESM0_ESM_INT_LOW_LVL_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MAIN_ESM0_ESM_INT_LOW_LVL_0;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MAIN_ESM0_ESM_INT_LOW_LVL_0;

/*! HAL ISR configuration data: MCU_ESM0_ESM_INT_CFG_LVL_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MCU_ESM0_ESM_INT_CFG_LVL_0;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MCU_ESM0_ESM_INT_CFG_LVL_0;

/*! HAL ISR configuration data: MCU_ESM0_ESM_INT_HI_LVL_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MCU_ESM0_ESM_INT_HI_LVL_0;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MCU_ESM0_ESM_INT_HI_LVL_0;

/*! HAL ISR configuration data: MCU_ESM0_ESM_INT_LOW_LVL_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MCU_ESM0_ESM_INT_LOW_LVL_0;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MCU_ESM0_ESM_INT_LOW_LVL_0;

/*! HAL ISR configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78;

/*! HAL ISR configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305;

/*! HAL ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn1 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SciServer_OsIsr_UserMsgHwiFxn1;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SciServer_OsIsr_UserMsgHwiFxn1;

/*! HAL ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn2 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SciServer_OsIsr_UserMsgHwiFxn2;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SciServer_OsIsr_UserMsgHwiFxn2;

/*! HAL ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn3 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SciServer_OsIsr_UserMsgHwiFxn3;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SciServer_OsIsr_UserMsgHwiFxn3;

/*! HAL ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn4 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SciServer_OsIsr_UserMsgHwiFxn4;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SciServer_OsIsr_UserMsgHwiFxn4;

/*! HAL ISR configuration data: WKUP_ESM0_ESM_INT_CFG_LVL_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_WKUP_ESM0_ESM_INT_CFG_LVL_0;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_WKUP_ESM0_ESM_INT_CFG_LVL_0;

/*! HAL ISR configuration data: WKUP_ESM0_ESM_INT_HI_LVL_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_WKUP_ESM0_ESM_INT_HI_LVL_0;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_WKUP_ESM0_ESM_INT_HI_LVL_0;

/*! HAL ISR configuration data: WKUP_ESM0_ESM_INT_LOW_LVL_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_WKUP_ESM0_ESM_INT_LOW_LVL_0;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_WKUP_ESM0_ESM_INT_LOW_LVL_0;

/*! HAL ISR configuration data: vHsmResponseIsr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_vHsmResponseIsr;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_vHsmResponseIsr;

/*! HAL interrupt resource level: OsResource */
extern CONST(Os_Hal_IntLevelType, OS_CONST) OsCfg_Hal_Resource_OsResource_IntLevel;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_INTERRUPT_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Interrupt_Lcfg.h
 *********************************************************************************************************************/
