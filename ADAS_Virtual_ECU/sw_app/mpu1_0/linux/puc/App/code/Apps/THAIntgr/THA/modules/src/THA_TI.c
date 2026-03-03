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
 * @author Afshan Shaikh (afshan.shaikh@magna.com)
 * 
 */

#include "THA_TI.h"
#include "platform/PlatformAPI.h"
// Dipti : Macro for number of classID according to trailerPose model
#define NUMBER_CLASSID_TRAILERPOSE  30
static vx_size getTensorDataType(vx_int32 tidl_type)
{
  vx_size openvx_type = VX_TYPE_INVALID;

  if (tidl_type == TIDL_UnsignedChar)
  {
    openvx_type = VX_TYPE_UINT8;
  }
  else if (tidl_type == TIDL_SignedChar)
  {
    openvx_type = VX_TYPE_INT8;
  }
  else if (tidl_type == TIDL_UnsignedShort)
  {
    openvx_type = VX_TYPE_UINT16;
  }
  else if (tidl_type == TIDL_SignedShort)
  {
    openvx_type = VX_TYPE_INT16;
  }
  else if (tidl_type == TIDL_UnsignedWord)
  {
    openvx_type = VX_TYPE_UINT32;
  }
  else if (tidl_type == TIDL_SignedWord)
  {
    openvx_type = VX_TYPE_INT32;
  }
  else if (tidl_type == TIDL_SinglePrecFloat)
  {
    openvx_type = VX_TYPE_FLOAT32;
  }

  return openvx_type;
}

void createInputTensors(sTIDL_IOBufDesc_t *ioBufDesc, vx_context context, vx_tensor *input_tensors)
{
  vx_size input_sizes[APP_MAX_TENSOR_DIMS];

  int32_t id;

  for (id = 0; id < ioBufDesc->numInputBuf; id++)
  {

    input_sizes[0] = ioBufDesc->inWidth[id] + ioBufDesc->inPadL[id] + ioBufDesc->inPadR[id];
    input_sizes[1] = ioBufDesc->inHeight[id] + ioBufDesc->inPadT[id] + ioBufDesc->inPadB[id];
    input_sizes[2] = ioBufDesc->inNumChannels[id];

    vx_size data_type = getTensorDataType(ioBufDesc->inElementType[id]);

    if (data_type != VX_TYPE_INVALID)
      input_tensors[id] = vxCreateTensor(context, 3, input_sizes, data_type, 0);
  }

  return;
}

static vx_status readInput(sTIDL_IOBufDesc_t *ioBufDesc, vx_tensor *input_tensors, const uint8_t *input_image, vx_size input_width, vx_size input_height, uint8_t bit_depth)
{
  vx_status status = VX_SUCCESS;
  void *input_buffer = NULL;
  uint8_t *input_tensorBuf_8 = NULL;
  uint16_t *input_tensorBuf_16 = NULL;
  int32_t capacity;
  int32_t id;
  vx_map_id map_id_input;
  vx_size start[APP_MAX_TENSOR_DIMS];
  vx_size input_strides[APP_MAX_TENSOR_DIMS];
  vx_size input_sizes[APP_MAX_TENSOR_DIMS];
  //ME_Debugger_F_Printf_v("\n ### readInput : ioBufDesc->numInputBuf = %d \n",ioBufDesc->numInputBuf);

  for (id = 0; id < ioBufDesc->numInputBuf; id++)
  {
    input_sizes[0] = ioBufDesc->inWidth[id] + ioBufDesc->inPadL[id] + ioBufDesc->inPadR[id];
    input_sizes[1] = ioBufDesc->inHeight[id] + ioBufDesc->inPadT[id] + ioBufDesc->inPadB[id];
    input_sizes[2] = ioBufDesc->inNumChannels[id]; //rgb = 3


    start[0] = start[1] = start[2] = 0;

    if(bit_depth == 1)
    {
      input_strides[0] = sizeof(vx_uint8); //bit depth of input tensor
    }
    else if(bit_depth == 2)
    {
      input_strides[0] = sizeof(vx_uint16); //bit depth of input tensor
    }
    else
    {
    }
    input_strides[1] = input_sizes[0] * input_strides[0];
    input_strides[2] = input_sizes[1] * input_strides[1];

    capacity = input_sizes[0] * input_sizes[1] * input_sizes[2] * input_strides[0];
#if ENABLE_DEBUG_THA
    // ME_Debugger_F_Printf_v(" input_sizes[0] = %d, dim = %d padL = %d padR = %d\n", (uint32_t)input_sizes[0], ioBufDesc->inWidth[id], ioBufDesc->inPadL[id], ioBufDesc->inPadR[id]);
    // ME_Debugger_F_Printf_v(" input_sizes[1] = %d, dim = %d padT = %d padB = %d\n", (uint32_t)input_sizes[1], ioBufDesc->inHeight[id], ioBufDesc->inPadT[id], ioBufDesc->inPadB[id]);
    // ME_Debugger_F_Printf_v(" input_sizes[2] = %d, dim = %d \n", (uint32_t)input_sizes[2], ioBufDesc->inNumChannels[id]);
    // ME_Debugger_F_Printf_v(" input_strides[0] = %d, input_strides[1] = %d, input_strides[2]=%d \n", (uint32_t)input_strides[0], (uint32_t)input_strides[1], (uint32_t)input_strides[2]);
#endif

    if (status == VX_SUCCESS)
    {
      status = tivxMapTensorPatch(input_tensors[id], ioBufDesc->inNumChannels[id], start, input_sizes, &map_id_input, input_strides, &input_buffer, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST);
    }
    if (VX_SUCCESS == status)
    {
      vx_int32 i, j;

      // Dipti : Convert RGB interleaved image into RGB planar tensor
      if (status != VX_SUCCESS)
      {
        ME_Debugger_F_Printf_v("app_tidl: Reading imagw file ... Failed !!!\n");
      }
      else
      {
        int size_pad0 = input_sizes[0] * ioBufDesc->inPadT[id];
        int size_pad1 = input_sizes[0] * ioBufDesc->inPadB[id];
        int offset_pad0 = 0;
        int offset_pad1 = size_pad0 + input_sizes[0] * (ioBufDesc->inHeight[id] + ioBufDesc->inPadT[id]);
        int im_offset = input_sizes[0] * input_sizes[1];
        if(input_buffer == NULL)
        {
          ME_Debugger_F_Printf_v("Input buffer is NULL\n");
        }
        memset(input_buffer,0,capacity);
        //uint8_t *input_buffer_8 = (uint8_t*) input_buffer;
        if(bit_depth == 1)
        {
          input_tensorBuf_8  = (uint8_t*) input_buffer;  // Typecast based on bit depth of input tensor
        uint64_t k = 0;
          for (int j = ioBufDesc->inPadT[id]; j < (int32_t)input_sizes[1] - ioBufDesc->inPadB[id]; j++)
          {
            for (int i = 0; i < (int32_t)input_sizes[0]; i++)
            {
              if (i >= ioBufDesc->inPadL[id])
              {
                uint32_t buffer_index = i + j * input_sizes[0];
                input_tensorBuf_8[buffer_index]                 = input_image[k];
                input_tensorBuf_8[buffer_index + im_offset]     = input_image[im_offset + k];
                input_tensorBuf_8[buffer_index + (im_offset*2)] = input_image[(im_offset*2) + k];
                k = k+1;
              }
            }
          }
        }
        else if(bit_depth == 2)
        {
          input_tensorBuf_16 = (uint16_t*) input_buffer;  // Typecast based on bit depth of input tensor
          uint64_t k = 0;
          for (int j = ioBufDesc->inPadT[id]; j < (int32_t)input_sizes[1] - ioBufDesc->inPadB[id]; j++)
          {
          for (int i = 0; i < (int32_t)input_sizes[0]; i++)
          {
              if (i >= ioBufDesc->inPadL[id])
            {
              uint32_t buffer_index = i + j * input_sizes[0];
                input_tensorBuf_16[buffer_index]                 = input_image[k];
                input_tensorBuf_16[buffer_index + im_offset]     = input_image[im_offset + k];
                input_tensorBuf_16[buffer_index + (im_offset*2)] = input_image[(im_offset*2) + k];
              k = k+1;
              }
            }
          }
        }
        else
        {
        }
        #if ENABLE_DEBUG_THA
        ME_Debugger_F_Printf_v("app_tidl: Image Pre processing status=%d ... Done.\n",status);
        #endif
      }
      tivxUnmapTensorPatch(input_tensors[id], map_id_input);
    }
  }

  return status;
}


