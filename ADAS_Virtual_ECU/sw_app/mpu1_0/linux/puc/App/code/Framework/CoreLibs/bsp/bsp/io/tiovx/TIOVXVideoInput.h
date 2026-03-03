//--------------------------------------------------------------------------
/// @file TIOVXVideoInput.h
/// @brief Implementation of TIOVX Video Input interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
//  --------------------------------------------------------------------------

#ifndef TIOVX_VIDEO_INPUT_H_
#define TIOVX_VIDEO_INPUT_H_

#include <platform/PlatformAPI.h>
#include <logging/Logger.h>
#include <variants/Enums.h>

#include <screen/screen.h>

#include <VX/vx.h>
#include <VX/vxu.h>
#include <VX/vx_khr_pipelining.h>
#include <TI/tivx_task.h>
#include <TI/tivx.h>

#include <sensor_drv/include/iss_sensors.h>

#include "SvsCamTypes.h"

#include "tiovx/kernels_j7/hwa/include/tivx_kernel_vpac_cuc_rc.h"

namespace bsp
{

/// @brief  Number of supported cameras
const uint32_t  c_CamerasNumber_u32 = 4;

/// @brief  Number of buffers in a pipeline
const int32_t   c_MaxBuffer2_u32 = 4;

typedef struct VideoInputBufferDesc2_s
{
  void*      buffers_apv[c_MaxBuffer2_u32];
  uint32_t   offset_aau32[c_MaxBuffer2_u32][3];
  uint32_t   stride_au32[3];
  uint32_t   size_au32[2];
  uint32_t   bufsize_au32[3];
  uint32_t   format_u32;
  uint32_t   numOfBuffer_u32;

} VideoInputBufferDesc2_t;

enum VideoInputState_e
{
    e_StateUninitialized = 0,
    e_StateIdle = 1,
    e_StateActive = 2,
    e_StateError = 3
};

/// @brief  Request for FuSa verification of input buffers
typedef struct VideoInputBufferVerifyRequest_s
{
    uint32_t idx_u32;
    uint16_t ctlval_au16[c_CamerasNumber_u32];
    bool_t ctlvalValid_ab[c_CamerasNumber_u32];
} VideoInputBufferVerifyRequest_t;

/// @brief  Size of queue of requests for FuSa verification of input buffers
const uint32_t c_MaxVideoInputBufferVerifyRequests_u32 = 8;

/// @brief  Video sensor support
class TIOVXVideoSensor
{
public:

    /// @brief  Class constructor
    TIOVXVideoSensor();

    /// @brief  Class destructor
    ~TIOVXVideoSensor();

    /// @brief  Logging function
    bool_t      log_b(logging::LogLevel_e i_level_e, const char *i_format_pc, ...) const;

    /// @brief  Initialize video input node
    bool_t      initVideoSensor_b(vx_context i_context_pv, char* i_sensor_pu8, uint8_t i_mask_u8, bool_t i_iss_b, uint8_t i_instanceId_u8, uint32_t i_inputFormat_u32);

    /// @brief  Read camera EEPROM
    void        readEepromData_v(variants::Camera_t i_CameraID_t);

public:

    /// @brief  Power control hook
    void    	powerEnable_v(bool_t i_enable_b);

    /// @brief  Enable/disable test pattern
    void        testPatternEnable_v(uint32_t i_CameraID_t, bool i_enable_b);

    /// ...tbd - remove later
    void        powerDisable_v();
    void        setFrameSync_v(bool_t i_Activate_b) const;
    void        switchMode_v(bool_t i_Mode_b) const;

public:

    /// @brief	Get input buffer descriptor
    bool_t    	getVideoInputBuffer_b(uint32_t i_CameraID_t, VideoInputBufferDesc2_t& o_VideoInputBufferDesc_rt);

    /// @brief 	Get index of oldest latched buffer
    uint32_t  	getCurrentBufferID_u32(uint32_t i_CameraID_t);

    /// @brief  Get index of oldest latched video buffer
    bool_t 		getVideoBuffer_b(uint32_t& o_bufferIdx_u32);

