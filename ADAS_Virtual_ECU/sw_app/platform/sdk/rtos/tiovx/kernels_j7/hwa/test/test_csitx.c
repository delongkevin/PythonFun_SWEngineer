/*******************************************************************************
 * test_csitx.c
 *
 * Sample application for CSITX UYVY pattern output demonstration
 *
 * Copyright (c) 2020 Cogent Embedded Inc.
 * ALL RIGHTS RESERVED.
 *
 * The source code contained or described herein and all documents related to the
 * source code("Software") or their modified versions are owned by
 * Cogent Embedded Inc. or its affiliates.
 *
 * No part of the Software may be used, copied, reproduced, modified, published,
 * uploaded, posted, transmitted, distributed, or disclosed in any way without
 * prior express written permission from Cogent Embedded Inc.
 *
 * Cogent Embedded Inc. grants a nonexclusive, non-transferable, royalty-free
 * license to use the Software to Licensee without the right to sublicense.
 * Licensee agrees not to distribute the Software to any third-party without
 * the prior written permission of Cogent Embedded Inc.
 *
 * Unless otherwise agreed by Cogent Embedded Inc. in writing, you may not remove
 * or alter this notice or any other notice embedded in Software in any way.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
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

TESTCASE(tivxHwaCsitx, CT_VXContext, ct_setup_vx_context, 0)

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
    CT_EXPAND(nextmacro(testArgName "/Width=1920", __VA_ARGS__, 1920))
#define ADD_HEIGHT(testArgName, nextmacro, ...) \
    CT_EXPAND(nextmacro(testArgName "/Height=1080", __VA_ARGS__, 1080))
#define ADD_LOOPCOUNT(testArgName, nextmacro, ...) \
    CT_EXPAND(nextmacro(testArgName "/loopCount=100", __VA_ARGS__, 100))

#define PARAMETERS \
    CT_GENERATE_PARAMETERS("Csitx", ADD_WIDTH, ADD_HEIGHT, ADD_LOOPCOUNT ,ARG)

#if 0
static int load_from_raw_file(vx_image copy_image, int w, int h, const char* filename, int offset)
{
    void* data;
    FILE* fp;
    int dataread;
    int numbytes = w * h * 4;;
    char file[MAX_ABS_FILENAME + 1];
    vx_rectangle_t rect             = { 0, 0, w, h };
    vx_imagepatch_addressing_t addr = VX_IMAGEPATCH_ADDR_INIT;
    int ret = 0;

    addr.dim_x = w;
    addr.dim_y = h;
    addr.stride_x = 4;;     /* bpp */
    addr.stride_y = w * 4;; /* stride */

    snprintf(file, MAX_ABS_FILENAME + 1, "%s/%s", ct_get_test_file_path(), filename);
    fp = fopen(file, "rb");
    if(!fp) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    data = ct_alloc_mem(numbytes);
    if (data != NULL) {
//        memset(data, 0, numbytes);
        fseek(fp, offset, SEEK_CUR);
        dataread = fread(data, 1, numbytes - offset, fp);
        if (dataread != (numbytes - offset)) {
            printf("Error: file_size != w * h\n");
            ret = -1;
        }

        vxCopyImagePatch(copy_image, &rect, 0, &addr, data, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST);
    }

    ct_free_mem(data);
    fclose(fp);

    return ret;
}
#else

void* data;

