/*
 * File: TRSC_StateMachine.h
 *
 * Code generated for Simulink model 'TRSC_StateMachine'.
 *
 * Model version                  : 1.1744
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:51:14 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TRSC_StateMachine_h_
#define RTW_HEADER_TRSC_StateMachine_h_
#include <math.h>
#include <string.h>
#ifndef TRSC_StateMachine_COMMON_INCLUDES_
# define TRSC_StateMachine_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TRSC_StateMachine_COMMON_INCLUDES_ */

#include "TRSC_StateMachine_types.h"

/* Includes for objects with custom storage classes. */
#include "TRSC_CalibParams.h"

/* user code (top of header file) */
#include "SignalDef.h"

/* Block signals for model 'TRSC_StateMachine' */
#ifndef TRSC_StateMachine_MDLREF_HIDE_CHILD_

typedef struct {
  TbTRSCSmVc_TunParam_t SignalConversion;/* '<Root>/Signal Conversion' */
  uint32_T DataTypeConversion25;       /* '<S25>/Data Type Conversion25' */
  uint32_T DataTypeConversion;         /* '<S26>/Data Type Conversion' */
  uint32_T DataTypeConversion25_d;     /* '<S21>/Data Type Conversion25' */
  uint32_T DataTypeConversion_n;       /* '<S24>/Data Type Conversion' */
  uint32_T DataTypeConversion25_e;     /* '<S22>/Data Type Conversion25' */
  uint32_T BitwiseOR3;                 /* '<S30>/Bitwise OR3' */
  uint32_T BitwiseOR4;                 /* '<S30>/Bitwise OR4' */
  uint32_T BitwiseOR5;                 /* '<S30>/Bitwise OR5' */
  uint32_T BitwiseOR6;                 /* '<S30>/Bitwise OR6' */
  uint32_T BitwiseOR7;                 /* '<S30>/Bitwise OR7' */
  uint32_T BitwiseOR8;                 /* '<S30>/Bitwise OR8' */
  uint32_T BitwiseOR9;                 /* '<S30>/Bitwise OR9' */
  uint32_T BitwiseOR10;                /* '<S30>/Bitwise OR10' */
  uint32_T BitwiseOR2;                 /* '<S30>/Bitwise OR2' */
  uint32_T Switch8;                    /* '<S28>/Switch8' */
  uint32_T BitwiseOR2_p;               /* '<S28>/Bitwise OR2' */
  uint32_T Switch6;                    /* '<S28>/Switch6' */
  uint32_T Switch5;                    /* '<S28>/Switch5' */
  uint32_T Switch4;                    /* '<S28>/Switch4' */
  uint32_T Switch3;                    /* '<S28>/Switch3' */
  uint32_T Switch2;                    /* '<S28>/Switch2' */
  uint32_T Switch9;                    /* '<S28>/Switch9' */
  uint32_T Switch1;                    /* '<S28>/Switch1' */
  uint32_T DataTypeConversion30;       /* '<S2>/Data Type Conversion30' */
  uint32_T Switch7;                    /* '<S28>/Switch7' */
  real32_T DataTypeConversion26;       /* '<S2>/Data Type Conversion26' */
  real32_T Gain7;                      /* '<Root>/Gain7' */
  real32_T Delay2;                     /* '<S2>/Delay2' */
  real32_T Product3;                   /* '<S2>/Product3' */
  real32_T Switch_TAD_des_Final1;      /* '<S2>/Switch_TAD_des_Final1' */
  real32_T deltafalllimit;             /* '<S17>/delta fall limit' */
  real32_T Yk1;                        /* '<S17>/Delay Input2' */
  real32_T UkYk1;                      /* '<S17>/Difference Inputs1' */
  real32_T Switch;                     /* '<S38>/Switch' */
  real32_T deltariselimit;             /* '<S17>/delta rise limit' */
  real32_T Switch2_n;                  /* '<S38>/Switch2' */
  real32_T DifferenceInputs2;          /* '<S17>/Difference Inputs2' */
  real32_T TrqCMD;                     /* '<S2>/Switch3' */
  real32_T Switch1_a;                  /* '<S127>/Switch1' */
  real32_T MinMax;                     /* '<S127>/MinMax' */
  real32_T MinMax_c;                   /* '<S34>/MinMax' */
  real32_T Switch_b;                   /* '<S20>/Switch' */
  real32_T Switch1_j;                  /* '<S20>/Switch1' */
  real32_T Switch2_f;                  /* '<S20>/Switch2' */
  real32_T Switch3_j;                  /* '<S20>/Switch3' */
  real32_T Switch4_d;                  /* '<S20>/Switch4' */
  real32_T Switch5_p;                  /* '<S20>/Switch5' */
  real32_T MinMax_h;                   /* '<S37>/MinMax' */
  real32_T MinMax_f;                   /* '<S36>/MinMax' */
  real32_T IeTRSC_pct_TRSCStrDmp_b;    /* '<S2>/Chart' */
  real32_T IeTRSC_M_TRSCStrTrq_n;      /* '<S2>/Chart' */
  real32_T MeTRSC_b_MoreCamSoftButtEnbl_o;/* '<S2>/Chart' */
  real32_T Product2;                   /* '<S2>/Product2' */
  real32_T sampletime;                 /* '<S17>/sample time' */
  real32_T Gain;                       /* '<S127>/Gain' */
  real32_T Sum1;                       /* '<S127>/Sum1' */
  real32_T DataTypeConversion28;       /* '<S2>/Data Type Conversion28' */
  real32_T Switch3_k;                  /* '<S36>/Switch3' */
  real32_T Abs2;                       /* '<S2>/Abs2' */
  real32_T Gain7_c;                    /* '<S2>/Gain7' */
  real32_T Sum;                        /* '<S36>/Sum' */
  real32_T Gain_e;                     /* '<S37>/Gain' */
  real32_T Sum_k;                      /* '<S34>/Sum' */
  real32_T Switch3_i;                  /* '<S34>/Switch3' */
  TeVBII_e_TrscEnblBtnSts Switch_d;    /* '<S19>/Switch' */
  TeTRSC_e_VehStpReq IeTRSC_e_VehStpReq_i;/* '<S2>/Chart' */
  TeTRSC_e_TrlrPrsntInfo Switch3_kh;   /* '<S18>/Switch3' */
  TeTRSC_e_TrlrHitchLightCtrl IeTRSC_e_TrlrHitchLightCtrl_e;/* '<S2>/Chart' */
  TeTRSC_e_TrlrCalInfo MeTRSC_e_SmTrlrCalInfo;/* '<S2>/Chart' */
  TeTRSC_e_TRSKMSts UnitDelay;         /* '<S33>/Unit Delay' */
  TeTRSC_e_TRSKMSts Switch_j;          /* '<S33>/Switch' */
  TeTRSC_e_TRSKMSts Switch1_b;         /* '<S33>/Switch1' */
  TeTRSC_e_TRSCUnavailReas_DID Switch12;/* '<S32>/Switch12' */
  TeTRSC_e_TRSCUnavailReas_DID Switch13;/* '<S32>/Switch13' */
  TeTRSC_e_TRSCUnavailReas_DID Switch14;/* '<S32>/Switch14' */
  TeTRSC_e_TRSCUnavailReas_DID Switch1_az;/* '<S32>/Switch1' */
  TeTRSC_e_TRSCUnavailReas_DID Switch20;/* '<S32>/Switch20' */
  TeTRSC_e_TRSCUnavailReas_DID Switch21;/* '<S32>/Switch21' */
  TeTRSC_e_TRSCUnavailReas_DID Switch22;/* '<S32>/Switch22' */
  TeTRSC_e_TRSCUnavailReas_DID Switch7_e;/* '<S32>/Switch7' */
  TeTRSC_e_TRSCUnavailReas_DID Switch23;/* '<S32>/Switch23' */
  TeTRSC_e_TRSCUnavailReas_DID Switch4_m;/* '<S32>/Switch4' */
  TeTRSC_e_TRSCUnavailReas_DID Switch27;/* '<S32>/Switch27' */
  TeTRSC_e_TRSCUnavailReas_DID Switch6_n;/* '<S32>/Switch6' */
  TeTRSC_e_TRSCUnavailReas_DID Switch11;/* '<S32>/Switch11' */
  TeTRSC_e_TRSCSts IeTRSC_e_TRSCSts_i; /* '<S2>/Chart' */
  TeTRSC_e_TRSCStrTrqActvReq IeTRSC_e_TRSCStrTrqActvReq_i;/* '<S2>/Chart' */
  TeTRSC_e_TRSCStrTrqActvReq TrqCMD_g; /* '<S2>/Switch2' */
  TeTRSC_e_TRSCStrTrqActvReq TrqCMD_gb;/* '<S2>/Switch1' */
  TeTRSC_e_TRSCStat MeTRSC_e_TRSCStat_p;/* '<S2>/Chart' */
  TeTRSC_e_TRSCPopupDispInfo IeTRSC_e_TRSCPopupDispInfo_e;/* '<S2>/Chart' */
  TeTRSC_e_TRSCPopupDispInfo IeTRSC_e_TRSCPopupDispInfoHld;/* '<S2>/Chart' */
  TeTRSC_e_TRSCLedSts IeTRSC_e_TRSCLedSts_b;/* '<S2>/Chart' */
  TeTRSC_e_TRSCAbortReason_DID Switch12_i;/* '<S29>/Switch12' */
  TeTRSC_e_TRSCAbortReason_DID Switch13_c;/* '<S29>/Switch13' */
  TeTRSC_e_TRSCAbortReason_DID Switch14_n;/* '<S29>/Switch14' */
  TeTRSC_e_TRSCAbortReason_DID Switch1_i;/* '<S29>/Switch1' */
  TeTRSC_e_TRSCAbortReason_DID Switch17;/* '<S29>/Switch17' */
  TeTRSC_e_TRSCAbortReason_DID Switch19;/* '<S29>/Switch19' */
  TeTRSC_e_TRSCAbortReason_DID Switch20_m;/* '<S29>/Switch20' */
  TeTRSC_e_TRSCAbortReason_DID Switch21_j;/* '<S29>/Switch21' */
  TeTRSC_e_TRSCAbortReason_DID Switch22_i;/* '<S29>/Switch22' */
  TeTRSC_e_TRSCAbortReason_DID Switch23_o;/* '<S29>/Switch23' */
  TeTRSC_e_TRSCAbortReason_DID Switch4_h;/* '<S29>/Switch4' */
  TeTRSC_e_TRSCAbortReason_DID Switch5_f;/* '<S29>/Switch5' */
  TeTRSC_e_TRSCAbortReason_DID Switch6_h;/* '<S29>/Switch6' */
  TeTRSC_e_TRSCAbortReason_DID Switch7_f;/* '<S29>/Switch7' */
  TeTRSC_e_TRSCAbortReason_DID Switch26;/* '<S29>/Switch26' */
  TeTRSC_e_TRSCAbortReason_DID Switch27_h;/* '<S29>/Switch27' */
  TeTRSC_e_TRSCAbortReason_DID Switch11_i;/* '<S29>/Switch11' */
  TeTRSC_e_TADAngActSign Switch1_g;    /* '<S27>/Switch1' */
  TeTRSC_e_TADAngActSign Switch2_c;    /* '<S27>/Switch2' */
  TeTRSC_e_TADAngActSign Switch_b0;    /* '<S27>/Switch' */
  TeTRSC_e_SpdLmtReq IeTRSC_e_SpdLmtReq_k;/* '<S2>/Chart' */
  uint16_T DataTypeConversion_a;       /* '<S33>/Data Type Conversion' */
  uint8_T DataTypeConversion25_a;      /* '<S2>/Data Type Conversion25' */
  uint8_T MeTRSC_e_CamBlockSts;        /* '<S2>/Data Type Conversion' */
  uint8_T IeVBII_e_CustTrlrType;       /* '<S2>/Data Type Conversion24' */
  uint8_T max_val;                     /* '<S14>/MATLAB Function2' */
  uint8_T buffer_out[100];             /* '<S14>/MATLAB Function2' */
  uint8_T UnitDelay_h;                 /* '<S2>/Unit Delay' */
  boolean_T DelayOneStep2;             /* '<S2>/Delay One Step2' */
  boolean_T AND1;                      /* '<S2>/AND1' */
  boolean_T RelationalOperator;        /* '<S3>/Relational Operator' */
  boolean_T LogicalOperator;           /* '<S3>/Logical Operator' */
  boolean_T Switch5_o;                 /* '<S2>/Switch5' */
  boolean_T RelationalOperator_g;      /* '<S2>/Relational Operator' */
  boolean_T RelationalOperator_l;      /* '<S34>/Relational Operator' */
  boolean_T RelationalOperator3;       /* '<S2>/Relational Operator3' */
  boolean_T DelayOneStep3;             /* '<S2>/Delay One Step3' */
  boolean_T Compare;                   /* '<S6>/Compare' */
  boolean_T Compare_n;                 /* '<S12>/Compare' */
  boolean_T RelationalOperator2;       /* '<S27>/Relational Operator2' */
  boolean_T RelationalOperator_f;      /* '<S37>/Relational Operator' */
  boolean_T StrTchDctc;                /* '<S2>/Chart3' */
  boolean_T IeTRSC_b_MoreCamReqSts_f;  /* '<S2>/Chart' */
  boolean_T MeTRSC_b_TRSCBtnSts;       /* '<S2>/Chart' */
  boolean_T MeTRSC_b_TrlrRevSteeringStsInfo_f;/* '<S2>/Chart' */
  boolean_T MeTRSC_b_DriverOverride;   /* '<S2>/Chart' */
  boolean_T MeTRSC_b_TrlrCalibPopInfo_i;/* '<S2>/Chart' */
  boolean_T LogicalOperator7;          /* '<S2>/Logical Operator7' */
  boolean_T Compare_f;                 /* '<S165>/Compare' */
  boolean_T Compare_g;                 /* '<S138>/Compare' */
  boolean_T Compare_b;                 /* '<S139>/Compare' */
  boolean_T Compare_a;                 /* '<S140>/Compare' */
  boolean_T Compare_az;                /* '<S136>/Compare' */
  boolean_T Compare_fv;                /* '<S142>/Compare' */
  boolean_T Compare_bb;                /* '<S143>/Compare' */
  boolean_T Compare_o;                 /* '<S144>/Compare' */
  boolean_T Compare_gn;                /* '<S147>/Compare' */
  boolean_T Compare_ff;                /* '<S141>/Compare' */
  boolean_T Compare_k;                 /* '<S145>/Compare' */
  boolean_T Compare_m;                 /* '<S146>/Compare' */
  boolean_T Compare_o2;                /* '<S96>/Compare' */
  boolean_T Compare_h;                 /* '<S97>/Compare' */
  boolean_T Compare_c;                 /* '<S98>/Compare' */
  boolean_T Compare_j;                 /* '<S94>/Compare' */
  boolean_T Compare_gk;                /* '<S99>/Compare' */
  boolean_T Compare_l;                 /* '<S100>/Compare' */
  boolean_T Compare_hq;                /* '<S102>/Compare' */
  boolean_T Compare_mz;                /* '<S103>/Compare' */
  boolean_T Compare_i;                 /* '<S104>/Compare' */
  boolean_T RelationalOperator_b;      /* '<S127>/Relational Operator' */
  boolean_T Compare_nc;                /* '<S108>/Compare' */
  boolean_T Compare_p;                 /* '<S105>/Compare' */
  boolean_T Compare_ig;                /* '<S106>/Compare' */
  boolean_T RelationalOperator1;       /* '<S27>/Relational Operator1' */
  boolean_T RelationalOperator_i;      /* '<S20>/Relational Operator' */
  boolean_T RelationalOperator1_g;     /* '<S20>/Relational Operator1' */
  boolean_T RelationalOperator2_h;     /* '<S20>/Relational Operator2' */
  boolean_T RelationalOperator3_g;     /* '<S20>/Relational Operator3' */
  boolean_T RelationalOperator4;       /* '<S20>/Relational Operator4' */
  boolean_T RelationalOperator5;       /* '<S20>/Relational Operator5' */
  boolean_T RelationalOperator1_e;     /* '<S2>/Relational Operator1' */
  boolean_T LogicalOperator1;          /* '<S33>/Logical Operator1' */
  boolean_T LogicalOperator1_a;        /* '<S27>/Logical Operator1' */
  boolean_T LogicalOperator_h;         /* '<S2>/Logical Operator' */
  boolean_T LogicalOperator_k;         /* '<S33>/Logical Operator' */
  boolean_T LogicalOperator3;          /* '<S2>/Logical Operator3' */
  boolean_T LogicalOperator_m;         /* '<S27>/Logical Operator' */
  boolean_T RelationalOperator_lc;     /* '<S27>/Relational Operator' */
} B_TRSC_StateMachine_c_T;