#if ENABLE_CD_HD
static void app_set_cfg_default_CD_HD(AppObj_CD_HD *obj)
{
  snprintf(obj->tidlObj.config_file_path, APP_MAX_FILE_PATH, ".");
  snprintf(obj->tidlObj.network_file_path, APP_MAX_FILE_PATH, ".");
 
  snprintf(obj->input_file_path, APP_MAX_FILE_PATH, ".");
}

static void app_parse_cfg_file_CD_HD(AppObj_CD_HD *obj, vx_char *cfg_file_name)
{
  strcpy(obj->tidlObj.config_file_path, "/ti_fs/vision_apps/tidl_io_TD_CD_HD_yolov5_v66.bin");
  strcpy(obj->tidlObj.network_file_path, "/ti_fs/vision_apps/tidl_net_TD_CD_HD_yolov5_v66.bin");

  strcpy(obj->input_file_path, "/ti_fs/vision_apps");
  strcpy(obj->output_file_path, "/ti_fs/vision_apps");
  
  obj->start_frame = 1;
  obj->num_frames = 1;
  obj->input_width   = 640;
  obj->input_height  = 640;
  obj->output_width  = 640;
  obj->output_height = 640;
}

void app_parse_cmd_line_args_CD_HD(AppObj_CD_HD *obj)
{
  app_set_cfg_default_CD_HD(obj);
  app_parse_cfg_file_CD_HD(obj, "app_CD_HD.cfg");
  return;
}

void readConfig_CD_HD(AppObj_CD_HD *obj, sTIDL_IOBufDesc_t *ioBufDescFeature, TIDLObj *tidlObj)
{
  vx_status status = VX_SUCCESS;

  tivxTIDLJ7Params *tidlParams = NULL;
  sTIDL_IOBufDesc_t *ioBufDesc = NULL;
  vx_user_data_object config = NULL;
  vx_uint32 capacity;
  vx_map_id map_id;

  FILE *fp_config;
  vx_size read_count;

  fp_config = fopen(tidlObj->config_file_path, "rb");

  if (fp_config == NULL)
  {
    ME_Debugger_F_Printf_v("\n app_tidl: ERROR: Unable to open IO config file %s ", tidlObj->config_file_path);
  }

  fseek(fp_config, 0, SEEK_END);
  capacity = ftell(fp_config);
  fseek(fp_config, 0, SEEK_SET);

  if (capacity != sizeof(sTIDL_IOBufDesc_t))
  {
    ME_Debugger_F_Printf_v("\n app_tidl: ERROR: Config file size (%d bytes) does not match size of sTIDL_IOBufDesc_t (%d bytes)", capacity, (vx_uint32) sizeof(sTIDL_IOBufDesc_t));
    fclose(fp_config);
  }

  /* Create a user struct type for handling config data*/
  config = vxCreateUserDataObject(obj->context, "tivxTIDLJ7Params", sizeof(tivxTIDLJ7Params), NULL);

  status = vxGetStatus((vx_reference) config);

  if (VX_SUCCESS == status)
  {
    status = vxMapUserDataObject(config, 0, sizeof(tivxTIDLJ7Params), &map_id,
        (void**) &tidlParams, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST, 0);

    if (VX_SUCCESS == status)
    {
      if (tidlParams == NULL)
      {
        ME_Debugger_F_Printf_v("\n app_tidl: ERROR: Map of config object failed");
        fclose(fp_config);
      }

      tivx_tidl_j7_params_init(tidlParams);

      ioBufDesc = (sTIDL_IOBufDesc_t*) &tidlParams->ioBufDesc;

      read_count = fread(ioBufDesc, capacity, 1, fp_config);
      if (read_count != 1)
      {
        ME_Debugger_F_Printf_v("\n app_tidl: ERROR: Unable to read config file");
      }
      fclose(fp_config);

      memcpy(ioBufDescFeature, ioBufDesc, capacity);
      if (status == VX_SUCCESS)
      {
        status = vxUnmapUserDataObject(config, map_id);
      }
    }
    else
    {
      fclose(fp_config);
    }
  }
  else
  {
    fclose(fp_config);
  }

  vxReleaseUserDataObject(&config);

  //return config;
}

