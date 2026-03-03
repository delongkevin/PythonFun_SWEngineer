/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 * This document in its entirety is CONFIDENTIAL and may not be disclosed,
 * disseminated or distributed to parties outside MAGNA Electronics
 * without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:       Header File for OEM Typedefs
 * DESIGN:      2014
 * DESCRIPTION: Header File for OEM Typedefs
 * ======================================================================== */

/**
 * \file     ME_hydra2defs_OEM.h
 * \brief    OEM specific defines and typedefs
 * \author   Marcel Engelhardt
 * \version  $Revision: 1.6.1.5 $
 * \details  h file public description of module
 */

#ifndef ME_HYDRA2DEFS_OEM_H_ 
#define ME_HYDRA2DEFS_OEM_H_

//From #include "ME_typedefs.h"


/* SUPPLIER_MAGNA 0x0049 */
#define SUPPLIER_IDENT_HIGHBYTE_MAGNA  0x00u
#define SUPPLIER_IDENT_LOWBYTE_MAGNA   0x49u

/*
** Typedefs per the coding standard.
*/
typedef unsigned char           BOOL;
typedef unsigned char           u8;
typedef signed char             s8;
typedef unsigned short int      u16;
typedef signed short int        s16;
typedef unsigned long int       u32;
typedef signed long int         s32;
typedef unsigned long long      u64;
typedef signed long long        s64;
typedef float                   f32;
typedef double                  d64;

#define U32_MAX (0xFFFFFFFFul)

typedef enum Std_E_ReturnType_e
{
  Std_E_RetType_Successful = 0u,
  Std_E_RetType_Failed
}Std_E_ReturnType_t;

typedef enum aHmiM_E_ModuleState_e
{
  aHmiM_E_NotInit         = 0u,
  aHmiM_E_Init            = 1u,
  aHmiM_E_NormalOperation = 2u,
  aHmiM_E_Inactive        = 3u,
  aHmiM_E_NumStates       = 4u
}aHmiM_E_ModuleState_t;

typedef u8 Std_ReturnType;
#define E_OK      0u
#define E_NOT_OK  1u

enum Std_E_LogicLevel_e
{
  Std_E_LogicLevel_Low = 0u,
  Std_E_LogicLevel_High
};
typedef u8 Std_LogicLevel_t;

//#pragma ghs nowarning 47
#define STD_HIGH Std_E_LogicLevel_High


//#pragma ghs nowarning 47
#define STD_LOW Std_E_LogicLevel_Low
//#pragma ghs endnowarning

/* function pointer */
typedef void (*v_fp_v)(void);
typedef BOOL (*v_fp_b)(void);
typedef void (*b_fp_v)(BOOL); /* PRQA S 1336 */

/* ===========================================================================
*
*   Public Defines
*
* ========================================================================= */

#define NULL 0
#define FALSE 0
#define TRUE 1





/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */
#define ME_HYDRA2DEFS_OEM_VERSION_ID_H "$Id: ME_hydra2defs_OEM.h 1.6.1.5 2021/08/17 14:52:37IST Shankaregowda M (shanm) Draft  $"  /**< \brief short c-file private description of lFoo_D_VERSION_ID_C */

/* this is the internal default resolution on which base the button coordinates are calculated */
#define ME_HYDRA2DEFS_DISPLAY_RESOLUTION_X 1024  /* Chrysler DT X Resolution (0-1023px) */
#define ME_HYDRA2DEFS_DISPLAY_RESOLUTION_Y 768   /* Chrysler DT Y Resolution (0-767px) */

#define ME_HYDRA2DEFS_HMI_RESOLUTION_X     1024   /* Chrysler HMI X Resolution (0-1023px) */
#define ME_HYDRA2DEFS_HMI_RESOLUTION_Y     768    /* Chrysler HMI Y Resolution (0-767px) */

#define ME_HYDRA2DEFS_OEM_DEFAULTVIEWTYPE ME_Hydra2defs_OEM_E_RearTopView
#define ME_HYDRA2DEFS_VIEW_VERSION        0u   /* Chrysler */

