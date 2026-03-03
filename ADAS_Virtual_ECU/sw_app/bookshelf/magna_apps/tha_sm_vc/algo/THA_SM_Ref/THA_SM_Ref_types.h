/*
 * File: THA_SM_Ref_types.h
 *
 * Code generated for Simulink model 'THA_SM_Ref'.
 *
 * Model version                  : 1.1861
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Aug  7 17:42:07 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_THA_SM_Ref_types_h_
#define RTW_HEADER_THA_SM_Ref_types_h_
#include "rtwtypes.h"
#include "TeTHA_e_HitchDetctStatus.h"
#include "TeTHA_e_CplrDetctStatus.h"
#include "TeTHA_e_ScreenRequest.h"
#include "TeSVS_e_DispView2.h"
#include "TeVBII_e_CmdIgnSts.h"
#include "TeVBII_e_TrailerConnectionSts.h"
#include "TeVBII_e_TrlrPrsntSts.h"
#include "TeVBII_e_TchScrSts.h"
#include "TeVBII_e_GearEngagedForDsply.h"
#include "TeVBII_e_VehStandStillSts.h"
#include "TeVBII_e_WhlSpnSts.h"
#include "TeVBII_e_VehEPBSts.h"
#include "TeVBII_e_BsmTHABrkResp.h"
#include "TeVBII_e_LwsAngleType.h"
#include "TeVBII_e_EpsTHADrvTrqOvrd.h"
#include "TeVBII_e_EpsTHASteerTrqResp.h"
#include "TeVBII_e_THASteerTouchStatus.h"
#include "TeVBII_e_EngineSts.h"
#include "TeVBII_e_EssEngState.h"
#include "TeVBII_e_EcmTHAResp.h"
#include "TePRX_e_VehLineCfg.h"
#include "TePRX_e_Wheelbase.h"
#include "TePRX_e_SteerRatRackPinionTyp.h"
#include "TeAP_e_FrntRearParkSts.h"
#include "TeAP_e_AutoParkStatus.h"
#include "TeTRSC_e_TRSCSts.h"
#include "TeTHA_e_THARmpUpDwnSpd.h"
#include "TeTHA_e_THASteerTrqReq.h"
#include "TeTHA_e_PamVol.h"
#include "TeTHA_e_PamChimeTyp.h"
#include "TeTHA_e_PamChimeRepRateSts.h"
#include "TeTHA_e_THAStateInfo.h"
#include "TeTHA_e_EPBReq.h"
#include "TeTHA_e_THASpdLimReq.h"
#include "TeTHA_e_THAState.h"
#include "TeTHA_e_RearBrkSupprInfo.h"
#ifndef DEFINED_TYPEDEF_FOR_TbTHASmVc_InputFromThaDet_t_
#define DEFINED_TYPEDEF_FOR_TbTHASmVc_InputFromThaDet_t_

typedef struct {
  /* Hitch detection status.
     0 - Not_Valid
     1 - Not_Detected
     2 - Detected */
  TeTHA_e_HitchDetctStatus MeTHA_e_HitchDetctStatus;

  /* Coupler detection status.
     0 - Not valid
     1 - Not_Detected
     2 - Detected */
  TeTHA_e_CplrDetctStatus MeTHA_e_CplrDetctStatus;

  /* Coupler angle. */
  real32_T MeTHA_deg_CplrAng;
  boolean_T MeTHA_b_CplrAngFound;

  /* Longitudinal Pixel Y difference from hitch to coupler. */
  int32_T MeTHA_px_HitchCplrPixDiffLong;

  /* Longitudinal Pixel X difference from hitch to coupler. */
  int32_T MeTHA_px_HitchCplrPixDiffLat;

  /* Hitch pixel position in rear view image. */
  int32_T MeTHA_px_HitchPnt[2];

  /* Coupler ball pixel position in rear view image. */
  int32_T MeTHA_px_CplrPnt[2];
} TbTHASmVc_InputFromThaDet_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbTHASmVc_InputFromHmiSvs_t_
#define DEFINED_TYPEDEF_FOR_TbTHASmVc_InputFromHmiSvs_t_

typedef struct {
  /* THA soft button pressed status. */
  boolean_T MeSVS_b_THASftBtnPrsdStsToTHA;

  /* Confirm button pressed. */
  boolean_T MeSVS_b_IsConfirmBtnPrsd;

  /* THA screen request acknowledgement from HMI. */
  TeTHA_e_ScreenRequest MeSVS_e_THAScrResp;

  /* Cancel Button */
  boolean_T MeSVS_b_ImgDefeatReqSts;

  /* HMI view zoom status.
     0 - Normal view
     1- Zoomed view */
  boolean_T MeSVS_b_ViewZoomSts;

  /* THA start manuever button pressed status. */
  boolean_T MeSVS_b_THAMnvrStartBtnPrsd;

  /* THA screen touch status. */
  boolean_T MeSVS_b_THAScrTchSts;

  /* THA feature abort request from HMI. */
  boolean_T MeSVS_b_THAAbortReq;

  /* HMI Display View and DID Value of Camera view (#) displayed on the radio screen. */
  TeSVS_e_DispView2 IeSVS_e_DispView2;
} TbTHASmVc_InputFromHmiSvs_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbTHASmVc_InputFromVehInp_t_
#define DEFINED_TYPEDEF_FOR_TbTHASmVc_InputFromVehInp_t_

