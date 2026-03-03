/*******************************************************************************
 * vx_vpac_cuc_viss_target.c
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
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "tivx_hwa_cuc_viss_priv.h"
#include "tivx_kernel_vpac_cuc_viss.h"
#include "utils/perf_stats/include/app_perf_stats.h"
#include <utils/udma/include/app_udma.h>
#include <common_sensor_api.h>
#include <vx_vpac_cuc_common.h>
#include "safety.h"

#include <inttypes.h>
#include <stdlib.h>
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

static vx_status VX_CALLBACK tivxVpacCucVissCreate(
    tivx_target_kernel_instance kernel,
    tivx_obj_desc_t *obj_desc[],
    uint16_t num_params, void *priv_arg);
static vx_status VX_CALLBACK tivxVpacCucVissDelete(
    tivx_target_kernel_instance kernel,
    tivx_obj_desc_t *obj_desc[],
    uint16_t num_params, void *priv_arg);
static vx_status VX_CALLBACK tivxVpacCucVissProcess(
    tivx_target_kernel_instance kernel,
    tivx_obj_desc_t *obj_desc[],
    uint16_t num_params, void *priv_arg);
static vx_status VX_CALLBACK tivxVpacCucVissControl(
    tivx_target_kernel_instance kernel,
    uint32_t node_cmd_id, tivx_obj_desc_t *obj_desc[],
    uint16_t num_params, void *priv_arg);

static void tivxVpacVissSetInputParams(tivxVpacCucIspObj *ispObj,
                                       const tivx_obj_desc_raw_image_t *raw_img_desc);
static vx_status tivxVpacVissSetOutputParams(tivxVpacCucIspObj *ispObj,
                                             const tivx_vpac_cuc_isp_params_t *vissPrms,
                                             tivx_obj_desc_image_t *obj_desc[]);
static vx_status tivxVpacVissMapFormat(uint32_t *fmt, uint32_t *ccsFmt,
                                       uint32_t out_id, uint32_t vxFmt, uint32_t mux_val);
static vx_status tivxVpacVissMapStorageFormat(uint32_t *ccsFmt, uint32_t vxFmt);
static void tivxVpacVissSetIsInvalidFlag(tivx_obj_desc_t *obj_desc[]);

static void tivxVpacCucMarkBuffer(tivxVpacCucIspObj *ispObj,
                                  tivx_obj_desc_image_t *img_desc);
static void tivxVpacCucUnmarkBuffer(tivxVpacCucIspObj *ispObj,
                                    tivx_obj_desc_image_t *img_desc);
static vx_status tivxVpacCucVerifyBuffer(tivxVpacCucIspObj *ispObj,
                                         tivx_obj_desc_image_t *img_desc,
                                         tivx_obj_desc_user_data_object_t *verify_desc);

int32_t tivxVpacCucVissFrameComplCb(Fvid2_Handle handle, void *appData);

__attribute__((weak)) void image_buffer_mark_err_report(bool error_status)
{
    return;
}

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
static tivx_target_kernel vx_vpac_cuc_viss_target_kernel = NULL;

extern tivxVpacCucIspObj g_cucIspObjs[VHWA_M2M_VISS_MAX_HANDLES];

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void tivxAddTargetKernelVpacCucViss(void)
{
    vx_status status = (vx_status)VX_FAILURE;
    char target_name[TIVX_TARGET_MAX_NAME];
    vx_enum self_cpu;

    self_cpu = tivxGetSelfCpuId();

    if ((self_cpu == (vx_enum)TIVX_CPU_ID_IPU1_0) ||
        (self_cpu == (vx_enum)TIVX_CPU_ID_IPU1_1))
    {
        strncpy(target_name, TIVX_TARGET_VPAC_CUC_VISS, TIVX_TARGET_MAX_NAME);
        status = (vx_status)VX_SUCCESS;
    }
    else
    {
        VX_PRINT(VX_ZONE_ERROR, "Invalid CPU ID\n");
        status = (vx_status)VX_FAILURE;
    }

    if (status == (vx_status)VX_SUCCESS)
    {
        vx_vpac_cuc_viss_target_kernel = tivxAddTargetKernelByName(
            TIVX_KERNEL_VPAC_CUC_VISS_NAME, target_name,
            tivxVpacCucVissProcess, tivxVpacCucVissCreate,
            tivxVpacCucVissDelete, tivxVpacCucVissControl, NULL);
    }

    if (NULL == vx_vpac_cuc_viss_target_kernel)
    {
        VX_PRINT(VX_ZONE_ERROR, "Failed to add target kernel by name %s\n",
                 TIVX_TARGET_VPAC_CUC_VISS);
    }
}

void tivxRemoveTargetKernelVpacCucViss(void)
{
    vx_status status = (vx_status)VX_SUCCESS;

    status = tivxRemoveTargetKernel(vx_vpac_cuc_viss_target_kernel);
    if (status == (vx_status)VX_SUCCESS)
    {
        vx_vpac_cuc_viss_target_kernel = NULL;
    }
    else
    {
        VX_PRINT(VX_ZONE_ERROR, "Failed to Remove Viss TargetKernel\n");
    }
}

/* Setting the output descriptor flags to invalid if received raw_image is invalid */
static void tivxVpacVissSetIsInvalidFlag(tivx_obj_desc_t *obj_desc[])
{
    uint32_t cnt;
    uint32_t out_start;

    if (tivxFlagIsBitSet(obj_desc[TIVX_KERNEL_VPAC_CUC_VISS_RAW_IDX]->flags,
                         TIVX_REF_FLAG_IS_INVALID) == 1U)
    {
        out_start = TIVX_KERNEL_VPAC_CUC_VISS_OUT0_IDX;

        for (cnt = 0U; cnt < TIVX_KERNEL_VPAC_CUC_VISS_MAX_IMAGE_OUTPUT; cnt++)
        {
            if (NULL != obj_desc[out_start])
            {
                tivxFlagBitSet(&obj_desc[out_start]->flags, TIVX_REF_FLAG_IS_INVALID);
            }
            out_start++;
        }
    }
    else
    {
        out_start = TIVX_KERNEL_VPAC_CUC_VISS_OUT0_IDX;

        for (cnt = 0U; cnt < TIVX_KERNEL_VPAC_CUC_VISS_MAX_IMAGE_OUTPUT; cnt++)
        {
            if (NULL != obj_desc[out_start])
            {
                tivxFlagBitClear(&obj_desc[out_start]->flags, TIVX_REF_FLAG_IS_INVALID);
            }
            out_start++;
        }
    }
}


