/*
 * File: TRSC_InputAdapter.h
 *
 * Code generated for Simulink model 'TRSC_InputAdapter'.
 *
 * Model version                  : 1.125
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:50:30 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TRSC_InputAdapter_h_
#define RTW_HEADER_TRSC_InputAdapter_h_
#include <string.h>
#ifndef TRSC_InputAdapter_COMMON_INCLUDES_
# define TRSC_InputAdapter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TRSC_InputAdapter_COMMON_INCLUDES_ */

#include "TRSC_InputAdapter_types.h"

/* Includes for objects with custom storage classes. */
#include "TRSC_CalibParams.h"

/* user code (top of header file) */
#include "SignalDef.h"

/* Block signals for model 'TRSC_InputAdapter' */
#ifndef TRSC_InputAdapter_MDLREF_HIDE_CHILD_

typedef struct {
  TbTRSCSmVc_TunParam_t IbTRSCSmVc_TunParam;/* '<Root>/Bus Assignment' */
  real32_T DataTypeConversion186[37];  /* '<Root>/Data Type Conversion186' */
  real32_T DataTypeConversion187[37];  /* '<Root>/Data Type Conversion187' */
  real32_T DataTypeConversion189[8];   /* '<Root>/Data Type Conversion189' */
  real32_T DataTypeConversion190[8];   /* '<Root>/Data Type Conversion190' */
  real32_T DataTypeConversion167[4];   /* '<Root>/Data Type Conversion167' */
  real32_T DataTypeConversion152[3];   /* '<Root>/Data Type Conversion152' */
  real32_T DataTypeConversion153[3];   /* '<Root>/Data Type Conversion153' */
  real32_T DataTypeConversion154[3];   /* '<Root>/Data Type Conversion154' */
  real32_T DataTypeConversion169[3];   /* '<Root>/Data Type Conversion169' */
  real32_T DataTypeConversion170[3];   /* '<Root>/Data Type Conversion170' */
  real32_T DataTypeConversion175[3];   /* '<Root>/Data Type Conversion175' */
  real32_T DataTypeConversion176[3];   /* '<Root>/Data Type Conversion176' */
  real32_T DataTypeConversion178[3];   /* '<Root>/Data Type Conversion178' */
  real32_T DataTypeConversion184[3];   /* '<Root>/Data Type Conversion184' */
  real32_T DataTypeConversion203[3];   /* '<Root>/Data Type Conversion203' */
  real32_T DataTypeConversion168[2];   /* '<Root>/Data Type Conversion168' */
  real32_T DataTypeConversion171[2];   /* '<Root>/Data Type Conversion171' */
  real32_T DataTypeConversion172[2];   /* '<Root>/Data Type Conversion172' */
  real32_T DataTypeConversion174[2];   /* '<Root>/Data Type Conversion174' */
  real32_T DataTypeConversion179[2];   /* '<Root>/Data Type Conversion179' */
  real32_T DataTypeConversion180[2];   /* '<Root>/Data Type Conversion180' */
  real32_T DataTypeConversion181[2];   /* '<Root>/Data Type Conversion181' */
  real32_T DataTypeConversion182[2];   /* '<Root>/Data Type Conversion182' */
  real32_T DataTypeConversion183[2];   /* '<Root>/Data Type Conversion183' */
  real32_T DataTypeConversion185[2];   /* '<Root>/Data Type Conversion185' */
  real32_T DataTypeConversion149;      /* '<Root>/Data Type Conversion149' */
  real32_T DataTypeConversion150;      /* '<Root>/Data Type Conversion150' */
  real32_T DataTypeConversion151;      /* '<Root>/Data Type Conversion151' */
  real32_T DataTypeConversion155;      /* '<Root>/Data Type Conversion155' */
  real32_T DataTypeConversion156;      /* '<Root>/Data Type Conversion156' */
  real32_T DataTypeConversion157;      /* '<Root>/Data Type Conversion157' */
  real32_T DataTypeConversion158;      /* '<Root>/Data Type Conversion158' */
  real32_T DataTypeConversion159;      /* '<Root>/Data Type Conversion159' */
  real32_T DataTypeConversion160;      /* '<Root>/Data Type Conversion160' */
  real32_T DataTypeConversion161;      /* '<Root>/Data Type Conversion161' */
  real32_T DataTypeConversion162;      /* '<Root>/Data Type Conversion162' */
  real32_T DataTypeConversion163;      /* '<Root>/Data Type Conversion163' */
  real32_T DataTypeConversion164;      /* '<Root>/Data Type Conversion164' */
  real32_T DataTypeConversion165;      /* '<Root>/Data Type Conversion165' */
  real32_T DataTypeConversion166;      /* '<Root>/Data Type Conversion166' */
  real32_T DataTypeConversion173;      /* '<Root>/Data Type Conversion173' */
  real32_T DataTypeConversion177;      /* '<Root>/Data Type Conversion177' */
  real32_T DataTypeConversion188;      /* '<Root>/Data Type Conversion188' */
  real32_T DataTypeConversion191;      /* '<Root>/Data Type Conversion191' */
  real32_T DataTypeConversion192;      /* '<Root>/Data Type Conversion192' */
  real32_T DataTypeConversion193;      /* '<Root>/Data Type Conversion193' */
  real32_T DataTypeConversion194;      /* '<Root>/Data Type Conversion194' */
  real32_T DataTypeConversion195;      /* '<Root>/Data Type Conversion195' */
  real32_T DataTypeConversion196;      /* '<Root>/Data Type Conversion196' */
  real32_T DataTypeConversion197;      /* '<Root>/Data Type Conversion197' */
  real32_T DataTypeConversion198;      /* '<Root>/Data Type Conversion198' */
  real32_T DataTypeConversion199;      /* '<Root>/Data Type Conversion199' */
  real32_T DataTypeConversion200;      /* '<Root>/Data Type Conversion200' */
  real32_T DataTypeConversion201;      /* '<Root>/Data Type Conversion201' */
  real32_T DataTypeConversion202;      /* '<Root>/Data Type Conversion202' */
  real32_T DataTypeConversion204;      /* '<Root>/Data Type Conversion204' */
  real32_T DataTypeConversion205;      /* '<Root>/Data Type Conversion205' */
  real32_T DataTypeConversion206;      /* '<Root>/Data Type Conversion206' */
  real32_T DataTypeConversion207;      /* '<Root>/Data Type Conversion207' */
  real32_T DataTypeConversion208;      /* '<Root>/Data Type Conversion208' */
  real32_T DataTypeConversion209;      /* '<Root>/Data Type Conversion209' */
  real32_T DataTypeConversion210;      /* '<Root>/Data Type Conversion210' */
  real32_T DataTypeConversion211;      /* '<Root>/Data Type Conversion211' */
  real32_T DataTypeConversion212;      /* '<Root>/Data Type Conversion212' */
  real32_T DataTypeConversion213;      /* '<Root>/Data Type Conversion213' */
  real32_T DataTypeConversion216;      /* '<Root>/Data Type Conversion216' */
  real32_T DataTypeConversion217;      /* '<Root>/Data Type Conversion217' */
  real32_T DataTypeConversion218;      /* '<Root>/Data Type Conversion218' */
  real32_T DataTypeConversion219;      /* '<Root>/Data Type Conversion219' */
  real32_T DataTypeConversion220;      /* '<Root>/Data Type Conversion220' */
  real32_T DataTypeConversion221;      /* '<Root>/Data Type Conversion221' */
  real32_T DataTypeConversion222;      /* '<Root>/Data Type Conversion222' */
  real32_T DataTypeConversion223;      /* '<Root>/Data Type Conversion223' */
  real32_T DataTypeConversion224;      /* '<Root>/Data Type Conversion224' */
  real32_T DataTypeConversion5;        /* '<Root>/Data Type Conversion5' */
  real32_T DataTypeConversion4;        /* '<Root>/Data Type Conversion4' */
  real32_T DataTypeConversion3;        /* '<Root>/Data Type Conversion3' */
  real32_T IeVBII_M_StrWhlTrq;         /* '<Root>/Data Type Conversion30' */
  real32_T DataTypeConversion72;       /* '<Root>/Data Type Conversion72' */
  real32_T DataTypeConversion71;       /* '<Root>/Data Type Conversion71' */
  real32_T DataTypeConversion70;       /* '<Root>/Data Type Conversion70' */
  real32_T DataTypeConversion67;       /* '<Root>/Data Type Conversion67' */
  real32_T DataTypeConversion9;        /* '<Root>/Data Type Conversion9' */
  real32_T DataTypeConversion6;        /* '<Root>/Data Type Conversion6' */
  real32_T IePRX_m_VehTyreSize;        /* '<Root>/Data Type Conversion138' */
  TeVBII_e_ShiftLvrPos DataTypeConversion122;/* '<Root>/Data Type Conversion122' */
  TeVBII_e_GearEngagedForDsply DataTypeConversion103;/* '<Root>/Data Type Conversion103' */
  TeTRSC_e_TrlrRecogInfo DataTypeConversion64;/* '<Root>/Data Type Conversion64' */
  TeTRSC_e_TrlrPrsntInfo DataTypeConversion54;/* '<Root>/Data Type Conversion54' */
  TeTRSC_e_TrlrID DataTypeConversion78;/* '<Root>/Data Type Conversion78' */
  TeTRSC_e_TrlrCalInfo DataTypeConversion63;/* '<Root>/Data Type Conversion63' */
  TeTRSC_e_TADState DataTypeConversion73;/* '<Root>/Data Type Conversion73' */
  TeTRSC_e_DispView2 DataTypeConversion55;/* '<Root>/Data Type Conversion55' */
  TeTRSC_e_CalFail DataTypeConversion77;/* '<Root>/Data Type Conversion77' */
  uint16_T DataTypeConversion116;      /* '<Root>/Data Type Conversion116' */
  uint8_T DataTypeConversion;          /* '<S1>/Data Type Conversion' */
  uint8_T DataTypeConversion214;       /* '<Root>/Data Type Conversion214' */
  uint8_T DataTypeConversion215;       /* '<Root>/Data Type Conversion215' */
  uint8_t DataTypeConversion51;        /* '<Root>/Data Type Conversion51' */
  uint8_T DataTypeConversion7;         /* '<Root>/Data Type Conversion7' */
  boolean_T DataTypeConversion225;     /* '<Root>/Data Type Conversion225' */
  boolean_T IePRX_b_TrlrSurroundPresence;/* '<Root>/Data Type Conversion132' */
  boolean_T IePRX_b_AuxTrlrCam;        /* '<Root>/Data Type Conversion131' */
  boolean_T IePRX_b_SVSPresent;        /* '<Root>/Data Type Conversion130' */
  boolean_T IePRX_b_SRT;               /* '<Root>/Data Type Conversion129' */
  boolean_T IeDDC_b_TRSCLimASCMDef;    /* '<Root>/Data Type Conversion148' */
  boolean_T IeDDC_b_TRSCLimDefView;    /* '<Root>/Data Type Conversion146' */
  boolean_T IeDDC_b_TRSCLimView;       /* '<Root>/Data Type Conversion142' */
  boolean_T MeTRSC_b_InternalFault;    /* '<Root>/Data Type Conversion57' */
} B_TRSC_InputAdapter_c_T;

