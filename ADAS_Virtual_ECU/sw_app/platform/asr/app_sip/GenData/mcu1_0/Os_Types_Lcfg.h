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
 *              File: Os_Types_Lcfg.h
 *   Generation Time: 2025-07-22 16:40:31
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_TYPES_LCFG_H
# define OS_TYPES_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* OS-Application identifiers. */
#define OsApplication_QM OsApplication_QM
#define OsApplication_Safety OsApplication_Safety
#define OsApplication_Trusted_Core0 OsApplication_Trusted_Core0
#define SystemApplication_OsCore0 SystemApplication_OsCore0

/* Trusted function identifiers. */
#define Os_ServiceCallee_Appl_vDamRemapNrcCalloutFunc Os_ServiceCallee_Appl_vDamRemapNrcCalloutFunc
#define Os_ServiceCallee_CanWUp_Val_CheckPN Os_ServiceCallee_CanWUp_Val_CheckPN
#define Os_ServiceCallee_CanWUp_Val_StartWakeUpValidation Os_ServiceCallee_CanWUp_Val_StartWakeUpValidation
#define Os_ServiceCallee_CanWUp_Val_StopWakeUpValidation Os_ServiceCallee_CanWUp_Val_StopWakeUpValidation
#define Os_ServiceCallee_CddIpcHandler_Init Os_ServiceCallee_CddIpcHandler_Init
#define Os_ServiceCallee_CddIpcHandler_Main Os_ServiceCallee_CddIpcHandler_Main
#define Os_ServiceCallee_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus Os_ServiceCallee_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus
#define Os_ServiceCallee_DcmCalloutStub_CompareKey Os_ServiceCallee_DcmCalloutStub_CompareKey
#define Os_ServiceCallee_DcmCalloutStub_GetSeed Os_ServiceCallee_DcmCalloutStub_GetSeed
#define Os_ServiceCallee_DcmCalloutStub_SessionCallback Os_ServiceCallee_DcmCalloutStub_SessionCallback
#define Os_ServiceCallee_Det_UserReportError Os_ServiceCallee_Det_UserReportError
#define Os_ServiceCallee_PMIC_EnterLongWindow_DisableWdg Os_ServiceCallee_PMIC_EnterLongWindow_DisableWdg
#define Os_ServiceCallee_Pmic_AppEnterInLongWindow Os_ServiceCallee_Pmic_AppEnterInLongWindow
#define Os_ServiceCallee_Pmic_F_SafeState2_v Os_ServiceCallee_Pmic_F_SafeState2_v
#define Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamCalibReset Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamCalibReset
#define Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock
#define Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock
#define Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock
#define Os_ServiceCallee_RE_DID2023_ProxiData Os_ServiceCallee_RE_DID2023_ProxiData
#define Os_ServiceCallee_RE_IntrinsicCameraSN_Readblock Os_ServiceCallee_RE_IntrinsicCameraSN_Readblock
#define Os_ServiceCallee_RE_IpcTxData Os_ServiceCallee_RE_IpcTxData
#define Os_ServiceCallee_RE_MCUReadDeviceReg Os_ServiceCallee_RE_MCUReadDeviceReg
#define Os_ServiceCallee_RE_MCUReadDeviceRegData Os_ServiceCallee_RE_MCUReadDeviceRegData
#define Os_ServiceCallee_RE_MCUWriteDeviceReg Os_ServiceCallee_RE_MCUWriteDeviceReg
#define Os_ServiceCallee_RE_ReportErrorStatus1_0_B Os_ServiceCallee_RE_ReportErrorStatus1_0_B
#define Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx
#define Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx
#define Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx
#define Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx
#define Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx
#define Os_ServiceCallee_ShutdownOS Os_ServiceCallee_ShutdownOS
#define Os_ServiceCallee_Update_CDD_IPCHandler_MirrorBlock Os_ServiceCallee_Update_CDD_IPCHandler_MirrorBlock
#define Os_ServiceCallee_Update_CalDataProvider_MirrorBlock Os_ServiceCallee_Update_CalDataProvider_MirrorBlock
#define Os_ServiceCallee_Update_Cdd_Safety_MirrorBlock Os_ServiceCallee_Update_Cdd_Safety_MirrorBlock
#define Os_ServiceCallee_Update_ComCallout_FlagStatus Os_ServiceCallee_Update_ComCallout_FlagStatus
#define Os_ServiceCallee_Update_Proxi_MirrorBlock Os_ServiceCallee_Update_Proxi_MirrorBlock
#define Os_ServiceCallee_Update_SafetyGuard_MirrorBlock Os_ServiceCallee_Update_SafetyGuard_MirrorBlock
#define Os_ServiceCallee_f_Send_Dbg_SDLFault_CanTx Os_ServiceCallee_f_Send_Dbg_SDLFault_CanTx
#define Os_ServiceCallee_f_Send_Dbg_SSMFault_CanTx Os_ServiceCallee_f_Send_Dbg_SSMFault_CanTx

