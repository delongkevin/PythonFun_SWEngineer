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
 *             File:  Rte_CDD_IPCHandler.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <CDD_IPCHandler>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CDD_IPCHANDLER_H
# define RTE_CDD_IPCHANDLER_H

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

# include "Rte_CDD_IPCHandler_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(CanDebugMode_t, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpCan14DbgRoutineState_Can14DbgRoutine;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpPAM2BTIpcTxStatus_IpcTxDone;
extern VAR(CmdIgnSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PpDrverSecuBltAlrmSts_TeVBII_e_DrverSecuBltAlrmSts (0U)
#  define Rte_InitValue_PpPAM2BTIpcTxStatus_IpcTxDone (FALSE)
#  define Rte_InitValue_RpCan14DbgRoutineState_Can14DbgRoutine (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_APARequestSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_Active_Park_Mode (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_Active_Park_Prox_Chime (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_Backup_Cam_Delay (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_Brk_Stat (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_CmdIgnSts (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_DriverDoorSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_DynamicGrid (TRUE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_ExternalTemperature (170U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_FT_PAMRequestSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_GearEngaged (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_HAS_Status_C2 (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_LHRDoorSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_LanguageSelection (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_LatAcceleration_BSM (4095U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_LongAcceleration_BSM (4095U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_LwsAngle (7200U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_LwsAngleType (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_LwsSpeed (2000U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_MRM_STATUS_C2 (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_PAMRequestSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_PamChimeVolumeFront (1U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_PamChimeVolumeRear (1U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_PsngrDoorSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_RHRDoorSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_RHatchSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_Rear_Brk_Asst (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_SVC_Guidelines (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_ShiftLeverPosition (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_TCASERANGESTATUS (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_TRANS_ADAS_Inhibit (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_TargetGear (15U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_TrailerConnectionSts (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_TransmissionSailingSts (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_VehicleSpeedVSOSig (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_YawRate_BSM (4095U)
# endif


# define RTE_START_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpAPSMPAOut_TbAP_APSMPAOut_t(P2VAR(TbAP_APSMPAOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(P2VAR(IFOD_Outputs_CVPAMFDData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(P2VAR(LMD_Outputs_CVPAMFDData2_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDebCurReqOverlay_Debug_HMI_Curr_Requested_Overlays(P2VAR(Debug_HMI_Curr_Requested_Overlays, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDebCurrDispOverlay_Debug_HMI_Curr_Displayed_Overlays(P2VAR(Debug_HMI_Curr_Displayed_Overlays, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDebCurrDispProxiCfg_Debug_HMI_Curr_Displayed_ProxiConfig(P2VAR(Debug_HMI_Curr_Displayed_ProxiConfig, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDebCurrReqProxiCfg_Debug_HMI_Curr_Requested_ProxiConfig(P2VAR(Debug_HMI_Curr_Requested_ProxiConfig, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDebHmiInput_Debug_HMI_Input_Data_t(P2VAR(Debug_HMI_Input_Data_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDebHmiInternal_Debug_HMI_Internal_Data_t(P2VAR(Debug_HMI_Internal_Data_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDebHmiTrailViews_Debug_HMI_Trailer_Views_Data_t(P2VAR(Debug_HMI_Trailer_Views_Data_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDetInpTrsc_Detection_Inputs_from_TRSC_t(P2VAR(Detection_Inputs_from_TRSC_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(P2VAR(TbAP_DriveAssistStatOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpFPAWarnOut_TbAP_FPAWarnOut_t(P2VAR(TbAP_FPAWarnOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(P2VAR(TbTHASmVc_FeatureOutputs_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpIDebugFODObject_IDebug_FODObject_t(P2VAR(IDebug_FODObject_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpIFODOpArbitration_IFOD_Outputs_Arbitration_t(P2VAR(IFOD_Outputs_Arbitration_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpIJobUSSObjOp_IJobUSSObjectMapOutput_t(P2VAR(IJobUSSObjectMapOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpJobFPAData_IJobFPAOutput_t(P2VAR(IJobFPAOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpJobPLDData_IJobPLDOutput_t(P2VAR(IJobPLDOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpJobTHADetOutput_JobTHADetOutput_t(P2VAR(JobTHADetOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpLMDLaneOp_LMD_Lane_Outputs_s(P2VAR(LMD_Lane_Outputs_s, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(P2VAR(ME_Proxi_MPU1_0_to_MCU1_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpNFCDOutput_NFCD_Output(P2VAR(NFCD_Output, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpNVMSignMgr_NVMSignalManager_t(P2VAR(NVMSignalManager_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpPAStateOut_TbAP_PAStateOut_t(P2VAR(TbAP_PAStateOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpPointDistOpBuff_US_S_PointDistOutputBuff_t(P2VAR(US_S_PointDistOutputBuff_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpRPAWarnOut_TbAP_RPAWarnOut_t(P2VAR(TbAP_RPAWarnOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpSMDAInternal_TbAP_SMDAInternalOut_t(P2VAR(TbAP_SMDAInternalOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpSR_State_MCU2_State_2_0(P2VAR(SSM_2_0_CoreStatus, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpSR_State_MCU2_State_2_1(P2VAR(SSM_2_1_CoreStatus, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpSVSNVMData_SVS_NVMData_t(P2VAR(SVS_NVMData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpSVStoTRSC_SVStoTRSC_t(P2VAR(SVStoTRSC_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpScreenRequest_ScreenRequest_t(P2VAR(ScreenRequest_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpSvsToTHA_SvsToTHA_t(P2VAR(SvsToTHA_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpSvsToVCAN_SvsToVCAN_t(P2VAR(SvsToVCAN_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTRSC_ME_VehOut_TRSC_t(P2VAR(ME_VehOut_TRSC_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTbAPDebugOut_TbAP_DebugOut(P2VAR(TbAP_DebugOut, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTbAPSMPAOut_TbAP_SMPAInternalOut_t(P2VAR(TbAP_SMPAInternalOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTbFAArbiterOutput_TbFA_ArbiterOutput_t(P2VAR(TbFA_ArbiterOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTbFAResetKM_TbFA_ResetKM_t(P2VAR(TbFA_ResetKM_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTrailerDetectOP_TrailerDetection_Output_DID_t(P2VAR(TrailerDetection_Output_DID_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTrscSmvctoSvs_TRSCSMVCtoSVS_t(P2VAR(TRSCSMVCtoSVS_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTrscToDiag_TRSCtoDiagMgr_t(P2VAR(TRSCtoDiagMgr_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t(P2VAR(TRSC_Inputs_from_TrailerDetection_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpUSSBlockageBit_US_S_BlockageBit_t(P2VAR(US_S_BlockageBit_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpUSSErrorDiagData_US_S_USSErrorDiagData_t(P2VAR(US_S_USSErrorDiagData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpUssDataCollection_US_S_USSDataCollectionData_t(P2VAR(US_S_USSDataCollectionData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpUssPointMapGrp_US_S_PointMapGroup_t(P2VAR(US_S_PointMapGroup_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpUssZoneInfo_US_S_ZoneInfo_t(P2VAR(US_S_ZoneInfo_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpVCActuatorOut_TbAP_VCActuatorOut_t(P2VAR(TbAP_VCActuatorOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpVCState_TbAP_VCStateOut_t(P2VAR(TbAP_VCStateOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpAPSMPAOut_TbAP_APSMPAOut_t(P2CONST(TbAP_APSMPAOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCAMSelInfo_CAM_select_info_t(P2CONST(CAM_select_info_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(P2CONST(IFOD_Outputs_CVPAMFDData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(P2CONST(LMD_Outputs_CVPAMFDData2_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCamCsData_CAM_CS_Curr_Monitor_t(P2CONST(CAM_CS_Curr_Monitor_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCamEepromData_Svs_CamEepromDataArray_t(P2CONST(Svs_CamEepromDataArray_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCamSerENStat_Cam_and_Ser_EN_Status_t(P2CONST(Cam_and_Ser_EN_Status_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t(P2CONST(CpuLoadMcu2_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t(P2CONST(CpuLoadMcu2_1_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDLDOutput_JobDLDOutput_t(P2CONST(JobDLDOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDebCurReqOverlay_Debug_HMI_Curr_Requested_Overlays(P2CONST(Debug_HMI_Curr_Requested_Overlays, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDebCurrDispOverlay_Debug_HMI_Curr_Displayed_Overlays(P2CONST(Debug_HMI_Curr_Displayed_Overlays, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDebCurrDispProxiCfg_Debug_HMI_Curr_Displayed_ProxiConfig(P2CONST(Debug_HMI_Curr_Displayed_ProxiConfig, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDebCurrReqProxiCfg_Debug_HMI_Curr_Requested_ProxiConfig(P2CONST(Debug_HMI_Curr_Requested_ProxiConfig, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDebHmiInput_Debug_HMI_Input_Data_t(P2CONST(Debug_HMI_Input_Data_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDebHmiInternal_Debug_HMI_Internal_Data_t(P2CONST(Debug_HMI_Internal_Data_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDebHmiTrailViews_Debug_HMI_Trailer_Views_Data_t(P2CONST(Debug_HMI_Trailer_Views_Data_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDetInpTrsc_Detection_Inputs_from_TRSC_t(P2CONST(Detection_Inputs_from_TRSC_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(P2CONST(TbAP_DriveAssistStatOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpErrFltMcu2_0_Error_Fault_MCU2_0_t(P2CONST(Error_Fault_MCU2_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpErrFltMcu2_1_Error_Fault_MCU2_1_t(P2CONST(Error_Fault_MCU2_1_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpErrFltMpu1_0_Error_Fault_MPU1_0_t(P2CONST(Error_Fault_MPU1_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpFPAWarnOut_TbAP_FPAWarnOut_t(P2CONST(TbAP_FPAWarnOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(P2CONST(TbTHASmVc_FeatureOutputs_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpIDebugFODObject_IDebug_FODObject_t(P2CONST(IDebug_FODObject_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t(P2CONST(IFOD_Outputs_Arbitration_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t(P2CONST(IJobUSSObjectMapOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpJobFPAData_IJobFPAOutput_t(P2CONST(IJobFPAOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpJobPLDData_IJobPLDOutput_t(P2CONST(IJobPLDOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpJobTHADetOutput_JobTHADetOutput_t(P2CONST(JobTHADetOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpKeepAliveResponse_KeepAliveResponse_t(P2CONST(KeepAliveResponse_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpLMDLaneOp_LMD_Lane_Outputs_s(P2CONST(LMD_Lane_Outputs_s, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(P2CONST(ME_Proxi_MPU1_0_to_MCU1_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpNFCDOutput_NFCD_Output(P2CONST(NFCD_Output, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpNVMCamCalibSM_TbSVS_e_SVSOutputToNVMCamCalibSM_t(P2CONST(TbSVS_e_SVSOutputToNVMCamCalibSM_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpNVMSignMgr_NVMSignalManager_t(P2CONST(NVMSignalManager_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpPAStateOut_TbAP_PAStateOut_t(P2CONST(TbAP_PAStateOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpPointDistOpBuff_US_S_PointDistOutputBuff_t(P2CONST(US_S_PointDistOutputBuff_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpRPAWarnOut_TbAP_RPAWarnOut_t(P2CONST(TbAP_RPAWarnOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t(P2CONST(RunTimeStats_MCU2_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t(P2CONST(RunTimeStats_MCU2_1_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t(P2CONST(RunTimeStats_MPU1_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSMDAInternal_TbAP_SMDAInternalOut_t(P2CONST(TbAP_SMDAInternalOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSR_State_MCU2_State_2_0(P2CONST(SSM_2_0_CoreStatus, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSR_State_MCU2_State_2_1(P2CONST(SSM_2_1_CoreStatus, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSR_State_QNX_State_QNX(P2CONST(SSM_QNX_CoreStatus, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t(P2CONST(TbSVS_S_SVSCamCurrentCalibDataToNVM_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t(P2CONST(TbSVS_S_SVSCamEOLCalibDataToNVM_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t(P2CONST(TbSVS_S_SVSCamOCCalibDataToNVM_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t(P2CONST(TbSVS_S_SVSCamSCCalibDataToNVM_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVSNVMData_SVS_NVMData_t(P2CONST(SVS_NVMData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t(P2CONST(TbSVS_e_SVSOutputToDiagMgrCamCalib_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVSToDiag_SVSToDiag_t(P2CONST(SVSToDiag_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVStoTRSC_SVStoTRSC_t(P2CONST(SVStoTRSC_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_1_0_B(P2CONST(ErrorMgr_ErrorCommPack_1_0_B, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B(P2CONST(ErrorMgr_ErrorCommPack_2_0_B, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B(P2CONST(ErrorMgr_ErrorCommPack_2_1_B, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B(P2CONST(ErrorMgr_ErrorCommPack_QNX_B, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_1_0_QM(P2CONST(ErrorMgr_ErrorCommPack_1_0_QM, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM(P2CONST(ErrorMgr_ErrorCommPack_2_0_QM, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM(P2CONST(ErrorMgr_ErrorCommPack_2_1_QM, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM(P2CONST(ErrorMgr_ErrorCommPack_QNX_QM, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpScreenRequest_ScreenRequest_t(P2CONST(ScreenRequest_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSnrDirEcho_US_S_SnrDirEcho_t(P2CONST(US_S_SnrDirEcho_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t(P2CONST(StackUsage_MCU2_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t(P2CONST(StackUsage_MCU2_1_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSvsToTHA_SvsToTHA_t(P2CONST(SvsToTHA_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSvsToVCAN_SvsToVCAN_t(P2CONST(SvsToVCAN_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTRSC_ME_VehOut_TRSC_t(P2CONST(ME_VehOut_TRSC_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t(P2CONST(TRSCSMVCtoDebugCAN_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTbAPDebugOut_TbAP_DebugOut(P2CONST(TbAP_DebugOut, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t(P2CONST(TbAP_SMPAInternalOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t(P2CONST(TbFA_ArbiterOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTbFAResetKM_TbFA_ResetKM_t(P2CONST(TbFA_ResetKM_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t(P2CONST(TbTHASmVc_DiagMgr_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTrailerDetectOP_TrailerDetection_Output_DID_t(P2CONST(TrailerDetection_Output_DID_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t(P2CONST(TRSCSMVCtoSVS_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTrscToDiag_TRSCtoDiagMgr_t(P2CONST(TRSCtoDiagMgr_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t(P2CONST(TRSC_Inputs_from_TrailerDetection_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUSSBlockageBit_US_S_BlockageBit_t(P2CONST(US_S_BlockageBit_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUSSConstantData_US_S_USSConstantData_t(P2CONST(US_S_USSConstantData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUSSErrorDiagData_US_S_USSErrorDiagData_t(P2CONST(US_S_USSErrorDiagData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t(P2CONST(US_S_USSPeriodDiagData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type(P2CONST(US_S_CsmStateChangeReason_Type, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUssDataCollection_US_S_USSDataCollectionData_t(P2CONST(US_S_USSDataCollectionData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUssDebugMsg_US_S_DebugMsg_t(P2CONST(US_S_DebugMsg_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUssMrrgData_US_S_MarriageSensorIDs_t(P2CONST(US_S_MarriageSensorIDs_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUssPointMapGrp_US_S_PointMapGroup_t(P2CONST(US_S_PointMapGroup_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUssTunData_UssTunningData_mcu2_1_t(P2CONST(UssTunningData_mcu2_1_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUssZoneInfo_US_S_ZoneInfo_t(P2CONST(US_S_ZoneInfo_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpVCActuatorOut_TbAP_VCActuatorOut_t(P2CONST(TbAP_VCActuatorOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpVCState_TbAP_VCStateOut_t(P2CONST(TbAP_VCStateOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t(P2CONST(WdgCheckpointStatus_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t(P2CONST(WdgCheckpointStatus_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t(P2CONST(WdgCheckpointStatus_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_RpAPSMPAOut_TbAP_APSMPAOut_t Rte_Read_CDD_IPCHandler_RpAPSMPAOut_TbAP_APSMPAOut_t
#  define Rte_Read_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t Rte_Read_CDD_IPCHandler_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t
#  define Rte_Read_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t Rte_Read_CDD_IPCHandler_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t
#  define Rte_Read_RpCan14DbgRoutineState_Can14DbgRoutine Rte_Read_CDD_IPCHandler_RpCan14DbgRoutineState_Can14DbgRoutine
#  define Rte_Read_CDD_IPCHandler_RpCan14DbgRoutineState_Can14DbgRoutine(data) (*(data) = Rte_SWC_RIDMgr_PpCan14DbgRoutineState_Can14DbgRoutine, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpDebCurReqOverlay_Debug_HMI_Curr_Requested_Overlays Rte_Read_CDD_IPCHandler_RpDebCurReqOverlay_Debug_HMI_Curr_Requested_Overlays
#  define Rte_Read_RpDebCurrDispOverlay_Debug_HMI_Curr_Displayed_Overlays Rte_Read_CDD_IPCHandler_RpDebCurrDispOverlay_Debug_HMI_Curr_Displayed_Overlays
#  define Rte_Read_RpDebCurrDispProxiCfg_Debug_HMI_Curr_Displayed_ProxiConfig Rte_Read_CDD_IPCHandler_RpDebCurrDispProxiCfg_Debug_HMI_Curr_Displayed_ProxiConfig
#  define Rte_Read_RpDebCurrReqProxiCfg_Debug_HMI_Curr_Requested_ProxiConfig Rte_Read_CDD_IPCHandler_RpDebCurrReqProxiCfg_Debug_HMI_Curr_Requested_ProxiConfig
#  define Rte_Read_RpDebHmiInput_Debug_HMI_Input_Data_t Rte_Read_CDD_IPCHandler_RpDebHmiInput_Debug_HMI_Input_Data_t
#  define Rte_Read_RpDebHmiInternal_Debug_HMI_Internal_Data_t Rte_Read_CDD_IPCHandler_RpDebHmiInternal_Debug_HMI_Internal_Data_t
#  define Rte_Read_RpDebHmiTrailViews_Debug_HMI_Trailer_Views_Data_t Rte_Read_CDD_IPCHandler_RpDebHmiTrailViews_Debug_HMI_Trailer_Views_Data_t
#  define Rte_Read_RpDetInpTrsc_Detection_Inputs_from_TRSC_t Rte_Read_CDD_IPCHandler_RpDetInpTrsc_Detection_Inputs_from_TRSC_t
#  define Rte_Read_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t Rte_Read_CDD_IPCHandler_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t
#  define Rte_Read_RpFPAWarnOut_TbAP_FPAWarnOut_t Rte_Read_CDD_IPCHandler_RpFPAWarnOut_TbAP_FPAWarnOut_t
#  define Rte_Read_RpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t Rte_Read_CDD_IPCHandler_RpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t
#  define Rte_Read_RpIDebugFODObject_IDebug_FODObject_t Rte_Read_CDD_IPCHandler_RpIDebugFODObject_IDebug_FODObject_t
#  define Rte_Read_RpIFODOpArbitration_IFOD_Outputs_Arbitration_t Rte_Read_CDD_IPCHandler_RpIFODOpArbitration_IFOD_Outputs_Arbitration_t
#  define Rte_Read_RpIJobUSSObjOp_IJobUSSObjectMapOutput_t Rte_Read_CDD_IPCHandler_RpIJobUSSObjOp_IJobUSSObjectMapOutput_t
#  define Rte_Read_RpJobFPAData_IJobFPAOutput_t Rte_Read_CDD_IPCHandler_RpJobFPAData_IJobFPAOutput_t
#  define Rte_Read_RpJobPLDData_IJobPLDOutput_t Rte_Read_CDD_IPCHandler_RpJobPLDData_IJobPLDOutput_t
#  define Rte_Read_RpJobTHADetOutput_JobTHADetOutput_t Rte_Read_CDD_IPCHandler_RpJobTHADetOutput_JobTHADetOutput_t
#  define Rte_Read_RpLMDLaneOp_LMD_Lane_Outputs_s Rte_Read_CDD_IPCHandler_RpLMDLaneOp_LMD_Lane_Outputs_s
#  define Rte_Read_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t Rte_Read_CDD_IPCHandler_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t
#  define Rte_Read_RpNFCDOutput_NFCD_Output Rte_Read_CDD_IPCHandler_RpNFCDOutput_NFCD_Output
#  define Rte_Read_RpNVMSignMgr_NVMSignalManager_t Rte_Read_CDD_IPCHandler_RpNVMSignMgr_NVMSignalManager_t
#  define Rte_Read_RpPAStateOut_TbAP_PAStateOut_t Rte_Read_CDD_IPCHandler_RpPAStateOut_TbAP_PAStateOut_t
#  define Rte_Read_RpPointDistOpBuff_US_S_PointDistOutputBuff_t Rte_Read_CDD_IPCHandler_RpPointDistOpBuff_US_S_PointDistOutputBuff_t
#  define Rte_Read_RpRPAWarnOut_TbAP_RPAWarnOut_t Rte_Read_CDD_IPCHandler_RpRPAWarnOut_TbAP_RPAWarnOut_t
#  define Rte_Read_RpSMDAInternal_TbAP_SMDAInternalOut_t Rte_Read_CDD_IPCHandler_RpSMDAInternal_TbAP_SMDAInternalOut_t
#  define Rte_Read_RpSR_State_MCU2_State_2_0 Rte_Read_CDD_IPCHandler_RpSR_State_MCU2_State_2_0
#  define Rte_Read_RpSR_State_MCU2_State_2_1 Rte_Read_CDD_IPCHandler_RpSR_State_MCU2_State_2_1
#  define Rte_Read_RpSVSNVMData_SVS_NVMData_t Rte_Read_CDD_IPCHandler_RpSVSNVMData_SVS_NVMData_t
#  define Rte_Read_RpSVStoTRSC_SVStoTRSC_t Rte_Read_CDD_IPCHandler_RpSVStoTRSC_SVStoTRSC_t
#  define Rte_Read_RpScreenRequest_ScreenRequest_t Rte_Read_CDD_IPCHandler_RpScreenRequest_ScreenRequest_t
#  define Rte_Read_RpSvsToTHA_SvsToTHA_t Rte_Read_CDD_IPCHandler_RpSvsToTHA_SvsToTHA_t
#  define Rte_Read_RpSvsToVCAN_SvsToVCAN_t Rte_Read_CDD_IPCHandler_RpSvsToVCAN_SvsToVCAN_t
#  define Rte_Read_RpTRSC_ME_VehOut_TRSC_t Rte_Read_CDD_IPCHandler_RpTRSC_ME_VehOut_TRSC_t
#  define Rte_Read_RpTbAPDebugOut_TbAP_DebugOut Rte_Read_CDD_IPCHandler_RpTbAPDebugOut_TbAP_DebugOut
#  define Rte_Read_RpTbAPSMPAOut_TbAP_SMPAInternalOut_t Rte_Read_CDD_IPCHandler_RpTbAPSMPAOut_TbAP_SMPAInternalOut_t
#  define Rte_Read_RpTbFAArbiterOutput_TbFA_ArbiterOutput_t Rte_Read_CDD_IPCHandler_RpTbFAArbiterOutput_TbFA_ArbiterOutput_t
#  define Rte_Read_RpTbFAResetKM_TbFA_ResetKM_t Rte_Read_CDD_IPCHandler_RpTbFAResetKM_TbFA_ResetKM_t
#  define Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts Rte_Read_CDD_IPCHandler_RpToSwcSafeFD02Rx_CmdIgnSts
#  define Rte_Read_CDD_IPCHandler_RpToSwcSafeFD02Rx_CmdIgnSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpTrailerDetectOP_TrailerDetection_Output_DID_t Rte_Read_CDD_IPCHandler_RpTrailerDetectOP_TrailerDetection_Output_DID_t
#  define Rte_Read_RpTrscSmvctoSvs_TRSCSMVCtoSVS_t Rte_Read_CDD_IPCHandler_RpTrscSmvctoSvs_TRSCSMVCtoSVS_t
#  define Rte_Read_RpTrscToDiag_TRSCtoDiagMgr_t Rte_Read_CDD_IPCHandler_RpTrscToDiag_TRSCtoDiagMgr_t
#  define Rte_Read_RpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t Rte_Read_CDD_IPCHandler_RpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t
#  define Rte_Read_RpUSSBlockageBit_US_S_BlockageBit_t Rte_Read_CDD_IPCHandler_RpUSSBlockageBit_US_S_BlockageBit_t
#  define Rte_Read_RpUSSErrorDiagData_US_S_USSErrorDiagData_t Rte_Read_CDD_IPCHandler_RpUSSErrorDiagData_US_S_USSErrorDiagData_t
#  define Rte_Read_RpUssDataCollection_US_S_USSDataCollectionData_t Rte_Read_CDD_IPCHandler_RpUssDataCollection_US_S_USSDataCollectionData_t
#  define Rte_Read_RpUssPointMapGrp_US_S_PointMapGroup_t Rte_Read_CDD_IPCHandler_RpUssPointMapGrp_US_S_PointMapGroup_t
#  define Rte_Read_RpUssZoneInfo_US_S_ZoneInfo_t Rte_Read_CDD_IPCHandler_RpUssZoneInfo_US_S_ZoneInfo_t
#  define Rte_Read_RpVCActuatorOut_TbAP_VCActuatorOut_t Rte_Read_CDD_IPCHandler_RpVCActuatorOut_TbAP_VCActuatorOut_t
#  define Rte_Read_RpVCState_TbAP_VCStateOut_t Rte_Read_CDD_IPCHandler_RpVCState_TbAP_VCStateOut_t


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpAPSMPAOut_TbAP_APSMPAOut_t Rte_Write_CDD_IPCHandler_PpAPSMPAOut_TbAP_APSMPAOut_t
#  define Rte_Write_PpCAMSelInfo_CAM_select_info_t Rte_Write_CDD_IPCHandler_PpCAMSelInfo_CAM_select_info_t
#  define Rte_Write_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t Rte_Write_CDD_IPCHandler_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t
#  define Rte_Write_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t Rte_Write_CDD_IPCHandler_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t
#  define Rte_Write_PpCamCsData_CAM_CS_Curr_Monitor_t Rte_Write_CDD_IPCHandler_PpCamCsData_CAM_CS_Curr_Monitor_t
#  define Rte_Write_PpCamEepromData_Svs_CamEepromDataArray_t Rte_Write_CDD_IPCHandler_PpCamEepromData_Svs_CamEepromDataArray_t
#  define Rte_Write_PpCamSerENStat_Cam_and_Ser_EN_Status_t Rte_Write_CDD_IPCHandler_PpCamSerENStat_Cam_and_Ser_EN_Status_t
#  define Rte_Write_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t Rte_Write_CDD_IPCHandler_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t
#  define Rte_Write_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t Rte_Write_CDD_IPCHandler_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t
#  define Rte_Write_PpDLDOutput_JobDLDOutput_t Rte_Write_CDD_IPCHandler_PpDLDOutput_JobDLDOutput_t
#  define Rte_Write_PpDebCurReqOverlay_Debug_HMI_Curr_Requested_Overlays Rte_Write_CDD_IPCHandler_PpDebCurReqOverlay_Debug_HMI_Curr_Requested_Overlays
#  define Rte_Write_PpDebCurrDispOverlay_Debug_HMI_Curr_Displayed_Overlays Rte_Write_CDD_IPCHandler_PpDebCurrDispOverlay_Debug_HMI_Curr_Displayed_Overlays
#  define Rte_Write_PpDebCurrDispProxiCfg_Debug_HMI_Curr_Displayed_ProxiConfig Rte_Write_CDD_IPCHandler_PpDebCurrDispProxiCfg_Debug_HMI_Curr_Displayed_ProxiConfig
#  define Rte_Write_PpDebCurrReqProxiCfg_Debug_HMI_Curr_Requested_ProxiConfig Rte_Write_CDD_IPCHandler_PpDebCurrReqProxiCfg_Debug_HMI_Curr_Requested_ProxiConfig
#  define Rte_Write_PpDebHmiInput_Debug_HMI_Input_Data_t Rte_Write_CDD_IPCHandler_PpDebHmiInput_Debug_HMI_Input_Data_t
#  define Rte_Write_PpDebHmiInternal_Debug_HMI_Internal_Data_t Rte_Write_CDD_IPCHandler_PpDebHmiInternal_Debug_HMI_Internal_Data_t
#  define Rte_Write_PpDebHmiTrailViews_Debug_HMI_Trailer_Views_Data_t Rte_Write_CDD_IPCHandler_PpDebHmiTrailViews_Debug_HMI_Trailer_Views_Data_t
#  define Rte_Write_PpDetInpTrsc_Detection_Inputs_from_TRSC_t Rte_Write_CDD_IPCHandler_PpDetInpTrsc_Detection_Inputs_from_TRSC_t
#  define Rte_Write_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t Rte_Write_CDD_IPCHandler_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t
#  define Rte_Write_PpDrverSecuBltAlrmSts_TeVBII_e_DrverSecuBltAlrmSts Rte_Write_CDD_IPCHandler_PpDrverSecuBltAlrmSts_TeVBII_e_DrverSecuBltAlrmSts
#  define Rte_Write_CDD_IPCHandler_PpDrverSecuBltAlrmSts_TeVBII_e_DrverSecuBltAlrmSts(data) (RTE_E_OK)
#  define Rte_Write_PpEPS_VehInpAdapter_opVehSignals Rte_Write_CDD_IPCHandler_PpEPS_VehInpAdapter_opVehSignals
#  define Rte_Write_CDD_IPCHandler_PpEPS_VehInpAdapter_opVehSignals(data) (RTE_E_OK)
#  define Rte_Write_PpErrFltMcu2_0_Error_Fault_MCU2_0_t Rte_Write_CDD_IPCHandler_PpErrFltMcu2_0_Error_Fault_MCU2_0_t
#  define Rte_Write_PpErrFltMcu2_1_Error_Fault_MCU2_1_t Rte_Write_CDD_IPCHandler_PpErrFltMcu2_1_Error_Fault_MCU2_1_t
#  define Rte_Write_PpErrFltMpu1_0_Error_Fault_MPU1_0_t Rte_Write_CDD_IPCHandler_PpErrFltMpu1_0_Error_Fault_MPU1_0_t
#  define Rte_Write_PpFPAWarnOut_TbAP_FPAWarnOut_t Rte_Write_CDD_IPCHandler_PpFPAWarnOut_TbAP_FPAWarnOut_t
#  define Rte_Write_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t Rte_Write_CDD_IPCHandler_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t
#  define Rte_Write_PpIDebugFODObject_IDebug_FODObject_t Rte_Write_CDD_IPCHandler_PpIDebugFODObject_IDebug_FODObject_t
#  define Rte_Write_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t Rte_Write_CDD_IPCHandler_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t
#  define Rte_Write_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t Rte_Write_CDD_IPCHandler_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t
#  define Rte_Write_PpJobFPAData_IJobFPAOutput_t Rte_Write_CDD_IPCHandler_PpJobFPAData_IJobFPAOutput_t
#  define Rte_Write_PpJobPLDData_IJobPLDOutput_t Rte_Write_CDD_IPCHandler_PpJobPLDData_IJobPLDOutput_t
#  define Rte_Write_PpJobTHADetOutput_JobTHADetOutput_t Rte_Write_CDD_IPCHandler_PpJobTHADetOutput_JobTHADetOutput_t
#  define Rte_Write_PpKeepAliveResponse_KeepAliveResponse_t Rte_Write_CDD_IPCHandler_PpKeepAliveResponse_KeepAliveResponse_t
#  define Rte_Write_PpLMDLaneOp_LMD_Lane_Outputs_s Rte_Write_CDD_IPCHandler_PpLMDLaneOp_LMD_Lane_Outputs_s
#  define Rte_Write_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t Rte_Write_CDD_IPCHandler_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t
#  define Rte_Write_PpNFCDOutput_NFCD_Output Rte_Write_CDD_IPCHandler_PpNFCDOutput_NFCD_Output
#  define Rte_Write_PpNVMCamCalibSM_TbSVS_e_SVSOutputToNVMCamCalibSM_t Rte_Write_CDD_IPCHandler_PpNVMCamCalibSM_TbSVS_e_SVSOutputToNVMCamCalibSM_t
#  define Rte_Write_PpNVMSignMgr_NVMSignalManager_t Rte_Write_CDD_IPCHandler_PpNVMSignMgr_NVMSignalManager_t
#  define Rte_Write_PpPAM2BTIpcTxStatus_IpcTxDone Rte_Write_CDD_IPCHandler_PpPAM2BTIpcTxStatus_IpcTxDone
#  define Rte_Write_CDD_IPCHandler_PpPAM2BTIpcTxStatus_IpcTxDone(data) (Rte_CDD_IPCHandler_PpPAM2BTIpcTxStatus_IpcTxDone = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpPAStateOut_TbAP_PAStateOut_t Rte_Write_CDD_IPCHandler_PpPAStateOut_TbAP_PAStateOut_t
#  define Rte_Write_PpPointDistOpBuff_US_S_PointDistOutputBuff_t Rte_Write_CDD_IPCHandler_PpPointDistOpBuff_US_S_PointDistOutputBuff_t
#  define Rte_Write_PpRPAWarnOut_TbAP_RPAWarnOut_t Rte_Write_CDD_IPCHandler_PpRPAWarnOut_TbAP_RPAWarnOut_t
#  define Rte_Write_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t Rte_Write_CDD_IPCHandler_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t
#  define Rte_Write_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t Rte_Write_CDD_IPCHandler_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t
#  define Rte_Write_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t Rte_Write_CDD_IPCHandler_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t
#  define Rte_Write_PpSMDAInternal_TbAP_SMDAInternalOut_t Rte_Write_CDD_IPCHandler_PpSMDAInternal_TbAP_SMDAInternalOut_t
#  define Rte_Write_PpSR_State_MCU2_State_2_0 Rte_Write_CDD_IPCHandler_PpSR_State_MCU2_State_2_0
#  define Rte_Write_PpSR_State_MCU2_State_2_1 Rte_Write_CDD_IPCHandler_PpSR_State_MCU2_State_2_1
#  define Rte_Write_PpSR_State_QNX_State_QNX Rte_Write_CDD_IPCHandler_PpSR_State_QNX_State_QNX
#  define Rte_Write_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t Rte_Write_CDD_IPCHandler_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t
#  define Rte_Write_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t Rte_Write_CDD_IPCHandler_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t
#  define Rte_Write_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t Rte_Write_CDD_IPCHandler_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t
#  define Rte_Write_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t Rte_Write_CDD_IPCHandler_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t
#  define Rte_Write_PpSVSNVMData_SVS_NVMData_t Rte_Write_CDD_IPCHandler_PpSVSNVMData_SVS_NVMData_t
#  define Rte_Write_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t Rte_Write_CDD_IPCHandler_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t
#  define Rte_Write_PpSVSToDiag_SVSToDiag_t Rte_Write_CDD_IPCHandler_PpSVSToDiag_SVSToDiag_t
#  define Rte_Write_PpSVStoTRSC_SVStoTRSC_t Rte_Write_CDD_IPCHandler_PpSVStoTRSC_SVStoTRSC_t
#  define Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_1_0_B Rte_Write_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_1_0_B
#  define Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B Rte_Write_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B
#  define Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B Rte_Write_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B
#  define Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B Rte_Write_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B
#  define Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_1_0_QM Rte_Write_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_1_0_QM
#  define Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM Rte_Write_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM
#  define Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM Rte_Write_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM
#  define Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM Rte_Write_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM
#  define Rte_Write_PpScreenRequest_ScreenRequest_t Rte_Write_CDD_IPCHandler_PpScreenRequest_ScreenRequest_t
#  define Rte_Write_PpScreenResponse_ScreenResponse_t Rte_Write_CDD_IPCHandler_PpScreenResponse_ScreenResponse_t
#  define Rte_Write_CDD_IPCHandler_PpScreenResponse_ScreenResponse_t(data) (RTE_E_OK)
#  define Rte_Write_PpSnrDirEcho_US_S_SnrDirEcho_t Rte_Write_CDD_IPCHandler_PpSnrDirEcho_US_S_SnrDirEcho_t
#  define Rte_Write_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t Rte_Write_CDD_IPCHandler_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t
#  define Rte_Write_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t Rte_Write_CDD_IPCHandler_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t
#  define Rte_Write_PpSvsToTHA_SvsToTHA_t Rte_Write_CDD_IPCHandler_PpSvsToTHA_SvsToTHA_t
#  define Rte_Write_PpSvsToVCAN_SvsToVCAN_t Rte_Write_CDD_IPCHandler_PpSvsToVCAN_SvsToVCAN_t
#  define Rte_Write_PpTRSC_ME_VehOut_TRSC_t Rte_Write_CDD_IPCHandler_PpTRSC_ME_VehOut_TRSC_t
#  define Rte_Write_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t Rte_Write_CDD_IPCHandler_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t
#  define Rte_Write_PpTbAPDebugOut_TbAP_DebugOut Rte_Write_CDD_IPCHandler_PpTbAPDebugOut_TbAP_DebugOut
#  define Rte_Write_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t Rte_Write_CDD_IPCHandler_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t
#  define Rte_Write_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t Rte_Write_CDD_IPCHandler_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t
#  define Rte_Write_PpTbFAResetKM_TbFA_ResetKM_t Rte_Write_CDD_IPCHandler_PpTbFAResetKM_TbFA_ResetKM_t
#  define Rte_Write_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t Rte_Write_CDD_IPCHandler_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t
#  define Rte_Write_PpTrailerDetectOP_TrailerDetection_Output_DID_t Rte_Write_CDD_IPCHandler_PpTrailerDetectOP_TrailerDetection_Output_DID_t
#  define Rte_Write_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t Rte_Write_CDD_IPCHandler_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t
#  define Rte_Write_PpTrscToDiag_TRSCtoDiagMgr_t Rte_Write_CDD_IPCHandler_PpTrscToDiag_TRSCtoDiagMgr_t
#  define Rte_Write_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t Rte_Write_CDD_IPCHandler_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t
#  define Rte_Write_PpUSSBlockageBit_US_S_BlockageBit_t Rte_Write_CDD_IPCHandler_PpUSSBlockageBit_US_S_BlockageBit_t
#  define Rte_Write_PpUSSConstantData_US_S_USSConstantData_t Rte_Write_CDD_IPCHandler_PpUSSConstantData_US_S_USSConstantData_t
#  define Rte_Write_PpUSSErrorDiagData_US_S_USSErrorDiagData_t Rte_Write_CDD_IPCHandler_PpUSSErrorDiagData_US_S_USSErrorDiagData_t
#  define Rte_Write_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t Rte_Write_CDD_IPCHandler_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t
#  define Rte_Write_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type Rte_Write_CDD_IPCHandler_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type
#  define Rte_Write_PpUssDataCollection_US_S_USSDataCollectionData_t Rte_Write_CDD_IPCHandler_PpUssDataCollection_US_S_USSDataCollectionData_t
#  define Rte_Write_PpUssDebugMsg_US_S_DebugMsg_t Rte_Write_CDD_IPCHandler_PpUssDebugMsg_US_S_DebugMsg_t
#  define Rte_Write_PpUssMrrgData_US_S_MarriageSensorIDs_t Rte_Write_CDD_IPCHandler_PpUssMrrgData_US_S_MarriageSensorIDs_t
#  define Rte_Write_PpUssPointMapGrp_US_S_PointMapGroup_t Rte_Write_CDD_IPCHandler_PpUssPointMapGrp_US_S_PointMapGroup_t
#  define Rte_Write_PpUssTunData_UssTunningData_mcu2_1_t Rte_Write_CDD_IPCHandler_PpUssTunData_UssTunningData_mcu2_1_t
#  define Rte_Write_PpUssZoneInfo_US_S_ZoneInfo_t Rte_Write_CDD_IPCHandler_PpUssZoneInfo_US_S_ZoneInfo_t
#  define Rte_Write_PpVCActuatorOut_TbAP_VCActuatorOut_t Rte_Write_CDD_IPCHandler_PpVCActuatorOut_TbAP_VCActuatorOut_t
#  define Rte_Write_PpVCState_TbAP_VCStateOut_t Rte_Write_CDD_IPCHandler_PpVCState_TbAP_VCStateOut_t
#  define Rte_Write_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t Rte_Write_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t
#  define Rte_Write_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t Rte_Write_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t
#  define Rte_Write_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t Rte_Write_CDD_IPCHandler_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_VAR_NOINIT) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_FPA_Slot_Data_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)71, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_FPA_Slot_Data_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)71, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_FPA_Slot_Data_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)71, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_FeatureAP_HMI_NvMData_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)67, arg1))

/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_DefaultValue;
extern CONST(INVMSignalManager_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_IPCHandler_FPA_Slot_Data_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_FeatureAP_HMI_NvMData_DefaultValue() (Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_DefaultValue)

#  define Rte_CData_FPA_Slot_Data_DefaultValue() (&Rte_CDD_IPCHandler_FPA_Slot_Data_DefaultValue)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(INVMSignalManager_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_FPA_Slot_Data_MirrorBlock() \
  (&Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock)
/* PRQA L:L1 */

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_INIT_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_INIT) Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_INIT_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_FeatureAP_HMI_NvMData_MirrorBlock() \
  (&Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define CDD_IPCHandler_START_SEC_CODE
# include "CDD_IPCHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RE_CddIpcHandler_Init RE_CddIpcHandler_Init
#  define RTE_RUNNABLE_RE_CddIpcHandler_Main RE_CddIpcHandler_Main
#  define RTE_RUNNABLE_RE_IpcTxData RE_IpcTxData
# endif

FUNC(void, CDD_IPCHandler_CODE) RE_CddIpcHandler_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, CDD_IPCHandler_CODE) RE_CddIpcHandler_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, CDD_IPCHandler_CODE) RE_IpcTxData(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define CDD_IPCHandler_STOP_SEC_CODE
# include "CDD_IPCHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CDD_IPCHANDLER_H */

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
