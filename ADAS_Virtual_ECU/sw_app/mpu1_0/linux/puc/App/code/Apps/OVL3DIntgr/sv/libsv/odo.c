/*******************************************************************************
 * odo.c
 *
 * Object-detection overlay generator and renderer
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

#define MODULE_TAG                      ODO

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "display.h"
#include "config.h"
#include "math-neon.h"
#include "odo.h"
#include "vbo-dynarray.h"

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Loal types definitions
 ******************************************************************************/

/**> Vertex data: {X,Y,Z} + {R,G,B,A} */
typedef GLfloat  odo_vertex_t[7];

/*******************************************************************************
 * Vertex shader construction
 ******************************************************************************/

/* ...VBO vertex shader */
static const char *vbo_vertex_shader =
    SH_SETPREC
    "attribute vec3	xyz;\n"
    "attribute vec4	c;\n"
    "varying vec4 color;\n"
    "uniform mat4 pvm;\n"
    "uniform float intensity;\n"
    "uniform float transparency;\n"
    "void main(void)\n"
    "{\n"
    "	gl_Position = pvm * vec4(xyz, 1.0);\n"
    "	color = vec4(c.xyz, c.w * transparency) * intensity;\n"
    "}\n";

/* ...VBO fragment shader */
static const char *vbo_fragment_shader =
    SH_SETPREC
    "varying vec4 color;\n"
    "void main()\n"
    "{\n"
    "   gl_FragColor = color;\n"
    "}\n";

/* ...specify shader name */
#define SHADER_TAG                  VBO
#define SHADER_VERTEX_SOURCE        vbo_vertex_shader
#define SHADER_FRAGMENT_SOURCE      vbo_fragment_shader

/* ...define list of attributes */
#define SHADER_ATTRIBUTES                               \
    __A(xyz), __A(c),

/* ...define list of uniforms */
#define SHADER_UNIFORMS                         \
    __U(pvm), __U(transparency), __U(intensity),

/* ...build shader lists */
#include "../src/shader-impl.h"

/**
 * @brief   Compile shader for overlay rendering
 *
 * @return                  Shader pointer
 */
static shader_data_t * odo_shader_compile(void)
{
    const shader_desc_t    *desc = &SHADER_DESC(VBO);

    return shader_create(desc);
}

/**
 * @brief   Return shader object for ODO
 *
 * @return                  Shader pointer, or NULL in case of error
 */
static shader_data_t * odo_get_shader(void)
{
    static shader_data_t * __shader;

    if (__shader == NULL)
    {
        /* ...shader not found; create new one */
        CHK_ERR(__shader = odo_shader_compile(), NULL);

        TRACE(INIT, _b("shader created: %u"), shader_program(__shader));
    }

    return __shader;
}

/**
 * @brief   Render VBO mesh
 *
 * @param   vbo[in]         VBO data
 * @param   texture[in]     Camera texture
 * @param   W[in]           Output window width
 * @param   W[in]           Output window height
 * @param   smooth[in]      Smoothing factor for alpha modulation
 * @param   intensity[in]   Global scene intensity level
 */

#define U(id)       u[UNIFORM(VBO, id)]
#define A(id)       ATTRIBUTE(VBO, id)

