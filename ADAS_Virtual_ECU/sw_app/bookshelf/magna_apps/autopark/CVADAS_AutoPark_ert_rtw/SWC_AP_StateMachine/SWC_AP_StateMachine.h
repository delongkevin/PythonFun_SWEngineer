/*
 * File: SWC_AP_StateMachine.h
 *
 * Code generated for Simulink model 'SWC_AP_StateMachine'.
 *
 * Model version                  : 1.2855
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:49:36 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_AP_StateMachine_h_
#define RTW_HEADER_SWC_AP_StateMachine_h_
#include <math.h>
#ifndef SWC_AP_StateMachine_COMMON_INCLUDES_
# define SWC_AP_StateMachine_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                /* SWC_AP_StateMachine_COMMON_INCLUDES_ */

#include "SWC_AP_StateMachine_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* user code (top of header file) */
#include "SignalDef.h"

/* Block signals for model 'SWC_AP_StateMachine' */
#ifndef SWC_AP_StateMachine_MDLREF_HIDE_CHILD_

typedef struct {
  TbAP_SMDebugOut IbAP_SMDebugOut;     /* '<S6>/Bus Creator' */
  uint64m_T UnitDelay;                 /* '<S5>/Unit Delay' */
  real_T Switch1;                      /* '<S47>/Switch1' */
  real_T Switch2;                      /* '<S47>/Switch2' */
  real_T Switch1_c;                    /* '<S27>/Switch1' */
  real_T Switch2_i;                    /* '<S27>/Switch2' */
  real_T Switch1_e;                    /* '<S23>/Switch1' */
  real_T Switch2_k;                    /* '<S23>/Switch2' */
  real32_T UnitDelay6;                 /* '<S186>/Unit Delay6' */
  real32_T IeVBII_per_PdlPosAct;
  real32_T Abs;                        /* '<Root>/Abs' */
  TeVBII_e_VehEPBSts IeVBII_e_VehEPBSts;
  TeAutoPark_e_AutoParkStatus IeAP_e_AutoParkStatus;/* '<S3>/Unit Delay7' */
  TeAP_e_USSSystemState Switch8;       /* '<S136>/Switch8' */
  TeAP_e_USSSystemMode Switch1_k;      /* '<S135>/Switch1' */
  TeAP_e_USSSystemMode Switch2_o;      /* '<S135>/Switch2' */
  TeAP_e_USSSystemMode Switch3;        /* '<S135>/Switch3' */
  TeAP_e_USSSystemMode Switch10;       /* '<S135>/Switch10' */
  TeAP_e_USSSystemMode Switch11;       /* '<S135>/Switch11' */
  TeAP_e_SPMLatCtrlReqSts IeAP_e_SPMLatCtrlReqSts;/* '<S5>/AUTOPARK_StateMachine' */
  TeAP_e_SPMActvStat UnitDelay9;       /* '<S3>/Unit Delay9' */
  TeAP_e_RearSnsrStatus Switch1_n;     /* '<S110>/Switch1' */
  TeAP_e_ParKMnvrActv IeAP_e_ParKMnvrActv;/* '<S3>/Unit Delay' */
  TeAP_e_PAMOffStatus2BT UnitDelay5;   /* '<S186>/Unit Delay5' */
  TeAP_e_GearShiftReq UnitDelay3;      /* '<S3>/Unit Delay3' */
  TeAP_e_FrntSnsrStatus Switch1_co;    /* '<S109>/Switch1' */
  TeAP_e_FiltdGearState UnitDelay9_o;  /* '<S186>/Unit Delay9' */
  TeAP_e_AlgoState UnitDelay2;         /* '<S3>/Unit Delay2' */
  TeAP_e_AlgoState UnitDelay4;         /* '<S186>/Unit Delay4' */
  uint16_T UnitDelay2_n;               /* '<S65>/Unit Delay2' */
  uint16_T Switch4;                    /* '<S65>/Switch4' */
  uint16_T Switch1_p;                  /* '<S65>/Switch1' */
  uint16_T Subtract;                   /* '<S65>/Subtract' */
  uint16_T UnitDelay2_l;               /* '<S47>/Unit Delay2' */
  uint16_T Switch3_d;                  /* '<S47>/Switch3' */
  uint16_T Subtract_l;                 /* '<S47>/Subtract' */
  uint16_T UnitDelay2_b;               /* '<S23>/Unit Delay2' */
  uint16_T Switch3_l;                  /* '<S23>/Switch3' */
  uint16_T UnitDelay2_m;               /* '<S27>/Unit Delay2' */
  uint16_T Switch3_p;                  /* '<S27>/Switch3' */
  uint16_T Subtract_a;                 /* '<S27>/Subtract' */
  uint16_T Subtract_j;                 /* '<S23>/Subtract' */
  uint16_T MeAP_cnt_TransDebugVar_h;   /* '<S6>/Data Type Conversion1' */
  uint8_T Switch8_m;                   /* '<S132>/Switch8' */
  uint8_T MeAP_e_USSFiringMode;        /* '<S132>/Switch1' */
  uint8_T Switch1_m;                   /* '<S184>/Switch1' */
  uint8_T Switch2_p;                   /* '<S184>/Switch2' */
  uint8_T Switch3_c;                   /* '<S184>/Switch3' */
  uint8_T Switch4_b;                   /* '<S184>/Switch4' */
  uint8_T Switch5;                     /* '<S184>/Switch5' */
  uint8_T DataTypeConversion2;         /* '<S64>/Data Type Conversion2' */
  uint8_T DataTypeConversion8;         /* '<S10>/Data Type Conversion8' */
  uint8_T DataTypeConversion1;         /* '<S31>/Data Type Conversion1' */
  boolean_T LogicalOperator4;          /* '<S133>/Logical Operator4' */
  boolean_T MeAP_b_SeekSpdExceedTimeout;/* '<S3>/Unit Delay1' */
  boolean_T UnitDelay4_o;              /* '<S3>/Unit Delay4' */
  boolean_T UnitDelay5_l;              /* '<S3>/Unit Delay5' */
  boolean_T UnitDelay6_j;              /* '<S3>/Unit Delay6' */
  boolean_T UnitDelay8;                /* '<S3>/Unit Delay8' */
  boolean_T UnitDelay10;               /* '<S3>/Unit Delay10' */
  boolean_T UnitDelay11;               /* '<S3>/Unit Delay11' */
  boolean_T UnitDelay12;               /* '<S3>/Unit Delay12' */
  boolean_T MeAP_b_SeekPhaseTimeout;   /* '<S3>/Unit Delay13' */
  boolean_T MeAP_b_InitBrkPedlPressed_h;/* '<S3>/Unit Delay14' */
  boolean_T MeAP_b_ValidSlotAvl;       /* '<S8>/Logical Operator' */
  boolean_T MeAP_e_b_PSExistL;         /* '<S8>/Logical Operator1' */
  boolean_T MeAP_e_b_PSExistR;         /* '<S8>/Logical Operator2' */
  boolean_T Switch1_j[2];              /* '<S187>/Switch1' */
  boolean_T Switch1_pg;                /* '<S186>/Switch1' */
  boolean_T DataTypeConversion5;       /* '<S5>/Data Type Conversion5' */
  boolean_T MeAP_b_BSMInterfaceTimeout;/* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_EPSInterfaceTimeout;/* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_GearShiftWaitTimeout;/* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_CamHandshakeTimeout;/* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_ObjInPathTimeout_m; /* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_PausedPressBtnTimeout_c;/* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_BSMHandshakeSts;    /* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_SeekSpdExceedTimeout_f;/* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_SeekPhaseTimeout_m; /* '<S5>/AUTOPARK_StateMachine' */
  boolean_T UnitDelay1;                /* '<S15>/Unit Delay1' */
  boolean_T UnitDelay2_i;              /* '<S15>/Unit Delay2' */
  boolean_T IeVBII_b_Override;
  boolean_T UnitDelay3_o;              /* '<S15>/Unit Delay3' */
  boolean_T UnitDelay_k;               /* '<S15>/Unit Delay' */
  boolean_T LogicalOperator;           /* '<S15>/Logical Operator' */
  boolean_T LogicalOperator36;         /* '<S15>/Logical Operator36' */
  boolean_T KeAP_b_SVSPresent;
  boolean_T MeAP_b_BSMHandshakeActv;   /* '<S30>/Logical Operator1' */
  boolean_T MeAP_b_WheelHandsOff;      /* '<S33>/Logical Operator1' */
  boolean_T MeAP_b_RmvHandsFeetConSucs;/* '<S33>/Logical Operator' */
  boolean_T MeAP_b_EPSHandshakeActv;   /* '<S32>/Logical Operator' */
  boolean_T LogicalOperator9;          /* '<S28>/Logical Operator9' */
  boolean_T LogicalOperator3;          /* '<S46>/Logical Operator3' */
  boolean_T UnitDelay1_o;              /* '<S48>/Unit Delay1' */
  boolean_T UnitDelay_n;               /* '<S49>/Unit Delay' */
  boolean_T Switch1_e5;                /* '<S49>/Switch1' */
  boolean_T UnitDelay_b;               /* '<S28>/Unit Delay' */
  boolean_T MeAP_b_APASwtStatus;       /* '<S28>/Switch' */
  boolean_T reset;                     /* '<S47>/Logical Operator' */
  boolean_T UnitDelay1_f;              /* '<S47>/Unit Delay1' */
  boolean_T LogicalOperator8;          /* '<S47>/Logical Operator8' */
  boolean_T UnitDelay_a;               /* '<S34>/Unit Delay' */
  boolean_T Switch2_f;                 /* '<S49>/Switch2' */
  boolean_T MeAP_b_AutoParkEnblSwtStatus;/* '<S34>/Chart1' */
  boolean_T MeAP_b_PPPABtnPressed;     /* '<S34>/Chart1' */
  boolean_T MeAP_b_PPPABtnReleased;    /* '<S34>/Chart1' */
  boolean_T LogicalOperator12;         /* '<S28>/Logical Operator12' */
  boolean_T LogicalOperator2;          /* '<S18>/Logical Operator2' */
  boolean_T Delay;                     /* '<S18>/Delay' */
  boolean_T MeAP_b_FPASwtStatus;       /* '<S18>/Switch' */
  boolean_T MeAP_b_FPASwtStuckStatus;  /* '<S18>/Logical Operator' */
  boolean_T UnitDelay1_p;              /* '<S23>/Unit Delay1' */
  boolean_T reset_f;                   /* '<S23>/Logical Operator' */
  boolean_T LogicalOperator8_e;        /* '<S23>/Logical Operator8' */
  boolean_T LogicalOperator2_h;        /* '<S19>/Logical Operator2' */
  boolean_T Delay_a;                   /* '<S19>/Delay' */
  boolean_T MeAP_b_RPASwtStatus;       /* '<S19>/Switch' */
  boolean_T MeAP_b_RPASwtStuckStatus;  /* '<S19>/Logical Operator' */
  boolean_T UnitDelay1_px;             /* '<S27>/Unit Delay1' */
  boolean_T reset_j;                   /* '<S27>/Logical Operator' */
  boolean_T LogicalOperator8_a;        /* '<S27>/Logical Operator8' */
  boolean_T LogicalOperator4_o;        /* '<S19>/Logical Operator4' */
  boolean_T LogicalOperator4_m;        /* '<S18>/Logical Operator4' */
  boolean_T Switch[2];                 /* '<S187>/Switch' */
  boolean_T RelationalOperator1;       /* '<S187>/Relational Operator1' */
  boolean_T LogicalOperator1;          /* '<S187>/Logical Operator1' */
  boolean_T RelationalOperator5;       /* '<S184>/Relational Operator5' */
  boolean_T RelationalOperator7;       /* '<S184>/Relational Operator7' */
  boolean_T RelationalOperator8;       /* '<S184>/Relational Operator8' */
  boolean_T RelationalOperator10;      /* '<S184>/Relational Operator10' */
  boolean_T RelationalOperator11;      /* '<S184>/Relational Operator11' */
  boolean_T RelationalOperator1_f;     /* '<S136>/RelationalOperator1' */
  boolean_T RelationalOperator7_g;     /* '<S135>/RelationalOperator7' */
  boolean_T RelationalOperator9;       /* '<S135>/Relational Operator9' */
  boolean_T RelationalOperator8_g;     /* '<S135>/RelationalOperator8' */
  boolean_T RelationalOperator11_g;    /* '<S135>/RelationalOperator11' */
  boolean_T RelationalOperator13;      /* '<S135>/Relational Operator13' */
  boolean_T RelationalOperator10_c;    /* '<S135>/RelationalOperator10' */
  boolean_T RelationalOperator30;      /* '<S15>/Relational Operator30' */
  boolean_T RelationalOperator;        /* '<S65>/Relational Operator' */
  boolean_T RelationalOperator_n;      /* '<S47>/Relational Operator' */
  boolean_T RelationalOperator_k;      /* '<S27>/Relational Operator' */
  boolean_T RelationalOperator_h;      /* '<S23>/Relational Operator' */
  boolean_T RelationalOperator18;      /* '<S186>/Relational Operator18' */
  boolean_T LogicalOperator3_l;        /* '<S184>/Logical Operator3' */
  boolean_T LogicalOperator4_my;       /* '<S184>/Logical Operator4' */
  boolean_T LogicalOperator5;          /* '<S184>/Logical Operator5' */
  boolean_T LogicalOperator6;          /* '<S184>/Logical Operator6' */
  boolean_T LogicalOperator7;          /* '<S184>/Logical Operator7' */
  boolean_T RelationalOperator8_i;     /* '<S135>/Relational Operator8' */
  boolean_T LogicalOperator9_i;        /* '<S135>/Logical Operator9' */
  boolean_T LogicalOperator8_n;        /* '<S135>/Logical Operator8' */
  boolean_T LogicalOperator10;         /* '<S135>/Logical Operator10' */
  boolean_T RelationalOperator9_m;     /* '<S135>/RelationalOperator9' */
  boolean_T LogicalOperator12_c;       /* '<S135>/Logical Operator12' */
  boolean_T LogicalOperator14;         /* '<S135>/Logical Operator14' */
  boolean_T LogicalOperator16;         /* '<S135>/Logical Operator16' */
  boolean_T RelationalOperator43;      /* '<S15>/Relational Operator43' */
  boolean_T LogicalOperator38;         /* '<S15>/Logical Operator38' */
  boolean_T LogicalOperator1_f;        /* '<S48>/Logical Operator1' */
  boolean_T LogicalOperator_d;         /* '<S186>/Logical Operator' */
  boolean_T LogicalOperator11;         /* '<S186>/Logical Operator11' */
  boolean_T LogicalOperator11_n;       /* '<S135>/Logical Operator11' */
  boolean_T LogicalOperator15;         /* '<S135>/Logical Operator15' */
  boolean_T LogicalOperator13;         /* '<S15>/Logical Operator13' */
  boolean_T LogicalOperator3_i;        /* '<S8>/Logical Operator3' */
  boolean_T LogicalOperator13_c;       /* '<S186>/Logical Operator13' */
  boolean_T LogicalOperator5_a;        /* '<S186>/Logical Operator5' */
  boolean_T RelationalOperator12;      /* '<S186>/Relational Operator12' */
  boolean_T LogicalOperator4_f;        /* '<S186>/Logical Operator4' */
  boolean_T RelationalOperator_g;      /* '<S33>/Relational Operator' */
  boolean_T LogicalOperator3_a;        /* '<S186>/Logical Operator3' */
  boolean_T LogicalOperator2_p;        /* '<S186>/Logical Operator2' */
  boolean_T RelationalOperator_o;      /* '<Root>/Relational Operator' */
} B_SWC_AP_StateMachine_c_T;

