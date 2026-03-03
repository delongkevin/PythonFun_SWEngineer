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
 *  \file    Os_Hal_InterruptController_GICv3.h
 *  \brief   HAL interface to work with the ARM Generic Interrupt Controller (GICv3).
 *  \details
 *           The GICv3 consists of two components:
 *           - The GIC CPU interface, which exists for each core which is connected to the GIC.
 *             Each core sees its CPU interface aliased on the same base address.
 *           - The GIC Distributor, which receives interrupts from devices and sends them to the CPU interfaces.
 *
 *      As GICv4 is an extension of GICv3.0 and GIC3.1, GICv4 should also be supported by this implementation.
 *      GIC is implemeneted without the export interface, The GIC distributor does not provide a memory
 *      mapped bus interface for configuring the GIC distributor on behalf of the external device.
 *
 *      As there are multiple hardware configurations for the hardware the current GIC implementation is for the R52.
 *      Security externsion is also not supported as the R52 does not have the security externsion and therefore
 *      has only two interrupt groups.
 *
 *      The Cortex-R52 processor does not support the following GIC version 3 features:
 *      - 1of N interrupt distribution.
 *      - Locality-specific Peripheral Interrupts (LPIs).
 *      - Interrupt Translation Service (ITS).
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

#ifndef  OS_HAL_INTERRUPTCONTROLLER_GICV3_H
# define OS_HAL_INTERRUPTCONTROLLER_GICV3_H
                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! The interrupt controller lowest implementation defined priority R52  */
# define OS_HAL_INTC_GIC_R52_LOWEST_PRIORITY               0xF8uL

/*! \brief    Logical interrupt level used for tasks.
 *  \details  The logically lowest interrupt level. */
# define OS_HAL_TASK_LEVEL                                  OS_HAL_INTC_GIC_R52_LOWEST_PRIORITY

/*! Interrupt ID which encodes a the legacy interrupt. */
# define OS_HAL_INTC_GIC_LEGACY_INTERRUPT_ID                (1022uL)

/*! Interrupt ID which encodes a spurious interrupt. */
/*  The values is returned in response to an interrupt acknowledge, if there is no pending interrupt with sufficient
 *  priority for it to be signaled to the PE, of if the highest priority pending interrupt is not appropriate for the:
 *  - Current security state
 *  - Interrupt group that is associated with the System register */
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

/*! The interrupt controller Register write pending mask. */
# define OS_HAL_INTC_GIC_RWP_MASK                           1uL << 31uL

/*! The interrupt controller Regiter processor sleep mask */
# define OS_HAL_INTC_GIC_PROCESSOR_SLEEP                    1uL << 1uL

/*! The interrupt controller Register Children sleep mask */
# define OS_HAL_INTC_GIC_CHILDREN_SLEEP                     1uL << 2uL

/*! The interrupt controller number of interrupts per register group  */
# define OS_HAL_INTC_GIC_R52_PRIORITY_COUNT_PER_GROUP       4u

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_Hal_IntcGetGicDistributorBase()
 **********************************************************************************************************************/
/*! \brief        Returns the Implementation defined GIC interrupt controller distributor base address.
 *  \details      Read from coprocessor register.
 *  \return       Base address value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_IntcGetGicDistributorBase()  Os_Hal_ReadFromCoprocessor(15, 1, 15, 3, 0)

/***********************************************************************************************************************
 *  Os_Hal_IntcSetIccIgrpen0()
 **********************************************************************************************************************/
/*! \brief        Set Interrupt controller Interrupt Group 0 Enable register (ICC_IGRPEN0).
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written(1 to enable and 0 to disable).
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_IntcSetIccIgrpen0(Value)   Os_Hal_WriteToCoprocessor(Value, 15, 0, 12, 12, 6)

/***********************************************************************************************************************
 *  Os_Hal_IntcSetIccIgrpen1()
 **********************************************************************************************************************/
/*! \brief        Set Interrupt controller Interrupt Group 1 Enable register (ICC_IGRPEN1).
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written(1 to enable and 0 to disable).
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_IntcSetIccIgrpen1(Value)   Os_Hal_WriteToCoprocessor(Value, 15, 0, 12, 12, 7)

/***********************************************************************************************************************
 *  Os_Hal_IntcGetIccIAR0()
 **********************************************************************************************************************/
/*! \brief        Get Interrupt Controller Interrupt Acknowledge Register (ICC_IAR0).
 *  \details      Read from coprocessor register.
 *  \return       Interrupt id.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_IntcGetIccIAR0()    Os_Hal_ReadFromCoprocessor(15, 0, 12, 8, 0)

/***********************************************************************************************************************
 *  Os_Hal_IntcSetEOIR0()
 **********************************************************************************************************************/
