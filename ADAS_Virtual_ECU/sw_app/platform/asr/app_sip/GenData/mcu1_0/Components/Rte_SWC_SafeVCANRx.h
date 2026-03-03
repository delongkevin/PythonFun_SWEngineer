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
 *             File:  Rte_SWC_SafeVCANRx.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <SWC_SafeVCANRx>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_SAFEVCANRX_H
# define RTE_SWC_SAFEVCANRX_H

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

# include "Rte_SWC_SafeVCANRx_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

#  include "Com.h"


/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DTCMgr_PpDtcB12852AData_v_DtcData_u8;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpFailSafeReaction_State;
extern VAR(Brk_Stat, RTE_VAR_INIT) Rte_Brk_Stat_oBRAKE_FD_2_oFDCAN2_1b647924_Rx;
extern VAR(DynamicGrid, RTE_VAR_INIT) Rte_DynamicGrid_oIPC_VEHICLE_SETUP_oFDCAN2_8defe0e1_Rx;
extern VAR(EPS_SteeringTouchStat, RTE_VAR_INIT) Rte_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN2_70168af6_Rx;
extern VAR(EPS_SteeringTouq_Resp, RTE_VAR_INIT) Rte_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN2_a31e0e47_Rx;
extern VAR(EPS_THA_DriverTorqueOverride, RTE_VAR_INIT) Rte_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN2_0e3a0a14_Rx;
extern VAR(EPS_THA_SteeringTorqueResp, RTE_VAR_INIT) Rte_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN2_2f8c0396_Rx;
extern VAR(ESS_ENG_ST_W, RTE_VAR_INIT) Rte_ESS_ENG_ST_W_oENGINE_FD_2_oFDCAN2_b1b6db89_Rx;
extern VAR(EngineSts_W, RTE_VAR_INIT) Rte_EngineSts_W_oENGINE_FD_2_oFDCAN2_7417ef03_Rx;
extern VAR(ExternalTemperature, RTE_VAR_INIT) Rte_ExternalTemperature_oBCM_FD_9_oFDCAN2_fd16cd2c_Rx;
extern VAR(FL_Lvl, RTE_VAR_INIT) Rte_FL_Lvl_oASCM_FD_1_oFDCAN2_724f5049_Rx;
extern VAR(FL_Lvl_Adj, RTE_VAR_INIT) Rte_FL_Lvl_Adj_oASCM_FD_1_oFDCAN2_959485e3_Rx;
extern VAR(FR_Lvl, RTE_VAR_INIT) Rte_FR_Lvl_oASCM_FD_1_oFDCAN2_6f14419a_Rx;
extern VAR(FR_Lvl_Adj, RTE_VAR_INIT) Rte_FR_Lvl_Adj_oASCM_FD_1_oFDCAN2_86d8b295_Rx;
extern VAR(GearEngagedForDisplay, RTE_VAR_INIT) Rte_GearEngagedForDisplay_oTRANSM_FD_2_oFDCAN2_375443ce_Rx;
extern VAR(HAS_Status_C2, RTE_VAR_INIT) Rte_HAS_Status_C2_oADAS_FD_INFO_C2_oFDCAN2_5f0dae63_Rx;
extern VAR(LatAcceleration_BSM, RTE_VAR_INIT) Rte_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_318e470e_Rx;
extern VAR(LongAcceleration_BSM, RTE_VAR_INIT) Rte_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_f132a23a_Rx;
extern VAR(LwsAngle, RTE_VAR_INIT) Rte_LwsAngle_oEPS_FD_1_oFDCAN2_4dcc502d_Rx;
extern VAR(LwsAngleType, RTE_VAR_INIT) Rte_LwsAngleType_oEPS_FD_1_oFDCAN2_aea1ae81_Rx;
extern VAR(LwsSpeed, RTE_VAR_INIT) Rte_LwsSpeed_oEPS_FD_1_oFDCAN2_08f75f98_Rx;
extern VAR(MRM_STATUS_C2, RTE_VAR_INIT) Rte_MRM_STATUS_C2_oADAS_FD_INFO_C2_oFDCAN2_8ba84d40_Rx;
extern VAR(PdlPosActual, RTE_VAR_INIT) Rte_PdlPosActual_oENGINE_FD_5_oFDCAN2_743309cb_Rx;
extern VAR(RL_Lvl, RTE_VAR_INIT) Rte_RL_Lvl_oASCM_FD_1_oFDCAN2_d1e53ddc_Rx;
extern VAR(RL_Lvl_Adj, RTE_VAR_INIT) Rte_RL_Lvl_Adj_oASCM_FD_1_oFDCAN2_44326a37_Rx;
extern VAR(RR_Lvl, RTE_VAR_INIT) Rte_RR_Lvl_oASCM_FD_1_oFDCAN2_ccbe2c0f_Rx;
extern VAR(RR_Lvl_Adj, RTE_VAR_INIT) Rte_RR_Lvl_Adj_oASCM_FD_1_oFDCAN2_577e5d41_Rx;
extern VAR(Shifter_ADAS_Inhibit, RTE_VAR_INIT) Rte_Shifter_ADAS_Inhibit_oAGSM_FD_2_oFDCAN2_633e22f5_Rx;
extern VAR(THA_SteeringTouchStat, RTE_VAR_INIT) Rte_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN2_b7575370_Rx;
extern VAR(TRANS_ADAS_Inhibit, RTE_VAR_INIT) Rte_TRANS_ADAS_Inhibit_oTRANSM_FD_1_oFDCAN2_6ec0c415_Rx;
extern VAR(TargetGear, RTE_VAR_INIT) Rte_TargetGear_oTRANSM_FD_1_oFDCAN2_b75950f9_Rx;
extern VAR(TrailerConnectionSts, RTE_VAR_INIT) Rte_TrailerConnectionSts_oBCM_FD_27_oFDCAN2_e828ec43_Rx;
extern VAR(TransmissionSailingSts, RTE_VAR_INIT) Rte_TransmissionSailingSts_oTRANSM_FD_1_oFDCAN2_86af8834_Rx;
extern VAR(VIN_MSG, RTE_VAR_INIT) Rte_VIN_MSG_oVIN_oFDCAN2_f39912b4_Rx;
extern VAR(VehicleSpeedVSOSig, RTE_VAR_INIT) Rte_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN2_53fecdc7_Rx;
extern VAR(YawRate_BSM, RTE_VAR_INIT) Rte_YawRate_BSM_oBRAKE_FD_2_oFDCAN2_64569af1_Rx;
extern VAR(FD14_ACC_Systemsts, RTE_VAR_INIT) Rte_FD14_ACC_Systemsts_oADAS_FD_INFO_oFDCAN14_2086cf20_Rx;
extern VAR(FD14_BrkPdl_Stat, RTE_VAR_INIT) Rte_FD14_BrkPdl_Stat_oBRAKE_FD_7_oFDCAN14_d494c4ed_Rx;
extern VAR(FD14_BrkTrq, RTE_VAR_INIT) Rte_FD14_BrkTrq_oBRAKE_FD_1_oFDCAN14_a585a712_Rx;
extern VAR(FD14_BrkTrq_Driver, RTE_VAR_INIT) Rte_FD14_BrkTrq_Driver_oBRAKE_FD_1_oFDCAN14_f4f61916_Rx;
extern VAR(FD14_Brk_Stat, RTE_VAR_INIT) Rte_FD14_Brk_Stat_oBRAKE_FD_2_oFDCAN14_0735ec77_Rx;
extern VAR(FD14_EPS_HandsOnRecognition, RTE_VAR_INIT) Rte_FD14_EPS_HandsOnRecognition_oEPS_FD_1_oFDCAN14_58e651a9_Rx;
extern VAR(FD14_EPS_SteeringTouchStat, RTE_VAR_INIT) Rte_FD14_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cae7cd32_Rx;
extern VAR(FD14_EPS_SteeringTouq_Resp, RTE_VAR_INIT) Rte_FD14_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN14_765246ac_Rx;
extern VAR(FD14_EPS_THA_DriverTorqueOverride, RTE_VAR_INIT) Rte_FD14_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN14_2abac25d_Rx;
extern VAR(FD14_EPS_THA_SteeringTorqueResp, RTE_VAR_INIT) Rte_FD14_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN14_c35bede9_Rx;
extern VAR(FD14_EngineSts_W, RTE_VAR_INIT) Rte_FD14_EngineSts_W_oENGINE_FD_2_oFDCAN14_da6e6207_Rx;
extern VAR(FD14_ExternalBrkRequestsDisabled, RTE_VAR_INIT) Rte_FD14_ExternalBrkRequestsDisabled_oBRAKE_FD_1_oFDCAN14_3622ec06_Rx;
extern VAR(FD14_HAS_Status, RTE_VAR_INIT) Rte_FD14_HAS_Status_oADAS_FD_INFO_oFDCAN14_368cf8df_Rx;
extern VAR(FD14_LHFWheelSpeed, RTE_VAR_INIT) Rte_FD14_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d701d2d3_Rx;
extern VAR(FD14_LHF_FastPulseCounter, RTE_VAR_INIT) Rte_FD14_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_c079cbbf_Rx;
extern VAR(FD14_LHF_Spin, RTE_VAR_INIT) Rte_FD14_LHF_Spin_oBRAKE_FD_3_oFDCAN14_d2937a4c_Rx;
extern VAR(FD14_LHF_WheelSensorFailSts, RTE_VAR_INIT) Rte_FD14_LHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_3a28d00b_Rx;
extern VAR(FD14_LHRWheelSpeed, RTE_VAR_INIT) Rte_FD14_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_bbd2a610_Rx;
extern VAR(FD14_LHR_FastPulseCounter, RTE_VAR_INIT) Rte_FD14_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_129a4c4c_Rx;
extern VAR(FD14_LHR_Spin, RTE_VAR_INIT) Rte_FD14_LHR_Spin_oBRAKE_FD_3_oFDCAN14_eda6ba5c_Rx;
extern VAR(FD14_LHR_WheelSensorFailSts, RTE_VAR_INIT) Rte_FD14_LHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_7665a615_Rx;
extern VAR(FD14_LatAccelerationFailSts_BSM, RTE_VAR_INIT) Rte_FD14_LatAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_b6857dc3_Rx;
extern VAR(FD14_LatAccelerationOffset_BSM, RTE_VAR_INIT) Rte_FD14_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_045731ef_Rx;
extern VAR(FD14_LatAcceleration_BSM, RTE_VAR_INIT) Rte_FD14_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_79c02fd1_Rx;
extern VAR(FD14_LongAccelerationFailSts_BSM, RTE_VAR_INIT) Rte_FD14_LongAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_7b4ee1d6_Rx;
extern VAR(FD14_LongAccelerationOffset_BSM, RTE_VAR_INIT) Rte_FD14_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_18cdb71a_Rx;
extern VAR(FD14_LongAcceleration_BSM, RTE_VAR_INIT) Rte_FD14_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_b347f969_Rx;
extern VAR(FD14_LwsAngle, RTE_VAR_INIT) Rte_FD14_LwsAngle_oEPS_FD_1_oFDCAN14_d27eb4fc_Rx;
extern VAR(FD14_LwsAngleType, RTE_VAR_INIT) Rte_FD14_LwsAngleType_oEPS_FD_1_oFDCAN14_8f61bc22_Rx;
extern VAR(FD14_LwsSpeed, RTE_VAR_INIT) Rte_FD14_LwsSpeed_oEPS_FD_1_oFDCAN14_6930c8f0_Rx;
extern VAR(FD14_PAM_Brk_Rq_RspSts, RTE_VAR_INIT) Rte_FD14_PAM_Brk_Rq_RspSts_oBRAKE_FD_7_oFDCAN14_65c28072_Rx;
extern VAR(FD14_ParkingGearShiftReq_BSM, RTE_VAR_INIT) Rte_FD14_ParkingGearShiftReq_BSM_oBRAKE_FD_2_oFDCAN14_45df8c18_Rx;
extern VAR(FD14_ParkingInterventionSts, RTE_VAR_INIT) Rte_FD14_ParkingInterventionSts_oBRAKE_FD_2_oFDCAN14_9b11ef29_Rx;
extern VAR(FD14_PdlPosActual, RTE_VAR_INIT) Rte_FD14_PdlPosActual_oENGINE_FD_5_oFDCAN14_7bc8f3ea_Rx;
extern VAR(FD14_REF_VEH_SPEED, RTE_VAR_INIT) Rte_FD14_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN14_7bd7d6fa_Rx;
extern VAR(FD14_RHFWheelSpeed, RTE_VAR_INIT) Rte_FD14_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d6d9a235_Rx;
extern VAR(FD14_RHF_FastPulseCounter, RTE_VAR_INIT) Rte_FD14_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_aa1206ae_Rx;
extern VAR(FD14_RHF_Spin, RTE_VAR_INIT) Rte_FD14_RHF_Spin_oBRAKE_FD_3_oFDCAN14_6be6e272_Rx;
extern VAR(FD14_RHF_WheelSensorFailSts, RTE_VAR_INIT) Rte_FD14_RHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_8c24277d_Rx;
extern VAR(FD14_RHRWheelSpeed, RTE_VAR_INIT) Rte_FD14_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_ba0ad6f6_Rx;
extern VAR(FD14_RHR_FastPulseCounter, RTE_VAR_INIT) Rte_FD14_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_78f1815d_Rx;
extern VAR(FD14_RHR_Spin, RTE_VAR_INIT) Rte_FD14_RHR_Spin_oBRAKE_FD_3_oFDCAN14_54d32262_Rx;
extern VAR(FD14_RHR_WheelSensorFailSts, RTE_VAR_INIT) Rte_FD14_RHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_c0695163_Rx;
extern VAR(FD14_SPM_Lat_Ctrl_ResponseSts, RTE_VAR_INIT) Rte_FD14_SPM_Lat_Ctrl_ResponseSts_oEPS_FD_1_oFDCAN14_35f1e4d0_Rx;
extern VAR(FD14_Slope, RTE_VAR_INIT) Rte_FD14_Slope_oBRAKE_FD_2_oFDCAN14_a6806d2f_Rx;
extern VAR(FD14_Steering_Column_Torque, RTE_VAR_INIT) Rte_FD14_Steering_Column_Torque_oEPS_FD_1_oFDCAN14_485a089f_Rx;
extern VAR(FD14_THA_SteeringTouchStat, RTE_VAR_INIT) Rte_FD14_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cefbaafe_Rx;
extern VAR(FD14_VehicleSpeedVSOSig, RTE_VAR_INIT) Rte_FD14_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN14_66b2f28a_Rx;
extern VAR(FD14_VehicleSpeedVSOSig_B2, RTE_VAR_INIT) Rte_FD14_VehicleSpeedVSOSig_B2_oBRAKE2_FD_1_oFDCAN14_1870b968_Rx;
extern VAR(FD14_VehicleStandStillSts, RTE_VAR_INIT) Rte_FD14_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN14_4aa14bb7_Rx;
extern VAR(FD14_YawRateFailSts_BSM, RTE_VAR_INIT) Rte_FD14_YawRateFailSts_BSM_oBRAKE_FD_2_oFDCAN14_07cbb027_Rx;
extern VAR(FD14_YawRate_BSM, RTE_VAR_INIT) Rte_FD14_YawRate_BSM_oBRAKE_FD_2_oFDCAN14_feebc52b_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpGearPosition_GearValue;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpGearPosition_ShortTermAdjActiveFlag_b;
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpNmStateInfo_v_IsNmStateNormal_b;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpPlantMode_Status;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(APARequestSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_APARequestSts;
extern VAR(ASCM_Stat, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ASCM_Stat;
extern VAR(Brk_Stat, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Brk_Stat;
extern VAR(CM_TCH_STAT, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_STAT;
extern VAR(CM_TCH_X_COORD, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_X_COORD;
extern VAR(CM_TCH_Y_COORD, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_Y_COORD;
extern VAR(CameraDisplaySts2, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CameraDisplaySts2;
extern VAR(CmdIgnSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts;
extern VAR(DriverDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_DriverDoorSts;
extern VAR(EngineSts_W, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EngineSts_W;
extern VAR(ExternalTemperature, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ExternalTemperature;
extern VAR(Fwrd_Cam_Guidelines, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines;
extern VAR(GearEngaged, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngaged;
extern VAR(ITBM_TrlrStat, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ITBM_TrlrStat;
extern VAR(LHRDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LHRDoorSts;
extern VAR(LanguageSelection, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LanguageSelection;
extern VAR(LwsAngle, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsAngle;
extern VAR(LwsSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsSpeed;
extern VAR(PAMRequestSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PAMRequestSts;
extern VAR(PamChimeVolumeFront, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeFront;
extern VAR(PamChimeVolumeRear, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeRear;
extern VAR(PsngrDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PsngrDoorSts;
extern VAR(RHRDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHRDoorSts;
extern VAR(RHatchSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHatchSts;
extern VAR(Rear_Brk_Asst, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Rear_Brk_Asst;
extern VAR(SVC_Guidelines, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_SVC_Guidelines;
extern VAR(ShiftLeverPosition, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ShiftLeverPosition;
extern VAR(TCASERANGESTATUS, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TCASERANGESTATUS;
extern VAR(TGW_CAMERA_DISP_STAT, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT;
extern VAR(TargetGear, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TargetGear;
extern VAR(TrailerConnectionSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TrailerConnectionSts;
extern VAR(VIN_MSG, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_MSG;
extern VAR(VehicleSpeedVSOSig, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VehicleSpeedVSOSig;
extern VAR(FD14_EPS_HandsOnRecognition, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition;
extern VAR(FD14_ESS_ENG_ST_W, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W;
extern VAR(FD14_LHFWheelSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHFWheelSpeed;
extern VAR(FD14_LHF_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter;
extern VAR(FD14_LHF_Spin, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_Spin;
extern VAR(FD14_LHF_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts;
extern VAR(FD14_LHRWheelSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHRWheelSpeed;
extern VAR(FD14_LHR_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter;
extern VAR(FD14_LHR_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts;
extern VAR(FD14_LatAccelerationFailSts_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM;
extern VAR(FD14_LatAcceleration_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM;
extern VAR(FD14_LongAccelerationFailSts_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM;
extern VAR(FD14_LongAcceleration_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM;
extern VAR(FD14_LwsAngle, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngle;
extern VAR(FD14_LwsAngleType, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngleType;
extern VAR(FD14_LwsSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsSpeed;
extern VAR(FD14_PAM_Brk_Rq_RspSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts;
extern VAR(FD14_PdlPosActual, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PdlPosActual;
extern VAR(FD14_RHFWheelSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHFWheelSpeed;
extern VAR(FD14_RHF_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter;
extern VAR(FD14_RHF_Spin, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_Spin;
extern VAR(FD14_RHF_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts;
extern VAR(FD14_RHRWheelSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHRWheelSpeed;
extern VAR(FD14_RHR_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter;
extern VAR(FD14_RHR_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts;
extern VAR(FD14_SPM_Lat_Ctrl_ResponseSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts;
extern VAR(FD14_Steering_Column_Torque, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_Steering_Column_Torque;
extern VAR(FD14_VehicleSpeedVSOSig, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig;
extern VAR(FD14_VehicleSpeedVSOSig_B2, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2;
extern VAR(FD14_VehicleStandStillSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleStandStillSts;
extern VAR(FD14_YawRateFailSts_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM;
extern VAR(FD14_YawRate_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRate_BSM;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_InvalidValueFlag;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_MissingMessageFlag;
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpPAM2BTIpcTxStatus_IpcTxDone;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Fullautomaticparking;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_PAMConfig_u8;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Parkwithstop_u8;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Trailerhitchassist_u8;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_TyreSz_u16;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PpToSwcSafeFD02Rx_APARequestSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_ASCM_Stat (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_ASCM_SysFail (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_Active_Park_Mode (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_Active_Park_Prox_Chime (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_Backup_Cam_Delay (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_Brk_Stat (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_CM_TCH_STAT (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_CM_TCH_X_COORD (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_CM_TCH_Y_COORD (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_CameraDisplaySts2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_CmdIgnSts (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_DriverDoorSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_DynamicGrid (TRUE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_ECM_THA_Resp (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_ECM_TRSC_Resp (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_EPS_SteeringTouchStat (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_EPS_SteeringTouq_Resp (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_EPS_THA_DriverTorqueOverride (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_EPS_THA_SteeringTorqueResp (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_ESS_ENG_ST_W (15U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_EngineSts_W (3U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_ExternalTemperature (170U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_FL_Lvl (254U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_FL_Lvl_Adj (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_FR_Lvl (254U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_FR_Lvl_Adj (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_FT_PAMRequestSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_GearEngaged (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_GearEngagedForDisplay (31U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_HAS_Status_C2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_HU_TRSC_EnableBtn_Sts (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_ITBM_TrlrStat (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_LHRDoorSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_LanguageSelection (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_LatAcceleration_BSM (4095U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_LongAcceleration_BSM (4095U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_LwsAngle (7200U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_LwsAngleType (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_LwsSpeed (2000U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_MRM_STATUS_C2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_PAMRequestSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_PamChimeVolumeFront (1U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_PamChimeVolumeRear (1U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_PdlPosActual (3U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_PsngrDoorSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_RHRDoorSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_RHatchSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_RL_Lvl (254U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_RL_Lvl_Adj (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_RR_Lvl (254U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_RR_Lvl_Adj (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_Rear_Brk_Asst (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_SVC_Guidelines (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_ShiftLeverPosition (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_ShiftLeverPositionReq (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_Shifter_ADAS_Inhibit (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_TCASERANGESTATUS (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_THA_SteeringTouchStat (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_TRANS_ADAS_Inhibit (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_TargetGear (15U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_TrailerConnectionSts (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_TransmissionSailingSts (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_VIN_MSG (3U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_VehicleSpeedVSOSig (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Rx_YawRate_BSM (4095U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_ACC_Systemsts (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_BSM_THA_Brk_Resp (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_BrkPdl_Stat (3U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_BrkTrq (10922U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_BrkTrq_Driver (10922U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_Brk_Stat (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_ECM_THA_Resp (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_ECM_TRSC_Resp (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_EPBSts (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_EPS_SteeringTouchStat (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_EPS_SteeringTouq_Resp (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_EPS_THA_DriverTorqueOverride (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_EPS_THA_SteeringTorqueResp (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W (15U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_EngineSts_W (3U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_ExternalBrkRequestsDisabled (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_HAS_Status (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LHFWheelSpeed (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LHF_Spin (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LHRWheelSpeed (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LHR_Spin (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LatAccelerationOffset_BSM (255U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM (4095U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LongAccelerationOffset_BSM (255U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM (4095U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LwsAngle (7200U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LwsAngleType (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_LwsSpeed (2000U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_ParkingGearShiftReq_BSM (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_ParkingInterventionSts (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_PdlPosActual (3U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_REF_VEH_SPEED (1023U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_RHFWheelSpeed (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_RHF_Spin (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_RHRWheelSpeed (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_RHR_Spin (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_Slope (100U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_Steering_Column_Torque (1024U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_THA_SteeringTouchStat (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_VehicleStandStillSts (1U)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD14Rx_FD14_YawRate_BSM (4095U)
#  define Rte_InitValue_PpVIN_MessageFault_VIN_InvalidValueFlag (FALSE)
#  define Rte_InitValue_PpVIN_MessageFault_VIN_MissingMessageFlag (FALSE)
#  define Rte_InitValue_RpDtcB12852AData_v_DtcData_u8 (0U)
#  define Rte_InitValue_RpFailSafeReaction_State (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_APARequestSts (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_ASCM_Stat (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_ASCM_SysFail (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_Active_Park_Mode (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_Active_Park_Prox_Chime (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_Backup_Cam_Delay (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_Brk_Stat (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_CM_TCH_STAT (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_CM_TCH_X_COORD (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_CM_TCH_Y_COORD (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_CameraDisplaySts2 (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_CmdIgnSts (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_DriverDoorSts (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_DynamicGrid (TRUE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_ECM_THA_Resp (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_ECM_TRSC_Resp (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_EPS_SteeringTouchStat (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_EPS_SteeringTouq_Resp (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_EPS_THA_DriverTorqueOverride (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_EPS_THA_SteeringTorqueResp (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_ESS_ENG_ST_W (15U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_EngineSts_W (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_ExternalTemperature (170U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_FL_Lvl (254U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_FL_Lvl_Adj (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_FR_Lvl (254U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_FR_Lvl_Adj (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_FT_PAMRequestSts (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_GearEngaged (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_GearEngagedForDisplay (31U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_HAS_Status_C2 (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_ITBM_TrlrStat (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_LHRDoorSts (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_LanguageSelection (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_LatAcceleration_BSM (4095U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_LongAcceleration_BSM (4095U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_LwsAngle (7200U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_LwsAngleType (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_LwsSpeed (2000U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_MRM_STATUS_C2 (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_PAMRequestSts (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_PamChimeVolumeFront (1U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_PamChimeVolumeRear (1U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_PdlPosActual (3U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_PsngrDoorSts (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_RHRDoorSts (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_RHatchSts (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_RL_Lvl (254U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_RL_Lvl_Adj (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_RR_Lvl (254U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_RR_Lvl_Adj (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_Rear_Brk_Asst (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_SVC_Guidelines (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_ShiftLeverPosition (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_ShiftLeverPositionReq (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_Shifter_ADAS_Inhibit (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_TCASERANGESTATUS (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_THA_SteeringTouchStat (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_TRANS_ADAS_Inhibit (FALSE)
#  define Rte_InitValue_RpFromComSafeFD02Rx_TargetGear (15U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_TrailerConnectionSts (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_TransmissionSailingSts (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_VIN_MSG (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_VehicleSpeedVSOSig (0U)
#  define Rte_InitValue_RpFromComSafeFD02Rx_YawRate_BSM (4095U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_ACC_Systemsts (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_BrkPdl_Stat (3U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_BrkTrq (10922U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_BrkTrq_Driver (10922U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_Brk_Stat (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_EPBSts (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_EPS_HandsOnRecognition (FALSE)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_EPS_SteeringTouchStat (FALSE)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_EPS_SteeringTouq_Resp (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_EPS_THA_DriverTorqueOverride (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_EPS_THA_SteeringTorqueResp (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W (15U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_EngineSts_W (3U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_ExternalBrkRequestsDisabled (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_HAS_Status (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LHFWheelSpeed (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LHF_FastPulseCounter (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LHF_Spin (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LHF_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LHRWheelSpeed (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LHR_FastPulseCounter (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LHR_Spin (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LHR_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LatAccelerationFailSts_BSM (FALSE)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LatAccelerationOffset_BSM (255U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LatAcceleration_BSM (4095U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LongAccelerationFailSts_BSM (FALSE)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LongAccelerationOffset_BSM (255U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LongAcceleration_BSM (4095U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LwsAngle (7200U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LwsAngleType (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_LwsSpeed (2000U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_ParkingGearShiftReq_BSM (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_ParkingInterventionSts (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_PdlPosActual (3U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_REF_VEH_SPEED (1023U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_RHFWheelSpeed (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_RHF_FastPulseCounter (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_RHF_Spin (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_RHF_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_RHRWheelSpeed (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_RHR_FastPulseCounter (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_RHR_Spin (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_RHR_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_Slope (100U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_Steering_Column_Torque (1024U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_THA_SteeringTouchStat (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_VehicleSpeedVSOSig (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2 (0U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_VehicleStandStillSts (1U)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_YawRateFailSts_BSM (FALSE)
#  define Rte_InitValue_RpFromComSafeFD14Rx_FD14_YawRate_BSM (4095U)
#  define Rte_InitValue_RpGearPosition_GearValue (0U)
#  define Rte_InitValue_RpGearPosition_ShortTermAdjActiveFlag_b (FALSE)
#  define Rte_InitValue_RpNmStateInfo_v_IsNmStateNormal_b (FALSE)
#  define Rte_InitValue_RpPlantMode_Status (0U)
# endif


# define RTE_START_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_R_SSM_2_State_State_2_0(P2VAR(SSM_2_0_CoreStatus, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_R_SSM_2_State_State_2_1(P2VAR(SSM_2_1_CoreStatus, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_R_SSM_QNXState_State_QNX(P2VAR(SSM_QNX_CoreStatus, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_R_SystemState_SystemState(P2VAR(SSM_SystemState, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpAPSMPAOut_TbAP_APSMPAOut_t(P2VAR(TbAP_APSMPAOut_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(P2VAR(IFOD_Outputs_CVPAMFDData_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(P2VAR(TbAP_DriveAssistStatOut_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(P2VAR(TbTHASmVc_FeatureOutputs_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_APARequestSts(P2VAR(APARequestSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_Stat(P2VAR(ASCM_Stat, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_SysFail(P2VAR(ASCM_SysFail, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Mode(P2VAR(Active_Park_Mode, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Prox_Chime(P2VAR(Active_Park_Prox_Chime, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Backup_Cam_Delay(P2VAR(Backup_Cam_Delay, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_STAT(P2VAR(CM_TCH_STAT, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_X_COORD(P2VAR(CM_TCH_X_COORD, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_Y_COORD(P2VAR(CM_TCH_Y_COORD, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CameraDisplaySts2(P2VAR(CameraDisplaySts2, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CmdIgnSts(P2VAR(CmdIgnSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_DriverDoorSts(P2VAR(DriverDoorSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_THA_Resp(P2VAR(ECM_THA_Resp, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_TRSC_Resp(P2VAR(ECM_TRSC_Resp, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FT_PAMRequestSts(P2VAR(FT_PAMRequestSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines(P2VAR(Fwrd_Cam_Guidelines, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_GearEngaged(P2VAR(GearEngaged, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts(P2VAR(HU_TRSC_EnableBtn_Sts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ITBM_TrlrStat(P2VAR(ITBM_TrlrStat, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LHRDoorSts(P2VAR(LHRDoorSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LanguageSelection(P2VAR(LanguageSelection, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PAMRequestSts(P2VAR(PAMRequestSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeFront(P2VAR(PamChimeVolumeFront, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeRear(P2VAR(PamChimeVolumeRear, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PsngrDoorSts(P2VAR(PsngrDoorSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHRDoorSts(P2VAR(RHRDoorSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHatchSts(P2VAR(RHatchSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Rear_Brk_Asst(P2VAR(Rear_Brk_Asst, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_SVC_Guidelines(P2VAR(SVC_Guidelines, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPosition(P2VAR(ShiftLeverPosition, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPositionReq(P2VAR(ShiftLeverPositionReq, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TCASERANGESTATUS(P2VAR(TCASERANGESTATUS, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT(P2VAR(TGW_CAMERA_DISP_STAT, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_VIN_DATA(P2VAR(uint8, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_VIN_DATA(P2VAR(VIN_DATA, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp(P2VAR(FD14_BSM_THA_Brk_Resp, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp(P2VAR(FD14_ECM_THA_Resp, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp(P2VAR(FD14_ECM_TRSC_Resp, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPBSts(P2VAR(FD14_EPBSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp(P2VAR(FD14_ESC_TRSC_Brk_Resp, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W(P2VAR(FD14_ESS_ENG_ST_W, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(P2VAR(ME_Proxi_MPU1_0_to_MCU1_0_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpProxiConfigData_ProxiData(P2VAR(ME_Hydra2defs_S_CodingTableExt_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpSafeGuardPAStateOut_TbAP_PAStateOut_t(P2VAR(TbAP_PAStateOut_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpSafeGuardSvsToVCAN_SvsToVCAN_t(P2VAR(SvsToVCAN_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpTRSC_ME_VehOut_TRSC_t(P2VAR(ME_VehOut_TRSC_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpVcanRxQM_ME_VehInp_to_IpcSignals_QM_t(P2VAR(ME_VehInp_to_IpcSignals_QM_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_DATA(P2CONST(uint8, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_DATA(P2CONST(VIN_DATA, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_SWC_SafeVCANRx_PpMode_VehicleSpeedCheck_Mode(uint8 nextMode);

# define RTE_STOP_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_SSM_2_State_State_2_0 Rte_Read_SWC_SafeVCANRx_R_SSM_2_State_State_2_0
#  define Rte_Read_R_SSM_2_State_State_2_1 Rte_Read_SWC_SafeVCANRx_R_SSM_2_State_State_2_1
#  define Rte_Read_R_SSM_QNXState_State_QNX Rte_Read_SWC_SafeVCANRx_R_SSM_QNXState_State_QNX
#  define Rte_Read_R_SystemState_SystemState Rte_Read_SWC_SafeVCANRx_R_SystemState_SystemState
#  define Rte_Read_RpAPSMPAOut_TbAP_APSMPAOut_t Rte_Read_SWC_SafeVCANRx_RpAPSMPAOut_TbAP_APSMPAOut_t
#  define Rte_Read_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t Rte_Read_SWC_SafeVCANRx_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t
#  define Rte_Read_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t Rte_Read_SWC_SafeVCANRx_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t
#  define Rte_Read_RpDtcB12852AData_v_DtcData_u8 Rte_Read_SWC_SafeVCANRx_RpDtcB12852AData_v_DtcData_u8
#  define Rte_Read_SWC_SafeVCANRx_RpDtcB12852AData_v_DtcData_u8(data) (*(data) = Rte_SWC_DTCMgr_PpDtcB12852AData_v_DtcData_u8, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFailSafeReaction_State Rte_Read_SWC_SafeVCANRx_RpFailSafeReaction_State
#  define Rte_Read_SWC_SafeVCANRx_RpFailSafeReaction_State(data) (*(data) = Rte_SWC_RIDMgr_PpFailSafeReaction_State, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t Rte_Read_SWC_SafeVCANRx_RpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t
#  define Rte_Read_RpFromComSafeFD02Rx_APARequestSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_APARequestSts
#  define Rte_Read_RpFromComSafeFD02Rx_ASCM_Stat Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_Stat
#  define Rte_Read_RpFromComSafeFD02Rx_ASCM_SysFail Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_SysFail
#  define Rte_Read_RpFromComSafeFD02Rx_Active_Park_Mode Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Mode
#  define Rte_Read_RpFromComSafeFD02Rx_Active_Park_Prox_Chime Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Prox_Chime
#  define Rte_Read_RpFromComSafeFD02Rx_Backup_Cam_Delay Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Backup_Cam_Delay
#  define Rte_Read_RpFromComSafeFD02Rx_Brk_Stat Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Brk_Stat
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Brk_Stat(data) (*(data) = Rte_Brk_Stat_oBRAKE_FD_2_oFDCAN2_1b647924_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_CM_TCH_STAT Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_STAT
#  define Rte_Read_RpFromComSafeFD02Rx_CM_TCH_X_COORD Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_X_COORD
#  define Rte_Read_RpFromComSafeFD02Rx_CM_TCH_Y_COORD Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_Y_COORD
#  define Rte_Read_RpFromComSafeFD02Rx_CameraDisplaySts2 Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CameraDisplaySts2
#  define Rte_Read_RpFromComSafeFD02Rx_CmdIgnSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CmdIgnSts
#  define Rte_Read_RpFromComSafeFD02Rx_DriverDoorSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_DriverDoorSts
#  define Rte_Read_RpFromComSafeFD02Rx_DynamicGrid Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_DynamicGrid
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_DynamicGrid(data) (*(data) = Rte_DynamicGrid_oIPC_VEHICLE_SETUP_oFDCAN2_8defe0e1_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_ECM_THA_Resp Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_THA_Resp
#  define Rte_Read_RpFromComSafeFD02Rx_ECM_TRSC_Resp Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_TRSC_Resp
#  define Rte_Read_RpFromComSafeFD02Rx_EPS_SteeringTouchStat Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_EPS_SteeringTouchStat
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_EPS_SteeringTouchStat(data) (*(data) = Rte_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN2_70168af6_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_EPS_SteeringTouq_Resp Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_EPS_SteeringTouq_Resp
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_EPS_SteeringTouq_Resp(data) (*(data) = Rte_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN2_a31e0e47_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_EPS_THA_DriverTorqueOverride Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_EPS_THA_DriverTorqueOverride
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_EPS_THA_DriverTorqueOverride(data) (*(data) = Rte_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN2_0e3a0a14_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_EPS_THA_SteeringTorqueResp Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_EPS_THA_SteeringTorqueResp
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_EPS_THA_SteeringTorqueResp(data) (*(data) = Rte_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN2_2f8c0396_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_ESS_ENG_ST_W Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ESS_ENG_ST_W
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ESS_ENG_ST_W(data) (*(data) = Rte_ESS_ENG_ST_W_oENGINE_FD_2_oFDCAN2_b1b6db89_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_EngineSts_W Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_EngineSts_W
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_EngineSts_W(data) (*(data) = Rte_EngineSts_W_oENGINE_FD_2_oFDCAN2_7417ef03_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_ExternalTemperature Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ExternalTemperature
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ExternalTemperature(data) (*(data) = Rte_ExternalTemperature_oBCM_FD_9_oFDCAN2_fd16cd2c_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_FL_Lvl Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FL_Lvl
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FL_Lvl(data) (*(data) = Rte_FL_Lvl_oASCM_FD_1_oFDCAN2_724f5049_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_FL_Lvl_Adj Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FL_Lvl_Adj
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FL_Lvl_Adj(data) (*(data) = Rte_FL_Lvl_Adj_oASCM_FD_1_oFDCAN2_959485e3_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_FR_Lvl Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FR_Lvl
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FR_Lvl(data) (*(data) = Rte_FR_Lvl_oASCM_FD_1_oFDCAN2_6f14419a_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_FR_Lvl_Adj Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FR_Lvl_Adj
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FR_Lvl_Adj(data) (*(data) = Rte_FR_Lvl_Adj_oASCM_FD_1_oFDCAN2_86d8b295_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_FT_PAMRequestSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FT_PAMRequestSts
#  define Rte_Read_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines
#  define Rte_Read_RpFromComSafeFD02Rx_GearEngaged Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_GearEngaged
#  define Rte_Read_RpFromComSafeFD02Rx_GearEngagedForDisplay Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_GearEngagedForDisplay
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_GearEngagedForDisplay(data) (*(data) = Rte_GearEngagedForDisplay_oTRANSM_FD_2_oFDCAN2_375443ce_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_HAS_Status_C2 Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_HAS_Status_C2
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_HAS_Status_C2(data) (*(data) = Rte_HAS_Status_C2_oADAS_FD_INFO_C2_oFDCAN2_5f0dae63_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts
#  define Rte_Read_RpFromComSafeFD02Rx_ITBM_TrlrStat Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ITBM_TrlrStat
#  define Rte_Read_RpFromComSafeFD02Rx_LHRDoorSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LHRDoorSts
#  define Rte_Read_RpFromComSafeFD02Rx_LanguageSelection Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LanguageSelection
#  define Rte_Read_RpFromComSafeFD02Rx_LatAcceleration_BSM Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LatAcceleration_BSM
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LatAcceleration_BSM(data) (*(data) = Rte_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_318e470e_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_LongAcceleration_BSM Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LongAcceleration_BSM
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LongAcceleration_BSM(data) (*(data) = Rte_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_f132a23a_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_LwsAngle Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LwsAngle
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LwsAngle(data) (*(data) = Rte_LwsAngle_oEPS_FD_1_oFDCAN2_4dcc502d_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_LwsAngleType Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LwsAngleType
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LwsAngleType(data) (*(data) = Rte_LwsAngleType_oEPS_FD_1_oFDCAN2_aea1ae81_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_LwsSpeed Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LwsSpeed
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LwsSpeed(data) (*(data) = Rte_LwsSpeed_oEPS_FD_1_oFDCAN2_08f75f98_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_MRM_STATUS_C2 Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_MRM_STATUS_C2
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_MRM_STATUS_C2(data) (*(data) = Rte_MRM_STATUS_C2_oADAS_FD_INFO_C2_oFDCAN2_8ba84d40_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_PAMRequestSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PAMRequestSts
#  define Rte_Read_RpFromComSafeFD02Rx_PamChimeVolumeFront Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeFront
#  define Rte_Read_RpFromComSafeFD02Rx_PamChimeVolumeRear Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeRear
#  define Rte_Read_RpFromComSafeFD02Rx_PdlPosActual Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PdlPosActual
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PdlPosActual(data) (*(data) = Rte_PdlPosActual_oENGINE_FD_5_oFDCAN2_743309cb_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_PsngrDoorSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PsngrDoorSts
#  define Rte_Read_RpFromComSafeFD02Rx_RHRDoorSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHRDoorSts
#  define Rte_Read_RpFromComSafeFD02Rx_RHatchSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHatchSts
#  define Rte_Read_RpFromComSafeFD02Rx_RL_Lvl Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RL_Lvl
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RL_Lvl(data) (*(data) = Rte_RL_Lvl_oASCM_FD_1_oFDCAN2_d1e53ddc_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_RL_Lvl_Adj Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RL_Lvl_Adj
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RL_Lvl_Adj(data) (*(data) = Rte_RL_Lvl_Adj_oASCM_FD_1_oFDCAN2_44326a37_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_RR_Lvl Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RR_Lvl
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RR_Lvl(data) (*(data) = Rte_RR_Lvl_oASCM_FD_1_oFDCAN2_ccbe2c0f_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_RR_Lvl_Adj Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RR_Lvl_Adj
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RR_Lvl_Adj(data) (*(data) = Rte_RR_Lvl_Adj_oASCM_FD_1_oFDCAN2_577e5d41_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_Rear_Brk_Asst Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Rear_Brk_Asst
#  define Rte_Read_RpFromComSafeFD02Rx_SVC_Guidelines Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_SVC_Guidelines
#  define Rte_Read_RpFromComSafeFD02Rx_ShiftLeverPosition Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPosition
#  define Rte_Read_RpFromComSafeFD02Rx_ShiftLeverPositionReq Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPositionReq
#  define Rte_Read_RpFromComSafeFD02Rx_Shifter_ADAS_Inhibit Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Shifter_ADAS_Inhibit
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Shifter_ADAS_Inhibit(data) (*(data) = Rte_Shifter_ADAS_Inhibit_oAGSM_FD_2_oFDCAN2_633e22f5_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_TCASERANGESTATUS Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TCASERANGESTATUS
#  define Rte_Read_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT
#  define Rte_Read_RpFromComSafeFD02Rx_THA_SteeringTouchStat Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_THA_SteeringTouchStat
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_THA_SteeringTouchStat(data) (*(data) = Rte_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN2_b7575370_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_TRANS_ADAS_Inhibit Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TRANS_ADAS_Inhibit
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TRANS_ADAS_Inhibit(data) (*(data) = Rte_TRANS_ADAS_Inhibit_oTRANSM_FD_1_oFDCAN2_6ec0c415_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_TargetGear Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TargetGear
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TargetGear(data) (*(data) = Rte_TargetGear_oTRANSM_FD_1_oFDCAN2_b75950f9_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_TrailerConnectionSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TrailerConnectionSts
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TrailerConnectionSts(data) (*(data) = Rte_TrailerConnectionSts_oBCM_FD_27_oFDCAN2_e828ec43_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_TransmissionSailingSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TransmissionSailingSts
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TransmissionSailingSts(data) (*(data) = Rte_TransmissionSailingSts_oTRANSM_FD_1_oFDCAN2_86af8834_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_VIN_DATA Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_VIN_DATA
#  define Rte_Read_RpFromComSafeFD02Rx_VIN_MSG Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_VIN_MSG
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_VIN_MSG(data) (*(data) = Rte_VIN_MSG_oVIN_oFDCAN2_f39912b4_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_VehicleSpeedVSOSig Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_VehicleSpeedVSOSig
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_VehicleSpeedVSOSig(data) (*(data) = Rte_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN2_53fecdc7_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD02Rx_YawRate_BSM Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_YawRate_BSM
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_YawRate_BSM(data) (*(data) = Rte_YawRate_BSM_oBRAKE_FD_2_oFDCAN2_64569af1_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_ACC_Systemsts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ACC_Systemsts
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ACC_Systemsts(data) (*(data) = Rte_FD14_ACC_Systemsts_oADAS_FD_INFO_oFDCAN14_2086cf20_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_BrkPdl_Stat Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BrkPdl_Stat
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BrkPdl_Stat(data) (*(data) = Rte_FD14_BrkPdl_Stat_oBRAKE_FD_7_oFDCAN14_d494c4ed_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_BrkTrq Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BrkTrq
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BrkTrq(data) (*(data) = Rte_FD14_BrkTrq_oBRAKE_FD_1_oFDCAN14_a585a712_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_BrkTrq_Driver Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BrkTrq_Driver
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BrkTrq_Driver(data) (*(data) = Rte_FD14_BrkTrq_Driver_oBRAKE_FD_1_oFDCAN14_f4f61916_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_Brk_Stat Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_Brk_Stat
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_Brk_Stat(data) (*(data) = Rte_FD14_Brk_Stat_oBRAKE_FD_2_oFDCAN14_0735ec77_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_EPBSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPBSts
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_EPS_HandsOnRecognition Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPS_HandsOnRecognition
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPS_HandsOnRecognition(data) (*(data) = Rte_FD14_EPS_HandsOnRecognition_oEPS_FD_1_oFDCAN14_58e651a9_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_EPS_SteeringTouchStat Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPS_SteeringTouchStat
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPS_SteeringTouchStat(data) (*(data) = Rte_FD14_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cae7cd32_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_EPS_SteeringTouq_Resp Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPS_SteeringTouq_Resp
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPS_SteeringTouq_Resp(data) (*(data) = Rte_FD14_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN14_765246ac_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_EPS_THA_DriverTorqueOverride Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPS_THA_DriverTorqueOverride
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPS_THA_DriverTorqueOverride(data) (*(data) = Rte_FD14_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN14_2abac25d_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_EPS_THA_SteeringTorqueResp Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPS_THA_SteeringTorqueResp
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPS_THA_SteeringTorqueResp(data) (*(data) = Rte_FD14_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN14_c35bede9_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_EngineSts_W Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EngineSts_W
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EngineSts_W(data) (*(data) = Rte_FD14_EngineSts_W_oENGINE_FD_2_oFDCAN14_da6e6207_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_ExternalBrkRequestsDisabled Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ExternalBrkRequestsDisabled
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ExternalBrkRequestsDisabled(data) (*(data) = Rte_FD14_ExternalBrkRequestsDisabled_oBRAKE_FD_1_oFDCAN14_3622ec06_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_HAS_Status Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_HAS_Status
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_HAS_Status(data) (*(data) = Rte_FD14_HAS_Status_oADAS_FD_INFO_oFDCAN14_368cf8df_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LHFWheelSpeed Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHFWheelSpeed
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHFWheelSpeed(data) (*(data) = Rte_FD14_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d701d2d3_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LHF_FastPulseCounter Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHF_FastPulseCounter
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHF_FastPulseCounter(data) (*(data) = Rte_FD14_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_c079cbbf_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LHF_Spin Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHF_Spin
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHF_Spin(data) (*(data) = Rte_FD14_LHF_Spin_oBRAKE_FD_3_oFDCAN14_d2937a4c_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LHF_WheelSensorFailSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHF_WheelSensorFailSts
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHF_WheelSensorFailSts(data) (*(data) = Rte_FD14_LHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_3a28d00b_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LHRWheelSpeed Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHRWheelSpeed
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHRWheelSpeed(data) (*(data) = Rte_FD14_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_bbd2a610_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LHR_FastPulseCounter Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHR_FastPulseCounter
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHR_FastPulseCounter(data) (*(data) = Rte_FD14_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_129a4c4c_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LHR_Spin Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHR_Spin
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHR_Spin(data) (*(data) = Rte_FD14_LHR_Spin_oBRAKE_FD_3_oFDCAN14_eda6ba5c_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LHR_WheelSensorFailSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHR_WheelSensorFailSts
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LHR_WheelSensorFailSts(data) (*(data) = Rte_FD14_LHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_7665a615_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LatAccelerationFailSts_BSM Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LatAccelerationFailSts_BSM
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LatAccelerationFailSts_BSM(data) (*(data) = Rte_FD14_LatAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_b6857dc3_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LatAccelerationOffset_BSM Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LatAccelerationOffset_BSM
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LatAccelerationOffset_BSM(data) (*(data) = Rte_FD14_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_045731ef_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LatAcceleration_BSM Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LatAcceleration_BSM
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LatAcceleration_BSM(data) (*(data) = Rte_FD14_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_79c02fd1_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LongAccelerationFailSts_BSM Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LongAccelerationFailSts_BSM
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LongAccelerationFailSts_BSM(data) (*(data) = Rte_FD14_LongAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_7b4ee1d6_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LongAccelerationOffset_BSM Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LongAccelerationOffset_BSM
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LongAccelerationOffset_BSM(data) (*(data) = Rte_FD14_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_18cdb71a_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LongAcceleration_BSM Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LongAcceleration_BSM
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LongAcceleration_BSM(data) (*(data) = Rte_FD14_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_b347f969_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LwsAngle Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LwsAngle
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LwsAngle(data) (*(data) = Rte_FD14_LwsAngle_oEPS_FD_1_oFDCAN14_d27eb4fc_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LwsAngleType Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LwsAngleType
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LwsAngleType(data) (*(data) = Rte_FD14_LwsAngleType_oEPS_FD_1_oFDCAN14_8f61bc22_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_LwsSpeed Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LwsSpeed
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_LwsSpeed(data) (*(data) = Rte_FD14_LwsSpeed_oEPS_FD_1_oFDCAN14_6930c8f0_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts(data) (*(data) = Rte_FD14_PAM_Brk_Rq_RspSts_oBRAKE_FD_7_oFDCAN14_65c28072_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_ParkingGearShiftReq_BSM Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ParkingGearShiftReq_BSM
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ParkingGearShiftReq_BSM(data) (*(data) = Rte_FD14_ParkingGearShiftReq_BSM_oBRAKE_FD_2_oFDCAN14_45df8c18_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_ParkingInterventionSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ParkingInterventionSts
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ParkingInterventionSts(data) (*(data) = Rte_FD14_ParkingInterventionSts_oBRAKE_FD_2_oFDCAN14_9b11ef29_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_PdlPosActual Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_PdlPosActual
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_PdlPosActual(data) (*(data) = Rte_FD14_PdlPosActual_oENGINE_FD_5_oFDCAN14_7bc8f3ea_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_REF_VEH_SPEED Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_REF_VEH_SPEED
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_REF_VEH_SPEED(data) (*(data) = Rte_FD14_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN14_7bd7d6fa_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_RHFWheelSpeed Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHFWheelSpeed
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHFWheelSpeed(data) (*(data) = Rte_FD14_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d6d9a235_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_RHF_FastPulseCounter Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHF_FastPulseCounter
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHF_FastPulseCounter(data) (*(data) = Rte_FD14_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_aa1206ae_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_RHF_Spin Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHF_Spin
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHF_Spin(data) (*(data) = Rte_FD14_RHF_Spin_oBRAKE_FD_3_oFDCAN14_6be6e272_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_RHF_WheelSensorFailSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHF_WheelSensorFailSts
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHF_WheelSensorFailSts(data) (*(data) = Rte_FD14_RHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_8c24277d_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_RHRWheelSpeed Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHRWheelSpeed
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHRWheelSpeed(data) (*(data) = Rte_FD14_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_ba0ad6f6_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_RHR_FastPulseCounter Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHR_FastPulseCounter
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHR_FastPulseCounter(data) (*(data) = Rte_FD14_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_78f1815d_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_RHR_Spin Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHR_Spin
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHR_Spin(data) (*(data) = Rte_FD14_RHR_Spin_oBRAKE_FD_3_oFDCAN14_54d32262_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_RHR_WheelSensorFailSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHR_WheelSensorFailSts
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_RHR_WheelSensorFailSts(data) (*(data) = Rte_FD14_RHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_c0695163_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts(data) (*(data) = Rte_FD14_SPM_Lat_Ctrl_ResponseSts_oEPS_FD_1_oFDCAN14_35f1e4d0_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_Slope Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_Slope
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_Slope(data) (*(data) = Rte_FD14_Slope_oBRAKE_FD_2_oFDCAN14_a6806d2f_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_Steering_Column_Torque Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_Steering_Column_Torque
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_Steering_Column_Torque(data) (*(data) = Rte_FD14_Steering_Column_Torque_oEPS_FD_1_oFDCAN14_485a089f_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_THA_SteeringTouchStat Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_THA_SteeringTouchStat
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_THA_SteeringTouchStat(data) (*(data) = Rte_FD14_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cefbaafe_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_VehicleSpeedVSOSig Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_VehicleSpeedVSOSig
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_VehicleSpeedVSOSig(data) (*(data) = Rte_FD14_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN14_66b2f28a_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2 Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2(data) (*(data) = Rte_FD14_VehicleSpeedVSOSig_B2_oBRAKE2_FD_1_oFDCAN14_1870b968_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_VehicleStandStillSts Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_VehicleStandStillSts
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_VehicleStandStillSts(data) (*(data) = Rte_FD14_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN14_4aa14bb7_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_YawRateFailSts_BSM Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_YawRateFailSts_BSM
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_YawRateFailSts_BSM(data) (*(data) = Rte_FD14_YawRateFailSts_BSM_oBRAKE_FD_2_oFDCAN14_07cbb027_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComSafeFD14Rx_FD14_YawRate_BSM Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_YawRate_BSM
#  define Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_YawRate_BSM(data) (*(data) = Rte_FD14_YawRate_BSM_oBRAKE_FD_2_oFDCAN14_feebc52b_Rx, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpGearPosition_GearValue Rte_Read_SWC_SafeVCANRx_RpGearPosition_GearValue
#  define Rte_Read_SWC_SafeVCANRx_RpGearPosition_GearValue(data) (*(data) = Rte_SWC_DIDMgr_PpGearPosition_GearValue, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpGearPosition_ShortTermAdjActiveFlag_b Rte_Read_SWC_SafeVCANRx_RpGearPosition_ShortTermAdjActiveFlag_b
#  define Rte_Read_SWC_SafeVCANRx_RpGearPosition_ShortTermAdjActiveFlag_b(data) (*(data) = Rte_SWC_DIDMgr_PpGearPosition_ShortTermAdjActiveFlag_b, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t Rte_Read_SWC_SafeVCANRx_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t
#  define Rte_Read_RpNmStateInfo_v_IsNmStateNormal_b Rte_Read_SWC_SafeVCANRx_RpNmStateInfo_v_IsNmStateNormal_b
#  define Rte_Read_SWC_SafeVCANRx_RpNmStateInfo_v_IsNmStateNormal_b(data) (*(data) = Rte_CDD_GenericBswM_PpNmStateInfo_v_IsNmStateNormal_b, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpPAM2BTIpcTxStatus_IpcTxDone Rte_Read_SWC_SafeVCANRx_RpPAM2BTIpcTxStatus_IpcTxDone
#  define Rte_Read_SWC_SafeVCANRx_RpPAM2BTIpcTxStatus_IpcTxDone(data) (*(data) = Rte_CDD_IPCHandler_PpPAM2BTIpcTxStatus_IpcTxDone, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpPlantMode_Status Rte_Read_SWC_SafeVCANRx_RpPlantMode_Status
#  define Rte_Read_SWC_SafeVCANRx_RpPlantMode_Status(data) (*(data) = Rte_SWC_RIDMgr_PpPlantMode_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpProxiConfigData_ProxiData Rte_Read_SWC_SafeVCANRx_RpProxiConfigData_ProxiData
#  define Rte_Read_RpProxiToSWC_Fullautomaticparking Rte_Read_SWC_SafeVCANRx_RpProxiToSWC_Fullautomaticparking
#  define Rte_Read_SWC_SafeVCANRx_RpProxiToSWC_Fullautomaticparking(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Fullautomaticparking, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpProxiToSWC_PAMConfig_u8 Rte_Read_SWC_SafeVCANRx_RpProxiToSWC_PAMConfig_u8
#  define Rte_Read_SWC_SafeVCANRx_RpProxiToSWC_PAMConfig_u8(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_PAMConfig_u8, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpProxiToSWC_Parkwithstop_u8 Rte_Read_SWC_SafeVCANRx_RpProxiToSWC_Parkwithstop_u8
#  define Rte_Read_SWC_SafeVCANRx_RpProxiToSWC_Parkwithstop_u8(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Parkwithstop_u8, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpProxiToSWC_SurroundViewCam_u8 Rte_Read_SWC_SafeVCANRx_RpProxiToSWC_SurroundViewCam_u8
#  define Rte_Read_SWC_SafeVCANRx_RpProxiToSWC_SurroundViewCam_u8(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpProxiToSWC_Trailerhitchassist_u8 Rte_Read_SWC_SafeVCANRx_RpProxiToSWC_Trailerhitchassist_u8
#  define Rte_Read_SWC_SafeVCANRx_RpProxiToSWC_Trailerhitchassist_u8(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Trailerhitchassist_u8, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpProxiToSWC_TyreSz_u16 Rte_Read_SWC_SafeVCANRx_RpProxiToSWC_TyreSz_u16
#  define Rte_Read_SWC_SafeVCANRx_RpProxiToSWC_TyreSz_u16(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_TyreSz_u16, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpSafeGuardPAStateOut_TbAP_PAStateOut_t Rte_Read_SWC_SafeVCANRx_RpSafeGuardPAStateOut_TbAP_PAStateOut_t
#  define Rte_Read_RpSafeGuardSvsToVCAN_SvsToVCAN_t Rte_Read_SWC_SafeVCANRx_RpSafeGuardSvsToVCAN_SvsToVCAN_t
#  define Rte_Read_RpTRSC_ME_VehOut_TRSC_t Rte_Read_SWC_SafeVCANRx_RpTRSC_ME_VehOut_TRSC_t
#  define Rte_Read_RpVcanRxQM_ME_VehInp_to_IpcSignals_QM_t Rte_Read_SWC_SafeVCANRx_RpVcanRxQM_ME_VehInp_to_IpcSignals_QM_t


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_APARequestSts Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_APARequestSts
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_APARequestSts() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_APARequestSts != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_APARequestSts_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_ASCM_Stat Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_Stat
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_Stat() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_Stat != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_Stat_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_ASCM_SysFail Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_SysFail
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_SysFail() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_SysFail != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_SysFail_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_Active_Park_Mode Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Mode
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Mode() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Mode != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Mode_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_Active_Park_Prox_Chime Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Prox_Chime
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Prox_Chime() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Prox_Chime != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Prox_Chime_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_Backup_Cam_Delay Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Backup_Cam_Delay
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Backup_Cam_Delay() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Backup_Cam_Delay != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Backup_Cam_Delay_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_CM_TCH_STAT Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_STAT
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_STAT() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_STAT != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_STAT_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_CM_TCH_X_COORD Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_X_COORD
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_X_COORD() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_X_COORD != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_X_COORD_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_CM_TCH_Y_COORD Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_Y_COORD
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_Y_COORD() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_Y_COORD != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_Y_COORD_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_CameraDisplaySts2 Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CameraDisplaySts2
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CameraDisplaySts2() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CameraDisplaySts2 != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CameraDisplaySts2_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_CmdIgnSts Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CmdIgnSts
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CmdIgnSts() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CmdIgnSts != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CmdIgnSts_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_DriverDoorSts Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_DriverDoorSts
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_DriverDoorSts() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_DriverDoorSts != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_DriverDoorSts_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_ECM_THA_Resp Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_THA_Resp
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_THA_Resp() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_THA_Resp != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_THA_Resp_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_ECM_TRSC_Resp Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_TRSC_Resp
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_TRSC_Resp() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_TRSC_Resp != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_TRSC_Resp_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_FT_PAMRequestSts Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FT_PAMRequestSts
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FT_PAMRequestSts() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FT_PAMRequestSts != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FT_PAMRequestSts_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_GearEngaged Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_GearEngaged
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_GearEngaged() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_GearEngaged != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_GearEngaged_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_ITBM_TrlrStat Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ITBM_TrlrStat
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ITBM_TrlrStat() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ITBM_TrlrStat != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ITBM_TrlrStat_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_LHRDoorSts Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LHRDoorSts
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LHRDoorSts() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LHRDoorSts != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LHRDoorSts_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_LanguageSelection Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LanguageSelection
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LanguageSelection() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LanguageSelection != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LanguageSelection_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_PAMRequestSts Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PAMRequestSts
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PAMRequestSts() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PAMRequestSts != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PAMRequestSts_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_PamChimeVolumeFront Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeFront
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeFront() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeFront != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeFront_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_PamChimeVolumeRear Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeRear
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeRear() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeRear != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeRear_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_PsngrDoorSts Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PsngrDoorSts
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PsngrDoorSts() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PsngrDoorSts != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PsngrDoorSts_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_RHRDoorSts Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHRDoorSts
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHRDoorSts() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHRDoorSts != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHRDoorSts_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_RHatchSts Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHatchSts
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHatchSts() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHatchSts != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHatchSts_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_Rear_Brk_Asst Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Rear_Brk_Asst
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Rear_Brk_Asst() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Rear_Brk_Asst != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Rear_Brk_Asst_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_SVC_Guidelines Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_SVC_Guidelines
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_SVC_Guidelines() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_SVC_Guidelines != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_SVC_Guidelines_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_ShiftLeverPosition Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPosition
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPosition() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPosition != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPosition_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_ShiftLeverPositionReq Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPositionReq
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPositionReq() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPositionReq != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPositionReq_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_TCASERANGESTATUS Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TCASERANGESTATUS
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TCASERANGESTATUS() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TCASERANGESTATUS != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TCASERANGESTATUS_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_EPBSts Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPBSts
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPBSts() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPBSts != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPBSts_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp_Sender)
#  define Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W
#  define Rte_IsUpdated_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W() (Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W_Sender)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpToSwcSafeFD02Rx_APARequestSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_APARequestSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_APARequestSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_APARequestSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_ASCM_Stat Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ASCM_Stat
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ASCM_Stat(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ASCM_Stat = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_ASCM_SysFail Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ASCM_SysFail
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ASCM_SysFail(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_Active_Park_Mode Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Active_Park_Mode
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Active_Park_Mode(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_Active_Park_Prox_Chime Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Active_Park_Prox_Chime
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Active_Park_Prox_Chime(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_Backup_Cam_Delay Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Backup_Cam_Delay
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Backup_Cam_Delay(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_Brk_Stat Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Brk_Stat
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Brk_Stat(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Brk_Stat = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_CM_TCH_STAT Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_STAT
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_STAT(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_STAT = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_CM_TCH_X_COORD Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_X_COORD
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_X_COORD(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_X_COORD = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_CM_TCH_Y_COORD Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_Y_COORD
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_Y_COORD(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_Y_COORD = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_CameraDisplaySts2 Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CameraDisplaySts2
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CameraDisplaySts2(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CameraDisplaySts2 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_CmdIgnSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_DriverDoorSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_DriverDoorSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_DriverDoorSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_DriverDoorSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_DynamicGrid Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_DynamicGrid
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_DynamicGrid(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_ECM_THA_Resp Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ECM_THA_Resp
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ECM_THA_Resp(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_ECM_TRSC_Resp Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ECM_TRSC_Resp
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ECM_TRSC_Resp(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_EPS_SteeringTouchStat Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EPS_SteeringTouchStat
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EPS_SteeringTouchStat(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_EPS_SteeringTouq_Resp Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EPS_SteeringTouq_Resp
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EPS_SteeringTouq_Resp(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_EPS_THA_DriverTorqueOverride Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EPS_THA_DriverTorqueOverride
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EPS_THA_DriverTorqueOverride(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_EPS_THA_SteeringTorqueResp Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EPS_THA_SteeringTorqueResp
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EPS_THA_SteeringTorqueResp(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_ESS_ENG_ST_W Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ESS_ENG_ST_W
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ESS_ENG_ST_W(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_EngineSts_W Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EngineSts_W
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EngineSts_W(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EngineSts_W = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_ExternalTemperature Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ExternalTemperature
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ExternalTemperature(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ExternalTemperature = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_FL_Lvl Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_FL_Lvl
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_FL_Lvl(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_FL_Lvl_Adj Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_FL_Lvl_Adj
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_FL_Lvl_Adj(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_FR_Lvl Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_FR_Lvl
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_FR_Lvl(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_FR_Lvl_Adj Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_FR_Lvl_Adj
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_FR_Lvl_Adj(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_FT_PAMRequestSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_FT_PAMRequestSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_FT_PAMRequestSts(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_GearEngaged Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngaged
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngaged(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngaged = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_GearEngagedForDisplay Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngagedForDisplay
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngagedForDisplay(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_HAS_Status_C2 Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_HAS_Status_C2
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_HAS_Status_C2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_HU_TRSC_EnableBtn_Sts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_HU_TRSC_EnableBtn_Sts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_HU_TRSC_EnableBtn_Sts(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_ITBM_TrlrStat Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ITBM_TrlrStat
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ITBM_TrlrStat(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ITBM_TrlrStat = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_LHRDoorSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LHRDoorSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LHRDoorSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LHRDoorSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_LanguageSelection Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LanguageSelection
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LanguageSelection(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LanguageSelection = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_LatAcceleration_BSM Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LatAcceleration_BSM
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LatAcceleration_BSM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_LongAcceleration_BSM Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LongAcceleration_BSM
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LongAcceleration_BSM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_LwsAngle Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsAngle
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsAngle(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsAngle = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_LwsAngleType Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsAngleType
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsAngleType(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_LwsSpeed Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsSpeed
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsSpeed(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsSpeed = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_MRM_STATUS_C2 Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_MRM_STATUS_C2
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_MRM_STATUS_C2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_PAMRequestSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PAMRequestSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PAMRequestSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PAMRequestSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_PamChimeVolumeFront Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeFront
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeFront(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeFront = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_PamChimeVolumeRear Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeRear
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeRear(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeRear = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_PdlPosActual Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PdlPosActual
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PdlPosActual(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_PsngrDoorSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PsngrDoorSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PsngrDoorSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PsngrDoorSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_RHRDoorSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHRDoorSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHRDoorSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHRDoorSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_RHatchSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHatchSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHatchSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHatchSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_RL_Lvl Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RL_Lvl
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RL_Lvl(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_RL_Lvl_Adj Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RL_Lvl_Adj
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RL_Lvl_Adj(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_RR_Lvl Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RR_Lvl
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RR_Lvl(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_RR_Lvl_Adj Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RR_Lvl_Adj
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RR_Lvl_Adj(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_Rear_Brk_Asst Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Rear_Brk_Asst
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Rear_Brk_Asst(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Rear_Brk_Asst = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_SVC_Guidelines Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_SVC_Guidelines
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_SVC_Guidelines(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_SVC_Guidelines = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_ShiftLeverPosition Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ShiftLeverPosition
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ShiftLeverPosition(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ShiftLeverPosition = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_ShiftLeverPositionReq Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ShiftLeverPositionReq
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ShiftLeverPositionReq(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_Shifter_ADAS_Inhibit Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Shifter_ADAS_Inhibit
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Shifter_ADAS_Inhibit(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_TCASERANGESTATUS Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TCASERANGESTATUS
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TCASERANGESTATUS(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TCASERANGESTATUS = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_THA_SteeringTouchStat Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_THA_SteeringTouchStat
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_THA_SteeringTouchStat(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_TRANS_ADAS_Inhibit Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TRANS_ADAS_Inhibit
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TRANS_ADAS_Inhibit(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_TargetGear Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TargetGear
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TargetGear(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TargetGear = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_TrailerConnectionSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TrailerConnectionSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TrailerConnectionSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TrailerConnectionSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_TransmissionSailingSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TransmissionSailingSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TransmissionSailingSts(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Rx_VIN_DATA Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_DATA
#  define Rte_Write_PpToSwcSafeFD02Rx_VIN_MSG Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_MSG
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_MSG(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_MSG = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_VehicleSpeedVSOSig Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VehicleSpeedVSOSig
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VehicleSpeedVSOSig(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VehicleSpeedVSOSig = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Rx_YawRate_BSM Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_YawRate_BSM
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_YawRate_BSM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_ACC_Systemsts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ACC_Systemsts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ACC_Systemsts(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_BSM_THA_Brk_Resp Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_BSM_THA_Brk_Resp
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_BSM_THA_Brk_Resp(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_BrkPdl_Stat Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_BrkPdl_Stat
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_BrkPdl_Stat(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_BrkTrq Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_BrkTrq
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_BrkTrq(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_BrkTrq_Driver Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_BrkTrq_Driver
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_BrkTrq_Driver(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_Brk_Stat Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_Brk_Stat
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_Brk_Stat(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_ECM_THA_Resp Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ECM_THA_Resp
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ECM_THA_Resp(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_ECM_TRSC_Resp Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ECM_TRSC_Resp
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ECM_TRSC_Resp(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_EPBSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPBSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPBSts(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_EPS_SteeringTouchStat Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_SteeringTouchStat
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_SteeringTouchStat(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_EPS_SteeringTouq_Resp Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_SteeringTouq_Resp
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_SteeringTouq_Resp(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_EPS_THA_DriverTorqueOverride Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_THA_DriverTorqueOverride
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_THA_DriverTorqueOverride(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_EPS_THA_SteeringTorqueResp Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_THA_SteeringTorqueResp
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_THA_SteeringTorqueResp(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_EngineSts_W Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EngineSts_W
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EngineSts_W(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_ExternalBrkRequestsDisabled Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ExternalBrkRequestsDisabled
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ExternalBrkRequestsDisabled(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_HAS_Status Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_HAS_Status
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_HAS_Status(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LHFWheelSpeed Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHFWheelSpeed
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHFWheelSpeed(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHFWheelSpeed = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LHF_Spin Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_Spin
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_Spin(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_Spin = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LHRWheelSpeed Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHRWheelSpeed
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHRWheelSpeed(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHRWheelSpeed = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LHR_Spin Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_Spin
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_Spin(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LatAccelerationOffset_BSM Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAccelerationOffset_BSM
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAccelerationOffset_BSM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LongAccelerationOffset_BSM Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAccelerationOffset_BSM
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAccelerationOffset_BSM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LwsAngle Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngle
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngle(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngle = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LwsAngleType Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngleType
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngleType(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngleType = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_LwsSpeed Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsSpeed
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsSpeed(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsSpeed = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_ParkingGearShiftReq_BSM Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ParkingGearShiftReq_BSM
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ParkingGearShiftReq_BSM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_ParkingInterventionSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ParkingInterventionSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ParkingInterventionSts(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_PdlPosActual Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PdlPosActual
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PdlPosActual(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PdlPosActual = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_REF_VEH_SPEED Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_REF_VEH_SPEED
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_REF_VEH_SPEED(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_RHFWheelSpeed Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHFWheelSpeed
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHFWheelSpeed(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHFWheelSpeed = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_RHF_Spin Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_Spin
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_Spin(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_Spin = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_RHRWheelSpeed Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHRWheelSpeed
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHRWheelSpeed(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHRWheelSpeed = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_RHR_Spin Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_Spin
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_Spin(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_Slope Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_Slope
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_Slope(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_Steering_Column_Torque Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_Steering_Column_Torque
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_Steering_Column_Torque(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_Steering_Column_Torque = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_THA_SteeringTouchStat Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_THA_SteeringTouchStat
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_THA_SteeringTouchStat(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2 Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_VehicleStandStillSts Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleStandStillSts
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleStandStillSts(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleStandStillSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Rx_FD14_YawRate_BSM Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRate_BSM
#  define Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRate_BSM(data) (Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRate_BSM = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpVIN_MessageFault_VIN_InvalidValueFlag Rte_Write_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_InvalidValueFlag
#  define Rte_Write_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_InvalidValueFlag(data) (Rte_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_InvalidValueFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpVIN_MessageFault_VIN_MissingMessageFlag Rte_Write_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_MissingMessageFlag
#  define Rte_Write_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_MissingMessageFlag(data) (Rte_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_MissingMessageFlag = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_PpMode_VehicleSpeedCheck_Mode Rte_Switch_SWC_SafeVCANRx_PpMode_VehicleSpeedCheck_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_E2EWRAPPER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CDD_E2EWRAPPER_APPL_CODE) RE_E2EWrapperCheck(P2VAR(E2E_MEP_ConfigType, AUTOMATIC, RTE_VAR_NOINIT) ConfigPtr, P2VAR(E2E_MEP_CheckStateType, AUTOMATIC, RTE_VAR_NOINIT) StatePtr, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) DataPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CDD_E2EWRAPPER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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

#  define Rte_Call_RpE2EServices_ME_E2E_Check RE_E2EWrapperCheck
#  define Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B RE_ReportErrorStatus1_0_B
#  define Rte_Call_RpIpcTxData_IPC_Write_v(arg1, arg2, arg3) (RE_IpcTxData(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define SWC_SafeVCANRx_START_SEC_CODE
# include "SWC_SafeVCANRx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RE_SafeVCANRx_Init RE_SafeVCANRx_Init
#  define RTE_RUNNABLE_RE_SafeVCANRx_Main RE_SafeVCANRx_Main
# endif

FUNC(void, SWC_SafeVCANRx_CODE) RE_SafeVCANRx_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_SafeVCANRx_CODE) RE_SafeVCANRx_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_SafeVCANRx_STOP_SEC_CODE
# include "SWC_SafeVCANRx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL (19U)

#  define RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG (23U)

#  define RTE_E_IF_E2EServices_ME_E2E_E_INTERR (25U)

#  define RTE_E_IF_E2EServices_ME_E2E_E_WRONGSTATE (26U)

#  define RTE_E_P_Error_CS_E_NOK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_SAFEVCANRX_H */

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
