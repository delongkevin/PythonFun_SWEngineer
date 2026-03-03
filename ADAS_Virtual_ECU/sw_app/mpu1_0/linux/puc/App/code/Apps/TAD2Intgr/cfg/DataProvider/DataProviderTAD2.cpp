//--------------------------------------------------------------------------
/// @file DataProviderTAD2.cpp
/// @brief Contains interface for TAD2 Dataprovider
///
/// DataProvider is an interface between TAD module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Pravin Pawar (pravin.pawar@magna.com)
///
//  --------------------------------------------------------------------------

#include "DataProviderTAD2.h"
#include "CANData.h"
#include <fsdata/fsdata.h>
#include <variants/Enums.h>
#include <fstream>
#if TAD2_NVM_ACCESS_ENABLED // Pravin - These buffers are not needed for new code
uint8_t trailerFeaturesBuff[182988+132]; // For 6 trailers 8 x 98
uint8_t trailerTemplate0[30450];
uint8_t trailerTemplate1[30450];
uint8_t trailerTemplate2[30450];
uint8_t trailerTemplate3[30450];
uint8_t trailerTemplate4[30450];
#endif
TRSC_Calibration_data_MPU1_0_t TAD_Calib_Data;

static char tadCalib[] = "/fs/100.dat";

extern "C" bool_t ME_VariantHelper_GetVariantID_b(uint8_t* var_id);

#if DUMP_FISHEYE_1920x1280
const uint32_t rawImageSize = 9830538;
uint8_t imageBuffer[rawImageSize];
#endif
#if DUMP_ALGO_VIEW_FOR_STATE7
int32_t TADState = 0;
#endif
static uint8_t var_id = 0;
static TAD2::VehicleParameters vehicleParams;
static TrailerDetection_Output_DID_t TrailerDetection_Output_DID_local;
static TRSC_Inputs_from_TrailerDetection_t TRSC_Inputs_from_TrailerDetection_local;

static ME_VehInp_to_IpcSignals_t VehData;
const uint32_t ImageSize_u32 = 640 * 400;

#if DUMP_REAR_FISHEYE_ALGO_VIEW
const uint32_t ImageSize = 640 * 426;
uint8_t RawBuffer[ImageSize*3];
#endif

#if !(TAD2_SIGM_TESTING)
#include "../../TAD2/simulation/TADAlgoSimulationData.h"
#endif

#define MAX_NUM_OBJECTS_FROM_SENSOR 40
#define FILEDUMP                    0
volatile uint32_t m_FrameNumber = 1;

