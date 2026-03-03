//--------------------------------------------------------------------------
/// @file TIOVXVideoInput.cpp
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

#include <platform/PlatformAPI.h>
#include <bsp/io/tiovx/TIOVXVideoInput.h>

#include <stdarg.h>

#include <VX/vx.h>
#include <VX/vxu.h>
#include <VX/vx_khr_pipelining.h>
#include <TI/tivx_task.h>
#include <TI/tivx.h>
#include <TI/j7_csitx.h>
#include <TI/j7_imaging_aewb.h>
#include <TI/tivx_obj_desc.h>
#include <../../utils/include/tivx_utils_graph_perf.h>
#include <TI/j7_vpac_cuc_isp.h>
#include <platform/stdlib/utils/crc/src/crc.h>

#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_VideoInputGraphThread   (1u)
#define PROFILE_InputBufferVerifyThread   (1u) 
#endif
#if PROFILE_VideoInputGraphThread
#include "osal/system/Time.h"
static uint32_t v_AvgVideoInputRuntime_u32 = 0;
static uint32_t v_VideoInputRunCntr_u32 = 0;
static uint32_t v_AvgVideoInputPeriodicity_u32 = 0;
static uint32_t v_VideoInputPreviousTime_u32 = 0;
static uint32_t v_VideoInputRuntimeData = 0; 
#endif

extern "C" {

// Private TI API that allows to get access to storage buffer
extern uint16_t ownReferenceGetObjDescId(vx_reference ref);

// internal TIOVX function
extern vx_status ownReferenceAllocMem(vx_reference ref);

// get total number of references
extern vx_uint32 ownTotalReferenceCount(vx_reference ref);

#include <app_init.h>

#include <utils/ipc/include/app_ipc.h>
#include <utils/remote_service/include/app_remote_service.h>
#include <utils/sensors/include/app_sensors.h>
#include <../../vision_apps/utils/iss/include/app_iss.h>

#include <../imaging/sensor_drv/include/iss_sensors.h>
#include <../imaging/sensor_drv/include/iss_sensor_if.h>

}

/// @brief	Enable buffers order debugging
#define DEBUG_TEST_BUFFERS      1

/// @brief	Timing debugging
#define DEBUG_TIMING			1

