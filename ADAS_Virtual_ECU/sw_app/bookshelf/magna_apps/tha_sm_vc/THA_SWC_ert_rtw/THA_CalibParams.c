/*
 * File: THA_CalibParams.c
 *
 * Code generated for Simulink model 'THA_SWC'.
 *
 * Model version                  : 1.1595
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Aug  7 17:43:08 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "THA_SWC_types.h"

/* Exported data definition */

/* Volatile memory section */
/* Definition for custom storage class: Volatile */
volatile real32_T KeTHA_Hz_StrCtrlLowPassFiltFreq = 3.0F;

/* Steering control low pass filter frequency. */
volatile real32_T KeTHA_M_AbortStrTrq = 0.0F;

/* Steering torque for maneuver abort. */
volatile real32_T KeTHA_M_SteerTweakTrq = 1.0F;

/* Steering tweak torque amplitude. */
volatile real32_T KeTHA_M_StrTrqValLimit = 5.0F;

/* Steering torque value limit. */
volatile real32_T KeTHA_a_AcclOfstBsmSNA = 2.54F;
volatile real32_T KeTHA_a_VehAccSNA = 40.94F;
volatile boolean_T KeTHA_b_EnblEngageRejectReq = 1;

/* Calibration to enable trailer posrion based engaged rejection strategy. */
volatile boolean_T KeTHA_b_EnblTrlrAngStrTrqCalc = 0;

/* Calibration to enable Steering torque calculation based on trailer angle. */
volatile boolean_T KeTHA_b_SpdCndEnable = 1;

/* Calibration to enable updated torque control logic. */
volatile boolean_T KeTHA_b_UseNewTrqCtrl = 1;

/* Calibration to enable updated torque control logic. */
volatile boolean_T KeTHA_b_UsePreProcessor = 1;

/* Calibration to enable updated torque control logic. */
volatile uint8_T KeTHA_cnt_FastPlsCntrSNA = 255U;
volatile real32_T KeTHA_dM_EpsRampOutSlewRate = 2.0F;

/* Slew rate at which EPS torque shall be set. */
volatile real32_T KeTHA_dM_TrqCtrlSlewRate = 50.0F;

/* Slew rate at which EPS torque shall be set. */
volatile uint16_T KeTHA_ddeg_StrRateLimFinal = 500U;

/* Steering rate limit during maneuver. */
volatile uint16_T KeTHA_ddeg_StrRateLimInit = 500U;

/* Initial steering rate limit to avoid sudden jerk. */
volatile real32_T KeTHA_ddeg_YawRateBsmSNA = 163.76F;
volatile real32_T KeTHA_deg_LowerSteeringAngLim = -500.0F;

/* Lower steering angle limit of the vehicle. */
volatile real32_T KeTHA_deg_StrWhlAngSNA = 5833.5F;

/* LWS Angle SNA Value */
volatile real32_T KeTHA_deg_UpperSteeringAngLim = 500.0F;

/* Upper steering angle limit of the vehicle. */
volatile real32_T KeTHA_deg_VehTrlrInitAngMax = 60.0F;

/* Maximum initial host vehicle angle from trailer ball to trailer coupler to initiate THA maneuver. */
volatile int32_T KeTHA_dpx_CplrPntRateLimitMax = 90;

/* Max allowable change in coupler point per second. */
volatile real32_T KeTHA_k_HeadingErrGain = -40.0F;

/* Heading error gain. */
volatile real32_T KeTHA_k_NumTweakPulse = 2.0F;

/* Number of PWM pulse, keep it single type */
volatile real32_T KeTHA_k_SteerTrqCtrlFiltCoef = 5.0F;

/* Steering filter coefficient. */
volatile real32_T KeTHA_k_SteerTrqCtrlKd = 1.0F;

/* Steering controller - Derivative gain */
volatile real32_T KeTHA_k_SteerTrqCtrlKi = 0.0F;

