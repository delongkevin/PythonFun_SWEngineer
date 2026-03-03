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
 *              File: Os_Hal_Context_Lcfg.c
 *   Generation Time: 2025-08-06 18:59:40
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_CONTEXT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Context.h"

/* Os kernel module dependencies */
#include "OsInt.h"
#include "Os_Core.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

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

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn;
/*! HAL dynamic hook FPU context data: Os_CoreInitHook_OsCore0 */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_Os_CoreInitHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ShutdownHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ShutdownHook_OsCore0_Dyn;
/*! HAL dynamic hook FPU context data: ShutdownHook_OsCore0 */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_ShutdownHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore0_Dyn;
/*! HAL dynamic hook FPU context data: ErrorHook_OsCore0 */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_ErrorHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ProtectionHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ProtectionHook_OsCore0_Dyn;
/*! HAL dynamic hook FPU context data: ProtectionHook_OsCore0 */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_ProtectionHook_OsCore0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn;

/*! HAL dynamic ISR2 level context data: Level4 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn;

/*! HAL dynamic ISR2 level context data: Level5 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level5_Dyn;

/*! HAL dynamic ISR2 level context data: Level6 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn;

/*! HAL dynamic ISR2 level context data: Level7 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn;

/*! HAL dynamic ISR2 level context data: Level8 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level8_Dyn;

/*! HAL dynamic ISR2 level context data: Level9 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn;

/*! HAL dynamic ISR2 level context data: Level10 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn;

/*! HAL dynamic task context data: BootAppOsTask */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_BootAppOsTask_Dyn;
/*! HAL dynamic task FPU context data: BootAppOsTask */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_BootAppOsTask_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore0_Dyn;

/*! HAL dynamic task context data: QM_ComTask_10ms */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_ComTask_10ms_Dyn;
/*! HAL dynamic task FPU context data: QM_ComTask_10ms */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_ComTask_10ms_Dyn;

/*! HAL dynamic task context data: QM_ComTask_5ms */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_ComTask_5ms_Dyn;
/*! HAL dynamic task FPU context data: QM_ComTask_5ms */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_ComTask_5ms_Dyn;

/*! HAL dynamic task context data: QM_DiagTask_10ms */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_DiagTask_10ms_Dyn;
/*! HAL dynamic task FPU context data: QM_DiagTask_10ms */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_DiagTask_10ms_Dyn;

/*! HAL dynamic task context data: QM_MemTask_10ms */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_MemTask_10ms_Dyn;
/*! HAL dynamic task FPU context data: QM_MemTask_10ms */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_MemTask_10ms_Dyn;

/*! HAL dynamic task context data: QM_Task_00_10ms */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_Task_00_10ms_Dyn;
/*! HAL dynamic task FPU context data: QM_Task_00_10ms */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_Task_00_10ms_Dyn;

/*! HAL dynamic task context data: QM_Task_01_10ms */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_Task_01_10ms_Dyn;
/*! HAL dynamic task FPU context data: QM_Task_01_10ms */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_Task_01_10ms_Dyn;

/*! HAL dynamic task context data: QM_Task_200ms */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_Task_200ms_Dyn;
/*! HAL dynamic task FPU context data: QM_Task_200ms */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_Task_200ms_Dyn;

/*! HAL dynamic task context data: QM_Task_Init */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_Task_Init_Dyn;
/*! HAL dynamic task FPU context data: QM_Task_Init */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_Task_Init_Dyn;

/*! HAL dynamic task context data: Safety_Task_00_10ms */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Safety_Task_00_10ms_Dyn;
/*! HAL dynamic task FPU context data: Safety_Task_00_10ms */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_Safety_Task_00_10ms_Dyn;

/*! HAL dynamic task context data: Safety_Task_01_10ms */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Safety_Task_01_10ms_Dyn;
/*! HAL dynamic task FPU context data: Safety_Task_01_10ms */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_Safety_Task_01_10ms_Dyn;

/*! HAL dynamic task context data: Safety_Task_200ms */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Safety_Task_200ms_Dyn;
/*! HAL dynamic task FPU context data: Safety_Task_200ms */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_Safety_Task_200ms_Dyn;