/*! \brief        Set Interrupt controller End Of Interrupt register (ICC_EOIR0).
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_IntcSetEOIR0(Value)     Os_Hal_WriteToCoprocessor(Value, 15, 0, 12, 8, 1)

/***********************************************************************************************************************
 *  Os_Hal_IntcGetIccIAR1()
 **********************************************************************************************************************/
/*! \brief        Get Interrupt Controller Interrupt Acknowledge Register  (ICC_IAR1).
 *  \details      Read from coprocessor register.
 *  \return       Interrupt id.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_IntcGetIccIAR1()    Os_Hal_ReadFromCoprocessor(15, 0, 12, 12, 0)

/***********************************************************************************************************************
 *  Os_Hal_IntcSetEOIR1()
 **********************************************************************************************************************/
/*! \brief        Set Interrupt controller End Of Interrupt register (ICC_EOIR1).
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_IntcSetEOIR1(Value)     Os_Hal_WriteToCoprocessor(Value, 15, 0, 12, 12, 1)

/***********************************************************************************************************************
 *  Os_Hal_IntcGetIccPmr()
 **********************************************************************************************************************/
/*! \brief        Get Interrupt Controller Priority Mask Register  (ICC_PMR)
 *  \details      Read from coprocessor register.
 *  \return       Priority Mask.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_IntcGetIccPmr()    Os_Hal_ReadFromCoprocessor(15, 0, 4, 6, 0)

/***********************************************************************************************************************
 *  Os_Hal_IntcSetIccPmr()
 **********************************************************************************************************************/
/*! \brief        Set Interrupt Controller Priority Mask Register  (ICC_PMR)
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_IntcSetIccPmr(Value)     Os_Hal_WriteToCoprocessor(Value, 15, 0, 4, 6, 0)

/***********************************************************************************************************************
 *  Os_Hal_IntcGetIccBpr0()
 **********************************************************************************************************************/
/*! \brief        Get Interrupt Controller Binary Point Register  (ICC_BPR0)
 *  \details      Read from coprocessor register.
 *  \return       Binary Point.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_IntcGetIccBpr0()    Os_Hal_ReadFromCoprocessor(15, 0, 12, 8, 3)

/***********************************************************************************************************************
 *  Os_Hal_IntcSetIccBpr0()
 **********************************************************************************************************************/
/*! \brief        Set Interrupt Controller Binary Point Register  (ICC_BPR0)
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_IntcSetIccBpr0(Value)     Os_Hal_WriteToCoprocessor(Value, 15, 0, 12, 8, 3)

/***********************************************************************************************************************
 *  Os_Hal_IntcGetIccBpr1()
 **********************************************************************************************************************/
/*! \brief        Get Interrupt Controller Binary Point Register  (ICC_BPR1)
 *  \details      Read from coprocessor register.
 *  \return       Binary Point.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_IntcGetIccBpr1()    Os_Hal_ReadFromCoprocessor(15, 0, 12, 12, 3)

/***********************************************************************************************************************
 *  Os_Hal_IntcSetIccBpr1()
 **********************************************************************************************************************/
/*! \brief        Set Interrupt Controller Binary Point Register  (ICC_BPR1)
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_IntcSetIccBpr1(Value)     Os_Hal_WriteToCoprocessor(Value, 15, 0, 12, 12, 3)

/***********************************************************************************************************************
 *  Os_Hal_IntcDisGetImpCbar()
 **********************************************************************************************************************/
/*! \brief        Get Configuration Base Address Register  (IMP_CBAR)
 *  \details      Read from coprocessor register.
 *  \return       Base Address.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          EL1 or EL2 Exception level
 **********************************************************************************************************************/
# define Os_Hal_IntcDisGetImpCbar()     Os_Hal_ReadFromCoprocessor(15, 1, 15, 3, 0)

/*! Distributor base address. */
# define OS_HAL_INTC_GIC_DISTRIBUTOR   ((volatile Os_Hal_IntcGicDistributorType *)Os_Hal_IntcDisGetImpCbar())

/*! ReDistributor base address. */
# define OS_HAL_INTC_GIC_REDISTRIBUTOR   ((volatile Os_Hal_IntcGicReDistributorType *)(Os_Hal_IntcDisGetImpCbar()  \
                                         + 0x100000uL + (((Os_Hal_GetMultiprocessorIdRegister())%(4u)) * 0x20000uL)))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! GICv3 CPU interface register map. */