typedef struct {
  /* Used to indicate the status of driver door */
  boolean_T IeVBII_b_DriverDoorSts;

  /* Used to indicate the status of the trunk liftgate */
  boolean_T IeVBII_b_TrnkStatus;

  /* Used to give information about the key selector position
     0 = Initialization
     1 = IGN_LK
     3 = ACC
     4 = RUN
     5 = START
     7 = SNA */
  TeVBII_e_CmdIgnSts IeVBII_e_CmdIgnSts;

  /* Connection status of TTM
     0 = NotConnected
     1 = Connected
     2 = NotUsed
     3 = SNA */
  TeVBII_e_TrailerConnectionSts IeVBII_e_TrailerConnectionSts;

  /* Trailer connection status
     0 = NO_TRLR
     1 = TRLR_PRSNT
     2 = TRLR_DCONN
     3 =  SNA */
  TeVBII_e_TrlrPrsntSts IeVBII_e_TrlrPrsntSts;

  /* Head unit touch screen status. */
  TeVBII_e_TchScrSts IeVBII_e_TchScrSts;

  /* Transmission Gear engaged signal for Display on cluster
     0 = Initialize
     1 = 1st_gear
     2 = 2nd_gear
     3 = 3rd_gear
     4 = 4th_gear
     5 = 5th_gear
     6 = 6th_gear
     7 = 7th_gear
     8 = 8th_gear
     9 = 9th_gear
     10 = Not_used1
     11 = Not_Used2
     12 = P
     13 = N
     14 = R
     15 = D
     16 = L
     17 = M
     18 = S
     31 =SNA */
  TeVBII_e_GearEngagedForDsply IeVBII_e_GearEngagedForDsply;

  /* This signal indicates if the car is in stand still condition
     0 = True
     1 = False
     3 = SNA */
  TeVBII_e_VehStandStillSts IeVBII_e_VehStandStillSts;

  /* This signal indicates the Lateral Acceleration Value (m/s^2) */
  real32_T IeVBII_a_VehLatAcc;

  /* This signal indicates the Longitudinal Acceleration Value (m/s^2) */
  real32_T IeVBII_a_VehLongAcc;

  /* This signal indicates the Yaw Rate Value */
  real32_T IeVBII_ddeg_VehYawRate;

  /* It is the average vehicle speed calculated */
  real32_T IeVBII_kph_VehSpeedVSOSig;

  /* This signal is the left front wheel pulse counter */
  uint8_T IeVBII_cnt_LhfPulseCtr;

  /* This signal indicates the left hand front wheel status
     0 = Stand_Still
     1 = Forward
     2 = Backward
     3 = SNA */
  TeVBII_e_WhlSpnSts IeVBII_e_LhfWhlSpnSts;

  /* This is the value of the left front wheel speed */
  real32_T IeVBII_kph_LhfWhlSpd;

  /* This signal is the left rear wheel pulse counter */
  uint8_T IeVBII_cnt_LhrPulseCtr;

  /* This signal indicates the left hand rear wheel status

     0 = Stand_Still
     1 = Forward
     2 = Backward
     3 = SNA */
  TeVBII_e_WhlSpnSts IeVBII_e_LhrWhlSpnSts;

  /* This is the value of the left rear wheel speed */
  real32_T IeVBII_kph_LhrWhlSpd;

  /* This signal is the right front wheel pulse counter */
  uint8_T IeVBII_cnt_RhfPulseCtr;

  /* This signal indicates the right hand front wheel status

     0 = Stand_Still
     1 = Forward
     2 = Backward
     3 = SNA */
  TeVBII_e_WhlSpnSts IeVBII_e_RhfWhlSpnSts;

  /* This is the value of the right front wheel speed */
  real32_T IeVBII_kph_RhfWhlSpd;

  /* This signal is the right rear wheel pulse counter */
  uint8_T IeVBII_cnt_RhrPulseCtr;

  /* This signal indicates the right hand rear wheel status

     0 = Stand_Still
     1 = Forward
     2 = Backward
     3 = SNA */
  TeVBII_e_WhlSpnSts IeVBII_e_RhrWhlSpnSts;

  /* This is the value of the right rear wheel speed */
  real32_T IeVBII_kph_RhrWhlSpd;

  /* LatAccelerationOffset_BSM (m/s^2). */
  real32_T IeVBII_a_VehLatAccOffset;

  /* LongAccelerationOffset_BSM (m/s^2) */
  real32_T IeVBII_a_VehLongAccOffset;

  /* 0 = Released
     1 = Applied
     2 = DynamicBrkESC
     3 = DynamicBrkEPB
     4 = Emergency_Braking
     5 = Applying
     6 = Maintenance_Mode
     7 = Assembly_Check
     8 = Inspection_Mode
     9 = Re_Clamping
     10 = Adjuste_Mode
     11 = Releasing
     12 = Fault_EPB_Released
     13 = Fault_EPB_Applied
     14 = Fault_Present
     15 = SNA */
  TeVBII_e_VehEPBSts IeVBII_e_VehEPBSts;

  /* BSM braking status for trailer hitch assist
     0 = Off
     1 = Active
     2 = Brakes Overheated
     3 = SNA */
  TeVBII_e_BsmTHABrkResp IeVBII_e_BsmTHABrkResp;

  /* This signal indicates the steering angle value, counterclockwise positive */
  real32_T IeVBII_deg_StrWhlAng;

  /* Steering wheel angle speed. */
  real32_T IeVBII_ddeg_StrWhlSpd;

  /* This signal indicates whether the angle sensor is absolute (all the possible turns/degrees) or not absolute (relative, torque only, etc.).
     0 = Absolute
     1 = Relative
     3 = SNA */
  TeVBII_e_LwsAngleType IeVBII_e_LwsAngleType;

  /* Determines if EPS driver torque on hand wheel is large enough to  override THA
     0 = False
     1 = True
     3 = SNA */
  TeVBII_e_EpsTHADrvTrqOvrd IeVBII_e_EpsTHADrvTrqOvrd;

  /* EPS steering torque overlay availability response for trailer hitch assist
     0 = Temp_NA
     1 = Perm_NA
     2 = TOI_Available
     3 = TOI_Unavailable
     7 = SNA */
  TeVBII_e_EpsTHASteerTrqResp IeVBII_e_EpsTHASteerTrqResp;

  /* EPS hands on status for trailer hitch assist
     0 = Hands Off
     1 = Hands On
     3 = SNA */
  TeVBII_e_THASteerTouchStatus IeVBII_e_THASteerTouchStatus;

  /* Engine Status
     0 = Engine_Off
     1 = Engine_Cranking
     2 = Engine_On
     3 = SNA */
  TeVBII_e_EngineSts IeVBII_e_EngineSts;

  /* ESS Engine State
     1 = ENS Stopped / ENS_STOPPED
     2 = ENS Request Start / ENS_RQ_ST
     3 = ENS Running / ENS_RUN
     4 = ENS Stop Pending / ENS_STOP_PEND
     5 = ENS Start protection / ENS_ST_PRTCT
     6 = ENS Start inhibit / ENS_ST_INH
     7 = ENS disabled / ENS_DSBL
     8 = ENS_IHB_LATCH
     9 = ENS Starting / ENS_Starting
     15 = SNA */
  TeVBII_e_EssEngState IeVBII_e_EssEngState;

  /* ECM speed limiting availability response for trailer hitch assist
     0 = Off
     1 = Active
     3 = SNA */
  TeVBII_e_EcmTHAResp IeVBII_e_EcmTHAResp;
} TbTHASmVc_InputFromVehInp_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbTHASmVc_InputFromProxiMgr_t_
#define DEFINED_TYPEDEF_FOR_TbTHASmVc_InputFromProxiMgr_t_

