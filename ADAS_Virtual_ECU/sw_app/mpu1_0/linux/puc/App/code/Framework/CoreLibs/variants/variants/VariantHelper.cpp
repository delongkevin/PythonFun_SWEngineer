//--------------------------------------------------------------------------
/// @file VariantHelper.c
/// @brief Acts as c/cpp bridge for variant data. Provides methods for easier access
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
// PRQA S 3710 EOF // Osal file handling

#include "VariantHelper.h"

#include <osal/io/File.h>
#include <osal/io/InOut.h>
#include <osal/io/MemoryFile.h>
#include "Components.h"
#include "Assets.h"
#include "fsdata/fsdata.h"
#include "ProxiParameters.h"

namespace variants // also add the namespace for Enumerations and easier access.
{


uint32_t ME_VariantHelper_GetAllCameraBits_u32 (void)
{
  const uint32_t c_AllCameras_u32 = (( 1U << static_cast < uint32_t >( variants :: e_CameraFront )) |
                                     ( 1U << static_cast < uint32_t >( variants :: e_CameraLeft  )) |
                                     ( 1U << static_cast < uint32_t >( variants :: e_CameraRear  )) |
                                     ( 1U << static_cast < uint32_t >( variants :: e_CameraRight )) |
                                     ( 1U << static_cast < uint32_t >( variants :: e_CameraChmsl ))
                                    );
  return c_AllCameras_u32;
}


uint32_t ME_VariantHelper_MapCamera2Bits_u32 ( const variants :: Camera_t i_Camera_t )
{
  uint32_t v_Camera_u32 = 0;

  if ( i_Camera_t >= variants :: e_CameraCount )
  {
    v_Camera_u32 = ME_VariantHelper_GetAllCameraBits_u32();
  }
  else
  {
    v_Camera_u32 = ( 1U << static_cast < uint32_t >( i_Camera_t ));
  }
  return v_Camera_u32;
}



Camera_t ME_VariantHelper_MapBits2Camera_t ( const uint32_t i_CameraBits_u32 )
  {
    variants :: Camera_t v_Camera_t = variants :: e_CameraInvalid;

    if ( i_CameraBits_u32 == ME_VariantHelper_GetAllCameraBits_u32())
    {
      v_Camera_t = variants :: e_CameraCount;
    }
    else
    {
      for ( uint16_t v_Ix_u16 = 0 ; v_Ix_u16 < static_cast < uint16_t >( variants :: e_CameraCount ) ; v_Ix_u16++ )
      {
        bool_t v_Erg_b = ME_VariantHelper_IsEnabled_b ( i_CameraBits_u32, static_cast < variants :: Camera_t >( v_Ix_u16 ));
        if (  v_Erg_b == true  )
        {
          v_Camera_t = static_cast < variants :: Camera_t >( v_Ix_u16 );
          break;
        }
      }
    }
    return v_Camera_t;
  }