/* Non-trusted function identifiers. */

/* Fast trusted function identifiers. */

/* Task identifiers. */
#define BootAppOsTask BootAppOsTask
#define IdleTask_OsCore0 IdleTask_OsCore0
#define QM_ComTask_10ms QM_ComTask_10ms
#define QM_ComTask_5ms QM_ComTask_5ms
#define QM_DiagTask_10ms QM_DiagTask_10ms
#define QM_MemTask_10ms QM_MemTask_10ms
#define QM_Task_00_10ms QM_Task_00_10ms
#define QM_Task_01_10ms QM_Task_01_10ms
#define QM_Task_200ms QM_Task_200ms
#define QM_Task_Init QM_Task_Init
#define Safety_Task_00_10ms Safety_Task_00_10ms
#define Safety_Task_01_10ms Safety_Task_01_10ms
#define Safety_Task_200ms Safety_Task_200ms
#define Safety_Task_Init Safety_Task_Init
#define Safety_WdgTask_10ms Safety_WdgTask_10ms
#define SciServerHighOsTask SciServerHighOsTask
#define SciServerLowOsTask SciServerLowOsTask
#define ShutdownTask ShutdownTask
#define StartUpTask StartUpTask

/* Category 2 ISR identifiers. */
#define ADC0 ADC0
#define ADC1 ADC1
#define Can_30_McanIsr_0 Can_30_McanIsr_0
#define Can_30_McanIsr_1 Can_30_McanIsr_1
#define CounterIsr_SystemTimer CounterIsr_SystemTimer
#define I2c_IrqUnit0 I2c_IrqUnit0
#define I2c_IrqUnit1 I2c_IrqUnit1
#define IPC_mailbox1 IPC_mailbox1
#define IPC_mailbox2 IPC_mailbox2
#define MAIN_ESM0_ESM_INT_CFG_LVL_0 MAIN_ESM0_ESM_INT_CFG_LVL_0
#define MAIN_ESM0_ESM_INT_HI_LVL_0 MAIN_ESM0_ESM_INT_HI_LVL_0
#define MAIN_ESM0_ESM_INT_LOW_LVL_0 MAIN_ESM0_ESM_INT_LOW_LVL_0
#define MCU_ESM0_ESM_INT_CFG_LVL_0 MCU_ESM0_ESM_INT_CFG_LVL_0
#define MCU_ESM0_ESM_INT_HI_LVL_0 MCU_ESM0_ESM_INT_HI_LVL_0
#define MCU_ESM0_ESM_INT_LOW_LVL_0 MCU_ESM0_ESM_INT_LOW_LVL_0
#define MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78
#define MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79
#define SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317
#define SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295
#define SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296
#define SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291
#define SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290
#define SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299
#define SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297
#define SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298
#define SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300
#define SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47
#define SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36
#define SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37
#define SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312
#define SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310
#define SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314
#define SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313
#define SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309
#define SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307
#define SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308
#define SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306
#define SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304
#define SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305
#define SciServer_OsIsr_UserMsgHwiFxn1 SciServer_OsIsr_UserMsgHwiFxn1
#define SciServer_OsIsr_UserMsgHwiFxn2 SciServer_OsIsr_UserMsgHwiFxn2
#define SciServer_OsIsr_UserMsgHwiFxn3 SciServer_OsIsr_UserMsgHwiFxn3
#define SciServer_OsIsr_UserMsgHwiFxn4 SciServer_OsIsr_UserMsgHwiFxn4
#define WKUP_ESM0_ESM_INT_CFG_LVL_0 WKUP_ESM0_ESM_INT_CFG_LVL_0
#define WKUP_ESM0_ESM_INT_HI_LVL_0 WKUP_ESM0_ESM_INT_HI_LVL_0
#define WKUP_ESM0_ESM_INT_LOW_LVL_0 WKUP_ESM0_ESM_INT_LOW_LVL_0
#define vHsmResponseIsr vHsmResponseIsr

