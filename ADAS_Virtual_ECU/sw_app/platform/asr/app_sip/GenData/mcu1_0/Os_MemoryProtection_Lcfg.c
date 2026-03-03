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
 *              File: Os_MemoryProtection_Lcfg.c
 *   Generation Time: 2024-02-13 13:07:50
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_MEMORYROTECTION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_MemoryProtection.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_MemoryProtection_Lcfg.h"


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

/*! Memory protection configuration data: OsCore0 */
CONST(Os_MpCoreConfigType, OS_CONST) OsCfg_Mp_OsCore0 =
{
  /* .HwConfig = */ &OsCfg_Hal_Mp_OsCore0
};

/*! Memory protection configuration data: OsApplication_QM */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsApplication_QM =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_QM,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EmptyThread
};

/*! Memory protection configuration data: OsApplication_Safety */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsApplication_Safety =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Safety,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EmptyThread
};

/*! Memory protection configuration data: OsApplication_Trusted_Core0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsApplication_Trusted_Core0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trusted_Core0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EmptyThread
};

/*! Memory protection configuration data: SystemApplication_OsCore0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SystemApplication_OsCore0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EmptyThread
};

/*! Memory protection configuration data: ADC0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_ADC0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_ADC0
};

/*! Memory protection configuration data: ADC1 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_ADC1 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_ADC1
};

/*! Memory protection configuration data: Can_30_McanIsr_0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Can_30_McanIsr_0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Can_30_McanIsr_0
};

/*! Memory protection configuration data: Can_30_McanIsr_1 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Can_30_McanIsr_1 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Can_30_McanIsr_1
};

/*! Memory protection configuration data: CounterIsr_SystemTimer */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CounterIsr_SystemTimer =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_CounterIsr_SystemTimer
};

/*! Memory protection configuration data: I2c_IrqUnit0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_I2c_IrqUnit0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_I2c_IrqUnit0
};

/*! Memory protection configuration data: I2c_IrqUnit1 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_I2c_IrqUnit1 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_I2c_IrqUnit1
};

/*! Memory protection configuration data: IPC_mailbox1 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_IPC_mailbox1 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_IPC_mailbox1
};

/*! Memory protection configuration data: IPC_mailbox2 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_IPC_mailbox2 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_IPC_mailbox2
};

/*! Memory protection configuration data: MAIN_ESM0_ESM_INT_CFG_LVL_0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MAIN_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_MAIN_ESM0_ESM_INT_CFG_LVL_0
};

/*! Memory protection configuration data: MAIN_ESM0_ESM_INT_HI_LVL_0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MAIN_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_MAIN_ESM0_ESM_INT_HI_LVL_0
};

/*! Memory protection configuration data: MAIN_ESM0_ESM_INT_LOW_LVL_0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MAIN_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_MAIN_ESM0_ESM_INT_LOW_LVL_0
};

/*! Memory protection configuration data: MCU_ESM0_ESM_INT_CFG_LVL_0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MCU_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_MCU_ESM0_ESM_INT_CFG_LVL_0
};

/*! Memory protection configuration data: MCU_ESM0_ESM_INT_HI_LVL_0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MCU_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_MCU_ESM0_ESM_INT_HI_LVL_0
};

/*! Memory protection configuration data: MCU_ESM0_ESM_INT_LOW_LVL_0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MCU_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_MCU_ESM0_ESM_INT_LOW_LVL_0
};

/*! Memory protection configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78
};

/*! Memory protection configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304
};

/*! Memory protection configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305
};

/*! Memory protection configuration data: SciServer_OsIsr_UserMsgHwiFxn1 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SciServer_OsIsr_UserMsgHwiFxn1 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SciServer_OsIsr_UserMsgHwiFxn1
};

/*! Memory protection configuration data: SciServer_OsIsr_UserMsgHwiFxn2 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SciServer_OsIsr_UserMsgHwiFxn2 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SciServer_OsIsr_UserMsgHwiFxn2
};

/*! Memory protection configuration data: SciServer_OsIsr_UserMsgHwiFxn3 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SciServer_OsIsr_UserMsgHwiFxn3 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SciServer_OsIsr_UserMsgHwiFxn3
};

/*! Memory protection configuration data: SciServer_OsIsr_UserMsgHwiFxn4 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SciServer_OsIsr_UserMsgHwiFxn4 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SciServer_OsIsr_UserMsgHwiFxn4
};

/*! Memory protection configuration data: WKUP_ESM0_ESM_INT_CFG_LVL_0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_WKUP_ESM0_ESM_INT_CFG_LVL_0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_WKUP_ESM0_ESM_INT_CFG_LVL_0
};

/*! Memory protection configuration data: WKUP_ESM0_ESM_INT_HI_LVL_0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_WKUP_ESM0_ESM_INT_HI_LVL_0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_WKUP_ESM0_ESM_INT_HI_LVL_0
};

/*! Memory protection configuration data: WKUP_ESM0_ESM_INT_LOW_LVL_0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_WKUP_ESM0_ESM_INT_LOW_LVL_0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_WKUP_ESM0_ESM_INT_LOW_LVL_0
};

/*! Memory protection configuration data: vHsmResponseIsr */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_vHsmResponseIsr =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_vHsmResponseIsr
};