/// @brief	Refcounts tracking (debugging)
#define PRINT_REFCOUNT(ref) \
({  \
    vx_uint32 __refcount = ownTotalReferenceCount((vx_reference)(ref));                         \
    vx_uint32 __ref2;   \
    vxQueryReference((vx_reference)(ref), VX_REFERENCE_COUNT, &__ref2, sizeof(__ref2)); \
    ME_Debugger_F_Printf_v("%d: reference '" #ref "': %u (%u)\n", __LINE__, __refcount, __ref2);       \
})

namespace bsp
{
    /// @brief  Sensor initialization procedure enable
    static const bool c_sensorInit = false;


/// @brief  Video sensor class constructor
TIOVXVideoSensor::TIOVXVideoSensor()
{
    memset(videoInputBuffer_apv, 0, sizeof(videoInputBuffer_apv));
    memset(currentReadBufferID_au32, 0, sizeof(currentReadBufferID_au32));
    memset(&sensorParams_t, 0, sizeof(sensorParams_t));

    Assert(e_PeOk == ME_Condvar_Init_t(&condvar_s));

    initDone_b = false;
    state_t = e_StateUninitialized;
    writeBufferIdx_u32 = 0U;

    for(uint8_t i = 0; i< c_CamerasNumber_u32; i++)
    {
      cameraRead_status[i] = false;

    }

    memset(&params_cmd_data, 0, sizeof(params_cmd_data));
    params_cmd_data.ee_enabled = 1;
    v_rcNode_pv = NULL;
    
    verifyHead_u32 = 0;
    verifyTail_u32 = 0;
    Assert(e_PeOk == ME_Condvar_Init_t(&verifyCondvar_s));
}

/// @brief  Video sensor class destructor
TIOVXVideoSensor::~TIOVXVideoSensor()
{
}

/// @brief  Logging function
bool_t TIOVXVideoSensor::log_b(logging::LogLevel_e i_level_e, const char *i_format_pc, ...) const
{
    char        v_buffer_ac[256];
    va_list     v_args_pt;

    va_start(v_args_pt, i_format_pc);

    vsnprintf(v_buffer_ac, sizeof(v_buffer_ac) - 1, i_format_pc, v_args_pt);

    return logging::Logger::log_b(i_level_e, logging::e_LogModeMaskPrintf, "%s: %s", sensorName_pu8, v_buffer_ac);
}

/// @brief  Graph handling thread
void* TIOVXVideoSensor::graphProcessingThread_pv(void* i_Args_pv)
{
    #if PROFILE_VideoInputGraphThread
        static osal::Time start;
        volatile uint32_t v_Start_t = 0;
        volatile uint32_t v_End_t = 0;
        volatile uint32_t currPeriodicity = 0;
        v_Start_t = __get_time_usec();
        currPeriodicity = v_Start_t - v_VideoInputPreviousTime_u32;
    #endif

    TIOVXVideoSensor*   v_videoSensor_po = reinterpret_cast<TIOVXVideoSensor*>(i_Args_pv);
    vx_status           v_status_t;

    // lock internal data
    ME_Mutex_Lock_t(&v_videoSensor_po->condvar_s.MEMutex_po);

    // wait for start-up command
    while (true)
    {
        // wait for start-up command
        while (v_videoSensor_po->state_t != e_StateActive)
        {
            v_videoSensor_po->log_b(logging::e_LogLvlInfo, "%d: wait cond: %p", __LINE__, &v_videoSensor_po->condvar_s);
            ME_Condvar_Wait_t(&v_videoSensor_po->condvar_s);
        }

        ME_Mutex_UnLock_t(&v_videoSensor_po->condvar_s.MEMutex_po);

        v_videoSensor_po->log_b(logging::e_LogLvlInfo, "start capture graph...");

        // start graph execution
        v_status_t = v_videoSensor_po->graphProcessingActive_t();

        v_videoSensor_po->log_b(logging::e_LogLvlInfo, "capture graph stopped: %X", v_status_t);

        ME_Mutex_Lock_t(&v_videoSensor_po->condvar_s.MEMutex_po);
    }

    // unlock internal data
    ME_Mutex_UnLock_t(&v_videoSensor_po->condvar_s.MEMutex_po);
	#if PROFILE_VideoInputGraphThread
        v_End_t = __get_time_usec();
        //ME_Debugger_F_Printf_v("VideoInput: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
        v_VideoInputRunCntr_u32++; //Increment the run counter for averaging purpose
        v_AvgVideoInputPeriodicity_u32 = ((v_AvgVideoInputPeriodicity_u32 * (v_VideoInputRunCntr_u32 -1)) + currPeriodicity)/v_VideoInputRunCntr_u32; //Average Periodicity
        v_AvgVideoInputRuntime_u32 = ((v_AvgVideoInputRuntime_u32 * (v_VideoInputRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_VideoInputRunCntr_u32; //New Average  
        v_VideoInputRuntimeData = (((v_AvgVideoInputRuntime_u32/1000U)<<16U) | ((v_AvgVideoInputPeriodicity_u32/1000U) & 0xFFFF));
        //dataProvider_po->setVideoInputRuntime(v_VideoInputRuntimeData);
        //ME_Debugger_F_Printf_v("VideoInput: E: %lld P: %lld \n", v_AvgVideoInputRuntime_u32, v_AvgVideoInputPeriodicity_u32);
        v_VideoInputPreviousTime_u32 = v_Start_t;
    #endif

    return NULL;
}

void* TIOVXVideoSensor::inputBufferVerifyThread_pv(void* i_Args_pv)
{
    TIOVXVideoSensor*   v_videoSensor_po = reinterpret_cast<TIOVXVideoSensor*>(i_Args_pv);
    vx_status           v_status_t = VX_SUCCESS;
    uint16_t group_id = 0;

    VideoInputBufferVerifyRequest_t* v_queueItem_po;
    tivx_vpac_cuc_isp_verify_buffer_data_t v_data_s;
    vx_user_data_object v_obj_pv;
    vx_reference        v_params_apo[2];

    if (v_status_t == VX_SUCCESS)
    {
        v_obj_pv = vxCreateUserDataObject(v_videoSensor_po->context_pv,
                "tivx_vpac_cuc_isp_verify_buffer_data_t", sizeof(tivx_vpac_cuc_isp_verify_buffer_data_t), NULL);
        v_status_t = vxGetStatus((vx_reference)v_obj_pv);
        if (v_status_t != VX_SUCCESS)
        {
            v_videoSensor_po->log_b(logging::e_LogLvlError, "creting verify data object failed: %X", v_status_t);
        }
    }

    ME_Mutex_Lock_t(&v_videoSensor_po->verifyCondvar_s.MEMutex_po);

    while (v_status_t == VX_SUCCESS)
    {
        while (v_videoSensor_po->verifyTail_u32 == v_videoSensor_po->verifyHead_u32)
        {
            ME_Condvar_Wait_t(&v_videoSensor_po->verifyCondvar_s);
        }

        // Can unlock now, data in request queue is safe while verifyTail was not advanced
        ME_Mutex_UnLock_t(&v_videoSensor_po->verifyCondvar_s.MEMutex_po);

        for (uint32_t v_i_u32 = 0; v_i_u32 < c_CamerasNumber_u32; v_i_u32++)
        {
            v_queueItem_po = &v_videoSensor_po->verifyQueue_ao[v_videoSensor_po->verifyTail_u32];

            if (v_queueItem_po->ctlvalValid_ab[v_i_u32])
            {
                v_params_apo[0] = vxGetObjectArrayItem(v_videoSensor_po->vissOutFrames_apv[v_queueItem_po->idx_u32], v_i_u32);

                v_data_s.ctlval = v_queueItem_po->ctlval_au16[v_i_u32];
                v_data_s.group_id = group_id;
                vxCopyUserDataObject(v_obj_pv, 0, sizeof(v_data_s), &v_data_s, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST);
                v_params_apo[1] = (vx_reference)v_obj_pv;

                v_status_t = tivxNodeSendCommand(v_videoSensor_po->vissNode_pv, v_i_u32, TIVX_VPAC_CUC_RC_CMD_VERIFY_BUFFER, v_params_apo, 2);

                vxReleaseReference(&v_params_apo[0]);

                if (v_status_t != VX_SUCCESS)
                {
                    v_videoSensor_po->log_b(logging::e_LogLvlError, "verify call failed: %X", v_status_t);
                    break;
                }                
            }
        }

        ME_Mutex_Lock_t(&v_videoSensor_po->verifyCondvar_s.MEMutex_po);

        v_videoSensor_po->verifyTail_u32 = (v_videoSensor_po->verifyTail_u32 + 1) % c_MaxVideoInputBufferVerifyRequests_u32;
        group_id++;
    }

    ME_Mutex_UnLock_t(&v_videoSensor_po->verifyCondvar_s.MEMutex_po);
    v_videoSensor_po->log_b(logging::e_LogLvlError, "input buffer verify thread terminatied");
    return NULL;
}

/// @brief  Enumerate image sensors (thread-safe)
static int32_t app_enumerate_image_sensor(char *sensor_name_list[], uint8_t  * num_sensors_found)
{
    uint8_t g_cmdPrm[CMD_PARAM_SIZE];
    int32_t status = -1;
    uint8_t count = 0;
    uint8_t numRegisteredSensors = 0;
    char*   sensor_name = NULL;

    memset(g_cmdPrm, 0, CMD_PARAM_SIZE);
    status = appRemoteServiceRun(
        APP_IPC_CPU_MCU2_0 ,
        (char*)IMAGE_SENSOR_REMOTE_SERVICE_NAME,
        IM_SENSOR_CMD_ENUMERATE,
        (void*)g_cmdPrm,
        CMD_PARAM_SIZE,
        0
    );

    if (0 == status)
    {
        for(count=0;count<ISS_SENSORS_MAX_SUPPORTED_SENSOR;count++)
        {
            sensor_name = (char*)(g_cmdPrm + count*ISS_SENSORS_MAX_NAME);
            if(0 != sensor_name[0])
            {
                memcpy(sensor_name_list[count], sensor_name, ISS_SENSORS_MAX_NAME);
                numRegisteredSensors++;
            }
        }
    }

    *num_sensors_found = numRegisteredSensors;

    return status;
}

/// @brief  Query image sensor parameters (thread-safe)
static int32_t app_query_image_sensor(char* sensor_name, IssSensor_CreateParams* pSensorCreatePrms)
{
    uint8_t g_cmdPrm[CMD_PARAM_SIZE];
    int32_t status = -1;

    memset(pSensorCreatePrms, 0, sizeof(IssSensor_CreateParams));
    memset(g_cmdPrm, 0, CMD_PARAM_SIZE);
    memcpy(g_cmdPrm, sensor_name, ISS_SENSORS_MAX_NAME);

    uint32_t i;
    for (i = 0; i < 100; i++)
    {
        status = appRemoteServiceRun(
            APP_IPC_CPU_MCU2_0 ,
            (char*)IMAGE_SENSOR_REMOTE_SERVICE_NAME,
            IM_SENSOR_CMD_QUERY,
            (void*)g_cmdPrm,
            CMD_PARAM_SIZE,
            0
        );

        if (status == 0)
        {
            break;
        }

        usleep(300000);
    }

    if (0 == status)
    {
        /*Sensor service appends sensor properties to sensor name in cmdprm buffer*/
        memcpy(pSensorCreatePrms, (g_cmdPrm+ISS_SENSORS_MAX_NAME), sizeof(IssSensor_CreateParams));
    }

    return status;
}

/// @brief  Initialize image sensor (thread-safe)
static int32_t app_init_image_sensor(char* sensor_name, uint32_t featuresEnabled, uint32_t channel_mask)
{
    uint8_t g_cmdPrm[CMD_PARAM_SIZE];
    int32_t status = -1;

    if((channel_mask >= (1<<ISS_SENSORS_MAX_CHANNEL)) || (channel_mask < 0x1))
    {
        return -1;
    }

    memset(g_cmdPrm, 0, CMD_PARAM_SIZE);
    memcpy(g_cmdPrm, sensor_name, ISS_SENSORS_MAX_NAME);
    memcpy(g_cmdPrm+ISS_SENSORS_MAX_NAME, &channel_mask, sizeof(uint32_t));
    status = appRemoteServiceRun(
        APP_IPC_CPU_MCU2_0 ,
        (char*)IMAGE_SENSOR_REMOTE_SERVICE_NAME,
        IM_SENSOR_CMD_PWRON,
        (void*)g_cmdPrm,
        CMD_PARAM_SIZE,
        0
    );

    if (status == 0)
    {
        memcpy(g_cmdPrm+ISS_SENSORS_MAX_NAME, &featuresEnabled, sizeof(uint32_t));
        memcpy(g_cmdPrm+ISS_SENSORS_MAX_NAME+sizeof(uint32_t), &channel_mask, sizeof(uint32_t));

        status = appRemoteServiceRun(
            APP_IPC_CPU_MCU2_0 ,
            (char*)IMAGE_SENSOR_REMOTE_SERVICE_NAME,
            IM_SENSOR_CMD_CONFIG,
            (void*)g_cmdPrm,
            CMD_PARAM_SIZE,
            0
        );
    }

    return status;
}

/// @brief  Start image sensor (thread-safe)
static int32_t app_start_image_sensor(char* sensor_name, uint32_t channel_mask)
{
    int32_t status = -1;
    uint8_t  g_cmdPrm[CMD_PARAM_SIZE];

    memset(g_cmdPrm, 0, CMD_PARAM_SIZE);
    memcpy(g_cmdPrm, sensor_name, ISS_SENSORS_MAX_NAME);
    memcpy(g_cmdPrm+ISS_SENSORS_MAX_NAME, &channel_mask, sizeof(uint32_t));

    status = appRemoteServiceRun(
        APP_IPC_CPU_MCU2_0 ,
        (char*)IMAGE_SENSOR_REMOTE_SERVICE_NAME,
        IM_SENSOR_CMD_STREAM_ON,
        (void*)g_cmdPrm,
        CMD_PARAM_SIZE,
        0
    );

    FILE *fd;
    char buff_tmp[] = "0xABCD";
    char buff_read[6];
    int loop = 0;

    fd = fopen( "/tmp/ISTREAMON.txt", "w" );
    if( fd != NULL ) {
        fwrite(&buff_tmp, 1, 6, fd);
        fflush(fd);

        fread(&buff_read, 1, 6, fd);
        for (loop =0; loop <= 5; loop ++)
        {
            ME_Debugger_F_Printf_v("READ ISTREAMON FILE %c \n", buff_read[loop]);
        }

        fclose( fd );
    }

    return status;
}

/// @brief  Stop image sensor (thread-safe)
static int32_t app_stop_image_sensor(char* sensor_name, uint32_t channel_mask)
{
    int32_t status = -1;
    uint8_t  g_cmdPrm[CMD_PARAM_SIZE];

    memset(g_cmdPrm, 0, CMD_PARAM_SIZE);
    memcpy(g_cmdPrm, sensor_name, ISS_SENSORS_MAX_NAME);
    memcpy(g_cmdPrm+ISS_SENSORS_MAX_NAME, &channel_mask, sizeof(uint32_t));

    status = appRemoteServiceRun(
        APP_IPC_CPU_MCU2_0 ,
        (char*)IMAGE_SENSOR_REMOTE_SERVICE_NAME,
        IM_SENSOR_CMD_STREAM_OFF,
        (void*)g_cmdPrm,
        CMD_PARAM_SIZE,
        0
    );

    return status;
}

/// @brief  Enable/disable test pattern for image sensor (thread-safe)
static int32_t app_image_sensor_test_pattern(char* sensor_name, uint32_t ch, bool_t enable)
{
    int32_t     status = -1;
    uint8_t     g_cmdPrm[CMD_PARAM_SIZE], *ptr = g_cmdPrm + ISS_SENSORS_MAX_NAME;
    uint32_t    cmd = IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_REG;
    uint32_t    addr = 0x3070;
    uint32_t    value = (enable ? 0x2 : 0x0);

    memset(g_cmdPrm, 0, CMD_PARAM_SIZE);
    memcpy(g_cmdPrm, sensor_name, ISS_SENSORS_MAX_NAME);

    memcpy(ptr, &ch, sizeof(ch));
    ptr += sizeof(ch);

    memcpy(ptr, &cmd, sizeof(cmd));
    ptr += sizeof(cmd);

    memcpy(ptr, &addr, sizeof(addr));
    ptr += sizeof(addr);

    memcpy(ptr, &value, sizeof(value));
    ptr += sizeof(value);

    status = appRemoteServiceRun(
        APP_IPC_CPU_MCU2_0,
        (char*)IMAGE_SENSOR_REMOTE_SERVICE_NAME,
        IM_SENSOR_CMD_CTL,
        (void*)g_cmdPrm,
        CMD_PARAM_SIZE,
        0
    );

    return status;
}

/// @brief  Query image sensor parameters (thread-safe)
static int32_t app_read_image_sensor_eeprom(char* sensor_name, uint32_t ch, uint32_t offset, uint32_t length, uint8_t *data)
{
    uint8_t     g_cmdPrm[CMD_PARAM_SIZE], *ptr = g_cmdPrm + ISS_SENSORS_MAX_NAME;
    uint32_t    cmd = IMAGE_SENSOR_CTRLCMD_READ_EEPROM;
    int32_t     status = -1;

    if (length > CMD_PARAM_SIZE - ISS_SENSORS_MAX_NAME - sizeof(uint32_t[4]))
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "length exceeded: %u > %u\n",
                               length, (uint32_t)(CMD_PARAM_SIZE - ISS_SENSORS_MAX_NAME - sizeof(uint32_t[4])));
        return -(errno = EINVAL);
    }

    memset(g_cmdPrm, 0, CMD_PARAM_SIZE);
    memcpy(g_cmdPrm, sensor_name, ISS_SENSORS_MAX_NAME);

    memcpy(ptr, &ch, sizeof(ch));
    ptr += sizeof(ch);

    memcpy(ptr, &cmd, sizeof(cmd));
    ptr += sizeof(cmd);

    memcpy(ptr, &offset, sizeof(offset));
    ptr += sizeof(offset);

    memcpy(ptr, &length, sizeof(length));
    ptr += sizeof(length);

    status = appRemoteServiceRun(
        APP_IPC_CPU_MCU2_0 ,
        (char*)IMAGE_SENSOR_REMOTE_SERVICE_NAME,
        IM_SENSOR_CMD_CTL,
        (void*)g_cmdPrm,
        CMD_PARAM_SIZE,
        0
    );

    if (0 == status)
    {
        /* Sensor service appends sensor properties to sensor name in cmdprm buffer*/
        memcpy(data, ptr, length);
    }

    return status;
}

/// @brief  Active-state graph processing
vx_status TIOVXVideoSensor::graphProcessingActive_t()
{
    vx_status   v_status_t;

    log_b(logging::e_LogLvlInfo, "start sensor operation");

    // start sensor
    v_status_t = app_start_image_sensor(sensorName_pu8, sensorMask_u8);
    if (v_status_t != VX_SUCCESS)
    {
        log_b(logging::e_LogLvlError, "failed to start sensor: %X", v_status_t);
        return v_status_t;
    }

    // Register error frame
    v_status_t = tivxCaptureRegisterErrorFrame(captureNode_pv, (vx_reference)errorFrame_pv);
    if (v_status_t != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "%s: tivxCaptureRegisterErrorFrame failed: %X\n", sensorName_pu8, v_status_t);
        return v_status_t;
    }

    // Enqueue buf for pipe up but don't trigger graph execution
    vx_reference*   v_captureFrames_apv = (iss_b ? (vx_reference*) vissOutImage_apv : (vx_reference*)captureFrames_apv);

    for (uint32_t v_bufId_u32 = 0U; v_bufId_u32 < c_MaxBuffer2_u32; v_bufId_u32++)
    {
        v_status_t = vxGraphParameterEnqueueReadyRef(capture_pv, 0, &v_captureFrames_apv[v_bufId_u32], 1);
        if (v_status_t != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "failed to enqueue capture-frame-%u: %X", v_bufId_u32, v_status_t);
        }
    }

    log_b(logging::e_LogLvlInfo, "buffers enqueued: %u", c_MaxBuffer2_u32);

    // start active-state executive loop
    ME_Mutex_Lock_t(&condvar_s.MEMutex_po);

    while (state_t == e_StateActive)
    {
        vx_reference&   v_captureFrame_pv = doneFrames_apv[writeBufferIdx_u32];
        vx_reference    v_outputImage_pv = NULL;
        vx_uint32       v_numRefs_t;

        // wait for a buffers completion (unlock internal state)
        ME_Mutex_UnLock_t(&condvar_s.MEMutex_po);

        v_status_t = vxGraphParameterDequeueDoneRef(capture_pv, 0, &v_captureFrame_pv, 1, &v_numRefs_t);
        if (v_status_t != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "failed to dequeue capture-frame: %X", v_status_t);
        }
        else
        {
            log_b(logging::e_LogLvlDebug, "dequeue capture-frame: %u", writeBufferIdx_u32);
        }

        // as needed, check out buffers indices are sane
        if (v_status_t == VX_SUCCESS)
        {
            if (DEBUG_TEST_BUFFERS)
            {
                vx_reference            v_outImage_pv = (iss_b ? v_captureFrame_pv : vxGetObjectArrayItem((vx_object_array)v_captureFrame_pv, 0));
                uint16_t                v_objID_u16 = ownReferenceGetObjDescId(v_outImage_pv);
                tivx_obj_desc_image_t*  v_desc_po;
                tivxGetObjDescList(&v_objID_u16, (tivx_obj_desc_t **)&v_desc_po, 1);

                void*       v_bufAddr_pv = tivxMemShared2TargetPtr(&v_desc_po->mem_ptr[0]);
                uint32_t    v_bufId_u32;

                for (v_bufId_u32 = 0U; v_bufId_u32 < c_MaxBuffer2_u32; v_bufId_u32++)
                {
                    if (v_bufAddr_pv == videoInputBuffer_apv[0].buffers_apv[v_bufId_u32])
                        break;
                }

                if (v_bufId_u32 < c_MaxBuffer2_u32)
                {
                    if (v_bufId_u32 != writeBufferIdx_u32)
                    {
                        log_b(logging::e_LogLvlError, "camera-buf: %u != %u, obj-id: %u[%u]", v_bufId_u32, writeBufferIdx_u32, v_objID_u16, v_desc_po->base.type);
                    }
                    else
                    {
                        log_b(logging::e_LogLvlDebug, "camera-buf: %u, obj-id: %u[%u]", v_bufId_u32, v_objID_u16, v_desc_po->base.type);
                    }
                }
                else
                {
                    log_b(logging::e_LogLvlError, "camera-buf not found: %p, obj-id: %u[%u]", v_bufAddr_pv, v_objID_u16, v_desc_po->base.type);
                }
            }

            // check for buffer validity
            if (iss_b)
            {
                vx_object_array v_array_pv = vissOutFrames_apv[writeBufferIdx_u32];
                uint8_t         v_failureMask_u8 = 0;

                for (uint32_t v_cameraId_u8 = 0U; v_cameraId_u8 < camerasNumber_u8; v_cameraId_u8++)
                {
                    vx_reference            v_outImage_pv = vxGetObjectArrayItem(v_array_pv, v_cameraId_u8);
                    uint16_t                v_objID_u16 = ownReferenceGetObjDescId(v_outImage_pv);
                    tivx_obj_desc_image_t*  v_desc_po;
                    tivxGetObjDescList(&v_objID_u16, (tivx_obj_desc_t **)&v_desc_po, 1);

                    timestamp_aau64[writeBufferIdx_u32][v_cameraId_u8] = v_desc_po->base.timestamp;

                    if ((v_desc_po->base.flags & TIVX_REF_FLAG_IS_INVALID) != 0U)
                    {
                        log_b(logging::e_LogLvlDebug, "%s: camera-%u frame invalid", sensorName_pu8, v_cameraId_u8);
                        v_failureMask_u8 |= (1U << v_cameraId_u8);
                    }
                }

                failureMask_u8 = v_failureMask_u8;
            }

            if (DEBUG_TIMING)
            {
                static uint32_t s_lastTimestamp_u32;
                static uint32_t s_deltaAcc_u32;
                static uint32_t s_counter_u32;

                uint32_t        v_timestamp_u32 = __get_time_usec();
                uint32_t        v_delta_u32 = (s_lastTimestamp_u32 ? v_timestamp_u32 - s_lastTimestamp_u32 : 0);

                s_lastTimestamp_u32 = v_timestamp_u32;

                if (v_delta_u32 > 66 * 1000)
                {
                    log_b(logging::e_LogLvlInfo, "input buffer delay: %u", v_delta_u32);
                }

                if (s_deltaAcc_u32 == 0)
                {
                    s_deltaAcc_u32 = v_delta_u32 << 4;
                }
                else
                {
                    s_deltaAcc_u32 += v_delta_u32 - ((s_deltaAcc_u32 + 8) >> 4);
                }

                if ((++s_counter_u32 & 31) == 0)
                {
                    log_b(logging::e_LogLvlDebug, "average input period: %u", (s_deltaAcc_u32 + 8) >> 4);
                }
            }
        }

        // enqueue buffer immediately
        v_status_t = vxGraphParameterEnqueueReadyRef(capture_pv, 0, &doneFrames_apv[writeBufferIdx_u32], 1);
        if (v_status_t != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "failed to enqueue capture-frame-%u: %X", writeBufferIdx_u32, v_status_t);
        }

        ME_Mutex_Lock_t(&condvar_s.MEMutex_po);

        // advance index of available buffers
        writeBufferIdx_u32 = (writeBufferIdx_u32 + 1) % c_MaxBuffer2_u32;
        frameNum_u32++;

        ME_Condvar_Broadcast_t(&condvar_s);
    }

    // set state to Idle? - tbd
    ME_Mutex_UnLock_t(&condvar_s.MEMutex_po);

    v_status_t = vxWaitGraph(capture_pv);
    if (v_status_t != VX_SUCCESS)
    {
        log_b(logging::e_LogLvlError, "failed to stop graph: %X", v_status_t);
    }

    // stop sensors processing (here we need to force graph finishing somehow) - tbd
    v_status_t = app_stop_image_sensor(sensorName_pu8, sensorMask_u8);
    if (v_status_t != VX_SUCCESS)
    {
        log_b(logging::e_LogLvlError, "failed to stop image sensor: %X", v_status_t);
    }

    log_b(logging::e_LogLvlInfo, "capture graph stopped: state=%u", state_t);

    return v_status_t;
}

