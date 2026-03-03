/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file  File:  BrsHw.c
 *      Project:  Vector Basic Runtime System
 *       Module:  BrsHw for platform Texas Instruments Jacinto7
 *     Template:  This file is reviewed according to Brs_Template@Implementation[1.02.01]
 *
 *  \brief Description:  This is the hardware specific code file for Vector Basic Runtime System (BRS).
 *
 *  \attention Please note:
 *    The demo and example programs only show special aspects of the software. With regard to the fact
 *    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
 *    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to BrsHw.h.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/

#define _BRSHW_C_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "BrsHw.h"

#if !defined (BRS_ENABLE_FBL_SUPPORT)
  #include "Os.h"
#endif

#if defined (BRS_DERIVATIVE_TDA4VM88)
  #ifndef SOC_J721E
    #define SOC_J721E
  #endif
#elif defined (BRS_DERIVATIVE_TDA4VE88)
  #ifndef SOC_J721S2
    #define SOC_J721S2
  #endif
#endif

#include "ti/drv/sciclient/sciclient.h"
#include "ti/cslr_intr_mcu_r5fss0_core0.h"
#include "ti/gpio.h"
#include "ti/cslr_wkup_ctrl_mmr.h"
#include "ti/cslr_mcu_ctrl_mmr.h"
#include "ti/board/board.h"
#include "ti/csl/arch/r5/csl_arm_r5_mpu.h"

#include "BrsMain.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if (BRSHW_VERSION != 0x0107u)
  #error "Header and source file are inconsistent!"
#endif
#if (BRSHW_BUGFIX_VERSION != 0x00u)
  #error "Different versions of bugfix in Header and Source used!"
#endif

/**********************************************************************************************************************
 *  CONFIGURATION CHECK
 *********************************************************************************************************************/
#if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
#else
  #error "Unknown compiler specified!"
#endif

#if defined (BRS_ENABLE_PREFER_PLL_WATCHDOG_INIT)
/* 
 * The vBRSHwConfig configuration parameter called "BrsHw: Prefer PLL and Watchdog Init", which leads to the 
 * definition of the BRS_ENABLE_PREFER_PLL_WATCHDOG_INIT preprocessor macro, shall not be selected for Jacinto7.
 *
 * Reason: 
 * ------
 *
 * TI libraries have global variables and it is expected that the memory is initialised before invoking the 
 * TI library function: Sciclient_init().
 *
 * ./ Enabling this parameter will lead to the following calling sequence:
 *
 *     startup code > Brs_PreMainStartup() > Brs_ApplicationEntry() > BrsMain_MemoryInit_StageHardReset_Hook()
 *     > BrsHwPreInitPowerOn() > Sciclient_init()
 *
 *    The memory initialization, particularly the ROM-to-RAM copy of initialised variables, is not performed 
 *    previous to the invocation of Sciclient_init() in the above-mentioned calling sequence.
 *
 * ./ Not enabling this paramter will lead to the following calling sequence:
 *
 *     startup code > Brs_PreMainStartup() > Brs_ApplicationEntry() > Brs_MemoryInit() ...  main() 
 *     > BrsMainInit() > BrsHwPreInitPowerOn() > Sciclient_init()
 *
 *    In this case, the memory initialization, particularily ROM-to-RAM copy of initialised global variables, is 
 *    already done before the invocation of Sciclient_init().
 *
 */
#  error "The vBRSHwConfig configuration parameter - BrsHw: Prefer PLL and Watchdog Init - shall not be activated for Jacinto7!"
#endif

/**********************************************************************************************************************
 *  DEFINITION + MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONST VARIABLES
 *********************************************************************************************************************/
/*
 * Description: These constants are used to propagate the Versions over
 *              module boundaries.The version numbers are BCD coded. E.g. a sub
 *              version of 23 is coded with 0x23, a bug fix version of 9 is
 *              coded 0x09.
 */
uint8 const kBrsHwMainVersion   = (uint8)(BRSHW_VERSION >> 8);
uint8 const kBrsHwSubVersion    = (uint8)(BRSHW_VERSION & 0xFF);
uint8 const kBrsHwBugfixVersion = (uint8)(BRSHW_BUGFIX_VERSION);

/**********************************************************************************************************************
 *  LOCAL VARIABLES AND LOCAL HW REGISTERS
 *********************************************************************************************************************/
/* part of ArmCommon */

/**********************************************************************************************************************
 *  CONTROLLER CONFIGURATION REGISTERS
 *********************************************************************************************************************/
/* R5FSS Vector Interrupt Manager (VIM) */
#define BRSHW_MCU_VIM_BASEADDR  0x40F80000UL
#define BRSHW_MAIN_VIM_BASEADDR  0x0FF80000UL
#define BRSHW_VIM_BASEADDR               (((BrsHw_GetCore() & 6U) == 0U) ? BRSHW_MCU_VIM_BASEADDR : BRSHW_MAIN_VIM_BASEADDR)
/* IRQ vector address register. */
#define BRSHW_INTC_VIM_IRQVEC            BRSHW_IOS(uint32, (BRSHW_VIM_BASEADDR + 0x18UL))
/* FIQ vector address register. */
#define BRSHW_INTC_VIM_FIQVEC            BRSHW_IOS(uint32, (BRSHW_VIM_BASEADDR + 0x1CUL))
/* Raw status/set register. */
#define BRSHW_INTC_VIM_RAW_J(n)          BRSHW_IOS(uint32, (BRSHW_VIM_BASEADDR + 0x0400UL + (n) * 0x20UL))
/* Interrupt enable set register. */
#define BRSHW_INTC_VIM_INTR_EN_SET_J(n)  BRSHW_IOS(uint32, (BRSHW_VIM_BASEADDR + 0x0408UL + (n) * 0x20UL))
/* Interrupt enable clear register. */
#define BRSHW_INTC_VIM_INTR_EN_CLR_J(n)  BRSHW_IOS(uint32, (BRSHW_VIM_BASEADDR + 0x040CUL + (n) * 0x20UL))
/* IRQ interrupt enable status/clear register. */
#define BRSHW_INTC_VIM_IRQSTS_J(n)       BRSHW_IOS(uint32, (BRSHW_VIM_BASEADDR + 0x0410UL + (n) * 0x20UL))
/* FIQ interrupt enable status/clear register. */
#define BRSHW_INTC_VIM_FIQSTS_J(n)       BRSHW_IOS(uint32, (BRSHW_VIM_BASEADDR + 0x0414UL + (n) * 0x20UL))
/* Interrupt map register. */
#define BRSHW_INTC_VIM_INTMAP_J(n)       BRSHW_IOS(uint32, (BRSHW_VIM_BASEADDR + 0x0418UL + (n) * 0x20UL))
/* Interrupt priority register. */
#define BRSHW_INTC_VIM_PRI_INT_J(n)      BRSHW_IOS(uint32, (BRSHW_VIM_BASEADDR + 0x1000UL + (n) * 0x04UL))

#if defined (BRS_ENABLE_PORT)
/* BrsHwInitPortInput(), BrsHwInitPortOutput(), BrsHwInitPortInputOutput() are replaced by 
 * proprietary functions provided by TI. */

/**
 *  \brief   This function reads a 32-bit value from a hardware register
 *           and returns the value.
 *
 *  \param   p      Address of the memory mapped hardware register.
 *
 *  \return  Unsigned 32-bit value read from a register.
 */
// static inline uint32 CSL_REG32_RD_RAW(volatile const unsigned int * const p)
// {
//   return (*p);
// }

/**
 *  \brief   This function writes a 32-bit value to a hardware register.
 *
 *  \param   p      Address of the memory mapped hardware register.
 *  \param   v      Unsigned 32-bit value which has to be written to the
 *                  register.
 */