/* Alarm identifiers. */
#define Rte_Al_TE2_QM_ComTask_10ms_0_10ms Rte_Al_TE2_QM_ComTask_10ms_0_10ms
#define Rte_Al_TE2_QM_ComTask_5ms_5_5ms Rte_Al_TE2_QM_ComTask_5ms_5_5ms
#define Rte_Al_TE2_QM_DiagTask_10ms_0_10ms Rte_Al_TE2_QM_DiagTask_10ms_0_10ms
#define Rte_Al_TE2_QM_MemTask_10ms_0_10ms Rte_Al_TE2_QM_MemTask_10ms_0_10ms
#define Rte_Al_TE2_QM_Task_200ms_0_200ms Rte_Al_TE2_QM_Task_200ms_0_200ms
#define Rte_Al_TE2_Safety_WdgTask_10ms_0_10ms Rte_Al_TE2_Safety_WdgTask_10ms_0_10ms
#define Rte_Al_TE_QM_ComTask_10ms_0_10ms Rte_Al_TE_QM_ComTask_10ms_0_10ms
#define Rte_Al_TE_QM_ComTask_5ms_0_5ms Rte_Al_TE_QM_ComTask_5ms_0_5ms
#define Rte_Al_TE_QM_DiagTask_10ms_0_10ms Rte_Al_TE_QM_DiagTask_10ms_0_10ms
#define Rte_Al_TE_QM_MemTask_10ms_0_10ms Rte_Al_TE_QM_MemTask_10ms_0_10ms
#define Rte_Al_TE_QM_Task_00_10ms_0_10ms Rte_Al_TE_QM_Task_00_10ms_0_10ms
#define Rte_Al_TE_QM_Task_01_10ms_0_10ms Rte_Al_TE_QM_Task_01_10ms_0_10ms
#define Rte_Al_TE_QM_Task_200ms_0_200ms Rte_Al_TE_QM_Task_200ms_0_200ms
#define Rte_Al_TE_Safety_Task_00_10ms_0_10ms Rte_Al_TE_Safety_Task_00_10ms_0_10ms
#define Rte_Al_TE_Safety_Task_01_10ms_0_10ms Rte_Al_TE_Safety_Task_01_10ms_0_10ms
#define Rte_Al_TE_Safety_Task_200ms_0_200ms Rte_Al_TE_Safety_Task_200ms_0_200ms
#define Rte_Al_TE_Safety_WdgTask_10ms_0_10ms Rte_Al_TE_Safety_WdgTask_10ms_0_10ms

/* Counter identifiers. */
#define SystemTimer SystemTimer

/* ScheduleTable identifiers. */

/* Resource identifiers. */
#define OsResource OsResource
#define OsResource_PMIC OsResource_PMIC
#define OsResource_SciSecureproxy OsResource_SciSecureproxy
#define OsResource_SciServerSync OsResource_SciServerSync

/* Spinlock identifiers. */

/* Peripheral identifiers. */

/* Barrier identifiers. */

/* Trace OS-Application identifiers (All OS-Applications inclusive system objects). */
#define Os_TraceId_OsApplication_QM Os_TraceId_OsApplication_QM
#define Os_TraceId_OsApplication_Safety Os_TraceId_OsApplication_Safety
#define Os_TraceId_OsApplication_Trusted_Core0 Os_TraceId_OsApplication_Trusted_Core0
#define Os_TraceId_SystemApplication_OsCore0 Os_TraceId_SystemApplication_OsCore0

