/*******************************************************************************
 * cc.h
 *
 * Color-correction calculator for surround view
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

#ifndef __LIBSV_CC_H
#define __LIBSV_CC_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "config.h"
#include "camera.h"

/*******************************************************************************
 * Types declarations
 ******************************************************************************/

/**> Opaque type declaration */
typedef struct cc_data      cc_data_t;

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Create color correction module
 *
 * @param   cfg[in]         Global configuration data
 * @param   camera[in]      Camera data array (tbd - not too good)
 *
 * @return                  Color-correction module handle, or NULL
 */
extern cc_data_t  * cc_data_create(cfg_data_t *cfg, camera_data_t *camera);

/**
 * @brief   Calculate color statistics of the regions
 *
 * @param   cc[in]              Color-correction data
 * @param   texture[in]         Array of raw input buffers
 */
extern void cc_update(cc_data_t *cc, texture_data_t **tex);

/**
 * @brief   Generate UV-coordinates of the points participating in statistics
 *          collection for correcting coefficients calculation
 *
 * @param   cc[in]          Color-correction data
 * @param   cfg[in]         Global configuration data pointer
 * @param   camera[in]      Camera data array (tbd - not too good)
 */
extern void cc_generate_points(cc_data_t *cc, cfg_data_t *cfg, camera_data_t *camera);

/**
 * @brief   Enable/disable masking of camera image with color
 *
 * @param   cc[in]      Color-correction data
 * @param   id[in]      Camera id
 * @param   color[in]   Color to use for masking the camera
 * @param   enable[in]  Mask enable flag
 */
extern void cc_mask_camera(cc_data_t *cc, uint32_t id, float32_t color[3], int enable);

/**
 * @brief   Return color-correction coefficients array
 *
 * @param   cc[in]      Color-correction data
 *
 * @return              Pointer to RGB-correction coefficients
 */
extern float32_t (*cc_get_coefs(cc_data_t *c))[3][3];

#endif  /* __LIBSV_CC_H */