#define ME_HYDRA2DEFS_EOLTARGETDISTANCE   2412u /* Chrysler in mm */
#define ME_HYDRA2DEFS_EOLTARGETID         1u    /* Chrysler */

#define ME_HYDRA2DEFS_SCTARGETDISTANCE    2412u /* Chrysler in mm */
#define ME_HYDRA2DEFS_SCTARGETID          1u    /* Chrysler */

#define ME_HYDRA2DEFS_OEM_D_NROFSTEERINGCURVEPOINTS 24u

#define APPL_CANCHANNEL_0_VEHICLECAN    0
#define APPL_CANCHANNEL_1_PRIVATECAN    1

typedef enum ME_Hydra2defs_E_SystemState
{
  SystemONVideoOFF  = 0u, /* S0: System ON Video OFF */
  SystemONVideoON   = 1u, /* S1: System ON Video ON */
  RVC_Only          = 2u  /* S10: RVC Views / TowBallView Mode */
} ME_Hydra2defs_E_SystemState_t;

typedef enum ME_Hydra2defs_E_ViewType
{
  ME_Hydra2defs_OEM_E_NoView                = 0u,

  ME_Hydra2defs_OEM_E_FrontTopView          = 1u,  /* S5: Front and Top View */
  ME_Hydra2defs_OEM_E_APA_FTV               = 2u,
  ME_Hydra2defs_OEM_E_RearTopView           = 3u,  /* S2: Rear and Top View */
  ME_Hydra2defs_OEM_E_APA_RTV               = 4u,
  ME_Hydra2defs_OEM_E_APA_FULLSCREEN        = 5u,
  ME_Hydra2defs_OEM_E_BlindLeft			        = 6u,
  ME_Hydra2defs_OEM_E_TRG_L100_R0           = 7u,
  ME_Hydra2defs_OEM_E_TRG_L75_R25           = 8u,
  ME_Hydra2defs_OEM_E_TRG_L50_R50           = 9u,
  ME_Hydra2defs_OEM_E_TRG_L25_R75           = 10u,
  ME_Hydra2defs_OEM_E_TRG_L0_R100           = 11u,
  ME_Hydra2defs_OEM_E_BlindRight		        = 12u,
  ME_Hydra2defs_OEM_E_FrontCrossPathView    = 13u,  /* S4: Front Crosspath View */
  ME_Hydra2defs_OEM_E_RearCrossPathView     = 14u,  /* S3: Rear Crosspath View */
  ME_Hydra2defs_OEM_E_FrontFacingCameraView = 15u,
  ME_Hydra2defs_OEM_E_BUNRV                 = 16u,  /* Normal Rear view */
  ME_Hydra2defs_OEM_E_BUZRV                 = 17u,  /* Zoomed Rear View*/
  ME_Hydra2defs_OEM_E_TRGLeftCurbView       = 18u,
  ME_Hydra2defs_OEM_E_TRGRightCurbView      = 19u,
  ME_Hydra2defs_OEM_E_BUNRVOneCam           = 20u,
  ME_Hydra2defs_OEM_E_BUZRVOneCam           = 21u,

  ME_Hydra2defs_OEM_E_RAW_Front             = 22u,
  ME_Hydra2defs_OEM_E_RAW_Left              = 23u,
  ME_Hydra2defs_OEM_E_RAW_Rear              = 24u,
  ME_Hydra2defs_OEM_E_RAW_Right             = 25u,
  ME_Hydra2defs_OEM_E_QuadView              = 26u, /* Debug View */

  ME_Hydra2defs_OEM_E_NonViewRequested      = 27u,
  
  ME_Hydra2defs_OEM_E_THA_Normal            = 28u,
  ME_Hydra2defs_OEM_E_THA_Zoom_Dynamic      = 29u,
  ME_Hydra2defs_OEM_E_THA_Zoom_Static       = 30u,
  
  ME_Hydra2defs_OEM_E_TSC_Aiming            = 31u,
  
  ME_Hydra2defs_OEM_E_ViewCount             = 32u
} ME_Hydra2defs_E_ViewType_t;



