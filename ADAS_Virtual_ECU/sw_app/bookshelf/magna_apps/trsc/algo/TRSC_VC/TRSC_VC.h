/*
 * File: TRSC_VC.h
 *
 * Code generated for Simulink model 'TRSC_VC'.
 *
 * Model version                  : 1.7705
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:52:03 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TRSC_VC_h_
#define RTW_HEADER_TRSC_VC_h_
#include <math.h>
#include <string.h>
#ifndef TRSC_VC_COMMON_INCLUDES_
# define TRSC_VC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* TRSC_VC_COMMON_INCLUDES_ */

#include "TRSC_VC_types.h"

/* Includes for objects with custom storage classes. */
#include "TRSC_CalibParams.h"
#include "rtsplntypes.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "rtGetInf.h"

/* user code (top of header file) */
#include "SignalDef.h"

/* Block signals for system '<S141>/Integrator_Subsytem1' */
#ifndef TRSC_VC_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T UnitDelay;                  /* '<S143>/Unit Delay' */
  real32_T Product;                    /* '<S143>/Product' */
} B_Integrator_Subsytem1_TRSC_VC_T;

#endif                                 /*TRSC_VC_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for system '<S141>/Integrator_Subsytem1' */
#ifndef TRSC_VC_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S143>/Unit Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S143>/Unit Delay1' */
} DW_Integrator_Subsytem1_TRSC_VC_T;

#endif                                 /*TRSC_VC_MDLREF_HIDE_CHILD_*/

/* Zero-crossing (trigger) state for system '<S141>/Integrator_Subsytem1' */
#ifndef TRSC_VC_MDLREF_HIDE_CHILD_

typedef struct {
  ZCSigState Integrator_Subsytem1_Reset_ZCE;/* '<S141>/Integrator_Subsytem1' */
} ZCE_Integrator_Subsytem1_TRSC_VC_T;

#endif                                 /*TRSC_VC_MDLREF_HIDE_CHILD_*/

