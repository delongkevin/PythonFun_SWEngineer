/*******************************************************************************
 * aiming.h
 *
 * Aiming-view overlay renderer
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

#ifndef __LIBSV_AIMING_H
#define __LIBSV_AIMING_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "icons.h"

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/* ...tbd */

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Render icons list
 *
 * @param   icon[in]        Icon data
 * @param   vehicle[in]     Vehicle state
 * @param   cfg[in]         Global configuration date
 * @param   ctx[in]         Rendering context
 * @param   intensity[in]   Global scene intensity
 */
extern void aiming_render(icon_data_t *icon, vehicle_state_t *vehicle, cfg_data_t *cfg, render_context_t *ctx, float32_t intensity);

#endif  /* __LIBSV_AIMING_H */
