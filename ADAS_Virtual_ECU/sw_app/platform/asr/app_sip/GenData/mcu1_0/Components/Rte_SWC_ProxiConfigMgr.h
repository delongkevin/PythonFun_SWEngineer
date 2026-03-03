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
 *             File:  Rte_SWC_ProxiConfigMgr.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <SWC_ProxiConfigMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PROXICONFIGMGR_H
# define RTE_SWC_PROXICONFIGMGR_H

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

# include "Rte_SWC_ProxiConfigMgr_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

#  include "Com.h"


/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(TotalOdometer, RTE_VAR_INIT) Rte_TotalOdometer_oIPC_FD_1_oFDCAN2_602313ac_Rx;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiReset_ProxiDataflag_b;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Fullautomaticparking;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_PAMConfig_u8;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_PRX_CanNod27_b;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Pamtuningset;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Parkwithstop_u8;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Trailerhitchassist_u8;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_TyreSz_u16;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpVariantData_Variant;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PpProxiReset_ProxiDataflag_b (FALSE)
#  define Rte_InitValue_PpProxiToSWC_Fullautomaticparking (0U)
#  define Rte_InitValue_PpProxiToSWC_PAMConfig_u8 (0U)
#  define Rte_InitValue_PpProxiToSWC_PRX_CanNod27_b (FALSE)
#  define Rte_InitValue_PpProxiToSWC_Pamtuningset (0U)
#  define Rte_InitValue_PpProxiToSWC_Parkwithstop_u8 (0U)
#  define Rte_InitValue_PpProxiToSWC_SurroundViewCam_u8 (0U)
#  define Rte_InitValue_PpProxiToSWC_Trailerhitchassist_u8 (0U)
#  define Rte_InitValue_PpProxiToSWC_TyreSz_u16 (0U)
#  define Rte_InitValue_PpToComFD02Tx_CurrentCanNMState_FD02_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_CurrentFailSts_FD02_PAM (FALSE)
#  define Rte_InitValue_PpToComFD02Tx_DES_FD02_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_01_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_02_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_03_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_04_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_05_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_06_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_07_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_08_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_09_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_10_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_11_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_EOL_FD02_PAM (FALSE)
#  define Rte_InitValue_PpToComFD02Tx_GenericFailSts_FD02_PAM (FALSE)
#  define Rte_InitValue_PpToComFD02Tx_PreviousCanNMState_FD02_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_THA_EPB_Req (0U)
#  define Rte_InitValue_PpToComFD02Tx_THA_STAT (0U)
#  define Rte_InitValue_PpToComFD02Tx_THA_SpeedLimit_Req (0U)
#  define Rte_InitValue_PpToComFD02Tx_THA_Speed_Limit (0U)
#  define Rte_InitValue_PpToComFD02Tx_THA_SteeringDamping (100U)
#  define Rte_InitValue_PpToComFD02Tx_THA_SteeringTorqueInfo (1024U)
#  define Rte_InitValue_PpToComFD02Tx_THA_SteeringTorqueReq (0U)
#  define Rte_InitValue_PpToComFD02Tx_TRSCMoreCamRQSts (FALSE)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_PopupDisp_Info (0U)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_PopupDisp_Info2 (0U)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_STAT (1U)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_SpeedLimit_Req (0U)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_SteeringDamping (128U)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_SteeringTorqueInfo (1024U)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_SteeringTorqueReq (0U)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_VehicleStop_Req (3U)
#  define Rte_InitValue_PpToComFD02Tx_Trailer_Angle (0U)
#  define Rte_InitValue_PpToComFD02Tx_Trailer_Angle_Sign (0U)
#  define Rte_InitValue_PpToComFD02Tx_Trailer_Calibration (0U)
#  define Rte_InitValue_PpToComFD02Tx_TrlrHitchLight_Cntrl (0U)
#  define Rte_InitValue_PpToComFD02Tx_WakeupSource_FD02_PAM (0U)
#  define Rte_InitValue_PpVariantData_Variant (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Altitude_RMSE_C2 (128U)
#  define Rte_InitValue_RpFromComFD02Rx_BSM_THA_Brk_Resp (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Battery_Volt_1 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD01_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD01_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD02_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD02_BSM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD02_CADM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD02_EPS (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD02_ORC (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD02_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD02_TRLR_REV (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD03_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD03_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD04_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD08_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD11_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD01_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD01_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD02_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD02_BSM2 (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD02_CADM2 (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD02_EPS (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD02_ORC (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD02_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD02_TRLR_REV (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD03_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD03_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD04_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD08_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD11_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD01_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD01_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD02_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD02_BSM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD02_CADM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD02_EPS (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD02_ORC (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD02_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD02_TRLR_REV (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD03_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD03_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD04_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD08_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD11_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DeltaTimestamp_IMUdata (255U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_01 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_02 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_03 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_04 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_05 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_06 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_07 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_08 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_09 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_10 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_11 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD01_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD01_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD02_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD02_BSM2 (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD02_CADM2 (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD02_EPS (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD02_ORC (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD02_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD02_TRLR_REV (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD03_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD03_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD04_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD08_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD11_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EPBSts (0U)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD01_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD01_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD02_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD02_BSM2 (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD02_CADM2 (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD02_EPS (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD02_ORC (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD02_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD02_TRLR_REV (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD03_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD03_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD04_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD08_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD11_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_Heading_Angle_C2 (65535U)
#  define Rte_InitValue_RpFromComFD02Rx_IgnitionOnCounter (0U)
#  define Rte_InitValue_RpFromComFD02Rx_LHFWheelSpeed (0U)
#  define Rte_InitValue_RpFromComFD02Rx_LHF_FastPulseCounter (0U)
#  define Rte_InitValue_RpFromComFD02Rx_LHF_Spin (0U)
#  define Rte_InitValue_RpFromComFD02Rx_LHRWheelSpeed (0U)
#  define Rte_InitValue_RpFromComFD02Rx_LHR_FastPulseCounter (0U)
#  define Rte_InitValue_RpFromComFD02Rx_LHR_Spin (0U)
#  define Rte_InitValue_RpFromComFD02Rx_LatAccelerationOffset_BSM (255U)
#  define Rte_InitValue_RpFromComFD02Rx_LatAcceleration_C2 (4095U)
#  define Rte_InitValue_RpFromComFD02Rx_Latitude_RMSE_C2 (128U)
#  define Rte_InitValue_RpFromComFD02Rx_LongAccelerationOffset_BSM (255U)
#  define Rte_InitValue_RpFromComFD02Rx_LongAcceleration_C2 (4095U)
#  define Rte_InitValue_RpFromComFD02Rx_Longitude_RMSE_C2 (128U)
#  define Rte_InitValue_RpFromComFD02Rx_OperationalModeSts (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PitchRate_C2 (4095U)
#  define Rte_InitValue_RpFromComFD02Rx_Pitch_RMSE_C2 (128U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD01_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD01_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD02_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD02_BSM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD02_CADM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD02_EPS (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD02_ORC (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD02_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD02_TRLR_REV (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD03_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD03_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD04_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD08_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD11_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_REF_VEH_SPEED (1023U)
#  define Rte_InitValue_RpFromComFD02Rx_RHFWheelSpeed (0U)
#  define Rte_InitValue_RpFromComFD02Rx_RHF_FastPulseCounter (0U)
#  define Rte_InitValue_RpFromComFD02Rx_RHF_Spin (0U)
#  define Rte_InitValue_RpFromComFD02Rx_RHRWheelSpeed (0U)
#  define Rte_InitValue_RpFromComFD02Rx_RHR_FastPulseCounter (0U)
#  define Rte_InitValue_RpFromComFD02Rx_RHR_Spin (0U)
#  define Rte_InitValue_RpFromComFD02Rx_RemStActvSts (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_RollRate_C2 (4095U)
#  define Rte_InitValue_RpFromComFD02Rx_Roll_RMSE_C2 (128U)
#  define Rte_InitValue_RpFromComFD02Rx_SBR1RowDriverSeatSts (3U)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD01_BCM (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD01_SGW (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD02_BCM (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD02_BSM2 (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD02_CADM2 (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD02_EPS (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD02_ORC (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD02_SGW (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD02_TRLR_REV (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD03_BCM (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD03_SGW (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD04_BCM (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD08_SGW (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD11_SGW (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_TRSC_CenterBtn_Sts (0U)
#  define Rte_InitValue_RpFromComFD02Rx_TRSC_EnableBtn_Sts (0U)
#  define Rte_InitValue_RpFromComFD02Rx_TRSC_RawKnob (0U)
#  define Rte_InitValue_RpFromComFD02Rx_TotalOdometer (0U)
#  define Rte_InitValue_RpFromComFD02Rx_TurnIndicatorSts (0U)
#  define Rte_InitValue_RpFromComFD02Rx_VehicleStandStillSts (1U)
#  define Rte_InitValue_RpFromComFD02Rx_VerticalAcceleration_C2 (4095U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD01_ADCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD01_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD01_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD02_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD02_BSM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD02_CADM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD02_EPS (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD02_ORC (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD02_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD02_TRLR_REV (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD03_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD03_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD04_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD08_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD11_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_YawRate_C2 (4095U)
#  define Rte_InitValue_RpFromComFD02Rx_YawRate_RMSE_C2 (128U)
# endif