#endif                                 /*TRSC_InputAdapter_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_InputAdapter_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_TRSC_InputAdapter_T {
  const char_T **errorStatus;
};

#endif                                 /*TRSC_InputAdapter_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_InputAdapter_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_TRSC_InputAdapter_T rtm;
} MdlrefDW_TRSC_InputAdapter_T;

#endif                                 /*TRSC_InputAdapter_MDLREF_HIDE_CHILD_*/

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T MeTRSC_deg_TADAngleSMVC;/* '<Root>/Data Type Conversion66'
                                         * TAD Angle
                                         */
extern TeTRSC_e_TrlrCalInfo MeTRSC_e_TrlrCalInfoSMVC;/* '<Root>/Data Type Conversion110'
                                                      * Trailer Calibration Information
                                                        0 -> Not Calibrated,
                                                        1 - >Calibrated
                                                        2 ->undefined
                                                      */
extern void TRSC_InputAdapter(const TRSC_Inputs_from_TrailerDetection_t
  *rtu_IbTrailerDet_TrailerDetInpBus, const SVStoTRSC_t *rtu_IbSVS_SVStoTRSC,
  const ME_VehInp_FromCAN14_IpcSignals *rtu_IbTRSC_MEVehInpFromCAN14IpcSignals,
  const ME_VehInp_FromCAN2_IpcSignals *rtu_IbTRSC_MEVehInpFromCAN2IpcSignals,
  const ME_ProxiToMCU2_1_Def_t *rtu_IbTRSC_MEProxiToIpcSignals, const
  FID_STRUCT_QM *rtu_IbDDC_DegManagerDefSignals, const TbTRSCSmVc_TunParam_t
  *rtu_IbTRSCSmVc_TunParam, TbTRSC_InpBus *rty_IbTRSC_InpBus);

