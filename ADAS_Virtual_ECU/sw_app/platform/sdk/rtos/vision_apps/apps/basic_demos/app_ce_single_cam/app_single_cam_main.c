/*
 *
 * Copyright (c) 2018 Texas Instruments Incorporated
 *
 * All rights reserved not granted herein.
 *
 * Limited License.
 *
 * Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
 * license under copyrights and patents it now or hereafter owns or controls to make,
 * have made, use, import, offer to sell and sell ("Utilize") this software subject to the
 * terms herein.  With respect to the foregoing patent license, such license is granted
 * solely to the extent that any such patent is necessary to Utilize the software alone.
 * The patent license shall not apply to any combinations which include this software,
 * other than combinations with devices manufactured by or for TI ("TI Devices").
 * No hardware patent is licensed hereunder.
 *
 * Redistributions must preserve existing copyright notices and reproduce this license
 * (including the above copyright notice and the disclaimer and (if applicable) source
 * code license limitations below) in the documentation and/or other materials provided
 * with the distribution
 *
 * Redistribution and use in binary form, without modification, are permitted provided
 * that the following conditions are met:
 *
 * *       No reverse engineering, decompilation, or disassembly of this software is
 * permitted with respect to any software provided in binary form.
 *
 * *       any redistribution and use are licensed by TI for use only with TI Devices.
 *
 * *       Nothing shall obligate TI to provide you with source code for the software
 * licensed and provided to you in object code.
 *
 * If software source code is provided to you, modification and redistribution of the
 * source code are permitted provided that the following conditions are met:
 *
 * *       any redistribution and use of the source code, including any resulting derivative
 * works, are licensed by TI for use only with TI Devices.
 *
 * *       any redistribution and use of any object code compiled from the source code
 * and any resulting derivative works, are licensed by TI for use only with TI Devices.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of its suppliers
 *
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * DISCLAIMER.
 *
 * THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "app_single_cam_main.h"
#include <utils/iss/include/app_iss.h>

/* #ifdef A72 */
/* #if defined(LINUX) */
/*ITT server is supported only in target mode and only on Linux*/
/* #include <itt_server.h> */
/* #endif */
/* #endif */

#include <png.h>

static char availableSensorNames[ISS_SENSORS_MAX_SUPPORTED_SENSOR][ISS_SENSORS_MAX_NAME];
static vx_uint8 num_sensors_found;
static IssSensor_CreateParams sensorParams;

/* 0..3 for capture slot A
 * 4..7 for capture slot B */
#define CAPT_CAMERA_INDEX           (0)

#define CAPT_INST_ID                (CAPT_CAMERA_INDEX / 4)
#define CAPT_CHANNELS_MASK          (1 << CAPT_CAMERA_INDEX)

#define APP_BUFFER_Q_DEPTH   (4)
#define APP_PIPELINE_DEPTH   (7)

enum supported_cameras {
    AR0233_DEFAULT,

    NUM_SUPPORTED_CAMS
};

rc_settings rc_prms[NUM_SUPPORTED_CAMS] =
{
    {
        .context_name = "ar0233",
        .configs = {
        },
    }
};

char *app_get_test_file_path()
{
    char *tivxPlatformGetEnv(char *env_var);

    #if defined(SYSBIOS)
    return tivxPlatformGetEnv("VX_TEST_DATA_PATH");
    #else
    return getenv("VX_TEST_DATA_PATH");
    #endif
}


/*
 * Utility API used to add a graph parameter from a node, node parameter index
 */
void add_graph_parameter_by_node_index(vx_graph graph, vx_node node, vx_uint32 node_parameter_index)
{
    vx_parameter parameter = vxGetParameterByIndex(node, node_parameter_index);

    vxAddParameterToGraph(graph, parameter);
    vxReleaseParameter(&parameter);
}

vx_status app_init(AppObj *obj)
{
    vx_status status = VX_FAILURE;
    char* sensor_list[ISS_SENSORS_MAX_SUPPORTED_SENSOR];
    vx_uint8 count = 0;
    char ch = 0xFF;
    vx_uint8 selectedSensor = 0xFF;

/* #ifdef A72 */
/* #if defined(LINUX) */
/* #<{(|ITT server is supported only in target mode and only on Linux|)}># */
/*     status = itt_server_init((void*)obj, (void*)save_debug_images); */
/*     if(status != 0) */
/*     { */
/*         printf("Warning : Failed to initialize ITT server. Live tuning will not work \n"); */
/*     } */
/* #endif */
/* #endif */

    obj->stop_task = 0;
    obj->stop_task_done = 0;

    obj->context = vxCreateContext();
    APP_ASSERT_VALID_REF(obj->context);

    tivxHwaLoadKernels(obj->context);
    /* tivxImagingLoadKernels(obj->context); */
    /* APP_PRINTF("tivxImagingLoadKernels done\n"); */

    memset(availableSensorNames, 0, ISS_SENSORS_MAX_SUPPORTED_SENSOR*ISS_SENSORS_MAX_NAME);
    for(count=0;count<ISS_SENSORS_MAX_SUPPORTED_SENSOR;count++)
    {
        sensor_list[count] = availableSensorNames[count];
    }
    status = appEnumerateImageSensor(sensor_list, &num_sensors_found);
    if(VX_SUCCESS != status)
    {
        printf("appCreateImageSensor returned %d\n", status);
        return status;
    }

       if(obj->is_interactive)
       {
        while(selectedSensor > (num_sensors_found-1))
        {
            printf("%d sensor(s) found \n", num_sensors_found);
            printf("Supported sensor list: \n");
            for(count=0;count<num_sensors_found;count++)
            {
               printf("%c : %s \n", count+'a', sensor_list[count]);
            }

            printf("Select a sensor \n");
            ch = getchar();
            printf("\n");
            selectedSensor = ch - 'a';
            if(selectedSensor > (num_sensors_found-1))
            {
                printf("Invalid selection %c. Try again \n", ch);
            }
        }
       }
    else
    {
        selectedSensor = obj->sensor_sel;
        if(selectedSensor > (num_sensors_found-1))
        {
            printf("Invalid sensor selection %d \n", selectedSensor);
            return VX_FAILURE;
        }
    }

    obj->sensor_name = sensor_list[selectedSensor];
    printf("Sensor selected : %s\n", obj->sensor_name);

#if 0
    /* Display initialization */
    memset(&obj->display_params, 0, sizeof(tivx_display_params_t));
    obj->display_params.opMode = TIVX_KERNEL_DISPLAY_ZERO_BUFFER_COPY_MODE;
    obj->display_params.pipeId = 0;
    obj->display_params.outHeight = 1080;
    obj->display_params.outWidth = 1920;
    obj->display_params.posX = 0;
    obj->display_params.posY = 0;

    obj->scaler_enable = vx_false_e;
#endif

    appPerfPointSetName(&obj->total_perf , "TOTAL");

    return status;
}

vx_status app_deinit(AppObj *obj)
{
    vx_status status = VX_FAILURE;
    tivxHwaUnLoadKernels(obj->context);
    APP_PRINTF("tivxHwaUnLoadKernels done\n");

    /* tivxImagingUnLoadKernels(obj->context); */
    /* APP_PRINTF("tivxImagingUnLoadKernels done\n"); */

    status = vxReleaseContext(&obj->context);
    if(VX_SUCCESS == status)
    {
        APP_PRINTF("vxReleaseContext done\n");
    }
    else
    {
        printf("Error: vxReleaseContext returned 0x%x \n", status);
    }
    return status;
}

