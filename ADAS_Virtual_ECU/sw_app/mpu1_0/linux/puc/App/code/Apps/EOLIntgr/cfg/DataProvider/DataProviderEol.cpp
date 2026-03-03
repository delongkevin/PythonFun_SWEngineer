//--------------------------------------------------------------------------
/// @file DataProviderEol.cpp
/// @brief Contains
///
/// DataProvider is an interface between Eol module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Saravan (saravanaperumal.ponnambalam@magna.com)
///
//  --------------------------------------------------------------------------


#include "DataProviderEol.h"

#define EOL_IMAGE_DUMP_RAW 0
//TODO: A lot of this code is identical between DataProviderOc and DataProviderEol. 
//A common base class should be introduced.


namespace eol
{

DataProviderEol::DataProviderEol(container::IDataProvider& b_DataInProvider_ro)
: IDataProviderEol(), dataProvider_ro(b_DataInProvider_ro), tiovxConsumer()
{
}

DataProviderEol::~DataProviderEol()
{
  // nothing to do here
}

void DataProviderEol::putEolOutput(aParaMgr_S_Calibration_t& i_CaliVCalib,
    ME_Hydra3defs_E_EOLAlgoState_t i_AlgoState, ME_Hydra3defs_E_CameraID_t m_CurrCamID)
{
  /* DD-ID: {E84050F0-B52F-4709-9634-A37AF89CBABB}*/
if (i_AlgoState == ME_Hydra3defs_E_EOLAlgoState_t::e_EOLFinished)
{
  m_EOLStatus.deltaPitch_f32 = i_CaliVCalib.camPitch_f32 - mecl::math::toDegrees_x(design_ang.camPitch_f32);
  m_EOLStatus.deltaYaw_f32 = i_CaliVCalib.camYaw_f32 - mecl::math::toDegrees_x(design_ang.camYaw_f32);

  ME_Debugger_F_Printf_v("camera ID = %d DegDesRoll: %f\n",m_CurrCamID, mecl::math::toDegrees_x(design_ang.camRoll_f32));
  ME_Debugger_F_Printf_v("camera ID = %d icalibRoll: %f\n",m_CurrCamID, i_CaliVCalib.camRoll_f32);

  if( (180.0F  < (i_CaliVCalib.camRoll_f32 - mecl::math::toDegrees_x(design_ang.camRoll_f32)))  ||
	  (-180.0F > (i_CaliVCalib.camRoll_f32 - mecl::math::toDegrees_x(design_ang.camRoll_f32))))
  {
	  m_EOLStatus.deltaRoll_f32 = i_CaliVCalib.camRoll_f32 + mecl::math::toDegrees_x(design_ang.camRoll_f32);
  }
  else
  {
    m_EOLStatus.deltaRoll_f32 = i_CaliVCalib.camRoll_f32 - mecl::math::toDegrees_x(design_ang.camRoll_f32);
  }

  m_EOLStatus.deltaX_f32 = i_CaliVCalib.camX_f32 - design_ang.camX_f32;
  m_EOLStatus.deltaY_f32 = i_CaliVCalib.camY_f32 -design_ang.camY_f32;
  m_EOLStatus.deltaZ_f32 = i_CaliVCalib.camZ_f32 - design_ang.camZ_f32;
}
else
{
  m_EOLStatus.deltaPitch_f32 = i_CaliVCalib.camPitch_f32;
  m_EOLStatus.deltaYaw_f32 = i_CaliVCalib.camYaw_f32;
  m_EOLStatus.deltaRoll_f32 = i_CaliVCalib.camRoll_f32;

  m_EOLStatus.deltaX_f32 = i_CaliVCalib.camX_f32;
  m_EOLStatus.deltaY_f32 = i_CaliVCalib.camY_f32;
  m_EOLStatus.deltaZ_f32 = i_CaliVCalib.camZ_f32;
}
#if 0//EOL_PARAMS_DEBUGGING
if(i_AlgoState == ME_Hydra3defs_E_EOLAlgoState_t::e_EOLFinished)
{
  ME_Debugger_F_Printf_v("putEolOutput: Camid: %d, ErrorCode: %d, Pitch: %f, Yaw: %f, Roll: %f, X: %f, Y: %f, Z: %f\n",
      camID_e,
      i_CaliVCalib.errorState_s.camState_s.status_u8,
      m_EOLStatus.deltaPitch_f32,
      m_EOLStatus.deltaYaw_f32,
      m_EOLStatus.deltaRoll_f32,
      m_EOLStatus.deltaX_f32,
      m_EOLStatus.deltaY_f32,
      m_EOLStatus.deltaZ_f32);
}
#endif

  switch(i_CaliVCalib.errorState_s.camState_s.status_u8)
  {
  case e_InProcess:
    m_EOLStatus.errorCode_e = e_EOL_CALIBRATION_IN_PROCESS;
    break;
  case e_Success:
    m_EOLStatus.errorCode_e =   e_EOL_CALIBRATION_SUCCESS;
    break;
  case e_MissingSoftware:
    m_EOLStatus.errorCode_e = e_EOL_MISSING_SOFTWARE;
    break;
  case e_PreconditionVrange:
    m_EOLStatus.errorCode_e = e_EOL_PRECONDITIONS_NOT_CORRECT_VRANGE;
    break;
  case e_PreconditionNumCameras:
    m_EOLStatus.errorCode_e = e_EOL_PRECONDITION_NOT_CORRECT_NUMCAMERAS;
    break;
  case e_MissingInternalLink:
    m_EOLStatus.errorCode_e =   e_EOL_MISSING_INTERNAL_LINK;
    break;
  case e_VariantCoding:
    m_EOLStatus.errorCode_e = e_EOL_VARIANT_CODING_ISSUE;
    break;
  case e_TargetNotFoundInit:
    m_EOLStatus.errorCode_e = e_EOL_TARGET_NOT_FOUND_INIT;
    break;
  case e_TargetNotFoundLeft:
    m_EOLStatus.errorCode_e = e_EOL_TARGET_NOT_FOUND_LEFT;
    break;
  case e_TargetNotFoundRight:
    m_EOLStatus.errorCode_e = e_EOL_TARGET_NOT_FOUND_RIGHT;
    break;
  case e_TargetIdentErrorLeft:
    m_EOLStatus.errorCode_e = e_EOL_TARGET_IDENTIFICATION_ERROR_LEFT;
    break;
  case e_TargetIdentErrorRight:
    m_EOLStatus.errorCode_e = e_EOL_TARGET_IDENTIFICATION_ERROR_RIGHT;
    break;
  case e_ExceededQualityLimit:
    m_EOLStatus.errorCode_e = e_EOL_RESULT_EXCEED_QUALITY_LIMIT;
    break;
  case e_NotCalibrated:
    m_EOLStatus.errorCode_e = e_EOL_NOT_CALIBRATED;
    break;
  case e_Aborted:
    m_EOLStatus.errorCode_e = e_EOL_ABORTED;
    break;
  case e_HomographyEstimationError:
    m_EOLStatus.errorCode_e = e_EOL_HMOGRAPHY_ESTIMATION_ERROR;
    break;
  case e_PreconditionVelocity:
    m_EOLStatus.errorCode_e = e_EOL_PRECONDITION_NOT_CORRECT_VELOCITY;
    break;
  case e_PreconditionDoors:
    m_EOLStatus.errorCode_e = e_EOL_PRECONDITION_NOT_CORRECT_DOORS;
    break;
  case e_WrongCameraSoftware:
    m_EOLStatus.errorCode_e = e_EOL_WRONG_CAMERA_SOFTWARE;
    break;
  case e_Precondition:
    m_EOLStatus.errorCode_e = e_EOL_PRECONDITION_NOT_CORRECT;
    break;
  default:
    m_EOLStatus.errorCode_e = e_EOL_CALIBRATION_IN_PROCESS;
    break;
  }
  m_EOLStatus.algoState_e = i_AlgoState;
  m_EOLStatus.camID_e = m_CurrCamID;

  m_EOLStatus.targetData_s.TargetInit_s8 = i_CaliVCalib.errorState_s.camState_s.targetInit_s8;
  m_EOLStatus.targetData_s.TargetLimitFront_s8 = i_CaliVCalib.errorState_s.camState_s.targetLimitF_s8;
  m_EOLStatus.targetData_s.TargetLimitRear_s8 = i_CaliVCalib.errorState_s.camState_s.targetLimitR_s8;
  m_EOLStatus.targetData_s.TargetDetectLeftFront_s8 = i_CaliVCalib.errorState_s.camState_s.targetDetectLF_s8;
  m_EOLStatus.targetData_s.TargetDetectLeftRear_s8 = i_CaliVCalib.errorState_s.camState_s.targetDetectLR_s8;
  m_EOLStatus.targetData_s.TargetDetectRightFront_s8 = i_CaliVCalib.errorState_s.camState_s.targetDetectRF_s8;
  m_EOLStatus.targetData_s.TargetDetectRightRear_s8 = i_CaliVCalib.errorState_s.camState_s.targetDetectRR_s8;
  m_EOLStatus.targetData_s.Reserved_s8 = 0;

  dataProvider_ro.getCalSmMData_po()->setSVSCalibAlgoToSMCamCalib_EolStatus ( m_EOLStatus);
}

#if HC_EOL_DATA
  uint8_t m_InputImage[IMAGE_WIDTH*IMAGE_HEIGHT] = {
  #include "EOL/Left.h"
      };
#else
  uint8_t m_InputImage[IMAGE_WIDTH*IMAGE_HEIGHT];
#endif

void DataProviderEol::getCalSMData()
{
  /* DD-ID: {2D78D902-A67D-4aa4-8A4F-AF66EDACBE2C}*/
#if HC_EOL_DATA

  camID_e = eol::e_LeftCamAlgo;
  calibType_e = eol::e_EndOfLineCalibration;
  lTargetSeperation_f32 = 2300.0F/2.0F + 4.5F * 200.0F;
  algoCommand_e = ME_Hydra3defs_E_AlgoCommand_t::AlgoCommand_Start;

#else
  TbSVS_e_SVSCalibSMToAlgoCamCalib_t i_SMToAlgo =
      dataProvider_ro.getCalSmMData_po()->getSVSCalibSMToAlgoCamCalib();

  switch(i_SMToAlgo.AlgoCntrlHeader_t.AlgoID)
  {
    case ME_Hydra3defs_E_AlgoID_e::AlgoID_EOL:
      calibType_e = eol::e_EndOfLineCalibration;
      break;
    default:
      calibType_e = eol::e_NoCalibration;
      break;
  }

  switch(i_SMToAlgo.AlgoCntrlHeader_t.CurrentCamID)
   {
     case ME_Hydra3defs_E_CameraID_e::CamID_Front:
       camID_e = eol::e_FrontCamAlgo;
       break;
     case ME_Hydra3defs_E_CameraID_e::CamID_Left:
       camID_e = eol::e_LeftCamAlgo;
       break;
     case ME_Hydra3defs_E_CameraID_e::CamID_Rear:
       camID_e = eol::e_RearCamAlgo;
       break;
     case ME_Hydra3defs_E_CameraID_e::CamID_Right:
       camID_e = eol::e_RightCamAlgo;
       break;
     default:
       camID_e = eol::e_RearCamAlgo;
       break;
   }

  algoCommand_e =i_SMToAlgo.AlgoCntrlHeader_t.AlgoCommand;
  uint16 targetDistance = 0;
  (void)memcpy(&targetDistance, &i_SMToAlgo.AlgoCntrlData_t.data[0], sizeof(targetDistance));
  lTargetSeperation_f32 = (float32_t)targetDistance/2.0F + 3.5F * 8.5F * 25.4F;

#if EOL_PARAMS_DEBUGGING
  static uint8 v_debugcntr = 0;

  if( (i_SMToAlgo.AlgoCntrlHeader_t.AlgoCommand == ME_Hydra3defs_E_AlgoCommand_t::AlgoCommand_Start) &&
      (calibType_e== eol::e_EndOfLineCalibration) &&
	  (v_debugcntr < 2) )
    {
    ME_Debugger_F_Printf_v("getCalSMData: Camid: %d, TargetDistance: %d, TargetSeperation: %f\n",
        camID_e,
        targetDistance,
        lTargetSeperation_f32);

      if ( (ME_Hydra3defs_E_CameraID_e::CamID_Right == i_SMToAlgo.AlgoCntrlHeader_t.CurrentCamID) ||
           (ME_Hydra3defs_E_CameraID_e::CamID_Rear == i_SMToAlgo.AlgoCntrlHeader_t.CurrentCamID) )
	  {
            v_debugcntr++;
	  }
    }
#endif
#endif
}

/* this is needed, start command comes with camera ID, need it in SIgM */
uint8_t DataProviderEol::getAlgoCommand_u8()
{
  /* DD-ID: {A210BBD9-9EC2-4abb-90A5-A3904D8DF86B}*/
  return algoCommand_e;//dataInProvider_ro.getDataMcu()->algoControl_s.AlgoCommand_u8;
}

uint8_t DataProviderEol::getAlgoType_u8()
{
  /* DD-ID: {2D38CDA9-F3F2-4941-8C12-E07A2B6EE483}*/
  return calibType_e;//dataInProvider_ro.getDataMcu()->algoControl_s.AlgoType_u8;
}

#if 0
/* this is needed, start command comes with camera ID, need it in SIgM */
uint8_t DataProviderEol::getCameraId_u8()
{
  return camID_e;//dataInProvider_ro.getDataMcu()->algoControl_s.MCUCameraID_u8;
}
#endif

ME_Hydra3defs_E_CameraID_t DataProviderEol::getCameraId_MEHydra3()
{
  /* DD-ID: {193CA44F-94D0-4ce2-8429-0A599EF9CBA6}*/
  ME_Hydra3defs_E_CameraID_t camID_MEHydra3;
  switch(camID_e)
  {
  case  eol::E_CameraId_t::e_FrontCamAlgo:
    camID_MEHydra3 = ME_Hydra3defs_E_CameraID_t::CamID_Front;
    break;
  case  eol::E_CameraId_t::e_LeftCamAlgo:
    camID_MEHydra3 = ME_Hydra3defs_E_CameraID_t::CamID_Left;
    break;
  case  eol::E_CameraId_t::e_RearCamAlgo:
    camID_MEHydra3 = ME_Hydra3defs_E_CameraID_t::CamID_Rear;
    break;
  default:
    camID_MEHydra3 = ME_Hydra3defs_E_CameraID_t::CamID_Right;
    break;
  }

  return camID_MEHydra3;
}

variants::Camera_t DataProviderEol::getCameraId_variants()
{
  /* DD-ID: {AB701379-A341-41d1-A052-EFE024DE1B39}*/
  variants::Camera_t camID_variant;
  switch(camID_e)
  {
  case  eol::E_CameraId_t::e_FrontCamAlgo:
    camID_variant = variants::Camera_t::e_CameraFront;
    break;
  case  eol::E_CameraId_t::e_LeftCamAlgo:
    camID_variant = variants::Camera_t::e_CameraLeft;
    break;
  case  eol::E_CameraId_t::e_RearCamAlgo:
    camID_variant = variants::Camera_t::e_CameraRear;
    break;
  default:
    camID_variant = variants::Camera_t::e_CameraRight;
    break;
  }

  return camID_variant;
}

EolInitData_s DataProviderEol::getEolData()
{
  /* DD-ID: {6A18DFB8-FFE2-4614-A3DD-46BE934C2AEF}*/
#if !HC_EOL_DATA
  bsp::VideoInputBufferDesc2_t ro_desc_t;
  bsp::TIOVXHost &v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
  bsp::TIOVXVideoInput &v_videoInput_ro = v_host_ro.getVideoInput_ro();
  uint32_t o_inputBufIdx_u32;
  // wait for input buffers readiness
  bool_t v_result_b = tiovxConsumer.waitSvsVideoBuffer_b(v_videoInput_ro, o_inputBufIdx_u32);
  if(v_result_b){
    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
        "input buf-%u ready\n", o_inputBufIdx_u32);
    variants::Camera_e varcamID_e;
    switch(camID_e)
    {
    case e_FrontCamAlgo:
      varcamID_e = variants::Camera_e::e_CameraFront;
      break;
    case e_LeftCamAlgo:
      varcamID_e = variants::Camera_e::e_CameraLeft;
      break;
    case e_RearCamAlgo:
      varcamID_e = variants::Camera_e::e_CameraRear;
      break;
    case e_RightCamAlgo:
      varcamID_e = variants::Camera_e::e_CameraRight;
      break;
    }

    v_videoInput_ro.getVideoInputBuffer_b( varcamID_e, ro_desc_t);
    memcpy(m_InputImage, ro_desc_t.buffers_apv[o_inputBufIdx_u32], IMAGE_WIDTH*IMAGE_HEIGHT);
  #if EOL_IMAGE_DUMP_RAW
    static char FileName[64] = {0};

    sprintf(FileName, "/ti_sd/varcamID_e_%d.bin", varcamID_e);

    FILE *fptr = fopen(FileName, "w");

    if (NULL != fptr)
    {
      ME_Debugger_F_Printf_v("Dumping EOL Image Cam = %d \n", varcamID_e);
      (void)fwrite(m_InputImage, 1, IMAGE_WIDTH*IMAGE_HEIGHT, fptr);
      fclose(fptr);
      fptr = NULL;
    }
  #endif
  }
#endif

