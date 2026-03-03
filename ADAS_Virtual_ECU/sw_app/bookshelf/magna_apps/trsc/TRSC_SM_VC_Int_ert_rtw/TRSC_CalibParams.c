/*
 * File: TRSC_CalibParams.c
 *
 * Code generated for Simulink model 'TRSC_SM_VC_Int'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:53:44 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "TRSC_SM_VC_Int_types.h"

/* Exported data definition */

/* Definition for custom storage class: ExportToFile */
real32_T CeConst_k_ConstOne = 1.0F;
int16_T CeConst_k_ConstOneInt16 = 1;
uint8_T CeConst_k_ConstOneUint8 = 1U;
real32_T CeConst_k_ConstThree = 3.0F;
uint8_T CeConst_k_ConstThreeUint8 = 3U;
real32_T CeConst_k_ConstTwo = 2.0F;
uint8_T CeConst_k_ConstTwoUint8 = 2U;
real32_T CeConst_k_ConstZero = 0.0F;
uint16_T CeConst_k_ConstZeroUint16 = 0U;
uint8_T CeConst_k_ConstZeroUint8 = 0U;
real32_T CeConst_k_SnglTen = 10.0F;

/* Constant Ten */
real32_T CeConst_k_SnglTwentyFive = 25.0F;

/* Constant TwentyFive */
real32_T CeConst_k_SnglZero = 0.0F;

/* Constant Zero */
real32_T CeConst_ku_deg2rad = 0.0174532905F;
real32_T CeConst_mph_VehSpeedThr = 25.0F;

/* Vehicle speed Threshold */
boolean_T CeKM_b_False = 0;

/* Relative angle Covariance */
boolean_T CeKM_b_True = 1;

/* array of zeros for initialiation */
real32_T CeKM_deg_180 = 180.0F;

/* 180 degree */
real32_T CeKM_deg_360 = 360.0F;

/* 360 degree */
real32_T CeKM_k_ArrayZeros[3] = { 0.0F, 0.0F, 0.0F } ;

/* array of zeros for initialiation */
uint8_T CeKM_k_ConstFour = 4U;

/* Gear number four */
real32_T CeKM_k_pi = 3.14159274F;

/* Pi Constant */
real32_T CeTRA_deg_AngleNinety = 90.0F;

/* Angle 90 deg */
real32_T CeTRA_deg_AngleOneEighty = 180.0F;

/* Angle 180 degree */
real32_T CeTRA_deg_AngleThreeSixty = 360.0F;

/* Angle 360 degree */
real32_T CeTRA_k_ConstTen = 10.0F;

/* Constant value Ten */
real32_T CeTRA_k_OnePerHundred = 0.01F;

/* Constant value 0.01 used to calculate D-gain of PID controller */
real32_T CeTRA_k_fifteen = 15.0F;

/* Constant Value Fifteen */
real32_T CeTRA_sec_SampleTime = 0.03F;

/* sampling time */
int16_T CeTRSC_deg_KnobHysLowLim = 0;

/*  Lower Limit of Threshold value for Knob Hysteresis */
int16_T CeTRSC_deg_KnobHysUpLim = 5;

/* Upper Limit of Threshold value for Knob Hysteresis */
uint16_T CeTRSC_deg_MaxKnobAngleLowLim = 100U;

/* Maximum Knob Angle Lower Limit */
uint16_T CeTRSC_deg_MaxKnobAngleUpLim = 240U;

/* Maximum Knob Angle Upper Limit */
uint16_T CeTRSC_k_MaxJumpSizeLowLim = 35U;

/* Lower limit of Max Jump Size for Raw Knob Count */
uint16_T CeTRSC_k_MaxJumpSizeUpLim = 90U;

/* Upper limit of Max Jump Size for Raw Knob Count */
real32_T CeTRSC_k_SnglEight = 8.0F;

/* Constant 8 */
real32_T CeTRSC_s_TRSCLpTm = 0.03F;

/* TRSC Loop time */
boolean_T OTBL_EN = 1;

/* Volatile memory section */
/* Definition for custom storage class: Volatile */
volatile real32_T KM_SamplingTime = 0.03F;
volatile real32_T KaTRA_deg_TADLUTBrkPts[3] = { 0.0F, 7.0F, 15.0F } ;

