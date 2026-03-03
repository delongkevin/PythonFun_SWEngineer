/*
 *
 * Copyright (c) 2020 Texas Instruments Incorporated
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
#include <signal.h>

#include <utils/draw2d/include/draw2d.h>
#include <utils/perf_stats/include/app_perf_stats.h>
#include <utils/console_io/include/app_get.h>
#include <utils/grpx/include/app_grpx.h>
#include <VX/vx_khr_pipelining.h>
#include <getopt.h>
#include <host/tivx_sample_kernels_priv.h>
#include <TI/tivx_sample_kernels.h>
#include <TI/tivx_sample_nodes.h>

#include "app_common.h"
#include "app_sensor_module.h"
#include "app_capture_module.h"
#include "app_viss_module.h"
#include "app_img_mosaic_module.h"
#include "app_display_module.h"
#include "app_csitx_module.h"
#include <TI/j7_imaging_aewb.h>
#include <png.h>

#include <utils/iss/include/app_iss.h>
#include <utils/ipc/include/app_ipc.h>
#include <utils/remote_service/include/app_remote_service.h>

#include "../../edt_server/edt_types.h"

#define APP_BUFFER_Q_DEPTH   (4)
#define APP_PIPELINE_DEPTH   (7)

#define BIT(x) (1<<(x))

typedef struct {

    SensorObj     sensorObj;
    CaptureObj    captureObj;
    VISSObj       vissObj;
    ImgMosaicObj  imgMosaicObj;
    DisplayObj    displayObj;
    CsiTxObj      csitxObj;

    vx_char output_file_path[APP_MAX_FILE_PATH];

    /* OpenVX references */
    vx_context context;
    vx_graph   graph;

    vx_node gl_mosaic_node;
    vx_int32   en_csitx;

    vx_uint32 is_interactive;

    vx_uint32 num_frames_to_write;
    vx_uint32 num_frames_to_skip;

    tivx_task task;
    vx_uint32 stop_task;
    vx_uint32 stop_task_done;

    app_perf_point_t total_perf;
    app_perf_point_t fileio_perf;
    app_perf_point_t draw_perf;

    int32_t pipeline;

    int32_t enqueueCnt;
    int32_t dequeueCnt;

    int32_t write_file;

    vx_int32 en_out_video_write;
    FILE *video_files[4];
    vx_uint32 frames_written;

} AppObj;

AppObj gAppObj;

vx_status app_parse_cmd_line_args(AppObj *obj, vx_int32 argc, vx_char *argv[]);
static vx_status app_init(AppObj *obj);
static void app_deinit(AppObj *obj);
static vx_status app_create_graph(AppObj *obj);
static vx_status app_verify_graph(AppObj *obj);
static vx_status app_run_graph(AppObj *obj);
static vx_status app_run_graph_interactive(AppObj *obj);
static void app_delete_graph(AppObj *obj);
static void app_default_param_set(AppObj *obj);
static void app_update_param_set(AppObj *obj);
static void app_pipeline_params_defaults(AppObj *obj);
static void add_graph_parameter_by_node_index(vx_graph graph, vx_node node, vx_uint32 node_parameter_index);
static vx_int32 calc_grid_size(vx_uint32 ch);
static void set_img_mosaic_params(ImgMosaicObj *imgMosaicObj, vx_uint32 in_width, vx_uint32 in_height, vx_int32 numCh);
void nv12_to_rgb(uint8_t* y_pixel, uint8_t* uv_pixel, uint8_t* rgb_data, uint32_t width, uint32_t height, uint32_t stride);

int32_t get_register_via_iss(uint32_t channel_id, uint32_t reg_addr, uint32_t *value)
{
	int32_t status = -1;
	uint8_t  cmdPrm[CMD_PARAM_SIZE];
	uint8_t * ptr8 = (uint8_t * )cmdPrm;
	char dummy_name[ISS_SENSORS_MAX_NAME] = "dummy";
	IMAGE_SENSOR_CTRLCMD ctrlCmd = IMAGE_SENSOR_CTRLCMD_READ_SENSOR_REG;

	memcpy(ptr8, dummy_name, ISS_SENSORS_MAX_NAME);
	ptr8 += ISS_SENSORS_MAX_NAME;

	memcpy(ptr8, &channel_id, sizeof(uint32_t));
	ptr8 += sizeof(uint32_t);

	memcpy(ptr8, &ctrlCmd, sizeof(IMAGE_SENSOR_CTRLCMD));
	ptr8 += sizeof(IMAGE_SENSOR_CTRLCMD);
	memcpy(ptr8, &reg_addr, sizeof(uint32_t));
	ptr8 += sizeof(uint32_t);

	status = appRemoteServiceRun(APP_IPC_CPU_MCU2_0,
				     IMAGE_SENSOR_REMOTE_SERVICE_NAME,
				     IM_SENSOR_CMD_CTL,
				     (void*)cmdPrm,
				     CMD_PARAM_SIZE,
				     0);

	memcpy(value, ptr8, sizeof(uint32_t));

	return status;
}

