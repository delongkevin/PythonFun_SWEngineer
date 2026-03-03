/*******************************************************************************
 * test_csitx_yuv10.c
 *
 * Sample application for CSITX UYVY 10bit pattern output demonstration
 *
 * Copyright (c) 2022 Cogent Embedded Inc.
 * ALL RIGHTS RESERVED.
 *
 * The source code contained or described herein and all documents related to the
 * source code("Software") or their modified versions are owned by
 * Cogent Embedded Inc. or its affiliates.
 *
 *******************************************************************************/

#include <VX/vx.h>
#include <TI/tivx.h>
#include "test_engine/test.h"
#include <TI/tivx_config.h>
#include <string.h>
#include <TI/tivx_task.h>
#include <TI/tivx_event.h>
#include "math.h"
#include <limits.h>
#include <string.h>
#include "test_tiovx/test_tiovx.h"
#include "test_hwa_common.h"

#define CSITX_INST_ID        (0U)
#define NUM_CHANNELS         (1U)

#define TIVX_TARGET_DEFAULT_STACK_SIZE       (64U * 1024U)
#define TIVX_TARGET_DEFAULT_TASK_PRIORITY1   (8U)

#define MAX_ABS_FILENAME     (1024U)

TESTCASE(tivxHwaCsitxYUV10, CT_VXContext, ct_setup_vx_context, 0)

static tivx_event eventHandle_TxFinished;

static vx_context context;
static vx_image image;
static uint32_t width, height, loop_cnt;
static vx_rectangle_t rect;

typedef struct {
    const char* name;
    uint32_t Width;
    uint32_t Height;
    uint32_t loopCount;
} Arg;

#define ADD_WIDTH(testArgName, nextmacro, ...) \
    CT_EXPAND(nextmacro(testArgName "/Width=1024", __VA_ARGS__, 1024))
#define ADD_HEIGHT(testArgName, nextmacro, ...) \
    CT_EXPAND(nextmacro(testArgName "/Height=768", __VA_ARGS__, 768))
#define ADD_LOOPCOUNT(testArgName, nextmacro, ...) \
    CT_EXPAND(nextmacro(testArgName "/loopCount=1000", __VA_ARGS__, 1000))

#define PARAMETERS \
    CT_GENERATE_PARAMETERS("CsitxYUV10", ADD_WIDTH, ADD_HEIGHT, ADD_LOOPCOUNT ,ARG)

void* data;

static int generate_raw_file_uyvy(vx_image copy_image, int w, int h, const char* filename, int offset)
{
    int numbytes = w * h * 2;
    vx_rectangle_t rect             = { 0, 0, w, h };
    vx_imagepatch_addressing_t addr = VX_IMAGEPATCH_ADDR_INIT;
    int i, j;
				  /* U Y V Y */
    uint32_t color_map_uyvy[8] = {0x80ff80ff, // white
				  0xffef00ef, // yellow
				  0x00cfffcf, // blue
				  0x008f008f, // green
				  0xff70ff70, // cyan
				  0xff400040, // red
				  0x0010ff10, // blue
				  0x80008000}; // black

    addr.dim_x = w;
    addr.dim_y = h;
    addr.stride_x = 2;     /* bpp */
    addr.stride_y = w * 2; /* stride */

    data = ct_alloc_mem(numbytes);
    if (data != NULL) {
        uint32_t* buf = data;

        memset(data, 0x0, numbytes);

        // generate pattern
        for (j = 0; j < h; j++) {
            for (i = 0; i < w / 2; i++) {
                *buf = color_map_uyvy[i / (w / 8 / 2)];
                buf++;
            }
        }

        vxCopyImagePatch(copy_image, &rect, 0, &addr, data, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST);
    }

    return 0;
}

static int rolling_raw_file_uyvy(vx_image copy_image, int w, int h, const char* filename, int offset, int counter)
{
    vx_rectangle_t rect             = { 0, h * counter, w, h * (counter + 1)};
    vx_imagepatch_addressing_t addr = VX_IMAGEPATCH_ADDR_INIT;
    int i, j;

    addr.dim_x = w;
    addr.dim_y = h;
    addr.stride_x = 2;     /* bpp */
    addr.stride_y = w * 2; /* stride */

    if (data != NULL) {
        uint32_t* buf = (uint32_t*)((uint8_t *)data + w * h * 2 * counter);

        // invert pattern in next rectangle
        for (j = 0; j < h; j++) {
            for (i = 0; i < w / 2; i++) {
                *buf = ~(*buf);
                buf++;
            }
        }

        vxCopyImagePatch(copy_image, &rect, 0, &addr, data, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST);
    }

    return 0;
}