#endif                                /*SWC_AP_StateMachine_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'SWC_AP_StateMachine' */
#ifndef SWC_AP_StateMachine_MDLREF_HIDE_CHILD_

typedef struct {
  uint64m_T UnitDelay_DSTATE;          /* '<S5>/Unit Delay' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S14>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S14>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S14>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_o;                     /* '<S15>/Scope' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S31>/Scope3' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK_o;                    /* '<S31>/Scope2' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<S31>/Scope5' */

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      /* '<S31>/Scope4' */

  struct {
    void *LoggedData;
  } Scope10_PWORK;                     /* '<S31>/Scope10' */

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<S31>/Scope6' */

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      /* '<S31>/Scope9' */

  struct {
    void *LoggedData;
  } Scope_PWORK_k;                     /* '<S28>/Scope' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_a;                    /* '<S28>/Scope3' */

  real32_T UnitDelay6_DSTATE;          /* '<S186>/Unit Delay6' */
  TeAP_e_FiltdGearState UnitDelay9_DSTATE;/* '<S186>/Unit Delay9' */
  TeAP_e_PAMOffStatus2BT UnitDelay5_DSTATE;/* '<S186>/Unit Delay5' */
  TeAP_e_ParKMnvrActv UnitDelay_DSTATE_f;/* '<S3>/Unit Delay' */
  TeAutoPark_e_AutoParkStatus UnitDelay7_DSTATE;/* '<S3>/Unit Delay7' */
  TeAP_e_AlgoState UnitDelay2_DSTATE;  /* '<S3>/Unit Delay2' */
  TeAP_e_AlgoState UnitDelay_DSTATE_p; /* '<S186>/Unit Delay' */
  TeAP_e_AlgoState UnitDelay1_DSTATE;  /* '<S186>/Unit Delay1' */
  TeAP_e_AlgoState UnitDelay2_DSTATE_p;/* '<S186>/Unit Delay2' */
  TeAP_e_AlgoState UnitDelay3_DSTATE;  /* '<S186>/Unit Delay3' */
  TeAP_e_AlgoState UnitDelay4_DSTATE;  /* '<S186>/Unit Delay4' */
  TeAP_e_SPMActvStat UnitDelay9_DSTATE_p;/* '<S3>/Unit Delay9' */
  TeAP_e_GearShiftReq UnitDelay3_DSTATE_d;/* '<S3>/Unit Delay3' */
  uint32_T MeAP_s_PausedPressBtnCnt;   /* '<S5>/AUTOPARK_StateMachine' */
  TeAP_b_PPPAMode MeAP_b_PPPAMode;     /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T UnitDelay2_DSTATE_e;        /* '<S65>/Unit Delay2' */
  uint16_T UnitDelay2_DSTATE_o;        /* '<S47>/Unit Delay2' */
  uint16_T UnitDelay2_DSTATE_j;        /* '<S23>/Unit Delay2' */
  uint16_T UnitDelay2_DSTATE_f;        /* '<S27>/Unit Delay2' */
  uint16_T MeAP_s_SeekPhaseSecCnt;     /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_s_SeekSpdExceedSecCnt; /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_s_BSMInterfaceCnt;     /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_s_EPSInterfaceCnt;     /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_s_ObjInPathCnt;        /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_s_CamHandshakeSecCnt;  /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_s_GearShiftWaitCnt;    /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_cnt_SPMBlinkLEDCnt;    /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_cnt_WaitEngineCnt;     /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_cnt_ScreenChimeCnt;    /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_cnt_EngagedFullWaitCnt;/* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_cnt_ScreenWaitCnt;     /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_cnt_StandstillTimer;   /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_cnt_AbortDelayWaitCnt; /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_cnt_RelCntrlWaitCnt;   /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_cnt_AbortHMIWaitCnt;   /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_cnt_DisableHMICnt;     /* '<S5>/AUTOPARK_StateMachine' */
  uint16_T MeAP_cnt_SwtStuckTimeCnt;   /* '<S34>/Chart1' */
  boolean_T UnitDelay1_DSTATE_f;       /* '<S3>/Unit Delay1' */
  boolean_T UnitDelay4_DSTATE_a;       /* '<S3>/Unit Delay4' */
  boolean_T UnitDelay5_DSTATE_k;       /* '<S3>/Unit Delay5' */
  boolean_T UnitDelay6_DSTATE_c;       /* '<S3>/Unit Delay6' */
  boolean_T UnitDelay8_DSTATE;         /* '<S3>/Unit Delay8' */
  boolean_T UnitDelay10_DSTATE;        /* '<S3>/Unit Delay10' */
  boolean_T UnitDelay11_DSTATE;        /* '<S3>/Unit Delay11' */
  boolean_T UnitDelay12_DSTATE;        /* '<S3>/Unit Delay12' */
  boolean_T UnitDelay13_DSTATE;        /* '<S3>/Unit Delay13' */
  boolean_T UnitDelay14_DSTATE;        /* '<S3>/Unit Delay14' */
  boolean_T UnitDelay1_DSTATE_fv;      /* '<S15>/Unit Delay1' */
  boolean_T UnitDelay2_DSTATE_b;       /* '<S15>/Unit Delay2' */
  boolean_T UnitDelay3_DSTATE_o;       /* '<S15>/Unit Delay3' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S15>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_m;        /* '<S46>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_i;       /* '<S28>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_e;       /* '<S48>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_f5;       /* '<S49>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_n;        /* '<S47>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_l;        /* '<S28>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_fb;      /* '<S47>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_a;        /* '<S34>/Unit Delay' */
  boolean_T Delay_DSTATE;              /* '<S18>/Delay' */
  boolean_T UnitDelay_DSTATE_k;        /* '<S22>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_m3;       /* '<S23>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_k;       /* '<S23>/Unit Delay1' */
  boolean_T Delay_DSTATE_l;            /* '<S19>/Delay' */
  boolean_T UnitDelay_DSTATE_la;       /* '<S26>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_o;        /* '<S27>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_fl;      /* '<S27>/Unit Delay1' */
  uint8_T is_active_c1_SWC_AP_StateMachine;/* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_c1_SWC_AP_StateMachine;   /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_FAULT;                    /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_ON;                       /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_STANDBY;                  /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_ACTIVE_AUTOPARK;          /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_ParkIn;                   /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_Scanning_FullAutoPark;    /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_SEARCHING_MOVE_FORWARD;   /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_SPACE_FOUND_STOP;         /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_SPACE_FOUND_STOP_STANDSTILL;/* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_SPACE_FOUND_SELECT_SPACE; /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_PERP_SELECT_RIGHT;        /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_PERP_SELECT_LEFT;         /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_DISCLAIMER;               /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_Scanning_SemiAutoPark;    /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_SEARCHING_MOVE_FORWARD_l; /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_SPACE_FOUND_STOP_k;       /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_SPACE_FOUND_STOP_STANDSTILL_a;/* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_SPACE_FOUND_SELECT_SPACE_b;/* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_Handshake_FullAutoPark;   /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_Active_SemiAutoPark;      /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_MutlipleMoves;            /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_Active_FullAutoPark;      /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_FULL_AUTO_ACTIVE_FRONT_REAR;/* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_Park_Exit;                /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_SemiAutoParkSCANNING;     /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_FullAutoParkSCANNING;     /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_Handshake_FullAutoPark_l; /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_Active_FullAutoPark_f;    /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_FULL_AUTO_ACTIVE_FRONT_REAR_o;/* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_Active_SemiAutoParkExit;  /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_MutlipleMoves_g;          /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_Abort;                    /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_Abort_HMI_3;              /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_Complete;                 /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T MeAP_cnt_Move;               /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T temporalCounter_i1;          /* '<S5>/AUTOPARK_StateMachine' */
  uint8_T is_active_c2_SWC_AP_StateMachine;/* '<S34>/Chart1' */
  uint8_T is_c2_SWC_AP_StateMachine;   /* '<S34>/Chart1' */
  uint8_T icLoad;                      /* '<S18>/Delay' */
  uint8_T icLoad_m;                    /* '<S19>/Delay' */
  boolean_T MeAP_b_BSMHandshakeSucces; /* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_EPSHandshakeSucces; /* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_BSMHandshakeStart;  /* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_EPSHandshakeStart;  /* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_MvCntUpdated;       /* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_WaitEngineTimeout;  /* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_EngagedFullWaitTimeout;/* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_ManoeuvreComplete;  /* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_VehicleParked;      /* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_HMIToIdle;          /* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_RelVehControl;      /* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_StandstillTimeout;  /* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_AbortDelayTimeOut;  /* '<S5>/AUTOPARK_StateMachine' */
  boolean_T MeAP_b_AbortHMITimeOut;    /* '<S5>/AUTOPARK_StateMachine' */
} DW_SWC_AP_StateMachine_f_T;