#endif                                 /*TRSC_StateMachine_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'TRSC_StateMachine' */
#ifndef TRSC_StateMachine_MDLREF_HIDE_CHILD_

typedef struct {
  real_T MeTRSC_s_VehOverSpdTmr;       /* '<S2>/Chart' */
  real_T MeTRSC_s_Disp22Tmr8Sec;       /* '<S2>/Chart' */
  real_T MeTRSC_s_Disp19Tmr2Sec;       /* '<S2>/Chart' */
  real32_T Delay2_DSTATE[255];         /* '<S2>/Delay2' */
  real32_T UnitDelay3_DSTATE;          /* '<S34>/UnitDelay3' */
  real32_T DelayInput2_DSTATE;         /* '<S17>/Delay Input2' */
  real32_T UnitDelay3_DSTATE_m;        /* '<S127>/UnitDelay3' */
  real32_T UnitDelay3_DSTATE_a;        /* '<S36>/UnitDelay3' */
  real32_T UnitDelay3_DSTATE_my;       /* '<S37>/UnitDelay3' */
  uint32_T UnitDelay_DSTATE;           /* '<S3>/Unit Delay' */
  TeTRSC_e_TRSKMSts UnitDelay_DSTATE_j;/* '<S33>/Unit Delay' */
  real32_T t;                          /* '<S2>/Chart3' */
  real32_T MeTRSC_s_LedTmr;            /* '<S2>/Chart' */
  real32_T MeTRSC_s_Timer2;            /* '<S2>/Chart' */
  real32_T MeTRSC_s_Timer3;            /* '<S2>/Chart' */
  real32_T MeTRSC_s_CalibLedTmr;       /* '<S2>/Chart' */
  real32_T MeTRSC_s_RevGearDbncTmr;    /* '<S2>/Chart' */
  real32_T MeTRSC_s_EpsRespDbncTmr;    /* '<S2>/Chart' */
  real32_T MeTRSC_s_TrlrHitchLightCtrlTimer;/* '<S2>/Chart' */
  real32_T MeTRSC_s_ParkGearDbncTmr;   /* '<S2>/Chart' */
  real32_T MeTRSC_s_LedTmr10Sec;       /* '<S2>/Chart' */
  real32_T MeTRSC_s_Disp10HldTmr;      /* '<S2>/Chart' */
  real32_T MeTRSC_s_Disp11HldTmr;      /* '<S2>/Chart' */
  real32_T MeTRSC_s_Disp12HldTmr;      /* '<S2>/Chart' */
  real32_T MeTRSC_s_Disp13HldTmr;      /* '<S2>/Chart' */
  real32_T MeTRSC_s_Disp5HldTmr;       /* '<S2>/Chart' */
  real32_T MeTRSC_s_Disp6HldTmr;       /* '<S2>/Chart' */
  real32_T MeTRSC_s_Disp7HldTmr;       /* '<S2>/Chart' */
  real32_T MeTRSC_s_Disp8HldTmr;       /* '<S2>/Chart' */
  real32_T MeTRSC_s_Disp9HldTmr;       /* '<S2>/Chart' */
  real32_T MeTRSC_s_SNAHldTmr;         /* '<S2>/Chart' */
  real32_T MeTRSC_s_Disp20HldTmr;      /* '<S2>/Chart' */
  real32_T MeTRSC_s_Disp22HldTmr;      /* '<S2>/Chart' */
  real32_T MeTRSC_s_Disp23HldTmr;      /* '<S2>/Chart' */
  real32_T MeTRSC_s_Disp19HldTmr;      /* '<S2>/Chart' */
  real32_T MeTRSC_s_Disp3HldTmr;       /* '<S2>/Chart' */
  real32_T MeTRSC_s_LedTmrBlink;       /* '<S2>/Chart' */
  uint32_T MeTRSC_cnt_SmTrlrCalibFailCntInfo;/* '<S2>/Chart' */
  TeVBII_e_TrscEnblBtnSts IeVBII_e_TrscEnblBtnSts_prev;/* '<S2>/Chart' */
  TeVBII_e_TrscEnblBtnSts IeVBII_e_TrscEnblBtnSts_start;/* '<S2>/Chart' */
  TeVBII_e_EnblBtnSts IeVBII_e_EnblBtnSts_prev;/* '<S2>/Chart' */
  TeVBII_e_EnblBtnSts IeVBII_e_EnblBtnSts_start;/* '<S2>/Chart' */
  TeTRSC_e_TrlrPrsntInfo MeTRSC_e_SmTrlrPrsntInfo;/* '<S2>/Chart' */
  TeVBII_e_Direction MeTRSC_e_Direction;/* '<S2>/Chart' */
  TeTRSC_e_TRSCPopupDispInfo IeTRSC_e_TRSCPopupDispInfo_prev;/* '<S2>/Chart' */
  TeTRSC_e_TRSCPopupDispInfo IeTRSC_e_TRSCPopupDispInfo_start;/* '<S2>/Chart' */
  uint8_T UnitDelay_DSTATE_i;          /* '<S2>/Unit Delay' */
  boolean_T DelayOneStep2_DSTATE;      /* '<S2>/Delay One Step2' */
  boolean_T DelayOneStep1_DSTATE;      /* '<S2>/Delay One Step1' */
  boolean_T UnitDelay1_DSTATE;         /* '<S3>/Unit Delay1' */
  boolean_T DelayOneStep3_DSTATE;      /* '<S2>/Delay One Step3' */
  uint8_T buffer[100];                 /* '<S14>/MATLAB Function2' */
  uint8_T index;                       /* '<S14>/MATLAB Function2' */
  uint8_T is_active_c1_TRSC_StateMachine;/* '<S2>/Chart3' */
  uint8_T is_c1_TRSC_StateMachine;     /* '<S2>/Chart3' */
  uint8_T is_active_c3_TRSC_StateMachine;/* '<S2>/Chart' */
  uint8_T is_ButtonProcessor;          /* '<S2>/Chart' */
  uint8_T is_ClearPopupDispInfo;       /* '<S2>/Chart' */
  uint8_T is_MainStateMachine;         /* '<S2>/Chart' */
  uint8_T is_Calibration;              /* '<S2>/Chart' */
  uint8_T is_Calibration_Steps;        /* '<S2>/Chart' */
  uint8_T temporalCounter_i1;          /* '<S2>/Chart' */
  boolean_T buffer_not_empty;          /* '<S14>/MATLAB Function2' */
  boolean_T MeTRSC_b_ExitActvStat;     /* '<S2>/Chart' */
  boolean_T MeTRSC_b_EnblBtnStsPressed;/* '<S2>/Chart' */
  boolean_T MeTRSC_b_TrscEnblBtnStsPressed;/* '<S2>/Chart' */
  boolean_T MeTRSC_b_StrTrqCtrlActv;   /* '<S2>/Chart' */
  boolean_T MeTRSC_b_NoTrailer;        /* '<S2>/Chart' */
  boolean_T MeTRSC_b_Disp20ShownOnce;  /* '<S2>/Chart' */
  boolean_T MeTRSC_b_Disp23;           /* '<S2>/Chart' */
  boolean_T MeTRSC_b_MesgClearance;    /* '<S2>/Chart' */
  boolean_T OverSpeed_Check_MODE;      /* '<S2>/OverSpeed_Check' */
} DW_TRSC_StateMachine_f_T;

