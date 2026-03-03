//--------------------------------------------------------------------------
/// @file FpgaViewGen.h
/// @brief Implementation of Fpga ViewGen interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#ifndef FPGA_VIEW_GEN_CONFIG_H_
#define FPGA_VIEW_GEN_CONFIG_H_

#include <platform/PlatformAPI.h>

#include "FpgaParameters.h"
#include "bsp/io/fpga/FpgaHelper.h"



namespace bsp
{

const uint32_t c_MaxLensCount_u32 = 4U;
const uint32_t c_MaxProjectionCount_u32 = 8U;


class ViewGenConfig
{

public:

  ViewGenConfig();

  ~ViewGenConfig();

  bool_t          init_b(void* i_BaseAddress_pv);

  void*           getAxiLite_pv() const;
  void*           getSequencingTable_pv() const;

  void*           getUndistortLUT_pv(uint32_t i_LensId_u32) const;
  static uint32_t getUndistortLUTEntryCount_u32();

  void*           getUndistPrincipalPoints_pv(uint32_t i_LensId_u32) const;
  static uint32_t getUndistPrincipalPoitnsEntryCount_u32();
  
  void*           getDistPrincipalPoints_pv(variants::Camera_t i_CameraId_t) const;
  static uint32_t getDistPrincipalPointsEntryCount_u32();

  void*           getDistPixelDensity_pv(variants::Camera_t i_CameraId_t) const;
  static uint32_t getDistPixelDensityEntryCount_u32();

  void*           getMatMul_pv(uint32_t i_ProjectionId_u32) const;
  static uint32_t getMatMulEntryCount_u32();

  void*           getHarmonThresh_pv() const;
  void*           getHarmonApplicationFactors_pv() const;
  void*           getHarmonApplicationOffsets_pv() const;
  void*           getHarmonComputationResults_pv() const;

  void*           getDistortLUT_pv(variants::Camera_t i_CameraId_t) const;
  static uint32_t getDistortLUTEntryCount_u32();

private:

  void* axiLite_pv;
  void* sequencingTable_pv;

  void* matMult_apv[c_MaxProjectionCount_u32];

  void* harmonThreshold_pv;
  void* harmonApplicationFactors_pv;
  void* harmonApplicationOffsets_pv;
  void* harmonComputationResults_pv;

  void* undistPrinciplePoints_apv[c_MaxLensCount_u32];
  void* undistLUT_apv            [c_MaxLensCount_u32];

  void* distPrinciplePoints_apv[variants::e_CameraCount];
  void* distPixelDensity_apv   [variants::e_CameraCount];
  void* distLUT_apv            [variants::e_CameraCount];
};


} // namespace bsp



#endif // FPGA_VIEW_GEN_H_
