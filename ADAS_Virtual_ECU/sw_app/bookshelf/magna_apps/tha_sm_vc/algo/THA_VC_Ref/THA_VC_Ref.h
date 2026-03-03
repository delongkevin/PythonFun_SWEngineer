/*
 * File: THA_VC_Ref.h
 *
 * Code generated for Simulink model 'THA_VC_Ref'.
 *
 * Model version                  : 1.2042
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Aug  7 17:42:34 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_THA_VC_Ref_h_
#define RTW_HEADER_THA_VC_Ref_h_
#include <math.h>
#include <string.h>
#ifndef THA_VC_Ref_COMMON_INCLUDES_
# define THA_VC_Ref_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* THA_VC_Ref_COMMON_INCLUDES_ */

#include "THA_VC_Ref_types.h"

/* Includes for objects with custom storage classes. */
#include "THA_CalibParams.h"

/* Block signals for model 'THA_VC_Ref' */
#ifndef THA_VC_Ref_MDLREF_HIDE_CHILD_

typedef struct {
  real_T Divide1;                      /* '<S12>/Divide1' */
  real32_T wheel_pos[8];               /* '<S36>/Compute_Whl_Pos' */
  real_T wheel_status_index1;
  real_T wheel_status_index2;
  real_T wheel_status_index2_tmp;
  real32_T Switch1;                    /* '<S7>/Switch1' */
  real32_T deltafalllimit;             /* '<S8>/delta fall limit' */
  real32_T Saturation1;                /* '<S2>/Saturation1' */
  real32_T Saturation6;                /* '<S2>/Saturation6' */
  real32_T Saturation3;                /* '<S2>/Saturation3' */
  real32_T Saturation4;                /* '<S2>/Saturation4' */
  real32_T Saturation5;                /* '<S2>/Saturation5' */
  real32_T Saturation7;                /* '<S2>/Saturation7' */
  real32_T Merge1;                     /* '<S1>/Merge1' */
  real32_T Yk1;                        /* '<S8>/Delay Input2' */
  real32_T UkYk1;                      /* '<S8>/Difference Inputs1' */
  real32_T Switch;                     /* '<S13>/Switch' */
  real32_T deltariselimit;             /* '<S8>/delta rise limit' */
  real32_T Switch2;                    /* '<S13>/Switch2' */
  real32_T MinMax;                     /* '<S7>/MinMax' */
  real32_T Saturation2;                /* '<S2>/Saturation2' */
  real32_T UnitDelay;                  /* '<S146>/Unit Delay' */
  real32_T Saturation;                 /* '<S2>/Saturation' */
  real32_T Switch1_i2av;               /* '<S146>/Switch1' */
  real32_T Gain3;                      /* '<S12>/Gain3' */
  real32_T MultiportSwitch;            /* '<S36>/Multiport Switch' */
  real32_T mm_to_m;                    /* '<S36>/mm_to_m' */
  real32_T SignalCopy1[4];             /* '<S36>/Signal Copy1' */
  real32_T DataTypeConversion20;       /* '<S10>/Data Type Conversion20' */
  real32_T Gain13[4];                  /* '<S46>/Gain13' */
  real32_T SignalCopy2[4];             /* '<S36>/Signal Copy2' */
  real32_T Sum;                        /* '<S69>/Sum' */
  real32_T Sum_pkps;                   /* '<S70>/Sum' */
  real32_T Sum_jqym;                   /* '<S71>/Sum' */
  real32_T Sum_fdny;                   /* '<S72>/Sum' */
  real32_T DataTypeConversion37;       /* '<S10>/Data Type Conversion37' */
  real32_T DataTypeConversion38;       /* '<S10>/Data Type Conversion38' */
  real32_T DataTypeConversion39;       /* '<S10>/Data Type Conversion39' */
  real32_T DataTypeConversion22;       /* '<S10>/Data Type Conversion22' */
  real32_T SignalCopy[4];              /* '<S36>/Signal Copy' */
  real32_T Sum_d1um;                   /* '<S75>/Sum' */
  real32_T Gain;                       /* '<S36>/Gain' */
  real32_T MeTHA_mps_KMSpeed_FW;       /* '<S10>/Abs1' */
  real32_T UnitDelay1;                 /* '<S38>/Unit Delay1' */
  real32_T UnitDelay2;                 /* '<S38>/Unit Delay2' */
  real32_T Gain2;                      /* '<S38>/Gain2' */
  real32_T Sum_gpp3;                   /* '<S43>/Sum' */
  real32_T Switch_lulz;                /* '<S39>/Switch' */
  real32_T Switch_ek3b;                /* '<S78>/Switch' */
  real32_T Switch2_hj2w;               /* '<S78>/Switch2' */
  real32_T Sum1;                       /* '<S42>/Sum1' */
  real32_T Abs1;                       /* '<S42>/Abs1' */
  real32_T Abs;                        /* '<S42>/Abs' */
  real32_T DiscreteTimeIntegrator;     /* '<S42>/Discrete-Time Integrator' */
  real32_T Switch_ctws;                /* '<S138>/Switch' */
  real32_T Switch2_pjho;               /* '<S138>/Switch2' */
  real32_T StrCmdTqLmtOld;             /* '<S42>/Add1' */
  real32_T Yk1_ocsm;                   /* '<S136>/Delay Input2' */
  real32_T UkYk1_ecnl;                 /* '<S136>/Difference Inputs1' */
  real32_T deltariselimit_h33d;        /* '<S136>/delta rise limit' */
  real32_T deltafalllimit_avfk;        /* '<S136>/delta fall limit' */
  real32_T Switch_cr1i;                /* '<S139>/Switch' */
  real32_T Switch2_cddq;               /* '<S139>/Switch2' */
  real32_T DifferenceInputs2;          /* '<S136>/Difference Inputs2' */
  real32_T Switch_gyji;                /* '<S137>/Switch' */
  real32_T Switch2_jsai;               /* '<S137>/Switch2' */
  real32_T Product2;                   /* '<S42>/Product2' */
  real32_T Sum_ewt2;                   /* '<S73>/Sum' */
  real32_T DataTypeConversion6;        /* '<S10>/Data Type Conversion6' */
  real32_T Sum_dtuk;                   /* '<S74>/Sum' */
  real32_T DataTypeConversion7;        /* '<S10>/Data Type Conversion7' */
  real32_T Abs_onz4;                   /* '<S10>/Abs' */
  real32_T DataTypeConversion13;       /* '<S10>/Data Type Conversion13' */
  real32_T DataTypeConversion14;       /* '<S10>/Data Type Conversion14' */
  real32_T SquareRoot1;                /* '<S36>/Square Root1' */
  real32_T DataTypeConversion10;       /* '<S10>/Data Type Conversion10' */
  real32_T DataTypeConversion11;       /* '<S10>/Data Type Conversion11' */
  real32_T DataTypeConversion15;       /* '<S10>/Data Type Conversion15' */
  real32_T DataTypeConversion16;       /* '<S10>/Data Type Conversion16' */
  real32_T Hypot;                      /* '<S36>/Hypot' */
  real32_T Product11;                  /* '<S42>/Product11' */
  real32_T Switch_ft0z;                /* '<S42>/Switch' */
  real32_T Product4;                   /* '<S42>/Product4' */
  real32_T Switch1_lajy;               /* '<S42>/Switch1' */
  real32_T Product10;                  /* '<S42>/Product10' */
  real32_T Product7;                   /* '<S42>/Product7' */
  real32_T Product12;                  /* '<S42>/Product12' */
  real32_T Switch2_iy0x;               /* '<S42>/Switch2' */
  real32_T Product5;                   /* '<S42>/Product5' */
  real32_T Product8;                   /* '<S42>/Product8' */
  real32_T Product13;                  /* '<S42>/Product13' */
  real32_T Switch3;                    /* '<S42>/Switch3' */
  real32_T Product6;                   /* '<S42>/Product6' */
  real32_T Product9;                   /* '<S42>/Product9' */
  real32_T Sum1_g22q;                  /* '<S41>/Sum1' */
  real32_T igainSaturation1;           /* '<S41>/igainSaturation1' */
  real32_T Product2_l505;              /* '<S41>/Product2' */
  real32_T FB_I_tq;                    /* '<S41>/Chart' */
  real32_T DataTypeConversion;         /* '<S40>/Data Type Conversion' */
  real32_T Yk1_oc1t;                   /* '<S84>/Delay Input2' */
  real32_T NProdOut;                   /* '<S118>/NProd Out' */
  real32_T StrAngleLimits;             /* '<S40>/StrAngleLimits' */
  real32_T SWA_Error;                  /* '<S40>/Add' */
  real32_T Discrete_Time_Integrator1;  /* '<S40>/Discrete_Time_Integrator1' */
  real32_T Data_Type_Conversion;       /* '<S40>/Data_Type_Conversion' */
  real32_T Data_Type_Conversion1;      /* '<S40>/Data_Type_Conversion1' */
  real32_T deltariselimit_az2v;        /* '<S84>/delta rise limit' */
  real32_T UkYk1_lhs3;                 /* '<S84>/Difference Inputs1' */
  real32_T deltafalllimit_embx;        /* '<S84>/delta fall limit' */
  real32_T Switch_irut;                /* '<S130>/Switch' */
  real32_T Switch2_ak0c;               /* '<S130>/Switch2' */
  real32_T DifferenceInputs2_hyze;     /* '<S84>/Difference Inputs2' */
  real32_T Angle_Saturation;           /* '<S40>/Angle_Saturation' */
  real32_T IProdOut;                   /* '<S112>/IProd Out' */
  real32_T rateLimit;                  /* '<S40>/determine_str_rate_limit' */
  real32_T Product;                    /* '<S40>/Product' */
  real32_T Discrete_Time_Integrator1_hao2;/* '<S79>/Discrete_Time_Integrator1' */
  real32_T Switch_bm4p;                /* '<S10>/Switch' */
  real32_T wheelSpeeds[4];             /* '<S36>/Tick_WhlSpeed_Merger1' */
  real32_T tickSpeed[4];               /* '<S36>/Tick_WhlSpeed_Merger' */
  real32_T heading_MABx;               /* '<S36>/MATLAB Function4' */
  real32_T ds;                         /* '<S36>/MATLAB Function1' */
  real32_T dx;                         /* '<S36>/MATLAB Function1' */
  real32_T dy;                         /* '<S36>/MATLAB Function1' */
  real32_T dyaw;                       /* '<S36>/MATLAB Function1' */
  real32_T WhlSpeed[4];                /* '<S36>/MATLAB Function' */
  real32_T merger[3];                  /* '<S36>/Inst_Vel_Merger' */
  real32_T veh_x_dot_all[6];           /* '<S36>/Forward_Kinematics_Model1' */
  real32_T veh_y_dot_all[6];           /* '<S36>/Forward_Kinematics_Model1' */
  real32_T veh_theta_dot_all[6];       /* '<S36>/Forward_Kinematics_Model1' */
  real32_T veh_x_dot;                  /* '<S36>/Forward_Kinematics_Model1' */
  real32_T veh_y_dot;                  /* '<S36>/Forward_Kinematics_Model1' */
  real32_T veh_theta_dot;              /* '<S36>/Forward_Kinematics_Model1' */
  real32_T veh_x_dot_all_cx3j[6];      /* '<S36>/Forward_Kinematics_Model' */
  real32_T veh_y_dot_all_mkvv[6];      /* '<S36>/Forward_Kinematics_Model' */
  real32_T veh_theta_dot_all_mtc1[6];  /* '<S36>/Forward_Kinematics_Model' */
  real32_T veh_x_dot_nnwm;             /* '<S36>/Forward_Kinematics_Model' */
  real32_T veh_y_dot_p3vd;             /* '<S36>/Forward_Kinematics_Model' */
  real32_T veh_theta_dot_ktag;         /* '<S36>/Forward_Kinematics_Model' */
  real32_T wheel_radius[4];            /* '<S36>/Compute_Whl_Radius' */
  real32_T x;                          /* '<S36>/Compute_Dead_Reckoning' */
  real32_T y;                          /* '<S36>/Compute_Dead_Reckoning' */
  real32_T theta;                      /* '<S36>/Compute_Dead_Reckoning' */
  real32_T uD_LUT_LEFT_63C;            /* '<S61>/1D_LUT_LEFT_63C' */
  real32_T uD_LUT_RIGHT_63C;           /* '<S61>/1D_LUT_RIGHT_63C' */
  real32_T angles[4];                  /* '<S61>/MATLAB Function' */
  real32_T uD_LUT_LEFT_63C_msgm;       /* '<S63>/1D_LUT_LEFT_63C' */
  real32_T uD_LUT_RIGHT_63C_g1oc;      /* '<S63>/1D_LUT_RIGHT_63C' */
  real32_T angles_ftc1[4];             /* '<S63>/MATLAB Function' */
  real32_T uD_LUT_LEFT_60C;            /* '<S62>/1D_LUT_LEFT_60C' */
  real32_T uD_LUT_RIGHT_60C;           /* '<S62>/1D_LUT_RIGHT_60C' */
  real32_T angles_k40t[4];             /* '<S62>/MATLAB Function' */
  real32_T uD_LUT_LEFT_55C;            /* '<S64>/1D_LUT_LEFT_55C' */
  real32_T uD_LUT_RIGHT_55C;           /* '<S64>/1D_LUT_RIGHT_55C' */
  real32_T angles_nyg4[4];             /* '<S64>/MATLAB Function' */
  real32_T tick_speed_RR;              /* '<S36>/ComputeTickBasedWhlSpeed' */
  real32_T tick_speed_RF;              /* '<S36>/ComputeTickBasedWhlSpeed' */
  real32_T tick_speed_LF;              /* '<S36>/ComputeTickBasedWhlSpeed' */
  real32_T tick_speed_LR;              /* '<S36>/ComputeTickBasedWhlSpeed' */
  real32_T wheelSpeeds_ckym[4];        /* '<S36>/CAN_WhlSpeed_Merger1' */
  real32_T Switch_j13x;                /* '<S19>/Switch' */
  real32_T Switch2_kwro;               /* '<S19>/Switch2' */
  real32_T Rpt_Xdiff;                  /* '<S9>/Rpt_Xdiff' */
  real32_T MinMax_pmrs;                /* '<S33>/MinMax' */
  real32_T uDLookupTable;              /* '<S17>/1-D Lookup Table' */
  real32_T Gain_fl2v;                  /* '<S1>/Gain' */
  real32_T Switch1_gex1;               /* '<S1>/Switch1' */
  real32_T sampletime;                 /* '<S8>/sample time' */
  real32_T Merge1_ptoy[4];             /* '<S46>/Merge1' */
  real32_T Delay;                      /* '<S69>/Delay' */
  real32_T Delay_kfuy;                 /* '<S70>/Delay' */
  real32_T Delay_irja;                 /* '<S71>/Delay' */
  real32_T Delay_o4cj;                 /* '<S72>/Delay' */
  real32_T Delay_oetc;                 /* '<S75>/Delay' */
  real32_T SquareRoot;                 /* '<S36>/Square Root' */
  real32_T sampletime_a0qp;            /* '<S136>/sample time' */
  real32_T Delay_bri0;                 /* '<S73>/Delay' */
  real32_T Delay_atsl;                 /* '<S74>/Delay' */
  real32_T P_gain_lookup_tabletrx;     /* '<S42>/P_gain_lookup_table trx' */
  real32_T P_gain_lookup_table98;      /* '<S42>/P_gain_lookup_table98' */
  real32_T P_gain_lookup_table103;     /* '<S42>/P_gain_lookup_table103' */
  real32_T P_gain_lookup_table102;     /* '<S42>/P_gain_lookup_table102' */
  real32_T integrator_gain_table_trx;  /* '<S42>/integrator_gain_table_trx' */
  real32_T integrator_gain_table1;     /* '<S42>/integrator_gain_table1' */
  real32_T integrator_gain_table;      /* '<S42>/integrator_gain_table' */
  real32_T differential_gain_table_trx;/* '<S42>/differential_gain_table_trx' */
  real32_T differential_gain_table1;   /* '<S42>/differential_gain_table1' */
  real32_T differential_gain_table;    /* '<S42>/differential_gain_table' */
  real32_T LookupTableDynamic;         /* '<S40>/Lookup Table Dynamic' */
  real32_T sampletime_m2db;            /* '<S84>/sample time' */
  real32_T LookupTableDynamic1;        /* '<S40>/Lookup Table Dynamic1' */
  real32_T Gain1;                      /* '<S39>/Gain1' */
  real32_T Divide;                     /* '<S1>/Divide' */
  real32_T uD_LUT_CENTER_63C;          /* '<S61>/1D_LUT_CENTER_63C' */
  real32_T uD_LUT_CORRECTION_63C;      /* '<S61>/1D_LUT_CORRECTION_63C' */
  real32_T uD_LUT_CENTER_63C_albi;     /* '<S63>/1D_LUT_CENTER_63C' */
  real32_T uD_LUT_CORRECTION_63C_cixs; /* '<S63>/1D_LUT_CORRECTION_63C' */
  real32_T uD_LUT_CENTER_60C;          /* '<S62>/1D_LUT_CENTER_60C' */
  real32_T uD_LUT_CORRECTION_60C;      /* '<S62>/1D_LUT_CORRECTION_60C' */
  real32_T uD_LUT_CENTER_55C;          /* '<S64>/1D_LUT_CENTER_55C' */
  real32_T uD_LUT_CORRECTION_55C;      /* '<S64>/1D_LUT_CORRECTION_55C' */
  real32_T Gain4;                      /* '<S10>/Gain4' */
  real32_T Filter;                     /* '<S110>/Filter' */
  real32_T Add1;                       /* '<S40>/Add1' */
  real32_T Abs1_izan;                  /* '<S40>/Abs1' */
  real32_T Sum_hqju;                   /* '<S7>/Sum' */
  real32_T integrator_external_saturation_table;
                              /* '<S42>/integrator_external_saturation_table' */
  real32_T Square3;                    /* '<S36>/Square3' */
  real32_T Add1_jabu;                  /* '<S36>/Add1' */
  real32_T Dgain;                      /* '<S41>/Dgain' */
  int32_T Saturation10;                /* '<S2>/Saturation10' */
  int32_T Saturation9;                 /* '<S2>/Saturation9' */
  int32_T Saturation8;                 /* '<S2>/Saturation8' */
  int32_T Saturation11;                /* '<S2>/Saturation11' */
  int32_T Rpt_Ydiff;                   /* '<S10>/Rpt_Ydiff' */
  int32_T Rpt_Xdiff_hala;              /* '<S10>/Rpt_Xdiff' */
  int32_T MeTHA_Pnt_HitchPnt[2];       /* '<S9>/MeTHA_Pnt_HitchPnt' */
  int32_T OutportBufferForMeTHA_pixel_HitchLocationY;
  int32_T Delay1;                      /* '<S9>/Delay1' */
  int32_T DifferenceInputs1;           /* '<S15>/Difference Inputs1' */
  int32_T DifferenceInputs2_lsrk;      /* '<S15>/Difference Inputs2' */
  int32_T Delay_pt0m;                  /* '<S9>/Delay' */
  int32_T DifferenceInputs1_ab5m;      /* '<S14>/Difference Inputs1' */
  int32_T Switch_fg02;                 /* '<S18>/Switch' */
  int32_T Switch2_haof;                /* '<S18>/Switch2' */
  int32_T DifferenceInputs2_jov4;      /* '<S14>/Difference Inputs2' */
  int32_T ResettableDelay;             /* '<S15>/Resettable Delay' */
  int32_T ResettableDelay_lzig;        /* '<S14>/Resettable Delay' */
  TeTHA_e_THARmpUpDwnSpd Multiport;    /* '<S16>/Multiport' */
  TeTHA_e_THARmpUpDwnSpd UnitDelay_ej2n;/* '<S16>/Unit Delay' */
  uint16_T DataTypeConversion29;       /* '<S10>/Data Type Conversion29' */
  uint8_T DataTypeConversion30;        /* '<S10>/Data Type Conversion30' */
  uint8_T DataTypeConversion23;        /* '<S10>/Data Type Conversion23' */
  uint8_T DataTypeConversion24;        /* '<S10>/Data Type Conversion24' */
  uint8_T DataTypeConversion25;        /* '<S10>/Data Type Conversion25' */
  uint8_T DataTypeConversion26;        /* '<S10>/Data Type Conversion26' */
  uint8_T DataTypeConversion32;        /* '<S10>/Data Type Conversion32' */
  uint8_T DataTypeConversion33;        /* '<S10>/Data Type Conversion33' */
  uint8_T DataTypeConversion34;        /* '<S10>/Data Type Conversion34' */
  uint8_T DataTypeConversion35;        /* '<S10>/Data Type Conversion35' */
  uint8_T DataTypeConversion21;        /* '<S10>/Data Type Conversion21' */
  uint8_T DataTypeConversion12;        /* '<S10>/Data Type Conversion12' */
  uint8_T status[4];                   /* '<S36>/WhlStatus_Merger' */
  uint8_T km_err;                      /* '<S36>/Forward_Kinematics_Model1' */
  uint8_T DataTypeConversion_kd4p;     /* '<S16>/DataTypeConversion' */
  uint8_T DataTypeConversion1;         /* '<S12>/Data Type Conversion1' */
  uint8_T DataTypeConversion_hcep;     /* '<S12>/Data Type Conversion' */
  uint8_T DataTypeConversion1_dyy3;    /* '<S40>/Data Type Conversion1' */
  int8_T DataTypeConversion_jb1p;      /* '<S61>/Data Type Conversion' */
  int8_T DataTypeConversion_otfa;      /* '<S63>/Data Type Conversion' */
  int8_T DataTypeConversion_p5bw;      /* '<S62>/Data Type Conversion' */
  int8_T DataTypeConversion_dwsq;      /* '<S64>/Data Type Conversion' */
  boolean_T MeTHA_b_VCActive;          /* '<S2>/Logical Operator2' */
  boolean_T LogicalOperator5;          /* '<S1>/Logical Operator5' */
  boolean_T LogicalOperator3;          /* '<S1>/Logical Operator3' */
  boolean_T MeTHA_b_THAEnggdNotSupp;   /* '<S147>/Logical Operator11' */
  boolean_T UnitDelay_h2xn;            /* '<S1>/Unit Delay' */
  boolean_T LogicalOperator8;          /* '<S1>/Logical Operator8' */
  boolean_T MeTHA_b_TrlrCplrReached;   /* '<S2>/RelationalOperator2' */
  boolean_T LogicalOperator2;          /* '<S146>/Logical Operator2' */
  boolean_T OR;                        /* '<S36>/OR' */
  boolean_T LogicalOperator;           /* '<S36>/Logical Operator' */
  boolean_T LogicalOperator1;          /* '<S10>/Logical Operator1' */
  boolean_T RelationalOperator;        /* '<S42>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S42>/Relational Operator1' */
  boolean_T LogicalOperator_orp3;      /* '<S42>/Logical Operator' */
  boolean_T LogicalOperator_hxxz;      /* '<S10>/Logical Operator' */
  boolean_T LogicalOperator2_imfa;     /* '<S41>/Logical Operator2' */
  boolean_T resetFlag;                 /* '<S41>/Chart' */
  boolean_T Compare;                   /* '<S82>/Compare' */
  boolean_T Compare_hqzm;              /* '<S81>/Compare' */
  boolean_T Compare_bgyw;              /* '<S80>/Compare' */
  boolean_T Compare_kjdt;              /* '<S77>/Compare' */
  boolean_T LogicalOperator3_cq0a;     /* '<S146>/Logical Operator3' */
  boolean_T MeTHA_b_ThaSmAbrtSts;      /* '<S2>/RelationalOperator1' */
  boolean_T UnitDelay4;                /* '<S41>/Unit Delay4' */
  boolean_T RelationalOperator6;       /* '<S1>/RelationalOperator6' */
  boolean_T LogicalOperator6;          /* '<S1>/Logical Operator6' */
} B_THA_VC_Ref_caua_T;