int32_t set_register_via_iss(uint32_t channel_id, uint32_t reg_addr, uint32_t value)
{
	int32_t status = -1;
	uint8_t  cmdPrm[CMD_PARAM_SIZE];
	uint8_t * ptr8 = (uint8_t * )cmdPrm;
	char dummy_name[ISS_SENSORS_MAX_NAME] = "dummy";
	IMAGE_SENSOR_CTRLCMD ctrlCmd = IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_REG;

	memcpy(ptr8, dummy_name, ISS_SENSORS_MAX_NAME);
	ptr8 += ISS_SENSORS_MAX_NAME;

	memcpy(ptr8, &channel_id, sizeof(uint32_t));
	ptr8 += sizeof(uint32_t);

	memcpy(ptr8, &ctrlCmd, sizeof(IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_REG));
	ptr8 += sizeof(IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_REG);
	memcpy(ptr8, &reg_addr, sizeof(uint32_t));
	ptr8 += sizeof(uint32_t);
	memcpy(ptr8, &value, sizeof(uint32_t));
	ptr8 += sizeof(uint32_t);

	status = appRemoteServiceRun(APP_IPC_CPU_MCU2_0,
				     IMAGE_SENSOR_REMOTE_SERVICE_NAME,
				     IM_SENSOR_CMD_CTL,
				     (void*)cmdPrm,
				     CMD_PARAM_SIZE,
				     0);

	return status;
}


void sigint_handler(int signum)
{
    if (gAppObj.stop_task)
        return;

    gAppObj.stop_task = 1;
}

static char menu[] = {
    "\n"
    "\n ========================="
    "\n Demo : Camera Demo"
    "\n ========================="
    "\n"
    "\n s: Save CSIx, VISS and LDC outputs"
    "\n"
    "\n p: Print performance statistics"
    "\n"
    "\n x: Exit"
    "\n"
    "\n Enter Choice: "
};

static void app_run_task(void *app_var)
{
    AppObj *obj = (AppObj *)app_var;

    while(!obj->stop_task)
    {
        app_run_graph(obj);
    }
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
        printf("app_tidl: ERROR: Unable to create task\n");
    }
    else
    {
        appPerfStatsResetAll();
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
                    appPerfPointPrint(&obj->fileio_perf);
                    appPerfPointPrint(&obj->total_perf);
                    printf("\n");
                    appPerfPointPrintFPS(&obj->total_perf);
                    printf("\n");
                    break;
                case 'e':
                    perf_arr[0] = &obj->total_perf;
                    fp = appPerfStatsExportOpenFile(".", "app_multi_cam_datasheet");
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
                case 's':
                    obj->write_file = 1;
                    break;
                case 'x':
                    obj->stop_task = 1;
                    done = 1;
                    break;
            }
        }
        app_run_task_delete(obj);
    }
    return status;
}

static void app_parse_cfg_file(AppObj *obj, vx_char *cfg_file_name)
{
    FILE *fp = fopen(cfg_file_name, "r");
    vx_char line_str[1024];
    vx_char *token;

    if(fp==NULL)
    {
        printf("# ERROR: Unable to open config file [%s]\n", cfg_file_name);
        exit(0);
    }

    while(fgets(line_str, sizeof(line_str), fp)!=NULL)
    {
        vx_char s[]=" \t";

        if (strchr(line_str, '#'))
        {
            continue;
        }

        /* get the first token */
        token = strtok(line_str, s);
        if(token != NULL)
        {
          if(strcmp(token, "sensor_index")==0)
          {
              token = strtok(NULL, s);
              if(token != NULL)
              {
                obj->sensorObj.sensor_index = atoi(token);
              }
          }
          else
          if(strcmp(token, "sensor_init")==0)
          {
              token = strtok(NULL, s);
              if(token != NULL)
              {
                obj->sensorObj.sensor_init = atoi(token);
                if(obj->sensorObj.sensor_init > 1)
                  obj->sensorObj.sensor_init = 1;
              }
          }
          else
          if(strcmp(token, "mask_cameras_enabled")==0)
          {
              token = strtok(NULL, s);
              if(token != NULL)
              {
                    obj->sensorObj.mask_cameras_enabled = (int)strtol(token, NULL, 0);

                    if(obj->sensorObj.mask_cameras_enabled > 0xff)
                    {
                        printf("Invalid Mask %d. \n", obj->sensorObj.mask_cameras_enabled);
                        exit(1);
                    }
                    obj->sensorObj.num_cameras_enabled =
                        __builtin_popcount(obj->sensorObj.mask_cameras_enabled);
                    printf("mask_cameras_enabled 0x%x\nnum_cameras_enabled 0x%x\n",
                           obj->sensorObj.mask_cameras_enabled,
                           obj->sensorObj.num_cameras_enabled);
              }
          }
          else
          if(strcmp(token, "tpg_mask")==0)
          {
              token = strtok(NULL, s);
              if(token != NULL)
              {
                    obj->sensorObj.tpg_mask = (int)strtol(token, NULL, 0);
              }
          }
          else
          if(strcmp(token, "enable_error_detection")==0)
          {
              token = strtok(NULL, s);
              if(token != NULL)
              {
                obj->captureObj.enable_error_detection = atoi(token);
              }
          }
          else
          if(strcmp(token, "en_csitx")==0)
          {
              token = strtok(NULL, s);
              if(token != NULL)
              {
                obj->en_csitx = atoi(token);
                if(obj->en_csitx > 1)
                  obj->en_csitx = 1;
              }
          }
          else
          if(strcmp(token, "en_out_capture_write")==0)
          {
              token = strtok(NULL, s);
              if(token != NULL)
              {
                obj->captureObj.en_out_capture_write = atoi(token);
                if(obj->captureObj.en_out_capture_write > 1)
                  obj->captureObj.en_out_capture_write = 1;
              }
          }
          else
          if(strcmp(token, "en_out_viss_write")==0)
          {
              token = strtok(NULL, s);
              if(token != NULL)
              {
                obj->vissObj.en_out_viss_write = atoi(token);
                if(obj->vissObj.en_out_viss_write > 1)
                  obj->vissObj.en_out_viss_write = 1;
              }
          }
          else
          if(strcmp(token, "output_file_path")==0)
          {
              token = strtok(NULL, s);
              if(token != NULL)
              {
                token[strlen(token)-1]=0;
                strcpy(obj->captureObj.output_file_path, token);
                strcpy(obj->vissObj.output_file_path, token);
                strcpy(obj->output_file_path, token);
              }
          }
          else
          if(strcmp(token, "is_interactive")==0)
          {
              token = strtok(NULL, s);
              if(token != NULL)
              {
                token[strlen(token)-1]=0;
                obj->is_interactive = atoi(token);
                if(obj->is_interactive > 1)
                  obj->is_interactive = 1;
              }
              obj->sensorObj.is_interactive = obj->is_interactive;
          }
          else
          if(strcmp(token, "num_frames_to_write")==0)
          {
              token = strtok(NULL, s);
              if(token != NULL)
              {
                  token[strlen(token)-1]=0;
                  obj->num_frames_to_write = atoi(token);
              }
          }
          else
          if(strcmp(token, "num_frames_to_skip")==0)
          {
              token = strtok(NULL, s);
              if(token != NULL)
              {
                  token[strlen(token)-1]=0;
                  obj->num_frames_to_skip = atoi(token);
              }
          }
          else
          if(strcmp(token, "en_out_video_write")==0)
          {
              token = strtok(NULL, s);
              if(token != NULL)
              {
                obj->en_out_video_write = atoi(token);
              }
          }
        }
    }

    fclose(fp);

}

