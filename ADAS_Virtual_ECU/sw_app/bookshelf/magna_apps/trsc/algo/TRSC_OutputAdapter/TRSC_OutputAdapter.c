/*
 * File: TRSC_OutputAdapter.c
 *
 * Code generated for Simulink model 'TRSC_OutputAdapter'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:50:50 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "TRSC_OutputAdapter.h"
#include "TRSC_OutputAdapter_private.h"

/* Exported block signals */
real32_T MeTRSC_M_SteeringTorqInfo;    /* '<Root>/Data Type Conversion'
                                        * MeTRSC_M_SteeringTorqInfo
                                        */
MdlrefDW_TRSC_OutputAdapter_T TRSC_OutputAdapter_MdlrefDW;

/* Block signals (default storage) */
B_TRSC_OutputAdapter_c_T TRSC_OutputAdapter_B;

/* Output and update for referenced model: 'TRSC_OutputAdapter' */
void TRSC_OutputAdapter(const TeTRSC_e_SpdLmtReq *rtu_IeTRSC_e_SpdLmtReq_In,
  const TeTRSC_e_VehStpReq *rtu_IeTRSC_e_VehStpReq_In, const TeTRSC_e_TRSCLedSts
  *rtu_IeTRSC_e_TRSCLedSts_In, const TeTRSC_e_TRSCPopupDispInfo
  *rtu_IeTRSC_e_TRSCPopupDispInfo_In, const TeTRSC_e_TRSCSts
  *rtu_IeTRSC_e_TRSCSts_In, const real32_T *rtu_IeTRSC_M_TRSCStrTrq_In, const
  TeTRSC_e_TRSCStrTrqActvReq *rtu_IeTRSC_e_TRSCStrTrqActvReq_In, const real32_T *
  rtu_IeTRSC_pct_TRSCStrDmp_In, const boolean_T *rtu_IeTRSC_b_MoreCamReqSts_In,
  const TeTRSC_e_TRSCStat *rtu_MeTRSC_e_TRSCStat_In, const boolean_T
  *rtu_MeTRSC_b_MoreCamSoftButtEnbl_In, const real32_T
  *rtu_MeTRSC_deg_JackKnifeAngle_In, const real32_T
  *rtu_MeTRSC_m_TrailerBeamLen_In, const real32_T
  *rtu_MeTRSC_deg_JackknifeThrAngle_In, const real32_T
  *rtu_MeTRSC_deg_MaxAllowedTADAngle_In, const real32_T
  *rtu_MeTRSC_deg_KnobAngle_In, const boolean_T
  *rtu_MeTRSC_b_TRSCSwitchPressed_In1, const boolean_T
  *rtu_MeTRSC_b_TrlrRevSteeringStsInfo_In, const TeVBII_e_EnblBtnSts
  *rtu_IeTRSC_e_TRSKMBtnSts, const uint16_T *rtu_IeTRSC_cnt_KnobPos, const
  TeVBII_e_CenterBtnSts *rtu_IeTRSC_e_TRSKMCenBtnSts, const TeTRSC_e_TRSKMSts
  *rtu_IeTRSC_e_TRSKMSts, const TeVBII_e_GearEngagedForDsply
  *rtu_IeTRSC_e_GearShiftSts, const real32_T *rtu_IeTRSC_kph_VehSpeedVSOSig,
  const uint32_T *rtu_IeTRSC_e_TRSCUnavailReas, const uint32_T
  *rtu_IeTRSC_e_TRSCAbortReas, const real32_T *rtu_IeTRSC_m_TrlrWhlBaseEff,
  const real32_T *rtu_IeTRSC_deg_FrntWhlAng, const real32_T
  *rtu_IeTRSC_deg_TrlrAngKnob, const real32_T *rtu_IeTRSC_deg_JackknifeThrAngle,
  const TeTRSC_e_TrlrHitchLightCtrl *rtu_IeTRSC_e_TrlrHitchLightCtrl_In, const
  TeTRSC_e_TrlrPrsntInfo *rtu_MeTRSC_e_TrlrPrsntInfoCAN_In, const real32_T
  *rtu_IeTRSC_deg_TADAngAct_In, const TeTRSC_e_TADAngActSign
  *rtu_IeTRSC_e_TADAngActSign_In, const TeTRSC_e_TrlrCalInfo
  *rtu_IeTRSC_e_TrlrCalInfo_In, const boolean_T *rtu_MeTRSC_b_OTBLReset_In,
  const boolean_T *rtu_MeTRSC_b_TBLComputationDone_In, const real32_T
  *rtu_MeTRSC_deg_StrCMD, const boolean_T *rtu_MeTRSC_b_TrlrCalibPopInfo, const
  real32_T *rtu_IeTRSC_kph_SpdLmtReq_DID, const TeTRSC_e_DispView2_DID
  *rtu_MeSVS_e_DispView2Info_DID_In, const TeTRSC_e_TRSKMBtnSts_DID
  *rtu_IeTRSC_e_TRSKMBtnSts_DID, const TeTRSC_e_TRSKMCenBtnSts_DID
  *rtu_IeTRSC_e_TRSKMCenBtnSts_DID, const TeTRSC_e_TRSKMSts_DID
  *rtu_IeTRSC_e_TRSKMSts_DID, const TeTRSC_e_GearShiftSts_DID
  *rtu_IeTRSC_e_GearShiftSts_DID, const TeTRSC_e_VehStpReq_DID
  *rtu_IeTRSC_e_VehStpReq_DID, const TeTRSC_e_GraphicOverlay_Sts
  *rtu_IeTRSC_e_GraphicOverlay_Sts_In, const TeTRSC_e_TRSCAbortReason_DID
  *rtu_IeTRSC_e_TRSCAbortReas_DID, const TeTRSC_e_TRSCUnavailReas_DID
  *rtu_IeTRSC_e_TRSCUnavailReas_DID, const real32_T
  *rtu_MeTRSC_deg_TADAngleSMVC_In, ME_VehOut_TRSC_t *rty_IbTRSC_ME_VehOut_TRSC,
  TRSCSMVCtoSVS_t *rty_IbTRSC_TRSCtoSVS, Detection_Inputs_from_TRSC_t
  *rty_IbTRSC_DetInp_from_TRSC, TRSCtoDiagMgr_t *rty_IbTRSC_TRSCtoDiagMgr,
  TRSCSMVCtoDebugCAN_t *rty_IbTRSC_TRSCSMVCtoDebugCAN_t)
{
  real32_T tmp;

  /* Abs: '<Root>/Abs' */
  TRSC_OutputAdapter_B.IeTRSC_M_TRSCStrTrq = fabsf(*rtu_IeTRSC_deg_TADAngAct_In);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  tmp = floorf(TRSC_OutputAdapter_B.IeTRSC_M_TRSCStrTrq);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 256.0F);
  }

  rty_IbTRSC_ME_VehOut_TRSC->IeTRSC_deg_TADAngAct = (uint8_T)(tmp < 0.0F ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion2' */

  /* BusCreator: '<Root>/Bus Creator1' */
  rty_IbTRSC_ME_VehOut_TRSC->IeTRSC_e_SpdLmtReq = *rtu_IeTRSC_e_SpdLmtReq_In;
  rty_IbTRSC_ME_VehOut_TRSC->IeTRSC_e_VehStpReq = *rtu_IeTRSC_e_VehStpReq_In;
  rty_IbTRSC_ME_VehOut_TRSC->IeTRSC_e_TRSCLedSts = *rtu_IeTRSC_e_TRSCLedSts_In;
  rty_IbTRSC_ME_VehOut_TRSC->IeTRSC_e_TRSCPopupDispInfo =
    *rtu_IeTRSC_e_TRSCPopupDispInfo_In;
  rty_IbTRSC_ME_VehOut_TRSC->IeTRSC_e_TRSCSts = *rtu_IeTRSC_e_TRSCSts_In;
  rty_IbTRSC_ME_VehOut_TRSC->IeTRSC_e_TRSCStrTrqActvReq =
    *rtu_IeTRSC_e_TRSCStrTrqActvReq_In;
  rty_IbTRSC_ME_VehOut_TRSC->IeTRSC_e_TrlrHitchLightCtrl =
    *rtu_IeTRSC_e_TrlrHitchLightCtrl_In;
  rty_IbTRSC_ME_VehOut_TRSC->IeTRSC_M_TRSCStrTrq = *rtu_IeTRSC_M_TRSCStrTrq_In;
  rty_IbTRSC_ME_VehOut_TRSC->IeTRSC_pct_TRSCStrDmp =
    *rtu_IeTRSC_pct_TRSCStrDmp_In;
  rty_IbTRSC_ME_VehOut_TRSC->IeTRSC_e_TADAngActSign =
    *rtu_IeTRSC_e_TADAngActSign_In;
  rty_IbTRSC_ME_VehOut_TRSC->IeTRSC_e_TrlrCalInfo = *rtu_IeTRSC_e_TrlrCalInfo_In;
  rty_IbTRSC_ME_VehOut_TRSC->IeTRSC_b_MoreCamReqSts =
    *rtu_IeTRSC_b_MoreCamReqSts_In;
  rty_IbTRSC_ME_VehOut_TRSC->IeTRSC_kph_SpdLmtReq_DID =
    *rtu_IeTRSC_kph_SpdLmtReq_DID;
  rty_IbTRSC_ME_VehOut_TRSC->IeTRSC_e_VehStpReq_DID =
    *rtu_IeTRSC_e_VehStpReq_DID;

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  MeTRSC_M_SteeringTorqInfo = *rtu_IeTRSC_M_TRSCStrTrq_In;

  /* BusCreator: '<Root>/Bus Creator2' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant6'
   */
  rty_IbTRSC_TRSCtoSVS->MeTRSC_e_TRSCStat = *rtu_MeTRSC_e_TRSCStat_In;
  rty_IbTRSC_TRSCtoSVS->MeTRSC_e_TrlrCalInfoSMVC = *rtu_IeTRSC_e_TrlrCalInfo_In;
  rty_IbTRSC_TRSCtoSVS->MeTRSC_deg_JackKnifeAngle =
    *rtu_MeTRSC_deg_JackKnifeAngle_In;
  rty_IbTRSC_TRSCtoSVS->MeTRSC_deg_JackknifeThrAngle =
    *rtu_MeTRSC_deg_JackknifeThrAngle_In;
  rty_IbTRSC_TRSCtoSVS->MeTRSC_deg_MaxAllowedTADAngle =
    *rtu_MeTRSC_deg_MaxAllowedTADAngle_In;
  rty_IbTRSC_TRSCtoSVS->MeTRSC_deg_KnobAngle = *rtu_MeTRSC_deg_KnobAngle_In;
  rty_IbTRSC_TRSCtoSVS->MeTRSC_M_SteeringTorqInfo = MeTRSC_M_SteeringTorqInfo;
  rty_IbTRSC_TRSCtoSVS->MeTRSC_deg_TADAngleSMVC =
    *rtu_MeTRSC_deg_TADAngleSMVC_In;
  rty_IbTRSC_TRSCtoSVS->ReservedSignal1 = CeConst_k_ConstZero;
  rty_IbTRSC_TRSCtoSVS->ReservedSignal2 = CeConst_k_ConstZero;
  rty_IbTRSC_TRSCtoSVS->MeTRSC_b_MoreCamSoftButtEnbl =
    *rtu_MeTRSC_b_MoreCamSoftButtEnbl_In;
  rty_IbTRSC_TRSCtoSVS->MeTRSC_b_TrlrRevSteeringStsInfo =
    *rtu_MeTRSC_b_TrlrRevSteeringStsInfo_In;

  /* BusCreator: '<Root>/Bus Creator3' */
  rty_IbTRSC_DetInp_from_TRSC->MeTRSC_e_TRSCStat = *rtu_MeTRSC_e_TRSCStat_In;
  rty_IbTRSC_DetInp_from_TRSC->MeTRSC_deg_JackKnifeAngle =
    *rtu_MeTRSC_deg_JackKnifeAngle_In;
  rty_IbTRSC_DetInp_from_TRSC->MeTRSC_m_TrailerBeamLen =
    *rtu_MeTRSC_m_TrailerBeamLen_In;
  rty_IbTRSC_DetInp_from_TRSC->MeTRSC_e_TrlrPrsntInfoCAN =
    *rtu_MeTRSC_e_TrlrPrsntInfoCAN_In;
  rty_IbTRSC_DetInp_from_TRSC->MeTRSC_b_TRSCSwitchPressed =
    *rtu_MeTRSC_b_TRSCSwitchPressed_In1;
  rty_IbTRSC_DetInp_from_TRSC->MeTRSC_b_OTBLReset = *rtu_MeTRSC_b_OTBLReset_In;
  rty_IbTRSC_DetInp_from_TRSC->MeTRSC_b_TBLComputationDone =
    *rtu_MeTRSC_b_TBLComputationDone_In;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  TRSC_OutputAdapter_B.IeTRSC_M_TRSCStrTrq = *rtu_IeTRSC_M_TRSCStrTrq_In;

  /* BusCreator: '<Root>/Bus Creator4' */
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_e_TRSKMBtnSts = *rtu_IeTRSC_e_TRSKMBtnSts;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_e_TRSKMBtnSts_DID =
    *rtu_IeTRSC_e_TRSKMBtnSts_DID;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_e_TRSKMCenBtnSts =
    *rtu_IeTRSC_e_TRSKMCenBtnSts;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_e_TRSKMCenBtnSts_DID =
    *rtu_IeTRSC_e_TRSKMCenBtnSts_DID;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_e_TRSKMSts = *rtu_IeTRSC_e_TRSKMSts;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_e_TRSKMSts_DID = *rtu_IeTRSC_e_TRSKMSts_DID;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_e_GearShiftSts = *rtu_IeTRSC_e_GearShiftSts;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_e_GearShiftSts_DID =
    *rtu_IeTRSC_e_GearShiftSts_DID;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_e_TRSCUnavailReas =
    *rtu_IeTRSC_e_TRSCUnavailReas;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_e_TRSCUnavailReas_DID =
    *rtu_IeTRSC_e_TRSCUnavailReas_DID;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_e_TRSCAbortReas = *rtu_IeTRSC_e_TRSCAbortReas;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_e_TRSCAbortReas_DID =
    *rtu_IeTRSC_e_TRSCAbortReas_DID;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_kph_VehSpeedVSOSig =
    *rtu_IeTRSC_kph_VehSpeedVSOSig;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_m_TrlrWhlBaseEff =
    *rtu_IeTRSC_m_TrlrWhlBaseEff;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_deg_FrntWhlAng = *rtu_IeTRSC_deg_FrntWhlAng;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_deg_TrlrAngKnob = *rtu_IeTRSC_deg_TrlrAngKnob;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_deg_JackknifeThrAngle =
    *rtu_IeTRSC_deg_JackknifeThrAngle;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_M_TRSCStrTrq =
    TRSC_OutputAdapter_B.IeTRSC_M_TRSCStrTrq;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_cnt_KnobPos = *rtu_IeTRSC_cnt_KnobPos;
  rty_IbTRSC_TRSCtoDiagMgr->MeSVS_e_DispView2Info_DID =
    *rtu_MeSVS_e_DispView2Info_DID_In;
  rty_IbTRSC_TRSCtoDiagMgr->IeTRSC_e_GraphicOverlay_Sts =
    *rtu_IeTRSC_e_GraphicOverlay_Sts_In;

  /* BusCreator: '<Root>/Bus Creator' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   */
  rty_IbTRSC_TRSCSMVCtoDebugCAN_t->MeTRSC_deg_StrCMD = *rtu_MeTRSC_deg_StrCMD;
  rty_IbTRSC_TRSCSMVCtoDebugCAN_t->ReservedTRSCSig1 = CeConst_k_ConstZero;
  rty_IbTRSC_TRSCSMVCtoDebugCAN_t->ReservedTRSCSig2 = CeConst_k_ConstZero;
  rty_IbTRSC_TRSCSMVCtoDebugCAN_t->MeTRSC_s_TRSCPeriodicity =
    CeConst_k_ConstZeroUint16;
  rty_IbTRSC_TRSCSMVCtoDebugCAN_t->MeTRSC_s_TRSCTimeTaken =
    CeConst_k_ConstZeroUint16;
  rty_IbTRSC_TRSCSMVCtoDebugCAN_t->MeTRSC_cnt_TRSCAliveCounter =
    CeConst_k_ConstZeroUint16;
  rty_IbTRSC_TRSCSMVCtoDebugCAN_t->MeTRSC_b_TrlrCalibPopInfo =
    *rtu_MeTRSC_b_TrlrCalibPopInfo;
}

/* Model initialize function */
void TRSC_OutputAdapter_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_TRSC_OutputAdapter_T *const TRSC_OutputAdapter_M =
    &(TRSC_OutputAdapter_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(TRSC_OutputAdapter_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