/* Registers are not memory mapped in R52 and need to accessed over the system register access interface*/
typedef struct
{
  uint32 Ctlr;            /*!< Offset: 0x0000       CPU Interface Control Register (GICC_CTLR). */
  uint32 Pmr;             /*!< Offset: 0x0004       Interrupt Priority Mask Register (GICC_PMR). */
  uint32 Bpr;             /*!< Offset: 0x0008       Binary Point Register (GICC_BPR). */
  uint32 Iar;             /*!< Offset: 0x000C       Interrupt Acknowledge Register (GICC_IAR). */
  uint32 Eoir;            /*!< Offset: 0x0010       End of Interrupt Register (GICC_EOIR). */
  uint32 Rpr;             /*!< Offset: 0x0014       Running Priority Register (GICC_RPR). */
  uint32 Hppir;           /*!< Offset: 0x0018       Highest Pending Interrupt Register (GICC_HPPIR). */
  uint32 Apbr;            /*!< Offset: 0x001C       Aliased Binary Point Register (GICC_ABPR). */
  uint32 Aiar;            /*!< Offset: 0x0020       Aliased Interrupt Acknowledge Register (GICC_AIAR). */
  uint32 Aeoir;           /*!< Offset: 0x0024       Aliased End of Interrupt Register (GICC_AEOIR). */
  uint32 Ahppir;          /*!< Offset: 0x0028       Aliased Highest Pending Interrupt Register (GICC_AHPPIR). */
  uint32 Statusr;         /*!< Offset: 0x002C       Error reporting status register (Optional) (GICC_STATUSR). */
  uint32 Reserved0[4];    /*!< Offset: 0x30-0x3C  Reserved. */
  uint32 Specific0[37];   /*!< Offset: 0x40-0xCF  Implementation specific. */
} Os_Hal_IntcGicCpuInterfaceType;

typedef struct
{
  uint32 Reserved0[32];       /*!< Offset: 0x0000-0x007C   Reserved. */
  uint32 Igroup0;             /*!< Offset: 0x0080          ReDistributor Interrupt Group Register (GICR_IGROUP0). */
  uint32 Reserved1[31];       /*!< Offset: 0x0084-0x00F8   Reserved. */
  uint32 Isenanbler0;         /*!< Offset: 0x0100          Interrupt Set-Enable Register 0 (GICR_ISENABLER0). */
  uint32 Reserved2[31];       /*!< Offset: 0x0104-0x017C   Reserved. */
  uint32 Icenanbler0;         /*!< Offset: 0x0180          Interrupt Clear-Enable Registers 0 (GICR_ICENABLER0). */
  uint32 Reserved3[31];       /*!< Offset: 0x0184-0x01FC   Reserved. */
  uint32 Ispendr0;            /*!< Offset: 0x0200          Interrupt Set-Pending Registers 0 (GICR_ISPENDR0). */
  uint32 Reserved4[31];       /*!< Offset: 0x0204-0x027C   Reserved. */
  uint32 Icpendr0;            /*!< Offset: 0x0280          Interrupt Clear-Pending Registers 0 (GICR_ICPENDR0). */
  uint32 Reserved5[31];       /*!< Offset: 0x0284-0x02FC   Reserved. */
  uint32 Isactiver0;          /*!< Offset: 0x0300          Interrupt Set-Active Registers 0 (GICR_ISACTIVER0). */
  uint32 Reserved6[31];       /*!< Offset: 0x0304-0x037C   Reserved. */
  uint32 Icactiver0;          /*!< Offset: 0x0380          Interrupt Clear-Active Registers 0 (GICR_ICACTIVER0). */
  uint32 Reserved7[31];       /*!< Offset: 0x0384-0x03FC   Reserved. */
  uint32 Ipriorityr[8];       /*!< Offset: 0x0400-0x041C   Interrupt Priority Registers 0-7 (GICR_IPRIORITYRn). */
  uint32 Reserved8[504];      /*!< Offset: 0x0420-0xBFC    Reserved. */
  uint32 Icfgr[2];            /*!< Offset: 0x0C00-0x0C04   Interrupt Configuration Registers 0-1 (GICR_ICFGRn). */
} Os_Hal_IntcGicReDistributorCoreType;

