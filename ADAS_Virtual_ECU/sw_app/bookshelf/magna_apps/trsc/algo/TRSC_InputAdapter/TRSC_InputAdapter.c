/*
 * File: TRSC_InputAdapter.c
 *
 * Code generated for Simulink model 'TRSC_InputAdapter'.
 *
 * Model version                  : 1.125
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:50:30 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "TRSC_InputAdapter.h"
#include "TRSC_InputAdapter_private.h"
#include "../../code/TRSC_SMVC_Defines.h"

MdlrefDW_TRSC_InputAdapter_T TRSC_InputAdapter_MdlrefDW;

/* Block signals (default storage) */
B_TRSC_InputAdapter_c_T TRSC_InputAdapter_B;

/* Output and update for referenced model: 'TRSC_InputAdapter' */
void TRSC_InputAdapter(const TRSC_Inputs_from_TrailerDetection_t
  *rtu_IbTrailerDet_TrailerDetInpBus, const SVStoTRSC_t *rtu_IbSVS_SVStoTRSC,
  const ME_VehInp_FromCAN14_IpcSignals *rtu_IbTRSC_MEVehInpFromCAN14IpcSignals,
  const ME_VehInp_FromCAN2_IpcSignals *rtu_IbTRSC_MEVehInpFromCAN2IpcSignals,
  const ME_ProxiToMCU2_1_Def_t *rtu_IbTRSC_MEProxiToIpcSignals, const
  FID_STRUCT_QM *rtu_IbDDC_DegManagerDefSignals, const TbTRSCSmVc_TunParam_t
  *rtu_IbTRSCSmVc_TunParam, TbTRSC_InpBus *rty_IbTRSC_InpBus)
{
#if TRSC_SMVC_IPC_PRINTS
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

  static int temp = 0;

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

  if (EPS_SteeringTouq_Resp_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_2.FD14_EPS_SteeringTouq_Resp)
    UART_printf("DataInp_EPS_FD_2.EPS_SteeringTouq_Resp    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_2.FD14_EPS_SteeringTouq_Resp);

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

  if (((LwsAngle_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_LwsAngle) < -0.001) ||
       ((LwsAngle_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_LwsAngle) > 0.001))
    UART_printf("DataInp_EPS_FD_1.LwsAngle    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_LwsAngle);

  if (LwsSpeed_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_LwsSpeed)
    UART_printf("DataInp_EPS_FD_1.LwsSpeed    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_LwsSpeed);

  if (((LatAcceleration_BSM_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_LatAcceleration_BSM) < -0.001) ||
       ((LatAcceleration_BSM_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_LatAcceleration_BSM) > 0.001))
    UART_printf("DataInp_BRAKE_FD_2.LatAcceleration_BSM    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_LatAcceleration_BSM);

  if (LwsAngleType_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_LwsAngleType)
    UART_printf("DataInp_EPS_FD_1.LwsAngleType    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_LwsAngleType);

  if (CM_TCH_X_COORD_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_X_COORD)
    UART_printf("DataInp_TELEMATIC_FD_5.CM_TCH_X_COORD    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_X_COORD);

  if (CM_TCH_Y_COORD_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_Y_COORD)
    UART_printf("DataInp_TELEMATIC_FD_5.CM_TCH_Y_COORD    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_Y_COORD);

  if (FL_Lvl_Adj_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FL_Lvl_Adj)
    UART_printf("DataInp_ASCM_FD_1.FL_Lvl_Adj    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FL_Lvl_Adj);

  if (FR_Lvl_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FR_Lvl)
    UART_printf("DataInp_ASCM_FD_1.FR_Lvl    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FR_Lvl);

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

  if (GearEngaged_old != rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_4.GearEngaged)
    UART_printf("DataInp_TRANSM_FD_4.GearEngaged    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_4.GearEngaged);

  if (SBR1RowDriverSeatSts_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ORC_FD_1.SBR1RowDriverSeatSts)
    UART_printf("DataInp_ORC_FD_1.SBR1RowDriverSeatSts    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ORC_FD_1.SBR1RowDriverSeatSts);

  if (ECM_TRSC_Resp_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_ENGINE_FD_7.FD14_ECM_TRSC_Resp)
    UART_printf("DataInp_ENGINE_FD_7.ECM_TRSC_Resp    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_ENGINE_FD_7.FD14_ECM_TRSC_Resp);

  if (((REF_VEH_SPEED_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_REF_VEH_SPEED) < -0.001) ||
       ((REF_VEH_SPEED_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_REF_VEH_SPEED) > 0.001))
    UART_printf("DataInp_BRAKE_FD_1.REF_VEH_SPEED    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_REF_VEH_SPEED);

  if (VehicleStandStillSts_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_VehicleStandStillSts)
    UART_printf("DataInp_BRAKE_FD_1.VehicleStandStillSts    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_VehicleStandStillSts);

  if (FL_Lvl_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FL_Lvl)
    UART_printf("DataInp_ASCM_FD_1.FL_Lvl    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FL_Lvl);

  if (((YawRate_BSM_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_YawRate_BSM) < -0.001) ||
       ((YawRate_BSM_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_YawRate_BSM) > 0.001))
    UART_printf("DataInp_BRAKE_FD_2.YawRate_BSM    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_YawRate_BSM);

  if (ASCM_SysFail_old !=rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_2.ASCM_SysFail)
    UART_printf("DataInp_ASCM_FD_2.ASCM_SysFail    : %d\n", rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_2.ASCM_SysFail);

  if (((VehicleSpeedVSOSig_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig) < -0.001) ||
       ((VehicleSpeedVSOSig_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig) > 0.001))
    UART_printf("DataInp_BRAKE_FD_2.VehicleSpeedVSOSig    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig);

  if (EPS_SteeringTouchStat_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_2.FD14_EPS_SteeringTouchStat)
    UART_printf("DataInp_EPS_FD_2.EPS_SteeringTouchStat    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_2.FD14_EPS_SteeringTouchStat);

  if (LHF_FastPulseCounter_old !=rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHF_FastPulseCounter )
    UART_printf("DataInp_BRAKE_FD_3.LHF_FastPulseCounter    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHF_FastPulseCounter);

  if (LHF_Spin_old !=rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHF_Spin )
    UART_printf("DataInp_BRAKE_FD_3.LHF_Spin    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHF_Spin);

  if (((LHFWheelSpeed_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHFWheelSpeed) < -0.001) ||
       ((LHFWheelSpeed_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHFWheelSpeed) > 0.001))
    UART_printf("DataInp_BRAKE_FD_3.LHFWheelSpeed    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHFWheelSpeed);

  if (FD14_SPM_Lat_Ctrl_ResponseSts_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_SPM_Lat_Ctrl_ResponseSts)
      UART_printf("DataInp_EPS_FD14_1.FD14_SPM_Lat_Ctrl_ResponseSts    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_SPM_Lat_Ctrl_ResponseSts);

  if (((FD14_Steering_Column_Torque_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_Steering_Column_Torque) < -0.001) ||
       ((FD14_Steering_Column_Torque_old - rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_Steering_Column_Torque) > 0.001))
      UART_printf("DataInp_EPS_FD14_1.FD14_Steering_Column_Torque    : %f\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_Steering_Column_Torque);

  if (FD14_ESC_TRSC_Brk_Resp_old != rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_5.FD14_ESC_TRSC_Brk_Resp)
      UART_printf("DataInp_BRAKE_FD14_5.FD14_ESC_TRSC_Brk_Resp    : %d\n", rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_5.FD14_ESC_TRSC_Brk_Resp);

  CmdIgnSts_old =                     rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_10.CmdIgnSts;
  TrailerConnectionSts_old =          rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_27.TrailerConnectionSts;
  LHR_FastPulseCounter_old =          rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHR_FastPulseCounter;
  RL_Lvl_Adj_old =                    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RL_Lvl_Adj;
  RR_Lvl_Adj_old =                    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RR_Lvl_Adj;
  ASCM_Stat_old =                     rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_2.ASCM_Stat;
  GearEngagedForDisplay_old =         rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_2.GearEngagedForDisplay;
  TRSC_CenterBtn_Sts_old =            rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRSKM_FD_1.TRSC_CenterBtn_Sts;
  TRSC_EnableBtn_Sts_old =            rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRSKM_FD_1.TRSC_EnableBtn_Sts;
  EPS_SteeringTouq_Resp_old =         rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_2.FD14_EPS_SteeringTouq_Resp;
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
  LwsAngle_old =                      rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_LwsAngle;
  LwsSpeed_old =                      rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_LwsSpeed;
  LatAcceleration_BSM_old =           rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_LatAcceleration_BSM;
  LwsAngleType_old =                  rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_LwsAngleType;
  CM_TCH_X_COORD_old =                rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_X_COORD;
  CM_TCH_Y_COORD_old =                rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_Y_COORD;
  FL_Lvl_Adj_old =                    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FL_Lvl_Adj;
  FR_Lvl_old =                        rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FR_Lvl;
  FR_Lvl_Adj_old =                    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FR_Lvl_Adj;
  RL_Lvl_old =                        rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RL_Lvl;
  RR_Lvl_old =                        rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RR_Lvl;
  LongAcceleration_BSM_old =          rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_LongAcceleration_BSM;
  HU_TRSC_EnableBtn_Sts_old =         rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_11.HU_TRSC_EnableBtn_Sts;
  GearEngaged_old =                   rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_4.GearEngaged;
  SBR1RowDriverSeatSts_old =          rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ORC_FD_1.SBR1RowDriverSeatSts;
  ECM_TRSC_Resp_old =                 rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_ENGINE_FD_7.FD14_ECM_TRSC_Resp;
  REF_VEH_SPEED_old =                 rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_REF_VEH_SPEED;
  VehicleStandStillSts_old =          rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_VehicleStandStillSts;
  FL_Lvl_old =                        rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FL_Lvl;
  YawRate_BSM_old =                   rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_YawRate_BSM;
  ASCM_SysFail_old =                  rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_2.ASCM_SysFail;
  VehicleSpeedVSOSig_old =            rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig;
  EPS_SteeringTouchStat_old =         rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_2.FD14_EPS_SteeringTouchStat;
  LHF_FastPulseCounter_old =          rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHF_FastPulseCounter;
  LHF_Spin_old =                      rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHF_Spin;
  LHFWheelSpeed_old =                 rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHFWheelSpeed;
  FD14_SPM_Lat_Ctrl_ResponseSts_old = rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_SPM_Lat_Ctrl_ResponseSts;
  FD14_Steering_Column_Torque_old =   rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_Steering_Column_Torque;
  FD14_ESC_TRSC_Brk_Resp_old =        rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_5.FD14_ESC_TRSC_Brk_Resp;

#endif

  int32_T i;

  /* Constant: '<S2>/KeTRSC_deg_KnobHys' */
  TRSC_InputAdapter_B.DataTypeConversion9 = KeTRSC_deg_KnobHys;

  /* Constant: '<S2>/KeTRSC_deg_MaxKnobAngle' */
  TRSC_InputAdapter_B.DataTypeConversion6 = KeTRSC_deg_MaxKnobAngle;

  /* BusCreator: '<S2>/Bus Creator7' incorporates:
   *  Constant: '<S2>/KaTRA_deg_TADLUTBrkPts'
   *  Constant: '<S2>/KaTRA_deg_TADLUTTblData'
   *  Constant: '<S2>/KaTRA_deg_TAD_IGainLUTBrkPts'
   *  Constant: '<S2>/KaTRA_k_PGainLUTTblData'
   *  Constant: '<S2>/KaTRA_k_TADLUTTblData'
   *  Constant: '<S2>/KaTRA_k_TAD_IGainLUTTblData'
   *  Constant: '<S2>/KaTRA_k_TravDistLUTTblData'
   *  Constant: '<S2>/KaTRA_k_VehSpdLUTTblData'
   *  Constant: '<S2>/KaTRA_k_VehSpd_HdgDeviatLUTTblData'
   *  Constant: '<S2>/KaTRA_k_VehSpd_IGainLUTTblData'
   *  Constant: '<S2>/KaTRA_m_PGainLUTYBrkPts'
   *  Constant: '<S2>/KaTRA_m_TravDistLUTBrkPts'
   *  Constant: '<S2>/KaTRA_rate_RateGuardXdat'
   *  Constant: '<S2>/KaTRA_rate_RateGuardYdat'
   *  Constant: '<S2>/KaTRA_v_PGainLUTXBrkPts'
   *  Constant: '<S2>/KaTRA_v_VehSpdLUTBrkPts'
   *  Constant: '<S2>/KaTRA_v_VehSpd_HdgDeviatLUTBrkPts'
   *  Constant: '<S2>/KaTRA_v_VehSpd_IGainLUTBrkPts'
   *  Constant: '<S2>/KaTRSC_deg_FtWhlAngPts'
   *  Constant: '<S2>/KaTRSC_deg_PGainLUTYBrkPts'
   *  Constant: '<S2>/KaTRSC_deg_StwAngPts'
   *  Constant: '<S2>/KaTRSC_k_DampingGainTblData'
   *  Constant: '<S2>/KaTRSC_k_DiffGainTblData'
   *  Constant: '<S2>/KaTRSC_k_InputRateLimTblData'
   *  Constant: '<S2>/KaTRSC_k_IntegratorExtSatTblData'
   *  Constant: '<S2>/KaTRSC_k_IntegratorGainTblData'
   *  Constant: '<S2>/KaTRSC_k_PGainLUTTblData'
   *  Constant: '<S2>/KaTRSC_kph_DampingGainBrkPts'
   *  Constant: '<S2>/KaTRSC_kph_DiffGainBrkPts'
   *  Constant: '<S2>/KaTRSC_kph_InputRateLimBrkPts'
   *  Constant: '<S2>/KaTRSC_kph_IntegratorExtSatBrkPts'
   *  Constant: '<S2>/KaTRSC_kph_IntegratorGainBrkPts'
   *  Constant: '<S2>/KaTRSC_kph_PGainLUTXBrkPts'
   *  Constant: '<S2>/KeKM_deg_AngTh'
   *  Constant: '<S2>/KeKM_k_GyroYawCov'
   *  Constant: '<S2>/KeKM_k_KM_SF_RelAngCov'
   *  Constant: '<S2>/KeKM_k_KM_SF_RelAngRateCov'
   *  Constant: '<S2>/KeKM_k_KM_SF_YawRateCov'
   *  Constant: '<S2>/KeKM_k_KM_YawRateGyroBiasInit'
   *  Constant: '<S2>/KeKM_k_NumWheelPulses'
   *  Constant: '<S2>/KeKM_k_SWA_Res'
   *  Constant: '<S2>/KeKM_k_TADCov'
   *  Constant: '<S2>/KeKM_k_UpdateIMU_H'
   *  Constant: '<S2>/KeKM_k_UpdateRPM_H'
   *  Constant: '<S2>/KeKM_k_UpdateTAD_H'
   *  Constant: '<S2>/KeKM_k_WhlPlsCnt_high_lim'
   *  Constant: '<S2>/KeKM_k_WhlPlsCnt_low_lim'
   *  Constant: '<S2>/KeKM_k_WhlRPMYawCov'
   *  Constant: '<S2>/KeKM_m_BeamLength'
   *  Constant: '<S2>/KeKM_m_TrackWidth'
   *  Constant: '<S2>/KeKM_m_WheelCircumference'
   *  Constant: '<S2>/KeKM_s_SampleTime'
   *  Constant: '<S2>/KeTRA_deg_TrailerBeamLenYBrkPts'
   *  Constant: '<S2>/KeTRA_k_Kp'
   *  Constant: '<S2>/KeTRA_k_SteerAngRateLmt'
   *  Constant: '<S2>/KeTRA_m_K_beta'
   *  Constant: '<S2>/KeTRA_m_TrailerBeamLenXBrkPts'
   *  Constant: '<S2>/KeTRSC_Cnt_FailedCnt'
   *  Constant: '<S2>/KeTRSC_TADdes_k_PIDKd'
   *  Constant: '<S2>/KeTRSC_TADep_k_PIDKp'
   *  Constant: '<S2>/KeTRSC_b_bValidFlag'
   *  Constant: '<S2>/KeTRSC_deg_MaxStrAngle'
   *  Constant: '<S2>/KeTRSC_deg_MaxStrAngle_Low_Limit'
   *  Constant: '<S2>/KeTRSC_deg_MaxStrAngle_Up_Limit'
   *  Constant: '<S2>/KeTRSC_deg_MaxTrlrAngl'
   *  Constant: '<S2>/KeTRSC_deg_TAD_DesRateUpLim'
   *  Constant: '<S2>/KeTRSC_deg_TGTADdesRateChange'
   *  Constant: '<S2>/KeTRSC_deg_TrqCnt_LowLimit'
   *  Constant: '<S2>/KeTRSC_deg_TrqCnt_UpLimit'
   *  Constant: '<S2>/KeTRSC_e_CamBlockAcceptLvl'
   *  Constant: '<S2>/KeTRSC_k_JKAngle_LowLimit'
   *  Constant: '<S2>/KeTRSC_k_JKAngle_UpLimit'
   *  Constant: '<S2>/KeTRSC_k_LogVecLength'
   *  Constant: '<S2>/KeTRSC_k_TrqConstRateLim'
   *  Constant: '<S2>/KeTRSC_k_TrqConstSatLim'
   *  Constant: '<S2>/KeTRSC_k_VariantID'
   *  Constant: '<S2>/KeTRSC_k_WhlAngCFBias'
   *  Constant: '<S2>/KeTRSC_k_WhlAngCFWt'
   *  Constant: '<S2>/KeTRSC_kph_DeactivationSpd'
   *  Constant: '<S2>/KeTRSC_m_TBL_LowLimit'
   *  Constant: '<S2>/KeTRSC_m_TBL_UpLimit'
   *  Constant: '<S2>/KeTRSC_m_WheelBase'
   *  Constant: '<S2>/KeTRSC_m_WheelBase_Low_Limit'
   *  Constant: '<S2>/KeTRSC_m_WheelBase_Up_Limit'
   *  Constant: '<S2>/KeTRSC_pct_JackKnifePerc'
   *  Constant: '<S2>/KeTRSC_pct_TrlrJackKnifePerc'
   *  Constant: '<S2>/KeTRSC_s_ActTransRevDbnc2'
   *  Constant: '<S2>/KeTRSC_s_CalibDlyTh'
   *  Constant: '<S2>/KeTRSC_s_EpsRespTmOut'
   *  Constant: '<S2>/KeTRSC_s_GearDbncTh'
   *  Constant: '<S2>/KeTRSC_s_LEDTmrTh'
   *  Constant: '<S2>/KeTRSC_s_RespNotRcvdTmOut'
   *  Constant: '<S2>/KeTRSC_s_TrlrUnkwnSet'
   */
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_GyroYawCov = KeKM_k_GyroYawCov;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_NumWheelPulses =
    KeKM_k_NumWheelPulses;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_TADCov = KeKM_k_TADCov;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_UpdateIMU_H[0] =
    KeKM_k_UpdateIMU_H[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_UpdateRPM_H[0] =
    KeKM_k_UpdateRPM_H[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_UpdateTAD_H[0] =
    KeKM_k_UpdateTAD_H[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_UpdateIMU_H[1] =
    KeKM_k_UpdateIMU_H[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_UpdateRPM_H[1] =
    KeKM_k_UpdateRPM_H[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_UpdateTAD_H[1] =
    KeKM_k_UpdateTAD_H[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_UpdateIMU_H[2] =
    KeKM_k_UpdateIMU_H[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_UpdateRPM_H[2] =
    KeKM_k_UpdateRPM_H[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_UpdateTAD_H[2] =
    KeKM_k_UpdateTAD_H[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_WhlPlsCnt_high_lim =
    KeKM_k_WhlPlsCnt_high_lim;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_WhlPlsCnt_low_lim =
    KeKM_k_WhlPlsCnt_low_lim;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_WhlRPMYawCov =
    KeKM_k_WhlRPMYawCov;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_m_TrackWidth = KeKM_m_TrackWidth;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_m_WheelCircumference =
    KeKM_m_WheelCircumference;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_s_SampleTime = KeKM_s_SampleTime;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_KM_YawRateGyroBiasInit =
    KeKM_k_KM_YawRateGyroBiasInit;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_KM_SF_RelAngCov =
    KeKM_k_KM_SF_RelAngCov;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_KM_SF_RelAngRateCov =
    KeKM_k_KM_SF_RelAngRateCov;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_KM_SF_YawRateCov =
    KeKM_k_KM_SF_YawRateCov;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRA_m_K_beta = KeTRA_m_K_beta;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_deg_AngTh = KeKM_deg_AngTh;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_PGainLUTTblData[0] =
    KaTRA_k_PGainLUTTblData[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_PGainLUTTblData[1] =
    KaTRA_k_PGainLUTTblData[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_PGainLUTTblData[2] =
    KaTRA_k_PGainLUTTblData[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_PGainLUTTblData[3] =
    KaTRA_k_PGainLUTTblData[3];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_VehSpd_IGainLUTTblData[0] =
    KaTRA_k_VehSpd_IGainLUTTblData[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_VehSpd_IGainLUTTblData[1] =
    KaTRA_k_VehSpd_IGainLUTTblData[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_VehSpd_HdgDeviatLUTTblData[0] =
    KaTRA_k_VehSpd_HdgDeviatLUTTblData[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_TADLUTTblData[0] =
    KaTRA_k_TADLUTTblData[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_VehSpd_HdgDeviatLUTTblData[1] =
    KaTRA_k_VehSpd_HdgDeviatLUTTblData[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_TADLUTTblData[1] =
    KaTRA_k_TADLUTTblData[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_VehSpd_HdgDeviatLUTTblData[2] =
    KaTRA_k_VehSpd_HdgDeviatLUTTblData[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_TADLUTTblData[2] =
    KaTRA_k_TADLUTTblData[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRA_k_Kp = KeTRA_k_Kp;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_TravDistLUTTblData[0] =
    KaTRA_k_TravDistLUTTblData[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_VehSpdLUTTblData[0] =
    KaTRA_k_VehSpdLUTTblData[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_TAD_IGainLUTTblData[0] =
    KaTRA_k_TAD_IGainLUTTblData[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_TravDistLUTTblData[1] =
    KaTRA_k_TravDistLUTTblData[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_VehSpdLUTTblData[1] =
    KaTRA_k_VehSpdLUTTblData[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_k_TAD_IGainLUTTblData[1] =
    KaTRA_k_TAD_IGainLUTTblData[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_k_SWA_Res = KeKM_k_SWA_Res;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRA_deg_TrailerBeamLenYBrkPts[0] =
    KeTRA_deg_TrailerBeamLenYBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRA_m_TrailerBeamLenXBrkPts[0] =
    KeTRA_m_TrailerBeamLenXBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_deg_TADLUTBrkPts[0] =
    KaTRA_deg_TADLUTBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRA_deg_TrailerBeamLenYBrkPts[1] =
    KeTRA_deg_TrailerBeamLenYBrkPts[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRA_m_TrailerBeamLenXBrkPts[1] =
    KeTRA_m_TrailerBeamLenXBrkPts[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_deg_TADLUTBrkPts[1] =
    KaTRA_deg_TADLUTBrkPts[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRA_deg_TrailerBeamLenYBrkPts[2] =
    KeTRA_deg_TrailerBeamLenYBrkPts[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRA_m_TrailerBeamLenXBrkPts[2] =
    KeTRA_m_TrailerBeamLenXBrkPts[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_deg_TADLUTBrkPts[2] =
    KaTRA_deg_TADLUTBrkPts[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_deg_TAD_IGainLUTBrkPts[0] =
    KaTRA_deg_TAD_IGainLUTBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_m_PGainLUTYBrkPts[0] =
    KaTRA_m_PGainLUTYBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_m_TravDistLUTBrkPts[0] =
    KaTRA_m_TravDistLUTBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_v_PGainLUTXBrkPts[0] =
    KaTRA_v_PGainLUTXBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_v_VehSpdLUTBrkPts[0] =
    KaTRA_v_VehSpdLUTBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_deg_TAD_IGainLUTBrkPts[1] =
    KaTRA_deg_TAD_IGainLUTBrkPts[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_m_PGainLUTYBrkPts[1] =
    KaTRA_m_PGainLUTYBrkPts[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_m_TravDistLUTBrkPts[1] =
    KaTRA_m_TravDistLUTBrkPts[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_v_PGainLUTXBrkPts[1] =
    KaTRA_v_PGainLUTXBrkPts[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_v_VehSpdLUTBrkPts[1] =
    KaTRA_v_VehSpdLUTBrkPts[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_v_VehSpd_HdgDeviatLUTBrkPts[0] =
    KaTRA_v_VehSpd_HdgDeviatLUTBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_v_VehSpd_HdgDeviatLUTBrkPts[1] =
    KaTRA_v_VehSpd_HdgDeviatLUTBrkPts[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_v_VehSpd_HdgDeviatLUTBrkPts[2] =
    KaTRA_v_VehSpd_HdgDeviatLUTBrkPts[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_v_VehSpd_IGainLUTBrkPts[0] =
    KaTRA_v_VehSpd_IGainLUTBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_v_VehSpd_IGainLUTBrkPts[1] =
    KaTRA_v_VehSpd_IGainLUTBrkPts[1];
  memcpy(&TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_deg_FtWhlAngPts[0],
         ((real32_T *)&(KaTRSC_deg_FtWhlAngPts[0])), 37U * sizeof(real32_T));
  memcpy(&TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_deg_StwAngPts[0],
         ((real32_T *)&(KaTRSC_deg_StwAngPts[0])), 37U * sizeof(real32_T));
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRA_k_SteerAngRateLmt =
    KeTRA_k_SteerAngRateLmt;
  for (i = 0; i < 8; i++) {
    TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_rate_RateGuardXdat[i] =
      KaTRA_rate_RateGuardXdat[i];
    TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_rate_RateGuardYdat[i] =
      KaTRA_rate_RateGuardYdat[i];
  }

  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_m_WheelBase =
    KeTRSC_m_WheelBase;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxStrAngle =
    KeTRSC_deg_MaxStrAngle;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxStrAngle_Up_Limit =
    KeTRSC_deg_MaxStrAngle_Up_Limit;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxStrAngle_Low_Limit =
    KeTRSC_deg_MaxStrAngle_Low_Limit;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_m_WheelBase_Up_Limit =
    KeTRSC_m_WheelBase_Up_Limit;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_m_WheelBase_Low_Limit =
    KeTRSC_m_WheelBase_Low_Limit;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_deg_KnobHys =
    TRSC_InputAdapter_B.DataTypeConversion9;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_pct_JackKnifePerc =
    KeTRSC_pct_JackKnifePerc;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxKnobAngle =
    TRSC_InputAdapter_B.DataTypeConversion6;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_deg_MaxTrlrAngl =
    KeTRSC_deg_MaxTrlrAngl;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_TADdes_k_PIDKd =
    KeTRSC_TADdes_k_PIDKd;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_TADep_k_PIDKp =
    KeTRSC_TADep_k_PIDKp;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_deg_TADLUTTblData[0] =
    KaTRA_deg_TADLUTTblData[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_deg_TADLUTTblData[1] =
    KaTRA_deg_TADLUTTblData[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRA_deg_TADLUTTblData[2] =
    KaTRA_deg_TADLUTTblData[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_deg_TGTADdesRateChange =
    KeTRSC_deg_TGTADdesRateChange;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_deg_TAD_DesRateUpLim =
    KeTRSC_deg_TAD_DesRateUpLim;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_deg_TrqCnt_UpLimit =
    KeTRSC_deg_TrqCnt_UpLimit;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_deg_TrqCnt_LowLimit =
    KeTRSC_deg_TrqCnt_LowLimit;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_k_JKAngle_UpLimit =
    KeTRSC_k_JKAngle_UpLimit;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_k_JKAngle_LowLimit =
    KeTRSC_k_JKAngle_LowLimit;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_k_LogVecLength =
    KeTRSC_k_LogVecLength;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeKM_m_BeamLength = KeKM_m_BeamLength;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_m_TBL_UpLimit =
    KeTRSC_m_TBL_UpLimit;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_m_TBL_LowLimit =
    KeTRSC_m_TBL_LowLimit;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_kph_DeactivationSpd =
    KeTRSC_kph_DeactivationSpd;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_pct_TrlrJackKnifePerc =
    KeTRSC_pct_TrlrJackKnifePerc;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_s_ActTransRevDbnc2 =
    KeTRSC_s_ActTransRevDbnc2;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_s_CalibDlyTh =
    KeTRSC_s_CalibDlyTh;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_s_EpsRespTmOut =
    KeTRSC_s_EpsRespTmOut;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_s_GearDbncTh =
    KeTRSC_s_GearDbncTh;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_s_LEDTmrTh = KeTRSC_s_LEDTmrTh;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_s_RespNotRcvdTmOut =
    KeTRSC_s_RespNotRcvdTmOut;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_s_TrlrUnkwnSet =
    KeTRSC_s_TrlrUnkwnSet;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_k_WhlAngCFWt =
    KeTRSC_k_WhlAngCFWt;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_k_WhlAngCFBias =
    KeTRSC_k_WhlAngCFBias;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_InputRateLimBrkPts[0] =
    KaTRSC_kph_InputRateLimBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_InputRateLimTblData[0] =
    KaTRSC_k_InputRateLimTblData[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_IntegratorGainBrkPts[0] =
    KaTRSC_kph_IntegratorGainBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_IntegratorGainTblData[0] =
    KaTRSC_k_IntegratorGainTblData[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_IntegratorExtSatBrkPts[0] =
    KaTRSC_kph_IntegratorExtSatBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_IntegratorExtSatTblData[0] =
    KaTRSC_k_IntegratorExtSatTblData[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_PGainLUTXBrkPts[0] =
    KaTRSC_kph_PGainLUTXBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_InputRateLimBrkPts[1] =
    KaTRSC_kph_InputRateLimBrkPts[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_InputRateLimTblData[1] =
    KaTRSC_k_InputRateLimTblData[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_IntegratorGainBrkPts[1] =
    KaTRSC_kph_IntegratorGainBrkPts[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_IntegratorGainTblData[1] =
    KaTRSC_k_IntegratorGainTblData[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_IntegratorExtSatBrkPts[1] =
    KaTRSC_kph_IntegratorExtSatBrkPts[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_IntegratorExtSatTblData[1] =
    KaTRSC_k_IntegratorExtSatTblData[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_PGainLUTXBrkPts[1] =
    KaTRSC_kph_PGainLUTXBrkPts[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_InputRateLimBrkPts[2] =
    KaTRSC_kph_InputRateLimBrkPts[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_InputRateLimTblData[2] =
    KaTRSC_k_InputRateLimTblData[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_IntegratorGainBrkPts[2] =
    KaTRSC_kph_IntegratorGainBrkPts[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_IntegratorGainTblData[2] =
    KaTRSC_k_IntegratorGainTblData[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_IntegratorExtSatBrkPts[2] =
    KaTRSC_kph_IntegratorExtSatBrkPts[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_IntegratorExtSatTblData[2] =
    KaTRSC_k_IntegratorExtSatTblData[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_PGainLUTXBrkPts[2] =
    KaTRSC_kph_PGainLUTXBrkPts[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_InputRateLimBrkPts[3] =
    KaTRSC_kph_InputRateLimBrkPts[3];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_InputRateLimTblData[3] =
    KaTRSC_k_InputRateLimTblData[3];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_IntegratorGainBrkPts[3] =
    KaTRSC_kph_IntegratorGainBrkPts[3];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_IntegratorGainTblData[3] =
    KaTRSC_k_IntegratorGainTblData[3];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_IntegratorExtSatBrkPts[3] =
    KaTRSC_kph_IntegratorExtSatBrkPts[3];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_IntegratorExtSatTblData[3] =
    KaTRSC_k_IntegratorExtSatTblData[3];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_PGainLUTXBrkPts[3] =
    KaTRSC_kph_PGainLUTXBrkPts[3];
  for (i = 0; i < 5; i++) {
    TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_deg_PGainLUTYBrkPts[i] =
      KaTRSC_deg_PGainLUTYBrkPts[i];
  }

  memcpy(&TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_PGainLUTTblData[0],
         ((real32_T *)&(KaTRSC_k_PGainLUTTblData[0])), 20U * sizeof(real32_T));
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_DiffGainBrkPts[0] =
    KaTRSC_kph_DiffGainBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_DiffGainTblData[0] =
    KaTRSC_k_DiffGainTblData[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_DampingGainBrkPts[0] =
    KaTRSC_kph_DampingGainBrkPts[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_DampingGainTblData[0] =
    KaTRSC_k_DampingGainTblData[0];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_DiffGainBrkPts[1] =
    KaTRSC_kph_DiffGainBrkPts[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_DiffGainTblData[1] =
    KaTRSC_k_DiffGainTblData[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_DampingGainBrkPts[1] =
    KaTRSC_kph_DampingGainBrkPts[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_DampingGainTblData[1] =
    KaTRSC_k_DampingGainTblData[1];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_DiffGainBrkPts[2] =
    KaTRSC_kph_DiffGainBrkPts[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_DiffGainTblData[2] =
    KaTRSC_k_DiffGainTblData[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_DampingGainBrkPts[2] =
    KaTRSC_kph_DampingGainBrkPts[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_DampingGainTblData[2] =
    KaTRSC_k_DampingGainTblData[2];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_DiffGainBrkPts[3] =
    KaTRSC_kph_DiffGainBrkPts[3];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_DiffGainTblData[3] =
    KaTRSC_k_DiffGainTblData[3];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_kph_DampingGainBrkPts[3] =
    KaTRSC_kph_DampingGainBrkPts[3];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KaTRSC_k_DampingGainTblData[3] =
    KaTRSC_k_DampingGainTblData[3];
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_k_TrqConstRateLim =
    KeTRSC_k_TrqConstRateLim;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_k_TrqConstSatLim =
    KeTRSC_k_TrqConstSatLim;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_k_VariantID =
    KeTRSC_k_VariantID;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_Cnt_FailedCnt =
    KeTRSC_Cnt_FailedCnt;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_e_CamBlockAcceptLvl =
    KeTRSC_e_CamBlockAcceptLvl;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_b_bValidFlag = false;

  /* End of BusCreator: '<S2>/Bus Creator7' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (!KeTRSC_b_BypTunParam) {
    TRSC_InputAdapter_B.IbTRSCSmVc_TunParam = *rtu_IbTRSCSmVc_TunParam;
  }

  /* End of Switch: '<Root>/Switch' */

  /* BusAssignment: '<Root>/Bus Assignment' */
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_m_WheelBase =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_m_WheelBase;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_k_WhlAngCFWt =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_k_WhlAngCFWt;
  TRSC_InputAdapter_B.IbTRSCSmVc_TunParam.KeTRSC_k_WhlAngCFBias =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_k_WhlAngCFBias;

  /* DataTypeConversion: '<Root>/Data Type Conversion32' */
  TRSC_InputAdapter_B.DataTypeConversion6 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_X_COORD;

  /* DataTypeConversion: '<Root>/Data Type Conversion33' */
  TRSC_InputAdapter_B.DataTypeConversion9 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_Y_COORD;

  /* DataTypeConversion: '<Root>/Data Type Conversion47' */
  TRSC_InputAdapter_B.DataTypeConversion5 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FL_Lvl;

  /* DataTypeConversion: '<Root>/Data Type Conversion35' */
  TRSC_InputAdapter_B.DataTypeConversion4 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FR_Lvl;

  /* DataTypeConversion: '<Root>/Data Type Conversion37' */
  TRSC_InputAdapter_B.DataTypeConversion3 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RL_Lvl;

  /* DataTypeConversion: '<Root>/Data Type Conversion39' */
  TRSC_InputAdapter_B.IeVBII_M_StrWhlTrq =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RR_Lvl;

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_10.CmdIgnSts;

  /* DataTypeConversion: '<Root>/Data Type Conversion68' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts =
    (TeVBII_e_CmdIgnSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_27.TrailerConnectionSts;

  /* DataTypeConversion: '<Root>/Data Type Conversion75' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_TrailerConnectionSts =
    (TeVBII_e_TrailerConnectionSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_29.ITBM_TrlrStat;

  /* DataTypeConversion: '<Root>/Data Type Conversion81' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_TrlrPrsntSts =
    (TeVBII_e_TrlrPrsntSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion23' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CM_TCH_STAT;

  /* DataTypeConversion: '<Root>/Data Type Conversion91' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_TchScrSts =
    (TeVBII_e_TchScrSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion40' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_11.HU_TRSC_EnableBtn_Sts;

  /* DataTypeConversion: '<Root>/Data Type Conversion92' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_TrscEnblBtnSts =
    (TeVBII_e_TrscEnblBtnSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion41' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_4.GearEngaged;

  /* DataTypeConversion: '<Root>/Data Type Conversion93' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_GearRptState =
    (TeVBII_e_GearRptState)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion42' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ORC_FD_1.SBR1RowDriverSeatSts;

  /* DataTypeConversion: '<Root>/Data Type Conversion94' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts =
    (TeVBII_e_SBR1RowDriverSeatSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion49' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_2.ASCM_Stat;

  /* DataTypeConversion: '<Root>/Data Type Conversion102' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_VehAscmSts =
    (TeVBII_e_VehAscmSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion133' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_4.ShiftLeverPosition;

  /* DataTypeConversion: '<Root>/Data Type Conversion122' */
  TRSC_InputAdapter_B.DataTypeConversion122 = (TeVBII_e_ShiftLvrPos)
    TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  TRSC_InputAdapter_B.DataTypeConversion = (uint8_T)
    TRSC_InputAdapter_B.DataTypeConversion122;

  /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   */
  switch (TRSC_InputAdapter_B.DataTypeConversion) {
   case 1:
    rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply =
      TeVBII_e_GearEngagedForDsply_P;
    break;

   case 2:
    rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply =
      TeVBII_e_GearEngagedForDsply_R;
    break;

   case 3:
    rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply =
      TeVBII_e_GearEngagedForDsply_N;
    break;

   case 4:
    rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply =
      TeVBII_e_GearEngagedForDsply_D;
    break;

   case 5:
    rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply =
      TeVBII_e_GearEngagedForDsply_L;
    break;

   case 0:
    rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply =
      TeVBII_e_GearEngagedForDsply_Initialize;
    break;

   case 15:
    rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply =
      TeVBII_e_GearEngagedForDsply_SNA;
    break;

   default:
    rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply =
      TeVBII_e_GearEngagedForDsply_Initialize;
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch' */

  /* DataTypeConversion: '<Root>/Data Type Conversion52' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRSKM_FD_1.TRSC_CenterBtn_Sts;

  /* DataTypeConversion: '<Root>/Data Type Conversion104' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_CenterBtnSts =
    (TeVBII_e_CenterBtnSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion59' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRSKM_FD_1.TRSC_EnableBtn_Sts;

  /* DataTypeConversion: '<Root>/Data Type Conversion105' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_EnblBtnSts =
    (TeVBII_e_EnblBtnSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion21' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_14.TGW_CAMERA_DISP_STAT;

  /* DataTypeConversion: '<Root>/Data Type Conversion89' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_TGWCamDispSts =
    (TeVBII_e_TGWCamDispSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion22' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TELEMATIC_FD_5.CameraDisplaySts2;

  /* DataTypeConversion: '<Root>/Data Type Conversion90' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_CamDispSts =
    (TeVBII_e_CamDispSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion60' */
  TRSC_InputAdapter_B.DataTypeConversion116 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRSKM_FD_1.TRSC_RawKnob;

  /* DataTypeConversion: '<Root>/Data Type Conversion18' */
  TRSC_InputAdapter_B.IePRX_b_TrlrSurroundPresence =
    (rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_9.DriverDoorSts != 0);

  /* DataTypeConversion: '<Root>/Data Type Conversion19' */
  TRSC_InputAdapter_B.IePRX_b_AuxTrlrCam =
    (rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_BCM_FD_9.RHatchSts != 0);

  /* DataTypeConversion: '<Root>/Data Type Conversion34' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FL_Lvl_Adj;

  /* DataTypeConversion: '<Root>/Data Type Conversion98' */
  TRSC_InputAdapter_B.IePRX_b_SVSPresent =
    (TRSC_InputAdapter_B.DataTypeConversion7 != 0);

  /* DataTypeConversion: '<Root>/Data Type Conversion36' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.FR_Lvl_Adj;

  /* DataTypeConversion: '<Root>/Data Type Conversion99' */
  TRSC_InputAdapter_B.IePRX_b_SRT = (TRSC_InputAdapter_B.DataTypeConversion7 !=
    0);

  /* DataTypeConversion: '<Root>/Data Type Conversion38' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RL_Lvl_Adj;

  /* DataTypeConversion: '<Root>/Data Type Conversion100' */
  TRSC_InputAdapter_B.IeDDC_b_TRSCLimASCMDef =
    (TRSC_InputAdapter_B.DataTypeConversion7 != 0);

  /* DataTypeConversion: '<Root>/Data Type Conversion48' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_1.RR_Lvl_Adj;

  /* DataTypeConversion: '<Root>/Data Type Conversion101' */
  TRSC_InputAdapter_B.IeDDC_b_TRSCLimDefView =
    (TRSC_InputAdapter_B.DataTypeConversion7 != 0);

  /* DataTypeConversion: '<Root>/Data Type Conversion50' */
  TRSC_InputAdapter_B.IeDDC_b_TRSCLimView =
    (rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_ASCM_FD_2.ASCM_SysFail != 0);

  /* BusCreator: '<Root>/Bus Creator1' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_px_TchXCoord =
    TRSC_InputAdapter_B.DataTypeConversion6;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_px_TchYCoord =
    TRSC_InputAdapter_B.DataTypeConversion9;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_mm_VehFlLvl =
    TRSC_InputAdapter_B.DataTypeConversion5;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_mm_VehFrLvl =
    TRSC_InputAdapter_B.DataTypeConversion4;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_mm_VehRlLvl =
    TRSC_InputAdapter_B.DataTypeConversion3;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_mm_VehRrLvl =
    TRSC_InputAdapter_B.IeVBII_M_StrWhlTrq;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_ShiftLvrPos =
    TRSC_InputAdapter_B.DataTypeConversion122;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_CustTrlrType =
    TeVBII_e_CustTrlrType_Conventional;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_k_KnobAngl =
    TRSC_InputAdapter_B.DataTypeConversion116;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts =
    TRSC_InputAdapter_B.IePRX_b_TrlrSurroundPresence;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_b_TrnkStatus =
    TRSC_InputAdapter_B.IePRX_b_AuxTrlrCam;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_VehFlLvlAdj =
    TRSC_InputAdapter_B.IePRX_b_SVSPresent;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_VehFrLvlAdj =
    TRSC_InputAdapter_B.IePRX_b_SRT;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_VehRlLvlAdj =
    TRSC_InputAdapter_B.IeDDC_b_TRSCLimASCMDef;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_e_VehRrLvlAdj =
    TRSC_InputAdapter_B.IeDDC_b_TRSCLimDefView;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN2.IeVBII_b_VehAscmSysFail =
    TRSC_InputAdapter_B.IeDDC_b_TRSCLimView;

  /* DataTypeConversion: '<Root>/Data Type Conversion30' */
  TRSC_InputAdapter_B.IeVBII_M_StrWhlTrq =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_Steering_Column_Torque;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  TRSC_InputAdapter_B.DataTypeConversion3 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_LatAcceleration_BSM;

  /* DataTypeConversion: '<Root>/Data Type Conversion4' */
  TRSC_InputAdapter_B.DataTypeConversion4 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_LongAcceleration_BSM;

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  TRSC_InputAdapter_B.DataTypeConversion5 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_YawRate_BSM;

  /* DataTypeConversion: '<Root>/Data Type Conversion6' */
  TRSC_InputAdapter_B.DataTypeConversion6 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig;

  /* DataTypeConversion: '<Root>/Data Type Conversion9' */
  TRSC_InputAdapter_B.DataTypeConversion9 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHFWheelSpeed;

  /* DataTypeConversion: '<Root>/Data Type Conversion11' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_kph_LhrWhlSpd =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHRWheelSpeed;

  /* DataTypeConversion: '<Root>/Data Type Conversion14' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_kph_RhfWhlSpd =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHFWheelSpeed;

  /* DataTypeConversion: '<Root>/Data Type Conversion16' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_kph_RhrWhlSpd =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHRWheelSpeed;

  /* DataTypeConversion: '<Root>/Data Type Conversion25' */
  TRSC_InputAdapter_B.DataTypeConversion72 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LatAccelerationOffset_BSM;

  /* DataTypeConversion: '<Root>/Data Type Conversion26' */
  TRSC_InputAdapter_B.DataTypeConversion71 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LongAccelerationOffset_BSM;

  /* DataTypeConversion: '<Root>/Data Type Conversion27' */
  TRSC_InputAdapter_B.DataTypeConversion70 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_LwsAngle;

  /* DataTypeConversion: '<Root>/Data Type Conversion28' */
  TRSC_InputAdapter_B.DataTypeConversion67 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_LwsSpeed;

  /* DataTypeConversion: '<Root>/Data Type Conversion45' */
  TRSC_InputAdapter_B.IePRX_m_VehTyreSize =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_REF_VEH_SPEED;

  /* DataTypeConversion: '<Root>/Data Type Conversion29' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_SPM_Lat_Ctrl_ResponseSts;

  /* DataTypeConversion: '<Root>/Data Type Conversion86' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_e_SPMLatCtrlRespSts =
    (TeVBII_e_SPMLatCtrlRespSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion44' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_5.FD14_ESC_TRSC_Brk_Resp;

  /* DataTypeConversion: '<Root>/Data Type Conversion96' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp =
    (TeVBII_e_EscTrscBrkResp)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion8' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHF_Spin;

  /* DataTypeConversion: '<Root>/Data Type Conversion82' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_e_LhfWhlSpnSts =
    (TeVBII_e_WhlSpnSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion13' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHF_Spin;

  /* DataTypeConversion: '<Root>/Data Type Conversion83' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_e_RhfWhlSpnSts =
    (TeVBII_e_WhlSpnSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion17' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHR_Spin;

  /* DataTypeConversion: '<Root>/Data Type Conversion84' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_e_LhrWhlSpnSts =
    (TeVBII_e_WhlSpnSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion24' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHR_Spin;

  /* DataTypeConversion: '<Root>/Data Type Conversion85' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_e_RhrWhlSpnSts =
    (TeVBII_e_WhlSpnSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion31' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_1.FD14_LwsAngleType;

  /* DataTypeConversion: '<Root>/Data Type Conversion87' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_e_StrWhlAngleType =
    (TeVBII_e_StrWhlAngleType)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion20' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_ENGINE_FD_2.FD14_EngineSts_W;

  /* DataTypeConversion: '<Root>/Data Type Conversion88' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts =
    (TeVBII_e_EngineSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion43' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_ENGINE_FD_7.FD14_ECM_TRSC_Resp;

  /* DataTypeConversion: '<Root>/Data Type Conversion95' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp =
    (TeVBII_e_EcmTrscResp)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion46' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_1.FD14_VehicleStandStillSts;

  /* DataTypeConversion: '<Root>/Data Type Conversion97' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_e_VehStandStillSts =
    (TeVBII_e_VehStandStillSts)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion62' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_2.FD14_EPS_SteeringTouq_Resp;

  /* DataTypeConversion: '<Root>/Data Type Conversion106' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp =
    (TeVBII_e_StrTrqResp)TRSC_InputAdapter_B.DataTypeConversion7;

  /* DataTypeConversion: '<Root>/Data Type Conversion7' */
  TRSC_InputAdapter_B.DataTypeConversion7 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHF_FastPulseCounter;

  /* DataTypeConversion: '<Root>/Data Type Conversion10' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_cnt_LhrPulseCtr =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_LHR_FastPulseCounter;

  /* DataTypeConversion: '<Root>/Data Type Conversion12' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_cnt_RhfPulseCtr =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHF_FastPulseCounter;

  /* DataTypeConversion: '<Root>/Data Type Conversion15' */
  TRSC_InputAdapter_B.DataTypeConversion51 =
    rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_BRAKE_FD_3.FD14_RHR_FastPulseCounter;

  /* DataTypeConversion: '<Root>/Data Type Conversion61' */
  TRSC_InputAdapter_B.IeDDC_b_TRSCLimView =
    (rtu_IbTRSC_MEVehInpFromCAN14IpcSignals->DataInp_FD14_EPS_FD_2.FD14_EPS_SteeringTouchStat
     != 0);

  /* BusCreator: '<Root>/Bus Creator5' */
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_M_StrWhlTrq =
    TRSC_InputAdapter_B.IeVBII_M_StrWhlTrq;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_a_VehLatAcc =
    TRSC_InputAdapter_B.DataTypeConversion3;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_a_VehLongAcc =
    TRSC_InputAdapter_B.DataTypeConversion4;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_ddeg_VehYawRate =
    TRSC_InputAdapter_B.DataTypeConversion5;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_kph_VehSpeedVSOSig =
    TRSC_InputAdapter_B.DataTypeConversion6;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_kph_LhfWhlSpd =
    TRSC_InputAdapter_B.DataTypeConversion9;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_a_VehLatAccOffset =
    TRSC_InputAdapter_B.DataTypeConversion72;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_a_VehLongAccOffset =
    TRSC_InputAdapter_B.DataTypeConversion71;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_deg_StrWhlAng =
    TRSC_InputAdapter_B.DataTypeConversion70;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_ddeg_StrWhlSpd =
    TRSC_InputAdapter_B.DataTypeConversion67;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_kph_RefVehSpd =
    TRSC_InputAdapter_B.IePRX_m_VehTyreSize;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_cnt_LhfPulseCtr =
    TRSC_InputAdapter_B.DataTypeConversion7;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_cnt_RhrPulseCtr =
    TRSC_InputAdapter_B.DataTypeConversion51;
  rty_IbTRSC_InpBus->IbTRSC_VehInpFromCAN14.IeVBII_b_StrTchSts =
    TRSC_InputAdapter_B.IeDDC_b_TRSCLimView;

  /* DataTypeConversion: '<Root>/Data Type Conversion66' */
  MeTRSC_deg_TADAngleSMVC =
    rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_deg_TADAngle;

  /* DataTypeConversion: '<Root>/Data Type Conversion76' */
  TRSC_InputAdapter_B.IePRX_m_VehTyreSize =
    rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_m_HitchLength;

  /* DataTypeConversion: '<Root>/Data Type Conversion67' */
  TRSC_InputAdapter_B.DataTypeConversion67 =
    rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_deg_TADAngleRate;

  /* DataTypeConversion: '<Root>/Data Type Conversion70' */
  TRSC_InputAdapter_B.DataTypeConversion70 =
    rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_deg_DetJackknifeThrAngle;

  /* DataTypeConversion: '<Root>/Data Type Conversion71' */
  TRSC_InputAdapter_B.DataTypeConversion71 =
    rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_m_DetTrailerBeamLen;

  /* DataTypeConversion: '<Root>/Data Type Conversion72' */
  TRSC_InputAdapter_B.DataTypeConversion72 =
    rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_deg_DetJackKnifeAngle;

  /* DataTypeConversion: '<Root>/Data Type Conversion53' */
  rty_IbTRSC_InpBus->IbTRSC_TrailerDetInp.MeTRSC_cnt_TrlrCalibFailCntInfo =
    rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_cnt_TrlrCalibFailCntInfo;

  /* DataTypeConversion: '<Root>/Data Type Conversion63' */
  TRSC_InputAdapter_B.DataTypeConversion63 =
    rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_e_TrlrCalInfo;

  /* DataTypeConversion: '<Root>/Data Type Conversion110' */
  MeTRSC_e_TrlrCalInfoSMVC = TRSC_InputAdapter_B.DataTypeConversion63;

  /* DataTypeConversion: '<Root>/Data Type Conversion64' */
  TRSC_InputAdapter_B.DataTypeConversion64 =
    rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_e_TrlrRecogInfo;

  /* DataTypeConversion: '<Root>/Data Type Conversion111' */
  rty_IbTRSC_InpBus->IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo =
    TRSC_InputAdapter_B.DataTypeConversion64;

  /* DataTypeConversion: '<Root>/Data Type Conversion54' */
  TRSC_InputAdapter_B.DataTypeConversion54 =
    rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_e_TrlrPrsntInfo;

  /* DataTypeConversion: '<Root>/Data Type Conversion113' */
  rty_IbTRSC_InpBus->IbTRSC_TrailerDetInp.MeTRSC_e_TrlrPrsntInfo =
    TRSC_InputAdapter_B.DataTypeConversion54;

  /* DataTypeConversion: '<Root>/Data Type Conversion73' */
  TRSC_InputAdapter_B.DataTypeConversion73 =
    rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_e_TADState;

  /* DataTypeConversion: '<Root>/Data Type Conversion115' */
  rty_IbTRSC_InpBus->IbTRSC_TrailerDetInp.MeTRSC_e_TADState =
    TRSC_InputAdapter_B.DataTypeConversion73;

  /* DataTypeConversion: '<Root>/Data Type Conversion80' */
  rty_IbTRSC_InpBus->IbTRSC_TrailerDetInp.MeTRSC_e_TADCalibrationSubstate =
    (TeTRSC_e_TADCalibrationSubstate)rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_e_TADCalibrationSubstate;

  /* DataTypeConversion: '<Root>/Data Type Conversion79' */
  rty_IbTRSC_InpBus->IbTRSC_TrailerDetInp.MeTRSC_e_TurnAroundSubState =
    (TeTRSC_e_TurnAroundSubState)rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_e_TurnAroundSubState;

  /* DataTypeConversion: '<Root>/Data Type Conversion69' */
  TRSC_InputAdapter_B.IeDDC_b_TRSCLimView =
    rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_b_OBTLRecalibrate;

  /* DataTypeConversion: '<Root>/Data Type Conversion226' */
  TRSC_InputAdapter_B.IeDDC_b_TRSCLimDefView =
    rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_b_TrlrCalibDelayInfo;

  /* BusCreator: '<Root>/Bus Creator4' */
  rty_IbTRSC_InpBus->IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle =
    MeTRSC_deg_TADAngleSMVC;
  rty_IbTRSC_InpBus->IbTRSC_TrailerDetInp.MeTRSC_m_HitchLength =
    TRSC_InputAdapter_B.IePRX_m_VehTyreSize;
  rty_IbTRSC_InpBus->IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngleRate =
    TRSC_InputAdapter_B.DataTypeConversion67;
  rty_IbTRSC_InpBus->IbTRSC_TrailerDetInp.MeTRSC_deg_DetJackknifeThrAngle =
    TRSC_InputAdapter_B.DataTypeConversion70;
  rty_IbTRSC_InpBus->IbTRSC_TrailerDetInp.MeTRSC_m_DetTrailerBeamLen =
    TRSC_InputAdapter_B.DataTypeConversion71;
  rty_IbTRSC_InpBus->IbTRSC_TrailerDetInp.MeTRSC_deg_DetJackKnifeAngle =
    TRSC_InputAdapter_B.DataTypeConversion72;
  rty_IbTRSC_InpBus->IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo =
    MeTRSC_e_TrlrCalInfoSMVC;
  rty_IbTRSC_InpBus->IbTRSC_TrailerDetInp.MeTRSC_b_OBTLRecalibrate =
    TRSC_InputAdapter_B.IeDDC_b_TRSCLimView;
  rty_IbTRSC_InpBus->IbTRSC_TrailerDetInp.MeTRSC_b_TrlrCalibDelayInfo =
    TRSC_InputAdapter_B.IeDDC_b_TRSCLimDefView;

  /* DataTypeConversion: '<Root>/Data Type Conversion119' */
  TRSC_InputAdapter_B.IePRX_m_VehTyreSize =
    rtu_IbTRSC_MEProxiToIpcSignals->PRX_VehTyreSize_f32;

  /* DataTypeConversion: '<Root>/Data Type Conversion120' */
  TRSC_InputAdapter_B.DataTypeConversion51 =
    rtu_IbTRSC_MEProxiToIpcSignals->PRX_Wheelbase_u8;

  /* DataTypeConversion: '<Root>/Data Type Conversion137' */
  rty_IbTRSC_InpBus->IbTRSC_MEProxiToIpc.IePRX_e_VehWhlBase =
    (TeTRSC_e_VehWhlBase)TRSC_InputAdapter_B.DataTypeConversion51;

  /* DataTypeConversion: '<Root>/Data Type Conversion117' */
  TRSC_InputAdapter_B.DataTypeConversion51 =
    rtu_IbTRSC_MEProxiToIpcSignals->PRX_RadioDispTyp_u8;

  /* DataTypeConversion: '<Root>/Data Type Conversion136' */
  rty_IbTRSC_InpBus->IbTRSC_MEProxiToIpc.IePRX_e_RadDsplyTyp =
    (TeTRSC_e_RadDsplyTyp)TRSC_InputAdapter_B.DataTypeConversion51;

  /* DataTypeConversion: '<Root>/Data Type Conversion118' */
  TRSC_InputAdapter_B.DataTypeConversion51 =
    rtu_IbTRSC_MEProxiToIpcSignals->PRX_StrRatRckPinionTyp_u8;

  /* DataTypeConversion: '<Root>/Data Type Conversion135' */
  rty_IbTRSC_InpBus->IbTRSC_MEProxiToIpc.IePRX_e_StrRackPinTyp =
    (TeTRSC_e_StrRackPinTyp)TRSC_InputAdapter_B.DataTypeConversion51;

  /* DataTypeConversion: '<Root>/Data Type Conversion56' */
  TRSC_InputAdapter_B.IeDDC_b_TRSCLimView =
    rtu_IbTRSC_MEProxiToIpcSignals->PRX_CanNod63_b;

  /* DataTypeConversion: '<Root>/Data Type Conversion65' */
  TRSC_InputAdapter_B.IeDDC_b_TRSCLimDefView =
    rtu_IbTRSC_MEProxiToIpcSignals->PRX_CanNod95_b;

  /* DataTypeConversion: '<Root>/Data Type Conversion112' */
  TRSC_InputAdapter_B.IeDDC_b_TRSCLimASCMDef =
    rtu_IbTRSC_MEProxiToIpcSignals->PRX_CanNod27_b;

  /* DataTypeConversion: '<Root>/Data Type Conversion114' */
  TRSC_InputAdapter_B.IePRX_b_SRT = rtu_IbTRSC_MEProxiToIpcSignals->PRX_SRT_b;

  /* DataTypeConversion: '<Root>/Data Type Conversion121' */
  TRSC_InputAdapter_B.IePRX_b_SVSPresent =
    rtu_IbTRSC_MEProxiToIpcSignals->PRX_SurroundViewCamera_b;

  /* DataTypeConversion: '<Root>/Data Type Conversion124' */
  TRSC_InputAdapter_B.IePRX_b_AuxTrlrCam =
    rtu_IbTRSC_MEProxiToIpcSignals->PRX_AuxTrlrCam_b;

  /* DataTypeConversion: '<Root>/Data Type Conversion125' */
  TRSC_InputAdapter_B.IePRX_b_TrlrSurroundPresence =
    rtu_IbTRSC_MEProxiToIpcSignals->PRX_TrlrSurroundPresence_b;

  /* DataTypeConversion: '<Root>/Data Type Conversion123' */
  TRSC_InputAdapter_B.MeTRSC_b_InternalFault =
    rtu_IbTRSC_MEProxiToIpcSignals->PRX_TRSCPresence_b;

  /* BusCreator: '<Root>/Bus Creator2' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  rty_IbTRSC_InpBus->IbTRSC_MEProxiToIpc.IePRX_mm_VehTyreSize =
    TRSC_InputAdapter_B.IePRX_m_VehTyreSize;
  rty_IbTRSC_InpBus->IbTRSC_MEProxiToIpc.IePRX_e_BoxDelete =
    CeConst_k_ConstZeroUint8;
  rty_IbTRSC_InpBus->IbTRSC_MEProxiToIpc.IePRX_b_CanNode63Ttm =
    TRSC_InputAdapter_B.IeDDC_b_TRSCLimView;
  rty_IbTRSC_InpBus->IbTRSC_MEProxiToIpc.IePRX_b_CanNode95ItbmItcm =
    TRSC_InputAdapter_B.IeDDC_b_TRSCLimDefView;
  rty_IbTRSC_InpBus->IbTRSC_MEProxiToIpc.IePRX_b_CanNode27AsmAscm =
    TRSC_InputAdapter_B.IeDDC_b_TRSCLimASCMDef;
  rty_IbTRSC_InpBus->IbTRSC_MEProxiToIpc.IePRX_b_SRT =
    TRSC_InputAdapter_B.IePRX_b_SRT;
  rty_IbTRSC_InpBus->IbTRSC_MEProxiToIpc.IePRX_b_SVSPresent =
    TRSC_InputAdapter_B.IePRX_b_SVSPresent;
  rty_IbTRSC_InpBus->IbTRSC_MEProxiToIpc.IePRX_b_AuxTrlrCam =
    TRSC_InputAdapter_B.IePRX_b_AuxTrlrCam;
  rty_IbTRSC_InpBus->IbTRSC_MEProxiToIpc.IePRX_b_TrlrSurroundPresence =
    TRSC_InputAdapter_B.IePRX_b_TrlrSurroundPresence;
  rty_IbTRSC_InpBus->IbTRSC_MEProxiToIpc.IePRX_b_TRSCPresent =
    TRSC_InputAdapter_B.MeTRSC_b_InternalFault;

  /* DataTypeConversion: '<Root>/Data Type Conversion55' */
  TRSC_InputAdapter_B.DataTypeConversion55 =
    (TeTRSC_e_DispView2)rtu_IbSVS_SVStoTRSC->MeSVS_e_DispView2Info;

  /* DataTypeConversion: '<Root>/Data Type Conversion107' */
  rty_IbTRSC_InpBus->IbTRSC_SVStoTRSC.MeSVS_e_DispView2Info =
    TRSC_InputAdapter_B.DataTypeConversion55;

  /* DataTypeConversion: '<Root>/Data Type Conversion74' */
  TRSC_InputAdapter_B.MeTRSC_b_InternalFault =
    rtu_IbSVS_SVStoTRSC->MeSVS_b_MoreCamReq;

  /* BusCreator: '<Root>/Bus Creator3' */
  rty_IbTRSC_InpBus->IbTRSC_SVStoTRSC.IeHMI_b_MoreCamReq =
    TRSC_InputAdapter_B.MeTRSC_b_InternalFault;

  /* DataTypeConversion: '<Root>/Data Type Conversion139' */
  TRSC_InputAdapter_B.DataTypeConversion51 =
    rtu_IbDDC_DegManagerDefSignals->m_QM_FID_TRSC_DISABLED;

  /* DataTypeConversion: '<Root>/Data Type Conversion140' */
  TRSC_InputAdapter_B.MeTRSC_b_InternalFault =
    (TRSC_InputAdapter_B.DataTypeConversion51 != 0);

  /* DataTypeConversion: '<Root>/Data Type Conversion141' */
  TRSC_InputAdapter_B.DataTypeConversion51 =
    rtu_IbDDC_DegManagerDefSignals->m_QM_FID_TRSC_LIMITED_View;

  /* DataTypeConversion: '<Root>/Data Type Conversion142' */
  TRSC_InputAdapter_B.IeDDC_b_TRSCLimView =
    (TRSC_InputAdapter_B.DataTypeConversion51 != 0);

  /* DataTypeConversion: '<Root>/Data Type Conversion145' */
  TRSC_InputAdapter_B.DataTypeConversion51 =
    rtu_IbDDC_DegManagerDefSignals->m_QM_FID_TRSC_LIMITED_DefView;

  /* DataTypeConversion: '<Root>/Data Type Conversion146' */
  TRSC_InputAdapter_B.IeDDC_b_TRSCLimDefView =
    (TRSC_InputAdapter_B.DataTypeConversion51 != 0);

  /* DataTypeConversion: '<Root>/Data Type Conversion147' */
  TRSC_InputAdapter_B.DataTypeConversion51 =
    rtu_IbDDC_DegManagerDefSignals->m_QM_FID_TRSC_LIMITED_ASCMDef;

  /* DataTypeConversion: '<Root>/Data Type Conversion148' */
  TRSC_InputAdapter_B.IeDDC_b_TRSCLimASCMDef =
    (TRSC_InputAdapter_B.DataTypeConversion51 != 0);

  /* BusCreator: '<Root>/Bus Creator6' */
  rty_IbTRSC_InpBus->IbDDC_DegMgrToTRSC.IeDDC_b_TRSCDisabled =
    TRSC_InputAdapter_B.MeTRSC_b_InternalFault;
  rty_IbTRSC_InpBus->IbDDC_DegMgrToTRSC.IeDDC_b_TRSCLimView =
    TRSC_InputAdapter_B.IeDDC_b_TRSCLimView;
  rty_IbTRSC_InpBus->IbDDC_DegMgrToTRSC.IeDDC_b_TRSCLimDefView =
    TRSC_InputAdapter_B.IeDDC_b_TRSCLimDefView;
  rty_IbTRSC_InpBus->IbDDC_DegMgrToTRSC.IeDDC_b_TRSCLimASCMDef =
    TRSC_InputAdapter_B.IeDDC_b_TRSCLimASCMDef;

  /* DataTypeConversion: '<Root>/Data Type Conversion58' */
  TRSC_InputAdapter_B.DataTypeConversion51 =
    rtu_IbDDC_DegManagerDefSignals->m_QM_FID_TRSC_DLD_DISABLED;

  /* DataTypeConversion: '<Root>/Data Type Conversion57' incorporates:
   *  Constant: '<Root>/Constant'
   */
  TRSC_InputAdapter_B.MeTRSC_b_InternalFault = false;

  /* BusCreator: '<Root>/Bus Creator' */
  rty_IbTRSC_InpBus->IbTRSCSmVc_TunParam =
    TRSC_InputAdapter_B.IbTRSCSmVc_TunParam;
  rty_IbTRSC_InpBus->MeTRSC_e_CamBlockSts =
    TRSC_InputAdapter_B.DataTypeConversion51;
  rty_IbTRSC_InpBus->MeTRSC_b_InternalFault =
    TRSC_InputAdapter_B.MeTRSC_b_InternalFault;

  /* DataTypeConversion: '<Root>/Data Type Conversion186' */
  memcpy(&TRSC_InputAdapter_B.DataTypeConversion186[0],
         &rtu_IbTRSCSmVc_TunParam->KaTRSC_deg_FtWhlAngPts[0], 37U * sizeof
         (real32_T));

  /* DataTypeConversion: '<Root>/Data Type Conversion187' */
  memcpy(&TRSC_InputAdapter_B.DataTypeConversion187[0],
         &rtu_IbTRSCSmVc_TunParam->KaTRSC_deg_StwAngPts[0], 37U * sizeof
         (real32_T));

  /* DataTypeConversion: '<Root>/Data Type Conversion189' */
  for (i = 0; i < 8; i++) {
    TRSC_InputAdapter_B.DataTypeConversion189[i] =
      rtu_IbTRSCSmVc_TunParam->KaTRA_rate_RateGuardXdat[i];
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion189' */

  /* DataTypeConversion: '<Root>/Data Type Conversion190' */
  for (i = 0; i < 8; i++) {
    TRSC_InputAdapter_B.DataTypeConversion190[i] =
      rtu_IbTRSCSmVc_TunParam->KaTRA_rate_RateGuardYdat[i];
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion190' */

  /* DataTypeConversion: '<Root>/Data Type Conversion167' */
  TRSC_InputAdapter_B.DataTypeConversion167[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_PGainLUTTblData[0];
  TRSC_InputAdapter_B.DataTypeConversion167[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_PGainLUTTblData[1];
  TRSC_InputAdapter_B.DataTypeConversion167[2] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_PGainLUTTblData[2];
  TRSC_InputAdapter_B.DataTypeConversion167[3] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_PGainLUTTblData[3];

  /* DataTypeConversion: '<Root>/Data Type Conversion152' */
  TRSC_InputAdapter_B.DataTypeConversion152[0] =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_UpdateIMU_H[0];
  TRSC_InputAdapter_B.DataTypeConversion152[1] =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_UpdateIMU_H[1];
  TRSC_InputAdapter_B.DataTypeConversion152[2] =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_UpdateIMU_H[2];

  /* DataTypeConversion: '<Root>/Data Type Conversion153' */
  TRSC_InputAdapter_B.DataTypeConversion153[0] =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_UpdateRPM_H[0];
  TRSC_InputAdapter_B.DataTypeConversion153[1] =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_UpdateRPM_H[1];
  TRSC_InputAdapter_B.DataTypeConversion153[2] =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_UpdateRPM_H[2];

  /* DataTypeConversion: '<Root>/Data Type Conversion154' */
  TRSC_InputAdapter_B.DataTypeConversion154[0] =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_UpdateTAD_H[0];
  TRSC_InputAdapter_B.DataTypeConversion154[1] =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_UpdateTAD_H[1];
  TRSC_InputAdapter_B.DataTypeConversion154[2] =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_UpdateTAD_H[2];

  /* DataTypeConversion: '<Root>/Data Type Conversion169' */
  TRSC_InputAdapter_B.DataTypeConversion169[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_VehSpd_HdgDeviatLUTTblData[0];
  TRSC_InputAdapter_B.DataTypeConversion169[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_VehSpd_HdgDeviatLUTTblData[1];
  TRSC_InputAdapter_B.DataTypeConversion169[2] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_VehSpd_HdgDeviatLUTTblData[2];

  /* DataTypeConversion: '<Root>/Data Type Conversion170' */
  TRSC_InputAdapter_B.DataTypeConversion170[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_TADLUTTblData[0];
  TRSC_InputAdapter_B.DataTypeConversion170[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_TADLUTTblData[1];
  TRSC_InputAdapter_B.DataTypeConversion170[2] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_TADLUTTblData[2];

  /* DataTypeConversion: '<Root>/Data Type Conversion175' */
  TRSC_InputAdapter_B.DataTypeConversion175[0] =
    rtu_IbTRSCSmVc_TunParam->KeTRA_deg_TrailerBeamLenYBrkPts[0];
  TRSC_InputAdapter_B.DataTypeConversion175[1] =
    rtu_IbTRSCSmVc_TunParam->KeTRA_deg_TrailerBeamLenYBrkPts[1];
  TRSC_InputAdapter_B.DataTypeConversion175[2] =
    rtu_IbTRSCSmVc_TunParam->KeTRA_deg_TrailerBeamLenYBrkPts[2];

  /* DataTypeConversion: '<Root>/Data Type Conversion176' */
  TRSC_InputAdapter_B.DataTypeConversion176[0] =
    rtu_IbTRSCSmVc_TunParam->KeTRA_m_TrailerBeamLenXBrkPts[0];
  TRSC_InputAdapter_B.DataTypeConversion176[1] =
    rtu_IbTRSCSmVc_TunParam->KeTRA_m_TrailerBeamLenXBrkPts[1];
  TRSC_InputAdapter_B.DataTypeConversion176[2] =
    rtu_IbTRSCSmVc_TunParam->KeTRA_m_TrailerBeamLenXBrkPts[2];

  /* DataTypeConversion: '<Root>/Data Type Conversion178' */
  TRSC_InputAdapter_B.DataTypeConversion178[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_deg_TADLUTBrkPts[0];
  TRSC_InputAdapter_B.DataTypeConversion178[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_deg_TADLUTBrkPts[1];
  TRSC_InputAdapter_B.DataTypeConversion178[2] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_deg_TADLUTBrkPts[2];

  /* DataTypeConversion: '<Root>/Data Type Conversion184' */
  TRSC_InputAdapter_B.DataTypeConversion184[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_v_VehSpd_HdgDeviatLUTBrkPts[0];
  TRSC_InputAdapter_B.DataTypeConversion184[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_v_VehSpd_HdgDeviatLUTBrkPts[1];
  TRSC_InputAdapter_B.DataTypeConversion184[2] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_v_VehSpd_HdgDeviatLUTBrkPts[2];

  /* DataTypeConversion: '<Root>/Data Type Conversion203' */
  TRSC_InputAdapter_B.DataTypeConversion203[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_deg_TADLUTTblData[0];
  TRSC_InputAdapter_B.DataTypeConversion203[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_deg_TADLUTTblData[1];
  TRSC_InputAdapter_B.DataTypeConversion203[2] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_deg_TADLUTTblData[2];

  /* DataTypeConversion: '<Root>/Data Type Conversion168' */
  TRSC_InputAdapter_B.DataTypeConversion168[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_VehSpd_IGainLUTTblData[0];
  TRSC_InputAdapter_B.DataTypeConversion168[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_VehSpd_IGainLUTTblData[1];

  /* DataTypeConversion: '<Root>/Data Type Conversion171' */
  TRSC_InputAdapter_B.DataTypeConversion171[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_TravDistLUTTblData[0];
  TRSC_InputAdapter_B.DataTypeConversion171[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_TravDistLUTTblData[1];

  /* DataTypeConversion: '<Root>/Data Type Conversion172' */
  TRSC_InputAdapter_B.DataTypeConversion172[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_VehSpdLUTTblData[0];
  TRSC_InputAdapter_B.DataTypeConversion172[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_VehSpdLUTTblData[1];

  /* DataTypeConversion: '<Root>/Data Type Conversion174' */
  TRSC_InputAdapter_B.DataTypeConversion174[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_TAD_IGainLUTTblData[0];
  TRSC_InputAdapter_B.DataTypeConversion174[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_k_TAD_IGainLUTTblData[1];

  /* DataTypeConversion: '<Root>/Data Type Conversion179' */
  TRSC_InputAdapter_B.DataTypeConversion179[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_deg_TAD_IGainLUTBrkPts[0];
  TRSC_InputAdapter_B.DataTypeConversion179[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_deg_TAD_IGainLUTBrkPts[1];

  /* DataTypeConversion: '<Root>/Data Type Conversion180' */
  TRSC_InputAdapter_B.DataTypeConversion180[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_m_PGainLUTYBrkPts[0];
  TRSC_InputAdapter_B.DataTypeConversion180[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_m_PGainLUTYBrkPts[1];

  /* DataTypeConversion: '<Root>/Data Type Conversion181' */
  TRSC_InputAdapter_B.DataTypeConversion181[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_m_TravDistLUTBrkPts[0];
  TRSC_InputAdapter_B.DataTypeConversion181[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_m_TravDistLUTBrkPts[1];

  /* DataTypeConversion: '<Root>/Data Type Conversion182' */
  TRSC_InputAdapter_B.DataTypeConversion182[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_v_PGainLUTXBrkPts[0];
  TRSC_InputAdapter_B.DataTypeConversion182[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_v_PGainLUTXBrkPts[1];

  /* DataTypeConversion: '<Root>/Data Type Conversion183' */
  TRSC_InputAdapter_B.DataTypeConversion183[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_v_VehSpdLUTBrkPts[0];
  TRSC_InputAdapter_B.DataTypeConversion183[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_v_VehSpdLUTBrkPts[1];

  /* DataTypeConversion: '<Root>/Data Type Conversion185' */
  TRSC_InputAdapter_B.DataTypeConversion185[0] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_v_VehSpd_IGainLUTBrkPts[0];
  TRSC_InputAdapter_B.DataTypeConversion185[1] =
    rtu_IbTRSCSmVc_TunParam->KaTRA_v_VehSpd_IGainLUTBrkPts[1];

  /* DataTypeConversion: '<Root>/Data Type Conversion51' */
  TRSC_InputAdapter_B.DataTypeConversion51 =
    rtu_IbTRSC_MEVehInpFromCAN2IpcSignals->DataInp_TRANSM_FD_2.GearEngagedForDisplay;

  /* DataTypeConversion: '<Root>/Data Type Conversion103' */
  TRSC_InputAdapter_B.DataTypeConversion103 = (TeVBII_e_GearEngagedForDsply)
    TRSC_InputAdapter_B.DataTypeConversion51;

  /* DataTypeConversion: '<Root>/Data Type Conversion149' */
  TRSC_InputAdapter_B.DataTypeConversion149 =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_GyroYawCov;

  /* DataTypeConversion: '<Root>/Data Type Conversion150' */
  TRSC_InputAdapter_B.DataTypeConversion150 =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_NumWheelPulses;

  /* DataTypeConversion: '<Root>/Data Type Conversion151' */
  TRSC_InputAdapter_B.DataTypeConversion151 =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_TADCov;

  /* DataTypeConversion: '<Root>/Data Type Conversion155' */
  TRSC_InputAdapter_B.DataTypeConversion155 =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_WhlPlsCnt_high_lim;

  /* DataTypeConversion: '<Root>/Data Type Conversion156' */
  TRSC_InputAdapter_B.DataTypeConversion156 =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_WhlPlsCnt_low_lim;

  /* DataTypeConversion: '<Root>/Data Type Conversion157' */
  TRSC_InputAdapter_B.DataTypeConversion157 =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_WhlRPMYawCov;

  /* DataTypeConversion: '<Root>/Data Type Conversion158' */
  TRSC_InputAdapter_B.DataTypeConversion158 =
    rtu_IbTRSCSmVc_TunParam->KeKM_m_TrackWidth;

  /* DataTypeConversion: '<Root>/Data Type Conversion159' */
  TRSC_InputAdapter_B.DataTypeConversion159 =
    rtu_IbTRSCSmVc_TunParam->KeKM_m_WheelCircumference;

  /* DataTypeConversion: '<Root>/Data Type Conversion160' */
  TRSC_InputAdapter_B.DataTypeConversion160 =
    rtu_IbTRSCSmVc_TunParam->KeKM_s_SampleTime;

  /* DataTypeConversion: '<Root>/Data Type Conversion161' */
  TRSC_InputAdapter_B.DataTypeConversion161 =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_KM_YawRateGyroBiasInit;

  /* DataTypeConversion: '<Root>/Data Type Conversion162' */
  TRSC_InputAdapter_B.DataTypeConversion162 =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_KM_SF_RelAngCov;

  /* DataTypeConversion: '<Root>/Data Type Conversion163' */
  TRSC_InputAdapter_B.DataTypeConversion163 =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_KM_SF_RelAngRateCov;

  /* DataTypeConversion: '<Root>/Data Type Conversion164' */
  TRSC_InputAdapter_B.DataTypeConversion164 =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_KM_SF_YawRateCov;

  /* DataTypeConversion: '<Root>/Data Type Conversion165' */
  TRSC_InputAdapter_B.DataTypeConversion165 =
    rtu_IbTRSCSmVc_TunParam->KeTRA_m_K_beta;

  /* DataTypeConversion: '<Root>/Data Type Conversion166' */
  TRSC_InputAdapter_B.DataTypeConversion166 =
    rtu_IbTRSCSmVc_TunParam->KeKM_deg_AngTh;

  /* DataTypeConversion: '<Root>/Data Type Conversion173' */
  TRSC_InputAdapter_B.DataTypeConversion173 =
    rtu_IbTRSCSmVc_TunParam->KeTRA_k_Kp;

  /* DataTypeConversion: '<Root>/Data Type Conversion177' */
  TRSC_InputAdapter_B.DataTypeConversion177 =
    rtu_IbTRSCSmVc_TunParam->KeKM_k_SWA_Res;

  /* DataTypeConversion: '<Root>/Data Type Conversion188' */
  TRSC_InputAdapter_B.DataTypeConversion188 =
    rtu_IbTRSCSmVc_TunParam->KeTRA_k_SteerAngRateLmt;

  /* DataTypeConversion: '<Root>/Data Type Conversion191' */
  TRSC_InputAdapter_B.DataTypeConversion191 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_m_WheelBase;

  /* DataTypeConversion: '<Root>/Data Type Conversion192' */
  TRSC_InputAdapter_B.DataTypeConversion192 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_deg_MaxStrAngle;

  /* DataTypeConversion: '<Root>/Data Type Conversion193' */
  TRSC_InputAdapter_B.DataTypeConversion193 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_deg_MaxStrAngle_Up_Limit;

  /* DataTypeConversion: '<Root>/Data Type Conversion194' */
  TRSC_InputAdapter_B.DataTypeConversion194 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_deg_MaxStrAngle_Low_Limit;

  /* DataTypeConversion: '<Root>/Data Type Conversion195' */
  TRSC_InputAdapter_B.DataTypeConversion195 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_m_WheelBase_Up_Limit;

  /* DataTypeConversion: '<Root>/Data Type Conversion196' */
  TRSC_InputAdapter_B.DataTypeConversion196 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_m_WheelBase_Low_Limit;

  /* DataTypeConversion: '<Root>/Data Type Conversion197' */
  TRSC_InputAdapter_B.DataTypeConversion197 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_deg_KnobHys;

  /* DataTypeConversion: '<Root>/Data Type Conversion198' */
  TRSC_InputAdapter_B.DataTypeConversion198 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_pct_JackKnifePerc;

  /* DataTypeConversion: '<Root>/Data Type Conversion199' */
  TRSC_InputAdapter_B.DataTypeConversion199 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_deg_MaxKnobAngle;

  /* DataTypeConversion: '<Root>/Data Type Conversion200' */
  TRSC_InputAdapter_B.DataTypeConversion200 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_deg_MaxTrlrAngl;

  /* DataTypeConversion: '<Root>/Data Type Conversion201' */
  TRSC_InputAdapter_B.DataTypeConversion201 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_TADdes_k_PIDKd;

  /* DataTypeConversion: '<Root>/Data Type Conversion202' */
  TRSC_InputAdapter_B.DataTypeConversion202 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_TADep_k_PIDKp;

  /* DataTypeConversion: '<Root>/Data Type Conversion204' */
  TRSC_InputAdapter_B.DataTypeConversion204 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_deg_TGTADdesRateChange;

  /* DataTypeConversion: '<Root>/Data Type Conversion205' */
  TRSC_InputAdapter_B.DataTypeConversion205 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_deg_TAD_DesRateUpLim;

  /* DataTypeConversion: '<Root>/Data Type Conversion206' */
  TRSC_InputAdapter_B.DataTypeConversion206 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_deg_TrqCnt_UpLimit;

  /* DataTypeConversion: '<Root>/Data Type Conversion207' */
  TRSC_InputAdapter_B.DataTypeConversion207 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_deg_TrqCnt_LowLimit;

  /* DataTypeConversion: '<Root>/Data Type Conversion208' */
  TRSC_InputAdapter_B.DataTypeConversion208 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_k_JKAngle_UpLimit;

  /* DataTypeConversion: '<Root>/Data Type Conversion209' */
  TRSC_InputAdapter_B.DataTypeConversion209 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_k_JKAngle_LowLimit;

  /* DataTypeConversion: '<Root>/Data Type Conversion210' */
  TRSC_InputAdapter_B.DataTypeConversion210 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_k_LogVecLength;

  /* DataTypeConversion: '<Root>/Data Type Conversion211' */
  TRSC_InputAdapter_B.DataTypeConversion211 =
    rtu_IbTRSCSmVc_TunParam->KeKM_m_BeamLength;

  /* DataTypeConversion: '<Root>/Data Type Conversion212' */
  TRSC_InputAdapter_B.DataTypeConversion212 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_m_TBL_UpLimit;

  /* DataTypeConversion: '<Root>/Data Type Conversion213' */
  TRSC_InputAdapter_B.DataTypeConversion213 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_m_TBL_LowLimit;

  /* DataTypeConversion: '<Root>/Data Type Conversion214' */
  TRSC_InputAdapter_B.DataTypeConversion214 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_Cnt_FailedCnt;

  /* DataTypeConversion: '<Root>/Data Type Conversion215' */
  TRSC_InputAdapter_B.DataTypeConversion215 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_e_CamBlockAcceptLvl;

  /* DataTypeConversion: '<Root>/Data Type Conversion216' */
  TRSC_InputAdapter_B.DataTypeConversion216 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_kph_DeactivationSpd;

  /* DataTypeConversion: '<Root>/Data Type Conversion217' */
  TRSC_InputAdapter_B.DataTypeConversion217 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_pct_TrlrJackKnifePerc;

  /* DataTypeConversion: '<Root>/Data Type Conversion218' */
  TRSC_InputAdapter_B.DataTypeConversion218 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_s_ActTransRevDbnc2;

  /* DataTypeConversion: '<Root>/Data Type Conversion219' */
  TRSC_InputAdapter_B.DataTypeConversion219 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_s_CalibDlyTh;

  /* DataTypeConversion: '<Root>/Data Type Conversion220' */
  TRSC_InputAdapter_B.DataTypeConversion220 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_s_EpsRespTmOut;

  /* DataTypeConversion: '<Root>/Data Type Conversion221' */
  TRSC_InputAdapter_B.DataTypeConversion221 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_s_GearDbncTh;

  /* DataTypeConversion: '<Root>/Data Type Conversion222' */
  TRSC_InputAdapter_B.DataTypeConversion222 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_s_LEDTmrTh;

  /* DataTypeConversion: '<Root>/Data Type Conversion223' */
  TRSC_InputAdapter_B.DataTypeConversion223 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_s_RespNotRcvdTmOut;

  /* DataTypeConversion: '<Root>/Data Type Conversion224' */
  TRSC_InputAdapter_B.DataTypeConversion224 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_s_TrlrUnkwnSet;

  /* DataTypeConversion: '<Root>/Data Type Conversion225' */
  TRSC_InputAdapter_B.DataTypeConversion225 =
    rtu_IbTRSCSmVc_TunParam->KeTRSC_b_bValidFlag;

  /* DataTypeConversion: '<Root>/Data Type Conversion77' */
  TRSC_InputAdapter_B.DataTypeConversion77 =
    (TeTRSC_e_CalFail)rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_e_CalFail;

  /* DataTypeConversion: '<Root>/Data Type Conversion78' */
  TRSC_InputAdapter_B.DataTypeConversion78 =
    (TeTRSC_e_TrlrID)rtu_IbTrailerDet_TrailerDetInpBus->MeTRSC_e_TrailerID;
}

/* Model initialize function */
void TRSC_InputAdapter_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_TRSC_InputAdapter_T *const TRSC_InputAdapter_M =
    &(TRSC_InputAdapter_MdlrefDW.rtm);

  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(TRSC_InputAdapter_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