#endif                                 /*THA_VC_Ref_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'THA_VC_Ref' */
#ifndef THA_VC_Ref_MDLREF_HIDE_CHILD_

typedef struct {
  real_T wheel_pairs[12];              /* '<S36>/Forward_Kinematics_Model1' */
  real_T wheel_pairs_etgb[12];         /* '<S36>/Forward_Kinematics_Model' */
  real32_T UnitDelay3_DSTATE;          /* '<S7>/UnitDelay3' */
  real32_T DelayInput2_DSTATE;         /* '<S8>/Delay Input2' */
  real32_T UnitDelay_DSTATE;           /* '<S146>/Unit Delay' */
  real32_T Delay_DSTATE;               /* '<S69>/Delay' */
  real32_T Delay_DSTATE_lu4u;          /* '<S70>/Delay' */
  real32_T Delay_DSTATE_psr1;          /* '<S71>/Delay' */
  real32_T Delay_DSTATE_nkk5;          /* '<S72>/Delay' */
  real32_T Delay_DSTATE_pwdf;          /* '<S75>/Delay' */
  real32_T UnitDelay_DSTATE_dk0c;      /* '<S38>/Unit Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S38>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S38>/Unit Delay2' */
  real32_T UnitDelay3_DSTATE_ogzh;     /* '<S38>/Unit Delay3' */
  real32_T UnitDelay_DSTATE_efpz;      /* '<S43>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_njpd;     /* '<S42>/Unit Delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S42>/Discrete-Time Integrator' */
  real32_T DelayInput2_DSTATE_ivvk;    /* '<S136>/Delay Input2' */
  real32_T Delay_DSTATE_j2qc;          /* '<S73>/Delay' */
  real32_T Delay_DSTATE_h4yd;          /* '<S74>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_e31n;/* '<S41>/DiscreteTimeIntegrator' */
  real32_T UnitDelay2_DSTATE_gk31;     /* '<S41>/Unit Delay2' */
  real32_T DelayInput2_DSTATE_mkva;    /* '<S84>/Delay Input2' */
  real32_T Integrator_DSTATE;          /* '<S115>/Integrator' */
  real32_T Filter_DSTATE;              /* '<S110>/Filter' */
  real32_T Discrete_Time_Integrator1_DSTATE;/* '<S40>/Discrete_Time_Integrator1' */
  real32_T Discrete_Time_Integrator1_DSTATE_m4zj;/* '<S79>/Discrete_Time_Integrator1' */
  real32_T UnitDelay3_DSTATE_bncg;     /* '<S33>/UnitDelay3' */
  int32_T Delay1_DSTATE;               /* '<S9>/Delay1' */
  int32_T ResettableDelay_DSTATE;      /* '<S15>/Resettable Delay' */
  int32_T Delay_DSTATE_b3on;           /* '<S9>/Delay' */
  int32_T ResettableDelay_DSTATE_lieo; /* '<S14>/Resettable Delay' */
  TeTHA_e_THARmpUpDwnSpd UnitDelay1_DSTATE_am1v;/* '<S16>/Unit Delay1' */
  TeTHA_e_THARmpUpDwnSpd UnitDelay_DSTATE_lln4;/* '<S16>/Unit Delay' */
  real32_T PrevY;                      /* '<S41>/DgainRateLimitor1' */
  real32_T last_pos[3];                /* '<S36>/Compute_Dead_Reckoning' */
  real32_T DifferenceInputs1_DWORK1;   /* '<S15>/Difference Inputs1' */
  int32_T Rpt_Ydiff_DWORK1;            /* '<S10>/Rpt_Ydiff' */
  boolean_T UnitDelay_DSTATE_dqs4;     /* '<S1>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_ogps;    /* '<S146>/Unit Delay1' */
  boolean_T DelayOneStep_DSTATE;       /* '<S36>/Delay One Step' */
  boolean_T UnitDelay4_DSTATE;         /* '<S41>/Unit Delay4' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S42>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_lsdo;/* '<S41>/DiscreteTimeIntegrator' */
  int8_T Discrete_Time_Integrator1_PrevResetState;/* '<S40>/Discrete_Time_Integrator1' */
  int8_T Discrete_Time_Integrator1_PrevResetState_pyfj;/* '<S79>/Discrete_Time_Integrator1' */
  uint8_T is_active_c68_THA_VC_Ref;    /* '<S41>/Chart' */
  uint8_T is_c68_THA_VC_Ref;           /* '<S41>/Chart' */
  uint8_T x;                           /* '<S36>/Forward_Kinematics_Model1' */
  uint8_T y;                           /* '<S36>/Forward_Kinematics_Model1' */
  uint8_T error;                       /* '<S36>/Forward_Kinematics_Model1' */
  uint8_T x_mu1j;                      /* '<S36>/Forward_Kinematics_Model' */
  uint8_T y_eojm;                      /* '<S36>/Forward_Kinematics_Model' */
  uint8_T error_n0hy;                  /* '<S36>/Forward_Kinematics_Model' */
  uint8_T last_tick_RR;                /* '<S36>/ComputeTickBasedWhlSpeed' */
  uint8_T last_tick_RF;                /* '<S36>/ComputeTickBasedWhlSpeed' */
  uint8_T last_tick_LF;                /* '<S36>/ComputeTickBasedWhlSpeed' */
  uint8_T last_tick_LR;                /* '<S36>/ComputeTickBasedWhlSpeed' */
  uint8_T icLoad;                      /* '<S15>/Resettable Delay' */
  uint8_T icLoad_hchm;                 /* '<S14>/Resettable Delay' */
  boolean_T last_tick_RR_not_empty;    /* '<S36>/ComputeTickBasedWhlSpeed' */
  boolean_T THA_KM_SteerTorque_Processing_MODE;
                                      /* '<S1>/THA_KM_SteerTorque_Processing' */
  boolean_T TrqControlOld_MODE;        /* '<S10>/TrqControlOld' */
  boolean_T Subsystem_MODE;            /* '<S39>/Subsystem' */
  boolean_T THA_Distance_SpeedLimit_Processing_MODE;
                                 /* '<S1>/THA_Distance_SpeedLimit_Processing' */
} DW_THA_VC_Ref_fwu4_T;

