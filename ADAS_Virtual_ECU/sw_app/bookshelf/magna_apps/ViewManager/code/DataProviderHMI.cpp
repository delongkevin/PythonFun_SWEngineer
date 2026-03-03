//--------------------------------------------------------------------------
/// @file DataProviderHMI.cpp
/// @brief Contains
///
/// DataProvider is an interface between HMI module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Faizaan Sayyad (Faizaan.Sayyad1@magna.com)
/// 
//  --------------------------------------------------------------------------

//#include <stdint.h>

#define ML_Trailer_Det_Active 0
#define TRSC_HARDCODE_ENABLE 0
#define AP_HARDCODE_ENABLE 0
#define THA_HARDCODE_ENABLE 0
#define HMI_DEGRADATION_DEBUG_ENABLE 0 // debug flag for degradation bench test

#include "DataProviderHMI.h"
#include <utils/console_io/include/app_log.h>
#include <math.h>
#include <ti/osal/TimerP.h>
#include <ti/osal/osal.h>

#define HMI_PROFILING 0
#if HMI_PROFILING 
  #include <utils/console_io/include/app_log.h>
    //#define GPIO_TIMING_MEASURE_ENA
    #if defined(GPIO_TIMING_MEASURE_ENA)
    #include <ti/csl/csl_gpio.h>
    #endif
#endif

extern "C"{
  extern aSigConverterTypes_S_Rx_HmiMRelatedData_t aHmiM_STM_v_Rx_HmiMRelatedData_e;
  #if HMI_PROFILING 
    extern uint64_t end_time2, hit_counter, hit_counter2;
    extern bool TouchFlag, GearFlag, DisplayStsFlag;
    extern bool TouchFlag2, GearFlag2, DisplayStsFlag2;
    extern uint64_t TouchRecieved, GearRecieved, DisplayStsRecieved;
  #endif
}

#if HMI_PROFILING 
  ScreenResponse_t screenResponse2;
  static ME_Hydra2defs_E_ViewType_t lastCurrentScreen;
#endif

typedef unsigned short int      u16;
// FZ static u16 view_no = 0;

