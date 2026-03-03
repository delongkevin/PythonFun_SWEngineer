/*******************************************************************************
 * camera.h
 *
 * Camera model implementation
 *
 * Copyright (c) 2015-2020 Cogent Embedded Inc.
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

#ifndef __LIBSV_CAMERA_H
#define __LIBSV_CAMERA_H

#include "config.h"

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**
 * @brief   Physical camera data
 */
typedef struct camera_data
{
    /**> Current translation vector */
    float32_t           T[3];

    /**> Camera rotation matrix (column-major order) */
    float32_t           R[3 * 3];

    /**> Fisheye distortion coefficients / camera-matrix */
    float32_t           params[8];

    /**> Gamma coefficient for distortion */
    float32_t           gamma;

}   camera_data_t;

/**
 * @brief   Virtual camera data
 */
typedef struct vcamera_data
{
    /**> Rotation matrix (column-major order) */
    float32_t           R[3 * 3];

    /**> Translation vector */
    float32_t           T[3];

    /**> Fisheye/rectilinear distortion coefficient */
    float32_t           gamma;
    float32_t           delta;

    /**> Compression coefficient coefficient */
    float32_t           alpha;
    float32_t           beta;

    /**> Camera matrix (scales and bias) */
    float32_t           params[4];

}   vcamera_data_t;

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Adjust camera parameters
 *
 * @param   camera[in]      Camera data
 * @param   T[in]           Camera translation vector in world coordinate system
 * @param   R[in]           Camera rotation vector
 */
extern void camera_set_extrinsics(camera_data_t *camera, const float32_t *T, const float32_t *R);

/**
 * @brief   Adjust camera intrinsic parameters
 *
 * @param   camera[in]      Camera data
 * @param   resolution[in]  Camera resolution: {W,H}
 * @param   dist[in]        Fisheye lens distortion polynomial coefficients
 * @param   intr[in]        Camera matrix
 */
extern void camera_set_intrinsics(camera_data_t *camera, const float32_t *resolution, const float32_t *dist, const float32_t *intr);

/**
 * @brief   Convert Magna extrinsics to ISO
 *
 * @param   cfg[in]     Global configuration data
 * @param   k[in]       Camera index
 * @param   angle[in]   Rotation angles (Magna), radians
 * @param   pos[in]     Translation vector (Magna), mm
 */
extern void camera_set_magna_extrinsics(cfg_data_t *cfg, int k, float32_t *angle, float32_t *pos);

/**
 * @brief   Transform point from world to camera coordinate system with respect to
 *          physical camera rotation / translation parameters
 *
 * @param   p[in]           Array of 3D-points in world coordinates
 * @param   tr[in]          Physical camera translation vector
 * @param   rot[in]         Physical camera rotation matrix in row-major form
 * @param   n[in]           Number of points
 * @param   v[out]          Output 3D-points in camera coordinate system
 */
extern void map_world_to_cam(float32_t (*p)[3],  float32_t *tr, float32_t *rot, int n, float32_t (*v)[3]);

/**
 * @brief   Fish-eye distortion of points
 *
 * @param   xyz[in]         Array of 3D-points in camera coordinate system
 * @param   uv[out]         Array of 2D-points in sensor space
 * @param   params[in]      Camera intrinsics
 * @param   count[in]       Number of points
 */
extern void distort_kannala(float32_t (*xyz)[3], float32_t (*uv)[2], float32_t *params, int32_t count);
extern void undistort_kannala(float32_t xyz[3], float32_t uv[2], float32_t *params);

/**
 * @brief   Fish-eye distortion of points
 *
 * @param   xyz[in]         Array of 3D-points in camera coordinate system
 * @param   uv[out]         Array of 2D-points in sensor space
 * @param   params[in]      Camera intrinsics
 * @param   res[in]         Camera resolution
 * @param   count[in]       Number of points
 */
extern void distort_kannala_clamp(float32_t (*xyz)[3], float32_t (*uv)[2], float32_t *params, int32_t count);

/**
 * @brief   Project point in world coordinate system into virtual camera sensor space
 *
 * @param   vcam[in]        Virtual camera data
 * @param   xyz[in]         Array of 3D-points in virtual camera coordinate system
 * @param   uv[out]         Array of 2D-points in virtual camera sensor space
 * @param   count[in]       Number of points
 */
extern void vcamera_distort(vcamera_data_t *vcam, float32_t (*xyz)[3], float32_t (*uv)[2], int32_t count);

/**
 * @brief   Map point from distorted virtual camera sensor space to physical
 *          camera coordinate system
 *
 * @param   vcam[in]        Virtual camera data
 * @param   uv[in]          Array of 2D-points in virtual camera sensor space
 * @param   xyz[out]        Array of 3D-points in physical camera coordinate system
 * @param   count[in]       Number of points
 */
extern void vcamera_back_project(vcamera_data_t *vcam, float32_t (*uv)[2], float32_t (*xyz)[3], int32_t count);
extern void vcamera_back_project_scale(vcamera_data_t *vcam, float32_t (*uv)[2], float32_t (*xyz)[3], int32_t count, float32_t scale, float32_t offset[2]);

/**
 * @brief   Initialize virtual camera data
 *
 * @param   vcam[in]            Virtual camera data
 * @param   rotation[in]        Rotation angles [Roll,Pitch,Yaw], in degrees
 * @param   translation[in]     Translation vector
 * @param   fov[in]             Horizontal / vertical field-of-view, in degrees
 * @param   gamma[in]           Fisheye/rectilinear distortion coefficient
 * @param   alpha[in]           Compression ratio
 */
extern void vcamera_init(vcamera_data_t *vcam, float32_t *rotation, float32_t *translation, float32_t *fov, float32_t *gamma, float32_t *alpha);

/**
 * @brief   Prepare virtual camera data for back-project operation
 *
 * @param   vcam[in]        Virtual camera data
 * @param   camera[in]      Physical camera data
 * @param   rotation[in]        Rotation angles [Roll,Pitch,Yaw], in degrees
 * @param   translation[in]     Translation vector
 * @param   fov[in]             Horizontal / vertical field-of-view, in degrees
 * @param   gamma[in]           Fisheye/rectilinear distortion coefficient
 * @param   alpha[in]           Compression ratio
 */
//extern void vcamera_back_project_init(vcamera_data_t *vcam, camera_data_t *camera,  float32_t *rotation, float32_t *translation, float32_t *fov, float32_t gamma, float32_t alpha);

/**
 * @brief   Prepare virtual camera data for back-project operation
 *
 * @param   vcam[in]            Virtual camera data
 * @param   camera[in]          Physical camera data
 * @param   rotation[in]        Rotation angles [Roll,Pitch,Yaw], in degrees
 * @param   translation[in]     Translation vector
 * @param   fov[in]             Horizontal / vertical field-of-view, in degrees
 * @param   gamma[in]           Fisheye/rectilinear distortion coefficient
 * @param   alpha[in]           Compression ratio
 */
extern void vcamera_back_project_to_world_init(vcamera_data_t *vcam, float32_t *rotation, float32_t *translation, float32_t *fov, float32_t *gamma, float32_t *alpha);

#endif  /* __LIBSV_CAMERA_H */
