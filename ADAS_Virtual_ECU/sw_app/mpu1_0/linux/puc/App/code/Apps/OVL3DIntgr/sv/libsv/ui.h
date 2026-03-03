/*******************************************************************************
 * ui.h
 *
 * User-interface for SVS
 *
 * Copyright (c) 2021 Cogent Embedded Inc.
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

#ifndef __LIBSV_UI_H
#define __LIBSV_UI_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "config.h"
#include "icons.h"
#include "view-manager.h"

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**> Opaque declaration of UI data */
typedef struct ui_data    ui_data_t;

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Create UI menu
 *
 * @param   cfg[in]             Global configuration data
 * @param   vehicle[in]         Vehicle state data
 *
 * @return                      Menu data handle, or NULL on failure
 */
extern ui_data_t * ui_create(cfg_data_t *cfg, vehicle_state_t *vehicle);

/**
 * @brief   Set UI page
 *
 * @param   ui[in]              UI data
 * @param   cfg[in]             Global configuration data
 * @param   id[in]              Page identifier
 *
 * @return                      Negative on failure
 */
extern int ui_set_page(ui_data_t *ui, cfg_data_t *cfg, uint32_t id);

/**
 * @brief   Render-list update function
 *
 * @param   menu[in]            Menu data
 * @param   render[in]          Icons renderlist
 *
 * @return                      Negative on failure
 */
extern int ui_update(ui_data_t *ui, icon_render_t *render, icon_render_t *render_back);

/**
 * @brief   Process button state change
 *
 * @param   ui[in]          UI data
 * @param   x[in]           Touch X-coordinate, pixels
 * @param   y[in]           Touch Y-coordinate, pixels
 * @param   id[out]         Pressed button id
 * @param   state[out]      New button state
 *
 * @return                  Non-zero if button was pressed
 */
extern int ui_touch_process(ui_data_t *ui, cfg_data_t *cfg, int32_t x, int32_t y, int32_t *action);

/**
 * @brief   Process button state change
 *
 * @param   ui[in]          UI data
 * @param   cfg[in]         Global configuration data
 * @param   x[in]           Touch X-coordinate, pixels
 * @param   y[in]           Touch Y-coordinate, pixels
 * @param   id[out]         Pressed button id
 * @param   state[out]      New button state
 *
 * @return                  Non-zero if button was pressed
 */
extern int ui_gesture_process(ui_data_t *ui, cfg_data_t *cfg, void *data, int async, int32_t *action);

/**
 * @brief   Process button state change
 *
 * @param   ui[in]          UI data
 * @param   x0[in]          Current touch reference position, X-coordinate
 * @param   y0[in]          Current touch reference position, Y-coordinate
 * @param   off_x[in]       Current offset from reference position, X-coordinate
 * @param   off_y[in]       Current offset from reference position, Y-coordinate
 * @param   stop[in]        Stop event reception
 * @param   action[out]     Pointer to nes page-id
 *
 * @return                  Non-zero if button was pressed
 */
extern int ui_input_process(ui_data_t *ui, cfg_data_t *cfg, int32_t x0, int32_t y0, int32_t off_x, int32_t off_y, uint32_t stop, int32_t *action);

extern void ui_language_reload(ui_data_t* ui, const char* path_to_ktx);

#endif  /* __LIBSV_UI_H */
