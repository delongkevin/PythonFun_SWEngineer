/*******************************************************************************
 * camera.c
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

#define MODULE_TAG                      CAMERA

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "config.h"
#include "camera.h"
#include "math-neon.h"
#include "float.h"


#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif
#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif


/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Public API
 ******************************************************************************/

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
void map_world_to_cam(float32_t (*p)[3], float32_t *tr, float32_t *rot, int n, float32_t (*v)[3])
{
    /* ...get camera translation vector coordinates */
    float32x4_t X = vdupq_n_f32(tr[0]);
    float32x4_t Y = vdupq_n_f32(tr[1]);
    float32x4_t Z = vdupq_n_f32(tr[2]);

    /* ...load coefficients of 3*3 rotation matrix (row-major) */
    float32x4_t a0123 = vld1q_f32(&rot[0]);
    float32x4_t a4567 = vld1q_f32(&rot[4]);
    float32_t   a8 = rot[8];

    int         i;

    /* ...process complete set of the points (okay to have extra empty points in the end) */
    for (i = 0; i < n; i += 4)
    {
        /* ...read 4 points in interleaved order:
         * [0]: {X0:X1:X2:X3}
         * [1]: {Y0:Y1:Y2:Y3}
         * [2]: {Z0:Z1:Z2:Z3}
         */
        float32x4x3_t   P = vld3q_f32(*p);
        p += 4;

        /* ...subtract camera translation vector */
        P.val[0] = vsubq_f32(P.val[0], X);
        P.val[1] = vsubq_f32(P.val[1], Y);
        P.val[2] = vsubq_f32(P.val[2], Z);

        /* ...multiply by rotation matrix and map to camera space: {X,Y,Z} = {-y,-z,x} */
        float32x4x3_t   Q;
        Q.val[2] = vmlaq_laneq_f32(vmlaq_laneq_f32(vmulq_laneq_f32(P.val[0], a0123, 0), P.val[1], a0123, 1), P.val[2], a0123, 2);
        Q.val[0] = vnegq_f32(vmlaq_laneq_f32(vmlaq_laneq_f32(vmulq_laneq_f32(P.val[0], a0123, 3), P.val[1], a4567, 0), P.val[2], a4567, 1));
        Q.val[1] = vnegq_f32(vmlaq_n_f32(vmlaq_laneq_f32(vmulq_laneq_f32(P.val[0], a4567, 2), P.val[1], a4567, 3), P.val[2], a8));

        /* ...store result in output array */
        vst3q_f32(*v, Q);
        v += 4;
    }
}

/**
 * @brief   Fisheye distortion of 4 points
 *
 * @param   d_coeff[in]     Distortion polynomial coefficients
 * @param   f_xy[in]        Camera matrix focals
 * @param   c_xy[in]        Camera matrix central points
 * @param   P[in]           Input ray coordinates:
 *                          [0]: {X0,X1,X2,X3}
 *                          [1]: {Y0,Y1,Y2,Y3}
 *                          [2]: {Z0,Z1,Z2,Z3}
 *
 * @return                  Sensor coordinates:
 *                          [0]: {U0,U1,U2,U3}
 *                          [1]: {V0,V1,V2,V3}
 */