/* Breakpoints for TAD LookUp Table  */
volatile real32_T KaTRA_deg_TADLUTTblData[3] = { 0.0F, 0.0F, 0.0F } ;

/* TAD Lookup Table Data */
volatile real32_T KaTRA_deg_TAD_IGainLUTBrkPts[2] = { 0.0F, 5.0F } ;

/* Breakpoints for I-Gain LookUp Table for TAD */
volatile real32_T KaTRA_k_PGainLUTTblData[4] = { 0.4F, 0.4F, 0.4F, 0.4F } ;

/* Table Data for P-Gain LookUp Table  */
volatile real32_T KaTRA_k_TADLUTTblData[3] = { 0.0F, 0.0F, 0.0F } ;

/* Table Data for TAD LookUp Table  */
volatile real32_T KaTRA_k_TAD_IGainLUTTblData[2] = { 0.0F, 0.0F } ;

/* Table data for I-Gain LookUp Table for TAD */
volatile real32_T KaTRA_k_TravDistLUTTblData[2] = { 0.0F, 1.0F } ;

/* Table data for Travel Distance LookUp Table */
volatile real32_T KaTRA_k_VehSpdLUTTblData[2] = { 0.0F, 1.0F } ;

/* Table data for Vehicle Speed LookUp Table  */
volatile real32_T KaTRA_k_VehSpd_HdgDeviatLUTTblData[3] = { 1.0F, 0.5F, 0.0F } ;

/* Table data for Heading Deviation LookUp Table  */
volatile real32_T KaTRA_k_VehSpd_IGainLUTTblData[2] = { 0.15F, 0.15F } ;

/* Table data for I-Gain LookUp Table for vehicle speed */
volatile real32_T KaTRA_m_PGainLUTYBrkPts[2] = { 1.4F, 8.2F } ;

/* Y-Breakpoints for P-Gain LookUp Table  */
volatile real32_T KaTRA_m_TravDistLUTBrkPts[2] = { 5.0F, 7.0F } ;

/* Breakpoints for Travel Distance LookUp Table */
volatile real32_T KaTRA_rate_RateGuardXdat[8] = { 0.0F, 1.3515625F, 2.0F, 3.0F,
  4.75F, 6.0F, 7.0F, 8.203125F } ;

/* Front Wheel to Steering Rate Guard X data */
volatile real32_T KaTRA_rate_RateGuardYdat[8] = { 13.1F, 13.1F, 12.0F, 10.4F,
  8.2F, 7.1F, 6.4F, 5.9F } ;

/* Front Wheel to Steering Rate Guard Y data */
volatile real32_T KaTRA_v_PGainLUTXBrkPts[2] = { 1.5F, 2.5F } ;

/* X-Breakpoints for P-Gain LookUp Table  */
volatile real32_T KaTRA_v_VehSpdLUTBrkPts[2] = { 0.1F, 0.3F } ;

/* Breakpoints for Vehicle Speed LookUp Table  */
volatile real32_T KaTRA_v_VehSpd_HdgDeviatLUTBrkPts[3] = { 4.0F, 5.5F, 7.0F } ;

/* Breakpoints for Heading Deviation LookUp Table */
volatile real32_T KaTRA_v_VehSpd_IGainLUTBrkPts[2] = { 0.0F, 3.0F } ;

/* Breakpoints for I-Gain LookUp Table  */
volatile real32_T KaTRSC_deg_FtWhlAngPts[37] = { -36.15F, -33.95F, -31.8F,
  -29.65F, -27.55F, -25.5F, -23.45F, -21.4F, -19.4F, -17.45F, -15.45F, -13.5F,
  -11.55F, -9.6F, -7.7F, -5.75F, -3.85F, -1.9F, 0.0F, 1.9F, 3.85F, 5.75F, 7.7F,
  9.6F, 11.55F, 13.5F, 15.45F, 17.45F, 19.4F, 21.4F, 23.45F, 25.5F, 27.55F,
  29.65F, 31.8F, 33.95F, 36.15F } ;

/* Maximum combined road wheel angle */
volatile real32_T KaTRSC_deg_PGainLUTYBPTyp1[5] = { 0.0F, 25.0F, 50.0F, 100.0F,
  570.0F } ;

