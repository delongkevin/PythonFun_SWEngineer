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
 *              File: Os_ServiceFunction_Lcfg.h
 *   Generation Time: 2024-02-13 13:07:51
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_SERVICEFUNCTION_LCFG_H
# define OS_SERVICEFUNCTION_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_ServiceFunction_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

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

/*! Service function configuration data: Appl_vDamRemapNrcCalloutFunc */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Appl_vDamRemapNrcCalloutFunc;

/*! Service function configuration data: CanWUp_Val_CheckPN */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_CanWUp_Val_CheckPN;

/*! Service function configuration data: CanWUp_Val_StartWakeUpValidation */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_CanWUp_Val_StartWakeUpValidation;

/*! Service function configuration data: CanWUp_Val_StopWakeUpValidation */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_CanWUp_Val_StopWakeUpValidation;

/*! Service function configuration data: CddIpcHandler_Init */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_CddIpcHandler_Init;

/*! Service function configuration data: CddIpcHandler_Main */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_CddIpcHandler_Main;

/*! Service function configuration data: Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus;

/*! Service function configuration data: DcmCalloutStub_CompareKey */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_DcmCalloutStub_CompareKey;

/*! Service function configuration data: DcmCalloutStub_GetSeed */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_DcmCalloutStub_GetSeed;

/*! Service function configuration data: DcmCalloutStub_SessionCallback */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_DcmCalloutStub_SessionCallback;

/*! Service function configuration data: Det_UserReportError */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Det_UserReportError;

/*! Service function configuration data: PMIC_EnterLongWindow_DisableWdg */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_PMIC_EnterLongWindow_DisableWdg;

/*! Service function configuration data: Pmic_AppEnterInLongWindow */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Pmic_AppEnterInLongWindow;

/*! Service function configuration data: Pmic_F_SafeState2_v */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Pmic_F_SafeState2_v;

/*! Service function configuration data: RE_CalDataProvider_Nvm_SVSCamCalibReset */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamCalibReset;

/*! Service function configuration data: RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock;

/*! Service function configuration data: RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock;

/*! Service function configuration data: RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock;

/*! Service function configuration data: RE_DID2023_ProxiData */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_DID2023_ProxiData;

/*! Service function configuration data: RE_IntrinsicCameraSN_Readblock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_IntrinsicCameraSN_Readblock;

/*! Service function configuration data: RE_IpcTxData */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_IpcTxData;

/*! Service function configuration data: RE_MCUReadDeviceReg */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_MCUReadDeviceReg;

/*! Service function configuration data: RE_MCUReadDeviceRegData */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_MCUReadDeviceRegData;

/*! Service function configuration data: RE_MCUWriteDeviceReg */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_MCUWriteDeviceReg;

/*! Service function configuration data: RE_ReportErrorStatus1_0_B */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_ReportErrorStatus1_0_B;

/*! Service function configuration data: SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx;

/*! Service function configuration data: SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx;

/*! Service function configuration data: SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx;

/*! Service function configuration data: SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx;

/*! Service function configuration data: SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx;

/*! Service function configuration data: ShutdownOS */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_ShutdownOS;

/*! Service function configuration data: Update_CDD_IPCHandler_MirrorBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Update_CDD_IPCHandler_MirrorBlock;

/*! Service function configuration data: Update_CalDataProvider_MirrorBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Update_CalDataProvider_MirrorBlock;

/*! Service function configuration data: Update_Cdd_Safety_MirrorBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Update_Cdd_Safety_MirrorBlock;

/*! Service function configuration data: Update_ComCallout_FlagStatus */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Update_ComCallout_FlagStatus;

/*! Service function configuration data: Update_Proxi_MirrorBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Update_Proxi_MirrorBlock;

/*! Service function configuration data: Update_SafetyGuard_MirrorBlock */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Update_SafetyGuard_MirrorBlock;

/*! Service function configuration data: f_Send_Dbg_SDLFault_CanTx */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_f_Send_Dbg_SDLFault_CanTx;

/*! Service function configuration data: f_Send_Dbg_SSMFault_CanTx */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_f_Send_Dbg_SSMFault_CanTx;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for trusted functions. */
extern CONSTP2CONST(Os_ServiceTfConfigType, OS_CONST, OS_CONST)
  OsCfg_TrustedFunctionRefs[OS_TRUSTEDFUNCTIONID_COUNT + 1];                                /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

/*! Object reference table for non-trusted functions. */
extern CONSTP2CONST(Os_ServiceNtfConfigType, OS_CONST, OS_CONST)
  OsCfg_NonTrustedFunctionRefs[OS_NONTRUSTEDFUNCTIONID_COUNT + 1];                            /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

/*! Object reference table for fast trusted functions. */
extern CONSTP2CONST(Os_ServiceFtfConfigType, OS_CONST, OS_CONST)
  OsCfg_FastTrustedFunctionRefs[OS_FASTTRUSTEDFUNCTIONID_COUNT + 1];                          /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_SERVICEFUNCTION_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_ServiceFunction_Lcfg.h
 *********************************************************************************************************************/
