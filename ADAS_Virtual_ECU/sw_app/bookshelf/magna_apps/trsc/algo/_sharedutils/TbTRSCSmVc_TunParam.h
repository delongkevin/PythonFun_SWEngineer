/*
 * File: TbTRSCSmVc_TunParam.h
 *
 * Code generated for Simulink model 'TRSC_InputAdapter'.
 *
 * Model version                  : 1.125
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:50:30 2025
 */

#ifndef RTW_HEADER_TbTRSCSmVc_TunParam_h_
#define RTW_HEADER_TbTRSCSmVc_TunParam_h_
#include "rtwtypes.h"

typedef struct {
  real32_T KeKM_k_GyroYawCov;
  real32_T KeKM_k_NumWheelPulses;
  real32_T KeKM_k_TADCov;
  real32_T KeKM_k_UpdateIMU_H[3];
  real32_T KeKM_k_UpdateRPM_H[3];
  real32_T KeKM_k_UpdateTAD_H[3];
  real32_T KeKM_k_WhlPlsCnt_high_lim;
  real32_T KeKM_k_WhlPlsCnt_low_lim;
  real32_T KeKM_k_WhlRPMYawCov;
  real32_T KeKM_m_TrackWidth;
  real32_T KeKM_m_WheelCircumference;
  real32_T KeKM_s_SampleTime;
  real32_T KeKM_k_KM_YawRateGyroBiasInit;
  real32_T KeKM_k_KM_SF_RelAngCov;
  real32_T KeKM_k_KM_SF_RelAngRateCov;
  real32_T KeKM_k_KM_SF_YawRateCov;
  real32_T KeTRA_m_K_beta;
  real32_T KeKM_deg_AngTh;
  real32_T KaTRA_k_PGainLUTTblData[4];
  real32_T KaTRA_k_VehSpd_IGainLUTTblData[2];
  real32_T KaTRA_k_VehSpd_HdgDeviatLUTTblData[3];
  real32_T KaTRA_k_TADLUTTblData[3];
  real32_T KaTRA_k_TravDistLUTTblData[2];
  real32_T KaTRA_k_VehSpdLUTTblData[2];
  real32_T KeTRA_k_Kp;
  real32_T KaTRA_k_TAD_IGainLUTTblData[2];
  real32_T KeTRA_deg_TrailerBeamLenYBrkPts[3];
  real32_T KeTRA_m_TrailerBeamLenXBrkPts[3];
  real32_T KeKM_k_SWA_Res;
  real32_T KaTRA_deg_TADLUTBrkPts[3];
  real32_T KaTRA_deg_TAD_IGainLUTBrkPts[2];
  real32_T KaTRA_m_PGainLUTYBrkPts[2];
  real32_T KaTRA_m_TravDistLUTBrkPts[2];
  real32_T KaTRA_v_PGainLUTXBrkPts[2];
  real32_T KaTRA_v_VehSpdLUTBrkPts[2];
  real32_T KaTRA_v_VehSpd_HdgDeviatLUTBrkPts[3];
  real32_T KaTRA_v_VehSpd_IGainLUTBrkPts[2];
  real32_T KaTRSC_deg_FtWhlAngPts[37];
  real32_T KaTRSC_deg_StwAngPts[37];
  real32_T KeTRA_k_SteerAngRateLmt;
  real32_T KaTRA_rate_RateGuardXdat[8];
  real32_T KaTRA_rate_RateGuardYdat[8];
  real32_T KeTRSC_m_WheelBase;
  real32_T KeTRSC_deg_MaxStrAngle;
  real32_T KeTRSC_deg_MaxStrAngle_Up_Limit;
  real32_T KeTRSC_deg_MaxStrAngle_Low_Limit;
  real32_T KeTRSC_m_WheelBase_Up_Limit;
  real32_T KeTRSC_m_WheelBase_Low_Limit;
  real32_T KeTRSC_deg_KnobHys;
  real32_T KeTRSC_pct_JackKnifePerc;
  real32_T KeTRSC_deg_MaxKnobAngle;
  real32_T KeTRSC_deg_MaxTrlrAngl;
  real32_T KeTRSC_TADdes_k_PIDKd;
  real32_T KeTRSC_TADep_k_PIDKp;
  real32_T KaTRA_deg_TADLUTTblData[3];
  real32_T KeTRSC_deg_TGTADdesRateChange;
  real32_T KeTRSC_deg_TAD_DesRateUpLim;
  real32_T KeTRSC_deg_TrqCnt_UpLimit;
  real32_T KeTRSC_deg_TrqCnt_LowLimit;
  real32_T KeTRSC_k_JKAngle_UpLimit;
  real32_T KeTRSC_k_JKAngle_LowLimit;
  real32_T KeTRSC_k_LogVecLength;
  real32_T KeKM_m_BeamLength;
  real32_T KeTRSC_m_TBL_UpLimit;
  real32_T KeTRSC_m_TBL_LowLimit;
  real32_T KeTRSC_kph_DeactivationSpd;
  real32_T KeTRSC_pct_TrlrJackKnifePerc;
  real32_T KeTRSC_s_ActTransRevDbnc2;
  real32_T KeTRSC_s_CalibDlyTh;
  real32_T KeTRSC_s_EpsRespTmOut;
  real32_T KeTRSC_s_GearDbncTh;
  real32_T KeTRSC_s_LEDTmrTh;
  real32_T KeTRSC_s_RespNotRcvdTmOut;
  real32_T KeTRSC_s_TrlrUnkwnSet;

  /* Wheel Angle C Factor Weight */
  real32_T KeTRSC_k_WhlAngCFWt;

  /* Wheel Angle C Factor Bias */
  real32_T KeTRSC_k_WhlAngCFBias;
  real32_T KaTRSC_kph_InputRateLimBrkPts[4];
  real32_T KaTRSC_k_InputRateLimTblData[4];
  real32_T KaTRSC_kph_IntegratorGainBrkPts[4];
  real32_T KaTRSC_k_IntegratorGainTblData[4];
  real32_T KaTRSC_kph_IntegratorExtSatBrkPts[4];
  real32_T KaTRSC_k_IntegratorExtSatTblData[4];
  real32_T KaTRSC_kph_PGainLUTXBrkPts[4];
  real32_T KaTRSC_deg_PGainLUTYBrkPts[5];
  real32_T KaTRSC_k_PGainLUTTblData[20];
  real32_T KaTRSC_kph_DiffGainBrkPts[4];
  real32_T KaTRSC_k_DiffGainTblData[4];
  real32_T KaTRSC_kph_DampingGainBrkPts[4];
  real32_T KaTRSC_k_DampingGainTblData[4];
  real32_T KeTRSC_k_TrqConstRateLim;
  real32_T KeTRSC_k_TrqConstSatLim;
  uint8_T KeTRSC_k_VariantID;
  uint8_T KeTRSC_Cnt_FailedCnt;
  uint8_T KeTRSC_e_CamBlockAcceptLvl;
  boolean_T KeTRSC_b_bValidFlag;
} TbTRSCSmVc_TunParam_t;

#endif                                 /* RTW_HEADER_TbTRSCSmVc_TunParam_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