vx_status app_init_CD_HD(AppObj_CD_HD *obj)
{
  vx_status status = VX_SUCCESS;

  /* Create OpenVx Context */
  obj->context = vxCreateContext();
  status = vxGetStatus((vx_reference) obj->context);

  if (status == VX_SUCCESS)
  {
    tivxHwaLoadKernels(obj->context);
    tivxImgProcLoadKernels(obj->context);
    tivxTIDLLoadKernels(obj->context);
  }

  if (status == VX_SUCCESS)
  {
    status = app_init_tidl(obj->context, &obj->tidlObj, "tidl_obj_CDHD", 1);
    readConfig_CD_HD(obj, &obj->ioBufDesc, &obj->tidlObj);
  }

  return status;
}

void app_deinit_CD_HD(AppObj_CD_HD *obj)
{
  app_deinit_tidl(&obj->tidlObj);

  tivxTIDLUnLoadKernels(obj->context);

  tivxImgProcUnLoadKernels(obj->context);

  tivxHwaUnLoadKernels(obj->context);

  vxReleaseContext(&obj->context);
}

vx_status app_create_graph_CD_HD(AppObj_CD_HD *obj)
{
  vx_status status = VX_SUCCESS;

  obj->graph = vxCreateGraph(obj->context);
  status = vxGetStatus((vx_reference) obj->graph);

  if (status == VX_SUCCESS)
  {
    status = vxSetReferenceName((vx_reference) obj->graph, "OpenVxGraph");
  }
  /* Create array of input tensors */
  createInputTensors(&obj->ioBufDesc, obj->context, obj->input_tensors);

  if (status == VX_SUCCESS)
  {
    status = app_create_graph_tidl_tens(obj->context, obj->graph, &obj->tidlObj, obj->input_tensors);
  }

  return status;
}

vx_status app_verify_graph_CD_HD(AppObj_CD_HD *obj)
{
  vx_status status = VX_SUCCESS;

  status = vxVerifyGraph(obj->graph);

  /* wait a while for prints to flush */
  tivxTaskWaitMsecs(100);

  return status;
}

vx_status app_run_graph_for_one_frame_sequential_CD_HD(AppObj_CD_HD *obj, const uint8_t *inputImage)
{
  vx_status status = VX_SUCCESS;
  uint8_t bit_depth = 2; // 1 : 8 bit, 2: 16 bit
  status = readInput(&obj->ioBufDesc, obj->input_tensors, inputImage, obj->input_width, obj->input_height,bit_depth);
  #if ENABLE_DEBUG_THA
    ME_Debugger_F_Printf_v("\n ###vxProcessGraph CD_HD in\n");
  #endif
  status = vxProcessGraph(obj->graph);
  #if ENABLE_DEBUG_THA
    ME_Debugger_F_Printf_v("\n ###vxProcessGraph CD_HD %d\n",status);
  #endif
  return status;
}

void app_delete_graph_CD_HD(AppObj_CD_HD *obj)
{
  app_delete_tidl(&obj->tidlObj);

  vxReleaseGraph(&obj->graph);
}

static vx_int32 clip_offset(vx_int32 input, vx_int32 max)
{
  vx_int32 output;
  output = (input >= max) ? max - 1 : input;
  output = output < 0 ? 0 : output;
  return output;
}

