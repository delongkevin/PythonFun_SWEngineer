/*
 * File: TRSC_SM_VC_Int.h
 *
 * Code generated for Simulink model 'TRSC_SM_VC_Int'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:53:44 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TRSC_SM_VC_Int_h_
#define RTW_HEADER_TRSC_SM_VC_Int_h_
#ifndef TRSC_SM_VC_Int_COMMON_INCLUDES_
# define TRSC_SM_VC_Int_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* TRSC_SM_VC_Int_COMMON_INCLUDES_ */

#include "TRSC_SM_VC_Int_types.h"

/* Child system includes */
#define TRSC_InputAdapter_MDLREF_HIDE_CHILD_
#include "TRSC_InputAdapter.h"
#define TRSC_SM_VC_MDLREF_HIDE_CHILD_
#include "TRSC_SM_VC.h"
#define TRSC_OutputAdapter_MDLREF_HIDE_CHILD_
#include "TRSC_OutputAdapter.h"

/* Includes for objects with custom storage classes. */
#include "TRSC_CalibParams.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

/* user code (top of header file) */
#include "SignalDef.h"

/* Block signals (default storage) */
typedef struct {
  TbTRSCSmVc_TunParam_t IbTRSCSmVc_TunParam;/* '<Root>/Signal Conversion8' */
  ME_VehInp_FromCAN2_IpcSignals IbTRSC_MEVehInpFromCAN2IpcSignals;/* '<Root>/Signal Conversion5' */
  ME_VehInp_FromCAN14_IpcSignals IbTRSC_MEVehInpFromCAN14IpcSignals;/* '<Root>/Signal Conversion4' */
  TRSCtoDiagMgr_t IbTRSC_TRSCtoDiagMgr;/* '<Root>/TRSC_Int_OutAdapter' */
  TRSC_Inputs_from_TrailerDetection_t IbTrailerDet_TrailerDetInpBus;/* '<Root>/Signal Conversion1' */
  ME_VehOut_TRSC_t IbTRSC_ME_VehOut_TRSC;/* '<Root>/TRSC_Int_OutAdapter' */
  TRSCSMVCtoSVS_t IbTRSC_TRSCtoSVS;    /* '<Root>/TRSC_Int_OutAdapter' */
  ME_ProxiToMCU2_1_Def_t IbTRSC_MEProxiToIpcSignals;/* '<Root>/Signal Conversion6' */
  TRSCSMVCtoDebugCAN_t TRSC_Int_OutAdapter_o5;/* '<Root>/TRSC_Int_OutAdapter' */
  FID_STRUCT_QM IbDDC_DegManagerDefSignals;/* '<Root>/Signal Conversion7' */
  Detection_Inputs_from_TRSC_t IbTRSC_DetInp_from_TRSC;/* '<Root>/TRSC_Int_OutAdapter' */
  SVStoTRSC_t IbSVS_SVStoTRSC;         /* '<Root>/Signal Conversion3' */
} B_TRSC_SM_VC_Int_T;

/* Real-time Model Data Structure */
struct tag_RTM_TRSC_SM_VC_Int_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_TRSC_SM_VC_Int_T TRSC_SM_VC_Int_B;

/* External data declarations for dependent source files */
extern ME_VehOut_TRSC_t TRSC_SM_VC_Int_rtZME_VehOut_TRSC_t;/* ME_VehOut_TRSC_t ground */
extern TRSCtoDiagMgr_t TRSC_SM_VC_Int_rtZTRSCtoDiagMgr_t;/* TRSCtoDiagMgr_t ground */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern TbTRSC_InpBus IbTRSC_InpBus;    /* '<Root>/TRSC_Int_InpAdapter'
                                        * IbTRSC_InpBus : TRSC state Machine Input signal bus , having following buses combined together:

                                          - Bus: TbTRSC_VehInpFromCAN2
                                          - Bus: TbTRSC_VehInpFromCAN14
                                          - Bus: TbTRSC_TrailerDetInp
                                          - Bus: TbTRSC_MEProxiToIpc
                                          - Bus: TbTRSC_SVStoTRSC

                                        */
extern uint32_T IeTRSC_e_TRSCUnavailReas;/* '<Root>/TRSC_IntModel'
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
extern uint32_T IeTRSC_e_TRSCAbortReas;/* '<Root>/TRSC_IntModel'
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
extern real32_T MeTRSC_deg_TADAngleSMVC;/* '<Root>/TRSC_Int_InpAdapter'
                                         * TAD Angle
                                         */
extern real32_T IeTRSC_M_TRSCStrTrq;   /* '<Root>/TRSC_IntModel'
                                        * TRSC steering torque overlay request  information
                                        */
extern real32_T IeTRSC_pct_TRSCStrDmp; /* '<Root>/TRSC_IntModel'
                                        * TRSC Steering damping percentage
                                        */
