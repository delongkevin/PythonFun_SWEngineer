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
 *              File: Os_Hal_MemoryProtection_Lcfg.c
 *   Generation Time: 2024-12-20 23:47:40
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_MEMORYPROTECTION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_MemoryProtection_Cfg.h"
#include "Os_Hal_MemoryProtection_Lcfg.h"
#include "Os_Hal_MemoryProtection.h"

/* Os kernel module dependencies */

/* Os hal dependencies */


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

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL memory protection configuration data: OsCore0 */
OS_LOCAL CONST(Os_Hal_MpRegionType, OS_CONST) OsCfg_Hal_Mp_OsCore0_Regions[13] =
{
  {
    /* .RegionNumber                            = */ 0x00000000u,
    /* .RegionBaseAddress                       = */ (uint32)0x00000000u,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(31u) | OS_HAL_MP_REGION_SIZE_ENABLE, /* 2^31 = 2 GB */
    /* .RegionAccessControl                     = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | OS_HAL_MP_ACCESS_TYPE_STRONGLY_ORDERED
  }
,
  {
    /* .RegionNumber                            = */ 0x00000001u,
    /* .RegionBaseAddress                       = */ (uint32)0x00000000u,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(15u) | OS_HAL_MP_REGION_SIZE_ENABLE, /* 2^15 = 32 kB */
    /* .RegionAccessControl                     = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE
  }
,
  {
    /* .RegionNumber                            = */ 0x00000002u,
    /* .RegionBaseAddress                       = */ (uint32)0x41000000u,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(18u) | OS_HAL_MP_REGION_SIZE_ENABLE, /* 2^18 = 256 kB */
    /* .RegionAccessControl                     = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE
  }
,
  {
    /* .RegionNumber                            = */ 0x00000003u,
    /* .RegionBaseAddress                       = */ (uint32)0x41C00000u,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(20u) | OS_HAL_MP_REGION_SIZE_ENABLE, /* 2^20 = 1 MB */
    /* .RegionAccessControl                     = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE
  }
,
  {
    /* .RegionNumber                            = */ 0x00000004u,
    /* .RegionBaseAddress                       = */ (uint32)0x41C00000u,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(14u) | OS_HAL_MP_REGION_SIZE_ENABLE, /* 2^14 = 16 kB */
    /* .RegionAccessControl                     = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | OS_HAL_MP_ACCESS_SHAREABLE | OS_HAL_MP_ACCESS_TYPE_NON_CACHEABLE
  }
,
  {
    /* .RegionNumber                            = */ 0x00000005u,
    /* .RegionBaseAddress                       = */ (uint32)0xD0000000u,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(19u) | OS_HAL_MP_REGION_SIZE_ENABLE, /* 2^19 = 512 kB */
    /* .RegionAccessControl                     = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | OS_HAL_MP_ACCESS_TYPE_NON_CACHEABLE
  }
,
  {
    /* .RegionNumber                            = */ 0x00000006u,
    /* .RegionBaseAddress                       = */ (uint32)0x80000000u,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(28u) | OS_HAL_MP_REGION_SIZE_ENABLE, /* 2^28 = 256 MB */
    /* .RegionAccessControl                     = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | OS_HAL_MP_ACCESS_TYPE_NON_CACHEABLE
  }
,
  {
    /* .RegionNumber                            = */ 0x00000007u,
    /* .RegionBaseAddress                       = */ (uint32)0x9E000000u,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(25u) | OS_HAL_MP_REGION_SIZE_ENABLE, /* 2^25 = 32 MB */
    /* .RegionAccessControl                     = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | OS_HAL_MP_ACCESS_TYPE_STRONGLY_ORDERED
  }
,
  {
    /* .RegionNumber                            = */ 0x00000008u,
    /* .RegionBaseAddress                       = */ (uint32)0x50000000u,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(27u) | OS_HAL_MP_REGION_SIZE_ENABLE, /* 2^27 = 128 MB */
    /* .RegionAccessControl                     = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE
  }
,
  {
    /* .RegionNumber                            = */ 0x00000009u,
    /* .RegionBaseAddress                       = */ (uint32)0x57FE0000u,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(17u) | OS_HAL_MP_REGION_SIZE_ENABLE, /* 2^17 = 128 kB */
    /* .RegionAccessControl                     = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | OS_HAL_MP_ACCESS_TYPE_STRONGLY_ORDERED
  }
,
  {
    /* .RegionNumber                            = */ 0x0000000Au,
    /* .RegionBaseAddress                       = */ (uint32)0x97800000u,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(22u) | OS_HAL_MP_REGION_SIZE_ENABLE, /* 2^22 = 4 MB */
    /* .RegionAccessControl                     = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE
  }
,
  {
    /* .RegionNumber                            = */ 0x0000000Bu,
    /* .RegionBaseAddress                       = */ (uint32)0xB6C00000u,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(19u) | OS_HAL_MP_REGION_SIZE_ENABLE, /* 2^19 = 512 kB */
    /* .RegionAccessControl                     = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | OS_HAL_MP_ACCESS_TYPE_NON_CACHEABLE
  }
,
  {
    /* .RegionNumber                            = */ 0x0000000Cu,
    /* .RegionBaseAddress                       = */ (uint32)0x546C0000u,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(7u) | OS_HAL_MP_REGION_SIZE_ENABLE, /* 2^7 = 128 B */
    /* .RegionAccessControl                     = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | OS_HAL_MP_ACCESS_TYPE_NON_CACHEABLE
  }

};

CONST(Os_Hal_MpCoreConfigType, OS_CONST) OsCfg_Hal_Mp_OsCore0 =
{
  /* .MpuRegionCount = */ (uint32)13,
  /* .MpuRegions     = */ OsCfg_Hal_Mp_OsCore0_Regions
};

/*! HAL memory protection configuration data: OsApplication_QM */
OS_LOCAL CONST(Os_Hal_MpRegionType, OS_CONST) OsCfg_Hal_Mp_OsApplication_QM_Regions[2] =
{
  {
    /* .RegionNumber                            = */ 0x0000000Eu,
    /* .RegionBaseAddress                       = */ (uint32)0x41C80000u,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(18u) | OS_HAL_MP_REGION_SIZE_ENABLE, /* 2^18 = 256 kB */
    /* .RegionAccessControl                     = */ OS_HAL_MP_ACCESS_S_RW_U_R | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE
  }
,
  {
    /* .RegionNumber                            = */ 0x0000000Du,
    /* .RegionBaseAddress                       = */ 0uL,                                           /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ 0uL,
    /* .RegionAccessControl                     = */ 0uL,
  },

};

CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_OsApplication_QM =
{
  /* .MpuRegionCount = */ (uint32)2,
  /* .MpuRegions     = */ OsCfg_Hal_Mp_OsApplication_QM_Regions
};

/*! HAL memory protection configuration data: OsApplication_Safety */
OS_LOCAL CONST(Os_Hal_MpRegionType, OS_CONST) OsCfg_Hal_Mp_OsApplication_Safety_Regions[2] =
{
  {
    /* .RegionNumber                            = */ 0x0000000Du,
    /* .RegionBaseAddress                       = */ (uint32)0x41C80000u,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ OS_HAL_MP_REGION_SIZE_POWER_OF_TWO(18u) | OS_HAL_MP_REGION_SIZE_ENABLE, /* 2^18 = 256 kB */
    /* .RegionAccessControl                     = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED | OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE
  }
,
  {
    /* .RegionNumber                            = */ 0x0000000Eu,
    /* .RegionBaseAddress                       = */ 0uL,                                           /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ 0uL,
    /* .RegionAccessControl                     = */ 0uL,
  },

};

CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_OsApplication_Safety =
{
  /* .MpuRegionCount = */ (uint32)2,
  /* .MpuRegions     = */ OsCfg_Hal_Mp_OsApplication_Safety_Regions
};

/*! HAL memory protection configuration data: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_Hal_MpRegionType, OS_CONST) OsCfg_Hal_Mp_OsApplication_Trusted_Core0_Regions[2] =
{
  {
    /* .RegionNumber                            = */ 0x0000000Eu,
    /* .RegionBaseAddress                       = */ 0uL,                                           /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ 0uL,
    /* .RegionAccessControl                     = */ 0uL,
  },

  {
    /* .RegionNumber                            = */ 0x0000000Du,
    /* .RegionBaseAddress                       = */ 0uL,                                           /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ 0uL,
    /* .RegionAccessControl                     = */ 0uL,
  },

};

CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_OsApplication_Trusted_Core0 =
{
  /* .MpuRegionCount = */ (uint32)2,
  /* .MpuRegions     = */ OsCfg_Hal_Mp_OsApplication_Trusted_Core0_Regions
};

/*! HAL memory protection configuration data: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_Hal_MpRegionType, OS_CONST) OsCfg_Hal_Mp_SystemApplication_OsCore0_Regions[2] =
{
  {
    /* .RegionNumber                            = */ 0x0000000Eu,
    /* .RegionBaseAddress                       = */ 0uL,                                           /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ 0uL,
    /* .RegionAccessControl                     = */ 0uL,
  },

  {
    /* .RegionNumber                            = */ 0x0000000Du,
    /* .RegionBaseAddress                       = */ 0uL,                                           /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */
    /* .SubregionsDisableAndRegionSizeAndEnable = */ 0uL,
    /* .RegionAccessControl                     = */ 0uL,
  },

};

CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_SystemApplication_OsCore0 =
{
  /* .MpuRegionCount = */ (uint32)2,
  /* .MpuRegions     = */ OsCfg_Hal_Mp_SystemApplication_OsCore0_Regions
};

/*! HAL memory protection configuration data: ADC0 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_ADC0 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: ADC1 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_ADC1 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Can_30_McanIsr_0 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Can_30_McanIsr_0 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Can_30_McanIsr_1 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Can_30_McanIsr_1 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: CounterIsr_SystemTimer */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CounterIsr_SystemTimer =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: I2c_IrqUnit0 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_I2c_IrqUnit0 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: I2c_IrqUnit1 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_I2c_IrqUnit1 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: IPC_mailbox1 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_IPC_mailbox1 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: IPC_mailbox2 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_IPC_mailbox2 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: MAIN_ESM0_ESM_INT_CFG_LVL_0 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MAIN_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: MAIN_ESM0_ESM_INT_HI_LVL_0 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MAIN_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: MAIN_ESM0_ESM_INT_LOW_LVL_0 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MAIN_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: MCU_ESM0_ESM_INT_CFG_LVL_0 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MCU_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: MCU_ESM0_ESM_INT_HI_LVL_0 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MCU_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: MCU_ESM0_ESM_INT_LOW_LVL_0 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MCU_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SciServer_OsIsr_UserMsgHwiFxn1 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SciServer_OsIsr_UserMsgHwiFxn1 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SciServer_OsIsr_UserMsgHwiFxn2 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SciServer_OsIsr_UserMsgHwiFxn2 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SciServer_OsIsr_UserMsgHwiFxn3 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SciServer_OsIsr_UserMsgHwiFxn3 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SciServer_OsIsr_UserMsgHwiFxn4 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SciServer_OsIsr_UserMsgHwiFxn4 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: WKUP_ESM0_ESM_INT_CFG_LVL_0 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_WKUP_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: WKUP_ESM0_ESM_INT_HI_LVL_0 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_WKUP_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: WKUP_ESM0_ESM_INT_LOW_LVL_0 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_WKUP_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: vHsmResponseIsr */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_vHsmResponseIsr =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: BootAppOsTask */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_BootAppOsTask =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: IdleTask_OsCore0 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_IdleTask_OsCore0 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: QM_ComTask_10ms */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_QM_ComTask_10ms =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: QM_ComTask_5ms */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_QM_ComTask_5ms =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: QM_DiagTask_10ms */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_QM_DiagTask_10ms =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: QM_MemTask_10ms */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_QM_MemTask_10ms =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: QM_Task_00_10ms */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_QM_Task_00_10ms =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: QM_Task_01_10ms */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_QM_Task_01_10ms =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: QM_Task_200ms */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_QM_Task_200ms =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: QM_Task_Init */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_QM_Task_Init =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Safety_Task_00_10ms */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Safety_Task_00_10ms =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Safety_Task_01_10ms */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Safety_Task_01_10ms =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Safety_Task_200ms */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Safety_Task_200ms =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Safety_Task_Init */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Safety_Task_Init =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Safety_WdgTask_10ms */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Safety_WdgTask_10ms =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SciServerHighOsTask */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SciServerHighOsTask =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SciServerLowOsTask */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SciServerLowOsTask =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: ShutdownTask */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_ShutdownTask =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: StartUpTask */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_StartUpTask =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL memory protection configuration data: SystemMpu */
CONST(Os_Hal_MpSystemConfigType, OS_CONST) OsCfg_Hal_Mp_SystemMpu =
{
  /* .Dummy     = */ 0uL,
};

/*! HAL memory protection configuration data: EmptyThread */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EmptyThread =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
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
 *  END OF FILE: Os_Hal_MemoryProtection_Lcfg.c
 *********************************************************************************************************************/
