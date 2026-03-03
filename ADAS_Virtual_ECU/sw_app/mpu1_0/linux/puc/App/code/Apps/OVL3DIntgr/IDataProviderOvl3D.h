//--------------------------------------------------------------------------
/// @file DataProviderOvl.h
/// @brief Contains
///
/// DataProvider is an interface between OVL module and the shared memory.
/// It implements the pure virtual interface definition to adapt the
/// module/component to the framework by specifying where the data comes form
/// or goes to. This means, this file contains all the interfaces required
/// to access input and output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef I_DATA_PROVIDEROVL_3D_H
#define I_DATA_PROVIDEROVL_3D_H

#include <cfg/BspTypes.h>
#include "cfg/IDataProvider.h"
#include <variants/Enums.h>
#include "meal/camera/core/inc/CameraPoint.h"
#define InitToZero 0U

namespace sensor
{
  class CameraBase;
}

namespace ovl3d
{

typedef struct THA_HitchData_s
{
  Point3f HitchLoc_p3f;
  Point2i HitchPix_p2d;
  int32_t HitchCplrPixDiffLongY_s32;
  HitchDetStatus_e HitchDetctStatus_e;
  CplrDetStatus_e  CplrDetctStatus_e;
} THA_HitchData_t;

class IDataProviderOvl3D
{
public:

  explicit IDataProviderOvl3D() {}
  virtual ~IDataProviderOvl3D() {}

  virtual void    	setIsPlaying_v(bool_t i_IsPlaying_b) = 0;
  virtual void*   	getVideoInputBuffer_pv(variants::Camera_t i_CameraId_t, bsp::VideoInputBufferDesc2_t& ro_desc_t) = 0;

  /// @brief  Allocate video buffer
  virtual bool_t 	allocVideoBuffer_b(uint32_t i_width_u32, uint32_t i_height_u32, uint32_t i_format_u32, uint32_t i_num_u32, bsp::VideoInputBufferDesc2_t& o_desc_ro, void** o_priv_apv = NULL) = 0;

  /// @brief  Destroy video buffer
  virtual void 		releaseVideoBuffer_v(bsp::VideoInputBufferDesc2_t& i_desc_ro, void** i_priv_apv) = 0;

  virtual void*   	getRenderBuffer_pv(uint32_t i_Index_u32) const = 0;
  virtual bool_t  	startRendering_b(uint32_t& o_inputBufIdx_u32, uint32_t& o_outputBufIdx_u32, uint32_t& io_frameNum_u32) = 0;
  virtual bool_t  	postWindow_b(uint32_t i_Width_u32, uint32_t i_Height_u32) = 0;
  virtual bool_t  	disableWindow_b() = 0;
  virtual uint32_t 	getCameraBufferID_u32(variants::Camera_t i_CameraID_t) = 0;

  virtual void  	testPatternEnable_v(variants::Camera_t i_CameraId_t, bool_t i_enable_b) = 0;
  virtual void    eeControl(bool_t i_enable_b) = 0;  
  virtual bool_t  	isCameraRunning_b(variants::Camera_t i_CameraId_t) = 0;
  virtual void      getResolutionInfo_v(uint32_t& i_width_u32, uint32_t& i_height_u32) = 0;

  virtual uint8_t 	getCameraFailure_u8() = 0;
  virtual sensor::CameraBase& getCamera_ro(variants::Camera_t i_CameraId_t) = 0;
  virtual ScreenRequest_t getScreenRequest_t(bool_t* o_receive_status_b_p ) const = 0;
  virtual THARelated_ScreenReq_t getTHARelated_ScreenReq_t(bool_t* o_receive_status_b_p ) const = 0;
#if TBD  
  virtual VehSpdWhlSpdData_t getVehSpdWhlSpdData_t(bool_t *o_ReceiveStatus_pb) const = 0;
#endif
  virtual ME_VehInp_to_IpcSignals_t getVehInp_CAN_to_IPC_Data_t(bool_t* o_receive_status_b_p ) = 0;
  virtual void setScreenResponse_v(const ScreenResponse_t& i_ScreenResponse_rt) = 0;
  virtual void  setTHARelated_ScreenReq_v(const THARelated_ScreenReq_t& i_THARelated_ScreenReq_t_rt) = 0;
  virtual THA_HitchData_t getTHAHitchData_t() = 0;

  virtual VehicleStateRequest_t getVehicleState_s() const = 0;

#if 0  
  virtual VehicleVStateRequest_t getVehicleVState_s() const = 0;
  virtual pas_state_t getPasState_o() const = 0;
  virtual uint8_t getTVMGuideMode_v() const = 0;
  virtual odo_state_t getOdoState_o() const = 0;
  virtual InPcanCommonData2_t getInCommonData2_o() const = 0;
  virtual InPcanCommonData1_t getInCommonData1_o() const = 0;
  virtual container::ResponseEOLCmd_t* getResponseEOLCmd_rt() const = 0;
  virtual uint8_t* getEolImageBuffer_pu8(variants::Camera_t i_CameraId_t) const = 0;
#endif  
  virtual sensor::CameraParams& getCameraParams_ro(variants::Camera_t i_CameraId_t) const = 0;

  virtual bool_t submitInputBufferVerificationRequest_b(uint32_t bufferIdx_u32, const uint16_t ctlval_au16[], const bool_t ctlvalValid_ab[]) = 0;

  virtual bsp::TIOVXHost& getTIOVX_ro() = 0;
  virtual container::OVL3DData* getOVL3DData_po() = 0;
  virtual void setOVL3DRuntime(uint32_t u_Runtime_u32) = 0;
  virtual void setRenderThreadRuntime(uint32_t u_Runtime_u32) = 0;
  virtual void setAlgoViewRuntime(uint32_t u_Runtime_u32) = 0;
  virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) = 0;
};

}; // namespace ovl

#endif /* DATAPROVIDEROVL_H_ */
