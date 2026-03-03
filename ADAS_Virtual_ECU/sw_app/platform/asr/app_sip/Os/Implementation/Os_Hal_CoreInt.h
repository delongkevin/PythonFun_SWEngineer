/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \ingroup     Os_Hal
 * \defgroup    Os_Hal_Core HAL Core.
 * \trace       CREQ-1201
 *
 * \{
 * \file        Os_Hal_CoreInt.h
 * \brief       Declares core and multi-core related primitives.
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_COREINT_H
# define OS_HAL_COREINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_CommonInt.h"
# include "Os_Hal_Core_Types.h"
# include "Os_Core_Types.h"
# include "Os_Hal_InterruptInt.h"
# include "Os_Hal_MemoryProtectionInt.h"
# include "Os_Core_Cfg.h"

/* Os HAL dependencies */


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! \brief    This define is used to mask the MSR bits that are not controlled by the OS (user bits).
 *  \details
 *  The define is needed during core initialization and context switch to avoid destroying the user configuration
 *  of the MSR (Machine State Register).
 */
# define OS_HAL_CORE_MSR_USER_BIT_MSK           (0xFEFFFE00uL)

/*! Defines whether the HAL provides a count leading zeros command (STD_ON) or not (STD_OFF). */
# define OS_HAL_COUNT_LEADING_ZEROS_HARDWARE     STD_ON

/*! The required address width to subscript the bits of a Os_Hal_CoreBitFieldType.
 * The value can be selected from the following table:
 * typeof(Os_Hal_BitFieldType)      | OS_HAL_INDEXBITWIDTH
 * :------------------------------: | :----------------------------
 * uint8                            | 3
 * uint16                           | 4
 * uint32                           | 5
 * uint64                           | 6
 */
# define OS_HAL_INDEXBITWIDTH       (5)

/*! Defines the value which is returned by \ref Os_Hal_SpinTryLock, if locking succeeded. */
# define OS_HAL_SPINLOCKSUCCEEDED    ((Os_Hal_SpinlockResultType)0uL)

/****** Cortex-AR specific defines ******/
/*! Multiprocessor Affinity Register (MPIDR):  Multi processor ID bit mask. */
# define OS_HAL_MULTIPROCESSOR_ID_MASK          (3uL)
# define OS_HAL_MULTIPROCESSOR_GROUP_MASK       (0x0000FF00uL)
/*! CPSR Register: IRQ Interrupt state bit mask. */
# define OS_HAL_PSR_INTERRUPTS_MASKED           (1uL << 7)
/*! CPSR Register: FIQ Interrupt state bit mask. */
# define OS_HAL_PSR_INTERRUPTS_MASKED_FIQ       (1uL << 6)
/*! CPSR Register: IRQ, FIQ not masked. */
# define OS_HAL_PSR_INTERRUPTS_ENABLE_GLOBAL    (0uL)


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! Platform specific core data. */
typedef uint32 Os_Hal_CoreType;

/*! \brief    Platform specific core configuration for AUTOSAR and Non-AUTOSAR cores.
 *  \details  Contains information for starting cores and master-slave emulation, if needed.
 */
struct Os_Hal_CoreConfigType_Tag
{
  /*!< Physical core ID.
  
       Note: 
       This type is used by the generated OsCfg_Hal_Core_OsCoreX const.
       For Zuxx, in the generated OsCfg_Hal_Core_OsCoreX const, physical core ID values (0,1) are used instead of
       preconfigured BSWMD physical core ID values (2,3). */
  uint32 CoreId;
};

/*! \brief    Struct for a core variable used at exception entry to save registers which are overwritten 
 *            afterwards to switch to kernel stack.
 *            
 *  \details  The usage of a var avoids pushing those registers to the stack which might otherwise cause 
 *            another exception.
 *            Each core has its own variable.
 */
struct Os_Hal_ExcEntryRegSaveType_Tag
{
  /* 0x00 */ uint32 R0;
  /* 0x04 */ uint32 R1;
  /* 0x08 */ uint32 R2;
  /* 0x0C */ uint32 R3;
  /* 0x10 */ uint32 R4;
  /* 0x14 */ uint32 R5;
  /* 0x18 */ uint32 LR_exc;
  /* 0x1C */ uint32 SPSR_exc;
  /* 0x20 */ uint32 SP_sys;
  /* 0x24 */ uint32 LR_sys;  
  /* 0x28 */ uint32 StackRegion_DRBAR;
  /* 0x2C */ uint32 StackRegion_DRACR;
  /* 0x30 */ uint32 StackRegion_DRSR;
};

/*! \brief    Platform specific AUTOSAR core configuration.
 *  \details  Contains the core specific interrupt and exceptions tables.
 */
struct Os_Hal_CoreAsrConfigType_Tag
{
  CONSTP2VAR(Os_Hal_ExcEntryRegSaveType, AUTOMATIC, OS_VAR_NOINIT_FAST) ExcEntryRegSaveVarRef;  /*!< Pointer holding the address of the core struct var used to save registers on exception entry. */
  Os_Hal_ExceptionTableType ExceptionTable;                                                     /*!< Pointer to exception vector table. */
  Os_Hal_VectorTableType IrqVectorTable[OS_HAL_NUMBER_OF_VECTOR_TABLES];                        /*!< Pointer to Irq vector tables. */
  Os_Hal_VectorTableType FiqVectorTable;                                                        /*!< Pointer to Fiq vector table. */
  Os_AddressOfConstType StackProtectionStartLabel;                                              /*!< Start label of the cores stack section. */
  Os_AddressOfConstType StackProtectionLimitLabel;                                              /*!< Limit label of the cores stack section. */
};

/*! \brief Platform specific dynamic system information.
 */
struct Os_Hal_Core2ThreadType_Tag
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread; /*!< Pointer to current thread. */
};