/*
 * Graph,
 *           viss_config
 *               |
 *               v
 * input_img -> VISS -----> output_img
 *
 */

vx_status app_create_graph(AppObj *obj)
{
    vx_status status = VX_SUCCESS;
    int32_t sensor_init_status = -1;
    obj->configuration = NULL;
    obj->raw = NULL;
    obj->y12 = NULL;
    obj->uv12_c1 = NULL;
    obj->y8_r8_c2 = NULL;
    obj->uv8_g8_c3 = NULL;
    obj->s8_b8_c4 = NULL;
    unsigned int image_width = obj->width_in;
    unsigned int image_height = obj->height_in;

    tivx_raw_image raw_image = 0;
    vx_user_data_object capture_config;
    vx_uint8 num_capture_frames = 1;
    tivx_capture_params_t local_capture_config;
    uint32_t buf_id, loopCnt;//, loop_id, num_buf, loopCnt, frameIdx;
    const vx_char capture_user_data_object_name[] = "tivx_capture_params_t";
    uint32_t sensor_features_enabled = 0;
    uint32_t sensor_features_supported = 0;
    /* vx_image display_image = NULL; */

    vx_graph_parameter_queue_params_t graph_parameters_queue_params_list[1];

    printf("Querying %s \n", obj->sensor_name);
    memset(&sensorParams, 0, sizeof(sensorParams));
    status = appQueryImageSensor(obj->sensor_name, &sensorParams);
    if(VX_SUCCESS != status)
    {
        printf("appQueryImageSensor returned %d\n", status);
        return status;
    }
    /*
    Check for supported sensor features.
    It is upto the application to decide which features should be enabled.
    This demo app enables WDR, DCC and 2A if the sensor supports it.
    */
    sensor_features_supported = sensorParams.sensorInfo.features;

    if(ISS_SENSOR_FEATURE_COMB_COMP_WDR_MODE == (sensor_features_supported & ISS_SENSOR_FEATURE_COMB_COMP_WDR_MODE))
    {
        APP_PRINTF("WDR mode is supported \n");
        sensor_features_enabled |= ISS_SENSOR_FEATURE_COMB_COMP_WDR_MODE;
    }else
    {
        APP_PRINTF("WDR mode is not supported. Defaulting to linear \n");
        sensor_features_enabled |= ISS_SENSOR_FEATURE_LINEAR_MODE;
    }

    if(ISS_SENSOR_FEATURE_MANUAL_EXPOSURE == (sensor_features_supported & ISS_SENSOR_FEATURE_MANUAL_EXPOSURE))
    {
        APP_PRINTF("Expsoure control is supported \n");
        sensor_features_enabled |= ISS_SENSOR_FEATURE_MANUAL_EXPOSURE;
    }

    if(ISS_SENSOR_FEATURE_MANUAL_GAIN == (sensor_features_supported & ISS_SENSOR_FEATURE_MANUAL_GAIN))
    {
        APP_PRINTF("Gain control is supported \n");
        sensor_features_enabled |= ISS_SENSOR_FEATURE_MANUAL_GAIN;
    }

    if(ISS_SENSOR_FEATURE_CFG_UC1 == (sensor_features_supported & ISS_SENSOR_FEATURE_CFG_UC1))
    {
        APP_PRINTF("CMS Usecase is supported \n");
        sensor_features_enabled |= ISS_SENSOR_FEATURE_CFG_UC1;
    }

    if(ISS_SENSOR_FEATURE_DCC_SUPPORTED == (sensor_features_supported & ISS_SENSOR_FEATURE_DCC_SUPPORTED))
    {
        sensor_features_enabled |= ISS_SENSOR_FEATURE_DCC_SUPPORTED;
        APP_PRINTF("Sensor DCC is enabled \n");
    }else
    {
        APP_PRINTF("Sensor DCC is NOT enabled \n");
    }

    APP_PRINTF("Sensor width = %d\n", sensorParams.sensorInfo.raw_params.width);
    APP_PRINTF("Sensor height = %d\n", sensorParams.sensorInfo.raw_params.height);
    APP_PRINTF("Sensor DCC ID = %d\n", sensorParams.dccId);
    APP_PRINTF("Sensor Supported Features = 0x%x\n", sensor_features_supported);
    APP_PRINTF("Sensor Enabled Features = 0x%x\n", sensor_features_enabled);
    sensor_init_status = appInitImageSensor(obj->sensor_name, sensor_features_enabled, CAPT_CHANNELS_MASK);
    if(0 != sensor_init_status)
    {
        printf("Error initializing sensor %s \n", obj->sensor_name);
        return VX_FAILURE;
    }

    image_width     = sensorParams.sensorInfo.raw_params.width;
    image_height    = sensorParams.sensorInfo.raw_params.height;
    obj->width_in   = sensorParams.sensorInfo.raw_params.width;
    obj->height_in  = sensorParams.sensorInfo.raw_params.height;
    obj->cam_dcc_id = sensorParams.dccId;

    APP_PRINTF("Creating graph \n");

    obj->graph = vxCreateGraph(obj->context);
    APP_ASSERT_VALID_REF(obj->graph);

    APP_ASSERT(vx_true_e == tivxIsTargetEnabled(TIVX_TARGET_VPAC_CUC_VISS));
    APP_ASSERT(vx_true_e == tivxIsTargetEnabled(TIVX_TARGET_VPAC_CUC_RC));

    APP_PRINTF("Initializing params for capture node \n");

    /* Setting to num buf of capture node */
    APP_PRINTF("Initializing params for capture node \n");
    raw_image = tivxCreateRawImage(obj->context, &sensorParams.sensorInfo.raw_params);
    obj->num_cap_buf = APP_BUFFER_Q_DEPTH;

    /* allocate Input and Output refs, multiple refs created to allow pipelining of graph */
    for(buf_id = 0; buf_id < obj->num_cap_buf; buf_id++)
    {
        obj->cap_frames[buf_id] = vxCreateObjectArray(obj->context,
                                                      (vx_reference)raw_image,
                                                      num_capture_frames);
    }

    /* Config initialization */
    tivx_capture_params_init(&local_capture_config);
    local_capture_config.numInst                                    = 1U;
    local_capture_config.numCh                                      = 1U;
    /* local_capture_config.mask                                       = CAPT_CHANNELS_MASK; */
    local_capture_config.instId[CAPT_INST_ID]                       = CAPT_INST_ID;
    local_capture_config.instCfg[CAPT_INST_ID].enableCsiv2p0Support = (uint32_t)vx_true_e;
    local_capture_config.instCfg[CAPT_INST_ID].numDataLanes         =
                                                sensorParams.sensorInfo.numDataLanes;
    local_capture_config.instCfg[CAPT_INST_ID].numPixels       = (uint32_t)1U;
    APP_PRINTF("local_capture_config.numDataLanes = %d \n", local_capture_config.instCfg[CAPT_INST_ID].numDataLanes);

    for (loopCnt = 0U ;
         loopCnt < local_capture_config.instCfg[CAPT_INST_ID].numDataLanes ;
         loopCnt++)
    {
        local_capture_config.instCfg[CAPT_INST_ID].dataLanesMap[loopCnt] =
                                sensorParams.sensorInfo.dataLanesMap[loopCnt];
        APP_PRINTF("local_capture_config.dataLanesMap[%d] = %d \n",
                    loopCnt,
                    local_capture_config.instCfg[CAPT_INST_ID].dataLanesMap[loopCnt]);
    }

    capture_config = vxCreateUserDataObject(obj->context, capture_user_data_object_name, sizeof(tivx_capture_params_t), &local_capture_config);
    APP_PRINTF("capture_config = 0x%p \n", capture_config);

    APP_PRINTF("Creating capture node \n");
    obj->capture_node = tivxCaptureNode(obj->graph, capture_config, obj->cap_frames[0]);
    APP_PRINTF("obj->capture_node = 0x%p \n", obj->capture_node);

    obj->capture_stats =
            vxCreateUserDataObject(obj->context, "tivx_capture_statistics_t" ,
            sizeof(tivx_capture_statistics_t), NULL);
    APP_PRINTF("obj->capture_stats = 0x%p \n", obj->capture_stats);

    vxReleaseUserDataObject(&capture_config);

    vxSetNodeTarget(obj->capture_node, VX_TARGET_STRING, TIVX_TARGET_CAPTURE1);

    obj->raw = (tivx_raw_image)vxGetObjectArrayItem(obj->cap_frames[0], 0);
    tivxReleaseRawImage(&raw_image);

    obj->y8_r8_c2 = vxCreateImage(obj->context, image_width, image_height, VX_DF_IMAGE_NV12/*VX_DF_IMAGE_U8*/);
    obj->uv8_g8_c3 = NULL;

    obj->y12 = vxCreateImage(obj->context, image_width, image_height, VX_DF_IMAGE_U16);
    obj->uv12_c1 = vxCreateImage(obj->context, image_width, image_height/2, VX_DF_IMAGE_U16);
    obj->s8_b8_c4 = vxCreateImage(obj->context, image_width, image_height, VX_DF_IMAGE_U8);

    /* VISS Initialize parameters */
    tivx_vpac_cuc_isp_params_init(&obj->viss_params);

    obj->viss_params.sensor_id = obj->cam_dcc_id;
    obj->viss_params.mux_output0 = 0;
    obj->viss_params.mux_output1 = 0;
    obj->viss_params.mux_output2 = 4;
    obj->viss_params.mux_output3 = 0;
    obj->viss_params.mux_output4 = 3;
    obj->viss_params.channel_id = 0;
    obj->viss_params.context_id = 0;

    memcpy(&obj->viss_params.rc_prms, &rc_prms[AR0233_DEFAULT],
           sizeof(obj->viss_params.rc_prms));

    obj->configuration = vxCreateUserDataObject(obj->context,
                                                "tivx_vpac_cuc_isp_params_t",
                                                sizeof(tivx_vpac_cuc_isp_params_t),
                                                &obj->viss_params);

    obj->node_viss = tivxVpacCucVissNode(
                                obj->graph,
                                obj->configuration,
                                obj->raw,
                                NULL, NULL, obj->y8_r8_c2, NULL, NULL);

    vxSetReferenceName((vx_reference)obj->node_viss, "CUC_VISS");
    vxSetNodeTarget(obj->node_viss, VX_TARGET_STRING, TIVX_TARGET_VPAC_CUC_VISS);
    tivxSetNodeParameterNumBufByIndex(obj->node_viss, 4u, APP_BUFFER_Q_DEPTH);

    APP_PRINTF("VISS Set Reference done\n");

    obj->node_rc = tivxVpacCucRcNode(obj->graph, obj->configuration, obj->raw, NULL);

    vxSetReferenceName((vx_reference)obj->node_rc, "CUC_RC");
    vxSetNodeTarget(obj->node_rc, VX_TARGET_STRING, TIVX_TARGET_VPAC_CUC_RC);

    APP_PRINTF("RC Set Reference done\n");

#if 0
    if((image_width != obj->display_params.outWidth) || (image_height != obj->display_params.outHeight))
    {
        vx_uint16 scaler_out_w, scaler_out_h;
        obj->scaler_enable = vx_true_e;
        appIssGetResizeParams(image_width, image_height, obj->display_params.outWidth, obj->display_params.outHeight, &scaler_out_w, &scaler_out_h);
        obj->scaler_out_img = vxCreateImage(obj->context, scaler_out_w, scaler_out_h, VX_DF_IMAGE_NV12);
        obj->scalerNode = tivxVpacMscScaleNode(obj->graph, obj->y8_r8_c2, obj->scaler_out_img, NULL, NULL, NULL, NULL);
        tivxSetNodeParameterNumBufByIndex(obj->scalerNode, 1u, APP_BUFFER_Q_DEPTH);
        vxSetNodeTarget(obj->scalerNode, VX_TARGET_STRING, TIVX_TARGET_VPAC_MSC1);
        obj->display_params.outHeight = scaler_out_h;
        obj->display_params.outWidth = scaler_out_w;
        display_image = obj->scaler_out_img;
    }else
    {
        obj->scaler_enable = vx_false_e;
        display_image = obj->y8_r8_c2;
    }

    if(NULL == display_image)
    {
        printf("Error : Display input is uninitialized \n");
        return VX_FAILURE;
    }
    else
    {
        obj->display_params.posX = (1920U - obj->display_params.outWidth)/2;
        obj->display_params.posY = (1080U - obj->display_params.outHeight)/2;
        obj->display_param_obj = vxCreateUserDataObject(obj->context, "tivx_display_params_t", sizeof(tivx_display_params_t), &obj->display_params);
        obj->displayNode = tivxDisplayNode(obj->graph, obj->display_param_obj, display_image);
    }

    vxSetNodeTarget(obj->displayNode, VX_TARGET_STRING, TIVX_TARGET_DISPLAY1);
    APP_PRINTF("Display Set Target done\n");
#endif

    int graph_parameter_num = 0;

    /* input @ node index 1, becomes graph parameter 0 */
    add_graph_parameter_by_node_index(obj->graph, obj->capture_node, 1);

    /* set graph schedule config such that graph parameter @ index 0 is enqueuable */
    graph_parameters_queue_params_list[graph_parameter_num].graph_parameter_index = 0;
    graph_parameters_queue_params_list[graph_parameter_num].refs_list_size = APP_BUFFER_Q_DEPTH;
    graph_parameters_queue_params_list[graph_parameter_num].refs_list = (vx_reference*)&(obj->cap_frames[0]);
    graph_parameter_num++;

    tivxSetGraphPipelineDepth(obj->graph, APP_PIPELINE_DEPTH);

    /* Schedule mode auto is used, here we dont need to call vxScheduleGraph
     * Graph gets scheduled automatically as refs are enqueued to it
     */
    vxSetGraphScheduleConfig(obj->graph,
            VX_GRAPH_SCHEDULE_MODE_QUEUE_AUTO,
            1,
            graph_parameters_queue_params_list
    );
    APP_PRINTF("vxSetGraphScheduleConfig done\n");

    status = vxVerifyGraph(obj->graph);
    APP_ASSERT(status==VX_SUCCESS);

#if 0
    if(vx_true_e == obj->scaler_enable)
    {
        tivx_vpac_msc_coefficients_t sc_coeffs;
        vx_reference refs[1];

        printf("Scaler is enabled\n");

        tivx_vpac_msc_coefficients_params_init(&sc_coeffs, VX_INTERPOLATION_BILINEAR);

        obj->sc_coeff_obj = vxCreateUserDataObject(obj->context, "tivx_vpac_msc_coefficients_t", sizeof(tivx_vpac_msc_coefficients_t), NULL);

        vxCopyUserDataObject(obj->sc_coeff_obj, 0, sizeof(tivx_vpac_msc_coefficients_t), &sc_coeffs, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST);

        refs[0] = (vx_reference)obj->sc_coeff_obj;
        tivxNodeSendCommand(obj->scalerNode, 0u, TIVX_VPAC_MSC_CMD_SET_COEFF, refs, 1u);

    }
    else
    {
        printf("Scaler is disabled\n");
    }
#endif

    tivxExportGraphToDot(obj->graph, ".", "single_cam_graph");

    APP_PRINTF("app_create_graph exiting\n");
    return status;
}

