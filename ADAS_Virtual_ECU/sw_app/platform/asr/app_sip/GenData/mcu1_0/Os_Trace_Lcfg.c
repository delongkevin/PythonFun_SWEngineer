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
 *              File: Os_Trace_Lcfg.c
 *   Generation Time: 2024-02-13 13:07:51
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_TRACE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Trace_Lcfg.h"
#include "Os_Trace.h"

/* Os kernel module dependencies */
#include "Os_Common_Types.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic trace data: OsCore0 */
VAR(Os_TraceCoreType, OS_VAR_NOINIT) OsCfg_Trace_OsCore0_Dyn;

/*! Dynamic trace data: BootAppOsTask */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_BootAppOsTask_Dyn;

/*! Dynamic trace data: IdleTask_OsCore0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_IdleTask_OsCore0_Dyn;

/*! Dynamic trace data: QM_ComTask_10ms */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_QM_ComTask_10ms_Dyn;

/*! Dynamic trace data: QM_ComTask_5ms */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_QM_ComTask_5ms_Dyn;

/*! Dynamic trace data: QM_DiagTask_10ms */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_QM_DiagTask_10ms_Dyn;

/*! Dynamic trace data: QM_MemTask_10ms */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_QM_MemTask_10ms_Dyn;

/*! Dynamic trace data: QM_Task_00_10ms */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_QM_Task_00_10ms_Dyn;

/*! Dynamic trace data: QM_Task_01_10ms */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_QM_Task_01_10ms_Dyn;

/*! Dynamic trace data: QM_Task_200ms */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_QM_Task_200ms_Dyn;

/*! Dynamic trace data: QM_Task_Init */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_QM_Task_Init_Dyn;

/*! Dynamic trace data: Safety_Task_00_10ms */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Safety_Task_00_10ms_Dyn;

/*! Dynamic trace data: Safety_Task_01_10ms */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Safety_Task_01_10ms_Dyn;

/*! Dynamic trace data: Safety_Task_200ms */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Safety_Task_200ms_Dyn;

/*! Dynamic trace data: Safety_Task_Init */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Safety_Task_Init_Dyn;

/*! Dynamic trace data: Safety_WdgTask_10ms */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Safety_WdgTask_10ms_Dyn;

/*! Dynamic trace data: SciServerHighOsTask */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SciServerHighOsTask_Dyn;

/*! Dynamic trace data: SciServerLowOsTask */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SciServerLowOsTask_Dyn;

/*! Dynamic trace data: ShutdownTask */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_ShutdownTask_Dyn;

/*! Dynamic trace data: StartUpTask */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_StartUpTask_Dyn;

/*! Dynamic trace data: ADC0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_ADC0_Dyn;

/*! Dynamic trace data: ADC1 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_ADC1_Dyn;

/*! Dynamic trace data: Can_30_McanIsr_0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Can_30_McanIsr_0_Dyn;

/*! Dynamic trace data: Can_30_McanIsr_1 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Can_30_McanIsr_1_Dyn;

/*! Dynamic trace data: CounterIsr_SystemTimer */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_CounterIsr_SystemTimer_Dyn;

/*! Dynamic trace data: I2c_IrqUnit0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_I2c_IrqUnit0_Dyn;

/*! Dynamic trace data: I2c_IrqUnit1 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_I2c_IrqUnit1_Dyn;

/*! Dynamic trace data: IPC_mailbox1 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_IPC_mailbox1_Dyn;

/*! Dynamic trace data: IPC_mailbox2 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_IPC_mailbox2_Dyn;

/*! Dynamic trace data: MAIN_ESM0_ESM_INT_CFG_LVL_0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_MAIN_ESM0_ESM_INT_CFG_LVL_0_Dyn;

/*! Dynamic trace data: MAIN_ESM0_ESM_INT_HI_LVL_0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_MAIN_ESM0_ESM_INT_HI_LVL_0_Dyn;

/*! Dynamic trace data: MAIN_ESM0_ESM_INT_LOW_LVL_0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_MAIN_ESM0_ESM_INT_LOW_LVL_0_Dyn;

/*! Dynamic trace data: MCU_ESM0_ESM_INT_CFG_LVL_0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_MCU_ESM0_ESM_INT_CFG_LVL_0_Dyn;

/*! Dynamic trace data: MCU_ESM0_ESM_INT_HI_LVL_0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_MCU_ESM0_ESM_INT_HI_LVL_0_Dyn;

/*! Dynamic trace data: MCU_ESM0_ESM_INT_LOW_LVL_0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_MCU_ESM0_ESM_INT_LOW_LVL_0_Dyn;

/*! Dynamic trace data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_Dyn;

/*! Dynamic trace data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_Dyn;

/*! Dynamic trace data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_Dyn;

/*! Dynamic trace data: SciServer_OsIsr_UserMsgHwiFxn1 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn1_Dyn;

/*! Dynamic trace data: SciServer_OsIsr_UserMsgHwiFxn2 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn2_Dyn;

/*! Dynamic trace data: SciServer_OsIsr_UserMsgHwiFxn3 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn3_Dyn;

/*! Dynamic trace data: SciServer_OsIsr_UserMsgHwiFxn4 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn4_Dyn;

/*! Dynamic trace data: WKUP_ESM0_ESM_INT_CFG_LVL_0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_WKUP_ESM0_ESM_INT_CFG_LVL_0_Dyn;

/*! Dynamic trace data: WKUP_ESM0_ESM_INT_HI_LVL_0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_WKUP_ESM0_ESM_INT_HI_LVL_0_Dyn;

/*! Dynamic trace data: WKUP_ESM0_ESM_INT_LOW_LVL_0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_WKUP_ESM0_ESM_INT_LOW_LVL_0_Dyn;

/*! Dynamic trace data: vHsmResponseIsr */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_vHsmResponseIsr_Dyn;

