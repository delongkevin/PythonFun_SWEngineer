#ifndef AHMIM_STM_RADIODISP_INCLUDEGUARD
#define AHMIM_STM_RADIODISP_INCLUDEGUARD 

    #include "SignalDef.h"

    void aHmiM_STM_f_UpdateScrnType_v(uint8_t Current_RadDispType, BOOL camConfig, BOOL isAuxPrsnt);
    extern uint8 Last_MePRX_e_RadDispType;

    /*Zoom In and zoom out touch coordinates*/
    extern uint16 AHMIM_STM_D_4CAM_MAGNIFIER_X_MIN_COORD ;                                                                
    extern uint16 AHMIM_STM_D_4CAM_MAGNIFIER_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_4CAM_MAGNIFIER_Y_MIN_COORD ;                                                                
    extern uint16 AHMIM_STM_D_4CAM_MAGNIFIER_Y_MAX_COORD ;

    extern uint16 AHMIM_STM_D_1CAM_MAGNIFIER_X_MIN_COORD ;                                                                
    extern uint16 AHMIM_STM_D_1CAM_MAGNIFIER_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_1CAM_MAGNIFIER_Y_MIN_COORD ;                                                                
    extern uint16 AHMIM_STM_D_1CAM_MAGNIFIER_Y_MAX_COORD ;

    /*X Button - Image Defeat touch coordinates*/                                                         
    extern uint16 AHMIM_STM_D_XBTN_X_MIN_COORD ;                                                      
    extern uint16 AHMIM_STM_D_XBTN_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_XBTN_Y_MIN_COORD ;                                                      
    extern uint16 AHMIM_STM_D_XBTN_Y_MAX_COORD ;

    /*RTV - Rear Top View touch coordinates*/
    extern uint16 AHMIM_STM_D_RTV_X_MIN_COORD ;                                                 
    extern uint16 AHMIM_STM_D_RTV_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_RTV_Y_MIN_COORD ;                                               
    extern uint16 AHMIM_STM_D_RTV_Y_MAX_COORD ;

    /*RCV - Rear Cross Path View touch coordinates*/
    extern uint16 AHMIM_STM_D_RCV_X_MIN_COORD ;                                               
    extern uint16 AHMIM_STM_D_RCV_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_RCV_Y_MIN_COORD ;                                               
    extern uint16 AHMIM_STM_D_RCV_Y_MAX_COORD ;

    /*FCV - Front Cross Path View touch coordinates*/
    extern uint16 AHMIM_STM_D_FCV_X_MIN_COORD ;                                                
    extern uint16 AHMIM_STM_D_FCV_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_FCV_Y_MIN_COORD ;                                               
    extern uint16 AHMIM_STM_D_FCV_Y_MAX_COORD ;

    /*FTV - Front Top View touch coordinates*/
    extern uint16 AHMIM_STM_D_FTV_X_MIN_COORD ;                                               
    extern uint16 AHMIM_STM_D_FTV_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_FTV_Y_MIN_COORD ;                                                
    extern uint16 AHMIM_STM_D_FTV_Y_MAX_COORD ;

    /*BURV or RVC - Backup Rear View touch coordinates*/
    extern uint16 AHMIM_STM_D_RVC_X_MIN_COORD ;                                                
    extern uint16 AHMIM_STM_D_RVC_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_RVC_Y_MIN_COORD ;                                                
    extern uint16 AHMIM_STM_D_RVC_Y_MAX_COORD ;

    /*FFCV- Front Facing Camera View, Can be present or absent based on Proxi*/
    extern uint16 AHMIM_STM_D_FFCVBTN_X_MIN_COORD ;                                                            
    extern uint16 AHMIM_STM_D_FFCVBTN_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_FFCVBTN_Y_MIN_COORD ;                                                            
    extern uint16 AHMIM_STM_D_FFCVBTN_Y_MAX_COORD ;

    /********************AUX CAM BUTTON*********************/
    /*FFC = Present*/
    extern uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_X_MIN_COORD ;                                                                                           
    extern uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_Y_MIN_COORD ;                                                                                           
    extern uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_Y_MAX_COORD ;
    /*FFC = Absent*/
    extern uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_X_MIN_COORD ;                                                                                            
    extern uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_Y_MIN_COORD ;                                                                                            
    extern uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_Y_MAX_COORD ;
    /*******************************************************/

    /********************MORE CAMS BUTTON******************/
    /*FFC = Present*/
    extern uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_X_MIN_COORD ;                                                                                           
    extern uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_Y_MIN_COORD ;                                                                                           
    extern uint16 AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_Y_MAX_COORD ;
    /*FFC = Absent*/
    extern uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_X_MIN_COORD ;                                                                                           
    extern uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_Y_MIN_COORD ;                                                                                           
    extern uint16 AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_Y_MAX_COORD ;
    /****************************************************/

    /**********************TRG Buttons*******************/
    /* TRG Left */
    extern uint16 AHMIM_STM_D_TRGLEFT_X_MIN_COORD ;
    extern uint16 AHMIM_STM_D_TRGLEFT_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_TRGLEFT_Y_MIN_COORD ;
    extern uint16 AHMIM_STM_D_TRGLEFT_Y_MAX_COORD ;
    /* TRG Right */
    extern uint16 AHMIM_STM_D_TRGRIGHT_X_MIN_COORD ;
    extern uint16 AHMIM_STM_D_TRGRIGHT_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_TRGRIGHT_Y_MIN_COORD ;
    extern uint16 AHMIM_STM_D_TRGRIGHT_Y_MAX_COORD ;
    /* TRG Auto */
    extern uint16 AHMIM_STM_D_TRGAUTO_X_MIN_COORD ;
    extern uint16 AHMIM_STM_D_TRGAUTO_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_TRGAUTO_Y_MIN_COORD ;
    extern uint16 AHMIM_STM_D_TRGAUTO_Y_MAX_COORD ;
    /*************************************************/

    /********************************************* THA Soft Buttons Dimensions in Pixels  ********************************/
    extern uint16 AHMIM_STM_D_THA_SCRN_TCH_PRSD_X_MIN_COORD ; 
    extern uint16 AHMIM_STM_D_THA_SCRN_TCH_PRSD_X_MAX_COORD ; 
    extern uint16 AHMIM_STM_D_THA_SCRN_TCH_PRSD_Y_MIN_COORD ; 
    extern uint16 AHMIM_STM_D_THA_SCRN_TCH_PRSD_Y_MAX_COORD ; 

    extern uint16 AHMIM_STM_D_THA_CNFRM_BTN_PRSD_X_MIN_COORD ; 
    extern uint16 AHMIM_STM_D_THA_CNFRM_BTN_PRSD_X_MAX_COORD ; 
    extern uint16 AHMIM_STM_D_THA_CNFRM_BTN_PRSD_Y_MIN_COORD ; 
    extern uint16 AHMIM_STM_D_THA_CNFRM_BTN_PRSD_Y_MAX_COORD ; 

    extern uint16 AHMIM_STM_D_THA_START_BTN_PRSD_X_MIN_COORD ;  
    extern uint16 AHMIM_STM_D_THA_START_BTN_PRSD_X_MAX_COORD ; 
    extern uint16 AHMIM_STM_D_THA_START_BTN_PRSD_Y_MIN_COORD ; 
    extern uint16 AHMIM_STM_D_THA_START_BTN_PRSD_Y_MAX_COORD ; 

    extern uint16 AHMIM_STM_D_THA_BTN_PRSD_X_MIN_COORD ; 
    extern uint16 AHMIM_STM_D_THA_BTN_PRSD_X_MAX_COORD ; 
    extern uint16 AHMIM_STM_D_THA_BTN_PRSD_Y_MIN_COORD ; 
    extern uint16 AHMIM_STM_D_THA_BTN_PRSD_Y_MAX_COORD ; 

    extern uint16 AHMIM_STM_D_THA_ZMOUT_PRSD_X_MIN_COORD ; 
    extern uint16 AHMIM_STM_D_THA_ZMOUT_PRSD_X_MAX_COORD ; 
    extern uint16 AHMIM_STM_D_THA_ZMOUT_PRSD_Y_MIN_COORD ; 
    extern uint16 AHMIM_STM_D_THA_ZMOUT_PRSD_Y_MAX_COORD ; 

    extern uint16 AHMIM_STM_D_AP_BACK_BTN_X_MIN_COORD ;
    extern uint16 AHMIM_STM_D_AP_BACK_BTN_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_AP_BACK_BTN_Y_MIN_COORD ;
    extern uint16 AHMIM_STM_D_AP_BACK_BTN_Y_MAX_COORD ;

    extern uint16 AHMIM_STM_D_AP_PARK_BTN_X_MIN_COORD ;
    extern uint16 AHMIM_STM_D_AP_PARK_BTN_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_AP_PARK_BTN_Y_MIN_COORD ;
    extern uint16 AHMIM_STM_D_AP_PARK_BTN_Y_MAX_COORD ;
    
    extern uint16 AHMIM_STM_D_AP_EXIT_BTN_X_MIN_COORD ;
    extern uint16 AHMIM_STM_D_AP_EXIT_BTN_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_AP_EXIT_BTN_Y_MIN_COORD ;
    extern uint16 AHMIM_STM_D_AP_EXIT_BTN_Y_MAX_COORD ;

    extern uint16 AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_X_MIN_COORD ;
    extern uint16 AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_Y_MIN_COORD ;
    extern uint16 AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_Y_MAX_COORD ;

    extern uint16 AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_X_MIN_COORD ;
    extern uint16 AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_Y_MIN_COORD ;
    extern uint16 AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_Y_MAX_COORD ;

    extern uint16 AHMIM_STM_D_AP_FRONT_IN_BTN_X_MIN_COORD ;
    extern uint16 AHMIM_STM_D_AP_FRONT_IN_BTN_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_AP_FRONT_IN_BTN_Y_MIN_COORD ;
    extern uint16 AHMIM_STM_D_AP_FRONT_IN_BTN_Y_MAX_COORD ;
    
    extern uint16 AHMIM_STM_D_AP_REAR_IN_BTN_X_MIN_COORD ;
    extern uint16 AHMIM_STM_D_AP_REAR_IN_BTN_X_MAX_COORD ;
    extern uint16 AHMIM_STM_D_AP_REAR_IN_BTN_Y_MIN_COORD ;
    extern uint16 AHMIM_STM_D_AP_REAR_IN_BTN_Y_MAX_COORD ;

    extern uint16 AHMIM_STM_D_AP_PARKSLOT_HEIGHT    ;
    extern uint16 AHMIM_STM_D_AP_PARKSLOT_WIDTH     ;
    extern uint16 AHMIM_STM_D_AP_PARKSLOT_MIN_Y     ;
    extern uint16 AHMIM_STM_D_AP_PARKSLOT_MAX_Y     ;    
    extern uint16 AHMIM_STM_D_AP_PARKSLOT_SEPRATION ;

    extern uint16 AHMIM_STM_D_AP_PARKSLOT_X1 ;
    extern uint16 AHMIM_STM_D_AP_PARKSLOT_X2 ;
    extern uint16 AHMIM_STM_D_AP_PARKSLOT_X3 ;
    extern uint16 AHMIM_STM_D_AP_PIXEL_CAR_ORIGIN_Y      ;
    extern uint16 AHMIM_STM_D_AP_WORLD_TO_PIXEL_FACTOR ;
    /********************************************* THA Soft Buttons Dimensions in Pixels  ********************************/


    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!********TYPE 2 OR  9************!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    /*Zoom In and zoom out for entire 4-CAM and 1-CAM when AUX proxi disablled*/
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_MAGNIFIER_SIZE_X 75u
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_MAGNIFIER_SIZE_Y 75u
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_MAGNIFIER_X_MIN_COORD 18u                                                                 
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_MAGNIFIER_X_MAX_COORD (AHMIM_STM_D_TYPE_29_TYPE_4CAM_MAGNIFIER_X_MIN_COORD + AHMIM_STM_D_TYPE_29_TYPE_4CAM_MAGNIFIER_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_MAGNIFIER_Y_MIN_COORD 18u                                                                 
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_MAGNIFIER_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_TYPE_4CAM_MAGNIFIER_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_TYPE_4CAM_MAGNIFIER_SIZE_Y) 

    /*Zoom In and zoom out for 1-CAM AUX enabled*/
    #define AHMIM_STM_D_TYPE_29_TYPE_1CAM_MAGNIFIER_SIZE_X 75u
    #define AHMIM_STM_D_TYPE_29_TYPE_1CAM_MAGNIFIER_SIZE_Y 75u
    #define AHMIM_STM_D_TYPE_29_TYPE_1CAM_MAGNIFIER_X_MIN_COORD 18u                                                                
    #define AHMIM_STM_D_TYPE_29_TYPE_1CAM_MAGNIFIER_X_MAX_COORD (AHMIM_STM_D_TYPE_29_TYPE_1CAM_MAGNIFIER_X_MIN_COORD + AHMIM_STM_D_TYPE_29_TYPE_1CAM_MAGNIFIER_SIZE_X)
    #define AHMIM_STM_D_TYPE_29_TYPE_1CAM_MAGNIFIER_Y_MIN_COORD 111u                                                                
    #define AHMIM_STM_D_TYPE_29_TYPE_1CAM_MAGNIFIER_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_TYPE_1CAM_MAGNIFIER_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_TYPE_1CAM_MAGNIFIER_SIZE_Y)
    
    /*X Button - Image Defeat touch coordinates*/
    #define AHMIM_STM_D_TYPE_29_XBTN_SIZE_X 75u                                                            
    #define AHMIM_STM_D_TYPE_29_XBTN_SIZE_Y 75u                                                           
    #define AHMIM_STM_D_TYPE_29_XBTN_X_MIN_COORD 931u                                                      
    #define AHMIM_STM_D_TYPE_29_XBTN_X_MAX_COORD (AHMIM_STM_D_TYPE_29_XBTN_X_MIN_COORD + AHMIM_STM_D_TYPE_29_XBTN_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_XBTN_Y_MIN_COORD 18u                                                       
    #define AHMIM_STM_D_TYPE_29_XBTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_XBTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_XBTN_SIZE_Y) 

    /*RTV - Rear Top View touch coordinates*/
    #define AHMIM_STM_D_TYPE_29_RTV_SIZE_X 96u
    #define AHMIM_STM_D_TYPE_29_RTV_SIZE_Y 96u
    #define AHMIM_STM_D_TYPE_29_RTV_X_MIN_COORD 18u                                                 
    #define AHMIM_STM_D_TYPE_29_RTV_X_MAX_COORD (AHMIM_STM_D_TYPE_29_RTV_X_MIN_COORD + AHMIM_STM_D_TYPE_29_RTV_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_RTV_Y_MIN_COORD 659u                                                
    #define AHMIM_STM_D_TYPE_29_RTV_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_RTV_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_RTV_SIZE_Y) 

    /*RCV - Rear Cross Path View touch coordinates*/
    #define AHMIM_STM_D_TYPE_29_RCV_SIZE_X 96u
    #define AHMIM_STM_D_TYPE_29_RCV_SIZE_Y 96u
    #define AHMIM_STM_D_TYPE_29_RCV_X_MIN_COORD 138u                                                
    #define AHMIM_STM_D_TYPE_29_RCV_X_MAX_COORD (AHMIM_STM_D_TYPE_29_RCV_X_MIN_COORD + AHMIM_STM_D_TYPE_29_RCV_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_RCV_Y_MIN_COORD 659u                                               
    #define AHMIM_STM_D_TYPE_29_RCV_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_RCV_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_RCV_SIZE_Y) 

    /*FCV - Front Cross Path View touch coordinates*/
    #define AHMIM_STM_D_TYPE_29_FCV_SIZE_X 96u
    #define AHMIM_STM_D_TYPE_29_FCV_SIZE_Y 96u
    #define AHMIM_STM_D_TYPE_29_FCV_X_MIN_COORD 259u                                                
    #define AHMIM_STM_D_TYPE_29_FCV_X_MAX_COORD (AHMIM_STM_D_TYPE_29_FCV_X_MIN_COORD + AHMIM_STM_D_TYPE_29_FCV_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_FCV_Y_MIN_COORD 659u                                               
    #define AHMIM_STM_D_TYPE_29_FCV_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_FCV_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_FCV_SIZE_Y) 

    /*FTV - Front Top View touch coordinates*/
    #define AHMIM_STM_D_TYPE_29_FTV_SIZE_X 96u
    #define AHMIM_STM_D_TYPE_29_FTV_SIZE_Y 96u
    #define AHMIM_STM_D_TYPE_29_FTV_X_MIN_COORD 379u                                                
    #define AHMIM_STM_D_TYPE_29_FTV_X_MAX_COORD (AHMIM_STM_D_TYPE_29_FTV_X_MIN_COORD + AHMIM_STM_D_TYPE_29_FTV_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_FTV_Y_MIN_COORD 659u                                               
    #define AHMIM_STM_D_TYPE_29_FTV_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_FTV_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_FTV_SIZE_Y) 

    /*BURV or RVC - Backup Rear View touch coordinates*/
    #define AHMIM_STM_D_TYPE_29_RVC_SIZE_X 96u
    #define AHMIM_STM_D_TYPE_29_RVC_SIZE_Y 96u
    #define AHMIM_STM_D_TYPE_29_RVC_X_MIN_COORD 500u                                                
    #define AHMIM_STM_D_TYPE_29_RVC_X_MAX_COORD (AHMIM_STM_D_TYPE_29_RVC_X_MIN_COORD + AHMIM_STM_D_TYPE_29_RVC_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_RVC_Y_MIN_COORD 659u                                                
    #define AHMIM_STM_D_TYPE_29_RVC_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_RVC_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_RVC_SIZE_Y) 

    /*FFCV- Front Facing Camera View, Can be present or absent based on Proxi*/
    #define AHMIM_STM_D_TYPE_29_FFCVBTN_SIZE_X 96u
    #define AHMIM_STM_D_TYPE_29_FFCVBTN_SIZE_Y 96u
    #define AHMIM_STM_D_TYPE_29_FFCVBTN_X_MIN_COORD 620u                                                            
    #define AHMIM_STM_D_TYPE_29_FFCVBTN_X_MAX_COORD (AHMIM_STM_D_TYPE_29_FFCVBTN_X_MIN_COORD + AHMIM_STM_D_TYPE_29_FFCVBTN_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_FFCVBTN_Y_MIN_COORD 659u                                                            
    #define AHMIM_STM_D_TYPE_29_FFCVBTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_FFCVBTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_FFCVBTN_SIZE_Y) 

    /********************AUX CAM BUTTON for 1-CAM*********************/
    /*FFC = Present*/
    #define AHMIM_STM_D_TYPE_29_TYPE_1CAM_VC_AUXCAM_SIZE_X 75u
    #define AHMIM_STM_D_TYPE_29_TYPE_1CAM_VC_AUXCAM_SIZE_Y 75u
    #define AHMIM_STM_D_TYPE_29_TYPE_1CAM_VC_AUXCAM_X_MIN_COORD 18u                                                                                            
    #define AHMIM_STM_D_TYPE_29_TYPE_1CAM_VC_AUXCAM_X_MAX_COORD (AHMIM_STM_D_TYPE_29_TYPE_1CAM_VC_AUXCAM_X_MIN_COORD + AHMIM_STM_D_TYPE_29_TYPE_1CAM_VC_AUXCAM_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_TYPE_1CAM_VC_AUXCAM_Y_MIN_COORD 18u                                                                                            
    #define AHMIM_STM_D_TYPE_29_TYPE_1CAM_VC_AUXCAM_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_TYPE_1CAM_VC_AUXCAM_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_TYPE_1CAM_VC_AUXCAM_SIZE_Y) 
   
    /*******************************************************/

       /********************AUX CAM BUTTON for 4-CAM*********************/
    /*FFC = Present*/
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_PRSNT_AUXCAM_SIZE_X 96u
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_PRSNT_AUXCAM_SIZE_Y 96u
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_PRSNT_AUXCAM_X_MIN_COORD 741u                                                                                            
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_PRSNT_AUXCAM_X_MAX_COORD (AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_PRSNT_AUXCAM_X_MIN_COORD + AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_PRSNT_AUXCAM_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_PRSNT_AUXCAM_Y_MIN_COORD 659u                                                                                            
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_PRSNT_AUXCAM_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_PRSNT_AUXCAM_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_PRSNT_AUXCAM_SIZE_Y) 
    /*FFC = Absent*/
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_ABSNT_AUXCAM_SIZE_X 96u
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_ABSNT_AUXCAM_SIZE_Y 96u
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_ABSNT_AUXCAM_X_MIN_COORD 620u                                                                                            
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_ABSNT_AUXCAM_X_MAX_COORD (AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_ABSNT_AUXCAM_X_MIN_COORD + AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_ABSNT_AUXCAM_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_ABSNT_AUXCAM_Y_MIN_COORD 659u                                                                                            
    #define AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_ABSNT_AUXCAM_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_ABSNT_AUXCAM_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_TYPE_4CAM_VC_OFFROAD_ABSNT_AUXCAM_SIZE_Y) 

    /********************MORE CAMS BUTTON******************/
    /*FFC = Present*/
    #define AHMIM_STM_D_TYPE_29_VC_OFFROAD_PRSNT_MC_BTN_SIZE_X 145u
    #define AHMIM_STM_D_TYPE_29_VC_OFFROAD_PRSNT_MC_BTN_SIZE_Y 96u
    #define AHMIM_STM_D_TYPE_29_VC_OFFROAD_PRSNT_MC_BTN_X_MIN_COORD 861u                                                                                            
    #define AHMIM_STM_D_TYPE_29_VC_OFFROAD_PRSNT_MC_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_29_VC_OFFROAD_PRSNT_MC_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_29_VC_OFFROAD_PRSNT_MC_BTN_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_VC_OFFROAD_PRSNT_MC_BTN_Y_MIN_COORD 659u                                                                                            
    #define AHMIM_STM_D_TYPE_29_VC_OFFROAD_PRSNT_MC_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_VC_OFFROAD_PRSNT_MC_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_VC_OFFROAD_PRSNT_MC_BTN_SIZE_Y) 
    /*FFC = Absent*/
    #define AHMIM_STM_D_TYPE_29_VC_OFFROAD_ABSNT_MC_BTN_SIZE_X 265u
    #define AHMIM_STM_D_TYPE_29_VC_OFFROAD_ABSNT_MC_BTN_SIZE_Y 96u
    #define AHMIM_STM_D_TYPE_29_VC_OFFROAD_ABSNT_MC_BTN_X_MIN_COORD 741u                                                                                            
    #define AHMIM_STM_D_TYPE_29_VC_OFFROAD_ABSNT_MC_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_29_VC_OFFROAD_ABSNT_MC_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_29_VC_OFFROAD_ABSNT_MC_BTN_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_VC_OFFROAD_ABSNT_MC_BTN_Y_MIN_COORD 659u                                                                                            
    #define AHMIM_STM_D_TYPE_29_VC_OFFROAD_ABSNT_MC_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_VC_OFFROAD_ABSNT_MC_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_VC_OFFROAD_ABSNT_MC_BTN_SIZE_Y) 
    /****************************************************/

    /**********************TRG Buttons*******************/
    /* TRG Left */
    #define AHMIM_STM_D_TYPE_29_TRGLEFT_SIZE_X 33u
    #define AHMIM_STM_D_TYPE_29_TRGLEFT_SIZE_Y 52u
    #define AHMIM_STM_D_TYPE_29_TRGLEFT_X_MIN_COORD 315u
    #define AHMIM_STM_D_TYPE_29_TRGLEFT_X_MAX_COORD (AHMIM_STM_D_TYPE_29_TRGLEFT_X_MIN_COORD + AHMIM_STM_D_TYPE_29_TRGLEFT_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_TRGLEFT_Y_MIN_COORD 680u
    #define AHMIM_STM_D_TYPE_29_TRGLEFT_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_TRGLEFT_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_TRGLEFT_SIZE_Y) 
    /* TRG Right */
    #define AHMIM_STM_D_TYPE_29_TRGRIGHT_SIZE_X 33u
    #define AHMIM_STM_D_TYPE_29_TRGRIGHT_SIZE_Y 52u
    #define AHMIM_STM_D_TYPE_29_TRGRIGHT_X_MIN_COORD 676u
    #define AHMIM_STM_D_TYPE_29_TRGRIGHT_X_MAX_COORD (AHMIM_STM_D_TYPE_29_TRGRIGHT_X_MIN_COORD + AHMIM_STM_D_TYPE_29_TRGRIGHT_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_TRGRIGHT_Y_MIN_COORD 680u
    #define AHMIM_STM_D_TYPE_29_TRGRIGHT_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_TRGRIGHT_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_TRGRIGHT_SIZE_Y) 
    /* TRG Auto */
    #define AHMIM_STM_D_TYPE_29_TRGAUTO_SIZE_X 145u
    #define AHMIM_STM_D_TYPE_29_TRGAUTO_SIZE_Y 75u
    #define AHMIM_STM_D_TYPE_29_TRGAUTO_X_MIN_COORD 18u
    #define AHMIM_STM_D_TYPE_29_TRGAUTO_X_MAX_COORD (AHMIM_STM_D_TYPE_29_TRGAUTO_X_MIN_COORD + AHMIM_STM_D_TYPE_29_TRGAUTO_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_TRGAUTO_Y_MIN_COORD 669u
    #define AHMIM_STM_D_TYPE_29_TRGAUTO_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_TRGAUTO_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_TRGAUTO_SIZE_Y) 
    /*************************************************/

    /********************************************* THA Soft Buttons Dimensions in Pixels  ********************************/
    #define AHMIM_STM_D_TYPE_29_THA_SCRN_TCH_PRSD_X_MIN_COORD 0u 
    #define AHMIM_STM_D_TYPE_29_THA_SCRN_TCH_PRSD_X_MAX_COORD 1024u 
    #define AHMIM_STM_D_TYPE_29_THA_SCRN_TCH_PRSD_Y_MIN_COORD 0u 
    #define AHMIM_STM_D_TYPE_29_THA_SCRN_TCH_PRSD_Y_MAX_COORD 645u 

    #define AHMIM_STM_D_TYPE_29_THA_CNFRM_BTN_PRSD_X_MIN_COORD 18u 
    #define AHMIM_STM_D_TYPE_29_THA_CNFRM_BTN_PRSD_X_MAX_COORD 258u 
    #define AHMIM_STM_D_TYPE_29_THA_CNFRM_BTN_PRSD_Y_MIN_COORD 667u 
    #define AHMIM_STM_D_TYPE_29_THA_CNFRM_BTN_PRSD_Y_MAX_COORD 747u 

    #define AHMIM_STM_D_TYPE_29_THA_START_BTN_PRSD_X_MIN_COORD 18u  
    #define AHMIM_STM_D_TYPE_29_THA_START_BTN_PRSD_X_MAX_COORD 258u 
    #define AHMIM_STM_D_TYPE_29_THA_START_BTN_PRSD_Y_MIN_COORD 667u 
    #define AHMIM_STM_D_TYPE_29_THA_START_BTN_PRSD_Y_MAX_COORD 747u 

    #define AHMIM_STM_D_TYPE_29_THA_BTN_PRSD_X_MIN_COORD 930u 
    #define AHMIM_STM_D_TYPE_29_THA_BTN_PRSD_X_MAX_COORD 1007u 
    #define AHMIM_STM_D_TYPE_29_THA_BTN_PRSD_Y_MIN_COORD 19u 
    #define AHMIM_STM_D_TYPE_29_THA_BTN_PRSD_Y_MAX_COORD 96u 

    #define AHMIM_STM_D_TYPE_29_THA_ZMOUT_PRSD_X_MIN_COORD 18u 
    #define AHMIM_STM_D_TYPE_29_THA_ZMOUT_PRSD_X_MAX_COORD 93u 
    #define AHMIM_STM_D_TYPE_29_THA_ZMOUT_PRSD_Y_MIN_COORD 18u 
    #define AHMIM_STM_D_TYPE_29_THA_ZMOUT_PRSD_Y_MAX_COORD 93u 

    /********************************************* THA Soft Buttons Dimensions in Pixels  ********************************/

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!************TYPE   7************!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    /*Zoom In and zoom out for entire 4-CAM and 1-CAM when AUX proxi disablled*/
    #define AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_SIZE_X 88u
    #define AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_SIZE_Y 88u
    #define AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_X_MIN_COORD 21u                                                                 
    #define AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_X_MAX_COORD (AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_X_MIN_COORD + AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_Y_MIN_COORD 21u                                                                 
    #define AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_TYPE_4CAM_MAGNIFIER_SIZE_Y) 

    /*Zoom In and zoom out for 1-CAM AUX enabled*/
    #define AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_SIZE_X 88u
    #define AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_SIZE_Y 88u
    #define AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_X_MIN_COORD 21u                                                                
    #define AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_X_MAX_COORD (AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_X_MIN_COORD + AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_SIZE_X)
    #define AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_Y_MIN_COORD 130u                                                                
    #define AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_TYPE_1CAM_MAGNIFIER_SIZE_Y)

    /*Zoom In and zoom out*/ /* Req ID : 445366 touch coordinates update */
    #define AHMIM_STM_D_TYPE_7_MAGNIFIER_SIZE_X 88u
    #define AHMIM_STM_D_TYPE_7_MAGNIFIER_SIZE_Y 88u
    #define AHMIM_STM_D_TYPE_7_MAGNIFIER_X_MIN_COORD 21u                                                                 
    #define AHMIM_STM_D_TYPE_7_MAGNIFIER_X_MAX_COORD (AHMIM_STM_D_TYPE_7_MAGNIFIER_X_MIN_COORD + AHMIM_STM_D_TYPE_7_MAGNIFIER_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_MAGNIFIER_Y_MIN_COORD 21u                                                                 
    #define AHMIM_STM_D_TYPE_7_MAGNIFIER_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_MAGNIFIER_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_MAGNIFIER_SIZE_Y) 

    /*X Button - Image Defeat touch coordinates*/
    #define AHMIM_STM_D_TYPE_7_XBTN_SIZE_X 88u                                                            
    #define AHMIM_STM_D_TYPE_7_XBTN_SIZE_Y 88u                                                           
    #define AHMIM_STM_D_TYPE_7_XBTN_X_MIN_COORD 1091u                                                      
    #define AHMIM_STM_D_TYPE_7_XBTN_X_MAX_COORD (AHMIM_STM_D_TYPE_7_XBTN_X_MIN_COORD + AHMIM_STM_D_TYPE_7_XBTN_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_XBTN_Y_MIN_COORD 21u                                                       
    #define AHMIM_STM_D_TYPE_7_XBTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_XBTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_XBTN_SIZE_Y) 

    /*RTV - Rear Top View touch coordinates*/
    #define AHMIM_STM_D_TYPE_7_RTV_SIZE_X 113u
    #define AHMIM_STM_D_TYPE_7_RTV_SIZE_Y 113u
    #define AHMIM_STM_D_TYPE_7_RTV_X_MIN_COORD 21u                                                 
    #define AHMIM_STM_D_TYPE_7_RTV_X_MAX_COORD (AHMIM_STM_D_TYPE_7_RTV_X_MIN_COORD + AHMIM_STM_D_TYPE_7_RTV_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_RTV_Y_MIN_COORD 772u                                               
    #define AHMIM_STM_D_TYPE_7_RTV_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_RTV_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_RTV_SIZE_Y) 

    /*RCV - Rear Cross Path View touch coordinates*/
    #define AHMIM_STM_D_TYPE_7_RCV_SIZE_X 113u
    #define AHMIM_STM_D_TYPE_7_RCV_SIZE_Y 113u
    #define AHMIM_STM_D_TYPE_7_RCV_X_MIN_COORD 162u                                                
    #define AHMIM_STM_D_TYPE_7_RCV_X_MAX_COORD (AHMIM_STM_D_TYPE_7_RCV_X_MIN_COORD + AHMIM_STM_D_TYPE_7_RCV_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_RCV_Y_MIN_COORD 772u                                               
    #define AHMIM_STM_D_TYPE_7_RCV_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_RCV_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_RCV_SIZE_Y) 

    /*FCV - Front Cross Path View touch coordinates*/
    #define AHMIM_STM_D_TYPE_7_FCV_SIZE_X 113u
    #define AHMIM_STM_D_TYPE_7_FCV_SIZE_Y 113u
    #define AHMIM_STM_D_TYPE_7_FCV_X_MIN_COORD 304u                                                
    #define AHMIM_STM_D_TYPE_7_FCV_X_MAX_COORD (AHMIM_STM_D_TYPE_7_FCV_X_MIN_COORD + AHMIM_STM_D_TYPE_7_FCV_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_FCV_Y_MIN_COORD 772u                                               
    #define AHMIM_STM_D_TYPE_7_FCV_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_FCV_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_FCV_SIZE_Y) 

    /*FTV - Front Top View touch coordinates*/
    #define AHMIM_STM_D_TYPE_7_FTV_SIZE_X 113u
    #define AHMIM_STM_D_TYPE_7_FTV_SIZE_Y 113u
    #define AHMIM_STM_D_TYPE_7_FTV_X_MIN_COORD 444u                                                
    #define AHMIM_STM_D_TYPE_7_FTV_X_MAX_COORD (AHMIM_STM_D_TYPE_7_FTV_X_MIN_COORD + AHMIM_STM_D_TYPE_7_FTV_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_FTV_Y_MIN_COORD 772u                                               
    #define AHMIM_STM_D_TYPE_7_FTV_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_FTV_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_FTV_SIZE_Y) 

    /*BURV or RVC - Backup Rear View touch coordinates*/
    #define AHMIM_STM_D_TYPE_7_RVC_SIZE_X 113u
    #define AHMIM_STM_D_TYPE_7_RVC_SIZE_Y 113u
    #define AHMIM_STM_D_TYPE_7_RVC_X_MIN_COORD 586u                                                
    #define AHMIM_STM_D_TYPE_7_RVC_X_MAX_COORD (AHMIM_STM_D_TYPE_7_RVC_X_MIN_COORD + AHMIM_STM_D_TYPE_7_RVC_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_RVC_Y_MIN_COORD 772u                                                
    #define AHMIM_STM_D_TYPE_7_RVC_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_RVC_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_RVC_SIZE_Y) 

    /*FFCV- Front Facing Camera View, Can be present or absent based on Proxi*/
    #define AHMIM_STM_D_TYPE_7_FFCVBTN_SIZE_X 113u
    #define AHMIM_STM_D_TYPE_7_FFCVBTN_SIZE_Y 113u
    #define AHMIM_STM_D_TYPE_7_FFCVBTN_X_MIN_COORD 727u                                                            
    #define AHMIM_STM_D_TYPE_7_FFCVBTN_X_MAX_COORD (AHMIM_STM_D_TYPE_7_FFCVBTN_X_MIN_COORD + AHMIM_STM_D_TYPE_7_FFCVBTN_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_FFCVBTN_Y_MIN_COORD 772u                                                            
    #define AHMIM_STM_D_TYPE_7_FFCVBTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_FFCVBTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_FFCVBTN_SIZE_Y) 

    /********************AUX CAM BUTTON*********************/
    /*FFC = Present*/
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_SIZE_X 113u
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_SIZE_Y 113u
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_X_MIN_COORD 868u                                                                                            
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_X_MAX_COORD (AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_X_MIN_COORD + AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_Y_MIN_COORD 772u                                                                                            
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_AUXCAM_SIZE_Y) 
    /*FFC = Absent*/
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_SIZE_X 113u
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_SIZE_Y 113u
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_X_MIN_COORD 727u                                                                                            
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_X_MAX_COORD (AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_X_MIN_COORD + AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_Y_MIN_COORD 772u                                                                                            
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_AUXCAM_SIZE_Y) 
    /*******************************************************/

    /********************MORE CAMS BUTTON******************/
    /*FFC = Present*/
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_SIZE_X 170u
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_SIZE_Y 113u
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_X_MIN_COORD 1009u                                                                                            
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_Y_MIN_COORD 772u                                                                                            
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_VC_OFFROAD_PRSNT_MC_BTN_SIZE_Y) 
    /*FFC = Absent*/
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_SIZE_X 311u
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_SIZE_Y 113u
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_X_MIN_COORD 868u                                                                                            
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_Y_MIN_COORD 772u                                                                                            
    #define AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_VC_OFFROAD_ABSNT_MC_BTN_SIZE_Y) 
    /****************************************************/

    /**********************TRG Buttons*******************/
    /* TRG Left */
    #define AHMIM_STM_D_TYPE_7_TRGLEFT_SIZE_X 39u
    #define AHMIM_STM_D_TYPE_7_TRGLEFT_SIZE_Y 62u
    #define AHMIM_STM_D_TYPE_7_TRGLEFT_X_MIN_COORD 369u
    #define AHMIM_STM_D_TYPE_7_TRGLEFT_X_MAX_COORD (AHMIM_STM_D_TYPE_7_TRGLEFT_X_MIN_COORD + AHMIM_STM_D_TYPE_7_TRGLEFT_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_TRGLEFT_Y_MIN_COORD 796u
    #define AHMIM_STM_D_TYPE_7_TRGLEFT_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_TRGLEFT_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_TRGLEFT_SIZE_Y) 
    /* TRG Right */
    #define AHMIM_STM_D_TYPE_7_TRGRIGHT_SIZE_X 39u
    #define AHMIM_STM_D_TYPE_7_TRGRIGHT_SIZE_Y 62u
    #define AHMIM_STM_D_TYPE_7_TRGRIGHT_X_MIN_COORD 792u
    #define AHMIM_STM_D_TYPE_7_TRGRIGHT_X_MAX_COORD (AHMIM_STM_D_TYPE_7_TRGRIGHT_X_MIN_COORD + AHMIM_STM_D_TYPE_7_TRGRIGHT_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_TRGRIGHT_Y_MIN_COORD 796u
    #define AHMIM_STM_D_TYPE_7_TRGRIGHT_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_TRGRIGHT_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_TRGRIGHT_SIZE_Y) 
    /* TRG Auto */
    #define AHMIM_STM_D_TYPE_7_TRGAUTO_SIZE_X 170u
    #define AHMIM_STM_D_TYPE_7_TRGAUTO_SIZE_Y 88u
    #define AHMIM_STM_D_TYPE_7_TRGAUTO_X_MIN_COORD 170u
    #define AHMIM_STM_D_TYPE_7_TRGAUTO_X_MAX_COORD (AHMIM_STM_D_TYPE_7_TRGAUTO_X_MIN_COORD + AHMIM_STM_D_TYPE_7_TRGAUTO_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_TRGAUTO_Y_MIN_COORD 784u
    #define AHMIM_STM_D_TYPE_7_TRGAUTO_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_TRGAUTO_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_TRGAUTO_SIZE_Y) 
    /*************************************************/

    /********************************************* THA Soft Buttons Dimensions in Pixels  ********************************/
    #define AHMIM_STM_D_TYPE_7_THA_SCRN_TCH_PRSD_X_MIN_COORD 0u 
    #define AHMIM_STM_D_TYPE_7_THA_SCRN_TCH_PRSD_X_MAX_COORD 1200u 
    #define AHMIM_STM_D_TYPE_7_THA_SCRN_TCH_PRSD_Y_MIN_COORD 0u 
    #define AHMIM_STM_D_TYPE_7_THA_SCRN_TCH_PRSD_Y_MAX_COORD 756u 

    #define AHMIM_STM_D_TYPE_7_THA_CNFRM_BTN_PRSD_X_MIN_COORD 21u 
    #define AHMIM_STM_D_TYPE_7_THA_CNFRM_BTN_PRSD_X_MAX_COORD 303u 
    #define AHMIM_STM_D_TYPE_7_THA_CNFRM_BTN_PRSD_Y_MIN_COORD 781u 
    #define AHMIM_STM_D_TYPE_7_THA_CNFRM_BTN_PRSD_Y_MAX_COORD 876u 

    #define AHMIM_STM_D_TYPE_7_THA_START_BTN_PRSD_X_MIN_COORD 21u  
    #define AHMIM_STM_D_TYPE_7_THA_START_BTN_PRSD_X_MAX_COORD 303u 
    #define AHMIM_STM_D_TYPE_7_THA_START_BTN_PRSD_Y_MIN_COORD 781u 
    #define AHMIM_STM_D_TYPE_7_THA_START_BTN_PRSD_Y_MAX_COORD 876u 

    #define AHMIM_STM_D_TYPE_7_THA_BTN_PRSD_X_MIN_COORD 1089u 
    #define AHMIM_STM_D_TYPE_7_THA_BTN_PRSD_X_MAX_COORD 1181u 
    #define AHMIM_STM_D_TYPE_7_THA_BTN_PRSD_Y_MIN_COORD 19u 
    #define AHMIM_STM_D_TYPE_7_THA_BTN_PRSD_Y_MAX_COORD 111u 

    #define AHMIM_STM_D_TYPE_7_THA_ZMOUT_PRSD_X_MIN_COORD 21u 
    #define AHMIM_STM_D_TYPE_7_THA_ZMOUT_PRSD_X_MAX_COORD 109u 
    #define AHMIM_STM_D_TYPE_7_THA_ZMOUT_PRSD_Y_MIN_COORD 21u 
    #define AHMIM_STM_D_TYPE_7_THA_ZMOUT_PRSD_Y_MAX_COORD 109u 

    /********************************************* THA Soft Buttons Dimensions in Pixels  ********************************/

    /*****************************************AutoPark HMI Soft Buttons Co-ordinates************************************************/

    /*Data of variant 8, taken from campos Consider front bumper center as 0,0*/
    #define AHMIM_STM_D_AP_WORLD_CAR_HEIGHT  5902.73f
    #define AHMIM_STM_D_AP_WORLD_CAR_ORIGIN  4666.114f

    #define AHMIM_STM_D_TYPE_7_AP_TOP_BAR_BTN_SIZE_X 244u
    #define AHMIM_STM_D_TYPE_7_AP_TOP_BAR_BTN_SIZE_Y 92u
        #define AHMIM_STM_D_TYPE_7_AP_BACK_BTN_X_MIN_COORD 17u
        #define AHMIM_STM_D_TYPE_7_AP_BACK_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_7_AP_BACK_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_7_AP_TOP_BAR_BTN_SIZE_X) 
        #define AHMIM_STM_D_TYPE_7_AP_BACK_BTN_Y_MIN_COORD 21u
        #define AHMIM_STM_D_TYPE_7_AP_BACK_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_AP_BACK_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_AP_TOP_BAR_BTN_SIZE_Y)
    #define AHMIM_STM_D_TYPE_7_AP_PARK_BTN_X_MIN_COORD 330u
    #define AHMIM_STM_D_TYPE_7_AP_PARK_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_7_AP_PARK_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_7_AP_TOP_BAR_BTN_SIZE_X) 
    #define AHMIM_STM_D_TYPE_7_AP_PARK_BTN_Y_MIN_COORD 21u
    #define AHMIM_STM_D_TYPE_7_AP_PARK_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_AP_PARK_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_AP_TOP_BAR_BTN_SIZE_Y)
        #define AHMIM_STM_D_TYPE_7_AP_EXIT_BTN_X_MIN_COORD 626u
        #define AHMIM_STM_D_TYPE_7_AP_EXIT_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_7_AP_EXIT_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_7_AP_TOP_BAR_BTN_SIZE_X) 
        #define AHMIM_STM_D_TYPE_7_AP_EXIT_BTN_Y_MIN_COORD 21u
        #define AHMIM_STM_D_TYPE_7_AP_EXIT_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_AP_EXIT_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_AP_TOP_BAR_BTN_SIZE_Y)

    #define AHMIM_STM_D_TYPE_7_AP_PARK_OUT_BTN_SIZE_X 383u
    #define AHMIM_STM_D_TYPE_7_AP_PARK_OUT_BTN_SIZE_Y 331u
        #define AHMIM_STM_D_TYPE_7_AP_RIGHT_FWD_OUT_BTN_X_MIN_COORD 751u
        #define AHMIM_STM_D_TYPE_7_AP_RIGHT_FWD_OUT_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_7_AP_RIGHT_FWD_OUT_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_7_AP_PARK_OUT_BTN_SIZE_X)
        #define AHMIM_STM_D_TYPE_7_AP_RIGHT_FWD_OUT_BTN_Y_MIN_COORD 285u
        #define AHMIM_STM_D_TYPE_7_AP_RIGHT_FWD_OUT_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_AP_RIGHT_FWD_OUT_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_AP_PARK_OUT_BTN_SIZE_Y)
    #define AHMIM_STM_D_TYPE_7_AP_LEFT_FWD_OUT_BTN_X_MIN_COORD 66u
    #define AHMIM_STM_D_TYPE_7_AP_LEFT_FWD_OUT_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_7_AP_LEFT_FWD_OUT_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_7_AP_PARK_OUT_BTN_SIZE_X)
    #define AHMIM_STM_D_TYPE_7_AP_LEFT_FWD_OUT_BTN_Y_MIN_COORD 285u
    #define AHMIM_STM_D_TYPE_7_AP_LEFT_FWD_OUT_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_AP_LEFT_FWD_OUT_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_AP_PARK_OUT_BTN_SIZE_Y)

    #define AHMIM_STM_D_TYPE_7_AP_PARK_IN_BTN_SIZE_X 515u
    #define AHMIM_STM_D_TYPE_7_AP_PARK_IN_BTN_SIZE_Y 540u
        #define AHMIM_STM_D_TYPE_7_AP_FRONT_IN_BTN_X_MIN_COORD 66u
        #define AHMIM_STM_D_TYPE_7_AP_FRONT_IN_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_7_AP_FRONT_IN_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_7_AP_PARK_IN_BTN_SIZE_X)
        #define AHMIM_STM_D_TYPE_7_AP_FRONT_IN_BTN_Y_MIN_COORD 285u
        #define AHMIM_STM_D_TYPE_7_AP_FRONT_IN_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_AP_FRONT_IN_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_AP_PARK_IN_BTN_SIZE_Y)
    #define AHMIM_STM_D_TYPE_7_AP_REAR_IN_BTN_X_MIN_COORD 619u
    #define AHMIM_STM_D_TYPE_7_AP_REAR_IN_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_7_AP_REAR_IN_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_7_AP_PARK_IN_BTN_SIZE_X)
    #define AHMIM_STM_D_TYPE_7_AP_REAR_IN_BTN_Y_MIN_COORD 285u
    #define AHMIM_STM_D_TYPE_7_AP_REAR_IN_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_7_AP_REAR_IN_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_7_AP_PARK_IN_BTN_SIZE_X)

    /*Below items need to be in sync with yaml else functionality will break!!*/
    #define AHMIM_STM_D_TYPE_7_SCREEN_WIDTH            1200u
    #define AHMIM_STM_D_TYPE_7_SCREEN_HEIGHT           900u
    #define AHMIM_STM_D_TYPE_7_AP_PARKSLOT_HEIGHT      210u
    #define AHMIM_STM_D_TYPE_7_AP_PARKSLOT_WIDTH       106u
    #define AHMIM_STM_D_TYPE_7_AP_PARKSLOT_SEPRATION   24u
    #define AHMIM_STM_D_TYPE_7_AP_PARKSLOT_MIN_Y       344u
    #define AHMIM_STM_D_TYPE_7_AP_PARKSLOT_MAX_Y       (AHMIM_STM_D_TYPE_7_SCREEN_HEIGHT - AHMIM_STM_D_TYPE_7_AP_PARKSLOT_SEPRATION)
    #define AHMIM_STM_D_TYPE_7_AP_PARKSLOT_X1          118u
    #define AHMIM_STM_D_TYPE_7_AP_PARKSLOT_X2          224u
    #define AHMIM_STM_D_TYPE_7_AP_PARKSLOT_X3          870u
    #define AHMIM_STM_D_TYPE_7_AP_PIXEL_CAR_START      152u
    #define AHMIM_STM_D_TYPE_7_AP_PIXEL_CAR_HEIGHT     192.0f

    #define AHMIM_STM_D_TYPE_7_AP_PIXEL_CAR_ORIGIN_Y   (AHMIM_STM_D_TYPE_7_AP_PIXEL_CAR_START + (uint16_t)( (AHMIM_STM_D_AP_WORLD_CAR_ORIGIN / AHMIM_STM_D_AP_WORLD_CAR_HEIGHT ) * AHMIM_STM_D_TYPE_7_AP_PIXEL_CAR_HEIGHT) )
    #define AHMIM_STM_D_TYPE_7_AP_WORLD_TO_PIXEL_FACTOR  (AHMIM_STM_D_AP_WORLD_CAR_HEIGHT/AHMIM_STM_D_TYPE_7_AP_PIXEL_CAR_HEIGHT)
    