    /// @brief  Wait for a next buffer readiness
    bool_t 		waitVideoBuffer_b(uint32_t& o_bufferIdx_u32, const uint32_t& i_lastbufferIdx_u32, uint64_t* o_timestamp_pu64 = NULL);
  
    /// @brief  Release oldest video buffer to a graph
    bool_t 		releaseVideoBuffer_b(uint32_t i_bufferIdx_u32);

    /// @brief  Return sensors failure mask
    uint8_t     getFailureMask_u8();

    /// @brief    SVSEepromData_t accessor
    Svs_CamEepromDataArray_t  getSvsEepromData();

    /// @brief  Eeprom CrcError Status
    bool_t getSvsEepromCrcErrorStatus(variants::Camera_t i_CameraID_t);

    /// @brief  Submit FuSa video input buffer verification request
    bool_t      submitInputBufferVerificationRequest_b(uint32_t bufferIdx_u32, const uint16_t ctlval_au16[], const bool_t ctlvalValid_ab[]);

    /// @brief send user parameters to ISP
    vx_status sendUserIspParameters();

	/// @brief get user parameters from ISP
    isp_user_parameters_t* getUserIspParameters();

private:
    /// @brief    Initialize image sensor
    vx_status     setupImageSensor();

    /// @brief    Capturing interface creation
    vx_status     createCaptureNode(uint8_t i_instanceId_u8, bool_t i_useRawImage_b);

    /// @brief    VISS/AWB interface creation
    vx_status     createVissAEWBNode();

    /// @brief    Cogent ISP interface creation
    vx_status     createCogenteVissAEWBNode();

    /// @brief  Graph processing thread in active state
    vx_status     graphProcessingActive_t();

    /// @brief  Graph handling thread
    static void*  graphProcessingThread_pv(void* i_Args_pv);

    /// @brief  Input buffer verification handling thread
    static void*  inputBufferVerifyThread_pv(void* i_Args_pv);

private:
    /// @brief  Conditional variable for various purposes
    Condvar_s               condvar_s;

    /// @brief  Sensor name
    char*                   sensorName_pu8;

    /// @brief  Sensor mask
    uint8_t                 sensorMask_u8;

    /// @brief  Number of cameras enabled
    uint8_t                 camerasNumber_u8;

    /// @brief  Input camera format
    uint32_t                inputFormat_u32;

    /// @brief  ISS usage
    bool_t                  iss_b;

    /// @brief  OVX context reference    - delete? - tbd
    vx_context              context_pv;

    /// @brief  Capture graph
    vx_graph                capture_pv;

    /// @brief  Frame number
    uint32_t                frameNum_u32;

    /// @brief  Ready frames
    vx_reference            doneFrames_apv[c_MaxBuffer2_u32];

    /// @brief  Capture frames array ("vx_image" / "tivx_raw_image")
    vx_object_array         captureFrames_apv[c_MaxBuffer2_u32];

    /// @brief  Error frame
    tivx_raw_image          errorFrame_pv;

    /// @brief  Capture node (tbd - not sure it needs to be stored permanently)
    vx_node                 captureNode_pv;

    /// @brief  VISS output frames array of "vx_image"
    vx_object_array         vissOutFrames_apv[c_MaxBuffer2_u32];

    /// @brief  Output images (first frame of an array)
    vx_image                vissOutImage_apv[c_MaxBuffer2_u32];

    /// @brief  VISS node - tbd - should we store that?
    vx_node                 vissNode_pv;

    /// @brief  AWB node - tbd - should we store that?
    vx_node                 aewbNode_pv;

    vx_node                 v_rcNode_pv;

    /// @brief  Video buffers descriptors - move somewhere else - to upper-layer class probably
    VideoInputBufferDesc2_t videoInputBuffer_apv[c_CamerasNumber_u32];

    /// @brief  Current timestamps of the input buffers
    uint64_t                timestamp_aau64[c_MaxBuffer2_u32][c_CamerasNumber_u32];

    /// @brief  presumably we don't need that eventually - define API later
    uint32_t                currentReadBufferID_au32[c_CamerasNumber_u32];

