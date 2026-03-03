/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           vx_vpac_cuc_rc_target.c
 *  @brief          ISP framework kernel implementation
 *
 *
 *  @version        3.31
 *  @author         Ulyanov Mikhail
 *  @date           01.10.2021
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "tivx_hwa_cuc_rc_priv.h"
#include "tivx_kernel_vpac_cuc_rc.h"
#include "utils/perf_stats/include/app_perf_stats.h"
#include <common_sensor_api.h>
#include <vx_vpac_cuc_common.h>

#include <inttypes.h>
#include <stdlib.h>

#include "processing.h"

#include <utils/udma/include/app_udma.h>

/* #undef below to see performance without VISS context save/restore */
#define VHWA_VISS_CTX_SAVE_RESTORE_ENABLE

/* #undef below to see performance using CPU for VISS context save/restore */
#define VHWA_VISS_CTX_SAVE_RESTORE_USE_DMA

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define MAGNA_TIME_PROFILING 0

#if MAGNA_TIME_PROFILING
   #include <ti/osal/TimerP.h>
    #include <ti/osal/osal.h>
    #include <utils/console_io/include/app_log.h>
    #define iterations 1000llu
    #define scheduling_ideal 8333llu
    #define scheduling_tolerence 4000llu /*1 ms*/
    static uint64_t start_time, end_time;
    static uint64_t prev_start_time;
    static uint64_t ISP_exec_counter = 0;
    static uint64_t ISP_scheduling_time[iterations];
    static uint64_t ISP_execution_time[iterations];
    static bool start_logs = FALSE;
#endif


/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

static vx_status VX_CALLBACK tivxVpacCucRcCreate(
    tivx_target_kernel_instance kernel,
    tivx_obj_desc_t *obj_desc[],
    uint16_t num_params, void *priv_arg);
static vx_status VX_CALLBACK tivxVpacCucRcDelete(
    tivx_target_kernel_instance kernel,
    tivx_obj_desc_t *obj_desc[],
    uint16_t num_params, void *priv_arg);
static vx_status VX_CALLBACK tivxVpacCucRcProcess(
    tivx_target_kernel_instance kernel,
    tivx_obj_desc_t *obj_desc[],
    uint16_t num_params, void *priv_arg);
static vx_status VX_CALLBACK tivxVpacCucRcControl(
    tivx_target_kernel_instance kernel,
    uint32_t node_cmd_id,
    tivx_obj_desc_t *obj_desc[],
    uint16_t num_params,
    void *priv_arg);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

static tivx_target_kernel vx_vpac_cuc_rc_target_kernel = NULL;
extern tivxVpacCucIspObj g_cucIspObjs[VHWA_M2M_VISS_MAX_HANDLES];
static outputFrameRate_callback set_fps_callback = cuc_set_fps_via_iss;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void tivxAddTargetKernelVpacCucRc(void)
{
    vx_status status = (vx_status)VX_FAILURE;
    char target_name[TIVX_TARGET_MAX_NAME];
    vx_enum self_cpu;

    self_cpu = tivxGetSelfCpuId();

    if (self_cpu == (vx_enum)TIVX_CPU_ID_IPU1_0 ||
        self_cpu == (vx_enum)TIVX_CPU_ID_IPU1_1)
    {
        strncpy(target_name, TIVX_TARGET_VPAC_CUC_RC, TIVX_TARGET_MAX_NAME);
        status = (vx_status)VX_SUCCESS;
    }
    else
    {
        VX_PRINT(VX_ZONE_ERROR, "Invalid CPU ID\n");
        status = (vx_status)VX_FAILURE;
    }

    if (status == (vx_status)VX_SUCCESS)
    {
        vx_vpac_cuc_rc_target_kernel = tivxAddTargetKernelByName(
            TIVX_KERNEL_VPAC_CUC_RC_NAME,
            target_name,
            tivxVpacCucRcProcess,
            tivxVpacCucRcCreate,
            tivxVpacCucRcDelete,
            tivxVpacCucRcControl,
            NULL);
    }

    if (NULL != vx_vpac_cuc_rc_target_kernel)
    {
        /* tweak_init("rpmsg", "rpmsg://17", "r5f"); */
    }
    else
    {
        VX_PRINT(VX_ZONE_ERROR, "Failed to add target kernel by name %s\n",
                 TIVX_TARGET_VPAC_CUC_RC);
    }
}