/* Trace thread identifiers (Tasks and ISRs inclusive system objects). */
#define Os_TraceId_BootAppOsTask Os_TraceId_BootAppOsTask
#define Os_TraceId_IdleTask_OsCore0 Os_TraceId_IdleTask_OsCore0
#define Os_TraceId_QM_ComTask_10ms Os_TraceId_QM_ComTask_10ms
#define Os_TraceId_QM_ComTask_5ms Os_TraceId_QM_ComTask_5ms
#define Os_TraceId_QM_DiagTask_10ms Os_TraceId_QM_DiagTask_10ms
#define Os_TraceId_QM_MemTask_10ms Os_TraceId_QM_MemTask_10ms
#define Os_TraceId_QM_Task_00_10ms Os_TraceId_QM_Task_00_10ms
#define Os_TraceId_QM_Task_01_10ms Os_TraceId_QM_Task_01_10ms
#define Os_TraceId_QM_Task_200ms Os_TraceId_QM_Task_200ms
#define Os_TraceId_QM_Task_Init Os_TraceId_QM_Task_Init
#define Os_TraceId_Safety_Task_00_10ms Os_TraceId_Safety_Task_00_10ms
#define Os_TraceId_Safety_Task_01_10ms Os_TraceId_Safety_Task_01_10ms
#define Os_TraceId_Safety_Task_200ms Os_TraceId_Safety_Task_200ms
#define Os_TraceId_Safety_Task_Init Os_TraceId_Safety_Task_Init
#define Os_TraceId_Safety_WdgTask_10ms Os_TraceId_Safety_WdgTask_10ms
#define Os_TraceId_SciServerHighOsTask Os_TraceId_SciServerHighOsTask
#define Os_TraceId_SciServerLowOsTask Os_TraceId_SciServerLowOsTask
#define Os_TraceId_ShutdownTask Os_TraceId_ShutdownTask
#define Os_TraceId_StartUpTask Os_TraceId_StartUpTask
#define Os_TraceId_ADC0 Os_TraceId_ADC0
#define Os_TraceId_ADC1 Os_TraceId_ADC1
#define Os_TraceId_Can_30_McanIsr_0 Os_TraceId_Can_30_McanIsr_0
#define Os_TraceId_Can_30_McanIsr_1 Os_TraceId_Can_30_McanIsr_1
#define Os_TraceId_CounterIsr_SystemTimer Os_TraceId_CounterIsr_SystemTimer
#define Os_TraceId_I2c_IrqUnit0 Os_TraceId_I2c_IrqUnit0
#define Os_TraceId_I2c_IrqUnit1 Os_TraceId_I2c_IrqUnit1
#define Os_TraceId_IPC_mailbox1 Os_TraceId_IPC_mailbox1
#define Os_TraceId_IPC_mailbox2 Os_TraceId_IPC_mailbox2
#define Os_TraceId_MAIN_ESM0_ESM_INT_CFG_LVL_0 Os_TraceId_MAIN_ESM0_ESM_INT_CFG_LVL_0
#define Os_TraceId_MAIN_ESM0_ESM_INT_HI_LVL_0 Os_TraceId_MAIN_ESM0_ESM_INT_HI_LVL_0
#define Os_TraceId_MAIN_ESM0_ESM_INT_LOW_LVL_0 Os_TraceId_MAIN_ESM0_ESM_INT_LOW_LVL_0
#define Os_TraceId_MCU_ESM0_ESM_INT_CFG_LVL_0 Os_TraceId_MCU_ESM0_ESM_INT_CFG_LVL_0
#define Os_TraceId_MCU_ESM0_ESM_INT_HI_LVL_0 Os_TraceId_MCU_ESM0_ESM_INT_HI_LVL_0
#define Os_TraceId_MCU_ESM0_ESM_INT_LOW_LVL_0 Os_TraceId_MCU_ESM0_ESM_INT_LOW_LVL_0
#define Os_TraceId_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 Os_TraceId_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78
#define Os_TraceId_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 Os_TraceId_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304
#define Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305
#define Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn1 Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn1
#define Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn2 Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn2
#define Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn3 Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn3
#define Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn4 Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn4
#define Os_TraceId_WKUP_ESM0_ESM_INT_CFG_LVL_0 Os_TraceId_WKUP_ESM0_ESM_INT_CFG_LVL_0
#define Os_TraceId_WKUP_ESM0_ESM_INT_HI_LVL_0 Os_TraceId_WKUP_ESM0_ESM_INT_HI_LVL_0
#define Os_TraceId_WKUP_ESM0_ESM_INT_LOW_LVL_0 Os_TraceId_WKUP_ESM0_ESM_INT_LOW_LVL_0
#define Os_TraceId_vHsmResponseIsr Os_TraceId_vHsmResponseIsr
#define Os_TraceId_OsCore0_Hooks Os_TraceId_OsCore0_Hooks