typedef struct ME_Hydra2defs_S_OverlayGroups
{
u8 Reserved0_b                          :1;/* Bit 111 */
u8 Reserved1_b                          :1;/* Bit 110 */
u8 Reserved2_b                          :1;/* Bit 109 */	
u8 Reserved3_b                          :1;/* Bit 108 */
u8 THAProgressBar                       :1;/* Bit 107 */
u8 THAStartButton                       :1;/* Bit 106 */
u8 THAConfirmButton                     :1;/* Bit 105*/
u8 THAButtonSelectable                  :1;/* Bit 104 */
u8 THAButtonGrey                        :1;/* Bit 103 */
u8 THACouplerBulletIcon				          :1;/* Bit 102 */
u8 THATriangleOverlay                   :1;/* Bit 101 */
u8 TrscTrailerRed                       :1;/* Bit 100 */
u8 TrscJackKnifeRed                     :1;/* Bit 99 */
u8 TrscJackKnifeOrange                  :1;/* Bit 98 */
u8 TrscOvl				                      :1;/* Bit 97*/
u8 SrvPrgBar100Per_b                    :1;/* Bit 96 */
u8 SrvPrgBar80Per_b                     :1;/* Bit 95 */
u8 SrvPrgBar60Per_b                     :1;/* Bit 94 */
u8 SrvPrgBar40Per_b                     :1;/* Bit 93 */
u8 SrvPrgBar20Per_b                     :1;/* Bit 92 */
u8 SrvPrgBar0Per_b                      :1;/* Bit 91 */
u8 SrvCamIndRiNone_b                    :1;/* Bit 90 */
u8 SrvCamIndRiPend_b                    :1;/* Bit 89 */
u8 SrvCamIndRiNok_b                     :1;/* Bit 88 */
u8 SrvCamIndRiOk_b                      :1;/* Bit 87 */
u8 SrvCamIndBaNone_b                    :1;/* Bit 86 */
u8 SrvCamIndBaPend_b                    :1;/* Bit 85 */
u8 SrvCamIndBaNok_b                     :1;/* Bit 84 */
u8 SrvCamIndBaOk_b                      :1;/* Bit 83 */
u8 SrvCamIndLeNone_b                    :1;/* Bit 82 */
u8 SrvCamIndLePend_b                    :1;/* Bit 81 */
u8 SrvCamIndLeNok_b                     :1;/* Bit 80 */
u8 SrvCamIndLeOk_b                      :1;/* Bit 79 */
u8 SrvCamIndFrNone_b                    :1;/* Bit 78 */
u8 SrvCamIndFrPend_b                    :1;/* Bit 77 */
u8 SrvCamIndFrNok_b                     :1; /* Bit 76 */
u8 SrvCamIndFrOk_b                      :1;/* Bit 75 */
u8 SrvChkIndCondNok_b                   :1;/* Bit 74 */
u8 SrvChkIndNok_b                       :1;/* Bit 73 */
u8 SrvChkIndOk_b                        :1;/* Bit 72 */
u8 SrvChkIndRun_b                       :1;/* Bit 71 */
u8 SrvSpOmIndNok_b                      :1;/* Bit 70 */
u8 SrvSpOmIndOk_b                       :1;/* Bit 69 */
u8 SrvStAngIndNok_b                     :1;/* Bit 68 */
u8 SrvStAngIndOk_b                      :1;/* Bit 67 */
u8 SrvLayout_b                          :1;/* Bit 66 */
u8 PDC_RearLeft_Red_b                   :1;/* Bit 65 */
u8 PDC_RearLeft_Yellow_b                :1;/* Bit 64 */
u8 Reserved08_b		                      :1;/* Bit 63 */
u8 PDC_FrontRight_Red_b                 :1;/* Bit 62 */
u8 PDC_FrontRight_Yellow_b              :1;/* Bit 61 */
u8 Reserved09_b		                      :1;/* Bit 60 */
u8 PDC_FrontCenter_Red_b                :1;/* Bit 59 */
u8 PDC_FrontCenter_Yellow_b             :1;/* Bit 58 */
u8 Reserved10_b		                      :1;/* Bit 57 */
u8 PDC_FrontLeft_Red_b                  :1;/* Bit 56 */
u8 PDC_FrontLeft_Yellow_b               :1;/* Bit 55 */
u8 Reserved11_b		                      :1;/* Bit 54 */
u8 PDC_RearRight_Red_b                  :1;/* Bit 53 */
u8 PDC_RearRight_Yellow_b               :1;/* Bit 52 */
u8 Reserved12_b		                      :1;/* Bit 51 */
u8 PDC_RearCenter_Red_b                 :1;/* Bit 50 */
u8 PDC_RearCenter_Yellow_b              :1;/* Bit 49 */
u8 Reserved13_b		                      :1;/* Bit 48 */
u8 RightDoorRearClose_Icon_b            :1;/* Bit 47 */
u8 RightDoorFrontClose_Icon_b           :1;/* Bit 46 */
u8 LeftDoorRearClose_Icon_b             :1;/* Bit 45 */
u8 LeftDoorFrontClose_Icon_b            :1;/* Bit 44 */
u8 TopViewBlack_b                       :1;/* Bit 43 */
u8 RightCam_NA_b                        :1;/* Bit 42 */
u8 BackCam_NA_b                         :1;/* Bit 41 */
u8 LeftCam_NA_b                         :1;/* Bit 40 */
u8 FrontCam_NA_b                        :1;/* Bit 39 */
u8 BackDoorOpen_Icon_b                  :1;/* Bit 38 */
u8 RightDoorRearOpen_Icon_b             :1;/* Bit 37 */
u8 RightDoorFrontOpen_Icon_b            :1;/* Bit 36 */
u8 LeftDoorRearOpen_Icon_b              :1;/* Bit 35 */
u8 LeftDoorFrontOpen_Icon_b             :1;/* Bit 34 */
u8 ZoomPlusIcon_b                       :1;/* Bit 33 */
u8 ZoomMinusIcon_b                      :1;/* Bit 32 */
u8 ZoomButtonDisable_b                  :1;/* Bit 31 */
u8 XIcon_b                              :1;/* Bit 30 */
u8 TopViewFrontDynamics_b               :1;/* Bit 29 */
u8 FrontViewDynamics_b                  :1;/* Bit 28 */
u8 TopViewRearDynamics_b                :1;/* Bit 27 */
u8 RearViewDynamics_b                   :1;/* Bit 26 */
u8 MoreCamsButton2NoSelect_b            :1;/* Bit 25 */
u8 MoreCamsButton2Select_b              :1;/* Bit 24 */
u8 MoreCamsButton1NoSelect_b            :1;/* Bit 23 */
u8 MoreCamsButton1Select_b              :1;/* Bit 22 */
u8 AuxCamButton2NoSelect_b              :1;/* Bit 21 */
u8 AuxCamButton2Select_b                :1;/* Bit 20  */
u8 AuxCamButton1NoSelect_b              :1; /* Bit 19 */
u8 AuxCamButton1Select_b                :1;/* Bit 18 */
u8 FrontTireTracks_b                    :1;/* Bit 17  */
u8 FrontFaceCamButtonNoSelect_b         :1;/* Bit 16 */
u8 FrontFaceCamButtonSelect_b           :1;/* Bit 15 */
u8 BackupRearCamButtonNoSelect_b        :1;/* Bit 14 */
u8 BackupRearCamButtonSelect_b          :1;/* Bit 13 */
u8 TopFrontButtonNoSelect_b             :1;/* Bit 12 */
u8 TopFrontButtonSelect_b               :1;/* Bit 11 */
u8 FrontCrossButtonSelect_b             :1;/* Bit 10 */
u8 FrontCrossButtonNoSelect_b           :1;/* Bit 9 */
u8 RearCrossButtonSelect_b              :1;/* Bit 8 */
u8 RearCrossButtonNoSelect_b            :1;/* Bit 7 */
u8 TopRearButtonSelect_b                :1;/* Bit 6 */
u8 TopRearButtonNoSelect_b              :1;/* Bit 5 */
u8 MoreCamsIconFullScreenNoSelect_b     :1;/* Bit 4 */
u8 Frameset2AndRearCrossText_b          :1;/* Bit 3 */
u8 Frameset2AndFrontCrossText_b         :1;/* Bit 2 */
u8 Frameset1AndTopRearText_b            :1;/* Bit 1 */
u8 Frameset1AndTopFrontText_b           :1;/* Bit 0 */	
} ME_Hydra2defs_S_OverlayGroups_t;