/*! \brief Platform specific list of system information.
 */
struct Os_Hal_Core2ThreadConfigType_Tag
{
  /*! Pointer to current thread pointer. */
  P2VAR(Os_Hal_Core2ThreadType, AUTOMATIC, OS_VAR_NOINIT_FAST) Core2Thread[OS_CFG_COREPHYSICALID_COUNT];
};

/*! \brief  Platform specific system configuration.
 */
struct Os_Hal_SystemConfigType_Tag
{
  uint32 Dummy; /*!< Data type not used on ARM platform. */
};


/*! XSignal interrupt configuration. */
struct Os_Hal_XSigInterruptConfigType_Tag
{
  uint32 Source;           /*!< The interrupt source ID to be triggered. */
  uint32 CoreID;           /*!< The core ID that has to handle the interrupt. */
};

/****** Cortex-AR specific data structures ******/
/*! Processor modes. */
typedef enum
{
  Os_Hal_ProcessorMode_User = 0x10u,          /*!< User Mode. */
  Os_Hal_ProcessorMode_FIQ = 0x11u,           /*!< FIQ Mode. */
  Os_Hal_ProcessorMode_IRQ = 0x12u,           /*!< IRQ Mode. */
  Os_Hal_ProcessorMode_Supervisor = 0x13u,    /*!< Supervisor Mode. */
  Os_Hal_ProcessorMode_Monitor = 0x16u,       /*!< Monitor Mode. */
  Os_Hal_ProcessorMode_Abort = 0x17u,         /*!< Abort Mode. */
  Os_Hal_ProcessorMode_Hyp = 0x1Au,           /*!< Hyp Mode. */
  Os_Hal_ProcessorMode_Undefined = 0x1Bu,     /*!< Undefined Mode. */
  Os_Hal_ProcessorMode_System = 0x1Fu         /*!< System Mode. */
} Os_Hal_ProcessorMode_Type;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_Hal_CoreGetId()
 **********************************************************************************************************************/