void tivxRemoveTargetKernelVpacCucRc(void)
{
    vx_status status = (vx_status)VX_SUCCESS;

    status = tivxRemoveTargetKernel(vx_vpac_cuc_rc_target_kernel);
    if (status == (vx_status)VX_SUCCESS)
    {
        vx_vpac_cuc_rc_target_kernel = NULL;
    }
    else
    {
        VX_PRINT(VX_ZONE_ERROR, "Failed to Remove Viss TargetKernel\n");
    }
}

/* ========================================================================== */
/*                              OPENVX Callbacks                              */
/* ========================================================================== */

static vx_status VX_CALLBACK tivxVpacCucRcCreate(
    tivx_target_kernel_instance kernel,
    tivx_obj_desc_t *obj_desc[],
    uint16_t num_params, void *priv_arg)
{
    vx_status status = (vx_status)VX_SUCCESS;
    tivxVpacCucIspObj *ispObj = NULL;
    tivx_vpac_cuc_isp_params_t *ispPrms = NULL;

    tivx_obj_desc_user_data_object_t *config_desc =
        (tivx_obj_desc_user_data_object_t *)obj_desc[TIVX_KERNEL_VPAC_CUC_RC_CFG_IDX];

    status = tivxVpacCucMapUserDesc((void **)&ispPrms, config_desc,
                                   sizeof(tivx_vpac_cuc_isp_params_t),
                                   (vx_enum)VX_READ_ONLY);
    if ((vx_status)VX_SUCCESS != status)
    {
        VX_PRINT(VX_ZONE_ERROR, "Failed to Map Parameters Descriptor\n");
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        ispObj = &g_cucIspObjs[ispPrms->context_id];
        status = tivxSetTargetKernelInstanceContext(kernel, ispObj,
                                                    sizeof(tivxVpacCucIspObj));
    }

    if (NULL != ispPrms)
    {
        tivxVpacCucUnmapUserDesc((void **)&ispPrms, config_desc,
                                (vx_enum)VX_READ_ONLY);
    }

    ispObj->frame_counter = 0;
    ispObj->need_reinit = 0;


    /* Initialize buffer pointer to NULL */
    ispObj->configurationBuffer.bufferPtr = NULL;

    return (status);
}

static void tivxVpacVissDeleteConfigBuffer(tivxVpacCucIspObj *vissObj)
{
    if (NULL != vissObj->configurationBuffer.bufferPtr)
    {
        tivxMemFree((void*) vissObj->configurationBuffer.bufferPtr,
                vissObj->configurationBuffer.length,
                (vx_enum) TIVX_MEM_EXTERNAL);

        vissObj->configurationBuffer.bufferPtr = NULL;
    }
}

static vx_status VX_CALLBACK tivxVpacCucRcDelete(
    tivx_target_kernel_instance kernel,
    tivx_obj_desc_t *obj_desc[],
    uint16_t num_params, void *priv_arg)
{
    vx_status status = (vx_status)VX_SUCCESS;
    uint32_t size;
    tivxVpacCucIspObj *ispObj = NULL;

    status = tivxGetTargetKernelInstanceContext(kernel, (void **)&ispObj, &size);

    if ((vx_status)VX_SUCCESS != status)
    {
        VX_PRINT(VX_ZONE_ERROR, "Incorrect kernel context or it's size\n");
    }
    else if (NULL == ispObj || sizeof(tivxVpacCucIspObj) != size)
    {
        VX_PRINT(VX_ZONE_ERROR, "Incorrect Object Size\n");
        status = (vx_status)VX_FAILURE;
    }
    else
    {
        ispObj->frame_counter = 0;
        ispObj->need_reinit = 0;
    }

    if (true == ispObj->configurationBuffer.configThroughUdmaFlag)
    {
        tivxVpacVissDeleteConfigBuffer(ispObj);
    }

    return (status);
}

