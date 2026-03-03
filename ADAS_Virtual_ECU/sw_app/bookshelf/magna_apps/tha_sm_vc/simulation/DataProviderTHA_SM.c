//--------------------------------------------------------------------------
/// @file DataProviderTHA_SM.c
/// @brief Contains
///
/// DataProvider is an interface between THA_SM module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
///
//  --------------------------------------------------------------------------

#include <stdint.h>
#include "PlatformDataTypes.h"
#include "DataProviderTHA_SM.h"

void get_THADetectionOutput(TbTHASmVc_InputFromThaDet_t* b_input0)
{
  b_input0->MeTHA_b_StatusCplrZone        = test_MeTHA_b_StatusCplrZone[V_FrameNoTHA_u8];
  b_input0->MeTHA_e_HitchDetctStatus      = test_MeTHA_e_HitchDetctStatus[V_FrameNoTHA_u8];
  b_input0->MeTHA_e_CplrDetctStatus       = test_MeTHA_e_CplrDetctStatus[V_FrameNoTHA_u8];
  b_input0->MeTHA_deg_CplrAng             = test_MeTHA_deg_CplrAng[V_FrameNoTHA_u8];
  b_input0->MeTHA_e_CplrAboveHitchStatus  = test_MeTHA_e_CplrAboveHitchStatus[V_FrameNoTHA_u8];
  b_input0->MeTHA_b_TrlrCplrStatus        = test_MeTHA_b_TrlrCplrStatus[V_FrameNoTHA_u8];
  b_input0->MeTHA_px_HitchCplrPixDiffLong = test_MeTHA_px_HitchCplrPixDiffLong[V_FrameNoTHA_u8];
  b_input0->MeTHA_px_HitchCplrPixDiffLat  = test_MeTHA_px_HitchCplrPixDiffLat[V_FrameNoTHA_u8];
  b_input0->MeTHA_px_HitchPnt[0]          = test_MeTHA_px_HitchPnt_x[V_FrameNoTHA_u8];
  b_input0->MeTHA_px_HitchPnt[1]          = test_MeTHA_px_HitchPnt_y[V_FrameNoTHA_u8];
  b_input0->MeTHA_px_CplrPnt[0]           = test_MeTHA_px_CplrPnt_x[V_FrameNoTHA_u8];
  b_input0->MeTHA_px_CplrPnt[1]           = test_MeTHA_px_CplrPnt_y[V_FrameNoTHA_u8];
}

void get_HMISVS_t_data(TbTHASmVc_InputFromHmiSvs_t* b_input1)
{
  b_input1->MeSVS_b_THASftBtnPrsdStsToTHA = test_MeSVS_b_THASftBtnPrsdStsToTHA[V_FrameNoTHA_u8];
  b_input1->MeSVS_b_IsConfirmBtnPrsd      = test_MeSVS_b_IsConfirmBtnPrsd[V_FrameNoTHA_u8];
  b_input1->MeSVS_e_THAScrResp            = test_MeSVS_e_THAScrResp[V_FrameNoTHA_u8];
  b_input1->MeSVS_b_ImgDefeatReqSts       = test_MeSVS_b_ImgDefeatReqSts[V_FrameNoTHA_u8];
  b_input1->MeSVS_b_ViewZoomSts           = test_MeSVS_b_ViewZoomSts[V_FrameNoTHA_u8];
  b_input1->MeSVS_b_THAMnvrStartBtnPrsd   = test_MeSVS_b_THAMnvrStartBtnPrsd[V_FrameNoTHA_u8];
  b_input1->MeSVS_b_THAScrTchSts          = test_MeSVS_b_THAScrTchSts[V_FrameNoTHA_u8];
}