/*! \brief          Returns the physical identifier of the local core
 *  \details        -
 *  \return         Physical identifier of the local core.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            -
 *  \note           Candidate for OS_NOSIDEEFFECTS or OS_PURE.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_CorePhysicalIdType, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_CoreGetId,
(
  void
));


/***********************************************************************************************************************
 *  Os_Hal_CoreInit()
 **********************************************************************************************************************/
/*! \brief          Hardware initialization of the current core.
 *  \details        The kernel calls this function on each core. If the given core has its own interrupt controller,
 *                  the core local interrupt controller is initialized here. It shall not enable memory protection
 *                  (this is part of the memory protection module). See also Os_Hal_CoreInitHardware().
 *  \param[in]      Config  Configuration which shall be used to perform hardware initialization on each core.
 *                          Parameter must not be NULL.
 *  \context        OS_INTERNAL
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 *  \pre            OS may be not initialized
 *  \trace          CREQ-1201
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Hal_CoreInit
(
  P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Config
);


/***********************************************************************************************************************
 *  Os_Hal_CoreInitHardware()
 **********************************************************************************************************************/
/*! \brief          Hardware initialization on the Hardware Init Core.
 *  \details        The kernel calls this function on the Hardware Init Core. It shall initialize the system interrupt controller
 *                  if present. It shall not enable memory protection. See also Os_Hal_CoreInit().
 *                  #### Interrupt Controller ####
 *                  If there is an interrupt controller for all cores, it has to be initialized here.
 *                  This is typically:
 *                  - Set the interrupt priority levels of all ISRs.
 *                  - Set the core mapping of all ISRs.
 *                  Interrupt sources, which are not configured, shall not be touched. The enabled-state of all interrupt sources
 *                  shall not be touched. This might not be possible on some interrupt controllers.
 *  \param[in]      Config  Configuration which shall be used to perform hardware initialization on the master core.
 *                          Parameter must not be NULL.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 *  \pre            OS may be not initialized
 *  \trace          CREQ-1201
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Hal_CoreInitHardware
(
  P2CONST(Os_Hal_SystemConfigType, AUTOMATIC, OS_CONST) Config
);


/***********************************************************************************************************************
 *  Os_Hal_CoreIsThreadPointerUserReadable()
 **********************************************************************************************************************/
/*! \brief          Returns whether the thread pointer is readable in user mode.
 *  \details        -
 *  \retval         !0 Thread pointer is readable in user mode.
 *  \retval         0  Thread pointer is not readable in user mode.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_CoreIsThreadPointerUserReadable,
(
  void
));


/***********************************************************************************************************************
 *  Os_Hal_CoreIsCoreIdUserReadable()
 **********************************************************************************************************************/
/*! \brief        Returns whether the core ID is readable in user mode.
 *  \details      --no details--
 *
 *  \retval       !0 Core ID is readable in user mode.
 *  \retval       0  Core ID is not readable in user mode.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_CoreIsCoreIdUserReadable,
(
  void
));



/***********************************************************************************************************************
 *  Os_Hal_CoreSetThread()
 **********************************************************************************************************************/
/*! \brief          Set the current thread pointer on the local core.
 *  \details        Main intention of holding the current thread pointer in the HAL is to speed up access to it.
 *                  The current thread pointer is accessed very often. The thread tells the kernel to which core it
 *                  belongs, to which application, which memory access rights are currently active,
 *                  which timing protection settings, etc.
 *                  There are the following variants to speed this up:
 *                  1. OS exclusive special purpose register: On some architectures there are special purpose register for
 *                  OS usage. They can be used to hold information which is frequently used.
 *                  2. Fast memory: Map the location for this value to fast accessible memory.
 *                  If the architecture does not provide such possibilities, the thread pointer can be an attribute in the
 *                  Os_Hal_Core2ThreadConfigType data structure.
 *                  Safety measures:
 *                  In case of mixed criticality derivatives, the location of the current thread has to be write protected
 *                  for other cores. This may be achieved by using either
 *                  - a core local register (write protected in user mode)
 *                  - or by using a constant array which references the location of the current thread.
 *                  This location is write protected for other cores.
 *
 *  \see            \ref Os_Thread
 *  \see            \ref Os_Hal_Core2ThreadType
 *  \see            \ref Os_Hal_Core2ThreadConfigType
 *
 *  \param[out]     Core2Thread    Pointer to a data structure which allows to get the current thread on a specific core
 *                                 (this may bee a NULL pointer on platforms which do not need such a data structure).
 *  \param[in]      Thread  Pointer to the current thread of the local core. Parameter must not be NULL.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_CoreSetThread,
(
  P2CONST(Os_Hal_Core2ThreadConfigType, AUTOMATIC, OS_CONST) Core2Thread,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_Hal_CoreGetThread()
 **********************************************************************************************************************/