//#define OPENCV_MODEL    1
#ifdef OPENCV_MODEL
static inline __attribute__((__always_inline__))
float32x4x2_t distort_kannala_4(
    const float32x4_t d_coeff,
    const float32x2_t f_xy,
    const float32x2_t c_xy,
    const float32x4x3_t P)
{
    float32x4x2_t   out;

    /* ...get radius length (eliminate zero division): x^2+y^2 */
    float32x4_t     rad_2 = vmlaq_f32(vmulq_f32(P.val[0], P.val[0]), P.val[1], P.val[1]);
    rad_2 = vmaxq_f32(rad_2, vmovq_n_f32(1e-6f));

    /* ...get radius and its inverse */
    float32x4_t i_rad = vinvsqrtq_f32(rad_2);
    float32x4_t rad = vmulq_f32(rad_2, i_rad);

    /* ...get theta=atan2(sqrt(x^2+y^2), z) */
    float32x4_t theta = atan2_ps(rad, P.val[2]);

    /* ...calculate 9-th degree odd polynomial of theta */
    float32x4_t theta2 = vmulq_f32(theta, theta);

    float32x4_t r_dist = vmovq_n_f32(vgetq_lane_f32(d_coeff, 3));
    r_dist = vmlaq_f32(vmovq_n_f32(vgetq_lane_f32(d_coeff, 2)), r_dist, theta2);
    r_dist = vmlaq_f32(vmovq_n_f32(vgetq_lane_f32(d_coeff, 1)), r_dist, theta2);
    r_dist = vmlaq_f32(vmovq_n_f32(vgetq_lane_f32(d_coeff, 0)), r_dist, theta2);
    r_dist = vmlaq_f32(vmovq_n_f32(1.0f), r_dist, theta2);
    r_dist = vmulq_f32(r_dist, theta);

    float32x4_t dist_x, dist_y;

    /* ...poly(theta) / sqrt(x^2+y^2) */
    r_dist = vmulq_f32(r_dist, i_rad);

    /* ...distorted points */
    dist_x = vmulq_f32(P.val[0], r_dist);
    dist_y = vmulq_f32(P.val[1], r_dist);

    /* ...multiply points by camera matrix */
    out.val[0] = vmlaq_lane_f32(vmovq_n_f32(vget_lane_f32(c_xy, 0)), dist_x, f_xy, 0);
    out.val[1] = vmlaq_lane_f32(vmovq_n_f32(vget_lane_f32(c_xy, 1)), dist_y, f_xy, 1);

    TRACE(0, _b("P=%f,%f,%f,%f:%f,%f,%f,%f, c_xy=%f,%f, f_xy=%f,%f, Q=%f,%f,%f,%f:%f,%f,%f,%f"), __float32x4_p(dist_x), __float32x4_p(dist_y),
          __float32x2_p(c_xy), __float32x2_p(f_xy), __float32x4_p(out.val[0]), __float32x4_p(out.val[1]));

    return out;
}
#else
static inline __attribute__((__always_inline__))
float32x4x2_t distort_kannala_4(
    const float32x4_t d_coeff,
    const float32x2_t f_xy,
    const float32x2_t c_xy,
    const float32x4x3_t P)
{
    float32x4x2_t   out;

    /* ...get radius length (eliminate zero division): x^2+y^2 */
    float32x4_t     rad_2 = vmlaq_f32(vmulq_f32(P.val[0], P.val[0]), P.val[1], P.val[1]);
    rad_2 = vmaxq_f32(rad_2, vmovq_n_f32(1e-6f));

    /* ...get radius and its inverse */
    float32x4_t i_rad = vinvsqrtq_f32(rad_2);
    float32x4_t rad = vmulq_f32(rad_2, i_rad);

    /* ...get theta=atan2(sqrt(x^2+y^2), z) */
    float32x4_t theta = atan2_ps(rad, P.val[2]);

    float32x4_t r_dist = vmovq_n_f32(vgetq_lane_f32(d_coeff, 3));
    r_dist = vmlaq_f32(vmovq_n_f32(vgetq_lane_f32(d_coeff, 2)), r_dist, theta);
    r_dist = vmlaq_f32(vmovq_n_f32(vgetq_lane_f32(d_coeff, 1)), r_dist, theta);
    r_dist = vmlaq_f32(vmovq_n_f32(vgetq_lane_f32(d_coeff, 0)), r_dist, theta);
    r_dist = vmlaq_f32(vmovq_n_f32(1.0f), r_dist, theta);
    r_dist = vmulq_f32(r_dist, theta);

    float32x4_t dist_x, dist_y;

    /* ...poly(theta) / sqrt(x^2+y^2) */
    r_dist = vmulq_f32(r_dist, i_rad);

    /* ...distorted points */
    dist_x = vmulq_f32(P.val[0], r_dist);
    dist_y = vmulq_f32(P.val[1], r_dist);

    /* ...multiply points by camera matrix */
    out.val[0] = vmlaq_lane_f32(vmovq_n_f32(vget_lane_f32(c_xy, 0)), dist_x, f_xy, 0);
    out.val[1] = vmlaq_lane_f32(vmovq_n_f32(vget_lane_f32(c_xy, 1)), dist_y, f_xy, 1);

    TRACE(0, _b("P=%f,%f,%f,%f:%f,%f,%f,%f, c_xy=%f,%f, f_xy=%f,%f, Q=%f,%f,%f,%f:%f,%f,%f,%f"), __float32x4_p(dist_x), __float32x4_p(dist_y),
          __float32x2_p(c_xy), __float32x2_p(f_xy), __float32x4_p(out.val[0]), __float32x4_p(out.val[1]));

    return out;
}
#endif
/**
 * @brief   Fish-eye distortion of points
 *
 * @param   xyz[in]         Array of 3D-points in camera coordinate system
 * @param   uv[out]         Array of 2D-points in sensor space
 * @param   params[in]      Camera intrinsics
 * @param   count[in]       Number of points
 */
void distort_kannala(float32_t (*xyz)[3], float32_t (*uv)[2], float32_t *params, int32_t count)
{
    /* ...distortion polynomial coefficients */
    float32x4_t distort_coeff = vld1q_f32(params);

    /* ...camera matrix coefficients */
    float32x2_t f_xy = vld1_f32(params + 4);
    float32x2_t c_xy = vld1_f32(params + 6);

    /* ...4 points at once */
    while (count > 0)
    {
        float32x4x3_t in_xyz = vld3q_f32(*xyz);
        xyz += 4;

        float32x4x2_t out;
        out = distort_kannala_4(distort_coeff, f_xy, c_xy,  in_xyz);

        vst2q_f32(*uv, out);
        uv += 4;

        count -= 4;
    }
}