/* Trace spinlock identifiers (All spinlocks inclusive system objects). */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32  Os_AppAccessMaskType;

/*! OS-Application identifiers. */
typedef enum
{
  OsApplication_QM = 0, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsApplication_Safety = 1, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsApplication_Trusted_Core0 = 2, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemApplication_OsCore0 = 3, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_APPID_COUNT = 4,
  INVALID_OSAPPLICATION = OS_APPID_COUNT
} ApplicationType;

/*! Trusted function identifiers. */
typedef enum
{
  Os_ServiceCallee_Appl_vDamRemapNrcCalloutFunc = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_CanWUp_Val_CheckPN = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_CanWUp_Val_StartWakeUpValidation = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_CanWUp_Val_StopWakeUpValidation = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_CddIpcHandler_Init = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_CddIpcHandler_Main = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_DcmCalloutStub_CompareKey = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_DcmCalloutStub_GetSeed = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_DcmCalloutStub_SessionCallback = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Det_UserReportError = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_PMIC_EnterLongWindow_DisableWdg = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Pmic_AppEnterInLongWindow = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Pmic_F_SafeState2_v = 13,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamCalibReset = 14,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock = 15,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock = 16,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock = 17,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_RE_DID2023_ProxiData = 18,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_RE_IntrinsicCameraSN_Readblock = 19,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_RE_IpcTxData = 20,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_RE_MCUReadDeviceReg = 21,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_RE_MCUReadDeviceRegData = 22,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_RE_MCUWriteDeviceReg = 23,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_RE_ReportErrorStatus1_0_B = 24,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx = 25,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx = 26,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx = 27,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx = 28,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx = 29,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_ShutdownOS = 30,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Update_CDD_IPCHandler_MirrorBlock = 31,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Update_CalDataProvider_MirrorBlock = 32,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Update_Cdd_Safety_MirrorBlock = 33,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Update_ComCallout_FlagStatus = 34,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Update_Proxi_MirrorBlock = 35,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_Update_SafetyGuard_MirrorBlock = 36,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_f_Send_Dbg_SDLFault_CanTx = 37,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Os_ServiceCallee_f_Send_Dbg_SSMFault_CanTx = 38,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_TRUSTEDFUNCTIONID_COUNT = 39
} TrustedFunctionIndexType;

/*! Non-trusted function identifiers. */
typedef enum
{
  OS_NONTRUSTEDFUNCTIONID_COUNT = 0
} Os_NonTrustedFunctionIndexType;

/*! Fast trusted function identifiers. */
typedef enum
{
  OS_FASTTRUSTEDFUNCTIONID_COUNT = 0
} Os_FastTrustedFunctionIndexType;

/*! Task identifiers. */
typedef enum
{
  BootAppOsTask = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore0 = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QM_ComTask_10ms = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QM_ComTask_5ms = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QM_DiagTask_10ms = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QM_MemTask_10ms = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QM_Task_00_10ms = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QM_Task_01_10ms = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QM_Task_200ms = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QM_Task_Init = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Safety_Task_00_10ms = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Safety_Task_01_10ms = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Safety_Task_200ms = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Safety_Task_Init = 13,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Safety_WdgTask_10ms = 14,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SciServerHighOsTask = 15,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SciServerLowOsTask = 16,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  ShutdownTask = 17,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  StartUpTask = 18,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_TASKID_COUNT = 19,
  INVALID_TASK = OS_TASKID_COUNT
} TaskType;