typedef struct ME_Hydra2defs_S_GooseNeck
{
  s16 x_val_position;
  s16 y_val_position;
  s16 x_val_positionlastvalid;
  s16 y_val_positionlastvalid;
} ME_Hydra2defs_S_GooseNeck_t;

#pragma pack(push, 1) /* set compiler alignment size to 1 byte and save previous setting to compiler stack */
typedef struct ME_Hydra2defs_S_Screen
{
  u8 Version;
  u8 ViewID;
  u8 ZoomFactor; /* Range: 0: MaxZoom, 100: NoZoom */
  ME_Hydra2defs_S_GooseNeck_t Gooseneck;
  ME_Hydra2defs_S_OverlayGroups_t Overlays;
} ME_Hydra2defs_S_Screen_t;
#pragma pack(pop) /* restore compiler alignment size setting */

/* supported Vehicle Configs */
typedef enum ME_Hydra2defs_E_VehCfg_ID_e
{
  VehCfg_Test1                      =  0,
  VehCfg_Test2                      =  1,

  VehCfg_DT_WB140LL_Std             =  2,
  VehCfg_DT_WB144LL_Std             =  3,
  VehCfg_DT_WB153LL_Std             =  4,
  VehCfg_DT_WB140LL_TT              =  5,
  VehCfg_DT_WB144LL_TT              =  6,
  VehCfg_DT_WB153LL_TT              =  7,
  VehCfg_DT_WB144TR_Std             =  8,
  VehCfg_DT_WB144TR_TT              =  9,
  VehCfg_DT_WB140Rebel_Std          = 10,
  VehCfg_DT_WB144Rebel_Std          = 11,
  VehCfg_DT_WB140Rebel_TT           = 12,
  VehCfg_DT_WB144Rebel_TT           = 13,

  VehCfg_RU                         = 14,

  /* add further OEM variants here */

  VehCfg_Count
} ME_Hydra2defs_E_VehCfg_ID_t;
#define ME_HYDRA2DEFS_DEFAULT_VEHCFG VehCfg_DT_WB144LL_TT