/*! HAL dynamic task context data: Safety_Task_Init */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Safety_Task_Init_Dyn;
/*! HAL dynamic task FPU context data: Safety_Task_Init */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_Safety_Task_Init_Dyn;

/*! HAL dynamic task context data: Safety_WdgTask_10ms */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Safety_WdgTask_10ms_Dyn;
/*! HAL dynamic task FPU context data: Safety_WdgTask_10ms */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_Safety_WdgTask_10ms_Dyn;

/*! HAL dynamic task context data: SciServerHighOsTask */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SciServerHighOsTask_Dyn;
/*! HAL dynamic task FPU context data: SciServerHighOsTask */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_SciServerHighOsTask_Dyn;

/*! HAL dynamic task context data: SciServerLowOsTask */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SciServerLowOsTask_Dyn;
/*! HAL dynamic task FPU context data: SciServerLowOsTask */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_SciServerLowOsTask_Dyn;

/*! HAL dynamic task context data: ShutdownTask */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ShutdownTask_Dyn;
/*! HAL dynamic task FPU context data: ShutdownTask */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_ShutdownTask_Dyn;

/*! HAL dynamic task context data: StartUpTask */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_StartUpTask_Dyn;
/*! HAL dynamic task FPU context data: StartUpTask */
VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_StartUpTask_Dyn;

