/*
 * File: THA_SmVc_Ref.h
 *
 * Code generated for Simulink model 'THA_SmVc_Ref'.
 *
 * Model version                  : 1.1542
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Aug  7 17:42:52 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_THA_SmVc_Ref_h_
#define RTW_HEADER_THA_SmVc_Ref_h_
#include <string.h>
#ifndef THA_SmVc_Ref_COMMON_INCLUDES_
# define THA_SmVc_Ref_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* THA_SmVc_Ref_COMMON_INCLUDES_ */

#include "THA_SmVc_Ref_types.h"

/* Child system includes */
#ifndef THA_SmVc_Ref_MDLREF_HIDE_CHILD_
#define THA_SM_Ref_MDLREF_HIDE_CHILD_
#include "THA_SM_Ref.h"
#endif                                 /*THA_SmVc_Ref_MDLREF_HIDE_CHILD_*/

#ifndef THA_SmVc_Ref_MDLREF_HIDE_CHILD_
#define THA_VC_Ref_MDLREF_HIDE_CHILD_
#include "THA_VC_Ref.h"
#endif                                 /*THA_SmVc_Ref_MDLREF_HIDE_CHILD_*/

/* Includes for objects with custom storage classes. */
#include "THA_CalibParams.h"

/* Block signals for model 'THA_SmVc_Ref' */
#ifndef THA_SmVc_Ref_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T MeTHA_deg_RoadWhlAng;       /* '<S1>/THA_VC_Ref' */
  TeTHA_e_THASteerTrqReq MeTHA_e_THASteerTrqReq;/* '<S1>/THA_SM_Ref' */
  TeTHA_e_THASteerTrqReq IeTHA_e_THASteerTrqReqPrev;/* '<S1>/UnitDelay1' */
  TeTHA_e_THAStateInfo MeTHA_e_THAStateInfo;/* '<S1>/THA_SM_Ref' */
  TeTHA_e_THAState IeTHA_e_THAState;   /* '<S1>/THA_SM_Ref' */
  TeTHA_e_THARmpUpDwnSpd IeTHA_e_THARmpUpDwnSpd;/* '<S1>/THA_VC_Ref' */
  TeTHA_e_THARmpUpDwnSpd IeTHA_e_THARmpUpDwnSpdPrev;/* '<S1>/UnitDelay' */
  TeTHA_e_ScreenRequest MeTHA_e_ScreenRequest;/* '<S1>/THA_SM_Ref' */
  boolean_T MeTHA_b_UsrHitchCnfm;      /* '<S1>/THA_SM_Ref' */
  boolean_T MeTHA_b_UsrCplrSelCnfm;    /* '<S1>/THA_SM_Ref' */
} B_THA_SmVc_Ref_caua_T;

#endif                                 /*THA_SmVc_Ref_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'THA_SmVc_Ref' */
#ifndef THA_SmVc_Ref_MDLREF_HIDE_CHILD_

typedef struct {
  TeTHA_e_THARmpUpDwnSpd UnitDelay_DSTATE;/* '<S1>/UnitDelay' */
  TeTHA_e_THASteerTrqReq UnitDelay1_DSTATE;/* '<S1>/UnitDelay1' */
  boolean_T THA_SmVc_Enabled_MODE;     /* '<Root>/THA_SmVc_Enabled' */
} DW_THA_SmVc_Ref_fwu4_T;

#endif                                 /*THA_SmVc_Ref_MDLREF_HIDE_CHILD_*/

extern void THA_SmVc_Ref_Init(boolean_T *rty_IeTHA_b_ChimeActvLhr, boolean_T
  *rty_IeTHA_b_ChimeActvRhr, TeTHA_e_PamChimeRepRateSts
  *rty_IeTHA_e_PamChimeRepRateSts, real32_T *rty_IeTHA_pct_THAStrDamp);
extern void THA_SmVc_Ref_Start(boolean_T *rty_IeTHA_b_ChimeActvLhr, boolean_T
  *rty_IeTHA_b_ChimeActvRhr, TeTHA_e_PamChimeRepRateSts
  *rty_IeTHA_e_PamChimeRepRateSts, real32_T *rty_IeTHA_pct_THAStrDamp);
