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
 *              File: Os_Core_Lcfg.c
 *   Generation Time: 2025-06-18 19:15:00
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_CORE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Core_Cfg.h"
#include "Os_Core_Lcfg.h"
#include "Os_Core.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Barrier_Lcfg.h"
#include "Os_Common.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Resource_Lcfg.h"
#include "Os_Scheduler_Lcfg.h"
#include "Os_Spinlock_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "Os.h"

/* Os hal dependencies */
#include "Os_Hal_Core_Cfg.h"
#include "Os_Hal_Core_Lcfg.h"
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

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core status: OsCore0 */
OS_LOCAL VAR(Os_CoreAsrStatusType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_Status_Dyn;

#define OS_STOP_SEC_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Thread class data for: OsCore0 */
OS_LOCAL VAR(Os_ThreadClassType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_ThreadClass;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core boot barrier: OsCore0 */
OS_LOCAL VAR(Os_CoreBootBarrierType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_BootBarrier_Dyn;

#define OS_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core data: OsCore0 */
VAR(Os_CoreAsrType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for core hooks: OsCore0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_Core_OsCore0_HookRefs[OS_CFG_NUM_CORE_OSCORE0_HOOKS + 1u] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ShutdownHook_OsCore0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ErrorHook_OsCore0),
  OS_HOOK_CASTCONFIG_PROTECTIONHOOK_2_HOOK(OsCfg_Hook_ProtectionHook_OsCore0),
  NULL_PTR
};

/*! Object reference table for core applications: OsCore0 */
OS_LOCAL CONST(Os_AppConfigRefType, OS_CONST) OsCfg_Core_OsCore0_AppRefs[OS_CFG_NUM_CORE_OSCORE0_APPS + 1u] =
{
  (Os_AppConfigRefType) &OsCfg_App_OsApplication_QM,
  (Os_AppConfigRefType) &OsCfg_App_OsApplication_Safety,
  (Os_AppConfigRefType) &OsCfg_App_OsApplication_Trusted_Core0,
  NULL_PTR
};

/*! Object reference table for core IOC communications: OsCore0 */
OS_LOCAL CONST(Os_IocConfigRefType, OS_CONST) OsCfg_Core_OsCore0_IocRefs[OS_CFG_NUM_CORE_OSCORE0_IOCS + 1u] =
{
  OS_IOC_CASTCONFIG_IOCREAD_2_IOC(OsCfg_IocRecv_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM),
  OS_IOC_CASTCONFIG_IOCWRITE_2_IOC(OsCfg_IocSend_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_0),
  OS_IOC_CASTCONFIG_IOCWRITE_2_IOC(OsCfg_IocSend_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_1),
  NULL_PTR
};

/*! Object reference table for core barriers: OsCore0 */
OS_LOCAL CONST(Os_BarrierBaseConfigRefType, OS_CONST) OsCfg_Core_OsCore0_BarrierRefs[OS_CFG_NUM_BARRIERS + 1u] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */ 
{
  NULL_PTR
};

/*! Object reference table for core resources: OsCore0 */
OS_LOCAL CONST(Os_ResourceConfigRefType, OS_CONST) OsCfg_Core_OsCore0_ResourceRefs[OS_CFG_NUM_CORE_OSCORE0_RESOURCES + 1u] =
{
  OS_RESOURCE_CASTCONFIG_RESOURCEINTERRUPT_2_RESOURCE(OsCfg_Resource_OsResource),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_OsResource_PMIC),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_OsResource_SciSecureproxy),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_OsResource_SciServerSync),
  NULL_PTR
};

/*! Object reference table for core stacks: OsCore0 */
OS_LOCAL CONST(Os_StackConfigRefType, OS_CONST) OsCfg_Core_OsCore0_StackRefs[OS_CFG_NUM_CORE_OSCORE0_STACKS + 1u] =
{
  (Os_StackConfigRefType) &OsCfg_Stack_BootAppOsTask,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Error,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Init,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Isr_Core,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Kernel,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Protection,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Shutdown,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio100,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio4294967295,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio50,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio54,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio78,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio79,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio88,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio90,
  (Os_StackConfigRefType) &OsCfg_Stack_QM_ComTask_10ms,
  (Os_StackConfigRefType) &OsCfg_Stack_QM_ComTask_5ms,
  (Os_StackConfigRefType) &OsCfg_Stack_QM_DiagTask_10ms,
  (Os_StackConfigRefType) &OsCfg_Stack_QM_MemTask_10ms,
  (Os_StackConfigRefType) &OsCfg_Stack_QM_Task_200ms,
  (Os_StackConfigRefType) &OsCfg_Stack_Safety_Task_200ms,
  (Os_StackConfigRefType) &OsCfg_Stack_Safety_WdgTask_10ms,
  (Os_StackConfigRefType) &OsCfg_Stack_SciServerHighOsTask,
  (Os_StackConfigRefType) &OsCfg_Stack_SciServerLowOsTask,
  NULL_PTR
};

