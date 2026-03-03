//--------------------------------------------------------------------------                                                                                                           
/// @file THA_SM_V1_Inputs.h
/// @brief Contains type definitions and constants used in the Overlay environment                                                
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Afshan Shaikh(afshan.shaikh@magna.comp)
///                                                                                         
//  -------------------------------------------------------------------------- 
#ifndef THAOFFLINE_INPUTS_H
#define THAOFFLINE_INPUTS_H

//#include "THA_SWC_types.h"
#include "PlatformDataTypes.h"

extern uint8_t V_FrameNoTHA_u8;
extern uint32_t THAArrTimeInst_u32[];

extern bool test_MeTHA_b_StatusCplrZone[];
extern uint8 test_MeTHA_e_HitchDetctStatus[];
extern uint16 test_MeTHA_px_CplrPnt_x[];
extern uint16 test_MeTHA_px_CplrPnt_y[];
extern bool test_MeSVS_b_THASftBtnPrsdStsToTHA[];
extern bool test_MeSVS_b_IsConfirmBtnPrsd[];
extern uint8 test_MeSVS_e_THAScrResp[];
extern bool test_MeSVS_b_ImgDefeatReqSts[];
extern bool test_MeSVS_b_ViewZoomSts[];
extern bool test_MeSVS_b_THAMnvrStartBtnPrsd[];
extern uint8 test_IeVBII_e_EssEngState[];
extern uint8 test_IeVBII_e_TGWCamDispSts[];
extern uint8 test_MeTHA_e_CplrDetctStatus[];
extern uint8 test_IeVBII_e_CamDispSts[];
extern uint8 test_IeVBII_e_BsmTHABrkResp[];
extern int16 test_IeVBII_mm_VehFlLvl[];
extern uint8 test_IeVBII_e_VehFlLvlAdj[];
extern bool test_MeSVS_b_THAScrTchSts[];
extern uint8 test_IeAP_e_FrntRearParkSts[];
extern uint8 test_IeVBII_e_CmdIgnSts[];
extern uint8 test_IeVBII_e_TrailerConnectionSts[];
extern uint8 test_IeVBII_e_TrlrPrsntSts[];
extern uint8 test_IeVBII_e_LwsAngleType[];
extern float test_MeTHA_deg_CplrAng[];
extern bool test_IeVBII_b_DriverDoorSts[];
extern bool test_IeVBII_b_TrnkStatus[];
extern int16_t test_IeVBII_mm_VehFrLvl[];
extern uint8 test_IeVBII_e_VehFrLvlAdj[];
extern float test_IeVBII_a_VehLatAcc[];
extern float test_IeVBII_a_VehLongAcc[];
extern float test_IeVBII_ddeg_VehYawRate[];
extern float test_IeVBII_kph_VehSpeedVSOSig[];
extern uint8 test_IeVBII_cnt_LhfPulseCtr[];
extern uint8 test_IeVBII_e_LhfWhlSpnSts[];
extern uint8 test_MeTHA_e_CplrAboveHitchStatus[];
extern float test_IeVBII_kph_LhfWhlSpd[];
extern uint8 test_IeVBII_cnt_LhrPulseCtr[];
extern float test_IeVBII_a_VehLatAccOffset[];
extern float test_IeVBII_a_VehLongAccOffset[];
extern int16_t test_IeVBII_mm_VehRlLvl[];
extern float test_IeVBII_deg_StrWhlAng[];
extern uint8 test_IeVBII_e_EngineSts[];
extern float test_IeVBII_kph_RefVehSpd[];
extern uint8 test_IeVBII_e_VehStandStillSts[];
extern uint8 test_IeVBII_e_LhrWhlSpnSts[];
extern bool test_MeTHA_b_TrlrCplrStatus[];
extern float test_IeVBII_kph_LhrWhlSpd[];
extern uint8 test_IeVBII_cnt_RhfPulseCtr[];
extern uint8 test_IeVBII_e_RhfWhlSpnSts[];
extern float test_IeVBII_kph_RhfWhlSpd[];
extern uint8 test_IeVBII_cnt_RhrPulseCtr[];
extern uint8 test_IeVBII_e_VehRlLvlAdj[];
extern uint8 test_IeVBII_e_RhrWhlSpnSts[];
extern float test_IeVBII_kph_RhrWhlSpd[];
extern int16_t test_IeVBII_mm_VehRrLvl[];
extern uint8 test_IeVBII_e_VehRrLvlAdj[];
extern uint16 test_MeTHA_px_HitchCplrPixDiffLong[];
extern uint8 test_IeVBII_e_VehAscmSts[];
extern bool test_IeVBII_b_VehAscmSysFail[];
extern uint8 test_IeVBII_e_GearEngagedForDsply[];
extern uint8 test_IeVBII_e_VehEPBSts[];
extern uint8 test_IeVBII_e_EcmTHAResp[];
extern uint8 test_IeVBII_e_EpsTHADrvTrqOvrd[];
extern bool test_MePRX_b_SvcEnbl[];
extern bool test_MePRX_b_SRT[];
extern uint8 test_MePRX_e_VehLineCfg[];
extern bool test_MePRX_b_TrlrHitchAssPres[];
extern uint16 test_MeTHA_px_HitchCplrPixDiffLat[];
extern uint8 test_MePRX_e_Wheelbase[];
extern float  test_MePRX_mm_TyreSz[];
extern bool test_MePRX_b_SteerRatRackPinionTyp[];
extern bool test_MeTHA_b_Disabled[];
extern uint8 test_IeVBII_e_EpsTHASteerTrqResp[];
extern uint16 test_MeTHA_px_HitchPnt_x[];
extern uint8 test_MeTHA_e_DsblReason[];
extern uint8 test_IeVBII_e_THASteerTouchStatus[];
extern uint16 test_MeTHA_px_HitchPnt_y[];
extern bool test_MePRX_b_CanNod24[];
extern bool test_MePRX_b_CanNod27[];
extern bool test_MePRX_b_CanNod63[];
extern bool test_MePRX_b_CanNod95[];
extern bool test_MePRX_b_RvcEnbl[];
extern bool test_MePRX_b_ParkWithStop[];
#endif // THAOFFLINE_INPUTS_H