void WriteOutput_CDHD(AppObj_CD_HD *obj,vx_size width, vx_size height, DNN_CDHD_out *data_arr, uint8_t* numObject)
{
  vx_status status = VX_SUCCESS;
  vx_tensor output;
  vx_size numCh;
  vx_uint32 ch, tensor_id;

  vx_map_id map_id_config;
  sTIDL_IOBufDesc_t *ioBufDesc;
  tivxTIDLJ7Params *tidlParams;

  vxMapUserDataObject(obj->tidlObj.config, 0, sizeof(tivxTIDLJ7Params), &map_id_config,
      (void **)&tidlParams, VX_READ_ONLY, VX_MEMORY_TYPE_HOST, 0);

  ioBufDesc = (sTIDL_IOBufDesc_t *)&tidlParams->ioBufDesc;
  //ME_Debugger_F_Printf_v("\n ### WriteOutput_CDHD: num_output_tensors=%d \n",obj->tidlObj.num_output_tensors);

  for(tensor_id = 0; tensor_id < obj->tidlObj.num_output_tensors; tensor_id++)
  {
    vxQueryObjectArray((vx_object_array)obj->tidlObj.output_tensor_arr[tensor_id], VX_OBJECT_ARRAY_NUMITEMS, &numCh, sizeof(vx_size));

    for(ch = 0; ch < numCh; ch++)
    {
      vx_size num_dims;
      void *data_ptr;
      vx_map_id map_id;

      vx_size    start[APP_MODULES_MAX_TENSOR_DIMS];
      vx_size    tensor_strides[APP_MODULES_MAX_TENSOR_DIMS];
      vx_size    tensor_sizes[APP_MODULES_MAX_TENSOR_DIMS];
      
      output  = (vx_tensor)vxGetObjectArrayItem((vx_object_array)obj->tidlObj.output_tensor_arr[tensor_id], ch);

      vxQueryTensor(output, VX_TENSOR_NUMBER_OF_DIMS, &num_dims, sizeof(vx_size));

      if(num_dims != 3)
      {
        ME_Debugger_F_Printf_v("\n### WriteOutput_CDHD: Number of dims are != 3! exiting.. \n");
        break;
      }

      vxQueryTensor(output, VX_TENSOR_DIMS, tensor_sizes, 3 * sizeof(vx_size));

      start[0] = start[1] = start[2] = 0;

      tensor_strides[0] = 1;
      tensor_strides[1] = tensor_strides[0];
      tensor_strides[2] = tensor_strides[1] * tensor_strides[1];

      status = tivxMapTensorPatch(output, num_dims, start, tensor_sizes, &map_id, tensor_strides, &data_ptr, VX_READ_ONLY, VX_MEMORY_TYPE_HOST);

      if(VX_SUCCESS == status)
      {
        vx_uint32 i;
        vx_uint32 numObjs;
        vx_int32   v_ClassID;
        
        TIDL_ODLayerHeaderInfo *pHeader;
        TIDL_ODLayerObjInfo *pObjInfo;
        
        vx_float32 *pOut = (vx_float32 *)((uint8_t *)data_ptr +  (ioBufDesc->outPadT[0] * tensor_sizes[0]) + ioBufDesc->outPadL[0]);
        pHeader  = (TIDL_ODLayerHeaderInfo *)pOut;
        pObjInfo = (TIDL_ODLayerObjInfo *)((uint8_t *)pOut + (vx_uint32)pHeader->objInfoOffset);
        numObjs  = (vx_uint32)pHeader->numDetObjects;
        #if ENABLE_DEBUG_THA
        ME_Debugger_F_Printf_v("\n ### WriteOutput_CDHD: numObjs = %d \n",(vx_uint32)((TIDL_ODLayerHeaderInfo *)pOut)->numDetObjects);
        ME_Debugger_F_Printf_v("\n ### WriteOutput_CDHD: ObjId, v_ClassID, pPSpots->score, xmin, ymin, xmax, ymax = ");
        #endif
        // Dipti : To get coupler and Hitch with confidence > 0.5
        for (i = 0; i < numObjs; i++)
        {
          TIDL_ODLayerObjInfo * pPSpots = (TIDL_ODLayerObjInfo *) ((uint8_t *)pObjInfo + (i * ((vx_uint32)pHeader->objInfoSize)));
          if((pPSpots->score > 0.5) && (*numObject < 50))
          {
            data_arr[i].xmin      = clip_offset((pPSpots->xmin * obj->input_width), obj->input_width);
            data_arr[i].ymin      = clip_offset((pPSpots->ymin * obj->input_height), obj->input_height);
            data_arr[i].xmax      = clip_offset((pPSpots->xmax * obj->input_width), obj->input_width);
            data_arr[i].ymax      = clip_offset((pPSpots->ymax * obj->input_height), obj->input_height);
            data_arr[i].v_ClassID = (vx_int32)pPSpots->label + 1;
            data_arr[i].ObjId     = (vx_int32)pPSpots->ObjId;
            data_arr[i].v_prob    = pPSpots->score;
            #if ENABLE_DEBUG_THA
            ME_Debugger_F_Printf_v("\n %d,%d,%f,%d,%d,%d,%d\n",data_arr[i].ObjId,data_arr[i].v_ClassID,\
            data_arr[i].v_prob, data_arr[i].xmin, data_arr[i].ymin, \
            data_arr[i].xmax, data_arr[i].ymax);
            #endif
            *numObject = (*numObject) + 1;
          }
        }
        //ME_Debugger_F_Printf_v("\n numObject : %d ",(*numObject));
        tivxUnmapTensorPatch(output, map_id);
      }
      vxReleaseTensor(&output);
    }
  }
  vxUnmapUserDataObject(obj->tidlObj.config, map_id_config);
}

#endif


#if ENABLE_TrailerPose

int app_init_TrailerPose(AppObj_TrailerPose *obj)
{
    int status = 0;
    #if ENABLE_DEBUG_THA
      APP_PRINTF("app_tidl: Init ... \n");
    #endif

    obj->context = vxCreateContext();
    APP_ASSERT_VALID_REF(obj->context);

    /* Create a vx_array object and read the config data*/
    obj->tidlObj.config = readConfig_TrailerPose(obj);
    APP_ASSERT_VALID_REF(obj->tidlObj.config)

    /* Create a vx_tensor object and read the network data */
    obj->tidlObj.network = readNetwork_TrailerPose(obj);
    APP_ASSERT_VALID_REF(obj->tidlObj.network)

    obj->tidlObj.createParams = setCreateParams_TrailerPose(obj->context);
    APP_ASSERT_VALID_REF(obj->tidlObj.createParams)

    obj->inArgs = setInArgs_TrailerPose(obj->context);
    APP_ASSERT_VALID_REF(obj->inArgs)

    obj->outArgs = setOutArgs_TrailerPose(obj->context);
    APP_ASSERT_VALID_REF(obj->outArgs)

    obj->tidlObj.kernel = tivxAddKernelTIDL(obj->context, obj->tidlObj.num_input_tensors, obj->tidlObj.num_output_tensors);
    APP_ASSERT_VALID_REF(obj->tidlObj.kernel)

    tivxTIDLLoadKernels(obj->context);

    obj->pInPlanes = tivxMemAlloc(MAX_IMG_WIDTH * MAX_IMG_HEIGHT * 3, TIVX_MEM_EXTERNAL);
    if(obj->pInPlanes == NULL) {
        ME_Debugger_F_Printf_v("app_tidl: ERROR: Unable to allocate memory for inPlanes, size = %d\n", MAX_IMG_WIDTH * MAX_IMG_HEIGHT * 3);
        status = -1;
    }

    obj->pOutPlanes = tivxMemAlloc(MAX_IMG_WIDTH * MAX_IMG_HEIGHT * 3, TIVX_MEM_EXTERNAL);
    if(obj->pOutPlanes == NULL) {
        ME_Debugger_F_Printf_v("app_tidl: ERROR: Unable to allocate memory for outPlanes, size = %d\n", MAX_IMG_WIDTH * MAX_IMG_HEIGHT * 3);
        status = -1;
    }
    #if ENABLE_DEBUG_THA
      ME_Debugger_F_Printf_v("app_tidl: Init ... Done.\n");
    #endif
    return status;
}

void app_deinit_TrailerPose(AppObj_TrailerPose *obj)
{
    tivxTIDLUnLoadKernels(obj->context);

    vxRemoveKernel(obj->tidlObj.kernel);

    vxReleaseContext(&obj->context);

    tivxMemFree(obj->pInPlanes, MAX_IMG_WIDTH * MAX_IMG_HEIGHT * 3, TIVX_MEM_EXTERNAL);
    tivxMemFree(obj->pOutPlanes, MAX_IMG_WIDTH * MAX_IMG_HEIGHT * 3, TIVX_MEM_EXTERNAL);

}

