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
 * \ingroup    Os_Hal
 * \defgroup   Os_Hal_MemoryProtection  HAL Memory Protection
 * \{
 *
 * \brief      Internal functions and data types related to memory protection.
 * \file       Os_Hal_MemoryProtection_PMSAv8Int.h
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_MEMORYPROTECTION_PMSAV8INT_H
# define OS_HAL_MEMORYPROTECTION_PMSAV8INT_H
                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! Description of a single region in the ARM PMSAv7 implementation. */
struct Os_Hal_MpRegionType_Tag
{
  uint32 RegionNumber;         /*!< Region number (PRSELR). */
  uint32 RegionBaseAddress;    /*!< Region base address (PRBAR). */
  uint32 RegionEndAddress;     /*!< Region end address (PRLAR). */
  uint32 RegionAccessControl;  /*!< Region base address (PRBAR). */
  uint32 RegionEnableAndFlags; /*!< Region base address (PRLAR). */
};


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! System Control Register (SCTLR): SCTLR.M bit mask. */
# define OS_HAL_MP_SYSTEMCONTROL_ENABLE_MPU        (0x01uL << 0u)
/*! System Control Register (SCTLR): SCTLR.BR bit mask. */
# define OS_HAL_MP_SYSTEMCONTROL_BACKGROUND_REGION (0x01uL << 17u)

/*! Protection Region Limit Address Register (PRLAR): PRLAR.En bit. */
# define OS_HAL_MP_REGION_SIZE_ENABLE              (0x01uL << 0u)

/*! Protection Region Limit Address Register (PRLAR): PRLAR Address bits. */
# define OS_HAL_MP_REGION_SIZE_ALIGNMENT          ~(uint32)(0x3Fu)

/*! Data Region Size Alignment. */
# define OS_HAL_MP_REGION_SIZE_64BYTE_ALIGNED(x)   ((x) & OS_HAL_MP_REGION_SIZE_ALIGNMENT)

/*! Protection Region Limit Address Register (PRBAR): PRBAR Control bits. */
# define OS_HAL_MP_PRBAR_ACCESS_CONTROL_BITS_MASK  (0x1F)

/*! Protection Region Base Address Register (PRBAR): PRBAR.XN bit, allowed value. */
# define OS_HAL_MP_ACCESS_EXECUTE_ALLOWED          (0x0uL << 0u)
/*! Protection Region Base Address Register (PRBAR): PRBAR.XN bit, forbidden value. */
# define OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN        (0x01uL << 0u)

/*! Protection Region Base Address Register (PRBAR): PRBAR.AP bit.
 *  \details Supervisor: RW- User: ---. */
# define OS_HAL_MP_ACCESS_S_RW_U_NONE              (0x0uL << 1u)
/*! Protection Region Base Address Register (PRBAR): PRBAR.AP bit.
 *  \details Supervisor: RW- User: RW-. */
# define OS_HAL_MP_ACCESS_S_RW_U_RW                (0x01uL << 1u)
/*! Protection Region Base Address Register (PRBAR): PRBAR.AP bit.
 *  \details Supervisor: R-- User: ---. */
# define OS_HAL_MP_ACCESS_S_R_U_NONE               (0x02uL << 1u)
/*! Protection Region Base Address Register (PRBAR): PRBAR.AP bit.
 *  \details Supervisor: R-- User: R--. */
# define OS_HAL_MP_ACCESS_S_R_U_R                  (0x03uL << 1u)

/*! Protection Region Base Address Register (PRBAR): PRBAR.SH field. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_SHAREABLE     (0x02uL << 3u)
/*! Protection Region Base Address Register (PRBAR): PRBAR.SH field. */
# define OS_HAL_MP_ACCESS_TYPE_INNER_SHAREABLE     (0x03uL << 3u)

/* Device memory type: non Gathering, non Re-ordering, non Early Write Acknowledgment. */
# define OS_HAL_MP_ACCESS_TYPE_DEVICE_nGnRnE_MEMORY  (uint8)(0x00u)
/* Device memory type: non Gathering, non Re-ordering, Early Write Acknowledgment. */
# define OS_HAL_MP_ACCESS_TYPE_DEVICE_nGnRE_MEMORY   (uint8)(0x04u)
/* Device memory type: non Gathering, Re-ordering, Early Write Acknowledgment. */
# define OS_HAL_MP_ACCESS_TYPE_DEVICE_nGRE_MEMORY    (uint8)(0x08u)
/* Device memory type: Gathering, Re-ordering, Early Write Acknowledgment. */
# define OS_HAL_MP_ACCESS_TYPE_DEVICE_GRE_MEMORY     (uint8)(0x0Cu)

/* Normal memory. Outer Write-Through transient, read allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_OUTER_WRITETHROUGH_TRANSIENT_READALLOCATE  (uint8)(0x02u << 4u)
/* Normal memory. Outer Write-Through transient, write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_OUTER_WRITETHROUGH_TRANSIENT_WRITEALLOCATE  (uint8)(0x01u << 4u)
/* Normal memory. Outer Write-Through transient, read allocate and write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_OUTER_WRITETHROUGH_TRANSIENT_READALLOCATE_WRITEALLOCATE  (uint8)(0x03u << 4u)

/* Normal Memory. Outer Non-Cacheable. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_OUTER_NON_CACHEABLE   (uint8)(0x04u << 4u)

/* Normal memory. Outer Write-Back transient, read allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_OUTER_WRITEBACK_TRANSIENT_READALLOCATE  (uint8)(0x06u << 4u)
/* Normal memory. Outer Write-Back transient, write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_OUTER_WRITEBACK_TRANSIENT_WRITEALLOCATE  (uint8)(0x05u << 4u)
/* Normal memory. Outer Write-Back transient, read allocate and write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_OUTER_WRITEBACK_TRANSIENT_READALLOCATE_WRITEALLOCATE  (uint8)(0x07u << 4u)

/* Normal memory. Outer Write-Through non-transient, read allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_OUTER_WRITETHROUGH_NONTRANSIENT_READALLOCATE  (uint8)(0x0Au << 4u)
/* Normal memory. Outer Write-Through non-transient, write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_OUTER_WRITETHROUGH_NONTRANSIENT_WRITEALLOCATE  (uint8)(0x09u << 4u)
/* Normal memory. Outer Write-Through non-transient, read allocate and write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_OUTER_WRITETHROUGH_NONTRANSIENT_READALLOCATE_WRITEALLOCATE  (uint8)(0x0Bu << 4u)

/* Normal memory. Outer Write-Back non-transient, read allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_OUTER_WRITEBACK_NONTRANSIENT_READALLOCATE  (uint8)(0x0Eu << 4u)
/* Normal memory. Outer Write-Back non-transient, write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_OUTER_WRITEBACK_NONTRANSIENT_WRITEALLOCATE  (uint8)(0x0Du << 4u)
/* Normal memory. Outer Write-Back non-transient, read allocate and write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_OUTER_WRITEBACK_NONTRANSIENT_READALLOCATE_WRITEALLOCATE  (uint8)(0x0Fu << 4u)

/* Normal memory. Inner Write-Through transient, read allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_WRITETHROUGH_TRANSIENT_READALLOCATE  (uint8)(0x02u)
/* Normal memory. Inner Write-Through transient, write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_WRITETHROUGH_TRANSIENT_WRITEALLOCATE  (uint8)(0x01u)
/* Normal memory. Inner Write-Through transient, read allocate and write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_WRITETHROUGH_TRANSIENT_READALLOCATE_WRITEALLOCATE  (uint8)(0x03u)

/* Normal Memory. Inner Non-Cacheable. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE   (uint8)(0x04u)

/* Normal memory. Inner Write-Back transient, read allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_WRITEBACK_TRANSIENT_READALLOCATE  (uint8)(0x06u)
/* Normal memory. Inner Write-Back transient, write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_WRITEBACK_TRANSIENT_WRITEALLOCATE  (uint8)(0x05u)
/* Normal memory. Inner Write-Back transient, read allocate and write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_WRITEBACK_TRANSIENT_READALLOCATE_WRITEALLOCATE  (uint8)(0x07u)

/* Normal memory. Inner Write-Through non-transient. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_WRITETHROUGH_NONTRANSIENT  (uint8)(0x08u)
/* Normal memory. Inner Write-Through non-transient, read allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_WRITETHROUGH_NONTRANSIENT_READALLOCATE  (uint8)(0x0Au)
/* Normal memory. Inner Write-Through non-transient, write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_WRITETHROUGH_NONTRANSIENT_WRITEALLOCATE  (uint8)(0x09u)
/* Normal memory. Inner Write-Through non-transient, read allocate and write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_WRITETHROUGH_NONTRANSIENT_READALLOCATE_WRITEALLOCATE  (uint8)(0x0Bu)

/* Normal memory. Inner Write-Back non-transient. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_WRITEBACK_NONTRANSIENT  (uint8)(0x0Cu)
/* Normal memory. Inner Write-Back non-transient, read allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_WRITEBACK_NONTRANSIENT_READALLOCATE  (uint8)(0x0Eu)
/* Normal memory. Inner Write-Back non-transient, write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_WRITEBACK_NONTRANSIENT_WRITEALLOCATE  (uint8)(0x0Du)
/* Normal memory. Inner Write-Back non-transient, read allocate and write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_WRITEBACK_NONTRANSIENT_READALLOCATE_WRITEALLOCATE  (uint8)(0x0Fu)

/*! Memory Attribute Indirection Registers 0 and 1 (MAIR0 and MAIR1) bits assignement. */
#define OS_HAL_MP_MAIR0_INIT_VALUE  ((uint32)(((uint32)OS_HAL_MP_MAIR0_ATTR3 << 24u) | \
                                              ((uint32)OS_HAL_MP_MAIR0_ATTR2 << 16u) | \
                                              ((uint32)OS_HAL_MP_MAIR0_ATTR1 << 8u)  | \
                                              (uint32)OS_HAL_MP_MAIR0_ATTR0))
#define OS_HAL_MP_MAIR1_INIT_VALUE  ((uint32)(((uint32)OS_HAL_MP_MAIR1_ATTR7 << 24u) | \
                                              ((uint32)OS_HAL_MP_MAIR1_ATTR6 << 16u) | \
                                              ((uint32)OS_HAL_MP_MAIR1_ATTR5 << 8u)  | \
                                              (uint32)OS_HAL_MP_MAIR1_ATTR4))

/*! Base address of the temporary startup region. */
# define OS_HAL_MP_STARTUP_REGION_BASE            (0x0uL)
/*! End address of the temporary startup region. */
# define OS_HAL_MP_STARTUP_REGION_END             (0xFFFFFFFFuL)
/*! Size of the temporary startup region. */
# define OS_HAL_MP_STARTUP_REGION_SIZE            (0x0uL)

#endif /* OS_HAL_MEMORYPROTECTION_PMSAV8INT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_MemoryProtection_PMSAv8Int.h
 **********************************************************************************************************************/
