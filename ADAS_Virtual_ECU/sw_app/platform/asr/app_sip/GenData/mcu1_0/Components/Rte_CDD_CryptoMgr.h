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
 *             File:  Rte_CDD_CryptoMgr.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <CDD_CryptoMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CDD_CRYPTOMGR_H
# define RTE_CDD_CRYPTOMGR_H

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

# include "Rte_CDD_CryptoMgr_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_PartNumMgr_PpFlashSts_v_FlashSts_u16;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_RpFlashSts_v_FlashSts_u16 (0U)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_CryptoMgr_RpProxiConfigData_ProxiData(P2VAR(ME_Hydra2defs_S_CodingTableExt_t, AUTOMATIC, RTE_CDD_CRYPTOMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_RpFlashSts_v_FlashSts_u16 Rte_Read_CDD_CryptoMgr_RpFlashSts_v_FlashSts_u16
#  define Rte_Read_CDD_CryptoMgr_RpFlashSts_v_FlashSts_u16(data) (*(data) = Rte_SWC_PartNumMgr_PpFlashSts_v_FlashSts_u16, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpProxiConfigData_ProxiData Rte_Read_CDD_CryptoMgr_RpProxiConfigData_ProxiData


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetDataIndex(NvM_BlockIdType parg0, uint8 DataIndex); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_VAR_NOINIT) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_DS_CertAccessInfo_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)14, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DS_CertAccessInfo_SetDataIndex(arg1) (NvM_SetDataIndex((NvM_BlockIdType)14, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DS_CertAccessInfo_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)14, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DS_FileHeader_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)13, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DS_FileHeader_SetDataIndex(arg1) (NvM_SetDataIndex((NvM_BlockIdType)13, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup1_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)68, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup1_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)68, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup1_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)68, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup2_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)69, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup2_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)69, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DS_SecureLogGroup2_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)69, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_SecAccessDelayFlag_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)3, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_SecAccessDelayFlag_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)3, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_SecAccessInvalidCount_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)4, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_SecAccessInvalidCount_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)4, arg1))

