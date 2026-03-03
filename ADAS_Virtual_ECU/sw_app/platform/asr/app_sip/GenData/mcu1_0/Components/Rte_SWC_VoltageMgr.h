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
 *             File:  Rte_SWC_VoltageMgr.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <SWC_VoltageMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_VOLTAGEMGR_H
# define RTE_SWC_VOLTAGEMGR_H

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

# include "Rte_SWC_VoltageMgr_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_VoltageMgr_PpTemperatureVal_GetTemperatureVal;
extern VAR(udtBatteryVoltageStatus, RTE_VAR_INIT) Rte_SWC_VoltageMgr_PpVoltageChannelStatus_BatteryVoltageStatus;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PpTemperatureVal_GetTemperatureVal (0U)
#  define Rte_InitValue_PpVoltageChannelStatus_BatteryVoltageStatus (0U)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_VoltageMgr_R_DtcData_B_Data_DtcAddData_B(P2VAR(DtcAddData_B, AUTOMATIC, RTE_SWC_VOLTAGEMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_VoltageMgr_R_DtcData_B_Data_DtcStatus_B(P2VAR(DtcStatus_B, AUTOMATIC, RTE_SWC_VOLTAGEMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_VoltageMgr_RpCAMSelInfo_CAM_select_info_t(P2VAR(CAM_select_info_t, AUTOMATIC, RTE_SWC_VOLTAGEMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_VoltageMgr_PpUssPowerData_UssPower(P2CONST(UssPowerSense, AUTOMATIC, RTE_SWC_VOLTAGEMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_DtcData_B_Data_DtcAddData_B Rte_Read_SWC_VoltageMgr_R_DtcData_B_Data_DtcAddData_B
#  define Rte_Read_R_DtcData_B_Data_DtcStatus_B Rte_Read_SWC_VoltageMgr_R_DtcData_B_Data_DtcStatus_B
#  define Rte_Read_RpCAMSelInfo_CAM_select_info_t Rte_Read_SWC_VoltageMgr_RpCAMSelInfo_CAM_select_info_t
#  define Rte_Read_RpProxiToSWC_SurroundViewCam_u8 Rte_Read_SWC_VoltageMgr_RpProxiToSWC_SurroundViewCam_u8
#  define Rte_Read_SWC_VoltageMgr_RpProxiToSWC_SurroundViewCam_u8(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpTemperatureVal_GetTemperatureVal Rte_Write_SWC_VoltageMgr_PpTemperatureVal_GetTemperatureVal
#  define Rte_Write_SWC_VoltageMgr_PpTemperatureVal_GetTemperatureVal(data) (Rte_SWC_VoltageMgr_PpTemperatureVal_GetTemperatureVal = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpUssPowerData_UssPower Rte_Write_SWC_VoltageMgr_PpUssPowerData_UssPower
#  define Rte_Write_PpVoltageChannelStatus_BatteryVoltageStatus Rte_Write_SWC_VoltageMgr_PpVoltageChannelStatus_BatteryVoltageStatus
#  define Rte_Write_SWC_VoltageMgr_PpVoltageChannelStatus_BatteryVoltageStatus(data) (Rte_SWC_VoltageMgr_PpVoltageChannelStatus_BatteryVoltageStatus = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_IPCHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CDD_IPCHANDLER_APPL_CODE) RE_IpcTxData(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CDD_IPCHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_ERRORMGRSAT_1_0_B_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_ERRORMGRSAT_1_0_B_APPL_CODE) RE_ReportErrorStatus1_0_B(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, P2CONST(ErrorMgr_stAddData, AUTOMATIC, RTE_VAR_NOINIT) addData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ERRORMGRSAT_1_0_B_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_PpIoHwAbAdc_GetRawValues(IOHWAB_UINT8 Channelndex, P2VAR(IOHWAB_UINT16, AUTOMATIC, RTE_VAR_NOINIT) ChannelRawValue); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_PpUSSDselPin_GetUSSDselPinStatus(IOHWAB_BOOL USSDselPinStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B RE_ReportErrorStatus1_0_B
#  define Rte_Call_RpIoHwAbADCData_GetRawValues IoHwAb_PpIoHwAbAdc_GetRawValues
#  define Rte_Call_RpIoHwAbUSSDselPin_GetUSSDselPinStatus IoHwAb_PpUSSDselPin_GetUSSDselPinStatus
#  define Rte_Call_RpIpcTxData_IPC_Write_v(arg1, arg2, arg3) (RE_IpcTxData(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define SWC_VoltageMgr_START_SEC_CODE
# include "SWC_VoltageMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RE_VoltageMgr_EtGetADCVoltageInfo RE_VoltageMgr_EtGetADCVoltageInfo
#  define RTE_RUNNABLE_RE_VoltageMgr_Init RE_VoltageMgr_Init
#  define RTE_RUNNABLE_RE_VoltageMgr_Main RE_VoltageMgr_Main
# endif

FUNC(void, SWC_VoltageMgr_CODE) RE_VoltageMgr_EtGetADCVoltageInfo(VoltMgr_Enum_VoltageMON Channel_ID, P2VAR(float32, AUTOMATIC, RTE_VAR_NOINIT) Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SWC_VoltageMgr_CODE) RE_VoltageMgr_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_VoltageMgr_CODE) RE_VoltageMgr_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_VoltageMgr_STOP_SEC_CODE
# include "SWC_VoltageMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_IF_IoHwAbADCData_IoHwAbApplicationError (1U)

#  define RTE_E_IF_IoHwAbUSSDselPin_IoHwAbApplicationError (1U)

#  define RTE_E_P_Error_CS_E_NOK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_VOLTAGEMGR_H */

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
