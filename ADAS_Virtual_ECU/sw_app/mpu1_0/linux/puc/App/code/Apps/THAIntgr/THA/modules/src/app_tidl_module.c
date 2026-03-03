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
#include "app_tidl_module.h"
#include "platform/stdlib/ME_Debugger.h"

#define COMPUTE_CHECKSUM

static vx_user_data_object readConfig(vx_context context, vx_char *config_file, uint32_t *num_input_tensors, uint32_t *num_output_tensors, vx_uint8 *check_sum);
static vx_user_data_object readNetwork(vx_context context, vx_char *network_file, vx_uint8 *check_sum);
static vx_status setCreateParams(vx_context context, vx_user_data_object createParams);
static vx_status setInArgs(vx_context context, vx_user_data_object inArgs);
static vx_status setOutArgs(vx_context context, vx_user_data_object outArgs);
static void createOutputTensors(vx_context context, vx_user_data_object config, vx_tensor output_tensors[]);
#if 0 // Not used
static void initParam(vx_reference params[], uint32_t _max_params);
static void addParam(vx_reference params[], vx_reference obj);
#endif
#ifdef COMPUTE_CHECKSUM
static void getQC(uint8_t *pIn, uint8_t *pOut, int32_t inSize);
#endif
static vx_status updateChecksums(vx_user_data_object config, vx_uint8 *config_checksum, vx_uint8 *network_checksum);

static uint32_t num_params;
static uint32_t max_params;

vx_status app_init_tidl(vx_context context, TIDLObj *tidlObj, char *objName, vx_int32 num_cameras)
{
  vx_status status = VX_SUCCESS;

  vx_uint32 num_input_tensors = 0;
  vx_uint32 num_output_tensors = 0;

  vx_tensor output_tensors[APP_MODULES_MAX_TENSORS];
  vx_uint32 capacity;
  vx_uint32 i;

  tidlObj->kernel = NULL;

  tidlObj->config = readConfig(context, &tidlObj->config_file_path[0], &num_input_tensors, &num_output_tensors, &tidlObj->config_checksum[0]);
  status = vxGetStatus((vx_reference) tidlObj->config);

  tidlObj->num_input_tensors = num_input_tensors;
  tidlObj->num_output_tensors = num_output_tensors;

  if (status == VX_SUCCESS)
  {
    tidlObj->network = readNetwork(context, &tidlObj->network_file_path[0], &tidlObj->network_checksum[0]);
    status = vxGetStatus((vx_reference) tidlObj->network);
  }

  if (status == VX_SUCCESS)
  {
    status = updateChecksums(tidlObj->config, &tidlObj->config_checksum[0], &tidlObj->network_checksum[0]);
  }

  if (status == VX_SUCCESS)
  {
    capacity = sizeof(TIDL_CreateParams);
    tidlObj->createParams = vxCreateUserDataObject(context, "TIDL_CreateParams", capacity, NULL);
    status = setCreateParams(context, tidlObj->createParams);
  }

  if (status == VX_SUCCESS)
  {
    vx_user_data_object inArgs;

    capacity = sizeof(TIDL_InArgs);
    inArgs = vxCreateUserDataObject(context, "TIDL_InArgs", capacity, NULL);
    tidlObj->in_args_arr = vxCreateObjectArray(context, (vx_reference) inArgs, num_cameras);
    vxReleaseUserDataObject(&inArgs);

    for (i = 0; i < (vx_uint32)num_cameras; i++)
    {
      vx_user_data_object inArgs;

      inArgs = (vx_user_data_object) vxGetObjectArrayItem(tidlObj->in_args_arr, i);
      setInArgs(context, inArgs);
      vxReleaseUserDataObject(&inArgs);
    }
  }

  if (status == VX_SUCCESS)
  {
    vx_user_data_object outArgs;

    capacity = sizeof(TIDL_outArgs);
    outArgs = vxCreateUserDataObject(context, "TIDL_outArgs", capacity, NULL);
    tidlObj->out_args_arr = vxCreateObjectArray(context, (vx_reference) outArgs, num_cameras);
    vxReleaseUserDataObject(&outArgs);

    for (i = 0; i < (vx_uint32)num_cameras; i++)
    {
      vx_user_data_object outArgs;

      outArgs = (vx_user_data_object) vxGetObjectArrayItem(tidlObj->out_args_arr, i);
      setOutArgs(context, outArgs);
      vxReleaseUserDataObject(&outArgs);
    }
  }

  for (i = 0; i < APP_MODULES_MAX_TENSORS; i++)
  {
    tidlObj->output_tensor_arr[i] = NULL;
  }

  createOutputTensors(context, tidlObj->config, output_tensors);

  for (i = 0; i < num_output_tensors; i++)
  {
    tidlObj->output_tensor_arr[i] = vxCreateObjectArray(context, (vx_reference) output_tensors[i], num_cameras);
    vxReleaseTensor(&output_tensors[i]);
  }

  if (status == VX_SUCCESS)
  {
    tidlObj->kernel = tivxAddKernelTIDL(context, tidlObj->num_input_tensors, tidlObj->num_output_tensors);
    status = vxGetStatus((vx_reference) tidlObj->kernel);
  }

  snprintf(tidlObj->objName, APP_MODULES_MAX_OBJ_NAME_SIZE, "%s", objName);

  return status;
}