#endif                                /*SWC_AP_StateMachine_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for model 'SWC_AP_StateMachine' */
#ifndef SWC_AP_StateMachine_MDLREF_HIDE_CHILD_

typedef struct {
  const real32_T MeAP_s_FaultWaitTime; /* '<Root>/Constant2' */
  const TeAutoPark_e_ScanDir Constant17;/* '<Root>/Constant17' */
  const TeAutoPark_e_GearCmd Constant19;/* '<Root>/Constant19' */
  const TeAutoPark_e_ChimeReq Constant16;/* '<Root>/Constant16' */
  const TeAP_e_RearSnsrStatus Switch2; /* '<S110>/Switch2' */
  const TeAP_e_FrntSnsrStatus Switch2_o;/* '<S109>/Switch2' */
  const uint8_T IeAP_e_MnvActvStat;    /* '<S3>/Constant9' */
  const uint8_T IeAP_e_AbortCon;       /* '<S3>/Constant10' */
  const uint8_T IeAP_e_SemiParkSysSts; /* '<S3>/Constant11' */
  const uint8_T IeAP_e_DIDHMICode;     /* '<S3>/Constant12' */
  const boolean_T RelationalOperator8; /* '<S133>/Relational Operator8' */
  const boolean_T RelationalOperator9; /* '<S133>/Relational Operator9' */
  const boolean_T RelationalOperator10;/* '<S133>/Relational Operator10' */
  const boolean_T RelationalOperator11;/* '<S133>/Relational Operator11' */
  const boolean_T LogicalOperator13;   /* '<S133>/Logical Operator13' */
  const boolean_T DataTypeConversion;  /* '<S134>/Data Type  Conversion' */
  const boolean_T MeAP_b_ParkSlotDetctSts;/* '<S3>/Constant8' */
  const boolean_T Constant11;          /* '<Root>/Constant11' */
  const boolean_T Constant12;          /* '<Root>/Constant12' */
  const boolean_T Constant13;          /* '<Root>/Constant13' */
  const boolean_T Constant14;          /* '<Root>/Constant14' */
  const boolean_T Constant15;          /* '<Root>/Constant15' */
  const boolean_T Constant18;          /* '<Root>/Constant18' */
  const boolean_T IeAP_b_AutoParkOverride;/* '<Root>/Constant1' */
  const boolean_T MeAP_b_SensorFltSts; /* '<Root>/Constant' */
} ConstB_SWC_AP_StateMachine_h_T;