static void odo_vbo_render(vbo_dynarray_t *vbo, float32_t *pvm, GLfloat transparency, GLfloat intensity)
{
    const void     *XYZ_off = vbo_dynarray_buffer(&vbo[0], sizeof(odo_vertex_t));
    const void     *C_off = XYZ_off + 3 * sizeof(GLfloat);
    const size_t    vbo_size = sizeof(odo_vertex_t);
    shader_data_t  *shader;

    /* ...bail out if shader is not found */
    if ((shader = odo_get_shader()) == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %m"));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    /* ...set rendering program */
    glUseProgram(shader_program(shader));

    /* ...set PVM matrix  */
    glUniformMatrix4fv(U(pvm), 1, GL_FALSE, pvm);   GLCHECK();

    /* ...set object transparency level */
    glUniform1f(U(transparency), transparency); GLCHECK();

    /* ...set global scene intensity level */
    glUniform1f(U(intensity), intensity);   GLCHECK();

    /* ...make sure no VBO buffer binding set */
    glBindBuffer(GL_ARRAY_BUFFER, 0);    GLCHECK();

    /* ...enable attributes vector */
    glEnableVertexAttribArray(A(xyz));           GLCHECK();
    glVertexAttribPointer(A(xyz), 3, GL_FLOAT, GL_FALSE, vbo_size, XYZ_off);   GLCHECK();

    glEnableVertexAttribArray(A(c));            GLCHECK();
    glVertexAttribPointer(A(c), 4, GL_FLOAT, GL_FALSE, vbo_size, C_off);     GLCHECK();

    /* ...draw all triangles */
    glDrawArrays(GL_TRIANGLES, 0, vbo_dynarray_num(&vbo[0]));   GLCHECK();

    TRACE(DEBUG, _b("render %d triangles"), vbo_dynarray_num(&vbo[0]) / 3);

    /* ...render lines */
    XYZ_off = vbo_dynarray_buffer(&vbo[1], sizeof(odo_vertex_t));
    C_off = XYZ_off + 3 * sizeof(GLfloat);

    glVertexAttribPointer(A(xyz), 3, GL_FLOAT, GL_FALSE, vbo_size, XYZ_off);   GLCHECK();
    glVertexAttribPointer(A(c), 4, GL_FLOAT, GL_FALSE, vbo_size, C_off);     GLCHECK();

    /* ...draw all lines */
    glDrawArrays(GL_LINES, 0, vbo_dynarray_num(&vbo[1]));   GLCHECK();

    TRACE(DEBUG, _b("render %d lines"), vbo_dynarray_num(&vbo[1]) / 2);

    /* ...reset rendering program */
    glUseProgram(0);
}

#undef  U
#undef  A

/*******************************************************************************
 * Overlay generator
 ******************************************************************************/

/**
 * @brief   Calculate dot-product of 2D vectors
 *
 * @param   A[in]       First argument
 * @param   B[in]       Second argument
 *
 * @return              Dot-product A*B (duplicated)
 */
static inline float32x2_t calc_dot_product(float32x2_t A, float32x2_t B)
{
    float32x2_t     t = vmul_f32(A, B);

    return vpadd_f32(t, vext_f32(t, t, 1));
}

/**
 * @brief   Calculate normale vector of line segment
 *
 * @param   P0[in]      Start point
 * @param   P1[in]      End point
 *
 * @return              Normale vector
 */
static inline float32x2_t calc_normale(float32x2_t P0, float32x2_t P1)
{
    /* ...{P1.x-P0.x, P1.y-P0.y} */
    float32x2_t     V = vsub_f32(P1, P0);

    /* ...{-V.y, V.x} */
    float32x2_t     N = vext_f32(vneg_f32(V), V, 1);

    /* ...{V.x^2 + V.y^2} */
    float32x2_t     L = calc_dot_product(V, V);

    TRACE(0, _b("normale: V=%f,%f, N=%f,%f, L=%f,%f"), __float32x2_p(V), __float32x2_p(N), __float32x2_p(L));

    return vmul_f32(N, vinvsqrt_f32(L));
}

/**
 * @brief   Calculate normale vector of line segment
 *
 * @param   V[in]       Vector coordinates
 *
 * @return              Vector length in both lanes
 */
static inline float32x2_t calc_length(float32x2_t V)
{
    /* ...{V.x^2 + V.y^2} */
    float32x2_t     L = calc_dot_product(V, V);

    return vmul_f32(L, vinvsqrt_f32(L));
}

/**
 * @brief   Calculate direction vector for connecting of line segments of given
 *          width
 *
 * @param   P[in]       Nearest point coordinate
 * @param   N0[in]      Left-side normale vector
 * @param   N1[in]      Right-side notmale vector
 * @param   R[in]       Half-width of the line segment
 */
static inline float32x2x2_t calc_side_step(float32x2_t P, float32x2_t N0, float32x2_t N1, float32_t R)
{
    float32x2x2_t   T;

    /* ...get (half-)sum of normale vectors */
    float32x2_t     N = vadd_f32(N0, N1);

    /* ...N0.x*N1.x + N0.y*N1.y */
    float32x2_t     t0 = calc_dot_product(N0, N1);

    /* ...N.x*N.x+N.y*N.y */
    float32x2_t     t1 = calc_dot_product(N, N);

    /* ...calculate 0.5*(1+dot(N0,N1))*dot(N,N) */
    float32x2_t     t2 = vmul_n_f32(vmla_f32(t1, t1, t0), 0.5f);

    /* ...calculate (N0+N1)/sqrt(0.5*(1+dot(N0,N1))*dot(N,N)) */
    float32x2_t     S = vmul_f32(N, vinvsqrt_f32(t2));

    /* ...get two side-step points */
    T.val[0] = vmla_n_f32(P, S, R);
    T.val[1] = vmls_n_f32(P, S, R);

    return T;
}

/**
 * @brief   Single point encoding
 *
 * @param   v[in]       VBO buffer pointer
 * @param   XY[in]      Point coordinates
 * @param   z[in]       Height to encode
 * @param   C[in]       Point color
 *
 * @return              Updated VBO buffer pointer
 */
static inline odo_vertex_t * odo_point_encode(odo_vertex_t *v, float32x2_t XY, float32_t z, float32x4_t C)
{
    vst1_f32(&(*v)[0], XY);
    (*v)[2] = z;
    vst1q_f32(&(*v)[3], C);

    return ++v;
}

/**
 * @brief   Single vertical quad encoding
 *
 * @param   v[in]           Current VBO pointer
 * @param   B01[in]         Two points ({0}, {1}) in interleaved order
 *
 */
static inline odo_vertex_t * odo_quad_encode(odo_vertex_t *v, float32x2_t XY0, float32x2_t XY1, float32_t z0, float32_t z1, float32x4_t C0, float32x4_t C1)
{
    /* ...make triangles of points {0},{1},{2} and {2},{1},{3} */
    v = odo_point_encode(v, XY0, z0, C0);
    v = odo_point_encode(v, XY1, z0, C0);
    v = odo_point_encode(v, XY0, z1, C1);
    v = odo_point_encode(v, XY0, z1, C1);
    v = odo_point_encode(v, XY1, z0, C0);
    v = odo_point_encode(v, XY1, z1, C1);

    return v;
}

/**
 * @brief   Single line encoding
 *
 * @param   v[in]           Current VBO pointer
 * @param   XY0[in]         First point X,Y coordinates
 * @param   z0[in]          First point Z coordinate
 * @param   XY1[in]         Second point X,Y coordinates
 * @param   z1[in]          Second point Z coordinate
 * @param   C0[in]          First point color
 * @param   C1[in]          Second point color
 *
 * @return                  Update VBO pointer
 */
static inline odo_vertex_t * odo_line_encode(odo_vertex_t *v, float32x2_t XY0, float32_t z0, float32x2_t XY1, float32_t z1, float32x4_t C0, float32x4_t C1)
{
    v = odo_point_encode(v, XY0, z0, C0);
    v = odo_point_encode(v, XY1, z1, C1);

    return v;
}

/**
 * @brief   Encode curve given by series of adjacent line segments on the ground
 *
 * @param   vbo[in]         Dynamic VBO array
 * @param   points[in]      Array of 2D-coordinates of the points
 * @param   num[in]         Number of points in the array
 * @param   height[in]      Quad height
 * @param   color[in]       Quad color on the ground
 *
 * @return                  Negative on failure
 */
static int odo_encode_curve(vbo_dynarray_t *vbo, float32_t (*points)[2], int32_t num, float32_t height, float32_t *color)
{
    float32x2_t     P0 = vld1_f32(*points++);
    float32x4_t     C0 = vld1q_f32(color);
    float32x4_t     C1 = vsetq_lane_f32(0.0f, C0, 3);
    float32x2_t     P1;
    int32_t         i;
    odo_vertex_t   *v;

    /* ...reserve vertices for (num-1) quads */
    CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (num - 1) * 6), -1);

    /* ...process all points in the curve */
    for (i = 1; i < num; i++)
    {
        P1 = vld1_f32(*points++);

        TRACE(0, _b("p-%d: <%f,%f>-<%f,%f>, height=%f"), i, __float32x2_p(P0), __float32x2_p(P1), height);

        v = odo_quad_encode(v, P0, P1, 0.0f, height, C0, C1);

        P0 = P1;
    }

    return 0;
}

