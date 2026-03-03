/*******************************************************************************
 * debug.h
 *
 * Debugging framework for PC-model
 *
 * Copyright (c) 2019 Cogent Embedded Inc.
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

#ifndef __DEBUG_H
#define __DEBUG_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "display.h"
#include "math-helpers.h"
#include "sv_api.h"

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**> Forward declaration */
typedef struct dbg_window   dbg_window_t;

/**
 * @brief   Debug window callback structure
 */
typedef struct dbg_info
{
    /* ...initial window width */
    int                 width;

    /* ...initial window height */
    int                 height;

    /* ...window title */
    char               *title;

    /* ...initialization callback */
    int               (*init)(dbg_window_t *dbg, int W, int H);

    /* ...redraw callback */
    void              (*redraw)(dbg_window_t *dbg, int W, int H);

    /* ...input event processing */
    int               (*event)(dbg_window_t *dbg, widget_event_t *event);

}   dbg_info_t;

/**
 * @brief   Debug window handle
 */
struct dbg_window
{
    /**> Window handle */
    window_data_t      *window;

    /**> Internal data protection lock */
    pthread_mutex_t     lock;

    /**> Window info data */
    window_info_t       info;

    /**> Debug window callback data */
    const dbg_info_t   *dbg_info;

    /**> Model matrix rotation angles accumulators */
    __vec3              rot;

    /**> Model matrix scale accumulator */
    float32_t           scale;

    /**> Last latched mouse position */
    int                 x, y;
};

/*******************************************************************************
 * Helpers functions
 ******************************************************************************/

/**
 * @brief   Lock internal data of debug window
 *
 * @param   dbg[in]         Debug window handle
 */
static inline void dbg_window_lock(dbg_window_t *dbg)
{
    pthread_mutex_lock(&dbg->lock);
}

/**
 * @brief   Unlock internal data of debug window
 *
 * @param   dbg[in]         Debug window handle
 */