static vx_status VX_CALLBACK tivxVpacCucRcControl(
    tivx_target_kernel_instance kernel,
    uint32_t node_cmd_id,
    tivx_obj_desc_t *obj_desc[],
    uint16_t num_params,
    void *priv_arg
)
{
    vx_status status = VX_SUCCESS;

    tivxVpacCucIspObj *ispObj = NULL;
    tivx_vpac_cuc_isp_params_t *ispPrms = NULL;
    uint32_t channel_id = 0;
    uint32_t size;

    if (NULL == obj_desc[0])
    {
        VX_PRINT(VX_ZONE_ERROR, "Input Image handle is NULL!\n");
        status = VX_FAILURE;
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        status = tivxGetTargetKernelInstanceContext(kernel, (void **)&ispObj, &size);
        if ((vx_status)VX_SUCCESS != status)
        {
            VX_PRINT(VX_ZONE_ERROR, "Incorrect kernel instance context\n");
        }
        else if (NULL == ispObj || sizeof(tivxVpacCucIspObj) != size)
        {
            VX_PRINT(VX_ZONE_ERROR, "Incorrect Object Size\n");
            status = (vx_status)VX_FAILURE;
        }
        else if (NULL == ispObj->handle)
        {
            VX_PRINT(VX_ZONE_ERROR, "VISS kernel is not initialized\n");
            status = (vx_status)VX_FAILURE;
        }
        else
        {
            ispPrms = &ispObj->ispPrms;
            channel_id = ispPrms->channel_id;
        }
    }

    isp_user_parameters_t user_params;


    if(status==VX_SUCCESS)
    {
        switch (node_cmd_id)
        {
            case TIVX_KERNEL_VPAC_CUC_RC_USER_CMD:
            {
                {
                    tivx_obj_desc_user_data_object_t* usr_data_obj = (tivx_obj_desc_user_data_object_t*)(obj_desc[0U]);
                    if (NULL != usr_data_obj)
                    {
                        void  *target_ptr = tivxMemShared2TargetPtr(&usr_data_obj->mem_ptr);

                        tivxMemBufferMap(target_ptr, usr_data_obj->mem_size,
                            (vx_enum)VX_MEMORY_TYPE_HOST, (vx_enum)VX_READ_ONLY);

                        memcpy(&user_params, target_ptr, sizeof(isp_user_parameters_t));

                        tivxMemBufferUnmap(target_ptr, usr_data_obj->mem_size,
                            (vx_enum)VX_MEMORY_TYPE_HOST, (vx_enum)VX_READ_ONLY);
                    }
                    else
                    {
                        VX_PRINT(VX_ZONE_ERROR,
                            "tivxKernelWriteUserDataObjectCmd: Data Object is NULL\n");
                        status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
                    }
                }
                VX_PRINT(VX_ZONE_INFO, "USER EE mode[%d] = %d\n", channel_id, user_params.ee_enabled);
                setEE(channel_id, user_params.ee_enabled);
                break;
            }
            default:
            {
                VX_PRINT(VX_ZONE_ERROR, "tivxVpacCucRcControl: Invalid Command Id\n");
                status = (vx_status)VX_FAILURE;
                break;
            }
        }
    }

    return (status);
}

static vx_status tivxVpacCucRcSetConfigBuffer(tivxVpacCucIspObj *vissObj)
{
    vx_status status =      (vx_status) VX_SUCCESS;
    int32_t fvid2_status =  FVID2_SOK;
    /* Initialize length to zero */
    vissObj->configurationBuffer.length = 0;
    /* Initialize configThroughUDMA to false */
    vissObj->configurationBuffer.configThroughUdmaFlag = false;

    /* Get configuration buffer information */
    fvid2_status = Fvid2_control(vissObj->handle,
    IOCTL_VHWA_M2M_VISS_GET_BUFF_INFO, (void*) &vissObj->configurationBuffer,
            NULL);

    if (FVID2_SOK != fvid2_status)
    {
        VX_PRINT(VX_ZONE_ERROR, "Failed to Get config buff info from driver\n");
    }

    if (FVID2_SOK == fvid2_status)
    {
        /* configThroughUdmaFlag is true, allocate config buffer */
        if (true == vissObj->configurationBuffer.configThroughUdmaFlag)
        {
            tivxVpacVissDeleteConfigBuffer(vissObj);
            /* allocate buffer for the length requested */
            vissObj->configurationBuffer.bufferPtr = (uint32_t*) tivxMemAlloc(
                    vissObj->configurationBuffer.length,
                    (vx_enum) TIVX_MEM_EXTERNAL);
            if (NULL == vissObj->configurationBuffer.bufferPtr)
            {
                VX_PRINT(VX_ZONE_ERROR, "failed to allocate %d bytes !!!\n",
                        vissObj->configurationBuffer.length);
                fvid2_status = FVID2_EALLOC;
            }
            else
            {
                /* Set configuration buffer information */
                fvid2_status = Fvid2_control(vissObj->handle,
                IOCTL_VHWA_M2M_VISS_SET_BUFF_INFO,
                        (void*) &vissObj->configurationBuffer, NULL);

                if (FVID2_SOK != fvid2_status)
                {
                    VX_PRINT(VX_ZONE_ERROR,
                            "Failed to set config buff info into driver\n");
                }
            }
        }
    }
    /* Convert FVID2 status to OpenVX Status */
    if (FVID2_SOK != fvid2_status)
    {
        status = (vx_status) VX_ERROR_INVALID_PARAMETERS;
    }
    else
    {
        status = (vx_status) VX_SUCCESS;
    }

    return (status);
}