static inline float32_t norm_v2f(const float32_t in[2])
{
    float32_t abs2 = in[0] * in[0] + in[1] * in[1];
    float32_t norm = 0.f;
    errno = 0;
    if (abs2 > 0.f)
    {
        norm = sqrtf(abs2);
    }
    return (errno == 0) ? norm : 0.f;
}

void undistort_kannala(float32_t xyz[3], float32_t uv[2], float32_t *params)
{
    float32_t K1 = 1.f;
    float32_t K2 = params[0];
    float32_t K3 = params[1];
    float32_t K4 = params[2];
    float32_t K5 = params[3];

    float32_t fx = params[4];
    float32_t fy = params[5];
    float32_t cx = params[6];
    float32_t cy = params[7];

    float32_t point[2];
    point[0] = (uv[0] - cx) / fx;
    point[1] = (uv[1] - cy) / fy;

    float32_t thD = norm_v2f(point);

    if (thD < FLT_EPSILON)
    {
        thD = FLT_EPSILON;
    }

    float32_t scale = 1.0f;

    thD = MIN(MAX(-M_PI / 2.f, thD), M_PI / 2.f);

    if (thD > FLT_EPSILON)
    {
        // compensate distortion iteratively
        float32_t theta1 = thD;

        for (uint32_t j = 0; j < 10U; j++)
        {
            float32_t theta2 = theta1 * theta1;
            float32_t theta3 = theta1 * theta2;
            float32_t theta4 = theta2 * theta2;

            float32_t k2_th1 = K2 * theta1;
            float32_t k3_th2 = K3 * theta2;
            float32_t k4_th3 = K4 * theta3;
            float32_t k5_th4 = K5 * theta4;

            float32_t th_fix = (theta1 * (K1 + k2_th1 + k3_th2 + k4_th3 + k5_th4) - thD)
            / (K1 + 2.f * k2_th1 + 3.f * k3_th2 + 4.f * k4_th3 + 5.f * k5_th4);

            theta1 = theta1 - th_fix;

            if (fabs(th_fix) < FLT_EPSILON)
            {
                break;
            }
        }

        scale = tanf(theta1) / thD;
    }

    xyz[0] = point[0] * scale;
    xyz[1] = point[1] * scale;
    xyz[2] = 1.0f;
}


/**
 * @brief   Fish-eye distortion of points
 *
 * @param   xyz[in]         Array of 3D-points in camera coordinate system
 * @param   uv[out]         Array of 2D-points in sensor space
 * @param   params[in]      Camera intrinsics
 * @param   count[in]       Number of points
 */
void distort_kannala_clamp(float32_t (*xyz)[3], float32_t (*uv)[2], float32_t *params, int32_t count)
{
    int i = 0;

    /* ...distortion polynomial coefficients */
    float32x4_t distort_coeff = vld1q_f32(params);

    /* ...camera matrix coefficients */
    float32x2_t f_xy = vld1_f32(params + 4);
    float32x2_t c_xy = vld1_f32(params + 6);

    const float32_t EPS = (float32_t)(1.0 / 2048.0);

    /* ...4 points at once */
    while (count > 0)
    {
        float32x4x3_t in_xyz = vld3q_f32(*xyz);
        xyz += 4;

        float32x4x2_t out;
        out = distort_kannala_4(distort_coeff, f_xy, c_xy,  in_xyz);

        /* ...clamp values to camera resolution */
        out.val[0] = vmaxq_f32(vminq_f32(out.val[0], vdupq_n_f32(1.0f - EPS)), vdupq_n_f32(0.0f));
        out.val[1] = vmaxq_f32(vminq_f32(out.val[1], vdupq_n_f32(1.0f - EPS)), vdupq_n_f32(0.0f));

        vst2q_f32(*uv, out);
        uv += 4;

        count -= 4;
    }
}

/**
 * @brief   Find solution of equation "gamma*r + (1-gamma)*atan(r) = theta"
 *          using Newton's method
 *
 * @param   theta[in]           Right-side term of equation
 * @param   gamma[in]           Distortion coefficient
 *
 * @return                      Approximate root of the equation
 */
