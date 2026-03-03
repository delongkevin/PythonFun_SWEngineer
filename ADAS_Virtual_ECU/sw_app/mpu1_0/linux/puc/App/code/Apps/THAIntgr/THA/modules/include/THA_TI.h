//--------------------------------------------------------------------------
/// @file THA_TI.h
/// @brief Contains the definition of TIOVX APIs.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
//  --------------------------------------------------------------------------

#ifndef THA_TI_H_
#define THA_TI_H_

#ifdef APP_TIDL_TRACE_DUMP
#include <tivx_utils_tidl_trace.h>
#endif

#include "app_common.h"
#include "app_tidl_module.h"
#include "tiovx_src.h"

#define ENABLE_CD_HD 1
#define ENABLE_TrailerPose 0

#define ENABLE_OFFLINE_TEST_THA 0
#define ENABLE_DEBUG_THA 0
#define DUMP_OUTPUT_CSV 0

#define MAX_IMG_WIDTH  (2048)
#define MAX_IMG_HEIGHT (1024)
static const char *tensor_num_str[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"};

#ifdef ENABLE_CD_HD
typedef struct
{
  TIDLObj tidlObj;

  vx_char input_file_path[APP_MAX_FILE_PATH];
  vx_char output_file_path[APP_MAX_FILE_PATH];

  vx_tensor input_tensors[APP_MAX_TENSORS];

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
} AppObj_CD_HD;

typedef struct
{
  vx_uint32  ObjId;
  vx_int32   v_ClassID;
  vx_int32   xmin;
  vx_int32   xmax;
  vx_int32   ymin;
  vx_int32   ymax;
  vx_float32 v_prob;
}DNN_CDHD_out;

void app_parse_cmd_line_args_CD_HD(AppObj_CD_HD *obj);
vx_status app_init_CD_HD(AppObj_CD_HD *obj);
void app_deinit_CD_HD(AppObj_CD_HD *obj);
vx_status app_create_graph_CD_HD(AppObj_CD_HD *obj);
vx_status app_verify_graph_CD_HD(AppObj_CD_HD *obj);
vx_status app_run_graph_CD_HD(AppObj_CD_HD *obj);
void app_delete_graph_CD_HD(AppObj_CD_HD *obj);
void readConfig_CD_HD(AppObj_CD_HD *obj, sTIDL_IOBufDesc_t *ioBufDescFeature, TIDLObj *tidlObj);
vx_status app_run_graph_for_one_frame_sequential_CD_HD(AppObj_CD_HD *obj, const uint8_t *inputImage);
void WriteOutput_CDHD(AppObj_CD_HD *obj,vx_size input_width, vx_size input_height, DNN_CDHD_out *data_arr, uint8_t* numObject);
#endif


#ifdef ENABLE_TrailerPose
typedef struct {

    /* config options */
    TIDLObj tidlObj;

    //input
    char input_file_path[APP_MAX_FILE_PATH];
    char output_file_path[APP_MAX_FILE_PATH];

    sTIDL_IOBufDesc_t   ioBufDesc;
    /* OpenVX references */
    vx_context context;
    vx_graph   graph;

    vx_node    tidl_node;

    vx_tensor  input_tensors[APP_MAX_TENSORS];
    vx_tensor  output_tensors[APP_MAX_TENSORS];
    /*-----------------------------------------------------------------------------*/

    // This can be hardcoded or not needed

    /* Input image params */
    tivx_utils_bmp_image_params_t imgParams;

    uint32_t input_width;
    uint32_t input_height;
    uint32_t output_width;
    uint32_t output_height;

    uint8_t *pInPlanes;
    uint8_t *pOutPlanes;

    vx_user_data_object  inArgs;
    vx_user_data_object  outArgs;

} AppObj_TrailerPose;

static uint32_t num_params;
static uint32_t max_params;

void app_parse_cmd_line_args_TrailerPose(AppObj_TrailerPose *obj);
int app_init_TrailerPose(AppObj_TrailerPose *obj);
void app_delete_graph_TrailerPose(AppObj_TrailerPose *obj);
void app_deinit_TrailerPose(AppObj_TrailerPose *obj);
vx_status app_create_graph_TrailerPose(AppObj_TrailerPose *obj);
vx_status app_verify_graph_TrailerPose(AppObj_TrailerPose *obj);
vx_status app_run_graph_for_one_frame_TrailerPose(AppObj_TrailerPose *obj, const unsigned char* input_img_buffer, float_t* o_classProb_f32, uint32_t* v_classID);

#endif

#endif // THA_TI_H_