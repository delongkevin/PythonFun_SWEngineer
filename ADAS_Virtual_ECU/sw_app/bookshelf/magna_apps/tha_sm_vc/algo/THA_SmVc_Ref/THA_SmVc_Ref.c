/*
 * File: THA_SmVc_Ref.c
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

#include "THA_SmVc_Ref.h"
#include "THA_SmVc_Ref_private.h"

/* Block signals (default storage) */
B_THA_SmVc_Ref_caua_T THA_SmVc_Ref_B;

/* Block states (default storage) */
DW_THA_SmVc_Ref_fwu4_T THA_SmVc_Ref_DW;

/* System initialize for referenced model: 'THA_SmVc_Ref' */
void THA_SmVc_Ref_Init(boolean_T *rty_IeTHA_b_ChimeActvLhr, boolean_T
  *rty_IeTHA_b_ChimeActvRhr, TeTHA_e_PamChimeRepRateSts
  *rty_IeTHA_e_PamChimeRepRateSts, real32_T *rty_IeTHA_pct_THAStrDamp)
{
  /* SystemInitialize for Enabled SubSystem: '<Root>/THA_SmVc_Enabled' */
  /* InitializeConditions for UnitDelay: '<S1>/UnitDelay' */
  THA_SmVc_Ref_DW.UnitDelay_DSTATE = TeTHA_e_THARmpUpDwnSpd_No_Request;

  /* InitializeConditions for UnitDelay: '<S1>/UnitDelay1' */
  THA_SmVc_Ref_DW.UnitDelay1_DSTATE = TeTHA_e_THASteerTrqReq_False;

  /* SystemInitialize for ModelReference: '<S1>/THA_SM_Ref' */
  THA_SM_Ref_Init();

  /* SystemInitialize for ModelReference: '<S1>/THA_VC_Ref' */
  THA_VC_Ref_Init();

  /* SystemInitialize for Outport: '<S1>/IeTHA_b_ChimeActvLhr' */
  *rty_IeTHA_b_ChimeActvLhr = false;

  /* SystemInitialize for Outport: '<S1>/IeTHA_b_ChimeActvRhr' */
  *rty_IeTHA_b_ChimeActvRhr = false;

  /* SystemInitialize for Outport: '<S1>/IeTHA_e_PamChimeRepRateSts' */
  *rty_IeTHA_e_PamChimeRepRateSts = TeTHA_e_PamChimeRepRateSts_Continuous_0_Hz;

  /* SystemInitialize for Outport: '<S1>/IeTHA_pct_THAStrDamp' */
  *rty_IeTHA_pct_THAStrDamp = 0.0F;

  /* End of SystemInitialize for SubSystem: '<Root>/THA_SmVc_Enabled' */
}