ParkingSlotType_t Determine_SlotType(Float2 SlotData[]);
namespace HMI
{

DataProviderHMI::DataProviderHMI()
{
}

DataProviderHMI::~DataProviderHMI()
{
}

void DataProviderHMI::get_vehicle_signal_input(void)
{
  /* DD-ID: {358A1295-49A3-42bd-B868-810114BBF5AD}*/

static boolean SvsProxiReadDone = FALSE;
static ME_VehInp_to_IpcSignals_t vehInputSig;
 
SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(&vehInputSig);

#if HMI_PROFILING
  static bool update_hit_counter2 = TRUE;
	SigMgr_PpScreenResponse_ScreenResponse_t_Get(&screenResponse2);

  if(lastCurrentScreen != (ME_Hydra2defs_E_ViewType_t)screenResponse2.MeSVS_e_ViewEngResCode)
  {
    end_time2 = TimerP_getTimeInUsecs();
    update_hit_counter2 = FALSE;
    lastCurrentScreen = (ME_Hydra2defs_E_ViewType_t)screenResponse2.MeSVS_e_ViewEngResCode;
  }
  
  /*HMI Instance 1 - Reading VCAN Signals from MCU1_0*/
  aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnStatus_e      = (aSigConverter_E_CM_TCH_STAT_t)vehInputSig.CAN2_to_IPC.DataInp_TELEMATIC_FD_5.CM_TCH_STAT;
  aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e  = (aSigConverter_E_CameraDisplaySts2_t)vehInputSig.CAN2_to_IPC.DataInp_TELEMATIC_FD_5.CameraDisplaySts2;
  aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e         = (aSigConverter_E_PRND_STAT_t)vehInputSig.CAN2_to_IPC.DataInp_TRANSM_FD_4.ShiftLeverPosition;
  aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e     = (aSigConverter_E_CmdIgnStat_t)vehInputSig.CAN2_to_IPC.DataInp_BCM_FD_10.CmdIgnSts;
  
  if( (TRUE)
      && (TCH_PSD == aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnStatus_e)
      && (FALSE == TouchFlag)
      && (FALSE == TouchFlag2)
      && (aHmiM_STM_v_Rx_HmiMRelatedData_e.prev_tchScrnStatus_e != aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnStatus_e)
  )
  {
    TouchFlag = TRUE;
    // TouchFlag2 = TRUE;
    //coord for BURV
    TouchRecieved = TimerP_getTimeInUsecs();
  }

  /*0, 4, 10 and 15 are skipped as they are not required*/
  /*All values that won't cause views to switch are gaurded*/
  if( (TRUE)
      && (FALSE == DisplayStsFlag)
      && (FALSE == DisplayStsFlag2)
      && ((aHmiM_STM_v_Rx_HmiMRelatedData_e.prev_CameraDisplaySts2_e != aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
      || (aHmiM_STM_v_Rx_HmiMRelatedData_e.prev_ignitionStatus_e != aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e))
  )
  {
    if( 
      ( (TRUE)
        && (0u != aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
        && (4u != aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
        && (10u != aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
        && (15u != aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
      )
      ||
      ( (FALSE)
        || ((IGN_RUN == aHmiM_STM_v_Rx_HmiMRelatedData_e.prev_ignitionStatus_e) && (IGN_RUN != aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e))
        || ((IGN_RUN != aHmiM_STM_v_Rx_HmiMRelatedData_e.prev_ignitionStatus_e) && (IGN_RUN == aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e))
      )
    )
    {
      hit_counter = 0;
      hit_counter2 = 0;
      update_hit_counter2 = TRUE;
    DisplayStsFlag = TRUE;
    // DisplayStsFlag2 = TRUE;
    DisplayStsRecieved = TimerP_getTimeInUsecs();
    #if defined(GPIO_TIMING_MEASURE_ENA)
      GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 35, GPIO_PIN_LOW);
      GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 34, GPIO_PIN_HIGH);
    #endif
    }
  }

  if( (TRUE)
      && (PRND_STAT_D == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e)
      && (FALSE == GearFlag)
      && (FALSE == GearFlag2)
      && (aHmiM_STM_v_Rx_HmiMRelatedData_e.prev_prndStatus_e != aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e)
  )
  {
    GearFlag = TRUE;
    // GearFlag2 = TRUE;
    GearRecieved = TimerP_getTimeInUsecs();
  }

  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.prev_tchScrnStatus_e != aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnStatus_e)
    aHmiM_STM_v_Rx_HmiMRelatedData_e.prev_tchScrnStatus_e = aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnStatus_e;

  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.prev_prndStatus_e != aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e)
    aHmiM_STM_v_Rx_HmiMRelatedData_e.prev_prndStatus_e = aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e;

  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.prev_CameraDisplaySts2_e != aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
    aHmiM_STM_v_Rx_HmiMRelatedData_e.prev_CameraDisplaySts2_e = aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e;

  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.prev_ignitionStatus_e != aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e)
    aHmiM_STM_v_Rx_HmiMRelatedData_e.prev_ignitionStatus_e = aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e; 

  hit_counter++;
  
  if(TRUE == update_hit_counter2)
  {
    hit_counter2++;
  } 

#endif

static ME_ProxiToMCU2_0_Def_t proxiInputSig;  

if(TRUE != SvsProxiReadDone)
{
  SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Get(&proxiInputSig);
  if(TRUE == proxiInputSig.PRX_bValid_b)
  {
    /*PROXI SIGNALS*/
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_VariantID              = proxiInputSig.PRX_variantID_u8;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_VehLineCfg             = proxiInputSig.PRX_VehLineCfg_u8;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_Wheelbase              = proxiInputSig.PRX_Wheelbase_u8;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_SteerRatRackPinionType = proxiInputSig.PRX_StrRatRckPinionTyp_u8;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_RadDispType            = proxiInputSig.PRX_RadioDispTyp_u8;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_MirrorType             = proxiInputSig.PRX_MirrorType_u8;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_PAMTunSet              = proxiInputSig.PRX_PAMTunSet_u8;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_AutonomyLvl            = proxiInputSig.PRX_AutonomyLvl_u8;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_SurroundViewCamera     = proxiInputSig.PRX_SurroundViewCamera_b;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_FrwFacingCam           = proxiInputSig.PRX_FrwFacingCam_b;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_AuxTrlrCam             = proxiInputSig.PRX_AuxTrlrCam_b;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CANNode95              = proxiInputSig.PRX_CanNod95_b;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CanNode27              = proxiInputSig.PRX_CanNod27_b;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_TRGPresence            = proxiInputSig.PRX_TRGPresence_b;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_TRSCPresence           = proxiInputSig.PRX_TRSCPresence_b; 
	  aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_TrlrHitchAssPres       = proxiInputSig.PRX_TrlrHitchAssPres_b;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CANNode63              = proxiInputSig.PRX_CanNod63_b;
    /*FOR FUTURE USE*/
    /*
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_TrlrSurroundPresence   = proxiInputSig.PRX_TrlrSurroundPresence_b;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_ParkSenseCamView       = proxiInputSig.PRX_ParkSenseCamView_b;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_DigTVfeature           = proxiInputSig.PRX_DigTVfeature_b;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_CountryCode            = proxiInputSig.PRX_CountryCode_u8;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_ModelYear              = proxiInputSig.PRX_ModelYear_u8;
    */
    /***************/

    if( FALSE
    || ((uint8)2 == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_RadDispType)
    || ((uint8)9 == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_RadDispType)
    )
    {
      /*Do Nothing*/
    }
    else 
    {
      aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_RadDispType = (uint8)0x07u;
    }
  SvsProxiReadDone = TRUE;
  }

  else 
  {  
    /*PROXI SIGNALS*/
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_VariantID              = (uint8)0x08u; //proxiInputSig.MePRX_e_VariantID;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_VehLineCfg             = (uint8)VEH_LINE1_DT;	//53			    
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_Wheelbase              = (uint8)0x01u;				    
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_SteerRatRackPinionType = (uint8)0x01u;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_RadDispType            = (uint8)0x07u;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_MirrorType             = (uint8)0x01u;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_PAMTunSet              = (uint8)0x01u;     		  
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_AutonomyLvl            = (uint8)0x01u;				    
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_SurroundViewCamera     = (uint8)0x01u;		
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_FrwFacingCam           = (uint8)0x01u;     	  
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_AuxTrlrCam             = (uint8)0x01u;         		
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CANNode95              = (uint8)0x01u;          		
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CanNode27              = (uint8)0x01u;             
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_TRGPresence            = (uint8)0x01u;        	
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_TRSCPresence           = (uint8)0x01u;
	  aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_TrlrHitchAssPres       = (uint8)0x01u;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CANNode63              = (uint8)0x01u;

    /*FOR FUTURE USE*/
    /*
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_TrlrSurroundPresence   = (uint8)0x01u;	  
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_ParkSenseCamView       = (uint8)0x01u;   
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_DigTVfeature           = (uint8)0x01u;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_CountryCode            = (uint8)0x01u; 
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_ModelYear              = (uint8)0x01u;     	
    */
    /***************/
  }
}
else {/*Do Nothing*/}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

/*TELEMATIC_FD_5 and TELEMATIC_FD_14 Signals*/
aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnStatus_e      = (aSigConverter_E_CM_TCH_STAT_t)vehInputSig.CAN2_to_IPC.DataInp_TELEMATIC_FD_5.CM_TCH_STAT;
aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.X_u16 = (u16)vehInputSig.CAN2_to_IPC.DataInp_TELEMATIC_FD_5.CM_TCH_X_COORD;
aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.Y_u16 = (u16)vehInputSig.CAN2_to_IPC.DataInp_TELEMATIC_FD_5.CM_TCH_Y_COORD;
aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e  = (aSigConverter_E_CameraDisplaySts2_t)vehInputSig.CAN2_to_IPC.DataInp_TELEMATIC_FD_5.CameraDisplaySts2;
aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e      = (aSigConverter_E_TGW_DISP_STAT_t)vehInputSig.CAN2_to_IPC.DataInp_TELEMATIC_FD_14.TGW_CAMERA_DISP_STAT;
/********************************************/

/*IPC VEHICLE SETUP*/

aHmiM_STM_v_Rx_HmiMRelatedData_e.LanguageSelection_u8            = vehInputSig.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.LanguageSelection;
aHmiM_STM_v_Rx_HmiMRelatedData_e.SVC_Static_Gridlines_Feature_b  = (BOOL)vehInputSig.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.StaticGrid;
aHmiM_STM_v_Rx_HmiMRelatedData_e.SVC_FFCV_Gridlines_Feature_b    = (BOOL)vehInputSig.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.Fwrd_Cam_Guidelines;
if(aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_SurroundViewCamera == 1U)
{
  
  aHmiM_STM_v_Rx_HmiMRelatedData_e.SVC_Dynamic_Gridlines_Feature_b = (BOOL)vehInputSig.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.SVC_Guidelines;
}
else
{
 aHmiM_STM_v_Rx_HmiMRelatedData_e.SVC_Dynamic_Gridlines_Feature_b = (BOOL)vehInputSig.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.DynamicGrid;
}

/*******************/
//Rx_HmiRelatedData->tchScrnCoordRaw_s=(u16){0,0};

aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e       = (aSigConverter_E_CmdIgnStat_t)vehInputSig.CAN2_to_IPC.DataInp_BCM_FD_10.CmdIgnSts;

//Req 18986388 : Treat  Gear = L OR TIP_Autostick OR Plus OR Minus OR Sport as Gear = Drive
if((FALSE)
  || (4u == vehInputSig.CAN2_to_IPC.DataInp_TRANSM_FD_4.ShiftLeverPosition)
  || (5u == vehInputSig.CAN2_to_IPC.DataInp_TRANSM_FD_4.ShiftLeverPosition)
  || (6u == vehInputSig.CAN2_to_IPC.DataInp_TRANSM_FD_4.ShiftLeverPosition)
  || (7u == vehInputSig.CAN2_to_IPC.DataInp_TRANSM_FD_4.ShiftLeverPosition)
  || (8u == vehInputSig.CAN2_to_IPC.DataInp_TRANSM_FD_4.ShiftLeverPosition)
  || (9u == vehInputSig.CAN2_to_IPC.DataInp_TRANSM_FD_4.ShiftLeverPosition)
)
{
  vehInputSig.CAN2_to_IPC.DataInp_TRANSM_FD_4.ShiftLeverPosition = 4;
}
else
{
  // Do nothing
}

if(2u == vehInputSig.CAN2_to_IPC.DataInp_TRANSM_FD_4.ShiftLeverPosition)
{  
  aHmiM_STM_v_Rx_HmiMRelatedData_e.revGear_e          = REV_GEAR_ENGAGED;
}
else
{  
  aHmiM_STM_v_Rx_HmiMRelatedData_e.revGear_e          = REV_GEAR_NOT_ENGAGED;
}

aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e           = (aSigConverter_E_PRND_STAT_t)vehInputSig.CAN2_to_IPC.DataInp_TRANSM_FD_4.ShiftLeverPosition;
aHmiM_STM_v_Rx_HmiMRelatedData_e.steeringWheelAngle_f32 = (f32)vehInputSig.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle;
aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32       = (f32)vehInputSig.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig;
aHmiM_STM_v_Rx_HmiMRelatedData_e.SVC_Delay_Feature_b    = 0;

/*DOOR Status*/
aHmiM_STM_v_Rx_HmiMRelatedData_e.TailgateAJAR_e   = (aSigConverter_E_DOOR_AJAR_t)vehInputSig.CAN2_to_IPC.DataInp_BCM_FD_9.RHatchSts;
aHmiM_STM_v_Rx_HmiMRelatedData_e.LeftFrontAJAR_e  = (aSigConverter_E_DOOR_AJAR_t)vehInputSig.CAN2_to_IPC.DataInp_BCM_FD_9.DriverDoorSts;    
aHmiM_STM_v_Rx_HmiMRelatedData_e.LeftRearAJAR_e   = (aSigConverter_E_DOOR_AJAR_t)vehInputSig.CAN2_to_IPC.DataInp_BCM_FD_9.LHRDoorSts;
aHmiM_STM_v_Rx_HmiMRelatedData_e.RightRearAJAR_e  = (aSigConverter_E_DOOR_AJAR_t)vehInputSig.CAN2_to_IPC.DataInp_BCM_FD_9.RHRDoorSts;   
aHmiM_STM_v_Rx_HmiMRelatedData_e.RightFrontAJAR_e = (aSigConverter_E_DOOR_AJAR_t)vehInputSig.CAN2_to_IPC.DataInp_BCM_FD_9.PsngrDoorSts;  
/************************/
/* Degradation FID */


FID_STRUCT_B degradedFID_B;
SigMgr_Data_FID_STRUCT_B_Get(&degradedFID_B);
/* Read SVS HMI degradation FID every cycle using IPC interface */
#if !HMI_DEGRADATION_DEBUG_ENABLE
aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_Disabled = degradedFID_B.m_B_FID_SV360_DISABLED;
aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod1 =  degradedFID_B.m_B_FID_SV360_LIMITED_Mode1;
aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod2 =  degradedFID_B.m_B_FID_SV360_LIMITED_Mode2;
aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod3 =  degradedFID_B.m_B_FID_SV360_LIMITED_Mode3;
aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod4 =  degradedFID_B.m_B_FID_SV360_LIMITED_Mode4;
aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod5 =  degradedFID_B.m_B_FID_SV360_LIMITED_Mode5;
aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod6 =  degradedFID_B.m_B_FID_SV360_LIMITED_Mode6;
aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod7 =  degradedFID_B.m_B_FID_SV360_LIMITED_Mode7;
aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod8 =  degradedFID_B.m_B_FID_SV360_LIMITED_Mode8;
aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod9 =  degradedFID_B.m_B_FID_SV360_LIMITED_Mode9;
aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod10 = degradedFID_B.m_B_FID_SV360_LIMITED_Mode10;
aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod11 = degradedFID_B.m_B_FID_SV360_LIMITED_Mode11;
aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMModOpenDoor = degradedFID_B.m_B_FID_SV360_LIMITED_Open_Door;
#else
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32 == 1.0F)
  {
  aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_Disabled 	= 1 ;
  }
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32 == 2.0F)
  {
  aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod1 	  = 1 ;
  }
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32 ==3.0F)
  {
  aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod2 	  = 1 ;
  }
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32 ==4.0F)
  {
  aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod3 	  = 1 ;
  }
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32 == 5.0F)
  {
  aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod4 	  = 1 ;
  }
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32 ==6.0F)
  {
  aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod5 	  = 1 ;
  }
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32  ==7.0F)
  {
  aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod6 	  = 1 ;
  }
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32 ==8.0F)
  {
  aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod7 	  = 1 ;
  }
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32==9.0F)
  {
  aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod8 	  = 1 ;
  }
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32 ==10.0F)
  {
  aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod9 	  = 1 ;
  }
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32 ==11.0F)
  {
  aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod10 	= 1 ;
  }
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32 ==12.0F)
  {
  aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod11 	= 1 ;
  }
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32 ==13.0F)
  {
  aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMModOpenDoor= 1 ;
  }
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32 == 0.0F)
  {
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_Disabled = 0;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod1 	  = 0 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod2 	  = 0 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod3 	  = 0 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod4 	  = 0 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod5 	  = 0 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod6 	  = 0 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod7 	  = 0 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod8 	  = 0 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod9 	  = 0 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod10 	= 0 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod11 	= 0 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMModOpenDoor= 0 ; 
  }
  if (aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32 == 20.0F)
  {
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_Disabled = 0;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod1 	  = 1 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod2 	  = 1 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod3 	  = 1 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod4 	  = 1 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod5 	  = 1 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod6 	  = 1 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod7 	  = 1 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod8 	  = 1 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod9 	  = 1 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod10 	= 1 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod11 	= 1 ;
    aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMModOpenDoor= 1 ; 
  }
