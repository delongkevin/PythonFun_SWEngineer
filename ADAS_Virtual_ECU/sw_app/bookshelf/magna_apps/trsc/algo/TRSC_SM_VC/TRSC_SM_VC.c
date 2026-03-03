/*
 * File: TRSC_SM_VC.c
 *
 * Code generated for Simulink model 'TRSC_SM_VC'.
 *
 * Model version                  : 1.133
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:53:04 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "TRSC_SM_VC.h"
#include "TRSC_SM_VC_private.h"

/* Exported block signals */
real32_T MeTRSC_M_TRSCStrTrq;          /* '<Root>/TRSC_Vehicle_Control'
                                        * Steering Torque input from Vehicle Control
                                        */
real32_T MeTRSC_pct_TRSCStrDmp;        /* '<Root>/TRSC_Vehicle_Control'
                                        * Steering Damping command in %
                                        */
TeTRSC_e_TRSCStrTrqActvReq MeTRSC_e_TRSCStrTrqActvReq;/* '<Root>/TRSC_Vehicle_Control' */
boolean_T MeTRSC_b_StrTwitchComplete;  /* '<Root>/TRSC_Vehicle_Control'
                                        * Steering Twitch Complete Status
                                        */
MdlrefDW_TRSC_SM_VC_T TRSC_SM_VC_MdlrefDW;

/* Block signals (default storage) */
B_TRSC_SM_VC_c_T TRSC_SM_VC_B;

/* Block states (default storage) */
DW_TRSC_SM_VC_f_T TRSC_SM_VC_DW;

/* System initialize for referenced model: 'TRSC_SM_VC' */
void TRSC_SM_VC_Init(void)
{
  /* SystemInitialize for ModelReference: '<Root>/Model' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_Init();

  /* SystemInitialize for ModelReference: '<Root>/TRSC_Vehicle_Control' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_Init();
}

/* Disable for referenced model: 'TRSC_SM_VC' */
void TRSC_SM_VC_Disable(void)
{
  /* Disable for ModelReference: '<Root>/Model' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_Disable();

  /* Disable for ModelReference: '<Root>/TRSC_Vehicle_Control' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_Disable(&TRSC_SM_VC_B.TRSC_Vehicle_Control_o7);
}

/* Start for referenced model: 'TRSC_SM_VC' */
void TRSC_SM_VC_Start(void)
{
  /* Start for ModelReference: '<Root>/TRSC_Vehicle_Control' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC_Start();
}

/* Output and update for referenced model: 'TRSC_SM_VC' */
void TRSC_SM_VC(void)
{
  /* UnitDelay: '<Root>/Unit Delay4' */
  TRSC_SM_VC_B.MeTRSC_deg_JackKnifeAngle_m = TRSC_SM_VC_DW.UnitDelay4_DSTATE;

  /* UnitDelay: '<Root>/Unit Delay3' */
  TRSC_SM_VC_B.MeTRSC_b_StrTwitchComplete_o = TRSC_SM_VC_DW.UnitDelay3_DSTATE;

  /* UnitDelay: '<Root>/Unit Delay' */
  TRSC_SM_VC_B.MeTRSC_M_TRSCStrTrq_h = TRSC_SM_VC_DW.UnitDelay_DSTATE;

  /* UnitDelay: '<Root>/Unit Delay1' */
  TRSC_SM_VC_B.MeTRSC_e_SpdLmtReq = TRSC_SM_VC_DW.UnitDelay1_DSTATE;

  /* UnitDelay: '<Root>/Unit Delay2' */
  TRSC_SM_VC_B.MeTRSC_pct_TRSCStrDmp_k = TRSC_SM_VC_DW.UnitDelay2_DSTATE;

  /* UnitDelay: '<Root>/Unit Delay5' */
  TRSC_SM_VC_B.MeTRSC_m_TrailerBeamLen_l = TRSC_SM_VC_DW.UnitDelay5_DSTATE;

  /* ModelReference: '<Root>/Model' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine(&TRSC_SM_VC_B.MeTRSC_deg_JackKnifeAngle_m,
                    &TRSC_SM_VC_B.MeTRSC_b_StrTwitchComplete_o,
                    &TRSC_SM_VC_B.MeTRSC_M_TRSCStrTrq_h,
                    &TRSC_SM_VC_B.MeTRSC_e_SpdLmtReq,
                    &TRSC_SM_VC_B.MeTRSC_pct_TRSCStrDmp_k,
                    &TRSC_SM_VC_B.MeTRSC_m_TrailerBeamLen_l);

  /* ModelReference: '<Root>/TRSC_Vehicle_Control' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_VC(&MeTRSC_e_TRSCStat, &MeTRSC_e_TRSCStrTrqActvReq,
          &TRSC_SM_VC_B.TRSC_Vehicle_Control_o7);

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  TRSC_SM_VC_B.DataTypeConversion = MeTRSC_M_TRSCStrTrq;

  /* Update for UnitDelay: '<Root>/Unit Delay4' */
  TRSC_SM_VC_DW.UnitDelay4_DSTATE = MeTRSC_deg_JackKnifeAngle;

  /* Update for UnitDelay: '<Root>/Unit Delay3' */
  TRSC_SM_VC_DW.UnitDelay3_DSTATE = MeTRSC_b_StrTwitchComplete;

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  TRSC_SM_VC_DW.UnitDelay_DSTATE = TRSC_SM_VC_B.DataTypeConversion;

  /* Update for UnitDelay: '<Root>/Unit Delay1' */
  TRSC_SM_VC_DW.UnitDelay1_DSTATE = TRSC_SM_VC_B.TRSC_Vehicle_Control_o7;

  /* Update for UnitDelay: '<Root>/Unit Delay2' */
  TRSC_SM_VC_DW.UnitDelay2_DSTATE = MeTRSC_pct_TRSCStrDmp;

  /* Update for UnitDelay: '<Root>/Unit Delay5' */
  TRSC_SM_VC_DW.UnitDelay5_DSTATE = MeTRSC_m_TrailerBeamLen;
}

/* Model initialize function */
void TRSC_SM_VC_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_TRSC_SM_VC_T *const TRSC_SM_VC_M = &(TRSC_SM_VC_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(TRSC_SM_VC_M, rt_errorStatus);

  /* Model Initialize function for ModelReference Block: '<Root>/Model' */
  TRSC_StateMachine_initialize(rtmGetErrorStatusPointer(TRSC_SM_VC_M));

  /* Model Initialize function for ModelReference Block: '<Root>/TRSC_Vehicle_Control' */
  TRSC_VC_initialize(rtmGetErrorStatusPointer(TRSC_SM_VC_M));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