/*! Object reference table for core ISRs: OsCore0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_Core_OsCore0_IsrRefs[OS_CFG_NUM_CORE_OSCORE0_ISRS + 1u] =
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

/*! Core configuration data: OsCore0 */
CONST(Os_CoreAsrConfigType, OS_CONST) OsCfg_Core_OsCore0 =
{
  /* .Core                 = */
  {
    /* .Status               = */ OS_CORE_CASTSTATUS_COREASRSTATUS_2_CORESTATUS(OsCfg_Core_OsCore0_Status_Dyn),
    /* .HwConfig             = */ &OsCfg_Hal_Core_OsCore0,
    /* .InterruptSourceRefs  = */ OsCfg_Hal_Core_OsCore0_InterruptSourceRefs,
    /* .InterruptSourceCount = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_INTERRUPTSOURCEREFS,
    /* .Id                   = */ OS_CORE_ID_0,
    /* .Trace                = */ &OsCfg_Trace_OsCore0_Dyn,
    /* .IsAsrCore            = */ TRUE,
    /* .IsAutostart          = */ TRUE,
    /* .IsMasterStartAllowed = */ FALSE,
    /* .HasPrivilegedHardwareAccess = */ TRUE
  },
  /* .Dyn                  = */ &OsCfg_Core_OsCore0_Dyn,
  /* .Scheduler            = */ &OsCfg_Scheduler_OsCore0,
  /* .IdleTask             = */ &OsCfg_Task_IdleTask_OsCore0,
  /* .KernelApp            = */ &OsCfg_App_SystemApplication_OsCore0,
  /* .KernelStack          = */ &OsCfg_Stack_OsCore0_Kernel,
  /* .PreStartTask         = */ NULL_PTR,
  /* .PreStartTaskCallback = */ NULL_PTR,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ &OsCfg_Hook_ShutdownHook_OsCore0,
  /* .ErrorHookRef         = */ &OsCfg_Hook_ErrorHook_OsCore0,
  /* .ProtectionHookRef    = */ &OsCfg_Hook_ProtectionHook_OsCore0,
  /* .InitHookRef          = */ &OsCfg_Hook_Os_CoreInitHook_OsCore0,
  /* .HookRefs             = */ OsCfg_Core_OsCore0_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_HOOKS,
  /* .AppRefs              = */ OsCfg_Core_OsCore0_AppRefs,
  /* .AppCount             = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_APPS,
  /* .ResourceRefs         = */ OsCfg_Core_OsCore0_ResourceRefs,
  /* .ResourceCount        = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_RESOURCES,
  /* .HwConfig             = */ &OsCfg_Hal_CoreAsr_OsCore0,
  /* .MemoryProtection     = */ &OsCfg_Mp_OsCore0,
  /* .TimingProtection     = */ NULL_PTR,
  /* .StackRefs            = */ OsCfg_Core_OsCore0_StackRefs,
  /* .StackCount           = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_STACKS,
  /* .CoreIdx              = */ OS_COREASRCOREIDX_0,
  /* .XSignal              = */ NULL_PTR,
  /* .IocRefs              = */ OsCfg_Core_OsCore0_IocRefs,
  /* .IocCount             = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_IOCS,
  /* .Barrier              = */ &OsCfg_Barrier_OsCore0,
  /* .BarrierRefs          = */ OsCfg_Core_OsCore0_BarrierRefs,
  /* .BarrierCount         = */ (Os_ObjIdxType)OS_CFG_NUM_BARRIERS,
  /* .ThreadClass          = */ &OsCfg_Core_OsCore0_ThreadClass,
  /* .IsrRefs              = */ OsCfg_Core_OsCore0_IsrRefs,
  /* .IsrCount             = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_ISRS
}
;

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for system spinlocks. */
OS_LOCAL CONST(Os_SpinlockConfigRefType, OS_CONST) OsCfg_SystemSpinlockRefs[OS_CFG_NUM_SYSTEM_SPINLOCKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core boot barriers. */
CONSTP2VAR(Os_CoreBootBarrierType, AUTOMATIC, OS_CONST) OsCfg_CoreBootBarrierRefs[OS_COREID_COUNT + 1u] =               /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */  
{
  &OsCfg_Core_OsCore0_BootBarrier_Dyn,
  NULL_PTR
};

/*! System configuration data. */
CONST(Os_SystemConfigType, OS_CONST) OsCfg_System =
{
  /* .VersionInfo      = */
  {
    /* .vendorID         = */ OS_VENDOR_ID,
    /* .moduleID         = */ OS_MODULE_ID,
    /* .sw_major_version = */ OS_SW_MAJOR_VERSION,
    /* .sw_minor_version = */ OS_SW_MINOR_VERSION,
    /* .sw_patch_version = */ OS_SW_PATCH_VERSION
  },
  /* .NumberOfAsrCores = */ OS_COREASRCOREIDX_COUNT,
  /* .SpinlockRefs     = */ OsCfg_SystemSpinlockRefs,
  /* .SpinlockCount    = */ (Os_ObjIdxType)OS_CFG_NUM_SYSTEM_SPINLOCKS,
  /* .HwConfig         = */ &OsCfg_Hal_System,
  /* .MemoryProtection = */ &OsCfg_Mp_SystemMpu,
  /* .InterruptSourceRefs  = */ OsCfg_Hal_System_InterruptSourceRefs,
  /* .InterruptSourceCount = */ (Os_ObjIdxType)OS_CFG_NUM_SYSTEM_INTERRUPTSOURCEREFS,
  /* .Core2Thread      = */ &OsCfg_Hal_Core2Thread
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
 *  END OF FILE: Os_Core_Lcfg.c
 *********************************************************************************************************************/