#define ME_HYDRA2DEFS_DEFAULT_RESOLUTION ME_Hydra2defs_OEM_E_OutputResolution_1024x768

/* supported different Vehicle SteeringCurves */
typedef enum ME_Hydra2defs_E_SteeringCurves_e
{
  SteeringCurve_RU,
  SteeringCurve_M161,
  SteeringCurve_M156,
  SteeringCurve_M157,
  SteeringCurve_DT_55,
  SteeringCurve_DT_60,
  SteeringCurve_DT_63,
  SteeringCurve_DT_TR,
  SteeringCurve_Count
} ME_Hydra2defs_E_SteeringCurves_t;

typedef enum ME_Hydra2defs_E_DisplayMode
{
  DisplayMode_None      = 0u,
  DisplayMode_Auto      = 1u,
  DisplayMode_Manual    = 2u,
  DisplayMode_OFF       = 3u
} ME_Hydra2defs_E_DisplayMode_t;

typedef enum ME_Hydra2defs_E_ReversedGear
{
  M_ReversedGear_Inactive = 0x0,
  M_ReversedGear_Active   = 0x1
} ME_Hydra2defs_E_ReversedGear_t;
/* Req 515905 , 526963 */
typedef enum ME_Hydra2defs_E_DNDGear
{
  M_DNDGear_NotSet = 0x0,
  M_DNDGear_Set   = 0x1
} ME_Hydra2defs_E_DNDGear_t;