void app_deinit_tidl(TIDLObj *tidlObj)
{
  vx_uint32 i;

  vxReleaseUserDataObject(&tidlObj->config);
  vxReleaseUserDataObject(&tidlObj->network);
  vxReleaseUserDataObject(&tidlObj->createParams);

  vxReleaseObjectArray(&tidlObj->in_args_arr);
  vxReleaseObjectArray(&tidlObj->out_args_arr);

  for (i = 0; i < tidlObj->num_output_tensors; i++)
  {
    vxReleaseObjectArray(&tidlObj->output_tensor_arr[i]);
  }
}

void app_delete_tidl(TIDLObj *tidlObj)
{
  if (tidlObj->node != NULL)
  {
    vxReleaseNode(&tidlObj->node);
  }
  if (tidlObj->kernel != NULL)
  {
    vxRemoveKernel(tidlObj->kernel);
  }
}
static vx_user_data_object readConfig(vx_context context, vx_char *config_file, vx_uint32 *num_input_tensors, vx_uint32 *num_output_tensors, vx_uint8 *check_sum)
{
  vx_status status = VX_SUCCESS;

  vx_user_data_object config = NULL;
  tivxTIDLJ7Params *tidlParams;
  sTIDL_IOBufDesc_t *ioBufDesc;
  vx_uint32 capacity;
  vx_map_id map_id;
  vx_size read_count;

  FILE *fp_config;

  fp_config = fopen(config_file, "rb");

  if (fp_config == NULL)
  {
    ME_Debugger_F_Printf_v("Unable to open file! %s \n", config_file);
    return NULL ;
  }

  fseek(fp_config, 0, SEEK_END);
  capacity = ftell(fp_config);
  fseek(fp_config, 0, SEEK_SET);

  if (capacity != sizeof(sTIDL_IOBufDesc_t))
  {
    ME_Debugger_F_Printf_v("Config file size (%d bytes) does not match size of sTIDL_IOBufDesc_t (%d bytes)\n", capacity, (vx_uint32) sizeof(sTIDL_IOBufDesc_t));
    fclose(fp_config);
    return NULL ;
  }

  status = vxGetStatus((vx_reference) context);

  if (VX_SUCCESS == status)
  {
    config = vxCreateUserDataObject(context, "tivxTIDLJ7Params", sizeof(tivxTIDLJ7Params), NULL);
    status = vxGetStatus((vx_reference) config);

    if (VX_SUCCESS == status)
    {
      vxMapUserDataObject(config, 0, sizeof(tivxTIDLJ7Params), &map_id,
          (void**) &tidlParams, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST, 0);

      if (tidlParams == NULL)
      {
        ME_Debugger_F_Printf_v("Map of config object failed\n");
        fclose(fp_config);
        return NULL ;
      }

      tivx_tidl_j7_params_init(tidlParams);

      ioBufDesc = (sTIDL_IOBufDesc_t*) &tidlParams->ioBufDesc;

      read_count = fread(ioBufDesc, capacity, 1, fp_config);
      if (read_count != 1)
      {
        ME_Debugger_F_Printf_v("Unable to read file %s \n", config_file);
      }

      *num_input_tensors = ioBufDesc->numInputBuf;
      *num_output_tensors = ioBufDesc->numOutputBuf;

#ifdef COMPUTE_CHECKSUM
      tidlParams->compute_config_checksum = 0;
      tidlParams->compute_network_checksum = 1;
#endif
      vxUnmapUserDataObject(config, map_id);
    }
  }
  fclose(fp_config);

  return config;
}

