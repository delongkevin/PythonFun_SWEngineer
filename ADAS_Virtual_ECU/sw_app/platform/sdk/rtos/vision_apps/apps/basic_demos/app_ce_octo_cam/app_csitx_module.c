/*
 *
 * Copyright (c) 2017 Texas Instruments Incorporated
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
#include "app_csitx_module.h"

vx_status app_init_csitx(vx_context context, CsiTxObj *csitxObj, char *objName,
                         uint32_t width, uint32_t height, vx_int32 bufq_depth)
{
    vx_status status = VX_SUCCESS;
    tivx_csitx_params_t local_csitx_config;
    vx_int32 q;

    /* CSITX Config initialization */
    tivx_csitx_params_init(&local_csitx_config);
    local_csitx_config.numInst                          = 1U;
    local_csitx_config.numCh                            = 1U;
    local_csitx_config.instId[0U]                       = 0U;
    local_csitx_config.instCfg[0U].rxCompEnable         = (uint32_t)vx_true_e;
    local_csitx_config.instCfg[0U].rxv1p3MapEnable      = (uint32_t)vx_true_e;
    local_csitx_config.instCfg[0U].laneBandSpeed        = TIVX_CSITX_LANE_BAND_SPEED_390_TO_450_MBPS;
    local_csitx_config.instCfg[0U].numDataLanes         = 2U;
    for (q = 0U; q < local_csitx_config.instCfg[0U].numDataLanes; q++)
    {
        local_csitx_config.instCfg[0U].lanePolarityCtrl[q] = 0u;
    }
    local_csitx_config.chVcNum[0]   = 0;
    local_csitx_config.chInstMap[0] = 0;

    csitxObj->csitx_config = vxCreateUserDataObject(context, "tivx_csitx_params_t",
                                          sizeof(tivx_csitx_params_t), &local_csitx_config);

    vx_image input_img = vxCreateImage(context, width, height, VX_DF_IMAGE_RGBX);
    for(q = 0; q < bufq_depth; q++)
    {
        csitxObj->input_img_arr[q] = vxCreateObjectArray(context, (vx_reference)input_img, 1);
        status = vxGetStatus((vx_reference)csitxObj->input_img_arr[q]);
        if(status != VX_SUCCESS)
        {
            printf("[CSITX-MODULE] Unable to create output image of size %d x %d!\n",
                   DISPLAY_WIDTH, DISPLAY_HEIGHT);
            break;
        }
    }
    vxReleaseImage(&input_img);

    return status;
}

void app_deinit_csitx(CsiTxObj *csitxObj, vx_int32 bufq_depth)
{
    vx_int32 q;

    for(q = 0; q < bufq_depth; q++)
    {
        vxReleaseObjectArray(&csitxObj->input_img_arr[q]);
    }

    vxReleaseUserDataObject(&csitxObj->csitx_config);
}

void app_delete_csitx(CsiTxObj *csitxObj)
{
    if (vx_true_e == tivxIsTargetEnabled(TIVX_TARGET_CSITX))
    {
        vxReleaseNode(&csitxObj->csitx_node);
    }
}

vx_status app_create_graph_csitx(vx_graph graph, CsiTxObj *csitxObj, vx_object_array input_image_arr)
{
    vx_status status = VX_SUCCESS;

    if (vx_true_e == tivxIsTargetEnabled(TIVX_TARGET_CSITX))
    {
        csitxObj->csitx_node = tivxCsitxNode(graph, csitxObj->csitx_config, input_image_arr);
        status = vxGetStatus((vx_reference)csitxObj->csitx_node);

        if(status == VX_SUCCESS)
        {
            vxSetNodeTarget(csitxObj->csitx_node, VX_TARGET_STRING, TIVX_TARGET_CSITX);
            vxSetReferenceName((vx_reference)csitxObj->csitx_node, "CsiTx_node");
        }
        else
        {
            printf("[CSITX-MODULE] Unable to create csitx node!\n");
        }
    }
    return status;
}