/// @brief  Power-up cameras (start processing)
void TIOVXVideoSensor::powerEnable_v(bool_t i_enable_b)
{
    ME_Mutex_Lock_t(&condvar_s.MEMutex_po);

    if (i_enable_b == true)
    {
        // wait for an initialization completion? what if it is active already? - tbd
        while (state_t != e_StateIdle)
        {
            ME_Condvar_Wait_t(&condvar_s);
        }

        log_b(logging::e_LogLvlInfo, "start capture graph: %d", i_enable_b);

        state_t = e_StateActive;
    }
    else
    {
        state_t = e_StateIdle;
    }

    ME_Condvar_Broadcast_t(&condvar_s);
    ME_Mutex_UnLock_t(&condvar_s.MEMutex_po);
}

/// @brief  Enable/disable test pattern
void TIOVXVideoSensor::testPatternEnable_v(uint32_t i_CameraID_t, bool_t i_enable_b)
{
    app_image_sensor_test_pattern(sensorName_pu8, i_CameraID_t, i_enable_b);
}

typedef struct VideoSensorEeprom
{
    uint16_t        revision_maj;
    uint16_t        revision_min;
    uint8_t         year[2];
    uint8_t         day[3];
    uint8_t         year1[2];
    uint8_t         day1[3];
    uint8_t         machine;
    uint8_t         zero;
    uint8_t         pad[4];

    uint8_t         width[4];
    uint8_t         height[4];
    uint8_t         ppx[4];
    uint8_t         ppy[4];
    uint8_t         i2w[6][4];
    uint8_t         w2i[6][4];
    uint8_t         ps_x[4];
    uint8_t         ps_y[4];
    uint8_t         fov[4];
    uint8_t         focal[4];
    uint8_t         rsvd[32];

}   VideoSensorEeprom_t;

static inline float32_t au8_2_f32(uint8_t *i_au8)
{
    union
    {
        uint8_t     au8[4];
        float32_t   f32;
        uint32_t    u32;

    }   val;

    return *reinterpret_cast<float32_t *>(i_au8);
#if 0
    val.au8[0] = i_au8[3];
    val.au8[1] = i_au8[2];
    val.au8[2] = i_au8[1];
    val.au8[3] = i_au8[0];

    return val.f32;
#endif
}