vx_status app_delete_graph(AppObj *obj)
{
    uint32_t buf_id;
    vx_status status = VX_SUCCESS;

    if(NULL != obj->capture_node)
    {
        APP_PRINTF("releasing capture node\n");
        status |= vxReleaseNode(&obj->capture_node);
    }

    if(NULL != obj->node_viss)
    {
        APP_PRINTF("releasing node_viss\n");
        status |= vxReleaseNode(&obj->node_viss);
    }

    if(NULL != obj->node_rc)
    {
        APP_PRINTF("releasing node_rc\n");
        status |= vxReleaseNode(&obj->node_rc);
    }

#if 0
    if(NULL != obj->displayNode)
    {
        APP_PRINTF("releasing displayNode\n");
        status |= vxReleaseNode(&obj->displayNode);
    }
#endif

    status |= tivxReleaseRawImage(&obj->raw);
    APP_PRINTF("releasing raw image done\n");

   for(buf_id=0; buf_id < obj->num_cap_buf; buf_id++)
    {
       if(NULL != obj->cap_frames[buf_id])
       {
        APP_PRINTF("releasing cap_frame # %d\n", buf_id);
        status |= vxReleaseObjectArray(&(obj->cap_frames[buf_id]));
    }
   }

    if(NULL != obj->y12)
    {
        APP_PRINTF("releasing y12\n");
        status |= vxReleaseImage(&obj->y12);
    }

    if(NULL != obj->uv12_c1)
    {
        APP_PRINTF("releasing uv12_c1\n");
        status |= vxReleaseImage(&obj->uv12_c1);
    }

    if(NULL != obj->s8_b8_c4)
    {
        APP_PRINTF("releasing s8_b8_c4\n");
        status |= vxReleaseImage(&obj->s8_b8_c4);
    }

    if(NULL != obj->y8_r8_c2)
    {
        APP_PRINTF("releasing y8_r8_c2\n");
        status |= vxReleaseImage(&obj->y8_r8_c2);
    }

    if(NULL != obj->uv8_g8_c3)
    {
        APP_PRINTF("releasing uv8_g8_c3\n");
        status |= vxReleaseImage(&obj->uv8_g8_c3);
    }

    if(NULL != obj->configuration)
    {
        APP_PRINTF("releasing configuration\n");
        status |= vxReleaseUserDataObject(&obj->configuration);

    }

#if 0
    if(NULL != obj->display_param_obj)
    {
        APP_PRINTF("releasing Display Param Data Object\n");
        status |= vxReleaseUserDataObject(&obj->display_param_obj);
    }
#endif

    if(NULL != obj->capture_stats)
    {
        APP_PRINTF("releasing capture stats Object\n");
        status |= vxReleaseUserDataObject(&obj->capture_stats);
    }

#if 0
    if(vx_true_e == obj->scaler_enable)
    {
        if (NULL != obj->scaler_out_img)
        {
            APP_PRINTF("releasing Scaler Output Image \n");
            status |= vxReleaseImage(&obj->scaler_out_img);
        }

        if(NULL != obj->scalerNode)
        {
            APP_PRINTF("releasing Scaler Node \n");
            status |= vxReleaseNode(&obj->scalerNode);
        }

        if (NULL != obj->sc_coeff_obj)
        {
            APP_PRINTF("release Scalar coefficient data object \n");
            status |= vxReleaseUserDataObject(&obj->sc_coeff_obj);
        }
    }
#endif

    APP_PRINTF("releasing graph\n");
    status |= vxReleaseGraph(&obj->graph);
    APP_PRINTF("releasing graph done\n");
    return status;
}

