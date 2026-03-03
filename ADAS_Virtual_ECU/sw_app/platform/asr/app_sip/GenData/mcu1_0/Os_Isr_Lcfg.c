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
 *              File: Os_Isr_Lcfg.c
 *   Generation Time: 2024-02-13 13:07:50
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_ISR_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Isr_Lcfg.h"
#include "Os_Isr.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Thread.h"
#include "Os_Timer.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "Os_XSignal_Lcfg.h"
#include "Os_XSignal.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Interrupt_Lcfg.h"


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

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic ISR data: ADC0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_ADC0_Dyn;

/*! Dynamic ISR data: ADC1 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_ADC1_Dyn;

/*! Dynamic ISR data: Can_30_McanIsr_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Can_30_McanIsr_0_Dyn;

/*! Dynamic ISR data: Can_30_McanIsr_1 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Can_30_McanIsr_1_Dyn;

/*! Dynamic ISR data: CounterIsr_SystemTimer */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_SystemTimer_Dyn;

/*! Dynamic ISR data: I2c_IrqUnit0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_I2c_IrqUnit0_Dyn;

/*! Dynamic ISR data: I2c_IrqUnit1 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_I2c_IrqUnit1_Dyn;

/*! Dynamic ISR data: IPC_mailbox1 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_IPC_mailbox1_Dyn;

/*! Dynamic ISR data: IPC_mailbox2 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_IPC_mailbox2_Dyn;

/*! Dynamic ISR data: MAIN_ESM0_ESM_INT_CFG_LVL_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0_Dyn;

/*! Dynamic ISR data: MAIN_ESM0_ESM_INT_HI_LVL_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0_Dyn;

/*! Dynamic ISR data: MAIN_ESM0_ESM_INT_LOW_LVL_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0_Dyn;

/*! Dynamic ISR data: MCU_ESM0_ESM_INT_CFG_LVL_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0_Dyn;

/*! Dynamic ISR data: MCU_ESM0_ESM_INT_HI_LVL_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MCU_ESM0_ESM_INT_HI_LVL_0_Dyn;

/*! Dynamic ISR data: MCU_ESM0_ESM_INT_LOW_LVL_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0_Dyn;

/*! Dynamic ISR data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_Dyn;

/*! Dynamic ISR data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_Dyn;

/*! Dynamic ISR data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_Dyn;

/*! Dynamic ISR data: SciServer_OsIsr_UserMsgHwiFxn1 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn1_Dyn;

/*! Dynamic ISR data: SciServer_OsIsr_UserMsgHwiFxn2 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn2_Dyn;

/*! Dynamic ISR data: SciServer_OsIsr_UserMsgHwiFxn3 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn3_Dyn;

/*! Dynamic ISR data: SciServer_OsIsr_UserMsgHwiFxn4 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn4_Dyn;

/*! Dynamic ISR data: WKUP_ESM0_ESM_INT_CFG_LVL_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0_Dyn;

/*! Dynamic ISR data: WKUP_ESM0_ESM_INT_HI_LVL_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0_Dyn;

/*! Dynamic ISR data: WKUP_ESM0_ESM_INT_LOW_LVL_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0_Dyn;

/*! Dynamic ISR data: vHsmResponseIsr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_vHsmResponseIsr_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: ADC0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_ADC0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_ADC0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_ADC0,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ADC0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_ADC0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_ADC0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_ADC0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_ADC0_HwConfig,
  /* .IsrId                     = */ ADC0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: ADC1 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_ADC1_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_ADC1,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_ADC1,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC1 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ADC1,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_ADC1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_ADC1,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_ADC1,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_ADC1_HwConfig,
  /* .IsrId                     = */ ADC1,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Can_30_McanIsr_0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Can_30_McanIsr_0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Can_30_McanIsr_0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Can_30_McanIsr_0,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Can_30_McanIsr_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Can_30_McanIsr_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level5_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Can_30_McanIsr_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Can_30_McanIsr_0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Can_30_McanIsr_0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Can_30_McanIsr_0_HwConfig,
  /* .IsrId                     = */ Can_30_McanIsr_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Can_30_McanIsr_1 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Can_30_McanIsr_1_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Can_30_McanIsr_1,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Can_30_McanIsr_1,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Can_30_McanIsr_1 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Can_30_McanIsr_1,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Can_30_McanIsr_1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Can_30_McanIsr_1,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Can_30_McanIsr_1,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Can_30_McanIsr_1_HwConfig,
  /* .IsrId                     = */ Can_30_McanIsr_1,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CounterIsr_SystemTimer */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CounterIsr_SystemTimer,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_SystemTimer,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_SystemTimer_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CounterIsr_SystemTimer,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_CounterIsr_SystemTimer,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CounterIsr_SystemTimer_HwConfig,
  /* .IsrId                     = */ CounterIsr_SystemTimer,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer)
};
/*! ISR configuration data: I2c_IrqUnit0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_I2c_IrqUnit0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_I2c_IrqUnit0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_I2c_IrqUnit0,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_I2c_IrqUnit0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_I2c_IrqUnit0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_I2c_IrqUnit0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_I2c_IrqUnit0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_I2c_IrqUnit0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_I2c_IrqUnit0_HwConfig,
  /* .IsrId                     = */ I2c_IrqUnit0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: I2c_IrqUnit1 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_I2c_IrqUnit1_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_I2c_IrqUnit1,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_I2c_IrqUnit1,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_I2c_IrqUnit1 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_I2c_IrqUnit1,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_I2c_IrqUnit1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_I2c_IrqUnit1,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_I2c_IrqUnit1,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_I2c_IrqUnit1_HwConfig,
  /* .IsrId                     = */ I2c_IrqUnit1,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: IPC_mailbox1 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_IPC_mailbox1_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_IPC_mailbox1,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_IPC_mailbox1,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_IPC_mailbox1 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_IPC_mailbox1,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_IPC_mailbox1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_IPC_mailbox1,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_IPC_mailbox1,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_IPC_mailbox1_HwConfig,
  /* .IsrId                     = */ IPC_mailbox1,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: IPC_mailbox2 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_IPC_mailbox2_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_IPC_mailbox2,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_IPC_mailbox2,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_IPC_mailbox2 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_IPC_mailbox2,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_IPC_mailbox2_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_IPC_mailbox2,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_IPC_mailbox2,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_IPC_mailbox2_HwConfig,
  /* .IsrId                     = */ IPC_mailbox2,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: MAIN_ESM0_ESM_INT_CFG_LVL_0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_MAIN_ESM0_ESM_INT_CFG_LVL_0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_MAIN_ESM0_ESM_INT_CFG_LVL_0,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MAIN_ESM0_ESM_INT_CFG_LVL_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MAIN_ESM0_ESM_INT_CFG_LVL_0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_MAIN_ESM0_ESM_INT_CFG_LVL_0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0_HwConfig,
  /* .IsrId                     = */ MAIN_ESM0_ESM_INT_CFG_LVL_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: MAIN_ESM0_ESM_INT_HI_LVL_0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_MAIN_ESM0_ESM_INT_HI_LVL_0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_MAIN_ESM0_ESM_INT_HI_LVL_0,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MAIN_ESM0_ESM_INT_HI_LVL_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MAIN_ESM0_ESM_INT_HI_LVL_0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_MAIN_ESM0_ESM_INT_HI_LVL_0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0_HwConfig,
  /* .IsrId                     = */ MAIN_ESM0_ESM_INT_HI_LVL_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: MAIN_ESM0_ESM_INT_LOW_LVL_0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_MAIN_ESM0_ESM_INT_LOW_LVL_0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_MAIN_ESM0_ESM_INT_LOW_LVL_0,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MAIN_ESM0_ESM_INT_LOW_LVL_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MAIN_ESM0_ESM_INT_LOW_LVL_0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_MAIN_ESM0_ESM_INT_LOW_LVL_0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0_HwConfig,
  /* .IsrId                     = */ MAIN_ESM0_ESM_INT_LOW_LVL_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: MCU_ESM0_ESM_INT_CFG_LVL_0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_MCU_ESM0_ESM_INT_CFG_LVL_0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_MCU_ESM0_ESM_INT_CFG_LVL_0,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MCU_ESM0_ESM_INT_CFG_LVL_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MCU_ESM0_ESM_INT_CFG_LVL_0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_MCU_ESM0_ESM_INT_CFG_LVL_0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0_HwConfig,
  /* .IsrId                     = */ MCU_ESM0_ESM_INT_CFG_LVL_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: MCU_ESM0_ESM_INT_HI_LVL_0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MCU_ESM0_ESM_INT_HI_LVL_0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_MCU_ESM0_ESM_INT_HI_LVL_0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_MCU_ESM0_ESM_INT_HI_LVL_0,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MCU_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MCU_ESM0_ESM_INT_HI_LVL_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MCU_ESM0_ESM_INT_HI_LVL_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MCU_ESM0_ESM_INT_HI_LVL_0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_MCU_ESM0_ESM_INT_HI_LVL_0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_MCU_ESM0_ESM_INT_HI_LVL_0_HwConfig,
  /* .IsrId                     = */ MCU_ESM0_ESM_INT_HI_LVL_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: MCU_ESM0_ESM_INT_LOW_LVL_0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_MCU_ESM0_ESM_INT_LOW_LVL_0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_MCU_ESM0_ESM_INT_LOW_LVL_0,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MCU_ESM0_ESM_INT_LOW_LVL_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MCU_ESM0_ESM_INT_LOW_LVL_0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_MCU_ESM0_ESM_INT_LOW_LVL_0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0_HwConfig,
  /* .IsrId                     = */ MCU_ESM0_ESM_INT_LOW_LVL_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_HwConfig,
  /* .IsrId                     = */ MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_HwConfig,
  /* .IsrId                     = */ MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_HwConfig,
  /* .IsrId                     = */ SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn1 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn1_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SciServer_OsIsr_UserMsgHwiFxn1,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SciServer_OsIsr_UserMsgHwiFxn1,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn1 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SciServer_OsIsr_UserMsgHwiFxn1,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level8_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SciServer_OsIsr_UserMsgHwiFxn1,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn1,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn1_HwConfig,
  /* .IsrId                     = */ SciServer_OsIsr_UserMsgHwiFxn1,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn2 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn2_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SciServer_OsIsr_UserMsgHwiFxn2,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SciServer_OsIsr_UserMsgHwiFxn2,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn2 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SciServer_OsIsr_UserMsgHwiFxn2,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level8_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn2_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SciServer_OsIsr_UserMsgHwiFxn2,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn2,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn2_HwConfig,
  /* .IsrId                     = */ SciServer_OsIsr_UserMsgHwiFxn2,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn3 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn3_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SciServer_OsIsr_UserMsgHwiFxn3,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SciServer_OsIsr_UserMsgHwiFxn3,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn3 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SciServer_OsIsr_UserMsgHwiFxn3,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn3_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SciServer_OsIsr_UserMsgHwiFxn3,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn3,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn3_HwConfig,
  /* .IsrId                     = */ SciServer_OsIsr_UserMsgHwiFxn3,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SciServer_OsIsr_UserMsgHwiFxn4 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn4_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SciServer_OsIsr_UserMsgHwiFxn4,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SciServer_OsIsr_UserMsgHwiFxn4,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn4 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SciServer_OsIsr_UserMsgHwiFxn4,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn4_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SciServer_OsIsr_UserMsgHwiFxn4,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn4,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn4_HwConfig,
  /* .IsrId                     = */ SciServer_OsIsr_UserMsgHwiFxn4,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: WKUP_ESM0_ESM_INT_CFG_LVL_0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_WKUP_ESM0_ESM_INT_CFG_LVL_0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_WKUP_ESM0_ESM_INT_CFG_LVL_0,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_WKUP_ESM0_ESM_INT_CFG_LVL_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_WKUP_ESM0_ESM_INT_CFG_LVL_0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_WKUP_ESM0_ESM_INT_CFG_LVL_0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0_HwConfig,
  /* .IsrId                     = */ WKUP_ESM0_ESM_INT_CFG_LVL_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: WKUP_ESM0_ESM_INT_HI_LVL_0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_WKUP_ESM0_ESM_INT_HI_LVL_0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_WKUP_ESM0_ESM_INT_HI_LVL_0,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_WKUP_ESM0_ESM_INT_HI_LVL_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_WKUP_ESM0_ESM_INT_HI_LVL_0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_WKUP_ESM0_ESM_INT_HI_LVL_0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0_HwConfig,
  /* .IsrId                     = */ WKUP_ESM0_ESM_INT_HI_LVL_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: WKUP_ESM0_ESM_INT_LOW_LVL_0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_WKUP_ESM0_ESM_INT_LOW_LVL_0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_WKUP_ESM0_ESM_INT_LOW_LVL_0,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_WKUP_ESM0_ESM_INT_LOW_LVL_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_WKUP_ESM0_ESM_INT_LOW_LVL_0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_WKUP_ESM0_ESM_INT_LOW_LVL_0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0_HwConfig,
  /* .IsrId                     = */ WKUP_ESM0_ESM_INT_LOW_LVL_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: vHsmResponseIsr */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_vHsmResponseIsr_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_vHsmResponseIsr,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_vHsmResponseIsr,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ TRUE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_vHsmResponseIsr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_vHsmResponseIsr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_vHsmResponseIsr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_vHsmResponseIsr,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_vHsmResponseIsr,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_vHsmResponseIsr_HwConfig,
  /* .IsrId                     = */ vHsmResponseIsr,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for category 2 ISRs. */
CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC1),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Can_30_McanIsr_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Can_30_McanIsr_1),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_I2c_IrqUnit0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_I2c_IrqUnit1),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_IPC_mailbox1),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_IPC_mailbox2),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MCU_ESM0_ESM_INT_HI_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn1),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn2),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn3),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn4),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_vHsmResponseIsr),
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
 *  END OF FILE: Os_Isr_Lcfg.c
 *********************************************************************************************************************/
