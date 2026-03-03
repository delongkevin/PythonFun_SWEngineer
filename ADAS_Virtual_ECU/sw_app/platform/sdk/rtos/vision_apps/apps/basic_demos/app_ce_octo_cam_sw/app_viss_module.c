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

#include "app_viss_module.h"

#define BIT(x)          (1 << (x))

rc_settings rc_prms =
{
    .context_name = "ar0233",
    .configs = {
    },
};

#if 0
static void safety_gets(char *out, size_t length)
{
    if (fgets(out, length, stdin) != 0)
    {
        out[strcspn(out, "\n")] = '\0';
    }
}
#endif

vx_status app_init_viss(vx_context context, VISSObj *vissObj, SensorObj *sensorObj, char *objName)
{
    vx_status status = VX_SUCCESS;
    vx_uint32 img_height, img_width;
    vx_user_data_object config_exemplar;
    uint8_t ctx_id = 0;
    uint8_t ch = 0;

    /* !!! This is highly use case specific */
    uint32_t more_than_2_cams_on_either_csi =
            __builtin_popcount(sensorObj->mask_cameras_enabled & 0x0f) > 2 ||
            __builtin_popcount(sensorObj->mask_cameras_enabled & 0xf0) > 2 ;

    config_exemplar = vxCreateUserDataObject(context, "tivx_vpac_cuc_isp_params_t",
                                             sizeof(tivx_vpac_cuc_isp_params_t),
                                             NULL);

    vissObj->configs_arr = vxCreateObjectArray(context, (vx_reference)config_exemplar,
                                              sensorObj->num_cameras_enabled);

    vxReleaseUserDataObject(&config_exemplar);

    fflush(stdin);

    for (ch = 0; ch < 8 /*TIVX_CAPTURE_MAX_CH*/; ch++)
    {
        /* if camera is enabled */
        if (sensorObj->mask_cameras_enabled & BIT(ch))
        {
            tivx_vpac_cuc_isp_params_t *config;
            uint32_t *data_ptr = NULL;
            vx_map_id config_map_id;
            config_exemplar = (vx_user_data_object)vxGetObjectArrayItem((vx_object_array)vissObj->configs_arr,
                                                                        ctx_id);
            vxMapUserDataObject((vx_user_data_object)config_exemplar,
                                0,
                                sizeof(tivx_vpac_cuc_isp_params_t),
                                &config_map_id,
                                (void **)&data_ptr,
                                VX_WRITE_ONLY,
                                VX_MEMORY_TYPE_HOST,
                                0);
            if (data_ptr)
            {
#if 0
                int i;
                printf("Please enter required configs for sensor channel %d:\n", ch);
                for (i = 0; i < TIVX_VPAC_CUC_RC_MAX_CONFIGS; i++)
                {
                    safety_gets(rc_prms.configs[i], TIVX_VPAC_CUC_RC_MAX_CONFIG_NAME_LEN);
                    if (rc_prms.configs[i][0] == 0)
                    {
                        break;
                    }
                }
#endif
                config = (tivx_vpac_cuc_isp_params_t *)data_ptr;

                tivx_vpac_cuc_isp_params_init(config);

                config->sensor_id        = sensorObj->sensorParams.dccId;
                config->mux_output0      = 0;
                config->mux_output1      = 0;
                config->mux_output2      = 4;
                config->mux_output3      = 0;
                config->mux_output4      = 3;
                config->channel_id       = ch;
                config->context_id       = ctx_id;
                config->enable_dma_quirk = more_than_2_cams_on_either_csi;
                config->test_pattern     = (sensorObj->tpg_mask >> (4 * ch)) & 0x0f;
                strcpy(rc_prms.context_name, sensorObj->sensor_name);
                memcpy(&config->rc_prms, &rc_prms,
                       sizeof(config->rc_prms));

                vxUnmapUserDataObject((vx_user_data_object)config_exemplar, config_map_id);
            }
            else
            {
                printf("Failed to map config object\n");
                return VX_ERROR_INVALID_PARAMETERS;
            }

            vxReleaseUserDataObject(&config_exemplar);

            ctx_id++;
        }
    }

    img_width  = sensorObj->sensorParams.sensorInfo.raw_params.width;
    img_height = sensorObj->sensorParams.sensorInfo.raw_params.height;

    vx_image output_img = vxCreateImage(context, img_width, img_height, VX_DF_IMAGE_NV12);
    vissObj->output_arr = vxCreateObjectArray(context, (vx_reference)output_img,
                                              sensorObj->num_cameras_enabled);
    vxReleaseImage(&output_img);

    if(vissObj->en_out_viss_write == 1)
    {
        char file_path[TIVX_FILEIO_FILE_PATH_LENGTH];
        char file_prefix[TIVX_FILEIO_FILE_PREFIX_LENGTH];

        strcpy(file_path, vissObj->output_file_path);
        vissObj->file_path   = vxCreateArray(context, VX_TYPE_UINT8, TIVX_FILEIO_FILE_PATH_LENGTH);
        vxAddArrayItems(vissObj->file_path, TIVX_FILEIO_FILE_PATH_LENGTH, &file_path[0], 1);

        strcpy(file_prefix, "viss_img_output");
        vissObj->img_file_prefix = vxCreateArray(context, VX_TYPE_UINT8, TIVX_FILEIO_FILE_PREFIX_LENGTH);
        vxAddArrayItems(vissObj->img_file_prefix, TIVX_FILEIO_FILE_PREFIX_LENGTH, &file_prefix[0], 1);

        vissObj->write_cmd = vxCreateUserDataObject(context, "tivxFileIOWriteCmd", sizeof(tivxFileIOWriteCmd), NULL);
    }
    else
    {
        vissObj->file_path        = NULL;
        vissObj->img_file_prefix  = NULL;
        vissObj->img_write_node   = NULL;
        vissObj->write_cmd        = NULL;
    }

    return (status);
}