// static inline void CSL_REG32_WR_RAW(volatile unsigned int * const p, unsigned int v)
// {
//   *p = v;
//   return;
// }

  #define CSL_GPIO0_BASE  0x600000UL
  #define CSL_WKUP_GPIO0_BASE  0x42110000UL

  #define CSL_CTRL_MMR0_CFG0_BASE  0x100000UL
  #define CSL_WKUP_CTRL_MMR0_CFG0_BASE  0x43000000UL
  #define CSL_MCU_CTRL_MMR0_CFG0_BASE 0x40f00000UL

  /**
   *  \brief   This macro writes a 32-bit value to a hardware register.
   *
   *  \param   p       Address of the memory mapped hardware register.
   *  \param   v       Unsigned 32-bit value which has to be written to the
   *                   register.
   */
  #define CSL_REG32_WR(p, v)  (CSL_REG32_WR_RAW((volatile uint32 *) (p), (uint32) (v)))

  /**
   *  \brief   This macro reads a 32-bit value from a hardware register
   *           and returns the value.
   *
   *  \param   p      Address of the memory mapped hardware register.
   *
   *  \return  Unsigned 32-bit value read from a register.
   */
  #define CSL_REG32_RD(p)       (CSL_REG32_RD_RAW((volatile uint32 *) (p)))

# if defined (BRS_ENABLE_ETHERNET_SUPPORT)
  /** \brief Unlock value for lock kick 0 */
  #define MMR_KICK0_UNLOCK_VAL            (0x68EF3490U)

  /** \brief Unlock value for lock kick 1 */
  #define MMR_KICK1_UNLOCK_VAL            (0xD172BC5AU)

  /** \brief RGMII_ID_MODE shift value in CTRLMMR_MCU_ENET_CTRL register */
  #define ENET_CTRL_RGMII_ID_SHIFT        (4U)

  /** \brief No internal TX delay in RGMII interface (CTRLMMR_MCU_ENET_CTRL) */
  #define ENET_CTRL_RGMII_ID_INTTXDLY     (0U)

  /** \brief Internal TX delay in RGMII interface (CTRLMMR_MCU_ENET_CTRL) */
  #define ENET_CTRL_RGMII_ID_NODELAY      (1U)

  /** \brief RMII port interface (CTRLMMR_MCU_ENET_CTRL) */
  #define ENET_CTRL_MODE_RMII             (1U)

  /** \brief RGMII port interface (CTRLMMR_MCU_ENET_CTRL) */
  #define ENET_CTRL_MODE_RGMII            (2U)

  /** \brief Packet transmit retry in non-confirmation mode */
  #define ETHAPP_TRANSMIT_RETRY_COUNT     (2U)

  #define PIN_MODE(mode)                  ((mode) & 0xFU)
  #define PIN_PULL_DISABLE                (0x1U << 16U)
  #define PIN_PULL_DIRECTION              (0x1U << 17U)
  #define PIN_INPUT_ENABLE                (0x1U << 18U)
  #define PIN_OUTPUT_DISABLE              (0x1U << 21U)
  #define PIN_WAKEUP_ENABLE               (0x1U << 29U)
  #define PIN_INPUT                       (PIN_PULL_DISABLE | PIN_INPUT_ENABLE)
  #define PIN_OUTPUT                      (PIN_PULL_DISABLE)

  typedef enum
  {
    ETH_MAC_CONN_TYPE_RMII_10               = 0x01U,
    /**< MAC connection type for 10Mbps RMII mode */
    ETH_MAC_CONN_TYPE_RMII_100              = 0x02U,
    /**< MAC connection type for 100Mbps RMII mode */
    ETH_MAC_CONN_TYPE_RGMII_FORCE_100_HALF  = 0x03U,
    /**< MAC connection type for forced half-duplex 100Mbps RGMII mode */
    ETH_MAC_CONN_TYPE_RGMII_FORCE_100_FULL  = 0x04U,
    /**< MAC connection type for forced full-duplex 100Mbps RGMII mode */
    ETH_MAC_CONN_TYPE_RGMII_FORCE_1000_FULL = 0x05U,
    /**< MAC connection type for forced full-duplex 1000Mbps RGMII mode */
    ETH_MAC_CONN_TYPE_RGMII_DETECT_INBAND   = 0x06U,
    /**< MAC connection type for RGMII inband detection mode
      *   (speed determined based on received RGMII Rx clock) */
  } Eth_MacConnectionType;
# endif /*BRS_ENABLE_ETHERNET_SUPPORT*/
#endif /*BRS_ENABLE_PORT*/

/**********************************************************************************************************************
 *  LOCAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONST VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PROTOTYPES OF GLOBAL FUNCTIONS
 *********************************************************************************************************************/
extern void BrsMain_SoftwareResetECU_Hook(void);

/**********************************************************************************************************************
 *  PROTOTYPES OF LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONST DEFINITIONS
 *********************************************************************************************************************/
#if defined(BRS_DERIVATIVE_TDA4VM88)
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
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 0U,
		.cacheable        = (uint32_t)FALSE,
		.cachePolicy      = 0U,
		.memAttr          = 0U,
	  },
	  {
		/* Region 1 configuration: 128 bytes memory for exception vector execution */
		.regionId         = 1U,
		.enable           = 1U,
		.baseAddr         = 0x0U,
		.size             = CSL_ARM_R5_MPU_REGION_SIZE_128B,
		.subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
		.exeNeverControl  = 0U,
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 0U,
		.cacheable        = (uint32_t)TRUE,
		.cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
		.memAttr          = 0U,
	  },
	  {
		/* Region 2 configuration: 512 KB OCMS RAM */
		.regionId         = 2U,
		.enable           = 1U,
		.baseAddr         = 0x41C00000,
		.size             = CSL_ARM_R5_MPU_REGION_SIZE_512KB,
		.subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
		.exeNeverControl  = 0U,
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 0U,
		.cacheable        = (uint32_t)TRUE,
		.cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
		.memAttr          = 0U,
	  },
	  {
		/* Region 3 configuration: 2 MB MCMS3 RAM */
		.regionId         = 3U,
		.enable           = 1U,
		.baseAddr         = 0x70000000,
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
		/* Region 4 configuration: 2 GB DDR RAM */
		.regionId         = 4U,
		.enable           = 1U,
		.baseAddr         = 0x80000000,
		.size             = CSL_ARM_R5_MPU_REGION_SIZE_2GB,
		.subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
		.exeNeverControl  = 0U,
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 0U,
		.cacheable        = (uint32_t)TRUE,
		.cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
		.memAttr          = 0U,
	  },
	  {
		/* Region 5 configuration: 32 KB BTCM */
		/* Address of ATCM/BTCM are configured via MCU_SEC_MMR registers
		   It can either be '0x0' or '0x41010000'. Application/Boot-loader shall
		   take care this configurations and linker command file shall be
		   in sync with this. For either of the above configurations,
		   MPU configurations will not changes as both regions will have same
		   set of permissions in almost all scenarios.
		   Application can chose to overwrite this MPU configuration if needed.
		   The same is true for the region corresponding to ATCM. */
		.regionId         = 5U,
		.enable           = 1U,
		.baseAddr         = 0x41010000,
		.size             = CSL_ARM_R5_MPU_REGION_SIZE_32KB,
		.subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
		.exeNeverControl  = 0U,
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 0U,
		.cacheable        = (uint32_t)TRUE,
		.cachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
		.memAttr          = 0U,
	  },
	  {
		/* Region 6 configuration: 32 KB BTCM */
		.regionId         = 6U,
		.enable           = 1U,
		.baseAddr         = 0x41C4B000,
		.size             = CSL_ARM_R5_MPU_REGION_SIZE_1KB,
		.subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
		.exeNeverControl  = 0U,
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 1U,
		.cacheable        = (uint32_t)FALSE,
		.cachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
		.memAttr          = 0U,
	  },
	  {
		/* Region 7 configuration: 32 KB ATCM */
		.regionId         = 7U,
		.enable           = 1U,
		.baseAddr         = 0x0,
		.size             = CSL_ARM_R5_MPU_REGION_SIZE_32KB,
		.subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
		.exeNeverControl  = 0U,
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 0U,
		.cacheable        = (uint32_t)TRUE,
		.cachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
		.memAttr          = 0U,
	  },
	  {
		/* Region 8 configuration: 4 KB OCMS RAM / MSRAM used for vHSM*/
		.regionId         = 8U,
		.enable           = 1U,
		.baseAddr         = 0x41C00000,
		.size             = CSL_ARM_R5_MPU_REGION_SIZE_4KB,
		.subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
		.exeNeverControl  = 0U,
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 1U,
		.cacheable        = (uint32_t)FALSE,
		.cachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
		.memAttr          = 0U,
	  }
	};
