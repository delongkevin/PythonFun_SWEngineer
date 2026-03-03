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
 *              File: Os_Lcfg.h
 *   Generation Time: 2024-02-13 13:07:50
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_LCFG_H
# define OS_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"
# include "Os_Types.h"
# include "Os_Types_Lcfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Lcfg.h"

/* User file includes */
#include "Trusted_Func_Api.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Backward compatibility API defines for trusted function stubs. */
# define Call_Appl_vDamRemapNrcCalloutFunc     Os_Call_Appl_vDamRemapNrcCalloutFunc
# define Call_CanWUp_Val_CheckPN     Os_Call_CanWUp_Val_CheckPN
# define Call_CanWUp_Val_StartWakeUpValidation     Os_Call_CanWUp_Val_StartWakeUpValidation
# define Call_CanWUp_Val_StopWakeUpValidation     Os_Call_CanWUp_Val_StopWakeUpValidation
# define Call_CddIpcHandler_Init     Os_Call_CddIpcHandler_Init
# define Call_CddIpcHandler_Main     Os_Call_CddIpcHandler_Main
# define Call_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus     Os_Call_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus
# define Call_DcmCalloutStub_CompareKey     Os_Call_DcmCalloutStub_CompareKey
# define Call_DcmCalloutStub_GetSeed     Os_Call_DcmCalloutStub_GetSeed
# define Call_DcmCalloutStub_SessionCallback     Os_Call_DcmCalloutStub_SessionCallback
# define Call_Det_UserReportError     Os_Call_Det_UserReportError
# define Call_PMIC_EnterLongWindow_DisableWdg     Os_Call_PMIC_EnterLongWindow_DisableWdg
# define Call_Pmic_AppEnterInLongWindow     Os_Call_Pmic_AppEnterInLongWindow
# define Call_Pmic_F_SafeState2_v     Os_Call_Pmic_F_SafeState2_v
# define Call_RE_CalDataProvider_Nvm_SVSCamCalibReset     Os_Call_RE_CalDataProvider_Nvm_SVSCamCalibReset
# define Call_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock     Os_Call_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock
# define Call_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock     Os_Call_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock
# define Call_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock     Os_Call_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock
# define Call_RE_DID2023_ProxiData     Os_Call_RE_DID2023_ProxiData
# define Call_RE_IntrinsicCameraSN_Readblock     Os_Call_RE_IntrinsicCameraSN_Readblock
# define Call_RE_IpcTxData     Os_Call_RE_IpcTxData
# define Call_RE_MCUReadDeviceReg     Os_Call_RE_MCUReadDeviceReg
# define Call_RE_MCUReadDeviceRegData     Os_Call_RE_MCUReadDeviceRegData
# define Call_RE_MCUWriteDeviceReg     Os_Call_RE_MCUWriteDeviceReg
# define Call_RE_ReportErrorStatus1_0_B     Os_Call_RE_ReportErrorStatus1_0_B
# define Call_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx     Os_Call_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx
# define Call_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx     Os_Call_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx
# define Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx     Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx
# define Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx     Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx
# define Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx     Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx
# define Call_ShutdownOS     Os_Call_ShutdownOS
# define Call_Update_CDD_IPCHandler_MirrorBlock     Os_Call_Update_CDD_IPCHandler_MirrorBlock
# define Call_Update_CalDataProvider_MirrorBlock     Os_Call_Update_CalDataProvider_MirrorBlock
# define Call_Update_Cdd_Safety_MirrorBlock     Os_Call_Update_Cdd_Safety_MirrorBlock
# define Call_Update_ComCallout_FlagStatus     Os_Call_Update_ComCallout_FlagStatus
# define Call_Update_Proxi_MirrorBlock     Os_Call_Update_Proxi_MirrorBlock
# define Call_Update_SafetyGuard_MirrorBlock     Os_Call_Update_SafetyGuard_MirrorBlock
# define Call_f_Send_Dbg_SDLFault_CanTx     Os_Call_f_Send_Dbg_SDLFault_CanTx
# define Call_f_Send_Dbg_SSMFault_CanTx     Os_Call_f_Send_Dbg_SSMFault_CanTx


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

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_BootAppOsTask_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  BootAppOsTask()
 *********************************************************************************************************************/