vx_status app_parse_cmd_line_args(AppObj *obj, int argc, char *argv[])
{
    const struct option long_options[] = {
        { "help", no_argument, NULL, 'h' },
        { "sensor_index", required_argument, NULL, 'i' },
        { "sensor_init", required_argument, NULL, 'I' },
        { "mask_cameras", required_argument, NULL, 'm' },
        { "tpg_mask", required_argument, NULL, 't' },
        { "cfg", required_argument, NULL, 'c' },
        { NULL, 0, NULL, 0 }
    };

    int opt;
    int option_index;
    char *config_file = NULL;

    if (argc > 1)
    {
        obj->is_interactive = 0;
        obj->sensorObj.is_interactive = 0;
    }

    while ((opt = getopt_long_only(argc, argv, "", long_options,
                              &option_index)) != -1)
    {
        switch(opt)
        {
            case 'm': {
                /* printf("mask = %s\n", optarg); */
                obj->sensorObj.mask_cameras_enabled = (int)strtol(optarg, NULL, 0);
                if(obj->sensorObj.mask_cameras_enabled > 0xff)
                {
                    printf("Invalid Mask %d. \n", obj->sensorObj.mask_cameras_enabled);
                    return VX_FAILURE;
                }
                obj->sensorObj.num_cameras_enabled =
                    __builtin_popcount(obj->sensorObj.mask_cameras_enabled);
                printf("mask_cameras_enabled 0x%x\nnum_cameras_enabled 0x%x\n",
                       obj->sensorObj.mask_cameras_enabled,
                       obj->sensorObj.num_cameras_enabled);
                break;
            };
            case 'i': {
                /* printf("sensor_index = %s\n", optarg); */
                obj->sensorObj.sensor_index = (int)strtol(optarg, NULL, 0);
                printf("sensor_index = %d\n", obj->sensorObj.sensor_index);
                break;
            };
            case 'I': {
                obj->sensorObj.sensor_init = (int)strtol(optarg, NULL, 0);
                printf("sensor_init = %d\n", obj->sensorObj.sensor_init);
                break;
            };
            case 't': {
                /* printf("tpg_mask = %s\n", optarg); */
                obj->sensorObj.tpg_mask = (int)strtol(optarg, NULL, 0);
                printf("tpg_mask = 0x%x\n", obj->sensorObj.tpg_mask);
                break;
            };
            case 'c': {
                printf("config = %s\n", optarg);
                config_file = optarg;
                break;
            };
            case '?':
                printf("unknown option\n");
            case 'h':
            default: {
                printf(" !!! config file options always override command line options"
                       "\t--help                   - this message\n"
                       "\t--sensor_index           - IIS camera index\n"
                       "\t--sensor_init            - ISS camera init\n"
                       "\t--mask_cameras <mask>    - cameras mask (e.g. 0x0f)\n"
                       "\t--cfg <config>           - config file name\n"
                       "\t--tpg_mask <tpg_mask>      - test patter mask each is 1 byte (LE)"
                       "\t ");
                return VX_FAILURE;
            };
        };
    };

    if (config_file)
    {
        app_parse_cfg_file(obj, config_file);
    }

    return VX_SUCCESS;
}

vx_int32 app_multi_cam_main(vx_int32 argc, vx_char* argv[])
{
    vx_status status = VX_SUCCESS;

    struct sigaction act = {0};
    act.sa_handler = sigint_handler;
    sigaction(SIGINT, &act, NULL);

    AppObj *obj = &gAppObj;

    /*Optional parameter setting*/
    app_default_param_set(obj);

    if (VX_FAILURE == app_parse_cmd_line_args(obj, argc, argv))
    {
        exit(1);
    }

    /* Querry sensor parameters */
    app_querry_sensor(&obj->sensorObj);

    /*Update of parameters are config file read*/
    app_update_param_set(obj);

    status = app_init(obj);

    if(status == VX_SUCCESS)
    {
        APP_PRINTF("App Init Done! \n");

        status = app_create_graph(obj);

        if(status == VX_SUCCESS)
        {

            APP_PRINTF("App Create Graph Done! \n");
            status = app_verify_graph(obj);

            tivxExportGraphToDot(obj->graph, ".", "octo_cam_graph");
            if(status == VX_SUCCESS)
            {
                APP_PRINTF("App Verify Graph Done! \n");
                if(obj->is_interactive)
                {
                    app_run_graph_interactive(obj);
                }
                else
                {
                    app_run_graph(obj);
                }
            }
        }

        APP_PRINTF("App Run Graph Done! \n");
    }

    app_delete_graph(obj);

    APP_PRINTF("App Delete Graph Done! \n");

    app_deinit(obj);

    APP_PRINTF("App De-init Done! \n");

    return 0;
}