#endif

/*HARDCODED VALUES*/
aHmiM_STM_v_Rx_HmiMRelatedData_e.lrwsST_e           = LRWS_ST_OK;
aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e    = TRANS_AUTOMATIC;
aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleLine_e      = VEH_LINE1_DT;
aHmiM_STM_v_Rx_HmiMRelatedData_e.trscStat_e         = TRSC_CALIBRATING;
aHmiM_STM_v_Rx_HmiMRelatedData_e.NetCfg_TRSCM_e     = TRSCM_Prsnt_TRUE;
aHmiM_STM_v_Rx_HmiMRelatedData_e.GW_C_I6_timeout_b  = FALSE;
/*****************/

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
static IFPAInfoToHMI_t AP_Detection_to_HMI;

#if !AP_HARDCODE_ENABLE
	SigMgr_Data_IFPAInfoToHMI_t_Get(&AP_Detection_to_HMI);
#endif

#if AP_HARDCODE_ENABLE
  #define HARDCODED_SLOT_WIDTH (3.000f)
  #define HARDCODED_SLOT_HEIGHT (6.000f)

  /*TEST DATA*/
  static int DetectionInitHMI = 0;
  if(0 == DetectionInitHMI)
  {
    DetectionInitHMI = 1;
    //!!/***********************************************************************************************************************************************************/
    /*
    HARDCODED PERPENDICULAR SLOT ON LEFT L1
    V1 V0(2,-3)
    V2 V3
    */
    AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	0	].y	=	(-3.000f)	;
    AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	0	].x	=	(2.000f) ;
    AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	1	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	0	].y -	HARDCODED_SLOT_HEIGHT;
    AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	1	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	0	].x;
    AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	2	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	0	].y -	HARDCODED_SLOT_HEIGHT;
    AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	2	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	0	].x + HARDCODED_SLOT_WIDTH;
    AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	3	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	0	].y;
    AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	3	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	0	].x + HARDCODED_SLOT_WIDTH;
    AP_Detection_to_HMI.stFPAParkingSlotData[	0	].m_SlotID	      =	ParkingSlotID_E_L1	;
    AP_Detection_to_HMI.stFPAParkingSlotData[	0	].m_SlotSide      = SlotSide_E_SLOT_LEFT;
              AP_Detection_to_HMI.m_Parkable[ 0 ]                 = TRUE;
    //!!/***********************************************************************************************************************************************************/

    //!!/***********************************************************************************************************************************************************/
    /*
    HARDCODED PARALLEL SLOT ON LEFT L2
    V1 V0(4,-3)
    V2 V3
    */
    AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	0	].y	=	(-3.000f)	;
    AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	0	].x	=	(4.000f) ;
    AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	1	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	0	].y -	HARDCODED_SLOT_WIDTH;
    AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	1	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	0	].x;
    AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	2	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	0	].y -	HARDCODED_SLOT_WIDTH;
    AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	2	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	0	].x + HARDCODED_SLOT_HEIGHT;
    AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	3	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	0	].y;
    AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	3	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	0	].x + HARDCODED_SLOT_HEIGHT;
    AP_Detection_to_HMI.stFPAParkingSlotData[	1	].m_SlotID	      =	ParkingSlotID_E_L2	;
    AP_Detection_to_HMI.stFPAParkingSlotData[	1	].m_SlotSide      = SlotSide_E_SLOT_LEFT;
              AP_Detection_to_HMI.m_Parkable[ 1 ]                 = TRUE;
    //!!/***********************************************************************************************************************************************************/

    //!!/***********************************************************************************************************************************************************/
    /*
    HARDCODED PARALLEL SLOT ON LEFT L3
    V1 V0(6,-3)
    V2 V3
    */
    AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	0	].y	=	(-3.000f)	;
    AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	0	].x	=	(6.000f) ;
    AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	1	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	0	].y -	HARDCODED_SLOT_WIDTH;
    AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	1	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	0	].x;
    AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	2	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	0	].y -	HARDCODED_SLOT_WIDTH;
    AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	2	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	0	].x + HARDCODED_SLOT_HEIGHT;
    AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	3	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	0	].y;
    AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	3	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	0	].x + HARDCODED_SLOT_HEIGHT;
    AP_Detection_to_HMI.stFPAParkingSlotData[	2	].m_SlotID	      =	ParkingSlotID_E_L3	;
    AP_Detection_to_HMI.stFPAParkingSlotData[	2	].m_SlotSide      = SlotSide_E_SLOT_LEFT;
              AP_Detection_to_HMI.m_Parkable[ 2 ]                 = TRUE;
    //!!/***********************************************************************************************************************************************************/

    //!!/***********************************************************************************************************************************************************/
    /*
    HARDCODED PARALLEL SLOT ON RIGHT R1
    V0(3,3) V1
    V3      V2
    */
    AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	0	].y	=	(3.000f)	;
    AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	0	].x	=	(3.000f)  ;
    AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	1	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	0	].y +	HARDCODED_SLOT_WIDTH;
    AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	1	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	0	].x;
    AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	2	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	0	].y +	HARDCODED_SLOT_WIDTH;
    AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	2	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	0	].x + HARDCODED_SLOT_HEIGHT;
    AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	3	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	0	].y;
    AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	3	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	0	].x + HARDCODED_SLOT_HEIGHT;
    AP_Detection_to_HMI.stFPAParkingSlotData[	3	].m_SlotID	      =	ParkingSlotID_E_R1	 ;
    AP_Detection_to_HMI.stFPAParkingSlotData[	3	].m_SlotSide      = SlotSide_E_SLOT_RIGHT;
              AP_Detection_to_HMI.m_Parkable[ 3 ]                 = TRUE;
    //!!/***********************************************************************************************************************************************************/
            
    //!!/***********************************************************************************************************************************************************/
    /*
    HARDCODED PERPENDICULAR SLOT ON RIGHT R2
    V0(5,3) V1
    V3        V2
    */
    AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	0	].y	=	(3.000f)   ;
    AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	0	].x	=	(5.000f)  ;
    AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	1	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	0	].y +	HARDCODED_SLOT_HEIGHT;
    AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	1	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	0	].x;
    AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	2	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	0	].y +	HARDCODED_SLOT_HEIGHT;
    AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	2	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	0	].x + HARDCODED_SLOT_WIDTH;
    AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	3	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	0	].y;
    AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	3	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	0	].x + HARDCODED_SLOT_WIDTH;
    AP_Detection_to_HMI.stFPAParkingSlotData[	4	].m_SlotID	      =	ParkingSlotID_E_R2	  ;
    AP_Detection_to_HMI.stFPAParkingSlotData[	4	].m_SlotSide      = SlotSide_E_SLOT_RIGHT ;
              AP_Detection_to_HMI.m_Parkable[ 4 ]                 = TRUE;
    //!!/***********************************************************************************************************************************************************/
    
    //!!/***********************************************************************************************************************************************************/
    /*
    HARDCODED PERPENDICULAR SLOT ON RIGHT R3
    V0(8,3) V1
    V3        V2
    */
    AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	0	].y	=	(3.000f)   ;
    AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	0	].x	=	(8.000f)  ;
    AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	1	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	0	].y +	HARDCODED_SLOT_HEIGHT;
    AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	1	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	0	].x;
    AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	2	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	0	].y +	HARDCODED_SLOT_HEIGHT;
    AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	2	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	0	].x + HARDCODED_SLOT_WIDTH;
    AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	3	].y	=	AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	0	].y;
    AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	3	].x	=	AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	0	].x + HARDCODED_SLOT_WIDTH;
    AP_Detection_to_HMI.stFPAParkingSlotData[	5	].m_SlotID	      =	ParkingSlotID_E_R3	  ;
    AP_Detection_to_HMI.stFPAParkingSlotData[	5	].m_SlotSide      = SlotSide_E_SLOT_RIGHT ;
              AP_Detection_to_HMI.m_Parkable[ 5 ]                 = TRUE;
    //!!/***********************************************************************************************************************************************************/

  }

  /*This will increment slot coordinates and simulate that vehicle is moving*/
  static int HMI_Detection_Counter = 0;
  int slot_update_rate = 5; /*Random experimental value*/
  float32_t slot_increament_meter = 0.010f;
  if(slot_update_rate > HMI_Detection_Counter)
    HMI_Detection_Counter++;
  else
  {
    HMI_Detection_Counter = 0;
    AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	0	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	1	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	2	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	3	].x += slot_increament_meter;

    AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	0	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	1	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	2	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	1	].Vertices[	3	].x += slot_increament_meter;
  
    AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	0	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	1	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	2	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	2	].Vertices[	3	].x += slot_increament_meter;

    AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	0	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	1	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	2	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	3	].Vertices[	3	].x += slot_increament_meter;

    AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	0	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	1	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	2	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	4	].Vertices[	3	].x += slot_increament_meter;

    AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	0	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	1	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	2	].x += slot_increament_meter;
    AP_Detection_to_HMI.stFPAParkingSlotData[	5	].Vertices[	3	].x += slot_increament_meter;

    /*20.0f is 20 meter, so just resetting hardcoded data after 20meter is crossed*/
    if(AP_Detection_to_HMI.stFPAParkingSlotData[	0	].Vertices[	3	].x	> (20.000f))
      DetectionInitHMI = 0 ; /*This will reinitialise test data*/
  }
