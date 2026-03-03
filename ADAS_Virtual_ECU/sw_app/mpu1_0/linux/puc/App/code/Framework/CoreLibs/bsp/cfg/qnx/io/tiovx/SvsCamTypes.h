//--------------------------------------------------------------------------
/// @file SvsCamTypes.h
/// @brief Implementation of structs used to read out Camera EEPROM data
///        Based on: https://magnalm-prd.ptcmscloud.com:7001/si/viewrevision?projectName=%23/L2G8970%23KP03_ProductEngineering/40_Software/10_Architecture/docs&selection=CAMERA_EEPROM_ZURICH_LITE_HD.xlsx
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Ananda kavrady (Ananda.kavrady@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef SVS_CAM_TYPES_H
#define SVS_CAM_TYPES_H


// static sizes for the three eeprom data sections
/*These Variable declarations should match with MCU2_0 declarations in Iss_sensors.c, if there is a change update at both places*/
static const uint8_t c_EepromDataCrcStartAddress_u8 = 248U;
static const uint32_t c_EepromDataCrcSize_u32 = 4U;
static const uint8_t c_EepromDataProductionStartAddress_u8 = 0U;
static const uint32_t c_EepromDataProductionSize_u32 = 64U;
static const uint8_t c_EepromDataIntrinsicStartAddress_u8 = 64U;
static const uint32_t c_EepromDataIntrinsicSize_u32 = 128U;

static const uint8_t c_EepromDataCRCCheckStartAddress_u8 = 2U;
static const uint8_t c_EepromDataCRCCheckEndAddress_u8 = 247u;
static const uint8_t c_EepromDataCRCCheckSize_u8 = 246u;
// --- CamEepromProductionData Begin ---

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
    StaticAssert(16U == sizeof(MagnaSerialNumber_s), "MagnaSerialNumber_s != 16  �\_(?)_/�");
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
    StaticAssert(10U == sizeof(FinalAssemblySerialNumber_s), "FinalAssemblySerialNumber_s != 10  �\_(?)_/�");
  }

  char_t finalAssemblyYear_ac[2U];            //  2 bytes
  char_t finalAssemblyDay_ac[3U];             //  5 bytes
  char_t finalAssemblySerialNumber_ac[4U];    //  9 bytes
  char_t finalAssemblyFocusAndAlign_ac[1U];   // 10 bytes

} FinalAssemblySerialNumber_t;


typedef struct SVSEepromProductionData_s //64 bytes
{
  SVSEepromProductionData_s()
    : magnaSerialNumber_s()
    , finalAssemblySerialNumber_s()
  {
    memset(constantStartSequence_ac,    0U, sizeof(constantStartSequence_ac));
    memset(finalAssemblyPartNumber_ac,  0U, sizeof(finalAssemblyPartNumber_ac));
    memset(eepromMapRevision_au16,      0U, sizeof(eepromMapRevision_au16));
    memset(reservedBytes_au8,           0U, sizeof(reservedBytes_au8));

    // make sure this is 64 bytes
    StaticAssert(c_EepromDataProductionSize_u32 == sizeof(SVSEepromProductionData_s), "SVSEepromProductionData_s != c_EepromDataProductionSize_u32  �\_(?)_/�");
  }

  char_t                      constantStartSequence_ac[2];      //  2 bytes
  MagnaSerialNumber_t         magnaSerialNumber_s;              // 18 bytes
  FinalAssemblySerialNumber_s finalAssemblySerialNumber_s;      // 28 bytes
  char_t                      finalAssemblyPartNumber_ac[16U];  // 44 bytes
  uint16_t                    eepromMapRevision_au16[2U];       // 48 bytes (+(2*2) bytes due to uint16_t)
  uint8_t                     reservedBytes_au8[16U];           // 64 Bytes

} SVSEepromProductionData_t;

// --- CamEepromProductionData End ---
// --- CamEepromIntrinsicData Begin ---