extern FUNC(void, OS_BOOTAPPOSTASK_CODE) Os_Task_BootAppOsTask(void);

# define OS_STOP_SEC_BootAppOsTask_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QM_ComTask_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QM_ComTask_10ms()
 *********************************************************************************************************************/
extern FUNC(void, OS_QM_COMTASK_10MS_CODE) Os_Task_QM_ComTask_10ms(void);

# define OS_STOP_SEC_QM_ComTask_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QM_ComTask_5ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QM_ComTask_5ms()
 *********************************************************************************************************************/
extern FUNC(void, OS_QM_COMTASK_5MS_CODE) Os_Task_QM_ComTask_5ms(void);

# define OS_STOP_SEC_QM_ComTask_5ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QM_DiagTask_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QM_DiagTask_10ms()
 *********************************************************************************************************************/
extern FUNC(void, OS_QM_DIAGTASK_10MS_CODE) Os_Task_QM_DiagTask_10ms(void);

# define OS_STOP_SEC_QM_DiagTask_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QM_MemTask_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QM_MemTask_10ms()
 *********************************************************************************************************************/
extern FUNC(void, OS_QM_MEMTASK_10MS_CODE) Os_Task_QM_MemTask_10ms(void);

# define OS_STOP_SEC_QM_MemTask_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QM_Task_00_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QM_Task_00_10ms()
 *********************************************************************************************************************/
extern FUNC(void, OS_QM_TASK_00_10MS_CODE) Os_Task_QM_Task_00_10ms(void);

# define OS_STOP_SEC_QM_Task_00_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QM_Task_01_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QM_Task_01_10ms()
 *********************************************************************************************************************/
extern FUNC(void, OS_QM_TASK_01_10MS_CODE) Os_Task_QM_Task_01_10ms(void);

# define OS_STOP_SEC_QM_Task_01_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QM_Task_200ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QM_Task_200ms()
 *********************************************************************************************************************/
extern FUNC(void, OS_QM_TASK_200MS_CODE) Os_Task_QM_Task_200ms(void);

# define OS_STOP_SEC_QM_Task_200ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QM_Task_Init_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QM_Task_Init()
 *********************************************************************************************************************/
extern FUNC(void, OS_QM_TASK_INIT_CODE) Os_Task_QM_Task_Init(void);

# define OS_STOP_SEC_QM_Task_Init_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Safety_Task_00_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Safety_Task_00_10ms()
 *********************************************************************************************************************/
extern FUNC(void, OS_SAFETY_TASK_00_10MS_CODE) Os_Task_Safety_Task_00_10ms(void);

# define OS_STOP_SEC_Safety_Task_00_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Safety_Task_01_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Safety_Task_01_10ms()
 *********************************************************************************************************************/
extern FUNC(void, OS_SAFETY_TASK_01_10MS_CODE) Os_Task_Safety_Task_01_10ms(void);

# define OS_STOP_SEC_Safety_Task_01_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Safety_Task_200ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Safety_Task_200ms()
 *********************************************************************************************************************/
extern FUNC(void, OS_SAFETY_TASK_200MS_CODE) Os_Task_Safety_Task_200ms(void);

# define OS_STOP_SEC_Safety_Task_200ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Safety_Task_Init_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Safety_Task_Init()
 *********************************************************************************************************************/
extern FUNC(void, OS_SAFETY_TASK_INIT_CODE) Os_Task_Safety_Task_Init(void);

# define OS_STOP_SEC_Safety_Task_Init_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Safety_WdgTask_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Safety_WdgTask_10ms()
 *********************************************************************************************************************/
extern FUNC(void, OS_SAFETY_WDGTASK_10MS_CODE) Os_Task_Safety_WdgTask_10ms(void);

# define OS_STOP_SEC_Safety_WdgTask_10ms_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SciServerHighOsTask_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SciServerHighOsTask()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCISERVERHIGHOSTASK_CODE) Os_Task_SciServerHighOsTask(void);

# define OS_STOP_SEC_SciServerHighOsTask_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SciServerLowOsTask_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SciServerLowOsTask()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCISERVERLOWOSTASK_CODE) Os_Task_SciServerLowOsTask(void);

# define OS_STOP_SEC_SciServerLowOsTask_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_ShutdownTask_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ShutdownTask()
 *********************************************************************************************************************/