/* Steering controller - Integral gain */
volatile real32_T KeTHA_k_SteerTrqCtrlKp = 0.1F;

/* Steer torque control Kp. */
volatile real32_T KeTHA_k_TrqCtrlDMultiplier_CF55 = 0.001F;

/* Torque controller Differential multiplier KeTHA_k_TrqCtrlDMultiplier */
volatile real32_T KeTHA_k_TrqCtrlDMultiplier_CF60_CF63 = 0.001F;

/* Torque controller Differential multiplier KeTHA_k_TrqCtrlDMultiplier */
volatile real32_T KeTHA_k_TrqCtrlDMultiplier_WB144_CF63 = 0.001F;

/* Torque controller Differential multiplier KeTHA_k_TrqCtrlDMultiplier */
volatile real32_T KeTHA_k_TrqCtrlFiltCoef = 10.0F;

/* Steering wheel angle to steering torque controller - Filter Coefficient. */
volatile real32_T KeTHA_k_TrqCtrlIMultiplier_CF55 = 4.0F;

/* Torque controller Integral multiplier KeTHA_k_TrqCtrlIMultiplier  for CF 55 */
volatile real32_T KeTHA_k_TrqCtrlIMultiplier_CF60_CF63 = 0.5F;

/* Torque controller Integral multiplier KeTHA_k_TrqCtrlIMultiplier */
volatile real32_T KeTHA_k_TrqCtrlIMultiplier_WB144_CF63 = 1.0F;

/* Torque controller Integral multiplier KeTHA_k_TrqCtrlIMultiplier */
volatile real32_T KeTHA_k_TrqCtrlKd = 0.2F;

/* Steering wheel angle to steering torque controller - Derivative gain. */
volatile real32_T KeTHA_k_TrqCtrlKi = 0.07F;

/* Steering wheel angle to steering torque controller - Integral gain. */
volatile real32_T KeTHA_k_TrqCtrlKp = 0.03F;

/* Steering wheel angle to steering torque controller - proportional gain. */
volatile real32_T KeTHA_k_TrqCtrlPMultiplier_CF55 = 0.018F;

/* Torque controller Propotional multiplier KeTHA_k_TrqCtrlPMultiplier for CF 55 */
volatile real32_T KeTHA_k_TrqCtrlPMultiplier_CF60 = 0.017F;

/* Torque controller Propotional multiplier KeTHA_k_TrqCtrlPMultiplier */
volatile real32_T KeTHA_k_TrqCtrlPMultiplier_CF63 = 0.014F;

/* Torque controller Propotional multiplier KeTHA_k_TrqCtrlPMultiplier */
volatile real32_T KeTHA_k_TrqCtrlPMultiplier_WB144_CF63 = 0.012F;

/* Torque controller Propotional multiplier KeTHA_k_TrqCtrlPMultiplier */
volatile real32_T KeTHA_kph_ActvSpdThd = 2.0F;

/* If vehicle speed goes above THA speed limit by this threshold value, then THA shall be aborted. */
volatile real32_T KeTHA_kph_VehSpdVSOSigSNA = 511.9375F;

/* SNA Value for average vehicle speed calculated  */
volatile real32_T KeTHA_kph_WhlSpdSNA = 511.9375F;
volatile real32_T KeTHA_m_WhlCircumference = 2.56032F;

/* Wheel circumference. */
volatile real32_T KeTHA_mps_SpdThreshold = 0.1F;

/* THA speed limit threshold stability  */
volatile real32_T KeTHA_pct_StrDampDefault = 0.0F;

/* Default value of THA steering damping. */
volatile int32_T KeTHA_px_EngageRejLatpxdiff = 50;

/* Lat pixel diff in case coupler detected above 3m , To engage Regection logic */
volatile int32_T KeTHA_px_HitchCplrDeltaThd1 = 125;