#endif
  
static uint8_t arr_length = 6; //as max number of slot are 6
for(uint8_t arr_index=0; arr_index < arr_length; arr_index++)
{
  
  for(uint8_t ver_index=0; ver_index < 4; ver_index++)
  {
    aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[arr_index].Vertices[ver_index].x = 
      1000.0f * AP_Detection_to_HMI.stFPAParkingSlotData[arr_index].Vertices[ver_index].x;

    aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[arr_index].Vertices[ver_index].y = 
      1000.0f * AP_Detection_to_HMI.stFPAParkingSlotData[arr_index].Vertices[ver_index].y;    
  }

  aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[arr_index].m_SlotType      =
    AP_Detection_to_HMI.stFPAParkingSlotData[arr_index].m_SlotType ;

  aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[arr_index].m_SlotSide      =
    AP_Detection_to_HMI.stFPAParkingSlotData[arr_index].m_SlotSide ;

  aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[arr_index].m_SlotID        =
    AP_Detection_to_HMI.stFPAParkingSlotData[arr_index].m_SlotID ;

  aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[arr_index].m_isSlotValid_b =
    AP_Detection_to_HMI.m_Parkable[arr_index];

  //TODO: CAN I use slot type from Detection now? Answer From Aruna 12th July - NO
  /*Added as slotType from Detection was not working*/
  aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[arr_index].m_SlotType =
      Determine_SlotType(AP_Detection_to_HMI.stFPAParkingSlotData[arr_index].Vertices);
}