void app_delete_graph_TrailerPose(AppObj_TrailerPose *obj)
{
    uint32_t id;
    
    vxReleaseNode(&obj->tidl_node);
    vxReleaseGraph(&obj->graph);

    vxReleaseUserDataObject(&obj->tidlObj.config);
    vxReleaseUserDataObject(&obj->tidlObj.network);

    vxReleaseUserDataObject(&obj->tidlObj.createParams);
    vxReleaseUserDataObject(&obj->inArgs);
    vxReleaseUserDataObject(&obj->outArgs);

    for(id = 0; id < obj->tidlObj.num_input_tensors; id++)
    {
        vxReleaseTensor(&obj->input_tensors[id]);
    }

    for(id = 0; id < obj->tidlObj.num_output_tensors; id++)
    {
        vxReleaseTensor(&obj->output_tensors[id]);
    }

}

static void app_set_cfg_default_TrailerPose(AppObj_TrailerPose *obj)
{
  snprintf(obj->tidlObj.config_file_path, APP_MAX_FILE_PATH, ".");
  snprintf(obj->tidlObj.network_file_path, APP_MAX_FILE_PATH, ".");
 
  snprintf(obj->input_file_path, APP_MAX_FILE_PATH, ".");
}

static int app_parse_cfg_file_TrailerPose(AppObj_TrailerPose *obj)
{
  strcpy(obj->tidlObj.config_file_path, "/ti_fs/vision_apps/tidl_io_TrailePose_Resnet_v14.bin");
  strcpy(obj->tidlObj.network_file_path, "/ti_fs/vision_apps/tidl_net_TrailePose_Resnet_v14.bin");
  strcpy(obj->input_file_path, "/ti_fs/vision_apps");
  strcpy(obj->output_file_path, "/ti_fs/vision_apps");

  obj->input_width   = 112;
  obj->input_height  = 112;
  obj->output_width  = 112;
  obj->output_height = 112;

  return 0;
}

void app_parse_cmd_line_args_TrailerPose(AppObj_TrailerPose *obj)
{
  app_set_cfg_default_TrailerPose(obj);
  app_parse_cfg_file_TrailerPose(obj);
}

static void initParam(vx_reference params[], uint32_t _max_params)
{
   num_params  = 0;
   max_params = _max_params;
}

static void addParam(vx_reference params[], vx_reference obj)
{
   APP_ASSERT(num_params <= max_params);

   params[num_params] = obj;

   num_params++;
}

vx_status app_create_graph_TrailerPose(AppObj_TrailerPose *obj)
{
    vx_status status = VX_SUCCESS;

    vx_reference params[APP_TIDL_MAX_PARAMS];
    uint32_t i;
    #if ENABLE_DEBUG_THA
    APP_PRINTF("app_tidl: Creating graph ... \n");
    #endif
    /* Create OpenVx Graph */
    obj->graph = vxCreateGraph(obj->context);
    APP_ASSERT_VALID_REF(obj->graph)
    vxSetReferenceName((vx_reference)obj->graph, "app_tidl_graph");

    /* Create array of input tensors */
    createInputTensors_TrailerPose(obj, obj->context, obj->tidlObj.config, obj->input_tensors);

    /* Create array of output tensors */
    createOutputTensors_TrailerPose(obj, obj->context, obj->tidlObj.config, obj->output_tensors);

    /* Initialize param array */
    initParam(params, APP_TIDL_MAX_PARAMS);

    /* The 1st param MUST be config */
    addParam(params, (vx_reference)obj->tidlObj.config);

    /* The 2nd param MUST be network */
    addParam(params, (vx_reference)obj->tidlObj.network);

    /* The 3rd param MUST be create params */
    addParam(params, (vx_reference)obj->tidlObj.createParams);

    /* The 4th param MUST be inArgs */
    addParam(params, (vx_reference)obj->inArgs);

    /* The 5th param MUST be outArgs */
    addParam(params, (vx_reference)obj->outArgs);

    /* The 6th param MUST be NULL if trace data dump is not enabled */
    addParam(params, (vx_reference)NULL);

    /* Create TIDL Node */
    obj->tidl_node = tivxTIDLNode(obj->graph, obj->tidlObj.kernel, params, obj->input_tensors, obj->output_tensors);
    APP_ASSERT_VALID_REF(obj->tidl_node)

    /* Set names for diferent OpenVX objects */
    vxSetReferenceName((vx_reference)obj->tidlObj.config, "Config");
    vxSetReferenceName((vx_reference)obj->tidlObj.network, "Network");
    vxSetReferenceName((vx_reference)obj->tidlObj.createParams, "CreateParams");
    vxSetReferenceName((vx_reference)obj->inArgs, "InArgs");
    vxSetReferenceName((vx_reference)obj->outArgs, "OutArgs");

    for(i = 0; i < obj->tidlObj.num_input_tensors; i++) {
        char tensor_name[] = "InputTensor_";
        char ref_name[64];
        snprintf(ref_name, 64, "%s%s", tensor_name, tensor_num_str[i]);
        vxSetReferenceName((vx_reference)obj->input_tensors[i], ref_name);
    }

    for(i = 0; i < obj->tidlObj.num_output_tensors; i++) {
        char tensor_name[] = "OutputTensor_";
        char ref_name[64];
        snprintf(ref_name, 64, "%s%s", tensor_name, tensor_num_str[i]);
        vxSetReferenceName((vx_reference)obj->output_tensors[i], ref_name);
    }

    vxSetReferenceName((vx_reference)obj->tidlObj.kernel, "TIDLKernel");
    vxSetReferenceName((vx_reference)obj->tidl_node, "TIDLNode");
    #if ENABLE_DEBUG_THA
      APP_PRINTF("app_tidl: Creating graph ... Done.\n");
    #endif

    return status;
}