static int generate_raw_file_uyvy_10b(vx_image copy_image, int w, int h, const char* filename, int offset)
{
    int numbytes = w * h * 4;
    vx_rectangle_t rect             = { 0, 0, w, h };
    vx_imagepatch_addressing_t addr = VX_IMAGEPATCH_ADDR_INIT;
    int i, j;

#if 1
				  /* U Y V Y */
    uint64_t color_map_uyvy[8] = {0x020003ff020003ff, // white
				  0x03ff03bf000003bf, // yellow
				  0x0000033f03ff033f, // blue
				  0x0000023f0000023f, // green
				  0x03ff01c003ff01c0, // cyan
				  0x03ff010000000100, // red
				  0x0000004003ff0040, // blue
				  0x0200000002000000}; // black
#else
    uint64_t color_map_uyvy[8] = {//0x0000010102020303, // white
				  0x00450167028903ab, // white
				  0x0123456789abcdef, // yellow
				  0x0123456789abcdef, // blue
				  0x0123456789abcdef, // green
				  0x0123456789abcdef, // cyan
				  0x0123456789abcdef, // red
				  0x0123456789abcdef, // blue
				  0x0123456789abcdef}; // black
#endif

    addr.dim_x = w;
    addr.dim_y = h;
    addr.stride_x = 4;     /* bpp */
    addr.stride_y = w * 4;; /* stride */

    data = ct_alloc_mem(numbytes);
    if (data != NULL) {
        uint64_t* buf = data;

        memset(data, 0, numbytes);

        // generate pattern
        for (j = 0; j < h; j++) {
            for (i = 0; i < w / 2; i++) {
                *buf = color_map_uyvy[i / (w / 8 / 2)];
                buf++;
            }
        }

        vxCopyImagePatch(copy_image, &rect, 0, &addr, data, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST);
    }

    return 0;
}

