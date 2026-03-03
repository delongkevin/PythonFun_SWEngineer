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
 * \file       Os_Hal_MemoryProtection_PMSAv7Int.h
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_MEMORYPROTECTION_PMSAV7INT_H
# define OS_HAL_MEMORYPROTECTION_PMSAV7INT_H
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
  uint32 RegionNumber;        /*!< Region number (RGNR). */
  uint32 RegionBaseAddress;   /*!< Region base address (DRBAR). */
  uint32 RegionSizeAndEnable; /*!< Region size and enable value (DRSR). */
  uint32 RegionAccessControl; /*!< Access control value (DRACR). */
};


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! System Control Register (SCTLR): SCTLR.M bit mask. */
# define OS_HAL_MP_SYSTEMCONTROL_ENABLE_MPU        (1uL <<  0)
/*! System Control Register (SCTLR): SCTLR.BR bit mask. */
# define OS_HAL_MP_SYSTEMCONTROL_BACKGROUND_REGION (1uL << 17)
/*! System Control Register (SCTLR): SCTLR.I, .Z, .C bit mask. */
# define OS_HAL_MP_SYSTEMCONTROL_CACHEING_MASK     (0x00001804uL)

/*! Data Region Size and Enable Register (DRSR): DRSR.En bit. */
# define OS_HAL_MP_REGION_SIZE_ENABLE              (1uL << 0)
/*! Data Region Size and Enable Register (DRSR): DRSR.RSize field. */
# define OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(x)     (((x) - 1u) << 1)
/*! Data Region Size and Enable Register (DRSR): DRSR.SxD Subregion Disable field (x: 0..7). */
# define OS_HAL_MP_SUBREGION_0_DISABLE             (1uL << 8)
# define OS_HAL_MP_SUBREGION_1_DISABLE             (1uL << 9)
# define OS_HAL_MP_SUBREGION_2_DISABLE             (1uL << 10)
# define OS_HAL_MP_SUBREGION_3_DISABLE             (1uL << 11)
# define OS_HAL_MP_SUBREGION_4_DISABLE             (1uL << 12)
# define OS_HAL_MP_SUBREGION_5_DISABLE             (1uL << 13)
# define OS_HAL_MP_SUBREGION_6_DISABLE             (1uL << 14)
# define OS_HAL_MP_SUBREGION_7_DISABLE             (1uL << 15)

/*! Data Region Access Control Register (DRACR): DRACR.S bit. */
# define OS_HAL_MP_ACCESS_SHAREABLE                (1uL << 2)
/*! Data Region Access Control Register (DRACR): DRACR.XN bit, allowed value. */
# define OS_HAL_MP_ACCESS_EXECUTE_ALLOWED          (0uL << 12)
/*! Data Region Access Control Register (DRACR): DRACR.XN bit, forbidden value. */
# define OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN        (1uL << 12)

/*! \brief   Data Region Access Control Register (DRACR): DRACR.AP value.
 *  \details Supervisor: --- User: ---. */
# define OS_HAL_MP_ACCESS_S_NONE_U_NONE              (0uL << 8)
/*! \brief   Data Region Access Control Register (DRACR): DRACR.AP value.
 *  \details Supervisor: RW- User: ---. */
# define OS_HAL_MP_ACCESS_S_RW_U_NONE                (1uL << 8)
/*! \brief   Data Region Access Control Register (DRACR): DRACR.AP value.
 *  \details Supervisor: RW- User: R--. */
# define OS_HAL_MP_ACCESS_S_RW_U_R                   (2uL << 8)
/*! \brief   Data Region Access Control Register (DRACR): DRACR.AP value.
 *  \details Supervisor: RW- User: RW-. */
# define OS_HAL_MP_ACCESS_S_RW_U_RW                  (3uL << 8)
/*! \brief   Data Region Access Control Register (DRACR): DRACR.AP value.
 *  \details Supervisor: R-- User: ---. */
# define OS_HAL_MP_ACCESS_S_R_U_NONE                 (5uL << 8)
/*! \brief   Data Region Access Control Register (DRACR): DRACR.AP value.
 *  \details Supervisor: R-- User: R--. */
# define OS_HAL_MP_ACCESS_S_R_U_R                    (6uL << 8)

