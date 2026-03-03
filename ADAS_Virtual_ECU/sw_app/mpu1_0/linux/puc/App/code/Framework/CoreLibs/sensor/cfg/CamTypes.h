//--------------------------------------------------------------------------
/// @file CamTypes.h
/// @brief Implementation of structs used to read out Camera EEPROM data
///        Based on: https://magnalm-prd.ptcmscloud.com:7001/si/viewrevision?projectName=%23/L2G8970%23KP03_ProductEngineering/40_Software/10_Architecture/docs&selection=CAMERA_EEPROM_ZURICH_LITE_HD.xlsx
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CAM_TYPES_H
#define CAM_TYPES_H

#include <platform/PlatformAPI.h>

#include <variants/Enums.h>

#include <mecl/meclcfg.h>

#ifdef ME_PLATFORM_QNX
#include <screen/screen.h>
#endif

// PRQA S 2100 EOF // public members used by design in structs

namespace sensor
{

// helper function to map Magna Camera Ids to QNX Ids
uint32_t mapCameraIds_u32(variants::Camera_t i_CameraId_t);


// static sizes for the three eeprom data sections
static const uint32_t c_EepromDataCamVersionSize_u32 = 16U;
static const uint32_t c_EepromDataProductionSize_u32 = 64U;
static const uint32_t c_EepromDataIntrinsicSize_u32 = 252U;
static const uint32_t c_EepromDataCrcSize_u32 = 4U;
static const uint32_t c_EepromDataSize_u32 = c_EepromDataCamVersionSize_u32 + c_EepromDataProductionSize_u32 + c_EepromDataIntrinsicSize_u32 + c_EepromDataCrcSize_u32;

// --- CamEepromProductionData Begin ---

typedef struct CamVersion_s
{

  CamVersion_s()
  {
    memset(camVersion_au8, 0, sizeof(camVersion_au8));
  }

  uint8_t camVersion_au8[c_EepromDataCamVersionSize_u32];
} CamVersion_t;

typedef struct MagnaSerialNumber_s
{
  MagnaSerialNumber_s()
    : initialCharacter_c(0U)
  {
    memset(productionLineNumber_ac, 0U, sizeof(productionLineNumber_ac));
    memset(productionYear_ac, 0U, sizeof(productionYear_ac));
    memset(productionDay_ac, 0U, sizeof(productionDay_ac));
    memset(productionSerialNumber_ac, 0U, sizeof(productionSerialNumber_ac));
    memset(productionBoardSerialNumber_ac, 0U, sizeof(productionBoardSerialNumber_ac));
    zeroCharacter_c = 0U;

    // Make sure this is 16 bytes
    StaticAssert(16U == sizeof(MagnaSerialNumber_s), " CamEepromTypes.h - MagnaSerialNumber_s != 16  �\_(?)_/�");
  }

  char_t initialCharacter_c;                  //  1 bytes
  char_t productionLineNumber_ac[2U];         //  3 bytes
  char_t productionYear_ac[2U];               //  5 bytes
  char_t productionDay_ac[3U];                //  8 bytes
  char_t productionSerialNumber_ac[5U];       // 13 bytes
  char_t productionBoardSerialNumber_ac[2U];  // 15 bytes
  char_t zeroCharacter_c;                     // 16 bytes

} MagnaSerialNumber_t;


typedef struct FinalAssemblySerialNumber_s
{
  // PRQA S 4054 1 // The members are initialized within body of constructor
  FinalAssemblySerialNumber_s()
  {
    memset(finalAssemblyYear_ac,          0U, sizeof(finalAssemblyYear_ac));
    memset(finalAssemblyDay_ac,           0U, sizeof(finalAssemblyDay_ac));
    memset(finalAssemblySerialNumber_ac,  0U, sizeof(finalAssemblySerialNumber_ac));
    memset(finalAssemblyFocusAndAlign_ac, 0U, sizeof(finalAssemblyFocusAndAlign_ac));

    // Make sure this is 10 bytes
    StaticAssert(10U == sizeof(FinalAssemblySerialNumber_s), "CamEepromTypes.h - FinalAssemblySerialNumber_s != 10  �\_(?)_/�");
  }

  char_t finalAssemblyYear_ac[2U];            //  2 bytes
  char_t finalAssemblyDay_ac[3U];             //  5 bytes
  char_t finalAssemblySerialNumber_ac[4U];    //  9 bytes
  char_t finalAssemblyFocusAndAlign_ac[1U];   // 10 bytes

} FinalAssemblySerialNumber_t;


typedef struct CamEepromProductionData_s //64 bytes
{
  CamEepromProductionData_s()
    : magnaSerialNumber_s()
    , finalAssemblySerialNumber_s()
  {
    memset(constantStartSequence_ac,    0U, sizeof(constantStartSequence_ac));
    memset(finalAssemblyPartNumber_ac,  0U, sizeof(finalAssemblyPartNumber_ac));
    memset(eepromMapRevision_au16,      0U, sizeof(eepromMapRevision_au16));
    memset(reservedBytes_au8,           0U, sizeof(reservedBytes_au8));

    // make sure this is 64 bytes
    StaticAssert(c_EepromDataProductionSize_u32 == sizeof(CamEepromProductionData_s), "CamEepromTypes.h - CamEepromProductionData_s != c_EepromDataProductionSize_u32  �\_(?)_/�");
  }

  char_t                      constantStartSequence_ac[2];      //  2 bytes
  MagnaSerialNumber_t         magnaSerialNumber_s;              // 18 bytes
  FinalAssemblySerialNumber_s finalAssemblySerialNumber_s;      // 28 bytes
  char_t                      finalAssemblyPartNumber_ac[16U];  // 44 bytes
  uint16_t                    eepromMapRevision_au16[2U];       // 48 bytes (+(2*2) bytes due to uint16_t)
  uint8_t                     reservedBytes_au8[16U];           // 64 Bytes

} CamEepromProductionData_t;

// --- CamEepromProductionData End ---


// --- CamEepromIntrinsicData Begin ---

static const uint32_t c_EepromIntrnisicPolySize_u32 = 6U;
typedef struct CamEepromIntrinsicData_s // 128 bytes
{
  CamEepromIntrinsicData_s()
    : imageWidth_u32(0UL)
    , imageHeight_u32(0UL)
    , ppx_f32(0.0F)
    , ppy_f32(0.0F)
  {
    memset(polyImage2World_af32,      0U, sizeof(polyImage2World_af32));
    memset(polyWorld2Image_af32,      0U, sizeof(polyWorld2Image_af32));

    pixelSizeX_f32                    = 0.0F;
    pixelSizeY_f32                    = 0.0F;
    fieldOfView_f32                   = 0.0F;
    effectiveFocalLength_f32          = 0.0F;

    memset(intrinsicAlgoRevision_ac,  0U, sizeof(intrinsicAlgoRevision_ac));
    memset(reservedBytes_au8,         0U, sizeof(reservedBytes_au8));

    // make sure this is 128 bytes
    StaticAssert(c_EepromDataIntrinsicSize_u32 == sizeof(CamEepromIntrinsicData_s), "CamEepromTypes.h - CamEepromIntrinsicData_s != c_EepromDataIntrinsicSize_u32  �\_(?)_/�");
  }

  char_t    intrinsicAlgoRevision_ac[16U];                        //  16 bytes
  uint32_t  imageWidth_u32;                                       //  20 bytes
  uint32_t  imageHeight_u32;                                      //  24 bytes
  float32_t ppx_f32;                                              //  28 bytes
  float32_t ppy_f32;                                              //  32 bytes
  float32_t polyImage2World_af32[c_EepromIntrnisicPolySize_u32];  //  56 bytes (+(6*4)) 
  float32_t polyWorld2Image_af32[c_EepromIntrnisicPolySize_u32];  //  80 bytes (+(6*4)) 
  float32_t pixelSizeX_f32;                                       //  84 bytes
  float32_t pixelSizeY_f32;                                       //  88 bytes
  float32_t fieldOfView_f32;                                      //  92 bytes
  float32_t effectiveFocalLength_f32;                             //  96 bytes
  uint8_t   reservedBytes_au8[156];                               // 252 bytes

} CamEepromIntrinsicData_t;

// --- CamEepromIntrinsicData End ---


// --- CamEepromCrcData Begin ---

typedef struct CamEepromCrcData_s // 64 bytes
{
  // PRQA S 4054 1 // The members are initialized within body of constructor
  CamEepromCrcData_s()
  {
    crc_u32 = 0U;

    // make sure this is 64 bytes
    StaticAssert(c_EepromDataCrcSize_u32 == sizeof(CamEepromCrcData_s), "CamEepromTypes.h - CamEepromCrcData_s != c_EepromDataCrcSize_u32  �\_(?)_/�");
  }
  uint32_t  crc_u32;            // 60 bytes

} CamEepromCrcData_t;

// --- CamEepromCrcData End ---


typedef struct CamEepromData_s
{
  CamEepromData_s()
    : camVersion_s()
    , camCrcData_s()
    , camIntrinsicData_s()
    , camProductionData_s()
  {
    // make sure this is 128 bytes
    StaticAssert(c_EepromDataSize_u32 == sizeof(CamEepromData_s), "CamEepromTypes.h - CamEepromData_s != c_EepromDataSize_u32  �\_(?)_/�");

  }

  CamVersion_t              camVersion_s;
  CamEepromCrcData_t        camCrcData_s;        // 256 bytes
  CamEepromIntrinsicData_t  camIntrinsicData_s;  // 192 bytes
  CamEepromProductionData_t camProductionData_s; //  64 bytes

} CameraEepromData_t;

#pragma pack(1) // exact fit - no padding // PRQA S 1040 // pragma needed for structures
typedef struct CameraErrorData_s
{
  uint16_t DetErr_u16;                  // 2
  uint16_t CorrErr_u16;                 // 4

  uint8_t ConfigLinkDetected_u8   : 1;
  uint8_t VideoLinkDetected_u8    : 1;
  uint8_t HLocked_u8              : 1;
  uint8_t LengthErr_u8            : 1;
  uint8_t LineBufferOverflow_u8   : 1;
  uint8_t VSyncdetect_u8          : 1;
  uint8_t FSync_Locked_u8         : 1;
  uint8_t reserved0_u8            : 1;  // 5

  uint8_t reserved4_u8            : 4;
  uint8_t reserved5_u8            : 1;
  uint8_t EepromCrcError_u8       : 1;
  uint8_t RunningStatus_u8        : 1;
  uint8_t PowerStatus_u8          : 1;  // 6
  uint8_t Tested_u8               : 1;
  uint8_t CamDataError_u8         : 1;
  uint8_t CamOperationError_u8    : 1;
  uint8_t DESError_u8             : 1;
  uint8_t I2CError_u8             : 1;

  CameraErrorData_s()
    : DetErr_u16(0)
    , CorrErr_u16(0)
    , ConfigLinkDetected_u8(0)
    , VideoLinkDetected_u8(0)
    , HLocked_u8(0)
    , LengthErr_u8(0)
    , LineBufferOverflow_u8(0)
    , VSyncdetect_u8(0)
    , FSync_Locked_u8(0)
    , reserved0_u8(0)
    , reserved4_u8(0)
    , reserved5_u8(0)
    , EepromCrcError_u8(0)
    , RunningStatus_u8(0)
    , PowerStatus_u8(0)
    , Tested_u8(0)
    , CamDataError_u8(0)
    , CamOperationError_u8(0)
    , DESError_u8(0)
    , I2CError_u8(0)
  {
  }

} CameraErrorData_t;
#pragma pack() //back to whatever the previous packing mode was // PRQA S 1040 // pragma needed for structures




// typedefs to map from mecl to sensor types
typedef mecl::model::LensRadial<float32_t, variants::e_CoefficientsCount - 1, variants::e_CoefficientsCount - 1> LensRadial_t;
typedef mecl::Pinhole_t Pinhole_t;
typedef mecl::Sensor_t Sensor_t;

typedef struct CalibrationData_s
{
  float32_t pitchDelta_f32;
  float32_t yawDelta_f32;
  float32_t rollDelta_f32;
  float32_t xDelta_f32;
  float32_t yDelta_f32;
  float32_t zDelta_f32;
} CalibrationData_t;

typedef struct ISPData_s
{
  sint8_t Brightness_s8; /* Brightness */
  sint8_t Contrast_s8; /* Contrast */
} ISPData_t;


typedef struct ISPCfgData_s
{
  uint8_t Runtime_ae_enable_u8; /* Runtime_ae_enable */
  uint8_t Runtime_awb_enable_u8; /* Runtime_awb_enable */
  uint8_t WbCfg_enable_u8; /* WbCfg_enable */
  uint8_t GammaCfg_enable_u8; /* GammaCfg_enable */
  uint8_t GammaCfg_lut_u8; /* GammaCfg_lut */
  uint8_t RadialShadingCfg_enable_u8; /* RadialShadingCfg_enable */
  uint8_t SinterCfg_enable_u8; /* SinterCfg_enable */
  uint8_t SharpStrength_Id_u8; /* SharpStrength_Id */
  uint8_t SharpStrength_ldu_u8; /* SharpStrength_ldu */
  uint8_t SharpStrength_lu_u8; /* SharpStrength_lu */
  sint32_t ToneMapCfg_Mode_s32; /* ToneMapCfg_Mode */
} ISPCfgData_t;


enum CameraState_e
{
  e_CameraStateNotInitialized = 0,
  e_CameraStateDisconnected,
  e_CameraStateInitialized,
  e_CameraStateStopped,
  e_CameraStateConnected,
  e_CameraStateConfigImager,
  e_CameraStateRunning,
  e_CameraStateFailure,
  e_CameraStateCount,
  e_CameraStateInvalid
};

enum VideoMode_e
{
  e_VideoModeHumanVision = 0,
  e_VideoModeMachineVision,
  e_VideoModeCount,
  e_VideoModeInvalid
};


//------------------------------------------------------
// Camera PRBS Test

#ifdef ME_PLATFORM_QNX
typedef struct PrbsTestResults_s
{
} PrbsTestResults_t;
#else
typedef struct PrbsTestResults_s
{
} PrbsTestResults_t;
#endif

enum PrbsTestCmd_e
{
  e_PrbsTestCmdStart = 0,
  e_PrbsTestCmdStop,
  e_PrbsTestCmdCount,
  e_PrbsTestCmdInvalid
};

typedef struct PrbsTestData_s
{
  variants::CameraPrbsTestState_t    state_t;

  PrbsTestCmd_e            command_e;

  variants::Camera_t       cameraId_e;

  variants::CameraDevice_t deviceId_e;

  uint32_t                 interval_u32;

  PrbsTestResults_t        results_s;

  PrbsTestData_s()
    : state_t(variants::e_CameraPrbsTestStateNotStarted)
    , command_e(e_PrbsTestCmdInvalid)
    , cameraId_e(variants::e_CameraInvalid)
    , deviceId_e(variants::e_CameraDeviceInvalid)
    , interval_u32(0U)
    , results_s()
  {}

} PrbsTestData_t;

// ----------------------------------------------------------------------------

} // namespace sensor

#endif // CAM_TYPES_H
