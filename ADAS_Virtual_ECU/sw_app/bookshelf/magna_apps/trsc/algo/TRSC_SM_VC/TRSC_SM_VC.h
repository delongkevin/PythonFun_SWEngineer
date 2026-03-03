/*
 * File: TRSC_SM_VC.h
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

#ifndef RTW_HEADER_TRSC_SM_VC_h_
#define RTW_HEADER_TRSC_SM_VC_h_
#ifndef TRSC_SM_VC_COMMON_INCLUDES_
# define TRSC_SM_VC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* TRSC_SM_VC_COMMON_INCLUDES_ */

#include "TRSC_SM_VC_types.h"

/* Child system includes */
#ifndef TRSC_SM_VC_MDLREF_HIDE_CHILD_
#define TRSC_StateMachine_MDLREF_HIDE_CHILD_
#include "TRSC_StateMachine.h"
#endif                                 /*TRSC_SM_VC_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_SM_VC_MDLREF_HIDE_CHILD_
#define TRSC_VC_MDLREF_HIDE_CHILD_
#include "TRSC_VC.h"
#endif                                 /*TRSC_SM_VC_MDLREF_HIDE_CHILD_*/

/* Includes for objects with custom storage classes. */
#include "TRSC_CalibParams.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

/* user code (top of header file) */
#include "SignalDef.h"

/* Block signals for model 'TRSC_SM_VC' */
#ifndef TRSC_SM_VC_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T MeTRSC_deg_JackKnifeAngle_m;/* '<Root>/Unit Delay4' */
  real32_T MeTRSC_M_TRSCStrTrq_h;      /* '<Root>/Unit Delay' */
  real32_T MeTRSC_pct_TRSCStrDmp_k;    /* '<Root>/Unit Delay2' */
  real32_T DataTypeConversion;         /* '<Root>/Data Type Conversion' */
  real32_T MeTRSC_m_TrailerBeamLen_l;  /* '<Root>/Unit Delay5' */
  TeTRSC_e_SpdLmtReq MeTRSC_e_SpdLmtReq;/* '<Root>/Unit Delay1' */
  TeTRSC_e_SpdLmtReq TRSC_Vehicle_Control_o7;/* '<Root>/TRSC_Vehicle_Control' */
  boolean_T MeTRSC_b_StrTwitchComplete_o;/* '<Root>/Unit Delay3' */
} B_TRSC_SM_VC_c_T;

#endif                                 /*TRSC_SM_VC_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'TRSC_SM_VC' */
#ifndef TRSC_SM_VC_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T UnitDelay4_DSTATE;          /* '<Root>/Unit Delay4' */
  real32_T UnitDelay_DSTATE;           /* '<Root>/Unit Delay' */
  real32_T UnitDelay2_DSTATE;          /* '<Root>/Unit Delay2' */
  real32_T UnitDelay5_DSTATE;          /* '<Root>/Unit Delay5' */
  TeTRSC_e_SpdLmtReq UnitDelay1_DSTATE;/* '<Root>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE;         /* '<Root>/Unit Delay3' */
} DW_TRSC_SM_VC_f_T;

#endif                                 /*TRSC_SM_VC_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_SM_VC_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_TRSC_SM_VC_T {
  const char_T **errorStatus;
};

#endif                                 /*TRSC_SM_VC_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_SM_VC_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_TRSC_SM_VC_T rtm;
} MdlrefDW_TRSC_SM_VC_T;

#endif                                 /*TRSC_SM_VC_MDLREF_HIDE_CHILD_*/

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
extern uint32_T IeTRSC_e_TRSCUnavailReas;/* '<Root>/Model'
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
extern uint32_T IeTRSC_e_TRSCAbortReas;/* '<Root>/Model'
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
extern real32_T IeTRSC_M_TRSCStrTrq;   /* '<Root>/Model'
                                        * TRSC steering torque overlay request  information
                                        */
extern real32_T IeTRSC_pct_TRSCStrDmp; /* '<Root>/Model'
                                        * TRSC Steering damping percentage
                                        */
extern real32_T IeTRSC_kph_VehSpeedVSOSig;/* '<Root>/Model'
                                           * It is the average vehicle speed calculated
                                           */
extern real32_T IeTRSC_deg_TADAngAct;  /* '<Root>/Model'
                                        * IeTRSC_deg_TADAngAct signal output from TRSC SM
                                        */
extern real32_T IeTRSC_kph_SpdLmtReq_DID;/* '<Root>/Model'
                                          * Speed limit request DID
                                          */
extern real32_T MeTRSC_M_TRSCStrTrq;   /* '<Root>/TRSC_Vehicle_Control'
                                        * Steering Torque input from Vehicle Control
                                        */