/* Y Breakpoints for P Gain LookUp Table  */
volatile real32_T KaTRSC_deg_PGainLUTYBPTyp2[5] = { 0.0F, 25.0F, 50.0F, 100.0F,
  570.0F } ;

/* Y Breakpoints for P Gain LookUp Table  */
volatile real32_T KaTRSC_deg_PGainLUTYBPTyp3[5] = { 0.0F, 25.0F, 50.0F, 100.0F,
  570.0F } ;

/* Y Breakpoints for P Gain LookUp Table  */
volatile real32_T KaTRSC_deg_PGainLUTYBrkPts[5] = { 0.0F, 25.0F, 50.0F, 100.0F,
  570.0F } ;

/* Y Breakpoints for P Gain LookUp Table  */
volatile real32_T KaTRSC_deg_StwAngPts[37] = { -611.4F, -577.5F, -543.5F,
  -509.5F, -475.6F, -441.6F, -407.6F, -373.7F, -339.7F, -305.7F, -271.7F,
  -237.8F, -203.8F, -169.8F, -135.9F, -101.9F, -67.9F, -34.0F, 0.0F, 34.0F,
  67.9F, 101.9F, 135.9F, 169.8F, 203.8F, 237.8F, 271.7F, 305.7F, 339.7F, 373.7F,
  407.6F, 441.6F, 475.6F, 509.5F, 543.5F, 577.5F, 611.4F } ;

/* Steering road wheel Angle */
volatile real32_T KaTRSC_k_DampingGainTblData[4] = { 0.0F, 0.0F, 0.0F, 0.0F } ;

/* Table Data for Damping Gain LookUp Table  */
volatile real32_T KaTRSC_k_DiffGainTblData[4] = { 0.002F, 0.002F, 0.0015F,
  0.0012F } ;

/* Table Data for Differential Gain LookUp Table  */
volatile real32_T KaTRSC_k_InputRateLimTblData[4] = { 250.0F, 200.0F, 200.0F,
  200.0F } ;

/* Table Data for Input Rate Limit LookUp Table  */
volatile real32_T KaTRSC_k_IntGainTDTyp1[16] = { 0.025F, 0.025F, 0.025F, 0.025F,
  0.025F, 0.025F, 0.025F, 0.025F, 0.0175F, 0.0175F, 0.0175F, 0.0175F, 0.0125F,
  0.0125F, 0.0125F, 0.0125F } ;

/* Table Data for Integrator Gain LookUp Table  */
volatile real32_T KaTRSC_k_IntGainTDTyp2or3[16] = { 0.025F, 0.025F, 0.025F,
  0.025F, 0.025F, 0.025F, 0.025F, 0.025F, 0.0175F, 0.0175F, 0.0175F, 0.0175F,
  0.0125F, 0.0125F, 0.0125F, 0.0125F } ;

/* Table Data for Integrator Gain LookUp Table  */
volatile real32_T KaTRSC_k_IntegratorExtSatTblData[4] = { 3.5F, 2.0F, 2.0F, 1.0F
} ;

/* Table Data for Integrator External Saturation LookUp Table  */
volatile real32_T KaTRSC_k_IntegratorGainTblData[4] = { 0.05F, 0.05F, 0.035F,
  0.025F } ;

/* Table Data for Integrator Gain LookUp Table  */
volatile real32_T KaTRSC_k_PGainLUTTDTyp1[20] = { 1.5F, 1.5F, 1.5F, 1.5F, 1.5F,
  1.5F, 1.5F, 1.5F, 1.25F, 1.25F, 1.25F, 1.25F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F } ;

/* Table Data for P Gain LookUp Table  */
volatile real32_T KaTRSC_k_PGainLUTTDTyp2[20] = { 1.5F, 1.5F, 1.5F, 1.5F, 1.5F,
  1.5F, 1.5F, 1.5F, 1.25F, 1.25F, 1.25F, 1.25F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F } ;

/* Table Data for P Gain LookUp Table  */
volatile real32_T KaTRSC_k_PGainLUTTDTyp3[20] = { 1.5F, 1.5F, 1.5F, 1.5F, 1.5F,
  1.5F, 1.5F, 1.5F, 1.25F, 1.25F, 1.25F, 1.25F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F } ;

