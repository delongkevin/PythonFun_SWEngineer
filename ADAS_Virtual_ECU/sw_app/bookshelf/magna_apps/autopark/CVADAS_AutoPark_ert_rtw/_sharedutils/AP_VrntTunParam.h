/* 
 * File: AP_VrntTunParam.h 
 *   
 * Code generated for Simulink model ''. 
 *  
 * Model version                  :  
 * Simulink Coder version         :  
 * C/C++ source code generated on : Wed Nov 12 18:10:05 2025 
 * Embedded hardware selection: 
 */

#ifndef RTW_HEADER_AP_VrntTunParam_h_
#define RTW_HEADER_AP_VrntTunParam_h_
#include "rtwtypes.h"


typedef struct
{
    real32_T KeAP_degC_OperatingTempThd;
    real32_T KeAP_kph_EnblHysThd;
    real32_T KeAP_kph_FrntWarnMaxSpdThd;
    real32_T KeAP_kph_ParkMnvThd;
    real32_T KeAP_kph_PSDOffThd;
    real32_T KeAP_kph_PSDOnThd;
    real32_T KeAP_kph_RearWarnMaxSpdThd;
    real32_T KeAP_kph_USSActiveSpdThd;
    real32_T K_e_RAEB_VehicleWidth;
    real32_T K_Overlap_Thrsld_RAEB[5];
    real32_T KeTOS_s_InTurnDbncTm;
    real32_T KeTOS_s_StrDrvDbncTm;
    real32_T KeTOS_s_TurnExitDbncTm;
    real32_T KeTOS_x_InTurnThd;
    real32_T KeTOS_x_TurnExitThd;
    real32_T keVehParam_m_DistWhlBse;
    real32_T Obj_DistTable[5];
    real32_T Overlap_Thrsld_Switch;
    real32_T RAEB_Envelope_Offset;
    real32_T RAEB_Lateral_Distance_Notification;
    real32_T RAEB_Minimum_Object_Heigh;
    real32_T sampling_time;
    real32_T keVehParam_e_VehSteerRatioTable[19];
    real32_T keVehParam_e_StrWhlRatioBrkPnts[19];
    real32_T keInpAdptr_e_StWhOffset;
    real32_T Straight_Driving_Thresold_rads2;
    real32_T Steering_Angle_DeadZone_Start;
    real32_T Steering_Angle_DeadZone_End;
    real32_T KeAP_k_PathSepaMinSpd;
    real32_T KeAP_k_PathSepaSpdRampGrd;
    real32_T KeAP_k_DetWP_PreviewTime;
    real32_T KeAP_k_LatPathDevPGain;
    real32_T KeAP_k_LatPathDevIGain;
    real32_T KeAP_k_LatPathDevDGain;
    real32_T KeAP_k_LatHeadDevPGain;
    real32_T KeAP_k_LatHeadDevIGain;
    real32_T KeAP_k_LatHeadDevDGain;
    real32_T KeAP_k_SteerUpperLimit;
    real32_T KeAP_k_SteerLowerLimit;
    real32_T KeAP_k_CtrlOutCollDetActivate;
    real32_T KeAP_k_CtrlOutRemainDistNA;
    real32_T KeAP_k_CtrlOutCollDetCollDistLimit;
    real32_T KeAP_k_CtrlOutCollDetRedStopVal;
    real32_T KeAP_k_CtrlOutVehSpdMaxSpotStrTime;
    real32_T KeAP_k_CtrlOutVehSpdMaxSpotStrRackDevThd;
    real32_T KeAP_k_CtrlOutVehSpdMaxSpotSteer;
    real32_T KeAP_k_BrakePGain;
    real32_T KeAP_k_BrakeIGain;
    real32_T KeAP_k_BrakeUpperLimit;
    real32_T KeAP_k_BrakeLowerLimit;
    real32_T KeAP_k_CtrlOutGearDrive;
    real32_T KeAP_k_CtrlOutGearReverse;
    real32_T KeAP_k_CtrlOutGearPark;
    real32_T KeAP_k_WhlCircum;
    uint16_T KeAP_cnt_ChimeVolChgAlert;
    uint16_T KeAP_cnt_FrntChimeDisTimeThd;
    uint16_T KeAP_cnt_HalfSecChimeAlert;
    uint16_T KeAP_cnt_LEDBlinkTimeThd;
    uint16_T KeAP_cnt_VehKeyOnTimeThd;
    uint16_T KeAP_Cnt_GearFiltTimeThd;
    uint16_T KeAP_cnt_TimeStep;
    uint16_T KeAP_cm_ObjPrestFCDistThd;
    uint16_T KeAP_cm_ObjPrestRCDistThd;
    uint16_T KeAP_cm_VehicleWidth;
    uint16_T KeAP_Cnt_GearOverrideTimeThd;
    uint16_T KeAP_cnt_SwtStuckTimeThd;
    uint16_T KeAP_s_BSMInterfaceCntTimeout;
    uint16_T KeAP_s_CamHandshakeDur;
    uint16_T KeAP_s_EPSInterfaceCntTimeout;
    uint16_T KeAP_s_GearShiftWaitCntTimeout;
    uint16_T KeAP_s_MaxStandstillTimeThd;
    uint16_T KeAP_s_ObjInPathTimeoutDur;
    uint16_T KeAP_s_PausedPressBtnTimeoutDur;
    uint16_T KeAP_s_SeekPhaseTimeoutDur;
    uint16_T KeAP_s_SpdExceedDur;
    uint16_T KeAP_cnt_SPMBlinkLEDDur;
    int16_T KeAP_cm_VehContour_FSL_x;
    int16_T KeAP_cm_VehContour_FOL_x;
    int16_T KeAP_cm_VehContour_FIL_x;
    int16_T KeAP_cm_VehContour_FIR_x;
    int16_T KeAP_cm_VehContour_FOR_x;
    int16_T KeAP_cm_VehContour_FSR_x;
    int16_T KeAP_cm_VehContour_FSL_y;
    int16_T KeAP_cm_VehContour_FOL_y;
    int16_T KeAP_cm_VehContour_FIL_y;
    int16_T KeAP_cm_VehContour_FIR_y;
    int16_T KeAP_cm_VehContour_FOR_y;
    int16_T KeAP_cm_VehContour_FSR_y;
    int16_T KeAP_cm_VehContour_RSR_x;
    int16_T KeAP_cm_VehContour_ROR_x;
    int16_T KeAP_cm_VehContour_RIR_x;
    int16_T KeAP_cm_VehContour_RIL_x;
    int16_T KeAP_cm_VehContour_ROL_x;
    int16_T KeAP_cm_VehContour_RSL_x;
    int16_T KeAP_cm_VehContour_RSR_y;
    int16_T KeAP_cm_VehContour_ROR_y;
    int16_T KeAP_cm_VehContour_RIR_y;
    int16_T KeAP_cm_VehContour_RIL_y;
    int16_T KeAP_cm_VehContour_ROL_y;
    int16_T KeAP_cm_VehContour_RSL_y;
    int16_T KeAP_cm_DistZone1;
    int16_T KeAP_cm_DistZone2;
    int16_T KeAP_cm_DistZone3;
    int16_T KeAP_cm_DistZone4;
    int16_T KeAP_cm_DistZone5;
    int16_T KeAP_cm_DistZone6;
    int16_T KeAP_cnt_DebounceTimeThd;
    int16_T KeAP_cm_FrntLongDistAdj;
    int16_T KeAP_cm_HalfVehicleWidth;
    int16_T KeAP_cm_HookDistOffset;
    int16_T KeAP_cm_MaxNoObjDetctDist;
    int16_T KeAP_cm_RearLongDistAdj;
    int16_T KeAP_cm_WarnOffset;
    uint8_T KeAP_e_GbTypAT;
    uint8_T KeAP_pct_ObjConfidenceThd;
    uint8_T Reverse_Gr_num;
    boolean_T KeAP_b_AutoParkEn;
    boolean_T KeAP_b_FPAEn;
    boolean_T KeAP_b_FullAutoPark;
    boolean_T KeAP_b_HookConnected;
    boolean_T KeAP_b_RPAwithBrk;
    boolean_T KeAP_b_RPAwithSurroundView;
    boolean_T KeAP_b_SteerOnlyAutoPark;
    boolean_T KeCMbB_b_EnblOncObjDbnc;
    boolean_T dummy;
    boolean_T dummy1;
    boolean_T dummy2;
} TbAP_VrntTunParam_t;


#endif                     /* RTW_HEADER_AP_VrntTunParam_h_ */
/* 
 * File trailer for generated code. 
 *  
 * [EOF] 
 */