static int generate_raw_file(vx_image copy_image, int w, int h, const char* filename, int offset)
{
//    void* data;
    int numbytes = w * h * 4;;
    vx_rectangle_t rect             = { 0, 0, w, h };
    vx_imagepatch_addressing_t addr = VX_IMAGEPATCH_ADDR_INIT;
    int i, j;

    uint32_t color_map_rgbx[8] = {0xffffffff, // white
				  0xffffff00, // yellow
				  0xff00ffff, // blue
				  0xff00ff00, // green
				  0xffff00ff, // cyan
				  0xffff0000, // red
				  0xff0000ff, // blue
				  0xff000000}; // black

    addr.dim_x = w;
    addr.dim_y = h;
    addr.stride_x = 4;;     /* bpp */
    addr.stride_y = w * 4;; /* stride */

    data = ct_alloc_mem(numbytes);
    if (data != NULL) {
        uint32_t* buf = data;

        memset(data, 0, numbytes);

        // generate pattern
        for (j = 0; j < h; j++) {
            for (i = 0; i < w; i++) {
                *buf = color_map_rgbx[i / (w / 8)];
                buf++;
            }
        }

        vxCopyImagePatch(copy_image, &rect, 0, &addr, data, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST);
    }

//    ct_free_mem(data);

    return 0;
}

static int rolling_raw_file(vx_image copy_image, int w, int h, const char* filename, int offset, int counter)
{
    vx_rectangle_t rect             = { 0, h * counter, w, h * (counter + 1)};
    vx_imagepatch_addressing_t addr = VX_IMAGEPATCH_ADDR_INIT;
    int i, j;

    uint32_t color_map_rgbx[8] = {0xffffffff, // white
				  0xffffff00, // yellow
				  0xff00ffff, // blue
				  0xff00ff00, // green
				  0xffff00ff, // cyan
				  0xffff0000, // red
				  0xff0000ff, // blue
				  0xff000000}; // black

    addr.dim_x = w;
    addr.dim_y = h;
    addr.stride_x = 4;;     /* bpp */
    addr.stride_y = w * 4;; /* stride */

    if (data != NULL) {
        uint32_t* buf = (uint32_t*)((uint8_t *)data + w * h * 4 * counter);

        // invert pattern in next rectangle
        for (j = 0; j < h; j++) {
            for (i = 0; i < w; i++) {
                *buf = ~(*buf);
                buf++;
            }
        }

#if 0
        // restore pattern in prev rectangle
        if (counter) {
            rect.start_y = h * (counter - 1);
            addr.dim_y = h*2;
            buf = (uint32_t*)((uint8_t*)data + w * h * 4 * (counter - 1));
            for (j = 0; j < h; j++) {
                for (i = 0; i < w; i++) {
                    *buf = color_map_rgbx[i / (w / 8)];
                    buf++;
                }
            }
        }
#endif

        vxCopyImagePatch(copy_image, &rect, 0, &addr, data, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST);
    }

    return 0;
}
#endif

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

    snprintf(filename, MAX_ABS_FILENAME, "%s", "video.rgbx");
#if 0
    load_from_raw_file(tx_frame_array_item, width, height, filename, 0);
#else
    generate_raw_file(tx_frame_array_item, width, height, filename, 0);
#endif

    /* wait for csitx_graph instances to complete, schedule again */
    for (loop_id = 0; loop_id < loop_cnt; loop_id++)
    {
        uint32_t num_refs;
        vx_object_array transmitted_frames = NULL;

        /* Get tramsnitted frame reference, waits until a reference is available */
        vxGraphParameterDequeueDoneRef(csitx_graph, 0, (vx_reference*)&transmitted_frames, 1, &num_refs);
#if 1
        // invert
        rolling_raw_file(tx_frame_array_item, width, height / 120, filename, 0, loop_id % 120);
#endif
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

TEST_WITH_ARG(tivxHwaCsitx, testCsitxloopback, Arg, PARAMETERS)
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
//        ASSERT_VX_OBJECT(image = vxCreateImage(context, width, height, VX_DF_IMAGE_UYVY), VX_TYPE_IMAGE);
        ASSERT_VX_OBJECT(image = vxCreateImage(context, width, height, VX_DF_IMAGE_RGBX), VX_TYPE_IMAGE);

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
        //Create Csitx Tasks
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

TESTCASE_TESTS(tivxHwaCsitx,
               testCsitxloopback)