/**
 * @brief   Generate half-circle for ODO overlay end
 *
 * @param   Q[in]           Circle center
 * @param   N[in]           Normale vector
 * @param   R[in]           Circle radius
 * @param   Z[in]           Wall heaight
 * @param   color[in]       Color of the wall at the ground
 * @param   T[out]          Start/end points of the circle
 *
 * @return                  Negative on failure
 */
static inline int odo_gen_circle(vbo_dynarray_t *vbo, float32x2_t Q, float32x2_t N, float32_t R, float32_t Z, float32_t *color, float32x2x2_t *T)
{
    const int32_t   K = 16;
    int32_t         i;

    float32_t       points[K + 1][2];
    float32_t     (*p)[2] = &points[0];

    /* ...multiply normale vector by radius */
    float32x2_t     NS = vmul_n_f32(N, R);

    /* ...save starting and ending points */
    T->val[0] = vadd_f32(Q, NS);
    T->val[1] = vsub_f32(Q, NS);

    /* ...build points on circle */
    float32x4_t     A = vmulq_n_f32(__mk_float32x4(0.0f, 1.0f, 2.0f, 3.0f), (float32_t)(M_PI / K));

    TRACE(0, _b("circle-gen: Q=%f,%f, N=%f,%f, NS=%f,%f"), __float32x2_p(Q), __float32x2_p(N), __float32x2_p(NS));

    for (i = 0; i < K; i += 4)
    {
        /* ...evaluate sine/cosine of the angle */
        float32x4_t     S, C;
        sincos_ps(A, &S, &C);

        /* ...build rotated points:
         * [0] = {cos(A)*N.x + sin(A)*N.y + Q.x}
         * [1] = {-sin(A)*N.x + cos(A)*N.y + Q.y}
         */
        float32x4x2_t   V;
        V.val[0] = vmlaq_lane_f32(vmlaq_lane_f32(vdupq_lane_f32(Q, 0), S, NS, 1), C, NS, 0);
        V.val[1] = vmlsq_lane_f32(vmlaq_lane_f32(vdupq_lane_f32(Q, 1), C, NS, 1), S, NS, 0);

        /* ...store points in interim array */
        vst2q_f32(*p, V);
        p += 4;

        /* ...advance angles */
        A = vaddq_f32(A, vdupq_n_f32((float32_t)(4 * M_PI / K)));
    }

    /* ...save last point (angle = PI) */
    vst1_f32(*p, T->val[1]);

    /* ...build series of quads from the points array */
    return odo_encode_curve(vbo, points, K + 1, Z, color);
}

/**
 * @brief   Generate ODO for a single object - tbd - there must be a VBO for each object
 *
 * @param   vbo[in]         Dynamic VBO array
 * @param   P[in]           Nearest object point position, <X,Y>
 * @param   L[in]           Left-edge object point position, <X,Y>
 * @param   R[in]           Right-edge object point position, <X,Y>
 * @param   Z[in]           Object height estimation, <Z>
 * @param   rel[i]          Object reliability code (tbd - need that?)
 *
 * @return                  Negative on failure
 */