extern FUNC(void, OS_SHUTDOWNTASK_CODE) Os_Task_ShutdownTask(void);

# define OS_STOP_SEC_ShutdownTask_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_StartUpTask_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  StartUpTask()
 *********************************************************************************************************************/
extern FUNC(void, OS_STARTUPTASK_CODE) Os_Task_StartUpTask(void);

# define OS_STOP_SEC_StartUpTask_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Adc_IrqUnit0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Adc_IrqUnit0()
 *********************************************************************************************************************/
extern FUNC(void, OS_ADC_IRQUNIT0_CODE) Os_Isr_Adc_IrqUnit0(void);

# define OS_STOP_SEC_Adc_IrqUnit0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Adc_IrqUnit1_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Adc_IrqUnit1()
 *********************************************************************************************************************/
extern FUNC(void, OS_ADC_IRQUNIT1_CODE) Os_Isr_Adc_IrqUnit1(void);

# define OS_STOP_SEC_Adc_IrqUnit1_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Can_30_McanIsr_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Can_30_McanIsr_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_CAN_30_MCANISR_0_CODE) Os_Isr_Can_30_McanIsr_0(void);

# define OS_STOP_SEC_Can_30_McanIsr_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Can_30_McanIsr_1_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Can_30_McanIsr_1()
 *********************************************************************************************************************/
extern FUNC(void, OS_CAN_30_MCANISR_1_CODE) Os_Isr_Can_30_McanIsr_1(void);

# define OS_STOP_SEC_Can_30_McanIsr_1_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_I2c_IrqUnit0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  I2c_IrqUnit0()
 *********************************************************************************************************************/
extern FUNC(void, OS_I2C_IRQUNIT0_CODE) Os_Isr_I2c_IrqUnit0(void);

# define OS_STOP_SEC_I2c_IrqUnit0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_I2c_IrqUnit1_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  I2c_IrqUnit1()
 *********************************************************************************************************************/
extern FUNC(void, OS_I2C_IRQUNIT1_CODE) Os_Isr_I2c_IrqUnit1(void);

# define OS_STOP_SEC_I2c_IrqUnit1_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_IPC_mailbox1_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  IPC_mailbox1()
 *********************************************************************************************************************/
extern FUNC(void, OS_IPC_MAILBOX1_CODE) Os_Isr_IPC_mailbox1(void);

# define OS_STOP_SEC_IPC_mailbox1_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_IPC_mailbox2_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  IPC_mailbox2()
 *********************************************************************************************************************/
extern FUNC(void, OS_IPC_MAILBOX2_CODE) Os_Isr_IPC_mailbox2(void);

# define OS_STOP_SEC_IPC_mailbox2_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_MAIN_ESM0_ESM_INT_CFG_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MAIN_ESM0_ESM_INT_CFG_LVL_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_MAIN_ESM0_ESM_INT_CFG_LVL_0_CODE) Os_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0(void);

# define OS_STOP_SEC_MAIN_ESM0_ESM_INT_CFG_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_MAIN_ESM0_ESM_INT_HI_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MAIN_ESM0_ESM_INT_HI_LVL_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_MAIN_ESM0_ESM_INT_HI_LVL_0_CODE) Os_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0(void);

# define OS_STOP_SEC_MAIN_ESM0_ESM_INT_HI_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_MAIN_ESM0_ESM_INT_LOW_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MAIN_ESM0_ESM_INT_LOW_LVL_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_MAIN_ESM0_ESM_INT_LOW_LVL_0_CODE) Os_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0(void);

# define OS_STOP_SEC_MAIN_ESM0_ESM_INT_LOW_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_MCU_ESM0_ESM_INT_CFG_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MCU_ESM0_ESM_INT_CFG_LVL_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_MCU_ESM0_ESM_INT_CFG_LVL_0_CODE) Os_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0(void);

# define OS_STOP_SEC_MCU_ESM0_ESM_INT_CFG_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_MCU_ESM0_ESM_INT_HI_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MCU_ESM0_ESM_INT_HI_LVL_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_MCU_ESM0_ESM_INT_HI_LVL_0_CODE) Os_Isr_MCU_ESM0_ESM_INT_HI_LVL_0(void);

