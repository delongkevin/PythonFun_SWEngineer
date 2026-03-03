/*******************************************************************************
 * icons.h
 *
 * Icons loader and renderer for surround view
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

#ifndef __LIBSV_ICONS_H
#define __LIBSV_ICONS_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "render-context.h"
#include "vehicle-state.h"
#include "vbo-dynarray.h"

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**> Opaque declaration of icon */
typedef struct icon_data    icon_data_t;

/**> Icon render list */
typedef struct icon_render
{
    /**> Dynamic array data */
    vbo_dynarray_t          vbo;

    /**> Anything else? Destination tile? - tbd */
    int32_t                *dst;

}   icon_render_t;

/**
 * @brief   Icon item data
 */
typedef struct icon_item
{
    /**> GL texture id (reference) */
    GLuint                  tex;

    /**> Texture source coordinates in GL-space (0,0 - bottom-right, 1,1 - top-left) */
    float32_t*              src;
    float32_t*              scale_x;
    float32_t*              scale_y;

}   icon_item_t;

/*******************************************************************************
 * Low-level API
 ******************************************************************************/

/**
 * @brief   Add icon item to rendering list
 *
 * @param   item[in]        Icon item data
 * @param   dst[in]         Destination tile on display
 * @param   angle[in]       Rotation angle, radians
 * @param   render[in]      Icon render-list
 *
 * @return                  Negative on failure
 */
extern int icon_add_item_rot(icon_item_t *item, int32_t *dst, float32_t angle, float32_t *pivot, int tr, icon_render_t *render);

/**
 * @brief   Add icon item to rendering list with no extra transformation
 *
 * @param   item[in]        Icon item data
 * @param   dst[in]         Destination tile on display
 * @param   angle[in]       Rotation angle, radians
 * @param   render[in]      Icon render-list
 *
 * @return                  Negative on failure
 */
static inline int icon_add_item(icon_item_t *item, int32_t *dst, icon_render_t *render)
{
    return icon_add_item_rot(item, dst, 0.0f, NULL, 0, render);
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Prepare icon data for update
 */
extern void icon_reset(icon_render_t *render);

/**
 * @brief   Add car model icon and PAS for sonar view
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   vehicle[in]     Vehicle state data pointer
 * @param   tv[in]          Top-view model flag
 * @param   render[in]      Icon render-list data
 *
 * @return                  Negative on failure
 */
extern int icon_add_sonar(icon_data_t *icon, cfg_data_t *cfg, vehicle_state_t *vehicle, int tv, int type, icon_render_t *render);


/**
 * @brief   Add sonars for auto-parking
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   vehicle[in]     Vehicle state data pointer
 * @param   tv[in]          Top-view model flag
 * @param   render[in]      Icon render-list data
 *
 * @return                  Negative on failure
 */
extern int icon_add_pdc(icon_data_t *icon, cfg_data_t *cfg, vehicle_state_t *vehicle, int tv, int type, icon_render_t *render);

/**
 * @brief   Add car model icon including the wheels
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   front[in]       Front/rear-CTA processing
 * @param   vehicle[in]     Vehicle data pointer
 * @param   render[in]      Icon render list
 *
 * @return                  Negative on failure
 */
extern int icon_add_cta(icon_data_t *icon, cfg_data_t *cfg, int front, vehicle_state_t *vehicle, icon_render_t *render);

/**
 * @brief   Add hitch distance overlay
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   vehicle[in]     Vehicle data pointer
 * @param   render[in]      Icon render list
 *
 * @return                  Negative on failure
 */
extern int icon_add_hitch(icon_data_t *icon, cfg_data_t *cfg, vehicle_state_t *vehicle, icon_render_t *render);

/**
 * @brief   Add coupler target overlay
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   vehicle[in]     Vehicle data pointer
 * @param   render[in]      Icon render list
 *
 * @return                  Negative on failure
 */
extern int icon_add_coupler(icon_data_t *icon, cfg_data_t *cfg, vehicle_state_t *vehicle, icon_render_t *render);

/**
 * @brief   Add TRSC overlay
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   type[in]        TRSC graphics type
 * @param   vehicle[in]     Vehicle data pointer
 * @param   render[in]      Icon render list
 *
 * @return                  Negative on failure
 */
extern int icon_add_trsc(icon_data_t *icon, cfg_data_t *cfg, int type, vehicle_state_t *vehicle, icon_render_t *render);

/**
 * @brief   Add aiming error icon as needed
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   type[in]        4-camera system flag
 * @param   side[in]        Side-view flag
 * @param   vehicle[in]     Vehicle data pointer
 * @param   render[in]      Icon render list
 *
 * @return                  Negative on failure
 */
extern int icon_add_aiming(icon_data_t *icon, cfg_data_t *cfg, int type, int side, vehicle_state_t *vehicle, icon_render_t *render);

/**
 * @brief   Add border icons as needed
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   screen_dst[in]  Screen destination tile
 * @param   side[in]        Side-view flag
 * @param   render[in]      Icon render list
 *
 * @return                  Negative on failure
 */
extern int icon_add_border(icon_data_t *icon, cfg_data_t *cfg, int32_t *screen_dst, icon_render_t *render);

/**
 * @brief   Render icons list
 *
 * @param   render[in]      Icons render-list
 * @param   ctx[in]         Rendering context
 * @param   dst[in]         Destination tile (crop-region)
 * @param   intensity[in]   Global scene intensity
 */
extern void icon_render(icon_render_t *render, render_context_t *ctx, float32_t intensity);

/**
 * @brief   Load icons resources
 *
 * @param   cfg[in]     Global configuration data
 *
 * @return              Icon data handle, or NULL on failure
 */
extern icon_data_t * icons_load(cfg_data_t *cfg);

/**
 * @brief   Get graphical resource source
 *
 * @param   icon[in]        Icons data
 * @param   id[in]          Resource id
 * @param   item[out]       Icon item pointer
 *
 * @return                  Negative on failure
 */
extern int icon_get_resource(icon_data_t *icon, uint32_t id, icon_item_t **item);

#endif  /* __LIBSV_ICONS_H */