/*! GICv3 ReDistributor register map. */
typedef struct
{
  uint32 Ctlr;                /*!< Offset: 0x0000          ReDistributor Control Register (GICR_CTLR). */
  uint32 Iidr;                /*!< Offset: 0x0004          ReDistributor Implementer Identification Register (GICR_IIDR). */
  uint32 Typer[2];            /*!< Offset: 0x0008-0x000C   ReDistributor Type Register core0 and core1 (GICR_TYPERn). */
  uint32 Reserved0;           /*!< Offset: 0x0010          Reserved. */
  uint32 Waker;               /*!< Offset: 0x0014          ReDistributor Wake Register (GICR_WAKER). */
  uint32 Reserved1[16366];    /*!< Offset: 0x0018-0xFFCC   Reserved. */
 /* Offsets seem to wrong in manual, following incremental offsets */
  uint32 Pidr0;               /*!< Offset: 0xFFE0          Peripheral ID0 register. */
  uint32 Pidr1;               /*!< Offset: 0xFFE4          Peripheral ID1 register. */
  uint32 Pidr2;               /*!< Offset: 0xFFE8          Peripheral ID2 register. */
  uint32 Pidr3;               /*!< Offset: 0xFFEC          Peripheral ID3 register. */
  uint32 Pidr4;               /*!< Offset: 0xFFD0          Peripheral ID4 register. */
  uint32 Pidr5;               /*!< Offset: 0xFFD4          Peripheral ID5 register. */
  uint32 Pidr6;               /*!< Offset: 0xFFD8          Peripheral ID6 register. */
  uint32 Pidr7;               /*!< Offset: 0xFFDC          Peripheral ID7 register. */
  uint32 Cidr0;               /*!< Offset: 0xFFF0          Component ID0 register.  */
  uint32 Cidr1;               /*!< Offset: 0xFFF4          Component ID1 register.  */
  uint32 Cidr2;               /*!< Offset: 0xFFF8          Component ID2 register.  */
  uint32 Cidr3;               /*!< Offset: 0xFFFC          Component ID3 register.  */
  Os_Hal_IntcGicReDistributorCoreType Core; /*!< Offset: 0x10000-0x10C04 */
} Os_Hal_IntcGicReDistributorType;

