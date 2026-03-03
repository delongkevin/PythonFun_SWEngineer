/*
 * File: THA_CalibParams.h
 *
 * Code generated for Simulink model 'THA_SWC'.
 *
 * Model version                  : 1.1595
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Aug  7 17:43:08 2025
 */

#ifndef RTW_HEADER_THA_CalibParams_h_
#define RTW_HEADER_THA_CalibParams_h_
#include "rtwtypes.h"

/* Volatile memory section */
/* Exported data declaration */
/* Declaration for custom storage class: Volatile */
extern volatile real32_T KeTHA_Hz_StrCtrlLowPassFiltFreq;

/* Steering control low pass filter frequency. */
extern volatile real32_T KeTHA_M_AbortStrTrq;

/* Steering torque for maneuver abort. */
extern volatile real32_T KeTHA_M_SteerTweakTrq;

/* Steering tweak torque amplitude. */
extern volatile real32_T KeTHA_M_StrTrqValLimit;

/* Steering torque value limit. */
extern volatile real32_T KeTHA_a_AcclOfstBsmSNA;
extern volatile real32_T KeTHA_a_VehAccSNA;
extern volatile boolean_T KeTHA_b_EnblEngageRejectReq;

/* Calibration to enable trailer posrion based engaged rejection strategy. */
extern volatile boolean_T KeTHA_b_EnblTrlrAngStrTrqCalc;

/* Calibration to enable Steering torque calculation based on trailer angle. */
extern volatile boolean_T KeTHA_b_SpdCndEnable;

/* Calibration to enable updated torque control logic. */
extern volatile boolean_T KeTHA_b_UseNewTrqCtrl;

/* Calibration to enable updated torque control logic. */
extern volatile boolean_T KeTHA_b_UsePreProcessor;

/* Calibration to enable updated torque control logic. */
extern volatile uint8_T KeTHA_cnt_FastPlsCntrSNA;
extern volatile real32_T KeTHA_dM_EpsRampOutSlewRate;

/* Slew rate at which EPS torque shall be set. */
extern volatile real32_T KeTHA_dM_TrqCtrlSlewRate;

/* Slew rate at which EPS torque shall be set. */
extern volatile uint16_T KeTHA_ddeg_StrRateLimFinal;

/* Steering rate limit during maneuver. */
extern volatile uint16_T KeTHA_ddeg_StrRateLimInit;

/* Initial steering rate limit to avoid sudden jerk. */
extern volatile real32_T KeTHA_ddeg_YawRateBsmSNA;
extern volatile real32_T KeTHA_deg_LowerSteeringAngLim;

/* Lower steering angle limit of the vehicle. */
extern volatile real32_T KeTHA_deg_StrWhlAngSNA;

/* LWS Angle SNA Value */
extern volatile real32_T KeTHA_deg_UpperSteeringAngLim;

/* Upper steering angle limit of the vehicle. */
extern volatile real32_T KeTHA_deg_VehTrlrInitAngMax;

/* Maximum initial host vehicle angle from trailer ball to trailer coupler to initiate THA maneuver. */
extern volatile int32_T KeTHA_dpx_CplrPntRateLimitMax;

/* Max allowable change in coupler point per second. */
extern volatile real32_T KeTHA_k_HeadingErrGain;

/* Heading error gain. */
extern volatile real32_T KeTHA_k_NumTweakPulse;

/* Number of PWM pulse, keep it single type */
extern volatile real32_T KeTHA_k_SteerTrqCtrlFiltCoef;

/* Steering filter coefficient. */
extern volatile real32_T KeTHA_k_SteerTrqCtrlKd;

/* Steering controller - Derivative gain */
extern volatile real32_T KeTHA_k_SteerTrqCtrlKi;

/* Steering controller - Integral gain */
extern volatile real32_T KeTHA_k_SteerTrqCtrlKp;

/* Steer torque control Kp. */
extern volatile real32_T KeTHA_k_TrqCtrlDMultiplier_CF55;

/* Torque controller Differential multiplier KeTHA_k_TrqCtrlDMultiplier */
extern volatile real32_T KeTHA_k_TrqCtrlDMultiplier_CF60_CF63;

/* Torque controller Differential multiplier KeTHA_k_TrqCtrlDMultiplier */
extern volatile real32_T KeTHA_k_TrqCtrlDMultiplier_WB144_CF63;

/* Torque controller Differential multiplier KeTHA_k_TrqCtrlDMultiplier */
extern volatile real32_T KeTHA_k_TrqCtrlFiltCoef;

/* Steering wheel angle to steering torque controller - Filter Coefficient. */
extern volatile real32_T KeTHA_k_TrqCtrlIMultiplier_CF55;

