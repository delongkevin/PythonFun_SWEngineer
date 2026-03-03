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
 *            Module: vLinkGen
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vLinkGen_Lcfg.c
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
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

#define VLINKGEN_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "vLinkGen_Lcfg.h"

/**********************************************************************************************************************
 *  VARIANT CHECK
 *********************************************************************************************************************/

/* Check that one of the configured variants is defined in the current build process. */
#if (  !defined (DemoBm) \
    && !defined (DemoFbl) \
    && !defined (DemoAppl) \
    && !defined (DemoUpd) )
# error "If variants are configured, one of them must always be defined in the build environment (e.g. via compiler option)."
#endif

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

/* Memory region blocks to be initialized with zeros in stage Early */
const vLinkGen_MemArea vLinkGen_ZeroInit_Early_Blocks[VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Memory region blocks to be initialized with zeros in stage One */
const vLinkGen_MemArea vLinkGen_ZeroInit_One_Blocks[VLINKGEN_CFG_NUM_ZERO_INIT_ONE_BLOCKS] =
{
  { /*  DataBssRegion_Shared  */ 
     /*  .Start  */ (uint32)0x700C0000u, 
     /*  .End  */ (uint32)0x700C0100u, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  { /*  DataBssRegion  */ 
     /*  .Start  */ (uint32)0x700C0100u, 
     /*  .End  */ (uint32)0x70120000u, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Memory region blocks to be initialized with zeros in stage HardReset */
const vLinkGen_MemArea vLinkGen_ZeroInit_HardReset_Blocks[VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_BLOCKS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

#ifdef DemoBm
/* Section groups to be initialized with zeros in stage Early of variant: DemoBm */
const vLinkGen_MemArea vLinkGen_ZeroInit_Early_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS] =
{
  { /*  STACK_C0  */ 
     /*  .Start  */ (uint32)_STACK_C0_START, 
     /*  .End  */ (uint32)_STACK_C0_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage Zero of variant: DemoBm */
const vLinkGen_MemArea vLinkGen_ZeroInit_Zero_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage One of variant: DemoBm */
const vLinkGen_MemArea vLinkGen_ZeroInit_One_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS] =
{
  { /*  RamBssSecGroup  */ 
     /*  .Start  */ (uint32)_RamBssSecGroup_START, 
     /*  .End  */ (uint32)_RamBssSecGroup_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage Two of variant: DemoBm */
const vLinkGen_MemArea vLinkGen_ZeroInit_Two_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage Three of variant: DemoBm */
const vLinkGen_MemArea vLinkGen_ZeroInit_Three_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage HardReset of variant: DemoBm */
const vLinkGen_MemArea vLinkGen_ZeroInit_HardReset_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage Zero of variant: DemoBm */
const vLinkGen_RamMemArea vLinkGen_Init_Zero_Groups[VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage One of variant: DemoBm */
const vLinkGen_RamMemArea vLinkGen_Init_One_Groups[VLINKGEN_CFG_NUM_INIT_ONE_GROUPS] =
{
  { /*  MasterSatelliteSharedRamSection  */ 
     /*  .Start  */ (uint32)_MasterSatelliteSharedRamSection_START, 
     /*  .End  */ (uint32)_MasterSatelliteSharedRamSection_LIMIT, 
     /*  .Romstart  */ (uint32)_MasterSatelliteSharedRamSection_ROM_START, 
     /*  .Romend  */ (uint32)_MasterSatelliteSharedRamSection_ROM_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  { /*  RamDataSecGroup  */ 
     /*  .Start  */ (uint32)_RamDataSecGroup_START, 
     /*  .End  */ (uint32)_RamDataSecGroup_LIMIT, 
     /*  .Romstart  */ (uint32)_RamDataSecGroup_ROM_START, 
     /*  .Romend  */ (uint32)_RamDataSecGroup_ROM_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage Two of variant: DemoBm */
const vLinkGen_RamMemArea vLinkGen_Init_Two_Groups[VLINKGEN_CFG_NUM_INIT_TWO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage Three of variant: DemoBm */
const vLinkGen_RamMemArea vLinkGen_Init_Three_Groups[VLINKGEN_CFG_NUM_INIT_THREE_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage HardReset of variant: DemoBm */
const vLinkGen_RamMemArea vLinkGen_Init_HardReset_Groups[VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};
#endif /* DemoBm */

#ifdef DemoFbl
/* Section groups to be initialized with zeros in stage Early of variant: DemoFbl */
const vLinkGen_MemArea vLinkGen_ZeroInit_Early_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS] =
{
  { /*  STACK_C0  */ 
     /*  .Start  */ (uint32)_STACK_C0_START, 
     /*  .End  */ (uint32)_STACK_C0_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage Zero of variant: DemoFbl */
const vLinkGen_MemArea vLinkGen_ZeroInit_Zero_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage One of variant: DemoFbl */
const vLinkGen_MemArea vLinkGen_ZeroInit_One_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS] =
{
  { /*  RamBssSecGroup  */ 
     /*  .Start  */ (uint32)_RamBssSecGroup_START, 
     /*  .End  */ (uint32)_RamBssSecGroup_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage Two of variant: DemoFbl */
const vLinkGen_MemArea vLinkGen_ZeroInit_Two_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage Three of variant: DemoFbl */
const vLinkGen_MemArea vLinkGen_ZeroInit_Three_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage HardReset of variant: DemoFbl */
const vLinkGen_MemArea vLinkGen_ZeroInit_HardReset_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage Zero of variant: DemoFbl */
const vLinkGen_RamMemArea vLinkGen_Init_Zero_Groups[VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage One of variant: DemoFbl */
const vLinkGen_RamMemArea vLinkGen_Init_One_Groups[VLINKGEN_CFG_NUM_INIT_ONE_GROUPS] =
{
  { /*  MasterSatelliteSharedRamSection  */ 
     /*  .Start  */ (uint32)_MasterSatelliteSharedRamSection_START, 
     /*  .End  */ (uint32)_MasterSatelliteSharedRamSection_LIMIT, 
     /*  .Romstart  */ (uint32)_MasterSatelliteSharedRamSection_ROM_START, 
     /*  .Romend  */ (uint32)_MasterSatelliteSharedRamSection_ROM_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  { /*  RamDataSecGroup  */ 
     /*  .Start  */ (uint32)_RamDataSecGroup_START, 
     /*  .End  */ (uint32)_RamDataSecGroup_LIMIT, 
     /*  .Romstart  */ (uint32)_RamDataSecGroup_ROM_START, 
     /*  .Romend  */ (uint32)_RamDataSecGroup_ROM_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage Two of variant: DemoFbl */
const vLinkGen_RamMemArea vLinkGen_Init_Two_Groups[VLINKGEN_CFG_NUM_INIT_TWO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage Three of variant: DemoFbl */
const vLinkGen_RamMemArea vLinkGen_Init_Three_Groups[VLINKGEN_CFG_NUM_INIT_THREE_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage HardReset of variant: DemoFbl */
const vLinkGen_RamMemArea vLinkGen_Init_HardReset_Groups[VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};
#endif /* DemoFbl */

#ifdef DemoAppl
/* Section groups to be initialized with zeros in stage Early of variant: DemoAppl */
const vLinkGen_MemArea vLinkGen_ZeroInit_Early_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS] =
{
  { /*  STACK_C0  */ 
     /*  .Start  */ (uint32)_STACK_C0_START, 
     /*  .End  */ (uint32)_STACK_C0_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage Zero of variant: DemoAppl */
const vLinkGen_MemArea vLinkGen_ZeroInit_Zero_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage One of variant: DemoAppl */
const vLinkGen_MemArea vLinkGen_ZeroInit_One_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS] =
{
  { /*  RamBssSecGroup  */ 
     /*  .Start  */ (uint32)_RamBssSecGroup_START, 
     /*  .End  */ (uint32)_RamBssSecGroup_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage Two of variant: DemoAppl */
const vLinkGen_MemArea vLinkGen_ZeroInit_Two_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage Three of variant: DemoAppl */
const vLinkGen_MemArea vLinkGen_ZeroInit_Three_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage HardReset of variant: DemoAppl */
const vLinkGen_MemArea vLinkGen_ZeroInit_HardReset_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage Zero of variant: DemoAppl */
const vLinkGen_RamMemArea vLinkGen_Init_Zero_Groups[VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage One of variant: DemoAppl */
const vLinkGen_RamMemArea vLinkGen_Init_One_Groups[VLINKGEN_CFG_NUM_INIT_ONE_GROUPS] =
{
  { /*  MasterSatelliteSharedRamSection  */ 
     /*  .Start  */ (uint32)_MasterSatelliteSharedRamSection_START, 
     /*  .End  */ (uint32)_MasterSatelliteSharedRamSection_LIMIT, 
     /*  .Romstart  */ (uint32)_MasterSatelliteSharedRamSection_ROM_START, 
     /*  .Romend  */ (uint32)_MasterSatelliteSharedRamSection_ROM_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  { /*  RamDataSecGroup  */ 
     /*  .Start  */ (uint32)_RamDataSecGroup_START, 
     /*  .End  */ (uint32)_RamDataSecGroup_LIMIT, 
     /*  .Romstart  */ (uint32)_RamDataSecGroup_ROM_START, 
     /*  .Romend  */ (uint32)_RamDataSecGroup_ROM_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage Two of variant: DemoAppl */
const vLinkGen_RamMemArea vLinkGen_Init_Two_Groups[VLINKGEN_CFG_NUM_INIT_TWO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage Three of variant: DemoAppl */
const vLinkGen_RamMemArea vLinkGen_Init_Three_Groups[VLINKGEN_CFG_NUM_INIT_THREE_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage HardReset of variant: DemoAppl */
const vLinkGen_RamMemArea vLinkGen_Init_HardReset_Groups[VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};
#endif /* DemoAppl */

#ifdef DemoUpd
/* Section groups to be initialized with zeros in stage Early of variant: DemoUpd */
const vLinkGen_MemArea vLinkGen_ZeroInit_Early_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS] =
{
  { /*  STACK_C0  */ 
     /*  .Start  */ (uint32)_STACK_C0_START, 
     /*  .End  */ (uint32)_STACK_C0_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage Zero of variant: DemoUpd */
const vLinkGen_MemArea vLinkGen_ZeroInit_Zero_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage One of variant: DemoUpd */
const vLinkGen_MemArea vLinkGen_ZeroInit_One_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS] =
{
  { /*  RamBssSecGroup  */ 
     /*  .Start  */ (uint32)_RamBssSecGroup_START, 
     /*  .End  */ (uint32)_RamBssSecGroup_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage Two of variant: DemoUpd */
const vLinkGen_MemArea vLinkGen_ZeroInit_Two_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage Three of variant: DemoUpd */
const vLinkGen_MemArea vLinkGen_ZeroInit_Three_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with zeros in stage HardReset of variant: DemoUpd */
const vLinkGen_MemArea vLinkGen_ZeroInit_HardReset_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage Zero of variant: DemoUpd */
const vLinkGen_RamMemArea vLinkGen_Init_Zero_Groups[VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage One of variant: DemoUpd */
const vLinkGen_RamMemArea vLinkGen_Init_One_Groups[VLINKGEN_CFG_NUM_INIT_ONE_GROUPS] =
{
  { /*  MasterSatelliteSharedRamSection  */ 
     /*  .Start  */ (uint32)_MasterSatelliteSharedRamSection_START, 
     /*  .End  */ (uint32)_MasterSatelliteSharedRamSection_LIMIT, 
     /*  .Romstart  */ (uint32)_MasterSatelliteSharedRamSection_ROM_START, 
     /*  .Romend  */ (uint32)_MasterSatelliteSharedRamSection_ROM_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  { /*  RamDataSecGroup  */ 
     /*  .Start  */ (uint32)_RamDataSecGroup_START, 
     /*  .End  */ (uint32)_RamDataSecGroup_LIMIT, 
     /*  .Romstart  */ (uint32)_RamDataSecGroup_ROM_START, 
     /*  .Romend  */ (uint32)_RamDataSecGroup_ROM_LIMIT, 
     /*  .Core  */ 0u, 
     /*  .Alignment  */ 0u
  }, 
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage Two of variant: DemoUpd */
const vLinkGen_RamMemArea vLinkGen_Init_Two_Groups[VLINKGEN_CFG_NUM_INIT_TWO_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage Three of variant: DemoUpd */
const vLinkGen_RamMemArea vLinkGen_Init_Three_Groups[VLINKGEN_CFG_NUM_INIT_THREE_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};

/* Section groups to be initialized with concrete data in stage HardReset of variant: DemoUpd */
const vLinkGen_RamMemArea vLinkGen_Init_HardReset_Groups[VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS] =
{
  {
    0u, 
    0u, 
    0u, 
    0u, 
    0u, 
    0u
  }
};
#endif /* DemoUpd */

/* Memory region blocks to be initialized with zeros in stage Early */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Early_BlocksSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS, 
  vLinkGen_ZeroInit_Early_Blocks
};

/* Memory region blocks to be initialized with zeros in stage One */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_One_BlocksSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_ONE_BLOCKS, 
  vLinkGen_ZeroInit_One_Blocks
};

/* Memory region blocks to be initialized with zeros in stage HardReset */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_HardReset_BlocksSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_BLOCKS, 
  vLinkGen_ZeroInit_HardReset_Blocks
};

/* Section groups to be initialized with zeros in stage Early */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Early_GroupsSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS, 
  vLinkGen_ZeroInit_Early_Groups
};

/* Section groups to be initialized with zeros in stage Zero */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Zero_GroupsSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS, 
  vLinkGen_ZeroInit_Zero_Groups
};

/* Section groups to be initialized with zeros in stage One */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_One_GroupsSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS, 
  vLinkGen_ZeroInit_One_Groups
};

/* Section groups to be initialized with zeros in stage Two */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Two_GroupsSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS, 
  vLinkGen_ZeroInit_Two_Groups
};

/* Section groups to be initialized with zeros in stage Three */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Three_GroupsSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS, 
  vLinkGen_ZeroInit_Three_Groups
};

/* Section groups to be initialized with zeros in stage HardReset */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_HardReset_GroupsSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS, 
  vLinkGen_ZeroInit_HardReset_Groups
};

/* Section groups to be initialized with concrete data in stage Zero */
const vLinkGen_RamMemAreaSet vLinkGen_Init_Zero_GroupsSet =
{
  VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS, 
  vLinkGen_Init_Zero_Groups
};

/* Section groups to be initialized with concrete data in stage One */
const vLinkGen_RamMemAreaSet vLinkGen_Init_One_GroupsSet =
{
  VLINKGEN_CFG_NUM_INIT_ONE_GROUPS, 
  vLinkGen_Init_One_Groups
};

/* Section groups to be initialized with concrete data in stage Two */
const vLinkGen_RamMemAreaSet vLinkGen_Init_Two_GroupsSet =
{
  VLINKGEN_CFG_NUM_INIT_TWO_GROUPS, 
  vLinkGen_Init_Two_Groups
};

/* Section groups to be initialized with concrete data in stage Three */
const vLinkGen_RamMemAreaSet vLinkGen_Init_Three_GroupsSet =
{
  VLINKGEN_CFG_NUM_INIT_THREE_GROUPS, 
  vLinkGen_Init_Three_Groups
};

/* Section groups to be initialized with concrete data in stage HardReset */
const vLinkGen_RamMemAreaSet vLinkGen_Init_HardReset_GroupsSet =
{
  VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS, 
  vLinkGen_Init_HardReset_Groups
};

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
 *  END OF FILE: vLinkGen_Lcfg.c
 *********************************************************************************************************************/