static int odo_generate(vbo_dynarray_t *vbo, float32_t *point, float32_t *left, float32_t *right, float32_t height, float32_t width, float32_t *color)
{
    /* ...load object coordinates */
    float32x2_t     P = vmul_n_f32(vld1_f32(point), 1000.0f);
    float32x2_t     L = vmul_n_f32(vld1_f32(left), 1000.0f);
    float32x2_t     R = vmul_n_f32(vld1_f32(right), 1000.0f);

    float32_t       W = width * 0.5f;
    uint32x2_t      LS = vcagt_f32(L, vdup_n_f32(W));
    uint32x2_t      RS = vcagt_f32(R, vdup_n_f32(W));

    float32x2_t     NL, NR;
    float32x2x2_t   TL, TR, TC;
    float32_t       points[3][2];

    TRACE(1, _b("P=%f,%f, L=%f,%f, R=%f,%f, LS=%x,%x, RS=%x,%x"), __float32x2_p(P), __float32x2_p(L), __float32x2_p(R), __uint32x2_p(LS), __uint32x2_p(RS));

    /* ...test if we have left-side */
    if (vget_lane_u64(vreinterpret_u64_u32(LS), 0) != 0ULL)
    {
        L = vadd_f32(P, L);

        /* ...left side exists; build normale */
        NL = calc_normale(P, L);

        /* ...generate half-circle of radius W from point L using the normale NL */
        CHK_API(odo_gen_circle(vbo, L, NL, W, height, color, &TL));

        /* ...test if we have right-side as well */
        if (vget_lane_u64(vreinterpret_u64_u32(RS), 0) != 0ULL)
        {
            R = vadd_f32(P, R);

            /* ...right side exists; build a normale */
            NR = calc_normale(R, P);

            /* ...generate half-circle of radius W from point R using the normale NR */
            CHK_API(odo_gen_circle(vbo, R, vneg_f32(NR), W, height, color, &TR));

            /* ...create a side-step directions from the central point */
            TC = calc_side_step(P, NL, NR, W);

            /* ...encode quads from TL-TC-TR */
            vst1_f32(points[0], TL.val[0]);
            vst1_f32(points[1], TC.val[0]);
            vst1_f32(points[2], TR.val[1]);
            CHK_API(odo_encode_curve(vbo, points, 3, height, color));

            vst1_f32(points[0], TR.val[0]);
            vst1_f32(points[1], TC.val[1]);
            vst1_f32(points[2], TL.val[1]);
            CHK_API(odo_encode_curve(vbo, points, 3, height, color));
        }
        else
        {
            /* ...there is no right-side; build a circle using normale NL with center in P */
            CHK_API(odo_gen_circle(vbo, P, vneg_f32(NL), W, height, color, &TC));

            /* ...connect points TC and TL */
            vst1_f32(points[0], TL.val[0]);
            vst1_f32(points[1], TC.val[1]);
            CHK_API(odo_encode_curve(vbo, points, 2, height, color));

            vst1_f32(points[0], TC.val[0]);
            vst1_f32(points[1], TL.val[1]);
            CHK_API(odo_encode_curve(vbo, points, 2, height, color));
        }
    }
    else
    {
        /* ...no left normale; test if there is a right side */
        if (vget_lane_u64(vreinterpret_u64_u32(RS), 0) != 0ULL)
        {
            R = vadd_f32(P, R);

            /* ...right-side exists; build a normale */
            NR = calc_normale(R, P);

            /* ...generate half-circle of radius W from point P */
            CHK_API(odo_gen_circle(vbo, P, NR, W, height, color, &TC));

            /* ...generate half-circle of radius W from point R using the normale NR */
            CHK_API(odo_gen_circle(vbo, R, vneg_f32(NR), W, height, color, &TR));

            /* ...connect points TC and TR */
            vst1_f32(points[0], TC.val[0]);
            vst1_f32(points[1], TR.val[1]);
            CHK_API(odo_encode_curve(vbo, points, 2, height, color));

            vst1_f32(points[0], TR.val[0]);
            vst1_f32(points[1], TC.val[1]);
            CHK_API(odo_encode_curve(vbo, points, 2, height, color));
        }
        else
        {
            /* ...no normales; build two half-circles */
            NR = __mk_float32x2(1.0f, 0.0f);
            CHK_API(odo_gen_circle(vbo, P, NR, W, height, color, &TR));
            CHK_API(odo_gen_circle(vbo, P, vneg_f32(NR), W, height, color, &TL));
        }
    }

    return 0;
}

/**
 * @brief   Generate ODO for a single object
 *
 */
