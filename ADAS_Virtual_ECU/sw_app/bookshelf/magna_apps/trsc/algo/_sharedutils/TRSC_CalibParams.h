/*
 * File: TRSC_CalibParams.h
 *
 * Code generated for Simulink model 'TRSC_VC'.
 *
 * Model version                  : 1.7705
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:52:03 2025
 */

#ifndef RTW_HEADER_TRSC_CalibParams_h_
#define RTW_HEADER_TRSC_CalibParams_h_
#include "rtwtypes.h"

/* Exported data declaration */
/* Declaration for custom storage class: ExportToFile */
extern real32_T CeConst_k_ConstOne;
extern int16_T CeConst_k_ConstOneInt16;
extern uint8_T CeConst_k_ConstOneUint8;
extern real32_T CeConst_k_ConstThree;
extern uint8_T CeConst_k_ConstThreeUint8;
extern real32_T CeConst_k_ConstTwo;
extern uint8_T CeConst_k_ConstTwoUint8;
extern real32_T CeConst_k_ConstZero;
extern uint16_T CeConst_k_ConstZeroUint16;
extern uint8_T CeConst_k_ConstZeroUint8;
extern real32_T CeConst_k_SnglTen;

/* Constant Ten */
extern real32_T CeConst_k_SnglTwentyFive;

/* Constant TwentyFive */
extern real32_T CeConst_k_SnglZero;

/* Constant Zero */
extern real32_T CeConst_ku_deg2rad;
extern real32_T CeConst_mph_VehSpeedThr;

/* Vehicle speed Threshold */
extern boolean_T CeKM_b_False;

/* Relative angle Covariance */
extern boolean_T CeKM_b_True;

/* array of zeros for initialiation */
extern real32_T CeKM_deg_180;

/* 180 degree */
extern real32_T CeKM_deg_360;

/* 360 degree */
extern real32_T CeKM_k_ArrayZeros[3];

/* array of zeros for initialiation */
extern uint8_T CeKM_k_ConstFour;

/* Gear number four */
extern real32_T CeKM_k_pi;

/* Pi Constant */
extern real32_T CeTRA_deg_AngleNinety;

/* Angle 90 deg */
extern real32_T CeTRA_deg_AngleOneEighty;

/* Angle 180 degree */
extern real32_T CeTRA_deg_AngleThreeSixty;

/* Angle 360 degree */
extern real32_T CeTRA_k_ConstTen;

/* Constant value Ten */
extern real32_T CeTRA_k_OnePerHundred;

/* Constant value 0.01 used to calculate D-gain of PID controller */
extern real32_T CeTRA_k_fifteen;

/* Constant Value Fifteen */
extern real32_T CeTRA_sec_SampleTime;

/* sampling time */
extern int16_T CeTRSC_deg_KnobHysLowLim;

/*  Lower Limit of Threshold value for Knob Hysteresis */
extern int16_T CeTRSC_deg_KnobHysUpLim;

/* Upper Limit of Threshold value for Knob Hysteresis */
extern uint16_T CeTRSC_deg_MaxKnobAngleLowLim;

/* Maximum Knob Angle Lower Limit */
extern uint16_T CeTRSC_deg_MaxKnobAngleUpLim;

/* Maximum Knob Angle Upper Limit */
extern uint16_T CeTRSC_k_MaxJumpSizeLowLim;

/* Lower limit of Max Jump Size for Raw Knob Count */
extern uint16_T CeTRSC_k_MaxJumpSizeUpLim;

/* Upper limit of Max Jump Size for Raw Knob Count */
extern real32_T CeTRSC_k_SnglEight;

/* Constant 8 */
extern real32_T CeTRSC_s_TRSCLpTm;

/* TRSC Loop time */
extern boolean_T OTBL_EN;

/* Volatile memory section */
/* Declaration for custom storage class: Volatile */
extern volatile real32_T KM_SamplingTime;
extern volatile real32_T KaTRA_deg_TADLUTBrkPts[3];

/* Breakpoints for TAD LookUp Table  */
extern volatile real32_T KaTRA_deg_TADLUTTblData[3];

/* TAD Lookup Table Data */
extern volatile real32_T KaTRA_deg_TAD_IGainLUTBrkPts[2];

/* Breakpoints for I-Gain LookUp Table for TAD */
extern volatile real32_T KaTRA_k_PGainLUTTblData[4];

/* Table Data for P-Gain LookUp Table  */
extern volatile real32_T KaTRA_k_TADLUTTblData[3];

