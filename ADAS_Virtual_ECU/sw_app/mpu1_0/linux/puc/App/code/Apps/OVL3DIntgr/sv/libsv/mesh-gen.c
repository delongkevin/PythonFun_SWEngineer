/*******************************************************************************
 * mesh-gen.c
 *
 * Mesh generator for surround view
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

#define MODULE_TAG                      MESH-GEN

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "display.h"
#include "math-neon.h"
#include "vbo-dynarray.h"
#include "mesh-render.h"
#include "mesh-gen.h"
#include "../libhv/hv.h"
#ifdef BUILD_NATIVE
#include "mesh-dbg.h"
#include "scv-dbg.h"
#endif

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Mesh generation
 ******************************************************************************/

/**
 * @brief   Mesh generator data
 */
typedef struct mesh_gen
{
    /**> Mesh generator data for individual cameras */
    camera_data_t       camera[SV_CAMERAS_NUMBER];

    /**> Dynamic vertex arrays for the cameras */
    mesh_vbo_t          vbo[SV_CAMERAS_NUMBER];

    /**> Matrix of ray-tracing equation (row-major form) */
    float32_t           U[3 * 3];

    /**> Additive term W of ray-tracing equation */
    float32_t           W[3];

    union {
        struct {
            /**> Camera index for SCV-mesh generation */
            uint32_t        camera_id;

            /**> Virtual camera for back-projection */
            vcamera_data_t  vcam;

            /**> Currently filled vertex array */
            mesh_vbo_t     *current;

            /**> Mask area pointer: [Xmin,Ymin,Xmax,Ymax] */
            float32_t      *mask;
        };

        struct {
            /**> Parabolic bowl parameters for a see-through view generation */
            float32_t       invRx, invRy, steep, smooth;

            /**> Coefficients "Bx/By/Bz" */
            float32_t       B[3];
        };
    };

    /**> Historical-view module data */
    hv_data_t          *hv;

    /**> Historical-view VBOs array */
    vbo_dynarray_t     *hv_vbo;

#ifdef  BUILD_NATIVE
    /**> Mesh-specific debug window data */
    void               *dbg;
#endif

}   mesh_gen_t;

camera_data_t       vm_camera_data[SV_CAMERAS_NUMBER];

/*******************************************************************************
 * Tracer functions
 ******************************************************************************/

/**
 * @brief   Solve linear equations A*z + B = 0. Division by zero results into z=0
 *
 * @param   A[in]       First coefficient of equation
 * @param   B[in]       Second coefficient of equation
 *
 * @return              Solutions of equations
 */
static inline __attribute__((__always_inline__, __gnu_inline__))
float32x4_t solve_linear(float32x4_t A, float32x4_t B)
{
    /* ...mask out too small denominators */
    uint32x4_t      M = vcageq_f32(A, vmovq_n_f32(0.001f));

    /* ...solve linear equation a*z = -b */
    float32x4_t     Z = vdivq_f32(B, vnegq_f32(A));

    /* ...apply the mask to solutions */
    return vreinterpretq_f32_u32(vandq_u32(M, vreinterpretq_u32_f32(Z)));
}

/**
 * @brief   Solve quadratic equations A*z^2 + 2*B*z + C = 0. Points with negative
 *          discriminant are solved as z=0
 *
 * @param   A[in]       First coefficient of equation
 * @param   B[in]       Second coefficient of equation
 * @param   C[in]       Third coefficient of equation
 *
 * @return              Solutions of equations
 */
static inline __attribute__((__always_inline__, __gnu_inline__))
float32x4_t solve_quadratic(float32x4_t A, float32x4_t B, float32x4_t C)
{
    /* ...find discriminant of quadratic equation A*z^2 + 2*B*z + C = 0: 4*(B^2-A*C) */
    float32x4_t D = vmlsq_f32(vmulq_f32(B, B), A, C);

    /* ...get positive discriminants mask */
    uint32x4_t  M = vcgeq_f32(D, vmovq_n_f32(0.0f));

    /* ...get solutions of equations */
    float32x4_t Z0 = vdivq_f32(vsubq_f32(vsqrtq_f32(D), B), A);

#ifdef HIGH_ACCURACY
    /* ...process the case when quadratic surface degrades to plane */
    TRACE(0, _b("A=%e,%e,%e,%e, B=%e,%e,%e,%e, C=%e,%e,%e,%e"), __float32x4_p(A), __float32x4_p(B), __float32x4_p(C));

    float32x4_t E = vmlaq_f32(C, Z0, vmlaq_f32(vmulq_n_f32(B, 2.0f), A, Z0));

    float32x4_t Z1 = vdivq_f32(vnegq_f32(C), vmulq_n_f32(B, 2.0f));

    float32x4_t E1 = vmlaq_f32(C, Z1, vmlaq_f32(vmulq_n_f32(B, 2.0f), A, Z1));
    //E = vaddq_f32(vaddq_f32(vmulq_f32(vmulq_f32(Z0, Z0), A), vmulq_f32(B, Z0)), C);

    TRACE(0, _b("E=%e,%e,%e,%e, E1=%e,%e,%e,%e"), __float32x4_p(E), __float32x4_p(E1));

    Z0 = vreinterpretq_f32_u32(vandq_u32(M, vreinterpretq_u32_f32(Z0)));
    Z1 = vreinterpretq_f32_u32(vandq_u32(vcageq_f32(B, vmovq_n_f32(0.0005f)), vreinterpretq_u32_f32(Z1)));

    Z0 = vbslq_f32(vcaltq_f32(E, E1), Z0, Z1);

    /* ...mask out imaginary (bad) roots */
    return Z0;
#else
    return vreinterpretq_f32_u32(vandq_u32(M, vreinterpretq_u32_f32(Z0)));
#endif
}

/**
 * @brief Curves smoothing function
 *
 * @param zeta0[in]         First curve values
 * @param zeta1[in]         Second curve values
 * @param radius[in]        Smoothing region radius
 * @return                  Smoothed curve values
 */
static inline __attribute__((__always_inline__, __gnu_inline__))
float32x4_t smooth_curves(float32x4_t zeta0, float32x4_t zeta1, float32_t radius)
{
    float32x4_t dz = vsubq_f32(zeta0, zeta1);
    float32_t   A = 0.25f / radius;
    float32x4_t R = vmovq_n_f32(radius);

    /* ...test for approximation within the smoothing region */
    float32x4_t q0 = vaddq_f32(R, dz);
    float32x4_t q1 = vsubq_f32(R, dz);
    float32x4_t q2 = vmlsq_n_f32(zeta0, vmulq_f32(q0, q0), A);
    float32x4_t q3 = vmlsq_n_f32(zeta1, vmulq_f32(q1, q1), A);
    float32x4_t Q0 = vbslq_f32(vcleq_f32(dz, vmovq_n_f32(0.0f)), q2, q3);

    /* ...drop the candidates that have negative zeta value, select the candidates out of smoothing region */
    uint32x4_t  r0 = vcleq_f32(zeta0, vmovq_n_f32(0.0f));
    uint32x4_t  r1 = vcleq_f32(zeta1, vmovq_n_f32(0.0f));
    uint32x4_t  r2 = vcleq_f32(R, dz);
    uint32x4_t  r3 = vcleq_f32(dz, vnegq_f32(R));
    uint32x4_t  R0 = vorrq_u32(r0, vbicq_u32(r2, r1));
    uint32x4_t  R1 = vorrq_u32(r1, vbicq_u32(r3, r0));

    /* ...drop the points with negative zeta0 or which are out of smoothing region and lie on zeta1 */
    float32x4_t Q1 = vbslq_f32(R0, zeta1, Q0);
    float32x4_t Q2 = vbslq_f32(R1, zeta0, Q1);

    return Q2;
}

/**
 * @brief Get intersection with a paraboloid defined by equation (A*x)^2 + (B*y)^2 - C*z = 1
 *
 * @param P[in]     Input points in de-interleaved order:
 *                  [0] = {P[3].x,P[2].x,P[1].x,P[0].x}
 *                  [1] = {P[3].y,P[2].y,P[1].x,P[0].y}
 *                  [2] = {P[3].z,P[2].z,P[1].x,P[0].z}
 * @param b_x[in]   Free term of linear equation (A*W.x) for X pre-multiplied by A: A*(P.x*zeta + W.x)
 * @param b_y[in]   Free term of linear equation (B*W.y) for Y pre-multiplied by B: B*(P.y*zeta + W.y)
 * @param b_z[in]   Free term of linear equation (C*W.z) for Z pre-multiplied by C: C*(P.z*zeta + W.z)
 * @param A[in]     First coefficient of cone equation
 * @param B[in]     Second coefficient of cone equation
 * @param C[in]     Third coefficient of cone equation
 *
 * @return          Intersection points zetas (zero if no intersection exists)
 */
static inline __attribute__((__always_inline__, __gnu_inline__))
float32x4_t solve_paraboloid(float32x4x3_t P, float32x4_t b_x, float32x4_t b_y, float32x4_t b_z, float32_t A, float32_t B, float32_t C)
{
    float32x4_t a_x = vmulq_n_f32(P.val[0], A);
    float32x4_t a_y = vmulq_n_f32(P.val[1], B);
    float32x4_t a_z = vmulq_n_f32(P.val[2], C);

    /* ...build-up coefficients of quadratic equation a*z^2 + 2*b*z + c = 0 */
    float32x4_t a = vmlaq_f32(vmulq_f32(a_x, a_x), a_y, a_y);
    float32x4_t b = vmlsq_n_f32(vmlaq_f32(vmulq_f32(a_x, b_x), a_y, b_y), a_z, 0.5f);
    float32x4_t c = vsubq_f32(vmlaq_f32(vmulq_f32(b_x, b_x), b_y, b_y), b_z);

    return solve_quadratic(a, b, c);
}

/**
 * @brief   Ray-tracing function for elliptic paraboloid bowl given by equation
 *          (A*x)^2 + (B*y)^2 = C*z + 1
 *
 * @param   gen[in]         Mesh generator
 * @param   v[in,out]       Array of points (input: U*{u,v,1}, output: {x,y,z})
 * @param   n[in]           Number of points in an array
 */
static void mesh_sv_parabolic_bowl_tracer(mesh_gen_t *gen, float32_t (*v)[3], int n)
{
    /* ...additive term - virtual camera position */
    float32x4_t     w_x = vmovq_n_f32(gen->W[0]);
    float32x4_t     w_y = vmovq_n_f32(gen->W[1]);
    float32x4_t     w_z = vmovq_n_f32(gen->W[2]);

    /* ...parabolic mesh parameters */
    float32_t       invRx = gen->invRx;
    float32_t       invRy = gen->invRy;
    float32_t       steep = gen->steep;
    float32_t       smooth = gen->smooth;

    /* ...quadratic equation coefficients */
    float32x4_t     b_x = vmovq_n_f32(gen->B[0]);
    float32x4_t     b_y = vmovq_n_f32(gen->B[1]);
    float32x4_t     b_z = vmovq_n_f32(gen->B[2]);
    int             i;

    /* ...process 4 points at once */
    for (i = 0; i < n; i += 4)
    {
        float32x4_t     Z, Z0;

        /* ...load 4 points:
         * [0] = {X0, X1, X2, X3}
         * [1] = {Y0, Y1, Y2, Y3}
         * [2] = {Z0, Z1, Z2, Z3}
         */
        float32x4x3_t   P = vld3q_f32(*v);

        /* ...get instersection with ground-plane: P.z * Z + Wz = 0 */
        Z = solve_linear(P.val[2], w_z);

        /* ...find intersection with paraboloid */
        Z0 = solve_paraboloid(P, b_x, b_y, b_z, invRx, invRy, steep);

        /* ...smooth the curves */
        Z = smooth_curves(Z, Z0, smooth);

        /* ...calculate the point in world coordinates: W + P * Z */
        P.val[0] = vmlaq_f32(w_x, P.val[0], Z);
        P.val[1] = vmlaq_f32(w_y, P.val[1], Z);
        P.val[2] = vmlaq_f32(w_z, P.val[2], Z);

        /* ...store all points back */
        vst3q_f32(*v, P);

        /* ...advance array pointer */
        v += 4;
    }
}

/*******************************************************************************
 * Vertex encoding
 ******************************************************************************/

/**
 * @brief   Create two triangles from the adjacent point-pairs
 *
 * @param   v[in, out]      Mesh VBO pointer
 * @param   b[in]           Triangles forming buffer
 * @param   B23[in]         Last two points ({2},{3}) in interleaved order
 */
static inline __attribute__((__always_inline__, __gnu_inline__))
void mesh_tri_encode(mesh_vertex_t **v, mesh_vertex_t b[2], float32x4x3_t B23)
{
    float32x4x3_t   B01;

    /* ...load last two points from triangles forming buffer:
     * [0]: X0:V0:X1:V1
     * [1]: Y0:Q0:Y1:Q1
     * [2]: U0:q0:U1:q1
     */
    B01 = vld3q_f32(b[0]);

    /* ...make a triangle of points {0},{1},{2} and {2},{1},{3}; place points {0},{1} first
     * [0]: X0:V0:X1:V1
     * [1]: Y0:Q0:Y1:Q1
     * [2]: U0:q0:U1:q1
     */
    vst3q_f32(**v, B01);
    *v += 2;

    /* ...next two points to store are {2}, {2}:
     * [0]: X2:V2:X2:V2
     * [1]: Y2:Q2:Y2:Q2
     * [2]: U2:q2:U2:q2
     */
    float32x4x3_t   B22;
    B22.val[0] = vcombine_f32(vget_low_f32(B23.val[0]), vget_low_f32(B23.val[0]));
    B22.val[1] = vcombine_f32(vget_low_f32(B23.val[1]), vget_low_f32(B23.val[1]));
    B22.val[2] = vcombine_f32(vget_low_f32(B23.val[2]), vget_low_f32(B23.val[2]));
    vst3q_f32(**v, B22);
    *v += 2;

    /* ...next two pointsa are {1},{3}:
     * [0]: X1:V1:X3:V3
     * [1]: Y1:Q1:Y3:Q3
     * [2]: U1:q1:U3:q3
     */
    float32x4x3_t   B13;
    B13.val[0] = vcombine_f32(vget_high_f32(B01.val[0]), vget_high_f32(B23.val[0]));
    B13.val[1] = vcombine_f32(vget_high_f32(B01.val[1]), vget_high_f32(B23.val[1]));
    B13.val[2] = vcombine_f32(vget_high_f32(B01.val[2]), vget_high_f32(B23.val[2]));
    vst3q_f32(**v, B13);
    *v += 2;
}

/**
 * @brief   Fish-eye distortion of 3D-points mapped into camera viewing space
 *
 * @param   gen[in]         Mesh generator
 * @param   k[in]           Index of the camera
 * @param   v[in]           Array of the 3D-points in world coordinate system
 * @param   xyz[out]        Scratch storage for the 3D-points in camera coordinate system
 * @param   q[in]           Array of the points weights for alpha-plane / color-correction
 * @param   n[in]           Number of points to transform
 * @param   uv[out]         Array of 2D camera-sensor coordinates
 * @param   yuv[out]        Lens-shading correction values
 */
static void mesh_sv_project(mesh_gen_t *gen, int k, float32_t (*v)[3], float32_t (*xyz)[3], float32_t (*q)[2], int n, float32_t (*uv)[2])
{
    camera_data_t  *camera = &gen->camera[k];

#ifdef  BUILD_NATIVE
    /* ...dump 3D-points into VBO using camera index as a color discriminator */
    gen->dbg ? mesh_dbg_dump_xyz(gen->dbg, v, q, n, k) : 0;
#endif

    /* ...transform points into camera space */
    map_world_to_cam(v, camera->T, camera->R, n, xyz);

    /* ...apply fish-eye distortion */
    distort_kannala(xyz, uv, camera->params, n);

#ifdef  BUILD_NATIVE
    /* ...dump 3D-points in camera space */
    gen->dbg ? mesh_dbg_dump_cam(gen->dbg, xyz, q, n, k) : 0;

    /* ...dump sensor coordinates */
    gen->dbg ? mesh_dbg_dump_uv(gen->dbg, uv, n, k) : 0;
#endif
}

/*******************************************************************************
 * Single-camera view mesh generation
 ******************************************************************************/

/**
 * @brief   Single-camera view ray-tracing function (intersection with ground-plane)
 *
 * @param   gen[in]         Mesh generator
 * @param   v[in,out]       Array of points (input: U*{u,v,1}, output: {x,y,z})
 * @param   n[in]           Number of points in an array
 */
static void mesh_scv_tracer(mesh_gen_t *gen, float32_t (*v)[3], int n, float32_t Z)
{
    float32x4_t     w_x = vmovq_n_f32(gen->W[0]);
    float32x4_t     w_y = vmovq_n_f32(gen->W[1]);
    float32x4_t     w_z = vmovq_n_f32(gen->W[2] - Z);
    float32x4_t     Z0 = vmovq_n_f32(5000.0f);
    float32x4_t     DS = vmovq_n_f32(100.0f);
    float32_t       smooth = 1000.0f;
    int             i;

    /* ...process 4 points at once */
    for (i = 0; i < n; i += 4)
    {
        float32x4x3_t       P;
        float32x4_t         Z;
        float32x4_t         DS;

        /* ...load 4 points and get intersection with ground-plane */
        P = vld3q_f32(*v);

        /* ...get intersection with ground plane */
        Z = solve_linear(P.val[2], w_z);

        /* ...smooth curve with a screen located at specified distance (hardcoded) */
        Z = smooth_curves(Z, Z0, smooth);

        /* ...calculate the point in world coordinates: W + P * Z */
        P.val[0] = vmlaq_f32(w_x, P.val[0], Z);
        P.val[1] = vmlaq_f32(w_y, P.val[1], Z);
        P.val[2] = vmlaq_f32(w_z, P.val[2], Z);

        /* ...write points into output buffer */
        vst3q_f32(*v, P);
        v += 4;
    }
}

/**
 * @brief   Distortion of 3D-points mapped into camera viewing space for SCV
 *
 * @param   gen[in]         Mesh generator data
 * @param   v[in]           Array of the 3D-points in world coordinate system
 * @param   xyz[out]        Scratch storage for the 3D-points in camera coordinate system
 * @param   n[in]           Number of points to transform
 * @param   uv[out]         Array of 2D camera-sensor coordinates
 */
static void mesh_scv_project(mesh_gen_t *gen, float32_t (*v)[3], float32_t (*xyz)[3], int n, float32_t (*uv)[2])
{
    camera_data_t  *camera = &gen->camera[gen->camera_id];

#ifdef  BUILD_NATIVE
    /* ...dump 3D-points in world coordinate system */
    (gen->dbg ? scv_dbg_dump_xyz(gen->dbg, v, n) : 0);
#endif

    /* ...map world to camera */
    map_world_to_cam(v, camera->T, camera->R, n, xyz);

    /* ...apply fish-eye distortion */
    distort_kannala(xyz, uv, camera->params, n);

#ifdef  BUILD_NATIVE
    /* ...dump 2D-points in sensor-space using 3D-coordinates as a color discriminator */
    (gen->dbg ? scv_dbg_dump_uv(gen->dbg, uv, n) : 0);
#endif
}

int32_t mesh_gen_w2c(camera_data_t *cam_data, const float32_t _xyz[3], float32_t uv[2])
{
    if (cam_data->T[0] == 0.f || cam_data->T[2] == 0.f)
    {
        return -1;
    }
    float32_t tmp[8][3] = {0};
    float32_t xyz[8][3] = {0};
    float32_t out[8][2] = {0};

    xyz[0][0] = _xyz[0];
    xyz[0][1] = _xyz[1];
    xyz[0][2] = _xyz[2];

        /* ...map world to camera */
    map_world_to_cam(xyz, cam_data->T, cam_data->R, 1, tmp);

    /* ...apply fish-eye distortion */
    distort_kannala(tmp, out, cam_data->params, 1);

    uv[0] = out[0][0];
    uv[1] = out[0][1];

    return 0;
}