static vx_status app_init(AppObj *obj)
{
    vx_status status = VX_SUCCESS;

    /* Create OpenVx Context */
    obj->context = vxCreateContext();
    APP_ASSERT_VALID_REF(obj->context);
    APP_PRINTF("Creating context done!\n");

    tivxHwaLoadKernels(obj->context);
    tivxImagingLoadKernels(obj->context);
    tivxFileIOLoadKernels(obj->context);
    if (obj->en_csitx == 1)
    {
        tivxSampleLoadKernels(obj->context);
        tivxRegisterSampleTargetA72Kernels();
    }
    APP_PRINTF("Kernel loading done!\n");

    /* Initialize modules */

    if (obj->sensorObj.sensor_init == 1) {
        app_init_sensor(&obj->sensorObj, "sensor_obj");
        APP_PRINTF("Sensor init done!\n");
    }

    app_init_capture(obj->context, &obj->captureObj, &obj->sensorObj, "capture_obj", APP_BUFFER_Q_DEPTH);
    APP_PRINTF("Capture init done!\n");

    status = app_init_viss(obj->context, &obj->vissObj, &obj->sensorObj, "viss_obj");
    APP_PRINTF("VISS init done!\n");

    app_init_img_mosaic(obj->context, &obj->imgMosaicObj, "img_mosaic_obj", APP_BUFFER_Q_DEPTH);
    APP_PRINTF("Img Mosaic init done!\n");

    if (obj->en_csitx == 1)
    {
        app_init_csitx(obj->context, &obj->csitxObj, NULL, DISPLAY_WIDTH,
                       DISPLAY_HEIGHT, APP_BUFFER_Q_DEPTH);
    }
    else
    {
        app_init_display(obj->context, &obj->displayObj, "display_obj");
        APP_PRINTF("Display init done!\n");
    }

    appPerfPointSetName(&obj->total_perf , "TOTAL");
    appPerfPointSetName(&obj->fileio_perf, "FILEIO");

    if (obj->en_out_video_write)
    {
        for (int i = 0; i < 4; i++)
        {
            char name[128] = {};
            snprintf(name, 128, "/mnt/stream_%d.nv12", i);
            obj->video_files[i] = fopen(name, "wb");
        }

        obj->frames_written = 0;
    }
    return status;
}

static void app_deinit(AppObj *obj)
{
    if (obj->en_out_video_write)
    {
        FILE *meta = fopen("/mnt/metadata.json", "w");
        if (meta)
        {
            fprintf(meta, "{\n"
                    "\t\"tracks\": [\n"
                    "\t\t{\n");
            for (int i = 0; i < 4; i++)
            {
                fprintf(meta, "\t\t\t\"index\":\"%d\",\n"
                        "\t\t\t\"data\":\"stream_%d.nv12\",\n"
                        "\t\t\t\"frames\":\"%u\"\n",
                        i, i, obj->frames_written);
            }
            fprintf(meta, "\t\t}\n"
                    "\t]\n"
                    "}\n");
            fclose(meta);
        }

        for (int i = 0; i < 4; i++)
        {
            fclose(obj->video_files[i]);
        }
    }

    app_deinit_sensor(&obj->sensorObj);
    APP_PRINTF("Sensor deinit done!\n");

    app_deinit_capture(&obj->captureObj, APP_BUFFER_Q_DEPTH);
    APP_PRINTF("Capture deinit done!\n");

    app_deinit_viss(&obj->vissObj);
    APP_PRINTF("VISS deinit done!\n");

    app_deinit_img_mosaic(&obj->imgMosaicObj, APP_BUFFER_Q_DEPTH);
    APP_PRINTF("Img Mosaic deinit done!\n");

    app_deinit_display(&obj->displayObj);
    APP_PRINTF("Display deinit done!\n");

    if (obj->en_csitx == 1)
    {
        app_deinit_csitx(&obj->csitxObj, APP_BUFFER_Q_DEPTH);
        APP_PRINTF("CSITX deinit done!\n");
    }

    tivxHwaUnLoadKernels(obj->context);
    tivxImagingUnLoadKernels(obj->context);
    tivxFileIOUnLoadKernels(obj->context);
    APP_PRINTF("Kernels unload done!\n");

    vxReleaseContext(&obj->context);
    APP_PRINTF("Release context done!\n");
}


/* static void _int_signal(int signo) */
/* { */
/*     printf("signal received: %d\n", signo); */
/*     obj.stop_task = 1; */
/* } */

static void app_delete_graph(AppObj *obj)
{
    app_delete_capture(&obj->captureObj);
    APP_PRINTF("Capture delete done!\n");

    app_delete_viss(&obj->vissObj);
    APP_PRINTF("VISS delete done!\n");

    app_delete_img_mosaic(&obj->imgMosaicObj);
    APP_PRINTF("Img Mosaic delete done!\n");

    app_delete_display(&obj->displayObj);
    APP_PRINTF("Display delete done!\n");

    if (obj->en_csitx == 1)
    {
        if(obj->gl_mosaic_node != NULL)
        {
            vxReleaseNode(&obj->gl_mosaic_node);
        }
        app_delete_csitx(&obj->csitxObj);
        APP_PRINTF("CSITX delete done!\n");
    }

    vxReleaseGraph(&obj->graph);
    APP_PRINTF("Graph release done!\n");
}