static TbAP_SMPAInternalOut_t AP_SM_to_HMI;
static TbAP_FPAWarnOut_t FPA_to_HMI;
static TbAP_RPAWarnOut_t RPA_to_HMI;

#if !AP_HARDCODE_ENABLE
  SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Get(&AP_SM_to_HMI);
  SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Get(&FPA_to_HMI);
  SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Get(&RPA_to_HMI);
#endif

#if AP_HARDCODE_ENABLE

  static int HMI_AutoPark_Counter = 0;
  static int SCAN_Screen_Num = 0;
  static int prev_SCAN_Screen_Num = 0;

  if(FALSE)
  {
    if(150 < HMI_AutoPark_Counter)
    {  
      HMI_AutoPark_Counter = 0;
      SCAN_Screen_Num++;
    }
    else
    {
      HMI_AutoPark_Counter++;
    }

    if(82u < SCAN_Screen_Num)
    {
      SCAN_Screen_Num = 0;
    }

    switch((TeAP_e_HMIPopUp)SCAN_Screen_Num)
    {
      case TeAP_e_HMIPopUp_IDLE:
      case TeAP_e_HMIPopUp_SHIFT_TO_DRIVE:
      case TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD:
      case TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH:
      case TeAP_e_HMIPopUp_SPACE_FOUND_STOP:
      case TeAP_e_HMIPopUp_SPACE_FOUND_STOP_STANDSTILL:
      case TeAP_e_HMIPopUp_SPACE_FOUND_SPEED_TOO_HIGH:
      case TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE:
      case TeAP_e_HMIPopUp_PERP_SELECT_LEFT:
      case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_FORWARD_AVAIL:
      case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_REVERSE_AVAIL:
      case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_FORWARD:
      case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_REVERSE:
      case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT:
      case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_FORWARD_AVAIL:
      case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_REVERSE_AVAIL:
      case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_FORWARD:
      case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_REVERSE:
      case TeAP_e_HMIPopUp_DISCLAIMER:
      case TeAP_e_HMIPopUp_PARALLEL_EXIT_SELECT:
      case TeAP_e_HMIPopUp_PARALLEL_EXIT_STOP:
      case TeAP_e_HMIPopUp_REMOVE_HANDS_FEET:
      case TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_FRONT:
      case TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR:
      case TeAP_e_HMIPopUp_PAUSED_PRESS_BUTTON:
      case TeAP_e_HMIPopUp_PAUSED_OBJECT_IN_PATH:
      case TeAP_e_HMIPopUp_COMPLETE_PROCEED:
      case TeAP_e_HMIPopUp_COMPLETE_RELEASE:
      case TeAP_e_HMIPopUp_SPACE_FOUND_REMOVE_HANDS_LEFT:
      case TeAP_e_HMIPopUp_SPACE_FOUND_REMOVE_HANDS_RIGHT:
      case TeAP_e_HMIPopUp_PARALLEL_EXIT_REMOVE_HANDS_LEFT:
      case TeAP_e_HMIPopUp_PARALLEL_EXIT_REMOVE_HANDS_RIGHT:
      case TeAP_e_HMIPopUp_WAIT_FOR_STEER_FRONT:
      case TeAP_e_HMIPopUp_WAIT_FOR_STEER_REAR:
      case TeAP_e_HMIPopUp_MOVE_BACKWARD:
      case TeAP_e_HMIPopUp_STOP_FRONT:
      case TeAP_e_HMIPopUp_STOP_REAR:
      case TeAP_e_HMIPopUp_SHIFT_TO_DRIVE_GUIDANCE:
      case TeAP_e_HMIPopUp_MOVE_FORWARD:
      case TeAP_e_HMIPopUp_SHIFT_TO_REVERSE:
      case TeAP_e_HMIPopUp_COMPLETE_HMI_FRONT:
      case TeAP_e_HMIPopUp_COMPLETE_HMI_REAR:
      case TeAP_e_HMIPopUp_DOOR_OPEN_FULLSCREEN:
      case TeAP_e_HMIPopUp_LIFEGATE_OPEN_FULLSCREEN:
      case TeAP_e_HMIPopUp_ESC_ACTIVE_FULLSCREEN:
      case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_FULLSCREEN:
      case TeAP_e_HMIPopUp_LO4_ACTIVE_FULLSCREEN:
      case TeAP_e_HMIPopUp_TRAILER_CONNECTED_FULLSCREEN:
      case TeAP_e_HMIPopUp_SERVICE_REQUIRED_FULLSCREEN:
      case TeAP_e_HMIPopUp_FRONT_WIPE_FULLSCREEN:
      case TeAP_e_HMIPopUp_REAR_WIPE_FULLSCREEN:
      case TeAP_e_HMIPopUp_TEMP_NA_FULLSCREEN:
      case TeAP_e_HMIPopUp_CRUISE_CONTROL_ENGAGED_FULLSCREEN:
      case TeAP_e_HMIPopUp_BUTTON_PRESS_FULLSCREEN:
      case TeAP_e_HMIPopUp_DOOR_OPEN_OVERLAY:
      case TeAP_e_HMIPopUp_LIFTGATE_OPEN_OVERLAY:
      case TeAP_e_HMIPopUp_ESC_ACTIVE_OVERLAY:
      case TeAP_e_HMIPopUp_BUTTON_PRESS_TAKECONTROL:
      case TeAP_e_HMIPopUp_LO4_ACTIVE_OVERLAY:
      case TeAP_e_HMIPopUp_TRAILER_CONNECTED_OVERLAY:
      case TeAP_e_HMIPopUp_SERVICE_REQUIRED_OVERLAY:
      case TeAP_e_HMIPopUp_FRONT_WIPE_OVERLAY:
      case TeAP_e_HMIPopUp_REAR_WIPE_OVERLAY:
      case TeAP_e_HMIPopUp_TEMP_NA_OVERLAY:
      case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_REAR:
      case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_FRONT:
      case TeAP_e_HMIPopUp_UNAVAIL_SPEED_TOO_HIGH_OVERLAY:
      case TeAP_e_HMIPopUp_CRUISE_CONTROL_ENGAGED_TAKECONTROL:
      case TeAP_e_HMIPopUp_DOOR_OPEN_TAKECONTROL:
      case TeAP_e_HMIPopUp_LIFTGATE_OPEN_TAKECONTROL:
      case TeAP_e_HMIPopUp_ESC_ACTIVE_TAKECONTROL:
      case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_TAKECONTROL:
      case TeAP_e_HMIPopUp_LO4_ACTIVE_TAKECONTROL:
      case TeAP_e_HMIPopUp_TRAILER_CONNECTED_TAKECONTROL:
      case TeAP_e_HMIPopUp_SERVICE_REQUIRED_TAKECONTROL:
      case TeAP_e_HMIPopUp_FRONT_WIPE_TAKECONTROL:
      case TeAP_e_HMIPopUp_REAR_WIPE_TAKECONTROL:
      case TeAP_e_HMIPopUp_TEMP_NA_TAKECONTROL:
      case TeAP_e_HMIPopUp_WHEEL_TOUCHED_TAKECONTROL:
      case TeAP_e_HMIPopUp_DRIVER_OVERRIDE_TAKECONTROL:
      case TeAP_e_HMIPopUp_MANUAL_PARK_TAKECONTROL:
      case TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_LEFT:
      case TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_RIGHT:
        AP_SM_to_HMI.MeAP_e_HMIPopUp = (TeAP_e_HMIPopUp)SCAN_Screen_Num;
        break;

      default:
        AP_SM_to_HMI.MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        HMI_AutoPark_Counter = 500;
        break;
    }
  }
  else
  {
    if(vehInputSig.CAN2_to_IPC.DataInp_BCM_FD_27.TrailerConnectionSts || vehInputSig.CAN2_to_IPC.DataInp_BCM_FD_29.ITBM_TrlrStat)
      SCAN_Screen_Num = 0;
    else 
      SCAN_Screen_Num = (int)vehInputSig.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig;
    
    AP_SM_to_HMI.MeAP_e_HMIPopUp = (TeAP_e_HMIPopUp)SCAN_Screen_Num;
  }

