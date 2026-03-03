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
 *              File: Os_MemoryProtection_Lcfg.h
 *   Generation Time: 2024-02-13 13:07:51
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_MEMORYPROTECTION_LCFG_H
# define OS_MEMORYPROTECTION_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_MemoryProtection_Types.h"

/* Os kernel module dependencies */

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Memory protection configuration data */
extern CONST(Os_MpCoreConfigType, OS_CONST) OsCfg_Mp_OsCore0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsApplication_QM;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsApplication_Safety;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsApplication_Trusted_Core0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SystemApplication_OsCore0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_ADC0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_ADC1;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Can_30_McanIsr_0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Can_30_McanIsr_1;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CounterIsr_SystemTimer;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_I2c_IrqUnit0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_I2c_IrqUnit1;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_IPC_mailbox1;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_IPC_mailbox2;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MAIN_ESM0_ESM_INT_CFG_LVL_0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MAIN_ESM0_ESM_INT_HI_LVL_0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MAIN_ESM0_ESM_INT_LOW_LVL_0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MCU_ESM0_ESM_INT_CFG_LVL_0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MCU_ESM0_ESM_INT_HI_LVL_0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MCU_ESM0_ESM_INT_LOW_LVL_0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SciServer_OsIsr_UserMsgHwiFxn1;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SciServer_OsIsr_UserMsgHwiFxn2;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SciServer_OsIsr_UserMsgHwiFxn3;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SciServer_OsIsr_UserMsgHwiFxn4;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_WKUP_ESM0_ESM_INT_CFG_LVL_0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_WKUP_ESM0_ESM_INT_HI_LVL_0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_WKUP_ESM0_ESM_INT_LOW_LVL_0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_vHsmResponseIsr;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_BootAppOsTask;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_IdleTask_OsCore0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_ComTask_10ms;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_ComTask_5ms;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_DiagTask_10ms;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_MemTask_10ms;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_Task_00_10ms;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_Task_01_10ms;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_Task_200ms;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_QM_Task_Init;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Safety_Task_00_10ms;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Safety_Task_01_10ms;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Safety_Task_200ms;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Safety_Task_Init;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Safety_WdgTask_10ms;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SciServerHighOsTask;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SciServerLowOsTask;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_ShutdownTask;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_StartUpTask;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Memory protection configuration data */
extern CONST(Os_MpSystemConfigType, OS_CONST) OsCfg_Mp_SystemMpu;

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_MEMORYPROTECTION_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_MemoryProtection_Lcfg.h
 *********************************************************************************************************************/
