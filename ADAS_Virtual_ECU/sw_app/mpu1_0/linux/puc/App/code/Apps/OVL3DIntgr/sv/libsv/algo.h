/*******************************************************************************
 * algo.c
 *
 * Algo-view generator
 *
 * Copyright (c) 2022 Cogent Embedded Inc.
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

#ifndef __ALGO_RENDER_H
#define __ALGO_RENDER_H

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**> Opaque declaration */
typedef struct algo_view    algo_view_t;

/**> Opaque declaration */
typedef struct mesh_gen     mesh_gen_t;

/*******************************************************************************
 * Algo-view types
 ******************************************************************************/

typedef enum algo_view_type
{
    ALGO_VIEW_GRAYSCALE,
    ALGO_VIEW_RGB_PLANAR,
    ALGO_VIEW_GRAYSCALE_RAW,
    ALGO_VIEW_RGB_PLANAR_RAW

}   algo_view_type_t;

/**
 * @brief   Create generic algo-view
 *
 * @param   cfg[in]         Global configuration data
 * @param   id[in]          View identifier
 * @param   type[in]        View type
 * @param   width[out]      Output buffer width
 * @param   height[out]     Output buffer height
 *
 * @return                  Algo-view handle
 */
extern algo_view_t *algo_view_create(cfg_data_t *cfg, char *id, int type, int *width, int *height);

/**
 * @brief   Destroy algo-view
 *
 * @param   cfg[in]     Global configuration data
 * @param   id[in]      View identifier
 * @param   type[in]    Mesh type
 *
 * @return              Algo-view handle, or NULL on failure
 */
extern void algo_view_destroy(algo_view_t *view);

/**
 * @brief   Render screen layout and process all transitions
 *
 * @param   vm[in]          View manager handle
 * @param   texture[in]     Array of camera textures
 * @param   output[in]      Output textures array
 * @param   sync[in]        Synchronization object pointer
 *
 * @return                  Negative on failure
 */
extern int algo_view_render(algo_view_t *view, texture_data_t **texture, texture_data_t **output, sync_data_t **sync);

/**
 * @brief   Update algo-view mesh
 *
 * @param   view[in]        Algo-view handle
 * @param   gen[in]         Mesh-generator data
 * @param   cfg[in]         Global configuration data
 * @param   vehicle[in]     Vehicle data
 *
 * @return                  Negative on failure
 */
extern int algo_view_update_cfg(algo_view_t *view, mesh_gen_t *gen, cfg_data_t *cfg, vehicle_state_t *vehicle);

/**
 * @brief   Invalidate algo-view
 *
 * @param   id[in]          View identifier
 */
extern void algo_view_invalidate(const char *id);

/**
 * @brief   Invalidate all algo-views
 */
extern void algo_view_invalidate_all(void);

/**
 * @brief   Create algo-view mesh - fisheye frame
 *
 * @param   cfg[in]         Global configuration data
 * @param   width[in]       Output buffer width
 * @param   height[in]      Output buffer height
 *
 * @return                  Negative on failure
 */
extern algo_view_t *algo_fisheye_y_create(cfg_data_t *cfg, int width, int height);

/**
 * @brief   Create algo-view mesh - planar RGB cylindrical projection
 *
 * @param   cfg[in]         Global configuration data
 * @param   width[in]       Output buffer width
 * @param   height[in]      Output buffer height
 *
 * @return                  Negative on failure
 */
extern algo_view_t *algo_cylindrical_rgb_create(cfg_data_t *cfg, int width, int height);

/**
 * @brief   Create algo-view mesh - Rear-Top-View, Y-coordinate
 *
 * @param   cfg[in]         Global configuration data
 * @param   width[in]       Output buffer width
 * @param   height[in]      Output buffer height
 *
 * @return                  Negative on failure
 */
extern algo_view_t *algo_rear_tv_y_create(cfg_data_t *cfg, int width, int height);

/**
 * @brief   Create algo-view mesh - grayscale top-view
 *
 * @param   cfg[in]         Global configuration data
 * @param   width[in]       Output buffer width
 * @param   height[in]      Output buffer height
 *
 * @return                  Negative on failure
 */
extern algo_view_t *algo_tv_y_create(cfg_data_t *cfg, int width, int height);
extern int algo_view_get_matrix(cfg_data_t *cfg, char *id, float32_t matrix[3*3]);
extern int  algo_view_set_src_roi(cfg_data_t *cfg, char *id, int32_t roi[4]);

#endif  /* __ALGO_RENDER_H */

