//--------------------------------------------------------------------------
/// @file DLD_TI.c
/// @brief Contains the job definition for the DLD DNN for TIDL
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
//  --------------------------------------------------------------------------


#include "DLD_TI.h"
#include "platform/PlatformAPI.h"

static uint32_t num_params;
static uint32_t max_params;

static void initParam(vx_reference params[], uint32_t _max_params) {
  num_params = 0;
  max_params = _max_params;
}

static void addParam(vx_reference params[], vx_reference obj) {
  if (num_params <= max_params) {
    params[num_params] = obj;
    num_params++;
  }
  else {
    APP_ERROR("Error! DLDL num_params > max_params!\n");
  }

}

vx_status app_create_graph_tidl_tens_DLD(vx_context context, vx_graph graph, TIDLObj *tidlObj, vx_tensor *input_tensors, vx_tensor *output_tensors) {
  vx_status status = VX_SUCCESS;

  vx_reference params[APP_MODULES_MAX_PARAMS];

  tidlObj->node = NULL;

  /* Initialize param array */
  initParam(params, APP_MODULES_MAX_PARAMS);

  /* The 1st param MUST be config array */
  addParam(params, (vx_reference) tidlObj->config);

  /* The 2nd param MUST be network tensor */
  addParam(params, (vx_reference) tidlObj->network);

  /* The 3rd param MUST be create params */
  addParam(params, (vx_reference) tidlObj->createParams);

  /* The 4th param MUST be inArgs */
  vx_user_data_object inArgs = (vx_user_data_object) vxGetObjectArrayItem((vx_object_array) tidlObj->in_args_arr, 0);
  addParam(params, (vx_reference) inArgs);
  vxReleaseUserDataObject(&inArgs);

  /* The 5th param MUST be outArgs */
  vx_user_data_object outArgs = (vx_user_data_object) vxGetObjectArrayItem((vx_object_array) tidlObj->out_args_arr, 0);
  addParam(params, (vx_reference) outArgs);
  vxReleaseUserDataObject(&outArgs);

  /* The 6th param MUST be NULL if trace data dump is not enabled */
  addParam(params, NULL);

  tidlObj->node = tivxTIDLNode(graph, tidlObj->kernel, params, input_tensors, output_tensors);
  status = vxGetStatus((vx_reference) tidlObj->node);
  vxSetReferenceName((vx_reference) tidlObj->node, "TIDLNode");

  return status;
}

static vx_size getTensorDataType(vx_int32 tidl_type) {
  vx_size openvx_type = VX_TYPE_INVALID;

  if (tidl_type == TIDL_UnsignedChar) {
    openvx_type = VX_TYPE_UINT8;
  }
  else if (tidl_type == TIDL_SignedChar) {
    openvx_type = VX_TYPE_INT8;
  }
  else if (tidl_type == TIDL_UnsignedShort) {
    openvx_type = VX_TYPE_UINT16;
  }
  else if (tidl_type == TIDL_SignedShort) {
    openvx_type = VX_TYPE_INT16;
  }
  else if (tidl_type == TIDL_UnsignedWord) {
    openvx_type = VX_TYPE_UINT32;
  }
  else if (tidl_type == TIDL_SignedWord) {
    openvx_type = VX_TYPE_INT32;
  }
  else if (tidl_type == TIDL_SinglePrecFloat) {
    openvx_type = VX_TYPE_FLOAT32;
  }

  return openvx_type;
}

void createInputTensors_DLD(sTIDL_IOBufDesc_t *ioBufDesc, vx_context context, vx_tensor *input_tensors) {
  vx_size input_sizes[APP_MAX_TENSOR_DIMS];

  for (int32_t id = 0; id < ioBufDesc->numInputBuf; id++) {
    input_sizes[0] = ioBufDesc->inWidth[id] + ioBufDesc->inPadL[id] + ioBufDesc->inPadR[id];
    input_sizes[1] = ioBufDesc->inHeight[id] + ioBufDesc->inPadT[id] + ioBufDesc->inPadB[id];
    input_sizes[2] = ioBufDesc->inNumChannels[id];

    vx_size data_type = getTensorDataType(ioBufDesc->inElementType[id]);
    if (data_type != VX_TYPE_INVALID) {
      input_tensors[id] = vxCreateTensor(context, 3, input_sizes, data_type, 0);
    }
  }
}