/* Table Data for TAD LookUp Table  */
extern volatile real32_T KaTRA_k_TAD_IGainLUTTblData[2];

/* Table data for I-Gain LookUp Table for TAD */
extern volatile real32_T KaTRA_k_TravDistLUTTblData[2];

/* Table data for Travel Distance LookUp Table */
extern volatile real32_T KaTRA_k_VehSpdLUTTblData[2];

/* Table data for Vehicle Speed LookUp Table  */
extern volatile real32_T KaTRA_k_VehSpd_HdgDeviatLUTTblData[3];

/* Table data for Heading Deviation LookUp Table  */
extern volatile real32_T KaTRA_k_VehSpd_IGainLUTTblData[2];

/* Table data for I-Gain LookUp Table for vehicle speed */
extern volatile real32_T KaTRA_m_PGainLUTYBrkPts[2];

/* Y-Breakpoints for P-Gain LookUp Table  */
extern volatile real32_T KaTRA_m_TravDistLUTBrkPts[2];

/* Breakpoints for Travel Distance LookUp Table */
extern volatile real32_T KaTRA_rate_RateGuardXdat[8];

/* Front Wheel to Steering Rate Guard X data */
extern volatile real32_T KaTRA_rate_RateGuardYdat[8];

/* Front Wheel to Steering Rate Guard Y data */
extern volatile real32_T KaTRA_v_PGainLUTXBrkPts[2];

/* X-Breakpoints for P-Gain LookUp Table  */
extern volatile real32_T KaTRA_v_VehSpdLUTBrkPts[2];

/* Breakpoints for Vehicle Speed LookUp Table  */
extern volatile real32_T KaTRA_v_VehSpd_HdgDeviatLUTBrkPts[3];

/* Breakpoints for Heading Deviation LookUp Table */
extern volatile real32_T KaTRA_v_VehSpd_IGainLUTBrkPts[2];

/* Breakpoints for I-Gain LookUp Table  */
extern volatile real32_T KaTRSC_deg_FtWhlAngPts[37];

/* Maximum combined road wheel angle */
extern volatile real32_T KaTRSC_deg_PGainLUTYBPTyp1[5];

/* Y Breakpoints for P Gain LookUp Table  */
extern volatile real32_T KaTRSC_deg_PGainLUTYBPTyp2[5];

/* Y Breakpoints for P Gain LookUp Table  */
extern volatile real32_T KaTRSC_deg_PGainLUTYBPTyp3[5];

/* Y Breakpoints for P Gain LookUp Table  */
extern volatile real32_T KaTRSC_deg_PGainLUTYBrkPts[5];

/* Y Breakpoints for P Gain LookUp Table  */
extern volatile real32_T KaTRSC_deg_StwAngPts[37];

/* Steering road wheel Angle */
extern volatile real32_T KaTRSC_k_DampingGainTblData[4];

/* Table Data for Damping Gain LookUp Table  */
extern volatile real32_T KaTRSC_k_DiffGainTblData[4];

/* Table Data for Differential Gain LookUp Table  */
extern volatile real32_T KaTRSC_k_InputRateLimTblData[4];

/* Table Data for Input Rate Limit LookUp Table  */
extern volatile real32_T KaTRSC_k_IntGainTDTyp1[16];

/* Table Data for Integrator Gain LookUp Table  */
extern volatile real32_T KaTRSC_k_IntGainTDTyp2or3[16];

/* Table Data for Integrator Gain LookUp Table  */
extern volatile real32_T KaTRSC_k_IntegratorExtSatTblData[4];

/* Table Data for Integrator External Saturation LookUp Table  */
extern volatile real32_T KaTRSC_k_IntegratorGainTblData[4];

/* Table Data for Integrator Gain LookUp Table  */
extern volatile real32_T KaTRSC_k_PGainLUTTDTyp1[20];

/* Table Data for P Gain LookUp Table  */
extern volatile real32_T KaTRSC_k_PGainLUTTDTyp2[20];

/* Table Data for P Gain LookUp Table  */
extern volatile real32_T KaTRSC_k_PGainLUTTDTyp3[20];

/* Table Data for P Gain LookUp Table  */
extern volatile real32_T KaTRSC_k_PGainLUTTblData[20];

/* Table Data for P Gain LookUp Table  */
extern volatile real32_T KaTRSC_kph_DampingGainBrkPts[4];

