//--------------------------------------------------------------------------
/// @file FpgaViewGenConfig.cpp
/// @brief Implementation of Fpga ViewGen Configuration structure
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#include "bsp/io/fpga/FpgaViewGenConfig.h"
#include "bsp/io/fpga/FpgaHelper.h"

#ifdef ME_PLATFORM_WIN

namespace bsp
{

  ViewGenConfig::ViewGenConfig()
    : axiLite_pv(NULL)
    , sequencingTable_pv(NULL)
  {
    for(uint32_t v_I_u32 = 0; v_I_u32 < variants::e_CameraCount; v_I_u32++)
    {
      distPixelDensity_apv[v_I_u32]      = NULL;
      distPrinciplePoints_apv[v_I_u32]   = NULL;
      distLUT_apv[v_I_u32]               = NULL;
    }

    for(uint32_t v_I_u32 = 0; v_I_u32 < c_MaxLensCount_u32; v_I_u32++)
    {
      undistPrinciplePoints_apv[v_I_u32]   = NULL;
      undistLUT_apv[v_I_u32]               = NULL;
    }

    for(uint32_t v_I_u32 = 0; v_I_u32 < c_MaxProjectionCount_u32; v_I_u32++)
    {
      matMult_apv[v_I_u32]      = NULL;
    }
  }
  
  ViewGenConfig::~ViewGenConfig()
  {
  }


  bool_t ViewGenConfig::init_b(void* i_BaseAddress_pv)
  {
    bool_t v_Result_b = false;

    if(i_BaseAddress_pv != NULL)
    {
      axiLite_pv                              = i_BaseAddress_pv;
      sequencingTable_pv                      = &reinterpret_cast<uint8_t*>(axiLite_pv)[c_SequencingTableOffset_u32];
      harmonThreshold_pv                      = &reinterpret_cast<uint8_t*>(axiLite_pv)[c_HarmonThresholdOffset_u32];
      harmonApplicationFactors_pv             = &reinterpret_cast<uint8_t*>(axiLite_pv)[c_HarmonApplicationFactorsOffset_u32];
      harmonApplicationOffsets_pv             = &reinterpret_cast<uint8_t*>(axiLite_pv)[c_HarmonApplicationOffsetsOffset_u32];
      harmonComputationResults_pv             = &reinterpret_cast<uint8_t*>(axiLite_pv)[c_HarmonComputationResultsOffset_u32];

      for(uint32_t v_I_u32 = 0; v_I_u32 < variants::e_CameraCount; v_I_u32++)
      {
        distPrinciplePoints_apv[v_I_u32]      = &reinterpret_cast<uint8_t*>(axiLite_pv)[c_DistortPrinciplePointsOffset_u32  + (v_I_u32 * 0x0008U)];
        distPixelDensity_apv[v_I_u32]         = &reinterpret_cast<uint8_t*>(axiLite_pv)[c_DistortPixelDensityOffset_u32     + (v_I_u32 * 0x0008U)];
        distLUT_apv[v_I_u32]                  = &reinterpret_cast<uint8_t*>(axiLite_pv)[c_DistortLUTOffset_u32              + (v_I_u32 * 0x1800U)];
      }

      for(uint32_t v_I_u32 = 0; v_I_u32 < c_MaxLensCount_u32; v_I_u32++)
      {
        undistPrinciplePoints_apv[v_I_u32]    = &reinterpret_cast<uint8_t*>(axiLite_pv)[c_UndistortPrinciplePointsOffset_u32 + (v_I_u32 * 0x0004U)];
        undistLUT_apv[v_I_u32]                = &reinterpret_cast<uint8_t*>(axiLite_pv)[c_UndistortLUTOffset_u32             + (v_I_u32 * 0x4000U)];
      }

      for(uint32_t v_I_u32 = 0; v_I_u32 < c_MaxProjectionCount_u32; v_I_u32++)
      {
        matMult_apv[v_I_u32]                  = &reinterpret_cast<uint8_t*>(axiLite_pv)[c_MatMulOffset_u32                   + (v_I_u32 * 0x0040U)];
      };

      v_Result_b = true;
    }

    return v_Result_b;
  }

  void* ViewGenConfig::getAxiLite_pv() const                                    
  { 
    return axiLite_pv; 
  }
  void* ViewGenConfig::getSequencingTable_pv() const   
  { 
    return sequencingTable_pv;
  }

  void* ViewGenConfig::getUndistPrincipalPoints_pv(uint32_t i_LensId_u32) const
  {
    void* v_Result_pv = NULL;

    if(i_LensId_u32 < c_MaxLensCount_u32)
    {
      v_Result_pv = undistPrinciplePoints_apv[i_LensId_u32];
    }

    return v_Result_pv;
  }

  void* ViewGenConfig::getDistPrincipalPoints_pv(variants::Camera_t i_CameraId_t) const
  {
    void* v_Result_pv = NULL;

    if(i_CameraId_t < variants::e_CameraCount)
    {
      uint32_t v_ViewGenCameraId_u32 = (i_CameraId_t);

      if(c_InvalidViewGenCameraId_u32 != v_ViewGenCameraId_u32)
      {
        v_Result_pv = distPrinciplePoints_apv[v_ViewGenCameraId_u32];
      }
    }

    return v_Result_pv;
  }

  void* ViewGenConfig::getDistPixelDensity_pv(variants::Camera_t i_CameraId_t) const
  {
    void* v_Result_pv = NULL;

    if(i_CameraId_t < variants::e_CameraCount)
    {
      uint32_t v_ViewGenCameraId_u32 = mapCameraId_u32(i_CameraId_t);

      if(c_InvalidViewGenCameraId_u32 != v_ViewGenCameraId_u32)
      {
        v_Result_pv = distPixelDensity_apv[v_ViewGenCameraId_u32];
      }
    }

    return v_Result_pv;
  }


  void* ViewGenConfig::getMatMul_pv(uint32_t i_ProjectionId_u32) const
  {
    void* v_Result_pv = NULL;

    if(i_ProjectionId_u32 < c_MaxProjectionCount_u32)
    {
      v_Result_pv = matMult_apv[i_ProjectionId_u32];
    }

    return v_Result_pv;
  }

  void* ViewGenConfig::getHarmonThresh_pv() const
  {
    return harmonThreshold_pv;
  }

  void* ViewGenConfig::getHarmonApplicationFactors_pv() const
  {
    return harmonApplicationFactors_pv;
  }

  void* ViewGenConfig::getHarmonApplicationOffsets_pv() const
  {
    return harmonApplicationOffsets_pv;
  }

  void* ViewGenConfig::getHarmonComputationResults_pv() const
  {
    return harmonComputationResults_pv;
  }

  void* ViewGenConfig::getUndistortLUT_pv(uint32_t i_LensId_u32) const
  {
    void* v_Result_pv = NULL;

    if(i_LensId_u32 < c_MaxLensCount_u32)
    {
      v_Result_pv = undistLUT_apv[i_LensId_u32];
    }

    return v_Result_pv;
  }

  void* ViewGenConfig::getDistortLUT_pv(variants::Camera_t i_CameraId_t) const
  {
    void* v_Result_pv = NULL;

    if(i_CameraId_t < variants::e_CameraCount)
    {
      uint32_t v_ViewGenCameraId_u32 = mapCameraId_u32(i_CameraId_t);

      if(c_InvalidViewGenCameraId_u32 != v_ViewGenCameraId_u32)
      {
        v_Result_pv = distLUT_apv[v_ViewGenCameraId_u32];
      }
    }

    return v_Result_pv;
  }


} // namespace bsp

#endif // ME_PLATFORM_QNX