static void createOutputTensors_DLD(sTIDL_IOBufDesc_t *ioBufDesc, vx_context context, vx_tensor *output_tensors) {
  vx_size output_sizes[APP_MAX_TENSOR_DIMS];

  for(int32_t id = 0; id < ioBufDesc->numOutputBuf; id++) {
    output_sizes[0] = ioBufDesc->outWidth[id]  + ioBufDesc->outPadL[id] + ioBufDesc->outPadR[id];
    output_sizes[1] = ioBufDesc->outHeight[id] + ioBufDesc->outPadT[id] + ioBufDesc->outPadB[id];
    output_sizes[2] = ioBufDesc->outNumChannels[id];

    vx_size data_type = getTensorDataType(ioBufDesc->outElementType[id]);
    if(data_type != VX_TYPE_INVALID) {
      output_tensors[id] = vxCreateTensor(context, 3, output_sizes, data_type, 0);
    }
  }
}

static vx_status readInput(sTIDL_IOBufDesc_t *ioBufDesc, vx_tensor *input_tensors, const uint8_t *input_image, vx_size input_width, vx_size input_height) {
  vx_status status = VX_SUCCESS;
  void *input_buffer = NULL;
  vx_map_id map_id_input;
  vx_size start[APP_MAX_TENSOR_DIMS];
  vx_size input_strides[APP_MAX_TENSOR_DIMS];
  vx_size input_sizes[APP_MAX_TENSOR_DIMS];
  //ME_Debugger_F_Printf_v("[DLD] readInput : ioBufDesc->numInputBuf = %d \n",ioBufDesc->numInputBuf);

  for (int32_t id = 0; id < ioBufDesc->numInputBuf; id++) {
    input_sizes[0] = ioBufDesc->inWidth[id] + ioBufDesc->inPadL[id] + ioBufDesc->inPadR[id]; //Width = 320+1+0
    input_sizes[1] = ioBufDesc->inHeight[id] + ioBufDesc->inPadT[id] + ioBufDesc->inPadB[id]; //height = 320+1+2
    input_sizes[2] = ioBufDesc->inNumChannels[id]; //rgb = 3

    start[0] = start[1] = start[2] = 0;

    input_strides[0] = sizeof(vx_int8);
    input_strides[1] = input_sizes[0] * input_strides[0];
    input_strides[2] = input_sizes[1] * input_strides[1];

    DLD_DEBUG_PRINT(DLD_TRACE_LOW, "[DLD] input_sizes[0] = %d, dim = %d padL = %d padR = %d\n", (uint32_t)input_sizes[0], ioBufDesc->inWidth[id], ioBufDesc->inPadL[id], ioBufDesc->inPadR[id]);
    DLD_DEBUG_PRINT(DLD_TRACE_LOW, "[DLD] input_sizes[1] = %d, dim = %d padT = %d padB = %d\n", (uint32_t)input_sizes[1], ioBufDesc->inHeight[id], ioBufDesc->inPadT[id], ioBufDesc->inPadB[id]);
    DLD_DEBUG_PRINT(DLD_TRACE_LOW, "[DLD] input_sizes[2] = %d, dim = %d \n", (uint32_t)input_sizes[2], ioBufDesc->inNumChannels[id]);
    DLD_DEBUG_PRINT(DLD_TRACE_LOW, "[DLD] input_strides[0,1,2] = [%d, %d, %d] \n", (uint32_t)input_strides[0], (uint32_t)input_strides[1], (uint32_t)input_strides[2]);

    if (VX_SUCCESS == status) {
      status = tivxMapTensorPatch(input_tensors[id], 3, start, input_sizes, &map_id_input, input_strides, &input_buffer, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST);
    }

    if (VX_SUCCESS == status) {
      uint32_t capacity = input_sizes[0] * input_sizes[1] * input_sizes[2];
      memcpy(input_buffer, input_image, capacity);
      tivxUnmapTensorPatch(input_tensors[id], map_id_input);
    }
    else {
      DLD_DEBUG_PRINT_ERROR("readInput: Failed copying input tensor <id=%d, status=%d>", id, status);
    }
  }

  return status;
}