/* Block signals for model 'TRSC_VC' */
#ifndef TRSC_VC_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T fv[3];
  real_T MinMax;                       /* '<S195>/MinMax' */
  real_T Sum;                          /* '<S181>/Sum' */
  real_T Product1;                     /* '<S141>/Product1' */
  real_T Identified_Case;              /* '<S122>/MATLAB Function' */
  real_T Gear_out;                     /* '<S1>/MATLAB Function' */
  real_T Sum1;                         /* '<S195>/Sum1' */
  real_T UnitDelay;                    /* '<S181>/Unit Delay' */
  real_T LookupTableDynamic;           /* '<S145>/Lookup Table Dynamic' */
  real_T Product;                      /* '<S142>/Product' */
  real_T Switch3;                      /* '<S195>/Switch3' */
  real_T Sum_h;                        /* '<S195>/Sum' */
  real_T Product2;                     /* '<S181>/Product2' */
  real_T Switch;                       /* '<S141>/Switch' */
  real_T ex;
  uint32_T Divide;                     /* '<S85>/Divide' */
  real32_T Gain5;                      /* '<S1>/Gain5' */
  real32_T Gain4;                      /* '<S1>/Gain4' */
  real32_T Gain2;                      /* '<S1>/Gain2' */
  real32_T Gain;                       /* '<S1>/Gain' */
  real32_T Switch_d;                   /* '<S14>/Switch' */
  real32_T Switch2;                    /* '<S14>/Switch2' */
  real32_T Gain13;                     /* '<S1>/Gain13' */
  real32_T Gain14;                     /* '<S1>/Gain14' */
  real32_T Switch_g;                   /* '<S16>/Switch' */
  real32_T Switch2_a;                  /* '<S16>/Switch2' */
  real32_T Add;                        /* '<S13>/Add' */
  real32_T Switch6;                    /* '<S1>/Switch6' */
  real32_T Gain3;                      /* '<S1>/Gain3' */
  real32_T Switch1;                    /* '<S1>/Switch1' */
  real32_T Switch_b;                   /* '<S15>/Switch' */
  real32_T Switch2_c;                  /* '<S15>/Switch2' */
  real32_T Switch_o;                   /* '<S103>/Switch' */
  real32_T Switch2_m;                  /* '<S103>/Switch2' */
  real32_T Gain15;                     /* '<S1>/Gain15' */
  real32_T Gain1;                      /* '<S1>/Gain1' */
  real32_T Gain7;                      /* '<S1>/Gain7' */
  real32_T Gain8;                      /* '<S1>/Gain8' */
  real32_T Gain1_h;                    /* '<S5>/Gain1' */
  real32_T Gain10;                     /* '<S1>/Gain10' */
  real32_T Gain9;                      /* '<S1>/Gain9' */
  real32_T DataTypeConversion17;       /* '<S1>/Data Type Conversion17' */
  real32_T Add_p;                      /* '<S6>/Add' */
  real32_T Gain19;                     /* '<S1>/Gain19' */
  real32_T Switch5;                    /* '<S1>/Switch5' */
  real32_T Constant2;                  /* '<S9>/Constant2' */
  real32_T DataTypeConversion5;        /* '<S1>/Data Type Conversion5' */
  real32_T Switch_f;                   /* '<S170>/Switch' */
  real32_T Switch4;                    /* '<S170>/Switch4' */
  real32_T Switch_gn;                  /* '<S187>/Switch' */
  real32_T Switch2_d;                  /* '<S187>/Switch2' */
  real32_T b_PI_k1;                    /* '<S178>/MATLAB Function2' */
  real32_T TBL_Failed;                 /* '<S178>/MATLAB Function2' */
  real32_T MaxPhiAngle_out;            /* '<S178>/MATLAB Function2' */
  real32_T MaxTadAngle_out;            /* '<S178>/MATLAB Function2' */
  real32_T Add_h;                      /* '<S183>/Add' */
  real32_T TADvec;   /* '<S177>/BusConversion_InsertedFor_LogOut_at_inport_0' */
  real32_T TAD01;    /* '<S177>/BusConversion_InsertedFor_LogOut_at_inport_0' */
  real32_T KeOTBL_m_HV_WheelBase;
                     /* '<S177>/BusConversion_InsertedFor_LogOut_at_inport_0' */
  real32_T TADvec_n; /* '<S185>/BusConversion_InsertedFor_LogOut_at_inport_0' */
  real32_T DiscreteTimeIntegrator;     /* '<S185>/Discrete-Time Integrator' */
  real32_T TAD01_a;  /* '<S185>/BusConversion_InsertedFor_LogOut_at_inport_0' */
  real32_T KeOTBL_m_HV_WheelBase_m;
                     /* '<S185>/BusConversion_InsertedFor_LogOut_at_inport_0' */
  real32_T Divide_m;                   /* '<S185>/Divide' */
  real32_T DelayOneStep;               /* '<S185>/Delay One Step' */
  real32_T DelayOneStep1;              /* '<S185>/Delay One Step1' */
  real32_T DataStoreRead3;             /* '<S170>/Data Store Read3' */
  real32_T Gain_g;                     /* '<S111>/Gain' */
  real32_T OutportBufferForMeCtrl_deg_frntwhlCommand;/* '<S108>/Controller_Main2' */
  real32_T Add1;                       /* '<S168>/Add1' */
  real32_T uDLookupTable_0_2;          /* '<S125>/1-D Lookup Table_0_2' */
  real32_T Yk1;                        /* '<S136>/Delay Input2' */
  real32_T deltariselimit;             /* '<S136>/delta rise limit' */
  real32_T KnobScalingLUT;             /* '<S117>/KnobScalingLUT' */
  real32_T Switch_d2;                  /* '<S144>/Switch' */
  real32_T Switch2_n;                  /* '<S144>/Switch2' */
  real32_T Product3;                   /* '<S146>/Product3' */
  real32_T Add_l;                      /* '<S146>/Add' */
  real32_T Switch_j;                   /* '<S147>/Switch' */
  real32_T UkYk1;                      /* '<S135>/Difference Inputs1' */
  real32_T Switch_bm;                  /* '<S139>/Switch' */
  real32_T Switch2_g;                  /* '<S139>/Switch2' */
  real32_T Yk;                         /* '<S135>/Difference Inputs2' */
  real32_T Switch_TAD_des_Final;       /* '<S117>/Switch_TAD_des_Final' */
  real32_T UkYk1_c;                    /* '<S136>/Difference Inputs1' */
  real32_T deltafalllimit;             /* '<S136>/delta fall limit' */
  real32_T Switch_a;                   /* '<S140>/Switch' */
  real32_T Switch2_k;                  /* '<S140>/Switch2' */
  real32_T DifferenceInputs2;          /* '<S136>/Difference Inputs2' */
  real32_T Add6;                       /* '<S117>/Add6' */
  real32_T Switch_am;                  /* '<S137>/Switch' */
  real32_T UkYk1_n;                    /* '<S134>/Difference Inputs1' */
  real32_T Switch_p;                   /* '<S138>/Switch' */
  real32_T Switch2_mv;                 /* '<S138>/Switch2' */
  real32_T Yk_p;                       /* '<S134>/Difference Inputs2' */
  real32_T Product3_g;                 /* '<S141>/Product3' */
  real32_T Divide6;                    /* '<S112>/Divide6' */
  real32_T tanVals;                    /* '<S123>/Switch4' */
  real32_T Switch_a4;                  /* '<S127>/Switch' */
  real32_T Switch2_l;                  /* '<S127>/Switch2' */
  real32_T Switch_m;                   /* '<S129>/Switch' */
  real32_T Switch2_f;                  /* '<S129>/Switch2' */
  real32_T DataTypeConversion1;        /* '<S113>/Data Type Conversion1' */
  real32_T UkYk1_k;                    /* '<S126>/Difference Inputs1' */
  real32_T Switch_c;                   /* '<S130>/Switch' */
  real32_T Switch2_mt;                 /* '<S130>/Switch2' */
  real32_T Yk_j;                       /* '<S126>/Difference Inputs2' */
  real32_T Switch_l;                   /* '<S128>/Switch' */
  real32_T Switch2_e;                  /* '<S128>/Switch2' */
  real32_T Sum_m;                      /* '<S166>/Sum' */
  real32_T DataTypeConversion;         /* '<S122>/Data Type Conversion' */
  real32_T err;                        /* '<S159>/Sum1' */
  real32_T Switch_bb;                  /* '<S165>/Switch' */
  real32_T Switch2_i;                  /* '<S165>/Switch2' */
  real32_T Abs1;                       /* '<S159>/Abs1' */
  real32_T Abs;                        /* '<S159>/Abs' */
  real32_T DiscreteTimeIntegrator_o2;  /* '<S159>/Discrete-Time Integrator' */
  real32_T Add1_k;                     /* '<S159>/Add1' */
  real32_T Yk1_m;                      /* '<S163>/Delay Input2' */
  real32_T UkYk1_ks;                   /* '<S163>/Difference Inputs1' */
  real32_T deltariselimit_b;           /* '<S163>/delta rise limit' */
  real32_T deltafalllimit_n;           /* '<S163>/delta fall limit' */
  real32_T Switch_g3;                  /* '<S167>/Switch' */
  real32_T Switch2_b;                  /* '<S167>/Switch2' */
  real32_T DifferenceInputs2_g;        /* '<S163>/Difference Inputs2' */
  real32_T Switch_h;                   /* '<S164>/Switch' */
  real32_T Switch2_bd;                 /* '<S164>/Switch2' */
  real32_T Yk1_i;                      /* '<S156>/Delay Input2' */
  real32_T deltariselimit_m;           /* '<S156>/delta rise limit' */
  real32_T UkYk1_o;                    /* '<S156>/Difference Inputs1' */
  real32_T deltafalllimit_j;           /* '<S156>/delta fall limit' */
  real32_T Switch_a2;                  /* '<S161>/Switch' */
  real32_T Switch2_h;                  /* '<S161>/Switch2' */
  real32_T DifferenceInputs2_p;        /* '<S156>/Difference Inputs2' */
  real32_T Switch_aq;                  /* '<S157>/Switch' */
  real32_T Switch2_fb;                 /* '<S157>/Switch2' */
  real32_T TrqCMD;                     /* '<S122>/Switch4' */
  real32_T Product2_l;                 /* '<S159>/Product2' */
  real32_T Abs1_b;                     /* '<S116>/Abs1' */
  real32_T Abs_c;                      /* '<S116>/Abs' */
  real32_T Product1_i;                 /* '<S146>/Product1' */
  real32_T KeTRSC_k_const_P_gain;      /* '<S159>/MATLAB Function' */
  real32_T proportional_multiplier_table_type2or3;
                           /* '<S159>/proportional_multiplier_table_type2or3' */
  real32_T proportional_multiplier_table_type1;
                              /* '<S159>/proportional_multiplier_table_type1' */
  real32_T StrTqFB_P_Old;              /* '<S159>/Switch8' */
  real32_T Switch1_n;                  /* '<S159>/Switch1' */
  real32_T P_gain_lookup_table_type2;  /* '<S159>/P_gain_lookup_table_type2' */
  real32_T P_gain_lookup_table_type3;  /* '<S159>/P_gain_lookup_table_type3' */
  real32_T StrTqFB_P_Old_f;            /* '<S159>/P_gain_lookup_table_type1' */
  real32_T integrator_gain_table_type2or3;
                                   /* '<S159>/integrator_gain_table_type2or3' */
  real32_T integrator_gain_table_type1;
                                      /* '<S159>/integrator_gain_table_type1' */
  real32_T Add_h2;                     /* '<S158>/Add' */
  real32_T Product_g;                  /* '<S158>/Product' */
  real32_T Gain3_g;                    /* '<S158>/Gain3' */
  real32_T TrqCMD_i;                   /* '<S122>/Data Type Conversion2' */
  real32_T Product1_j;                 /* '<S150>/Product1' */
  real32_T Product3_j;                 /* '<S150>/Product3' */
  real32_T Add_k;                      /* '<S150>/Add' */
  real32_T Switch_cz;                  /* '<S151>/Switch' */
  real32_T Add_m;                      /* '<S153>/Add' */
  real32_T Add_pu;                     /* '<S142>/Add' */
  real32_T Product1_b;                 /* '<S117>/Product1' */
  real32_T IeLSCAN_m_TY;               /* '<S115>/Switch' */
  real32_T Add3;                       /* '<S115>/Add3' */
  real32_T uDLookupTable_0_2_m;        /* '<S133>/1-D Lookup Table_0_2' */
  real32_T IeLSCAN_m_TX;               /* '<S115>/Switch' */
  real32_T Add2;                       /* '<S115>/Add2' */
  real32_T Switch4_o;                  /* '<S133>/Switch4' */
  real32_T uDLookupTable_0_6;          /* '<S133>/1-D Lookup Table_0_6' */
  real32_T Gain1_k;                    /* '<S133>/Gain1' */
  real32_T Switch2_hj;                 /* '<S133>/Switch2' */
  real32_T Gain2_a;                    /* '<S133>/Gain2' */
  real32_T Switch3_f;                  /* '<S132>/Switch3' */
  real32_T uDLookupTable_0_3;          /* '<S132>/1-D Lookup Table_0_3' */
  real32_T uDLookupTable_0_2_c;        /* '<S132>/1-D Lookup Table_0_2' */
  real32_T Gain3_f;                    /* '<S132>/Gain3' */
  real32_T MeCtrl_deg_HeadingIn;       /* '<S114>/Add6' */
  real32_T Product_n;                  /* '<S131>/Product' */
  real32_T Add3_b;                     /* '<S131>/Add3' */
  real32_T Switch1_d;                  /* '<S131>/Switch1' */
  real32_T Add2_l;                     /* '<S131>/Add2' */
  real32_T Gain_h;                     /* '<S114>/Gain' */
  real32_T MeCtrl_deg_SteerAngIn_c;    /* '<S113>/Product' */
  real32_T Switch4_m;                  /* '<S125>/Switch4' */
  real32_T uDLookupTable_0_6_b;        /* '<S125>/1-D Lookup Table_0_6' */
  real32_T Gain1_e;                    /* '<S125>/Gain1' */
  real32_T Switch2_j;                  /* '<S125>/Switch2' */
  real32_T Gain2_b;                    /* '<S125>/Gain2' */
  real32_T Switch3_h;                  /* '<S124>/Switch3' */
  real32_T uDLookupTable_0_3_p;        /* '<S124>/1-D Lookup Table_0_3' */
  real32_T uDLookupTable_0_2_mx;       /* '<S124>/1-D Lookup Table_0_2' */
  real32_T Gain3_l;                    /* '<S124>/Gain3' */
  real32_T uDLookupTable_0_6_k;        /* '<S123>/1-D Lookup Table_0_6' */
  real32_T Gain1_g;                    /* '<S123>/Gain1' */
  real32_T speed_out;                  /* '<S1>/MATLAB Function2' */
  real32_T gamma_now_deg;              /* '<S1>/MATLAB Function1' */
  real32_T gamma_dot_deg;              /* '<S1>/MATLAB Function1' */
  real32_T Switch_ae;                  /* '<S105>/Switch' */
  real32_T Switch2_f4;                 /* '<S105>/Switch2' */
  real32_T OutportBufferForChange_In_Dir_Flag;/* '<S100>/KnobAngle' */
  real32_T OutportBufferForknob_dwn_change_flg;/* '<S100>/KnobAngle' */
  real32_T OutportBufferForknob_up_change_flg;/* '<S100>/KnobAngle' */
  real32_T knob_up_change_flg;         /* '<S100>/KnobAngle' */
  real32_T knob_dwn_change_flg;        /* '<S100>/KnobAngle' */
  real32_T Change_In_Dir_Flag;         /* '<S100>/KnobAngle' */
  real32_T DataTypeConversion_h;       /* '<S8>/Data Type Conversion' */
  real32_T IeLSCAN_Cnt_Gear;           /* '<S24>/Cast To Single5' */
  real32_T MeKM_k_Direction;           /* '<S34>/Driving_Direction' */
  real32_T IeLSCAN_Cnt_WhlPlsCntRR;    /* '<S24>/Cast To Single3' */
  real32_T IeLSCAN_Cnt_WhlPlsCntRL;    /* '<S24>/Cast To Single4' */
  real32_T Delay;                      /* '<S24>/Delay' */
  real32_T Delay1;                     /* '<S24>/Delay1' */
  real32_T Gain_c;                     /* '<S24>/Gain' */
  real32_T Gain1_h3;                   /* '<S24>/Gain1' */
  real32_T Gain2_bd;                   /* '<S24>/Gain2' */
  real32_T IeLSCAN_v_VehSpd;           /* '<S27>/Divide' */
  real32_T Saturation;                 /* '<S24>/Saturation' */
  real32_T Product_k;                  /* '<S43>/Product' */
  real32_T UnitDelay_h;                /* '<S28>/Unit Delay' */
  real32_T Subtract2[3];               /* '<S42>/Subtract2' */
  real32_T Selector;                   /* '<S68>/Selector' */
  real32_T MeKM_k_WhlAngl;             /* '<S34>/Add' */
  real32_T Selector1;                  /* '<S68>/Selector1' */
  real32_T uDLookupTable_0_2_o;        /* '<S79>/1-D Lookup Table_0_2' */
  real32_T MaKM_k_P_next[9];           /* '<S58>/Add2' */
  real32_T Subtract3[9];               /* '<S41>/Subtract3' */
  real32_T MeKM_ddeg_YawRateWhlRPM;    /* '<S46>/Switch' */
  real32_T Subtract2_p[3];             /* '<S41>/Subtract2' */
  real32_T start_avg;                  /* '<S59>/Switch' */
  real32_T Selector_d;                 /* '<S67>/Selector' */
  real32_T uDLookupTable_0_2_h;        /* '<S76>/1-D Lookup Table_0_2' */
  real32_T Selector1_m;                /* '<S67>/Selector1' */
  real32_T MaKM_k_x_next[3];           /* '<S58>/Assignment2' */
  real32_T MeKM_k_YawRateWhlRPMEn;     /* '<S45>/Switch' */
  real32_T MeKM_k_yawrate;             /* '<S44>/Switch' */
  real32_T Product_a;                  /* '<S35>/Product' */
  real32_T IeLSCAN_deg_HV_H;           /* '<S35>/Switch' */
  real32_T MeKM_m_HV_X;                /* '<S26>/Product' */
  real32_T Add_b;                      /* '<S82>/Add' */
  real32_T Product_l;                  /* '<S85>/Product' */
  real32_T IeLSCAN_deg_TH;             /* '<S85>/Switch' */
  real32_T uDLookupTable_0_2_g;        /* '<S89>/1-D Lookup Table_0_2' */
  real32_T uDLookupTable_0_2_a;        /* '<S88>/1-D Lookup Table_0_2' */
  real32_T uDLookupTable_0_2_b;        /* '<S50>/1-D Lookup Table_0_2' */
  real32_T MeKM_m_HV_Y;                /* '<S26>/Product1' */
  real32_T Switch_e;                   /* '<S51>/Switch' */
  real32_T Add_pe;                     /* '<S97>/Add' */
  real32_T MeKM_ddeg_YawRateRPM_Bias;  /* '<S47>/Divide1' */
  real32_T DataTypeConversion1_d;      /* '<S46>/Data Type Conversion1' */
  real32_T DataTypeConversion2;        /* '<S46>/Data Type Conversion2' */
  real32_T YR;                         /* '<S48>/Selector' */
  real32_T Switch4_b;                  /* '<S89>/Switch4' */
  real32_T uDLookupTable_0_6_a;        /* '<S89>/1-D Lookup Table_0_6' */
  real32_T Gain1_n;                    /* '<S89>/Gain1' */
  real32_T Switch2_ju;                 /* '<S89>/Switch2' */
  real32_T Gain2_f;                    /* '<S89>/Gain2' */
  real32_T Switch4_j;                  /* '<S88>/Switch4' */
  real32_T uDLookupTable_0_6_h;        /* '<S88>/1-D Lookup Table_0_6' */
  real32_T Gain1_f;                    /* '<S88>/Gain1' */
  real32_T Switch2_dh;                 /* '<S88>/Switch2' */
  real32_T Gain2_n;                    /* '<S88>/Gain2' */
  real32_T Switch3_c;                  /* '<S87>/Switch3' */
  real32_T uDLookupTable_0_3_e;        /* '<S87>/1-D Lookup Table_0_3' */
  real32_T uDLookupTable_0_2_e;        /* '<S87>/1-D Lookup Table_0_2' */
  real32_T Gain3_c;                    /* '<S87>/Gain3' */
  real32_T Switch3_fz;                 /* '<S86>/Switch3' */
  real32_T uDLookupTable_0_3_n;        /* '<S86>/1-D Lookup Table_0_3' */
  real32_T uDLookupTable_0_2_f;        /* '<S86>/1-D Lookup Table_0_2' */
  real32_T Gain3_o;                    /* '<S86>/Gain3' */
  real32_T Add3_f;                     /* '<S85>/Add3' */
  real32_T Switch1_o;                  /* '<S85>/Switch1' */
  real32_T Add2_i;                     /* '<S85>/Add2' */
  real32_T Add3_m;                     /* '<S70>/Add3' */
  real32_T yr2;                        /* '<S69>/Product6' */
  real32_T Product7;                   /* '<S69>/Product7' */
  real32_T Switch4_h;                  /* '<S79>/Switch4' */
  real32_T uDLookupTable_0_6_i;        /* '<S79>/1-D Lookup Table_0_6' */
  real32_T Gain1_a;                    /* '<S79>/Gain1' */
  real32_T Switch2_ht;                 /* '<S79>/Switch2' */
  real32_T Gain2_fq;                   /* '<S79>/Gain2' */
  real32_T Switch3_j;                  /* '<S78>/Switch3' */
  real32_T uDLookupTable_0_3_f;        /* '<S78>/1-D Lookup Table_0_3' */
  real32_T uDLookupTable_0_2_i;        /* '<S78>/1-D Lookup Table_0_2' */
  real32_T Gain3_d;                    /* '<S78>/Gain3' */
  real32_T Switch4_d;                  /* '<S76>/Switch4' */
  real32_T uDLookupTable_0_6_hg;       /* '<S76>/1-D Lookup Table_0_6' */
  real32_T Gain1_ey;                   /* '<S76>/Gain1' */
  real32_T Switch2_ec;                 /* '<S76>/Switch2' */
  real32_T Gain2_ae;                   /* '<S76>/Gain2' */
  real32_T Switch3_p;                  /* '<S75>/Switch3' */
  real32_T uDLookupTable_0_3_m;        /* '<S75>/1-D Lookup Table_0_3' */
  real32_T uDLookupTable_0_2_of;       /* '<S75>/1-D Lookup Table_0_2' */
  real32_T Gain3_h;                    /* '<S75>/Gain3' */
  real32_T Add_o;                      /* '<S63>/Add' */
  real32_T Add_i;                      /* '<S62>/Add' */
  real32_T MeKM_deg_AvgTanAngle;       /* '<S61>/Switch' */
  real32_T tanVals_p;                  /* '<S64>/tan Lookup' */
  real32_T Divide_p;                   /* '<S61>/Divide' */
  real32_T Divide_j;                   /* '<S36>/Divide' */
  real32_T Add3_m3;                    /* '<S35>/Add3' */
  real32_T Switch1_c;                  /* '<S35>/Switch1' */
  real32_T Add2_p;                     /* '<S35>/Add2' */
  real32_T Gain_hg;                    /* '<S34>/Gain' */
  real32_T IeLSCAN_m_HV_Y;             /* '<S31>/Add' */
  real32_T MeKM_k_HeadingIn;           /* '<S30>/Add' */
  real32_T IeLSCAN_m_HV_X;             /* '<S29>/Add' */
  real32_T wN;                         /* '<S54>/Sum' */
  real32_T xN;                         /* '<S54>/Sum2' */
  real32_T Add_ol;                     /* '<S52>/Add' */
  real32_T Switch4_a;                  /* '<S50>/Switch4' */
  real32_T uDLookupTable_0_6_i0;       /* '<S50>/1-D Lookup Table_0_6' */
  real32_T Gain1_hs;                   /* '<S50>/Gain1' */
  real32_T Switch2_cz;                 /* '<S50>/Switch2' */
  real32_T Gain2_c;                    /* '<S50>/Gain2' */
  real32_T Switch3_e;                  /* '<S49>/Switch3' */
  real32_T uDLookupTable_0_3_l;        /* '<S49>/1-D Lookup Table_0_3' */
  real32_T uDLookupTable_0_2_j;        /* '<S49>/1-D Lookup Table_0_2' */
  real32_T Gain3_ot;                   /* '<S49>/Gain3' */
  real32_T HV_Speed_RearAxle;
             /* '<S24>/Host Vehicle Speed Calculation - Wheel Pulse_MODIFIED' */
  real32_T Delay_n;                    /* '<S7>/Delay' */
  real32_T Switch_n;                   /* '<S22>/Switch' */
  real32_T JackKnifeAngle;             /* '<S7>/MATLAB Function1' */
  real32_T DataTypeConversion8;        /* '<S1>/Data Type Conversion8' */
  real32_T Switch_k;                   /* '<S1>/Switch' */
  real32_T DataTypeConversion7;        /* '<S1>/Data Type Conversion7' */
  real32_T Product_b;                  /* '<S183>/Product' */
  real32_T UnitDelay1;                 /* '<S168>/Unit Delay1' */
  real32_T TmpSignalConversionAtLookupTableDynamic1Inport3[2];
  real32_T LookupTableDynamic1;        /* '<S113>/Lookup Table Dynamic1' */
  real32_T sampletime;                 /* '<S136>/sample time' */
  real32_T Yk1_m2;                     /* '<S135>/Resettable Delay' */
  real32_T Yk1_l;                      /* '<S134>/Resettable Delay' */
  real32_T Yk1_c;                      /* '<S126>/Resettable Delay' */
  real32_T Delay_d;                    /* '<S160>/Delay' */
  real32_T Delay_l;                    /* '<S166>/Delay' */
  real32_T sampletime_n;               /* '<S163>/sample time' */
  real32_T sampletime_g;               /* '<S156>/sample time' */
  real32_T LookupTableDynamic2;        /* '<S118>/Lookup Table Dynamic2' */
  real32_T LookupTableDynamic1_b;      /* '<S145>/Lookup Table Dynamic1' */
  real32_T LookupTableDynamic2_b;      /* '<S145>/Lookup Table Dynamic2' */
  real32_T Delay1_c;                   /* '<S158>/Delay1' */
  real32_T LookupTableDynamic2_k;      /* '<S120>/Lookup Table Dynamic2' */
  real32_T LookupTableDynamic1_j;      /* '<S120>/Lookup Table Dynamic1' */
  real32_T LookupTableDynamic_j;       /* '<S120>/Lookup Table Dynamic' */
  real32_T Product2_d;                 /* '<S116>/Product2' */
  real32_T Product5;                   /* '<S116>/Product5' */
  real32_T Product7_m;                 /* '<S116>/Product7' */
  real32_T Product9;                   /* '<S116>/Product9' */
  real32_T Product11;                  /* '<S116>/Product11' */
  real32_T Gain_n;                     /* '<S116>/Gain' */
  real32_T Gain1_hh;                   /* '<S116>/Gain1' */
  real32_T Gain2_o;                    /* '<S132>/Gain2' */
  real32_T Divide_n;                   /* '<S113>/Divide' */
  real32_T Add_b2;                     /* '<S113>/Add' */
  real32_T Gain2_i;                    /* '<S124>/Gain2' */
  real32_T Divide_k;                   /* '<S46>/Divide' */
  real32_T DataTypeConversion_c;       /* '<S46>/Data Type Conversion' */
  real32_T Divide4;                    /* '<S46>/Divide4' */
  real32_T Gain2_l;                    /* '<S87>/Gain2' */
  real32_T Gain2_on;                   /* '<S86>/Gain2' */
  real32_T Selector3;                  /* '<S70>/Selector3' */
  real32_T Divide_c;                   /* '<S69>/Divide' */
  real32_T Divide1;                    /* '<S69>/Divide1' */
  real32_T Divide6_p;                  /* '<S69>/Divide6' */
  real32_T Gain2_e;                    /* '<S78>/Gain2' */
  real32_T Gain2_eh;                   /* '<S75>/Gain2' */
  real32_T Gain2_d;                    /* '<S49>/Gain2' */
  real32_T Add_mf;                     /* '<S149>/Add' */
  real32_T uDLookupTable_0_1;          /* '<S133>/1-D Lookup Table_0_1' */
  real32_T uDLookupTable_0_1_i;        /* '<S125>/1-D Lookup Table_0_1' */
  real32_T uDLookupTable_0_1_g;        /* '<S123>/1-D Lookup Table_0_1' */
  real32_T Subtract3_a[9];             /* '<S40>/Subtract3' */
  real32_T Product4;                   /* '<S46>/Product4' */
  real32_T uDLookupTable_0_1_o;        /* '<S89>/1-D Lookup Table_0_1' */
  real32_T uDLookupTable_0_1_j;        /* '<S88>/1-D Lookup Table_0_1' */
  real32_T Product4_m;                 /* '<S70>/Product4' */
  real32_T Divide5;                    /* '<S69>/Divide5' */
  real32_T uDLookupTable_0_1_c;        /* '<S79>/1-D Lookup Table_0_1' */
  real32_T uDLookupTable_0_1_h;        /* '<S76>/1-D Lookup Table_0_1' */
  real32_T uDLookupTable_0_1_p;        /* '<S50>/1-D Lookup Table_0_1' */
  real32_T Product1_a;                 /* '<S158>/Product1' */
  real32_T Switch_jy;                  /* '<S158>/Switch' */
  real32_T Saturation_b;               /* '<S116>/Saturation' */
  real32_T Saturation2;                /* '<S116>/Saturation2' */
  real32_T Switch1_f;                  /* '<S170>/Switch1' */
  real32_T uDLookupTable_0_1_f;        /* '<S132>/1-D Lookup Table_0_1' */
  real32_T uDLookupTable_0_1_e;        /* '<S124>/1-D Lookup Table_0_1' */
  real32_T Assignment2[9];             /* '<S36>/Assignment2' */
  real32_T Selector_g;                 /* '<S74>/Selector' */
  real32_T uDLookupTable_0_1_im;       /* '<S87>/1-D Lookup Table_0_1' */
  real32_T uDLookupTable_0_1_l;        /* '<S86>/1-D Lookup Table_0_1' */
  real32_T uDLookupTable_0_1_jm;       /* '<S78>/1-D Lookup Table_0_1' */
  real32_T uDLookupTable_0_1_k;        /* '<S75>/1-D Lookup Table_0_1' */
  real32_T uDLookupTable_0_1_d;        /* '<S49>/1-D Lookup Table_0_1' */
  real32_T Selector1_a;                /* '<S73>/Selector1' */
  real32_T Switch2_du;                 /* '<S70>/Switch2' */
  real32_T Divide_pk;                  /* '<S112>/Divide' */
  real32_T Abs_d;                      /* '<S118>/Abs' */
  real32_T Add_kg;                     /* '<S148>/Add' */
  real32_T Divide8[9];                 /* '<S41>/Divide8' */
  real32_T Assignment1[3];             /* '<S58>/Assignment1' */
  real32_T Gain_k;                     /* '<Root>/Gain' */
  real32_T Divide5_h[9];               /* '<S41>/Divide5' */
  real32_T Product2_j;                 /* '<S67>/Product2' */
  real32_T Add_me;                     /* '<S143>/Add' */
  real32_T integrator_multiplier_table_type1;
                                /* '<S159>/integrator_multiplier_table_type1' */
  real32_T Add2_m;                     /* '<S67>/Add2' */
  real32_T Product_DesiredTAD;         /* '<S1>/Product_DesiredTAD' */
  real32_T DiscreteTimeIntegrator_o1;  /* '<S159>/Discrete-Time Integrator' */
  real32_T Selector2;                  /* '<S73>/Selector2' */
  real32_T Divide3[9];                 /* '<S41>/Divide3' */
  real32_T uwNxN;                      /* '<S54>/Product1' */
  real32_T u1wNxN1;                    /* '<S54>/Product2' */
  real32_T Product5_m;                 /* '<S159>/Product5' */
  real32_T Product_p;                  /* '<S145>/Product' */
  real32_T u1wN;                       /* '<S54>/Sum1' */
  real32_T gamma_now_deg_m;
  real32_T pulse_counter_RR;
  real32_T Dt;
  real32_T absx;
  real32_T b_absx;
  real32_T d;
  int32_T k;
  int_T idxDelay;
  TeTRSC_e_TrlrCalInfo DataTypeConversion12;/* '<S1>/Data Type Conversion12' */
  TeTRSC_e_SpdLmtReq MeTRSC_e_SpdLmtReq;/* '<S116>/Switch' */
  TeTRSC_e_SpdLmtReq Switch7;          /* '<S116>/Switch7' */
  TeTRSC_e_SpdLmtReq Switch1_m;        /* '<S116>/Switch1' */
  TeTRSC_e_SpdLmtReq Switch2_kv;       /* '<S116>/Switch2' */
  TeTRSC_e_SpdLmtReq Switch3_l;        /* '<S116>/Switch3' */
  TeTRSC_e_SpdLmtReq Switch4_g;        /* '<S116>/Switch4' */
  TeTRSC_e_SpdLmtReq Switch5_n;        /* '<S116>/Switch5' */
  TeTRSC_e_SpdLmtReq Switch9;          /* '<S116>/Switch9' */
  TeTRSC_e_SpdLmtReq DataTypeConversion3;/* '<S116>/Data Type Conversion3' */
  TeTRSC_e_SpdLmtReq DataTypeConversion9;/* '<S116>/Data Type Conversion9' */
  TeTRSC_e_SpdLmtReq Switch8;          /* '<S116>/Switch8' */
  TeTRSC_e_SpdLmtReq DataTypeConversion7_p;/* '<S116>/Data Type Conversion7' */
  uint16_T Switch_nf;                  /* '<S102>/Switch' */
  uint16_T Switch2_kvh;                /* '<S102>/Switch2' */
  int16_T DataTypeConversion_j;        /* '<S9>/Data Type Conversion' */
  int16_T UnitDelay1_j;                /* '<S9>/Unit Delay1' */
  int16_T DataTypeConversion1_g;       /* '<S9>/Data Type Conversion1' */
  int16_T DataTypeConversion4;         /* '<S9>/Data Type Conversion4' */
  int16_T In1;                         /* '<S106>/In1' */
  int16_T Switch_TAD_des_Final2;       /* '<S101>/Switch_TAD_des_Final2' */
  int16_T OutportBufferForChange_In_Dir;/* '<S100>/KnobAngle' */
  int16_T Computed_Out;                /* '<S100>/KnobAngle' */
  int16_T Rotary_Encoder_Btn;          /* '<S100>/KnobAngle' */
  int16_T Change_In_Dir;               /* '<S100>/KnobAngle' */
  int16_T Gain4_n;                     /* '<S101>/Gain4' */
  int16_T Add2_e;                      /* '<S101>/Add2' */
  uint8_T DataTypeConversion2_f;       /* '<S1>/Data Type Conversion2' */
  uint8_T DataTypeConversion4_h;       /* '<S1>/Data Type Conversion4' */
  uint8_T DataTypeConversion6;         /* '<S1>/Data Type Conversion6' */
  uint8_T UnitDelay_m;                 /* '<S170>/Unit Delay' */
  uint8_T Add1_g;                      /* '<S116>/Add1' */
  uint8_T Add5;                        /* '<S116>/Add5' */
  uint8_T Add3_n;                      /* '<S116>/Add3' */
  boolean_T LogicalOperator2;          /* '<S1>/Logical Operator2' */
  boolean_T Compare;                   /* '<S2>/Compare' */
  boolean_T LogicalOperator1;          /* '<S1>/Logical Operator1' */
  boolean_T Compare_b;                 /* '<S98>/Compare' */
  boolean_T AND;                       /* '<S9>/AND' */
  boolean_T Compare_f;                 /* '<S3>/Compare' */
  boolean_T DataTypeConversion_n;      /* '<S1>/Data Type Conversion' */
  boolean_T Compare_j;                 /* '<S188>/Compare' */
  boolean_T LogicalOperator3;          /* '<S19>/Logical Operator3' */
  boolean_T AND1;                      /* '<S170>/AND1' */
  boolean_T AND3;                      /* '<S170>/AND3' */
  boolean_T DataStoreRead2;            /* '<S170>/Data Store Read2' */
  boolean_T DataStoreRead;             /* '<S170>/Data Store Read' */
  boolean_T shallowTurn_out;           /* '<S178>/MATLAB Function2' */
  boolean_T DataStoreRead1;            /* '<S170>/Data Store Read1' */
  boolean_T DataStoreRead4;            /* '<S170>/Data Store Read4' */
  boolean_T Delay_lx;                  /* '<S108>/Delay' */
  boolean_T DataTypeConversion_m;      /* '<S108>/Data Type Conversion' */
  boolean_T RelationalOperator3;       /* '<S109>/Relational Operator3' */
  boolean_T LogicalOperator1_c;        /* '<S109>/Logical Operator1' */
  boolean_T LogicalOperator2_m;        /* '<S141>/Logical Operator2' */
  boolean_T LogicalOperator1_g;        /* '<S113>/Logical Operator1' */
  boolean_T Compare_p;                 /* '<S154>/Compare' */
  boolean_T RelationalOperator3_e;     /* '<S159>/Relational Operator3' */
  boolean_T LogicalOperator2_d;        /* '<S159>/Logical Operator2' */
  boolean_T LogicalOperator1_f;        /* '<S122>/Logical Operator1' */
  boolean_T RelationalOperator;        /* '<S158>/Relational Operator' */
  boolean_T NOT1;                      /* '<S101>/NOT1' */
  boolean_T RelationalOperator3_g;     /* '<S8>/Relational Operator3' */
  boolean_T UnitDelay5;                /* '<S24>/Unit Delay5' */
  boolean_T enable_RPM;                /* '<S46>/Switch1' */
  boolean_T DataTypeConversion3_e;     /* '<S33>/Data Type Conversion3' */
  boolean_T FixPtRelationalOperator;   /* '<S55>/FixPt Relational Operator' */
  boolean_T LogicalOperator4;          /* '<S24>/Logical Operator4' */
  boolean_T IeLSCAN_b_KM_RstRprt;      /* '<S33>/Relational Operator3' */
  boolean_T RelationalOperator2;       /* '<S33>/Relational Operator2' */
  boolean_T RelationalOperator1;       /* '<S33>/Relational Operator1' */
  boolean_T UnitDelay_g;               /* '<S56>/Unit Delay' */
  boolean_T MeKM_b_ResetKM;            /* '<S56>/Switch1' */
  boolean_T LogicalOperator;           /* '<S56>/Logical Operator' */
  boolean_T Delay2;                    /* '<S7>/Delay2' */
  boolean_T FixPtRelationalOperator_b; /* '<S20>/FixPt Relational Operator' */
  boolean_T Compare_fv;                /* '<S194>/Compare' */
  boolean_T LowerRelop1;               /* '<S187>/LowerRelop1' */
  boolean_T UpperRelop;                /* '<S187>/UpperRelop' */
  boolean_T RelationalOperator3_i;     /* '<S168>/Relational Operator3' */
  boolean_T Delay_p;                   /* '<S118>/Delay' */
  boolean_T RelationalOperator2_b;     /* '<S116>/Relational Operator2' */
  boolean_T RelationalOperator5;       /* '<S116>/Relational Operator5' */
  boolean_T RelationalOperator7;       /* '<S116>/Relational Operator7' */
  boolean_T RelationalOperator9;       /* '<S116>/Relational Operator9' */
  boolean_T RelationalOperator11;      /* '<S116>/Relational Operator11' */
  boolean_T RelationalOperator6;       /* '<S116>/Relational Operator6' */
  boolean_T RelationalOperator4;       /* '<S116>/Relational Operator4' */
  boolean_T RelationalOperator6_g;     /* '<S133>/Relational Operator6' */
  boolean_T RelationalOperator2_n;     /* '<S133>/Relational Operator2' */
  boolean_T RelationalOperator4_l;     /* '<S132>/Relational Operator4' */
  boolean_T RelationalOperator1_c;     /* '<S131>/Relational Operator1' */
  boolean_T RelationalOperator6_i;     /* '<S125>/Relational Operator6' */
  boolean_T RelationalOperator2_e;     /* '<S125>/Relational Operator2' */
  boolean_T RelationalOperator4_c;     /* '<S124>/Relational Operator4' */
  boolean_T RelationalOperator2_ba;    /* '<S101>/Relational Operator2' */
  boolean_T RelationalOperator6_a;     /* '<S89>/Relational Operator6' */
  boolean_T RelationalOperator2_p;     /* '<S89>/Relational Operator2' */
  boolean_T RelationalOperator6_o;     /* '<S88>/Relational Operator6' */
  boolean_T RelationalOperator2_l;     /* '<S88>/Relational Operator2' */
  boolean_T RelationalOperator4_b;     /* '<S87>/Relational Operator4' */
  boolean_T RelationalOperator4_h;     /* '<S86>/Relational Operator4' */
  boolean_T RelationalOperator1_j;     /* '<S85>/Relational Operator1' */
  boolean_T RelationalOperator6_n;     /* '<S79>/Relational Operator6' */
  boolean_T RelationalOperator2_h;     /* '<S79>/Relational Operator2' */
  boolean_T RelationalOperator4_p;     /* '<S78>/Relational Operator4' */
  boolean_T RelationalOperator6_gk;    /* '<S76>/Relational Operator6' */
  boolean_T RelationalOperator2_i;     /* '<S76>/Relational Operator2' */
  boolean_T RelationalOperator4_a;     /* '<S75>/Relational Operator4' */
  boolean_T RelationalOperator1_d;     /* '<S35>/Relational Operator1' */
  boolean_T RelationalOperator6_f;     /* '<S50>/Relational Operator6' */
  boolean_T RelationalOperator2_bi;    /* '<S50>/Relational Operator2' */
  boolean_T RelationalOperator4_b4;    /* '<S49>/Relational Operator4' */
  boolean_T RelationalOperator_e;      /* '<S195>/Relational Operator' */
  boolean_T LogicalOperator_g;         /* '<S19>/Logical Operator' */
  boolean_T LogicalOperator2_b;        /* '<S168>/Logical Operator2' */
  boolean_T Compare_h;                 /* '<S173>/Compare' */
  boolean_T LogicalOperator1_a;        /* '<S174>/Logical Operator1' */
  boolean_T LogicalOperator_e;         /* '<S158>/Logical Operator' */
  boolean_T Compare_m;                 /* '<S189>/Compare' */
  boolean_T AND4;                      /* '<S170>/AND4' */
  boolean_T Switch5_j;                 /* '<S170>/Switch5' */
  boolean_T Compare_mp;                /* '<S193>/Compare' */
  boolean_T RelationalOperator1_g;     /* '<S116>/Relational Operator1' */
  boolean_T RelationalOperator1_f;     /* '<S45>/Relational Operator1' */
  boolean_T RelationalOperator1_e;     /* '<S51>/Relational Operator1' */
  boolean_T LogicalOperator_c;         /* '<S51>/Logical Operator' */
  boolean_T LogicalOperator1_fq;       /* '<S45>/Logical Operator1' */
  boolean_T UpperRelop_m;              /* '<S157>/UpperRelop' */
  boolean_T RelationalOperator_f;      /* '<S116>/Relational Operator' */
  B_Integrator_Subsytem1_TRSC_VC_T Integrator_Subsytem1_j;/* '<S150>/Integrator_Subsytem1' */
  B_Integrator_Subsytem1_TRSC_VC_T Integrator_Subsytem2;/* '<S146>/Integrator_Subsytem2' */
  B_Integrator_Subsytem1_TRSC_VC_T Integrator_Subsytem1_g;/* '<S146>/Integrator_Subsytem1' */
  B_Integrator_Subsytem1_TRSC_VC_T Integrator_Subsytem1;/* '<S141>/Integrator_Subsytem1' */
} B_TRSC_VC_c_T;

