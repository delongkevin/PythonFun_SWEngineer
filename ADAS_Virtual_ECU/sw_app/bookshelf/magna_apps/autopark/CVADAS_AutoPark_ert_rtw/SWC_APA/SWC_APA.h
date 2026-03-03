/*
 * File: SWC_APA.h
 *
 * Code generated for Simulink model 'SWC_APA'.
 *
 * Model version                  : 1.594
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Nov 12 18:11:22 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_APA_h_
#define RTW_HEADER_SWC_APA_h_
#include <math.h>
#ifndef SWC_APA_COMMON_INCLUDES_
# define SWC_APA_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SWC_APA_COMMON_INCLUDES_ */

#include "SWC_APA_types.h"

/* Child system includes */
#ifndef SWC_APA_MDLREF_HIDE_CHILD_
#include "FrontParkAssist.h"
#endif                                 /*SWC_APA_MDLREF_HIDE_CHILD_*/

#ifndef SWC_APA_MDLREF_HIDE_CHILD_
#include "RearParkAssist.h"
#endif                                 /*SWC_APA_MDLREF_HIDE_CHILD_*/

#ifndef SWC_APA_MDLREF_HIDE_CHILD_
#include "RearStop_Release.h"
#endif                                 /*SWC_APA_MDLREF_HIDE_CHILD_*/

#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define CeAP_cm_CurbLatchDist          170.0F                    /* Referenced by: '<S57>/Rear_ObjectDetection' */
#define CeAP_cm_DefaultRearDistInt16   1023                      /* Referenced by: '<S653>/RearDistHold' */
#define CeAP_cm_EnRaebDistHoldThsd     60                        /* Referenced by: '<S653>/RearDistHold' */
#define CeAP_cm_FrntSideArc1Adj        10                        /* Referenced by:
                                                                  * '<S83>/AlertFilterLHF'
                                                                  * '<S83>/AlertFilterRHF'
                                                                  */
#define CeAP_cm_FrntSideArc2Adj        5                         /* Referenced by:
                                                                  * '<S83>/AlertFilterLHF'
                                                                  * '<S83>/AlertFilterRHF'
                                                                  */
#define CeAP_cm_SideArc1Adj            5                         /* Referenced by:
                                                                  * '<S484>/AlertFilterLHR'
                                                                  * '<S484>/AlertFilterRHR'
                                                                  */
#define CeAP_cm_SideArc2Adj            0                         /* Referenced by:
                                                                  * '<S484>/AlertFilterLHR'
                                                                  * '<S484>/AlertFilterRHR'
                                                                  */
#define CeAP_deg_MinSteerCurvature     10.0F                     /* Referenced by: '<S57>/Rear_ObjectDetection' */
#define CeAP_k_CurbDbnc                20U                       /* Referenced by: '<S57>/Rear_ObjectDetection' */
#define CeAP_k_SingleNegOne            -1.0F                     /* Referenced by: '<S57>/Rear_ObjectDetection' */
#define CeAP_k_SingleOne               1.0F                      /* Referenced by: '<S57>/Rear_ObjectDetection' */
#define CeAP_k_SingleTwo               2.0F                      /* Referenced by: '<S57>/Rear_ObjectDetection' */
#define CeAP_k_SingleZero              2.0F                      /* Referenced by: '<S57>/Rear_ObjectDetection' */
#define CeAP_k_Uint8One                1U                        /* Referenced by: '<S57>/Rear_ObjectDetection' */
#define CeAP_k_Uint8Zero               0U                        /* Referenced by:
                                                                  * '<S57>/Rear_ObjectDetection'
                                                                  * '<S653>/RearDistHold'
                                                                  */
#define CeAP_ms_RaebThsdHold1          100U                      /* Referenced by: '<S653>/RearDistHold' */
#define CeAP_ms_RaebThsdHold2          200U                      /* Referenced by: '<S653>/RearDistHold' */
#define KeAP_k_RaebCruiseAgeThd        6U                        /* Referenced by: '<S57>/Rear_ObjectDetection' */
#define KeAP_pct_CurbConfThd           78U                       /* Referenced by: '<S57>/Rear_ObjectDetection' */
#define KePA_cm_RearCurbDetectLatThd   15                        /* Referenced by: '<S57>/Rear_ObjectDetection' */
#define KePA_cm_RearCurbDetectLongThd  10                        /* Referenced by: '<S57>/Rear_ObjectDetection' */
#define KePA_cnt_RearCurbPntCntThd     3U                        /* Referenced by: '<S57>/Rear_ObjectDetection' */

/* user code (top of header file) */
#include "SignalDef.h"

/* Block signals for model 'SWC_APA' */
#ifndef SWC_APA_MDLREF_HIDE_CHILD_

