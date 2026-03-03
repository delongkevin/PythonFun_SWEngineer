/*
 * File: THA_SM_Ref.h
 *
 * Code generated for Simulink model 'THA_SM_Ref'.
 *
 * Model version                  : 1.1861
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Aug  7 17:42:07 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_THA_SM_Ref_h_
#define RTW_HEADER_THA_SM_Ref_h_
#include <math.h>
#ifndef THA_SM_Ref_COMMON_INCLUDES_
# define THA_SM_Ref_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* THA_SM_Ref_COMMON_INCLUDES_ */

#include "THA_SM_Ref_types.h"

/* Includes for objects with custom storage classes. */
#include "THA_CalibParams.h"

/* Block states (default storage) for system '<S157>/Chart2' */
#ifndef THA_SM_Ref_MDLREF_HIDE_CHILD_

typedef struct {
  uint32_T temporalCounter_i1;         /* '<S157>/Chart2' */
  uint8_T is_active_c12_THA_SM_Ref;    /* '<S157>/Chart2' */
  uint8_T is_c12_THA_SM_Ref;           /* '<S157>/Chart2' */
} DW_Chart2_THA_SM_Ref_T;

#endif                                 /*THA_SM_Ref_MDLREF_HIDE_CHILD_*/

/* Block signals for model 'THA_SM_Ref' */
#ifndef THA_SM_Ref_MDLREF_HIDE_CHILD_

