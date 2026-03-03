//--------------------------------------------------------------------------
/// file TRSC_Support_Functions.c
/// @brief Contains hand coded support functions for TRSC SMVC
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Pravin Pawar (pravin.pawar@magna.com)
///
//  --------------------------------------------------------------------------

#include "TRSC_Support_Functions.h"
#include "TRSC_SMVC_Defines.h"
#include "UART_stdio.h"

#include "../TRSC_SM_VC_Int_ert_rtw/TRSC_SM_VC_Int.h"

#if TRSC_SMVC_IPC_TEST
void Simulate_TRSC_SMVC_Output()
{
  static uint32_t temp = 0;
  TRSC_SM_VC_Int_B.IbTRSC_DetInp_from_TRSC.MeTRSC_e_TRSCStat = (TeTRSC_e_TRSCStat) temp;
  TRSC_SM_VC_Int_B.IbTRSC_DetInp_from_TRSC.MeTRSC_deg_JackKnifeAngle = temp * 1.0f;
  TRSC_SM_VC_Int_B.IbTRSC_DetInp_from_TRSC.MeTRSC_m_TrailerBeamLen = temp * 1.0f;
  TRSC_SM_VC_Int_B.IbTRSC_DetInp_from_TRSC.MeTRSC_b_TRSCSwitchPressed = temp;

  TRSC_SM_VC_Int_B.IbTRSC_ME_VehOut_TRSC.IeTRSC_e_SpdLmtReq = (TeTRSC_e_SpdLmtReq) temp;
  TRSC_SM_VC_Int_B.IbTRSC_ME_VehOut_TRSC.IeTRSC_e_TRSCLedSts = (TeTRSC_e_TRSCLedSts) temp;
  TRSC_SM_VC_Int_B.IbTRSC_ME_VehOut_TRSC.IeTRSC_e_TRSCPopupDispInfo = (TeTRSC_e_TRSCPopupDispInfo) temp;
  TRSC_SM_VC_Int_B.IbTRSC_ME_VehOut_TRSC.IeTRSC_e_TRSCSts = (TeTRSC_e_TRSCSts) temp;
  TRSC_SM_VC_Int_B.IbTRSC_ME_VehOut_TRSC.IeTRSC_M_TRSCStrTrq = temp * 1.0f;
  TRSC_SM_VC_Int_B.IbTRSC_ME_VehOut_TRSC.IeTRSC_e_TRSCStrTrqActvReq = (TeTRSC_e_TRSCStrTrqActvReq) temp;
  TRSC_SM_VC_Int_B.IbTRSC_ME_VehOut_TRSC.IeTRSC_pct_TRSCStrDmp = temp * 1.0f;
  TRSC_SM_VC_Int_B.IbTRSC_ME_VehOut_TRSC.IeTRSC_b_MoreCamReqSts = temp;

  TRSC_SM_VC_Int_B.IbTRSC_TRSCtoSVS.MeTRSC_e_TRSCStat = (TeTRSC_e_TRSCStat) 6;
  TRSC_SM_VC_Int_B.IbTRSC_TRSCtoSVS.MeTRSC_b_MoreCamSoftButtEnbl = 1;
  TRSC_SM_VC_Int_B.IbTRSC_TRSCtoSVS.MeTRSC_deg_JackKnifeAngle = 2.0f;
  TRSC_SM_VC_Int_B.IbTRSC_TRSCtoSVS.MeTRSC_deg_JackknifeThrAngle = 3.0f;
  TRSC_SM_VC_Int_B.IbTRSC_TRSCtoSVS.MeTRSC_deg_MaxAllowedTADAngle = 4.0f;
  TRSC_SM_VC_Int_B.IbTRSC_TRSCtoSVS.MeTRSC_deg_KnobAngle = 5.0f;
  TRSC_SM_VC_Int_B.IbTRSC_TRSCtoSVS.MeTRSC_M_SteeringTorqInfo = 6.0f;
  TRSC_SM_VC_Int_B.IbTRSC_TRSCtoSVS.MeTRSC_b_TrlrRevSteeringStsInfo = 6;
  temp++;
}
#endif