vx_status app_verify_graph_TrailerPose(AppObj_TrailerPose *obj)
{
    vx_status status = VX_SUCCESS;
    #if ENABLE_DEBUG_THA
    APP_PRINTF("app_tidl: Verifying graph ... \n");
    #endif
    /* Verify the TIDL Graph */
    status = vxVerifyGraph(obj->graph);
    if(status != VX_SUCCESS)
    {
        ME_Debugger_F_Printf_v("app_tidl: ERROR: Verifying graph ... Failed !!!\n");
        return status;
    }
    #if ENABLE_DEBUG_THA
    APP_PRINTF("app_tidl: Verifying graph ... Done.\n");
    #endif
    /* wait a while for prints to flush */
    tivxTaskWaitMsecs(100);

#if 0
    if(status == VX_SUCCESS)
    {
        status = tivxExportGraphToDot(obj->graph,".", "vx_app_tidl");
        APP_ASSERT(status==VX_SUCCESS);
    }
#endif

    return status;
}

vx_status app_run_graph_for_one_frame_TrailerPose(AppObj_TrailerPose *obj, const unsigned char* input_img_buffer, float_t* o_classProb_f32, uint32_t* v_classID)
{
    vx_status status = VX_SUCCESS;
    vx_uint32 tensor_actual_checksum = 0, display_actual_checksum = 0;
    uint8_t bit_depth = 1; // 1 : 8 bit, 2: 16 bit
    /* Read input from file and poplulate the input tensors */
    if(status == VX_SUCCESS)
    {
        status = readInput(&obj->ioBufDesc, obj->input_tensors, input_img_buffer, obj->input_width, obj->input_height,bit_depth);
    }
    /* Execute the network */
    if(status == VX_SUCCESS)
    {
      #if ENABLE_DEBUG_THA
      ME_Debugger_F_Printf_v("\n ###vxProcessGraph TrailerPose in\n");
      #endif
        status = vxProcessGraph(obj->graph);
    }

    #if ENABLE_DEBUG_THA
    ME_Debugger_F_Printf_v("\n ###vxProcessGraph TrailerPose %d\n",status);
    #endif
    
    if(status == VX_SUCCESS)
    {
        /* Write the output */
        WriteOutput_TrailerPose(obj, obj->tidlObj.config, obj->output_tensors, o_classProb_f32, v_classID);
        #if ENABLE_DEBUG_THA
          ME_Debugger_F_Printf_v("\n #### TrailerPose: WriteOutput done \n");
        #endif
    }
    return status;
}

static vx_user_data_object readConfig_TrailerPose(AppObj_TrailerPose *obj)
{
    vx_status status = VX_SUCCESS;

    tivxTIDLJ7Params  *tidlParams = NULL;
    sTIDL_IOBufDesc_t *ioBufDesc = NULL;
    vx_user_data_object   config = NULL;
    vx_uint32 capacity;
    vx_map_id map_id;

    FILE *fp_config;
    vx_size read_count;
    #if ENABLE_DEBUG_THA
      APP_PRINTF("app_tidl: Reading config file %s ...\n", obj->tidlObj.config_file_path);
    #endif
    fp_config = fopen(obj->tidlObj.config_file_path, "rb");

    if(fp_config == NULL)
    {
        ME_Debugger_F_Printf_v("app_tidl: ERROR: Unable to open IO config file %s \n", obj->tidlObj.config_file_path);

        return NULL;
    }

    fseek(fp_config, 0, SEEK_END);
    capacity = ftell(fp_config);
    fseek(fp_config, 0, SEEK_SET);

    if( capacity != sizeof(sTIDL_IOBufDesc_t) )
    {
        ME_Debugger_F_Printf_v("app_tidl: ERROR: Config file size (%d bytes) does not match size of sTIDL_IOBufDesc_t (%d bytes)\n", capacity, (vx_uint32)sizeof(sTIDL_IOBufDesc_t));
        fclose(fp_config);
        return NULL;
    }


    /* Create a user struct type for handling config data*/
    config = vxCreateUserDataObject(obj->context, "tivxTIDLJ7Params", sizeof(tivxTIDLJ7Params), NULL );

    status = vxGetStatus((vx_reference)config);

    if (VX_SUCCESS == status)
    {
      status = vxMapUserDataObject(config, 0, sizeof(tivxTIDLJ7Params), &map_id,
                          (void **)&tidlParams, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST, 0);

      if (VX_SUCCESS == status)
      {
          if(tidlParams == NULL)
          {
            ME_Debugger_F_Printf_v("app_tidl: ERROR: Map of config object failed\n");
            fclose(fp_config);
            return NULL;
          }

          tivx_tidl_j7_params_init(tidlParams);

          ioBufDesc = (sTIDL_IOBufDesc_t *)&tidlParams->ioBufDesc;

          read_count = fread(ioBufDesc, capacity, 1, fp_config);
          if(read_count != 1)
          {
            ME_Debugger_F_Printf_v("app_tidl: ERROR: Unable to read config file\n");
          }
          fclose(fp_config);

          memcpy(&obj->ioBufDesc, ioBufDesc, capacity);
          obj->tidlObj.num_input_tensors  = ioBufDesc->numInputBuf;
          obj->tidlObj.num_output_tensors = ioBufDesc->numOutputBuf;
          if(status == VX_SUCCESS)
          {
              status = vxUnmapUserDataObject(config, map_id);
          }
        }
        else
        {
            fclose(fp_config);
        }
    }
    else
    {
        fclose(fp_config);
    }
    #if ENABLE_DEBUG_THA
      APP_PRINTF("app_tidl: Reading config file %s ... Done. %d bytes\n", obj->tidlObj.config_file_path, (uint32_t)capacity);
      APP_PRINTF("app_tidl: Tensors, input = %d, output = %d\n", *num_input_tensors, *num_output_tensors);
    #endif
    return config;
}