vx_status app_run_graph(AppObj *obj)
{
    vx_status status = VX_SUCCESS;
    vx_uint32 i;
    vx_uint32 frm_loop_cnt;

    uint32_t buf_id;
    uint32_t num_refs_capture;
    vx_object_array out_capture_frames;
    int graph_parameter_num = 0;

    if(NULL == obj->sensor_name)
    {
        printf("sensor name is NULL \n");
        return VX_FAILURE;
    }
    status = appStartImageSensor(obj->sensor_name, CAPT_CHANNELS_MASK);

    /* Enqueue buf for pipe up but don't trigger graph execution */
    for(buf_id = 0; buf_id < obj->num_cap_buf - 1; buf_id++)
    {
        graph_parameter_num = 0;
        tivxGraphParameterEnqueueReadyRef(obj->graph, graph_parameter_num,
                                          (vx_reference*)&(obj->cap_frames[buf_id]),
                                          1, TIVX_GRAPH_PARAMETER_ENQUEUE_FLAG_PIPEUP);
        graph_parameter_num++;
    }

    graph_parameter_num = 0;
    /* Need to trigger again since display holds on to a buffer */
    vxGraphParameterEnqueueReadyRef(obj->graph, graph_parameter_num,
                                    (vx_reference*)&obj->cap_frames[obj->num_cap_buf-1], 1);
    graph_parameter_num++;

    /*
        The application reads and  processes the same image "frm_loop_cnt" times
        The output may change because on VISS, parameters are updated every frame based on AEWB results
        AEWB result is avaialble after 1 frame and is applied after 2 frames
        Therefore, first 2 output images will have wrong colors
    */
    frm_loop_cnt = obj->num_frames_to_run;
    frm_loop_cnt += obj->num_cap_buf;

    if(obj->is_interactive)
    {
        /* in interactive mode loop for ever */
        frm_loop_cnt  = 0xFFFFFFFF;
    }

    for(i=0; i<frm_loop_cnt; i++)
    {
        appPerfPointBegin(&obj->total_perf);
        graph_parameter_num = 0;
        vxGraphParameterDequeueDoneRef(obj->graph, graph_parameter_num, (vx_reference*)&out_capture_frames, 1, &num_refs_capture);
        graph_parameter_num++;

        APP_PRINTF(" frm_loop_cnt %d...\n", i);
        graph_parameter_num = 0;
        vxGraphParameterEnqueueReadyRef(obj->graph, graph_parameter_num, (vx_reference*)&out_capture_frames, 1);
        graph_parameter_num++;

        appPerfPointEnd(&obj->total_perf);

        if(obj->stop_task)
        {
            break;
        }
    }

    vxWaitGraph(obj->graph);

    /* Dequeue buf for pipe down */
    graph_parameter_num = 0;
    vxGraphParameterDequeueDoneRef(obj->graph, graph_parameter_num,
                                   (vx_reference*)&out_capture_frames, 1,
                                   &num_refs_capture);
    graph_parameter_num++;

    return status;
}