#endif                                 /*TRSC_VC_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'TRSC_VC' */
#ifndef TRSC_VC_MDLREF_HIDE_CHILD_

typedef struct {
  real_T UnitDelay3_DSTATE;            /* '<S195>/UnitDelay3' */
  real_T UnitDelay_DSTATE;             /* '<S181>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S142>/Unit Delay1' */
  real_T errorIntVec[121];             /* '<S178>/MATLAB Function2' */
  real_T last_Identified_Case;         /* '<S122>/MATLAB Function' */
  real_T Add_DWORK1;                   /* '<S142>/Add' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S19>/Scope' */

  struct {
    void *LoggedData[4];
  } Scope1_PWORK;                      /* '<S19>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_n;                     /* '<S177>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_f;                     /* '<S168>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_e;                     /* '<S120>/Scope' */

  void* m_bpDataSet;                   /* '<S78>/1-D Lookup Table_0_2' */
  void* TWork[6];                      /* '<S78>/1-D Lookup Table_0_2' */
  void* SWork[9];                      /* '<S78>/1-D Lookup Table_0_2' */
  void* m_bpDataSet_i;                 /* '<S75>/1-D Lookup Table_0_2' */
  void* TWork_d[6];                    /* '<S75>/1-D Lookup Table_0_2' */
  void* SWork_k[9];                    /* '<S75>/1-D Lookup Table_0_2' */
  real32_T UnitDelay_DSTATE_f;         /* '<Root>/Unit Delay' */
  real32_T Delay2_DSTATE;              /* '<S170>/Delay2' */
  real32_T UnitDelay1_DSTATE_o;        /* '<S170>/Unit Delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S185>/Discrete-Time Integrator' */
  real32_T DelayOneStep_DSTATE[100];   /* '<S185>/Delay One Step' */
  real32_T DelayOneStep1_DSTATE[100];  /* '<S185>/Delay One Step1' */
  real32_T UnitDelay1_DSTATE_d;        /* '<S168>/Unit Delay1' */
  real32_T DelayInput2_DSTATE;         /* '<S136>/Delay Input2' */
  real32_T ResettableDelay_DSTATE;     /* '<S135>/Resettable Delay' */
  real32_T ResettableDelay_DSTATE_e;   /* '<S134>/Resettable Delay' */
  real32_T ResettableDelay_DSTATE_i;   /* '<S126>/Resettable Delay' */
  real32_T Delay_DSTATE;               /* '<S160>/Delay' */
  real32_T UnitDelay1_DSTATE_n;        /* '<S159>/Unit Delay1' */
  real32_T Delay_DSTATE_f;             /* '<S166>/Delay' */
  real32_T UnitDelay2_DSTATE;          /* '<S159>/Unit Delay2' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S122>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S159>/Discrete-Time Integrator' */
  real32_T DelayInput2_DSTATE_p;       /* '<S163>/Delay Input2' */
  real32_T DelayInput2_DSTATE_d;       /* '<S156>/Delay Input2' */
  real32_T Delay1_DSTATE;              /* '<S158>/Delay1' */
  real32_T Delay_DSTATE_j;             /* '<S158>/Delay' */
  real32_T UnitDelay_DSTATE_fm;        /* '<S121>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_h;        /* '<S121>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_d;         /* '<S153>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_b;        /* '<S153>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_p;         /* '<S142>/Unit Delay' */
  real32_T UnitDelay1_2_DSTATE;        /* '<S115>/Unit Delay1' */
  real32_T UnitDelay1_1_DSTATE;        /* '<S115>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_e;         /* '<S37>/Unit Delay' */
  real32_T Delay_DSTATE_k[5];          /* '<S24>/Delay' */
  real32_T Delay1_DSTATE_d[5];         /* '<S24>/Delay1' */
  real32_T UnitDelay1_DSTATE_m[3];     /* '<S24>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_k;         /* '<S28>/Unit Delay' */
  real32_T UnitDelay3_DSTATE_d[9];     /* '<S24>/Unit Delay3' */
  real32_T UnitDelay4_DSTATE;          /* '<S24>/Unit Delay4' */
  real32_T UnitDelay_DSTATE_dj;        /* '<S97>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_e;        /* '<S97>/Unit Delay1' */
  real32_T UnitDelay3_DSTATE_a;        /* '<S47>/Unit Delay3' */
  real32_T UnitDelay_DSTATE_b;         /* '<S63>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_bl;       /* '<S63>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_pb;        /* '<S62>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_a;        /* '<S62>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_m;         /* '<S31>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_p;        /* '<S31>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_m5;        /* '<S30>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_he;       /* '<S30>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_kq;        /* '<S29>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_nt;       /* '<S29>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_d1;        /* '<S54>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_oq;       /* '<S54>/Unit Delay1' */
  real32_T Delay_DSTATE_i;             /* '<S7>/Delay' */
  real32_T DelayInput1_DSTATE;         /* '<S20>/Delay Input1' */
  real32_T Online_FINAL_TBL;           /* '<S170>/Data Store Memory1' */
  real32_T prev_time;                  /* '<S178>/MATLAB Function2' */
  real32_T TAD_predz1[121];            /* '<S178>/MATLAB Function2' */
  real32_T MaxTadAngle;                /* '<S178>/MATLAB Function2' */
  real32_T MaxPhiAngle;                /* '<S178>/MATLAB Function2' */
  real32_T internal_timer;             /* '<S159>/MATLAB Function' */
  real32_T Add_DWORK1_h;               /* '<S158>/Add' */
  real32_T Divide1_DWORK3;             /* '<S40>/Divide1' */
  real32_T Divide1_DWORK4;             /* '<S40>/Divide1' */
  real32_T Divide1_DWORK5;             /* '<S40>/Divide1' */
  real32_T Divide1_DWORK4_m;           /* '<S42>/Divide1' */
  real32_T Divide1_DWORK4_b;           /* '<S41>/Divide1' */
  real32_T m_bpLambda;                 /* '<S78>/1-D Lookup Table_0_2' */
  real32_T m_yyA;                      /* '<S78>/1-D Lookup Table_0_2' */
  real32_T m_yyB;                      /* '<S78>/1-D Lookup Table_0_2' */
  real32_T m_yy2;                      /* '<S78>/1-D Lookup Table_0_2' */
  real32_T m_up[91];                   /* '<S78>/1-D Lookup Table_0_2' */
  real32_T m_y2[91];                   /* '<S78>/1-D Lookup Table_0_2' */
  real32_T m_bpLambda_o;               /* '<S75>/1-D Lookup Table_0_2' */
  real32_T m_yyA_d;                    /* '<S75>/1-D Lookup Table_0_2' */
  real32_T m_yyB_o;                    /* '<S75>/1-D Lookup Table_0_2' */
  real32_T m_yy2_a;                    /* '<S75>/1-D Lookup Table_0_2' */
  real32_T m_up_j[91];                 /* '<S75>/1-D Lookup Table_0_2' */
  real32_T m_y2_j[91];                 /* '<S75>/1-D Lookup Table_0_2' */
  int32_T Divide1_DWORK2;              /* '<S40>/Divide1' */
  uint32_T m_bpIndex;                  /* '<S78>/1-D Lookup Table_0_2' */
  uint32_T m_bpIndex_i;                /* '<S75>/1-D Lookup Table_0_2' */
  int16_T UnitDelay1_DSTATE_g;         /* '<S9>/Unit Delay1' */
  int16_T Prev_CAN_In_Rotary_Encoder_Btn;/* '<S100>/KnobAngle' */
  int16_T Prev_Change_In_Dir;          /* '<S100>/KnobAngle' */
  uint16_T i;                          /* '<S100>/KnobAngle' */
  uint16_T j;                          /* '<S100>/KnobAngle' */
  uint8_T UnitDelay_DSTATE_kg;         /* '<S170>/Unit Delay' */
  boolean_T UnitDelay2_DSTATE_o;       /* '<S1>/Unit Delay2' */
  boolean_T UnitDelay2_DSTATE_a;       /* '<S9>/Unit Delay2' */
  boolean_T UnitDelay_DSTATE_n;        /* '<S9>/Unit Delay' */
  boolean_T DelayOneStep1_DSTATE_d;    /* '<S170>/Delay One Step1' */
  boolean_T DelayOneStep_DSTATE_d;     /* '<S170>/Delay One Step' */
  boolean_T DelayOneStep2_DSTATE;      /* '<S170>/Delay One Step2' */
  boolean_T Delay_DSTATE_d[2];         /* '<S108>/Delay' */
  boolean_T Delay_DSTATE_o[4];         /* '<S118>/Delay' */
  boolean_T Delay_DSTATE_kg;           /* '<S109>/Delay' */
  boolean_T UnitDelay1_DSTATE_ed;      /* '<S122>/Unit Delay1' */
  boolean_T Delay2_DSTATE_o;           /* '<S158>/Delay2' */
  boolean_T UnitDelay5_DSTATE;         /* '<S24>/Unit Delay5' */
  boolean_T DelayInput1_DSTATE_g;      /* '<S55>/Delay Input1' */
  boolean_T UnitDelay_DSTATE_kz;       /* '<S56>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_pk;      /* '<S33>/Unit Delay1' */
  boolean_T Delay2_DSTATE_k;           /* '<S7>/Delay2' */
  int8_T DiscreteTimeIntegrator1_PrevResetState;/* '<S122>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S159>/Discrete-Time Integrator' */
  uint8_T icLoad;                      /* '<S135>/Resettable Delay' */
  uint8_T icLoad_k;                    /* '<S134>/Resettable Delay' */
  uint8_T icLoad_d;                    /* '<S126>/Resettable Delay' */
  uint8_T icLoad_j;                    /* '<S160>/Delay' */
  uint8_T icLoad_p;                    /* '<S166>/Delay' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING;/* '<S159>/Discrete-Time Integrator' */
  uint8_T is_active_c1_TRSC_VC;        /* '<S100>/KnobAngle' */
  uint8_T icLoad_c;                    /* '<S24>/Delay' */
  uint8_T icLoad_jq;                   /* '<S24>/Delay1' */
  uint8_T icLoad_m;                    /* '<S7>/Delay' */
  boolean_T TBLComputationDone;        /* '<S170>/Data Store Memory' */
  boolean_T OTBLReset;                 /* '<S170>/Data Store Memory2' */
  boolean_T prev_time_not_empty;       /* '<S178>/MATLAB Function2' */
  boolean_T Prev_knob_up_change_flg;   /* '<S100>/KnobAngle' */
  boolean_T Prev_knob_dwn_change_flg;  /* '<S100>/KnobAngle' */
  boolean_T TrailerBeamLength1_MODE;   /* '<S1>/Trailer Beam Length1' */
  boolean_T Subsystem_MODE;            /* '<S170>/Subsystem' */
  boolean_T OnlineTrailerBeamLengthEstimation_MODE;
                                /* '<S170>/OnlineTrailerBeamLengthEstimation' */
  boolean_T Controller_Main2_MODE;     /* '<S108>/Controller_Main2' */
  boolean_T THA_SteerTweakProfile_Processing2_MODE;
                                /* '<S122>/THA_SteerTweakProfile_Processing2' */
  boolean_T KnobAngleComp_MODE;        /* '<S9>/KnobAngleComp' */
  boolean_T DesiredTrailerAngleComp_MODE;/* '<S9>/DesiredTrailerAngleComp' */
  boolean_T KinematicModel_MODE;       /* '<S1>/Kinematic Model' */
  boolean_T KM_Integrator_Trapazoidal2_MODE;/* '<S24>/KM_Integrator_Trapazoidal2' */
  boolean_T KM_Integrator_Trapazoidal1_MODE;/* '<S24>/KM_Integrator_Trapazoidal1' */
  boolean_T KM_Integrator_Trapazoidal_MODE;/* '<S24>/KM_Integrator_Trapazoidal' */
  DW_Integrator_Subsytem1_TRSC_VC_T Integrator_Subsytem1_j;/* '<S150>/Integrator_Subsytem1' */
  DW_Integrator_Subsytem1_TRSC_VC_T Integrator_Subsytem2;/* '<S146>/Integrator_Subsytem2' */
  DW_Integrator_Subsytem1_TRSC_VC_T Integrator_Subsytem1_g;/* '<S146>/Integrator_Subsytem1' */
  DW_Integrator_Subsytem1_TRSC_VC_T Integrator_Subsytem1;/* '<S141>/Integrator_Subsytem1' */
} DW_TRSC_VC_f_T;

