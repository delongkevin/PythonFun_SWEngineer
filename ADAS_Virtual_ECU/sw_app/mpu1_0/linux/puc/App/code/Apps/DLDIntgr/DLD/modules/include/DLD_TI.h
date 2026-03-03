//--------------------------------------------------------------------------
/// @file DLD_TI.h
/// @brief Contains the definition of TIOVX APIs.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
//  --------------------------------------------------------------------------

#ifndef DLD_TI_H_
#define DLD_TI_H_

#ifdef APP_TIDL_TRACE_DUMP
#include <tivx_utils_tidl_trace.h>
#endif

#include "app_common.h"
#include "app_tidl_module.h"
#include "../../algo/common/DLDDef.h"
#include "platform/PlatformAPI.h"

typedef struct {
  TIDLObj tidlObj;

  vx_char input_file_path[APP_MAX_FILE_PATH];
  vx_char output_file_path[APP_MAX_FILE_PATH];

  vx_tensor input_tensors[APP_MAX_TENSORS];
  vx_tensor output_tensors[APP_MAX_TENSORS];

  uint32_t input_width;
  uint32_t input_height;
  uint32_t output_width;
  uint32_t output_height;

  /* OpenVX references */
  vx_context context;
  vx_graph graph;

  vx_int32 start_frame;
  vx_int32 num_frames;

  sTIDL_IOBufDesc_t ioBufDesc;
} AppObj_DLD;

typedef struct {
  float32_t v_occlusionProb[DLD_OUTPUT_OCC_WIDTH];
  float32_t v_luminanceProb[DLD_OUTPUT_LUM_WIDTH];
} DNN_DLD_out;

void app_parse_cmd_line_args_DLD(AppObj_DLD *obj);
vx_status app_init_DLD(AppObj_DLD *obj);
void app_deinit_DLD(AppObj_DLD *obj);
vx_status app_create_graph_DLD(AppObj_DLD *obj);
vx_status app_verify_graph_DLD(AppObj_DLD *obj);
vx_status app_run_graph_DLD(AppObj_DLD *obj);
void app_delete_graph_DLD(AppObj_DLD *obj);
void readConfig_DLD(AppObj_DLD *obj, sTIDL_IOBufDesc_t *ioBufDescFeature, TIDLObj *tidlObj);
vx_status app_run_graph_for_one_frame_sequential_DLD(AppObj_DLD *obj, const uint8_t *inputImage);
void writeOutput_DLD(AppObj_DLD *obj, DNN_DLD_out* out);
vx_status app_create_graph_tidl_tens_DLD(vx_context context, vx_graph graph, TIDLObj *tidlObj, vx_tensor *input_tensors, vx_tensor *output_tensors);

#endif // DLD_TI_H_