/* Torque controller Integral multiplier KeTHA_k_TrqCtrlIMultiplier  for CF 55 */
extern volatile real32_T KeTHA_k_TrqCtrlIMultiplier_CF60_CF63;

/* Torque controller Integral multiplier KeTHA_k_TrqCtrlIMultiplier */
extern volatile real32_T KeTHA_k_TrqCtrlIMultiplier_WB144_CF63;

/* Torque controller Integral multiplier KeTHA_k_TrqCtrlIMultiplier */
extern volatile real32_T KeTHA_k_TrqCtrlKd;

/* Steering wheel angle to steering torque controller - Derivative gain. */
extern volatile real32_T KeTHA_k_TrqCtrlKi;

/* Steering wheel angle to steering torque controller - Integral gain. */
extern volatile real32_T KeTHA_k_TrqCtrlKp;

/* Steering wheel angle to steering torque controller - proportional gain. */
extern volatile real32_T KeTHA_k_TrqCtrlPMultiplier_CF55;

/* Torque controller Propotional multiplier KeTHA_k_TrqCtrlPMultiplier for CF 55 */
extern volatile real32_T KeTHA_k_TrqCtrlPMultiplier_CF60;

/* Torque controller Propotional multiplier KeTHA_k_TrqCtrlPMultiplier */
extern volatile real32_T KeTHA_k_TrqCtrlPMultiplier_CF63;

/* Torque controller Propotional multiplier KeTHA_k_TrqCtrlPMultiplier */
extern volatile real32_T KeTHA_k_TrqCtrlPMultiplier_WB144_CF63;

/* Torque controller Propotional multiplier KeTHA_k_TrqCtrlPMultiplier */
extern volatile real32_T KeTHA_kph_ActvSpdThd;

/* If vehicle speed goes above THA speed limit by this threshold value, then THA shall be aborted. */
extern volatile real32_T KeTHA_kph_VehSpdVSOSigSNA;

/* SNA Value for average vehicle speed calculated  */
extern volatile real32_T KeTHA_kph_WhlSpdSNA;
extern volatile real32_T KeTHA_m_WhlCircumference;

/* Wheel circumference. */
extern volatile real32_T KeTHA_mps_SpdThreshold;

/* THA speed limit threshold stability  */
extern volatile real32_T KeTHA_pct_StrDampDefault;

/* Default value of THA steering damping. */
extern volatile int32_T KeTHA_px_EngageRejLatpxdiff;

/* Lat pixel diff in case coupler detected above 3m , To engage Regection logic */
extern volatile int32_T KeTHA_px_HitchCplrDeltaThd1;

/* Coupler distance threshold for transiting to Engaged Delta state in pixels. (Equivalent to 4 Feet) */
extern volatile int32_T KeTHA_px_HitchCplrDeltaThd2;

/* Coupler distance threshold for transiting to Engaged Inquiry state in pixels. (Equivalent to 2 Feet) */
extern volatile int32_T KeTHA_px_RearBrkSuppDist;

/* Distance from target trailer coupler that autonomous braking will be suppressed.  */
extern volatile real32_T KeTHA_s_BsmHandshake;

/* BSM handshake duration. */
extern volatile real32_T KeTHA_s_ChimeActvTime;

/* THA completion chime activation duration. */
extern volatile real32_T KeTHA_s_CplrAngFoundTimeout;

/* Wait time for CplrAngFound signal value to be updated from THA detection side. */
extern volatile real32_T KeTHA_s_CplrDetStsBufEnabled;

/* Coupler status detection buffer duration for Enabled state. */
extern volatile real32_T KeTHA_s_CplrDetStsBufEngaged;

/* Coupler status detection buffer duration for Engaged state. */
extern volatile real32_T KeTHA_s_DistConfDur;

/* Coupler to hitch distance stability duration. */
extern volatile real32_T KeTHA_s_EcmHandshake;

/* ECM handshake duration.
 */
extern volatile real32_T KeTHA_s_EpsHandshake;

/* EPS handshake duration. */
extern volatile real32_T KeTHA_s_GearEnggConfDur;

/* Duration to detrmine vehicle gear confidence during Engaged Suppression state. */
extern volatile real32_T KeTHA_s_HitchCplrDetctTimeout;

/* Max wait duration for hitch and coupler detection status from THA detection after giving request. */
extern volatile real32_T KeTHA_s_HitchDetStsBufEnabled;

/* Hitch status detection buffer duration for Enabled state. */
extern volatile real32_T KeTHA_s_HitchDetStsBufEngaged;