typedef struct {
  TbVBIA_VehState_AP
    BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1;
  TbNVM_ProxyCalibParam
    BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1;
  real_T UnitDelay2;                   /* '<S559>/Unit Delay2' */
  real_T UnitDelay2_o;                 /* '<S558>/Unit Delay2' */
  real_T Switch4;                      /* '<S558>/Switch4' */
  real_T Switch4_g;                    /* '<S559>/Switch4' */
  real_T UnitDelay2_i;                 /* '<S505>/Unit Delay2' */
  real_T Switch4_k;                    /* '<S505>/Switch4' */
  real_T Switch1;                      /* '<S559>/Switch1' */
  real_T Subtract;                     /* '<S559>/Subtract' */
  real_T Switch1_c;                    /* '<S558>/Switch1' */
  real_T Subtract_e;                   /* '<S558>/Subtract' */
  real_T Switch1_e;                    /* '<S505>/Switch1' */
  real_T Subtract_m;                   /* '<S505>/Subtract' */
  real_T UnitDelay2_e;                 /* '<S151>/Unit Delay2' */
  real_T UnitDelay2_b;                 /* '<S150>/Unit Delay2' */
  real_T Switch4_e;                    /* '<S150>/Switch4' */
  real_T Switch4_l;                    /* '<S151>/Switch4' */
  real_T UnitDelay2_c;                 /* '<S104>/Unit Delay2' */
  real_T Switch4_a;                    /* '<S104>/Switch4' */
  real_T Switch1_d;                    /* '<S151>/Switch1' */
  real_T Subtract_p;                   /* '<S151>/Subtract' */
  real_T Switch1_h;                    /* '<S150>/Switch1' */
  real_T Subtract_pq;                  /* '<S150>/Subtract' */
  real_T Switch1_o;                    /* '<S104>/Switch1' */
  real_T Subtract_g;                   /* '<S104>/Subtract' */
  real_T Switch1_i;                    /* '<S27>/Switch1' */
  real_T Switch2;                      /* '<S27>/Switch2' */
  real_T Switch1_m;                    /* '<S22>/Switch1' */
  real_T Switch2_f;                    /* '<S22>/Switch2' */
  real_T Switch3;                      /* '<S559>/Switch3' */
  real_T Switch3_p;                    /* '<S505>/Switch3' */
  uint32_T DataTypeConversion;         /* '<S2>/Data Type Conversion' */
  real32_T Saturation;                 /* '<S5>/Saturation' */
  real32_T Saturation1;                /* '<S5>/Saturation1' */
  real32_T Saturation2;                /* '<S5>/Saturation2' */
  real32_T MeAP_cm_RearDist;           /* '<S57>/Rear_ObjectDetection' */
  real32_T DataTypeConversion1;        /* '<S651>/Data Type Conversion1' */
  real32_T UnitDelay;                  /* '<S661>/Unit Delay' */
  real32_T DataTypeConversion_n;       /* '<S653>/Data Type Conversion' */
  real32_T Switch;                     /* '<S661>/Switch' */
  real32_T MeAP_cm_RearDist_Out;       /* '<S653>/RearDistHold' */
  real32_T Sum1;                       /* '<S661>/Sum1' */
  real32_T Switch6;                    /* '<S564>/Switch6' */
  real32_T Subtract_h;                 /* '<S564>/Subtract' */
  real32_T Zone1;                      /* '<S156>/Switch4' */
  real32_T Subtract_mz;                /* '<S156>/Subtract' */
  real32_T DataTypeConversion_i;       /* '<S651>/Data Type Conversion' */
  TeVBII_e_PamChimeVol UnitDelay_p;    /* '<S482>/Unit Delay' */
  TeVBII_e_PamChimeVol UnitDelay_k;    /* '<S81>/Unit Delay' */
  TeVBII_e_CmdIgnSts UnitDelay1;       /* '<S58>/Unit Delay1' */
  TeAP_e_RearSnsrStatus Switch1_n;     /* '<S40>/Switch1' */
  TeAP_e_PAMVolume MeAP_e_PAMVolume;   /* '<S55>/Switch2' */
  TeAP_e_PAMVolume MultiportSwitch1;   /* '<S55>/Multiport Switch1' */
  TeAP_e_PAMVolume Switch1_a;          /* '<S55>/Switch1' */
  TeAP_e_PAMVolume Switch3_i;          /* '<S55>/Switch3' */
  TeAP_e_PAMVolume MultiportSwitch;    /* '<S55>/Multiport Switch' */
  TeAP_e_PAMPopUpReq MeAP_e_PAMPopUpReqPrev;/* '<S244>/Unit Delay2' */
  TeAP_e_PAMPopUpReq MeAP_e_PAMPopUpReq;/* '<S54>/PopUpPriority1' */
  TeAP_e_PAMOffStatus2BT MeAP_e_FeatStsBeforeTrlrPrev;/* '<S685>/Unit Delay' */
  TeAP_e_PAMOffStatus2BT MeAP_e_FeatStsBeforeTrlr;/* '<S685>/Merge' */
  TeAP_e_PAMOffStatus2BT MeAP_e_FeatStsBeforeTrlr_h;/* '<S685>/Merge' */
  TeAP_e_PAMOffStatus2BT Switch1_j;    /* '<S14>/Switch1' */
  TeAP_e_PAMOffStatus2BT Switch2_h;    /* '<S14>/Switch2' */
  TeAP_e_PAMLedCtrlStatus UnitDelay1_m;/* '<S480>/Unit Delay1' */
  TeAP_e_PAMLedCtrlStatus Switch3_c;   /* '<S480>/Switch3' */
  TeAP_e_PAMLedCtrlStatus Switch4_es;  /* '<S480>/Switch4' */
  TeAP_e_PAMLedCtrlStatus UnitDelay1_n;/* '<S78>/Unit Delay1' */
  TeAP_e_PAMLedCtrlStatus Switch3_a;   /* '<S78>/Switch3' */
  TeAP_e_PAMLedCtrlStatus Switch4_ap;  /* '<S78>/Switch4' */
  TeAP_e_PAMChimeTyp Switch1_dd;       /* '<S53>/Switch1' */
  TeAP_e_PAMChimeRepnRate MeAP_e_LtRearChimeRepnRate;/* '<S482>/Switch2' */
  TeAP_e_PAMChimeRepnRate MeAP_e_RtRearChimeRepnRate;/* '<S482>/Switch2' */
  TeAP_e_PAMChimeRepnRate MeAP_e_LtRearChimeRepnRate_Raw;/* '<S511>/Switch' */
  TeAP_e_PAMChimeRepnRate MeAP_e_RtRearChimeRepnRate_Raw;/* '<S512>/Switch' */
  TeAP_e_PAMChimeRepnRate MeAP_e_RtRearChimeRepnRate_Raw_l;/* '<S512>/Switch1' */
  TeAP_e_PAMChimeRepnRate MeAP_e_RtRearChimeRepnRate_Raw_a;/* '<S512>/Switch2' */
  TeAP_e_PAMChimeRepnRate MeAP_e_RtRearChimeRepnRate_Raw_k;/* '<S512>/Switch3' */
  TeAP_e_PAMChimeRepnRate MeAP_e_RtRearChimeRepnRate_Raw_g;/* '<S512>/Switch4' */
  TeAP_e_PAMChimeRepnRate MeAP_e_RtRearChimeRepnRate_Raw_j;/* '<S512>/Switch5' */
  TeAP_e_PAMChimeRepnRate MeAP_e_LtRearChimeRepnRate_Raw_k;/* '<S511>/Switch1' */
  TeAP_e_PAMChimeRepnRate MeAP_e_LtRearChimeRepnRate_Raw_l;/* '<S511>/Switch2' */
  TeAP_e_PAMChimeRepnRate MeAP_e_LtRearChimeRepnRate_Raw_ku;/* '<S511>/Switch3' */
  TeAP_e_PAMChimeRepnRate MeAP_e_LtRearChimeRepnRate_Raw_a;/* '<S511>/Switch4' */
  TeAP_e_PAMChimeRepnRate MeAP_e_LtRearChimeRepnRate_Raw_n;/* '<S511>/Switch5' */
  TeAP_e_PAMChimeRepnRate MeAP_e_LtFrntChimeRepnRate;/* '<S81>/Switch2' */
  TeAP_e_PAMChimeRepnRate MeAP_e_RtFrntChimeRepnRate;/* '<S81>/Switch2' */
  TeAP_e_PAMChimeRepnRate MeAP_e_RtFrntChimeRepnRate_n;/* '<S117>/Switch' */
  TeAP_e_PAMChimeRepnRate MeAP_e_LtFrntChimeRepnRate_l;/* '<S116>/Switch' */
  TeAP_e_PAMChimeRepnRate MeAP_e_RtFrntChimeRepnRate_m;/* '<S117>/Switch1' */
  TeAP_e_PAMChimeRepnRate MeAP_e_LtFrntChimeRepnRate_a;/* '<S116>/Switch1' */
  TeAP_e_PAMChimeRepnRate DataTypeConversion5;/* '<S50>/Data Type Conversion5' */
  TeAP_e_PAMChimeRepnRate Switch1_jn;  /* '<S50>/Switch1' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicRHR;/* '<S567>/Switch' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicLHR;/* '<S566>/Switch' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicCHR;/* '<S564>/Switch' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicRHR_b;/* '<S567>/Switch1' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicLHR_i;/* '<S566>/Switch1' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicCHR_h;/* '<S564>/Switch1' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicCHR_j;/* '<S564>/Switch2' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicCHR_f;/* '<S564>/Switch3' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicCHR_p;/* '<S564>/Switch4' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicCHR_l;/* '<S564>/Switch5' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicRHF;/* '<S159>/Switch' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicLHF;/* '<S158>/Switch' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicCHF;/* '<S156>/Switch' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicRHF_i;/* '<S159>/Switch1' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicLHF_j;/* '<S158>/Switch1' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicCHF_a;/* '<S156>/Switch1' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicCHF_l;/* '<S156>/Switch2' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicCHF_i;/* '<S156>/Switch3' */
  TeAP_e_FrntSnsrStatus Switch1_oo;    /* '<S39>/Switch1' */
  TeAP_e_FiltdGearState UnitDelay1_nu; /* '<S79>/Unit Delay1' */
  TeAP_e_Alert Switch1_g;              /* '<S607>/Switch1' */
  TeAP_e_Alert Switch2_i;              /* '<S607>/Switch2' */
  TeAP_e_Alert Switch1_jc;             /* '<S606>/Switch1' */
  TeAP_e_Alert Switch2_c;              /* '<S606>/Switch2' */
  TeAP_e_Alert Switch1_nm;             /* '<S605>/Switch1' */
  TeAP_e_Alert Switch2_j;              /* '<S605>/Switch2' */
  TeAP_e_Alert MeAP_e_AlertRHR;        /* '<S484>/AlertFilterRHR' */
  TeAP_e_Alert MeAP_e_AlertLHR;        /* '<S484>/AlertFilterLHR' */
  TeAP_e_Alert MeAP_e_AlertCHR;        /* '<S484>/AlertFilterCHR' */
  TeAP_e_Alert MeAP_e_AlertCHR_p;      /* '<S564>/Switch' */
  TeAP_e_Alert MeAP_e_AlertLHR_o;      /* '<S566>/Switch' */
  TeAP_e_Alert MeAP_e_AlertRHR_h;      /* '<S567>/Switch' */
  TeAP_e_Alert OutportBufferForMeAP_e_AlertCHR;/* '<S483>/CheckDNNFlag' */
  TeAP_e_Alert OutportBufferForMeAP_e_AlertLHR;/* '<S483>/CheckDNNFlag' */
  TeAP_e_Alert OutportBufferForMeAP_e_AlertRHR;/* '<S483>/CheckDNNFlag' */
  TeAP_e_Alert MeAP_e_AlertRHR_hd;     /* '<S567>/Switch1' */
  TeAP_e_Alert MeAP_e_AlertLHR_l;      /* '<S566>/Switch1' */
  TeAP_e_Alert MeAP_e_AlertCHR_Raw;    /* '<S565>/DNNCheck' */
  TeAP_e_Alert MeAP_e_AlertLHR_Raw;    /* '<S565>/DNNCheck' */
  TeAP_e_Alert MeAP_e_AlertRHR_Raw;    /* '<S565>/DNNCheck' */
  TeAP_e_Alert MeAP_e_AlertCHR_o;      /* '<S564>/Switch1' */
  TeAP_e_Alert MeAP_e_AlertCHR_l;      /* '<S564>/Switch2' */
  TeAP_e_Alert MeAP_e_AlertCHR_d;      /* '<S564>/Switch3' */
  TeAP_e_Alert MeAP_e_AlertCHR_j;      /* '<S564>/Switch4' */
  TeAP_e_Alert MeAP_e_AlertCHR_a;      /* '<S564>/Switch5' */
  TeAP_e_Alert Switch1_a2;             /* '<S195>/Switch1' */
  TeAP_e_Alert Switch2_cc;             /* '<S195>/Switch2' */
  TeAP_e_Alert Switch1_ix;             /* '<S194>/Switch1' */
  TeAP_e_Alert Switch2_jt;             /* '<S194>/Switch2' */
  TeAP_e_Alert Switch1_l;              /* '<S193>/Switch1' */
  TeAP_e_Alert Switch2_p;              /* '<S193>/Switch2' */
  TeAP_e_Alert MeAP_e_AlertRHF;        /* '<S83>/AlertFilterRHF' */
  TeAP_e_Alert MeAP_e_AlertLHF;        /* '<S83>/AlertFilterLHF' */
  TeAP_e_Alert MeAP_e_AlertCHF;        /* '<S83>/AlertFilterCHF' */
  TeAP_e_Alert MeAP_e_AlertCHF_p;      /* '<S156>/Switch' */
  TeAP_e_Alert MeAP_e_AlertLHF_i;      /* '<S158>/Switch' */
  TeAP_e_Alert MeAP_e_AlertRHF_n;      /* '<S159>/Switch' */
  TeAP_e_Alert OutportBufferForMeAP_e_AlertCHF;/* '<S82>/CheckDNNFlag' */
  TeAP_e_Alert OutportBufferForMeAP_e_AlertLHF;/* '<S82>/CheckDNNFlag' */
  TeAP_e_Alert OutportBufferForMeAP_e_AlertRHF;/* '<S82>/CheckDNNFlag' */
  TeAP_e_Alert MeAP_e_AlertRHF_b;      /* '<S159>/Switch1' */
  TeAP_e_Alert MeAP_e_AlertLHF_o;      /* '<S158>/Switch1' */
  TeAP_e_Alert MeAP_e_AlertCHF_Raw;    /* '<S157>/DNNCheck' */
  TeAP_e_Alert MeAP_e_AlertLHF_Raw;    /* '<S157>/DNNCheck' */
  TeAP_e_Alert MeAP_e_AlertRHF_Raw;    /* '<S157>/DNNCheck' */
  TeAP_e_Alert MeAP_e_AlertCHF_h;      /* '<S156>/Switch1' */
  TeAP_e_Alert MeAP_e_AlertCHF_b;      /* '<S156>/Switch2' */
  TeAP_e_Alert MeAP_e_AlertCHF_f;      /* '<S156>/Switch3' */
  TeAP_e_Alert FrontObjMinZoneEnum;    /* '<S241>/Data Type Conversion1' */
  uint16_T timerValue;                 /* '<S607>/Switch4' */
  uint16_T timerValue_k;               /* '<S605>/Switch4' */
  uint16_T timerValue_g;               /* '<S606>/Switch4' */
  uint16_T UnitDelay2_n;               /* '<S509>/Unit Delay2' */
  uint16_T Switch3_h;                  /* '<S509>/Switch3' */
  uint16_T UnitDelay_d;                /* '<S648>/Unit Delay' */
  uint16_T Switch1_ii;                 /* '<S648>/Switch1' */
  uint16_T Minimum;                    /* '<S648>/Minimum' */
  uint16_T timerValue_e;               /* '<S607>/Switch3' */
  uint16_T LookupTableDynamic;         /* '<S607>/Lookup Table Dynamic' */
  uint16_T UnitDelay_o;                /* '<S638>/Unit Delay' */
  uint16_T Switch1_cy;                 /* '<S638>/Switch1' */
  uint16_T Minimum_b;                  /* '<S638>/Minimum' */
  uint16_T timerValue_e2;              /* '<S606>/Switch3' */
  uint16_T LookupTableDynamic_g;       /* '<S606>/Lookup Table Dynamic' */
  uint16_T UnitDelay_b;                /* '<S628>/Unit Delay' */
  uint16_T Switch1_k;                  /* '<S628>/Switch1' */
  uint16_T Minimum_g;                  /* '<S628>/Minimum' */
  uint16_T timerValue_gk;              /* '<S605>/Switch3' */
  uint16_T LookupTableDynamic_j;       /* '<S605>/Lookup Table Dynamic' */
  uint16_T uDLookupTable;              /* '<S582>/1-D Lookup Table' */
  uint16_T UnitDelay_pz;               /* '<S584>/Unit Delay' */
  uint16_T Switch1_lb;                 /* '<S584>/Switch1' */
  uint16_T Minimum_c;                  /* '<S584>/Minimum' */
  uint16_T UnitDelay2_g;               /* '<S530>/Unit Delay2' */
  uint16_T Switch4_b;                  /* '<S530>/Switch4' */
  uint16_T UnitDelay2_cy;              /* '<S550>/Unit Delay2' */
  uint16_T Switch4_n;                  /* '<S550>/Switch4' */
  uint16_T Switch1_p;                  /* '<S550>/Switch1' */
  uint16_T Subtract_a;                 /* '<S550>/Subtract' */
  uint16_T Switch1_f;                  /* '<S530>/Switch1' */
  uint16_T Subtract_gg;                /* '<S530>/Subtract' */
  uint16_T Switch1_am;                 /* '<S509>/Switch1' */
  uint16_T Subtract_py;                /* '<S509>/Subtract' */
  uint16_T Switch_a;                   /* '<S480>/Switch' */
  uint16_T UnitDelay2_it;              /* '<S467>/Unit Delay2' */
  uint16_T Switch3_po;                 /* '<S467>/Switch3' */
  uint16_T UnitDelay2_ib;              /* '<S463>/Unit Delay2' */
  uint16_T Switch3_f;                  /* '<S463>/Switch3' */
  uint16_T UnitDelay2_h;               /* '<S465>/Unit Delay2' */
  uint16_T Switch3_b;                  /* '<S465>/Switch3' */
  uint16_T UnitDelay2_nd;              /* '<S260>/Unit Delay2' */
  uint16_T Switch3_fy;                 /* '<S260>/Switch3' */
  uint16_T Add;                        /* '<S249>/Add' */
  uint16_T Switch1_mh;                 /* '<S467>/Switch1' */
  uint16_T Subtract_c;                 /* '<S467>/Subtract' */
  uint16_T Switch1_nq;                 /* '<S465>/Switch1' */
  uint16_T Subtract_pb;                /* '<S465>/Subtract' */
  uint16_T Switch1_kq;                 /* '<S463>/Switch1' */
  uint16_T Subtract_k;                 /* '<S463>/Subtract' */
  uint16_T Switch_h;                   /* '<S257>/Switch' */
  uint16_T Switch1_iu;                 /* '<S260>/Switch1' */
  uint16_T Subtract_pa;                /* '<S260>/Subtract' */
  uint16_T Switch4_c;                  /* '<S194>/Switch4' */
  uint16_T Switch4_esz;                /* '<S195>/Switch4' */
  uint16_T Switch4_f;                  /* '<S193>/Switch4' */
  uint16_T UnitDelay2_gm;              /* '<S108>/Unit Delay2' */
  uint16_T Switch3_k;                  /* '<S108>/Switch3' */
  uint16_T UnitDelay_c;                /* '<S236>/Unit Delay' */
  uint16_T Switch1_jq;                 /* '<S236>/Switch1' */
  uint16_T Minimum_k;                  /* '<S236>/Minimum' */
  uint16_T Switch3_m;                  /* '<S195>/Switch3' */
  uint16_T LookupTableDynamic_m;       /* '<S195>/Lookup Table Dynamic' */
  uint16_T UnitDelay_e;                /* '<S226>/Unit Delay' */
  uint16_T Switch1_nh;                 /* '<S226>/Switch1' */
  uint16_T Minimum_b0;                 /* '<S226>/Minimum' */
  uint16_T Switch3_o;                  /* '<S194>/Switch3' */
  uint16_T LookupTableDynamic_d;       /* '<S194>/Lookup Table Dynamic' */
  uint16_T UnitDelay_cz;               /* '<S216>/Unit Delay' */
  uint16_T Switch1_b;                  /* '<S216>/Switch1' */
  uint16_T Minimum_gh;                 /* '<S216>/Minimum' */
  uint16_T Switch3_hv;                 /* '<S193>/Switch3' */
  uint16_T LookupTableDynamic_f;       /* '<S193>/Lookup Table Dynamic' */
  uint16_T uDLookupTable_p;            /* '<S170>/1-D Lookup Table' */
  uint16_T UnitDelay_kx;               /* '<S172>/Unit Delay' */
  uint16_T Switch1_gi;                 /* '<S172>/Switch1' */
  uint16_T Minimum_l;                  /* '<S172>/Minimum' */
  uint16_T UnitDelay2_m;               /* '<S120>/Unit Delay2' */
  uint16_T Switch3_ca;                 /* '<S120>/Switch3' */
  uint16_T Switch1_dc;                 /* '<S120>/Switch1' */
  uint16_T Subtract_d;                 /* '<S120>/Subtract' */
  uint16_T Switch1_gn;                 /* '<S108>/Switch1' */
  uint16_T Subtract_da;                /* '<S108>/Subtract' */
  uint16_T Switch_b;                   /* '<S78>/Switch' */
  uint16_T UnitDelay2_a;               /* '<S22>/Unit Delay2' */
  uint16_T Switch3_iv;                 /* '<S22>/Switch3' */
  uint16_T UnitDelay2_ed;              /* '<S27>/Unit Delay2' */
  uint16_T Switch3_j;                  /* '<S27>/Switch3' */
  uint16_T Subtract_ka;                /* '<S27>/Subtract' */
  uint16_T Subtract_mh;                /* '<S22>/Subtract' */
  uint16_T Summation;                  /* '<S648>/Summation' */
  uint16_T Summation_o;                /* '<S638>/Summation' */
  uint16_T Summation_j;                /* '<S628>/Summation' */
  uint16_T Summation_l;                /* '<S584>/Summation' */
  uint16_T Summation_i;                /* '<S236>/Summation' */
  uint16_T Summation_jx;               /* '<S226>/Summation' */
  uint16_T Summation_m;                /* '<S216>/Summation' */
  uint16_T Summation_p;                /* '<S172>/Summation' */
  uint16_T Switch3_co;                 /* '<S550>/Switch3' */
  int16_T MeAP_cm_RearDist_Int;        /* '<S57>/Rear_ObjectDetection' */
  int16_T Switch7;                     /* '<S564>/Switch7' */
  uint8_T FixPtRelationalOperator;     /* '<S654>/FixPt Relational Operator' */
  uint8_T DataTypeConversion_p;        /* '<S603>/Data Type Conversion' */
  uint8_T DataTypeConversion_g;        /* '<S602>/Data Type Conversion' */
  uint8_T DataTypeConversion_e;        /* '<S604>/Data Type Conversion' */
  uint8_T DataTypeConversion_gm;       /* '<S55>/Data Type Conversion' */
  uint8_T DataTypeConversion1_i;       /* '<S55>/Data Type Conversion1' */
  uint8_T DataTypeConversion1_d;       /* '<S250>/Data Type Conversion1' */
  uint8_T DataTypeConversion1_g;       /* '<S251>/Data Type Conversion1' */
  uint8_T DataTypeConversion1_n;       /* '<S252>/Data Type Conversion1' */
  uint8_T DataTypeConversion_h;        /* '<S191>/Data Type Conversion' */
  uint8_T DataTypeConversion_eb;       /* '<S190>/Data Type Conversion' */
  uint8_T DataTypeConversion_pb;       /* '<S192>/Data Type Conversion' */
  uint8_T MeAP_TransitionDebugVar;     /* '<S5>/APA_StateMachine' */
  uint8_T DataTypeConversion_ebm;      /* '<S687>/Data Type Conversion' */
  uint8_T DataTypeConversion1_p;       /* '<S687>/Data Type Conversion1' */
  uint8_T BitwiseOperator1;            /* '<S687>/Bitwise Operator1' */
  uint8_T BitwiseOperator;             /* '<S687>/Bitwise Operator' */
  uint8_T BitwiseOperator1_e;          /* '<S59>/Bitwise Operator1' */
  uint8_T BitwiseOperator_e;           /* '<S59>/Bitwise Operator' */
  uint8_T BitwiseOperator_k;           /* '<S564>/Bitwise Operator' */
  uint8_T MultiportSwitch_l;           /* '<S251>/Multiport Switch' */
  uint8_T MultiportSwitch_m;           /* '<S252>/Multiport Switch' */
  uint8_T IsFrntWall;                  /* '<S156>/Bitwise Operator' */
  uint8_T DataTypeConversion3;         /* '<S50>/Data Type Conversion3' */
  uint8_T DataTypeConversion2;         /* '<S50>/Data Type Conversion2' */
  uint8_T DataTypeConversion1_i3;      /* '<S50>/Data Type Conversion1' */
  uint8_T MinMax;                      /* '<S50>/MinMax' */
  uint8_T DataTypeConversion_c;        /* '<S650>/Data Type Conversion' */
  boolean_T ECUPwrd;                   /* '<S7>/Unit Delay' */
  boolean_T BitwiseOperator_g;         /* '<S7>/Bitwise Operator' */
  boolean_T MeAP_b_DisableDiag;        /* '<S9>/Logical Operator' */
  boolean_T LogicalOperator12;         /* '<S51>/Logical Operator12' */
  boolean_T Compare;                   /* '<S683>/Compare' */
  boolean_T Compare_b;                 /* '<S682>/Compare' */
  boolean_T BitwiseOperator_l;         /* '<S58>/Bitwise Operator' */
  boolean_T BitwiseOperator1_n;        /* '<S58>/Bitwise Operator1' */
  boolean_T MeAP_b_PrevIgnCyclRearSts; /* '<S677>/Logical Operator2' */
  boolean_T MeAP_b_PrevIgnCyclFrntSts; /* '<S676>/Logical Operator2' */
  boolean_T MeAP_b_PAMStopCtrlStatus;  /* '<S652>/Logical Operator5' */
  boolean_T MeAP_b_ObjInPath;          /* '<S57>/Rear_ObjectDetection' */
  boolean_T UnitDelay3;                /* '<S660>/Unit Delay3' */
  boolean_T Switch5;                   /* '<S660>/Switch5' */
  boolean_T MeAP_b_DisableRearBrarking;/* '<S651>/Signal Conversion' */
  boolean_T MeAP_b_PAMBrkReqStatus;    /* '<S651>/Switch' */
  boolean_T LogicalOperator2;          /* '<S652>/Logical Operator2' */
  boolean_T LogicalOperator4;          /* '<S652>/Logical Operator4' */
  boolean_T LogicalOperator1;          /* '<S652>/Logical Operator1' */
  boolean_T Switch6_d;                 /* '<S660>/Switch6' */
  boolean_T arcJump;                   /* '<S607>/Logical Operator1' */
  boolean_T UnitDelay_a;               /* '<S607>/Unit Delay' */
  boolean_T UnitDelay_j;               /* '<S647>/Unit Delay' */
  boolean_T Switch5_n;                 /* '<S647>/Switch5' */
  boolean_T arcJump_i;                 /* '<S605>/Logical Operator1' */
  boolean_T UnitDelay_ef;              /* '<S605>/Unit Delay' */
  boolean_T UnitDelay_l;               /* '<S627>/Unit Delay' */
  boolean_T Switch5_l;                 /* '<S627>/Switch5' */
  boolean_T arcJump_p;                 /* '<S606>/Logical Operator1' */
  boolean_T UnitDelay_ow;              /* '<S606>/Unit Delay' */
  boolean_T UnitDelay_m;               /* '<S637>/Unit Delay' */
  boolean_T Switch5_b;                 /* '<S637>/Switch5' */
  boolean_T UnitDelay1_j;              /* '<S482>/Unit Delay1' */
  boolean_T Switch2_l;                 /* '<S559>/Switch2' */
  boolean_T RelationalOperator1;       /* '<S559>/Relational Operator1' */
  boolean_T UnitDelay3_b;              /* '<S562>/Unit Delay3' */
  boolean_T Switch5_m;                 /* '<S562>/Switch5' */
  boolean_T LogicalOperator4_c;        /* '<S482>/Logical Operator4' */
  boolean_T Switch2_d;                 /* '<S558>/Switch2' */
  boolean_T RelationalOperator1_d;     /* '<S558>/Relational Operator1' */
  boolean_T UnitDelay3_j;              /* '<S560>/Unit Delay3' */
  boolean_T Switch5_j;                 /* '<S560>/Switch5' */
  boolean_T MeAP_b_ChimeActvLHR;       /* '<S482>/Switch2' */
  boolean_T MeAP_b_ChimeActvRHR;       /* '<S482>/Switch2' */
  boolean_T RelationalOperator11;      /* '<S480>/Relational Operator11' */
  boolean_T MeAP_b_RearSysFault;       /* '<S480>/Logical Operator1' */
  boolean_T LogicalOperator7;          /* '<S480>/Logical Operator7' */
  boolean_T RelationalOperator1_l;     /* '<S505>/Relational Operator1' */
  boolean_T Switch2_o;                 /* '<S505>/Switch2' */
  boolean_T UnitDelay3_f;              /* '<S507>/Unit Delay3' */
  boolean_T Switch5_c;                 /* '<S507>/Switch5' */
  boolean_T AND;                       /* '<S648>/AND' */
  boolean_T AND_k;                     /* '<S649>/AND' */
  boolean_T Switch6_k;                 /* '<S647>/Switch6' */
  boolean_T AND_o;                     /* '<S638>/AND' */
  boolean_T AND_k2;                    /* '<S639>/AND' */
  boolean_T Switch6_h;                 /* '<S637>/Switch6' */
  boolean_T AND_g;                     /* '<S628>/AND' */
  boolean_T AND_oq;                    /* '<S629>/AND' */
  boolean_T Switch6_j;                 /* '<S627>/Switch6' */
  boolean_T LogicalOperator;           /* '<S582>/Logical Operator' */
  boolean_T UnitDelay_e0;              /* '<S583>/Unit Delay' */
  boolean_T Switch5_a;                 /* '<S583>/Switch5' */
  boolean_T RelationalOperator1_m;     /* '<S564>/Relational Operator1' */
  boolean_T RelationalOperator2;       /* '<S564>/Relational Operator2' */
  boolean_T RelationalOperator3;       /* '<S564>/Relational Operator3' */
  boolean_T RelationalOperator4;       /* '<S564>/Relational Operator4' */
  boolean_T RelationalOperator5;       /* '<S564>/Relational Operator5' */
  boolean_T RelationalOperator1_f;     /* '<S566>/Relational Operator1' */
  boolean_T RelationalOperator1_j;     /* '<S567>/Relational Operator1' */
  boolean_T AND_c;                     /* '<S584>/AND' */
  boolean_T AND_p;                     /* '<S585>/AND' */
  boolean_T Switch6_g;                 /* '<S583>/Switch6' */
  boolean_T Switch6_b;                 /* '<S562>/Switch6' */
  boolean_T Switch6_a;                 /* '<S560>/Switch6' */
  boolean_T RelationalOperator;        /* '<S482>/Relational Operator' */
  boolean_T MeAP_b_IsRearLeftChimeZone5;/* '<S511>/Logical Operator6' */
  boolean_T MeAP_b_IsRearLeftChimeZone6;/* '<S511>/Logical Operator7' */
  boolean_T Switch2_jb;                /* '<S530>/Switch2' */
  boolean_T RelationalOperator1_a;     /* '<S530>/Relational Operator1' */
  boolean_T UnitDelay3_a;              /* '<S531>/Unit Delay3' */
  boolean_T Switch5_k;                 /* '<S531>/Switch5' */
  boolean_T MeAP_b_IsRearLeftChimeZone4;/* '<S511>/Logical Operator5' */
  boolean_T MeAP_b_IsRearLeftChimeZone3;/* '<S511>/Logical Operator4' */
  boolean_T MeAP_b_IsRearLeftChimeZone2;/* '<S511>/Logical Operator2' */
  boolean_T MeAP_b_ChimeActvLHR_Raw;   /* '<S511>/Switch' */
  boolean_T MeAP_b_IsRearRightChimeZone5;/* '<S512>/Logical Operator6' */
  boolean_T MeAP_b_IsRearRightChimeZone6;/* '<S512>/Logical Operator7' */
  boolean_T Switch2_k;                 /* '<S550>/Switch2' */
  boolean_T RelationalOperator1_c;     /* '<S550>/Relational Operator1' */
  boolean_T UnitDelay3_k;              /* '<S551>/Unit Delay3' */
  boolean_T Switch5_h;                 /* '<S551>/Switch5' */
  boolean_T MeAP_b_IsRearRightChimeZone4;/* '<S512>/Logical Operator5' */
  boolean_T MeAP_b_IsRearRightChimeZone3;/* '<S512>/Logical Operator4' */
  boolean_T MeAP_b_IsRearRightChimeZone2;/* '<S512>/Logical Operator2' */
  boolean_T MeAP_b_ChimeActvRHR_Raw;   /* '<S512>/Switch' */
  boolean_T MeAP_b_ChimeActvRHR_Raw_p; /* '<S512>/Switch1' */
  boolean_T MeAP_b_ChimeActvRHR_Raw_c; /* '<S512>/Switch2' */
  boolean_T MeAP_b_ChimeActvRHR_Raw_o; /* '<S512>/Switch3' */
  boolean_T MeAP_b_ChimeActvRHR_Raw_b; /* '<S512>/Switch4' */
  boolean_T MeAP_b_ChimeActvRHR_Raw_c1;/* '<S512>/Switch5' */
  boolean_T MeAP_b_ChimeActvRHR_Raw_a; /* '<S512>/Signal Conversion' */
  boolean_T Switch6_kn;                /* '<S551>/Switch6' */
  boolean_T MeAP_b_ChimeActvLHR_Raw_h; /* '<S511>/Switch1' */
  boolean_T MeAP_b_ChimeActvLHR_Raw_o; /* '<S511>/Switch2' */
  boolean_T MeAP_b_ChimeActvLHR_Raw_j; /* '<S511>/Switch3' */
  boolean_T MeAP_b_ChimeActvLHR_Raw_n; /* '<S511>/Switch4' */
  boolean_T MeAP_b_ChimeActvLHR_Raw_b; /* '<S511>/Switch5' */
  boolean_T MeAP_b_ChimeActvLHR_Raw_p; /* '<S511>/Signal Conversion' */
  boolean_T Switch6_bv;                /* '<S531>/Switch6' */
  boolean_T Switch6_e;                 /* '<S507>/Switch6' */
  boolean_T IgnRun;                    /* '<S480>/Relational Operator17' */
  boolean_T MeAP_b_CarGraphicCond2;    /* '<S336>/Logical Operator1' */
  boolean_T MeAP_b_CarGraphicCond1;    /* '<S335>/Logical Operator1' */
  boolean_T MeAP_b_CarGraphicCond3;    /* '<S337>/Logical Operator1' */
  boolean_T VehKeyDetected;            /* '<S54>/Logical Operator' */
  boolean_T UnitDelay2_nc;             /* '<S54>/Unit Delay2' */
  boolean_T MeAP_b_FT_WipeStartUp;     /* '<S383>/Logical Operator1' */
  boolean_T MeAP_b_RR_WipeStartUp;     /* '<S387>/Logical Operator1' */
  boolean_T MeAP_b_FT_Wipe_RR_WipeStartUp;/* '<S382>/Logical Operator1' */
  boolean_T MeAP_b_FT_SrvStartUp;      /* '<S378>/Logical Operator1' */
  boolean_T MeAP_b_RR_SrvStartUp;      /* '<S384>/Logical Operator1' */
  boolean_T MeAP_b_FT_Srv_RR_SrvStartUp;/* '<S375>/Logical Operator1' */
  boolean_T MeAP_b_FT_Wipe_RR_SrvStartUp;/* '<S380>/Logical Operator1' */
  boolean_T MeAP_b_FT_Srv_RR_WipeStartUp;/* '<S377>/Logical Operator1' */
  boolean_T MeAP_b_RR_TrlrStartUp;     /* '<S386>/Logical Operator1' */
  boolean_T MeAP_b_FT_Srv_RR_TrlrStartUp;/* '<S376>/Logical Operator1' */
  boolean_T MeAP_b_FT_Wipe_RR_TrlrStartUp;/* '<S381>/Logical Operator1' */
  boolean_T MeAP_b_Sys_FailStartUp;    /* '<S388>/Logical Operator1' */
  boolean_T MeAP_b_Sys_Temp_NA_StartUp;/* '<S389>/Logical Operator1' */
  boolean_T MeAP_b_FT_Temp_NA_StartUp; /* '<S379>/Logical Operator1' */
  boolean_T MeAP_b_RR_Temp_NA_StartUp; /* '<S385>/Logical Operator1' */
  boolean_T UnitDelay3_l;              /* '<S462>/Unit Delay3' */
  boolean_T Switch5_jw;                /* '<S462>/Switch5' */
  boolean_T MeAP_b_SpeedTooHigh;       /* '<S453>/Logical Operator1' */
  boolean_T UnitDelay1_k;              /* '<S54>/Unit Delay1' */
  boolean_T MeAP_b_RearSwitchPressed;  /* '<S248>/Signal Conversion' */
  boolean_T MeAP_b_CarGraphicCond4;    /* '<S338>/Logical Operator1' */
  boolean_T MeAP_b_IDLE_HMI;           /* '<S262>/Logical Operator' */
  boolean_T MeAP_b_StrtUpPopUp;        /* '<S244>/Unit Delay3' */
  boolean_T MeAP_b_PopUpHold;          /* '<S244>/Logical Operator1' */
  boolean_T IsTimerRunning;            /* '<S260>/Logical Operator4' */
  boolean_T MeAP_b_RR_TrlrBtnPress;    /* '<S275>/Logical Operator1' */
  boolean_T MeAP_b_Sys_Temp_NA_BtnPress;/* '<S277>/Logical Operator1' */
  boolean_T MeAP_b_RR_FailBtnPress;    /* '<S273>/Logical Operator1' */
  boolean_T MeAP_b_RR_SrvBtnPress;     /* '<S274>/Logical Operator1' */
  boolean_T MeAP_b_RR_WipeBtnPress;    /* '<S276>/Logical Operator1' */
  boolean_T MeAP_b_FT_FailBtnPress;    /* '<S270>/Logical Operator1' */
  boolean_T MeAP_b_FT_SrvBtnPress;     /* '<S271>/Logical Operator1' */
  boolean_T MeAP_b_FT_WipeBtnPress;    /* '<S272>/Logical Operator1' */
  boolean_T RelationalOperator_d;      /* '<S54>/Relational Operator' */
  boolean_T RelationalOperator_m;      /* '<S262>/Relational Operator' */
  boolean_T Switch6_bd;                /* '<S462>/Switch6' */
  boolean_T MeAP_b_BtnPrssPopUp;       /* '<S54>/PopUpPriority1' */
  boolean_T MeAP_b_StrtUpPopUp_l;      /* '<S54>/PopUpPriority1' */
  boolean_T LogicalOperator1_l;        /* '<S194>/Logical Operator1' */
  boolean_T UnitDelay_km;              /* '<S194>/Unit Delay' */
  boolean_T UnitDelay_cf;              /* '<S225>/Unit Delay' */
  boolean_T Switch5_ct;                /* '<S225>/Switch5' */
  boolean_T MeAP_e_FiltdGearP2R;       /* '<S79>/Logical Operator1' */
  boolean_T MeAP_e_FiltdGearD2R;       /* '<S79>/Logical Operator2' */
  boolean_T MeAP_e_FiltdGearToDrive;   /* '<S79>/Relational Operator3' */
  boolean_T LogicalOperator1_lz;       /* '<S195>/Logical Operator1' */
  boolean_T UnitDelay_i;               /* '<S195>/Unit Delay' */
  boolean_T UnitDelay_o4;              /* '<S235>/Unit Delay' */
  boolean_T Switch5_a0;                /* '<S235>/Switch5' */
  boolean_T LogicalOperator1_l5;       /* '<S193>/Logical Operator1' */
  boolean_T UnitDelay_bl;              /* '<S193>/Unit Delay' */
  boolean_T UnitDelay_ka;              /* '<S215>/Unit Delay' */
  boolean_T Switch5_ht;                /* '<S215>/Switch5' */
  boolean_T UnitDelay1_h;              /* '<S81>/Unit Delay1' */
  boolean_T Switch2_k2;                /* '<S151>/Switch2' */
  boolean_T RelationalOperator1_p;     /* '<S151>/Relational Operator1' */
  boolean_T UnitDelay3_lo;             /* '<S154>/Unit Delay3' */
  boolean_T Switch5_jv;                /* '<S154>/Switch5' */
  boolean_T LogicalOperator4_i;        /* '<S81>/Logical Operator4' */
  boolean_T Switch2_m;                 /* '<S150>/Switch2' */
  boolean_T RelationalOperator1_d5;    /* '<S150>/Relational Operator1' */
  boolean_T UnitDelay3_h;              /* '<S152>/Unit Delay3' */
  boolean_T Switch5_nn;                /* '<S152>/Switch5' */
  boolean_T MeAP_b_ChimeActvLHF;       /* '<S81>/Switch2' */
  boolean_T MeAP_b_ChimeActvRHF;       /* '<S81>/Switch2' */
  boolean_T RelationalOperator4_e;     /* '<S78>/Relational Operator4' */
  boolean_T MeAP_b_FrntSysFault;       /* '<S78>/Logical Operator1' */
  boolean_T LogicalOperator7_i;        /* '<S78>/Logical Operator7' */
  boolean_T RelationalOperator1_jd;    /* '<S104>/Relational Operator1' */
  boolean_T Switch2_oo;                /* '<S104>/Switch2' */
  boolean_T UnitDelay3_g;              /* '<S106>/Unit Delay3' */
  boolean_T Switch5_no;                /* '<S106>/Switch5' */
  boolean_T AND_d;                     /* '<S236>/AND' */
  boolean_T AND_i;                     /* '<S237>/AND' */
  boolean_T Switch6_c;                 /* '<S235>/Switch6' */
  boolean_T AND_n;                     /* '<S226>/AND' */
  boolean_T AND_e;                     /* '<S227>/AND' */
  boolean_T Switch6_gd;                /* '<S225>/Switch6' */
  boolean_T AND_a;                     /* '<S216>/AND' */
  boolean_T AND_dj;                    /* '<S217>/AND' */
  boolean_T Switch6_o;                 /* '<S215>/Switch6' */
  boolean_T RelationalOperator3_o;     /* '<S156>/Relational Operator3' */
  boolean_T RelationalOperator2_a;     /* '<S156>/Relational Operator2' */
  boolean_T RelationalOperator1_py;    /* '<S156>/Relational Operator1' */
  boolean_T LogicalOperator_k;         /* '<S170>/Logical Operator' */
  boolean_T UnitDelay_dh;              /* '<S171>/Unit Delay' */
  boolean_T Switch5_a3;                /* '<S171>/Switch5' */
  boolean_T RelationalOperator1_cr;    /* '<S158>/Relational Operator1' */
  boolean_T RelationalOperator1_i;     /* '<S159>/Relational Operator1' */
  boolean_T AND_kt;                    /* '<S172>/AND' */
  boolean_T AND_pp;                    /* '<S173>/AND' */
  boolean_T Switch6_l;                 /* '<S171>/Switch6' */
  boolean_T Switch6_p;                 /* '<S154>/Switch6' */
  boolean_T Switch6_ab;                /* '<S152>/Switch6' */
  boolean_T RelationalOperator_l;      /* '<S81>/Relational Operator' */
  boolean_T MeAP_b_IsLeftChimeZone2;   /* '<S116>/Logical Operator2' */
  boolean_T MeAP_b_ChimeActvLHF_d;     /* '<S116>/Switch' */
  boolean_T MeAP_b_IsLeftChimeZone2_a; /* '<S117>/Logical Operator2' */
  boolean_T MeAP_b_ChimeActvRHF_m;     /* '<S117>/Switch' */
  boolean_T MeAP_b_VehMoving;          /* '<S121>/Logical Operator5' */
  boolean_T FrontChimeTimerStart;      /* '<S119>/Logical Operator' */
  boolean_T MeAP_b_ChimeActvLHF_h;     /* '<S115>/Logical Operator1' */
  boolean_T MeAP_b_ChimeActvRHF_k;     /* '<S115>/Logical Operator3' */
  boolean_T MeAP_b_ChimeActvRHF_e;     /* '<S117>/Switch1' */
  boolean_T MeAP_b_ChimeActvLHF_b;     /* '<S116>/Switch1' */
  boolean_T Switch6_e0;                /* '<S106>/Switch6' */
  boolean_T IgnRun_i;                  /* '<S78>/Relational Operator17' */
  boolean_T MeAP_b_ChimeActv_LHF;      /* '<S51>/Switch' */
  boolean_T MeAP_b_ChimeActv_LHF_g;    /* '<S51>/Signal Conversion' */
  boolean_T MeAP_b_ChimeActv_RHF;      /* '<S51>/Switch' */
  boolean_T MeAP_b_ChimeActv_RHF_o;    /* '<S51>/Signal Conversion1' */
  boolean_T MeAP_b_ChimeActv_LHR;      /* '<S51>/Switch' */
  boolean_T MeAP_b_ChimeActv_LHR_f;    /* '<S51>/Signal Conversion2' */
  boolean_T MeAP_b_ChimeActv_RHR;      /* '<S51>/Switch' */
  boolean_T MeAP_b_ChimeActv_RHR_n;    /* '<S51>/Signal Conversion3' */
  boolean_T MeAP_b_RPAwithBrkStatus;   /* '<S5>/APA_StateMachine' */
  boolean_T LogicalOperator11;         /* '<S11>/Logical Operator11' */
  boolean_T LogicalOperator2_e;        /* '<S16>/Logical Operator2' */
  boolean_T Delay1;                    /* '<S16>/Delay1' */
  boolean_T MeAP_b_FPAEnablingCond;    /* '<S16>/Switch1' */
  boolean_T LogicalOperator2_ex;       /* '<S17>/Logical Operator2' */
  boolean_T Delay1_h;                  /* '<S17>/Delay1' */
  boolean_T MeAP_b_TrlrNotConnected;   /* '<S15>/Logical Operator5' */
  boolean_T MeAP_b_RPAEnablingCond;    /* '<S17>/Switch1' */
  boolean_T Delay;                     /* '<S17>/Delay' */
  boolean_T Delay_g;                   /* '<S16>/Delay' */
  boolean_T UnitDelay1_hq;             /* '<S22>/Unit Delay1' */
  boolean_T reset;                     /* '<S22>/Logical Operator' */
  boolean_T LogicalOperator8;          /* '<S22>/Logical Operator8' */
  boolean_T UnitDelay1_mb;             /* '<S27>/Unit Delay1' */
  boolean_T reset_h;                   /* '<S27>/Logical Operator' */
  boolean_T LogicalOperator8_p;        /* '<S27>/Logical Operator8' */
  boolean_T LogicalOperator4_cj;       /* '<S17>/Logical Operator4' */
  boolean_T LogicalOperator5;          /* '<S17>/Logical Operator5' */
  boolean_T LogicalOperator4_k;        /* '<S16>/Logical Operator4' */
  boolean_T LogicalOperator7_g;        /* '<S16>/Logical Operator7' */
  boolean_T BitwiseOperator1_j;        /* '<S7>/Bitwise Operator1' */
  boolean_T EnableRearBraking;         /* '<S651>/Relational Operator' */
  boolean_T RelationalOperator3_h;     /* '<S607>/Relational Operator3' */
  boolean_T RelationalOperator1_mw;    /* '<S607>/Relational Operator1' */
  boolean_T RelationalOperator5_b;     /* '<S607>/Relational Operator5' */
  boolean_T RelationalOperator3_i;     /* '<S606>/Relational Operator3' */
  boolean_T RelationalOperator1_lp;    /* '<S606>/Relational Operator1' */
  boolean_T RelationalOperator5_i;     /* '<S606>/Relational Operator5' */
  boolean_T RelationalOperator3_a;     /* '<S605>/Relational Operator3' */
  boolean_T RelationalOperator1_e;     /* '<S605>/Relational Operator1' */
  boolean_T RelationalOperator5_f;     /* '<S605>/Relational Operator5' */
  boolean_T LogicalOperator8_n;        /* '<S559>/Logical Operator8' */
  boolean_T RelationalOperator_e;      /* '<S559>/Relational Operator' */
  boolean_T LogicalOperator8_pb;       /* '<S558>/Logical Operator8' */
  boolean_T RelationalOperator_f;      /* '<S558>/Relational Operator' */
  boolean_T LogicalOperator8_e;        /* '<S550>/Logical Operator8' */
  boolean_T RelationalOperator_n;      /* '<S550>/Relational Operator' */
  boolean_T LogicalOperator8_j;        /* '<S530>/Logical Operator8' */
  boolean_T RelationalOperator_fq;     /* '<S530>/Relational Operator' */
  boolean_T LogicalOperator8_c;        /* '<S505>/Logical Operator8' */
  boolean_T RelationalOperator_k;      /* '<S505>/Relational Operator' */
  boolean_T RelationalOperator3_f;     /* '<S480>/Relational Operator3' */
  boolean_T RelationalOperator14;      /* '<S480>/Relational Operator14' */
  boolean_T LogicalOperator5_h;        /* '<S480>/Logical Operator5' */
  boolean_T RelationalOperator9;       /* '<S480>/Relational Operator9' */
  boolean_T LogicalOperator13;         /* '<S480>/Logical Operator13' */
  boolean_T RelationalOperator8;       /* '<S480>/Relational Operator8' */
  boolean_T LogicalOperator1_k;        /* '<S55>/Logical Operator1' */
  boolean_T LogicalOperator4_j;        /* '<S55>/Logical Operator4' */
  boolean_T LogicalOperator3;          /* '<S55>/Logical Operator3' */
  boolean_T LogicalOperator1_m;        /* '<S467>/Logical Operator1' */
  boolean_T LogicalOperator1_i;        /* '<S465>/Logical Operator1' */
  boolean_T LogicalOperator1_lf;       /* '<S463>/Logical Operator1' */
  boolean_T RelationalOperator9_d;     /* '<S453>/Relational Operator9' */
  boolean_T RelationalOperator_o;      /* '<S244>/Relational Operator' */
  boolean_T RelationalOperator2_ae;    /* '<S244>/Relational Operator2' */
  boolean_T LogicalOperator2_i;        /* '<S53>/Logical Operator2' */
  boolean_T RelationalOperator3_e;     /* '<S195>/Relational Operator3' */
  boolean_T RelationalOperator1_k;     /* '<S195>/Relational Operator1' */
  boolean_T RelationalOperator5_d;     /* '<S195>/Relational Operator5' */
  boolean_T RelationalOperator3_g;     /* '<S194>/Relational Operator3' */
  boolean_T RelationalOperator1_mwk;   /* '<S194>/Relational Operator1' */
  boolean_T RelationalOperator5_c;     /* '<S194>/Relational Operator5' */
  boolean_T RelationalOperator3_p;     /* '<S193>/Relational Operator3' */
  boolean_T RelationalOperator1_ip;    /* '<S193>/Relational Operator1' */
  boolean_T RelationalOperator5_k;     /* '<S193>/Relational Operator5' */
  boolean_T LogicalOperator8_g;        /* '<S151>/Logical Operator8' */
  boolean_T RelationalOperator_dc;     /* '<S151>/Relational Operator' */
  boolean_T LogicalOperator8_d;        /* '<S150>/Logical Operator8' */
  boolean_T RelationalOperator_m1;     /* '<S150>/Relational Operator' */
  boolean_T RelationalOperator5_km;    /* '<S118>/Relational Operator5' */
  boolean_T RelationalOperator4_l;     /* '<S118>/Relational Operator4' */
  boolean_T LogicalOperator8_dy;       /* '<S104>/Logical Operator8' */
  boolean_T RelationalOperator_oc;     /* '<S104>/Relational Operator' */
  boolean_T RelationalOperator14_i;    /* '<S78>/Relational Operator14' */
  boolean_T RelationalOperator3_n;     /* '<S78>/Relational Operator3' */
  boolean_T RelationalOperator9_c;     /* '<S78>/Relational Operator9' */
  boolean_T LogicalOperator13_k;       /* '<S78>/Logical Operator13' */
  boolean_T RelationalOperator_j;      /* '<S27>/Relational Operator' */
  boolean_T RelationalOperator_mv;     /* '<S22>/Relational Operator' */
  boolean_T AND_ne;                    /* '<S607>/AND' */
  boolean_T LogicalOperator2_b;        /* '<S607>/Logical Operator2' */
  boolean_T LogicalOperator_i;         /* '<S607>/Logical Operator' */
  boolean_T AND_ag;                    /* '<S606>/AND' */
  boolean_T LogicalOperator2_f;        /* '<S606>/Logical Operator2' */
  boolean_T LogicalOperator_f;         /* '<S606>/Logical Operator' */
  boolean_T AND_og;                    /* '<S605>/AND' */
  boolean_T LogicalOperator2_d;        /* '<S605>/Logical Operator2' */
  boolean_T LogicalOperator_d;         /* '<S605>/Logical Operator' */
  boolean_T ElapseTimer;               /* '<S509>/Logical Operator3' */
  boolean_T RelationalOperator6;       /* '<S480>/Relational Operator6' */
  boolean_T ElapseTimer_h;             /* '<S467>/Logical Operator3' */
  boolean_T ElapseTimer_e;             /* '<S465>/Logical Operator3' */
  boolean_T ElapseTimer_hg;            /* '<S463>/Logical Operator3' */
  boolean_T ElapseTimer_n;             /* '<S260>/Logical Operator3' */
  boolean_T AND_pf;                    /* '<S195>/AND' */
  boolean_T LogicalOperator2_be;       /* '<S195>/Logical Operator2' */
  boolean_T LogicalOperator_j;         /* '<S195>/Logical Operator' */
  boolean_T AND_j;                     /* '<S194>/AND' */
  boolean_T LogicalOperator2_dn;       /* '<S194>/Logical Operator2' */
  boolean_T LogicalOperator_e;         /* '<S194>/Logical Operator' */
  boolean_T AND_it;                    /* '<S193>/AND' */
  boolean_T LogicalOperator2_j;        /* '<S193>/Logical Operator2' */
  boolean_T LogicalOperator_l;         /* '<S193>/Logical Operator' */
  boolean_T ElapseTimer_f;             /* '<S120>/Logical Operator3' */
  boolean_T ElapseTimer_p;             /* '<S108>/Logical Operator3' */
  boolean_T RelationalOperator6_k;     /* '<S78>/Relational Operator6' */
  boolean_T LogicalOperator15;         /* '<S78>/Logical Operator15' */
  boolean_T LogicalOperator_lt;        /* '<S40>/Logical Operator' */
  boolean_T LogicalOperator_ev;        /* '<S39>/Logical Operator' */
  boolean_T LogicalOperator3_m;        /* '<S14>/Logical Operator3' */
  boolean_T LogicalOperator6;          /* '<S14>/Logical Operator6' */
  boolean_T LogicalOperator1_is;       /* '<S260>/Logical Operator1' */
  boolean_T LogicalOperator1_f;        /* '<S120>/Logical Operator1' */
  boolean_T LogicalOperator10;         /* '<S480>/Logical Operator10' */
  boolean_T LogicalOperator9;          /* '<S480>/Logical Operator9' */
  boolean_T LogicalOperator3_n;        /* '<S480>/Logical Operator3' */
  boolean_T LogicalOperator10_n;       /* '<S78>/Logical Operator10' */
  boolean_T LogicalOperator9_h;        /* '<S78>/Logical Operator9' */
  boolean_T LogicalOperator3_e;        /* '<S78>/Logical Operator3' */
  boolean_T RelationalOperator_jv;     /* '<S9>/Relational Operator' */
  boolean_T LogicalOperator1_d;        /* '<S9>/Logical Operator1' */
  boolean_T RelationalOperator8_e;     /* '<S652>/Relational Operator8' */
  boolean_T RelationalOperator6_p;     /* '<S272>/Relational Operator6' */
  boolean_T RelationalOperator7;       /* '<S652>/Relational Operator7' */
  boolean_T MeAP_b_FrontSwitchPressed; /* '<S247>/Signal Conversion' */
  boolean_T RelationalOperator8_er;    /* '<S272>/Relational Operator8' */
  boolean_T Compare_k;                 /* '<S664>/Compare' */
  boolean_T RelationalOperator2_j;     /* '<S652>/Relational Operator2' */
  boolean_T RelationalOperator1_e1;    /* '<S652>/Relational Operator1' */
  boolean_T RelationalOperator4_m;     /* '<S272>/Relational Operator4' */
  boolean_T RelationalOperator1_mc;    /* '<S272>/Relational Operator1' */
  boolean_T LogicalOperator2_n;        /* '<S272>/Logical Operator2' */
} B_SWC_APA_c_T;