#endif                                /*SWC_AP_StateMachine_MDLREF_HIDE_CHILD_*/

#ifndef SWC_AP_StateMachine_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_SWC_AP_StateMachine_T {
  const char_T **errorStatus;
};

#endif                                /*SWC_AP_StateMachine_MDLREF_HIDE_CHILD_*/

#ifndef SWC_AP_StateMachine_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_SWC_AP_StateMachine_T rtm;
} MdlrefDW_SWC_AP_StateMachine_T;

#endif                                /*SWC_AP_StateMachine_MDLREF_HIDE_CHILD_*/

extern void SWC_AP_StateMachine_Init(void);
extern void SWC_AP_StateMachine(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeAutoPark_e_ParkStyle *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const TeHMI_e_UsrParkOutSide
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const TeAP_e_UsrPPPAManeuverSel
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const boolean_T
  *rtu_MbDiag_PlantModeOn, const boolean_T *rtu_MbDiag_TestModeForceOn, const
  boolean_T *rtu_MeAP_b_PosMet, const boolean_T *rtu_MeAP_b_SteerActionReq,
  const TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TbNVM_ReadParam
  *rtu_MbNVM_ReadParam, const TbNVM_ProxyCalibParam *rtu_MbNVM_ProxyParam, const
  TbUSS_DiagFlag *rtu_MbUSS_DiagFlag, const IJobFPAOutput_t
  *rtu_LwSpd_FPA_Output, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd, const
  boolean_T *rtu_MeAP_b_ManualParkReq, const boolean_T *rtu_MeAP_b_ObjInPath,
  const boolean_T *rtu_IbFID_PA_MeAP_b_FrntSenorFail, const boolean_T
  *rtu_IbFID_PA_MeAP_b_FrntSenorBlock, const boolean_T
  *rtu_IbFID_PA_MeAP_b_RearSenorFail, const boolean_T
  *rtu_IbFID_PA_MeAP_b_RearSenorBlock, const boolean_T
  *rtu_IbFID_PPPA_MeAP_b_PPPAActvTrlr, const boolean_T
  *rtu_IbFID_PPPA_MeAP_b_PPPAActv4LOW, const boolean_T
  *rtu_IbFID_PPPA_MeAP_b_PPPADisable, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOffThd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SPMBlinkLEDDur, const boolean_T
  *rtu_IbAP_InputVrntTunParam_KeAP_b_AutoParkEn, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt, const boolean_T
  *rtu_MeAP_b_ObjPrestFC, const boolean_T *rtu_MeAP_b_ObjPrestRC, const
  TeAP_e_PAMOffStatus2BT *rtu_MeAP_e_PAMOffStatus2BT, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist, const real32_T
  *rtu_IeAP_nm_StrwTrqReq, const TeTHA_e_RearBrkSupprInfo
  *rtu_MeTHA_e_RearBrkSupprInfo, TeAP_e_FrntSnsrStatus
  *rty_IeAP_e_FrntSnsrStatus, TeAP_e_RearSnsrStatus *rty_IeAP_e_RearSnsrStatus,
  boolean_T *rty_MeAP_b_DisableDiag, boolean_T
  *rty_MeAP_b_AutoParkEnblSwtStuckStatus, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_SPMLatCtrlReqSts *rty_IeAP_e_SPMLatCtrlReqSts,
  TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus *rty_IeAP_e_SPMLedSts, boolean_T
  *rty_IeAP_b_SPMFailSts, boolean_T *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *
  rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_IeAP_b_StandstillReq, boolean_T *rty_MeAP_b_VCOpPaused,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, uint8_T *rty_MeAP_b_parkout_perp_left,
  boolean_T *rty_MeAP_b_VCActive, boolean_T *rty_MeAP_b_PerpNoseIn, uint8_T
  *rty_MeAP_m_ParkSpotType, boolean_T *rty_MeAP_b_ParkOut, boolean_T
  *rty_MeAP_b_ResetVCKM, TeAP_e_USSSupplyPwrSt *rty_MeAP_e_USSSupplyPwrSt,
  TeAP_e_USSSystemMode *rty_MeAP_e_USSSystemMode, TeAP_e_USSSystemState
  *rty_MeAP_e_USSSystemState, uint8_T *rty_MeAP_e_USSFiringMode, boolean_T
  *rty_MeAP_b_USSReInit, boolean_T *rty_MeAP_b_ScanSts, uint16_T
  *rty_IbAP_SMDebugOut_MeAP_cnt_StateDebugVar, uint16_T
  *rty_IbAP_SMDebugOut_MeAP_cnt_TransDebugVar, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_VCOpPaused, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_BSMInterfaceTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_EPSInterfaceTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_GearShiftWaitTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_CamHandshakeTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_ObjInPathTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_PausedPressBtnTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_SeekSpdExceedTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_APInitSts, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_DriverOverride, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_StandStill, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_BSMHandshakeActv, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_VehCndSts, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_FeatureEnbl, boolean_T *rty_MeAP_b_StandStill);

