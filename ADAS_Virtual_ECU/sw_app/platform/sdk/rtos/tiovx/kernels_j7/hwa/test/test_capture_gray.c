/*
 * Sample application for CSIRX GRAY8 capture
 *
 * Copyright (c) 2019 Texas Instruments Incorporated
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
 */

#include <VX/vx.h>
#include <TI/tivx.h>
#include "test_engine/test.h"
#include <TI/tivx_config.h>
#include <string.h>
#include "tivx_utils_file_rd_wr.h"
#include <TI/tivx_task.h>
#include "math.h"
#include <limits.h>
#include "test_tiovx/test_tiovx.h"
#include "tivx_utils_file_rd_wr.h"

#include <utils/sensors/include/app_sensors.h>
#include <utils/remote_service/include/app_remote_service.h>
#include <utils/ipc/include/app_ipc.h>
#include "test_hwa_common.h"
#include <utils/iss/include/app_iss.h>

#define VX_DF_IMAGE_FORMAT	VX_DF_IMAGE_U8
#define MAX_ABS_FILENAME	1024
#define MAX_NUM_BUF		8
#define NUM_CHANNELS		1
#define CAPT_CH_IDX		4 /* des#2 port#0 */
#define CAPT_INST_ID		1

#define IMAGE_WIDTH		1600
#define IMAGE_HEIGHT		(1300+1) /* including EMB line */

static const vx_char user_data_object_name[] = "tivx_capture_params_t";

static int load_to_gray8_file(vx_image copy_image, int w, int h, const char* filename, int offset)
{
    void* data;
    FILE* fp;
    int datasize;
    int numbytes = w * h * 1;
    char file[MAX_ABS_FILENAME + 1];
    vx_rectangle_t rect = { 0, 0, w, h };
    vx_imagepatch_addressing_t addr = VX_IMAGEPATCH_ADDR_INIT;
    int ret = 0;

    addr.dim_x = w;
    addr.dim_y = h;
    addr.stride_x = 1;     /* bpp */
    addr.stride_y = w * 1; /* stride */

    snprintf(file, MAX_ABS_FILENAME + 1, "%s/%s", ct_get_test_file_path(), filename);
    fp = fopen(file, "wb");
    if(!fp) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    data = ct_alloc_mem(numbytes);
    if (data != NULL) {
        memset(data, 0xAA, numbytes);
        fseek(fp, offset, SEEK_CUR);

        vxCopyImagePatch(copy_image, &rect, 0, &addr, data, VX_READ_ONLY, VX_MEMORY_TYPE_HOST);

        datasize = fwrite(data, 1, numbytes - offset, fp);
        if (datasize != (numbytes - offset)) {
            printf("Error: file_size != w * h\n");
            ret = -1;
        }
    }

    ct_free_mem(data);
    fclose(fp);

    return ret;
}

/*
 * Utility API used to add a graph parameter from a node, node parameter index
 */
static void add_graph_parameter_by_node_index(vx_graph graph, vx_node node, vx_uint32 node_parameter_index)
{
    vx_parameter parameter = vxGetParameterByIndex(node, node_parameter_index);

    vxAddParameterToGraph(graph, parameter);
    vxReleaseParameter(&parameter);
}

static uint32_t initSensorParams(uint32_t sensor_features_supported)
{
    uint32_t sensor_features_enabled = 0;

    if(ISS_SENSOR_FEATURE_MANUAL_EXPOSURE == (sensor_features_supported & ISS_SENSOR_FEATURE_MANUAL_EXPOSURE))
    {
        sensor_features_enabled |= ISS_SENSOR_FEATURE_MANUAL_EXPOSURE;
    }

    if(ISS_SENSOR_FEATURE_MANUAL_GAIN == (sensor_features_supported & ISS_SENSOR_FEATURE_MANUAL_GAIN))
    {
        sensor_features_enabled |= ISS_SENSOR_FEATURE_MANUAL_GAIN;
    }

    return sensor_features_enabled;
}

TESTCASE(tivxHwaCaptureGray, CT_VXContext, ct_setup_vx_context, 0)

typedef struct {
    const char* name;
    int loop_cnt;
    int raw_capture;
} Arg_Capture;

#define CAPTURE_PARAMETERS \
    CT_GENERATE_PARAMETERS("capture", ARG, 100, 1)