static vx_user_data_object readNetwork(vx_context context, vx_char *network_file, vx_uint8 *check_sum)
{
  vx_status status = VX_SUCCESS;

  vx_user_data_object network;
  vx_map_id map_id;
  vx_uint32 capacity;
  vx_size read_count;
  void *network_buffer = NULL;

  FILE *fp_network;

  fp_network = fopen(network_file, "rb");

  if (fp_network == NULL)
  {
    ME_Debugger_F_Printf_v("Unable to open file! %s \n", network_file);
    return NULL ;
  }

  fseek(fp_network, 0, SEEK_END);
  capacity = ftell(fp_network);
  fseek(fp_network, 0, SEEK_SET);

  network = vxCreateUserDataObject(context, "TIDL_network", capacity, NULL);
  status = vxGetStatus((vx_reference) network);

  if (VX_SUCCESS == status)
  {
    vxMapUserDataObject(network, 0, capacity, &map_id,
        (void**) &network_buffer, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST, 0);

    if (network_buffer)
    {
      read_count = fread(network_buffer, capacity, 1, fp_network);
      if (read_count != 1)
      {
        ME_Debugger_F_Printf_v("Unable to read file!\n");
      }
#ifdef COMPUTE_CHECKSUM
      sTIDL_Network_t *pNet = (sTIDL_Network_t*) network_buffer;
      if (pNet->dataFlowInfo < (int32_t)capacity)
      {
        uint8_t *pPerfInfo = (uint8_t*) network_buffer + pNet->dataFlowInfo;
        //ME_Debugger_F_Printf_v("Computing checksum at 0x%016lX, size = %d\n", (uint64_t) pPerfInfo, capacity - pNet->dataFlowInfo);
        getQC(pPerfInfo, check_sum, capacity - pNet->dataFlowInfo);
      }
      else
      {
        ME_Debugger_F_Printf_v("ERROR: pNet->dataFlowInfo should be less than %d\n", capacity);
      }
#endif
    }
    else
    {
      ME_Debugger_F_Printf_v("Unable to allocate memory for reading network! %d bytes\n", capacity);
    }

    vxUnmapUserDataObject(network, map_id);
  }

  fclose(fp_network);

  return network;
}

static vx_status updateChecksums(vx_user_data_object config, vx_uint8 *config_checksum, vx_uint8 *network_checksum)
{
  vx_status status = VX_SUCCESS;

  tivxTIDLJ7Params *tidlParams;
  vx_map_id map_id;

  vxMapUserDataObject(config, 0, sizeof(tivxTIDLJ7Params), &map_id,
      (void**) &tidlParams, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST, 0);

  if (tidlParams != NULL)
  {
    memcpy(tidlParams->config_checksum, config_checksum, TIVX_TIDL_J7_CHECKSUM_SIZE);
    memcpy(tidlParams->network_checksum, network_checksum, TIVX_TIDL_J7_CHECKSUM_SIZE);
  }
  else
  {
    ME_Debugger_F_Printf_v("Unable to copy checksums!\n");
    status = VX_FAILURE;
  }

  vxUnmapUserDataObject(config, map_id);

  return status;
}
static vx_status setCreateParams(vx_context context, vx_user_data_object createParams)
{
  vx_status status = VX_SUCCESS;
  vx_map_id map_id;
  vx_uint32 capacity;
  void *createParams_buffer = NULL;

  status = vxGetStatus((vx_reference) createParams);

  if (VX_SUCCESS == status)
  {
    capacity = sizeof(TIDL_CreateParams);
    vxMapUserDataObject(createParams, 0, capacity, &map_id,
        (void**) &createParams_buffer, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST, 0);

    if (createParams_buffer)
    {
      TIDL_CreateParams *prms = createParams_buffer;
      //write create params here
      TIDL_createParamsInit(prms);

      prms->isInbufsPaded = 1;
      prms->quantRangeExpansionFactor = 1.0;
      prms->quantRangeUpdateFactor = 0.0;
      prms->traceLogLevel = 0;
      prms->traceWriteLevel = 0;
    }
    else
    {
      ME_Debugger_F_Printf_v("Unable to allocate memory for create time params! %d bytes\n", capacity);
    }

    vxUnmapUserDataObject(createParams, map_id);
  }

  return status;
}

static vx_status setInArgs(vx_context context, vx_user_data_object inArgs)
{
  vx_status status = VX_SUCCESS;

  vx_map_id map_id;
  vx_uint32 capacity;
  void *inArgs_buffer = NULL;

  status = vxGetStatus((vx_reference) inArgs);

  if (VX_SUCCESS == status)
  {
    capacity = sizeof(TIDL_InArgs);
    vxMapUserDataObject(inArgs, 0, capacity, &map_id,
        (void**) &inArgs_buffer, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST, 0);

    if (inArgs_buffer)
    {
      TIDL_InArgs *prms = inArgs_buffer;
      prms->iVisionInArgs.size = sizeof(TIDL_InArgs);
      prms->iVisionInArgs.subFrameInfo = 0;
    }
    else
    {
      ME_Debugger_F_Printf_v("Unable to allocate memory for inArgs! %d bytes\n", capacity);
    }

    vxUnmapUserDataObject(inArgs, map_id);
  }

  return status;
}

