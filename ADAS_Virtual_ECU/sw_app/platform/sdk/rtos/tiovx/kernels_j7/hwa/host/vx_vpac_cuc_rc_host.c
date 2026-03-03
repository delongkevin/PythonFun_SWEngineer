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
#ifdef BUILD_VPAC_CUC_VISS

#include "TI/tivx.h"
#include "tivx_hwa_kernels.h"
#include "tivx_kernel_vpac_cuc_rc.h"
#include "TI/tivx_target_kernel.h"
#include "tivx_hwa_host_priv.h"

static vx_kernel vx_vpac_cuc_isp_rc_kernel = NULL;

static vx_status VX_CALLBACK tivxAddKernelVpacCucRcValidate(vx_node node,
            const vx_reference parameters[ ],
            vx_uint32 num,
            vx_meta_format metas[]);
static vx_status VX_CALLBACK tivxAddKernelVpacCucRcInitialize(vx_node node,
            const vx_reference parameters[ ],
            vx_uint32 num_params);

static vx_status VX_CALLBACK tivxAddKernelVpacCucRcValidate(vx_node node,
            const vx_reference parameters[ ],
            vx_uint32 num,
            vx_meta_format metas[])
{
    vx_status status = (vx_status)VX_SUCCESS;

    vx_user_data_object configuration = NULL;
    vx_user_data_object trace = NULL;
    vx_char configuration_name[VX_MAX_REFERENCE_NAME];
    vx_size configuration_size;
    vx_char trace_name[VX_MAX_REFERENCE_NAME];
    vx_size trace_size;
    tivx_vpac_cuc_isp_params_t params;

    tivx_raw_image raw = NULL;
    vx_uint32 raw_w;
    vx_uint32 raw_h;

    if ((num != TIVX_KERNEL_VPAC_CUC_RC_MAX_PARAMS)
        || (NULL == parameters[TIVX_KERNEL_VPAC_CUC_RC_CFG_IDX])
        || (NULL == parameters[TIVX_KERNEL_VPAC_CUC_RC_RAW_IDX])
    )
    {
        status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
        VX_PRINT(VX_ZONE_ERROR, "One or more REQUIRED parameters are set to NULL\n");
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        configuration = (vx_user_data_object)parameters[TIVX_KERNEL_VPAC_CUC_RC_CFG_IDX];
        raw = (tivx_raw_image)parameters[TIVX_KERNEL_VPAC_CUC_RC_RAW_IDX];
        trace = (vx_user_data_object)parameters[TIVX_KERNEL_VPAC_CUC_RC_TRACE_IDX];
    }

    /* PARAMETER ATTRIBUTE FETCH */

    if ((vx_status)VX_SUCCESS == status)
    {
        tivxCheckStatus(&status, vxQueryUserDataObject(configuration, (vx_enum)VX_USER_DATA_OBJECT_NAME, &configuration_name, sizeof(configuration_name)));
        tivxCheckStatus(&status, vxQueryUserDataObject(configuration, (vx_enum)VX_USER_DATA_OBJECT_SIZE, &configuration_size, sizeof(configuration_size)));

        tivxCheckStatus(&status, tivxQueryRawImage(raw, (vx_enum)TIVX_RAW_IMAGE_WIDTH, &raw_w, sizeof(raw_w)));
        tivxCheckStatus(&status, tivxQueryRawImage(raw, (vx_enum)TIVX_RAW_IMAGE_HEIGHT, &raw_h, sizeof(raw_h)));

        if (NULL != trace)
        {
            tivxCheckStatus(&status, vxQueryUserDataObject(trace, (vx_enum)VX_USER_DATA_OBJECT_NAME, &trace_name, sizeof(trace_name)));
            tivxCheckStatus(&status, vxQueryUserDataObject(trace, (vx_enum)VX_USER_DATA_OBJECT_SIZE, &trace_size, sizeof(trace_size)));
        }
    }

    /* PARAMETER CHECKING */

    if ((vx_status)VX_SUCCESS == status)
    {
        if ((configuration_size != sizeof(tivx_vpac_cuc_isp_params_t)) ||
            (strncmp(configuration_name, "tivx_vpac_cuc_isp_params_t", sizeof(configuration_name)) != 0))
        {
            status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
            VX_PRINT(VX_ZONE_ERROR, "'configuration' should be a user_data_object of type:\n tivx_vpac_cuc_isp_params_t \n");
        }
        else
        {
            vxCopyUserDataObject(configuration, 0, sizeof(tivx_vpac_cuc_isp_params_t), &params, (vx_enum)VX_READ_ONLY, (vx_enum)VX_MEMORY_TYPE_HOST);
        }

        if (NULL != trace)
        {
            if ((trace_size != sizeof(tivx_vpac_cuc_isp_trace_t)) ||
                (strncmp(trace_name, "tivx_vpac_cuc_isp_trace_t", sizeof(trace_name)) != 0))
            {
                status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
                VX_PRINT(VX_ZONE_ERROR, "'trace' should be a user_data_object of type:\n tivx_vpac_cuc_isp_trace_t \n");
            }
        }
    }

    return status;
}

