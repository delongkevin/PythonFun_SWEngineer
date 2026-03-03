/*
 * File: TRSC_OutputAdapter.h
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

#ifndef RTW_HEADER_TRSC_OutputAdapter_h_
#define RTW_HEADER_TRSC_OutputAdapter_h_
#include <math.h>
#ifndef TRSC_OutputAdapter_COMMON_INCLUDES_
# define TRSC_OutputAdapter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TRSC_OutputAdapter_COMMON_INCLUDES_ */

#include "TRSC_OutputAdapter_types.h"

/* Includes for objects with custom storage classes. */
#include "TRSC_CalibParams.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* user code (top of header file) */
#include "SignalDef.h"

/* Block signals for model 'TRSC_OutputAdapter' */
#ifndef TRSC_OutputAdapter_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T IeTRSC_M_TRSCStrTrq;        /* '<Root>/Data Type Conversion1' */
} B_TRSC_OutputAdapter_c_T;

#endif                                 /*TRSC_OutputAdapter_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_OutputAdapter_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_TRSC_OutputAdapter_T {
  const char_T **errorStatus;
};

#endif                                 /*TRSC_OutputAdapter_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_OutputAdapter_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_TRSC_OutputAdapter_T rtm;
} MdlrefDW_TRSC_OutputAdapter_T;

#endif                                 /*TRSC_OutputAdapter_MDLREF_HIDE_CHILD_*/

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T MeTRSC_M_SteeringTorqInfo;/* '<Root>/Data Type Conversion'
                                           * MeTRSC_M_SteeringTorqInfo
                                           */
extern void TRSC_OutputAdapter(const TeTRSC_e_SpdLmtReq
  *rtu_IeTRSC_e_SpdLmtReq_In, const TeTRSC_e_VehStpReq
  *rtu_IeTRSC_e_VehStpReq_In, const TeTRSC_e_TRSCLedSts
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
  TRSCSMVCtoDebugCAN_t *rty_IbTRSC_TRSCSMVCtoDebugCAN_t);

/* Model reference registration function */
extern void TRSC_OutputAdapter_initialize(const char_T **rt_errorStatus);

#ifndef TRSC_OutputAdapter_MDLREF_HIDE_CHILD_

extern MdlrefDW_TRSC_OutputAdapter_T TRSC_OutputAdapter_MdlrefDW;

#endif                                 /*TRSC_OutputAdapter_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_OutputAdapter_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_TRSC_OutputAdapter_c_T TRSC_OutputAdapter_B;

#endif                                 /*TRSC_OutputAdapter_MDLREF_HIDE_CHILD_*/

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TRSC_OutputAdapter'
 */
#endif                                 /* RTW_HEADER_TRSC_OutputAdapter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