static inline float32_t au8_2_u32(uint8_t *i_au8)
{
    union
    {
        uint8_t     au8[4];
        float32_t   f32;
        uint32_t    u32;

    }   val;

    return *reinterpret_cast<uint32_t *>(i_au8);
#if 0
    val.au8[0] = i_au8[3];
    val.au8[1] = i_au8[2];
    val.au8[2] = i_au8[1];
    val.au8[3] = i_au8[0];

    return val.f32;
#endif
}

/// @brief  Read camera EEPROM
void TIOVXVideoSensor::readEepromData_v(variants::Camera_t i_CameraID_t)
{
    uint8_t au8eeprom[256];

    uint32_t  v_maped_cameraId_u32 = 0;
    uint32_t v_CrC_u32 = 0;
    vx_status       v_status_t;

    SVSEepromData_t   v_Default_SVSEepData_t;

    //Get the mapped SVS camera ID to read the   Eeprom intrinsics.
    switch(i_CameraID_t)
        {
        case  variants::Camera_t::e_CameraFront:
        	v_maped_cameraId_u32 = 2;
    	      break;
    	case  variants::Camera_t::e_CameraLeft:
    		v_maped_cameraId_u32 = 0;
    	      break;
    	case  variants::Camera_t::e_CameraRear:
    		v_maped_cameraId_u32 = 3;
    	      break;
    	case  variants::Camera_t::e_CameraRight:
    		v_maped_cameraId_u32 = 1;
    	      break;
    	default:
    		 ME_Debugger_F_Printf_v("\n Get maped camera ID failed\n");
    	     break;
        }

/*  // Test code added here to check CRC values periodically on console.
    if(cameraRead_status[i_CameraID_t] == true)
    {
    	static uint32_t count = 1;
    	uint32_t v_CrC_u32 =0;
    	uint32_t crc_Evalue_u32;

    	if ((count%1000 == 0) || (((count-1)%1000 == 0)) || (((count-2)%1000 == 0)) || (((count-3)%1000 == 0)))
    	{
    	   app_read_image_sensor_eeprom(sensorName_pu8, v_maped_cameraId_u32, 0x00, 256U, &au8eeprom[0]);

    	   memcpy(&v_CrC_u32, &au8eeprom[c_EepromDataCrcStartAddress_u8], c_EepromDataCrcSize_u32);

    	   crc_Evalue_u32 = crc_calculateCRC32(&au8eeprom[c_EepromDataCRCCheckStartAddress_u8], c_EepromDataCRCCheckSize_u8, CRC_INITIAL_VALUE32);

    	   ME_Debugger_F_Printf_v(" RETRY:  camera ID  %d CRC is  %x\n", i_CameraID_t, v_CrC_u32);

    	   if( (crc_Evalue_u32 == 0) && (crc_Evalue_u32 != v_CrC_u32) )
    	   {
    		   cameraRead_status[i_CameraID_t] = false;

    	   }
    	}

    	count++;
    }
*/


    if(cameraRead_status[i_CameraID_t] != true)
    {

      v_status_t = app_read_image_sensor_eeprom(sensorName_pu8, v_maped_cameraId_u32, 0x00, 256U, &au8eeprom[0]);

      if (v_status_t == VX_SUCCESS)
      {
        v_CrC_u32 = crc_calculateCRC32(&au8eeprom[c_EepromDataCRCCheckStartAddress_u8], c_EepromDataCRCCheckSize_u8, CRC_INITIAL_VALUE32);
        // Check CRC value
        memcpy(&(SVSEepData_t[i_CameraID_t].crc_u32), &au8eeprom[c_EepromDataCrcStartAddress_u8], c_EepromDataCrcSize_u32);

        if(v_CrC_u32 == SVSEepData_t[i_CameraID_t].crc_u32)
        {
          // CRC Matches
          log_b(logging::e_LogLvlInfo, "CRC Matches: ch-%u", i_CameraID_t);
          memcpy(&(SVSEepData_t[i_CameraID_t].SVSProductionData_s), &au8eeprom[c_EepromDataProductionStartAddress_u8], c_EepromDataProductionSize_u32);
          memcpy(&(SVSEepData_t[i_CameraID_t].SVSIntrinsicData_s), &au8eeprom[c_EepromDataIntrinsicStartAddress_u8], c_EepromDataIntrinsicSize_u32);

          cameraRead_status[i_CameraID_t] = true;
        }
        else
        {
          // CRC is zero and  CRC error. Use default values.
          memcpy(&SVSEepData_t[i_CameraID_t], &v_Default_SVSEepData_t, sizeof(SVSEepromData_t));
          cameraRead_status[i_CameraID_t] = false;
          
          log_b(logging::e_LogLvlInfo, "CRC Failure: ch-%u Calc_Crc-%u, EepCrc-%u", i_CameraID_t, v_CrC_u32, SVSEepData_t[i_CameraID_t].crc_u32);
          crcError_ab[i_CameraID_t] = true;
        }

      }
      else
      {
        log_b(logging::e_LogLvlInfo, "Camera eeprom read failed for  camera ID  %d ", i_CameraID_t);

        // Use default values.
        memcpy(&SVSEepData_t[i_CameraID_t], &v_Default_SVSEepData_t, sizeof(SVSEepromData_t));

        cameraRead_status[i_CameraID_t] = false;
      }


#if 0
        ME_Debugger_F_Printf_v("Eeprom Data for Camera : %d %d %d year:%x %x image width:%u\n", i_CameraID_t, v_CrC_u32, SVSEepData_t[i_CameraID_t].crc_u32,
                            SVSEepData_t[i_CameraID_t].SVSProductionData_s.finalAssemblySerialNumber_s.finalAssemblyYear_ac[0],
                            SVSEepData_t[i_CameraID_t].SVSProductionData_s.finalAssemblySerialNumber_s.finalAssemblyYear_ac[1],
                            SVSEepData_t[i_CameraID_t].SVSIntrinsicData_s.imageWidth_u32);
      uint8_t i = 0;
      for (uint8_t j = 0; j < 256/8 ; j++)
      {
          ME_Debugger_F_Printf_v("[%0X %0x %0X %0x %0X %0X %0X %0X]\n",
            au8eeprom[i],
            au8eeprom[++i],
            au8eeprom[++i],
            au8eeprom[++i],
            au8eeprom[++i],
            au8eeprom[++i],
            au8eeprom[++i],
            au8eeprom[++i],
            au8eeprom[++i]);
    }
#endif
   }

}

/// @brief  Get index of most recent camera buffer
bool_t TIOVXVideoSensor::waitVideoBuffer_b(uint32_t& o_bufferIdx_u32, const uint32_t& i_lastbufferIdx_u32, uint64_t* o_timestamp_pu64)
{
    bool_t      v_result_b = true;

    ME_Mutex_Lock_t(&condvar_s.MEMutex_po);

    if (i_lastbufferIdx_u32 < c_MaxBuffer2_u32)
    {
        o_bufferIdx_u32 = (i_lastbufferIdx_u32 + 1) % c_MaxBuffer2_u32;
    }
    else
    {
        // Out-of-range i_lastbufferIdx_u32 means that the reader is just starting,
        // and thus must synchronoze with the writer
        o_bufferIdx_u32 = writeBufferIdx_u32;
    }

    // get most recent buffer index (wait for availability)
    // writeBufferIdx_u32 points to the buffer where next frame is being written
    while (o_bufferIdx_u32 == writeBufferIdx_u32)
    {
        ME_Condvar_Wait_t(&condvar_s);
    }

    if (o_timestamp_pu64 != NULL)
    {
        uint64_t    v_minTimestamp_u64 = ~0UL;

        // find frame with minimal non-zero timestamp
        for (uint8_t v_cameraId_u8 = 0U; v_cameraId_u8 < camerasNumber_u8; v_cameraId_u8++)
        {
            uint64_t    v_timestamp_u64 = timestamp_aau64[o_bufferIdx_u32][v_cameraId_u8];

            if (v_timestamp_u64 != 0UL && v_minTimestamp_u64 > v_timestamp_u64)
            {
                v_minTimestamp_u64 = v_timestamp_u64;
            }
        }

        *o_timestamp_pu64 = v_minTimestamp_u64;
    }

    ME_Mutex_UnLock_t(&condvar_s.MEMutex_po);

    // frameNum_u32 is producer index, calculate consumer index based on
    // difference between writeBufferIdx_u32 and o_bufferIdx_u32
    log_b(logging::e_LogLvlDebug, "frame ready: %u(%u)", o_bufferIdx_u32,
            frameNum_u32 - (writeBufferIdx_u32 - o_bufferIdx_u32 - 1 + c_MaxBuffer2_u32) % c_MaxBuffer2_u32);

    return v_result_b;
}

/// @brief  Get index of most recent camera buffer
bool_t TIOVXVideoSensor::getVideoBuffer_b(uint32_t& o_bufferIdx_u32)
{
    bool_t      v_result_b = true;
    vx_status   v_status_t;

    ME_Mutex_Lock_t(&condvar_s.MEMutex_po);

    o_bufferIdx_u32 = (writeBufferIdx_u32 + c_MaxBuffer2_u32 - 1) % c_MaxBuffer2_u32;

    ME_Mutex_UnLock_t(&condvar_s.MEMutex_po);

    return v_result_b;
}

/// @brief  Release video buffers to a graph up to given index
bool_t TIOVXVideoSensor::releaseVideoBuffer_b(uint32_t i_bufferIdx_u32)
{
    bool_t      v_result_b = true;
    vx_status   v_status_t;
    uint32_t    v_bufferIdx_u32;

    // as we are submitting buffer right after dequeueing, it's a no-op
    return true;
}

/// @brief  Return sensors failure mask
uint8_t TIOVXVideoSensor::getFailureMask_u8()
{
    return failureMask_u8;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief  Utility API used to add a graph parameter from a node, node parameter index
static inline void add_graph_parameter_by_node_index(vx_graph graph, vx_node node, vx_uint32 node_parameter_index)
{
    vx_parameter    parameter = vxGetParameterByIndex(node, node_parameter_index);
    vx_status       status;

    if ((status = vxGetStatus((vx_reference)parameter)) != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "failed to get parameter-%u from node %p: %X\n", node_parameter_index, node, status);
    }

    status = vxAddParameterToGraph(graph, parameter);
    if (status != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "failed to add graph parameter-%u to node %p: %X\n", node_parameter_index, node, status);
    }

    uint32_t        type;
    vxQueryParameter(parameter, VX_PARAMETER_TYPE, &type, sizeof(type));

    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                           "add param-%u: node=%p, type=%u\n", node_parameter_index, node);

    vxReleaseParameter(&parameter);
}