#elif defined (BRS_DERIVATIVE_TDA4VE88)
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
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 0U,
		.cacheable        = (uint32_t)FALSE,
		.cachePolicy      = 0U,
		.memAttr          = 0U,
	  },
	  {
		/* Region 1 configuration: 128 bytes memory for exception vector execution */
		.regionId         = 1U,
		.enable           = 1U,
		.baseAddr         = 0x0U,
		.size             = CSL_ARM_R5_MPU_REGION_SIZE_128B,
		.subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
		.exeNeverControl  = 0U,
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 0U,
		.cacheable        = (uint32_t)TRUE,
		.cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
		.memAttr          = 0U,
	  },
	  {
		/* Region 2 configuration: 512 KB OCMS RAM */
		.regionId         = 2U,
		.enable           = 1U,
		.baseAddr         = 0x41C00000,
		.size             = CSL_ARM_R5_MPU_REGION_SIZE_1MB,
		.subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
		.exeNeverControl  = 0U,
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 0U,
		.cacheable        = (uint32_t)TRUE,
		.cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WT_NO_WA,
		.memAttr          = 0U,
	  },
	  {
		/* Region 3 configuration: 2 MB MCMS3 RAM */
		.regionId         = 3U,
		.enable           = 1U,
		.baseAddr         = 0x70000000,
		.size             = CSL_ARM_R5_MPU_REGION_SIZE_4MB,
		.subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
		.exeNeverControl  = 0U,
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 0U,
		.cacheable        = (uint32_t)TRUE,
		.cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
		.memAttr          = 0U,
	  },
	  {
		 /* Region 4 configuration: 2 GB DDR RAM */
		.regionId         = 4U,
		.enable           = 1U,
		.baseAddr         = 0x80000000,
		.size             = CSL_ARM_R5_MPU_REGION_SIZE_2GB,
		.subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
		.exeNeverControl  = 0U,
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 0U,
		.cacheable        = (uint32_t)TRUE,
		.cachePolicy      = CSL_ARM_R5_CACHE_POLICY_WT_NO_WA,
		.memAttr          = 0U,
	  },
	  {
		/* Region 5 configuration: 32 KB BTCM */
		/* Address of ATCM/BTCM are configured via MCU_SEC_MMR registers
		   It can either be '0x0' or '0x41010000'. Application/Boot-loader shall
		   take care this configurations and linker command file shall be
		   in sync with this. For either of the above configurations,
		   MPU configurations will not changes as both regions will have same
		   set of permissions in almost all scenarios.
		   Application can chose to overwrite this MPU configuration if needed.
		   The same is true for the region corresponding to ATCM. */
		.regionId         = 5U,
		.enable           = 1U,
		.baseAddr         = 0x41010000,
		.size             = CSL_ARM_R5_MPU_REGION_SIZE_32KB,
		.subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
		.exeNeverControl  = 0U,
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 0U,
		.cacheable        = (uint32_t)TRUE,
		.cachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
		.memAttr          = 0U,
	  },
	  {
		/* Region 6 configuration: 32 KB BTCM */
		.regionId         = 6U,
		.enable           = 1U,
		.baseAddr         = 0x41C4B000,
		.size             = CSL_ARM_R5_MPU_REGION_SIZE_1KB,
		.subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
		.exeNeverControl  = 0U,
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 1U,
		.cacheable        = (uint32_t)FALSE,
		.cachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
		.memAttr          = 0U,
	  },
	  {
		/* Region 7 configuration: 32 KB ATCM */
		.regionId         = 7U,
		.enable           = 1U,
		.baseAddr         = 0x0,
		.size             = CSL_ARM_R5_MPU_REGION_SIZE_32KB,
		.subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
		.exeNeverControl  = 0U,
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 0U,
		.cacheable        = (uint32_t)TRUE,
		.cachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
		.memAttr          = 0U,
	  },
	  {
		/* Region 8 configuration: 4 KB OCMS RAM / MSRAM used for vHSM*/
		.regionId         = 8U,
		.enable           = 1U,
		.baseAddr         = 0x41C00000,
		.size             = CSL_ARM_R5_MPU_REGION_SIZE_16KB,
		.subRegionEnable  = CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL,
		.exeNeverControl  = 0U,
		.accessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
		.shareable        = 1U,
		.cacheable        = (uint32_t)FALSE,
		.cachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
		.memAttr          = 0U,
	  }
	};
#endif

/**********************************************************************************************************************
 *  FUNCTION DEFINITIONS
 *********************************************************************************************************************/
extern void Intc_Init(void);

#if defined (BRS_ENABLE_CAN_SUPPORT)
void Can_InterruptConfig(void)
{
  struct tisci_msg_rm_irq_set_req     rmIrqReq;
  struct tisci_msg_rm_irq_set_resp    rmIrqResp;
  uint32 retVal;

  /* There is no special routing required for MCU MCAN0 and MCU MCAN1 */

  /* If the CAN instance is not in MCU domain, the interrupt router will
     have to be configured */
  /* Set the destination interrupt */

#if defined (BRS_ENABLE_CAN_CHANNEL_4)
  /* MAIN MCAN 4 routing */
  rmIrqReq.valid_params           = TISCI_MSG_VALUE_RM_DST_ID_VALID;
  rmIrqReq.valid_params          |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;
  rmIrqReq.src_id                 = TISCI_DEV_MCAN4;
  rmIrqReq.global_event           = 0U;
  /* Src Index 0 - mcanss_ext_ts_rollover_lvl_int,
     Src Index 1 - mcanss_mcan_lvl_int Line 0,
     Src Index 2 - mcanss_mcan_lvl_int Line 1 */
  rmIrqReq.src_index              = 1U;
  rmIrqReq.dst_id                 = TISCI_DEV_MCU_R5FSS0_CORE0;
  rmIrqReq.dst_host_irq           = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0 + 0;
  rmIrqReq.ia_id                  = 0U;
  rmIrqReq.vint                   = 0U;
  rmIrqReq.vint_status_bit_index  = 0U;
  rmIrqReq.secondary_host         = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
  retVal = Sciclient_rmIrqSet(&rmIrqReq, &rmIrqResp, SCICLIENT_SERVICE_WAIT_FOREVER);
  if((uint32)0 != retVal)
  {
    while(1);
  }
#endif /*BRS_ENABLE_CAN_CHANNEL_4*/

#if defined (BRS_ENABLE_CAN_CHANNEL_9)
  /* MAIN MCAN 9 routing */
  rmIrqReq.valid_params           = TISCI_MSG_VALUE_RM_DST_ID_VALID;
  rmIrqReq.valid_params          |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;
  rmIrqReq.src_id                 = TISCI_DEV_MCAN9;
  rmIrqReq.global_event           = 0U;
  /* Src Index 0 - mcanss_ext_ts_rollover_lvl_int,
     Src Index 1 - mcanss_mcan_lvl_int Line 0,
     Src Index 2 - mcanss_mcan_lvl_int Line 1 */
  rmIrqReq.src_index              = 1U;
  rmIrqReq.dst_id                 = TISCI_DEV_MCU_R5FSS0_CORE0;
  rmIrqReq.dst_host_irq           = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0 + 1;
  rmIrqReq.ia_id                  = 0U;
  rmIrqReq.vint                   = 0U;
  rmIrqReq.vint_status_bit_index  = 0U;
  rmIrqReq.secondary_host         = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
  retVal = Sciclient_rmIrqSet(&rmIrqReq, &rmIrqResp, SCICLIENT_SERVICE_WAIT_FOREVER);
  if((uint32)0 != retVal)
  {
    while(1);
  }
#endif /*BRS_ENABLE_CAN_CHANNEL_9*/
}
#endif /*BRS_ENABLE_CAN_SUPPORT*/