#endif                                 /*SWC_APA_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'SWC_APA' */
#ifndef SWC_APA_MDLREF_HIDE_CHILD_

typedef struct {
  real_T UnitDelay2_DSTATE;            /* '<S559>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_b;          /* '<S558>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_f;          /* '<S505>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_d;          /* '<S151>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_k;          /* '<S150>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_c;          /* '<S104>/Unit Delay2' */
  real_T Subtract_DWORK1;              /* '<S559>/Subtract' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S156>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S156>/Scope1' */

  real32_T UnitDelay_DSTATE;           /* '<S651>/Unit Delay' */
  real32_T UnitDelay_DSTATE_a;         /* '<S661>/Unit Delay' */
  TeVBII_e_CmdIgnSts UnitDelay1_DSTATE;/* '<S58>/Unit Delay1' */
  TeVBII_e_PamChimeVol UnitDelay_DSTATE_p;/* '<S482>/Unit Delay' */
  TeVBII_e_PamChimeVol UnitDelay_DSTATE_j;/* '<S81>/Unit Delay' */
  TeAP_e_FiltdGearState UnitDelay2_DSTATE_g;/* '<S79>/Unit Delay2' */
  TeAP_e_FiltdGearState UnitDelay1_DSTATE_i;/* '<S79>/Unit Delay1' */
  TeAP_e_PAMOffStatus2BT UnitDelay_DSTATE_m;/* '<S685>/Unit Delay' */
  TeAP_e_PAMLedCtrlStatus UnitDelay1_DSTATE_e;/* '<S480>/Unit Delay1' */
  TeAP_e_PAMLedCtrlStatus UnitDelay1_DSTATE_h;/* '<S78>/Unit Delay1' */
  TeAP_e_PAMPopUpReq UnitDelay2_DSTATE_kd;/* '<S244>/Unit Delay2' */
  real32_T Subtract_DWORK1_l;          /* '<S564>/Subtract' */
  uint32_T prev_AlertCHR;              /* '<S565>/DNNCheck' */
  uint32_T prev_AlertCHF;              /* '<S157>/DNNCheck' */
  TeAP_e_Alert LastChanged_Alert_Raw;  /* '<S484>/AlertFilterRHR' */
  TeAP_e_Alert MeAP_e_AlertRHR_Raw_prev;/* '<S484>/AlertFilterRHR' */
  TeAP_e_Alert MeAP_e_AlertRHR_Raw_start;/* '<S484>/AlertFilterRHR' */
  TeAP_e_Alert LastChanged_Alert_Raw_o;/* '<S484>/AlertFilterLHR' */
  TeAP_e_Alert MeAP_e_AlertLHR_Raw_prev;/* '<S484>/AlertFilterLHR' */
  TeAP_e_Alert MeAP_e_AlertLHR_Raw_start;/* '<S484>/AlertFilterLHR' */
  TeAP_e_Alert LastChanged_Alert_Raw_oq;/* '<S484>/AlertFilterCHR' */
  TeAP_e_Alert MeAP_e_AlertCHR_Raw_prev;/* '<S484>/AlertFilterCHR' */
  TeAP_e_Alert MeAP_e_AlertCHR_Raw_start;/* '<S484>/AlertFilterCHR' */
  TeAP_e_Alert LastChanged_Alert_Raw_a;/* '<S83>/AlertFilterRHF' */
  TeAP_e_Alert MeAP_e_AlertRHF_Raw_prev;/* '<S83>/AlertFilterRHF' */
  TeAP_e_Alert MeAP_e_AlertRHF_Raw_start;/* '<S83>/AlertFilterRHF' */
  TeAP_e_Alert LastChanged_Alert_Raw_i;/* '<S83>/AlertFilterLHF' */
  TeAP_e_Alert MeAP_e_AlertLHF_Raw_prev;/* '<S83>/AlertFilterLHF' */
  TeAP_e_Alert MeAP_e_AlertLHF_Raw_start;/* '<S83>/AlertFilterLHF' */
  TeAP_e_Alert LastChanged_Alert_Raw_c;/* '<S83>/AlertFilterCHF' */
  TeAP_e_Alert MeAP_e_AlertCHF_Raw_prev;/* '<S83>/AlertFilterCHF' */
  TeAP_e_Alert MeAP_e_AlertCHF_Raw_start;/* '<S83>/AlertFilterCHF' */
  uint16_T UnitDelay1_DSTATE_k;        /* '<S607>/Unit Delay1' */
  uint16_T UnitDelay1_DSTATE_f;        /* '<S605>/Unit Delay1' */
  uint16_T UnitDelay1_DSTATE_h5;       /* '<S606>/Unit Delay1' */
  uint16_T UnitDelay2_DSTATE_j;        /* '<S509>/Unit Delay2' */
  uint16_T UnitDelay_DSTATE_i;         /* '<S648>/Unit Delay' */
  uint16_T UnitDelay_DSTATE_g;         /* '<S638>/Unit Delay' */
  uint16_T UnitDelay_DSTATE_b;         /* '<S628>/Unit Delay' */
  uint16_T UnitDelay_DSTATE_o;         /* '<S584>/Unit Delay' */
  uint16_T UnitDelay2_DSTATE_go;       /* '<S530>/Unit Delay2' */
  uint16_T UnitDelay2_DSTATE_i;        /* '<S550>/Unit Delay2' */
  uint16_T UnitDelay2_DSTATE_p;        /* '<S467>/Unit Delay2' */
  uint16_T UnitDelay2_DSTATE_kn;       /* '<S463>/Unit Delay2' */
  uint16_T UnitDelay2_DSTATE_ib;       /* '<S465>/Unit Delay2' */
  uint16_T UnitDelay2_DSTATE_ig;       /* '<S260>/Unit Delay2' */
  uint16_T UnitDelay1_DSTATE_g;        /* '<S194>/Unit Delay1' */
  uint16_T UnitDelay1_DSTATE_p;        /* '<S195>/Unit Delay1' */
  uint16_T UnitDelay1_DSTATE_pp;       /* '<S193>/Unit Delay1' */
  uint16_T UnitDelay2_DSTATE_gt;       /* '<S108>/Unit Delay2' */
  uint16_T UnitDelay_DSTATE_bs;        /* '<S236>/Unit Delay' */
  uint16_T UnitDelay_DSTATE_a2;        /* '<S226>/Unit Delay' */
  uint16_T UnitDelay_DSTATE_f;         /* '<S216>/Unit Delay' */
  uint16_T UnitDelay_DSTATE_fz;        /* '<S172>/Unit Delay' */
  uint16_T UnitDelay2_DSTATE_knz;      /* '<S120>/Unit Delay2' */
  uint16_T UnitDelay2_DSTATE_bf;       /* '<S22>/Unit Delay2' */
  uint16_T UnitDelay2_DSTATE_jp;       /* '<S27>/Unit Delay2' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S7>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_k;        /* '<S58>/Unit Delay' */
  boolean_T UnitDelay2_DSTATE_l;       /* '<S58>/Unit Delay2' */
  boolean_T UnitDelay_DSTATE_gj;       /* '<S57>/Unit Delay' */
  boolean_T Delay_DSTATE;              /* '<S652>/Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S654>/Delay Input1' */
  boolean_T UnitDelay3_DSTATE;         /* '<S660>/Unit Delay3' */
  boolean_T UnitDelay2_DSTATE_m;       /* '<S607>/Unit Delay2' */
  boolean_T UnitDelay_DSTATE_ej;       /* '<S607>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_go;       /* '<S647>/Unit Delay' */
  boolean_T UnitDelay2_DSTATE_o;       /* '<S605>/Unit Delay2' */
  boolean_T UnitDelay_DSTATE_c;        /* '<S605>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_a4;       /* '<S627>/Unit Delay' */
  boolean_T UnitDelay2_DSTATE_jh;      /* '<S606>/Unit Delay2' */
  boolean_T UnitDelay_DSTATE_ke;       /* '<S606>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_p4;       /* '<S637>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_j;       /* '<S482>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_fa;      /* '<S563>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_e5;      /* '<S559>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE_a;       /* '<S562>/Unit Delay3' */
  boolean_T UnitDelay1_DSTATE_m;       /* '<S561>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_n;       /* '<S558>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE_f;       /* '<S560>/Unit Delay3' */
  boolean_T UnitDelay1_DSTATE_et;      /* '<S510>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_o;       /* '<S508>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_hk;      /* '<S505>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE_a1;      /* '<S507>/Unit Delay3' */
  boolean_T UnitDelay_DSTATE_mt;       /* '<S649>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_l;        /* '<S639>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_e4;       /* '<S629>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_m0;       /* '<S583>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_i5;       /* '<S585>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_a;       /* '<S532>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_d;       /* '<S530>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE_h;       /* '<S531>/Unit Delay3' */
  boolean_T UnitDelay1_DSTATE_mi;      /* '<S552>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_l;       /* '<S550>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE_o;       /* '<S551>/Unit Delay3' */
  boolean_T UnitDelay_DSTATE_gc;       /* '<S54>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_ko;      /* '<S468>/Unit Delay1' */
  boolean_T UnitDelay2_DSTATE_pf;      /* '<S54>/Unit Delay2' */
  boolean_T UnitDelay3_DSTATE_m;       /* '<S462>/Unit Delay3' */
  boolean_T UnitDelay1_DSTATE_jm;      /* '<S464>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_dv;      /* '<S54>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_oc;      /* '<S466>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE_g;       /* '<S244>/Unit Delay3' */
  boolean_T UnitDelay1_DSTATE_b;       /* '<S244>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_pn;      /* '<S261>/Unit Delay1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S310>/Delay Input1' */
  boolean_T UnitDelay2_DSTATE_e;       /* '<S194>/Unit Delay2' */
  boolean_T UnitDelay_DSTATE_pz;       /* '<S194>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_ge;       /* '<S225>/Unit Delay' */
  boolean_T UnitDelay2_DSTATE_jk;      /* '<S195>/Unit Delay2' */
  boolean_T UnitDelay_DSTATE_fc;       /* '<S195>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_mc;       /* '<S235>/Unit Delay' */
  boolean_T UnitDelay2_DSTATE_kc;      /* '<S193>/Unit Delay2' */
  boolean_T UnitDelay_DSTATE_bq;       /* '<S193>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_av;       /* '<S215>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_jd;      /* '<S81>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_lo;      /* '<S155>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_mh;      /* '<S151>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE_hm;      /* '<S154>/Unit Delay3' */
  boolean_T UnitDelay1_DSTATE_m3;      /* '<S153>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_jf;      /* '<S150>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE_h0;      /* '<S152>/Unit Delay3' */
  boolean_T UnitDelay1_DSTATE_bv;      /* '<S109>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_dv3;     /* '<S107>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_dk;      /* '<S104>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE_ar;      /* '<S106>/Unit Delay3' */
  boolean_T UnitDelay_DSTATE_jt;       /* '<S237>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_or;       /* '<S227>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_jk;       /* '<S217>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_gq;       /* '<S171>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_n;        /* '<S173>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_nm;      /* '<S126>/Unit Delay1' */
  boolean_T Delay1_DSTATE;             /* '<S16>/Delay1' */
  boolean_T UnitDelay_DSTATE_pa;       /* '<S21>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_bh;       /* '<S22>/Unit Delay' */
  boolean_T Delay1_DSTATE_d;           /* '<S17>/Delay1' */
  boolean_T UnitDelay_DSTATE_em;       /* '<S26>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_jj;       /* '<S27>/Unit Delay' */
  boolean_T Delay_DSTATE_l;            /* '<S17>/Delay' */
  boolean_T Delay_DSTATE_f;            /* '<S16>/Delay' */
  boolean_T UnitDelay1_DSTATE_fy;      /* '<S22>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_c;       /* '<S27>/Unit Delay1' */
  uint8_T icLoad;                      /* '<S652>/Delay' */
  uint8_T is_active_c16_SWC_APA;       /* '<S653>/RearDistHold' */
  uint8_T RearDistHoldCount;           /* '<S653>/RearDistHold' */
  uint8_T RearDistHoldCount1;          /* '<S653>/RearDistHold' */
  uint8_T is_active_c13_SWC_APA;       /* '<S484>/AlertFilterRHR' */
  uint8_T is_c13_SWC_APA;              /* '<S484>/AlertFilterRHR' */
  uint8_T count;                       /* '<S484>/AlertFilterRHR' */
  uint8_T is_active_c12_SWC_APA;       /* '<S484>/AlertFilterLHR' */
  uint8_T is_c12_SWC_APA;              /* '<S484>/AlertFilterLHR' */
  uint8_T count_o;                     /* '<S484>/AlertFilterLHR' */
  uint8_T is_active_c11_SWC_APA;       /* '<S484>/AlertFilterCHR' */
  uint8_T is_c11_SWC_APA;              /* '<S484>/AlertFilterCHR' */
  uint8_T count_of;                    /* '<S484>/AlertFilterCHR' */
  uint8_T MeAP_b_HighPointsPresentRear_prev;/* '<S565>/DNNCheck' */
  uint8_T MeAP_b_HighPointsPresentRear_start;/* '<S565>/DNNCheck' */
  uint8_T is_active_c14_SWC_APA;       /* '<S83>/AlertFilterRHF' */
  uint8_T is_c14_SWC_APA;              /* '<S83>/AlertFilterRHF' */
  uint8_T count_f;                     /* '<S83>/AlertFilterRHF' */
  uint8_T is_active_c9_SWC_APA;        /* '<S83>/AlertFilterLHF' */
  uint8_T is_c9_SWC_APA;               /* '<S83>/AlertFilterLHF' */
  uint8_T count_b;                     /* '<S83>/AlertFilterLHF' */
  uint8_T is_active_c7_SWC_APA;        /* '<S83>/AlertFilterCHF' */
  uint8_T is_c7_SWC_APA;               /* '<S83>/AlertFilterCHF' */
  uint8_T count_k;                     /* '<S83>/AlertFilterCHF' */
  uint8_T IsDnnHeightLow;              /* '<S157>/DNNCheck' */
  uint8_T IsDnnHeightLow_prev;         /* '<S157>/DNNCheck' */
  uint8_T IsDnnHeightLow_start;        /* '<S157>/DNNCheck' */
  uint8_T MeAP_b_HighPointsPresentFront_prev;/* '<S157>/DNNCheck' */
  uint8_T MeAP_b_HighPointsPresentFront_start;/* '<S157>/DNNCheck' */
  uint8_T is_active_c25_SWC_APA;       /* '<S5>/APA_StateMachine' */
  uint8_T is_PA_FAULT_STATUS;          /* '<S5>/APA_StateMachine' */
  uint8_T is_PA_FEAT_STATUS;           /* '<S5>/APA_StateMachine' */
  uint8_T is_ON;                       /* '<S5>/APA_StateMachine' */
  uint8_T is_FPA_ACTIVE;               /* '<S5>/APA_StateMachine' */
  uint8_T is_FPA_Degradded;            /* '<S5>/APA_StateMachine' */
  uint8_T is_RPA_ACTIVE;               /* '<S5>/APA_StateMachine' */
  uint8_T is_RPA_Degradded;            /* '<S5>/APA_StateMachine' */
  uint8_T icLoad_e;                    /* '<S16>/Delay1' */
  uint8_T icLoad_h;                    /* '<S17>/Delay1' */
  boolean_T RearDistHold;              /* '<S653>/RearDistHold' */
  boolean_T RearDistHold1;             /* '<S653>/RearDistHold' */
  boolean_T doneDoubleBufferReInit;    /* '<S565>/DNNCheck' */
  boolean_T DNN_Latch;                 /* '<S565>/DNNCheck' */
  boolean_T IsDnnHeightLow_f;          /* '<S565>/DNNCheck' */
  boolean_T IsDnnHeightLow_prev_m;     /* '<S565>/DNNCheck' */
  boolean_T IsDnnHeightLow_start_f;    /* '<S565>/DNNCheck' */
  boolean_T doneDoubleBufferReInit_o;  /* '<S157>/DNNCheck' */
  boolean_T DNN_Latch_d;               /* '<S157>/DNNCheck' */
  boolean_T RPA_GraphicAlertGen_MODE;  /* '<S56>/RPA_GraphicAlertGen' */
  boolean_T RPA_ChimeAlertGen_MODE;    /* '<S56>/RPA_ChimeAlertGen' */
  boolean_T FPA_GraphicAlertGen_MODE;  /* '<S52>/FPA_GraphicAlertGen' */
  boolean_T FPA_ChimeAlertGen_MODE;    /* '<S52>/FPA_ChimeAlertGen' */
} DW_SWC_APA_f_T;