/**
 * @brief   Convert World x,y,z coordinates to raw image x,y cordinates for specific camera
 *
 * @param   cam_indx[in]        Camera ID (i.e. front,rear,left,right)
 * @param   world_xyz[in]       Array of 3D-coordinates of the points in world coordinate system
 * @param   raw_coords[out]     Array of 2D-coordinates of screen points (in) / sensor coordinates (out)
 * @param   returns 0 Success, -1 failure(invalid cam)
 */
int32_t mesh_gen_w2c_camera(uint32_t cam_indx, const float32_t world_xyz[3], float32_t raw_coords[2])
{
    camera_data_t *cam_data = &vm_camera_data[cam_indx];
    if (cam_data->T[0] == 0.f || cam_data->T[2] == 0.f)
    {
        ME_Debugger_F_Printf_v("cam_data->T is not initialized \n");
        return -1;
    }
    ME_Debugger_F_Printf_v("mesh_gen_w2c_camera():cam_indx=%u,world_xyz=%f,%f,%f\n",cam_indx,world_xyz[0],world_xyz[1],world_xyz[2]);
    return mesh_gen_w2c(cam_data, world_xyz, raw_coords);
}

/**
 * @brief   Calculate sensor coordinates for distorted SCV
 *
 * @param   gen[in]             Mesh generator
 * @param   uv[in, out]         Array of 2D-coordinates of screen points (in) / sensor coordinates (out)
 * @param   v[out]              Array of 3D-coordinates of the points in world coordinate system
 * @param   n[in]               Number of points in array
 */
static void mesh_scv_calc_uv(mesh_gen_t *gen, float32_t (*uv)[2], float32_t (*v)[3], int n, float32_t touch_x, float32_t touch_y
    , uint32_t zoom, float32_t scale)
{
    if (zoom)
    {
        float32_t offset[2] = {touch_x*(1 - scale),touch_y*(1 - scale)};
        vcamera_back_project_scale(&gen->vcam, uv, v, n, scale, offset);
    }
    else
    {
        vcamera_back_project(&gen->vcam, uv, v, n);
    }


    /* ...find intersection with ground */
    if (1) mesh_scv_tracer(gen, v, n, 0);

    /* ...project points in world into physical camera sensor space */
    mesh_scv_project(gen, v, v, n, uv);
}

static void mesh_gen_scv_prepare(vcamera_data_t *vcam, camera_data_t *camera, cfg_scv_mesh_t *scv, vehicle_state_t *vehicle, float32_t *U, float32_t *W);

static void get_zoom_point(const cfg_scv_mesh_t* scv, const vehicle_state_t *vehicle, const int32_t* dst, float32_t* point_x, float32_t* point_y)
{
    int32_t     x0 = dst[0], y0 = dst[1], x1 = dst[2], y1 = dst[3];

    if (scv->zoom_point[0] == 0 && scv->zoom_point[1] == 0)
    {
        float32_t touch_x = vehicle->mouse_zoom_x;
        float32_t touch_y = vehicle->mouse_zoom_y;
        point_x[0] = (touch_x - x0) / (x1 - x0) * 2.0f - 1.0f;
        point_y[0] = (touch_y - y0) / (y1 - y0) * 2.0f - 1.0f;
    }
    else
    {
        point_x[0] = scv->zoom_point[0];
        point_y[0] = scv->zoom_point[1];
    }
}

void scv_display2cam(mesh_gen_t *gen, cfg_scv_mesh_t* scv, vehicle_state_t *vehicle, float32_t uv[2], float32_t Z, float32_t v[3], const int32_t* dst)
{
    mesh_gen_t copy = *gen;
    gen = &copy;

    mesh_gen_scv_prepare(&gen->vcam, &gen->camera[gen->camera_id], scv, vehicle, gen->U, gen->W);
    
    float32_t uv_dup[4][2] = {{uv[0], uv[1]}, {uv[0], uv[1]}, {uv[0], uv[1]}, {uv[0], uv[1]}};
    float32_t v_dup[4][3] = {{v[0], v[1], v[2]}, {v[0], v[1], v[2]}, {v[0], v[1], v[2]}, {v[0], v[1], v[2]}};

    float32_t touch_x = 0.f;
    float32_t touch_y = 0.f;
    float32_t scale = scv->zoom;

    if (dst && scale > 0)
    {
        get_zoom_point(scv, vehicle, dst, &touch_x, &touch_y);
    }

    if (scale == 0.f || dst == NULL)
        vcamera_back_project(&gen->vcam, uv_dup, v_dup, 4);
    else
    {
        float32_t offset[2] = {touch_x*(1 - scale),touch_y*(1 - scale)};
        vcamera_back_project_scale(&gen->vcam, uv_dup, v_dup, 4, scale, offset);
    }
    /* ...find intersection with Z plane */
    if (1) mesh_scv_tracer(gen, v_dup, 4, Z);

    /* ...project points in world into physical camera sensor space */
    mesh_scv_project(gen, v_dup, v_dup, 4, uv_dup);
    uv[0] = uv_dup[0][0];
    uv[1] = uv_dup[0][1];
}


/**
 * @brief   Encode strip into mesh VBO
 *
 * @param   gen[in]         Mesh generator
 * @param   x0[in]          Strip origin, X-coordinate
 * @param   y0[in]          Strip origin, Y-coordinate
 * @param   dx[in]          Quad width
 * @param   dy[in]          Quad height
 * @param   uv0[in]         Sensor-coordinates array (upper row)
 * @param   uv1[in]         Sensor-coordinates array (lower row)
 * @param   n[in]           Number of points in a row
 */
static void mesh_scv_encode(mesh_gen_t *gen, float32_t x0, float32_t y0, float32_t dx, float32_t dy, float32_t (*uv0)[2], float32_t (*uv1)[2], int n)
{
    mesh_vbo_t     *vbo = gen->current;
    mesh_vertex_t  *v;
    int             i;

    /* ...reserve place for 2 * (n - 1) triangles, 3 points each */
    if ((v = mesh_vbo_add(vbo, (n - 1) * 6)) == NULL)
    {
        TRACE(ERROR, _x("failed to reserve %u vertices"), (n - 1) * 6);
        return;
    }

    float32x2x2_t   XY;
    XY.val[0] = __mk_float32x2(x0, x0);
    XY.val[1] = __mk_float32x2(y0, y0 + dy);

    float32x2_t     SX = vdup_n_f32(dx);

    mesh_vertex_t   b[2];

    float32x2x2_t   Q0;
    Q0.val[0] = vdup_n_f32(100.0f);
    Q0.val[1] = vdup_n_f32(1.0f);

    /* ...process all vertices (we always have pairs of points) */
    for (i = 0; i < n; i++)
    {
        /* ...load sensor coordinates: [0]: U0:V0, [1]: U1:V1 */
        float32x2_t     t0 = vld1_f32(*uv0);
        uv0++;

        float32x2_t     t1 = vld1_f32(*uv1);
        uv1++;

        /* ...reorder points: [0]: U0:U1, [1]:V0:V1 */
        float32x2x2_t   T;
        T.val[0] = vtrn1_f32(t0, t1);
        T.val[1] = vtrn2_f32(t0, t1);

        /* ...create two vertices in interleaved order:
         * [0]: X0:V0:X1:V1
         * [1]: Y0:Q0:Y1:Q1
         * [2]: U0:q0:U1:q1
         */
        float32x4x3_t   B;
        B.val[0] = vcombine_f32(vtrn1_f32(XY.val[0], T.val[1]), vtrn2_f32(XY.val[0], T.val[1]));
        B.val[1] = vcombine_f32(vtrn1_f32(XY.val[1], Q0.val[0]), vtrn2_f32(XY.val[1], Q0.val[0]));
        B.val[2] = vcombine_f32(vtrn1_f32(T.val[0], Q0.val[1]), vtrn2_f32(T.val[0], Q0.val[1]));

        /* ...advance display coordinates of the points (X-coordinate only) */
        XY.val[0] = vadd_f32(XY.val[0], SX);

        /* ...create two triangles if possible */
        (i > 0 ? mesh_tri_encode(&v, b, B) : 0);

        /* ...save last point-pair in triangles forming buffer */
        vst3q_f32(b[0], B);
    }
}

/**
 * @brief   Create single-camera mesh
 *
 * @param   gen[in]         Mesh generator
 * @param   N[in]           Lattice horizontal size
 * @param   M[in]           Lattice vertical size
 *
 * @return                  Zero on success, negative on failure
 */
static int mesh_create_single_dist(mesh_gen_t *gen, const vehicle_state_t* vehicle, const int32_t N, const int32_t M, int* dst, cfg_scv_mesh_t* scv)
{
    u32             t0 = __get_time_usec();

    uint32_t zoom_flag = 0;
    float32_t touch_x, touch_y;

    float32_t scale = scv->zoom;

    if (dst && scale > 0)
    {
        get_zoom_point(scv, vehicle, dst, &touch_x, &touch_y);
        zoom_flag = 1;
    }

    /* ...interim storage for mesh 3D-points in single row (allocate on stack) */
    float32_t       V0[(N + 3) * 3] __attribute__((aligned(16)));
    float32_t       V1[(N + 3) * 3] __attribute__((aligned(16)));
    float32_t      *VV[2] = { V0, V1 };

    /* ...sensor coordinates */
    float32_t       UV0[(N + 3) * 2] __attribute__((aligned(16)));
    float32_t       UV1[(N + 3) * 2] __attribute__((aligned(16)));
    float32_t      *UV[2] = { UV0, UV1 };

    float32_t       dx = (2.0f / (float32_t)(N - 1));
    float32_t       dy = (2.0f / (float32_t)(M - 1));

    u32             T0 = 0, T1 = 0, T2 = 0;

    int             i, j, bank;

    /* ...create vertex lattice */
    for (bank = 0, j = 0; j < M; bank ^= 1, j++)
    {
        float32_t     (*v0)[3] = (float32_t (*) [3])VV[bank];
        float32_t     (*v1)[3] = (float32_t (*) [3])VV[bank ^ 1];

        float32_t     (*uv0)[2] = (float32_t (*) [2])UV[bank];
        float32_t     (*uv1)[2] = (float32_t (*) [2])UV[bank ^ 1];

        float32x4_t     X = vmlaq_n_f32(vmovq_n_f32(-1.0f), __mk_float32x4(0.0f, 1.0f, 2.0f, 3.0f), dx);
        float32x4_t     Y = vmovq_n_f32((float32_t)j * dy - 1.0f);

        u32 _t0 = __get_time_usec();

        /* ...prepare single row of 2D-coordinates in sensor space */
        for (i = 0; i < N; i += 4)
        {
            float32x4x2_t   Q;

            Q.val[0] = X;
            Q.val[1] = Y;

            /* ...store screen coordinates in temporary array */
            vst2q_f32(uv0[i], Q);

            /* ...advance X-coordinates */
            X = vaddq_f32(X, vmovq_n_f32(4.0f * dx));
        }

        u32 _t1 = __get_time_usec();

        /* ...produce 3D-points in world-coordinates */
        mesh_scv_calc_uv(gen, uv0, v0, N, touch_x, touch_y, zoom_flag, scale);

        u32 _t2 = __get_time_usec();

        /* ...encode a strip if possible */
        if (j != 0)
        {
            mesh_scv_encode(gen, -1.0f, (float32_t)(j - 1) * dy - 1.0f, dx, dy, uv1, uv0, N);
        }

        u32 _t3 = __get_time_usec();

        T0 += (_t1 - _t0), T1 += (_t2 - _t1), T2 += (_t3 - _t2);
    }

    u32             t1 = __get_time_usec();

    TRACE(INFO, _b("mesh-scv built: %u=(%u+%u+%u), [%d * %d]"), t1 - t0, T0, T1, T2, N, M);

    return 0;
}

/*******************************************************************************
 * Side-view mesh generator
 ******************************************************************************/

/**
 * @brief   Side-view ray-tracing function (intersection with ground-plane)
 *
 * @param   gen[in]         Mesh generator data
 * @param   v[in,out]       Array of points (input: U*{u,v,1}, output: {x,y,z})
 * @param   q[out]          Array of distance to the mask area boundary
 * @param   n[in]           Number of points in an array
 * @param   w[in]           Additive term of ray-tracing equation
 */
static void mesh_side_view_tracer(mesh_gen_t *gen, float32_t (*v)[3], float32_t (*q)[1], int n)
{
    float32x4_t     w_x = vmovq_n_f32(gen->W[0]);
    float32x4_t     w_y = vmovq_n_f32(gen->W[1]);
    float32x4_t     w_z = vmovq_n_f32(gen->W[2]);
    float32x4_t     Z0 = vmovq_n_f32(20000.0f);
    int             i;

    /* ...load mask region:
     * [0]: {Xmin, Xmax}
     * [1]: {Ymin, Ymax}
     */
    float32x2x2_t   S = vld2_f32(gen->mask);

    /* ...process 4 points at once */
    for (i = 0; i < n; i += 4)
    {
        float32x4x3_t       P;
        float32x4_t         Z;
        float32x4_t         DS;

        /* ...load 4 points and get intersection with ground-plane */
        P = vld3q_f32(*v);

        /* ...get intersection with ground plane */
        Z = solve_linear(P.val[2], w_z);

        /* ...limit value of Z in camera space to 20 meters */
        Z = smooth_curves(Z, Z0, 1000.0f);

        /* ...calculate the point in world coordinates: W + P * Z */
        P.val[0] = vmlaq_f32(w_x, P.val[0], Z);
        P.val[1] = vmlaq_f32(w_y, P.val[1], Z);
        P.val[2] = vmlaq_f32(w_z, P.val[2], Z);

        /* ...write points into output buffer */
        vst3q_f32(*v, P);
        v += 4;

        /* ...get distance from point */
        DS = vsubq_f32(vdupq_lane_f32(S.val[0], 1), P.val[0]);
        DS = vminq_f32(DS, vsubq_f32(P.val[0], vdupq_lane_f32(S.val[0], 0)));
        DS = vminq_f32(DS, vsubq_f32(vdupq_lane_f32(S.val[1], 1), P.val[1]));
        DS = vminq_f32(DS, vsubq_f32(P.val[1], vdupq_lane_f32(S.val[1], 0)));

        /* ...mask out discriminants with negative Z */
        //DS = vreinterpretq_f32_u32(vandq_u32(vcgtq_f32(Z, vmovq_n_f32(0.0f)), vreinterpretq_u32_f32(DS)));

        TRACE(0, _b("X=%f,%f,%f,%f, Y=%f,%f,%f,%f, DS=%f,%f,%f,%f"), __float32x4_p(P.val[0]), __float32x4_p(P.val[1]), __float32x4_p(DS));

        /* ...write distance values */
        vst1q_f32(*q, DS);
        q += 4;
    }
}

/**
 * @brief   Calculate UV-coordinates of the points {X,Y,1} on virtual camera screen
 */
static void mesh_side_view_calc_uv(mesh_gen_t *gen, float32_t (*v)[3], float32_t (*q)[1], float32_t (*uv)[2], int32_t n)
{
    /* ...back-project points from virtual camera sensor space */
    vcamera_back_project(&gen->vcam, uv, v, n);

    /* ...update XYZ world coordinates */
    mesh_side_view_tracer(gen, v, q, n);

    /* ...produce UV-sensor coordinates */
    mesh_scv_project(gen, v, v, n, uv);
}

/**
 * @brief   Encode strip into mesh VBO
 *
 * @param   gen[in]         Mesh generator
 * @param   x0[in]          Strip origin, X-coordinate
 * @param   y0[in]          Strip origin, Y-coordinate
 * @param   dx[in]          Quad width
 * @param   dy[in]          Quad height
 * @param   uv0[in]         Sensor-coordinates array, upper row
 * @param   uv1[in]         Sensor-coordinates array, lower row
 * @param   q0[in]          Points weights, upper row
 * @param   q1[in]          Points weights, lower row
 * @param   n[in]           Number of points-pairs in a strip
 */
static void mesh_side_view_encode(
    mesh_gen_t *gen,
    float32_t x0,
    float32_t y0,
    float32_t dx,
    float32_t dy,
    float32_t (*uv0)[2],
    float32_t (*uv1)[2],
    float32_t (*q0)[1],
    float32_t (*q1)[1],
    int32_t n)
{
    mesh_vbo_t     *vbo = gen->current;
    mesh_vertex_t  *v;
    int32_t         i;

    /* ...reserve place for 2 * (n - 1) triangles, 3 points each */
    if ((v = mesh_vbo_add(vbo, (n - 1) * 6)) == NULL)
    {
        TRACE(ERROR, _x("failed to reserve %u vertices"), (n - 1) * 6);
        return;
    }

    float32x2x2_t   XY;
    XY.val[0] = __mk_float32x2(x0, x0);
    XY.val[1] = __mk_float32x2(y0, y0 + dy);

    float32x2_t     SX = vdup_n_f32(dx);

    mesh_vertex_t   b[2];

    float32x2x2_t   Q;
    Q.val[0] = vdup_n_f32(0.0f);
    Q.val[1] = vdup_n_f32(1.0f);

    /* ...process all vertices (we always have pairs of points) */
    for (i = 0; i < n; i++)
    {
        /* ...load sensor coordinates: [0]: U0:V0, [1]: U1:V1 */
        float32x2_t     t0 = vld1_f32(*uv0);
        uv0++;

        float32x2_t     t1 = vld1_f32(*uv1);
        uv1++;

        /* ...reorder points: [0]: U0:U1, [1]:V0:V1 */
        float32x2x2_t   T;
        T.val[0] = vtrn1_f32(t0, t1);
        T.val[1] = vtrn2_f32(t0, t1);

        /* ...load points ratios: [0]: q0:q1, [1]:Q0:Q1 */
        Q.val[0] = __mk_float32x2((*q0++)[0], (*q1++)[0]);

        /* ...create two vertices in interleaved order:
         * [0]: X0:V0:X1:V1
         * [1]: Y0:Q0:Y1:Q1
         * [2]: U0:q0:U1:q1
         */
        float32x4x3_t   B;
        B.val[0] = vcombine_f32(vtrn1_f32(XY.val[0], T.val[1]), vtrn2_f32(XY.val[0], T.val[1]));
        B.val[1] = vcombine_f32(vtrn1_f32(XY.val[1], Q.val[0]), vtrn2_f32(XY.val[1], Q.val[0]));
        B.val[2] = vcombine_f32(vtrn1_f32(T.val[0], Q.val[1]), vtrn2_f32(T.val[0], Q.val[1]));

        TRACE(0, _b("X=%f,%f : Y=%f,%f, U=%f,%f, V=%f,%f, Q=%f,%f"), __float32x2_p(XY.val[0]), __float32x2_p(XY.val[1]), __float32x2_p(T.val[0]), __float32x2_p(T.val[1]), __float32x2_p(Q.val[0]));

        /* ...advance display coordinates of the points (X-coordinate only) */
        XY.val[0] = vadd_f32(XY.val[0], SX);

        /* ...create two triangles if possible */
        (i > 0 ? mesh_tri_encode(&v, b, B) : 0);

        /* ...save last point-pair in triangles forming buffer */
        vst3q_f32(b[0], B);
    }
}