#endif                                 /*TRSC_VC_MDLREF_HIDE_CHILD_*/

/* Zero-crossing (trigger) state for model 'TRSC_VC' */
#ifndef TRSC_VC_MDLREF_HIDE_CHILD_

typedef struct {
  ZCSigState ResettableDelay_Reset_ZCE;/* '<S135>/Resettable Delay' */
  ZCSigState ResettableDelay_Reset_ZCE_a;/* '<S134>/Resettable Delay' */
  ZCSigState Delay_Reset_ZCE;          /* '<S118>/Delay' */
  ZCSigState ResettableDelay_Reset_ZCE_g;/* '<S126>/Resettable Delay' */
  ZCSigState TravDist_TrapIntegrator_Reset_ZCE;/* '<S109>/TravDist_TrapIntegrator' */
  ZCSigState TAD_ep1_Reset_ZCE;        /* '<S109>/TAD_ep1' */
  ZCSigState Integrator_Subsytem2_Reset_ZCE;/* '<S150>/Integrator_Subsytem2' */
  ZCE_Integrator_Subsytem1_TRSC_VC_T Integrator_Subsytem1_j;/* '<S150>/Integrator_Subsytem1' */
  ZCE_Integrator_Subsytem1_TRSC_VC_T Integrator_Subsytem2;/* '<S146>/Integrator_Subsytem2' */
  ZCE_Integrator_Subsytem1_TRSC_VC_T Integrator_Subsytem1_g;/* '<S146>/Integrator_Subsytem1' */
  ZCE_Integrator_Subsytem1_TRSC_VC_T Integrator_Subsytem1;/* '<S141>/Integrator_Subsytem1' */
  ZCSigState Integrator_Subsytem_Reset_ZCE;/* '<S141>/Integrator_Subsytem' */
  ZCSigState Path_Deviation_Reset_ZCE; /* '<S109>/Path_Deviation' */
  ZCSigState Heading_Deviation1_Reset_ZCE;/* '<S109>/Heading_Deviation1' */
  ZCSigState Kinematic_model_Reset_ZCE;/* '<S8>/Kinematic_model' */
  ZCSigState ResettableSubsystem_Reset_ZCE;/* '<S57>/ResettableSubsystem' */
} ZCE_TRSC_VC_T;