static vx_status app_create_graph(AppObj *obj)
{
    vx_status status = VX_SUCCESS;
    vx_graph_parameter_queue_params_t graph_parameters_queue_params_list[2];
    vx_int32 graph_parameter_index;

    obj->graph = vxCreateGraph(obj->context);
    status = vxGetStatus((vx_reference)obj->graph);
    vxSetReferenceName((vx_reference)obj->graph, "app_multi_cam_graph");
    APP_PRINTF("Graph create done!\n");

    if(status == VX_SUCCESS)
    {
        status = app_create_graph_capture(obj->graph, &obj->captureObj);
        APP_PRINTF("Capture graph done!\n");
    }

    if(status == VX_SUCCESS)
    {
        status = app_create_graph_viss(obj->graph, &obj->vissObj,
                                       obj->captureObj.raw_image_arr[0]);
        APP_PRINTF("VISS graph done!\n");
    }

    if (status == VX_SUCCESS)
    {
        if (obj->en_csitx == 1)
        {
            tivx_opengl_mosaic_params_t params;
            vx_user_data_object param_obj;
            vx_image output;

            memset(&params, 0, sizeof(tivx_opengl_mosaic_params_t));
            params.renderType = TIVX_KERNEL_OPENGL_MOSAIC_TYPE_1x1;
            if (obj->sensorObj.num_cameras_enabled > 1)
            {
                params.renderType = TIVX_KERNEL_OPENGL_MOSAIC_TYPE_2x2;
            }

            output = (vx_image)vxGetObjectArrayItem(obj->csitxObj.input_img_arr[0], 0);

            param_obj = vxCreateUserDataObject(obj->context, "tivx_opengl_mosaic_params_t",
                                               sizeof(tivx_opengl_mosaic_params_t), &params);
            status = vxGetStatus((vx_reference) param_obj);
            if(status == VX_SUCCESS)
            {
                obj->gl_mosaic_node = tivxOpenglMosaicNode(obj->graph, param_obj,
                                                           obj->vissObj.output_arr,
                                                           output);
                status = vxGetStatus((vx_reference)obj->gl_mosaic_node);
            }
            if(status == VX_SUCCESS)
            {
                status = vxSetNodeTarget(obj->gl_mosaic_node, VX_TARGET_STRING, TIVX_TARGET_A72_0);
            }
            if(status == VX_SUCCESS)
            {
                vxSetReferenceName((vx_reference)obj->gl_mosaic_node, "gl_mosaic_node");
            }
            if(status == VX_SUCCESS)
            {
                status = app_create_graph_csitx(obj->graph, &obj->csitxObj, obj->csitxObj.input_img_arr[0]);
                APP_PRINTF("CSITX graph done!\n");
            }
        }
        else
        {
            obj->imgMosaicObj.input_arr[0] = obj->vissObj.output_arr;
            status = app_create_graph_img_mosaic(obj->graph, &obj->imgMosaicObj);
            APP_PRINTF("Img Mosaic graph done!\n");

            if(status == VX_SUCCESS)
            {
                vx_image output = (vx_image)vxGetObjectArrayItem(obj->imgMosaicObj.output_arr[0], 0);
                status = app_create_graph_display(obj->graph, &obj->displayObj, output);
                APP_PRINTF("Display graph done!\n");
            }
        }
    }

    if(status == VX_SUCCESS)
    {
        graph_parameter_index = 0;
        add_graph_parameter_by_node_index(obj->graph, obj->captureObj.node, 1);
        obj->captureObj.graph_parameter_index = graph_parameter_index;
        graph_parameters_queue_params_list[graph_parameter_index].graph_parameter_index = graph_parameter_index;
        graph_parameters_queue_params_list[graph_parameter_index].refs_list_size = APP_BUFFER_Q_DEPTH;
        graph_parameters_queue_params_list[graph_parameter_index].refs_list = (vx_reference*)&obj->captureObj.raw_image_arr[0];
        graph_parameter_index++;

        vxSetGraphScheduleConfig(obj->graph,
                VX_GRAPH_SCHEDULE_MODE_QUEUE_AUTO,
                graph_parameter_index,
                graph_parameters_queue_params_list);

        tivxSetGraphPipelineDepth(obj->graph, APP_PIPELINE_DEPTH);

        tivxSetNodeParameterNumBufByIndex(obj->vissObj.viss_node, 4, APP_BUFFER_Q_DEPTH);

        if (obj->en_csitx == 1)
        {
            tivxSetNodeParameterNumBufByIndex(obj->gl_mosaic_node, 2, APP_BUFFER_Q_DEPTH);
        }
        else
        {
            tivxSetNodeParameterNumBufByIndex(obj->imgMosaicObj.node, 1, APP_BUFFER_Q_DEPTH);
        }

        APP_PRINTF("Pipeline params setup done!\n");
    }

    return status;
}

static vx_status app_verify_graph(AppObj *obj)
{
    vx_status status = VX_SUCCESS;

    status = vxVerifyGraph(obj->graph);

    if(status == VX_SUCCESS)
    {
        APP_PRINTF("Grapy verify done!\n");
    }

    if (obj->captureObj.enable_error_detection)
    {
        status = app_send_error_frame(&obj->captureObj);
    }

    /* wait a while for prints to flush */
    tivxTaskWaitMsecs(100);

    return status;
}

