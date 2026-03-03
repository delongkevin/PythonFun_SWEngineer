/*******************************************************************************
 * view-manager.h
 *
 * View manager (compositor) module
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

#ifndef __VIEW_MANAGER_H
#define __VIEW_MANAGER_H

#include "config.h"

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
typedef struct mesh_gen         mesh_gen_t;

/*******************************************************************************
 * Global constants definitions
 ******************************************************************************/

/**> View type code */
typedef enum view_type
{
    VIEW_FRONT_TOP,
    VIEW_FRONT,
    VIEW_FRONT_WIDE,
    VIEW_REAR_TOP,
    VIEW_REAR,
    VIEW_REAR_WIDE,
    VIEW_REAR_CENTRIC,
    VIEW_SIDE,
    VIEW_SONAR,
    VIEW_FRONT_ST,
    VIEW_REAR_ST,
    VIEW_AIMING,
    VIEW_AIMING_ERROR,
    VIEW_DEBUG,
    VIEW_NUMBER

}   view_type_t;

/**> Screen layout code */
typedef enum screen_layout_id
{
    LAYOUT_NONE = 0,
    LAYOUT_FRONT_ST_TOP = 1,
    LAYOUT_FRONT_TOP = 2,
    LAYOUT_FRONT_WIDE_TOP = 3,
    LAYOUT_SIDE = 4,
    LAYOUT_REAR_ST_TOP = 5,
    LAYOUT_REAR_TOP = 6,
    LAYOUT_REAR_WIDE_TOP = 7,
    LAYOUT_REAR_SONAR = 8,
    LAYOUT_SONAR = 9,
    LAYOUT_REAR_CENTER = 10,
    LAYOUT_LEFT = 11,
    LAYOUT_AIMING = 12,
    LAYOUT_AIMING_ERROR = 13,
    LAYOUT_FRONT_RAW = 14,
    LAYOUT_LEFT_RAW = 15,
    LAYOUT_REAR_RAW = 16,
    LAYOUT_RIGHT_RAW = 17,
    LAYOUT_DEBUG = 18,
    LAYOUT_MAX_ID = 19,

}   screen_layout_id_t;

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
 * @brief   Get mesh-generator data pointer
 *
 * @param   vm[in]          View manager handle
 *
 * @return                  Mesh generator handle
 */
extern mesh_gen_t * vm_get_mesh_gen(view_manager_t *vm);

/**
 * @brief   Update view parameters
 *
 * @param   vm[in]          View manager handle
 * @param   view[in]        View to update
 */
extern void view_manager_update_view(view_manager_t *vm, view_type_t view);

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
 * @brief   Update TRSC state
 *
 * @param   vm[in]          View manager handle
 */
extern void view_manager_update_trsc(view_manager_t *vm);

extern void view_manager_update_tha(view_manager_t *vm);


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
 * @brief   Register tweak-tool listener
 */
extern void vm_tweak_register(view_manager_t *vm, cfg_data_t *cfg);

/**
 * @brief   Gesture processing (touchscreen)
 */
extern int view_manager_gesture_event(view_manager_t *vm, void *data, int async);

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
extern int vm_ui_language_reload(view_manager_t *vm, const char* path_to_ktx);
extern int view_manager_world_2_cam(view_manager_t *vm, uint32_t cam_id, const float32_t xyz[3], float32_t camera_coords[2]);

extern int view_manager_mouse_tha(view_manager_t *vm, int32_t x, int32_t y);
extern int view_manager_mouse_get_coord(view_manager_t *vm, int32_t x, int32_t y, float32_t result_xy[2]);
extern void view_manager_raw_2_world_rear(view_manager_t *vm, float32_t raw_x, float32_t raw_y, int32_t refWorld_z, float32_t result_xy[2]);
extern void view_manager_get_ctlval_info(view_manager_t *vm, uint32_t* ctlval_mask, uint32_t ctlval_coords[2]);
#endif  /* __VIEW_MANAGER_H */
