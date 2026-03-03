//--------------------------------------------------------------------------
/// @file IDataProviderEol.h
/// @brief Contains
///
/// IDataProvider is an interface used by the algorithm to define what data
/// is actually needed. Implementation is delegated to a derived data provider
/// that is component/module specific and belongs to the framework implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Saravan (saravanaperumal.ponnambalam@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef IDATAPROVIDEREOL_H_
#define IDATAPROVIDEREOL_H_

#include "EolTypesInternal.h"
#include "EolCalib.h"
#include "CommonDataTypeRef.h"
#include <variants/Enums.h>
#include <cfg/DataProvider.h>

namespace eol
{
class IDataProviderEol
{
public:
  explicit IDataProviderEol()
  {
  }

  virtual ~IDataProviderEol();

  /* Get CALSM data */
  virtual void getCalSMData()=0;
  virtual uint8_t getAlgoCommand_u8() =0;
  virtual uint8_t getAlgoType_u8() =0;
  virtual ME_Hydra3defs_E_CameraID_t getCameraId_MEHydra3()=0;

  /* Put CALSM data */
  virtual void putEolOutput(aParaMgr_S_Calibration_t& i_CaliVCalib,
      ME_Hydra3defs_E_EOLAlgoState_t i_AlgoState, ME_Hydra3defs_E_CameraID_t m_CurrCamID)  = 0;

  /* Get Image bufffer from TIOVX */
  virtual EolInitData_s getEolData()=0;

  /* Get Camera parameters (Intrinsics and Extrinsic) */
  virtual void getCameraParameters_v() = 0;
  virtual variants::Camera_t getCameraId_variants() =0;

  virtual void setEOLRuntime(uint32_t u_Runtime_u32) = 0;
  virtual void setEOLThreadRuntime(uint32_t u_Runtime_u32) = 0;
  virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) = 0;

#if 0
  virtual void clearEolDataToMcu_v()=0;
  //virtual void configureFpgaForInputImage_v(bool_t i_EnableAlgoView_b, CameraId_t i_McuCamId_e) = 0;
  //virtual const uint8_t* getInputImage_pu8() const =0;
  
  virtual void putEolOutput(aParaMgr_S_Calibration_t& i_CaliVCalib,
      ME_Hydra3defs_E_EOLAlgoState_t i_AlgoState, ME_Hydra3defs_E_CameraID_t m_CurrCamID)  = 0;

 // virtual void setAlgoState_v( const EolAlgoState_t i_EolAlgoState_e) = 0;
  virtual void setLastUpdate_v() = 0;
  virtual void setEolActive(bool_t i_EolActive_b) = 0;
  virtual void setLastRequestedAt_v( uint32_t i_LastRequestedAt_u32) =0;
  //virtual void setEolErrorCode_v( const EolErrorCode_t i_EolErrorCode_e ) = 0;
  virtual void setDeltaPitch_v( float32_t i_DeltaPitch_f32 ) =0;
  virtual void setDeltaRoll_v( float32_t i_DeltaRoll_32 ) =0;
  virtual void setDeltaYaw_v( float32_t i_DeltaYaw_f32 ) =0;
  virtual void setDeltaX_v( float32_t i_DeltaX_f32 ) =0;
  virtual void setDeltaY_v( float32_t i_DeltaY_f32 ) =0;
  virtual void setDeltaZ_v( float32_t i_DeltaZ_f32 ) =0;
  virtual void setEolTargetData_v( const EolCalib &i_EolCalib_ro) =0;
  virtual void setMcuCameraId_v( uint8_t i_McuCameraId_u8) =0;
  virtual void getCameraParameters_v() = 0;
 // virtual void setAlgoViewBuffer_v( const EolAlgoView1280x800Buffer_t i_AlgoViewBuffer_e)=0;

  virtual void getCalSMData()=0;
  //virtual EolInitData_s getEolData()=0;
  virtual uint32_t getLastRequestedAt_u32() const =0;
  virtual float32_t getDeltaPitch_f32() =0;
  virtual float32_t getDeltaRoll_f32() =0;
  virtual float32_t getDeltaYaw_f32() =0;
  virtual float32_t getDeltaX_f32() =0;
  virtual float32_t getDeltaY_f32() =0;
  virtual float32_t getDeltaZ_f32() =0;
  virtual uint8_t getAlgoType_u8() =0;
  virtual uint32_t getRequestedAt_u32() const =0;
  //virtual ResponseState_t getResponseState_e() =0;
  virtual uint8_t getAlgoCommand_u8() =0;
  virtual uint8_t getCameraId_u8() =0;
  virtual variants::Camera_t getCameraId_variants() =0;
  virtual ME_Hydra3defs_E_CameraID_t getCameraId_MEHydra3()=0;
  virtual float32_t getLTargetSeperation_f32() =0;

  //virtual AlgoDebugView_t getAlgoDebugView_e() =0;
  virtual uint32_t getFrameId_u32() =0;
  //virtual AlgoDebugTypeEol_t getAlgoDebugTypeEol_e() =0;
  virtual uint8_t getEolCameraMask_u8() =0;
  virtual uint16_t getTargetId_u16() =0;
  virtual uint16_t getTargetDistance_u16() const=0;
  //virtual VariantId_t getVariantId_e() =0;
  //virtual AlgosDebugData_t& accessDebugLayer_rt()=0;
  //virtual uint8_t getCameraConnectorIdFromMcuId_u8(const CameraId_t i_CameraId_t)=0;
  //virtual prjcontainer::AdapterCameraReal& accessAdapterCameraReal_ro() =0;
  //virtual EolErrorCode_t getEolErrorCode_e() = 0;
  //virtual shmdata::EolConfig_s getEolConfigData_s() = 0;
#endif 
#ifdef VIDEO_INPUT_BUFFER
  virtual void*       getVideoInputBuffer_pv(variants::Camera_t i_CameraId_t, bsp::VideoInputBufferDesc2_t& ro_desc_t) = 0;
  virtual void*       getRenderBuffer_pv(uint32_t i_Index_u32) const = 0;
  virtual void        setIsPlaying_v(bool_t i_IsPlaying_b) = 0;
#endif
};

  extern uint8_t m_InputImage[1920*1280];

} // namespace eol

#endif // IDATAPROVIDEREOL_H_
