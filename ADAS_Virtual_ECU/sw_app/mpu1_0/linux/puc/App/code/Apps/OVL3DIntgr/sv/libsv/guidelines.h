/*******************************************************************************
 * guidelines.h
 *
 * Guidelines generator and renderer for surround view
 *
 * Copyright (c) 2020 Cogent Embedded Inc.
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

#ifndef __LIBSV_GUIDELINES_H
#define __LIBSV_GUIDELINES_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "render-context.h"
#include "vehicle-state.h"
#include "vbo-dynarray.h"
#include "icons.h"

#define max_hatched_sections (TV_HATCHED_MAX_POINTS - 2U)
#define max_quads_in_sections (16U)

/*******************************************************************************
 * Opaque declarations
 ******************************************************************************/

/**> Guidelines generator */
typedef struct guide_gen
{
    /**> Dynamic vertex array */
    vbo_dynarray_t      vbo;
    vbo_dynarray_t      vbo_bw;
    vbo_dynarray_t      vbo_ffc;
    vbo_dynarray_t      vbo_lines;
    vbo_dynarray_t      vbo_hatched;

    GLuint ffc_tex;
    GLuint    hatched_tex;
    float32_t hatched_dst[4];

    __vec3 curved_points_for_hatched_area[TV_HATCHED_MAX_POINTS*max_quads_in_sections];
    __vec2 display_points_for_hatched_area_l[TV_HATCHED_MAX_POINTS*max_quads_in_sections];
    __vec2 display_points_for_hatched_area_r[TV_HATCHED_MAX_POINTS*max_quads_in_sections];

}   guide_gen_t;

/**
 * @brief   Guideline data
 */
typedef struct guide_data
{
    /**> Guidelines type */
    uint32_t            type;

    /**> VBO buffer containing guideline vertices */
    vbo_data_t         *vbo;
    vbo_data_t         *vbo_bw;
    vbo_data_t         *vbo_ffc;
    vbo_data_t         *vbo_lines;
    vbo_data_t         *vbo_hatched;

    /**> Type-specific data */
    union
    {
        /**> Top-view-specific data */
        struct
        {
            /**> Trajectory lines visibility */
            int     visible[4];

        }   tv;

        /**> Side-view-specific data */
        struct
        {
            /**> Trajectory line visibility */
            int     visible;

        }   sv;

        /**> See-through-view-specific data */
        struct
        {
            /**> Trajectory lines visibility */
            int     visible[2];

        }   stv;
    };

    /**> Destination tile for rendering */
    int32_t             dst[4];

    GLuint ffc_tex;
    GLuint hatched_tex;

}   guide_data_t;

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Guideline generator initialization
 */
extern guide_gen_t * guide_gen_create(icon_data_t* icon_data);

/**
 * @brief   Generate guidelines for front/rear-view
 *
 * @param   cfg[in]         Global configuration data
 * @param   scv[in]         SCV-configuration data
 * @param   front[in]       Front-view guidelines
 * @param   vehicle[in]     Vehicle state data
 * @param   guide[in]       Guideline descriptor
 *
 * @return                  Negative on failure
 */
extern int guide_front_rear_generate(guide_gen_t *gen, cfg_data_t *cfg, cfg_scv_mesh_t *scv, int front, int narrow, vehicle_state_t *vehicle, guide_data_t *guide);

/**
 * @brief   Generate FFC guidelines
 *
 * @param   cfg[in]         Global configuration data
 * @param   scv[in]         SCV-configuration data
 * @param   front[in]       Front-view guidelines
 * @param   vehicle[in]     Vehicle state data
 * @param   guide[in]       Guideline descriptor
 *
 * @return                  Negative on failure
 */
extern int guide_ffc_generate(guide_gen_t *gen, cfg_data_t *cfg, cfg_scv_mesh_t *scv, int front, int narrow, vehicle_state_t *vehicle,  guide_data_t *guide);

/**
 * @brief   Generate dynamic guidelines overlay for top-view
 *
 * @param   cfg[in]         Global configuration data
 * @param   tv[in]          TV-mesh configuration
 * @param   forward[in]     Forward movement
 * @param   vehicle[in]     Vehicle state data
 *
 * @return                  Negative on failure
 */
extern int guide_gen_top_view(guide_gen_t *gen, cfg_data_t *cfg, cfg_tv_mesh_t *tv, int forward, vehicle_state_t *vehicle, guide_data_t *guide);

/**
 * @brief   Generate guidelines for side-view
 *
 * @param   cfg[in]         Global configuration data
 * @param   scv[in]         SCV-configuration data
 * @param   front[in]       Front-view guidelines
 * @param   vehicle[in]     Vehicle state data
 * @param   guide[in]       Guideline descriptor
 *
 * @return                  Negative on failure
 */
extern int guide_side_generate(guide_gen_t *gen, cfg_data_t *cfg, cfg_scv_mesh_t *scv, int left, vehicle_state_t *vehicle, guide_data_t *guide);

/**
 * @brief   Generate guidelines for see-through view
 *
 * @param   cfg[in]         Global configuration data
 * @param   stv[in]         STV-configuration data
 * @param   front[in]       Front-view guidelines
 * @param   vehicle[in]     Vehicle state data
 * @param   guide[in]       Guideline descriptor
 *
 * @return                  Negative on failure
 */
extern int guide_stv_generate(guide_gen_t *gen, cfg_data_t *cfg, cfg_stv_mesh_t *stv, int front, vehicle_state_t *vehicle, guide_data_t *guide);

/**
 * @brief   Generate guidelines for THA view
 *
 * @param   cfg[in]         Global configuration data
 * @param   scv[in]         SCV-configuration data
 * @param   vehicle[in]     Vehicle state data
 * @param   guide[in]       Guideline descriptor
 *
 * @return                  Negative on failure
 */
extern int guide_tha_generate(guide_gen_t *gen, cfg_data_t *cfg, cfg_scv_mesh_t *scv, vehicle_state_t *vehicle, guide_data_t *guide);

/**
 * @brief   Render guidelines overlay
 *
 * @param   guide[in]       Guidelines data
 * @param   ctx[in]         Rendering context
 * @param   intensity[in]   Global scene intensity
 */
extern void guide_render(guide_data_t *guide, render_context_t *ctx, float32_t intensity);

extern int32_t tha_calc_triangle(cfg_data_t *cfg, cfg_scv_mesh_t *scv, vehicle_state_t *vehicle, guide_data_t *guide, float32_t (*coords)[2]);
extern uint32_t tha_check_arc(float32_t (*coords)[2], float32_t point[2]);
extern int32_t tha_check(cfg_data_t *cfg, vehicle_state_t *vehicle, float32_t world_coords[3] );


extern int guide_hatched_generate(guide_gen_t *gen, cfg_data_t *cfg, cfg_tv_mesh_t *tv, guide_data_t *guide);

#endif  /* __LIBSV_GUIDELINES_H */
