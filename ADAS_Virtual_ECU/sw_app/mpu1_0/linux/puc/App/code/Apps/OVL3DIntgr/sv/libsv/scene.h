/*******************************************************************************
 * scene.c
 *
 * Scene transformations for user input
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

#ifndef __LIBSV_SCENE_H
#define __LIBSV_SCENE_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "config.h"

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Process mouse event
 *
 * @param   stv[in]         STV-configuration
 * @param   cfg[in]         Scene parameters update configuration
 * @param   x[in]           Current mouse position, X-coordinate
 * @param   y[in]           Current mouse position, Y-coordinate
 * @param   button[in]      Button code
 * @param   button[in]      Buttons state
 *
 * @return                  Non-zero is view update is required
 */
extern int scene_stv_mouse_event(cfg_stv_mesh_t *stv, cfg_scene_params_t *cfg, int32_t x, int32_t y, uint32_t button, uint32_t state);

/**
 * @brief   Process gesture event
 *
 * @param   stv[in]         STV-configuration
 * @param   cfg[in]         Scene parameters update configuration
 * @param   data[in]        Gesture-specific information
 * @param   async[in]       Asynchronous gestrure recognition flag
 *
 * @return                  Non-zero is view update is required
 */
extern int scene_stv_touch_event(cfg_stv_mesh_t *stv, cfg_scene_params_t *cfg, void *data, int async);

/**
 * @brief   Process CAN-input event
 *
 * @param   stv[in]         STV-configuration
 * @param   x0[in]          Current touch reference position, X-coordinate
 * @param   y0[in]          Current touch reference position, Y-coordinate
 * @param   off_x[in]       Current offset from reference position, X-coordinate
 * @param   y0[in]          Current offset from reference position, Y-coordinate
 * @param   stop[in]        Stop event reception
 *
 * @return                  Non-zero is view update is required
 */
extern int scene_stv_input_event(cfg_stv_mesh_t *stv, cfg_scene_params_t *cfg, int32_t x0, int32_t y0, int32_t off_x, int32_t off_y, uint32_t stop);

#endif  /* __LIBSV_SCENE_H */
