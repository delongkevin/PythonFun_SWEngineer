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
 *              File: Os_ServiceFunction_Lcfg.c
 *   Generation Time: 2024-02-13 13:07:51
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_SERVICEFUNCTION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_ServiceFunction_Cfg.h"
#include "Os_ServiceFunction_Lcfg.h"
#include "Os_ServiceFunction.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Common_Types.h"
#include "Os_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os.h"

/* Os externals dependencies */
#include "Platform_Types.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Context.h"

/* User file includes */
#include "Trusted_Func_Api.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Data type for packing user variables for: Appl_vDamRemapNrcCalloutFunc */
typedef struct
{
  uint8 Arg1; /* IN - SID */
  uint8 Arg2; /* IN - intErrorCode */
  uint8* Arg3; /* IN - errorCode */
} Os_Appl_vDamRemapNrcCalloutFuncPackageType;

/*! Data type for packing user variables for: CanWUp_Val_CheckPN */
typedef struct
{
  uint32 Arg1; /* IN - WakeupSource */
} Os_CanWUp_Val_CheckPNPackageType;

/*! Data type for packing user variables for: Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus */
typedef struct
{
  uint8 Arg1; /* IN - index */
  uint8 Arg2; /* IN - Data */
  uint8 Arg3; /* IN - storeAtShut */
} Os_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatusPackageType;

/*! Data type for packing user variables for: DcmCalloutStub_CompareKey */
typedef struct
{
  const uint8* Arg1; /* IN - Key */
  uint8 Arg2; /* IN - OpStatus */
  uint8* Arg3; /* IN - ErrorCode */
  Std_ReturnType Returnvalue;
} Os_DcmCalloutStub_CompareKeyPackageType;

/*! Data type for packing user variables for: DcmCalloutStub_GetSeed */
typedef struct
{
  const uint8* Arg1; /* IN - SecurityAccessDataRecord */
  uint8 Arg2; /* IN - OpStatus */
  uint8* Arg3; /* IN - Seed */
  uint8* Arg4; /* IN - ErrorCode */
  Std_ReturnType Returnvalue;
} Os_DcmCalloutStub_GetSeedPackageType;

/*! Data type for packing user variables for: DcmCalloutStub_SessionCallback */
typedef struct
{
  uint8 Arg1; /* IN - FormerSession */
  uint8 Arg2; /* IN - NewSession */
} Os_DcmCalloutStub_SessionCallbackPackageType;

/*! Data type for packing user variables for: Det_UserReportError */
typedef struct
{
  uint16 Arg1; /* IN - ModuleId */
  uint8 Arg2; /* IN - InstanceId */
  uint8 Arg3; /* IN - ApiId */
  uint8 Arg4; /* IN - ErrorId */
  uint8 Returnvalue;
} Os_Det_UserReportErrorPackageType;

/*! Data type for packing user variables for: Pmic_AppEnterInLongWindow */
typedef struct
{
  sint32 Returnvalue;
} Os_Pmic_AppEnterInLongWindowPackageType;

/*! Data type for packing user variables for: Pmic_F_SafeState2_v */
typedef struct
{
  uint8 Arg1; /* IN - SafeStateReason */
} Os_Pmic_F_SafeState2_vPackageType;

/*! Data type for packing user variables for: RE_CalDataProvider_Nvm_SVSCamCalibReset */
typedef struct
{
  const TbSVS_S_SVSCamCalibReset_t * Arg1; /* IN - v_SVSCamCalibReset */
  Std_ReturnType Returnvalue;
} Os_RE_CalDataProvider_Nvm_SVSCamCalibResetPackageType;

/*! Data type for packing user variables for: RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock */
typedef struct
{
  const TbSVS_S_SVSCamEOLCalibDataToNVM_t * Arg1; /* IN - v_SVSCamEOLCalibData */
  Std_ReturnType Returnvalue;
} Os_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlockPackageType;

/*! Data type for packing user variables for: RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock */
typedef struct
{
  const TbSVS_S_SVSCamOCCalibDataToNVM_t * Arg1; /* IN - v_SVSCamOCCalibData */
  Std_ReturnType Returnvalue;
} Os_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlockPackageType;

/*! Data type for packing user variables for: RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock */
typedef struct
{
  const TbSVS_S_SVSCamSCCalibDataToNVM_t * Arg1; /* IN - v_SVSCamSCCalibData */
  Std_ReturnType Returnvalue;
} Os_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlockPackageType;

