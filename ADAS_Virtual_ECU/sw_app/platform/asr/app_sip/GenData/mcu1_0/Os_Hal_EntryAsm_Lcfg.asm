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
 *              File: Os_Hal_EntryAsm_Lcfg.asm
 *   Generation Time: 2024-02-13 13:07:49
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Os_Cfg.h"
#if defined(OS_CFG_COMPILER_IAR)
# include "Os_Hal_Entry_IAR.inc"
#elif defined(OS_CFG_COMPILER_ARM6) || defined(OS_CFG_COMPILER_ARM)
# include "Os_Hal_Entry_ARM6.inc"
#else
# include "Os_Hal_Entry.inc"
#endif

/***********************************************************************************************************************
 *  DECLARATIONS
 **********************************************************************************************************************/


  OS_HAL_ASM_ARM_CODE
  OS_HAL_ASM_CODE_SECTION(OS_CODE)

  OS_HAL_ASM_IMPORT(Os_Hal_SysCallHandler_Jacinto7)            
  OS_HAL_ASM_IMPORT(Os_Hal_MemFault_PrefetchAbort)            
  OS_HAL_ASM_IMPORT(Os_Hal_MemFault_DataAbort)            

/***********************************************************************************************************************
 *  Exception tables
 **********************************************************************************************************************/

  /* ----------------------------------------------------------------------------------
   *  Exception Table - OsCore0 - Logical core 0 - Physical core 0
   * --------------------------------------------------------------------------------- */

  OS_HAL_ASM_CODE_SECTION(OS_CODE)
  
  /* Wrappers for OS internal interrupt handlers */

  OS_HAL_ASM_EXPORT(Os_Hal_IrqHandler_Jacinto7_Mcu_Core0)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_IrqHandler_Jacinto7_Mcu_Core0)
  Os_Hal_IrqInterruptEntry_Jacinto7_Mcu
  OS_HAL_ASM_FUNCTION_END(Os_Hal_IrqHandler_Jacinto7_Mcu_Core0)

  OS_HAL_ASM_EXPORT(Os_Hal_FiqHandler_Jacinto7_Mcu_Core0)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_FiqHandler_Jacinto7_Mcu_Core0)
  Os_Hal_FiqInterruptEntry_Jacinto7_Mcu
  OS_HAL_ASM_FUNCTION_END(Os_Hal_FiqHandler_Jacinto7_Mcu_Core0)

  /* Entry symbol declaration */

  OS_HAL_ASM_IMPORT(_c_int00)
  
  /* Exception Table - OsCore0 - Logical core 0 - Physical core 0 */

  OS_HAL_ASM_CODE_SECTION(OS_EXCVEC_CORE0_CODE)

  OS_HAL_ASM_EXPORT(OsCfg_Hal_Core_OsCore0_ExceptionTable)
OS_HAL_ASM_DEFINE_LABEL(OsCfg_Hal_Core_OsCore0_ExceptionTable)
  ldr pc,[pc,#0x18] /* Exception 0: Reset */
  ldr pc,[pc,#0x18] /* Exception 1: Undefined Instruction */
  ldr pc,[pc,#0x18] /* Exception 2: SVCall */
  ldr pc,[pc,#0x18] /* Exception 3: Abort Prefetch */
  ldr pc,[pc,#0x18] /* Exception 4: Abort Data */
  ldr pc,[pc,#0x18] /* Exception 5: Reserved */
  ldr pc,[pc,#0x18] /* Exception 6: IRQ */
  ldr pc,[pc,#0x18] /* Exception 7: FIQ */

OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_0_Address)
  OS_HAL_ASM_DEFINE_WORD(_c_int00)
OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_1_Address)
  OS_HAL_ASM_DEFINE_WORD(Os_Hal_UndefinedInstructionExceptionEntry_WithMemoryProtection)
OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_2_Address)
  OS_HAL_ASM_DEFINE_WORD(Os_Hal_SysCallHandler_Jacinto7)
OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_3_Address)
  OS_HAL_ASM_DEFINE_WORD(Os_Hal_MemFault_PrefetchAbort)
OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_4_Address)
  OS_HAL_ASM_DEFINE_WORD(Os_Hal_MemFault_DataAbort)
OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_5_Address)
  OS_HAL_ASM_DEFINE_WORD(Os_Hal_UnhandledExceptionEntry_WithMemoryProtection)
OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_6_Address)
  OS_HAL_ASM_DEFINE_WORD(Os_Hal_IrqHandler_Jacinto7_Mcu_Core0)
OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_7_Address)
  OS_HAL_ASM_DEFINE_WORD(Os_Hal_FiqHandler_Jacinto7_Mcu_Core0)