/*! Category 2 ISR identifiers. */
typedef enum
{
  ADC0 = 0,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  ADC1 = 1,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Can_30_McanIsr_0 = 2,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Can_30_McanIsr_1 = 3,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer = 4,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  I2c_IrqUnit0 = 5,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  I2c_IrqUnit1 = 6,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IPC_mailbox1 = 7,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IPC_mailbox2 = 8,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MAIN_ESM0_ESM_INT_CFG_LVL_0 = 9,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MAIN_ESM0_ESM_INT_HI_LVL_0 = 10,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MAIN_ESM0_ESM_INT_LOW_LVL_0 = 11,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MCU_ESM0_ESM_INT_CFG_LVL_0 = 12,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MCU_ESM0_ESM_INT_HI_LVL_0 = 13,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MCU_ESM0_ESM_INT_LOW_LVL_0 = 14,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 = 15,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 = 16,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 = 17,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 = 18,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 = 19,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 = 20,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 = 21,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 = 22,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 = 23,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 = 24,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 = 25,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 = 26,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 = 27,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 = 28,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 = 29,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 = 30,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 = 31,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 = 32,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 = 33,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 = 34,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 = 35,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 = 36,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 = 37,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 = 38,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SciServer_OsIsr_UserMsgHwiFxn1 = 39,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SciServer_OsIsr_UserMsgHwiFxn2 = 40,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SciServer_OsIsr_UserMsgHwiFxn3 = 41,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SciServer_OsIsr_UserMsgHwiFxn4 = 42,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  WKUP_ESM0_ESM_INT_CFG_LVL_0 = 43,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  WKUP_ESM0_ESM_INT_HI_LVL_0 = 44,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  WKUP_ESM0_ESM_INT_LOW_LVL_0 = 45,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  vHsmResponseIsr = 46,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ISRID_COUNT = 47,
  INVALID_ISR = OS_ISRID_COUNT
} ISRType;

/*! Alarm identifiers. */
typedef enum
{
  Rte_Al_TE2_QM_ComTask_10ms_0_10ms = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_QM_ComTask_5ms_5_5ms = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_QM_DiagTask_10ms_0_10ms = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_QM_MemTask_10ms_0_10ms = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_QM_Task_200ms_0_200ms = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_Safety_WdgTask_10ms_0_10ms = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_QM_ComTask_10ms_0_10ms = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_QM_ComTask_5ms_0_5ms = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_QM_DiagTask_10ms_0_10ms = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_QM_MemTask_10ms_0_10ms = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_QM_Task_00_10ms_0_10ms = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_QM_Task_01_10ms_0_10ms = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_QM_Task_200ms_0_200ms = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Safety_Task_00_10ms_0_10ms = 13,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Safety_Task_01_10ms_0_10ms = 14,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Safety_Task_200ms_0_200ms = 15,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Safety_WdgTask_10ms_0_10ms = 16,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ALARMID_COUNT = 17
} AlarmType;

/*! Counter identifiers. */
typedef enum
{
  SystemTimer = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_COUNTERID_COUNT = 1
} CounterType;

/*! ScheduleTable identifiers. */
typedef enum
{
  OS_SCHTID_COUNT = 0
} ScheduleTableType;

/*! Resource identifiers. */
typedef enum
{
  OsResource = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsResource_PMIC = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsResource_SciSecureproxy = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsResource_SciServerSync = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_RESOURCEID_COUNT = 4
} ResourceType;

/*! Spinlock identifiers. */
typedef enum
{
  OS_SPINLOCKID_COUNT = 0,
  INVALID_SPINLOCK = OS_SPINLOCKID_COUNT
} SpinlockIdType;

/*! Peripheral identifiers. */
typedef enum
{
  OS_PERIPHERALID_COUNT = 0
} Os_PeripheralIdType;

/*! Barrier identifiers. */
typedef enum
{
  OS_BARRIERID_COUNT = 0
} Os_BarrierIdType;

/*! Trace OS-Application identifiers (All OS-Applications inclusive system objects). */
typedef enum
{
  Os_TraceId_OsApplication_QM = 0,
  Os_TraceId_OsApplication_Safety = 1,
  Os_TraceId_OsApplication_Trusted_Core0 = 2,
  Os_TraceId_SystemApplication_OsCore0 = 3,
  OS_TRACE_APPID_COUNT = 4,
  OS_TRACE_INVALID_APPLICATION = OS_TRACE_APPID_COUNT + 1
} Os_TraceAppIdType;