static int odo_generate_box(vbo_dynarray_t *vbo, float32_t *point, cfg_data_t *cfg)
{
    /* ...load object coordinates (reported in metres) */
    float32x2_t     P = vmul_n_f32(vld1_f32(point), 1000.0f);

    /* ...load car rectangle area: Xmin, Ymin, Xmax, Ymax */
    float32x2x2_t   S;
    S.val[0] = __mk_float32x2(
        -cfg->vehicle.rear_overhang - cfg->vehicle.rear_blind_area,
        cfg->vehicle.width * -0.5f - cfg->vehicle.right_blind_area);
    S.val[1] = __mk_float32x2(
        cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + cfg->vehicle.front_blind_area,
        cfg->vehicle.width * 0.5f + cfg->vehicle.left_blind_area);

    /* ...get distance to the vehicle */
    float32x2_t     D = vmax_f32(vsub_f32(P, S.val[1]), vsub_f32(S.val[0], P));
    float32x2_t     M = vmax_f32(D, vext_f32(D, D, 1));
    float32_t       d = vget_lane_f32(M, 0);

    TRACE(1, _b("P=%f,%f, D=%f,%f, M=%f,%f"), __float32x2_p(P), __float32x2_p(D), __float32x2_p(M));

    /* ...check if the object is within the visible range */
    if (d >= 1000.0f * cfg->stv_pas.stv_obstacle_close_distance && d <= 1000.0f * cfg->stv_pas.stv_obstacle_max_distance)
    {
        float32_t   width = cfg->stv_pas.stv_obstacle_dim[0];
        float32_t   height = cfg->stv_pas.stv_obstacle_dim[1];
        float32_t   rect[4];

        if (vget_lane_f32(D, 0) >= d)
        {
            /* ...render lateral box */
            rect[0] = vget_lane_f32(P, 0);
            rect[1] = vget_lane_f32(P, 1) - width * 0.5f;
            rect[2] = rect[0] + (rect[0] < 0.0f ? -d : d);
            rect[3] = rect[1] + width;
        }
        else
        {
            /* ...render box along car side */
            rect[0] = vget_lane_f32(P, 0) - width * 0.5f;
            rect[1] = vget_lane_f32(P, 1);
            rect[2] = rect[0] + width;
            rect[3] = rect[1] + (rect[1] < 0.0f ? -d : d);
        }

        float32x4_t     C0 = __mk_float32x4(
            (float32_t)cfg->stv_pas.stv_obstacle_color[0] / 255.0f,
            (float32_t)cfg->stv_pas.stv_obstacle_color[1] / 255.0f,
            (float32_t)cfg->stv_pas.stv_obstacle_color[2] / 255.0f,
            1.0f - (float32_t)cfg->stv_pas.stv_obstacle_transparency * 0.01f);
        float32x4_t     C1 = C0;

        float32x2_t     XY0 = vld1_f32(&rect[0]);
        float32x2_t     XY1 = vld1_f32(&rect[2]);
        float32x2_t     XY2 = vtrn1_f32(XY0, vext_f32(XY1, XY1, 1));
        float32x2_t     XY3 = vtrn1_f32(XY1, vext_f32(XY0, XY0, 1));
        odo_vertex_t   *v;

        TRACE(1, _b("draw rect %f,%f - %f,%f"), __float32x2_p(XY0), __float32x2_p(XY1));

        /* ...reserve vertices for 4 quads (box walls only) */
        CHK_ERR(v = vbo_dynarray_add(&vbo[0], sizeof(*v), 4 * 6), -1);

        v = odo_quad_encode(v, XY0, XY2, 0.0f, height, C0, C1);
        v = odo_quad_encode(v, XY2, XY1, 0.0f, height, C0, C1);
        v = odo_quad_encode(v, XY1, XY3, 0.0f, height, C0, C1);
        v = odo_quad_encode(v, XY3, XY0, 0.0f, height, C0, C1);

        C0 = __mk_float32x4(
            (float32_t)cfg->stv_pas.stv_obstacle_line_color[0] / 255.0f,
            (float32_t)cfg->stv_pas.stv_obstacle_line_color[1] / 255.0f,
            (float32_t)cfg->stv_pas.stv_obstacle_line_color[2] / 255.0f,
            1.0f - (float32_t)cfg->stv_pas.stv_obstacle_line_transparency * 0.01f);
        C1 = C0;

        /* ...reserve vertices for box frame */
        CHK_ERR(v = vbo_dynarray_add(&vbo[1], sizeof(*v), 2 * 12), -1);
        v = odo_line_encode(v, XY0, 0.0f, XY2, 0.0f, C0, C0);
        v = odo_line_encode(v, XY2, 0.0f, XY1, 0.0f, C0, C0);
        v = odo_line_encode(v, XY1, 0.0f, XY3, 0.0f, C0, C0);
        v = odo_line_encode(v, XY3, 0.0f, XY0, 0.0f, C0, C0);

        v = odo_line_encode(v, XY0, height, XY2, height, C1, C1);
        v = odo_line_encode(v, XY2, height, XY1, height, C1, C1);
        v = odo_line_encode(v, XY1, height, XY3, height, C1, C1);
        v = odo_line_encode(v, XY3, height, XY0, height, C1, C1);

        v = odo_line_encode(v, XY0, 0.0f, XY0, height, C0, C1);
        v = odo_line_encode(v, XY2, 0.0f, XY2, height, C0, C1);
        v = odo_line_encode(v, XY1, 0.0f, XY1, height, C0, C1);
        v = odo_line_encode(v, XY3, 0.0f, XY3, height, C0, C1);
    }

    return 0;
}

/**
 * @brief   Set color value
 *
 * @param   color[in]           RGB values
 * @param   transparency[in]    Transparency in percents
 *
 * @param                       RGBA color
 */
static inline float32x4_t odo_color(uint8_t *color, uint8_t transparency)
{
    return __mk_float32x4(
        (float32_t)color[0] / 255.0f,
        (float32_t)color[1] / 255.0f,
        (float32_t)color[2] / 255.0f,
        1.0f - (float32_t)transparency * 0.01f);
}

/**
 * @brief   Generate ODO for a single object
 *
 */