static void app_set_cfg_default_DLD(AppObj_DLD *obj) {
  snprintf(obj->tidlObj.config_file_path, APP_MAX_FILE_PATH, ".");
  snprintf(obj->tidlObj.network_file_path, APP_MAX_FILE_PATH, ".");
  snprintf(obj->input_file_path, APP_MAX_FILE_PATH, ".");
}

static void app_parse_cfg_file_DLD(AppObj_DLD *obj, vx_char *cfg_file_name) {
  strcpy(obj->tidlObj.config_file_path, "/ti_fs/vision_apps/tidl_io_DLD_11_1_23_grid_v4_1.bin");
  strcpy(obj->tidlObj.network_file_path, "/ti_fs/vision_apps/tidl_net_DLD_11_1_23_grid_v4.bin");

  strcpy(obj->input_file_path, "/ti_fs/vision_apps");
  strcpy(obj->output_file_path, "/ti_fs/vision_apps");
  
  obj->start_frame = 1;
  obj->num_frames = 1;

  obj->input_width = DLD_INPUT_WIDTH;
  obj->input_height = DLD_INPUT_HEIGHT;
  obj->output_width = DLD_INPUT_WIDTH;
  obj->output_height = DLD_INPUT_HEIGHT;
}

void app_parse_cmd_line_args_DLD(AppObj_DLD *obj) {
  app_set_cfg_default_DLD(obj);
  app_parse_cfg_file_DLD(obj, "app_DLD.cfg");
  return;
}

void readConfig_DLD(AppObj_DLD *obj, sTIDL_IOBufDesc_t *ioBufDescFeature, TIDLObj *tidlObj) {
  vx_status status = VX_SUCCESS;

  tivxTIDLJ7Params *tidlParams = NULL;
  sTIDL_IOBufDesc_t *ioBufDesc = NULL;
  vx_user_data_object config = NULL;
  vx_uint32 capacity;
  vx_map_id map_id;

  FILE *fp_config;
  vx_size read_count;

  fp_config = fopen(tidlObj->config_file_path, "rb");

  if (fp_config == NULL) {
    ME_Debugger_F_Printf_v("\n app_tidl: ERROR: Unable to open IO config file %s ", tidlObj->config_file_path);
  }

  fseek(fp_config, 0, SEEK_END);
  capacity = ftell(fp_config);
  fseek(fp_config, 0, SEEK_SET);

  if (capacity != sizeof(sTIDL_IOBufDesc_t)) {
    ME_Debugger_F_Printf_v("\n app_tidl: ERROR: Config file size (%d bytes) does not match size of sTIDL_IOBufDesc_t (%d bytes)", capacity, (vx_uint32) sizeof(sTIDL_IOBufDesc_t));
    fclose(fp_config);
  }

  /* Create a user struct type for handling config data*/
  config = vxCreateUserDataObject(obj->context, "tivxTIDLJ7Params", sizeof(tivxTIDLJ7Params), NULL);
  status = vxGetStatus((vx_reference) config);
  if (VX_SUCCESS == status) {
    status = vxMapUserDataObject(config, 0, sizeof(tivxTIDLJ7Params), &map_id,
        (void**) &tidlParams, VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST, 0);

    if (VX_SUCCESS == status) {
      if (tidlParams == NULL) {
        ME_Debugger_F_Printf_v("\n app_tidl: ERROR: Map of config object failed");
        fclose(fp_config);
      }

      tivx_tidl_j7_params_init(tidlParams);

      ioBufDesc = (sTIDL_IOBufDesc_t*) &tidlParams->ioBufDesc;

      read_count = fread(ioBufDesc, capacity, 1, fp_config);
      if (read_count != 1) {
        ME_Debugger_F_Printf_v("\n app_tidl: ERROR: Unable to read config file");
      }
      fclose(fp_config);

      memcpy(ioBufDescFeature, ioBufDesc, capacity);
      if (status == VX_SUCCESS) {
        status = vxUnmapUserDataObject(config, map_id);
      }
    }
    else {
      fclose(fp_config);
    }
  }
  else {
    fclose(fp_config);
  }

  vxReleaseUserDataObject(&config);

  //return config;
}

