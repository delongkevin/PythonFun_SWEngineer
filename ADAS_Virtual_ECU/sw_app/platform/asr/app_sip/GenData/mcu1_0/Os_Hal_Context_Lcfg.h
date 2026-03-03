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
 *              File: Os_Hal_Context_Lcfg.h
 *   Generation Time: 2025-01-22 11:22:08
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_CONTEXT_LCFG_H
# define OS_HAL_CONTEXT_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Context_Types.h"

/* Os kernel module dependencies */
# include "Os_Core_Cfg.h"

/* Os hal dependencies */
# include "Os_Hal_Os_Types.h"


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

# define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn;
/*! HAL dynamic hook FPU context data: Os_CoreInitHook_OsCore0 */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_Os_CoreInitHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ShutdownHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ShutdownHook_OsCore0_Dyn;
/*! HAL dynamic hook FPU context data: ShutdownHook_OsCore0 */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_ShutdownHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore0_Dyn;
/*! HAL dynamic hook FPU context data: ErrorHook_OsCore0 */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_ErrorHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ProtectionHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ProtectionHook_OsCore0_Dyn;
/*! HAL dynamic hook FPU context data: ProtectionHook_OsCore0 */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_ProtectionHook_OsCore0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn;

/*! HAL dynamic ISR2 level context data: Level4 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn;

/*! HAL dynamic ISR2 level context data: Level5 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level5_Dyn;

/*! HAL dynamic ISR2 level context data: Level6 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn;

/*! HAL dynamic ISR2 level context data: Level7 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn;

/*! HAL dynamic ISR2 level context data: Level8 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level8_Dyn;

/*! HAL dynamic ISR2 level context data: Level9 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level9_Dyn;

/*! HAL dynamic ISR2 level context data: Level10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level10_Dyn;

/*! HAL dynamic task context data: BootAppOsTask */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_BootAppOsTask_Dyn;
/*! HAL dynamic task FPU context data: BootAppOsTask */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_BootAppOsTask_Dyn;


/*! HAL dynamic task context data: IdleTask_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore0_Dyn;


/*! HAL dynamic task context data: QM_ComTask_10ms */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_ComTask_10ms_Dyn;
/*! HAL dynamic task FPU context data: QM_ComTask_10ms */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_ComTask_10ms_Dyn;


/*! HAL dynamic task context data: QM_ComTask_5ms */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_ComTask_5ms_Dyn;
/*! HAL dynamic task FPU context data: QM_ComTask_5ms */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_ComTask_5ms_Dyn;


/*! HAL dynamic task context data: QM_DiagTask_10ms */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_DiagTask_10ms_Dyn;
/*! HAL dynamic task FPU context data: QM_DiagTask_10ms */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_DiagTask_10ms_Dyn;


/*! HAL dynamic task context data: QM_MemTask_10ms */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_MemTask_10ms_Dyn;
/*! HAL dynamic task FPU context data: QM_MemTask_10ms */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_MemTask_10ms_Dyn;


/*! HAL dynamic task context data: QM_Task_00_10ms */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_Task_00_10ms_Dyn;
/*! HAL dynamic task FPU context data: QM_Task_00_10ms */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_Task_00_10ms_Dyn;


/*! HAL dynamic task context data: QM_Task_01_10ms */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_Task_01_10ms_Dyn;
/*! HAL dynamic task FPU context data: QM_Task_01_10ms */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_Task_01_10ms_Dyn;


/*! HAL dynamic task context data: QM_Task_200ms */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_Task_200ms_Dyn;
/*! HAL dynamic task FPU context data: QM_Task_200ms */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_Task_200ms_Dyn;


/*! HAL dynamic task context data: QM_Task_Init */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_QM_Task_Init_Dyn;
/*! HAL dynamic task FPU context data: QM_Task_Init */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_QM_Task_Init_Dyn;


/*! HAL dynamic task context data: Safety_Task_00_10ms */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Safety_Task_00_10ms_Dyn;
/*! HAL dynamic task FPU context data: Safety_Task_00_10ms */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_Safety_Task_00_10ms_Dyn;


/*! HAL dynamic task context data: Safety_Task_01_10ms */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Safety_Task_01_10ms_Dyn;
/*! HAL dynamic task FPU context data: Safety_Task_01_10ms */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_Safety_Task_01_10ms_Dyn;


/*! HAL dynamic task context data: Safety_Task_200ms */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Safety_Task_200ms_Dyn;
/*! HAL dynamic task FPU context data: Safety_Task_200ms */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_Safety_Task_200ms_Dyn;


/*! HAL dynamic task context data: Safety_Task_Init */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Safety_Task_Init_Dyn;
/*! HAL dynamic task FPU context data: Safety_Task_Init */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_Safety_Task_Init_Dyn;


/*! HAL dynamic task context data: Safety_WdgTask_10ms */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Safety_WdgTask_10ms_Dyn;
/*! HAL dynamic task FPU context data: Safety_WdgTask_10ms */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_Safety_WdgTask_10ms_Dyn;


/*! HAL dynamic task context data: SciServerHighOsTask */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SciServerHighOsTask_Dyn;
/*! HAL dynamic task FPU context data: SciServerHighOsTask */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_SciServerHighOsTask_Dyn;


/*! HAL dynamic task context data: SciServerLowOsTask */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SciServerLowOsTask_Dyn;
/*! HAL dynamic task FPU context data: SciServerLowOsTask */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_SciServerLowOsTask_Dyn;


/*! HAL dynamic task context data: ShutdownTask */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ShutdownTask_Dyn;
/*! HAL dynamic task FPU context data: ShutdownTask */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_ShutdownTask_Dyn;