/* Disable for referenced model: 'THA_SmVc_Ref' */
void THA_SmVc_Ref_Disable(TeTHA_e_THAState *rty_IeTHA_e_THAState,
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
  *rty_MeTHA_deg_RoadWhlAng)
{
  /* Disable for Enabled SubSystem: '<Root>/THA_SmVc_Enabled' */
  if (THA_SmVc_Ref_DW.THA_SmVc_Enabled_MODE) {
    /* Disable for ModelReference: '<S1>/THA_VC_Ref' */
    THA_VC_Ref_Disable(&THA_SmVc_Ref_B.IeTHA_e_THARmpUpDwnSpd,
                       &THA_SmVc_Ref_B.MeTHA_deg_RoadWhlAng);

    /* Disable for Outport: '<S1>/IeTHA_e_THAState' */
    *rty_IeTHA_e_THAState = TeTHA_e_THAState_Initial;

    /* Disable for Outport: '<S1>/IeTHA_e_THASpdLimReq' */
    *rty_IeTHA_e_THASpdLimReq = TeTHA_e_THASpdLimReq_No_Request;

    /* Disable for Outport: '<S1>/IeTHA_e_PamVol' */
    *rty_IeTHA_e_PamVol = TeTHA_e_PamVol_None;

    /* Disable for Outport: '<S1>/IeTHA_b_ChimeActvLhf' */
    *rty_IeTHA_b_ChimeActvLhf = false;

    /* Disable for Outport: '<S1>/IeTHA_b_ChimeActvRhf' */
    *rty_IeTHA_b_ChimeActvRhf = false;

    /* Disable for Outport: '<S1>/IeTHA_b_ChimeActvLhr' */
    *rty_IeTHA_b_ChimeActvLhr = false;

    /* Disable for Outport: '<S1>/IeTHA_b_ChimeActvRhr' */
    *rty_IeTHA_b_ChimeActvRhr = false;

    /* Disable for Outport: '<S1>/IeTHA_e_PamChimeTyp' */
    *rty_IeTHA_e_PamChimeTyp = TeTHA_e_PamChimeTyp_None;

    /* Disable for Outport: '<S1>/IeTHA_e_PamChimeRepRateSts' */
    *rty_IeTHA_e_PamChimeRepRateSts = TeTHA_e_PamChimeRepRateSts_Continuous_0_Hz;

    /* Disable for Outport: '<S1>/IeTHA_e_THASteerTrqReq' */
    *rty_IeTHA_e_THASteerTrqReq = TeTHA_e_THASteerTrqReq_False;

    /* Disable for Outport: '<S1>/IeTHA_e_THARmpUpDwnSpd' */
    *rty_IeTHA_e_THARmpUpDwnSpd = TeTHA_e_THARmpUpDwnSpd_No_Request;

    /* Disable for Outport: '<S1>/IeTHA_M_THASteerTrqInfo' */
    *rty_IeTHA_M_THASteerTrqInfo = 0.0F;

    /* Disable for Outport: '<S1>/IeTHA_e_EPBReq' */
    *rty_IeTHA_e_EPBReq = TeTHA_e_EPBReq_No_Request;

    /* Disable for Outport: '<S1>/IeTHA_pct_THAStrDamp' */
    *rty_IeTHA_pct_THAStrDamp = 0.0F;

    /* Disable for Outport: '<S1>/MeTHA_e_THAStateInfo' */
    *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Off;

    /* Disable for Outport: '<S1>/MeTHA_e_ScreenRequest' */
    *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_Default;

    /* Disable for Outport: '<S1>/MeTHA_b_EnblRearParkAsstTrg' */
    *rty_MeTHA_b_EnblRearParkAsstTrg = false;

    /* Disable for Outport: '<S1>/MeTHA_e_RearBrkSupprInfo' */
    *rty_MeTHA_e_RearBrkSupprInfo = TeTHA_e_RearBrkSupprInfo_Invalid;

    /* Disable for Outport: '<S1>/MeTHA_b_UsrHitchCnfm' */
    *rty_MeTHA_b_UsrHitchCnfm = false;

    /* Disable for Outport: '<S1>/MeTHA_b_UsrCplrSelCnfm' */
    *rty_MeTHA_b_UsrCplrSelCnfm = false;

    /* Disable for Outport: '<S1>/MeTHA_deg_RoadWhlAng' */
    *rty_MeTHA_deg_RoadWhlAng = 0.0F;
    THA_SmVc_Ref_DW.THA_SmVc_Enabled_MODE = false;
  }

  /* End of Disable for SubSystem: '<Root>/THA_SmVc_Enabled' */
}