/* Table Data for P Gain LookUp Table  */
volatile real32_T KaTRSC_k_PGainLUTTblData[20] = { 0.01F, 0.01F, 0.07F, 0.05F,
  0.01F, 0.01F, 0.07F, 0.05F, 0.01F, 0.01F, 0.07F, 0.05F, 0.01F, 0.01F, 0.07F,
  0.05F, 0.01F, 0.01F, 0.07F, 0.05F } ;

/* Table Data for P Gain LookUp Table  */
volatile real32_T KaTRSC_kph_DampingGainBrkPts[4] = { 0.0F, 2.0F, 5.0F, 10.0F } ;

/* Breakpoints for Damping Gain LookUp Table  */
volatile real32_T KaTRSC_kph_DiffGainBrkPts[4] = { 0.0F, 2.0F, 5.0F, 10.0F } ;

/* Breakpoints for Differential Gain LookUp Table  */
volatile real32_T KaTRSC_kph_InputRateLimBrkPts[4] = { 0.0F, 2.0F, 5.0F, 10.0F }
;

/* Breakpoints for Input Rate Limit LookUp Table  */
volatile real32_T KaTRSC_kph_IntGainBPTyp1[4] = { 0.0F, 2.0F, 5.0F, 10.0F } ;

/* Breakpoints for Integrator Gain LookUp Table  */
volatile real32_T KaTRSC_kph_IntGainBPTyp2or3[4] = { 0.0F, 2.0F, 5.0F, 10.0F } ;

/* Breakpoints for Integrator Gain LookUp Table  */
volatile real32_T KaTRSC_kph_IntegratorExtSatBrkPts[4] = { 0.0F, 2.0F, 5.0F,
  10.0F } ;

/* Breakpoints for Integrator External Saturation LookUp Table  */
volatile real32_T KaTRSC_kph_IntegratorGainBrkPts[4] = { 0.0F, 2.0F, 5.0F, 10.0F
} ;

/* Breakpoints for Integrator Gain LookUp Table  */
volatile real32_T KaTRSC_kph_PGainLUTXBPTyp1[4] = { 0.0F, 2.0F, 5.0F, 10.0F } ;

/* X Breakpoints for P Gain LookUp Table  */
volatile real32_T KaTRSC_kph_PGainLUTXBPTyp2[4] = { 0.0F, 2.0F, 5.0F, 10.0F } ;

/* X Breakpoints for P Gain LookUp Table  */
volatile real32_T KaTRSC_kph_PGainLUTXBPTyp3[4] = { 0.0F, 2.0F, 5.0F, 10.0F } ;

/* X Breakpoints for P Gain LookUp Table  */
volatile real32_T KaTRSC_kph_PGainLUTXBrkPts[4] = { 0.0F, 2.0F, 5.0F, 10.0F } ;

/* X Breakpoints for P Gain LookUp Table  */
volatile real32_T KeKM_deg_AngTh = 0.1F;

/* steering wheel threshold value to compare steering wheel angle. */
volatile real32_T KeKM_k_GyroYawCov = 0.0144F;

/* Gyro Yaw Covariance   */
volatile real32_T KeKM_k_KM_SF_RelAngCov = 0.01F;

/* Relative angle Covariance */
volatile real32_T KeKM_k_KM_SF_RelAngRateCov = 0.01F;

/* Relative angle rate covariance   */
volatile real32_T KeKM_k_KM_SF_YawRateCov = 0.1F;

/* Yaw Rate Covariance */
volatile real32_T KeKM_k_KM_YawRateGyroBiasInit = 0.0F;

/* Yaw rate Gyro bias initialization */
volatile real32_T KeKM_k_NumWheelPulses = 96.0F;

/* Number of wheel pulses */
volatile real32_T KeKM_k_SWA_Res = 0.1F;

/* Steering Wheel Angle Resolution */
volatile real32_T KeKM_k_TADCov = 0.0001F;

/* Trailer Angle Detection Covariance   */
volatile real32_T KeKM_k_UpdateIMU_H[3] = { 1.0F, 0.0F, 0.0F } ;

