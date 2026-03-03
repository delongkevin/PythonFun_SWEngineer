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
 *              File: Os_Hal_Core_Lcfg.c
 *   Generation Time: 2024-02-13 13:07:49
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_CORE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Core.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Entry_Lcfg.h"
#include "Os_Hal_Interrupt_Lcfg.h"
#include "Os_Hal_Kernel_Lcfg.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL variable used to save registers on exception entry: OsCore0 */
OS_LOCAL VAR(Os_Hal_ExcEntryRegSaveType, OS_VAR_NOINIT_FAST) OsCfg_Hal_ExcEntryRegSaveVar_OsCore0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */




/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic core to thread data: OsCore0 */
OS_LOCAL VAR(Os_Hal_Core2ThreadType, OS_VAR_NOINIT_FAST) OsCfg_Hal_Core2Thread_OsCore0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core initialized interrupt sources: OsCore0 */
CONSTP2CONST(Os_IsrHwConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore0_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE0_INTERRUPTSOURCEREFS + 1u] =
{
  &OsCfg_Isr_ADC0_HwConfig,
  &OsCfg_Isr_ADC1_HwConfig,
  &OsCfg_Isr_Can_30_McanIsr_0_HwConfig,
  &OsCfg_Isr_Can_30_McanIsr_1_HwConfig,
  &OsCfg_Isr_CounterIsr_SystemTimer_HwConfig,
  &OsCfg_Isr_I2c_IrqUnit0_HwConfig,
  &OsCfg_Isr_I2c_IrqUnit1_HwConfig,
  &OsCfg_Isr_IPC_mailbox1_HwConfig,
  &OsCfg_Isr_IPC_mailbox2_HwConfig,
  &OsCfg_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0_HwConfig,
  &OsCfg_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0_HwConfig,
  &OsCfg_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0_HwConfig,
  &OsCfg_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0_HwConfig,
  &OsCfg_Isr_MCU_ESM0_ESM_INT_HI_LVL_0_HwConfig,
  &OsCfg_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0_HwConfig,
  &OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_HwConfig,
  &OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_HwConfig,
  &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_HwConfig,
  &OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn1_HwConfig,
  &OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn2_HwConfig,
  &OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn3_HwConfig,
  &OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn4_HwConfig,
  &OsCfg_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0_HwConfig,
  &OsCfg_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0_HwConfig,
  &OsCfg_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0_HwConfig,
  &OsCfg_Isr_vHsmResponseIsr_HwConfig,
  NULL_PTR
};


/*! HAL core configuration data: OsCore0 */
CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore0 =
{
  /* .CoreId  = */ 0 /* OsCore0 */
}
;

/*! HAL AUTOSAR core configuration data: OsCore0 */
CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore0 =
{
  /* .ExcEntryRegSaveVarRef     = */ &OsCfg_Hal_ExcEntryRegSaveVar_OsCore0_Dyn,
  /* .ExceptionTable            = */ (Os_Hal_ExceptionTableType)OsCfg_Hal_Core_OsCore0_ExceptionTable,
  /* .IrqVectorTable            = */ {(Os_Hal_VectorTableType)OsCfg_Hal_Core_OsCore0_VectorTable},
  /* .FiqVectorTable            = */ NULL_PTR,
  /* .StackProtectionStartLabel = */ (Os_AddressOfConstType)(NULL_PTR),            
  /* .StackProtectionLimitLabel = */ (Os_AddressOfConstType)(NULL_PTR)             

};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core to thread configuration data. */
CONST(Os_Hal_Core2ThreadConfigType, OS_CONST) OsCfg_Hal_Core2Thread =
{
  /* .Core2Thread = */
  {
    &OsCfg_Hal_Core2Thread_OsCore0_Dyn, /* OS_CORE_ID_0 */
  }
};

/*! HAL system configuration data. */
CONST(Os_Hal_SystemConfigType, OS_CONST) OsCfg_Hal_System =
{
  /* .Dummy = */ 0,
};

/*! Interrupt sources which are initialized by the hardware init core. */
CONSTP2CONST(Os_IsrHwConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_System_InterruptSourceRefs[OS_CFG_NUM_SYSTEM_INTERRUPTSOURCEREFS + 1u] =
{
  NULL_PTR
};


#define OS_STOP_SEC_CONST_UNSPECIFIED
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
 *  END OF FILE: Os_Hal_Core_Lcfg.c
 *********************************************************************************************************************/