/*This is test code and under disablled macro*/
static uint64_t time_ref = TimerP_getTimeInUsecs();
static BOOL ARC_TOGGLE_FLAG;

if((TimerP_getTimeInUsecs()-time_ref) > 2000000llu)
{
  ARC_TOGGLE_FLAG = !ARC_TOGGLE_FLAG;
  time_ref = TimerP_getTimeInUsecs();
}

FPA_to_HMI.IeAP_e_DispArcLHF = (TRUE == ARC_TOGGLE_FLAG) ? TeAP_e_Alert_Arc1  :  TeAP_e_Alert_Arc2;
FPA_to_HMI.IeAP_e_DispArcCHF = (TRUE == ARC_TOGGLE_FLAG) ? TeAP_e_Alert_Arc1  :  TeAP_e_Alert_Arc2;
FPA_to_HMI.IeAP_e_DispArcRHF = (TRUE == ARC_TOGGLE_FLAG) ? TeAP_e_Alert_Arc1  :  TeAP_e_Alert_Arc2;
RPA_to_HMI.IeAP_e_DispArcLHR = (TRUE == ARC_TOGGLE_FLAG) ? TeAP_e_Alert_Arc1  :  TeAP_e_Alert_Arc2;
RPA_to_HMI.IeAP_e_DispArcCHR = (TRUE == ARC_TOGGLE_FLAG) ? TeAP_e_Alert_Arc1  :  TeAP_e_Alert_Arc2;
RPA_to_HMI.IeAP_e_DispArcRHR = (TRUE == ARC_TOGGLE_FLAG) ? TeAP_e_Alert_Arc1  :  TeAP_e_Alert_Arc2;
FPA_to_HMI.IeAP_e_ArcFlashRateLHF = TeAP_e_GraphicFlshRate_Solid;
FPA_to_HMI.IeAP_e_ArcFlashRateCHF = TeAP_e_GraphicFlshRate_SlowFlash;
FPA_to_HMI.IeAP_e_ArcFlashRateRHF = TeAP_e_GraphicFlshRate_MAX;
RPA_to_HMI.IeAP_e_ArcFlashRateLHR = TeAP_e_GraphicFlshRate_Solid;
RPA_to_HMI.IeAP_e_ArcFlashRateCHR = TeAP_e_GraphicFlshRate_SlowFlash;
RPA_to_HMI.IeAP_e_ArcFlashRateRHR = TeAP_e_GraphicFlshRate_MAX;