/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Strongly ordered. */
# define OS_HAL_MP_ACCESS_TYPE_STRONGLY_ORDERED               ((0uL << 3) | (0uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer and Inner Write-Back, Cacheable. */
# define OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE   ((1uL << 3) | (3uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer and Inner Non-Cacheable. */
# define OS_HAL_MP_ACCESS_TYPE_NON_CACHEABLE                  ((1uL << 3) | (0uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Shared device, Non-cacheable. */
# define OS_HAL_MP_ACCESS_TYPE_SHAREABLE_DEVICE                  ((0uL << 3) | (1uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Non-Shared device, Non-cacheable. */
# define OS_HAL_MP_ACCESS_TYPE_NON_SHAREABLE_DEVICE              ((2uL << 3) | (0uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer and inner write-through, no write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITETHROUGH_NO_ALLOCATE   ((0uL << 3) | (2uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer and inner write-back, no write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITEBACK_NO_ALLOCATE      ((0uL << 3) | (3uL << 0))

/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer non cacheable and inner non cacheable. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_NON_CACHEABLE_INNER_NON_CACHEABLE    ((4uL << 3) | (0uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer non cacheable and inner write-back, write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_NON_CACHEABLE_INNER_WRITEBACK_ALLOCATE    ((4uL << 3) | (1uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer non cacheable and inner write-through, no write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_NON_CACHEABLE_INNER_WRITETHROUGH_NO_ALLOCATE    ((4uL << 3) | (2uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer non cacheable and inner write-back, no write allocate. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_NON_CACHEABLE_INNER_WRITEBACK_NO_ALLOCATE    ((4uL << 3) | (3uL << 0))

/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer write-back, write-allocate and inner non-cacheable. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_WRITEBACK_ALLOCATE_INNER_NON_CACHEABLE    ((5uL << 3) | (0uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer write-back, write-allocate and inner write-back, write-allocate. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_WRITEBACK_ALLOCATE_INNER_WRITEBACK_ALLOCATE    ((5uL << 3) | (1uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer write-back, write-allocate and inner write-through, no write-allocate. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_WRITEBACK_ALLOCATE_INNER_WRITETHROUGH_NO_ALLOCATE    ((5uL << 3) | (2uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer write-back, write-allocate and inner write-back, no write-allocate. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_WRITEBACK_ALLOCATE_INNER_WRITEBACK_NO_ALLOCATE    ((5uL << 3) | (3uL << 0))

/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer write-through, no write-allocate and inner non cacheable. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_WRITETHROUGH_NO_ALLOCATE_INNER_NON_CACHEABLE    ((6uL << 3) | (0uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer write-through, no write-allocate and inner write-back, write-allocate. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_WRITETHROUGH_NO_ALLOCATE_INNER_WRITEBACK_ALLOCATE    ((6uL << 3) | (1uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer write-through, no write-allocate and inner write-through, no write-allocate. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_WRITETHROUGH_NO_ALLOCATE_INNER_WRITETHROUGH_NO_ALLOCATE    ((6uL << 3) | (2uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer write-through, no write-allocate and inner write-back, no write-allocate. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_WRITETHROUGH_NO_ALLOCATE_INNER_WRITEBACK_NO_ALLOCATE    ((6uL << 3) | (3uL << 0))

/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer write-back, no write-allocate and inner non cacheable. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_WRITEBACK_NO_ALLOCATE_INNER_NON_CACHEABLE    ((7uL << 3) | (0uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer write-back, no write-allocate and inner write-back, write-allocate. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_WRITEBACK_NO_ALLOCATE_INNER_WRITEBACK_ALLOCATE    ((7uL << 3) | (1uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer write-back, no write-allocate and inner write-through, no write-allocate. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_WRITEBACK_NO_ALLOCATE_INNER_WRITETHROUGH_NO_ALLOCATE    ((7uL << 3) | (2uL << 0))
/*! \brief   Data Region Access Control Register (DRACR): DRACR.C,B and TEX value
 *  \details Outer write-back, no write-allocate and inner write-back, no write-allocate. */
# define OS_HAL_MP_ACCESS_TYPE_OUTER_WRITEBACK_NO_ALLOCATE_INNER_WRITEBACK_NO_ALLOCATE    ((7uL << 3) | (3uL << 0))

/*! Access rights for the temporary startup region. */
# define OS_HAL_MP_STARTUP_REGION_ACCESSRIGHTS      (OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | \
                                                     OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE | \
                                                     OS_HAL_MP_ACCESS_S_RW_U_RW)

/*! Base address of the temporary startup region. */
# define OS_HAL_MP_STARTUP_REGION_BASE              (0x00000000uL)

/*! End address of the temporary startup region. */
# define OS_HAL_MP_STARTUP_REGION_END               (0xFFFFFFFFuL)

/*! Size of the temporary startup region. */
# define OS_HAL_MP_STARTUP_REGION_SIZE              (OS_HAL_MP_REGION_SIZE_ENABLE | OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(32uL))

#endif /* OS_HAL_MEMORYPROTECTION_PMSAV7INT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_MemoryProtection_PMSAv7Int.h
 **********************************************************************************************************************/
