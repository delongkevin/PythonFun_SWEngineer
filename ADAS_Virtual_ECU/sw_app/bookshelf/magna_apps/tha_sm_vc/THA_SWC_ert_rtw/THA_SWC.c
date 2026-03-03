/*
 * File: THA_SWC.c
 *
 * Code generated for Simulink model 'THA_SWC'.
 *
 * Model version                  : 1.1595
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Aug  7 17:43:08 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "THA_SWC.h"
#include "THA_SWC_private.h"
#include <UART_stdio.h>
#include <ti/osal/TaskP.h>
#if DEBUG_PRINTS
static uint32_t counter = 0;
#endif
//Dipti : Added header for resetting VC variables in step function
#include "THA_VC_Ref.h"

const TbTHASmVc_InputFromVehInp_t THA_SWC_rtZTbTHASmVc_InputFromVehInp_t = {
  false,                               /* IeVBII_b_DriverDoorSts */
  false,                               /* IeVBII_b_TrnkStatus */
  TeVBII_e_CmdIgnSts_Initialization,   /* IeVBII_e_CmdIgnSts */
  TeVBII_e_TrailerConnectionSts_NotConnected,/* IeVBII_e_TrailerConnectionSts */
  TeVBII_e_TrlrPrsntSts_NO_TRLR,       /* IeVBII_e_TrlrPrsntSts */
  TeVBII_e_TchScrSts_TCH_NOT_PSD,      /* IeVBII_e_TchScrSts */
  TeVBII_e_GearEngagedForDsply_Initialize,/* IeVBII_e_GearEngagedForDsply */
  TeVBII_e_VehStandStillSts_False,     /* IeVBII_e_VehStandStillSts */
  0.0F,                                /* IeVBII_a_VehLatAcc */
  0.0F,                                /* IeVBII_a_VehLongAcc */
  0.0F,                                /* IeVBII_ddeg_VehYawRate */
  0.0F,                                /* IeVBII_kph_VehSpeedVSOSig */
  0U,                                  /* IeVBII_cnt_LhfPulseCtr */
  TeVBII_e_WhlSpnSts_StandStill,       /* IeVBII_e_LhfWhlSpnSts */
  0.0F,                                /* IeVBII_kph_LhfWhlSpd */
  0U,                                  /* IeVBII_cnt_LhrPulseCtr */
  TeVBII_e_WhlSpnSts_StandStill,       /* IeVBII_e_LhrWhlSpnSts */
  0.0F,                                /* IeVBII_kph_LhrWhlSpd */
  0U,                                  /* IeVBII_cnt_RhfPulseCtr */
  TeVBII_e_WhlSpnSts_StandStill,       /* IeVBII_e_RhfWhlSpnSts */
  0.0F,                                /* IeVBII_kph_RhfWhlSpd */
  0U,                                  /* IeVBII_cnt_RhrPulseCtr */
  TeVBII_e_WhlSpnSts_StandStill,       /* IeVBII_e_RhrWhlSpnSts */
  0.0F,                                /* IeVBII_kph_RhrWhlSpd */
  0.0F,                                /* IeVBII_a_VehLatAccOffset */
  0.0F,                                /* IeVBII_a_VehLongAccOffset */
  TeVBII_e_VehEPBSts_Released,         /* IeVBII_e_VehEPBSts */
  TeVBII_e_BsmTHABrkResp_Off,          /* IeVBII_e_BsmTHABrkResp */
  0.0F,                                /* IeVBII_deg_StrWhlAng */
  0.0F,                                /* IeVBII_ddeg_StrWhlSpd */
  TeVBII_e_LwsAngleType_Absolute,      /* IeVBII_e_LwsAngleType */
  TeVBII_e_EpsTHADrvTrqOvrd_False,     /* IeVBII_e_EpsTHADrvTrqOvrd */
  TeVBII_e_EpsTHASteerTrqResp_Temp_NA, /* IeVBII_e_EpsTHASteerTrqResp */
  TeVBII_e_THASteerTouchStatus_Hands_Off,/* IeVBII_e_THASteerTouchStatus */
  TeVBII_e_EngineSts_Engine_Off,       /* IeVBII_e_EngineSts */
  TeVBII_e_EssEngState_ENS_STOPPED,    /* IeVBII_e_EssEngState */
  TeVBII_e_EcmTHAResp_Off              /* IeVBII_e_EcmTHAResp */
} ;                                    /* TbTHASmVc_InputFromVehInp_t ground */

const TbTHASmVc_InputFromProxiMgr_t THA_SWC_rtZTbTHASmVc_InputFromProxiMgr_t = {
  false,                               /* MePRX_b_CanNod63 */
  false,                               /* MePRX_b_CanNod95 */
  false,                               /* MePRX_b_ParkWithStop */
  0U,                                  /* MePRX_k_VariantId */
  TePRX_e_VehLineCfg_Invalid,          /* MePRX_e_VehLineCfg */
  false,                               /* MePRX_b_TrlrHitchAssPres */
  TePRX_e_Wheelbase_Type_2,            /* MePRX_e_Wheelbase */
  0U,                                  /* MePRX_mm_TyreSz */
  TePRX_e_SteerRatRackPinionTyp_Type_2 /* MePRX_e_SteerRatRackPinionTyp */
} ;                                   /* TbTHASmVc_InputFromProxiMgr_t ground */

/* Block signals (default storage) */
B_THA_SWC_T THA_SWC_B;

//Dipti : Logic to reset VC parameters
/*boolean_T ReInitializeTHASMVC(void)
{
  boolean_T v_Ret_t = FALSE;
  static TeTHA_e_THAStateInfo v_PrevTHAStatus_e = TeTHA_e_THAStateInfo_Initial;

  if (((TeTHA_e_THAStateInfo_Engaged         == v_PrevTHAStatus_e) ||
       (TeTHA_e_THAStateInfo_Engaged_Delta   == v_PrevTHAStatus_e) ||
       (TeTHA_e_THAStateInfo_Engaged_Inquiry == v_PrevTHAStatus_e) ||
       (TeTHA_e_THAStateInfo_Complete        == v_PrevTHAStatus_e) ||
       (TeTHA_e_THAStateInfo_Faulted         == v_PrevTHAStatus_e) ||
       (TeTHA_e_THAStateInfo_SNA             == v_PrevTHAStatus_e)) &&
       (TeTHA_e_THAStateInfo_Idle            == THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_e_THAStateInfo))
  {
    //UART_printf("Initializing THASMVC\n");
    memset(&THA_VC_Ref_B, 0, sizeof(THA_VC_Ref_B));
    memset(&THA_VC_Ref_DW, 0, sizeof(THA_VC_Ref_DW));
    memset(&THA_VC_Ref_PrevZCX, 0, sizeof(THA_VC_Ref_PrevZCX));
    //THA_SWC_initialize();
    v_Ret_t = TRUE;
  }
  
  v_PrevTHAStatus_e = THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_e_THAStateInfo;

  return v_Ret_t;
}
Code commented as it is not there in BEV*/