static vx_status vhwaCucRcAllocMemForCtx(tivxVpacCucIspObj *vissObj)
{
    vx_status           status = (vx_status)VX_SUCCESS;
    int32_t             fvid2_status = FVID2_SOK;
    Glbce_Control       glbceCtrl;

    Vhwa_M2mVissParams* vissPrms = (vissObj == NULL) ? NULL : &vissObj->vissPrms;

    if ((NULL != vissObj) && (NULL != vissPrms))
    {
        glbceCtrl.module = GLBCE_MODULE_GET_STATS_INFO;
        glbceCtrl.statsInfo = &vissObj->glbceStatInfo;
        fvid2_status = Fvid2_control(vissObj->handle,
            IOCTL_GLBCE_GET_CONFIG, (void *)&glbceCtrl, NULL);
        if (FVID2_SOK != fvid2_status)
        {
            vissObj->ctx_mem_phys_ptr = 0u;
            status = (vx_status)VX_FAILURE;
            VX_PRINT(VX_ZONE_ERROR, "Failed to get GLBCE Stats Info!!!\n");
        }
        else
        {
            tivxMemBufferAlloc(&vissObj->ctx_mem_ptr,
                vissObj->glbceStatInfo.size, (vx_enum)TIVX_MEM_EXTERNAL);
            if ((int32_t)NULL == (int32_t)vissObj->ctx_mem_ptr.host_ptr)
            {
                vissObj->ctx_mem_phys_ptr = 0u;
                status = (vx_status)VX_ERROR_NO_MEMORY;
                VX_PRINT(VX_ZONE_ERROR, "Failed to allocate memory!!!\n");
            }
            else
            {
                vissObj->ctx_mem_phys_ptr = tivxMemShared2PhysPtr(
                    vissObj->ctx_mem_ptr.shared_ptr,
                    (int32_t)vissObj->ctx_mem_ptr.mem_heap_region);

                VX_PRINT(VX_ZONE_ERROR, "TIOVX: VISS: GLBCE ctx mem @ 0x%08x or size %d B\n", (uint32_t)vissObj->ctx_mem_phys_ptr, vissObj->glbceStatInfo.size);
            }
        }
    }
    else
    {
        status = (vx_status)VX_FAILURE;
    }

    return (status);
}

static void vhwaCucRcFreeCtxMem(tivxVpacCucIspObj *vissObj)
{
    if (NULL != vissObj)
    {
        if (0u != vissObj->ctx_mem_phys_ptr)
        {
            tivxMemBufferFree(&vissObj->ctx_mem_ptr,
                vissObj->glbceStatInfo.size);
            vissObj->ctx_mem_phys_ptr = 0u;
        }
    }
}


/* ========================================================================== */
/*                              OPENVX Callbacks                              */
/* ========================================================================== */

static vx_status VX_CALLBACK tivxVpacCucVissCreate(
    tivx_target_kernel_instance kernel,
    tivx_obj_desc_t *obj_desc[],
    uint16_t num_params, void *priv_arg)
{
    vx_status status = (vx_status)VX_SUCCESS;
    uint32_t cnt;
    tivxVpacCucIspObj *ispObj = NULL;
    tivx_vpac_cuc_isp_params_t *ispPrms = NULL;

    tivx_obj_desc_image_t *img_desc[TIVX_KERNEL_VPAC_CUC_VISS_MAX_IMAGE_OUTPUT];
    tivx_obj_desc_raw_image_t *raw_img_desc =
        (tivx_obj_desc_raw_image_t *)obj_desc[TIVX_KERNEL_VPAC_CUC_VISS_RAW_IDX];
    tivx_obj_desc_user_data_object_t *config_desc =
        (tivx_obj_desc_user_data_object_t *)obj_desc[TIVX_KERNEL_VPAC_CUC_VISS_CONFIGURATION_IDX];
    for (cnt = 0U; cnt < TIVX_KERNEL_VPAC_CUC_VISS_MAX_IMAGE_OUTPUT; cnt++)
    {
        img_desc[cnt] = (tivx_obj_desc_image_t *)
            obj_desc[TIVX_KERNEL_VPAC_CUC_VISS_OUT0_IDX + cnt];
    }

    status = tivxVpacCucMapUserDesc((void **)&ispPrms, config_desc,
                                   sizeof(tivx_vpac_cuc_isp_params_t),
                                   (vx_enum)VX_READ_ONLY);
    if ((vx_status)VX_SUCCESS != status)
    {
        VX_PRINT(VX_ZONE_ERROR, "Failed to Map Parameters Descriptor\n");
    }
    else
    {
        ispObj = &g_cucIspObjs[ispPrms->context_id];

        /* local copy  */
        memcpy((void *)&ispObj->ispPrms, (void *)ispPrms,
               sizeof(tivx_vpac_cuc_isp_params_t));

        tivxVpacCucUnmapUserDesc((void **)&ispPrms, config_desc,
                                (vx_enum)VX_READ_ONLY);

        ispPrms = &ispObj->ispPrms;
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        status = tivxEventCreate(&ispObj->eventProcessCmpl);
        if ((vx_status)VX_SUCCESS != status)
        {
            VX_PRINT(VX_ZONE_ERROR, "Failed to allocate Event\n");
        }
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        status = tivxEventCreate(&ispObj->eventVissCmpl);
        if ((vx_status)VX_SUCCESS != status)
        {
            VX_PRINT(VX_ZONE_ERROR, "Failed to allocate Event\n");
        }
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        status = tivxEventCreate(&ispObj->eventRcCmpl);
        if ((vx_status)VX_SUCCESS != status)
        {
            VX_PRINT(VX_ZONE_ERROR, "Failed to allocate Event\n");
        }
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        Vhwa_M2mVissCreateArgs createArgs;
        Vhwa_m2mVissCreateArgsInit(&createArgs);

        Fvid2_CbParams cbPrms;
        cbPrms.cbFxn = tivxVpacCucVissFrameComplCb;
        cbPrms.appData = ispObj;

        ispObj->handle = Fvid2_create(FVID2_VHWA_M2M_VISS_DRV_ID,
                                      VHWA_M2M_VISS_DRV_INST0, &createArgs, NULL, &cbPrms);
        if (NULL == ispObj->handle)
        {
            VX_PRINT(VX_ZONE_ERROR, "Failed to Open Driver\n");
            status = (vx_status)VX_ERROR_NO_RESOURCES;
        }
    }



    if ((vx_status)VX_SUCCESS == status)
    {
        Vhwa_M2mVissParams *vissDrvPrms = &ispObj->vissPrms;
        Vhwa_m2mVissParamsInit(vissDrvPrms);

        vissDrvPrms->enableGlbce = (uint32_t)TRUE;
        vissDrvPrms->enableNsf4 = (uint32_t)TRUE;
        vissDrvPrms->edgeEnhancerMode = VHWA_M2M_VISS_EE_ON_LUMA8;

        /* Allocate memory for the GLBCE Statistics */
        status = vhwaCucRcAllocMemForCtx(ispObj);

        if ((vx_status)VX_SUCCESS == status)
        {
            tivxVpacVissSetInputParams(ispObj, raw_img_desc);
            status = tivxVpacVissSetOutputParams(ispObj, ispPrms, img_desc);
            if ((vx_status)VX_SUCCESS != status)
            {
                VX_PRINT(VX_ZONE_ERROR, "Failed to set Output Params\n");
            }
        }
        else
        {
            VX_PRINT(VX_ZONE_ERROR, "vhwaCucRcAllocMemForCtx failure\n");
        }
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        status = tivxSetTargetKernelInstanceContext(kernel, ispObj,
                                                    sizeof(tivxVpacCucIspObj));
        if ((vx_status)VX_SUCCESS != status)
        {
            VX_PRINT(VX_ZONE_ERROR, "Failed to set target kernel instance\n");
        }
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        /* Set up the input frame list */
        for (cnt = 0U; cnt < ispObj->num_in_buf; cnt++)
        {
            ispObj->inFrmList.frames[cnt] = &ispObj->inFrm[cnt];
        }
        ispObj->inFrmList.numFrames = ispObj->num_in_buf;

        /* Set up the output frame list */
        for (cnt = 0U; cnt < VHWA_M2M_VISS_MAX_OUTPUTS; cnt++)
        {
            ispObj->outFrmList.frames[cnt] = &ispObj->outFrm[cnt];
        }
        ispObj->outFrmList.numFrames = VHWA_M2M_VISS_MAX_OUTPUTS;
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        for (cnt = 0; cnt < TIVX_VPAC_CUC_CTLVAL_RECORD_COUNT; cnt++)
        {
            ispObj->ctlval_records[cnt].obj_desc_id = 0xffff;
        }
    }

    if ((vx_status)VX_SUCCESS != status)
    {
        if (NULL != ispObj)
        {
            if (NULL != ispObj->handle)
            {
                Fvid2_delete(ispObj->handle, NULL);
                ispObj->handle = NULL;
            }

            if (NULL != ispObj->eventProcessCmpl)
            {
                tivxEventDelete(&ispObj->eventProcessCmpl);
            }
            if (NULL != ispObj->eventRcCmpl)
            {
                tivxEventDelete(&ispObj->eventRcCmpl);
            }
            if (NULL != ispObj->eventVissCmpl)
            {
                tivxEventDelete(&ispObj->eventVissCmpl);
            }
        }

        vhwaCucRcFreeCtxMem(ispObj);

    }

    return (status);
}

