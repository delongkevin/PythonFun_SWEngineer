//--------------------------------------------------------------------------
/// @file Cam.cpp
/// @brief Implementation of QNX camera interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#ifndef FPGA_LAYER_ENGINE_H_
#define FPGA_LAYER_ENGINE_H_

#include "FpgaParameters.h"
#include "FpgaLayerEngineDefines.h"

#include <platform/PlatformAPI.h>

#include <osal/system/Time.h>
#include <osal/threading/Mutex.h>

#include <variants/Enums.h>

#include <cfg/shmdata/SigM_Messages.h>

namespace bsp
{


class FpgaLayerEngine
{

public:

  FpgaLayerEngine();

  ~FpgaLayerEngine();

  bool_t                initLayerEngine_b();

  bool_t                setScreenRequest_b(ScreenRequest_t i_ScreenRequest_t);

  bool_t                setVehicleState_b(VehicleStateRequest_t i_VehicleState_t);

  ScreenRequest_t       getScreenRequest_t();

  VehicleStateRequest_t getVehicleState_t();

public:

  bool_t  update_b();

  bool_t  updateNonLock_b();

  void    free_v();

  void    freeLayer_v(FpgaLayerID_e i_LayerID_e);

  bool_t  configLayer_b(LayerConfig_s& i_LayerConfig_rs);

  void    printLayer_v();

public:

  void*   getOverlayLayer_pv(FpgaLayerID_e i_LayerID_e, uint8_t i_BufferIdx_u8) const;

  void*   getAlphaLayer_pv(FpgaLayerID_e i_LayerID_e, uint8_t i_BufferIdx_u8) const;

  bool_t  getLayerConfig_b(FpgaLayerID_e i_LayerID_e, LayerConfig_s& o_LayerConfig_rs);

  bool_t  setLayerProcessed_b(FpgaLayerID_e i_LayerID_e);


private:

  bool_t  updateVideoLayer_b(const LayerConfig_s& i_LayerConfig_rs) const;

  bool_t  updateOverlayLayer_b(const LayerConfig_s& i_LayerConfig_rs) const;

public:

  bool_t                  isEnabled_b() const;

  bool_t                  isLayerConfigDone_b(bool_t i_All_b);

  FpgaLayerProcessState_e isLayerProcessed_e();

  bool_t                  isViewChangeConfigDone_b();

  bool_t                  enableLayerEngine_b(bool_t i_Enable_b);

public:

  bool_t                  lock_b();

  bool_t                  unlock_b();

private:

  osal::Time                         time_o;
  osal::Mutex                        mutex_o;
  osal::Mutex                        lockMutex_o;

  ScreenRequest_t                    screenRequest_t;
  VehicleStateRequest_t              vehicleState_t;
  uint8_t                            prevZoomFactor_u8;

  bool_t                             isLayerEngineEnabled_b;

  bool_t                             isConfigLayerDone_ab[c_LayerEngineLayerCount_u8];

  bool_t                             isProcessingLayer_ab[c_LayerEngineLayerCount_u8];

  bool_t                             wasProcessedLayer_ab[c_LayerEngineLayerCount_u8];

  /// -------------------------------------------------------------------------------
  /// Real FPGA Addresses and Buffers
  void*                              layerEngineCommon_pv;
  void*                              layerEngineBase_pv;

  /// -------------------------------------------------------------------------------
  /// Overlay Buffers
  void*                              layerBuffer_apv[c_LayerEngineLayerCount_u8][2U];

  /// -------------------------------------------------------------------------------
  /// Temporary Buffers and Configs

  LayerConfig_s                      cacheLayerConfig_as[c_LayerEngineLayerCount_u8];
};


} // namespace bsp



#endif // FPGA_LAYER_ENGINE_H_
