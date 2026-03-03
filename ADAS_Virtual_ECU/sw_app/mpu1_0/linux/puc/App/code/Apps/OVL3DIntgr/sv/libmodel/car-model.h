/*******************************************************************************
 * car-model.h
 *
 * Car model loader
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

#ifndef __CAR_MODEL_H
#define __CAR_MODEL_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "math-helpers.h"
#include "config.h"
#include "render-context.h"
#include "vehicle-state.h"
#include "../libsv/icons.h"

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**> Opaque car model data */
typedef struct car_model    car_model_t;

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Load car model from file
 *
 * @param   cfg[in]         Model configuration data
 * @param   icon[in]        Graphical resources pointer
 *
 * @return                  Car model data, or NULL on failure
 */
extern car_model_t * car_model_load(cfg_data_t *cfg, icon_data_t *icon);

/**
 * @brief   Set car model and car shadow matrices
 *
 * @param   car[in]         Car model data
 * @param   cfg[in]         Global configuration data pointer
 */
extern void car_model_update_matrix(car_model_t *car, cfg_data_t *cfg);

/**
 * @brief   Calculate PVM matrices for specified viewing position
 *
 * @param   car[in]         Car model data
 * @param   position[in]    Virtual camera position
 * @param   rotation[in]    Rotation angles
 * @param   fov[in]         Horizontal/vertical field-of-view, in degrees
 * @param   pvm[out]        PVM matrix
 */
extern void car_model_set_viewpoint(car_model_t *car, float32_t *position, float32_t *rotation, float32_t *fov, float32_t *pvm);

/**
 * @brief   Render car image
 *
 * @param   car[in]         Car model data
 * @param   cfg[in]         Global configuration data pointer
 * @param   vehicle[in]     Vehicle state data
 * @param   P[in]           Perspective scene projection matrix
 * @param   VM[in]          Scene VM-matrix
 * @param   intensity[in]   Global scene intensity
 */
extern void car_model_render(car_model_t *car, cfg_data_t *cfg, vehicle_state_t *vehicle, float32_t intensity);

#endif  /* __CAR_MODEL_H */