static inline float32x4_t solve_back_project(float32x4_t theta, float32_t gamma)
{
    int         i;
    float32x4_t r_n = theta;
    float32x4_t one = vmovq_n_f32(1.0f);

    for (i = 0; i < 4; i++)
    {
        float32x4_t t0 = r_n;
        float32x4_t t1 = atan_ps(r_n);
        float32x4_t f_n = vsubq_f32(vmlaq_n_f32(t1, vsubq_f32(t0, t1), gamma), theta);

        float32x4_t d0 = one;
        float32x4_t d1 = vdivq_f32(one, vmlaq_f32(one, r_n, r_n));
        float32x4_t df_n = vmlaq_n_f32(d1, vsubq_f32(d0, d1), gamma);

        r_n = vsubq_f32(r_n, vdivq_f32(f_n, df_n));

        TRACE(0, _b("i=%d: theta=%f,%f,%f,%f, r_n=%f,%f,%f,%f, f_n=%e,%e,%e,%e"), i, __float32x4_p(theta), __float32x4_p(r_n), __float32x4_p(f_n));
    }

    return r_n;
}

/**
 * @brief   Map point from distorted virtual camera sensor space to physical camera
 *          coordinate system
 *
 * @param   vcam[in]        Virtual camera data
 * @param   uv[in]          Array of 2D-points in virtual camera sensor space
 * @param   xyz[out]        Array of 3D-points in physical camera coordinate system
 * @param   count[in]       Number of points
 */
void vcamera_back_project(vcamera_data_t *vcam, float32_t (*uv)[2], float32_t (*xyz)[3], int32_t count)
{
    /* ...load transform matrix */
    float32x4_t     f_uv = vld1q_f32(vcam->params);
    float32_t       gamma = vcam->gamma;
    float32_t       delta = vcam->delta;
    float32_t       alpha = vcam->alpha;
    float32_t       beta = vcam->beta;

    /* ...load rotation matrix */
    float32x4_t     U0123 = vld1q_f32(&vcam->R[0]);
    float32x4_t     U4567 = vld1q_f32(&vcam->R[4]);
    float32_t       U8 = vcam->R[8];

    while (count > 0)
    {
        /* ...load screen coordinates: [0]: {X0,X1,X2,X3}, [1]: {Y0,Y1,Y2,Y3} */
        float32x4x2_t   Q = vld2q_f32(*uv);
        uv += 4;

        /* ...get distorted lense coordinate  */
        float32x4_t     x = atan_ps(vmulq_n_f32(tan_ps(Q.val[0]), alpha));
        float32x4_t     y = atan_ps(vmulq_n_f32(tan_ps(Q.val[1]), beta));

        Q.val[0] = vmlaq_laneq_f32(vdupq_laneq_f32(f_uv, 2), Q.val[0], f_uv, 0);
        Q.val[1] = vmlaq_laneq_f32(vdupq_laneq_f32(f_uv, 3), Q.val[1], f_uv, 1);

        float32x4_t     ax = atan_ps(Q.val[0]);
        float32x4_t     lambda = vmlaq_n_f32(ax, vsubq_f32(Q.val[0], ax), gamma);

        float32x4_t     ay = atan_ps(Q.val[1]);
        float32x4_t     phi = vmlaq_n_f32(ay, vsubq_f32(Q.val[1], ay), delta);

        float32x4_t     s0, c0;
        sincos_ps(lambda, &s0, &c0);

        float32x4_t     s1, c1;
        sincos_ps(phi, &s1, &c1);

        float32x4_t     X = vmulq_n_f32(vmulq_f32(s0, vmlaq_n_f32(c1, vsubq_f32(vdupq_n_f32(1.0), c1), delta)), alpha);
        float32x4_t     Y = vmulq_n_f32(vmulq_f32(s1, vmlaq_n_f32(c0, vsubq_f32(vdupq_n_f32(1.0), c0), gamma)), beta);
        float32x4_t     Z = vmulq_f32(c0, c1);

        float32x4x3_t   P = mat3x3_mulv(X, Y, Z, U0123, U4567, U8);

        /* ...store coordinates */
        vst3q_f32(*xyz, P);
        xyz += 4;

        count -= 4;
    }
}


