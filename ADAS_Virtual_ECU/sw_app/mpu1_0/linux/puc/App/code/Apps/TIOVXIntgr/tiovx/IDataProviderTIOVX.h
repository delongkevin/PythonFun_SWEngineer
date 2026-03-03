//--------------------------------------------------------------------------
/// @file IDataProviderTIOVX.h
/// @brief Contains interface for TIOVX Dataprovider
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
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
//  --------------------------------------------------------------------------
#ifndef I_DATA_PROVIDER_TIOVX_H_
#define I_DATA_PROVIDER_TIOVX_H_

#include <platform/PlatformAPI.h>

#include <sensor/CameraBase.h>

#include <bsp/io/tiovx/TIOVXHost.h>


namespace tiovx
{
  class IDataProviderTIOVX
  {
  public:

    explicit IDataProviderTIOVX() {}
    virtual ~IDataProviderTIOVX() {}

    virtual bool_t   init_b(uint8_t i_InitType_u8) = 0;
    virtual void start_cameras(){};

    //----------------------------------------------------------------------------------------
    // // Data Input (only getter)
    //---------------------------------------------------------------------------------------

	virtual bsp::TIOVXHost&        getTIOVX_ro() = 0;
#ifdef USE_REQUEST_AND_RESPONSE
	virtual uint8_t              getViewId_u8() = 0;
#else
    virtual uint8_t              getViewId_u8(bool_t* o_receive_status_b_p ) = 0;
#endif

    virtual sensor::CameraBase&  getCamera_ro(variants::Camera_t i_CameraId_t) = 0;

    virtual bool_t getCamDataInitStatus() = 0;

    virtual void    setCamEepromDataArray_v() = 0;
    virtual  void    updateCamCaliberationData_v() = 0;
 virtual  void    updateCamera_v(const variants::Camera_t i_Camera_t, const sensor::CalibrationData_t& i_CalibrationData_rt) = 0;

    virtual Svs_CamEepromDataArray_t    getCamEepromDataArray_v() = 0;
    virtual void setTIOVXRuntime(uint32_t u_Runtime_u32) = 0;
    virtual void setTIOVXThreadRuntime(uint32_t u_Runtime_u32) = 0;
    virtual void setCamCalibRuntime(uint32_t u_Runtime_u32) = 0;
    virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) = 0;
    virtual CamHotplugStatus_t getCamHotplugStatus_v(void) = 0;

    //----------------------------------------------------------------------------------------
    // Data Output (only setter)
    //----------------------------------------------------------------------------------------

  };


} // namespace tiovx

#endif // I_DATA_PROVIDER_TIOVX_H_