/* Update IMU measurement matrix */
volatile real32_T KeKM_k_UpdateRPM_H[3] = { 1.0F, 0.0F, 0.0F } ;

/* Update RPM measurement matrix */
volatile real32_T KeKM_k_UpdateTAD_H[3] = { 0.0F, 0.0F, 1.0F } ;

/* Update TAD measurement matrix */
volatile real32_T KeKM_k_WhlPlsCnt_high_lim = 255.0F;

/* Wheel Pulse count high limit */
volatile real32_T KeKM_k_WhlPlsCnt_low_lim = 0.0F;

/* Wheel Pulse count low limit */
volatile real32_T KeKM_k_WhlRPMYawCov = 0.01F;

/* Wheel RPM Yaw Covariance   */
volatile real32_T KeKM_m_BeamLength = 2.5F;

/* Beam Length */
volatile real32_T KeKM_m_TrackWidth = 1.73F;

/* Track Width */
volatile real32_T KeKM_m_WheelCircumference = 2.5F;

/* Wheel circumference */
volatile real32_T KeKM_s_SampleTime = 0.03F;

/* sampling time */
volatile real32_T KeTRA_deg_TrailerBeamLenYBrkPts[3] = { 20.0F, 25.0F, 30.0F } ;

/* Trailer Beam Length Y Data Break Point */
volatile real32_T KeTRA_k_Kp = 5.0F;

/* Kp value(5) used to calculate P-gain of PID controller */
volatile real32_T KeTRA_k_SteerAngRateLmt = 700.0F;

/* Control Steering Angle Rate Upper Limit */
volatile real32_T KeTRA_m_K_beta = 1.5F;

/* Calibration Value Beta used for P-Gain in PID */
volatile real32_T KeTRA_m_TrailerBeamLenXBrkPts[3] = { 1.0F, 4.6F, 8.0F } ;

/* X-Breakpoints for Trailer Beam Length */
volatile uint8_T KeTRSC_Cnt_FailedCnt = 5U;

/* Failed Count */
volatile real32_T KeTRSC_Nm_MaxTrqLim = 1.0F;

/* KeTRSC_Nm_MaxTrqLim */
volatile real32_T KeTRSC_TADdes_k_PIDKd = 0.0F;

/* TAD Des PID Derevative Gain */
volatile real32_T KeTRSC_TADep_k_PIDKp = 3.0F;

/* TAD Dep PID Propotional Gain */
volatile boolean_T KeTRSC_b_BypTunParam = 1;

/* Calibration to Bypass Tunable Params from BSW */
volatile boolean_T KeTRSC_b_BypassRadDsplyTyp = 1;

/* Bypass RadDsplyTyp check for TRSC Enable Button Sts */
volatile boolean_T KeTRSC_b_EnblDrvDctcOvrd = 0;
volatile boolean_T KeTRSC_b_EnblExtFault = 1;

/* Enable External Faults */
volatile boolean_T KeTRSC_b_ForceJKCalc = 0;

/* Force JK calculation */
volatile boolean_T KeTRSC_b_HardcodeTBLflag = 0;

/* Flag to enable/disable TBL hardcoding */
volatile uint8_T KeTRSC_cnt_AvgSampleCnt = 5U;
volatile real32_T KeTRSC_cnt_DrvOvrdTurnOnDlyTime = 0.5F;
volatile real32_T KeTRSC_cnt_OvrSpdThr = 10.0F;

/* Over speed counter based on Maximum speed limit request  */
volatile real32_T KeTRSC_cnt_ResetOvrSpdThr = 2.0F;

/* Over speed counter based on Maximum speed limit request  */
volatile real32_T KeTRSC_dM_StrTrqCmdRateLmtForDrvOvrd = 1.95F;
volatile real32_T KeTRSC_ddeg_SmTrqRateLimNonActv = 2.0F;

/* State Machine TrqRateLim NonActv State */
volatile real32_T KeTRSC_ddeg_TadDesRateLim = 10.0F;

/* Desired Trailer Angle rate limit for TAD Error computation */
volatile int16_T KeTRSC_deg_KnobHys = 5;

/* Threshold value for Knob Hysteresis */
volatile uint16_T KeTRSC_deg_MaxKnobAngle = 120U;

