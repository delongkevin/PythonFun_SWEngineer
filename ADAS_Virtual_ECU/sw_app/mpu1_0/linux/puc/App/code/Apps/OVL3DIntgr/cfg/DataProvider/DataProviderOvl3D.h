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
#ifndef DATA_PROVIDER_OVL_3D_H
#define DATA_PROVIDER_OVL_3D_H

#include "IDataProviderOvl3D.h"
#include <bsp/io/tiovx/TIOVXVideoInput.h>

/**> Enable latency measurement */
#define	DEBUG_LATENCY			0

namespace ovl3d
{

class DataProviderOvl3D : public IDataProviderOvl3D
{
public:
    explicit DataProviderOvl3D(container::IDataProvider& b_DataProvider_ro);
    virtual ~DataProviderOvl3D();


    virtual void        setIsPlaying_v(bool_t i_IsPlaying_b) ME_OVERRIDE;

    virtual void*       getVideoInputBuffer_pv(variants::Camera_t i_CameraId_t, bsp::VideoInputBufferDesc2_t& ro_desc_t) ME_OVERRIDE;

    /// @brief  Allocate video buffer
    virtual bool_t 	    allocVideoBuffer_b(uint32_t i_width_u32, uint32_t i_height_u32, uint32_t i_format_u32, uint32_t i_num_u32, bsp::VideoInputBufferDesc2_t& o_desc_ro, void** o_priv_apv = NULL) ME_OVERRIDE;

    /// @brief  Destroy video buffer
    virtual void 		releaseVideoBuffer_v(bsp::VideoInputBufferDesc2_t& i_desc_ro, void** i_priv_apv) ME_OVERRIDE;

    virtual void*       getRenderBuffer_pv(uint32_t i_Index_u32) const ME_OVERRIDE;

    virtual bool_t      startRendering_b(uint32_t& o_inputBufIdx_u32, uint32_t& o_outputBufIdx_u32, uint32_t& io_frameNum_u32) ME_OVERRIDE;
    virtual bool_t      postWindow_b(uint32_t i_Width_u32, uint32_t i_Height_u32) ME_OVERRIDE;
    virtual bool_t      disableWindow_b() ME_OVERRIDE;

    virtual uint32_t    getCameraBufferID_u32(variants::Camera_t i_CameraID_t) ME_OVERRIDE;

    virtual void  	  testPatternEnable_v(variants::Camera_t i_CameraId_t, bool_t i_enable_b) ME_OVERRIDE;
    virtual void        eeControl(bool_t i_enable_b) ME_OVERRIDE;
    virtual bool_t      isCameraRunning_b(variants::Camera_t i_CameraId_t) ME_OVERRIDE;

    virtual void getResolutionInfo_v(uint32_t& i_width_u32, uint32_t& i_height_u32) ME_OVERRIDE;

    virtual uint8_t 	getCameraFailure_u8() ME_OVERRIDE;
    virtual sensor::CameraBase& getCamera_ro(variants::Camera_t i_CameraId_t) ME_OVERRIDE;
    virtual ScreenRequest_t getScreenRequest_t(bool_t* o_receive_status_b_p ) const ME_OVERRIDE;
    virtual THARelated_ScreenReq_t getTHARelated_ScreenReq_t(bool_t* o_receive_status_b_p ) const ME_OVERRIDE;
#if	TBD
    virtual VehSpdWhlSpdData_t getVehSpdWhlSpdData_t(bool_t* o_receive_status_b_p ) const ME_OVERRIDE;
#endif
    virtual ME_VehInp_to_IpcSignals_t getVehInp_CAN_to_IPC_Data_t(bool_t* o_receive_status_b_p ) ME_OVERRIDE;

    virtual void setScreenResponse_v(const ScreenResponse_t& i_ScreenResponse_rt) ME_OVERRIDE;
    virtual void  setTHARelated_ScreenReq_v(const THARelated_ScreenReq_t& i_THARelated_ScreenReq_t_rt) ME_OVERRIDE;
    virtual THA_HitchData_t getTHAHitchData_t() ME_OVERRIDE;
    virtual VehicleStateRequest_t getVehicleState_s() const ME_OVERRIDE;
#if 0
    virtual VehicleVStateRequest_t getVehicleVState_s() const ME_OVERRIDE;
    virtual pas_state_t getPasState_o() const ME_OVERRIDE;
    virtual uint8_t getTVMGuideMode_v() const ME_OVERRIDE;
    virtual odo_state_t getOdoState_o() const ME_OVERRIDE;
    virtual InPcanCommonData2_t getInCommonData2_o() const ME_OVERRIDE;
    virtual InPcanCommonData1_t getInCommonData1_o() const ME_OVERRIDE;
    virtual container::ResponseEOLCmd_t* getResponseEOLCmd_rt() const ME_OVERRIDE;
    virtual uint8_t* getEolImageBuffer_pu8(variants::Camera_t i_CameraId_t) const ME_OVERRIDE;
#endif
    virtual sensor::CameraParams& getCameraParams_ro(variants::Camera_t i_CameraId_t) const ME_OVERRIDE;

    virtual bool_t submitInputBufferVerificationRequest_b(uint32_t bufferIdx_u32, const uint16_t ctlval_au16[], const bool_t ctlvalValid_ab[]) ME_OVERRIDE;
    
    virtual bsp::TIOVXHost& getTIOVX_ro() ME_OVERRIDE;
    virtual container::OVL3DData* getOVL3DData_po() ME_OVERRIDE;
    void setOVL3DRuntime(uint32_t u_Runtime_u32);
    void setRenderThreadRuntime(uint32_t u_Runtime_u32);
    void setAlgoViewRuntime(uint32_t u_Runtime_u32);
    virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) ME_OVERRIDE;

private:

    container::IDataProvider& dataProvider_ro;

#if DEBUG_LATENCY
    /// @brief  Timestamp ring-buffer size
    static const uint32_t   c_timestampArraySize_u32 = 8;

    /// @brief  Input buffers timestamps
    uint64_t            timestamp_au64[c_timestampArraySize_u32][2];

    /// @brief  Index of next input timestamp
    uint8_t             timestampInIndex_u8;

    /// @brief  Index of next output timestamp
    uint8_t             timestampOutIndex_u8;
#endif

    /// @brief  Frame number
    uint32_t            frameNum_u32;

    /// @brief  THA hitch and coupler data
    THA_HitchData_t     thaHitchData;
};

}; // namespace ovl

#endif /* DATA_PROVIDER_OVL_3D_H */