vx_status app_init_DLD(AppObj_DLD *obj)
{
  vx_status status = VX_SUCCESS;

  /* Create OpenVx Context */
  obj->context = vxCreateContext();
  status = vxGetStatus((vx_reference) obj->context);

  if (status == VX_SUCCESS) {
    tivxHwaLoadKernels(obj->context);
    tivxImgProcLoadKernels(obj->context);
    tivxTIDLLoadKernels(obj->context);
  }

  if (status == VX_SUCCESS) {
    status = app_init_tidl(obj->context, &obj->tidlObj, "tidl_obj_DLD", 1);
    readConfig_DLD(obj, &obj->ioBufDesc, &obj->tidlObj);
  }

  return status;
}

void app_deinit_DLD(AppObj_DLD *obj) {
  app_deinit_tidl(&obj->tidlObj);

  tivxTIDLUnLoadKernels(obj->context);

  tivxImgProcUnLoadKernels(obj->context);

  tivxHwaUnLoadKernels(obj->context);

  vxReleaseContext(&obj->context);
}

vx_status app_create_graph_DLD(AppObj_DLD *obj) {
  vx_status status = VX_SUCCESS;

  obj->graph = vxCreateGraph(obj->context);
  status = vxGetStatus((vx_reference) obj->graph);

  if (status == VX_SUCCESS) {
    status = vxSetReferenceName((vx_reference) obj->graph, "OpenVxGraph");
  }

  /* Create array of input tensors */
  createInputTensors_DLD(&obj->ioBufDesc, obj->context, obj->input_tensors);

  /* Create array of output tensors */
  createOutputTensors_DLD(&obj->ioBufDesc, obj->context, obj->output_tensors);

  if (status == VX_SUCCESS) {
    status = app_create_graph_tidl_tens_DLD(obj->context, obj->graph, &obj->tidlObj, obj->input_tensors, obj->output_tensors);
  }

  return status;
}

vx_status app_verify_graph_DLD(AppObj_DLD *obj) {
  vx_status status = VX_SUCCESS;

  status = vxVerifyGraph(obj->graph);

  /* wait a while for prints to flush */
  tivxTaskWaitMsecs(100);

  return status;
}

vx_status app_run_graph_for_one_frame_sequential_DLD(AppObj_DLD *obj, const uint8_t *inputImage) {
  vx_status status = VX_SUCCESS;

  status = readInput(&obj->ioBufDesc, obj->input_tensors, inputImage, obj->input_width, obj->input_height);
  status = vxProcessGraph(obj->graph);
  if(VX_SUCCESS != status) {
    DLD_DEBUG_PRINT(DLD_TRACE_MID, "[DLD] vxProcessGraph status=%d\n", status);
  }
  return status;
}

void app_delete_graph_DLD(AppObj_DLD *obj) {
  app_delete_tidl(&obj->tidlObj);
  vxReleaseGraph(&obj->graph);
  for(uint32_t id = 0; id < obj->tidlObj.num_input_tensors; id++) {
    vxReleaseTensor(&obj->input_tensors[id]);
  }

  for(uint32_t id = 0; id < obj->tidlObj.num_output_tensors; id++) {
    vxReleaseTensor(&obj->output_tensors[id]);
  }
}

