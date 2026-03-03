/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 *  \addtogroup  Os_Hal_Interrupt
 *  \{
 *
 *  \file    Os_Hal_InterruptController_GIC_Nested.h
 *  \brief   HAL interface to work with the ARM PL390 generic interrupt controller (GIC390).
 *  \details
 *           The GICv1 consists of two components:
 *           - The GIC CPU interface, which exists for each core which is connected to the GIC.
 *             Each core sees its CPU interface aliased on the same base address.
 *           - The GIC Distributor, which receives interrupts from devices and sends them to the CPU interfaces.
 *
 *  Internal comment removed.
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
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_INTERRUPTCONTROLLER_GIC_NESTED_H
# define OS_HAL_INTERRUPTCONTROLLER_GIC_NESTED_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! \brief    Logical interrupt level used for tasks.
 *  \details  The logically lowest interrupt level. */
# define OS_HAL_TASK_LEVEL                                  (0xF0u)

/*! Interrupt ID of the legacy nIRQ interrupt. */
# define OS_HAL_INTC_GIC_NIRQ_INTERRUPT_ID                  (31uL)

/*! Interrupt ID of the legacy nFIQ interrupt. */
# define OS_HAL_INTC_GIC_NFIQ_INTERRUPT_ID                  (28uL)

/*! Interrupt ID which encodes a spurious interrupt. */
# define OS_HAL_INTC_GIC_SPURIOUS_INTERRUPT_ID              (1023uL)

/*! Interrupt ID offset for unhandled interrupts of the GIC-Core. */
# define OS_HAL_INTC_GIC_CORE_UNHANDLED_INT_NR_OFFSET       (1024uL)

/*! Sender core ID mask (ICCIAR register) */
# define OS_HAL_INTC_GIC_CPUID_ACKNOWLEDGE_MASK             (0x1C00uL)

/*! IRQ ID mask (ICCIAR register) */
# define OS_HAL_INTC_GIC_IRQID_ACKNOWLEDGE_MASK             (0x3FFuL)

/*! Define the interrupt controller specific cat2 ISR disable level. */
# define OS_HAL_ISR2_DISABLE_LEVEL_ABSTRACT                 (OS_CFG_HAL_ISR2_DISABLE_LEVEL)

/*! Define the interrupt controller specific cat1 ISR disable level. */
# define OS_HAL_ISR1_DISABLE_LEVEL_ABSTRACT                 (OS_CFG_HAL_ISR1_DISABLE_LEVEL)

/*! Define the interrupt controller specific Timing Protection ISR disable level. */
# define OS_HAL_TIMING_PROTECTION_DISABLE_LEVEL_ABSTRACT    (OS_CFG_HAL_TP_DISABLE_LEVEL)

/*! Trigger peripheral interrupt by software supported*/
# define OS_HAL_INTC_SWT_SUPPORTED                          1u

/*! The interrupt controller supports priority level handling. */
# define OS_HAL_INTC_LEVEL_SUPPORTED                        1u


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/*! CPU Interface base address. */
# define OS_HAL_INTC_GIC_RT_CPUIF         ((volatile Os_Hal_IntcGicCpuInterfaceType *)OS_HAL_INTC_GIC_NESTED_RT_CPUIF_BASE)
/*! Distributor base address. */
# define OS_HAL_INTC_GIC_RT_DISTRIBUTOR   ((volatile Os_Hal_IntcGicDistributorType *)OS_HAL_INTC_GIC_NESTED_RT_DISTRIBUTOR_BASE)

/*! CPU Interface base address. */
# define OS_HAL_INTC_GIC_CORE_CPUIF       ((volatile Os_Hal_IntcGicCpuInterfaceType *)OS_HAL_INTC_GIC_NESTED_CORE_CPUIF_BASE)
/*! Distributor base address. */
# define OS_HAL_INTC_GIC_CORE_DISTRIBUTOR ((volatile Os_Hal_IntcGicDistributorType *)OS_HAL_INTC_GIC_NESTED_CORE_DISTRIBUTOR_BASE)



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! GICv1 CPU interface register map. */
typedef struct
{
  uint32 Iccicr;          /*!< Offset: 0x00       CPU Interface Control Register (ICCICR). */
  uint32 Iccpmr;          /*!< Offset: 0x04       Interrupt Priority Mask Register (ICCPMR). */
  uint32 Iccbpr;          /*!< Offset: 0x08       Binary Point Register (ICCBPR). */
  uint32 Icciar;          /*!< Offset: 0x0C       Interrupt Acknowledge Register (ICCIAR). */
  uint32 Icceoir;         /*!< Offset: 0x10       End of Interrupt Register (ICCEOIR). */
  uint32 Iccrpr;          /*!< Offset: 0x14       Running Priority Register (ICCRPR). */
  uint32 Icchpir;         /*!< Offset: 0x18       Highest Pending Interrupt Register (ICCHPIR). */
  uint32 Iccabpr;         /*!< Offset: 0x1C       Aliased Binary Point Register (ICCABPR). */
  uint32 Reserved0[8];    /*!< Offset: 0x20-0x3C  Reserved. */
  uint32 Specific0[37];   /*!< Offset: 0x40-0xCF  Implementation specific. */
  uint32 Reserved1[11];   /*!< Offset: 0xD0-0xF8  Reserved. */
  uint32 Icciidr;         /*!< Offset: 0xFC       CPU Interface Identification Register (ICCIIDR). */
} Os_Hal_IntcGicCpuInterfaceType;


/*! GICv1 Distributor register map. */
typedef struct
{
  uint32 Icddcr;              /*!< Offset: 0x000        Distributor Control Register (ICDDCR). */
  uint32 Icdictr;             /*!< Offset: 0x004        Interrupt Controller Type Register (ICDICTR). */
  uint32 Icdiidr;             /*!< Offset: 0x008        Distributor Implementer Identification Register (ICDIIDR). */
  uint32 Reserved0[29];       /*!< Offset: 0x00C-0x07C  Reserved. */
  uint32 Icdisr[32];          /*!< Offset: 0x080-0x09C  Interrupt Security Registers (ICDISRn).  DIFFERENCE BETWEEN GICv1 SPEC AND CORTEX-A9 MPCore (end offset + 32). */
  uint32 Icdiser[32];         /*!< Offset: 0x100-0x11C  Interrupt Set-Enable Registers (ICDISERn). DIFFERENCE BETWEEN GICv1 SPEC AND CORTEX-A9 MPCore (end offset - 96). */
  uint32 Icdicer[32];         /*!< Offset: 0x180-0x19C  Interrupt Clear-Enable Registers (ICDICERn). DIFFERENCE BETWEEN GICv1 SPEC AND CORTEX-A9 MPCore (end offset - 96). */
  uint32 Icdispr[32];         /*!< Offset: 0x200-0x27C  Interrupt Set-Pending Registers (ICDISPRn). */
  uint32 Icdicpr[32];         /*!< Offset: 0x280-0x29C  Interrupt Clear-Pending Registers (ICDICPRn). DIFFERENCE BETWEEN GICv1 SPEC AND CORTEX-A9 MPCore (end offset - 96). */
  uint32 Icdabr[32];          /*!< Offset: 0x300-0x31C  Active Bit Registers (ICDABRn).  DIFFERENCE BETWEEN GICv1 SPEC AND CORTEX-A9 MPCore (end offset - 96). */
  uint32 Reserved1[32];       /*!< Offset: 0x380-0x3FC  Reserved. */
  uint8  Icdipr[1020];        /*!< Offset: 0x400-0x4FC  Interrupt Priority Registers (ICDIPRn).  DIFFERENCE BETWEEN GICv1 SPEC AND CORTEX-A9 MPCore (end offset - 764). */
  uint32 Reserved2;           /*!< Offset: 0x7FC        Reserved. */
  uint8  Icdiptr[1020];       /*!< Offset: 0x800-0x8FC  Interrupt Processor Targets Registers (ICDIPTRn) DIFFERENCE BETWEEN GICv1 SPEC AND CORTEX-A9 MPCore (end offset + 64) */
  uint32 Reserved3;           /*!< Offset: 0xBFC        Reserved. */
  uint32 Icdicfr[64];         /*!< Offset: 0xC00-0xC3C  Interrupt Configuration Registers (ICDICFRn). DIFFERENCE BETWEEN GICv1 SPEC AND CORTEX-A9 MPCore (end offset - 32)*/
  uint32 Icppisr;             /*!< Offset: 0xD00        PPI Status Register. CORTEX-A9 MPCore specific. */
  uint32 Icspisr[31];         /*!< Offset: 0xD04-0xD1C  SPI Status Register. CORTEX-A9 MPCore specific. */
  uint32 Reserved4[96];       /*!< Offset: 0xD80-0xEFC  Reserved. */
  uint32 Icdsgir;             /*!< Offset: 0xF00        Software Generated Interrupt Register (ICDSGIR). */
  uint32 Reserved5[51];       /*!< Offset: 0xF04-0xFCC  Reserved. */
  uint32 Icpidr0;             /*!< Offset: 0xFD0        Peripheral ID0 register. CORTEX-A9 MPCore specific. */
  uint32 Icpidr1;             /*!< Offset: 0xFD0        Peripheral ID1 register. CORTEX-A9 MPCore specific. */
  uint32 Icpidr2;             /*!< Offset: 0xFD0        Peripheral ID2 register. CORTEX-A9 MPCore specific. */
  uint32 Icpidr3;             /*!< Offset: 0xFD0        Peripheral ID3 register. CORTEX-A9 MPCore specific. */
  uint32 Icpidr4;             /*!< Offset: 0xFD0        Peripheral ID4 register. CORTEX-A9 MPCore specific. */
  uint32 Icpidr5;             /*!< Offset: 0xFD0        Peripheral ID5 register. CORTEX-A9 MPCore specific. */
  uint32 Icpidr6;             /*!< Offset: 0xFD0        Peripheral ID6 register. CORTEX-A9 MPCore specific. */
  uint32 Icpidr7;             /*!< Offset: 0xFD0        Peripheral ID7 register. CORTEX-A9 MPCore specific. */
  uint32 Iccidr0;             /*!< Offset: 0xFD0        Component ID0 register. CORTEX-A9 MPCore specific. */
  uint32 Iccidr1;             /*!< Offset: 0xFD0        Component ID1 register. CORTEX-A9 MPCore specific. */
  uint32 Iccidr2;             /*!< Offset: 0xFD0        Component ID2 register. CORTEX-A9 MPCore specific. */
  uint32 Iccidr3;             /*!< Offset: 0xFD0        Component ID3 register. CORTEX-A9 MPCore specific. */

} Os_Hal_IntcGicDistributorType;


/*! Interrupt type. */
typedef enum
{
  OS_HAL_ISR_CAT2,       /*!< The interrupt source is handled by a category 2 ISR. */
  OS_HAL_ISR_CAT1,       /*!< The interrupt source is handled by a category 1 ISR. */
  OS_HAL_ISR_CAT0,       /*!< The interrupt source is handled by a category 0 ISR. */
  OS_HAL_ISR_UNHANDLED   /*!< The interrupt source has not been configured and is handled by the default handler. */
} Os_Hal_IntcInterruptType;


/*! Data needed to handle the interrupt. */
typedef struct
{                                                                                                                       /* PRQA S 0750 */ /* MD_MSR_Union */
  void *IsrConfigRef;                 /*!< Pointer to High level category 2 ISR configuration object. */
  void (*Cat1IsrFunction)(void);      /*!< Pointer to category 1 ISR function. */
} Os_Hal_IntcIrqDataType;


/*! Interrupt source description. */
typedef struct
{
  Os_Hal_IntcInterruptType InterruptType; /*!< Interrupt type (CAT2, CAT1 or Unhandled). */
  Os_Hal_IntcIrqDataType Data;            /*!< Data which is used to handle the ISR
                                               (IsrConfig pointer or Cat1 function pointer). */
} Os_Hal_IntcIrqSourceConfigType;


/*! Platform specific array of interrupt vector table pointers. */
typedef P2CONST(Os_Hal_IntcIrqSourceConfigType, AUTOMATIC, OS_CONST) Os_Hal_Core2InterruptVectorTableType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_IntDisableAndReturnGlobalState()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE Os_Hal_IntGlobalStateType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntDisableAndReturnGlobalState, (void))
{
   Os_Hal_IntGlobalStateType psr;
   Os_Hal_IntGlobalStateType previousGlobalState;


  /* #10 Get current IRQ and FIQ bits from CPSR. */
  psr = Os_Hal_ReadPsr();
  previousGlobalState = (psr & (OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ));

  /* #20 Set IRQ and FIQ bits of CPSR (global interrupt disable). */
  Os_Hal_WritePsr(psr | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ);

  /* #30 Return the previously read global state. */
  return previousGlobalState;
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_InitIntVectors()
 **********************************************************************************************************************/
/*!
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_InitIntVectors,
(
  P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Core
))
{
  OS_IGNORE_UNREF_PARAM(Core);                                                                                          /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  /* #10 Configure interrupts of any priority to be signaled to the processor for GIC-RT. (Set ICCPMR to 0xF0) */
  OS_HAL_INTC_GIC_RT_CPUIF->Iccpmr = 0xF0uL;                                                                            /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_CPUIF */

  /* #20 Write to the ICCBPR, to set the binary point position,
   * that determines preemption on the interface for GIC-RT. */
  OS_HAL_INTC_GIC_RT_CPUIF->Iccbpr = 0uL;                                                                               /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_CPUIF */

  /* #30 Write to the ICCICR to enable signaling of interrupts by the interface for GIC-RT. */
  OS_HAL_INTC_GIC_RT_CPUIF->Iccicr = 1uL;                                                                               /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_CPUIF */

  /* #40 Write to the ICDDCR to enable the Distributor for GIC-RT. */
  OS_HAL_INTC_GIC_RT_DISTRIBUTOR->Icddcr = 1uL;                                                                         /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_DISTRIBUTOR */

  /* #50 Repeat the steps for GIC-Core. */
  OS_HAL_INTC_GIC_CORE_CPUIF->Iccpmr = 0xF0uL;                                                                          /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_CPUIF */
  OS_HAL_INTC_GIC_CORE_CPUIF->Iccbpr = 0uL;                                                                             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_CPUIF */
  OS_HAL_INTC_GIC_CORE_CPUIF->Iccicr = 1uL;                                                                             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_CPUIF */
  OS_HAL_INTC_GIC_CORE_DISTRIBUTOR->Icddcr = 1uL;                                                                       /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_DISTRIBUTOR */

  /* #60 Set the priority for the legacy nIRQ interrupt to the highest level on GIC-Core. */
  OS_HAL_INTC_GIC_CORE_DISTRIBUTOR->Icdipr[OS_HAL_INTC_GIC_NIRQ_INTERRUPT_ID] = 0x0u;                                   /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_DISTRIBUTOR */

  /* #70 Enable the legacy nIRQ interrupt on GIC-Core. */
  OS_HAL_INTC_GIC_CORE_DISTRIBUTOR->Icdiser[OS_HAL_INTC_GIC_NIRQ_INTERRUPT_ID/32u] =                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_DISTRIBUTOR */
                                                            (1uL << (OS_HAL_INTC_GIC_NIRQ_INTERRUPT_ID%32u));

  /* #80 Set the interrupt priority mask register to the lowest possible level on GIC-Core. */
  OS_HAL_INTC_GIC_CORE_CPUIF->Iccpmr = 0xFFuL;                                                                          /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_CPUIF */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_InitSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_InitSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  /* #10 Set source to secure. GIC security extension is currently not used. */
  OS_HAL_INTC_GIC_RT_DISTRIBUTOR->Icdisr[(InterruptConfig->Source)/32u] &= ~(1uL << (InterruptConfig->Source%32u));     /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_DISTRIBUTOR */

  /* #20 Edge or level sensitivity is not handled by the OS but by drivers and user software. Do nothing. */

  /* #30 Write to the ICDIPRs to specify the priority value for given source. */
  OS_HAL_INTC_GIC_RT_DISTRIBUTOR->Icdipr[InterruptConfig->Source] = (uint8)(InterruptConfig->Level);                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_DISTRIBUTOR */

  /* #40 Specify the target processor. The target of the first 32 sources cannot be modified. */
  if(OS_UNLIKELY((InterruptConfig->Source) > 31u))
  {
    OS_HAL_INTC_GIC_RT_DISTRIBUTOR->Icdiptr[InterruptConfig->Source] = (uint8)(1uL << (InterruptConfig->CoreID));       /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_DISTRIBUTOR */
  }
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_EnableSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_EnableSource,
(
  Os_Hal_IntSourceType Source,
  Os_Hal_IntLevelType Level,
  Os_Hal_IntControllerType InterruptController
))
{
  OS_IGNORE_UNREF_PARAM(Level);                                                                                         /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Enable given interrupt source by writing a 1 to the corresponding Set-enable bit. */
  OS_HAL_INTC_GIC_RT_DISTRIBUTOR->Icdiser[Source/32u] = (1uL << (Source%32u));                                          /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_DISTRIBUTOR */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_EnableMappedSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_EnableMappedSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_DisableSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_DisableSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  /* #10 Disable given interrupt source by writing a 1 to the corresponding Clear-enable bit. */
  OS_HAL_INTC_GIC_RT_DISTRIBUTOR->Icdicer[InterruptConfig->Source/32u] = (1uL << (InterruptConfig->Source%32u));        /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_DISTRIBUTOR */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_DisableMappedSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_DisableMappedSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_SetCurrentLevel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_SetCurrentLevel,
(
  Os_Hal_IntLevelType Level
))
{
  /* #10 Set interrupt priority mask register to given level. */
  OS_HAL_INTC_GIC_RT_CPUIF->Iccpmr = Level;                                                                             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_CPUIF */

  /* #20 Perform data synchronization barrier. */
  Os_Hal_DataSyncBarrier();
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_SetCurrentLevelException()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_SetCurrentLevelException,
(
  Os_Hal_IntLevelType Level
))
{
  /* #10 Set interrupt priority mask register to given level. */
  OS_HAL_INTC_GIC_RT_CPUIF->Iccpmr = Level;                                                                             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_CPUIF */

  /* #20 Perform data synchronization barrier. */
  Os_Hal_DataSyncBarrier();
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_GetCurrentLevel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntLevelType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_GetCurrentLevel,
(
  void
))
{
  /* #10 Return current value of interrupt priority mask register. */
  return OS_HAL_INTC_GIC_RT_CPUIF->Iccpmr;                                                                              /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_GetCurrentLevelException()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntLevelType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_GetCurrentLevelException,
(
  void
))
{
  /* #10 Return current value of interrupt priority mask register. */
  return OS_HAL_INTC_GIC_RT_CPUIF->Iccpmr;                                                                              /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_ClearPending()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_ClearPending,
(
  Os_Hal_IntSourceType Source,
  Os_Hal_IntIsrSenderCoreID SenderCoreID,
  Os_Hal_IntControllerType InterruptController
))                                                                                                                      /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
{
  OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Clear interrupt pending flag. */
  OS_HAL_INTC_GIC_RT_DISTRIBUTOR->Icdicpr[Source/32u] = (1uL << (Source%32u));                                          /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_DISTRIBUTOR */

  /* #20 Signal end of interrupt for the given source. */
  Os_Hal_INTC_EndOfInterrupt(Source, SenderCoreID);
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_EndOfInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_EndOfInterrupt,
(
  Os_Hal_IntSourceType Source,
  Os_Hal_IntIsrSenderCoreID SenderCoreID
))
{
  /* #10 Write source ID and the sender core ID to ICCEOIR to signal end of interrupt to the GIC-RT. */
  OS_HAL_INTC_GIC_RT_CPUIF->Icceoir = SenderCoreID | Source;                                                            /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_CPUIF */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IntEndOfInterruptMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IntEndOfInterruptMapped,
(
  Os_Hal_IntSourceType Source
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(Source);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_TriggerPeripheralInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_TriggerPeripheralInterrupt,
(
  Os_Hal_IntSourceType Source,
  Os_Hal_IntControllerType InterruptController
))                                                                                                                      /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
{
  OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Trigger given interrupt source by writing a 1 to the corresponding
   *     interrupt set-pending register (ICDISPRn). */
  OS_HAL_INTC_GIC_RT_DISTRIBUTOR->Icdispr[Source/32u] = (1uL << (Source%32u));                                          /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_DISTRIBUTOR */
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_TriggerCrossCoreInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
  Os_Hal_INTC_TriggerCrossCoreInterrupt,
(
  uint32 CoreID,
  Os_Hal_IntSourceType Source
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  /* #10 Not supported: single core derivative.*/
  OS_IGNORE_UNREF_PARAM(CoreID);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(Source);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IsInterruptSourceEnabled()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IsInterruptSourceEnabled,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  /* #10 Return whether given interrupt source is enabled by inspecting the corresponding bit
   *     in the Interrupt Clear-Enable Registers (ICDICERn). */
  return (Os_StdReturnType)((OS_HAL_INTC_GIC_RT_DISTRIBUTOR->Icdicer[InterruptConfig->Source/32u] &                     /* PRQA S 0303, 4304 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_C90BooleanCompatibility */
      (1uL << (InterruptConfig->Source%32u))) != 0u);
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IsMappedInterruptSourceEnabled()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IsMappedInterruptSourceEnabled,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  /* #10 Mapped interrupt feauture is not supported. */
  return (Os_StdReturnType)(0u);
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IsInterruptPending()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IsInterruptPending,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  /* #10 Return whether an interrupt is pending at the given interrupt source by reading the corresponding bit
   *     in the Interrupt Clear-Pending Registers (ICDICPRn). */
  return (Os_StdReturnType)((OS_HAL_INTC_GIC_RT_DISTRIBUTOR->Icdicpr[InterruptConfig->Source/32u] &                     /* PRQA S 0303, 4304 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_C90BooleanCompatibility */
      (1uL << (InterruptConfig->Source%32u))) != 0u);
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IntLevelIsGt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_IntLevelIsGt,
(
  CONST(Os_Hal_IntLevelType, OS_CONST) LevelX,
  CONST(Os_Hal_IntLevelType, OS_CONST) LevelY
))
{
  /* #10 Return !0 if LevelX is smaller than LevelY. */
  return (Os_StdReturnType)(LevelX < LevelY);                                                                           /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IsClearPendingSupported()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IsClearPendingSupported, ( void ))
{
  /* #10 Return 1 (clear pending interrupt is always possible). */
  return (Os_StdReturnType)(1u);
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IrqHandler()
 **********************************************************************************************************************/
/*!
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
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IrqHandler,
(
  uint32 Address,
  uint32 IsPrivileged
))
{
  volatile uint32 irqNumberCore;

  extern CONST(Os_Hal_Core2InterruptVectorTableType, OS_CONST) OsCfg_Hal_Core2InterruptVectorTable[];                   /* PRQA S 3684 */ /* MD_Os_Rule8.11_3684_LinkerSymbol */

  P2CONST(Os_Hal_IntcIrqSourceConfigType, AUTOMATIC, OS_CONST) interruptVectorTable =
      OsCfg_Hal_Core2InterruptVectorTable[Os_Hal_CoreGetId()];

  /* #10 Get the interrupt source of the GIC-Core. */
  irqNumberCore = OS_HAL_INTC_GIC_CORE_CPUIF->Icciar & OS_HAL_INTC_GIC_IRQID_ACKNOWLEDGE_MASK;                          /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */

  /* #20 If the interrupt on GIC-Core is nIRQ, process it. */
  if(irqNumberCore == OS_HAL_INTC_GIC_NIRQ_INTERRUPT_ID)                                                                /* COV_OS_HALPLATFORM_UNHANDLEDINT_ON_NESTED_INTC */
  {
    volatile uint32 irqNumberRT;
    volatile uint32 icciarRT;

    /* #30 Get the interrupt source and sender core ID from GIC-RT to acknowledge the interrupt. */
    icciarRT = OS_HAL_INTC_GIC_RT_CPUIF->Icciar;                                                                        /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
    irqNumberRT = icciarRT & OS_HAL_INTC_GIC_IRQID_ACKNOWLEDGE_MASK;

    /* #40 Signal EOI on the GIC-Core to make the GIC-Core drop the legacy interrupt irq priority, allowing interrupt preemption. */
    OS_HAL_INTC_GIC_CORE_CPUIF->Icceoir = OS_HAL_INTC_GIC_NIRQ_INTERRUPT_ID;                                            /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GIC_CPUIF */

    /* #50 If the interrupt has been a spurious interrupt, ignore it. */
    if(OS_UNLIKELY(irqNumberRT == OS_HAL_INTC_GIC_SPURIOUS_INTERRUPT_ID))                                               /* COV_OS_HALPLATFORMSPURIOUSINTERRUPT */
    {
      ;
    }
    /* #60 Otherwise: */
    else
    {
      /* #70 Store the sender core ID in the interrupt configuration (will be used at end of interrupt). */

      switch(interruptVectorTable[irqNumberRT].InterruptType)
      {
        /* #80 If the ISR is a category 2 ISR call kernel function and pass pointer to ISR configuration object. */
        case OS_HAL_ISR_CAT2:
          {
            P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) pIsrConfig =
              (const Os_IsrConfigType*)interruptVectorTable[irqNumberRT].Data.IsrConfigRef;                             /* PRQA S 0316 */ /* MD_Os_Hal_Rule11.5_0316 */
            *(pIsrConfig->SourceConfig->HwConfig->SenderCoreID) = icciarRT & OS_HAL_INTC_GIC_CPUID_ACKNOWLEDGE_MASK;    /* SBSW_OS_HAL_INT_VECTOR_TABLE */
            Os_IsrRun(pIsrConfig);                                                                                      /* SBSW_OS_HAL_FC_ISRCONFIG_GIC */
          }
          break;

        /* #90 If the ISR is a category 1 or 0 ISR call its function. */
        case OS_HAL_ISR_CAT0:
        case OS_HAL_ISR_CAT1:
          interruptVectorTable[irqNumberRT].Data.Cat1IsrFunction();                                                     /* SBSW_OS_HAL_FPC_ISRCONFIG_GIC */
          break;

        /* #100 Otherwise the ISR has not been configured, call the default handler and pass the interrupt ID. */
        case OS_HAL_ISR_UNHANDLED:
        default:                                                                                                        /* COV_OS_HALPLATFORMGICINVSTATE */
          Os_UnhandledIrq(irqNumberRT, (Os_AddressOfConstType)Address, (boolean)IsPrivileged);                          /* PRQA S 0326, 4340 */ /* MD_Os_Rule11.6_0326, MD_Os_C90BooleanCompatibility */ /* SBSW_OS_HAL_FC_POINTER2CONST */
          break;                                                                                                        /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880_NonReturning */
      }
    }
  }
  else if (irqNumberCore == OS_HAL_INTC_GIC_SPURIOUS_INTERRUPT_ID)
  {
    /* #110 Otherwise if the interrupt has been a spurious interrupt, ignore it. */
  }
  else
  {
    /* #120 Otherwise signal an unhandled interrupt. */
    Os_UnhandledIrq(irqNumberCore + OS_HAL_INTC_GIC_CORE_UNHANDLED_INT_NR_OFFSET,
                    (Os_AddressOfConstType)Address, (boolean)IsPrivileged);                                             /* PRQA S 0326, 4340 */ /* MD_Os_Rule11.6_0326, MD_Os_C90BooleanCompatibility */ /* SBSW_OS_HAL_FC_POINTER2CONST */
  }
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IntClearPendingMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IntClearPendingMapped,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IntIsInterruptPendingMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IntIsInterruptPendingMapped,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  /* #10 Mapped interrupt feauture is not supported. */
  return (Os_StdReturnType)(0u);
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IntIsInterruptMappingSupported()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IntIsInterruptMappingSupported, ( void ))
{
  /* #10 Check whether interrupt mapping is supported. */
  return (Os_StdReturnType)(0u);
}


/***********************************************************************************************************************
 *  Os_Hal_IntIsInterruptPostActionSupported()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_IntIsInterruptPostActionSupported, ( void ))
{
  /* #10 Return 0 as the hardware does not support interrupt post action handling. */
  return 0u;
}


/***********************************************************************************************************************
 *  Os_Hal_IntPostAction()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_IntPostAction,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRPOSTACTIONAVAILABILITY */
{
  /* #10 Nothing to do on this hardware. */
  OS_IGNORE_UNREF_PARAM(IsrConfig);                                                                                     /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}


/***********************************************************************************************************************
 *  Os_Hal_IntPostActionMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_IntPostActionMapped,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRPOSTACTIONAVAILABILITY */
{
  /* #10 Nothing to do on this hardware. */
  OS_IGNORE_UNREF_PARAM(IsrConfig);                                                                                     /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* OS_HAL_INTERRUPTCONTROLLER_GIC_NESTED_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_InterruptController_GIC_Nested.h
 *********************************************************************************************************************/