/*! \brief        Returns the current thread pointer of the local core.
 *  \details      See Os_Hal_CoreSetThread().
 *  \param[in]    Core2Thread      Pointer to a data structure which allows to get the current thread on a specific core
 *                                 (this may be a NULL pointer on platforms which do not need such a data structure).
 *  \return       Pointer to the current thread of the local core.
 *  \context      OS_INTERNAL
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          Current thread pointer has been set before.
 *  \note         Candidate for OS_NOSIDEEFFECTS or OS_PURE.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_CoreGetThread,
(
  P2CONST(Os_Hal_Core2ThreadConfigType, AUTOMATIC, OS_CONST) Core2Thread
));


/***********************************************************************************************************************
 *  Os_Hal_CoreIsPrivilegedModeUserReadable()
 **********************************************************************************************************************/
/*! \brief        Returns whether the privileged mode is readable in user mode.
 *  \details      Only supervisor has full access rights to the privileged mode. Reading in user mode would return
 *                incorrect results.
 *
 *  \retval       0  Privileged mode is not readable in user mode.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_CoreIsPrivilegedModeUserReadable,
(
  void
));


/***********************************************************************************************************************
 *  Os_Hal_CoreGetPrivilegedMode()
 **********************************************************************************************************************/
/*! \brief        Returns the current privileged mode.
 *  \details      --no details--
 *
 *  \retval       !0 Supervisor mode.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode is active.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_CoreGetPrivilegedMode,
(
  void
));


/***********************************************************************************************************************
 *  Os_Hal_CountLeadingZeros()
 **********************************************************************************************************************/
/*! \brief          Returns the number of consecutive zeros counted from the MSb.
 *  \details        If the MSb of BitField is set, zero is returned.
 *                  If the given BitField is zero, the bit width of Os_BitArrayType is returned.
 *  \param[in]      BitField       Field to query.
 *  \return         The number of consecutive zero bits.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint8, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_CountLeadingZeros,
(
  Os_Hal_BitFieldType BitField
));


/***********************************************************************************************************************
 *  Os_Hal_StackEndGet()
 **********************************************************************************************************************/
/*! \brief          Returns the stack end of two given addresses.
 *  \details        Stack growing direction is hardware dependent. On some architectures the stack end is at the low
 *                  address of the stack, on others at the high address of the stack.
 *  \see            \ref GlossaryStackWording
 *  \param[in,out]  LowAddress     The low address of the stack.
 *  \param[in,out]  HighAddress    The high address of the stack.
 *  \return         Stack end pointer.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT),
OS_CODE, OS_ALWAYS_INLINE, Os_Hal_StackEndGet,
(
  P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) LowAddress,
  P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) HighAddress
));


/***********************************************************************************************************************
 *  Os_Hal_StackBottomGet()
 **********************************************************************************************************************/
/*! \brief          Returns the stack bottom of two given addresses.
 *  \details        Stack growing direction is hardware dependent. On some architectures the stack bottom is at the low
 *                  address of the stack, on others at the high address of the stack.
 *  \see            \ref GlossaryStackWording
 *  \param[in,out]  LowAddress     The low address of the stack.
 *  \param[in,out]  HighAddress    The high address of the stack.
 *  \return         Stack bottom pointer.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT),
OS_CODE, OS_ALWAYS_INLINE, Os_Hal_StackBottomGet,
(
  P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) LowAddress,
  P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) HighAddress
));


/***********************************************************************************************************************
 *  Os_Hal_StackTopGet()
 **********************************************************************************************************************/
