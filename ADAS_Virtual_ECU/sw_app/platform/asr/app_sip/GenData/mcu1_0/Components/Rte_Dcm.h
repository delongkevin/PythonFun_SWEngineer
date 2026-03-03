/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Dcm.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <Dcm>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_DCM_H
# define RTE_DCM_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Dcm_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(uint8, RTE_CODE) Rte_Mode_Dcm_Dcm_Read_Mode_Dcm_Read_Mode(P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) previousMode, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) nextMode);
FUNC(uint8, RTE_CODE) Rte_Mode_Dcm_Dcm_Read_ModeProgPreconditionCheck_Dcm_Read_ModeProgPreconditionCheck(P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) previousMode, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CN_FDCAN2_28a8fc44_DcmCommunicationControl_ComMConf_ComMChannel_CN_FDCAN2_28a8fc44(Dcm_CommunicationModeType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting(Dcm_ControlDtcSettingType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset(void);
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_3101D003_Application_Logical_Block_Hash_Start(P2CONST(Dcm_StartDataIn_Routine_3101D003_Application_Logical_Block_Hash_In_ReqDataArrayType, AUTOMATIC, RTE_DCM_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101D003_Application_Logical_Block_Hash_Out_ResDataArrayType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_3101D003_Application_Logical_Block_Hash_Start(P2CONST(Dcm_StartDataIn_Routine_3101D003_Application_Logical_Block_Hash_In_ReqDataType, AUTOMATIC, RTE_DCM_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101D003_Application_Logical_Block_Hash_Out_ResDataType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_3101F000_Check_Program_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101F000_Check_Program_Start_Out_ResDataArrayType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_3101F000_Check_Program_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101F000_Check_Program_Start_Out_ResDataType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_3101FF00_FlashErase_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FF00_FlashErase_Start_Out_ResDataArrayType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_3101FF00_FlashErase_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FF00_FlashErase_Start_Out_ResDataType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_3101FF01_checkProgrammingDependencies_FlashChecksum_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FF01_checkProgrammingDependencies_FlashChecksum_Start_Out_ResDataArrayType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_3101FF01_checkProgrammingDependencies_FlashChecksum_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FF01_checkProgrammingDependencies_FlashChecksum_Start_Out_ResDataType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_Dcm_Read_Mode_Dcm_Read_Mode Rte_Mode_Dcm_Dcm_Read_Mode_Dcm_Read_Mode
#  define Rte_Mode_Dcm_Read_ModeProgPreconditionCheck_Dcm_Read_ModeProgPreconditionCheck Rte_Mode_Dcm_Dcm_Read_ModeProgPreconditionCheck_Dcm_Read_ModeProgPreconditionCheck


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_CN_FDCAN2_28a8fc44_DcmCommunicationControl_ComMConf_ComMChannel_CN_FDCAN2_28a8fc44 Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CN_FDCAN2_28a8fc44_DcmCommunicationControl_ComMConf_ComMChannel_CN_FDCAN2_28a8fc44
#  define Rte_Switch_DcmControlDtcSetting_DcmControlDtcSetting Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting
#  define Rte_Switch_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl
#  define Rte_Switch_DcmEcuReset_DcmEcuReset Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset


/**********************************************************************************************************************
 * Rte_Feedback_<p>_<m> (mode switch acknowledge)
 *********************************************************************************************************************/
#  define Rte_SwitchAck_DcmEcuReset_DcmEcuReset Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_CRYPTOMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22100C_Security_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22100C_Security_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data5ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22201F_Boot_Failure_Reason_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22201F_Boot_Failure_Reason_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data960ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222031_Disallowed_Certificate_List_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222031_Disallowed_Certificate_List_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3072ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222032_Secure_Log_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222032_Secure_Log_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1296ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222951_Certificate_Store_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222951_Certificate_Store_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data16ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222954_Policy_Type_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222954_Policy_Type_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1056ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data96ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data352ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22295B_HTA_Header_Info_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22295B_HTA_Header_Info_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data176ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22295C_HTA_Header_UUID_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22295C_HTA_Header_UUID_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data16ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22295E_DCL_Header_UUID_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22295E_DCL_Header_UUID_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data16ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data176ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CDD_CRYPTOMGR_APPL_CODE) DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_CDD_CRYPTOMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SWC_DIDMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_220103_VIN_Lock_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_220103_VIN_Lock_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_220107_RoE_Activation_State_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_220107_RoE_Activation_State_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_220107_RoE_Activation_State_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_220107_RoE_Activation_State_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_221002_Vehicle_Speed_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_221002_Vehicle_Speed_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_221004_Battery_Voltage_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_221004_Battery_Voltage_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_221008_ECU_Life_Time_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_221008_ECU_Life_Time_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_221009_ECU_Time_Since_Ignition_ON_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_221009_ECU_Time_Since_Ignition_ON_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22100B_Diagnostic_Tool_and_Session_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22100B_Diagnostic_Tool_and_Session_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22102A_Check_EOL_Configuration_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22102A_Check_EOL_Configuration_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data9ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22191D_Time_of_Power_Latch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22191D_Time_of_Power_Latch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_221921_Operational_Mode_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_221921_Operational_Mode_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data9ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222001_Odometer_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222001_Odometer_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222002_Odometer_at_last_Flash_programming_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222002_Odometer_at_last_Flash_programming_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222008_ECU_Life_Time_Not_Volatile_Memory_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222008_ECU_Life_Time_Not_Volatile_Memory_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22200A_Ignition_ON_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22200A_Ignition_ON_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22200B_Time_First_DTC_Detection_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22200B_Time_First_DTC_Detection_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22200C_Time_Since_Ignition_ON_of_first_DTC_Detection_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22200C_Time_Since_Ignition_ON_of_first_DTC_Detection_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22200D_Odometer_Last_Clear_Data_Trouble_Code_DTC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22200D_Odometer_Last_Clear_Data_Trouble_Code_DTC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222010_Programming_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222010_Programming_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222013_VIN_Lock_State_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222013_VIN_Lock_State_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222024_Read_ECU_PROXI_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222024_Read_ECU_PROXI_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data255ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222024_Read_ECU_PROXI_Data_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222026_CAN_Overrun_Counters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222026_CAN_Overrun_Counters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data8ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22292E_PROXI_Write_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22292E_PROXI_Write_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222939_FDCAN2_BUS_Network_WakeUp_Reason_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222939_FDCAN2_BUS_Network_WakeUp_Reason_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data24ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222945_Flow_Control_Test_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222945_Flow_Control_Test_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data200ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222945_Flow_Control_Test_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_222945_Flow_Control_Test_WriteData(P2CONST(Dcm_Data200ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224421_USS_Sensor_1_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224421_USS_Sensor_1_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224422_USS_Sensor2_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224422_USS_Sensor2_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224423_USS_Sensor_3_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224423_USS_Sensor_3_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224424_USS_Sensor_4_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224424_USS_Sensor_4_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224425_USS_Sensor_5_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224425_USS_Sensor_5_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224426_USS_Sensor_6_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224426_USS_Sensor_6_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224427_USS_Sensor_7_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224427_USS_Sensor_7_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224428_USS_Sensor_8_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224428_USS_Sensor_8_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224429_USS_Sensor_9_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224429_USS_Sensor_9_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22442A_USS_Sensor_10_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22442A_USS_Sensor_10_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22442B_USS_Sensor_11_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22442B_USS_Sensor_11_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22442C_USS_Sensor_12_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22442C_USS_Sensor_12_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224451_EOL_Calibration_State_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_224451_EOL_Calibration_State_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data44ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225100_SPM_status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225100_SPM_status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225102_FD_CAN14_Rx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225102_FD_CAN14_Rx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data34ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225103_FD_CAN2_Rx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225103_FD_CAN2_Rx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data41ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225104_FD_CAN14_Tx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225104_FD_CAN14_Tx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data5ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225105_FD_CAN2_Tx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225105_FD_CAN2_Tx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data19ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225107_Front_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225107_Front_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225109_Rear_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225109_Rear_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225201_Plant_Mode_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225201_Plant_Mode_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225300_Rear_Braking_Event_1_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225300_Rear_Braking_Event_1_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225301_Rear_Braking_Event_2_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225301_Rear_Braking_Event_2_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225302_Rear_Braking_Event_3_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225302_Rear_Braking_Event_3_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225303_SPM_Event_Abort_1_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225303_SPM_Event_Abort_1_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225304_SPM_Event_Abort_2_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225304_SPM_Event_Abort_2_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225305_SPM_Event_Abort_3_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225305_SPM_Event_Abort_3_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225500_Trailer_Sense_and_Drive_Function_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225500_Trailer_Sense_and_Drive_Function_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data42ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225501_Trailer_coupler_sense_detection_Function_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_225501_Trailer_coupler_sense_detection_Function_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data48ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22F10B_ECU_Qualification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22F10B_ECU_Qualification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22F186_Active_Diagnostic_Session_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22F186_Active_Diagnostic_Session_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22F190_VIN_Original_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22F190_VIN_Original_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data17ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22F1A1_Configuration_Code_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22F1A1_Configuration_Code_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data11ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22F1A6_Message_Matrix_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22F1A6_Message_Matrix_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22F1B0_VIN_Current_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22F1B0_VIN_Current_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data17ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD00_Plant_Camera_Calibration_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD00_Plant_Camera_Calibration_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data54ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD00_Plant_Camera_Calibration_Data_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD00_Plant_Camera_Calibration_Data_WriteData(P2CONST(Dcm_Data54ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD01_Previous_Camera_Calibration_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD01_Previous_Camera_Calibration_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data50ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3072ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_WriteData(P2CONST(Dcm_Data3072ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD07_OC_Result_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD07_OC_Result_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data8ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD08_OC_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD08_OC_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data28ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD08_OC_Data_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD08_OC_Data_Read_WriteData(P2CONST(Dcm_Data28ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD0A_SC_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD0A_SC_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data28ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD0A_SC_Data_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD0A_SC_Data_Read_WriteData(P2CONST(Dcm_Data28ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD0C_Front_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD0C_Front_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data256ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD0D_Left_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD0D_Left_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data256ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD0E_Rear_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD0E_Rear_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data256ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD0F_Right_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD0F_Right_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data256ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD1C_Current_Camera_Calibration_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD1C_Current_Camera_Calibration_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data52ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD1E_Calibration_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD1E_Calibration_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data21ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD20_ECU_PinStates_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD20_ECU_PinStates_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD28_USS_Ringing_Frequency_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD28_USS_Ringing_Frequency_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data24ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD29_USS_Driving_Frequency_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD29_USS_Driving_Frequency_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data24ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD2A_USS_Ringing_Time_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD2A_USS_Ringing_Time_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data24ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD2B_USS_Direct_Distance_0xFD2B_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD2B_USS_Direct_Distance_0xFD2B_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data24ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD2C_USS_Temperature_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD2C_USS_Temperature_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data24ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD2D_USS_Sensor_ID_IME_SN_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD2D_USS_Sensor_ID_IME_SN_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data48ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD2E_USS_Sensor_ID_Murata_SN_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD2E_USS_Sensor_ID_Murata_SN_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data48ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD33_Magna_Testing_2_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD33_Magna_Testing_2_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD33_Magna_Testing_2_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD33_Magna_Testing_2_Read_WriteData(P2CONST(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD42_Failsafe_Behaviour_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD42_Failsafe_Behaviour_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD42_Failsafe_Behaviour_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD42_Failsafe_Behaviour_Read_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD43_Active_Safe_State_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD43_Active_Safe_State_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD44_Error_Flags_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD44_Error_Flags_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD46_Camera_Power_Supply_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD46_Camera_Power_Supply_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data8ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD47_SoC_Temperature_0xFD47_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD47_SoC_Temperature_0xFD47_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD48_PCBA_Temperature_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD48_PCBA_Temperature_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD49_SoC_Die_Temperature_ID_0xFD49_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD49_SoC_Die_Temperature_ID_0xFD49_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data16ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD4A_Ultrasonic_Sensors_Power_supply_and_Current_Level_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD4A_Ultrasonic_Sensors_Power_supply_and_Current_Level_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data9ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD60_ECU_Software_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD60_ECU_Software_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD61_Vehicle_Variant_Coding_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD61_Vehicle_Variant_Coding_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD62_ASIL_QM_Fault_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD62_ASIL_QM_Fault_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD64_ASIL_B_Fault_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD64_ASIL_B_Fault_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data138ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD65_FuSa_Module_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD65_FuSa_Module_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data28ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD66_Camera_occlusion_and_low_light_status_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD66_Camera_occlusion_and_low_light_status_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data9ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD67_Camera_DLD_Status_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD67_Camera_DLD_Status_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD74_PHY_Tunning_Error_And_Buffer_Mark_Error_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD74_PHY_Tunning_Error_And_Buffer_Mark_Error_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD86_Functional_Settings_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD86_Functional_Settings_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data6ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD86_Functional_Settings_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FD86_Functional_Settings_Read_WriteData(P2CONST(Dcm_Data6ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF0_ECU_shutdown_process_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF0_ECU_shutdown_process_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF0_ECU_shutdown_process_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF0_ECU_shutdown_process_Read_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF1_CPU_Load_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF1_CPU_Load_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data5ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF2_Reset_Reason_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF2_Reset_Reason_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF5_PerformanceStatEnable_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF5_PerformanceStatEnable_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF5_PerformanceStatEnable_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF5_PerformanceStatEnable_Read_WriteData(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF6_RunTimeStatsData_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF6_RunTimeStatsData_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data306ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF7_Intrinsic_Camera_NvM_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF7_Intrinsic_Camera_NvM_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data44ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF8_StackUsage_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_22FDF8_StackUsage_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data37ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_2E2023_PROXI_Data_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_2E2023_PROXI_Data_WriteData(P2CONST(Dcm_Data255ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_2EF184_Application_Software_Fingerprint_writing_information_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_2EF184_Application_Software_Fingerprint_writing_information_WriteData(P2CONST(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_2EF185_Application_Data_Software_Fingerprint_Writing_Information_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_2EF185_Application_Data_Software_Fingerprint_Writing_Information_WriteData(P2CONST(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_2EFD4E_Reset_NVM_Write_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_2EFD4E_Reset_NVM_Write_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_2F5001_Gear_Position_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_2F5001_Gear_Position_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_2F5001_Gear_Position_Read_ReturnControlToECU(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_2F5001_Gear_Position_Read_ShortTermAdjustment(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_DIDMGR_APPL_CODE) DataServices_Data_2F5001_Gear_Position_Read_ShortTermAdjustment(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SWC_DIDMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SWC_PARTNUMMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data20ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F10D_Diagnostic_Specification_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F10D_Diagnostic_Specification_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F110_ECU_Diagnostic_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F110_ECU_Diagnostic_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F112_PTESLM_Hardware_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F112_PTESLM_Hardware_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F122_Software_EBOM_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F122_Software_EBOM_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data90ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F132_EBOM_ECU_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F132_EBOM_ECU_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F133_EBOM_Assembly_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F133_EBOM_Assembly_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F134_CODEP_assembly_part_number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F134_CODEP_assembly_part_number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data11ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F154_Hardware_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F154_Hardware_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F155_Software_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F155_Software_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F180_Boot_Software_Version_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F180_Boot_Software_Version_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F181_Application_Software_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F181_Application_Software_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data66ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F182_Application_Data_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F182_Application_Data_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data40ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F187_CODEP_ECU_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F187_CODEP_ECU_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data11ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data11ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F18C_ECU_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F18C_ECU_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data11ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data11ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data11ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F1A0_System_Identification_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F1A0_System_Identification_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data90ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F1A2_Vector_Delivery_ID_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F1A2_Vector_Delivery_ID_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data71ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data43ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD13_Magna_Software_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD13_Magna_Software_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data5ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD15_Magna_Production_HW_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD15_Magna_Production_HW_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data64ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD1D_PCB_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD1D_PCB_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_WriteData(P2CONST(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD38_Programmed_Assembly_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_PARTNUMMGR_APPL_CODE) DataServices_Data_22FD38_Programmed_Assembly_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data16ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SWC_PARTNUMMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SWC_RIDMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31012000_Original_VIN_Lock_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31012001_Original_VIN_Unlock_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartFlexibleOutArrayData_Routine_3101D002_Check_Programming_Preconditions_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SWC_RIDMGR_APPL_CODE) RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SWC_RIDMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_Data_220103_VIN_Lock_Status_ReadData DataServices_Data_220103_VIN_Lock_Status_ReadData
#  define Rte_Call_DataServices_Data_220107_RoE_Activation_State_ReadData DataServices_Data_220107_RoE_Activation_State_ReadData
#  define Rte_Call_DataServices_Data_220107_RoE_Activation_State_WriteData DataServices_Data_220107_RoE_Activation_State_WriteData
#  define Rte_Call_DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_ReadData DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_ReadData
#  define Rte_Call_DataServices_Data_221002_Vehicle_Speed_ReadData DataServices_Data_221002_Vehicle_Speed_ReadData
#  define Rte_Call_DataServices_Data_221004_Battery_Voltage_ReadData DataServices_Data_221004_Battery_Voltage_ReadData
#  define Rte_Call_DataServices_Data_221008_ECU_Life_Time_ReadData DataServices_Data_221008_ECU_Life_Time_ReadData
#  define Rte_Call_DataServices_Data_221009_ECU_Time_Since_Ignition_ON_ReadData DataServices_Data_221009_ECU_Time_Since_Ignition_ON_ReadData
#  define Rte_Call_DataServices_Data_22100B_Diagnostic_Tool_and_Session_Status_ReadData DataServices_Data_22100B_Diagnostic_Tool_and_Session_Status_ReadData
#  define Rte_Call_DataServices_Data_22100C_Security_Status_Read_ReadData DataServices_Data_22100C_Security_Status_Read_ReadData
#  define Rte_Call_DataServices_Data_22102A_Check_EOL_Configuration_Data_ReadData DataServices_Data_22102A_Check_EOL_Configuration_Data_ReadData
#  define Rte_Call_DataServices_Data_22191D_Time_of_Power_Latch_ReadData DataServices_Data_22191D_Time_of_Power_Latch_ReadData
#  define Rte_Call_DataServices_Data_221921_Operational_Mode_Status_ReadData DataServices_Data_221921_Operational_Mode_Status_ReadData
#  define Rte_Call_DataServices_Data_222001_Odometer_ReadData DataServices_Data_222001_Odometer_ReadData
#  define Rte_Call_DataServices_Data_222002_Odometer_at_last_Flash_programming_ReadData DataServices_Data_222002_Odometer_at_last_Flash_programming_ReadData
#  define Rte_Call_DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_ReadData DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_ReadData
#  define Rte_Call_DataServices_Data_222008_ECU_Life_Time_Not_Volatile_Memory_ReadData DataServices_Data_222008_ECU_Life_Time_Not_Volatile_Memory_ReadData
#  define Rte_Call_DataServices_Data_22200A_Ignition_ON_Counter_ReadData DataServices_Data_22200A_Ignition_ON_Counter_ReadData
#  define Rte_Call_DataServices_Data_22200B_Time_First_DTC_Detection_ReadData DataServices_Data_22200B_Time_First_DTC_Detection_ReadData
#  define Rte_Call_DataServices_Data_22200C_Time_Since_Ignition_ON_of_first_DTC_Detection_ReadData DataServices_Data_22200C_Time_Since_Ignition_ON_of_first_DTC_Detection_ReadData
#  define Rte_Call_DataServices_Data_22200D_Odometer_Last_Clear_Data_Trouble_Code_DTC_ReadData DataServices_Data_22200D_Odometer_Last_Clear_Data_Trouble_Code_DTC_ReadData
#  define Rte_Call_DataServices_Data_222010_Programming_Status_ReadData DataServices_Data_222010_Programming_Status_ReadData
#  define Rte_Call_DataServices_Data_222013_VIN_Lock_State_Read_ReadData DataServices_Data_222013_VIN_Lock_State_Read_ReadData
#  define Rte_Call_DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_ReadData DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_ReadData
#  define Rte_Call_DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_ReadData DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_ReadData
#  define Rte_Call_DataServices_Data_22201F_Boot_Failure_Reason_Read_ReadData DataServices_Data_22201F_Boot_Failure_Reason_Read_ReadData
#  define Rte_Call_DataServices_Data_222024_Read_ECU_PROXI_Data_ReadData DataServices_Data_222024_Read_ECU_PROXI_Data_ReadData
#  define Rte_Call_DataServices_Data_222024_Read_ECU_PROXI_Data_ReadDataLength DataServices_Data_222024_Read_ECU_PROXI_Data_ReadDataLength
#  define Rte_Call_DataServices_Data_222026_CAN_Overrun_Counters_ReadData DataServices_Data_222026_CAN_Overrun_Counters_ReadData
#  define Rte_Call_DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_ReadData DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_ReadData
#  define Rte_Call_DataServices_Data_222031_Disallowed_Certificate_List_Read_ReadData DataServices_Data_222031_Disallowed_Certificate_List_Read_ReadData
#  define Rte_Call_DataServices_Data_222032_Secure_Log_Read_ReadData DataServices_Data_222032_Secure_Log_Read_ReadData
#  define Rte_Call_DataServices_Data_22292E_PROXI_Write_Counter_ReadData DataServices_Data_22292E_PROXI_Write_Counter_ReadData
#  define Rte_Call_DataServices_Data_222939_FDCAN2_BUS_Network_WakeUp_Reason_ReadData DataServices_Data_222939_FDCAN2_BUS_Network_WakeUp_Reason_ReadData
#  define Rte_Call_DataServices_Data_222945_Flow_Control_Test_ReadData DataServices_Data_222945_Flow_Control_Test_ReadData
#  define Rte_Call_DataServices_Data_222945_Flow_Control_Test_WriteData DataServices_Data_222945_Flow_Control_Test_WriteData
#  define Rte_Call_DataServices_Data_222951_Certificate_Store_UUID_Read_ReadData DataServices_Data_222951_Certificate_Store_UUID_Read_ReadData
#  define Rte_Call_DataServices_Data_222954_Policy_Type_Read_ReadData DataServices_Data_222954_Policy_Type_Read_ReadData
#  define Rte_Call_DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_ReadData DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_ReadData
#  define Rte_Call_DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_ReadData DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_ReadData
#  define Rte_Call_DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_ReadData DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_ReadData
#  define Rte_Call_DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_ReadData DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_ReadData
#  define Rte_Call_DataServices_Data_22295B_HTA_Header_Info_Read_ReadData DataServices_Data_22295B_HTA_Header_Info_Read
#  define Rte_Call_DataServices_Data_22295C_HTA_Header_UUID_Read_ReadData DataServices_Data_22295C_HTA_Header_UUID_Read
#  define Rte_Call_DataServices_Data_22295E_DCL_Header_UUID_Read_ReadData DataServices_Data_22295E_DCL_Header_UUID_Read
#  define Rte_Call_DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_ReadData DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_ReadData
#  define Rte_Call_DataServices_Data_224421_USS_Sensor_1_Part_Number_Read_ReadData DataServices_Data_224421_USS_Sensor_1_Part_Number_Read_ReadData
#  define Rte_Call_DataServices_Data_224422_USS_Sensor2_Part_Number_Read_ReadData DataServices_Data_224422_USS_Sensor2_Part_Number_Read_ReadData
#  define Rte_Call_DataServices_Data_224423_USS_Sensor_3_Part_Number_Read_ReadData DataServices_Data_224423_USS_Sensor_3_Part_Number_Read_ReadData
#  define Rte_Call_DataServices_Data_224424_USS_Sensor_4_Part_Number_Read_ReadData DataServices_Data_224424_USS_Sensor_4_Part_Number_Read_ReadData
#  define Rte_Call_DataServices_Data_224425_USS_Sensor_5_Part_Number_Read_ReadData DataServices_Data_224425_USS_Sensor_5_Part_Number_Read_ReadData
#  define Rte_Call_DataServices_Data_224426_USS_Sensor_6_Part_Number_Read_ReadData DataServices_Data_224426_USS_Sensor_6_Part_Number_Read_ReadData
#  define Rte_Call_DataServices_Data_224427_USS_Sensor_7_Part_Number_Read_ReadData DataServices_Data_224427_USS_Sensor_7_Part_Number_Read_ReadData
#  define Rte_Call_DataServices_Data_224428_USS_Sensor_8_Part_Number_Read_ReadData DataServices_Data_224428_USS_Sensor_8_Part_Number_Read_ReadData
#  define Rte_Call_DataServices_Data_224429_USS_Sensor_9_Part_Number_Read_ReadData DataServices_Data_224429_USS_Sensor_9_Part_Number_Read_ReadData
#  define Rte_Call_DataServices_Data_22442A_USS_Sensor_10_Part_Number_Read_ReadData DataServices_Data_22442A_USS_Sensor_10_Part_Number_Read_ReadData
#  define Rte_Call_DataServices_Data_22442B_USS_Sensor_11_Part_Number_Read_ReadData DataServices_Data_22442B_USS_Sensor_11_Part_Number_Read_ReadData
#  define Rte_Call_DataServices_Data_22442C_USS_Sensor_12_Part_Number_Read_ReadData DataServices_Data_22442C_USS_Sensor_12_Part_Number_Read_ReadData
#  define Rte_Call_DataServices_Data_224451_EOL_Calibration_State_Read_ReadData DataServices_Data_224451_EOL_Calibration_State_Read_ReadData
#  define Rte_Call_DataServices_Data_225100_SPM_status_Read_ReadData DataServices_Data_225100_SPM_status_Read_ReadData
#  define Rte_Call_DataServices_Data_225102_FD_CAN14_Rx_Signals_Read_ReadData DataServices_Data_225102_FD_CAN14_Rx_Signals_Read_ReadData
#  define Rte_Call_DataServices_Data_225103_FD_CAN2_Rx_Signals_Read_ReadData DataServices_Data_225103_FD_CAN2_Rx_Signals_Read_ReadData
#  define Rte_Call_DataServices_Data_225104_FD_CAN14_Tx_Signals_Read_ReadData DataServices_Data_225104_FD_CAN14_Tx_Signals_Read_ReadData
#  define Rte_Call_DataServices_Data_225105_FD_CAN2_Tx_Signals_Read_ReadData DataServices_Data_225105_FD_CAN2_Tx_Signals_Read_ReadData
#  define Rte_Call_DataServices_Data_225107_Front_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData DataServices_Data_225107_Front_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData
#  define Rte_Call_DataServices_Data_225109_Rear_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData DataServices_Data_225109_Rear_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData
#  define Rte_Call_DataServices_Data_225201_Plant_Mode_Status_Read_ReadData DataServices_Data_225201_Plant_Mode_Status_Read_ReadData
#  define Rte_Call_DataServices_Data_225300_Rear_Braking_Event_1_Read_ReadData DataServices_Data_225300_Rear_Braking_Event_1_Read_ReadData
#  define Rte_Call_DataServices_Data_225301_Rear_Braking_Event_2_Read_ReadData DataServices_Data_225301_Rear_Braking_Event_2_Read_ReadData
#  define Rte_Call_DataServices_Data_225302_Rear_Braking_Event_3_Read_ReadData DataServices_Data_225302_Rear_Braking_Event_3_Read_ReadData
#  define Rte_Call_DataServices_Data_225303_SPM_Event_Abort_1_Read_ReadData DataServices_Data_225303_SPM_Event_Abort_1_Read_ReadData
#  define Rte_Call_DataServices_Data_225304_SPM_Event_Abort_2_Read_ReadData DataServices_Data_225304_SPM_Event_Abort_2_Read_ReadData
#  define Rte_Call_DataServices_Data_225305_SPM_Event_Abort_3_Read_ReadData DataServices_Data_225305_SPM_Event_Abort_3_Read_ReadData
#  define Rte_Call_DataServices_Data_225500_Trailer_Sense_and_Drive_Function_Data_Read_ReadData DataServices_Data_225500_Trailer_Sense_and_Drive_Function_Data_Read_ReadData
#  define Rte_Call_DataServices_Data_225501_Trailer_coupler_sense_detection_Function_Data_Read_ReadData DataServices_Data_225501_Trailer_coupler_sense_detection_Function_Data_Read_ReadData
#  define Rte_Call_DataServices_Data_22F10B_ECU_Qualification_ReadData DataServices_Data_22F10B_ECU_Qualification_ReadData
#  define Rte_Call_DataServices_Data_22F10D_Diagnostic_Specification_Information_ReadData DataServices_Data_22F10D_Diagnostic_Specification_Information_ReadData
#  define Rte_Call_DataServices_Data_22F110_ECU_Diagnostic_Identification_ReadData DataServices_Data_22F110_ECU_Diagnostic_Identification_ReadData
#  define Rte_Call_DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_ReadData DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_ReadData
#  define Rte_Call_DataServices_Data_22F112_PTESLM_Hardware_Number_ReadData DataServices_Data_22F112_PTESLM_Hardware_Number_ReadData
#  define Rte_Call_DataServices_Data_22F122_Software_EBOM_Part_Number_ReadData DataServices_Data_22F122_Software_EBOM_Part_Number_ReadData
#  define Rte_Call_DataServices_Data_22F132_EBOM_ECU_Part_Number_ReadData DataServices_Data_22F132_EBOM_ECU_Part_Number_ReadData
#  define Rte_Call_DataServices_Data_22F133_EBOM_Assembly_Part_Number_ReadData DataServices_Data_22F133_EBOM_Assembly_Part_Number_ReadData
#  define Rte_Call_DataServices_Data_22F134_CODEP_assembly_part_number_ReadData DataServices_Data_22F134_CODEP_assembly_part_number_ReadData
#  define Rte_Call_DataServices_Data_22F154_Hardware_Supplier_Identification_ReadData DataServices_Data_22F154_Hardware_Supplier_Identification_ReadData
#  define Rte_Call_DataServices_Data_22F155_Software_Supplier_Identification_ReadData DataServices_Data_22F155_Software_Supplier_Identification_ReadData
#  define Rte_Call_DataServices_Data_22F180_Boot_Software_Version_Information_ReadData DataServices_Data_22F180_Boot_Software_Version_Information_ReadData
#  define Rte_Call_DataServices_Data_22F181_Application_Software_Identification_ReadData DataServices_Data_22F181_Application_Software_Identification_ReadData
#  define Rte_Call_DataServices_Data_22F182_Application_Data_Identification_ReadData DataServices_Data_22F182_Application_Data_Identification_ReadData
#  define Rte_Call_DataServices_Data_22F186_Active_Diagnostic_Session_ReadData DataServices_Data_22F186_Active_Diagnostic_Session_ReadData
#  define Rte_Call_DataServices_Data_22F187_CODEP_ECU_Part_Number_ReadData DataServices_Data_22F187_CODEP_ECU_Part_Number_ReadData
#  define Rte_Call_DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_ReadData DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_ReadData
#  define Rte_Call_DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_ReadData DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_ReadData
#  define Rte_Call_DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_ReadData DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_ReadData
#  define Rte_Call_DataServices_Data_22F18C_ECU_Serial_Number_ReadData DataServices_Data_22F18C_ECU_Serial_Number_ReadData
#  define Rte_Call_DataServices_Data_22F190_VIN_Original_ReadData DataServices_Data_22F190_VIN_Original_ReadData
#  define Rte_Call_DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_ReadData DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_ReadData
#  define Rte_Call_DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_ReadData DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_ReadData
#  define Rte_Call_DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_ReadData DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_ReadData
#  define Rte_Call_DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_ReadData DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_ReadData
#  define Rte_Call_DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_ReadData DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_ReadData
#  define Rte_Call_DataServices_Data_22F1A0_System_Identification_Data_ReadData DataServices_Data_22F1A0_System_Identification_Data_ReadData
#  define Rte_Call_DataServices_Data_22F1A1_Configuration_Code_ReadData DataServices_Data_22F1A1_Configuration_Code_ReadData
#  define Rte_Call_DataServices_Data_22F1A2_Vector_Delivery_ID_ReadData DataServices_Data_22F1A2_Vector_Delivery_ID_ReadData
#  define Rte_Call_DataServices_Data_22F1A6_Message_Matrix_ReadData DataServices_Data_22F1A6_Message_Matrix_ReadData
#  define Rte_Call_DataServices_Data_22F1B0_VIN_Current_ReadData DataServices_Data_22F1B0_VIN_Current_ReadData
#  define Rte_Call_DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_ReadData DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_ReadData
#  define Rte_Call_DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_ReadData DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_ReadData
#  define Rte_Call_DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_ReadData DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_ReadData
#  define Rte_Call_DataServices_Data_22FD00_Plant_Camera_Calibration_Data_ReadData DataServices_Data_22FD00_Plant_Camera_Calibration_Data_ReadData
#  define Rte_Call_DataServices_Data_22FD00_Plant_Camera_Calibration_Data_WriteData DataServices_Data_22FD00_Plant_Camera_Calibration_Data_WriteData
#  define Rte_Call_DataServices_Data_22FD01_Previous_Camera_Calibration_Data_ReadData DataServices_Data_22FD01_Previous_Camera_Calibration_Data_ReadData
#  define Rte_Call_DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadData DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadDataLength DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadDataLength
#  define Rte_Call_DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_WriteData DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_WriteData
#  define Rte_Call_DataServices_Data_22FD07_OC_Result_Read_ReadData DataServices_Data_22FD07_OC_Result_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD08_OC_Data_Read_ReadData DataServices_Data_22FD08_OC_Data_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD08_OC_Data_Read_WriteData DataServices_Data_22FD08_OC_Data_Read_WriteData
#  define Rte_Call_DataServices_Data_22FD0A_SC_Data_Read_ReadData DataServices_Data_22FD0A_SC_Data_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD0A_SC_Data_Read_WriteData DataServices_Data_22FD0A_SC_Data_Read_WriteData
#  define Rte_Call_DataServices_Data_22FD0C_Front_Camera_Data_EEPROM_Read_ReadData DataServices_Data_22FD0C_Front_Camera_Data_EEPROM_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD0D_Left_Camera_Data_EEPROM_Read_ReadData DataServices_Data_22FD0D_Left_Camera_Data_EEPROM_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD0E_Rear_Camera_Data_EEPROM_Read_ReadData DataServices_Data_22FD0E_Rear_Camera_Data_EEPROM_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD0F_Right_Camera_Data_EEPROM_Read_ReadData DataServices_Data_22FD0F_Right_Camera_Data_EEPROM_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD13_Magna_Software_Version_ReadData DataServices_Data_22FD13_Magna_Software_Version_ReadData
#  define Rte_Call_DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_ReadData DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD15_Magna_Production_HW_Number_Read_ReadData DataServices_Data_22FD15_Magna_Production_HW_Number_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_ReadData DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_ReadData DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD1C_Current_Camera_Calibration_Data_Read_ReadData DataServices_Data_22FD1C_Current_Camera_Calibration_Data_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD1D_PCB_Serial_Number_ReadData DataServices_Data_22FD1D_PCB_Serial_Number_ReadData
#  define Rte_Call_DataServices_Data_22FD1E_Calibration_Status_Read_ReadData DataServices_Data_22FD1E_Calibration_Status_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD20_ECU_PinStates_Read_ReadData DataServices_Data_22FD20_ECU_PinStates_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD28_USS_Ringing_Frequency_Read_ReadData DataServices_Data_22FD28_USS_Ringing_Frequency_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD29_USS_Driving_Frequency_Read_ReadData DataServices_Data_22FD29_USS_Driving_Frequency_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD2A_USS_Ringing_Time_Read_ReadData DataServices_Data_22FD2A_USS_Ringing_Time_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD2B_USS_Direct_Distance_0xFD2B_Read_ReadData DataServices_Data_22FD2B_USS_Direct_Distance_0xFD2B_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD2C_USS_Temperature_Read_ReadData DataServices_Data_22FD2C_USS_Temperature_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD2D_USS_Sensor_ID_IME_SN_Read_ReadData DataServices_Data_22FD2D_USS_Sensor_ID_IME_SN_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD2E_USS_Sensor_ID_Murata_SN_Read_ReadData DataServices_Data_22FD2E_USS_Sensor_ID_Murata_SN_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_ReadData DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_WriteData DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_WriteData
#  define Rte_Call_DataServices_Data_22FD33_Magna_Testing_2_Read_ReadData DataServices_Data_22FD33_Magna_Testing_2_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD33_Magna_Testing_2_Read_WriteData DataServices_Data_22FD33_Magna_Testing_2_Read_WriteData
#  define Rte_Call_DataServices_Data_22FD38_Programmed_Assembly_ReadData DataServices_Data_22FD38_Programmed_Assembly_ReadData
#  define Rte_Call_DataServices_Data_22FD42_Failsafe_Behaviour_Read_ReadData DataServices_Data_22FD42_Failsafe_Behaviour_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD42_Failsafe_Behaviour_Read_WriteData DataServices_Data_22FD42_Failsafe_Behaviour_Read_WriteData
#  define Rte_Call_DataServices_Data_22FD43_Active_Safe_State_Read_ReadData DataServices_Data_22FD43_Active_Safe_State_Read
#  define Rte_Call_DataServices_Data_22FD44_Error_Flags_Read_ReadData DataServices_Data_22FD44_Error_Flags_Read
#  define Rte_Call_DataServices_Data_22FD46_Camera_Power_Supply_Read_ReadData DataServices_Data_22FD46_Camera_Power_Supply_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD47_SoC_Temperature_0xFD47_Read_ReadData DataServices_Data_22FD47_SoC_Temperature_0xFD47_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD48_PCBA_Temperature_Read_ReadData DataServices_Data_22FD48_PCBA_Temperature_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD49_SoC_Die_Temperature_ID_0xFD49_Read_ReadData DataServices_Data_22FD49_SoC_Die_Temperature_ID_0xFD49_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD4A_Ultrasonic_Sensors_Power_supply_and_Current_Level_Read_ReadData DataServices_Data_22FD4A_Ultrasonic_Sensors_Power_supply_and_Current_Level_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD60_ECU_Software_Status_Read_ReadData DataServices_Data_22FD60_ECU_Software_Status_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD61_Vehicle_Variant_Coding_Data_Read_ReadData DataServices_Data_22FD61_Vehicle_Variant_Coding_Data_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD62_ASIL_QM_Fault_Status_Read_ReadData DataServices_Data_22FD62_ASIL_QM_Fault_Status_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD64_ASIL_B_Fault_Status_Read_ReadData DataServices_Data_22FD64_ASIL_B_Fault_Status_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD65_FuSa_Module_Status_Read_ReadData DataServices_Data_22FD65_FuSa_Module_Status_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD66_Camera_occlusion_and_low_light_status_Read_ReadData DataServices_Data_22FD66_Camera_occlusion_and_low_light_status_Read
#  define Rte_Call_DataServices_Data_22FD67_Camera_DLD_Status_Read_ReadData DataServices_Data_22FD67_Camera_DLD_Status_Read
#  define Rte_Call_DataServices_Data_22FD74_PHY_Tunning_Error_And_Buffer_Mark_Error_Read_ReadData DataServices_Data_22FD74_PHY_Tunning_Error_And_Buffer_Mark_Error_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD86_Functional_Settings_Read_ReadData DataServices_Data_22FD86_Functional_Settings_Read_ReadData
#  define Rte_Call_DataServices_Data_22FD86_Functional_Settings_Read_WriteData DataServices_Data_22FD86_Functional_Settings_Read_WriteData
#  define Rte_Call_DataServices_Data_22FDF0_ECU_shutdown_process_Read_ReadData DataServices_Data_22FDF0_ECU_shutdown_process_Read_ReadData
#  define Rte_Call_DataServices_Data_22FDF0_ECU_shutdown_process_Read_WriteData DataServices_Data_22FDF0_ECU_shutdown_process_Read_WriteData
#  define Rte_Call_DataServices_Data_22FDF1_CPU_Load_Read_ReadData DataServices_Data_22FDF1_CPU_Load_Read_ReadData
#  define Rte_Call_DataServices_Data_22FDF2_Reset_Reason_Read_ReadData DataServices_Data_22FDF2_Reset_Reason_Read_ReadData
#  define Rte_Call_DataServices_Data_22FDF5_PerformanceStatEnable_Read_ReadData DataServices_Data_22FDF5_PerformanceStatEnable_Read_ReadData
#  define Rte_Call_DataServices_Data_22FDF5_PerformanceStatEnable_Read_WriteData DataServices_Data_22FDF5_PerformanceStatEnable_Read_WriteData
#  define Rte_Call_DataServices_Data_22FDF6_RunTimeStatsData_Read_ReadData DataServices_Data_22FDF6_RunTimeStatsData_Read_ReadData
#  define Rte_Call_DataServices_Data_22FDF7_Intrinsic_Camera_NvM_Data_Read_ReadData DataServices_Data_22FDF7_Intrinsic_Camera_NvM_Data_Read_ReadData
#  define Rte_Call_DataServices_Data_22FDF8_StackUsage_Read_ReadData DataServices_Data_22FDF8_StackUsage_Read_ReadData
#  define Rte_Call_DataServices_Data_2E2023_PROXI_Data_WriteData DataServices_Data_2E2023_PROXI_Data_WriteData
#  define Rte_Call_DataServices_Data_2EF184_Application_Software_Fingerprint_writing_information_WriteData DataServices_Data_2EF184_Application_Software_Fingerprint_writing_information_WriteData
#  define Rte_Call_DataServices_Data_2EF185_Application_Data_Software_Fingerprint_Writing_Information_WriteData DataServices_Data_2EF185_Application_Data_Software_Fingerprint_Writing_Information_WriteData
#  define Rte_Call_DataServices_Data_2EFD4E_Reset_NVM_Write_WriteData DataServices_Data_2EFD4E_Reset_NVM_Write_WriteData
#  define Rte_Call_DataServices_Data_2F5001_Gear_Position_Read_ReadData DataServices_Data_2F5001_Gear_Position_Read_ReadData
#  define Rte_Call_DataServices_Data_2F5001_Gear_Position_Read_ReturnControlToECU DataServices_Data_2F5001_Gear_Position_Read_ReturnControlToECU
#  define Rte_Call_DataServices_Data_2F5001_Gear_Position_Read_ShortTermAdjustment DataServices_Data_2F5001_Gear_Position_Read_ShortTermAdjustment
#  define Rte_Call_RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Start RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Start
#  define Rte_Call_RoutineServices_Routine_31012000_Original_VIN_Lock_Start RoutineServices_Routine_31012000_Original_VIN_Lock_Start
#  define Rte_Call_RoutineServices_Routine_31012001_Original_VIN_Unlock_Start RoutineServices_Routine_31012001_Original_VIN_Unlock_Start
#  define Rte_Call_RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_Start RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_Start
#  define Rte_Call_RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_Start RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_Start
#  define Rte_Call_RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_Start RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_Start
#  define Rte_Call_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_RequestResults RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_RequestResults
#  define Rte_Call_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_Start RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_Start
#  define Rte_Call_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_RequestResults RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_RequestResults
#  define Rte_Call_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_Start RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_Start
#  define Rte_Call_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_RequestResults RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_RequestResults
#  define Rte_Call_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_Start RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_Start
#  define Rte_Call_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_RequestResults RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_RequestResults
#  define Rte_Call_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Start RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Start
#  define Rte_Call_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Start RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Start
#  define Rte_Call_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Stop RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Stop
#  define Rte_Call_RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_Start RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_Start
#  define Rte_Call_RoutineServices_Routine_3101D003_Application_Logical_Block_Hash_Start Rte_Call_Dcm_RoutineServices_Routine_3101D003_Application_Logical_Block_Hash_Start
#  define Rte_Call_RoutineServices_Routine_3101F000_Check_Program_Start_Start Rte_Call_Dcm_RoutineServices_Routine_3101F000_Check_Program_Start_Start
#  define Rte_Call_RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_Start RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_Start
#  define Rte_Call_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_Start RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_Start
#  define Rte_Call_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Start RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Start
#  define Rte_Call_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Stop RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Stop
#  define Rte_Call_RoutineServices_Routine_3101FF00_FlashErase_Start_Start Rte_Call_Dcm_RoutineServices_Routine_3101FF00_FlashErase_Start_Start
#  define Rte_Call_RoutineServices_Routine_3101FF01_checkProgrammingDependencies_FlashChecksum_Start_Start Rte_Call_Dcm_RoutineServices_Routine_3101FF01_checkProgrammingDependencies_FlashChecksum_Start_Start
#  define Rte_Call_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_Start RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_Start

# endif /* !defined(RTE_CORE) */


# define Dcm_START_SEC_CODE
# include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Dcm_MainFunction Dcm_MainFunction
#  define RTE_RUNNABLE_GetActiveProtocol Dcm_GetActiveProtocol
#  define RTE_RUNNABLE_GetRequestKind Dcm_GetRequestKind
#  define RTE_RUNNABLE_GetSecurityLevel Dcm_GetSecurityLevel
#  define RTE_RUNNABLE_GetSesCtrlType Dcm_GetSesCtrlType
#  define RTE_RUNNABLE_ResetToDefaultSession Dcm_ResetToDefaultSession
#  define RTE_RUNNABLE_SetActiveDiagnostic Dcm_SetActiveDiagnostic
# endif

FUNC(void, Dcm_CODE) Dcm_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetActiveProtocol(P2VAR(Dcm_ProtocolType, AUTOMATIC, RTE_DCM_APPL_VAR) ActiveProtocol); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetRequestKind(uint16 TesterSourceAddress, P2VAR(Dcm_RequestKindType, AUTOMATIC, RTE_DCM_APPL_VAR) RequestKind); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetSecurityLevel(P2VAR(Dcm_SecLevelType, AUTOMATIC, RTE_DCM_APPL_VAR) SecLevel); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_VAR_NOINIT) SesCtrlType); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_ResetToDefaultSession(void); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_SetActiveDiagnostic(boolean active); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Dcm_STOP_SEC_CODE
# include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DCMServices_E_NOT_OK (1U)

#  define RTE_E_DCMServices_E_OK (0U)

#  define RTE_E_DataServices_Data_220103_VIN_Lock_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_220103_VIN_Lock_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_220107_RoE_Activation_State_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_220107_RoE_Activation_State_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_221002_Vehicle_Speed_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_221002_Vehicle_Speed_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_221004_Battery_Voltage_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_221004_Battery_Voltage_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_221008_ECU_Life_Time_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_221008_ECU_Life_Time_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_221009_ECU_Time_Since_Ignition_ON_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_221009_ECU_Time_Since_Ignition_ON_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22100B_Diagnostic_Tool_and_Session_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22100B_Diagnostic_Tool_and_Session_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22100C_Security_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22100C_Security_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22102A_Check_EOL_Configuration_Data_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22102A_Check_EOL_Configuration_Data_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22191D_Time_of_Power_Latch_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22191D_Time_of_Power_Latch_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_221921_Operational_Mode_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_221921_Operational_Mode_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222001_Odometer_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222001_Odometer_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222002_Odometer_at_last_Flash_programming_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222002_Odometer_at_last_Flash_programming_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222008_ECU_Life_Time_Not_Volatile_Memory_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222008_ECU_Life_Time_Not_Volatile_Memory_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22200A_Ignition_ON_Counter_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22200A_Ignition_ON_Counter_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22200B_Time_First_DTC_Detection_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22200B_Time_First_DTC_Detection_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22200C_Time_Since_Ignition_ON_of_first_DTC_Detection_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22200C_Time_Since_Ignition_ON_of_first_DTC_Detection_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22200D_Odometer_Last_Clear_Data_Trouble_Code_DTC_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22200D_Odometer_Last_Clear_Data_Trouble_Code_DTC_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222010_Programming_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222010_Programming_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222013_VIN_Lock_State_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222013_VIN_Lock_State_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22201F_Boot_Failure_Reason_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22201F_Boot_Failure_Reason_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222024_Read_ECU_PROXI_Data_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222024_Read_ECU_PROXI_Data_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222026_CAN_Overrun_Counters_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222026_CAN_Overrun_Counters_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222031_Disallowed_Certificate_List_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222031_Disallowed_Certificate_List_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222032_Secure_Log_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222032_Secure_Log_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22292E_PROXI_Write_Counter_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22292E_PROXI_Write_Counter_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222939_FDCAN2_BUS_Network_WakeUp_Reason_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222939_FDCAN2_BUS_Network_WakeUp_Reason_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222945_Flow_Control_Test_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222945_Flow_Control_Test_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222951_Certificate_Store_UUID_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222951_Certificate_Store_UUID_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222954_Policy_Type_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222954_Policy_Type_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22295B_HTA_Header_Info_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22295B_HTA_Header_Info_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22295C_HTA_Header_UUID_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22295C_HTA_Header_UUID_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22295E_DCL_Header_UUID_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22295E_DCL_Header_UUID_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224421_USS_Sensor_1_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224421_USS_Sensor_1_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224422_USS_Sensor2_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224422_USS_Sensor2_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224423_USS_Sensor_3_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224423_USS_Sensor_3_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224424_USS_Sensor_4_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224424_USS_Sensor_4_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224425_USS_Sensor_5_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224425_USS_Sensor_5_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224426_USS_Sensor_6_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224426_USS_Sensor_6_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224427_USS_Sensor_7_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224427_USS_Sensor_7_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224428_USS_Sensor_8_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224428_USS_Sensor_8_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224429_USS_Sensor_9_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224429_USS_Sensor_9_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22442A_USS_Sensor_10_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22442A_USS_Sensor_10_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22442B_USS_Sensor_11_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22442B_USS_Sensor_11_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22442C_USS_Sensor_12_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22442C_USS_Sensor_12_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224451_EOL_Calibration_State_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224451_EOL_Calibration_State_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225100_SPM_status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225100_SPM_status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225102_FD_CAN14_Rx_Signals_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225102_FD_CAN14_Rx_Signals_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225103_FD_CAN2_Rx_Signals_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225103_FD_CAN2_Rx_Signals_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225104_FD_CAN14_Tx_Signals_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225104_FD_CAN14_Tx_Signals_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225105_FD_CAN2_Tx_Signals_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225105_FD_CAN2_Tx_Signals_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225107_Front_Sensor_HealthBlockage_LiveDetection_Check_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225107_Front_Sensor_HealthBlockage_LiveDetection_Check_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225109_Rear_Sensor_HealthBlockage_LiveDetection_Check_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225109_Rear_Sensor_HealthBlockage_LiveDetection_Check_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225201_Plant_Mode_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225201_Plant_Mode_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225300_Rear_Braking_Event_1_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225300_Rear_Braking_Event_1_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225301_Rear_Braking_Event_2_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225301_Rear_Braking_Event_2_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225302_Rear_Braking_Event_3_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225302_Rear_Braking_Event_3_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225303_SPM_Event_Abort_1_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225303_SPM_Event_Abort_1_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225304_SPM_Event_Abort_2_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225304_SPM_Event_Abort_2_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225305_SPM_Event_Abort_3_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225305_SPM_Event_Abort_3_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225500_Trailer_Sense_and_Drive_Function_Data_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225500_Trailer_Sense_and_Drive_Function_Data_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225501_Trailer_coupler_sense_detection_Function_Data_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225501_Trailer_coupler_sense_detection_Function_Data_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F10B_ECU_Qualification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F10B_ECU_Qualification_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F10D_Diagnostic_Specification_Information_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F10D_Diagnostic_Specification_Information_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F110_ECU_Diagnostic_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F110_ECU_Diagnostic_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F112_PTESLM_Hardware_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F112_PTESLM_Hardware_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F122_Software_EBOM_Part_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F122_Software_EBOM_Part_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F132_EBOM_ECU_Part_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F132_EBOM_ECU_Part_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F133_EBOM_Assembly_Part_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F133_EBOM_Assembly_Part_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F134_CODEP_assembly_part_number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F134_CODEP_assembly_part_number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F154_Hardware_Supplier_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F154_Hardware_Supplier_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F155_Software_Supplier_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F155_Software_Supplier_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F180_Boot_Software_Version_Information_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F180_Boot_Software_Version_Information_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F181_Application_Software_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F181_Application_Software_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F182_Application_Data_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F182_Application_Data_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F186_Active_Diagnostic_Session_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F186_Active_Diagnostic_Session_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F187_CODEP_ECU_Part_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F187_CODEP_ECU_Part_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F18C_ECU_Serial_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F18C_ECU_Serial_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F190_VIN_Original_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F190_VIN_Original_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F1A0_System_Identification_Data_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F1A0_System_Identification_Data_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F1A1_Configuration_Code_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F1A1_Configuration_Code_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F1A2_Vector_Delivery_ID_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F1A2_Vector_Delivery_ID_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F1A6_Message_Matrix_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F1A6_Message_Matrix_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F1B0_VIN_Current_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F1B0_VIN_Current_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD00_Plant_Camera_Calibration_Data_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD00_Plant_Camera_Calibration_Data_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD01_Previous_Camera_Calibration_Data_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD01_Previous_Camera_Calibration_Data_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD07_OC_Result_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD07_OC_Result_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD08_OC_Data_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD08_OC_Data_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD0A_SC_Data_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD0A_SC_Data_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD0C_Front_Camera_Data_EEPROM_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD0C_Front_Camera_Data_EEPROM_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD0D_Left_Camera_Data_EEPROM_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD0D_Left_Camera_Data_EEPROM_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD0E_Rear_Camera_Data_EEPROM_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD0E_Rear_Camera_Data_EEPROM_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD0F_Right_Camera_Data_EEPROM_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD0F_Right_Camera_Data_EEPROM_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD13_Magna_Software_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD13_Magna_Software_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD15_Magna_Production_HW_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD15_Magna_Production_HW_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD1C_Current_Camera_Calibration_Data_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD1C_Current_Camera_Calibration_Data_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD1D_PCB_Serial_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD1D_PCB_Serial_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD1E_Calibration_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD1E_Calibration_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD20_ECU_PinStates_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD20_ECU_PinStates_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD28_USS_Ringing_Frequency_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD28_USS_Ringing_Frequency_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD29_USS_Driving_Frequency_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD29_USS_Driving_Frequency_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD2A_USS_Ringing_Time_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD2A_USS_Ringing_Time_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD2B_USS_Direct_Distance_0xFD2B_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD2B_USS_Direct_Distance_0xFD2B_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD2C_USS_Temperature_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD2C_USS_Temperature_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD2D_USS_Sensor_ID_IME_SN_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD2D_USS_Sensor_ID_IME_SN_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD2E_USS_Sensor_ID_Murata_SN_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD2E_USS_Sensor_ID_Murata_SN_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD33_Magna_Testing_2_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD33_Magna_Testing_2_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD38_Programmed_Assembly_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD38_Programmed_Assembly_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD42_Failsafe_Behaviour_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD42_Failsafe_Behaviour_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD43_Active_Safe_State_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD43_Active_Safe_State_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD44_Error_Flags_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD44_Error_Flags_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD46_Camera_Power_Supply_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD46_Camera_Power_Supply_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD47_SoC_Temperature_0xFD47_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD47_SoC_Temperature_0xFD47_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD48_PCBA_Temperature_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD48_PCBA_Temperature_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD49_SoC_Die_Temperature_ID_0xFD49_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD49_SoC_Die_Temperature_ID_0xFD49_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD4A_Ultrasonic_Sensors_Power_supply_and_Current_Level_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD4A_Ultrasonic_Sensors_Power_supply_and_Current_Level_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD60_ECU_Software_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD60_ECU_Software_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD61_Vehicle_Variant_Coding_Data_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD61_Vehicle_Variant_Coding_Data_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD62_ASIL_QM_Fault_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD62_ASIL_QM_Fault_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD64_ASIL_B_Fault_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD64_ASIL_B_Fault_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD65_FuSa_Module_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD65_FuSa_Module_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD66_Camera_occlusion_and_low_light_status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD66_Camera_occlusion_and_low_light_status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD67_Camera_DLD_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD67_Camera_DLD_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD74_PHY_Tunning_Error_And_Buffer_Mark_Error_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD74_PHY_Tunning_Error_And_Buffer_Mark_Error_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD86_Functional_Settings_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD86_Functional_Settings_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FDF0_ECU_shutdown_process_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FDF0_ECU_shutdown_process_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FDF1_CPU_Load_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FDF1_CPU_Load_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FDF2_Reset_Reason_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FDF2_Reset_Reason_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FDF5_PerformanceStatEnable_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FDF5_PerformanceStatEnable_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FDF6_RunTimeStatsData_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FDF6_RunTimeStatsData_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FDF7_Intrinsic_Camera_NvM_Data_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FDF7_Intrinsic_Camera_NvM_Data_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FDF8_StackUsage_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FDF8_StackUsage_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_2E2023_PROXI_Data_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_2E2023_PROXI_Data_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_2EF184_Application_Software_Fingerprint_writing_information_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_2EF184_Application_Software_Fingerprint_writing_information_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_2EF185_Application_Data_Software_Fingerprint_Writing_Information_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_2EF185_Application_Data_Software_Fingerprint_Writing_Information_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_2EFD4E_Reset_NVM_Write_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_2EFD4E_Reset_NVM_Write_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_2F5001_Gear_Position_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_2F5001_Gear_Position_Read_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31012000_Original_VIN_Lock_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31012000_Original_VIN_Lock_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31012000_Original_VIN_Lock_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31012001_Original_VIN_Unlock_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31012001_Original_VIN_Unlock_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31012001_Original_VIN_Unlock_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101D003_Application_Logical_Block_Hash_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101D003_Application_Logical_Block_Hash_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101D003_Application_Logical_Block_Hash_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101F000_Check_Program_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101F000_Check_Program_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101F000_Check_Program_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101FF00_FlashErase_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101FF00_FlashErase_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101FF00_FlashErase_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101FF01_checkProgrammingDependencies_FlashChecksum_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101FF01_checkProgrammingDependencies_FlashChecksum_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101FF01_checkProgrammingDependencies_FlashChecksum_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_DCM_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_1330:  MISRA rule: Rule8.3
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