#endif                                 /*TRSC_VC_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for model 'TRSC_VC' */
#ifndef TRSC_VC_MDLREF_HIDE_CHILD_

typedef struct {
  const real32_T Gain16;               /* '<S1>/Gain16' */
  const real32_T Gain1;                /* '<S124>/Gain1' */
  const real32_T Gain4;                /* '<S125>/Gain4' */
  const real32_T DataTypeConversion2;  /* '<S159>/Data Type Conversion2' */
  const real32_T Gain1_e;              /* '<S132>/Gain1' */
  const real32_T Gain4_b;              /* '<S133>/Gain4' */
  const real32_T Gain1_o;              /* '<S49>/Gain1' */
  const real32_T Gain4_m;              /* '<S50>/Gain4' */
  const real32_T Gain1_d;              /* '<S75>/Gain1' */
  const real32_T Gain4_c;              /* '<S76>/Gain4' */
  const real32_T Gain1_i;              /* '<S78>/Gain1' */
  const real32_T Gain4_o;              /* '<S79>/Gain4' */
  const real32_T Gain1_h;              /* '<S86>/Gain1' */
  const real32_T Gain1_hh;             /* '<S87>/Gain1' */
  const real32_T Gain4_cf;             /* '<S88>/Gain4' */
  const real32_T Gain4_j;              /* '<S89>/Gain4' */
} ConstB_TRSC_VC_h_T;