static vx_status VX_CALLBACK tivxVpacCucVissDelete(
    tivx_target_kernel_instance kernel,
    tivx_obj_desc_t *obj_desc[],
    uint16_t num_params, void *priv_arg)
{
    vx_status status = (vx_status)VX_SUCCESS;
    uint32_t size;
    tivxVpacCucIspObj *ispObj = NULL;

    status = tivxGetTargetKernelInstanceContext(kernel, (void **)&ispObj,
                                                &size);
    if ((vx_status)VX_SUCCESS != status)
    {
        VX_PRINT(VX_ZONE_ERROR, "Incorrect kernel instance context\n");
    }
    else if ((NULL == ispObj) ||
             (sizeof(tivxVpacCucIspObj) != size))
    {
        VX_PRINT(VX_ZONE_ERROR, "Incorrect Object Size\n");
        status = (vx_status)VX_FAILURE;
    }
    else
    {
        Fvid2_delete(ispObj->handle, NULL);
        ispObj->handle = NULL;

        if (NULL != ispObj->eventProcessCmpl)
        {
            tivxEventDelete(&ispObj->eventProcessCmpl);
        }
        if (NULL != ispObj->eventRcCmpl)
        {
            tivxEventDelete(&ispObj->eventRcCmpl);
        }
        if (NULL != ispObj->eventVissCmpl)
        {
            tivxEventDelete(&ispObj->eventVissCmpl);
        }

        vhwaCucRcFreeCtxMem(ispObj);

    }

    return (status);
}

static void vhwaCucVissRestoreCtx(const tivxVpacCucIspObj *vissObj)
{
    int32_t status;
    app_udma_copy_1d_prms_t prms;

    if ((NULL != vissObj) && (0u != vissObj->ctx_mem_phys_ptr))
    {
        prms.src_addr = vissObj->ctx_mem_phys_ptr;
        prms.dest_addr = vissObj->glbceStatInfo.addr;
        prms.length = vissObj->glbceStatInfo.size;
        status = appUdmaCopy1D(NULL, &prms);

        if (0 != status)
        {
            VX_PRINT(VX_ZONE_ERROR, "Failed to restore Context !!!\n");
        }
    }
}

static void vhwaCucVissSaveCtx(const tivxVpacCucIspObj *vissObj)
{
    int32_t status;
    app_udma_copy_1d_prms_t prms;

    if ((NULL != vissObj) && (0u != vissObj->ctx_mem_phys_ptr))
    {
        prms.src_addr = vissObj->glbceStatInfo.addr;
        prms.dest_addr = vissObj->ctx_mem_phys_ptr;
        prms.length = vissObj->glbceStatInfo.size;
        status = appUdmaCopy1D(NULL, &prms);

        if (0 != status)
        {
            VX_PRINT(VX_ZONE_ERROR, "Failed to restore Context !!!\n");
        }
    }
}