/* Coupler distance threshold for transiting to Engaged Delta state in pixels. (Equivalent to 4 Feet) */
volatile int32_T KeTHA_px_HitchCplrDeltaThd2 = 11;

/* Coupler distance threshold for transiting to Engaged Inquiry state in pixels. (Equivalent to 2 Feet) */
volatile int32_T KeTHA_px_RearBrkSuppDist = 1080;

/* Distance from target trailer coupler that autonomous braking will be suppressed.  */
volatile real32_T KeTHA_s_BsmHandshake = 0.75F;

/* BSM handshake duration. */
volatile real32_T KeTHA_s_ChimeActvTime = 0.15F;

/* THA completion chime activation duration. */
volatile real32_T KeTHA_s_CplrAngFoundTimeout = 0.45F;

/* Wait time for CplrAngFound signal value to be updated from THA detection side. */
volatile real32_T KeTHA_s_CplrDetStsBufEnabled = 0.45F;

/* Coupler status detection buffer duration for Enabled state. */
volatile real32_T KeTHA_s_CplrDetStsBufEngaged = 0.45F;

/* Coupler status detection buffer duration for Engaged state. */
volatile real32_T KeTHA_s_DistConfDur = 0.45F;

/* Coupler to hitch distance stability duration. */
volatile real32_T KeTHA_s_EcmHandshake = 0.75F;

/* ECM handshake duration.
 */
volatile real32_T KeTHA_s_EpsHandshake = 0.75F;

/* EPS handshake duration. */
volatile real32_T KeTHA_s_GearEnggConfDur = 0.5F;

/* Duration to detrmine vehicle gear confidence during Engaged Suppression state. */
volatile real32_T KeTHA_s_HitchCplrDetctTimeout = 3.0F;

/* Max wait duration for hitch and coupler detection status from THA detection after giving request. */
volatile real32_T KeTHA_s_HitchDetStsBufEnabled = 0.45F;

/* Hitch status detection buffer duration for Enabled state. */
volatile real32_T KeTHA_s_HitchDetStsBufEngaged = 0.0F;

/* Hitch status detection buffer duration for Engaged state. */
volatile real32_T KeTHA_s_HmiFaultPopUpDur = 2.0F;

/* THA fault HMI popup message duration. */
volatile real32_T KeTHA_s_MnvTimeout = 600.0F;

/* THA Maneuver Timeout. */
volatile real32_T KeTHA_s_SpdLimConfDur = 0.45F;

/* THA speed limit stability duration. */
volatile real32_T KeTHA_s_SpdOvrdTimeout = 1.0F;

/* Wait time to abort THA if vehicle speed is greater than THA speed limit. */
volatile real32_T KeTHA_s_Standstill = 2.0F;

/* Vehicle standstill time. */
volatile real32_T KeTHA_s_SteerTweakTime = 0.24F;

/* Steering tweak profile duration.
 */
volatile real32_T KeTHA_s_ThaSampleTime = 0.03F;

/* Sample time of THA feature for counter/timer operations within logic. */
volatile real32_T KeTHA_s_TrajLostDur = 0.75F;

/* Duration to detrmine if hitch to coupler distance is increased continuously in reverse. */
volatile real32_T KsTHA_deg_StrToRdWhlAngTD[17] = { -39.42F, -33.7F, -28.49F,
  -23.54F, -18.49F, -13.94F, -9.07F, -4.58F, 0.0F, 4.65F, 9.1F, 13.97F, 18.57F,
  23.54F, 28.57F, 33.7F, 39.45F } ;

/* Array of road wheel angles corresponding to steering wheel values of [-600 -525 -450 -375 -300 -225 -150 -75 0 75 150 225 300 375 450 525 600]. */
volatile real32_T KsTHA_k_ErrxHeadingErrTD[4] = { 0.0F, 0.0F, 0.5F, 1.0F } ;

