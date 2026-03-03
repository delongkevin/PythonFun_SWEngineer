//--------------------------------------------------------------------------
/// @file VariantHelper.h
/// @brief Acts as c/cpp bridge for variant data. Provides Project specific methods for easier access
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert2 (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

// PRQA S 4113 EOF // nested scope is no option if code is used in c context.
// PRQA S 3706 EOF // subscript operator is necessary here for arrays.

#ifndef VARIANT_HELPER_H
#define VARIANT_HELPER_H

#include <platform/PlatformAPI.h>

// include all necessary variant library files
#include "Enums.h"

#ifdef __cplusplus
namespace variants 
{
extern "C" 
{  
#endif  


// --------------------------------- Load Variant Data ------------------------------------------

// get path of variant id file
const char_t* ME_VariantHelper_GetVariantIdFilePath_pc();

// load variant data from file system
bool_t ME_VariantHelper_LoadFromFile_b(const char_t* i_FileName_pc);

// load variant data from memory
bool_t ME_VariantHelper_LoadFromMemory_b(uint8_t* i_Data_pu8, const uint32_t i_DataSize_u32);

// --------------------------------- Camera Data Specific ---------------------------------------

// Gets the Camera GUID of a given camera (front, left, rear, right, fifth) and variant
uint32_t ME_VariantHelper_GetCameraGUID_u32(Camera_t i_Camera_t);

// Gets the camera position (Extrinsic)
bool_t ME_VariantHelper_GetCameraPosition_b(Camera_t i_Camera_t, float32_t* b_X_pf32, float32_t* b_Y_pf32, float32_t* b_Z_pf32);

// Gets the camera rotation (Extrinsic) Returns euler angles in degrees
bool_t ME_VariantHelper_GetCameraRotation_b(Camera_t i_Camera_t, float32_t* b_Pitch_pf32, float32_t* b_Yaw_pf32, float32_t* b_Roll_pf32);

// Gets the camera Pre Roll and Rotation Type (Extrinsic)
bool_t ME_VariantHelper_GetCameraPreRollAndRotType_b(Camera_t i_Camera_t, PreRoll_t* b_PreRoll_pt, RotationType_t* b_RotType_pt);

// Gets the camera focal Length (Intrinsic)
bool_t ME_VariantHelper_GetCameraFocalLength_b(Camera_t i_Camera_t, float32_t* b_FocalLengthX_pf32, float32_t* b_FocalLengthY_pf32);

// Gets the camera Sensor PrincipalPoint (Intrinsic)
bool_t ME_VariantHelper_GetCameraPrincipalPoint_b(Camera_t i_Camera_t, float32_t* b_PrincipalPointX_pf32, float32_t* b_PrincipalPointY_pf32);

// Gets the camera Sensor Pixel Size (Intrinsic)
bool_t ME_VariantHelper_GetCameraPixelSize_b(Camera_t i_Camera_t, float32_t* b_PixelSizeX_pf32, float32_t* b_PixelSizeY_pf32);

// Gets the camera Sensor Image Origin (intrinsic)
bool_t ME_VariantHelper_GetCameraImageOrigin_b(Camera_t i_Camera_t, ImageOriginPosition_t* b_ImageOrigin_pt);

// Gets the camera Sensor Top left Area (intrinsic)
bool_t ME_VariantHelper_GetCameraSensorAreaTopLeft_b(Camera_t i_Camera_t, float32_t* b_X_pf32, float32_t* b_Y_pf32);

// Gets the camera Sensor Bottom Right Area (intrinsic)
bool_t ME_VariantHelper_GetCameraSensorAreaBottomRight_b(Camera_t i_Camera_t, float32_t* b_X_pf32, float32_t* b_Y_pf32);

// Gets the Camera Radial Lens World To Image Polynomial
bool_t ME_VariantHelper_GetCameraLensWorldToImage_b(Camera_t i_Camera_t, float32_t* b_Polynomial_paf32, uint32_t i_PolySize_u32);

// Gets the Camera Radial Lens Image To World Polynomial
bool_t ME_VariantHelper_GetCameraLensImageToWorld_b(Camera_t i_Camera_t, float32_t* b_Polynomial_paf32, uint32_t i_PolySize_u32);

// Gets the Camera Radial Lens maximum elevation
bool_t ME_VariantHelper_GetCameraLensMaxElevation_b(Camera_t i_Camera_t, float32_t* b_MaxElevation_pf32);


// --------------------------------- Vehicle Data Specific --------------------------------------

// Gets the Vehicle Data GUID of a given variant
uint32_t ME_VariantHelper_GetVehicleDataGUID_u32();

// Gets the Wheelbase for a given variant
bool_t ME_VariantHelper_GetWheelBase_b(float32_t* b_WheelBase_pf32);

// Gets the front and rear bumper X position for a given variant
bool_t ME_VariantHelper_GetFrontAndRearBumperPosX_b(float32_t* b_FrontBumperPosX_pf32, float32_t* b_RearBumperPosX_pf32);

// Gets the left and right mirror Y position for a given variant
bool_t ME_VariantHelper_GetLeftAndRightMirrorPosY_b(float32_t* b_RightMirrorPosY_pf32, float32_t* b_LeftMirrorPosY_pf32);

// Get the vehicle width at fender for a given variant
bool_t ME_VariantHelper_GetVehicleWidthAtFender_b(float32_t* b_VehicleWidthAtFender_pf32);

// Gets the front and rear bumper projection offset for a given variant
bool_t ME_VariantHelper_GetFrontAndRearBumperProjOffset_b(float32_t* b_FrontBumperProjOffset_pf32, float32_t* b_RearBumperProjOffset_pf32);

// Gets the bed end pos X and Z for a given variant
bool_t ME_VariantHelper_GetBedEndPos_b(float32_t* b_BedEndPosX_pf32, float32_t* b_BedEndPosZ_pf32);


// --------------------------------- Online calibration --------------------------------------
uint32_t ME_VariantHelper_GetAllCameraBits_u32 (void);

uint32_t ME_VariantHelper_MapCamera2Bits_u32 ( const Camera_t i_Camera_t );

Camera_t ME_VariantHelper_MapBits2Camera_t ( const uint32_t i_CameraBits_u32 );

bool_t ME_VariantHelper_IsEnabled_b ( const uint32_t i_CameraBits_u32, const Camera_t i_Camera_t );
  

uint32_t ME_VariantHelper_GetEOLGUID_u32(Camera_t i_Camera_t);

uint32_t ME_VariantHelper_GetOCGUID_u32(Camera_t i_Camera_t);

uint32_t ME_VariantHelper_GetSCGUID_u32(Camera_t i_Camera_t);

bool_t ME_VariantHelper_GetRadioDisp_b(uint8_t* radio_val);
bool_t ME_VariantHelper_GetVariantID_b(uint8_t* var_id);


#ifdef __cplusplus
} // extern "C" 
} // namespace variants
#endif  


#endif