/*! Dynamic trace data: OsCore0_Hooks */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_OsCore0_Hooks_Dyn;

#define OS_STOP_SEC_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Trace configuration data: OsApplication_QM */
CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_OsApplication_QM =
{
  /* .Id   = */ Os_TraceId_OsApplication_QM
};

/*! Trace configuration data: OsApplication_Safety */
CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_OsApplication_Safety =
{
  /* .Id   = */ Os_TraceId_OsApplication_Safety
};

/*! Trace configuration data: OsApplication_Trusted_Core0 */
CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_OsApplication_Trusted_Core0 =
{
  /* .Id   = */ Os_TraceId_OsApplication_Trusted_Core0
};

/*! Trace configuration data: SystemApplication_OsCore0 */
CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_SystemApplication_OsCore0 =
{
  /* .Id   = */ Os_TraceId_SystemApplication_OsCore0
};

/*! Trace configuration data: BootAppOsTask */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_BootAppOsTask =
{
  /* .Dyn  = */ &OsCfg_Trace_BootAppOsTask_Dyn,
  /* .Id   = */ Os_TraceId_BootAppOsTask,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: IdleTask_OsCore0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_IdleTask_OsCore0 =
{
  /* .Dyn  = */ &OsCfg_Trace_IdleTask_OsCore0_Dyn,
  /* .Id   = */ Os_TraceId_IdleTask_OsCore0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: QM_ComTask_10ms */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_ComTask_10ms =
{
  /* .Dyn  = */ &OsCfg_Trace_QM_ComTask_10ms_Dyn,
  /* .Id   = */ Os_TraceId_QM_ComTask_10ms,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: QM_ComTask_5ms */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_ComTask_5ms =
{
  /* .Dyn  = */ &OsCfg_Trace_QM_ComTask_5ms_Dyn,
  /* .Id   = */ Os_TraceId_QM_ComTask_5ms,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: QM_DiagTask_10ms */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_DiagTask_10ms =
{
  /* .Dyn  = */ &OsCfg_Trace_QM_DiagTask_10ms_Dyn,
  /* .Id   = */ Os_TraceId_QM_DiagTask_10ms,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: QM_MemTask_10ms */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_MemTask_10ms =
{
  /* .Dyn  = */ &OsCfg_Trace_QM_MemTask_10ms_Dyn,
  /* .Id   = */ Os_TraceId_QM_MemTask_10ms,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: QM_Task_00_10ms */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_Task_00_10ms =
{
  /* .Dyn  = */ &OsCfg_Trace_QM_Task_00_10ms_Dyn,
  /* .Id   = */ Os_TraceId_QM_Task_00_10ms,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: QM_Task_01_10ms */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_Task_01_10ms =
{
  /* .Dyn  = */ &OsCfg_Trace_QM_Task_01_10ms_Dyn,
  /* .Id   = */ Os_TraceId_QM_Task_01_10ms,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: QM_Task_200ms */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_Task_200ms =
{
  /* .Dyn  = */ &OsCfg_Trace_QM_Task_200ms_Dyn,
  /* .Id   = */ Os_TraceId_QM_Task_200ms,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: QM_Task_Init */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_Task_Init =
{
  /* .Dyn  = */ &OsCfg_Trace_QM_Task_Init_Dyn,
  /* .Id   = */ Os_TraceId_QM_Task_Init,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Safety_Task_00_10ms */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Safety_Task_00_10ms =
{
  /* .Dyn  = */ &OsCfg_Trace_Safety_Task_00_10ms_Dyn,
  /* .Id   = */ Os_TraceId_Safety_Task_00_10ms,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Safety_Task_01_10ms */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Safety_Task_01_10ms =
{
  /* .Dyn  = */ &OsCfg_Trace_Safety_Task_01_10ms_Dyn,
  /* .Id   = */ Os_TraceId_Safety_Task_01_10ms,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Safety_Task_200ms */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Safety_Task_200ms =
{
  /* .Dyn  = */ &OsCfg_Trace_Safety_Task_200ms_Dyn,
  /* .Id   = */ Os_TraceId_Safety_Task_200ms,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Safety_Task_Init */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Safety_Task_Init =
{
  /* .Dyn  = */ &OsCfg_Trace_Safety_Task_Init_Dyn,
  /* .Id   = */ Os_TraceId_Safety_Task_Init,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Safety_WdgTask_10ms */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Safety_WdgTask_10ms =
{
  /* .Dyn  = */ &OsCfg_Trace_Safety_WdgTask_10ms_Dyn,
  /* .Id   = */ Os_TraceId_Safety_WdgTask_10ms,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: SciServerHighOsTask */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SciServerHighOsTask =
{
  /* .Dyn  = */ &OsCfg_Trace_SciServerHighOsTask_Dyn,
  /* .Id   = */ Os_TraceId_SciServerHighOsTask,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: SciServerLowOsTask */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SciServerLowOsTask =
{
  /* .Dyn  = */ &OsCfg_Trace_SciServerLowOsTask_Dyn,
  /* .Id   = */ Os_TraceId_SciServerLowOsTask,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: ShutdownTask */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_ShutdownTask =
{
  /* .Dyn  = */ &OsCfg_Trace_ShutdownTask_Dyn,
  /* .Id   = */ Os_TraceId_ShutdownTask,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: StartUpTask */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_StartUpTask =
{
  /* .Dyn  = */ &OsCfg_Trace_StartUpTask_Dyn,
  /* .Id   = */ Os_TraceId_StartUpTask,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: ADC0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_ADC0 =
{
  /* .Dyn  = */ &OsCfg_Trace_ADC0_Dyn,
  /* .Id   = */ Os_TraceId_ADC0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: ADC1 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_ADC1 =
{
  /* .Dyn  = */ &OsCfg_Trace_ADC1_Dyn,
  /* .Id   = */ Os_TraceId_ADC1,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: Can_30_McanIsr_0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Can_30_McanIsr_0 =
{
  /* .Dyn  = */ &OsCfg_Trace_Can_30_McanIsr_0_Dyn,
  /* .Id   = */ Os_TraceId_Can_30_McanIsr_0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: Can_30_McanIsr_1 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Can_30_McanIsr_1 =
{
  /* .Dyn  = */ &OsCfg_Trace_Can_30_McanIsr_1_Dyn,
  /* .Id   = */ Os_TraceId_Can_30_McanIsr_1,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: CounterIsr_SystemTimer */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CounterIsr_SystemTimer =
{
  /* .Dyn  = */ &OsCfg_Trace_CounterIsr_SystemTimer_Dyn,
  /* .Id   = */ Os_TraceId_CounterIsr_SystemTimer,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: I2c_IrqUnit0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_I2c_IrqUnit0 =
{
  /* .Dyn  = */ &OsCfg_Trace_I2c_IrqUnit0_Dyn,
  /* .Id   = */ Os_TraceId_I2c_IrqUnit0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: I2c_IrqUnit1 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_I2c_IrqUnit1 =
{
  /* .Dyn  = */ &OsCfg_Trace_I2c_IrqUnit1_Dyn,
  /* .Id   = */ Os_TraceId_I2c_IrqUnit1,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: IPC_mailbox1 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_IPC_mailbox1 =
{
  /* .Dyn  = */ &OsCfg_Trace_IPC_mailbox1_Dyn,
  /* .Id   = */ Os_TraceId_IPC_mailbox1,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: IPC_mailbox2 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_IPC_mailbox2 =
{
  /* .Dyn  = */ &OsCfg_Trace_IPC_mailbox2_Dyn,
  /* .Id   = */ Os_TraceId_IPC_mailbox2,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: MAIN_ESM0_ESM_INT_CFG_LVL_0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MAIN_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .Dyn  = */ &OsCfg_Trace_MAIN_ESM0_ESM_INT_CFG_LVL_0_Dyn,
  /* .Id   = */ Os_TraceId_MAIN_ESM0_ESM_INT_CFG_LVL_0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: MAIN_ESM0_ESM_INT_HI_LVL_0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MAIN_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .Dyn  = */ &OsCfg_Trace_MAIN_ESM0_ESM_INT_HI_LVL_0_Dyn,
  /* .Id   = */ Os_TraceId_MAIN_ESM0_ESM_INT_HI_LVL_0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: MAIN_ESM0_ESM_INT_LOW_LVL_0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MAIN_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .Dyn  = */ &OsCfg_Trace_MAIN_ESM0_ESM_INT_LOW_LVL_0_Dyn,
  /* .Id   = */ Os_TraceId_MAIN_ESM0_ESM_INT_LOW_LVL_0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: MCU_ESM0_ESM_INT_CFG_LVL_0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MCU_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .Dyn  = */ &OsCfg_Trace_MCU_ESM0_ESM_INT_CFG_LVL_0_Dyn,
  /* .Id   = */ Os_TraceId_MCU_ESM0_ESM_INT_CFG_LVL_0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: MCU_ESM0_ESM_INT_HI_LVL_0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MCU_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .Dyn  = */ &OsCfg_Trace_MCU_ESM0_ESM_INT_HI_LVL_0_Dyn,
  /* .Id   = */ Os_TraceId_MCU_ESM0_ESM_INT_HI_LVL_0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: MCU_ESM0_ESM_INT_LOW_LVL_0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MCU_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .Dyn  = */ &OsCfg_Trace_MCU_ESM0_ESM_INT_LOW_LVL_0_Dyn,
  /* .Id   = */ Os_TraceId_MCU_ESM0_ESM_INT_LOW_LVL_0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 =
{
  /* .Dyn  = */ &OsCfg_Trace_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_Dyn,
  /* .Id   = */ Os_TraceId_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 =
{
  /* .Dyn  = */ &OsCfg_Trace_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_Dyn,
  /* .Id   = */ Os_TraceId_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 =
{
  /* .Dyn  = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_Dyn,
  /* .Id   = */ Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SciServer_OsIsr_UserMsgHwiFxn1 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn1 =
{
  /* .Dyn  = */ &OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn1_Dyn,
  /* .Id   = */ Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn1,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SciServer_OsIsr_UserMsgHwiFxn2 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn2 =
{
  /* .Dyn  = */ &OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn2_Dyn,
  /* .Id   = */ Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn2,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SciServer_OsIsr_UserMsgHwiFxn3 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn3 =
{
  /* .Dyn  = */ &OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn3_Dyn,
  /* .Id   = */ Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn3,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: SciServer_OsIsr_UserMsgHwiFxn4 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn4 =
{
  /* .Dyn  = */ &OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn4_Dyn,
  /* .Id   = */ Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn4,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: WKUP_ESM0_ESM_INT_CFG_LVL_0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_WKUP_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .Dyn  = */ &OsCfg_Trace_WKUP_ESM0_ESM_INT_CFG_LVL_0_Dyn,
  /* .Id   = */ Os_TraceId_WKUP_ESM0_ESM_INT_CFG_LVL_0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: WKUP_ESM0_ESM_INT_HI_LVL_0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_WKUP_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .Dyn  = */ &OsCfg_Trace_WKUP_ESM0_ESM_INT_HI_LVL_0_Dyn,
  /* .Id   = */ Os_TraceId_WKUP_ESM0_ESM_INT_HI_LVL_0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: WKUP_ESM0_ESM_INT_LOW_LVL_0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_WKUP_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .Dyn  = */ &OsCfg_Trace_WKUP_ESM0_ESM_INT_LOW_LVL_0_Dyn,
  /* .Id   = */ Os_TraceId_WKUP_ESM0_ESM_INT_LOW_LVL_0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: vHsmResponseIsr */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_vHsmResponseIsr =
{
  /* .Dyn  = */ &OsCfg_Trace_vHsmResponseIsr_Dyn,
  /* .Id   = */ Os_TraceId_vHsmResponseIsr,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: OsCore0_Hooks */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsCore0_Hooks =
{
  /* .Dyn  = */ &OsCfg_Trace_OsCore0_Hooks_Dyn,
  /* .Id   = */ Os_TraceId_OsCore0_Hooks,
  /* .Type = */ OS_TRACE_THREAD_TYPE_MISC
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
 *  END OF FILE: Os_Trace_Lcfg.c
 *********************************************************************************************************************/
