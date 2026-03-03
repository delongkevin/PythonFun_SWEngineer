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
#ifndef _APP_SINGLE_CAM_UTIL_H_
#define _APP_SINGLE_CAM_UTIL_H_

#include <TI/tivx.h>
#include <TI/tivx_task.h>
#include <tivx_utils_graph_perf.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#ifdef x86_64
#include <sys/stat.h>
#endif

#include <iss_sensors.h>
#include <iss_sensor_if.h>

#include <utils/perf_stats/include/app_perf_stats.h>

#define APP_MAX_FILE_PATH           (256u)
#define APP_ASSERT(x)               assert((x))
#define APP_ASSERT_VALID_REF(ref)   (APP_ASSERT(vxGetStatus((vx_reference)(ref))==VX_SUCCESS));

#define VISS_TEST_DATA_PATH_DEF  "./"
#define VISS_TEST_DATA_IMAGE  "input1.raw"
#define VISS_TEST_DATA_OUT  "output1.yuv"

vx_int32 read_input_image(char * file_name, tivx_raw_image raw_image);

#define MAX_NUM_BUF  8
#define NUM_BUFS 3u

typedef struct {

    /* config options */
    uint32_t width_in;
    uint32_t height_in;
    uint32_t width_out;
    uint32_t height_out;
    uint8_t img_format1;
    uint8_t img_format2;
    uint32_t cam_dcc_id;

    vx_node capture_node;
    uint32_t num_cap_buf;

    /* OpenVX references */
    vx_context context;
    vx_graph graph;
    vx_node  node_viss;
    vx_node  node_rc;
    tivx_display_params_t display_params;
    vx_node displayNode;
    tivx_raw_image raw;
    vx_image y12;
    vx_image uv12_c1;
    vx_image y8_r8_c2;
    vx_image uv8_g8_c3;
    vx_image s8_b8_c4;
    vx_user_data_object configuration;
    tivx_vpac_cuc_isp_params_t viss_params;
    vx_user_data_object capture_stats;
    vx_user_data_object display_param_obj;

    vx_object_array cap_frames[MAX_NUM_BUF];
    char *sensor_name;
    vx_uint8 sensor_sel;
    vx_uint32 num_frames_to_run;

    uint32_t is_interactive;
    tivx_task task;
    uint32_t stop_task;
    uint32_t stop_task_done;

    vx_bool scaler_enable;
    vx_image scaler_out_img;
    vx_node scalerNode;
    vx_user_data_object sc_coeff_obj;

    app_perf_point_t total_perf;

} AppObj;

extern AppObj gAppObj;

#ifdef A72
#define _APP_DEBUG_
#endif

#ifdef _APP_DEBUG_
int save_debug_images(AppObj *obj, char* dump_filename);
vx_int32 write_output_image_fp(FILE * fp, vx_image out_image);
vx_int32 write_output_image_nv12_8bit(char * file_name, vx_image out_nv12);
#endif //_APP_DEBUG_

vx_status app_parse_cmd_line_args(AppObj *obj, int argc, char *argv[]);
vx_status app_init(AppObj *obj);
vx_status app_deinit(AppObj *obj);
vx_status app_create_graph(AppObj *obj);
vx_status app_run_graph(AppObj *obj);
vx_status app_delete_graph(AppObj *obj);

void add_graph_parameter_by_node_index(vx_graph graph, vx_node node, vx_uint32 node_parameter_index);

/*Define this macro to enable prints*/
#define APP_DEBUG_SINGLE_CAM

#ifdef APP_DEBUG_SINGLE_CAM
#define APP_PRINTF(f_, ...) printf((f_), ##__VA_ARGS__)
#else
#define APP_PRINTF(f_, ...)
#endif

vx_int32 write_output_image_raw(char * file_name, tivx_raw_image raw_image);


#endif //_APP_SINGLE_CAM_UTIL_H_