/// @brief  Capturing interface creation
vx_status TIOVXVideoSensor::createCaptureNode(uint8_t i_instanceId_u8, bool_t i_useRawImage_b)
{
    vx_status       v_status_t;
    vx_reference    v_sampleImage_pv;

    if (i_useRawImage_b == true)
    {
        v_sampleImage_pv = (vx_reference)tivxCreateRawImage(context_pv, &sensorParams_t.sensorInfo.raw_params);
        if ((v_status_t = vxGetStatus(v_sampleImage_pv)) != VX_SUCCESS)
        {
            logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                                   "%s: failed to create sample raw image: %X\n", sensorName_pu8, v_status_t);
            return v_status_t;
        }
    }
    else
    {
        uint32_t    v_inputWidth_u32 = sensorParams_t.sensorInfo.raw_params.width;
        uint32_t    v_inputHeight_u32 = sensorParams_t.sensorInfo.raw_params.height;

        v_sampleImage_pv = (vx_reference)vxCreateImage(context_pv, v_inputWidth_u32, v_inputHeight_u32, inputFormat_u32);
        if ((v_status_t = vxGetStatus(v_sampleImage_pv)) != VX_SUCCESS)
        {
            logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                                   "%s: sampleImage creation failed: %X\n", sensorName_pu8, v_status_t);
            return v_status_t;
        }
    }

    // Creating object arrays to be used as output to capture node
    for (uint32_t v_bufId_u32 = 0; v_bufId_u32 < c_MaxBuffer2_u32; v_bufId_u32++)
    {
        captureFrames_apv[v_bufId_u32] = vxCreateObjectArray(context_pv, (vx_reference)v_sampleImage_pv, camerasNumber_u8);
        if ((v_status_t = vxGetStatus((vx_reference)captureFrames_apv[v_bufId_u32])) != VX_SUCCESS)
        {
            logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                                   "%s: captureFrames[#%u] creation failed: %X\n", sensorName_pu8, v_bufId_u32, v_status_t);
            return v_status_t;
        }
    }

    if (i_useRawImage_b == true)
    {
        tivxReleaseRawImage((tivx_raw_image*)&v_sampleImage_pv);
    }
    else
    {
        vxReleaseImage((vx_image*)&v_sampleImage_pv);
    }

    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                           "%s: setup capture: instId=%u, numCh=%u, numDataLanes=%u\n",
                           sensorName_pu8, i_instanceId_u8, camerasNumber_u8, sensorParams_t.sensorInfo.numDataLanes);

    // Capture initialization
    tivx_capture_params_t v_captureParams;
    tivx_capture_params_init(&v_captureParams);
    v_captureParams.numInst = 1U;
    v_captureParams.numCh = camerasNumber_u8;
    v_captureParams.mask = sensorMask_u8;//i_instanceId_u8 == 0 ? 0xf : 0x1;
	for (uint32_t v_chId_u32 = 0; v_chId_u32 < camerasNumber_u8; v_chId_u32++)
    {
        v_captureParams.chVcNum[v_chId_u32] = v_chId_u32;
        v_captureParams.chInstMap[v_chId_u32] = i_instanceId_u8;
    }

    v_captureParams.instId[0U] = i_instanceId_u8;
    v_captureParams.instCfg[0U].enableCsiv2p0Support = (uint32_t)vx_true_e;
    v_captureParams.instCfg[0U].numDataLanes = sensorParams_t.sensorInfo.numDataLanes;
    v_captureParams.instCfg[0U].numPixels = 1U;
    memcpy(v_captureParams.instCfg[0U].dataLanesMap, sensorParams_t.sensorInfo.dataLanesMap, sizeof(sensorParams_t.sensorInfo.dataLanesMap));

    // specify timeouts
    v_captureParams.timeout = 90;
    v_captureParams.timeoutInitial = 500;

    // Capture parameters object creation
    vx_user_data_object v_captureParamObj_pv;
    v_captureParamObj_pv = vxCreateUserDataObject(context_pv, "tivx_capture_params_t", sizeof(tivx_capture_params_t), &v_captureParams);
    if ((v_status_t = vxGetStatus((vx_reference)v_captureParamObj_pv)) != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "%s: captureParamObj creation failed: %X\n", sensorName_pu8, v_status_t);
        return v_status_t;
    }

    // Allocate error-frame
    errorFrame_pv = tivxCreateRawImage(context_pv, &sensorParams_t.sensorInfo.raw_params);
    if ((v_status_t = vxGetStatus((vx_reference)errorFrame_pv)) != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "%s: tivxCreateRawImage failed: %X\n", sensorName_pu8, v_status_t);
        return v_status_t;
    }

    // initialize it somehow? - tbd
    vx_rectangle_t v_rect_o;
    v_rect_o.start_x = 0;
    v_rect_o.start_y = 0;
    v_rect_o.end_x = sensorParams_t.sensorInfo.raw_params.width;
    v_rect_o.end_y = sensorParams_t.sensorInfo.raw_params.height;

    vx_map_id   v_map_pv;
    void*       v_buf_pv;
    vx_imagepatch_addressing_t v_imageAddr_o;
    v_status_t = tivxMapRawImagePatch(errorFrame_pv, &v_rect_o, 0, &v_map_pv, &v_imageAddr_o, &v_buf_pv, VX_READ_ONLY, VX_MEMORY_TYPE_HOST, TIVX_RAW_IMAGE_ALLOC_BUFFER);
    if (v_status_t == VX_SUCCESS)
    {
        memset(v_buf_pv, 0x00, v_imageAddr_o.stride_y * (sensorParams_t.sensorInfo.raw_params.height + sensorParams_t.sensorInfo.raw_params.meta_height_before + sensorParams_t.sensorInfo.raw_params.meta_height_after));
        tivxUnmapRawImagePatch(errorFrame_pv, v_map_pv);
    }

    // Capture node creation
    captureNode_pv = tivxCaptureNode(capture_pv, v_captureParamObj_pv, captureFrames_apv[0]);
    if ((v_status_t = vxGetStatus((vx_reference)captureNode_pv)) != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "%s: captureNode creation failed: %X\n", sensorName_pu8, v_status_t);
        return v_status_t;
    }
    else
    {
        vxSetNodeTarget(captureNode_pv, VX_TARGET_STRING, (i_instanceId_u8 == 0 ? TIVX_TARGET_CAPTURE1 : TIVX_TARGET_CAPTURE2));
        vxSetReferenceName((vx_reference)captureNode_pv, "Capture_node");
    }

    vxReleaseUserDataObject(&v_captureParamObj_pv);

    if (iss_b == false)
    {
        // add parameter to the graph
        add_graph_parameter_by_node_index(capture_pv, captureNode_pv, 1);
    }
    else
    {
        // specify number of intermediate buffers
        tivxSetNodeParameterNumBufByIndex(captureNode_pv, 1, c_MaxBuffer2_u32);
    }

    return v_status_t;
}

/// @brief  Initialize image sensor
vx_status TIOVXVideoSensor::setupImageSensor()
{
    uint32_t    v_featuresEnabled_u32 = 0U;
    vx_status   v_status_t;

    // Check for supported sensor features. It is upto the application to decide
    // which features should be enabled. This demo app enables WDR, DCC and 2A
    // if the sensor supports it.
    uint32_t    v_features_u32 = sensorParams_t.sensorInfo.features;

    if ((v_features_u32 & ISS_SENSOR_FEATURE_COMB_COMP_WDR_MODE) != 0U)
    {
        logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                               "WDR mode is supported\n");
        v_featuresEnabled_u32 |= ISS_SENSOR_FEATURE_COMB_COMP_WDR_MODE;
    }
    else
    {
        logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                               "WDR mode is not supported. Defaulting to linear\n");
        v_featuresEnabled_u32 |= ISS_SENSOR_FEATURE_LINEAR_MODE;
    }

    if ((v_features_u32 & ISS_SENSOR_FEATURE_MANUAL_EXPOSURE) != 0U)
    {
        logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                               "Exposure control is supported\n");
        v_featuresEnabled_u32 |= ISS_SENSOR_FEATURE_MANUAL_EXPOSURE;
    }

    if ((v_features_u32 & ISS_SENSOR_FEATURE_MANUAL_GAIN) != 0U)
    {
        logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                               "Gain control is supported\n");
        v_featuresEnabled_u32 |= ISS_SENSOR_FEATURE_MANUAL_GAIN;
    }

#if 0   // disabled for some reason
    if ((v_features_u32 & ISS_SENSOR_FEATURE_CFG_UC1) != 0U)
    {
        logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                               "CMS Usecase is supported\n");
        v_featuresEnabled_u32 |= ISS_SENSOR_FEATURE_CFG_UC1;
    }
#endif

    if ((v_features_u32 & ISS_SENSOR_FEATURE_DCC_SUPPORTED) != 0U)
    {
        logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                               "DCC is supported\n");
        v_featuresEnabled_u32 |= ISS_SENSOR_FEATURE_DCC_SUPPORTED;
    }

    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                           "Sensor width = %d\n", sensorParams_t.sensorInfo.raw_params.width);
    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                           "Sensor height = %d\n", sensorParams_t.sensorInfo.raw_params.height);
    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                           "Sensor DCC ID = %d\n", sensorParams_t.dccId);
    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                           "Sensor Supported Features = 0x%x\n", v_features_u32);
    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                           "Sensor Enabled Features = 0x%x\n", v_featuresEnabled_u32);
    v_status_t = app_init_image_sensor(sensorName_pu8, v_featuresEnabled_u32, sensorMask_u8);
    if (v_status_t != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "failed to initialize image sensor: %X\n", v_status_t);
        return v_status_t;
    }

    return v_status_t;
}