/*! HAL dynamic task context data: StartUpTask */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_StartUpTask_Dyn;
/*! HAL dynamic task FPU context data: StartUpTask */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_StartUpTask_Dyn;


/*! HAL exception context data: OsCore0 */
extern VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_ExceptionContext;

# define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0;

/*! HAL hook context configuration data: ShutdownHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ShutdownHook_OsCore0;

/*! HAL hook context configuration data: ErrorHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore0;

/*! HAL hook context configuration data: ProtectionHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ProtectionHook_OsCore0;

/*! HAL ISR2 context configuration data: ADC0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC0;

/*! HAL ISR2 context configuration data: ADC1 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC1;

/*! HAL ISR2 context configuration data: Can_30_McanIsr_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Can_30_McanIsr_0;

/*! HAL ISR2 context configuration data: Can_30_McanIsr_1 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Can_30_McanIsr_1;

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer;

/*! HAL ISR2 context configuration data: I2c_IrqUnit0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_I2c_IrqUnit0;

/*! HAL ISR2 context configuration data: I2c_IrqUnit1 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_I2c_IrqUnit1;

/*! HAL ISR2 context configuration data: IPC_mailbox1 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IPC_mailbox1;

/*! HAL ISR2 context configuration data: IPC_mailbox2 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IPC_mailbox2;

/*! HAL ISR2 context configuration data: MAIN_ESM0_ESM_INT_CFG_LVL_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MAIN_ESM0_ESM_INT_CFG_LVL_0;

/*! HAL ISR2 context configuration data: MAIN_ESM0_ESM_INT_HI_LVL_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MAIN_ESM0_ESM_INT_HI_LVL_0;

/*! HAL ISR2 context configuration data: MAIN_ESM0_ESM_INT_LOW_LVL_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MAIN_ESM0_ESM_INT_LOW_LVL_0;

/*! HAL ISR2 context configuration data: MCU_ESM0_ESM_INT_CFG_LVL_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MCU_ESM0_ESM_INT_CFG_LVL_0;

/*! HAL ISR2 context configuration data: MCU_ESM0_ESM_INT_HI_LVL_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MCU_ESM0_ESM_INT_HI_LVL_0;

/*! HAL ISR2 context configuration data: MCU_ESM0_ESM_INT_LOW_LVL_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MCU_ESM0_ESM_INT_LOW_LVL_0;

/*! HAL ISR2 context configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78;

/*! HAL ISR2 context configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304;

/*! HAL ISR2 context configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305;

/*! HAL ISR2 context configuration data: SciServer_OsIsr_UserMsgHwiFxn1 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SciServer_OsIsr_UserMsgHwiFxn1;

/*! HAL ISR2 context configuration data: SciServer_OsIsr_UserMsgHwiFxn2 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SciServer_OsIsr_UserMsgHwiFxn2;

/*! HAL ISR2 context configuration data: SciServer_OsIsr_UserMsgHwiFxn3 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SciServer_OsIsr_UserMsgHwiFxn3;

/*! HAL ISR2 context configuration data: SciServer_OsIsr_UserMsgHwiFxn4 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SciServer_OsIsr_UserMsgHwiFxn4;

/*! HAL ISR2 context configuration data: WKUP_ESM0_ESM_INT_CFG_LVL_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_WKUP_ESM0_ESM_INT_CFG_LVL_0;

/*! HAL ISR2 context configuration data: WKUP_ESM0_ESM_INT_HI_LVL_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_WKUP_ESM0_ESM_INT_HI_LVL_0;

/*! HAL ISR2 context configuration data: WKUP_ESM0_ESM_INT_LOW_LVL_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_WKUP_ESM0_ESM_INT_LOW_LVL_0;

/*! HAL ISR2 context configuration data: vHsmResponseIsr */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_vHsmResponseIsr;

/*! HAL task context configuration data: BootAppOsTask */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BootAppOsTask;

/*! HAL task context configuration data: IdleTask_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore0;

/*! HAL task context configuration data: QM_ComTask_10ms */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_ComTask_10ms;

/*! HAL task context configuration data: QM_ComTask_5ms */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_ComTask_5ms;

/*! HAL task context configuration data: QM_DiagTask_10ms */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_DiagTask_10ms;

/*! HAL task context configuration data: QM_MemTask_10ms */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_MemTask_10ms;

/*! HAL task context configuration data: QM_Task_00_10ms */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_Task_00_10ms;

/*! HAL task context configuration data: QM_Task_01_10ms */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_Task_01_10ms;

/*! HAL task context configuration data: QM_Task_200ms */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_Task_200ms;

/*! HAL task context configuration data: QM_Task_Init */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_QM_Task_Init;

/*! HAL task context configuration data: Safety_Task_00_10ms */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Safety_Task_00_10ms;

/*! HAL task context configuration data: Safety_Task_01_10ms */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Safety_Task_01_10ms;

/*! HAL task context configuration data: Safety_Task_200ms */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Safety_Task_200ms;

/*! HAL task context configuration data: Safety_Task_Init */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Safety_Task_Init;

/*! HAL task context configuration data: Safety_WdgTask_10ms */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Safety_WdgTask_10ms;

/*! HAL task context configuration data: SciServerHighOsTask */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SciServerHighOsTask;

/*! HAL task context configuration data: SciServerLowOsTask */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SciServerLowOsTask;

/*! HAL task context configuration data: ShutdownTask */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ShutdownTask;

/*! HAL task context configuration data: StartUpTask */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_StartUpTask;

/*! HAL kernel stack configuration data: OsCore0_Kernel */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore0_Kernel;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for HAL exception context. */
extern CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1u];

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_CONTEXT_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_Lcfg.h
 *********************************************************************************************************************/