#endif                                 /*TRSC_VC_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_VC_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_TRSC_VC_T {
  const char_T **errorStatus;
};

#endif                                 /*TRSC_VC_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_VC_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_TRSC_VC_T rtm;
} MdlrefDW_TRSC_VC_T;

#endif                                 /*TRSC_VC_MDLREF_HIDE_CHILD_*/

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern TbTRSC_InpBus IbTRSC_InpBus;    /* '<Root>/IbTRSC_InpBus'
                                        * IbTRSC_InpBus : TRSC state Machine Input signal bus , having following buses combined together:

                                          - Bus: TbTRSC_VehInpFromCAN2
                                          - Bus: TbTRSC_VehInpFromCAN14
                                          - Bus: TbTRSC_TrailerDetInp
                                          - Bus: TbTRSC_MEProxiToIpc
                                          - Bus: TbTRSC_SVStoTRSC

                                        */
extern TbTRSC_KM_MABx KM_MABx;         /* '<S8>/Bus Creator1'
                                        * KM_MABx
                                        */
extern real32_T IeTRSC_deg_FrntWhlAng; /* '<Root>/Data Type Conversion1'
                                        * DID Value of Front Road wheel angle
                                        */
extern real32_T IeTRSC_m_TrlrWhlBaseEff;/* '<Root>/Data Type Conversion'
                                         * DID value of Trailer Wheel Base effective
                                         */
extern real32_T IeTRSC_deg_TrlrAngKnob;/* '<Root>/Data Type Conversion2'
                                        * DID Value of Trailer Angle requested by the knob
                                        */
extern real32_T MeTRSC_deg_KnobAngle;  /* '<Root>/Data Type Conversion4' */
extern real32_T IeTRSC_deg_JackknifeThrAngle;/* '<Root>/Data Type Conversion3'
                                              * DID Value of JackknifeThresholdAngle
                                              */
extern real32_T MeTRSC_m_TrailerBeamLen;/* '<Root>/Data Type Conversion5' */
extern real32_T MeTRSC_deg_JackKnifeAngle;/* '<S1>/Data Type Conversion1' */
extern real32_T MeTRSC_deg_MaxAllowedTADAngle;/* '<S1>/Data Type Conversion10' */
extern real32_T MeTRSC_deg_JackknifeThrAngle;/* '<S1>/Data Type Conversion9' */
extern real32_T MeTRSC_pct_TRSCStrDmp; /* '<S1>/Data Type Conversion13'
                                        * Steering Damping command in %
                                        */
extern real32_T IeLSCAN_m_TrailerBeamLen;/* '<S170>/Saturation4'
                                          * IeLSCAN_m_TrailerBeamLen
                                          */
extern real32_T MeTRSC_M_TRSCStrTrq;   /* '<S17>/VehicleControl'
                                        * Steering Torque input from Vehicle Control
                                        */
extern real32_T MeTRSC_deg_StrCMD;     /* '<S17>/VehicleControl'
                                        * Steering Angle command in degree
                                        */
extern real32_T MeCtrl_deg_THInit;     /* '<S168>/Switch'
                                        * MeCtrl_deg_THInit
                                        */