static vx_status app_run_graph_for_one_frame_pipeline(AppObj *obj, vx_int32 frame_id)
{
  vx_status status = VX_SUCCESS;

  appPerfPointBegin(&obj->total_perf);

  CaptureObj *captureObj = &obj->captureObj;

  if(obj->pipeline < 0)
  {
    /* Enqueue outpus */

    /* Enqueue inputs during pipeup dont execute */
    vxGraphParameterEnqueueReadyRef(obj->graph, captureObj->graph_parameter_index, (vx_reference*)&obj->captureObj.raw_image_arr[obj->enqueueCnt], 1);

    obj->enqueueCnt++;
    obj->enqueueCnt   = (obj->enqueueCnt  >= APP_BUFFER_Q_DEPTH)? 0 : obj->enqueueCnt;
    obj->pipeline++;

  }

  if(obj->pipeline == 0)
  {
      /* Execute 1st frame */
      vxGraphParameterEnqueueReadyRef(obj->graph, captureObj->graph_parameter_index, (vx_reference*)&obj->captureObj.raw_image_arr[obj->enqueueCnt], 1);

      obj->enqueueCnt++;
      obj->enqueueCnt   = (obj->enqueueCnt  >= APP_BUFFER_Q_DEPTH)? 0 : obj->enqueueCnt;
      obj->pipeline++;
  }

  if(obj->pipeline > 0)
  {
    vx_image capture_input_image;
    uint32_t num_refs;

    /* Dequeue input */
    vxGraphParameterDequeueDoneRef(obj->graph, captureObj->graph_parameter_index, (vx_reference*)&capture_input_image, 1, &num_refs);

    /* Enqueue input - start execution */
    vxGraphParameterEnqueueReadyRef(obj->graph, captureObj->graph_parameter_index, (vx_reference*)&capture_input_image, 1);

    obj->enqueueCnt++;
    obj->dequeueCnt++;

    obj->enqueueCnt = (obj->enqueueCnt >= APP_BUFFER_Q_DEPTH)? 0 : obj->enqueueCnt;
    obj->dequeueCnt = (obj->dequeueCnt >= APP_BUFFER_Q_DEPTH)? 0 : obj->dequeueCnt;

  }

  appPerfPointEnd(&obj->total_perf);

  return status;
}

vx_int32 write_output_image_fp(FILE * fp, vx_image out_image)
{
    vx_uint32 width, height;
    vx_size planes;
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
        num_luma_bytes_written_to_file  += fwrite(data_ptr1, 1, imgaddr_stride, fp);
        data_ptr1 += imgaddr_stride;
    }
    vxUnmapImagePatch(out_image, map_id1);

    fflush(fp);
    if (planes > 1)
    {
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
    }
    num_bytes_written_to_file = num_luma_bytes_written_to_file + num_chroma_bytes_written_to_file;
    APP_PRINTF("Written %d bytes \n", num_bytes_written_to_file);

    return num_bytes_written_to_file;
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
    /* uint32_t size = (stride * height); */
    /* uint32_t rgb_size = size * 3; */
    uint32_t rgb_stride = stride * 3;
    /* uint32_t rgb_pixel_ctr = 1; */
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
    /* uint32_t size = (stride * height); */
    /* uint32_t rgb_size = size * 3; */
    uint32_t rgb_stride = stride * 3;
    /* uint32_t rgb_pixel_ctr = 1; */
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
    /* png_byte bit_depth = 24; */
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
    /* vx_uint32 num_bytes_per_pixel = 1; */
    /* vx_uint32 num_luma_bytes_written_to_file = 0; */
    /* vx_uint32 num_chroma_bytes_written_to_file = 0; */
    /* vx_uint32 num_bytes_written_to_file = 0; */
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

vx_int32 write_output_image_png_8bit(char * file_name, vx_image out_nv12)
{
    FILE * fp = fopen(file_name, "wb");
    if(!fp)
    {
        APP_PRINTF("Unable to open file %s\n", file_name);
        return -1;
    }

    vx_uint32 len1 = write_output_image_nv12_png_fp(fp, out_nv12);

    fclose(fp);
    APP_PRINTF("%d bytes written to %s\n", len1, file_name);
    return len1;
}

static void write_video(AppObj *obj)
{
    uint32_t i;
    for (i = 0; i < obj->sensorObj.num_cameras_enabled; i++)
    {
        vx_image output_img = (vx_image)vxGetObjectArrayItem(obj->vissObj.output_arr, i);

        write_output_image_fp(obj->video_files[i], output_img);
    }
    obj->frames_written++;
}

static void save_debug_images(AppObj *obj, uint32_t frame_ctr)
{
    int num_bytes_io = 0;
    char yuv_image_fname[128];
    char png_image_fname[128];

    uint32_t i;
    for (i = 0; i < obj->sensorObj.num_cameras_enabled; i++)
    {
        vx_image output_img = (vx_image)vxGetObjectArrayItem(obj->vissObj.output_arr, i);
        snprintf(yuv_image_fname, 128, "./%s_%d_%04d[%dx%d].yuv", "img_viss", i, frame_ctr, obj->sensorObj.image_width, obj->sensorObj.image_height);
        snprintf(png_image_fname, 128, "./%s_%d_%04d[%dx%d].png", "img_viss", i, frame_ctr, obj->sensorObj.image_width, obj->sensorObj.image_height);
        num_bytes_io = write_output_image_nv12_8bit(yuv_image_fname, output_img);
        if(num_bytes_io < 0)
        {
            printf("Error writing to VISS NV12 file \n");
        }

        num_bytes_io = write_output_image_png_8bit(png_image_fname, output_img);
        if(num_bytes_io < 0)
        {
            printf("Error writing to VISS PNG file \n");
        }
    }
}

