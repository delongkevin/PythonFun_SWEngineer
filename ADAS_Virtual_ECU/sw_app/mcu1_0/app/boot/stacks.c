#include <stdlib.h>
#include <stdint.h>
#include <ti/csl/arch/csl_arch.h>
#include "Std_Types.h"


//# pragma SET_DATA_SECTION (".ABT_STACK")
//#pragma RETAIN ( OS_AbtStack )
//volatile uint8         OS_AbtStack[1024];
//# pragma SET_DATA_SECTION ()
//
//# pragma SET_DATA_SECTION (".FIQ_STACK")
//#pragma RETAIN ( OS_FiqStack )
//volatile uint8         OS_FiqStack[1024];
//# pragma SET_DATA_SECTION ()
//
//# pragma SET_DATA_SECTION (".IRQ_STACK")
//#pragma RETAIN ( OS_IrqStack )
//volatile uint8         OS_IrqStack[2048];
//# pragma SET_DATA_SECTION ()
//
//# pragma SET_DATA_SECTION (".SVC_STACK")
//#pragma RETAIN ( OS_SvcStack )
//volatile uint8         OS_SvcStack[2048];
//# pragma SET_DATA_SECTION ()
//
//# pragma SET_DATA_SECTION (".UND_STACK")
//#pragma RETAIN ( OS_UndStack )
//volatile uint8         OS_UndStack[1024];
//# pragma SET_DATA_SECTION ()

const CSL_ArmR5MpuRegionCfg gCslR5MpuCfg[CSL_ARM_R5F_MPU_REGIONS_MAX] =
{
	{
        /* Region 0 configuration: complete 32 bit address space = 4Gbits */
        .regionId         = 0U,
        .enable           = 1U,
        .baseAddr         = 0x0U,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_4GB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 1U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_RD_WR,
        .shareable        = 1U,
        .cacheable        = (uint32_t)FALSE,
        .cachePolicy      = 0U,
        .memAttr          = CSL_ARM_R5_MEM_ATTR_STRONGLY_ORDERED,
    },
	{
        /* Region 0 configuration: complete 32 bit address space = 4Gbits */
        .regionId         = 1U,
        .enable           = 1U,
        .baseAddr         = 0x0U,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_32KB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_RD_WR,
        .shareable        = 1U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
	{
        /* Region 0 configuration: complete 32 bit address space = 4Gbits */
        .regionId         = 2U,
        .enable           = 1U,
        .baseAddr         = 0x41000000U,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_32KB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
	{
        /* Region 0 configuration: complete 32 bit address space = 4Gbits */
        .regionId         = 3U,
        .enable           = 1U,
        .baseAddr         = 0x41010000U,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_32KB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
	{
        /* Region 0 configuration: complete 32 bit address space = 4Gbits */
        .regionId         = 4U,
        .enable           = 1U,
        .baseAddr         = 0x41C00000U,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_1MB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
	{
        /* Region 0 configuration: complete 32 bit address space = 4Gbits */
        .regionId         = 5U,
        .enable           = 1U,
        .baseAddr         = 0x70000000U,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_8MB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
	{
        /* Region 0 configuration: complete 32 bit address space = 4Gbits */
        .regionId         = 6U,
        .enable           = 1U,
        .baseAddr         = 0x80000000U,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_1GB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
        .memAttr          = 0U,
    },
	{
        /* Region 0 configuration: complete 32 bit address space = 4Gbits */
        .regionId         = 7U,
        .enable           = 1U,
        .baseAddr         = 0xAA000000U,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_32MB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 1U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 1U,
        .cacheable        = (uint32_t)FALSE,
        .cachePolicy      = 0U,
        .memAttr          = CSL_ARM_R5_MEM_ATTR_STRONGLY_ORDERED,
    },
    {
        /* Region 6 configuration: Covers first 128MB of EVM Flash (FSS DAT0) */
        .regionId         = 8U,
        .enable           = 1U,
        .baseAddr         = 0x50000000,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_128MB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 0U,
        .cacheable        = (uint32_t)TRUE,
        .cachePolicy      = CSL_ARM_R5_MEM_ATTR_CACHED_WT_NO_WA,
        /*.cacheable        = (uint32_t)FALSE,
        .cachePolicy      = 0U,*/
        .memAttr          = 0U,
    },
	{
        /* Region 0 configuration: complete 32 bit address space = 4Gbits */
        .regionId         = 9U,
        .enable           = 1U,
        .baseAddr         = 0x41C00000U,
        .size             = CSL_ARM_R5_MPU_REGION_SIZE_16KB,
        .subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
        .exeNeverControl  = 0U,
        .accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
        .shareable        = 1U,
        .cacheable        = (uint32_t)FALSE,
        .cachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
        .memAttr          = 0U,
    },
	{
        /* Region 0 configuration: complete 32 bit address space = 4Gbits */
        .regionId         = 10U,
        .enable           = 0U,
        .baseAddr         = 0x00000000U,
        .size             = 0U,
        .subRegionEnable  = 0U,
        .exeNeverControl  = 0U,
        .accessPermission = 0U,
        .shareable        = 0U,
        .cacheable        = 0U,
        .cachePolicy      = 0U,
        .memAttr          = 0U,
    }
};