# define OS_STOP_SEC_MCU_ESM0_ESM_INT_HI_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_MCU_ESM0_ESM_INT_LOW_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MCU_ESM0_ESM_INT_LOW_LVL_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_MCU_ESM0_ESM_INT_LOW_LVL_0_CODE) Os_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0(void);

# define OS_STOP_SEC_MCU_ESM0_ESM_INT_LOW_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78()
 *********************************************************************************************************************/
extern FUNC(void, OS_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_CODE) Os_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78(void);

# define OS_STOP_SEC_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79()
 *********************************************************************************************************************/
extern FUNC(void, OS_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_CODE) Os_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79(void);

# define OS_STOP_SEC_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305()
 *********************************************************************************************************************/
extern FUNC(void, OS_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_CODE) Os_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305(void);

# define OS_STOP_SEC_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SciServer_OsIsr_UserMsgHwiFxn1_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SciServer_OsIsr_UserMsgHwiFxn1()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCISERVER_OSISR_USERMSGHWIFXN1_CODE) Os_Isr_SciServer_OsIsr_UserMsgHwiFxn1(void);

# define OS_STOP_SEC_SciServer_OsIsr_UserMsgHwiFxn1_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SciServer_OsIsr_UserMsgHwiFxn2_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SciServer_OsIsr_UserMsgHwiFxn2()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCISERVER_OSISR_USERMSGHWIFXN2_CODE) Os_Isr_SciServer_OsIsr_UserMsgHwiFxn2(void);

# define OS_STOP_SEC_SciServer_OsIsr_UserMsgHwiFxn2_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SciServer_OsIsr_UserMsgHwiFxn3_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SciServer_OsIsr_UserMsgHwiFxn3()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCISERVER_OSISR_USERMSGHWIFXN3_CODE) Os_Isr_SciServer_OsIsr_UserMsgHwiFxn3(void);

# define OS_STOP_SEC_SciServer_OsIsr_UserMsgHwiFxn3_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SciServer_OsIsr_UserMsgHwiFxn4_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SciServer_OsIsr_UserMsgHwiFxn4()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCISERVER_OSISR_USERMSGHWIFXN4_CODE) Os_Isr_SciServer_OsIsr_UserMsgHwiFxn4(void);

# define OS_STOP_SEC_SciServer_OsIsr_UserMsgHwiFxn4_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_WKUP_ESM0_ESM_INT_CFG_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  WKUP_ESM0_ESM_INT_CFG_LVL_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_WKUP_ESM0_ESM_INT_CFG_LVL_0_CODE) Os_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0(void);

# define OS_STOP_SEC_WKUP_ESM0_ESM_INT_CFG_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_WKUP_ESM0_ESM_INT_HI_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  WKUP_ESM0_ESM_INT_HI_LVL_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_WKUP_ESM0_ESM_INT_HI_LVL_0_CODE) Os_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0(void);

# define OS_STOP_SEC_WKUP_ESM0_ESM_INT_HI_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_WKUP_ESM0_ESM_INT_LOW_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  WKUP_ESM0_ESM_INT_LOW_LVL_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_WKUP_ESM0_ESM_INT_LOW_LVL_0_CODE) Os_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0(void);

# define OS_STOP_SEC_WKUP_ESM0_ESM_INT_LOW_LVL_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_vHsmResponseIsr_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmResponseIsr()
 *********************************************************************************************************************/
extern FUNC(void, OS_VHSMRESPONSEISR_CODE) Os_Isr_vHsmResponseIsr(void);

