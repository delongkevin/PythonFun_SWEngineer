/*******************************************************************************
 * odo.h
 *
 * Object-detection overlay generator and renderer for surround view
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

#ifndef __LIBSV_ODO_H
#define __LIBSV_ODO_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "render-context.h"
#include "vehicle-state.h"
#include "vbo-dynarray.h"

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**> Object-detection generator data */
typedef struct pas_stv_data
{
    /**> VBO dynamic arrays for all objects */
    vbo_dynarray_t  vbo[PAS_AREA_NUMBER][2];

    /**> Timer values for show-/hide-ramps */
    uint32_t        timer[PAS_AREA_NUMBER];

    /**> Current transparency value */
    float32_t       transparency[PAS_AREA_NUMBER];

    /**> Current visualization state */
    uint32_t        state[PAS_AREA_NUMBER];

    /**> Current distance */
    float32_t       distance[PAS_AREA_NUMBER][2];

}   pas_stv_data_t;

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Generate object-detection overlay
 *
 * @param   cfg[in]     Global configuration data pointer
 * @param   vehicle[in] Vehicle state
 * @param   odo[in]     Object-detection overlay data
 *
 * @return              Negative on failure
 */
extern int stv_odo_generate(cfg_data_t *cfg, vehicle_state_t *vehicle, pas_stv_data_t *odo);

/**
 * @brief   Calculate PVM matrices for specified viewing position
 *
 * @param   position[in]    Virtual camera position
 * @param   rotation[in]    Rotation angles
 * @param   fov[in]         Horizontal/vertical field-of-view, in degrees
 * @param   pvm[out]        PVM matrix
 */
extern void odo_set_viewpoint(float32_t *position, float32_t *rotation, float32_t *fov, float32_t *pvm);

/**
 * @brief   Object-detection overlay rendering
 *
 * @param   odo[in]         Object-detection overlay data
 * @param   ctx[in]         Rendering context
 * @param   cfg[in]         Global configuration data
 * @param   pvm[in]         PVM matrix for scene rendering
 * @param   intensity[in]   Global scene intensity
 */
extern void stv_odo_render(pas_stv_data_t *odo, render_context_t *ctx, cfg_data_t *cfg, float32_t *pvm, float32_t intensity);

#endif  /* __LIBSV_ODO_H */
