/*******************************************************************************
 * mesh-render.h
 *
 * Mesh renderer for surround view
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

#ifndef __MESH_RENDER_H
#define __MESH_RENDER_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "vbo-dynarray.h"
#include "config.h"
#include "render-context.h"

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**
 * @brief   Vertex attribute encoding:
 *          [0] - X-coordinate, pixel
 *          [1] - Y-coordinate, pixel
 *          [2] - U-coordinate, pixel
 *          [3] - V-coordinate, pixel
 *          [4] - blending weight (distance to blend zone boundary, mm)
 *          [5] - color-correction ratio
 */
typedef GLfloat mesh_vertex_t[6];

/**
 * @brief   Dynamic VBO array for individual camera mesh vertices
 */
typedef struct mesh_vbo
{
    /**> Generic dynamic VBO array */
    vbo_dynarray_t      vbo;

    /**> Destination tile pointer */
    int32_t            *dst;

    /**> Camera id */
    uint32_t            id;

}   mesh_vbo_t;

/**
 * @brief   Mesh item for rendering
 */
typedef struct mesh_item
{
    /**> Camera identifier */
    uint32_t            id;

    /**> VBO buffer containing mesh vertices */
    vbo_data_t         *vbo;

    /**> Destination tile for rendering */
    int32_t             dst[4];

}   mesh_item_t;

/**
 * @brief   Generic mesh object
 */
typedef struct mesh_data
{
    /**> Array of mesh items */
    mesh_item_t         item[SV_CAMERAS_NUMBER];

    /**> Mesh type (informative) */
    int32_t             type;

    /**> Number of mesh items in each bank */
    uint32_t            number;

    /**> Debug window for visualization */
    void               *dbg;

    /**> Generated top view mask texture */
    fbo_data_t*              mask_fbo;
    texture_data_t*          mask_tex;
}   mesh_data_t;

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Initialize dynamic VBO array
 *
 * @param   vbo[in]     VBO dynamic array handle
 * @param   size[in]    Initial number of preallocated entries
 *
 * @return              Negative on failure
 */
static inline int mesh_vbo_init(mesh_vbo_t *vbo, uint32_t size)
{
    return vbo_dynarray_init(&vbo->vbo, sizeof(mesh_vertex_t), size);
}

/**
 * @brief   Reserve place for specified number of vertices inside dynamic VBO array
 *
 * @param   vbo[in]         VBO dynamis array
 * @param   n[in]           Number of entries to preallocate
 *
 * @return                  Pointer to first allocated entry
 */
static inline mesh_vertex_t * mesh_vbo_add(mesh_vbo_t *vbo, uint32_t n)
{
    return vbo_dynarray_add(&vbo->vbo, sizeof(mesh_vertex_t), n);
}


/**
 * @brief   Clear dynamic array
 *
 * @param   vbo[in]         Dynamic VBO array handle
 */
static inline void mesh_vbo_clear(mesh_vbo_t *vbo)
{
    vbo_dynarray_clear(&vbo->vbo, sizeof(mesh_vertex_t));
}

/**
 * @brief   Get total number of entries inside VBO
 *
 * @param   vbo[in]         Dynamic VBO array handle
 *
 * @return                  Total number of entries
 */
static inline int mesh_vbo_num(mesh_vbo_t *vbo)
{
    return vbo_dynarray_num(&vbo->vbo);
}

/**
 * @brief   Get VBO array buffer pointer
 *
 * @param   vbo[in]         Dynamic VBO array handle
 *
 * @return                  Total number of entries
 */
static inline mesh_vertex_t * mesh_vbo_buffer(mesh_vbo_t *vbo)
{
    return vbo_dynarray_buffer(&vbo->vbo, sizeof(mesh_vertex_t));
}

/**
 * @brief   Destroy mesh VBO object
 *
 * @param   vbo[in]     Dynamic VBO array handle
 */
static inline void mesh_vbo_destroy(mesh_vbo_t *vbo)
{
    vbo_dynarray_destroy(&vbo->vbo, sizeof(mesh_vertex_t));
}

/**
 * @brief   Create generic mesh descriptor
 *
 * @param   id[in]          Mesh textual id (informative purpose only)
 * @param   type[in]        Mesh type
 *
 * @return                  Mesh descriptor, or NULL on failure
 */
extern mesh_data_t * mesh_create(const char *id, int type);

/**
 * @brief   Upload mesh vertices into pending VBO bank, and make it current
 *
 * @param   mesh[in]        Mesh descriptor
 * @param   vbo[in]         Array of mesh VBO objects
 * @param   number[in]      Number of mesh VBO objects
 *
 * @return                  Negative on failure
 */
extern int mesh_update(mesh_data_t *mesh, mesh_vbo_t *vbo, uint32_t number);

/**
 * @brief   Render generic mesh
 *
 * @param   mesh[in]            Generic mesh descriptor
 * @param   texture[in]         Array of camera textures
 * @param   ctx[in]             Rendering context
 * @param   intensity[in]       Global scene intensity level
 * @param   CC[in]              Color-correction coefficients
 */
extern void mesh_render(mesh_data_t *mesh, texture_data_t **texture, render_context_t *ctx, float32_t intensity, float32_t (*CC)[3][3]);
extern void mesh_render_tv(mesh_data_t *mesh, texture_data_t **texture, render_context_t *ctx, float32_t intensity, float32_t (*CC)[3][3]);

/**
 * @brief   Render  mesh into frame-buffer
 *
 * @param   mesh[in]            Generic mesh descriptor
 * @param   tex[in]             Array of camera textures
 * @param   ctx[in]             Rendering context
 * @param   intensity[in]       Global scene intensity level
 * @param   CC[in]              Color-correction coefficients pointer
 */
extern void mesh_render_fb(mesh_data_t *mesh, texture_data_t *tex, int k, float32_t (*CC)[3][3]);

/**
 * @brief   Render raw texture
 *
 * @param   texture[in]         Camera texture
 * @param   cfg[in]             Raw mesh configuration
 * @param   ctx[in]             Rendering context
 * @param   intensity[in]       Global scene intensity level
 */
extern void mesh_render_raw(texture_data_t *texture, cfg_raw_mesh_t *cfg, render_context_t *ctx, float32_t intensity);

/**
 * @brief   Render raw-mcv view
 *
 * @param   texture[in]         Camera texture
 * @param   cfg[in]             Raw-MCV mesh configuration
 * @param   ctx[in]             Rendering context
 * @param   intensity[in]       Global scene intensity level
 */
extern void mesh_render_raw_mcv(texture_data_t **texture, cfg_raw_mcv_mesh_t *cfg, render_context_t *ctx, float32_t intensity);

/**
 * @brief   Destroy mesh descriptor
 *
 * @param   mesh[in]        Mesh descriptor
 */
extern void mesh_destroy(mesh_data_t *mesh);

#endif  /* __MESH_RENDER_H */