/*
* Name: THA_SWC_step
* Remarks: DD-ID: {AC0B1508-86E0-4b39-A6E9-4814824B70DE}
* Remarks: DD-ID: {E7AC0BFF-DB0D-4a76-873C-AE126B40A551}
*/
/* Model step function */
void THA_SWC_step(void)
{
/*
  //Dipti : Logic to reset VC parameters
  if( TRUE == ReInitializeTHASMVC())
  {
    return;
  }
Code commented as it is not there in BEV*/
  int32_T i;

  /* DataStoreRead: '<S5>/DataStoreRead9' */
  // Dipti : Moved this call to Init() as to be called only once
  //THA_SWC_B.MbTHA_VrntTunParamOut =
    //SigMgr_Data_THA_Calibration_data_MCU2_1_t_Get();

  /* DataTypeConversion: '<S4>/DataTypeConversion43' */
  memcpy(&THA_SWC_B.BusCreator7.KsTHA_deg_StrToRdWhlAngTD[0],
         &THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KsTHA_deg_StrToRdWhlAngTD[0],
         17U * sizeof(real32_T));

  /* DataTypeConversion: '<S4>/DataTypeConversion54' */
  for (i = 0; i < 6; i++) {
    THA_SWC_B.BusCreator7.KsTHA_mps_DistSpdTD[i] = (real32_T)
      THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KsTHA_mps_DistSpdTD[i];
  }

  /* End of DataTypeConversion: '<S4>/DataTypeConversion54' */

  /* DataTypeConversion: '<S4>/DataTypeConversion56' */
  for (i = 0; i < 5; i++) {
    THA_SWC_B.BusCreator7.KsTHA_k_ErrxPropGainTD[i] = (real32_T)
      THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KsTHA_k_ErrxPropGainTD[i];
  }

  /* End of DataTypeConversion: '<S4>/DataTypeConversion56' */

  /* DataTypeConversion: '<S4>/DataTypeConversion55' */
  THA_SWC_B.BusCreator7.KsTHA_k_ErrxHeadingErrTD[0] = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KsTHA_k_ErrxHeadingErrTD[0];
  THA_SWC_B.BusCreator7.KsTHA_k_ErrxHeadingErrTD[1] = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KsTHA_k_ErrxHeadingErrTD[1];
  THA_SWC_B.BusCreator7.KsTHA_k_ErrxHeadingErrTD[2] = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KsTHA_k_ErrxHeadingErrTD[2];
  THA_SWC_B.BusCreator7.KsTHA_k_ErrxHeadingErrTD[3] = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KsTHA_k_ErrxHeadingErrTD[3];

  /* DataStoreRead: '<S5>/DataStoreRead' */
  SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Get(&THA_SWC_B.MbTHA_ThaDetOut);
  
#if DEBUG_PRINTS  
UART_printf("\n %d:HStat:%d,CStat:%d,DiffLong:%d,DiffLat:%d,\t", 
counter,THA_SWC_B.MbTHA_ThaDetOut.HitchDetctStatus_e, THA_SWC_B.MbTHA_ThaDetOut.CplrDetctStatus_e, THA_SWC_B.MbTHA_ThaDetOut.HitchCplrPixDiffLongY_s32,
THA_SWC_B.MbTHA_ThaDetOut.HitchCplrPixDiffLatX_s32);
TaskP_sleepInMsecs(3);
#endif
//HardCode for Vehicle testing
//THA_SWC_B.MbTHA_ThaDetOut.CplrDetctStatus_e = e_Cplr_Detected;
// THA_SWC_B.MbTHA_ThaDetOut.HitchDetctStatus_e = e_Hitch_Detected;
// THA_SWC_B.MbTHA_ThaDetOut.HitchPix_p2d.x            = 325;
// THA_SWC_B.MbTHA_ThaDetOut.HitchPix_p2d.y            = 300;
// THA_SWC_B.MbTHA_ThaDetOut.CplrPix_p2d.x             = 325;
// THA_SWC_B.MbTHA_ThaDetOut.CplrPix_p2d.y             = 150;
// THA_SWC_B.MbTHA_ThaDetOut.HitchCplrPixDiffLongY_s32 = 150;
// THA_SWC_B.MbTHA_ThaDetOut.HitchCplrPixDiffLatX_s32  = 0;

  /* DataTypeConversion: '<S4>/DataTypeConversion3' */
  THA_SWC_B.MeTHA_px_HitchPnt[0] = (int32_T)
    THA_SWC_B.MbTHA_ThaDetOut.HitchPix_p2d.x;
  THA_SWC_B.MeTHA_px_HitchPnt[1] = (int32_T)
    THA_SWC_B.MbTHA_ThaDetOut.HitchPix_p2d.y;

  /* DataTypeConversion: '<S4>/DataTypeConversion1' */
  THA_SWC_B.MeTHA_px_CplrPnt[0] = (int32_T)
    THA_SWC_B.MbTHA_ThaDetOut.CplrPix_p2d.x;
  THA_SWC_B.MeTHA_px_CplrPnt[1] = (int32_T)
    THA_SWC_B.MbTHA_ThaDetOut.CplrPix_p2d.y;

  /* DataTypeConversion: '<S4>/DataTypeConversion14' */
  THA_SWC_B.MeTHA_e_HitchDetctStatus_i0mv = (TeTHA_e_HitchDetctStatus)
    THA_SWC_B.MbTHA_ThaDetOut.HitchDetctStatus_e;

  /* DataTypeConversion: '<S4>/DataTypeConversion46' */
  THA_SWC_B.MeTHA_e_CplrDetctStatus_dz1g = (TeTHA_e_CplrDetctStatus)
    THA_SWC_B.MbTHA_ThaDetOut.CplrDetctStatus_e;

  /* DataTypeConversion: '<S4>/DataTypeConversion5' */
  THA_SWC_B.IeVBII_a_VehLatAcc = (real32_T)THA_SWC_B.MbTHA_ThaDetOut.CplrAng_f32;

  /* DataTypeConversion: '<S4>/DataTypeConversion58' */
  THA_SWC_B.MeSVS_b_THASftBtnPrsdStsToTHA_orlw = ((int32_T)
    THA_SWC_B.MbTHA_ThaDetOut.CplrAngFound_b != 0);

  /* DataTypeConversion: '<S4>/DataTypeConversion8' */
  THA_SWC_B.KeTHA_px_HitchCplrDeltaThd2_o0fz = (int32_T)
    THA_SWC_B.MbTHA_ThaDetOut.HitchCplrPixDiffLongY_s32;

  /* DataTypeConversion: '<S4>/DataTypeConversion9' */
  THA_SWC_B.KeTHA_px_HitchCplrDeltaThd1_ifbu = (int32_T)
    THA_SWC_B.MbTHA_ThaDetOut.HitchCplrPixDiffLatX_s32;

  /* BusCreator: '<S4>/BusCreator' */
  THA_SWC_B.MbTHA_ThaDetOutData.MeTHA_e_HitchDetctStatus =
    THA_SWC_B.MeTHA_e_HitchDetctStatus_i0mv;
  THA_SWC_B.MbTHA_ThaDetOutData.MeTHA_e_CplrDetctStatus =
    THA_SWC_B.MeTHA_e_CplrDetctStatus_dz1g;
  THA_SWC_B.MbTHA_ThaDetOutData.MeTHA_deg_CplrAng = THA_SWC_B.IeVBII_a_VehLatAcc;
  THA_SWC_B.MbTHA_ThaDetOutData.MeTHA_b_CplrAngFound =
    THA_SWC_B.MeSVS_b_THASftBtnPrsdStsToTHA_orlw;
  THA_SWC_B.MbTHA_ThaDetOutData.MeTHA_px_HitchCplrPixDiffLong =
    THA_SWC_B.KeTHA_px_HitchCplrDeltaThd2_o0fz;
  THA_SWC_B.MbTHA_ThaDetOutData.MeTHA_px_HitchCplrPixDiffLat =
    THA_SWC_B.KeTHA_px_HitchCplrDeltaThd1_ifbu;
  THA_SWC_B.MbTHA_ThaDetOutData.MeTHA_px_HitchPnt[0] =
    THA_SWC_B.MeTHA_px_HitchPnt[0];
  THA_SWC_B.MbTHA_ThaDetOutData.MeTHA_px_HitchPnt[1] =
    THA_SWC_B.MeTHA_px_HitchPnt[1];
  THA_SWC_B.MbTHA_ThaDetOutData.MeTHA_px_CplrPnt[0] =
    THA_SWC_B.MeTHA_px_CplrPnt[0];
  THA_SWC_B.MbTHA_ThaDetOutData.MeTHA_px_CplrPnt[1] =
    THA_SWC_B.MeTHA_px_CplrPnt[1];

  /* DataStoreRead: '<S5>/DataStoreRead1' */
  SigMgr_PpSvsToTHA_SvsToTHA_t_Get(&THA_SWC_B.MbTHA_HmiSvsToThaOut);

#if DEBUG_PRINTS  
// UART_printf("\n %d:sftBtn:%d,Mnvr:%d,ScrTch:%d,cnfmB:%d,Zoom:%d,Cancel:%d\t", 
// counter,THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_THASftBtnPrsdStsToTHA, THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_THAMnvrStartBtnPrsd, 
// THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_THAScrTchSts,THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_IsConfirmBtnPrsd,
// THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_ViewZoomSts,THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_ImgDefeatReqSts);
//TaskP_sleepInMsecs(3);
#endif
//HardCode for Vehicle testing
  // THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_THASftBtnPrsdStsToTHA = 1;
  // THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_THAMnvrStartBtnPrsd = 1;
  // THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_THAScrTchSts = 1;
  /* DataTypeConversion: '<S4>/DataTypeConversion10' */
  THA_SWC_B.MeSVS_b_THASftBtnPrsdStsToTHA_orlw =
    THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_THASftBtnPrsdStsToTHA;

  /* DataTypeConversion: '<S4>/DataTypeConversion11' */
  THA_SWC_B.MeSVS_b_IsConfirmBtnPrsd_gvdh =
    THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_IsConfirmBtnPrsd;

  /* DataTypeConversion: '<S4>/DataTypeConversion44' */
  THA_SWC_B.MeSVS_e_THAScrResp_pelw = (TeTHA_e_ScreenRequest)
    THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_e_THAScrResp;

  /* DataTypeConversion: '<S4>/DataTypeConversion12' */
  THA_SWC_B.MeSVS_b_ImgDefeatReqSts_iwrg =
    THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_ImgDefeatReqSts;

  /* DataTypeConversion: '<S4>/DataTypeConversion13' */
  THA_SWC_B.MePRX_b_TrlrHitchAssPres =
    THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_ViewZoomSts;

  /* DataTypeConversion: '<S4>/DataTypeConversion83' */
  THA_SWC_B.MeTHA_b_FidDLDAbort_jpzk =
    THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_THAMnvrStartBtnPrsd;

  /* DataTypeConversion: '<S4>/DataTypeConversion85' */
  THA_SWC_B.MeTHA_b_FidCamCalAbort_oxnw =
    THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_THAScrTchSts;

  /* DataTypeConversion: '<S4>/DataTypeConversion6' */
  THA_SWC_B.KeTHA_b_Valid = THA_SWC_B.MbTHA_HmiSvsToThaOut.MeSVS_b_THAAbortReq;

  /* DataStoreRead: '<S5>/DataStoreRead8' */
  SigMgr_PpSvsToVCAN_SvsToVCAN_t_Get(&THA_SWC_B.MbTHA_HmiSvsToVcanOut);
//HardCode for Vehicle testing
  //THA_SWC_B.MbTHA_HmiSvsToVcanOut.IeSVS_e_DispView2 = DisplayView2_View1;

  /* DataTypeConversion: '<S4>/DataTypeConversion42' */
  THA_SWC_B.IeSVS_e_DispView2 = (TeSVS_e_DispView2)
    THA_SWC_B.MbTHA_HmiSvsToVcanOut.IeSVS_e_DispView2;

  /* BusCreator: '<S4>/BusCreator1' */
  THA_SWC_B.MbTHA_HmiSvsOutData.MeSVS_b_THASftBtnPrsdStsToTHA =
    THA_SWC_B.MeSVS_b_THASftBtnPrsdStsToTHA_orlw;
  THA_SWC_B.MbTHA_HmiSvsOutData.MeSVS_b_IsConfirmBtnPrsd =
    THA_SWC_B.MeSVS_b_IsConfirmBtnPrsd_gvdh;
  THA_SWC_B.MbTHA_HmiSvsOutData.MeSVS_e_THAScrResp =
    THA_SWC_B.MeSVS_e_THAScrResp_pelw;
  THA_SWC_B.MbTHA_HmiSvsOutData.MeSVS_b_ImgDefeatReqSts =
    THA_SWC_B.MeSVS_b_ImgDefeatReqSts_iwrg;
  THA_SWC_B.MbTHA_HmiSvsOutData.MeSVS_b_ViewZoomSts =
    THA_SWC_B.MePRX_b_TrlrHitchAssPres;
  THA_SWC_B.MbTHA_HmiSvsOutData.MeSVS_b_THAMnvrStartBtnPrsd =
    THA_SWC_B.MeTHA_b_FidDLDAbort_jpzk;
  THA_SWC_B.MbTHA_HmiSvsOutData.MeSVS_b_THAScrTchSts =
    THA_SWC_B.MeTHA_b_FidCamCalAbort_oxnw;
  THA_SWC_B.MbTHA_HmiSvsOutData.MeSVS_b_THAAbortReq = THA_SWC_B.KeTHA_b_Valid;
  THA_SWC_B.MbTHA_HmiSvsOutData.IeSVS_e_DispView2 = THA_SWC_B.IeSVS_e_DispView2;

  /* DataStoreRead: '<S5>/DataStoreRead3' */
  SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Get(&THA_SWC_B.MbTHA_ApSmOut);

  /* DataTypeConversion: '<S4>/DataTypeConversion45' */
  THA_SWC_B.IeAP_e_FrntRearParkSts = (TeAP_e_FrntRearParkSts)
    THA_SWC_B.MbTHA_ApSmOut.IeAP_e_FrntRearParkSts;

  /* DataStoreRead: '<S5>/DataStoreRead5' */
  SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Get(&THA_SWC_B.MbTHA_ApDaOut);

  /* DataTypeConversion: '<S4>/DataTypeConversion15' */
  THA_SWC_B.IeAP_e_AutoParkStatus = (TeAP_e_AutoParkStatus)
    THA_SWC_B.MbTHA_ApDaOut.IeAP_e_AutoParkStatus;

  /* BusCreator: '<S4>/BusCreator2' */
  THA_SWC_B.MbTHA_ApSmOutData.IeAP_e_FrntRearParkSts =
    THA_SWC_B.IeAP_e_FrntRearParkSts;
  THA_SWC_B.MbTHA_ApSmOutData.IeAP_e_AutoParkStatus =
    THA_SWC_B.IeAP_e_AutoParkStatus;

  /* DataStoreRead: '<S5>/DataStoreRead2' */
  SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(&THA_SWC_B.MbTHA_VehInpOut);

  /* DataTypeConversion: '<S4>/DataTypeConversion40' */
  THA_SWC_B.KeTHA_b_Valid = ((int32_T)
    THA_SWC_B.MbTHA_VehInpOut.CAN2_to_IPC.DataInp_BCM_FD_9.DriverDoorSts != 0);

  /* DataTypeConversion: '<S4>/DataTypeConversion39' */
  THA_SWC_B.MeTHA_b_FidCamCalAbort_oxnw = ((int32_T)
    THA_SWC_B.MbTHA_VehInpOut.CAN2_to_IPC.DataInp_BCM_FD_9.RHatchSts != 0);

  /* DataTypeConversion: '<S4>/DataTypeConversion2' */
  THA_SWC_B.IeVBII_e_CmdIgnSts = (TeVBII_e_CmdIgnSts)
    THA_SWC_B.MbTHA_VehInpOut.CAN2_to_IPC.DataInp_BCM_FD_10.CmdIgnSts;

  /* DataTypeConversion: '<S4>/DataTypeConversion4' */
  THA_SWC_B.IeVBII_e_TrailerConnectionSts = (TeVBII_e_TrailerConnectionSts)
    THA_SWC_B.MbTHA_VehInpOut.CAN2_to_IPC.DataInp_BCM_FD_27.TrailerConnectionSts;

  /* DataTypeConversion: '<S4>/DataTypeConversion47' */
  THA_SWC_B.IeVBII_e_TrlrPrsntSts = (TeVBII_e_TrlrPrsntSts)
    THA_SWC_B.MbTHA_VehInpOut.CAN2_to_IPC.DataInp_BCM_FD_29.ITBM_TrlrStat;

  /* DataTypeConversion: '<S4>/DataTypeConversion53' */
  THA_SWC_B.IeVBII_e_TchScrSts = (TeVBII_e_TchScrSts)
    THA_SWC_B.MbTHA_VehInpOut.CAN2_to_IPC.DataInp_TELEMATIC_FD_5.CM_TCH_STAT;

  /* DataTypeConversion: '<S4>/DataTypeConversion112' */
  THA_SWC_B.IeVBII_e_GearEngagedForDsply = (TeVBII_e_GearEngagedForDsply)
    THA_SWC_B.MbTHA_VehInpOut.CAN2_to_IPC.DataInp_TRANSM_FD_2.GearEngagedForDisplay;

  /* DataTypeConversion: '<S4>/DataTypeConversion111' */
  THA_SWC_B.IeVBII_e_VehStandStillSts = (TeVBII_e_VehStandStillSts)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_1.FD14_VehicleStandStillSts;

  /* DataTypeConversion: '<S4>/DataTypeConversion18' */
  THA_SWC_B.IeVBII_a_VehLatAcc = (real32_T)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_LatAcceleration_BSM;

  /* DataTypeConversion: '<S4>/DataTypeConversion19' */
  THA_SWC_B.IeVBII_a_VehLongAcc = (real32_T)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_LongAcceleration_BSM;

  /* DataTypeConversion: '<S4>/DataTypeConversion20' */
  THA_SWC_B.KeTHA_m_WhlCircumference_p23o = (real32_T)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_YawRate_BSM;

  /* DataTypeConversion: '<S4>/DataTypeConversion21' */
  THA_SWC_B.KeTHA_k_HeadingErrGain_hve4 = (real32_T)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig;

  /* DataTypeConversion: '<S4>/DataTypeConversion22' */
  THA_SWC_B.IeVBII_cnt_LhfPulseCtr =
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHF_FastPulseCounter;

  /* DataTypeConversion: '<S4>/DataTypeConversion87' */
  THA_SWC_B.IeVBII_e_LhfWhlSpnSts = (TeVBII_e_WhlSpnSts)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHF_Spin;

  /* DataTypeConversion: '<S4>/DataTypeConversion24' */
  THA_SWC_B.KeTHA_k_TrqCtrlFiltCoef_h2g4 = (real32_T)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHFWheelSpeed;

  /* DataTypeConversion: '<S4>/DataTypeConversion25' */
  THA_SWC_B.IeVBII_cnt_LhrPulseCtr =
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHR_FastPulseCounter;

  /* DataTypeConversion: '<S4>/DataTypeConversion90' */
  THA_SWC_B.IeVBII_e_LhrWhlSpnSts = (TeVBII_e_WhlSpnSts)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHR_Spin;

  /* DataTypeConversion: '<S4>/DataTypeConversion27' */
  THA_SWC_B.KeTHA_k_TrqCtrlKd_fhal = (real32_T)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHRWheelSpeed;

  /* DataTypeConversion: '<S4>/DataTypeConversion28' */
  THA_SWC_B.IeVBII_cnt_RhfPulseCtr =
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHF_FastPulseCounter;

  /* DataTypeConversion: '<S4>/DataTypeConversion93' */
  THA_SWC_B.IeVBII_e_RhfWhlSpnSts = (TeVBII_e_WhlSpnSts)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHF_Spin;

  /* DataTypeConversion: '<S4>/DataTypeConversion30' */
  THA_SWC_B.KeTHA_k_TrqCtrlKi_obwj = (real32_T)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHFWheelSpeed;

  /* DataTypeConversion: '<S4>/DataTypeConversion31' */
  THA_SWC_B.MePRX_k_VariantId =
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHR_FastPulseCounter;

  /* DataTypeConversion: '<S4>/DataTypeConversion96' */
  THA_SWC_B.IeVBII_e_RhrWhlSpnSts = (TeVBII_e_WhlSpnSts)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHR_Spin;

  /* DataTypeConversion: '<S4>/DataTypeConversion33' */
  THA_SWC_B.KeTHA_k_TrqCtrlKp_bi22 = (real32_T)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHRWheelSpeed;

  /* DataTypeConversion: '<S4>/DataTypeConversion34' */
  THA_SWC_B.KeTHA_k_SteerTrqCtrlFiltCoef_pwgq = (real32_T)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LatAccelerationOffset_BSM;

  /* DataTypeConversion: '<S4>/DataTypeConversion35' */
  THA_SWC_B.KeTHA_k_SteerTrqCtrlKd_pnpi = (real32_T)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LongAccelerationOffset_BSM;

  /* DataTypeConversion: '<S4>/DataTypeConversion116' */
  THA_SWC_B.IeVBII_e_VehEPBSts = (TeVBII_e_VehEPBSts)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_4.FD14_EPBSts;

  /* DataTypeConversion: '<S4>/DataTypeConversion109' */
  THA_SWC_B.IeVBII_e_BsmTHABrkResp = (TeVBII_e_BsmTHABrkResp)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_5.FD14_BSM_THA_Brk_Resp;

  /* DataTypeConversion: '<S4>/DataTypeConversion36' */
  THA_SWC_B.KeTHA_k_SteerTrqCtrlKi_hrlm = (real32_T)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle;

  /* DataTypeConversion: '<S4>/DataTypeConversion57' */
  THA_SWC_B.KeTHA_k_SteerTrqCtrlKp_ndhb = (real32_T)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsSpeed;

  /* DataTypeConversion: '<S4>/DataTypeConversion101' */
  THA_SWC_B.IeVBII_e_LwsAngleType = (TeVBII_e_LwsAngleType)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngleType;

  /* DataTypeConversion: '<S4>/DataTypeConversion113' */
  THA_SWC_B.IeVBII_e_EpsTHADrvTrqOvrd = (TeVBII_e_EpsTHADrvTrqOvrd)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_EPS_FD_2.FD14_EPS_THA_DriverTorqueOverride;

  /* DataTypeConversion: '<S4>/DataTypeConversion114' */
  THA_SWC_B.IeVBII_e_EpsTHASteerTrqResp = (TeVBII_e_EpsTHASteerTrqResp)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_EPS_FD_2.FD14_EPS_THA_SteeringTorqueResp;

  /* DataTypeConversion: '<S4>/DataTypeConversion115' */
  THA_SWC_B.IeVBII_e_THASteerTouchStatus = (TeVBII_e_THASteerTouchStatus)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_EPS_FD_2.FD14_THA_SteeringTouchStat;

  /* DataTypeConversion: '<S4>/DataTypeConversion102' */
  THA_SWC_B.IeVBII_e_EngineSts = (TeVBII_e_EngineSts)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_ENGINE_FD_2.FD14_EngineSts_W;

  /* DataTypeConversion: '<S4>/DataTypeConversion105' */
  THA_SWC_B.IeVBII_e_EssEngState = (TeVBII_e_EssEngState)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_ENGINE_FD_2.FD14_ESS_ENG_ST_W;

  /* DataTypeConversion: '<S4>/DataTypeConversion108' */
  THA_SWC_B.IeVBII_e_EcmTHAResp = (TeVBII_e_EcmTHAResp)
    THA_SWC_B.MbTHA_VehInpOut.CAN14_to_IPC.DataInp_FD14_ENGINE_FD_7.FD14_ECM_THA_Resp;

  /* BusCreator: '<S4>/BusCreator3' */
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_b_DriverDoorSts = THA_SWC_B.KeTHA_b_Valid;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_b_TrnkStatus =
    THA_SWC_B.MeTHA_b_FidCamCalAbort_oxnw;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_CmdIgnSts =
    THA_SWC_B.IeVBII_e_CmdIgnSts;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_TrailerConnectionSts =
    THA_SWC_B.IeVBII_e_TrailerConnectionSts;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_TrlrPrsntSts =
    THA_SWC_B.IeVBII_e_TrlrPrsntSts;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_TchScrSts =
    THA_SWC_B.IeVBII_e_TchScrSts;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_GearEngagedForDsply =
    THA_SWC_B.IeVBII_e_GearEngagedForDsply;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_VehStandStillSts =
    THA_SWC_B.IeVBII_e_VehStandStillSts;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_a_VehLatAcc =
    THA_SWC_B.IeVBII_a_VehLatAcc;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_a_VehLongAcc =
    THA_SWC_B.IeVBII_a_VehLongAcc;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_ddeg_VehYawRate =
    THA_SWC_B.KeTHA_m_WhlCircumference_p23o;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_kph_VehSpeedVSOSig =
    THA_SWC_B.KeTHA_k_HeadingErrGain_hve4;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_cnt_LhfPulseCtr =
    THA_SWC_B.IeVBII_cnt_LhfPulseCtr;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_LhfWhlSpnSts =
    THA_SWC_B.IeVBII_e_LhfWhlSpnSts;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_kph_LhfWhlSpd =
    THA_SWC_B.KeTHA_k_TrqCtrlFiltCoef_h2g4;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_cnt_LhrPulseCtr =
    THA_SWC_B.IeVBII_cnt_LhrPulseCtr;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_LhrWhlSpnSts =
    THA_SWC_B.IeVBII_e_LhrWhlSpnSts;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_kph_LhrWhlSpd =
    THA_SWC_B.KeTHA_k_TrqCtrlKd_fhal;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_cnt_RhfPulseCtr =
    THA_SWC_B.IeVBII_cnt_RhfPulseCtr;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_RhfWhlSpnSts =
    THA_SWC_B.IeVBII_e_RhfWhlSpnSts;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_kph_RhfWhlSpd =
    THA_SWC_B.KeTHA_k_TrqCtrlKi_obwj;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_cnt_RhrPulseCtr =
    THA_SWC_B.MePRX_k_VariantId;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_RhrWhlSpnSts =
    THA_SWC_B.IeVBII_e_RhrWhlSpnSts;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_kph_RhrWhlSpd =
    THA_SWC_B.KeTHA_k_TrqCtrlKp_bi22;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_a_VehLatAccOffset =
    THA_SWC_B.KeTHA_k_SteerTrqCtrlFiltCoef_pwgq;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_a_VehLongAccOffset =
    THA_SWC_B.KeTHA_k_SteerTrqCtrlKd_pnpi;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_VehEPBSts =
    THA_SWC_B.IeVBII_e_VehEPBSts;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_BsmTHABrkResp =
    THA_SWC_B.IeVBII_e_BsmTHABrkResp;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_deg_StrWhlAng =
    THA_SWC_B.KeTHA_k_SteerTrqCtrlKi_hrlm;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_ddeg_StrWhlSpd =
    THA_SWC_B.KeTHA_k_SteerTrqCtrlKp_ndhb;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_LwsAngleType =
    THA_SWC_B.IeVBII_e_LwsAngleType;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_EpsTHADrvTrqOvrd =
    THA_SWC_B.IeVBII_e_EpsTHADrvTrqOvrd;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_EpsTHASteerTrqResp =
    THA_SWC_B.IeVBII_e_EpsTHASteerTrqResp;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_THASteerTouchStatus =
    THA_SWC_B.IeVBII_e_THASteerTouchStatus;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_EngineSts =
    THA_SWC_B.IeVBII_e_EngineSts;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_EssEngState =
    THA_SWC_B.IeVBII_e_EssEngState;
  THA_SWC_B.MbTHA_VehInpOutData.IeVBII_e_EcmTHAResp =
    THA_SWC_B.IeVBII_e_EcmTHAResp;

  /* DataStoreRead: '<S5>/DataStoreRead4' */
  static bool_t validProxyReceived_b = FALSE;
  if (FALSE == validProxyReceived_b)
  {
    SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Get(&THA_SWC_B.MbTHA_ProxiMgrOut);
    if (TRUE == THA_SWC_B.MbTHA_ProxiMgrOut.PRX_bValid_b)
    {
      validProxyReceived_b = TRUE;
    }
  }
  
#if DEBUG_PRINTS
// UART_printf("\n %d:CanNod63:%d,CanNod95:%d,PrxTHA:%d\t", 
// counter,THA_SWC_B.MbTHA_ProxiMgrOut.PRX_CanNod63_b,THA_SWC_B.MbTHA_ProxiMgrOut.PRX_CanNod95_b,THA_SWC_B.MbTHA_ProxiMgrOut.PRX_TrlrHitchAssPres_b);
// TaskP_sleepInMsecs(3);
#endif
//HardCode for Vehicle testing
//THA_SWC_B.MbTHA_ProxiMgrOut.PRX_CanNod63_b = 1;
//THA_SWC_B.MbTHA_ProxiMgrOut.PRX_TrlrHitchAssPres_b = 1;

  /* DataTypeConversion: '<S4>/DataTypeConversion70' */
  THA_SWC_B.KeTHA_b_Valid = THA_SWC_B.MbTHA_ProxiMgrOut.PRX_CanNod63_b;

  /* DataTypeConversion: '<S4>/DataTypeConversion71' */
  THA_SWC_B.MeTHA_b_FidCamCalAbort_oxnw =
    THA_SWC_B.MbTHA_ProxiMgrOut.PRX_CanNod95_b;

  /* DataTypeConversion: '<S4>/DataTypeConversion48' */
  THA_SWC_B.MeTHA_b_FidDLDAbort_jpzk =
    THA_SWC_B.MbTHA_ProxiMgrOut.PRX_ParkWithStop_b;

  /* DataTypeConversion: '<S4>/DataTypeConversion75' */
  THA_SWC_B.MePRX_k_VariantId = THA_SWC_B.MbTHA_ProxiMgrOut.PRX_variantID_u8;

  /* DataTypeConversion: '<S4>/DataTypeConversion76' */
  THA_SWC_B.MePRX_e_VehLineCfg = (TePRX_e_VehLineCfg)
    THA_SWC_B.MbTHA_ProxiMgrOut.PRX_VehLineCfg_u8;

  /* DataTypeConversion: '<S4>/DataTypeConversion77' */
  THA_SWC_B.MePRX_b_TrlrHitchAssPres =
    THA_SWC_B.MbTHA_ProxiMgrOut.PRX_TrlrHitchAssPres_b;

  /* DataTypeConversion: '<S4>/DataTypeConversion78' */
  THA_SWC_B.MePRX_e_Wheelbase = (TePRX_e_Wheelbase)
    THA_SWC_B.MbTHA_ProxiMgrOut.PRX_Wheelbase_u8;

  /* DataTypeConversion: '<S4>/DataTypeConversion79' */
  THA_SWC_B.KeTHA_ddeg_StrRateLimFinal_asrp =
    THA_SWC_B.MbTHA_ProxiMgrOut.PRX_TyreSz_u16;

  /* DataTypeConversion: '<S4>/DataTypeConversion80' */
  THA_SWC_B.MePRX_e_SteerRatRackPinionTyp = (TePRX_e_SteerRatRackPinionTyp)
    THA_SWC_B.MbTHA_ProxiMgrOut.PRX_StrRatRckPinionTyp_u8;

  /* BusCreator: '<S4>/BusCreator4' */
  THA_SWC_B.MbTHA_ProxiMgrOutData.MePRX_b_CanNod63 = THA_SWC_B.KeTHA_b_Valid;
  THA_SWC_B.MbTHA_ProxiMgrOutData.MePRX_b_CanNod95 =
    THA_SWC_B.MeTHA_b_FidCamCalAbort_oxnw;
  THA_SWC_B.MbTHA_ProxiMgrOutData.MePRX_b_ParkWithStop =
    THA_SWC_B.MeTHA_b_FidDLDAbort_jpzk;
  THA_SWC_B.MbTHA_ProxiMgrOutData.MePRX_k_VariantId =
    THA_SWC_B.MePRX_k_VariantId;
  THA_SWC_B.MbTHA_ProxiMgrOutData.MePRX_e_VehLineCfg =
    THA_SWC_B.MePRX_e_VehLineCfg;
  THA_SWC_B.MbTHA_ProxiMgrOutData.MePRX_b_TrlrHitchAssPres =
    THA_SWC_B.MePRX_b_TrlrHitchAssPres;
  THA_SWC_B.MbTHA_ProxiMgrOutData.MePRX_e_Wheelbase =
    THA_SWC_B.MePRX_e_Wheelbase;
  THA_SWC_B.MbTHA_ProxiMgrOutData.MePRX_mm_TyreSz =
    THA_SWC_B.KeTHA_ddeg_StrRateLimFinal_asrp;
  THA_SWC_B.MbTHA_ProxiMgrOutData.MePRX_e_SteerRatRackPinionTyp =
    THA_SWC_B.MePRX_e_SteerRatRackPinionTyp;

  /* DataStoreRead: '<S5>/DataStoreRead6' */
  SigMgr_PpTRSC_ME_VehOut_TRSC_t_Get(&THA_SWC_B.MbTHA_TrscSmVcOut);

  /* DataTypeConversion: '<S4>/DataTypeConversion16' */
  THA_SWC_B.IeTRSC_e_TRSCSts = THA_SWC_B.MbTHA_TrscSmVcOut.IeTRSC_e_TRSCSts;

  /* BusCreator: '<S4>/BusCreator6' */
  THA_SWC_B.MbTHA_TrscSmVcOutData.IeTRSC_e_TRSCSts = THA_SWC_B.IeTRSC_e_TRSCSts;

  /* DataStoreRead: '<S5>/DataStoreRead7' */
  SigMgr_Data_FID_STRUCT_QM_Get(&THA_SWC_B.MbTHA_DegMgrFIDOut);
  #if DEBUG_PRINTS
  // UART_printf("\n %d:FidDisabled:%d,FidCamAbort:%d\t", counter,THA_SWC_B.MbTHA_DegMgrFIDOut.m_QM_FID_THA_DISABLED,THA_SWC_B.MbTHA_DegMgrFIDOut.m_QM_FID_THA_CAM_CAL_ABORT);
  // TaskP_sleepInMsecs(5);
  #endif
  //HardCode for Vehicle testing
  //THA_SWC_B.MbTHA_DegMgrFIDOut.m_QM_FID_THA_DISABLED = 0;
  //THA_SWC_B.MbTHA_DegMgrFIDOut.m_QM_FID_THA_CAM_CAL_ABORT = 0;
  //THA_SWC_B.MbTHA_DegMgrFIDOut.m_QM_FID_THA_DLD_ABORT = 0;
  
  /* DataTypeConversion: '<S4>/DataTypeConversion26' */
  THA_SWC_B.KeTHA_b_Valid = ((int32_T)
    THA_SWC_B.MbTHA_DegMgrFIDOut.m_QM_FID_THA_DISABLED != 0);

  /* DataTypeConversion: '<S4>/DataTypeConversion29' */
  THA_SWC_B.MeTHA_b_FidCamCalAbort_oxnw = ((int32_T)
    THA_SWC_B.MbTHA_DegMgrFIDOut.m_QM_FID_THA_CAM_CAL_ABORT != 0);

  /* DataTypeConversion: '<S4>/DataTypeConversion23' */
  THA_SWC_B.MeTHA_b_FidDLDAbort_jpzk = ((int32_T)
    THA_SWC_B.MbTHA_DegMgrFIDOut.m_QM_FID_THA_DLD_ABORT != 0);

  /* BusCreator: '<S4>/BusCreator5' */
  THA_SWC_B.MbTHA_DegradMgrOutData.MeTHA_b_FidDisabled = THA_SWC_B.KeTHA_b_Valid;
  THA_SWC_B.MbTHA_DegradMgrOutData.MeTHA_b_FidCamCalAbort =
    THA_SWC_B.MeTHA_b_FidCamCalAbort_oxnw;
  THA_SWC_B.MbTHA_DegradMgrOutData.MeTHA_b_FidDLDAbort =
    THA_SWC_B.MeTHA_b_FidDLDAbort_jpzk;

  /* DataTypeConversion: '<S4>/DataTypeConversion32' */
  THA_SWC_B.KeTHA_px_HitchCplrDeltaThd1_ifbu = (int32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_px_HitchCplrDeltaThd1;

  /* DataTypeConversion: '<S4>/DataTypeConversion17' */
  THA_SWC_B.KeTHA_px_HitchCplrDeltaThd2_o0fz = (int32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_px_HitchCplrDeltaThd2;

  /* DataTypeConversion: '<S4>/DataTypeConversion38' */
  THA_SWC_B.BusCreator7.KeTHA_px_RearBrkSuppDist = (int32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_px_RearBrkSuppDist;

  /* DataTypeConversion: '<S4>/DataTypeConversion49' */
  THA_SWC_B.KeTHA_k_SteerTrqCtrlKp_ndhb = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_k_SteerTrqCtrlKp;

  /* DataTypeConversion: '<S4>/DataTypeConversion50' */
  THA_SWC_B.KeTHA_k_SteerTrqCtrlKi_hrlm = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_k_SteerTrqCtrlKi;

  /* DataTypeConversion: '<S4>/DataTypeConversion51' */
  THA_SWC_B.KeTHA_k_SteerTrqCtrlKd_pnpi = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_k_SteerTrqCtrlKd;

  /* DataTypeConversion: '<S4>/DataTypeConversion52' */
  THA_SWC_B.KeTHA_k_SteerTrqCtrlFiltCoef_pwgq = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_k_SteerTrqCtrlFiltCoef;

  /* DataTypeConversion: '<S4>/DataTypeConversion63' */
  THA_SWC_B.KeTHA_k_TrqCtrlKp_bi22 = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_k_TrqCtrlKp;

  /* DataTypeConversion: '<S4>/DataTypeConversion64' */
  THA_SWC_B.KeTHA_k_TrqCtrlKi_obwj = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_k_TrqCtrlKi;

  /* DataTypeConversion: '<S4>/DataTypeConversion65' */
  THA_SWC_B.KeTHA_k_TrqCtrlKd_fhal = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_k_TrqCtrlKd;

  /* DataTypeConversion: '<S4>/DataTypeConversion66' */
  THA_SWC_B.KeTHA_k_TrqCtrlFiltCoef_h2g4 = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_k_TrqCtrlFiltCoef;

  /* DataTypeConversion: '<S4>/DataTypeConversion86' */
  THA_SWC_B.KeTHA_ddeg_StrRateLimFinal_asrp =
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_ddeg_StrRateLimFinal;

  /* DataTypeConversion: '<S4>/DataTypeConversion88' */
  THA_SWC_B.BusCreator7.KeTHA_ddeg_StrRateLimInit =
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_ddeg_StrRateLimInit;

  /* DataTypeConversion: '<S4>/DataTypeConversion7' */
  THA_SWC_B.KeTHA_k_HeadingErrGain_hve4 = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_k_HeadingErrGain;

  /* DataTypeConversion: '<S4>/DataTypeConversion89' */
  THA_SWC_B.KeTHA_m_WhlCircumference_p23o = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_m_WhlCircumference;

  /* BusCreator: '<S4>/BusCreator7' incorporates:
   *  Constant: '<S4>/Constant18'
   *  Constant: '<S4>/Constant19'
   */
  THA_SWC_B.BusCreator7.KeTHA_px_HitchCplrDeltaThd1 =
    THA_SWC_B.KeTHA_px_HitchCplrDeltaThd1_ifbu;
  THA_SWC_B.BusCreator7.KeTHA_px_HitchCplrDeltaThd2 =
    THA_SWC_B.KeTHA_px_HitchCplrDeltaThd2_o0fz;
  THA_SWC_B.BusCreator7.KeTHA_M_SteerTweakTrq = KeTHA_M_SteerTweakTrq;
  THA_SWC_B.BusCreator7.KeTHA_s_SteerTweakTime = KeTHA_s_SteerTweakTime;
  THA_SWC_B.BusCreator7.KeTHA_k_SteerTrqCtrlKp =
    THA_SWC_B.KeTHA_k_SteerTrqCtrlKp_ndhb;
  THA_SWC_B.BusCreator7.KeTHA_k_SteerTrqCtrlKi =
    THA_SWC_B.KeTHA_k_SteerTrqCtrlKi_hrlm;
  THA_SWC_B.BusCreator7.KeTHA_k_SteerTrqCtrlKd =
    THA_SWC_B.KeTHA_k_SteerTrqCtrlKd_pnpi;
  THA_SWC_B.BusCreator7.KeTHA_k_SteerTrqCtrlFiltCoef =
    THA_SWC_B.KeTHA_k_SteerTrqCtrlFiltCoef_pwgq;
  THA_SWC_B.BusCreator7.KeTHA_k_TrqCtrlKp = THA_SWC_B.KeTHA_k_TrqCtrlKp_bi22;
  THA_SWC_B.BusCreator7.KeTHA_k_TrqCtrlKi = THA_SWC_B.KeTHA_k_TrqCtrlKi_obwj;
  THA_SWC_B.BusCreator7.KeTHA_k_TrqCtrlKd = THA_SWC_B.KeTHA_k_TrqCtrlKd_fhal;
  THA_SWC_B.BusCreator7.KeTHA_k_TrqCtrlFiltCoef =
    THA_SWC_B.KeTHA_k_TrqCtrlFiltCoef_h2g4;
  THA_SWC_B.BusCreator7.KeTHA_ddeg_StrRateLimFinal =
    THA_SWC_B.KeTHA_ddeg_StrRateLimFinal_asrp;
  THA_SWC_B.BusCreator7.KeTHA_k_HeadingErrGain =
    THA_SWC_B.KeTHA_k_HeadingErrGain_hve4;
  THA_SWC_B.BusCreator7.KeTHA_m_WhlCircumference =
    THA_SWC_B.KeTHA_m_WhlCircumference_p23o;

  /* DataTypeConversion: '<S4>/DataTypeConversion95' */
  THA_SWC_B.KeTHA_b_Valid = ((int32_T)THA_SWC_B.MbTHA_VrntTunParamOut.bValid !=
    0);

  /* BusCreator: '<S4>/BusCreator8' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant10'
   *  Constant: '<S4>/Constant11'
   *  Constant: '<S4>/Constant12'
   *  Constant: '<S4>/Constant13'
   *  Constant: '<S4>/Constant14'
   *  Constant: '<S4>/Constant15'
   *  Constant: '<S4>/Constant16'
   *  Constant: '<S4>/Constant17'
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant28'
   *  Constant: '<S4>/Constant29'
   *  Constant: '<S4>/Constant3'
   *  Constant: '<S4>/Constant30'
   *  Constant: '<S4>/Constant4'
   *  Constant: '<S4>/Constant5'
   *  Constant: '<S4>/Constant6'
   *  Constant: '<S4>/Constant7'
   *  Constant: '<S4>/Constant8'
   *  Constant: '<S4>/Constant9'
   */
  THA_SWC_B.BusCreator8.KeTHA_px_HitchCplrDeltaThd1 =
    KeTHA_px_HitchCplrDeltaThd1;
  THA_SWC_B.BusCreator8.KeTHA_px_HitchCplrDeltaThd2 =
    KeTHA_px_HitchCplrDeltaThd2;
  THA_SWC_B.BusCreator8.KeTHA_px_RearBrkSuppDist = KeTHA_px_RearBrkSuppDist;
  THA_SWC_B.BusCreator8.KeTHA_M_SteerTweakTrq = KeTHA_M_SteerTweakTrq;
  THA_SWC_B.BusCreator8.KeTHA_s_SteerTweakTime = KeTHA_s_SteerTweakTime;
  THA_SWC_B.BusCreator8.KeTHA_k_SteerTrqCtrlKp = KeTHA_k_SteerTrqCtrlKp;
  THA_SWC_B.BusCreator8.KeTHA_k_SteerTrqCtrlKi = KeTHA_k_SteerTrqCtrlKi;
  THA_SWC_B.BusCreator8.KeTHA_k_SteerTrqCtrlKd = KeTHA_k_SteerTrqCtrlKd;
  THA_SWC_B.BusCreator8.KeTHA_k_SteerTrqCtrlFiltCoef =
    KeTHA_k_SteerTrqCtrlFiltCoef;
  THA_SWC_B.BusCreator8.KeTHA_k_TrqCtrlKp = KeTHA_k_TrqCtrlKp;
  THA_SWC_B.BusCreator8.KeTHA_k_TrqCtrlKi = KeTHA_k_TrqCtrlKi;
  THA_SWC_B.BusCreator8.KeTHA_k_TrqCtrlKd = KeTHA_k_TrqCtrlKd;
  THA_SWC_B.BusCreator8.KeTHA_k_TrqCtrlFiltCoef = KeTHA_k_TrqCtrlFiltCoef;
  THA_SWC_B.BusCreator8.KeTHA_ddeg_StrRateLimFinal = KeTHA_ddeg_StrRateLimFinal;
  THA_SWC_B.BusCreator8.KeTHA_ddeg_StrRateLimInit = KeTHA_ddeg_StrRateLimInit;
  THA_SWC_B.BusCreator8.KeTHA_k_HeadingErrGain = KeTHA_k_HeadingErrGain;
  THA_SWC_B.BusCreator8.KeTHA_m_WhlCircumference = KeTHA_m_WhlCircumference;
  memcpy(&THA_SWC_B.BusCreator8.KsTHA_deg_StrToRdWhlAngTD[0], ((real32_T *)
          &(KsTHA_deg_StrToRdWhlAngTD[0])), 17U * sizeof(real32_T));
  for (i = 0; i < 6; i++) {
    THA_SWC_B.BusCreator8.KsTHA_mps_DistSpdTD[i] = KsTHA_mps_DistSpdTD[i];
  }

  THA_SWC_B.BusCreator8.KsTHA_k_ErrxHeadingErrTD[0] = KsTHA_k_ErrxHeadingErrTD[0];
  THA_SWC_B.BusCreator8.KsTHA_k_ErrxHeadingErrTD[1] = KsTHA_k_ErrxHeadingErrTD[1];
  THA_SWC_B.BusCreator8.KsTHA_k_ErrxHeadingErrTD[2] = KsTHA_k_ErrxHeadingErrTD[2];
  THA_SWC_B.BusCreator8.KsTHA_k_ErrxHeadingErrTD[3] = KsTHA_k_ErrxHeadingErrTD[3];
  for (i = 0; i < 5; i++) {
    THA_SWC_B.BusCreator8.KsTHA_k_ErrxPropGainTD[i] = KsTHA_k_ErrxPropGainTD[i];
  }

  /* End of BusCreator: '<S4>/BusCreator8' */

  /* Switch: '<S4>/Switch' */
  // Dipti: Valid flag to be set 0 when calib data is to be disabled for testing
  //THA_SWC_B.KeTHA_b_Valid = 0;
  if (THA_SWC_B.KeTHA_b_Valid) {
    THA_SWC_B.MbTHA_VrntTunParamOutData = THA_SWC_B.BusCreator7;
  } else {
    THA_SWC_B.MbTHA_VrntTunParamOutData = THA_SWC_B.BusCreator8;
  }

  /* End of Switch: '<S4>/Switch' */

  /* ModelReference: '<Root>/THA_SmVc_Ref' */
  THA_SmVc_Ref(&THA_SWC_B.MbTHA_ThaDetOutData, &THA_SWC_B.MbTHA_HmiSvsOutData,
               &THA_SWC_B.MbTHA_ApSmOutData, &THA_SWC_B.MbTHA_VehInpOutData,
               &THA_SWC_B.MbTHA_ProxiMgrOutData,
               &THA_SWC_B.MbTHA_TrscSmVcOutData,
               &THA_SWC_B.MbTHA_DegradMgrOutData,
               &THA_SWC_B.MbTHA_VrntTunParamOutData, &THA_SWC_B.IeTHA_e_THAState,
               &THA_SWC_B.IeTHA_e_THASpdLimReq, &THA_SWC_B.IeTHA_e_PamVol,
               &THA_SWC_B.IeTHA_b_ChimeActvLhf, &THA_SWC_B.IeTHA_b_ChimeActvRhf,
               &THA_SWC_B.IeTHA_b_ChimeActvLhr, &THA_SWC_B.IeTHA_b_ChimeActvRhr,
               &THA_SWC_B.IeTHA_e_PamChimeTyp,
               &THA_SWC_B.IeTHA_e_PamChimeRepRateSts,
               &THA_SWC_B.IeTHA_e_THASteerTrqReq,
               &THA_SWC_B.IeTHA_e_THARmpUpDwnSpd,
               &THA_SWC_B.IeTHA_M_THASteerTrqInfo, &THA_SWC_B.IeTHA_e_EPBReq,
               &THA_SWC_B.IeTHA_pct_THAStrDamp, &THA_SWC_B.MeTHA_e_THAStateInfo,
               &THA_SWC_B.MeTHA_e_ScreenRequest,
               &THA_SWC_B.MeTHA_b_EnblRearParkAsstTrg,
               &THA_SWC_B.MeTHA_e_RearBrkSupprInfo,
               &THA_SWC_B.MeTHA_b_UsrHitchCnfm,
               &THA_SWC_B.MeTHA_b_UsrCplrSelCnfm,
               &THA_SWC_B.MeTHA_b_TrlrCplrStatus,
               &THA_SWC_B.MeTHA_b_THAAbortStatus,
               &THA_SWC_B.MeTHA_deg_RoadWhlAng,
               &THA_SWC_B.MeTHA_b_UsrInputTimeOut,
               &THA_SWC_B.MeTHA_b_ViewZoomSts, &THA_SWC_B.MeTHA_b_CamOccluLoLi,
               &THA_SWC_B.MeTHA_px_HitchCplrPixDiffLongAtStrt);

  /* BusCreator: '<S2>/BusCreator' */
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.IeTHA_M_THASteerTrqInfo =
    THA_SWC_B.IeTHA_M_THASteerTrqInfo;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.IeTHA_pct_THAStrDamp =
    THA_SWC_B.IeTHA_pct_THAStrDamp;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_deg_RoadWhlAng =
    THA_SWC_B.MeTHA_deg_RoadWhlAng;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.IeTHA_e_THAState =
    THA_SWC_B.IeTHA_e_THAState;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.IeTHA_e_THASpdLimReq =
    THA_SWC_B.IeTHA_e_THASpdLimReq;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.IeTHA_e_PamVol =
    THA_SWC_B.IeTHA_e_PamVol;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.IeTHA_e_PamChimeTyp =
    THA_SWC_B.IeTHA_e_PamChimeTyp;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.IeTHA_e_PamChimeRepRateSts =
    THA_SWC_B.IeTHA_e_PamChimeRepRateSts;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.IeTHA_e_THASteerTrqReq =
    THA_SWC_B.IeTHA_e_THASteerTrqReq;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.IeTHA_e_THARmpUpDwnSpd =
    THA_SWC_B.IeTHA_e_THARmpUpDwnSpd;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.IeTHA_e_EPBReq =
    THA_SWC_B.IeTHA_e_EPBReq;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_e_THAStateInfo =
    THA_SWC_B.MeTHA_e_THAStateInfo;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_e_ScreenRequest =
    THA_SWC_B.MeTHA_e_ScreenRequest;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_e_RearBrkSupprInfo =
    THA_SWC_B.MeTHA_e_RearBrkSupprInfo;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.IeTHA_b_ChimeActvLhf =
    THA_SWC_B.IeTHA_b_ChimeActvLhf;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.IeTHA_b_ChimeActvRhf =
    THA_SWC_B.IeTHA_b_ChimeActvRhf;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.IeTHA_b_ChimeActvLhr =
    THA_SWC_B.IeTHA_b_ChimeActvLhr;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.IeTHA_b_ChimeActvRhr =
    THA_SWC_B.IeTHA_b_ChimeActvRhr;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_b_EnblRearParkAsstTrg =
    THA_SWC_B.MeTHA_b_EnblRearParkAsstTrg;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_b_UsrHitchCnfm =
    THA_SWC_B.MeTHA_b_UsrHitchCnfm;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_b_UsrCplrSelCnfm =
    THA_SWC_B.MeTHA_b_UsrCplrSelCnfm;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_b_TrlrCplrStatus =
    THA_SWC_B.MeTHA_b_TrlrCplrStatus;
  THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_b_THAAbortStatus =
    THA_SWC_B.MeTHA_b_THAAbortStatus;
  //HardCode for Vehicle testing : Workaround for THA detection to work
  //THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_b_UsrCplrSelCnfm = true;

#if DEBUG_PRINTS
uint32_t roadWhlAng = (uint32_t)THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_deg_RoadWhlAng;
UART_printf("\n %d:StateInfo:%d,ScrnReq:%d,RearBrkSupr:%d,AbortStat:%d,RdWhlAng:%d\t", 
counter,THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_e_THAStateInfo,THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_e_ScreenRequest,
THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_e_RearBrkSupprInfo,THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11.MeTHA_b_THAAbortStatus,
roadWhlAng);
TaskP_sleepInMsecs(3);
counter++;
#endif

  /* DataStoreWrite: '<S2>/DataStoreWrite' */
  static TbTHASmVc_FeatureOutputs_t PrevTHASmVc_FeatureOutputs;
  if(0 != memcmp(&THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11, &PrevTHASmVc_FeatureOutputs, sizeof(PrevTHASmVc_FeatureOutputs)))
  {
    SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Put(&THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11);

  }
  PrevTHASmVc_FeatureOutputs = THA_SWC_B.TbTHASmVc_FeatureOutputs_t_kb11;
  
  /* SignalConversion: '<S2>/SignalCopy19' */
  THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu.MeTHA_e_THASpdLimReq =
    THA_SWC_B.IeTHA_e_THASpdLimReq;

  /* SignalConversion: '<S2>/SignalCopy1' */
  THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu.MeTHA_e_THASteerTrqReq =
    THA_SWC_B.IeTHA_e_THASteerTrqReq;

  /* SignalConversion: '<S2>/SignalCopy2' */
  THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu.MeTHA_e_THARmpUpDwnSpd =
    THA_SWC_B.IeTHA_e_THARmpUpDwnSpd;

  /* SignalConversion: '<S2>/SignalCopy3' */
  THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu.MeTHA_e_EPBReq = THA_SWC_B.IeTHA_e_EPBReq;

  /* BusCreator: '<S2>/BusCreator1' */
  THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu.MeTHA_px_HitchCplrPixDiffLongAtStrt =
    THA_SWC_B.MeTHA_px_HitchCplrPixDiffLongAtStrt;
  THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu.MeTHA_deg_RoadWhlAng =
    THA_SWC_B.MeTHA_deg_RoadWhlAng;
  THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu.MeTHA_e_THAStateInfo =
    THA_SWC_B.MeTHA_e_THAStateInfo;
  THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu.MeTHA_b_UsrCplrSelCnfm =
    THA_SWC_B.MeTHA_b_UsrCplrSelCnfm;
  THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu.MeTHA_b_TrlrCplrStatus =
    THA_SWC_B.MeTHA_b_TrlrCplrStatus;
  THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu.MeTHA_b_THAAbortStatus =
    THA_SWC_B.MeTHA_b_THAAbortStatus;
  THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu.MeTHA_b_UsrInputTimeOut =
    THA_SWC_B.MeTHA_b_UsrInputTimeOut;
  THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu.MeTHA_b_ViewZoomSts =
    THA_SWC_B.MeTHA_b_ViewZoomSts;
  THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu.MeTHA_b_CamOccluLoLi =
    THA_SWC_B.MeTHA_b_CamOccluLoLi;

  /* DataStoreWrite: '<S2>/DataStoreWrite1' */
  ME_CanDebugRIDStatus_t debugStatus_s;
  // TBD THA : To enable SigMgr API once available
  SigMgr_Data_ME_CanDebugRIDStatus_t_Get(&debugStatus_s);
  // Send Debug IPC message only when enabled via RID
  if (Debug_Mode == debugStatus_s.CanDebugMode)
  {  
    static TbTHASmVc_DiagMgr_t PrevTHASmVc_DiagMgr;
    if(0 != memcmp(&THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu, &PrevTHASmVc_DiagMgr, sizeof(PrevTHASmVc_DiagMgr)))
    {
      SigMgr_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t_Put(&THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu);
    }
    PrevTHASmVc_DiagMgr = THA_SWC_B.TbTHASmVc_DiagMgr_t_l3cu;
  }
   /* DataTypeConversion: '<S4>/DataTypeConversion37' */
  THA_SWC_B.KeTHA_M_SteerTweakTrq_jky1 = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_M_SteerTweakTrq;

  /* DataTypeConversion: '<S4>/DataTypeConversion41' */
  THA_SWC_B.KeTHA_s_SteerTweakTime_l4b0 = (real32_T)
    THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_s_SteerTweakTime;
}

/* Model initialize function */
void THA_SWC_initialize(void)
{
  /* Registration code */

  /* block I/O */
  {
    THA_SWC_B.MbTHA_VehInpOutData = THA_SWC_rtZTbTHASmVc_InputFromVehInp_t;
    THA_SWC_B.MbTHA_ProxiMgrOutData = THA_SWC_rtZTbTHASmVc_InputFromProxiMgr_t;
    THA_SWC_B.IeVBII_e_VehStandStillSts = TeVBII_e_VehStandStillSts_False;
    THA_SWC_B.IeVBII_e_EssEngState = TeVBII_e_EssEngState_ENS_STOPPED;
    THA_SWC_B.MePRX_e_Wheelbase = TePRX_e_Wheelbase_Type_2;
    THA_SWC_B.MePRX_e_SteerRatRackPinionTyp =
      TePRX_e_SteerRatRackPinionTyp_Type_2;
  }

  /* Model Initialize function for ModelReference Block: '<Root>/THA_SmVc_Ref' */
  THA_SmVc_Ref_initialize();

  /* Start for ModelReference: '<Root>/THA_SmVc_Ref' */
  THA_SmVc_Ref_Start(&THA_SWC_B.IeTHA_b_ChimeActvLhr,
                     &THA_SWC_B.IeTHA_b_ChimeActvRhr,
                     &THA_SWC_B.IeTHA_e_PamChimeRepRateSts,
                     &THA_SWC_B.IeTHA_pct_THAStrDamp);

  /* SystemInitialize for ModelReference: '<Root>/THA_SmVc_Ref' */
  THA_SmVc_Ref_Init(&THA_SWC_B.IeTHA_b_ChimeActvLhr,
                    &THA_SWC_B.IeTHA_b_ChimeActvRhr,
                    &THA_SWC_B.IeTHA_e_PamChimeRepRateSts,
					&THA_SWC_B.IeTHA_pct_THAStrDamp);

  /* DataStoreRead: '<S5>/DataStoreRead9' */
  SigMgr_Data_THA_Calibration_data_MCU2_1_t_Get(&(THA_SWC_B.MbTHA_VrntTunParamOut));
  #if DEBUG_PRINTS
  UART_printf("\nMCU2_1 Calib Data: %d,%d,%d,%d,%d,\t", 
  THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_cnt_WhlPlsCntLowLim,
  THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_px_HitchCplrDeltaThd1,
  THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_px_HitchCplrDeltaThd2,
  THA_SWC_B.MbTHA_VrntTunParamOut.CalData.KeTHA_px_RearBrkSuppDist,
  THA_SWC_B.MbTHA_VrntTunParamOut.bValid);
  TaskP_sleepInMsecs(3);
  #endif
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