# define OS_STOP_SEC_vHsmResponseIsr_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Appl_vDamRemapNrcCalloutFunc
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_Appl_vDamRemapNrcCalloutFunc
(
  uint8 Arg1,
  uint8 Arg2,
  uint8* Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_CanWUp_Val_CheckPN
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_CanWUp_Val_CheckPN
(
  uint32 Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_CanWUp_Val_StartWakeUpValidation
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_CanWUp_Val_StartWakeUpValidation
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_CanWUp_Val_StopWakeUpValidation
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_CanWUp_Val_StopWakeUpValidation
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_CddIpcHandler_Init
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_CddIpcHandler_Init
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_CddIpcHandler_Main
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_CddIpcHandler_Main
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus
(
  uint8 Arg1,
  uint8 Arg2,
  uint8 Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_DcmCalloutStub_CompareKey
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_DcmCalloutStub_CompareKey
(
  const uint8* Arg1,
  uint8 Arg2,
  uint8* Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_DcmCalloutStub_GetSeed
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_DcmCalloutStub_GetSeed
(
  const uint8* Arg1,
  uint8 Arg2,
  uint8* Arg3,
  uint8* Arg4
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_DcmCalloutStub_SessionCallback
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_DcmCalloutStub_SessionCallback
(
  uint8 Arg1,
  uint8 Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Det_UserReportError
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(uint8, OS_CODE) Os_Call_Det_UserReportError
(
  uint16 Arg1,
  uint8 Arg2,
  uint8 Arg3,
  uint8 Arg4
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_PMIC_EnterLongWindow_DisableWdg
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_PMIC_EnterLongWindow_DisableWdg
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Pmic_AppEnterInLongWindow
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(sint32, OS_CODE) Os_Call_Pmic_AppEnterInLongWindow
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Pmic_F_SafeState2_v
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_Pmic_F_SafeState2_v
(
  uint8 Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_RE_CalDataProvider_Nvm_SVSCamCalibReset
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_RE_CalDataProvider_Nvm_SVSCamCalibReset
(
  const TbSVS_S_SVSCamCalibReset_t * Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock
(
  const TbSVS_S_SVSCamEOLCalibDataToNVM_t * Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock
(
  const TbSVS_S_SVSCamOCCalibDataToNVM_t * Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock
(
  const TbSVS_S_SVSCamSCCalibDataToNVM_t * Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_RE_DID2023_ProxiData
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_RE_DID2023_ProxiData
(
  const uint8 * Arg1,
  uint16 Arg2,
  uint8 * Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_RE_IntrinsicCameraSN_Readblock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_RE_IntrinsicCameraSN_Readblock
(
  IntrinsicCamID* Arg1,
  CamNvmReadSts* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_RE_IpcTxData
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_RE_IpcTxData
(
  void * Arg1,
  uint16 Arg2,
  uint16 Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_RE_MCUReadDeviceReg
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(uint8, OS_CODE) Os_Call_RE_MCUReadDeviceReg
(
  uint8 Arg1,
  uint16 Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_RE_MCUReadDeviceRegData
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(uint8, OS_CODE) Os_Call_RE_MCUReadDeviceRegData
(
  uint8 Arg1,
  uint16 * Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_RE_MCUWriteDeviceReg
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(uint8, OS_CODE) Os_Call_RE_MCUWriteDeviceReg
(
  uint8 Arg1,
  uint16 Arg2,
  uint16 Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_RE_ReportErrorStatus1_0_B
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_RE_ReportErrorStatus1_0_B
(
  uint32 Arg1,
  uint32 Arg2,
  const ErrorMgr_stAddData* Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx
(
  PduIdType Arg1,
  PduInfoType* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx
(
  PduIdType Arg1,
  PduInfoType* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx
(
  PduIdType Arg1,
  PduInfoType* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx
(
  PduIdType Arg1,
  PduInfoType* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx
(
  PduIdType Arg1,
  PduInfoType* Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_ShutdownOS
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_ShutdownOS
(
  uint8 Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Update_CDD_IPCHandler_MirrorBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_Update_CDD_IPCHandler_MirrorBlock
(
  boolean Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Update_CalDataProvider_MirrorBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_Update_CalDataProvider_MirrorBlock
(
  boolean Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Update_Cdd_Safety_MirrorBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_Update_Cdd_Safety_MirrorBlock
(
  boolean Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Update_ComCallout_FlagStatus
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_Update_ComCallout_FlagStatus
(
  uint8* Arg1,
  uint8 Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Update_Proxi_MirrorBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_Update_Proxi_MirrorBlock
(
  boolean Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_Update_SafetyGuard_MirrorBlock
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_Update_SafetyGuard_MirrorBlock
(
  boolean Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_f_Send_Dbg_SDLFault_CanTx
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_f_Send_Dbg_SDLFault_CanTx
(
  uint16 Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_Call_f_Send_Dbg_SSMFault_CanTx
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_f_Send_Dbg_SSMFault_CanTx
(
  uint8* Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Lcfg.h
 *********************************************************************************************************************/