/* Breakpoints for Damping Gain LookUp Table  */
extern volatile real32_T KaTRSC_kph_DiffGainBrkPts[4];

/* Breakpoints for Differential Gain LookUp Table  */
extern volatile real32_T KaTRSC_kph_InputRateLimBrkPts[4];

/* Breakpoints for Input Rate Limit LookUp Table  */
extern volatile real32_T KaTRSC_kph_IntGainBPTyp1[4];

/* Breakpoints for Integrator Gain LookUp Table  */
extern volatile real32_T KaTRSC_kph_IntGainBPTyp2or3[4];

/* Breakpoints for Integrator Gain LookUp Table  */
extern volatile real32_T KaTRSC_kph_IntegratorExtSatBrkPts[4];

/* Breakpoints for Integrator External Saturation LookUp Table  */
extern volatile real32_T KaTRSC_kph_IntegratorGainBrkPts[4];

/* Breakpoints for Integrator Gain LookUp Table  */
extern volatile real32_T KaTRSC_kph_PGainLUTXBPTyp1[4];

/* X Breakpoints for P Gain LookUp Table  */
extern volatile real32_T KaTRSC_kph_PGainLUTXBPTyp2[4];

/* X Breakpoints for P Gain LookUp Table  */
extern volatile real32_T KaTRSC_kph_PGainLUTXBPTyp3[4];

/* X Breakpoints for P Gain LookUp Table  */
extern volatile real32_T KaTRSC_kph_PGainLUTXBrkPts[4];

/* X Breakpoints for P Gain LookUp Table  */
extern volatile real32_T KeKM_deg_AngTh;

/* steering wheel threshold value to compare steering wheel angle. */
extern volatile real32_T KeKM_k_GyroYawCov;

/* Gyro Yaw Covariance   */
extern volatile real32_T KeKM_k_KM_SF_RelAngCov;

/* Relative angle Covariance */
extern volatile real32_T KeKM_k_KM_SF_RelAngRateCov;

/* Relative angle rate covariance   */
extern volatile real32_T KeKM_k_KM_SF_YawRateCov;

/* Yaw Rate Covariance */
extern volatile real32_T KeKM_k_KM_YawRateGyroBiasInit;

/* Yaw rate Gyro bias initialization */
extern volatile real32_T KeKM_k_NumWheelPulses;

/* Number of wheel pulses */
extern volatile real32_T KeKM_k_SWA_Res;

/* Steering Wheel Angle Resolution */
extern volatile real32_T KeKM_k_TADCov;

/* Trailer Angle Detection Covariance   */
extern volatile real32_T KeKM_k_UpdateIMU_H[3];

/* Update IMU measurement matrix */
extern volatile real32_T KeKM_k_UpdateRPM_H[3];

/* Update RPM measurement matrix */
extern volatile real32_T KeKM_k_UpdateTAD_H[3];

/* Update TAD measurement matrix */
extern volatile real32_T KeKM_k_WhlPlsCnt_high_lim;

/* Wheel Pulse count high limit */
extern volatile real32_T KeKM_k_WhlPlsCnt_low_lim;

/* Wheel Pulse count low limit */
extern volatile real32_T KeKM_k_WhlRPMYawCov;

/* Wheel RPM Yaw Covariance   */
extern volatile real32_T KeKM_m_BeamLength;

/* Beam Length */
extern volatile real32_T KeKM_m_TrackWidth;

/* Track Width */
extern volatile real32_T KeKM_m_WheelCircumference;

/* Wheel circumference */
extern volatile real32_T KeKM_s_SampleTime;

/* sampling time */
extern volatile real32_T KeTRA_deg_TrailerBeamLenYBrkPts[3];

/* Trailer Beam Length Y Data Break Point */
extern volatile real32_T KeTRA_k_Kp;

/* Kp value(5) used to calculate P-gain of PID controller */
extern volatile real32_T KeTRA_k_SteerAngRateLmt;

/* Control Steering Angle Rate Upper Limit */
extern volatile real32_T KeTRA_m_K_beta;

/* Calibration Value Beta used for P-Gain in PID */
extern volatile real32_T KeTRA_m_TrailerBeamLenXBrkPts[3];

/* X-Breakpoints for Trailer Beam Length */
extern volatile uint8_T KeTRSC_Cnt_FailedCnt;

/* Failed Count */
extern volatile real32_T KeTRSC_Nm_MaxTrqLim;

/* KeTRSC_Nm_MaxTrqLim */
extern volatile real32_T KeTRSC_TADdes_k_PIDKd;