void writeOutput_DLD(AppObj_DLD *obj, DNN_DLD_out* out) {
  sTIDL_IOBufDesc_t *ioBufDesc = &obj->ioBufDesc;
  DLD_DEBUG_PRINT(DLD_TRACE_LOW, "[DLD] writeOutput: ioBufDesc->numOutputBuf = %d\n", ioBufDesc->numOutputBuf);
  DLD_DEBUG_PRINT(DLD_TRACE_LOW, "[DLD] writeOutput: ioBufDesc->outTensorScale[0] = %f\n", ioBufDesc->outTensorScale[0]);
  for(int32_t id = 0; id < ioBufDesc->numOutputBuf; id++) {
    vx_size output_sizes[APP_MAX_TENSOR_DIMS];
    vx_size data_type = getTensorDataType(ioBufDesc->outElementType[id]);
    output_sizes[0] = ioBufDesc->outWidth[id]  + ioBufDesc->outPadL[id] + ioBufDesc->outPadR[id];
    output_sizes[1] = ioBufDesc->outHeight[id] + ioBufDesc->outPadT[id] + ioBufDesc->outPadB[id];
    output_sizes[2] = ioBufDesc->outNumChannels[id];
    DLD_DEBUG_PRINT(DLD_TRACE_LOW, "[DLD] output_sizes[0] = %d, dim = %d padL = %d padR = %d\n", (uint32_t)output_sizes[0], ioBufDesc->outWidth[id], ioBufDesc->outPadL[id], ioBufDesc->outPadR[id]);
    DLD_DEBUG_PRINT(DLD_TRACE_LOW, "[DLD] output_sizes[1] = %d, dim = %d padT = %d padB = %d\n", (uint32_t)output_sizes[1], ioBufDesc->outHeight[id], ioBufDesc->outPadT[id], ioBufDesc->outPadB[id]);
    DLD_DEBUG_PRINT(DLD_TRACE_LOW, "[DLD] output_sizes[2] = %d, dim = %d\n", (uint32_t)output_sizes[2], ioBufDesc->outNumChannels[id]);

    vx_status status = vxGetStatus((vx_reference)obj->output_tensors[id]);
    if (VX_SUCCESS == status) {
      /* Compute output strides based on data type */
      vx_size output_strides[APP_MAX_TENSOR_DIMS];
      output_strides[0] = sizeof(vx_int8);
      if((VX_TYPE_INT8 == data_type) || (VX_TYPE_UINT8 == data_type)) {
        output_strides[0] = sizeof(vx_int8);
      }
      else if((VX_TYPE_INT16 == data_type) || (VX_TYPE_UINT16 == data_type)) {
        output_strides[0] = sizeof(vx_int16);
      }
      else if(VX_TYPE_FLOAT32 == data_type) {
        output_strides[0] = sizeof(vx_float32);
      }
      output_strides[1] = output_sizes[0] * output_strides[0];
      output_strides[2] = output_sizes[1] * output_strides[1];
      DLD_DEBUG_PRINT(DLD_TRACE_LOW, "[DLD] output_strides[0,1,2] = [%d, %d, %d]\n", output_strides[0], output_strides[1], output_strides[2]);

      void *output_buffer;
      vx_map_id map_id_output;
      vx_size start[APP_MAX_TENSOR_DIMS] = { 0 };
      status = tivxMapTensorPatch(obj->output_tensors[id], 3, start, output_sizes, &map_id_output, output_strides, &output_buffer, VX_READ_ONLY, VX_MEMORY_TYPE_HOST);
      if(VX_SUCCESS == status) {
        int8_t *pOut8 = (int8_t *)output_buffer;
        uint32_t numOutputs = output_sizes[0] * output_sizes[1] * output_sizes[2];
        DLD_DEBUG_PRINT(DLD_TRACE_LOW, "[DLD] writeOutput: DNN results[%d-%d] < ", id, numOutputs);
        for(uint8_t i = 0u; i < numOutputs; i++) {
          float32_t value = (float32_t)((float32_t)(pOut8[i])/ioBufDesc->outTensorScale[id]);
          DLD_DEBUG_PRINT(DLD_TRACE_LOW, "%d, ", (int)value);
          switch (id) {
            case DLD_OUTPUT_OCC_ID:
              out->v_occlusionProb[i] = value;
              break;
            case DLD_OUTPUT_LUM_ID:
              out->v_luminanceProb[i] = value;
              break;
          }
          
        }
        DLD_DEBUG_PRINT(DLD_TRACE_LOW, ">\n");
      }
      else {
        DLD_DEBUG_PRINT_ERROR("Unable to map tensor patch <status=%d>", status);
      }
      tivxUnmapTensorPatch(obj->output_tensors[id], map_id_output);
    }
    else {
      DLD_DEBUG_PRINT_ERROR("Invalid output tensor <id=%d, status=%d>", id, status);
    }
  }
}