/***********************************************************************************************************************
 * Interrupt wrappers
 **********************************************************************************************************************/
 
   
  OS_HAL_ASM_CODE_SECTION(OS_INTVEC_CORE0_CODE)

  /* Definitions of the IRQ wrappers on OsCore0 */


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_0)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_Can_30_McanIsr_0)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_0)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_Can_30_McanIsr_0
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_0)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_2)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_Can_30_McanIsr_1)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_2)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_Can_30_McanIsr_1
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_2)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_6)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_ADC0)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_6)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_ADC0
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_6)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_7)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_ADC1)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_7)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_ADC1
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_7)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_18)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_I2c_IrqUnit0)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_18)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_I2c_IrqUnit0
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_18)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_36)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_36)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_36)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_37)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_37)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_37)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_39)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_CounterIsr_SystemTimer)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_39)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_CounterIsr_SystemTimer
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_39)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_44)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_vHsmResponseIsr)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_44)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_vHsmResponseIsr
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_44)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_47)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_47)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_47)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_48)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_48)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_48)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_49)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_MCU_ESM0_ESM_INT_HI_LVL_0)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_49)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MCU_ESM0_ESM_INT_HI_LVL_0
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_49)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_53)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_53)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_53)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_70)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn1)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_70)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn1
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_70)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_71)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn2)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_71)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn2
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_71)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_72)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn3)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_72)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn3
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_72)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_73)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn4)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_73)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn4
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_73)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_78)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_78)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_78)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_79)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_79)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_79)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_96)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_I2c_IrqUnit1)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_96)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_I2c_IrqUnit1
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_96)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_98)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_98)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_98)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_99)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_99)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_99)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_100)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_100)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_100)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_140)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_140)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_140)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_141)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_141)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_141)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_142)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_142)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_142)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_290)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_290)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_290)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_291)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_291)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_291)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_295)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_295)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_295)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_296)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_296)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_296)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_297)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_297)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_297)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_298)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_298)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_298)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_299)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_299)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_299)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_300)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_300)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_300)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_304)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_304)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_304)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_305)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_305)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_305)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_306)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_306)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_306)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_307)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_307)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_307)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_308)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_308)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_308)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_309)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_309)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_309)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_310)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_310)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_310)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_312)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_312)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_312)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_313)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_313)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_313)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_314)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_314)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_314)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_317)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_317)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_317)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_376)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_IPC_mailbox1)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_376)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_IPC_mailbox1
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_376)


  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_377)
  OS_HAL_ASM_IMPORT(OsCfg_Isr_IPC_mailbox2)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_377)
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_IPC_mailbox2
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_377)


  /* Definitions of the unhandled IRQ wrappers on OsCore0 */

  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_1)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_1)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 1
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_1)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_3)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_3)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 3
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_3)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_4)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_4)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 4
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_4)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_5)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_5)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 5
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_5)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_8)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_8)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 8
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_8)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_9)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_9)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 9
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_9)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_10)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_10)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 10
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_10)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_11)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_11)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 11
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_11)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_12)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_12)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 12
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_12)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_13)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_13)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 13
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_13)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_14)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_14)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 14
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_14)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_15)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_15)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 15
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_15)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_16)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_16)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 16
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_16)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_17)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_17)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 17
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_17)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_19)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_19)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 19
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_19)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_20)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_20)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 20
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_20)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_21)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_21)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 21
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_21)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_22)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_22)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 22
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_22)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_23)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_23)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 23
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_23)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_24)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_24)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 24
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_24)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_25)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_25)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 25
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_25)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_26)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_26)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 26
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_26)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_27)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_27)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 27
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_27)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_28)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_28)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 28
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_28)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_29)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_29)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 29
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_29)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_30)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_30)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 30
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_30)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_31)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_31)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 31
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_31)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_32)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_32)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 32
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_32)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_33)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_33)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 33
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_33)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_34)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_34)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 34
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_34)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_35)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_35)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 35
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_35)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_38)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_38)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 38
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_38)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_40)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_40)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 40
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_40)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_41)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_41)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 41
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_41)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_42)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_42)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 42
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_42)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_43)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_43)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 43
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_43)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_45)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_45)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 45
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_45)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_46)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_46)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 46
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_46)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_50)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_50)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 50
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_50)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_51)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_51)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 51
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_51)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_52)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_52)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 52
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_52)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_54)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_54)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 54
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_54)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_55)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_55)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 55
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_55)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_56)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_56)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 56
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_56)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_57)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_57)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 57
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_57)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_58)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_58)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 58
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_58)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_59)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_59)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 59
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_59)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_60)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_60)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 60
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_60)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_61)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_61)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 61
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_61)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_62)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_62)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 62
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_62)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_63)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_63)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 63
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_63)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_64)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_64)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 64
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_64)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_65)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_65)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 65
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_65)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_66)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_66)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 66
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_66)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_67)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_67)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 67
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_67)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_68)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_68)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 68
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_68)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_69)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_69)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 69
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_69)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_74)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_74)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 74
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_74)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_75)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_75)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 75
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_75)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_76)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_76)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 76
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_76)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_77)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_77)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 77
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_77)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_80)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_80)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 80
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_80)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_81)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_81)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 81
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_81)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_82)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_82)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 82
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_82)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_83)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_83)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 83
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_83)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_84)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_84)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 84
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_84)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_85)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_85)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 85
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_85)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_86)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_86)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 86
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_86)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_87)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_87)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 87
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_87)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_88)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_88)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 88
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_88)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_89)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_89)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 89
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_89)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_90)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_90)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 90
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_90)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_91)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_91)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 91
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_91)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_92)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_92)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 92
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_92)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_93)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_93)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 93
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_93)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_94)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_94)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 94
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_94)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_95)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_95)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 95
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_95)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_97)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_97)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 97
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_97)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_101)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_101)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 101
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_101)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_102)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_102)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 102
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_102)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_103)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_103)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 103
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_103)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_104)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_104)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 104
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_104)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_105)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_105)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 105
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_105)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_106)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_106)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 106
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_106)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_107)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_107)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 107
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_107)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_108)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_108)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 108
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_108)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_109)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_109)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 109
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_109)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_110)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_110)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 110
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_110)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_111)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_111)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 111
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_111)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_112)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_112)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 112
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_112)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_113)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_113)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 113
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_113)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_114)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_114)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 114
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_114)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_115)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_115)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 115
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_115)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_116)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_116)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 116
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_116)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_117)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_117)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 117
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_117)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_118)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_118)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 118
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_118)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_119)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_119)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 119
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_119)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_120)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_120)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 120
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_120)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_121)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_121)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 121
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_121)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_122)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_122)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 122
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_122)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_123)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_123)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 123
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_123)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_124)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_124)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 124
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_124)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_125)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_125)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 125
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_125)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_126)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_126)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 126
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_126)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_127)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_127)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 127
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_127)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_128)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_128)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 128
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_128)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_129)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_129)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 129
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_129)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_130)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_130)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 130
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_130)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_131)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_131)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 131
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_131)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_132)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_132)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 132
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_132)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_133)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_133)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 133
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_133)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_134)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_134)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 134
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_134)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_135)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_135)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 135
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_135)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_136)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_136)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 136
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_136)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_137)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_137)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 137
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_137)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_138)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_138)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 138
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_138)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_139)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_139)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 139
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_139)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_143)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_143)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 143
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_143)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_144)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_144)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 144
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_144)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_145)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_145)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 145
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_145)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_146)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_146)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 146
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_146)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_147)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_147)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 147
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_147)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_148)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_148)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 148
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_148)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_149)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_149)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 149
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_149)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_150)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_150)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 150
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_150)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_151)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_151)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 151
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_151)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_152)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_152)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 152
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_152)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_153)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_153)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 153
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_153)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_154)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_154)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 154
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_154)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_155)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_155)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 155
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_155)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_156)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_156)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 156
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_156)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_157)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_157)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 157
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_157)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_158)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_158)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 158
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_158)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_159)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_159)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 159
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_159)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_160)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_160)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 160
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_160)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_161)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_161)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 161
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_161)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_162)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_162)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 162
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_162)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_163)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_163)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 163
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_163)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_164)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_164)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 164
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_164)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_165)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_165)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 165
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_165)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_166)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_166)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 166
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_166)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_167)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_167)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 167
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_167)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_168)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_168)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 168
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_168)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_169)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_169)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 169
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_169)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_170)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_170)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 170
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_170)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_171)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_171)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 171
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_171)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_172)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_172)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 172
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_172)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_173)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_173)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 173
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_173)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_174)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_174)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 174
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_174)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_175)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_175)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 175
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_175)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_176)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_176)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 176
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_176)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_177)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_177)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 177
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_177)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_178)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_178)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 178
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_178)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_179)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_179)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 179
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_179)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_180)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_180)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 180
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_180)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_181)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_181)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 181
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_181)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_182)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_182)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 182
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_182)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_183)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_183)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 183
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_183)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_184)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_184)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 184
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_184)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_185)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_185)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 185
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_185)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_186)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_186)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 186
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_186)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_187)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_187)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 187
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_187)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_188)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_188)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 188
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_188)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_189)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_189)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 189
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_189)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_190)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_190)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 190
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_190)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_191)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_191)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 191
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_191)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_192)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_192)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 192
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_192)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_193)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_193)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 193
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_193)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_194)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_194)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 194
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_194)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_195)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_195)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 195
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_195)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_196)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_196)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 196
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_196)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_197)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_197)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 197
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_197)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_198)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_198)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 198
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_198)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_199)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_199)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 199
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_199)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_200)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_200)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 200
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_200)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_201)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_201)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 201
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_201)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_202)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_202)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 202
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_202)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_203)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_203)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 203
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_203)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_204)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_204)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 204
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_204)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_205)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_205)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 205
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_205)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_206)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_206)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 206
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_206)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_207)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_207)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 207
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_207)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_208)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_208)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 208
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_208)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_209)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_209)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 209
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_209)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_210)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_210)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 210
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_210)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_211)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_211)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 211
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_211)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_212)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_212)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 212
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_212)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_213)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_213)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 213
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_213)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_214)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_214)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 214
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_214)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_215)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_215)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 215
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_215)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_216)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_216)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 216
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_216)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_217)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_217)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 217
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_217)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_218)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_218)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 218
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_218)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_219)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_219)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 219
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_219)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_220)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_220)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 220
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_220)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_221)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_221)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 221
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_221)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_222)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_222)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 222
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_222)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_223)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_223)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 223
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_223)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_224)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_224)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 224
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_224)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_225)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_225)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 225
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_225)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_226)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_226)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 226
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_226)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_227)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_227)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 227
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_227)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_228)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_228)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 228
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_228)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_229)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_229)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 229
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_229)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_230)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_230)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 230
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_230)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_231)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_231)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 231
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_231)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_232)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_232)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 232
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_232)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_233)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_233)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 233
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_233)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_234)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_234)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 234
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_234)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_235)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_235)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 235
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_235)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_236)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_236)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 236
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_236)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_237)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_237)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 237
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_237)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_238)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_238)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 238
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_238)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_239)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_239)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 239
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_239)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_240)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_240)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 240
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_240)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_241)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_241)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 241
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_241)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_242)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_242)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 242
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_242)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_243)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_243)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 243
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_243)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_244)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_244)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 244
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_244)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_245)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_245)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 245
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_245)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_246)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_246)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 246
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_246)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_247)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_247)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 247
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_247)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_248)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_248)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 248
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_248)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_249)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_249)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 249
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_249)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_250)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_250)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 250
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_250)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_251)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_251)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 251
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_251)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_252)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_252)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 252
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_252)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_253)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_253)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 253
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_253)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_254)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_254)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 254
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_254)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_255)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_255)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 255
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_255)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_256)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_256)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 256
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_256)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_257)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_257)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 257
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_257)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_258)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_258)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 258
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_258)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_259)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_259)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 259
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_259)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_260)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_260)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 260
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_260)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_261)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_261)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 261
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_261)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_262)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_262)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 262
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_262)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_263)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_263)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 263
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_263)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_264)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_264)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 264
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_264)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_265)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_265)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 265
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_265)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_266)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_266)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 266
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_266)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_267)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_267)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 267
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_267)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_268)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_268)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 268
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_268)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_269)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_269)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 269
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_269)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_270)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_270)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 270
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_270)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_271)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_271)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 271
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_271)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_272)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_272)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 272
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_272)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_273)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_273)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 273
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_273)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_274)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_274)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 274
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_274)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_275)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_275)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 275
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_275)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_276)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_276)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 276
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_276)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_277)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_277)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 277
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_277)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_278)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_278)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 278
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_278)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_279)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_279)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 279
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_279)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_280)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_280)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 280
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_280)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_281)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_281)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 281
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_281)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_282)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_282)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 282
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_282)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_283)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_283)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 283
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_283)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_284)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_284)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 284
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_284)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_285)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_285)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 285
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_285)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_286)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_286)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 286
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_286)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_287)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_287)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 287
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_287)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_288)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_288)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 288
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_288)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_289)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_289)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 289
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_289)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_292)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_292)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 292
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_292)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_293)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_293)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 293
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_293)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_294)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_294)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 294
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_294)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_301)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_301)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 301
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_301)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_302)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_302)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 302
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_302)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_303)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_303)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 303
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_303)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_311)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_311)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 311
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_311)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_315)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_315)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 315
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_315)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_316)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_316)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 316
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_316)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_318)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_318)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 318
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_318)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_319)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_319)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 319
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_319)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_320)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_320)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 320
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_320)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_321)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_321)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 321
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_321)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_322)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_322)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 322
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_322)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_323)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_323)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 323
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_323)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_324)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_324)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 324
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_324)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_325)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_325)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 325
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_325)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_326)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_326)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 326
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_326)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_327)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_327)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 327
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_327)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_328)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_328)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 328
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_328)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_329)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_329)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 329
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_329)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_330)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_330)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 330
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_330)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_331)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_331)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 331
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_331)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_332)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_332)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 332
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_332)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_333)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_333)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 333
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_333)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_334)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_334)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 334
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_334)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_335)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_335)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 335
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_335)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_336)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_336)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 336
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_336)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_337)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_337)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 337
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_337)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_338)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_338)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 338
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_338)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_339)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_339)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 339
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_339)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_340)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_340)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 340
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_340)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_341)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_341)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 341
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_341)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_342)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_342)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 342
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_342)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_343)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_343)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 343
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_343)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_344)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_344)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 344
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_344)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_345)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_345)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 345
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_345)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_346)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_346)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 346
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_346)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_347)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_347)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 347
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_347)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_348)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_348)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 348
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_348)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_349)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_349)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 349
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_349)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_350)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_350)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 350
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_350)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_351)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_351)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 351
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_351)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_352)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_352)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 352
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_352)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_353)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_353)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 353
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_353)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_354)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_354)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 354
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_354)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_355)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_355)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 355
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_355)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_356)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_356)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 356
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_356)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_357)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_357)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 357
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_357)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_358)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_358)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 358
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_358)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_359)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_359)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 359
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_359)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_360)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_360)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 360
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_360)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_361)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_361)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 361
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_361)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_362)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_362)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 362
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_362)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_363)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_363)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 363
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_363)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_364)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_364)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 364
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_364)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_365)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_365)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 365
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_365)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_366)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_366)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 366
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_366)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_367)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_367)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 367
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_367)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_368)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_368)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 368
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_368)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_369)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_369)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 369
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_369)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_370)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_370)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 370
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_370)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_371)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_371)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 371
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_371)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_372)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_372)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 372
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_372)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_373)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_373)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 373
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_373)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_374)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_374)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 374
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_374)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_375)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_375)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 375
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_375)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_378)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_378)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 378
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_378)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_379)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_379)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 379
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_379)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_380)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_380)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 380
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_380)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_381)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_381)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 381
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_381)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_382)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_382)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 382
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_382)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_UnhandledInterrupt_383)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_UnhandledInterrupt_383)
  Os_Hal_UnhandledInterruptEntry_Jacinto7 383
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_UnhandledInterrupt_383)




  OS_HAL_ASM_MODULE_END