/* Req Id - 529288 ,529290 */
typedef enum ME_Hydra2defs_E_FFClatch
{
  M_FFClatch_NotSet = 0x0,
  M_FFClatch_Set   = 0x1
} ME_Hydra2defs_E_FFClatch_t;


typedef enum ME_Hydra2defs_E_SVCViewMemoryType
{
  ME_Hydra2defs_OEM_SVCViewMemory_E_NoView              = 0u,
  ME_Hydra2defs_OEM_SVCViewMemory_E_RearTopView         = 1u,  /* S2: Rear and Top View */
  ME_Hydra2defs_OEM_SVCViewMemory_E_RearCrossView       = 2u,  /* S3: Rear Crosspath View */
  ME_Hydra2defs_OEM_SVCViewMemory_E_FrontCrossView      = 3u,  /* S4: Front Crosspath View */
  ME_Hydra2defs_OEM_SVCViewMemory_E_FrontTopView        = 4u,  /* S5: Front and Top View */
}ME_Hydra2defs_E_SVCViewMemoryType_t;

typedef enum ME_Hydra2defs_E_ZoomLevel
{
  M_ZoomLevel_Normal = 0x0,
  M_ZoomLevel_Zoom   = 0x1
} ME_Hydra2defs_E_ZoomLevel_t;

/* OEM dependent implementation */
typedef struct ME_Hydra2defs_S_MCUDebug0_s
{
  ME_Hydra2defs_E_DisplayMode_t              DisplayMode            	:8;
  ME_Hydra2defs_E_DNDGear_t                  DNDGear             		:8;
  ME_Hydra2defs_E_ReversedGear_t             ReversedGear        		:8;
  ME_Hydra2defs_E_ViewType_t                 M_CurrentScreenOnZynqM		:8;
  ME_Hydra2defs_E_ViewType_t                 M_RequestedScreenByHmiM    :8;
  ME_Hydra2defs_E_FFClatch_t				 M_FFClatch			 	    :8;
  ME_Hydra2defs_E_ZoomLevel_t                M_BURV_Memory_e     		:8;
  u8                 						 Reserved1_u8   			:8;
} ME_Hydra2defs_E_MCUDebug0_t;

typedef struct ME_Hydra2defs_S_MCUDebug1_s
{
  u8 res0      :4;
  u8 PGOOD_3V3 :1;
  u8 PGOOD_1V8 :1;
  u8 PGOOD_1V2 :1;
  u8 PGOOD_1V0 :1;

  u8 res1        :3;
  u8 POR_N       :1;
  u8 PROGRAM_N   :1;
  u8 RESET_SOC_N :1;
  u8 SOC_DONE    :1;
  u8 INIT_N      :1;

  u16 stack_usage_bytes_u16;
  u16 stack_size_bytes_u16;
  u8 res6;
  u8 res7;
} ME_Hydra2defs_E_MCUDebug1_t;

typedef enum ME_Hydra2defs_E_ModuleHardwareConfiguration_NumCameraCfg
{
  ME_Hydra2defs_E_ModuleHardwareConfiguration_NumCameraCfg_1Camera = 0x0,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_NumCameraCfg_2Camera = 0x1,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_NumCameraCfg_4Camera = 0x2,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_NumCameraCfg_5Camera = 0x3,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_NumCameraCfg_6Camera = 0x4,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_NumCameraCfg_3Camera = 0x5
} ME_Hydra2defs_E_ModuleHardwareConfiguration_NumCameraCfg_t;

typedef enum ME_Hydra2defs_E_ModuleHardwareConfiguration_PresenceIndication
{
  ME_Hydra2defs_E_ModuleHardwareConfiguration_PresenceIndication_Absent  = 0x0,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_PresenceIndication_Present = 0x1
} ME_Hydra2defs_E_ModuleHardwareConfiguration_PresenceIndication_t;

