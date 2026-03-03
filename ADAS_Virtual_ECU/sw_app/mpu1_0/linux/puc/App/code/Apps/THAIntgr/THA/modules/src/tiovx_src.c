/*
 * tiovx_src.c
 *
 *  Created on: Mar 3, 2022
 *      Author: user0
 */
#include "tiovx_src.h"

static uint32_t num_params;
static uint32_t max_params;

static void initParam(vx_reference params[], uint32_t _max_params)
{
  num_params = 0;
  max_params = _max_params;
}

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

vx_status app_create_graph_tidl_tens(vx_context context, vx_graph graph, TIDLObj *tidlObj, vx_tensor *input_tensors)
{
  vx_status status = VX_SUCCESS;

  vx_reference params[APP_MODULES_MAX_PARAMS];

  vx_tensor input_tensor[APP_MODULES_MAX_TENSORS];
  vx_tensor output_tensor[APP_MODULES_MAX_TENSORS];
  APP_PRINTF("1\n");
  vx_uint32 i;

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
  APP_PRINTF("2\n");
  for (i = 0; i < tidlObj->num_input_tensors; i++)
  {
    input_tensor[i] = input_tensors[i];
  }
  for (i = 0; i < tidlObj->num_output_tensors; i++)
  {
    output_tensor[i] = (vx_tensor) vxGetObjectArrayItem((vx_object_array) tidlObj->output_tensor_arr[i], 0);
  }

  APP_PRINTF("3\n");
  tidlObj->node = tivxTIDLNode(graph, tidlObj->kernel, params, input_tensor, output_tensor);
  status = vxGetStatus((vx_reference) tidlObj->node);
  vxSetReferenceName((vx_reference) tidlObj->node, "TIDLNode");
  APP_PRINTF("4\n");

  for (i = 0; i < tidlObj->num_input_tensors; i++)
  {
    vxReleaseTensor(&input_tensor[i]);
  }

  for (i = 0; i < tidlObj->num_output_tensors; i++)
  {
    vxReleaseTensor(&output_tensor[i]);
  }
  return status;
}