void get_SWCVCANMgr_t_Data(TbTHASmVc_InputFromVehInp_t* b_input2)
{
  b_input2->IeVBII_e_CmdIgnSts            = test_IeVBII_e_CmdIgnSts[V_FrameNoTHA_u8];            
  b_input2->IeVBII_e_TrailerConnectionSts = test_IeVBII_e_TrailerConnectionSts[V_FrameNoTHA_u8]; 
  b_input2->IeVBII_e_TrlrPrsntSts         = test_IeVBII_e_TrlrPrsntSts[V_FrameNoTHA_u8];         
  b_input2->IeVBII_e_LwsAngleType         = test_IeVBII_e_LwsAngleType[V_FrameNoTHA_u8];         
  b_input2->IeVBII_b_DriverDoorSts        = test_IeVBII_b_DriverDoorSts[V_FrameNoTHA_u8];        
  b_input2->IeVBII_b_TrnkStatus           = test_IeVBII_b_TrnkStatus[V_FrameNoTHA_u8];           
  b_input2->IeVBII_e_EssEngState          = test_IeVBII_e_EssEngState[V_FrameNoTHA_u8];          
  b_input2->IeVBII_e_TGWCamDispSts        = test_IeVBII_e_TGWCamDispSts[V_FrameNoTHA_u8];        
  b_input2->IeVBII_e_CamDispSts           = test_IeVBII_e_CamDispSts[V_FrameNoTHA_u8];           
  b_input2->IeVBII_e_BsmTHABrkResp        = test_IeVBII_e_BsmTHABrkResp[V_FrameNoTHA_u8];        
  b_input2->IeVBII_mm_VehFlLvl            = test_IeVBII_mm_VehFlLvl[V_FrameNoTHA_u8];            
  b_input2->IeVBII_e_VehFlLvlAdj          = test_IeVBII_e_VehFlLvlAdj[V_FrameNoTHA_u8];          
  b_input2->IeVBII_mm_VehFrLvl            = test_IeVBII_mm_VehFrLvl[V_FrameNoTHA_u8];            
  b_input2->IeVBII_e_VehFrLvlAdj          = test_IeVBII_e_VehFrLvlAdj[V_FrameNoTHA_u8];          
  b_input2->IeVBII_mm_VehRlLvl            = test_IeVBII_mm_VehRlLvl[V_FrameNoTHA_u8];            
  b_input2->IeVBII_e_VehRlLvlAdj          = test_IeVBII_e_VehRlLvlAdj[V_FrameNoTHA_u8];          
  b_input2->IeVBII_mm_VehRrLvl            = test_IeVBII_mm_VehRrLvl[V_FrameNoTHA_u8];            
  b_input2->IeVBII_e_VehRrLvlAdj          = test_IeVBII_e_VehRrLvlAdj[V_FrameNoTHA_u8];          
  b_input2->IeVBII_e_VehAscmSts           = test_IeVBII_e_VehAscmSts[V_FrameNoTHA_u8];           
  b_input2->IeVBII_b_VehAscmSysFail       = test_IeVBII_b_VehAscmSysFail[V_FrameNoTHA_u8];       
  b_input2->IeVBII_e_GearEngagedForDsply  = test_IeVBII_e_GearEngagedForDsply[V_FrameNoTHA_u8];  
  b_input2->IeVBII_e_VehEPBSts            = test_IeVBII_e_VehEPBSts[V_FrameNoTHA_u8];            
  b_input2->IeVBII_a_VehLatAcc            = test_IeVBII_a_VehLatAcc[V_FrameNoTHA_u8];            
  b_input2->IeVBII_a_VehLongAcc           = test_IeVBII_a_VehLongAcc[V_FrameNoTHA_u8];           
  b_input2->IeVBII_ddeg_VehYawRate        = test_IeVBII_ddeg_VehYawRate[V_FrameNoTHA_u8];        
  b_input2->IeVBII_kph_VehSpeedVSOSig     = test_IeVBII_kph_VehSpeedVSOSig[V_FrameNoTHA_u8];     
  b_input2->IeVBII_cnt_LhfPulseCtr        = test_IeVBII_cnt_LhfPulseCtr[V_FrameNoTHA_u8];        
  b_input2->IeVBII_e_LhfWhlSpnSts         = test_IeVBII_e_LhfWhlSpnSts[V_FrameNoTHA_u8];         
  b_input2->IeVBII_kph_LhfWhlSpd          = test_IeVBII_kph_LhfWhlSpd[V_FrameNoTHA_u8];          
  b_input2->IeVBII_cnt_LhrPulseCtr        = test_IeVBII_cnt_LhrPulseCtr[V_FrameNoTHA_u8];        
  b_input2->IeVBII_e_LhrWhlSpnSts         = test_IeVBII_e_LhrWhlSpnSts[V_FrameNoTHA_u8];         
  b_input2->IeVBII_kph_LhrWhlSpd          = test_IeVBII_kph_LhrWhlSpd[V_FrameNoTHA_u8];         
  b_input2->IeVBII_cnt_RhfPulseCtr        = test_IeVBII_cnt_RhfPulseCtr[V_FrameNoTHA_u8];        
  b_input2->IeVBII_e_RhfWhlSpnSts         = test_IeVBII_e_RhfWhlSpnSts[V_FrameNoTHA_u8];         
  b_input2->IeVBII_kph_RhfWhlSpd          = test_IeVBII_kph_RhfWhlSpd[V_FrameNoTHA_u8];          
  b_input2->IeVBII_cnt_RhrPulseCtr        = test_IeVBII_cnt_RhrPulseCtr[V_FrameNoTHA_u8];        
  b_input2->IeVBII_e_RhrWhlSpnSts         = test_IeVBII_e_RhrWhlSpnSts[V_FrameNoTHA_u8];         
  b_input2->IeVBII_kph_RhrWhlSpd          = test_IeVBII_kph_RhrWhlSpd[V_FrameNoTHA_u8];          
  b_input2->IeVBII_a_VehLatAccOffset      = test_IeVBII_a_VehLatAccOffset[V_FrameNoTHA_u8];      
  b_input2->IeVBII_a_VehLongAccOffset     = test_IeVBII_a_VehLongAccOffset[V_FrameNoTHA_u8];     
  b_input2->IeVBII_deg_StrWhlAng          = test_IeVBII_deg_StrWhlAng[V_FrameNoTHA_u8];          
  b_input2->IeVBII_e_EngineSts            = test_IeVBII_e_EngineSts[V_FrameNoTHA_u8];            
  b_input2->IeVBII_kph_RefVehSpd          = test_IeVBII_kph_RefVehSpd[V_FrameNoTHA_u8];          
  b_input2->IeVBII_e_VehStandStillSts     = test_IeVBII_e_VehStandStillSts[V_FrameNoTHA_u8];     
  b_input2->IeVBII_e_EcmTHAResp           = test_IeVBII_e_EcmTHAResp[V_FrameNoTHA_u8];           
  b_input2->IeVBII_e_EpsTHADrvTrqOvrd     = test_IeVBII_e_EpsTHADrvTrqOvrd[V_FrameNoTHA_u8];     
  b_input2->IeVBII_e_EpsTHASteerTrqResp   = test_IeVBII_e_EpsTHASteerTrqResp[V_FrameNoTHA_u8];   
  b_input2->IeVBII_e_THASteerTouchStatus  = test_IeVBII_e_THASteerTouchStatus[V_FrameNoTHA_u8];    
}