/*! HAL exception context data: OsCore0 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_ExceptionContext;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Init_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED,
  /* .IntLevel         = */ (uint32)128u,
  /* .Entry            = */ (uint32)&Os_HookWrapperOs_CoreInitHook,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Init_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL hook context configuration data: ShutdownHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ShutdownHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Shutdown_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_HookWrapperStatusHook,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Shutdown_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL hook context configuration data: ErrorHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Error_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED,
  /* .IntLevel         = */ (uint32)128u,
  /* .Entry            = */ (uint32)&Os_HookWrapperStatusHook,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Error_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL hook context configuration data: ProtectionHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ProtectionHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Protection_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_HookWrapperProtectionHook,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)0, /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Protection_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: ADC0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_Adc_IrqUnit0,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: ADC1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_Adc_IrqUnit1,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: Can_30_McanIsr_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Can_30_McanIsr_0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_Can_30_McanIsr_0,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: Can_30_McanIsr_1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Can_30_McanIsr_1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_Can_30_McanIsr_1,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_Os_TimerPfrtIsr,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: I2c_IrqUnit0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_I2c_IrqUnit0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_I2c_IrqUnit0,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: I2c_IrqUnit1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_I2c_IrqUnit1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_I2c_IrqUnit1,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: IPC_mailbox1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IPC_mailbox1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_IPC_mailbox1,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: IPC_mailbox2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IPC_mailbox2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_IPC_mailbox2,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: MAIN_ESM0_ESM_INT_CFG_LVL_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MAIN_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: MAIN_ESM0_ESM_INT_HI_LVL_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MAIN_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: MAIN_ESM0_ESM_INT_LOW_LVL_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MAIN_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: MCU_ESM0_ESM_INT_CFG_LVL_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MCU_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: MCU_ESM0_ESM_INT_HI_LVL_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MCU_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_MCU_ESM0_ESM_INT_HI_LVL_0,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: MCU_ESM0_ESM_INT_LOW_LVL_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MCU_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SciServer_OsIsr_UserMsgHwiFxn1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SciServer_OsIsr_UserMsgHwiFxn1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SciServer_OsIsr_UserMsgHwiFxn1,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SciServer_OsIsr_UserMsgHwiFxn2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SciServer_OsIsr_UserMsgHwiFxn2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SciServer_OsIsr_UserMsgHwiFxn2,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SciServer_OsIsr_UserMsgHwiFxn3 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SciServer_OsIsr_UserMsgHwiFxn3 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SciServer_OsIsr_UserMsgHwiFxn3,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: SciServer_OsIsr_UserMsgHwiFxn4 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SciServer_OsIsr_UserMsgHwiFxn4 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_SciServer_OsIsr_UserMsgHwiFxn4,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: WKUP_ESM0_ESM_INT_CFG_LVL_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_WKUP_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: WKUP_ESM0_ESM_INT_HI_LVL_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_WKUP_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: WKUP_ESM0_ESM_INT_LOW_LVL_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_WKUP_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL ISR2 context configuration data: vHsmResponseIsr */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_vHsmResponseIsr =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ ,
  /* .IntLevel         = */ (uint32)192u,
  /* .Entry            = */ (uint32)&Os_Isr_vHsmResponseIsr,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: BootAppOsTask */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BootAppOsTask =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_BootAppOsTask_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_BootAppOsTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_BootAppOsTask_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(12u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: IdleTask_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Os_IdleTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: QM_ComTask_10ms */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_ComTask_10ms =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_QM_ComTask_10ms_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_User,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_QM_ComTask_10ms,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_QM_ComTask_10ms_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(12u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: QM_ComTask_5ms */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_ComTask_5ms =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_QM_ComTask_5ms_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_User,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_QM_ComTask_5ms,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_QM_ComTask_5ms_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: QM_DiagTask_10ms */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_DiagTask_10ms =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_QM_DiagTask_10ms_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_User,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_QM_DiagTask_10ms,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_QM_DiagTask_10ms_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(12u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: QM_MemTask_10ms */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_MemTask_10ms =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_QM_MemTask_10ms_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_User,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_QM_MemTask_10ms,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_QM_MemTask_10ms_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: QM_Task_00_10ms */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_Task_00_10ms =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio54_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_User,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_QM_Task_00_10ms,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio54_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(12u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: QM_Task_01_10ms */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_Task_01_10ms =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio50_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_User,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_QM_Task_01_10ms,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio50_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(14u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: QM_Task_200ms */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_Task_200ms =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_QM_Task_200ms_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_User,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_QM_Task_200ms,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_QM_Task_200ms_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(11u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: QM_Task_Init */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_Task_Init =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio88_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_User,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_QM_Task_Init,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio88_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(11u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: Safety_Task_00_10ms */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Safety_Task_00_10ms =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio79_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_User,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Safety_Task_00_10ms,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio79_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(13u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: Safety_Task_01_10ms */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Safety_Task_01_10ms =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio78_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_User,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Safety_Task_01_10ms,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio78_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(15u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: Safety_Task_200ms */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Safety_Task_200ms =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Safety_Task_200ms_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_User,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Safety_Task_200ms,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_Safety_Task_200ms_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: Safety_Task_Init */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Safety_Task_Init =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio90_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_User,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Safety_Task_Init,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio90_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(13u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: Safety_WdgTask_10ms */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Safety_WdgTask_10ms =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Safety_WdgTask_10ms_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_User,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Safety_WdgTask_10ms,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_Safety_WdgTask_10ms_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(12u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: SciServerHighOsTask */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SciServerHighOsTask =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_SciServerHighOsTask_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_SciServerHighOsTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_SciServerHighOsTask_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(12u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: SciServerLowOsTask */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SciServerLowOsTask =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_SciServerLowOsTask_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_SciServerLowOsTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_SciServerLowOsTask_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(12u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: ShutdownTask */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ShutdownTask =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio100_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_ShutdownTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio100_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(11u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL task context configuration data: StartUpTask */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_StartUpTask =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio100_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Psr              = */ (uint32)Os_Hal_ProcessorMode_System,
  /* .IntLevel         = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_StartUpTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio100_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(11u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

/*! HAL kernel stack configuration data: OsCore0_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore0_Kernel =
{
  /* .StackRegionEnd   = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn)+1),  /* OsCore0_Kernel */   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackRegionSize  = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(10u) | OS_HAL_MP_REGION_SIZE_ENABLE

}
;

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for HAL exception context. */
CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1u] =
{
  &OsCfg_Hal_Context_OsCore0_ExceptionContext,
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
 *  END OF FILE: Os_Hal_Context_Lcfg.c
 *********************************************************************************************************************/