/* Maximum Knob Angle */
volatile real32_T KeTRSC_deg_MaxStrAngTyp1 = 540.0F;

/* Maximum Steering Angle threshold */
volatile real32_T KeTRSC_deg_MaxStrAngTyp2 = 650.0F;

/* Maximum Steering Angle threshold */
volatile real32_T KeTRSC_deg_MaxStrAngle = 579.0F;

/* Maximum Steering Angle threshold */
volatile real32_T KeTRSC_deg_MaxStrAngle_Low_Limit = 500.0F;

/* Maximum Steering Angle threshold Low Limit */
volatile real32_T KeTRSC_deg_MaxStrAngle_Up_Limit = 700.0F;

/* Maximum Steering Angle threshold Up Limit */
volatile real32_T KeTRSC_deg_MaxTrlrAngl = 53.0F;

/* Maximum Trailer Angle */
volatile real32_T KeTRSC_deg_TADErrSpdLmtLowThr = 7.0F;

/* TADErrSpdLmtLowThr */
volatile real32_T KeTRSC_deg_TADErrSpdLmtMidThr = 15.0F;

/* TADErrSpdLmtMidThr */
volatile real32_T KeTRSC_deg_TAD_DesRateUpLim = 20.0F;

/* TAD des Rate change Up Limit */
volatile real32_T KeTRSC_deg_TGTADdesRateChange = 100.0F;

/* TAD des Rate change */
volatile real32_T KeTRSC_deg_TadCornerCaseThr = 10.0F;

/* TAD angle threshold for corner case */
volatile real32_T KeTRSC_deg_TadErrSatLim = 15.0F;

/* Saturation Limit for TAD error */
volatile real32_T KeTRSC_deg_TrqCnt_LowLimit = -2.0F;

/* Torque Control Lowe Limit */
volatile real32_T KeTRSC_deg_TrqCnt_UpLimit = 2.0F;

/* Torque Control Upper Limit */
volatile real32_T KeTRSC_deg_TwitchTrqRateLim = 200.0F;

/* trq rate limit for twitch */
volatile real32_T KeTRSC_deg_Zero = 0.0F;

/* lower saturation value for Trailer Protection Angle  */
volatile int16_T KeTRSC_deg_ZeroInt16 = 0;

/* lower saturation value for Trailer Protection Angle  */
volatile int16_T KeTRSC_deg_ZeroPadUpThr = 2;
volatile uint8_T KeTRSC_e_CamBlockAcceptLvl = 50U;

/* acceptance value */
volatile real32_T KeTRSC_k_EnblJKPrevention = 1.0F;

/* flag to Enable JK Prevention logic in TAD PID */
volatile real32_T KeTRSC_k_ErrSatLim[4] = { 200.0F, 1500.0F, 1500.0F, 1500.0F } ;

/* steering Error saturation limit
 */
volatile real32_T KeTRSC_k_IntExtSat = 3.5F;

/* Integrator Saturation Limit */
volatile real32_T KeTRSC_k_JKAngle_LowLimit = 20.0F;

/* Jack Knife Angle Lower Limit */
volatile real32_T KeTRSC_k_JKAngle_UpLimit = 95.0F;

/* Jack Knife Angle Upper Limit */
volatile real32_T KeTRSC_k_LogVecLength = 4000.0F;

/* Log Vehicle Length */
volatile uint16_T KeTRSC_k_MaxJumpSize = 90U;

/* Max Jump Size for Raw Knob Count */
volatile real32_T KeTRSC_k_NegSteerWheelThreshold = -1000.0F;

/* Negative Steering angle threshold for TRSC activation for corner case1 */
volatile real32_T KeTRSC_k_NegativeTadAngleThreshold = -100.0F;

/* Negative TAD angle threshold for TRSC activation for corner case1 */
volatile real32_T KeTRSC_k_NumTwitchPulse = 2.0F;

/* Number of PWM pulses for twitch */
volatile real32_T KeTRSC_k_PIDKdPathDeviation = 0.0F;

/* Path Deviation PID control D gain */
volatile real32_T KeTRSC_k_PosSteerWheelThreshold = 1000.0F;

/* Positive Steering angle threshold for TRSC activation for corner case1 */
volatile real32_T KeTRSC_k_PositiveTadAngleThreshold = 100.0F;