static void app_run_task(void *app_var)
{
    AppObj *obj = (AppObj *)app_var;

    appPerfStatsCpuLoadResetAll();

    app_run_graph(obj);

    obj->stop_task_done = 1;
}

static int32_t app_run_task_create(AppObj *obj)
{
    tivx_task_create_params_t params;
    int32_t status;

    tivxTaskSetDefaultCreateParams(&params);
    params.task_main = app_run_task;
    params.app_var = obj;

    obj->stop_task_done = 0;
    obj->stop_task = 0;

    status = tivxTaskCreate(&obj->task, &params);

    return status;
}

static void app_run_task_delete(AppObj *obj)
{
    while(obj->stop_task_done==0)
    {
         tivxTaskWaitMsecs(100);
    }

    tivxTaskDelete(&obj->task);
}

static char menu[] = {
    "\n"
    "\n =========================="
    "\n Demo : Single Camera w/ 2A"
    "\n =========================="
    "\n"
    "\n p: Print performance statistics"
    "\n"
#ifdef _APP_DEBUG_
    "\n s: Save Sensor RAW, VISS Output and H3A output images to File System"
    "\n"
#endif
    "\n e: Export performance statistics"
    "\n"
    "\n x: Exit"
    "\n"
    "\n Enter Choice: "
};

/* Querying node for sensor stats */
static vx_status get_capture_stats(AppObj *obj)
{
    vx_reference refs[1];
    uint32_t *data_ptr;
    tivx_capture_statistics_t *capture_stats_struct;
    vx_map_id capture_stats_map_id;
    uint32_t chIdx;

    if (NULL == obj->capture_stats) {
        return VX_FAILURE;
    }

    refs[0] = (vx_reference)obj->capture_stats;
    tivxNodeSendCommand(obj->capture_node, 0,
        TIVX_CAPTURE_GET_STATISTICS, refs, 1u);

    vxMapUserDataObject(
            (vx_user_data_object)refs[0],
            0,
            sizeof(tivx_capture_statistics_t),
            &capture_stats_map_id,
            (void **)&data_ptr,
            VX_READ_ONLY,
            VX_MEMORY_TYPE_HOST,
            0
        );

    capture_stats_struct = (tivx_capture_statistics_t*)data_ptr;

    /* As this is single instance app, array index to access status will be always '0U' */
    printf("\n\r==========================================================\r\n");
    printf(": Capture Status:\r\n");
    printf("==========================================================\r\n");
    printf(": FIFO Overflow Count: %d\r\n",
              capture_stats_struct->overflowCount[0U]);
    printf(": Spurious UDMA interrupt count: %d\r\n",
              capture_stats_struct->spuriousUdmaIntrCount[0U]);
    printf("  [Channel No] | Frame Queue Count |"
        " Frame De-queue Count | Frame Drop Count |\n");
    for(chIdx = 0U ; chIdx < 4 ; chIdx ++)
    {
        printf("\t\t%d|\t\t%d|\t\t%d|\t\t%d|\n",
              chIdx,
              capture_stats_struct->queueCount[0U][chIdx],
              capture_stats_struct->dequeueCount[0U][chIdx],
              capture_stats_struct->dropCount[0U][chIdx]);
    }
    vxUnmapUserDataObject((vx_user_data_object)refs[0], capture_stats_map_id);

    return VX_SUCCESS;
}


static vx_status app_run_graph_interactive(AppObj *obj)
{
    vx_status status;
    uint32_t done = 0;
    char ch;
    FILE *fp;
    app_perf_point_t *perf_arr[1];

    status = app_run_task_create(obj);
    if(status!=0)
    {
        printf("ERROR: Unable to create task\n");
    }
    else
    {
        while(!done)
        {
            printf(menu);
            ch = getchar();
            printf("\n");

            switch(ch)
            {
                case 'p':
                    appPerfStatsPrintAll();
                    tivx_utils_graph_perf_print(obj->graph);
                    appPerfPointPrint(&obj->total_perf);
                    printf("\n");
                    appPerfPointPrintFPS(&obj->total_perf);
                    printf("\n");
                    get_capture_stats(obj);
                    printf("\n");
                    break;
                case 's':
                    save_debug_images(obj, NULL);
                    break;
                case 'e':
                    perf_arr[0] = &obj->total_perf;
                    fp = appPerfStatsExportOpenFile(".", "apps_basic_demos_single_camera");
                    if (NULL != fp)
                    {
                        appPerfStatsExportAll(fp, perf_arr, 1);
                        tivx_utils_graph_perf_export(fp, obj->graph);
                        appPerfStatsExportCloseFile(fp);
                        appPerfStatsResetAll();
                    }
                    else
                    {
                        printf("fp is null\n");
                    }
                    break;
                case 'x':
                    obj->stop_task = 1;
                    done = 1;
                    break;
            }
        }
        app_run_task_delete(obj);
    }
    status = appStopImageSensor(obj->sensor_name, CAPT_CHANNELS_MASK);
    return status;
}

static void app_show_usage(int argc, char* argv[])
{
    printf("\n");
    printf(" Single Camera Demo - (c) Texas Instruments 2019\n");
    printf(" ========================================================\n");
    printf("\n");
    printf(" Usage,\n");
    printf("  %s --cfg <config file>\n", argv[0]);
    printf("\n");
}

#define MAX_FNAME 128

typedef struct
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_pixel_t;


static inline float clampf(float a, float min, float max)
{
    return a >= min ? (a <= max ? a : max) : min;
}

const float bt709_full_yuv2rgb[4][4] = {
    {   1.   ,    0.  ,          1.53571429, -196.57142857},
    {   1.   ,   -0.17857143,   -0.46428571,   82.28571429},
    {   1.   ,    1.82142857,   -0.,         -233.14285714},
    {   0.0  ,    0.0  ,         0.0,           1.   }
};

static inline void yuv444_to_rgb888(uint8_t y, uint8_t u, uint8_t v,
        uint8_t *r, uint8_t *g, uint8_t *b)
{

    *r = (uint8_t)clampf((y * bt709_full_yuv2rgb[2][0] + u * bt709_full_yuv2rgb[2][1] + v * bt709_full_yuv2rgb[2][2] +  bt709_full_yuv2rgb[2][3] + 0.5f), 0.f, 255.f);
    *g = (uint8_t)clampf((y * bt709_full_yuv2rgb[1][0] + u * bt709_full_yuv2rgb[1][1] + v * bt709_full_yuv2rgb[1][2] +  bt709_full_yuv2rgb[1][3] + 0.5f), 0.f, 255.f);
    *b = (uint8_t)clampf((y * bt709_full_yuv2rgb[0][0] + u * bt709_full_yuv2rgb[0][1] + v * bt709_full_yuv2rgb[0][2] +  bt709_full_yuv2rgb[0][3] + 0.5f), 0.f, 255.f);
}

