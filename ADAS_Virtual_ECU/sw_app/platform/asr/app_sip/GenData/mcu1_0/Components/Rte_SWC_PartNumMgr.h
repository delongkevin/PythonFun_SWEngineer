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
 *             File:  Rte_SWC_PartNumMgr.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <SWC_PartNumMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PARTNUMMGR_H
# define RTE_SWC_PARTNUMMGR_H

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

# include "Rte_SWC_PartNumMgr_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_PartNumMgr_PpFlashSts_v_FlashSts_u16;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpVINData_VINLockStatus;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpVINData_VINOdoCounter;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PpFlashSts_v_FlashSts_u16 (0U)
#  define Rte_InitValue_RpVINData_VINLockStatus (0U)
#  define Rte_InitValue_RpVINData_VINOdoCounter (0U)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PartNumMgr_R_SSM_1_0_State_State_1_0(P2VAR(SSM_1_0_CoreStatus, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PartNumMgr_R_SSM_2_State_State_2_0(P2VAR(SSM_2_0_CoreStatus, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PartNumMgr_R_SSM_2_State_State_2_1(P2VAR(SSM_2_1_CoreStatus, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PartNumMgr_R_SSM_QNXState_State_QNX(P2VAR(SSM_QNX_CoreStatus, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PartNumMgr_R_SystemState_SystemState(P2VAR(SSM_SystemState, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PartNumMgr_RpUSSConstantData_US_S_USSConstantData_t(P2VAR(US_S_USSConstantData_t, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PartNumMgr_RpUssMrrgData_US_S_MarriageSensorIDs_t(P2VAR(US_S_MarriageSensorIDs_t, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PartNumMgr_RpVINData_VINCurrentData(P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PartNumMgr_RpVINData_VINCurrentData(P2VAR(VINlData_Arr, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PartNumMgr_RpVINData_VINOriginalData(P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PartNumMgr_RpVINData_VINOriginalData(P2VAR(VINlData_Arr, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_SSM_1_0_State_State_1_0 Rte_Read_SWC_PartNumMgr_R_SSM_1_0_State_State_1_0
#  define Rte_Read_R_SSM_2_State_State_2_0 Rte_Read_SWC_PartNumMgr_R_SSM_2_State_State_2_0
#  define Rte_Read_R_SSM_2_State_State_2_1 Rte_Read_SWC_PartNumMgr_R_SSM_2_State_State_2_1
#  define Rte_Read_R_SSM_QNXState_State_QNX Rte_Read_SWC_PartNumMgr_R_SSM_QNXState_State_QNX
#  define Rte_Read_R_SystemState_SystemState Rte_Read_SWC_PartNumMgr_R_SystemState_SystemState
#  define Rte_Read_RpUSSConstantData_US_S_USSConstantData_t Rte_Read_SWC_PartNumMgr_RpUSSConstantData_US_S_USSConstantData_t
#  define Rte_Read_RpUssMrrgData_US_S_MarriageSensorIDs_t Rte_Read_SWC_PartNumMgr_RpUssMrrgData_US_S_MarriageSensorIDs_t
#  define Rte_Read_RpVINData_VINCurrentData Rte_Read_SWC_PartNumMgr_RpVINData_VINCurrentData
#  define Rte_Read_RpVINData_VINLockStatus Rte_Read_SWC_PartNumMgr_RpVINData_VINLockStatus
#  define Rte_Read_SWC_PartNumMgr_RpVINData_VINLockStatus(data) (*(data) = Rte_SWC_RIDMgr_PpVINData_VINLockStatus, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpVINData_VINOdoCounter Rte_Read_SWC_PartNumMgr_RpVINData_VINOdoCounter
#  define Rte_Read_SWC_PartNumMgr_RpVINData_VINOdoCounter(data) (*(data) = Rte_SWC_RIDMgr_PpVINData_VINOdoCounter, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpVINData_VINOriginalData Rte_Read_SWC_PartNumMgr_RpVINData_VINOriginalData


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpFlashSts_v_FlashSts_u16 Rte_Write_SWC_PartNumMgr_PpFlashSts_v_FlashSts_u16
#  define Rte_Write_SWC_PartNumMgr_PpFlashSts_v_FlashSts_u16(data) (Rte_SWC_PartNumMgr_PpFlashSts_v_FlashSts_u16 = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_IPCHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CDD_IPCHANDLER_APPL_CODE) RE_IpcTxData(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CDD_IPCHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetDataIndex(NvM_BlockIdType parg0, uint8 DataIndex); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_DID_FD31_EOLCodingState_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)57, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DS_MetaData_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)12, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DS_MetaData_SetDataIndex(arg1) (NvM_SetDataIndex((NvM_BlockIdType)12, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_UssSensorMarrData_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)62, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_UssSensorMarrData_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)62, arg1))
#  define Rte_Call_RpIpcTxData_IPC_Write_v(arg1, arg2, arg3) (RE_IpcTxData(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))