static vx_status VX_CALLBACK tivxVpacCucVissProcess(
    tivx_target_kernel_instance kernel,
    tivx_obj_desc_t *obj_desc[],
    uint16_t num_params, void *priv_arg)
{
    vx_status status = (vx_status)VX_SUCCESS;
    int32_t fvid2_status = FVID2_SOK;
    uint32_t cnt;
    uint32_t buf_cnt;
    uint32_t size;
    tivxVpacCucIspObj *ispObj = NULL;
    uint64_t cur_time;

    tivx_obj_desc_image_t *img_desc[TIVX_KERNEL_VPAC_CUC_VISS_MAX_IMAGE_OUTPUT];
    tivx_obj_desc_raw_image_t *raw_img_desc =
        (tivx_obj_desc_raw_image_t *)obj_desc[TIVX_KERNEL_VPAC_CUC_VISS_RAW_IDX];
    for (cnt = 0U; cnt < TIVX_KERNEL_VPAC_CUC_VISS_MAX_IMAGE_OUTPUT; cnt++)
    {
        img_desc[cnt] = (tivx_obj_desc_image_t *)
            obj_desc[TIVX_KERNEL_VPAC_CUC_VISS_OUT0_IDX + cnt];
    }

    status = tivxGetTargetKernelInstanceContext(kernel, (void **)&ispObj,
                                                &size);
    if ((vx_status)VX_SUCCESS != status)
    {
        VX_PRINT(VX_ZONE_ERROR, "Incorrect kernel instance context\n");
    }
    else if ((NULL == ispObj) || (sizeof(tivxVpacCucIspObj) != size))
    {
        VX_PRINT(VX_ZONE_ERROR, "Incorrect Object Size\n");
        status = (vx_status)VX_FAILURE;
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        tivxVpacVissSetIsInvalidFlag(obj_desc);
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        for (cnt = 0U; cnt < TIVX_KERNEL_VPAC_CUC_VISS_MAX_IMAGE_OUTPUT; cnt++)
        {
            if (ispObj->num_out_buf_addr[cnt])
            {
                tivxVpacCucUnmarkBuffer(ispObj, img_desc[cnt]);
            }
        }
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        for (cnt = 0u; cnt < ispObj->num_in_buf; cnt++)
        {
            ispObj->inFrm[cnt].addr[0u] = tivxMemShared2PhysPtr(
                raw_img_desc->img_ptr[cnt].shared_ptr,
                (int32_t)raw_img_desc->img_ptr[cnt].mem_heap_region);
        }

        for (cnt = 0u; cnt < TIVX_KERNEL_VPAC_CUC_VISS_MAX_IMAGE_OUTPUT; cnt++)
        {
            for (buf_cnt = 0U; buf_cnt < ispObj->num_out_buf_addr[cnt];
                 buf_cnt++)
            {
                ispObj->outFrm[cnt].addr[buf_cnt] = tivxMemShared2PhysPtr(
                    img_desc[cnt]->mem_ptr[buf_cnt].shared_ptr,
                    (int32_t)img_desc[cnt]->mem_ptr[buf_cnt].mem_heap_region);
            }
        }

        ispObj->outFrm[VHWA_M2M_VISS_OUT_H3A_IDX].addr[0u] = (uint64_t)ispObj->h3a_stats_data;
    }

    tivxEventWait(ispObj->eventRcCmpl, TIVX_EVENT_TIMEOUT_WAIT_FOREVER);

    if ((vx_status)VX_SUCCESS == status)
    {
        cur_time = tivxPlatformGetTimeInUsecs();

        vhwaCucVissRestoreCtx(ispObj);

        fvid2_status = Fvid2_processRequest(ispObj->handle, &ispObj->inFrmList,
                                            &ispObj->outFrmList, FVID2_TIMEOUT_FOREVER);
        if (FVID2_SOK != fvid2_status)
        {
            VX_PRINT(VX_ZONE_ERROR, "Failed to Submit Request\n");
            status = (vx_status)VX_FAILURE;
        }
        else
        {
            tivxEventWait(ispObj->eventProcessCmpl,
                          TIVX_EVENT_TIMEOUT_WAIT_FOREVER);

            fvid2_status = Fvid2_getProcessedRequest(ispObj->handle,
                                                     &ispObj->inFrmList, &ispObj->outFrmList, 0);

            if (FVID2_SOK != fvid2_status)
            {
                VX_PRINT(VX_ZONE_ERROR, "Failed to Get Processed Request\n");
                status = (vx_status)VX_FAILURE;
            }
        }

        vhwaCucVissSaveCtx(ispObj);
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        for (cnt = 0U; cnt < TIVX_KERNEL_VPAC_CUC_VISS_MAX_IMAGE_OUTPUT; cnt++)
        {
            if (ispObj->num_out_buf_addr[cnt])
            {
                tivxVpacCucMarkBuffer(ispObj, img_desc[cnt]);
            }
        }
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        tivxEventPost(ispObj->eventVissCmpl);

        cur_time = tivxPlatformGetTimeInUsecs() - cur_time;

        /* appPerfStatsHwaUpdateLoad(APP_PERF_HWA_CUC_VISS, (uint32_t)cur_time, */
        /*                           raw_img_desc->params.width * raw_img_desc->params.height); */
    }

    return (status);
}

static vx_status VX_CALLBACK tivxVpacCucVissControl(
       tivx_target_kernel_instance kernel,
       uint32_t node_cmd_id, tivx_obj_desc_t *obj_desc[],
       uint16_t num_params, void *priv_arg)
{
    vx_status status = VX_SUCCESS;
    tivxVpacCucIspObj *ispObj = NULL;
    uint32_t size;

    status = tivxGetTargetKernelInstanceContext(kernel, (void **)&ispObj,
                                                &size);
    if ((vx_status)VX_SUCCESS != status)
    {
        VX_PRINT(VX_ZONE_ERROR, "Incorrect kernel instance context\n");
    }
    else if ((NULL == ispObj) || (sizeof(tivxVpacCucIspObj) != size))
    {
        VX_PRINT(VX_ZONE_ERROR, "Incorrect Object Size\n");
        status = (vx_status)VX_FAILURE;
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        switch (node_cmd_id)
        {
        case TIVX_VPAC_CUC_RC_CMD_VERIFY_BUFFER:
            if (num_params == 2 &&
                obj_desc[0] && obj_desc[0]->type == TIVX_OBJ_DESC_IMAGE &&
                obj_desc[1] && obj_desc[1]->type == TIVX_OBJ_DESC_USER_DATA_OBJECT &&
                    ((tivx_obj_desc_user_data_object_t *)obj_desc[1])->mem_size >= sizeof(tivx_vpac_cuc_isp_verify_buffer_data_t))
            {
                status = tivxVpacCucVerifyBuffer(ispObj,
                        (tivx_obj_desc_image_t *)obj_desc[0],
                        (tivx_obj_desc_user_data_object_t *)obj_desc[1]);
            }
            else
            {
                VX_PRINT(VX_ZONE_ERROR, "Invalid CMD_VERIFY_BUFFER params");
                status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
            }
            break;
        default:
            VX_PRINT(VX_ZONE_ERROR, "Invalid Node Cmd Id: %d\n", node_cmd_id);
            status = (vx_status)VX_FAILURE;
            break;
        }
    }

    return status;
}