void nv12_to_rgb_flipped(uint8_t* y_pixel, uint8_t* uv_pixel, uint8_t* rgb_data, uint32_t width, uint32_t height, uint32_t stride)
{
    int32_t i = 0;
    int32_t j = 0;
    uint32_t rgb_stride = stride * 3;
    uint32_t uv_rows = 0;

    for (j = 0; j < height; j++)
    {
        uint32_t y_offset = stride * j;
        uint32_t uv_offset = stride * uv_rows;
        rgb_pixel_t* rgb_pixel = (rgb_pixel_t*) (&rgb_data[rgb_stride * (height - (j + 1))]);
        for (i = 0; i < stride; i += 2)
        {
            yuv444_to_rgb888(y_pixel[y_offset + i + 0], uv_pixel[uv_offset + i + 0], uv_pixel[uv_offset + i + 1],
                            &(rgb_pixel->r), &(rgb_pixel->g), &(rgb_pixel->b));
            rgb_pixel++;
            yuv444_to_rgb888(y_pixel[y_offset + i + 1], uv_pixel[uv_offset + i + 0], uv_pixel[uv_offset + i + 1],
                            &(rgb_pixel->r), &(rgb_pixel->g), &(rgb_pixel->b));
            rgb_pixel++;
        }
        uv_rows =  (j%2) ? (uv_rows + 1) : uv_rows;
    }
}

void nv12_to_rgb(uint8_t* y_pixel, uint8_t* uv_pixel, uint8_t* rgb_data, uint32_t width, uint32_t height, uint32_t stride)
{
    int32_t i = 0;
    int32_t j = 0;
    uint32_t rgb_stride = stride * 3;
    uint32_t uv_rows = 0;

    for (j = 0; j < height; j++)
    {
        uint32_t y_offset = stride * j;
        uint32_t uv_offset = stride * uv_rows;
        rgb_pixel_t* rgb_pixel = (rgb_pixel_t*) (&rgb_data[rgb_stride * j]);
        for (i = 0; i < stride; i += 2)
        {
            yuv444_to_rgb888(y_pixel[y_offset + i + 0], uv_pixel[uv_offset + i + 0], uv_pixel[uv_offset + i + 1],
                            &(rgb_pixel->r), &(rgb_pixel->g), &(rgb_pixel->b));
            rgb_pixel++;
            yuv444_to_rgb888(y_pixel[y_offset + i + 1], uv_pixel[uv_offset + i + 0], uv_pixel[uv_offset + i + 1],
                            &(rgb_pixel->r), &(rgb_pixel->g), &(rgb_pixel->b));
            rgb_pixel++;
        }
        uv_rows =  (j%2) ? (uv_rows + 1) : uv_rows;
    }
}

#if 0
vx_int32 write_output_image_png_8bit(char * file_name, vx_image out_nv12)
{
    FILE * fp = fopen(file_name, "wb");
    if(!fp)
    {
        APP_PRINTF("Unable to open file %s\n", file_name);
        return -1;
    }

    /* vx_uint32 len1 = write_output_image_nv12_png_fp(fp, out_nv12); */

    fclose(fp);
    APP_PRINTF("%d bytes written to %s\n", len1, file_name);
    return len1;
}
#endif


int save_debug_images(AppObj *obj, char* dump_filename)
{
    int num_bytes_io = 0;
    static int file_index = 0;
    char raw_image_fname[MAX_FNAME];
    char yuv_image_fname[MAX_FNAME];
    char png_image_fname[MAX_FNAME];
    /* char scaler_image_fname[MAX_FNAME]; */
    char h3a_image_fname[MAX_FNAME];
    char failsafe_test_data_path[3] = "./";
    char * test_data_path = app_get_test_file_path();

    if(NULL == test_data_path)
    {
        printf("Test data path is NULL. Defaulting to current folder \n");
        test_data_path = failsafe_test_data_path;
    }

    if (dump_filename != NULL)
    {
        snprintf(raw_image_fname, MAX_FNAME, "%s/%s[%dx%d].raw", test_data_path, dump_filename, obj->width_in, obj->height_in);
        snprintf(yuv_image_fname, MAX_FNAME, "%s/%s[%dx%d].yuv", test_data_path, dump_filename, obj->width_in, obj->height_in);
        snprintf(png_image_fname, MAX_FNAME, "%s/%s[%dx%d].png", test_data_path, dump_filename, obj->width_in, obj->height_in);
        /* snprintf(scaler_image_fname, MAX_FNAME, "%s/img_msc_%s.yuv", test_data_path, dump_filename); */
        snprintf(h3a_image_fname, MAX_FNAME, "%s/%s.bin", test_data_path, dump_filename);
    }
    else
    {
        snprintf(raw_image_fname, MAX_FNAME, "%s/%s_%04d[%dx%d].raw", test_data_path, "img", file_index, obj->width_in, obj->height_in);
        snprintf(yuv_image_fname, MAX_FNAME, "%s/%s_%04d[%dx%d].yuv", test_data_path, "img_viss", file_index, obj->width_in, obj->height_in);
        snprintf(png_image_fname, MAX_FNAME, "%s/%s_%04d[%dx%d].png", test_data_path, "img_viss", file_index, obj->width_in, obj->height_in);
        /* snprintf(scaler_image_fname, MAX_FNAME, "%s/%s_%04d.yuv", test_data_path, "img_msc", file_index); */
        snprintf(h3a_image_fname, MAX_FNAME, "%s/%s_%04d.bin", test_data_path, "h3a", file_index);
    }

    printf("RAW file name %s \n", raw_image_fname);
    num_bytes_io = write_output_image_raw(raw_image_fname, obj->raw);
    if(num_bytes_io < 0)
    {
        printf("Error writing to RAW file \n");
        return VX_FAILURE;
    }

    printf("YUV file name %s \n", yuv_image_fname);
    num_bytes_io = write_output_image_nv12_8bit(yuv_image_fname, obj->y8_r8_c2);
    if(num_bytes_io < 0)
    {
        printf("Error writing to VISS NV12 file \n");
        return VX_FAILURE;
    }

    /* printf("png file name %s \n", png_image_fname); */
    /* num_bytes_io = write_output_image_png_8bit(png_image_fname, obj->y8_r8_c2); */
    /* if(num_bytes_io < 0) */
    /* { */
    /*     printf("Error writing to VISS NV12 file \n"); */
    /*     return VX_FAILURE; */
    /* } */

    /* if(obj->scaler_enable) */
    /* { */
    /*     printf("YUV file name %s \n", scaler_image_fname); */
    /*     num_bytes_io = write_output_image_nv12_8bit(scaler_image_fname, obj->scaler_out_img); */
    /*     if(num_bytes_io < 0) */
    /*     { */
    /*         printf("Error writing to MSC NV12 file \n"); */
    /*         return VX_FAILURE; */
    /*     } */
    /* } */

    file_index++;
    return (file_index-1);
}