//!!/***************************************************************************************************************************************************************/
        
    #define AHMIM_STM_D_TYPE_29_AP_TOP_BAR_BTN_SIZE_X 208u
    #define AHMIM_STM_D_TYPE_29_AP_TOP_BAR_BTN_SIZE_Y 79u
        #define AHMIM_STM_D_TYPE_29_AP_BACK_BTN_X_MIN_COORD 14u
        #define AHMIM_STM_D_TYPE_29_AP_BACK_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_29_AP_BACK_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_29_AP_TOP_BAR_BTN_SIZE_X) 
        #define AHMIM_STM_D_TYPE_29_AP_BACK_BTN_Y_MIN_COORD 17u
        #define AHMIM_STM_D_TYPE_29_AP_BACK_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_AP_BACK_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_AP_TOP_BAR_BTN_SIZE_Y)
    #define AHMIM_STM_D_TYPE_29_AP_PARK_BTN_X_MIN_COORD 281u
    #define AHMIM_STM_D_TYPE_29_AP_PARK_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_29_AP_PARK_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_29_AP_TOP_BAR_BTN_SIZE_X) 
    #define AHMIM_STM_D_TYPE_29_AP_PARK_BTN_Y_MIN_COORD 17u
    #define AHMIM_STM_D_TYPE_29_AP_PARK_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_AP_PARK_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_AP_TOP_BAR_BTN_SIZE_Y)
        #define AHMIM_STM_D_TYPE_29_AP_EXIT_BTN_X_MIN_COORD 534u
        #define AHMIM_STM_D_TYPE_29_AP_EXIT_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_29_AP_EXIT_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_29_AP_TOP_BAR_BTN_SIZE_X) 
        #define AHMIM_STM_D_TYPE_29_AP_EXIT_BTN_Y_MIN_COORD 17u
        #define AHMIM_STM_D_TYPE_29_AP_EXIT_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_AP_EXIT_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_AP_TOP_BAR_BTN_SIZE_Y)

    #define AHMIM_STM_D_TYPE_29_AP_PARK_OUT_BTN_SIZE_X 327u
    #define AHMIM_STM_D_TYPE_29_AP_PARK_OUT_BTN_SIZE_Y 282u
        #define AHMIM_STM_D_TYPE_29_AP_RIGHT_FWD_OUT_BTN_X_MIN_COORD 640u
        #define AHMIM_STM_D_TYPE_29_AP_RIGHT_FWD_OUT_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_29_AP_RIGHT_FWD_OUT_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_29_AP_PARK_OUT_BTN_SIZE_X)
        #define AHMIM_STM_D_TYPE_29_AP_RIGHT_FWD_OUT_BTN_Y_MIN_COORD 243u
        #define AHMIM_STM_D_TYPE_29_AP_RIGHT_FWD_OUT_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_AP_RIGHT_FWD_OUT_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_AP_PARK_OUT_BTN_SIZE_Y)
    #define AHMIM_STM_D_TYPE_29_AP_LEFT_FWD_OUT_BTN_X_MIN_COORD 56u
    #define AHMIM_STM_D_TYPE_29_AP_LEFT_FWD_OUT_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_29_AP_LEFT_FWD_OUT_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_29_AP_PARK_OUT_BTN_SIZE_X)
    #define AHMIM_STM_D_TYPE_29_AP_LEFT_FWD_OUT_BTN_Y_MIN_COORD 243u
    #define AHMIM_STM_D_TYPE_29_AP_LEFT_FWD_OUT_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_AP_LEFT_FWD_OUT_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_AP_PARK_OUT_BTN_SIZE_Y)

    #define AHMIM_STM_D_TYPE_29_AP_PARK_IN_BTN_SIZE_X 439u
    #define AHMIM_STM_D_TYPE_29_AP_PARK_IN_BTN_SIZE_Y 461u
        #define AHMIM_STM_D_TYPE_29_AP_FRONT_IN_BTN_X_MIN_COORD 56u
        #define AHMIM_STM_D_TYPE_29_AP_FRONT_IN_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_29_AP_FRONT_IN_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_29_AP_PARK_IN_BTN_SIZE_X)
        #define AHMIM_STM_D_TYPE_29_AP_FRONT_IN_BTN_Y_MIN_COORD 243u
        #define AHMIM_STM_D_TYPE_29_AP_FRONT_IN_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_AP_FRONT_IN_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_AP_PARK_IN_BTN_SIZE_Y)
    #define AHMIM_STM_D_TYPE_29_AP_REAR_IN_BTN_X_MIN_COORD 528u
    #define AHMIM_STM_D_TYPE_29_AP_REAR_IN_BTN_X_MAX_COORD (AHMIM_STM_D_TYPE_29_AP_REAR_IN_BTN_X_MIN_COORD + AHMIM_STM_D_TYPE_29_AP_PARK_IN_BTN_SIZE_X)
    #define AHMIM_STM_D_TYPE_29_AP_REAR_IN_BTN_Y_MIN_COORD 243u
    #define AHMIM_STM_D_TYPE_29_AP_REAR_IN_BTN_Y_MAX_COORD (AHMIM_STM_D_TYPE_29_AP_REAR_IN_BTN_Y_MIN_COORD + AHMIM_STM_D_TYPE_29_AP_PARK_IN_BTN_SIZE_X)

    /*Below items need to be in sync with yaml else functionality will break!!*/
    #define AHMIM_STM_D_TYPE_29_SCREEN_WIDTH            1024u
    #define AHMIM_STM_D_TYPE_29_SCREEN_HEIGHT           768u
    #define AHMIM_STM_D_TYPE_29_AP_PARKSLOT_HEIGHT      180u
    #define AHMIM_STM_D_TYPE_29_AP_PARKSLOT_WIDTH       90u
    #define AHMIM_STM_D_TYPE_29_AP_PARKSLOT_SEPRATION   20u
    #define AHMIM_STM_D_TYPE_29_AP_PARKSLOT_MIN_Y       294u
    #define AHMIM_STM_D_TYPE_29_AP_PARKSLOT_MAX_Y       (AHMIM_STM_D_TYPE_29_SCREEN_HEIGHT - AHMIM_STM_D_TYPE_29_AP_PARKSLOT_SEPRATION)
    #define AHMIM_STM_D_TYPE_29_AP_PARKSLOT_X1          101u
    #define AHMIM_STM_D_TYPE_29_AP_PARKSLOT_X2          191u
    #define AHMIM_STM_D_TYPE_29_AP_PARKSLOT_X3          742u
    #define AHMIM_STM_D_TYPE_29_AP_PIXEL_CAR_START      130u
    #define AHMIM_STM_D_TYPE_29_AP_PIXEL_CAR_HEIGHT     164.0f

    #define AHMIM_STM_D_TYPE_29_AP_PIXEL_CAR_ORIGIN_Y    (AHMIM_STM_D_TYPE_29_AP_PIXEL_CAR_START + (uint16_t)((AHMIM_STM_D_AP_WORLD_CAR_ORIGIN / AHMIM_STM_D_AP_WORLD_CAR_HEIGHT) * AHMIM_STM_D_TYPE_29_AP_PIXEL_CAR_HEIGHT) )
    #define AHMIM_STM_D_TYPE_29_AP_WORLD_TO_PIXEL_FACTOR  (AHMIM_STM_D_AP_WORLD_CAR_HEIGHT/AHMIM_STM_D_TYPE_29_AP_PIXEL_CAR_HEIGHT)
    
    /*******************************************************************************************************************************/

#endif