/* ========================================================================== */
/*                          Local Functions                                   */
/* ========================================================================== */

static vx_status tivxVpacVissSetOutputParams(tivxVpacCucIspObj *ispObj,
                                             const tivx_vpac_cuc_isp_params_t *ispPrms,
                                             tivx_obj_desc_image_t *obj_desc[])
{
    vx_status status = (vx_status)VX_SUCCESS;
    uint32_t cnt;
    uint32_t out_cnt;
    uint32_t mux_val[TIVX_KERNEL_VPAC_CUC_VISS_MAX_IMAGE_OUTPUT];
    uint32_t out_start;
    Vhwa_M2mVissOutputParams *outPrms = NULL;
    Vhwa_M2mVissParams *vissDrvPrms;
    tivx_obj_desc_image_t *im_desc;

    mux_val[0U] = ispPrms->mux_output0;
    mux_val[1U] = ispPrms->mux_output1;
    mux_val[2U] = ispPrms->mux_output2;
    mux_val[3U] = ispPrms->mux_output3;
    mux_val[4U] = ispPrms->mux_output4;
    vissDrvPrms = &ispObj->vissPrms;

    out_start = TIVX_KERNEL_VPAC_CUC_VISS_OUT0_IDX;
    for (out_cnt = 0u; out_cnt < TIVX_KERNEL_VPAC_CUC_VISS_MAX_IMAGE_OUTPUT; out_cnt++)
    {
        ispObj->num_out_buf_addr[out_cnt] = 0U;
        im_desc = obj_desc[out_cnt];

        if (NULL != obj_desc[out_cnt])
        {
            outPrms = &vissDrvPrms->outPrms[out_cnt];

            status = tivxVpacVissMapFormat(&outPrms->fmt.dataFormat,
                                           &outPrms->fmt.ccsFormat, out_start,
                                           im_desc->format, mux_val[out_cnt]);
            if ((vx_status)VX_SUCCESS == status)
            {
                outPrms->enable = TRUE;
                outPrms->fmt.width = im_desc->width;
                outPrms->fmt.height = im_desc->height;

                for (cnt = 0u; cnt < TIVX_IMAGE_MAX_PLANES; cnt++)
                {
                    outPrms->fmt.pitch[cnt] =
                        (uint32_t)im_desc->imagepatch_addr[cnt].stride_y;
                }
            }
            else
            {
                VX_PRINT(VX_ZONE_ERROR, "Failed to map format for output%d\n", out_cnt);
            }

            /* TODO: See if there are any others here */
            if ((FVID2_DF_YUV420SP_UV == outPrms->fmt.dataFormat) ||
                (FVID2_DF_YUV422SP_UV == outPrms->fmt.dataFormat))
            {
                ispObj->num_out_buf_addr[out_cnt] = 2U;
            }
            else
            {
                ispObj->num_out_buf_addr[out_cnt] = 1U;
            }
        }

        if ((vx_status)VX_SUCCESS != status)
        {
            break;
        }
        out_start++;
    }

    if ((vx_status)VX_SUCCESS == status)
    {
        outPrms = &vissDrvPrms->outPrms[VHWA_M2M_VISS_OUT_H3A_IDX];
        outPrms->enable = (uint32_t)TRUE;
        outPrms->fmt.dataFormat = FVID2_DF_RAW;
    }

    return (status);
}

static void tivxVpacVissSetInputParams(tivxVpacCucIspObj *ispObj,
                                       const tivx_obj_desc_raw_image_t *raw_img_desc)
{
    Fvid2_Format *fmt;
    Vhwa_M2mVissParams *vissDrvPrms;

    vissDrvPrms = &ispObj->vissPrms;
    fmt = &vissDrvPrms->inFmt;

    /* Set number of inputs */
    if (1U == raw_img_desc->params.num_exposures)
    {
        vissDrvPrms->inputMode = VHWA_M2M_VISS_MODE_SINGLE_FRAME_INPUT;
    }
    else if (2U == raw_img_desc->params.num_exposures)
    {
        vissDrvPrms->inputMode = VHWA_M2M_VISS_MODE_TWO_FRAME_MERGE;
    }
    else if (3U == raw_img_desc->params.num_exposures)
    {
        vissDrvPrms->inputMode = VHWA_M2M_VISS_MODE_THREE_FRAME_MERGE;
    }
    else
    {
        /* do nothing */
    }

    /* Set the Input Format */
    fmt->width = raw_img_desc->params.width;
    fmt->height = raw_img_desc->params.height;
    fmt->pitch[0] = (uint32_t)raw_img_desc->imagepatch_addr[0U].stride_y;
    fmt->dataFormat = FVID2_DF_RAW;

    switch (raw_img_desc->params.format[0U].pixel_container)
    {
    case (vx_enum)TIVX_RAW_IMAGE_8_BIT:
        fmt->ccsFormat = FVID2_CCSF_BITS8_PACKED;
        break;
    case (vx_enum)TIVX_RAW_IMAGE_16_BIT:
        fmt->ccsFormat = FVID2_CCSF_BITS12_UNPACKED16;
        break;
    case (vx_enum)TIVX_RAW_IMAGE_P12_BIT:
        fmt->ccsFormat = FVID2_CCSF_BITS12_PACKED;
        break;
    default:
        /* do nothing */
        break;
    }

    ispObj->num_in_buf = 1u;
    switch (vissDrvPrms->inputMode)
    {
    case VHWA_M2M_VISS_MODE_SINGLE_FRAME_INPUT:
        ispObj->num_in_buf = 1u;
        break;
    case VHWA_M2M_VISS_MODE_TWO_FRAME_MERGE:
        ispObj->num_in_buf = 2u;
        break;
    case VHWA_M2M_VISS_MODE_THREE_FRAME_MERGE:
        ispObj->num_in_buf = 3u;
        break;
    default:
        ispObj->num_in_buf = 1u;
        break;
    }

    return;
}