/* Start for referenced model: 'THA_SmVc_Ref' */
void THA_SmVc_Ref_Start(boolean_T *rty_IeTHA_b_ChimeActvLhr, boolean_T
  *rty_IeTHA_b_ChimeActvRhr, TeTHA_e_PamChimeRepRateSts
  *rty_IeTHA_e_PamChimeRepRateSts, real32_T *rty_IeTHA_pct_THAStrDamp)
{
  /* Start for Enabled SubSystem: '<Root>/THA_SmVc_Enabled' */

  /* Start for ModelReference: '<S1>/THA_SM_Ref' */
  THA_SM_Ref_Start(rty_IeTHA_b_ChimeActvLhr, rty_IeTHA_b_ChimeActvRhr,
                   rty_IeTHA_e_PamChimeRepRateSts);

  /* Start for ModelReference: '<S1>/THA_VC_Ref' */
  THA_VC_Ref_Start(rty_IeTHA_pct_THAStrDamp);

  /* End of Start for SubSystem: '<Root>/THA_SmVc_Enabled' */
}

/* Output and update for referenced model: 'THA_SmVc_Ref' */
void THA_SmVc_Ref(const TbTHASmVc_InputFromThaDet_t *rtu_MbTHA_ThaDetOutData,
                  const TbTHASmVc_InputFromHmiSvs_t *rtu_MbTHA_HmiSvsOutData,
                  const TbTHASmVc_InputFromApSmPa_t *rtu_MbTHA_ApSmOutData,
                  const TbTHASmVc_InputFromVehInp_t *rtu_MbTHA_VehInpOutData,
                  const TbTHASmVc_InputFromProxiMgr_t *rtu_MbTHA_ProxiMgrOutData,
                  const TbTHASmVc_InputFromTRSC_t *rtu_MbTHA_TrscSmVcOutData,
                  const TbTHASmVc_InputFromDegMgr_t *rtu_MbTHA_DegradMgrOutData,
                  const TbTHASmVc_InputVrntTunParam_t
                  *rtu_MbTHA_VrntTunParamOutData, TeTHA_e_THAState
                  *rty_IeTHA_e_THAState, TeTHA_e_THASpdLimReq
                  *rty_IeTHA_e_THASpdLimReq, TeTHA_e_PamVol *rty_IeTHA_e_PamVol,
                  boolean_T *rty_IeTHA_b_ChimeActvLhf, boolean_T
                  *rty_IeTHA_b_ChimeActvRhf, boolean_T *rty_IeTHA_b_ChimeActvLhr,
                  boolean_T *rty_IeTHA_b_ChimeActvRhr, TeTHA_e_PamChimeTyp
                  *rty_IeTHA_e_PamChimeTyp, TeTHA_e_PamChimeRepRateSts
                  *rty_IeTHA_e_PamChimeRepRateSts, TeTHA_e_THASteerTrqReq
                  *rty_IeTHA_e_THASteerTrqReq, TeTHA_e_THARmpUpDwnSpd
                  *rty_IeTHA_e_THARmpUpDwnSpd, real32_T
                  *rty_IeTHA_M_THASteerTrqInfo, TeTHA_e_EPBReq
                  *rty_IeTHA_e_EPBReq, real32_T *rty_IeTHA_pct_THAStrDamp,
                  TeTHA_e_THAStateInfo *rty_MeTHA_e_THAStateInfo,
                  TeTHA_e_ScreenRequest *rty_MeTHA_e_ScreenRequest, boolean_T
                  *rty_MeTHA_b_EnblRearParkAsstTrg, TeTHA_e_RearBrkSupprInfo
                  *rty_MeTHA_e_RearBrkSupprInfo, boolean_T
                  *rty_MeTHA_b_UsrHitchCnfm, boolean_T
                  *rty_MeTHA_b_UsrCplrSelCnfm, boolean_T
                  *rty_MeTHA_b_TrlrCplrStatus, boolean_T
                  *rty_MeTHA_b_THAAbortStatus, real32_T
                  *rty_MeTHA_deg_RoadWhlAng, boolean_T
                  *rty_MeTHA_b_UsrInputTimeOut, boolean_T
                  *rty_MeTHA_b_ViewZoomSts, boolean_T *rty_MeTHA_b_CamOccluLoLi,
                  int32_T *rty_MeTHA_px_HitchCplrPixDiffLongAtStrt)
{
  /* Outputs for Enabled SubSystem: '<Root>/THA_SmVc_Enabled' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  if (rtu_MbTHA_ProxiMgrOutData->MePRX_b_TrlrHitchAssPres) {
    if (!THA_SmVc_Ref_DW.THA_SmVc_Enabled_MODE) {
      /* InitializeConditions for UnitDelay: '<S1>/UnitDelay' */
      THA_SmVc_Ref_DW.UnitDelay_DSTATE = TeTHA_e_THARmpUpDwnSpd_No_Request;

      /* InitializeConditions for UnitDelay: '<S1>/UnitDelay1' */
      THA_SmVc_Ref_DW.UnitDelay1_DSTATE = TeTHA_e_THASteerTrqReq_False;

      /* SystemReset for ModelReference: '<S1>/THA_SM_Ref' */
      THA_SM_Ref_Reset(&THA_SmVc_Ref_B.IeTHA_e_THAState,
                       &THA_SmVc_Ref_B.MeTHA_e_THAStateInfo,
                       &THA_SmVc_Ref_B.MeTHA_e_ScreenRequest,
                       &THA_SmVc_Ref_B.MeTHA_b_UsrHitchCnfm,
                       &THA_SmVc_Ref_B.MeTHA_b_UsrCplrSelCnfm);

      /* SystemReset for ModelReference: '<S1>/THA_VC_Ref' */
      THA_VC_Ref_Reset();
      THA_SmVc_Ref_DW.THA_SmVc_Enabled_MODE = true;
    }

    /* UnitDelay: '<S1>/UnitDelay' */
    THA_SmVc_Ref_B.IeTHA_e_THARmpUpDwnSpdPrev = THA_SmVc_Ref_DW.UnitDelay_DSTATE;

    /* UnitDelay: '<S1>/UnitDelay1' */
    THA_SmVc_Ref_B.IeTHA_e_THASteerTrqReqPrev =
      THA_SmVc_Ref_DW.UnitDelay1_DSTATE;

    /* ModelReference: '<S1>/THA_SM_Ref' */
    THA_SM_Ref(rtu_MbTHA_ThaDetOutData, rtu_MbTHA_HmiSvsOutData,
               rtu_MbTHA_VehInpOutData, rtu_MbTHA_ProxiMgrOutData,
               rtu_MbTHA_DegradMgrOutData, rtu_MbTHA_ApSmOutData,
               rtu_MbTHA_TrscSmVcOutData, rtu_MbTHA_VrntTunParamOutData,
               &THA_SmVc_Ref_B.IeTHA_e_THARmpUpDwnSpdPrev,
               &THA_SmVc_Ref_B.IeTHA_e_THASteerTrqReqPrev,
               &THA_SmVc_Ref_B.IeTHA_e_THAState, rty_IeTHA_e_THASpdLimReq,
               rty_IeTHA_e_PamVol, rty_IeTHA_b_ChimeActvLhf,
               rty_IeTHA_b_ChimeActvRhf, rty_IeTHA_b_ChimeActvLhr,
               rty_IeTHA_b_ChimeActvRhr, rty_IeTHA_e_PamChimeTyp,
               rty_IeTHA_e_PamChimeRepRateSts,
               &THA_SmVc_Ref_B.MeTHA_e_THASteerTrqReq, rty_IeTHA_e_EPBReq,
               &THA_SmVc_Ref_B.MeTHA_e_THAStateInfo,
               &THA_SmVc_Ref_B.MeTHA_e_ScreenRequest,
               rty_MeTHA_b_EnblRearParkAsstTrg, rty_MeTHA_e_RearBrkSupprInfo,
               &THA_SmVc_Ref_B.MeTHA_b_UsrHitchCnfm,
               &THA_SmVc_Ref_B.MeTHA_b_UsrCplrSelCnfm,
               rty_MeTHA_b_TrlrCplrStatus, rty_MeTHA_b_THAAbortStatus,
               rty_MeTHA_b_UsrInputTimeOut, rty_MeTHA_b_ViewZoomSts,
               rty_MeTHA_b_CamOccluLoLi, rty_MeTHA_px_HitchCplrPixDiffLongAtStrt);

    /* ModelReference: '<S1>/THA_VC_Ref' */
    THA_VC_Ref(rtu_MbTHA_ThaDetOutData, rtu_MbTHA_VehInpOutData,
               rtu_MbTHA_ProxiMgrOutData, rtu_MbTHA_VrntTunParamOutData,
               &THA_SmVc_Ref_B.MeTHA_e_THASteerTrqReq,
               &THA_SmVc_Ref_B.MeTHA_e_THAStateInfo,
               &THA_SmVc_Ref_B.IeTHA_e_THARmpUpDwnSpd,
               rty_IeTHA_M_THASteerTrqInfo, rty_IeTHA_e_THASteerTrqReq,
               rty_IeTHA_pct_THAStrDamp, &THA_SmVc_Ref_B.MeTHA_deg_RoadWhlAng);

    /* SignalConversion generated from: '<S1>/IeTHA_e_THARmpUpDwnSpd' */
    *rty_IeTHA_e_THARmpUpDwnSpd = THA_SmVc_Ref_B.IeTHA_e_THARmpUpDwnSpd;

    /* SignalConversion generated from: '<S1>/MeTHA_deg_RoadWhlAng' */
    *rty_MeTHA_deg_RoadWhlAng = THA_SmVc_Ref_B.MeTHA_deg_RoadWhlAng;

    /* SignalConversion generated from: '<S1>/IeTHA_e_THAState' */
    *rty_IeTHA_e_THAState = THA_SmVc_Ref_B.IeTHA_e_THAState;

    /* SignalConversion generated from: '<S1>/MeTHA_b_UsrCplrSelCnfm' */
    *rty_MeTHA_b_UsrCplrSelCnfm = THA_SmVc_Ref_B.MeTHA_b_UsrCplrSelCnfm;

    /* SignalConversion generated from: '<S1>/MeTHA_b_UsrHitchCnfm' */
    *rty_MeTHA_b_UsrHitchCnfm = THA_SmVc_Ref_B.MeTHA_b_UsrHitchCnfm;

    /* SignalConversion generated from: '<S1>/MeTHA_e_ScreenRequest' */
    *rty_MeTHA_e_ScreenRequest = THA_SmVc_Ref_B.MeTHA_e_ScreenRequest;

    /* SignalConversion generated from: '<S1>/MeTHA_e_THAStateInfo' */
    *rty_MeTHA_e_THAStateInfo = THA_SmVc_Ref_B.MeTHA_e_THAStateInfo;

    /* Update for UnitDelay: '<S1>/UnitDelay' */
    THA_SmVc_Ref_DW.UnitDelay_DSTATE = THA_SmVc_Ref_B.IeTHA_e_THARmpUpDwnSpd;

    /* Update for UnitDelay: '<S1>/UnitDelay1' */
    THA_SmVc_Ref_DW.UnitDelay1_DSTATE = *rty_IeTHA_e_THASteerTrqReq;
  } else {
    if (THA_SmVc_Ref_DW.THA_SmVc_Enabled_MODE) {
      /* Disable for ModelReference: '<S1>/THA_VC_Ref' */
      THA_VC_Ref_Disable(&THA_SmVc_Ref_B.IeTHA_e_THARmpUpDwnSpd,
                         &THA_SmVc_Ref_B.MeTHA_deg_RoadWhlAng);

      /* Disable for Outport: '<S1>/IeTHA_e_THAState' */
      *rty_IeTHA_e_THAState = TeTHA_e_THAState_Initial;

      /* Disable for Outport: '<S1>/IeTHA_e_THASpdLimReq' */
      *rty_IeTHA_e_THASpdLimReq = TeTHA_e_THASpdLimReq_No_Request;

      /* Disable for Outport: '<S1>/IeTHA_e_PamVol' */
      *rty_IeTHA_e_PamVol = TeTHA_e_PamVol_None;

      /* Disable for Outport: '<S1>/IeTHA_b_ChimeActvLhf' */
      *rty_IeTHA_b_ChimeActvLhf = false;

      /* Disable for Outport: '<S1>/IeTHA_b_ChimeActvRhf' */
      *rty_IeTHA_b_ChimeActvRhf = false;

      /* Disable for Outport: '<S1>/IeTHA_b_ChimeActvLhr' */
      *rty_IeTHA_b_ChimeActvLhr = false;

      /* Disable for Outport: '<S1>/IeTHA_b_ChimeActvRhr' */
      *rty_IeTHA_b_ChimeActvRhr = false;

      /* Disable for Outport: '<S1>/IeTHA_e_PamChimeTyp' */
      *rty_IeTHA_e_PamChimeTyp = TeTHA_e_PamChimeTyp_None;

      /* Disable for Outport: '<S1>/IeTHA_e_PamChimeRepRateSts' */
      *rty_IeTHA_e_PamChimeRepRateSts =
        TeTHA_e_PamChimeRepRateSts_Continuous_0_Hz;

      /* Disable for Outport: '<S1>/IeTHA_e_THASteerTrqReq' */
      *rty_IeTHA_e_THASteerTrqReq = TeTHA_e_THASteerTrqReq_False;

      /* Disable for Outport: '<S1>/IeTHA_e_THARmpUpDwnSpd' */
      *rty_IeTHA_e_THARmpUpDwnSpd = TeTHA_e_THARmpUpDwnSpd_No_Request;

      /* Disable for Outport: '<S1>/IeTHA_M_THASteerTrqInfo' */
      *rty_IeTHA_M_THASteerTrqInfo = 0.0F;

      /* Disable for Outport: '<S1>/IeTHA_e_EPBReq' */
      *rty_IeTHA_e_EPBReq = TeTHA_e_EPBReq_No_Request;

      /* Disable for Outport: '<S1>/IeTHA_pct_THAStrDamp' */
      *rty_IeTHA_pct_THAStrDamp = 0.0F;

      /* Disable for Outport: '<S1>/MeTHA_e_THAStateInfo' */
      *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Off;

      /* Disable for Outport: '<S1>/MeTHA_e_ScreenRequest' */
      *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_Default;

      /* Disable for Outport: '<S1>/MeTHA_b_EnblRearParkAsstTrg' */
      *rty_MeTHA_b_EnblRearParkAsstTrg = false;

      /* Disable for Outport: '<S1>/MeTHA_e_RearBrkSupprInfo' */
      *rty_MeTHA_e_RearBrkSupprInfo = TeTHA_e_RearBrkSupprInfo_Invalid;

      /* Disable for Outport: '<S1>/MeTHA_b_UsrHitchCnfm' */
      *rty_MeTHA_b_UsrHitchCnfm = false;

      /* Disable for Outport: '<S1>/MeTHA_b_UsrCplrSelCnfm' */
      *rty_MeTHA_b_UsrCplrSelCnfm = false;

      /* Disable for Outport: '<S1>/MeTHA_deg_RoadWhlAng' */
      *rty_MeTHA_deg_RoadWhlAng = 0.0F;
      THA_SmVc_Ref_DW.THA_SmVc_Enabled_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/THA_SmVc_Enabled' */
}

/* Model initialize function */
void THA_SmVc_Ref_initialize(void)
{
  /* Model Initialize function for ModelReference Block: '<S1>/THA_SM_Ref' */
  THA_SM_Ref_initialize();

  /* Model Initialize function for ModelReference Block: '<S1>/THA_VC_Ref' */
  THA_VC_Ref_initialize();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