typedef struct {
  /* PROXI parameter CAN node 63 (TTM). */
  boolean_T MePRX_b_CanNod63;

  /* PROXI parameter CAN node 95 (ITBM/ITCM). */
  boolean_T MePRX_b_CanNod95;

  /* Park with stop. */
  boolean_T MePRX_b_ParkWithStop;

  /* Proxi parameter variant id. */
  uint8_T MePRX_k_VariantId;

  /* Proxi parameter Vehicle Line Configuration.

     0 = Invalid
     51 = 343 (33 Hex)
     52 = 327FL (34 Hex)
     53 = 226 (35 Hex)
     80 = PF (50 Hex)
     81 = KL/K4  (51 Hex)
     82 = UF (52 Hex)
     83 = UT (53 Hex)
     84 = 334 (54 Hex)
     85 = 520 (55 Hex)
     86 = 551 /M1 (56 Hex)
     87 = 338 (57 Hex)
     88 = 521 (58 Hex)
     89 = 636 VM (59 Hex)
     90 = 356 (5A Hex)
     91 = 952 (5B Hex)
     92 = 341 (5C Hex)
     93 = 552/MP (5D Hex)
     94 = 949 (5E Hex)
     95 = 523 (5F Hex)
     96 = 358 (60 Hex)
     97 = 359 (61 Hex)
     98 = 553/M4 (62 Hex)
     99 = 556/M6 (63 Hex)
     100 = K8 (64 Hex)
     101 = WL (65 Hex)
     102 = 281 (66 Hex)
     103 = 363 (67 Hex)
     104 = WS (68 Hex)
     105 = 332 (69 Hex)
     106 = 560 (6A Hex)
     124 = DT (7C hex) */
  TePRX_e_VehLineCfg MePRX_e_VehLineCfg;

  /* Proxi parameter Trailer Hitch Assist Presence. */
  boolean_T MePRX_b_TrlrHitchAssPres;

  /* Proxi parameter Wheelbase.
     0 = Invalid
     1 = Type 1 (Short Wheel Base - 3124)
     2 = Type 2 (Long Wheel Base - 3302) */
  TePRX_e_Wheelbase MePRX_e_Wheelbase;

  /* Proxi parameter Tyre Size. */
  uint16_T MePRX_mm_TyreSz;

  /* Proxi parameter Steering Ratio Rack Pinion Type.
     0 = Type_1 (Rebel 144.5" WB, 55 C-Factor
     1 = Type_2 (Base 140.5' WB or 144.5' WB, 60 C-Factor
     2 = Type_3 (Base 153.5' WB or TRX, 63 C-Factor) */
  TePRX_e_SteerRatRackPinionTyp MePRX_e_SteerRatRackPinionTyp;
} TbTHASmVc_InputFromProxiMgr_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbTHASmVc_InputFromDegMgr_t_
#define DEFINED_TYPEDEF_FOR_TbTHASmVc_InputFromDegMgr_t_