/**
 * @brief   Create side-view mesh for single camera
 *
 * @param   gen[in]     Mesh generator data
 * @param   N[in]       Mesh lattice horizontal dimension
 * @param   M[in]       Mesh lattice vertical dimension
 *
 * @return              Zero on success, negative on failure
 */
static int mesh_create_side_view(mesh_gen_t *gen, const int32_t N, const int32_t M)
{
    u32             t0 = __get_time_usec();

    /* ...interim storage for mesh 3D-points in single row (allocate on stack) */
    float32_t       V0[(N + 3) * 3] __attribute__((aligned(16)));
    float32_t       V1[(N + 3) * 3] __attribute__((aligned(16)));
    float32_t      *V[2] = { V0, V1 };

    /* ...sensor coordinates */
    float32_t       UV0[(N + 3) * 2] __attribute__((aligned(16)));
    float32_t       UV1[(N + 3) * 2] __attribute__((aligned(16)));
    float32_t      *UV[2] = { UV0, UV1 };

    /* ...weights values */
    float32_t       Q0[(N + 3) * 1] __attribute__((aligned(16)));
    float32_t       Q1[(N + 3) * 1] __attribute__((aligned(16)));
    float32_t      *Q[2] = { Q0, Q1 };

    /* ...calculate initial horizontal coordinate / increment */
    float32_t       dx = 2.0f / (float32_t)(N - 1);
    float32_t       dy = 2.0f / (float32_t)(M - 1);
    int             i, j, bank;

    /* ...create vertex lattice */
    for (bank = 0, j = 0; j < M; bank ^= 1, j++)
    {
        float32_t     (*v0)[3] = (float32_t (*) [3])V[bank];
        float32_t     (*v1)[3] = (float32_t (*) [3])V[bank ^ 1];

        float32_t     (*uv0)[2] = (float32_t (*) [2])UV[bank];
        float32_t     (*uv1)[2] = (float32_t (*) [2])UV[bank ^ 1];

        float32_t     (*q0)[1] = (float32_t (*) [1])Q[bank];
        float32_t     (*q1)[1] = (float32_t (*) [1])Q[bank ^ 1];

        float32x4_t     X = vmlaq_n_f32(vmovq_n_f32(-1.0f), __mk_float32x4(0, 1, 2, 3), dx);
        float32x4_t     Y = vmovq_n_f32((float32_t)j * dy - 1.0f);
        int             i;

        /* ...prepare single row of 2D-coordinates in sensor space */
        for (i = 0; i < N; i += 4)
        {
            float32x4x2_t   Q;

            Q.val[0] = X;
            Q.val[1] = Y;

            /* ...store screen coordinates in temporary array */
            vst2q_f32(uv0[i], Q);

            /* ...advance X-coordinates */
            X = vaddq_f32(X, vmovq_n_f32(4.0f * dx));
        }

        /* ...calculate sensor coordinates of the points */
        mesh_side_view_calc_uv(gen, v0, q0, uv0, N);

        /* ...encode a strip if possible */
        if (j != 0)
        {
            mesh_side_view_encode(gen, -1.0f, (float32_t)(j - 1) * dy - 1.0f, dx, dy, uv1, uv0, q1, q0, N);
        }
    }

    u32             t1 = __get_time_usec();

    TRACE(INFO, _b("mesh-sv built: %u"), t1 - t0);

    return 0;
}

/**
 * @brief   Prepare virtual camera projection matrix for mapping the points from
 *          camera coordinate system ({u, v, 1} * zeta) to world coordinate
 *          system ({x,y,z}): {x, y, z} = U * {u, v, 1} * zeta + W
 *
 * @param   fov[in]     Horizontal / vertical fields of view, degrees
 * @param   rot[in]     Rotation angles of virtual camera, degrees
 * @param   tr[in]      Translation vector of virtual camera
 * @param   U[out]      3x3 virtual camera rotation
 * @param   W[out]      Virtual camera translation vector
 */
static void mesh_prepare_vr_matrix(
    float32_t fov[2],
    float32_t rot[3],
    float32_t tr[3],
    float32_t U[3 * 3],
    float32_t W[3])
{
    float32_t       hfov2 = fov[0] * (float32_t)(M_PI / 180.0 * 0.5);
    float32_t       vfov2 = fov[1] * (float32_t)(M_PI / 180.0 * 0.5);

    __mat3x3        R;
    __mat3x3_rotation(R, (__vec3){ rot[0], -rot[1], rot[2] }, __MATH_ONE);

    /* ...camera-to-world transformation matrix */
    __mat3x3        S = {
        0.0f, 0.0f, 1.0f,
        -tanf(hfov2), 0.0f, 0.0f,
        0.0f, -tanf(vfov2), 0.0f,
    };

    /* ...create transformation matrix for virtual camera */
    __mat3x3_mul(S, R, U);

    /* ...save translation vector */
    memcpy(W, tr, sizeof(float32_t [3]));
}

/**
 * @brief   Prepare coordinates transformation matrix for top-view:
 *
 *          {x, y, 0} = U * {Xdisp, Ydisp, 1}
 *
 * @param   x0[in]          Top-left corner, X-coordinate, in pixels
 * @param   y0[in]          Top-left corner, Y-coordinate, in pixels
 * @param   x1[in]          Bottom-right corner, X-coordinate, in pixels
 * @param   y1[in]          Bottom-right corner, Y-coordinate, in pixels
 * @param   scale[in]       Vector of scales for axes, mm-per-pixels
 * @param   offset[in]      Vector of offsets car center, mm
 * @param   U[out]          2x3 transformation matrix
 */
static inline void mesh_prepare_tv_matrix(int32_t x0, int32_t y0, int32_t x1, int32_t y1, float32_t scale, float32_t offset[2], float32_t U[2 * 3])
{
    /* ...multiply rows by scalar */
    U[0] = 0.0f;
    U[1] = -scale * 0.5f * (y1 - y0);
    U[2] = offset[0];

    U[3] = -scale * 0.5f * (x1 - x0);
    U[4] = 0.0f;
    U[5] = offset[1];
}

/*******************************************************************************
 * Surround view mesh generation
 ******************************************************************************/

/**
 * @brief   Select camera region (single- or blend-region or shadow) basing on
 *          projection of 3D-point onto ground plane
 *
 * @param   X[in]       3D-point projection on ground plane - X coordinate
 * @param   Y[in]       3D-point projection on ground plane - Y coordinate
 * @param   S[in]       Shadow corner: [0]:{Xmin,Ymin}, [1]:{Xmax,Ymax}
 * @param   B0[in]      Blend-zones lower-lines coefficients
 * @param   B1[in]      Blend-zones upper-lines coefficients
 */
static inline __attribute__((__always_inline__))
uint16x4_t mesh_tv_select_region(float32x4_t X, float32x4_t Y, float32x2x2_t S, float32x4x3_t B0, float32x4x3_t B1)
{
    /* ...check if the point falls into shadow region: r0={Xmin <= Xi}, r1={Ymin <= Yi} */
    uint16x4_t  r0 = vmovn_u32(vcleq_f32(vdupq_lane_f32(S.val[0], 0), X));
    uint16x4_t  r1 = vmovn_u32(vcleq_f32(vdupq_lane_f32(S.val[0], 1), Y));

    /* ...r2={Xi <= Xmax}, r3={Yi <= Ymax} */
    uint16x4_t  r2 = vmovn_u32(vcleq_f32(X, vdupq_lane_f32(S.val[1], 0)));
    uint16x4_t  r3 = vmovn_u32(vcleq_f32(Y, vdupq_lane_f32(S.val[1], 1)));

    /* ...regions test conditions: {Xmax < Xi, Ymax < Yi, X < Xmin, Y < Ymin} */
    uint16x4_t  t0 = vtrn1_u16(r2, r3);     // {Xmax >= X0, Ymax >= Y0, Xmax >= X2, Ymax >= Y2}
    uint16x4_t  t1 = vtrn2_u16(r2, r3);     // {Xmax >= X1, Ymax >= Y1, Xmax >= X3, Ymax >= Y3}
    uint16x4_t  t2 = vtrn1_u16(r0, r1);     // {Xmin <= X0, Ymin <= Y0, Xmin <= X2, Ymin <= Y2}
    uint16x4_t  t3 = vtrn2_u16(r0, r1);     // {Xmin <= X1, Ymin <= Y1, Xmin <= X3, Ymin <= Y3}

    /* ...build region test masks for each point: {Xmax >= Xi, Ymax >= Yi, Xi >= Xmin, Yi >= Ymin} */
    uint16x4x4_t    T0;
    T0.val[0] = vreinterpret_u16_u32(vtrn1_u32(vreinterpret_u32_u16(t0), vreinterpret_u32_u16(t2)));
    T0.val[1] = vreinterpret_u16_u32(vtrn1_u32(vreinterpret_u32_u16(t1), vreinterpret_u32_u16(t3)));
    T0.val[2] = vreinterpret_u16_u32(vtrn2_u32(vreinterpret_u32_u16(t0), vreinterpret_u32_u16(t2)));
    T0.val[3] = vreinterpret_u16_u32(vtrn2_u32(vreinterpret_u32_u16(t1), vreinterpret_u32_u16(t3)));

    /* ...get positions with respect to all four "lower" lines (non-zero if below the line) */
    uint16x4x4_t    R0;
    R0.val[0] = vmovn_u32(vcleq_f32(vmlsq_laneq_f32(vmulq_laneq_f32(B0.val[1], Y, 0), B0.val[0], X, 0), B0.val[2]));
    R0.val[1] = vmovn_u32(vcleq_f32(vmlsq_laneq_f32(vmulq_laneq_f32(B0.val[1], Y, 1), B0.val[0], X, 1), B0.val[2]));
    R0.val[2] = vmovn_u32(vcleq_f32(vmlsq_laneq_f32(vmulq_laneq_f32(B0.val[1], Y, 2), B0.val[0], X, 2), B0.val[2]));
    R0.val[3] = vmovn_u32(vcleq_f32(vmlsq_laneq_f32(vmulq_laneq_f32(B0.val[1], Y, 3), B0.val[0], X, 3), B0.val[2]));

    /* ...and the positions with respect to all four "upper" lines (non-zero if below the line) */
    uint16x4x4_t    R1;
    R1.val[0] = vmovn_u32(vcleq_f32(vmlsq_laneq_f32(vmulq_laneq_f32(B1.val[1], Y, 0), B1.val[0], X, 0), B1.val[2]));
    R1.val[1] = vmovn_u32(vcleq_f32(vmlsq_laneq_f32(vmulq_laneq_f32(B1.val[1], Y, 1), B1.val[0], X, 1), B1.val[2]));
    R1.val[2] = vmovn_u32(vcleq_f32(vmlsq_laneq_f32(vmulq_laneq_f32(B1.val[1], Y, 2), B1.val[0], X, 2), B1.val[2]));
    R1.val[3] = vmovn_u32(vcleq_f32(vmlsq_laneq_f32(vmulq_laneq_f32(B1.val[1], Y, 3), B1.val[0], X, 3), B1.val[2]));

    /* ...determine if the point gets into extended camera region */
    uint16x4x4_t    R2;
    R2.val[0] = vbic_u16(vbic_u16(R1.val[0], vext_u16(R0.val[0], R0.val[0], 3)), T0.val[0]);
    R2.val[1] = vbic_u16(vbic_u16(R1.val[1], vext_u16(R0.val[1], R0.val[1], 3)), T0.val[1]);
    R2.val[2] = vbic_u16(vbic_u16(R1.val[2], vext_u16(R0.val[2], R0.val[2], 3)), T0.val[2]);
    R2.val[3] = vbic_u16(vbic_u16(R1.val[3], vext_u16(R0.val[3], R0.val[3], 3)), T0.val[3]);

    uint16x4_t      sel = __mk_uint16x4(1, 2, 4, 8);
    R2.val[0] = vbsl_u16(R2.val[0], sel, vmov_n_u16(0));
    R2.val[1] = vbsl_u16(R2.val[1], sel, vmov_n_u16(0));
    R2.val[2] = vbsl_u16(R2.val[2], sel, vmov_n_u16(0));
    R2.val[3] = vbsl_u16(R2.val[3], sel, vmov_n_u16(0));

    R2.val[0] = vorr_u16(R2.val[0], vext_u16(R2.val[0], R2.val[0], 2));
    R2.val[0] = vorr_u16(R2.val[0], vext_u16(R2.val[0], R2.val[0], 1));
    R2.val[1] = vorr_u16(R2.val[1], vext_u16(R2.val[1], R2.val[1], 2));
    R2.val[1] = vorr_u16(R2.val[1], vext_u16(R2.val[1], R2.val[1], 1));
    R2.val[2] = vorr_u16(R2.val[2], vext_u16(R2.val[2], R2.val[2], 2));
    R2.val[2] = vorr_u16(R2.val[2], vext_u16(R2.val[2], R2.val[2], 1));
    R2.val[3] = vorr_u16(R2.val[3], vext_u16(R2.val[3], R2.val[3], 2));
    R2.val[3] = vorr_u16(R2.val[3], vext_u16(R2.val[3], R2.val[3], 1));

    uint16x4_t      K = R2.val[0];
    K = vset_lane_u16(vget_lane_u16(R2.val[1], 0), K, 1);
    K = vset_lane_u16(vget_lane_u16(R2.val[2], 0), K, 2);
    K = vset_lane_u16(vget_lane_u16(R2.val[3], 0), K, 3);

    return K;
}

/**
 * @brief   Determine quad region mask
 *
 * @param   Q0[in]          Region mask of points 00,01
 * @param   Q1[in]          Region mask of points 10,11
 */
static inline __attribute__((__always_inline__))
int mesh_tv_select_regions(uint16_t *k0, uint16_t *k1)
{
    static const int map[16] = {
        [0x0] = -1,
        [0x1] = 0,
        [0x2] = 2,
        [0x3] = 1,
        [0x4] = 4,
        [0x5] = -1,
        [0x6] = 3,
        [0x7] = -1,
        [0x8] = 6,
        [0x9] = 7,
        [0xA] = -1,
        [0xB] = -1,
        [0xC] = 5,
        [0xD] = -1,
        [0xE] = -1,
        [0xF] = -1,
    };

    return map[(k0[0] | k0[1] | k1[0] | k1[1]) & 0xF];
}

/*
 * @brief   Calculate point ratios for a selected camera region (single-camera region)
 *          basing on the distance of 2D-projection point from lines bounding the region
 *
 * @param   X[in]           X-coordinates of the points
 * @param   Y[in]           Y-coordinates of the points
 * @param   Z[in]           Z-coordinates of the points
 * @param   k0[in]          Index of the blend-zone lower equation
 * @param   k1[in]          Index of the blend-zone upper equation
 * @param   B0[in]          Blend-zones lower lines equations
 * @param   B1[in]          Blend-zones upper lines equations
 * @param   Q0[out]         Points weights (first camera)
 * @param   Q1[out]         Points weights (second camera - not used)
 */
static inline __attribute__((__always_inline__))
void mesh_calc_ratios(
    float32x4_t X,
    float32x4_t Y,
    float32x4_t Z,
    const int k0,
    const int k1,
    float32x4x3_t B0,
    float32x4x3_t B1,
    float32x4x2_t *Q0,
    float32x4x2_t *Q1)
{
    float32x4_t     D0;
    D0 = vmlsq_laneq_f32(vmulq_laneq_f32(Y, B0.val[1], k0), X, B0.val[0], k0);
    D0 = vsubq_f32(D0, vdupq_laneq_f32(B0.val[2], k0));

    float32x4_t     D1;
    D1 = vmlsq_laneq_f32(vmulq_laneq_f32(Y, B1.val[1], k1), X, B1.val[0], k1);
    D1 = vsubq_f32(vdupq_laneq_f32(B1.val[2], k1), D1);

    float32x4_t     T0 = vmulq_f32(D1, D1);
    float32x4_t     T1 = vmlaq_f32(T0, D0, D0);
    float32x4_t     T2 = vdivq_f32(T0, T1);

    T2 = vbslq_f32(vcleq_f32(D0, vmovq_n_f32(0.0f)), vmovq_n_f32(0.0f), T2);
    T2 = vbslq_f32(vcleq_f32(D1, vmovq_n_f32(0.0f)), vmovq_n_f32(1.0f), T2);

    /* ...single-camera coefficient saving */
    Q0->val[0] = vmovq_n_f32(1.0f);
    Q0->val[1] = T2;

    *Q1 = *Q0;
}

/*
 * @brief   Calculate point ratios for a selected camera region (blend-camera region)
 *          basing on the distance of 2D-projection point from lines bounding the region
 *
 * @param   X[in]           X-coordinates of the points
 * @param   Y[in]           Y-coordinates of the points
 * @param   Z[in]           Z-coordinates of the points
 * @param   k0[in]          Index of the blend-zone lower equation
 * @param   k1[in]          Index of the blend-zone upper equation
 * @param   B0[in]          Blend-zones lower lines equations
 * @param   B1[in]          Blend-zones upper lines equations
 * @param   Q0[out]         Points weights (first camera)
 * @param   Q1[out]         Points weights (second camera)
 */
static inline __attribute__((__always_inline__))
void mesh_calc_blend_ratios(
    float32x4_t X,
    float32x4_t Y,
    float32x4_t Z,
    const int k,
    float32x4x3_t B0,
    float32x4x3_t B1,
    float32x4x2_t *Q0,
    float32x4x2_t *Q1)
{
    /* ...distance to lower line (positive) */
    float32x4_t     D0;
    D0 = vmlsq_laneq_f32(vmulq_laneq_f32(Y, B0.val[1], k), X, B0.val[0], k);
    D0 = vsubq_f32(D0, vdupq_laneq_f32(B0.val[2], k));

    /* ...distance to upper line (positive) */
    float32x4_t     D1;
    D1 = vmlsq_laneq_f32(vmulq_laneq_f32(Y, B1.val[1], k), X, B1.val[0], k);
    D1 = vsubq_f32(vdupq_laneq_f32(B1.val[2], k), D1);

    float32x4_t     T0 = vmulq_f32(D1, D1);
    float32x4_t     T1 = vmlaq_f32(T0, D0, D0);
    float32x4_t     T2 = vdivq_f32(T0, T1);

    /* ...blend-ratio coefficient */
    T2 = vbslq_f32(vcleq_f32(D1, vmovq_n_f32(0.0f)), vmovq_n_f32(0.0f), T2);
    T2 = vbslq_f32(vcleq_f32(D0, vmovq_n_f32(0.0f)), vmovq_n_f32(1.0f), T2);

    Q0->val[0] = T2;
    Q0->val[1] = vmovq_n_f32(0.0f);
    Q1->val[0] = vsubq_f32(vmovq_n_f32(1.0f), T2);
    Q1->val[1] = vmovq_n_f32(1.0f);
}

/**
 * @brief   Calculate point ratios for a selected camera region (single- or blend-region)
 *          basing on the distance of 2D-projection point from lines bounding the region
 *
 * @param   T0[in]          Upper two points in the quad in interleaved order:
 *                          [0]: {X00, X01}
 *                          [1]: {Y00, Y01}
 *                          [2]: {Z00, Z01}
 * @param   T1[in]          Lower two points in the quad in interleaved order:
 *                          [0]: {X10, X11}
 *                          [1]: {Y10, Y11}
 *                          [2]: {Z10, Z11}
 * @param   S[in]           Shadow region:
 *                          [0]: {Xmin,Ymin}
 *                          [1]: {Xmax,Ymax}
 * @param   B0[in]          Blend-zones lower lines coefficients
 * @param   B1[in]          Blend-zones upper lines coefficients
 * @param   k[in]           Blend-zone index
 * @param   Q0[out]         Points weights for lower region:
 *                          [0]: {q00,q01,q10,q11}
 *                          [1]: {Q00,Q01,Q10,Q11}
 * @param   Q1[out]         Points weights for upper region:
 *                          [0]: {q00,q01,q10,q11}
 *                          [1]: {Q00,Q01,Q10,Q11}
 */