static int odo_generate_object(vbo_dynarray_t *vbo, cfg_data_t *cfg, float32_t *origin, float32_t angle, float32_t distance)
{
    const float32_t cube[4][2] = {
        { -0.5f, -0.5f },
        { -0.5f, +0.5f },
        { +0.5f, -0.5f },
        { +0.5f, +0.5f },
    };

    float32_t       coord[4][2];

    /* ...calculate scale vector basing on distance to the object */
    float32_t   alpha = -angle * (float32_t)(M_PI / 180.0);
    float32_t   c = cosf(alpha);
    float32_t   s = sinf(alpha);

    /* ...create object position matrix */
    __vec2      scale = {
        cfg->stv_pas.stv_obstacle_dim[0] + distance * cfg->stv_pas.stv_obstacle_dim_scale[0],
        cfg->stv_pas.stv_obstacle_dim[1] + distance * cfg->stv_pas.stv_obstacle_dim_scale[1],
    };

    float32_t   height = cfg->stv_pas.stv_obstacle_dim[2] + distance * cfg->stv_pas.stv_obstacle_dim_scale[2];

    __mat3x3    S;
    __matNxN_M_diagv(3, 2, S, scale);

    __mat3x3    R;
    __matNxN_rotate(3, R, 1, 0, angle);

    __mat3x3    M;
    __mat3x3_mul(R, S, M);
    __M(3, M, 0, 2) += origin[0] + c * distance;
    __M(3, M, 1, 2) += origin[1] - s * distance;

    /* ...multiply cube points by matrix */
    int     i;
    for (i = 0; i < sizeof(cube) / sizeof(cube[0]); i++)
    {
        __vec3  p;

        __mat3x3_mulvh(M, cube[i], p);

        TRACE(0, _b("[%d]: P=%f,%f"), i, p[0], p[1]);

        memcpy(coord[i], p, sizeof(float32_t[2]));
    }


    /* ...determine line color basing on distance */
    float32_t       close_dist = cfg->stv_pas.stv_obstacle_close_distance;
    float32_t       middle_dist = cfg->stv_pas.stv_obstacle_middle_distance;
    float32_t       far_dist = cfg->stv_pas.stv_obstacle_far_distance;
    float32_t       max_dist = cfg->stv_pas.stv_obstacle_max_distance;
    float32x4_t     C0;
    float32x4_t     C1;
    float32_t       mix;

    if (distance <= close_dist)
    {
        C0 = odo_color(cfg->stv_pas.stv_pas_close_color, cfg->stv_pas.stv_obstacle_transparency);
        C1 = C0;
        mix = 0.0f;
        TRACE(DEBUG, _b("close dist: %f, mix: %f"), distance, mix);
    }
    else if (distance <= middle_dist)
    {
        C0 = odo_color(cfg->stv_pas.stv_pas_close_color, cfg->stv_pas.stv_obstacle_transparency);
        C1 = odo_color(cfg->stv_pas.stv_pas_middle_color, cfg->stv_pas.stv_obstacle_transparency);
        mix = powf((distance - close_dist) / (middle_dist - close_dist), 2.0f);
        TRACE(DEBUG, _b("close-middle dist: %f, mix: %f"), distance, mix);
    }
    else if (distance <= far_dist)
    {
        C0 = odo_color(cfg->stv_pas.stv_pas_middle_color, cfg->stv_pas.stv_obstacle_transparency);
        C1 = odo_color(cfg->stv_pas.stv_pas_far_color, cfg->stv_pas.stv_obstacle_transparency);
        mix = powf((distance - middle_dist) / (far_dist - middle_dist), 2.0f);
        TRACE(DEBUG, _b("middle-far dist: %f, mix: %f"), distance, mix);
    }
    else if (distance <= max_dist)
    {
        C0 = odo_color(cfg->stv_pas.stv_pas_far_color, cfg->stv_pas.stv_obstacle_transparency);
        C1 = odo_color(cfg->stv_pas.stv_pas_max_color, cfg->stv_pas.stv_obstacle_transparency);
        mix = powf((distance - far_dist) / (max_dist - far_dist), 2.0f);
        TRACE(DEBUG, _b("far-max: %f, mix: %f"), distance, mix);
    }
    else
    {
        C0 = odo_color(cfg->stv_pas.stv_pas_max_color, cfg->stv_pas.stv_obstacle_transparency);
        C1 = C0;
        mix = 0.0f;
        TRACE(DEBUG, _b("max: %f, mix: %f"), distance, mix);
    }

    C0 = vmlaq_n_f32(C0, vsubq_f32(C1, C0), mix);
    C1 = C0;

    float32x2_t     XY0 = vld1_f32(&coord[0][0]);
    float32x2_t     XY1 = vld1_f32(&coord[3][0]);
    float32x2_t     XY2 = vld1_f32(&coord[1][0]);
    float32x2_t     XY3 = vld1_f32(&coord[2][0]);

    odo_vertex_t   *v;

    /* ...reserve vertices for 4 quads (box walls only) */
    CHK_ERR(v = vbo_dynarray_add(&vbo[0], sizeof(*v), 4 * 6), -1);

    v = odo_quad_encode(v, XY0, XY2, 0.0f, height, C0, C1);
    v = odo_quad_encode(v, XY2, XY1, 0.0f, height, C0, C1);
    v = odo_quad_encode(v, XY1, XY3, 0.0f, height, C0, C1);
    v = odo_quad_encode(v, XY3, XY0, 0.0f, height, C0, C1);

    /* ...adjust line color */
    float32_t   line_alpha = 1.0f - (float32_t)cfg->stv_pas.stv_obstacle_line_transparency * 0.01f;
    C0 = vsetq_lane_f32(line_alpha, C0, 3);
    C1 = C0;

    /* ...reserve vertices for box frame */
    CHK_ERR(v = vbo_dynarray_add(&vbo[1], sizeof(*v), 2 * 12), -1);
    v = odo_line_encode(v, XY0, 0.0f, XY2, 0.0f, C0, C0);
    v = odo_line_encode(v, XY2, 0.0f, XY1, 0.0f, C0, C0);
    v = odo_line_encode(v, XY1, 0.0f, XY3, 0.0f, C0, C0);
    v = odo_line_encode(v, XY3, 0.0f, XY0, 0.0f, C0, C0);

    v = odo_line_encode(v, XY0, height, XY2, height, C1, C1);
    v = odo_line_encode(v, XY2, height, XY1, height, C1, C1);
    v = odo_line_encode(v, XY1, height, XY3, height, C1, C1);
    v = odo_line_encode(v, XY3, height, XY0, height, C1, C1);

    v = odo_line_encode(v, XY0, 0.0f, XY0, height, C0, C1);
    v = odo_line_encode(v, XY2, 0.0f, XY2, height, C0, C1);
    v = odo_line_encode(v, XY1, 0.0f, XY1, height, C0, C1);
    v = odo_line_encode(v, XY3, 0.0f, XY3, height, C0, C1);

    return 0;
}

/*******************************************************************************
 * Internal functions
 ******************************************************************************/

/**
 * @brief   Calculate distance from object to vehicle nearest point, in m
 *
 * @param   P[in]           Nearest object point, in m
 * @param   S[in]           Vehicle shadow region, in m
 *
 * @return                  Distance between object and closest vehicle point
 */

static inline float32_t calc_obj_distance(float32x2_t P, float32x2x2_t S)
{
    float32x2_t Q;

    /* ...min(X,Xmax), min(Y,Ymax) */
    Q = vmin_f32(P, S.val[1]);

    /* ...max(min(X,Xmax),Xmin), max(min(Y,Ymax),Ymin) */
    Q = vmax_f32(Q, S.val[0]);

    /* ....get distance to nearest vehicle point */
    return vget_lane_f32(calc_length(vsub_f32(P, Q)), 0);
}