vx_int32 write_output_image_fp(FILE * fp, vx_image out_image)
{
    vx_uint32 width, height;
    vx_df_image df;
    vx_imagepatch_addressing_t image_addr;
    vx_rectangle_t rect;
    vx_map_id map_id1, map_id2;
    void *data_ptr1, *data_ptr2;
    vx_uint32 num_bytes_per_pixel = 1;
    vx_uint32 num_luma_bytes_written_to_file=0;
	vx_uint32 num_chroma_bytes_written_to_file=0;
	vx_uint32 num_bytes_written_to_file=0;
    vx_uint32 imgaddr_width, imgaddr_height, imgaddr_stride;
	int i;

    vxQueryImage(out_image, VX_IMAGE_WIDTH, &width, sizeof(vx_uint32));
    vxQueryImage(out_image, VX_IMAGE_HEIGHT, &height, sizeof(vx_uint32));
    vxQueryImage(out_image, VX_IMAGE_FORMAT, &df, sizeof(vx_df_image));

    rect.start_x = 0;
    rect.start_y = 0;
    rect.end_x = width;
    rect.end_y = height;

    vxMapImagePatch(out_image,
        &rect,
        0,
        &map_id1,
        &image_addr,
        &data_ptr1,
        VX_WRITE_ONLY,
        VX_MEMORY_TYPE_HOST,
        VX_NOGAP_X
        );


    if(!data_ptr1)
    {
        printf("data_ptr1 is NULL \n");
        return -1;
    }

    imgaddr_width  = image_addr.dim_x;
    imgaddr_height = image_addr.dim_y;
    imgaddr_stride = image_addr.stride_y;

    num_luma_bytes_written_to_file = 0;

    for(i=0;i<imgaddr_height;i++)
    {
        num_luma_bytes_written_to_file  += fwrite(data_ptr1, 1, imgaddr_width*num_bytes_per_pixel, fp);
        data_ptr1 += imgaddr_stride;
    }
    vxUnmapImagePatch(out_image, map_id1);

    fflush(fp);

	vxMapImagePatch(out_image,
        &rect,
        1,
        &map_id2,
        &image_addr,
        &data_ptr2,
        VX_WRITE_ONLY,
        VX_MEMORY_TYPE_HOST,
        VX_NOGAP_X
        );

    if(!data_ptr2)
    {
        printf("data_ptr2 is NULL \n");
        return -1;
    }

    imgaddr_width  = image_addr.dim_x;
    imgaddr_height = image_addr.dim_y;
    imgaddr_stride = image_addr.stride_y;

    num_chroma_bytes_written_to_file = 0;
    for(i=0;i<imgaddr_height/2;i++)
    {
        num_chroma_bytes_written_to_file  += fwrite(data_ptr2, 1, imgaddr_width*num_bytes_per_pixel, fp);
        data_ptr2 += imgaddr_stride;
    }

    fflush(fp);

    vxUnmapImagePatch(out_image, map_id2);

    num_bytes_written_to_file = num_luma_bytes_written_to_file + num_chroma_bytes_written_to_file;
	printf("Written %d bytes \n", num_bytes_written_to_file);

    return num_bytes_written_to_file;
}


static void
user_write_data(png_structp png_ptr,
        png_bytep data, png_size_t length)
{
    FILE *fp = (FILE *)png_get_io_ptr(png_ptr);
    size_t result;

    result = fwrite(data, 1, length, fp);

    if (result != length)
    {
        printf("result %lu\n", result);
    }
}

static void
user_flush_data(png_structp png_ptr)
{
    FILE *fp = (FILE *)png_get_io_ptr(png_ptr);

    if (fflush(fp))
    {
        png_error(png_ptr, "Failed to flush png file!");
    }
}

vx_int32 write_output_image_nv12_png_fp(FILE * fp, vx_image out_image)
{
    png_byte color_type = PNG_COLOR_TYPE_RGB;
    png_structp png_ptr;
    png_infop info_ptr;
    jmp_buf jb;
    vx_uint32 width, height;
    vx_size planes;
    vx_df_image df;
    vx_imagepatch_addressing_t image_addr;
    vx_rectangle_t rect;
    vx_map_id map_id1, map_id2;
    void *data_ptr1, *data_ptr2;
    vx_uint32 imgaddr_width, imgaddr_height, imgaddr_stride;
    int i;

    vxQueryImage(out_image, VX_IMAGE_WIDTH, &width, sizeof(vx_uint32));
    vxQueryImage(out_image, VX_IMAGE_HEIGHT, &height, sizeof(vx_uint32));
    vxQueryImage(out_image, VX_IMAGE_FORMAT, &df, sizeof(vx_df_image));
    vxQueryImage(out_image, VX_IMAGE_PLANES, &planes, sizeof(vx_size));

    rect.start_x = 0;
    rect.start_y = 0;
    rect.end_x = width;
    rect.end_y = height;

    vxMapImagePatch(out_image,
        &rect,
        0,
        &map_id1,
        &image_addr,
        &data_ptr1,
        VX_WRITE_ONLY,
        VX_MEMORY_TYPE_HOST,
        VX_NOGAP_X
        );

    vxMapImagePatch(out_image,
        &rect,
        1,
        &map_id2,
        &image_addr,
        &data_ptr2,
        VX_WRITE_ONLY,
        VX_MEMORY_TYPE_HOST,
        VX_NOGAP_X
        );

    if(!data_ptr1)
    {
        printf("data_ptr1 is NULL \n");
        return -1;
    }

    if(!data_ptr2)
    {
        printf("data_ptr2 is NULL \n");
        return -1;
    }

    imgaddr_width  = image_addr.dim_x;
    imgaddr_height = image_addr.dim_y;
    imgaddr_stride = image_addr.stride_y;
    uint8_t* rgb_data = (uint8_t*)malloc(imgaddr_stride * 3 * imgaddr_height);
    nv12_to_rgb(data_ptr1, data_ptr2, rgb_data, imgaddr_width, imgaddr_height, imgaddr_stride);
     /* ...create write structure */
    if (!(png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, &jb, NULL, NULL)))
    {
        return -1;
    }

    if (!(info_ptr = png_create_info_struct(png_ptr)))
    {
        return -1;
    }

    /* ...prepare emergency return point */
    if (setjmp(jb) != 0)
    {
        return -1;
    }

    /* ...initialize I/O */
    png_init_io(png_ptr, fp);
    png_set_bgr(png_ptr);
    png_set_write_fn(png_ptr, fp, user_write_data, user_flush_data);
    /* ...write header */
    png_set_IHDR(png_ptr, info_ptr, imgaddr_width, imgaddr_height, 8, color_type, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);


    /* ...write info structure */
    png_write_info(png_ptr, info_ptr);
    /* ...write all image rows */
    uint8_t                 *rows[imgaddr_height];

    for (i = 0; i < imgaddr_height; i++)
    {
        rows[i] = rgb_data + i * (imgaddr_stride * 3);
    }
    png_set_rows(png_ptr, info_ptr, rows);
    png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
    /* ...mark completion of the image */
    png_write_end(png_ptr, NULL);
    png_write_flush(png_ptr);
    free(rgb_data);

    fflush(fp);

    vxUnmapImagePatch(out_image, map_id1);
    vxUnmapImagePatch(out_image, map_id2);

    return imgaddr_stride * 3 * imgaddr_height;
}

vx_int32 write_output_image_nv12_8bit(char * file_name, vx_image out_nv12)
{
    FILE * fp = fopen(file_name, "wb");
    if(!fp)
    {
        APP_PRINTF("Unable to open file %s\n", file_name);
        return -1;
    }
    vx_uint32 len1 = write_output_image_fp(fp, out_nv12);
    fclose(fp);
    APP_PRINTF("%d bytes written to %s\n", len1, file_name);
    return len1;
}