static inline __attribute__((__always_inline__))
void mesh_calc_quad_ratios(
    float32x2x3_t T0,
    float32x2x3_t T1,
    float32x2x2_t S,
    float32x4x3_t B0,
    float32x4x3_t B1,
    int k,
    float32x4x2_t *Q0,
    float32x4x2_t *Q1)
{
    float32x4_t     X = vcombine_f32(T0.val[0], T1.val[0]);
    float32x4_t     Y = vcombine_f32(T0.val[1], T1.val[1]);
    float32x4_t     Z = vcombine_f32(T0.val[2], T1.val[2]);

    TRACE(0, _b("X=%f:%f:%f:%f, Y=%f:%f:%f:%f, k=%d"), __float32x4_p(X), __float32x4_p(Y), k);

    /* ...calculate distance to lower / higher bounds of the region */
    switch (k)
    {
    case 0:
        /* ...front camera region */
        mesh_calc_ratios(X, Y, Z, 3, 0, B1, B0, Q0, Q1);
        break;

    case 1:
        /* ...front-left camera region */
        mesh_calc_blend_ratios(X, Y, Z, 0, B0, B1, Q0, Q1);
        break;

    case 2:
        /* ...left camera region */
        mesh_calc_ratios(X, Y, Z, 0, 1, B1, B0, Q0, Q1);
        break;

    case 3:
        /* ...left-rear blend-region */
        mesh_calc_blend_ratios(X, Y, Z, 1, B0, B1, Q0, Q1);
        break;

    case 4:
        /* ...rear camera region */
        mesh_calc_ratios(X, Y, Z, 1, 2, B1, B0, Q0, Q1);
        break;

    case 5:
        /* ...rear-right blend-region */
        mesh_calc_blend_ratios(X, Y, Z, 2, B0, B1, Q0, Q1);
        break;

    case 6:
        /* ...right camera region */
        mesh_calc_ratios(X, Y, Z, 2, 3, B1, B0, Q0, Q1);
        break;

    default:
        /* ...right-front blend-region */
        mesh_calc_blend_ratios(X, Y, Z, 3, B0, B1, Q0, Q1);
    }
}

/**
 * @brief   Encode strip into mesh VBO
 *
 * @param   gen[in]         Mesh generator
 * @param   k[in]           Camera index
 * @param   x0[in]          Strip origin, X-coordinate
 * @param   y0[in]          Strip origin, Y-coordinate
 * @param   dx[in]          Quad width
 * @param   dy[in]          Quad height
 * @param   uv[in]          Sensor-coordinates array
 * @param   q[in]           Points weights array
 * @param   n[in]           Number of points-pairs in a strip
 */
static void mesh_strip_encode(
    mesh_gen_t *gen,
    int k,
    float32_t x0,
    float32_t y0,
    float32_t dx,
    float32_t dy,
    float32_t (*uv)[2],
    float32_t (*q)[2],
    int n)
{
    mesh_vertex_t  *v;
    int             i;

    /* ...reserve place for 2 * (n - 1) triangles */
    if ((v = mesh_vbo_add(&gen->vbo[k], (n - 1) * 6)) == NULL)
    {
        TRACE(ERROR, _x("cam-%u: failed to reserve %u vertices"), k, (n - 1) * 6);
        return;
    }

    float32x2x2_t   XY;
    XY.val[0] = __mk_float32x2(x0, x0);
    XY.val[1] = __mk_float32x2(y0, y0 + dy);

    float32x2_t     SX = vdup_n_f32(dx);

    mesh_vertex_t   b[2];

    /* ...process all vertices (we always have pairs of points) */
    for (i = 0; i < n; i++)
    {
        /* ...load sensor coordinates:
         * [0]: U0:U1
         * [1]: V0:V1
         */
        float32x2x2_t   T0 = vld2_f32(*uv);
        uv += 2;

        /* ...load blend/correction ratios:
         * [0]: Q0:Q1
         * [1]: q0:q1
         */
        float32x2x2_t   Q0 = vld2_f32(*q);
        q += 2;

        /* ...create two vertices in interleaved order:
         * [0]: X0:V0:X1:V1
         * [1]: Y0:Q0:Y1:Q1
         * [2]: U0:q0:U1:q1
         */
        float32x4x3_t   B;
        B.val[0] = vcombine_f32(vtrn1_f32(XY.val[0], T0.val[1]), vtrn2_f32(XY.val[0], T0.val[1]));
        B.val[1] = vcombine_f32(vtrn1_f32(XY.val[1], Q0.val[0]), vtrn2_f32(XY.val[1], Q0.val[0]));
        B.val[2] = vcombine_f32(vtrn1_f32(T0.val[0], Q0.val[1]), vtrn2_f32(T0.val[0], Q0.val[1]));

        /* ...advance display coordinates of the points (X-coordinate only) */
        XY.val[0] = vadd_f32(XY.val[0], SX);

        /* ...create two triangles if possible */
        (i > 0 ? mesh_tri_encode(&v, b, B) : 0);

        /* ...put last two points into triangle forming buffer */
        vst3q_f32(b[0], B);
    }
}

/**
 * @brief   Calculate blend regions configuration using the car shadow region, blend regions
 *          directrisses angles
 *
 * @param   shadow[in]      Shadow region in world coordinates: [x_min, y_min, x_max, y_max], mm
 * @param   angles[in]      Zones separation angles: [FL, LR, RR, RF], deg
 * @param   S[out]          Shadow zone configuration
 * @param   B[out]          Zones separation lines equations: -B[0]*X + B[1]*Y = B[2]
 */
void mesh_calc_separation_zones(
    float32_t *shadow,
    float32_t *angles,
    float32_t *offsets,
    float32x2x2_t *S,
    float32x4x3_t *B0,
    float32x4x3_t *B1,
    float32x4x2_t *C0,
    float32x4x2_t *C1)
{
    /* ...load shadow parameters:
     * [0]: {x_min, x_max}
     * [1]: {y_min, y_max}
     */
    float32x2x2_t   T = vld2_f32(shadow);

    /* ...prepare corners array starting from FL:
     * [0]: {x_max, x_min, x_min, x_max}
     * [1]: {y_max, y_max, y_min, y_min}
     *
     */
    float32x4x2_t   K;
    K.val[0] = vcombine_f32(vext_f32(T.val[0], T.val[0], 1), T.val[0]);
    K.val[1] = vcombine_f32(vtrn2_f32(T.val[1], T.val[1]), vtrn1_f32(T.val[1], T.val[1]));

    /* ...load first offsets from the shadow corners */
    float32x4_t     P0 = vld1q_f32(offsets);
    C0->val[0] = vaddq_f32(K.val[0], vtrn2q_f32(vmovq_n_f32(0.0f), P0));
    C0->val[1] = vaddq_f32(K.val[1], vtrn1q_f32(P0, vmovq_n_f32(0.0f)));

    /* ...reorder points:
     * [0]: {x_min, y_min}
     * [1]: {x_max, y_max}
     */
    S->val[0] = vtrn1_f32(T.val[0], T.val[1]);
    S->val[1] = vtrn2_f32(T.val[0], T.val[1]);

    /* ...load angles (in degrees), translate to radians */
    float32x4_t     A0 = vmulq_n_f32(vld1q_f32(angles), (float32_t)(M_PI / 180.0));

    /* ...calculate zone-separation lines equations:
     * [0]: sin(A0),sin(A1),...
     * [1]: cos(A0),cos(A1),...
     * [2]: -sin(A0)*X0 + cos(A0)*Y0,...
     */
    sincos_ps(A0, &B0->val[0], &B0->val[1]);
    B0->val[2] = vmlsq_f32(vmulq_f32(C0->val[1], B0->val[1]), C0->val[0], B0->val[0]);

    /* ...load second offsets from the shadow corners */
    float32x4_t     P1 = vld1q_f32(offsets + 4);
    C1->val[0] = vaddq_f32(K.val[0], vtrn1q_f32(P1, vmovq_n_f32(0.0f)));
    C1->val[1] = vaddq_f32(K.val[1], vtrn2q_f32(vmovq_n_f32(0.0f), P1));

    /* ...load angles (in degrees), translate to radians */
    float32x4_t     A1 = vmulq_n_f32(vld1q_f32(angles + 4), (float32_t)(M_PI / 180.0));

    /* ...calculate zone-separation lines equations:
     * [0]: sin(A0),sin(A1),...
     * [1]: cos(A0),cos(A1),...
     * [2]: -sin(A0)*X0 + cos(A0)*Y0,...
     */
    sincos_ps(A1, &B1->val[0], &B1->val[1]);
    B1->val[2] = vmlsq_f32(vmulq_f32(C1->val[1], B1->val[1]), C1->val[0], B1->val[0]);
}

/**
 * @brief   Start new strip for a given camera; place first quad
 *
 * @param   k[in]           Blend-zone index (informative)
 * @param   T0[in]          Upper two points in the quad in interleaved order:
 *                          [0]: {X00, X01}
 *                          [1]: {Y00, Y01}
 *                          [2]: {Z00, Z01}
 * @param   T1[in]          Lower two points in the quad in interleaved order:
 *                          [0]: {X10, X11}
 *                          [1]: {Y10, Y11}
 *                          [2]: {Z10, Z11}
 * @param   Q0[in]          Points weights for lower region:
 *                          [0]: {q00,q01,q10,q11}
 *                          [1]: {Q00,Q01,Q10,Q11}
 * @param   Q1[in]          Points weights for upper region:
 *                          [0]: {q00,q01,q10,q11}
 *                          [1]: {Q00,Q01,Q10,Q11}
 * @param   v[out]          Strip points array: {P00,P10,P01,P11}
 * @param   q0[out]         Lower region points weights array: {q00,q10,q01,q11}
 * @param   q1[out]         Upper region points weights array: {Q00,Q10,Q01,Q11}
 */
static inline __attribute__((__always_inline__, __gnu_inline__))
void mesh_strip_start(
    int k,
    float32x2x3_t T0,
    float32x2x3_t T1,
    float32x4x2_t Q0,
    float32x4x2_t Q1,
    float32_t (*v)[3],
    float32_t (*q0)[2],
    float32_t (*q1)[2])
{
    float32x4x3_t   T;
    T.val[0] = vcombine_f32(vtrn1_f32(T0.val[0], T1.val[0]), vtrn2_f32(T0.val[0], T1.val[0]));
    T.val[1] = vcombine_f32(vtrn1_f32(T0.val[1], T1.val[1]), vtrn2_f32(T0.val[1], T1.val[1]));
    T.val[2] = vcombine_f32(vtrn1_f32(T0.val[2], T1.val[2]), vtrn2_f32(T0.val[2], T1.val[2]));
    vst3q_f32(*v, T);

    float32x2_t     R0, R1;
    float32x4x2_t   R;
    R0 = vget_low_f32(Q0.val[0]);
    R1 = vget_high_f32(Q0.val[0]);
    R.val[0] = vcombine_f32(vtrn1_f32(R0, R1), vtrn2_f32(R0, R1));

    R0 = vget_low_f32(Q0.val[1]);
    R1 = vget_high_f32(Q0.val[1]);
    R.val[1] = vcombine_f32(vtrn1_f32(R0, R1), vtrn2_f32(R0, R1));
    vst2q_f32(*q0, R);

    R0 = vget_low_f32(Q1.val[0]);
    R1 = vget_high_f32(Q1.val[0]);
    R.val[0] = vcombine_f32(vtrn1_f32(R0, R1), vtrn2_f32(R0, R1));

    R0 = vget_low_f32(Q1.val[1]);
    R1 = vget_high_f32(Q1.val[1]);
    R.val[1] = vcombine_f32(vtrn1_f32(R0, R1), vtrn2_f32(R0, R1));
    vst2q_f32(*q1, R);
}

/**
 * @brief   Add point-pair {<X01,Y01,Z01>, <X11,Y11,Z11>} to current strip
 *
 * @param   k[in]           Camera index (informative)
 * @param   T0[in]          Upper two points in the quad in interleaved order:
 *                          [0]: {X00, X01}
 *                          [1]: {Y00, Y01}
 *                          [2]: {Z00, Z01}
 * @param   T1[in]          Lower two points in the quad in interleaved order:
 *                          [0]: {X10, X11}
 *                          [1]: {Y10, Y11}
 *                          [2]: {Z10, Z11}
 * @param   Q0[in]          Points weights for lower region:
 *                          [0]: {q00,q01,q10,q11}
 *                          [1]: {Q00,Q01,Q10,Q11}
 * @param   Q1[in]          Points weights for upper region:
 *                          [0]: {q00,q01,q10,q11}
 *                          [1]: {Q00,Q01,Q10,Q11}
 * @param   v[out]          Strip points array: {P01,P11}
 * @param   q0[out]         Lower region points weights array: {q01,q11}
 * @param   q1[out]         Upper region points weights array: {Q01,Q11}
 */
static inline __attribute__((__always_inline__, __gnu_inline__))
void mesh_strip_add(
    int k,
    float32x2x3_t T0,
    float32x2x3_t T1,
    float32x4x2_t Q0,
    float32x4x2_t Q1,
    float32_t (*v)[3],
    float32_t (*q0)[2],
    float32_t (*q1)[2])
{
    float32x2x3_t   T;
    T.val[0] = vtrn2_f32(T0.val[0], T1.val[0]);
    T.val[1] = vtrn2_f32(T0.val[1], T1.val[1]);
    T.val[2] = vtrn2_f32(T0.val[2], T1.val[2]);
    vst3_f32(*v, T);

    float32x2x2_t   R;
    R.val[0] = vtrn2_f32(vget_low_f32(Q0.val[0]), vget_high_f32(Q0.val[0]));
    R.val[1] = vtrn2_f32(vget_low_f32(Q0.val[1]), vget_high_f32(Q0.val[1]));
    vst2_f32(*q0, R);

    R.val[0] = vtrn2_f32(vget_low_f32(Q1.val[0]), vget_high_f32(Q1.val[0]));
    R.val[1] = vtrn2_f32(vget_low_f32(Q1.val[1]), vget_high_f32(Q1.val[1]));
    vst2_f32(*q1, R);
}

/**
 * @brief   Complete single strip
 *
 * @param   gen[in]         Mesh generator
 * @param   x0[in]          Strip origin X-coordinate
 * @param   y0[in]          Strip origin Y-coordinate
 * @param   dx[in]          Quad horizontal size
 * @param   dy[in]          Quad vertical size
 * @param   v[in]           Strip points array: {P00,P10,P01,P11}
 * @param   q0[in]          Lower region points weights array: {q00,q10,q01,q11}
 * @param   q1[in]          Lower region points weights array: {q00,q10,q01,q11}
 * @param   count[in]       Number of point-pairs in the strip
 * @param   k[in]           Index of the blend-region
 */
static void mesh_strip_complete(
    mesh_gen_t *gen,
    float32_t x0,
    float32_t y0,
    float32_t dx,
    float32_t dy,
    float32_t (*v)[3],
    float32_t (*q0)[2],
    float32_t (*q1)[2],
    int count,
    int k)
{
    float32_t   xyz[(count + 3) * 2][3] __attribute__((aligned(16)));
    float32_t   uv[(count + 3) * 2][2] __attribute__((aligned(16)));
    int         k0 = k >> 1;

    /* ...map points from camera "k0" */
    mesh_sv_project(gen, k0, v, xyz, q0, count * 2, uv);

    /* ...encode a lower region strip first */
    mesh_strip_encode(gen, k0, x0, y0, dx, dy, uv, q0, count);

    if (k & 1)
    {
        /* ...blend-region; process adjacent (higher) region */
        k0 = (k0 + 1) & 3;

        /* ...produce mapping for higher camera region */
        mesh_sv_project(gen, k0, v, xyz, q1, count * 2, uv);

        /* ...encode a higher region strip with negation of distance weights */
        mesh_strip_encode(gen, k0, x0, y0, dx, dy, uv, q1, count);
    }

    TRACE(0, _b("strip-%d complete (x0=%f,y0=%f,count=%d)"), k, x0, y0, count);
}

/**
 * @brief   Start new shadow strip; place first quad
 *
 * @param   T0[in]          Upper two points in the quad in interleaved order:
 *                          [0]: {X00, X01}
 *                          [1]: {Y00, Y01}
 *                          [2]: {Z00, Z01}
 * @param   T1[in]          Lower two points in the quad in interleaved order:
 *                          [0]: {X10, X11}
 *                          [1]: {Y10, Y11}
 *                          [2]: {Z10, Z11}
 * @param   v[out]          Strip points array: {P00,P10,P01,P11}
 */
static inline __attribute__((__always_inline__, __gnu_inline__))
void mesh_shadow_strip_start(
    float32x2x3_t T0,
    float32x2x3_t T1,
    float32_t (*v)[3])
{
    float32x4x3_t   T;
    T.val[0] = vcombine_f32(vtrn1_f32(T0.val[0], T1.val[0]), vtrn2_f32(T0.val[0], T1.val[0]));
    T.val[1] = vcombine_f32(vtrn1_f32(T0.val[1], T1.val[1]), vtrn2_f32(T0.val[1], T1.val[1]));
    T.val[2] = vcombine_f32(vtrn1_f32(T0.val[2], T1.val[2]), vtrn2_f32(T0.val[2], T1.val[2]));
    vst3q_f32(*v, T);
}

/**
 * @brief   Add point-pair {<X01,Y01,Z01>, <X11,Y11,Z11>} to shadow strip
 *
 * @param   T0[in]          Upper two points in the quad in interleaved order:
 *                          [0]: {X00, X01}
 *                          [1]: {Y00, Y01}
 *                          [2]: {Z00, Z01}
 * @param   T1[in]          Lower two points in the quad in interleaved order:
 *                          [0]: {X10, X11}
 *                          [1]: {Y10, Y11}
 *                          [2]: {Z10, Z11}
 * @param   v[out]          Strip points array: {P01,P11}
 */
static inline __attribute__((__always_inline__, __gnu_inline__))
void mesh_shadow_strip_add(
    float32x2x3_t T0,
    float32x2x3_t T1,
    float32_t (*v)[3])
{
    float32x2x3_t   T;
    T.val[0] = vtrn2_f32(T0.val[0], T1.val[0]);
    T.val[1] = vtrn2_f32(T0.val[1], T1.val[1]);
    T.val[2] = vtrn2_f32(T0.val[2], T1.val[2]);
    vst3_f32(*v, T);
}

/**
 * @brief   Complete single shadow strip
 *
 * @param   gen[in]         Mesh generator
 * @param   x0[in]          Strip origin X-coordinate
 * @param   y0[in]          Strip origin Y-coordinate
 * @param   dx[in]          Quad horizontal size
 * @param   dy[in]          Quad vertical size
 * @param   v[in]           Strip points array: {P00,P10,P01,P11}
 * @param   count[in]       Number of point-pairs in the strip
 */
static void mesh_shadow_strip_complete(
    mesh_gen_t *gen,
    float32_t x0,
    float32_t y0,
    float32_t dx,
    float32_t dy,
    float32_t (*v)[3],
    int count)
{
    TRACE(0, _b("shadow-strip complete (x0=%f,y0=%f,count=%d)"), x0, y0, count);

    hv_mesh_create_strip(gen->hv, gen->hv_vbo, v, (float32_t [2]){x0, y0}, (float32_t [2]){dx, dy}, count);
}