static vx_status app_run_graph(AppObj *obj)
{
    vx_status status = VX_SUCCESS;

    SensorObj *sensorObj = &obj->sensorObj;
    vx_int32 frame_id = 0;

    app_pipeline_params_defaults(obj);

    if(NULL == sensorObj->sensor_name)
    {
        printf("sensor name is NULL \n");
        return VX_FAILURE;
    }
    status = appStartImageSensor(sensorObj->sensor_name, sensorObj->mask_cameras_enabled);

    if (sensorObj->tpg_mask)
    {
        vx_int32 ch, tpg;

        for (ch = 0; ch < 8; ch++) {
            tpg = (sensorObj->tpg_mask >> (4 * ch)) & 0x0f;

            /* if camera is enabled */
            if (!(sensorObj->mask_cameras_enabled & BIT(ch)))
                continue;
            /* if tpg_mask is enabled */
            if (!tpg)
                continue;

#if 0
            switch(tpg)
            {
                case ISP_MANUFACTURING_SOLID_WHITE:
                    status =  set_register_via_iss(ch, AR233_TEST_PATTERN_MODE_REG, AR233_TEST_PATTERN_SOLID);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_RED_REG, 0xffff);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_GREENR_REG, 0xffff);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_BLUE_REG, 0xffff);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_GREENB_REG, 0xffff);
                    break;
                case ISP_MANUFACTURING_SOLID_BLACK:
                    status =  set_register_via_iss(ch, AR233_TEST_PATTERN_MODE_REG, AR233_TEST_PATTERN_SOLID);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_RED_REG, 0x0);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_GREENR_REG, 0x0);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_BLUE_REG, 0x0);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_GREENB_REG, 0x0);
                    break;
                case ISP_MANUFACTURING_SOLID_RED:
                    status =  set_register_via_iss(ch, AR233_TEST_PATTERN_MODE_REG, AR233_TEST_PATTERN_SOLID);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_RED_REG, 0xffff);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_GREENR_REG, 0x0);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_BLUE_REG, 0x0);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_GREENB_REG, 0x0);
                    break;
                case ISP_MANUFACTURING_SOLID_GREEN:
                    status =  set_register_via_iss(ch, AR233_TEST_PATTERN_MODE_REG, AR233_TEST_PATTERN_SOLID);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_RED_REG, 0x0);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_GREENR_REG, 0xffff);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_BLUE_REG, 0x0);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_GREENB_REG, 0xffff);
                    break;
                case ISP_MANUFACTURING_SOLID_BLUE:
                    status =  set_register_via_iss(ch, AR233_TEST_PATTERN_MODE_REG, AR233_TEST_PATTERN_SOLID);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_RED_REG, 0x0);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_GREENR_REG, 0x0);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_BLUE_REG, 0xffff);
                    status |= set_register_via_iss(ch, AR233_TEST_DATA_GREENB_REG, 0x0);
                    break;
                case ISP_MANUFACTURING_COLOR_BAR:
                    status =  set_register_via_iss(ch, AR233_TEST_PATTERN_MODE_REG, AR233_TEST_PATTERN_BARS);
                    break;
                case ISP_MANUFACTURING_COLOR_BAR_GRADIENT:
                    status =  set_register_via_iss(ch, AR233_TEST_PATTERN_MODE_REG, AR233_TEST_PATTERN_BARS_FADE);
                    break;
                case ISP_MANUFACTURING_TEST_NONE:
                default:
                    status =  set_register_via_iss(ch, AR233_TEST_PATTERN_MODE_REG, AR233_TEST_PATTERN_NORMAL);
            }
#else
            switch(tpg)
            {
                case ISP_MANUFACTURING_COLOR_BAR:
                    status =  set_register_via_iss(ch, 0x5240, 0x01);
                    status |=  set_register_via_iss(ch, 0x5440, 0x01);
                    status |=  set_register_via_iss(ch, 0x5640, 0x01);
                    status |=  set_register_via_iss(ch, 0x5840, 0x01);
                    status |=  set_register_via_iss(ch, 0x5004, 0x1f);
                    status |=  set_register_via_iss(ch, 0x5005, 0x00);
                    status |=  set_register_via_iss(ch, 0x5006, 0x1f);
                    status |=  set_register_via_iss(ch, 0x5007, 0x1f);
                    break;
                case ISP_MANUFACTURING_COLOR_BAR_GRADIENT:
                    status =  set_register_via_iss(ch, 0x5240, 0x11);
                    status |=  set_register_via_iss(ch, 0x5440, 0x11);
                    status |=  set_register_via_iss(ch, 0x5640, 0x11);
                    status |=  set_register_via_iss(ch, 0x5840, 0x11);
                    status |=  set_register_via_iss(ch, 0x5004, 0x1f);
                    status |=  set_register_via_iss(ch, 0x5005, 0x00);
                    status |=  set_register_via_iss(ch, 0x5006, 0x1f);
                    status |=  set_register_via_iss(ch, 0x5007, 0x1f);
                    break;
                case ISP_MANUFACTURING_TEST_NONE:
                default:
                    status =  set_register_via_iss(ch, 0x5240, 0x0f);
                    status |=  set_register_via_iss(ch, 0x5440, 0x0f);
                    status |=  set_register_via_iss(ch, 0x5640, 0x0f);
                    status |=  set_register_via_iss(ch, 0x5840, 0x0f);
                    status |=  set_register_via_iss(ch, 0x5004, 0x1e);
                    status |=  set_register_via_iss(ch, 0x5005, 0x1e);
                    status |=  set_register_via_iss(ch, 0x5006, 0x1e);
                    status |=  set_register_via_iss(ch, 0x5007, 0x1e);
            }