/**
 * @brief   Select object color basing on its distance
 *
 * @param   cfg[in]         Guidelines configuration data pointer
 * @param   point[in]       Object nearest point position
 * @param   color[out]      Color value
 *
 * @return                  Non-zero if object is to be displayed
 */
static inline int odo_set_color(cfg_data_t *cfg, float32_t *point, float32_t *color)
{
    uint8_t        *rgb;

    /* ...load point position */
    float32x2_t     P = vld1_f32(point);

    /* ...car rectangle area: Xmin, Ymin, Xmax, Ymax */
    float32x2x2_t   S;
    S.val[0] = __mk_float32x2(-cfg->vehicle.rear_overhang * 0.001f, cfg->vehicle.width * -0.0005f);
    S.val[1] = __mk_float32x2((cfg->vehicle.wheel_base + cfg->vehicle.front_overhang) * 0.001f, cfg->vehicle.width * 0.0005f);

    /* ...get distance to closest vehicle point */
    float32_t       D = calc_obj_distance(P, S);

    if (D <= cfg->stv_pas.stv_obstacle_close_distance)
    {
        rgb = cfg->stv_pas.stv_pas_close_color;
    }
    else if (D <= cfg->stv_pas.stv_obstacle_middle_distance)
    {
        rgb = cfg->stv_pas.stv_pas_middle_color;
    }
    else if (D <= cfg->stv_pas.stv_obstacle_far_distance)
    {
        rgb = cfg->stv_pas.stv_pas_far_color;
    }
    else if (D <= cfg->stv_pas.stv_obstacle_max_distance)
    {
        rgb = cfg->stv_pas.stv_pas_max_color;
    }
    else
    {
        rgb = NULL;
    }

    if (rgb != NULL)
    {
        TRACE(DEBUG, _b("D=%f, rgb=%u/%u/%u"), D, rgb[0], rgb[1], rgb[2]);

        color[0] = (float32_t)rgb[0] / 255.0f;
        color[1] = (float32_t)rgb[1] / 255.0f;
        color[2] = (float32_t)rgb[2] / 255.0f;
        color[3] = 1.0f - (float32_t)cfg->stv_pas.stv_obstacle_transparency * 0.01f;
    }

    return (rgb != NULL);
}

/**
 * @brief   Calculate sonar obstacle distance for current area-info
 *
 * @param   pas[in]             STV-PAS configuration
 * @param   distance[in, out]   Target/current distance values
 * @param   area_info[in]       Sonar area information
 *
 * @return                      Object visibility status
 */
static int stv_pas_calc_distance(cfg_stv_pas_t *pas, int area_info, float32_t *distance)
{
    float32_t   d;

    /* ...get area information */
    if (area_info == PAS_AREA_INFO_CLOSE_DISTANCE)
    {
        d = pas->stv_obstacle_close_distance;
    }
    else if (area_info == PAS_AREA_INFO_MIDDLE_DISTANCE)
    {
        d = pas->stv_obstacle_middle_distance;
    }
    else if (area_info == PAS_AREA_INFO_FAR_DISTANCE)
    {
        d = pas->stv_obstacle_far_distance;
    }
    else if (area_info == PAS_AREA_INFO_MAX_DISTANCE)
    {
        d = pas->stv_obstacle_max_distance;
    }
    else if (area_info != PAS_AREA_INFO_NO_DETECTION)
    {
        /* ...keep current target value */
        if ((d = distance[0]) == 0.0f)
        {
            /* ...don't show sonar if it has bad distance - tbd, think about that */
            return 0;
        }
    }
    else
    {
        /* ...turn off the sonar */
        return 0;
    }

    /* ...set target distance */
    distance[0] = d;

    /* ...average current distance (exponential averaging) */
    d = distance[1] + pas->stv_obstacle_switch_factor * (d - distance[1]);

    /* ...clamp value to target as it gets close enough */
    distance[1] = (fabsf(d - distance[0]) < 10.0f ? distance[0] : d);

    return 1;
}