/*! \brief          Returns the stack top of the current stack.
 *  \details        Depending on the architecture, the stack pointer points to the last used or the next free entry.
 *                  The stack top is defined as the last entry used.
 *  \see            \ref GlossaryStackWording
 *  \return         Stack top of the current stack.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            -
 *********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_StackTopGet,
(
  void
));


/***********************************************************************************************************************
 *  Os_Hal_StackPointerMoveDown()
 **********************************************************************************************************************/
/*! \brief          Moves the given pointer towards the stack bottom.
 *  \details        On systems where a pop instruction:
 *                  1. Decreases the pointer, this function decreases the given stack address.
 *                  2. Increases the pointer, this function increases the given stack address.
 *                  Decreasing and increasing is done using 'sizeof(Os_Hal_CoreStackType)'.
 *  \see            \ref GlossaryStackWording
 *  \param[in,out]  StackPointer   The stack pointer to step down.
 *  \return         The result pointer address.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_StackPointerMoveDown,
(
  P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) StackPointer
));


/***********************************************************************************************************************
 *  Os_Hal_StackCalculateUsage()
 **********************************************************************************************************************/
/*! \brief          Calculates the number of bytes between the stack bottom and the stack top.
 *  \details        -
 *  \see            \ref GlossaryStackWording
 *  \param[in]      StackBottom    Stack bottom.
 *  \param[in]      StackTop       Stack top.
 *  \return         Number of bytes between StackBottom and StackTop including StackBottom and StackTop.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_StackCalculateUsage,
(
  P2CONST(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) StackBottom,
  P2CONST(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) StackTop
));


/***********************************************************************************************************************
 *  Os_Hal_CoreStart()
 **********************************************************************************************************************/
/*! \brief          Start the given core.
 *  \details        Starting a core is typically done by writing a special purpose register.
 *  \param[in]      Core  The core which shall be started. Parameter must not be NULL.
 *  \context        OS_INTERNAL
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_CoreStart,
(
  P2CONST(Os_Hal_CoreConfigType, AUTOMATIC, OS_CONST) Core
));


/***********************************************************************************************************************
 *  Os_Hal_SpinInit()
 **********************************************************************************************************************/
/*! \brief          Initializes the given spinlock as unlocked.
 *  \details        -
 *  \param[in]      Spinlock  The spinlock to check. Parameter must not be NULL.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_SpinInit,
(
  P2VAR(volatile Os_Hal_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) Spinlock
));


/***********************************************************************************************************************
 *  Os_Hal_SpinIsLocked()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given spinlock is locked or not.
 *  \details        -
 *  \param[in]      Spinlock  The spinlock to check. Parameter must not be NULL.
 *  \retval         0   If the given lock is free.
 *  \retval         !0  If the given lock is in use.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_SpinIsLocked,
(
  P2CONST(volatile Os_Hal_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) Spinlock
));


/***********************************************************************************************************************
 *  Os_Hal_SpinTryLock()
 **********************************************************************************************************************/
/*! \brief          Tries to get the lock.
 *  \details        -
 *  \param[in,out]  Spinlock  The spinlock to lock. Parameter must not be NULL.
 *  \retval         OS_HAL_SPINLOCKSUCCEEDED      If getting the lock succeeded.
 *  \retval         !OS_HAL_SPINLOCKSUCCEEDED     If getting the lock failed.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_Hal_SpinlockResultType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_SpinTryLock,
(
  P2VAR(volatile Os_Hal_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) Spinlock
));


/***********************************************************************************************************************
 *  Os_Hal_SpinUnlock()
 **********************************************************************************************************************/
/*! \brief          Release the given spinlock.
 *  \details        -
 *  \param[in,out]  Spinlock  The spinlock to unlock. Parameter must not be NULL.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_SpinUnlock,
(
  P2VAR(volatile Os_Hal_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) Spinlock
));


/***********************************************************************************************************************
 *  Os_Hal_XSigInit()
 **********************************************************************************************************************/