/// @brief   VISS interface creation
vx_status TIOVXVideoSensor::createCogenteVissAEWBNode()
{
    vx_status   v_status_t = VX_SUCCESS;

    // Allocate sample image for an object array
    vx_image    v_sampleImage_pv;
    uint32_t    v_inputWidth_u32 = sensorParams_t.sensorInfo.raw_params.width;
    uint32_t    v_inputHeight_u32 = sensorParams_t.sensorInfo.raw_params.height;

    v_sampleImage_pv = vxCreateImage(context_pv, v_inputWidth_u32, v_inputHeight_u32, inputFormat_u32);
    if ((v_status_t = vxGetStatus((vx_reference)v_sampleImage_pv)) != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "%s: sampleImage creation failed: %X\n", sensorName_pu8, v_status_t);
        return VX_FAILURE;
    }

    for (uint32_t v_bufId_u32 = 0U; v_bufId_u32 < c_MaxBuffer2_u32; v_bufId_u32++)
    {
        // Allocate object array for the output frames
        vissOutFrames_apv[v_bufId_u32] = vxCreateObjectArray(context_pv, (vx_reference)v_sampleImage_pv, camerasNumber_u8);
        if ((v_status_t = vxGetStatus((vx_reference)vissOutFrames_apv[v_bufId_u32])) != VX_SUCCESS)
        {
            logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                                   "%s: vissOutFrames[#%u] creation failed: %X\n", sensorName_pu8, v_bufId_u32, v_status_t);
            return v_status_t;
        }

        vissOutImage_apv[v_bufId_u32] = (vx_image)vxGetObjectArrayItem(vissOutFrames_apv[v_bufId_u32], 0);
        if ((v_status_t = vxGetStatus((vx_reference)vissOutImage_apv[v_bufId_u32])) != VX_SUCCESS)
        {
            logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                                   "%s: vissOutImage[#%u] creation failed: %X\n", sensorName_pu8, v_bufId_u32, v_status_t);
            return v_status_t;
        }
    }

    vxReleaseImage(&v_sampleImage_pv);

    // create VISS configuration
    vx_user_data_object     v_cfgExemplar_pv;
    v_cfgExemplar_pv = vxCreateUserDataObject(context_pv, "tivx_vpac_cuc_isp_params_t", sizeof(tivx_vpac_cuc_isp_params_t), NULL);
    if ((v_status_t = vxGetStatus((vx_reference)v_cfgExemplar_pv)) != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "%s: cfgExemplar creation failed: %X\n", sensorName_pu8, v_status_t);
        return v_status_t;
    }

    vx_object_array         v_cfgArray_pv;
    v_cfgArray_pv = vxCreateObjectArray(context_pv, (vx_reference)v_cfgExemplar_pv, camerasNumber_u8);
    vxReleaseUserDataObject(&v_cfgExemplar_pv);

    rc_settings     v_rcPrms_t;
    strcpy(v_rcPrms_t.context_name, sensorName_pu8);

    uint8_t v_sensorMask_u8 = sensorMask_u8;
    uint8_t v_contextId_u8 = 0U;

    for (uint8_t v_channel_u8 = 0U; v_sensorMask_u8 != 0U; v_channel_u8++)
    {
        if ((v_sensorMask_u8 & 1U) != 0U)
        {
            vx_map_id   v_map_pv;
            void*       v_buf_pv;

            v_cfgExemplar_pv = (vx_user_data_object)vxGetObjectArrayItem(v_cfgArray_pv, v_contextId_u8);
            vxMapUserDataObject(v_cfgExemplar_pv, 0, sizeof(tivx_vpac_cuc_isp_params_t), &v_map_pv, &v_buf_pv, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST, 0);
            if (v_buf_pv == NULL)
            {
                logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                                       "%s: cam-%u: failed to map configuration\n", sensorName_pu8, v_channel_u8);
                return VX_FAILURE;
            }

            logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                                   "%s: channel-id: %u, context-id: %u\n", sensorName_pu8, v_channel_u8, v_contextId_u8);

            tivx_vpac_cuc_isp_params_t  *v_config_po = (tivx_vpac_cuc_isp_params_t *)v_buf_pv;
            tivx_vpac_cuc_isp_params_init(v_config_po);
            v_config_po->sensor_id        = sensorParams_t.dccId;
            v_config_po->mux_output0      = 0;
            v_config_po->mux_output1      = 0;
            v_config_po->mux_output2      = (inputFormat_u32 == VX_DF_IMAGE_NV12 ? TIVX_VPAC_VISS_MUX2_NV12 : TIVX_VPAC_VISS_MUX2_YUV422);
            v_config_po->mux_output3      = 0;
            v_config_po->mux_output4      = 3;
            v_config_po->channel_id       = v_channel_u8;
            v_config_po->context_id       = v_contextId_u8++;
            v_config_po->enable_dma_quirk = 1;
            memcpy(&v_config_po->rc_prms, &v_rcPrms_t, sizeof(v_rcPrms_t));

            vxUnmapUserDataObject((vx_user_data_object)v_cfgExemplar_pv, v_map_pv);
            vxReleaseUserDataObject(&v_cfgExemplar_pv);
        }

        v_sensorMask_u8 = v_sensorMask_u8 >> 1U;
    }

    vx_user_data_object v_vissCfg_pv;
    v_vissCfg_pv = (vx_user_data_object)vxGetObjectArrayItem(v_cfgArray_pv, 0);
    if ((v_status_t = vxGetStatus((vx_reference)v_vissCfg_pv)) != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "%s: failed to get config: %X\n", sensorName_pu8, v_status_t);
        return v_status_t;
    }

    // Get sample RAW Image
    tivx_raw_image  v_rawImage_pv;
    v_rawImage_pv = (tivx_raw_image)vxGetObjectArrayItem(captureFrames_apv[0], 0);
    if ((v_status_t = vxGetStatus((vx_reference)v_rawImage_pv)) != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "failed to get raw-image: %X\n", v_status_t);
        return v_status_t;
    }

    // ISP node creation
    vissNode_pv = tivxVpacCucVissNode(
        capture_pv,
        v_vissCfg_pv,
        v_rawImage_pv,
        NULL,
        NULL,
        vissOutImage_apv[0],
        NULL,
        NULL);

    if ((v_status_t = vxGetStatus((vx_reference)vissNode_pv)) != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "vissNode create failed: %X\n", v_status_t);
        return v_status_t;
    }

    vxSetReferenceName((vx_reference)vissNode_pv, "CUC_VISS");
    vxSetNodeTarget(vissNode_pv, VX_TARGET_STRING, TIVX_TARGET_VPAC_CUC_VISS);

    vx_bool v_replicate_ba[] = {
        vx_true_e, vx_true_e, vx_false_e, vx_false_e, vx_true_e, vx_false_e, vx_false_e
    };
    v_status_t = vxReplicateNode(capture_pv, vissNode_pv, v_replicate_ba, 7);
    if (v_status_t != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "failed to replicate node: %d\n", v_status_t);
        return v_status_t;
    }

    v_rcNode_pv = tivxVpacCucRcNode(
        capture_pv,
        v_vissCfg_pv,
        v_rawImage_pv,
        NULL);

    if ((v_status_t = vxGetStatus((vx_reference)v_rcNode_pv)) != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "rcNode create failed: %X\n", v_status_t);
        return v_status_t;
    }

    vxSetReferenceName((vx_reference)v_rcNode_pv, "CUC_RC");
    vxSetNodeTarget(v_rcNode_pv, VX_TARGET_STRING, TIVX_TARGET_VPAC_CUC_RC);

    vx_bool v_rcReplicate_ba[] = {
        vx_true_e, vx_true_e, vx_false_e
    };
    v_status_t = vxReplicateNode(capture_pv, v_rcNode_pv, v_rcReplicate_ba, 3);
    if (v_status_t != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "rcNode replication failed: %X\n", v_status_t);
        return v_status_t;
    }

    // add graph parameter for output buffers
    add_graph_parameter_by_node_index(capture_pv, vissNode_pv, 4);

    vxReleaseUserDataObject(&v_vissCfg_pv);
    tivxReleaseRawImage(&v_rawImage_pv);

    params_cmd = vxCreateUserDataObject(context_pv, "tivxIspParamsCmd", sizeof(isp_user_parameters_t), NULL);

    return v_status_t;
}