/**
 * @brief   Create parabolic bowl mesh
 *
 * @param   gen[in]         Mesh generator
 * @param   shadow[in]      Shadow region in world coordinates: [x_min, y_min, x_max, y_max], mm
 * @param   angles[in]      Zones separation angles: [FL, LR, RR, RF], deg
 * @param   N[in]           Lattice horizontal size
 * @param   M[in]           Lattice vertical size
 *
 * @return                  Zero on success, negative on failure
 */
static int mesh_create_bowl(
    mesh_gen_t *gen,
    float32_t *shadow,
    float32_t *angles,
    float32_t *offsets,
    const int32_t N,
    const int32_t M)
{
    u32             t0 = __get_time_usec();

    /* ...interim storage for mesh 3D-points in single row (allocate on stack) */
    float32_t       V0[(N + 3) * 3] __attribute__((aligned(16)));
    float32_t       V1[(N + 3) * 3] __attribute__((aligned(16)));
    float32_t      *VV[2] = { V0, V1 };

    uint16_t        K0[(N + 3) * 1]  __attribute__((aligned(16)));
    uint16_t        K1[(N + 3) * 1]  __attribute__((aligned(16)));
    uint16_t       *KK[2] = { K0, K1 };

    /* ...calculate separation lines equations and shadow zone */
    float32x2x2_t   s;
    float32x4x3_t   b0, b1;
    float32x4x2_t   c0, c1;
    mesh_calc_separation_zones(shadow, angles, offsets, &s, &b0, &b1, &c0, &c1);

    u32             t1 = __get_time_usec();
    u32             T0 = 0, T1 = 0, T2 = 0, T3 = 0;

    /* ...load transformation matrix */
    float32x4_t     U0123 = vld1q_f32(gen->U);
    float32x4_t     U4567 = vld1q_f32(gen->U + 4);
    float32_t       U8 = gen->U[8];

    float32_t       dx = (2.0f / (float32_t)(N - 1));
    float32_t       dy = (2.0f / (float32_t)(M - 1));

    int             i, j, bank;

    /* ...create vertex lattice */
    for (bank = 0, j = 0; j < M; bank ^= 1, j++)
    {
        uint16_t      (*j0)[1] = (uint16_t (*) [1])KK[bank];
        uint16_t      (*j1)[1] = (uint16_t (*) [1])KK[bank ^ 1];

        float32_t     (*v0)[3] = (float32_t (*) [3])VV[bank];
        float32_t     (*v1)[3] = (float32_t (*) [3])VV[bank ^ 1];

        float32x4_t     X = vmlaq_n_f32(vmovq_n_f32(-1.0f), __mk_float32x4(0.0f, 1.0f, 2.0f, 3.0f), dx);
        float32x4_t     Y = vmovq_n_f32((float32_t)j * dy - 1.0f);

        u32 _t0 = __get_time_usec();

        /* ...process single row - get U*{u,v,1} terms of ray-tracing equation */
        for (i = 0; i < N; i += 4)
        {
            float32x4x3_t   P;

            /* ...produce next 4 points */
            P = mat3x3_mulvh(X, Y, U0123, U4567, U8);

            /* ...store result in temporary array */
            vst3q_f32(v0[i], P);

            /* ...advance X-coordinates */
            X = vaddq_f32(X, vmovq_n_f32(dx * 4.0f));
        }

        u32 _t1 = __get_time_usec();

        /* ...pass points produced to ray-tracer - in-place processing */
        mesh_sv_parabolic_bowl_tracer(gen, v0, N);

        u32 _t2 = __get_time_usec();

        /* ...select point region */
        for (i = 0; i < N; i += 4)
        {
            float32x4x3_t   P;
            uint16x4_t      K;

            /* ...load 4 points */
            P = vld3q_f32(v0[i]);

            /* ...calculate indices of the points */
            K = mesh_tv_select_region(P.val[0], P.val[1], s, b0, b1);

            /* ...store indices of the points */
            vst1_u16(j0[i], K);
        }

        u32 _t3 = __get_time_usec();

        /* ...process strip if possible */
        if (j != 0)
        {
            float32_t       strip[(N + 3) * 2][3] __attribute__((aligned(16)));
            float32_t       ratio0[(N + 3) * 2][2] __attribute__((aligned(16)));
            float32_t       ratio1[(N + 3) * 2][2] __attribute__((aligned(16)));
            int             count = 0;
            int             k0 = -1, k1;
            int             i0 = 0;

            for (i = 0; i < N - 1; i++)
            {
                /* ...test all four corners of the quad to find out where it gets */
                k1 = mesh_tv_select_regions(*j1++, *j0++);

                float32x2x3_t   t0 = vld3_f32(*v1++);
                float32x2x3_t   t1 = vld3_f32(*v0++);
                float32x4x2_t   q0, q1;

                if (k1 >= 0)
                {
                    /* ...calculate ratios for current camera region (all four points) */
                    mesh_calc_quad_ratios(t0, t1, s, b0, b1, k1, &q0, &q1);
                }

                if (k1 != k0)
                {
                    if (k0 >= 0)
                    {
                        /* ...complete current strip */
                        mesh_strip_complete(gen, i0 * dx - 1.0f, (j - 1) * dy - 1.0f, dx, dy, strip, ratio0, ratio1, count, k0);
                    }
                    else if (gen->hv != NULL)
                    {
                        /* ...complete shadow strip */
                        mesh_shadow_strip_complete(gen, i0 * dx - 1.0f, (j - 1) * dy - 1.0f, dx, dy, strip, count);
                    }

                    if (k1 >= 0)
                    {
                        /* ...start next strip */
                        mesh_strip_start(k1, t0, t1, q0, q1, &strip[0], &ratio0[0], &ratio1[0]);
                    }
                    else if (gen->hv != NULL)
                    {
                        /* ...start shadow strip */
                        mesh_shadow_strip_start(t0, t1, &strip[0]);
                    }

                    /* ...save strip characteristics */
                    i0 = i, count = 2, k0 = k1;
                }
                else
                {
                    if (k1 >= 0)
                    {
                        /* ...add point-pair to current strip */
                        mesh_strip_add(k1, t0, t1, q0, q1, &strip[count * 2], &ratio0[count * 2], &ratio1[count * 2]);
                    }
                    else if (gen->hv != NULL)
                    {
                        /* ...add point-pair to shadow strip */
                        mesh_shadow_strip_add(t0, t1, &strip[count * 2]);
                    }

                    count++;
                }
            }

            /* ...finish last strip */
            if (k0 >= 0)
            {
                mesh_strip_complete(gen, i0 * dx - 1.0f, (j - 1) * dy - 1.0f, dx, dy, strip, ratio0, ratio1, count, k0);
            }
            else if (gen->hv != NULL)
            {
                mesh_shadow_strip_complete(gen, i0 * dx - 1.0f, (j - 1) * dy - 1.0f, dx, dy, strip, count);
            }
        }

        u32 _t4 = __get_time_usec();

        T0 += (_t1 - _t0), T1 += (_t2 - _t1), T2 += (_t3 - _t2), T3 += (_t4 - _t3);
    }

    u32             t2 = __get_time_usec();

    TRACE(INFO, _b("mesh built: %u/%u=(%u+%u+%u+%u) (%u), [%d * %d]"), t1 - t0, t2 - t1, T0, T1, T2, T3, t2 - t0, N, M);

    return 0;
}


static
void mesh_set_mask_data(mesh_alphamask_cfg_t *mask,
                        cfg_data_t *cfg,
                        cfg_tv_mesh_t *tv)
{
    float32x2x2_t   s;
    float32x4x3_t   B0, B1;
    float32x4x2_t   C0, C1;
    mesh_calc_separation_zones(tv->shadow, tv->angles, tv->offsets, &s, &B0, &B1, &C0, &C1);

    float *b0v0 = (float*)(&B0.val[0]);
    float *b0v1 = (float*)(&B0.val[1]);
    float *b0v2 = (float*)(&B0.val[2]);

    float *b1v0 = (float*)(&B1.val[0]);
    float *b1v1 = (float*)(&B1.val[1]);
    float *b1v2 = (float*)(&B1.val[2]);

    /* l, of region 0                        (FrontLeft)   */
    mask->m[0][0] = b0v0[0]; mask->m[0][1] = -b0v1[0]; mask->m[0][2] = b0v2[0];
    mask->l[0][0] = -b1v0[0]; mask->l[0][1] = b1v1[0]; mask->l[0][2] = -b1v2[0];

    /* l, of region 1                         (RearLeft)   */
    mask->l[1][0] = b0v0[1]; mask->l[1][1] = -b0v1[1]; mask->l[1][2] = b0v2[1];
    mask->m[1][0] = -b1v0[1]; mask->m[1][1] = b1v1[1]; mask->m[1][2] = -b1v2[1];

    /* l, of region 2                         (RearRight)  */
    mask->m[2][0] = b0v0[2]; mask->m[2][1] = -b0v1[2]; mask->m[2][2] = b0v2[2];
    mask->l[2][0] = -b1v0[2]; mask->l[2][1] = b1v1[2]; mask->l[2][2] = -b1v2[2];

    /* l, of region 3                         (FrontRight) */
    mask->l[3][0] = b0v0[3]; mask->l[3][1] = -b0v1[3]; mask->l[3][2] = b0v2[3];
    mask->m[3][0] = -b1v0[3]; mask->m[3][1] = b1v1[3]; mask->m[3][2] = -b1v2[3];
}

/**
 * @brief   Create top-view mesh
 *
 * @param   gen[in]         Mesh generator
 * @param   shadow[in]      Shadow region in world coordinates: [x_min, y_min, x_max, y_max], mm
 * @param   angles[in]      Zones separation angles: [FL, LR, RR, RF], deg
 * @param   N[in]           Lattice horizontal size
 * @param   M[in]           Lattice vertical size
 *
 * @return                  Zero on success, negative on failure
 */
static int mesh_create_tv(
    mesh_gen_t *gen,
    float32_t *shadow,
    float32_t *angles,
    float32_t *offsets,
    const int32_t N,
    const int32_t M,
    mesh_alphamask_cfg_t* alphamask)
{
    /* ...interim storage for mesh 3D-points in single row (allocate on stack) */
    float32_t       V0[(N + 3) * 3] __attribute__((aligned(16)));
    float32_t       V1[(N + 3) * 3] __attribute__((aligned(16)));
    float32_t      *VV[2] = { V0, V1 };

    uint16_t        K0[(N + 3) * 1]  __attribute__((aligned(16)));
    uint16_t        K1[(N + 3) * 1]  __attribute__((aligned(16)));
    uint16_t       *KK[2] = { K0, K1 };

    /* ...calculate separation lines equations and shadow zone */
    float32x2x2_t   s;
    float32x4x3_t   b0, b1;
    float32x4x2_t   c0, c1;
    mesh_calc_separation_zones(shadow, angles, offsets, &s, &b0, &b1, &c0, &c1);

    /* ...load transformation matrix:
     * [0]: {Sxx, Syx}
     * [1]: {Sxy, Syy}
     * [2]: {Ox, Oy}
     */
    float32x2x3_t   U = vld3_f32(gen->U);

    TRACE(0, _b("U: {%f,%f,%f} : {%f,%f,%f} : {%f,%f,%f}"),
           gen->U[0], gen->U[1], gen->U[2],
           gen->U[3], gen->U[4], gen->U[5],
           gen->U[6], gen->U[7], gen->U[8]);


    if (alphamask)
    {
        memcpy(alphamask->U, gen->U, sizeof(float) * 6);
        alphamask->U[6] = 0.f;
        alphamask->U[7] = 0.f;
        alphamask->U[8] = 1.f;
    }

    /* ...calculate initial horizontal coordinate / increment */
    float32_t       dx = 2.0f / (float32_t)(N - 1);
    float32_t       dy = 2.0f / (float32_t)(M - 1);

    int32_t         i, j, bank;

    /* ...create vertex lattice */
    for (bank = 0, j = 0; j < M; bank ^= 1, j++)
    {
        uint16_t      (*j0)[1] = (uint16_t (*) [1])KK[bank];
        uint16_t      (*j1)[1] = (uint16_t (*) [1])KK[bank ^ 1];

        float32_t     (*v0)[3] = (float32_t (*) [3])VV[bank];
        float32_t     (*v1)[3] = (float32_t (*) [3])VV[bank ^ 1];

        float32x4_t     X = vmlaq_n_f32(vmovq_n_f32(-1.0f), __mk_float32x4(0, 1.0f, 2.0f, 3.0f), dx);
        float32x4_t     Y = vmovq_n_f32((float32_t)j * dy - 1.0f);
        float32x4x3_t   P;
        int             i;

        /* ...Z coordinate is explicitly set to 0 */
        P.val[2] = vmovq_n_f32(0.0f);

        /* ...process single row - get coordinates of the points on the ground */
        for (i = 0; i < N; i += 4)
        {
            /* ...multiply display point by transformation matrix */
            P.val[0] = vmlaq_lane_f32(vmlaq_lane_f32(vdupq_lane_f32(U.val[2], 0), X, U.val[0], 0), Y, U.val[1], 0);
            P.val[1] = vmlaq_lane_f32(vmlaq_lane_f32(vdupq_lane_f32(U.val[2], 1), X, U.val[0], 1), Y, U.val[1], 1);

            /* ...store result in temporary array */
            vst3q_f32(v0[i], P);

            TRACE(0, _b("P={%f,%f,%f,%f} : {%f,%f,%f,%f} : {%f,%f,%f,%f}"), __float32x4_p(P.val[0]), __float32x4_p(P.val[1]), __float32x4_p(P.val[2]));

            /* ...calculate indices of the points */
            uint16x4_t  K = mesh_tv_select_region(P.val[0], P.val[1], s, b0, b1);

            /* ...store indices of the points */
            vst1_u16(j0[i], K);

            /* ...advance X-coordinates */
            X = vaddq_f32(X, vmovq_n_f32(4.0f * dx));
        }

        /* ...process strip if possible */
        if (j != 0)
        {
            float32_t       strip[(N + 3) * 2][3] __attribute__((aligned(16)));
            float32_t       ratio0[(N + 3) * 2][2] __attribute__((aligned(16)));
            float32_t       ratio1[(N + 3) * 2][2] __attribute__((aligned(16)));
            int             count = 0;
            int             k0 = -1, k1;
            int             i0 = 0;

            for (i = 0; i < N - 1; i++)
            {
                /* ...test all four corners of the quad to find out where it gets */
                k1 = mesh_tv_select_regions(*j1++, *j0++);

                float32x2x3_t   t0 = vld3_f32(*v1++);
                float32x2x3_t   t1 = vld3_f32(*v0++);
                float32x4x2_t   q0, q1;

                if (k1 >= 0)
                {
                    /* ...calculate ratios for current camera region (all four points) */
                    mesh_calc_quad_ratios(t0, t1, s, b0, b1, k1, &q0, &q1);
                }

                if (k1 != k0)
                {
                    if (k0 >= 0)
                    {
                        /* ...complete current strip */
                        mesh_strip_complete(gen, i0 * dx - 1.0f, (j - 1) * dy - 1.0f, dx, dy, strip, ratio0, ratio1, count, k0);
                    }

                    if (k1 >= 0)
                    {
                        /* ...start next strip */
                        mesh_strip_start(k1, t0, t1, q0, q1, &strip[0], &ratio0[0], &ratio1[0]);

                        /* ...save strip characteristics */
                        i0 = i, count = 2;
                    }

                    k0 = k1;
                }
                else
                {
                    if (k1 >= 0)
                    {
                        /* ...add point-pair to current strip */
                        mesh_strip_add(k1, t0, t1, q0, q1, &strip[count * 2], &ratio0[count * 2], &ratio1[count * 2]);

                        count++;
                    }
                }
            }

            /* ...finish last strip */
            if (k0 >= 0)
            {
                mesh_strip_complete(gen, i0 * dx - 1.0f, (j - 1) * dy - 1.0f, dx, dy, strip, ratio0, ratio1, count, k0);
            }
        }
    }

    TRACE(INFO, _b("TV-mesh built: [%d * %d]"), N, M);

    return 0;
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

#ifdef BUILD_NATIVE
/**
 * @brief   Prepare mesh debug window
 *
 * @param   mesh[in]        Mesh data
 * @param   type[in]        Mesh type
 *
 * @return                  Debug window handle
 */
static void * mesh_dbg_setup(mesh_data_t *mesh, uint32_t type, uint32_t number, const char *id)
{
    /* ...destroy current debug window as required */
    if (mesh->dbg != NULL)
    {
        if (mesh->type != type || number != mesh->number)
        {
            if (mesh->type == MESH_SCV)
            {
                scv_dbg_destroy(mesh->dbg);
            }
            else if (mesh->type == MESH_STV || mesh->type == MESH_TV || mesh->type == MESH_BV)
            {
                mesh_dbg_destroy(mesh->dbg);
            }
            else
            {
                mcv_dbg_destroy(mesh->dbg, mesh->number);
            }

            TRACE(DEBUG, _b("debug window %p [type=%d] destroyed..."), mesh->dbg, type);

            mesh->dbg = NULL;
        }
        else
        {
            /* ...special reset? not sure */
        }
    }

    /* ...create mesh debug window if possible */
    if (mesh->dbg == NULL)
    {
        /* ...create debug window */
        if (type == MESH_SCV)
        {
            mesh->dbg = scv_dbg_create(1280, 720, id);
        }
        else if (type == MESH_STV || type == MESH_TV || type == MESH_BV)
        {
            mesh->dbg = mesh_dbg_create(1280, 720, id);
        }
        else if (type == MESH_MCV)
        {
            mesh->dbg = mcv_dbg_create(number, 1280, 720, id);
        }

        /* ...save number of windows */
        mesh->number = number;

        TRACE(DEBUG, _b("debug window %p [type=%d] created..."), mesh->dbg, type);
    }

    return mesh->dbg;
}
#endif  /* BUILD_NATIVE */

/**
 * @brief   Prepare mesh-generator operation
 *
 * @param   gen[in]             Mesh generator data
 * @param   mesh[in]            Mesh data pointer
 * @param   number[in]          Number of mesh VBO arrays to prepare
 * @param   dst[in]             Destination tile pointer to set for all mesh items
 * @param   type[in]            Mesh type
 */
static int mesh_gen_prepare(mesh_gen_t *gen, mesh_data_t *mesh, uint32_t number, int32_t *dst, uint32_t type, char *id)
{
    uint32_t    k;

    /* ...reset all dynamic arrays */
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        /* ...reset VBO */
        mesh_vbo_clear(&gen->vbo[k]);
        gen->vbo[k].dst = dst;
        gen->vbo[k].id = k;
    }

#ifdef BUILD_NATIVE
    /* ...initialize mesh-dependent debug window */
    (getenv("MESH_DEBUG") ? gen->dbg = mesh_dbg_setup(mesh, type, number, id) : 0);
#endif

    /* ...save mesh type */
    mesh->type = type;

    return 0;
}

/**
 * @brief   Finalize mesh-generator operation
 *
 * @param   gen[in]             Mesh generator data
 * @param   mesh[in]            Mesh data
 * @param   number[in]          Number of mesh items
 *
 * @return                      Negative on failure
 */