/*! Memory protection configuration data: BootAppOsTask */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_BootAppOsTask =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_BootAppOsTask
};

/*! Memory protection configuration data: IdleTask_OsCore0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_IdleTask_OsCore0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_IdleTask_OsCore0
};

/*! Memory protection configuration data: QM_ComTask_10ms */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_ComTask_10ms =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_QM,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_QM_ComTask_10ms
};

/*! Memory protection configuration data: QM_ComTask_5ms */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_ComTask_5ms =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_QM,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_QM_ComTask_5ms
};

/*! Memory protection configuration data: QM_DiagTask_10ms */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_DiagTask_10ms =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_QM,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_QM_DiagTask_10ms
};

/*! Memory protection configuration data: QM_MemTask_10ms */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_MemTask_10ms =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_QM,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_QM_MemTask_10ms
};

/*! Memory protection configuration data: QM_Task_00_10ms */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_Task_00_10ms =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_QM,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_QM_Task_00_10ms
};

/*! Memory protection configuration data: QM_Task_01_10ms */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_Task_01_10ms =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_QM,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_QM_Task_01_10ms
};

/*! Memory protection configuration data: QM_Task_200ms */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_Task_200ms =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_QM,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_QM_Task_200ms
};

/*! Memory protection configuration data: QM_Task_Init */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_Task_Init =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_QM,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_QM_Task_Init
};

/*! Memory protection configuration data: Safety_Task_00_10ms */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Safety_Task_00_10ms =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Safety,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Safety_Task_00_10ms
};

/*! Memory protection configuration data: Safety_Task_01_10ms */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Safety_Task_01_10ms =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Safety,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Safety_Task_01_10ms
};

/*! Memory protection configuration data: Safety_Task_200ms */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Safety_Task_200ms =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Safety,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Safety_Task_200ms
};

/*! Memory protection configuration data: Safety_Task_Init */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Safety_Task_Init =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Safety,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Safety_Task_Init
};

/*! Memory protection configuration data: Safety_WdgTask_10ms */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Safety_WdgTask_10ms =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Safety,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Safety_WdgTask_10ms
};

/*! Memory protection configuration data: SciServerHighOsTask */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SciServerHighOsTask =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SciServerHighOsTask
};

/*! Memory protection configuration data: SciServerLowOsTask */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SciServerLowOsTask =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SciServerLowOsTask
};

/*! Memory protection configuration data: ShutdownTask */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_ShutdownTask =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_ShutdownTask
};

/*! Memory protection configuration data: StartUpTask */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_StartUpTask =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_StartUpTask
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Memory protection configuration data: SystemMpu */
CONST(Os_MpSystemConfigType, OS_CONST) OsCfg_Mp_SystemMpu =
{
  /* .HwConfig = */ &OsCfg_Hal_Mp_SystemMpu
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
 *  END OF FILE: Os_MemoryProtection_Lcfg.c
 *********************************************************************************************************************/