static vx_status tivxVpacVissMapStorageFormat(uint32_t *ccsFmt, uint32_t vxFmt)
{
    vx_status status = (vx_status)VX_SUCCESS;

    if ((vx_df_image)VX_DF_IMAGE_U16 == vxFmt)
    {
        *ccsFmt = FVID2_CCSF_BITS12_UNPACKED16;
    }
    else if ((vx_df_image)TIVX_DF_IMAGE_P12 == vxFmt)
    {
        *ccsFmt = FVID2_CCSF_BITS12_PACKED;
    }
    else if ((vx_df_image)VX_DF_IMAGE_U8 == vxFmt)
    {
        *ccsFmt = FVID2_CCSF_BITS8_PACKED;
    }
    else
    {
        VX_PRINT(VX_ZONE_ERROR, "Invalid Storage Format \n");
        status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
    }

    return (status);
}

static vx_status tivxVpacVissMapFormat(uint32_t *fmt, uint32_t *ccsFmt,
                                       uint32_t out_id, uint32_t vxFmt, uint32_t mux_val)
{
    vx_status status = (vx_status)VX_SUCCESS;

    switch (mux_val)
    {
    case 0U:
    {
        /* Map single plane storage format */
        status = tivxVpacVissMapStorageFormat(ccsFmt, vxFmt);

        if ((vx_status)VX_SUCCESS != status)
        {
            VX_PRINT(VX_ZONE_ERROR, "Map Storage Format Failed\n");
        }
        /* Map data format on mux val0 */
        else if ((TIVX_KERNEL_VPAC_CUC_VISS_OUT0_IDX == out_id) ||
                 (TIVX_KERNEL_VPAC_CUC_VISS_OUT2_IDX == out_id))
        {
            *fmt = FVID2_DF_LUMA_ONLY;
        }
        else if ((TIVX_KERNEL_VPAC_CUC_VISS_OUT1_IDX == out_id) ||
                 (TIVX_KERNEL_VPAC_CUC_VISS_OUT3_IDX == out_id))
        {
            *fmt = FVID2_DF_CHROMA_ONLY;
        }
        else
        {
            VX_PRINT(VX_ZONE_ERROR, "mux0 not supported on output4\n");
            status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
        }
        break;
    }
    case 1U:
    {
        /* Map single plane storage format */
        status = tivxVpacVissMapStorageFormat(ccsFmt, vxFmt);

        if ((vx_status)VX_SUCCESS != status)
        {
            VX_PRINT(VX_ZONE_ERROR, "Map Storage Format Failed\n");
        }
        /* Map data format on mux val1 */
        else if (TIVX_KERNEL_VPAC_CUC_VISS_OUT2_IDX == out_id)
        {
            *fmt = FVID2_DF_RED;
        }
        else if (TIVX_KERNEL_VPAC_CUC_VISS_OUT3_IDX == out_id)
        {
            *fmt = FVID2_DF_GREEN;
        }
        else if (TIVX_KERNEL_VPAC_CUC_VISS_OUT4_IDX == out_id)
        {
            *fmt = FVID2_DF_BLUE;
        }
        else
        {
            VX_PRINT(VX_ZONE_ERROR, "mux1 not supported on output0/1\n");
            status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
        }
        break;
    }
    case 2U:
    {
        /* Map single plane storage format */
        status = tivxVpacVissMapStorageFormat(ccsFmt, vxFmt);

        if ((vx_status)VX_SUCCESS != status)
        {
            VX_PRINT(VX_ZONE_ERROR, "Map Storage Format Failed\n");
        }
        /* Map data format on mux val2 */
        else if ((TIVX_KERNEL_VPAC_CUC_VISS_OUT1_IDX == out_id) ||
                 (TIVX_KERNEL_VPAC_CUC_VISS_OUT2_IDX == out_id) ||
                 (TIVX_KERNEL_VPAC_CUC_VISS_OUT3_IDX == out_id) ||
                 (TIVX_KERNEL_VPAC_CUC_VISS_OUT4_IDX == out_id))
        {
            *fmt = FVID2_DF_RAW;
        }
        else
        {
            VX_PRINT(VX_ZONE_ERROR, "mux2 not supported on output0\n");
            status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
        }
        break;
    }
    case 3U:
    {
        /* Map single plane storage format */
        status = tivxVpacVissMapStorageFormat(ccsFmt, vxFmt);

        if ((vx_status)VX_SUCCESS != status)
        {
            VX_PRINT(VX_ZONE_ERROR, "Map Storage Format Failed\n");
        }
        /* Map data format on mux val2 */
        else if ((TIVX_KERNEL_VPAC_CUC_VISS_OUT0_IDX == out_id) ||
                 (TIVX_KERNEL_VPAC_CUC_VISS_OUT2_IDX == out_id))
        {
            *fmt = FVID2_DF_GREY;
        }
        else if (TIVX_KERNEL_VPAC_CUC_VISS_OUT4_IDX == out_id)
        {
            *fmt = FVID2_DF_SATURATION;
        }
        else
        {
            VX_PRINT(VX_ZONE_ERROR, "mux3 not supported on output1/3\n");
            status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
        }
        break;
    }
    case 4U:
    {
        if ((vx_df_image)VX_DF_IMAGE_NV12 == vxFmt)
        {
            *ccsFmt = FVID2_CCSF_BITS8_PACKED;
        }
        else if ((vx_df_image)TIVX_DF_IMAGE_NV12_P12 == vxFmt)
        {
            *ccsFmt = FVID2_CCSF_BITS12_PACKED;
        }
        else
        {
            VX_PRINT(VX_ZONE_ERROR, "only NV12 supported on mux4\n");
            status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
        }

        if ((vx_status)VX_SUCCESS == status)
        {
            if ((TIVX_KERNEL_VPAC_CUC_VISS_OUT0_IDX == out_id) ||
                (TIVX_KERNEL_VPAC_CUC_VISS_OUT2_IDX == out_id))
            {
                *fmt = FVID2_DF_YUV420SP_UV;
            }
            else
            {
                VX_PRINT(VX_ZONE_ERROR, "only output0/2 supports on mux4\n");
                status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
            }
        }
        break;
    }
    case 5U:
    {
        *ccsFmt = FVID2_CCSF_BITS8_PACKED;

        if (TIVX_KERNEL_VPAC_CUC_VISS_OUT2_IDX == out_id)
        {
            if ((vx_df_image)VX_DF_IMAGE_UYVY == vxFmt)
            {
                *fmt = FVID2_DF_YUV422I_UYVY;
            }
            else if ((vx_df_image)VX_DF_IMAGE_YUYV == vxFmt)
            {
                *fmt = FVID2_DF_YUV422I_YUYV;
            }
            else
            {
                VX_PRINT(VX_ZONE_ERROR, "only UYVY/YUYV formats supported \n");
                status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
            }
        }
        else
        {
            VX_PRINT(VX_ZONE_ERROR, "mux5 is supported only on output2 \n");
            status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
        }
        break;
    }
    default:
    {
        VX_PRINT(VX_ZONE_ERROR, "Invalid value of mux \n");
        status = (vx_status)VX_ERROR_INVALID_PARAMETERS;
        break;
    }
    }

    return (status);
}