/* Model reference registration function */
extern void SWC_AP_StateMachine_initialize(const char_T **rt_errorStatus);

/* Exported data declaration */

/* Declaration for custom storage class: Default */
extern uint16_T KeAP_Cnt_GearOverrideTimeThd;/* Referenced by: '<S31>/Constant1' */

/* Gear override time threshold */
extern boolean_T KeAP_b_DevlopmentTest;/* Referenced by:
                                        * '<S14>/Constant'
                                        * '<S14>/Constant1'
                                        * '<S14>/Constant2'
                                        */

/* Test Parameter used to change value of Tunable parameter while Testing */
extern uint16_T KeAP_cnt_AbortDelayWaitCnt;
                               /* Referenced by: '<S5>/AUTOPARK_StateMachine' */
extern real32_T KeAP_cnt_AbortHMIWaitCnt;
                               /* Referenced by: '<S5>/AUTOPARK_StateMachine' */
extern uint16_T KeAP_cnt_RelCntrlWaitThd;
                               /* Referenced by: '<S5>/AUTOPARK_StateMachine' */
extern uint16_T KeAP_cnt_ScreenChimeTimeoutDur;
                               /* Referenced by: '<S5>/AUTOPARK_StateMachine' */

/* Screen Chime Time Threshold */
extern uint16_T KeAP_cnt_ScreenWaitTimeoutDur;
                               /* Referenced by: '<S5>/AUTOPARK_StateMachine' */
extern uint16_T KeAP_cnt_StandstillTimeoutDur;
                               /* Referenced by: '<S5>/AUTOPARK_StateMachine' */

/*  Standstill Timer 9 min 50sec */
extern uint16_T KeAP_cnt_TimeStep;     /* Referenced by: '<S31>/Constant2' */