static vx_status VX_CALLBACK tivxVpacCucRcProcess(
    tivx_target_kernel_instance kernel,
    tivx_obj_desc_t *obj_desc[],
    uint16_t num_params, void *priv_arg)
{
    #if MAGNA_TIME_PROFILING  
        prev_start_time = start_time;
        start_time = TimerP_getTimeInUsecs();

        if(iterations > ISP_exec_counter)
            ISP_scheduling_time[ISP_exec_counter] = start_time - prev_start_time;
        else
            appLogPrintf("\n Core Crash Avoided sch!!!! \n");
    #endif

    vx_status status = (vx_status)VX_SUCCESS;
    uint32_t size;
    tivxVpacCucIspObj *ispObj = NULL;
    tivx_vpac_cuc_isp_params_t *ispPrms = NULL;
    uint32_t channel_id;
    Vhwa_M2mVissParams *vissDrvPrms = NULL;
    int32_t fvid2_status = FVID2_SOK;

    tivx_obj_desc_raw_image_t *raw_img_desc =
        (tivx_obj_desc_raw_image_t *)obj_desc[TIVX_KERNEL_VPAC_CUC_RC_RAW_IDX];

    if ((vx_status)VX_SUCCESS == status)
    {
        status = tivxGetTargetKernelInstanceContext(kernel, (void **)&ispObj, &size);
        if ((vx_status)VX_SUCCESS != status)
        {
            VX_PRINT(VX_ZONE_ERROR, "Incorrect kernel instance context\n");
        }
        else if (NULL == ispObj || sizeof(tivxVpacCucIspObj) != size)
        {
            VX_PRINT(VX_ZONE_ERROR, "Incorrect Object Size\n");
            status = (vx_status)VX_FAILURE;
        }
        else if (NULL == ispObj->handle)
        {
            VX_PRINT(VX_ZONE_ERROR, "VISS kernel is not initialized\n");
            status = (vx_status)VX_FAILURE;
        }
        else
        {
            ispPrms = &ispObj->ispPrms;
            channel_id = ispPrms->channel_id;
        }
    }

    if ((vx_status)VX_SUCCESS == status &&
        tivxFlagIsBitSet(obj_desc[TIVX_KERNEL_VPAC_CUC_RC_RAW_IDX]->flags,
                         TIVX_REF_FLAG_IS_INVALID) == 1U &&
                          0 != ispObj->frame_counter) /*.. let it initialize anyway */
    {
        //VX_PRINT(VX_ZONE_WARNING, "Invalid flag in input raw image; skip processing\n");

        tivxEventWait(ispObj->eventVissCmpl, TIVX_EVENT_TIMEOUT_WAIT_FOREVER);
        ispObj->frame_counter++;
        ispObj->need_reinit = 1;
        tivxEventPost(ispObj->eventRcCmpl);

        /*.. TODO: process as invalid frame by isp-rc */
        return status;
    }

    if ((vx_status)VX_SUCCESS == status && (0 == ispObj->frame_counter || 1 == ispObj->need_reinit))
    {
        /*.. Initialize ISP-RC on the first frame */
        vissDrvPrms = &ispObj->vissPrms;
        vx_status status;

        status = rc_init(ispObj, raw_img_desc->params.width,
                         raw_img_desc->params.height);

        /* before writing configuration set application buffer */
        if ((vx_status) VX_SUCCESS == status)
        {
            status = tivxVpacCucRcSetConfigBuffer(ispObj);
            if (VX_SUCCESS != status)
            {
                VX_PRINT(VX_ZONE_ERROR, "Failed to set ConfigBuf in driver\n");
            }
        }

        if ((vx_status)VX_SUCCESS == status)
        {
            /*.. If current config does not use some blocks, bypass them */
            vissDrvPrms->enableDpc = ispObj->vissCfg.dpcLutCfg.enable ||
                                     ispObj->vissCfg.dpcOtfCfg.enable;
            vissDrvPrms->enableGlbce = (uint32_t)TRUE;
            vissDrvPrms->enableNsf4 = (uint32_t)TRUE;
            /* vissDrvPrms->enableDmaQuirk = (bool)ispPrms->enable_dma_quirk; */
            vissDrvPrms->edgeEnhancerMode = VHWA_M2M_VISS_EE_ON_LUMA8;

            fvid2_status = Fvid2_control(ispObj->handle,
                                         IOCTL_VHWA_M2M_VISS_SET_PARAMS,
                                         (void *)vissDrvPrms, NULL);
            if (FVID2_SOK != fvid2_status)
            {
                VX_PRINT(VX_ZONE_ERROR, "Failed to set Params in driver\n");
                status = (vx_status)VX_FAILURE;
            }
        }
    }

    if ((vx_status)VX_SUCCESS == status && 0 < ispObj->frame_counter)
    {
        /*.. Normal frame processing */
        tivxEventWait(ispObj->eventVissCmpl, TIVX_EVENT_TIMEOUT_WAIT_FOREVER);

        struct ar014x_sensor_data *sensorData = &ispObj->sensorData;
        if ((vx_status)VX_SUCCESS == status)
        {
            sensorData->num_embedded_data_lines = raw_img_desc->params.meta_height_before;
            if (sensorData->num_embedded_data_lines)
            {
                sensorData->embedded_data_size = sensorData->num_embedded_data_lines *
                    (uint32_t)raw_img_desc->imagepatch_addr[0U].stride_y;
                sensorData->embedded_data_width = raw_img_desc->params.width;

                if (sensorData->embedded_data_size > 0)
                {
                    sensorData->embeddedData = (uint16_t *)tivxMemShared2TargetPtr(raw_img_desc->meta_before_ptr);
                    tivxMemBufferMap((void *)sensorData->embeddedData,
                                     sensorData->embedded_data_size,
                                     (vx_enum)VX_MEMORY_TYPE_HOST,
                                     (vx_enum)VX_READ_ONLY);
                }
                else
                {
                    VX_PRINT(VX_ZONE_ERROR, "Misconfiguration\n");
                    status = (vx_status)VX_FAILURE;
                }
            }
            else
            {
                sensorData->embeddedData = NULL;
            }
        }
        if ((vx_status)VX_SUCCESS == status)
        {
            sensorData->num_embedded_stats_lines = raw_img_desc->params.meta_height_after;
            if (sensorData->num_embedded_stats_lines)
            {
                sensorData->embedded_stats_size = sensorData->num_embedded_stats_lines *
                    (uint32_t)raw_img_desc->imagepatch_addr[0U].stride_y;
                sensorData->embedded_stats_width = raw_img_desc->params.width;

                if (sensorData->embedded_stats_size > 0)
                {
                    sensorData->embeddedStats = (uint8_t *)tivxMemShared2TargetPtr(raw_img_desc->meta_after_ptr);
                    tivxMemBufferMap((void *)sensorData->embeddedStats,
                                     sensorData->embedded_stats_size,
                                     (vx_enum)VX_MEMORY_TYPE_HOST,
                                     (vx_enum)VX_READ_ONLY);
                }
                else
                {
                    VX_PRINT(VX_ZONE_ERROR, "Misconfiguration\n");
                    status = (vx_status)VX_FAILURE;
                }
            }
            else
            {
                sensorData->embeddedStats = NULL;
            }
        }

        if ((vx_status)VX_SUCCESS == status && ispObj->tpg != ispPrms->test_pattern)
        {
            status = setManufacturingTestMode(channel_id,
                          (v3xISP_ManufacturingTestType_t)ispPrms->test_pattern);

            if (VX_SUCCESS != status)
            {
                VX_PRINT(VX_ZONE_ERROR, "Failed to set tp (ctx_id:%d): %d\n",
                         channel_id, status);
            }
            else
            {
                ispObj->tpg = (v3xISP_ManufacturingTestType_t)ispPrms->test_pattern;
            }
        }

        if ((vx_status)VX_SUCCESS == status)
        {
            CacheP_Inv(ispObj->h3a_stats_data, ispObj->h3a_output_size);
            status = rc_process(ispObj);

            if (VX_SUCCESS != status)
            {
                VX_PRINT(VX_ZONE_ERROR, "Failed to run rc_process(): %d\n", status);
            }
        }

        if (sensorData->embeddedData != NULL)
        {
            tivxMemBufferUnmap((void *)sensorData->embeddedData,
                               sensorData->embedded_data_size,
                               (vx_enum)VX_MEMORY_TYPE_HOST, (vx_enum)VX_READ_ONLY);
        }

        if (sensorData->embeddedStats != NULL)
        {
            tivxMemBufferUnmap((void *)sensorData->embeddedStats,
                               sensorData->embedded_stats_size,
                               (vx_enum)VX_MEMORY_TYPE_HOST, (vx_enum)VX_READ_ONLY);
        }
    }

    if (((vx_status)VX_SUCCESS == status) && (0u != ispObj->vissCfg.usageFlag))
    {
        ispObj->vissCfg.usageFlag = 0;
        status = tivxVpacCucVissSetConfigInDrv(ispObj);

        if ((vx_status)VX_SUCCESS != status)
        {
            VX_PRINT(VX_ZONE_ERROR, "Failed to Set Config in Driver\n");
        }
    }

    tivxEventPost(ispObj->eventRcCmpl);

    if ((vx_status)VX_SUCCESS == status)
    {
        rc_sensor_write(ispObj);
    }

    ispObj->frame_counter++;
    ispObj->need_reinit = 0;

    #if MAGNA_TIME_PROFILING
            end_time = TimerP_getTimeInUsecs();
            
            if(iterations > ISP_exec_counter)
                ISP_execution_time[ISP_exec_counter] = end_time - start_time;
            else
                appLogPrintf("\n Core Crash Avoided exe!!!! \n");

            ISP_exec_counter++;
            if(iterations == ISP_exec_counter)
            {
                // appLogPrintf("nth iteration timestamp = %llu", start_time);
                ISP_exec_counter = 0;
                uint64_t sum_exe = 0, sum_sch = 0;
                uint64_t min_exe_index, max_exe_index, min_sch_index, max_sch_index;
                uint64_t min_time_exe = -1, max_time_exe = 0;
                uint64_t min_time_sch = -1, max_time_sch = 0;
                uint64_t times_delay_sch = 0, times_prior_sch = 0;

                for(uint64_t index = 0; index<iterations; index++)
                {
                    sum_exe += ISP_execution_time[index];
                    sum_sch += ISP_scheduling_time[index];

                    if(max_time_exe < ISP_execution_time[index])
                    {
                        max_time_exe = ISP_execution_time[index];
                        max_exe_index = index;
                    }

                    if(min_time_exe > ISP_execution_time[index])
                    {
                        min_time_exe = ISP_execution_time[index];
                        min_exe_index = index;
                    }

                    if(max_time_sch < ISP_scheduling_time[index])
                    {
                        max_time_sch = ISP_scheduling_time[index];
                        max_sch_index = index;
                    }

                    if(min_time_sch > ISP_scheduling_time[index])
                    {
                        min_time_sch = ISP_scheduling_time[index];
                        min_sch_index = index;
                    }

                    if(scheduling_ideal > ISP_scheduling_time[index])
                    {
                        if((scheduling_ideal - ISP_scheduling_time[index]) > scheduling_tolerence)
                            times_prior_sch++;
                    }
                    else
                    {
                        if((ISP_scheduling_time[index] - scheduling_ideal) > scheduling_tolerence)
                            times_delay_sch++;  
                    }
                }

                if((50000000llu < TimerP_getTimeInUsecs()) && (FALSE == start_logs))
                {
                    start_logs = TRUE;
                    appLogPrintf("ISP: Iterations, Tolerence, Times_Prior_Scheduled, Times_Delayed_Scheduled, Avg_Exe_Time, Max_Exe_Time, Max_Exe_Index, Min_Exe_Time, Min_Exe_Index, Avg_Sch_Time, Max_Sch_Time, Max_Sch_Index, Min_Sch_Time, Min_Sch_Index\n");
                }

                if(start_logs)
                {
                    appLogPrintf("ISP: %llu, %llu, %llu, %llu, %llu, %llu, %llu, %llu, %llu, %llu, %llu, %llu, %llu, %llu\n"
                    ,iterations
                    ,scheduling_tolerence
                    ,times_prior_sch
                    ,times_delay_sch
                    ,(sum_exe/iterations)
                    ,max_time_exe
                    ,max_exe_index
                    ,min_time_exe
                    ,min_exe_index
                    ,(sum_sch/iterations)
                    ,max_time_sch
                    ,max_sch_index
                    ,min_time_sch
                    ,min_sch_index
                    );
                }
            }
    #endif
    return (status);
}