#endif                                 /*TRSC_StateMachine_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_StateMachine_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_TRSC_StateMachine_T {
  const char_T **errorStatus;
};

#endif                                 /*TRSC_StateMachine_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_StateMachine_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_TRSC_StateMachine_T rtm;
} MdlrefDW_TRSC_StateMachine_T;

#endif                                 /*TRSC_StateMachine_MDLREF_HIDE_CHILD_*/

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
extern uint32_T IeTRSC_e_TRSCAbortReas;/* '<S2>/Data Type Conversion21'
                                        * Decimal value shall be converted to binary to understand bit set or resetted for below values:

                                          DID Value for Abort/Cancellation Reason:
                                          No response or invalid from Engine Controller,
                                          No response or invalid from Brake Systems Module,
                                          No response or invalid from Electric Power steering Module,
                                          No response or invalid from Transmission Controller,
                                          No response or invalid from ORC Module,
                                          No response or invalid from Radio,
                                          Ignition not in RUN,
                                          Rear tailgate open,
                                          Engine status signal says engine OFF,
                                          Driver door Open,
                                          Exceed speed in forward direction above 25 MPH,
                                          Trailer image in Camera view - lost in the field of view,
                                          Driver steering override,
                                          No user feedback for 600 Sec,
                                          TRSC button pressed on the TRSKM or radio screen,
                                          No Response or invalid data received from TRSKM Knob module,
                                          CVADAS ECU supply Voltage lower or higher than operating range,
                                          Trailer Angle too steep,
                                          Vehicle Speed exceeds the speed requested by CVADAS module during the maneuver,
                                          Invalid Proxi Parameter(out of range)/Vehicle Configuration mismatch,
                                          Fail not present,
                                          SNA - When internal fault present and parameter not available
                                        */
