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
 *             File:  Rte_SWC_KinematicModule.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <SWC_KinematicModule>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_KINEMATICMODULE_H
# define RTE_SWC_KINEMATICMODULE_H

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

# include "Rte_SWC_KinematicModule_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(GearEngaged, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngaged;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHRWheelSpeed;
extern VAR(FD14_LHR_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter;
extern VAR(FD14_LwsAngle, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngle;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHRWheelSpeed;
extern VAR(FD14_RHR_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

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
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_ACC_Systemsts (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_BSM_THA_Brk_Resp (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_BrkPdl_Stat (3U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_BrkTrq (10922U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_BrkTrq_Driver (10922U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_Brk_Stat (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_EPBSts (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_ExternalBrkRequestsDisabled (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_HAS_Status (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHFWheelSpeed (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHF_Spin (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHRWheelSpeed (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHR_Spin (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LatAccelerationOffset_BSM (255U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM (4095U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LongAccelerationOffset_BSM (255U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM (4095U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LwsAngle (7200U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LwsAngleType (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LwsSpeed (2000U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_ParkingGearShiftReq_BSM (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_ParkingInterventionSts (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_REF_VEH_SPEED (1023U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHFWheelSpeed (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHF_Spin (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHRWheelSpeed (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHR_Spin (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_Slope (100U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_Steering_Column_Torque (1024U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2 (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_VehicleStandStillSts (1U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_YawRate_BSM (4095U)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_KinematicModule_RpAPVarTunParam_TbAP_VrntTunParam_t(P2VAR(TbAP_VrntTunParam_t, AUTOMATIC, RTE_SWC_KINEMATICMODULE_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_KinematicModule_RpIFODOpArbitration_IFOD_Outputs_Arbitration_t(P2VAR(IFOD_Outputs_Arbitration_t, AUTOMATIC, RTE_SWC_KINEMATICMODULE_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_KinematicModule_RpProxiConfigData_ProxiData(P2VAR(ME_Hydra2defs_S_CodingTableExt_t, AUTOMATIC, RTE_SWC_KINEMATICMODULE_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_KinematicModule_RpSMDAInternal_TbAP_SMDAInternalOut_t(P2VAR(TbAP_SMDAInternalOut_t, AUTOMATIC, RTE_SWC_KINEMATICMODULE_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_KinematicModule_RpTbFAResetKM_TbFA_ResetKM_t(P2VAR(TbFA_ResetKM_t, AUTOMATIC, RTE_SWC_KINEMATICMODULE_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_RpAPVarTunParam_TbAP_VrntTunParam_t Rte_Read_SWC_KinematicModule_RpAPVarTunParam_TbAP_VrntTunParam_t
#  define Rte_Read_RpIFODOpArbitration_IFOD_Outputs_Arbitration_t Rte_Read_SWC_KinematicModule_RpIFODOpArbitration_IFOD_Outputs_Arbitration_t
#  define Rte_Read_RpProxiConfigData_ProxiData Rte_Read_SWC_KinematicModule_RpProxiConfigData_ProxiData
#  define Rte_Read_RpSMDAInternal_TbAP_SMDAInternalOut_t Rte_Read_SWC_KinematicModule_RpSMDAInternal_TbAP_SMDAInternalOut_t
#  define Rte_Read_RpTbFAResetKM_TbFA_ResetKM_t Rte_Read_SWC_KinematicModule_RpTbFAResetKM_TbFA_ResetKM_t
#  define Rte_Read_RpToSwcSafeFD02Rx_GearEngaged Rte_Read_SWC_KinematicModule_RpToSwcSafeFD02Rx_GearEngaged
#  define Rte_Read_SWC_KinematicModule_RpToSwcSafeFD02Rx_GearEngaged(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngaged, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LHRWheelSpeed Rte_Read_SWC_KinematicModule_RpToSwcSafeFD14Rx_FD14_LHRWheelSpeed
#  define Rte_Read_SWC_KinematicModule_RpToSwcSafeFD14Rx_FD14_LHRWheelSpeed(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHRWheelSpeed, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter Rte_Read_SWC_KinematicModule_RpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter
#  define Rte_Read_SWC_KinematicModule_RpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LwsAngle Rte_Read_SWC_KinematicModule_RpToSwcSafeFD14Rx_FD14_LwsAngle
#  define Rte_Read_SWC_KinematicModule_RpToSwcSafeFD14Rx_FD14_LwsAngle(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngle, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_RHRWheelSpeed Rte_Read_SWC_KinematicModule_RpToSwcSafeFD14Rx_FD14_RHRWheelSpeed
#  define Rte_Read_SWC_KinematicModule_RpToSwcSafeFD14Rx_FD14_RHRWheelSpeed(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHRWheelSpeed, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter Rte_Read_SWC_KinematicModule_RpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter
#  define Rte_Read_SWC_KinematicModule_RpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_IPCHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CDD_IPCHANDLER_APPL_CODE) RE_IpcTxData(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CDD_IPCHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RpIpcTxData_IPC_Write_v(arg1, arg2, arg3) (RE_IpcTxData(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define SWC_KinematicModule_START_SEC_CODE
# include "SWC_KinematicModule_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RE_KinematicModule_Init RE_KinematicModule_Init
#  define RTE_RUNNABLE_RE_KinematicModule_Main RE_KinematicModule_Main
# endif

FUNC(void, SWC_KinematicModule_CODE) RE_KinematicModule_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_KinematicModule_CODE) RE_KinematicModule_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_KinematicModule_STOP_SEC_CODE
# include "SWC_KinematicModule_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_KINEMATICMODULE_H */

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