static inline int mesh_gen_finish(mesh_gen_t *gen, mesh_data_t *mesh, uint32_t number)
{
    /* ...clear historical-view module reference */
    gen->hv = NULL;

    /* ...upload vertices into VBOs */
    return mesh_update(mesh, gen->vbo, number);
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Prepare single-camera-view generation procedure
 *
 * @param   vcam[in]        Virtual camera data
 * @param   camera[in]      Physical camera data
 * @param   scv[in]         SCV-mesh configuration data
 */
static void mesh_gen_scv_prepare(vcamera_data_t *vcam, camera_data_t *camera, cfg_scv_mesh_t *scv, vehicle_state_t *vehicle, float32_t *U, float32_t *W)
{
    float32_t  *position = scv->position;
    float32_t   rotation[3];
    float32_t   fov[4];

    /* ...if position is {0,0,0}, then take physical camera position */
    if (position[0] == 0.0f && position[1] == 0.0f && position[2] == 0.0f)
    {
        position = camera->T;
    }

    /* ...set rotation angles */
    rotation[0] = scv->rotation[0];
    rotation[1] = scv->rotation[1];
    rotation[2] = scv->rotation[2] + scv->yaw_adj_coef * vehicle->steering;

    /* ...set field of view parameters */
    fov[0] = scv->fov[0] + scv->fov_adj_coef[0] * fabsf(vehicle->steering);
    fov[1] = scv->fov[1] + scv->fov_adj_coef[1] * fabsf(vehicle->steering);
    fov[2] = scv->fov[2] + scv->fov_adj_coef[2] * vehicle->steering;
    fov[3] = scv->fov[3] + scv->fov_adj_coef[3] * vehicle->steering;

    /* ...initialize virtual camera for back-project operation */
    vcamera_back_project_to_world_init(vcam, rotation, position, fov, scv->distortion, scv->compression);

    /* ...save virtual camera matrices */
    memcpy(U, vcam->R, sizeof(vcam->R));

    /* ...additive term is a virtual camera position */
    memcpy(W, vcam->T, sizeof(vcam->T));
}

/**
 * @brief   Create single-camera-view mesh
 *
 * @param   gen[in]             Mesh generator data
 * @param   cfg[in]             Global configuration data
 * @param   scv[in]             SCV-mesh configuration parameters
 * @param   vehicle[in]         Vehicle state data
 * @param   mesh[in]            Mesh data
 *
 * @return                      Negative on failure
 */
int mesh_generate_scv(mesh_gen_t *gen, cfg_data_t *cfg, cfg_scv_mesh_t *scv_data, vehicle_state_t *vehicle, mesh_data_t *mesh)
{
    cfg_scv_mesh_t* scv = scv_data;

    int32_t    *dst = scv->base.dst;
    int32_t     x0 = dst[0], y0 = dst[1], x1 = dst[2], y1 = dst[3];

    /* ...prepare mesh-generator for operation */
    CHK_API(mesh_gen_prepare(gen, mesh, 1, dst, MESH_SCV, "scv"));

    /* ...save scratch data for single-camera mesh generation */
    gen->vbo[0].id = gen->camera_id = scv->id;
    gen->current = &gen->vbo[0];

    /* ...prepare tracing matrices for single-camera-view */
    mesh_gen_scv_prepare(&gen->vcam, &gen->camera[gen->camera_id], scv, vehicle, gen->U, gen->W);

#ifdef  BUILD_NATIVE
    /* ...prepare XYZ/UV VBO filling */
    (gen->dbg ? scv_dbg_prepare(gen->dbg, scv->fov, gen->U, gen->W) : 0);
#endif

    /* ...generate mesh */
    CHK_API(mesh_create_single_dist(gen, vehicle, (x1 - x0 + 8) / 8, (y1 - y0 + 8) / 8, dst, scv));

#ifdef  BUILD_NATIVE
    /* ...finish filling of XYZ/UV VBO */
    (gen->dbg ? scv_dbg_finish(gen->dbg) : 0);
#endif

    /* ...upload mesh vertices */
    return mesh_gen_finish(gen, mesh, 1);
}


typedef struct
{
    GLfloat x;
    GLfloat y;
    GLfloat u;
    GLfloat v;
    GLfloat q0;
    GLfloat q1;
} xyuvq_point_t;


static inline void fill_quad_ver(float32_t x0, float32_t x1, float32_t y0, float32_t y1, float32_t w, float32_t h,  xyuvq_point_t *verts)
{
    verts[0].x = 2.f*(x0 / w) - 1.f;
    verts[0].y = 2.f*(y0 / h) - 1.f;
    verts[1].x = 2.f*(x1 / w) - 1.f;
    verts[1].y = 2.f*(y0 / h) - 1.f;
    verts[2].x = 2.f*(x0 / w) - 1.f;
    verts[2].y = 2.f*(y1 / h) - 1.f;
    verts[3].x = 2.f*(x0 / w) - 1.f;
    verts[3].y = 2.f*(y1 / h) - 1.f;
    verts[4].x = 2.f*(x1 / w) - 1.f;
    verts[4].y = 2.f*(y0 / h) - 1.f;
    verts[5].x = 2.f*(x1 / w) - 1.f;
    verts[5].y = 2.f*(y1 / h) - 1.f;
}

static inline void fill_quad_tex(float32_t x0, float32_t x1, float32_t y0, float32_t y1, float32_t w, float32_t h,  xyuvq_point_t *verts)
{
    verts[0].u = x0 / w;
    verts[0].v = y0 / h;
    verts[1].u = x1 / w;
    verts[1].v = y0 / h;
    verts[2].u = x0 / w;
    verts[2].v = y1 / h;
    verts[3].u = x0 / w;
    verts[3].v = y1 / h;
    verts[4].u = x1 / w;
    verts[4].v = y0 / h;
    verts[5].u = x1 / w;
    verts[5].v = y1 / h;

    uint32_t i;

    for (i = 0; i < 6; i++)
    {
        verts[i].q0 = 1.f;
        verts[i].q1 = 1.f;
    }
}

static void init_copy_mesh(vbo_data_t** dst, uint32_t img_w, uint32_t img_h, uint32_t out_w, uint32_t out_h, uint32_t target_x, uint32_t target_y)
{
    /// 6 points in 2 triangles
    /// 4 quads, 1 quad for each camera type
    xyuvq_point_t data[6] = {0};

    xyuvq_point_t* data_out = data;

    uint32_t i;

    float32_t s_x0 = img_w - 4;
    float32_t s_x1 = img_w;
    float32_t s_y0 = 0;
    float32_t s_y1 = 1;

    float32_t d_x0 = target_x;
    float32_t d_x1 = target_x + 4;
    float32_t d_y0 = target_y;
    float32_t d_y1 = target_y + 1;

    fill_quad_ver(d_x0, d_x1, d_y0, d_y1, out_w, out_h, data_out);
    fill_quad_tex(s_x0, s_x1, s_y0, s_y1, img_w, img_h, data_out);

    if (dst[0])
    {
        vbo_destroy(dst[0]);
    }

    dst[0] = vbo_create(sizeof(xyuvq_point_t), 6, data);
}


/**
 * @brief   Create single-camera-view mesh
 *
 * @param   gen[in]             Mesh generator data
 * @param   cfg[in]             Global configuration data
 * @param   scv[in]             SCV-mesh configuration parameters
 * @param   vehicle[in]         Vehicle state data
 * @param   mesh[in]            Mesh data
 *
 * @return                      Negative on failure
 */
int mesh_generate_ctl(mesh_gen_t *gen, cfg_data_t *cfg, cfg_ctlval_mesh_t* ctl, mesh_data_t *mesh)
{
    int32_t    *dst = ctl->base.dst;
    int32_t     x0 = dst[0], y0 = dst[1], x1 = dst[2], y1 = dst[3];

    uint32_t target_x = ctl->output_point[0];
    uint32_t target_y = ctl->output_point[1];

    mesh->type = MESH_CTL;

    uint32_t w = ctl->base.dst[2] - ctl->base.dst[0];
    uint32_t h = ctl->base.dst[3] - ctl->base.dst[1];

    uint32_t i;

    for (i = 0; i < SV_CAMERAS_NUMBER; i++)
    {
        if (ctl->cameras & (1 << i))
        {
            uint32_t cam_w = (uint32_t)cfg->camera[i].resolution[0] + 0.5f;
            uint32_t cam_h = (uint32_t)cfg->camera[i].resolution[1] + 0.5f;
            init_copy_mesh(&mesh->item[i].vbo, cam_w, cam_h, w, h, target_x + 4*i, target_y);
            mesh->item[i].id = i;
            memcpy(mesh->item[i].dst, dst, sizeof(int32_t) * 4);
        }
    }

    return 0;
}

/**
 * @brief   Prepare ray-tracing parameters for STV-mesh generation
 *
 * @param   stv[in]         STV-mesh configuration data
 * @param   U[out]          3*3 virtual camera rotation matrix
 * @param   W[out]          Virtual camera position
 */
static inline void mesh_gen_stv_prepare(cfg_stv_mesh_t *stv, float32_t *U, float32_t *W)
{
    /* ...prepare VR-matrix (PVM matrix is not needed in fact) */
    mesh_prepare_vr_matrix(stv->fov, stv->rotation, stv->position, U, W);
}

/**
 * @brief   Calculate STV-mesh rotation matrix angles
 *
 * @param   stv[in]             STV-mesh configuration data
 */
void mesh_stv_fix_angles(cfg_stv_mesh_t *stv)
{
    float32_t   diff[3] = {
        stv->look_at[0] - stv->position[0],
        stv->look_at[1] - stv->position[1],
        stv->look_at[2] - stv->position[2],
    };

    /* ...calculate rotation matrix (yaw and pitch only) basing on look-at and position vectors */
    stv->rotation[0] = 0.0f * (float32_t)(180.0 / M_PI);
    stv->rotation[1] = -atan2f(diff[2], sqrtf(diff[0] * diff[0] + diff[1] * diff[1])) * (float32_t)(180.0 / M_PI);
    stv->rotation[2] = atan2f(diff[1], diff[0]) * (float32_t)(180.0 / M_PI);

    TRACE(DEBUG, _b("position: %f,%f,%f, look-at: %f,%f,%f, rotation: %f,%f,%f"),
          stv->position[0], stv->position[1], stv->position[2],
          stv->look_at[0], stv->look_at[1], stv->look_at[2],
          stv->rotation[0], stv->rotation[1], stv->rotation[2]);
}

/**
 * @brief   Create see-through-view mesh
 *
 * @param   gen[in]             Mesh generator data
 * @param   cfg[in]             STV-mesh configuration parameters
 * @param   mesh[in]            Mesh data
 *
 * @return                      Negative on failure
 */
int mesh_generate_stv(mesh_gen_t *gen, cfg_data_t *cfg, cfg_stv_mesh_t *stv, mesh_data_t *mesh)
{
    int32_t        *dst = stv->base.dst;
    int32_t         x0 = dst[0], y0 = dst[1], x1 = dst[2], y1 = dst[3];

    /* ...prepare mesh generation operation */
    CHK_API(mesh_gen_prepare(gen, mesh, SV_CAMERAS_NUMBER, dst, MESH_STV, "stv"));

    /* ...prepare virtual camera matrix */
    mesh_gen_stv_prepare(stv, gen->U, gen->W);

#ifdef  BUILD_NATIVE
    /* ...prepare debug VBO for XYZ/UV coordinates collection */
    gen->dbg ? mesh_dbg_prepare(gen->dbg, gen->U, gen->W) : 0;
#endif

    /* ...select center of bowl to be a geometrical center of the car */
    float32_t   C[3] = {
        0.5f * (cfg->vehicle.wheel_base + cfg->vehicle.front_overhang - cfg->vehicle.rear_overhang),
        0.0f,
        0.0f,
    };

    /* ...prepare mesh parameters */
    gen->invRx = 1.0f / stv->parabolic[0];
    gen->invRy = 1.0f / stv->parabolic[1];
    gen->steep = 1.0f / stv->parabolic[2];
    gen->smooth = stv->parabolic[3];

    /* ...precalculate coefficients of quadratic equation for paraboloid tracing */
    gen->B[0] = (gen->W[0] - C[0]) * gen->invRx;
    gen->B[1] = (gen->W[1] - C[1]) * gen->invRy;
    gen->B[2] = (gen->W[2] - C[2]) * gen->steep + 1.0f;

    /* ...create parabolic bowl mesh */
    CHK_API(mesh_create_bowl(gen, stv->shadow, stv->angles, stv->offsets, (x1 - x0 + 8) / 8, (y1 - y0 + 8) / 8));

    TRACE(INFO, _b("STV-view generated"));

#ifdef BUILD_NATIVE
    /* ...trigger VBO visualization */
    gen->dbg ? mesh_dbg_finish(gen->dbg) : 0;
#endif

    /* ...upload mesh vertices */
    return mesh_gen_finish(gen, mesh, SV_CAMERAS_NUMBER);
}

/**
 * @brief   Calculate position of the point on the ground matching the
 *          2D-coordinates of the point in virtual camera space
 *
 * @param   stv[in]         STV-view parameters
 * @param   uv[in]          2D-point in virtual camera space
 * @param   xyz[out]        Coordinates of matching 3D-point in the world
 */
float32_t mesh_stv_map_uv(cfg_stv_mesh_t *stv, float32_t *uv, float32_t *xyz)
{
    float32_t   U[3 * 3], W[3];

    /* ...prepare virtual camera matrix */
    mesh_gen_stv_prepare(stv, U, W);

    float32_t   P[3];

    __matNxN_mulvht(3, U, uv, P);

    /* ...find intersecion with ground plane */
    float32_t   Z = (fabsf(P[2]) < 0.001 ? 0.0f : -W[2] / P[2]);

    /* ...get resulting point as a W + Z*P */
    __vec3_mac(W, P, Z, xyz);

    TRACE(DEBUG, _b("uv=%f,%f, xyz=%f,%f,%f, Z=%f"), uv[0], uv[1], xyz[0], xyz[1], xyz[2], Z);

    return Z;
}


/**
 * @brief   Prepare ray-tracing parameters for TV-mesh generation
 *
 * @param   tv[in]          TV-mesh configuration data
 * @param   C[in]           2D world-coordinate of vehicle geometric center
 * @param   U[out]          2*3 pix-to-word conversion matrix
 */
static inline void mesh_gen_tv_prepare(cfg_tv_mesh_t *tv, float32_t *C, float32_t *U)
{
    int32_t    *dst = tv->base.dst;
    int32_t     x0 = dst[0], y0 = dst[1], x1 = dst[2], y1 = dst[3];

    /* ...generate transformation matrix for mesh generator */
    mesh_prepare_tv_matrix(x0, y0, x1, y1, tv->scale, C, U);
}

/**
 * @brief   Adjust top-view mesh parameters to maintain scene aspect
 *
 * @param   cfg[in]             Global configuration data
 * @param   tv[in]              TV-mesh configuration data
 */
void mesh_tv_fix_aspect(cfg_data_t *cfg, cfg_tv_mesh_t *tv, float32_t* area)
{
    int32_t    *dst = tv->base.dst;
    float32_t   Xc = (cfg->vehicle.wheel_base + cfg->vehicle.front_overhang - cfg->vehicle.rear_overhang) * 0.5f;
    float32_t   Yc = 0.0f;
    float32_t   Dw = (float32_t)(dst[2] - dst[0]) * 0.5f;
    float32_t   Dh = (float32_t)(dst[3] - dst[1]) * 0.5f;
    float32_t   length = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + cfg->vehicle.rear_overhang + tv->area[0] + tv->area[2];
    float32_t   width = cfg->vehicle.width_mirrors + tv->area[1] + tv->area[3];
    float32_t   scale_x = 0.5f * length / Dh;
    float32_t   scale_y = 0.5f * width / Dw;

    if (area)
    {
        memcpy(area, tv->area, sizeof(tv->area));

        if (scale_x > scale_y)
        {
            float32_t offset = (width*scale_x/scale_y - width) / 2.0f;
            area[1] += offset;
            area[3] += offset;
        }
        else
        {
            float32_t offset = (length*scale_y/scale_x - length) / 2.0f;
            area[0] += offset;
            area[2] += offset;
        }
    }

    TRACE(DEBUG, _b("area: %f,%f,%f,%f"), tv->area[0], tv->area[1], tv->area[2], tv->area[3]);

    tv->scale = MAX(scale_x, scale_y);

    float32_t   icon_width_2 = cfg->vehicle.width_mirrors * 0.5f / tv->scale;
    float32_t   icon_height_2 = (cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + cfg->vehicle.rear_overhang) * 0.5f / tv->scale;
    tv->icon_dst[0] = (dst[0] + dst[2]) * 0.5f - icon_width_2;
    tv->icon_dst[1] = (dst[1] + dst[3] + 200) * 0.5f - icon_height_2;
    tv->icon_dst[2] = (dst[0] + dst[2]) * 0.5f + icon_width_2;
    tv->icon_dst[3] = (dst[1] + dst[3] + 200) * 0.5f + icon_height_2;

    TRACE(0, _b("front-wheel-Y: %f, rear-wheel-Y: %f"),
          (dst[1] + dst[3]) * 0.5f - (cfg->vehicle.wheel_base - Xc) / tv->scale,
          (dst[1] + dst[3]) * 0.5f - (0 - Xc) / tv->scale);
}



/**
 * @brief   Create top-view mesh
 *
 * @param   gen[in]             Mesh generator data
 * @param   cfg[in]             TV-mesh configuration parameters
 * @param   mesh[in]            Mesh data
 *
 * @return                      Negative on failure
 */
int mesh_generate_tv(mesh_gen_t *gen, cfg_data_t *cfg, cfg_tv_mesh_t *tv, mesh_data_t *mesh)
{
    int32_t        *dst = tv->base.dst;
    int32_t         x0 = dst[0], y0 = dst[1], x1 = dst[2], y1 = dst[3];

    float32_t area[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    /* ...fix-up mesh aspect ratios */
    mesh_tv_fix_aspect(cfg, tv, area);

    /* ...prepare mesh generation operation */
    CHK_API(mesh_gen_prepare(gen, mesh, SV_CAMERAS_NUMBER, dst, MESH_TV, "tv"));

    /* ...world-coordinates of vehicle geometric center */
    float32_t   C[2] = {
        (cfg->vehicle.wheel_base + cfg->vehicle.front_overhang - cfg->vehicle.rear_overhang) * 0.5f + (area[0] - area[2])*0.5f,
        (area[3] - area[1]) * 0.5f,
    };

    /* ...prepare ray-tracer 2*3 matrix */
    mesh_gen_tv_prepare(tv, C, gen->U);

#ifdef  BUILD_NATIVE
    /* ...prepare buffer for VBO filling */
    gen->dbg ? mesh_dbg_prepare_tv(gen->dbg, x0, y0, x1, y1, gen->U) : 0;
#endif

    mesh_alphamask_cfg_t alphamask = {0};
    /* ...generate top-view mesh */
    CHK_API(mesh_create_tv(gen, tv->shadow, tv->angles, tv->offsets, (x1 - x0 + 8) / 8, (y1 - y0 + 8) / 8, &alphamask));
    mesh_set_mask_data(&alphamask, cfg, tv);
    mesh_tv_create_mask(mesh, &alphamask);

    TRACE(INFO, _b("TV-view generated"));

#ifdef BUILD_NATIVE
    /* ...trigger VBO visualization */
    gen->dbg ? mesh_dbg_finish(gen->dbg) : 0;
#endif

    /* ...finalize mesh generation */
    return mesh_gen_finish(gen, mesh, SV_CAMERAS_NUMBER);
}


void algo_get_matix(cfg_data_t *cfg, cfg_tv_mesh_t *tv, float32_t matrix[3*3])
{
    int32_t        *dst = tv->base.dst;
    int32_t         x0 = dst[0], y0 = dst[1], x1 = dst[2], y1 = dst[3];

    float32_t area[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    /* ...fix-up mesh aspect ratios */
    mesh_tv_fix_aspect(cfg, tv, area);

    /* ...world-coordinates of vehicle geometric center */
    float32_t   C[2] = {
        (cfg->vehicle.wheel_base + cfg->vehicle.front_overhang - cfg->vehicle.rear_overhang) * 0.5f + (area[0] - area[2])*0.5f,
        (area[3] - area[1]) * 0.5f,
    };

    /* ...prepare ray-tracer 2*3 matrix */
    mesh_gen_tv_prepare(tv, C, matrix);
    matrix[6] = 0.f;
    matrix[7] = 0.f;
    matrix[8] = 1.f;
}

/**
 * @brief   Prepare ray-tracing parameters for STV-mesh generation
 *
 * @param   camera[in]      Physical camera data
 * @param   cfg[in]         SCV-mesh configuration data
 * @param   dst[in]         Destination tile
 * @param   U[out]          3*3 virtual camera rotation matrix
 * @param   W[out]          Virtual camera translation vector
 */
static void mesh_gen_side_prepare(camera_data_t *camera, cfg_scv_mesh_t *scv, int32_t *dst, float32_t *U, float32_t *W)
{
    /* ...prepare virtual camera matrix */
    mesh_prepare_vr_matrix(scv->fov, scv->rotation, scv->position, U, W);
}

/**
 * @brief   Create multi-camera view mesh (side-view / mosaic)
 *
 * @param   gen[in]             Mesh generator data
 * @param   cfg[in]             Global configuration data
 * @param   mcv[in]             MCV-mesh configuration parameters array
 * @param   vehicle[in]         Vehicle state data
 * @param   mesh[in]            Mesh data
 *
 * @return                      Negative on failure
 */
int mesh_generate_mcv(mesh_gen_t *gen, cfg_data_t *cfg, cfg_mcv_mesh_t *mcv, vehicle_state_t *vehicle, mesh_data_t *mesh)
{
    uint32_t    number = mcv->number;
    uint32_t    i;

    /* ...prepare mesh generator for operation */
    CHK_API(mesh_gen_prepare(gen, mesh, number, NULL, MESH_MCV, "mcv"));

    /* ...process individual cameras */
    for (i = 0; i < number; i++)
    {
        cfg_scv_mesh_t     *scv = &mcv->scv[i];
        int32_t            *dst = scv->base.dst;
        int32_t             x0 = dst[0], y0 = dst[1], x1 = dst[2], y1 = dst[3];

        /* ...set current camera-id */
        gen->vbo[i].id = gen->camera_id = scv->id;

        /* ...save destination tile pointer */
        gen->vbo[i].dst = dst;

        /* ...set current VBO pointer */
        gen->current = &gen->vbo[i];

        /* ...check if mask area is not empty */
        if (scv->mask[0] < scv->mask[2] && scv->mask[1] < scv->mask[3])
        {
            /* ...save mask area */
            gen->mask = scv->mask;

            /* ...prepare tracing of single-camera */
            //mesh_gen_side_prepare(&gen->camera[gen->camera_id], scv, dst, gen->U, gen->W);
            mesh_gen_scv_prepare(&gen->vcam, &gen->camera[gen->camera_id], scv, vehicle, gen->U, gen->W);

#ifdef BUILD_NATIVE
            /* ...prepare debug window */
            gen->dbg = (mesh->dbg ? ((scv_dbg_t **)mesh->dbg)[i] : NULL);
            (gen->dbg ? scv_dbg_prepare(gen->dbg, scv->fov, gen->U, gen->W) : 0);
#endif
            /* ...generate mesh */
            CHK_API(mesh_create_side_view(gen, (x1 - x0 + 8) / 8, (y1 - y0 + 8) / 8));

#ifdef BUILD_NATIVE
            /* ...finalize debug window */
            (gen->dbg ? scv_dbg_finish(gen->dbg) : 0);
#endif
        }
        else
        {
            /* ...prepare tracing of single-camera */
            mesh_gen_scv_prepare(&gen->vcam, &gen->camera[gen->camera_id], scv, vehicle, gen->U, gen->W);

#ifdef BUILD_NATIVE
            /* ...prepare debug window */
            gen->dbg = (mesh->dbg ? ((scv_dbg_t **)mesh->dbg)[i] : NULL);
            (gen->dbg ? scv_dbg_prepare(gen->dbg, scv->fov, gen->U, gen->W) : 0);
#endif
            /* ...generate mesh */
            CHK_API(mesh_create_single_dist(gen, vehicle, (x1 - x0 + 8) / 8, (y1 - y0 + 8) / 8, dst, 0));

#ifdef BUILD_NATIVE
            /* ...finalize debug window */
            (gen->dbg ? scv_dbg_finish(gen->dbg) : 0);
#endif
        }
    }

    /* ...upload mesh vertices */
    return mesh_gen_finish(gen, mesh, number);
}

/**
 * @brief   Fish-eye distortion of 3D-points mapped into camera viewing space
 *
 * @param   gen[in]         Mesh generator
 * @param   k[in]           Index of the camera
 * @param   v[in]           Array of the 3D-points in world coordinate system
 * @param   xyz[out]        Scratch storage for the 3D-points in camera coordinate system
 * @param   q[in]           Array of the points weights for alpha-plane / color-correction
 * @param   n[in]           Number of points to transform
 * @param   uv[out]         Array of 2D camera-sensor coordinates
 * @param   yuv[out]        Lens-shading correction values
 */
static void mesh_bv_project(mesh_gen_t *gen, int k, float32_t (*v)[3], float32_t (*xyz)[3], int n, float32_t (*uv)[2])
{
    camera_data_t  *camera = &gen->camera[k];

#ifdef  BUILD_NATIVE
    /* ...dump 3D-points into VBO using camera index as a color discriminator */
    gen->dbg ? mesh_dbg_dump_xyz(gen->dbg, v, NULL, n, k) : 0;
#endif

    /* ...transform points into camera space */
    map_world_to_cam(v, camera->T, camera->R, n, xyz);

    /* ...apply fish-eye distortion */
    distort_kannala(xyz, uv, camera->params, n);

    if (0 && k == 2)
    {
        TRACE(1, _b("T=%f,%f,%f"), camera->T[0], camera->T[1], camera->T[2]);
        TRACE(1, _b("R=%f,%f,%f : %f,%f,%f : %f,%f,%f"), camera->R[0], camera->R[1], camera->R[2],
              camera->R[3], camera->R[4], camera->R[5], camera->R[6], camera->R[7], camera->R[8]);

        for (int i = 0; i < n; i++)
        {
            TRACE(1, _b("uv[%d] = %f, %f"), i, uv[i][0], uv[i][1]);
        }
    }

#ifdef  BUILD_NATIVE
    /* ...dump 3D-points in camera space */
    gen->dbg ? mesh_dbg_dump_cam(gen->dbg, xyz, NULL, n, k) : 0;

    /* ...dump sensor coordinates */
    gen->dbg ? mesh_dbg_dump_uv(gen->dbg, uv, n, k) : 0;
#endif
}

/**
 * @brief   Create top-view mesh
 *
 * @param   gen[in]         Mesh generator
 * @param   shadow[in]      Shadow region in world coordinates: [x_min, y_min, x_max, y_max], mm
 * @param   angles[in]      Zones separation angles: [FL, LR, RR, RF], deg
 * @param   N[in]           Lattice horizontal size
 * @param   M[in]           Lattice vertical size
 *
 * @return                  Zero on success, negative on failure
 */
static int mesh_create_bv(mesh_gen_t *gen, const int32_t N, const int32_t M, float32_t *u)
{
    /* ...interim storage for mesh 3D-points in single row (allocate on stack) */
    float32_t       V0[(N + 3) * 3] __attribute__((aligned(16)));
    float32_t       V1[(N + 3) * 3] __attribute__((aligned(16)));
    float32_t      *VV[2] = { V0, V1 };

    /* ...sensor coordinates */
    float32_t       UV0[(N + 3) * 2] __attribute__((aligned(16)));
    float32_t       UV1[(N + 3) * 2] __attribute__((aligned(16)));
    float32_t      *UV[2] = { UV0, UV1 };

    /* ...load transformation matrix:
     * [0]: {Sxx, Syx}
     * [1]: {Sxy, Syy}
     * [2]: {Ox, Oy}
     */
    float32x2x3_t   U = vld3_f32(u);

    /* ...calculate initial horizontal coordinate / increment */
    float32_t       dx = 2.0f / (float32_t)(N - 1);
    float32_t       dy = 2.0f / (float32_t)(M - 1);

    int32_t         i, j, bank;

    /* ...create vertex lattice */
    for (bank = 0, j = 0; j < M; bank ^= 1, j++)
    {
        float32_t     (*v0)[3] = (float32_t (*) [3])VV[bank];
        float32_t     (*v1)[3] = (float32_t (*) [3])VV[bank ^ 1];

        float32_t     (*uv0)[2] = (float32_t (*) [2])UV[bank];
        float32_t     (*uv1)[2] = (float32_t (*) [2])UV[bank ^ 1];

        float32x4_t     X = vmlaq_n_f32(vmovq_n_f32(-1.0f), __mk_float32x4(0, 1.0f, 2.0f, 3.0f), dx);
        float32x4_t     Y = vmovq_n_f32((float32_t)j * dy - 1.0f);
        float32x4x3_t   P;
        int             i;

        /* ...Z coordinate is explicitly set to 0 */
        P.val[2] = vmovq_n_f32(0.0f);

        /* ...process single row - get coordinates of the points on the ground */
        for (i = 0; i < N; i += 4)
        {
            /* ...multiply display point by transformation matrix */
            P.val[0] = vmlaq_lane_f32(vmlaq_lane_f32(vdupq_lane_f32(U.val[2], 0), X, U.val[0], 0), Y, U.val[1], 0);
            P.val[1] = vmlaq_lane_f32(vmlaq_lane_f32(vdupq_lane_f32(U.val[2], 1), X, U.val[0], 1), Y, U.val[1], 1);

            /* ...store result in temporary array */
            vst3q_f32(v0[i], P);

            if (0 && gen->camera_id == 2) TRACE(1, _b("P={%f,%f,%f,%f} : {%f,%f,%f,%f} : {%f,%f,%f,%f}"), __float32x4_p(P.val[0]), __float32x4_p(P.val[1]), __float32x4_p(P.val[2]));

            /* ...advance X-coordinates */
            X = vaddq_f32(X, vmovq_n_f32(4.0f * dx));
        }

        /* ...produce 2D-points in sensor coordinates */
        //mesh_scv_project(gen, v0, v0, N, uv0);
        mesh_sv_project(gen, gen->camera_id, v0, v0, NULL, N, uv0);


        /* ...encode a strip if possible */
        if (j != 0)
        {
            mesh_scv_encode(gen, -1.0f, (float32_t)(j - 1) * dy - 1.0f, dx, dy, uv1, uv0, N);
        }
    }

    TRACE(INFO, _b("BV-mesh built (camera-%d): [%d * %d]"), gen->camera_id, N, M);

    return 0;
}

/**
 * @brief   Generate bird-view mesh for single camera (top-view)
 *
 * @param   gen[in]         Mesh-generator data
 * @param   cfg[in]         Global configuration data
 * @param   bv[in]          Bird-view configuration data
 * @param   mesh[in]        Mesh data
 *
 * @return                  Negative on failure
 */
int mesh_generate_bv(mesh_gen_t *gen, cfg_data_t *cfg, cfg_bv_mesh_t *bv, mesh_data_t *mesh)
{
    int             k;

    /* ...prepare mesh generation operation */
    CHK_API(mesh_gen_prepare(gen, mesh, SV_CAMERAS_NUMBER, NULL, MESH_BV, "bv"));

    float32_t   Xf = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + bv->front_blind_area;
    float32_t   Xc = (-cfg->vehicle.rear_overhang + cfg->vehicle.wheel_base + cfg->vehicle.front_overhang) * 0.5f;
    float32_t   Xr = -cfg->vehicle.rear_overhang - bv->rear_blind_area;

    float32_t   Yl = cfg->vehicle.width * 0.5f + bv->left_blind_area;
    float32_t   Yc = 0.0f;
    float32_t   Yr = -cfg->vehicle.width * 0.5f - bv->right_blind_area;

    float32_t   Wfr2 = bv->slice_width_hor * 0.5f;
    float32_t   Hfr2 = bv->slice_height_hor * 0.5f;
    float32_t   Wlr2 = bv->slice_width_vert * 0.5f;
    float32_t   Hlr2 = bv->slice_height_vert * 0.5f;

    //TRACE(1, _b("Wfr2=%f, Hfr2=%f, Wlr2=%f, Hlr2=%f"));

    float32_t   U[SV_CAMERAS_NUMBER][2][3] = {
        [SV_CAMERA_FRONT] = {
            {0.0f, -Hfr2, Xf + Hfr2},
            {-Wfr2, 0.0f, Yc},
        },
        [SV_CAMERA_LEFT] = {
            {Wlr2, 0.0f, Xc},
            {0.0f, -Hlr2, Yl + Hlr2},
        },
        [SV_CAMERA_REAR] = {
            {0.0f, Hfr2, Xr - Hfr2},
            {Wfr2, 0.0f, Yc},
        },
        [SV_CAMERA_RIGHT] = {
            {-Wlr2, 0.0f, Xc},
            {0.0f, Hlr2, Yr - Hlr2},
        }
    };

#ifdef  BUILD_NATIVE
    /* ...prepare debug VBO for XYZ/UV coordinates collection */
    gen->dbg ? mesh_dbg_prepare(gen->dbg, U[0][0], (__vec3){0.0f}) : 0;
#endif

    /* ...process individual cameras */
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        int32_t        *dim = bv->dim[k];
        int32_t         w = dim[0], h = dim[1];

        /* ...save scratch data for single-camera mesh generation */
        gen->vbo[k].id = gen->camera_id = k;
        gen->current = &gen->vbo[k];

        if (k == 0) TRACE(1, _b("U={%f,%f,%f : %f,%f,%f}"),
                          U[k][0][0], U[k][0][1], U[k][0][2],
                          U[k][1][0], U[k][1][1], U[k][1][2]);

        /* ...prepare ray-tracer 2*3 matrix */
        CHK_API(mesh_create_bv(gen, (w + 8) / 8, (h + 8) / 8, U[k][0]));
    }

#ifdef BUILD_NATIVE
    /* ...trigger VBO visualization */
    gen->dbg ? mesh_dbg_finish(gen->dbg) : 0;
#endif

    return  mesh_gen_finish(gen, mesh, SV_CAMERAS_NUMBER);
}

/**
 * @brief   Prepare historical-view mesh generation
 *
 * @param   gen[in]             Mesh generator data
 * @param   cfg[in]             Global configuration parameters
 * @param   hv[in]              Historical-view module data
 * @param   vbo[in]             Historical-view VBOs array
 *
 * @return                      Negative on failure
 */
int mesh_prepare_hv(mesh_gen_t *gen, cfg_data_t *cfg, hv_data_t *hv, vbo_dynarray_t *vbo)
{
    int     k;

    /* ...reset VBOs as needed */
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        if (vbo[k].size == 0)
        {
            CHK_API(vbo_dynarray_init(&vbo[k], sizeof(hv_vertex_t), 1000));
        }
        else
        {
            vbo_dynarray_clear(&vbo[k], sizeof(hv_vertex_t));
        }
    }

    gen->hv = hv;
    gen->hv_vbo = vbo;

    return 0;
}

/*******************************************************************************
 * Mesh generator initialization
 ******************************************************************************/

/**
 * @brief   Initialize mesh generator data
 *
 * @param   cfg[in]         Application configuration data
 *
 * @return                  Mesh generator handle, or NULL on failure
 */
mesh_gen_t * mesh_gen_create(cfg_data_t *cfg)
{
    mesh_gen_t     *gen;
    camera_data_t  *camera;
    int             k;

    /* ...allocate mesh generator data */
    CHK_ERR(gen = calloc(1, sizeof(*gen)), NULL);

    /* ...initialize cameras */
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        cfg_camera_t   *cam_cfg = &cfg->camera[k];

        if (mesh_vbo_init(&gen->vbo[k], 40000) < 0)
        {
            TRACE(ERROR, _x("failed to initialize VBO array: %m"));
            return NULL;
        }

        if (cam_cfg->magna_format != 0)
        {
            /* ...convert magna format to ISO as needed */
            float32_t   angles[3] = {
                -__MATH_RADIANS(cam_cfg->rotation[1]),
                __MATH_RADIANS(cam_cfg->rotation[0]),
                -__MATH_RADIANS(cam_cfg->rotation[2]),
            };

            camera_set_magna_extrinsics(cfg, k, angles, cam_cfg->position);
        }
        else
        {
            /* ...use ISO8855 extrinsics format */
            camera_set_extrinsics(&gen->camera[k], cam_cfg->position, cam_cfg->rotation);
        }

        /* ...set camera intrinsics */
        camera_set_intrinsics(&gen->camera[k], cam_cfg->resolution, cam_cfg->distortion, cam_cfg->intrinsics);

        /* ...use ISO8855 extrinsics format */
        camera_set_extrinsics(&gen->camera[k], cam_cfg->position, cam_cfg->rotation);

        TRACE(DEBUG, _b("cam-%d: position=%f,%f,%f, rotation=%f,%f,%f"), k, cam_cfg->position[0], cam_cfg->position[1], cam_cfg->position[2],
              cam_cfg->rotation[0], cam_cfg->rotation[1], cam_cfg->rotation[2]);


        TRACE(INIT, _b("cam-%u: resolution=%f*%f, distortion=%f/%f/%f/%f"), k, cam_cfg->resolution[0], cam_cfg->resolution[1],
              cam_cfg->distortion[0], cam_cfg->distortion[1], cam_cfg->distortion[2], cam_cfg->distortion[3]);
    }

    TRACE(INIT, _b("mesh generator created"));

    return gen;
}

