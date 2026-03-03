//--------------------------------------------------------------------------
/// @file DataProviderOvl3D.cpp
/// @brief Contains OVL3D data provider
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
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
///
//  --------------------------------------------------------------------------

#include "DataProviderOvl3D.h"


/**> Use png instead of cameras */
extern bool use_png;

/**> SVS log level */
extern int LOG_LEVEL;

// PRQA S 3706 EOF // performance

namespace ovl3d
{

/// @brief  Logging function
static bool_t log_b(logging::LogLevel_e i_level_e, const char *i_format_pc, ...)
{
    char        v_buffer_ac[256];
    va_list     v_args_pt;

    va_start(v_args_pt, i_format_pc);

    vsnprintf(v_buffer_ac, sizeof(v_buffer_ac) - 1, i_format_pc, v_args_pt);

    return logging::Logger::log_b(i_level_e, logging::e_LogModeMaskPrintf, "ovl3d: %s\n", v_buffer_ac);
}

DataProviderOvl3D::DataProviderOvl3D(container::IDataProvider& b_DataProvider_ro)
    : IDataProviderOvl3D()
    , dataProvider_ro(b_DataProvider_ro)
{
#if DEBUG_LATENCY
    timestampInIndex_u8 = timestampOutIndex_u8 = 0U;
#endif
}

DataProviderOvl3D::~DataProviderOvl3D()
{
  // nothing to do here
}

/// @brief  Power-up/down video input
void DataProviderOvl3D::setIsPlaying_v(bool_t i_IsPlaying_b)
{
    bsp::TIOVXHost&         v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
    bsp::TIOVXVideoInput&   v_videoInput_ro = v_host_ro.getVideoInput_ro();

    v_videoInput_ro.powerEnable_v(i_IsPlaying_b);
}

/// @brief  Get input camera buffer
void* DataProviderOvl3D::getVideoInputBuffer_pv(variants::Camera_t i_CameraId_t, bsp::VideoInputBufferDesc2_t& ro_desc_t)
{
    bsp::TIOVXHost&         v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
    bsp::TIOVXVideoInput&   v_videoInput_ro = v_host_ro.getVideoInput_ro();

    // get camera buffer descriptor
    v_videoInput_ro.getVideoInputBuffer_b(i_CameraId_t, ro_desc_t);

    // return buffer pointer (indexed?)
    return ro_desc_t.buffers_apv[0];
}

ME_VehInp_to_IpcSignals_t DataProviderOvl3D::getVehInp_CAN_to_IPC_Data_t(bool_t* o_receive_status_b_p )
{
    return dataProvider_ro.getSigMData_po()->getME_VehInp_to_IpcSignals_t();
}

/// @brief  Allocate video buffer
bool_t DataProviderOvl3D::allocVideoBuffer_b(uint32_t i_width_u32, uint32_t i_height_u32, uint32_t i_format_u32, uint32_t i_num_u32, bsp::VideoInputBufferDesc2_t& o_desc_ro, void** o_priv_apv)
{
    bsp::TIOVXHost&     v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();

    return v_host_ro.allocVideoBuffer_b(i_width_u32, i_height_u32, i_format_u32, i_num_u32, o_desc_ro);
}

/// @brief  Destroy video buffer
void DataProviderOvl3D::releaseVideoBuffer_v(bsp::VideoInputBufferDesc2_t& i_desc_ro, void** i_priv_apv)
{
    bsp::TIOVXHost&     v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();

    v_host_ro.releaseVideoBuffer_v(i_desc_ro, i_priv_apv);
}

/// @brief  Get output render buffer pointer
void* DataProviderOvl3D::getRenderBuffer_pv(uint32_t i_Index_u32) const
{
    bsp::TIOVXHost&         v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
    bsp::TIOVXVideoOutput&  v_videoOutput_ro = v_host_ro.getVideoOutput_ro();

    return v_videoOutput_ro.getVideoOutputBuffer_b(i_Index_u32);
}

/// @brief  Wait for output buffer availability
  bool_t DataProviderOvl3D::startRendering_b(uint32_t& o_inputBufIdx_u32, uint32_t& o_outputBufIdx_u32, uint32_t& io_frameNum_u32)
{
    bsp::TIOVXHost&         v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
    bsp::TIOVXVideoOutput&  v_videoOutput_ro = v_host_ro.getVideoOutput_ro();
    bsp::TIOVXVideoInput&   v_videoInput_ro = v_host_ro.getVideoInput_ro();
    bool_t                  v_result_b;
    uint32_t                v_bufferIdx_u32;

    if (!use_png)
    {
        static uint32_t     s_inputBufIdx_u32 = 0;
        uint64_t            v_timestamp_u64[2];

        // wait for input buffers readiness
        v_result_b = v_videoInput_ro.waitSvsVideoBuffer_b(o_inputBufIdx_u32, s_inputBufIdx_u32, &v_timestamp_u64[0]);
        if (v_result_b == true)
        {
            s_inputBufIdx_u32 = o_inputBufIdx_u32;
            io_frameNum_u32++;
            log_b(logging::e_LogLvlDebug, "input buf-%u ready", o_inputBufIdx_u32);
        }
        else
        {
            log_b(logging::e_LogLvlError, "no input buffers available");
        }

#if DEBUG_LATENCY
        // put timestamp into ring-buffer
        timestamp_au64[timestampInIndex_u8][0] = v_timestamp_u64[0];
		timestamp_au64[timestampInIndex_u8][1] = v_timestamp_u64[1];
        timestampInIndex_u8 = (timestampInIndex_u8 + 1) % c_timestampArraySize_u32;
#endif
    }
    else
    {
        // advance frame number
        io_frameNum_u32++;

        v_result_b = true;
    }

    // wait for output buffer readiness
    if (v_result_b == true)
    {
        uint64_t    v_timestamp_u64;

        v_result_b = v_videoOutput_ro.waitFrameBuffer_b(o_outputBufIdx_u32, &v_timestamp_u64);
        if (v_result_b == true)
        {
            log_b(logging::e_LogLvlDebug, "output buf-%u ready", o_outputBufIdx_u32);
        }
        else
        {
            log_b(logging::e_LogLvlError, "no output buffers available");
        }
#if DEBUG_LATENCY
        // put timestamp into ring-buffer
        if (v_timestamp_u64 != 0UL)
        {
            static uint32_t s_deltaAcc_u32;
            static uint32_t s_counter_u32;

            uint32_t    v_delta_u32 = (uint32_t)(v_timestamp_u64 - timestamp_au64[timestampOutIndex_u8][0]);

            timestampOutIndex_u8 = (timestampOutIndex_u8 + 1) % c_timestampArraySize_u32;

            if (s_deltaAcc_u32 == 0)
            {
                s_deltaAcc_u32 = v_delta_u32 << 4;
            }
            else
            {
                s_deltaAcc_u32 += v_delta_u32 - ((s_deltaAcc_u32 + 8) >> 4);
            }

            ME_Debugger_F_Printf_v("frame #%u: latency: %u = %lu-%lu (idx: %u/%u), delta=%u", frameNum_u32, v_delta_u32, v_timestamp_u64, timestamp_au64[(timestampOutIndex_u8 + c_timestampArraySize_u32 - 1) % c_timestampArraySize_u32][0], timestampInIndex_u8, timestampOutIndex_u8,
								   (uint32_t)(timestamp_au64[(timestampOutIndex_u8 + c_timestampArraySize_u32 - 1) % c_timestampArraySize_u32][1] - timestamp_au64[(timestampOutIndex_u8 + c_timestampArraySize_u32 - 1) % c_timestampArraySize_u32][0]));

            if ((++s_counter_u32 & 31) == 0)
            {
                log_b(logging::e_LogLvlDebug, "average buffer latency: %u", (s_deltaAcc_u32 + 8) >> 4);
            }
        }
#endif
    }

    // increment number of rendered frames (may be different from input frame number)
    frameNum_u32++;
    
     dataProvider_ro.getSigMData_po()->setRenderFrameID(frameNum_u32);

    return v_result_b;
}

/// @brief  Submit output buffer for visualization
bool_t DataProviderOvl3D::postWindow_b(uint32_t i_Width_u32, uint32_t i_Height_u32)
{
    bsp::TIOVXHost&         v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
    bsp::TIOVXVideoOutput&  v_videoOutput_ro = v_host_ro.getVideoOutput_ro();
    bool_t                  v_result_b;

    v_result_b = v_videoOutput_ro.submitBuffer_b();
    if (v_result_b == false)
    {
        log_b(logging::e_LogLvlError, "failed to output frame");
    }

    return v_result_b;
}

/// @brief  This is never called, I guess
bool_t DataProviderOvl3D::disableWindow_b()
{
  bool_t v_result_b = false;

  return v_result_b;
}

/// @brief  Get index of most recent camera buffer?
uint32_t DataProviderOvl3D::getCameraBufferID_u32(variants::Camera_t i_CameraID_t)
{
    bsp::TIOVXHost&         v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
    bsp::TIOVXVideoInput&   v_videoInput_ro = v_host_ro.getVideoInput_ro();
    uint32_t                v_bufferIdx_u32 = 0;
    bool_t                  v_result_b;

    // get index of last latched buffer
    v_result_b = v_videoInput_ro.getSvsVideoBuffer_b(v_bufferIdx_u32);
    if (v_result_b == true)
    {
        log_b(logging::e_LogLvlDebug, "camera-%u: buffer-%u ready", i_CameraID_t, v_bufferIdx_u32);
    }

    return v_bufferIdx_u32;
}

/// @brief  Enable/disable test pattern
void   DataProviderOvl3D::testPatternEnable_v(variants::Camera_t i_CameraId_t, bool_t i_enable_b)
{
    bsp::TIOVXHost&         v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
    bsp::TIOVXVideoInput&   v_videoInput_ro = v_host_ro.getVideoInput_ro();

    v_videoInput_ro.testPatternEnable_v(i_CameraId_t, i_enable_b);
}

/// @brief  Enable/disable edge enhancement
void   DataProviderOvl3D::eeControl(bool_t i_enable_b)
{
    bsp::TIOVXHost&         v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
    bsp::TIOVXVideoInput&   v_videoInput_ro = v_host_ro.getVideoInput_ro();

    v_videoInput_ro.eeControl(i_enable_b);
}

/// @brief  Test if individual camera is running
bool_t DataProviderOvl3D::isCameraRunning_b(variants::Camera_t i_CameraId_t)
{
    container::CamMData*    v_camm_po = dataProvider_ro.getCamMData_po();
    sensor::CameraBase&     v_camera_ro = v_camm_po->getCamera_ro(i_CameraId_t);

    return (use_png ? true : v_camera_ro.getCameraState_e() == sensor::e_CameraStateRunning);
}

void DataProviderOvl3D::getResolutionInfo_v(uint32_t& i_width_u32, uint32_t& i_height_u32)
{
    bsp::TIOVXHost&         v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
    bsp::TIOVXVideoOutput&  v_videoOutput_ro = v_host_ro.getVideoOutput_ro();
    v_videoOutput_ro.getResolutionInfo_v(i_width_u32, i_height_u32);
}


/// @brief  Get camera failure mask
uint8_t DataProviderOvl3D::getCameraFailure_u8()
{
    bsp::TIOVXHost&         v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
    bsp::TIOVXVideoInput&   v_videoInput_ro = v_host_ro.getVideoInput_ro();

    return (use_png ? 0U : v_videoInput_ro.getSvsFailureMask_u8());
}

bool_t DataProviderOvl3D::submitInputBufferVerificationRequest_b(uint32_t bufferIdx_u32, const uint16_t ctlval_au16[], const bool_t ctlvalValid_ab[])
{
    bsp::TIOVXHost&         v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
    bsp::TIOVXVideoInput&   v_videoInput_ro = v_host_ro.getVideoInput_ro();

    return use_png ? true : v_videoInput_ro.submitInputBufferVerificationRequest_b(bufferIdx_u32, ctlval_au16, ctlvalValid_ab);
}

/// @brief  Get individual camera data
sensor::CameraBase& DataProviderOvl3D::getCamera_ro(variants::Camera_t i_CameraId_t)
{
    return dataProvider_ro.getCamMData_po()->getCamera_ro(i_CameraId_t);
}

THARelated_ScreenReq_t DataProviderOvl3D::getTHARelated_ScreenReq_t(bool_t* o_receive_status_b_p ) const
{
  return dataProvider_ro.getSigMData_po()->getTHARelated_ScreenReq_t();
}

ScreenRequest_t DataProviderOvl3D::getScreenRequest_t(bool_t* o_receive_status_b_p ) const
{
  return dataProvider_ro.getSigMData_po()->getScreenRequest_t(o_receive_status_b_p);
}

void DataProviderOvl3D::setScreenResponse_v(const ScreenResponse_t& i_ScreenResponse_rt)
{
  dataProvider_ro.getSigMData_po()->setScreenResponse_v(i_ScreenResponse_rt);
}

void  DataProviderOvl3D::setTHARelated_ScreenReq_v(const THARelated_ScreenReq_t& i_THARelated_ScreenReq_t_rt)
{
    dataProvider_ro.getSigMData_po()->setTHARelated_ScreenReq_v(i_THARelated_ScreenReq_t_rt);
}

THA_HitchData_t DataProviderOvl3D::getTHAHitchData_t() {
    JobTHADetOutput_t thaDetOutput = dataProvider_ro.getSigMData_po()->getJobTHADetOutput_t();
    if(e_Cplr_Detected == thaDetOutput.CplrDetctStatus_e) {
        thaHitchData.HitchCplrPixDiffLongY_s32 = thaDetOutput.HitchCplrPixDiffLongY_s32;
    }
    thaHitchData.HitchPix_p2d.x = thaDetOutput.HitchPix_p2d.x;
    thaHitchData.HitchPix_p2d.y = thaDetOutput.HitchPix_p2d.y;
    thaHitchData.HitchDetctStatus_e = thaDetOutput.HitchDetctStatus_e;
    thaHitchData.CplrDetctStatus_e = thaDetOutput.CplrDetctStatus_e;

    THA_Calibration_data_MPU1_0_t thaCalibData = dataProvider_ro.getSigMData_po()->getTHA_Calibration_data_MPU1_0();
    thaHitchData.HitchLoc_p3f.x = thaCalibData.CalData.DefaultHitchXmm_s32;
    thaHitchData.HitchLoc_p3f.y = thaCalibData.CalData.DefaultHitchYmm_s32;
    thaHitchData.HitchLoc_p3f.z = thaCalibData.CalData.DefaultHitchZmm_s32;

    return thaHitchData;
}

VehicleStateRequest_t DataProviderOvl3D::getVehicleState_s() const
{
  return dataProvider_ro.getSigMData_po()->getVehicleState_s();
}

sensor::CameraParams& DataProviderOvl3D::getCameraParams_ro(variants::Camera_t i_CameraId_t) const
{
    return dataProvider_ro.getCamMData_po()->getCamera_ro(i_CameraId_t).getCameraParams_ro();
}

bsp::TIOVXHost& DataProviderOvl3D::getTIOVX_ro()
{
    return dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
}

container::OVL3DData* DataProviderOvl3D::getOVL3DData_po()
{
    return dataProvider_ro.getOVL3DData_po();
}

void DataProviderOvl3D::setOVL3DRuntime(uint32_t u_Runtime_u32)
{
  dataProvider_ro.getOVL3DData_po()->setOVL3DRuntime(u_Runtime_u32);
}

void DataProviderOvl3D::setRenderThreadRuntime(uint32_t u_Runtime_u32)
{
    dataProvider_ro.getOVL3DData_po()->setRenderThreadRuntime(u_Runtime_u32);
}

void DataProviderOvl3D::setAlgoViewRuntime(uint32_t u_Runtime_u32)
{
    dataProvider_ro.getOVL3DData_po()->setAlgoViewRuntime(u_Runtime_u32);
}

PerformanceStatsEnable_t DataProviderOvl3D::get_PerformanceStatsEnable(void)
{
	return dataProvider_ro.getSigMData_po()->getPerformanceStatsEnable_t();
}
} // namespace ovl

