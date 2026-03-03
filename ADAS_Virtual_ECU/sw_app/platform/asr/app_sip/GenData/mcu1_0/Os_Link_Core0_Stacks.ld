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
 *              File: Os_Link_Core0_Stacks.ld
 *   Generation Time: 2025-06-18 19:15:02
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  STACK SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_KERNEL_STACKS )
_OS_CORE0_STACKS_START = .;

/* Stack: OsCore0_Task_Prio78 (32768 Byte) */
  . = align(32768);
  _OS_STACK_OSCORE0_TASK_PRIO78_VAR_NOINIT_START = .;
  *(.OS_STACK_OSCORE0_TASK_PRIO78_VAR_NOINIT)
  _OS_STACK_OSCORE0_TASK_PRIO78_VAR_NOINIT_END = .-1;
  _OS_STACK_OSCORE0_TASK_PRIO78_VAR_NOINIT_LIMIT = .;

/* Stack: OsCore0_Task_Prio50 (16384 Byte) */
  . = align(16384);
  _OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_START = .;
  *(.OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT)
  _OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_END = .-1;
  _OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_LIMIT = .;

/* Stack: OsCore0_Task_Prio90 (8192 Byte) */
  . = align(8192);
  _OS_STACK_OSCORE0_TASK_PRIO90_VAR_NOINIT_START = .;
  *(.OS_STACK_OSCORE0_TASK_PRIO90_VAR_NOINIT)
  _OS_STACK_OSCORE0_TASK_PRIO90_VAR_NOINIT_END = .-1;
  _OS_STACK_OSCORE0_TASK_PRIO90_VAR_NOINIT_LIMIT = .;

/* Stack: OsCore0_Task_Prio79 (8192 Byte) */
  . = align(8192);
  _OS_STACK_OSCORE0_TASK_PRIO79_VAR_NOINIT_START = .;
  *(.OS_STACK_OSCORE0_TASK_PRIO79_VAR_NOINIT)
  _OS_STACK_OSCORE0_TASK_PRIO79_VAR_NOINIT_END = .-1;
  _OS_STACK_OSCORE0_TASK_PRIO79_VAR_NOINIT_LIMIT = .;

/* Stack: SciServerLowOsTask (4096 Byte) */
  . = align(4096);
  _OS_STACK_SCISERVERLOWOSTASK_VAR_NOINIT_START = .;
  *(.OS_STACK_SCISERVERLOWOSTASK_VAR_NOINIT)
  _OS_STACK_SCISERVERLOWOSTASK_VAR_NOINIT_END = .-1;
  _OS_STACK_SCISERVERLOWOSTASK_VAR_NOINIT_LIMIT = .;

/* Stack: SciServerHighOsTask (4096 Byte) */
  . = align(4096);
  _OS_STACK_SCISERVERHIGHOSTASK_VAR_NOINIT_START = .;
  *(.OS_STACK_SCISERVERHIGHOSTASK_VAR_NOINIT)
  _OS_STACK_SCISERVERHIGHOSTASK_VAR_NOINIT_END = .-1;
  _OS_STACK_SCISERVERHIGHOSTASK_VAR_NOINIT_LIMIT = .;

/* Stack: Safety_WdgTask_10ms (4096 Byte) */
  . = align(4096);
  _OS_STACK_SAFETY_WDGTASK_10MS_VAR_NOINIT_START = .;
  *(.OS_STACK_SAFETY_WDGTASK_10MS_VAR_NOINIT)
  _OS_STACK_SAFETY_WDGTASK_10MS_VAR_NOINIT_END = .-1;
  _OS_STACK_SAFETY_WDGTASK_10MS_VAR_NOINIT_LIMIT = .;

/* Stack: QM_DiagTask_10ms (4096 Byte) */
  . = align(4096);
  _OS_STACK_QM_DIAGTASK_10MS_VAR_NOINIT_START = .;
  *(.OS_STACK_QM_DIAGTASK_10MS_VAR_NOINIT)
  _OS_STACK_QM_DIAGTASK_10MS_VAR_NOINIT_END = .-1;
  _OS_STACK_QM_DIAGTASK_10MS_VAR_NOINIT_LIMIT = .;

/* Stack: QM_ComTask_10ms (4096 Byte) */
  . = align(4096);
  _OS_STACK_QM_COMTASK_10MS_VAR_NOINIT_START = .;
  *(.OS_STACK_QM_COMTASK_10MS_VAR_NOINIT)
  _OS_STACK_QM_COMTASK_10MS_VAR_NOINIT_END = .-1;
  _OS_STACK_QM_COMTASK_10MS_VAR_NOINIT_LIMIT = .;

/* Stack: OsCore0_Task_Prio54 (4096 Byte) */
  . = align(4096);
  _OS_STACK_OSCORE0_TASK_PRIO54_VAR_NOINIT_START = .;
  *(.OS_STACK_OSCORE0_TASK_PRIO54_VAR_NOINIT)
  _OS_STACK_OSCORE0_TASK_PRIO54_VAR_NOINIT_END = .-1;
  _OS_STACK_OSCORE0_TASK_PRIO54_VAR_NOINIT_LIMIT = .;