#endif
        }
    }

    while(obj->stop_task == 0)
    {
        if (obj->en_out_video_write)
        {
            write_video(obj);
        }

        if(obj->write_file == 1)
        {
            if(obj->captureObj.en_out_capture_write == 1)
            {
                app_send_cmd_capture_write_node(&obj->captureObj, frame_id, obj->num_frames_to_write, obj->num_frames_to_skip);
                save_debug_images(obj, frame_id);
            }
            if(obj->vissObj.en_out_viss_write == 1)
            {
                app_send_cmd_viss_write_node(&obj->vissObj, frame_id, obj->num_frames_to_write, obj->num_frames_to_skip);
            }

            if(obj->captureObj.en_out_capture_write == 1)
            {
                app_send_cmd_capture_write_node(&obj->captureObj, frame_id, obj->num_frames_to_write, obj->num_frames_to_skip);
            }
            obj->write_file = 0;
        }

        app_run_graph_for_one_frame_pipeline(obj, frame_id);
        frame_id++;
        /* user asked to stop processing */
        if(obj->stop_task)
          break;
    }

    vxWaitGraph(obj->graph);

    obj->stop_task = 1;

    status = appStopImageSensor(obj->sensorObj.sensor_name, sensorObj->mask_cameras_enabled);

    return status;
}

static void app_pipeline_params_defaults(AppObj *obj)
{
  obj->pipeline       = -APP_BUFFER_Q_DEPTH + 1;
  obj->enqueueCnt     = 0;
  obj->dequeueCnt     = 0;
}

static void set_sensor_defaults(SensorObj *sensorObj)
{
    strcpy(sensorObj->sensor_name, SENSOR_ONSEMI_AR0233_UB953_MARS);

    sensorObj->sensor_index = 1;
    sensorObj->sensor_init = 1;
    sensorObj->num_sensors_found = 0;
    sensorObj->sensor_features_enabled = 0;
    sensorObj->sensor_features_supported = 0;
    sensorObj->sensor_dcc_enabled = 0;
    sensorObj->sensor_wdr_enabled = 0;
    sensorObj->sensor_exp_control_enabled = 0;
    sensorObj->sensor_gain_control_enabled = 0;
}

static void app_default_param_set(AppObj *obj)
{
    set_sensor_defaults(&obj->sensorObj);

    app_pipeline_params_defaults(obj);

    obj->is_interactive = 1;
    obj->sensorObj.is_interactive = obj->is_interactive;
    obj->write_file = 0;

    obj->en_csitx = 1;

    obj->captureObj.en_out_capture_write = 1;
    obj->vissObj.en_out_viss_write = 0;
    obj->captureObj.enable_error_detection = 1;
    obj->sensorObj.num_cameras_enabled = 1;
    obj->sensorObj.mask_cameras_enabled = 0x01;
    obj->sensorObj.tpg_mask = 0;
    obj->num_frames_to_write = 1;
    obj->num_frames_to_skip = 0;

    snprintf(obj->captureObj.output_file_path,APP_MAX_FILE_PATH, ".");
    snprintf(obj->vissObj.output_file_path,APP_MAX_FILE_PATH, ".");
}

static vx_int32 calc_grid_size(vx_uint32 ch)
{
    if(0==ch)
    {
        return -1;
    }
    else if(1==ch)
    {
        return 1;
    }
    else if(4>=ch)
    {
        return 2;
    }
    else if(9>=ch)
    {
        return 3;
    }
    else if(16>=ch)
    {
        return 4;
    }else
    {
        return -1;
    }
}

static void set_img_mosaic_params(ImgMosaicObj *imgMosaicObj, vx_uint32 in_width,
                                  vx_uint32 in_height, vx_int32 numCh)
{
    vx_int32 idx, ch;
    vx_int32 grid_size = calc_grid_size(numCh);

    imgMosaicObj->out_width    = DISPLAY_WIDTH;
    imgMosaicObj->out_height   = DISPLAY_HEIGHT;
    imgMosaicObj->num_inputs   = 1;

    idx = 0;

    tivxImgMosaicParamsSetDefaults(&imgMosaicObj->params);

    for(ch = 0; ch < numCh; ch++)
    {
        vx_int32 winX = ch%grid_size;
        vx_int32 winY = ch/grid_size;


        imgMosaicObj->params.windows[idx].startX  = (winX * (in_width/grid_size));
        imgMosaicObj->params.windows[idx].startY  = (winY * (in_height/grid_size));
        imgMosaicObj->params.windows[idx].width   = in_width/grid_size;
        imgMosaicObj->params.windows[idx].height  = in_height/grid_size;
        imgMosaicObj->params.windows[idx].input_select   = 0;
        imgMosaicObj->params.windows[idx].channel_select = ch;
        idx++;
    }

    imgMosaicObj->params.num_windows  = idx;

    /* Number of time to clear the output buffer before it gets reused */
    imgMosaicObj->params.clear_count  = APP_BUFFER_Q_DEPTH;
    //imgMosaicObj->params.enable_overlay = 0;
}

static void app_update_param_set(AppObj *obj)
{

    vx_uint16 resized_width, resized_height;
    appIssGetResizeParams(obj->sensorObj.image_width,
                          obj->sensorObj.image_height,
                          DISPLAY_WIDTH, DISPLAY_HEIGHT,
                          &resized_width, &resized_height);

    set_img_mosaic_params(&obj->imgMosaicObj,
                          resized_width, resized_height,
                          obj->sensorObj.num_cameras_enabled);
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
