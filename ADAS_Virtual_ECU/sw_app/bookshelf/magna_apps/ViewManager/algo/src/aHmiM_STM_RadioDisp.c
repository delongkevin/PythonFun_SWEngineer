//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!************VARIABLE DECLARATION************!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "aHmiM_STM_RadioDisp.h"

/*Zoom In and zoom out touch coordinates*/
uint16_t AHMIM_STM_D_4CAM_MAGNIFIER_X_MIN_COORD = AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_X_MIN_COORD;                                                                
uint16_t AHMIM_STM_D_4CAM_MAGNIFIER_X_MAX_COORD = AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_X_MAX_COORD;
uint16_t AHMIM_STM_D_4CAM_MAGNIFIER_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_Y_MIN_COORD;                                                                
uint16_t AHMIM_STM_D_4CAM_MAGNIFIER_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_Y_MAX_COORD;

uint16_t AHMIM_STM_D_1CAM_MAGNIFIER_X_MIN_COORD = AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_X_MIN_COORD;                                                                
uint16_t AHMIM_STM_D_1CAM_MAGNIFIER_X_MAX_COORD = AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_X_MAX_COORD;
uint16_t AHMIM_STM_D_1CAM_MAGNIFIER_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_Y_MIN_COORD;                                                                
uint16_t AHMIM_STM_D_1CAM_MAGNIFIER_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_Y_MAX_COORD;

/*X Button - Image Defeat touch coordinates*/                                                          
uint16 AHMIM_STM_D_XBTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_XBTN_X_MIN_COORD;                                                      
uint16 AHMIM_STM_D_XBTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_XBTN_X_MAX_COORD;
uint16 AHMIM_STM_D_XBTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_XBTN_Y_MIN_COORD;                                                      
uint16 AHMIM_STM_D_XBTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_XBTN_Y_MAX_COORD;

/*RTV - Rear Top View touch coordinates*/
uint16 AHMIM_STM_D_RTV_X_MIN_COORD = AHMIM_STM_D_TYPE_7_RTV_X_MIN_COORD;                                                 
uint16 AHMIM_STM_D_RTV_X_MAX_COORD = AHMIM_STM_D_TYPE_7_RTV_X_MAX_COORD;
uint16 AHMIM_STM_D_RTV_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_RTV_Y_MIN_COORD;                                               
uint16 AHMIM_STM_D_RTV_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_RTV_Y_MAX_COORD;

/*RCV - Rear Cross Path View touch coordinates*/
uint16 AHMIM_STM_D_RCV_X_MIN_COORD = AHMIM_STM_D_TYPE_7_RCV_X_MIN_COORD;                                               
uint16 AHMIM_STM_D_RCV_X_MAX_COORD = AHMIM_STM_D_TYPE_7_RCV_X_MAX_COORD;
uint16 AHMIM_STM_D_RCV_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_RCV_Y_MIN_COORD;                                               
uint16 AHMIM_STM_D_RCV_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_RCV_Y_MAX_COORD;

/*FCV - Front Cross Path View touch coordinates*/
uint16 AHMIM_STM_D_FCV_X_MIN_COORD = AHMIM_STM_D_TYPE_7_FCV_X_MIN_COORD;                                                
uint16 AHMIM_STM_D_FCV_X_MAX_COORD = AHMIM_STM_D_TYPE_7_FCV_X_MAX_COORD;
uint16 AHMIM_STM_D_FCV_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_FCV_Y_MIN_COORD;                                               
uint16 AHMIM_STM_D_FCV_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_FCV_Y_MAX_COORD;

/*FTV - Front Top View touch coordinates*/
uint16 AHMIM_STM_D_FTV_X_MIN_COORD = AHMIM_STM_D_TYPE_7_FTV_X_MIN_COORD;                                                
uint16 AHMIM_STM_D_FTV_X_MAX_COORD = AHMIM_STM_D_TYPE_7_FTV_X_MAX_COORD;
uint16 AHMIM_STM_D_FTV_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_FTV_Y_MIN_COORD;                                               
uint16 AHMIM_STM_D_FTV_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_FTV_Y_MAX_COORD;

/*BURV or RVC - Backup Rear View touch coordinates*/
uint16 AHMIM_STM_D_RVC_X_MIN_COORD = AHMIM_STM_D_TYPE_7_RVC_X_MIN_COORD;                                                
uint16 AHMIM_STM_D_RVC_X_MAX_COORD = AHMIM_STM_D_TYPE_7_RVC_X_MAX_COORD;
uint16 AHMIM_STM_D_RVC_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_RVC_Y_MIN_COORD;                                               
uint16 AHMIM_STM_D_RVC_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_RVC_Y_MAX_COORD;

/*FFCV- Front Facing Camera View, Can be present or absent based on Proxi*/
uint16 AHMIM_STM_D_FFCVBTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_FFCVBTN_X_MIN_COORD;                                                
uint16 AHMIM_STM_D_FFCVBTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_FFCVBTN_X_MAX_COORD;
uint16 AHMIM_STM_D_FFCVBTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_FFCVBTN_Y_MIN_COORD;                                               
uint16 AHMIM_STM_D_FFCVBTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_FFCVBTN_Y_MAX_COORD;

/********************AUX CAM BUTTON*********************/
/*FFC = Present*/
uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_X_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_X_MIN_COORD;                                                
uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_X_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_X_MAX_COORD;
uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_Y_MIN_COORD;                                               
uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_Y_MAX_COORD;
/*FFC = Absent*/
uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_X_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_X_MIN_COORD;                                                
uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_X_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_X_MAX_COORD;
uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_Y_MIN_COORD;                                               
uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_Y_MAX_COORD;
/*******************************************************/

/********************MORE CAMS BUTTON******************/
/*FFC = Present*/
uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_X_MIN_COORD;                                                
uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_X_MAX_COORD;
uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_Y_MIN_COORD;                                               
uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_Y_MAX_COORD;
/*FFC = Absent*/
uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_X_MIN_COORD;                                                
uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_X_MAX_COORD;
uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_Y_MIN_COORD;                                               
uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_Y_MAX_COORD;
/****************************************************/