extern real32_T MeCtrl_deg_HdgDevLookup;/* '<S119>/Lookup Table Dynamic'
                                         * MeCtrl_deg_HdgDevLookup
                                         */
extern real32_T MeCtrl_deg_TAD_des;    /* '<S147>/Switch2'
                                        * MeCtrl_deg_TAD_des
                                        */
extern real32_T MeCtrl_deg_TAD_error;  /* '<S137>/Switch2'
                                        * MeCtrl_deg_TAD_error
                                        */
extern real32_T MeTRSC_deg_TrlrAngKnob;/* '<S117>/Data Type Conversion1'
                                        * MeTRSC_deg_TrlrAngKnob
                                        */
extern real32_T MeCtrl_deg_TAD_PID;    /* '<S141>/Add'
                                        * Intermediate signal for Trailer Angle Detect for PID
                                        */
extern real32_T MeCtrl_deg_SteerAngIn; /* '<S113>/Switch1'
                                        * MeCtrl_deg_SteerAngIn
                                        */
extern real32_T MeCtrl_deg_SteerCMD;   /* '<S126>/Data Type Conversion'
                                        * MeCtrl_deg_SteerCMD
                                        */
extern real32_T StrCmd;                /* '<S160>/Sum'
                                        * StrCmd
                                        */
extern real32_T StrRpt;                /* '<S122>/Data Type Conversion1'
                                        * StrRpt
                                        */
extern real32_T MeTRSC_s_TwitchTmr;    /* '<S122>/Discrete-Time Integrator1'
                                        * MeTRSC_s_TwitchTmr
                                        */
extern real32_T MeTRSC_e_IdentifiedCase;/* '<S122>/Data Type Conversion3'
                                         * MeTRSC_e_IdentifiedCase
                                         */
extern real32_T MeCtrl_m_TravelDist;   /* '<S121>/Add'
                                        * MeCtrl_m_TravelDist
                                        */
extern real32_T MeCtrl_deg_PIDe_p;     /* '<S151>/Switch2'
                                        * MeCtrl_deg_PIDe_p
                                        */
extern real32_T MeTRA_deg_PathDeviation;/* '<S115>/Add5'
                                         * MeTRA_deg_PathDeviation
                                         */
extern real32_T MeCtrl_deg_HeadingOut; /* '<S131>/Switch'
                                        * Intermediate signal for Heading Output
                                        */
extern real32_T MeCtrl_deg_e_p;        /* '<S114>/Switch'
                                        * Intermediate signal for error
                                        */
extern real32_T MeCtrl_deg_HeadingDeviation;/* '<S114>/Add'
                                             * Intermediate signal for Heading Deviation
                                             */
extern real32_T MeTRSC_deg_RawDesTrlrAng;/* '<S99>/Product_DesiredTAD1  '
                                          * Intermediate signal for Raw value of desired trailer angle
                                          */
extern real32_T IeLSCAN_v_VehSp_pulse; /* '<S37>/Sum'
                                        * IeLSCAN_v_VehSp_pulse
                                        */
extern real32_T MeKM_deg_GyroYawRate;  /* '<S52>/Switch'
                                        * MeKM_deg_GyroYawRate
                                        */
extern real32_T JackKnifeAngle_deg;    /* '<S22>/Switch2'
                                        * JackKnifeAngle_deg
                                        */
extern int16_T MeTRSC_deg_KnobAngHys;  /* '<S101>/Switch_TAD_des_Final1'
                                        * Intermediate signal for Knob Angle (Output of knob hysteresis logic)
                                        */
extern boolean_T MeTRSC_b_TBLComputationDone;/* '<S1>/Trailer Beam Length1' */
extern boolean_T MeTRSC_b_TRAAct;      /* '<S19>/Logical Operator1'
                                        * TRA ACT
                                        */
extern boolean_T MeTRSC_b_OTBLReset;   /* '<S1>/Trailer Beam Length1'
                                        * OTBL Reset flag
                                        */
extern boolean_T MeOTBL_b_Enable_1;    /* '<S176>/Logical Operator1'
                                        * MeOTBL_b_Enable_1
                                        */
extern boolean_T MeOTBL_b_Enable;      /* '<S179>/Compare'
                                        * MeOTBL_b_Enable
                                        */
extern boolean_T MeTRSC_b_StrTwitchComplete;/* '<S17>/VehicleControl'
                                             * Steering Twitch Complete Status
                                             */
extern boolean_T MeTRSC_b_TwitchCompleted;/* '<S122>/Logical Operator'
                                           * MeTRSC_b_TwitchCompleted
                                           */
extern void TRSC_VC_Init(void);
extern void TRSC_VC_Start(void);
extern void TRSC_VC_Disable(TeTRSC_e_SpdLmtReq *rty_MeTRSC_e_SpdLmtReq);
extern void TRSC_VC(const TeTRSC_e_TRSCStat *rtu_MeTRSC_e_TRSCStat,
                    TeTRSC_e_TRSCStrTrqActvReq *rty_MeTRSC_e_TRSCStrTrqActvReq,
                    TeTRSC_e_SpdLmtReq *rty_MeTRSC_e_SpdLmtReq);

/* Model reference registration function */
extern void TRSC_VC_initialize(const char_T **rt_errorStatus);

#ifndef TRSC_VC_MDLREF_HIDE_CHILD_

extern void TRSC_VC_Integrator_Subsytem1_Init(DW_Integrator_Subsytem1_TRSC_VC_T *
  localDW);
extern void TRSC_VC_Integrator_Subsytem1_Reset(DW_Integrator_Subsytem1_TRSC_VC_T
  *localDW);
extern void TRSC_VC_Integrator_Subsytem1_Update(real32_T rtu_u, real32_T *rty_y,
  DW_Integrator_Subsytem1_TRSC_VC_T *localDW);
extern void TRSC_VC_Integrator_Subsytem1(real32_T rtu_t, boolean_T rtu_Reset,
  real32_T *rty_y, B_Integrator_Subsytem1_TRSC_VC_T *localB,
  DW_Integrator_Subsytem1_TRSC_VC_T *localDW, ZCE_Integrator_Subsytem1_TRSC_VC_T
  *localZCE);
extern void TRSC_VC_OTBL_Enable(void);
extern void TRSC_VC_OTBL_Enable1(void);

#endif                                 /*TRSC_VC_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_VC_MDLREF_HIDE_CHILD_

extern MdlrefDW_TRSC_VC_T TRSC_VC_MdlrefDW;

#endif                                 /*TRSC_VC_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_VC_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_TRSC_VC_c_T TRSC_VC_B;

/* Block states (default storage) */
extern DW_TRSC_VC_f_T TRSC_VC_DW;

/* Previous zero-crossings (trigger) states */
extern ZCE_TRSC_VC_T TRSC_VC_PrevZCX;