/**
 * @brief   Set camera parameters for mesh building procedure
 *
 * @param   gen[in]             Mesh generator data
 * @param   camera_cfg[in]      Camera configuration array
 */
void mesh_gen_camera_setup(mesh_gen_t *gen, cfg_camera_t *camera_cfg)
{
    uint32_t    k;
    static uint8_t u8Twice = 0;
    u8Twice++;
    /* ...prepare camera intrinsics / extrinsics */
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        camera_data_t  *camera = &gen->camera[k];
        cfg_camera_t   *cam_cfg = &camera_cfg[k];

        /* ...set camera intrinsic parameters */
        camera_set_intrinsics(camera, cam_cfg->resolution, cam_cfg->distortion, cam_cfg->intrinsics);

        /* ...set camera extrinsic parameters */
        camera_set_extrinsics(camera, cam_cfg->position, cam_cfg->rotation);

        if(2 >= u8Twice)
        {
            memcpy((void *)&vm_camera_data[k], camera, sizeof(camera_data_t));
            const float32_t *R = (float32_t *)vm_camera_data[k].R;
            const float32_t *T = (float32_t *)vm_camera_data[k].T;

            ME_Debugger_F_Printf_v("###################################\n");
            ME_Debugger_F_Printf_v("producer = %p\n", camera);
            ME_Debugger_F_Printf_v("R = [[%f, %f, %f], [%f, %f, %f], [%f, %f, %f]]\n", R[0], R[1], R[2], R[3], R[4], R[5], R[6], R[7], R[8]);
            ME_Debugger_F_Printf_v("T = [%f, %f, %f]\n", T[0], T[1], T[2]);
        }
        else
        {
            u8Twice = 3;
        }
    }
}

/**
 * @brief   Get camera data - tbd - doesn't look great
 *
 * @param   gen[in]     Mesh generator data
 */
camera_data_t * mesh_gen_cameras(mesh_gen_t *gen)
{
    return gen->camera;
}