typedef struct {
  boolean_T MeTHA_b_FidDisabled;
  boolean_T MeTHA_b_FidCamCalAbort;
  boolean_T MeTHA_b_FidDLDAbort;
} TbTHASmVc_InputFromDegMgr_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbTHASmVc_InputFromApSmPa_t_
#define DEFINED_TYPEDEF_FOR_TbTHASmVc_InputFromApSmPa_t_

typedef struct {
  /* FT_OFF_RR_OFF(0)
     FT_OFF_RR_ON(1)
     FT_ON_RR_OFF(2)
     FT_ON_RR_ON(3) */
  TeAP_e_FrntRearParkSts IeAP_e_FrntRearParkSts;

  /* Autopark feature status
     Off(0)
     Initialize(1)
     Standby(2)
     Active(3)
     Fault(4)
     Abort(5)
     Complete(6) */
  TeAP_e_AutoParkStatus IeAP_e_AutoParkStatus;
} TbTHASmVc_InputFromApSmPa_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbTHASmVc_InputFromTRSC_t_
#define DEFINED_TYPEDEF_FOR_TbTHASmVc_InputFromTRSC_t_

typedef struct {
  /* Current state of TRSC feature :
     0 - Standby,
     1 - Calibrating,
     2 - PreActive,
     3 - Active */
  TeTRSC_e_TRSCSts IeTRSC_e_TRSCSts;
} TbTHASmVc_InputFromTRSC_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbTHASmVc_InputVrntTunParam_t_
#define DEFINED_TYPEDEF_FOR_TbTHASmVc_InputVrntTunParam_t_

typedef struct {
  int32_T KeTHA_px_HitchCplrDeltaThd1;
  int32_T KeTHA_px_HitchCplrDeltaThd2;
  int32_T KeTHA_px_RearBrkSuppDist;
  real32_T KeTHA_M_SteerTweakTrq;
  real32_T KeTHA_s_SteerTweakTime;
  real32_T KeTHA_k_SteerTrqCtrlKp;
  real32_T KeTHA_k_SteerTrqCtrlKi;
  real32_T KeTHA_k_SteerTrqCtrlKd;
  real32_T KeTHA_k_SteerTrqCtrlFiltCoef;
  real32_T KeTHA_k_TrqCtrlKp;
  real32_T KeTHA_k_TrqCtrlKi;
  real32_T KeTHA_k_TrqCtrlKd;
  real32_T KeTHA_k_TrqCtrlFiltCoef;
  uint16_T KeTHA_ddeg_StrRateLimFinal;
  uint16_T KeTHA_ddeg_StrRateLimInit;
  real32_T KeTHA_k_HeadingErrGain;
  real32_T KeTHA_m_WhlCircumference;
  real32_T KsTHA_deg_StrToRdWhlAngTD[17];
  real32_T KsTHA_mps_DistSpdTD[6];
  real32_T KsTHA_k_ErrxHeadingErrTD[4];
  real32_T KsTHA_k_ErrxPropGainTD[5];
} TbTHASmVc_InputVrntTunParam_t;

#endif
#endif                                 /* RTW_HEADER_THA_SM_Ref_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