  bool_t ME_VariantHelper_IsEnabled_b ( const uint32_t i_CameraBits_u32, const Camera_t i_Camera_t )
  {
    const uint32_t c_Temp_u32 = ME_VariantHelper_MapCamera2Bits_u32( i_Camera_t );
    return (( i_CameraBits_u32 & c_Temp_u32) != 0 ) ? true : false;
  }


uint32_t ME_VariantHelper_GetCameraGUID_u32(Camera_t i_Camera_t)
{
  const VariantConfig* v_Config_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_CameraGUID_u32 = c_InvalidGUID_u32;

  if (true == v_Success_b)
  {
    v_Config_po = VariantConfig::get_po(c_VariantConfig_u32);
    v_Success_b = (NULL != v_Config_po);
    if (true == v_Success_b)
    {
      // get the linked GUID for this variant and camera
      v_CameraGUID_u32 = v_Config_po->getCompVariantConfig_po()->getCams_ps()[i_Camera_t].camLink_u32;
    }
  }

  return v_CameraGUID_u32;
}


uint32_t ME_VariantHelper_GetEOLGUID_u32(Camera_t i_Camera_t)
{
  const VariantConfig* v_Config_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_EOLGUID_u32 = c_InvalidGUID_u32;

  if (true == v_Success_b)
  {
    v_Config_po = VariantConfig::get_po(c_VariantConfig_u32);
    v_Success_b = (NULL != v_Config_po);
    if (true == v_Success_b)
    {
      // get the linked GUID for this variant and camera
        v_EOLGUID_u32 = v_Config_po->getCompVariantConfig_po()->getCams_ps()[i_Camera_t].eolcalibrationLink_u32;
    }
  }
  return v_EOLGUID_u32;
}


uint32_t ME_VariantHelper_GetOCGUID_u32(Camera_t i_Camera_t)
{
  const VariantConfig* v_Config_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_OCGUID_u32 = c_InvalidGUID_u32;

  if (true == v_Success_b)
  {
    v_Config_po = VariantConfig::get_po(c_VariantConfig_u32);
    v_Success_b = (NULL != v_Config_po);
    if (true == v_Success_b)
    {
      // get the linked GUID for this variant and camera
      v_OCGUID_u32 = v_Config_po->getCompVariantConfig_po()->getCams_ps()[i_Camera_t].ocCalibrationLink_u32;
    }
  }
  return v_OCGUID_u32;
}


uint32_t ME_VariantHelper_GetSCGUID_u32(Camera_t i_Camera_t)
{
  const VariantConfig* v_Config_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_SCGUID_u32 = c_InvalidGUID_u32;

  if (true == v_Success_b)
  {
    v_Config_po = VariantConfig::get_po(c_VariantConfig_u32);
    v_Success_b = (NULL != v_Config_po);
    if (true == v_Success_b)
    {
      // get the linked GUID for this variant and camera
        v_SCGUID_u32 = v_Config_po->getCompVariantConfig_po()->getCams_ps()[i_Camera_t].scCalibrationLink_u32;
    }
  }
  return v_SCGUID_u32;
}


const char_t* ME_VariantHelper_GetVariantIdFilePath_pc()
{
  static const char_t* s_FilePath_pc = "/fs/variants/VarData.version";
  return s_FilePath_pc;
}

// PRQA S 2642 1 // intended, forced to call only internally, helper to load and verify the header
bool_t ME_VariantHelper_LoadHeader_b(osal::InOut& b_IO_ro)
{
  bool_t v_Success_b = true;

  uint32_t v_HeaderSize_u32 = 0;
  uint32_t v_PayloadSize_u32 = 0;
  uint32_t v_Version_u32 = 0;
  uint32_t v_Reserved_u32 = 0;

  b_IO_ro.serialize_v<uint32_t>(v_HeaderSize_u32);
  b_IO_ro.serialize_v<uint32_t>(v_PayloadSize_u32);
  b_IO_ro.serialize_v<uint32_t>(v_Version_u32);
  b_IO_ro.serialize_v<uint32_t>(v_Reserved_u32);

  return v_Success_b;
}

bool_t ME_VariantHelper_LoadFromFile_b(const char_t* i_FileName_pc)
{
  // load from file system
  osal::File v_File_o;
  osal::InOut v_IO_o;
  bool_t v_Success_b = v_File_o.open_b(i_FileName_pc, e_FomRead | e_FomBinary);

  // create io structure
  if (true == v_Success_b)
  {
    // create io structure
    v_Success_b = v_IO_o.create_b(&v_File_o, true);

    // Load Header
    if (true == v_Success_b)
    {
      v_Success_b = ME_VariantHelper_LoadHeader_b(v_IO_o);
    }

    // serialize all variant data
    if (true == v_Success_b)
    {
      // call assets serialize method
      variants::serialize_v(v_IO_o);
    }
    v_File_o.close_b();
  }

  return v_Success_b;
}

bool_t ME_VariantHelper_LoadFromMemory_b(uint8_t* i_Data_pu8, const uint32_t i_DataSize_u32)
{
  // load from memory
  osal::MemoryFile v_File_o;
  osal::InOut v_IO_o;

  bool_t v_Success_b = v_File_o.open_b(i_Data_pu8, i_DataSize_u32, true);

  // create io structure
  if (true == v_Success_b)
  {
    // create io structure
    v_Success_b = v_IO_o.create_b(&v_File_o, true);

    // Load Header
    if (true == v_Success_b)
    {
      v_Success_b = ME_VariantHelper_LoadHeader_b(v_IO_o);
    }

    // serialize all variant data
    if (true == v_Success_b)
    {
      // call assets serialize method
      variants::serialize_v(v_IO_o);
    }
    v_File_o.close_b();
  }

  return v_Success_b;
}

bool_t ME_VariantHelper_GetCameraPosition_b(Camera_t i_Camera_t, float32_t* b_X_pf32, float32_t* b_Y_pf32, float32_t* b_Z_pf32)
{
  const CameraRadialLens* v_CamRad_po = NULL;
  const PinholeComponent* v_Pinhole_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_CamGUID_u32 = ME_VariantHelper_GetCameraGUID_u32( i_Camera_t);

  // check if it's a radial lens camera
  v_CamRad_po = CameraRadialLens::get_po(v_CamGUID_u32);
  v_Success_b = (NULL != v_CamRad_po);
  if (true == v_Success_b)
  {
    v_Pinhole_po = v_CamRad_po->getPinholeComponent_po();
    v_Success_b = (NULL != v_Pinhole_po);
    if (true == v_Success_b)
    {
      // X
      if (NULL != b_X_pf32)
      {
        *b_X_pf32 = v_Pinhole_po->getExtrinsic_rs().posX_f32;
      }

      // Y
      if (NULL != b_Y_pf32)
      {
        *b_Y_pf32 = v_Pinhole_po->getExtrinsic_rs().posY_f32;
      }

      // Z
      if (NULL != b_Z_pf32)
      {
        *b_Z_pf32 = v_Pinhole_po->getExtrinsic_rs().posZ_f32;
      }
    }
  }
  // else it might be a different camera or wrong cam link


  return v_Success_b;
}

bool_t ME_VariantHelper_GetCameraRotation_b(Camera_t i_Camera_t, float32_t* b_Pitch_pf32, float32_t* b_Yaw_pf32, float32_t* b_Roll_pf32)
{
  const CameraRadialLens* v_CamRad_po = NULL;
  const PinholeComponent* v_Pinhole_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_CamGUID_u32 = ME_VariantHelper_GetCameraGUID_u32( i_Camera_t);

  // check if it's a radial lens camera
  v_CamRad_po = CameraRadialLens::get_po(v_CamGUID_u32);
  v_Success_b = (NULL != v_CamRad_po);
  if (true == v_Success_b)
  {
    v_Pinhole_po = v_CamRad_po->getPinholeComponent_po();
    v_Success_b = (NULL != v_Pinhole_po);
    if (true == v_Success_b)
    {
      if (NULL != b_Pitch_pf32)
      {
        *b_Pitch_pf32 = v_Pinhole_po->getExtrinsic_rs().pitch_f32;
      }

      if (NULL != b_Yaw_pf32)
      {
        *b_Yaw_pf32 = v_Pinhole_po->getExtrinsic_rs().yaw_f32;
      }

      if (NULL != b_Roll_pf32)
      {
        *b_Roll_pf32 = v_Pinhole_po->getExtrinsic_rs().roll_f32;
      }
    }
  }

  return v_Success_b;
}

bool_t ME_VariantHelper_GetCameraPreRollAndRotType_b(Camera_t i_Camera_t, PreRoll_t* b_PreRoll_pt, RotationType_t* b_RotType_pt)
{
  const CameraRadialLens* v_CamRad_po = NULL;
  const PinholeComponent* v_Pinhole_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_CamGUID_u32 = ME_VariantHelper_GetCameraGUID_u32( i_Camera_t);

  // check if it's a radial lens camera
  v_CamRad_po = CameraRadialLens::get_po(v_CamGUID_u32);
  v_Success_b = (NULL != v_CamRad_po);
  if (true == v_Success_b)
  {
    v_Pinhole_po = v_CamRad_po->getPinholeComponent_po();
    v_Success_b = (NULL != v_Pinhole_po);
    if (true == v_Success_b)
    {
      if (NULL != b_PreRoll_pt)
      {
        *b_PreRoll_pt = v_Pinhole_po->getExtrinsic_rs().preRoll_e;
      }

      if (NULL != b_RotType_pt)
      {
        *b_RotType_pt = v_Pinhole_po->getExtrinsic_rs().rotationType_e;
      }
    }
  }

  return v_Success_b;
}

bool_t ME_VariantHelper_GetCameraFocalLength_b(Camera_t i_Camera_t, float32_t* b_FocalLengthX_pf32, float32_t* b_FocalLengthY_pf32)
{
  const CameraRadialLens* v_CamRad_po = NULL;
  const PinholeComponent* v_Pinhole_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_CamGUID_u32 = ME_VariantHelper_GetCameraGUID_u32( i_Camera_t);

  // check if it's a radial lens camera
  v_CamRad_po = CameraRadialLens::get_po(v_CamGUID_u32);
  v_Success_b = (NULL != v_CamRad_po);
  if (true == v_Success_b)
  {
    v_Pinhole_po = v_CamRad_po->getPinholeComponent_po();
    v_Success_b = (NULL != v_Pinhole_po);
    if (true == v_Success_b)
    {
      if (NULL != b_FocalLengthX_pf32)
      {
        *b_FocalLengthX_pf32 = v_Pinhole_po->getIntrinsic_rs().focalLengthX_f32;
      }

      if (NULL != b_FocalLengthY_pf32)
      {
        *b_FocalLengthY_pf32 = v_Pinhole_po->getIntrinsic_rs().focalLengthY_f32;
      }
    }
  }

  return v_Success_b;
}

bool_t ME_VariantHelper_GetCameraPrincipalPoint_b(Camera_t i_Camera_t, float32_t* b_PrincipalPointX_pf32, float32_t* b_PrincipalPointY_pf32)
{
  const CameraRadialLens* v_CamRad_po = NULL;
  const PinholeComponent* v_Pinhole_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_CamGUID_u32 = ME_VariantHelper_GetCameraGUID_u32( i_Camera_t);

  // check if it's a radial lens camera
  v_CamRad_po = CameraRadialLens::get_po(v_CamGUID_u32);
  v_Success_b = (NULL != v_CamRad_po);
  if (true == v_Success_b)
  {
    v_Pinhole_po = v_CamRad_po->getPinholeComponent_po();
    v_Success_b = (NULL != v_Pinhole_po);
    if (true == v_Success_b)
    {
      if (NULL != b_PrincipalPointX_pf32)
      {
        *b_PrincipalPointX_pf32 = v_Pinhole_po->getIntrinsic_rs().principalPointX_f32;
      }

      if (NULL != b_PrincipalPointY_pf32)
      {
        *b_PrincipalPointY_pf32 = v_Pinhole_po->getIntrinsic_rs().principalPointY_f32;
      }
    }
  }

  return v_Success_b;
}


bool_t ME_VariantHelper_GetCameraPixelSize_b(Camera_t i_Camera_t, float32_t* b_PixelSizeX_pf32, float32_t* b_PixelSizeY_pf32)
{
  const CameraRadialLens* v_CamRad_po = NULL;
  const PinholeComponent* v_Pinhole_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_CamGUID_u32 = ME_VariantHelper_GetCameraGUID_u32( i_Camera_t);

  // check if it's a radial lens camera
  v_CamRad_po = CameraRadialLens::get_po(v_CamGUID_u32);
  v_Success_b = (NULL != v_CamRad_po);
  if (true == v_Success_b)
  {
    v_Pinhole_po = v_CamRad_po->getPinholeComponent_po();
    v_Success_b = (NULL != v_Pinhole_po);
    if (true == v_Success_b)
    {
      if (NULL != b_PixelSizeX_pf32)
      {
        *b_PixelSizeX_pf32 = v_Pinhole_po->getIntrinsic_rs().pixelSizeX_f32;
      }

      if (NULL != b_PixelSizeY_pf32)
      {
        *b_PixelSizeY_pf32 = v_Pinhole_po->getIntrinsic_rs().pixelSizeY_f32;
      }
    }
  }

  return v_Success_b;
}

bool_t ME_VariantHelper_GetCameraImageOrigin_b(Camera_t i_Camera_t, ImageOriginPosition_t* b_ImageOrigin_pt)
{
  const CameraRadialLens* v_CamRad_po = NULL;
  const PinholeComponent* v_Pinhole_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_CamGUID_u32 = ME_VariantHelper_GetCameraGUID_u32( i_Camera_t);

  // check if it's a radial lens camera
  v_CamRad_po = CameraRadialLens::get_po(v_CamGUID_u32);
  v_Success_b = (NULL != v_CamRad_po);
  if (true == v_Success_b)
  {
    v_Pinhole_po = v_CamRad_po->getPinholeComponent_po();
    v_Success_b = (NULL != v_Pinhole_po);
    if (true == v_Success_b)
    {
      if (NULL != b_ImageOrigin_pt)
      {
        *b_ImageOrigin_pt = v_Pinhole_po->getIntrinsic_rs().imageOrigin_e;
      }
    }
  }

  return v_Success_b;
}

bool_t ME_VariantHelper_GetCameraSensorAreaTopLeft_b(Camera_t i_Camera_t, float32_t* b_X_pf32, float32_t* b_Y_pf32)
{
  const CameraRadialLens* v_CamRad_po = NULL;
  const PinholeComponent* v_Pinhole_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_CamGUID_u32 = ME_VariantHelper_GetCameraGUID_u32( i_Camera_t);

  // check if it's a radial lens camera
  v_CamRad_po = CameraRadialLens::get_po(v_CamGUID_u32);
  v_Success_b = (NULL != v_CamRad_po);
  if (true == v_Success_b)
  {
    v_Pinhole_po = v_CamRad_po->getPinholeComponent_po();
    v_Success_b = (NULL != v_Pinhole_po);
    if (true == v_Success_b)
    {
      if (NULL != b_X_pf32)
      {
        *b_X_pf32 = v_Pinhole_po->getIntrinsic_rs().sensorAreaTopLeftX_f32;
      }

      if (NULL != b_Y_pf32)
      {
        *b_Y_pf32 = v_Pinhole_po->getIntrinsic_rs().sensorAreaTopLeftY_f32;
      }

    }
  }

  return v_Success_b;
}


bool_t ME_VariantHelper_GetCameraSensorAreaBottomRight_b(Camera_t i_Camera_t, float32_t* b_X_pf32, float32_t* b_Y_pf32)
{
  const CameraRadialLens* v_CamRad_po = NULL;
  const PinholeComponent* v_Pinhole_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_CamGUID_u32 = ME_VariantHelper_GetCameraGUID_u32( i_Camera_t);

  // check if it's a radial lens camera
  v_CamRad_po = CameraRadialLens::get_po(v_CamGUID_u32);
  v_Success_b = (NULL != v_CamRad_po);
  if (true == v_Success_b)
  {
    v_Pinhole_po = v_CamRad_po->getPinholeComponent_po();
    v_Success_b = (NULL != v_Pinhole_po);
    if (true == v_Success_b)
    {
      if (NULL != b_X_pf32)
      {
        *b_X_pf32 = v_Pinhole_po->getIntrinsic_rs().sensorAreaBottomRightX_f32;
      }

      if (NULL != b_Y_pf32)
      {
        *b_Y_pf32 = v_Pinhole_po->getIntrinsic_rs().sensorAreaBottomRightY_f32;
      }

    }
  }

  return v_Success_b;
}

bool_t ME_VariantHelper_GetCameraLensWorldToImage_b(Camera_t i_Camera_t, float32_t* b_Polynomial_paf32, uint32_t i_PolySize_u32)
{
  const CameraRadialLens* v_CamRad_po = NULL;
  const LensRadialComponent* v_Lens_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_CamGUID_u32 = ME_VariantHelper_GetCameraGUID_u32( i_Camera_t);

  // check if it's a radial lens camera
  v_CamRad_po = CameraRadialLens::get_po(v_CamGUID_u32);
  v_Success_b = (NULL != v_CamRad_po);
  if (true == v_Success_b)
  {
    v_Lens_po = v_CamRad_po->getLensRadialComponent_po();
    v_Success_b = (NULL != v_Lens_po);
    if (true == v_Success_b)
    {
      v_Success_b = (i_PolySize_u32 >= e_CoefficientsCount);
      if (true == v_Success_b)
      {
        // assign array members
        for (uint32_t v_I_u32 = 0U; v_I_u32 < i_PolySize_u32; ++v_I_u32)
        {
          b_Polynomial_paf32[v_I_u32] = v_Lens_po->getWorld2Image_ps()[v_I_u32].coeff_f32;
        }
      }
    }
  }

  return v_Success_b;
}

bool_t ME_VariantHelper_GetCameraLensImageToWorld_b(Camera_t i_Camera_t, float32_t* b_Polynomial_paf32, uint32_t i_PolySize_u32)
{
  const CameraRadialLens* v_CamRad_po = NULL;
  const LensRadialComponent* v_Lens_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_CamGUID_u32 = ME_VariantHelper_GetCameraGUID_u32( i_Camera_t);

  // check if it's a radial lens camera
  v_CamRad_po = CameraRadialLens::get_po(v_CamGUID_u32);
  v_Success_b = (NULL != v_CamRad_po);
  if (true == v_Success_b)
  {
    v_Lens_po = v_CamRad_po->getLensRadialComponent_po();
    v_Success_b = (NULL != v_Lens_po);
    if (true == v_Success_b)
    {
      v_Success_b = (i_PolySize_u32 >= e_CoefficientsCount);
      if (true == v_Success_b)
      {
        // assign array members
        for (uint32_t v_I_u32 = 0U; v_I_u32 < i_PolySize_u32; ++v_I_u32)
        {
          b_Polynomial_paf32[v_I_u32] = v_Lens_po->getImage2World_ps()[v_I_u32].coeff_f32;
        }
      }
    }
  }

  return v_Success_b;
}

bool_t ME_VariantHelper_GetCameraLensMaxElevation_b(Camera_t i_Camera_t, float32_t* b_MaxElevation_pf32)
{
  const CameraRadialLens* v_CamRad_po = NULL;
  const LensRadialComponent* v_Lens_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_CamGUID_u32 = ME_VariantHelper_GetCameraGUID_u32( i_Camera_t);

  // check if it's a radial lens camera
  v_CamRad_po = CameraRadialLens::get_po(v_CamGUID_u32);
  v_Success_b = (NULL != v_CamRad_po);
  if (true == v_Success_b)
  {
    v_Lens_po = v_CamRad_po->getLensRadialComponent_po();
    v_Success_b = (NULL != v_Lens_po);
    if (true == v_Success_b)
    {
      if (NULL != b_MaxElevation_pf32)
      {
        *b_MaxElevation_pf32 = v_Lens_po->getElevationMax_f32();
      }
    }
  }

  return v_Success_b;
}


uint32_t ME_VariantHelper_GetVehicleDataGUID_u32()
{
  const VariantConfig* v_Config_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_VehicleDataGUID_u32 = c_InvalidGUID_u32;

  if (true == v_Success_b)
  {
    // get variant config Asset
    v_Config_po = VariantConfig::get_po(c_VariantConfig_u32);
    v_Success_b = (NULL != v_Config_po);

    if (true == v_Success_b)
    {
      // get the linked GUID for this vehicle
      v_VehicleDataGUID_u32 = v_Config_po->getCompVariantConfig_po()->getVehicleDataLink_u32();
    }
  }

  return v_VehicleDataGUID_u32;
}



bool_t ME_VariantHelper_GetWheelBase_b(float32_t* b_WheelBase_pf32)
{
  const VehicleData* v_VehicleData_po = NULL;
  const CompVehicleData* v_VehicleDataComp_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_VehicleDataGUID_u32 = ME_VariantHelper_GetVehicleDataGUID_u32();

  // get Vehicle Data Asset
  v_VehicleData_po = VehicleData::get_po(v_VehicleDataGUID_u32);
  v_Success_b = (NULL != v_VehicleData_po);
  if (true == v_Success_b)
  {
    // get Vehicle Data Component
      v_VehicleDataComp_po = v_VehicleData_po->getCompVehicleData_po();
    v_Success_b = (NULL != v_VehicleDataComp_po);
    if (true == v_Success_b)
    {
      if (NULL != b_WheelBase_pf32)
      {
        *b_WheelBase_pf32 = v_VehicleDataComp_po->getWheelBase_f32();
      }
    }
  }

  return v_Success_b;
}

bool_t ME_VariantHelper_GetFrontAndRearBumperPosX_b(float32_t* b_FrontBumperPosX_pf32, float32_t* b_RearBumperPosX_pf32)
{
  const VehicleData* v_VehicleData_po = NULL;
  const CompVehicleData* v_VehicleDataComp_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_VehicleDataGUID_u32 = ME_VariantHelper_GetVehicleDataGUID_u32();

  // get Vehicle Data Asset
  v_VehicleData_po = VehicleData::get_po(v_VehicleDataGUID_u32);
  v_Success_b = (NULL != v_VehicleData_po);
  if (true == v_Success_b)
  {
    // get Vehicle Data Component
      v_VehicleDataComp_po = v_VehicleData_po->getCompVehicleData_po();
    v_Success_b = (NULL != v_VehicleDataComp_po);
    if (true == v_Success_b)
    {
      if (NULL != b_FrontBumperPosX_pf32)
      {
        *b_FrontBumperPosX_pf32 = v_VehicleDataComp_po->getFrontBumperPosX_f32();
      }

      if (NULL != b_RearBumperPosX_pf32)
      {
        *b_RearBumperPosX_pf32 = v_VehicleDataComp_po->getRearBumperPosX_f32();
      }
    }
  }

  return v_Success_b;
}


bool_t ME_VariantHelper_GetLeftAndRightMirrorPosY_b(float32_t* b_RightMirrorPosY_pf32, float32_t* b_LeftMirrorPosY_pf32)
{
  const VehicleData* v_VehicleData_po = NULL;
  const CompVehicleData* v_VehicleDataComp_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_VehicleDataGUID_u32 = ME_VariantHelper_GetVehicleDataGUID_u32();

  // get Vehicle Data Asset
  v_VehicleData_po = VehicleData::get_po(v_VehicleDataGUID_u32);
  v_Success_b = (NULL != v_VehicleData_po);
  if (true == v_Success_b)
  {
    // get Vehicle Data Component
    v_VehicleDataComp_po = v_VehicleData_po->getCompVehicleData_po();
    v_Success_b = (NULL != v_VehicleDataComp_po);
    if (true == v_Success_b)
    {
      if (NULL != b_RightMirrorPosY_pf32)
      {
        *b_RightMirrorPosY_pf32 = v_VehicleDataComp_po->getRightMirrorPosY_f32();
      }

      if (NULL != b_LeftMirrorPosY_pf32)
      {
        *b_LeftMirrorPosY_pf32 = v_VehicleDataComp_po->getLeftMirrorPosY_f32();
      }
    }
  }

  return v_Success_b;
}

bool_t ME_VariantHelper_GetVehicleWidthAtFender_b(float32_t* b_VehicleWidthAtFender_pf32)
{
  const VehicleData* v_VehicleData_po = NULL;
  const CompVehicleData* v_VehicleDataComp_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_VehicleDataGUID_u32 = ME_VariantHelper_GetVehicleDataGUID_u32();

  // get Vehicle Data Asset
  v_VehicleData_po = VehicleData::get_po(v_VehicleDataGUID_u32);
  v_Success_b = (NULL != v_VehicleData_po);
  if (true == v_Success_b)
  {
    // get Vehicle Data Component
    v_VehicleDataComp_po = v_VehicleData_po->getCompVehicleData_po();
    v_Success_b = (NULL != v_VehicleDataComp_po);
    if (true == v_Success_b)
    {
      if (NULL != b_VehicleWidthAtFender_pf32)
      {
        *b_VehicleWidthAtFender_pf32 = v_VehicleDataComp_po->getVehicleWidthAtFender_f32();
      }
    }
  }

  return v_Success_b;
}

bool_t ME_VariantHelper_GetFrontAndRearBumperProjOffset_b(float32_t* b_FrontBumperProjOffset_pf32, float32_t* b_RearBumperProjOffset_pf32)
{
  const VehicleData* v_VehicleData_po = NULL;
  const CompVehicleData* v_VehicleDataComp_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_VehicleDataGUID_u32 = ME_VariantHelper_GetVehicleDataGUID_u32();

  // get Vehicle Data Asset
  v_VehicleData_po = VehicleData::get_po(v_VehicleDataGUID_u32);
  v_Success_b = (NULL != v_VehicleData_po);
  if (true == v_Success_b)
  {
    // get Vehicle Data Component
    v_VehicleDataComp_po = v_VehicleData_po->getCompVehicleData_po();
    v_Success_b = (NULL != v_VehicleDataComp_po);
    if (true == v_Success_b)
    {
      if (NULL != b_FrontBumperProjOffset_pf32)
      {
        *b_FrontBumperProjOffset_pf32 = v_VehicleDataComp_po->getFrontBumperProjectionOffset_f32();
      }
      if (NULL != b_RearBumperProjOffset_pf32)
      {
        *b_RearBumperProjOffset_pf32 = v_VehicleDataComp_po->getRearBumperProjectionOffset_f32();
      }
    }
  }

  return v_Success_b;
}

bool_t ME_VariantHelper_GetBedEndPos_b(float32_t* b_BedEndPosX_pf32, float32_t* b_BedEndPosZ_pf32)
{
  const VehicleData* v_VehicleData_po = NULL;
  const CompVehicleData* v_VehicleDataComp_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_VehicleDataGUID_u32 = ME_VariantHelper_GetVehicleDataGUID_u32();

  // get Vehicle Data Asset
  v_VehicleData_po = VehicleData::get_po(v_VehicleDataGUID_u32);
  v_Success_b = (NULL != v_VehicleData_po);
  if (true == v_Success_b)
  {
    // get Vehicle Data Component
    v_VehicleDataComp_po = v_VehicleData_po->getCompVehicleData_po();
    v_Success_b = (NULL != v_VehicleDataComp_po);
    if (true == v_Success_b)
    {
      if (NULL != b_BedEndPosX_pf32)
      {
        *b_BedEndPosX_pf32 = v_VehicleDataComp_po->getBedEndPosX_f32();
      }
      if (NULL != b_BedEndPosZ_pf32)
      {
        *b_BedEndPosZ_pf32 = v_VehicleDataComp_po->getBedEndPosZ_f32();
      }
    }
  }

  return v_Success_b;
}

bool_t ME_VariantHelper_GetVariantID_b(uint8_t* var_id)
{
	uint16_t v_VariantId_u8 = 8U; // set default variant id
	osal::File v_File_o;
	bool_t v_Success_b = true;
	uint8_t *dptr = (uint8_t*)&v_VariantId_u8;
	ME_Proxi_MPU1_0_to_MCU1_0_t proxi_req;

	if(false == fsdata::fsdata_read_data(variants::ME_VariantHelper_GetVariantIdFilePath_pc(),(char*)&proxi_req,sizeof(proxi_req)))
	{
		v_Success_b = false;
		printf("variantHelper: Read from file failed\n");
	}
	else
	{
		*var_id = proxi_req.PRX_variantID_u8;
	}
return v_Success_b;

//	if (true == v_File_o.open_b(ME_VariantHelper_GetVariantIdFilePath_pc(), e_FomRead  | e_FomBinary))
//	{
//		uint64_t v_NumBytesRead_u64 = v_File_o.read_u64(reinterpret_cast<void*>(&v_VariantId_u8), sizeof(v_VariantId_u8));
//
//		*var_id = (dptr[0] - '0')*10;
//		*var_id += dptr[1] - '0';
//
//		v_File_o.close_b();
//	}
//	else
//	{
//		v_Success_b = false;
//	}
}

bool_t ME_VariantHelper_GetRadioDisp_b(uint8_t* radio_val)
{
	uint64_t temp = 0U;
	osal::File v_File_o;
	uint8_t *dptr = (uint8_t*)&temp;
	  bool_t v_Success_b = true;
		ME_Proxi_MPU1_0_to_MCU1_0_t proxi_req;

		if(false == fsdata::fsdata_read_data(variants::ME_VariantHelper_GetVariantIdFilePath_pc(),(char*)&proxi_req,sizeof(proxi_req)))
		{
			v_Success_b = false;
			printf("variantHelper: Read from file failed\n");
		}
		else
		{
			*radio_val = proxi_req.PRX_RadioDispTyp_u8;
		}
return v_Success_b;

//	if (true == v_File_o.open_b(ME_VariantHelper_GetVariantIdFilePath_pc(), e_FomRead  | e_FomBinary))
//	{
//		uint64_t v_NumBytesRead_u64 = v_File_o.read_u64(reinterpret_cast<void*>(&temp), sizeof(temp));
//
//		*radio_val = (dptr[3] - '0')*10;
//		*radio_val += dptr[4] - '0';
//    ME_Debugger_F_Printf_v("Value of radio_val : %d\n", radio_val);
//
//		v_File_o.close_b();
//	}
//	else
//	{
//		v_Success_b = false;
//	}
//  return v_Success_b;
}


#if 0
//----------------------------------------------------------------------------------------------------------
// Author: Detlef Hafer
bool_t ME_VariantHelper_GetOCKinematics_b( VarOCKinematics_t* o_Kinematics_pt)
{
  const KinematicsOC* v_KinematicsOC_po = NULL;
  const CompKinematics* v_CompKinematics_po = NULL;
  bool_t v_Success_b = true;
  uint32_t v_KinematicsGUID_u32 = ME_VariantHelper_GetOCKinematicsDataGUID_u32();

  // get Vehicle Data Asset
  v_KinematicsOC_po = KinematicsOC::get_po(v_KinematicsGUID_u32);
  v_Success_b = (NULL != v_KinematicsOC_po);
  if (true == v_Success_b)
  {
      // get Vehicle Data Component
      v_CompKinematics_po = v_KinematicsOC_po->getCompKinematics_po();
      v_Success_b = (NULL != v_CompKinematics_po);
      if (true == v_Success_b)
      {
        if (NULL != o_Kinematics_pt)
        {
            o_Kinematics_pt->distanceCoG2FrontAxis_f32      = v_CompKinematics_po->getProperties_rs().distanceCoG2FrontAxis_f32;
            o_Kinematics_pt->distanceCoG2RearAxis_f32       = v_CompKinematics_po->getProperties_rs().distanceCoG2RearAxis_f32;
            o_Kinematics_pt->tireCircumferencePerPulse_f32 = v_CompKinematics_po->getProperties_rs().tireCircumferencePerPulse_f32;
        }
      }
  }
  return v_Success_b;
}
#endif


} // namespace variants