#if TRSC_SMVC_IPC_PRINTS
void printTRSCInputs(const ME_VehInp_FromCAN14_IpcSignals *rtu_IbTRSC_MEVehInpFromCAN14IpcSignals,
                     const ME_VehInp_FromCAN2_IpcSignals *rtu_IbTRSC_MEVehInpFromCAN2IpcSignals)
{
  static uint8_t CmdIgnSts_old = 0;
  static uint8_t TrailerConnectionSts_old = 0;
  static uint8_t LHR_FastPulseCounter_old = 0;
  static uint8_t RL_Lvl_Adj_old = 0;
  static uint8_t RR_Lvl_Adj_old = 0;
  static uint8_t ASCM_Stat_old = 0;
  static uint8_t GearEngagedForDisplay_old = 0;
  static uint8_t TRSC_CenterBtn_Sts_old = 0;
  static uint8_t TRSC_EnableBtn_Sts_old = 0;
  static uint8_t EPS_SteeringTouq_Resp_old = 0;
  static float32_t LHRWheelSpeed_old = 0;
  static uint16_t TRSC_RawKnob_old = 0;
  static uint8_t RHF_FastPulseCounter_old = 0;
  static uint8_t RHF_Spin_old = 0;
  static float32_t RHFWheelSpeed_old = 0;
  static uint8_t RHR_FastPulseCounter_old = 0;
  static float32_t RHRWheelSpeed_old = 0;
  static uint8_t LHR_Spin_old = 0;
  static uint8_t DriverDoorSts_old = 0;
  static uint8_t RHatchSts_old = 0;
  static uint8_t ITBM_TrlrStat_old = 0;
  static uint8_t EngineSts_W_old = 0;
  static uint8_t TGW_CAMERA_DISP_STAT_old = 0;
  static uint8_t CameraDisplaySts_old = 0;
  static uint8_t CM_TCH_STAT_old = 0;
  static uint8_t RHR_Spin_old = 0;
  static float32_t LatAccelerationOffset_BSM_old = 0;
  static float32_t LongAccelerationOffset_BSM_old = 0;
  static float32_t LwsAngle_old = 0;
  static sint16_t LwsSpeed_old = 0;
  static float32_t LatAcceleration_BSM_old = 0;
  static uint8_t LwsAngleType_old = 0;
  static uint16_t CM_TCH_X_COORD_old = 0;
  static uint16_t CM_TCH_Y_COORD_old = 0;
  static uint8_t FL_Lvl_Adj_old = 0;
  static sint16_t FR_Lvl_old = 0;
  static uint8_t FR_Lvl_Adj_old = 0;
  static sint16_t RL_Lvl_old = 0;
  static sint16_t RR_Lvl_old = 0;
  static float32_t LongAcceleration_BSM_old = 0;
  static uint8_t HU_TRSC_EnableBtn_Sts_old = 0;
  static uint8_t GearEngaged_old = 0;
  static uint8_t SBR1RowDriverSeatSts_old = 0;
  static uint8_t ECM_TRSC_Resp_old = 0;
  static float32_t REF_VEH_SPEED_old = 0;
  static uint8_t VehicleStandStillSts_old = 0;
  static sint16_t FL_Lvl_old = 0;
  static float32_t YawRate_BSM_old = 0;
  static uint8_t ASCM_SysFail_old = 0;
  static float32_t VehicleSpeedVSOSig_old = 0;
  static uint8_t EPS_SteeringTouchStat_old = 0;
  static uint8_t LHF_FastPulseCounter_old = 0;
  static uint8_t LHF_Spin_old = 0;
  static float32_t LHFWheelSpeed_old = 0;
  static uint8_t FD14_SPM_Lat_Ctrl_ResponseSts_old = 0;
  static float32_t FD14_Steering_Column_Torque_old = 0;
  static uint8_t FD14_ESC_TRSC_Brk_Resp_old = 0;
  static uint8_t Cust_Trlr_Type_old = 0;
  static uint8_t ShiftLeverPosition_old = 0;

  if (CmdIgnSts_old != rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_10.CmdIgnSts)
      UART_printf("DataInp_BCM_FD_10.CmdIgnSts                : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_10.CmdIgnSts);

  if (TrailerConnectionSts_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_27.TrailerConnectionSts)
    UART_printf("DataInp_BCM_FD_27.TrailerConnectionSts     : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_27.TrailerConnectionSts);

  if (LHR_FastPulseCounter_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHR_FastPulseCounter)
    UART_printf("DataInp_BRAKE_FD_3.LHR_FastPulseCounter    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHR_FastPulseCounter);

  if (RL_Lvl_Adj_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RL_Lvl_Adj)
    UART_printf("DataInp_ASCM_FD_1.RL_Lvl_Adj    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RL_Lvl_Adj);

  if (RR_Lvl_Adj_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RR_Lvl_Adj)
    UART_printf("DataInp_ASCM_FD_1.RR_Lvl_Adj    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RR_Lvl_Adj);

  if (ASCM_Stat_old != rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_2.ASCM_Stat)
    UART_printf("DataInp_ASCM_FD_2.ASCM_Stat    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_2.ASCM_Stat);

  if (GearEngagedForDisplay_old != rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_2.GearEngagedForDisplay)
    UART_printf("DataInp_TRANSM_FD_2.GearEngagedForDisplay    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_2.GearEngagedForDisplay);

  if (TRSC_CenterBtn_Sts_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRSKM_FD_1.TRSC_CenterBtn_Sts)
    UART_printf("DataInp_TRSKM_FD_1.TRSC_CenterBtn_Sts    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRSKM_FD_1.TRSC_CenterBtn_Sts);

  if (TRSC_EnableBtn_Sts_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRSKM_FD_1.TRSC_EnableBtn_Sts)
    UART_printf("DataInp_TRSKM_FD_1.TRSC_EnableBtn_Sts    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRSKM_FD_1.TRSC_EnableBtn_Sts);

  if (EPS_SteeringTouq_Resp_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_2.FD14_EPS_STOM_SteeringTouq_Resp)
    UART_printf("DataInp_EPS_FD_2.EPS_SteeringTouq_Resp    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_2.FD14_EPS_STOM_SteeringTouq_Resp);

  if (((LHRWheelSpeed_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHRWheelSpeed) < -0.001) ||
      ((LHRWheelSpeed_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHRWheelSpeed) > 0.001))
    UART_printf("DataInp_BRAKE_FD_3.LHRWheelSpeed    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHRWheelSpeed);

  if (TRSC_RawKnob_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRSKM_FD_1.TRSC_RawKnob)
    UART_printf("DataInp_TRSKM_FD_1.TRSC_RawKnob    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRSKM_FD_1.TRSC_RawKnob);

  if (RHF_FastPulseCounter_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHF_FastPulseCounter)
    UART_printf("DataInp_BRAKE_FD_3.RHF_FastPulseCounter    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHF_FastPulseCounter);

  if (RHF_Spin_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHF_Spin)
    UART_printf("DataInp_BRAKE_FD_3.RHF_Spin    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHF_Spin);

  if (((RHFWheelSpeed_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHFWheelSpeed) < -0.001) ||
      ((RHFWheelSpeed_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHFWheelSpeed) > 0.001))
    UART_printf("DataInp_BRAKE_FD_3.RHFWheelSpeed    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHFWheelSpeed);

  if (RHR_FastPulseCounter_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHR_FastPulseCounter)
    UART_printf("DataInp_BRAKE_FD_3.RHR_FastPulseCounter    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHR_FastPulseCounter);

  if (((RHRWheelSpeed_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHRWheelSpeed) < -0.001) ||
       ((RHRWheelSpeed_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHRWheelSpeed) > 0.001))
    UART_printf("DataInp_BRAKE_FD_3.RHRWheelSpeed    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHRWheelSpeed);

  if (LHR_Spin_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHR_Spin)
    UART_printf("DataInp_BRAKE_FD_3.LHR_Spin    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHR_Spin);

  if (DriverDoorSts_old != rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_9.DriverDoorSts)
    UART_printf("DataInp_BCM_FD_9.DriverDoorSts    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_9.DriverDoorSts);

  if (RHatchSts_old != rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_9.RHatchSts)
    UART_printf("DataInp_BCM_FD_9.RHatchSts    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_9.RHatchSts);

  if (ITBM_TrlrStat_old != rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_29.ITBM_TrlrStat)
    UART_printf("DataInp_BCM_FD_29.ITBM_TrlrStat    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_29.ITBM_TrlrStat);

  if (EngineSts_W_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_ENGINE_FD_2.FD14_EngineSts_W)
    UART_printf("DataInp_ENGINE_FD_2.EngineSts_W    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_ENGINE_FD_2.FD14_EngineSts_W);

  if (TGW_CAMERA_DISP_STAT_old != rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_14.TGW_CAMERA_DISP_STAT)
    UART_printf("DataInp_TELEMATIC_FD14.TGW_CAMERA_DISP_STAT    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_14.TGW_CAMERA_DISP_STAT);

  if (CameraDisplaySts_old != rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CameraDisplaySts2)
    UART_printf("DataInp_TELEMATIC_FD14.CameraDisplaySts    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CameraDisplaySts2);

  if (CM_TCH_STAT_old != rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_STAT)
    UART_printf("DataInp_TELEMATIC_FD_5.CM_TCH_STAT    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_STAT);

  if (RHR_Spin_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHR_Spin)
    UART_printf("DataInp_BRAKE_FD_3.RHR_Spin    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHR_Spin);

  if (((LatAccelerationOffset_BSM_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LatAccelerationOffset_BSM) < -0.001) ||
       ((LatAccelerationOffset_BSM_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LatAccelerationOffset_BSM) > 0.001))
    UART_printf("DataInp_BRAKE_FD_3.LatAccelerationOffset_BSM    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LatAccelerationOffset_BSM);

  if (((LongAccelerationOffset_BSM_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LongAccelerationOffset_BSM) < -0.001) ||
       ((LongAccelerationOffset_BSM_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LongAccelerationOffset_BSM) > 0.001))
    UART_printf("DataInp_BRAKE_FD_3.LongAccelerationOffset_BSM    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LongAccelerationOffset_BSM);

  if (((LwsAngle_old - rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_STEERING1.LwsAngle_SCCM) < -0.001) ||
       ((LwsAngle_old - rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_STEERING1.LwsAngle_SCCM) > 0.001))
    UART_printf("DataInp_EPS_FD_1.LwsAngle    : %f\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_STEERING1.LwsAngle_SCCM);

  if (((LatAcceleration_BSM_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_LatAcceleration_BSM) < -0.001) ||
       ((LatAcceleration_BSM_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_LatAcceleration_BSM) > 0.001))
    UART_printf("DataInp_BRAKE_FD_2.LatAcceleration_BSM    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_LatAcceleration_BSM);

  if (LwsAngleType_old != rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_STEERING1.LwsAngleType_SCCM)
    UART_printf("DataInp_EPS_FD_1.LwsAngleType    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_STEERING1.LwsAngleType_SCCM);

  if (CM_TCH_X_COORD_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_X_COORD)
    UART_printf("DataInp_TELEMATIC_FD_5.CM_TCH_X_COORD    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_X_COORD);

  if (CM_TCH_Y_COORD_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_Y_COORD)
    UART_printf("DataInp_TELEMATIC_FD_5.CM_TCH_Y_COORD    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_Y_COORD);

  if (FL_Lvl_Adj_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FL_Lvl_Adj)
    UART_printf("DataInp_ASCM_FD_1.FL_Lvl_Adj    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FL_Lvl_Adj);

  if (FR_Lvl_Adj_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FR_Lvl_Adj)
    UART_printf("DataInp_ASCM_FD_1.FR_Lvl_Adj    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FR_Lvl_Adj);

  if (RL_Lvl_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RL_Lvl)
    UART_printf("DataInp_ASCM_FD_1.RL_Lvl    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RL_Lvl);

  if (RR_Lvl_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RR_Lvl)
    UART_printf("DataInp_ASCM_FD_1.RR_Lvl    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RR_Lvl);

  if (((LongAcceleration_BSM_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_LongAcceleration_BSM) < -0.001) ||
       ((LongAcceleration_BSM_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_LongAcceleration_BSM) > 0.001))
    UART_printf("DataInp_BRAKE_FD_2.LongAcceleration_BSM    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_LongAcceleration_BSM);

  if (HU_TRSC_EnableBtn_Sts_old != rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_11.HU_TRSC_EnableBtn_Sts)
    UART_printf("DataInp_TELEMATIC_FD_11.HU_TRSC_EnableBtn_Sts    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_11.HU_TRSC_EnableBtn_Sts);

  if (GearEngaged_old != rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_1.TargetGear)
    UART_printf("DataInp_TRANSM_FD_1.TargetGear    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_1.TargetGear);

  if (SBR1RowDriverSeatSts_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ORC_FD_1.SBR1RowDriverSeatSts)
    UART_printf("DataInp_ORC_FD_1.SBR1RowDriverSeatSts    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ORC_FD_1.SBR1RowDriverSeatSts);

  if (ECM_TRSC_Resp_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_ENGINE_FD_7.FD14_ECM_TRSC_Resp)
    UART_printf("DataInp_ENGINE_FD_7.ECM_TRSC_Resp    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_ENGINE_FD_7.FD14_ECM_TRSC_Resp);

  if (((REF_VEH_SPEED_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_REF_VEH_SPEED) < -0.001) ||
       ((REF_VEH_SPEED_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_REF_VEH_SPEED) > 0.001))
    UART_printf("DataInp_BRAKE_FD_1.REF_VEH_SPEED    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_REF_VEH_SPEED);

  if (VehicleStandStillSts_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_VehicleStandStillSts)
    UART_printf("DataInp_BRAKE_FD_1.VehicleStandStillSts    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_VehicleStandStillSts);

  if (((YawRate_BSM_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_YawRate_BSM) < -0.001) ||
       ((YawRate_BSM_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_YawRate_BSM) > 0.001))
    UART_printf("DataInp_BRAKE_FD_2.YawRate_BSM    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_YawRate_BSM);

  if (ASCM_SysFail_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_2.ASCM_SysFail)
    UART_printf("DataInp_ASCM_FD_2.ASCM_SysFail    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_2.ASCM_SysFail);

  if (((VehicleSpeedVSOSig_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig) < -0.001) ||
       ((VehicleSpeedVSOSig_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig) > 0.001))
    UART_printf("DataInp_BRAKE_FD_2.VehicleSpeedVSOSig    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig);

  if (EPS_SteeringTouchStat_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_2.FD14_EPS_STOM_SteeringTouchStat)
    UART_printf("DataInp_FD14_EPS_FD_2.FD14_EPS_STOM_SteeringTouchStat    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_2.FD14_EPS_STOM_SteeringTouchStat);

  if (LHF_FastPulseCounter_old !=rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHF_FastPulseCounter )
    UART_printf("DataInp_BRAKE_FD_3.LHF_FastPulseCounter    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHF_FastPulseCounter);

  if (LHF_Spin_old !=rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHF_Spin )
    UART_printf("DataInp_BRAKE_FD_3.LHF_Spin    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHF_Spin);

  if (((LHFWheelSpeed_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHFWheelSpeed) < -0.001) ||
       ((LHFWheelSpeed_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHFWheelSpeed) > 0.001))
    UART_printf("DataInp_BRAKE_FD_3.LHFWheelSpeed    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHFWheelSpeed);

  if (FD14_SPM_Lat_Ctrl_ResponseSts_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_SPM_Lat_Ctrl_ResponseSts)
      UART_printf("DataInp_EPS_FD14_1.FD14_SPM_Lat_Ctrl_ResponseSts    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_SPM_Lat_Ctrl_ResponseSts);

  if (FD14_ESC_TRSC_Brk_Resp_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_5.FD14_ESC_TRSC_Brk_Resp)
      UART_printf("DataInp_BRAKE_FD14_5.FD14_ESC_TRSC_Brk_Resp    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_5.FD14_ESC_TRSC_Brk_Resp);

  if (Cust_Trlr_Type_old != rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_IPC_FD4.Cust_Trlr_Type)
      UART_printf("DataInp_IPC_FD4.Cust_Trlr_Type    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_IPC_FD4.Cust_Trlr_Type);

  if (ShiftLeverPosition_old != rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_4.ShiftLeverPosition)
      UART_printf("DataInp_TRANSM_FD_4.ShiftLeverPosition    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_4.ShiftLeverPosition);

  CmdIgnSts_old =                     rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_10.CmdIgnSts;
  TrailerConnectionSts_old =          rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_27.TrailerConnectionSts;
  LHR_FastPulseCounter_old =          rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHR_FastPulseCounter;
  RL_Lvl_Adj_old =                    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RL_Lvl_Adj;
  RR_Lvl_Adj_old =                    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RR_Lvl_Adj;
  ASCM_Stat_old =                     rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_2.ASCM_Stat;
  GearEngagedForDisplay_old =         rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_2.GearEngagedForDisplay;
  TRSC_CenterBtn_Sts_old =            rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRSKM_FD_1.TRSC_CenterBtn_Sts;
  TRSC_EnableBtn_Sts_old =            rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRSKM_FD_1.TRSC_EnableBtn_Sts;
  EPS_SteeringTouq_Resp_old =         rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_2.FD14_EPS_STOM_SteeringTouq_Resp;
  LHRWheelSpeed_old =                 rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHRWheelSpeed;
  TRSC_RawKnob_old =                  rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRSKM_FD_1.TRSC_RawKnob;
  RHF_FastPulseCounter_old =          rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHF_FastPulseCounter;
  RHF_Spin_old =                      rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHF_Spin;
  RHFWheelSpeed_old =                 rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHFWheelSpeed;
  RHR_FastPulseCounter_old =          rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHR_FastPulseCounter;
  RHRWheelSpeed_old =                 rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHRWheelSpeed;
  LHR_Spin_old =                      rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHR_Spin;
  DriverDoorSts_old =                 rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_9.DriverDoorSts;
  RHatchSts_old =                     rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_9.RHatchSts;
  ITBM_TrlrStat_old =                 rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_29.ITBM_TrlrStat;
  EngineSts_W_old =                   rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_ENGINE_FD_2.FD14_EngineSts_W;
  TGW_CAMERA_DISP_STAT_old =          rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_14.TGW_CAMERA_DISP_STAT;
  CameraDisplaySts_old =              rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CameraDisplaySts2;
  CM_TCH_STAT_old =                   rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_STAT;
  RHR_Spin_old =                      rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHR_Spin;
  LatAccelerationOffset_BSM_old =     rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LatAccelerationOffset_BSM;
  LongAccelerationOffset_BSM_old =    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LongAccelerationOffset_BSM;
  LwsAngle_old =                      rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_STEERING1.LwsAngle_SCCM;
  LatAcceleration_BSM_old =           rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_LatAcceleration_BSM;
  LwsAngleType_old =                  rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_STEERING1.LwsAngleType_SCCM;
  CM_TCH_X_COORD_old =                rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_X_COORD;
  CM_TCH_Y_COORD_old =                rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_Y_COORD;
  FL_Lvl_Adj_old =                    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FL_Lvl_Adj;
  FR_Lvl_Adj_old =                    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FR_Lvl_Adj;
  RL_Lvl_old =                        rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RL_Lvl;
  RR_Lvl_old =                        rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RR_Lvl;
  LongAcceleration_BSM_old =          rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_LongAcceleration_BSM;
  HU_TRSC_EnableBtn_Sts_old =         rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_11.HU_TRSC_EnableBtn_Sts;
  GearEngaged_old =                   rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_1.TargetGear;
  SBR1RowDriverSeatSts_old =          rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ORC_FD_1.SBR1RowDriverSeatSts;
  ECM_TRSC_Resp_old =                 rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_ENGINE_FD_7.FD14_ECM_TRSC_Resp;
  REF_VEH_SPEED_old =                 rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_REF_VEH_SPEED;
  VehicleStandStillSts_old =          rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_VehicleStandStillSts;
  YawRate_BSM_old =                   rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_YawRate_BSM;
  ASCM_SysFail_old =                  rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_2.ASCM_SysFail;
  VehicleSpeedVSOSig_old =            rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig;
  EPS_SteeringTouchStat_old =         rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_2.FD14_EPS_STOM_SteeringTouchStat;
  LHF_FastPulseCounter_old =          rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHF_FastPulseCounter;
  LHF_Spin_old =                      rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHF_Spin;
  LHFWheelSpeed_old =                 rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHFWheelSpeed;
  FD14_SPM_Lat_Ctrl_ResponseSts_old = rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_SPM_Lat_Ctrl_ResponseSts;
  FD14_ESC_TRSC_Brk_Resp_old =        rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_5.FD14_ESC_TRSC_Brk_Resp;
  Cust_Trlr_Type_old =                rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_IPC_FD4.Cust_Trlr_Type;
  ShiftLeverPosition_old =            rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_4.ShiftLeverPosition;

  return;
}
#endif