/*! \brief          Initialize a cross core interrupt using the given configuration.
 *  \details        The kernel uses this function during OS initialization to initialize cross core interrupts.
 *  \param[in,out]  XSigConfig     XSignal hardware configuration. Parameter must not be NULL.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_XSigInit,
(
  P2CONST(Os_Hal_XSigInterruptConfigType, AUTOMATIC, OS_CONST) XSigConfig
));


/***********************************************************************************************************************
 *  Os_Hal_XSigTrigger()
 **********************************************************************************************************************/
/*! \brief          Trigger the given interrupt.
 *  \details        The kernel uses this function to tell a foreign core, that a new cross core message is available.
 *  \param[in,out]  XSigConfig     XSignal hardware configuration. Parameter must not be NULL.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_XSigTrigger,
(
  P2CONST(Os_Hal_XSigInterruptConfigType, AUTOMATIC, OS_CONST) XSigConfig
));


/***********************************************************************************************************************
 *  Os_Hal_XSigAcknowledge()
 **********************************************************************************************************************/
/*! \brief          Tell the hardware, that we are handling the interrupt request.
 *  \details        The kernel uses this function to clear pending timer interrupt flags.
 *  \param[in]      XSigConfig      XSignal hardware configuration. Parameter must not be NULL.
 *  \context        ISR2|OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_XSigAcknowledge,
(
  P2CONST(Os_Hal_XSigInterruptConfigType, AUTOMATIC, OS_CONST) XSigConfig
));


/***********************************************************************************************************************
 *  Os_Hal_CoreIdle()
 **********************************************************************************************************************/
/*! \brief          Behavior during idle loop in kernel.
 *  \details        The kernel calls this function in case of idle state in a loop.
 *  \context        TASK|OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_CoreIdle, (void));


/***********************************************************************************************************************
 *  Os_Hal_CoreNop()
 **********************************************************************************************************************/
/*! \brief          Behavior during loops in kernel.
 *  \details        The kernel calls this function in a loop in case that the loop is expected to take some time.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_CoreNop, (void));


/***********************************************************************************************************************
 *  Os_Hal_CoreFreeze()
 **********************************************************************************************************************/
/*! \brief          Freeze behavior.
 *  \details        The kernel calls this function to enter an endless loop in case of an assertion is not true.
 *                  Typically endless loop.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_NORETURN, Os_Hal_CoreFreeze, (void));


/***********************************************************************************************************************
 *  Os_Hal_CoreExceptionGetInterruptLockLevel()
 **********************************************************************************************************************/
/*! \brief          SetException.
 *  \details        The kernel calls this function during GetException functionality to save the current interrupt 
                    lock level to exception context structure.
 *  \context        OS_INTERNAL
 *  \return         Current interrupt lock level.
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
FUNC(Os_Hal_IntLevelType, OS_CODE) Os_Hal_CoreExceptionGetInterruptLockLevel
(
  void
);


/***********************************************************************************************************************
 *  Os_Hal_CoreExceptionSetInterruptLockLevel()
 **********************************************************************************************************************/
/*! \brief          SetException.
 *  \details        The kernel calls this function during SetException functionality to restore the saved interrupt 
                    lock level from exception context structure.
 *  \param[in]      LockLevel      LockLevel to be set.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Hal_CoreExceptionSetInterruptLockLevel
(
  Os_Hal_IntLevelType LockLevel
);


/***********************************************************************************************************************
 *  Os_Hal_Core_InitExceptions()
 **********************************************************************************************************************/
/*! \brief          Initializes exception handling.
 *  \details        This function initializes exception vector table. Depending on the core, this function might do
 *                  nothing. See internal design for more information.
 *  \context        OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_Core_InitExceptions,
(
  P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Config
));


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_COREINT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_CoreInt.h
 **********************************************************************************************************************/