/*! Trace thread identifiers (Tasks and ISRs inclusive system objects). */
typedef enum
{
  Os_TraceId_BootAppOsTask = 0,
  Os_TraceId_IdleTask_OsCore0 = 1,
  Os_TraceId_QM_ComTask_10ms = 2,
  Os_TraceId_QM_ComTask_5ms = 3,
  Os_TraceId_QM_DiagTask_10ms = 4,
  Os_TraceId_QM_MemTask_10ms = 5,
  Os_TraceId_QM_Task_00_10ms = 6,
  Os_TraceId_QM_Task_01_10ms = 7,
  Os_TraceId_QM_Task_200ms = 8,
  Os_TraceId_QM_Task_Init = 9,
  Os_TraceId_Safety_Task_00_10ms = 10,
  Os_TraceId_Safety_Task_01_10ms = 11,
  Os_TraceId_Safety_Task_200ms = 12,
  Os_TraceId_Safety_Task_Init = 13,
  Os_TraceId_Safety_WdgTask_10ms = 14,
  Os_TraceId_SciServerHighOsTask = 15,
  Os_TraceId_SciServerLowOsTask = 16,
  Os_TraceId_ShutdownTask = 17,
  Os_TraceId_StartUpTask = 18,
  Os_TraceId_ADC0 = 19,
  Os_TraceId_ADC1 = 20,
  Os_TraceId_Can_30_McanIsr_0 = 21,
  Os_TraceId_Can_30_McanIsr_1 = 22,
  Os_TraceId_CounterIsr_SystemTimer = 23,
  Os_TraceId_I2c_IrqUnit0 = 24,
  Os_TraceId_I2c_IrqUnit1 = 25,
  Os_TraceId_IPC_mailbox1 = 26,
  Os_TraceId_IPC_mailbox2 = 27,
  Os_TraceId_MAIN_ESM0_ESM_INT_CFG_LVL_0 = 28,
  Os_TraceId_MAIN_ESM0_ESM_INT_HI_LVL_0 = 29,
  Os_TraceId_MAIN_ESM0_ESM_INT_LOW_LVL_0 = 30,
  Os_TraceId_MCU_ESM0_ESM_INT_CFG_LVL_0 = 31,
  Os_TraceId_MCU_ESM0_ESM_INT_HI_LVL_0 = 32,
  Os_TraceId_MCU_ESM0_ESM_INT_LOW_LVL_0 = 33,
  Os_TraceId_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 = 34,
  Os_TraceId_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 = 35,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 = 36,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 = 37,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 = 38,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 = 39,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 = 40,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 = 41,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 = 42,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 = 43,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 = 44,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 = 45,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 = 46,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 = 47,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 = 48,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 = 49,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 = 50,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 = 51,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 = 52,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 = 53,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 = 54,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 = 55,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 = 56,
  Os_TraceId_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 = 57,
  Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn1 = 58,
  Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn2 = 59,
  Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn3 = 60,
  Os_TraceId_SciServer_OsIsr_UserMsgHwiFxn4 = 61,
  Os_TraceId_WKUP_ESM0_ESM_INT_CFG_LVL_0 = 62,
  Os_TraceId_WKUP_ESM0_ESM_INT_HI_LVL_0 = 63,
  Os_TraceId_WKUP_ESM0_ESM_INT_LOW_LVL_0 = 64,
  Os_TraceId_vHsmResponseIsr = 65,
  Os_TraceId_OsCore0_Hooks = 66,
  OS_TRACE_THREADID_COUNT = 67,
  OS_TRACE_INVALID_THREAD = OS_TRACE_THREADID_COUNT + 1
} Os_TraceThreadIdType;

/*! Trace spinlock identifiers (All spinlocks inclusive system objects). */
typedef enum
{
  OS_TRACE_NUMBER_OF_CONFIGURED_SPINLOCKS = 0,
  OS_TRACE_NUMBER_OF_ALL_SPINLOCKS = 0,
  OS_TRACE_INVALID_SPINLOCK = OS_TRACE_NUMBER_OF_ALL_SPINLOCKS + 1
} Os_TraceSpinlockIdType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TYPES_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Types_Lcfg.h
 *********************************************************************************************************************/