/*! Data type for packing user variables for: RE_DID2023_ProxiData */
typedef struct
{
  const uint8 * Arg1; /* IN - Data */
  uint16 Arg2; /* IN - Datalength */
  uint8 * Arg3; /* IN - Errorcode */
} Os_RE_DID2023_ProxiDataPackageType;

/*! Data type for packing user variables for: RE_IntrinsicCameraSN_Readblock */
typedef struct
{
  IntrinsicCamID* Arg1; /* OUT - CamNvmData */
  CamNvmReadSts* Arg2; /* OUT - NvmCamSts */
  Std_ReturnType Returnvalue;
} Os_RE_IntrinsicCameraSN_ReadblockPackageType;

/*! Data type for packing user variables for: RE_IpcTxData */
typedef struct
{
  void * Arg1; /* IN - b_TxData_pv */
  uint16 Arg2; /* IN - i_IpcMsgId_u16 */
  uint16 Arg3; /* IN - i_IpcMsgSize_u16 */
} Os_RE_IpcTxDataPackageType;

/*! Data type for packing user variables for: RE_MCUReadDeviceReg */
typedef struct
{
  uint8 Arg1; /* IN - DeviceAdd */
  uint16 Arg2; /* IN - RegAddress */
  uint8 Returnvalue;
} Os_RE_MCUReadDeviceRegPackageType;

/*! Data type for packing user variables for: RE_MCUReadDeviceRegData */
typedef struct
{
  uint8 Arg1; /* IN - DeviceAddress */
  uint16 * Arg2; /* IN - RegAddress */
  uint8 Returnvalue;
} Os_RE_MCUReadDeviceRegDataPackageType;

/*! Data type for packing user variables for: RE_MCUWriteDeviceReg */
typedef struct
{
  uint8 Arg1; /* IN - DeviceAdd */
  uint16 Arg2; /* IN - RegAddress */
  uint16 Arg3; /* IN - RegData */
  uint8 Returnvalue;
} Os_RE_MCUWriteDeviceRegPackageType;

/*! Data type for packing user variables for: RE_ReportErrorStatus1_0_B */
typedef struct
{
  uint32 Arg1; /* IN - err */
  uint32 Arg2; /* IN - errStatus */
  const ErrorMgr_stAddData* Arg3; /* IN - addData */
  Std_ReturnType Returnvalue;
} Os_RE_ReportErrorStatus1_0_BPackageType;

/*! Data type for packing user variables for: SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx */
typedef struct
{
  PduIdType Arg1; /* IN - PduId */
  PduInfoType* Arg2; /* OUT - PduInfoPtr */
} Os_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_TxPackageType;

/*! Data type for packing user variables for: SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx */
typedef struct
{
  PduIdType Arg1; /* IN - PduId */
  PduInfoType* Arg2; /* OUT - PduInfoPtr */
} Os_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_TxPackageType;

/*! Data type for packing user variables for: SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx */
typedef struct
{
  PduIdType Arg1; /* IN - PduId */
  PduInfoType* Arg2; /* OUT - PduInfoPtr */
} Os_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_TxPackageType;

/*! Data type for packing user variables for: SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx */
typedef struct
{
  PduIdType Arg1; /* IN - PduId */
  PduInfoType* Arg2; /* OUT - PduInfoPtr */
} Os_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_TxPackageType;

/*! Data type for packing user variables for: SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx */
typedef struct
{
  PduIdType Arg1; /* IN - PduId */
  PduInfoType* Arg2; /* OUT - PduInfoPtr */
} Os_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_TxPackageType;

/*! Data type for packing user variables for: ShutdownOS */
typedef struct
{
  uint8 Arg1; /* IN - Error */
} Os_ShutdownOSPackageType;

/*! Data type for packing user variables for: Update_CDD_IPCHandler_MirrorBlock */
typedef struct
{
  boolean Arg1; /* IN - CDD_IPCHandler_Erase_block */
} Os_Update_CDD_IPCHandler_MirrorBlockPackageType;

/*! Data type for packing user variables for: Update_CalDataProvider_MirrorBlock */
typedef struct
{
  boolean Arg1; /* IN - CalDataProvider_Erase_block */
} Os_Update_CalDataProvider_MirrorBlockPackageType;

/*! Data type for packing user variables for: Update_Cdd_Safety_MirrorBlock */
typedef struct
{
  boolean Arg1; /* IN - Cdd_Safety_Erase_block */
} Os_Update_Cdd_Safety_MirrorBlockPackageType;

/*! Data type for packing user variables for: Update_ComCallout_FlagStatus */
typedef struct
{
  uint8* Arg1; /* OUT - flagPtrU8 */
  uint8 Arg2; /* IN - data */
} Os_Update_ComCallout_FlagStatusPackageType;