# define RTE_START_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_ProxiConfigMgr_R_SSM_1_0_State_State_1_0(P2VAR(SSM_1_0_CoreStatus, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_ProxiConfigMgr_R_SSM_2_State_State_2_0(P2VAR(SSM_2_0_CoreStatus, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_ProxiConfigMgr_R_SSM_2_State_State_2_1(P2VAR(SSM_2_1_CoreStatus, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_ProxiConfigMgr_R_SSM_QNXState_State_QNX(P2VAR(SSM_QNX_CoreStatus, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_ProxiConfigMgr_R_SystemState_SystemState(P2VAR(SSM_SystemState, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_ProxiConfigMgr_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(P2VAR(ME_Proxi_MPU1_0_to_MCU1_0_t, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpProxiConfigData_ProxiData(P2CONST(ME_Hydra2defs_S_CodingTableExt_t, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpProxiErrorData_Error(P2CONST(ME_Hydra2defs_S_PROXI_error_Data_t, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_01_PAM(Digit_01_PAM data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_02_PAM(Digit_02_PAM data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_03_PAM(Digit_03_PAM data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_04_PAM(Digit_04_PAM data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_05_PAM(Digit_05_PAM data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_06_PAM(Digit_06_PAM data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_07_PAM(Digit_07_PAM data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_08_PAM(Digit_08_PAM data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_09_PAM(Digit_09_PAM data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_10_PAM(Digit_10_PAM data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_11_PAM(Digit_11_PAM data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_EOL_FD02_PAM(EOL_FD02_PAM data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_SSM_1_0_State_State_1_0 Rte_Read_SWC_ProxiConfigMgr_R_SSM_1_0_State_State_1_0
#  define Rte_Read_R_SSM_2_State_State_2_0 Rte_Read_SWC_ProxiConfigMgr_R_SSM_2_State_State_2_0
#  define Rte_Read_R_SSM_2_State_State_2_1 Rte_Read_SWC_ProxiConfigMgr_R_SSM_2_State_State_2_1
#  define Rte_Read_R_SSM_QNXState_State_QNX Rte_Read_SWC_ProxiConfigMgr_R_SSM_QNXState_State_QNX
#  define Rte_Read_R_SystemState_SystemState Rte_Read_SWC_ProxiConfigMgr_R_SystemState_SystemState
#  define Rte_Read_RpFromComFD02Rx_TotalOdometer Rte_Read_SWC_ProxiConfigMgr_RpFromComFD02Rx_TotalOdometer
#  define Rte_Read_SWC_ProxiConfigMgr_RpFromComFD02Rx_TotalOdometer(data) (*(data) = Rte_TotalOdometer_oIPC_FD_1_oFDCAN2_602313ac_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t Rte_Read_SWC_ProxiConfigMgr_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpProxiConfigData_ProxiData Rte_Write_SWC_ProxiConfigMgr_PpProxiConfigData_ProxiData
#  define Rte_Write_PpProxiErrorData_Error Rte_Write_SWC_ProxiConfigMgr_PpProxiErrorData_Error
#  define Rte_Write_PpProxiReset_ProxiDataflag_b Rte_Write_SWC_ProxiConfigMgr_PpProxiReset_ProxiDataflag_b
#  define Rte_Write_SWC_ProxiConfigMgr_PpProxiReset_ProxiDataflag_b(data) (Rte_SWC_ProxiConfigMgr_PpProxiReset_ProxiDataflag_b = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpProxiToSWC_Fullautomaticparking Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_Fullautomaticparking
#  define Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_Fullautomaticparking(data) (Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Fullautomaticparking = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpProxiToSWC_PAMConfig_u8 Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_PAMConfig_u8
#  define Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_PAMConfig_u8(data) (Rte_SWC_ProxiConfigMgr_PpProxiToSWC_PAMConfig_u8 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpProxiToSWC_PRX_CanNod27_b Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_PRX_CanNod27_b
#  define Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_PRX_CanNod27_b(data) (Rte_SWC_ProxiConfigMgr_PpProxiToSWC_PRX_CanNod27_b = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpProxiToSWC_Pamtuningset Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_Pamtuningset
#  define Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_Pamtuningset(data) (Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Pamtuningset = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpProxiToSWC_Parkwithstop_u8 Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_Parkwithstop_u8
#  define Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_Parkwithstop_u8(data) (Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Parkwithstop_u8 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpProxiToSWC_SurroundViewCam_u8 Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8
#  define Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8(data) (Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpProxiToSWC_Trailerhitchassist_u8 Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_Trailerhitchassist_u8
#  define Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_Trailerhitchassist_u8(data) (Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Trailerhitchassist_u8 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpProxiToSWC_TyreSz_u16 Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_TyreSz_u16
#  define Rte_Write_SWC_ProxiConfigMgr_PpProxiToSWC_TyreSz_u16(data) (Rte_SWC_ProxiConfigMgr_PpProxiToSWC_TyreSz_u16 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToComFD02Tx_Digit_01_PAM Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_01_PAM
#  define Rte_Write_PpToComFD02Tx_Digit_02_PAM Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_02_PAM
#  define Rte_Write_PpToComFD02Tx_Digit_03_PAM Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_03_PAM
#  define Rte_Write_PpToComFD02Tx_Digit_04_PAM Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_04_PAM
#  define Rte_Write_PpToComFD02Tx_Digit_05_PAM Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_05_PAM
#  define Rte_Write_PpToComFD02Tx_Digit_06_PAM Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_06_PAM
#  define Rte_Write_PpToComFD02Tx_Digit_07_PAM Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_07_PAM
#  define Rte_Write_PpToComFD02Tx_Digit_08_PAM Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_08_PAM
#  define Rte_Write_PpToComFD02Tx_Digit_09_PAM Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_09_PAM
#  define Rte_Write_PpToComFD02Tx_Digit_10_PAM Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_10_PAM
#  define Rte_Write_PpToComFD02Tx_Digit_11_PAM Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_11_PAM
#  define Rte_Write_PpToComFD02Tx_EOL_FD02_PAM Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_EOL_FD02_PAM
#  define Rte_Write_PpVariantData_Variant Rte_Write_SWC_ProxiConfigMgr_PpVariantData_Variant
#  define Rte_Write_SWC_ProxiConfigMgr_PpVariantData_Variant(data) (Rte_SWC_ProxiConfigMgr_PpVariantData_Variant = (data), ((Std_ReturnType)RTE_E_OK))


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