static vx_status setOutArgs(vx_context context, vx_user_data_object outArgs)
{
  vx_status status = VX_SUCCESS;

  vx_map_id map_id;
  vx_uint32 capacity;
  void *outArgs_buffer = NULL;

  status = vxGetStatus((vx_reference) outArgs);

  if (VX_SUCCESS == status)
  {
    capacity = sizeof(TIDL_outArgs);
    vxMapUserDataObject(outArgs, 0, capacity, &map_id,
        (void**) &outArgs_buffer, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST, 0);

    if (outArgs_buffer)
    {
      TIDL_outArgs *prms = outArgs_buffer;
      prms->iVisionOutArgs.size = sizeof(TIDL_outArgs);
    }
    else
    {
      ME_Debugger_F_Printf_v("Unable to allocate memory for outArgs! %d bytes\n", capacity);
    }

    vxUnmapUserDataObject(outArgs, map_id);
  }

  return status;
}

static void createOutputTensors(vx_context context, vx_user_data_object config, vx_tensor output_tensors[])
{
  vx_size output_sizes[APP_MODULES_MAX_TENSOR_DIMS];
  vx_map_id map_id_config;

  vx_uint32 id;

  tivxTIDLJ7Params *tidlParams;
  sTIDL_IOBufDesc_t *ioBufDesc;

  vxMapUserDataObject(config, 0, sizeof(tivxTIDLJ7Params), &map_id_config,
      (void**) &tidlParams, VX_READ_ONLY, VX_MEMORY_TYPE_HOST, 0);

  ioBufDesc = (sTIDL_IOBufDesc_t*) &tidlParams->ioBufDesc;
  for (id = 0; id < (vx_uint32)ioBufDesc->numOutputBuf; id++)
  {
    output_sizes[0] = ioBufDesc->outWidth[id] + ioBufDesc->outPadL[id] + ioBufDesc->outPadR[id];
    output_sizes[1] = ioBufDesc->outHeight[id] + ioBufDesc->outPadT[id] + ioBufDesc->outPadB[id];
    output_sizes[2] = ioBufDesc->outNumChannels[id];

    vx_enum data_type = get_vx_tensor_datatype_e(ioBufDesc->outElementType[id]);
    output_tensors[id] = vxCreateTensor(context, 3, output_sizes, data_type, 0);
  }

  vxUnmapUserDataObject(config, map_id_config);

  return;
}

#if 0 // Not used
static void initParam(vx_reference params[], uint32_t _max_params)
{
  num_params = 0;
  max_params = _max_params;
}
#endif

#if 0 // Not used
static void addParam(vx_reference params[], vx_reference obj)
{
  if (num_params <= max_params)
  {
    params[num_params] = obj;
    num_params++;
  }
  else
  {
    APP_ERROR("Error! num_params > max_params!\n");
  }

}
#endif

#ifdef COMPUTE_CHECKSUM
static void getQC(uint8_t *pIn, uint8_t *pOut, int32_t inSize)
{
  int32_t i, j;
  uint8_t vec[TIVX_TIDL_J7_CHECKSUM_SIZE];
  int32_t remSize;

  /* Initialize vector */
  for (j = 0; j < TIVX_TIDL_J7_CHECKSUM_SIZE; j++)
  {
    vec[j] = 0;
  }

  /* Create QC */
  remSize = inSize;
  for (i = 0; i < inSize; i += TIVX_TIDL_J7_CHECKSUM_SIZE)
  {
    int32_t elems;

    if (remSize < TIVX_TIDL_J7_CHECKSUM_SIZE)
    {
      elems = TIVX_TIDL_J7_CHECKSUM_SIZE - remSize;
      remSize += TIVX_TIDL_J7_CHECKSUM_SIZE;
    }
    else
    {
      elems = TIVX_TIDL_J7_CHECKSUM_SIZE;
      remSize -= TIVX_TIDL_J7_CHECKSUM_SIZE;
    }

    for (j = 0; j < elems; j++)
    {
      vec[j] ^= pIn[i + j];
    }
  }

  /* Return QC */
  for (j = 0; j < TIVX_TIDL_J7_CHECKSUM_SIZE; j++)
  {
    pOut[j] = vec[j];
  }
}
#endif