static inline uint8_t encodeCtlValBits(uint8_t hexdigit)
{
    /* Split 220 into 16 equal areas, return the middle of one corresponding to hexdigit
     *
     * Since 220 does not divide to 16, scale 4x up.
     * (220 * 4) / 16 = 55
     */
    return (0x40 + hexdigit * 55 + 27) >> 2;
}

static inline uint8_t decodeCtlValBits(uint8_t byte)
{
    return (byte - 0x10) / 0xe;
}

static inline uint8_t *mapCtlValPlaneArea(tivx_obj_desc_image_t *img_desc,
                                          uint8_t plane)
{
    uint8_t *p;

    /* Use last 4 bytes of the first line */
    p = ((uint8_t *)tivxMemShared2TargetPtr(&img_desc->mem_ptr[plane])) +
            img_desc->imagepatch_addr[plane].stride_y - 4;

    tivxMemBufferMap(p, 4, (vx_enum)VX_MEMORY_TYPE_HOST, (vx_enum)VX_WRITE_ONLY);

    return p;
}

static inline void unmapCtlValPlaneArea(uint8_t *p)
{
    tivxMemBufferUnmap(p, 4, (vx_enum)VX_MEMORY_TYPE_HOST, (vx_enum)VX_WRITE_ONLY);
}

static void tivxVpacCucMarkBuffer(tivxVpacCucIspObj *ispObj,
                                  tivx_obj_desc_image_t *img_desc)
{
    uint16_t ctlval;
    uint8_t *p;
    uint32_t cnt;
    ctlval_record_t record, record2;

    /* Use a random value as ctlval */
    ctlval = rand();
    /* Never use zero as ctlval) */
    if (ctlval == 0)
        ctlval = 1;

    /* Save ctlval in last 4 bytes of the first line of the first plane,
     * using 4 most significant bits per byte. GPU can introduce some buzz
     * while copying, so lower bits could break */
    p = mapCtlValPlaneArea(img_desc, 0);
    *(p + 0) = encodeCtlValBits((ctlval >>  0) & 0xF);
    *(p + 1) = encodeCtlValBits((ctlval >>  4) & 0xF);
    *(p + 2) = encodeCtlValBits((ctlval >>  8) & 0xF);
    *(p + 3) = encodeCtlValBits((ctlval >> 12) & 0xF);
    unmapCtlValPlaneArea(p);

    /* For U and V planes, write 0x80 to last 4 bytes of the first line, to
     * assist on-GPU ctlval copying procedure */
    for (cnt = 1; cnt < img_desc->planes; cnt++)
    {
        p = mapCtlValPlaneArea(img_desc, cnt);
        *(uint32_t *)p = 0x80808080;
        unmapCtlValPlaneArea(p);
    }

    /* Save ctlval for this buffer in ispObj->ctlval_records, keep LRU order */
    record.obj_desc_id = img_desc->base.obj_desc_id;
    record.ctlval = ctlval;
    record.verified = 0;
    for (cnt = 0; cnt < TIVX_VPAC_CUC_CTLVAL_RECORD_COUNT; cnt++)
    {
        record2 = ispObj->ctlval_records[cnt];
        ispObj->ctlval_records[cnt] = record;
        record = record2;
        if (record.obj_desc_id == img_desc->base.obj_desc_id)
        {
            /* Reached old position of this buffer in ctlval_records[] */
            if (record.verified == 0)
            {
                /* ctlval got overwritten without even been verified */
                //VX_PRINT(VX_ZONE_ERROR, "ctlval for a buffer was overwritten before verification\n");
            }
            break;
        }
        if (record.obj_desc_id == 0xffff)
        {
            /* Reached end of used part of ctlval_records[] */
            break;
        }
    }
}

static void tivxVpacCucSubmitVerifyBufferResult(tivxVpacCucIspObj *ispObj,
                                                uint16_t group_id, bool result)
{
    /* Verifications are for individual ctlvals, but the logic is in terms of frames.
     *
     * Here at mcu2_0 there is no easy way to detect which verifications belong
     * to the same frame. The source of that information is at a-core side: which
     * buffers have been used together. But, a-core is untrusted.
     *
     * Solution:
     * - a-core sends group_id value, group_id is the same for verifications that
     *   belong to the same frame
     *   - this value is untrusted
     *     - can get same value for different frames
     *     - can get different values for same frame
     * - at mcu2_0 size, trying to "merge" verifications with the same group
     *   - that means, assume errors with the same group_id as single error
     * - for reliability, must not "merge" from different frames (if doing so,
     *   will loose erratic frames); the reverse is less important
     *   - to avoid merging from different frames, detect the same group_id
     *     repeating for particular ispObj, and avoid merging with any past in
     *     that case
     */

    /* 4 erratic frames to set error
     * 12 ok frames (with no errors in between) to clear error and reset counter */
    static const unsigned int set_error_state_thres = 4;
    static const unsigned int clr_error_state_thres = 12;

    static unsigned int error_counter = 0;      /* counts up to set_error_state_thres */
    static unsigned int ok_counter = 0;         /* counts up to clr_error_state_thres when error_counter is nonzero,
                                                   cleared on any single error */

    static uint16_t curr_group_id;
    static uint16_t curr_group_id_valid = false;
    static bool curr_group_error;               /* if error was already accounted for the current group */

    static bool error_state = false;            /* if entered error state */

    static uint16_t prev_group_id_for_inst[VHWA_M2M_VISS_MAX_HANDLES];
    static uint16_t prev_group_id_for_inst_valid[VHWA_M2M_VISS_MAX_HANDLES];

    unsigned long obj_id;
    unsigned int i;
    
    obj_id = ispObj - &g_cucIspObjs[0];
    if (obj_id >= VHWA_M2M_VISS_MAX_HANDLES)
    {
        VX_PRINT(VX_ZONE_ERROR, "bad ispObj\n");
        return;
    }

    if (prev_group_id_for_inst_valid[obj_id] && prev_group_id_for_inst[obj_id] == group_id)
    {
        /* group_id repeated for the same object - assume new group and invalidate saved group_ids */
        curr_group_id_valid = false;
        for (i = 0; i < VHWA_M2M_VISS_MAX_HANDLES; i++)
        {
            prev_group_id_for_inst_valid[i] = false;
        }
    }

    prev_group_id_for_inst[obj_id] = group_id;
    prev_group_id_for_inst_valid[obj_id] = true;

    if (!curr_group_id_valid || (curr_group_id != group_id))
    {
        /* new group_id */
        if (curr_group_id_valid && !curr_group_error)
        {
            /* all calls for old curr_group have been without errors - frame was ok */
            if (error_counter > 0)
            {
                ok_counter++;
                if (ok_counter == clr_error_state_thres)
                {
                    if (error_state)
                    {
                        VX_PRINT(VX_ZONE_ERROR, "CLEAR ERROR STATE\n");
                        error_state = false;
                        image_buffer_mark_err_report(error_state);

                    }
                    error_counter = 0;
                    ok_counter = 0;
                }
            }
        }
        curr_group_id = group_id;
        curr_group_id_valid = true;
        curr_group_error = false;
    }

    if (result == false && curr_group_error == false)
    {
        /* first error for the current group_id detected */
        curr_group_error = true;
        if (error_counter < set_error_state_thres) {
            ok_counter = 0;
            error_counter++;
            if (error_counter == set_error_state_thres) {
                VX_PRINT(VX_ZONE_ERROR, "SET ERROR STATE\n");
                error_state = true;
                image_buffer_mark_err_report(error_state);
            }
        }
    }
}