/**********************TRG Buttons*******************/
/* TRG Left */
uint16 AHMIM_STM_D_TRGLEFT_X_MIN_COORD = AHMIM_STM_D_TYPE_7_TRGLEFT_X_MIN_COORD;                                                
uint16 AHMIM_STM_D_TRGLEFT_X_MAX_COORD = AHMIM_STM_D_TYPE_7_TRGLEFT_X_MAX_COORD;
uint16 AHMIM_STM_D_TRGLEFT_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_TRGLEFT_Y_MIN_COORD;                                               
uint16 AHMIM_STM_D_TRGLEFT_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_TRGLEFT_Y_MAX_COORD;
/* TRG Right */
uint16 AHMIM_STM_D_TRGRIGHT_X_MIN_COORD = AHMIM_STM_D_TYPE_7_TRGRIGHT_X_MIN_COORD;                                                
uint16 AHMIM_STM_D_TRGRIGHT_X_MAX_COORD = AHMIM_STM_D_TYPE_7_TRGRIGHT_X_MAX_COORD;
uint16 AHMIM_STM_D_TRGRIGHT_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_TRGRIGHT_Y_MIN_COORD;                                               
uint16 AHMIM_STM_D_TRGRIGHT_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_TRGRIGHT_Y_MAX_COORD;
/* TRG Auto */
uint16 AHMIM_STM_D_TRGAUTO_X_MIN_COORD = AHMIM_STM_D_TYPE_7_TRGAUTO_X_MIN_COORD;                                                
uint16 AHMIM_STM_D_TRGAUTO_X_MAX_COORD = AHMIM_STM_D_TYPE_7_TRGAUTO_X_MAX_COORD;
uint16 AHMIM_STM_D_TRGAUTO_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_TRGAUTO_Y_MIN_COORD;                                               
uint16 AHMIM_STM_D_TRGAUTO_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_TRGAUTO_Y_MAX_COORD;
/*************************************************/

/********************************************* THA Soft Buttons Dimensions in Pixels  ********************************/
uint16 AHMIM_STM_D_THA_SCRN_TCH_PRSD_X_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_SCRN_TCH_PRSD_X_MIN_COORD; 
uint16 AHMIM_STM_D_THA_SCRN_TCH_PRSD_X_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_SCRN_TCH_PRSD_X_MAX_COORD; 
uint16 AHMIM_STM_D_THA_SCRN_TCH_PRSD_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_SCRN_TCH_PRSD_Y_MIN_COORD; 
uint16 AHMIM_STM_D_THA_SCRN_TCH_PRSD_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_SCRN_TCH_PRSD_Y_MAX_COORD; 


uint16 AHMIM_STM_D_THA_CNFRM_BTN_PRSD_X_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_CNFRM_BTN_PRSD_X_MIN_COORD; 
uint16 AHMIM_STM_D_THA_CNFRM_BTN_PRSD_X_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_CNFRM_BTN_PRSD_X_MAX_COORD; 
uint16 AHMIM_STM_D_THA_CNFRM_BTN_PRSD_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_CNFRM_BTN_PRSD_Y_MIN_COORD; 
uint16 AHMIM_STM_D_THA_CNFRM_BTN_PRSD_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_CNFRM_BTN_PRSD_Y_MAX_COORD; 

uint16 AHMIM_STM_D_THA_START_BTN_PRSD_X_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_START_BTN_PRSD_X_MIN_COORD; 
uint16 AHMIM_STM_D_THA_START_BTN_PRSD_X_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_START_BTN_PRSD_X_MAX_COORD; 
uint16 AHMIM_STM_D_THA_START_BTN_PRSD_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_START_BTN_PRSD_Y_MIN_COORD; 
uint16 AHMIM_STM_D_THA_START_BTN_PRSD_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_START_BTN_PRSD_Y_MAX_COORD; 

uint16 AHMIM_STM_D_THA_BTN_PRSD_X_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_BTN_PRSD_X_MIN_COORD; 
uint16 AHMIM_STM_D_THA_BTN_PRSD_X_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_BTN_PRSD_X_MAX_COORD; 
uint16 AHMIM_STM_D_THA_BTN_PRSD_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_BTN_PRSD_Y_MIN_COORD; 
uint16 AHMIM_STM_D_THA_BTN_PRSD_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_BTN_PRSD_Y_MAX_COORD; 

uint16 AHMIM_STM_D_THA_ZMOUT_PRSD_X_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_ZMOUT_PRSD_X_MIN_COORD; 
uint16 AHMIM_STM_D_THA_ZMOUT_PRSD_X_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_ZMOUT_PRSD_X_MAX_COORD; 
uint16 AHMIM_STM_D_THA_ZMOUT_PRSD_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_ZMOUT_PRSD_Y_MIN_COORD; 
uint16 AHMIM_STM_D_THA_ZMOUT_PRSD_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_ZMOUT_PRSD_Y_MAX_COORD; 

/********************************************* THA Soft Buttons Dimensions in Pixels  ********************************/

/********************AP SOFTBUTTONS***************************/

uint16 AHMIM_STM_D_AP_BACK_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_BACK_BTN_X_MIN_COORD;
uint16 AHMIM_STM_D_AP_BACK_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_BACK_BTN_X_MAX_COORD;
uint16 AHMIM_STM_D_AP_BACK_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_BACK_BTN_Y_MIN_COORD;
uint16 AHMIM_STM_D_AP_BACK_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_BACK_BTN_Y_MAX_COORD;

uint16 AHMIM_STM_D_AP_PARK_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_PARK_BTN_X_MIN_COORD;
uint16 AHMIM_STM_D_AP_PARK_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_PARK_BTN_X_MAX_COORD;
uint16 AHMIM_STM_D_AP_PARK_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_PARK_BTN_Y_MIN_COORD;
uint16 AHMIM_STM_D_AP_PARK_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_PARK_BTN_Y_MAX_COORD;

uint16 AHMIM_STM_D_AP_EXIT_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_EXIT_BTN_X_MIN_COORD;
uint16 AHMIM_STM_D_AP_EXIT_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_EXIT_BTN_X_MAX_COORD;
uint16 AHMIM_STM_D_AP_EXIT_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_EXIT_BTN_Y_MIN_COORD;
uint16 AHMIM_STM_D_AP_EXIT_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_EXIT_BTN_Y_MAX_COORD;

uint16 AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_RIGHT_FWD_OUT_BTN_X_MIN_COORD ;
uint16 AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_RIGHT_FWD_OUT_BTN_X_MAX_COORD ;
uint16 AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_RIGHT_FWD_OUT_BTN_Y_MIN_COORD ;
uint16 AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_RIGHT_FWD_OUT_BTN_Y_MAX_COORD ;