#if defined (BRS_ENABLE_LIN_SUPPORT)
void Lin_InterruptConfig(void)
{
  struct tisci_msg_rm_irq_set_req rmIrqReq;
  struct tisci_msg_rm_irq_set_resp rmIrqResp;
  uint32 retVal;

  /* If the UART instance is not in MCU domain, the interrupt router will
     have to be configured */
  /* Set the destination interrupt */

#if defined (BRS_ENABLE_LIN_CHANNEL_4)
  /* MAIN UART4 routing */
  rmIrqReq.valid_params           = TISCI_MSG_VALUE_RM_DST_ID_VALID;
  rmIrqReq.valid_params          |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;
  rmIrqReq.src_id                 = TISCI_DEV_UART4;
  rmIrqReq.global_event           = 0U;
  /* set to 0 for non-event based interrupt */
  rmIrqReq.src_index              = 0U;
  rmIrqReq.dst_id                 = TISCI_DEV_MCU_R5FSS0_CORE0;
  rmIrqReq.dst_host_irq           = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0 + 3;
  rmIrqReq.ia_id                  = 0U;
  rmIrqReq.vint                   = 0U;
  rmIrqReq.vint_status_bit_index  = 0U;
  rmIrqReq.secondary_host         = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
  retVal = Sciclient_rmIrqSet(&rmIrqReq, &rmIrqResp, SCICLIENT_SERVICE_WAIT_FOREVER);
  if((uint32)0 != retVal)
  {
    while(1);
  }
#endif /*BRS_ENABLE_LIN_CHANNEL_4*/

#if defined (BRS_ENABLE_LIN_CHANNEL_8)
  /* MAIN UART8 routing */
  rmIrqReq.valid_params           = TISCI_MSG_VALUE_RM_DST_ID_VALID;
  rmIrqReq.valid_params          |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;
  rmIrqReq.src_id                 = TISCI_DEV_UART8;
  rmIrqReq.global_event           = 0U;
  /* set to 0 for non-event based interrupt */
  rmIrqReq.src_index              = 0U;
  rmIrqReq.dst_id                 = TISCI_DEV_MCU_R5FSS0_CORE0;
  rmIrqReq.dst_host_irq           = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0 + 2;
  rmIrqReq.ia_id                  = 0U;
  rmIrqReq.vint                   = 0U;
  rmIrqReq.vint_status_bit_index  = 0U;
  rmIrqReq.secondary_host         = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
  retVal = Sciclient_rmIrqSet(&rmIrqReq, &rmIrqResp, SCICLIENT_SERVICE_WAIT_FOREVER);
  if((uint32)0 != retVal)
  {
    while(1);
  }
#endif /*BRS_ENABLE_LIN_CHANNEL_8*/
}
#endif /*BRS_ENABLE_LIN_SUPPORT*/

#if defined (BRS_ENABLE_I2C_SUPPORT)
void I2C_InterruptConfig(void)
{
  struct tisci_msg_rm_irq_set_req rmIrqReq;
  struct tisci_msg_rm_irq_set_resp rmIrqResp;
  uint32 retVal;

  /*
  * The interrupt path is established using the DMSC firmware
  * for I2C instance 1 on MAIN domin
  */
  rmIrqReq.valid_params           = TISCI_MSG_VALUE_RM_DST_ID_VALID;
  rmIrqReq.valid_params          |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;
  rmIrqReq.src_id                 = TISCI_DEV_I2C1;
  rmIrqReq.global_event           = 0U;
  rmIrqReq.src_index              = 0U;
  rmIrqReq.dst_id                 = TISCI_DEV_MCU_R5FSS0_CORE0;
  rmIrqReq.dst_host_irq           = CSLR_MCU_R5FSS0_CORE0_INTR_MAIN2MCU_LVL_INTRTR0_OUTL_0 + 4;
  rmIrqReq.ia_id                  = 0U;
  rmIrqReq.vint                   = 0U;
  rmIrqReq.vint_status_bit_index  = 0U;
  rmIrqReq.secondary_host         = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
  retVal = Sciclient_rmIrqSet(&rmIrqReq, &rmIrqResp, SCICLIENT_SERVICE_WAIT_FOREVER);
  if((uint32)0 != retVal)
  {
    /*while(1); Check removed by TI in SDK 7.0 update delivery */
  }
}
#endif /*BRS_ENABLE_I2C_SUPPORT*/

/*****************************************************************************/
/* @brief      This function can be used to initialize controller specific
 *             stuff that is not related to one of the other InitPowerOn
 *             functions (e.g. code that is always mandatory, also if MCAL
 *             and/or OS is used). This function is called from BrsMain
 *             immediately after BrsHwDisableInterruptAtPowerOn() during
 *             initialization (if BRSHW_PREINIT_AVAILABLE is set in BrsHw.h).
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 *****************************************************************************/
void BrsHwPreInitPowerOn(void)
{
  uint32 retVal;
  Sciclient_ConfigPrms_t config;
  Sciclient_configPrmsInit(&config);
  retVal = Sciclient_init(&config);
  if (retVal != BOARD_SOK)
  {
    while(1);
  }
  
  Intc_Init();

#if defined (BRS_ENABLE_CAN_SUPPORT)
  Can_InterruptConfig();
#endif

#if defined (BRS_ENABLE_LIN_SUPPORT)
  Lin_InterruptConfig();
#endif

#if defined (BRS_ENABLE_I2C_SUPPORT)
  I2C_InterruptConfig();
#endif
}

#if defined (BRS_ENABLE_WATCHDOG)
/*****************************************************************************/
/* @brief      This function must be used to initialize the Watchdog.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 *****************************************************************************/
void BrsHwWatchdogInitPowerOn(void)
{
  /* Nothing to be done here, Watchdogs disabled after boot from SBL */
}
#endif /*BRS_ENABLE_WATCHDOG*/

#if defined (BRS_ENABLE_PLLCLOCKS)
/*****************************************************************************/
/* @brief      This function must be used to initialize the PLL.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 *****************************************************************************/
void BrsHwPllInitPowerOn(void)
{
#if defined (BRS_ENABLE_CAN_SUPPORT)
/** \brief None, SBL powers up the timers and clock sources */
    /* default clock source: 80MHz*/
#endif

#if defined (BRS_ENABLE_LIN_SUPPORT)
/** \brief None, SBL powers up the timers and clock sources */
  /* default clock source: 48MHz*/
#endif

#if defined (BRS_ENABLE_I2C_SUPPORT)
  /* default clock source: 96MHz clock input clock*/
  /* I2C driver needs to configure the bus frequency to 100KHz or 400KHz */
#endif
}
#endif /*BRS_ENABLE_PLLCLOCKS*/

#if defined (BRS_ENABLE_PORT)
/* Calls of BrsHwInitPortOutput() and BrsHwInitPortInput() replaced by proprietery PlatformInit() functions, provided by TI */

# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_START_SEC_RAM_CODE
  #include "Brs_MemMap.h"
# endif
/*****************************************************************************/
/* @brief      This function sets the output level of a port pin.
 * @pre        Port pin configurations available within BrsHw_Ports.h,
 *             no DrvPort used for port pin initialization and
 *             transferred port pin has to be initialized as output pin with
 *             GPIO functionality.
 * @param[in]  p     - brsHw_Port_PortType, to be set,
 *             Level - level, port pin has to be set to
 *                     (BRSHW_PORT_LOGIC_LOW or BRSHW_PORT_LOGIC_HIGH).
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsHwPortInitPowerOn() and
 *             provided to external modules (e.g. BrsMainTogglePin()).
 *****************************************************************************/
void BrsHwPort_SetLevel(brsHw_Port_PortType p, uint8 Level)
{
  GPIOPinWrite_v0(p.portGroup, p.portNumber, Level);

  /* Read back the pin levels to ensure the setting */
  while (GPIOPinRead_v0(p.portGroup, p.portNumber) != Level)
  {}
}

/*****************************************************************************/
/* @brief      This function reads the input level of a port pin.
 * @pre        Port pin configurations available within BrsHw_Ports.h,
 *             no DrvPort used for port pin initialization and
 *             transferred port pin has to be initialized as input pin with
 *             GPIO functionality.
 * @param[in]  p - brsHw_Port_PortType, to be read.
 * @param[out] -
 * @return     Level, read from port pin
 *             (BRSHW_PORT_LOGIC_LOW or BRSHW_PORT_LOGIC_HIGH).
 * @context    Function is provided to external modules.
 *****************************************************************************/
uint8 BrsHwPort_GetLevel(brsHw_Port_PortType p)
{
  if(GPIOPinRead_v0(p.portGroup, p.portNumber) == GPIO_PIN_HIGH)
  {
    return BRSHW_PORT_LOGIC_HIGH;
  }
  else
  {
    return BRSHW_PORT_LOGIC_LOW;
  }
}
# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_STOP_SEC_RAM_CODE
  #include "Brs_MemMap.h"
# endif