typedef struct {
  TbTHASmVc_InputVrntTunParam_t MbTHASmVc_InputsFromVrntTunParam;/* '<S2>/SignalCopy58' */
  uint32_T UnitDelay;                  /* '<S16>/UnitDelay' */
  uint32_T Switch;                     /* '<S16>/Switch' */
  uint32_T Divide;                     /* '<S16>/Divide' */
  uint32_T Add;                        /* '<S16>/Add' */
  uint32_T Max;                        /* '<S16>/Max' */
  real32_T Switch_kz4h;                /* '<S99>/Switch' */
  real32_T Saturation;                 /* '<S99>/Saturation' */
  real32_T IeVBII_kph_VehSpeedVSOSig;  /* '<S2>/SignalCopy14' */
  real32_T Switch1;                    /* '<S99>/Switch1' */
  real32_T MeTHA_deg_CplrAngFiltered;  /* '<S99>/Switch6' */
  real32_T Abs;                        /* '<S6>/Abs' */
  real32_T MinMax;                     /* '<S150>/MinMax' */
  real32_T MinMax_nhme;                /* '<S44>/MinMax' */
  real32_T MinMax_owtc;                /* '<S43>/MinMax' */
  real32_T MinMax_doph;                /* '<S22>/MinMax' */
  real32_T MinMax_pkc0;                /* '<S36>/MinMax' */
  real32_T MinMax_mgiu;                /* '<S117>/MinMax' */
  real32_T MinMax_mfsu;                /* '<S116>/MinMax' */
  real32_T MinMax_bt4j;                /* '<S126>/MinMax' */
  real32_T MinMax_aayr;                /* '<S96>/MinMax' */
  real32_T Switch2;                    /* '<S99>/Switch2' */
  real32_T Switch3;                    /* '<S99>/Switch3' */
  real32_T Max1;                       /* '<S16>/Max1' */
  real32_T Sum;                        /* '<S96>/Sum' */
  real32_T Sum_ndvb;                   /* '<S117>/Sum' */
  real32_T Sum_njfy;                   /* '<S22>/Sum' */
  real32_T Sum_jetc;                   /* '<S126>/Sum' */
  real32_T Sum_jrtb;                   /* '<S116>/Sum' */
  real32_T Switch3_ajqq;               /* '<S43>/Switch3' */
  real32_T Sum1;                       /* '<S150>/Sum1' */
  real32_T Gain;                       /* '<S43>/Gain' */
  real32_T Switch3_pas4;               /* '<S96>/Switch3' */
  real32_T Sum_oetd;                   /* '<S36>/Sum' */
  int32_T MeTHA_px_HitchCplrPixDiffLongFiltered;/* '<S99>/Switch4' */
  int32_T MeTHA_px_HitchCplrPixDiffLatFiltered;/* '<S99>/Switch5' */
  int32_T Abs_cit4;                    /* '<S74>/Abs' */
  int32_T UnitDelay_esis;              /* '<S9>/Unit Delay' */
  int32_T Switch1_hemj;                /* '<S9>/Switch1' */
  int32_T UnitDelay_i52v;              /* '<S18>/Unit Delay' */
  TeVBII_e_WhlSpnSts IeVBII_e_LhrWhlSpnSts;/* '<S2>/SignalCopy19' */
  TeVBII_e_WhlSpnSts IeVBII_e_RhrWhlSpnSts;/* '<S2>/SignalCopy30' */
  TeVBII_e_VehStandStillSts IeVBII_e_VehStandStillSts;/* '<S2>/SignalCopy45' */
  TeVBII_e_VehEPBSts IeVBII_e_VehEPBSts;/* '<S2>/SignalCopy50' */
  TeVBII_e_TrlrPrsntSts IeVBII_e_TrlrPrsntSts;/* '<S2>/SignalCopy17' */
  TeVBII_e_TrailerConnectionSts TeVBII_e_TrailerConnectionSts_jp0t;/* '<S2>/SignalCopy16' */
  TeVBII_e_TchScrSts IeVBII_e_TchScrSts;/* '<S2>/SignalCopy59' */
  TeVBII_e_TchScrSts UnitDelay2;       /* '<S17>/Unit Delay2' */
  TeVBII_e_THASteerTouchStatus IeVBII_e_THASteerTouchStatus;/* '<S2>/SignalCopy44' */
  TeVBII_e_LwsAngleType IeVBII_e_LwsAngTyp;/* '<S2>/SignalCopy35' */
  TeVBII_e_GearEngagedForDsply IeVBII_e_GearEngagedForDsply;/* '<S2>/SignalCopy46' */
  TeVBII_e_GearEngagedForDsply UnitDelay1;/* '<S17>/Unit Delay1' */
  TeVBII_e_EssEngState IeVBII_e_EssEngState;/* '<S2>/SignalCopy34' */
  TeVBII_e_EpsTHASteerTrqResp IeVBII_e_EpsTHASteerTrqResp;/* '<S2>/SignalCopy43' */
  TeVBII_e_EpsTHADrvTrqOvrd IeVBII_e_EpsTHADrvTrqOvrd;/* '<S2>/SignalCopy47' */
  TeVBII_e_EngineSts IeVBII_e_EngineSts;/* '<S2>/SignalCopy33' */
  TeVBII_e_EcmTHAResp IeVBII_e_EcmTHAResp;/* '<S2>/SignalCopy42' */
  TeVBII_e_CmdIgnSts IeVBII_e_CmdIgnSts;/* '<S2>/SignalCopy15' */
  TeVBII_e_BsmTHABrkResp IeVBII_e_BsmTHABrkResp;/* '<S2>/SignalCopy38' */
  TeTRSC_e_TRSCSts IeTRSC_e_TRSCSts;   /* '<S2>/SignalCopy55' */
  TeTHA_e_THAStateInfo UnitDelay1_kl5n;/* '<S9>/Unit Delay1' */
  TeTHA_e_ScreenRequest MeTHA_e_ScreenRequestPrev;/* '<S1>/UnitDelay1' */
  TeTHA_e_RearBrkSupprInfo Switch1_oaul;/* '<S8>/Switch1' */
  TeTHA_e_HitchDetctStatus MeTHA_e_HitchDetStsFiltered;/* '<S99>/HitchDetStsHyst' */
  TeTHA_e_CplrDetctStatus MeTHA_e_CplrDetStsFiltered;/* '<S99>/CplrDetStsHyst' */
  TeSVS_e_DispView2 IeSVS_e_DispView2; /* '<S2>/SignalCopy63' */
  TeAP_e_FrntRearParkSts IeAP_e_FrntRearParkSts;/* '<S2>/SignalCopy54' */
  TeAP_e_AutoParkStatus IeAP_e_AutoParkStatus;/* '<S2>/SignalCopy12' */
  uint8_T IeVBII_cnt_RhrFastPlsCntr;   /* '<S2>/SignalCopy24' */
  boolean_T LogicalOperator;           /* '<S99>/Logical Operator' */
  boolean_T LogicalOperator_efqh;      /* '<S7>/Logical Operator' */
  boolean_T MeTHA_b_IgnitionRunStart;  /* '<S92>/LogicalOperator' */
  boolean_T IeVBII_b_DrvDoorSts;       /* '<S2>/SignalCopy36' */
  boolean_T IeVBII_b_TrnkStatus;       /* '<S2>/SignalCopy37' */
  boolean_T MeTHA_b_EnabledSelectionTrns;/* '<S89>/LogicalOperator' */
  boolean_T MeTHA_b_EngagedDeltaTrns;  /* '<S90>/RelationalOperator1' */
  boolean_T MeTHA_b_EngagedInquiryTrns;/* '<S90>/Unit Delay' */
  boolean_T RelationalOperator;        /* '<S96>/RelationalOperator' */
  boolean_T MeTHA_b_CompleteTrns;      /* '<S88>/LogicalOperator1' */
  boolean_T MeTHA_b_THAEnggdNotSupp;   /* '<S110>/LogicalOperator' */
  boolean_T LogicalOperator1;          /* '<S109>/LogicalOperator1' */
  boolean_T UnitDelay_ewqi;            /* '<S127>/UnitDelay' */
  boolean_T Switch_a0h1;               /* '<S127>/Switch' */
  boolean_T MeTHA_b_AbortStrTrqSpdLimReq;/* '<S107>/LogicalOperator2' */
  boolean_T RelationalOperator_ibvb;   /* '<S36>/RelationalOperator' */
  boolean_T RelationalOperator1;       /* '<S3>/RelationalOperator1' */
  boolean_T MeTHA_b_CplrAngFound;      /* '<S2>/SignalCopy41' */
  boolean_T MeTHA_b_EngageRejectReq;   /* '<S74>/Logical Operator' */
  boolean_T LogicalOperator5;          /* '<S8>/LogicalOperator5' */
  boolean_T RelationalOperator_h4jm;   /* '<S150>/RelationalOperator' */
  boolean_T RelationalOperator_g1ma;   /* '<S43>/RelationalOperator' */
  boolean_T LogicalOperator5_gtpq;     /* '<S18>/LogicalOperator5' */
  boolean_T RelationalOperator3;       /* '<S90>/RelationalOperator3' */
  boolean_T switchOut;                 /* '<S159>/Chart2' */
  boolean_T switchOut_lh0v;            /* '<S158>/Chart2' */
  boolean_T switchOut_efwl;            /* '<S157>/Chart2' */
  boolean_T LogicalOperator5_flx5;     /* '<S109>/LogicalOperator5' */
  boolean_T Switch1_ggdu;              /* '<S127>/Switch1' */
  boolean_T LogicalOperator_fazu;      /* '<S127>/LogicalOperator' */
  boolean_T MeTHA_b_EngageRejectReq_al0i;/* '<S74>/LateralOffsetCheck' */
  boolean_T switchOut_gy5o;            /* '<S35>/Chart2' */
  boolean_T RelationalOperator5;       /* '<S99>/RelationalOperator5' */
  boolean_T RelationalOperator7;       /* '<S9>/RelationalOperator7' */
  boolean_T RelationalOperator6;       /* '<S9>/RelationalOperator6' */
  boolean_T LogicalOperator2;          /* '<S9>/Logical Operator2' */
  boolean_T LogicalOperator3;          /* '<S8>/LogicalOperator3' */
  boolean_T LogicalOperator2_ehda;     /* '<S17>/Logical Operator2' */
  boolean_T LogicalOperator6;          /* '<S108>/LogicalOperator6' */
  boolean_T RelationalOperator4;       /* '<S75>/RelationalOperator4' */
  boolean_T LogicalOperator3_edxj;     /* '<S88>/LogicalOperator3' */
  boolean_T LogicalOperator2_m1ul;     /* '<S109>/LogicalOperator2' */
  boolean_T LogicalOperator2_a3nq;     /* '<S5>/Logical Operator2' */
  boolean_T RelationalOperator2;       /* '<S75>/RelationalOperator2' */
  boolean_T RelationalOperator19;      /* '<S18>/RelationalOperator19' */
  boolean_T LogicalOperator7;          /* '<S19>/LogicalOperator7' */
  boolean_T RelationalOperator3_lwkl;  /* '<S19>/RelationalOperator3' */
  boolean_T LogicalOperator2_npvg;     /* '<S18>/Logical Operator2' */
  boolean_T RelationalOperator3_anin;  /* '<S75>/RelationalOperator3' */
  boolean_T RelationalOperator1_ibmm;  /* '<S18>/RelationalOperator1' */
  boolean_T RelationalOperator2_hq3h;  /* '<S18>/RelationalOperator2' */
  boolean_T LogicalOperator4;          /* '<S18>/LogicalOperator4' */
  boolean_T RelationalOperator7_jqco;  /* '<S18>/RelationalOperator7' */
} B_THA_SM_Ref_caua_T;