extern real32_T MeTRSC_deg_JackKnifeAngle;/* '<Root>/TRSC_Vehicle_Control' */
extern real32_T MeTRSC_m_TrailerBeamLen;/* '<Root>/TRSC_Vehicle_Control' */
extern real32_T MeTRSC_deg_JackknifeThrAngle;/* '<Root>/TRSC_Vehicle_Control' */
extern real32_T MeTRSC_deg_MaxAllowedTADAngle;/* '<Root>/TRSC_Vehicle_Control' */
extern real32_T MeTRSC_pct_TRSCStrDmp; /* '<Root>/TRSC_Vehicle_Control'
                                        * Steering Damping command in %
                                        */
extern real32_T MeTRSC_deg_KnobAngle;  /* '<Root>/TRSC_Vehicle_Control' */
extern real32_T IeTRSC_m_TrlrWhlBaseEff;/* '<Root>/TRSC_Vehicle_Control'
                                         * DID value of Trailer Wheel Base effective
                                         */
extern real32_T IeTRSC_deg_FrntWhlAng; /* '<Root>/TRSC_Vehicle_Control'
                                        * DID Value of Front Road wheel angle
                                        */
extern real32_T IeTRSC_deg_TrlrAngKnob;/* '<Root>/TRSC_Vehicle_Control'
                                        * DID Value of Trailer Angle requested by the knob
                                        */
extern real32_T IeTRSC_deg_JackknifeThrAngle;/* '<Root>/TRSC_Vehicle_Control'
                                              * DID Value of JackknifeThresholdAngle
                                              */
extern real32_T MeTRSC_deg_StrCMD;     /* '<Root>/TRSC_Vehicle_Control'
                                        * Steering Angle command in degree
                                        */
extern TeVBII_e_GearEngagedForDsply IeTRSC_e_GearShiftSts;/* '<Root>/Model'
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
extern TeVBII_e_EnblBtnSts IeTRSC_e_TRSKMBtnSts;/* '<Root>/Model'
                                                 * DID Value of TRSKM Button Status
                                                   NotPressed(0)
                                                   Pressed(1)
                                                   SNA(2)
                                                 */
extern TeVBII_e_CenterBtnSts IeTRSC_e_TRSKMCenBtnSts;/* '<Root>/Model'
                                                      * DID Value of TRSKM Push to Center Button Status:
                                                        NotPressed(0)
                                                        Pressed(1)
                                                        SNA(2)
                                                      */
extern TeTRSC_e_VehStpReq_DID IeTRSC_e_VehStpReq_DID;/* '<Root>/Model'
                                                      * TRSC break activation request DID
                                                      */
extern TeTRSC_e_VehStpReq IeTRSC_e_VehStpReq;/* '<Root>/Model'
                                              * TRSC break activation request
                                              */
extern TeTRSC_e_TrlrPrsntInfo MeTRSC_e_TrlrPrsntInfoCAN;/* '<Root>/Model'
                                                         * MeTRSC_e_TrlrPrsntInfoCAN signal output from TRSC SM
                                                         */
extern TeTRSC_e_TrlrHitchLightCtrl IeTRSC_e_TrlrHitchLightCtrl;/* '<Root>/Model'
                                                                * Trailer Hitch light Control when trailer is connected
                                                                */
extern TeTRSC_e_TrlrCalInfo IeTRSC_e_TrlrCalInfo;/* '<Root>/Model'
                                                  * Trailer Calibration Information
                                                    0 -> Not Calibrated,
                                                    1 - >Calibrated
                                                    2 ->undefined
                                                  */
extern TeTRSC_e_TRSKMSts_DID IeTRSC_e_TRSKMSts_DID;/* '<Root>/Model'
                                                    * DID Value of TRSKM Module status:
                                                      Enabled,
                                                      Not Enabled,
                                                      SNA - No confirmation received by TRSKM
                                                    */
extern TeTRSC_e_TRSKMSts IeTRSC_e_TRSKMSts;/* '<Root>/Model'
                                            * DID Value of TRSKM Module status:
                                              Enabled,
                                              Not Enabled,
                                              SNA - No confirmation received by TRSKM
                                            */
extern TeTRSC_e_TRSKMCenBtnSts_DID IeTRSC_e_TRSKMCenBtnSts_DID;/* '<Root>/Model'
                                                                * DID Value of TRSKM Push to Center Button Status:
                                                                  NotPressed(0)
                                                                  Pressed(1)
                                                                  SNA(2)
                                                                */
extern TeTRSC_e_TRSKMBtnSts_DID IeTRSC_e_TRSKMBtnSts_DID;/* '<Root>/Model'
                                                          * DID Value of TRSKM Button Status
                                                            NotPressed(0)
                                                            Pressed(1)
                                                            SNA(2)
                                                          */