void vcamera_back_project_scale(vcamera_data_t *vcam, float32_t (*uv)[2], float32_t (*xyz)[3], int32_t count, float32_t scale, float32_t offset[2])
{
    /* ...load transform matrix */
    float32x4_t     f_uv = vld1q_f32(vcam->params);
    float32_t       gamma = vcam->gamma;
    float32_t       delta = vcam->delta;
    float32_t       alpha = vcam->alpha;
    float32_t       beta = vcam->beta;

    /* ...load rotation matrix */
    float32x4_t     U0123 = vld1q_f32(&vcam->R[0]);
    float32x4_t     U4567 = vld1q_f32(&vcam->R[4]);
    float32_t       U8 = vcam->R[8];

    float32x4_t     scale4 = vdupq_n_f32(scale);
    float32x4_t     offsetX4 = vdupq_n_f32(offset[0]);
    float32x4_t     offsetY4 = vdupq_n_f32(offset[1]);

    while (count > 0)
    {
        /* ...load screen coordinates: [0]: {X0,X1,X2,X3}, [1]: {Y0,Y1,Y2,Y3} */
        float32x4x2_t   Q = vld2q_f32(*uv);
        Q = mlaq2(Q, scale4, scale4, offsetX4, offsetY4);
        uv += 4;

        /* ...get distorted lense coordinate  */
        float32x4_t     x = atan_ps(vmulq_n_f32(tan_ps(Q.val[0]), alpha));
        float32x4_t     y = atan_ps(vmulq_n_f32(tan_ps(Q.val[1]), beta));

        Q.val[0] = vmlaq_laneq_f32(vdupq_laneq_f32(f_uv, 2), Q.val[0], f_uv, 0);
        Q.val[1] = vmlaq_laneq_f32(vdupq_laneq_f32(f_uv, 3), Q.val[1], f_uv, 1);

        float32x4_t     ax = atan_ps(Q.val[0]);
        float32x4_t     lambda = vmlaq_n_f32(ax, vsubq_f32(Q.val[0], ax), gamma);

        float32x4_t     ay = atan_ps(Q.val[1]);
        float32x4_t     phi = vmlaq_n_f32(ay, vsubq_f32(Q.val[1], ay), delta);

        float32x4_t     s0, c0;
        sincos_ps(lambda, &s0, &c0);

        float32x4_t     s1, c1;
        sincos_ps(phi, &s1, &c1);

        float32x4_t     X = vmulq_n_f32(vmulq_f32(s0, vmlaq_n_f32(c1, vsubq_f32(vdupq_n_f32(1.0), c1), delta)), alpha);
        float32x4_t     Y = vmulq_n_f32(vmulq_f32(s1, vmlaq_n_f32(c0, vsubq_f32(vdupq_n_f32(1.0), c0), gamma)), beta);
        float32x4_t     Z = vmulq_f32(c0, c1);

        float32x4x3_t   P = mat3x3_mulv(X, Y, Z, U0123, U4567, U8);

        /* ...store coordinates */
        vst3q_f32(*xyz, P);
        xyz += 4;

        count -= 4;
    }
}

/**
 * @brief   Find solution of system of equations using iterative method:
 *                  X/Z=tan(lambda)*cos(phi)/(cos(phi)*delta + 1-delta)
 *                  Y/Z=tan(phi)*cos(lambda)/(cos(lamba)*gamma + 1-gamma)
 *
 * @param   X[in]           X-coordinate
 * @param   Y[in]           Y-coordinate
 * @param   Z[in]           Z-coordinate
 * @param   gamma[in]       Gamma-coefficient (0..1)
 * @param   delta[in]       Delta-coefficient (0..1)
 *
 * @return                  Approximate solution of the equation:
 *                          [0]: {lambda}
 *                          [1]: {phi}
 */
static inline float32x4x2_t solve_back_project_5(float32x4_t X, float32x4_t Y, float32x4_t Z, float32_t gamma, float32_t delta)
{
    float32x4_t     phi = vmovq_n_f32(0.0f);
    float32x4_t     lambda = vmovq_n_f32(0.0f);
    float32x4x2_t   r;
    int             i;

    for (i = 0; i < 4; i++)
    {
        float32x4_t     c0 = cos_ps(lambda);
        float32x4_t     n0 = Y;
        float32x4_t     t0 = vdivq_f32(vmlaq_n_f32(c0, vsubq_f32(vmovq_n_f32(1.0f), c0), gamma), c0);
        float32x4_t     d0 = vmulq_f32(Z, t0);
        phi = atan2_ps(n0, d0);

        TRACE(0, _b("c0=%f,%f,%f,%f, cc=%f,%f,%f,%f, n0=%f,%f,%f,%f, d0=%f,%f,%f,%f"), __float32x4_p(c0), __float32x4_p(t0), __float32x4_p(n0), __float32x4_p(d0));

        float32x4_t     c1 = cos_ps(phi);
        float32x4_t     n1 = X;
        float32x4_t     t1 = vdivq_f32(vmlaq_n_f32(c1, vsubq_f32(vmovq_n_f32(1.0f), c1), delta), c1);
        float32x4_t     d1 = vmulq_f32(Z, t1);
        lambda = atan2_ps(n1, d1);

        TRACE(0, _b("c1=%f,%f,%f,%f, n1=%f,%f,%f,%f, d1=%f,%f,%f,%f"), __float32x4_p(c1), __float32x4_p(n1), __float32x4_p(d1));
        TRACE(0, _b("i=%d: lambda=%f,%f,%f,%f, phi=%f,%f,%f,%f"), i, __float32x4_p(lambda), __float32x4_p(phi));
    }

    r.val[0] = lambda;
    r.val[1] = phi;

    return r;
}