/*! Data type for packing user variables for: Update_Proxi_MirrorBlock */
typedef struct
{
  boolean Arg1; /* IN - Proxi_Erase_block */
} Os_Update_Proxi_MirrorBlockPackageType;

/*! Data type for packing user variables for: Update_SafetyGuard_MirrorBlock */
typedef struct
{
  boolean Arg1; /* IN - Reset_Reason_Erase_Block */
} Os_Update_SafetyGuard_MirrorBlockPackageType;

/*! Data type for packing user variables for: f_Send_Dbg_SDLFault_CanTx */
typedef struct
{
  uint16 Arg1; /* IN - SDLFault */
} Os_f_Send_Dbg_SDLFault_CanTxPackageType;

/*! Data type for packing user variables for: f_Send_Dbg_SSMFault_CanTx */
typedef struct
{
  uint8* Arg1; /* IN_OUT - SSMFault */
} Os_f_Send_Dbg_SSMFault_CanTxPackageType;


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Appl_vDamRemapNrcCalloutFunc
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Appl_vDamRemapNrcCalloutFunc
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_CanWUp_Val_CheckPN
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_CanWUp_Val_CheckPN
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_CanWUp_Val_StartWakeUpValidation
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_CanWUp_Val_StartWakeUpValidation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_CanWUp_Val_StopWakeUpValidation
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_CanWUp_Val_StopWakeUpValidation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_CddIpcHandler_Init
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_CddIpcHandler_Init
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_CddIpcHandler_Main
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_CddIpcHandler_Main
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_DcmCalloutStub_CompareKey
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_DcmCalloutStub_CompareKey
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_DcmCalloutStub_GetSeed
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_DcmCalloutStub_GetSeed
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_DcmCalloutStub_SessionCallback
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_DcmCalloutStub_SessionCallback
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Det_UserReportError
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Det_UserReportError
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_PMIC_EnterLongWindow_DisableWdg
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_PMIC_EnterLongWindow_DisableWdg
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Pmic_AppEnterInLongWindow
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Pmic_AppEnterInLongWindow
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Pmic_F_SafeState2_v
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Pmic_F_SafeState2_v
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamCalibReset
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamCalibReset
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_DID2023_ProxiData
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_DID2023_ProxiData
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_IntrinsicCameraSN_Readblock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_IntrinsicCameraSN_Readblock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_IpcTxData
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_IpcTxData
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_MCUReadDeviceReg
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_MCUReadDeviceReg
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_MCUReadDeviceRegData
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_MCUReadDeviceRegData
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_MCUWriteDeviceReg
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_MCUWriteDeviceReg
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_ReportErrorStatus1_0_B
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_ReportErrorStatus1_0_B
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_ShutdownOS
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_ShutdownOS
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Update_CDD_IPCHandler_MirrorBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Update_CDD_IPCHandler_MirrorBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Update_CalDataProvider_MirrorBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Update_CalDataProvider_MirrorBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Update_Cdd_Safety_MirrorBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Update_Cdd_Safety_MirrorBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Update_ComCallout_FlagStatus
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Update_ComCallout_FlagStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Update_Proxi_MirrorBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Update_Proxi_MirrorBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Update_SafetyGuard_MirrorBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Update_SafetyGuard_MirrorBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_f_Send_Dbg_SDLFault_CanTx
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_f_Send_Dbg_SDLFault_CanTx
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_f_Send_Dbg_SSMFault_CanTx
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_f_Send_Dbg_SSMFault_CanTx
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Trusted function configuration data: Appl_vDamRemapNrcCalloutFunc */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Appl_vDamRemapNrcCalloutFunc =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Appl_vDamRemapNrcCalloutFunc,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: CanWUp_Val_CheckPN */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_CanWUp_Val_CheckPN =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_CanWUp_Val_CheckPN,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: CanWUp_Val_StartWakeUpValidation */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_CanWUp_Val_StartWakeUpValidation =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_CanWUp_Val_StartWakeUpValidation,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: CanWUp_Val_StopWakeUpValidation */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_CanWUp_Val_StopWakeUpValidation =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_CanWUp_Val_StopWakeUpValidation,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: CddIpcHandler_Init */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_CddIpcHandler_Init =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_CddIpcHandler_Init,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: CddIpcHandler_Main */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_CddIpcHandler_Main =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_CddIpcHandler_Main,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: DcmCalloutStub_CompareKey */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_DcmCalloutStub_CompareKey =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_DcmCalloutStub_CompareKey,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: DcmCalloutStub_GetSeed */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_DcmCalloutStub_GetSeed =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_DcmCalloutStub_GetSeed,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: DcmCalloutStub_SessionCallback */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_DcmCalloutStub_SessionCallback =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_DcmCalloutStub_SessionCallback,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Det_UserReportError */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Det_UserReportError =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Det_UserReportError,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: PMIC_EnterLongWindow_DisableWdg */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_PMIC_EnterLongWindow_DisableWdg =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_PMIC_EnterLongWindow_DisableWdg,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Pmic_AppEnterInLongWindow */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Pmic_AppEnterInLongWindow =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Pmic_AppEnterInLongWindow,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Pmic_F_SafeState2_v */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Pmic_F_SafeState2_v =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Pmic_F_SafeState2_v,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: RE_CalDataProvider_Nvm_SVSCamCalibReset */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamCalibReset =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamCalibReset,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: RE_DID2023_ProxiData */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_DID2023_ProxiData =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_RE_DID2023_ProxiData,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: RE_IntrinsicCameraSN_Readblock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_IntrinsicCameraSN_Readblock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_RE_IntrinsicCameraSN_Readblock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: RE_IpcTxData */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_IpcTxData =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_RE_IpcTxData,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: RE_MCUReadDeviceReg */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_MCUReadDeviceReg =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_RE_MCUReadDeviceReg,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: RE_MCUReadDeviceRegData */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_MCUReadDeviceRegData =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_RE_MCUReadDeviceRegData,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: RE_MCUWriteDeviceReg */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_MCUWriteDeviceReg =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_RE_MCUWriteDeviceReg,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: RE_ReportErrorStatus1_0_B */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RE_ReportErrorStatus1_0_B =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_RE_ReportErrorStatus1_0_B,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: ShutdownOS */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_ShutdownOS =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_ShutdownOS,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Update_CDD_IPCHandler_MirrorBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Update_CDD_IPCHandler_MirrorBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Update_CDD_IPCHandler_MirrorBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Update_CalDataProvider_MirrorBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Update_CalDataProvider_MirrorBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Update_CalDataProvider_MirrorBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Update_Cdd_Safety_MirrorBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Update_Cdd_Safety_MirrorBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Update_Cdd_Safety_MirrorBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Update_ComCallout_FlagStatus */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Update_ComCallout_FlagStatus =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Update_ComCallout_FlagStatus,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Update_Proxi_MirrorBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Update_Proxi_MirrorBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Update_Proxi_MirrorBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Update_SafetyGuard_MirrorBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Update_SafetyGuard_MirrorBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Update_SafetyGuard_MirrorBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: f_Send_Dbg_SDLFault_CanTx */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_f_Send_Dbg_SDLFault_CanTx =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_f_Send_Dbg_SDLFault_CanTx,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: f_Send_Dbg_SSMFault_CanTx */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_f_Send_Dbg_SSMFault_CanTx =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trusted_Core0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_f_Send_Dbg_SSMFault_CanTx,
  /* .Context  = */ NULL_PTR
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for trusted functions. */
CONSTP2CONST(Os_ServiceTfConfigType, OS_CONST, OS_CONST)
  OsCfg_TrustedFunctionRefs[OS_TRUSTEDFUNCTIONID_COUNT + 1] =                                /* PRQA S 1533, 4521 */ /* MD_Os_Rule8.9_1533, MD_Os_Rule10.1_4521 */
{
  &OsCfg_Service_Appl_vDamRemapNrcCalloutFunc,
  &OsCfg_Service_CanWUp_Val_CheckPN,
  &OsCfg_Service_CanWUp_Val_StartWakeUpValidation,
  &OsCfg_Service_CanWUp_Val_StopWakeUpValidation,
  &OsCfg_Service_CddIpcHandler_Init,
  &OsCfg_Service_CddIpcHandler_Main,
  &OsCfg_Service_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus,
  &OsCfg_Service_DcmCalloutStub_CompareKey,
  &OsCfg_Service_DcmCalloutStub_GetSeed,
  &OsCfg_Service_DcmCalloutStub_SessionCallback,
  &OsCfg_Service_Det_UserReportError,
  &OsCfg_Service_PMIC_EnterLongWindow_DisableWdg,
  &OsCfg_Service_Pmic_AppEnterInLongWindow,
  &OsCfg_Service_Pmic_F_SafeState2_v,
  &OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamCalibReset,
  &OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock,
  &OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock,
  &OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock,
  &OsCfg_Service_RE_DID2023_ProxiData,
  &OsCfg_Service_RE_IntrinsicCameraSN_Readblock,
  &OsCfg_Service_RE_IpcTxData,
  &OsCfg_Service_RE_MCUReadDeviceReg,
  &OsCfg_Service_RE_MCUReadDeviceRegData,
  &OsCfg_Service_RE_MCUWriteDeviceReg,
  &OsCfg_Service_RE_ReportErrorStatus1_0_B,
  &OsCfg_Service_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx,
  &OsCfg_Service_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx,
  &OsCfg_Service_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx,
  &OsCfg_Service_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx,
  &OsCfg_Service_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx,
  &OsCfg_Service_ShutdownOS,
  &OsCfg_Service_Update_CDD_IPCHandler_MirrorBlock,
  &OsCfg_Service_Update_CalDataProvider_MirrorBlock,
  &OsCfg_Service_Update_Cdd_Safety_MirrorBlock,
  &OsCfg_Service_Update_ComCallout_FlagStatus,
  &OsCfg_Service_Update_Proxi_MirrorBlock,
  &OsCfg_Service_Update_SafetyGuard_MirrorBlock,
  &OsCfg_Service_f_Send_Dbg_SDLFault_CanTx,
  &OsCfg_Service_f_Send_Dbg_SSMFault_CanTx,
  NULL_PTR
};