/* Time Step for Counter  */
extern real32_T KeAP_kph_FrntWarnMaxSpdThd;/* Referenced by:
                                            * '<S133>/Constant'
                                            * '<S133>/Constant1'
                                            * '<S135>/Constant3'
                                            * '<S135>/Constant5'
                                            * '<S135>/Constant6'
                                            * '<S135>/Constant8'
                                            * '<S186>/KeAP_kph_FrntWarnMaxSpdThd'
                                            * '<S186>/KeAP_kph_FrntWarnMaxSpdThd1'
                                            */

/* Vehicle speed threshold during Front Park Assist feature */
extern real32_T KeAP_kph_PSDOffThd;    /* Referenced by: '<S15>/Constant1' */

/* Vehicle speed threshold during detection the parking slot */
extern real32_T KeAP_kph_ParkMnvThd;   /* Referenced by: '<S15>/Constant2' */

/* Ego Vehicle speed limit to continue parking maneuvering */
extern real32_T KeAP_kph_RearWarnMaxSpdThd;/* Referenced by: '<S135>/Constant7' */

/* Vehicle speed threshold during Rear Park Assist feature */
extern real32_T KeAP_kph_StandStillSpdThd;
                               /* Referenced by: '<S5>/AUTOPARK_StateMachine' */
extern real32_T KeAP_pct_PdlPosActThd; /* Referenced by: '<S31>/Constant' */

/* Screen Chime Time Threshold */
extern uint16_T KeAP_s_GearShiftReqWaitCnt;
                               /* Referenced by: '<S5>/AUTOPARK_StateMachine' */
extern uint16_T KeAP_s_WaitEngineOnThd;
                               /* Referenced by: '<S5>/AUTOPARK_StateMachine' */

/* Engine On Time THreshold */
extern boolean_T MeAP_b_ACCEngg;       /* '<S15>/Logical Operator7' */
extern boolean_T MeAP_b_APActConAvl;   /* '<S28>/Logical Operator10' */
extern boolean_T MeAP_b_AbortCon1;     /* '<S14>/Logical Operator3' */
extern boolean_T MeAP_b_AbortCon2;     /* '<S14>/Logical Operator5' */
extern boolean_T MeAP_b_AbortCon3;     /* '<S14>/Logical Operator7' */
extern boolean_T MeAP_b_BSMHandshakeFailed;/* '<S15>/Logical Operator18' */
extern boolean_T MeAP_b_BrkPedlOverride;/* '<S31>/Logical Operator3' */
extern boolean_T MeAP_b_BtnPsd;        /* '<S15>/Switch1' */
extern boolean_T MeAP_b_DoorOpen;      /* '<S15>/Switch' */
extern boolean_T MeAP_b_DriverOverride;/* '<S31>/Logical Operator5' */
extern boolean_T MeAP_b_EPBOverride;   /* '<S31>/Relational Operator4' */
extern boolean_T MeAP_b_EPBStsFaulted; /* '<S15>/Logical Operator31' */
extern boolean_T MeAP_b_EPSHandshakeFailed;/* '<S15>/Logical Operator21' */
extern boolean_T MeAP_b_ESCActive;     /* '<S15>/Logical Operator39' */
extern boolean_T MeAP_b_ETMHandshakeFailed;/* '<S15>/Logical Operator26' */
extern boolean_T MeAP_b_FrntSnsrBlk;   /* '<S15>/Relational Operator12' */
extern boolean_T MeAP_b_GasPedlOverride;/* '<S31>/Logical Operator1' */
extern boolean_T MeAP_b_GearShiftOverride;/* '<S65>/Logical Operator8' */
extern boolean_T MeAP_b_GearShiftReqWaitTimeout;/* '<S5>/AUTOPARK_StateMachine' */
extern boolean_T MeAP_b_HandsOn;       /* '<S15>/Logical Operator9' */
extern boolean_T MeAP_b_InitBrkPedlPressed;/* '<S5>/AUTOPARK_StateMachine' */
extern boolean_T MeAP_b_LifeGateOpen;  /* '<S15>/Logical Operator1' */
extern boolean_T MeAP_b_Lo4DriveTrain; /* '<S15>/Relational Operator9' */
extern boolean_T MeAP_b_ManualParkReq; /* '<S15>/Logical Operator12' */
extern boolean_T MeAP_b_MnvSpdExceed;  /* '<S15>/Logical Operator3' */
extern boolean_T MeAP_b_ObjInPathTimeout;/* '<S15>/Logical Operator29' */
extern boolean_T MeAP_b_PausedPressBtnTimeout;/* '<S15>/Logical Operator30' */
extern boolean_T MeAP_b_PreEPSInterfaceAbort1;/* '<S5>/AUTOPARK_StateMachine' */
extern boolean_T MeAP_b_PreEPSInterfaceAbort2;/* '<S5>/AUTOPARK_StateMachine' */
extern boolean_T MeAP_b_RearSnsrBlk;   /* '<S15>/Relational Operator13' */
extern boolean_T MeAP_b_ResetKM;       /* '<S186>/Switch9' */
extern boolean_T MeAP_b_SeekSpdExceed; /* '<S15>/Logical Operator33' */
extern boolean_T MeAP_b_TCMFailed;     /* '<S15>/Logical Operator23' */
extern boolean_T MeAP_b_TrlrConn;      /* '<S15>/Logical Operator6' */
extern boolean_T MeAP_b_VehCndSts;     /* '<S29>/Logical Operator8' */
extern uint32_T MeAP_cnt_StateDebugVar;/* '<S5>/AUTOPARK_StateMachine' */
extern uint32_T MeAP_cnt_TransDebugVar;/* '<S5>/AUTOPARK_StateMachine' */
extern TeAutoPark_e_AutoParkStatus MeAP_e_AutoParkStatus;/* '<S5>/AUTOPARK_StateMachine' */
extern uint16_T MeAP_s_GearShiftReqWaitCnt;/* '<S5>/AUTOPARK_StateMachine' */
extern TeAP_e_AlgoState MeAutoPark_e_AlgoState;/* '<S5>/AUTOPARK_StateMachine' */

#ifndef SWC_AP_StateMachine_MDLREF_HIDE_CHILD_

extern MdlrefDW_SWC_AP_StateMachine_T SWC_AP_StateMachine_MdlrefDW;

#endif                                /*SWC_AP_StateMachine_MDLREF_HIDE_CHILD_*/

#ifndef SWC_AP_StateMachine_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_SWC_AP_StateMachine_c_T SWC_AP_StateMachine_B;

/* Block states (default storage) */
extern DW_SWC_AP_StateMachine_f_T SWC_AP_StateMachine_DW;