void vcamera_distort(vcamera_data_t *vcam, float32_t (*xyz)[3], float32_t (*uv)[2], int32_t count)
{
    float32x4_t f_xy = vld1q_f32(vcam->params);
    float32_t   gamma = vcam->gamma;
    float32_t   delta = vcam->delta;
    float32_t   inv_alpha = 1.0f / vcam->alpha;
    float32_t   inv_beta = 1.0f / vcam->beta;

    /* ...process 4 points at once */
    while (count > 0)
    {
        float32x4x3_t   P = vld3q_f32(*xyz);
        xyz += 4;

        TRACE(0, _b("P=%f,%f,%f,%f : %f,%f,%f,%f : %f,%f,%f,%f"), __float32x4_p(P.val[0]), __float32x4_p(P.val[1]), __float32x4_p(P.val[2]));

        float32x4_t     X = vmulq_n_f32(P.val[0], inv_alpha);
        float32x4_t     Y = vmulq_n_f32(P.val[1], inv_beta);
        float32x4_t     Z = P.val[2];

        TRACE(0, _b("XYZ=%f,%f,%f,%f : %f,%f,%f,%f : %f,%f,%f,%f"), __float32x4_p(X), __float32x4_p(Y), __float32x4_p(Z));

        float32x4x2_t   angles = solve_back_project_5(X, Y, Z, gamma, delta);

        TRACE(0, _b("angles: %f,%f,%f,%f : %f,%f,%f,%f"), __float32x4_p(angles.val[0]), __float32x4_p(angles.val[1]));

        float32x4_t     u = solve_back_project(angles.val[0], gamma);
        float32x4_t     v = solve_back_project(angles.val[1], delta);

        float32x4x2_t   out;
        out.val[0] = vmlaq_laneq_f32(vdupq_laneq_f32(f_xy, 2), u, f_xy, 0);
        out.val[1] = vmlaq_laneq_f32(vdupq_laneq_f32(f_xy, 3), v, f_xy, 1);

        TRACE(0, _b("Q=%f,%f,%f,%f : %f,%f,%f,%f"), __float32x4_p(out.val[0]), __float32x4_p(out.val[1]));

        /* ...store point in virtual camera sensor space */
        vst2q_f32(*uv, out);
        uv += 4;

        count -= 4;
    }
}

/**
 * @brief   Adjust camera parameters
 *
 * @param   camera[in]      Camera data
 * @param   T[in]           Camera translation vector in world coordinate system
 * @param   R[in]           Camera rotation vector
 */
void camera_set_extrinsics(camera_data_t *camera, const float32_t *T, const float32_t *R)
{
    __mat3x3    r, t;

    /* ...copy camera translation vector */
    memcpy(camera->T, T, sizeof(camera->T));

    /* ...build rotation matrix (axis swap? - tbd) */
    __mat3x3_rotation(r, (__vec3){R[0], -R[1], R[2]}, __MATH_ONE);

    /* ...transpose matrix - rotation matrix is stored in row-major order  */
    __mat3x3_transpose(r, camera->R);
}

/**
 * @brief   Adjust camera intrinsic parameters
 *
 * @param   camera[in]      Camera data
 * @param   dist[in]        Fisheye lens distortion polynomial coefficients
 * @param   intr[in]        Camera matrix
 */
void camera_set_intrinsics(camera_data_t *camera, const float32_t *resolution, const float32_t *dist, const float32_t *intr)
{
    float32_t   invW = 1.0f / resolution[0];
    float32_t   invH = 1.0f / resolution[1];

    /* ...copy distortion coefficients */
    memcpy(&camera->params[0], dist, sizeof(float32_t [4]));

    /* ...copy camera matrix (only focus and optical center) */
    camera->params[4] = intr[0 * 3 + 0] * invW;
    camera->params[5] = intr[1 * 3 + 1] * invH;
    camera->params[6] = intr[0 * 3 + 2] * invW;
    camera->params[7] = intr[1 * 3 + 2] * invH;

    TRACE(1, _b("cam: dist=%f,%f,%f,%f, matr=%f,%f,%f,%f"),
          camera->params[0], camera->params[1], camera->params[2], camera->params[3],
          camera->params[4], camera->params[5], camera->params[6], camera->params[7]);
}

/**
 * @brief   Convert Magna extrinsics to ISO
 *
 * @param   cfg[in]     Global configuration data
 * @param   k[in]       Camera index
 * @param   angle[in]   Rotation angles (Magna), radians
 * @param   pos[in]     Translation vector (Magna), mm
 */