#endif                                 /*THA_VC_Ref_MDLREF_HIDE_CHILD_*/

/* Zero-crossing (trigger) state for model 'THA_VC_Ref' */
#ifndef THA_VC_Ref_MDLREF_HIDE_CHILD_

typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S69>/Delay' */
  ZCSigState Delay_Reset_ZCE_pnvs;     /* '<S70>/Delay' */
  ZCSigState Delay_Reset_ZCE_cdhr;     /* '<S71>/Delay' */
  ZCSigState Delay_Reset_ZCE_kvqh;     /* '<S72>/Delay' */
  ZCSigState Delay_Reset_ZCE_cqgx;     /* '<S75>/Delay' */
  ZCSigState Delay_Reset_ZCE_lhwz;     /* '<S73>/Delay' */
  ZCSigState Delay_Reset_ZCE_pmiu;     /* '<S74>/Delay' */
  ZCSigState ResettableDelay_Reset_ZCE;/* '<S15>/Resettable Delay' */
  ZCSigState ResettableDelay_Reset_ZCE_ajsj;/* '<S14>/Resettable Delay' */
} ZCE_THA_VC_Ref_T;

#endif                                 /*THA_VC_Ref_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for model 'THA_VC_Ref' */
#ifndef THA_VC_Ref_MDLREF_HIDE_CHILD_