/* TAD Des PID Derevative Gain */
extern volatile real32_T KeTRSC_TADep_k_PIDKp;

/* TAD Dep PID Propotional Gain */
extern volatile boolean_T KeTRSC_b_BypTunParam;

/* Calibration to Bypass Tunable Params from BSW */
extern volatile boolean_T KeTRSC_b_BypassRadDsplyTyp;

/* Bypass RadDsplyTyp check for TRSC Enable Button Sts */
extern volatile boolean_T KeTRSC_b_EnblDrvDctcOvrd;
extern volatile boolean_T KeTRSC_b_EnblExtFault;

/* Enable External Faults */
extern volatile boolean_T KeTRSC_b_ForceJKCalc;

/* Force JK calculation */
extern volatile boolean_T KeTRSC_b_HardcodeTBLflag;

/* Flag to enable/disable TBL hardcoding */
extern volatile uint8_T KeTRSC_cnt_AvgSampleCnt;
extern volatile real32_T KeTRSC_cnt_DrvOvrdTurnOnDlyTime;
extern volatile real32_T KeTRSC_cnt_OvrSpdThr;

/* Over speed counter based on Maximum speed limit request  */
extern volatile real32_T KeTRSC_cnt_ResetOvrSpdThr;

/* Over speed counter based on Maximum speed limit request  */
extern volatile real32_T KeTRSC_dM_StrTrqCmdRateLmtForDrvOvrd;
extern volatile real32_T KeTRSC_ddeg_SmTrqRateLimNonActv;

/* State Machine TrqRateLim NonActv State */
extern volatile real32_T KeTRSC_ddeg_TadDesRateLim;

/* Desired Trailer Angle rate limit for TAD Error computation */
extern volatile int16_T KeTRSC_deg_KnobHys;

/* Threshold value for Knob Hysteresis */
extern volatile uint16_T KeTRSC_deg_MaxKnobAngle;

/* Maximum Knob Angle */
extern volatile real32_T KeTRSC_deg_MaxStrAngTyp1;

/* Maximum Steering Angle threshold */
extern volatile real32_T KeTRSC_deg_MaxStrAngTyp2;

/* Maximum Steering Angle threshold */
extern volatile real32_T KeTRSC_deg_MaxStrAngle;

/* Maximum Steering Angle threshold */
extern volatile real32_T KeTRSC_deg_MaxStrAngle_Low_Limit;

/* Maximum Steering Angle threshold Low Limit */
extern volatile real32_T KeTRSC_deg_MaxStrAngle_Up_Limit;

/* Maximum Steering Angle threshold Up Limit */
extern volatile real32_T KeTRSC_deg_MaxTrlrAngl;

/* Maximum Trailer Angle */
extern volatile real32_T KeTRSC_deg_TADErrSpdLmtLowThr;

/* TADErrSpdLmtLowThr */
extern volatile real32_T KeTRSC_deg_TADErrSpdLmtMidThr;

/* TADErrSpdLmtMidThr */
extern volatile real32_T KeTRSC_deg_TAD_DesRateUpLim;

/* TAD des Rate change Up Limit */
extern volatile real32_T KeTRSC_deg_TGTADdesRateChange;

/* TAD des Rate change */
extern volatile real32_T KeTRSC_deg_TadCornerCaseThr;

/* TAD angle threshold for corner case */
extern volatile real32_T KeTRSC_deg_TadErrSatLim;

/* Saturation Limit for TAD error */
extern volatile real32_T KeTRSC_deg_TrqCnt_LowLimit;

/* Torque Control Lowe Limit */
extern volatile real32_T KeTRSC_deg_TrqCnt_UpLimit;

/* Torque Control Upper Limit */
extern volatile real32_T KeTRSC_deg_TwitchTrqRateLim;

/* trq rate limit for twitch */
extern volatile real32_T KeTRSC_deg_Zero;

/* lower saturation value for Trailer Protection Angle  */
extern volatile int16_T KeTRSC_deg_ZeroInt16;

/* lower saturation value for Trailer Protection Angle  */
extern volatile int16_T KeTRSC_deg_ZeroPadUpThr;
extern volatile uint8_T KeTRSC_e_CamBlockAcceptLvl;

/* acceptance value */
extern volatile real32_T KeTRSC_k_EnblJKPrevention;

/* flag to Enable JK Prevention logic in TAD PID */
extern volatile real32_T KeTRSC_k_ErrSatLim[4];