static vx_user_data_object readNetwork_TrailerPose(AppObj_TrailerPose *obj)
{
    vx_status status;

    vx_user_data_object  network;
    vx_map_id  map_id;
    vx_uint32  capacity;
    void      *network_buffer = NULL;
    vx_size read_count;

    FILE *fp_network;
    #if ENABLE_DEBUG_THA
      APP_PRINTF("app_tidl: Reading network file %s ... \n", obj->tidlObj.network_file_path);
    #endif

    fp_network = fopen(obj->tidlObj.network_file_path, "rb");

    if(fp_network == NULL)
    {
        ME_Debugger_F_Printf_v("app_tidl: ERROR: Unable to open network file %s \n", obj->tidlObj.network_file_path);

        return NULL;
    }
    fseek(fp_network, 0, SEEK_END);
    capacity = ftell(fp_network);
    fseek(fp_network, 0, SEEK_SET);

    network = vxCreateUserDataObject(obj->context, "TIDL_network", capacity, NULL );

    status = vxGetStatus((vx_reference)network);

    if (VX_SUCCESS == status)
    {
        status = vxMapUserDataObject(network, 0, capacity, &map_id,
                        (void **)&network_buffer, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST, 0);

        if (VX_SUCCESS == status)
        {
            if(network_buffer)
            {
                read_count = fread(network_buffer, capacity, 1, fp_network);
                if(read_count != 1)
                {
                    ME_Debugger_F_Printf_v("app_tidl: ERROR: Unable to read network file\n");
                }
                fclose(fp_network);
            }
            else
            {
                ME_Debugger_F_Printf_v("app_tidl: ERROR: Unable to allocate memory for reading network file of %d bytes\n", capacity);
                fclose(fp_network);
            }
            if(status == VX_SUCCESS)
            {
                status = vxUnmapUserDataObject(network, map_id);
            }
        }
        else
        {
            fclose(fp_network);
        }
    }
    else
    {
        fclose(fp_network);
    }
    #if ENABLE_DEBUG_THA
      APP_PRINTF("app_tidl: Reading network file %s ... Done. %d bytes\n", obj->tidl_network_file_path, (uint32_t)capacity);
    #endif

    return network;
}

static vx_user_data_object setCreateParams_TrailerPose(vx_context context)
{
    vx_status status;

    vx_user_data_object  createParams;
    vx_map_id  map_id;
    vx_uint32  capacity;
    void *createParams_buffer = NULL;

    capacity = sizeof(TIDL_CreateParams);
    createParams = vxCreateUserDataObject(context, "TIDL_CreateParams", capacity, NULL );

    status = vxGetStatus((vx_reference)createParams);

    if (VX_SUCCESS == status)
    {
        status = vxMapUserDataObject(createParams, 0, capacity, &map_id,
                        (void **)&createParams_buffer, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST, 0);

        if (VX_SUCCESS == status)
        {
            if(createParams_buffer)
            {
                TIDL_CreateParams *prms = createParams_buffer;

                TIDL_createParamsInit(prms);

                prms->isInbufsPaded                 = 1;
                prms->quantRangeExpansionFactor     = 1.0;
                prms->quantRangeUpdateFactor        = 0.0;
#ifdef x86_64
                prms->flowCtrl                      = 1;
#endif
                prms->traceLogLevel                 = 0;
                prms->traceWriteLevel               = 0;
            }
            else
            {
                ME_Debugger_F_Printf_v("app_tidl: ERROR: Unable to allocate memory for create time params! %d bytes\n", capacity);
            }

            vxUnmapUserDataObject(createParams, map_id);
        }
    }

    return createParams;
}

static vx_user_data_object setInArgs_TrailerPose(vx_context context)
{
    vx_status status;

    vx_user_data_object  inArgs;
    vx_map_id  map_id;
    vx_uint32  capacity;
    void *inArgs_buffer = NULL;

    capacity = sizeof(TIDL_InArgs);
    inArgs = vxCreateUserDataObject(context, "TIDL_InArgs", capacity, NULL );

    status = vxGetStatus((vx_reference)inArgs);

    if (VX_SUCCESS == status)
    {
        status = vxMapUserDataObject(inArgs, 0, capacity, &map_id,
                        (void **)&inArgs_buffer, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST, 0);

        if (VX_SUCCESS == status)
        {
            if(inArgs_buffer)
            {
              TIDL_InArgs *prms = inArgs_buffer;
              prms->iVisionInArgs.size         = sizeof(TIDL_InArgs);
              prms->iVisionInArgs.subFrameInfo = 0;
            }
            else
            {
                ME_Debugger_F_Printf_v("app_tidl: Unable to allocate memory for inArgs! %d bytes\n", capacity);
            }

            vxUnmapUserDataObject(inArgs, map_id);
        }
    }

    return inArgs;
}

static vx_user_data_object setOutArgs_TrailerPose(vx_context context)
{
    vx_status status;

    vx_user_data_object  outArgs;
    vx_map_id  map_id;
    vx_uint32  capacity;
    void *outArgs_buffer = NULL;

    capacity = sizeof(TIDL_outArgs);
    outArgs = vxCreateUserDataObject(context, "TIDL_outArgs", capacity, NULL );

    status = vxGetStatus((vx_reference)outArgs);

    if (VX_SUCCESS == status)
    {
        status = vxMapUserDataObject(outArgs, 0, capacity, &map_id,
                        (void **)&outArgs_buffer, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST, 0);

        if (VX_SUCCESS == status)
        {
            if(outArgs_buffer)
            {
              TIDL_outArgs *prms = outArgs_buffer;
              prms->iVisionOutArgs.size         = sizeof(TIDL_outArgs);
            }
            else
            {
                ME_Debugger_F_Printf_v("app_tidl: Unable to allocate memory for outArgs! %d bytes\n", capacity);
            }

            vxUnmapUserDataObject(outArgs, map_id);
        }
    }

    return outArgs;
}

static void createInputTensors_TrailerPose(AppObj_TrailerPose *obj, vx_context context, vx_user_data_object config, vx_tensor *input_tensors)
{
    vx_size   input_sizes[APP_MAX_TENSOR_DIMS];

    uint32_t id;

    sTIDL_IOBufDesc_t *ioBufDesc = &obj->ioBufDesc;

    for(id = 0; id < ioBufDesc->numInputBuf; id++) {

        input_sizes[0] = ioBufDesc->inWidth[id]  + ioBufDesc->inPadL[id] + ioBufDesc->inPadR[id];
        input_sizes[1] = ioBufDesc->inHeight[id] + ioBufDesc->inPadT[id] + ioBufDesc->inPadB[id];
        input_sizes[2] = ioBufDesc->inNumChannels[id];

        vx_size data_type = getTensorDataType(ioBufDesc->inElementType[id]);

        if(data_type != VX_TYPE_INVALID)
          input_tensors[id] = vxCreateTensor(context, 3, input_sizes, data_type, 0);
    }

    return;
}

