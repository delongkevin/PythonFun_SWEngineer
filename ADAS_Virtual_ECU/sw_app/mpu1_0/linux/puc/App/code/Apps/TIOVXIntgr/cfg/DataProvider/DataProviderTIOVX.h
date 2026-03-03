//--------------------------------------------------------------------------
/// @file DataProviderTIOVX.h
/// @brief Contains
///
/// DataProvider is an interface between TIOVX module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
//  --------------------------------------------------------------------------
#ifndef DATA_PROVIDER_TIOVX_H_
#define DATA_PROVIDER_TIOVX_H_

#include "tiovx/IDataProviderTIOVX.h"
#include <cfg/DataProvider.h>

namespace tiovx
{

class DataProviderTIOVX : public IDataProviderTIOVX
{
public:
  explicit DataProviderTIOVX(container::IDataProvider& b_DataProvider_ro);
  virtual ~DataProviderTIOVX();

  virtual bool_t               init_b(uint8_t i_InitType_u8) ME_OVERRIDE;
  virtual void start_cameras() ME_OVERRIDE;

virtual  void  updateCamera_v(const variants::Camera_t i_Camera_t, const sensor::CalibrationData_t& i_CalibrationData_rt) ME_OVERRIDE;

 virtual  void  updateCamCaliberationData_v() ME_OVERRIDE;

 virtual void setTIOVXRuntime(uint32_t u_Runtime_u32) ME_OVERRIDE;
 virtual void setTIOVXThreadRuntime(uint32_t u_Runtime_u32) ME_OVERRIDE;
 virtual void setCamCalibRuntime(uint32_t u_Runtime_u32) ME_OVERRIDE;
 virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) ME_OVERRIDE;
 virtual CamHotplugStatus_t getCamHotplugStatus_v(void) ME_OVERRIDE;

  /// ---------------------------------------------------------

  virtual bsp::TIOVXHost&      getTIOVX_ro() ME_OVERRIDE;

#ifdef USE_REQUEST_AND_RESPONSE
  virtual uint8_t              getViewId_u8() ME_OVERRIDE;
#else
  virtual uint8_t              getViewId_u8(bool_t* o_receive_status_b_p ) ME_OVERRIDE;
#endif

virtual sensor::CameraBase&  getCamera_ro(variants::Camera_t i_CameraId_t) ME_OVERRIDE;

virtual void                setCamEepromDataArray_v() ME_OVERRIDE;

virtual Svs_CamEepromDataArray_t    getCamEepromDataArray_v() ME_OVERRIDE;

virtual bool_t getCamDataInitStatus() ME_OVERRIDE;
private:

  container::IDataProvider& dataProvider_ro;
  Svs_CamEepromDataArray_t 	svs_CamEepromDataArray_t;
  bool_t                  crcError_ab[4];
  sensor::CalibrationData_t v_LastCalibrationDataCamFront_t;
  sensor::CalibrationData_t v_LastCalibrationDataCamRight_t;
  sensor::CalibrationData_t v_LastCalibrationDataCamLeft_t;
  sensor::CalibrationData_t v_LastCalibrationDataCamRear_t;

};

} // namespace tiovx

#endif // DATA_PROVIDER_TIOVX_H_