/// @brief  Initialize video sensor module
bool_t TIOVXVideoSensor::initVideoSensor_b(vx_context i_context_pv, char* i_sensor_pu8, uint8_t i_mask_u8, bool_t i_iss_b, uint8_t i_instanceId_u8, uint32_t i_inputFormat_u32)
{
    bool_t          v_result_b = true;
    vx_status       v_status_t;

    // save OVX context (no addref for context)
    context_pv = i_context_pv;
    sensorName_pu8 = i_sensor_pu8;
    sensorMask_u8 = i_mask_u8;
    camerasNumber_u8 = __builtin_popcount(sensorMask_u8);
    inputFormat_u32 = i_inputFormat_u32;
    iss_b = i_iss_b;

    // Get sensor parameters
    v_status_t = app_query_image_sensor(sensorName_pu8, &sensorParams_t);
    if (v_status_t != VX_SUCCESS)
    {
        log_b(logging::e_LogLvlError, "app_query_image_sensor failed: %X", v_status_t);
        v_result_b = false;
    }
    else
    {
        log_b(logging::e_LogLvlInfo, "params: %d*%d, dcc: %d",
              sensorParams_t.sensorInfo.raw_params.width,
              sensorParams_t.sensorInfo.raw_params.height,
              sensorParams_t.dccId);
    }

    // create execution graph
    if (v_result_b == true)
    {
        capture_pv = vxCreateGraph(context_pv);
        if ((v_status_t = vxGetStatus((vx_reference)capture_pv)) != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "graph creation failed: %X", v_status_t);
            v_result_b = false;
        }

        vxSetReferenceName((vx_reference)capture_pv, "CAPTURE");
    }

    if (v_result_b == true)
    {
        // create capture interface (use raw image for VISS)
        v_status_t = createCaptureNode(i_instanceId_u8, (iss_b ? true : false));
        if (v_status_t != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "failed to create capture node: %X", v_status_t);
            v_result_b = false;
        }
    }

    if (v_result_b == true && c_sensorInit == true)
    {
        // initialize image sensor interface
        if ((v_status_t = setupImageSensor()) != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "image sensor initialization failed: %X", v_status_t);
            v_result_b = false;
        }
    }

    if (v_result_b == true && iss_b == true)
    {
        // create VISS/AEWB node
        if ((v_status_t = createCogenteVissAEWBNode()) != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "VISS/AEWB node creation failed: %X", v_status_t);
            v_result_b = false;
        }
    }

    if (v_result_b == true)
    {
        vx_graph_parameter_queue_params_t v_graphParamsQueue_ao[1];

        // Set graph schedule config such that graph parameter @ index 0 is enqueuable
        v_graphParamsQueue_ao[0].graph_parameter_index = 0;
        v_graphParamsQueue_ao[0].refs_list_size = c_MaxBuffer2_u32;
        v_graphParamsQueue_ao[0].refs_list = (iss_b ? (vx_reference*)vissOutImage_apv : (vx_reference*)captureFrames_apv);

        v_status_t = tivxSetGraphPipelineDepth(capture_pv, c_MaxBuffer2_u32);
        if (v_status_t != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "failed to set graph depth: %X", v_status_t);
            v_result_b = false;
        }

        // Schedule mode auto is used, here we don't need to call vxScheduleGraph.
        // Graph gets scheduled automatically as refs are enqueued to it
        v_status_t = vxSetGraphScheduleConfig(capture_pv, VX_GRAPH_SCHEDULE_MODE_QUEUE_AUTO, 1, v_graphParamsQueue_ao);
        if (v_status_t != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "failed to set graph config: %X", v_status_t);
            v_result_b = false;
        }

        if ((v_status_t = vxVerifyGraph(capture_pv)) != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "graph verification failed: %X", v_status_t);
            v_result_b = false;
        }

        tivxExportGraphToDot(capture_pv, (char*)"/tmp", (char*)(std::string("capture_graph_") + std::to_string(i_instanceId_u8)).c_str());

        log_b(logging::e_LogLvlInfo, "capture graph created");
    }

    if (v_result_b == true)
    {
        // force allocation of output frames
        v_status_t = ownReferenceAllocMem((vx_reference)(iss_b ? vissOutFrames_apv[0] : captureFrames_apv[0]));
        if (v_status_t != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "allocation status: %X", v_status_t);
            v_result_b = false;
        }
    }

    // save video input descriptors
    vx_object_array    *v_array_apv = (iss_b ? vissOutFrames_apv : captureFrames_apv);

    for (uint32_t v_id_u32 = 0U; v_result_b == true && v_id_u32 < c_MaxBuffer2_u32; v_id_u32++)
    {
        for (uint32_t v_cameraId_u32 = 0U; v_cameraId_u32 < camerasNumber_u8; v_cameraId_u32++)
        {
            vx_reference    v_outFrame_pv = vxGetObjectArrayItem(v_array_apv[v_id_u32], v_cameraId_u32);
            if ((v_status_t = vxGetStatus(v_outFrame_pv)) != VX_SUCCESS)
            {
                log_b(logging::e_LogLvlError, "cam-%u: failed to get output frame-%u", v_cameraId_u32, v_id_u32);
                v_result_b = false;
            }

            uint16_t                v_objID_u16 = ownReferenceGetObjDescId(v_outFrame_pv);
            tivx_obj_desc_t*        v_desc_po;
            tivxGetObjDescList(&v_objID_u16, (tivx_obj_desc_t **)&v_desc_po, 1);

            VideoInputBufferDesc2_t&    v_bufferDesc_ro = videoInputBuffer_apv[v_cameraId_u32];

            tivx_shared_mem_ptr_t*  v_mem_apo;

            uint8_t*   v_addr_apu32[3];

            if (v_desc_po->type == TIVX_OBJ_DESC_IMAGE)
            {
                tivx_obj_desc_image_t*  v_image_po = reinterpret_cast<tivx_obj_desc_image_t*>(v_desc_po);

                v_mem_apo = v_image_po->mem_ptr;

                if (v_id_u32 == 0U)
                {
                    v_bufferDesc_ro.size_au32[0] = v_image_po->width;
                    v_bufferDesc_ro.size_au32[1] = v_image_po->height;
                    v_bufferDesc_ro.stride_au32[0] = v_image_po->imagepatch_addr[0].stride_y;
                    v_bufferDesc_ro.stride_au32[1] = v_image_po->imagepatch_addr[1].stride_y;
                    v_bufferDesc_ro.stride_au32[2] = v_image_po->imagepatch_addr[2].stride_y;
                    v_bufferDesc_ro.bufsize_au32[0] = v_image_po->mem_size[0];
                    v_bufferDesc_ro.bufsize_au32[1] = v_image_po->mem_size[1];
                    v_bufferDesc_ro.bufsize_au32[2] = v_image_po->mem_size[2];
                    v_bufferDesc_ro.numOfBuffer_u32 = c_MaxBuffer2_u32;
                }
            }
            else
            {
                tivx_obj_desc_raw_image_t*  v_rawImage_po = reinterpret_cast<tivx_obj_desc_raw_image_t*>(v_desc_po);

                v_mem_apo = v_rawImage_po->mem_ptr;

                if (v_id_u32 == 0U)
                {
                    v_bufferDesc_ro.size_au32[0] = v_rawImage_po->params.width;
                    v_bufferDesc_ro.size_au32[1] = v_rawImage_po->params.height;
                    v_bufferDesc_ro.stride_au32[0] = v_rawImage_po->imagepatch_addr[0].stride_y;
                    v_bufferDesc_ro.stride_au32[1] = v_rawImage_po->imagepatch_addr[1].stride_y;
                    v_bufferDesc_ro.stride_au32[2] = v_rawImage_po->imagepatch_addr[2].stride_y;
                    v_bufferDesc_ro.bufsize_au32[0] = v_rawImage_po->mem_size[0];
                    v_bufferDesc_ro.bufsize_au32[1] = v_rawImage_po->mem_size[1];
                    v_bufferDesc_ro.bufsize_au32[2] = v_rawImage_po->mem_size[2];
                    v_bufferDesc_ro.numOfBuffer_u32 = c_MaxBuffer2_u32;
                }
            }

            if (v_id_u32 == 0)
            {
                switch (inputFormat_u32)
                {
                case VX_DF_IMAGE_NV12:
                    v_bufferDesc_ro.format_u32 = SCREEN_FORMAT_NV12;
                    break;
                case VX_DF_IMAGE_UYVY:
                    v_bufferDesc_ro.format_u32 = SCREEN_FORMAT_UYVY;
                    break;
                default:
                    v_bufferDesc_ro.format_u32 = SCREEN_FORMAT_BYTE;
                }
            }

            uint8_t* v_addr_apu8[3] = {
                (uint8_t*)tivxMemShared2TargetPtr(&v_mem_apo[0]),
                (uint8_t*)tivxMemShared2TargetPtr(&v_mem_apo[1]),
                (uint8_t*)tivxMemShared2TargetPtr(&v_mem_apo[2]),
            };

            v_bufferDesc_ro.buffers_apv[v_id_u32] = v_addr_apu8[0];
            v_bufferDesc_ro.offset_aau32[v_id_u32][0] = 0;
            v_bufferDesc_ro.offset_aau32[v_id_u32][1] = (v_addr_apu8[1] ? (uint32_t)(v_addr_apu8[1] - v_addr_apu8[0]) : 0U);
            v_bufferDesc_ro.offset_aau32[v_id_u32][2] = (v_addr_apu8[2] ? (uint32_t)(v_addr_apu8[2] - v_addr_apu8[0]) : 0U);

            log_b(logging::e_LogLvlInfo, "cam-%u: buf-%d: %p, desc: %X", v_cameraId_u32, v_id_u32, v_bufferDesc_ro.buffers_apv[v_id_u32], v_objID_u16);
        }
    }

    if (v_result_b == true)
    {
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, graphProcessingThread_pv, this, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, "VideoInputGraphThread");

        if (iss_b)
        {
            // create input buffer verification thread
            ThreadHandle_s v_verifyThread_s;
            ME_Thread_Create_t(&v_verifyThread_s, inputBufferVerifyThread_pv, this, ME_Thread_C_DefaultStackSize_t);
            ME_Thread_SetPriority_t(&v_verifyThread_s, e_PriorityRealtime);
            ME_Thread_SetName_t(&v_verifyThread_s, "InputBufferVerifyThread");
        }
        else
        {
            log_b(logging::e_LogLvlWarning, "input buffer verify supported for iss only");
        }

        initDone_b = true;
        state_t = e_StateIdle;

        ME_Condvar_Broadcast_t(&condvar_s);

        log_b(logging::e_LogLvlError, "TIOVX Video Sensor created");
    }
    else
    {
        log_b(logging::e_LogLvlError, "TIOVX Video Sensor creation failed");
    }

#if 1   // no EEPROM yet
    for (uint32_t i_cameraId_t = 0; i_cameraId_t < camerasNumber_u8; i_cameraId_t++)
    {
        readEepromData_v(static_cast<variants::Camera_t>(i_cameraId_t));
    }
#endif

    return v_result_b;
}

/// @brief  Retrieve individual video buffer descriptor
bool_t TIOVXVideoSensor::getVideoInputBuffer_b(uint32_t i_CameraID_t, VideoInputBufferDesc2_t& o_VideoInputBufferDesc_rt)
{
    bool_t              v_result_b = true;

    ME_Mutex_Lock_t(&condvar_s.MEMutex_po);
    while (initDone_b == false)
    {
        ME_Condvar_Wait_t(&condvar_s);
    }
    ME_Mutex_UnLock_t(&condvar_s.MEMutex_po);

    o_VideoInputBufferDesc_rt = videoInputBuffer_apv[i_CameraID_t];

    return v_result_b;
}

bool_t TIOVXVideoSensor::submitInputBufferVerificationRequest_b(uint32_t bufferIdx_u32, const uint16_t ctlval_au16[], const bool_t ctlvalValid_ab[])
{
    bool_t v_result_b = false;

    ME_Mutex_Lock_t(&verifyCondvar_s.MEMutex_po);

    if ((bufferIdx_u32 < c_MaxBuffer2_u32) && ((verifyHead_u32 + 1) % c_MaxVideoInputBufferVerifyRequests_u32 != verifyTail_u32))
    {
        verifyQueue_ao[verifyHead_u32].idx_u32 = bufferIdx_u32;
        memcpy(verifyQueue_ao[verifyHead_u32].ctlval_au16, ctlval_au16, sizeof(verifyQueue_ao[verifyHead_u32].ctlval_au16));
        memcpy(verifyQueue_ao[verifyHead_u32].ctlvalValid_ab, ctlvalValid_ab, sizeof(verifyQueue_ao[verifyHead_u32].ctlvalValid_ab));

        verifyHead_u32 = (verifyHead_u32 + 1) % c_MaxVideoInputBufferVerifyRequests_u32;
        ME_Condvar_Broadcast_t(&verifyCondvar_s);

        v_result_b = true;
    }

    ME_Mutex_UnLock_t(&verifyCondvar_s.MEMutex_po);

    return v_result_b;
}

/// @brief get user parameters from ISP
isp_user_parameters_t* TIOVXVideoSensor::getUserIspParameters()
{
    return &params_cmd_data;
}