#endif

aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP = AP_SM_to_HMI.MeAP_e_HMIPopUp;

if( (FALSE)
|| (TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_RIGHT < AP_SM_to_HMI.MeAP_e_HMIPopUp)
|| (TeAP_e_HMIPopUp_IDLE > AP_SM_to_HMI.MeAP_e_HMIPopUp) 
)
{
  /*Invalid value recieved hence discard request by Autopark SM and abort feature*/
  aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP = TeAP_e_HMIPopUp_IDLE;
}

aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_FL_e       = FPA_to_HMI.IeAP_e_DispArcLHF ; 
aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_FC_e       = FPA_to_HMI.IeAP_e_DispArcCHF ;
aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_FR_e       = FPA_to_HMI.IeAP_e_DispArcRHF ;
aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_FL_e = FPA_to_HMI.IeAP_e_ArcFlashRateLHF ;
aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_FC_e = FPA_to_HMI.IeAP_e_ArcFlashRateCHF ;
aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_FR_e = FPA_to_HMI.IeAP_e_ArcFlashRateRHF ;

aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_RL_e       = RPA_to_HMI.IeAP_e_DispArcLHR ;
aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_RC_e       = RPA_to_HMI.IeAP_e_DispArcCHR ;
aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_RR_e       = RPA_to_HMI.IeAP_e_DispArcRHR ;
aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_RL_e = RPA_to_HMI.IeAP_e_ArcFlashRateLHR ;
aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_RC_e = RPA_to_HMI.IeAP_e_ArcFlashRateCHR ;
aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_RR_e = RPA_to_HMI.IeAP_e_ArcFlashRateRHR ;

#if !TRSC_HARDCODE_ENABLE
//! **********************TRSC*******************************
static TRSC_Inputs_from_TrailerDetection_t TRSC_Inputs_from_TrailerDetection_e;
SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Get(&TRSC_Inputs_from_TrailerDetection_e);

static TRSCSMVCtoSVS_t TRSCSMVCtoSVS_e;
SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Get(&TRSCSMVCtoSVS_e);
//not used in logic
aHmiM_STM_v_Rx_HmiMRelatedData_e.TrailerAngleSign = (TeTRSC_e_TrlrAngSign)TRSC_Inputs_from_TrailerDetection_e.MeTRSC_e_TrlrAngSign;
aHmiM_STM_v_Rx_HmiMRelatedData_e.MaxTadAngle = (real32_T)TRSCSMVCtoSVS_e.MeTRSC_deg_MaxAllowedTADAngle;

#if ML_Trailer_Det_Active
aHmiM_STM_v_Rx_HmiMRelatedData_e.MeTRSC_e_TrlrPrsntInfo = (uint8_t)TRSC_Inputs_from_TrailerDetection_e.MeTRSC_e_TrlrPrsntInfo;
#endif

#if !ML_Trailer_Det_Active
aHmiM_STM_v_Rx_HmiMRelatedData_e.MeTRSC_e_TrlrPrsntInfo = 0; //Permanetly set to 0 as detection was giving false positives
#endif

aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle = (real32_T)(-TRSC_Inputs_from_TrailerDetection_e.MeTRSC_deg_TADAngle);
aHmiM_STM_v_Rx_HmiMRelatedData_e.KnobAngle = (real32_T)TRSCSMVCtoSVS_e.MeTRSC_deg_KnobAngle;
aHmiM_STM_v_Rx_HmiMRelatedData_e.JackKnifeAngle = (real32_T)TRSCSMVCtoSVS_e.MeTRSC_deg_JackKnifeAngle;

/* Uncomment if debugging is required
static real32_T TadAngle, KnobAngle, JackKnifeAngle;
if((FALSE)
|| (TadAngle != aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle)
|| (KnobAngle != aHmiM_STM_v_Rx_HmiMRelatedData_e.KnobAngle)
|| (JackKnifeAngle != aHmiM_STM_v_Rx_HmiMRelatedData_e.JackKnifeAngle)
)
{
  printf("DP TAD %.1f, KNOB %.1f, JK %.1f"
    ,aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle
    ,aHmiM_STM_v_Rx_HmiMRelatedData_e.KnobAngle
    ,aHmiM_STM_v_Rx_HmiMRelatedData_e.JackKnifeAngle
  );

  TadAngle = aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle;
  KnobAngle = aHmiM_STM_v_Rx_HmiMRelatedData_e.KnobAngle;
  JackKnifeAngle = aHmiM_STM_v_Rx_HmiMRelatedData_e.JackKnifeAngle;
}
*/
aHmiM_STM_v_Rx_HmiMRelatedData_e.TrscStatus = (TeTRSC_e_TRSCStat)TRSCSMVCtoSVS_e.MeTRSC_e_TRSCStat;
aHmiM_STM_v_Rx_HmiMRelatedData_e.TrailerConnectionStatus = (uint8)vehInputSig.CAN2_to_IPC.DataInp_BCM_FD_27.TrailerConnectionSts;
aHmiM_STM_v_Rx_HmiMRelatedData_e.TrailerCalibrationStatus = (TeTRSC_e_TrlrCalInfo)TRSC_Inputs_from_TrailerDetection_e.MeTRSC_e_TrlrCalInfo;
aHmiM_STM_v_Rx_HmiMRelatedData_e.ItbmTrailerStatus = (uint8)vehInputSig.CAN2_to_IPC.DataInp_BCM_FD_29.ITBM_TrlrStat;
#endif

#if TRSC_HARDCODE_ENABLE
//! **********************TRSC*******************************
aHmiM_STM_v_Rx_HmiMRelatedData_e.TrailerAngleSign = (TeTRSC_e_TrlrAngSign)TeTRSC_e_TrlrAngSign_Clockwise; 
aHmiM_STM_v_Rx_HmiMRelatedData_e.MaxTadAngle = (real32_T)90.0f; 

static int INCREMENET_TAD_KNOB_AFTER_N_CYCLES = ((int)20);
static int JK_ARRAY_MAX = ((int)6);
static int TAD_KNOB_ANGLE = ((int)-100);
static int TAD_KNOB_CYCLES = ((int)0);
static int JK_ARRAY_INDEX = 0;
static real32_T JK_Refrence[6] = { 0.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f};

if(TAD_KNOB_CYCLES < INCREMENET_TAD_KNOB_AFTER_N_CYCLES)
{
  TAD_KNOB_CYCLES++;
}
else
{
  TAD_KNOB_CYCLES = (int)0;
  TAD_KNOB_ANGLE++;
}