void camera_set_magna_extrinsics(cfg_data_t *cfg, int k, float32_t *angle, float32_t *pos)
{
    cfg_camera_t       *camera = &cfg->camera[k];
    const float32_t     preroll[4] = { 90.0f, 180.0f, -90.0f, 0.0f };

    /* ...build rotation matrix in Magna camera coordinate system */
    __mat3x3    s = {
        0, 1, 0,
        0, 0, -1,
        -1, 0, 0,
    };

    __mat3x3    rz_pre, rx, ry, rz;
    __matNxN_rotate(3, rz_pre, 2, 1, preroll[k]);
    __matNxN_rotate(3, rx, 0, 2, __MATH_DEGREES(angle[1]));
    __matNxN_rotate(3, ry, 0, 1, __MATH_DEGREES(angle[0]));
    __matNxN_rotate(3, rz, 2, 1, __MATH_DEGREES(angle[2]));

    __mat3x3    t0, t1;
    __mat3x3_mul(rz, ry, t0);
    __mat3x3_mul(t0, rx, t1);
    __mat3x3_mul(t1, rz_pre, t0);
    __mat3x3_mul(t0, s, t1);

    /* ...get rotation angles in ISO coordinate system */
    __mat3x3_rot2xyz(t1, camera->rotation);

    /* ...translate camera position */
    camera->position[0] = cfg->vehicle.wheel_base - pos[0];
    camera->position[1] = -pos[1];
    camera->position[2] = pos[2];

    /* ...mark extrinsics are in ISO8855 format */
    camera->magna_format = 0;

    TRACE(INIT, _b("cam-%d: rot=%f,%f,%f, tr=%f,%f,%f"), k,
          camera->rotation[0], camera->rotation[1], camera->rotation[2],
          camera->position[0], camera->position[1], camera->position[2]);
}

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
void vcamera_init(vcamera_data_t *vcam, float32_t *rotation, float32_t *translation, float32_t *fov, float32_t *gamma, float32_t *alpha)
{
    __mat3x3    r, t;

    /* ...copy camera translation vector */
    memcpy(vcam->T, translation, sizeof(vcam->T));

    /* ...build rotation matrix (axis swap? - tbd) */
    __mat3x3_rotation(r, (__vec3){rotation[0], -rotation[1], rotation[2]}, __MATH_ONE);

    /* ...transpose matrix - rotation matrix is stored in row-major order  */
    __mat3x3_transpose(r, vcam->R);

    /* ...calculate mapping function for extreme FoV angles */
    float32x4_t t0 = vld1q_f32(fov);
    float32x2_t fov2 = vmul_n_f32(vget_low_f32(t0), (float32_t)(0.5 * M_PI / 180.0));
    float32x2_t off = vmul_n_f32(vget_high_f32(t0), (float32_t)(M_PI / 180.0));
    float32x4_t theta = vcombine_f32(vadd_f32(off, fov2), vsub_f32(off, fov2));

    float32x4_t s, c;
    sincos_ps(theta, &s, &c);
    float32x4_t theta1 = atan2_ps(s, vmulq_n_f32(c, alpha[0]));

    float32x4_t map = solve_back_project(theta1, gamma[0]);

    /* ...set virtual camera intrinsics */
    vcam->params[0] = 2.0f / (vgetq_lane_f32(map, 0) - vgetq_lane_f32(map, 2));
    vcam->params[2] = -0.5f * vcam->params[0] * (vgetq_lane_f32(map, 0) + vgetq_lane_f32(map, 2));

    float32x4_t theta2 = atan2_ps(s, vmulq_n_f32(c, alpha[1]));

    float32x4_t t1 = solve_back_project(theta2, gamma[1]);
    vcam->params[1] = -2.0f / (vgetq_lane_f32(t1, 1) - vgetq_lane_f32(t1, 3));
    vcam->params[3] = -0.5f * vcam->params[1] * (vgetq_lane_f32(t1, 1) + vgetq_lane_f32(t1, 3));

    /* ...save distortion coefficient */
    vcam->gamma = gamma[0];
    vcam->delta = gamma[1];

    /* ...save compression ratio */
    vcam->alpha = alpha[0];
    vcam->beta = alpha[1];
}

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
void vcamera_back_project_init(vcamera_data_t *vcam, camera_data_t *camera,  float32_t *rotation, float32_t *translation, float32_t *fov, float32_t gamma, float32_t alpha)
{
    /* ...camera-to-world transformation matrix (column-major order): {z, -x, -y} */
    const __mat3x3  S = {
        0, -1, 0,
        0, 0, -1,
        1, 0, 0,
    };

    /* ...world-to-camera transformation matrix (column-major order): {-y,-z, x} */
    const __mat3x3  Sinv = {
        0, 0, 1,
        -1, 0, 0,
        0, -1, 0,
    };

    /* ...set virtual camera translation parameter */
    memcpy(vcam->T, translation, sizeof(float32_t[3]));

    __mat3x3        m0, m1, R, Rv, Rvt;

    /* ...calculate virtual camera rotation matrix - tbd - simplify a bit */
    __mat3x3_rotation(Rv, (__vec3){rotation[0], -rotation[1], rotation[2]}, __MATH_ONE);

    /* ...transform point from virtual camera space to physical */
    __mat3x3_transpose(camera->R, R);
    __mat3x3_transpose(Rv, Rvt);

    /* ...Pcam = S(world-to-cam)*R*Rv^-1*S(cam-to-world)*Pvirt */
    __mat3x3_mul(Sinv, R, m0);
    __mat3x3_mul(m0, Rvt, m1);
    __mat3x3_mul(m1, S, R);

    /* ...save virtual camera rotation matrix in row-major format */
    __mat3x3_transpose(R, vcam->R);

    /* ...calculate mapping function for extreme FoV angles */
    float32x2_t fov2 = vmul_n_f32(vld1_f32(fov), (float32_t)(0.5 * M_PI / 180));
    float32x4_t theta = vcombine_f32(fov2, vneg_f32(fov2));
    float32x4_t map = solve_back_project(theta, gamma);

    /* ...use calculated scale factors to preserve requested FoV */
    vst1_f32(vcam->params, vget_low_f32(map));

    /* ...save virtual camera distortion coefficient */
    vcam->gamma = gamma;

    /* ...save compression ratio */
    vcam->alpha = alpha;
}