/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(DID_F110_Pin_Arr, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F110_Ecu_Diag_Info_DefaultValue;
extern CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F132_EBOM_Ecu_PartNum_DefaultValue;
extern CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F133_EBOM_Asm_PartNum_DefaultValue;
extern CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F134_CODEP_Asm_PartNum_DefaultValue;
extern CONST(Dcm_Data13ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F180_Boot_SW_Ver_Info_DefaultValue;
extern CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F187_CODEP_Ecu_PartNum_DefaultValue;
extern CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F188_FCA_ESLM_Ecu_SW_Num_DefaultValue;
extern CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_DefaultValue;
extern CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F18B_FCA_ESLM_ECU_SW_App_Num_DefaultValue;
extern CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F194_Supplier_Ecu_SW_PartNum_DefaultValue;
extern CONST(Dcm_Data2ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F195_Supplier_Ecu_SW_VerNum_DefaultValue;
extern CONST(Dcm_Data4ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_DefaultValue;
extern CONST(US_S_MarriageSensorIDs_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_UssSensorMarrData_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_DID_F110_Ecu_Diag_Info_DefaultValue() (&(Rte_SWC_PartNumMgr_DID_F110_Ecu_Diag_Info_DefaultValue[0]))
#  else
#   define Rte_CData_DID_F110_Ecu_Diag_Info_DefaultValue() (&Rte_SWC_PartNumMgr_DID_F110_Ecu_Diag_Info_DefaultValue)
#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_DID_F132_EBOM_Ecu_PartNum_DefaultValue() (&(Rte_SWC_PartNumMgr_DID_F132_EBOM_Ecu_PartNum_DefaultValue[0]))
#  else
#   define Rte_CData_DID_F132_EBOM_Ecu_PartNum_DefaultValue() (&Rte_SWC_PartNumMgr_DID_F132_EBOM_Ecu_PartNum_DefaultValue)
#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_DID_F133_EBOM_Asm_PartNum_DefaultValue() (&(Rte_SWC_PartNumMgr_DID_F133_EBOM_Asm_PartNum_DefaultValue[0]))
#  else
#   define Rte_CData_DID_F133_EBOM_Asm_PartNum_DefaultValue() (&Rte_SWC_PartNumMgr_DID_F133_EBOM_Asm_PartNum_DefaultValue)
#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_DID_F134_CODEP_Asm_PartNum_DefaultValue() (&(Rte_SWC_PartNumMgr_DID_F134_CODEP_Asm_PartNum_DefaultValue[0]))
#  else
#   define Rte_CData_DID_F134_CODEP_Asm_PartNum_DefaultValue() (&Rte_SWC_PartNumMgr_DID_F134_CODEP_Asm_PartNum_DefaultValue)
#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_DID_F180_Boot_SW_Ver_Info_DefaultValue() (&(Rte_SWC_PartNumMgr_DID_F180_Boot_SW_Ver_Info_DefaultValue[0]))
#  else
#   define Rte_CData_DID_F180_Boot_SW_Ver_Info_DefaultValue() (&Rte_SWC_PartNumMgr_DID_F180_Boot_SW_Ver_Info_DefaultValue)
#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_DID_F187_CODEP_Ecu_PartNum_DefaultValue() (&(Rte_SWC_PartNumMgr_DID_F187_CODEP_Ecu_PartNum_DefaultValue[0]))
#  else
#   define Rte_CData_DID_F187_CODEP_Ecu_PartNum_DefaultValue() (&Rte_SWC_PartNumMgr_DID_F187_CODEP_Ecu_PartNum_DefaultValue)
#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_DID_F188_FCA_ESLM_Ecu_SW_Num_DefaultValue() (&(Rte_SWC_PartNumMgr_DID_F188_FCA_ESLM_Ecu_SW_Num_DefaultValue[0]))
#  else
#   define Rte_CData_DID_F188_FCA_ESLM_Ecu_SW_Num_DefaultValue() (&Rte_SWC_PartNumMgr_DID_F188_FCA_ESLM_Ecu_SW_Num_DefaultValue)
#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_DefaultValue() (&(Rte_SWC_PartNumMgr_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_DefaultValue[0]))
#  else
#   define Rte_CData_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_DefaultValue() (&Rte_SWC_PartNumMgr_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_DefaultValue)
#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_DID_F18B_FCA_ESLM_ECU_SW_App_Num_DefaultValue() (&(Rte_SWC_PartNumMgr_DID_F18B_FCA_ESLM_ECU_SW_App_Num_DefaultValue[0]))
#  else
#   define Rte_CData_DID_F18B_FCA_ESLM_ECU_SW_App_Num_DefaultValue() (&Rte_SWC_PartNumMgr_DID_F18B_FCA_ESLM_ECU_SW_App_Num_DefaultValue)
#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_DID_F194_Supplier_Ecu_SW_PartNum_DefaultValue() (&(Rte_SWC_PartNumMgr_DID_F194_Supplier_Ecu_SW_PartNum_DefaultValue[0]))
#  else
#   define Rte_CData_DID_F194_Supplier_Ecu_SW_PartNum_DefaultValue() (&Rte_SWC_PartNumMgr_DID_F194_Supplier_Ecu_SW_PartNum_DefaultValue)
#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_DID_F195_Supplier_Ecu_SW_VerNum_DefaultValue() (&(Rte_SWC_PartNumMgr_DID_F195_Supplier_Ecu_SW_VerNum_DefaultValue[0]))
#  else
#   define Rte_CData_DID_F195_Supplier_Ecu_SW_VerNum_DefaultValue() (&Rte_SWC_PartNumMgr_DID_F195_Supplier_Ecu_SW_VerNum_DefaultValue)
#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_DID_FD31_EOLCodingState_DefaultValue() (&(Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_DefaultValue[0]))
#  else
#   define Rte_CData_DID_FD31_EOLCodingState_DefaultValue() (&Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_DefaultValue)
#  endif

#  define Rte_CData_UssSensorMarrData_DefaultValue() (&Rte_SWC_PartNumMgr_UssSensorMarrData_DefaultValue)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(DID_F110_Pin_Arr, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F110_Ecu_Diag_Info_MirrorBlock;
extern VAR(Dcm_Data10ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F132_EBOM_Ecu_PartNum_MirrorBlock;
extern VAR(Dcm_Data10ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F133_EBOM_Asm_PartNum_MirrorBlock;
extern VAR(Dcm_Data11ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F134_CODEP_Asm_PartNum_MirrorBlock;
extern VAR(Dcm_Data13ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F180_Boot_SW_Ver_Info_MirrorBlock;
extern VAR(Dcm_Data11ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F187_CODEP_Ecu_PartNum_MirrorBlock;
extern VAR(Dcm_Data11ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F188_FCA_ESLM_Ecu_SW_Num_MirrorBlock;
extern VAR(Dcm_Data10ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_MirrorBlock;
extern VAR(Dcm_Data10ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F18B_FCA_ESLM_ECU_SW_App_Num_MirrorBlock;
extern VAR(Dcm_Data11ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F194_Supplier_Ecu_SW_PartNum_MirrorBlock;
extern VAR(Dcm_Data2ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F195_Supplier_Ecu_SW_VerNum_MirrorBlock;
extern VAR(Dcm_Data4ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_MirrorBlock;
extern VAR(US_S_MarriageSensorIDs_t, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_UssSensorMarrData_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_DID_F110_Ecu_Diag_Info_MirrorBlock() (&((*RtePim_DID_F110_Ecu_Diag_Info_MirrorBlock())[0]))
#  else
#   define Rte_Pim_DID_F110_Ecu_Diag_Info_MirrorBlock() RtePim_DID_F110_Ecu_Diag_Info_MirrorBlock()
#  endif
#  define RtePim_DID_F110_Ecu_Diag_Info_MirrorBlock() \
  (&Rte_SWC_PartNumMgr_DID_F110_Ecu_Diag_Info_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_DID_F132_EBOM_Ecu_PartNum_MirrorBlock() (&((*RtePim_DID_F132_EBOM_Ecu_PartNum_MirrorBlock())[0]))
#  else
#   define Rte_Pim_DID_F132_EBOM_Ecu_PartNum_MirrorBlock() RtePim_DID_F132_EBOM_Ecu_PartNum_MirrorBlock()
#  endif
#  define RtePim_DID_F132_EBOM_Ecu_PartNum_MirrorBlock() \
  (&Rte_SWC_PartNumMgr_DID_F132_EBOM_Ecu_PartNum_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_DID_F133_EBOM_Asm_PartNum_MirrorBlock() (&((*RtePim_DID_F133_EBOM_Asm_PartNum_MirrorBlock())[0]))
#  else
#   define Rte_Pim_DID_F133_EBOM_Asm_PartNum_MirrorBlock() RtePim_DID_F133_EBOM_Asm_PartNum_MirrorBlock()
#  endif
#  define RtePim_DID_F133_EBOM_Asm_PartNum_MirrorBlock() \
  (&Rte_SWC_PartNumMgr_DID_F133_EBOM_Asm_PartNum_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_DID_F134_CODEP_Asm_PartNum_MirrorBlock() (&((*RtePim_DID_F134_CODEP_Asm_PartNum_MirrorBlock())[0]))
#  else
#   define Rte_Pim_DID_F134_CODEP_Asm_PartNum_MirrorBlock() RtePim_DID_F134_CODEP_Asm_PartNum_MirrorBlock()
#  endif
#  define RtePim_DID_F134_CODEP_Asm_PartNum_MirrorBlock() \
  (&Rte_SWC_PartNumMgr_DID_F134_CODEP_Asm_PartNum_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_DID_F180_Boot_SW_Ver_Info_MirrorBlock() (&((*RtePim_DID_F180_Boot_SW_Ver_Info_MirrorBlock())[0]))
#  else
#   define Rte_Pim_DID_F180_Boot_SW_Ver_Info_MirrorBlock() RtePim_DID_F180_Boot_SW_Ver_Info_MirrorBlock()
#  endif
#  define RtePim_DID_F180_Boot_SW_Ver_Info_MirrorBlock() \
  (&Rte_SWC_PartNumMgr_DID_F180_Boot_SW_Ver_Info_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_DID_F187_CODEP_Ecu_PartNum_MirrorBlock() (&((*RtePim_DID_F187_CODEP_Ecu_PartNum_MirrorBlock())[0]))
#  else
#   define Rte_Pim_DID_F187_CODEP_Ecu_PartNum_MirrorBlock() RtePim_DID_F187_CODEP_Ecu_PartNum_MirrorBlock()
#  endif
#  define RtePim_DID_F187_CODEP_Ecu_PartNum_MirrorBlock() \
  (&Rte_SWC_PartNumMgr_DID_F187_CODEP_Ecu_PartNum_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_DID_F188_FCA_ESLM_Ecu_SW_Num_MirrorBlock() (&((*RtePim_DID_F188_FCA_ESLM_Ecu_SW_Num_MirrorBlock())[0]))
#  else
#   define Rte_Pim_DID_F188_FCA_ESLM_Ecu_SW_Num_MirrorBlock() RtePim_DID_F188_FCA_ESLM_Ecu_SW_Num_MirrorBlock()
#  endif
#  define RtePim_DID_F188_FCA_ESLM_Ecu_SW_Num_MirrorBlock() \
  (&Rte_SWC_PartNumMgr_DID_F188_FCA_ESLM_Ecu_SW_Num_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_MirrorBlock() (&((*RtePim_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_MirrorBlock())[0]))
#  else
#   define Rte_Pim_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_MirrorBlock() RtePim_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_MirrorBlock()
#  endif
#  define RtePim_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_MirrorBlock() \
  (&Rte_SWC_PartNumMgr_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_DID_F18B_FCA_ESLM_ECU_SW_App_Num_MirrorBlock() (&((*RtePim_DID_F18B_FCA_ESLM_ECU_SW_App_Num_MirrorBlock())[0]))
#  else
#   define Rte_Pim_DID_F18B_FCA_ESLM_ECU_SW_App_Num_MirrorBlock() RtePim_DID_F18B_FCA_ESLM_ECU_SW_App_Num_MirrorBlock()
#  endif
#  define RtePim_DID_F18B_FCA_ESLM_ECU_SW_App_Num_MirrorBlock() \
  (&Rte_SWC_PartNumMgr_DID_F18B_FCA_ESLM_ECU_SW_App_Num_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_DID_F194_Supplier_Ecu_SW_PartNum_MirrorBlock() (&((*RtePim_DID_F194_Supplier_Ecu_SW_PartNum_MirrorBlock())[0]))
#  else
#   define Rte_Pim_DID_F194_Supplier_Ecu_SW_PartNum_MirrorBlock() RtePim_DID_F194_Supplier_Ecu_SW_PartNum_MirrorBlock()
#  endif
#  define RtePim_DID_F194_Supplier_Ecu_SW_PartNum_MirrorBlock() \
  (&Rte_SWC_PartNumMgr_DID_F194_Supplier_Ecu_SW_PartNum_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_DID_F195_Supplier_Ecu_SW_VerNum_MirrorBlock() (&((*RtePim_DID_F195_Supplier_Ecu_SW_VerNum_MirrorBlock())[0]))
#  else
#   define Rte_Pim_DID_F195_Supplier_Ecu_SW_VerNum_MirrorBlock() RtePim_DID_F195_Supplier_Ecu_SW_VerNum_MirrorBlock()
#  endif
#  define RtePim_DID_F195_Supplier_Ecu_SW_VerNum_MirrorBlock() \
  (&Rte_SWC_PartNumMgr_DID_F195_Supplier_Ecu_SW_VerNum_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_DID_FD31_EOLCodingState_MirrorBlock() (&((*RtePim_DID_FD31_EOLCodingState_MirrorBlock())[0]))
#  else
#   define Rte_Pim_DID_FD31_EOLCodingState_MirrorBlock() RtePim_DID_FD31_EOLCodingState_MirrorBlock()
#  endif
#  define RtePim_DID_FD31_EOLCodingState_MirrorBlock() \
  (&Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_UssSensorMarrData_MirrorBlock() \
  (&Rte_SWC_PartNumMgr_UssSensorMarrData_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define SWC_PartNumMgr_START_SEC_CODE
# include "SWC_PartNumMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_ReadData DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_ReadData DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_ReadData DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F10D_Diagnostic_Specification_Information_ReadData DataServices_Data_22F10D_Diagnostic_Specification_Information_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F110_ECU_Diagnostic_Identification_ReadData DataServices_Data_22F110_ECU_Diagnostic_Identification_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F112_PTESLM_Hardware_Number_ReadData DataServices_Data_22F112_PTESLM_Hardware_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F122_Software_EBOM_Part_Number_ReadData DataServices_Data_22F122_Software_EBOM_Part_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F132_EBOM_ECU_Part_Number_ReadData DataServices_Data_22F132_EBOM_ECU_Part_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F133_EBOM_Assembly_Part_Number_ReadData DataServices_Data_22F133_EBOM_Assembly_Part_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F134_CODEP_assembly_part_number_ReadData DataServices_Data_22F134_CODEP_assembly_part_number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F154_Hardware_Supplier_Identification_ReadData DataServices_Data_22F154_Hardware_Supplier_Identification_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F155_Software_Supplier_Identification_ReadData DataServices_Data_22F155_Software_Supplier_Identification_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F180_Boot_Software_Version_Information_ReadData DataServices_Data_22F180_Boot_Software_Version_Information_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F181_Application_Software_Identification_ReadData DataServices_Data_22F181_Application_Software_Identification_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F182_Application_Data_Identification_ReadData DataServices_Data_22F182_Application_Data_Identification_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F187_CODEP_ECU_Part_Number_ReadData DataServices_Data_22F187_CODEP_ECU_Part_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_ReadData DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_ReadData DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_ReadData DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F18C_ECU_Serial_Number_ReadData DataServices_Data_22F18C_ECU_Serial_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_ReadData DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_ReadData DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_ReadData DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_ReadData DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_ReadData DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F1A0_System_Identification_Data_ReadData DataServices_Data_22F1A0_System_Identification_Data_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F1A2_Vector_Delivery_ID_ReadData DataServices_Data_22F1A2_Vector_Delivery_ID_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_ReadData DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_ReadData DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_ReadData DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD13_Magna_Software_Version_ReadData DataServices_Data_22FD13_Magna_Software_Version_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_ReadData DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD15_Magna_Production_HW_Number_Read_ReadData DataServices_Data_22FD15_Magna_Production_HW_Number_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_ReadData DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_ReadData DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD1D_PCB_Serial_Number_ReadData DataServices_Data_22FD1D_PCB_Serial_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_ReadData DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_WriteData DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_WriteData
#  define RTE_RUNNABLE_DataServices_Data_22FD38_Programmed_Assembly_ReadData DataServices_Data_22FD38_Programmed_Assembly_ReadData
#  define RTE_RUNNABLE_RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_MetaData_JobFinished RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_MetaData_JobFinished
#  define RTE_RUNNABLE_RE_PartNumMgr_Init RE_PartNumMgr_Init
#  define RTE_RUNNABLE_RE_PartNumMgr_Main RE_PartNumMgr_Main
# endif

# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data20ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F10D_Diagnostic_Specification_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F10D_Diagnostic_Specification_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F110_ECU_Diagnostic_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F110_ECU_Diagnostic_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F112_PTESLM_Hardware_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F112_PTESLM_Hardware_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F122_Software_EBOM_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F122_Software_EBOM_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data90ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F132_EBOM_ECU_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F132_EBOM_ECU_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F133_EBOM_Assembly_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F133_EBOM_Assembly_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F134_CODEP_assembly_part_number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F134_CODEP_assembly_part_number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data11ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F154_Hardware_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F154_Hardware_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F155_Software_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F155_Software_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F180_Boot_Software_Version_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F180_Boot_Software_Version_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F181_Application_Software_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F181_Application_Software_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data66ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F182_Application_Data_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F182_Application_Data_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data40ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F187_CODEP_ECU_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F187_CODEP_ECU_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data11ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data11ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F18C_ECU_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F18C_ECU_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data11ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data11ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data11ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F1A0_System_Identification_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F1A0_System_Identification_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data90ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F1A2_Vector_Delivery_ID_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F1A2_Vector_Delivery_ID_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data71ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data43ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD13_Magna_Software_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD13_Magna_Software_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data5ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD15_Magna_Production_HW_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD15_Magna_Production_HW_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data64ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD1D_PCB_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD1D_PCB_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_WriteData(P2CONST(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD38_Programmed_Assembly_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD38_Programmed_Assembly_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data16ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, SWC_PartNumMgr_CODE) RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_MetaData_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SWC_PartNumMgr_CODE) RE_PartNumMgr_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PartNumMgr_CODE) RE_PartNumMgr_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PartNumMgr_STOP_SEC_CODE
# include "SWC_PartNumMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F10D_Diagnostic_Specification_Information_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F10D_Diagnostic_Specification_Information_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F110_ECU_Diagnostic_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F110_ECU_Diagnostic_Identification_E_NOT_OK (1U)

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

#  define RTE_E_DataServices_Data_22F1A2_Vector_Delivery_ID_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F1A2_Vector_Delivery_ID_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_E_NOT_OK (1U)

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

#  define RTE_E_DataServices_Data_22FD1D_PCB_Serial_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD1D_PCB_Serial_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD38_Programmed_Assembly_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD38_Programmed_Assembly_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC2_SRBS_DS_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PARTNUMMGR_H */

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
