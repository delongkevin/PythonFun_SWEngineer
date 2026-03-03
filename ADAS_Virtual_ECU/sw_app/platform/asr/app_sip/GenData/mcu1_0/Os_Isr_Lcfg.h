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
 *              File: Os_Isr_Lcfg.h
 *   Generation Time: 2024-02-13 13:07:50
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_ISR_LCFG_H
# define OS_ISR_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Isr_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"
# include "Os_Timer_Types.h"
# include "Os_XSignal_Types.h"

/* Os hal dependencies */


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

/*! ISR configuration data: ADC0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_ADC0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC0;

/*! ISR configuration data: ADC1 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_ADC1_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC1;

/*! ISR configuration data: Can_30_McanIsr_0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Can_30_McanIsr_0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Can_30_McanIsr_0;

/*! ISR configuration data: Can_30_McanIsr_1 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Can_30_McanIsr_1_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Can_30_McanIsr_1;

/*! ISR configuration data: CounterIsr_SystemTimer */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer_HwConfig;
extern CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer;

/*! ISR configuration data: I2c_IrqUnit0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_I2c_IrqUnit0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_I2c_IrqUnit0;

/*! ISR configuration data: I2c_IrqUnit1 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_I2c_IrqUnit1_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_I2c_IrqUnit1;

/*! ISR configuration data: IPC_mailbox1 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_IPC_mailbox1_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_IPC_mailbox1;

/*! ISR configuration data: IPC_mailbox2 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_IPC_mailbox2_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_IPC_mailbox2;

/*! ISR configuration data: MAIN_ESM0_ESM_INT_CFG_LVL_0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0;

/*! ISR configuration data: MAIN_ESM0_ESM_INT_HI_LVL_0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0;

/*! ISR configuration data: MAIN_ESM0_ESM_INT_LOW_LVL_0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0;

/*! ISR configuration data: MCU_ESM0_ESM_INT_CFG_LVL_0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0;

/*! ISR configuration data: MCU_ESM0_ESM_INT_HI_LVL_0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MCU_ESM0_ESM_INT_HI_LVL_0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MCU_ESM0_ESM_INT_HI_LVL_0;

/*! ISR configuration data: MCU_ESM0_ESM_INT_LOW_LVL_0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0;

/*! ISR configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78;

/*! ISR configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304;

/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305;

/*! ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn1 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn1_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn1;

/*! ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn2 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn2_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn2;

/*! ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn3 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn3_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn3;

/*! ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn4 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn4_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn4;

/*! ISR configuration data: WKUP_ESM0_ESM_INT_CFG_LVL_0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0;

/*! ISR configuration data: WKUP_ESM0_ESM_INT_HI_LVL_0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0;

/*! ISR configuration data: WKUP_ESM0_ESM_INT_LOW_LVL_0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0;

/*! ISR configuration data: vHsmResponseIsr */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_vHsmResponseIsr_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_vHsmResponseIsr;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for category 2 ISRs. */
extern CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1];  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_ISR_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Isr_Lcfg.h
 *********************************************************************************************************************/