static inline void dbg_window_unlock(dbg_window_t *dbg)
{
    pthread_mutex_unlock(&dbg->lock);
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Initialize debug window structure
 *
 * @param   dbg[in]         Pointer to allocated debug data
 * @param   info[in]        Debug window descriptor
 *
 * @return                  Zero on success
 */
extern int dbg_window_init(dbg_window_t *dbg, const dbg_info_t *dbg_info);

/**
 * @brief   Destroy debug window
 *
 * @param   dbg[in]         Debug window data
 */
extern void dbg_window_destroy(dbg_window_t *dbg);

/**
 * @brief   Trigger update of debug window
 *
 * @param   dbg[in]     Debug window handle
 */
extern void dbg_window_update(dbg_window_t *dbg);

/**
 * @brief   Render buffer items encoded as <X, Y, Z, R, G, B, A>
 *
 * @param   buf[in]         Points buffer
 * @param   mode[in]        Rendering mode for glDrawArray (GL_POINTS, GL_LINES, etc)
 * @param   first[in]       Starting index of VBO item
 * @param   count[in]       Number of items in VBO buffer to render
 * @param   pvm[in]         PVM-matrix for points transformation
 */
extern void dbg_buffer_render(void *buf, GLenum mode, GLint first, GLsizei count, __mat4x4 pvm);

/**
 * @brief   Render VBO items encoded as <X, Y, Z, R, G, B, A>
 *
 * @param   vbo[in]         VBO handle
 * @param   mode[in]        Rendering mode for glDrawArray (GL_POINTS, GL_LINES, etc)
 * @param   first[in]       Starting index of VBO item
 * @param   count[in]       Number of items in VBO buffer to render
 * @param   pvm[in]         PVM-matrix for points transformation
 */
extern void dbg_vbo_render(vbo_data_t *vbo, GLenum mode, GLint first, GLsizei count, __mat4x4 pvm);

/**
 * @brief   Draw coordinate system axis of a given length and width
 *
 * @param   length[in]      Length of one axe
 * @param   width[in]       Line width in pixels
 * @param   pvm[in]         PVM matrix
 */
extern void dbg_axis_render(float32_t length, float32_t width, float32_t *pvm);

/**
 * @brief   Draw square grid on the floor of a given size and width
 *
 * @param   stepx[in]       Grid step in X direction, mm
 * @param   stepy[in]       Grid step in Y direction, mm
 * @param   nx[in]          Number of cells in X direction
 * @param   ny[in]          Number of cells in Y direction
 * @param   width[in]       Line width in pixels
 * @param   pvm[in]         PVM matrix
 */
extern void dbg_grid_render(float32_t stepx, float32_t stepy, int32_t nx, int32_t ny, float32_t width, float32_t *pvm);

/**
 * @brief   Draw viewing frustum
 *
 * @param   frustum[in]     Viewing frustum points
 * @param   width[in]       Line width in pixels
 * @param   pvm[in]         PVM matrix
 */
extern void dbg_frustum_render(float32_t (*frustum)[3], float32_t width, float32_t *pvm);

/**
 * @brief   Render bounding box
 *
 * @param   coord[in]       Box coordinates [x0, y0, x1, y1]
 * @param   width[in]       Line width
 * @param   color[in]       Array of colors of each corner
 * @param   pvm[in]         PVM matrix for rendering
 */
extern void dbg_box_render(float32_t coord[4], float32_t width, const float32_t (*color)[4], float32_t *pvm);

/**
 * @brief   Render texture with optional blend-mask
 *
 * @param   tex[in]         Texture handle (RGBA)
 * @param   msk[in]         Blend-mask texture handle (grayscale)
 * @param   inv[in]         Non-zero if bland mask shall be inverted
 * @param   x0[in]          Upper-left corner, X coordinate
 * @param   y0[in]          Upper-left corner, Y coordinate
 * @param   x1[in]          Lower-right corner, X coordinate
 * @param   y1[in]          Lower-right corner, Y coordinate
 * @param   W[in]           Window (viewport) width
 * @param   H[in]           Window (viewport) height
 */
extern void dbg_tex_render(texture_data_t *tex, texture_data_t *msk, float32_t alpha, int x0, int y0, int x1, int y1, int W, int H);

/*******************************************************************************
 * Auxiliary debugging facilities
 ******************************************************************************/

/**
 * @brief   Dynamic array of colored points
 */
typedef struct dbg_vbo
{
    /**> VBO handle */
    vbo_data_t         *vbo;

    /**> Current buffer position */
    GLfloat           (*v)[7];

    /**> Current VBO size */
    u32                 size;

    /**> Number of available points in VBO */
    u32                 avail;

}   dbg_vbo_t;

/**
 * @brief   Initialize dynamic VBO
 *
 * @param   vbo[in]             Dynamic VBO data to initialize
 * @param   size[in]            Initial size of VBO (in elements)
 *
 * @return                      Zero on success
 */
extern int dbg_vbo_init(dbg_vbo_t *vbo, u32 size);

/**
 * @brief   Destroy dynamic VBO
 *
 * @param   vbo[in]             Dynamic VBO data
 */
extern void dbg_vbo_destroy(dbg_vbo_t *vbo);

/**
 * @brief   Prepare dynamic VBO for filling
 *
 * @param   vbo[in]             Dynamic VBO data
 *
 * @return                      Zero on success
 */
extern int dbg_vbo_prepare(dbg_vbo_t *vbo);

/**
 * @brief   Add elements to dynamic VBO
 *
 * @param   vbo[in]             Dynamic VBO data
 * @param   n[in]               Number of points to add
 *
 * @return                      Pointer to first added point
 */
extern float32_t (* dbg_vbo_add(dbg_vbo_t *vbo, u32 n)) [7];

/**
 * @brief   Finish dynamic VBO filling
 *
 * @param   vbo[in]             Dynamic VBO data
 *
 * @return                      Zero on success
 */
extern void dbg_vbo_finish(dbg_vbo_t *vbo);

/**
 * @brief   Query number of filled items in the dynamic VBO
 *
 * @param   vbo[in]             Dynamic VBO data
 *
 * @return                      Number of items
 */
static inline u32 dbg_vbo_count(dbg_vbo_t *vbo)
{
    return vbo->size - vbo->avail;
}

#endif  /* __DEBUG_H */