#endif                                 /*THA_SM_Ref_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'THA_SM_Ref' */
#ifndef THA_SM_Ref_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T UnitDelay3_DSTATE;          /* '<S96>/UnitDelay3' */
  real32_T UnitDelay3_DSTATE_bz1l;     /* '<S126>/UnitDelay3' */
  real32_T UnitDelay3_DSTATE_ipup;     /* '<S116>/UnitDelay3' */
  real32_T UnitDelay3_DSTATE_hyrp;     /* '<S117>/UnitDelay3' */
  real32_T UnitDelay_DSTATE;           /* '<S17>/Unit Delay' */
  real32_T UnitDelay3_DSTATE_fkls;     /* '<S36>/UnitDelay3' */
  real32_T UnitDelay3_DSTATE_gjgb;     /* '<S22>/UnitDelay3' */
  real32_T UnitDelay3_DSTATE_dasz;     /* '<S44>/UnitDelay3' */
  real32_T UnitDelay2_DSTATE;          /* '<S99>/Unit Delay2' */
  real32_T UnitDelay3_DSTATE_mxty;     /* '<S150>/UnitDelay3' */
  real32_T UnitDelay3_DSTATE_nlty;     /* '<S43>/UnitDelay3' */
  int32_T UnitDelay_DSTATE_jxgs;       /* '<S99>/Unit Delay' */
  int32_T UnitDelay1_DSTATE;           /* '<S99>/Unit Delay1' */
  int32_T UnitDelay_DSTATE_coxe;       /* '<S9>/Unit Delay' */
  int32_T UnitDelay_DSTATE_bhgc;       /* '<S18>/Unit Delay' */
  uint32_T UnitDelay_DSTATE_hgbb;      /* '<S16>/UnitDelay' */
  TeTHA_e_ScreenRequest UnitDelay1_DSTATE_lybn;/* '<S1>/UnitDelay1' */
  TeVBII_e_TchScrSts UnitDelay2_DSTATE_kwqb;/* '<S17>/Unit Delay2' */
  TeVBII_e_GearEngagedForDsply UnitDelay1_DSTATE_cn3d;/* '<S17>/Unit Delay1' */
  TeTHA_e_THAStateInfo UnitDelay2_DSTATE_co0c;/* '<S1>/UnitDelay2' */
  TeTHA_e_THAStateInfo UnitDelay1_DSTATE_ggez;/* '<S9>/Unit Delay1' */
  real32_T time_count;                 /* '<S99>/HitchDetStsHyst' */
  real32_T time_count_kisl;            /* '<S99>/CplrDetStsHyst' */
  real32_T cplr_det_wait;              /* '<S6>/THA_HMI_Logic_Flow' */
  real32_T hitch_det_wait;             /* '<S6>/THA_HMI_Logic_Flow' */
  uint32_T temporalCounter_i1;         /* '<S7>/THA_MainStateMachine' */
  uint32_T temporalCounter_i1_gafy;    /* '<S6>/THA_HMI_Logic_Flow' */
  uint32_T temporalCounter_i1_bsnb;    /* '<S35>/Chart2' */
  uint32_T Add_DWORK1;                 /* '<S16>/Add' */
  TeTHA_e_HitchDetctStatus local_status;/* '<S99>/HitchDetStsHyst' */
  TeTHA_e_CplrDetctStatus local_status_nrep;/* '<S99>/CplrDetStsHyst' */
  boolean_T UnitDelay_DSTATE_fbjp;     /* '<S90>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_d5cr;     /* '<S109>/UnitDelay' */
  boolean_T UnitDelay_DSTATE_kgyy;     /* '<S127>/UnitDelay' */
  boolean_T UnitDelay1_DSTATE_fw4h;    /* '<S16>/UnitDelay1' */
  boolean_T UnitDelay1_DSTATE_gih2;    /* '<S18>/Unit Delay1' */
  uint8_T is_active_c5_THA_SM_Ref;     /* '<S7>/THA_MainStateMachine' */
  uint8_T is_c5_THA_SM_Ref;            /* '<S7>/THA_MainStateMachine' */
  uint8_T is_THA_Activ_Process;        /* '<S7>/THA_MainStateMachine' */
  uint8_T is_Enabled;                  /* '<S7>/THA_MainStateMachine' */
  uint8_T is_Engaged_Main;             /* '<S7>/THA_MainStateMachine' */
  uint8_T is_active_c2_THA_SM_Ref;     /* '<S99>/HitchDetStsHyst' */
  uint8_T is_c2_THA_SM_Ref;            /* '<S99>/HitchDetStsHyst' */
  uint8_T is_active_c3_THA_SM_Ref;     /* '<S99>/CplrDetStsHyst' */
  uint8_T is_c3_THA_SM_Ref;            /* '<S99>/CplrDetStsHyst' */
  uint8_T is_active_c1_THA_SM_Ref;     /* '<S6>/THA_HMI_Logic_Flow' */
  uint8_T is_c1_THA_SM_Ref;            /* '<S6>/THA_HMI_Logic_Flow' */
  uint8_T is_THA_Normal;               /* '<S6>/THA_HMI_Logic_Flow' */
  uint8_T is_Init;                     /* '<S6>/THA_HMI_Logic_Flow' */
  uint8_T is_Enabled_dfuo;             /* '<S6>/THA_HMI_Logic_Flow' */
  uint8_T is_CplrSelCnfrm;             /* '<S6>/THA_HMI_Logic_Flow' */
  uint8_T is_Engaged;                  /* '<S6>/THA_HMI_Logic_Flow' */
  uint8_T is_active_c9_THA_SM_Ref;     /* '<S35>/Chart2' */
  uint8_T is_c9_THA_SM_Ref;            /* '<S35>/Chart2' */
  DW_Chart2_THA_SM_Ref_T sf_Chart2_g3d0;/* '<S159>/Chart2' */
  DW_Chart2_THA_SM_Ref_T sf_Chart2_kfbv;/* '<S158>/Chart2' */
  DW_Chart2_THA_SM_Ref_T sf_Chart2_gkm0;/* '<S157>/Chart2' */
} DW_THA_SM_Ref_fwu4_T;