extern real32_T MeTRSC_deg_JackKnifeAngle;/* '<Root>/TRSC_IntModel' */
extern real32_T MeTRSC_m_TrailerBeamLen;/* '<Root>/TRSC_IntModel' */
extern real32_T MeTRSC_deg_JackknifeThrAngle;/* '<Root>/TRSC_IntModel' */
extern real32_T MeTRSC_deg_MaxAllowedTADAngle;/* '<Root>/TRSC_IntModel' */
extern real32_T MeTRSC_deg_KnobAngle;  /* '<Root>/TRSC_IntModel' */
extern real32_T IeTRSC_kph_VehSpeedVSOSig;/* '<Root>/TRSC_IntModel'
                                           * It is the average vehicle speed calculated
                                           */
extern real32_T IeTRSC_m_TrlrWhlBaseEff;/* '<Root>/TRSC_IntModel'
                                         * DID value of Trailer Wheel Base effective
                                         */
extern real32_T IeTRSC_deg_FrntWhlAng; /* '<Root>/TRSC_IntModel'
                                        * DID Value of Front Road wheel angle
                                        */
extern real32_T IeTRSC_deg_TrlrAngKnob;/* '<Root>/TRSC_IntModel'
                                        * DID Value of Trailer Angle requested by the knob
                                        */
extern real32_T IeTRSC_deg_JackknifeThrAngle;/* '<Root>/TRSC_IntModel'
                                              * DID Value of JackknifeThresholdAngle
                                              */
extern real32_T IeTRSC_deg_TADAngAct;  /* '<Root>/TRSC_IntModel'
                                        * IeTRSC_deg_TADAngAct signal output from TRSC SM
                                        */
extern real32_T MeTRSC_deg_StrCMD;     /* '<Root>/TRSC_IntModel'
                                        * Steering Angle command in degree
                                        */
extern real32_T IeTRSC_kph_SpdLmtReq_DID;/* '<Root>/TRSC_IntModel'
                                          * Speed limit request DID
                                          */
extern TeVBII_e_GearEngagedForDsply IeTRSC_e_GearShiftSts;/* '<Root>/TRSC_IntModel'
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
extern TeVBII_e_EnblBtnSts IeTRSC_e_TRSKMBtnSts;/* '<Root>/TRSC_IntModel'
                                                 * DID Value of TRSKM Button Status
                                                   NotPressed(0)
                                                   Pressed(1)
                                                   SNA(2)
                                                 */
extern TeVBII_e_CenterBtnSts IeTRSC_e_TRSKMCenBtnSts;/* '<Root>/TRSC_IntModel'
                                                      * DID Value of TRSKM Push to Center Button Status:
                                                        NotPressed(0)
                                                        Pressed(1)
                                                        SNA(2)
                                                      */
extern TeTRSC_e_VehStpReq_DID IeTRSC_e_VehStpReq_DID;/* '<Root>/TRSC_IntModel'
                                                      * TRSC break activation request DID
                                                      */
extern TeTRSC_e_VehStpReq IeTRSC_e_VehStpReq;/* '<Root>/TRSC_IntModel'
                                              * TRSC break activation request
                                              */
extern TeTRSC_e_TrlrPrsntInfo MeTRSC_e_TrlrPrsntInfoCAN;/* '<Root>/TRSC_IntModel'
                                                         * MeTRSC_e_TrlrPrsntInfoCAN signal output from TRSC SM
                                                         */
extern TeTRSC_e_TrlrHitchLightCtrl IeTRSC_e_TrlrHitchLightCtrl;/* '<Root>/TRSC_IntModel'
                                                                * Trailer Hitch light Control when trailer is connected
                                                                */
extern TeTRSC_e_TrlrCalInfo MeTRSC_e_TrlrCalInfoSMVC;/* '<Root>/TRSC_Int_InpAdapter'
                                                      * Trailer Calibration Information
                                                        0 -> Not Calibrated,
                                                        1 - >Calibrated
                                                        2 ->undefined
                                                      */
extern TeTRSC_e_TrlrCalInfo IeTRSC_e_TrlrCalInfo;/* '<Root>/TRSC_IntModel'
                                                  * Trailer Calibration Information
                                                    0 -> Not Calibrated,
                                                    1 - >Calibrated
                                                    2 ->undefined
                                                  */
extern TeTRSC_e_TRSKMSts_DID IeTRSC_e_TRSKMSts_DID;/* '<Root>/TRSC_IntModel'
                                                    * DID Value of TRSKM Module status:
                                                      Enabled,
                                                      Not Enabled,
                                                      SNA - No confirmation received by TRSKM
                                                    */
extern TeTRSC_e_TRSKMSts IeTRSC_e_TRSKMSts;/* '<Root>/TRSC_IntModel'
                                            * DID Value of TRSKM Module status:
                                              Enabled,
                                              Not Enabled,
                                              SNA - No confirmation received by TRSKM
                                            */