/* steering Error saturation limit
 */
extern volatile real32_T KeTRSC_k_IntExtSat;

/* Integrator Saturation Limit */
extern volatile real32_T KeTRSC_k_JKAngle_LowLimit;

/* Jack Knife Angle Lower Limit */
extern volatile real32_T KeTRSC_k_JKAngle_UpLimit;

/* Jack Knife Angle Upper Limit */
extern volatile real32_T KeTRSC_k_LogVecLength;

/* Log Vehicle Length */
extern volatile uint16_T KeTRSC_k_MaxJumpSize;

/* Max Jump Size for Raw Knob Count */
extern volatile real32_T KeTRSC_k_NegSteerWheelThreshold;

/* Negative Steering angle threshold for TRSC activation for corner case1 */
extern volatile real32_T KeTRSC_k_NegativeTadAngleThreshold;

/* Negative TAD angle threshold for TRSC activation for corner case1 */
extern volatile real32_T KeTRSC_k_NumTwitchPulse;

/* Number of PWM pulses for twitch */
extern volatile real32_T KeTRSC_k_PIDKdPathDeviation;

/* Path Deviation PID control D gain */
extern volatile real32_T KeTRSC_k_PosSteerWheelThreshold;

/* Positive Steering angle threshold for TRSC activation for corner case1 */
extern volatile real32_T KeTRSC_k_PositiveTadAngleThreshold;

/* Positive TAD angle threshold for TRSC activation for corner case1 */
extern volatile real32_T KeTRSC_k_StrCtrlLPFFrequency;

/* Steering_controller_low_pass_filter_frequency
 */
extern volatile real32_T KeTRSC_k_StrRptLPFFrequency;

/* Steering_controller_low_pass_filter_frequency
 */
extern volatile real32_T KeTRSC_k_StrTrqPercThresholdForDrvOvrd;

/* Percentage value to enable false driver override prevention code */
extern volatile real32_T KeTRSC_k_TadPidPGainMult;

/* TAD PID P gain multiplier for non-zero Knob angle */
extern volatile real32_T KeTRSC_k_TrqConstRateLim;

/* Constant Rate Limit for Torque  */
extern volatile real32_T KeTRSC_k_TrqConstSatLim;

/* Constant Saturation Limit for Torque  */
extern volatile real32_T KeTRSC_k_TrqCtrlDMultiplier[4];

/* Torque controller D multiplier */
extern volatile real32_T KeTRSC_k_TrqCtrlIMultiplier[4];

/* Torque controller I multiplier */
extern volatile real32_T KeTRSC_k_TrqCtrlPMultiplierT1[4];

/* Torque controller P multiplier */
extern volatile real32_T KeTRSC_k_TrqCtrlPMultiplierT2or3[4];

/* Torque controller P multiplier */
extern volatile uint8_T KeTRSC_k_VariantID;

/* Variant ID  */
extern volatile real32_T KeTRSC_k_WhlAngCFBias;

/* KeTRSC_k_WhlAngCFBias */
extern volatile real32_T KeTRSC_k_WhlAngCFWt;

/* KeTRSC_k_WhlAngCFWt */
extern volatile real32_T KeTRSC_kph_DeactivationSpd;

/* DEACTIVATION_SPD */
extern volatile real32_T KeTRSC_kph_MaxSpdLimThr;

/* Vehicle speed threshold based on Maximum speed limit request */
extern volatile real32_T KeTRSC_m_DesAnglScaleTBLThr[4];

/* Desired Trlr Angle TBL Threshold */
extern volatile real32_T KeTRSC_m_DesAnglScaleTBLThrSM;

/* TBL Threshold for TAD angle limit for activation */
extern volatile real32_T KeTRSC_m_HardcodedTBL;

/* Hardcoded TBL value */
extern volatile real32_T KeTRSC_m_SprLimitTBLThr;

/* Trailer Beam Length Upper Limit */
extern volatile real32_T KeTRSC_m_SprLimitTBLThr1;

/* Trailer Beam Length Upper Limit */
extern volatile real32_T KeTRSC_m_TBL_LowLimit;

/* Trailer Beam Length Lower Limit */
extern volatile real32_T KeTRSC_m_TBL_UpLimit;

/* Trailer Beam Length Upper Limit */
extern volatile real32_T KeTRSC_m_WheelBase;

/* Wheel base of the host vehicle */
extern volatile real32_T KeTRSC_m_WheelBase_Low_Limit;