vx_int32 write_output_image_raw(char * file_name, tivx_raw_image raw_image)
{
    FILE * fp = fopen(file_name, "wb");
    vx_uint32 width, height, i;
    vx_imagepatch_addressing_t image_addr;
    vx_rectangle_t rect;
    vx_map_id map_id;
    void *data_ptr;
    vx_uint32 num_bytes_per_pixel = 2; /*Mayank : Hardcoded to 12b Unpacked format*/
    vx_uint32 num_bytes_written_to_file;
    tivx_raw_image_format_t format;
    vx_uint32 imgaddr_width, imgaddr_height, imgaddr_stride;

    if(!fp)
    {
        APP_PRINTF("Unable to open file %s\n", file_name);
        return -1;
    }

    tivxQueryRawImage(raw_image, TIVX_RAW_IMAGE_WIDTH, &width, sizeof(vx_uint32));
    tivxQueryRawImage(raw_image, TIVX_RAW_IMAGE_HEIGHT, &height, sizeof(vx_uint32));
    tivxQueryRawImage(raw_image, TIVX_RAW_IMAGE_FORMAT, &format, sizeof(format));

    APP_PRINTF("in width =  %d\n", width);
    APP_PRINTF("in height =  %d\n", height);
    APP_PRINTF("in format =  %d\n", format.pixel_container);

    rect.start_x = 0;
    rect.start_y = 0;
    rect.end_x = width;
    rect.end_y = height;

    tivxMapRawImagePatch(raw_image,
        &rect,
        0,
        &map_id,
        &image_addr,
        &data_ptr,
        VX_READ_ONLY,
        VX_MEMORY_TYPE_HOST,
        TIVX_RAW_IMAGE_PIXEL_BUFFER
        );

    if(!data_ptr)
    {
        APP_PRINTF("data_ptr is NULL \n");
        fclose(fp);
        return -1;
    }
    num_bytes_written_to_file = 0;

    imgaddr_width  = image_addr.dim_x;
    imgaddr_height = image_addr.dim_y;
    imgaddr_stride = image_addr.stride_y;

    for(i=0;i<imgaddr_height;i++)
    {
        num_bytes_written_to_file += fwrite(data_ptr, 1, imgaddr_width*num_bytes_per_pixel, fp);
        data_ptr += imgaddr_stride;
    }

    tivxUnmapRawImagePatch(raw_image, map_id);

    fflush(fp);
    fclose(fp);
    APP_PRINTF("%d bytes written to %s\n", num_bytes_written_to_file, file_name);
    return num_bytes_written_to_file;
}

vx_char default_sensor_name[ISS_SENSORS_MAX_NAME] = SENSOR_SONY_IMX390_UB953_D3;
void app_set_cfg_default(AppObj *obj)
{
    obj->width_in = 1920;
    obj->height_in = 1080;
    obj->width_out = 1920;
    obj->height_out = 1080;
    obj->is_interactive = 1;
    obj->sensor_name = default_sensor_name;
}

static void app_parse_cfg_file(AppObj *obj, char *cfg_file_name)
{
    FILE *fp = fopen(cfg_file_name, "r");
    char line_str[1024];
    char *token;

    if(fp==NULL)
    {
        printf("# ERROR: Unable to open config file [%s]. Switching to interactive mode\n", cfg_file_name);
        obj->is_interactive = 1;
    }

    while(fgets(line_str, sizeof(line_str), fp)!=NULL)
    {
        char s[]=" \t";

        if (strchr(line_str, '#'))
        {
            continue;
        }

        /* get the first token */
        token = strtok(line_str, s);
        if(strcmp(token, "sensor_index")==0)
        {
            token = strtok(NULL, s);
            obj->sensor_sel = atoi(token);
            printf("sensor_selection = [%d]\n", obj->sensor_sel);
        }
        else
        if(strcmp(token, "num_frames_to_run")==0)
        {
            token = strtok(NULL, s);
            obj->num_frames_to_run = atoi(token);
            printf("num_frames_to_run = [%d]\n", obj->num_frames_to_run);
        }
        else
        if(strcmp(token, "is_interactive")==0)
        {
            token = strtok(NULL, s);
            obj->is_interactive = atoi(token);
            printf("is_interactive = [%d]\n", obj->is_interactive);
        }
        else
        {
            APP_PRINTF("Invalid token [%s]\n", token);
        }
    }

    fclose(fp);

    if(obj->width_in<128)
        obj->width_in = 128;
    if(obj->height_in<128)
        obj->height_in = 128;
    if(obj->width_out<128)
        obj->width_out = 128;
    if(obj->height_out<128)
        obj->height_out = 128;

}

vx_status app_parse_cmd_line_args(AppObj *obj, int argc, char *argv[])
{
    app_set_cfg_default(obj);

    int i;
    if(argc==1)
    {
        app_show_usage(argc, argv);
        printf("Defaulting to interactive mode \n");
        obj->is_interactive = 1;
        return VX_SUCCESS;
    }

    for(i=0; i<argc; i++)
    {
        if(strcmp(argv[i], "--cfg")==0)
        {
            i++;
            if(i>=argc)
            {
                app_show_usage(argc, argv);
            }
            app_parse_cfg_file(obj, argv[i]);
            break;
        }
        else
        if(strcmp(argv[i], "--help")==0)
        {
            app_show_usage(argc, argv);
            return VX_FAILURE;
        }
    }
    return VX_SUCCESS;
}



#ifdef _APP_DEBUG_
vx_int32 write_output_image_nv12(char * file_name, vx_image out_nv12)
{
    FILE * fp = fopen(file_name, "wb");
    if(!fp)
    {
        APP_PRINTF("Unable to open file %s\n", file_name);
        return -1;
    }
    vx_uint32 len1 = write_output_image_fp(fp, out_nv12);
    fclose(fp);
    APP_PRINTF("%d bytes written to %s\n", len1, file_name);
    return len1;
}
#endif


AppObj gAppObj;

int app_single_cam_main(int argc, char* argv[])
{
    AppObj *obj = &gAppObj;
    vx_status status = VX_FAILURE;
    status = app_parse_cmd_line_args(obj, argc, argv);
    if(VX_SUCCESS == status)
    {
        status = app_init(obj);
        if(VX_SUCCESS == status)
        {
            APP_PRINTF("app_init done\n");
            status = app_create_graph(obj);
            if(VX_SUCCESS == status)
            {
                APP_PRINTF("app_create_graph done\n");
                if(obj->is_interactive)
                {
                    status = app_run_graph_interactive(obj);
                }
                else
                {
                    status = app_run_graph(obj);
                }
                if(VX_SUCCESS == status)
                {
                    APP_PRINTF("app_run_graph done\n");
                    status = app_delete_graph(obj);
                    if(VX_SUCCESS == status)
                    {
                        APP_PRINTF("app_delete_graph done\n");
                    }
                    else
                    {
                        printf("Error : app_delete_graph returned 0x%x \n", status);
                    }
                }
                else
                {
                    printf("Error : app_run_graph_xx returned 0x%x \n", status);
                }
            }
            else
            {
                printf("Error : app_create_graph returned 0x%x is_interactive =%d  \n", status, obj->is_interactive);
            }
        }
        else
        {
            printf("Error : app_init returned 0x%x \n", status);
        }
        status = app_deinit(obj);
        if(VX_SUCCESS == status)
        {
            APP_PRINTF("app_deinit done\n");
        }
        else
        {
            printf("Error : app_deinit returned 0x%x \n", status);
        }
        appDeInitImageSensor(obj->sensor_name, CAPT_CHANNELS_MASK);
    }
    else
    {
        printf("Error: app_parse_cmd_line_args returned 0x%x \n", status);
    }

    return 0;
}