#endif                                /*SWC_AP_StateMachine_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'SWC_AP_StateMachine'
 * '<S1>'   : 'SWC_AP_StateMachine/Enumerated Constant'
 * '<S2>'   : 'SWC_AP_StateMachine/Model Info'
 * '<S3>'   : 'SWC_AP_StateMachine/SWC_AP_StateMachine'
 * '<S4>'   : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits'
 * '<S5>'   : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_Statemachine'
 * '<S6>'   : 'SWC_AP_StateMachine/SWC_AP_StateMachine/CANDebugSignal'
 * '<S7>'   : 'SWC_AP_StateMachine/SWC_AP_StateMachine/Enumerated Constant20'
 * '<S8>'   : 'SWC_AP_StateMachine/SWC_AP_StateMachine/FPA_InputProcessing'
 * '<S9>'   : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes'
 * '<S10>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing'
 * '<S11>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/APA_EnablingCondition'
 * '<S12>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition'
 * '<S13>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_StartAndStopInteraction'
 * '<S14>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortCondition'
 * '<S15>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck'
 * '<S16>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/USS_SensorStatus'
 * '<S17>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/APA_EnablingCondition/PAM2BTSwtStatusUpdate'
 * '<S18>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/APA_EnablingCondition/PAM2BTSwtStatusUpdate/FPASwtStuckStatusUpdate'
 * '<S19>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/APA_EnablingCondition/PAM2BTSwtStatusUpdate/RPASwtStuckStatusUpdate'
 * '<S20>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/APA_EnablingCondition/PAM2BTSwtStatusUpdate/FPASwtStuckStatusUpdate/Enumerated Constant1'
 * '<S21>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/APA_EnablingCondition/PAM2BTSwtStatusUpdate/FPASwtStuckStatusUpdate/Enumerated Constant7'
 * '<S22>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/APA_EnablingCondition/PAM2BTSwtStatusUpdate/FPASwtStuckStatusUpdate/FallingEdge'
 * '<S23>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/APA_EnablingCondition/PAM2BTSwtStatusUpdate/FPASwtStuckStatusUpdate/OffTimer'
 * '<S24>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/APA_EnablingCondition/PAM2BTSwtStatusUpdate/RPASwtStuckStatusUpdate/Enumerated Constant1'
 * '<S25>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/APA_EnablingCondition/PAM2BTSwtStatusUpdate/RPASwtStuckStatusUpdate/Enumerated Constant7'
 * '<S26>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/APA_EnablingCondition/PAM2BTSwtStatusUpdate/RPASwtStuckStatusUpdate/FallingEdge'
 * '<S27>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/APA_EnablingCondition/PAM2BTSwtStatusUpdate/RPASwtStuckStatusUpdate/OffTimer'
 * '<S28>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable'
 * '<S29>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_VehicleConditions'
 * '<S30>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/BSMHandshakeActvCon'
 * '<S31>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/DriverOverride'
 * '<S32>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/EPSHandshakeActvCon'
 * '<S33>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/RmvHandsFeetConSucs'
 * '<S34>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/AutoParkEnblSwtStuckStatusUpdate'
 * '<S35>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/Enumerated Constant'
 * '<S36>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/Enumerated Constant10'
 * '<S37>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/Enumerated Constant11'
 * '<S38>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/Enumerated Constant2'
 * '<S39>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/Enumerated Constant3'
 * '<S40>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/Enumerated Constant4'
 * '<S41>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/Enumerated Constant5'
 * '<S42>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/Enumerated Constant6'
 * '<S43>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/Enumerated Constant7'
 * '<S44>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/Enumerated Constant8'
 * '<S45>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/Enumerated Constant9'
 * '<S46>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/FallingEdge'
 * '<S47>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/OffTimer'
 * '<S48>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/RisingEdgeTrigger'
 * '<S49>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/Subsystem'
 * '<S50>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_FeatureEnable/AutoParkEnblSwtStuckStatusUpdate/Chart1'
 * '<S51>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_VehicleConditions/Enumerated Constant'
 * '<S52>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/AP_VehicleConditions/Enumerated Constant1'
 * '<S53>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/BSMHandshakeActvCon/Enumerated Constant'
 * '<S54>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/BSMHandshakeActvCon/Enumerated Constant1'
 * '<S55>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/BSMHandshakeActvCon/Enumerated Constant2'
 * '<S56>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/BSMHandshakeActvCon/Enumerated Constant3'
 * '<S57>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/BSMHandshakeActvCon/Enumerated Constant4'
 * '<S58>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/DriverOverride/Enumerated Constant'
 * '<S59>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/DriverOverride/Enumerated Constant1'
 * '<S60>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/DriverOverride/Enumerated Constant2'
 * '<S61>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/DriverOverride/Enumerated Constant3'
 * '<S62>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/DriverOverride/Enumerated Constant4'
 * '<S63>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/DriverOverride/Enumerated Constant5'
 * '<S64>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/DriverOverride/GearRptStateUpdate'
 * '<S65>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/DriverOverride/OnTimer'
 * '<S66>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AP_EnablingCondition/RmvHandsFeetConSucs/Enumerated Constant'
 * '<S67>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant'
 * '<S68>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant1'
 * '<S69>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant10'
 * '<S70>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant11'
 * '<S71>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant12'
 * '<S72>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant13'
 * '<S73>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant14'
 * '<S74>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant15'
 * '<S75>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant16'
 * '<S76>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant17'
 * '<S77>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant18'
 * '<S78>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant19'
 * '<S79>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant2'
 * '<S80>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant20'
 * '<S81>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant21'
 * '<S82>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant22'
 * '<S83>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant23'
 * '<S84>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant25'
 * '<S85>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant27'
 * '<S86>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant28'
 * '<S87>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant29'
 * '<S88>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant3'
 * '<S89>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant30'
 * '<S90>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant31'
 * '<S91>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant32'
 * '<S92>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant33'
 * '<S93>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant34'
 * '<S94>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant35'
 * '<S95>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant36'
 * '<S96>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant37'
 * '<S97>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant38'
 * '<S98>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant39'
 * '<S99>'  : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant4'
 * '<S100>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant40'
 * '<S101>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant41'
 * '<S102>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant42'
 * '<S103>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant5'
 * '<S104>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant6'
 * '<S105>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant7'
 * '<S106>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant8'
 * '<S107>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/AbortConditionCheck/Enumerated Constant9'
 * '<S108>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/USS_SensorStatus/SnsrStatusUpdate'
 * '<S109>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/USS_SensorStatus/SnsrStatusUpdate/FrntSnsrStatusUpdate'
 * '<S110>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/USS_SensorStatus/SnsrStatusUpdate/RearSnsrStatusUpdate'
 * '<S111>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/USS_SensorStatus/SnsrStatusUpdate/FrntSnsrStatusUpdate/Enumerated Constant'
 * '<S112>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/USS_SensorStatus/SnsrStatusUpdate/FrntSnsrStatusUpdate/Enumerated Constant1'
 * '<S113>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/USS_SensorStatus/SnsrStatusUpdate/FrntSnsrStatusUpdate/Enumerated Constant2'
 * '<S114>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/USS_SensorStatus/SnsrStatusUpdate/FrntSnsrStatusUpdate/Enumerated Constant3'
 * '<S115>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/USS_SensorStatus/SnsrStatusUpdate/RearSnsrStatusUpdate/Enumerated Constant'
 * '<S116>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/USS_SensorStatus/SnsrStatusUpdate/RearSnsrStatusUpdate/Enumerated Constant1'
 * '<S117>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/USS_SensorStatus/SnsrStatusUpdate/RearSnsrStatusUpdate/Enumerated Constant2'
 * '<S118>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_PreRequisits/USS_SensorStatus/SnsrStatusUpdate/RearSnsrStatusUpdate/Enumerated Constant3'
 * '<S119>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/AP_Statemachine/AUTOPARK_StateMachine'
 * '<S120>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/FPA_InputProcessing/Enumerated Constant1'
 * '<S121>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/FPA_InputProcessing/Enumerated Constant10'
 * '<S122>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/FPA_InputProcessing/Enumerated Constant11'
 * '<S123>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/FPA_InputProcessing/Enumerated Constant12'
 * '<S124>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/FPA_InputProcessing/Enumerated Constant2'
 * '<S125>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/FPA_InputProcessing/Enumerated Constant3'
 * '<S126>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/FPA_InputProcessing/Enumerated Constant4'
 * '<S127>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/FPA_InputProcessing/Enumerated Constant5'
 * '<S128>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/FPA_InputProcessing/Enumerated Constant6'
 * '<S129>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/FPA_InputProcessing/Enumerated Constant7'
 * '<S130>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/FPA_InputProcessing/Enumerated Constant8'
 * '<S131>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/FPA_InputProcessing/Enumerated Constant9'
 * '<S132>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSFiringMode'
 * '<S133>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSReInit'
 * '<S134>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSupplyPwrStateCal'
 * '<S135>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal'
 * '<S136>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemStateCal'
 * '<S137>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSFiringMode/Enumerated Constant'
 * '<S138>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSFiringMode/Enumerated Constant1'
 * '<S139>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSFiringMode/Enumerated Constant2'
 * '<S140>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSFiringMode/Enumerated Constant27'
 * '<S141>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSFiringMode/Enumerated Constant3'
 * '<S142>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSFiringMode/Enumerated Constant4'
 * '<S143>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSFiringMode/Enumerated Constant5'
 * '<S144>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSReInit/Enumerated Constant1'
 * '<S145>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSReInit/Enumerated Constant2'
 * '<S146>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSReInit/Enumerated Constant20'
 * '<S147>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSReInit/Enumerated Constant21'
 * '<S148>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSReInit/Enumerated Constant22'
 * '<S149>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSReInit/Enumerated Constant23'
 * '<S150>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSReInit/Enumerated Constant3'
 * '<S151>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSReInit/Enumerated Constant4'
 * '<S152>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSReInit/Enumerated Constant5'
 * '<S153>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSReInit/Enumerated Constant6'
 * '<S154>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSReInit/Enumerated Constant7'
 * '<S155>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSReInit/Enumerated Constant8'
 * '<S156>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSupplyPwrStateCal/Enumerated Constant10'
 * '<S157>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSupplyPwrStateCal/Enumerated Constant11'
 * '<S158>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant'
 * '<S159>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant13'
 * '<S160>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant2'
 * '<S161>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant21'
 * '<S162>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant22'
 * '<S163>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant23'
 * '<S164>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant24'
 * '<S165>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant25'
 * '<S166>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant26'
 * '<S167>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant27'
 * '<S168>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant28'
 * '<S169>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant29'
 * '<S170>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant30'
 * '<S171>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant31'
 * '<S172>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant32'
 * '<S173>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant33'
 * '<S174>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant34'
 * '<S175>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant35'
 * '<S176>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant5'
 * '<S177>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant8'
 * '<S178>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemModeCal/Enumerated Constant9'
 * '<S179>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemStateCal/Enumerated Constant1'
 * '<S180>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemStateCal/Enumerated Constant19'
 * '<S181>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemStateCal/Enumerated Constant20'
 * '<S182>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/USSFiringModes/USSSystemStateCal/Enumerated Constant3'
 * '<S183>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/Compare To Constant'
 * '<S184>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ParkSpotType'
 * '<S185>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/PerpParkStyleSel'
 * '<S186>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ResetKM1'
 * '<S187>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/VC_ActiveStatus'
 * '<S188>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ParkSpotType/Enumerated Constant1'
 * '<S189>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ParkSpotType/Enumerated Constant10'
 * '<S190>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ParkSpotType/Enumerated Constant11'
 * '<S191>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ParkSpotType/Enumerated Constant12'
 * '<S192>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ParkSpotType/Enumerated Constant2'
 * '<S193>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ParkSpotType/Enumerated Constant3'
 * '<S194>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ParkSpotType/Enumerated Constant4'
 * '<S195>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ParkSpotType/Enumerated Constant5'
 * '<S196>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ParkSpotType/Enumerated Constant6'
 * '<S197>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ParkSpotType/Enumerated Constant7'
 * '<S198>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ParkSpotType/Enumerated Constant8'
 * '<S199>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ParkSpotType/Enumerated Constant9'
 * '<S200>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ResetKM1/Enumerated Constant1'
 * '<S201>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ResetKM1/Enumerated Constant10'
 * '<S202>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ResetKM1/Enumerated Constant11'
 * '<S203>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ResetKM1/Enumerated Constant12'
 * '<S204>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ResetKM1/Enumerated Constant16'
 * '<S205>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ResetKM1/Enumerated Constant17'
 * '<S206>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ResetKM1/Enumerated Constant2'
 * '<S207>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ResetKM1/Enumerated Constant3'
 * '<S208>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ResetKM1/Enumerated Constant4'
 * '<S209>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ResetKM1/Enumerated Constant5'
 * '<S210>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ResetKM1/Enumerated Constant6'
 * '<S211>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ResetKM1/Enumerated Constant7'
 * '<S212>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ResetKM1/Enumerated Constant8'
 * '<S213>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/ResetKM1/Enumerated Constant9'
 * '<S214>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/VC_ActiveStatus/Enumerated Constant'
 * '<S215>' : 'SWC_AP_StateMachine/SWC_AP_StateMachine/VC_InputPreProcessing/VC_ActiveStatus/Enumerated Constant1'
 */
#endif                                 /* RTW_HEADER_SWC_AP_StateMachine_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