#endif                                 /*THA_SM_Ref_MDLREF_HIDE_CHILD_*/

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T MeTHA_deg_CplrAng;     /* '<S2>/SignalCopy2'
                                        * Coupler angle.
                                        */
extern int32_T MeTHA_px_HitchCplrPixDiffLong;/* '<S2>/SignalCopy3'
                                              * Longitudinal Pixel Y difference from hitch to coupler.
                                              */
extern int32_T MeTHA_px_HitchCplrPixDiffLat;/* '<S2>/SignalCopy4'
                                             * Longitudinal Pixel X difference from hitch to coupler.
                                             */
extern TeTHA_e_ScreenRequest MeSVS_e_THAScrResp;/* '<S2>/SignalCopy7'
                                                 * THA screen request acknowledgement from HMI.
                                                 */
extern TeTHA_e_HitchDetctStatus MeTHA_e_HitchDetctStatus;/* '<S2>/SignalCopy'
                                                          * Hitch detection status.
                                                            0 - Not_Valid
                                                            1 - Not_Detected
                                                            2 - Detected
                                                          */
extern TeTHA_e_CplrDetctStatus MeTHA_e_CplrDetctStatus;/* '<S2>/SignalCopy1'
                                                        * Coupler detection status.
                                                          0 - Not valid
                                                          1 - Not_Detected
                                                          2 - Detected
                                                        */
extern boolean_T MeSVS_b_THASftBtnPrsdStsToTHA;/* '<S2>/SignalCopy5'
                                                * THA soft button pressed status.
                                                */
extern boolean_T MeSVS_b_ImgDefeatReqSts;/* '<S2>/SignalCopy8'
                                          * Cancel Button
                                          */
extern boolean_T MeSVS_b_IsConfirmBtnPrsd;/* '<S2>/SignalCopy6'
                                           * Confirm button pressed.
                                           */
extern boolean_T MeTHA_b_FidDisabled;  /* '<S2>/SignalCopy49' */
extern boolean_T MeTHA_b_FidCamCalAbort;/* '<S2>/SignalCopy53' */
extern boolean_T MePRX_b_CanNod63;     /* '<S2>/SignalCopy51'
                                        * PROXI parameter CAN node 63 (TTM).
                                        */