static int rolling_raw_file_uyvy_10b(vx_image copy_image, int w, int h, const char* filename, int offset, int counter)
{
    vx_rectangle_t rect             = { 0, h * counter, w, h * (counter + 1)};
    vx_imagepatch_addressing_t addr = VX_IMAGEPATCH_ADDR_INIT;
    int i, j;

    addr.dim_x = w;
    addr.dim_y = h;
    addr.stride_x = 4;     /* bpp */
    addr.stride_y = w * 4; /* stride */

    if (data != NULL) {
        uint64_t* buf = (uint64_t*)((uint8_t *)data + w * h * 4 * counter);

        // invert pattern in next rectangle
        for (j = 0; j < h; j++) {
            for (i = 0; i < w / 2; i++) {
                *buf = ~(*buf) & 0x03ff03ff03ff03ff;
                buf++;
            }
        }

        vxCopyImagePatch(copy_image, &rect, 0, &addr, data, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST);
    }

    return 0;
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

static void VX_CALLBACK tivxTask_csitx(void *app_var)
{
    vx_node csitx_node = 0;
    vx_image tx_frame_array_item = 0;
    vx_object_array tx_frame = 0;
    vx_user_data_object csitx_config;
    tivx_csitx_params_t local_csitx_config;
    uint32_t buf_id, loop_id, loopCnt;
    vx_graph_parameter_queue_params_t csitx_graph_parameters_queue_params_list[1];
    vx_int32 i, j;
    vx_imagepatch_addressing_t addr;
    uint16_t *ptr = NULL;
    char filename[MAX_ABS_FILENAME];

    vx_graph csitx_graph = (vx_graph)app_var;

    /* allocate Input and Output refs*/
    ASSERT_VX_OBJECT(tx_frame = vxCreateObjectArray(context, (vx_reference)image, NUM_CHANNELS), VX_TYPE_OBJECT_ARRAY);
    ASSERT_VX_OBJECT(tx_frame_array_item = (vx_image) vxGetObjectArrayItem(tx_frame, 0), VX_TYPE_IMAGE);

    /* CSITX Config initialization */
    tivx_csitx_params_init(&local_csitx_config);
    local_csitx_config.numInst                          = 1U;
    local_csitx_config.numCh                            = NUM_CHANNELS;
    local_csitx_config.instId[0U]                       = CSITX_INST_ID;
    local_csitx_config.instCfg[0U].rxCompEnable         = (uint32_t)vx_true_e;
    local_csitx_config.instCfg[0U].rxv1p3MapEnable      = (uint32_t)vx_true_e;
    local_csitx_config.instCfg[0U].laneBandSpeed        = TIVX_CSITX_LANE_BAND_SPEED_390_TO_450_MBPS;
    local_csitx_config.instCfg[0U].numDataLanes         = 4U;
    for (loopCnt = 0U; loopCnt < local_csitx_config.instCfg[0U].numDataLanes; loopCnt++) {
        local_csitx_config.instCfg[0U].lanePolarityCtrl[loopCnt] = 0u;
    }
    for (loopCnt = 0U; loopCnt < NUM_CHANNELS; loopCnt++) {
        local_csitx_config.chVcNum[loopCnt]   = loopCnt;
        local_csitx_config.chInstMap[loopCnt] = CSITX_INST_ID;
    }

    ASSERT_VX_OBJECT(csitx_config = vxCreateUserDataObject(context, "tivx_csitx_params_t", sizeof(tivx_csitx_params_t), &local_csitx_config), (enum vx_type_e)VX_TYPE_USER_DATA_OBJECT);
    ASSERT_VX_OBJECT(csitx_node = tivxCsitxNode(csitx_graph, csitx_config, tx_frame), VX_TYPE_NODE);

    VX_CALL(vxSetNodeTarget(csitx_node, VX_TARGET_STRING, TIVX_TARGET_CSITX));

    /* input @ node index 0, becomes csitx_graph parameter 1 */
    add_graph_parameter_by_node_index(csitx_graph, csitx_node, 1);

    /* set csitx_graph schedule config such that csitx_graph parameter @ index 0 and 1 are enqueuable */
    csitx_graph_parameters_queue_params_list[0].graph_parameter_index = 0;
    csitx_graph_parameters_queue_params_list[0].refs_list_size = 1;
    csitx_graph_parameters_queue_params_list[0].refs_list = (vx_reference*)&tx_frame;

    /* Schedule mode auto is used, here we dont need to call vxScheduleGraph
     * Graph gets scheduled automatically as refs are enqueued to it */
    vxSetGraphScheduleConfig(csitx_graph,
                             VX_GRAPH_SCHEDULE_MODE_QUEUE_AUTO, 1, csitx_graph_parameters_queue_params_list);

    ASSERT_EQ_VX_STATUS(VX_SUCCESS, vxVerifyGraph(csitx_graph));

    /* Now enqueue a buffer to trigger csitx_graph scheduling */
    vxGraphParameterEnqueueReadyRef(csitx_graph, 0, (vx_reference*)&tx_frame, 1);

    snprintf(filename, MAX_ABS_FILENAME, "%s", "video.uyvy");

    if (0)
        generate_raw_file_uyvy(tx_frame_array_item, width, height, filename, 0);
    if (1)
        generate_raw_file_uyvy_10b(tx_frame_array_item, width, height, filename, 0);

    /* wait for csitx_graph instances to complete, schedule again */
    for (loop_id = 0; loop_id < loop_cnt; loop_id++)
    {
        uint32_t num_refs;
        vx_object_array transmitted_frames = NULL;

        /* Get tramsnitted frame reference, waits until a reference is available */
        vxGraphParameterDequeueDoneRef(csitx_graph, 0, (vx_reference*)&transmitted_frames, 1, &num_refs);

        // invert
        if (0)
            rolling_raw_file_uyvy(tx_frame_array_item, width, height / 100, filename, 0, loop_id % 100);
        if (1)
            rolling_raw_file_uyvy_10b(tx_frame_array_item, width, height / 100, filename, 0, loop_id % 100);

        vxGraphParameterEnqueueReadyRef(csitx_graph, 0, (vx_reference*)&transmitted_frames, 1);

        tivxTaskWaitMsecs(33); // 30FPS
    }
    /* ensure all csitx_graph processing is complete */
    vxWaitGraph(csitx_graph);

    VX_CALL(vxReleaseNode(&csitx_node));
    VX_CALL(vxReleaseObjectArray(&tx_frame));
    VX_CALL(vxReleaseImage(&tx_frame_array_item));
    VX_CALL(vxReleaseUserDataObject(&csitx_config));

    /*Signal the completion of csitx graph processing*/
    tivxEventPost(eventHandle_TxFinished);
}

TEST_WITH_ARG(tivxHwaCsitxYUV10, testCsitxYUV10loopback, Arg, PARAMETERS)
{
    vx_graph csitx_graph = 0;
    tivx_task_create_params_t taskParams_csitx;
    tivx_task taskHandle_csitx;

    context = context_->vx_context_;

    if (vx_true_e == tivxIsTargetEnabled(TIVX_TARGET_CSITX))
    {
        loop_cnt = arg_->loopCount;
        width = arg_->Width;
        height = arg_->Height;

        tivxHwaLoadKernels(context);
        CT_RegisterForGarbageCollection(context, ct_teardown_hwa_kernels, CT_GC_OBJECT);

        tivx_clr_debug_zone(VX_ZONE_INFO);

        ASSERT_VX_OBJECT(csitx_graph = vxCreateGraph(context), VX_TYPE_GRAPH);

//        ASSERT_VX_OBJECT(image = vxCreateImage(context, width, height, VX_DF_IMAGE_YUYV), VX_TYPE_IMAGE);
//        ASSERT_VX_OBJECT(image = vxCreateImage(context, width, height, VX_DF_IMAGE_U8), VX_TYPE_IMAGE);
        ASSERT_VX_OBJECT(image = vxCreateImage(context, width, height, VX_DF_IMAGE_U32), VX_TYPE_IMAGE); // YUV10
//        ASSERT_VX_OBJECT(image = vxCreateImage(context, width, height, VX_DF_IMAGE_UYVY), VX_TYPE_IMAGE);
//        ASSERT_VX_OBJECT(image = vxCreateImage(context, width, height, VX_DF_IMAGE_RGBX), VX_TYPE_IMAGE);

        rect.start_x = 0;
        rect.start_y = 0;
        rect.end_x = width;
        rect.end_y = height;

        // Setting up task params for csitx_task
        tivxTaskSetDefaultCreateParams(&taskParams_csitx);
        taskParams_csitx.task_main = &tivxTask_csitx;
        taskParams_csitx.app_var = csitx_graph;
        taskParams_csitx.stack_ptr = NULL;
        taskParams_csitx.stack_size = TIVX_TARGET_DEFAULT_STACK_SIZE;
        taskParams_csitx.core_affinity = TIVX_TASK_AFFINITY_ANY;
        taskParams_csitx.priority = TIVX_TARGET_DEFAULT_TASK_PRIORITY1;
#if 0
        tivxExportGraphToDot(csitx_graph, ".", "csitx_graph");
#endif
        //Create events for Sync
        ASSERT_EQ_VX_STATUS(VX_SUCCESS, tivxEventCreate(&eventHandle_TxFinished));
        //Create CsitxYUV10 Tasks
        ASSERT_EQ_VX_STATUS(VX_SUCCESS, tivxTaskCreate(&taskHandle_csitx, &taskParams_csitx));
        //Wait for CSITX Graph Processing to complete
        tivxEventWait(eventHandle_TxFinished, TIVX_EVENT_TIMEOUT_WAIT_FOREVER);

        // finished, release resources
        VX_CALL(vxReleaseImage(&image));
        VX_CALL(vxReleaseGraph(&csitx_graph));
        ASSERT_EQ_VX_STATUS(VX_SUCCESS, tivxEventDelete(&eventHandle_TxFinished));
        ASSERT_EQ_VX_STATUS(VX_SUCCESS, tivxTaskDelete(&taskHandle_csitx));

        tivxHwaUnLoadKernels(context);
        tivx_clr_debug_zone(VX_ZONE_INFO);
    }
}

TESTCASE_TESTS(tivxHwaCsitxYUV10,
               testCsitxYUV10loopback)