#if defined (BRS_ENABLE_CAN_SUPPORT)
void Can_PlatformInit(void)
{
  uint32 regVal = 0U;
#if defined (BRS_DERIVATIVE_TDA4VM88)
  #if defined (BRS_ENABLE_CAN_CHANNEL_0)
    /* MCU MCAN 0 Tx PAD configuration: PIN_MCU_MCAN0_TX */
    regVal = 0x60000U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0A8U, regVal);
    /* MCU MCAN 0 Rx PAD configuration: PIN_MCU_MCAN0_RX */
    regVal = 0x60000U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0ACU, regVal);
  #endif /*BRS_ENABLE_CAN_CHANNEL_0*/

  #if defined (BRS_ENABLE_CAN_CHANNEL_1)
    /* MCU MCAN 1 Tx PAD configuration: PIN_WKUP_GPIO0_4 */
    regVal = 0x60000U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0C0U, regVal);
    /* MCU MCAN 1 Rx PAD configuration: PIN_WKUP_GPIO0_5 */
    regVal = 0x60000U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0C4U, regVal);
  #endif /*BRS_ENABLE_CAN_CHANNEL_1*/

  #if defined (BRS_ENABLE_CAN_CHANNEL_4)
    /* MAIN MCAN 4 Tx PAD configuration: PIN_PRG1_PRU0_GPO7 */
    regVal = 0x60006U;
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C020U, regVal);
    /* MAIN MCAN 4 Rx PAD configuration: PIN_PRG1_PRU0_GPO8 */
    regVal = 0x60006U;
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C024U, regVal);
  #endif /*BRS_ENABLE_CAN_CHANNEL_4*/

  #if defined (BRS_ENABLE_CAN_CHANNEL_9)
    /* MAIN MCAN 9 Tx PAD configuration: PIN_PRG0_PRU0_GPO7 */
    regVal = 0x60006U;
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C0CCU, regVal);
    /* MAIN MCAN 9 Rx PAD configuration: PIN_PRG0_PRU0_GPO8 */
    regVal = 0x60006U;
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C0D0U, regVal);
  #endif /*BRS_ENABLE_CAN_CHANNEL_9*/
#elif defined (BRS_DERIVATIVE_TDA4VE88)
  #if defined (BRS_ENABLE_CAN_CHANNEL_0)
    /* MCU MCAN 0 Tx PAD configuration: PIN_MCU_MCAN0_TX */
    regVal = 0x60000U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0B8U, regVal);
    /* MCU MCAN 0 Rx PAD configuration: PIN_MCU_MCAN0_RX */
    regVal = 0x60000U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0BCU, regVal);
  #endif /*BRS_ENABLE_CAN_CHANNEL_0*/

  #if defined (BRS_ENABLE_CAN_CHANNEL_1)
    /* MCU MCAN 1 Tx PAD configuration: PIN_WKUP_GPIO0_4 */
    regVal = 0x60000U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0D0U, regVal);
    /* MCU MCAN 1 Rx PAD configuration: PIN_WKUP_GPIO0_5 */
    regVal = 0x60000U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0D4U, regVal);
  #endif /*BRS_ENABLE_CAN_CHANNEL_1*/

  #if defined (BRS_ENABLE_CAN_CHANNEL_4)
    /* MAIN MCAN 4 Tx PAD configuration: PIN_MCASP0_AXR5 */
    regVal = 0x60000U;
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C084U, regVal);
    /* MAIN MCAN 4 Rx PAD configuration: PIN_MCASP0_AXR6 */
    regVal = 0x60000U;
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C088U, regVal);
  #endif /*BRS_ENABLE_CAN_CHANNEL_4*/

  #if defined (BRS_ENABLE_CAN_CHANNEL_9)
    /* MAIN MCAN 9 Tx PAD configuration: PIN_MCASP0_AXR15 */
    regVal = 0x60000U;
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C0ACU, regVal);
    /* MAIN MCAN 9 Rx PAD configuration: PIN_MCASP2_AXR0 */
    regVal = 0x60000U;
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C05CU, regVal);
  #endif /*BRS_ENABLE_CAN_CHANNEL_9*/
#endif

}

void Can_EnableTransceivers(void)
{
  uint32 regVal = 0U;
  uint32 pin_level = 0U;
#if defined (BRS_DERIVATIVE_TDA4VM88)
  #if defined (BRS_ENABLE_CAN_CHANNEL_0)
    /* Take MCU MCAN0 transceiver EN */
    regVal = 0x08050007U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG44, regVal);
    /* Set WAKEUP_GPIO0_0 Pin direction to output and drive High*/
    GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 0U, GPIO_DIRECTION_OUTPUT);
    GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 0U, GPIO_PIN_HIGH);
    pin_level = GPIOPinRead_v0(CSL_WKUP_GPIO0_BASE, 0U);
    while (GPIO_PIN_HIGH != pin_level)
    {
      pin_level = GPIOPinRead_v0(CSL_WKUP_GPIO0_BASE, 0U);
    }

    /* Take MCU MCAN0 transceiver STB */
    regVal = 0x08050007U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE +
    CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG38, regVal);
    /* Set WAKEUP_GPIO0_54 Pin direction to output and drive High */
    GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 54U, GPIO_DIRECTION_OUTPUT);
    GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE,54U, GPIO_PIN_HIGH);
    pin_level = GPIOPinRead_v0(CSL_WKUP_GPIO0_BASE, 54U);
    while (GPIO_PIN_HIGH != pin_level)
    {
      pin_level = GPIOPinRead_v0(CSL_WKUP_GPIO0_BASE, 54U);
    }
  #endif /*BRS_ENABLE_CAN_CHANNEL_0*/

  #if defined (BRS_ENABLE_CAN_CHANNEL_1)
    /* Take MCU MCAN1 transceiver STB */
    regVal = 0x08050007U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG46, regVal);
    /* Set WAKEUP_GPIO0_2 Pin direction to output and drive Low*/
    GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 2U, GPIO_DIRECTION_OUTPUT);
    GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE,2U, GPIO_PIN_LOW);
    pin_level = GPIOPinRead_v0(CSL_WKUP_GPIO0_BASE, 2U);
    while (GPIO_PIN_LOW != pin_level)
    {
      pin_level = GPIOPinRead_v0(CSL_WKUP_GPIO0_BASE, 2U);
    }
  #endif /*BRS_ENABLE_CAN_CHANNEL_1*/

  #if defined (BRS_ENABLE_CAN_CHANNEL_4) || defined (BRS_ENABLE_CAN_CHANNEL_9)
    /* Pin mux for MAIN MCAN4/9 STB used in GESI board: PIN_PRG0_PRU0_GPO17: GPIO0_60*/
    regVal = 0x50007U;
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C0F4U, regVal);
    /* Take MCAN transceiver out of STB mode for MCAN0 */
    /* Set Pin direction to output and drive low*/
    GPIOSetDirMode_v0(CSL_GPIO0_BASE, 60U, GPIO_DIRECTION_OUTPUT);
    GPIOPinWrite_v0(CSL_GPIO0_BASE, 60U, GPIO_PIN_LOW);
    pin_level = GPIOPinRead_v0(CSL_GPIO0_BASE, 60U);
    while (GPIO_PIN_LOW != pin_level)
    {
      pin_level = GPIOPinRead_v0(CSL_GPIO0_BASE, 60U);
    }
  #endif /*BRS_ENABLE_CAN_CHANNEL_4||BRS_ENABLE_CAN_CHANNEL_9*/