namespace TAD2
{

unsigned char ImgBuffer[ImageSize_u32];

DataProviderTAD2::DataProviderTAD2(container::IDataProvider& b_DataProvider_ro)
: IDataProviderTAD2(),
  dataProvider_ro(b_DataProvider_ro)
{
  memset(&VehData, 0, sizeof(ME_VehInp_to_IpcSignals_t));
  memset(&vehicleParams, 0, sizeof(TAD2::VehicleParameters));
  memset(&TrailerDetection_Output_DID_local, 0, sizeof(TrailerDetection_Output_DID_t));
  memset(&TRSC_Inputs_from_TrailerDetection_local, 0, sizeof(TRSC_Inputs_from_TrailerDetection_t));
  memset(&TAD_Calib_Data, 0, sizeof(TRSC_Calibration_data_MPU1_0_t));
#if READ_VARIANT_ID
  char old_var_data[5] ={0};
  uint8_t v_VarId_u8;
  bool_t result_b = true;
  result_b = ME_VariantHelper_GetVariantID_b(&var_id);
#endif
#if TAD2_NVM_ACCESS_ENABLED
  
  // Trailer Features
  for( uint32_t i = 0; i < TrailerID_t::Trailer_MAX; i++ )
  {
      m_loadedFeatures.TrailerData[i].Is_Valid = false;
  }

  InitTrailerTemplate();
  InitJobInput();
#endif
}

DataProviderTAD2::~DataProviderTAD2()
{
#if TAD2_NVM_ACCESS_ENABLED
	// -- Save Features
	TAD2::TrailerFeatures FeatureData = m_jobOutput.TRSC_NVM_Output.trailerFeatures;
	SaveTrailerFeatures( FeatureData );

	for( uint32_t i = 0; i < TrailerID_t::Trailer_MAX; i++ )
	{
		if( m_loadedFeatures.TrailerData[i].trailerTemplate.getData() != NULL )
		{
			m_loadedFeatures.TrailerData[i].trailerTemplate.setData( NULL );
		}
	}
#endif
}

/// @brief  Get TIOVX host handle
bsp::TIOVXHost& DataProviderTAD2::getTIOVX_ro()
{
    return dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
}

/// @brief  Get AlgoView processor data
container::OVL3DData* DataProviderTAD2::getOVL3DData_po()
{
    return dataProvider_ro.getOVL3DData_po();
}

void DataProviderTAD2::getVehicleData() const
{
   VehData = dataProvider_ro.getSigMData_po()->getME_VehInp_to_IpcSignals_t();
}


IKinematicData_t DataProviderTAD2::getKMData() const
{
    return dataProvider_ro.getSigMData_po()->getIKinematicData_t();
}

float32_t DataProviderTAD2::getVehicleSpeed() const
{
   return VehData.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig;
}

int8_t DataProviderTAD2::getVehicleGear() const
{
  uint8_t GearEngaged  = (eVehicleGear_t)VehData.CAN2_to_IPC.DataInp_TRANSM_FD_4.ShiftLeverPosition;
  int8_t MappedGearVal = 0;

  if(TeVBII_e_ShiftLvrPos_P == GearEngaged)
  {
    MappedGearVal = GearValues_E_GEAR_PARK;
  }
  else if(TeVBII_e_ShiftLvrPos_R == GearEngaged)
  {
    MappedGearVal = GearValues_E_GEAR_REVERSE;
  }
  else if((TeVBII_e_ShiftLvrPos_N == GearEngaged) ||
          (TeVBII_e_ShiftLvrPos_SNA == GearEngaged))
  {
    MappedGearVal = GearValues_E_GEAR_NEUTRAL;
  }
  else if(TeVBII_e_ShiftLvrPos_D == GearEngaged)
  {
    MappedGearVal = GearValues_E_GEAR_FORWARD;
  }
  
  return MappedGearVal;
}

TAD2::VehicleControlData DataProviderTAD2::get_VehicleControl_data() const
{
	TAD2::VehicleControlData m_VehicleControlData;

	uint8_t GearEngaged  = (eVehicleGear_t)VehData.CAN2_to_IPC.DataInp_TRANSM_FD_2.GearEngagedForDisplay;
	return m_VehicleControlData;
}

float32_t DataProviderTAD2::getVehicleSteeringWheelAng() const
{
  return VehData.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle;
}

uint8_t DataProviderTAD2::getTailgateStatus() const
{
  return VehData.CAN2_to_IPC.DataInp_BCM_FD_9.RHatchSts;
}

ME_ProxiToMPU1_0_Def_t* DataProviderTAD2::getProxyData() 
{
  v_Proxy_st = dataProvider_ro.getSigMData_po()->getME_Proxi_to_IpcSignals_t();
  return &v_Proxy_st;
}
Detection_Inputs_from_TRSC_t DataProviderTAD2::getDetection_Inputs_from_TRSC() const
{
  return dataProvider_ro.getSigMData_po()->getDetection_Inputs_from_TRSC_t();
}

void DataProviderTAD2::setTrailerDetection_DID(TrailerDetection_Output_DID_t& TrailerDetection_Output_DID)
{
  mapNewSignalsForDID(TrailerDetection_Output_DID);
  // Send IPC message only if there is difference in current and previous message
  ME_CanDebugRIDStatus_t debugStatus_s;
  debugStatus_s = dataProvider_ro.getSigMData_po()->getCanDebugRIDStatus();
  if (Debug_Mode == debugStatus_s.CanDebugMode)
  {
    int32_t isNewMessage = memcmp((void*)&TrailerDetection_Output_DID,
                    (void*)&TrailerDetection_Output_DID_local,
                    sizeof(TrailerDetection_Output_DID_t));
    if (isNewMessage != 0)
    {
      dataProvider_ro.getSigMData_po()->setTrailerDet_Output_DID_v(TrailerDetection_Output_DID);
      memcpy((void*)&TrailerDetection_Output_DID_local,
          (void*)&TrailerDetection_Output_DID,
          sizeof(TrailerDetection_Output_DID_t));
    }
  }
}
void DataProviderTAD2::mapNewSignalsForDID(TrailerDetection_Output_DID_t& TrailerDetection_Output_DID_mapping) 
{
  Detection_Inputs_from_TRSC_t trlrInfo;
  trlrInfo = getDetection_Inputs_from_TRSC();
  // static JobDLDOutput_t DLDstatus;
  // DLDstatus = dataProvider_ro.getSigMData_po()->getJobDLDOutput();
  // m_jobInput.DLDInput.CamBlockStatus = DLDstatus.IeDLD_e_RrCamSts;
  if(isTADFeatureAllowedToRun(trlrInfo.MeTRSC_e_TrlrPrsntInfoCAN))
  {
    switch(TrailerDetection_Output_DID_mapping.Trailer_Calibration_maneuver_State)
    {
      case(CalibrationState_DriveStraight):
      TrailerDetection_Output_DID_mapping.Trailer_Calibration_maneuver_State_DID = CalibrationState_DriveStraight_DID;
      break;
      case(CalibrationState_TurnLeftOrRight):
      TrailerDetection_Output_DID_mapping.Trailer_Calibration_maneuver_State_DID = CalibrationState_TurnLeftOrRight_DID;
      break;
      case(CalibrationState_Wait):
      TrailerDetection_Output_DID_mapping.Trailer_Calibration_maneuver_State_DID = CalibrationState_DriveStraight_DID;
      break;
      default : TrailerDetection_Output_DID_mapping.Trailer_Calibration_maneuver_State_DID = CalibrationState_None_DID;
      break;
    }
    switch(TrailerDetection_Output_DID_mapping.Trailer_Calibration_Status)
    {
      case(TeTRSC_e_TrlrCalInfo_NotCalibrated) : 
      TrailerDetection_Output_DID_mapping.Trailer_Calibration_Status_DID = TeTRSC_e_TrlrCalInfo_NotCalibrated_DID;
      break;
      case(TeTRSC_e_TrlrCalInfo_Calibrated):
      TrailerDetection_Output_DID_mapping.Trailer_Calibration_Status_DID = TeTRSC_e_TrlrCalInfo_Calibrated_DID;
      break;
      default : TrailerDetection_Output_DID_mapping.Trailer_Calibration_Status_DID = TeTRSC_e_TrlrCalInfo_NotCalibrated_DID;
      break;
    }

    switch(TrailerDetection_Output_DID_mapping.Trailer_Presence_detection)
    { 
      case(TeTRSC_e_TrlrPrsntInfo_NoTrlr):
      TrailerDetection_Output_DID_mapping.Trailer_Presence_detection_DID = TeTRSC_e_TrlrPrsntInfo_Not_Detected_DID;
      break;
      case(TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt):
      TrailerDetection_Output_DID_mapping.Trailer_Presence_detection_DID = TeTRSC_e_TrlrPrsntInfo_Detected_DID;
      break;
      default : TrailerDetection_Output_DID_mapping.Trailer_Presence_detection_DID = TeTRSC_e_TrlrPrsntInfo_Not_Detected_DID;
    }
  
    switch(TrailerDetection_Output_DID_mapping.Trailer_known_or_Unknown)
    {
      case(TeTRSC_e_TrlrRecogInfo_Unknown):
      TrailerDetection_Output_DID_mapping.Trailer_known_or_Unknown_DID = TeTRSC_e_TrlrRecogInfo_Unknown_DID;
      break;
      case(TeTRSC_e_TrlrRecogInfo_Known):
      TrailerDetection_Output_DID_mapping.Trailer_known_or_Unknown_DID = TeTRSC_e_TrlrRecogInfo_Known_DID;
      break;
      default : TrailerDetection_Output_DID_mapping.Trailer_known_or_Unknown_DID = TeTRSC_e_TrlrRecogInfo_No_Trailer_Detected_DID;
      break;
    }
  }
  else
  {
      TrailerDetection_Output_DID_mapping.Trailer_Calibration_maneuver_State_DID = CalibrationState_None_DID;
      TrailerDetection_Output_DID_mapping.Trailer_Calibration_Status_DID = TeTRSC_e_TrlrCalInfo_NotCalibrated_DID;
      TrailerDetection_Output_DID_mapping.Trailer_Presence_detection_DID = TeTRSC_e_TrlrPrsntInfo_Not_Detected_DID;
      TrailerDetection_Output_DID_mapping.Trailer_known_or_Unknown_DID = TeTRSC_e_TrlrRecogInfo_No_Trailer_Detected_DID;
  }
  switch(TrailerDetection_Output_DID_mapping.Trailer_Calibration_Fail_Reason)
  {
    case(Camera_Blocked):
    TrailerDetection_Output_DID_mapping.Trailer_Calibration_Fail_Reason_DID = Camera_Blocked_or_low_Light;
    break;
    case(No_Failure):
    TrailerDetection_Output_DID_mapping.Trailer_Calibration_Fail_Reason_DID = No_Failure_DID;
    break;
    default : TrailerDetection_Output_DID_mapping.Trailer_Calibration_Fail_Reason_DID = No_Failure_DID;
    break;
  }

  if((m_jobInput.DLDInput.CamBlockStatus) || (m_jobInput.DLDInput.LowLightStatus))
  {
    TrailerDetection_Output_DID_mapping.trailerDetectionFailReason_DID = DetectionFailInfo_OCCULSION_or_LOWLIGHT_DID;
  }
  else
  {
    switch(TrailerDetection_Output_DID_mapping.trailerDetectionFailReason)
    {
      case(DetectionFailInfo_NONE):
      TrailerDetection_Output_DID_mapping.trailerDetectionFailReason_DID = DetectionFailInfo_NONE_DID;
      break;
      case(DetectionFailInfo_SNA):
      TrailerDetection_Output_DID_mapping.trailerDetectionFailReason_DID = DetectionFailInfo_SNA_DID;
      break;
      case(DetectionFailInfo_OCCULSION):
      TrailerDetection_Output_DID_mapping.trailerDetectionFailReason_DID = DetectionFailInfo_OCCULSION_or_LOWLIGHT_DID;
      break;
      default : TrailerDetection_Output_DID_mapping.trailerDetectionFailReason_DID = DetectionFailInfo_NONE_DID;
      break;
    } 
  }
  if((m_jobInput.DLDInput.CamBlockStatus))
  {
    TrailerDetection_Output_DID_mapping.IeTRSC_e_CamBlockSts = TeTRSC_e_CamBlockSts_CameraBlocked;
  }
  else if((m_jobInput.DLDInput.LowLightStatus))
  {
    TrailerDetection_Output_DID_mapping.IeTRSC_e_CamBlockSts = TeTRSC_e_CamBlockSts_LowLight;
  }
  else
  {
    TrailerDetection_Output_DID_mapping.IeTRSC_e_CamBlockSts = TeTRSC_e_CamBlockSts_CameraClear;
  }

}

void DataProviderTAD2::setTRSC_Inputs_from_TrailerDetection(TRSC_Inputs_from_TrailerDetection_t& TRSC_Inputs_from_TrailerDetection) const
{
  // Send IPC message only if there is difference in current and previous message
  int32_t isNewMessage = memcmp((void*)&TRSC_Inputs_from_TrailerDetection,
		  	  	  	  	  	  	  (void*)&TRSC_Inputs_from_TrailerDetection_local,
								  sizeof(TRSC_Inputs_from_TrailerDetection_t));
  if (isNewMessage != 0)
  {
	  dataProvider_ro.getSigMData_po()->setTRSC_Inputs_from_TrailerDetection_v(TRSC_Inputs_from_TrailerDetection);
	  memcpy((void*)&TRSC_Inputs_from_TrailerDetection_local,
			  (void*)&TRSC_Inputs_from_TrailerDetection,
			  sizeof(TRSC_Inputs_from_TrailerDetection_t));
  }
  return;
}

TAD2::JobTADInput* DataProviderTAD2::get_input()
{
#if !(TAD2_SIGM_TESTING)
  m_jobInput.NVMInput.calibrateCollisionAngle = false;
  m_jobInput.NVMInput.calibrateHitchPoint = false;
  m_jobInput.NVMInput.calibrateNewTrailer = false;
  m_jobInput.NVMInput.ConfigTrailerID = -1;
  m_jobInput.NVMInput.InputTrailerID = -2;
  m_jobInput.NVMInput.trailerLoadedSuccessfully = true;
  m_jobInput.StatemachineInput.MeTRSC_b_TRSCSwitchPressed = true;
  m_jobInput.StatemachineInput.MeTRSC_m_TrailerBeamLen = 2100;
  m_jobInput.StatemachineInput.MeTRSC_deg_JackKnifeAngle = 80.00f;
#endif
  m_jobInput.StatemachineInput.MeTRSC_b_TBLComputationDone = false;
  m_jobInput.StatemachineInput.MeTRSC_b_OTBLReset = false;
  return &m_jobInput;
}

TAD2::RawKinematicData DataProviderTAD2::get_kinematic_data() const
{
  TAD2::RawKinematicData kinematicData;
  memset(&kinematicData, 0, sizeof(TAD2::RawKinematicData));
#if !(TAD2_SIGM_TESTING)
  kinematicData.dx_m = ( float32_t )0;
  kinematicData.dy_m = ( float32_t )0;
  kinematicData.dyaw_rad = ( float32_t )0;
  kinematicData.timestamp_s = ( float32_t )0;
#endif
return kinematicData;
}

TAD2::RawVehicleData DataProviderTAD2::get_Vehicle_data()
{
  TAD2::RawVehicleData vehData;
#if !(TAD2_SIGM_TESTING)
    vehData.speed_kmPh = speed_kmPh_test[m_FrameNumber - 1];
    vehData.steeringWheelAngle_rad = steeringWheelAngle_rad_test[m_FrameNumber - 1];
    vehData.wheelAngle_rad = wheelAngle_rad_test[m_FrameNumber - 1];
    vehData.gear = (TAD2::eVehicleGear)gear_test[0];
    //vehData.yawrate = 0.004200f;
    vehData.timeStamp_s = 0.0f;
  #else
    // todo : Implement SigM calls once they are available
  #endif

    return vehData;
}

void DataProviderTAD2::set_config( tad2config::TADConfigData& i_config )
{
  // i_config.getCanAndVehicleConfigParams().rear;//285 rearBumper2hitch_mm
  i_config.getCanAndVehicleConfigParams().setTime( true ) ;
  i_config.getCanAndVehicleConfigParams().setAngleCW( 0 );
}

void DataProviderTAD2::set_vehicle_params( TAD2::VehicleParameters& vehicleParams )
{
}

TAD2::VehicleParameters DataProviderTAD2::get_vehicle_params()
{
#if (!TAD2_SIGM_TESTING) // Vehicle parameter for F150DS_AH_FE (TestRecord_001.vid)
  vehicleParams.length_mm = 5863.0;//( uint16_t )m_pAppCtrlInfo->m_pVehicleInfo->VehicleLength_mm;
  vehicleParams.width_mm = 2200.0;;//( uint16_t )m_pAppCtrlInfo->m_pVehicleInfo->VehicleWidth_mm;
  vehicleParams.frontOverhang_mm = 954.0;//( uint16_t )m_pAppCtrlInfo->m_pVehicleInfo->FrontOverhang_mm;
  vehicleParams.rearOverhang_mm = 1209.0;//( uint16_t )m_pAppCtrlInfo->m_pVehicleInfo->RearOverhang_mm;
  // wheelBase_mm  = DistanceCoG2FrontAxis_mm + DistanceCoG2RearAxis_mm
  vehicleParams.wheelBase_mm = 3700.0;//( uint16_t )( m_pAppCtrlInfo->m_pVehicleInfo->WheelBase_mm );
  vehicleParams.hitchLength_mm = 1494.0;
#else	//Vehicle parameters for Mule 6
  /*Defualt values for mule 6*/
  vehicleParams.length_mm = 5902.73f;
  vehicleParams.width_mm = 2595.91f;
  vehicleParams.frontOverhang_mm = 993.30f;
  vehicleParams.rearOverhang_mm = 1236.62f;
  vehicleParams.wheelBase_mm = 3672.82f;
  for(int32_t i = 0; i < 1000; i++)
  {
    TAD_Calib_Data = dataProvider_ro.getSigMData_po()->getTRSC_Calibration_data_MPU1_0();
    if (TRUE == TAD_Calib_Data.bValid)
    {
      vehicleParams.length_mm = TAD_Calib_Data.CalData.length_mm;
      vehicleParams.width_mm = TAD_Calib_Data.CalData.width_mm;
      vehicleParams.frontOverhang_mm = TAD_Calib_Data.CalData.frontOverhang_mm;
      vehicleParams.rearOverhang_mm = TAD_Calib_Data.CalData.rearOverhang_mm;
      vehicleParams.wheelBase_mm = TAD_Calib_Data.CalData.wheelBase_mm;
      #if 0
      printf("TRSC_CalibData: %f, %f, %f, %f, %f\n", vehicleParams.length_mm,
             vehicleParams.width_mm,
             vehicleParams.frontOverhang_mm,
             vehicleParams.rearOverhang_mm,
             vehicleParams.wheelBase_mm);
      #endif
      break;       
    }
    /* Sleep for preemption to free CPU*/
    ME_Thread_Sleep_t(30);
  }
#endif
  return vehicleParams;
}
const uint8_t* DataProviderTAD2::get_topview_u8c1() const
{
    return ImgBuffer;
}
//
 void DataProviderTAD2::put_output( const TAD2::JobTADOutput& i_jobTADOutput )
{
	m_jobOutput = i_jobTADOutput;
}

#if DUMP_REAR_FISHEYE_ALGO_VIEW
void DataProviderTAD2::dump_Fisheye_rear()
{
    static container::OVL3DData *v_ovl3d_po = getOVL3DData_po();
    static bsp::TIOVXHost &v_tiovx_ro = getTIOVX_ro();

    uint32_t v_width_u32;
    uint32_t v_height_u32;

    static algo_view_t *v_algoView_pv;
    static Condvar_s v_condvar_s;
    static bsp::VideoInputBufferDesc2_t v_bufferDesc_t;
    static texture_data_t *v_textures_apo[3];

    static uint8 m_InitOnce = 1;

    if (m_InitOnce)
    {
        // create AlgoView descriptor
    	if ((v_algoView_pv = v_ovl3d_po->algoViewCreate_po((char*)"algo-fisheye-rgb", ALGO_VIEW_RGB_PLANAR_RAW, v_width_u32, v_height_u32)) == NULL)
        {
            ME_Debugger_F_Printf_v("failed to create algo-view\n");
        }
        else if (v_tiovx_ro.allocVideoBuffer_b(v_width_u32, v_height_u32, SCREEN_FORMAT_BYTE, 3, v_bufferDesc_t) == false)
        {
            ME_Debugger_F_Printf_v("failed to allocate buffer\n");
        }
        else if (v_ovl3d_po->algoViewBuffersPrepare_b(v_bufferDesc_t, v_textures_apo) == false)
        {
            ME_Debugger_F_Printf_v("failed to prepare buffers\n");
        }

        memset(&v_condvar_s, 0, sizeof(v_condvar_s));
        ME_Condvar_Init_t(&v_condvar_s);

        m_InitOnce = 0;
    }
    else if(v_algoView_pv != NULL)
    {
        // set first frame number
        static uint32_t v_frameNum_u32 = 0;

        AlgoViewJob_s v_job_t;

        // wait for next input frame (use every frame nominally)
        v_ovl3d_po->waitFrame_b(v_frameNum_u32);

        v_job_t.algoView_po = v_algoView_pv;
        v_job_t.condvar_po = &v_condvar_s;
        v_job_t.output_apo = v_textures_apo;
        v_job_t.sync_ppo = NULL;

        ME_Mutex_Lock_t(&v_condvar_s.MEMutex_po);

        uint32_t t0 = __get_time_usec();

        if (v_ovl3d_po->algoViewJobSubmit_b(&v_job_t) == true)
        {
            // wait for job completion (explicitly)
            ME_Condvar_Wait_t(&v_condvar_s);
        }

        uint32_t t1 = __get_time_usec();

        ME_Mutex_UnLock_t(&v_condvar_s.MEMutex_po);
        uint32_t* v_data_pu32[3] = {
            static_cast<uint32_t*>(v_bufferDesc_t.buffers_apv[0]),
            static_cast<uint32_t*>(v_bufferDesc_t.buffers_apv[1]),
            static_cast<uint32_t*>(v_bufferDesc_t.buffers_apv[2]),
        };

        (void)memcpy((void*)RawBuffer, (void*)v_data_pu32[0], ImageSize);
        (void)memcpy((RawBuffer + ImageSize), v_data_pu32[1], ImageSize);
        (void)memcpy((RawBuffer + (ImageSize *2)), v_data_pu32[2], ImageSize);
		char buffer[100];
		FILE* fp;
		sprintf( buffer, "/ti_sd/rear-raw_%d.bin", m_FrameNumber);
		fp = fopen( buffer, "wb" );
		fwrite(RawBuffer, 1, ImageSize * 3, fp);
		fclose(fp);
    }
}
#endif
//
int DataProviderTAD2::read_topview_gray()
{
#if DUMP_REAR_FISHEYE_ALGO_VIEW
	if (!(m_FrameNumber % 500))
	{
		dump_Fisheye_rear();
	}
#endif
#if (TAD2_SIGM_TESTING)
  static container::OVL3DData *v_ovl3d_po = getOVL3DData_po();
  static bsp::TIOVXHost &v_tiovx_ro = getTIOVX_ro();

  uint32_t v_width_u32;
  uint32_t v_height_u32;

  static algo_view_t *v_algoView_pv;
  static Condvar_s v_condvar_s;
  static bsp::VideoInputBufferDesc2_t v_bufferDesc_t;
  static texture_data_t *v_textures_apo[3];

#if PRINT_ALGO_VIEW_DEBUG_DATA
  sensor::CameraParams& v_SensorCameraParam = dataProvider_ro.getCamMData_po()->getCamera_ro(variants::Camera_t::e_CameraRear).getCameraParams_ro();
  mecl::model::Pinhole<float32_t>::Config_s v_PinholeCfg_s;
  v_SensorCameraParam.getPinholeDesignData_b(v_PinholeCfg_s);
  mecl::model::Pinhole<float32_t> v_Pinhole_o(v_PinholeCfg_s);

  static float32_t previousWheelBase_mm = 0;
  if (previousWheelBase_mm != vehicleParams.wheelBase_mm)
  {
    printf("TAD2: Wheelbase %f\n", vehicleParams.wheelBase_mm);
    previousWheelBase_mm = vehicleParams.wheelBase_mm;
  }
#endif

  static uint8 m_InitOnce = 1;

  if (m_InitOnce)
  {
    bool_t bAlgoCreateFail = false;
    
#if PRINT_ALGO_VIEW_DEBUG_DATA
    char old_var_data[5] ={0};
    uint8_t v_VarId_u8;
    bool_t result_b = true;
    result_b = ME_VariantHelper_GetVariantID_b(&var_id);
    ME_Debugger_F_Printf_v("TAD2: extrinsic_s.pos_x.cVal_ax: %f, %f, %f\n",v_PinholeCfg_s.extrinsic_s.pos_x.cVal_ax[0],
        v_PinholeCfg_s.extrinsic_s.pos_x.cVal_ax[1],
        v_PinholeCfg_s.extrinsic_s.pos_x.cVal_ax[2]);
    ME_Debugger_F_Printf_v("TAD2: Wheelbase at algo creation time %f\n", TAD_Calib_Data.CalData.wheelBase_mm);
#endif
    if ((v_algoView_pv = v_ovl3d_po->algoViewCreate_po((char *)"mule6-algo-rear-tv-y", ALGO_VIEW_GRAYSCALE, v_width_u32, v_height_u32)) == NULL)
    {
      bAlgoCreateFail = true;
    }

    if (bAlgoCreateFail)
    {
      ME_Debugger_F_Printf_v("failed to create algo-view\n");
    }
    else if (v_tiovx_ro.allocVideoBuffer_b(v_width_u32, v_height_u32, SCREEN_FORMAT_BYTE, 1, v_bufferDesc_t) == false)
    {
      ME_Debugger_F_Printf_v("failed to allocate buffer\n");
    }
    else if (v_ovl3d_po->algoViewBuffersPrepare_b(v_bufferDesc_t, v_textures_apo) == false)
    {
      ME_Debugger_F_Printf_v("failed to prepare buffers\n");
    }

    memset(&v_condvar_s, 0, sizeof(v_condvar_s));
    ME_Condvar_Init_t(&v_condvar_s);

    m_InitOnce = 0;
  }
  else if(v_algoView_pv != NULL)
  {
	  // set first frame number
	  static uint32_t v_frameNum_u32 = 0;
	  static uint32_t last_v_frameNum_u32 = 0;

	  v_ovl3d_po->updateFrame_v(v_frameNum_u32);
	  if(last_v_frameNum_u32 < v_frameNum_u32)
	  {
	    last_v_frameNum_u32 = v_frameNum_u32;
	    AlgoViewJob_s v_job_t;

	    // wait for next input frame (use every frame nominally)
	    // v_ovl3d_po->waitFrame_b(v_frameNum_u32);

	    v_job_t.algoView_po = v_algoView_pv;
	    v_job_t.condvar_po = &v_condvar_s;
	    v_job_t.output_apo = v_textures_apo;
	    v_job_t.sync_ppo = NULL;

	    ME_Mutex_Lock_t(&v_condvar_s.MEMutex_po);
	    if (v_ovl3d_po->algoViewJobSubmit_b(&v_job_t) == true)
	    {
	      // wait for job completion (explicitly)
	      ME_Condvar_Wait_t(&v_condvar_s);
	    }
	    ME_Mutex_UnLock_t(&v_condvar_s.MEMutex_po);

	    uint32_t *v_data_pu32 = static_cast<uint32_t *>(v_bufferDesc_t.buffers_apv[0]);
	    (void)memcpy(ImgBuffer, v_data_pu32, ImageSize_u32);
	    FlipHorizontalPlanarW640H640(ImgBuffer, 640, 400);
	  }
  }


#else
  char buffer[100];
  FILE* fp;
  sprintf( buffer, "/ti_sd/images/%d.bin", m_FrameNumber );
  while (access(buffer, F_OK) != 0)    {     ME_Thread_Sleep_t(10);   }
  fp = fopen( buffer, "rb" );
  if (NULL != fp)
  {
	  fread((void*)ImgBuffer,ImageSize_u32,1,fp);
	  fclose(fp);
	  //printf("Processing %s\n", buffer);
	  // Remove frame if stored on temp folder
	  // if (remove(buffer) == 0)   {   printf("%s file is deleted\n", buffer); }
  }
  else
  {
	  ME_Debugger_F_Printf_v("Unable to read frame %s\n", buffer);
  }
#endif

#if DUMP_ALGO_VIEW
	char buffer[100];
	FILE* fp;
	if (!(m_FrameNumber % 2000))
	{
		sprintf( buffer, "/ti_sd/TAD_algo_view_%d.bin", m_FrameNumber );
		fp = fopen( buffer, "wb" );
		fwrite(ImgBuffer, 1, ImageSize_u32, fp);
		fclose(fp);
	}
#endif
#if DUMP_ALGO_VIEW_FOR_STATE7
	char buffer3[100];
	FILE* fp1;
	static int count = 0;
	if ((7 == TADState) && (count < 10))
	{
		sprintf( buffer3, "/ti_sd/TAD_algo_view_%d.bin", m_FrameNumber );
		fp1 = fopen( buffer3, "wb" );
		fwrite(ImgBuffer, 1, ImageSize_u32, fp1);
		fclose(fp1);
		count++;
	}
#endif

#if DUMP_FISHEYE_1920x1280
	char buffer1[100];
	char buffer2[100];
	static bool_t bDumpRawImage = true;
	if (50 == m_FrameNumber)
	{
		if (bDumpRawImage)
		{
			for (int i = 34; i <= 34; i++)
			{
				sprintf( buffer1, "/dev/screen/buffers/buf-%d/buf-%d.bmp", i, i );
				fsdata::fsdata_read_data(buffer1, (char*)&imageBuffer, rawImageSize);
				sprintf( buffer2, "/ti_sd/buf-%d.bmp", i );
				fsdata::fsdata_store_data(buffer2, (char*)&imageBuffer, rawImageSize);
				ME_Debugger_F_Printf_v("Copied %s\n", buffer1);
			}
			bDumpRawImage = false;
		}
	}
#endif

    return 0;
}

#if !(TAD2_SIGM_TESTING)
void DataProviderTAD2::readSanityTestData(TAD2::RawVehicleData &vehData, TAD2::RawKinematicData &KMData)
{
  unsigned int index = m_FrameNumber - 1;
  vehData.speed_kmPh = speed_kmPh_test[index];
  vehData.steeringWheelAngle_rad = steeringWheelAngle_rad_test[index];
  vehData.gear = ( TAD2::eVehicleGear )gear_test[index];
  vehData.wheelAngle_rad = wheelAngle_rad_test[index];
#if 0 // [Pravin] Not used in code?
  vehData.timeStamp_s = timeStamp_s_test[index];
  KMData.dx_m = dx_m_test[index];
  KMData.dy_m = dy_m_test[index];
  KMData.dyaw_rad = dyaw_rad_test[index];
  KMData.timestamp_s = km_timestamp_s_test[index];
#endif
  
  return;
}
#endif

void DataProviderTAD2::FlipHorizontalPlanarW640H640( uint8_t* i_inputImage_pu8, const uint16_t i_inputWidth_u16, const uint16_t i_inputHeight_u16 )
{
  uint8_t v_temp[640];
  uint8_t* v_PxT;
  uint8_t* v_PxB;
  uint16_t v_inputHeightLast_u16 = i_inputHeight_u16 - 1;
  uint32_t v_imgOffset_u32 = ( i_inputWidth_u16 * i_inputHeight_u16 );

  for( uint16_t v_img_row_u32 = 0; v_img_row_u32 < ( i_inputHeight_u16 / 2 ); v_img_row_u32++ )
  {
	  v_PxT = &i_inputImage_pu8[( v_img_row_u32 * ( i_inputWidth_u16 ) )];
	  v_PxB = &i_inputImage_pu8[( ( v_inputHeightLast_u16 - v_img_row_u32 ) * ( i_inputWidth_u16 ) )];
	  memcpy( v_temp, v_PxT, i_inputWidth_u16 );
	  memcpy( v_PxT, v_PxB, i_inputWidth_u16 );
	  memcpy( v_PxB, v_temp, i_inputWidth_u16 );
  }
}

#if TAD2_NVM_ACCESS_ENABLED
void DataProviderTAD2::SaveTrailerFeatures( TAD2::TrailerFeatures& trailerfeatures )
{
	bool_t valid = false;

	for( uint32_t i = 0; i < TrailerID_e::Trailer_MAX; i++ )
	{
		valid = valid || trailerfeatures.TrailerData[i].Is_Valid;
	}

    if( !valid )
    {
        return;
    }

    // --- Write data to file
    uint32_t buf_size = trailerfeatures.GetFeatureStorageSize();
    trailerfeatures.SerializeFeature( trailerFeaturesBuff );
    fsdata::fsdata_store_data(tadCalib, (char*)&trailerFeaturesBuff, buf_size);
#if DUMP_TRSC_CALIB_ON_SD_CARD
    fsdata::fsdata_store_data(tadCalib, (char*)&trailerFeaturesBuff, buf_size);
#endif
}
#if 0
void DataProviderTAD2::SaveTrailerTemplate( TAD2::TrailerCalibration& trailerCalibration, TrailerID_t id )
{
    if( !TemplateIDValid( id ) )
    {
        return;
    }

#if DUMP_TRAILER_IMAGE
        FILE* fp;
        fp = fopen( "/tmp/trailerImage.csv", "a+" );
        //fwrite( (void*)gradMag_crop.getData(), 1, sizeof(uint16_t)*640 * 150, fp );
        for( uint32_t y = 0; y < trailerCalibration.trailerImage.getHeight(); y++ )
		{
			for( uint32_t x = 0; x < trailerCalibration.trailerImage.getWidth(); x++ )
			{
				int val = *trailerCalibration.trailerImage.at( x, y );
				fprintf( fp,"%d,", val);
			}

			fprintf( fp,"\n");
		}
        fclose(fp);
#endif
    // std::string filename = "/fs/calib/" + std::to_string( id );
    // image::Image<uint8_t>& trailerImage = trailerCalibration.trailerImage;
    // --- Save template as .jpg
#ifdef ENABLE_OPENCV

    if( trailerCalibration.trailerImageValid )
    {
        cv::Mat cvTemplate = cv::Mat( trailerImage.getHeight(), trailerImage.getWidth(), CV_8UC3 );
        processing::ImageProcessing::CopyToCV<uint8_t>( trailerImage, cvTemplate );
        //cv::Mat cvTemplate = cv::Mat( cv::Size( trailerImage.width, trailerImage.height ), CV_8UC1, trailerImage.data, trailerImage.step );
        cv::resize( cvTemplate, cvTemplate, cv::Size( trailerImage.getWidth(), trailerImage.getHeight() ) );

        if( trailerCalibration.hitchPointValid )
        {
            cv::Point cvHitch = cv::Point( trailerCalibration.hitchPoint.x, trailerCalibration.hitchPoint.y );
            cv::circle( cvTemplate, cvHitch, 3, cv::Scalar( 0, 0, 255 ), -1 );
        }

        cv::imwrite( filename + ".jpg", cvTemplate );
        cvTemplate.release();
    }

#endif

    char fileName[100];
    sprintf( fileName, "/fs/%d.dat", id);

    // --- Write data to file
    uint32_t buf_size = trailerCalibration.GetStorageSize();
    //uint8_t* buffer = new uint8_t[buf_size];
    trailerCalibration.Serialize( trailerCalibrationBuff );
    fsdata::fsdata_store_data(fileName, (char*)&trailerCalibrationBuff, buf_size);
#if DUMP_TRSC_CALIB_ON_SD_CARD
    fsdata::fsdata_store_data("/ti_sd/%d.dat", (char*)&trailerCalibrationBuff, buf_size);
#endif

    //delete[] buffer;
}
#endif

void DataProviderTAD2::InitJobInput()
{

	//state Mchine
	// m_jobInput.StatemachineInput.MeTRSC_e_TrlrPrsntInfoCAN = TeTRSC_e_TrlrPrsntInfo::TeTRSC_e_TrlrPrsntInfo_Unknown;
			// [Pravin] Commented as IPC API's are available on ECU
    m_jobInput.NVMInput.trailerFeatures = m_loadedFeatures;
    m_jobInput.NVMInput.calibrateNewTrailer = m_config.inputConfigParams.calibrateNewTrailer;
    m_jobInput.NVMInput.calibrateHitchPoint = m_config.inputConfigParams.calibrateHitchPoint;
    m_jobInput.NVMInput.calibrateCollisionAngle = m_config.tadConfigParams.getCollisionAngleDetectionConfigParamsRef().getEnabled();
}

void DataProviderTAD2::InitTrailerTemplate()
{
    m_bTrailerTemplateOutput = false;
    //
    m_curTrailerID = -2;// GetTrailerTemplateID( ); [Pravin] This is intentionally done as confirmed with Sandip S
    m_loadedTrailerID = m_curTrailerID;
    m_jobInput.NVMInput.InputTrailerID = m_loadedTrailerID;

    // --- Load Features
    LoadFeatures();

}

bool DataProviderTAD2::LoadFeatures()
{
	for( uint32_t i = 0; i < TrailerID_e::Trailer_MAX; i++ )
	{
		m_loadedFeatures.TrailerData[i].Is_Valid = false;

		if( m_loadedFeatures.TrailerData[i].trailerTemplate.getData() != NULL )
		{
			m_loadedFeatures.TrailerData[i].trailerTemplate.setData( NULL );
		}
	}

	std::string filename = tadCalib;
	std::ifstream file1;
	file1.open( filename, std::ios::in | std::ios::binary );

	if( file1.fail() )
	{
		return false;
	}

	// --- Get size of file
	file1.seekg( 0, std::ios::end );
	uint32_t buf_size = ( uint32_t )file1.tellg();
	file1.seekg( 0, std::ios::beg );

  fsdata::fsdata_read_data(tadCalib, (char*)&trailerFeaturesBuff, buf_size);
  uint32_t Template_size = TAD2::TrailerFeatures::ReadFeatureTemplateSize( trailerFeaturesBuff );

	if( Template_size != 0 )
	{
		m_loadedFeatures.TrailerData[0].trailerTemplate.setData( trailerTemplate0);
		m_loadedFeatures.TrailerData[1].trailerTemplate.setData( trailerTemplate1);
		m_loadedFeatures.TrailerData[2].trailerTemplate.setData( trailerTemplate2);
		m_loadedFeatures.TrailerData[3].trailerTemplate.setData( trailerTemplate3);
		m_loadedFeatures.TrailerData[4].trailerTemplate.setData( trailerTemplate4);
	}

	m_loadedFeatures.DeserializeFeature( trailerFeaturesBuff );

	// --- Close file and deallocate buffer
	file1.close();
	return true;
}
#endif

bool_t DataProviderTAD2::isTADFeatureAllowedToRun(TeTRSC_e_TrlrPrsntInfo &TrlrPrsntInfo)
{
  bool isAllowed = TRUE;

  getVehicleData();

  if (getTailgateStatus() == TRUE)

  {
    isAllowed &= FALSE;
  }

  // Check Trailer connection history for past trailerDisconnectThresh_u16 and then disable TAD algo
  static uint16_t trailerConnectionHistory_u16 = 0;
  if (TRUE == isAllowed)
  {
    if (TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt == TrlrPrsntInfo)
    {
      trailerConnectionHistory_u16 = trailerDisconnectThresh_u16;
    }
    else
    {
      if (0u == trailerConnectionHistory_u16)
      {
        trailerConnectionHistory_u16 = 1u;
        isAllowed &= FALSE;
      }
      trailerConnectionHistory_u16--;
    }
  }


  if (TRUE == isAllowed)
  {
    FID_STRUCT_QM v_FID_struct_QM = dataProvider_ro.getSigMData_po()->getFID_STRUCT_QM();
    if (1u == v_FID_struct_QM.m_QM_FID_TRSC_DLD_DISABLED) 
    {
      isAllowed &= FALSE;
    }
  }

  /* Check for SC */
  if (TRUE == isAllowed)
  {
    TbSVS_e_SVSCalibSMToAlgoCamCalib_t i_SMToAlgo = dataProvider_ro.getCalSmMData_po()->getSVSCalibSMToAlgoCamCalib();
    if (TRUE == i_SMToAlgo.AlgoCntrlData_t.data[SC_ALGO_ACTIVE_BYTE]) {
      isAllowed &= FALSE;
    }
    /* Check for EOL */
    if (TRUE == i_SMToAlgo.AlgoCntrlData_t.data[EOL_ALGO_ACTIVE_BYTE]) {
      isAllowed &= FALSE;
    }
  }

	/* Check for APA Parking */
  if (TRUE == isAllowed)
  {
    TbAP_DriveAssistStatOut_t i_apData = dataProvider_ro.getSigMData_po()->getTbAP_DriveAssistStatOut();
    eAutoParkingState_t eAutoParkingState = (eAutoParkingState_t)i_apData.IeAP_e_AlgoState;
    if((eAutoParkingState_E_PW_APS_SCANNING == eAutoParkingState) ||
       (eAutoParkingState_E_PW_APS_PARKINGIN == eAutoParkingState) ||
       (eAutoParkingState_E_PW_APS_PARKINGOUT == eAutoParkingState))
    {
      isAllowed &= FALSE;
    }
  }

  /*Disable TAD2 according to proxy*/
  if (TRUE == isAllowed)
  {
    if (0u == v_Proxy_st.PRX_TRSCPresence_b)
    {
      isAllowed &= FALSE;
    }
  }

  /* Check for THA */
  bool_t m_THADetEnabled = dataProvider_ro.getTHAData_po()->get_THA_SM_status();
  if(m_THADetEnabled)
  {
    isAllowed &= FALSE;
  }
  
  if (FALSE == isAllowed)
  {
    trailerConnectionHistory_u16 = 0u;
  }

  return isAllowed;
}

TeTRSC_e_TrailerCalibMemClearResponse_t DataProviderTAD2::calibrationMemClear()
{
	static TeTRSC_e_TrailerCalibMemClearResponse_t memClearReponse = {TeTRSC_e_TrailerCalibMemClearResponse_Dummy, false};
	TRSC_CalibrationClear_t TRSC_CalibrationClear_local;
	TRSC_CalibrationClear_local = dataProvider_ro.getSigMData_po()->getTRSC_CalibrationClear_t();

	if (TRSC_CalibrationClear_local.TRSC_Calib_Clear_Req == 1)
	{
		char buffer[50];
		sprintf( buffer, tadCalib);
		if (access(buffer, F_OK) == 0)
		{
			if (0 == remove(buffer))
			{
			  memClearReponse.CalibMemClearResponse = TeTRSC_e_Completed;
			}
			else
			{
				memClearReponse.CalibMemClearResponse = TeTRSC_e_Abort;
			}
			memClearReponse.bValid = true;
		}
	}
  else
  {
    memClearReponse.bValid = false;
  }

	return memClearReponse;
}

void DataProviderTAD2::setTADRuntime(uint32_t u_Runtime_u32)
{
  dataProvider_ro.getTAD2Data_po()->setTADRuntime(u_Runtime_u32);
}

void DataProviderTAD2::setTADThreadRuntime(uint32_t u_Runtime_u32)
{
  dataProvider_ro.getTAD2Data_po()->setTADThreadRuntime(u_Runtime_u32);
}

PerformanceStatsEnable_t DataProviderTAD2::get_PerformanceStatsEnable(void)
{
	return dataProvider_ro.getSigMData_po()->getPerformanceStatsEnable_t();
}
} // namespace TAD2