typedef enum ME_Hydra2defs_E_ModuleHardwareConfiguration_StatusIndication
{
  ME_Hydra2defs_E_ModuleHardwareConfiguration_StatusIndication_Disabled  = 0x0,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_StatusIndication_Enabled   = 0x1
} ME_Hydra2defs_E_ModuleHardwareConfiguration_StatusIndication_t;

typedef enum ME_Hydra2defs_E_ModuleHardwareConfiguration_CamSwitchTypeCfg
{
  ME_Hydra2defs_E_ModuleHardwareConfiguration_CamSwitchTypeCfg_Network    = 0x0,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_CamSwitchTypeCfg_Hardwire   = 0x1
} ME_Hydra2defs_E_ModuleHardwareConfiguration_FrontCamEnableCfg_t;

typedef enum ME_Hydra2defs_E_ModuleHardwareConfiguration_DriveSide
{
  ME_Hydra2defs_E_ModuleHardwareConfiguration_DriveSide_Left = 0x0,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_DriveSide_Right = 0x1
} ME_Hydra2defs_E_ModuleHardwareConfiguration_DriveSide_t;

typedef enum ME_Hydra2defs_E_ModuleHardwareConfiguration_ParkAssistTypeCfg
{
  ME_Hydra2defs_E_ModuleHardwareConfiguration_ParkAssistTypeCfg_None = 0x0,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_ParkAssistTypeCfg_4Channel = 0x1,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_ParkAssistTypeCfg_8Channel = 0x2,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_ParkAssistTypeCfg_10Channel = 0x3,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_ParkAssistTypeCfg_12Channel = 0x4,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_ParkAssistTypeCfg_12ChannelFlank = 0x5
} ME_Hydra2defs_E_ModuleHardwareConfiguration_ParkAssistTypeCfg_t;

typedef enum ME_Hydra2defs_E_ModuleHardwareConfiguration_VehicleType
{
  ME_Hydra2defs_E_ModuleHardwareConfiguration_VehicleType_1 = 0x0,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_VehicleType_100 = 0x64
} ME_Hydra2defs_E_ModuleHardwareConfiguration_VehicleType_t;

typedef enum ME_Hydra2defs_E_ModuleHardwareConfiguration_BadgeCloseBehavior
{
  ME_Hydra2defs_E_ModuleHardwareConfiguration_BadgeCloseBehavior_Null = 0x0,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_BadgeCloseBehavior_Neutral = 0x1
} ME_Hydra2defs_E_ModuleHardwareConfiguration_BadgeCloseBehavior_t;

typedef enum ME_Hydra2defs_E_ModuleHardwareConfiguration_GDLOverlay
{
  ME_Hydra2defs_E_ModuleHardwareConfiguration_GDLOverlay_Disabled = 0x0,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_GDLOverlay_Static   = 0x1,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_GDLOverlay_Dynamic  = 0x2,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_GDLOverlay_Full     = 0x3
} ME_Hydra2defs_E_ModuleHardwareConfiguration_GDLOverlay_t;

typedef enum ME_Hydra2defs_E_ModuleHardwareConfiguration_Style
{
  ME_Hydra2defs_E_ModuleHardwareConfiguration_OldStyle = 0x0,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_NewStyle = 0x1
} ME_Hydra2defs_E_ModuleHardwareConfiguration_Style_t;

typedef enum ME_Hydra2defs_E_ModuleHardwareConfiguration_HitchAngle
{
  ME_Hydra2defs_E_ModuleHardwareConfiguration_HitchAngle_High       = 0x0,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_HitchAngle_HighMed    = 0x1,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_HitchAngle_HighMedLow = 0x2,
  ME_Hydra2defs_E_ModuleHardwareConfiguration_HitchAngle_NotUsed    = 0x3
} ME_Hydra2defs_E_ModuleHardwareConfiguration_HitchAngle_t;

