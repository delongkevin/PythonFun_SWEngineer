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
 *              File: Os_Hal_Interrupt_Lcfg.c
 *   Generation Time: 2024-02-13 13:07:50
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_INTERRUPT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Interrupt_Lcfg.h"
#include "Os_Hal_Interrupt.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_Core.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#define OS_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic interrupt send core information: ADC0 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_ADC0_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: ADC1 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_ADC1_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: Can_30_McanIsr_0 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_Can_30_McanIsr_0_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: Can_30_McanIsr_1 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_Can_30_McanIsr_1_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: CounterIsr_SystemTimer */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_CounterIsr_SystemTimer_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: I2c_IrqUnit0 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_I2c_IrqUnit0_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: I2c_IrqUnit1 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_I2c_IrqUnit1_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: IPC_mailbox1 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_IPC_mailbox1_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: IPC_mailbox2 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_IPC_mailbox2_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: MAIN_ESM0_ESM_INT_CFG_LVL_0 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: MAIN_ESM0_ESM_INT_HI_LVL_0 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: MAIN_ESM0_ESM_INT_LOW_LVL_0 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: MCU_ESM0_ESM_INT_CFG_LVL_0 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: MCU_ESM0_ESM_INT_HI_LVL_0 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_MCU_ESM0_ESM_INT_HI_LVL_0_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: MCU_ESM0_ESM_INT_LOW_LVL_0 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SciServer_OsIsr_UserMsgHwiFxn1 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SciServer_OsIsr_UserMsgHwiFxn1_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SciServer_OsIsr_UserMsgHwiFxn2 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SciServer_OsIsr_UserMsgHwiFxn2_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SciServer_OsIsr_UserMsgHwiFxn3 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SciServer_OsIsr_UserMsgHwiFxn3_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: SciServer_OsIsr_UserMsgHwiFxn4 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_SciServer_OsIsr_UserMsgHwiFxn4_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: WKUP_ESM0_ESM_INT_CFG_LVL_0 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: WKUP_ESM0_ESM_INT_HI_LVL_0 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: WKUP_ESM0_ESM_INT_LOW_LVL_0 */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0_SenderID_Dyn;

/*! HAL dynamic interrupt send core information: vHsmResponseIsr */
OS_LOCAL VAR(Os_Hal_IntIsrSenderCoreID, OS_VAR_NOINIT) OsCfg_Hal_Isr_vHsmResponseIsr_SenderID_Dyn;