/* Wheel base of the host vehicle Low Limit */
extern volatile real32_T KeTRSC_m_WheelBase_Up_Limit;

/* Wheel base of the host vehicle Up Limit */
extern volatile real32_T KeTRSC_mph_SpdThrActivation;

/* Vehicle Speed Threshold for TRSC activation */
extern volatile real32_T KeTRSC_pct_4kphSpdThr;

/* Percentage Threshold for 4 kph Speed Limit Req */
extern volatile real32_T KeTRSC_pct_5kphSpdThr;

/* Percentage Threshold for 5 kph Speed Limit Req */
extern volatile real32_T KeTRSC_pct_6kphSpdThr;

/* Percentage Threshold for 6 kph Speed Limit Req */
extern volatile real32_T KeTRSC_pct_7kphSpdThr;

/* Percentage Threshold for 7 kph Speed Limit Req */
extern volatile real32_T KeTRSC_pct_8kphSpdThr;

/* Percentage Threshold for 8 kph Speed Limit Req */
extern volatile real32_T KeTRSC_pct_9kphSpdThr;

/* Percentage Threshold for 8 kph Speed Limit Req */
extern volatile real32_T KeTRSC_pct_JackKnifePerc;

/* JackKnife Angle Percentage */
extern volatile real32_T KeTRSC_pct_StrCornerCaseThr;

/* Percentage Max Steering wheel angle threshold for corner case */
extern volatile real32_T KeTRSC_pct_TrlrAngScaleDwnPct[4];

/* Percentage to scale down KnobAngle based on TBL */
extern volatile real32_T KeTRSC_pct_TrlrAngScaleDwnPctSM;

/* Desired Trlr Angle TBL Threshold */
extern volatile real32_T KeTRSC_pct_TrlrJackKnifePerc;

/* TRAILER_JACKNIFE_PERCENT */
extern volatile real32_T KeTRSC_s_ActTransRevDbnc2;

/* ACTUAL_TRANS_REVERSE_DEBOUNCE_2 */
extern volatile real32_T KeTRSC_s_CalibDlyTh;

/* Calibration Delay (1000 ms) */
extern volatile real32_T KeTRSC_s_DeactSpdTime;

/* DEACTIVATON_SPD_TIME */
extern volatile real32_T KeTRSC_s_EightSecTh;

/* Display timer threshold (8 Sec) used for Disply popup */
extern volatile real32_T KeTRSC_s_EpsRespTmOut;

/* EPS_RESPONSE_TIME_OUT */
extern volatile real32_T KeTRSC_s_FifteenSecTh;

/* 15 sec */
extern volatile real32_T KeTRSC_s_FiveSecTh;

/* LED timer threshold (5 Sec) used for blinking */
extern volatile real32_T KeTRSC_s_GearDbncTh;

/* Gear Debounce timer threshold = 350 msec */
extern volatile real32_T KeTRSC_s_HeldThreshold;

/* Time threshold to ensure user is actually requesting knob zero
 */
extern volatile real32_T KeTRSC_s_LEDTmrTh;

/* LED timer threshold (5 Sec) used for blinking */
extern volatile real32_T KeTRSC_s_RespNotRcvdTmOut;

/* RESPONSE_NOT_RECEIVED_TIME_OUT (300 msec) */
extern volatile real32_T KeTRSC_s_TRSCCornerCasAtc;

/* Time limit for TRSCCornerCasAtc */
extern volatile real32_T KeTRSC_s_TblKmDelay;

/* Systemic delay for KM signal i.e. speed and yaw specified in seconds */
extern volatile real32_T KeTRSC_s_TenMinTh;

/* 10 Min = 600 seconds timer threshold */
extern volatile real32_T KeTRSC_s_ThirtySecTh;

/* 30 sec */
extern volatile real32_T KeTRSC_s_TrlrUnkwnSet;

/* TRAILER_UNKNOWN_SET = 10 sec */
extern volatile real32_T KeTRSC_s_TwitchTime;

/* KeTRSC_s_TwitchTime */
extern volatile real32_T KeTRSC_s_TwoSecTh;

/* LED timer threshold (2 Sec) used for blinking */
extern volatile real32_T KeTRSC_sec_CornerCaseLatchLimit;

/* Corner case latch limit
 */
extern volatile real32_T KeTRSC_sec_CornerCaseTimeLimit;

/* Corner case identification limit
 */
#endif                                 /* RTW_HEADER_TRSC_CalibParams_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