/* Positive TAD angle threshold for TRSC activation for corner case1 */
volatile real32_T KeTRSC_k_StrCtrlLPFFrequency = 3.0F;

/* Steering_controller_low_pass_filter_frequency
 */
volatile real32_T KeTRSC_k_StrRptLPFFrequency = 3.0F;

/* Steering_controller_low_pass_filter_frequency
 */
volatile real32_T KeTRSC_k_StrTrqPercThresholdForDrvOvrd = 0.9F;

/* Percentage value to enable false driver override prevention code */
volatile real32_T KeTRSC_k_TadPidPGainMult = 1.0F;

/* TAD PID P gain multiplier for non-zero Knob angle */
volatile real32_T KeTRSC_k_TrqConstRateLim = 50.0F;

/* Constant Rate Limit for Torque  */
volatile real32_T KeTRSC_k_TrqConstSatLim = 5.0F;

/* Constant Saturation Limit for Torque  */
volatile real32_T KeTRSC_k_TrqCtrlDMultiplier[4] = { 0.0F, 0.0F, 0.0F, 0.0F } ;

/* Torque controller D multiplier */
volatile real32_T KeTRSC_k_TrqCtrlIMultiplier[4] = { 1.0F, 0.5F, 0.3F, 0.2F } ;

/* Torque controller I multiplier */
volatile real32_T KeTRSC_k_TrqCtrlPMultiplierT1[4] = { 0.015F, 0.008F, 0.008F,
  0.008F } ;

/* Torque controller P multiplier */
volatile real32_T KeTRSC_k_TrqCtrlPMultiplierT2or3[4] = { 0.02F, 0.01F, 0.01F,
  0.01F } ;

/* Torque controller P multiplier */
volatile uint8_T KeTRSC_k_VariantID = 5U;

/* Variant ID  */
volatile real32_T KeTRSC_k_WhlAngCFBias = -0.0129193F;

/* KeTRSC_k_WhlAngCFBias */
volatile real32_T KeTRSC_k_WhlAngCFWt = -0.0670865F;

/* KeTRSC_k_WhlAngCFWt */
volatile real32_T KeTRSC_kph_DeactivationSpd = 2.0F;

/* DEACTIVATION_SPD */
volatile real32_T KeTRSC_kph_MaxSpdLimThr = 7.0F;

/* Vehicle speed threshold based on Maximum speed limit request */
volatile real32_T KeTRSC_m_DesAnglScaleTBLThr[4] = { 2.0F, 3.25F, 4.0F, 13.0F } ;

/* Desired Trlr Angle TBL Threshold */
volatile real32_T KeTRSC_m_DesAnglScaleTBLThrSM = 3.3F;

/* TBL Threshold for TAD angle limit for activation */
volatile real32_T KeTRSC_m_HardcodedTBL = 4.0F;

/* Hardcoded TBL value */
volatile real32_T KeTRSC_m_SprLimitTBLThr = 3.5F;

/* Trailer Beam Length Upper Limit */
volatile real32_T KeTRSC_m_SprLimitTBLThr1 = 2.7F;

/* Trailer Beam Length Upper Limit */
volatile real32_T KeTRSC_m_TBL_LowLimit = 1.8F;

/* Trailer Beam Length Lower Limit */
volatile real32_T KeTRSC_m_TBL_UpLimit = 8.0F;

/* Trailer Beam Length Upper Limit */
volatile real32_T KeTRSC_m_WheelBase = 3.8989F;

/* Wheel base of the host vehicle */
volatile real32_T KeTRSC_m_WheelBase_Low_Limit = 3.0F;

/* Wheel base of the host vehicle Low Limit */
volatile real32_T KeTRSC_m_WheelBase_Up_Limit = 5.0F;

/* Wheel base of the host vehicle Up Limit */
volatile real32_T KeTRSC_mph_SpdThrActivation = 6.2F;

/* Vehicle Speed Threshold for TRSC activation */
volatile real32_T KeTRSC_pct_4kphSpdThr = 0.5F;

/* Percentage Threshold for 4 kph Speed Limit Req */
volatile real32_T KeTRSC_pct_5kphSpdThr = 0.35F;

