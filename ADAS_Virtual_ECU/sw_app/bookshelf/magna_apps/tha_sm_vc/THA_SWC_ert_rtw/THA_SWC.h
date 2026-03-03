/*
 * File: THA_SWC.h
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

#ifndef RTW_HEADER_THA_SWC_h_
#define RTW_HEADER_THA_SWC_h_
#include <string.h>
#ifndef THA_SWC_COMMON_INCLUDES_
# define THA_SWC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* THA_SWC_COMMON_INCLUDES_ */

#include "THA_SWC_types.h"
#include "SignalDef.h"

/* Child system includes */
#define THA_SmVc_Ref_MDLREF_HIDE_CHILD_
#include "THA_SmVc_Ref.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
/* Includes for objects with custom storage classes. */
#include "THA_CalibParams.h"
#define DEBUG_PRINTS  0

/* Macros for accessing real-time model data structure */

/* Block signals (default storage) */
typedef struct {
  ME_VehInp_to_IpcSignals_t MbTHA_VehInpOut;/* '<S5>/DataStoreRead2' */
  THA_Calibration_data_MCU2_1_t MbTHA_VrntTunParamOut;/* '<S5>/DataStoreRead9' */
  TbTHASmVc_InputVrntTunParam_t MbTHA_VrntTunParamOutData;/* '<S4>/Switch' */
  TbTHASmVc_InputVrntTunParam_t BusCreator7;/* '<S4>/BusCreator7' */
  TbTHASmVc_InputVrntTunParam_t BusCreator8;/* '<S4>/BusCreator8' */
  TbTHASmVc_InputFromVehInp_t MbTHA_VehInpOutData;/* '<S4>/BusCreator3' */
  JobTHADetOutput_t MbTHA_ThaDetOut;   /* '<S5>/DataStoreRead' */
  TbTHASmVc_FeatureOutputs_t TbTHASmVc_FeatureOutputs_t_kb11;/* '<S2>/BusCreator' */
  ME_ProxiToMCU2_1_Def_t MbTHA_ProxiMgrOut;/* '<S5>/DataStoreRead4' */
  TbTHASmVc_InputFromThaDet_t MbTHA_ThaDetOutData;/* '<S4>/BusCreator' */
  TbTHASmVc_DiagMgr_t TbTHASmVc_DiagMgr_t_l3cu;/* '<S2>/BusCreator1' */
  TbTHASmVc_InputFromProxiMgr_t MbTHA_ProxiMgrOutData;/* '<S4>/BusCreator4' */
  TbTHASmVc_InputFromHmiSvs_t MbTHA_HmiSvsOutData;/* '<S4>/BusCreator1' */
  FID_STRUCT_QM MbTHA_DegMgrFIDOut;    /* '<S5>/DataStoreRead7' */
  SvsToTHA_t MbTHA_HmiSvsToThaOut;     /* '<S5>/DataStoreRead1' */
  TbTHASmVc_InputFromTRSC_t MbTHA_TrscSmVcOutData;/* '<S4>/BusCreator6' */
  TbTHASmVc_InputFromDegMgr_t MbTHA_DegradMgrOutData;/* '<S4>/BusCreator5' */
  TbTHASmVc_InputFromApSmPa_t MbTHA_ApSmOutData;/* '<S4>/BusCreator2' */
  TbAP_DriveAssistStatOut_t MbTHA_ApDaOut;/* '<S5>/DataStoreRead5' */
  TbAP_APSMPAOut_t MbTHA_ApSmOut;      /* '<S5>/DataStoreRead3' */
  SvsToVCAN_t MbTHA_HmiSvsToVcanOut;   /* '<S5>/DataStoreRead8' */
  ME_VehOut_TRSC_t MbTHA_TrscSmVcOut;  /* '<S5>/DataStoreRead6' */
  real32_T IeTHA_M_THASteerTrqInfo;    /* '<Root>/THA_SmVc_Ref' */
  real32_T IeTHA_pct_THAStrDamp;       /* '<Root>/THA_SmVc_Ref' */
  real32_T MeTHA_deg_RoadWhlAng;       /* '<Root>/THA_SmVc_Ref' */
  real32_T KeTHA_M_SteerTweakTrq_jky1; /* '<S4>/DataTypeConversion37' */
  real32_T KeTHA_s_SteerTweakTime_l4b0;/* '<S4>/DataTypeConversion41' */
  real32_T IeVBII_a_VehLongAcc;        /* '<S4>/DataTypeConversion19' */
  real32_T IeVBII_a_VehLatAcc;         /* '<S4>/DataTypeConversion18' */
  real32_T KeTHA_m_WhlCircumference_p23o;/* '<S4>/DataTypeConversion89' */
  real32_T KeTHA_k_HeadingErrGain_hve4;/* '<S4>/DataTypeConversion7' */
  real32_T KeTHA_k_TrqCtrlFiltCoef_h2g4;/* '<S4>/DataTypeConversion66' */
  real32_T KeTHA_k_TrqCtrlKd_fhal;     /* '<S4>/DataTypeConversion65' */
  real32_T KeTHA_k_TrqCtrlKi_obwj;     /* '<S4>/DataTypeConversion64' */
  real32_T KeTHA_k_TrqCtrlKp_bi22;     /* '<S4>/DataTypeConversion63' */
  real32_T KeTHA_k_SteerTrqCtrlFiltCoef_pwgq;/* '<S4>/DataTypeConversion52' */
  real32_T KeTHA_k_SteerTrqCtrlKd_pnpi;/* '<S4>/DataTypeConversion51' */
  real32_T KeTHA_k_SteerTrqCtrlKi_hrlm;/* '<S4>/DataTypeConversion50' */
  real32_T KeTHA_k_SteerTrqCtrlKp_ndhb;/* '<S4>/DataTypeConversion49' */
  int32_T MeTHA_px_HitchCplrPixDiffLongAtStrt;/* '<Root>/THA_SmVc_Ref' */
  int32_T MeTHA_px_HitchPnt[2];        /* '<S4>/DataTypeConversion3' */
  int32_T MeTHA_px_CplrPnt[2];         /* '<S4>/DataTypeConversion1' */
  int32_T KeTHA_px_HitchCplrDeltaThd2_o0fz;/* '<S4>/DataTypeConversion17' */
  int32_T KeTHA_px_HitchCplrDeltaThd1_ifbu;/* '<S4>/DataTypeConversion32' */
  TeVBII_e_WhlSpnSts IeVBII_e_LhfWhlSpnSts;/* '<S4>/DataTypeConversion87' */
  TeVBII_e_WhlSpnSts IeVBII_e_LhrWhlSpnSts;/* '<S4>/DataTypeConversion90' */
  TeVBII_e_WhlSpnSts IeVBII_e_RhfWhlSpnSts;/* '<S4>/DataTypeConversion93' */
  TeVBII_e_WhlSpnSts IeVBII_e_RhrWhlSpnSts;/* '<S4>/DataTypeConversion96' */
  TeVBII_e_VehStandStillSts IeVBII_e_VehStandStillSts;/* '<S4>/DataTypeConversion111' */
  TeVBII_e_VehEPBSts IeVBII_e_VehEPBSts;/* '<S4>/DataTypeConversion116' */
  TeVBII_e_TrlrPrsntSts IeVBII_e_TrlrPrsntSts;/* '<S4>/DataTypeConversion47' */
  TeVBII_e_TrailerConnectionSts IeVBII_e_TrailerConnectionSts;/* '<S4>/DataTypeConversion4' */
  TeVBII_e_TchScrSts IeVBII_e_TchScrSts;/* '<S4>/DataTypeConversion53' */
  TeVBII_e_THASteerTouchStatus IeVBII_e_THASteerTouchStatus;/* '<S4>/DataTypeConversion115' */
  TeVBII_e_LwsAngleType IeVBII_e_LwsAngleType;/* '<S4>/DataTypeConversion101' */
  TeVBII_e_GearEngagedForDsply IeVBII_e_GearEngagedForDsply;/* '<S4>/DataTypeConversion112' */
  TeVBII_e_EssEngState IeVBII_e_EssEngState;/* '<S4>/DataTypeConversion105' */
  TeVBII_e_EpsTHASteerTrqResp IeVBII_e_EpsTHASteerTrqResp;/* '<S4>/DataTypeConversion114' */
  TeVBII_e_EpsTHADrvTrqOvrd IeVBII_e_EpsTHADrvTrqOvrd;/* '<S4>/DataTypeConversion113' */
  TeVBII_e_EngineSts IeVBII_e_EngineSts;/* '<S4>/DataTypeConversion102' */
  TeVBII_e_EcmTHAResp IeVBII_e_EcmTHAResp;/* '<S4>/DataTypeConversion108' */
  TeVBII_e_CmdIgnSts IeVBII_e_CmdIgnSts;/* '<S4>/DataTypeConversion2' */
  TeVBII_e_BsmTHABrkResp IeVBII_e_BsmTHABrkResp;/* '<S4>/DataTypeConversion109' */
  TeTRSC_e_TRSCSts IeTRSC_e_TRSCSts;   /* '<S4>/DataTypeConversion16' */
  TeTHA_e_THASteerTrqReq IeTHA_e_THASteerTrqReq;/* '<Root>/THA_SmVc_Ref' */
  TeTHA_e_THAStateInfo MeTHA_e_THAStateInfo;/* '<Root>/THA_SmVc_Ref' */
  TeTHA_e_THAState IeTHA_e_THAState;   /* '<Root>/THA_SmVc_Ref' */
  TeTHA_e_THASpdLimReq IeTHA_e_THASpdLimReq;/* '<Root>/THA_SmVc_Ref' */
  TeTHA_e_THARmpUpDwnSpd IeTHA_e_THARmpUpDwnSpd;/* '<Root>/THA_SmVc_Ref' */
  TeTHA_e_ScreenRequest MeTHA_e_ScreenRequest;/* '<Root>/THA_SmVc_Ref' */
  TeTHA_e_ScreenRequest MeSVS_e_THAScrResp_pelw;/* '<S4>/DataTypeConversion44' */
  TeTHA_e_RearBrkSupprInfo MeTHA_e_RearBrkSupprInfo;/* '<Root>/THA_SmVc_Ref' */
  TeTHA_e_PamVol IeTHA_e_PamVol;       /* '<Root>/THA_SmVc_Ref' */
  TeTHA_e_PamChimeTyp IeTHA_e_PamChimeTyp;/* '<Root>/THA_SmVc_Ref' */
  TeTHA_e_PamChimeRepRateSts IeTHA_e_PamChimeRepRateSts;/* '<Root>/THA_SmVc_Ref' */
  TeTHA_e_HitchDetctStatus MeTHA_e_HitchDetctStatus_i0mv;/* '<S4>/DataTypeConversion14' */
  TeTHA_e_EPBReq IeTHA_e_EPBReq;       /* '<Root>/THA_SmVc_Ref' */
  TeTHA_e_CplrDetctStatus MeTHA_e_CplrDetctStatus_dz1g;/* '<S4>/DataTypeConversion46' */
  TeSVS_e_DispView2 IeSVS_e_DispView2; /* '<S4>/DataTypeConversion42' */
  TePRX_e_Wheelbase MePRX_e_Wheelbase; /* '<S4>/DataTypeConversion78' */
  TePRX_e_VehLineCfg MePRX_e_VehLineCfg;/* '<S4>/DataTypeConversion76' */
  TePRX_e_SteerRatRackPinionTyp MePRX_e_SteerRatRackPinionTyp;/* '<S4>/DataTypeConversion80' */
  TeAP_e_FrntRearParkSts IeAP_e_FrntRearParkSts;/* '<S4>/DataTypeConversion45' */
  TeAP_e_AutoParkStatus IeAP_e_AutoParkStatus;/* '<S4>/DataTypeConversion15' */
  uint16_T KeTHA_ddeg_StrRateLimFinal_asrp;/* '<S4>/DataTypeConversion86' */
  uint8_T IeVBII_cnt_LhfPulseCtr;      /* '<S4>/DataTypeConversion22' */
  uint8_T IeVBII_cnt_LhrPulseCtr;      /* '<S4>/DataTypeConversion25' */
  uint8_T IeVBII_cnt_RhfPulseCtr;      /* '<S4>/DataTypeConversion28' */
  uint8_T MePRX_k_VariantId;           /* '<S4>/DataTypeConversion75' */
  boolean_T IeTHA_b_ChimeActvLhf;      /* '<Root>/THA_SmVc_Ref' */
  boolean_T IeTHA_b_ChimeActvRhf;      /* '<Root>/THA_SmVc_Ref' */
  boolean_T IeTHA_b_ChimeActvLhr;      /* '<Root>/THA_SmVc_Ref' */
  boolean_T IeTHA_b_ChimeActvRhr;      /* '<Root>/THA_SmVc_Ref' */
  boolean_T MeTHA_b_EnblRearParkAsstTrg;/* '<Root>/THA_SmVc_Ref' */
  boolean_T MeTHA_b_UsrHitchCnfm;      /* '<Root>/THA_SmVc_Ref' */
  boolean_T MeTHA_b_UsrCplrSelCnfm;    /* '<Root>/THA_SmVc_Ref' */
  boolean_T MeTHA_b_TrlrCplrStatus;    /* '<Root>/THA_SmVc_Ref' */
  boolean_T MeTHA_b_THAAbortStatus;    /* '<Root>/THA_SmVc_Ref' */
  boolean_T MeTHA_b_UsrInputTimeOut;   /* '<Root>/THA_SmVc_Ref' */
  boolean_T MeTHA_b_ViewZoomSts;       /* '<Root>/THA_SmVc_Ref' */
  boolean_T MeTHA_b_CamOccluLoLi;      /* '<Root>/THA_SmVc_Ref' */
  boolean_T MeSVS_b_IsConfirmBtnPrsd_gvdh;/* '<S4>/DataTypeConversion11' */
  boolean_T MeSVS_b_ImgDefeatReqSts_iwrg;/* '<S4>/DataTypeConversion12' */
  boolean_T MeSVS_b_THASftBtnPrsdStsToTHA_orlw;/* '<S4>/DataTypeConversion10' */
  boolean_T MePRX_b_TrlrHitchAssPres;  /* '<S4>/DataTypeConversion77' */
  boolean_T MeTHA_b_FidDLDAbort_jpzk;  /* '<S4>/DataTypeConversion23' */
  boolean_T MeTHA_b_FidCamCalAbort_oxnw;/* '<S4>/DataTypeConversion29' */
  boolean_T KeTHA_b_Valid;             /* '<S4>/DataTypeConversion95' */
} B_THA_SWC_T;

/* Block signals (default storage) */
extern B_THA_SWC_T THA_SWC_B;

/* External data declarations for dependent source files */
extern const TbTHASmVc_InputFromVehInp_t THA_SWC_rtZTbTHASmVc_InputFromVehInp_t;/* TbTHASmVc_InputFromVehInp_t ground */
extern const TbTHASmVc_InputFromProxiMgr_t
  THA_SWC_rtZTbTHASmVc_InputFromProxiMgr_t;
                                      /* TbTHASmVc_InputFromProxiMgr_t ground */

/* Model entry point functions */
extern void THA_SWC_initialize(void);
extern void THA_SWC_step(void);

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
 * '<Root>' : 'THA_SWC'
 * '<S1>'   : 'THA_SWC/DataStoreMemoryIn'
 * '<S2>'   : 'THA_SWC/DataStoreMemoryOut'
 * '<S3>'   : 'THA_SWC/Model Info'
 * '<S4>'   : 'THA_SWC/DataStoreMemoryIn/CodeToModelMapping'
 * '<S5>'   : 'THA_SWC/DataStoreMemoryIn/Rx_Embedded'
 */

/*-
 * Requirements for '<Root>': THA_SWC
 */
#endif                                 /* RTW_HEADER_THA_SWC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