extern boolean_T MePRX_b_CanNod95;     /* '<S2>/SignalCopy52'
                                        * PROXI parameter CAN node 95 (ITBM/ITCM).
                                        */
extern boolean_T MeTHA_b_ActivTrns;    /* '<S93>/LogicalOperator9'
                                        * THA activation condition transition model internal signal.
                                        */
extern boolean_T MeTHA_b_AbortSteerTrqReq;/* '<S109>/LogicalOperator6'
                                           * THA abort request due to EPS, model internal signal.
                                           */
extern boolean_T MeTHA_b_AbortSpdLimReq;/* '<S108>/LogicalOperator4'
                                         * THA abort request due to BSM or ECM, model internal signal.
                                         */
extern boolean_T MeTHA_b_AbortCndnFaulted;/* '<S19>/LogicalOperator12'
                                           * THA abort condition faulted model internal signal.
                                           */
extern boolean_T MeTHA_b_FidDLDAbort;  /* '<S2>/SignalCopy40' */
extern boolean_T MeTHA_b_FeatureOverride;/* '<S17>/Logical Operator3'
                                          * THA abort condition if any other Driver Assist feature takes over actuation.
                                          */
extern boolean_T MeTHA_b_AbortCndnEnabled;/* '<S5>/Logical Operator'
                                           * THA abort condition Enabled model internal signal.
                                           */
extern boolean_T MeTHA_b_OverSpeedAbort;/* '<S44>/RelationalOperator'
                                         * THA abort condition if vehicle speed exceeds beyond specified limit.
                                         */
extern boolean_T MeTHA_b_AbortCndnEngaged;/* '<S5>/Logical Operator1'
                                           * THA abort condition Engaged model internal signal.
                                           */
extern boolean_T MeSVS_b_ViewZoomSts;  /* '<S2>/SignalCopy9'
                                        * HMI view zoom status.
                                          0 - Normal view
                                          1- Zoomed view
                                        */
extern boolean_T MeSVS_b_THAScrTchSts; /* '<S2>/SignalCopy11'
                                        * THA screen touch status.
                                        */
extern boolean_T MeSVS_b_THAAbortReq;  /* '<S2>/SignalCopy39'
                                        * THA feature abort request from HMI.
                                        */
extern boolean_T MeTHA_b_THACompleteHMITrig;/* '<S75>/LogicalOperator'
                                             * THA complete HMI trigger model internal signal.
                                             */
extern boolean_T MePRX_b_ParkWithStop; /* '<S2>/SignalCopy48'
                                        * Park with stop.
                                        */
extern boolean_T MeSVS_b_THAMnvrStartBtnPrsd;/* '<S2>/SignalCopy10'
                                              * THA start manuever button pressed status.
                                              */
extern void THA_SM_Ref_Init(void);
extern void THA_SM_Ref_Reset(TeTHA_e_THAState *rty_IeTHA_e_THAState,
  TeTHA_e_THAStateInfo *rty_MeTHA_e_THAStateInfo, TeTHA_e_ScreenRequest
  *rty_MeTHA_e_ScreenRequest, boolean_T *rty_MeTHA_b_UsrHitchCnfm, boolean_T
  *rty_MeTHA_b_UsrCplrSelCnfm);
extern void THA_SM_Ref_Start(boolean_T *rty_IeTHA_b_ChimeActvLhr, boolean_T
  *rty_IeTHA_b_ChimeActvRhr, TeTHA_e_PamChimeRepRateSts
  *rty_IeTHA_e_PamChimeRepRateSts);
extern void THA_SM_Ref(const TbTHASmVc_InputFromThaDet_t
  *rtu_MbTHA_ThaDetOutData, const TbTHASmVc_InputFromHmiSvs_t
  *rtu_MbTHA_HmiSvsOutData, const TbTHASmVc_InputFromVehInp_t
  *rtu_MbTHA_VehInpOutData, const TbTHASmVc_InputFromProxiMgr_t
  *rtu_MbTHA_ProxiMgrOutData, const TbTHASmVc_InputFromDegMgr_t
  *rtu_MbTHA_DegradMgrOutData, const TbTHASmVc_InputFromApSmPa_t
  *rtu_MbTHA_ApSmOutData, const TbTHASmVc_InputFromTRSC_t
  *rtu_MbTHA_TrscSmVcOutData, const TbTHASmVc_InputVrntTunParam_t
  *rtu_MbTHA_VrntTunParamOutData, const TeTHA_e_THARmpUpDwnSpd
  *rtu_IeTHA_e_THARmpUpDwnSpdPrev, const TeTHA_e_THASteerTrqReq
  *rtu_IeTHA_e_THASteerTrqReqPrev, TeTHA_e_THAState *rty_IeTHA_e_THAState,
  TeTHA_e_THASpdLimReq *rty_IeTHA_e_THASpdLimReq, TeTHA_e_PamVol
  *rty_IeTHA_e_PamVol, boolean_T *rty_IeTHA_b_ChimeActvLhf, boolean_T
  *rty_IeTHA_b_ChimeActvRhf, boolean_T *rty_IeTHA_b_ChimeActvLhr, boolean_T
  *rty_IeTHA_b_ChimeActvRhr, TeTHA_e_PamChimeTyp *rty_IeTHA_e_PamChimeTyp,
  TeTHA_e_PamChimeRepRateSts *rty_IeTHA_e_PamChimeRepRateSts,
  TeTHA_e_THASteerTrqReq *rty_MeTHA_e_THASteerTrqReq, TeTHA_e_EPBReq
  *rty_IeTHA_e_EPBReq, TeTHA_e_THAStateInfo *rty_MeTHA_e_THAStateInfo,
  TeTHA_e_ScreenRequest *rty_MeTHA_e_ScreenRequest, boolean_T
  *rty_MeTHA_b_EnblRearParkAsstTrg, TeTHA_e_RearBrkSupprInfo
  *rty_MeTHA_e_RearBrkSupprInfo, boolean_T *rty_MeTHA_b_UsrHitchCnfm, boolean_T *
  rty_MeTHA_b_UsrCplrSelCnfm, boolean_T *rty_MeTHA_b_TrlrCplrStatus, boolean_T
  *rty_MeTHA_b_THAAbortStatus, boolean_T *rty_MeTHA_b_UsrInputTimeOut, boolean_T
  *rty_MeTHA_b_ViewZoomSts, boolean_T *rty_MeTHA_b_CamOccluLoLi, int32_T
  *rty_MeTHA_px_HitchCplrPixDiffLongAtStrt);