/* Percentage Threshold for 5 kph Speed Limit Req */
volatile real32_T KeTRSC_pct_6kphSpdThr = 0.2F;

/* Percentage Threshold for 6 kph Speed Limit Req */
volatile real32_T KeTRSC_pct_7kphSpdThr = 0.1F;

/* Percentage Threshold for 7 kph Speed Limit Req */
volatile real32_T KeTRSC_pct_8kphSpdThr = 0.0F;

/* Percentage Threshold for 8 kph Speed Limit Req */
volatile real32_T KeTRSC_pct_9kphSpdThr = 0.0F;

/* Percentage Threshold for 8 kph Speed Limit Req */
volatile real32_T KeTRSC_pct_JackKnifePerc = 85.0F;

/* JackKnife Angle Percentage */
volatile real32_T KeTRSC_pct_StrCornerCaseThr = 0.4F;

/* Percentage Max Steering wheel angle threshold for corner case */
volatile real32_T KeTRSC_pct_TrlrAngScaleDwnPct[4] = { 0.9F, 0.9F, 1.0F, 1.0F } ;

/* Percentage to scale down KnobAngle based on TBL */
volatile real32_T KeTRSC_pct_TrlrAngScaleDwnPctSM = 0.9F;

/* Desired Trlr Angle TBL Threshold */
volatile real32_T KeTRSC_pct_TrlrJackKnifePerc = 95.0F;

/* TRAILER_JACKNIFE_PERCENT */
volatile real32_T KeTRSC_s_ActTransRevDbnc2 = 1.0F;

/* ACTUAL_TRANS_REVERSE_DEBOUNCE_2 */
volatile real32_T KeTRSC_s_CalibDlyTh = 1.0F;

/* Calibration Delay (1000 ms) */
volatile real32_T KeTRSC_s_DeactSpdTime = 2.0F;

/* DEACTIVATON_SPD_TIME */
volatile real32_T KeTRSC_s_EightSecTh = 8.0F;

/* Display timer threshold (8 Sec) used for Disply popup */
volatile real32_T KeTRSC_s_EpsRespTmOut = 3.0F;

/* EPS_RESPONSE_TIME_OUT */
volatile real32_T KeTRSC_s_FifteenSecTh = 15.0F;

/* 15 sec */
volatile real32_T KeTRSC_s_FiveSecTh = 5.0F;

/* LED timer threshold (5 Sec) used for blinking */
volatile real32_T KeTRSC_s_GearDbncTh = 0.35F;

/* Gear Debounce timer threshold = 350 msec */
volatile real32_T KeTRSC_s_HeldThreshold = 4.0F;

/* Time threshold to ensure user is actually requesting knob zero
 */
volatile real32_T KeTRSC_s_LEDTmrTh = 5.0F;

/* LED timer threshold (5 Sec) used for blinking */
volatile real32_T KeTRSC_s_RespNotRcvdTmOut = 0.3F;

/* RESPONSE_NOT_RECEIVED_TIME_OUT (300 msec) */
volatile real32_T KeTRSC_s_TRSCCornerCasAtc = 0.06F;

/* Time limit for TRSCCornerCasAtc */
volatile real32_T KeTRSC_s_TblKmDelay = 0.1F;

/* Systemic delay for KM signal i.e. speed and yaw specified in seconds */
volatile real32_T KeTRSC_s_TenMinTh = 600.0F;

/* 10 Min = 600 seconds timer threshold */
volatile real32_T KeTRSC_s_ThirtySecTh = 30.0F;

/* 30 sec */
volatile real32_T KeTRSC_s_TrlrUnkwnSet = 10.0F;

/* TRAILER_UNKNOWN_SET = 10 sec */
volatile real32_T KeTRSC_s_TwitchTime = 0.24F;

/* KeTRSC_s_TwitchTime */
volatile real32_T KeTRSC_s_TwoSecTh = 2.0F;

/* LED timer threshold (2 Sec) used for blinking */
volatile real32_T KeTRSC_sec_CornerCaseLatchLimit = 4.0F;

/* Corner case latch limit
 */
volatile real32_T KeTRSC_sec_CornerCaseTimeLimit = 2.0F;

/* Corner case identification limit
 */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