uint16 AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_LEFT_FWD_OUT_BTN_X_MIN_COORD ;
uint16 AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_LEFT_FWD_OUT_BTN_X_MAX_COORD ;
uint16 AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_LEFT_FWD_OUT_BTN_Y_MIN_COORD ;
uint16 AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_LEFT_FWD_OUT_BTN_Y_MAX_COORD ;

uint16 AHMIM_STM_D_AP_FRONT_IN_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_FRONT_IN_BTN_X_MIN_COORD ;
uint16 AHMIM_STM_D_AP_FRONT_IN_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_FRONT_IN_BTN_X_MAX_COORD ;
uint16 AHMIM_STM_D_AP_FRONT_IN_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_FRONT_IN_BTN_Y_MIN_COORD ;
uint16 AHMIM_STM_D_AP_FRONT_IN_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_FRONT_IN_BTN_Y_MAX_COORD ;

uint16 AHMIM_STM_D_AP_REAR_IN_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_REAR_IN_BTN_X_MIN_COORD ;
uint16 AHMIM_STM_D_AP_REAR_IN_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_REAR_IN_BTN_X_MAX_COORD ;
uint16 AHMIM_STM_D_AP_REAR_IN_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_REAR_IN_BTN_Y_MIN_COORD ;
uint16 AHMIM_STM_D_AP_REAR_IN_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_REAR_IN_BTN_Y_MAX_COORD ;

uint16 AHMIM_STM_D_AP_PARKSLOT_HEIGHT       = AHMIM_STM_D_TYPE_7_AP_PARKSLOT_HEIGHT;
uint16 AHMIM_STM_D_AP_PARKSLOT_WIDTH        = AHMIM_STM_D_TYPE_7_AP_PARKSLOT_WIDTH;
uint16 AHMIM_STM_D_AP_PARKSLOT_MIN_Y        = AHMIM_STM_D_TYPE_7_AP_PARKSLOT_MIN_Y;
uint16 AHMIM_STM_D_AP_PARKSLOT_MAX_Y        = AHMIM_STM_D_TYPE_7_AP_PARKSLOT_MAX_Y;
uint16 AHMIM_STM_D_AP_PARKSLOT_SEPRATION    = AHMIM_STM_D_TYPE_7_AP_PARKSLOT_SEPRATION;

uint16 AHMIM_STM_D_AP_PARKSLOT_X1    =  AHMIM_STM_D_TYPE_7_AP_PARKSLOT_X1;
uint16 AHMIM_STM_D_AP_PARKSLOT_X2    =  AHMIM_STM_D_TYPE_7_AP_PARKSLOT_X2;
uint16 AHMIM_STM_D_AP_PARKSLOT_X3    =  AHMIM_STM_D_TYPE_7_AP_PARKSLOT_X3;
uint16 AHMIM_STM_D_AP_PIXEL_CAR_ORIGIN_Y       =  AHMIM_STM_D_TYPE_7_AP_PIXEL_CAR_ORIGIN_Y;
uint16 AHMIM_STM_D_AP_WORLD_TO_PIXEL_FACTOR  =  AHMIM_STM_D_TYPE_7_AP_WORLD_TO_PIXEL_FACTOR;
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!************FUNCTION************!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

uint8 Last_RadDispType = 0x7u;
BOOL  Last_camConfig   = TRUE;
BOOL  Last_auxConfig   = TRUE;