extern uint32_T IeTRSC_e_TRSCUnavailReas;/* '<S2>/Data Type Conversion20'
                                          * Decimal value shall be converted to binary to understand bit set or resetted for below values:

                                            DID Value for TRSC Unavailable/ not able to engage TRSC Reason:
                                            No response or invalid from Engine Controller,
                                            No response or invalid from Brake Systems Module,
                                            No response or invalid from Electric Power steering Module,
                                            No response or invalid from Transmission Controller,
                                            No response or invalid from ORC Module,
                                            No response or invalid from Radio,
                                            Ignition not in RUN,
                                            Rear tailgate open,
                                            Engine status signal says engine OFF,
                                            Driver door Open,
                                            Vehicle not in 'P',
                                            Camera calibration is unknown,
                                            Trailer not detected by the system,
                                            Trailer Angle to the vehicle too steep to engage the TRSC feature,
                                            Trailer Calibration Failure,
                                            No Response or invalid data received from TRSKM Knob module,
                                            CVADAS ECU supply Voltage lower or higher than operating range,
                                            CVADAS ECU in plant mode,
                                            Invalid Proxi Parameter(out of range)/Vehicle Configuration mismatch,
                                            Fail not present,
                                            SNA - When internal fault present and parameter not available
                                          */
extern real32_T IeTRSC_M_TRSCStrTrq;   /* '<S2>/Data Type Conversion6'
                                        * TRSC steering torque overlay request  information
                                        */