void app_deinit_viss(VISSObj *vissObj)
{
    vxReleaseObjectArray(&vissObj->configs_arr);
    vxReleaseObjectArray(&vissObj->output_arr);

    if(vissObj->en_out_viss_write == 1)
    {
        vxReleaseArray(&vissObj->file_path);
        vxReleaseArray(&vissObj->img_file_prefix);
        vxReleaseUserDataObject(&vissObj->write_cmd);
    }
}

void app_delete_viss(VISSObj *vissObj)
{
    if(vissObj->viss_node != NULL)
    {
        vxReleaseNode(&vissObj->viss_node);
    }

    if(vissObj->rc_node != NULL)
    {
        vxReleaseNode(&vissObj->rc_node);
    }

    if(vissObj->img_write_node != NULL)
    {
        vxReleaseNode(&vissObj->img_write_node);
    }
}

vx_status app_create_graph_viss(vx_graph graph, VISSObj *vissObj,
                                vx_object_array raw_image_arr)
{
    vx_status status = VX_SUCCESS;

    tivx_raw_image raw_image = (tivx_raw_image)vxGetObjectArrayItem(raw_image_arr, 0);
    vx_image output_img = (vx_image)vxGetObjectArrayItem(vissObj->output_arr, 0);
    vx_user_data_object config = (vx_user_data_object)vxGetObjectArrayItem(vissObj->configs_arr, 0);

    vissObj->viss_node = tivxVpacCucVissNode(
                                graph,
                                config,
                                raw_image,
                                NULL, NULL, output_img, NULL, NULL);

    vxSetReferenceName((vx_reference)vissObj->viss_node, "CUC_VISS");
    vxSetNodeTarget(vissObj->viss_node, VX_TARGET_STRING, TIVX_TARGET_VPAC_CUC_VISS);

    vx_bool viss_replicate[] = { vx_true_e,
                                 vx_true_e,
                    vx_false_e, vx_false_e, vx_true_e, vx_false_e, vx_false_e };
    vxReplicateNode(graph, vissObj->viss_node, viss_replicate, 7);

    vissObj->rc_node = tivxVpacCucRcNode(graph, config, raw_image, NULL);

    vxSetReferenceName((vx_reference)vissObj->rc_node, "CUC_RC");
    vxSetNodeTarget(vissObj->rc_node, VX_TARGET_STRING, TIVX_TARGET_VPAC_CUC_RC);

    vx_bool rc_replicate[] = { vx_true_e, vx_true_e, vx_false_e };
    status = vxReplicateNode(graph, vissObj->rc_node, rc_replicate, 3);
    if (VX_SUCCESS != status)
    {
            printf("replicate failed!\n");
    }

    tivxReleaseRawImage(&raw_image);
    vxReleaseImage(&output_img);
    vxReleaseUserDataObject(&config);

    if(vissObj->en_out_viss_write == 1)
    {
        APP_PRINTF("Adding VISS write node on graph .. \n");
        status = app_create_graph_viss_write_output(graph, vissObj);
        APP_PRINTF("VISS write node added! \n");
    }

    return status;
}

vx_status app_create_graph_viss_write_output(vx_graph graph, VISSObj *vissObj)
{
    vx_status status = VX_SUCCESS;

    vx_image output_img = (vx_image)vxGetObjectArrayItem(vissObj->output_arr, 0);

    vissObj->img_write_node = tivxWriteImageNode(graph, output_img, vissObj->file_path, vissObj->img_file_prefix);
    status = vxGetStatus((vx_reference)vissObj->img_write_node);
    vxSetNodeTarget(vissObj->img_write_node, VX_TARGET_STRING, TIVX_TARGET_A72_0);
    vxSetReferenceName((vx_reference)vissObj->img_write_node, "viss_img_write_node");

    vx_bool replicate[] = { vx_true_e, vx_false_e, vx_false_e};
    vxReplicateNode(graph, vissObj->img_write_node, replicate, 3);

    vxReleaseImage(&output_img);

    return (status);
}

vx_status app_send_cmd_viss_write_node(VISSObj *vissObj, vx_uint32 start_frame, vx_uint32 num_frames, vx_uint32 num_skip)
{
    vx_status status = VX_SUCCESS;

    tivxFileIOWriteCmd write_cmd;

    write_cmd.start_frame = start_frame;
    write_cmd.num_frames = num_frames;
    write_cmd.num_skip = num_skip;

    status = vxCopyUserDataObject(vissObj->write_cmd, 0, sizeof(tivxFileIOWriteCmd),\
                  &write_cmd, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST);

    if(status == VX_SUCCESS)
    {
        vx_reference refs[2];

        refs[0] = (vx_reference)vissObj->write_cmd;

        status = tivxNodeSendCommand(vissObj->img_write_node, TIVX_CONTROL_CMD_SEND_TO_ALL_REPLICATED_NODES,
                                 TIVX_FILEIO_CMD_SET_FILE_WRITE,
                                 refs, 1u);

        if(VX_SUCCESS != status)
        {
            printf("VISS Img Write Node send command failed!\n");
        }

        APP_PRINTF("VISS Img Write node send command success!\n");
    }
    return (status);
}