/*! GICv3 Distributor register map. */
typedef struct
{
  uint32 Ctlr;                /*!< Offset: 0x0000          Distributor Control Register (GICD_CTLR). */
  uint32 Typer;               /*!< Offset: 0x0004          Interrupt Controller Type Register (GICD_TYPER). */
  uint32 Iidr;                /*!< Offset: 0x0008          Distributor Implementer Identification Register (GICD_IIDR). */
  uint32 Reserved0[29];       /*!< Offset: 0x000C-0x007C   Reserved. */
  uint32 Igroupr[31];         /*!< Offset: 0x0080-0x00F8   Interrupt Group Registers 1-30 (GICD_IGROUPRn). */
  uint32 Reserved2;           /*!< Offset: 0x00FC          Reserved. */
  uint32 Isenanbler[31];      /*!< Offset: 0x0100-0x0178   Interrupt Set-Enable Registers 1-30 (GICD_ISENABLERn). */
  uint32 Reserved3;           /*!< Offset: 0x017C          Reserved. */
  uint32 Icenanbler[31];      /*!< Offset: 0x0180-0x01F8   Interrupt Clear-Enable Registers 1-30 (GICD_ICENABLERn). */
  uint32 Reserved4;           /*!< Offset: 0x01FC          Reserved. */
  uint32 Ispendr[31];         /*!< Offset: 0x0200-0x0278   Interrupt Set-Pending Registers 1-30 (GICD_ISPENDRn). */
  uint32 Reserved5;           /*!< Offset: 0x027C          Reserved. */
  uint32 Icpendr[31];         /*!< Offset: 0x0280-0x02F8   Interrupt Clear-Pending Registers 1-30 (GICD_ICPENDRn). */
  uint32 Reserved6;           /*!< Offset: 0x02FC          Reserved. */
  uint32 Isactiver[31];       /*!< Offset: 0x0300-0x0378   Interrupt Set-Active Registers 1-30 (GICD_ISACTIVERn). */
  uint32 Reserved7;           /*!< Offset: 0x037C          Reserved. */
  uint32 Icactiver[31];       /*!< Offset: 0x0380-0x03F8   Interrupt Clear-Active Registers 1-30 (GICD_ICACTIVERn). */
  uint32 Reserved8;           /*!< Offset: 0x03FC          Reserved. */
  uint32 Ipriorityr[248];     /*!< Offset: 0x0400-0x07DF   Interrupt Priority Registers 8-247 (GICD_IPRIORITYRn). */
  uint32 Reserved9[264];      /*!< Offset: 0x07E0-0xBFC    Reserved. */
  uint32 Icfgr[62];           /*!< Offset: 0x0C00-0x0CF4   Interrupt Configuration Registers 2-61 (GICD_ICFGRn). */
  uint32 Reserved10[5314];    /*!< Offset: 0x0CF8-0x5FFC   Reserved. */
  uint64 Irouter[992];        /*!< Offset: 0x6000-0x7EF8   Interrupt Routing Registers 32-991 (GICD_IROUTERn). */
  uint32 Reserved11[8248];    /*!< Offset: 0x7F00-0xFFDC   Reserved. */
  uint32 Pidr0;               /*!< Offset: 0xFFE0          Peripheral ID0 register. */
  uint32 Pidr1;               /*!< Offset: 0xFFE4          Peripheral ID1 register. */
  uint32 Pidr2;               /*!< Offset: 0xFFE8          Peripheral ID2 register. */
  uint32 Pidr3;               /*!< Offset: 0xFFEC          Peripheral ID3 register. */
  uint32 Pidr4;               /*!< Offset: 0xFFD0          Peripheral ID4 register. */
  uint32 Pidr5;               /*!< Offset: 0xFFD4          Peripheral ID5 register. */
  uint32 Pidr6;               /*!< Offset: 0xFFD8          Peripheral ID6 register. */
  uint32 Pidr7;               /*!< Offset: 0xFFDC          Peripheral ID7 register. */
  uint32 Cidr0;               /*!< Offset: 0xFFF0          Component ID0 register.  */
  uint32 Cidr1;               /*!< Offset: 0xFFF4          Component ID1 register.  */
  uint32 Cidr2;               /*!< Offset: 0xFFF8          Component ID2 register.  */
  uint32 Cidr3;               /*!< Offset: 0xFFFC          Component ID3 register.  */
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_InitIntVectors,
(
  P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Core
))
{
  OS_IGNORE_UNREF_PARAM(Core);                                                                                          /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Enable Group 0(FIQ) and Group 1(IRQ) Interrupts from the Distributor to the CPU Interface. */
  OS_HAL_INTC_GIC_DISTRIBUTOR->Ctlr |= (uint32)0x13u;                                                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */

  /* #20 Wait till the write progress is guaranteed. */
  while(((OS_HAL_INTC_GIC_DISTRIBUTOR->Ctlr) & (OS_HAL_INTC_GIC_RWP_MASK)) != 0x0uL)                                    /* COV_OS_HALPLATFORMINVSTATE */ /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */ /* FETA_OS_HAL_ARM_GICV3INIT */
  {
    /* Wait */
  }

  /* #30 Initialize the Redistributor, target is not in Processor Sleep state */
  OS_HAL_INTC_GIC_REDISTRIBUTOR->Waker &= ~(uint32)(OS_HAL_INTC_GIC_PROCESSOR_SLEEP);                                   /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */

  /* #40 Wait till all interfaces to the connected target are not quiescent. */
  while(((OS_HAL_INTC_GIC_REDISTRIBUTOR->Waker) & (OS_HAL_INTC_GIC_CHILDREN_SLEEP)) != 0x0uL)                           /* COV_OS_HALPLATFORMINVSTATE */ /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */ /* FETA_OS_HAL_ARM_GICV3INIT */
  {
    /* Wait */
  }

  /* #50 Configure interrupts of any priority to be signaled to the processor. (Set ICCPMR to 0xF8). */
  Os_Hal_IntcSetIccPmr(OS_HAL_INTC_GIC_R52_LOWEST_PRIORITY);

  /* #60 Write to the BPR0 and BPR1 to enable preemption for the Group0 and Group1 interrupts on the CPU interface. */
  Os_Hal_IntcSetIccBpr0(0x0uL);
  Os_Hal_IntcSetIccBpr1(0x0uL);

  /* #70 Write to the IGRPEN0 and IGRPEN1 to enable the Group0 and Group1 interrupts in the CPU interface. */
  Os_Hal_IntcSetIccIgrpen0(0x1uL);
  Os_Hal_IntcSetIccIgrpen1(0x1uL);
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
   uint32 registerBank;
   uint32 sourceRegisterOffset;

   registerBank = (uint32)((InterruptConfig->Source) / OS_HAL_INTC_GIC_R52_PRIORITY_COUNT_PER_GROUP);
   sourceRegisterOffset = (uint32)(8u * ((InterruptConfig->Source) % OS_HAL_INTC_GIC_R52_PRIORITY_COUNT_PER_GROUP));

 /* #10 Edge or level sensitivity is not handled by the OS but by drivers and user software. Do nothing. */

  /* #20 If the interrupt is a PPI, configure the interrupt in the Redistributor*/
 if(InterruptConfig->Source < 32u)
 {
   /* #30 Configure the interrupt group of the given interrupt source. */
   OS_HAL_INTC_GIC_REDISTRIBUTOR->Core.Igroup0 |= (uint32)(0x1uL << (InterruptConfig->Source));                         /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
    /*
    * GICR_IPRIORITYR has 4 interrupt entries per interrupt
    * Each register provide a 5-bit priority field.
    *    [7:3]   priority, byte offset 0
    *    [15:11] priority, byte offset 1
    *    [23:19] priority, byte offset 2
    *    [31:27] priority, byte offset 3
    * Each byte offset's start bit = (8*n + 3)
    */

   /* #40 Configure the interrupt priority of the given interrupt source. */
   OS_HAL_INTC_GIC_REDISTRIBUTOR->Core.Ipriorityr[registerBank] &= (uint32)~(0xFFuL << sourceRegisterOffset);           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
   OS_HAL_INTC_GIC_REDISTRIBUTOR->Core.Ipriorityr[registerBank] |=                                                      /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
                                  (uint32)((Os_Hal_IntLevelType)(InterruptConfig->Level) << sourceRegisterOffset);
 }

  /* #50 Else if the interrupt is a SPI, configure the interrupt in the Distributor. */
 else
 {
   /* #60 Configure interrupt group of the interrupt */
   OS_HAL_INTC_GIC_DISTRIBUTOR->Igroupr[(InterruptConfig->Source)/32u] |=                                               /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
                                          (uint32)(0x1uL << ((InterruptConfig->Source) % 32u));
    /*
    * GICD_IPRIORITYR has 4 interrupt entries per interrupt
    * Each register provide a 5-bit priority field.
    *    [7:3]   priority, byte offset 0
    *    [15:11] priority, byte offset 1
    *    [23:19] priority, byte offset 2
    *    [31:27] priority, byte offset 3
    * Each byte offset's start bit = (8*n + 3)
    */

   /* #70 Configure the interrupt priority of the given interrupt source. */
   OS_HAL_INTC_GIC_DISTRIBUTOR->Ipriorityr[registerBank] &= (uint32)~(0xFFuL << sourceRegisterOffset);                  /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
   OS_HAL_INTC_GIC_DISTRIBUTOR->Ipriorityr[registerBank] |=                                                             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
                                (uint32)((Os_Hal_IntLevelType)(InterruptConfig->Level) << sourceRegisterOffset);

   /* #80 Write to the GICD_IROUTER to set the affinity based routing information for SPI. */
   OS_HAL_INTC_GIC_DISTRIBUTOR->Irouter[InterruptConfig->Source] |= (uint64)InterruptConfig->CoreID;                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
 }
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_EnableSource()
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
Os_Hal_INTC_EnableSource,
(
 Os_Hal_IntSourceType Source,
 Os_Hal_IntLevelType Level,
 Os_Hal_IntControllerType InterruptController
))
{
 OS_IGNORE_UNREF_PARAM(Level);                                                                                         /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
 OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

 /* #10 If the interrupt is a PPI, enable the given interrupt source by writing a 1 to the
        corresponding bit in the Interrupt set-enable Register in the Redistributor. */
 if(Source < 32u)
 {
   OS_HAL_INTC_GIC_REDISTRIBUTOR->Core.Isenanbler0 = (1uL << (Source));                                                /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
 }

 /* #20 Else if the interrupt is a SPI, enable the given interrupt source by writing a 1 to the
        corresponding bit in the Interrupt set-enable Registers in the Distributor. */
 else
 {
   OS_HAL_INTC_GIC_DISTRIBUTOR->Isenanbler[Source/32u] = (1uL << (Source%32u));                                        /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
 }
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_EnableMappedSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
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
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_DisableSource,
(
 P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  /* #10 If the interrupt is a PPI, disable the given interrupt source by writing a 1 to the
        corresponding bit in the Interrupt clear-enable Register in the Redistributor. */
 if(InterruptConfig->Source < 32u)
 {
   OS_HAL_INTC_GIC_REDISTRIBUTOR->Core.Icenanbler0 = (1uL << (InterruptConfig->Source));                               /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
 }

  /* #20 Else if the interrupt is a SPI, disable the given interrupt source by writing a 1 to the
       corresponding bit in the Interrupt clear-enable Registers in the Distributor. */
 else
 {
   OS_HAL_INTC_GIC_DISTRIBUTOR->Icenanbler[InterruptConfig->Source/32u] = (1uL << (InterruptConfig->Source%32u));      /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
 }
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_DisableMappedSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_SetCurrentLevel,
(
 Os_Hal_IntLevelType Level
))
{
  /* #10 Set interrupt priority mask register to given level. */
  Os_Hal_IntcSetIccPmr(Level);
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_SetCurrentLevelException()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMSETEXCEPTIONCONTEXTAVAILABILITY */
Os_Hal_INTC_SetCurrentLevelException,
(
 Os_Hal_IntLevelType Level
))                                                                                                                      /* COV_OS_HALPLATFORMSETEXCEPTIONCONTEXTAVAILABILITY */
{
  /* #10 Set interrupt priority mask register to given level. */
  Os_Hal_IntcSetIccPmr(Level);
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
  return Os_Hal_IntcGetIccPmr();
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_GetCurrentLevelException()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntLevelType, OS_CODE, OS_ALWAYS_INLINE,                            /* COV_OS_HALPLATFORMSETEXCEPTIONCONTEXTAVAILABILITY */
Os_Hal_INTC_GetCurrentLevelException,
(
 void
))
{
  /* #10 Return current value of interrupt priority mask register. */
  return Os_Hal_IntcGetIccPmr();
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_ClearPending()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_ClearPending,
(
 Os_Hal_IntSourceType Source,
 Os_Hal_IntIsrSenderCoreID SenderCoreID,
 Os_Hal_IntControllerType InterruptController
))
{
 OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 If the interrupt is a PPI, clear the interrupt in the Redistributor. */
 if(Source < 32u)
 {
   /* #20 Clear the given interrupt source by writing a 1 to the corresponding Clear-pending bit. */
   OS_HAL_INTC_GIC_REDISTRIBUTOR->Core.Icpendr0 = (1uL << (Source));                                                   /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */

   /* #30 Signal end of interrupt for the given source. */
   Os_Hal_INTC_EndOfInterrupt(Source, SenderCoreID);
 }
  /* #40 Else if the interrupt is a SPI, clear the interrupt in the distributor. */
 else
 {
   /* #50 Clear the given interrupt source by writing a 1 to the corresponding Clear-pending bit. */
   OS_HAL_INTC_GIC_DISTRIBUTOR->Icpendr[Source/32u] = (1uL << (Source%32u));                                           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */

   /* #60 Signal end of interrupt for the given source. */
   Os_Hal_INTC_EndOfInterrupt(Source, SenderCoreID);
 }

}

/***********************************************************************************************************************
 *  Os_Hal_INTC_EndOfInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
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
  OS_IGNORE_UNREF_PARAM(SenderCoreID);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

 /* #10 Write source ID to ICCEOIR to signal end of interrupt to the GICD */
  Os_Hal_IntcSetEOIR1(Source);

 /* #20 If the interrupt is a PPI, assert interrupt deactivation by writing a 1 to the
        corresponding bit in the Interrupt clear-active Register in the Redistributor. */
 if(Source < 32u)
 {
   OS_HAL_INTC_GIC_REDISTRIBUTOR->Core.Icactiver0 = (1uL << (Source));                                                  /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
 }

 /* #30 Else if the interrupt is a SPI, assert interrupt deactivation by writing a 1 to the
        corresponding bit in the Interrupt clear-active Registers in the Distributor. */
 else
 {
   OS_HAL_INTC_GIC_DISTRIBUTOR->Icactiver[Source/32u] = (1uL << (Source%32u));                                          /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
 }
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IntEndOfInterruptMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
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
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_TriggerPeripheralInterrupt,
(
 Os_Hal_IntSourceType Source,
 Os_Hal_IntControllerType InterruptController
))
{
 OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

 /* #10 If the interrupt is a PPI, trigger the given interrupt source by writing a 1 to the
        corresponding bit in the Interrupt Set-pending Register in the Redistributor. */
 if(Source < 32u)                                                                                                      /* COV_OS_HALPLATFORMTRIGGERPERIPHERALINTERRUPT */
 {
   OS_HAL_INTC_GIC_REDISTRIBUTOR->Core.Ispendr0 = (1uL << (Source));                                                   /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
 }

 /* #20 Else if the interrupt is a SPI, trigger the given interrupt source by writing a 1 to the
        corresponding bit in the Interrupt Set-pending Registers in the Distributor. */
 else
 {
   OS_HAL_INTC_GIC_DISTRIBUTOR->Ispendr[Source/32u] = (1uL << (Source%32u));                                           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
 }

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
  OS_IGNORE_UNREF_PARAM(CoreID);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Trigger a SPI using the GIC Distributor.*/
  OS_HAL_INTC_GIC_DISTRIBUTOR->Ispendr[Source/32u] = (1uL << (Source%32u));                                             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IsInterruptSourceEnabled()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
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
 uint32 isEnabled;
 isEnabled = 0u;                                                                                                        /* PRQA S 2982 */ /* MD_Os_Rule2.2_2982 */

 /* #10 If the interrupt is a PPI return whether an interrupt is enabled by inspecting the
        corresponding bit in the Interrupt Clear-Enable Register in the Redistributor. */
 if(InterruptConfig->Source < 32u)
 {
   isEnabled = ((OS_HAL_INTC_GIC_REDISTRIBUTOR->Core.Icenanbler0 & (1uL << (InterruptConfig->Source))) != 0uL);         /* PRQA S 0303, 4404 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_C90BooleanCompatibility */
 }

 /* #20 Else if the interrupt is a SPI return whether an interrupt is enabled by inspecting the
        corresponding bit in the Interrupt Clear-Enable Registers in the Distributor. */
 else
 {
   isEnabled = ((OS_HAL_INTC_GIC_DISTRIBUTOR->Icenanbler[InterruptConfig->Source/32u] &                                 /* PRQA S 0303, 4404 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_C90BooleanCompatibility */ /* SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR */
                                        (1uL << (InterruptConfig->Source%32u))) != 0uL);
 }

  return (Os_StdReturnType)(isEnabled);
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
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IsInterruptPending,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
 uint32 isPending;
 isPending = 0u;                                                                                                        /* PRQA S 2982 */ /* MD_Os_Rule2.2_2982 */

 /* #10 If the interrupt is a PPI return whether an interrupt is pending at the given interrupt source by reading the
        corresponding bit in the Interrupt Clear-Pending Registers in the Redistributor. */
 if(InterruptConfig->Source < 32u)
 {
   isPending = ((OS_HAL_INTC_GIC_REDISTRIBUTOR->Core.Icpendr0 & (1uL << (InterruptConfig->Source))) != 0u);             /* PRQA S 0303, 4404 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_C90BooleanCompatibility */
 }

 /* #20 Else if the interrupt is a SPI return whether an interrupt is pending at the given interrupt source by reading
        the corresponding bit in the Interrupt Clear-Pending Registers in the Distributor. */
 else
 {
   isPending = ((OS_HAL_INTC_GIC_DISTRIBUTOR->Icpendr[InterruptConfig->Source/32u] &                                    /* PRQA S 0303, 4404 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_C90BooleanCompatibility */
      (1uL << (InterruptConfig->Source%32u))) != 0u);
 }

  return (Os_StdReturnType)(isPending);
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
  /* #10 Return !0 (clear pending interrupt is always possible). */
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IrqHandler,
(
  uint32 Address,
  uint32 IsPrivileged
))
{
  volatile uint32 irqNumber;
  volatile uint32 icciar;

  extern CONST(Os_Hal_Core2InterruptVectorTableType, OS_CONST) OsCfg_Hal_Core2InterruptVectorTable[];                   /* PRQA S 3684 */ /* MD_Os_Rule8.11_3684_LinkerSymbol */

  P2CONST(Os_Hal_IntcIrqSourceConfigType, AUTOMATIC, OS_CONST) interruptVectorTable =
      OsCfg_Hal_Core2InterruptVectorTable[Os_Hal_CoreGetId()];

  /* #10 Get the interrupt source and sender core ID to acknowledge the interrupt (read ICCIAR). */

  icciar = Os_Hal_IntcGetIccIAR1();
  irqNumber = icciar & OS_HAL_INTC_GIC_IRQID_ACKNOWLEDGE_MASK;

  /* #20 If the interrupt has been a spurious interrupt, ignore it. */
  if(OS_UNLIKELY(irqNumber == OS_HAL_INTC_GIC_SPURIOUS_INTERRUPT_ID))                                                   /* COV_OS_HALPLATFORMSPURIOUSINTERRUPT */
  {
    ;
  }
  /* #30 Otherwise: */
  else
  {
    /* #40 Store the sender core ID in the interrupt configuration (will be used at end of interrupt). */

    switch(interruptVectorTable[irqNumber].InterruptType)
    {
      /* #50 If the ISR is a category 2 ISR call kernel function and pass pointer to ISR configuration object. */
      case OS_HAL_ISR_CAT2:
        {
          P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) pIsrConfig =
            (const Os_IsrConfigType*)interruptVectorTable[irqNumber].Data.IsrConfigRef;                                 /* PRQA S 0316 */ /* MD_Os_Hal_Rule11.5_0316 */
             Os_IsrRun(pIsrConfig);                                                                                     /* SBSW_OS_HAL_FC_ISRCONFIG_GIC */
        }
        break;

      /* #60 If the ISR is a category 1 or 0 ISR call its function. */
      case OS_HAL_ISR_CAT0:
      case OS_HAL_ISR_CAT1:
        interruptVectorTable[irqNumber].Data.Cat1IsrFunction();                                                         /* SBSW_OS_HAL_FPC_ISRCONFIG_GIC */
        break;

      /* #70 Otherwise the ISR has not been configured, call the default handler and pass the interrupt ID. */
      case OS_HAL_ISR_UNHANDLED:
      default:                                                                                                          /* COV_OS_HALPLATFORMGICINVSTATE */
        Os_UnhandledIrq(irqNumber, (Os_AddressOfConstType)Address, (boolean)IsPrivileged);                              /* PRQA S 0326, 4340 */ /* MD_Os_Rule11.6_0326, MD_Os_C90BooleanCompatibility */ /* SBSW_OS_HAL_FC_POINTER2CONST */
        break;                                                                                                          /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
    }
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
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

#endif /* OS_HAL_INTERRUPTCONTROLLER_GICV3_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_InterruptController_GICv3.h
 *********************************************************************************************************************/