/* Heading error for the longitudinal pixel difference between hitch and coupler/trailer of [0,50,150,200]. */
volatile real32_T KsTHA_k_ErrxPropGainTD[5] = { 200.0F, 200.0F, 200.0F, 200.0F,
  200.0F } ;

/* Proportional gain array for the longitudinal pixel difference between hitch and coupler/trailer of [0,50,100,150,200]. */
volatile real32_T KsTHA_k_TrqCtrlDampGainTD[4] = { 0.0F, 0.0F, 0.0F, 0.0F } ;

/* Damping gain table data corresponding to vehicle speed [0,2,5,10]. */
volatile real32_T KsTHA_k_TrqCtrlDiffGainTD_C55[4] = { 0.002F, 0.002F, 0.0015F,
  0.0012F } ;

/* Differential gain table data corresponding to vehicle speed [0,2,5,10] for default variant 5. */
volatile real32_T KsTHA_k_TrqCtrlDiffGainTD_C60_C63[4] = { 0.0025F, 0.003F,
  0.0025F, 0.002F } ;

/* Differential gain table data corresponding to vehicle speed [0,2,5,10] for default variant 5. */
volatile real32_T KsTHA_k_TrqCtrlDiffGainTD_WB144_C63[4] = { 0.0015F, 0.0018F,
  0.0015F, 0.0012F } ;

/* Differential gain table data corresponding to vehicle speed [0,2,5,10] for default variant 5. */
volatile real32_T KsTHA_k_TrqCtrlIntExtSatTD[4] = { 2.0F, 2.0F, 2.0F, 2.0F } ;

/* Integrator external saturation table data corresponding to vehicle speed [0,2,5,10]. */
volatile real32_T KsTHA_k_TrqCtrlIntGainTD_C55[4] = { 0.01F, 0.01F, 0.01F, 0.01F
} ;

/* Integrator gain table data corresponding to vehicle speed [0,2,5,10] for default variant 5.. */
volatile real32_T KsTHA_k_TrqCtrlIntGainTD_C60_C63[4] = { 0.01F, 0.01F, 0.01F,
  0.01F } ;

/* Integrator gain table data corresponding to vehicle speed [0,2,5,10] for default variant 5.. */
volatile real32_T KsTHA_k_TrqCtrlIntGainTD_WB144_C63[4] = { 0.01F, 0.01F, 0.01F,
  0.01F } ;

/* Integrator gain table data corresponding to vehicle speed [0,2,5,10] for default variant 5.. */
volatile real32_T KsTHA_k_TrqCtrlPropGainTD_C55[20] = { 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F } ;

/* Kp gain LUT corresponding to vehicle speed [0,2,5,10] and steering angle [0,25,50,100,570] for default variant 5. */
volatile real32_T KsTHA_k_TrqCtrlPropGainTD_C60[20] = { 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F } ;

/* Kp gain LUT corresponding to vehicle speed [0,2,5,10] and steering angle [0,25,50,100,570] for default variant 5. */
volatile real32_T KsTHA_k_TrqCtrlPropGainTD_C63[20] = { 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F } ;

/* Kp gain LUT corresponding to vehicle speed [0,2,5,10] and steering angle [0,25,50,100,570] for default variant 5. */
volatile real32_T KsTHA_k_TrqCtrlPropGainTD_WB144_C63[20] = { 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F } ;

/* Kp gain LUT corresponding to vehicle speed [0,2,5,10] and steering angle [0,25,50,100,570] for default variant 5. */
volatile real32_T KsTHA_mps_DistSpdTD[6] = { 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F
} ;

/* THA speed limit array for the longitudinal pixel difference between hitch and coupler/trailer of [60, 112, 137, 147, 155, 164]. */
volatile int32_T KsTHA_px_EngageRejLatOffset[4] = { 80, 60, 60, 40 } ;

/* Max allowable lateral offset array for following longitudinal pixel difference range: 0-1m, 1-2m, 2-4m, 4-6m. */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