/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_NvMBlockDescriptor_SecondCounter_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_DefaultValue;
extern CONST(boolean, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_NvMBlockDescriptor_CertificateExpired_DefaultValue;
extern CONST(Array_15Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_NvMBlockDescriptor_SystemTimestamp_DefaultValue;
extern CONST(SecureLogRecord_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_DefaultValue;
extern CONST(SecureLogRecord_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_NvMBlockDescriptor_SecondCounter_DefaultValue() (Rte_CDD_CryptoMgr_NvMBlockDescriptor_SecondCounter_DefaultValue)

#  define Rte_CData_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_DefaultValue() (Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_DefaultValue)

#  define Rte_CData_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_DefaultValue() (Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_DefaultValue)

#  define Rte_CData_NvMBlockDescriptor_CertificateExpired_DefaultValue() (Rte_CDD_CryptoMgr_NvMBlockDescriptor_CertificateExpired_DefaultValue)

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_NvMBlockDescriptor_SystemTimestamp_DefaultValue() (&(Rte_CDD_CryptoMgr_NvMBlockDescriptor_SystemTimestamp_DefaultValue[0]))
#  else
#   define Rte_CData_NvMBlockDescriptor_SystemTimestamp_DefaultValue() (&Rte_CDD_CryptoMgr_NvMBlockDescriptor_SystemTimestamp_DefaultValue)
#  endif

#  define Rte_CData_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_DefaultValue() (&Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_DefaultValue)

#  define Rte_CData_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_DefaultValue() (&Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_DefaultValue)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(SecureLogRecord_t, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_MirrorBlock;
extern VAR(SecureLogRecord_t, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_MirrorBlock() \
  (&Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_MirrorBlock() \
  (&Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_MirrorBlock)
/* PRQA L:L1 */

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT) Rte_CDD_CryptoMgr_NvMBlockDescriptor_SecondCounter_MirrorBlock;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT) Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_MirrorBlock;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT) Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_MirrorBlock;
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT) Rte_CDD_CryptoMgr_NvMBlockDescriptor_CertificateExpired_MirrorBlock;
extern VAR(Array_15Bytes, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT) Rte_CDD_CryptoMgr_NvMBlockDescriptor_SystemTimestamp_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_NvMBlockDescriptor_SecondCounter_MirrorBlock() \
  (&Rte_CDD_CryptoMgr_NvMBlockDescriptor_SecondCounter_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_MirrorBlock() \
  (&Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_MirrorBlock() \
  (&Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_NvMBlockDescriptor_CertificateExpired_MirrorBlock() \
  (&Rte_CDD_CryptoMgr_NvMBlockDescriptor_CertificateExpired_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_NvMBlockDescriptor_SystemTimestamp_MirrorBlock() (&((*RtePim_NvMBlockDescriptor_SystemTimestamp_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvMBlockDescriptor_SystemTimestamp_MirrorBlock() RtePim_NvMBlockDescriptor_SystemTimestamp_MirrorBlock()
#  endif
#  define RtePim_NvMBlockDescriptor_SystemTimestamp_MirrorBlock() \
  (&Rte_CDD_CryptoMgr_NvMBlockDescriptor_SystemTimestamp_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define CDD_CryptoMgr_START_SEC_CODE
# include "CDD_CryptoMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_ReadData DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22100C_Security_Status_Read_ReadData DataServices_Data_22100C_Security_Status_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22201F_Boot_Failure_Reason_Read_ReadData DataServices_Data_22201F_Boot_Failure_Reason_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_ReadData DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222031_Disallowed_Certificate_List_Read_ReadData DataServices_Data_222031_Disallowed_Certificate_List_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222032_Secure_Log_Read_ReadData DataServices_Data_222032_Secure_Log_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222951_Certificate_Store_UUID_Read_ReadData DataServices_Data_222951_Certificate_Store_UUID_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222954_Policy_Type_Read_ReadData DataServices_Data_222954_Policy_Type_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_ReadData DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_ReadData DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_ReadData DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_ReadData DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22295B_HTA_Header_Info_Read DataServices_Data_22295B_HTA_Header_Info_Read
#  define RTE_RUNNABLE_DataServices_Data_22295C_HTA_Header_UUID_Read DataServices_Data_22295C_HTA_Header_UUID_Read
#  define RTE_RUNNABLE_DataServices_Data_22295E_DCL_Header_UUID_Read DataServices_Data_22295E_DCL_Header_UUID_Read
#  define RTE_RUNNABLE_DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_ReadData DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_ReadData DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_ReadData
#  define RTE_RUNNABLE_RE_CryptoArray_CryptoArray RE_CryptoArray_CryptoArray
#  define RTE_RUNNABLE_RE_CryptoMgr_Init RE_CryptoMgr_Init
#  define RTE_RUNNABLE_RE_CryptoMgr_Main RE_CryptoMgr_Main
#  define RTE_RUNNABLE_RE_Get_SecureAuthenticationStatus RE_Get_SecureAuthenticationStatus
#  define RTE_RUNNABLE_RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_CertAccessInfo_JobFinished RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_CertAccessInfo_JobFinished
#  define RTE_RUNNABLE_RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_FileHeader_JobFinished RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_FileHeader_JobFinished
# endif

# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22100C_Security_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22100C_Security_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data5ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22201F_Boot_Failure_Reason_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22201F_Boot_Failure_Reason_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data960ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222031_Disallowed_Certificate_List_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222031_Disallowed_Certificate_List_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3072ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222032_Secure_Log_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222032_Secure_Log_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1296ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222951_Certificate_Store_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222951_Certificate_Store_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data16ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222954_Policy_Type_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222954_Policy_Type_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222957_Hosted_App_Firmware_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1056ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222958_Hosted_App_firmware_Header_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data96ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_222959_Hosted_App_Firmware_Cal_Config_Data_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data352ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22295A_Hosted_App_Firmware_Cal_Config_Data_Header_UUID_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22295B_HTA_Header_Info_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22295B_HTA_Header_Info_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data176ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22295C_HTA_Header_UUID_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22295C_HTA_Header_UUID_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data16ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22295E_DCL_Header_UUID_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22295E_DCL_Header_UUID_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data16ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22295F_DCL_and_Cerstore_Header_Info_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data176ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, CDD_CryptoMgr_CODE) DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, CDD_CryptoMgr_CODE) RE_CryptoArray_CryptoArray(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) CertPtr, uint16 CertLen); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CDD_CryptoMgr_CODE) RE_CryptoMgr_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, CDD_CryptoMgr_CODE) RE_CryptoMgr_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, CDD_CryptoMgr_CODE) RE_Get_SecureAuthenticationStatus(P2VAR(ADAStatusType, AUTOMATIC, RTE_VAR_NOINIT) ADAStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CDD_CryptoMgr_CODE) RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_CertAccessInfo_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CDD_CryptoMgr_CODE) RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_FileHeader_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define CDD_CryptoMgr_STOP_SEC_CODE
# include "CDD_CryptoMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_220108_Authenticated_Diagnostics_Active_Role_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22100C_Security_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22100C_Security_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22201F_Boot_Failure_Reason_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22201F_Boot_Failure_Reason_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222030_Authenticated_Diagnostic_Previous_Access_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222031_Disallowed_Certificate_List_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222031_Disallowed_Certificate_List_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222032_Secure_Log_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222032_Secure_Log_Read_E_NOT_OK (1U)

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

#  define RTE_E_DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F111_Public_Certificates_Regional_Support_Read_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC2_SRBS_DS_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CDD_CRYPTOMGR_H */

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

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