void get_SMModelOutput_t_Data(TbTHASmVc_InputFromApSmPa_t* b_input3)
{
  b_input3->IeAP_e_FrntRearParkSts        = test_IeAP_e_FrntRearParkSts[V_FrameNoTHA_u8];
}

void get_SWCProxiMgr_t(TbTHASmVc_InputFromProxiMgr_t* b_input4)
{
  b_input4->MePRX_b_CanNod24              = test_MePRX_b_CanNod24[V_FrameNoTHA_u8];             
  b_input4->MePRX_b_CanNod27              = test_MePRX_b_CanNod27[V_FrameNoTHA_u8];             
  b_input4->MePRX_b_CanNod63              = test_MePRX_b_CanNod63[V_FrameNoTHA_u8];             
  b_input4->MePRX_b_CanNod95              = test_MePRX_b_CanNod95[V_FrameNoTHA_u8];             
  b_input4->MePRX_b_RvcEnbl               = test_MePRX_b_RvcEnbl[V_FrameNoTHA_u8];              
  b_input4->MePRX_b_ParkWithStop          = test_MePRX_b_ParkWithStop[V_FrameNoTHA_u8];        
  b_input4->MePRX_b_SvcEnbl               = test_MePRX_b_SvcEnbl[V_FrameNoTHA_u8];              
  b_input4->MePRX_b_SRT                   = test_MePRX_b_SRT[V_FrameNoTHA_u8];                  
  b_input4->MePRX_e_VehLineCfg            = test_MePRX_e_VehLineCfg[V_FrameNoTHA_u8];           
  b_input4->MePRX_b_TrlrHitchAssPres      = test_MePRX_b_TrlrHitchAssPres[V_FrameNoTHA_u8];     
  b_input4->MePRX_e_Wheelbase             = test_MePRX_e_Wheelbase[V_FrameNoTHA_u8];            
  b_input4->MePRX_mm_TyreSz               = test_MePRX_mm_TyreSz[V_FrameNoTHA_u8];              
  b_input4->MePRX_b_SteerRatRackPinionTyp = test_MePRX_b_SteerRatRackPinionTyp[V_FrameNoTHA_u8];
}

void get_MECalibSVS_t_Data(TbTHASmVc_InputFromDegrdMgr_t* b_input5)
{
  b_input5->MeTHA_b_Disabled              = test_MeTHA_b_Disabled[V_FrameNoTHA_u8];
  b_input5->MeTHA_e_DsblReason            = test_MeTHA_e_DsblReason[V_FrameNoTHA_u8];
}

void put_THA_output(  )
{

}