/* Model reference registration function */
extern void TRSC_InputAdapter_initialize(const char_T **rt_errorStatus);

#ifndef TRSC_InputAdapter_MDLREF_HIDE_CHILD_

extern MdlrefDW_TRSC_InputAdapter_T TRSC_InputAdapter_MdlrefDW;

#endif                                 /*TRSC_InputAdapter_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_InputAdapter_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_TRSC_InputAdapter_c_T TRSC_InputAdapter_B;

#endif                                 /*TRSC_InputAdapter_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'TRSC_InputAdapter'
 * '<S1>'   : 'TRSC_InputAdapter/ShiftLvrPos_to_GearEngagedForDisplay'
 * '<S2>'   : 'TRSC_InputAdapter/Subsystem2'
 * '<S3>'   : 'TRSC_InputAdapter/ShiftLvrPos_to_GearEngagedForDisplay/Enumerated Constant'
 * '<S4>'   : 'TRSC_InputAdapter/ShiftLvrPos_to_GearEngagedForDisplay/Enumerated Constant1'
 * '<S5>'   : 'TRSC_InputAdapter/ShiftLvrPos_to_GearEngagedForDisplay/Enumerated Constant2'
 * '<S6>'   : 'TRSC_InputAdapter/ShiftLvrPos_to_GearEngagedForDisplay/Enumerated Constant3'
 * '<S7>'   : 'TRSC_InputAdapter/ShiftLvrPos_to_GearEngagedForDisplay/Enumerated Constant4'
 * '<S8>'   : 'TRSC_InputAdapter/ShiftLvrPos_to_GearEngagedForDisplay/Enumerated Constant5'
 * '<S9>'   : 'TRSC_InputAdapter/ShiftLvrPos_to_GearEngagedForDisplay/Enumerated Constant6'
 * '<S10>'  : 'TRSC_InputAdapter/ShiftLvrPos_to_GearEngagedForDisplay/Enumerated Constant7'
 */
#endif                                 /* RTW_HEADER_TRSC_InputAdapter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