typedef struct {
  const real32_T DataTypeConversion27; /* '<S10>/Data Type Conversion27' */
  const real32_T alpha;                /* '<S69>/Divide' */
  const real32_T one_minus_alpha;      /* '<S69>/Add' */
  const real32_T alpha_kmmg;           /* '<S70>/Divide' */
  const real32_T one_minus_alpha_byr0; /* '<S70>/Add' */
  const real32_T alpha_poul;           /* '<S71>/Divide' */
  const real32_T one_minus_alpha_iwdm; /* '<S71>/Add' */
  const real32_T alpha_dyf4;           /* '<S72>/Divide' */
  const real32_T one_minus_alpha_ozv1; /* '<S72>/Add' */
  const real32_T alpha_n3n2;           /* '<S73>/Divide' */
  const real32_T one_minus_alpha_kfc5; /* '<S73>/Add' */
  const real32_T alpha_nu5l;           /* '<S74>/Divide' */
  const real32_T one_minus_alpha_nbz0; /* '<S74>/Add' */
  const real32_T alpha_f52f;           /* '<S75>/Divide' */
  const real32_T one_minus_alpha_l2zc; /* '<S75>/Add' */
  const real32_T Constant1;            /* '<S42>/Constant1' */
  const real32_T Constant1_it32;       /* '<S41>/Constant1' */
  const uint8_T DataTypeConversion36;  /* '<S10>/Data Type Conversion36' */
} ConstB_THA_VC_Ref_hb4t_T;