extern TeTRSC_e_TRSCUnavailReas_DID IeTRSC_e_TRSCUnavailReas_DID;/* '<Root>/Model'
                                                                  * TRSC Unavailable reasons DID
                                                                  */
extern TeTRSC_e_TRSCSts IeTRSC_e_TRSCSts;/* '<Root>/Model'
                                          * TRSC Status
                                          */
extern TeTRSC_e_TRSCStrTrqActvReq IeTRSC_e_TRSCStrTrqActvReq;/* '<Root>/Model'
                                                              * TRSC steering torque overlay activation request
                                                              */
extern TeTRSC_e_TRSCStrTrqActvReq MeTRSC_e_TRSCStrTrqActvReq;/* '<Root>/TRSC_Vehicle_Control' */
extern TeTRSC_e_TRSCStat MeTRSC_e_TRSCStat;/* '<Root>/Model'
                                            * Internal Current State of TRSC feature
                                            */
extern TeTRSC_e_TRSCPopupDispInfo IeTRSC_e_TRSCPopupDispInfo;/* '<Root>/Model'
                                                              * TRSC Cluster PopUp Request
                                                              */
extern TeTRSC_e_TRSCLedSts IeTRSC_e_TRSCLedSts;/* '<Root>/Model'
                                                * TRSKM LED request
                                                */
extern TeTRSC_e_TRSCAbortReason_DID IeTRSC_e_TRSCAbortReas_DID;/* '<Root>/Model'
                                                                * TRSC Abort reasons DID
                                                                */
extern TeTRSC_e_TADAngActSign IeTRSC_e_TADAngActSign;/* '<Root>/Model'
                                                      * IeTRSC_e_TADAngActSign signal output from TRSC SM
                                                      */
extern TeTRSC_e_SpdLmtReq IeTRSC_e_SpdLmtReq;/* '<Root>/Model'
                                              * TRSC ECM Speed limit request
                                              */
extern TeTRSC_e_GraphicOverlay_Sts IeTRSC_e_GraphicOverlay_Sts;/* '<Root>/Model'
                                                                * Graphical Overlay DID
                                                                */
extern TeTRSC_e_GearShiftSts_DID IeTRSC_e_GearShiftSts_DID;/* '<Root>/Model'
                                                            * Gear shift status DID
                                                            */
extern TeTRSC_e_DispView2_DID MeSVS_e_DispView2Info_DID;/* '<Root>/Model'
                                                         * CVPM Display view2 status from HMI
                                                         */
extern uint16_T IeTRSC_cnt_KnobPos;    /* '<Root>/Model'
                                        * DID Value of TRSKM Knob Position
                                        */
extern boolean_T IeTRSC_b_MoreCamReqSts;/* '<Root>/Model'
                                         * Status of More Camera request Input from HMI SoftButton, ( 0 -> NotPressed, 1 -> Pressed)
                                         */
extern boolean_T MeTRSC_b_MoreCamSoftButtEnbl;/* '<Root>/Model'
                                               * More Camera Enable Soft Button Input
                                               */
extern boolean_T MeTRSC_b_TRSCSwitchPressed;/* '<Root>/Model' */
extern boolean_T MeTRSC_b_TrlrRevSteeringStsInfo;/* '<Root>/Model' */
extern boolean_T MeTRSC_b_TrlrCalibPopInfo;/* '<Root>/Model'
                                            * Trailer Calibration Popup information
                                            */
extern boolean_T MeTRSC_b_StrTwitchComplete;/* '<Root>/TRSC_Vehicle_Control'
                                             * Steering Twitch Complete Status
                                             */
extern boolean_T MeTRSC_b_OTBLReset;   /* '<Root>/TRSC_Vehicle_Control'
                                        * OTBL Reset flag
                                        */
extern boolean_T MeTRSC_b_TBLComputationDone;/* '<Root>/TRSC_Vehicle_Control' */
extern void TRSC_SM_VC_Init(void);
extern void TRSC_SM_VC_Start(void);
extern void TRSC_SM_VC_Disable(void);
extern void TRSC_SM_VC(void);

/* Model reference registration function */
extern void TRSC_SM_VC_initialize(const char_T **rt_errorStatus);

#ifndef TRSC_SM_VC_MDLREF_HIDE_CHILD_

extern MdlrefDW_TRSC_SM_VC_T TRSC_SM_VC_MdlrefDW;

#endif                                 /*TRSC_SM_VC_MDLREF_HIDE_CHILD_*/

#ifndef TRSC_SM_VC_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_TRSC_SM_VC_c_T TRSC_SM_VC_B;

/* Block states (default storage) */
extern DW_TRSC_SM_VC_f_T TRSC_SM_VC_DW;

#endif                                 /*TRSC_SM_VC_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'TRSC_SM_VC'
 */
#endif                                 /* RTW_HEADER_TRSC_SM_VC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