if(TAD_KNOB_ANGLE <= ((int)100))
{
  //do nothing
}
else
{
  TAD_KNOB_ANGLE = ((int)-100);
  JK_ARRAY_INDEX++;
}

if(JK_ARRAY_INDEX < 6)
{
  //do nothing
}
else
{
  JK_ARRAY_INDEX = 0;
}

aHmiM_STM_v_Rx_HmiMRelatedData_e.JackKnifeAngle = JK_Refrence[JK_ARRAY_INDEX];
aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle = (real32_T)(TAD_KNOB_ANGLE);  
aHmiM_STM_v_Rx_HmiMRelatedData_e.KnobAngle = (real32_T)(-TAD_KNOB_ANGLE); 

aHmiM_STM_v_Rx_HmiMRelatedData_e.TrscStatus = (TeTRSC_e_TRSCStat)vehInputSig.CAN2_to_IPC.DataInp_TRANSM_FD_4.GearEngaged; 
aHmiM_STM_v_Rx_HmiMRelatedData_e.TrailerConnectionStatus = (uint8)vehInputSig.CAN2_to_IPC.DataInp_BCM_FD_27.TrailerConnectionSts;
aHmiM_STM_v_Rx_HmiMRelatedData_e.ItbmTrailerStatus = (uint8)vehInputSig.CAN2_to_IPC.DataInp_BCM_FD_29.ITBM_TrlrStat;
aHmiM_STM_v_Rx_HmiMRelatedData_e.TrailerCalibrationStatus = TeTRSC_e_TrlrCalInfo_Calibrated;

static real32_T TadAngle, KnobAngle, JackKnifeAngle;
if((FALSE)
|| (TadAngle != aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle)
|| (KnobAngle != aHmiM_STM_v_Rx_HmiMRelatedData_e.KnobAngle)
|| (JackKnifeAngle != aHmiM_STM_v_Rx_HmiMRelatedData_e.JackKnifeAngle)
)
{
  printf("\n DP TAD %.1f, KNOB %.1f, JK %.1f"
    ,aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle
    ,aHmiM_STM_v_Rx_HmiMRelatedData_e.KnobAngle
    ,aHmiM_STM_v_Rx_HmiMRelatedData_e.JackKnifeAngle
  );

  TadAngle = aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle;
  KnobAngle = aHmiM_STM_v_Rx_HmiMRelatedData_e.KnobAngle;
  JackKnifeAngle = aHmiM_STM_v_Rx_HmiMRelatedData_e.JackKnifeAngle;
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#endif

#if !THA_HARDCODE_ENABLE
//! THA INPUTS *********************************************
ScreenResponse_t ScreenResponseTHA;
SigMgr_PpScreenResponse_ScreenResponse_t_Get(&ScreenResponseTHA);

TbTHASmVc_FeatureOutputs_t THASmInputToHMI;
SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get(&THASmInputToHMI);

JobTHADetOutput_t THADetInputToHMI;
SigMgr_PpJobTHADetOutput_JobTHADetOutput_t_Get(&THADetInputToHMI);

aHmiM_STM_v_Rx_HmiMRelatedData_e.THA_ScreenRequest_e       = (aSigConverter_E_THAScreenRequest_t)THASmInputToHMI.MeTHA_e_ScreenRequest;
aHmiM_STM_v_Rx_HmiMRelatedData_e.THA_ScreenResponse_e      = (aSigConverter_E_THAScreenRequest_t)THA_Default;
if(e_Cplr_Detected == THADetInputToHMI.CplrDetctStatus_e) {
  aHmiM_STM_v_Rx_HmiMRelatedData_e.THA_LongHitchCplrDiff   = THADetInputToHMI.HitchCplrPixDiffLongY_s32;
}
aHmiM_STM_v_Rx_HmiMRelatedData_e.THA_Is_Valid_Tch_Zone     = (BOOL)ScreenResponseTHA.THAViewZoomResponse;
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
#endif

#if THA_HARDCODE_ENABLE
static ScreenResponse_t ScreenResponseTHA;
SigMgr_PpScreenResponse_ScreenResponse_t_Get(&ScreenResponseTHA);
aHmiM_STM_v_Rx_HmiMRelatedData_e.THA_ScreenRequest_e      = (aSigConverter_E_THAScreenRequest_t)vehInputSig.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.LanguageSelection;
aHmiM_STM_v_Rx_HmiMRelatedData_e.THA_ScreenResponse_e     = (aSigConverter_E_THAScreenRequest_t)THA_Default;
aHmiM_STM_v_Rx_HmiMRelatedData_e.THA_LongHitchCplrDiff    = (uint16_t)0u;
aHmiM_STM_v_Rx_HmiMRelatedData_e.THA_Is_Valid_Tch_Zone    = (BOOL)1u;
#endif

}

int DataProviderHMI::set_HMI_output_signal(aSigConverterTypes_S_Tx_HmiMRelatedData_t hmi_output)
{
  /* DD-ID: {FBAEB208-E43B-49d1-B09D-5CC95B88771A}*/
  return 0;
}
}

ParkingSlotType_t Determine_SlotType(Float2 SlotData[])
{
  /* DD-ID: {808D8E68-68E5-4488-9713-208C9E8F4B43}*/
  Float2 Mid_Top, Mid_Bottom, Mid_Left, Mid_Right;
  float32 height, width;

  /*between vertices 0 and 1*/
  Mid_Top.x = (SlotData[0].x + SlotData[1].x)/2;
  Mid_Top.y = (SlotData[0].y + SlotData[1].y)/2;

  /*between vertices 2 and 3*/
  Mid_Bottom.x = (SlotData[2].x + SlotData[3].x)/2;
  Mid_Bottom.y = (SlotData[2].y + SlotData[3].y)/2;

  /*between vertices 1 and 2*/
  Mid_Left.x = (SlotData[1].x + SlotData[2].x)/2;
  Mid_Left.y = (SlotData[1].y + SlotData[2].y)/2;

  /*between vertices 0 and 3*/
  Mid_Right.x = (SlotData[0].x + SlotData[3].x)/2;
  Mid_Right.y = (SlotData[0].y + SlotData[3].y)/2;

  //TODO : Check with Aruna regarding midpoints //
  
  height   = pow(  ( pow((Mid_Top.x - Mid_Bottom.x),2)  + pow((Mid_Top.y - Mid_Bottom.y),2)  ),  0.5);
  width    = pow(  ( pow((Mid_Left.x - Mid_Right.x),2)  + pow((Mid_Left.y - Mid_Right.y),2)  ),  0.5);

  if(height != width)
    return (height > width) ? ParkingSlotType_E_PW_PARALLEL  :  ParkingSlotType_E_PW_PERPENDICULAR;

  return ParkingSlotType_E_PW_NODIR;
}