#endif                                 /*SWC_APA_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for model 'SWC_APA' */
#ifndef SWC_APA_MDLREF_HIDE_CHILD_

typedef struct {
  const TeAP_e_RearSnsrStatus Switch2; /* '<S40>/Switch2' */
  const TeAP_e_FrntSnsrStatus Switch2_h;/* '<S39>/Switch2' */
  const uint8_T DataTypeConversion2;   /* '<S250>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_m; /* '<S251>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_l; /* '<S252>/Data Type Conversion2' */
  const boolean_T Constant5;           /* '<S2>/Constant5' */
  const boolean_T Constant7;           /* '<S2>/Constant7' */
  const boolean_T LogicalOperator1;    /* '<S509>/Logical Operator1' */
  const boolean_T LogicalOperator1_a;  /* '<S108>/Logical Operator1' */
} ConstB_SWC_APA_h_T;

#endif                                 /*SWC_APA_MDLREF_HIDE_CHILD_*/

#ifndef SWC_APA_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_SWC_APA_T {
  const char_T **errorStatus;
};

#endif                                 /*SWC_APA_MDLREF_HIDE_CHILD_*/

#ifndef SWC_APA_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_SWC_APA_T rtm;
} MdlrefDW_SWC_APA_T;

#endif                                 /*SWC_APA_MDLREF_HIDE_CHILD_*/