#elif defined (BRS_DERIVATIVE_TDA4VE88)
  #if defined (BRS_ENABLE_CAN_CHANNEL_0)
    /* Take MCU MCAN0 transceiver EN */
    regVal = 0x08050007U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG48, regVal);
    /* Set WAKEUP_GPIO0_0 Pin direction to output and drive High*/
    GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 0U, GPIO_DIRECTION_OUTPUT);
    GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 0U, GPIO_PIN_HIGH);
    pin_level = GPIOPinRead_v0(CSL_WKUP_GPIO0_BASE, 0U);
    while (GPIO_PIN_HIGH != pin_level)
    {
      pin_level = GPIOPinRead_v0(CSL_WKUP_GPIO0_BASE, 0U);
    }

    /* Take MCU MCAN0 transceiver STB */
    regVal = 0x08050007U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE +
    CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG42, regVal);
    /* Set WAKEUP_GPIO0_54 Pin direction to output and drive High */
    GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 69U, GPIO_DIRECTION_OUTPUT);
    GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 69U, GPIO_PIN_HIGH);
    pin_level = GPIOPinRead_v0(CSL_WKUP_GPIO0_BASE, 69U);
    while (GPIO_PIN_HIGH != pin_level)
    {
      pin_level = GPIOPinRead_v0(CSL_WKUP_GPIO0_BASE, 69U);
    }
  #endif /*BRS_ENABLE_CAN_CHANNEL_0*/

  #if defined (BRS_ENABLE_CAN_CHANNEL_1)
    /* Take MCU MCAN1 transceiver STB */
    regVal = 0x08050007U;
    CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG50, regVal);
    /* Set WAKEUP_GPIO0_2 Pin direction to output and drive Low*/
    GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 2U, GPIO_DIRECTION_OUTPUT);
    GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE,2U, GPIO_PIN_LOW);
    pin_level = GPIOPinRead_v0(CSL_WKUP_GPIO0_BASE, 2U);
    while (GPIO_PIN_LOW != pin_level)
    {
      pin_level = GPIOPinRead_v0(CSL_WKUP_GPIO0_BASE, 2U);
    }
  #endif /*BRS_ENABLE_CAN_CHANNEL_1*/

  #if defined (BRS_ENABLE_CAN_CHANNEL_4) || defined (BRS_ENABLE_CAN_CHANNEL_9)
  #error "Currently not supported. Need to change to I2C for enablement in J7AEP."
    #if 0 /* Need to change to I2C for enablement in J7AEP */
      /* Pin mux for MAIN MCAN4/9 STB used in GESI board: PIN_PRG0_PRU0_GPO17: GPIO0_60*/
      regVal = 0x50007U;
      CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C0F4U, regVal);
      /* Take MCAN transceiver out of STB mode for MCAN0 */
      /* Set Pin direction to output and drive low*/
      GPIOSetDirMode_v0(CSL_GPIO0_BASE, 60U, GPIO_DIRECTION_OUTPUT);
      GPIOPinWrite_v0(CSL_GPIO0_BASE, 60U, GPIO_PIN_LOW);
      pin_level = GPIOPinRead_v0(CSL_GPIO0_BASE, 60U);
      while (GPIO_PIN_LOW != pin_level)
      {
        pin_level = GPIOPinRead_v0(CSL_GPIO0_BASE, 60U);
      }
    #endif
  #endif /*BRS_ENABLE_CAN_CHANNEL_4||BRS_ENABLE_CAN_CHANNEL_9*/
#endif    
}


#endif /*BRS_ENABLE_CAN_SUPPORT*/

#if defined (BRS_ENABLE_LIN_SUPPORT)
void Lin_PlatformInit(void)
{
  uint32 regVal = 0U;

#if defined (BRS_ENABLE_LIN_CHANNEL_4)
  /* UART4 config, not connected to any LIN Transceiver */
  /* MAIN UART4 Tx (PIN_RGMII6_TD2) PAD configuration */
  regVal = 0x60001U;
  CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C194U, regVal);
  /* MAIN UART4 Rx (PIN_RGMII6_TD3)  PAD configuration */
  regVal = 0x60001U;
  CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C190U, regVal);
#endif /*BRS_ENABLE_LIN_CHANNEL_4*/

#if defined (BRS_ENABLE_LIN_CHANNEL_8)
  /* UART8 config for TLIN1022DMTTQ1 (U45) */
  /* MAIN UART8 Tx (PIN_PRG0_PRU1_GPO10) PAD configuration */
  regVal = 0x6000EU;
  CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C128U, regVal);
  /* MAIN UART8 Rx (PIN_PRG0_PRU1_GPO9)  PAD configuration */
  regVal = 0x6000EU;
  CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C124U, regVal);
#endif /*BRS_ENABLE_LIN_CHANNEL_8*/
}

void Lin_EnableTransceiver(void)
{
#if defined (BRS_DERIVATIVE_TDA4VM88)
  #if defined (BRS_ENABLE_LIN_CHANNEL_8)
    uint32 regVal = 0U;
    uint32 pin_level = 0U;

    /* LIN ENABLE for TLIN1022DMTTQ1 (U45) */
    /* Pin mux for LIN EN (PIN_PRG0_PRU1_GPO5: GPIO0_68)*/
    regVal = 0x50007U;
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C114U, regVal);

    /* Set GPIO0_68 direction to output and drive it High */
    GPIOSetDirMode_v0(CSL_GPIO0_BASE, 68U, GPIO_DIRECTION_OUTPUT);
    GPIOPinWrite_v0(CSL_GPIO0_BASE, 68U, GPIO_PIN_HIGH);
    pin_level = GPIOPinRead_v0(CSL_GPIO0_BASE, 68U);
    while (GPIO_PIN_HIGH != pin_level)
    {
      pin_level = GPIOPinRead_v0(CSL_GPIO0_BASE, 68U);
    }
  #endif /*BRS_ENABLE_LIN_CHANNEL_8*/
#elif defined (BRS_DERIVATIVE_TDA4VE88)
  #if defined (BRS_ENABLE_LIN_CHANNEL_8)
  #error "Currently not supported. Need to change to I2C for enablement in J7AEP."
    #if 0 /* Need to change to I2C for enablement in J7AEP */
      uint32 regVal = 0U;
      uint32 pin_level = 0U;

      /* LIN ENABLE for TLIN1022DMTTQ1 (U45) */
      /* Pin mux for LIN EN (PIN_PRG0_PRU1_GPO5: GPIO0_68)*/
      regVal = 0x50007U;
      CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C114U, regVal);

      /* Set GPIO0_68 direction to output and drive it High */
      GPIOSetDirMode_v0(CSL_GPIO0_BASE, 68U, GPIO_DIRECTION_OUTPUT);
      GPIOPinWrite_v0(CSL_GPIO0_BASE, 68U, GPIO_PIN_HIGH);
      pin_level = GPIOPinRead_v0(CSL_GPIO0_BASE, 68U);
      while (GPIO_PIN_HIGH != pin_level)
      {
        pin_level = GPIOPinRead_v0(CSL_GPIO0_BASE, 68U);
      }
    #endif
  #endif /*BRS_ENABLE_LIN_CHANNEL_8*/
#endif
}
#endif /*BRS_ENABLE_LIN_SUPPORT*/

