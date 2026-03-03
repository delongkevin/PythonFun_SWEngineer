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
 *  \ingroup    Os_Hal
 *  \defgroup   Os_Hal_Os  HAL OS
 *  \{
 *
 *  \file       Os_Hal_OsInt.h
 *  \brief      HAL interfaces which are visible to the user.
 *  \details
 *  This file is included by Os.h. Therefore all symbols defined here are visible to the user.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_OSINT_H
# define OS_HAL_OSINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Os_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/*! \brief      Provides function declaration for category 1 ISRs.
 *  \details    -
 *  \param[in]  IsrName   The function name which contains the user code of the category 1 ISR.
 */
# define OS_HAL_ISR1_DECLARE(IsrName)      void IsrName(void)


/*! \brief      Provides function definition for category 1 ISRs.
 *  \details    The kernel uses this macro to provide the platform independent OS_ISR1() interface.
 *  \param[in]  IsrName   The function name which contains the user code of the category 1 ISR.
 */
# define OS_HAL_ISR1_DEFINE(IsrName)       void IsrName(void)

/*! \brief      Provides function declaration for category 0 ISRs.
 *  \param[in]  IsrName   The function name which contains the user code of the category 0 ISR.
 */
# define OS_HAL_ISR0_DECLARE(IsrName)      void IsrName(void)


/*! \brief      Provides function definition for category 0 ISRs.
 *  \details    The kernel uses this macro to provide the platform independent OS_ISR0() interface.
 *  \param[in]  IsrName   The function name which contains the user code of the category 0 ISR.
 */
# define OS_HAL_ISR0_DEFINE(IsrName)       void IsrName(void)

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! \brief     General purpose registers of the mode previous to the exception entry.
 *  -
*/
struct Os_Hal_PreviousModeGpRegistersType_Tag
{
  /* 0x04 */ uint32 R0;                      /*!< R0. */
  /* 0x08 */ uint32 R1;                      /*!< R1. */
  /* 0x0C */ uint32 R2;                      /*!< R2. */
  /* 0x10 */ uint32 R3;                      /*!< R3. */
  /* 0x14 */ uint32 R4;                      /*!< R4. */
  /* 0x18 */ uint32 R5;                      /*!< R5. */
  /* 0x1C */ uint32 R6;                      /*!< R6. */
  /* 0x20 */ uint32 R7;                      /*!< R7. */
  /* 0x24 */ uint32 R8;                      /*!< R8. */
  /* 0x28 */ uint32 R9;                      /*!< R9. */
  /* 0x2C */ uint32 R10;                     /*!< R10. */
  /* 0x30 */ uint32 R11;                     /*!< R11. */
  /* 0x34 */ uint32 R12;                     /*!< R12. */
  /* 0x38 */ uint32 SP;                      /*!< SP. */
  /* 0x3C */ uint32 LR;                      /*!< LR. */  
};
typedef struct Os_Hal_PreviousModeGpRegistersType_Tag Os_Hal_PreviousModeGpRegistersType;

/*! \brief     Banked FIQ mode registers.
 *  -
*/
struct Os_Hal_BankedFiqRegistersType_Tag
{
  /* 0x40 */ uint32 R8_fiq;                  /*!< R8_fiq. */
  /* 0x44 */ uint32 R9_fiq;                  /*!< R9_fiq. */
  /* 0x48 */ uint32 R10_fiq;                 /*!< R10_fiq. */
  /* 0x4C */ uint32 R11_fiq;                 /*!< R11_fiq. */
  /* 0x50 */ uint32 R12_fiq;                 /*!< R12_fiq. */
  /* 0x54 */ uint32 SP_fiq;                  /*!< SP_fiq. */
  /* 0x58 */ uint32 LR_fiq;                  /*!< LR_fiq. */
  /* 0x5C */ uint32 SPSR_fiq;                /*!< SPSR_fiq. */
};
typedef struct Os_Hal_BankedFiqRegistersType_Tag Os_Hal_BankedFiqRegistersType;

/*! \brief     Banked IRQ mode registers.
 *  -
*/
struct Os_Hal_BankedIrqRegistersType_Tag
{
  /* 0x60 */ uint32 SP_irq;                  /*!< SP_irq. */
  /* 0x64 */ uint32 LR_irq;                  /*!< LR_irq. */
  /* 0x68 */ uint32 SPSR_irq;                /*!< SPSR_irq. */
};
typedef struct Os_Hal_BankedIrqRegistersType_Tag Os_Hal_BankedIrqRegistersType;

/*! \brief     Banked ABT mode registers.
 *  -
*/
struct Os_Hal_BankedAbtRegistersType_Tag
{
  /* 0x6C */ uint32 SP_abt;                  /*!< SP_abt. */
  /* 0x70 */ uint32 LR_abt;                  /*!< LR_abt. */
  /* 0x74 */ uint32 SPSR_abt;                /*!< SPSR_abt. */
};
typedef struct Os_Hal_BankedAbtRegistersType_Tag Os_Hal_BankedAbtRegistersType;

/*! \brief     Banked SVC mode registers.
 *  -
*/
struct Os_Hal_BankedSvcRegistersType_Tag
{
  /* 0x78 */ uint32 SP_svc;                  /*!< SP_svc. */
  /* 0x7C */ uint32 LR_svc;                  /*!< LR_svc. */
  /* 0x80 */ uint32 SPSR_svc;                /*!< SPSR_svc. */
};
typedef struct Os_Hal_BankedSvcRegistersType_Tag Os_Hal_BankedSvcRegistersType;

/*! \brief     Banked UND mode registers.
 *  -
*/
struct Os_Hal_BankedUndRegistersType_Tag
{
  /* 0x84 */ uint32 SP_und;                  /*!< SP_und. */
  /* 0x88 */ uint32 LR_und;                  /*!< LR_und. */
  /* 0x8C */ uint32 SPSR_und;                /*!< SPSR_und. */
};
typedef struct Os_Hal_BankedUndRegistersType_Tag Os_Hal_BankedUndRegistersType;

/*! \brief     Banked registers.
 *  -
*/
struct Os_Hal_BankedRegistersType_Tag
{
  /* 0x40 */ Os_Hal_BankedFiqRegistersType BankedFiqRegisters; /*!< Banked FIQ Registers. */
  /* 0x60 */ Os_Hal_BankedIrqRegistersType BankedIrqRegisters; /*!< Banked IRQ Registers. */
  /* 0x6C */ Os_Hal_BankedAbtRegistersType BankedAbtRegisters; /*!< Banked ABT Registers. */
  /* 0x78 */ Os_Hal_BankedSvcRegistersType BankedSvcRegisters; /*!< Banked SVC Registers. */
  /* 0x84 */ Os_Hal_BankedUndRegistersType BankedUndRegisters; /*!< Banked UND Registers. */
};
typedef struct Os_Hal_BankedRegistersType_Tag Os_Hal_BankedRegistersType;

/*! \brief     Data Fault Registers.
 *  -
*/
struct Os_Hal_DataFaultRegistersType_Tag
{
  /* 0x94 */ uint32 DFSR;                    /*!< DFSR. */
  /* 0x98 */ uint32 ADFSR;                   /*!< ADFSR. */
  /* 0x9C */ uint32 DFAR;                    /*!< DFAR. */
};
typedef struct Os_Hal_DataFaultRegistersType_Tag Os_Hal_DataFaultRegistersType;

/*! \brief     Instruction Fault Registers.
 *  -
*/
struct Os_Hal_InstructionFaultRegistersType_Tag
{
  /* 0xA0 */ uint32 IFSR;                    /*!< IFSR. */
  /* 0xA4 */ uint32 AIFSR;                   /*!< AIFSR. */
  /* 0xA8 */ uint32 IFAR;                    /*!< IFAR. */
};
typedef struct Os_Hal_InstructionFaultRegistersType_Tag Os_Hal_InstructionFaultRegistersType;

/*! \brief     FPU registers: S0..S31.
 *  -
*/
struct Os_Hal_FpuOperationRegistersType_Tag
{
  /* 0xAC  */ uint32 S0;                     /*!< S0. */
  /* 0xB0  */ uint32 S1;                     /*!< S1. */
  /* 0xB4  */ uint32 S2;                     /*!< S2. */
  /* 0xB8  */ uint32 S3;                     /*!< S3. */
  /* 0xBC  */ uint32 S4;                     /*!< S4. */
  /* 0xC0  */ uint32 S5;                     /*!< S5. */
  /* 0xC4  */ uint32 S6;                     /*!< S6. */
  /* 0xC8  */ uint32 S7;                     /*!< S7. */
  /* 0xCC  */ uint32 S8;                     /*!< S8. */
  /* 0xD0  */ uint32 S9;                     /*!< S9. */
  /* 0xD4  */ uint32 S10;                    /*!< S10. */
  /* 0xD8  */ uint32 S11;                    /*!< S11. */
  /* 0xDC  */ uint32 S12;                    /*!< S12. */
  /* 0xE0  */ uint32 S13;                    /*!< S13. */
  /* 0xE4  */ uint32 S14;                    /*!< S14. */
  /* 0xE8  */ uint32 S15;                    /*!< S15. */
  /* 0xEC  */ uint32 S16;                    /*!< S16. */
  /* 0xF0  */ uint32 S17;                    /*!< S17. */
  /* 0xF4  */ uint32 S18;                    /*!< S18. */
  /* 0xF8  */ uint32 S19;                    /*!< S19. */
  /* 0xFC  */ uint32 S20;                    /*!< S20. */
  /* 0x100 */ uint32 S21;                    /*!< S21. */
  /* 0x104 */ uint32 S22;                    /*!< S22. */
  /* 0x108 */ uint32 S23;                    /*!< S23. */
  /* 0x10C */ uint32 S24;                    /*!< S24. */
  /* 0x110 */ uint32 S25;                    /*!< S25. */
  /* 0x114 */ uint32 S26;                    /*!< S26. */
  /* 0x118 */ uint32 S27;                    /*!< S27. */
  /* 0x11C */ uint32 S28;                    /*!< S28. */
  /* 0x120 */ uint32 S29;                    /*!< S29. */
  /* 0x124 */ uint32 S30;                    /*!< S30. */
  /* 0x128 */ uint32 S31;                    /*!< S31. */
};
typedef struct Os_Hal_FpuOperationRegistersType_Tag Os_Hal_FpuOperationRegistersType;

/*! \brief     FPU Status and control registers.
 *  -
*/
struct Os_Hal_FpuStatusControlRegistersType_Tag
{
  /* 0x12C */ uint32 FPEXC;                  /*!< Floating-Point Exception Register: FPEXC. */
  /* 0x130 */ uint32 FPSCR;                  /*!< Floating-Point Status and Control Register: FPSCR. */
};
typedef struct Os_Hal_FpuStatusControlRegistersType_Tag Os_Hal_FpuStatusControlRegistersType;

/*! \brief     FPU Status and control registers.
 *  -
*/
struct Os_Hal_FpuRegistersType_Tag
{
  /* 0xAC  */ Os_Hal_FpuOperationRegistersType     FpuOperationRegisters;      /*!< S0..S31. */
  /* 0x12C */ Os_Hal_FpuStatusControlRegistersType FpuStatusControlRegisters;  /*!< FPEXC, FPSCR. */
};
typedef struct Os_Hal_FpuRegistersType_Tag Os_Hal_FpuRegistersType;


/*! \brief     Current thread Stack region information: start, size, ...
 *  \details
 *   - 
*/
struct Os_Hal_ThreadStackMpuRegionDetailsType_Tag
{
  /* 0x134 */ uint32 RGNR;   /*!< Thread Stack Region Number */
  /* 0x138 */ uint32 DRBAR;  /*!< Thread Stack Region Base Address Register */
  /* 0x13C */ uint32 DRACR;  /*!< Thread Stack Region Access Control Register */
  /* 0x140 */ uint32 DRSR;   /*!< Thread Stack Region Size and Enable and subregion disable Register */
};
typedef struct Os_Hal_ThreadStackMpuRegionDetailsType_Tag Os_Hal_ThreadStackMpuRegionDetailsType;

/*! \brief     Structure holding exception context elements. 
 *  \details   It is filled by the exception handler when an exception occurs.
 *             It can be overwritten by the user within the protection hook to modify the faulty context.
 *             After calling the proetction hook, the corrected context is written to HW registers at the
*              end of the exception handler before leaving the exception.
*/
struct Os_ExceptionContextType_Tag
{
  /* 0x00  */ uint32                                  ExceptionId;                 /*!< Exception Id. */
  /* 0x04  */ Os_Hal_PreviousModeGpRegistersType      PreviousModeGpRegisters;     /*!< Previous Mode general purpose Registers: R0..R14. */
  /* 0x40  */ Os_Hal_BankedRegistersType              BankedRegisters;             /*!< Banked Registers. */  
  /* 0x90  */ uint32                                  ThreadId;                    /*!< Thread ID Coprocessor Register TPIDRURO. */
  /* 0x94  */ Os_Hal_DataFaultRegistersType           DataFaultRegisters;          /*!< Data Fault Registers        : DFSR, ADFSR, DFAR. */ 
  /* 0xA0  */ Os_Hal_InstructionFaultRegistersType    InstructionFaultRegisters;   /*!< Instruction Fault Registers : IFSR, AIFSR, IFAR. */ 
  /* 0xAC  */ Os_Hal_FpuRegistersType                 FpuRegisters;                /*!< FPU Registers: S0..S31, FPSCR, FPEXC. */
  /* 0x134 */ Os_Hal_ThreadStackMpuRegionDetailsType  ThreadStackMpuRegionDetails; /*!< Current thread Stack MPU region information: start, size, ... */
  /* 0x144 */ uint32                                  ExceptionAddress;            /*!< Location of the Exception. */
  /* 0x148 */ uint32                                  ReturnAddress;               /*!< Return address after the exception handling. */
  /* 0x14C */ uint32                                  InterruptLevel;              /*!< Interrupt controller interrupt lock level. */
};


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


#endif /* OS_HAL_OS_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_OsInt.h
 **********************************************************************************************************************/