#define OS_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: ADC0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC0 =
{
  /* .Level                    = */ 13u,
  /* .Source                   = */ 6u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_ADC0_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_ADC0 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: ADC1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC1 =
{
  /* .Level                    = */ 14u,
  /* .Source                   = */ 7u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_ADC1_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_ADC1 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: Can_30_McanIsr_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Can_30_McanIsr_0 =
{
  /* .Level                    = */ 10u,
  /* .Source                   = */ 0u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_Can_30_McanIsr_0_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Can_30_McanIsr_0 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: Can_30_McanIsr_1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Can_30_McanIsr_1 =
{
  /* .Level                    = */ 12u,
  /* .Source                   = */ 2u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_Can_30_McanIsr_1_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Can_30_McanIsr_1 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: CounterIsr_SystemTimer */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer =
{
  /* .Level                    = */ 1u,
  /* .Source                   = */ 39u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_CounterIsr_SystemTimer_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CounterIsr_SystemTimer =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: I2c_IrqUnit0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_I2c_IrqUnit0 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 18u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_I2c_IrqUnit0_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_I2c_IrqUnit0 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: I2c_IrqUnit1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_I2c_IrqUnit1 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 96u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_I2c_IrqUnit1_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_I2c_IrqUnit1 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: IPC_mailbox1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_IPC_mailbox1 =
{
  /* .Level                    = */ 14u,
  /* .Source                   = */ 376u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_IPC_mailbox1_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_IPC_mailbox1 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: IPC_mailbox2 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_IPC_mailbox2 =
{
  /* .Level                    = */ 14u,
  /* .Source                   = */ 377u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_IPC_mailbox2_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_IPC_mailbox2 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: MAIN_ESM0_ESM_INT_CFG_LVL_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MAIN_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 142u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MAIN_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: MAIN_ESM0_ESM_INT_HI_LVL_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MAIN_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 141u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MAIN_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: MAIN_ESM0_ESM_INT_LOW_LVL_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MAIN_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 140u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MAIN_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: MCU_ESM0_ESM_INT_CFG_LVL_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MCU_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 53u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MCU_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: MCU_ESM0_ESM_INT_HI_LVL_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MCU_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 49u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_MCU_ESM0_ESM_INT_HI_LVL_0_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MCU_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: MCU_ESM0_ESM_INT_LOW_LVL_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MCU_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 48u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MCU_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 =
{
  /* .Level                    = */ 4u,
  /* .Source                   = */ 78u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 =
{
  /* .Level                    = */ 4u,
  /* .Source                   = */ 79u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 317u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 295u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 296u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 291u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 290u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 299u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 297u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 298u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 300u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 47u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 36u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 37u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 312u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 310u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 314u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 313u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 309u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 307u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 308u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 306u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 304u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 305u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SciServer_OsIsr_UserMsgHwiFxn1 =
{
  /* .Level                    = */ 5u,
  /* .Source                   = */ 70u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SciServer_OsIsr_UserMsgHwiFxn1_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SciServer_OsIsr_UserMsgHwiFxn1 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn2 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SciServer_OsIsr_UserMsgHwiFxn2 =
{
  /* .Level                    = */ 5u,
  /* .Source                   = */ 71u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SciServer_OsIsr_UserMsgHwiFxn2_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SciServer_OsIsr_UserMsgHwiFxn2 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn3 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SciServer_OsIsr_UserMsgHwiFxn3 =
{
  /* .Level                    = */ 6u,
  /* .Source                   = */ 72u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SciServer_OsIsr_UserMsgHwiFxn3_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SciServer_OsIsr_UserMsgHwiFxn3 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn4 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SciServer_OsIsr_UserMsgHwiFxn4 =
{
  /* .Level                    = */ 6u,
  /* .Source                   = */ 73u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_SciServer_OsIsr_UserMsgHwiFxn4_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SciServer_OsIsr_UserMsgHwiFxn4 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: WKUP_ESM0_ESM_INT_CFG_LVL_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_WKUP_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 100u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_WKUP_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: WKUP_ESM0_ESM_INT_HI_LVL_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_WKUP_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 99u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_WKUP_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: WKUP_ESM0_ESM_INT_LOW_LVL_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_WKUP_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .Level                    = */ 15u,
  /* .Source                   = */ 98u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_WKUP_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL ISR configuration data: vHsmResponseIsr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_vHsmResponseIsr =
{
  /* .Level                    = */ 7u,
  /* .Source                   = */ 44u,
  /* .CoreID                   = */ 0u,
  /* .InterruptControllerType  = */ OS_HAL_ISR_INTC_ROOT,
  /* .Type                     = */ OS_HAL_ISR_TYPE_IRQ,
  /* .SenderCoreID             = */ &OsCfg_Hal_Isr_vHsmResponseIsr_SenderID_Dyn,
  /* .TriggerType              = */ OS_HAL_ISR_TRIGGER_TYPE_LEVEL
}
;

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_vHsmResponseIsr =
{
  /* .Dummy         = */ (uint32)0
}
;

/*! HAL interrupt resource level: OsResource */
CONST(Os_Hal_IntLevelType, OS_CONST) OsCfg_Hal_Resource_OsResource_IntLevel = ((Os_Hal_IntLevelType)OS_HAL_PSR_INTERRUPTS_MASKED)
;

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Interrupt_Lcfg.c
 *********************************************************************************************************************/