    /// @brief  Sensor parameters - tbd - not sure it's good to expose it at all
    IssSensor_CreateParams  sensorParams_t;

    /// @brief  Graph initialization completion
    bool_t                  initDone_b;

    /// @brief eeprom  CRC error status
    bool_t                  crcError_ab[c_CamerasNumber_u32];

    /// @brief  Submitted buffers writing index
    uint32_t			    writeBufferIdx_u32;

    /// @brief  Graph state
    uint32_t			    state_t;

    /// @brief  Failing sensors mask
    uint8_t                 failureMask_u8;

    bool_t                  cameraRead_status[c_CamerasNumber_u32];

    /// @brief Eeprom Data
    SVSEepromData_t         SVSEepData_t[c_CamerasNumber_u32];

    /// @brief  Queue of requests for FuSa verification of input buffers
    VideoInputBufferVerifyRequest_t verifyQueue_ao[c_MaxVideoInputBufferVerifyRequests_u32];

    /// @brief ISP user parameters
    vx_user_data_object params_cmd;
    
    isp_user_parameters_t params_cmd_data;

    /// @brief  Position in verifyQueue_ao to write next request to
    uint32_t    verifyHead_u32;

    /// @brief  Position in verifyQueue_ao of the next request to process
    uint32_t    verifyTail_u32;

    /// @brief  Condition (and mutex) to protect and handle verifyQueue
    Condvar_s   verifyCondvar_s;
};

/// @brief  Video input interface
class TIOVXVideoInput
{
public:
    /// @brief  Class constructor
    TIOVXVideoInput();

    /// @brief  Class destructor
    ~TIOVXVideoInput();

    /// @brief  Logging function
    bool_t      log_b(logging::LogLevel_e i_level_e, const char *i_format_pc, ...) const;

    /// @brief  Initialize video input node
    bool_t      initVideoInput_b(vx_context i_context_pv);

    /// @brief  Power control function
    void        powerEnable_v(bool_t i_enable_b);

    /// @brief  Enable/disable test pattern
    void        testPatternEnable_v(variants::Camera_t i_CameraID_t, bool i_enable_b);

    // --tbd - delete eventually?
    void        powerDisable_v();
    void        setFrameSync_v(bool_t i_Activate_b) const;
    void        switchMode_v(bool_t i_Mode_b) const;
    
    /// @brief  ISP edge enhancement control
    void eeControl(bool_t i_enable_b);

public:

    /// @brief  Get input buffer descriptor
    bool_t      getVideoInputBuffer_b(variants::Camera_t i_CameraID_t, VideoInputBufferDesc2_t& o_VideoInputBufferDesc_rt);

    /// @brief 	Get index of oldest latched buffer
    uint32_t  	getCurrentBufferID_u32(variants::Camera_t i_CameraID_t);

    /// @brief  Get index of oldest SVS-latched video buffer
    bool_t 		getSvsVideoBuffer_b(uint32_t& o_bufferIdx_u32);

    /// @brief  Wait for a next SVS-buffer readiness
    bool_t 		waitSvsVideoBuffer_b(uint32_t& o_bufferIdx_u32, const uint32_t& i_lastbufferIdx_u32, uint64_t* o_timestamp_pu64 = NULL);

    /// @brief  Release oldest SVS-buffer to a graph
    bool_t 		releaseSvsVideoBuffer_b(uint32_t i_bufferIdx_u32);

    /// @brief  Return sensors failure mask
    uint8_t     getSvsFailureMask_u8();

    /// @brief    TIOVXVideoSensor accessor
    TIOVXVideoSensor&     getsvsVideoSensor_ro();

    /// @brief  Submit FuSa video input buffer verification request
    bool_t      submitInputBufferVerificationRequest_b(uint32_t bufferIdx_u32, const uint16_t ctlval_au16[], const bool_t ctlvalValid_ab[]);

private:
    /// @brief  SVS-cameras sensor
    TIOVXVideoSensor    svsVideoSensor;
};

} // namespace bsp

#endif // TIOVX_VIDEO_INPUT_H_