static void createOutputTensors_TrailerPose(AppObj_TrailerPose *obj, vx_context context, vx_user_data_object config, vx_tensor *output_tensors)
{
    vx_size output_sizes[APP_MAX_TENSOR_DIMS];

    uint32_t id;

    sTIDL_IOBufDesc_t *ioBufDesc = &obj->ioBufDesc;

    for(id = 0; id < ioBufDesc->numOutputBuf; id++) {

        output_sizes[0] = ioBufDesc->outWidth[id]  + ioBufDesc->outPadL[id] + ioBufDesc->outPadR[id];
        output_sizes[1] = ioBufDesc->outHeight[id] + ioBufDesc->outPadT[id] + ioBufDesc->outPadB[id];
        output_sizes[2] = ioBufDesc->outNumChannels[id];

        vx_size data_type = getTensorDataType(ioBufDesc->outElementType[id]);

        if(data_type != VX_TYPE_INVALID)
        {
          output_tensors[id] = vxCreateTensor(context, 3, output_sizes, data_type, 0);
        }
    }
    return;
}

static void WriteOutput_TrailerPose(AppObj_TrailerPose *obj, vx_user_data_object config, vx_tensor *output_tensors, float_t* o_classProb_f32, uint32_t* v_classID)
{
    vx_status status = VX_SUCCESS;

    vx_size output_sizes[APP_MAX_TENSOR_DIMS];

    int32_t id, i, j;

    sTIDL_IOBufDesc_t *ioBufDesc;

    ioBufDesc = &obj->ioBufDesc;
    
    #if ENABLE_DEBUG_THA
      // ME_Debugger_F_Printf_v("\n### WriteOutput_TrailerPose: ioBufDesc->numOutputBuf = %d \n", ioBufDesc->numOutputBuf);
      // ME_Debugger_F_Printf_v("\n### WriteOutput_TrailerPose: ioBufDesc->outTensorScale[0] = %f \n", ioBufDesc->outTensorScale[0]);
    #endif

    for(id = 0; id < ioBufDesc->numOutputBuf; id++)
    {
        vx_size data_type = getTensorDataType(ioBufDesc->outElementType[id]);

        output_sizes[0] = ioBufDesc->outWidth[id]  + ioBufDesc->outPadL[id] + ioBufDesc->outPadR[id];
        output_sizes[1] = ioBufDesc->outHeight[id] + ioBufDesc->outPadT[id] + ioBufDesc->outPadB[id];
        output_sizes[2] = ioBufDesc->outNumChannels[id];
        #if ENABLE_DEBUG_THA
        // ME_Debugger_F_Printf_v(" output_sizes[0] = %d, dim = %d padL = %d padR = %d\n", (uint32_t)output_sizes[0], ioBufDesc->outWidth[id], ioBufDesc->outPadL[id], ioBufDesc->outPadR[id]);
        // ME_Debugger_F_Printf_v(" output_sizes[1] = %d, dim = %d padT = %d padB = %d\n", (uint32_t)output_sizes[1], ioBufDesc->outHeight[id], ioBufDesc->outPadT[id], ioBufDesc->outPadB[id]);
        // ME_Debugger_F_Printf_v(" output_sizes[2] = %d, dim = %d \n", (uint32_t)output_sizes[2], ioBufDesc->outNumChannels[id]);
        #endif
        if(status == VX_SUCCESS)
        {
            status = vxGetStatus((vx_reference)output_tensors[id]);
        }
        if (VX_SUCCESS == status)
        {
            void *output_buffer;

            vx_map_id map_id_output;

            vx_size output_strides[APP_MAX_TENSOR_DIMS];
            vx_size start[APP_MAX_TENSOR_DIMS];

            start[0] = start[1] = start[2] = start[3] = 0;

            output_strides[0] = sizeof(vx_int8);

            if((data_type == VX_TYPE_INT8) ||
               (data_type == VX_TYPE_UINT8))
            {
                output_strides[0] = sizeof(vx_int8);
            }
            else if((data_type == VX_TYPE_INT16) ||
                    (data_type == VX_TYPE_UINT16))
            {
                output_strides[0] = sizeof(vx_int16);
            }
            else if(data_type == VX_TYPE_FLOAT32)
            {
                output_strides[0] = sizeof(vx_float32);
            }

            output_strides[1] = output_sizes[0] * output_strides[0];
            output_strides[2] = output_sizes[1] * output_strides[1];

            status = tivxMapTensorPatch(output_tensors[id], 3, start, output_sizes, &map_id_output, output_strides, &output_buffer, VX_READ_ONLY, VX_MEMORY_TYPE_HOST);

            if(status == VX_SUCCESS)
            {
                vx_uint32 classid[5] = {0};
                vx_uint32 label_offset;

                label_offset = 0;
                if(ioBufDesc->outWidth[id] == 1001)
                {
                    label_offset = 0;
                }
                else if(ioBufDesc->outWidth[id] == 1000)
                {
                    label_offset = 1;
                }

                float32_t *pOut;
                pOut = (float32_t *)output_buffer;

                #if ENABLE_DEBUG_THA
                  // for(int k=0;k<NUMBER_CLASSID_TRAILERPOSE;k++)
                  // {
                  //    ME_Debugger_F_Printf_v("### WriteOutput_TrailerPose: pOut[%d]=%f \n", k, pOut[k]);
                  // }
                  for(int k=0;k<NUMBER_CLASSID_TRAILERPOSE;k++)
                  {
                     ME_Debugger_F_Printf_v("%f, ", ((pOut[k])/(ioBufDesc->outTensorScale[0])) );
                  }
                #endif

                *o_classProb_f32 = 0.0f;
                for( size_t i = 0; i < NUMBER_CLASSID_TRAILERPOSE; i++ )
                {
                  float_t temp = (float_t)((pOut[i])/(ioBufDesc->outTensorScale[0]));
                  if( temp > *o_classProb_f32 )
                  {
                      *o_classProb_f32 = temp;
                      *v_classID = i;
                  }
                }
            }
            tivxUnmapTensorPatch(output_tensors[id], map_id_output);
        }
    }
    #if ENABLE_DEBUG_THA
      APP_PRINTF("app_tidl: Showing output ... Done.\n");
    #endif
}

#endif