/* Hitch status detection buffer duration for Engaged state. */
extern volatile real32_T KeTHA_s_HmiFaultPopUpDur;

/* THA fault HMI popup message duration. */
extern volatile real32_T KeTHA_s_MnvTimeout;

/* THA Maneuver Timeout. */
extern volatile real32_T KeTHA_s_SpdLimConfDur;

/* THA speed limit stability duration. */
extern volatile real32_T KeTHA_s_SpdOvrdTimeout;

/* Wait time to abort THA if vehicle speed is greater than THA speed limit. */
extern volatile real32_T KeTHA_s_Standstill;

/* Vehicle standstill time. */
extern volatile real32_T KeTHA_s_SteerTweakTime;

/* Steering tweak profile duration.
 */
extern volatile real32_T KeTHA_s_ThaSampleTime;

/* Sample time of THA feature for counter/timer operations within logic. */
extern volatile real32_T KeTHA_s_TrajLostDur;

/* Duration to detrmine if hitch to coupler distance is increased continuously in reverse. */
extern volatile real32_T KsTHA_deg_StrToRdWhlAngTD[17];

/* Array of road wheel angles corresponding to steering wheel values of [-600 -525 -450 -375 -300 -225 -150 -75 0 75 150 225 300 375 450 525 600]. */
extern volatile real32_T KsTHA_k_ErrxHeadingErrTD[4];

/* Heading error for the longitudinal pixel difference between hitch and coupler/trailer of [0,50,150,200]. */
extern volatile real32_T KsTHA_k_ErrxPropGainTD[5];

/* Proportional gain array for the longitudinal pixel difference between hitch and coupler/trailer of [0,50,100,150,200]. */
extern volatile real32_T KsTHA_k_TrqCtrlDampGainTD[4];

/* Damping gain table data corresponding to vehicle speed [0,2,5,10]. */
extern volatile real32_T KsTHA_k_TrqCtrlDiffGainTD_C55[4];

/* Differential gain table data corresponding to vehicle speed [0,2,5,10] for default variant 5. */
extern volatile real32_T KsTHA_k_TrqCtrlDiffGainTD_C60_C63[4];

/* Differential gain table data corresponding to vehicle speed [0,2,5,10] for default variant 5. */
extern volatile real32_T KsTHA_k_TrqCtrlDiffGainTD_WB144_C63[4];

/* Differential gain table data corresponding to vehicle speed [0,2,5,10] for default variant 5. */
extern volatile real32_T KsTHA_k_TrqCtrlIntExtSatTD[4];

/* Integrator external saturation table data corresponding to vehicle speed [0,2,5,10]. */
extern volatile real32_T KsTHA_k_TrqCtrlIntGainTD_C55[4];

/* Integrator gain table data corresponding to vehicle speed [0,2,5,10] for default variant 5.. */
extern volatile real32_T KsTHA_k_TrqCtrlIntGainTD_C60_C63[4];

/* Integrator gain table data corresponding to vehicle speed [0,2,5,10] for default variant 5.. */
extern volatile real32_T KsTHA_k_TrqCtrlIntGainTD_WB144_C63[4];

/* Integrator gain table data corresponding to vehicle speed [0,2,5,10] for default variant 5.. */
extern volatile real32_T KsTHA_k_TrqCtrlPropGainTD_C55[20];

/* Kp gain LUT corresponding to vehicle speed [0,2,5,10] and steering angle [0,25,50,100,570] for default variant 5. */
extern volatile real32_T KsTHA_k_TrqCtrlPropGainTD_C60[20];

/* Kp gain LUT corresponding to vehicle speed [0,2,5,10] and steering angle [0,25,50,100,570] for default variant 5. */
extern volatile real32_T KsTHA_k_TrqCtrlPropGainTD_C63[20];

/* Kp gain LUT corresponding to vehicle speed [0,2,5,10] and steering angle [0,25,50,100,570] for default variant 5. */
extern volatile real32_T KsTHA_k_TrqCtrlPropGainTD_WB144_C63[20];

/* Kp gain LUT corresponding to vehicle speed [0,2,5,10] and steering angle [0,25,50,100,570] for default variant 5. */
extern volatile real32_T KsTHA_mps_DistSpdTD[6];

/* THA speed limit array for the longitudinal pixel difference between hitch and coupler/trailer of [60, 112, 137, 147, 155, 164]. */
extern volatile int32_T KsTHA_px_EngageRejLatOffset[4];

/* Max allowable lateral offset array for following longitudinal pixel difference range: 0-1m, 1-2m, 2-4m, 4-6m. */
#endif                                 /* RTW_HEADER_THA_CalibParams_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