#endif                                 /*THA_VC_Ref_MDLREF_HIDE_CHILD_*/

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T MeTHA_deg_RelAngle;    /* '<S146>/Switch'
                                        * Initial angle made by coupler with Hitch when THA is engaged.
                                        */
extern real32_T MeTHA_deg_StrAngCmd;   /* '<S39>/Signal Copy'
                                        * Required steering angle calculated by steering control block of VC.
                                        */
extern void THA_VC_Ref_Init(void);
extern void THA_VC_Ref_Reset(void);
extern void THA_VC_Ref_Start(real32_T *rty_IeTHA_pct_THAStrDamp);
extern void THA_VC_Ref_Disable(TeTHA_e_THARmpUpDwnSpd
  *rty_IeTHA_e_THARmpUpDwnSpd, real32_T *rty_MeTHA_deg_RoadWhlAng);
extern void THA_VC_Ref(const TbTHASmVc_InputFromThaDet_t
  *rtu_MbTHA_ThaDetOutData, const TbTHASmVc_InputFromVehInp_t
  *rtu_MbTHA_VehInpOutData, const TbTHASmVc_InputFromProxiMgr_t
  *rtu_MbTHA_ProxiMgrOutData, const TbTHASmVc_InputVrntTunParam_t
  *rtu_MbTHA_VrntTunParamOutData, const TeTHA_e_THASteerTrqReq
  *rtu_MeTHA_e_THASteerTrqReq, const TeTHA_e_THAStateInfo
  *rtu_MeTHA_e_THAStateInfo, TeTHA_e_THARmpUpDwnSpd *rty_IeTHA_e_THARmpUpDwnSpd,
  real32_T *rty_IeTHA_M_THASteerTrqInfo, TeTHA_e_THASteerTrqReq
  *rty_IeTHA_e_THASteerTrqReq, real32_T *rty_IeTHA_pct_THAStrDamp, real32_T
  *rty_MeTHA_deg_RoadWhlAng);