extern void SWC_APA_Init(void);
extern void SWC_APA_Disable(void);
extern void SWC_APA(const TeVBII_e_CmdIgnSts
                    *rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts, const boolean_T
                    *rtu_IbVBIA_VehState_IeVBII_b_FrntParkAsstReq, const
                    boolean_T *rtu_IbVBIA_VehState_IeVBII_b_ParkAsstReq, const
                    boolean_T *rtu_IbVBIA_VehState_IeVBII_b_RemoteStartActvSts,
                    const boolean_T
                    *rtu_IbVBIA_VehState_IeVBII_b_SnowPlowAttached, const
                    TeVBII_e_TrailerConnectionSts
                    *rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts, const
                    TeVBII_e_TrlrPrsntSts
                    *rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts, const real32_T
                    *rtu_IbVBIA_VehState_IeVBII_degC_ExtTemp, const
                    TeVBII_e_BrkStat *rtu_IbVBIA_VehState_IeVBII_e_BrkStat,
                    const TeVBII_e_VehEPBSts
                    *rtu_IbVBIA_VehState_IeVBII_e_VehEPBSts, const
                    TeVBII_e_TCaseRangeSts
                    *rtu_IbVBIA_VehState_IeVBII_e_TCaseRangeSts, const
                    TeVBII_e_EssEngState
                    *rtu_IbVBIA_VehState_IeVBII_e_EssEngState, const
                    TeVBII_e_PamChimeVol
                    *rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolFrnt, const
                    TeVBII_e_PamChimeVol
                    *rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolRear, const
                    boolean_T *rtu_IbVBIA_VehState_IeVBII_b_RearBrkAsst, const
                    TeAP_e_FiltdGearState
                    *rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear, const
                    TeVBII_e_TransSailingTst
                    *rtu_IbVBIA_VehState_IeVBII_e_TransSailingTst, const
                    real32_T *rtu_IbVBIA_VehState_IeVBII_a_VehLatAcc, const
                    real32_T *rtu_IbVBIA_VehState_IeVBII_a_VehLongAcc, const
                    real32_T *rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig,
                    const real32_T *rtu_IbVBIA_VehState_IeVBII_ddeg_VehYawRate,
                    const uint8_T *rtu_IbVBIA_VehState_IeVBII_cnt_LhfPulseCtr,
                    const TeVBII_e_WhlSpnSts
                    *rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts, const real32_T
                    *rtu_IbVBIA_VehState_IeVBII_kph_LhfWhlSpd, const uint8_T
                    *rtu_IbVBIA_VehState_IeVBII_cnt_LhrPulseCtr, const real32_T *
                    rtu_IbVBIA_VehState_IeVBII_kph_LhrWhlSpd, const uint8_T
                    *rtu_IbVBIA_VehState_IeVBII_cnt_RhfPulseCtr, const
                    TeVBII_e_WhlSpnSts
                    *rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts, const real32_T
                    *rtu_IbVBIA_VehState_IeVBII_kph_RhfWhlSpd, const uint8_T
                    *rtu_IbVBIA_VehState_IeVBII_cnt_RhrPulseCtr, const real32_T *
                    rtu_IbVBIA_VehState_IeVBII_kph_RhrWhlSpd, const real32_T
                    *rtu_IbVBIA_VehState_IeVBII_deg_StrWhlAng, const real32_T
                    *rtu_IbVBIA_VehState_IeVBII_deg_StrWhlSpd, const boolean_T
                    *rtu_IbVBIA_VehState_IeVBII_b_ShifterAutoconnectSts, const
                    TeVBII_e_ShiftLvrPosReq
                    *rtu_IbVBIA_VehState_IeVBII_e_ShiftLvrPosReq, const
                    boolean_T *rtu_IbVBIA_VehState_IeVBII_b_AutoParkEnblSwt,
                    const TeVBII_e_TurnIndicSts
                    *rtu_IbVBIA_VehState_IeVBII_e_TurnIndicSts, const boolean_T *
                    rtu_IbVBIA_VehState_IeVBII_b_DriverDoorSts, const boolean_T *
                    rtu_IbVBIA_VehState_IeVBII_b_DoorRL, const boolean_T
                    *rtu_IbVBIA_VehState_IeVBII_b_DoorP, const boolean_T
                    *rtu_IbVBIA_VehState_IeVBII_b_TrnkStatus, const boolean_T
                    *rtu_IbVBIA_VehState_IeVBII_b_DoorRR, const
                    TeVBII_e_EngineSts *rtu_IbVBIA_VehState_IeVBII_e_EngineSts,
                    const real32_T *rtu_IbVBIA_VehState_IeVBII_per_PdlPosAct,
                    const boolean_T *rtu_IbVBIA_VehState_IeVBII_b_ActvParkMode,
                    const TeVBII_e_LanguageSeln
                    *rtu_IbVBIA_VehState_IeVBII_e_LanguageSeln, const
                    TeVBII_e_TGWCamDispSts
                    *rtu_IbVBIA_VehState_IeVBII_e_TGWCamDispSts, const
                    TeVBII_e_TchScrSts *rtu_IbVBIA_VehState_IeVBII_e_TchScrSts,
                    const uint16_T *rtu_IbVBIA_VehState_IeVBII_e_TchXCoord,
                    const uint16_T *rtu_IbVBIA_VehState_IeVBII_e_TchYCoord,
                    const boolean_T
                    *rtu_IbVBIA_VehState_IeVBII_b_GearShiftReqAccept, const
                    TeAP_e_FiltdGearState
                    *rtu_IbVBIA_VehState_MeAP_e_FiltdGearRptState, const
                    TeVBII_e_ACCSysSts *rtu_IbVBIA_VehState_IeVBII_e_ACCSysSts,
                    const uint32_T *rtu_IbVBIA_VehState_IeVBII_nm_BrkTrqAct,
                    const TeVBII_e_ParkingIntrvntionSts
                    *rtu_IbVBIA_VehState_IeVBII_e_ParkingIntrvntionSts, const
                    boolean_T *rtu_IbVBIA_VehState_IeVBII_b_HandsOnRecog, const
                    TeVBII_e_SPMLatCtrlRespSts
                    *rtu_IbVBIA_VehState_IeVBII_e_SPMLatCtrlRespSts, const
                    real32_T *rtu_IbVBIA_VehState_IeVBII_M_StrWhlTrq, const
                    boolean_T *rtu_IbVBIA_VehState_IeVBII_b_VehLatAccFailSts,
                    const boolean_T
                    *rtu_IbVBIA_VehState_IeVBII_b_VehLongAccFailSts, const
                    boolean_T *rtu_IbVBIA_VehState_IeVBII_b_VehYawRateFailSts,
                    const boolean_T
                    *rtu_IbVBIA_VehState_IeVBII_b_LHFWhlSnsrFailSts, const
                    boolean_T *rtu_IbVBIA_VehState_IeVBII_b_LHRWhlSnsrFailSts,
                    const boolean_T
                    *rtu_IbVBIA_VehState_IeVBII_b_RHFWhlSnsrFailSts, const
                    boolean_T *rtu_IbVBIA_VehState_IeVBII_b_RHRWhlSnsrFailSts,
                    const TeVBII_e_PAMBrkReqRespStatus
                    *rtu_IbVBIA_VehState_IeVBII_e_PAMBrkReqRespStatus, const
                    TeVBII_e_ShiftLvrPos
                    *rtu_IbVBIA_VehState_IeVBII_e_ShiftLvrPos, const uint32_T
                    *rtu_IbVBIA_VehState_IeVBII_nm_BrkTrqDriver, const
                    TeVBII_e_ExtBrkReqDisabled
                    *rtu_IbVBIA_VehState_IeVBII_e_ExtBrkReqDisabled, const
                    TeVBII_e_ParkingGearShiftReq
                    *rtu_IbVBIA_VehState_IeVBII_e_ParkingGearShiftReq, const
                    int16_T *rtu_IbVBIA_VehState_IeVBII_pct_Slope, const
                    TeVBII_e_DriverReqAxleTrqEnabled
                    *rtu_IbVBIA_VehState_IeVBII_e_DriverReqAxleTrqEnabled, const
                    TeVBII_e_BrkPdlStat *rtu_IbVBIA_VehState_IeVBII_e_BrkPdlStat,
                    const boolean_T *rtu_IbVBIA_VehState_IeVBII_b_Override,
                    const boolean_T
                    *rtu_IbVBIA_VehState_IeVBII_b_TrqEnblReqAllowed, const
                    boolean_T *rtu_IbVBIA_VehState_IeVBII_b_ParkProxChime, const
                    boolean_T *rtu_MbNVM_ProxyParam_KeAP_b_CanNode67DTCM, const
                    boolean_T *rtu_MbNVM_ProxyParam_KeAP_b_CanNode63TTM, const
                    boolean_T *rtu_MbNVM_ProxyParam_KeAP_b_StopAndStrt, const
                    uint16_T *rtu_MbNVM_ProxyParam_KeAP_mm_TyreSz, const
                    TeAP_e_SteerRatRackPinionTyp
                    *rtu_MbNVM_ProxyParam_KeAP_e_SteerRatRackPinionTyp, const
                    TeAP_e_DrvTypVrnt *rtu_MbNVM_ProxyParam_KeAP_e_DrvTypVrnt,
                    const TeAP_e_GbTyp *rtu_MbNVM_ProxyParam_KeAP_e_GbTyp, const
                    TeAP_e_PAMTunSet *rtu_MbNVM_ProxyParam_KeAP_e_PAMTunSet,
                    const uint8_T *rtu_MbNVM_ProxyParam_KeAP_e_VehLineCfg, const
                    TeAP_e_CtryCod *rtu_MbNVM_ProxyParam_KeAP_e_CtryCod, const
                    TeAP_e_HybTyp *rtu_MbNVM_ProxyParam_KeAP_e_HybTyp, const
                    TeAP_e_WhlBas *rtu_MbNVM_ProxyParam_KeAP_e_WhlBas, const
                    boolean_T *rtu_MbNVM_ProxyParam_KeAP_b_ParkWithStop, const
                    boolean_T *rtu_MbNVM_ProxyParam_KeAP_b_PAMCfg, const
                    TeAP_e_RadioDispTyp
                    *rtu_MbNVM_ProxyParam_KeAP_e_RadioDispTyp, const boolean_T
                    *rtu_MbNVM_ProxyParam_KeAP_b_CanNode95ITBMTCM, const
                    boolean_T *rtu_MbNVM_ProxyParam_KeAP_b_DrvSide, const
                    boolean_T *rtu_MbNVM_ProxyParam_KeAP_b_SemiAutoPrkgSys,
                    const uint16_T *rtu_MbNVM_ProxyParam_KeAP_e_MdlYr, const
                    boolean_T *rtu_MbNVM_ProxyParam_KeAP_b_PullOutCtrlPres,
                    const boolean_T *rtu_MbNVM_ProxyParam_KeAP_b_FullAutoPrkgSys,
                    const boolean_T
                    *rtu_MbNVM_ProxyParam_KeAP_b_TrlrHitchAsstPres, const
                    boolean_T *rtu_MbNVM_ProxyParam_KeAP_b_TrlrRvsSteerPres,
                    const boolean_T *rtu_MbNVM_ProxyParam_KeAP_b_SVSPresent,
                    const uint8_T *rtu_MbNVM_ProxyParam_KeAP_k_VariantID, const
                    boolean_T *rtu_IbFID_PA_MeAP_b_ExternalFail, const boolean_T
                    *rtu_IbFID_PA_MeAP_b_SystemFail, const boolean_T
                    *rtu_IbFID_PA_MeAP_b_FPADisable, const boolean_T
                    *rtu_IbFID_PA_MeAP_b_RPADisable, const boolean_T
                    *rtu_IbFID_PA_MeAP_b_RPAActvTrlr_27, const boolean_T
                    *rtu_IbFID_PA_MeAP_b_RPAActvTrlr_29, const boolean_T
                    *rtu_IbFID_PA_MeAP_b_PAVolDefMed, const boolean_T
                    *rtu_IbFID_PA_MeAP_b_FPAVolDefMed, const boolean_T
                    *rtu_IbFID_PA_MeAP_b_RPAVolDefMed, const boolean_T
                    *rtu_IbFID_PA_MeAP_b_FrntSenorFail, const boolean_T
                    *rtu_IbFID_PA_MeAP_b_FrntSenorBlock, const boolean_T
                    *rtu_IbFID_PA_MeAP_b_RearSenorFail, const boolean_T
                    *rtu_IbFID_PA_MeAP_b_RearSenorBlock, const boolean_T
                    *rtu_IbFID_PARB_MeAP_b_PARBActv4LOW, const boolean_T
                    *rtu_IbFID_PARB_MeAP_b_PARBDiable, const TbNVM_ReadParam
                    *rtu_MbNVM_ReadParam, const real32_T
                    *rtu_IbAP_InputVrntTunParam_KeAP_degC_OperatingTempThd,
                    const real32_T
                    *rtu_IbAP_InputVrntTunParam_KeAP_kph_EnblHysThd, const
                    real32_T
                    *rtu_IbAP_InputVrntTunParam_KeAP_kph_FrntWarnMaxSpdThd,
                    const real32_T
                    *rtu_IbAP_InputVrntTunParam_KeAP_kph_RearWarnMaxSpdThd,
                    const real32_T
                    *rtu_IbAP_InputVrntTunParam_K_e_RAEB_VehicleWidth, const
                    uint16_T
                    *rtu_IbAP_InputVrntTunParam_KeAP_cnt_ChimeVolChgAlert, const
                    uint16_T
                    *rtu_IbAP_InputVrntTunParam_KeAP_cnt_FrntChimeDisTimeThd,
                    const uint16_T
                    *rtu_IbAP_InputVrntTunParam_KeAP_cnt_LEDBlinkTimeThd, const
                    uint16_T
                    *rtu_IbAP_InputVrntTunParam_KeAP_cnt_VehKeyOnTimeThd, const
                    uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
                    const uint16_T
                    *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd, const
                    int16_T *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone1, const
                    int16_T *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone2, const
                    int16_T *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone3, const
                    int16_T *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone4, const
                    int16_T *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone5, const
                    int16_T *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone6, const
                    int16_T *rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj,
                    const boolean_T *rtu_IbAP_InputVrntTunParam_KeAP_b_FPAEn,
                    const boolean_T
                    *rtu_IbAP_InputVrntTunParam_KeAP_b_RPAwithBrk, const
                    boolean_T
                    *rtu_IbAP_InputVrntTunParam_KeAP_b_RPAwithSurroundView,
                    const US_S_PointMapOutputBuff_t *rtu_USS_2DPointMap, const
                    TeAP_e_SPMLatCtrlReqSts *rtu_IeAP_e_SPMLatCtrlReqSts, const
                    TeAP_e_ParKMnvrActv *rtu_IeAP_e_ParKMnvrActv, const
                    TeTRSC_e_TRSCSts *rtu_IeTRSC_e_TRSCSts, const
                    TeTHA_e_RearBrkSupprInfo *rtu_MeTHA_e_RearBrkSupprInfo,
                    const boolean_T *rtu_MbDiag_TestModeForceOn, const int16_T
                    *rtu_MeAP_cm_FrntCenterMinXDist, const int16_T
                    *rtu_MeAP_cm_FrntLeftMinXDist, const int16_T
                    *rtu_MeAP_cm_FrntRightMinXDist, const int16_T
                    *rtu_MeAP_cm_RearCenterMinXDist, const int16_T
                    *rtu_MeAP_cm_RearLeftMinXDist, const int16_T
                    *rtu_MeAP_cm_RearRightMinXDist, const boolean_T
                    *rtu_MbDiag_PlantModeOn, const TeTRSC_e_TRSCPopupDispInfo
                    *rtu_IeTRSC_e_TRSCPopupDispInfo, const uint8_T
                    *rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFront,
                    const uint8_T
                    *rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFL,
                    const uint8_T
                    *rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFR,
                    const uint8_T
                    *rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRear,
                    const uint8_T
                    *rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRL,
                    const uint8_T
                    *rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRR,
                    const uint8_T *rtu_MeAP_b_IsWall, const int16_T
                    *rtu_MeAP_cm_WallFrntCenterDist, const int16_T
                    *rtu_MeAP_cm_WallRearCenterDist, TeAP_e_Alert
                    *rty_MeAP_e_AlertCHF, TeAP_e_Alert *rty_MeAP_e_AlertLHF,
                    TeAP_e_Alert *rty_MeAP_e_AlertRHF, TeAP_e_Alert
                    *rty_MeAP_e_AlertCHR, TeAP_e_Alert *rty_MeAP_e_AlertLHR,
                    TeAP_e_Alert *rty_MeAP_e_AlertRHR, TeAP_e_GraphicFlshRate
                    *rty_MeAP_e_GraphicCHF, TeAP_e_GraphicFlshRate
                    *rty_MeAP_e_GraphicLHF, TeAP_e_GraphicFlshRate
                    *rty_MeAP_e_GraphicRHF, TeAP_e_GraphicFlshRate
                    *rty_MeAP_e_GraphicCHR, TeAP_e_GraphicFlshRate
                    *rty_MeAP_e_GraphicLHR, TeAP_e_GraphicFlshRate
                    *rty_MeAP_e_GraphicRHR, boolean_T *rty_MeAP_b_ChimeActvLHF,
                    boolean_T *rty_MeAP_b_ChimeActvRHF, boolean_T
                    *rty_MeAP_b_ChimeActvLHR, boolean_T *rty_MeAP_b_ChimeActvRHR,
                    TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRate,
                    TeAP_e_PAMVolume *rty_MeAP_e_PAMVolume,
                    TeAP_e_PAMLedCtrlStatus *rty_MeAP_e_FrntPAMLedCtrlStatus,
                    TeAP_e_PAMLedCtrlStatus *rty_MeAP_e_RearPAMLedCtrlStatus,
                    TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTyp,
                    TeAP_e_PAMPopUpReq *rty_MeAP_e_PAMPopUpReq, boolean_T
                    *rty_MeAP_b_PAMBrkReqStatus, real32_T *rty_MeAP_cm_RearDist,
                    boolean_T *rty_MeAP_b_PAMStopCtrlStatus,
                    TeAP_e_ParkAssistStatus *rty_MeAP_e_ParkAssistStatus,
                    boolean_T *rty_MeAP_b_FPAStatus, boolean_T
                    *rty_MeAP_b_RPAStatus, TeAP_e_PAMSystemFault
                    *rty_IeAP_e_PAMSystemFault, TeAP_e_PAMOffStatus2BT
                    *rty_MeAP_e_PAMOffStatus2BT, boolean_T
                    *rty_MeAP_b_SystemFail, boolean_T *rty_MeAP_b_ExternalFail,
                    boolean_T *rty_MeAP_b_RPAwithBrkDisable, boolean_T
                    *rty_MeAP_b_RPADisable, boolean_T *rty_MeAP_b_FPADisable,
                    TeAutoPark_e_ScanDir *rty_IeAutoPark_e_ScanDir,
                    TeAP_e_FrntSnsrStatus *rty_IeAP_e_FrntSnsrStatus,
                    TeAP_e_RearSnsrStatus *rty_IeAP_e_RearSnsrStatus);