  EolInitData_s m_EolInitData;
  m_EolInitData.c_Image_pu8 = eol::m_InputImage;
  m_EolInitData.calibType_u8 = calibType_e;         //Calibration Types
  m_EolInitData.cameraId_u8 = camID_e;          //camera id
  m_EolInitData.targetLimitF_s8 = targetLimitF_as8[camID_e];
  m_EolInitData.targetInit_s8 = targetInit_as8[camID_e];
  m_EolInitData.targetLimitR_s8 = targetLimitR_as8[camID_e];
  m_EolInitData.targetSeperation_f32 = lTargetSeperation_f32; //For different types of calibration
  m_EolInitData.camera_po = &camera64_o;

  return m_EolInitData;
}

void DataProviderEol::getCameraParameters_v()
{
  /* DD-ID: {8672BB29-4469-444d-A03B-FDCC3D7C0624}*/
#if HC_EOL_DATA
  mecl::model::Camera<float32_t> v_Camera_o;
    /*camera model */
#if 0
    mecl::model::LensRadial<float32_t>::Config_s v_lensCfg_s = {
         { 0.00000E+00f, 1.42015669206004F, -0.113997055790991F, 0.460614878362174F, -0.315489534605087F, 0.0741941244429088F },
         { 0.00000E+00f, 0.713407177128378F, -0.00378655845687185F, -0.0512079151728888F, 0.024582822394419F, -0.00370418935097875F }
      }; // Fisker Berline EEPROM data.
#endif

    mecl::model::LensRadial<float32_t>::Config_s v_lensCfg_s;
    switch(camID_e)
    {
    case eol::e_FrontCamAlgo:
    {
      mecl::model::LensRadial<float32_t>::Config_s v_lensCfgFront_s =
      {
        /* World to Image */
        { 0.0000F, 1.3999999761581F, -0.0344999991357F, 0.3160000145435F, -0.2039999961853F, 0.0454000011086F },
		/* Image to World */
		{ 0.0000F, 0.7210000157356F, -0.0103000001982F, -0.0469999983907F, 0.0230000000447F, -0.0035000001080F },

		/* elevationMaxCfg_x*/
        110.0F
      }; //Front camera Fisker Jeep // Brampton Berlin veh 494
      memcpy(&v_lensCfg_s,&v_lensCfgFront_s,sizeof(mecl::model::LensRadial<float32_t>::Config_s));
      break;
    }
    case eol::e_LeftCamAlgo:
    {
      mecl::model::LensRadial<float32_t>::Config_s v_lensCfgLeft_s =
      {
        /* World to Image */
    	{ 0.0000F, 1.3999999761581F, -0.0344999991357F, 0.3160000145435F, -0.2039999961853F, 0.0454000011086F },
        /* Image to World */
        { 0.0000F, 0.7210000157356F, -0.0103000001982F, -0.0469999983907F, 0.0230000000447F, -0.0035000001080F },
		/* elevationMaxCfg_x*/
		110.0F
      }; //Left camera Fisker Jeep // Brampton Berlin veh 494
      memcpy(&v_lensCfg_s,&v_lensCfgLeft_s,sizeof(mecl::model::LensRadial<float32_t>::Config_s));
      break;
    }
    case eol::e_RearCamAlgo:
    {
      mecl::model::LensRadial<float32_t>::Config_s v_lensCfgRear_s =
      {
        /* World to Image */
        { 0.0000F, 1.3999999761581F, -0.0344999991357F, 0.3160000145435F, -0.2039999961853F, 0.0454000011086F },
    	/* Image to World */
    	{ 0.0000F, 0.7210000157356F, -0.0103000001982F, -0.0469999983907F, 0.0230000000447F, -0.0035000001080F },
        /* elevationMaxCfg_x*/
    	110.0F
      }; //Rear camera Fisker Bramton Jeep // veh 494 Berlin
      memcpy(&v_lensCfg_s,&v_lensCfgRear_s,sizeof(mecl::model::LensRadial<float32_t>::Config_s));
      break;
    }
    case eol::e_RightCamAlgo:
    {
      mecl::model::LensRadial<float32_t>::Config_s v_lensCfgRight_s =
      {
        /* World to Image */
        { 0.0000F, 1.3999999761581F, -0.0344999991357F, 0.3160000145435F, -0.2039999961853F, 0.0454000011086F },
        /* Image to World */
        { 0.0000F, 0.7210000157356F, -0.0103000001982F, -0.0469999983907F, 0.0230000000447F, -0.0035000001080F },
        /* elevationMaxCfg_x*/
        110.0F
      }; //Right camera  Fisker Bramton Jeep // veh 494 Berlin
      memcpy(&v_lensCfg_s,&v_lensCfgRight_s,sizeof(mecl::model::LensRadial<float32_t>::Config_s));
      break;
    }
   }

    // Instantiate lens object
    mecl::model::LensRadial<float32_t> v_Lens(v_lensCfg_s);

    // STEP 1 : Setup common properties
    // Principal point in pixels
    #if USE_DESIGN_VALUES
      mecl::core::Point2D<float32_t>::Config_s v_PppPxCfg_s = { (IMAGE_WIDTH-1)/2.0f, (IMAGE_HEIGHT-1)/2.0f };//1920x1280px
    #else
      mecl::core::Point2D<float32_t>::Config_s v_PppPxCfg_s;
      switch(camID_e)
      {
        case eol::e_FrontCamAlgo:
          v_PppPxCfg_s.cVal_ax[0] = 960.0f; //Stellantis DT Laramie 5 Variant 8
          v_PppPxCfg_s.cVal_ax[1] = 640.0f; //Stellantis DT Laramie 5 Variant 8
        break;
        case eol::e_LeftCamAlgo:
          v_PppPxCfg_s.cVal_ax[0] = 960.0f;//Stellantis DT Laramie 5 Variant 8
          v_PppPxCfg_s.cVal_ax[1] = 640.0f;//Stellantis DT Laramie 5 Variant 8
        break;
        case eol::e_RearCamAlgo:
          v_PppPxCfg_s.cVal_ax[0] = 960.0f;//Stellantis DT Laramie 5 Variant 8
          v_PppPxCfg_s.cVal_ax[1] = 640.0f;//Stellantis DT Laramie 5 Variant 8
        break;
        case eol::e_RightCamAlgo:
          v_PppPxCfg_s.cVal_ax[0] = 960.0f; //Stellantis DT Laramie 5 Variant 8
          v_PppPxCfg_s.cVal_ax[1] = 640.0f; //Stellantis DT Laramie 5 Variant 8
        break;
      }
    #endif

    // Pixel size in mm/pixel
    mecl::core::Point2D<float32_t>::Config_s v_PszPxCfg_s = { 0.003f, 0.003f };

    // Define configuration for common sensor
    mecl::model::Sensor<float32_t>::Config_s v_sensorCfg_s = { v_PppPxCfg_s, v_PszPxCfg_s, mecl::model::e_UpperLeft, {0.0F, 0.0F}, {(float)IMAGE_WIDTH-1, (float)IMAGE_HEIGHT-1} };
    mecl::model::Sensor<float32_t> v_Sensor(v_sensorCfg_s);

    // Configure camera intrinsics
    mecl::model::Pinhole<float32_t>::Intrinsic_s v_Intrinsic_s = {
      1.0f, 1.0f, {0.0f, 0.0f}   // Values for K-matrix (focal length in x and y and principal point in camera coordinates)
    };

    // STEP 2: Positions (Examples utilizes Ford P558 Variant WB 142 SRW)
    // Location of camera center point
    // Positions originate from Ford EEPROM data as of 20.04.2015 (v1.13 in MKS)
    /*
      Parameter                     FRONT CAM  LEFT CAM  REAR CAM  RIGHT CAM
        Camera ME x position         -893.18   896.58    3848.63   896.58
        Camera ME y position            0.00   -1035.45  0.00      1035.45
        Camera ME z position          626.14    1134.48   640.20    1134.48
        Camera pitch rotation angle   65.35     56.50     63.86     56.50
        Camera yaw rotation angle     0.00      -0.07     0.00      0.07
        Camera roll rotation angle    0.00       0.10     0.00     -0.10
    */
                                                            /* X                  Y                    Z */
    mecl::core::Point3D<float32_t>::Config_s v_FrontCfg_s = {-983.0800170898438f, 0.0f,                1000.5399780273438f};
    mecl::core::Point3D<float32_t>::Config_s v_LeftCfg_s  = {829.1199951171875f, -1010.7299804687500f, 1328.1400146484375f};
    mecl::core::Point3D<float32_t>::Config_s v_RearCfg_s  = {4880.9501953125000f, 0.0f,                1312.4300537109375f};
    mecl::core::Point3D<float32_t>::Config_s v_RightCfg_s = {829.1199951171875f,  1010.7299804687500f, 1328.1400146484375f};

    // STEP 3: Setup mounting angles
    // Euler angles with respect to mounting position
                                                                                                                 /* Pitch    yaw   roll */
    mecl::core::RotationMatrix<float32_t>::EulerAngles_s v_FrontEulerAngles_s = {mecl::math::toRadians_x<float32_t>(60.8199996948242f), 0.0F, mecl::math::toRadians_x<float32_t>(0.0F)};
    mecl::core::RotationMatrix<float32_t>::EulerAngles_s v_LeftEulerAngles_s  = {mecl::math::toRadians_x<float32_t>(40.4599990844727f), mecl::math::toRadians_x<float32_t>(22.0599994659424f), mecl::math::toRadians_x<float32_t>(18.2399997711182f)};
    mecl::core::RotationMatrix<float32_t>::EulerAngles_s v_RearEulerAngles_s  = {mecl::math::toRadians_x<float32_t>(50.7700004577637f), 0.0f,mecl::math::toRadians_x<float32_t>(0.0F)};
    mecl::core::RotationMatrix<float32_t>::EulerAngles_s v_RightEulerAngles_s = {mecl::math::toRadians_x<float32_t>(40.4599990844727f), mecl::math::toRadians_x<float32_t>(-22.0599994659424f), mecl::math::toRadians_x<float32_t>(161.7599945068359f)};

    //temp
    mecl::core::Point3D<float32_t>::Config_s v_TmpCfg_s;
    mecl::core::RotationMatrix<float32_t>::EulerAngles_s v_TmpEulerAngles_s;
    switch(camID_e)
    {
    case eol::e_FrontCamAlgo:
      memcpy(&v_TmpCfg_s,&v_FrontCfg_s,sizeof( mecl::core::Point3D<float32_t>::Config_s));
      memcpy(&v_TmpEulerAngles_s,&v_FrontEulerAngles_s,sizeof( mecl::core::RotationMatrix<float32_t>::EulerAngles_s));
      break;
    case eol::e_LeftCamAlgo:
      memcpy(&v_TmpCfg_s,&v_LeftCfg_s,sizeof( mecl::core::Point3D<float32_t>::Config_s));
      memcpy(&v_TmpEulerAngles_s,&v_LeftEulerAngles_s,sizeof( mecl::core::RotationMatrix<float32_t>::EulerAngles_s));
      break;
    case eol::e_RearCamAlgo:
      memcpy(&v_TmpCfg_s,&v_RearCfg_s,sizeof( mecl::core::Point3D<float32_t>::Config_s));
      memcpy(&v_TmpEulerAngles_s,&v_RearEulerAngles_s,sizeof( mecl::core::RotationMatrix<float32_t>::EulerAngles_s));
      break;
    case eol::e_RightCamAlgo:
      memcpy(&v_TmpCfg_s,&v_RightCfg_s,sizeof( mecl::core::Point3D<float32_t>::Config_s));
      memcpy(&v_TmpEulerAngles_s,&v_RightEulerAngles_s,sizeof( mecl::core::RotationMatrix<float32_t>::EulerAngles_s));
      break;
    }

    // STEP 4: Define camera extrinsics
    // Define camera extrinsics
    mecl::model::Pinhole<float32_t>::Extrinsic_s v_FrontExtrinsic_s = { v_FrontCfg_s, v_FrontEulerAngles_s, mecl::model::e_PreRoll90, mecl::model::e_WorldToCamera};
    mecl::model::Pinhole<float32_t>::Extrinsic_s v_LeftExtrinsic_s  = { v_LeftCfg_s, v_LeftEulerAngles_s, mecl::model::e_PreRoll180, mecl::model::e_WorldToCamera};
    mecl::model::Pinhole<float32_t>::Extrinsic_s v_RearExtrinsic_s  = { v_RearCfg_s, v_RearEulerAngles_s, mecl::model::e_PreRoll270, mecl::model::e_WorldToCamera};
    mecl::model::Pinhole<float32_t>::Extrinsic_s v_RightExtrinsic_s = { v_RightCfg_s, v_RightEulerAngles_s, mecl::model::e_PreRoll0, mecl::model::e_WorldToCamera};

    // STEP 5: Pinhole model setup
    // Pinhole configuration
    mecl::model::Pinhole<float32_t>::Config_s v_FrontPinholeCfg_s = { v_FrontExtrinsic_s, v_Intrinsic_s };
    mecl::model::Pinhole<float32_t>::Config_s v_LeftPinholeCfg_s  = { v_LeftExtrinsic_s, v_Intrinsic_s };
    mecl::model::Pinhole<float32_t>::Config_s v_RearPinholeCfg_s  = { v_RearExtrinsic_s, v_Intrinsic_s };
    mecl::model::Pinhole<float32_t>::Config_s v_RightPinholeCfg_s = { v_RightExtrinsic_s, v_Intrinsic_s };

    // Instantiate pinhole object based on configuration
    mecl::model::Pinhole<float32_t> v_FrontPinhole_o(v_FrontPinholeCfg_s);
    mecl::model::Pinhole<float32_t> v_LeftPinhole_o(v_LeftPinholeCfg_s);
    mecl::model::Pinhole<float32_t> v_RearPinhole_o(v_RearPinholeCfg_s);
    mecl::model::Pinhole<float32_t> v_RightPinhole_o(v_RightPinholeCfg_s);

    // STEP 6: Setup camera model for each camera position.
    // Instantiate camera object based on pinhole and lens objects.
    mecl::model::Camera<float32_t> v_FrontCamera_o(v_FrontPinhole_o, v_Lens, v_Sensor);
    mecl::model::Camera<float32_t> v_LeftCamera_o(v_LeftPinhole_o, v_Lens, v_Sensor);
    mecl::model::Camera<float32_t> v_RearCamera_o(v_RearPinhole_o, v_Lens, v_Sensor);
    mecl::model::Camera<float32_t> v_RightCamera_o(v_RightPinhole_o, v_Lens, v_Sensor);

    sint8_t v_TargetIndex_s8;
    float32_t v_OffsetX_f32;
    float32_t v_PatternX_f32 = TARGET_SIZE*3.0F*25.4F;
    v_OffsetX_f32 = v_PatternX_f32 * 0.5F;
    //Couldn't be fixed with eol, related to mecl
    //PRQA S 3077 1
    mecl::model::Pinhole<float32_t> &v_PinHole = dynamic_cast<mecl::model::Pinhole<float32_t>&>(v_RearCamera_o.getImager_rx());
    mecl::core::Point3D<float32_t> v_T_o = v_PinHole.getTranslationVector_x();
    v_T_o = v_PinHole.getCameraCenter_x(v_T_o);
    v_TargetIndex_s8 = static_cast<sint8_t>((v_T_o(0) - v_OffsetX_f32)/v_PatternX_f32);
    switch(camID_e)
      {
      case eol::e_FrontCamAlgo:
        targetLimitF_as8[camID_e] = -3;
        targetInit_as8[camID_e] = -2;
        targetLimitR_as8[camID_e] = -2; //For P558. For D544, it should be -2.
        memcpy(&v_Camera_o,&v_FrontCamera_o,sizeof(v_FrontCamera_o));
        break;
      case eol::e_LeftCamAlgo:
        targetLimitF_as8[camID_e] = -1;
        targetInit_as8[camID_e] = 0;
        targetLimitR_as8[camID_e] = 7;
        memcpy(&v_Camera_o,&v_LeftCamera_o,sizeof(v_LeftCamera_o));
        break;
      case eol::e_RearCamAlgo:
        {
        sint8_t rearCamMaxTargetLimitR_s8 = 9;
        targetLimitF_as8[camID_e] = v_TargetIndex_s8 + 0;
        targetInit_as8[camID_e] = v_TargetIndex_s8 + 1;
        if ((v_TargetIndex_s8 + 4) <= rearCamMaxTargetLimitR_s8)
        {
          targetLimitR_as8[camID_e] = v_TargetIndex_s8 + 4;
        }
        else
        {
          targetLimitR_as8[camID_e] = rearCamMaxTargetLimitR_s8;
        }
        memcpy(&v_Camera_o,&v_RearCamera_o,sizeof(v_RearCamera_o));
        break;
        }
      case eol::e_RightCamAlgo:
        targetLimitF_as8[camID_e] = -1;
        targetInit_as8[camID_e] = 0;
        targetLimitR_as8[camID_e] = 7;
        memcpy(&v_Camera_o,&v_RightCamera_o,sizeof(v_RightCamera_o));
        break;
      }
#else

    /* Get the Camera parameters (extrinsic and Intrinsic) from camera manager */
    sensor::CameraParams& v_SensorCameraParam = dataProvider_ro.getCamMData_po()->getCamera_ro(getCameraId_variants()).getCameraParams_ro();

    /* Get the Camera radial lens data (Intrinsic) from camera manager (eeprom) */
    mecl::model::LensRadial<float32_t>::Config_s v_lensCfg_s;
     v_SensorCameraParam.getRealRadialLensData_b(v_lensCfg_s);
    /*v_SensorCameraParam.getRadialLensDesignData_b(v_lensCfg_s);*/
    mecl::model::LensRadial<float32_t> v_Lens(v_lensCfg_s);

    /* Get the Camera sensor data (Intrinsic) from camera manager (eeprom) */
    mecl::model::Sensor<float32_t>::Config_s v_sensorCfg_s;
    v_SensorCameraParam.getRealSensorData_b(v_sensorCfg_s);
    mecl::model::Sensor<float32_t> v_Sensor(v_sensorCfg_s);

    /* Get the Camera pinhole design (Extrinsic) from camera manager (eeprom) */
    mecl::model::Pinhole<float32_t>::Config_s v_PinholeCfg_s;
    v_SensorCameraParam.getPinholeDesignData_b(v_PinholeCfg_s);
    mecl::model::Pinhole<float32_t> v_Pinhole_o(v_PinholeCfg_s);

    mecl::model::Camera<float32_t> v_Camera_o(v_Pinhole_o, v_Lens, v_Sensor);

#if 0
    sensor::CameraParams& v_RearSensorCameraParam = dataProvider_ro.getCamMData_po()->getCamera_ro(variants::Camera_t::e_CameraRear).getCameraParams_ro();
    v_SensorCameraParam.init_b(variants::Camera_t::e_CameraRear);
    mecl::model::Pinhole<float32_t>::Config_s v_RearPinholeCfg_s;
    v_RearSensorCameraParam.getPinholeDesignData_b(v_RearPinholeCfg_s);
    mecl::model::Pinhole<float32_t> v_RearPinhole_o(v_RearPinholeCfg_s);
#endif
    
    sint8_t   v_TargetIndex_s8;
    float32_t v_OffsetX_f32;
    float32_t v_PatternX_f32 = TARGET_SIZE*3.0F*25.4F;
    v_OffsetX_f32 = v_PatternX_f32 * 0.5F;
    mecl::model::Pinhole<float32_t>::Config_s v_RearPinholeCfg_s;

    if(variants::Camera_t::e_CameraRear == getCameraId_variants())
    {
      mecl::model::Pinhole<float32_t>::Config_s v_RearPinholeCfg_s;
      v_RearPinholeCfg_s = v_PinholeCfg_s;
      mecl::model::Pinhole<float32_t> v_RearPinhole_o(v_RearPinholeCfg_s);

      mecl::core::Point3D<float32_t> v_T_o = v_RearPinhole_o.getTranslationVector_x();
      v_T_o = v_RearPinhole_o.getCameraCenter_x(v_T_o);
      v_TargetIndex_s8 = static_cast<sint8_t>((v_T_o(0) - v_OffsetX_f32)/v_PatternX_f32);
    }
    else
    {
    	//Do nothing
    }

#if EOL_PARAMS_DEBUGGING
  if (e_EndOfLineCalibration == calibType_e)
  {
    ME_Debugger_F_Printf_v("\n\n\nPrinting Camera Params\n");
    ME_Debugger_F_Printf_v("Cam id: %d\n", camID_e);

    ME_Debugger_F_Printf_v("For v_lensCfg_s: \n");
    ME_Debugger_F_Printf_v("elevationMaxCfg: %f\n",v_lensCfg_s.elevationMaxCfg_x);
    ME_Debugger_F_Printf_v("image2world_x[0]: %f\n",v_lensCfg_s.image2world_x[0]);
    ME_Debugger_F_Printf_v("image2world_x[1]: %f\n",v_lensCfg_s.image2world_x[1]);
    ME_Debugger_F_Printf_v("image2world_x[2]: %f\n",v_lensCfg_s.image2world_x[2]);
    ME_Debugger_F_Printf_v("image2world_x[3]: %f\n",v_lensCfg_s.image2world_x[3]);
    ME_Debugger_F_Printf_v("image2world_x[4]: %f\n",v_lensCfg_s.image2world_x[4]);
    ME_Debugger_F_Printf_v("image2world_x[5]: %f\n",v_lensCfg_s.image2world_x[5]);
    ME_Debugger_F_Printf_v("world2image_x[0]: %f\n",v_lensCfg_s.world2image_x[0]);
    ME_Debugger_F_Printf_v("world2image_x[1]: %f\n",v_lensCfg_s.world2image_x[1]);
    ME_Debugger_F_Printf_v("world2image_x[2]: %f\n",v_lensCfg_s.world2image_x[2]);
    ME_Debugger_F_Printf_v("world2image_x[3]: %f\n",v_lensCfg_s.world2image_x[3]);
    ME_Debugger_F_Printf_v("world2image_x[4]: %f\n",v_lensCfg_s.world2image_x[4]);
    ME_Debugger_F_Printf_v("world2image_x[5]: %f\n",v_lensCfg_s.world2image_x[5]);

    ME_Debugger_F_Printf_v("For v_sensorCfg_s: \n");
    ME_Debugger_F_Printf_v("pppCfg_x.cVal_ax[0]: %f\n",v_sensorCfg_s.pppCfg_x.cVal_ax[0]);
    ME_Debugger_F_Printf_v("pppCfg_x.cVal_ax[1]: %f\n",v_sensorCfg_s.pppCfg_x.cVal_ax[1]);
    ME_Debugger_F_Printf_v("pszCfg_x.cVal_ax[0]: %f\n",v_sensorCfg_s.pszCfg_x.cVal_ax[0]);
    ME_Debugger_F_Printf_v("pszCfg_x.cVal_ax[1]: %f\n",v_sensorCfg_s.pszCfg_x.cVal_ax[1]);
    ME_Debugger_F_Printf_v("pos1Cfg_x.cVal_ax[0]: %f\n",v_sensorCfg_s.pos1Cfg_x.cVal_ax[0]);
    ME_Debugger_F_Printf_v("pos1Cfg_x.cVal_ax[1]: %f\n",v_sensorCfg_s.pos1Cfg_x.cVal_ax[1]);
    ME_Debugger_F_Printf_v("pos2Cfg_x.cVal_ax[0]: %f\n",v_sensorCfg_s.pos2Cfg_x.cVal_ax[0]);
    ME_Debugger_F_Printf_v("pos2Cfg_x.cVal_ax[1]: %f\n",v_sensorCfg_s.pos2Cfg_x.cVal_ax[1]);

    ME_Debugger_F_Printf_v("For v_PinholeCfg_s: \n");
    ME_Debugger_F_Printf_v("extrinsic_s.pos_x.cVal_ax[0]: %f\n",v_PinholeCfg_s.extrinsic_s.pos_x.cVal_ax[0]);
    ME_Debugger_F_Printf_v("extrinsic_s.pos_x.cVal_ax[1]: %f\n",v_PinholeCfg_s.extrinsic_s.pos_x.cVal_ax[1]);
    ME_Debugger_F_Printf_v("extrinsic_s.pos_x.cVal_ax[2]: %f\n",v_PinholeCfg_s.extrinsic_s.pos_x.cVal_ax[2]);
    ME_Debugger_F_Printf_v("PitchDeg: %f\n",mecl::math::toDegrees_x(v_PinholeCfg_s.extrinsic_s.eulerAngles_s.pitch_x));
    ME_Debugger_F_Printf_v("RollDeg: %f\n",mecl::math::toDegrees_x(v_PinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x));
    ME_Debugger_F_Printf_v("YawDeg: %f\n",mecl::math::toDegrees_x(v_PinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x));
    ME_Debugger_F_Printf_v("extrinsic_s.eulerAngles_s.pitch_x: %f\n",v_PinholeCfg_s.extrinsic_s.eulerAngles_s.pitch_x);
    ME_Debugger_F_Printf_v("extrinsic_s.eulerAngles_s.roll_x: %f\n",v_PinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x);
    ME_Debugger_F_Printf_v("extrinsic_s.eulerAngles_s.yaw_x: %f\n",v_PinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x);
    ME_Debugger_F_Printf_v("intrinsic_s.foclX_x: %f\n",v_PinholeCfg_s.intrinsic_s.foclX_x);
    ME_Debugger_F_Printf_v("intrinsic_s.foclY_x: %f\n",v_PinholeCfg_s.intrinsic_s.foclY_x);
    ME_Debugger_F_Printf_v("intrinsic_s.pppCfg_x.cVal_ax[0]: %f\n",v_PinholeCfg_s.intrinsic_s.pppCfg_x.cVal_ax[0]);
    ME_Debugger_F_Printf_v("intrinsic_s.pppCfg_x.cVal_ax[1]: %f\n\n\n",v_PinholeCfg_s.intrinsic_s.pppCfg_x.cVal_ax[1]);
  }
#endif

    switch(camID_e)
      {
        case eol::e_FrontCamAlgo:

        	targetLimitF_as8[camID_e] = -3;
            targetInit_as8[camID_e] = -2;
            targetLimitR_as8[camID_e] = -1; //For P558. For D544, it should be -2.
        break;

        case eol::e_LeftCamAlgo:

        	targetLimitF_as8[camID_e] = -2;
            targetInit_as8[camID_e] = 0;
            targetLimitR_as8[camID_e] = 8;
        break;

        case eol::e_RearCamAlgo:
          {
            sint8_t rearCamMaxTargetLimitR_s8 = 9;
            targetLimitF_as8[camID_e] = v_TargetIndex_s8 + 1;
            targetInit_as8[camID_e] = v_TargetIndex_s8 + 1;

            if ((v_TargetIndex_s8 + 4) <= rearCamMaxTargetLimitR_s8)
            {
              targetLimitR_as8[camID_e] = v_TargetIndex_s8 + 4;
            }
            else
            {
              targetLimitR_as8[camID_e] = rearCamMaxTargetLimitR_s8;
            }
        break;
          }

        case eol::e_RightCamAlgo:

        	targetLimitF_as8[camID_e] = -2;
            targetInit_as8[camID_e] = 0;
            targetLimitR_as8[camID_e] = 8;
        break;
      }
#endif
        //Updating float64_t camera object by copying elements from float32_t camera object
      mecl::model::LensRadial<float64_t>::Config_s v_LensRadialCfg64_o;
      mecl::model::Pinhole<float64_t>::Config_s v_PinholeCfg64_o;
      mecl::model::Sensor<float64_t>::Config_s v_SensorCfg64_o;

      // PRQA S 3077 1 // This downcast is necessary here.
      mecl::model::Pinhole<float32_t> &v_PinHole32_ro = dynamic_cast<mecl::model::Pinhole<float32_t>&>(v_Camera_o.getImager_rx());
      const mecl::model::Pinhole<float32_t>::Intrinsic_s& v_Intrinsics32_ro = v_PinHole32_ro.getIntrinsic_rs();
      const mecl::model::Pinhole<float32_t>::Extrinsic_s& v_Extrinsics32_ro = v_PinHole32_ro.getExtrinsic_rs();

      const mecl::model::Sensor<float32_t>& v_EolSensor32_ro = dynamic_cast<mecl::model::Sensor<float32_t>&>(v_Camera_o.getSensor_rx());
      mecl::model::Sensor<float32_t>::Config_s v_SensorConfig32_s;
      v_EolSensor32_ro.copyConfig_v(v_SensorConfig32_s);
      const mecl::model::LensRadial<float32_t>& v_EolLensRadial32_ro = dynamic_cast<mecl::model::LensRadial<float32_t>&>(v_Camera_o.getLens_rx());
      mecl::model::LensRadial<float32_t>::Config_s v_LensRadialConfig32_s;
      v_EolLensRadial32_ro.copyConfig_v(v_LensRadialConfig32_s);

      v_PinholeCfg64_o.extrinsic_s.eulerAngles_s.pitch_x = static_cast<float64_t>(v_Extrinsics32_ro.eulerAngles_s.pitch_x);
      v_PinholeCfg64_o.extrinsic_s.eulerAngles_s.yaw_x = static_cast<float64_t>(v_Extrinsics32_ro.eulerAngles_s.yaw_x);
      v_PinholeCfg64_o.extrinsic_s.eulerAngles_s.roll_x = static_cast<float64_t>(v_Extrinsics32_ro.eulerAngles_s.roll_x);
      v_PinholeCfg64_o.extrinsic_s.pos_x.cVal_ax[0] = static_cast<float64_t>(v_Extrinsics32_ro.pos_x.cVal_ax[0]);
      v_PinholeCfg64_o.extrinsic_s.pos_x.cVal_ax[1] = static_cast<float64_t>(v_Extrinsics32_ro.pos_x.cVal_ax[1]);
      v_PinholeCfg64_o.extrinsic_s.pos_x.cVal_ax[2] = static_cast<float64_t>(v_Extrinsics32_ro.pos_x.cVal_ax[2]);

      design_ang.camYaw_f32  = static_cast<float64_t>(v_Extrinsics32_ro.eulerAngles_s.yaw_x);
      design_ang.camPitch_f32 = static_cast<float64_t>(v_Extrinsics32_ro.eulerAngles_s.pitch_x);
      design_ang.camRoll_f32 = static_cast<float64_t>(v_Extrinsics32_ro.eulerAngles_s.roll_x);
      design_ang.camX_f32 = static_cast<float64_t>(v_Extrinsics32_ro.pos_x.cVal_ax[0]);
      design_ang.camY_f32 = static_cast<float64_t>(v_Extrinsics32_ro.pos_x.cVal_ax[1]);
      design_ang.camZ_f32 = static_cast<float64_t>(v_Extrinsics32_ro.pos_x.cVal_ax[2]);
      v_PinholeCfg64_o.extrinsic_s.preRoll_e = v_Extrinsics32_ro.preRoll_e;
      v_PinholeCfg64_o.extrinsic_s.rotationType_e = v_Extrinsics32_ro.rotationType_e;
      v_PinholeCfg64_o.intrinsic_s.foclX_x = static_cast<float64_t>(v_Intrinsics32_ro.foclX_x);
      v_PinholeCfg64_o.intrinsic_s.foclY_x = static_cast<float64_t>(v_Intrinsics32_ro.foclY_x);
      v_PinholeCfg64_o.intrinsic_s.pppCfg_x.cVal_ax[0] =  static_cast<float64_t>(v_Intrinsics32_ro.pppCfg_x.cVal_ax[0]);
      v_PinholeCfg64_o.intrinsic_s.pppCfg_x.cVal_ax[1] =  static_cast<float64_t>(v_Intrinsics32_ro.pppCfg_x.cVal_ax[1]);

      pinhole64_o.updateConfig_v(v_PinholeCfg64_o);
      camera64_o.setImager_v(pinhole64_o);
      v_SensorCfg64_o.pppCfg_x.cVal_ax[0] = static_cast<float64_t>(v_SensorConfig32_s.pppCfg_x.cVal_ax[0]);
      v_SensorCfg64_o.pppCfg_x.cVal_ax[1] = static_cast<float64_t>(v_SensorConfig32_s.pppCfg_x.cVal_ax[1]);
      v_SensorCfg64_o.pszCfg_x.cVal_ax[0] = static_cast<float64_t>(v_SensorConfig32_s.pszCfg_x.cVal_ax[0]);
      v_SensorCfg64_o.pszCfg_x.cVal_ax[1] = static_cast<float64_t>(v_SensorConfig32_s.pszCfg_x.cVal_ax[1]);
        v_SensorCfg64_o.imageOriginPositionCfg_e = v_SensorConfig32_s.imageOriginPositionCfg_e;
      v_SensorCfg64_o.pos1Cfg_x.cVal_ax[0] = static_cast<float64_t>(v_SensorConfig32_s.pos1Cfg_x.cVal_ax[0]);
      v_SensorCfg64_o.pos1Cfg_x.cVal_ax[1] = static_cast<float64_t>(v_SensorConfig32_s.pos1Cfg_x.cVal_ax[1]);
      v_SensorCfg64_o.pos2Cfg_x.cVal_ax[0] = static_cast<float64_t>(v_SensorConfig32_s.pos2Cfg_x.cVal_ax[0]);
      v_SensorCfg64_o.pos2Cfg_x.cVal_ax[1] = static_cast<float64_t>(v_SensorConfig32_s.pos2Cfg_x.cVal_ax[1]);
      sensor64_o.updateConfig_v(v_SensorCfg64_o);
      camera64_o.setSensor_v(sensor64_o);
      for(uint32_t v_I_u32 = 0U; v_I_u32 < 6U; v_I_u32++)
      {
        v_LensRadialCfg64_o.world2image_x[v_I_u32] = static_cast<float64_t>(v_LensRadialConfig32_s.world2image_x[v_I_u32]);
        v_LensRadialCfg64_o.image2world_x[v_I_u32] = static_cast<float64_t>(v_LensRadialConfig32_s.image2world_x[v_I_u32]);
      }
      v_LensRadialCfg64_o.elevationMaxCfg_x = static_cast<float64_t>(v_LensRadialConfig32_s.elevationMaxCfg_x);
      lensRadial64_o.updateConfig_v(v_LensRadialCfg64_o);
      camera64_o.setLens_v(lensRadial64_o);

}

void DataProviderEol::setEOLRuntime(uint32_t u_Runtime_u32)
{
  dataProvider_ro.getEolMData_po()->setEOLRuntime(u_Runtime_u32);
}

void DataProviderEol::setEOLThreadRuntime(uint32_t u_Runtime_u32)
{
  dataProvider_ro.getEolMData_po()->setEOLThreadRuntime(u_Runtime_u32);
}

PerformanceStatsEnable_t DataProviderEol::get_PerformanceStatsEnable(void)
{
	return dataProvider_ro.getSigMData_po()->getPerformanceStatsEnable_t();
}

} // namespace eol