extern real32_T IeTRSC_kph_SpdLmtReq_DID;/* '<S20>/Switch6'
                                          * Speed limit request DID
                                          */
extern real32_T IeTRSC_deg_TADAngAct;  /* '<S27>/Data Type Conversion1'
                                        * IeTRSC_deg_TADAngAct signal output from TRSC SM
                                        */
extern real32_T IeTRSC_pct_TRSCStrDmp; /* '<S2>/Data Type Conversion8'
                                        * TRSC Steering damping percentage
                                        */
extern real32_T IeTRSC_kph_VehSpeedVSOSig;/* '<S2>/Data Type Conversion19'
                                           * It is the average vehicle speed calculated
                                           */
extern TeVBII_e_GearEngagedForDsply IeTRSC_e_GearShiftSts;/* '<S2>/Data Type Conversion18'
                                                           * DID Value of Shifter Position status read from bus:
                                                             Initialize(0)
                                                             Gear1(1)
                                                             Gear2(2)
                                                             Gear3(3)
                                                             Gear4(4)
                                                             Gear5(5)
                                                             Gear6(6)
                                                             Gear7(7)
                                                             Gear8(8)
                                                             Gear9(9)
                                                             NotUsed1(10)
                                                             NotUsed2(11)
                                                             P(12)
                                                             N(13)
                                                             R(14)
                                                             D(15)
                                                             L(16)
                                                             M(17)
                                                             S(18)
                                                             SNA(31)
                                                           */
extern TeVBII_e_EnblBtnSts IeTRSC_e_TRSKMBtnSts;/* '<S2>/Data Type Conversion14'
                                                 * DID Value of TRSKM Button Status
                                                   NotPressed(0)
                                                   Pressed(1)
                                                   SNA(2)
                                                 */
extern TeVBII_e_CenterBtnSts IeTRSC_e_TRSKMCenBtnSts;/* '<S2>/Data Type Conversion16'
                                                      * DID Value of TRSKM Push to Center Button Status:
                                                        NotPressed(0)
                                                        Pressed(1)
                                                        SNA(2)
                                                      */
extern TeTRSC_e_VehStpReq_DID IeTRSC_e_VehStpReq_DID;/* '<S26>/Multiport Switch'
                                                      * TRSC break activation request DID
                                                      */