/* Model reference registration function */
extern void SWC_APA_initialize(const char_T **rt_errorStatus);
extern const TbVBIA_VehState_AP SWC_APA_rtZTbVBIA_VehState_AP;/* TbVBIA_VehState_AP ground */
extern const TbNVM_ProxyCalibParam SWC_APA_rtZTbNVM_ProxyCalibParam;/* TbNVM_ProxyCalibParam ground */

/* Exported data declaration */

/* Declaration for custom storage class: Default */
extern real32_T CONST_DPS2RPS; /* Referenced by: '<S57>/Rear_ObjectDetection' */

/* conversion parameter from degree/s to rad/s */
extern uint16_T CeAP_ms_SampleTime;   /* Referenced by: '<S653>/RearDistHold' */
extern real32_T K_e_RAEB_DrawingTubeOffset;
                               /* Referenced by: '<S57>/Rear_ObjectDetection' */

/* To feed mobileye obj type into AdCam instead of hard coded value */
extern real32_T K_e_RAEB_VehicleWidth;
                               /* Referenced by: '<S57>/Rear_ObjectDetection' */

/* To feed mobileye obj type into AdCam instead of hard coded value */
extern real32_T K_e_RAEB_WarnOffset;
                               /* Referenced by: '<S57>/Rear_ObjectDetection' */

/* To feed lateral offset to issue warning */
extern boolean_T KeAP_b_EnVehStandstillArcBlip;/* Referenced by:
                                                * '<S193>/Constant2'
                                                * '<S194>/Constant2'
                                                * '<S195>/Constant2'
                                                * '<S605>/Constant2'
                                                * '<S606>/Constant2'
                                                * '<S607>/Constant2'
                                                */
extern boolean_T KeAP_b_EnWallAcurracy;/* Referenced by:
                                        * '<S156>/Constant5'
                                        * '<S564>/Constant5'
                                        */
extern boolean_T KeAP_b_RPAwithBrk;    /* Referenced by: '<S57>/Constant1' */

/* Ego vehicle shall be equipped with Rear Park Assist with Brake */
extern boolean_T KeAP_b_RearDistCorrBasedVehSpd;
                               /* Referenced by: '<S57>/Rear_ObjectDetection' */
extern uint8_T KeAP_b_SupprsUssGlblHght;
                               /* Referenced by: '<S57>/Rear_ObjectDetection' */
extern boolean_T KeAP_b_SwitchOldAlgo; /* Referenced by:
                                        * '<S16>/Constant2'
                                        * '<S17>/Constant2'
                                        */
extern int16_T KeAP_cm_DistZone1;      /* Referenced by:
                                        * '<S484>/AlertFilterLHR'
                                        * '<S484>/AlertFilterRHR'
                                        */

/* Warning Zone 1 Dist */
extern int16_T KeAP_cm_DistZone2;      /* Referenced by:
                                        * '<S57>/Rear_ObjectDetection'
                                        * '<S484>/AlertFilterCHR'
                                        * '<S484>/AlertFilterLHR'
                                        * '<S484>/AlertFilterRHR'
                                        */

/* Warning Zone 2 Dist */
extern int16_T KeAP_cm_DistZone3;      /* Referenced by:
                                        * '<S484>/AlertFilterCHR'
                                        * '<S484>/AlertFilterLHR'
                                        * '<S484>/AlertFilterRHR'
                                        */

/* Warning Zone 3 Dist */
extern int16_T KeAP_cm_DistZone4;      /* Referenced by:
                                        * '<S484>/AlertFilterCHR'
                                        * '<S484>/AlertFilterLHR'
                                        * '<S484>/AlertFilterRHR'
                                        */

/* Warning Zone 4 Dist */
extern int16_T KeAP_cm_DistZone5;      /* Referenced by:
                                        * '<S484>/AlertFilterCHR'
                                        * '<S484>/AlertFilterLHR'
                                        * '<S484>/AlertFilterRHR'
                                        */

/* Warning Zone 5 Dist */
extern int16_T KeAP_cm_DistZone6;      /* Referenced by:
                                        * '<S484>/AlertFilterCHR'
                                        * '<S484>/AlertFilterLHR'
                                        * '<S484>/AlertFilterRHR'
                                        */

/* Warning Zone 6 Dist */
extern int16_T KeAP_cm_FrntDistZone1;  /* Referenced by:
                                        * '<S83>/AlertFilterLHF'
                                        * '<S83>/AlertFilterRHF'
                                        * '<S156>/Constant4'
                                        * '<S158>/Constant'
                                        * '<S159>/Constant'
                                        */

/* Warning Zone 1 Dist */
extern int16_T KeAP_cm_FrntDistZone2;  /* Referenced by:
                                        * '<S83>/AlertFilterCHF'
                                        * '<S83>/AlertFilterLHF'
                                        * '<S83>/AlertFilterRHF'
                                        * '<S156>/Constant1'
                                        * '<S158>/Constant1'
                                        * '<S159>/Constant1'
                                        */

/* Warning Zone 2 Dist */
extern int16_T KeAP_cm_FrntDistZone3;  /* Referenced by:
                                        * '<S83>/AlertFilterCHF'
                                        * '<S83>/AlertFilterLHF'
                                        * '<S83>/AlertFilterRHF'
                                        * '<S156>/Constant2'
                                        */

/* Warning Zone 3 Dist */
extern int16_T KeAP_cm_FrntDistZone4;  /* Referenced by:
                                        * '<S83>/AlertFilterCHF'
                                        * '<S83>/AlertFilterLHF'
                                        * '<S83>/AlertFilterRHF'
                                        * '<S156>/Constant3'
                                        */

/* Warning Zone 4 Dist */
extern int16_T KeAP_cm_FrntDistZone5;  /* Referenced by:
                                        * '<S83>/AlertFilterCHF'
                                        * '<S83>/AlertFilterLHF'
                                        * '<S83>/AlertFilterRHF'
                                        */

/* Warning Zone 5 Dist */
extern int16_T KeAP_cm_FrntDistZone6;  /* Referenced by:
                                        * '<S83>/AlertFilterCHF'
                                        * '<S83>/AlertFilterLHF'
                                        * '<S83>/AlertFilterRHF'
                                        */

/* Warning Zone 6 Dist */
extern real32_T KeAP_cm_FrntWallZone1Adj;/* Referenced by: '<S156>/Constant9' */
extern int16_T KeAP_cm_NhXmaxOffset;
                               /* Referenced by: '<S57>/Rear_ObjectDetection' */

/* NeighboutHood Window */
extern int16_T KeAP_cm_NhXminOffset;
                               /* Referenced by: '<S57>/Rear_ObjectDetection' */

/* NeighboutHood Window */
extern int16_T KeAP_cm_NhYmaxOffset;
                               /* Referenced by: '<S57>/Rear_ObjectDetection' */

/* NeighboutHood Window */
extern int16_T KeAP_cm_NhYminOffset;
                               /* Referenced by: '<S57>/Rear_ObjectDetection' */

/* NeighboutHood Window */
extern real32_T KeAP_cm_RearBrkDistChngLwThresh;/* Referenced by:
                                                 * '<S657>/Constant'
                                                 * '<S664>/Constant'
                                                 */

/* Rear Braking Dist Change lower Threshold */
extern real32_T KeAP_cm_RearBrkDistChngUpThresh;/* Referenced by: '<S662>/Constant' */

/* Rear Braking Dist Change upper Threshold */
extern int16_T KeAP_cm_RearLongDistAdj;
                               /* Referenced by: '<S57>/Rear_ObjectDetection' */

/* Longitudanl Distance from Rear Axle to Rear edge of vehicle */
extern real32_T KeAP_cm_RearWallZone1Adj;/* Referenced by: '<S564>/Constant14' */
extern uint16_T KeAP_cnt_ArcBlipStandstillTimer;/* Referenced by:
                                                 * '<S193>/Constant1'
                                                 * '<S194>/Constant1'
                                                 * '<S195>/Constant1'
                                                 * '<S605>/Constant1'
                                                 * '<S606>/Constant1'
                                                 * '<S607>/Constant1'
                                                 */
extern uint16_T KeAP_cnt_ArcBlipVehInMotTimer[6];/* Referenced by:
                                                  * '<S193>/Constant5'
                                                  * '<S194>/Constant5'
                                                  * '<S195>/Constant5'
                                                  * '<S605>/Constant5'
                                                  * '<S606>/Constant5'
                                                  * '<S607>/Constant5'
                                                  */
extern real32_T KeAP_cnt_ArcBlipVehSpdThd[6];/* Referenced by:
                                              * '<S193>/Constant6'
                                              * '<S194>/Constant6'
                                              * '<S195>/Constant6'
                                              * '<S605>/Constant6'
                                              * '<S606>/Constant6'
                                              * '<S607>/Constant6'
                                              */
extern uint16_T KeAP_cnt_BootupTimeThd;/* Referenced by:
                                        * '<S81>/Constant7'
                                        * '<S482>/Constant7'
                                        */

/* Time threshold for ECU bootup */
extern uint16_T KeAP_cnt_BtnPressPopUpTimeThd;/* Referenced by:
                                               * '<S247>/Constant'
                                               * '<S248>/Constant'
                                               * '<S105>/Constant'
                                               * '<S257>/Constant'
                                               * '<S506>/Constant'
                                               */

/* Time for which Startup PopUp Requests are shown */
extern real32_T KeAP_cnt_NoiseModeRearDistComp;
                               /* Referenced by: '<S57>/Rear_ObjectDetection' */
extern uint16_T KeAP_cnt_PlntModeLEDBlinkTimeThd;/* Referenced by:
                                                  * '<S78>/Constant2'
                                                  * '<S480>/Constant2'
                                                  */

/* Time Step for LED blinking for ECU-In Plant Mode */
extern real32_T KeAP_cnt_RearDistCompTimeThd;
                               /* Referenced by: '<S57>/Rear_ObjectDetection' */
extern uint16_T KeAP_cnt_TimeStep;     /* Referenced by:
                                        * '<S81>/Constant6'
                                        * '<S482>/Constant6'
                                        */

/* Time Step for Counter  */
extern uint8_T KeAP_e_GbTypAT;         /* Referenced by: '<S650>/Constant1' */

/* ATX Gear_Box_Type */
extern real32_T KeAP_kph_EnblHysThd;   /* Referenced by: '<S453>/Constant2' */

/* Hystere sis threshold to apply for all vehicle speed related threshold parameters */
extern real32_T KeAP_kph_FrntWarnMaxSpdThd;/* Referenced by: '<S39>/Constant1' */

/* Vehicle speed threshold during Front Park Assist feature */
extern real32_T KeAP_kph_RearWarnMaxSpdThd;/* Referenced by:
                                            * '<S40>/Constant1'
                                            * '<S335>/Constant'
                                            * '<S336>/Constant'
                                            * '<S453>/Constant1'
                                            * '<S453>/Constant2'
                                            */

/* Vehicle speed threshold during Rear Park Assist feature */
extern uint8_T KeAP_pct_ObjConfidenceThd;
                               /* Referenced by: '<S57>/Rear_ObjectDetection' */

/* Detected Object Confidence threshold */
extern uint8_T KePA_b_EnFeatPointSplitImp;
                               /* Referenced by: '<S57>/Rear_ObjectDetection' */

/* Enable NeighboutHood Window */
extern uint8_T KePA_b_EnHeightFlagFrontSideArcs;/* Referenced by: '<S157>/DNNCheck' */

/* Enable DNN Flag check for Side front arcs */
extern uint8_T KePA_b_EnHeightFlagRearSideArcs;/* Referenced by: '<S565>/DNNCheck' */

/* Enable DNN Flag check for Side rear arc */
extern uint8_T KePA_b_IsDnnHeightLow;  /* Referenced by:
                                        * '<S157>/DNNCheck'
                                        * '<S565>/DNNCheck'
                                        */

/* Enable DNN Flag check */
extern boolean_T MeAP_b_FPASwtStatus;  /* '<S16>/Switch' */
extern boolean_T MeAP_b_FPASwtStuckStatus;/* '<S16>/Logical Operator' */
extern boolean_T MeAP_b_FrntParkAssistStatus;/* '<S14>/Logical Operator' */
extern boolean_T MeAP_b_FrontParkAssistEnbl;/* '<S12>/Logical Operator5' */
extern boolean_T MeAP_b_RPASwtStatus;  /* '<S17>/Switch' */
extern boolean_T MeAP_b_RPASwtStuckStatus;/* '<S17>/Logical Operator' */
extern boolean_T MeAP_b_RearParkAssistEnbl;/* '<S15>/Logical Operator1' */
extern boolean_T MeAP_b_RearParkAssistStatus;/* '<S14>/Logical Operator1' */

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const uint8_T CeAP_k_CurbArrayInit[10];
                               /* Referenced by: '<S57>/Rear_ObjectDetection' */

#ifndef SWC_APA_MDLREF_HIDE_CHILD_

extern MdlrefDW_SWC_APA_T SWC_APA_MdlrefDW;

#endif                                 /*SWC_APA_MDLREF_HIDE_CHILD_*/

#ifndef SWC_APA_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_SWC_APA_c_T SWC_APA_B;

/* Block states (default storage) */
extern DW_SWC_APA_f_T SWC_APA_DW;