TEST_WITH_ARG(tivxHwaCaptureGray, testRawImageCapture, Arg_Capture, CAPTURE_PARAMETERS)
{
    /* Graph objects */
    vx_context context = context_->vx_context_;
    vx_graph graph;
    vx_node n0;

    /* Data objects for graph */
    vx_object_array capture_frames[MAX_NUM_BUF];
    vx_user_data_object capture_config;
    vx_image image = 0;

    /* Local objects */
    vx_graph_parameter_queue_params_t graph_parameters_queue_params_list[1];
    tivx_capture_params_t local_capture_config;
    uint32_t num_capture_channels = NUM_CHANNELS;
    uint32_t buf_id, loop_id, loop_cnt, num_buf, chIdx, out_num_refs;
    uint64_t exe_time;
    vx_bool done;
    vx_object_array dequeue_capture_array;

    /* Image objects */
    vx_reference refs[1];
    vx_user_data_object capture_stats_obj;
    tivx_capture_statistics_t *capture_stats_struct;
    vx_map_id capture_stats_map_id;
    uint32_t *data_ptr;
    vx_imagepatch_addressing_t addr;
    vx_rectangle_t rect;

    /* Sensor Parameters */
    char* sensor_list[ISS_SENSORS_MAX_SUPPORTED_SENSOR];
    vx_uint8 num_sensors_found, count = 0;
    IssSensor_CreateParams sensorParams;
    char availableSensorNames[ISS_SENSORS_MAX_SUPPORTED_SENSOR][ISS_SENSORS_MAX_NAME];
    char *sensor_name;
    uint32_t sensor_features_enabled = 0, sensor_features_supported = 0;

    /* Setting to num buf of capture node */
    num_buf = 3;
    loop_cnt = arg_->loop_cnt;

    /* Init for test case */
    tivxHwaLoadKernels(context);
    CT_RegisterForGarbageCollection(context, ct_teardown_hwa_kernels, CT_GC_OBJECT);
    tivx_clr_debug_zone(VX_ZONE_INFO);

    ASSERT_VX_OBJECT(graph = vxCreateGraph(context), VX_TYPE_GRAPH);

    /* Imaging Initialization */
    {
        memset(availableSensorNames, 0, ISS_SENSORS_MAX_SUPPORTED_SENSOR*ISS_SENSORS_MAX_NAME);
        for(count=0;count<ISS_SENSORS_MAX_SUPPORTED_SENSOR;count++)
        {
            sensor_list[count] = availableSensorNames[count];
        }
        VX_CALL(appEnumerateImageSensor(sensor_list, &num_sensors_found));

        sensor_name = sensor_list[7]; /* Note: hardcoding to Magna OV2311 */

        memset(&sensorParams, 0, sizeof(sensorParams));
        VX_CALL(appQueryImageSensor(sensor_name, &sensorParams));

        sensor_features_supported = sensorParams.sensorInfo.features;

        sensor_features_enabled = initSensorParams(sensor_features_supported);

        VX_CALL(appInitImageSensor(sensor_name, sensor_features_enabled, (1<<CAPT_CH_IDX)));
    }

    /* Creating objects for graph */
    {
        ASSERT_VX_OBJECT(image = vxCreateImage(context, IMAGE_WIDTH, IMAGE_HEIGHT, VX_DF_IMAGE_FORMAT), VX_TYPE_IMAGE);

        /* allocate Input and Output refs, multiple refs created to allow pipelining of graph */
        for(buf_id=0; buf_id<num_buf; buf_id++)
        {
            ASSERT_VX_OBJECT(capture_frames[buf_id] = vxCreateObjectArray(context, (vx_reference)image, num_capture_channels), VX_TYPE_OBJECT_ARRAY);
        }

        /* Config initialization */
        tivx_capture_params_init(&local_capture_config);
        local_capture_config.numInst = 1;
        local_capture_config.numCh   = 1;
        local_capture_config.mask    = 0x01;
        local_capture_config.chVcNum[0]   = 0;
        local_capture_config.chInstMap[0] = CAPT_INST_ID;
        {
            local_capture_config.instId[0] = CAPT_INST_ID;
            local_capture_config.instCfg[0].enableCsiv2p0Support = (uint32_t)vx_true_e;
            local_capture_config.instCfg[0].numDataLanes         = 4U;
            for (loop_id = 0U; loop_id < local_capture_config.instCfg[0U].numDataLanes ; loop_id++)
            {
                local_capture_config.instCfg[0].dataLanesMap[loop_id] = (loop_id + 1u);
            }
        }

        ASSERT_VX_OBJECT(capture_config = vxCreateUserDataObject(context, user_data_object_name, sizeof(tivx_capture_params_t), &local_capture_config), (enum vx_type_e)VX_TYPE_USER_DATA_OBJECT);

        ASSERT_VX_OBJECT(n0 = tivxCaptureNode(graph, capture_config, capture_frames[0]), VX_TYPE_NODE);
    }

    /* Pipelining and graph verification */
    {
        /* input @ node index 0, becomes graph parameter 1 */
        add_graph_parameter_by_node_index(graph, n0, 1);

        /* set graph schedule config such that graph parameter @ index 0 and 1 are enqueuable */
        graph_parameters_queue_params_list[0].graph_parameter_index = 0;
        graph_parameters_queue_params_list[0].refs_list_size = num_buf;
        graph_parameters_queue_params_list[0].refs_list = (vx_reference*)&capture_frames[0];

        /* Schedule mode auto is used, here we dont need to call vxScheduleGraph
         * Graph gets scheduled automatically as refs are enqueued to it
         */
        vxSetGraphScheduleConfig(graph,
                VX_GRAPH_SCHEDULE_MODE_QUEUE_AUTO,
                1,
                graph_parameters_queue_params_list
                );

        VX_CALL(vxSetNodeTarget(n0, VX_TARGET_STRING, TIVX_TARGET_CAPTURE2));
        ASSERT_EQ_VX_STATUS(VX_SUCCESS, vxVerifyGraph(graph));
    }


    /* iniitalizing sensor */
    VX_CALL(appStartImageSensor(sensor_name, (1<<CAPT_CH_IDX)));

    exe_time = tivxPlatformGetTimeInUsecs();

    /* enqueue buf for pipeup but dont trigger graph execution */
    for(buf_id=0; buf_id<num_buf-1; buf_id++)
    {
        tivxGraphParameterEnqueueReadyRef(graph, 0, (vx_reference*)&capture_frames[buf_id], 1, TIVX_GRAPH_PARAMETER_ENQUEUE_FLAG_PIPEUP);
    }

    /* after pipeup, now enqueue a buffer to trigger graph scheduling */
    vxGraphParameterEnqueueReadyRef(graph, 0, (vx_reference*)&capture_frames[buf_id], 1);

    /* wait for graph instances to complete, compare output and recycle data buffers, schedule again */
    for(loop_id=0; loop_id<(loop_cnt+num_buf); loop_id++)
    {
        uint32_t num_refs;
        vx_object_array out_capture_frames;
        uint64_t timestamp0 = 0;

        /* Get output reference, waits until a reference is available */
        vxGraphParameterDequeueDoneRef(graph, 0, (vx_reference*)&out_capture_frames, 1, &num_refs);

        {
            vx_image element0;
            char filename[MAX_ABS_FILENAME];

            ASSERT_VX_OBJECT(element0 = (vx_image) vxGetObjectArrayItem(out_capture_frames, 0), VX_TYPE_IMAGE);

            VX_CALL(vxQueryReference((vx_reference)element0, TIVX_REFERENCE_TIMESTAMP, &timestamp0, sizeof(timestamp0)));

            snprintf(filename, MAX_ABS_FILENAME, "%s%d%s", "video", loop_id, ".gray");
            if (loop_id == loop_cnt)
                load_to_gray8_file(element0, IMAGE_WIDTH, IMAGE_HEIGHT, filename, 0);

            VX_CALL(vxReleaseImage(&element0));
        }

        vxGraphParameterEnqueueReadyRef(graph, 0, (vx_reference*)&out_capture_frames, 1);
    }

    /* ensure all graph processing is complete */
    vxWaitGraph(graph);

    exe_time = tivxPlatformGetTimeInUsecs() - exe_time;

    /* Dequeue all buffers */
    done = vx_false_e;
    while(!done)
    {
        VX_CALL(vxGraphParameterCheckDoneRef(graph, 0, &out_num_refs));

        if(out_num_refs>0)
        {
            VX_CALL(vxGraphParameterDequeueDoneRef(graph, 0, (vx_reference*)&dequeue_capture_array, 1, &out_num_refs));
        }

        if(out_num_refs == 0)
        {
            done = vx_true_e;
        }
    }

    VX_CALL(appStopImageSensor(sensor_name, (1<< CAPT_CH_IDX))); /*Mask for 4 cameras*/

    /* Querying node for sensor stats */
    {
        capture_stats_obj =
            vxCreateUserDataObject(context, "tivx_capture_statistics_t" ,
            sizeof(tivx_capture_statistics_t), NULL);

        refs[0] = (vx_reference)capture_stats_obj;
        tivxNodeSendCommand(n0, 0,
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
        chIdx = 0U;
        {
            printf("\t\t%d|\t\t%d|\t\t%d|\t\t%d|\n",
                  chIdx,
                  capture_stats_struct->queueCount[0U][chIdx],
                  capture_stats_struct->dequeueCount[0U][chIdx],
                  capture_stats_struct->dropCount[0U][chIdx]);
        }
        vxUnmapUserDataObject((vx_user_data_object)refs[0], capture_stats_map_id);
    }

    VX_CALL(vxReleaseNode(&n0));
    VX_CALL(vxReleaseGraph(&graph));

    {
        VX_CALL(vxReleaseImage(&image));
    }

    for(buf_id=0; buf_id<num_buf; buf_id++)
    {
        VX_CALL(vxReleaseObjectArray(&capture_frames[buf_id]));
    }
    VX_CALL(vxReleaseUserDataObject(&capture_config));
    VX_CALL(vxReleaseUserDataObject(&capture_stats_obj));

    tivxHwaUnLoadKernels(context);

    appDeInitImageSensor(sensor_name, (1<< CAPT_CH_IDX));

    tivx_clr_debug_zone(VX_ZONE_INFO);
}

TESTCASE_TESTS(tivxHwaCaptureGray,
               testRawImageCapture)