extern TeTRSC_e_VehStpReq IeTRSC_e_VehStpReq;/* '<S2>/Data Type Conversion2'
                                              * TRSC break activation request
                                              */
extern TeTRSC_e_TrlrPrsntInfo MeTRSC_e_TrlrPrsntInfoCAN;/* '<S18>/Data Type Conversion'
                                                         * MeTRSC_e_TrlrPrsntInfoCAN signal output from TRSC SM
                                                         */
extern TeTRSC_e_TrlrHitchLightCtrl IeTRSC_e_TrlrHitchLightCtrl;/* '<S2>/Data Type Conversion22'
                                                                * Trailer Hitch light Control when trailer is connected
                                                                */
extern TeTRSC_e_TrlrCalInfo IeTRSC_e_TrlrCalInfo;/* '<S2>/Data Type Conversion23'
                                                  * Trailer Calibration Information
                                                    0 -> Not Calibrated,
                                                    1 - >Calibrated
                                                    2 ->undefined
                                                  */
extern TeTRSC_e_TRSKMSts_DID IeTRSC_e_TRSKMSts_DID;/* '<S25>/Multiport Switch'
                                                    * DID Value of TRSKM Module status:
                                                      Enabled,
                                                      Not Enabled,
                                                      SNA - No confirmation received by TRSKM
                                                    */
extern TeTRSC_e_TRSKMSts IeTRSC_e_TRSKMSts;/* '<S2>/Data Type Conversion17'
                                            * DID Value of TRSKM Module status:
                                              Enabled,
                                              Not Enabled,
                                              SNA - No confirmation received by TRSKM
                                            */
extern TeTRSC_e_TRSKMCenBtnSts_DID IeTRSC_e_TRSKMCenBtnSts_DID;/* '<S22>/Multiport Switch'
                                                                * DID Value of TRSKM Push to Center Button Status:
                                                                  NotPressed(0)
                                                                  Pressed(1)
                                                                  SNA(2)
                                                                */
extern TeTRSC_e_TRSKMBtnSts_DID IeTRSC_e_TRSKMBtnSts_DID;/* '<S21>/Multiport Switch'
                                                          * DID Value of TRSKM Button Status
                                                            NotPressed(0)
                                                            Pressed(1)
                                                            SNA(2)
                                                          */
extern TeTRSC_e_TRSCUnavailReas_DID IeTRSC_e_TRSCUnavailReas_DID;/* '<S2>/Data Type Conversion32'
                                                                  * TRSC Unavailable reasons DID
                                                                  */
extern TeTRSC_e_TRSCSts IeTRSC_e_TRSCSts;/* '<S2>/Data Type Conversion5'
                                          * TRSC Status
                                          */
extern TeTRSC_e_TRSCStrTrqActvReq IeTRSC_e_TRSCStrTrqActvReq;/* '<S2>/Data Type Conversion7'
                                                              * TRSC steering torque overlay activation request
                                                              */
extern TeTRSC_e_TRSCStat MeTRSC_e_TRSCStat;/* '<S2>/Data Type Conversion10'
                                            * Internal Current State of TRSC feature
                                            */
extern TeTRSC_e_TRSCPopupDispInfo IeTRSC_e_TRSCPopupDispInfo;/* '<S2>/Data Type Conversion4'
                                                              * TRSC Cluster PopUp Request
                                                              */
extern TeTRSC_e_TRSCLedSts IeTRSC_e_TRSCLedSts;/* '<S2>/Data Type Conversion3'
                                                * TRSKM LED request
                                                */
extern TeTRSC_e_TRSCAbortReason_DID IeTRSC_e_TRSCAbortReas_DID;/* '<S2>/Data Type Conversion29'
                                                                * TRSC Abort reasons DID
                                                                */
extern TeTRSC_e_TADAngActSign IeTRSC_e_TADAngActSign;/* '<S27>/Data Type Conversion'
                                                      * IeTRSC_e_TADAngActSign signal output from TRSC SM
                                                      */
extern TeTRSC_e_SpdLmtReq IeTRSC_e_SpdLmtReq;/* '<S2>/Data Type Conversion1'
                                              * TRSC ECM Speed limit request
                                              */
extern TeTRSC_e_GraphicOverlay_Sts IeTRSC_e_GraphicOverlay_Sts;/* '<S23>/Switch17'
                                                                * Graphical Overlay DID
                                                                */
extern TeTRSC_e_GearShiftSts_DID IeTRSC_e_GearShiftSts_DID;/* '<S24>/Multiport Switch'
                                                            * Gear shift status DID
                                                            */
extern TeTRSC_e_DispView2_DID MeSVS_e_DispView2Info_DID;/* '<S2>/Data Type Conversion31'
                                                         * CVPM Display view2 status from HMI
                                                         */
extern uint16_T IeTRSC_cnt_KnobPos;    /* '<S2>/Data Type Conversion15'
                                        * DID Value of TRSKM Knob Position
                                        */
extern boolean_T MeTRSC_b_ExternalFault;/* '<S31>/Logical Operator1'
                                         * TRSC External Fault signal comprising following CAN  signals:

                                           1. m_QM_FID_TRSC_DISABLED
                                           2. m_QM_FID_TRSC_CAM_CAL_ABORT

                                         */
extern boolean_T MeTRSC_b_MoreCamSoftButtEnbl;/* '<S2>/Data Type Conversion11'
                                               * More Camera Enable Soft Button Input
                                               */
extern boolean_T MeTRSC_b_TRSCSwitchPressed;/* '<S2>/Data Type Conversion12' */
extern boolean_T MeTRSC_b_TrlrRevSteeringStsInfo;/* '<S2>/Data Type Conversion13' */
extern boolean_T MeTRSC_b_TrlrCalibPopInfo;/* '<S2>/Data Type Conversion27'
                                            * Trailer Calibration Popup information
                                            */
extern boolean_T IeTRSC_b_MoreCamReqSts;/* '<S2>/Data Type Conversion9'
                                         * Status of More Camera request Input from HMI SoftButton, ( 0 -> NotPressed, 1 -> Pressed)
                                         */