#endif                                 /*SWC_APA_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'SWC_APA'
 * '<S1>'   : 'SWC_APA/Model Info'
 * '<S2>'   : 'SWC_APA/SWC_APA'
 * '<S3>'   : 'SWC_APA/SWC_APA/PA_DisableFlags'
 * '<S4>'   : 'SWC_APA/SWC_APA/PA_EnableCondition'
 * '<S5>'   : 'SWC_APA/SWC_APA/PA_StateMachine'
 * '<S6>'   : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist'
 * '<S7>'   : 'SWC_APA/SWC_APA/SaveFeatureStsTrlr'
 * '<S8>'   : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition'
 * '<S9>'   : 'SWC_APA/SWC_APA/PA_EnableCondition/AP_StartAndStopInteraction'
 * '<S10>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/SnsrStatusUpdate'
 * '<S11>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/VehCndCheck'
 * '<S12>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/FPA_EnablingCondition'
 * '<S13>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAM2BTSwtStatusUpdate'
 * '<S14>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAMSwtStatusUpdate'
 * '<S15>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/RPA_EnablingCondition'
 * '<S16>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAM2BTSwtStatusUpdate/FPASwtStuckStatusUpdate'
 * '<S17>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAM2BTSwtStatusUpdate/RPASwtStuckStatusUpdate'
 * '<S18>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAM2BTSwtStatusUpdate/FPASwtStuckStatusUpdate/Enumerated Constant'
 * '<S19>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAM2BTSwtStatusUpdate/FPASwtStuckStatusUpdate/Enumerated Constant1'
 * '<S20>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAM2BTSwtStatusUpdate/FPASwtStuckStatusUpdate/Enumerated Constant7'
 * '<S21>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAM2BTSwtStatusUpdate/FPASwtStuckStatusUpdate/FallingEdge'
 * '<S22>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAM2BTSwtStatusUpdate/FPASwtStuckStatusUpdate/OffTimer'
 * '<S23>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAM2BTSwtStatusUpdate/RPASwtStuckStatusUpdate/Enumerated Constant'
 * '<S24>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAM2BTSwtStatusUpdate/RPASwtStuckStatusUpdate/Enumerated Constant1'
 * '<S25>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAM2BTSwtStatusUpdate/RPASwtStuckStatusUpdate/Enumerated Constant7'
 * '<S26>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAM2BTSwtStatusUpdate/RPASwtStuckStatusUpdate/FallingEdge'
 * '<S27>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAM2BTSwtStatusUpdate/RPASwtStuckStatusUpdate/OffTimer'
 * '<S28>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAMSwtStatusUpdate/Enumerated Constant'
 * '<S29>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAMSwtStatusUpdate/Enumerated Constant5'
 * '<S30>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAMSwtStatusUpdate/Enumerated Constant6'
 * '<S31>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAMSwtStatusUpdate/Enumerated Constant7'
 * '<S32>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/PAMSwtStatusUpdate/Enumerated Constant8'
 * '<S33>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/RPA_EnablingCondition/Enumerated Constant2'
 * '<S34>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/RPA_EnablingCondition/Enumerated Constant3'
 * '<S35>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/RPA_EnablingCondition/Enumerated Constant4'
 * '<S36>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/RPA_EnablingCondition/Enumerated Constant5'
 * '<S37>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/RPA_EnablingCondition/Enumerated Constant6'
 * '<S38>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/APA_EnablingCondition/RPA_EnablingCondition/Enumerated Constant7'
 * '<S39>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/SnsrStatusUpdate/FrntSnsrStatusUpdate'
 * '<S40>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/SnsrStatusUpdate/RearSnsrStatusUpdate'
 * '<S41>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/SnsrStatusUpdate/FrntSnsrStatusUpdate/Enumerated Constant'
 * '<S42>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/SnsrStatusUpdate/FrntSnsrStatusUpdate/Enumerated Constant1'
 * '<S43>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/SnsrStatusUpdate/FrntSnsrStatusUpdate/Enumerated Constant2'
 * '<S44>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/SnsrStatusUpdate/FrntSnsrStatusUpdate/Enumerated Constant3'
 * '<S45>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/SnsrStatusUpdate/RearSnsrStatusUpdate/Enumerated Constant'
 * '<S46>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/SnsrStatusUpdate/RearSnsrStatusUpdate/Enumerated Constant1'
 * '<S47>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/SnsrStatusUpdate/RearSnsrStatusUpdate/Enumerated Constant2'
 * '<S48>'  : 'SWC_APA/SWC_APA/PA_EnableCondition/SnsrStatusUpdate/RearSnsrStatusUpdate/Enumerated Constant3'
 * '<S49>'  : 'SWC_APA/SWC_APA/PA_StateMachine/APA_StateMachine'
 * '<S50>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CalPAMChimeRepnRate'
 * '<S51>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CheckForChimePriority1'
 * '<S52>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA'
 * '<S53>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMChimeTypeUpdate'
 * '<S54>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen'
 * '<S55>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMVolumeGen'
 * '<S56>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA'
 * '<S57>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk'
 * '<S58>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/SaveFeatureSts1'
 * '<S59>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/Subsystem'
 * '<S60>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CalPAMChimeRepnRate/Enumerated Constant1'
 * '<S61>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CalPAMChimeRepnRate/Enumerated Constant2'
 * '<S62>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CalPAMChimeRepnRate/Enumerated Constant3'
 * '<S63>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CalPAMChimeRepnRate/Enumerated Constant4'
 * '<S64>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CalPAMChimeRepnRate/Enumerated Constant8'
 * '<S65>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CheckForChimePriority1/Enumerated Constant1'
 * '<S66>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CheckForChimePriority1/Enumerated Constant10'
 * '<S67>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CheckForChimePriority1/Enumerated Constant11'
 * '<S68>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CheckForChimePriority1/Enumerated Constant12'
 * '<S69>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CheckForChimePriority1/Enumerated Constant13'
 * '<S70>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CheckForChimePriority1/Enumerated Constant2'
 * '<S71>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CheckForChimePriority1/Enumerated Constant3'
 * '<S72>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CheckForChimePriority1/Enumerated Constant4'
 * '<S73>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CheckForChimePriority1/Enumerated Constant5'
 * '<S74>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CheckForChimePriority1/Enumerated Constant6'
 * '<S75>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CheckForChimePriority1/Enumerated Constant7'
 * '<S76>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CheckForChimePriority1/Enumerated Constant8'
 * '<S77>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/CheckForChimePriority1/Enumerated Constant9'
 * '<S78>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen'
 * '<S79>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/CheckGearChanges'
 * '<S80>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen'
 * '<S81>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertUpdate'
 * '<S82>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen'
 * '<S83>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis'
 * '<S84>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant1'
 * '<S85>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant10'
 * '<S86>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant11'
 * '<S87>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant12'
 * '<S88>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant13'
 * '<S89>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant14'
 * '<S90>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant15'
 * '<S91>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant16'
 * '<S92>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant17'
 * '<S93>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant19'
 * '<S94>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant2'
 * '<S95>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant20'
 * '<S96>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant21'
 * '<S97>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant3'
 * '<S98>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant4'
 * '<S99>'  : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant5'
 * '<S100>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant6'
 * '<S101>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant7'
 * '<S102>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant8'
 * '<S103>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/Enumerated Constant9'
 * '<S104>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/OffTimer'
 * '<S105>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/TimerForFrontSwitchPress'
 * '<S106>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/OffTimer/Latch'
 * '<S107>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/OffTimer/RisingEdge'
 * '<S108>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/TimerForFrontSwitchPress/OffTimer'
 * '<S109>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/AP_FrntPAMLedStatusGen/TimerForFrontSwitchPress/OffTimer/DetectChange'
 * '<S110>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/CheckGearChanges/Enumerated Constant1'
 * '<S111>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/CheckGearChanges/Enumerated Constant2'
 * '<S112>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/CheckGearChanges/Enumerated Constant3'
 * '<S113>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/CheckGearChanges/Enumerated Constant4'
 * '<S114>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/CheckGearChanges/Enumerated Constant5'
 * '<S115>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/ChimeAlertUpdate'
 * '<S116>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/LeftChimeAlertGen'
 * '<S117>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/RightChimeAlertGen'
 * '<S118>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/ChimeAlertUpdate/FrontChimeTimerDisable'
 * '<S119>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/ChimeAlertUpdate/FrontChimeTimerEnable'
 * '<S120>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/ChimeAlertUpdate/OffTimer'
 * '<S121>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/ChimeAlertUpdate/ReActivateFrontChime'
 * '<S122>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/ChimeAlertUpdate/FrontChimeTimerDisable/Enumerated Constant3'
 * '<S123>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/ChimeAlertUpdate/FrontChimeTimerDisable/Enumerated Constant4'
 * '<S124>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/ChimeAlertUpdate/FrontChimeTimerEnable/Enumerated Constant'
 * '<S125>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/ChimeAlertUpdate/FrontChimeTimerEnable/Enumerated Constant1'
 * '<S126>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/ChimeAlertUpdate/OffTimer/RisingEdge'
 * '<S127>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/ChimeAlertUpdate/ReActivateFrontChime/Enumerated Constant3'
 * '<S128>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/ChimeAlertUpdate/ReActivateFrontChime/Enumerated Constant4'
 * '<S129>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/LeftChimeAlertGen/Enumerated Constant1'
 * '<S130>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/LeftChimeAlertGen/Enumerated Constant16'
 * '<S131>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/LeftChimeAlertGen/Enumerated Constant2'
 * '<S132>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/LeftChimeAlertGen/Enumerated Constant3'
 * '<S133>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/LeftChimeAlertGen/Enumerated Constant4'
 * '<S134>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/LeftChimeAlertGen/Enumerated Constant5'
 * '<S135>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/LeftChimeAlertGen/Enumerated Constant6'
 * '<S136>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/LeftChimeAlertGen/Enumerated Constant7'
 * '<S137>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/RightChimeAlertGen/Enumerated Constant1'
 * '<S138>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/RightChimeAlertGen/Enumerated Constant2'
 * '<S139>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/RightChimeAlertGen/Enumerated Constant3'
 * '<S140>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/RightChimeAlertGen/Enumerated Constant4'
 * '<S141>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/RightChimeAlertGen/Enumerated Constant5'
 * '<S142>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/RightChimeAlertGen/Enumerated Constant6'
 * '<S143>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/RightChimeAlertGen/Enumerated Constant7'
 * '<S144>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertGen/RightChimeAlertGen/Enumerated Constant8'
 * '<S145>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertUpdate/Enumerated Constant1'
 * '<S146>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertUpdate/Enumerated Constant2'
 * '<S147>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertUpdate/Enumerated Constant7'
 * '<S148>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertUpdate/Enumerated Constant8'
 * '<S149>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertUpdate/Enumerated Constant9'
 * '<S150>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertUpdate/OffTimer'
 * '<S151>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertUpdate/OffTimer1'
 * '<S152>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertUpdate/OffTimer/Latch'
 * '<S153>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertUpdate/OffTimer/RisingEdge'
 * '<S154>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertUpdate/OffTimer1/Latch'
 * '<S155>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_ChimeAlertUpdate/OffTimer1/RisingEdge'
 * '<S156>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CenterGraphicAlertGen'
 * '<S157>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CheckDNNFlag'
 * '<S158>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/LeftGraphicAlertGen'
 * '<S159>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/RightGraphicAlertGen'
 * '<S160>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant1'
 * '<S161>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant10'
 * '<S162>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant2'
 * '<S163>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant3'
 * '<S164>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant4'
 * '<S165>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant5'
 * '<S166>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant6'
 * '<S167>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant7'
 * '<S168>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant8'
 * '<S169>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant9'
 * '<S170>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CenterGraphicAlertGen/Subsystem1'
 * '<S171>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CenterGraphicAlertGen/Subsystem1/S_R'
 * '<S172>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CenterGraphicAlertGen/Subsystem1/Turn On Delay Time'
 * '<S173>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CenterGraphicAlertGen/Subsystem1/Turn On Delay Time/EdgeRising1'
 * '<S174>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/CheckDNNFlag/DNNCheck'
 * '<S175>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/LeftGraphicAlertGen/Enumerated Constant1'
 * '<S176>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/LeftGraphicAlertGen/Enumerated Constant10'
 * '<S177>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/LeftGraphicAlertGen/Enumerated Constant2'
 * '<S178>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/LeftGraphicAlertGen/Enumerated Constant6'
 * '<S179>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/LeftGraphicAlertGen/Enumerated Constant7'
 * '<S180>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/LeftGraphicAlertGen/Enumerated Constant9'
 * '<S181>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/RightGraphicAlertGen/Enumerated Constant1'
 * '<S182>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/RightGraphicAlertGen/Enumerated Constant10'
 * '<S183>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/RightGraphicAlertGen/Enumerated Constant2'
 * '<S184>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/RightGraphicAlertGen/Enumerated Constant6'
 * '<S185>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/RightGraphicAlertGen/Enumerated Constant7'
 * '<S186>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FPA_GraphicAlertGen/RightGraphicAlertGen/Enumerated Constant9'
 * '<S187>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/AlertFilterCHF'
 * '<S188>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/AlertFilterLHF'
 * '<S189>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/AlertFilterRHF'
 * '<S190>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Graphic_CHF'
 * '<S191>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Graphic_LHF'
 * '<S192>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Graphic_RHF'
 * '<S193>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem1'
 * '<S194>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem2'
 * '<S195>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem3'
 * '<S196>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Graphic_CHF/Enumerated Constant1'
 * '<S197>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Graphic_CHF/Enumerated Constant2'
 * '<S198>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Graphic_CHF/Enumerated Constant3'
 * '<S199>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Graphic_CHF/Enumerated Constant7'
 * '<S200>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Graphic_LHF/Enumerated Constant1'
 * '<S201>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Graphic_LHF/Enumerated Constant2'
 * '<S202>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Graphic_LHF/Enumerated Constant3'
 * '<S203>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Graphic_LHF/Enumerated Constant7'
 * '<S204>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Graphic_RHF/Enumerated Constant1'
 * '<S205>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Graphic_RHF/Enumerated Constant2'
 * '<S206>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Graphic_RHF/Enumerated Constant3'
 * '<S207>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Graphic_RHF/Enumerated Constant7'
 * '<S208>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem1/Enumerated Constant'
 * '<S209>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem1/Enumerated Constant1'
 * '<S210>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem1/Enumerated Constant2'
 * '<S211>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem1/Enumerated Constant3'
 * '<S212>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem1/Enumerated Constant4'
 * '<S213>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem1/Enumerated Constant5'
 * '<S214>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem1/Enumerated Constant6'
 * '<S215>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem1/S_R'
 * '<S216>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem1/Turn On Delay Time'
 * '<S217>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem1/Turn On Delay Time/EdgeRising1'
 * '<S218>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem2/Enumerated Constant'
 * '<S219>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem2/Enumerated Constant1'
 * '<S220>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem2/Enumerated Constant2'
 * '<S221>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem2/Enumerated Constant3'
 * '<S222>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem2/Enumerated Constant4'
 * '<S223>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem2/Enumerated Constant5'
 * '<S224>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem2/Enumerated Constant6'
 * '<S225>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem2/S_R'
 * '<S226>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem2/Turn On Delay Time'
 * '<S227>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem2/Turn On Delay Time/EdgeRising1'
 * '<S228>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem3/Enumerated Constant'
 * '<S229>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem3/Enumerated Constant1'
 * '<S230>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem3/Enumerated Constant2'
 * '<S231>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem3/Enumerated Constant3'
 * '<S232>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem3/Enumerated Constant4'
 * '<S233>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem3/Enumerated Constant5'
 * '<S234>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem3/Enumerated Constant6'
 * '<S235>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem3/S_R'
 * '<S236>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem3/Turn On Delay Time'
 * '<S237>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/FPA/FrontHysteresis/Subsystem3/Turn On Delay Time/EdgeRising1'
 * '<S238>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMChimeTypeUpdate/Enumerated Constant1'
 * '<S239>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMChimeTypeUpdate/Enumerated Constant2'
 * '<S240>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMChimeTypeUpdate/Enumerated Constant3'
 * '<S241>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/CheckIfFrontObjectPresent'
 * '<S242>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/Enumerated Constant'
 * '<S243>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/Enumerated Constant1'
 * '<S244>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/HoldPopUpRq'
 * '<S245>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpPriority1'
 * '<S246>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions'
 * '<S247>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/TimerForFrontSwitchPress'
 * '<S248>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/TimerForRearSwitchPress'
 * '<S249>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/TimerForVehKey'
 * '<S250>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/CheckIfFrontObjectPresent/ConvToNum'
 * '<S251>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/CheckIfFrontObjectPresent/ConvToNum1'
 * '<S252>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/CheckIfFrontObjectPresent/ConvToNum2'
 * '<S253>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/CheckIfFrontObjectPresent/Enumerated Constant6'
 * '<S254>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/CheckIfFrontObjectPresent/ConvToNum/Enumerated Constant6'
 * '<S255>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/CheckIfFrontObjectPresent/ConvToNum1/Enumerated Constant6'
 * '<S256>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/CheckIfFrontObjectPresent/ConvToNum2/Enumerated Constant6'
 * '<S257>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/HoldPopUpRq/BtnPrssTimer'
 * '<S258>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/HoldPopUpRq/Enumerated Constant1'
 * '<S259>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/HoldPopUpRq/Enumerated Constant6'
 * '<S260>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/HoldPopUpRq/BtnPrssTimer/OffTimer'
 * '<S261>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/HoldPopUpRq/BtnPrssTimer/OffTimer/RisingEdge'
 * '<S262>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/IDLE_HMI'
 * '<S263>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp'
 * '<S264>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic'
 * '<S265>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp'
 * '<S266>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/SpeedTooHigh'
 * '<S267>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/IDLE_HMI/Enumerated Constant'
 * '<S268>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/IDLE_HMI/Enumerated Constant1'
 * '<S269>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/IDLE_HMI/Enumerated Constant2'
 * '<S270>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_FAIL_BUTTONPRESS'
 * '<S271>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_SRV_BUTTONPRESS'
 * '<S272>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_WIPE_BUTTONPRESS'
 * '<S273>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_FAIL_BUTTONPRESS'
 * '<S274>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_SRV_BUTTONPRESS'
 * '<S275>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_TRLR_BUTTONPRESS'
 * '<S276>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_WIPE_BUTTONPRESS'
 * '<S277>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/SYS_TEMP_NA_BUTTONPRESS'
 * '<S278>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_FAIL_BUTTONPRESS/Enumerated Constant1'
 * '<S279>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_FAIL_BUTTONPRESS/Enumerated Constant4'
 * '<S280>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_FAIL_BUTTONPRESS/Enumerated Constant5'
 * '<S281>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_FAIL_BUTTONPRESS/Enumerated Constant6'
 * '<S282>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_FAIL_BUTTONPRESS/Enumerated Constant7'
 * '<S283>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_SRV_BUTTONPRESS/Enumerated Constant1'
 * '<S284>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_SRV_BUTTONPRESS/Enumerated Constant4'
 * '<S285>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_SRV_BUTTONPRESS/Enumerated Constant5'
 * '<S286>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_SRV_BUTTONPRESS/Enumerated Constant6'
 * '<S287>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_SRV_BUTTONPRESS/Enumerated Constant7'
 * '<S288>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_SRV_BUTTONPRESS/Enumerated Constant8'
 * '<S289>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_WIPE_BUTTONPRESS/Enumerated Constant1'
 * '<S290>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_WIPE_BUTTONPRESS/Enumerated Constant4'
 * '<S291>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_WIPE_BUTTONPRESS/Enumerated Constant5'
 * '<S292>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_WIPE_BUTTONPRESS/Enumerated Constant6'
 * '<S293>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_WIPE_BUTTONPRESS/Enumerated Constant7'
 * '<S294>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/FT_WIPE_BUTTONPRESS/Enumerated Constant8'
 * '<S295>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_FAIL_BUTTONPRESS/Enumerated Constant1'
 * '<S296>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_FAIL_BUTTONPRESS/Enumerated Constant10'
 * '<S297>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_FAIL_BUTTONPRESS/Enumerated Constant11'
 * '<S298>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_FAIL_BUTTONPRESS/Enumerated Constant4'
 * '<S299>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_FAIL_BUTTONPRESS/Enumerated Constant5'
 * '<S300>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_SRV_BUTTONPRESS/Enumerated Constant1'
 * '<S301>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_SRV_BUTTONPRESS/Enumerated Constant10'
 * '<S302>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_SRV_BUTTONPRESS/Enumerated Constant11'
 * '<S303>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_SRV_BUTTONPRESS/Enumerated Constant2'
 * '<S304>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_SRV_BUTTONPRESS/Enumerated Constant3'
 * '<S305>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_SRV_BUTTONPRESS/Enumerated Constant4'
 * '<S306>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_SRV_BUTTONPRESS/Enumerated Constant5'
 * '<S307>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_SRV_BUTTONPRESS/Enumerated Constant6'
 * '<S308>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_SRV_BUTTONPRESS/Enumerated Constant7'
 * '<S309>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_SRV_BUTTONPRESS/Enumerated Constant8'
 * '<S310>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_TRLR_BUTTONPRESS/Detect Increase'
 * '<S311>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_TRLR_BUTTONPRESS/Enumerated Constant1'
 * '<S312>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_TRLR_BUTTONPRESS/Enumerated Constant10'
 * '<S313>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_TRLR_BUTTONPRESS/Enumerated Constant12'
 * '<S314>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_TRLR_BUTTONPRESS/Enumerated Constant4'
 * '<S315>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_TRLR_BUTTONPRESS/Enumerated Constant5'
 * '<S316>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_TRLR_BUTTONPRESS/Enumerated Constant6'
 * '<S317>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_TRLR_BUTTONPRESS/Enumerated Constant7'
 * '<S318>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_TRLR_BUTTONPRESS/Enumerated Constant8'
 * '<S319>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_TRLR_BUTTONPRESS/Enumerated Constant9'
 * '<S320>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_WIPE_BUTTONPRESS/Enumerated Constant1'
 * '<S321>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_WIPE_BUTTONPRESS/Enumerated Constant10'
 * '<S322>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_WIPE_BUTTONPRESS/Enumerated Constant11'
 * '<S323>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_WIPE_BUTTONPRESS/Enumerated Constant2'
 * '<S324>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_WIPE_BUTTONPRESS/Enumerated Constant3'
 * '<S325>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_WIPE_BUTTONPRESS/Enumerated Constant4'
 * '<S326>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_WIPE_BUTTONPRESS/Enumerated Constant5'
 * '<S327>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_WIPE_BUTTONPRESS/Enumerated Constant6'
 * '<S328>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_WIPE_BUTTONPRESS/Enumerated Constant7'
 * '<S329>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/RR_WIPE_BUTTONPRESS/Enumerated Constant8'
 * '<S330>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/SYS_TEMP_NA_BUTTONPRESS/Enumerated Constant1'
 * '<S331>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/SYS_TEMP_NA_BUTTONPRESS/Enumerated Constant10'
 * '<S332>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/SYS_TEMP_NA_BUTTONPRESS/Enumerated Constant11'
 * '<S333>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/SYS_TEMP_NA_BUTTONPRESS/Enumerated Constant4'
 * '<S334>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_ButtonPress_PopUp/SYS_TEMP_NA_BUTTONPRESS/Enumerated Constant5'
 * '<S335>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond1'
 * '<S336>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond2'
 * '<S337>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3'
 * '<S338>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond4'
 * '<S339>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond1/Enumerated Constant1'
 * '<S340>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond1/Enumerated Constant2'
 * '<S341>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond1/Enumerated Constant3'
 * '<S342>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond1/Enumerated Constant4'
 * '<S343>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond1/Enumerated Constant5'
 * '<S344>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond1/Enumerated Constant6'
 * '<S345>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond1/Enumerated Constant7'
 * '<S346>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond2/Enumerated Constant1'
 * '<S347>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond2/Enumerated Constant13'
 * '<S348>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond2/Enumerated Constant14'
 * '<S349>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond2/Enumerated Constant2'
 * '<S350>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond2/Enumerated Constant3'
 * '<S351>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond2/Enumerated Constant4'
 * '<S352>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond2/Enumerated Constant5'
 * '<S353>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond2/Enumerated Constant6'
 * '<S354>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3/Enumerated Constant1'
 * '<S355>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3/Enumerated Constant10'
 * '<S356>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3/Enumerated Constant11'
 * '<S357>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3/Enumerated Constant12'
 * '<S358>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3/Enumerated Constant13'
 * '<S359>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3/Enumerated Constant14'
 * '<S360>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3/Enumerated Constant15'
 * '<S361>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3/Enumerated Constant2'
 * '<S362>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3/Enumerated Constant3'
 * '<S363>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3/Enumerated Constant4'
 * '<S364>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3/Enumerated Constant5'
 * '<S365>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3/Enumerated Constant6'
 * '<S366>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3/Enumerated Constant7'
 * '<S367>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3/Enumerated Constant8'
 * '<S368>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond3/Enumerated Constant9'
 * '<S369>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond4/Enumerated Constant1'
 * '<S370>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond4/Enumerated Constant2'
 * '<S371>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond4/Enumerated Constant3'
 * '<S372>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond4/Enumerated Constant4'
 * '<S373>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond4/Enumerated Constant6'
 * '<S374>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_CarGraphic/CarGraphicCond4/Enumerated Constant7'
 * '<S375>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_SRV_STARTUP'
 * '<S376>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_TRLR_STARTUP1'
 * '<S377>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_WIPE_STARTUP'
 * '<S378>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_STARTUP'
 * '<S379>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_TEMP_NA_STARTUP'
 * '<S380>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_RR_SRV_STARTUP'
 * '<S381>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_RR_TRLR_STARTUP1'
 * '<S382>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_RR_WIPE_STARTUP'
 * '<S383>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_STARTUP'
 * '<S384>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_SRV_STARTUP'
 * '<S385>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_TEMP_NA_STARTUP'
 * '<S386>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_TRLR_STARTUP1'
 * '<S387>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_WIPE_STARTUP'
 * '<S388>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/SYS_FAIL_STARTUP'
 * '<S389>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/SYS_TEMP_NA_STARTUP'
 * '<S390>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_SRV_STARTUP/Enumerated Constant1'
 * '<S391>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_SRV_STARTUP/Enumerated Constant10'
 * '<S392>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_SRV_STARTUP/Enumerated Constant2'
 * '<S393>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_SRV_STARTUP/Enumerated Constant4'
 * '<S394>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_SRV_STARTUP/Enumerated Constant8'
 * '<S395>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_TRLR_STARTUP1/Enumerated Constant1'
 * '<S396>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_TRLR_STARTUP1/Enumerated Constant10'
 * '<S397>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_TRLR_STARTUP1/Enumerated Constant4'
 * '<S398>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_TRLR_STARTUP1/Enumerated Constant8'
 * '<S399>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_WIPE_STARTUP/Enumerated Constant10'
 * '<S400>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_WIPE_STARTUP/Enumerated Constant2'
 * '<S401>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_WIPE_STARTUP/Enumerated Constant4'
 * '<S402>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_RR_WIPE_STARTUP/Enumerated Constant8'
 * '<S403>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_STARTUP/Enumerated Constant10'
 * '<S404>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_STARTUP/Enumerated Constant2'
 * '<S405>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_STARTUP/Enumerated Constant3'
 * '<S406>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_STARTUP/Enumerated Constant4'
 * '<S407>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_SRV_STARTUP/Enumerated Constant8'
 * '<S408>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_TEMP_NA_STARTUP/Enumerated Constant2'
 * '<S409>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_TEMP_NA_STARTUP/Enumerated Constant3'
 * '<S410>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_TEMP_NA_STARTUP/Enumerated Constant4'
 * '<S411>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_RR_SRV_STARTUP/Enumerated Constant10'
 * '<S412>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_RR_SRV_STARTUP/Enumerated Constant2'
 * '<S413>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_RR_SRV_STARTUP/Enumerated Constant4'
 * '<S414>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_RR_SRV_STARTUP/Enumerated Constant8'
 * '<S415>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_RR_TRLR_STARTUP1/Enumerated Constant1'
 * '<S416>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_RR_TRLR_STARTUP1/Enumerated Constant10'
 * '<S417>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_RR_TRLR_STARTUP1/Enumerated Constant4'
 * '<S418>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_RR_TRLR_STARTUP1/Enumerated Constant8'
 * '<S419>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_RR_WIPE_STARTUP/Enumerated Constant10'
 * '<S420>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_RR_WIPE_STARTUP/Enumerated Constant2'
 * '<S421>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_RR_WIPE_STARTUP/Enumerated Constant4'
 * '<S422>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_RR_WIPE_STARTUP/Enumerated Constant8'
 * '<S423>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_STARTUP/Enumerated Constant10'
 * '<S424>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_STARTUP/Enumerated Constant2'
 * '<S425>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_STARTUP/Enumerated Constant3'
 * '<S426>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_STARTUP/Enumerated Constant4'
 * '<S427>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/FT_WIPE_STARTUP/Enumerated Constant8'
 * '<S428>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_SRV_STARTUP/Enumerated Constant10'
 * '<S429>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_SRV_STARTUP/Enumerated Constant2'
 * '<S430>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_SRV_STARTUP/Enumerated Constant3'
 * '<S431>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_SRV_STARTUP/Enumerated Constant4'
 * '<S432>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_SRV_STARTUP/Enumerated Constant8'
 * '<S433>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_TEMP_NA_STARTUP/Enumerated Constant2'
 * '<S434>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_TEMP_NA_STARTUP/Enumerated Constant3'
 * '<S435>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_TEMP_NA_STARTUP/Enumerated Constant4'
 * '<S436>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_TRLR_STARTUP1/Enumerated Constant1'
 * '<S437>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_TRLR_STARTUP1/Enumerated Constant10'
 * '<S438>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_TRLR_STARTUP1/Enumerated Constant4'
 * '<S439>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_TRLR_STARTUP1/Enumerated Constant8'
 * '<S440>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_WIPE_STARTUP/Enumerated Constant10'
 * '<S441>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_WIPE_STARTUP/Enumerated Constant2'
 * '<S442>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_WIPE_STARTUP/Enumerated Constant3'
 * '<S443>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_WIPE_STARTUP/Enumerated Constant4'
 * '<S444>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/RR_WIPE_STARTUP/Enumerated Constant8'
 * '<S445>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/SYS_FAIL_STARTUP/Enumerated Constant2'
 * '<S446>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/SYS_FAIL_STARTUP/Enumerated Constant3'
 * '<S447>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/SYS_FAIL_STARTUP/Enumerated Constant4'
 * '<S448>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/SYS_FAIL_STARTUP/Enumerated Constant6'
 * '<S449>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/SYS_TEMP_NA_STARTUP/Enumerated Constant2'
 * '<S450>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/SYS_TEMP_NA_STARTUP/Enumerated Constant3'
 * '<S451>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/SYS_TEMP_NA_STARTUP/Enumerated Constant4'
 * '<S452>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/PAM_StartUp_PopUp/SYS_TEMP_NA_STARTUP/Enumerated Constant6'
 * '<S453>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/SpeedTooHigh/SPEED_TOO_HIGH'
 * '<S454>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/SpeedTooHigh/SPEED_TOO_HIGH/Enumerated Constant1'
 * '<S455>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/SpeedTooHigh/SPEED_TOO_HIGH/Enumerated Constant10'
 * '<S456>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/SpeedTooHigh/SPEED_TOO_HIGH/Enumerated Constant2'
 * '<S457>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/SpeedTooHigh/SPEED_TOO_HIGH/Enumerated Constant3'
 * '<S458>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/SpeedTooHigh/SPEED_TOO_HIGH/Enumerated Constant4'
 * '<S459>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/SpeedTooHigh/SPEED_TOO_HIGH/Enumerated Constant5'
 * '<S460>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/SpeedTooHigh/SPEED_TOO_HIGH/Enumerated Constant6'
 * '<S461>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/SpeedTooHigh/SPEED_TOO_HIGH/Enumerated Constant7'
 * '<S462>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/PopUpRq_Conditions/SpeedTooHigh/SPEED_TOO_HIGH/Latch'
 * '<S463>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/TimerForFrontSwitchPress/OffTimer'
 * '<S464>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/TimerForFrontSwitchPress/OffTimer/DetectChange'
 * '<S465>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/TimerForRearSwitchPress/OffTimer'
 * '<S466>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/TimerForRearSwitchPress/OffTimer/DetectChange'
 * '<S467>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/TimerForVehKey/OffTimer'
 * '<S468>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMPopUpReq_Gen/TimerForVehKey/OffTimer/RisingEdge'
 * '<S469>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMVolumeGen/Enumerated Constant1'
 * '<S470>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMVolumeGen/Enumerated Constant10'
 * '<S471>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMVolumeGen/Enumerated Constant11'
 * '<S472>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMVolumeGen/Enumerated Constant2'
 * '<S473>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMVolumeGen/Enumerated Constant3'
 * '<S474>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMVolumeGen/Enumerated Constant4'
 * '<S475>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMVolumeGen/Enumerated Constant5'
 * '<S476>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMVolumeGen/Enumerated Constant6'
 * '<S477>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMVolumeGen/Enumerated Constant7'
 * '<S478>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMVolumeGen/Enumerated Constant8'
 * '<S479>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/PAMVolumeGen/Enumerated Constant9'
 * '<S480>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen'
 * '<S481>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen'
 * '<S482>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertUpdate'
 * '<S483>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen'
 * '<S484>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis'
 * '<S485>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant1'
 * '<S486>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant10'
 * '<S487>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant11'
 * '<S488>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant12'
 * '<S489>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant13'
 * '<S490>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant14'
 * '<S491>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant15'
 * '<S492>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant16'
 * '<S493>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant17'
 * '<S494>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant19'
 * '<S495>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant2'
 * '<S496>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant20'
 * '<S497>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant21'
 * '<S498>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant3'
 * '<S499>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant4'
 * '<S500>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant5'
 * '<S501>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant6'
 * '<S502>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant7'
 * '<S503>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant8'
 * '<S504>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/Enumerated Constant9'
 * '<S505>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/OffTimer'
 * '<S506>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/TimerForRearSwitchPress'
 * '<S507>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/OffTimer/Latch'
 * '<S508>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/OffTimer/RisingEdge'
 * '<S509>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/TimerForRearSwitchPress/OffTimer'
 * '<S510>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/AP_RearPAMLedStatusGen/TimerForRearSwitchPress/OffTimer/DetectChange'
 * '<S511>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1'
 * '<S512>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1'
 * '<S513>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant1'
 * '<S514>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant10'
 * '<S515>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant11'
 * '<S516>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant12'
 * '<S517>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant13'
 * '<S518>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant14'
 * '<S519>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant15'
 * '<S520>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant16'
 * '<S521>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant17'
 * '<S522>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant2'
 * '<S523>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant3'
 * '<S524>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant4'
 * '<S525>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant5'
 * '<S526>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant6'
 * '<S527>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant7'
 * '<S528>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant8'
 * '<S529>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/Enumerated Constant9'
 * '<S530>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/OffTimer'
 * '<S531>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/OffTimer/Latch'
 * '<S532>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/LeftChimeAlertGen1/OffTimer/RisingEdge'
 * '<S533>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant1'
 * '<S534>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant10'
 * '<S535>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant11'
 * '<S536>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant12'
 * '<S537>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant13'
 * '<S538>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant14'
 * '<S539>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant15'
 * '<S540>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant17'
 * '<S541>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant18'
 * '<S542>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant2'
 * '<S543>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant3'
 * '<S544>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant4'
 * '<S545>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant5'
 * '<S546>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant6'
 * '<S547>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant7'
 * '<S548>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant8'
 * '<S549>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/Enumerated Constant9'
 * '<S550>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/OffTimer'
 * '<S551>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/OffTimer/Latch'
 * '<S552>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertGen/RightChimeAlertGen1/OffTimer/RisingEdge'
 * '<S553>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertUpdate/Enumerated Constant1'
 * '<S554>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertUpdate/Enumerated Constant2'
 * '<S555>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertUpdate/Enumerated Constant7'
 * '<S556>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertUpdate/Enumerated Constant8'
 * '<S557>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertUpdate/Enumerated Constant9'
 * '<S558>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertUpdate/OffTimer'
 * '<S559>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertUpdate/OffTimer1'
 * '<S560>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertUpdate/OffTimer/Latch'
 * '<S561>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertUpdate/OffTimer/RisingEdge'
 * '<S562>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertUpdate/OffTimer1/Latch'
 * '<S563>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_ChimeAlertUpdate/OffTimer1/RisingEdge'
 * '<S564>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen'
 * '<S565>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CheckDNNFlag'
 * '<S566>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/LeftGraphicAlertGen'
 * '<S567>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/RightGraphicAlertGen'
 * '<S568>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant1'
 * '<S569>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant10'
 * '<S570>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant11'
 * '<S571>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant12'
 * '<S572>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant13'
 * '<S573>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant14'
 * '<S574>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant2'
 * '<S575>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant3'
 * '<S576>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant4'
 * '<S577>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant5'
 * '<S578>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant6'
 * '<S579>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant7'
 * '<S580>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant8'
 * '<S581>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Enumerated Constant9'
 * '<S582>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Subsystem1'
 * '<S583>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Subsystem1/S_R'
 * '<S584>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Subsystem1/Turn On Delay Time'
 * '<S585>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CenterGraphicAlertGen/Subsystem1/Turn On Delay Time/EdgeRising1'
 * '<S586>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/CheckDNNFlag/DNNCheck'
 * '<S587>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/LeftGraphicAlertGen/Enumerated Constant1'
 * '<S588>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/LeftGraphicAlertGen/Enumerated Constant10'
 * '<S589>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/LeftGraphicAlertGen/Enumerated Constant2'
 * '<S590>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/LeftGraphicAlertGen/Enumerated Constant6'
 * '<S591>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/LeftGraphicAlertGen/Enumerated Constant7'
 * '<S592>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/LeftGraphicAlertGen/Enumerated Constant9'
 * '<S593>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/RightGraphicAlertGen/Enumerated Constant1'
 * '<S594>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/RightGraphicAlertGen/Enumerated Constant10'
 * '<S595>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/RightGraphicAlertGen/Enumerated Constant2'
 * '<S596>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/RightGraphicAlertGen/Enumerated Constant6'
 * '<S597>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/RightGraphicAlertGen/Enumerated Constant7'
 * '<S598>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RPA_GraphicAlertGen/RightGraphicAlertGen/Enumerated Constant9'
 * '<S599>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/AlertFilterCHR'
 * '<S600>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/AlertFilterLHR'
 * '<S601>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/AlertFilterRHR'
 * '<S602>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Graphic_CHR'
 * '<S603>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Graphic_LHR'
 * '<S604>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Graphic_RHR'
 * '<S605>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem2'
 * '<S606>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem3'
 * '<S607>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem4'
 * '<S608>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Graphic_CHR/Enumerated Constant1'
 * '<S609>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Graphic_CHR/Enumerated Constant2'
 * '<S610>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Graphic_CHR/Enumerated Constant3'
 * '<S611>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Graphic_CHR/Enumerated Constant7'
 * '<S612>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Graphic_LHR/Enumerated Constant1'
 * '<S613>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Graphic_LHR/Enumerated Constant2'
 * '<S614>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Graphic_LHR/Enumerated Constant3'
 * '<S615>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Graphic_LHR/Enumerated Constant7'
 * '<S616>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Graphic_RHR/Enumerated Constant1'
 * '<S617>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Graphic_RHR/Enumerated Constant2'
 * '<S618>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Graphic_RHR/Enumerated Constant3'
 * '<S619>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Graphic_RHR/Enumerated Constant7'
 * '<S620>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem2/Enumerated Constant'
 * '<S621>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem2/Enumerated Constant1'
 * '<S622>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem2/Enumerated Constant2'
 * '<S623>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem2/Enumerated Constant3'
 * '<S624>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem2/Enumerated Constant4'
 * '<S625>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem2/Enumerated Constant5'
 * '<S626>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem2/Enumerated Constant6'
 * '<S627>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem2/S_R'
 * '<S628>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem2/Turn On Delay Time'
 * '<S629>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem2/Turn On Delay Time/EdgeRising1'
 * '<S630>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem3/Enumerated Constant'
 * '<S631>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem3/Enumerated Constant1'
 * '<S632>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem3/Enumerated Constant2'
 * '<S633>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem3/Enumerated Constant3'
 * '<S634>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem3/Enumerated Constant4'
 * '<S635>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem3/Enumerated Constant5'
 * '<S636>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem3/Enumerated Constant6'
 * '<S637>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem3/S_R'
 * '<S638>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem3/Turn On Delay Time'
 * '<S639>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem3/Turn On Delay Time/EdgeRising1'
 * '<S640>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem4/Enumerated Constant'
 * '<S641>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem4/Enumerated Constant1'
 * '<S642>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem4/Enumerated Constant2'
 * '<S643>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem4/Enumerated Constant3'
 * '<S644>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem4/Enumerated Constant4'
 * '<S645>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem4/Enumerated Constant5'
 * '<S646>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem4/Enumerated Constant6'
 * '<S647>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem4/S_R'
 * '<S648>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem4/Turn On Delay Time'
 * '<S649>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPA/RearHysteresis/Subsystem4/Turn On Delay Time/EdgeRising1'
 * '<S650>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/BrkReqStatusUpdate'
 * '<S651>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/DisableRearBraking'
 * '<S652>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/PAMStopCtrlStatusUpdate'
 * '<S653>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/RearDistHoldLogic'
 * '<S654>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/BrkReqStatusUpdate/Detect Increase'
 * '<S655>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/BrkReqStatusUpdate/Enumerated Constant1'
 * '<S656>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/DisableRearBraking/Compare To Constant'
 * '<S657>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/DisableRearBraking/Compare To Constant1'
 * '<S658>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/DisableRearBraking/Compare To Constant2'
 * '<S659>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/DisableRearBraking/Enumerated Constant'
 * '<S660>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/DisableRearBraking/Latch'
 * '<S661>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/DisableRearBraking/RateLimiter'
 * '<S662>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/DisableRearBraking/RateLimiter/Compare To Constant'
 * '<S663>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/DisableRearBraking/RateLimiter/Compare To Constant1'
 * '<S664>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/DisableRearBraking/RateLimiter/Compare To Constant2'
 * '<S665>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/PAMStopCtrlStatusUpdate/Enumerated Constant'
 * '<S666>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/PAMStopCtrlStatusUpdate/Enumerated Constant1'
 * '<S667>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/PAMStopCtrlStatusUpdate/Enumerated Constant2'
 * '<S668>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/PAMStopCtrlStatusUpdate/Enumerated Constant3'
 * '<S669>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/PAMStopCtrlStatusUpdate/Enumerated Constant4'
 * '<S670>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/PAMStopCtrlStatusUpdate/Enumerated Constant6'
 * '<S671>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/PAMStopCtrlStatusUpdate/Enumerated Constant7'
 * '<S672>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/PAMStopCtrlStatusUpdate/Enumerated Constant8'
 * '<S673>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/RPAwithBrk/RearDistHoldLogic/RearDistHold'
 * '<S674>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/SaveFeatureSts1/Enumerated Constant1'
 * '<S675>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/SaveFeatureSts1/Enumerated Constant2'
 * '<S676>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/SaveFeatureSts1/SavePreviousFrntStatus'
 * '<S677>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/SaveFeatureSts1/SavePreviousRearStatus'
 * '<S678>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/SaveFeatureSts1/SavePreviousFrntStatus/Enumerated Constant1'
 * '<S679>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/SaveFeatureSts1/SavePreviousFrntStatus/Enumerated Constant7'
 * '<S680>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/SaveFeatureSts1/SavePreviousRearStatus/Enumerated Constant1'
 * '<S681>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/SaveFeatureSts1/SavePreviousRearStatus/Enumerated Constant7'
 * '<S682>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/Subsystem/Compare To Constant'
 * '<S683>' : 'SWC_APA/SWC_APA/Rear_Front_ParkAssist/Subsystem/Compare To Constant1'
 * '<S684>' : 'SWC_APA/SWC_APA/SaveFeatureStsTrlr/Enumerated Constant'
 * '<S685>' : 'SWC_APA/SWC_APA/SaveFeatureStsTrlr/SavePreviousFrntStatus'
 * '<S686>' : 'SWC_APA/SWC_APA/SaveFeatureStsTrlr/SavePreviousFrntStatus/UpdateBothFeatureSts'
 * '<S687>' : 'SWC_APA/SWC_APA/SaveFeatureStsTrlr/SavePreviousFrntStatus/UpdateFPASts'
 * '<S688>' : 'SWC_APA/SWC_APA/SaveFeatureStsTrlr/SavePreviousFrntStatus/UpdateFPASts1'
 */
#endif                                 /* RTW_HEADER_SWC_APA_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