/**
 * @brief   Prepare virtual camera data for back-project operation
 *
 * @param   vcam[in]            Virtual camera data
 * @param   rotation[in]        Rotation angles [Roll,Pitch,Yaw], in degrees
 * @param   translation[in]     Translation vector
 * @param   fov[in]             Horizontal / vertical field-of-view, in degrees
 * @param   gamma[in]           Fisheye/rectilinear distortion coefficient
 * @param   alpha[in]           Compression ratio
 */
void vcamera_back_project_to_world_init(vcamera_data_t *vcam, float32_t *rotation, float32_t *translation, float32_t *fov, float32_t *gamma, float32_t *alpha)
{
    /* ...camera-to-world transformation matrix (column-major order): {z, -x, -y} */
    const __mat3x3  S = {
        0, 0, 1,
        -1, 0, 0,
        0, -1, 0,
    };

    __mat3x3        R;

    /* ...calculate virtual camera rotation matrix */
    __mat3x3_rotation(R, (__vec3){rotation[0], -rotation[1], rotation[2]}, __MATH_ONE);

    /* ...Pworld = Rv^-1*S(cam-to-world)*Pvirt + T*/
    __mat3x3_mul(S, R, vcam->R);

    /* ...set virtual camera translation parameter */
    memcpy(vcam->T, translation, sizeof(float32_t[3]));

    /* ...calculate mapping function for extreme FoV angles */
    float32x4_t t0 = vld1q_f32(fov);
    float32x2_t fov2 = vmul_n_f32(vget_low_f32(t0), (float32_t)(0.5 * M_PI / 180.0));
    float32x2_t off = vmul_n_f32(vget_high_f32(t0), (float32_t)(M_PI / 180.0));
    float32x4_t theta = vcombine_f32(vadd_f32(off, fov2), vsub_f32(off, fov2));

    float32x4_t s, c;
    sincos_ps(theta, &s, &c);
    float32x4_t theta1 = atan2_ps(s, vmulq_n_f32(c, alpha[0]));

    float32x4_t map = solve_back_project(theta1, gamma[0]);

    /* ...use calculated scale factors to preserve requested FoV */
    vcam->params[0] = (vgetq_lane_f32(map, 0) - vgetq_lane_f32(map, 2)) * 0.5f;
    vcam->params[2] = (vgetq_lane_f32(map, 0) + vgetq_lane_f32(map, 2)) * 0.5f;

    float32x4_t theta2 = atan2_ps(s, vmulq_n_f32(c, alpha[1]));
    float32x4_t t1 = solve_back_project(theta2, gamma[1]);
    vcam->params[1] = (vgetq_lane_f32(t1, 1) - vgetq_lane_f32(t1, 3)) * 0.5f;
    vcam->params[3] = 0.5f * (vgetq_lane_f32(t1, 1) + vgetq_lane_f32(t1, 3));

    /* ...save virtual camera distortion coefficient */
    vcam->gamma = gamma[0];
    vcam->delta = gamma[1];

    /* ...save compression ratio */
    vcam->alpha = alpha[0];
    vcam->beta = alpha[1];

    TRACE(DEBUG, _b("bp: params=%f,%f,%f,%f"), vcam->params[0], vcam->params[1], vcam->params[2], vcam->params[3]);
    TRACE(DEBUG, _b("bp: alpha=%f,beta=%f,gamma=%f,delta=%f"), vcam->alpha, vcam->beta, vcam->gamma, vcam->delta);
}