extern void TRSC_StateMachine_Init(void);
extern void TRSC_StateMachine_Disable(void);
extern void TRSC_StateMachine(const real32_T *rtu_MeTRSC_deg_JackKnifeAngle,
  const boolean_T *rtu_MeTRSC_b_StrTwitchComplete, const real32_T
  *rtu_MeTRSC_M_TRSCStrTrq, const TeTRSC_e_SpdLmtReq *rtu_MeTRSC_e_SpdLmtReq,
  const real32_T *rtu_MeTRSC_pct_TRSCStrDmp, const real32_T
  *rtu_MeTRSC_m_TrailerBeamLen);

/* Model reference registration function */
extern void TRSC_StateMachine_initialize(const char_T **rt_errorStatus);

#ifndef TRSC_StateMachine_MDLREF_HIDE_CHILD_

extern MdlrefDW_TRSC_StateMachine_T TRSC_StateMachine_MdlrefDW;

#endif                                 /*TRSC_StateMachine_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_StateMachine_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_TRSC_StateMachine_c_T TRSC_StateMachine_B;

/* Block states (default storage) */
extern DW_TRSC_StateMachine_f_T TRSC_StateMachine_DW;

#endif                                 /*TRSC_StateMachine_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'TRSC_StateMachine'
 * '<S1>'   : 'TRSC_StateMachine/Model Info'
 * '<S2>'   : 'TRSC_StateMachine/TRSC_StateLogic'
 * '<S3>'   : 'TRSC_StateMachine/TRSC_StateLogic/CalFailedFor2Samples'
 * '<S4>'   : 'TRSC_StateMachine/TRSC_StateLogic/Chart'
 * '<S5>'   : 'TRSC_StateMachine/TRSC_StateLogic/Chart3'
 * '<S6>'   : 'TRSC_StateMachine/TRSC_StateLogic/Compare To Constant'
 * '<S7>'   : 'TRSC_StateMachine/TRSC_StateLogic/Compare To Constant1'
 * '<S8>'   : 'TRSC_StateMachine/TRSC_StateLogic/Compare To Constant11'
 * '<S9>'   : 'TRSC_StateMachine/TRSC_StateLogic/Compare To Constant12'
 * '<S10>'  : 'TRSC_StateMachine/TRSC_StateLogic/Compare To Constant13'
 * '<S11>'  : 'TRSC_StateMachine/TRSC_StateLogic/Compare To Constant2'
 * '<S12>'  : 'TRSC_StateMachine/TRSC_StateLogic/Compare To Constant5'
 * '<S13>'  : 'TRSC_StateMachine/TRSC_StateLogic/Compare To Constant7'
 * '<S14>'  : 'TRSC_StateMachine/TRSC_StateLogic/Enabled Subsystem'
 * '<S15>'  : 'TRSC_StateMachine/TRSC_StateLogic/MaxStrAngle_Selection'
 * '<S16>'  : 'TRSC_StateMachine/TRSC_StateLogic/OverSpeed_Check'
 * '<S17>'  : 'TRSC_StateMachine/TRSC_StateLogic/Rate Limiter Dynamic1'
 * '<S18>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem'
 * '<S19>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem1'
 * '<S20>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem2'
 * '<S21>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem3'
 * '<S22>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem4'
 * '<S23>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem5'
 * '<S24>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem6'
 * '<S25>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem7'
 * '<S26>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem8'
 * '<S27>'  : 'TRSC_StateMachine/TRSC_StateLogic/TADAngAct_TADAngActSign'
 * '<S28>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas'
 * '<S29>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID'
 * '<S30>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCUnavailReas'
 * '<S31>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_ExternalFault'
 * '<S32>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID'
 * '<S33>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSKMSts'
 * '<S34>'  : 'TRSC_StateMachine/TRSC_StateLogic/Timer1'
 * '<S35>'  : 'TRSC_StateMachine/TRSC_StateLogic/Enabled Subsystem/MATLAB Function2'
 * '<S36>'  : 'TRSC_StateMachine/TRSC_StateLogic/OverSpeed_Check/Timer1'
 * '<S37>'  : 'TRSC_StateMachine/TRSC_StateLogic/OverSpeed_Check/Timer2'
 * '<S38>'  : 'TRSC_StateMachine/TRSC_StateLogic/Rate Limiter Dynamic1/Saturation Dynamic'
 * '<S39>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem/Enumerated Constant11'
 * '<S40>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem/Enumerated Constant12'
 * '<S41>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem/Enumerated Constant13'
 * '<S42>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem/Enumerated Constant14'
 * '<S43>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem1/Enumerated Constant'
 * '<S44>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem1/Enumerated Constant1'
 * '<S45>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem1/Enumerated Constant2'
 * '<S46>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem1/Enumerated Constant3'
 * '<S47>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem3/Enumerated Constant'
 * '<S48>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem3/Enumerated Constant1'
 * '<S49>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem3/Enumerated Constant2'
 * '<S50>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem3/Enumerated Constant3'
 * '<S51>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem4/Enumerated Constant'
 * '<S52>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem4/Enumerated Constant1'
 * '<S53>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem4/Enumerated Constant2'
 * '<S54>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem4/Enumerated Constant3'
 * '<S55>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem5/Compare To Constant17'
 * '<S56>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem5/Enumerated Constant1'
 * '<S57>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem5/Enumerated Constant4'
 * '<S58>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem6/Enumerated Constant'
 * '<S59>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem6/Enumerated Constant1'
 * '<S60>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem6/Enumerated Constant2'
 * '<S61>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem6/Enumerated Constant3'
 * '<S62>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem6/Enumerated Constant4'
 * '<S63>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem6/Enumerated Constant5'
 * '<S64>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem6/Enumerated Constant6'
 * '<S65>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem6/Enumerated Constant7'
 * '<S66>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem6/Enumerated Constant8'
 * '<S67>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem7/Enumerated Constant1'
 * '<S68>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem7/Enumerated Constant2'
 * '<S69>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem7/Enumerated Constant6'
 * '<S70>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem8/Enumerated Constant'
 * '<S71>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem8/Enumerated Constant1'
 * '<S72>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem8/Enumerated Constant2'
 * '<S73>'  : 'TRSC_StateMachine/TRSC_StateLogic/Subsystem8/Enumerated Constant3'
 * '<S74>'  : 'TRSC_StateMachine/TRSC_StateLogic/TADAngAct_TADAngActSign/Compare To Constant'
 * '<S75>'  : 'TRSC_StateMachine/TRSC_StateLogic/TADAngAct_TADAngActSign/Compare To Constant1'
 * '<S76>'  : 'TRSC_StateMachine/TRSC_StateLogic/TADAngAct_TADAngActSign/Enumerated Constant'
 * '<S77>'  : 'TRSC_StateMachine/TRSC_StateLogic/TADAngAct_TADAngActSign/Enumerated Constant1'
 * '<S78>'  : 'TRSC_StateMachine/TRSC_StateLogic/TADAngAct_TADAngActSign/Enumerated Constant2'
 * '<S79>'  : 'TRSC_StateMachine/TRSC_StateLogic/TADAngAct_TADAngActSign/Enumerated Constant3'
 * '<S80>'  : 'TRSC_StateMachine/TRSC_StateLogic/TADAngAct_TADAngActSign/Enumerated Constant4'
 * '<S81>'  : 'TRSC_StateMachine/TRSC_StateLogic/TADAngAct_TADAngActSign/Enumerated Constant5'
 * '<S82>'  : 'TRSC_StateMachine/TRSC_StateLogic/TADAngAct_TADAngActSign/Enumerated Constant6'
 * '<S83>'  : 'TRSC_StateMachine/TRSC_StateLogic/TADAngAct_TADAngActSign/Enumerated Constant7'
 * '<S84>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas/Compare To Constant1'
 * '<S85>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas/Compare To Constant10'
 * '<S86>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas/Compare To Constant2'
 * '<S87>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas/Compare To Constant3'
 * '<S88>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas/Compare To Constant4'
 * '<S89>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas/Compare To Constant5'
 * '<S90>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas/Compare To Constant6'
 * '<S91>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas/Compare To Constant7'
 * '<S92>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas/Compare To Constant8'
 * '<S93>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas/Compare To Constant9'
 * '<S94>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Compare To Constant1'
 * '<S95>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Compare To Constant11'
 * '<S96>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Compare To Constant12'
 * '<S97>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Compare To Constant13'
 * '<S98>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Compare To Constant14'
 * '<S99>'  : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Compare To Constant17'
 * '<S100>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Compare To Constant19'
 * '<S101>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Compare To Constant2'
 * '<S102>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Compare To Constant20'
 * '<S103>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Compare To Constant21'
 * '<S104>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Compare To Constant22'
 * '<S105>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Compare To Constant24'
 * '<S106>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Compare To Constant25'
 * '<S107>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Compare To Constant3'
 * '<S108>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Compare To Constant4'
 * '<S109>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant1'
 * '<S110>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant12'
 * '<S111>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant13'
 * '<S112>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant14'
 * '<S113>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant15'
 * '<S114>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant16'
 * '<S115>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant17'
 * '<S116>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant18'
 * '<S117>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant19'
 * '<S118>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant2'
 * '<S119>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant20'
 * '<S120>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant3'
 * '<S121>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant4'
 * '<S122>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant5'
 * '<S123>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant6'
 * '<S124>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant7'
 * '<S125>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant8'
 * '<S126>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Enumerated Constant9'
 * '<S127>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCAbortReas_DID/Timer1'
 * '<S128>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCUnavailReas/Compare To Constant1'
 * '<S129>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCUnavailReas/Compare To Constant2'
 * '<S130>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCUnavailReas/Compare To Constant3'
 * '<S131>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCUnavailReas/Compare To Constant4'
 * '<S132>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCUnavailReas/Compare To Constant5'
 * '<S133>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCUnavailReas/Compare To Constant6'
 * '<S134>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCUnavailReas/Compare To Constant7'
 * '<S135>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSCUnavailReas/Compare To Constant8'
 * '<S136>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Compare To Constant1'
 * '<S137>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Compare To Constant11'
 * '<S138>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Compare To Constant12'
 * '<S139>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Compare To Constant13'
 * '<S140>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Compare To Constant14'
 * '<S141>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Compare To Constant2'
 * '<S142>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Compare To Constant20'
 * '<S143>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Compare To Constant21'
 * '<S144>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Compare To Constant22'
 * '<S145>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Compare To Constant25'
 * '<S146>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Compare To Constant4'
 * '<S147>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Compare To Constant5'
 * '<S148>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Enumerated Constant1'
 * '<S149>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Enumerated Constant12'
 * '<S150>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Enumerated Constant13'
 * '<S151>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Enumerated Constant14'
 * '<S152>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Enumerated Constant16'
 * '<S153>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Enumerated Constant17'
 * '<S154>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Enumerated Constant19'
 * '<S155>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Enumerated Constant2'
 * '<S156>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Enumerated Constant20'
 * '<S157>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Enumerated Constant3'
 * '<S158>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Enumerated Constant4'
 * '<S159>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Enumerated Constant6'
 * '<S160>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Enumerated Constant8'
 * '<S161>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSC_e_TRSCUnavailReas_DID/Enumerated Constant9'
 * '<S162>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSKMSts/Compare To Constant'
 * '<S163>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSKMSts/Compare To Constant1'
 * '<S164>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSKMSts/Compare To Constant2'
 * '<S165>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSKMSts/Compare To Constant3'
 * '<S166>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSKMSts/Enumerated Constant'
 * '<S167>' : 'TRSC_StateMachine/TRSC_StateLogic/TRSKMSts/Enumerated Constant1'
 */
#endif                                 /* RTW_HEADER_TRSC_StateMachine_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