typedef enum ME_Hydra2defs_E_DTCSuppressionType
{
  ME_Hydra2defs_E_DTCSuppressionType_Supressed      = 0x0,
  ME_Hydra2defs_E_DTCSuppressionType_ContinuousOnly = 0x1,
  ME_Hydra2defs_E_DTCSuppressionType_SelfTestOnly   = 0x2,
  ME_Hydra2defs_E_DTCSuppressionType_FullyEnabled   = 0x3
} ME_Hydra2defs_E_DTCSuppressionType_t;

typedef struct ME_Hydra2defs_S_ModuleHardwareConfiguration_s
{
  /* Byte #0 */
  u8  Unusedbit_Byte0_Bit7           : 1;
  u8  SlaveExists_CVC_Cfg_u1         : 1;
  u8  SlaveExists_BaseCam_Cfg_u1     : 1;
  u8  AuxInput_Cfg_u1                : 1;
  u8  PSCMExists_Cfg_u1              : 1;
  u8  NumCamera_Cfg_u3               : 3;

  /* Byte #1 */
  u8  LINSel_BaseCam_Cfg_u8          : 8; /* LIN Configuration Byte */

  /* Byte #2 */
  u8  Unusedbit_Byte2_Bit7           : 1;
  u8  ParkAsstDsply_Cfg_u1           : 1;
  u8  DriveSide_Cfg_u1               : 1;
  u8  TADEnable_Cfg_u1               : 1;
  u8  FrontCamEnable_Cfg_u1          : 1;
  u8  Vss_Sleep_u1                   : 1; /* changed to u8 to solve QAC warning */
  u8  SlaveExists_RB_Cfg_u1          : 1;
  u8  SlaveExists_FB_Cfg_u1          : 1;

  /* Byte #3 */
  u8  FrontCamInd_Cfg_u1             : 1;
  u8  TailgateAjarInd_Cfg_u1         : 1;
  u8  DoorAjarInd_Cfg_u1             : 1;
  u8  RemoteCam_Cfg_u1               : 1;
  u8  Unusedbit_Byte3_Bit4           : 1;
  u8  ParkAssistType_Cfg_u3          : 3; /* changed to u8 to solve QAC warning */

  /* Byte #4 */
  u8  Unusedbit_Byte4_Bit7           : 1;
  u8  APAInterface_Cfg_u1            : 1;
  u8  AutoCalibration_Cfg_u1         : 1;
  u8  FrontOverlay_Cfg_u2            : 2;
  u8  RearOverlay_Cfg_u2             : 2;
  u8  BadgeCloseBehavior_Cfg_u1      : 1;

  /* Byte #5 */
  u8  Unusedbit_Byte5_Bit7           : 3;
  u8  TADLowConfSelector_Cfg_u1      : 1;
  u8  TADMedConfSelector_Cfg_u1      : 1;
  u8  TADHighConfSelector_Cfg_u1     : 1;
  u8  TBA_HitchAngle_Conf_Cfg_u2     : 2;

  /* Byte #6 */
  u8  VehType_Cfg_u8                 : 8;

  /* Byte #7 */
  u8  LINSel_CVC_Cfg_u8              : 8; /* LIN Configuration Byte */
} ME_Hydra2defs_S_ModuleHardwareConfiguration_t;

typedef struct ME_Hydra2defs_S_DTC_Suppression_Number_s
{
  /*Byte 0*/
  u8 Unusedbit_Byte0_Bit5           : 3;
  u8 RearSplitEnable_Cfg_u1         : 1;
  u8 Unusedbit_Byte0_Bit0           : 4;

  /* Bytes 1 - 7 */
  u8 MandatoryUnusedByte1_u8;
  u8 MandatoryUnusedByte2_u8;
  u8 MandatoryUnusedByte3_u8;
  u8 MandatoryUnusedByte4_u8;
  u8 MandatoryUnusedByte5_u8;
  u8 MandatoryUnusedByte6_u8;
  u8 MandatoryUnusedByte7_u8;
} ME_Hydra2defs_S_DTC_Suppression_Number_t;

/* --------------------------------------------------------------------------------- */
#endif /* ME_HYDRA2DEFS_OEM_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: ME_hydra2defs_OEM.h */