static vx_status tivxVpacCucVerifyBuffer(tivxVpacCucIspObj *ispObj,
                                         tivx_obj_desc_image_t *img_desc,
                                         tivx_obj_desc_user_data_object_t *verify_desc)
{
    vx_status status = (vx_status)VX_SUCCESS;
    tivx_vpac_cuc_isp_verify_buffer_data_t *data;
    uint16_t user_ctlval;
    uint16_t group_id;
    uint8_t *p;
    uint16_t ctlval_from_buffer;
    uint32_t cnt;
    uint16_t saved_ctlval;
    bool result = true;

    /* Extract given ctlval from verify_desc */
    data = (tivx_vpac_cuc_isp_verify_buffer_data_t *)tivxMemShared2TargetPtr(&verify_desc->mem_ptr);
    tivxMemBufferMap(data, sizeof(*data), (vx_enum)VX_MEMORY_TYPE_HOST, (vx_enum)VX_READ_ONLY);
    user_ctlval = data->ctlval;
    group_id = data->group_id;
    tivxMemBufferUnmap(data, sizeof(*data), (vx_enum)VX_MEMORY_TYPE_HOST, (vx_enum)VX_READ_ONLY);

    /* Extract ctlval from buffer */
    p = mapCtlValPlaneArea(img_desc, 0);
    ctlval_from_buffer = (decodeCtlValBits(*(p + 0)) <<  0) |
                         (decodeCtlValBits(*(p + 1)) <<  4) |
                         (decodeCtlValBits(*(p + 2)) <<  8) |
                         (decodeCtlValBits(*(p + 3)) << 12);
    unmapCtlValPlaneArea(p);

    /* Extract saved ctlval from ispObj->ctlval_records */
    for (cnt = 0; cnt < TIVX_VPAC_CUC_CTLVAL_RECORD_COUNT; cnt++)
    {
        if (ispObj->ctlval_records[cnt].obj_desc_id == img_desc->base.obj_desc_id)
        {
            saved_ctlval = ispObj->ctlval_records[cnt].ctlval;
            break;
        }
    }

    /* Verification */

    if (cnt == TIVX_VPAC_CUC_CTLVAL_RECORD_COUNT)
    {
        /* This buffer was not found in ispObj->ctlval_records[] LRU list.
         *
         * Any buffer that goes through tivxVpacCucVissProcess(), gets passed
         * to tivxVpacCucMarkBuffer() before returning, and is recorded to
         * ctlval_records[] there.
         *
         * If control appeared at this error path, it means that either:
         * (1) a buffer passed to VERIFY_BUFFER was never given to this VpacCuc
         *     instance for filling, or
         * (2) too many other *different* buffers have been passed to this VpacCuc
         *     for filling since this buffer was last passed, or
         * (3) mcu internal data structrure got broken.
         *
         * (1) or (2) means that applicaion side buffer management works wrong.
         */
        VX_PRINT(VX_ZONE_ERROR, "no internally saved ctlval for the buffer\n");
        status = (vx_status)VX_FAILURE;
    }
    else
    {
        ispObj->ctlval_records[cnt].verified = 1;

        if (saved_ctlval != ctlval_from_buffer)
        {
            /* The buffer mark read from buffer does not match saved buffer mark.
             *
             * This means that either:
             * (1) verification was called too late, the current buffer was
             *     already given back for refilling, or
             * (2) buffer mark inside buffer was broken by somebody, or
             * (3) mcu intenal data structure got broken.
             */
            //VX_PRINT(VX_ZONE_ERROR, "ctlval saved internally differs from ctlval saved the buffer\n");
            result = false;
        }
        else if (saved_ctlval != user_ctlval)
        {
            /* Saved ctlvals look sane, but application passed a different ctlval.
             *
             * This means that either:
             * (1) GPU worked with wrong buffer, or
             * (2) GPU failed to copy ctlval properly, or
             * (3) application failed to pass ctlval copied by GPU.
             */
            //VX_PRINT(VX_ZONE_ERROR, "ctlval verification failed\n");
            result = false;
        }
    }

    if (status == (vx_status)VX_SUCCESS)
    {
        tivxVpacCucSubmitVerifyBufferResult(ispObj, group_id, result);
    }

    return status;
}

static void tivxVpacCucUnmarkBuffer(tivxVpacCucIspObj *ispObj,
                                    tivx_obj_desc_image_t *img_desc)
{
    uint8_t *p;

    /* Clear the area of the buffer */
    p = mapCtlValPlaneArea(img_desc, 0);
    *(uint32_t *)p = 0x00000000;
    unmapCtlValPlaneArea(p);
}

/* ========================================================================== */
/*                    Control Command Implementation                          */
/* ========================================================================== */

/* ========================================================================== */
/*                              Driver Callbacks                              */
/* ========================================================================== */

int32_t tivxVpacCucVissFrameComplCb(Fvid2_Handle handle, void *appData)
{
    tivxVpacCucIspObj *ispObj = (tivxVpacCucIspObj *)appData;

    if (NULL != ispObj)
    {
        tivxEventPost(ispObj->eventProcessCmpl);
    }

    return FVID2_SOK;
}