/* Stack: BootAppOsTask (4096 Byte) */
  . = align(4096);
  _OS_STACK_BOOTAPPOSTASK_VAR_NOINIT_START = .;
  *(.OS_STACK_BOOTAPPOSTASK_VAR_NOINIT)
  _OS_STACK_BOOTAPPOSTASK_VAR_NOINIT_END = .-1;
  _OS_STACK_BOOTAPPOSTASK_VAR_NOINIT_LIMIT = .;

/* Stack: QM_Task_200ms (2048 Byte) */
  . = align(2048);
  _OS_STACK_QM_TASK_200MS_VAR_NOINIT_START = .;
  *(.OS_STACK_QM_TASK_200MS_VAR_NOINIT)
  _OS_STACK_QM_TASK_200MS_VAR_NOINIT_END = .-1;
  _OS_STACK_QM_TASK_200MS_VAR_NOINIT_LIMIT = .;

/* Stack: OsCore0_Task_Prio88 (2048 Byte) */
  . = align(2048);
  _OS_STACK_OSCORE0_TASK_PRIO88_VAR_NOINIT_START = .;
  *(.OS_STACK_OSCORE0_TASK_PRIO88_VAR_NOINIT)
  _OS_STACK_OSCORE0_TASK_PRIO88_VAR_NOINIT_END = .-1;
  _OS_STACK_OSCORE0_TASK_PRIO88_VAR_NOINIT_LIMIT = .;

/* Stack: OsCore0_Task_Prio100 (2048 Byte) */
  . = align(2048);
  _OS_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT_START = .;
  *(.OS_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT)
  _OS_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT_END = .-1;
  _OS_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT_LIMIT = .;

/* Stack: Safety_Task_200ms (1024 Byte) */
  . = align(1024);
  _OS_STACK_SAFETY_TASK_200MS_VAR_NOINIT_START = .;
  *(.OS_STACK_SAFETY_TASK_200MS_VAR_NOINIT)
  _OS_STACK_SAFETY_TASK_200MS_VAR_NOINIT_END = .-1;
  _OS_STACK_SAFETY_TASK_200MS_VAR_NOINIT_LIMIT = .;

/* Stack: QM_MemTask_10ms (1024 Byte) */
  . = align(1024);
  _OS_STACK_QM_MEMTASK_10MS_VAR_NOINIT_START = .;
  *(.OS_STACK_QM_MEMTASK_10MS_VAR_NOINIT)
  _OS_STACK_QM_MEMTASK_10MS_VAR_NOINIT_END = .-1;
  _OS_STACK_QM_MEMTASK_10MS_VAR_NOINIT_LIMIT = .;

/* Stack: QM_ComTask_5ms (1024 Byte) */
  . = align(1024);
  _OS_STACK_QM_COMTASK_5MS_VAR_NOINIT_START = .;
  *(.OS_STACK_QM_COMTASK_5MS_VAR_NOINIT)
  _OS_STACK_QM_COMTASK_5MS_VAR_NOINIT_END = .-1;
  _OS_STACK_QM_COMTASK_5MS_VAR_NOINIT_LIMIT = .;

/* Stack: OsCore0_Task_Prio4294967295 (1024 Byte) */
  . = align(1024);
  _OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_START = .;
  *(.OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT)
  _OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_END = .-1;
  _OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_LIMIT = .;

/* Stack: OsCore0_Shutdown (1024 Byte) */
  . = align(1024);
  _OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_START = .;
  *(.OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT)
  _OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_END = .-1;
  _OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_LIMIT = .;

/* Stack: OsCore0_Protection (1024 Byte) */
  . = align(1024);
  _OS_STACK_OSCORE0_PROTECTION_VAR_NOINIT_START = .;
  *(.OS_STACK_OSCORE0_PROTECTION_VAR_NOINIT)
  _OS_STACK_OSCORE0_PROTECTION_VAR_NOINIT_END = .-1;
  _OS_STACK_OSCORE0_PROTECTION_VAR_NOINIT_LIMIT = .;

/* Stack: OsCore0_Kernel (1024 Byte) */
  . = align(1024);
  _OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_START = .;
  *(.OS_STACK_OSCORE0_KERNEL_VAR_NOINIT)
  _OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_END = .-1;
  _OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_LIMIT = .;

/* Stack: OsCore0_Isr_Core (1024 Byte) */
  . = align(1024);
  _OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_START = .;
  *(.OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT)
  _OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_END = .-1;
  _OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_LIMIT = .;

/* Stack: OsCore0_Init (1024 Byte) */
  . = align(1024);
  _OS_STACK_OSCORE0_INIT_VAR_NOINIT_START = .;
  *(.OS_STACK_OSCORE0_INIT_VAR_NOINIT)
  _OS_STACK_OSCORE0_INIT_VAR_NOINIT_END = .-1;
  _OS_STACK_OSCORE0_INIT_VAR_NOINIT_LIMIT = .;

/* Stack: OsCore0_Error (1024 Byte) */
  . = align(1024);
  _OS_STACK_OSCORE0_ERROR_VAR_NOINIT_START = .;
  *(.OS_STACK_OSCORE0_ERROR_VAR_NOINIT)
  _OS_STACK_OSCORE0_ERROR_VAR_NOINIT_END = .-1;
  _OS_STACK_OSCORE0_ERROR_VAR_NOINIT_LIMIT = .;

_OS_CORE0_STACKS_END = .-1;
_OS_CORE0_STACKS_LIMIT = .;
#endif

#ifdef OS_LINK_KERNEL_STACKS
# undef OS_LINK_KERNEL_STACKS
#endif