#if defined (BRS_ENABLE_ETHERNET_SUPPORT)
void Eth_PlatformInit(void)
{
#if defined (BRS_DERIVATIVE_TDA4VM88)
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK2_KICK0, MMR_KICK0_UNLOCK_VAL);
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK2_KICK1, MMR_KICK1_UNLOCK_VAL);
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK7_KICK0, MMR_KICK0_UNLOCK_VAL);
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK7_KICK1, MMR_KICK1_UNLOCK_VAL);

  /* MCU_CPSW -> MCU_RGMII1_TX_CTL -> B27 (DRA721E) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG22, PIN_MODE(0U) | PIN_OUTPUT);

  /* MCU_CPSW -> MCU_RGMII1_RX_CTL -> C25 (DRA721E) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG23, PIN_MODE(0U) | PIN_INPUT);

  /* MCU_CPSW -> MCU_RGMII1_TD3 -> A28 (DRA721E) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG24, PIN_MODE(0U) | PIN_OUTPUT);

  /* MCU_CPSW -> MCU_RGMII1_TD2 -> A27 (DRA721E) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG25, PIN_MODE(0U) | PIN_OUTPUT);

  /* MCU_CPSW -> MCU_RGMII1_TD1 -> A26 (DRA721E) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG26, PIN_MODE(0U) | PIN_OUTPUT);

  /* MCU_CPSW -> MCU_RGMII1_TD0 -> B25 (DRA721E) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG27, PIN_MODE(0U) | PIN_OUTPUT);

  /* MCU_CPSW -> MCU_RGMII1_TXC -> B26 (DRA721E) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG28, PIN_MODE(0U) | PIN_OUTPUT);

  /* MCU_CPSW -> MCU_RGMII1_RXC -> C24 (DRA721E) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG29, PIN_MODE(0U) | PIN_INPUT);

  /* MCU_CPSW -> MCU_RGMII1_RD3 -> A25 (DRA721E) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG30, PIN_MODE(0U) | PIN_INPUT);

  /* MCU_CPSW -> MCU_RGMII1_RD2 -> D24 (DRA721E) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG31, PIN_MODE(0U) | PIN_INPUT);

  /* MCU_CPSW -> MCU_RGMII1_RD1 -> A24 (DRA721E) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG32, PIN_MODE(0U) | PIN_INPUT);

  /* MCU_CPSW -> MCU_RGMII1_RD0 -> B24 (DRA721E) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG33, PIN_MODE(0U) | PIN_INPUT);

  /* MCU_MDIO0 -> MCU_MDIO0_MDIO -> E23 (DRA721E) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG34, PIN_MODE(0U) | PIN_INPUT);

  /* MCU_MDIO0 -> MCU_MDIO0_MDC -> F23 (DRA721E) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG35, PIN_MODE(0U) | PIN_OUTPUT);

  /* WKUP_GPIO0 -> WKUP_GPIO0_3 -> F27 (DRA721E) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG47, PIN_MODE(7U) | PIN_INPUT);
#elif defined (BRS_DERIVATIVE_TDA4VE88)
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK2_KICK0, MMR_KICK0_UNLOCK_VAL);
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK2_KICK1, MMR_KICK1_UNLOCK_VAL);
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK7_KICK0, MMR_KICK0_UNLOCK_VAL);
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK7_KICK1, MMR_KICK1_UNLOCK_VAL);

  /* MCU_CPSW -> MCU_RGMII1_TX_CTL -> F22 (J721S2) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG26, PIN_MODE(0U) | PIN_OUTPUT);

  /* MCU_CPSW -> MCU_RGMII1_RX_CTL -> E23 (J721S2) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG27, PIN_MODE(0U) | PIN_INPUT);

  /* MCU_CPSW -> MCU_RGMII1_TD3 -> E22 (J721S2) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG28, PIN_MODE(0U) | PIN_OUTPUT);

  /* MCU_CPSW -> MCU_RGMII1_TD2 -> E21 (J721S2) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG29, PIN_MODE(0U) | PIN_OUTPUT);

  /* MCU_CPSW -> MCU_RGMII1_TD1 -> G22 (J721S2) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG30, PIN_MODE(0U) | PIN_OUTPUT);

  /* MCU_CPSW -> MCU_RGMII1_TD0 -> F23 (J721S2) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG31, PIN_MODE(0U) | PIN_OUTPUT);

  /* MCU_CPSW -> MCU_RGMII1_TXC -> F21 (J721S2) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG32, PIN_MODE(0U) | PIN_OUTPUT);

  /* MCU_CPSW -> MCU_RGMII1_RXC -> D22 (J721S2) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG33, PIN_MODE(0U) | PIN_INPUT);

  /* MCU_CPSW -> MCU_RGMII1_RD3 -> D23 (J721S2) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG34, PIN_MODE(0U) | PIN_INPUT);

  /* MCU_CPSW -> MCU_RGMII1_RD2 -> C22 (J721S2) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG35, PIN_MODE(0U) | PIN_INPUT);

  /* MCU_CPSW -> MCU_RGMII1_RD1 -> B21 (J721S2) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG36, PIN_MODE(0U) | PIN_INPUT);

  /* MCU_CPSW -> MCU_RGMII1_RD0 -> B22 (J721S2) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG37, PIN_MODE(0U) | PIN_INPUT);

  /* MCU_MDIO0 -> MCU_MDIO0_MDIO -> A22 (J721S2) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG38, PIN_MODE(0U) | PIN_INPUT);

  /* MCU_MDIO0 -> MCU_MDIO0_MDC -> A21 (J721S2) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG39, PIN_MODE(0U) | PIN_OUTPUT);

  /* WKUP_GPIO56 -> WKUP_GPIO0_56 -> G27 (J721S2) */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG72, PIN_MODE(7U) | PIN_INPUT);
#endif
}

void Eth_EnableTransceiver(Eth_MacConnectionType type)
{
  uint32 val;

  /* Set Connection Type */
  val = ENET_CTRL_RGMII_ID_NODELAY << ENET_CTRL_RGMII_ID_SHIFT;

  switch (type)
  {
  case ETH_MAC_CONN_TYPE_RMII_10:
  case ETH_MAC_CONN_TYPE_RMII_100:
    val |= ENET_CTRL_MODE_RMII;
    break;
  case ETH_MAC_CONN_TYPE_RGMII_FORCE_100_HALF:
  case ETH_MAC_CONN_TYPE_RGMII_FORCE_100_FULL:
  case ETH_MAC_CONN_TYPE_RGMII_FORCE_1000_FULL:
  case ETH_MAC_CONN_TYPE_RGMII_DETECT_INBAND:
    val |= ENET_CTRL_MODE_RGMII;
    break;
  default:
    break;
  }

  /* Set MAC port interface in MMR */
  CSL_REG32_WR(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0, MMR_KICK0_UNLOCK_VAL);
  CSL_REG32_WR(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1, MMR_KICK1_UNLOCK_VAL);
  CSL_REG32_WR(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL, val);
}
#endif /*BRS_ENABLE_ETHERNET_SUPPORT*/

#if defined (BRS_ENABLE_I2C_SUPPORT)
void I2C_PlatformInit(void)
{
#if defined (BRS_DERIVATIVE_TDA4VM88)
  uint32 regVal = 0U;

  /* MCU I2C0 */
  /* pinmux for MCU I2C0 SCL: PIN_MCU_I2C0_SCL */
  regVal = 0x60000U;
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C100U, regVal);
  /* pinmux for MCU I2C0 SDA: PIN_MCU_I2C0_SDA */
  regVal = 0x60000U;
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C104U, regVal);

  /* MAIN I2C1 */
  /* MAIN I2C1 SCL: PIN_I2C1_SCL */
  regVal = 0x60000U;
  CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C228U, regVal);
  /* MAIN I2C1 SDA: PIN_I2C1_SDA */
  regVal = 0x60000U;
  CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C22CU, regVal);
#elif defined (BRS_DERIVATIVE_TDA4VE88)
  uint32 regVal = 0U;

  /* MCU I2C0 */
  /* pinmux for MCU I2C0 SCL: PIN_MCU_I2C0_SCL */
  regVal = 0x60000U;
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C108U, regVal);
  /* pinmux for MCU I2C0 SDA: PIN_MCU_I2C0_SDA */
  regVal = 0x60000U;
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C10CU, regVal);

  /* MAIN I2C1 */
  /* MAIN I2C1 SCL: PIN_ECAP0_IN_APWM_OUT */
  regVal = 0x60000U;
  CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C0C4U, regVal);
  /* MAIN I2C1 SDA: PIN_EXT_REFCLK1 */
  regVal = 0x60000U;
  CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C0C8U, regVal);
#endif
}
#endif /*BRS_ENABLE_I2C_SUPPORT*/

#define KICK0 0x68EF3490ull
#define KICK1 0xD172BC5Aull

/*****************************************************************************/
/* @brief      This function must be used to initialize the used ports.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 *****************************************************************************/
void BrsHwPortInitPowerOn(void)
{
  uint32 regVal = 0;

  /* Unlock WAKUP CTRL MMR LOCK7 */
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1D008, KICK0);
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1D00C, KICK1);
  /* Check for unlock */
  regVal = CSL_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1D008);

  while ((regVal & 0x1) != 0x1U)
  {
    regVal = CSL_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1D008);
  }

  /* Unlock MAIN CTRL MMR LOCK7*/
  CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1D008, KICK0);
  CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1D00C, KICK1);
  /* Check for unlock */
  regVal = CSL_REG32_RD(CSL_CTRL_MMR0_CFG0_BASE + 0x1D008);
  while ((regVal & 0x1) != 0x1U)
  {
    regVal = CSL_REG32_RD(CSL_CTRL_MMR0_CFG0_BASE + 0x1D008);
  }

  /* Unlocking done */

#if defined (BRS_ENABLE_SUPPORT_LEDS)
  /* Calls of BrsHwInitPortOutput() and BrsHwInitPortInput() replaced by proprietery implementation, provided by TI */

  /* WAKEUP_GPIO0_6 */
  regVal = 0x08050007U;
  CSL_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_PADCONFIG50, regVal);

  /* Set WAKEUP_GPIO0_6 Pin direction to output and drive High*/
  GPIOSetDirMode_v0(CSL_WKUP_GPIO0_BASE, 6U, GPIO_DIRECTION_OUTPUT);

  /* Set LED on EVB demo board to show the system is alive */
  BrsMainTogglePin(BRSMAIN_TOGGLEPIN_LED);