static const uint32_t c_EepromIntrnisicPolySize_u32 = 6U;
typedef struct SVSEepromIntrinsicData_s // 128 bytes
{
  SVSEepromIntrinsicData_s()
    : imageWidth_u32(1920UL)
    , imageHeight_u32(1280UL)
    , ppx_f32(962.0F)
    , ppy_f32(643.0F)
  {
    memset(intrinsicAlgoRevision_ac,  0U, sizeof(intrinsicAlgoRevision_ac));
    memset(reservedBytes_au8,         0xFF, sizeof(reservedBytes_au8));
    polyImage2World_af32[0]           = 0.0F;
    polyImage2World_af32[1]           = 0.721F;
    polyImage2World_af32[2]           = -0.01030F;
    polyImage2World_af32[3]           = -0.04700F;
    polyImage2World_af32[4]           = 0.02300F;
    polyImage2World_af32[5]           = -0.00350F;

    polyWorld2Image_af32[0]           = 0.0F;
    polyWorld2Image_af32[1]           = 1.4F;
    polyWorld2Image_af32[2]           = -0.03450F;
    polyWorld2Image_af32[3]           = 0.31600F;
    polyWorld2Image_af32[4]           = -0.20400F;
    polyWorld2Image_af32[5]           = 0.04540F;

    pixelSizeX_f32                    = 0.003F;
    pixelSizeY_f32                    = 0.003F;
    fieldOfView_f32                   = 3.840F;
    effectiveFocalLength_f32          = 1.0F;

    reservedBytes_au8[0]             = 0xFF;
    reservedBytes_au8[1]             = 0xFF;
    reservedBytes_au8[2]             = 0xFF;
    reservedBytes_au8[3]             = 0xFF;
    reservedBytes_au8[4]             = 0xFF;
    reservedBytes_au8[5]             = 0xFF;
    reservedBytes_au8[6]             = 0xFF;
    reservedBytes_au8[7]             = 0xFF;
    reservedBytes_au8[8]             = 0xFF;
    reservedBytes_au8[9]             = 0xFF;
    reservedBytes_au8[10]             = 0xFF;
    reservedBytes_au8[11]             = 0xFF;
    reservedBytes_au8[12]             = 0xFF;
    reservedBytes_au8[13]             = 0xFF;
    reservedBytes_au8[14]             = 0xFF;
    reservedBytes_au8[15]             = 0xFF;
    reservedBytes_au8[16]             = 0xFF;
    reservedBytes_au8[17]             = 0xFF;
    reservedBytes_au8[18]             = 0xFF;
    reservedBytes_au8[19]             = 0xFF;
    reservedBytes_au8[20]             = 0xFF;
    reservedBytes_au8[21]             = 0xFF;
    reservedBytes_au8[22]             = 0xFF;
    reservedBytes_au8[23]             = 0xFF;
    reservedBytes_au8[24]             = 0xFF;
    reservedBytes_au8[25]             = 0xFF;
    reservedBytes_au8[26]             = 0xFF;
    reservedBytes_au8[27]             = 0xFF;
    reservedBytes_au8[28]             = 0xFF;
    reservedBytes_au8[29]             = 0xFF;


    // make sure this is 128 bytes
    StaticAssert(c_EepromDataIntrinsicSize_u32 == sizeof(SVSEepromIntrinsicData_s), "SVSEepromIntrinsicData_s != c_EepromDataIntrinsicSize_u32  �\_(?)_/�");
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
  uint8_t   reservedBytes_au8[32];                               // 128 bytes

} SVSEepromIntrinsicData_t;

// --- CamEepromIntrinsicData End ---
typedef struct SVSEepromData_s
{
  SVSEepromProductionData_t SVSProductionData_s; //  64 bytes
  SVSEepromIntrinsicData_t  SVSIntrinsicData_s;  // 128 bytes
  uint32_t  crc_u32;
} SVSEepromData_t;

//----A72 to mcu1_0----->
/*****************************************************************************/
typedef struct Svs_CamEepromDataArray_s
{
  SVSEepromData_t CameraEepromData[4]; //256*4 bytes
} Svs_CamEepromDataArray_t;  //   1024 bytes

#endif // CAM_TYPES_H