#if 0
/**
 * @brief   Rotate 3D-point around center of source/destination points
 *
 * @param   pos[out]        Result of rotation operation
 * @param   src[in]         Source 3D-point
 * @param   dst[in]         Destination 3D-point
 * @param   t[in]           LERP factor
 */
static void mesh_stv_position_lerp(float32_t *pos, float32_t *src, float32_t *dst, float32_t t)
{
    float32_t   diff[3] = {
        (src[0] - dst[0]) * 0.5f,
        (src[1] - dst[1]) * 0.5f,
        (src[2] - dst[2]) * 0.5f,
    };

    float32_t   center[3] = {
        (src[0] + dst[0]) * 0.5f,
        (src[1] + dst[1]) * 0.5f,
        (src[2] + dst[2]) * 0.5f,
    };

    float32_t   pitch = -atan2f(diff[2], diff[0]);
    float32_t   yaw = t * M_PI;
    __mat3x3    Ry, Ry_inv, Rz, m0, m1;
    float32_t   delta[3];

    __matNxN_rotate(3, Ry, 0, 2, pitch * (float32_t)(180.0 / M_PI));
    __matNxN_rotate(3, Rz, 0, 1, yaw * (float32_t)(180.0 / M_PI));
    __mat3x3_transpose(Ry, Ry_inv);

    __mat3x3_mul(Ry, Rz, m0);
    __mat3x3_mul(m0, Ry_inv, m1);
    __mat3x3_mulv(m1, diff, delta);
    __vec3_add(center, delta, pos);

    TRACE(DEBUG, _b("t=%f, src=%f,%f,%f, dst=%f,%f,%f, pos=%f,%f,%f"), t, src[0], src[1], src[2], dst[0], dst[1], dst[2], pos[0], pos[1], pos[2]);
}
#endif

/**
 * @brief   LERP-transform 2D-vectors
 *
 * @param   vec[out]        Result of LERP operation
 * @param   src[in]         Source 2D-vector
 * @param   dst[in]         Destination 2D-vector
 * @param   t[in]           LERP factor
 */
static void mesh_lerp_vec2(float32_t *vec, float32_t *src, float32_t *dst, float32_t t)
{
    vec[0] = src[0] + t * (dst[0] - src[0]);
    vec[1] = src[1] + t * (dst[1] - src[1]);
}

/**
 * @brief   LERP-transform 3D-vectors
 *
 * @param   vec[out]        Result of LERP operation
 * @param   src[in]         Source 3D-vector
 * @param   dst[in]         Destination 3D-vector
 * @param   t[in]           LERP factor
 */
static void mesh_lerp_vec3(float32_t *vec, float32_t *src, float32_t *dst, float32_t t)
{
    vec[0] = src[0] + t * (dst[0] - src[0]);
    vec[1] = src[1] + t * (dst[1] - src[1]);
    vec[2] = src[2] + t * (dst[2] - src[2]);
}

/**
 * @brief   LERP-transform 4D-vectors
 *
 * @param   vec[out]        Result of LERP operation
 * @param   src[in]         Source 4D-vector
 * @param   dst[in]         Destination 4D-vector
 * @param   t[in]           LERP factor
 */
static void mesh_lerp_vec4(float32_t *vec, float32_t *src, float32_t *dst, float32_t t)
{
    vec[0] = src[0] + t * (dst[0] - src[0]);
    vec[1] = src[1] + t * (dst[1] - src[1]);
    vec[2] = src[2] + t * (dst[2] - src[2]);
    vec[3] = src[3] + t * (dst[3] - src[3]);
}

/**
 * @brief   LERP-transform FoVs of source and destination virtual cameras
 *
 * @param   fov[out]        Result of LERP operation
 * @param   src[in]         Source FoV values
 * @param   dst[in]         Destination FoV values
 * @param   t[in]           LERP factor
 */
static void mesh_lerp_fov(float32_t *fov, float32_t *src, float32_t *dst, float32_t t)
{
    fov[0] = fabsf(src[0]) + t * (fabsf(dst[0]) - fabsf(src[0]));
    fov[1] = fabsf(src[1]) + t * (fabsf(dst[1]) - fabsf(src[1]));

    if (t <= 0.5f)
    {
        src[0] < 0.0f ? fov[0] = -fov[0] : 0;
        src[1] < 0.0f ? fov[1] = -fov[1] : 0;
    }
    else
    {
        dst[0] < 0.0f ? fov[0] = -fov[0] : 0;
        dst[1] < 0.0f ? fov[1] = -fov[1] : 0;
    }
}

/**
 * @brief   LERP-transform display tile parameters
 *
 * @param   tile[out]       Result of LERP operation
 * @param   src[in]         Source tile parameters
 * @param   dst[in]         Destination tile parameters
 * @param   t[in]           LERP factor
 */
static void mesh_lerp_tile(int32_t *tile, int32_t *src, int32_t *dst, float32_t t)
{
    tile[0] = src[0] + (int32_t)(t * (float32_t)(dst[0] - src[0]));
    tile[1] = src[1] + (int32_t)(t * (float32_t)(dst[1] - src[1]));
    tile[2] = src[2] + (int32_t)(t * (float32_t)(dst[2] - src[2]));
    tile[3] = src[3] + (int32_t)(t * (float32_t)(dst[3] - src[3]));
}

/**
 * @brief   Create SCV configuration as a LERP operator on source and
 *          destination configs
 *
 * @param   cfg[in]         SCV-mesh configuration
 * @param   src[in]         Source SCV-mesh configuration
 * @param   dst[in]         Destination SCV-mesh configuration
 * @param   t[in]           LERP factor
 */
void mesh_scv_cfg_lerp(cfg_scv_mesh_t *cfg, cfg_scv_mesh_t *src, cfg_scv_mesh_t *dst, float32_t t)
{
    /* ...move position */
    mesh_lerp_vec3(cfg->position, src->position, dst->position, t);

    /* ...adjust rotation */
    mesh_lerp_vec3(cfg->rotation, src->rotation, dst->rotation, t);

    /* ...adjust FoV */
    mesh_lerp_fov(cfg->fov, src->fov, dst->fov, t);

    /* ...adjust distortion */
    mesh_lerp_vec2(cfg->distortion, src->distortion, dst->distortion, t);

    mesh_lerp_vec2(cfg->compression, src->compression, dst->compression, t);

    /* ...adjust destination tile */
    mesh_lerp_tile(cfg->base.dst, src->base.dst, dst->base.dst, t);
}

/**
 * @brief   Create STV configuration as a LERP operator on source and
 *          destination configs
 *
 * @param   cfg[in]         STV-mesh configuration
 * @param   src[in]         Source STV-mesh configuration
 * @param   dst[in]         Destination STV-mesh configuration
 * @param   t[in]           LERP factor
 */
void mesh_stv_cfg_lerp(cfg_stv_mesh_t *cfg, cfg_stv_mesh_t *src, cfg_stv_mesh_t *dst, float32_t t)
{
    //mesh_stv_position_lerp(cfg->look_at, src->look_at, dst->look_at, t);
    mesh_lerp_vec3(cfg->rotation, src->rotation, dst->rotation, t);
    mesh_lerp_vec3(cfg->position, src->position, dst->position, t);
    mesh_lerp_fov(cfg->fov, src->fov, dst->fov, t);
    mesh_lerp_vec4(cfg->shadow, src->shadow, dst->shadow, t);
    mesh_lerp_vec4(cfg->angles, src->angles, dst->angles, t);
    mesh_lerp_vec4(cfg->parabolic, src->parabolic, dst->parabolic, t);
    mesh_lerp_tile(cfg->base.dst, src->base.dst, dst->base.dst, t);
}

/**
 * @brief   Create STV configuration as a LERP operator on source and
 *          destination configs
 *
 * @param   cfg[in]         SCV-mesh configuration
 * @param   src[in]         Source SCV-mesh configuration
 * @param   dst[in]         Destination STV-mesh configuration
 * @param   t[in]           LERP factor
 */
void mesh_scv_stv_cfg_lerp_out(cfg_scv_mesh_t *cfg, cfg_scv_mesh_t *src, cfg_stv_mesh_t *dst, float32_t t)
{
    /* ...move position */
    mesh_lerp_vec3(cfg->position, src->position, dst->position, t);

    /* ...adjust rotation */
    mesh_lerp_vec3(cfg->rotation, src->rotation, dst->rotation, t);

    /* ...adjust FoV */
    mesh_lerp_fov(cfg->fov, src->fov, dst->fov, t);

    /* ...adjust distortion */
    cfg->distortion[0] = src->distortion[0] * MAX(1.0f - 2.0f * t, 0.0f);
    cfg->distortion[1] = src->distortion[1] * MAX(1.0f - 2.0f * t, 0.0f);

    /* ...adjust destination tile */
    mesh_lerp_tile(cfg->base.dst, src->base.dst, dst->base.dst, t);
}

/**
 * @brief   Create STV configuration as a LERP operator on source and
 *          destination configs
 *
 * @param   cfg[in]         STV-mesh configuration
 * @param   src[in]         Source SCV-mesh configuration
 * @param   dst[in]         Destination STV-mesh configuration
 * @param   t[in]           LERP factor
 */
void mesh_scv_stv_cfg_lerp_in(cfg_stv_mesh_t *cfg, cfg_scv_mesh_t *src, cfg_stv_mesh_t *dst, float32_t t)
{
    /* ...move position */
    mesh_lerp_vec3(cfg->position, src->position, dst->position, t);

    /* ...adjust rotation */
    mesh_lerp_vec3(cfg->rotation, src->rotation, dst->rotation, t);

    /* ...adjust FoV */
    mesh_lerp_fov(cfg->fov, src->fov, dst->fov, t);

    /* ...adjust destination tile */
    mesh_lerp_tile(cfg->base.dst, src->base.dst, dst->base.dst, t);
}

/**
 * @brief   Create STV/SCV configuration as a LERP operator on source and
 *          destination configs
 *
 * @param   cfg[in]         STV-mesh configuration
 * @param   src[in]         Source STV-mesh configuration
 * @param   dst[in]         Destination SCV-mesh configuration
 * @param   t[in]           LERP factor
 */
void mesh_stv_scv_cfg_lerp_out(cfg_stv_mesh_t *cfg, cfg_stv_mesh_t *src, cfg_scv_mesh_t *dst, float32_t t)
{
    /* ...move position */
    mesh_lerp_vec3(cfg->position, src->position, dst->position, t);

    /* ...adjust rotation */
    mesh_lerp_vec3(cfg->rotation, src->rotation, dst->rotation, t);

    /* ...adjust FoV */
    mesh_lerp_fov(cfg->fov, src->fov, dst->fov, t);

    /* ...adjust destination tile */
    mesh_lerp_tile(cfg->base.dst, src->base.dst, dst->base.dst, t);
}

/**
 * @brief   Create STV configuration as a LERP operator on source and
 *          destination configs
 *
 * @param   cfg[in]         SCV-mesh configuration
 * @param   src[in]         Source SCV-mesh configuration
 * @param   dst[in]         Destination STV-mesh configuration
 * @param   t[in]           LERP factor
 */
void mesh_stv_scv_cfg_lerp_in(cfg_scv_mesh_t *cfg, cfg_stv_mesh_t *src, cfg_scv_mesh_t *dst, float32_t t)
{
    /* ...move position */
    mesh_lerp_vec3(cfg->position, src->position, dst->position, t);

    /* ...adjust rotation */
    mesh_lerp_vec3(cfg->rotation, src->rotation, dst->rotation, t);

    /* ...adjust FoV */
    mesh_lerp_fov(cfg->fov, src->fov, dst->fov, t);

    /* ...adjust distortion */
    cfg->distortion[0] = dst->distortion[0] * MAX(t, 1.0f);
    cfg->distortion[1] = dst->distortion[1] * MAX(t, 1.0f);

    /* ...adjust destination tile */
    mesh_lerp_tile(cfg->base.dst, src->base.dst, dst->base.dst, t);
}

/**
 * @brief   Calculate aspect ratio for a tile
 *
 * @param   dst[in]     Destination tile: [X0,Y0,X1,Y1]
 *
 * @return              Tile height-to-width aspect ratio
 */
float32_t mesh_tile_aspect(int32_t *dst)
{
    int32_t     x0 = dst[0], y0 = dst[1], x1 = dst[2], y1 = dst[3];

    return (float32_t)(y1 - y0) / (float32_t)(x1 - x0);
}

/**
 * @brief   Calculate aspect ratio for a camera FoV
 *
 * @param   fov[in]     Camera field-of-view angles: [HFoV, VFoV]
 *
 * @return              Tile height-to-width aspect ratio
 */
float32_t mesh_fov_aspect(float32_t *fov)
{
    float32_t hfov2 = fov[0] * (float32_t)(0.5 * M_PI / 180.0);
    float32_t vfov2 = fov[1] * (float32_t)(0.5 * M_PI / 180.0);

    return (float32_t)fabsf(tanf(vfov2) / tanf(hfov2));
}

void calculate_shadow_from_vehicle(const cfg_data_t *cfg, cfg_tv_mesh_t *tv)
{
    if (tv->shadow[0] == 0.f && tv->shadow[2] == 0.f)
    {
        tv->shadow[0] = -cfg->vehicle.rear_overhang - cfg->vehicle.rear_blind_area;
        tv->shadow[1] = -cfg->vehicle.width*0.5f - cfg->vehicle.right_blind_area;
        tv->shadow[2] = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + cfg->vehicle.front_blind_area;
        tv->shadow[3] = cfg->vehicle.width*0.5f + cfg->vehicle.left_blind_area;
    }
    else if (tv->shadow[0] == 1.f && tv->shadow[2] == 1.f) /*Faizaan : Added to compensate for shadow changes for PLD algo view*/
    {
        tv->shadow[0] = -cfg->vehicle.rear_overhang - 100.f; /*100 is previous value of rear blind*/
        tv->shadow[1] = -cfg->vehicle.width*0.5f;
        tv->shadow[2] = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + 200.f; /*200 is previous value of front blind*/
        tv->shadow[3] = cfg->vehicle.width*0.5f;
    }
}
/**
 * @brief   Calculate virtual camera position for single-camera-view
 *
 * @param   scv[in]     SCV-mesh configuration data
 * @param   cfg[in]     Global configuration data
 */

void recalculate_position(cfg_scv_mesh_t* scv, const cfg_data_t* cfg)
{
    uint32_t camera = scv->id;
    if (scv->position[2] < 1.f)
    {
        scv->position[0] = cfg->camera[camera].position[0];
        scv->position[1] = cfg->camera[camera].position[1];
        scv->position[2] = cfg->camera[camera].position[2];

        if (camera == SV_CAMERA_FRONT || camera == SV_CAMERA_REAR)
            scv->position[1] = 0;
    }
    else if (scv->position[0] == 0.f && scv->position[1] == 0.f)
    {
        scv->position[0] = cfg->camera[camera].position[0];
        scv->position[1] = cfg->camera[camera].position[1];

        if (camera == SV_CAMERA_FRONT || camera == SV_CAMERA_REAR)
            scv->position[1] = 0;
    }
}

void undistort_kannala_gen(float32_t xyz[3], float32_t uv[2], mesh_gen_t* gen, uint32_t camera_id, float32_t Z)
{
    float32_t camera_xyz[3] = {0};
    undistort_kannala(camera_xyz, uv, gen->camera[camera_id].params);
    TRACE(0, _b("camera_xyz = [%f, %f, %f]\n"), camera_xyz[0], camera_xyz[1], camera_xyz[2]);
    const float32_t* R = gen->camera[camera_id].R;
    const float32_t* T = gen->camera[camera_id].T;

    TRACE(0, _b("R = [[%f, %f, %f], [%f, %f, %f], [%f, %f, %f]]\n"), R[0], R[1], R[2], R[3], R[4], R[5], R[6], R[7], R[8]);
    TRACE(0, _b("T = [%f, %f, %f]\n"), T[0], T[1], T[2]);

    float32_t C[9] = {0, -1, 0, 0, 0, -1, 1, 0, 0};
    float32_t Rt[9] = {0};
    float32_t Ri[9] = {0};
    __mat3x3_mul(R, C, Rt);
    __mat3x3_transpose(Rt, Ri);

    float32_t R0 = Ri[6];
    float32_t R1 = Ri[7];
    float32_t R2 = Ri[8];

    float32_t c0 = camera_xyz[0];
    float32_t c1 = camera_xyz[1];
    float32_t c2 = camera_xyz[2];

    float32_t q = (Z - T[2]) / (R0*c0 + R1*c1 + R2*c2);

    camera_xyz[0]*=q;
    camera_xyz[1]*=q;
    camera_xyz[2]*=q;

    /// xyz = Ri@camera_xyz+T
    xyz[0] = Ri[0]*camera_xyz[0] + Ri[1]*camera_xyz[1] + Ri[2]*camera_xyz[2] + T[0];
    xyz[1] = Ri[3]*camera_xyz[0] + Ri[4]*camera_xyz[1] + Ri[5]*camera_xyz[2] + T[1];
    xyz[2] = Ri[6]*camera_xyz[0] + Ri[7]*camera_xyz[1] + Ri[8]*camera_xyz[2] + T[2];
}

void undistort_kannala_gen_camera(float32_t xyz[3], float32_t uv[2], float32_t Z)
{
    camera_data_t *camera = &vm_camera_data[SV_CAMERA_REAR];
    float32_t camera_xyz[3] = {0};
    undistort_kannala(camera_xyz, uv, camera->params);
    TRACE(0, _b("camera_xyz = [%f, %f, %f]\n"), camera_xyz[0], camera_xyz[1], camera_xyz[2]);
    // printf("camera_xyz = [%f, %f, %f]\n", camera_xyz[0], camera_xyz[1], camera_xyz[2]);
    const float32_t* R = camera->R;
    const float32_t* T = camera->T;

    TRACE(0, _b("R = [[%f, %f, %f], [%f, %f, %f], [%f, %f, %f]]\n"), R[0], R[1], R[2], R[3], R[4], R[5], R[6], R[7], R[8]);
    TRACE(0, _b("T = [%f, %f, %f]\n"), T[0], T[1], T[2]);
    // printf("User camera = %p\n", camera);
    // printf("R = [[%f, %f, %f], [%f, %f, %f], [%f, %f, %f]]\n", R[0], R[1], R[2], R[3], R[4], R[5], R[6], R[7], R[8]);
    // printf("T = [%f, %f, %f]\n", T[0], T[1], T[2]);

    float32_t C[9] = {0, -1, 0, 0, 0, -1, 1, 0, 0};
    float32_t Rt[9] = {0};
    float32_t Ri[9] = {0};
    __mat3x3_mul(R, C, Rt);
    __mat3x3_transpose(Rt, Ri);

    float32_t R0 = Ri[6];
    float32_t R1 = Ri[7];
    float32_t R2 = Ri[8];

    float32_t c0 = camera_xyz[0];
    float32_t c1 = camera_xyz[1];
    float32_t c2 = camera_xyz[2];

    float32_t q = (Z - T[2]) / (R0*c0 + R1*c1 + R2*c2);

    camera_xyz[0]*=q;
    camera_xyz[1]*=q;
    camera_xyz[2]*=q;

    /// xyz = Ri@camera_xyz+T
    xyz[0] = Ri[0]*camera_xyz[0] + Ri[1]*camera_xyz[1] + Ri[2]*camera_xyz[2] + T[0];
    xyz[1] = Ri[3]*camera_xyz[0] + Ri[4]*camera_xyz[1] + Ri[5]*camera_xyz[2] + T[1];
    xyz[2] = Ri[6]*camera_xyz[0] + Ri[7]*camera_xyz[1] + Ri[8]*camera_xyz[2] + T[2];
}