static vx_status VX_CALLBACK tivxAddKernelVpacCucRcInitialize(vx_node node,
            const vx_reference parameters[ ],
            vx_uint32 num_params)
{
    vx_status status = (vx_status)VX_SUCCESS;

    if ((num_params != TIVX_KERNEL_VPAC_CUC_RC_MAX_PARAMS) ||
        (NULL == parameters[TIVX_KERNEL_VPAC_CUC_RC_CFG_IDX]) ||
        (NULL == parameters[TIVX_KERNEL_VPAC_CUC_RC_RAW_IDX]))
    {
        status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
        VX_PRINT(VX_ZONE_ERROR, "One or more REQUIRED parameters are set to NULL\n");
    }

    return status;
}

vx_status tivxAddKernelVpacCucRc(vx_context context)
{
    vx_kernel kernel;
    vx_status status;
    uint32_t index;
    vx_enum kernel_id;

    status = vxAllocateUserKernelId(context, &kernel_id);
    if(status != (vx_status)VX_SUCCESS)
    {
        VX_PRINT(VX_ZONE_ERROR, "Unable to allocate user kernel ID\n");
    }

    if (status == (vx_status)VX_SUCCESS)
    {
        kernel = vxAddUserKernel(
                    context,
                    TIVX_KERNEL_VPAC_CUC_RC_NAME,
                    kernel_id,
                    NULL,
                    TIVX_KERNEL_VPAC_CUC_RC_MAX_PARAMS,
                    tivxAddKernelVpacCucRcValidate,
                    tivxAddKernelVpacCucRcInitialize,
                    NULL);

        status = vxGetStatus((vx_reference)kernel);
    }
    if (status == (vx_status)VX_SUCCESS)
    {
        index = 0;

        if (status == (vx_status)VX_SUCCESS)
        {
            /* Input config */
            status = vxAddParameterToKernel(kernel,
                        index,
                        (vx_enum)VX_INPUT,
                        VX_TYPE_USER_DATA_OBJECT,
                        (vx_enum)VX_PARAMETER_STATE_REQUIRED
            );
            index++;
        }
        if (status == (vx_status)VX_SUCCESS)
        {
            /* Input RAW Images */
            status = vxAddParameterToKernel(kernel,
                        index,
                        (vx_enum)VX_INPUT,
                        TIVX_TYPE_RAW_IMAGE,
                        (vx_enum)VX_PARAMETER_STATE_REQUIRED
            );
            index++;
        }
        if (status == (vx_status)VX_SUCCESS)
        {
            /* Input RAW Images */
            status = vxAddParameterToKernel(kernel,
                        index,
                        (vx_enum)VX_OUTPUT,
                        VX_TYPE_USER_DATA_OBJECT,
                        (vx_enum)VX_PARAMETER_STATE_OPTIONAL
            );
            index++;
        }
        if (status == (vx_status)VX_SUCCESS)
        {
            /* add supported target's */
            tivxAddKernelTarget(kernel, TIVX_TARGET_VPAC_CUC_RC);
            VX_PRINT(VX_ZONE_ERROR, "tivxAddKernelTarget  %s   ready\n", TIVX_TARGET_VPAC_CUC_RC);
        }
        if (status == (vx_status)VX_SUCCESS)
        {
            status = vxFinalizeKernel(kernel);
        }
        if (status != (vx_status)VX_SUCCESS)
        {
            vxReleaseKernel(&kernel);
            kernel = NULL;
            VX_PRINT(VX_ZONE_ERROR, "tivxAddKernelTarget  %s   failed\n", TIVX_TARGET_VPAC_CUC_RC);
        }
    }
    else
    {
        kernel = NULL;
    }
    vx_vpac_cuc_isp_rc_kernel = kernel;

    return status;
}

vx_status tivxRemoveKernelVpacCucRc(vx_context context)
{
    vx_status status;
    vx_kernel kernel = vx_vpac_cuc_isp_rc_kernel;

    status = vxRemoveKernel(kernel);
    vx_vpac_cuc_isp_rc_kernel = NULL;

    return status;
}

#endif
