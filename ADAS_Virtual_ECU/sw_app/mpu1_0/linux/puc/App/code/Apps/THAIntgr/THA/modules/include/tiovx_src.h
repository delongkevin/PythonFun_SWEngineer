/*
 * support.h
 *
 *  Created on: Mar 3, 2022
 *      Author: user0
 */

#ifndef APP_TIDL_OD_SUPPORT_H_
#define APP_TIDL_OD_SUPPORT_H_
#include "app_common.h"
//#include "itidl_ti.h"
#include "modules/include/app_modules.h"
#include "modules/include/app_tidl_module.h"

vx_status writeTIDLInput(char *file_name, vx_tensor *output);
vx_status app_create_graph_tidl_tens(vx_context context, vx_graph graph, TIDLObj *tidlObj, vx_tensor *input_tensors);
vx_status writeTIDLOutput_local(char *file_name, TIDLObj *tidlObj, vx_int32 width, vx_int32 height, vx_int32 frame_id);

#endif /* APP_TIDL_OD_SUPPORT_H_ */