/* Model reference registration function */
extern void THA_VC_Ref_initialize(void);

#ifndef THA_VC_Ref_MDLREF_HIDE_CHILD_

extern void THA_VC_Ref_MATLABFunction(real32_T rtu_rear, real32_T rtu_right,
  real32_T rtu_left, int8_T rtu_str_dir, real32_T rty_angles[4]);

#endif                                 /*THA_VC_Ref_MDLREF_HIDE_CHILD_*/

#ifndef THA_VC_Ref_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_THA_VC_Ref_caua_T THA_VC_Ref_B;

/* Block states (default storage) */
extern DW_THA_VC_Ref_fwu4_T THA_VC_Ref_DW;

/* Previous zero-crossings (trigger) states */
extern ZCE_THA_VC_Ref_T THA_VC_Ref_PrevZCX;

#endif                                 /*THA_VC_Ref_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'THA_VC_Ref'
 * '<S1>'   : 'THA_VC_Ref/THA_VC_Controller'
 * '<S2>'   : 'THA_VC_Ref/THA_VC_InputProcessing'
 * '<S3>'   : 'THA_VC_Ref/THA_VC_Controller/EnumeratedConstant1'
 * '<S4>'   : 'THA_VC_Ref/THA_VC_Controller/EnumeratedConstant2'
 * '<S5>'   : 'THA_VC_Ref/THA_VC_Controller/EnumeratedConstant7'
 * '<S6>'   : 'THA_VC_Ref/THA_VC_Controller/FloatComparison'
 * '<S7>'   : 'THA_VC_Ref/THA_VC_Controller/MagnaTimer'
 * '<S8>'   : 'THA_VC_Ref/THA_VC_Controller/Rate Limiter Dynamic'
 * '<S9>'   : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing'
 * '<S10>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing'
 * '<S11>'  : 'THA_VC_Ref/THA_VC_Controller/THA_MnvrAbort_SteerTorque_Processing'
 * '<S12>'  : 'THA_VC_Ref/THA_VC_Controller/THA_SteerTweakProfile_Processing2'
 * '<S13>'  : 'THA_VC_Ref/THA_VC_Controller/Rate Limiter Dynamic/Saturation Dynamic'
 * '<S14>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/DynamicRateLimiterX'
 * '<S15>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/DynamicRateLimiterY'
 * '<S16>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/enum_max_speed_output'
 * '<S17>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/max_speed_decider'
 * '<S18>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/DynamicRateLimiterX/Saturation Dynamic'
 * '<S19>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/DynamicRateLimiterY/Saturation Dynamic'
 * '<S20>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/enum_max_speed_output/EnumeratedConstant'
 * '<S21>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/enum_max_speed_output/EnumeratedConstant1'
 * '<S22>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/enum_max_speed_output/EnumeratedConstant10'
 * '<S23>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/enum_max_speed_output/EnumeratedConstant11'
 * '<S24>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/enum_max_speed_output/EnumeratedConstant12'
 * '<S25>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/enum_max_speed_output/EnumeratedConstant2'
 * '<S26>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/enum_max_speed_output/EnumeratedConstant3'
 * '<S27>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/enum_max_speed_output/EnumeratedConstant4'
 * '<S28>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/enum_max_speed_output/EnumeratedConstant5'
 * '<S29>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/enum_max_speed_output/EnumeratedConstant6'
 * '<S30>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/enum_max_speed_output/EnumeratedConstant7'
 * '<S31>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/enum_max_speed_output/EnumeratedConstant8'
 * '<S32>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/enum_max_speed_output/EnumeratedConstant9'
 * '<S33>'  : 'THA_VC_Ref/THA_VC_Controller/THA_Distance_SpeedLimit_Processing/enum_max_speed_output/MagnaTimer'
 * '<S34>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/Atan_diff_deg'
 * '<S35>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/Compare_To_Constant'
 * '<S36>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM'
 * '<S37>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/ForwardSteerTrqCmd'
 * '<S38>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/Mvg_Avg'
 * '<S39>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/PreProcessor'
 * '<S40>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control'
 * '<S41>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/TrqControlOld'
 * '<S42>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/TrqControl_PID_Error'
 * '<S43>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/low_pass_filter'
 * '<S44>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/CAN_WhlSpeed_Merger1'
 * '<S45>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/ComputeTickBasedWhlSpeed'
 * '<S46>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/ComputeWheelAngles'
 * '<S47>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/Compute_Dead_Reckoning'
 * '<S48>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/Compute_Whl_Pos'
 * '<S49>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/Compute_Whl_Radius'
 * '<S50>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/Forward_Kinematics_Model'
 * '<S51>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/Forward_Kinematics_Model1'
 * '<S52>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/Inst_Vel_Merger'
 * '<S53>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/LPF2'
 * '<S54>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/LPF3'
 * '<S55>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/MATLAB Function'
 * '<S56>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/MATLAB Function1'
 * '<S57>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/MATLAB Function4'
 * '<S58>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/Tick_WhlSpeed_Merger'
 * '<S59>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/Tick_WhlSpeed_Merger1'
 * '<S60>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/WhlStatus_Merger'
 * '<S61>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/ComputeWheelAngles/If Action Subsystem1'
 * '<S62>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/ComputeWheelAngles/If Action Subsystem2'
 * '<S63>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/ComputeWheelAngles/If Action Subsystem3'
 * '<S64>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/ComputeWheelAngles/If Action Subsystem8'
 * '<S65>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/ComputeWheelAngles/If Action Subsystem1/MATLAB Function'
 * '<S66>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/ComputeWheelAngles/If Action Subsystem2/MATLAB Function'
 * '<S67>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/ComputeWheelAngles/If Action Subsystem3/MATLAB Function'
 * '<S68>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/ComputeWheelAngles/If Action Subsystem8/MATLAB Function'
 * '<S69>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/LPF2/LPF_1'
 * '<S70>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/LPF2/LPF_2'
 * '<S71>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/LPF2/LPF_3'
 * '<S72>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/LPF2/LPF_4'
 * '<S73>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/LPF3/LPF_1'
 * '<S74>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/LPF3/LPF_2'
 * '<S75>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/FKM/LPF3/LPF_3'
 * '<S76>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/ForwardSteerTrqCmd/EnumeratedConstant7'
 * '<S77>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/PreProcessor/Compare To Constant'
 * '<S78>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/PreProcessor/Saturation Dynamic'
 * '<S79>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/PreProcessor/Subsystem'
 * '<S80>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/PreProcessor/Subsystem/Compare_To_Zero'
 * '<S81>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Compare_To_Constant'
 * '<S82>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Compare_To_Zero'
 * '<S83>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller'
 * '<S84>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Rate_Limiter_Dynamic'
 * '<S85>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/determine_str_rate_limit'
 * '<S86>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Anti-windup'
 * '<S87>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/D Gain'
 * '<S88>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Filter'
 * '<S89>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Filter ICs'
 * '<S90>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/I Gain'
 * '<S91>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Ideal P Gain'
 * '<S92>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Ideal P Gain Fdbk'
 * '<S93>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Integrator'
 * '<S94>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Integrator ICs'
 * '<S95>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/N Copy'
 * '<S96>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/N Gain'
 * '<S97>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/P Copy'
 * '<S98>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Parallel P Gain'
 * '<S99>'  : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Reset Signal'
 * '<S100>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Saturation'
 * '<S101>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Saturation Fdbk'
 * '<S102>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Sum'
 * '<S103>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Sum Fdbk'
 * '<S104>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Tracking Mode'
 * '<S105>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Tracking Mode Sum'
 * '<S106>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/postSat Signal'
 * '<S107>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/preSat Signal'
 * '<S108>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Anti-windup/Passthrough'
 * '<S109>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/D Gain/External Parameters'
 * '<S110>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Filter/Disc. Forward Euler Filter'
 * '<S111>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Filter ICs/Internal IC - Filter'
 * '<S112>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/I Gain/External Parameters'
 * '<S113>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Ideal P Gain/Passthrough'
 * '<S114>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Ideal P Gain Fdbk/Disabled'
 * '<S115>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Integrator/Discrete'
 * '<S116>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Integrator ICs/Internal IC'
 * '<S117>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/N Copy/Disabled'
 * '<S118>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/N Gain/External Parameters'
 * '<S119>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/P Copy/Disabled'
 * '<S120>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Parallel P Gain/External Parameters'
 * '<S121>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Reset Signal/Disabled'
 * '<S122>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Saturation/Passthrough'
 * '<S123>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Saturation Fdbk/Disabled'
 * '<S124>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Sum/Sum_PID'
 * '<S125>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Sum Fdbk/Disabled'
 * '<S126>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Tracking Mode/Disabled'
 * '<S127>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/Tracking Mode Sum/Passthrough'
 * '<S128>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/postSat Signal/Forward_Path'
 * '<S129>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Discrete_PID_Controller/preSat Signal/Forward_Path'
 * '<S130>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/STR_Control/Rate_Limiter_Dynamic/Saturation Dynamic'
 * '<S131>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/TrqControlOld/Chart'
 * '<S132>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/TrqControlOld/Compare To Constant'
 * '<S133>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/TrqControl_PID_Error/EnumeratedConstant1'
 * '<S134>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/TrqControl_PID_Error/EnumeratedConstant2'
 * '<S135>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/TrqControl_PID_Error/EnumeratedConstant7'
 * '<S136>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/TrqControl_PID_Error/Rate Limiter Dynamic'
 * '<S137>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/TrqControl_PID_Error/Saturation Dynamic'
 * '<S138>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/TrqControl_PID_Error/Saturation Dynamic1'
 * '<S139>' : 'THA_VC_Ref/THA_VC_Controller/THA_KM_SteerTorque_Processing/TrqControl_PID_Error/Rate Limiter Dynamic/Saturation Dynamic'
 * '<S140>' : 'THA_VC_Ref/THA_VC_InputProcessing/EnumeratedConstant1'
 * '<S141>' : 'THA_VC_Ref/THA_VC_InputProcessing/EnumeratedConstant2'
 * '<S142>' : 'THA_VC_Ref/THA_VC_InputProcessing/EnumeratedConstant3'
 * '<S143>' : 'THA_VC_Ref/THA_VC_InputProcessing/EnumeratedConstant4'
 * '<S144>' : 'THA_VC_Ref/THA_VC_InputProcessing/EnumeratedConstant5'
 * '<S145>' : 'THA_VC_Ref/THA_VC_InputProcessing/EnumeratedConstant6'
 * '<S146>' : 'THA_VC_Ref/THA_VC_InputProcessing/InitCplrAngSelect'
 * '<S147>' : 'THA_VC_Ref/THA_VC_InputProcessing/Subsystem'
 * '<S148>' : 'THA_VC_Ref/THA_VC_InputProcessing/Subsystem/EnumeratedConstant7'
 */

/*-
 * Requirements for '<Root>': THA_VC_Ref
 */
#endif                                 /* RTW_HEADER_THA_VC_Ref_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