#endif                                 /*TRSC_VC_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'TRSC_VC'
 * '<S1>'   : 'TRSC_VC/TRSC_VC2'
 * '<S2>'   : 'TRSC_VC/TRSC_VC2/Compare To Constant'
 * '<S3>'   : 'TRSC_VC/TRSC_VC2/Compare To Constant2'
 * '<S4>'   : 'TRSC_VC/TRSC_VC2/Compare To Constant6'
 * '<S5>'   : 'TRSC_VC/TRSC_VC2/Degrees to Radians1'
 * '<S6>'   : 'TRSC_VC/TRSC_VC2/FrontAngleComp'
 * '<S7>'   : 'TRSC_VC/TRSC_VC2/JackKnife Angle '
 * '<S8>'   : 'TRSC_VC/TRSC_VC2/Kinematic Model'
 * '<S9>'   : 'TRSC_VC/TRSC_VC2/Knob_Sensing'
 * '<S10>'  : 'TRSC_VC/TRSC_VC2/MATLAB Function'
 * '<S11>'  : 'TRSC_VC/TRSC_VC2/MATLAB Function1'
 * '<S12>'  : 'TRSC_VC/TRSC_VC2/MATLAB Function2'
 * '<S13>'  : 'TRSC_VC/TRSC_VC2/MaxFrontAngleComp'
 * '<S14>'  : 'TRSC_VC/TRSC_VC2/Saturation Dynamic1'
 * '<S15>'  : 'TRSC_VC/TRSC_VC2/Saturation Dynamic2'
 * '<S16>'  : 'TRSC_VC/TRSC_VC2/Saturation Dynamic3'
 * '<S17>'  : 'TRSC_VC/TRSC_VC2/Torque Control'
 * '<S18>'  : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1'
 * '<S19>'  : 'TRSC_VC/TRSC_VC2/VehicleActivation'
 * '<S20>'  : 'TRSC_VC/TRSC_VC2/JackKnife Angle /Detect Change'
 * '<S21>'  : 'TRSC_VC/TRSC_VC2/JackKnife Angle /MATLAB Function1'
 * '<S22>'  : 'TRSC_VC/TRSC_VC2/JackKnife Angle /Saturation Dynamic3'
 * '<S23>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/DocBlock'
 * '<S24>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model'
 * '<S25>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Host Vehicle Speed Calculation - Wheel Pulse_MODIFIED'
 * '<S26>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/HostVehiclePositionCalculation'
 * '<S27>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Host_Vehicle_Speed_Calculation_RPM'
 * '<S28>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/KM_Gyro_YawRate'
 * '<S29>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/KM_Integrator_Trapazoidal'
 * '<S30>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/KM_Integrator_Trapazoidal1'
 * '<S31>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/KM_Integrator_Trapazoidal2'
 * '<S32>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/KM_Rear_Axle_ds'
 * '<S33>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/KM_Reset'
 * '<S34>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/KM_Wheel_Angle'
 * '<S35>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/KM_heading_angle'
 * '<S36>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/KeKM_k_NoiseCovQ1'
 * '<S37>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/ME_EWMA_Float'
 * '<S38>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict'
 * '<S39>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/TrailerPositionAndHeadingCalculation'
 * '<S40>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Update_measurement_IMU'
 * '<S41>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Update_measurement_RPM'
 * '<S42>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Update_measurement_TAD'
 * '<S43>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/YawRate'
 * '<S44>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/YawRateEnableCriteria'
 * '<S45>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/YawRateWhlRPMEn'
 * '<S46>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/YawRate_RPM'
 * '<S47>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/YawRate_RPM_Bias'
 * '<S48>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/x_Out'
 * '<S49>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/HostVehiclePositionCalculation/cos'
 * '<S50>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/HostVehiclePositionCalculation/sin'
 * '<S51>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/KM_Gyro_YawRate/Bias_Calculation_Enable_Criteria'
 * '<S52>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/KM_Gyro_YawRate/Gyro_Measurement_Signal_Processing'
 * '<S53>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/KM_Gyro_YawRate/Gyro_YawRate_Bias'
 * '<S54>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/KM_Gyro_YawRate/Gyro_YawRate_Bias/ME_ExpWeightMovAvg'
 * '<S55>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/KM_Reset/Detect Increase'
 * '<S56>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/KM_Reset/reset_KM'
 * '<S57>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_Avg_tanAngle'
 * '<S58>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next'
 * '<S59>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_Avg_tanAngle/Enable_Average_Wheel_Angle_Calculation'
 * '<S60>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_Avg_tanAngle/ResettableSubsystem'
 * '<S61>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_Avg_tanAngle/ResettableSubsystem/AvgTanAngleCal'
 * '<S62>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_Avg_tanAngle/ResettableSubsystem/Integrator_Subsytem'
 * '<S63>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_Avg_tanAngle/ResettableSubsystem/Integrator_Subsytem1'
 * '<S64>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_Avg_tanAngle/ResettableSubsystem/tan'
 * '<S65>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/MatTranspose_1x3'
 * '<S66>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/MatTranspose_3x3'
 * '<S67>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/X_next(2)'
 * '<S68>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/X_next(2)1'
 * '<S69>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/x_next(1)'
 * '<S70>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/x_next(3)'
 * '<S71>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/MatTranspose_1x3/Matrix_FirstRow'
 * '<S72>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/MatTranspose_3x3/Matrix_FirstRow'
 * '<S73>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/MatTranspose_3x3/Matrix_SecRow'
 * '<S74>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/MatTranspose_3x3/Matrix_threeRow'
 * '<S75>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/X_next(2)/cos'
 * '<S76>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/X_next(2)/sin'
 * '<S77>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/X_next(2)/tan'
 * '<S78>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/X_next(2)1/cos'
 * '<S79>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/X_next(2)1/sin'
 * '<S80>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/X_next(2)1/tan'
 * '<S81>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Predict/StateTransitionFunction_x_next/x_next(1)/tan'
 * '<S82>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/TrailerPositionAndHeadingCalculation/Calc_T_H'
 * '<S83>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/TrailerPositionAndHeadingCalculation/Calc_T_X'
 * '<S84>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/TrailerPositionAndHeadingCalculation/Calc_T_Y'
 * '<S85>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/TrailerPositionAndHeadingCalculation/Calc_T_H/heading_angle'
 * '<S86>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/TrailerPositionAndHeadingCalculation/Calc_T_X/cos'
 * '<S87>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/TrailerPositionAndHeadingCalculation/Calc_T_X/cos1'
 * '<S88>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/TrailerPositionAndHeadingCalculation/Calc_T_Y/sin'
 * '<S89>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/TrailerPositionAndHeadingCalculation/Calc_T_Y/sin1'
 * '<S90>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Update_measurement_IMU/MatTranspose_1x3'
 * '<S91>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Update_measurement_IMU/MatTranspose_1x3/Matrix_FirstRow'
 * '<S92>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Update_measurement_RPM/MatTranspose_1x3'
 * '<S93>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Update_measurement_RPM/MatTranspose_1x3/Matrix_FirstRow'
 * '<S94>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Update_measurement_TAD/MatTranspose_1x3'
 * '<S95>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/Update_measurement_TAD/MatTranspose_1x3/Matrix_FirstRow'
 * '<S96>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/YawRate_RPM_Bias/Accumulator'
 * '<S97>'  : 'TRSC_VC/TRSC_VC2/Kinematic Model/Kinematic_model/YawRate_RPM_Bias/Accumulator/Integrator_Subsytem'
 * '<S98>'  : 'TRSC_VC/TRSC_VC2/Knob_Sensing/Compare To Constant5'
 * '<S99>'  : 'TRSC_VC/TRSC_VC2/Knob_Sensing/DesiredTrailerAngleComp'
 * '<S100>' : 'TRSC_VC/TRSC_VC2/Knob_Sensing/KnobAngleComp'
 * '<S101>' : 'TRSC_VC/TRSC_VC2/Knob_Sensing/KnobHysteresis'
 * '<S102>' : 'TRSC_VC/TRSC_VC2/Knob_Sensing/Saturation Dynamic1'
 * '<S103>' : 'TRSC_VC/TRSC_VC2/Knob_Sensing/Saturation Dynamic2'
 * '<S104>' : 'TRSC_VC/TRSC_VC2/Knob_Sensing/KnobAngleComp/KnobAngle'
 * '<S105>' : 'TRSC_VC/TRSC_VC2/Knob_Sensing/KnobHysteresis/Saturation Dynamic2'
 * '<S106>' : 'TRSC_VC/TRSC_VC2/Knob_Sensing/KnobHysteresis/Subsystem'
 * '<S107>' : 'TRSC_VC/TRSC_VC2/Torque Control/DocBlock'
 * '<S108>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl'
 * '<S109>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2'
 * '<S110>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_T_h_init'
 * '<S111>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Subsystem'
 * '<S112>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/Desired_angle_controller'
 * '<S113>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/FrontWheel_to_Steering1'
 * '<S114>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/Heading_Deviation1'
 * '<S115>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/Path_Deviation'
 * '<S116>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/Speed Limit Req'
 * '<S117>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_Error'
 * '<S118>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_PID1'
 * '<S119>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_des1'
 * '<S120>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_ep1'
 * '<S121>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TravDist_TrapIntegrator'
 * '<S122>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TrqControl2'
 * '<S123>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/Desired_angle_controller/atand'
 * '<S124>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/Desired_angle_controller/cos'
 * '<S125>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/Desired_angle_controller/sin'
 * '<S126>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/FrontWheel_to_Steering1/Dynamic_rate_limiter2'
 * '<S127>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/FrontWheel_to_Steering1/Saturation Dynamic1'
 * '<S128>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/FrontWheel_to_Steering1/Saturation Dynamic2'
 * '<S129>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/FrontWheel_to_Steering1/Saturation Dynamic3'
 * '<S130>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/FrontWheel_to_Steering1/Dynamic_rate_limiter2/Saturation Dynamic1'
 * '<S131>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/Heading_Deviation1/heading_angle'
 * '<S132>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/Path_Deviation/cos'
 * '<S133>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/Path_Deviation/sin'
 * '<S134>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_Error/Dynamic_rate_limiter1'
 * '<S135>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_Error/Dynamic_rate_limiter2'
 * '<S136>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_Error/Rate Limiter Dynamic1'
 * '<S137>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_Error/Saturation Dynamic1'
 * '<S138>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_Error/Dynamic_rate_limiter1/Saturation Dynamic1'
 * '<S139>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_Error/Dynamic_rate_limiter2/Saturation Dynamic1'
 * '<S140>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_Error/Rate Limiter Dynamic1/Saturation Dynamic'
 * '<S141>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_PID1/Discrete_PID_Controller'
 * '<S142>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_PID1/Discrete_PID_Controller/Integrator_Subsytem'
 * '<S143>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_PID1/Discrete_PID_Controller/Integrator_Subsytem1'
 * '<S144>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_des1/Saturation Dynamic'
 * '<S145>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_des1/TAD_PID'
 * '<S146>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_des1/TAD_PID/Discrete_PID_Controller'
 * '<S147>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_des1/TAD_PID/Saturation Dynamic1'
 * '<S148>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_des1/TAD_PID/Discrete_PID_Controller/Integrator_Subsytem1'
 * '<S149>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_des1/TAD_PID/Discrete_PID_Controller/Integrator_Subsytem2'
 * '<S150>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_ep1/Discrete_PID_Controller1'
 * '<S151>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_ep1/Saturation Dynamic1'
 * '<S152>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_ep1/Discrete_PID_Controller1/Integrator_Subsytem1'
 * '<S153>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TAD_ep1/Discrete_PID_Controller1/Integrator_Subsytem2'
 * '<S154>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TrqControl2/Compare To Constant'
 * '<S155>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TrqControl2/MATLAB Function'
 * '<S156>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TrqControl2/Rate Limiter Dynamic'
 * '<S157>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TrqControl2/Saturation Dynamic3'
 * '<S158>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TrqControl2/THA_SteerTweakProfile_Processing2'
 * '<S159>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TrqControl2/TrqControl1'
 * '<S160>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TrqControl2/low_pass_filter'
 * '<S161>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TrqControl2/Rate Limiter Dynamic/Saturation Dynamic'
 * '<S162>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TrqControl2/TrqControl1/MATLAB Function'
 * '<S163>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TrqControl2/TrqControl1/Rate Limiter Dynamic'
 * '<S164>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TrqControl2/TrqControl1/Saturation Dynamic'
 * '<S165>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TrqControl2/TrqControl1/Saturation Dynamic2'
 * '<S166>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TrqControl2/TrqControl1/low_pass_filter'
 * '<S167>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_Main2/TrqControl2/TrqControl1/Rate Limiter Dynamic/Saturation Dynamic'
 * '<S168>' : 'TRSC_VC/TRSC_VC2/Torque Control/VehicleControl/Controller_T_h_init/Calc_T_H_init'
 * '<S169>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/DocBlock1'
 * '<S170>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem'
 * '<S171>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/Compare To Constant2'
 * '<S172>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/Compare To Constant3'
 * '<S173>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/Compare To Constant4'
 * '<S174>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/Enabled Subsystem'
 * '<S175>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/OTBL_Enable'
 * '<S176>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/OTBL_Enable1'
 * '<S177>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/OnlineTrailerBeamLengthEstimation'
 * '<S178>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/Subsystem'
 * '<S179>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/OTBL_Enable/Compare To Constant2'
 * '<S180>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/OTBL_Enable/Compare To Constant6'
 * '<S181>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/OTBL_Enable/ME_EWMA_Float1'
 * '<S182>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/OTBL_Enable1/Compare To Constant3'
 * '<S183>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/OnlineTrailerBeamLengthEstimation/OTBLWheelAngle'
 * '<S184>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/OnlineTrailerBeamLengthEstimation/TrailerBeamLengthCalculation'
 * '<S185>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/OnlineTrailerBeamLengthEstimation/TrailerBeamLengthCalculation/TBL_DataLog'
 * '<S186>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/Subsystem/MATLAB Function2'
 * '<S187>' : 'TRSC_VC/TRSC_VC2/Trailer Beam Length1/Subsystem/Subsystem/Saturation Dynamic3'
 * '<S188>' : 'TRSC_VC/TRSC_VC2/VehicleActivation/Compare To Constant'
 * '<S189>' : 'TRSC_VC/TRSC_VC2/VehicleActivation/Compare To Constant1'
 * '<S190>' : 'TRSC_VC/TRSC_VC2/VehicleActivation/Compare To Constant2'
 * '<S191>' : 'TRSC_VC/TRSC_VC2/VehicleActivation/Compare To Constant3'
 * '<S192>' : 'TRSC_VC/TRSC_VC2/VehicleActivation/Compare To Constant4'
 * '<S193>' : 'TRSC_VC/TRSC_VC2/VehicleActivation/Compare To Constant5'
 * '<S194>' : 'TRSC_VC/TRSC_VC2/VehicleActivation/Compare To Constant6'
 * '<S195>' : 'TRSC_VC/TRSC_VC2/VehicleActivation/Timer1'
 */
#endif                                 /* RTW_HEADER_TRSC_VC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