extern void THA_SmVc_Ref_Disable(TeTHA_e_THAState *rty_IeTHA_e_THAState,
  TeTHA_e_THASpdLimReq *rty_IeTHA_e_THASpdLimReq, TeTHA_e_PamVol
  *rty_IeTHA_e_PamVol, boolean_T *rty_IeTHA_b_ChimeActvLhf, boolean_T
  *rty_IeTHA_b_ChimeActvRhf, boolean_T *rty_IeTHA_b_ChimeActvLhr, boolean_T
  *rty_IeTHA_b_ChimeActvRhr, TeTHA_e_PamChimeTyp *rty_IeTHA_e_PamChimeTyp,
  TeTHA_e_PamChimeRepRateSts *rty_IeTHA_e_PamChimeRepRateSts,
  TeTHA_e_THASteerTrqReq *rty_IeTHA_e_THASteerTrqReq, TeTHA_e_THARmpUpDwnSpd
  *rty_IeTHA_e_THARmpUpDwnSpd, real32_T *rty_IeTHA_M_THASteerTrqInfo,
  TeTHA_e_EPBReq *rty_IeTHA_e_EPBReq, real32_T *rty_IeTHA_pct_THAStrDamp,
  TeTHA_e_THAStateInfo *rty_MeTHA_e_THAStateInfo, TeTHA_e_ScreenRequest
  *rty_MeTHA_e_ScreenRequest, boolean_T *rty_MeTHA_b_EnblRearParkAsstTrg,
  TeTHA_e_RearBrkSupprInfo *rty_MeTHA_e_RearBrkSupprInfo, boolean_T
  *rty_MeTHA_b_UsrHitchCnfm, boolean_T *rty_MeTHA_b_UsrCplrSelCnfm, real32_T
  *rty_MeTHA_deg_RoadWhlAng);
extern void THA_SmVc_Ref(const TbTHASmVc_InputFromThaDet_t
  *rtu_MbTHA_ThaDetOutData, const TbTHASmVc_InputFromHmiSvs_t
  *rtu_MbTHA_HmiSvsOutData, const TbTHASmVc_InputFromApSmPa_t
  *rtu_MbTHA_ApSmOutData, const TbTHASmVc_InputFromVehInp_t
  *rtu_MbTHA_VehInpOutData, const TbTHASmVc_InputFromProxiMgr_t
  *rtu_MbTHA_ProxiMgrOutData, const TbTHASmVc_InputFromTRSC_t
  *rtu_MbTHA_TrscSmVcOutData, const TbTHASmVc_InputFromDegMgr_t
  *rtu_MbTHA_DegradMgrOutData, const TbTHASmVc_InputVrntTunParam_t
  *rtu_MbTHA_VrntTunParamOutData, TeTHA_e_THAState *rty_IeTHA_e_THAState,
  TeTHA_e_THASpdLimReq *rty_IeTHA_e_THASpdLimReq, TeTHA_e_PamVol
  *rty_IeTHA_e_PamVol, boolean_T *rty_IeTHA_b_ChimeActvLhf, boolean_T
  *rty_IeTHA_b_ChimeActvRhf, boolean_T *rty_IeTHA_b_ChimeActvLhr, boolean_T
  *rty_IeTHA_b_ChimeActvRhr, TeTHA_e_PamChimeTyp *rty_IeTHA_e_PamChimeTyp,
  TeTHA_e_PamChimeRepRateSts *rty_IeTHA_e_PamChimeRepRateSts,
  TeTHA_e_THASteerTrqReq *rty_IeTHA_e_THASteerTrqReq, TeTHA_e_THARmpUpDwnSpd
  *rty_IeTHA_e_THARmpUpDwnSpd, real32_T *rty_IeTHA_M_THASteerTrqInfo,
  TeTHA_e_EPBReq *rty_IeTHA_e_EPBReq, real32_T *rty_IeTHA_pct_THAStrDamp,
  TeTHA_e_THAStateInfo *rty_MeTHA_e_THAStateInfo, TeTHA_e_ScreenRequest
  *rty_MeTHA_e_ScreenRequest, boolean_T *rty_MeTHA_b_EnblRearParkAsstTrg,
  TeTHA_e_RearBrkSupprInfo *rty_MeTHA_e_RearBrkSupprInfo, boolean_T
  *rty_MeTHA_b_UsrHitchCnfm, boolean_T *rty_MeTHA_b_UsrCplrSelCnfm, boolean_T
  *rty_MeTHA_b_TrlrCplrStatus, boolean_T *rty_MeTHA_b_THAAbortStatus, real32_T
  *rty_MeTHA_deg_RoadWhlAng, boolean_T *rty_MeTHA_b_UsrInputTimeOut, boolean_T
  *rty_MeTHA_b_ViewZoomSts, boolean_T *rty_MeTHA_b_CamOccluLoLi, int32_T
  *rty_MeTHA_px_HitchCplrPixDiffLongAtStrt);

/* Model reference registration function */
extern void THA_SmVc_Ref_initialize(void);

#ifndef THA_SmVc_Ref_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_THA_SmVc_Ref_caua_T THA_SmVc_Ref_B;

/* Block states (default storage) */
extern DW_THA_SmVc_Ref_fwu4_T THA_SmVc_Ref_DW;

#endif                                 /*THA_SmVc_Ref_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'THA_SmVc_Ref'
 * '<S1>'   : 'THA_SmVc_Ref/THA_SmVc_Enabled'
 */

/*-
 * Requirements for '<Root>': THA_SmVc_Ref
 */
#endif                                 /* RTW_HEADER_THA_SmVc_Ref_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