/* Model reference registration function */
extern void THA_SM_Ref_initialize(void);

#ifndef THA_SM_Ref_MDLREF_HIDE_CHILD_

extern void THA_SM_Ref_Chart2_Init(boolean_T *rty_switchOut);
extern void THA_SM_Ref_Chart2_Reset(boolean_T *rty_switchOut,
  DW_Chart2_THA_SM_Ref_T *localDW);
extern void THA_SM_Ref_Chart2(const boolean_T *rtu_Trigger, real32_T
  rtu_KeTHA_s_HmiFaultPopUpDur, boolean_T *rty_switchOut, DW_Chart2_THA_SM_Ref_T
  *localDW);

#endif                                 /*THA_SM_Ref_MDLREF_HIDE_CHILD_*/

#ifndef THA_SM_Ref_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_THA_SM_Ref_caua_T THA_SM_Ref_B;

/* Block states (default storage) */
extern DW_THA_SM_Ref_fwu4_T THA_SM_Ref_DW;

#endif                                 /*THA_SM_Ref_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'THA_SM_Ref'
 * '<S1>'   : 'THA_SM_Ref/THA_SM_Controller'
 * '<S2>'   : 'THA_SM_Ref/THA_SM_InputProcessing'
 * '<S3>'   : 'THA_SM_Ref/THA_SM_Controller/THA_Chime_Manager'
 * '<S4>'   : 'THA_SM_Ref/THA_SM_Controller/THA_DID_Gateway'
 * '<S5>'   : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager'
 * '<S6>'   : 'THA_SM_Ref/THA_SM_Controller/THA_HMILogicFlow_Manager'
 * '<S7>'   : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager'
 * '<S8>'   : 'THA_SM_Ref/THA_SM_Controller/THA_RearParkAssist_Manager'
 * '<S9>'   : 'THA_SM_Ref/THA_SM_Controller/THA_Status_Manager'
 * '<S10>'  : 'THA_SM_Ref/THA_SM_Controller/THA_Chime_Manager/EnumeratedConstant1'
 * '<S11>'  : 'THA_SM_Ref/THA_SM_Controller/THA_Chime_Manager/EnumeratedConstant2'
 * '<S12>'  : 'THA_SM_Ref/THA_SM_Controller/THA_Chime_Manager/EnumeratedConstant3'
 * '<S13>'  : 'THA_SM_Ref/THA_SM_Controller/THA_Chime_Manager/EnumeratedConstant4'
 * '<S14>'  : 'THA_SM_Ref/THA_SM_Controller/THA_Chime_Manager/EnumeratedConstant5'
 * '<S15>'  : 'THA_SM_Ref/THA_SM_Controller/THA_Chime_Manager/EnumeratedConstant6'
 * '<S16>'  : 'THA_SM_Ref/THA_SM_Controller/THA_Chime_Manager/RisingEdgeTimer'
 * '<S17>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled'
 * '<S18>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Engaged'
 * '<S19>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted'
 * '<S20>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/EnumeratedConstant1'
 * '<S21>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/EnumeratedConstant2'
 * '<S22>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/MagnaTimer'
 * '<S23>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled/EnumeratedConstant1'
 * '<S24>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled/EnumeratedConstant10'
 * '<S25>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled/EnumeratedConstant11'
 * '<S26>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled/EnumeratedConstant2'
 * '<S27>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled/EnumeratedConstant3'
 * '<S28>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled/EnumeratedConstant4'
 * '<S29>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled/EnumeratedConstant5'
 * '<S30>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled/EnumeratedConstant6'
 * '<S31>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled/EnumeratedConstant7'
 * '<S32>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled/EnumeratedConstant8'
 * '<S33>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled/EnumeratedConstant9'
 * '<S34>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled/FloatComparison4'
 * '<S35>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled/Hold_2sec'
 * '<S36>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled/MagnaTimer'
 * '<S37>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Enabled/Hold_2sec/Chart2'
 * '<S38>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Engaged/EnumeratedConstant1'
 * '<S39>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Engaged/EnumeratedConstant11'
 * '<S40>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Engaged/EnumeratedConstant18'
 * '<S41>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Engaged/EnumeratedConstant21'
 * '<S42>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Engaged/FloatComparison1'
 * '<S43>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Engaged/MagnaTimer'
 * '<S44>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Engaged/MagnaTimer1'
 * '<S45>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant1'
 * '<S46>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant10'
 * '<S47>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant11'
 * '<S48>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant12'
 * '<S49>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant15'
 * '<S50>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant16'
 * '<S51>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant17'
 * '<S52>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant18'
 * '<S53>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant19'
 * '<S54>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant2'
 * '<S55>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant21'
 * '<S56>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant3'
 * '<S57>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant4'
 * '<S58>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant5'
 * '<S59>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant6'
 * '<S60>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant7'
 * '<S61>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant8'
 * '<S62>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/EnumeratedConstant9'
 * '<S63>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/FloatComparison1'
 * '<S64>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/FloatComparison11'
 * '<S65>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/FloatComparison14'
 * '<S66>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/FloatComparison15'
 * '<S67>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/FloatComparison16'
 * '<S68>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/FloatComparison2'
 * '<S69>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/FloatComparison3'
 * '<S70>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/FloatComparison4'
 * '<S71>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/FloatComparison5'
 * '<S72>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/FloatComparison7'
 * '<S73>'  : 'THA_SM_Ref/THA_SM_Controller/THA_FaultCheck_Manager/Abort_Condition_THA_Faulted/FloatComparison9'
 * '<S74>'  : 'THA_SM_Ref/THA_SM_Controller/THA_HMILogicFlow_Manager/InitialVehiclePositionCheck'
 * '<S75>'  : 'THA_SM_Ref/THA_SM_Controller/THA_HMILogicFlow_Manager/THAComplete_HMITriggerCheck'
 * '<S76>'  : 'THA_SM_Ref/THA_SM_Controller/THA_HMILogicFlow_Manager/THA_HMI_Logic_Flow'
 * '<S77>'  : 'THA_SM_Ref/THA_SM_Controller/THA_HMILogicFlow_Manager/InitialVehiclePositionCheck/EnumeratedConstant7'
 * '<S78>'  : 'THA_SM_Ref/THA_SM_Controller/THA_HMILogicFlow_Manager/InitialVehiclePositionCheck/LateralOffsetCheck'
 * '<S79>'  : 'THA_SM_Ref/THA_SM_Controller/THA_HMILogicFlow_Manager/THAComplete_HMITriggerCheck/EnumeratedConstant1'
 * '<S80>'  : 'THA_SM_Ref/THA_SM_Controller/THA_HMILogicFlow_Manager/THAComplete_HMITriggerCheck/EnumeratedConstant2'
 * '<S81>'  : 'THA_SM_Ref/THA_SM_Controller/THA_HMILogicFlow_Manager/THAComplete_HMITriggerCheck/EnumeratedConstant3'
 * '<S82>'  : 'THA_SM_Ref/THA_SM_Controller/THA_HMILogicFlow_Manager/THAComplete_HMITriggerCheck/EnumeratedConstant4'
 * '<S83>'  : 'THA_SM_Ref/THA_SM_Controller/THA_HMILogicFlow_Manager/THAComplete_HMITriggerCheck/EnumeratedConstant5'
 * '<S84>'  : 'THA_SM_Ref/THA_SM_Controller/THA_HMILogicFlow_Manager/THAComplete_HMITriggerCheck/EnumeratedConstant6'
 * '<S85>'  : 'THA_SM_Ref/THA_SM_Controller/THA_HMILogicFlow_Manager/THAComplete_HMITriggerCheck/EnumeratedConstant7'
 * '<S86>'  : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing'
 * '<S87>'  : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THA_MainStateMachine'
 * '<S88>'  : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/CompleteStateCheck'
 * '<S89>'  : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EnabledSelectionCheck'
 * '<S90>'  : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedDeltaInquiryCheck'
 * '<S91>'  : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck'
 * '<S92>'  : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/IgnitionStatusCheck'
 * '<S93>'  : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/THAActivationCheck'
 * '<S94>'  : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/CompleteStateCheck/EnumeratedConstant'
 * '<S95>'  : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/CompleteStateCheck/EnumeratedConstant1'
 * '<S96>'  : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/CompleteStateCheck/MagnaTimer'
 * '<S97>'  : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EnabledSelectionCheck/EnumeratedConstant1'
 * '<S98>'  : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EnabledSelectionCheck/EnumeratedConstant6'
 * '<S99>'  : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedDeltaInquiryCheck/DetectionStatusFilter'
 * '<S100>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedDeltaInquiryCheck/DetectionStatusFilter/CplrDetStsHyst'
 * '<S101>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedDeltaInquiryCheck/DetectionStatusFilter/EnumeratedConstant1'
 * '<S102>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedDeltaInquiryCheck/DetectionStatusFilter/EnumeratedConstant2'
 * '<S103>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedDeltaInquiryCheck/DetectionStatusFilter/EnumeratedConstant3'
 * '<S104>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedDeltaInquiryCheck/DetectionStatusFilter/EnumeratedConstant4'
 * '<S105>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedDeltaInquiryCheck/DetectionStatusFilter/EnumeratedConstant7'
 * '<S106>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedDeltaInquiryCheck/DetectionStatusFilter/HitchDetStsHyst'
 * '<S107>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/AbortReq'
 * '<S108>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/BSM_ECM_SpdLimHandshake'
 * '<S109>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/EPSTrqOvrHandShake'
 * '<S110>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/THAStateEngagedCheck'
 * '<S111>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/BSM_ECM_SpdLimHandshake/EnumeratedConstant'
 * '<S112>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/BSM_ECM_SpdLimHandshake/EnumeratedConstant1'
 * '<S113>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/BSM_ECM_SpdLimHandshake/EnumeratedConstant2'
 * '<S114>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/BSM_ECM_SpdLimHandshake/EnumeratedConstant3'
 * '<S115>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/BSM_ECM_SpdLimHandshake/EnumeratedConstant4'
 * '<S116>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/BSM_ECM_SpdLimHandshake/MagnaTimer1'
 * '<S117>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/BSM_ECM_SpdLimHandshake/MagnaTimer2'
 * '<S118>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/EPSTrqOvrHandShake/EnumeratedConstant1'
 * '<S119>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/EPSTrqOvrHandShake/EnumeratedConstant10'
 * '<S120>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/EPSTrqOvrHandShake/EnumeratedConstant4'
 * '<S121>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/EPSTrqOvrHandShake/EnumeratedConstant5'
 * '<S122>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/EPSTrqOvrHandShake/EnumeratedConstant6'
 * '<S123>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/EPSTrqOvrHandShake/EnumeratedConstant7'
 * '<S124>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/EPSTrqOvrHandShake/EnumeratedConstant8'
 * '<S125>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/EPSTrqOvrHandShake/EnumeratedConstant9'
 * '<S126>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/EPSTrqOvrHandShake/MagnaTimer'
 * '<S127>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/EPSTrqOvrHandShake/SR_FlipFlop'
 * '<S128>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/THAStateEngagedCheck/EnumeratedConstant1'
 * '<S129>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/THAStateEngagedCheck/EnumeratedConstant2'
 * '<S130>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/THAStateEngagedCheck/EnumeratedConstant3'
 * '<S131>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/EngagedHandShakeCheck/THAStateEngagedCheck/EnumeratedConstant4'
 * '<S132>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/IgnitionStatusCheck/EnumeratedConstant1'
 * '<S133>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/IgnitionStatusCheck/EnumeratedConstant6'
 * '<S134>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/THAActivationCheck/EnumeratedConstant'
 * '<S135>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/THAActivationCheck/EnumeratedConstant1'
 * '<S136>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/THAActivationCheck/EnumeratedConstant2'
 * '<S137>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/THAActivationCheck/EnumeratedConstant3'
 * '<S138>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/THAActivationCheck/EnumeratedConstant4'
 * '<S139>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/THAActivationCheck/EnumeratedConstant5'
 * '<S140>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/THAActivationCheck/EnumeratedConstant6'
 * '<S141>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/THAActivationCheck/EnumeratedConstant7'
 * '<S142>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/THAActivationCheck/EnumeratedConstant8'
 * '<S143>' : 'THA_SM_Ref/THA_SM_Controller/THA_MainStateMachine_Manager/THAStates_PreProcessing/THAActivationCheck/EnumeratedConstant9'
 * '<S144>' : 'THA_SM_Ref/THA_SM_Controller/THA_RearParkAssist_Manager/EnumeratedConstant'
 * '<S145>' : 'THA_SM_Ref/THA_SM_Controller/THA_RearParkAssist_Manager/EnumeratedConstant1'
 * '<S146>' : 'THA_SM_Ref/THA_SM_Controller/THA_RearParkAssist_Manager/EnumeratedConstant2'
 * '<S147>' : 'THA_SM_Ref/THA_SM_Controller/THA_RearParkAssist_Manager/EnumeratedConstant3'
 * '<S148>' : 'THA_SM_Ref/THA_SM_Controller/THA_RearParkAssist_Manager/EnumeratedConstant4'
 * '<S149>' : 'THA_SM_Ref/THA_SM_Controller/THA_RearParkAssist_Manager/EnumeratedConstant5'
 * '<S150>' : 'THA_SM_Ref/THA_SM_Controller/THA_RearParkAssist_Manager/MagnaTimer'
 * '<S151>' : 'THA_SM_Ref/THA_SM_Controller/THA_Status_Manager/EnumeratedConstant'
 * '<S152>' : 'THA_SM_Ref/THA_SM_Controller/THA_Status_Manager/EnumeratedConstant1'
 * '<S153>' : 'THA_SM_Ref/THA_SM_Controller/THA_Status_Manager/EnumeratedConstant2'
 * '<S154>' : 'THA_SM_Ref/THA_SM_Controller/THA_Status_Manager/EnumeratedConstant3'
 * '<S155>' : 'THA_SM_Ref/THA_SM_Controller/THA_Status_Manager/EnumeratedConstant4'
 * '<S156>' : 'THA_SM_Ref/THA_SM_Controller/THA_Status_Manager/EnumeratedConstant5'
 * '<S157>' : 'THA_SM_Ref/THA_SM_InputProcessing/Subsystem1'
 * '<S158>' : 'THA_SM_Ref/THA_SM_InputProcessing/Subsystem2'
 * '<S159>' : 'THA_SM_Ref/THA_SM_InputProcessing/Subsystem3'
 * '<S160>' : 'THA_SM_Ref/THA_SM_InputProcessing/Subsystem1/Chart2'
 * '<S161>' : 'THA_SM_Ref/THA_SM_InputProcessing/Subsystem2/Chart2'
 * '<S162>' : 'THA_SM_Ref/THA_SM_InputProcessing/Subsystem3/Chart2'
 */

/*-
 * Requirements for '<Root>': THA_SM_Ref
 */
#endif                                 /* RTW_HEADER_THA_SM_Ref_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