void aHmiM_STM_f_UpdateScrnType_v(uint8 Current_RadDispType, BOOL fourCamConfigEnbld, BOOL isAuxEnabled)
{
  /* DD-ID: {BB5138AA-CE1D-45a7-89C8-91932F789743}*/
    if(Last_RadDispType != Current_RadDispType || Last_camConfig != fourCamConfigEnbld || Last_auxConfig != isAuxEnabled)
    {
        if(Last_RadDispType != Current_RadDispType)
        printf("Touch Processing changed from: %u, to: %u\n",Last_RadDispType, Current_RadDispType);
        
        if(Last_camConfig != fourCamConfigEnbld)
        printf("SVS Enabled changed from: %u to %u\n",Last_camConfig, fourCamConfigEnbld);

        if(Last_auxConfig != isAuxEnabled)
        printf("AUX Enabled changed from: %u to %u\n",Last_auxConfig, isAuxEnabled);

        if(0x02u == Current_RadDispType || 0x09u == Current_RadDispType)
        {
            /*Zoom In and zoom out touch coordinates*/
            AHMIM_STM_D_4CAM_MAGNIFIER_X_MIN_COORD = AHMIM_STM_D_TYPE_29_TYPE_4CAM_MAGNIFIER_X_MIN_COORD;                                                                
            AHMIM_STM_D_4CAM_MAGNIFIER_X_MAX_COORD = AHMIM_STM_D_TYPE_29_TYPE_4CAM_MAGNIFIER_X_MAX_COORD;
            AHMIM_STM_D_4CAM_MAGNIFIER_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_TYPE_4CAM_MAGNIFIER_Y_MIN_COORD;                                                                
            AHMIM_STM_D_4CAM_MAGNIFIER_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_TYPE_4CAM_MAGNIFIER_Y_MAX_COORD;

            AHMIM_STM_D_1CAM_MAGNIFIER_X_MIN_COORD = AHMIM_STM_D_TYPE_29_TYPE_1CAM_MAGNIFIER_X_MIN_COORD;                                                                
            AHMIM_STM_D_1CAM_MAGNIFIER_X_MAX_COORD = AHMIM_STM_D_TYPE_29_TYPE_1CAM_MAGNIFIER_X_MAX_COORD;
            AHMIM_STM_D_1CAM_MAGNIFIER_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_TYPE_1CAM_MAGNIFIER_Y_MIN_COORD;                                                                
            AHMIM_STM_D_1CAM_MAGNIFIER_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_TYPE_1CAM_MAGNIFIER_Y_MAX_COORD;

            /*X Button - Image Defeat touch coordinates*/                                                          
            AHMIM_STM_D_XBTN_X_MIN_COORD = AHMIM_STM_D_TYPE_29_XBTN_X_MIN_COORD;                                                      
            AHMIM_STM_D_XBTN_X_MAX_COORD = AHMIM_STM_D_TYPE_29_XBTN_X_MAX_COORD;
            AHMIM_STM_D_XBTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_XBTN_Y_MIN_COORD;                                                      
            AHMIM_STM_D_XBTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_XBTN_Y_MAX_COORD;

            /*RTV - Rear Top View touch coordinates*/
            AHMIM_STM_D_RTV_X_MIN_COORD = AHMIM_STM_D_TYPE_29_RTV_X_MIN_COORD;                                                 
            AHMIM_STM_D_RTV_X_MAX_COORD = AHMIM_STM_D_TYPE_29_RTV_X_MAX_COORD;
            AHMIM_STM_D_RTV_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_RTV_Y_MIN_COORD;                                               
            AHMIM_STM_D_RTV_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_RTV_Y_MAX_COORD;

            /*RCV - Rear Cross Path View touch coordinates*/
            AHMIM_STM_D_RCV_X_MIN_COORD = AHMIM_STM_D_TYPE_29_RCV_X_MIN_COORD;                                               
            AHMIM_STM_D_RCV_X_MAX_COORD = AHMIM_STM_D_TYPE_29_RCV_X_MAX_COORD;
            AHMIM_STM_D_RCV_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_RCV_Y_MIN_COORD;                                               
            AHMIM_STM_D_RCV_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_RCV_Y_MAX_COORD;

            /*FCV - Front Cross Path View touch coordinates*/
            AHMIM_STM_D_FCV_X_MIN_COORD = AHMIM_STM_D_TYPE_29_FCV_X_MIN_COORD;                                                
            AHMIM_STM_D_FCV_X_MAX_COORD = AHMIM_STM_D_TYPE_29_FCV_X_MAX_COORD;
            AHMIM_STM_D_FCV_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_FCV_Y_MIN_COORD;                                               
            AHMIM_STM_D_FCV_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_FCV_Y_MAX_COORD;

            /*FTV - Front Top View touch coordinates*/
            AHMIM_STM_D_FTV_X_MIN_COORD = AHMIM_STM_D_TYPE_29_FTV_X_MIN_COORD;                                                
            AHMIM_STM_D_FTV_X_MAX_COORD = AHMIM_STM_D_TYPE_29_FTV_X_MAX_COORD;
            AHMIM_STM_D_FTV_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_FTV_Y_MIN_COORD;                                               
            AHMIM_STM_D_FTV_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_FTV_Y_MAX_COORD;

            /*BURV or RVC - Backup Rear View touch coordinates*/
            AHMIM_STM_D_RVC_X_MIN_COORD = AHMIM_STM_D_TYPE_29_RVC_X_MIN_COORD;                                                
            AHMIM_STM_D_RVC_X_MAX_COORD = AHMIM_STM_D_TYPE_29_RVC_X_MAX_COORD;
            AHMIM_STM_D_RVC_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_RVC_Y_MIN_COORD;                                               
            AHMIM_STM_D_RVC_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_RVC_Y_MAX_COORD;

            /*FFCV- Front Facing Camera View, Can be present or absent based on Proxi*/
            AHMIM_STM_D_FFCVBTN_X_MIN_COORD = AHMIM_STM_D_TYPE_29_FFCVBTN_X_MIN_COORD;                                                
            AHMIM_STM_D_FFCVBTN_X_MAX_COORD = AHMIM_STM_D_TYPE_29_FFCVBTN_X_MAX_COORD;
            AHMIM_STM_D_FFCVBTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_FFCVBTN_Y_MIN_COORD;                                               
            AHMIM_STM_D_FFCVBTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_FFCVBTN_Y_MAX_COORD;

            if(fourCamConfigEnbld == TRUE)
            {
            /********************AUX CAM BUTTON*********************/
            /*FFC = Present*/
                AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_X_MIN_COORD = AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_PRSNT_AUXCAM_X_MIN_COORD;                                                
                AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_X_MAX_COORD = AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_PRSNT_AUXCAM_X_MAX_COORD;
                AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_PRSNT_AUXCAM_Y_MIN_COORD;                                               
                AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_PRSNT_AUXCAM_Y_MAX_COORD;
            /*FFC = Absent*/
                AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_X_MIN_COORD = AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_ABSNT_AUXCAM_X_MIN_COORD;                                                
                AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_X_MAX_COORD = AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_ABSNT_AUXCAM_X_MAX_COORD;
                AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_ABSNT_AUXCAM_Y_MIN_COORD;                                               
                AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_ABSNT_AUXCAM_Y_MAX_COORD;
            }
            else if(isAuxEnabled == 1U)
            {
                AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_X_MIN_COORD = AHMIM_STM_D_TYPE_29_TYPE_1CAM_VC_AUXCAM_X_MIN_COORD;                                                
                AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_X_MAX_COORD = AHMIM_STM_D_TYPE_29_TYPE_1CAM_VC_AUXCAM_X_MAX_COORD;
                AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_TYPE_1CAM_VC_AUXCAM_Y_MIN_COORD;                                               
                AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_TYPE_1CAM_VC_AUXCAM_Y_MAX_COORD;
            }
            else
            {
                AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_X_MIN_COORD = 2000U;                                                
                AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_X_MAX_COORD = 2000U;
                AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_Y_MIN_COORD = 2000U;                                               
                AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_Y_MAX_COORD = 2000U;
            }
            /*******************************************************/

            /********************MORE CAMS BUTTON******************/
            /*FFC = Present*/
            AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_29_VC_OFFROAD_PRSNT_MC_BTN_X_MIN_COORD;                                                
            AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_29_VC_OFFROAD_PRSNT_MC_BTN_X_MAX_COORD;
            AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_VC_OFFROAD_PRSNT_MC_BTN_Y_MIN_COORD;                                               
            AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_VC_OFFROAD_PRSNT_MC_BTN_Y_MAX_COORD;
            /*FFC = Absent*/
            AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_29_VC_OFFROAD_ABSNT_MC_BTN_X_MIN_COORD;                                                
            AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_29_VC_OFFROAD_ABSNT_MC_BTN_X_MAX_COORD;
            AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_VC_OFFROAD_ABSNT_MC_BTN_Y_MIN_COORD;                                               
            AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_VC_OFFROAD_ABSNT_MC_BTN_Y_MAX_COORD;
            /****************************************************/

            /**********************TRG Buttons*******************/
            /* TRG Left */
            AHMIM_STM_D_TRGLEFT_X_MIN_COORD = AHMIM_STM_D_TYPE_29_TRGLEFT_X_MIN_COORD;                                                
            AHMIM_STM_D_TRGLEFT_X_MAX_COORD = AHMIM_STM_D_TYPE_29_TRGLEFT_X_MAX_COORD;
            AHMIM_STM_D_TRGLEFT_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_TRGLEFT_Y_MIN_COORD;                                               
            AHMIM_STM_D_TRGLEFT_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_TRGLEFT_Y_MAX_COORD;
            /* TRG Right */
            AHMIM_STM_D_TRGRIGHT_X_MIN_COORD = AHMIM_STM_D_TYPE_29_TRGRIGHT_X_MIN_COORD;                                                
            AHMIM_STM_D_TRGRIGHT_X_MAX_COORD = AHMIM_STM_D_TYPE_29_TRGRIGHT_X_MAX_COORD;
            AHMIM_STM_D_TRGRIGHT_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_TRGRIGHT_Y_MIN_COORD;                                               
            AHMIM_STM_D_TRGRIGHT_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_TRGRIGHT_Y_MAX_COORD;
            /* TRG Auto */
            AHMIM_STM_D_TRGAUTO_X_MIN_COORD = AHMIM_STM_D_TYPE_29_TRGAUTO_X_MIN_COORD;                                                
            AHMIM_STM_D_TRGAUTO_X_MAX_COORD = AHMIM_STM_D_TYPE_29_TRGAUTO_X_MAX_COORD;
            AHMIM_STM_D_TRGAUTO_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_TRGAUTO_Y_MIN_COORD;                                               
            AHMIM_STM_D_TRGAUTO_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_TRGAUTO_Y_MAX_COORD;
            /*************************************************/

            /********************************************* THA Soft Buttons Dimensions in Pixels  ********************************/
            AHMIM_STM_D_THA_SCRN_TCH_PRSD_X_MIN_COORD = AHMIM_STM_D_TYPE_29_THA_SCRN_TCH_PRSD_X_MIN_COORD; 
            AHMIM_STM_D_THA_SCRN_TCH_PRSD_X_MAX_COORD = AHMIM_STM_D_TYPE_29_THA_SCRN_TCH_PRSD_X_MAX_COORD; 
            AHMIM_STM_D_THA_SCRN_TCH_PRSD_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_THA_SCRN_TCH_PRSD_Y_MIN_COORD; 
            AHMIM_STM_D_THA_SCRN_TCH_PRSD_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_THA_SCRN_TCH_PRSD_Y_MAX_COORD; 

            AHMIM_STM_D_THA_CNFRM_BTN_PRSD_X_MIN_COORD = AHMIM_STM_D_TYPE_29_THA_CNFRM_BTN_PRSD_X_MIN_COORD; 
            AHMIM_STM_D_THA_CNFRM_BTN_PRSD_X_MAX_COORD = AHMIM_STM_D_TYPE_29_THA_CNFRM_BTN_PRSD_X_MAX_COORD; 
            AHMIM_STM_D_THA_CNFRM_BTN_PRSD_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_THA_CNFRM_BTN_PRSD_Y_MIN_COORD; 
            AHMIM_STM_D_THA_CNFRM_BTN_PRSD_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_THA_CNFRM_BTN_PRSD_Y_MAX_COORD; 

            AHMIM_STM_D_THA_START_BTN_PRSD_X_MIN_COORD = AHMIM_STM_D_TYPE_29_THA_START_BTN_PRSD_X_MIN_COORD; 
            AHMIM_STM_D_THA_START_BTN_PRSD_X_MAX_COORD = AHMIM_STM_D_TYPE_29_THA_START_BTN_PRSD_X_MAX_COORD; 
            AHMIM_STM_D_THA_START_BTN_PRSD_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_THA_START_BTN_PRSD_Y_MIN_COORD; 
            AHMIM_STM_D_THA_START_BTN_PRSD_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_THA_START_BTN_PRSD_Y_MAX_COORD; 

            AHMIM_STM_D_THA_BTN_PRSD_X_MIN_COORD = AHMIM_STM_D_TYPE_29_THA_BTN_PRSD_X_MIN_COORD; 
            AHMIM_STM_D_THA_BTN_PRSD_X_MAX_COORD = AHMIM_STM_D_TYPE_29_THA_BTN_PRSD_X_MAX_COORD; 
            AHMIM_STM_D_THA_BTN_PRSD_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_THA_BTN_PRSD_Y_MIN_COORD; 
            AHMIM_STM_D_THA_BTN_PRSD_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_THA_BTN_PRSD_Y_MAX_COORD; 

            AHMIM_STM_D_THA_ZMOUT_PRSD_X_MIN_COORD = AHMIM_STM_D_TYPE_29_THA_ZMOUT_PRSD_X_MIN_COORD; 
            AHMIM_STM_D_THA_ZMOUT_PRSD_X_MAX_COORD = AHMIM_STM_D_TYPE_29_THA_ZMOUT_PRSD_X_MAX_COORD; 
            AHMIM_STM_D_THA_ZMOUT_PRSD_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_THA_ZMOUT_PRSD_Y_MIN_COORD; 
            AHMIM_STM_D_THA_ZMOUT_PRSD_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_THA_ZMOUT_PRSD_Y_MAX_COORD; 

            /***********************************************************************/

            /***********************AP SOFT BUTTONS*******************/
            AHMIM_STM_D_AP_BACK_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_29_AP_BACK_BTN_X_MIN_COORD;
            AHMIM_STM_D_AP_BACK_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_29_AP_BACK_BTN_X_MAX_COORD;
            AHMIM_STM_D_AP_BACK_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_AP_BACK_BTN_Y_MIN_COORD;
            AHMIM_STM_D_AP_BACK_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_AP_BACK_BTN_Y_MAX_COORD;

            AHMIM_STM_D_AP_PARK_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_29_AP_PARK_BTN_X_MIN_COORD;
            AHMIM_STM_D_AP_PARK_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_29_AP_PARK_BTN_X_MAX_COORD;
            AHMIM_STM_D_AP_PARK_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_AP_PARK_BTN_Y_MIN_COORD;
            AHMIM_STM_D_AP_PARK_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_AP_PARK_BTN_Y_MAX_COORD;

            AHMIM_STM_D_AP_EXIT_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_29_AP_EXIT_BTN_X_MIN_COORD;
            AHMIM_STM_D_AP_EXIT_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_29_AP_EXIT_BTN_X_MAX_COORD;
            AHMIM_STM_D_AP_EXIT_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_AP_EXIT_BTN_Y_MIN_COORD;
            AHMIM_STM_D_AP_EXIT_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_AP_EXIT_BTN_Y_MAX_COORD;

            AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_29_AP_RIGHT_FWD_OUT_BTN_X_MIN_COORD ;
            AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_29_AP_RIGHT_FWD_OUT_BTN_X_MAX_COORD ;
            AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_AP_RIGHT_FWD_OUT_BTN_Y_MIN_COORD ;
            AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_AP_RIGHT_FWD_OUT_BTN_Y_MAX_COORD ;

            AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_29_AP_LEFT_FWD_OUT_BTN_X_MIN_COORD ;
            AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_29_AP_LEFT_FWD_OUT_BTN_X_MAX_COORD ;
            AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_AP_LEFT_FWD_OUT_BTN_Y_MIN_COORD ;
            AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_AP_LEFT_FWD_OUT_BTN_Y_MAX_COORD ;

            AHMIM_STM_D_AP_FRONT_IN_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_29_AP_FRONT_IN_BTN_X_MIN_COORD ;
            AHMIM_STM_D_AP_FRONT_IN_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_29_AP_FRONT_IN_BTN_X_MAX_COORD ;
            AHMIM_STM_D_AP_FRONT_IN_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_AP_FRONT_IN_BTN_Y_MIN_COORD ;
            AHMIM_STM_D_AP_FRONT_IN_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_AP_FRONT_IN_BTN_Y_MAX_COORD ;

            AHMIM_STM_D_AP_REAR_IN_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_29_AP_REAR_IN_BTN_X_MIN_COORD ;
            AHMIM_STM_D_AP_REAR_IN_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_29_AP_REAR_IN_BTN_X_MAX_COORD ;
            AHMIM_STM_D_AP_REAR_IN_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_29_AP_REAR_IN_BTN_Y_MIN_COORD ;
            AHMIM_STM_D_AP_REAR_IN_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_29_AP_REAR_IN_BTN_Y_MAX_COORD ;

            AHMIM_STM_D_AP_PARKSLOT_HEIGHT       = AHMIM_STM_D_TYPE_29_AP_PARKSLOT_HEIGHT;
            AHMIM_STM_D_AP_PARKSLOT_WIDTH        = AHMIM_STM_D_TYPE_29_AP_PARKSLOT_WIDTH;
            AHMIM_STM_D_AP_PARKSLOT_MIN_Y        = AHMIM_STM_D_TYPE_29_AP_PARKSLOT_MIN_Y;
            AHMIM_STM_D_AP_PARKSLOT_MAX_Y        = AHMIM_STM_D_TYPE_29_AP_PARKSLOT_MAX_Y;
            AHMIM_STM_D_AP_PARKSLOT_SEPRATION    = AHMIM_STM_D_TYPE_29_AP_PARKSLOT_SEPRATION;

            AHMIM_STM_D_AP_PARKSLOT_X1    =  AHMIM_STM_D_TYPE_29_AP_PARKSLOT_X1;
            AHMIM_STM_D_AP_PARKSLOT_X2    =  AHMIM_STM_D_TYPE_29_AP_PARKSLOT_X2;
            AHMIM_STM_D_AP_PARKSLOT_X3    =  AHMIM_STM_D_TYPE_29_AP_PARKSLOT_X3;

            AHMIM_STM_D_AP_PIXEL_CAR_ORIGIN_Y       =  AHMIM_STM_D_TYPE_29_AP_PIXEL_CAR_ORIGIN_Y;
            AHMIM_STM_D_AP_WORLD_TO_PIXEL_FACTOR    =  AHMIM_STM_D_TYPE_29_AP_WORLD_TO_PIXEL_FACTOR;         
        }
        else if(0x07u == Current_RadDispType)
        {         
            /*Zoom In and zoom out touch coordinates*/
            AHMIM_STM_D_4CAM_MAGNIFIER_X_MIN_COORD = AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_X_MIN_COORD;                                                                
            AHMIM_STM_D_4CAM_MAGNIFIER_X_MAX_COORD = AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_X_MAX_COORD;
            AHMIM_STM_D_4CAM_MAGNIFIER_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_Y_MIN_COORD;                                                                
            AHMIM_STM_D_4CAM_MAGNIFIER_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_Y_MAX_COORD;

            AHMIM_STM_D_1CAM_MAGNIFIER_X_MIN_COORD = AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_X_MIN_COORD;                                                                
            AHMIM_STM_D_1CAM_MAGNIFIER_X_MAX_COORD = AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_X_MAX_COORD;
            AHMIM_STM_D_1CAM_MAGNIFIER_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_Y_MIN_COORD;                                                                
            AHMIM_STM_D_1CAM_MAGNIFIER_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_Y_MAX_COORD;

            /*X Button - Image Defeat touch coordinates*/                                                          
            AHMIM_STM_D_XBTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_XBTN_X_MIN_COORD;                                                      
            AHMIM_STM_D_XBTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_XBTN_X_MAX_COORD;
            AHMIM_STM_D_XBTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_XBTN_Y_MIN_COORD;                                                      
            AHMIM_STM_D_XBTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_XBTN_Y_MAX_COORD;

            /*RTV - Rear Top View touch coordinates*/
            AHMIM_STM_D_RTV_X_MIN_COORD = AHMIM_STM_D_TYPE_7_RTV_X_MIN_COORD;                                                 
            AHMIM_STM_D_RTV_X_MAX_COORD = AHMIM_STM_D_TYPE_7_RTV_X_MAX_COORD;
            AHMIM_STM_D_RTV_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_RTV_Y_MIN_COORD;                                               
            AHMIM_STM_D_RTV_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_RTV_Y_MAX_COORD;

            /*RCV - Rear Cross Path View touch coordinates*/
            AHMIM_STM_D_RCV_X_MIN_COORD = AHMIM_STM_D_TYPE_7_RCV_X_MIN_COORD;                                               
            AHMIM_STM_D_RCV_X_MAX_COORD = AHMIM_STM_D_TYPE_7_RCV_X_MAX_COORD;
            AHMIM_STM_D_RCV_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_RCV_Y_MIN_COORD;                                               
            AHMIM_STM_D_RCV_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_RCV_Y_MAX_COORD;

            /*FCV - Front Cross Path View touch coordinates*/
            AHMIM_STM_D_FCV_X_MIN_COORD = AHMIM_STM_D_TYPE_7_FCV_X_MIN_COORD;                                                
            AHMIM_STM_D_FCV_X_MAX_COORD = AHMIM_STM_D_TYPE_7_FCV_X_MAX_COORD;
            AHMIM_STM_D_FCV_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_FCV_Y_MIN_COORD;                                               
            AHMIM_STM_D_FCV_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_FCV_Y_MAX_COORD;

            /*FTV - Front Top View touch coordinates*/
            AHMIM_STM_D_FTV_X_MIN_COORD = AHMIM_STM_D_TYPE_7_FTV_X_MIN_COORD;                                                
            AHMIM_STM_D_FTV_X_MAX_COORD = AHMIM_STM_D_TYPE_7_FTV_X_MAX_COORD;
            AHMIM_STM_D_FTV_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_FTV_Y_MIN_COORD;                                               
            AHMIM_STM_D_FTV_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_FTV_Y_MAX_COORD;

            /*BURV or RVC - Backup Rear View touch coordinates*/
            AHMIM_STM_D_RVC_X_MIN_COORD = AHMIM_STM_D_TYPE_7_RVC_X_MIN_COORD;                                                
            AHMIM_STM_D_RVC_X_MAX_COORD = AHMIM_STM_D_TYPE_7_RVC_X_MAX_COORD;
            AHMIM_STM_D_RVC_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_RVC_Y_MIN_COORD;                                               
            AHMIM_STM_D_RVC_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_RVC_Y_MAX_COORD;

            /*FFCV- Front Facing Camera View, Can be present or absent based on Proxi*/
            AHMIM_STM_D_FFCVBTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_FFCVBTN_X_MIN_COORD;                                                
            AHMIM_STM_D_FFCVBTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_FFCVBTN_X_MAX_COORD;
            AHMIM_STM_D_FFCVBTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_FFCVBTN_Y_MIN_COORD;                                               
            AHMIM_STM_D_FFCVBTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_FFCVBTN_Y_MAX_COORD;

            /********************AUX CAM BUTTON*********************/
            /*FFC = Present*/
            AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_X_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_X_MIN_COORD;                                                
            AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_X_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_X_MAX_COORD;
            AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_Y_MIN_COORD;                                               
            AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_Y_MAX_COORD;
            /*FFC = Absent*/
            AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_X_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_X_MIN_COORD;                                                
            AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_X_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_X_MAX_COORD;
            AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_Y_MIN_COORD;                                               
            AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_Y_MAX_COORD;
            /*******************************************************/

            /********************MORE CAMS BUTTON******************/
            /*FFC = Present*/
            AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_X_MIN_COORD;                                                
            AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_X_MAX_COORD;
            AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_Y_MIN_COORD;                                               
            AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_Y_MAX_COORD;
            /*FFC = Absent*/
            AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_X_MIN_COORD;                                                
            AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_X_MAX_COORD;
            AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_Y_MIN_COORD;                                               
            AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_Y_MAX_COORD;
            /****************************************************/

            /**********************TRG Buttons*******************/
            /* TRG Left */
            AHMIM_STM_D_TRGLEFT_X_MIN_COORD = AHMIM_STM_D_TYPE_7_TRGLEFT_X_MIN_COORD;                                                
            AHMIM_STM_D_TRGLEFT_X_MAX_COORD = AHMIM_STM_D_TYPE_7_TRGLEFT_X_MAX_COORD;
            AHMIM_STM_D_TRGLEFT_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_TRGLEFT_Y_MIN_COORD;                                               
            AHMIM_STM_D_TRGLEFT_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_TRGLEFT_Y_MAX_COORD;
            /* TRG Right */
            AHMIM_STM_D_TRGRIGHT_X_MIN_COORD = AHMIM_STM_D_TYPE_7_TRGRIGHT_X_MIN_COORD;                                                
            AHMIM_STM_D_TRGRIGHT_X_MAX_COORD = AHMIM_STM_D_TYPE_7_TRGRIGHT_X_MAX_COORD;
            AHMIM_STM_D_TRGRIGHT_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_TRGRIGHT_Y_MIN_COORD;                                               
            AHMIM_STM_D_TRGRIGHT_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_TRGRIGHT_Y_MAX_COORD;
            /* TRG Auto */
            AHMIM_STM_D_TRGAUTO_X_MIN_COORD = AHMIM_STM_D_TYPE_7_TRGAUTO_X_MIN_COORD;                                                
            AHMIM_STM_D_TRGAUTO_X_MAX_COORD = AHMIM_STM_D_TYPE_7_TRGAUTO_X_MAX_COORD;
            AHMIM_STM_D_TRGAUTO_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_TRGAUTO_Y_MIN_COORD;                                               
            AHMIM_STM_D_TRGAUTO_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_TRGAUTO_Y_MAX_COORD;
            /*************************************************/

            /********************************************* THA Soft Buttons Dimensions in Pixels  ********************************/
            AHMIM_STM_D_THA_SCRN_TCH_PRSD_X_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_SCRN_TCH_PRSD_X_MIN_COORD; 
            AHMIM_STM_D_THA_SCRN_TCH_PRSD_X_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_SCRN_TCH_PRSD_X_MAX_COORD; 
            AHMIM_STM_D_THA_SCRN_TCH_PRSD_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_SCRN_TCH_PRSD_Y_MIN_COORD; 
            AHMIM_STM_D_THA_SCRN_TCH_PRSD_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_SCRN_TCH_PRSD_Y_MAX_COORD; 

            AHMIM_STM_D_THA_CNFRM_BTN_PRSD_X_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_CNFRM_BTN_PRSD_X_MIN_COORD; 
            AHMIM_STM_D_THA_CNFRM_BTN_PRSD_X_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_CNFRM_BTN_PRSD_X_MAX_COORD; 
            AHMIM_STM_D_THA_CNFRM_BTN_PRSD_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_CNFRM_BTN_PRSD_Y_MIN_COORD; 
            AHMIM_STM_D_THA_CNFRM_BTN_PRSD_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_CNFRM_BTN_PRSD_Y_MAX_COORD; 

            AHMIM_STM_D_THA_START_BTN_PRSD_X_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_START_BTN_PRSD_X_MIN_COORD; 
            AHMIM_STM_D_THA_START_BTN_PRSD_X_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_START_BTN_PRSD_X_MAX_COORD; 
            AHMIM_STM_D_THA_START_BTN_PRSD_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_START_BTN_PRSD_Y_MIN_COORD; 
            AHMIM_STM_D_THA_START_BTN_PRSD_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_START_BTN_PRSD_Y_MAX_COORD; 

            AHMIM_STM_D_THA_BTN_PRSD_X_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_BTN_PRSD_X_MIN_COORD; 
            AHMIM_STM_D_THA_BTN_PRSD_X_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_BTN_PRSD_X_MAX_COORD; 
            AHMIM_STM_D_THA_BTN_PRSD_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_BTN_PRSD_Y_MIN_COORD; 
            AHMIM_STM_D_THA_BTN_PRSD_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_BTN_PRSD_Y_MAX_COORD; 

            AHMIM_STM_D_THA_ZMOUT_PRSD_X_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_ZMOUT_PRSD_X_MIN_COORD; 
            AHMIM_STM_D_THA_ZMOUT_PRSD_X_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_ZMOUT_PRSD_X_MAX_COORD; 
            AHMIM_STM_D_THA_ZMOUT_PRSD_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_THA_ZMOUT_PRSD_Y_MIN_COORD; 
            AHMIM_STM_D_THA_ZMOUT_PRSD_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_THA_ZMOUT_PRSD_Y_MAX_COORD;
            /***********************************************************************/

            /***********************AP SOFT BUTTONS*******************/
            AHMIM_STM_D_AP_BACK_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_BACK_BTN_X_MIN_COORD;
            AHMIM_STM_D_AP_BACK_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_BACK_BTN_X_MAX_COORD;
            AHMIM_STM_D_AP_BACK_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_BACK_BTN_Y_MIN_COORD;
            AHMIM_STM_D_AP_BACK_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_BACK_BTN_Y_MAX_COORD;

            AHMIM_STM_D_AP_PARK_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_PARK_BTN_X_MIN_COORD;
            AHMIM_STM_D_AP_PARK_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_PARK_BTN_X_MAX_COORD;
            AHMIM_STM_D_AP_PARK_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_PARK_BTN_Y_MIN_COORD;
            AHMIM_STM_D_AP_PARK_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_PARK_BTN_Y_MAX_COORD;

            AHMIM_STM_D_AP_EXIT_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_EXIT_BTN_X_MIN_COORD;
            AHMIM_STM_D_AP_EXIT_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_EXIT_BTN_X_MAX_COORD;
            AHMIM_STM_D_AP_EXIT_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_EXIT_BTN_Y_MIN_COORD;
            AHMIM_STM_D_AP_EXIT_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_EXIT_BTN_Y_MAX_COORD;

            AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_RIGHT_FWD_OUT_BTN_X_MIN_COORD ;
            AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_RIGHT_FWD_OUT_BTN_X_MAX_COORD ;
            AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_RIGHT_FWD_OUT_BTN_Y_MIN_COORD ;
            AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_RIGHT_FWD_OUT_BTN_Y_MAX_COORD ;

            AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_LEFT_FWD_OUT_BTN_X_MIN_COORD ;
            AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_LEFT_FWD_OUT_BTN_X_MAX_COORD ;
            AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_LEFT_FWD_OUT_BTN_Y_MIN_COORD ;
            AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_LEFT_FWD_OUT_BTN_Y_MAX_COORD ;

            AHMIM_STM_D_AP_FRONT_IN_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_FRONT_IN_BTN_X_MIN_COORD ;
            AHMIM_STM_D_AP_FRONT_IN_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_FRONT_IN_BTN_X_MAX_COORD ;
            AHMIM_STM_D_AP_FRONT_IN_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_FRONT_IN_BTN_Y_MIN_COORD ;
            AHMIM_STM_D_AP_FRONT_IN_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_FRONT_IN_BTN_Y_MAX_COORD ;

            AHMIM_STM_D_AP_REAR_IN_BTN_X_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_REAR_IN_BTN_X_MIN_COORD ;
            AHMIM_STM_D_AP_REAR_IN_BTN_X_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_REAR_IN_BTN_X_MAX_COORD ;
            AHMIM_STM_D_AP_REAR_IN_BTN_Y_MIN_COORD = AHMIM_STM_D_TYPE_7_AP_REAR_IN_BTN_Y_MIN_COORD ;
            AHMIM_STM_D_AP_REAR_IN_BTN_Y_MAX_COORD = AHMIM_STM_D_TYPE_7_AP_REAR_IN_BTN_Y_MAX_COORD ;

            AHMIM_STM_D_AP_PARKSLOT_HEIGHT       = AHMIM_STM_D_TYPE_7_AP_PARKSLOT_HEIGHT;
            AHMIM_STM_D_AP_PARKSLOT_WIDTH        = AHMIM_STM_D_TYPE_7_AP_PARKSLOT_WIDTH;
            AHMIM_STM_D_AP_PARKSLOT_MIN_Y        = AHMIM_STM_D_TYPE_7_AP_PARKSLOT_MIN_Y;
            AHMIM_STM_D_AP_PARKSLOT_MAX_Y        = AHMIM_STM_D_TYPE_7_AP_PARKSLOT_MAX_Y;
            AHMIM_STM_D_AP_PARKSLOT_SEPRATION    = AHMIM_STM_D_TYPE_7_AP_PARKSLOT_SEPRATION;

            AHMIM_STM_D_AP_PARKSLOT_X1    =  AHMIM_STM_D_TYPE_7_AP_PARKSLOT_X1;
            AHMIM_STM_D_AP_PARKSLOT_X2    =  AHMIM_STM_D_TYPE_7_AP_PARKSLOT_X2;
            AHMIM_STM_D_AP_PARKSLOT_X3    =  AHMIM_STM_D_TYPE_7_AP_PARKSLOT_X3;

            AHMIM_STM_D_AP_PIXEL_CAR_ORIGIN_Y       =  AHMIM_STM_D_TYPE_7_AP_PIXEL_CAR_ORIGIN_Y;
            AHMIM_STM_D_AP_WORLD_TO_PIXEL_FACTOR    =  AHMIM_STM_D_TYPE_7_AP_WORLD_TO_PIXEL_FACTOR; 
        }
        else
        {
            /*Do Nothing*/
        }

        Last_RadDispType = Current_RadDispType;
        Last_camConfig   = fourCamConfigEnbld;
        Last_auxConfig   = isAuxEnabled;
    }
    else
    {/*Do Nothing*/}

    return;
}