static int stv_pas_calc_transparency(uint32_t delta, uint32_t duration, int on, float32_t *tr)
{
    float32_t   t0 = (float32_t)delta / (float32_t)(duration * 1000);
    int         done = 0;

    if (t0 < 0.5f)
    {
        *tr = 1.0f - 2.0f * powf(t0, 2.0f);
    }
    else if (t0 < 1.0f)
    {
        *tr = 2.0f * powf(1.0f - t0, 2.0f);
    }
    else
    {
        *tr = 0.0f;
        done = 1;
    }

    /* ...invert transparency if fade-in ramp */
    (on ? *tr = 1.0f - *tr : 0);

    return done;
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**> ODO animation sequence state */
enum odo_animation_state
{
    ODO_STATE_INACTIVE = 0,
    ODO_STATE_ENABLE = 1,
    ODO_STATE_ACTIVE = 2,
    ODO_STATE_DISABLE = 3,
};

/**
 * @brief   Generate object-detection overlay
 *
 * @param   cfg[in]     Global configuration data pointer
 * @param   vehicle[in] Vehicle state
 * @param   odo
 * @return              Negative on failure
 */
int stv_odo_generate(cfg_data_t *cfg, vehicle_state_t *vehicle, pas_stv_data_t *odo)
{
    uint32_t        duration = cfg->stv_pas.stv_obstacle_fadeout_duration;
    pas_state_t    *pas = &vehicle->pas;
    uint32_t        ts = __get_time_usec();
    int             update = 0;
    int32_t         i;

    /* ...process all sonars */
    for (i = 0; i < PAS_AREA_NUMBER; i++)
    {
        uint32_t    delta = ts - odo->timer[i];
        int         visible;

        /* ...process individual objects */
        if (pas->state == PAS_STATE_ON && pas->sonar_state[i] == 0)
        {
            /* ...sonar is operational; get visibility basing on area-info */
            visible = stv_pas_calc_distance(&cfg->stv_pas, pas->area_info[i], odo->distance[i]);
        }
        else
        {
            /* ...sonar failure; object is invisible */
            visible = 0;
        }

        /* ...clear VBO array if object shall be shown */
        if (visible != 0)
        {
            vbo_dynarray_clear(&odo->vbo[i][0], sizeof(odo_vertex_t));
            vbo_dynarray_clear(&odo->vbo[i][1], sizeof(odo_vertex_t));

            /* ...calculate object visibility */
            if (odo->state[i] == ODO_STATE_INACTIVE)
            {
                odo->timer[i] = ts;
                odo->transparency[i] = 0.0f;
                odo->state[i] = ODO_STATE_ENABLE;
            }
            else if (odo->state[i] == ODO_STATE_ENABLE)
            {
                if (stv_pas_calc_transparency(delta, duration, 1, &odo->transparency[i]))
                {
                    odo->state[i] = ODO_STATE_ACTIVE;
                }
            }
            else
            {
                /* ...revert state back to active */
                odo->transparency[i] = 1.0f;
                odo->state[i] = ODO_STATE_ACTIVE;
            }

            TRACE(0, _b("obj-%d: state=%d"), i, odo->state[i]);

            /* ...render object box */
            odo_generate_object(odo->vbo[i], cfg, cfg->stv_pas.sonar_origin[i], cfg->stv_pas.sonar_direction[i], odo->distance[i][1]);

            /* ...put update flag if animation is running */
            if (odo->state[i] == ODO_STATE_ENABLE || odo->distance[i][0] != odo->distance[i][1])
            {
                TRACE(DEBUG, _b("sonar-%d: force update: %f != %f"), i, odo->distance[i][0], odo->distance[i][1]);
                update = 1;
            }
        }
        else
        {
            /* ...process fade-out ramp */
            if (odo->state[i] == ODO_STATE_ACTIVE)
            {
                /* ...start hiding animation */
                odo->timer[i] = ts;
                odo->transparency[i] = 1.0f;
                odo->state[i] = ODO_STATE_DISABLE;
            }
            else if (odo->state[i] == ODO_STATE_DISABLE)
            {
                if (stv_pas_calc_transparency(delta, duration, 0, &odo->transparency[i]))
                {
                    odo->state[i] = ODO_STATE_INACTIVE;
                }
            }
            else
            {
                /* ...revert state back to inactive */
                odo->transparency[i] = 0.0f;
                odo->state[i] = ODO_STATE_INACTIVE;
            }

            /* ...put update flag if animation is running */
            if (odo->state[i] != ODO_STATE_INACTIVE)
            {
                update = 1;
            }
        }
    }

    return update;
}

/**
 * @brief   Calculate PVM matrices for specified viewing position
 *
 * @param   car[in]         Car model data
 * @param   position[in]    Virtual camera position
 * @param   rotation[in]    Rotation angles
 * @param   fov[in]         Horizontal/vertical field-of-view, in degrees
 * @param   pvm[out]        PVM matrix
 */
void odo_set_viewpoint(float32_t *position, float32_t *rotation, float32_t *fov, float32_t *pvm)
{
    float32_t   z0 = 100.0f, z1 = 20000.0f;
    float32_t   hfov2 = fov[0] * (float32_t)(0.5 * M_PI / 180.0);
    float32_t   vfov2 = fov[1] * (float32_t)(0.5 * M_PI / 180.0);

    /* ...set perspective projection matrix */
    __mat4x4    P, VM;
    __matNxN_zero(4, P);
    __M(4, P, 0, 0) = 1.0f / tanf(hfov2);
    __M(4, P, 1, 1) = 1.0f / tanf(vfov2);
    __M(4, P, 2, 2) = z1 / (z0 - z1);
    __M(4, P, 2, 3) = (z0 * z1) / (z0 - z1) * 1.0e-0f;
    __M(4, P, 3, 2) = -1.0f;

    __mat4x4    T, R, m;
    __mat4x4_translation(T, -position[0], -position[1], -position[2]);
    __mat4x4_rotation(R, (__vec3){rotation[0], -rotation[1], rotation[2]}, __MATH_ONE);
    __mat4x4_mul(R, T, m);

    /* ...convert coordinates from world to display (GL) coordinate system */
    const __mat4x4  S = {
        0.0f, 0.0f, -1.0f, 0.0f,
        -1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, +1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };

    __mat4x4_mul(S, m, VM);

    /* ...produce PVM matrix */
    __mat4x4_mul(P, VM, pvm);
}

/**
 * @brief   Object-detection overlay rendering
 *
 * @param   odo[in]         Object-detection overlay data
 * @param   ctx[in]         Rendering context
 * @param   cfg[in]         Global configuration data
 * @param   pvm[in]         PVM matrix for scene rendering
 * @param   intensity[in]   Global scene intensity
 */
void stv_odo_render(pas_stv_data_t *odo, render_context_t *ctx, cfg_data_t *cfg, float32_t *pvm, float32_t intensity)
{
    uint32_t        i;

    glDisable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glLineWidth(ctx->scale * cfg->stv_pas.stv_obstacle_line_width);

    for (i = 0; i < PAS_AREA_NUMBER; i++)
    {
        if (odo->state[i] != ODO_STATE_INACTIVE)
        {
            TRACE(0, _b("obj-%d: transparency = %f"), i, odo->transparency[i]);

            /* ...render stuff eventually - tbd - split into different functions */
            odo_vbo_render(odo->vbo[i], pvm, odo->transparency[i], intensity);
        }
    }
}
