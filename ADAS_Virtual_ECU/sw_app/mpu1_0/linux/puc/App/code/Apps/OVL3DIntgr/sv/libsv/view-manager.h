/*******************************************************************************
 * view-manager.h
 *
 * View manager (compositor) module
 *
 * Copyright (c) 2020-2022 Cogent Embedded Inc.
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

#ifndef __VIEW_MANAGER_H
#define __VIEW_MANAGER_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "vehicle-state.h"

/*******************************************************************************
 * Opaque declarations
 ******************************************************************************/

typedef struct view_manager     view_manager_t;
typedef struct texture_data     texture_data_t;
typedef struct render_context   render_context_t;

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Create view manager
 *
 * @param   cfg[in]         Configuration data pointer
 *
 * @return                  View manager handle, or NULL on failure
 */
extern view_manager_t * view_manager_create(cfg_data_t *cfg);

/**
 * @brief   Render screen layout and process all transitions
 *
 * @param   vm[in]          View manager handle
 * @param   texture[in]     Array of camera textures
 * @param   ctx[in]         Rendering context
 *
 * @return                  Negative on failure
 */
extern int view_manager_render(view_manager_t *vm, texture_data_t **texture, render_context_t *ctx);

/**
 * @brief   Create view manager
 *
 * @param   cfg[in]         Configuration data pointer
 *
 * @return                  View manager handle, or NULL on failure
 */
extern void view_manager_destroy(view_manager_t *vm);

/**
 * @brief   Lock access to view manager internal data
 *
 * @param   vm[in]          View manager handle
 */
extern void view_manager_lock(view_manager_t *vm);

/**
 * @brief   Unlock access to view manager internal data
 *
 * @param   vm[in]          View manager handle
 */
extern void view_manager_unlock(view_manager_t *vm);

/**
 * @brief   Get vehicle state data pointer
 *
 * @param   vm[in]          View manager handle
 *
 * @return                  Vehicle state data pointer
 */
extern vehicle_state_t * vm_get_vehicle_state(view_manager_t *vm);

/**
 * @brief   Update all enabled overlays
 *
 * @param   vm[in]          View manager handle
 */
extern void view_manager_update_overlays(view_manager_t *vm);

/**
 * @brief   Update color-correction module parameters
 *
 * @param   vm[in]          View manager handle
 */
extern void view_manager_update_cc(view_manager_t *vm);

/**
 * @brief   Update guide-lines overlays
 *
 * @param   vm[in]          View manager handle
 */
extern void view_manager_update_guide(view_manager_t *vm);

/**
 * @brief   Update car model overlay
 *
 * @param   vm[in]          View manager handle
 */
extern void view_manager_update_car_model(view_manager_t *vm);

/**
 * @brief   Update PAS state
 *
 * @param   vm[in]          View manager handle
 */
extern void view_manager_update_pas(view_manager_t *vm);


/**
 * @brief   Update AP state
 *
 * @param   vm[in]          View manager handle
 */
extern void view_manager_update_ap(view_manager_t *vm);
/**
 * @brief   Update CTA state
 *
 * @param   vm[in]          View manager handle
 */
extern void view_manager_update_cta(view_manager_t *vm);

/**
 * @brief   Update aiming error overlay state
 *
 * @param   vm[in]          View manager handle
 */
extern void view_manager_update_aiming_error(view_manager_t *vm);

/**
 * @brief   Update ODO state
 *
 * @param   vm[in]          View manager handle
 */
extern void view_manager_update_odo(view_manager_t *vm);

/**
 * @brief   Update THA state
 *
 * @param   vm[in]          View manager handle
 */
extern void view_manager_update_tha(view_manager_t *vm);

/**
 * @brief   Update TRSC state
 *
 * @param   vm[in]          View manager handle
 */
extern void view_manager_update_trsc(view_manager_t *vm);

/**
 * @brief   Update UI state
 *
 * @param   vm[in]          View manager handle
 */
extern void view_manager_update_ui(view_manager_t *vm);

/**
 * @brief   Set screen layout
 *
 * @param   vm[in]          View manager handle
 * @param   layout[in]      Screen layout code
 *
 * @return                  Negative on failure
 */
extern int view_manager_set_layout(view_manager_t *vm, int32_t layout);

/**
 * @brief   Update camera parameters
 *
 * @param   vm[in]              View-manager data
 */
extern void view_manager_update_cameras(view_manager_t *vm);

/**
 * @brief   Adjust configuration with respect to steering position
 *
 * @param   vm[in]              View-manager data
 * @param   steering_lhd[in]    Steering position
 */
extern void view_manager_set_steering_position(view_manager_t *vm, uint32_t steering_lhd);

/**
 * @brief   UI event processing
 *
 * @param   vm[in]              View-manager data
 * @param   id[in]              Button identifier
 * @param   state[in]           Button state
 */
extern void view_manager_ui_event(view_manager_t *vm, uint32_t id, uint32_t state);

extern int view_manager_mouse_tha(view_manager_t *vm, int32_t x, int32_t y);

extern int view_manager_mouse_event(view_manager_t *vm, int32_t x, int32_t y, uint32_t button, uint32_t state);

/**
 * @param   Process CAN-input event
 *
 * @param   vm[in]          View-manager data
 * @param   x[in]           Current touch reference position, X-coordinate
 * @param   y[in]           Current touch reference position, Y-coordinate
 * @param   off_x[in]       Current offset from reference position, X-coordinate
 * @param   off_y[in]       Current offset from reference position, Y-coordinate
 * @param   stop[in]        Stop event reception
 *
 * @return                  Processing status
 */
extern int view_manager_input_event(view_manager_t *vm, int32_t x, int32_t y, int32_t dx, int32_t dy, uint32_t stop);

/**
 * @brief   Register tweak-tool listener
 */
extern void vm_tweak_register(view_manager_t *vm, cfg_data_t *cfg);
extern int vm_ui_language_reload(view_manager_t *vm, const char* path_to_ktx);
extern int view_manager_world_2_cam(view_manager_t *vm, uint32_t cam_id, const float32_t xyz[3], float32_t camera_coords[2]);

extern int view_manager_mouse_get_coord(view_manager_t *vm, int32_t x, int32_t y, float32_t result_xy[2]);
extern void view_manager_get_ctlval_info(view_manager_t *vm, uint32_t* ctlval_mask, uint32_t ctlval_coords[2]);


#endif  /* __VIEW_MANAGER_H */
