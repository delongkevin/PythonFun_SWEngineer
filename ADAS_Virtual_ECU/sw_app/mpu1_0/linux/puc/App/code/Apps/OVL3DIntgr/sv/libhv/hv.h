/*******************************************************************************
 * hv.h
 *
 * Historcial-view module
 *
 * Copyright (c) 2015-2021 Cogent Embedded Inc.
 * ALL RIGHTS RESERVED.
 *
 * The source code contained or described herein and all documents related to the
 * source code("Software") or their modified versions are owned by
 * Cogent Embedded Inc. or its affiliates.
 *
 * No part of the Software may be used, copied, reproduced, modified, published,
 * uploaded, posted, transmitted, distributed, or disclosed in any way without
 * prior express written permission from Cogent Embedded Inc.
 *
 * Cogent Embedded Inc. grants a nonexclusive, non-transferable, royalty-free
 * license to use the Software to Licensee without the right to sublicense.
 * Licensee agrees not to distribute the Software to any third-party without
 * the prior written permission of Cogent Embedded Inc.
 *
 * Unless otherwise agreed by Cogent Embedded Inc. in writing, you may not remove
 * or alter this notice or any other notice embedded in Software in any way.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *******************************************************************************/

#ifndef __LIBHV_HV_H
#define __LIBHV_HV_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "config.h"
#include "vehicle-state.h"
#include "../libsv/vbo-dynarray.h"
#include "../libsv/mesh-gen.h"

/*******************************************************************************
 * Types declarations
 ******************************************************************************/

/**> Opaque type declaration */
typedef struct  hv_data     hv_data_t;

/**
 * @brief   Vertex attribute encoding:
 *          [0] - X-coordinate, pixel
 *          [1] - Y-coordinate, pixel
 *          [2] - U-coordinate, pixel
 *          [3] - V-coordinate, pixel
 *          [4] - slice level index
 *          [5] - blending weight
 */
typedef GLfloat hv_vertex_t[6];

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Update HV-buffers mesh parameters
 *
 * @param   hv[in]          Historical view data
 * @param   cfg[in]         Global configuration data
 * @param   vehicle[in]     Vehicle state data
 * @param   gen[in]         Mesh generator
 *
 * @return                  Negative on failure
 */
extern int hv_update(hv_data_t *hv, cfg_data_t *cfg, vehicle_state_t *vehicle, mesh_gen_t *gen);

/**
 * @brief   Process HV-buffers update
 *
 * @param   hv[in]          Historical view data
 * @param   cfg[in]         Global configuration data
 * @param   vehicle[in]     Vehicle-state data
 * @param   texture[in]     Input textures array
 *
 * @return                  Negative on failure
 */
extern int hv_process(hv_data_t *hv, cfg_data_t *cfg, vehicle_state_t *vehicle, texture_data_t **texture, float32_t (*CC)[3][3]);

/**
 * @brief   Render historical-view mesh
 */
extern void hv_mesh_render(hv_data_t *hv, vbo_dynarray_t *vbo);

/**
 * @brief   Create HV-module
 *
 * @param   cfg[in]         Global configuration data
 *
 * @return                  Historical view data, or NULL on failure
 */
extern hv_data_t * hv_create(cfg_data_t *cfg);

/**
 * @brief   Reset HV-module operation
 *
 * @param   hv[in]          Historical view module data
 */
extern void hv_reset(hv_data_t *hv);

/**
 * @brief   Create HV-mesh for single strip
 *
 * @param   hv[in]      Historical view data
 * @param   vbo[in]     Mesh VBO array
 * @param   v[in]       World-coordinates of the points in a strip
 * @param   x[in]       Strip origin {x0,y0}
 * @param   d[in]       Quad dimensions {dx, dy}
 * @param   n[in]       Number of point-pairs in a strip
 *
 * @return              Negative on failure
 */
extern int hv_mesh_create_strip(hv_data_t *hv, vbo_dynarray_t *vbo, float32_t (*v)[3], float32_t *x, float32_t *d, int32_t n);


#endif  /* __LIBHV_HV_H */