extern TeTRSC_e_TRSKMCenBtnSts_DID IeTRSC_e_TRSKMCenBtnSts_DID;/* '<Root>/TRSC_IntModel'
                                                                * DID Value of TRSKM Push to Center Button Status:
                                                                  NotPressed(0)
                                                                  Pressed(1)
                                                                  SNA(2)
                                                                */
extern TeTRSC_e_TRSKMBtnSts_DID IeTRSC_e_TRSKMBtnSts_DID;/* '<Root>/TRSC_IntModel'
                                                          * DID Value of TRSKM Button Status
                                                            NotPressed(0)
                                                            Pressed(1)
                                                            SNA(2)
                                                          */
extern TeTRSC_e_TRSCUnavailReas_DID IeTRSC_e_TRSCUnavailReas_DID;/* '<Root>/TRSC_IntModel'
                                                                  * TRSC Unavailable reasons DID
                                                                  */
extern TeTRSC_e_TRSCSts IeTRSC_e_TRSCSts;/* '<Root>/TRSC_IntModel'
                                          * TRSC Status
                                          */
extern TeTRSC_e_TRSCStrTrqActvReq IeTRSC_e_TRSCStrTrqActvReq;/* '<Root>/TRSC_IntModel'
                                                              * TRSC steering torque overlay activation request
                                                              */
extern TeTRSC_e_TRSCStat MeTRSC_e_TRSCStat;/* '<Root>/TRSC_IntModel'
                                            * Internal Current State of TRSC feature
                                            */
extern TeTRSC_e_TRSCPopupDispInfo IeTRSC_e_TRSCPopupDispInfo;/* '<Root>/TRSC_IntModel'
                                                              * TRSC Cluster PopUp Request
                                                              */
extern TeTRSC_e_TRSCLedSts IeTRSC_e_TRSCLedSts;/* '<Root>/TRSC_IntModel'
                                                * TRSKM LED request
                                                */
extern TeTRSC_e_TRSCAbortReason_DID IeTRSC_e_TRSCAbortReas_DID;/* '<Root>/TRSC_IntModel'
                                                                * TRSC Abort reasons DID
                                                                */
extern TeTRSC_e_TADAngActSign IeTRSC_e_TADAngActSign;/* '<Root>/TRSC_IntModel'
                                                      * IeTRSC_e_TADAngActSign signal output from TRSC SM
                                                      */
extern TeTRSC_e_SpdLmtReq IeTRSC_e_SpdLmtReq;/* '<Root>/TRSC_IntModel'
                                              * TRSC ECM Speed limit request
                                              */
extern TeTRSC_e_GraphicOverlay_Sts IeTRSC_e_GraphicOverlay_Sts;/* '<Root>/TRSC_IntModel'
                                                                * Graphical Overlay DID
                                                                */
extern TeTRSC_e_GearShiftSts_DID IeTRSC_e_GearShiftSts_DID;/* '<Root>/TRSC_IntModel'
                                                            * Gear shift status DID
                                                            */
extern TeTRSC_e_DispView2_DID MeSVS_e_DispView2Info_DID;/* '<Root>/TRSC_IntModel'
                                                         * CVPM Display view2 status from HMI
                                                         */
extern uint16_T IeTRSC_cnt_KnobPos;    /* '<Root>/TRSC_IntModel'
                                        * DID Value of TRSKM Knob Position
                                        */
extern boolean_T IeTRSC_b_MoreCamReqSts;/* '<Root>/TRSC_IntModel'
                                         * Status of More Camera request Input from HMI SoftButton, ( 0 -> NotPressed, 1 -> Pressed)
                                         */
extern boolean_T MeTRSC_b_MoreCamSoftButtEnbl;/* '<Root>/TRSC_IntModel'
                                               * More Camera Enable Soft Button Input
                                               */
extern boolean_T MeTRSC_b_TRSCSwitchPressed;/* '<Root>/TRSC_IntModel' */
extern boolean_T MeTRSC_b_TrlrRevSteeringStsInfo;/* '<Root>/TRSC_IntModel' */
extern boolean_T MeTRSC_b_OTBLReset;   /* '<Root>/TRSC_IntModel'
                                        * OTBL Reset flag
                                        */
extern boolean_T MeTRSC_b_TBLComputationDone;/* '<Root>/TRSC_IntModel' */
extern boolean_T MeTRSC_b_TrlrCalibPopInfo;/* '<Root>/TRSC_IntModel'
                                            * Trailer Calibration Popup information
                                            */

/* Model entry point functions */
extern void TRSC_SM_VC_Int_initialize(void);
extern void TRSC_SM_VC_Int_step(void);
extern void TRSC_SM_VC_Int_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TRSC_SM_VC_Int_T *const TRSC_SM_VC_Int_M;

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
 * '<Root>' : 'TRSC_SM_VC_Int'
 * '<S1>'   : 'TRSC_SM_VC_Int/Model Info'
 */
#endif                                 /* RTW_HEADER_TRSC_SM_VC_Int_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