/// @brief send user parameters to ISP
vx_status TIOVXVideoSensor::sendUserIspParameters()
{
    vx_status status = VX_SUCCESS;

    status = vxCopyUserDataObject(params_cmd, 0, sizeof(isp_user_parameters_t),\
                  &params_cmd_data, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST);

    if(status == VX_SUCCESS)
    {
        vx_reference refs[1];

        refs[0] = (vx_reference)params_cmd;

        status = tivxNodeSendCommand(v_rcNode_pv, TIVX_CONTROL_CMD_SEND_TO_ALL_REPLICATED_NODES,
                                 TIVX_KERNEL_VPAC_CUC_RC_USER_CMD,
                                 refs, sizeof(refs) / sizeof(refs[0]));

        if(VX_SUCCESS != status)
        {
            log_b(logging::e_LogLvlError, "RC node send command failed!\n");
        }
        else
        {
            log_b(logging::e_LogLvlInfo, "RC node send command success!\n");
        }
    }
    else
    {
        log_b(logging::e_LogLvlError, "Failed to copy user data object\n");
    }

    return status;
}

/// @brief  Video input graph constructor
TIOVXVideoInput::TIOVXVideoInput()
: svsVideoSensor()
  //, dmcVideoSensor()
{
}

/// @brief  Video input graph destructor
TIOVXVideoInput::~TIOVXVideoInput()
{
}

/// @brief  Logging function
bool_t TIOVXVideoInput::log_b(logging::LogLevel_e i_level_e, const char *i_format_pc, ...) const
{
    char        v_buffer_ac[256];
    va_list     v_args_pt;

    va_start(v_args_pt, i_format_pc);

    vsnprintf(v_buffer_ac, sizeof(v_buffer_ac) - 1, i_format_pc, v_args_pt);

    return logging::Logger::log_b(i_level_e, logging::e_LogModeMaskPrintf, "%s", v_buffer_ac);
}

/// @brief  Initialize video input module
bool_t TIOVXVideoInput::initVideoInput_b(vx_context i_context_pv)
{
    bool_t          v_result_b = true;
    vx_status       v_status_t;

    // enumerate sensors (use App framework)
    static char     s_availableSensorNames_au8[ISS_SENSORS_MAX_SUPPORTED_SENSOR][ISS_SENSORS_MAX_NAME];
    char*           v_sensorList_apu8[ISS_SENSORS_MAX_SUPPORTED_SENSOR];
    for (uint32_t v_count_u32 = 0; v_count_u32 < ISS_SENSORS_MAX_SUPPORTED_SENSOR; v_count_u32++)
    {
        v_sensorList_apu8[v_count_u32] = s_availableSensorNames_au8[v_count_u32];
    }
    static char*    s_svsName_pu8 = (char*)"ox03c10";
    if (c_sensorInit == true)
    {
        vx_uint8        v_numSensorsFound_u8;
        v_status_t = app_enumerate_image_sensor(v_sensorList_apu8, &v_numSensorsFound_u8);
        if (v_status_t != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "failed to enumerate image sensors: %X", v_status_t);
            v_result_b = false;
        }
        else
        {
        // select OV2311 sensor for DMA camera (ID=7), channel mask 0x1
        //v_result_b &= dmcVideoSensor.initVideoSensor_b(i_context_pv, v_sensorList_apu8[7], 0x10U, false, 1U, VX_DF_IMAGE_U8);

        // select AR0233 sensor for cameras Front..Right (ID=1), channel mask 0xF
            log_b(logging::e_LogLvlError, "succeeded to enumerate image sensors: %X", v_status_t);
        //v_result_b &= svsVideoSensor.initVideoSensor_b(i_context_pv, v_sensorList_apu8[3], 0xFU, true, 0U, VX_DF_IMAGE_NV12);
        }
    }

    if(true == v_result_b)
    {
        v_result_b &= svsVideoSensor.initVideoSensor_b(i_context_pv, s_svsName_pu8/*v_sensorList_apu8[3]*/, 0xFU, true, 0U, VX_DF_IMAGE_NV12);
    }

    if (v_result_b == true)
    {
        log_b(logging::e_LogLvlError, "TIOVX Video Input created");
    }
    else
    {
        log_b(logging::e_LogLvlError, "TIOVX Video Input creation failed");
    }

    return v_result_b;
}

/// @brief  Enable/disable test pattern
void TIOVXVideoInput::testPatternEnable_v(variants::Camera_t i_CameraID_t, bool i_enable_b)
{
    uint32_t    v_channel_u32;

    switch (i_CameraID_t)
    {
    case variants::e_CameraFront:
        svsVideoSensor.testPatternEnable_v(3U, i_enable_b);
        break;

    case variants::e_CameraLeft:
        svsVideoSensor.testPatternEnable_v(1U, i_enable_b);
        break;

    case variants::e_CameraRear:
        svsVideoSensor.testPatternEnable_v(2U, i_enable_b);
        break;

    case variants::e_CameraRight:
        svsVideoSensor.testPatternEnable_v(0U, i_enable_b);
        break;

    default:
        log_b(logging::e_LogLvlError, "invalid camera-id: %u", static_cast<uint32_t>(i_CameraID_t));
    }
}

/// @brief  Retrieve individual video buffer descriptor
bool_t TIOVXVideoInput::getVideoInputBuffer_b(variants::Camera_t i_CameraID_t, VideoInputBufferDesc2_t& o_VideoInputBufferDesc_rt)
{
    bool_t      v_result_b;

    switch(i_CameraID_t)
    {
    case variants::e_CameraFront:
        v_result_b = svsVideoSensor.getVideoInputBuffer_b(variants::e_CameraHWFront, o_VideoInputBufferDesc_rt);
        break;

    case variants::e_CameraLeft:
        v_result_b = svsVideoSensor.getVideoInputBuffer_b(variants::e_CameraHWLeft, o_VideoInputBufferDesc_rt);
        break;

    case variants::e_CameraRear:
        v_result_b = svsVideoSensor.getVideoInputBuffer_b(variants::e_CameraHWRear, o_VideoInputBufferDesc_rt);
        break;

    case variants::e_CameraRight:
        v_result_b = svsVideoSensor.getVideoInputBuffer_b(variants::e_CameraHWRight, o_VideoInputBufferDesc_rt);
        break;

    default:
        log_b(logging::e_LogLvlError, "invalid camera-id: %u", static_cast<uint32_t>(i_CameraID_t));
        v_result_b = false;
    }

    return v_result_b;
}

/// @brief  Return sensors failure mask
uint8_t TIOVXVideoInput::getSvsFailureMask_u8()
{
    uint8_t     v_failureMask_u8 = svsVideoSensor.getFailureMask_u8();
    uint8_t     v_outputMask_u8 = 0U;

    if ((v_failureMask_u8 & (1U << variants::e_CameraHWRight)) != 0U)
        v_outputMask_u8 |= 1U << static_cast<int>(variants::e_CameraRight);

    if ((v_failureMask_u8 & (1U << variants::e_CameraHWLeft)) != 0U)
        v_outputMask_u8 |= 1U << static_cast<int>(variants::e_CameraLeft);

    if ((v_failureMask_u8 & (1U << variants::e_CameraHWRear)) != 0U)
        v_outputMask_u8 |= 1U << static_cast<int>(variants::e_CameraRear);

    if ((v_failureMask_u8 & (1U << variants::e_CameraHWFront)) != 0U)
        v_outputMask_u8 |= 1U << static_cast<int>(variants::e_CameraFront);

    return v_outputMask_u8;
}

/// @brief  Power-up cameras (start processing)
void TIOVXVideoInput::powerEnable_v(bool_t i_enable_b)
{
    log_b(logging::e_LogLvlInfo, "start video input: %d", i_enable_b);

    svsVideoSensor.powerEnable_v(i_enable_b);
}

/// @brief  ISP edge enhancement control
void TIOVXVideoInput::eeControl(bool_t i_enable_b)
{
    svsVideoSensor.getUserIspParameters()->ee_enabled = i_enable_b ? 1 : 0;
    svsVideoSensor.getUserIspParameters()->invalidate_ee = 1;
    svsVideoSensor.sendUserIspParameters();
}

/// @brief  Get index of most recent SVS-camera buffer
bool_t TIOVXVideoInput::getSvsVideoBuffer_b(uint32_t& o_bufferIdx_u32)
{
    return svsVideoSensor.getVideoBuffer_b(o_bufferIdx_u32);
}

/// @brief  Get index of most recent camera buffer
bool_t TIOVXVideoInput::waitSvsVideoBuffer_b(uint32_t& o_bufferIdx_u32, const uint32_t& i_lastbufferIdx_u32, uint64_t* o_timestamp_pu64)
{
    return svsVideoSensor.waitVideoBuffer_b(o_bufferIdx_u32, i_lastbufferIdx_u32, o_timestamp_pu64);
}

/// @brief  Release video buffers to a graph up to given index
bool_t TIOVXVideoInput::releaseSvsVideoBuffer_b(uint32_t i_bufferIdx_u32)
{
    return svsVideoSensor.releaseVideoBuffer_b(i_bufferIdx_u32);
}

/// @brief  Video input interface accessor
TIOVXVideoSensor& TIOVXVideoInput::getsvsVideoSensor_ro()
{
  return svsVideoSensor;
}

bool_t TIOVXVideoInput::submitInputBufferVerificationRequest_b(uint32_t bufferIdx_u32, const uint16_t ctlval_au16[], const bool_t ctlvalValid_ab[])
{
    return svsVideoSensor.submitInputBufferVerificationRequest_b(bufferIdx_u32, ctlval_au16, ctlvalValid_ab);
}

Svs_CamEepromDataArray_t   TIOVXVideoSensor::getSvsEepromData()
{
  Svs_CamEepromDataArray_t 	svs_CamEepromDataArray_t;

#if 1   // read eeprom retry
    for (uint32_t i_cameraId_t = 0; i_cameraId_t < camerasNumber_u8; i_cameraId_t++)
    {
        readEepromData_v(static_cast<variants::Camera_t>(i_cameraId_t));
    }
#endif

  svs_CamEepromDataArray_t.CameraEepromData[0] = SVSEepData_t[0];
  svs_CamEepromDataArray_t.CameraEepromData[1] = SVSEepData_t[1];
  svs_CamEepromDataArray_t.CameraEepromData[2] = SVSEepData_t[2];
  svs_CamEepromDataArray_t.CameraEepromData[3] = SVSEepData_t[3];

  return svs_CamEepromDataArray_t ;
}

bool_t TIOVXVideoSensor::getSvsEepromCrcErrorStatus(variants::Camera_t i_CameraID_t)
{
	return crcError_ab[i_CameraID_t];
}

} // namespace bsp