#endif

#if defined (BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN)
  /* Calls of BrsHwInitPortOutput() and BrsHwInitPortInput() replaced by proprietery implementation, provided by TI */
  #error "Implementation for initialization of specific pin must be added here. See LED pin as reference."
#endif

#if defined (BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN)
  /* Calls of BrsHwInitPortOutput() and BrsHwInitPortInput() replaced by proprietery implementation, provided by TI */
  #error "Implementation for initialization of specific pin must be added here. See LED pin as reference."
#endif

/*******************************************************************************
 *  CAN driver
 *******************************************************************************/
#if defined (BRS_ENABLE_CAN_SUPPORT)
  Can_PlatformInit();
  Can_EnableTransceivers();

  /* Calls of BrsHwInitPortOutput() and BrsHwInitPortInput() replaced by proprietery Can_PlatformInit() function, provided by TI */

# if defined (BRS_ENABLE_CAN_CHANNEL_2) || defined (BRS_ENABLE_CAN_CHANNEL_3) || \
     defined (BRS_ENABLE_CAN_CHANNEL_5) || defined (BRS_ENABLE_CAN_CHANNEL_6) || \
     defined (BRS_ENABLE_CAN_CHANNEL_7) || defined (BRS_ENABLE_CAN_CHANNEL_8)
  #error "Configured CAN channels not supported yet!"
# endif
#endif /*BRS_ENABLE_CAN_SUPPORT*/

/*******************************************************************************
 *  LIN driver
 *******************************************************************************/
#if defined (BRS_ENABLE_LIN_SUPPORT)
  Lin_PlatformInit();
  Lin_EnableTransceiver();

  /* Calls of BrsHwInitPortOutput() and BrsHwInitPortInput() replaced by proprietery Lin_PlatformInit() function, provided by TI */

# if defined (BRS_ENABLE_LIN_CHANNEL_0) || defined (BRS_ENABLE_LIN_CHANNEL_1) || \
     defined (BRS_ENABLE_LIN_CHANNEL_2) || defined (BRS_ENABLE_LIN_CHANNEL_3) || \
     defined (BRS_ENABLE_LIN_CHANNEL_5) || defined (BRS_ENABLE_LIN_CHANNEL_6) || \
     defined (BRS_ENABLE_LIN_CHANNEL_7)
  #error "Configured LIN channels not supported yet!"
# endif
#endif /*BRS_ENABLE_LIN_SUPPORT*/

/*******************************************************************************
 *  FLEXRAY driver
 *******************************************************************************/
#if defined (BRS_ENABLE_FLEXRAY_SUPPORT)
  #error "Configured Flexray channels not supported yet!"
#endif

/*******************************************************************************
 *  ETHERNET driver
 *******************************************************************************/
#if defined (BRS_ENABLE_ETHERNET_SUPPORT)
  Eth_PlatformInit();
  /* Currently selecting connection RMII 10 by default */
  Eth_EnableTransceiver(ETH_MAC_CONN_TYPE_RMII_10);
#endif

  /* Calls of BrsHwInitPortOutput() and BrsHwInitPortInput() replaced by proprietery Eth_PlatformInit() function, provided by TI */

/*******************************************************************************
 *  I2C driver
 *******************************************************************************/
#if defined (BRS_ENABLE_I2C_SUPPORT)
  I2C_PlatformInit();
#endif

  /* Calls of BrsHwInitPortOutput() and BrsHwInitPortInput() replaced by proprietery I2C_PlatformInit() function, provided by TI */
}
#endif /*BRS_ENABLE_PORT*/

/* BrsHwDisableInterruptAtPowerOn() is part of ArmCommon */

/*****************************************************************************/
/* @brief      Restart ECU (issue a software reset or jump to startup code)
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from e.g. ECU state handling
 *****************************************************************************/
void BrsHwSoftwareResetECU(void)
{
  BrsMain_SoftwareResetECU_Hook();

#if !defined (BRS_ENABLE_FBL_SUPPORT) /* FBL is always running in polling mode with interrupts disabled */
  DisableAllInterrupts();
#endif

  /* Implementation still missing. Will be provided by TI later on */

  /* implement code, necessary for a software reset, here */

  while (1)
  {
    /* Wait until reset/watchdog reset occurs */
  }
}

/*****************************************************************************/
/* @brief      Get reset reason
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     Reset reason
 * @context    Function is called from BrsMainStartup to determine if reset
 *             was triggered through software call (BrsHwSoftwareResetECU()).
 *****************************************************************************/
brsHw_ResetReasonType BrsHwGetResetReason(void)
{
  /* Implementation still missing. Will be provided by TI later on */

  if(/*...*/0)
  {
    return BRSHW_RESET_SW;
  }
  else
  {
    return BRSHW_RESET_OTHER;
  }
}

/* BrsHwTime100NOP() is part of ArmCommon */

#if defined (BRS_ENABLE_SAFECTXSUPPORT)
/*****************************************************************************/
/* @brief      This API is used to enable hardware access in untrusted mode
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function must be called after all depending peripheral modules
 *             are supplied by proper clocks AND before the OS is started.
 *****************************************************************************/
void BrsHw_EnableHwAccess(void)
{
  /* nothing to be done for this platform yet (or never tested) */
  #error "Hardware access in UserMode not yet supported for your specific derivative!"
}
#endif /*BRS_ENABLE_SAFECTXSUPPORT*/

/* BrsHw_GetCore() is part of ArmCommon */

/*****************************************************************************/
/* @brief      This API is used to enable an interrupt source in the core
 *             interrupt controller.
 * @pre        -
 * @param[in]  Source to be enabled.
 * @param[in]  Priority level to be set.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 *****************************************************************************/
void BrsHw_EnableInterrupt(uint32 Source, uint8 Priority)
{
  /* Clear pending interrupt. */
  if(((BRSHW_INTC_VIM_INTMAP_J(Source / 32U)) >> (Source % 32U)) & (uint32)0x01)
  {
    BRSHW_INTC_VIM_FIQSTS_J(Source / 32U)= (uint32)(1UL << (Source % 32U));
    BRSHW_INTC_VIM_FIQVEC = 0x01UL;
  }
  else
  {
    BRSHW_INTC_VIM_IRQSTS_J(Source / 32U)= (uint32)(1UL << (Source % 32U));
    BRSHW_INTC_VIM_IRQVEC = 0x01UL;
  }
  /* Set interrupt priority. */
  BRSHW_INTC_VIM_PRI_INT_J(Source) = Priority;
  /* Enable interrupt handling. */
  BRSHW_INTC_VIM_INTR_EN_SET_J(Source / 32U) |= (uint32)(1UL << (Source % 32U));
}

/*****************************************************************************/
/* @brief      This API is used to disable an interrupt source in the core
 *             interrupt controller.
 * @pre        -
 * @param[in]  Source to be disabled.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 *****************************************************************************/
void BrsHw_DisableInterrupt(uint32 Source)
{
  BRSHW_INTC_VIM_INTR_EN_CLR_J(Source / 32U) |= (uint32)(1UL << (Source % 32U));
}

/*****************************************************************************/
/* @brief      This API is used to trigger the given software interrupt source.
 * @pre        -
 * @param[in]  Source to be triggered.
 *             Some derivatives only support few software triggerable sources,
 *             check for their validity.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 *****************************************************************************/
void BrsHw_TriggerSoftwareInterrupt(uint32 Source)
{
  BRSHW_INTC_VIM_RAW_J(Source / 32U) |= (uint32)(1UL << (Source % 32U));
}

#if defined (BRS_ENABLE_OS_MULTICORESUPPORT)
/*****************************************************************************/
/* @brief      This API is used as sync barrier. It is used to unlock cores
 *             that are locked in the Startup code. The implementation is only
 *             needed on platforms, where all cores are started automatically
 *             after a power-on reset. All additional cores are looped, until
 *             the boot core reaches this function.
 * @pre        -
 * @param[in]  uint32 coreId
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainStartup on the boot core.
 *****************************************************************************/
void BrsHw_UnlockCores(uint32 coreId)
{
  /* The mechanism is not used/needed on this platform */
}
#endif /*BRS_ENABLE_OS_MULTICORESUPPORT*/