#  define RTE_START_SEC_ERRORMGRSAT_1_0_QM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_ERRORMGRSAT_1_0_QM_APPL_CODE) RE_ReportErrorStatus1_0_QM(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, P2CONST(ErrorMgr_stAddData, AUTOMATIC, RTE_VAR_NOINIT) addData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ERRORMGRSAT_1_0_QM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_VAR_NOINIT) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SWC_DIDMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_SWC_DIDMGR_APPL_CODE) Pp_NVM_Write_ProxiConfigTable_ProxiconfigTable_Nvm_write_confirmation(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SWC_DIDMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_ProxiConfigTable_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)53, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_ProxiConfigTable_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)53, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_ProxiErrorData_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)54, arg1))
#  define Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B RE_ReportErrorStatus1_0_B
#  define Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM RE_ReportErrorStatus1_0_QM
#  define Rte_Call_RpIpcTxData_IPC_Write_v(arg1, arg2, arg3) (RE_IpcTxData(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_Rp_NVM_Write_ProxiConfigTable_ProxiconfigTable_Nvm_write_confirmation() (Pp_NVM_Write_ProxiConfigTable_ProxiconfigTable_Nvm_write_confirmation(), ((Std_ReturnType)RTE_E_OK))

/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(ME_Hydra2defs_S_CodingTableExt_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_ProxiConfigMgr_ProxiConfigTable_DefaultValue;
extern CONST(ME_Hydra2defs_S_PROXI_error_Data_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_ProxiConfigMgr_ProxiErrorData_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_ProxiConfigTable_DefaultValue() (&Rte_SWC_ProxiConfigMgr_ProxiConfigTable_DefaultValue)

#  define Rte_CData_ProxiErrorData_DefaultValue() (&Rte_SWC_ProxiConfigMgr_ProxiErrorData_DefaultValue)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(ME_Hydra2defs_S_CodingTableExt_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock;
extern VAR(ME_Hydra2defs_S_PROXI_error_Data_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_ProxiConfigTable_MirrorBlock() \
  (&Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_ProxiErrorData_MirrorBlock() \
  (&Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define SWC_ProxiConfigMgr_START_SEC_CODE
# include "SWC_ProxiConfigMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RE_DID2023_ProxiData RE_DID2023_ProxiData
#  define RTE_RUNNABLE_RE_ProxiConfigMgr_Init RE_ProxiConfigMgr_Init
#  define RTE_RUNNABLE_RE_ProxiConfigMgr_Main RE_ProxiConfigMgr_Main
#  define RTE_RUNNABLE_RE_ProxiMgr_ConfigDataRSP RE_ProxiMgr_ConfigDataRSP
# endif

# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(void, SWC_ProxiConfigMgr_CODE) RE_DID2023_ProxiData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, uint16 Datalength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) Errorcode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, SWC_ProxiConfigMgr_CODE) RE_DID2023_ProxiData(P2CONST(Proxi_255byte, AUTOMATIC, RTE_VAR_NOINIT) Data, uint16 Datalength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) Errorcode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, SWC_ProxiConfigMgr_CODE) RE_ProxiConfigMgr_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_ProxiConfigMgr_CODE) RE_ProxiConfigMgr_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_ProxiConfigMgr_CODE) RE_ProxiMgr_ConfigDataRSP(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_ProxiConfigMgr_STOP_SEC_CODE
# include "SWC_ProxiConfigMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_P_Error_CS_E_NOK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PROXICONFIGMGR_H */

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
