//--------------------------------------------------------------------------
/// @file CamTypes.h
/// @brief Implementation of structs used to read out Camera EEPROM data
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
///
//  --------------------------------------------------------------------------

#ifndef CAM_TYPES_H
#define CAM_TYPES_H

#include "PlatformDataTypes.h"

typedef struct MagnaSerialNumber_s
{
  char_T initialCharacter_c;                  //  1 bytes
  char_T productionLineNumber_ac[2U];         //  2 bytes
  char_T productionYear_ac[2U];               //  2 bytes
  char_T productionDay_ac[3U];                //  3 bytes
  char_T productionSerialNumber_ac[5U];       //  5 bytes
  char_T productionBoardSerialNumber_ac[2U];  //  2 bytes
  char_T zeroCharacter_c;                     //  1 bytes

} MagnaSerialNumber_t;  // 16 bytes


typedef struct FinalAssemblySerialNumber_s
{
  char_T finalAssemblyYear_ac[2U];            //  2 bytes
  char_T finalAssemblyDay_ac[3U];             //  3 bytes
  char_T finalAssemblySerialNumber_ac[4U];    //  4 bytes
  char_T finalAssemblyFocusAndAlign_ac[1U];   //  1 bytes

} FinalAssemblySerialNumber_t;  //10 bytes


typedef struct CamEepromProductionData_s
{
  char_T                      constantStartSequence_ac[2];      //  2 bytes
  MagnaSerialNumber_t         magnaSerialNumber_s;              // 16 bytes
  FinalAssemblySerialNumber_t finalAssemblySerialNumber_s;      // 10 bytes
  char_T                      finalAssemblyPartNumber_ac[16U];  // 16 bytes
  uint16_t                    eepromMapRevision_au16[2U];       //  4 bytes (+(2*2) bytes due to uint16_t)
  uint8_t                     reservedBytes_au8[16U];           // 16 Bytes
  
} CamEepromProductionData_t;  //64 bytes

// --- CamEepromProductionData End ---


// --- CamEepromIntrinsicData Begin ---


typedef struct CamEepromIntrinsicData_s // 128 bytes
{
  char_T    intrinsicAlgoRevision_ac[16U];                        //  16 bytes
  uint32_t  imageWidth_u32;                                       //   4 bytes
  uint32_t  imageHeight_u32;                                      //   4 bytes
  float32_t ppx_f32;                                              //   4 bytes
  float32_t ppy_f32;                                              //   4 bytes
  float32_t polyImage2World_af32[6];                              //  24 bytes (6*4) 
  float32_t polyWorld2Image_af32[6];                              //  24 bytes (6*4) 
  float32_t pixelSizeX_f32;                                       //   4 bytes
  float32_t pixelSizeY_f32;                                       //   4 bytes
  float32_t fieldOfView_f32;                                      //   4 bytes
  float32_t effectiveFocalLength_f32;                             //   4 bytes
  uint8_t   reservedBytes_au8[32];                                //  32 bytes

} CamEepromIntrinsicData_t; //128 bytes

// --- CamEepromIntrinsicData End ---


// --- CamEepromCrcData Begin ---

typedef struct CamEepromCrcData_s 
{
  
  uint32_t  crc_u32;                 //4 bytes
  uint8_t   firstReservedBytes_u8[56];  //56 bytes
  uint8_t   secondReservedBytes_u8[4];  // 4 bytes 
  
} CamEepromCrcData_t; // 64 bytes

// --- CamEepromCrcData End ---


typedef struct CamEepromData_s
{
  CamEepromProductionData_t camProductionData_s; //64 bytes
  CamEepromIntrinsicData_t  camIntrinsicData_s;  //128 bytes
  CamEepromCrcData_t        camCrcData_s;        //64 bytes
} CameraEepromData_t; //256 bytes

/*******************************************************************************/
// --- CamEepromDataArray for 4 cameras ---
//  CameraFront = 0, // Front Camera
//  CameraLeft = 1, // Left Camera
//  CameraRear = 2, // Rear Camera
//  CameraRight = 3, // Right Camera

//----A72 to mcu1_0----->
/*****************************************************************************/
typedef struct Svs_CamEepromDataArray_s
{
  CameraEepromData_t CameraEepromData[4]; //256*4 bytes
}Svs_CamEepromDataArray_t;  //   1024 bytes

//----MCU2_0 to A72----->
/*****************************************************************************/
typedef struct CamHotplugStatus_s
{
  uint8_t CamStatus[4]; //4 bytes
} CamHotplugStatus_t;

#endif // CAM_TYPES_H