/*! Object reference table for non-trusted functions. */
CONSTP2CONST(Os_ServiceNtfConfigType, OS_CONST, OS_CONST)
  OsCfg_NonTrustedFunctionRefs[OS_NONTRUSTEDFUNCTIONID_COUNT + 1] =                            /* PRQA S 1533, 4521 */ /* MD_Os_Rule8.9_1533, MD_Os_Rule10.1_4521 */
{
  NULL_PTR
};

/*! Object reference table for fast trusted functions. */
CONSTP2CONST(Os_ServiceFtfConfigType, OS_CONST, OS_CONST)
  OsCfg_FastTrustedFunctionRefs[OS_FASTTRUSTEDFUNCTIONID_COUNT + 1] =                            /* PRQA S 1533, 4521 */ /* MD_Os_Rule8.9_1533, MD_Os_Rule10.1_4521 */
{
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Appl_vDamRemapNrcCalloutFunc
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Appl_vDamRemapNrcCalloutFunc
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_Appl_vDamRemapNrcCalloutFuncPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_Appl_vDamRemapNrcCalloutFuncPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  Appl_vDamRemapNrcCalloutFunc
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_CanWUp_Val_CheckPN
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_CanWUp_Val_CheckPN
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_CanWUp_Val_CheckPNPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_CanWUp_Val_CheckPNPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  CanWUp_Val_CheckPN
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_CanWUp_Val_StartWakeUpValidation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_CanWUp_Val_StartWakeUpValidation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  /* #10 Call service function. */
  CanWUp_Val_StartWakeUpValidation();

  OS_IGNORE_UNREF_PARAM(FunctionParams);                                             /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_CanWUp_Val_StopWakeUpValidation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_CanWUp_Val_StopWakeUpValidation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  /* #10 Call service function. */
  CanWUp_Val_StopWakeUpValidation();

  OS_IGNORE_UNREF_PARAM(FunctionParams);                                             /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_CddIpcHandler_Init
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_CddIpcHandler_Init
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  /* #10 Call service function. */
  CddIpcHandler_Init();

  OS_IGNORE_UNREF_PARAM(FunctionParams);                                             /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_CddIpcHandler_Main
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_CddIpcHandler_Main
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  /* #10 Call service function. */
  CddIpcHandler_Main();

  OS_IGNORE_UNREF_PARAM(FunctionParams);                                             /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatusPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatusPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_DcmCalloutStub_CompareKey
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_DcmCalloutStub_CompareKey
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_DcmCalloutStub_CompareKeyPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_DcmCalloutStub_CompareKeyPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = DcmCalloutStub_CompareKey
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_DcmCalloutStub_GetSeed
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_DcmCalloutStub_GetSeed
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_DcmCalloutStub_GetSeedPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_DcmCalloutStub_GetSeedPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = DcmCalloutStub_GetSeed
  (
    package->Arg1,
    package->Arg2,
    package->Arg3,
    package->Arg4
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_DcmCalloutStub_SessionCallback
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_DcmCalloutStub_SessionCallback
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_DcmCalloutStub_SessionCallbackPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_DcmCalloutStub_SessionCallbackPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  DcmCalloutStub_SessionCallback
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Det_UserReportError
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Det_UserReportError
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Det_UserReportErrorPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Det_UserReportErrorPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Det_UserReportError
  (
    package->Arg1,
    package->Arg2,
    package->Arg3,
    package->Arg4
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_PMIC_EnterLongWindow_DisableWdg
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_PMIC_EnterLongWindow_DisableWdg
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  /* #10 Call service function. */
  PMIC_EnterLongWindow_DisableWdg();

  OS_IGNORE_UNREF_PARAM(FunctionParams);                                             /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Pmic_AppEnterInLongWindow
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Pmic_AppEnterInLongWindow
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Pmic_AppEnterInLongWindowPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Pmic_AppEnterInLongWindowPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Pmic_AppEnterInLongWindow
  (
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Pmic_F_SafeState2_v
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Pmic_F_SafeState2_v
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_Pmic_F_SafeState2_vPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_Pmic_F_SafeState2_vPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  Pmic_F_SafeState2_v
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamCalibReset
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamCalibReset
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_RE_CalDataProvider_Nvm_SVSCamCalibResetPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_RE_CalDataProvider_Nvm_SVSCamCalibResetPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = RE_CalDataProvider_Nvm_SVSCamCalibReset
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_DID2023_ProxiData
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_DID2023_ProxiData
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_RE_DID2023_ProxiDataPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_RE_DID2023_ProxiDataPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  RE_DID2023_ProxiData
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_IntrinsicCameraSN_Readblock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_IntrinsicCameraSN_Readblock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_RE_IntrinsicCameraSN_ReadblockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_RE_IntrinsicCameraSN_ReadblockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = RE_IntrinsicCameraSN_Readblock
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_IpcTxData
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_IpcTxData
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_RE_IpcTxDataPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_RE_IpcTxDataPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  RE_IpcTxData
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_MCUReadDeviceReg
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_MCUReadDeviceReg
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_RE_MCUReadDeviceRegPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_RE_MCUReadDeviceRegPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = RE_MCUReadDeviceReg
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_MCUReadDeviceRegData
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_MCUReadDeviceRegData
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_RE_MCUReadDeviceRegDataPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_RE_MCUReadDeviceRegDataPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = RE_MCUReadDeviceRegData
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_MCUWriteDeviceReg
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_MCUWriteDeviceReg
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_RE_MCUWriteDeviceRegPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_RE_MCUWriteDeviceRegPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = RE_MCUWriteDeviceReg
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_RE_ReportErrorStatus1_0_B
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_RE_ReportErrorStatus1_0_B
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_RE_ReportErrorStatus1_0_BPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_RE_ReportErrorStatus1_0_BPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = RE_ReportErrorStatus1_0_B
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_TxPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_TxPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_TxPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_TxPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_TxPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_TxPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_TxPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_TxPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_TxPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_TxPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_ShutdownOS
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_ShutdownOS
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_ShutdownOSPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_ShutdownOSPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  ShutdownOS
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Update_CDD_IPCHandler_MirrorBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Update_CDD_IPCHandler_MirrorBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_Update_CDD_IPCHandler_MirrorBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_Update_CDD_IPCHandler_MirrorBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  Update_CDD_IPCHandler_MirrorBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Update_CalDataProvider_MirrorBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Update_CalDataProvider_MirrorBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_Update_CalDataProvider_MirrorBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_Update_CalDataProvider_MirrorBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  Update_CalDataProvider_MirrorBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Update_Cdd_Safety_MirrorBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Update_Cdd_Safety_MirrorBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_Update_Cdd_Safety_MirrorBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_Update_Cdd_Safety_MirrorBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  Update_Cdd_Safety_MirrorBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Update_ComCallout_FlagStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Update_ComCallout_FlagStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_Update_ComCallout_FlagStatusPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_Update_ComCallout_FlagStatusPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  Update_ComCallout_FlagStatus
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Update_Proxi_MirrorBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Update_Proxi_MirrorBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_Update_Proxi_MirrorBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_Update_Proxi_MirrorBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  Update_Proxi_MirrorBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Update_SafetyGuard_MirrorBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Update_SafetyGuard_MirrorBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_Update_SafetyGuard_MirrorBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_Update_SafetyGuard_MirrorBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  Update_SafetyGuard_MirrorBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_f_Send_Dbg_SDLFault_CanTx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_f_Send_Dbg_SDLFault_CanTx
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_f_Send_Dbg_SDLFault_CanTxPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_f_Send_Dbg_SDLFault_CanTxPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  f_Send_Dbg_SDLFault_CanTx
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_f_Send_Dbg_SSMFault_CanTx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_f_Send_Dbg_SSMFault_CanTx
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2CONST(Os_f_Send_Dbg_SSMFault_CanTxPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2CONST(Os_f_Send_Dbg_SSMFault_CanTxPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  f_Send_Dbg_SSMFault_CanTx
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Os_Call_Appl_vDamRemapNrcCalloutFunc
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_Appl_vDamRemapNrcCalloutFunc
(
  uint8 Arg1,
  uint8 Arg2,
  uint8* Arg3
)
{
  Os_Appl_vDamRemapNrcCalloutFuncPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Appl_vDamRemapNrcCalloutFunc, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_CanWUp_Val_CheckPN
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_CanWUp_Val_CheckPN
(
  uint32 Arg1
)
{
  Os_CanWUp_Val_CheckPNPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_CanWUp_Val_CheckPN, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_CanWUp_Val_StartWakeUpValidation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_CanWUp_Val_StartWakeUpValidation
(
  void
)
{
  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_CanWUp_Val_StartWakeUpValidation, NULL_PTR);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_CanWUp_Val_StopWakeUpValidation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_CanWUp_Val_StopWakeUpValidation
(
  void
)
{
  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_CanWUp_Val_StopWakeUpValidation, NULL_PTR);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_CddIpcHandler_Init
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_CddIpcHandler_Init
(
  void
)
{
  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_CddIpcHandler_Init, NULL_PTR);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_CddIpcHandler_Main
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_CddIpcHandler_Main
(
  void
)
{
  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_CddIpcHandler_Main, NULL_PTR);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus
(
  uint8 Arg1,
  uint8 Arg2,
  uint8 Arg3
)
{
  Os_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatusPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_DcmCalloutStub_CompareKey
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_DcmCalloutStub_CompareKey
(
  const uint8* Arg1,
  uint8 Arg2,
  uint8* Arg3
)
{
  Os_DcmCalloutStub_CompareKeyPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_DcmCalloutStub_CompareKey, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_DcmCalloutStub_GetSeed
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_DcmCalloutStub_GetSeed
(
  const uint8* Arg1,
  uint8 Arg2,
  uint8* Arg3,
  uint8* Arg4
)
{
  Os_DcmCalloutStub_GetSeedPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;
  package.Arg4 = Arg4;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_DcmCalloutStub_GetSeed, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_DcmCalloutStub_SessionCallback
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_DcmCalloutStub_SessionCallback
(
  uint8 Arg1,
  uint8 Arg2
)
{
  Os_DcmCalloutStub_SessionCallbackPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_DcmCalloutStub_SessionCallback, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_Det_UserReportError
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(uint8, OS_CODE) Os_Call_Det_UserReportError
(
  uint16 Arg1,
  uint8 Arg2,
  uint8 Arg3,
  uint8 Arg4
)
{
  Os_Det_UserReportErrorPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;
  package.Arg4 = Arg4;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Det_UserReportError, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_PMIC_EnterLongWindow_DisableWdg
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_PMIC_EnterLongWindow_DisableWdg
(
  void
)
{
  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_PMIC_EnterLongWindow_DisableWdg, NULL_PTR);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_Pmic_AppEnterInLongWindow
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(sint32, OS_CODE) Os_Call_Pmic_AppEnterInLongWindow
(
  void
)
{
  Os_Pmic_AppEnterInLongWindowPackageType package;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Pmic_AppEnterInLongWindow, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Pmic_F_SafeState2_v
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_Pmic_F_SafeState2_v
(
  uint8 Arg1
)
{
  Os_Pmic_F_SafeState2_vPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Pmic_F_SafeState2_v, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_RE_CalDataProvider_Nvm_SVSCamCalibReset
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_RE_CalDataProvider_Nvm_SVSCamCalibReset
(
  const TbSVS_S_SVSCamCalibReset_t * Arg1
)
{
  Os_RE_CalDataProvider_Nvm_SVSCamCalibResetPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamCalibReset, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock
(
  const TbSVS_S_SVSCamEOLCalibDataToNVM_t * Arg1
)
{
  Os_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock
(
  const TbSVS_S_SVSCamOCCalibDataToNVM_t * Arg1
)
{
  Os_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock
(
  const TbSVS_S_SVSCamSCCalibDataToNVM_t * Arg1
)
{
  Os_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_RE_DID2023_ProxiData
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_RE_DID2023_ProxiData
(
  const uint8 * Arg1,
  uint16 Arg2,
  uint8 * Arg3
)
{
  Os_RE_DID2023_ProxiDataPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_RE_DID2023_ProxiData, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_RE_IntrinsicCameraSN_Readblock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_RE_IntrinsicCameraSN_Readblock
(
  IntrinsicCamID* Arg1,
  CamNvmReadSts* Arg2
)
{
  Os_RE_IntrinsicCameraSN_ReadblockPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_RE_IntrinsicCameraSN_Readblock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_RE_IpcTxData
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_RE_IpcTxData
(
  void * Arg1,
  uint16 Arg2,
  uint16 Arg3
)
{
  Os_RE_IpcTxDataPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_RE_IpcTxData, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_RE_MCUReadDeviceReg
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(uint8, OS_CODE) Os_Call_RE_MCUReadDeviceReg
(
  uint8 Arg1,
  uint16 Arg2
)
{
  Os_RE_MCUReadDeviceRegPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_RE_MCUReadDeviceReg, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_RE_MCUReadDeviceRegData
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(uint8, OS_CODE) Os_Call_RE_MCUReadDeviceRegData
(
  uint8 Arg1,
  uint16 * Arg2
)
{
  Os_RE_MCUReadDeviceRegDataPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_RE_MCUReadDeviceRegData, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_RE_MCUWriteDeviceReg
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(uint8, OS_CODE) Os_Call_RE_MCUWriteDeviceReg
(
  uint8 Arg1,
  uint16 Arg2,
  uint16 Arg3
)
{
  Os_RE_MCUWriteDeviceRegPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_RE_MCUWriteDeviceReg, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_RE_ReportErrorStatus1_0_B
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_RE_ReportErrorStatus1_0_B
(
  uint32 Arg1,
  uint32 Arg2,
  const ErrorMgr_stAddData* Arg3
)
{
  Os_RE_ReportErrorStatus1_0_BPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_RE_ReportErrorStatus1_0_B, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx
(
  PduIdType Arg1,
  PduInfoType* Arg2
)
{
  Os_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_TxPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx
(
  PduIdType Arg1,
  PduInfoType* Arg2
)
{
  Os_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_TxPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx
(
  PduIdType Arg1,
  PduInfoType* Arg2
)
{
  Os_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_TxPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx
(
  PduIdType Arg1,
  PduInfoType* Arg2
)
{
  Os_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_TxPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx
(
  PduIdType Arg1,
  PduInfoType* Arg2
)
{
  Os_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_TxPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_ShutdownOS
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_ShutdownOS
(
  uint8 Arg1
)
{
  Os_ShutdownOSPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_ShutdownOS, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_Update_CDD_IPCHandler_MirrorBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_Update_CDD_IPCHandler_MirrorBlock
(
  boolean Arg1
)
{
  Os_Update_CDD_IPCHandler_MirrorBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Update_CDD_IPCHandler_MirrorBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_Update_CalDataProvider_MirrorBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_Update_CalDataProvider_MirrorBlock
(
  boolean Arg1
)
{
  Os_Update_CalDataProvider_MirrorBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Update_CalDataProvider_MirrorBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_Update_Cdd_Safety_MirrorBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_Update_Cdd_Safety_MirrorBlock
(
  boolean Arg1
)
{
  Os_Update_Cdd_Safety_MirrorBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Update_Cdd_Safety_MirrorBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_Update_ComCallout_FlagStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_Update_ComCallout_FlagStatus
(
  uint8* Arg1,
  uint8 Arg2
)
{
  Os_Update_ComCallout_FlagStatusPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Update_ComCallout_FlagStatus, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_Update_Proxi_MirrorBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_Update_Proxi_MirrorBlock
(
  boolean Arg1
)
{
  Os_Update_Proxi_MirrorBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Update_Proxi_MirrorBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_Update_SafetyGuard_MirrorBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_Update_SafetyGuard_MirrorBlock
(
  boolean Arg1
)
{
  Os_Update_SafetyGuard_MirrorBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Update_SafetyGuard_MirrorBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_f_Send_Dbg_SDLFault_CanTx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_f_Send_Dbg_SDLFault_CanTx
(
  uint16 Arg1
)
{
  Os_f_Send_Dbg_SDLFault_CanTxPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_f_Send_Dbg_SDLFault_CanTx, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

/**********************************************************************************************************************
 *  Os_Call_f_Send_Dbg_SSMFault_CanTx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(void, OS_CODE) Os_Call_f_Send_Dbg_SSMFault_CanTx
(
  uint8* Arg1
)
{
  Os_f_Send_Dbg_SSMFault_CanTxPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_f_Send_Dbg_SSMFault_CanTx, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  END OF FILE: Os_ServiceFunction_Lcfg.c
 *********************************************************************************************************************/
